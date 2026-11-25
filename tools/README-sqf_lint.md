# sqf_lint

A linter for Arma 3 SQF script files (`.sqf`).

Built as a structural linter, not a command-database linter. It validates the *shape* of your code (balanced brackets, well-formed `if/then`, proper `private` semantics) rather than checking command names against a database. Modern commands like `setCruiseControl` and modern syntax like the `#` array-select operator just work — the linter never tries to know what every command is, so it can't go stale.

Single Python file, stdlib only, Python 3.8+. No pip install, no node, no docker, no rust toolchain.

## Quick start

Drop `sqf_lint.py` into `tools/` (alongside `arma_lint.py` if you have it) and run it:

```bash
python3 tools/sqf_lint.py addons
```

Default exit codes:
- `0` clean
- `1` warnings only
- `2` errors

## What it catches

### Errors (these break things)

| Rule | What |
|------|------|
| E001-E003 | Unbalanced braces / brackets / parens |
| E004      | Unterminated string literal |
| E005      | Unterminated block comment |
| E006      | Unbalanced `#if`/`#endif` directives |
| E007      | Malformed preprocessor directive |
| E008      | Stray closing bracket with no matching opener |
| E010      | `if` condition not followed by `then` or `exitWith` |
| E011      | `while` condition not followed by `do` |
| E012      | `for` loop missing `do` clause |
| E013      | `switch` block not followed by `do` |
| E014      | `case` / `default` outside a switch block |
| E015      | `else` without preceding `then` |
| E016      | Trailing operator at end of expression |
| E017      | Two consecutive operators with no operand between |
| E018      | Empty parentheses where expression expected |
| E019      | `private` not followed by a variable or array of strings |

### Warnings (likely problems)

| Rule | What |
|------|------|
| W001 | UTF-8 BOM at start of file |
| W002 | Mixed line endings (CRLF + LF in same file) |
| W003 | File is not valid UTF-8 |
| W004 | File path contains spaces |
| W005 | Local variable used without `private` declaration |
| W006 | `=` used inside `if`/`while` condition (probably typo for `==`) |
| W008 | Empty `then`/`do`/`forEach` body |
| W009 | `private` re-declares variable already private in same scope |
| W013 | `compile`/`compileFinal` on a non-literal value |
| W015 | Local variable declared private but never read |

### Cosmetic (off by default, enable with `--cosmetic`)

| Rule | What |
|------|------|
| W010 | Mixed tabs and spaces for indentation |
| W011 | Trailing whitespace at end of line |
| W012 | Line exceeds max length |
| W016 | Magic number in code |

## Why no command database?

LordGolias/sqf and SkaceKamen's tools both maintain a list of every SQF command and their signatures. Both went stale: when BI added `setCruiseControl` in 2022 it produced false positives until someone updated the database. Eight years later, neither database reflects current SQF.

This linter dodges that trap entirely. Unknown identifiers are just unknown identifiers — they could be commands, BIS_fnc_*, mod-defined functions, or macros from `#define`. The linter focuses on what it can verify without that knowledge: brackets, control flow keywords, scoping of `_locals`. The cost is no completeness check on individual commands. The benefit is that the linter doesn't need maintenance every time BI ships an update.

## SQF features explicitly supported

Things that broke older linters but pass cleanly here:

```sqf
// The '#' array-select operator
private _first = _array#0;
private _last = _array#(count _array - 1);

// Modern commands (any post-2018 command)
_vehicle setCruiseControl [60, false];

// Modern params with type-array defaults
params [
    ["_target", objNull, [objNull]],
    ["_caller", objNull, [objNull]],
    ["_actionData", []]
];

// for "_i" implicit privatisation
for "_i" from 0 to 10 do {
    hint format ["%1", _i];
};

// _x in apply / forEach / count / findIf bodies
private _names = units player apply { name _x };
private _alive = { alive _x } count units player;

// try / catch with _exception
try { throw "bad" } catch { hint format ["err: %1", _exception]; };

// Macros (CBA-style)
LOG("starting up");
GVAR(playerData) = _data;
```

