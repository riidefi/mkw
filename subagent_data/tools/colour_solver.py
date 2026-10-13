#!/usr/bin/env python3
"""colour_solver.py -- constraint-solver tool for the MWCC register-allocation
problem on KartState::updateCollisions (Mario Kart Wii matching decomp).

It reads the structured dataset (subagents.db: regalloc + rules) and encodes the
colouring model described by the reusable rules as a constraint system:

  * R-COLOR-ORDER .. saved registers r31,r30,r29,... are handed out in
    DESCENDING vreg-id order.
  * R-VREG-BLOCKS .. declared locals are ONE contiguous vreg block numbered in
    reverse declaration order; compiler temps are numbered above the block.
  * R-SPLIT ........ a lifetime split recolours a web iff the value is
    non-rematerializable AND the copy's live range overlaps the original.

Given the retail TARGET colouring {pe=r30, var_r28=r28, proxy=r26, pool=r29} it
solves for the vreg ordering / membership that is REQUIRED, then adds the
source-realizability constraints (a declared local cannot out-rank a temp; a
rematerializable value cannot be promoted to a long-lived temp) and reports
either the surviving source shape or an UNSAT core as an infeasibility proof.

z3 is used when importable; otherwise a pure-python exhaustive fallback solves
the (tiny) ordering model.

Usage:
    python colour_solver.py [--db subagents.db] [--harness] [--json out.json]
"""
from __future__ import annotations

import argparse
import itertools
import json
import os
import sqlite3
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_DB = os.path.join(os.path.dirname(HERE), "subagents.db")

SAVED = ["r31", "r30", "r29", "r28", "r27", "r26", "r25", "r24", "r23",
         "r22", "r21", "r20", "r19", "r18", "r17", "r16"]

TARGET = {"pe": "r30", "var_r28": "r28", "proxyF": "r26", "pool": "r29"}
BASE93_SCORE = 93.4368

STATIC_WEBS = [
    {"name": "hi",      "vreg": 143, "degree": None, "kind": "temp",
     "origin": "temp",  "remat": False, "reg": "r31",
     "note": "highest saved web in the base93 assigned dump"},
    {"name": "var_r28", "vreg": 94,  "degree": 245,  "kind": "temp",
     "origin": "temp",  "remat": True,  "reg": "r30",
     "note": "anon live node of (flags0 & 0x40000) != 0"},
    {"name": "pool",    "vreg": 88,  "degree": 276,  "kind": "temp",
     "origin": "temp",  "remat": False, "reg": "r29",
     "note": "lbl_1_rodata_27D0 constant pool; vreg invariant"},
    {"name": "pe",      "vreg": 69,  "degree": 257,  "kind": "local",
     "origin": "local", "remat": True,  "reg": "r28",
     "note": "first-declared local; f32* const pe = lbl_1_data_3918"},
    {"name": "var_r27", "vreg": 63,  "degree": 93,   "kind": "local",
     "origin": "local", "remat": True,  "reg": "r27",
     "note": "declared bool"},
    {"name": "proxyF",  "vreg": 62,  "degree": 283,  "kind": "split",
     "origin": "split", "remat": False, "reg": "r26",
     "note": "the winning lifetime split; non-rematerializable"},
]


def load_webs(db_path):
    webs = {w["name"]: dict(w) for w in STATIC_WEBS}
    if os.path.exists(db_path):
        con = sqlite3.connect(db_path)
        try:
            rows = con.execute(
                "SELECT name,vreg,degree,reg,flags FROM regalloc "
                "WHERE build_id='base93'").fetchall()
        except sqlite3.Error:
            rows = []
        finally:
            con.close()
        for name, vreg, degree, reg, flags in rows:
            key = "proxyF" if name == "proxyF" else name
            if key in webs:
                webs[key]["db_vreg"] = vreg
                webs[key]["db_degree"] = degree
                webs[key]["db_reg"] = reg
                webs[key]["db_flags"] = flags
    return webs


def check_rule_r_color_order(webs):
    ordered = sorted(webs.values(), key=lambda w: -w["vreg"])
    rows = []
    ok = True
    for i, w in enumerate(ordered):
        expected = SAVED[i]
        hit = (expected == w["reg"])
        ok = ok and hit
        rows.append((w["name"], w["vreg"], expected, w["reg"], hit))
    return ok, rows


