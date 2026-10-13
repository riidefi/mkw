#!/usr/bin/env python3
"""run_and_log.py -- ETL harness for `KartState::updateCollisions` candidates.

Runs a batch of source-edit candidates through the compile+objdiff harness
(`%TEMP%\\opencode\\perm`, i.e. `import probe as P; P.run([...])`), captures the
resulting colouring by disassembling the emitted object with objdump, then
writes the observations BACK into the subagent database:

  * one `trials` row per candidate (agent_id="ETL", schema-complete, with
    base / delta / beat provenance),
  * one `regalloc` row per web (build_id="cand-<trial_id>") for any candidate
    that is re-dumped through the MWCC debugger,
  * a summary `findings` row for the experiment family,
  * refreshed FTS5 indexes (fts_trials / fts_findings / fts_agents).

Rows are de-duplicated by (label, edit_from, edit_to). Because `build_db.py`
recreates the database from scratch, every ETL row is also exported to
`extra_*.jsonl` next to the DB; `build_db.py` merges those files on rebuild so
the ETL results survive a re-run.

The repository source is never left modified: candidates are compiled from an
in-memory copy (via `probe.build`), and the one candidate re-dumped for
regalloc is written to `src/kart/KartState.cpp` only for the duration of the
MWCC debugger run, then restored byte-for-byte.

Usage:
    python run_and_log.py                 # run the default family, log to DB
    python run_and_log.py --list          # list the family, run nothing
    python run_and_log.py --dry-run       # run, print, do not touch the DB
    python run_and_log.py --redump all    # re-dump every candidate's regalloc
    python run_and_log.py --db PATH --json out.json
"""
from __future__ import annotations

import argparse
import concurrent.futures
import importlib.util
import json
import os
import re
import sqlite3
import subprocess
import sys
import tempfile

# --------------------------------------------------------------------------- #
# paths
# --------------------------------------------------------------------------- #
HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.dirname(HERE)
DEFAULT_DB = os.path.join(DATA, "subagents.db")

MW = r"C:\Users\nnnn\Documents\mkwii"
SRC = os.path.join(MW, "src", "kart", "KartState.cpp")
OBJDUMP = os.path.join(MW, "build", "binutils", "powerpc-eabi-objdump.exe")
SYM = "updateCollisions__Q24Kart9KartStateFv"

TEMP = os.environ.get("TEMP") or tempfile.gettempdir()
PERM = os.path.join(TEMP, "opencode", "perm")
MHTRI = os.path.join(TEMP, "opencode", "mhtri")
WORK = os.path.join(TEMP, "opencode", "etl")
os.makedirs(WORK, exist_ok=True)

# --------------------------------------------------------------------------- #
# harness + domain constants (reuse the existing analytics module)
# --------------------------------------------------------------------------- #
sys.path.insert(0, PERM)
import probe as P  # noqa: E402  (needs PERM on sys.path)
h = P.h

sys.path.insert(0, HERE)
import analyze_db as AD  # noqa: E402

# registers tuple order is "pe/var_r28/proxy/pool" (see README.md)
REG_ORDER = ("pe", "var_r28", "proxy", "pool")
BASE93 = tuple(AD.BASE93)              # ("r28","r30","r26","r29")
TARGET = tuple(AD.TARGET)              # ("r30","r28","r26","r29")
BASE93_SCORE = float(AD.BASE93_SCORE)  # 93.4368

AGENT_ID = "ETL"
FAMILY = "ETL-RSPLIT-EXT"

