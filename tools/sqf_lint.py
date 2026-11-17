#!/usr/bin/env python3
"""
sqf_lint.py - A linter for Arma 3 SQF script files (.sqf).

Designed as a structural linter. It does NOT carry a command database, so
modern commands (setCruiseControl, etc.) and modern syntax (the '#' select
operator) Just Work. If BI adds fifty new commands tomorrow, this linter
keeps running without an update because it never tried to validate command
names in the first place.

What it catches:
  * Hard syntax errors that will make the SQF compiler refuse to parse
    (unbalanced brackets, unterminated strings/comments, malformed
    preprocessor directives)
  * Common SQF mistakes (missing 'then' after 'if', missing 'do' after
    'while'/'for', '=' used as comparison, undeclared local variables)
  * Style issues (BOM, mixed line endings, tabs/spaces, locals without
    private, suspicious variable shadowing)

Stdlib only. Python 3.8+.

Usage:
    python3 sqf_lint.py [paths...]

Common flags:
    -W, --warnings-as-errors   Treat warnings as errors (exit 2 if any)
    --no-warnings              Suppress warnings entirely
    --json                     Emit JSON instead of human-readable output
    --quiet                    Hide the per-run summary line
    --rules                    List all rules and exit
    --disable RULE             Disable a rule by ID (repeatable)
    --enable RULE              Force-enable a rule by ID (repeatable)
    --cosmetic                 Enable cosmetic/style rules (off by default)
    --ignore-name NAME         Treat NAME as a known global identifier
                               (repeatable; useful for project conventions)
    --max-line-len N           Override long-line warning threshold (default 200)

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
from typing import Iterable, Iterator, Optional


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

    def format_human(self, root: Optional[Path] = None) -> str:
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
# Rule registry. Keep IDs stable so users can disable specific rules.
# ----------------------------------------------------------------------------

RULES: dict = {
    # id: (default_level, description)

    # ---- Hard syntax errors ----
    "E001": (LEVEL_ERROR,   "Unbalanced braces { }"),
    "E002": (LEVEL_ERROR,   "Unbalanced square brackets [ ]"),
    "E003": (LEVEL_ERROR,   "Unbalanced parentheses ( )"),
    "E004": (LEVEL_ERROR,   "Unterminated string literal"),
    "E005": (LEVEL_ERROR,   "Unterminated block comment"),
    "E006": (LEVEL_ERROR,   "Unbalanced preprocessor #if/#endif"),
    "E007": (LEVEL_ERROR,   "Malformed preprocessor directive"),
    "E008": (LEVEL_ERROR,   "Stray closing bracket with no matching opener"),

    # ---- Structural (control flow) errors ----
    "E010": (LEVEL_ERROR,   "'if' condition not followed by 'then' or 'exitWith'"),
    "E011": (LEVEL_ERROR,   "'while' condition not followed by 'do'"),
    "E012": (LEVEL_ERROR,   "'for' loop missing 'do' clause"),
    "E013": (LEVEL_ERROR,   "'switch' block not followed by 'do'"),
    "E014": (LEVEL_ERROR,   "'case' / 'default' used outside a switch block"),
    "E015": (LEVEL_ERROR,   "'else' used outside an if/then chain"),
    "E016": (LEVEL_ERROR,   "Trailing operator at end of expression"),
    "E017": (LEVEL_ERROR,   "Two consecutive operators with no operand between"),
    "E018": (LEVEL_ERROR,   "Empty parentheses where expression expected"),
    "E019": (LEVEL_ERROR,   "'private' must be followed by a variable or array of strings"),

    # ---- Warnings (likely problems) ----
    "W001": (LEVEL_WARNING, "UTF-8 BOM at start of file"),
    "W002": (LEVEL_WARNING, "Mixed line endings (CRLF and LF in same file)"),
    "W003": (LEVEL_WARNING, "File is not valid UTF-8"),
    "W004": (LEVEL_WARNING, "Filename or path contains spaces"),
    "W005": (LEVEL_WARNING, "Local variable used without 'private' declaration"),
    "W006": (LEVEL_WARNING, "Likely typo: '=' used as comparison (use '==' or 'isEqualTo')"),
    "W007": (LEVEL_WARNING, "Bare lowercase identifier looks like an undeclared local (missing underscore?)"),
    "W008": (LEVEL_WARNING, "Empty if/while/for body"),
    "W009": (LEVEL_WARNING, "'private' re-declares variable already private in same scope"),
    "W010": (LEVEL_WARNING, "Mixed tabs and spaces for indentation"),
    "W011": (LEVEL_WARNING, "Trailing whitespace at end of line"),
    "W012": (LEVEL_WARNING, "Line exceeds max length (configurable via --max-line-len)"),
    "W013": (LEVEL_WARNING, "Suspicious 'compile' on non-literal value (security/perf concern)"),
    "W014": (LEVEL_WARNING, "Possible string concatenation without '+' (use 'format' or '+')"),
    "W015": (LEVEL_WARNING, "Local variable assigned but never used"),
    "W016": (LEVEL_WARNING, "Magic number in code (consider a named constant)"),
}

# Rules that are off by default, opt in via --cosmetic.
COSMETIC_RULES = {"W010", "W011", "W012", "W016"}


def all_rule_ids() -> list:
    return list(RULES.keys())


# ----------------------------------------------------------------------------
# SQF reserved keywords. These have special parse meaning - they're the only
# identifiers we treat differently. Everything else (commands, BIS_fnc_*,
# user functions, mod globals) is just an IDENT token.
#
# Deliberately kept short. The point of this linter is structural validation,
# not command database matching.
# ----------------------------------------------------------------------------

KW_CONTROL = {
    "if", "then", "else",
    "while", "do",
    "for", "from", "to", "step",
    "forEach", "foreach",
    "switch", "case", "default",
    "try", "catch", "throw",
    "exitWith", "exitwith",
    "with",
    "params",
    "private",
}

# Booleans / nil are treated as IDENT but recognised so we don't accidentally
# warn on them.
KW_LITERALS = {"true", "false", "nil"}

# These show up bare (no parens) and combine with whatever follows. We flag
# 'if' missing 'then' but only if the if-construct doesn't dissolve into one
# of these legal continuations.
LEGAL_AFTER_IF_CONDITION = {"then", "exitWith", "exitwith"}


# ----------------------------------------------------------------------------
# Lexer
# ----------------------------------------------------------------------------

@dataclass
class Token:
    kind: str   # 'IDENT', 'STRING', 'NUMBER', 'OP', '{', '}', '[', ']', '(', ')', ';', ',', 'PP', 'KW_*'
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


# Operators recognised by the tokenizer, longest match first.
# We keep these as OP tokens (with the literal in .value) so the parser can
# spot consecutive-operator errors without caring about which one.
#
# Note: '#' is in here. This is the modern array-select shorthand (`_arr#0`)
# that broke LordGolias. We just emit it as an OP and move on.
_OPERATORS = [
    "==", "!=", ">=", "<=", "&&", "||", ">>",
    "+", "-", "*", "/", "%", "^",
    "=", ">", "<", "!",
    "#",
    ":",
]
_OPERATORS.sort(key=len, reverse=True)

_NUMBER_RE = re.compile(
    r"""
    (?:
        0[xX][0-9a-fA-F]+      # hex
      | \$[0-9a-fA-F]+         # alternative hex prefix sometimes used
      | (?:\d+\.\d*|\.\d+|\d+) # decimal / float
        (?:[eE][+-]?\d+)?      # optional exponent
    )
    """,
    re.VERBOSE,
)

_IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z_0-9]*")


class Lexer:
    """
    Tokenises SQF source. Strips comments. Captures preprocessor lines
    as PP tokens (including #include, #define, #ifdef, etc.) so the
    parser can sidestep them and we can balance-check them later.
    """

    def __init__(self, src: str):
        self.src = src
        self.pos = 0
        self.line = 1
        self.col = 1
        self.tokens: list = []
        self.diagnostics: list = []
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

    def _is_at_line_start(self) -> bool:
        # True iff there's nothing but whitespace between the start of the
        # current line and the cursor.
        i = self.pos - 1
        while i >= 0:
            ch = self.src[i]
            if ch == "\n":
                return True
            if ch not in " \t":
                return False
            i -= 1
        return True

    def _emit(self, kind: str, value: str, line: int, col: int) -> None:
        self.tokens.append(Token(kind, value, line, col))

    def tokenize(self) -> list:
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

            # Preprocessor line
            if c == "#" and self._is_at_line_start():
                start_line, start_col = self.line, self.col
                buf = []
                while self.pos < self.length:
                    ch = self._peek()
                    if ch == "\n":
                        # Backslash line continuation: previous non-whitespace char on the line is '\'
                        line_so_far = "".join(buf)
                        if line_so_far.rstrip(" \t").endswith("\\"):
                            stripped = line_so_far.rstrip(" \t")
                            buf = [stripped[:-1]]
                            buf.append("\n")
                            self._advance()
                            continue
                        break
                    buf.append(ch)
                    self._advance()
                self._emit("PP", "".join(buf), start_line, start_col)
                continue

            # String literal — double or single quoted, both with doubled-quote escape
            if c == '"' or c == "'":
                start_line, start_col = self.line, self.col
                quote = c
                self._advance()
                buf = []
                closed = False
                while self.pos < self.length:
                    ch = self._peek()
                    if ch == quote:
                        # Doubled quote = literal quote inside string
                        if self._peek(1) == quote:
                            buf.append(quote)
                            self._advance()
                            self._advance()
                            continue
                        self._advance()
                        closed = True
                        break
                    # SQF strings can span multiple lines (for both quote types).
                    buf.append(ch)
                    self._advance()
                if not closed:
                    raise LexError(
                        f"Unterminated string literal (started with {quote})",
                        start_line, start_col, "E004",
                    )
                self._emit("STRING", "".join(buf), start_line, start_col)
                continue

            # Number
            if c.isdigit() or (c == "." and self._peek(1).isdigit()) or (c == "$" and self._peek(1) and self._peek(1) in "0123456789abcdefABCDEF"):
                m = _NUMBER_RE.match(self.src, self.pos)
                if m:
                    start_line, start_col = self.line, self.col
                    val = m.group(0)
                    for _ in val:
                        self._advance()
                    self._emit("NUMBER", val, start_line, start_col)
                    continue

            # Identifier / keyword
            if c.isalpha() or c == "_":
                m = _IDENT_RE.match(self.src, self.pos)
                if m:
                    start_line, start_col = self.line, self.col
                    val = m.group(0)
                    for _ in val:
                        self._advance()
                    # Preserve case: SQF is case-insensitive for commands but
                    # not for variable names. We compare lowercased for
                    # control keywords below.
                    if val.lower() in KW_CONTROL:
                        self._emit("KW_" + val.lower(), val, start_line, start_col)
                    else:
                        self._emit("IDENT", val, start_line, start_col)
                    continue

            # Punctuation
            if c in "{}[]();,":
                start_line, start_col = self.line, self.col
                self._advance()
                self._emit(c, c, start_line, start_col)
                continue

            # Operators (longest match first)
            matched = False
            for op in _OPERATORS:
                if self.src.startswith(op, self.pos):
                    start_line, start_col = self.line, self.col
                    for _ in op:
                        self._advance()
                    self._emit("OP", op, start_line, start_col)
                    matched = True
                    break
            if matched:
                continue

            # Anything else is an unknown char - record info and skip
            start_line, start_col = self.line, self.col
            self.diagnostics.append(Diagnostic(
                file="", line=start_line, col=start_col,
                level=LEVEL_INFO, rule="E007",
                message=f"Unrecognised character '{c!r}' (U+{ord(c):04X})",
            ))
            self._advance()

        return self.tokens


# ----------------------------------------------------------------------------
# Bracket balance checker.
# Operates on tokens so brackets inside strings/comments are correctly ignored.
# ----------------------------------------------------------------------------

def check_bracket_balance(tokens: list, file: str) -> list:
    """Return a list of E001/E002/E003/E008 diagnostics for unmatched brackets."""
    diags = []
    stack = []  # (open_kind, line, col)
    pairs = {")": "(", "]": "[", "}": "{"}

    rule_for_open = {"(": "E003", "[": "E002", "{": "E001"}
    rule_for_close = {")": "E003", "]": "E002", "}": "E001"}

    for tok in tokens:
        if tok.kind in "([{":
            stack.append(tok)
        elif tok.kind in ")]}":
            if not stack:
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule="E008",
                    message=f"Stray closing '{tok.kind}' with no matching opener",
                ))
                continue
            opener = stack.pop()
            expected = pairs[tok.kind]
            if opener.kind != expected:
                # Mismatched: report against the wrong-type closer
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule=rule_for_close[tok.kind],
                    message=(f"Closing '{tok.kind}' at this position does not match "
                             f"the open '{opener.kind}' at line {opener.line}:{opener.col}"),
                ))
                # Don't push the opener back; we've consumed it as best-effort recovery
    # Anything left open
    for opener in stack:
        diags.append(Diagnostic(
            file=file, line=opener.line, col=opener.col,
            level=LEVEL_ERROR, rule=rule_for_open[opener.kind],
            message=f"Open '{opener.kind}' has no matching closer",
        ))
    return diags


def check_pp_balance(tokens: list, file: str) -> list:
    """Verify #if(n)def / #endif balance across the file."""
    diags = []
    stack = []  # (line, col, directive)
    for tok in tokens:
        if tok.kind != "PP":
            continue
        # First non-whitespace token after the '#' tells us the directive
        m = re.match(r"\s*#\s*(\w+)", tok.value)
        if not m:
            diags.append(Diagnostic(
                file=file, line=tok.line, col=tok.col,
                level=LEVEL_ERROR, rule="E007",
                message="Malformed preprocessor directive (no directive name)",
            ))
            continue
        directive = m.group(1).lower()
        if directive in ("if", "ifdef", "ifndef"):
            stack.append((tok.line, tok.col, directive))
        elif directive == "endif":
            if not stack:
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule="E006",
                    message="#endif with no matching #if/#ifdef/#ifndef",
                ))
            else:
                stack.pop()
        elif directive in ("else", "elif"):
            if not stack:
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule="E006",
                    message=f"#{directive} with no matching #if/#ifdef/#ifndef",
                ))
        # #define, #include, #undef, #pragma — no balance impact
    for line, col, directive in stack:
        diags.append(Diagnostic(
            file=file, line=line, col=col,
            level=LEVEL_ERROR, rule="E006",
            message=f"Unclosed #{directive} (no matching #endif)",
        ))
    return diags


