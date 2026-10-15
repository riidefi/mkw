import sys, os, subprocess, re, itertools, json
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

OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"
TMP = os.path.join(os.environ["TEMP"], "opencode", "eo9")
os.makedirs(TMP, exist_ok=True)

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


def make(decl_first, store_order, tree, y_named, t4_named):
    decls = ("          f32 temp_f5 = ci.wallNrm.x;\n          f32 temp_f4 = ci.wallNrm.z;\n"
             if decl_first == "f5" else
             "          f32 temp_f4 = ci.wallNrm.z;\n          f32 temp_f5 = ci.wallNrm.x;\n")
    pre = ""
    if y_named:
        # accum.y must be set before reading it
        st = list(STORES[store_order])
        if "accum.y = 0.0f;" in st:
            st.remove("accum.y = 0.0f;")
            pre += "          accum.y = 0.0f;\n"
        pre += "          f32 ysq = accum.y * accum.y;\n"
        tree = tree.replace(Y, "ysq")
        stores = st
    else:
        stores = STORES[store_order]
    if t4_named:
        pre += "          f32 t4sq = temp_f4 * temp_f4;\n"
        tree = tree.replace(T4, "t4sq")
    body = decls + pre + "\n".join("          " + s for s in stores) + \
        "\n          if (EGG::Mathf::sqrt(" + tree + ") < 0.05f) {"
    return base.replace(BLOCK, body)


def loadreg(text, name):
    cpath = os.path.join(TMP, name + ".cpp")
    opath = os.path.join(TMP, name + ".o")
    open(cpath, "w", encoding="utf-8", newline="").write(text)
    r = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath], cwd=h.MW, capture_output=True, text=True)
    if r.returncode != 0:
        return None, None, "compile-fail"
    out = subprocess.run([OD, "-d", opath], capture_output=True, text=True).stdout
    started = False
    lines = out.splitlines()
    for i, l in enumerate(lines):
        if "updateCollisions__" in l:
            started = True
            continue
        if started and not l.startswith(" "):
            break
        if started:
            mm = re.search(r"\tfmuls\s+(f\d+),(f\d+),(f\d+)", l)
            if mm and mm.group(2) == mm.group(3):
                for nxt in lines[i + 1:i + 3]:
                    ms = re.search(r"\tstfs\s+(f\d+),44\(r1\)", nxt)
                    if ms:
                        if ms.group(1) == mm.group(2):
                            return mm.group(2), opath, None
                        return "split?" + mm.group(2) + "/" + ms.group(1), opath, None
    return None, opath, None


combos = list(itertools.product(["f5", "f4"], STORES.keys(), range(len(TREES)), [False, True], [False, True]))
texts, metas = [], []
for i, (df, so, ti, yn, t4n) in enumerate(combos):
    texts.append(make(df, so, TREES[ti], yn, t4n))
    metas.append((df, so, ti, yn, t4n))

results = h.run([(i, "m%03d" % i, t) for i, t in enumerate(texts)])

f5_hits, top = [], []
for (i, res) in enumerate(results):
    _, v, note = res
    if isinstance(v, (int, float)) and v is not None and v == v:
        reg, _, err = loadreg(texts[i], "m%03d" % i)
        row = (v, reg, metas[i])
        if reg == "f5":
            f5_hits.append(row)
        top.append(row)

top.sort(key=lambda r: -r[0])
print("=== load==f5 forms (%d) ===" % len(f5_hits))
for v, reg, meta in f5_hits:
    print("  score=%s meta=%s" % (v, meta))
print("=== top 15 ===")
for v, reg, meta in top[:15]:
    print("  score=%-9s load=%-4s meta=%s" % (v, reg, meta))