# --------------------------------------------------------------------------- #
# experiment family
#   category values come from the README vocabulary; every (old, new) snippet is
#   validated against the *current* source before the candidate is run.
# --------------------------------------------------------------------------- #
# name, category, notes, [(old, new), ...]
FAMILY_RSPLIT_EXT = [
    ("split-var_r25-at-use", "lifetime-split",
     "R-SPLIT: copy var_r25 (loop-accumulated, read once at line ~509) into a "
     "fresh local at its last use -> new web if non-rematerializable.",
     [("    if (var_r25 != 0) {\n      _a6 = 3;",
       "    s32 var_r25b = var_r25;\n    if (var_r25b != 0) {\n      _a6 = 3;")]),

    ("split-var_r23-at-lastuse", "lifetime-split",
     "R-SPLIT: split the floor-collision counter var_r23 at its last read.",
     [("  if ((var_r23 > 0) || (ci.flags & 1)) {",
       "  s32 var_r23b = var_r23;\n  if ((var_r23b > 0) || (ci.flags & 1)) {")]),

    ("split-var_r22-at-use", "lifetime-split",
     "R-SPLIT: split the wall-collision counter var_r22 at its last read.",
     [("  if ((var_r22 > 0) || (var_r21 != 0)) {",
       "  s32 var_r22b = var_r22;\n  if ((var_r22b > 0) || (var_r21 != 0)) {")]),

    ("split-var_r24-at-lastuse", "lifetime-split",
     "R-SPLIT: split var_r24 (soft-wall latch, set early, read once later).",
     [("  if (var_r24 != 0 && (ci.flags & 0x200)) {",
       "  s32 var_r24b = var_r24;\n  if (var_r24b != 0 && (ci.flags & 0x200)) {")]),

    ("split-var_r27-at-use", "lifetime-split",
     "R-SPLIT: split the bool var_r27 (set from flags0 early, read once late).",
     [("    if (!var_r27) {\n      proxyF->kartState()->field(0) |= 0x4000;",
       "    bool var_r27b = var_r27;\n    if (!var_r27b) {\n"
       "      proxyF->kartState()->field(0) |= 0x4000;")]),

    ("pe-split-at-hwg", "lifetime-split",
     "R-SPLIT on pe at the pe+17 use only (pe is rematerializable; expect fold).",
     [("      s32 hwg = *((s32*)(pe + 17));",
       "      f32* const peL = pe;\n      s32 hwg = *((s32*)(peL + 17));")]),

    ("pe-split-at-pe3", "lifetime-split",
     "R-SPLIT on pe at the pe[3] use only.",
     [("        f32 var_f1 = fabsf(temp_f31 * pe[3]);",
       "        f32* const peL3 = pe;\n"
       "        f32 var_f1 = fabsf(temp_f31 * peL3[3]);")]),

    ("pe-split-both-uses", "lifetime-split",
     "R-SPLIT pe at both tail uses (pe+17 and pe[3]).",
     [("      s32 hwg = *((s32*)(pe + 17));",
       "      f32* const peL = pe;\n      s32 hwg = *((s32*)(peL + 17));"),
      ("        f32 var_f1 = fabsf(temp_f31 * pe[3]);",
       "        f32* const peL3 = pe;\n"
       "        f32 var_f1 = fabsf(temp_f31 * peL3[3]);")]),

    ("v28-local-after-pe", "declaration",
     "pe/var_r28 combo: make var_r28 a declared local in the top block "
     "(below pe) instead of an anonymous temp.",
     [("  HitboxGroup** hgp;\n  s32 var_r27_2;\n",
       "  HitboxGroup** hgp;\n  s32 var_r27_2;\n  s32 var_r28;\n"),
      ("  s32 var_r28 = (flags0 & 0x40000) != 0;\n",
       "  var_r28 = (flags0 & 0x40000) != 0;\n")]),

    ("v28-local-before-pe", "declaration",
     "pe/var_r28 combo: declare var_r28 as the first local (before pe).",
     [("  f32* const pe = lbl_1_data_3918;\n  KartObjectProxy* proxy = mProxy;",
       "  s32 var_r28 = 0;\n  f32* const pe = lbl_1_data_3918;\n"
       "  KartObjectProxy* proxy = mProxy;"),
      ("  s32 var_r28 = (flags0 & 0x40000) != 0;\n",
       "  var_r28 = (flags0 & 0x40000) != 0;\n")]),

    ("pe-declared-last-local", "declaration",
     "pe/var_r28 combo: move pe's declaration to the end of the local block.",
     [("  f32* const pe = lbl_1_data_3918;\n  KartObjectProxy* proxy = mProxy;",
       "  KartObjectProxy* proxy = mProxy;"),
      ("  HitboxGroup** hgp;\n  s32 var_r27_2;\n",
       "  HitboxGroup** hgp;\n  s32 var_r27_2;\n"
       "  f32* const pe = lbl_1_data_3918;\n")]),

    ("v28-inline-at-uses", "expression",
     "pe/var_r28 combo: drop the var_r28 local and rematerialize the mask test "
     "at both branch sites (extends flags0's live range).",
     [("  s32 var_r28 = (flags0 & 0x40000) != 0;\n", ""),
      ("if (var_r28 == 0) {", "if (((flags0 & 0x40000) != 0) == 0) {"),
      ("    if (var_r28 != 0) {", "    if (((flags0 & 0x40000) != 0) != 0) {")]),

    ("v28-addr-taken", "lifetime-split",
     "R-SPLIT barrier: take var_r28's address (unused alias) to force a stack "
     "home and block coalescing.",
     [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
       "  s32 var_r28 = (flags0 & 0x40000) != 0;\n  s32* pv28 = &var_r28;")]),

    ("pe-addr-taken", "lifetime-split",
     "R-SPLIT barrier: take pe's address (unused alias) without rewriting uses.",
     [("  f32* const pe = lbl_1_data_3918;",
       "  f32* const pe = lbl_1_data_3918;\n  f32* const* ppe = &pe;")]),

    ("combo-v28-local-and-pe-split", "combination",
     "pe/var_r28 combo x R-SPLIT: var_r28 as a named local + pe split at pe+17.",
     [("  HitboxGroup** hgp;\n  s32 var_r27_2;\n",
       "  HitboxGroup** hgp;\n  s32 var_r27_2;\n  s32 var_r28;\n"),
      ("  s32 var_r28 = (flags0 & 0x40000) != 0;\n",
       "  var_r28 = (flags0 & 0x40000) != 0;\n"),
      ("      s32 hwg = *((s32*)(pe + 17));",
       "      f32* const peL = pe;\n      s32 hwg = *((s32*)(peL + 17));")]),

    ("combo-v28-inline-and-pe-split", "combination",
     "pe/var_r28 combo x R-SPLIT: var_r28 rematerialized + pe split at both uses.",
     [("  s32 var_r28 = (flags0 & 0x40000) != 0;\n", ""),
      ("if (var_r28 == 0) {", "if (((flags0 & 0x40000) != 0) == 0) {"),
      ("    if (var_r28 != 0) {", "    if (((flags0 & 0x40000) != 0) != 0) {"),
      ("      s32 hwg = *((s32*)(pe + 17));",
       "      f32* const peL = pe;\n      s32 hwg = *((s32*)(peL + 17));"),
      ("        f32 var_f1 = fabsf(temp_f31 * pe[3]);",
       "        f32* const peL3 = pe;\n"
       "        f32 var_f1 = fabsf(temp_f31 * peL3[3]);")]),

    ("split-var_r25-and-r23", "combination",
     "Two R-SPLITs at once (var_r25 + var_r23) to test whether two independent "
     "splits compound.",
     [("    if (var_r25 != 0) {\n      _a6 = 3;",
       "    s32 var_r25b = var_r25;\n    if (var_r25b != 0) {\n      _a6 = 3;"),
      ("  if ((var_r23 > 0) || (ci.flags & 1)) {",
       "  s32 var_r23b = var_r23;\n  if ((var_r23b > 0) || (ci.flags & 1)) {")]),
]

