#!/usr/bin/env python3
"""
fix_bad_faces.py - clean MLOD p3ds that crash the Blender Arma 3 Object Builder importer.

Fixes, in every LOD:
  - faces that use the same point twice (degenerate): quads with 3 distinct points become
    triangles, anything with fewer than 3 distinct points is removed
  - zero-length vertex normals: replaced with the normal of a face that uses them
  - extra UV sets beyond the two Arma uses (set 0 and 1); Blender allows 8 UV maps per mesh
Named selections, #UVSet# data and other per-face data are kept in step with the faces.
The original is copied once to temp\\shadow_backups (same place the Shadow LOD Maker uses).

  py fix_bad_faces.py ADF_Gear\\adfrc_helmets\\Opscore_af_cover.p3d
  py fix_bad_faces.py --dry-run ADF_Gear ADF_Gear_2
Stdlib only. Needs make_shadow_lods.py next to it.
"""
import argparse, math, os, shutil, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_shadow_lods as m

def face_normal(L, f):
    pts = [L.points[v[0]] for v in f['v'][:3]]
    ux, uy, uz = (pts[1][i] - pts[0][i] for i in range(3))
    vx, vy, vz = (pts[2][i] - pts[0][i] for i in range(3))
    n = (uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx)
    l = math.sqrt(sum(c * c for c in n))
    return [c / l for c in n] if l > 1e-12 else [0.0, 0.0, 1.0]

def clean_lod(L):
    npts, nf = len(L.points), len(L.faces)
    keep = []       # (old face index, list of kept vertex positions within the face)
    fixed = removed = 0
    for fi, f in enumerate(L.faces):
        pis = [v[0] for v in f['v']]
        if len(set(pis)) == len(pis):
            keep.append((fi, list(range(len(pis))))); continue
        pos, seen = [], set()
        for k, pi in enumerate(pis):
            if pi not in seen:
                seen.add(pi); pos.append(k)
        if len(pos) >= 3:
            keep.append((fi, pos[:3] if len(pos) == 3 else pos)); fixed += 1
        else:
            removed += 1
    zero = [i for i, n in enumerate(L.normals) if n[0] * n[0] + n[1] * n[1] + n[2] * n[2] < 1e-12]
    extra_uv = [t for t in L.tags if t[1] == b'#UVSet#' and struct.unpack_from('<I', t[2], 0)[0] >= 2]
    if extra_uv:
        L.tags = [t for t in L.tags if not (t[1] == b'#UVSet#' and struct.unpack_from('<I', t[2], 0)[0] >= 2)]
    if not fixed and not removed and not zero:
        return 0, 0, 0, len(extra_uv)
    # faces
    new_faces = []
    for fi, pos in keep:
        f = L.faces[fi]
        new_faces.append({'v': [f['v'][k] for k in pos], 'flags': f['flags'], 'tex': f['tex'], 'mat': f['mat']})
    # zero normals -> normal of the first face using them
    if zero:
        zs = set(zero); done = set()
        for f in new_faces:
            for v in f['v']:
                if v[1] in zs and v[1] not in done:
                    L.normals[v[1]] = face_normal(L, f); done.add(v[1])
        for i in zs - done:
            L.normals[i] = [0.0, 1.0, 0.0]
    # tags that carry per-face data
    new_tags = []
    for active, name, data in L.tags:
        if name == b'#UVSet#':
            set_id = data[:4]; p = 4; per_face = []
            for f in L.faces:
                nv = len(f['v']); per_face.append(data[p:p + nv * 8]); p += nv * 8
            out = bytearray(set_id)
            for fi, pos in keep:
                blk = per_face[fi]
                for k in pos: out += blk[k * 8:k * 8 + 8]
            data = bytes(out)
        elif len(data) == npts + nf and (not name.startswith(b'#') or name in (b'#Selected#', b'#Hidden#', b'#Lock#')):
            data = data[:npts] + bytes(data[npts + fi] for fi, _ in keep)
        new_tags.append([active, name, data])
    L.faces = new_faces; L.tags = new_tags
    return fixed, removed, len(zero), len(extra_uv)

def process(path, dry):
    try:
        ver, lods = m.read_p3d(path)
    except Exception as e:
        return 'skip  %s: %s' % (path, e)
    report = []
    for L in lods:
        f, r, z, u = clean_lod(L)
        if f or r or z or u:
            report.append('LOD %g: %d faces fixed, %d removed, %d zero normals, %d extra UV sets dropped' % (L.res, f, r, z, u))
    if not report:
        return 'clean %s' % path
    if not dry:
        bdir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'temp', 'shadow_backups')
        os.makedirs(bdir, exist_ok=True)
        bak = os.path.join(bdir, m.backup_name(path))
        if not os.path.exists(bak):
            shutil.copy2(path, bak)
        m.write_p3d(path, ver, lods)
        m.read_p3d(path)
    return 'fixed %s: %s' % (path, '; '.join(report)) if not dry else 'would fix %s: %s' % (path, '; '.join(report))

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('paths', nargs='+'); ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args(); files = []
    for p in a.paths:
        if os.path.isdir(p):
            for dp, dn, fn in os.walk(p):
                if any(x in dp.replace('\\', '/').split('/') for x in ('temp', '_to_delete')): continue
                files += [os.path.join(dp, f) for f in fn if f.lower().endswith('.p3d')]
        else:
            files.append(p)
    for f in sorted(files):
        print(process(f, a.dry_run)); sys.stdout.flush()

if __name__ == '__main__':
    main()
