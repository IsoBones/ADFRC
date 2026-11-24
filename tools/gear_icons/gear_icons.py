"""ADFRC gear icon tool: renders arsenal/inventory pictures for gear and weapons from the MLOD p3ds.

Run from the build folder (the P: drive root), or pass --root. Steps:

  select   read the in-game dump (dump_gear.sqf), pick classes that need an icon -> need.json
  export   read their p3ds + textures from the build folder               -> stage/
  render   render each look in Blender (headless)                         -> raw/
  fit      crop and fit to 256x256 (weapons 512x256)                      -> icons/ + contact_sheet.png
  apply    convert to PAA (ImageToPAA) and set picture= in the configs (dry run without --apply)
  all      select, export, render, fit (stops before apply so you can check the contact sheet)

Everything goes in <root>/temp/gear_icons unless --work is given. See README.md.
"""
import argparse, collections, glob, json, os, shutil, subprocess, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

GEAR = ('headgear', 'nvg', 'glasses', 'vest', 'uniform', 'backpack', 'weapon', 'attachment', 'magazine')
SIZE, MARGIN = 256, 0.06
# icon size (w, h) per category; weapons are 2:1 like the vanilla and existing ADFRC weapon pictures
SIZES = {'weapon': (512, 256)}

def icon_size(category):
    return SIZES.get(category, (SIZE, SIZE))


# ---------------------------------------------------------------- select
def read_dump(path):
    rows = []
    for line in open(path, encoding='utf-8', errors='replace'):
        line = line.strip()
        i = line.find('ADFI|')          # tolerate RPT timestamps / quotes around the line
        if i < 0:
            continue
        r = line[i:].rstrip('"').split('|')
        if len(r) >= 7:
            rows.append((r + [''] * 10)[:10])
    return rows

def resolve(root, p):
    """Case-insensitive lookup of an Arma path under root. Returns the real path or None."""
    cur = root
    for part in p.strip().lstrip('\\').replace('\\', '/').split('/'):
        try:
            names = {x.lower(): x for x in os.listdir(cur)}
        except OSError:
            return None
        if part.lower() not in names:
            return None
        cur = os.path.join(cur, names[part.lower()])
    return cur

def cmd_select(a):
    rows = read_dump(a.dump)
    if not rows:
        sys.exit('No ADFI| lines in %s. Paste the dump_gear.sqf output into it first.' % a.dump)
    cats = set(a.categories)
    only = {c.lower() for c in a.only}
    use = collections.Counter(r[6].lstrip('\\').lower() for r in rows if r[6].strip())
    need, why = [], collections.Counter()
    for r in rows:
        cls, cat, pic = r[1], r[2], r[6].strip()
        if cat not in cats:
            continue
        if only and cls.lower() not in only:
            continue
        p = pic.lstrip('\\').lower()
        if a.all or only:
            reason = 'forced'
        elif not p:
            reason = 'no picture'
        elif p.startswith('a3\\'):
            reason = 'vanilla picture'
        elif not resolve(a.root, pic):
            reason = 'picture file missing'
        elif use[p] > 1 and not a.no_shared:
            reason = 'picture shared with %d classes' % use[p]
        else:
            continue
        need.append(r); why[reason.split(' with ')[0]] += 1
    os.makedirs(a.work, exist_ok=True)
    json.dump(need, open(os.path.join(a.work, 'need.json'), 'w'), indent=0)
    print('%d of %d dumped classes need an icon:' % (len(need), len(rows)))
    for k, v in why.most_common():
        print('  %-22s %d' % (k, v))


# ---------------------------------------------------------------- export
def cmd_export(a):
    import export_meshes
    export_meshes.main(a.root, a.work)


