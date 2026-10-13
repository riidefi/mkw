#!/usr/bin/env python3
"""harvest_coverage.py -- COVERAGE-OF-HARVEST-METHODS analysis for the
`updateCollisions` subagent dataset.

The `harvest_methods` table records *that* 40 methods were used and *what they
collect*, but (unlike `agents`/`trials`/`regalloc`) it has no explicit
"applied-to" column. This tool derives the coverage of every method -- which
variables / regions / TU-contexts it was actually applied to, and at what grain
(function | section | instruction | expression) -- by cross-referencing the
method's own `collects`/`used_for`/`command` text against the `trials`,
`regalloc` and `findings` evidence, then flags methods that were only used
*partially* (a scope the method supports but the corpus never exercised).

Outputs:
  1. the coverage table (method -> used-on) with grain + coverage status
  2. discovered gaps (partial-coverage methods + the unexercised scope)
  3. the concrete candidate edits generated from those gaps and their objdiff
     match% (read from hv_results.json if present)

Usage:  python harvest_coverage.py [--db subagents.db] [--results hv_results.json]
"""
from __future__ import annotations

import argparse
import json
import os
import sqlite3
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_DB = os.path.join(os.path.dirname(HERE), "subagents.db")
DEFAULT_RESULTS = os.path.join(HERE, "hv_results.json")

BASE93 = ("r28", "r30", "r26", "r29")     # pe / var_r28 / proxy / pool at 93.4368
TARGET = ("r30", "r28", "r26", "r29")     # what the retail target wants

# ---------------------------------------------------------------------------
# Domain vocabulary
# ---------------------------------------------------------------------------
# The *targets* a harvesting method can be pointed at in this function.
VAR_TARGETS = ["pe", "var_r28", "var_r27", "flags0", "proxy", "proxyF", "pool",
               "gameMode", "playerIdx", "collide", "wheel/loop", "tail-block"]
REGION_TARGETS = ["prologue/decl", "wheel-loop", "pe-tail-reads", ".rodata pool",
                  ".data arrays", "TU/function-order"]
GRAIN = ["function", "section", "instruction", "expression"]

