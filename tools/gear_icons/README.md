# Gear icon tool

Renders arsenal/inventory pictures (`picture = ...`) for ADFRC gear straight from the MLOD models in the build folder, then converts them to PAA and points each class at its own icon.

Covers headgear, NVGs, facewear, vests, uniforms and backpacks. The icons are 256x256 with a transparent background. Like the vanilla icons, items are angled slightly to the right and seen from slightly above. Uniforms are framed shoulders to mid-thigh with the arms down.

## What you need

- **The build folder** (P: drive) with the unbinarised `.p3d` models and textures. The tool reads MLOD p3ds only: classes that use a vanilla (binarised) model, like the retextured BI backpacks, are skipped.
- **Python 3.8+** with `numpy` and `Pillow`. `GearIcons.bat` installs them on first run.
- **Blender 4.x or 5.x.** Nothing extra is needed inside Blender. The tool finds it on PATH, in `Program Files\Blender Foundation\`, or in Steam. Otherwise pass `--blender "C:\path\to\blender.exe"` or set the `BLENDER` environment variable.
- **Arma 3 Tools** (ImageToPAA), found through Steam, for the last step only. Otherwise pass `--imagetopaa`.

## Running it

Everything runs through `GearIcons.bat` (or `py -3 gear_icons.py`). The build folder is taken from `%ADFRC_ROOT%` if you set it, otherwise `P:\`, otherwise the current folder. Working files go to `<build folder>\temp\gear_icons\`.

1. **Dump the gear from the game.** Load ADFRC, open any mission in Eden and play it in singleplayer. Paste all of `dump_gear.sqf` into the debug console and press **LOCAL EXEC**. One line per ADFRC gear class is copied to the clipboard. Paste it into `<build folder>\temp\gear_icons\gear_dump.txt`.
2. **Render.** Run `GearIcons.bat all`. This picks the classes that need an icon, exports their models, renders them in Blender, fits them to 256x256, and writes `contact_sheet.png` showing every result.
3. **Check** `temp\gear_icons\contact_sheet.png`. To redo or tweak a few items, run `GearIcons.bat all --only <classname> <classname>`.
4. **Apply.** First run `GearIcons.bat apply` for a dry run: it lists every config it would edit and where each icon would go. When that looks right, run `GearIcons.bat apply --apply`.

Each step can be run on its own: `select`, `export`, `render`, `fit`, `apply`.

### Which classes get an icon

By default `select` picks any gear class that has one of these:
- no picture
- a vanilla `\a3\` picture
- a picture path that doesn't exist in the build folder
- a picture shared with other classes (e.g. one generic vest icon for every camo)

You can change that with these options:
- `--no-shared`: leave classes with a shared picture alone.
- `--all`: redo every class.
- `--only A B C`: just those classes, whatever they have now.
- `--categories vest uniform`: limit by gear type.

### What apply changes

- Each icon is saved as `<classname>_ca.paa` in the folder that config file already uses for its pictures. If there isn't one, it goes in `<addon>\icons`.
- The class's own `picture` line is replaced, or a new one is added straight after its opening brace. Line endings (CRLF/LF) are kept.
- Every config is copied to `temp\gear_icons\config_backup\` before its first edit.
- Classes built by macros, with no literal `class X {` in the source, are listed for a manual edit.
- By default the configs searched are every top-level `ADF*` folder in the build folder. Use `--addons` to change that.

New PAAs are Git LFS files, so commit them from your own machine as normal.

## Files

| File | What it does |
| --- | --- |
| `GearIcons.bat` | Windows launcher: finds Python and the build folder, installs numpy/Pillow if missing |
| `gear_icons.py` | The command line: select, render (launches Blender), fit, contact sheet, apply |
| `dump_gear.sqf` | In-game dump of every ADFRC gear class: model, hidden selections, textures, picture |
| `export_meshes.py` | Reads each p3d's first resolution LOD and its textures into `stage\` |
| `render_icons.py` | Runs inside Blender (bpy + numpy only) and renders each look to `raw\` |
| `apply_icons.py` | ImageToPAA conversion and config edits |
| `paa.py` | PAA decoder (DXT1/DXT5 + LZO) used to read textures |

Camera angles per gear type are in `VIEWS` at the top of `render_icons.py`, as (azimuth, elevation) in degrees.

Weapons and attachments aren't supported yet: they need a side-on camera with the muzzle to the left, and that's tracked separately.
