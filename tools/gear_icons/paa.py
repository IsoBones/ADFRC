"""Minimal PAA reader: DXT1 / DXT5 / ARGB8888 / ARGB4444 / ARGB1555 / AI88, LZO-compressed mips.
read_paa(path, max_size=1024) -> (width, height, numpy uint8 array HxWx4 RGBA)
Picks the first mipmap no wider/taller than max_size (no resampling).
"""
import struct
import numpy as np

def lzo1x_decompress(src, out_len):
    src = memoryview(src)
    out = bytearray()
    ip = 0

    def run_len(t, base):
        nonlocal ip
        if t == 0:
            while src[ip] == 0:
                t += 255
                ip += 1
            t += base + src[ip]
            ip += 1
        return t

    def copy_match(dist, n):
        start = len(out) - dist
        if dist >= n:
            out.extend(out[start:start + n])
        else:
            for k in range(n):
                out.append(out[start + k])

    state = 0  # 0 = expect instruction, 1 = after first literal run
    t = src[ip]
    if t > 17:
        ip += 1
        t -= 17
        out.extend(src[ip:ip + t]); ip += t
        state = 1 if t >= 4 else 2   # 2: literals<4 copied, go straight to match decode
    while True:
        if state == 0:
            t = src[ip]; ip += 1
            if t < 16:
                t = run_len(t, 15)
                out.extend(src[ip:ip + t + 3]); ip += t + 3
                state = 1
                continue
        elif state == 1:
            t = src[ip]; ip += 1
            if t < 16:
                dist = 1 + 0x0800 + (t >> 2) + (src[ip] << 2); ip += 1
                copy_match(dist, 3)
                t = src[ip - 2] & 3
                if t:
                    out.extend(src[ip:ip + t]); ip += t
                    state = 2
                else:
                    state = 0
                continue
        else:  # state 2: next byte is a match instruction
            t = src[ip]; ip += 1
        # match loop
        while True:
            if t >= 64:
                dist = 1 + ((t >> 2) & 7) + (src[ip] << 3); ip += 1
                copy_match(dist, (t >> 5) - 1 + 2)
            elif t >= 32:
                n = run_len(t & 31, 31)
                dist = 1 + (src[ip] >> 2) + (src[ip + 1] << 6); ip += 2
                copy_match(dist, n + 2)
            elif t >= 16:
                hi = (t & 8) << 11
                n = run_len(t & 7, 7)
                dist = hi + (src[ip] >> 2) + (src[ip + 1] << 6); ip += 2
                if dist == 0:
                    return bytes(out[:out_len])
                copy_match(dist + 0x4000, n + 2)
            else:
                dist = 1 + (t >> 2) + (src[ip] << 2); ip += 1
                copy_match(dist, 2)
            t = src[ip - 2] & 3
            if t == 0:
                state = 0
                break
            out.extend(src[ip:ip + t]); ip += t
            t = src[ip]; ip += 1
        if len(out) >= out_len and state == 0 and ip >= len(src):
            return bytes(out[:out_len])

def _565(c):
    r = ((c >> 11) & 31).astype(np.uint32) * 255 // 31
    g = ((c >> 5) & 63).astype(np.uint32) * 255 // 63
    b = (c & 31).astype(np.uint32) * 255 // 31
    return np.stack([r, g, b], -1)

