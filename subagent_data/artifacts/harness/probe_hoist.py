import sys, os, subprocess, re, itertools
sys.path.insert(0, r'C:\Users\nnnn\AppData\Local\Temp\opencode\perm')
import h

base = h.orig
BLOCK = ("          f32 temp_f5 = ci.wallNrm.x;\n"
         "          f32 temp_f4 = ci.wallNrm.z;\n"
         "          accum.x = temp_f5;\n"
         "          accum.z = temp_f4;\n"
         "          accum.y = 0.0f;\n"
         "          if (EGG::Mathf::sqrt((temp_f4 * temp_f4) + ((temp_f5 * temp_f5) + (accum.y * accum.y))) < 0.05f) {")
assert BLOCK in base

T4 = "(temp_f4 * temp_f4)"
T5 = "(temp_f5 * temp_f5)"
Y = "(accum.y * accum.y)"
TREES = [
    T4 + " + (" + T5 + " + " + Y + ")",
    "(" + T4 + " + " + T5 + ") + " + Y,
    "(" + T5 + " + " + T4 + ") + " + Y,
    T5 + " + (" + T4 + " + " + Y + ")",
]
STORES = {
    "xzy": ["accum.x = temp_f5;", "accum.z = temp_f4;", "accum.y = 0.0f;"],
    "xyz": ["accum.x = temp_f5;", "accum.y = 0.0f;", "accum.z = temp_f4;"],
    "yxz": ["accum.y = 0.0f;", "accum.x = temp_f5;", "accum.z = temp_f4;"],
    "yzx": ["accum.y = 0.0f;", "accum.z = temp_f4;", "accum.x = temp_f5;"],
    "zxy": ["accum.z = temp_f4;", "accum.x = temp_f5;", "accum.y = 0.0f;"],
    "zyx": ["accum.z = temp_f4;", "accum.y = 0.0f;", "accum.x = temp_f5;"],
}
# hoist pattern: which of (ysq, t4sq, t5sq) get named and computed before the stores
HOISTS = {
    "none": [],
    "t4": ["t4"],
    "t5": ["t5"],
    "t4t5": ["t4", "t5"],
    "t4t5y": ["t4", "t5", "y"],
    "y": ["y"],
}


def make(hoist, decl, store_order, tree):
    tree = TREES[tree]
    decls = ("          f32 temp_f5 = ci.wallNrm.x;\n          f32 temp_f4 = ci.wallNrm.z;\n"
             if decl == "f5" else
             "          f32 temp_f4 = ci.wallNrm.z;\n          f32 temp_f5 = ci.wallNrm.x;\n")
    pre = ""
    st = list(STORES[store_order])
    if "y" in HOISTS[hoist]:
        if "accum.y = 0.0f;" in st:
            st.remove("accum.y = 0.0f;")
        pre += "          accum.y = 0.0f;\n"
        pre += "          f32 ysq = accum.y * accum.y;\n"
        tree = tree.replace(Y, "ysq")
    if "t4" in HOISTS[hoist]:
        pre += "          f32 t4sq = temp_f4 * temp_f4;\n"
        tree = tree.replace(T4, "t4sq")
    if "t5" in HOISTS[hoist]:
        pre += "          f32 t5sq = temp_f5 * temp_f5;\n"
        tree = tree.replace(T5, "t5sq")
    body = decls + pre + "\n".join("          " + s for s in st) + \
        "\n          if (EGG::Mathf::sqrt(" + tree + ") < 0.05f) {"
    return base.replace(BLOCK, body)


combos = list(itertools.product(HOISTS.keys(), ["f5", "f4"], STORES.keys(), range(len(TREES))))
texts = [make(*c) for c in combos]
print("combos:", len(texts))

results = h.run([(i, "x%03d" % i, t) for i, t in enumerate(texts)])

TMP = os.path.join(os.environ["TEMP"], "opencode", "hoistp")
os.makedirs(TMP, exist_ok=True)
OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"


def reg_of(i):
    cpath = os.path.join(TMP, "x%03d.cpp" % i)
    opath = os.path.join(TMP, "x%03d.o" % i)
    open(cpath, "w", encoding="utf-8", newline="").write(texts[i])
    r = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath], cwd=h.MW, capture_output=True, text=True)
    if r.returncode != 0:
        return "cf"
    out = subprocess.run([OD, "-d", opath], capture_output=True, text=True).stdout
    lines = out.splitlines()
    started = False
    for j, l in enumerate(lines):
        if "updateCollisions__Q24Kart9KartStateFv>:" in l:
            started = True
            continue
        if started and not l.startswith(" "):
            break
        if started:
            mm = re.search(r"\tfmuls\s+(f\d+),(f\d+),(f\d+)", l)
            if mm and mm.group(2) == mm.group(3):
                for nxt in lines[j + 1:j + 3]:
                    ms = re.search(r"\tstfs\s+(f\d+),44\(r1\)", nxt)
                    if ms:
                        return mm.group(2) if ms.group(1) == mm.group(2) else "split"
    return "?"


rows = []
for i, res in enumerate(results):
    _, v, note = res
    rows.append((v, combos[i]))
rows.sort(key=lambda r: -(r[0] if r[0] == r[0] else -1))
print("=== top 20 by score ===")
for v, meta in rows[:20]:
    print("  score=%-9s meta=%s" % (v, meta))
# register scan for anything >= 99.642
hi = [(v, m) for v, m in rows if v and v == v and v >= 99.642]
print("=== register for all >= 99.642 (%d) ===" % len(hi))
seen = {}
for v, m in hi:
    idx = combos.index(m)
    rg = reg_of(idx)
    seen.setdefault((rg, v), []).append(m)
for (rg, v), metas in sorted(seen.items(), key=lambda kv: -kv[0][1]):
    print("  reg=%-6s score=%-9s n=%d e.g. %s" % (rg, v, len(metas), metas[0]))
