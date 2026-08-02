#!/usr/bin/env python3
"""
arma_lint.py — A linter for Arma 3 mod config files (.cpp / .hpp / .cfg).

Targets BI's flavour of "C++" config syntax (CfgPatches, CfgVehicles, etc.),
not real C++. Designed to catch:
  * Catastrophic errors that will make PboProject refuse to pack
  * In-game config errors (missing brackets on arrays, dangling semicolons,
    duplicate classes, broken inheritance chains)
  * Best-practice warnings (missing CfgPatches fields, BOMs, dodgy paths)

Stdlib only. Python 3.8+.

Usage:
    python3 arma_lint.py [paths...]

Common flags:
    -W, --warnings-as-errors   Treat warnings as errors (exit 2 if any)
    --no-warnings              Suppress warnings entirely
    --json                     Emit JSON instead of human-readable output
    --include-dir DIR          Extra root for resolving #include paths
                               (repeatable; can use $PBOPREFIX$-style roots)
    --max-path-len N           Max in-PBO path length to allow (default 100)
    --internal-prefix PFX      Top-level folder prefix owned by this project
                               (repeatable, default ADF_). Absolute #includes
                               rooted elsewhere (\\x\\cba, \\z\\ace, \\MCC, ...)
                               warn as W018 instead of erroring as E013.
    --quiet                    Only show errors+warnings, no per-file headers
    --rules                    List all rules and exit
    --disable RULE             Disable a rule by ID (repeatable)

Exit codes:
    0  no errors, no warnings (or warnings suppressed)
    1  warnings only
    2  errors (or warnings if -W)
"""

from __future__ import annotations

import argparse
import json
import os
import re
import sys
from dataclasses import dataclass, field, asdict
from pathlib import Path
from typing import Iterable, Iterator


# ----------------------------------------------------------------------------
# Diagnostic types
# ----------------------------------------------------------------------------

LEVEL_ERROR = "error"
LEVEL_WARNING = "warning"
LEVEL_INFO = "info"


@dataclass
class Diagnostic:
    file: str
    line: int
    col: int
    level: str
    rule: str
    message: str

    def format_human(self, root: Path | None = None) -> str:
        path = self.file
        if root:
            try:
                path = str(Path(self.file).resolve().relative_to(root.resolve()))
            except ValueError:
                pass
        colour = {
            LEVEL_ERROR: "\033[31m",
            LEVEL_WARNING: "\033[33m",
            LEVEL_INFO: "\033[36m",
        }.get(self.level, "")
        reset = "\033[0m" if colour else ""
        return f"{path}:{self.line}:{self.col}: {colour}{self.level}{reset}[{self.rule}]: {self.message}"


# ----------------------------------------------------------------------------
# Rule registry. Keep IDs stable for users disabling them.
# ----------------------------------------------------------------------------

RULES: dict[str, tuple[str, str]] = {
    # id: (default_level, description)
    "E001": (LEVEL_ERROR,   "Unbalanced braces { }"),
    "E002": (LEVEL_ERROR,   "Unbalanced square brackets [ ]"),
    "E003": (LEVEL_ERROR,   "Unbalanced parentheses ( )"),
    "E004": (LEVEL_ERROR,   "Unterminated string literal"),
    "E005": (LEVEL_ERROR,   "Unterminated block comment"),
    "E006": (LEVEL_ERROR,   "Unbalanced preprocessor #if/#endif"),
    "E007": (LEVEL_ERROR,   "Array assignment missing []  e.g. magazines = {...} should be magazines[] = {...}"),
    "E008": (LEVEL_ERROR,   "Class definition missing trailing semicolon"),
    "E009": (LEVEL_ERROR,   "Forward declaration cannot have a parent  e.g. class A : B; is invalid"),
    "E010": (LEVEL_ERROR,   "Statement missing trailing semicolon"),
    "E011": (LEVEL_ERROR,   "Reserved keyword used as class name"),
    "E012": (LEVEL_ERROR,   "Duplicate class definition in same scope"),
    "E013": (LEVEL_ERROR,   "#include target file not found"),
    "E014": (LEVEL_ERROR,   "Empty assignment (no value before semicolon)"),
    "E015": (LEVEL_ERROR,   "Class name missing or invalid"),
    "E016": (LEVEL_WARNING, "Inheritance from class never declared (in this file)"),
    "E017": (LEVEL_INFO,    "Stray token outside any class body"),
    "E018": (LEVEL_ERROR,   "Unquoted localization string ($STR_... must be in quotes)"),
    "E019": (LEVEL_ERROR,   "Unquoted multi-word value (likely missing quotes around a string)"),

    "W001": (LEVEL_WARNING, "UTF-8 BOM at start of file (PboProject can be picky)"),
    "W002": (LEVEL_WARNING, "Mixed line endings (CRLF and LF in same file)"),
    "W003": (LEVEL_WARNING, "Filename or path contains spaces"),
    "W004": (LEVEL_WARNING, "Filename or path contains non-ASCII characters"),
    "W005": (LEVEL_WARNING, "PBO-relative path exceeds recommended length"),
    "W006": (LEVEL_WARNING, "CfgPatches subclass missing requiredAddons[]"),
    "W007": (LEVEL_WARNING, "CfgPatches subclass missing units[]"),
    "W008": (LEVEL_WARNING, "CfgPatches subclass missing weapons[]"),
    "W009": (LEVEL_WARNING, "Mixed tabs and spaces for indentation"),
    "W010": (LEVEL_WARNING, "Trailing whitespace at end of line"),
    "W011": (LEVEL_WARNING, "Class body is empty (intentional? consider forward declaration)"),
    "W012": (LEVEL_WARNING, "Likely typo: '==' used in config (configs use '=')"),
    "W013": (LEVEL_WARNING, "Path uses double-backslash in string literal"),
    "W014": (LEVEL_WARNING, "config.cpp at addon root has no CfgPatches block"),
    "W015": (LEVEL_WARNING, "#include path uses forward slashes (Arma convention is backslash)"),
    "W016": (LEVEL_WARNING, "Numeric literal looks malformed"),
    "W017": (LEVEL_WARNING, "#include path case differs from real filename (breaks on Linux/Mac/CI)"),
    "W018": (LEVEL_WARNING, "#include target not found, but points outside the project (external/soft dependency)"),
}

# Top-level folder prefixes that count as "ours". An absolute #include whose
# first path segment doesn't start with one of these can't be resolved from
# this repo alone (CBA, ACE, ACEX, MCC, etc.), so a miss is W018 not E013.
DEFAULT_INTERNAL_PREFIXES = ("ADF_",)

# Cosmetic-only rules: muted by default, opt in via --cosmetic
COSMETIC_RULES = {"W009", "W010"}


def all_rule_ids() -> list[str]:
    return list(RULES.keys())


# ----------------------------------------------------------------------------
# Lexer
# ----------------------------------------------------------------------------

# Arma config keywords / pseudo-keywords we should never see used as classnames
RESERVED_CLASSNAMES = {
    "class", "delete", "enum",
    # Booleans defined as macros in basicDefines — not strictly reserved but
    # nobody in their right mind would name a class these:
    "true", "false",
}


