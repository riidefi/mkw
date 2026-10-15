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

T4 = "(temp_f4 * temp_f4)"
T5 = "(temp_f5 * temp_f5)"
Y = "(accum.y * accum.y)"
SZ = "accum.z = temp_f4"

FORMS = {}
# A1: t4^2 first, then stfs x, then t5^2, then stfs z, y stored before expr
FORMS["A1"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + (((accum.x = temp_f5, temp_f5) * temp_f5) + " +
    "((accum.z = temp_f4, temp_f4) * 1.0f * (temp_f4 / temp_f4) * temp_f4 / temp_f4) + " + Y + ")) < 0.05f) {")
# too clever above risks folds; do clean variants instead
FORMS["A1"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + (((accum.x = temp_f5, temp_f5) * temp_f5) + " + Y + ")) < 0.05f) {")
# A2: stfs x embedded before t5^2 only (t4^2 already first operand)
FORMS["A2"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + ((temp_f5 * temp_f5) + " + Y + ")) < 0.05f) {")
# A3: all three stores embedded after t4^2, before t5^2
FORMS["A3"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + (((accum.x = temp_f5, accum.z = temp_f4, temp_f5) * temp_f5) + " + Y + ")) < 0.05f) {")
# A4: stores AFTER both muls (before y^2), y stored first
FORMS["A4"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + (" + T5 + " + ((accum.x = temp_f5, accum.z = temp_f4, accum.y) * accum.y))) < 0.05f) {")
# A5: stfs x embedded, t5-outer tree
FORMS["A5"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt((((accum.x = temp_f5, temp_f5) * temp_f5) + (" + T4 + " + " + Y + "))) < 0.05f) {")
# A6: stfs z embedded after t4^2 (x stored normally before)
FORMS["A6"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.x = temp_f5;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(((accum.z = temp_f4, temp_f4) * temp_f4) + ((temp_f5 * temp_f5) + " + Y + ")) < 0.05f) {")
# A7: stfs x + stfs z embedded around t4^2/t5^2, y before
FORMS["A7"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(((accum.z = temp_f4, temp_f4) * temp_f4) + (((accum.x = temp_f5, temp_f5) * temp_f5) + " + Y + ")) < 0.05f) {")
# A8: only stfs x embedded at the END of the expr (after y^2)
FORMS["A8"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(" + T4 + " + (" + T5 + " + ((accum.x = temp_f5, accum.y) * accum.y))) < 0.05f) {")


def analyze(name, text):
    TMP = os.path.join(os.environ["TEMP"], "opencode", "commap")
    os.makedirs(TMP, exist_ok=True)
    cpath = os.path.join(TMP, name + ".cpp")
    opath = os.path.join(TMP, name + ".o")
    open(cpath, "w", encoding="utf-8", newline="").write(text)
    r = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath], cwd=h.MW, capture_output=True, text=True)
    if r.returncode != 0:
        print("%-4s COMPILE FAIL %s" % (name, (r.stderr or "")[-160:]))
        return
    _, v, note = h.score((0, name, text))
    OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"
    out = subprocess.run([OD, "-d", opath], capture_output=True, text=True).stdout
    lines = out.splitlines()
    started, reg, seq = False, None, []
    for i, l in enumerate(lines):
        if "updateCollisions__Q24Kart9KartStateFv>:" in l:
            started = True
            continue
        if started and not l.startswith(" "):
            break
        if started:
            mm = re.search(r"\tfmuls\s+(f\d+),(f\d+),(f\d+)", l)
            if mm and mm.group(2) == mm.group(3) and reg is None:
                for nxt in lines[i + 1:i + 3]:
                    ms = re.search(r"\tstfs\s+(f\d+),44\(r1\)", nxt)
                    if ms:
                        reg = mm.group(2) if ms.group(1) == mm.group(2) else "split(%s,%s)" % (mm.group(2), ms.group(1))
                        break
            m = re.search(r"\t(lfs|fmuls|fadds|stfs)\s+(.*)", l)
            if m and re.search(r"36\(r31\)|44\(r31\)|44\(r1\)|52\(r1\)|48\(r1\)", m.group(2)):
                seq.append(m.group(1) + " " + m.group(2))
    print("%-4s score=%-9s web=%-10s" % (name, v, reg))
    for s in seq[:12]:
        print("       %s" % s)


for name, body in FORMS.items():
    analyze(name, base.replace(BLOCK, body))