def _dxt_colors(blk, four_always):
    c0 = blk[:, 0].astype(np.uint32) | (blk[:, 1].astype(np.uint32) << 8)
    c1 = blk[:, 2].astype(np.uint32) | (blk[:, 3].astype(np.uint32) << 8)
    p0, p1 = _565(c0), _565(c1)
    four = np.ones(len(blk), bool) if four_always else (c0 > c1)
    p2 = np.where(four[:, None], (2 * p0 + p1) // 3, (p0 + p1) // 2)
    p3 = np.where(four[:, None], (p0 + 2 * p1) // 3, 0)
    pal = np.stack([p0, p1, p2, p3], 1)  # n,4,3
    a = np.full((len(blk), 4), 255, np.uint32)
    if not four_always:
        a[:, 3] = np.where(four, 255, 0)
    idx = blk[:, 4].astype(np.uint32) | (blk[:, 5].astype(np.uint32) << 8) | (blk[:, 6].astype(np.uint32) << 16) | (blk[:, 7].astype(np.uint32) << 24)
    sel = (idx[:, None] >> (2 * np.arange(16, dtype=np.uint32))[None, :]) & 3  # n,16
    rgb = np.take_along_axis(pal, sel[:, :, None].astype(np.int64).repeat(3, 2), 1)
    al = np.take_along_axis(a, sel.astype(np.int64), 1)
    return rgb, al

def _blocks_to_img(px, w, h):
    bw, bh = max(1, w // 4), max(1, h // 4)
    img = px.reshape(bh, bw, 4, 4, 4).transpose(0, 2, 1, 3, 4).reshape(bh * 4, bw * 4, 4)
    return img[:h, :w]

def decode_dxt(data, w, h, kind):
    nb = max(1, w // 4) * max(1, h // 4)
    if kind == 1:
        blk = np.frombuffer(data, np.uint8, nb * 8).reshape(nb, 8)
        rgb, al = _dxt_colors(blk, False)
    else:
        b = np.frombuffer(data, np.uint8, nb * 16).reshape(nb, 16)
        rgb, _ = _dxt_colors(b[:, 8:16], True)
        a0, a1 = b[:, 0].astype(np.int32), b[:, 1].astype(np.int32)
        bits = np.zeros(nb, np.uint64)
        for k in range(6):
            bits |= b[:, 2 + k].astype(np.uint64) << np.uint64(8 * k)
        sel = ((bits[:, None] >> (np.uint64(3) * np.arange(16, dtype=np.uint64))[None, :]) & np.uint64(7)).astype(np.int32)
        pal = np.zeros((nb, 8), np.int32)
        pal[:, 0], pal[:, 1] = a0, a1
        big = a0 > a1
        for i in range(1, 7):
            pal[:, i + 1] = np.where(big, ((7 - i) * a0 + i * a1) // 7, pal[:, i + 1])
        for i in range(1, 5):
            pal[:, i + 1] = np.where(~big, ((5 - i) * a0 + i * a1) // 5, pal[:, i + 1])
        pal[:, 6] = np.where(~big, 0, pal[:, 6])
        pal[:, 7] = np.where(~big, 255, pal[:, 7])
        al = np.take_along_axis(pal, sel, 1)
    px = np.concatenate([rgb, al[:, :, None]], 2).astype(np.uint8)
    return _blocks_to_img(px, w, h)

def read_paa(path, max_size=1024):
    d = open(path, 'rb').read()
    typ = struct.unpack_from('<H', d, 0)[0]
    p = 2
    while d[p:p + 4] == b'GGAT':
        ln = struct.unpack_from('<I', d, p + 8)[0]
        p += 12 + ln
    npal = struct.unpack_from('<H', d, p)[0]; p += 2 + npal * 3
    mips = []
    while p + 4 <= len(d):
        w, h = struct.unpack_from('<HH', d, p); p += 4
        if w == 0 or h == 0:
            break
        size = d[p] | (d[p + 1] << 8) | (d[p + 2] << 16); p += 3
        mips.append((w, h, p, size)); p += size
    if not mips:
        raise ValueError('no mipmaps')
    pick = next((m for m in mips if (m[0] & 0x7fff) <= max_size and m[1] <= max_size), mips[-1])
    w, h, off, size = pick
    lzo = bool(w & 0x8000); w &= 0x7fff
    raw = d[off:off + size]
    if typ in (0xFF01, 0xFF05):
        need = (max(1, w // 4) * max(1, h // 4)) * (8 if typ == 0xFF01 else 16)
        if lzo:
            raw = lzo1x_decompress(raw, need)
        return w, h, decode_dxt(raw, w, h, 1 if typ == 0xFF01 else 5)
    # uncompressed formats (LZSS-packed in PAA; only plain storage handled here)
    if typ == 0x8888 and len(raw) >= w * h * 4:
        a = np.frombuffer(raw, np.uint8, w * h * 4).reshape(h, w, 4)
        return w, h, a[:, :, [2, 1, 0, 3]].copy()
    raise ValueError('unsupported PAA type %04x (or packed storage)' % typ)

if __name__ == '__main__':
    import sys
    from PIL import Image
    w, h, img = read_paa(sys.argv[1], int(sys.argv[3]) if len(sys.argv) > 3 else 1024)
    Image.fromarray(img, 'RGBA').save(sys.argv[2])
    print(w, h)
