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
assert BLOCK in base, "BLOCK not found"

OD = r"C:\Users\nnnn\Documents\mkwii\build\binutils\powerpc-eabi-objdump.exe"
TMP = os.path.join(os.environ["TEMP"], "opencode", "eo8")
os.makedirs(TMP, exist_ok=True)

SQRT = "(temp_f4 * temp_f4) + ((temp_f5 * temp_f5) + (accum.y * accum.y))"

FORMS = {}
FORMS["muls_before"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          f32 ysq = 0.0f * 0.0f;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(t4sq + (t5sq + ysq)) < 0.05f) {")
FORMS["muls_before_t5first"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          f32 ysq = 0.0f * 0.0f;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(t4sq + (t5sq + ysq)) < 0.05f) {")
FORMS["muls_before_avar"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          f32 ysq = accum.y * accum.y;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (EGG::Mathf::sqrt(t4sq + (t5sq + ysq)) < 0.05f) {")
FORMS["sum_named"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          f32 sqsum = " + SQRT + ";\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (EGG::Mathf::sqrt(sqsum) < 0.05f) {")
FORMS["len_named"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.y = 0.0f;\n"
    "          f32 len = EGG::Mathf::sqrt(" + SQRT + ");\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          if (len < 0.05f) {")
FORMS["t4hoist"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(t4sq + ((temp_f5 * temp_f5) + (accum.y * accum.y))) < 0.05f) {")
FORMS["t5hoist"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          accum.x = temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt((temp_f4 * temp_f4) + (t5sq + (accum.y * accum.y))) < 0.05f) {")
FORMS["muls_before_storez"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          f32 ysq = 0.0f * 0.0f;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          accum.x = temp_f5;\n"
    "          accum.y = 0.0f;\n"
    "          accum.z = temp_f4;\n"
    "          if (EGG::Mathf::sqrt(t4sq + (t5sq + ysq)) < 0.05f) {")
FORMS["muls_between"] = (
    "          f32 temp_f5 = ci.wallNrm.x;\n"
    "          f32 temp_f4 = ci.wallNrm.z;\n"
    "          accum.x = temp_f5;\n"
    "          f32 ysq = 0.0f * 0.0f;\n"
    "          f32 t4sq = temp_f4 * temp_f4;\n"
    "          f32 t5sq = temp_f5 * temp_f5;\n"
    "          accum.z = temp_f4;\n"
    "          accum.y = 0.0f;\n"
    "          if (EGG::Mathf::sqrt(t4sq + (t5sq + ysq)) < 0.05f) {")


def analyze(name, text):
    cpath = os.path.join(TMP, name + ".cpp")
    opath = os.path.join(TMP, name + ".o")
    open(cpath, "w", encoding="utf-8", newline="").write(text)
    r = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath], cwd=h.MW, capture_output=True, text=True)
    if r.returncode != 0:
        print("%-20s COMPILE FAIL: %s" % (name, (r.stderr or "")[-150:]))
        return
    _, v, note = h.score((0, name, text))
    out = subprocess.run([OD, "-d", opath], capture_output=True, text=True).stdout
    loadreg, seq = None, []
    started = False
    for l in out.splitlines():
        if "updateCollisions__" in l:
            started = True
            continue
        if started and not l.startswith(" "):
            break
        if started:
            m = re.search(r"lfs\s+(f\d+),\s*36\(r31\)", l)
            if m:
                loadreg = m.group(1)
            m2 = re.search(r"\t(lfs|fmuls|fadds|fsubs|stfs)\s+(.*)", l)
            if m2 and re.search(r"0x24\(r31\)|0x2c\(r31\)|44\(r1\)|48\(r1\)|52\(r1\)", m2.group(2)):
                seq.append(m2.group(1) + " " + m2.group(2).replace("\t", " "))
    print("%-20s score=%-9s temp_f5_load=%-4s" % (name, v, loadreg))
    for s in seq:
        print("      %s" % s)


for name, body in FORMS.items():
    analyze(name, base.replace(BLOCK, body))