## Useful flags

```
-W, --warnings-as-errors   Treat warnings as errors
--no-warnings              Hide warnings entirely
--cosmetic                 Enable W010/W011/W012/W016 (style nits)
--json                     Emit JSON for CI / IDE integration
--quiet                    Hide the per-run summary line
--disable RULE             Disable a rule by ID (repeatable)
--enable RULE              Force-enable a cosmetic rule
--ignore-name NAME         Treat NAME as a known global (repeatable)
--max-line-len N           Long-line warning threshold (default 200)
--rules                    List all rules and exit
```

## Examples

Lint everything:
```bash
python3 tools/sqf_lint.py addons
```

Lint a single file:
```bash
python3 tools/sqf_lint.py addons/adf_air/adfrc_blackhawk/scripts/init_base.sqf
```

Strict mode for CI (any warning fails the build):
```bash
python3 tools/sqf_lint.py addons -W
```

JSON for piping into your editor:
```bash
python3 tools/sqf_lint.py addons --json | jq '.diagnostics[] | select(.level == "error")'
```

Disable a noisy rule for one run:
```bash
python3 tools/sqf_lint.py addons --disable W005
```

Ignore project-wide globals so they don't trigger W007:
```bash
python3 tools/sqf_lint.py addons --ignore-name ADFRC_globalState --ignore-name ADFRC_init
```

## CI integration

A ready-made GitHub Actions workflow lives at `.github/workflows/sqflint.yml`. It runs on PRs that touch any `.sqf` under `addons/`. Mirrors the structure of the existing `configlint.yml`.

Workflow uses `--no-warnings` by default to avoid drowning the CI log in pre-existing warnings. Once those are cleaned up, swap for `-W` to start blocking PRs that introduce regressions.

## Pre-commit hook

`.pre-commit-config.yaml.example` is included if you want commits blocked locally on lint errors. Rename to `.pre-commit-config.yaml` and run `pre-commit install`. If you already use the config linter pre-commit, add this one as a second hook in the same file — they don't conflict.

## What it doesn't do

- **Type inference.** Doesn't know that `vehicle player` returns an Object so `(vehicle player) + 1` would be flagged. That's a much bigger lift involving a real interpreter.
- **Command-signature validation.** Doesn't check that `setVelocity` takes an array of three numbers. By design — see "Why no command database" above.
- **Macro expansion.** Preprocessor lines are skipped, not expanded. A typo inside a macro body won't be caught until that macro is expanded by Arma's compiler.
- **Cross-file scope tracking.** Variables defined in file A and read in file B aren't tracked. Each file is linted independently. Acceptable trade-off given how SQF locals work in practice.
- **Dead-code detection.** Doesn't flag unreachable branches.

## Adding new rules

The rule registry at the top of `sqf_lint.py` is the canonical list. To add a new check:

1. Add an entry to `RULES` with a stable ID and default level.
2. Write a `check_*` function that takes `(tokens, file)` and returns a list of `Diagnostic`.
3. Call it from `lint_file()`.

Same pattern as the config linter, copy/paste any existing check as a template.

## Comparison with other tools

| Tool | Maintained? | Modern syntax | Setup cost | Coverage |
|------|-------------|---------------|------------|----------|
| `arma-actions/sqflint` (LordGolias) | Dead since 2018 | No | Low | Good if pinned to 2018 |
| SkaceKamen sqflint (Java) | Slow | Partial | Medium | Good |
| sqf-analyzer (Rust) | Active | Yes | Medium (cargo build) | Best |
| HEMTT SQF inspector | Active | Yes | High (HEMTT migration) | Best |
| **sqf_lint.py (this)** | Trivially updateable | Yes (no DB to stale) | Zero | Structural only |

This linter is positioned as the zero-friction option. If you eventually migrate to HEMTT, its SQF inspector slots in for free with proper variable tracking and you get type-aware coverage. Until then, this catches the structural mistakes that account for the bulk of real-world SQF errors and integrates without any toolchain overhead.