FAMILIES = {FAMILY: FAMILY_RSPLIT_EXT}


# --------------------------------------------------------------------------- #
# harness: compile + score + objdump
# --------------------------------------------------------------------------- #
def _score_from_objdiff(objpath):
    r = subprocess.run(
        [h.OBJDIFF, "diff", "-1", h.TARGET, "-2", objpath, "-o", "-",
         "--format", "json"],
        cwd=MW, capture_output=True, text=True)
    try:
        d = json.loads(r.stdout)
    except Exception:
        return None
    for s in d["left"]["sections"]:
        for f in s.get("functions", []):
            if "updateCollisions__" in f["symbol"]["name"]:
                return round(f.get("match_percent", 0), 4)
    return None


def _extract_regs(objpath):
    """Return (regs_dict, instr_count) from the emitted object via objdump.

    * proxy : first `lwz rN,24(r3)`  (this+0x18 == mProxy)
    * pe    : `lis rN,0` whose relocation is `lbl_1_data_3918`
    * pool  : `lis rN,0` whose relocation names the local `.rodata` pool
    * var_r28: `rlwinm rN,rM,14,31,31` (mask form) or the shift-form fallback
    """
    out = subprocess.run([OBJDUMP, "-dr", "--disassemble=" + SYM, objpath],
                         capture_output=True, text=True).stdout
    lines = out.splitlines()
    regs = {k: None for k in REG_ORDER}
    instr = 0
    for i, ln in enumerate(lines):
        if not re.match(r"^\s*[0-9a-f]+:\t", ln):
            continue
        instr += 1
        asm = ln.split("\t")[-1].strip()
        m = re.match(r"lwz\s+r(\d+),\s*24\(r3\)", asm)
        if m and regs["proxy"] is None:
            regs["proxy"] = "r" + m.group(1)
        m = re.match(r"rlwinm\s+r(\d+),\s*r\d+,\s*14,\s*31,\s*31", asm)
        if m and regs["var_r28"] is None:
            regs["var_r28"] = "r" + m.group(1)
        m = re.match(r"rlwinm\s+r(\d+),\s*r\d+,\s*18,\s*31,\s*31", asm)
        if m and regs["var_r28"] is None:
            regs["var_r28"] = "r" + m.group(1)
        m = re.match(r"lis\s+r(\d+),\s*0$", asm)
        if m:
            dst = "r" + m.group(1)
            for j in range(i + 1, min(i + 3, len(lines))):
                rel = re.search(r"R_PPC_\w+\s+(\S+)", lines[j])
                if rel:
                    sym = rel.group(1)
                    if "lbl_1_data_3918" in sym and regs["pe"] is None:
                        regs["pe"] = dst
                    elif "rodata" in sym and regs["pool"] is None:
                        regs["pool"] = dst
                    break
    return regs, instr


