"""Step 3: render each look with Blender. Runs inside stock Blender (needs only bpy + numpy,
both bundled with Blender), normally launched by gear_icons.py:

  blender -b -P render_icons.py -- <stage dir> <raw dir> [look ids or classnames...]

Writes <raw dir>/<look id>.png: a 512x512 transparent render. Cropping/fitting to the final
256x256 icon is step 4 (gear_icons.py fit), outside Blender.
"""
import json, math, os, sys
import numpy as np
import bpy
from mathutils import Vector

argv = sys.argv[sys.argv.index('--') + 1:] if '--' in sys.argv else sys.argv[1:]
STAGE, OUT = argv[0], argv[1]
ONLY = set(argv[2:])
os.makedirs(OUT, exist_ok=True)

RENDER = 512
# camera per category: azimuth deg from the model's front toward its right side, elevation deg
VIEWS = {
    'headgear': (40, 24),
    'nvg': (40, 24),
    'glasses': (32, 16),
    'vest': (22, 14),
    'uniform': (18, 10),
    'backpack': (200, 16),
    # weapons, attachments and magazines: angles are relative to the weapon's left side, muzzle to the
    # left like the vanilla pictures (forward is worked out from the memory points when there are any)
    'weapon': (0, 0),
    'attachment': (20, 12),
    'magazine': (25, 12),
}
SIDE_ON = ('weapon', 'attachment', 'magazine')
ORTHO = ('weapon',)                       # straight side view without perspective
WIDE = {'weapon': (1024, 512)}            # raw render size when not square

_img_cache = {}

def setup_scene():
    # clear the previous look (and Blender's default cube/light/camera); images stay cached
    for coll in (bpy.data.objects, bpy.data.meshes, bpy.data.materials, bpy.data.lights,
                 bpy.data.cameras, bpy.data.worlds):
        for b in list(coll):
            coll.remove(b)
    sc = bpy.context.scene
    sc.render.engine = 'CYCLES'
    sc.cycles.device = 'CPU'
    sc.cycles.samples = 48
    sc.cycles.use_denoising = True
    sc.render.film_transparent = True
    sc.render.resolution_x = sc.render.resolution_y = RENDER
    sc.render.image_settings.file_format = 'PNG'
    sc.render.image_settings.color_mode = 'RGBA'
    sc.view_settings.view_transform = 'Standard'
    sc.view_settings.look = 'None'
    world = bpy.data.worlds.new('w'); sc.world = world
    world.use_nodes = True
    bg = world.node_tree.nodes['Background']
    bg.inputs[0].default_value = (0.55, 0.57, 0.6, 1); bg.inputs[1].default_value = 0.55
    cam = bpy.data.objects.new('cam', bpy.data.cameras.new('cam'))
    cam.data.lens = 85
    sc.collection.objects.link(cam); sc.camera = cam
    return sc, cam

def add_light(name, energy, size, loc, target):
    l = bpy.data.lights.new(name, 'AREA'); l.energy = energy; l.size = size
    o = bpy.data.objects.new(name, l); bpy.context.scene.collection.objects.link(o)
    o.location = loc
    d = Vector(target) - Vector(loc)
    o.rotation_euler = d.to_track_quat('-Z', 'Y').to_euler()
    return o

def material(key, stage):
    m = bpy.data.materials.get(key)
    if m:
        return m
    m = bpy.data.materials.new(key); m.use_nodes = True
    nt = m.node_tree; bsdf = nt.nodes['Principled BSDF']
    bsdf.inputs['Roughness'].default_value = 0.72
    if 'Specular IOR Level' in bsdf.inputs:
        bsdf.inputs['Specular IOR Level'].default_value = 0.25
    if key.startswith('#'):
        import re
        nums = re.findall(r'[-\d.]+', key.split('color(')[-1]) if 'color(' in key else []
        rgba = [float(x) for x in nums[:4]] + [1.0] * (4 - len(nums[:4]))
        bsdf.inputs['Base Color'].default_value = (rgba[0], rgba[1], rgba[2], 1)
        bsdf.inputs['Alpha'].default_value = rgba[3]
    else:
        tex = nt.nodes.new('ShaderNodeTexImage')
        img = _img_cache.get(key) or bpy.data.images.load(os.path.join(stage, key))
        _img_cache[key] = img
        tex.image = img
        tex.interpolation = 'Cubic'
        nt.links.new(tex.outputs['Color'], bsdf.inputs['Base Color'])
        nt.links.new(tex.outputs['Alpha'], bsdf.inputs['Alpha'])
    return m

def _w(raw):
    """MLOD selection weight byte -> 0..1 (0 = not selected, 1 = full, else (256-v)/255)."""
    w = (256.0 - raw.astype(np.float32)) / 255.0
    w[raw == 0] = 0.0
    w[raw == 1] = 1.0
    return w

ARM_DROP = 1.0   # 1.0 = arms straight down beside the body (minus ARM_SPLAY)
ARM_SPLAY = 9.0  # degrees out from the body

