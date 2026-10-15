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

# where to embed "accum.x = temp_f5," (comma) relative to the four sub-expressions:
# slots: before-t4, before-t5, before-y, after-y (each slot keeps evaluation order legal)
def build(slot, decl, tree):
    decls = ("          f32 temp_f5 = ci.wallNrm.x;\n          f32 temp_f4 = ci.wallNrm.z;\n"
             if decl == "f5" else
             "          f32 temp_f4 = ci.wallNrm.z;\n          f32 temp_f5 = ci.wallNrm.x;\n")
    head = "          accum.y = 0.0f;\n"
    X = "(accum.x = temp_f5, temp_f5)"
    parts = {"T4": T4, "T5": T5, "Y": Y}
    if slot == "before-t4":
        parts["T4"] = "((accum.x = temp_f5, temp_f4) * temp_f4)"
    elif slot == "before-t5":
        parts["T5"] = "((accum.x = temp_f5, temp_f5) * temp_f5)"
    elif slot == "before-y":
        parts["Y"] = "((accum.x = temp_f5, accum.y) * accum.y)"
    elif slot == "after-y":
        parts["Y"] = "((accum.y * accum.y) + (accum.x = temp_f5, 0.0f))"
    t4, t5, yy = parts["T4"], parts["T5"], parts["Y"]
    TREES = [
        t4 + " + (" + t5 + " + " + yy + ")",
        "(" + t4 + " + " + t5 + ") + " + yy,
        "(" + t5 + " + " + t4 + ") + " + yy,
        t5 + " + (" + t4 + " + " + yy + ")",
    ]
    body = decls + head + \
        "          if (EGG::Mathf::sqrt(" + TREES[tree] + ") < 0.05f) {"
    return base.replace(BLOCK, body)


slots = ["before-t4", "before-t5", "before-y", "after-y"]
combos = list(itertools.product(slots, ["f5", "f4"], range(4)))
texts = [build(*c) for c in combos]
results = h.run([(i, "c%03d" % i, t) for i, t in enumerate(texts)])

TMP = os.path.join(os.environ["TEMP"], "opencode", "comma2")
os.makedirs(TMP, exist_ok=True)
OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"


def reg_of(i):
    cpath = os.path.join(TMP, "c%03d.cpp" % i)
    opath = os.path.join(TMP, "c%03d.o" % i)
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
                        return mm.group(2) if ms.group(1) == mm.group(2) else "split(%s/%s)" % (mm.group(2), ms.group(1))
    return "?"


rows = []
for i, (_, v, _) in enumerate(results):
    rows.append((v if v == v else -1, combos[i], i))
rows.sort(key=lambda r: -r[0])
f5s = []
print("=== top 10 ===")
for v, meta, i in rows[:10]:
    print("  score=%-9s meta=%s" % (v, meta))
print("=== register scan, score>=99.40 ===")
for v, meta, i in rows:
    if v >= 99.40:
        rg = reg_of(i)
        print("  score=%-9s reg=%-12s meta=%s" % (v, rg, meta))
        if "f5" in str(rg):
            f5s.append((v, meta))
print("f5 hits:", f5s)