def check_rule_degree_priority(webs):
    ordered = sorted([w for w in webs.values() if w["degree"] is not None],
                     key=lambda w: -w["degree"])
    rows = []
    ok = True
    for i, w in enumerate(ordered):
        expected = SAVED[i]
        hit = (expected == w["reg"])
        ok = ok and hit
        rows.append((w["name"], w["degree"], expected, w["reg"], hit))
    return ok, rows


def brute_force(webs, realizable):
    names = list(webs.keys())
    n = len(names)
    target_rank = {n_: SAVED.index(TARGET[n_]) for n_ in names if n_ in TARGET}

    solutions = []
    for order in itertools.permutations(names):
        pos = {nm: i for i, nm in enumerate(order)}
        if any(pos[nm] != r for nm, r in target_rank.items()):
            continue
        for bits in range(1 << n):
            is_local = {names[i]: bool(bits >> i & 1) for i in range(n)}
            count = sum(is_local.values())
            cut = n - count
            if any(is_local[order[i]] != (i >= cut) for i in range(n)):
                continue
            if is_local["pool"]:
                continue
            if realizable:
                if webs["pe"]["origin"] == "local" and webs["pe"]["remat"] \
                        and not is_local["pe"]:
                    continue
                if webs["var_r28"]["origin"] == "temp" and is_local["var_r28"]:
                    continue
            sol = {"order": list(order), "is_local": is_local, "cut": cut}
            if sol not in solutions:
                solutions.append(sol)
            if len(solutions) >= 8:
                return solutions
    return solutions


def solve_with_z3(webs):
    from z3 import (Bool, Implies, Int, Not, Solver, And, Distinct, If,
                    sat, unsat)

    names = list(webs.keys())
    target_rank = {n: SAVED.index(TARGET[n]) for n in names if n in TARGET}

    def structural():
        s = Solver()
        v = {n: Int("v_" + n) for n in names}
        rank = {n: Int("rank_" + n) for n in names}
        is_local = {n: Bool("local_" + n) for n in names}
        local_top = Int("local_top")

        for n in names:
            s.add(v[n] >= 1, v[n] <= 400)
            s.add(rank[n] >= 0, rank[n] < len(names))
        s.add(Distinct([rank[n] for n in names]))
        for n in names:
            if n in target_rank:
                s.add(rank[n] == target_rank[n])
        for a, b in itertools.combinations(names, 2):
            s.add(If(rank[a] < rank[b], v[a] > v[b], v[a] < v[b]))

        s.assert_and_track(local_top >= 0, "local_top_nonneg")
        s.assert_and_track(local_top <= 400, "local_top_bounded")
        for n in names:
            s.assert_and_track(Implies(is_local[n], v[n] <= local_top),
                               "R-VREG-BLOCKS:local_under_top_" + n)
            s.assert_and_track(Implies(Not(is_local[n]), v[n] >= local_top + 1),
                               "R-VREG-BLOCKS:temp_over_floor_" + n)
        s.assert_and_track(v["pool"] == webs["pool"]["vreg"],
                           "pool_vreg_invariant")
        s.assert_and_track(Not(is_local["pool"]), "pool_is_temp")
        s.assert_and_track(v["pe"] > v["pool"],
                           "R-COLOR-ORDER+target:pe_out_ranks_pool")
        return s, v, rank, is_local

    s1, v1, r1, l1 = structural()
    ok1 = s1.check() == sat
    model1 = None
    if ok1:
        m = s1.model()
        model1 = {
            "vreg": {n: m.eval(v1[n]).as_long() for n in names},
            "rank": {n: m.eval(r1[n]).as_long() for n in names},
            "is_local": {n: bool(m.eval(l1[n])) for n in names},
        }

    s2, v2, r2, l2 = structural()
    origin = {n: Bool("origin_local_" + n) for n in names}
    remat = {n: Bool("remat_" + n) for n in names}
    recolour = {n: Bool("recolour_" + n) for n in names}
    for n in names:
        s2.assert_and_track(origin[n] if webs[n]["origin"] == "local"
                            else Not(origin[n]), "fact_origin_local_" + n)
        s2.assert_and_track(remat[n] if webs[n]["remat"]
                            else Not(remat[n]), "fact_remat_" + n)
        s2.assert_and_track(
            Implies(And(origin[n], Not(l2[n])), recolour[n]),
            "promote_requires_split_" + n)
        s2.assert_and_track(Implies(recolour[n], Not(remat[n])),
                            "R-SPLIT:recolour_needs_nonremat_" + n)

    res2 = s2.check()
    core2 = None
    if res2 == unsat:
        core2 = sorted(str(c) for c in s2.unsat_core())
    model2 = None
    if res2 == sat:
        m = s2.model()
        model2 = {
            "vreg": {n: m.eval(v2[n]).as_long() for n in names},
            "rank": {n: m.eval(r2[n]).as_long() for n in names},
            "is_local": {n: bool(m.eval(l2[n])) for n in names},
        }
    return ok1, model1, (str(res2), core2, model2)