@dataclass
class Token:
    kind: str   # 'IDENT', 'STRING', 'NUMBER', '{', '}', '[', ']', '(', ')', ';', ',', '=', ':', 'KW_CLASS', 'KW_DELETE', 'KW_ENUM', 'PP', 'EOF'
    value: str
    line: int
    col: int


class LexError(Exception):
    def __init__(self, message: str, line: int, col: int, rule: str = "E004"):
        super().__init__(message)
        self.message = message
        self.line = line
        self.col = col
        self.rule = rule


class Lexer:
    """
    Tokenises Arma config source. Strips comments and preprocessor lines
    (returning preprocessor lines as 'PP' tokens so they can be inspected
    for #include without complicating downstream parsing).
    """

    KEYWORDS = {
        "class": "KW_CLASS",
        "delete": "KW_DELETE",
        "enum": "KW_ENUM",
    }

    def __init__(self, src: str):
        self.src = src
        self.pos = 0
        self.line = 1
        self.col = 1
        self.tokens: list[Token] = []
        self.diagnostics: list[Diagnostic] = []
        self.length = len(src)

    def _peek(self, offset: int = 0) -> str:
        p = self.pos + offset
        return self.src[p] if 0 <= p < self.length else ""

    def _advance(self) -> str:
        if self.pos >= self.length:
            return ""
        c = self.src[self.pos]
        self.pos += 1
        if c == "\n":
            self.line += 1
            self.col = 1
        else:
            self.col += 1
        return c

    def _emit(self, kind: str, value: str, line: int, col: int) -> None:
        self.tokens.append(Token(kind, value, line, col))

    def tokenize(self) -> list[Token]:
        while self.pos < self.length:
            c = self._peek()

            # Whitespace
            if c in " \t\r\n":
                self._advance()
                continue

            # Line comment
            if c == "/" and self._peek(1) == "/":
                while self.pos < self.length and self._peek() != "\n":
                    self._advance()
                continue

            # Block comment
            if c == "/" and self._peek(1) == "*":
                start_line, start_col = self.line, self.col
                self._advance()
                self._advance()
                closed = False
                while self.pos < self.length:
                    if self._peek() == "*" and self._peek(1) == "/":
                        self._advance()
                        self._advance()
                        closed = True
                        break
                    self._advance()
                if not closed:
                    raise LexError("Unterminated block comment", start_line, start_col, "E005")
                continue

            # Preprocessor line: capture from '#' to end-of-line, respecting
            # backslash line continuations.
            if c == "#" and self._is_at_line_start():
                start_line, start_col = self.line, self.col
                buf: list[str] = []
                while self.pos < self.length:
                    ch = self._peek()
                    if ch == "\n":
                        # Check if previous non-space char on this line is a backslash → line continuation
                        if buf and buf[-1].rstrip(" \t") and buf[-1].rstrip(" \t")[-1] == "\\":
                            buf[-1] = buf[-1].rstrip(" \t")[:-1]
                            buf.append("\n")
                            self._advance()
                            continue
                        break
                    buf.append(ch)
                    self._advance()
                self._emit("PP", "".join(buf), start_line, start_col)
                continue

            # String literals: Arma config supports "..." with "" as escaped quote
            if c == '"':
                self._read_string()
                continue

            # Numbers: -?digits(.digits)?(e[+-]?digits)?
            if c.isdigit() or (c == "." and self._peek(1).isdigit()) or (c == "-" and (self._peek(1).isdigit() or self._peek(1) == ".")):
                # Need to be careful: a leading '-' could also be a unary
                # minus on its own. We only swallow it when followed by a digit.
                if c == "-" and not (self._peek(1).isdigit() or self._peek(1) == "."):
                    pass  # fall through to symbols
                else:
                    self._read_number()
                    continue

            # Identifiers
            if c == "_" or c.isalpha():
                self._read_ident()
                continue

            # Single-char symbols
            if c in "{}[]();,=:":
                line, col = self.line, self.col
                self._advance()
                self._emit(c, c, line, col)
                continue

            # Arithmetic operators valid inside scalar value expressions
            # (e.g. lockDetectionSystem = CM_Lock_Radar + CM_Lock_Laser;
            #       initFov = (30 / 120);
            #       magazines[] += {"x"};
            # Note: '-' as a unary on a number is handled in _read_number.
            if c in "+-*/%":
                line, col = self.line, self.col
                self._advance()
                self._emit(c, c, line, col)
                continue

            # '$' often appears in unquoted localization keys ($STR_...).
            # That's a real bug in user code, but emit a targeted error diag
            # rather than the generic "unexpected character", and then synthesize
            # a STRING token so the parser sees a valid value (avoids cascade).
            if c == "$":
                line, col = self.line, self.col
                start = self.pos
                self._advance()  # consume $
                while self.pos < self.length and (self._peek() == "_" or self._peek().isalnum()):
                    self._advance()
                literal = self.src[start:self.pos]
                self.diagnostics.append(
                    Diagnostic("", line, col, LEVEL_ERROR, "E018",
                               f"Unquoted localization string {literal!r}. Wrap it in quotes: \"{literal}\"")
                )
                # Synthesize as a STRING token so downstream parse stays sane
                self._emit("STRING", literal, line, col)
                continue

            # Anything else is unexpected. Skip but record as info-level diagnostic
            # so the parser can carry on.
            self.diagnostics.append(
                Diagnostic("", self.line, self.col, LEVEL_INFO, "E017",
                           f"Unexpected character {c!r}, skipped during lex")
            )
            self._advance()

        self._emit("EOF", "", self.line, self.col)
        return self.tokens

    def _is_at_line_start(self) -> bool:
        # Look backwards from current pos: every char up to a newline (or BOF) must be whitespace
        i = self.pos - 1
        while i >= 0:
            ch = self.src[i]
            if ch == "\n":
                return True
            if ch not in " \t":
                return False
            i -= 1
        return True

    def _read_string(self) -> None:
        line, col = self.line, self.col
        self._advance()  # consume opening "
        buf: list[str] = []
        while self.pos < self.length:
            ch = self._peek()
            if ch == '"':
                # Doubled "" inside string is an escaped quote
                if self._peek(1) == '"':
                    buf.append('"')
                    self._advance()
                    self._advance()
                    continue
                self._advance()
                self._emit("STRING", "".join(buf), line, col)
                return
            if ch == "\n":
                # Arma allows multiline strings? In practice no, this is bad.
                # Treat as unterminated to be safe — the engine will error too.
                raise LexError("Unterminated string literal (newline in string)", line, col, "E004")
            buf.append(ch)
            self._advance()
        raise LexError("Unterminated string literal at end of file", line, col, "E004")

    def _read_number(self) -> None:
        """
        Read a number OR a digit-prefixed identifier.

        Arma config identifiers can start with digits (e.g. '150Rnd_762x51_Box').
        Strategy: scan a numeric run, then if we land on an identifier character,
        keep reading and re-emit the whole thing as an IDENT.
        """
        line, col = self.line, self.col
        start = self.pos
        if self._peek() == "-":
            self._advance()
        # Numeric part: digits, decimals, exponents
        while self.pos < self.length:
            ch = self._peek()
            if ch.isdigit() or ch == ".":
                self._advance()
                continue
            if ch in "eE":
                self._advance()
                if self._peek() in "+-":
                    self._advance()
                continue
            break
        # If we now find an identifier char (letter or underscore), this is
        # actually a digit-prefixed identifier (e.g. 150Rnd_762x51_Box),
        # not a number.
        if self.pos < self.length and (self._peek() == "_" or self._peek().isalpha()):
            while self.pos < self.length and (self._peek() == "_" or self._peek().isalnum()):
                self._advance()
            value = self.src[start:self.pos]
            kind = self.KEYWORDS.get(value, "IDENT")
            self._emit(kind, value, line, col)
            return
        value = self.src[start:self.pos]
        self._emit("NUMBER", value, line, col)

    def _read_ident(self) -> None:
        line, col = self.line, self.col
        start = self.pos
        while self.pos < self.length and (self._peek() == "_" or self._peek().isalnum()):
            self._advance()
        value = self.src[start:self.pos]
        kind = self.KEYWORDS.get(value, "IDENT")
        self._emit(kind, value, line, col)