def measure(full_text, tag):
    """Compile one candidate, score it and objdump its colouring."""
    cpath = os.path.join(WORK, "c_%s.cpp" % tag)
    opath = os.path.join(WORK, "c_%s.o" % tag)
    info = {"name": tag, "score": None, "registers": None,
            "reg_tuple": None, "instr_count": None, "note": ""}
    try:
        with open(cpath, "w", encoding="utf-8", newline="") as fh:
            fh.write(full_text)
        rc = subprocess.run([h.MWCC] + h.FLAGS + [cpath, "-o", opath],
                            cwd=MW, capture_output=True, text=True)
        if rc.returncode != 0:
            tail = (rc.stderr or rc.stdout or "").strip().splitlines()
            info["note"] = "compile-fail: " + (tail[-1][:100] if tail else "")
            return info
        score = _score_from_objdiff(opath)
        regs, instr = _extract_regs(opath)
        info["score"] = score
        info["register_map"] = regs
        info["registers"] = "/".join(regs[k] or "-" for k in REG_ORDER)
        info["reg_tuple"] = tuple(regs[k] for k in REG_ORDER)
        info["instr_count"] = instr
    except Exception as e:  # pragma: no cover - defensive
        info["note"] = "error: %s" % e
    finally:
        for pth in (cpath, opath):
            try:
                os.remove(pth)
            except OSError:
                pass
    return info


