"""Step 2: export the meshes + textures the icon renderer needs, from MLOD p3ds in the build folder.

Reads <work>/need.json (rows picked by `gear_icons.py select`), writes <work>/stage/:
  looks.json                      look id -> {model, category, classes, mesh, textures}
  mesh_<model hash>.npz           Res 1 LOD: points, triangles, uvs, per-tri texture + selections
  tex_<hash>.png                  textures (largest mip <= 1024)
Stdlib + numpy + Pillow.
"""
import hashlib, json, os, struct, sys
import numpy as np
from PIL import Image
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from paa import read_paa

ROOT = os.getcwd()   # build folder (P: drive root); set by main()
OUT = None

_dircache = {}
def resolve(p, ext=None):
    q = p.strip().lstrip('\\').replace('\\', '/')
    if ext and not q.lower().endswith(ext):
        q += ext
    cur = ROOT
    for part in q.split('/'):
        if cur not in _dircache:
            try:
                _dircache[cur] = {x.lower(): x for x in os.listdir(cur)}
            except OSError:
                _dircache[cur] = {}
        m = _dircache[cur].get(part.lower())
        if not m:
            return None
        cur = os.path.join(cur, m)
    return cur

def _cstr(d, p):
    e = d.index(b'\0', p)
    return d[p:e], e + 1

def read_first_res_lod(path):
    d = open(path, 'rb').read()
    assert d[:4] == b'MLOD', 'not MLOD'
    n = struct.unpack_from('<I', d, 8)[0]; p = 12
    best, muzzle = None, None
    for _ in range(n):
        assert d[p:p + 4] == b'P3DM'
        npts, nnorm, nf = struct.unpack_from('<3I', d, p + 12); p += 28
        pts = np.frombuffer(d, np.float32, npts * 4, p).reshape(npts, 4)[:, :3].copy(); p += npts * 16
        p += nnorm * 12
        faces = []
        for i in range(nf):
            nv = struct.unpack_from('<I', d, p)[0]
            vs = [struct.unpack_from('<IIff', d, p + 4 + k * 16) for k in range(nv)]
            p += 72
            tex, p = _cstr(d, p); mat, p = _cstr(d, p)
            faces.append((vs, tex.decode('latin1')))
        assert d[p:p + 4] == b'TAGG'; p += 4
        sels = {}
        while True:
            p += 1
            name, p = _cstr(d, p)
            ln = struct.unpack_from('<I', d, p)[0]; p += 4
            data = d[p:p + ln]; p += ln
            if name == b'#EndOfFile#':
                break
            if not name.startswith(b'#'):
                sels[name.decode('latin1').lower()] = (np.frombuffer(data[npts:npts + nf], np.uint8) > 0,
                                                        np.frombuffer(data[:npts], np.uint8).copy())
        res = struct.unpack_from('<f', d, p)[0]; p += 4
        if res < 1000 and faces and (best is None or res < best[0]):
            best = (res, pts, faces, sels)
        elif 0.9e15 < res < 1.1e15 and 'usti hlavne' in sels and 'konec hlavne' in sels:
            # memory LOD: barrel end -> muzzle gives the weapon's forward direction
            a, b = pts[sels['konec hlavne'][1] > 0], pts[sels['usti hlavne'][1] > 0]
            if len(a) and len(b):
                muzzle = (b.mean(0) - a.mean(0))
    return best + (muzzle,) if best else None

def proxy_frames(pts, faces, sels, key):
    """Origin and axes (x, y, z) of each proxy triangle whose name contains key, in p3d space.
    The proxy triangle's first point is the origin, the second sets +Y and the third +Z."""
    out = []
    for name, (fsel, _) in sels.items():
        if not (name.startswith('proxy:') and key in name):
            continue
        for fi in np.nonzero(fsel)[0]:
            vs = faces[fi][0]
            if len(vs) < 3:
                continue
            o, a, b = (pts[vs[i][0]].astype(np.float64) for i in range(3))
            y = (a - o) / (np.linalg.norm(a - o) or 1.0)
            z = (b - o) / (np.linalg.norm(b - o) or 1.0)
            out.append((o, np.cross(y, z), y, z))
    return out

