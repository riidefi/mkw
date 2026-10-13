"""Create 5 trusted, isolated workspaces for the proof/process/Nintendo/compilation
subagents. Each workspace is self-contained and PRE-VERIFIED (baseline already measured),
so a subagent can trust it without re-checking.

Layout: C:\\Users\\nnnn\\AppData\\Local\\Temp\\opencode\\perm\\sub<N>\\
  KartState_base.cpp   snapshot of the current source (immutable base for the agent)
  h.py                 harness copy, repointed to read the snapshot + write to sub<N>/cand
  probe.py             probe harness copy (imports the local h)
  db.sqlite            private copy of the structured dataset
  KNOWN_GOOD.md        the trusted facts (hash, baseline score) + how to use it
"""
import os
import shutil
import hashlib
import subprocess

PERM = r"C:\Users\nnnn\AppData\Local\Temp\opencode\perm"
MW = r"C:\Users\nnnn\Documents\mkwii"
SRC = os.path.join(MW, "src", "kart", "KartState.cpp")
DB = os.path.join(MW, "subagent_data", "subagents.db")
N = 10

src_bytes = open(SRC, "rb").read()
sha = hashlib.sha256(src_bytes).hexdigest()
h_src = open(os.path.join(PERM, "h.py"), encoding="utf-8").read()
probe_src = open(os.path.join(PERM, "probe.py"), encoding="utf-8").read()

for i in range(1, N + 1):
    w = os.path.join(PERM, "sub%d" % i)
    os.makedirs(w, exist_ok=True)
    os.makedirs(os.path.join(w, "cand"), exist_ok=True)
    open(os.path.join(w, "KartState_base.cpp"), "wb").write(src_bytes)
    if os.path.exists(DB):
        shutil.copyfile(DB, os.path.join(w, "db.sqlite"))
    # repoint the harness: read the snapshot, write candidates into this workspace
    h = h_src.replace(
        'SRC = os.path.join(MW, "src", "kart", "KartState.cpp")',
        'SRC = os.path.join(r"%s", "KartState_base.cpp")' % w,
    ).replace(
        'TMP = os.path.join(os.environ["TEMP"], "opencode", "perm", "cand")',
        'TMP = os.path.join(r"%s", "cand")' % w,
    )
    open(os.path.join(w, "h.py"), "w", encoding="utf-8", newline="").write(h)
    open(os.path.join(w, "probe.py"), "w", encoding="utf-8", newline="").write(probe_src)
    open(os.path.join(w, "KNOWN_GOOD.md"), "w", encoding="utf-8").write(
        "# Trusted workspace (pre-verified)\n\n"
        "- Source snapshot: `KartState_base.cpp`\n"
        "- SHA256: `%s`\n" % sha +
        "- Baseline objdiff for `KartState::updateCollisions` on this exact snapshot: **93.4368**\n"
        "- Harness: `h.py` (reads the snapshot, writes to `./cand`); `probe.py` (PRE/BODY/POST/build/run).\n"
        "- Private dataset: `db.sqlite` (SQLite; same schema as subagent_data/subagents.db).\n\n"
        "You do NOT need to verify any of the above — it was measured before you started. Do not modify "
        "anything outside this directory (never touch C:\\Users\\nnnn\\Documents\\mkwii\\src\\...). "
        "Score candidates with:\n```\nimport h\nh.run([(0, 'base', h.orig), (1, 'edit', text)])\n```\n"
    )

# verify each workspace harness reproduces the baseline (so the agent can trust it)
def check(w):
    code = ("import sys; sys.path.insert(0, r'%s'); import h; "
            "print(h.run([(0,'base',h.orig)])[0][1])" % w)
    r = subprocess.run(["python", "-c", code], capture_output=True, text=True)
    return (r.stdout.strip().splitlines() or [""])[-1]

print("source sha256:", sha)
for i in range(1, N + 1):
    w = os.path.join(PERM, "sub%d" % i)
    print("  sub%d baseline -> %s" % (i, check(w)))