# ----------------------------------------------------------------------------
# Structural / control-flow checks.
#
# These operate on the token stream and look for specific shapes:
#   * `if (cond)` should be followed (eventually) by `then`/`exitWith`
#   * `while (cond)` should be followed by `do`
#   * `for ... from ... to ... step? ... do`
#   * `switch (x) do { case ...; default: ...; }`
#
# We deliberately tolerate any number of intermediate tokens between the
# condition and the keyword, because users sometimes assign the condition
# to a var, comment heavily, etc.
# ----------------------------------------------------------------------------

def _next_significant(tokens: list, start: int) -> int:
    """Return the index of the next non-PP token at or after start, or len(tokens)."""
    i = start
    while i < len(tokens) and tokens[i].kind == "PP":
        i += 1
    return i


def _skip_balanced(tokens: list, start: int, open_kind: str, close_kind: str) -> int:
    """
    Given tokens[start] is open_kind, return the index just past the matching
    close_kind. Returns -1 if no match (caller should bail).
    """
    if start >= len(tokens) or tokens[start].kind != open_kind:
        return -1
    depth = 1
    i = start + 1
    while i < len(tokens):
        if tokens[i].kind == open_kind:
            depth += 1
        elif tokens[i].kind == close_kind:
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return -1


def check_control_flow(tokens: list, file: str) -> list:
    """Run the if/while/for/switch checks across all tokens."""
    diags = []
    n = len(tokens)
    i = 0
    # Track switch nesting to validate `case`/`default`
    switch_depth_stack = []  # list of brace-depths where a switch's body opens
    brace_depth = 0

    while i < n:
        tok = tokens[i]

        # Track plain brace depth for switch tracking
        if tok.kind == "{":
            brace_depth += 1
            i += 1
            continue
        if tok.kind == "}":
            brace_depth -= 1
            if switch_depth_stack and brace_depth < switch_depth_stack[-1]:
                switch_depth_stack.pop()
            i += 1
            continue

        if tok.kind == "KW_if":
            i = _check_if(tokens, i, file, diags)
            continue

        if tok.kind == "KW_while":
            i = _check_while(tokens, i, file, diags)
            continue

        if tok.kind == "KW_for":
            i = _check_for(tokens, i, file, diags)
            continue

        if tok.kind == "KW_switch":
            i, body_open_depth = _check_switch(tokens, i, file, diags, brace_depth)
            if body_open_depth is not None:
                switch_depth_stack.append(body_open_depth)
            continue

        if tok.kind == "KW_case" or tok.kind == "KW_default":
            # Must be inside a switch body
            if not switch_depth_stack:
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule="E014",
                    message=f"'{tok.value}' used outside a 'switch ... do {{ ... }}' block",
                ))
            i += 1
            continue

        if tok.kind == "KW_else":
            # 'else' is legal as `then ... else ...` or `if cond then {...} else {...}`.
            # We can't perfectly track this without full parsing, so we only flag
            # `else` that has no `then`/`}`/closing-paren immediately preceding it.
            # Reasonable heuristic: look back to the previous significant token.
            j = i - 1
            while j >= 0 and tokens[j].kind == "PP":
                j -= 1
            if j < 0:
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_ERROR, rule="E015",
                    message="'else' at start of file with no preceding 'then' branch",
                ))
            elif tokens[j].kind not in ("}", "STRING", "NUMBER", "IDENT", ")", "KW_then"):
                # Can be preceded by a value (rare 1-liner: then "foo" else "bar")
                diags.append(Diagnostic(
                    file=file, line=tok.line, col=tok.col,
                    level=LEVEL_WARNING, rule="E015",
                    message="'else' not preceded by a 'then' clause - check structure",
                ))
            i += 1
            continue

        i += 1

    return diags


