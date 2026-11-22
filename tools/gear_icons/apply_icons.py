"""Step 5: put the icons into the addons and point each class's picture at its own icon.

Inputs: <work>/stage/looks.json (look -> classes), <work>/icons/<look>.png
Icons go next to the class's config, in the folder that config already uses for pictures
(fallback <addon>\\icons), named <classname>_ca.paa.
Configs are edited in place: an existing picture line in the class body is replaced, otherwise one is
added after the opening brace. CRLF/LF is kept as found. Originals of edited configs are copied once to
<work>/config_backup. Classes built by macros (no literal "class X {") are listed for a manual edit.
"""
import collections, json, ntpath, os, re, shutil, subprocess, sys

ROOT = ICONS = None
SEARCH = []

def find_imagetopaa(override=None):
    if override:
        return override if os.path.exists(override) else None
    cands = []
    try:
        import winreg
        k = winreg.OpenKey(winreg.HKEY_CURRENT_USER, r'Software\Valve\Steam')
        steam = winreg.QueryValueEx(k, 'SteamPath')[0]
        libs = [steam]
        vdf = os.path.join(steam, 'steamapps', 'libraryfolders.vdf')
        if os.path.exists(vdf):
            libs += re.findall(r'"path"\s+"([^"]+)"', open(vdf, encoding='utf-8', errors='replace').read())
        cands += [os.path.join(l.replace('\\\\', '\\'), 'steamapps', 'common', 'Arma 3 Tools', 'ImageToPAA', 'ImageToPAA.exe') for l in libs]
    except Exception:
        pass
    cands += [r'C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe']
    return next((c for c in cands if os.path.exists(c)), None)

def config_files():
    for base in SEARCH:
        for r, ds, fs in os.walk(os.path.join(ROOT, base)):
            for f in fs:
                if f.lower().endswith(('.cpp', '.hpp')):
                    yield os.path.join(r, f)

def body_span(text, open_brace):
    depth, i, n = 0, open_brace, len(text)
    in_str = False
    while i < n:
        c = text[i]
        if in_str:
            if c == '"':
                in_str = False
        elif c == '"':
            in_str = True
        elif text.startswith('//', i):
            i = text.find('\n', i); i = n if i < 0 else i; continue
        elif text.startswith('/*', i):
            i = text.find('*/', i); i = n if i < 0 else i + 2; continue
        elif c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return open_brace, i
        i += 1
    return None

def top_level_picture(text, a, b):
    """(start, end) of the value string of a depth-1 picture assignment inside text[a:b], or None."""
    depth = 0
    for m in re.finditer(r'[{}]|^[ \t]*picture\s*=\s*"([^"]*)"\s*;', text[a:b], re.I | re.M):
        tok = m.group(0)
        if tok == '{':
            depth += 1
        elif tok == '}':
            depth -= 1
        elif depth == 1:
            return a + m.start(1), a + m.end(1)
    return None

