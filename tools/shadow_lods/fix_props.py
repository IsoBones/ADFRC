"""Clean named properties in MLOD p3ds so pboProject stops complaining.

Default (all models):
  - drops #Property# entries whose name has any whitespace in it
    ('lodnoshadow ', ' lodnoshadow', 'made by', '<new property>' etc.)
  - drops exact duplicate properties (same name + value in the same LOD)
  - adds an empty #Mass# tag to an EMPTY Geometry LOD that has none
    (pboProject: "Geolod has no mass" / "mass tagg missing")
--strip-junk:
  - also keeps ONLY the whitelisted properties below (res/view LODs and Geometry),
    for models built off old templates full of typos and info junk (psq36 etc.)

Backups go to <scriptdir>/temp/prop_backups once (never overwritten).
Usage: py -3 fix_props.py [--dry-run] [--strip-junk] file.p3d|folder ...
"""
import sys, os, shutil
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_shadow_lods as m

GEO = 1e13
KEEP_RES = {b'lodnoshadow', b'autocenter', b'prefershadowvolume', b'forcenotalpha', b'sbsource'}
KEEP_GEO = {b'autocenter', b'prefershadowvolume', b'class', b'map', b'damage', b'buoyancy'}
HERE = os.path.dirname(os.path.abspath(__file__))
BK = os.path.join(HERE, 'temp', 'prop_backups')

def pname(t): return t[2][:64].split(b'\0')[0]
def pval(t):  return t[2][64:].split(b'\0')[0]

def fix(path, dry, junk):
    ver, lods = m.read_p3d(path)
    log = []
    for L in lods:
        tag = '%g' % L.res
        seen = set(); out = []
        for t in L.tags:
            if t[1] != b'#Property#':
                out.append(t); continue
            k, v = pname(t), pval(t)
            if any(c in k for c in b' \t'):
                log.append('%s: drop %r=%r (whitespace)' % (tag, k.decode('latin1'), v.decode('latin1'))); continue
            if junk:
                keep = KEEP_GEO if m.near(L.res, GEO) else (KEEP_RES if L.res < 10000 else None)
                if keep is not None and k.lower() not in keep:
                    log.append('%s: drop %r=%r (junk)' % (tag, k.decode('latin1'), v.decode('latin1'))); continue
            if (k.lower(), v) in seen:
                log.append('%s: drop duplicate %r' % (tag, k.decode('latin1'))); continue
            seen.add((k.lower(), v)); out.append(t)
        L.tags = out
        if m.near(L.res, GEO) and not any(t[1] == b'#Mass#' for t in L.tags):
            if L.points:
                log.append('%s: Geometry has %d points but NO mass - set mass in OB/Blender (not auto-fixed)' % (tag, len(L.points)))
            else:
                L.tags.append([1, b'#Mass#', b'']); log.append('%s: added empty #Mass# to empty Geometry LOD' % tag)
    changed = any(not l.endswith('(not auto-fixed)') for l in log)
    print('==', path, '(dry run)' if dry else '')
    for l in log: print('  ' + l)
    if not log: print('  clean')
    if changed and not dry:
        os.makedirs(BK, exist_ok=True)
        try: rel = os.path.relpath(os.path.abspath(path), HERE)
        except ValueError: rel = os.path.abspath(path)
        b = os.path.join(BK, rel.replace(os.sep, '__').replace('/', '__').replace(':', ''))
        if not os.path.exists(b): shutil.copy2(path, b)
        m.write_p3d(path, ver, lods)
        m.read_p3d(path)  # re-read sanity check

def main():
    a = sys.argv[1:]; dry = '--dry-run' in a; junk = '--strip-junk' in a
    paths = [x for x in a if not x.startswith('--')]
    if not paths: print(__doc__); return
    for p in paths:
        if os.path.isdir(p):
            for r, ds, fs in os.walk(p):
                ds[:] = [d for d in ds if d.lower() not in ('temp', '_to_delete')]
                for f in fs:
                    if f.lower().endswith('.p3d'):
                        try: fix(os.path.join(r, f), dry, junk)
                        except Exception as e: print('== %s ERROR %s' % (os.path.join(r, f), e))
        else: fix(p, dry, junk)

if __name__ == '__main__': main()