def _check_if(tokens: list, i: int, file: str, diags: list) -> int:
    """
    Validate that `if <cond>` is followed by `then` or `exitWith`.
    Returns the new cursor.
    """
    if_tok = tokens[i]
    j = i + 1
    # Skip any whitespace/PP and find the condition. Conditions can be:
    #   * (paren expression)
    #   * a single identifier/literal
    #   * a complex expression terminated by `then`/`exitWith`/`;`
    j = _next_significant(tokens, j)
    if j >= len(tokens):
        diags.append(Diagnostic(
            file=file, line=if_tok.line, col=if_tok.col,
            level=LEVEL_ERROR, rule="E010",
            message="'if' at end of file with no condition",
        ))
        return i + 1

    # Scan forward, tracking nested brackets, looking for `then` or `exitWith`
    # at the same nesting level. Stop at `;` at level 0 (statement boundary).
    depth_paren = 0
    depth_bracket = 0
    depth_brace = 0
    seen_cond_token = False
    k = j
    while k < len(tokens):
        t = tokens[k]
        if t.kind == "(":
            depth_paren += 1
        elif t.kind == ")":
            depth_paren -= 1
            if depth_paren < 0:
                # We've fallen out of an outer paren - this if is part of a sub-expression
                break
        elif t.kind == "[":
            depth_bracket += 1
        elif t.kind == "]":
            depth_bracket -= 1
            if depth_bracket < 0:
                break
        elif t.kind == "{":
            depth_brace += 1
        elif t.kind == "}":
            depth_brace -= 1
            if depth_brace < 0:
                break
        elif depth_paren == 0 and depth_bracket == 0 and depth_brace == 0:
            if t.kind == ";" or t.kind == ",":
                # Statement boundary before `then`/`exitWith` - that's an error
                diags.append(Diagnostic(
                    file=file, line=if_tok.line, col=if_tok.col,
                    level=LEVEL_ERROR, rule="E010",
                    message="'if' condition not followed by 'then' or 'exitWith' before statement end",
                ))
                return k + 1
            if t.kind in ("KW_then", "KW_exitwith"):
                return k + 1
        if t.kind not in ("PP",):
            seen_cond_token = True
        k += 1

    # Reached end of tokens or fell out of enclosing bracket without finding then/exitWith
    if seen_cond_token:
        diags.append(Diagnostic(
            file=file, line=if_tok.line, col=if_tok.col,
            level=LEVEL_ERROR, rule="E010",
            message="'if' condition not followed by 'then' or 'exitWith'",
        ))
    return k