def pose_arms(P, PW, sels):
    """Rotate each arm chain down about its shoulder, weighted by the bone weights (linear blend)."""
    if PW.shape[1] == 0:
        return P
    P = P.copy()
    for side, sgn in (('left', 1.0), ('right', -1.0)):
        chain = [i for i, n in enumerate(sels) if n.startswith(side) and any(k in n for k in ('arm', 'hand'))]
        if not chain:
            continue
        w = np.clip(sum(_w(PW[:, i]) for i in chain), 0, 1)
        seam = (w > 0.25) & (w < 0.75)
        full = w > 0.95
        if seam.sum() < 3 or full.sum() < 3:
            continue
        piv = P[seam].mean(0)
        vec = P[full].mean(0) - piv                       # current arm direction (x,z plane)
        cur = math.atan2(vec[2], vec[0] * sgn)            # angle below horizontal, outward positive
        tgt = math.atan2(-math.cos(math.radians(ARM_SPLAY)), math.sin(math.radians(ARM_SPLAY)))
        ang = (tgt - cur) * ARM_DROP * sgn
        c, s_ = math.cos(ang), math.sin(ang)
        q = P - piv
        rx = c * q[:, 0] - s_ * q[:, 2]
        rz = s_ * q[:, 0] + c * q[:, 2]
        P[:, 0] = P[:, 0] + w * (rx - q[:, 0])
        P[:, 2] = P[:, 2] + w * (rz - q[:, 2])
    return P

def build(look, stage):
    z = np.load(os.path.join(stage, look['mesh']))
    P, T, UV, FT, SB = z['P'], z['T'], z['UV'], z['FT'], z['SB']
    sels = look['mesh_sels']
    if 'PW' in z.files:
        P = pose_arms(P, z['PW'], sels)
    tex = np.array([t if t else '' for t in look['mesh_textures']], dtype=object)[FT]
    hide = tex == ''
    for i, s in enumerate(sels):
        if s.startswith('proxy:'):
            hide |= SB[:, i]
    for s, t in look['overrides']:
        if s not in sels:
            continue
        m = SB[:, sels.index(s)]
        if t is None:
            hide |= m
        else:
            tex[m] = t
            hide[m] = False
    keep = ~hide
    T, UV, tex = T[keep], UV[keep], tex[keep]
    used = np.unique(T)
    remap = np.full(len(P), -1, np.int64); remap[used] = np.arange(len(used))
    Pv = P[used]; Tv = remap[T]
    me = bpy.data.meshes.new('m')
    me.from_pydata(Pv.tolist(), [], Tv.tolist())
    uvl = me.uv_layers.new(name='uv')
    uvl.data.foreach_set('uv', UV.reshape(-1).astype(np.float32))
    keys = sorted(set(tex.tolist()))
    for k in keys:
        me.materials.append(material(k, stage))
    me.polygons.foreach_set('material_index', np.array([keys.index(k) for k in tex], np.int32))
    me.polygons.foreach_set('use_smooth', np.ones(len(Tv), bool))
    me.update()
    ob = bpy.data.objects.new('item', me)
    bpy.context.scene.collection.objects.link(ob)
    bpy.context.view_layer.objects.active = ob; ob.select_set(True)
    try:
        bpy.ops.object.shade_smooth_by_angle(angle=math.radians(40))
    except Exception:
        pass
    return ob, Pv

def frame(cam, pts, az, el, ortho=False, aspect=1.0):
    lo, hi = pts.min(0), pts.max(0)
    c = Vector(((lo + hi) / 2).tolist())
    r = float(np.linalg.norm(pts - np.array(c), axis=1).max())
    a, e = math.radians(az), math.radians(el)
    # models face -Y (their right is -X) once p3d (x,y,z) is mapped to blender (x,z,y)
    d = Vector((-math.sin(a) * math.cos(e), -math.cos(a) * math.cos(e), math.sin(e)))
    fov = 2 * math.atan(18 / cam.data.lens)
    dist = r / math.sin(fov / 2) * 1.02
    cam.location = c + d * dist
    cam.rotation_euler = (-d).to_track_quat('-Z', 'Y').to_euler()
    if ortho:
        cam.data.type = 'ORTHO'
        cam.data.ortho_scale = 2 * r * 1.04   # view width; the height is width / aspect
    cam.data.clip_start = max(0.001, dist - r * 1.5); cam.data.clip_end = dist + r * 2
    return c, d, dist, r

def fwd_of(look):
    z = np.load(os.path.join(STAGE, look['mesh']))
    return z['FWD'] if 'FWD' in z.files else np.array([-1.0, 0.0, 0.0])

def main():
    looks = json.load(open(os.path.join(STAGE, 'looks.json')))
    for lid, look in looks.items():
        if ONLY and lid not in ONLY and not (set(look['classes']) & ONLY):
            continue
        sc, cam = setup_scene()
        ob, pts = build(look, STAGE)
        if look['category'] not in VIEWS:
            print('SKIP', lid, look['category'], '(no camera view for this category)', flush=True)
            continue
        cat = look['category']
        az, el = VIEWS[cat]
        if cat in SIDE_ON:
            f = fwd_of(look)
            az += math.degrees(math.atan2(f[1], -f[0]))   # put the camera on the weapon's left side
        w, h = WIDE.get(cat, (RENDER, RENDER))
        sc.render.resolution_x, sc.render.resolution_y = w, h
        c, d, dist, r = frame(cam, pts, az, el, ortho=cat in ORTHO, aspect=w / h)
        right = d.cross(Vector((0, 0, 1))).normalized()
        up = right.cross(d).normalized() * -1
        key = c + (d * 1.0 - right * 0.9 + up * 0.9).normalized() * dist
        fill = c + (d * 1.0 + right * 1.0 + up * 0.1).normalized() * dist
        rim = c + (-d + up * 0.8).normalized() * dist
        add_light('key', 60 * dist * dist, r * 1.5, key, c)
        add_light('fill', 22 * dist * dist, r * 2.5, fill, c)
        add_light('rim', 40 * dist * dist, r * 1.5, rim, c)
        sc.render.filepath = os.path.join(OUT, lid + '.png')
        bpy.ops.render.render(write_still=True)
        print('RENDER', lid, look['category'], look['classes'][0], flush=True)

main()
