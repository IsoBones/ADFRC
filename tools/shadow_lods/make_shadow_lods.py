#!/usr/bin/env python3
"""
make_shadow_lods.py - add Shadow Volume LODs to MLOD gear p3ds (vests, helmets, packs).

For each model it copies a chosen resolution LOD and turns it into a shadow volume:
  - proxies removed, textures and materials stripped
  - quads split into triangles
  - duplicate points welded, degenerate and duplicate faces removed
  - open holes capped so the mesh is closed (shadow volumes need a closed mesh)
  - parts still leaky after capping (open / non-manifold / flipped / paper-thin) are what
    throw long streaks across the ground: ones up to --hull-max (0.25 m) are replaced by
    their convex hull, bigger ones are dropped; inside-out parts are flipped
  - every edge marked sharp
  - named selections (bone weights) kept, so the shadow follows the body
It writes Shadow Volume 0 and a Shadow Volume 1000 copy for first person (as vanilla
vests and helmets do). Lower-detail Shadow 10 / 1010 are made from
--low if given. Vanilla gear layout: Res LODs, [View Pilot], Shadow 0/10, Geometry, Shadow 1000/1010.

Usage (Windows, from the build folder):
  py make_shadow_lods.py ADF_Gear_2\\adfrc_vests\\vest_aircrew.p3d
  py make_shadow_lods.py --source 3 --low 5 ADF_Gear_2\\adfrc_vests        (every p3d in a folder)
  py make_shadow_lods.py --dry-run ADF_Gear ADF_Gear_2                     (report only)
Options:
  --source N     resolution LOD to copy for Shadow 0 (default 3; nearest existing is used)
  --low N        resolution LOD to copy for Shadow 10/1010 (default: none)
  --no-firstperson  don't add the Shadow 1000/1010 first-person copies
  --shrink M     pull the shadow mesh M metres inward along its normals (e.g. 0.002) if the
                 vest shows dark speckles/self-shadowing on its own surface
  --replace      rebuild shadow LODs that already exist (default: skip those models)
  --bad-parts hull|drop|keep   what to do with leaky parts (default hull, see above)
  --hull-max M   largest leaky part in metres that gets a hull instead of being dropped
  --dry-run      report what would happen, write nothing
The original of every changed file is copied once to temp\\shadow_backups next to this script
(never overwritten), so nothing extra lands in the addon folders.
Every run also tidies the file for pboProject (same as fix_props.py): named properties with
whitespace in the name and duplicates are removed, and an empty Geometry LOD gets the empty
mass tag pboProject wants ("Geolod has no mass").
Skipped on purpose: uniforms / full bodies (foot bones), which keep BI's character shadow LODs,
and models with no named selections (optic overlays).
Stdlib only.
"""
import argparse, math, os, shutil, struct, sys
from collections import defaultdict

# ----------------------------------------------------------------- MLOD io
def _cstr(d, p):
    e = d.index(b'\0', p)
    return d[p:e], e + 1

class Lod:
    def __init__(self):
        self.res = 0.0; self.flags = 0
        self.points = []   # [x,y,z,flag]
        self.normals = []  # [x,y,z]
        self.faces = []    # dict(v=[(pi,ni,u,v)...], flags, tex, mat)
        self.tags = []     # [(active, name(bytes), data(bytes))] excluding #EndOfFile#
        self.major = 0x1c; self.minor = 0x100

def read_p3d(path):
    d = open(path, 'rb').read()
    if d[:4] != b'MLOD':
        raise ValueError('not an MLOD p3d (binarised?)')
    ver, n = struct.unpack_from('<II', d, 4); p = 12; lods = []
    for _ in range(n):
        L = Lod()
        assert d[p:p+4] == b'P3DM'
        L.major, L.minor, npts, nnorm, nf, L.flags = struct.unpack_from('<6I', d, p + 4); p += 28
        for i in range(npts):
            L.points.append(list(struct.unpack_from('<3fI', d, p))); p += 16
        for i in range(nnorm):
            L.normals.append(list(struct.unpack_from('<3f', d, p))); p += 12
        for i in range(nf):
            nv = struct.unpack_from('<I', d, p)[0]
            vs = [struct.unpack_from('<IIff', d, p + 4 + k * 16) for k in range(4)]
            fl = struct.unpack_from('<I', d, p + 68)[0]; p += 72
            tex, p = _cstr(d, p); mat, p = _cstr(d, p)
            L.faces.append({'v': [tuple(x) for x in vs[:nv]], 'flags': fl, 'tex': tex, 'mat': mat})
        assert d[p:p+4] == b'TAGG'; p += 4
        while True:
            active = d[p]; p += 1
            name, p = _cstr(d, p)
            ln = struct.unpack_from('<I', d, p)[0]; p += 4
            data = d[p:p+ln]; p += ln
            if name == b'#EndOfFile#': break
            L.tags.append([active, name, data])
        L.res = struct.unpack_from('<f', d, p)[0]; p += 4
        lods.append(L)
    if p != len(d):
        raise ValueError('trailing bytes after last LOD')
    return ver, lods