# ---------------------------------------------------------------- render
def find_blender(override):
    if override:
        return override
    if os.environ.get('BLENDER'):
        return os.environ['BLENDER']
    exe = shutil.which('blender')
    if exe:
        return exe
    cands = []
    for pf in filter(None, [os.environ.get('ProgramFiles'), os.environ.get('ProgramFiles(x86)')]):
        cands += glob.glob(os.path.join(pf, 'Blender Foundation', '*', 'blender.exe'))
    for steam in [r'C:\Program Files (x86)\Steam', r'C:\Program Files\Steam']:
        cands += glob.glob(os.path.join(steam, 'steamapps', 'common', 'Blender', 'blender.exe'))
    cands.sort(key=lambda c: [int(x) if x.isdigit() else x for x in c.replace('.', ' ').split()])
    return cands[-1] if cands else None

def cmd_render(a):
    stage, raw = os.path.join(a.work, 'stage'), os.path.join(a.work, 'raw')
    if not os.path.exists(os.path.join(stage, 'looks.json')):
        sys.exit('Nothing exported yet. Run the export step first.')
    os.makedirs(raw, exist_ok=True)
    script = os.path.join(HERE, 'render_icons.py')
    exe = find_blender(a.blender)
    if exe:
        cmd = [exe, '-b', '--factory-startup', '-P', script, '--', stage, raw] + a.only
    else:
        try:
            import bpy  # noqa: F401  (pip install bpy also works)
            cmd = [sys.executable, script, stage, raw] + a.only
        except ImportError:
            sys.exit('Blender not found. Install Blender 4.x or 5.x, or pass --blender "C:\\path\\to\\blender.exe".')
    print('rendering with', cmd[0])
    r = subprocess.run(cmd)
    if r.returncode:
        sys.exit('Blender exited with code %d' % r.returncode)


# ---------------------------------------------------------------- fit
def fit(png_in, png_out, category=''):
    """Crop to the object and fit it in SIZE with a margin. Thin bits (antennas, straps) don't count
    toward the size, so they can run off the edge instead of shrinking the item. Uniforms are framed
    shoulders to mid-thigh, like the existing G3 icons."""
    import numpy as np
    from PIL import Image
    im = Image.open(png_in).convert('RGBA')
    alpha = np.array(im)[:, :, 3] > 8
    if not alpha.any():
        return False
    rows, cols = alpha.sum(1), alpha.sum(0)
    thin = 0.18 if category == 'backpack' else 0.02 if category == 'weapon' else 0.06   # packs: ignore antennas and cables; weapons: keep thin barrels
    rk = rows >= max(2, rows.max() * thin)
    ck = cols >= max(2, cols.max() * thin)
    y0, y1 = np.nonzero(rk)[0][[0, -1]]
    x0, x1 = np.nonzero(ck)[0][[0, -1]]
    if category == 'uniform':
        y1 = y0 + int((y1 - y0) * 0.62)
        xs = np.nonzero(alpha[y0:y1 + 1].any(0))[0]
        x0, x1 = xs[0], xs[-1]
    W, H = icon_size(category)
    w, h = x1 - x0 + 1, y1 - y0 + 1
    s = min(W * (1 - 2 * MARGIN) / w, H * (1 - 2 * MARGIN) / h)
    cx, cy = (x0 + x1) / 2, (y0 + y1) / 2
    scaled = im.resize((max(1, round(im.size[0] * s)), max(1, round(im.size[1] * s))), Image.LANCZOS)
    out = Image.new('RGBA', (W, H), (0, 0, 0, 0))
    ox, oy = round(W / 2 - cx * s), round(H / 2 - cy * s)
    if category == 'uniform':
        oy = round(H * MARGIN - y0 * s)
    out.paste(scaled, (ox, oy), scaled)   # negative offsets just clip
    out.save(png_out)
    return True