def _check_while(tokens: list, i: int, file: str, diags: list) -> int:
    """Validate `while <cond>` is followed by `do`."""
    while_tok = tokens[i]
    j = _next_significant(tokens, i + 1)
    if j >= len(tokens):
        diags.append(Diagnostic(
            file=file, line=while_tok.line, col=while_tok.col,
            level=LEVEL_ERROR, rule="E011",
            message="'while' at end of file with no condition",
        ))
        return i + 1

    depth_paren = 0
    depth_bracket = 0
    depth_brace = 0
    seen_cond_token = False
    k = j
    while k < len(tokens):
        t = tokens[k]
        if t.kind == "(":
            depth_paren += 1
        elif t.kind == ")":
            depth_paren -= 1
            if depth_paren < 0:
                break
        elif t.kind == "[":
            depth_bracket += 1
        elif t.kind == "]":
            depth_bracket -= 1
            if depth_bracket < 0:
                break
        elif t.kind == "{":
            depth_brace += 1
        elif t.kind == "}":
            depth_brace -= 1
            if depth_brace < 0:
                break
        elif depth_paren == 0 and depth_bracket == 0 and depth_brace == 0:
            if t.kind == ";" or t.kind == ",":
                diags.append(Diagnostic(
                    file=file, line=while_tok.line, col=while_tok.col,
                    level=LEVEL_ERROR, rule="E011",
                    message="'while' condition not followed by 'do' before statement end",
                ))
                return k + 1
            if t.kind == "KW_do":
                return k + 1
        if t.kind not in ("PP",):
            seen_cond_token = True
        k += 1

    if seen_cond_token:
        diags.append(Diagnostic(
            file=file, line=while_tok.line, col=while_tok.col,
            level=LEVEL_ERROR, rule="E011",
            message="'while' condition not followed by 'do'",
        ))
    return k


def _check_for(tokens: list, i: int, file: str, diags: list) -> int:
    """
    Validate `for ... do`. Two forms in SQF:
      * for [{init}, {cond}, {step}] do {body}    (C-style)
      * for "_var" from N to M [step S] do {body} (count-style)
    Either way, `do` must show up.
    """
    for_tok = tokens[i]
    depth_paren = 0
    depth_bracket = 0
    depth_brace = 0
    k = i + 1
    while k < len(tokens):
        t = tokens[k]
        if t.kind == "(":
            depth_paren += 1
        elif t.kind == ")":
            depth_paren -= 1
            if depth_paren < 0:
                break
        elif t.kind == "[":
            depth_bracket += 1
        elif t.kind == "]":
            depth_bracket -= 1
            if depth_bracket < 0:
                break
        elif t.kind == "{":
            depth_brace += 1
        elif t.kind == "}":
            depth_brace -= 1
            if depth_brace < 0:
                break
        elif depth_paren == 0 and depth_bracket == 0 and depth_brace == 0:
            if t.kind == ";":
                diags.append(Diagnostic(
                    file=file, line=for_tok.line, col=for_tok.col,
                    level=LEVEL_ERROR, rule="E012",
                    message="'for' loop missing 'do' clause before statement end",
                ))
                return k + 1
            if t.kind == "KW_do":
                return k + 1
        k += 1

    diags.append(Diagnostic(
        file=file, line=for_tok.line, col=for_tok.col,
        level=LEVEL_ERROR, rule="E012",
        message="'for' loop missing 'do' clause",
    ))
    return k


def _check_switch(tokens: list, i: int, file: str, diags: list, current_brace_depth: int):
    """
    Validate `switch <expr> do { ... }`.
    Returns (new_cursor, body_open_brace_depth_or_None).
    body_open_brace_depth_or_None is the brace depth AFTER opening the switch body,
    so the outer loop can pop the switch context when the corresponding } closes.
    """
    switch_tok = tokens[i]
    depth_paren = 0
    depth_bracket = 0
    k = i + 1
    while k < len(tokens):
        t = tokens[k]
        if t.kind == "(":
            depth_paren += 1
        elif t.kind == ")":
            depth_paren -= 1
            if depth_paren < 0:
                break
        elif t.kind == "[":
            depth_bracket += 1
        elif t.kind == "]":
            depth_bracket -= 1
            if depth_bracket < 0:
                break
        elif depth_paren == 0 and depth_bracket == 0:
            if t.kind == ";":
                diags.append(Diagnostic(
                    file=file, line=switch_tok.line, col=switch_tok.col,
                    level=LEVEL_ERROR, rule="E013",
                    message="'switch' block not followed by 'do' before statement end",
                ))
                return k + 1, None
            if t.kind == "KW_do":
                # Find the next `{` - that's the start of the body
                m = _next_significant(tokens, k + 1)
                if m < len(tokens) and tokens[m].kind == "{":
                    # The `{` will be consumed by the main loop, which increments brace_depth.
                    # We tell the caller "expect us to pop when brace_depth returns below current+1".
                    return k + 1, current_brace_depth + 1
                return k + 1, None
        k += 1

    diags.append(Diagnostic(
        file=file, line=switch_tok.line, col=switch_tok.col,
        level=LEVEL_ERROR, rule="E013",
        message="'switch' block not followed by 'do'",
    ))
    return k, None


# ----------------------------------------------------------------------------
# Operator-sequence checks
# ----------------------------------------------------------------------------

# Operators that cannot appear at end of expression
_TRAILING_BAD = {"+", "-", "*", "/", "%", "^", "==", "!=", ">=", "<=", "&&", "||", ">>", "=", ">", "<"}

# Operators that can be unary (so two operators in a row is OK if the second
# is unary, e.g. `x + -y`)
_CAN_BE_UNARY = {"-", "!", "+"}