def write_p3d(path, ver, lods):
    out = bytearray(b'MLOD' + struct.pack('<II', ver, len(lods)))
    for L in lods:
        out += b'P3DM' + struct.pack('<6I', L.major, L.minor, len(L.points), len(L.normals), len(L.faces), L.flags)
        for pt in L.points: out += struct.pack('<3fI', *pt)
        for n in L.normals: out += struct.pack('<3f', *n)
        for f in L.faces:
            vs = list(f['v']) + [(0, 0, 0.0, 0.0)] * (4 - len(f['v']))
            out += struct.pack('<I', len(f['v']))
            for v in vs: out += struct.pack('<IIff', *v)
            out += struct.pack('<I', f['flags']) + f['tex'] + b'\0' + f['mat'] + b'\0'
        out += b'TAGG'
        for active, name, data in L.tags:
            out += bytes([active]) + name + b'\0' + struct.pack('<I', len(data)) + data
        out += b'\x01#EndOfFile#\0' + struct.pack('<I', 0)
        out += struct.pack('<f', L.res)
    open(path, 'wb').write(bytes(out))

# ----------------------------------------------------------------- helpers
SHADOW0, SHADOW10, SHADOW1000, SHADOW1010 = 10000.0, 10010.0, 11000.0, 11010.0
VIEWPILOT, GEOMETRY = 1100.0, 1e13

def is_res(r): return r < 1000.0
def near(a, b): return abs(a - b) <= max(abs(b) * 1e-4, 1e-3)
def is_shadow(r): return 10000.0 <= r < 20000.0

def selections(L):
    return [t for t in L.tags if not t[1].startswith(b'#')]

def get_prop(L, key):
    for t in L.tags:
        if t[1] == b'#Property#' and t[2][:64].split(b'\0')[0].lower() == key.lower().encode():
            return t[2][64:].split(b'\0')[0].decode('latin1')
    return None

def set_prop(L, key, value):
    data = key.encode('latin1').ljust(64, b'\0') + value.encode('latin1').ljust(64, b'\0')
    for t in L.tags:
        if t[1] == b'#Property#' and t[2][:64].split(b'\0')[0].lower() == key.lower().encode():
            t[2] = data; return
    L.tags.append([1, b'#Property#', data])

def del_prop(L, key):
    L.tags = [t for t in L.tags if not (t[1] == b'#Property#' and t[2][:64].split(b'\0')[0].lower() == key.lower().encode())]

def pick_res(lods, want):
    res = sorted([L for L in lods if is_res(L.res) and L.faces], key=lambda L: L.res)
    if not res: return None
    exact = [L for L in res if near(L.res, want)]
    if exact: return exact[0]
    below = [L for L in res if L.res < want]
    return below[-1] if below else res[0]