def solve_no_z3(webs):
    sols1 = brute_force(webs, realizable=False)
    sols2 = brute_force(webs, realizable=True)
    model1 = None
    if sols1:
        s = sols1[0]
        order = s["order"]
        model1 = {
            "vreg": {n: 200 - i for i, n in enumerate(order)},
            "rank": {n: i for i, n in enumerate(order)},
            "is_local": s["is_local"],
        }
    return bool(sols1), model1, ("sat" if sols2 else "unsat", None, None)


HARNESS_CANDIDATES = [
    ("baseline", []),
    ("pe-addr-taken", [
        ("  f32* const pe = lbl_1_data_3918;\n",
         "  f32* pe = lbl_1_data_3918;\n  f32** ppe = &pe;\n"),
        ("(pe + 17)", "(*ppe + 17)"),
        ("pe[3]", "(*ppe)[3]"),
        ("pe[18]", "(*ppe)[18]"),
    ]),
    ("pe-addr-func-scope", [
        ("  f32* const pe = lbl_1_data_3918;\n",
         "  f32* const pe = lbl_1_data_3918;\n  f32* const* ppe = &pe;\n"),
        ("      s32 hwg = *((s32*)(pe + 17));\n",
         "      s32 hwg = *((s32*)((*ppe) + 17));\n"),
        ("fabsf(temp_f31 * pe[3])", "fabsf(temp_f31 * (*ppe)[3])"),
    ]),
    ("var_r28-decl-local", [
        ("  f32* const pe = lbl_1_data_3918;\n",
         "  f32* const pe = lbl_1_data_3918;\n  s32 var_r28 = 0;\n"),
        ("  s32 var_r28 = (flags0 & 0x40000) != 0;\n",
         "  var_r28 = (flags0 & 0x40000) != 0;\n"),
    ]),
    ("pe-addr-func+var_r28-local", [
        ("  f32* const pe = lbl_1_data_3918;\n",
         "  f32* const pe = lbl_1_data_3918;\n  f32* const* ppe = &pe;\n  s32 var_r28 = 0;\n"),
        ("      s32 hwg = *((s32*)(pe + 17));\n",
         "      s32 hwg = *((s32*)((*ppe) + 17));\n"),
        ("fabsf(temp_f31 * pe[3])", "fabsf(temp_f31 * (*ppe)[3])"),
        ("  s32 var_r28 = (flags0 & 0x40000) != 0;\n",
         "  var_r28 = (flags0 & 0x40000) != 0;\n"),
    ]),
]


