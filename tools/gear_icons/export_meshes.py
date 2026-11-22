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
    best = None
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
    return best

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
        if model.lower().lstrip('\\').startswith('a3\\'):
            continue  # vanilla model, binarised: not exported
        sel_list = [s.lower() for s in sels.split(';')] if sels else []
        tex_list = texs.split(';') if texs else []
        key = '|'.join([model.lower(), ';'.join(sel_list), ';'.join(t.lower() for t in tex_list)])
        lid = h(key)
        if lid in looks:
            looks[lid]['classes'].append(cls); continue
        mk = h(model.lower())
        if mk not in done_mesh:
            f = resolve(model, '.p3d')
            if not f:
                print('model missing', model); done_mesh[mk] = None; continue
            lod = read_first_res_lod(f)
            if lod is None:
                print('no res LOD', model); done_mesh[mk] = None; continue
            res, pts, faces, selmap = lod
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
            np.savez_compressed(os.path.join(OUT, 'mesh_%s.npz' % mk), P=P, T=np.array(tris, np.int32),
                                UV=np.array(uvs, np.float32), FT=np.array(ftex, np.int16), SB=selbits, PW=pw)
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