# ----------------------------------------------------------------------------
# Parser — recognises the subset of "config syntax" we actually care about.
# Goal is to flag structural problems, not to build a usable AST for codegen.
# ----------------------------------------------------------------------------

@dataclass
class ClassNode:
    name: str
    parent: str | None
    line: int
    col: int
    is_forward: bool = False
    children: list["ClassNode"] = field(default_factory=list)
    declared_in_scope: set[str] = field(default_factory=set)  # class names declared (forward) here


@dataclass
class FileParseResult:
    path: str
    classes: list[ClassNode]
    diagnostics: list[Diagnostic]
    pp_lines: list[Token]  # preprocessor tokens, kept for include checks


class Parser:
    def __init__(self, tokens: list[Token], path: str):
        self.tokens = tokens
        self.path = path
        self.pos = 0
        self.diagnostics: list[Diagnostic] = []
        self.top_level: list[ClassNode] = []
        # Stack of dicts: name -> ClassNode (for duplicate detection per scope)
        self.scope_stack: list[dict[str, ClassNode]] = [{}]
        # Stack of declared-but-empty (forward) names per scope, for inheritance check
        self.declared_stack: list[set[str]] = [set()]

    def _peek(self, offset: int = 0) -> Token:
        i = self.pos + offset
        if i >= len(self.tokens):
            return self.tokens[-1]  # EOF
        return self.tokens[i]

    def _eat(self) -> Token:
        t = self.tokens[self.pos]
        if t.kind != "EOF":
            self.pos += 1
        return t

    def _diag(self, level: str, rule: str, message: str, line: int | None = None, col: int | None = None) -> None:
        t = self._peek()
        self.diagnostics.append(Diagnostic(
            file=self.path,
            line=line if line is not None else t.line,
            col=col if col is not None else t.col,
            level=level,
            rule=rule,
            message=message,
        ))

    def parse(self) -> FileParseResult:
        while self._peek().kind != "EOF":
            self._parse_top_statement()
        return FileParseResult(
            path=self.path,
            classes=self.top_level,
            diagnostics=self.diagnostics,
            pp_lines=[t for t in self.tokens if t.kind == "PP"],
        )

    def _parse_top_statement(self) -> None:
        t = self._peek()

        # Skip preprocessor lines — they were already extracted; here they
        # appear interleaved with real tokens. Just consume them.
        if t.kind == "PP":
            self._eat()
            return

        if t.kind == "KW_CLASS":
            node = self._parse_class()
            if node is not None:
                self.top_level.append(node)
            return

        if t.kind == "KW_DELETE":
            self._parse_delete()
            return

        if t.kind == "KW_ENUM":
            self._parse_enum()
            return

        if t.kind == "IDENT":
            self._parse_assignment()
            return

        if t.kind == ";":
            # Stray semicolon is harmless; eat it
            self._eat()
            return

        # Anything else at top level is a stray token
        self._diag(LEVEL_ERROR, "E017", f"Unexpected token {t.value!r} at top level", t.line, t.col)
        self._eat()

    def _parse_class(self) -> ClassNode | None:
        kw = self._eat()  # KW_CLASS
        name_tok = self._peek()
        # Arma config allows class names to be pure digits ('class 417')
        # in addition to identifiers. We accept either.
        if name_tok.kind not in ("IDENT", "NUMBER"):
            self._diag(LEVEL_ERROR, "E015", f"Expected class name, got {name_tok.value!r}", kw.line, kw.col)
            self._recover_to_semi_or_close()
            return None

        if name_tok.kind == "IDENT" and name_tok.value in RESERVED_CLASSNAMES:
            self._diag(LEVEL_ERROR, "E011", f"'{name_tok.value}' is reserved and cannot be a class name", name_tok.line, name_tok.col)
        self._eat()
        name = name_tok.value

        parent: str | None = None
        if self._peek().kind == ":":
            self._eat()
            p = self._peek()
            if p.kind not in ("IDENT", "NUMBER"):
                self._diag(LEVEL_ERROR, "E015", f"Expected parent class name after ':', got {p.value!r}", p.line, p.col)
                self._recover_to_semi_or_close()
                return None
            parent = p.value
            self._eat()

        nxt = self._peek()
        if nxt.kind == ";":
            # Forward declaration. Parent is illegal here.
            if parent is not None:
                self._diag(LEVEL_ERROR, "E009",
                           f"'class {name} : {parent};' is invalid — forward declarations cannot have a parent",
                           name_tok.line, name_tok.col)
            self._eat()
            node = ClassNode(name=name, parent=parent, line=name_tok.line, col=name_tok.col, is_forward=True)
            self._register_class(node, forward=True)
            return node

        if nxt.kind != "{":
            self._diag(LEVEL_ERROR, "E008",
                       f"Expected '{{' or ';' after 'class {name}', got {nxt.value!r}",
                       name_tok.line, name_tok.col)
            self._recover_to_semi_or_close()
            return None

        # Full class body
        self._eat()  # {
        # Inheritance check (against this scope only)
        # Skip the check for `class X : X` — that's the standard Arma pattern
        # for extending a parent class's nested inner class (e.g. Turrets,
        # HitPoints, Components) and would always look like a missing decl here.
        if parent is not None and parent != name and not self._parent_visible(parent):
            self._diag(LEVEL_WARNING, "E016",
                       f"Class '{name}' inherits from '{parent}', which is not declared in this file. "
                       f"This is fine if '{parent}' is provided by another addon — otherwise add a forward declaration: 'class {parent};'",
                       name_tok.line, name_tok.col)

        node = ClassNode(name=name, parent=parent, line=name_tok.line, col=name_tok.col, is_forward=False)
        self._register_class(node, forward=False)

        self.scope_stack.append({})
        self.declared_stack.append(set())

        empty_body = True
        while self._peek().kind not in ("}", "EOF"):
            empty_body = False
            self._parse_class_member(node)

        if self._peek().kind == "EOF":
            self._diag(LEVEL_ERROR, "E001", f"Unbalanced braces — class '{name}' is never closed",
                       name_tok.line, name_tok.col)
            self.scope_stack.pop()
            self.declared_stack.pop()
            return node

        # Consume the '}'
        close = self._eat()
        # Must have a trailing ';'
        if self._peek().kind == ";":
            self._eat()
        else:
            self._diag(LEVEL_ERROR, "E008",
                       f"Missing ';' after closing '}}' of class '{name}'",
                       close.line, close.col)

        if empty_body and parent is None:
            # Empty body with a parent is a totally normal Arma pattern
            # (e.g. ACE compatibility classes that just register existence
            # to satisfy CfgPatches dependencies). Only warn when there's
            # no inheritance — that's far more likely to be a real mistake.
            self._diag(LEVEL_WARNING, "W011",
                       f"Class '{name}' has empty body — did you mean a forward declaration ('class {name};')?",
                       name_tok.line, name_tok.col)

        # Done with this scope
        self.scope_stack.pop()
        self.declared_stack.pop()
        return node

    def _register_class(self, node: ClassNode, forward: bool) -> None:
        scope = self.scope_stack[-1]
        if node.name in scope:
            existing = scope[node.name]
            # Re-declaring as forward after a full def is fine in some syntaxes
            # but not in Arma — flag both sides as duplicate when both are full.
            if not forward and not existing.is_forward:
                self._diag(LEVEL_ERROR, "E012",
                           f"Duplicate class definition '{node.name}' in same scope (first at line {existing.line})",
                           node.line, node.col)
        scope[node.name] = node
        if forward:
            self.declared_stack[-1].add(node.name)

    def _parent_visible(self, parent: str) -> bool:
        # Visible if forward-declared *or* fully defined in any enclosing scope.
        for scope in self.scope_stack:
            if parent in scope:
                return True
        for declared in self.declared_stack:
            if parent in declared:
                return True
        return False

    def _parse_class_member(self, parent_class: ClassNode) -> None:
        t = self._peek()

        if t.kind == "PP":
            self._eat()
            return

        if t.kind == "KW_CLASS":
            child = self._parse_class()
            if child is not None:
                parent_class.children.append(child)
            return

        if t.kind == "KW_DELETE":
            self._parse_delete()
            return

        if t.kind == "KW_ENUM":
            self._parse_enum()
            return

        if t.kind == "IDENT":
            self._parse_assignment()
            return

        if t.kind == ";":
            self._eat()
            return

        # Stray
        self._diag(LEVEL_ERROR, "E017",
                   f"Unexpected token {t.value!r} inside class body",
                   t.line, t.col)
        self._eat()

    def _parse_delete(self) -> None:
        kw = self._eat()  # KW_DELETE
        name_tok = self._peek()
        if name_tok.kind != "IDENT":
            self._diag(LEVEL_ERROR, "E015", f"Expected name after 'delete', got {name_tok.value!r}", kw.line, kw.col)
            self._recover_to_semi_or_close()
            return
        self._eat()
        if self._peek().kind == ";":
            self._eat()
        else:
            self._diag(LEVEL_ERROR, "E010", f"Missing ';' after 'delete {name_tok.value}'", name_tok.line, name_tok.col)

    def _parse_enum(self) -> None:
        # enum is rare in Arma configs — handle it loosely
        kw = self._eat()
        if self._peek().kind != "{":
            self._diag(LEVEL_ERROR, "E015", "Expected '{' after 'enum'", kw.line, kw.col)
            return
        self._eat()
        depth = 1
        while depth > 0 and self._peek().kind != "EOF":
            t = self._eat()
            if t.kind == "{":
                depth += 1
            elif t.kind == "}":
                depth -= 1
        if self._peek().kind == ";":
            self._eat()

    def _parse_assignment(self) -> None:
        name_tok = self._eat()  # IDENT
        next_tok = self._peek()

        # Macro invocation: IDENT ( args ) ;
        # Common Arma pattern from basicDefines_A3.hpp:
        #     mag_xx(SmokeShell, 2);
        #     bag_xx(B_Parachute, 2);
        # We don't validate the macro args — just consume balanced parens
        # and an optional trailing semicolon.
        if next_tok.kind == "(":
            self._eat()
            depth = 1
            while depth > 0 and self._peek().kind != "EOF":
                t = self._eat()
                if t.kind == "(":
                    depth += 1
                elif t.kind == ")":
                    depth -= 1
            # Optional trailing ';' — many macros expand to a class def that
            # already provides its own brace block, so the trailing ';' is
            # written by the user.
            if self._peek().kind == ";":
                self._eat()
            return

        # Array assignment: IDENT [ ] (= | += | -=) { ... } ;
        if next_tok.kind == "[":
            self._eat()
            if self._peek().kind != "]":
                # unusual: indexed assignment — not valid in Arma config
                self._diag(LEVEL_ERROR, "E002",
                           f"Expected ']' after '[' in array declaration of '{name_tok.value}'",
                           next_tok.line, next_tok.col)
                self._recover_to_semi_or_close()
                return
            self._eat()
            # Accept '=', '+=', '-=' for array assignments
            op_tok = self._peek()
            if op_tok.kind == "=":
                self._eat()
            elif op_tok.kind in ("+", "-") and self._peek(1).kind == "=":
                self._eat()  # consume + or -
                self._eat()  # consume =
            else:
                self._diag(LEVEL_ERROR, "E010",
                           f"Expected '=', '+=', or '-=' after '{name_tok.value}[]'",
                           name_tok.line, name_tok.col)
                self._recover_to_semi_or_close()
                return
            self._parse_array_or_value(array_required=True, ident_name=name_tok.value, ident_line=name_tok.line, ident_col=name_tok.col)
            return

        # Scalar assignment: IDENT = value ;
        if next_tok.kind == "=":
            # Quick W012 check: '==' would tokenise as = then = with nothing between.
            if self._peek(1).kind == "=":
                self._diag(LEVEL_WARNING, "W012",
                           f"'{name_tok.value} == ...' looks like an equality test — config syntax uses single '='",
                           next_tok.line, next_tok.col)
            self._eat()
            self._parse_array_or_value(array_required=False, ident_name=name_tok.value, ident_line=name_tok.line, ident_col=name_tok.col)
            return

        # IDENT alone followed by ; : tolerated (some configs do bare statements
        # via macros). Just consume.
        if next_tok.kind == ";":
            self._eat()
            return

        self._diag(LEVEL_ERROR, "E010",
                   f"Expected '=' or '[]=' after '{name_tok.value}', got {next_tok.value!r}",
                   name_tok.line, name_tok.col)
        self._recover_to_semi_or_close()

    def _parse_array_or_value(self, *, array_required: bool, ident_name: str, ident_line: int, ident_col: int) -> None:
        t = self._peek()
        if t.kind == "{":
            # It's an array. Walk it.
            if not array_required:
                self._diag(LEVEL_ERROR, "E007",
                           f"'{ident_name}' is assigned an array literal but is not declared as an array. "
                           f"Did you mean '{ident_name}[] = {{...}};' ?",
                           ident_line, ident_col)
            self._consume_array()
            self._expect_semi(ident_name, ident_line, ident_col)
            return

        if t.kind == ";":
            self._diag(LEVEL_ERROR, "E014",
                       f"Empty assignment for '{ident_name}'",
                       ident_line, ident_col)
            self._eat()
            return

        # Scalar expression: allow STRING | NUMBER | IDENT | (...) | [...]
        # joined by + - * / % operators, terminating at ';' at depth 0.
        # Configs allow simple arithmetic for combining flag macros, e.g.
        #     CM_Lock_Radar + CM_Lock_Laser
        #     (30 / 120)
        # And also bracketed sub-expressions for sound volume curves:
        #     volume = camPos * (rotorThrust factor [0.7, 0.9]);
        # We don't validate the expression — just consume balanced tokens.

        if t.kind not in ("STRING", "NUMBER", "IDENT", "(", "[", "+", "-"):
            self._diag(LEVEL_ERROR, "E010",
                       f"Unexpected token {t.value!r} in value for '{ident_name}'",
                       ident_line, ident_col)
            self._recover_to_semi_or_close()
            return

        # Track multi-word unquoted IDENTs to detect E019 ("missing quotes").
        # Pattern: IDENT IDENT ... ;  with no operators between -> probably
        # the user wrote `author = ADF Re-Cut;` instead of `author = "ADF Re-Cut";`.
        consumed_idents_in_a_row = 0
        depth_paren = 0
        depth_bracket = 0
        first_ident_tok: Token | None = None

        def _depth() -> int:
            return depth_paren + depth_bracket

        while True:
            cur = self._peek()
            if cur.kind == "EOF":
                self._diag(LEVEL_ERROR, "E010",
                           f"Reached end of file while parsing value for '{ident_name}'",
                           ident_line, ident_col)
                return
            if cur.kind == ";" and _depth() == 0:
                self._eat()
                return
            if cur.kind == "(":
                depth_paren += 1
                consumed_idents_in_a_row = 0
                self._eat()
                continue
            if cur.kind == ")":
                if depth_paren == 0:
                    self._diag(LEVEL_ERROR, "E003",
                               f"Unmatched ')' in value for '{ident_name}'",
                               cur.line, cur.col)
                    self._eat()
                    return
                depth_paren -= 1
                self._eat()
                continue
            if cur.kind == "[":
                depth_bracket += 1
                consumed_idents_in_a_row = 0
                self._eat()
                continue
            if cur.kind == "]":
                if depth_bracket == 0:
                    self._diag(LEVEL_ERROR, "E002",
                               f"Unmatched ']' in value for '{ident_name}'",
                               cur.line, cur.col)
                    self._eat()
                    return
                depth_bracket -= 1
                self._eat()
                continue
            if cur.kind in ("+", "-", "*", "/", "%", ","):
                consumed_idents_in_a_row = 0
                self._eat()
                continue
            if cur.kind in ("STRING", "NUMBER"):
                consumed_idents_in_a_row = 0
                self._eat()
                continue
            if cur.kind == "IDENT":
                consumed_idents_in_a_row += 1
                if consumed_idents_in_a_row == 1:
                    first_ident_tok = cur
                if consumed_idents_in_a_row == 2 and _depth() == 0:
                    # E019: two identifiers in a row at top level of a scalar value
                    # most likely means a missing quote, e.g. `author = ADF Re-Cut;`
                    ft = first_ident_tok if first_ident_tok else cur
                    self._diag(LEVEL_ERROR, "E019",
                               f"'{ident_name}' looks like it has an unquoted multi-word value "
                               f"(saw two identifiers in a row, '{ft.value}' then '{cur.value}'). "
                               f"Wrap the value in quotes.",
                               ft.line, ft.col)
                self._eat()
                continue
            if cur.kind == "{":
                # An array literal in the middle of a scalar expression is bogus
                self._diag(LEVEL_ERROR, "E010",
                           f"Unexpected '{{' inside scalar value for '{ident_name}'",
                           cur.line, cur.col)
                self._recover_to_semi_or_close()
                return
            if cur.kind == "}":
                # Reached enclosing class close without seeing ';'
                self._diag(LEVEL_ERROR, "E010",
                           f"Missing ';' after value for '{ident_name}'",
                           ident_line, ident_col)
                return
            # Unknown token — bail
            self._diag(LEVEL_ERROR, "E010",
                       f"Unexpected token {cur.value!r} in value for '{ident_name}'",
                       cur.line, cur.col)
            self._recover_to_semi_or_close()
            return

    def _consume_array(self) -> None:
        # We've already peeked '{'. Walk balanced.
        depth = 0
        while True:
            t = self._peek()
            if t.kind == "EOF":
                self._diag(LEVEL_ERROR, "E001", "Unbalanced braces inside array literal", t.line, t.col)
                return
            if t.kind == "{":
                depth += 1
            elif t.kind == "}":
                depth -= 1
                if depth == 0:
                    self._eat()
                    return
            self._eat()

    def _expect_semi(self, ident_name: str, line: int, col: int) -> None:
        if self._peek().kind == ";":
            self._eat()
            return
        self._diag(LEVEL_ERROR, "E010",
                   f"Missing ';' after assignment to '{ident_name}'",
                   line, col)

    def _recover_to_semi_or_close(self) -> None:
        depth = 0
        while True:
            t = self._peek()
            if t.kind == "EOF":
                return
            if t.kind == "{":
                depth += 1
                self._eat()
                continue
            if t.kind == "}":
                if depth == 0:
                    return
                depth -= 1
                self._eat()
                continue
            if t.kind == ";" and depth == 0:
                self._eat()
                return
            self._eat()