# ----------------------------------------------------------------- shadow builder
# ----------------------------------------------------------------- convex hull (for leaky parts)
def convex_hull(idx, P, eps=1e-6):
    """3D convex hull of points P[i] for i in idx (incremental, visible region grown by
    flood-fill from the most-visible face so the horizon is always one clean loop).
    Returns triangles [a,b,c] wound outward (right-handed) or None if degenerate."""
    pts = list(dict.fromkeys(idx))
    if len(pts) < 4: return None
    def sub(a, b): return (P[a][0]-P[b][0], P[a][1]-P[b][1], P[a][2]-P[b][2])
    def cross(u, v): return (u[1]*v[2]-u[2]*v[1], u[2]*v[0]-u[0]*v[2], u[0]*v[1]-u[1]*v[0])
    def dot(u, v): return u[0]*v[0]+u[1]*v[1]+u[2]*v[2]
    def ln(u): return math.sqrt(dot(u, u))
    p0 = pts[0]
    p1 = max(pts, key=lambda i: ln(sub(i, p0)))
    if ln(sub(p1, p0)) < eps: return None
    d01 = sub(p1, p0)
    p2 = max(pts, key=lambda i: ln(cross(d01, sub(i, p0))))
    nrm = cross(d01, sub(p2, p0))
    if ln(nrm) < eps * eps: return None
    p3 = max(pts, key=lambda i: abs(dot(nrm, sub(i, p0))))
    if abs(dot(nrm, sub(p3, p0))) / ln(nrm) < eps: return None
    cen = [sum(P[i][k] for i in (p0, p1, p2, p3)) / 4 for k in range(3)]
    faces = {}; emap = {}; nid = [0]
    def add(a, b, c):
        n = cross(sub(b, a), sub(c, a)); l = ln(n)
        if l == 0: l = 1e-30
        n = (n[0]/l, n[1]/l, n[2]/l)
        k = nid[0]; nid[0] += 1
        faces[k] = (a, b, c, n)
        for e in ((a, b), (b, c), (c, a)): emap[e] = k
    def rem(k):
        a, b, c, _ = faces.pop(k)
        for e in ((a, b), (b, c), (c, a)):
            if emap.get(e) == k: del emap[e]
    for a, b, c in ((p0, p1, p2), (p0, p1, p3), (p0, p2, p3), (p1, p2, p3)):
        n = cross(sub(b, a), sub(c, a))
        if dot(n, (cen[0]-P[a][0], cen[1]-P[a][1], cen[2]-P[a][2])) > 0: b, c = c, b
        add(a, b, c)
    rest = [p for p in pts if p not in (p0, p1, p2, p3)]
    rest.sort(key=lambda i: -((P[i][0]-cen[0])**2 + (P[i][1]-cen[1])**2 + (P[i][2]-cen[2])**2))
    for p in rest:
        best, bd = None, eps
        for k, (a, b, c, n) in faces.items():
            d = dot(n, sub(p, a))
            if d > bd: best, bd = k, d
        if best is None: continue
        vis = {best}; stack = [best]
        while stack:
            a, b, c, _ = faces[stack.pop()]
            for u, v in ((a, b), (b, c), (c, a)):
                k = emap.get((v, u))
                if k is None or k in vis: continue
                fa, fb, fc, fn = faces[k]
                if dot(fn, sub(p, fa)) > eps:
                    vis.add(k); stack.append(k)
        horizon = []
        for k in vis:
            a, b, c, _ = faces[k]
            for u, v in ((a, b), (b, c), (c, a)):
                if emap.get((v, u)) not in vis: horizon.append((u, v))
        for k in vis: rem(k)
        for u, v in horizon: add(u, v, p)
    return [[a, b, c] for a, b, c, _ in faces.values()]

def _components(tris):
    par = {}
    def fd(x):
        par.setdefault(x, x)
        while par[x] != x:
            par[x] = par[par[x]]; x = par[x]
        return x
    for t in tris:
        for v in t[1:]:
            ra, rb = fd(t[0]), fd(v)
            if ra != rb: par[rb] = ra
    groups = defaultdict(list)
    for i, t in enumerate(tris): groups[fd(t[0])].append(i)
    return list(groups.values())

def _signed_volume(tris, P):
    V = 0.0
    for a, b, c in tris:
        pa, pb, pc = P[a], P[b], P[c]
        V += (pa[0]*(pb[1]*pc[2]-pb[2]*pc[1]) - pa[1]*(pb[0]*pc[2]-pb[2]*pc[0]) + pa[2]*(pb[0]*pc[1]-pb[1]*pc[0]))
    return V / 6.0