def contact_sheet(looks, icons, out, cols=10):
    from PIL import Image, ImageDraw
    items = [(lid, lk) for lid, lk in looks.items() if os.path.exists(os.path.join(icons, lid + '.png'))]
    if not items:
        return
    cell, lab = 160, 28
    cols = min(cols, len(items))
    rows = (len(items) + cols - 1) // cols
    sheet = Image.new('RGBA', (cols * cell, rows * (cell + lab)), (70, 72, 76, 255))
    d = ImageDraw.Draw(sheet)
    for i, (lid, lk) in enumerate(items):
        x, y = (i % cols) * cell, (i // cols) * (cell + lab)
        ic = Image.open(os.path.join(icons, lid + '.png'))
        k = (cell - 8) / max(ic.size)
        ic = ic.resize((max(1, round(ic.size[0] * k)), max(1, round(ic.size[1] * k))), Image.LANCZOS)
        sheet.alpha_composite(ic, (x + 4 + (cell - 8 - ic.size[0]) // 2, y + 4 + (cell - 8 - ic.size[1]) // 2))
        name = lk['classes'][0] + (' +%d' % (len(lk['classes']) - 1) if len(lk['classes']) > 1 else '')
        d.text((x + 4, y + cell), name[:26], fill=(235, 235, 235, 255))
        d.text((x + 4, y + cell + 13), name[26:52], fill=(235, 235, 235, 255))
    sheet.save(out)

def cmd_fit(a):
    looks = json.load(open(os.path.join(a.work, 'stage', 'looks.json')))
    raw, icons = os.path.join(a.work, 'raw'), os.path.join(a.work, 'icons')
    os.makedirs(icons, exist_ok=True)
    ok = empty = 0
    for lid, lk in looks.items():
        src = os.path.join(raw, lid + '.png')
        if not os.path.exists(src):
            continue
        if fit(src, os.path.join(icons, lid + '.png'), lk['category']):
            ok += 1
        else:
            empty += 1; print('  EMPTY render:', lk['classes'][0])
    sheet = os.path.join(a.work, 'contact_sheet.png')
    contact_sheet(looks, icons, sheet)
    print('%d icons in %s (%d empty). Check %s before applying.' % (ok, icons, empty, sheet))


# ---------------------------------------------------------------- apply
def cmd_apply(a):
    import apply_icons
    addons = a.addons or sorted(d for d in os.listdir(a.root)
                                if d.lower().startswith('adf') and os.path.isdir(os.path.join(a.root, d)))
    apply_icons.main(a.root, a.work, addons, apply=a.apply, imagetopaa=a.imagetopaa)


def cmd_all(a):
    for step in (cmd_select, cmd_export, cmd_render, cmd_fit):
        print('==', step.__name__[4:])
        step(a)
    print('== done. Look at contact_sheet.png, then run the apply step (dry run first).')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('step', choices=['select', 'export', 'render', 'fit', 'apply', 'all'])
    ap.add_argument('--root', default=os.getcwd(), help='build folder / P: drive root (default: current folder)')
    ap.add_argument('--work', help='working folder (default: <root>/temp/gear_icons)')
    ap.add_argument('--dump', help='dump file from dump_gear.sqf (default: <work>/gear_dump.txt)')
    ap.add_argument('--categories', nargs='+', default=list(GEAR), choices=GEAR, help='gear types to do (default: all)')
    ap.add_argument('--only', nargs='+', default=[], metavar='CLASS', help='only these classnames (forces them)')
    ap.add_argument('--all', action='store_true', help='select: redo every class, even ones with their own icon')
    ap.add_argument('--no-shared', action='store_true', help='select: skip classes whose picture is shared, not their own')
    ap.add_argument('--blender', help='path to blender.exe (default: search PATH, Program Files, Steam)')
    ap.add_argument('--addons', nargs='+', help='apply: top-level addon folders to search for configs (default: ADF*)')
    ap.add_argument('--imagetopaa', help='apply: path to ImageToPAA.exe (default: find Arma 3 Tools via Steam)')
    ap.add_argument('--apply', action='store_true', help='apply: really write PAAs and edit configs')
    a = ap.parse_args()
    a.root = os.path.abspath(a.root)
    a.work = os.path.abspath(a.work or os.path.join(a.root, 'temp', 'gear_icons'))
    a.dump = a.dump or os.path.join(a.work, 'gear_dump.txt')
    {'select': cmd_select, 'export': cmd_export, 'render': cmd_render, 'fit': cmd_fit,
     'apply': cmd_apply, 'all': cmd_all}[a.step](a)

if __name__ == '__main__':
    main()