# ---------------------------------------------------------------------------
# Curated method -> applied-to map, DERIVED from each row's `collects` /
# `used_for` text (quoted evidence in `note`). `partial` = the method's own
# description implies a finer/other scope the corpus never exercised.
# ---------------------------------------------------------------------------
# method_id: (applied_to, grain, partial, gap_or_None, note)
METHOD_COVERAGE = {
    1:  (["every trial (48)", "updateCollisions"], "function", True,
         "per-instruction rows are collected but only the aggregate score is "
         "consumed; the instruction rows were never mined per-expression",
         "collects: 'per-function/per-section match_percent; per-instruction rows'"),
    2:  (["pool/.rodata symbol name"], "function", True,
         "applied only to the .rodata symbol-name difference; never to the "
         "pe symbol name at the pe[18]/pe+17/pe[3] read sites",
         "used_for: 'proved the .rodata symbol-name difference did not affect the score'"),
    3:  (["prologue", "all regs (pe/var_r28/proxy/pool)"], "function", False, None,
         "used_for: 'compared ours vs target prologue/registers; found the pool/pe lds'"),
    4:  (["pe", "var_r28", "proxy", "pool"], "function", False, None,
         "used_for: 'extracting the pe/var_r28/proxy/pool register tuple'"),
    5:  (["rodata symbols"], "section", False, None,
         "used_for: 'compared target vs our object symbols (rodata naming/size)'"),
    6:  (["sections", ".rodata pool"], "section", False, None,
         "used_for: 'section sizes; finding the .rodata pool'"),
    7:  (["function reloc set", "pe", "pool"], "function", True,
         "symbol-reference comparison is function-grain; never per-expression "
         "around the pe reads",
         "used_for: 'per-function symbol-reference comparison; located r29=.../r30=pe'"),
    8:  ([".rodata bytes"], "section", False, None,
         "used_for: 'proved target/our .rodata byte-identical'"),
    9:  (["TU function order"], "section", False, None,
         "used_for: 'TU function order; per-function byte compare'"),
    10: (["whole function (structural vs register diffs)"], "function", True,
         "'no structural diffs' was asserted function-wide; the pe-read "
         "expressions were never isolated instruction-by-instruction",
         "used_for: 'proved the residual is register-only'"),
    11: (["original function order", "data addresses"], "section", False, None,
         "used_for: 'confirmed the original function order and data addresses'"),
    12: (["project layout", "symbol map"], "section", False, None,
         "used_for: 'mapdas input; project layout; symbol map'"),
    13: (["proxy", "(coalescing instruction)"], "instruction", False, None,
         "used_for: 'found the coalescing mr r385,r92; pass attribution'"),
    14: (["pe", "var_r28", "pool", "proxyF", "var_r27"], "function", False, None,
         "used_for: 'the vreg-index colouring rule; degrees; coalescing'"),
    15: (["compiler internals"], "section", False, None,
         "used_for: 'enabled the debugger on our exact compiler'"),
    16: (["updateCollisions"], "function", False, None,
         "used_for: 'pinned Wii/0x4201_127 as best'"),
    17: (["updateCollisions"], "function", False, None,
         "used_for: 'confirmed the project flags are optimal'"),
    18: (["every candidate (~150k)"], "function", False, None,
         "used_for: 'the throughput engine'"),
    19: (["proxy", "var_r28 mask"], "function", True,
         "the hill-climb lever library was centred on proxy/var_r28; pe read "
         "expressions (pe[18]/pe+17/pe[3]) were not individual levers",
         "used_for: 'found the proxyF lifetime-split win'"),
    20: (["updateCollisions (structural mutations)"], "function", False, None,
         "used_for: 'structural search; no gain past the wall'"),
    21: (["updateCollisions (text mutations)"], "function", False, None,
         "used_for: 'broad text-level candidate generation'"),
    22: ([], "n/a", True,
         "NEVER APPLIED: decomp-permuter is C-only and this is a C++ TU",
         "used_for: 'limited to C, not this C++ TU'"),
    23: (["DOL/link identity"], "section", False, None,
         "used_for: 'confirmed code-identity'"),
    24: (["linked ELF symtab"], "section", False, None,
         "used_for: 'found a project-wide symbol-name mismatch'"),
    25: (["whole function (external)"], "function", False, None,
         "used_for: 'published WIP scratch hbr0m'"),
    26: (["technique corpus"], "n/a", False, None,
         "used_for: 'found SFA-Decomp playbook, mwcc-debugger'"),
    27: (["declarations", "types", "casts of proxy/pe"], "function", True,
         "source-form enumeration is declaration/type grain; per-EXPRESSION "
         "forms of the pe reads and of var_r28 at its uses were under-enumerated",
         "used_for: 'systematic libraries of declaration/type/qualifier/cast spellings'"),
    28: (["proxy", "pe", "var_r28", "var_r25/24/23/22/27"], "statement", True,
         "lifetime splits were applied to whole values; not to individual read "
         "expressions (pe[18] vs pe+17 vs pe[3] separately)",
         "used_for: 'x2=x copies at many points / per-value splits'"),
    29: (["pe", "var_r28", "proxy", "pool"], "function", True,
         "the tuple is extracted whole-function only; never per-region "
         "(prologue vs wheel-loop vs pe-tail) and never per-expression",
         "used_for: 'the (pe/var_r28/proxy/pool) physical registers from the object'"),
    30: (["pe", "var_r28", "pool", "proxyF", "var_r27"], "function", False, None,
         "used_for: 'var -> vreg -> degree -> register -> flags from regalloc dumps'"),
    31: (["function / decl-block vreg table"], "function", True,
         "FORWARD-ONLY and function/decl-block grain: derived R-VREG-BLOCKS by "
         "edit->vreg; never run in REVERSE (target vreg table -> source form), "
         "and never per-variable (pe, var_r28) across source forms",
         "used_for: 'how a source edit shifts the vreg table (cause->effect map)'"),
    32: (["whole interference graph"], "function", False, None,
         "used_for: 'falsified the degree-priority model'"),
    33: (["data symbols across 201 TUs"], "section", True,
         "TU-wide data-order sweep; never pointed at the *pool* symbol "
         "(lbl_1_rodata_27D0) interacting with pe in THIS TU",
         "used_for: 'found the data-section ordering is cross-declaration'"),
    34: (["201 TUs"], "section", True,
         "project-wide TU sweep; the pool-vs-pe interaction inside one TU was "
         "not a separate axis",
         "used_for: 'bounded the data-section issues'"),
    35: (["linked ELF symtab"], "section", False, None,
         "used_for: 'made ninja dol_diff green'"),
    36: (["referenced symbols per function"], "function", True,
         "RELOC-SYMBOL COMPARISON only at function granularity; never per "
         "EXPRESSION around pe[18]/pe+17/pe[3]",
         "used_for: 'set of referenced symbols per function (ours vs target)'"),
    37: (["everything (parallel)"], "n/a", False, None,
         "used_for: 'the proxyF win; then exhaustive confirmation of the wall'"),
    38: (["dataset (analytics/graph/solver/retrieval/ETL)"], "dataset", True,
         "the DB tools had no coverage-of-METHODS view (this analysis fills it)",
         "used_for: 'formal no-path + UNSAT proofs; grew this DB'"),
    39: (["gameMode block"], "statement", False, None,
         "used_for: 'recovered gameMode as a (false-positive) switch'"),
    40: (["scratch context bundle"], "n/a", False, None,
         "used_for: 'prepared the scratch/permuter bundle'"),
}


