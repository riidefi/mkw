import os, sys, re, concurrent.futures, importlib.util
here = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location("h", os.path.join(here, "h.py"))
h = importlib.util.module_from_spec(spec); spec.loader.exec_module(h)

FULL = h.orig
START = "void KartState::updateCollisions() {"
END = "\nKartState::~KartState"
i = FULL.index(START)
j = FULL.index(END)
PRE = FULL[:i]
BODY = FULL[i:j]
POST = FULL[j:]

def build(edits, body=BODY):
    b = body
    for old, new in edits:
        if old not in b:
            return None
        b = b.replace(old, new)
    return PRE + b + POST

def run(jobs):
    # jobs: list of (name, fulltext)
    jobs = [(k, n, t) for k, (n, t) in enumerate(jobs)]
    res = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=12) as ex:
        for r in ex.map(h.score, jobs):
            res.append(r)
    res.sort(key=lambda r: (r[1] is None, -(r[1] or 0)))
    for name, val, note in res:
        print("%9s  %-46s %s" % (str(val), name, note))
    return res