# ----------------------------------------------------------------------------
# File-level checks (run before lex/parse)
# ----------------------------------------------------------------------------

def file_level_checks(path: Path, raw: bytes, disabled: set[str]) -> list[Diagnostic]:
    diags: list[Diagnostic] = []
    sp = str(path)

    if "W001" not in disabled and raw.startswith(b"\xef\xbb\xbf"):
        diags.append(Diagnostic(sp, 1, 1, LEVEL_WARNING, "W001",
                                "File starts with UTF-8 BOM. PboProject and the Arma engine prefer no BOM."))

    if "W002" not in disabled:
        has_crlf = b"\r\n" in raw
        has_lone_lf = re.search(rb"(?<!\r)\n", raw) is not None
        # Both CRLF and lone LF in the same file is "mixed"
        if has_crlf and has_lone_lf:
            # Find first lone LF
            m = re.search(rb"(?<!\r)\n", raw)
            if m:
                line = raw[:m.start()].count(b"\n") + 1
                diags.append(Diagnostic(sp, line, 1, LEVEL_WARNING, "W002",
                                        "File mixes CRLF and LF line endings. Pick one (CRLF is conventional on Windows mod tooling)."))

    if "W003" not in disabled and " " in path.name:
        diags.append(Diagnostic(sp, 1, 1, LEVEL_WARNING, "W003",
                                f"Filename contains a space: {path.name!r}. PboProject can choke on spaces in paths."))

    if "W004" not in disabled:
        try:
            path.name.encode("ascii")
        except UnicodeEncodeError:
            diags.append(Diagnostic(sp, 1, 1, LEVEL_WARNING, "W004",
                                    f"Filename contains non-ASCII characters: {path.name!r}"))

    # Per-line checks: trailing whitespace, mixed indent, double-backslash strings
    try:
        text = raw.decode("utf-8", errors="replace")
    except Exception:
        return diags

    for i, line in enumerate(text.splitlines(), start=1):
        if "W010" not in disabled and line.rstrip("\r") != line.rstrip("\r ").rstrip("\t"):
            stripped = line.rstrip("\r")
            if stripped and stripped[-1] in " \t":
                diags.append(Diagnostic(sp, i, len(stripped), LEVEL_WARNING, "W010",
                                        "Trailing whitespace at end of line"))
        if "W009" not in disabled:
            # Look at the leading whitespace block
            m = re.match(r"^([ \t]+)", line)
            if m and " " in m.group(1) and "\t" in m.group(1):
                diags.append(Diagnostic(sp, i, 1, LEVEL_WARNING, "W009",
                                        "Indentation mixes tabs and spaces"))

    return diags