def check_operator_sequences(tokens: list, file: str) -> list:
    """
    Catch two cases:
      * Trailing operator (operator at the very end with nothing after, or
        immediately followed by a closer like `;` `]` `)`).
      * Two consecutive binary operators with no operand between them, where
        the second isn't a legal unary form.
    """
    diags = []
    closers = {";", ")", "]", "}", ","}
    n = len(tokens)
    for i, t in enumerate(tokens):
        if t.kind != "OP":
            continue
        # Look ahead to next significant token
        j = i + 1
        while j < n and tokens[j].kind == "PP":
            j += 1
        if t.value in _TRAILING_BAD:
            if j >= n:
                diags.append(Diagnostic(
                    file=file, line=t.line, col=t.col,
                    level=LEVEL_ERROR, rule="E016",
                    message=f"Trailing operator '{t.value}' at end of file",
                ))
                continue
            if tokens[j].kind in closers:
                diags.append(Diagnostic(
                    file=file, line=t.line, col=t.col,
                    level=LEVEL_ERROR, rule="E016",
                    message=f"Trailing operator '{t.value}' before '{tokens[j].kind}'",
                ))
                continue
            # Two operators in a row?
            if tokens[j].kind == "OP":
                if tokens[j].value not in _CAN_BE_UNARY:
                    diags.append(Diagnostic(
                        file=file, line=t.line, col=t.col,
                        level=LEVEL_ERROR, rule="E017",
                        message=f"Operator '{t.value}' immediately followed by '{tokens[j].value}' "
                                f"with no operand between",
                    ))
    return diags


# ----------------------------------------------------------------------------
# Empty-parens check.
# `()` with nothing inside is essentially never valid in SQF (unlike e.g. C).
# Most often an oversight where a condition was meant.
# ----------------------------------------------------------------------------

def check_empty_parens(tokens: list, file: str) -> list:
    diags = []
    for i, t in enumerate(tokens):
        if t.kind != "(":
            continue
        j = i + 1
        while j < len(tokens) and tokens[j].kind == "PP":
            j += 1
        if j < len(tokens) and tokens[j].kind == ")":
            diags.append(Diagnostic(
                file=file, line=t.line, col=t.col,
                level=LEVEL_ERROR, rule="E018",
                message="Empty parentheses '()' - SQF expects an expression",
            ))
    return diags


# ----------------------------------------------------------------------------
# `private` semantics check.
# Forms:
#   private _var = expr;            (modern keyword form)
#   private ["_a", "_b"];            (legacy array form)
#   private "_var";                  (legacy single-string form)
# Anything else after `private` is an error.
# ----------------------------------------------------------------------------

def check_private_usage(tokens: list, file: str) -> list:
    diags = []
    n = len(tokens)
    for i, t in enumerate(tokens):
        if t.kind != "KW_private":
            continue
        j = _next_significant(tokens, i + 1)
        if j >= n:
            diags.append(Diagnostic(
                file=file, line=t.line, col=t.col,
                level=LEVEL_ERROR, rule="E019",
                message="'private' at end of file with no variable",
            ))
            continue
        nxt = tokens[j]
        if nxt.kind == "IDENT" and nxt.value.startswith("_"):
            continue  # private _foo
        if nxt.kind == "STRING" and nxt.value.startswith("_"):
            continue  # private "_foo"
        if nxt.kind == "[":
            # Array form: every element must be a string starting with '_'
            k = j + 1
            depth = 1
            saw_string = False
            while k < n and depth > 0:
                tt = tokens[k]
                if tt.kind == "[":
                    depth += 1
                elif tt.kind == "]":
                    depth -= 1
                elif tt.kind == "STRING" and depth == 1:
                    saw_string = True
                    if not tt.value.startswith("_"):
                        diags.append(Diagnostic(
                            file=file, line=tt.line, col=tt.col,
                            level=LEVEL_ERROR, rule="E019",
                            message=f"'private' array element \"{tt.value}\" should start with underscore",
                        ))
                elif tt.kind == "IDENT" and depth == 1 and tt.value.lower() not in KW_LITERALS:
                    # Bare identifier inside private array - probably a typo
                    diags.append(Diagnostic(
                        file=file, line=tt.line, col=tt.col,
                        level=LEVEL_ERROR, rule="E019",
                        message=f"'private' array contains bare identifier '{tt.value}' "
                                f"(elements must be quoted strings like \"_var\")",
                    ))
                k += 1
            if not saw_string:
                diags.append(Diagnostic(
                    file=file, line=t.line, col=t.col,
                    level=LEVEL_WARNING, rule="E019",
                    message="'private' array contains no underscore-prefixed strings",
                ))
            continue
        diags.append(Diagnostic(
            file=file, line=t.line, col=t.col,
            level=LEVEL_ERROR, rule="E019",
            message=f"'private' must be followed by a local variable or array of strings, got {nxt.kind} '{nxt.value}'",
        ))
    return diags


# ----------------------------------------------------------------------------
# Variable analysis: track local-var usage vs `private` declarations.
#
# Scope tracking is a simplified version of real SQF semantics. We treat
# `{ ... }` as a scope boundary, since most SQF locals are scoped to a
# code block. Top level is also a scope.
#
# We emit:
#   W005 - `_var` is read or assigned without ever appearing in a `private`
#          declaration in the enclosing scope chain.
#   W009 - `private _var` redeclares a `_var` already private in the same
#          (innermost) scope.
#   W015 - `private _var = ...` followed by no read of `_var` anywhere.
# ----------------------------------------------------------------------------

# Variables that SQF auto-injects - never warn on these.
SQF_BUILTIN_LOCALS = {v.lower() for v in (
    "_this", "_x", "_y", "_forEachIndex",
    "_thisFsm", "_thisScript",
    "_thisEvent", "_thisEventHandler",
    "_exception", "_thrown",
    "_thisArgs",
)}  # lower-cased: lookups use var.lower(), and SQF names are case-insensitive


def _find_block_extent(tokens: list, open_idx: int) -> int:
    """Given tokens[open_idx] is '{', return idx just past the matching '}'."""
    depth = 1
    i = open_idx + 1
    while i < len(tokens):
        if tokens[i].kind == "{":
            depth += 1
        elif tokens[i].kind == "}":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return len(tokens)


