import subprocess, os, json, concurrent.futures, importlib.util, sys

MW = r"C:\Users\nnnn\Documents\mkwii"
SRC = os.path.join(MW, "src", "kart", "KartState.cpp")
TMP = os.path.join(os.environ["TEMP"], "opencode", "perm", "cand")
os.makedirs(TMP, exist_ok=True)
TARGET = os.path.join(MW, "build", "RMCP01", "StaticR", "obj", "kart", "KartState.o")
MWCC = os.path.join(MW, "build", "compilers", "Wii", "0x4201_127", "mwcceppc.exe")
OBJDIFF = os.path.join(MW, "build", "tools", "objdiff-cli.exe")
FLAGS = ["-nodefaults","-align","powerpc","-enc","SJIS","-gccinc","-proc","gekko","-enum","int","-O4,p",
         "-inline","auto","-fp","hardware","-Cpp_exceptions","off","-RTTI","off","-nostdinc","-DREVOKART",
         "-func_align","4","-i","./include","-i","./src","-i","./src/kart","-i","lib/MSL/include","-i","lib/MSL/src","-i","lib",
         "-DNDEBUG=1","-sdata","0","-sdata2","0","-ipa","file","-rostr","-str","noreuse","-use_lmw_stmw=on",
         "-lang=c++","-pragma","legacy_struct_alignment on","-DREL","-c"]

orig = open(SRC, encoding="utf-8", newline="").read().replace("\r\n", "\n")

def score(job):
    idx, name, text = job
    if text is None:
        return (name, None, "NOTFOUND")
    cpath = os.path.join(TMP, "h_%d.cpp" % idx)
    opath = os.path.join(TMP, "h_%d.o" % idx)
    open(cpath, "w", encoding="utf-8", newline="").write(text)
    rc = subprocess.run([MWCC] + FLAGS + [cpath, "-o", opath], cwd=MW, capture_output=True, text=True)
    if rc.returncode != 0:
        return (name, None, "FAIL: " + (rc.stderr.strip().splitlines()[-1][:120] if rc.stderr else ""))
    r = subprocess.run([OBJDIFF, "diff", "-1", TARGET, "-2", opath, "-o", "-", "--format", "json"],
                       cwd=MW, capture_output=True, text=True)
    try:
        d = json.loads(r.stdout)
    except Exception:
        return (name, None, "ODFAIL")
    for s in d["left"]["sections"]:
        for f in s.get("functions", []):
            if "updateCollisions__" in f["symbol"]["name"]:
                return (name, round(f.get("match_percent", 0), 4), "")
    return (name, None, "NOFN")

def run(jobs, workers=12):
    results = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as ex:
        for res in ex.map(score, jobs):
            results.append(res)
    results.sort(key=lambda r: (r[1] is None, -(r[1] or 0)))
    for name, val, note in results:
        print("%9s  %-40s %s" % (str(val), name, note))
    return results

if __name__ == "__main__":
    modname = sys.argv[1] if len(sys.argv) > 1 else "cs"
    spec = importlib.util.spec_from_file_location(modname, os.path.join(os.path.dirname(__file__), modname + ".py"))
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    jobs = [(0, "baseline", orig)]
    idx = 1
    for name, edits in getattr(m, "EDITS", []):
        t = orig
        ok = True
        for old, new in edits:
            if old not in t:
                ok = False; break
            t = t.replace(old, new, 1)
        jobs.append((idx, name, t if ok else None)); idx += 1
    for name, text in getattr(m, "FULLS", []):
        jobs.append((idx, name, text)); idx += 1
    print("jobs:", len(jobs), flush=True)
    run(jobs)