def build_shadow(src, res_value, shrink=0.0, bad_parts='hull', hull_max=0.25):
    npts, nf = len(src.points), len(src.faces)
    sels = selections(src)
    proxy_faces = set()
    keep_sels = []
    for active, name, data in sels:
        fw = data[npts:npts + nf]
        if name.lower().startswith(b'proxy:'):
            proxy_faces.update(i for i in range(nf) if fw[i])
        else:
            keep_sels.append((name, data[:npts], fw))

    # weld points by position (1e-5 m grid)
    key_to_new, old_to_new, new_pts, rep = {}, {}, [], []
    for i, (x, y, z, fl) in enumerate(src.points):
        k = (round(x / 1e-5), round(y / 1e-5), round(z / 1e-5))
        j = key_to_new.get(k)
        if j is None:
            j = len(new_pts); key_to_new[k] = j; new_pts.append([x, y, z, 0]); rep.append(i)
        old_to_new[i] = j

    # triangulate, drop proxies, degenerates, duplicates
    tris, tri_src, seen = [], [], set()
    for fi, f in enumerate(src.faces):
        if fi in proxy_faces: continue
        idx = [old_to_new[v[0]] for v in f['v']]
        parts = [idx] if len(idx) == 3 else [[idx[0], idx[1], idx[2]], [idx[0], idx[2], idx[3]]]
        for t in parts:
            if len(set(t)) < 3: continue
            k = tuple(sorted(t))
            if k in seen: continue
            seen.add(k); tris.append(t); tri_src.append(fi)

    # edge use counts (directed + undirected)
    def edge_stats(tris):
        und = defaultdict(int); directed = defaultdict(int)
        for a, b, c in tris:
            for u, v in ((a, b), (b, c), (c, a)):
                und[(min(u, v), max(u, v))] += 1; directed[(u, v)] += 1
        return und, directed
    und, directed = edge_stats(tris)
    open_before = sum(1 for c in und.values() if c == 1)
    nonman = sum(1 for c in und.values() if c > 2)

    # cap holes: boundary edges (used once) chained into loops, fan-filled with reversed winding.
    # Repeated a few times so loops left over from figure-8 boundaries get closed too.
    caps = 0
    for _pass in range(4):
        und, directed = edge_stats(tris)
        boundary = {}
        for (u, v) in directed:
            if und[(min(u, v), max(u, v))] == 1:
                boundary.setdefault(v, []).append(u)   # walk reversed: v -> u
        if not boundary: break
        added = 0
        for start in list(boundary):
            while boundary.get(start):
                loop = [start]; cur = start
                while True:
                    nxts = boundary.get(cur)
                    if not nxts: break
                    nxt = nxts.pop()
                    if nxt == start: break
                    if nxt in loop:
                        loop = loop[loop.index(nxt):]; break
                    loop.append(nxt); cur = nxt
                if len(loop) >= 3:
                    for i in range(1, len(loop) - 1):
                        t = [loop[0], loop[i], loop[i + 1]]
                        k = tuple(sorted(t))
                        if k in seen: continue
                        seen.add(k); tris.append(t); tri_src.append(-1); caps += 1; added += 1
        if not added: break
    und2, _ = edge_stats(tris)
    open_after = sum(1 for c in und2.values() if c == 1)

    # leaky parts (open / non-manifold / flipped after capping) are what throw the long streaks.
    # Replace compact ones with their convex hull, drop the rest (or keep, if asked).
    hulled = dropped = flipped = 0
    if bad_parts != 'keep':
        und, directed = edge_stats(tris)
        bad = set(e for e, c in und.items() if c != 2) | set((min(u, v), max(u, v)) for (u, v), c in directed.items() if c > 1)
        out_t, out_s, repl, good = [], [], [], []
        for comp in _components(tris):
            ct = [tris[i] for i in comp]
            leaky = any((min(u, v), max(u, v)) in bad for a, b, c in ct for u, v in ((a, b), (b, c), (c, a)))
            vol = _signed_volume(ct, new_pts)
            if not leaky:
                area = 0.0
                for a, b, c in ct:
                    pa, pb, pc = new_pts[a], new_pts[b], new_pts[c]
                    ux, uy, uz = pb[0]-pa[0], pb[1]-pa[1], pb[2]-pa[2]; vx, vy, vz = pc[0]-pa[0], pc[1]-pa[1], pc[2]-pa[2]
                    area += math.sqrt((uy*vz-uz*vy)**2 + (uz*vx-ux*vz)**2 + (ux*vy-uy*vx)**2) / 2
                # closed but paper-thin (double-sided plane): no real volume, treat as leaky
                if area and 3 * abs(vol) / area >= 0.0002:
                    good.append((comp, ct, vol)); continue
            pidx = [i for t in ct for i in t]
            xs = [new_pts[i][0] for i in pidx]; ys = [new_pts[i][1] for i in pidx]; zs = [new_pts[i][2] for i in pidx]
            size = max(max(xs) - min(xs), max(ys) - min(ys), max(zs) - min(zs))
            h = convex_hull(pidx, new_pts) if (bad_parts == 'hull' and size <= hull_max) else None
            if h:   # reject a hull that isn't a clean closed shell (near-flat parts can do this)
                hu, hd = edge_stats(h)
                if any(c != 2 for c in hu.values()) or any(c > 1 for c in hd.values()): h = None
            if h:
                srcs = [tri_src[i] for i in comp if tri_src[i] >= 0]
                fs = max(set(srcs), key=srcs.count) if srcs else -1
                repl.append((h, fs)); hulled += 1
            else:
                dropped += 1
        # winding convention = whatever most of the (closed) volume uses, i.e. the visual mesh's
        good_vol = sum(v for _, _, v in good)
        want_neg = good_vol < 0 if good_vol else True
        for comp, ct, vol in good:
            inv = (vol > 0) if want_neg else (vol < 0)
            if inv: flipped += 1
            out_t += [[a, c, b] for a, b, c in ct] if inv else ct
            out_s += [tri_src[i] for i in comp]
        # hull comes out right-handed outward (positive volume)
        for h, fs in repl:
            for a, b, c in h:
                out_t.append([a, c, b] if want_neg else [a, b, c]); out_s.append(fs)
        tris, tri_src = out_t, out_s
        und2, _ = edge_stats(tris)
        open_after = sum(1 for c in und2.values() if c == 1)

    # drop points no triangle uses (proxy points etc.)
    used_pts = sorted({i for t in tris for i in t})
    remap = {o: n for n, o in enumerate(used_pts)}
    new_pts = [new_pts[o] for o in used_pts]; rep = [rep[o] for o in used_pts]
    tris = [[remap[i] for i in t] for t in tris]
    und2 = {(min(remap[u], remap[v]), max(remap[u], remap[v])): c for (u, v), c in und2.items()}

    # optional shrink along vertex normals so the volume sits just inside the visual mesh
    if shrink:
        vn = [[0.0, 0.0, 0.0] for _ in new_pts]
        for a, b, c in tris:
            pa, pb, pc = new_pts[a], new_pts[b], new_pts[c]
            ux, uy, uz = pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2]
            vx, vy, vz = pc[0] - pa[0], pc[1] - pa[1], pc[2] - pa[2]
            n = (uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx)
            for i in (a, b, c):
                vn[i][0] += n[0]; vn[i][1] += n[1]; vn[i][2] += n[2]
        moved = []
        for i, pt in enumerate(new_pts):
            l = math.sqrt(sum(x * x for x in vn[i])) or 1.0
            moved.append([pt[0] - shrink * vn[i][0] / l, pt[1] - shrink * vn[i][1] / l, pt[2] - shrink * vn[i][2] / l, pt[3]])
        new_pts = moved

    # assemble LOD
    S = Lod(); S.res = res_value; S.major, S.minor, S.flags = src.major, src.minor, src.flags
    S.points = new_pts
    for a, b, c in tris:
        pa, pb, pc = (new_pts[a], new_pts[b], new_pts[c])
        ux, uy, uz = pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2]
        vx, vy, vz = pc[0] - pa[0], pc[1] - pa[1], pc[2] - pa[2]
        nx, ny, nz = uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx
        l = math.sqrt(nx * nx + ny * ny + nz * nz) or 1.0
        S.normals.append([nx / l, ny / l, nz / l])
        ni = len(S.normals) - 1
        S.faces.append({'v': [(a, ni, 0.0, 0.0), (b, ni, 0.0, 0.0), (c, ni, 0.0, 0.0)], 'flags': 0, 'tex': b'', 'mat': b''})
    # selections: point weight from the representative source point, faces from source face
    newn, newf = len(new_pts), len(tris)
    for name, pw, fw in keep_sels:
        p_bytes = bytes(pw[rep[j]] for j in range(newn))
        if not any(p_bytes): continue
        f_bytes = bytes((fw[s] if s >= 0 else 0) for s in tri_src)
        S.tags.append([1, name, p_bytes + f_bytes])
    # every edge sharp
    edges = sorted(und2.keys())
    S.tags.append([1, b'#SharpEdges#', b''.join(struct.pack('<II', u, v) for u, v in edges)])
    stats = {'tris': newf, 'points': newn, 'open_before': open_before, 'caps': caps,
             'open_after': open_after, 'nonmanifold': nonman, 'proxies_removed': len(proxy_faces),
             'hulled': hulled, 'dropped': dropped, 'flipped': flipped, 'nonman_after': sum(1 for c in und2.values() if c > 2)}
    return S, stats

