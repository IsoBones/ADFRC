# Shadow LOD tools

Small stdlib-only Python tools for MLOD gear p3ds (vests, helmets, NODs, facewear, packs). Python 3 on PATH (`py` launcher or `python`), nothing to install.

They edit MLOD p3ds, so they're for the model source (private repo / build folder), not for anything in this repo directly. Copy this folder's files into the build folder root, or run them from here and point them at the build folder. Backups go to `temp\shadow_backups` next to the scripts, once per file, never overwritten.

## ShadowLODs.bat / ShadowLODs.ps1

One-click window for `make_shadow_lods.py`. Browse to a folder, Scan, tick models (red = no shadow yet), set options, Make Shadow LODs. "Restore originals" puts the backed-up files back.

Settings that have worked on our gear: Source 3, Low 5, first person on, shrink 0. Tick "Rebuild" to replace existing shadow LODs.

## make_shadow_lods.py

Builds Shadow Volume 0 (from `--source`, default Res 3) and 10 (from `--low`), plus the 1000/1010 first-person copies, from the resolution LODs:

- proxies, textures and materials stripped, quads split, points welded, junk faces removed
- holes capped so the volume is closed
- parts still leaky after capping (the cause of long shadow streaks) are replaced with their convex hull if they're up to 25 cm, dropped if bigger; inside-out parts are flipped
- every edge sharp; bone selections kept so the shadow follows the body

Every run also tidies the file for pboProject (see `fix_props.py`).

Skipped on purpose:
- **uniforms / full bodies** (anything with foot bones). Generating these breaks them; they use BI's character shadow LODs (from the field dress / BI sample soldier).
- models with no named selections (optic overlays).

```
py -3 make_shadow_lods.py --source 3 --low 5 ADF_Gear ADF_Gear_2
py -3 make_shadow_lods.py --replace --source 3 --low 5 ADF_Gear_2\adfrc_vests\vest_aircrew.p3d
py -3 make_shadow_lods.py --dry-run ADF_Gear          (report only)
py -3 make_shadow_lods.py --info ADF_Gear            (LOD summary per model)
```

## fix_props.py

Cleans named properties so pboProject stops warning/erroring: drops properties with whitespace in the name (`'lodnoshadow '`, `made by`, `<new property>`...), exact duplicates, and adds the empty mass tag an empty Geometry LOD needs ("Geolod has no mass"). `--strip-junk` also cuts res/Geometry LODs down to a short whitelist, for models built on old templates full of typo properties (PSQ-36, facewear). The shadow tool already does the basic clean-up, so this is only for one-offs.

## fix_bad_faces.py

Fixes p3ds that crash the Arma 3 Object Builder Blender importer (`EXCEPTION_ACCESS_VIOLATION` in `mesh_normals_corner_custom_set`): degenerate faces removed or turned into triangles, zero-length normals replaced, unused extra UV sets dropped. Run it before importing a model that crashes Blender.