# ----------------------------------------------------------------------------
# Project-level checks
# ----------------------------------------------------------------------------

def check_cfg_patches(parsed: FileParseResult, *, addon_root: Path | None, disabled: set[str]) -> list[Diagnostic]:
    diags: list[Diagnostic] = []

    cfg_patches = next((c for c in parsed.classes if c.name == "CfgPatches" and not c.is_forward), None)

    # If this looks like the addon's root config.cpp (lives directly inside an
    # Addons/<addon>/ folder) and CfgPatches is missing entirely → W014
    if "W014" not in disabled and addon_root is not None:
        p = Path(parsed.path)
        if p.name.lower() == "config.cpp" and p.parent == addon_root and cfg_patches is None:
            diags.append(Diagnostic(parsed.path, 1, 1, LEVEL_WARNING, "W014",
                                    "Addon-root config.cpp has no CfgPatches block. Arma will refuse to load this addon."))

    if cfg_patches is None:
        return diags

    for sub in cfg_patches.children:
        # Each child of CfgPatches should declare requiredAddons[], units[], weapons[]
        # We only have the *class structure*, not the assignments — we need to
        # re-scan the source for those. Cheap workaround: store the raw assignment
        # names during parse. For now, a pragmatic re-read of the file:
        pass  # handled in scan_cfgpatches_fields below

    return diags