def backup_name(path):
    try:
        rel = os.path.relpath(os.path.abspath(path))
    except ValueError:          # different drive on Windows
        rel = os.path.abspath(path)
    return rel.replace(os.sep, '__').replace('/', '__').replace(':', '')

def quick_info(path):
    """Fast LOD summary without building point/face lists."""
    d = open(path, 'rb').read()
    if d[:4] != b'MLOD':
        return None
    n = struct.unpack_from('<I', d, 8)[0]; p = 12; out = []
    for _ in range(n):
        _, _, npts, nnorm, nf, _ = struct.unpack_from('<6I', d, p + 4)
        p += 28 + npts * 16 + nnorm * 12
        for _ in range(nf):
            p += 72; p = d.index(b'\0', p) + 1; p = d.index(b'\0', p) + 1
        p += 4
        while True:
            p += 1; e = d.index(b'\0', p); name = d[p:e]; p = e + 1
            ln = struct.unpack_from('<I', d, p)[0]; p += 4 + ln
            if name == b'#EndOfFile#': break
        out.append((struct.unpack_from('<f', d, p)[0], nf)); p += 4
    return out

# ----------------------------------------------------------------- per file
def tidy(lods):
    """Same clean-up as fix_props.py, done on every run so nobody has to remember it:
    drop named properties with whitespace in the name (pboProject warnings), exact
    duplicate properties, and give an EMPTY Geometry LOD the empty #Mass# tag pboProject
    demands ("Geolod has no mass" / "mass tagg missing")."""
    notes = []
    for L in lods:
        seen = set(); out = []
        for t in L.tags:
            if t[1] == b'#Property#':
                k = t[2][:64].split(b'\0')[0]; v = t[2][64:].split(b'\0')[0]
                if any(c in k for c in b' \t') or (k.lower(), v) in seen:
                    notes.append(k.decode('latin1')); continue
                seen.add((k.lower(), v))
            out.append(t)
        L.tags = out
        if near(L.res, GEOMETRY) and not L.points and not any(t[1] == b'#Mass#' for t in L.tags):
            L.tags.append([1, b'#Mass#', b'']); notes.append('#Mass#')
    msg = []
    props = [n for n in notes if n != '#Mass#']
    if props: msg.append('      tidied %d bad/duplicate named properties' % len(props))
    if '#Mass#' in notes: msg.append('      added empty mass to empty Geometry LOD (pboProject "Geolod has no mass")')
    return msg

