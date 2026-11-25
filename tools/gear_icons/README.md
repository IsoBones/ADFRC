# Gear icon tool

Renders arsenal/inventory pictures (`picture = ...`) for ADFRC gear and weapons straight from the MLOD models in the build folder, then converts them to PAA and points each class at its own icon.

Covers headgear, NVGs, facewear, vests, uniforms, backpacks, weapons, weapon attachments and magazines. Icons have a transparent background.

- Gear is 256x256. Like the vanilla icons, items are angled slightly to the right and seen from slightly above. Uniforms are framed shoulders to mid-thigh with the arms down.
- Weapons are 512x256, a straight side-on view of the left side with the muzzle pointing left, like the vanilla and existing ADFRC weapon pictures. The weapon's first compatible magazine is drawn in its magazine slot when that magazine has its own (MLOD) model; vanilla magazine models are binarised and can't be read, so those weapons are drawn without one.
- Attachments and magazines are 256x256, mostly side-on and turned slightly toward the camera.
- Weapon presets (classes with `LinkedItems`) aren't dumped, so they keep their parent's picture.

## What you need

- **The build folder** (P: drive) with the unbinarised `.p3d` models and textures. The tool reads MLOD p3ds only: classes that use a vanilla (binarised) model, like the retextured BI backpacks, are skipped.
- **Python 3.8+** ([python.org](https://www.python.org/downloads/), tick "Add python.exe to PATH" when installing) with `numpy` and `Pillow`. The tool offers to install those on first run.
- **Blender 4.x or 5.x.** Nothing extra is needed inside Blender. The tool finds it on PATH, in `Program Files\Blender Foundation\`, or in Steam. Otherwise point the window at `blender.exe`, pass `--blender "C:\path\to\blender.exe"`, or set the `BLENDER` environment variable.
- **Arma 3 Tools** (ImageToPAA), found through Steam, for the last step only. Otherwise point the window at `ImageToPAA.exe` or pass `--imagetopaa`.

## The easy way: the window

Double-click `GearIcons.bat`. It opens the Gear Icon Maker window; work through it top to bottom:

1. **Setup.** Check the build folder (your P: drive) and that Blender and ImageToPAA were found. **Detect tools** looks again; **Browse...** sets them by hand. These are remembered for next time.
2. **Dump the gear list.** Press **Copy dump script**. In game: load ADFRC, open any mission in Eden, press Play (singleplayer), open the debug console, paste, press **LOCAL EXEC**. Back in the window, press **Paste dump from clipboard**.
3. **Find classes.** Pick the gear types and press **Find classes**. The list shows every class that needs an icon and why. Untick anything you don't want.
4. **Render ticked.** Renders them in Blender (about 8 seconds each, the window stays usable and **Cancel** stops it). Rendered rows turn green; click a row to see its icon on the right, or open the contact sheet.
5. **Put ticked icons into the mod.** Shows what will change in the log, asks once, then writes the PAAs and edits the configs. Configs are backed up to `temp\gear_icons\config_backup\` first.

Then lint, pack, check the icons in the Arsenal, and commit the new `.paa` files with the edited configs.

## Command line

`GearIcons.bat` with arguments runs the command line version instead (or use `py -3 gear_icons.py`). The build folder is taken from `%ADFRC_ROOT%` if you set it, otherwise `P:\`, otherwise the current folder. Working files go to `<build folder>\temp\gear_icons\`.

1. **Dump the gear from the game.** Load ADFRC, open any mission in Eden and play it in singleplayer. Paste all of `dump_gear.sqf` into the debug console and press **LOCAL EXEC**. One line per ADFRC gear, weapon, attachment and magazine class is copied to the clipboard. Paste it into `<build folder>\temp\gear_icons\gear_dump.txt`.
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
- `--only-file list.txt`: same as `--only`, one classname per line.
- `--categories vest uniform`: limit by type (`headgear nvg glasses vest uniform backpack weapon attachment magazine`).

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
| `GearIcons.bat` | Windows launcher: no arguments opens the window, with arguments runs the command line (finds Python and the build folder, installs numpy/Pillow if missing) |
| `GearIcons.ps1` | The Gear Icon Maker window (Windows Forms); runs `gear_icons.py` for every step |
| `gear_icons.py` | The command line: select, render (launches Blender), fit, contact sheet, apply |
| `dump_gear.sqf` | In-game dump of every ADFRC gear class: model, hidden selections, textures, picture |
| `export_meshes.py` | Reads each p3d's first resolution LOD and its textures into `stage\`, plus the weapon's direction (memory points) and magazine |
| `render_icons.py` | Runs inside Blender (bpy + numpy only) and renders each look to `raw\` |
| `apply_icons.py` | ImageToPAA conversion and config edits |
| `paa.py` | PAA decoder (DXT1/DXT5 + LZO) used to read textures |

Camera angles per type are in `VIEWS` at the top of `render_icons.py`, as (azimuth, elevation) in degrees. For weapons, attachments and magazines the angle is relative to the weapon's left side: the forward direction comes from the `usti hlavne` / `konec hlavne` memory points, or p3d -X (how ADFRC weapons are built) when they're missing. Icon sizes per type are in `SIZES` in `gear_icons.py`.