def scan_cfgpatches_fields(path: Path, raw_text: str, disabled: set[str]) -> list[Diagnostic]:
    """
    Cheap regex pass over CfgPatches subclasses to verify they have
    requiredAddons[], units[], weapons[].

    We deliberately don't reuse the parser's class tree here — assignments
    aren't stored in nodes. A bounded regex per CfgPatches body is good enough
    and avoids re-architecting the parser for this single check.
    """
    diags: list[Diagnostic] = []
    sp = str(path)

    # Find a top-level "class CfgPatches { ... };" (greedy on inner content)
    # Strip comments first to avoid false negatives
    stripped = strip_comments(raw_text)

    # Locate "class CfgPatches" then walk braces to find body
    m = re.search(r"\bclass\s+CfgPatches\b", stripped)
    if not m:
        return diags
    i = m.end()
    # Skip whitespace / parent
    while i < len(stripped) and stripped[i] != "{":
        i += 1
    if i >= len(stripped):
        return diags
    # Walk braces
    depth = 0
    body_start = i + 1
    j = i
    while j < len(stripped):
        c = stripped[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                break
        j += 1
    body = stripped[body_start:j]

    # Find each subclass declaration inside body
    for sub in re.finditer(r"\bclass\s+(\w+)\s*(?::\s*\w+\s*)?\{", body):
        name = sub.group(1)
        # Find this subclass's body
        sub_start = sub.end()
        depth = 1
        k = sub_start
        while k < len(body) and depth > 0:
            ch = body[k]
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    break
            k += 1
        sub_body = body[sub_start:k]
        # Compute approximate line for diagnostics
        line = stripped[:body_start + sub.start()].count("\n") + 1

        if "W006" not in disabled and not re.search(r"\brequiredAddons\s*\[\s*\]\s*=", sub_body):
            diags.append(Diagnostic(sp, line, 1, LEVEL_WARNING, "W006",
                                    f"CfgPatches class '{name}' is missing 'requiredAddons[] = {{...}};'"))
        if "W007" not in disabled and not re.search(r"\bunits\s*\[\s*\]\s*=", sub_body):
            diags.append(Diagnostic(sp, line, 1, LEVEL_WARNING, "W007",
                                    f"CfgPatches class '{name}' is missing 'units[] = {{...}};'"))
        if "W008" not in disabled and not re.search(r"\bweapons\s*\[\s*\]\s*=", sub_body):
            diags.append(Diagnostic(sp, line, 1, LEVEL_WARNING, "W008",
                                    f"CfgPatches class '{name}' is missing 'weapons[] = {{...}};'"))

    return diags


def _find_case_insensitive(target: Path) -> Path | None:
    """Walk up looking for a case-insensitive match of `target`."""
    if target.exists():
        return target
    parent = target.parent
    if not parent.exists():
        # Try resolving the parent case-insensitively recursively
        ci_parent = _find_case_insensitive(parent)
        if ci_parent is None:
            return None
        parent = ci_parent
    name_lower = target.name.lower()
    try:
        for entry in parent.iterdir():
            if entry.name.lower() == name_lower:
                return entry
    except OSError:
        return None
    return None


def _external_include_root(rel_target: str, internal_prefixes: tuple[str, ...]) -> str | None:
    """
    For an absolute-style include (leading \\ or /), return the first path
    segment if it isn't one of our own top-level folders, else None.

    Relative includes always return None: those must resolve inside the repo,
    so a miss there is a genuine error.
    """
    if not rel_target.startswith("/"):
        return None
    segs = [s for s in rel_target.split("/") if s]
    if len(segs) < 2:
        return None
    first = segs[0]
    for p in internal_prefixes:
        if first.lower().startswith(p.lower()):
            return None
    return first


def check_includes(path: Path, raw_text: str, include_dirs: list[Path], disabled: set[str], pbo_root: Path | None,
                   internal_prefixes: tuple[str, ...] = DEFAULT_INTERNAL_PREFIXES) -> list[Diagnostic]:
    diags: list[Diagnostic] = []
    sp = str(path)

    # Match #include "..." or #include <...>
    for m in re.finditer(r'^[ \t]*#include[ \t]+([\"<])([^\">\n]+)([\">])', raw_text, flags=re.MULTILINE):
        line_no = raw_text[:m.start()].count("\n") + 1
        opener, target, closer = m.group(1), m.group(2), m.group(3)

        # Sanity-match brackets
        if (opener == '"' and closer != '"') or (opener == '<' and closer != '>'):
            diags.append(Diagnostic(sp, line_no, 1, LEVEL_ERROR, "E013",
                                    f"Malformed #include delimiters around {target!r}"))
            continue

        if "W015" not in disabled and "/" in target and "\\" not in target:
            diags.append(Diagnostic(sp, line_no, 1, LEVEL_WARNING, "W015",
                                    f"#include path uses forward slashes: {target!r}. Arma convention is backslashes."))

        # Try multiple resolution strategies
        rel_target = target.replace("\\", "/")

        candidates: list[Path] = []
        if rel_target.startswith("/"):
            for d in include_dirs:
                candidates.append(d / rel_target.lstrip("/"))
        else:
            candidates.append(path.parent / rel_target)
            for d in include_dirs:
                candidates.append(d / rel_target)

        # Exact-match check first
        if any(c.exists() for c in candidates):
            continue

        # Case-insensitive fallback — if we find a match this way, the
        # build will work on Windows but break on case-sensitive
        # filesystems (Linux build runners, Mac dev boxes).
        ci_match: Path | None = None
        for c in candidates:
            ci = _find_case_insensitive(c)
            if ci is not None:
                ci_match = ci
                break

        if ci_match is not None:
            if "W017" not in disabled:
                diags.append(Diagnostic(sp, line_no, 1, LEVEL_WARNING, "W017",
                                        f"#include path {target!r} differs in case from real file {ci_match.name!r}. "
                                        f"Works on Windows, but breaks PboProject on Linux/Mac and CI."))
            continue

        external_root = _external_include_root(rel_target, internal_prefixes)
        if external_root is not None:
            if "W018" not in disabled:
                own = ", ".join(p + "*" for p in internal_prefixes)
                diags.append(Diagnostic(sp, line_no, 1, LEVEL_WARNING, "W018",
                                        f"#include target not found: {target!r}. Root folder {external_root!r} is not "
                                        f"part of this project ({own}), so it can't be resolved from the repo. "
                                        f"Assuming external/soft dependency."))
            continue

        if "E013" not in disabled:
            hint = ""
            if pbo_root is not None and rel_target.startswith("/"):
                hint = f" (looked under {pbo_root}/...)"
            diags.append(Diagnostic(sp, line_no, 1, LEVEL_ERROR, "E013",
                                    f"#include target not found: {target!r}{hint}"))

    # Double-backslash in non-include strings is a common gotcha (W013)
    if "W013" not in disabled:
        # Walk string literals only, skipping the #include lines we already scanned
        lines = raw_text.splitlines()
        for i, line in enumerate(lines, start=1):
            if line.lstrip().startswith("#include"):
                continue
            for sm in re.finditer(r'"([^"\n]*)"', line):
                if "\\\\" in sm.group(1):
                    diags.append(Diagnostic(sp, i, sm.start() + 1, LEVEL_WARNING, "W013",
                                            "String literal contains '\\\\' — Arma config strings use single backslash for paths."))
                    break

    return diags


def check_path_constraints(path: Path, repo_root: Path, max_path_len: int, disabled: set[str]) -> list[Diagnostic]:
    diags: list[Diagnostic] = []
    sp = str(path)

    try:
        rel = path.resolve().relative_to(repo_root.resolve())
    except ValueError:
        rel = path

    rel_str = str(rel).replace(os.sep, "/")

    if "W003" not in disabled and " " in rel_str:
        diags.append(Diagnostic(sp, 1, 1, LEVEL_WARNING, "W003",
                                f"Path contains a space: {rel_str!r}. Strip the space — PboProject often gives up at this."))

    if "W005" not in disabled and len(rel_str) > max_path_len:
        diags.append(Diagnostic(sp, 1, 1, LEVEL_WARNING, "W005",
                                f"Path is {len(rel_str)} chars (>{max_path_len}). Some Arma path operations have hard limits — keep it short."))

    return diags


# ----------------------------------------------------------------------------
# Helpers
# ----------------------------------------------------------------------------

_BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.DOTALL)
_LINE_COMMENT_RE = re.compile(r"//[^\n]*")