def load(dbpath):
    con = sqlite3.connect(dbpath)
    con.row_factory = sqlite3.Row
    cur = con.cursor()
    rows = lambda s: [dict(r) for r in cur.execute(s)]
    return {
        "methods": rows("SELECT * FROM harvest_methods ORDER BY method_id"),
        "trials": rows("SELECT * FROM trials"),
        "regalloc": rows("SELECT * FROM regalloc"),
        "findings": rows("SELECT * FROM findings"),
        "rules": rows("SELECT * FROM rules"),
        "agents": rows("SELECT * FROM agents"),
    }


def category_application(data):
    """Auto cross-reference: for each harvest category, which trial categories /
    labels exercised it, and which reg tuples were reached."""
    by_cat = {}
    for t in data["trials"]:
        by_cat.setdefault(t["category"], []).append(t)
    out = {}
    for m in data["methods"]:
        out[m["method_id"]] = m["category"]
    return by_cat


def coverage_table(data):
    app = category_application(data)
    # map method category -> trial categories it plausibly produced
    cat_map = {
        "measure": ["reference", "lifetime-split", "expression", "declaration",
                    "type", "structure", "loop", "flag", "tu-context", "combination"],
        "disasm": ["reference", "lifetime-split"],
        "symbols": ["reference"],
        "reloc": ["reference", "lifetime-split"],
        "data": ["tu-context"],
        "compiler": ["flag"],
        "permuter": ["lifetime-split", "declaration", "expression", "structure"],
        "external": ["structure", "flag"],
        "vreg-internals": ["lifetime-split", "declaration", "expression"],
        "edit-generation": ["declaration", "type", "lifetime-split", "expression"],
        "meta": ["reference"],
    }
    table = []
    for m in data["methods"]:
        mid = m["method_id"]
        cov = METHOD_COVERAGE.get(mid)
        if cov:
            applied, grain, partial, gap, note = cov
        else:
            applied, grain, partial, gap, note = (["?"], "?", False, None, "")
        tcats = cat_map.get(m["category"], [])
        n_trials = sum(len(app.get(c, [])) for c in tcats)
        table.append({
            "method_id": mid, "name": m["name"], "category": m["category"],
            "tool": m["tool"], "applied_to": applied, "grain": grain,
            "partial": partial, "gap": gap, "evidence": note,
            "trial_cats": tcats, "n_trials": n_trials,
        })
    return table


def gaps(table):
    return [r for r in table if r["partial"]]


def print_report(data, results_path):
    table = coverage_table(data)
    print("=" * 100)
    print("HARVEST-METHOD COVERAGE  (method -> used-on)   |  * = partial coverage")
    print("=" * 100)
    print("%-3s %-30s %-14s %-42s %s" %
          ("id", "method", "category", "used-on", "grain/partial"))
    print("-" * 100)
    for r in table:
        star = "*" if r["partial"] else " "
        used = "; ".join(r["applied_to"]) if r["applied_to"] else "(never applied)"
        if len(used) > 40:
            used = used[:37] + "..."
        print("%-3d%s%-30s %-14s %-42s %s" %
              (r["method_id"], star, r["name"][:30], r["category"],
               used, r["grain"]))

    print("\n" + "=" * 100)
    print("DISCOVERED GAPS (methods with a scope the corpus never exercised)")
    print("=" * 100)
    for r in gaps(table):
        print("G[#%d] %s  --  %s" % (r["method_id"], r["name"], r["category"]))
        print("      applied : %s" % "; ".join(r["applied_to"]) if r["applied_to"]
              else "      applied : (never)")
        print("      GAP     : %s" % r["gap"])
        print("      evidence: %s" % r["evidence"])

    # ---- regalloc / tuple evidence --------------------------------------
    print("\n" + "=" * 100)
    print("COLOURING EVIDENCE (regalloc) -- which webs the vreg methods touched")
    print("=" * 100)
    builds = {}
    for r in data["regalloc"]:
        builds.setdefault(r["build_id"], []).append(r)
    for b, rows in builds.items():
        names = sorted({r["name"] for r in rows if r["name"]})
        print("  [%s] %s" % (b, ", ".join(names) if names else "(anon temps)"))

    # ---- applied-method candidates + scores -----------------------------
    print("\n" + "=" * 100)
    print("APPLIED-METHOD CANDIDATES (generated from the gaps) + objdiff match%")
    print("=" * 100)
    if os.path.exists(results_path):
        res = json.load(open(results_path, encoding="utf-8"))
        print("  base = %s" % res.get("base"))
        beat = res.get("beat")
        print("  best = %s ; beat 93.4368 = %s" % (res.get("best"), beat))
        print("  %-34s %-9s %-26s %s" % ("candidate", "match%", "from-gap", "regs(pool,pe)"))
        for c in res.get("candidates", []):
            print("  %-34s %-9s %-26s %s" %
                  (c.get("name"), c.get("score"), c.get("gap"),
                   c.get("tuple", "")))
    else:
        print("  (no %s -- run the applied-method scripts first)" % results_path)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--results", default=DEFAULT_RESULTS)
    args = ap.parse_args(argv)
    if not os.path.exists(args.db):
        print("db not found: %s" % args.db, file=sys.stderr)
        return 2
    print_report(load(args.db), args.results)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