def save(path, ver, lods):
    bdir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'temp', 'shadow_backups')
    os.makedirs(bdir, exist_ok=True)
    bak = os.path.join(bdir, backup_name(path))
    if not os.path.exists(bak):
        shutil.copy2(path, bak)
    write_p3d(path, ver, lods)
    read_p3d(path)  # verify it parses

def process(path, a):
    try:
        ver, lods = read_p3d(path)
    except Exception as e:
        return 'skip  %s: %s' % (path, e)
    tmsg = tidy(lods)
    def skip(why):
        if tmsg and not a.dry_run: save(path, ver, lods)
        return '\n'.join(['skip  %s: %s' % (path, why)] + tmsg)
    existing = [L for L in lods if is_shadow(L.res)]
    if existing and not a.replace:
        return skip('already has shadow LODs %s (use --replace)' % [L.res - 10000 for L in existing])
    src = pick_res(lods, a.source)
    if src is None:
        return skip('no resolution LOD with faces')
    if not [t for t in selections(src) if not t[1].lower().startswith(b'proxy:')]:
        return skip('no named selections, not worn gear (optic overlay?)')
    if {t[1].lower() for t in selections(src)} & {b'leftfoot', b'rightfoot'}:
        return skip('uniform / full body (has foot bones): generated shadows break these, use the BI character shadow LODs instead')
    lods = [L for L in lods if not is_shadow(L.res)]
    new = []
    s0, st = build_shadow(src, SHADOW0, a.shrink, a.bad_parts, a.hull_max); new.append(s0)
    msg = ['ok    %s: Shadow 0 from Res %g (%d tris; open edges %d -> %d; leaky parts hulled %d, dropped %d; inside-out parts flipped %d; proxies dropped %d)'
           % (path, src.res, st['tris'], st['open_before'], st['open_after'], st['hulled'], st['dropped'], st['flipped'], st['proxies_removed'])]
    low = pick_res(lods, a.low) if a.low else None
    if low is not None and low is not src:
        s10, st10 = build_shadow(low, SHADOW10, a.shrink, a.bad_parts, a.hull_max); new.append(s10)
        msg.append('      Shadow 10 from Res %g (%d tris; open %d; leaky parts hulled %d, dropped %d; flipped %d)' % (low.res, st10['tris'], st10['open_after'], st10['hulled'], st10['dropped'], st10['flipped']))
    if not a.no_firstperson:
        s1000, _ = build_shadow(src, SHADOW1000, a.shrink, a.bad_parts, a.hull_max); new.append(s1000)
        if low is not None and low is not src:
            s1010, _ = build_shadow(low, SHADOW1010, a.shrink, a.bad_parts, a.hull_max); new.append(s1010)
        msg.append('      + first-person copies (1000%s)' % ('/1010' if low is not None and low is not src else ''))
    # properties: undo the visualex experiment, let the engine use the volume
    for L in lods:
        if get_prop(L, 'sbsource') == 'visualex':
            del_prop(L, 'sbsource'); msg.append('      removed sbsource=visualex from LOD %g' % L.res)
        if is_res(L.res) and get_prop(L, 'prefershadowvolume') == '0':
            set_prop(L, 'prefershadowvolume', '1')
    # order: res + view LODs, Shadow 0/10, the rest (Geometry etc), Shadow 1000/1010
    head = [L for L in lods if L.res < 10000.0]
    tail = [L for L in lods if L.res >= 10000.0]
    early = [S for S in new if S.res < 11000.0]
    late = [S for S in new if S.res >= 11000.0]
    out = head + early + tail + late
    msg += tmsg
    if not a.dry_run:
        save(path, ver, out)
    if st['open_after'] or st.get('nonman_after'):
        msg.append('      WARNING: %d open edges remain; check this shadow in Object Builder (Shadow LOD must be closed)' % st['open_after'])
    return '\n'.join(msg)

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('paths', nargs='+')
    ap.add_argument('--source', type=float, default=3)
    ap.add_argument('--low', type=float, default=None)
    ap.add_argument('--no-firstperson', action='store_true')
    ap.add_argument('--shrink', type=float, default=0.0)
    ap.add_argument('--replace', action='store_true')
    ap.add_argument('--bad-parts', choices=['hull', 'drop', 'keep'], default='hull',
                    help='parts still leaky after capping: hull = replace small ones with convex hull, drop big ones (default); drop = drop all; keep = old behaviour')
    ap.add_argument('--hull-max', type=float, default=0.25, help='largest leaky part (m) that gets a hull instead of being dropped')
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--info', action='store_true', help='list LOD summary per model, change nothing')
    a = ap.parse_args()
    files = []
    for p in a.paths:
        if os.path.isdir(p):
            for dp, dn, fn in os.walk(p):
                files += [os.path.join(dp, f) for f in fn if f.lower().endswith('.p3d')]
        else:
            files.append(p)
    for f in sorted(files):
        if a.info:
            try:
                q = quick_info(f)
            except Exception as e:
                q = None
            if q is None:
                print('INFO|%s|-|-|-|-|not an MLOD p3d' % f); continue
            res = [r for r, _ in q if is_res(r)]
            sh = [r - 10000 for r, _ in q if is_shadow(r)]
            vp = any(near(r, VIEWPILOT) for r, _ in q)
            f1 = next((nf for r, nf in sorted(q) if is_res(r)), 0)
            print('INFO|%s|%d|%s|%s|%d|%s' % (f, len(res), 'yes' if vp else 'no',
                  ','.join('%g' % x for x in sh) or 'none', f1, ' '.join('%g' % r for r in res)))
            sys.stdout.flush()
            continue
        print(process(f, a))
        sys.stdout.flush()

if __name__ == '__main__':
    main()