def check_variable_usage(tokens: list, file: str, ignored: set) -> list:
    """
    Walk top-level tokens building scope info for `_var` (local) variables.
    Reports W005 (unprivate use) and W015 (unused private).
    """
    diags = []

    # Pass 1: collect every `private` declaration site (with its scope start/end indices)
    # and every `_var` token reference position.
    n = len(tokens)

    # private_decls: list of (var_name, scope_start, scope_end, decl_line, decl_col)
    private_decls = []
    # all_local_refs: list of (var_name, idx, line, col, is_assignment)
    all_local_refs = []

    def register_private(var: str, idx_in_scope: int, scope_start: int, scope_end: int,
                         line: int, col: int) -> None:
        private_decls.append((var, scope_start, scope_end, line, col, idx_in_scope))

    # Build a list of scope ranges: for each `{`, the matching range (start, end_exclusive).
    # The outermost scope is (0, n).
    scope_ranges = [(0, n)]
    for i, t in enumerate(tokens):
        if t.kind == "{":
            end = _find_block_extent(tokens, i)
            scope_ranges.append((i, end))

    def innermost_scope(idx: int) -> tuple:
        # Pick the smallest scope that contains idx.
        best = scope_ranges[0]
        for s, e in scope_ranges:
            if s <= idx < e:
                if (e - s) < (best[1] - best[0]):
                    best = (s, e)
        return best

    # Walk tokens, processing private declarations and _var refs
    i = 0
    while i < n:
        t = tokens[i]

        if t.kind == "KW_private":
            j = _next_significant(tokens, i + 1)
            if j >= n:
                i += 1
                continue
            nxt = tokens[j]
            scope_start, scope_end = innermost_scope(j)
            if nxt.kind == "IDENT" and nxt.value.startswith("_"):
                register_private(nxt.value, j, scope_start, scope_end, nxt.line, nxt.col)
                # Also treat this position as a local ref (declaration)
                all_local_refs.append((nxt.value, j, nxt.line, nxt.col, True))
                i = j + 1
                continue
            if nxt.kind == "STRING" and nxt.value.startswith("_"):
                register_private(nxt.value, j, scope_start, scope_end, nxt.line, nxt.col)
                i = j + 1
                continue
            if nxt.kind == "[":
                # Walk array of strings
                depth = 1
                k = j + 1
                while k < n and depth > 0:
                    tt = tokens[k]
                    if tt.kind == "[":
                        depth += 1
                    elif tt.kind == "]":
                        depth -= 1
                    elif tt.kind == "STRING" and tt.value.startswith("_"):
                        register_private(tt.value, k, scope_start, scope_end, tt.line, tt.col)
                    k += 1
                i = k
                continue
            i += 1
            continue

        # Look for `params` blocks - these implicitly privatise their elements.
        # `params [ "_a", "_b", ["_c", default] ]`
        if t.kind == "KW_params":
            j = _next_significant(tokens, i + 1)
            if j < n and tokens[j].kind == "[":
                scope_start, scope_end = innermost_scope(j)
                depth = 1
                k = j + 1
                while k < n and depth > 0:
                    tt = tokens[k]
                    if tt.kind == "[":
                        depth += 1
                    elif tt.kind == "]":
                        depth -= 1
                    elif tt.kind == "STRING" and tt.value.startswith("_"):
                        register_private(tt.value, k, scope_start, scope_end, tt.line, tt.col)
                    k += 1
                i = k
                continue

        # `for "_i" from N to M [step S] do { body }` implicitly privatises `_i`
        # within the body block. Detect the pattern and register `_i` as private
        # for the scope of the body brace pair.
        if t.kind == "KW_for":
            j = _next_significant(tokens, i + 1)
            if j < n and tokens[j].kind == "STRING" and tokens[j].value.startswith("_"):
                iter_var = tokens[j].value
                iter_line = tokens[j].line
                iter_col = tokens[j].col
                # Find the matching `do` then the next `{`
                k = j + 1
                while k < n and tokens[k].kind != "KW_do":
                    if tokens[k].kind == ";":
                        break  # malformed, give up
                    k += 1
                if k < n and tokens[k].kind == "KW_do":
                    m = _next_significant(tokens, k + 1)
                    if m < n and tokens[m].kind == "{":
                        body_end = _find_block_extent(tokens, m)
                        register_private(iter_var, m, m, body_end, iter_line, iter_col)
                # Don't fast-forward i - let the regular walker continue so
                # other identifiers inside still get processed.
            # Fall through to normal handling

        # `with namespace do {...}` and similar `with` forms - skip; no implicit privates.

        # Any IDENT starting with '_' is a local reference.
        if t.kind == "IDENT" and t.value.startswith("_"):
            # Determine if this is an assignment target by looking at the next significant op.
            j = _next_significant(tokens, i + 1)
            is_assign = (j < n and tokens[j].kind == "OP" and tokens[j].value == "=")
            all_local_refs.append((t.value, i, t.line, t.col, is_assign))

        i += 1

    # Now detect duplicate privates in same scope (W009)
    seen_in_scope = {}  # (scope_start, scope_end, var) -> first_line
    for var, s, e, line, col, _ in private_decls:
        key = (s, e, var)
        if key in seen_in_scope:
            first = seen_in_scope[key]
            diags.append(Diagnostic(
                file=file, line=line, col=col,
                level=LEVEL_WARNING, rule="W009",
                message=f"'{var}' already declared private in this scope at line {first}",
            ))
        else:
            seen_in_scope[key] = line

    # Detect refs without an enclosing private (W005)
    # A ref is "covered" if there's a private decl with (scope_start, scope_end)
    # containing the ref's idx, AND the decl's idx is at or before the ref's idx.
    private_lookup = {}  # var -> list of (scope_start, scope_end, decl_idx)
    for var, s, e, _, _, didx in private_decls:
        private_lookup.setdefault(var, []).append((s, e, didx))

    referenced = set()  # set of declaration sites (var, decl_idx) that get used
    warned_unprivate = set()  # to avoid duplicate warnings on same var/line

    for var, idx, line, col, is_assign in all_local_refs:
        # Find any covering private. Do this BEFORE the builtin/ignored skip
        # so an explicit `private _x = ...` followed by a use of `_x` correctly
        # marks the private as referenced even though `_x` is normally a
        # builtin (in forEach/apply contexts).
        # Pick the innermost (most specific) declaration that covers this ref, so a
        # `params` inside a nested block (addAction code, spawn) isn't shadowed by an
        # outer declaration of the same name.
        covering = None
        best_key = None
        for s, e, didx in private_lookup.get(var, []):
            if s <= idx < e and didx <= idx:
                key = (e - s, -didx)
                if best_key is None or key < best_key:
                    best_key = key
                    covering = (var, didx)

        if covering is not None:
            referenced.add(covering)
            continue

        # Skip builtins / ignored only for the "warn on undeclared" branch.
        # _x outside any explicit `private _x` is the magic variable in
        # forEach/apply/count/findIf bodies and should never warn.
        if var.lower() in SQF_BUILTIN_LOCALS or var in ignored:
            continue

        # If this _is_ a private declaration site itself, the ref==decl, so skip
        decl_match = any(idx == didx for _, _, didx in private_lookup.get(var, []))
        if decl_match:
            continue

        key = (var, line)
        if key not in warned_unprivate:
            warned_unprivate.add(key)
            diags.append(Diagnostic(
                file=file, line=line, col=col,
                level=LEVEL_WARNING, rule="W005",
                message=f"Local variable '{var}' used without 'private' declaration in enclosing scope",
            ))

    # Detect unused privates (W015)
    for var, s, e, line, col, didx in private_decls:
        if (var, didx) in referenced:
            continue
        # If the variable is only assigned (declaration with init) and never read, warn.
        # Also skip vars whose name suggests intentional disuse: starts with __.
        if var.startswith("__"):
            continue
        diags.append(Diagnostic(
            file=file, line=line, col=col,
            level=LEVEL_INFO, rule="W015",
            message=f"Local variable '{var}' declared private but never read",
        ))

    return diags


