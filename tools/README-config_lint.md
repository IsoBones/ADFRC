# arma_lint

A linter for Arma 3 mod config files (`.cpp`, `.hpp`, `.cfg`).

Targets BI's flavour of "C++" config syntax, not actual C++. Catches the stuff that breaks PboProject packing and the stuff that throws errors when Arma loads your addon.

Single Python file, stdlib only, Python 3.8+. No pip install, no node, no docker.

## Quick start

Drop `arma_lint.py` somewhere in your repo (a `tools/` folder works) and run it:

```bash
python3 tools/arma_lint.py addons
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
| E006      | Unbalanced `#if` / `#endif` |
| E007      | Array assignment missing `[]` (e.g. `magazines = {...}` instead of `magazines[] = {...}`) |
| E008      | Class definition missing trailing `;` |
| E009      | Forward decl with parent (`class A : B;` is invalid) |
| E010      | Missing `;` after assignment |
| E011      | Reserved keyword as class name |
| E012      | Duplicate class definition in same scope, or the same forward declaration twice |
| E013      | `#include` target not found |
| E014      | Empty assignment (`name = ;`) |
| E015      | Class name missing or invalid |
| E018      | Unquoted localization string (`$STR_FOO` without quotes) |
| E019      | Unquoted multi-word value (`author = ADF Re-Cut;` should be `author = "ADF Re-Cut";`) |
| E020      | Duplicate property in the same class (`forceHideDriver=0;` twice). Rapify fails with "duplicated token or class". `x[] += {...}` appends are fine |

### Warnings (likely problems)

| Rule | What |
|------|------|
| W001 | UTF-8 BOM at start of file |
| W002 | Mixed CRLF/LF line endings |
| W003 | Filename or path contains spaces |
| W004 | Filename contains non-ASCII chars |
| W005 | PBO-relative path too long |
| W006-W008 | CfgPatches subclass missing `requiredAddons[]` / `units[]` / `weapons[]` |
| W011 | Empty class body without parent (probably forgot the `;` for forward decl) |
| W012 | `==` used in config (configs use `=`) |
| W013 | Path uses `\\` in string literal |
| W014 | Addon-root `config.cpp` has no `CfgPatches` block |
| W015 | `#include` uses forward slashes |
| W017 | `#include` path case differs from real filename — works on Windows, breaks PboProject on Linux/Mac/CI |
| E016 | Inheritance from class never declared anywhere in the project (downgraded to warning because BI base classes won't be visible) |

### Cosmetic (off by default, enable with `--cosmetic`)

| Rule | What |
|------|------|
| W009 | Mixed tabs and spaces for indentation |
| W010 | Trailing whitespace at end of line |

## Useful flags

```
-W, --warnings-as-errors   Treat warnings as errors
--no-warnings              Hide warnings entirely
--cosmetic                 Enable W009/W010 (whitespace nits)
--json                     Emit JSON for CI / IDE integration
--include-dir DIR          Extra root for resolving #include paths (repeatable)
--max-path-len N           Override path-length warning threshold (default 100)
--quiet                    Hide the per-run summary line
--disable RULE             Disable a rule by ID (repeatable)
--enable RULE              Force-enable a rule by ID (repeatable, useful with --cosmetic)
--rules                    List all rules and exit
```

## Examples

Lint everything:
```bash
python3 tools/arma_lint.py addons
```

Lint a single file:
```bash
python3 tools/arma_lint.py addons/adf_air/adfrc_apache/cfgVehicles.hpp
```

Strict mode for CI (any warning fails the build):
```bash
python3 tools/arma_lint.py addons -W
```

JSON for piping into your editor:
```bash
python3 tools/arma_lint.py addons --json | jq '.diagnostics[] | select(.level == "error")'
```

Disable a noisy rule for one run:
```bash
python3 tools/arma_lint.py addons --disable E016
```

## CI integration

A ready-made GitHub Actions workflow lives at `.github/workflows/configlint.yml`. It runs on PRs that touch any `.cpp` / `.hpp` / `.cfg` under `addons/`. Mirrors the structure of the existing `sqflint.yml`.

## Pre-commit hook

`.pre-commit-config.yaml.example` is included if you want commits blocked locally on lint errors. Rename to `.pre-commit-config.yaml` and run `pre-commit install`.

## Arma-specific patterns it understands

These all pass cleanly:

```cpp
// Array append/remove via inheritance
magazines[] += {"ACE_HuntIR_M203"};
items[] -= {"junk"};

// Arithmetic in scalar values (flag combination, FOV math)
lockDetectionSystem = CM_Lock_Radar + CM_Lock_Laser;
initFov = (30 / 120);

// Volume curve expressions with brackets
volume = camPos * (rotorThrust factor [0.7, 0.9]);

// Inner-class override pattern
class MyChopper : Heli_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret { /* ... */ };
    };
};

// Empty body with parent (Ace marker class)
class arifle_AUG_F: arifle_AUG_base_F {};

// Macro invocations from basicDefines_A3.hpp
mag_xx(SmokeShell, 2);
bag_xx(B_Parachute, 2);

// Class names starting with digits (or pure digits)
class 150Rnd_762x51_Box;
class 417 : Default { /* ... */ };
```

## What it doesn't do

- **Macro expansion.** It skips preprocessor lines rather than expanding them. A typo inside a macro body won't be caught until that macro is expanded by the real compiler. Reasonable trade-off given how complex full preprocessing gets.
- **Cross-PBO inheritance validation.** It can't know about classes defined in `@CBA_A3`, `@ace`, base game `A3_Data_F`, etc. E016 is downgraded to a warning for this reason and the project-wide class set covers most common cases.
- **HEMTT-level config validation.** That's a much bigger lift involving a real config interpreter. This is the lighter-weight check before that.
- **Model checks.** Doesn't validate `.p3d` references, texture paths, or animation source counts. Just the config syntax itself.

## Adding rules

The rule registry is at the top of `arma_lint.py` in the `RULES` dict. Each rule is just `(default_level, description)`. The actual checks are scattered across the lexer, parser, and post-parse functions — pick the right layer:

- **Lexer**: character-level concerns (BOM detection happens earlier as a file-level check)
- **Parser**: structural concerns (missing semicolons, duplicate classes, etc.)
- **Post-parse**: anything that needs the whole file or whole project (CfgPatches field validation, #include resolution, project-wide class lookup)

## License

Same as the rest of ADF: Re-Cut. Pick whichever of APL-SA / repo license applies.
