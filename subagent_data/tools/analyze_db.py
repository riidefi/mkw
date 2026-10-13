#!/usr/bin/env python3
"""analyze_db.py -- statistical / relational analytics over the updateCollisions
subagent dataset (subagents.db).

Pure sqlite3 (no third-party deps). It loads and joins
    trials <-> agents <-> regalloc        (+ findings, rules, FTS)
and emits:

  1. delta by category
  2. distribution of the `registers` tuple ("pe/var_r28/proxy/pool")
  3. which edit TOKENS (edit_from/edit_to/notes) correlate with a register move
  4. regalloc vreg / degree vs trial score
  5. coverage gaps (thin categories, register tuples never reached)
  6. a RANKED list of UNTRIED lever candidates (category x token combinations
     that do not occur in the trials table, scored by how strongly the token /
     category has historically moved a register toward the target colouring
     pe=r30, var_r28=r28), each with a concrete, directly-testable source edit.

The target colouring is pe->r30, var_r28->r28. The 93.4368 winner's colouring is
pe=r28, var_r28=r30 (proxy=r26, pool=r29); the residual is exactly the pe/var_r28
swap that R-VREG-BLOCKS / R-COLOR-ORDER describe.

Usage:
    python analyze_db.py [--db subagents.db] [--top 20] [--json out.json]
"""
from __future__ import annotations

import argparse
import json
import math
import os
import re
import sqlite3
import sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_DB = os.path.join(os.path.dirname(HERE), "subagents.db")

# ----------------------------------------------------------------------------
# Domain constants
# ----------------------------------------------------------------------------
# registers tuple = "pe/var_r28/proxy/pool"
BASE93 = ("r28", "r30", "r26", "r29")   # the 93.4368 winner (base for the residual)
TARGET = ("r30", "r28", "r26", "r29")   # what the retail target wants
BASE93_SCORE = 93.4368

# saved-register colour order: r31 > r30 > r29 > r28 ... (R-COLOR-ORDER)
REG_ORDER = ["r31", "r30", "r29", "r28", "r27", "r26", "r25", "r24",
             "r23", "r22", "r21", "r20", "r19", "r18", "r17", "r16",
             "r15", "r14", "r13", "r12", "r11", "r10", "r9", "r8", "r7",
             "r6", "r5", "r4", "r3"]

STOPWORDS = {
    "the", "a", "an", "and", "or", "to", "of", "in", "on", "for", "with",
    "at", "by", "is", "are", "was", "be", "as", "it", "its", "this", "that",
    "into", "from", "then", "than", "no", "not", "all", "any", "new", "old",
    "const", "static", "s32", "u32", "u16", "u8", "s16", "s8", "f32", "f64",
    "int", "bool", "void", "char", "float", "double", "unsigned", "signed",
    "var", "tmp", "temp", "value", "use", "uses", "used", "using", "via",
    "plus", "keep", "remove", "keep", "add", "adds", "gave", "give", "gives",
    "same", "form", "forms", "point", "points", "over", "line", "lines",
    "expr", "cast", "casts", "local", "locals", "copy", "copies",
}