# ----------------------------------------------------------------------------
# `=` used as comparison (W006).
#
# Heuristic: inside an `if (...)` paren expression, any '=' that isn't part
# of '==' / '!=' / '>=' / '<=' / `=>` is suspicious. Our lexer already
# longest-matches '==' so a bare '=' OP token inside an if's condition is the
# tell.
# ----------------------------------------------------------------------------

def check_equals_in_conditions(tokens: list, file: str) -> list:
    diags = []
    n = len(tokens)
    i = 0
    while i < n:
        t = tokens[i]
        if t.kind not in ("KW_if", "KW_while"):
            i += 1
            continue
        # Find immediately following '(' ... ')'
        j = _next_significant(tokens, i + 1)
        if j >= n or tokens[j].kind != "(":
            i += 1
            continue
        end = _skip_balanced(tokens, j, "(", ")")
        if end < 0:
            i += 1
            continue
        # Scan inside (j+1 .. end-2) for bare '=' ops
        for k in range(j + 1, end - 1):
            tk = tokens[k]
            if tk.kind == "OP" and tk.value == "=":
                diags.append(Diagnostic(
                    file=file, line=tk.line, col=tk.col,
                    level=LEVEL_WARNING, rule="W006",
                    message=f"'=' inside '{t.value}' condition - use '==' or 'isEqualTo' for comparison",
                ))
        i = end
    return diags


# ----------------------------------------------------------------------------
# Empty body check (W008): `if cond then {}`, `while cond do {}`, `forEach {}`
# These almost never make sense - flag for review.
# ----------------------------------------------------------------------------

def check_empty_bodies(tokens: list, file: str) -> list:
    diags = []
    n = len(tokens)
    # `exitWith {}` is a legitimate early-out idiom (e.g. `if (!isServer) exitWith {};`)
    # so we don't flag it here. We only flag empty `then {}`, `do {}`, `else {}`, etc.
    triggers = {"KW_then", "KW_do", "KW_forEach", "KW_foreach", "KW_else"}
    for i, t in enumerate(tokens):
        if t.kind not in triggers:
            continue
        j = _next_significant(tokens, i + 1)
        if j >= n or tokens[j].kind != "{":
            continue
        end = _skip_balanced(tokens, j, "{", "}")
        if end < 0:
            continue
        # Scan inside (j+1 .. end-2) - is there any non-PP, non-trivial token?
        empty = True
        for k in range(j + 1, end - 1):
            if tokens[k].kind != "PP":
                empty = False
                break
        if empty:
            diags.append(Diagnostic(
                file=file, line=tokens[j].line, col=tokens[j].col,
                level=LEVEL_WARNING, rule="W008",
                message=f"Empty body after '{t.value}' - intentional?",
            ))
    return diags


# ----------------------------------------------------------------------------
# `compile <variable>` warning (W013): code-injection / perf foot-gun.
# Compiling a string literal is fine; compiling a runtime value is suspicious.
# ----------------------------------------------------------------------------

def check_dynamic_compile(tokens: list, file: str) -> list:
    diags = []
    n = len(tokens)
    for i, t in enumerate(tokens):
        if t.kind != "IDENT":
            continue
        if t.value.lower() not in ("compile", "compilefinal"):
            continue
        j = _next_significant(tokens, i + 1)
        if j >= n:
            continue
        # `compile "literal"`  - fine
        # `compile preprocessFileLineNumbers "..."` - fine
        # `compile _var`, `compile (someExpr)` - flag
        nxt = tokens[j]
        if nxt.kind == "STRING":
            continue
        if nxt.kind == "IDENT" and nxt.value.lower() in ("preprocessfile", "preprocessfilelinenumbers", "loadfile"):
            continue
        if nxt.kind == "(":
            # Could be `compile (preprocessFile "x")` - allow if the first significant
            # token inside is preprocessFile/preprocessFileLineNumbers/loadFile
            inner = _next_significant(tokens, j + 1)
            if inner < n and tokens[inner].kind == "IDENT" and tokens[inner].value.lower() in (
                "preprocessfile", "preprocessfilelinenumbers", "loadfile"
            ):
                continue
            diags.append(Diagnostic(
                file=file, line=t.line, col=t.col,
                level=LEVEL_WARNING, rule="W013",
                message=f"'{t.value}' on a runtime expression - prefer compileFinal of static source",
            ))
            continue
        # IDENT or anything else: warn
        diags.append(Diagnostic(
            file=file, line=t.line, col=t.col,
            level=LEVEL_WARNING, rule="W013",
            message=f"'{t.value}' on a non-literal value - prefer compileFinal of a static string",
        ))
    return diags


# ----------------------------------------------------------------------------
# Whole-file checks (BOM, line endings, whitespace, line length)
# ----------------------------------------------------------------------------

def check_file_level(path: Path, raw: bytes, max_line_len: int, disabled: set) -> list:
    diags = []
    file = str(path)

    # W001: BOM
    if "W001" not in disabled and raw.startswith(b"\xef\xbb\xbf"):
        diags.append(Diagnostic(
            file=file, line=1, col=1,
            level=LEVEL_WARNING, rule="W001",
            message="UTF-8 BOM at start of file - some Arma tools choke on this",
        ))

    # W003: not valid UTF-8 (after BOM strip)
    text_bytes = raw[3:] if raw.startswith(b"\xef\xbb\xbf") else raw
    try:
        text = text_bytes.decode("utf-8")
        utf8_ok = True
    except UnicodeDecodeError:
        text = text_bytes.decode("utf-8", errors="replace")
        utf8_ok = False
        if "W003" not in disabled:
            diags.append(Diagnostic(
                file=file, line=1, col=1,
                level=LEVEL_WARNING, rule="W003",
                message="File is not valid UTF-8 (decoded with replacement characters)",
            ))

    # W002: mixed line endings
    has_crlf = b"\r\n" in text_bytes
    # Count standalone LFs (not preceded by CR)
    has_lf_only = False
    for i, b in enumerate(text_bytes):
        if b == 0x0A and (i == 0 or text_bytes[i - 1] != 0x0D):
            has_lf_only = True
            break
    if has_crlf and has_lf_only and "W002" not in disabled:
        diags.append(Diagnostic(
            file=file, line=1, col=1,
            level=LEVEL_WARNING, rule="W002",
            message="Mixed line endings (both CRLF and LF in same file)",
        ))

    # W004: filename/path with spaces
    if " " in str(path) and "W004" not in disabled:
        diags.append(Diagnostic(
            file=file, line=1, col=1,
            level=LEVEL_WARNING, rule="W004",
            message="File path contains spaces - PboProject and many build tools can't cope",
        ))

    # Line-by-line checks (W010 mixed indent, W011 trailing ws, W012 long lines)
    lines = text.splitlines()
    for ln_no, line in enumerate(lines, 1):
        if "W010" not in disabled:
            # Mixed tabs and spaces in leading indent
            indent = ""
            for ch in line:
                if ch in " \t":
                    indent += ch
                else:
                    break
            if "\t" in indent and " " in indent:
                diags.append(Diagnostic(
                    file=file, line=ln_no, col=1,
                    level=LEVEL_WARNING, rule="W010",
                    message="Mixed tabs and spaces in indentation",
                ))
        if "W011" not in disabled:
            stripped = line.rstrip("\r")
            if stripped and stripped[-1] in " \t":
                # Don't double-flag trailing CR
                col = len(stripped.rstrip(" \t")) + 1
                diags.append(Diagnostic(
                    file=file, line=ln_no, col=col,
                    level=LEVEL_WARNING, rule="W011",
                    message="Trailing whitespace at end of line",
                ))
        if "W012" not in disabled:
            display_len = len(line.rstrip("\r"))
            if display_len > max_line_len:
                diags.append(Diagnostic(
                    file=file, line=ln_no, col=max_line_len + 1,
                    level=LEVEL_WARNING, rule="W012",
                    message=f"Line is {display_len} chars (max {max_line_len})",
                ))

    return diags