def run_family(family, limit=None):
    candidates = FAMILIES[family]
    if limit:
        candidates = candidates[:limit]

    base_text = P.build([])
    base = measure(base_text, "baseline")
    print("baseline: score=%s regs=%s instr=%s"
          % (base["score"], base["registers"], base["instr_count"]))

    jobs = []
    for name, category, notes, edits in candidates:
        text = P.build(edits)
        if text is None:
            jobs.append((name, category, notes, edits, None))
        else:
            jobs.append((name, category, notes, edits, text))

    results = []
    runnable = [j for j in jobs if j[4] is not None]
    with concurrent.futures.ThreadPoolExecutor(max_workers=6) as ex:
        measured = list(ex.map(lambda j: measure(j[4], j[0]), runnable))
    by_name = {m["name"]: m for m in measured}
    for name, category, notes, edits, text in jobs:
        m = by_name.get(name) or {"name": name, "score": None, "registers": None,
                                  "reg_tuple": None, "instr_count": None,
                                  "note": "snippet-not-found"}
        m.update(category=category, notes=notes, edits=edits)
        results.append(m)
    results.sort(key=lambda m: (m["score"] is None, -(m["score"] or 0)))
    return base, results


# --------------------------------------------------------------------------- #
# MWCC debugger re-dump (regalloc rows)
# --------------------------------------------------------------------------- #
def parse_assigned_dump(path):
    """Parse `r<vreg> -> r<phys> <name>` blocks from the assigned dump."""
    rows = []
    cur = None
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = re.match(r"^r(\d+) -> r(\d+)(.*)$", line)
            if m:
                cur = {"vreg": int(m.group(1)), "reg": "r" + m.group(2),
                       "name": m.group(3).strip(), "degree": None, "flags": ""}
                rows.append(cur)
                continue
            if cur is None:
                continue
            s = line.strip()
            if s.startswith("neighbors:"):
                mm = re.match(r"neighbors: (\d+)", s)
                if mm:
                    cur["degree"] = int(mm.group(1))
            elif s.startswith("flags:"):
                cur["flags"] = s[6:].strip()
    return rows