def h(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()[:12]

def main(root, work):
    global ROOT, OUT
    ROOT, OUT = os.path.abspath(root), os.path.join(work, 'stage')
    _dircache.clear()
    rows = json.load(open(os.path.join(work, 'need.json')))
    os.makedirs(OUT, exist_ok=True)
    looks, done_mesh, done_tex = {}, {}, {}
    def tex_png(t):
        t = t.strip()
        if not t:
            return None
        if t.startswith('#'):
            return t  # procedural, renderer handles color(...)
        if t in done_tex:
            return done_tex[t]
        base = t[:-4] if t.lower()[-4:] in ('.tga', '.png', '.jpg') else t
        f = resolve(base, '.paa')
        name = None
        if f:
            try:
                w, hh, img = read_paa(f, 1024)
                name = 'tex_%s.png' % h(t.lower())
                Image.fromarray(img, 'RGBA').save(os.path.join(OUT, name))
            except Exception as e:
                print('  texture fail', t, e)
        else:
            print('  texture missing', t)
        done_tex[t] = name
        return name
    for r in rows:
        cls, cat, model, sels, texs = r[1], r[2], r[3], r[4], r[5]
        mag = r[9].strip() if cat == 'weapon' and len(r) > 9 else ''
        if mag.lower().lstrip('\\').startswith('a3\\'):
            mag = ''   # vanilla magazine model, binarised: draw the weapon without it
        if model.lower().lstrip('\\').startswith('a3\\'):
            continue  # vanilla model, binarised: not exported
        sel_list = [s.lower() for s in sels.split(';')] if sels else []
        tex_list = texs.split(';') if texs else []
        key = '|'.join([model.lower(), ';'.join(sel_list), ';'.join(t.lower() for t in tex_list), mag.lower()])
        lid = h(key)
        if lid in looks:
            looks[lid]['classes'].append(cls); continue
        mk = h(model.lower() + '|' + mag.lower())
        if mk not in done_mesh:
            f = resolve(model, '.p3d')
            if not f:
                print('model missing', model); done_mesh[mk] = None; continue
            lod = read_first_res_lod(f)
            if lod is None:
                print('no res LOD', model); done_mesh[mk] = None; continue
            res, pts, faces, selmap, muzzle = lod
            if mag:
                mf = resolve(mag, '.p3d')
                mlod = read_first_res_lod(mf) if mf else None
                slots = proxy_frames(pts, faces, selmap, 'magazineslot')
                if mlod and slots:
                    o, x, y, z = slots[0]
                    mp = mlod[1].astype(np.float64)
                    mp = o + np.outer(mp[:, 0], x) + np.outer(mp[:, 1], y) + np.outer(mp[:, 2], z)
                    base = len(pts)
                    pts = np.concatenate([pts, mp.astype(np.float32)])
                    faces = faces + [([(v[0] + base,) + tuple(v[1:]) for v in vs], t) for vs, t in mlod[2]]
                    nf_add = len(mlod[2])
                    selmap = {k: (np.concatenate([f, np.zeros(nf_add, bool)]), np.concatenate([w, np.zeros(len(mp), np.uint8)]))
                              for k, (f, w) in selmap.items()}
                    print('  + magazine', mag)
                else:
                    print('  magazine not drawn (%s)' % ('no magazine slot proxy' if mf and mlod else 'model missing'), mag)
            tris, uvs, ftex, fidx = [], [], [], []
            texnames = sorted({t for _, t in faces})
            for fi, (vs, t) in enumerate(faces):
                order = [(0, 1, 2)] if len(vs) == 3 else [(0, 1, 2), (0, 2, 3)]
                for a, b, c in order:
                    tris.append((vs[a][0], vs[b][0], vs[c][0]))
                    uvs.append(((vs[a][2], 1 - vs[a][3]), (vs[b][2], 1 - vs[b][3]), (vs[c][2], 1 - vs[c][3])))
                    ftex.append(texnames.index(t)); fidx.append(fi)
            fidx = np.array(fidx, np.int32)
            names = sorted(selmap)
            selbits = np.stack([selmap[n][0][fidx] for n in names], 1) if names else np.zeros((len(fidx), 0), bool)
            # raw per-point selection weight bytes, only for full bodies (used to pose the arms down)
            body = any(n in selmap for n in ('leftfoot', 'rightfoot'))
            pw = np.stack([selmap[n][1] for n in names], 1) if (names and body) else np.zeros((len(pts), 0), np.uint8)
            # p3d (x right, y up, z fwd, left-handed) -> blender (x, z, y)
            P = pts[:, [0, 2, 1]].astype(np.float32)
            # forward direction in blender axes; ADFRC weapons and attachments point along p3d -x
            fwd = muzzle[[0, 2, 1]] if muzzle is not None else np.array([-1.0, 0.0, 0.0])
            np.savez_compressed(os.path.join(OUT, 'mesh_%s.npz' % mk), P=P, T=np.array(tris, np.int32),
                                UV=np.array(uvs, np.float32), FT=np.array(ftex, np.int16), SB=selbits, PW=pw,
                                FWD=fwd.astype(np.float32))
            done_mesh[mk] = {'file': 'mesh_%s.npz' % mk, 'textures': texnames, 'sels': names, 'res': res}
            print('mesh', model, 'res', res, len(tris), 'tris')
        m = done_mesh[mk]
        if not m:
            continue
        # per-face texture after hiddenSelections: listed selection without a texture (or "") is hidden
        overrides = []
        for i, s in enumerate(sel_list):
            t = tex_list[i] if i < len(tex_list) else ''
            overrides.append([s, tex_png(t) if t.strip() else None])
        looks[lid] = {'model': model, 'category': cat, 'classes': [cls], 'mesh': m['file'],
                      'mesh_textures': [tex_png(t) for t in m['textures']], 'mesh_sels': m['sels'],
                      'overrides': overrides}
    json.dump(looks, open(os.path.join(OUT, 'looks.json'), 'w'), indent=1)
    print(len(looks), 'looks exported to', OUT)

if __name__ == '__main__':
    sys.exit('Run this through gear_icons.py (see README.md).')