def main(root, work, addons, apply=False, imagetopaa=None):
    global ROOT, ICONS, SEARCH
    ROOT, ICONS, SEARCH = os.path.abspath(root), work, addons
    APPLY = apply
    looks = json.load(open(os.path.join(ICONS, 'stage', 'looks.json')))
    rendered = os.path.join(ICONS, 'icons')
    want = {}
    for lid, lk in looks.items():
        png = os.path.join(rendered, lid + '.png')
        if os.path.exists(png):
            for c in lk['classes']:
                want[c.lower()] = (c, png)
    texts = {f: open(f, encoding='latin1', newline='').read() for f in config_files()}   # keep CRLF as is
    # existing icon folders per config file (most used picture dir)
    found, icondir = {}, {}
    for f, t in texts.items():
        dirs = collections.Counter(ntpath.dirname(m.group(1)).lstrip('\\') for m in re.finditer(r'(?i)\bpicture\s*=\s*"(\\?(?!a3\\)[^"]+\.paa)"', t))
        rel_addon = os.path.relpath(os.path.dirname(f), ROOT).replace(os.sep, '\\')
        icondir[f] = dirs.most_common(1)[0][0] if dirs else rel_addon + '\\icons'
        for m in re.finditer(r'(?i)\bclass\s+(\w+)\s*(?::\s*\w+\s*)?\{', t):
            k = m.group(1).lower()
            if k in want:
                found.setdefault(k, []).append((f, m.end() - 1))
    edits = collections.defaultdict(list)  # file -> [(class, brace, iconpath)]
    convert, missing = [], []
    for k, (cls, png) in sorted(want.items()):
        locs = found.get(k)
        if not locs:
            missing.append(cls); continue
        # prefer the definition that has a displayName (the real one, not a compat re-declare)
        def score(loc):
            f, br = loc; sp = body_span(texts[f], br)
            return 1 if sp and re.search(r'(?i)displayName', texts[f][sp[0]:sp[1]]) else 0
        f, br = max(locs, key=score)
        d = icondir[f].replace('/', '\\')
        paa_rel = '\\' + d + '\\' + cls.lower() + '_ca.paa'
        edits[f].append((cls, br, paa_rel))
        convert.append((png, os.path.join(ROOT, d.replace('\\', os.sep), cls.lower() + '_ca.paa')))
    print('icons to place: %d, configs to edit: %d, classes not found literally: %d' % (len(convert), len(edits), len(missing)))
    for c in missing:
        print('  MANUAL (macro, or not in the searched addons):', c)
    if not APPLY:
        for f, es in edits.items():
            print(os.path.relpath(f, ROOT), len(es), 'classes, e.g.', es[0][0], '->', es[0][2])
        print('dry run, nothing written. Re-run with --apply.')
        return
    exe = find_imagetopaa(imagetopaa)
    if not exe:
        sys.exit('ImageToPAA.exe not found (Arma 3 Tools). Install Arma 3 Tools or pass --imagetopaa.')
    tmp = os.path.join(ICONS, 'paa_src'); os.makedirs(tmp, exist_ok=True)
    bad = 0
    for png, paa in convert:
        os.makedirs(os.path.dirname(paa), exist_ok=True)
        src = os.path.join(tmp, os.path.basename(paa)[:-4] + '.png')   # *_ca.png -> DXT5 with alpha
        shutil.copyfile(png, src)
        r = subprocess.run([exe, src, paa], capture_output=True, text=True)
        if r.returncode != 0 or not os.path.exists(paa):
            bad += 1; print('  ImageToPAA failed:', src, r.stdout.strip()[-200:], r.stderr.strip()[-200:])
    print('converted %d icons (%d failed)' % (len(convert) - bad, bad))
    bk = os.path.join(ICONS, 'config_backup'); os.makedirs(bk, exist_ok=True)
    for f, es in edits.items():
        b = os.path.join(bk, os.path.relpath(f, ROOT).replace(os.sep, '__'))
        if not os.path.exists(b):
            shutil.copyfile(f, b)
        t = texts[f]
        for cls, br, paa_rel in sorted(es, key=lambda e: -e[1]):      # back to front keeps offsets valid
            sp = body_span(t, br)
            pic = top_level_picture(t, sp[0], sp[1] + 1) if sp else None
            if pic:
                t = t[:pic[0]] + paa_rel + t[pic[1]:]
            else:
                nl = t.find('\n', br)
                nxt = t[nl + 1:t.find('\n', nl + 1)]
                indent = re.match(r'[ \t]*', nxt).group(0) or '\t\t'
                eol = '\r\n' if t[nl - 1:nl] == '\r' else '\n'
                t = t[:nl + 1] + indent + 'picture = "' + paa_rel + '";' + eol + t[nl + 1:]
        open(f, 'w', encoding='latin1', newline='').write(t)
        print('edited', os.path.relpath(f, ROOT), len(es))

if __name__ == '__main__':
    sys.exit('Run this through gear_icons.py (see README.md).')