def strip_comments(text: str) -> str:
    """Remove comments but preserve newlines so line numbers stay right."""
    def _block(m: re.Match[str]) -> str:
        return "\n" * m.group(0).count("\n")
    text = _BLOCK_COMMENT_RE.sub(_block, text)
    text = _LINE_COMMENT_RE.sub("", text)
    return text


# ----------------------------------------------------------------------------
# Top-level driver
# ----------------------------------------------------------------------------

CONFIG_EXTS = {".cpp", ".hpp", ".cfg"}


def find_config_files(paths: Iterable[str]) -> Iterator[Path]:
    for raw in paths:
        p = Path(raw)
        if p.is_dir():
            for f in p.rglob("*"):
                if f.is_file() and f.suffix.lower() in CONFIG_EXTS:
                    # skip .git, build, etc.
                    if any(part in {".git", "node_modules", "build", "@build"} for part in f.parts):
                        continue
                    yield f
        elif p.is_file():
            yield p
        else:
            print(f"warning: {raw} is not a file or directory; skipping", file=sys.stderr)


def find_addon_root(file_path: Path) -> Path | None:
    """Walk up looking for an Addons/<name>/ ancestor; return the <name> dir."""
    p = file_path.resolve()
    parts = p.parts
    for i in range(len(parts) - 2, -1, -1):
        if parts[i].lower() == "addons":
            return Path(*parts[: i + 2])
    return None


def lint_file(path: Path, repo_root: Path, include_dirs: list[Path], max_path_len: int, disabled: set[str],
              project_classes: set[str] | None = None,
              internal_prefixes: tuple[str, ...] = DEFAULT_INTERNAL_PREFIXES) -> tuple[list[Diagnostic], FileParseResult | None]:
    diags: list[Diagnostic] = []

    try:
        raw = path.read_bytes()
    except OSError as e:
        return [Diagnostic(str(path), 1, 1, LEVEL_ERROR, "E013", f"Cannot read file: {e}")], None

    # Strip BOM for parser, but record it
    if raw.startswith(b"\xef\xbb\xbf"):
        text_for_parse = raw[3:].decode("utf-8", errors="replace")
    else:
        text_for_parse = raw.decode("utf-8", errors="replace")

    diags.extend(file_level_checks(path, raw, disabled))
    diags.extend(check_path_constraints(path, repo_root, max_path_len, disabled))

    # Lex
    lexer = Lexer(text_for_parse)
    try:
        tokens = lexer.tokenize()
    except LexError as e:
        if e.rule not in disabled:
            diags.append(Diagnostic(str(path), e.line, e.col, LEVEL_ERROR, e.rule, e.message))
        for d in lexer.diagnostics:
            d2 = Diagnostic(str(path), d.line, d.col, d.level, d.rule, d.message)
            if d2.rule not in disabled:
                diags.append(d2)
        return diags, None
    for d in lexer.diagnostics:
        d2 = Diagnostic(str(path), d.line, d.col, d.level, d.rule, d.message)
        if d2.rule not in disabled:
            diags.append(d2)

    # Sanity bracket balance (caught by parser too, but cheap pre-check gives better message)
    o = sum(1 for t in tokens if t.kind == "{")
    c = sum(1 for t in tokens if t.kind == "}")
    if o != c and "E001" not in disabled:
        diags.append(Diagnostic(str(path), 1, 1, LEVEL_ERROR, "E001",
                                f"Brace count mismatch: {o} '{{' vs {c} '}}'. Parser will continue but cascade errors are likely."))
    o = sum(1 for t in tokens if t.kind == "[")
    c = sum(1 for t in tokens if t.kind == "]")
    if o != c and "E002" not in disabled:
        diags.append(Diagnostic(str(path), 1, 1, LEVEL_ERROR, "E002",
                                f"Square bracket mismatch: {o} '[' vs {c} ']'."))
    o = sum(1 for t in tokens if t.kind == "(")
    c = sum(1 for t in tokens if t.kind == ")")
    if o != c and "E003" not in disabled:
        diags.append(Diagnostic(str(path), 1, 1, LEVEL_ERROR, "E003",
                                f"Parenthesis mismatch: {o} '(' vs {c} ')'."))

    # Preprocessor balance
    pp_tokens = [t for t in tokens if t.kind == "PP"]
    if pp_tokens and "E006" not in disabled:
        ifs = sum(1 for t in pp_tokens if re.match(r"^\s*#\s*if(n?def)?\b", t.value))
        endifs = sum(1 for t in pp_tokens if re.match(r"^\s*#\s*endif\b", t.value))
        if ifs != endifs:
            first = pp_tokens[0]
            diags.append(Diagnostic(str(path), first.line, first.col, LEVEL_ERROR, "E006",
                                    f"Preprocessor #if/#endif mismatch: {ifs} '#if(n?def)' vs {endifs} '#endif'"))

    # Parse
    parser = Parser(tokens, str(path))
    parsed = parser.parse()
    for d in parsed.diagnostics:
        # If we have a project-wide class set, suppress E016 for parents that
        # are declared anywhere in the project.
        if d.rule == "E016" and project_classes is not None:
            # Extract the parent class name from the message: "...inherits from 'X', which..."
            m = re.search(r"inherits from '([^']+)'", d.message)
            if m and m.group(1) in project_classes:
                continue
        if d.rule not in disabled:
            diags.append(d)

    addon_root = find_addon_root(path)
    diags.extend(check_cfg_patches(parsed, addon_root=addon_root, disabled=disabled))
    diags.extend(scan_cfgpatches_fields(path, text_for_parse, disabled=disabled))
    diags.extend(check_includes(path, text_for_parse, include_dirs=include_dirs, disabled=disabled, pbo_root=repo_root,
                                internal_prefixes=internal_prefixes))

    return diags, parsed