# Concrete source edits keyed by token. Each entry is a list of
# (candidate_name, [(old_snippet, new_snippet), ...]) drawn from / generalising
# the corpus so every emitted candidate is directly runnable through the
# compile harness (probe.build). Snippets must occur in src/kart/KartState.cpp.
TOKEN_EDITS = {
    "addr": [
        ("pe-addr-taken-barrier",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* const pe = lbl_1_data_3918;\n  f32* const* ppe = &pe;")]),
        ("v28-addr-taken",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 & 0x40000) != 0;\n  s32* pv28 = &var_r28;")]),
        ("proxy-addr-refsplit",
         [("  KartObjectProxy* proxyF = proxy;",
           "  KartObjectProxy* proxyF = proxy;\n  KartObjectProxy** pproxyF = &proxyF;")]),
    ],
    "split": [
        ("pe-split-copy",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* const pe = lbl_1_data_3918;\n  f32* const peF = pe;")]),
        ("v28-split-copy",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 & 0x40000) != 0;\n  s32 var_r28b = var_r28;")]),
        ("pe-and-v28-split",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* const pe = lbl_1_data_3918;\n  f32* const peF = pe;"),
          ("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 & 0x40000) != 0;\n  s32 var_r28b = var_r28;")]),
        ("pcollide-style-split-pe",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* const pe = lbl_1_data_3918;\n  f32* pe2 = pe;\n  f32** ppe2 = &pe2;")]),
    ],
    "volatile": [
        ("pe-ptr-volatile",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* const volatile pe = lbl_1_data_3918;")]),
        ("v28-volatile",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  volatile s32 var_r28 = (flags0 & 0x40000) != 0;")]),
    ],
    "register": [
        ("pe-register-kw",
         [("  f32* const pe = lbl_1_data_3918;",
           "  register f32* const pe = lbl_1_data_3918;")]),
        ("v28-register-kw",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  register s32 var_r28 = (flags0 & 0x40000) != 0;")]),
    ],
    "mask": [
        ("v28-double-mask",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = ((flags0 >> 18) & 1) != 0;")]),
        ("v28-bitfield-test",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 & 0x40000) >> 18;")]),
        ("v28-bool-neg",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = !(flags0 & 0x40000) ? 0 : 1;")]),
    ],
    "shift": [
        ("v28-shift-then-mask",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 >> 18) & 1;")]),
    ],
    "decl": [
        ("v28-declared-before-pe",
         [("  f32* const pe = lbl_1_data_3918;\n  KartObjectProxy* proxy = mProxy;",
           "  KartObjectProxy* proxy = mProxy;\n  f32* const pe = lbl_1_data_3918;")]),
        ("pe-declared-after-vars",
         [("  f32* const pe = lbl_1_data_3918;\n  KartObjectProxy* proxy = mProxy;",
           "  KartObjectProxy* proxy = mProxy;\n  s32 _pad = 0;\n  f32* const pe = lbl_1_data_3918;")]),
        ("declare-v28-as-named-local",
         [("  KartObjectProxy* proxy = mProxy;",
           "  s32 var_r28 = 0;\n  KartObjectProxy* proxy = mProxy;"),
          ("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  var_r28 = (flags0 & 0x40000) != 0;")]),
    ],
    "coalesc": [
        ("v28-address-prevents-coalesce",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (flags0 & 0x40000) != 0;\n  if (var_r28) { var_r28 = 1; }")]),
        ("pe-force-live-across", 
         [("  KartObjectProxy* proxyF = proxy;",
           "  KartObjectProxy* proxyF = proxy;\n  if (pe[0] == pe[1]) { proxyF = mProxy; }")]),
    ],
    "playerIdx": [
        ("playerIdx-u8-early",
         [("  s32 playerIdx = proxyF->getPlayerIdx();",
           "  u8 playerIdx = (u8)proxyF->getPlayerIdx();")]),
        ("playerIdx-const",
         [("  s32 playerIdx = proxyF->getPlayerIdx();",
           "  const s32 playerIdx = proxyF->getPlayerIdx();")]),
    ],
    "gameMode": [
        ("gameMode-eq-const",
         [("gameMode - 3 == 0", "gameMode == 3")]),
        ("gameMode-cached",
         [("  s32 playerIdx = proxyF->getPlayerIdx();",
           "  s32 gameModeCache = proxyF->kartState()->field(2);\n  s32 playerIdx = proxyF->getPlayerIdx();")]),
    ],
    "loop": [
        ("pe-one-trip-loop",
         [("if ((softRatio / softTimer) - (nonSoftRatio / nonSoftTimer) < pe[18]) {",
           "f32 thresh = pe[18];\n      for (s32 _i = 0; _i < 1; _i++) { thresh = pe[18 + _i]; }\n      if ((softRatio / softTimer) - (nonSoftRatio / nonSoftTimer) < thresh) {")]),
    ],
    "temp": [
        ("pe-via-int-temp",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* pe = (f32*)((u8*)lbl_1_data_3918);")]),
        ("v28-via-int-temp",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  s32 var_r28 = (s32)((flags0 & 0x40000) != 0);")]),
    ],
    "rematerial": [
        ("pe-load-through-pcollide-like",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* pe = *(f32***)&lbl_1_data_3918;")]),
    ],
    "struct": [
        ("v28-in-struct",
         [("  s32 var_r28 = (flags0 & 0x40000) != 0;",
           "  struct { s32 b; } _v28 = { (flags0 & 0x40000) != 0 };\n  s32 var_r28 = _v28.b;")]),
        ("pe-in-struct",
         [("  f32* const pe = lbl_1_data_3918;",
           "  struct { f32* p; } _pe = { lbl_1_data_3918 };\n  f32* const pe = _pe.p;")]),
    ],
    "inline": [
        ("pe-inline-late-use",
         [("  f32* const pe = lbl_1_data_3918;",
           "  f32* pe = lbl_1_data_3918;\n  (void)pe;")]),
    ],
}

# tokens that the rules describe as the reusable register levers
DOMAIN_LEVER_TOKENS = {
    "split", "addr", "coalesc", "rematerial", "temp", "decl",
    "mask", "shift", "volatile", "register", "struct", "loop",
    "playerIdx", "gameMode", "inline",
}


# ----------------------------------------------------------------------------
# parsing helpers
# ----------------------------------------------------------------------------
def parse_regs(s):
    """'r28/r30/r26/r29' -> tuple; '-' -> None. Tolerates <4 fields."""
    if not s or s.strip() in ("-", ""):
        return None
    parts = [p.strip() for p in s.split("/")]
    if any(p in ("-", "") for p in parts):
        # partially measured: fill with None but keep alignment
        return tuple(p if p not in ("-", "") else None for p in parts)
    return tuple(parts)


def reg_num(r):
    if not r:
        return None
    m = re.match(r"r(\d+)$", r.strip())
    return int(m.group(1)) if m else None


def measured(regs):
    return regs is not None and regs[0] is not None and regs[1] is not None


def is_moved(regs):
    """A register move relevant to the residual: pe/var_r28 colouring changed."""
    return measured(regs) and (regs[0], regs[1]) != (BASE93[0], BASE93[1])


def toward_target(regs):
    """+1 per tracked var that reached the target register (max 2)."""
    if not measured(regs):
        return 0
    return int(regs[0] == TARGET[0]) + int(regs[1] == TARGET[1])


def reg_distance(regs):
    """Lower is closer to the target for pe & var_r28 (positions 0,1)."""
    if not measured(regs):
        return None
    d = 0
    for got, want in ((regs[0], TARGET[0]), (regs[1], TARGET[1])):
        gi, wi = reg_num(got), reg_num(want)
        if gi is None:
            return None
        d += abs(gi - wi)
    return d


TOKEN_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
REG_TOKEN_RE = re.compile(r"^r\d+$")
HEX_TOKEN_RE = re.compile(r"^(0x[0-9a-f]+|[0-9a-f]{4,})$")


def tokenize(*texts):
    toks = set()
    for t in texts:
        if not t:
            continue
        for m in TOKEN_RE.findall(t):
            low = m.lower()
            if len(low) < 3 or low in STOPWORDS:
                continue
            if REG_TOKEN_RE.match(low) or HEX_TOKEN_RE.match(low):
                continue  # physical-register names / hex literals are not levers
            toks.add(low)
    return toks


# ----------------------------------------------------------------------------
# data loading / joins
# ----------------------------------------------------------------------------
def load(dbpath):
    con = sqlite3.connect(dbpath)
    con.row_factory = sqlite3.Row
    cur = con.cursor()

    def rows(sql, *args):
        return [dict(r) for r in cur.execute(sql, args)]

    data = {
        "agents": rows("SELECT * FROM agents"),
        "trials": rows("SELECT * FROM trials"),
        "regalloc": rows("SELECT * FROM regalloc"),
        "findings": rows("SELECT * FROM findings"),
        "rules": rows("SELECT * FROM rules"),
    }
    # --- joins -------------------------------------------------------------
    agents_by = {a["agent_id"]: a for a in data["agents"]}
    reg_by_build = defaultdict(list)
    for r in data["regalloc"]:
        reg_by_build[r["build_id"]].append(r)

    # trials <-> agents (attribute evidence: round / angle / model / status)
    joined = []
    for t in data["trials"]:
        a = agents_by.get(t["agent_id"], {})
        t2 = dict(t)
        t2["round"] = a.get("round")
        t2["angle"] = a.get("angle")
        t2["model"] = a.get("model")
        t2["agent_status"] = a.get("status")
        t2["regs"] = parse_regs(t.get("registers"))
        joined.append(t2)
    data["trials_joined"] = joined

    # trials <-> regalloc: infer build_id from the trial base (86.99 -> base86,
    # 93.4368 -> base93) and attach the regalloc rows whose physical register is
    # one of the registers named in the trial's tuple.
    for t in joined:
        base = t.get("base")
        build = "base86" if (base is not None and base < 90.0) else "base93"
        t["build_id"] = build
        regs = set(x for x in (t["regs"] or ()) if x)
        t["regalloc"] = [r for r in reg_by_build.get(build, []) if r["reg"] in regs]
    data["reg_by_build"] = dict(reg_by_build)
    # FTS5 demonstration over the corpus (fts_trials is content-linked).
    try:
        data["fts_demo"] = rows(
            "SELECT t.label,t.score,t.category,t.registers "
            "FROM fts_trials f JOIN trials t ON t.trial_id=f.rowid "
            "WHERE fts_trials MATCH ? ORDER BY t.score DESC",
            "coalesc* OR split OR remateriali*")
    except sqlite3.OperationalError:
        data["fts_demo"] = []
    return data


# ----------------------------------------------------------------------------
# analytics
# ----------------------------------------------------------------------------
def delta_by_category(trials):
    g = defaultdict(lambda: {"n": 0, "deltas": [], "scores": [], "beats": 0,
                             "moved": 0, "instr": []})
    for t in trials:
        c = t["category"]
        x = g[c]
        x["n"] += 1
        if t["delta"] is not None:
            x["deltas"].append(t["delta"])
        if t["score"] is not None:
            x["scores"].append(t["score"])
        x["beats"] += int(bool(t["beat"]))
        x["moved"] += int(is_moved(t["regs"]))
        if t["instr_count"] is not None:
            x["instr"].append(t["instr_count"])
    out = []
    for c, x in g.items():
        out.append({
            "category": c,
            "n": x["n"],
            "mean_delta": _mean(x["deltas"]),
            "max_delta": max(x["deltas"]) if x["deltas"] else 0.0,
            "min_delta": min(x["deltas"]) if x["deltas"] else 0.0,
            "mean_score": _mean(x["scores"]),
            "beats": x["beats"],
            "moved": x["moved"],
            "mean_instr": _mean(x["instr"]),
        })
    out.sort(key=lambda d: d["max_delta"], reverse=True)
    return out


def reg_tuple_distribution(trials):
    d = {}
    for t in trials:
        key = t.get("registers") or "-"
        e = d.setdefault(key, {"tuple": key, "n": 0, "deltas": [], "scores": [],
                               "cats": set(), "toward": 0})
        e["n"] += 1
        if t["delta"] is not None:
            e["deltas"].append(t["delta"])
        if t["score"] is not None:
            e["scores"].append(t["score"])
        e["cats"].add(t["category"])
        e["toward"] += toward_target(t["regs"])
    out = []
    for k, e in d.items():
        out.append({"tuple": k, "n": e["n"], "mean_delta": _mean(e["deltas"]),
                    "best_score": max(e["scores"]) if e["scores"] else None,
                    "categories": sorted(e["cats"]), "reached_target_vars": e["toward"]})
    out.sort(key=lambda e: e["n"], reverse=True)
    return out


def token_correlation(trials):
    """token -> stats over trials whose text contains it."""
    global_moved = sum(1 for t in trials if is_moved(t["regs"]))
    global_meas = sum(1 for t in trials if measured(t["regs"]))
    base_rate = (global_moved / global_meas) if global_meas else 0.0

    stats = defaultdict(lambda: {"n": 0, "meas": 0, "moved": 0, "toward": 0,
                                 "deltas": [], "scores": [], "cats": set(),
                                 "examples": []})
    for t in trials:
        toks = tokenize(t.get("edit_from"), t.get("edit_to"), t.get("notes"),
                        t.get("label"))
        if not toks:
            continue
        for tok in toks:
            e = stats[tok]
            e["n"] += 1
            if measured(t["regs"]):
                e["meas"] += 1
                e["moved"] += int(is_moved(t["regs"]))
            e["toward"] += toward_target(t["regs"])
            if t["delta"] is not None:
                e["deltas"].append(t["delta"])
            if t["score"] is not None:
                e["scores"].append(t["score"])
            e["cats"].add(t["category"])
            if len(e["examples"]) < 3:
                e["examples"].append((t["label"], t["score"], t["registers"]))
    out = []
    for tok, e in stats.items():
        rate = (e["moved"] / e["meas"]) if e["meas"] else 0.0
        out.append({
            "token": tok, "n": e["n"], "moved": e["moved"], "meas": e["meas"],
            "move_rate": rate, "lift": (rate / base_rate) if base_rate else 0.0,
            "toward_target": e["toward"],
            "mean_delta": _mean(e["deltas"]),
            "best_score": max(e["scores"]) if e["scores"] else None,
            "categories": sorted(e["cats"]), "examples": e["examples"],
        })
    out.sort(key=lambda d: (d["lift"], d["n"]), reverse=True)
    return out, base_rate


def regalloc_vs_score(data):
    """Join each trial to regalloc rows by build + named register and correlate
    vreg / degree against score & delta; plus the raw colouring tables."""
    per_trial = []
    for t in data["trials_joined"]:
        if not t["regalloc"]:
            continue
        vregs = [r["vreg"] for r in t["regalloc"]]
        degs = [r["degree"] for r in t["regalloc"]]
        per_trial.append({
            "trial_id": t["trial_id"], "label": t["label"],
            "score": t["score"], "delta": t["delta"],
            "build_id": t["build_id"], "registers": t["registers"],
            "mean_vreg": _mean(vregs), "sum_vreg": sum(vregs),
            "mean_degree": _mean(degs), "sum_degree": sum(degs),
        })
    corr = {
        "vreg_vs_score": _pearson([p["sum_vreg"] for p in per_trial],
                                  [p["score"] for p in per_trial]),
        "degree_vs_score": _pearson([p["sum_degree"] for p in per_trial],
                                    [p["score"] for p in per_trial]),
        "vreg_vs_delta": _pearson([p["sum_vreg"] for p in per_trial],
                                  [p["delta"] for p in per_trial]),
        "n": len(per_trial),
    }
    tables = {}
    for build, rows in data["reg_by_build"].items():
        tables[build] = sorted(rows, key=lambda r: -(r["vreg"] or 0))
    return per_trial, corr, tables


def coverage_gaps(trials, tokens):
    cats = defaultdict(int)
    cat_tokens = defaultdict(set)
    for t in trials:
        cats[t["category"]] += 1
        for tok in tokenize(t.get("edit_from"), t.get("edit_to"),
                            t.get("notes"), t.get("label")):
            cat_tokens[t["category"]].add(tok)
    thin = sorted([(c, n) for c, n in cats.items() if n <= 3], key=lambda x: x[1])

    observed = set()
    for t in trials:
        r = t["regs"]
        if measured(r):
            observed.add((r[0], r[1]))
        else:
            observed.add(None)
    # which (pe,var_r28) combinations were reached at all
    reached = sorted([x for x in observed if x], key=lambda p: (p[0], p[1]))
    target_reached = (TARGET[0], TARGET[1]) in observed
    return {
        "thin_categories": thin,
        "category_counts": dict(sorted(cats.items(), key=lambda x: -x[1])),
        "reached_pairs": reached,
        "target_pair": (TARGET[0], TARGET[1]),
        "target_pair_reached": target_reached,
        "unreached_pair_count": len(reached) and (
            0 if target_reached else 1),
    }


def _rules_context(data):
    """Print the reusable rules and finding-kind counts (joined by agent), and
    demonstrate the FTS5 index against the corpus."""
    _hr("5b. RULES & FINDINGS (rules / findings joined by agent_id)")
    for r in data["rules"]:
        print("[%s] %s" % (r["rule_id"], r["statement"]))
        print("      consequence: %s" % r["consequence"])
    kinds = defaultdict(int)
    for f in data["findings"]:
        kinds[f["kind"]] += 1
    print("findings by kind: " + ", ".join("%s=%d" % (k, n)
                                            for k, n in sorted(kinds.items())))
    for f in data["findings"]:
        if f["kind"] in ("rule", "consequence"):
            print("  %-11s %-6s %s" % (f["agent_id"], f["kind"], f["statement"]))
    print("FTS5 fts_trials MATCH 'coalesc* OR split OR remateriali*':")
    for t in data.get("fts_demo", []):
        print("  %-18s %8s %-14s %s" % (t["label"], t["score"],
                                          t["category"], t["registers"]))


def untried_levers(trials, tok_stats, cat_stats, top=25):
    """rank UNTRIED (category x token) combinations."""
    tok_by_name = {s["token"]: s for s in tok_stats}
    cat_by_name = {s["category"]: s for s in cat_stats}

    # what (category, token) combos are already present?
    present = set()
    for t in trials:
        toks = tokenize(t.get("edit_from"), t.get("edit_to"), t.get("notes"),
                        t.get("label"))
        for tok in toks:
            present.add((t["category"], tok))

    global_rate = 0.0
    meas = sum(1 for t in trials if measured(t["regs"]))
    moved = sum(1 for t in trials if is_moved(t["regs"]))
    if meas:
        global_rate = moved / meas

    cands = []
    # only propose actionable tokens: those with a canned, testable edit or an
    # explicitly domain-known lever. This keeps the ranking concrete.
    tokens = set(TOKEN_EDITS) | DOMAIN_LEVER_TOKENS
    for cat in cat_by_name:
        cs = cat_by_name[cat]
        for tok in tokens:
            if (cat, tok) in present:
                continue
            ts = tok_by_name.get(tok)
            # token signal: how often it moved a register elsewhere, and any
            # evidence it reached toward the target
            if ts:
                lift = ts["lift"]
                move_rate = ts["move_rate"]
                toward = ts["toward_target"]
                tok_best = ts["best_score"] or 0.0
            else:
                # domain-known lever never measured: neutral prior
                lift = 1.0
                move_rate = global_rate
                toward = 0
                tok_best = 0.0
            cat_best = max(cs["max_delta"], 0.0)
            # predicted pull toward the pe=r30 / var_r28=r28 colouring
            pred = (2.0 * toward
                    + 1.0 * lift
                    + 0.75 * move_rate
                    + 0.20 * cat_best
                    + 0.001 * tok_best)
            edits = TOKEN_EDITS.get(tok, [])
            cands.append({
                "category": cat, "token": tok, "predicted_pull": round(pred, 4),
                "token_lift": round(lift, 4), "token_move_rate": round(move_rate, 4),
                "token_reached_target_vars": toward,
                "category_max_delta": cat_best,
                "category_n": cs["n"],
                "edits": [{"name": n, "edits": e} for n, e in edits],
            })
    cands.sort(key=lambda c: c["predicted_pull"], reverse=True)
    # de-duplicate identical edit payloads, keep first (highest ranked)
    seen, out = set(), []
    for c in cands:
        key = json.dumps(c["edits"], sort_keys=True)
        if key and key in seen:
            continue
        seen.add(key)
        out.append(c)
        if len(out) >= top:
            break
    return out


# ----------------------------------------------------------------------------
# small math
# ----------------------------------------------------------------------------
def _mean(xs):
    xs = [x for x in xs if x is not None]
    return (sum(xs) / len(xs)) if xs else 0.0


def _pearson(xs, ys):
    pairs = [(x, y) for x, y in zip(xs, ys)
             if x is not None and y is not None]
    n = len(pairs)
    if n < 2:
        return None
    mx = sum(p[0] for p in pairs) / n
    my = sum(p[1] for p in pairs) / n
    num = sum((x - mx) * (y - my) for x, y in pairs)
    dx = math.sqrt(sum((x - mx) ** 2 for x, _ in pairs))
    dy = math.sqrt(sum((y - my) ** 2 for _, y in pairs))
    if dx == 0 or dy == 0:
        return None
    return num / (dx * dy)


# ----------------------------------------------------------------------------
# reporting
# ----------------------------------------------------------------------------
def _hr(title):
    print("\n" + "=" * 78)
    print(title)
    print("=" * 78)


def report(data, top=25, want_json=None):
    trials = data["trials_joined"]

    _hr("0. DATA LOAD & JOIN")
    print("agents=%d  trials=%d  regalloc=%d  findings=%d  rules=%d"
          % (len(data["agents"]), len(trials), len(data["regalloc"]),
             len(data["findings"]), len(data["rules"])))
    print("agents by round: " + ", ".join(
        "%s=%d" % (r, n) for r, n in sorted(
            _count(data["agents"], "round").items())))
    print("trials joined to agents: %d/%d ; trials joined to regalloc: %d/%d"
          % (sum(1 for t in trials if t.get("round")), len(trials),
             sum(1 for t in trials if t["regalloc"]), len(trials)))

    _hr("1. DELTA BY CATEGORY  (base=86.9928 or 93.4368 per trial)")
    print("%-14s %4s %9s %9s %9s %8s %6s %6s" %
          ("category", "n", "mean_d", "max_d", "min_d", "mean_sc", "beat", "moved"))
    for c in delta_by_category(trials):
        print("%-14s %4d %9.4f %9.4f %9.4f %8.4f %6d %6d" %
              (c["category"], c["n"], c["mean_delta"], c["max_delta"],
               c["min_delta"], c["mean_score"], c["beats"], c["moved"]))

    _hr("2. DISTRIBUTION OF THE registers TUPLE  (pe/var_r28/proxy/pool)")
    print("target colouring = pe=r30 var_r28=r28  (base93 = %s)" % "/".join(BASE93))
    print("%-22s %4s %9s %10s %s" % ("tuple", "n", "mean_delta", "best_sc", "reached_target_vars"))
    for e in reg_tuple_distribution(trials):
        print("%-22s %4d %9.4f %10s %d" %
              (e["tuple"], e["n"], e["mean_delta"],
               ("%.4f" % e["best_score"]) if e["best_score"] is not None else "-",
               e["reached_target_vars"]))

    tok_stats, base_rate = token_correlation(trials)
    _hr("3. EDIT TOKENS CORRELATED WITH A REGISTER MOVE  (global move_rate=%.3f)" % base_rate)
    print("%-14s %3s %6s %9s %6s %9s %9s %s" %
          ("token", "n", "moved", "move_rate", "lift", "mean_delta", "best_sc", "categories"))
    shown = [s for s in tok_stats if s["n"] >= 2][:20]
    for s in shown:
        print("%-14s %3d %6d %9.3f %6.2f %9.4f %9s %s" %
              (s["token"], s["n"], s["moved"], s["move_rate"], s["lift"],
               s["mean_delta"],
               ("%.4f" % s["best_score"]) if s["best_score"] is not None else "-",
               ",".join(s["categories"])))

    per_trial, corr, tables = regalloc_vs_score(data)
    _hr("4. REGALLOC vreg / degree vs TRIAL SCORE")
    print("joined trials w/ regalloc=%d" % corr["n"])
    print("pearson(sum_vreg, score)   = %s" % _fmt(corr["vreg_vs_score"]))
    print("pearson(sum_degree, score) = %s" % _fmt(corr["degree_vs_score"]))
    print("pearson(sum_vreg, delta)   = %s" % _fmt(corr["vreg_vs_delta"]))
    print("\ncolouring tables (descending vreg = colour order, R-COLOR-ORDER):")
    for build, rows in tables.items():
        print("  [%s]" % build)
        for r in rows:
            print("    v%-4s deg=%-4s -> %-4s  %-26s %s"
                  % (r["vreg"], r["degree"], r["reg"], r["name"], r["flags"]))

    gaps = coverage_gaps(trials, tok_stats)
    _hr("5. COVERAGE GAPS")
    print("category counts: " + ", ".join("%s=%d" % (c, n) for c, n in
                                           gaps["category_counts"].items()))
    print("thin categories (<=3 trials): %s" %
          ", ".join("%s(%d)" % (c, n) for c, n in gaps["thin_categories"]))
    print("reached (pe,var_r28) pairs: %s" % (gaps["reached_pairs"],))
    print("target pair %s reached: %s" % (gaps["target_pair"],
                                           gaps["target_pair_reached"]))

    _rules_context(data)

    levers = untried_levers(trials, tok_stats, delta_by_category(trials), top=top)
    _hr("6. RANKED UNTRIED LEVER CANDIDATES (category x token)")
    for i, c in enumerate(levers, 1):
        name = c["edits"][0]["name"] if c["edits"] else "(no canned edit)"
        print("%2d. pull=%.3f  %-14s x %-12s  token_lift=%.2f move_rate=%.2f "
              "reached=%d cat_max_d=%.3f  [%s]"
              % (i, c["predicted_pull"], c["category"], c["token"],
                 c["token_lift"], c["token_move_rate"],
                 c["token_reached_target_vars"], c["category_max_delta"], name))
        for ed in c["edits"][:1]:
            for old, new in ed["edits"]:
                print("        - from: %s" % old.replace("\n", "\\n"))
                print("        + to:   %s" % new.replace("\n", "\\n"))

    if want_json:
        payload = {
            "delta_by_category": delta_by_category(trials),
            "reg_tuple_distribution": reg_tuple_distribution(trials),
            "token_correlation": [{k: v for k, v in s.items()}
                                  for s in tok_stats],
            "regalloc_corr": corr,
            "coverage_gaps": gaps,
            "untried_levers": levers,
        }
        with open(want_json, "w", encoding="utf-8") as f:
            json.dump(payload, f, indent=2)
        print("\n[json] wrote %s" % want_json)
    return levers


def _count(rows, key):
    d = defaultdict(int)
    for r in rows:
        d[r.get(key)] += 1
    return d


def _fmt(x):
    return "n/a" if x is None else "%+.4f" % x


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--db", default=DEFAULT_DB, help="path to subagents.db")
    ap.add_argument("--top", type=int, default=25, help="number of levers to rank")
    ap.add_argument("--json", dest="json_out", default=None,
                    help="also write the analytics as JSON")
    args = ap.parse_args(argv)
    if not os.path.exists(args.db):
        print("error: db not found: %s" % args.db, file=sys.stderr)
        return 2
    data = load(args.db)
    report(data, top=args.top, want_json=args.json_out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