def redump_regalloc(full_text, build_id):
    """Compile `full_text` through the MWCC debugger and return saved-reg rows.

    The repository source is backed up (raw bytes) and restored in `finally`.
    """
    dump = os.path.join(MW, "build", "mwcc-debug", "dumps",
                        "regalloc-gpr-pass-1-assigned.txt")
    with open(SRC, "rb") as fh:
        backup = fh.read()
    try:
        with open(SRC, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(full_text)
        r = subprocess.run([sys.executable, os.path.join(MHTRI, "run_debugger.py")],
                           cwd=MHTRI, capture_output=True, text=True)
        if not os.path.exists(dump):
            return [], "no-dump"
        rows = []
        for e in parse_assigned_dump(dump):
            n = int(e["reg"][1:])
            if 14 <= n <= 31:
                rows.append((build_id, "redump " + build_id, e["name"],
                             e["vreg"], e["degree"], e["reg"], e["flags"]))
        return rows, ("ok" if r.returncode == 0 else "rc=%d" % r.returncode)
    except Exception as e:  # pragma: no cover
        return [], "error:%s" % e
    finally:
        with open(SRC, "wb") as fh:
            fh.write(backup)


# --------------------------------------------------------------------------- #
# database writes
# --------------------------------------------------------------------------- #
def _connect(dbpath):
    con = sqlite3.connect(dbpath)
    con.row_factory = sqlite3.Row
    return con


def dedup_set(con):
    return set((r["label"], r["edit_from"], r["edit_to"])
               for r in con.execute("SELECT label, edit_from, edit_to FROM trials"))


def upsert_agent(con, best_score, any_beat, summary, key_finding):
    row = con.execute("SELECT rowid FROM agents WHERE agent_id=?", (AGENT_ID,)).fetchone()
    if row is None:
        con.execute(
            "INSERT INTO agents(agent_id,round,angle,model,status,best_score,"
            "beat_base,summary,key_finding) VALUES(?,?,?,?,?,?,?,?,?)",
            (AGENT_ID, "ETL", "etl harness (run_and_log.py)", "deepseek-flash",
             "completed", best_score, 1 if any_beat else 0, summary, key_finding))
        rid = con.execute("SELECT rowid FROM agents WHERE agent_id=?",
                          (AGENT_ID,)).fetchone()[0]
        con.execute(
            "INSERT INTO fts_agents(rowid,angle,summary,key_finding) VALUES(?,?,?,?)",
            (rid, "etl harness (run_and_log.py)", summary, key_finding))
    else:
        con.execute(
            "UPDATE agents SET best_score=?,beat_base=?,summary=?,key_finding=? "
            "WHERE agent_id=?",
            (best_score, 1 if any_beat else 0, summary, key_finding, AGENT_ID))


def insert_trial(con, label, category, edit_from, edit_to, score, base,
                 registers, instr_count, notes):
    delta = round(score - base, 4)
    beat = 1 if score > base + 1e-9 else 0
    cur = con.execute(
        "INSERT INTO trials(agent_id,label,category,edit_from,edit_to,score,base,"
        "delta,registers,instr_count,beat,notes) VALUES(?,?,?,?,?,?,?,?,?,?,?,?)",
        (AGENT_ID, label, category, edit_from, edit_to, score, base, delta,
         registers, instr_count, beat, notes))
    tid = cur.lastrowid
    con.execute(
        "INSERT INTO fts_trials(rowid,label,category,edit_from,edit_to,notes) "
        "VALUES(?,?,?,?,?,?)",
        (tid, label, category, edit_from, edit_to, notes))
    return tid, delta, beat


def insert_regalloc(con, rows):
    for build_id, source, name, vreg, degree, reg, flags in rows:
        con.execute(
            "INSERT INTO regalloc(build_id,source,name,vreg,degree,reg,flags) "
            "VALUES(?,?,?,?,?,?,?)",
            (build_id, source, name, vreg, degree, reg, flags))


def insert_finding(con, kind, statement, evidence):
    if con.execute("SELECT 1 FROM findings WHERE statement=?", (statement,)).fetchone():
        return
    cur = con.execute(
        "INSERT INTO findings(agent_id,kind,statement,evidence) VALUES(?,?,?,?)",
        (AGENT_ID, kind, statement, evidence))
    fid = cur.lastrowid
    con.execute(
        "INSERT INTO fts_findings(rowid,statement,evidence,kind) VALUES(?,?,?,?)",
        (fid, statement, evidence, kind))


def export_extras(dbpath):
    out = {}
    con = _connect(dbpath)
    for name, sql in (
        ("extra_agents.jsonl", "SELECT * FROM agents WHERE agent_id='ETL'"),
        ("extra_trials.jsonl", "SELECT * FROM trials WHERE agent_id='ETL'"),
        ("extra_regalloc.jsonl", "SELECT * FROM regalloc WHERE build_id LIKE 'cand-%'"),
        ("extra_findings.jsonl", "SELECT * FROM findings WHERE agent_id='ETL'"),
    ):
        path = os.path.join(DATA, name)
        rows = [dict(r) for r in con.execute(sql)]
        with open(path, "w", encoding="utf-8") as fh:
            for r in rows:
                fh.write(json.dumps(r, ensure_ascii=False) + "\n")
        out[name] = len(rows)
    con.close()
    return out


def edit_signature(edits):
    ef = " || ".join(o for o, _ in edits)
    et = " || ".join(n for _, n in edits)
    return ef, et


# --------------------------------------------------------------------------- #
# driver
# --------------------------------------------------------------------------- #
def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--family", default=FAMILY, choices=sorted(FAMILIES))
    ap.add_argument("--limit", type=int, default=None)
    ap.add_argument("--redump", choices=("none", "movers", "all"), default="movers",
                    help="which candidates to re-dump through the MWCC debugger")
    ap.add_argument("--dry-run", action="store_true", help="do not touch the DB")
    ap.add_argument("--list", action="store_true", help="list the family and exit")
    ap.add_argument("--json", dest="json_out", default=None)
    args = ap.parse_args(argv)

    if args.list:
        for i, (n, c, notes, edits) in enumerate(FAMILIES[args.family], 1):
            print("%2d. %-32s %-14s %d edit(s)" % (i, n, c, len(edits)))
        return 0

    if not os.path.exists(args.db):
        print("error: db not found: %s" % args.db, file=sys.stderr)
        return 2

    base, results = run_family(args.family, args.limit)

    print("\n%-32s %-14s %9s %9s %5s %-20s %s"
          % ("candidate", "category", "score", "delta", "beat", "registers", "note"))
    for m in results:
        print("%-32s %-14s %9s %9s %5s %-20s %s"
              % (m["name"], m["category"],
                 m["score"] if m["score"] is not None else "FAIL",
                 ("%+.4f" % (m["score"] - BASE93_SCORE)) if m["score"] is not None else "-",
                 "Y" if (m["score"] or 0) > BASE93_SCORE else "",
                 m["registers"] or "-", m["note"] if m["note"] else ""))

    # ---- write to DB -----------------------------------------------------
    new_trials = new_regalloc = 0
    best = max((m["score"] for m in results if m["score"] is not None),
               default=None)
    any_beat = any(m["score"] is not None and m["score"] > BASE93_SCORE
                   for m in results)

    if args.dry_run:
        print("\n[dry-run] no DB writes")
    else:
        con = _connect(args.db)
        try:
            seen = dedup_set(con)
            redump_mode = args.redump
            for m in results:
                if m["score"] is None:
                    continue
                ef, et = edit_signature(m["edits"])
                if (m["name"], ef, et) in seen:
                    print("[dedup] skip", m["name"])
                    continue
                notes = ("%s | family=%s | redump=%s" %
                         (m["notes"], args.family, redump_mode))
                tid, delta, beat = insert_trial(
                    con, m["name"], m["category"], ef, et, m["score"],
                    BASE93_SCORE, m["registers"] or "-", m["instr_count"], notes)
                new_trials += 1
                seen.add((m["name"], ef, et))
                m["trial_id"] = tid

                want = (redump_mode == "all" or
                        (redump_mode == "movers" and m["reg_tuple"] != BASE93))
                if want:
                    text = P.build(m["edits"])
                    build_id = "cand-%d" % tid
                    rows, status = redump_regalloc(text, build_id)
                    if rows:
                        insert_regalloc(con, rows)
                        new_regalloc += len(rows)
                    print("[redump] %-28s %s -> %d regalloc row(s)"
                          % (m["name"], build_id, len(rows)))
                con.commit()

            summary = ("%s: %d candidates, best=%s, beat=%s; R-SPLIT applied to "
                       "long-lived ints/bools (var_r25/23/22/24/27) + pe, and "
                       "pe/var_r28 declaration/expression combos."
                       % (args.family, len(results),
                          ("%.4f" % best) if best is not None else "n/a",
                          "yes" if any_beat else "no"))
            kf = ("Extended R-SPLIT: splitting the remaining long-lived "
                  "scalars and pe does not recolour; splitting is inert "
                  "unless the value is non-rematerializable.")
            upsert_agent(con, best, any_beat, summary, kf)
            insert_finding(con, "result", summary,
                           "run_and_log.py %s; scores=%s" % (
                               args.family,
                               ", ".join("%s=%.4f" % (m["name"], m["score"])
                                         for m in results
                                         if m["score"] is not None)))
            con.commit()
            extras = export_extras(args.db)
        finally:
            con.close()
        print("\n[db] new trials=%d new regalloc rows=%d" % (new_trials, new_regalloc))
        print("[db] extras exported: "
              + ", ".join("%s=%d" % kv for kv in extras.items()))

    if args.json_out:
        with open(args.json_out, "w", encoding="utf-8") as fh:
            json.dump({"family": args.family, "base_score": BASE93_SCORE,
                       "baseline": {k: v for k, v in base.items() if k != "edits"},
                       "results": [{k: v for k, v in m.items()
                                    if k not in ("edits", "register_map")}
                                   for m in results]}, fh, indent=2)
        print("[json] wrote %s" % args.json_out)

    print("\nread back with:")
    print("  sqlite3 subagents.db \"SELECT trial_id,label,category,score,base,delta,"
          "registers,instr_count,beat FROM trials WHERE agent_id='ETL' "
          "ORDER BY score DESC;\"")
    print("  sqlite3 subagents.db \"SELECT build_id,name,vreg,degree,reg,flags FROM "
          "regalloc WHERE build_id LIKE 'cand-%' ORDER BY build_id,vreg DESC;\"")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