def collect_project_classes(parsed_files: list[FileParseResult]) -> set[str]:
    """Walk all parsed file results and collect every class name declared,
    forward or full, at any depth. Used to suppress E016 false positives."""
    names: set[str] = set()

    def walk(node: ClassNode) -> None:
        names.add(node.name)
        for c in node.children:
            walk(c)

    for f in parsed_files:
        for c in f.classes:
            walk(c)
    return names


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(
        prog="arma_lint",
        description="Lint Arma 3 mod config files (.cpp/.hpp/.cfg)",
    )
    parser.add_argument("paths", nargs="*", default=["."], help="Files or directories to lint (default: .)")
    parser.add_argument("-W", "--warnings-as-errors", action="store_true")
    parser.add_argument("--no-warnings", action="store_true", help="Hide warnings entirely")
    parser.add_argument("--json", action="store_true", help="Emit JSON")
    parser.add_argument("--include-dir", action="append", default=[], help="Extra include search root (repeatable)")
    parser.add_argument("--max-path-len", type=int, default=100, help="Max in-PBO path length to allow")
    parser.add_argument("--internal-prefix", action="append", default=[],
                        help="Top-level folder prefix that counts as part of this project (repeatable). "
                             f"Absolute #includes rooted elsewhere downgrade from E013 to W018. "
                             f"Default: {', '.join(DEFAULT_INTERNAL_PREFIXES)}")
    parser.add_argument("--quiet", action="store_true")
    parser.add_argument("--disable", action="append", default=[], help="Disable a rule by ID (repeatable)")
    parser.add_argument("--enable", action="append", default=[], help="Force-enable a rule by ID (repeatable)")
    parser.add_argument("--cosmetic", action="store_true",
                        help=f"Enable cosmetic/style rules (off by default): {', '.join(sorted(COSMETIC_RULES))}")
    parser.add_argument("--rules", action="store_true", help="List all rules and exit")
    args = parser.parse_args(argv)

    if args.rules:
        for rid, (lvl, desc) in sorted(RULES.items()):
            tag = " [cosmetic]" if rid in COSMETIC_RULES else ""
            print(f"{rid}  {lvl:8s}  {desc}{tag}")
        return 0

    disabled: set[str] = set(args.disable)
    if not args.cosmetic:
        # Don't add explicitly-enabled rules to the disabled set
        enabled = set(args.enable)
        for r in COSMETIC_RULES:
            if r not in enabled:
                disabled.add(r)
    repo_root = Path(args.paths[0]).resolve() if len(args.paths) == 1 and Path(args.paths[0]).is_dir() else Path.cwd()
    internal_prefixes = tuple(args.internal_prefix) if args.internal_prefix else DEFAULT_INTERNAL_PREFIXES
    include_dirs = [Path(d).resolve() for d in args.include_dir]
    # Always include repo_root as an include search dir
    if repo_root not in include_dirs:
        include_dirs.append(repo_root)

    files = list(find_config_files(args.paths))
    files.sort()

    # First pass: lex+parse every file silently to gather every declared
    # class name across the project. We discard diagnostics and re-run
    # the full lint pass below — but the parse output gives us a known
    # universe of class names so cross-file inheritance (`class Foo : BaseFromOtherFile`)
    # doesn't trip E016.
    project_classes: set[str] = set()
    parse_results: list[FileParseResult] = []
    for f in files:
        try:
            raw = f.read_bytes()
            text = raw[3:] if raw.startswith(b"\xef\xbb\xbf") else raw
            text_str = text.decode("utf-8", errors="replace")
            try:
                tokens = Lexer(text_str).tokenize()
            except LexError:
                continue
            parsed = Parser(tokens, str(f)).parse()
            parse_results.append(parsed)
        except OSError:
            continue
    project_classes = collect_project_classes(parse_results)

    all_diags: list[Diagnostic] = []
    for f in files:
        file_diags, _ = lint_file(f, repo_root, include_dirs, args.max_path_len, disabled,
                                  project_classes=project_classes, internal_prefixes=internal_prefixes)
        all_diags.extend(file_diags)

    if args.no_warnings:
        all_diags = [d for d in all_diags if d.level != LEVEL_WARNING]

    # Sort: by file, then by line
    all_diags.sort(key=lambda d: (d.file, d.line, d.col, d.rule))

    n_err = sum(1 for d in all_diags if d.level == LEVEL_ERROR)
    n_warn = sum(1 for d in all_diags if d.level == LEVEL_WARNING)
    n_info = sum(1 for d in all_diags if d.level == LEVEL_INFO)

    if args.json:
        print(json.dumps({
            "summary": {
                "files_scanned": len(files),
                "errors": n_err,
                "warnings": n_warn,
                "info": n_info,
            },
            "diagnostics": [asdict(d) for d in all_diags],
        }, indent=2))
    else:
        for d in all_diags:
            print(d.format_human(repo_root))
        if not args.quiet:
            print(f"\nScanned {len(files)} file(s): {n_err} error(s), {n_warn} warning(s), {n_info} info", file=sys.stderr)

    if n_err > 0:
        return 2
    if n_warn > 0 and args.warnings_as_errors:
        return 2
    if n_warn > 0:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))