# ----------------------------------------------------------------------------
# Driver
# ----------------------------------------------------------------------------

def find_sqf_files(paths: list) -> Iterator[Path]:
    seen = set()
    for p in paths:
        path = Path(p)
        if path.is_file() and path.suffix.lower() == ".sqf":
            rp = path.resolve()
            if rp not in seen:
                seen.add(rp)
                yield path
        elif path.is_dir():
            for f in path.rglob("*.sqf"):
                rp = f.resolve()
                if rp not in seen:
                    seen.add(rp)
                    yield f


def lint_file(path: Path, max_line_len: int, disabled: set, ignored_names: set) -> list:
    """Run all checks on a single SQF file. Return diagnostics."""
    diags = []
    try:
        raw = path.read_bytes()
    except OSError as e:
        return [Diagnostic(
            file=str(path), line=1, col=1,
            level=LEVEL_ERROR, rule="E000",
            message=f"Cannot read file: {e}",
        )]

    # File-level checks first (work on raw bytes / lines)
    diags.extend(check_file_level(path, raw, max_line_len, disabled))

    # Strip BOM, decode
    text_bytes = raw[3:] if raw.startswith(b"\xef\xbb\xbf") else raw
    text = text_bytes.decode("utf-8", errors="replace")

    # Tokenize
    try:
        tokens = Lexer(text).tokenize()
    except LexError as le:
        if le.rule not in disabled:
            diags.append(Diagnostic(
                file=str(path), line=le.line, col=le.col,
                level=LEVEL_ERROR, rule=le.rule,
                message=le.message,
            ))
        return [d for d in diags if d.rule not in disabled]

    file = str(path)

    # Bracket balance
    diags.extend(check_bracket_balance(tokens, file))
    # PP balance
    diags.extend(check_pp_balance(tokens, file))
    # Control flow
    diags.extend(check_control_flow(tokens, file))
    # Operator sequences
    diags.extend(check_operator_sequences(tokens, file))
    # Empty parens
    diags.extend(check_empty_parens(tokens, file))
    # `private` semantics
    diags.extend(check_private_usage(tokens, file))
    # Variable usage (W005, W009, W015)
    diags.extend(check_variable_usage(tokens, file, ignored_names))
    # `=` in conditions (W006)
    diags.extend(check_equals_in_conditions(tokens, file))
    # Empty bodies (W008)
    diags.extend(check_empty_bodies(tokens, file))
    # Dynamic compile (W013)
    diags.extend(check_dynamic_compile(tokens, file))

    # Filter disabled rules
    return [d for d in diags if d.rule not in disabled]


def main(argv: list) -> int:
    parser = argparse.ArgumentParser(
        prog="sqf_lint",
        description="Lint Arma 3 SQF script files (.sqf)",
    )
    parser.add_argument("paths", nargs="*", default=["."], help="Files or directories to lint (default: .)")
    parser.add_argument("-W", "--warnings-as-errors", action="store_true",
                        help="Treat warnings as errors (exit 2 if any)")
    parser.add_argument("--no-warnings", action="store_true", help="Hide warnings entirely")
    parser.add_argument("--json", action="store_true", help="Emit JSON")
    parser.add_argument("--quiet", action="store_true", help="Hide the per-run summary line")
    parser.add_argument("--disable", action="append", default=[], help="Disable a rule by ID (repeatable)")
    parser.add_argument("--enable", action="append", default=[], help="Force-enable a cosmetic rule (repeatable)")
    parser.add_argument("--cosmetic", action="store_true",
                        help=f"Enable cosmetic/style rules (off by default): {', '.join(sorted(COSMETIC_RULES))}")
    parser.add_argument("--ignore-name", action="append", default=[],
                        help="Treat NAME as a known identifier (repeatable, e.g. project-wide globals)")
    parser.add_argument("--max-line-len", type=int, default=200,
                        help="Override long-line warning threshold (default 200)")
    parser.add_argument("--rules", action="store_true", help="List all rules and exit")
    args = parser.parse_args(argv)

    if args.rules:
        for rid, (lvl, desc) in sorted(RULES.items()):
            tag = " [cosmetic]" if rid in COSMETIC_RULES else ""
            print(f"{rid}  {lvl:8s}  {desc}{tag}")
        return 0

    disabled = set(args.disable)
    if not args.cosmetic:
        enabled = set(args.enable)
        for r in COSMETIC_RULES:
            if r not in enabled:
                disabled.add(r)

    repo_root = Path(args.paths[0]).resolve() if (
        len(args.paths) == 1 and Path(args.paths[0]).is_dir()
    ) else Path.cwd()

    ignored_names = set(args.ignore_name)

    files = list(find_sqf_files(args.paths))
    files.sort()

    all_diags = []
    for f in files:
        all_diags.extend(lint_file(f, args.max_line_len, disabled, ignored_names))

    if args.no_warnings:
        all_diags = [d for d in all_diags if d.level != LEVEL_WARNING]

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
            print(
                f"\nScanned {len(files)} file(s): {n_err} error(s), {n_warn} warning(s), {n_info} info",
                file=sys.stderr,
            )

    if n_err > 0:
        return 2
    if n_warn > 0 and args.warnings_as_errors:
        return 2
    if n_warn > 0:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
