#!/usr/bin/env python3
"""autoloop.py -- automated hypothesise -> test -> log -> refine loop for
`KartState::updateCollisions` (Mario Kart Wii matching decomp, MWCC Wii/0x4201_127).

This tool CHAINS the existing subagent_data tools into one closed loop:

  hypothesise   kb_retrieval.propose_hypotheses()  (novel mechanism x node)
                + analyze_db.untried_levers()      (concrete category x token edits)
                + regstate_graph.candidate_library (CURRENT->TARGET move edits)
                + colour_solver.HARNESS_CANDIDATES
                + hypotheses_uc.HYPOTHESES
                -> one deduplicated candidate pool of concrete source edits.

  test          run_and_log.measure()  (compile via probe.build + objdiff score
                + objdump extraction of the "pe/var_r28/proxy/pool" colour tuple).

  log           rows written BACK into subagents.db with provenance
                agent_id='AUTOLOOP' (trials, agents, findings, regalloc), the
                FTS5 indexes refreshed, and every row mirrored to the canonical
                extra_*.jsonl so `build_db.py` merges them on rebuild.

  refine        regstate_graph.build_graph() + colour_solver solve on the GROWN
                db decide the next round: if the target colouring is still
                unreachable / UNSAT, the best new mover is crossed with the
                remaining untried levers to seed round r+1.

Deterministic: candidates are ordered by (novel mechanism x node bucket,
predicted pull, mechanism, node, name); edits are deduplicated by their exact
(old,new) signature; no randomness is used. The repository source is never left
modified: a byte-for-byte backup of src/kart/KartState.cpp is taken at start and
restored in a finally block (the regalloc re-dump temporarily rewrites it, as
run_and_log.redump_regalloc already restores byte-for-byte).

Usage:
    python autoloop.py --rounds 4 --budget 20
    python autoloop.py --rounds 4 --budget 20 --redump movers --json out.json
    python autoloop.py --dry-run            # hypothesise + test, no DB writes
    python autoloop.py --list               # show the candidate pool, run nothing
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sqlite3
import sys
import time

# --------------------------------------------------------------------------- #
# paths / harness
# --------------------------------------------------------------------------- #
HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.dirname(HERE)
DEFAULT_DB = os.path.join(DATA, "subagents.db")
PERM = os.path.join(os.environ.get("TEMP", ""), "opencode", "perm")
MW = r"C:\Users\nnnn\Documents\mkwii"
SRC = os.path.join(MW, "src", "kart", "KartState.cpp")

sys.path.insert(0, PERM)
sys.path.insert(0, HERE)

import probe as P               # noqa: E402
import analyze_db as AD         # noqa: E402
import kb_retrieval as KB       # noqa: E402
import run_and_log as RL        # noqa: E402
import regstate_graph as RG     # noqa: E402
import colour_solver as CS      # noqa: E402

try:
    import hypotheses_uc as HU  # noqa: E402
except Exception:               # pragma: no cover - optional source
    HU = None

# --------------------------------------------------------------------------- #
# domain constants + provenance
# --------------------------------------------------------------------------- #
AGENT_ID = "AUTOLOOP"
ROUND_TAG = "AUTOLOOP"
ANGLE = "automated tool-chain loop (autoloop.py)"
MODEL = "deepseek-flash"

BASE = float(AD.BASE93_SCORE)           # 93.4368
BASE93 = tuple(AD.BASE93)               # ("r28","r30","r26","r29")
TARGET = tuple(AD.TARGET)               # ("r30","r28","r26","r29")
REG_ORDER = ("pe", "var_r28", "proxy", "pool")

# stamp the shared ETL row-writers with AUTOLOOP provenance
RL.AGENT_ID = AGENT_ID

# canonical extra_*.jsonl files that build_db.py merges on rebuild
EXTRA_TRIALS = os.path.join(DATA, "extra_trials.jsonl")
EXTRA_AGENTS = os.path.join(DATA, "extra_agents.jsonl")
EXTRA_FINDINGS = os.path.join(DATA, "extra_findings.jsonl")
EXTRA_REGALLOC = os.path.join(DATA, "extra_regalloc.jsonl")

# --------------------------------------------------------------------------- #
# candidate pool
# --------------------------------------------------------------------------- #
# source anchors in the current 93.4368 body
D_PE = "  f32* const pe = lbl_1_data_3918;\n"
D_PROXY = "  KartObjectProxy* proxy = mProxy;\n"
D_PPROXY = "  KartObjectProxy** pproxy = &proxy;\n"
I_FLAGS0 = "  u32 flags0 = (*pproxy)->kartState()->field(0);\n"
I_V28 = "  s32 var_r28 = (flags0 & 0x40000) != 0;\n"
I_V27 = "  bool var_r27 = (flags0 & 0x60) != 0;\n"
I_PROXYF = "  KartObjectProxy* proxyF = proxy;\n"
I_CIFLAGS = "  u32 f = ci.flags;\n"
CI4 = "  if ((ci.flags & 4) && (field(1) & 0x200) &&"
PIDX_DECL = "          s32 playerIdx = proxyF->getPlayerIdx();\n"
PIDX_CALL = "(rm->raceMode, (u8)playerIdx)"
GM_DECL = "          s32 gameMode = rc->mRaceScenario.mSettings.mGameMode;\n"
GM9 = "          } else if (!(gameMode != 9 && gameMode != 10)) {"
TAIL = "  proxyF->kartWheelPhysics(0);\n  proxyF->getPos();\n"
PE3_BLOCK = ("        f32 var_f1 = fabsf(temp_f31 * pe[3]);\n"
             "        if (1.0f < var_f1) {\n"
             "          var_f1 = 1.0f;\n"
             "        }\n")

# explicit mechanism x node crossings not yet present in `trials`
EXPLICIT = [
    # (name, mechanism, node, category, notes, edits)
    ("split-flags0-second-load", "R-SPLIT", "flags0", "lifetime-split",
     "R-SPLIT x flags0: a second independent field(0) load for var_r27 so it "
     "cannot be CSE'd/rematerialized against flags0.",
     [(I_V27, "  u32 flags0b = (*pproxy)->kartState()->field(0);\n"
              "  bool var_r27 = (flags0b & 0x60) != 0;\n")]),

    ("split-ci-flags-alias", "R-SPLIT", "ci.flags", "lifetime-split",
     "R-SPLIT x ci.flags: a long-lived alias of the loaded ci.flags mask used "
     "later, creating an overlapping second web.",
     [(I_CIFLAGS, I_CIFLAGS + "  u32 fAlias = f;\n"),
      (CI4, "  if ((fAlias & 4) && (field(1) & 0x200) &&")]),

    ("split-gamemode-alias", "R-SPLIT", "gameMode", "lifetime-split",
     "R-SPLIT x gameMode: a long-lived alias of the race gameMode read again in "
     "the 9/10 branch.",
     [(GM_DECL, GM_DECL + "          s32 gmAlias = gameMode;\n"),
      (GM9, "          } else if (!(gmAlias != 9 && gmAlias != 10)) {")]),

    ("split-pool-second-literal", "R-SPLIT", "pool", "lifetime-split",
     "R-SPLIT x pool: a new rodata float literal (3.25f) used late, creating a "
     "second constant-pool web that must be coloured.",
     [(PE3_BLOCK,
       "        f32 var_f1 = fabsf(temp_f31 * pe[3]);\n"
       "        if (3.25f < var_f1) {\n"
       "          var_f1 = 3.25f;\n"
       "        }\n")]),

    ("order-proxy-third-web-tail", "R-COLOR-ORDER", "proxy", "coalescing",
     "R-COLOR-ORDER x proxy: a third proxy web for the two tail calls, extending "
     "the winning proxyF split to probe colour ordering.",
     [(I_PROXYF, I_PROXYF + "  KartObjectProxy* proxyG = proxyF;\n"),
      (TAIL, "  proxyG->kartWheelPhysics(0);\n  proxyG->getPos();\n")]),

    ("vregblocks-gamemode-early", "R-VREG-BLOCKS", "gameMode", "declaration",
     "R-VREG-BLOCKS x gameMode: hoist the gameMode read to a named local next to "
     "flags0 so it joins the declared block ordering.",
     [(I_V28, I_V28 + "  s32 gameModeEarly;\n"),
      (GM_DECL, "          gameModeEarly = rc->mRaceScenario.mSettings.mGameMode;\n"
                "          s32 gameMode = gameModeEarly;\n")]),

    ("order-flags0-promote", "R-COLOR-ORDER", "flags0", "declaration",
     "R-COLOR-ORDER x flags0: declare flags0 as a named long-lived local before "
     "pe, probing whether a load can out-rank the pool.",
     [(D_PE, "  u32 flags0;\n" + D_PE),
      (I_FLAGS0, "  flags0 = (*pproxy)->kartState()->field(0);\n")]),

    ("order-ciflags-longlived", "R-COLOR-ORDER", "ci.flags", "declaration",
     "R-COLOR-ORDER x ci.flags: promote the loaded ci.flags mask to a long-lived "
     "address-taken web so it can be coloured/ordered against the pool.",
     [(I_CIFLAGS, I_CIFLAGS + "  u32 fEarly = f;\n  u32* pfEarly = &fEarly;\n"),
      ("  if ((f & 0x42) && var_r4 == 0) {",
       "  if ((*pfEarly & 0x42) && var_r4 == 0) {")]),

    ("order-gamemode-longlived", "R-COLOR-ORDER", "gameMode", "declaration",
     "R-COLOR-ORDER x gameMode: promote gameMode to a long-lived address-taken "
     "web so it can be coloured/ordered against the pool.",
     [(GM_DECL, GM_DECL + "          s32* pgmEarly = &gameMode;\n"),
      (GM9, "          } else if (!(*pgmEarly != 9 && *pgmEarly != 10)) {")]),
]


def _edit_sig(edits):
    """run_and_log-compatible signature (matches trials.edit_from / edit_to)."""
    return RL.edit_signature([tuple(e) for e in edits])


def _slug(name):
    return re.sub(r"[^A-Za-z0-9_.-]", "_", name)[:64]


def _infer_node(text):
    low = text.lower()
    for node, toks in KB.NODE_TOKENS.items():
        if any(t in low for t in toks):
            return node
    return "pe"


def _infer_mech(text):
    low = text.lower()
    for mech, toks in KB.MECHANISM_TOKENS.items():
        if any(t in low for t in toks):
            return mech
    return "R-SPLIT"


class Pool:
    def __init__(self):
        self._seen = set()
        self.items = []

    def add(self, name, mech, node, category, notes, edits, source, pull=0.0):
        edits = [[o, n] for o, n in edits]
        try:
            key = _edit_sig(edits)
        except Exception:
            return None
        if key in self._seen:
            return None
        self._seen.add(key)
        item = {"name": name, "mech": mech, "node": node, "category": category,
                "notes": notes, "edits": edits, "source": source,
                "pull": round(pull, 4), "sig": key}
        self.items.append(item)
        return item


def assemble_pool(db):
    """Union of every concrete-edit source, deterministic order."""
    pool = Pool()

    # 1. explicit new crossings -> highest priority (they are the concretely
    #    authored novel mechanism x node hypotheses) ------------------------ #
    for name, mech, node, cat, notes, edits in EXPLICIT:
        pool.add(name, mech, node, cat, notes, edits, "explicit", pull=9.0)

    # 2. regstate_graph candidate library (CURRENT -> TARGET moves) ------- #
    for c in RG.candidate_library():
        node = "pe" if ("pe" in c["name"] or "pe" in c["intent"]) else "var_r28"
        mech = ("R-VREG-BLOCKS" if "local" in c["name"].lower()
                else "R-SPLIT" if "split" in c["name"].lower() or "addr" in c["name"].lower()
                else "R-COLOR-ORDER")
        pool.add("rg-" + c["name"], mech, node, "combination",
                 "[regstate_graph] " + c["intent"], c["edits"], "regstate_graph",
                 pull=3.0)

    # 3. colour_solver harness candidates -------------------------------- #
    for name, edits in CS.HARNESS_CANDIDATES:
        if not edits:
            continue
        pool.add("cs-" + name, _infer_mech(name), _infer_node(name), "combination",
                 "[colour_solver] target-move probe", edits, "colour_solver", pull=2.0)

    # 4. hypotheses_uc retrieval-driven batch ---------------------------- #
    if HU is not None:
        for name, desc, edits in HU.HYPOTHESES:
            pool.add("hu-" + name, _infer_mech(name + " " + desc),
                     _infer_node(name + " " + desc), "combination",
                     "[hypotheses_uc] " + desc, edits, "hypotheses_uc", pull=2.5)

    # 5. analyze_db untried levers (concrete category x token edits) ------ #
    data = AD.load(db)
    trials = data["trials_joined"]
    tok_stats, _ = AD.token_correlation(trials)
    levers = AD.untried_levers(trials, tok_stats, AD.delta_by_category(trials),
                               top=200)
    for lev in levers:
        tok = lev["token"]
        mech = {
            "split": "R-SPLIT", "addr": "R-SPLIT", "volatile": "R-SPLIT",
            "coalesc": "R-SPLIT", "rematerial": "R-SPLIT", "temp": "R-SPLIT",
            "struct": "R-SPLIT", "loop": "R-SPLIT", "inline": "R-SPLIT",
            "playerIdx": "R-SPLIT", "gameMode": "R-SPLIT",
            "decl": "R-VREG-BLOCKS", "register": "R-COLOR-ORDER",
            "shift": "R-COLOR-ORDER", "mask": "expression",
        }.get(tok, "R-SPLIT")
        for ed in lev["edits"]:
            txt = ed["name"] + " " + " ".join(o for o, _ in ed["edits"])
            node = {"playerIdx": "playerIdx", "gameMode": "gameMode",
                    "mask": "var_r28", "shift": "var_r28"}.get(tok) \
                or _infer_node(txt)
            pool.add("ad-" + ed["name"], mech, node, lev["category"],
                     "[analyze_db] untried %s x %s (pull=%.2f)"
                     % (lev["category"], tok, lev["predicted_pull"]),
                     ed["edits"], "analyze_db", pull=lev["predicted_pull"])

    # deterministic ordering key
    novel = novel_combos(db)
    for it in pool.items:
        it["novel_mech"] = (it["mech"], it["node"]) in novel
    pool.items.sort(key=lambda it: (
        0 if it["novel_mech"] else 1, -it["pull"], it["mech"], it["node"],
        it["name"]))
    return pool, novel


def novel_combos(db):
    kb = KB.Corpus(db)
    return {(h["mechanism"], h["node"])
            for h in KB.propose_hypotheses(kb) if h["novel"]}


def db_signatures(con):
    return {(r[0], r[1]) for r in
            con.execute("SELECT edit_from, edit_to FROM trials")}


# --------------------------------------------------------------------------- #
# DB writes (AUTOLOOP provenance)
# --------------------------------------------------------------------------- #
def upsert_agent(con, best, any_beat, summary, key_finding):
    row = con.execute("SELECT rowid FROM agents WHERE agent_id=?",
                      (AGENT_ID,)).fetchone()
    if row is None:
        con.execute(
            "INSERT INTO agents(agent_id,round,angle,model,status,best_score,"
            "beat_base,summary,key_finding) VALUES(?,?,?,?,?,?,?,?,?)",
            (AGENT_ID, ROUND_TAG, ANGLE, MODEL, "completed", best,
             1 if any_beat else 0, summary, key_finding))
        rid = con.execute("SELECT rowid FROM agents WHERE agent_id=?",
                          (AGENT_ID,)).fetchone()[0]
        con.execute("INSERT INTO fts_agents(rowid,angle,summary,key_finding) "
                    "VALUES(?,?,?,?)", (rid, ANGLE, summary, key_finding))
    else:
        con.execute("UPDATE agents SET best_score=?,beat_base=?,summary=?,"
                    "key_finding=? WHERE agent_id=?",
                    (best, 1 if any_beat else 0, summary, key_finding, AGENT_ID))
        rid = row[0]
        con.execute("UPDATE fts_agents SET angle=?,summary=?,key_finding=? "
                    "WHERE rowid=?", (ANGLE, summary, key_finding, rid))


def insert_regalloc(con, rows):
    for build_id, source, name, vreg, degree, reg, flags in rows:
        con.execute("INSERT INTO regalloc(build_id,source,name,vreg,degree,reg,"
                    "flags) VALUES(?,?,?,?,?,?,?)",
                    (build_id, source, name, vreg, degree, reg, flags))


# --------------------------------------------------------------------------- #
# test one round
# --------------------------------------------------------------------------- #
def run_round(db, pool, con, seen_db, tested_sigs, round_no, budget, redump,
              workers_movers=8):
    """Pick the next batch, measure it, write rows back. Returns
    (results, new_trials, new_regalloc, best, any_beat, refine)."""
    cands = [c for c in pool.items
             if c["sig"] not in seen_db and c["sig"] not in tested_sigs]
    batch = cands[:budget]
    if not batch:
        return [], 0, 0, None, False, None

    results = []
    for c in batch:
        tested_sigs.add(c["sig"])
        text = P.build([tuple(e) for e in c["edits"]])
        if text is None:
            results.append((c, {"name": c["name"], "score": None,
                                "registers": None, "reg_tuple": None,
                                "instr_count": None, "note": "snippet-not-found"}))
            continue
        m = RL.measure(text, _slug(c["name"]))
        results.append((c, m))

    new_trials = new_regalloc = 0
    movers_done = 0
    regalloc_rows_out = []
    trial_rows_out = []
    beat_any = False
    best = None

    for c, m in results:
        if m["score"] is None:
            continue
        best = m["score"] if best is None else max(best, m["score"])
        if m["score"] > BASE + 1e-9:
            beat_any = True
        ef, et = c["sig"]
        notes = ("autoloop r%d mech=%s node=%s src=%s | %s"
                 % (round_no, c["mech"], c["node"], c["source"], c["notes"]))
        tid, delta, beat = RL.insert_trial(
            con, c["name"], c["category"], ef, et, m["score"], BASE,
            m["registers"] or "-", m["instr_count"], notes)
        new_trials += 1
        seen_db.add(c["sig"])
        trial_rows_out.append({
            "agent_id": AGENT_ID, "label": c["name"], "category": c["category"],
            "edit_from": ef, "edit_to": et, "score": m["score"], "base": BASE,
            "delta": delta, "registers": m["registers"] or "-",
            "instr_count": m["instr_count"], "beat": beat, "notes": notes})

        want = (redump != "none") and (
            redump == "all" or (m["reg_tuple"] is not None
                                and m["reg_tuple"] != BASE93))
        if want and movers_done < workers_movers:
            text = P.build([tuple(e) for e in c["edits"]])
            build_id = "autoloop-%d" % tid
            rows, status = RL.redump_regalloc(text, build_id)
            if rows:
                insert_regalloc(con, rows)
                new_regalloc += len(rows)
                regalloc_rows_out.extend(
                    {"build_id": bid, "source": src, "name": n, "vreg": v,
                     "degree": d, "reg": r, "flags": f}
                    for bid, src, n, v, d, r, f in rows)
            movers_done += 1
            print("      [redump] %-44s %-9s -> %d regalloc rows"
                  % (c["name"], status, len(rows)))
        con.commit()

    # summary + refinement finding
    refine = refine_db(db)
    summary = ("%s r%d: %d candidates tested, best=%s, beat=%s; %d new trials, "
               "%d regalloc rows; target reachable=%s solver=%s"
               % (ROUND_TAG, round_no, len(batch),
                  "%.4f" % best if best is not None else "n/a",
                  "yes" if beat_any else "no", new_trials, new_regalloc,
                  refine.get("target_reachable"), refine.get("solver_status")))
    kf = ("Round %d crossed %d novel mechanism x node edits; the grown DB keeps "
          "the target colouring unreachable/UNSAT." % (round_no, new_trials))
    RL.insert_finding(con, "result", summary,
                      "autoloop.py %s; refine=%s" % (ROUND_TAG,
                                                     json.dumps(refine)))
    con.commit()
    finding_rows_out = [{"agent_id": AGENT_ID, "kind": "result",
                         "statement": summary,
                         "evidence": "autoloop.py %s; refine=%s"
                                     % (ROUND_TAG, json.dumps(refine))}]

    export_extras(trial_rows_out, regalloc_rows_out, finding_rows_out)
    return results, new_trials, new_regalloc, best, beat_any, refine


# --------------------------------------------------------------------------- #
# refine: regstate_graph + colour_solver consume the grown DB
# --------------------------------------------------------------------------- #
def refine_db(db):
    info = {}
    try:
        g, _ = RG.build_graph(db)
        cur, tgt = RG.node_str(RG.CURRENT), RG.node_str(RG.TARGET)
        reach = g.reachable(cur)
        info["target_reachable"] = tgt in reach
        info["target_indeg"] = sum(1 for e in g.edges if e.v == tgt)
        info["nodes"] = len(g.nodes)
        info["edges"] = len(g.edges)
        b = g.bfs(cur, tgt)
        info["bfs_path_hops"] = len(b[1]) if b else None
    except Exception as e:  # pragma: no cover
        info["graph_error"] = str(e)
    try:
        webs = CS.load_webs(db)
        _ok1, _m1, res2 = CS.solve_with_z3(webs)
        status2, core2, _m2 = res2
        info["solver_status"] = status2
        info["unsat_core"] = core2
    except Exception as e:  # pragma: no cover
        info["solver_error"] = str(e)
    return info


# --------------------------------------------------------------------------- #
# refine: compose round r+1 from the best mover
# --------------------------------------------------------------------------- #
def compose(pool, best_c, tested_sigs, cap=24):
    """Cross the best novel mover with untried levers to seed the next round."""
    added = 0
    best_olds = {o for o, _ in best_c["edits"]}
    for c in list(pool.items):
        if added >= cap:
            break
        if c["sig"] in tested_sigs:
            continue
        if {o for o, _ in c["edits"]} & best_olds:
            continue        # conflicting anchors -> skip
        name = "cross-%s+%s" % (_slug(best_c["name"]), _slug(c["name"]))
        edits = best_c["edits"] + c["edits"]
        item = pool.add(name, "%s+%s" % (best_c["mech"], c["mech"]),
                        "%s x %s" % (best_c["node"], c["node"]), "combination",
                        "autoloop refinement: cross best mover with %s" % c["name"],
                        edits, "autoloop", pull=best_c["pull"] + 0.5 * c["pull"])
        if item is not None:
            added += 1
    return added


# --------------------------------------------------------------------------- #
# extras mirror (build_db.py merges these on rebuild)
# --------------------------------------------------------------------------- #
def _append_extra(path, rows, keyfn, drop=("trial_id", "id", "finding_id")):
    if not rows:
        return 0
    existing = set()
    if os.path.exists(path):
        with open(path, encoding="utf-8") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                try:
                    existing.add(keyfn(json.loads(line)))
                except Exception:
                    pass
    n = 0
    with open(path, "a", encoding="utf-8") as fh:
        for r in rows:
            k = keyfn(r)
            if k in existing:
                continue
            existing.add(k)
            fh.write(json.dumps({kk: vv for kk, vv in r.items() if kk not in drop},
                                ensure_ascii=False) + "\n")
            n += 1
    return n


def export_extras(trial_rows, regalloc_rows, finding_rows):
    counts = {}
    counts["trials"] = _append_extra(
        EXTRA_TRIALS, trial_rows, lambda r: (r["label"], r["edit_from"], r["edit_to"]))
    counts["findings"] = _append_extra(
        EXTRA_FINDINGS, finding_rows, lambda r: r["statement"])
    counts["regalloc"] = _append_extra(
        EXTRA_REGALLOC, regalloc_rows,
        lambda r: (r["build_id"], r["name"], r["vreg"], r["reg"]))
    return counts


def export_agent(summary, key_finding, best, any_beat):
    row = {"agent_id": AGENT_ID, "round": ROUND_TAG, "angle": ANGLE, "model": MODEL,
           "status": "completed", "best_score": best,
           "beat_base": 1 if any_beat else 0, "summary": summary,
           "key_finding": key_finding}
    _append_extra(EXTRA_AGENTS, [row], lambda r: r["agent_id"])


# (extra file) -> (table, merge columns, WHERE selecting AUTOLOOP rows)
_RESYNC = [
    (EXTRA_TRIALS, "trials",
     ["agent_id", "label", "category", "edit_from", "edit_to", "score", "base",
      "delta", "registers", "instr_count", "beat", "notes"],
     "agent_id='AUTOLOOP'"),
    (EXTRA_AGENTS, "agents",
     ["agent_id", "round", "angle", "model", "status", "best_score", "beat_base",
      "summary", "key_finding"], "agent_id='AUTOLOOP'"),
    (EXTRA_FINDINGS, "findings",
     ["agent_id", "kind", "statement", "evidence"], "agent_id='AUTOLOOP'"),
    (EXTRA_REGALLOC, "regalloc",
     ["build_id", "source", "name", "vreg", "degree", "reg", "flags"],
     "build_id LIKE 'autoloop-%'"),
]


def resync_extras(db):
    """Rewrite the AUTOLOOP rows in the canonical extra_*.jsonl from the live DB,
    preserving every pre-existing (ETL) line. Makes `build_db.py` reproduce the
    live DB exactly. Returns {filename: autoloop_rows_written}."""
    con = sqlite3.connect(db)
    con.row_factory = sqlite3.Row
    out = {}
    for path, table, cols, where in _RESYNC:
        keep = []
        if os.path.exists(path):
            with open(path, encoding="utf-8") as fh:
                for line in fh:
                    line = line.strip()
                    if not line:
                        continue
                    row = json.loads(line)
                    if table == "regalloc":
                        if str(row.get("build_id", "")).startswith("autoloop-"):
                            continue
                    elif row.get("agent_id") == "AUTOLOOP":
                        continue
                    keep.append(line)
        fresh, seen = [], set()
        sql = "SELECT %s FROM %s WHERE %s ORDER BY rowid" % (
            ",".join(cols), table, where)
        for r in con.execute(sql):
            d = {k: r[k] for k in cols}
            j = json.dumps(d, ensure_ascii=False)
            if j in seen:
                continue
            seen.add(j)
            fresh.append(j)
        with open(path, "w", encoding="utf-8") as fh:
            for line in keep:
                fh.write(line + "\n")
            for line in fresh:
                fh.write(line + "\n")
        out[os.path.basename(path)] = len(fresh)
    con.close()
    return out


# --------------------------------------------------------------------------- #
# source guard
# --------------------------------------------------------------------------- #
def _read_src():
    with open(SRC, "rb") as fh:
        return fh.read()


def _restore_src(backup):
    try:
        cur = _read_src()
    except OSError:
        cur = None
    if cur != backup:
        with open(SRC, "wb") as fh:
            fh.write(backup)
        return False
    return True


# --------------------------------------------------------------------------- #
# driver
# --------------------------------------------------------------------------- #
def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--rounds", type=int, default=4)
    ap.add_argument("--budget", type=int, default=20,
                    help="candidates tested per round")
    ap.add_argument("--redump", choices=("none", "movers", "all"), default="movers")
    ap.add_argument("--dry-run", action="store_true", help="do not touch the DB")
    ap.add_argument("--list", action="store_true", help="list the pool and exit")
    ap.add_argument("--resync-extras", action="store_true",
                    help="rewrite AUTOLOOP rows in extra_*.jsonl from the DB and exit")
    ap.add_argument("--json", dest="json_out", default=None)
    args = ap.parse_args(argv)

    if not os.path.exists(args.db):
        print("error: db not found: %s" % args.db, file=sys.stderr)
        return 2

    backup = _read_src()
    t0 = time.time()
    report = {"agent_id": AGENT_ID, "base": BASE, "rounds": [],
              "new_trials": 0, "new_regalloc": 0, "best_score": None,
              "beat_base": False}
    con = None
    overall_best = None
    any_beat = False
    try:
        if args.resync_extras:
            counts = resync_extras(args.db)
            print("resynced extras: " + ", ".join(
                "%s=%d" % kv for kv in sorted(counts.items())))
            return 0

        pool, novel = assemble_pool(args.db)
        print("candidate pool: %d unique concrete edits; %d novel mechanism x node "
              "combos: %s" % (len(pool.items), len(novel), sorted(novel)))
        if args.list:
            for i, c in enumerate(pool.items, 1):
                flag = "NOVEL" if c["novel_mech"] else "     "
                print("%3d. [%s] %-14s %-12s %-46s pull=%.2f src=%s"
                      % (i, flag, c["mech"], c["node"], c["name"], c["pull"],
                         c["source"]))
            return 0

        con = sqlite3.connect(args.db)
        seen_db = db_signatures(con)
        tested_sigs = set()

        for rnd in range(1, args.rounds + 1):
            print("\n== round %d/%d ==" % (rnd, args.rounds))
            if args.dry_run:
                # measure without writing; emulate row bookkeeping locally
                cands = [c for c in pool.items
                         if c["sig"] not in seen_db and c["sig"] not in tested_sigs]
                batch = cands[:args.budget]
                if not batch:
                    print("  pool exhausted")
                    break
                for c in batch:
                    tested_sigs.add(c["sig"])
                    text = P.build([tuple(e) for e in c["edits"]])
                    if text is None:
                        print("  %-46s snippet-not-found" % c["name"])
                        continue
                    m = RL.measure(text, _slug(c["name"]))
                    print("  %-46s score=%-9s regs=%s"
                          % (c["name"], m["score"], m["registers"]))
                    if m["score"] is not None:
                        overall_best = m["score"] if overall_best is None \
                            else max(overall_best, m["score"])
                        any_beat = any_beat or m["score"] > BASE + 1e-9
                report["rounds"].append({"round": rnd, "new_trials": 0,
                                         "best": overall_best, "dry_run": True})
                continue

            results, nt, nr, best, beat, refine = run_round(
                args.db, pool, con, seen_db, tested_sigs, rnd, args.budget,
                args.redump)
            if not results:
                print("  pool exhausted")
                break
            report["new_trials"] += nt
            report["new_regalloc"] += nr
            overall_best = best if overall_best is None else \
                max(overall_best, best or 0)
            any_beat = any_beat or beat
            print("  tested=%d new_trials=%d new_regalloc=%d best=%s beat=%s"
                  % (len(results), nt, nr,
                     "%.4f" % best if best is not None else "n/a",
                     "YES" if beat else "no"))
            print("  refine: %s" % json.dumps(refine, default=str))
            report["rounds"].append({"round": rnd, "tested": len(results),
                                     "new_trials": nt, "new_regalloc": nr,
                                     "best": best, "beat": beat,
                                     "refine": refine})

            # seed the next round from the best mover of this round
            scored = [(c, m) for c, m in results
                      if m["score"] is not None]
            if rnd < args.rounds and scored:
                best_c, best_m = max(
                    scored, key=lambda cm: (cm[1]["score"], cm[0]["pull"],
                                            cm[0]["name"]))
                added = compose(pool, best_c, tested_sigs,
                                cap=args.budget)
                print("  refinement: crossed best mover %r with %d leaders"
                      % (best_c["name"], added))
                # keep pool deterministic after growth
                pool.items.sort(key=lambda it: (
                    0 if it.get("novel_mech") else 1, -it["pull"], it["mech"],
                    it["node"], it["name"]))
            if any_beat:
                print("  !! a candidate beat %.4f -- stopping" % BASE)
                break

        if not args.dry_run and con is not None:
            summary = ("%s: %d rounds, %d candidates, %d new trials, %d regalloc "
                       "rows, best=%s, beat=%s"
                       % (ROUND_TAG, len(report["rounds"]),
                          sum(r.get("tested", 0) for r in report["rounds"]),
                          report["new_trials"], report["new_regalloc"],
                          ("%.4f" % overall_best) if overall_best is not None
                          else "n/a", "yes" if any_beat else "no"))
            kf = ("Automated loop crossed remaining mechanism x node levers on the "
                  "grown DB; target pe=r30/var_r28=r28 stays unreachable.")
            upsert_agent(con, overall_best, any_beat, summary, kf)
            con.commit()
            export_agent(summary, kf, overall_best, any_beat)
            report["summary"] = summary
    finally:
        if con is not None:
            con.close()
        restored = _restore_src(backup)
        if not restored:
            print("[warn] source was rewritten and has been restored from backup")

    report["best_score"] = overall_best
    report["beat_base"] = any_beat
    report["elapsed_s"] = round(time.time() - t0, 1)
    report["src_unchanged"] = _read_src() == backup

    print("\n== summary ==")
    print("  rounds run        : %d" % len(report["rounds"]))
    print("  new trials        : %d" % report["new_trials"])
    print("  new regalloc rows : %d" % report["new_regalloc"])
    print("  best score found  : %s" % report["best_score"])
    print("  beat %.4f        : %s" % (BASE, report["beat_base"]))
    print("  src unchanged     : %s" % report["src_unchanged"])
    print("  elapsed           : %ss" % report["elapsed_s"])

    if args.json_out:
        with open(args.json_out, "w", encoding="utf-8") as fh:
            json.dump(report, fh, indent=2, default=str)
        print("  wrote %s" % args.json_out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