def run_harness():
    perm = os.path.join(os.environ.get("TEMP", ""), "opencode", "perm")
    if not os.path.isdir(perm):
        print("harness dir not found:", perm)
        return []
    sys.path.insert(0, perm)
    import probe as P
    jobs = []
    for name, edits in HARNESS_CANDIDATES:
        jobs.append((name, P.build(edits) if edits else P.build([])))
    return P.run(jobs)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--harness", action="store_true")
    ap.add_argument("--no-z3", action="store_true",
                    help="force the pure-python fallback solver")
    ap.add_argument("--json", default=None)
    args = ap.parse_args()

    webs = load_webs(args.db)
    names = list(webs.keys())

    print("=" * 78)
    print("COLOURING CONSTRAINT MODEL  --  KartState::updateCollisions")
    print("=" * 78)
    print("saved ladder (R-COLOR-ORDER):", " ".join(SAVED[:len(names)]))
    print("target          : " + "  ".join("%s=%s" % (k, v) for k, v in TARGET.items()))
    print("webs (base93)   :")
    for n in names:
        w = webs[n]
        print("  %-8s vreg=%-4s deg=%-4s kind=%-6s origin=%-6s remat=%s"
              % (n, w["vreg"], w["degree"], w["kind"], w["origin"], w["remat"]))

    print("\n-- VALIDATION: R-COLOR-ORDER reproduces the base93 colouring --")
    ok_order, rows = check_rule_r_color_order(webs)
    for n, vreg, exp, got, hit in rows:
        print("  %-8s v%-4d rank->%-4s observed %-4s %s"
              % (n, vreg, exp, got, "OK" if hit else "MISMATCH"))
    print("  R-COLOR-ORDER matches base93:", ok_order)

    print("\n-- FALSIFICATION: degree-priority cannot explain base93 --")
    ok_deg, rows = check_rule_degree_priority(webs)
    for n, deg, exp, got, hit in rows:
        print("  %-8s deg=%-4s rank->%-4s observed %-4s %s"
              % (n, deg, exp, got, "OK" if hit else "MISMATCH"))
    print("  degree-priority matches base93:", ok_deg)

    have_z3 = not args.no_z3
    if have_z3:
        try:
            import z3  # noqa
        except ImportError:
            have_z3 = False
    print("\nsolver backend:", "z3" if have_z3 else "brute-force fallback")

    if have_z3:
        ok1, model1, res2 = solve_with_z3(webs)
    else:
        ok1, model1, res2 = solve_no_z3(webs)

    print("\n" + "=" * 78)
    print("MODEL 1  (pure colouring: R-COLOR-ORDER + R-VREG-BLOCKS + target)")
    print("=" * 78)
    print("result:", "SAT" if ok1 else "UNSAT")
    if ok1:
        order = sorted(names, key=lambda n: -model1["vreg"][n])
        print("required descending-vreg order (= creation order, last first):")
        for i, n in enumerate(order):
            print("  rank %d  %-8s vreg=%-4d %-6s  <- %s"
                  % (i, n, model1["vreg"][n],
                     "LOCAL" if model1["is_local"][n] else "temp",
                     TARGET.get(n, "(unconstrained)")))
        print("REQUIRED membership:")
        print("  pe      must be a TEMP with vreg > pool(%d)" % webs["pool"]["vreg"])
        print("  var_r28 must be a LOCAL (or temp with vreg < pool) so it ranks below pool")
        print("  pool    stays TEMP vreg %d" % webs["pool"]["vreg"])
        print("  proxyF  local/split with vreg below var_r28")
        print("REQUIRED relative creation order: pe AFTER pool, var_r28 BEFORE pool.")

    print("\n" + "=" * 78)
    print("MODEL 2  (source-realizable: + R-SPLIT, declared-local can't out-rank temp)")
    print("=" * 78)
    status2, core2, model2 = res2
    print("result:", status2.upper())
    if status2 == "unsat":
        print("INFEASIBILITY PROOF (unsat core):")
        if core2:
            for c in core2:
                print("   .", c)
        print("  pe is declared `f32* const pe = lbl_1_data_3918`, a REMATERIALIZABLE")
        print("  global address (R3-A/R3-D: 15 uses -> 15 lis; copies fold).")
        print("  For pe to reach r30 it must out-rank pool => be a TEMP.")
        print("  To become a temp it must be lifetime-split-and-recoloured (R-SPLIT),")
        print("  which requires NON-rematerializable; pe is rematerializable, FOLD.")
        print("  Keeping pe a declared local forces vreg <= local_top < pool,")
        print("  so pe can never out-rank pool.  Both branches contradict pe>pool.")
    elif model2:
        print("source-realizable configuration exists:", model2)

    print("\n-- SOURCE-SHAPE REQUIREMENT --")
    print("  pe must become a long-lived backend TEMP numbered ABOVE the temp floor")
    print("  AND above the pool's vreg, i.e. created after the pool. No C++ source")
    print("  form does this for a constant global address: a declared pointer is a")
    print("  local (below the floor), and a rematerializable value folds on split.")

    result = {
        "validation_color_order": ok_order,
        "validation_degree_priority": ok_deg,
        "model1_sat": ok1,
        "model1": model1,
        "model2_status": status2,
        "model2_core": core2,
    }

    if args.harness:
        print("\n" + "=" * 78)
        print("HARNESS TEST  (base = %.4f)" % BASE93_SCORE)
        print("=" * 78)
        res = run_harness()
        best = max((r[1] or 0) for r in res) if res else 0
        result["harness"] = [{"name": r[0], "score": r[1], "note": r[2]} for r in res]
        result["harness_best"] = best
        result["beat_base"] = best > BASE93_SCORE
        print("best:", best, "| beat %.4f:" % BASE93_SCORE, best > BASE93_SCORE)

    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump(result, fh, indent=2, default=str)
        print("\nwrote", args.json)
    return result


if __name__ == "__main__":
    main()
