import sys, os, subprocess, re
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

EXPR = "(temp_f4 * temp_f4) + ((temp_f5 * temp_f5) + (accum.y * accum.y))"

FORMS = {}
FORMS["bool_under"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          bool under = EGG::Mathf::sqrt(" + EXPR + ") < 0.05f;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (under) {")
FORMS["bool_under_xyz"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          bool under = EGG::Mathf::sqrt(" + EXPR + ") < 0.05f;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (under) {")
FORMS["bool_declfirst"] = (
    "          bool under;\n"
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          under = EGG::Mathf::sqrt(" + EXPR + ") < 0.05f;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (under) {")
FORMS["bool_volatile_no"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          bool under = EGG::Mathf::sqrt(" + EXPR + ") < 0.05f;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (under) {")
# condition computed from an f32 named length (FPR vreg shift, but try)
FORMS["len2_before"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          f32 len2 = EGG::Mathf::sqrt(" + EXPR + ");\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (len2 < 0.05f) {")
# same-value: compute the raw sum (no call) before stores
FORMS["sum2_before"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          f32 sum2 = " + EXPR + ";\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (EGG::Mathf::sqrt(sum2) < 0.05f) {")


def analyze(name, text):
    TMP = os.path.join(os.environ["TEMP"], "opencode", "boolp")
    os.makedirs(TMP, exist_ok=True)
    cpath = os.path.join(TMP, name + ".cpp")
    opath = os.path.join(TMP, name + ".o")
    open(cpath, "w", encoding="utf-8", newline="").write(text)
    r = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath], cwd=h.MW, capture_output=True, text=True)
    if r.returncode != 0:
        print("%-16s COMPILE FAIL %s" % (name, (r.stderr or "")[-140:]))
        return
    _, v, note = h.score((0, name, text))
    OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"
    out = subprocess.run([OD, "-d", opath], capture_output=True, text=True).stdout
    lines = out.splitlines()
    reg, nins = None, 0
    started = False
    for i, l in enumerate(lines):
        if "updateCollisions__" in l:
            started = True
            continue
        if started and not l.startswith(" "):
            break
        if started:
            nins += 1
            if reg is None:
                mm = re.search(r"\tfmuls\s+(f\d+),(f\d+),(f\d+)", l)
                if mm and mm.group(2) == mm.group(3):
                    for nxt in lines[i + 1:i + 3]:
                        ms = re.search(r"\tstfs\s+(f\d+),44\(r1\)", nxt)
                        if ms:
                            reg = mm.group(2) if ms.group(1) == mm.group(2) else ("split?" + mm.group(2))
                            break
    print("%-16s score=%-9s web=%-8s insns=%s" % (name, v, reg, nins))


for name, body in FORMS.items():
    analyze(name, base.replace(BLOCK, body))
