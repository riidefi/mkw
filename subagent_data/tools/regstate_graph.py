#!/usr/bin/env python3
"""regstate_graph.py -- state-space / graph search over REGISTER CONFIGURATIONS
of `KartState::updateCollisions` (Mario Kart Wii matching decomp, MWCC Wii/0x4201_127).

Tool paradigm: graph search.

  NODES  = register configurations.  A configuration is the 4-tuple
           (pe, var_r28, proxy, pool) of physical registers, exactly the
           `trials.registers` field "pe/var_r28/proxy/pool" that the dataset
           normalises.  `-` means "not measured" (an unknown / wildcard slot).
           Nodes are enriched with the per-build vreg/reg table from `regalloc`.

  EDGES  = trials / source edits.  Each trial is an edge from the register
           configuration of the build it was measured against (its `base`) to
           the configuration it produced (`registers`).  Edges carry
           (category, delta, score, edit_from, edit_to, agent_id, notes).

Because the configuration graph is small and the target is a specific tuple,
we can answer the three questions directly:

  1. shortest (fewest hops) and lowest-cost path CURRENT -> TARGET, listing the
     intermediate edits; or a proof that no path exists.
  2. which existing nodes sit next to the TARGET and by which role(s) they differ
     ("neighbourhood" of the target).
  3. which EDGES are missing -- the untried moves that would be required to reach
     the target -- emitted as concrete source-edit candidates (JSON) and,
     optionally, tested against the ground-truth objdiff harness.

Usage
-----
  python regstate_graph.py                       # full report
  python regstate_graph.py --emit-candidates c.json
  python regstate_graph.py --run-harness         # also run candidates through probe.py
  python regstate_graph.py --db ..\\subagents.db

The graph is hand-rolled (no third-party dependency); `networkx` is NOT required.
"""
from __future__ import annotations

import argparse
import collections
import heapq
import json
import os
import sqlite3
import sys

# --------------------------------------------------------------------------
# Domain constants
# --------------------------------------------------------------------------
ROLES = ("pe", "var_r28", "proxy", "pool")
UNKNOWN = "-"

# current state = the 93.4368 build in src/kart/KartState.cpp
CURRENT = ("r28", "r30", "r26", "r29")   # pe=r28, var_r28=r30, proxy=r26, pool=r29
# the target colouring of the original binary
TARGET = ("r30", "r28", "r26", "r29")    # pe=r30, var_r28=r28, proxy=r26, pool=r29

BASE86 = 86.9928
BASE93 = 93.4368

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_DB = os.path.normpath(os.path.join(HERE, "..", "subagents.db"))

# harness (probe.py) lives in %TEMP%\opencode\perm by default
DEFAULT_HARNESS_DIR = os.path.join(os.environ.get("TEMP", ""), "opencode", "perm")


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------
def parse_registers(text):
    """'r28/r30/r26/r29' -> ('r28','r30','r26','r29'); '-' -> UNKNOWN."""
    if not text or text.strip() in ("", UNKNOWN):
        return tuple(UNKNOWN for _ in ROLES)
    parts = [p.strip() for p in text.split("/")]
    parts += [UNKNOWN] * (len(ROLES) - len(parts))
    return tuple(parts[: len(ROLES)])


def node_str(node):
    return "/".join(node)


def known_diffs(a, b):
    """Roles where BOTH a and b are known and differ."""
    return {ROLES[i]: (a[i], b[i]) for i in range(len(ROLES))
            if a[i] != UNKNOWN and b[i] != UNKNOWN and a[i] != b[i]}


def distance(a, b):
    """Hamming distance over known-known role pairs (unknown = wildcard match)."""
    return len(known_diffs(a, b))


# --------------------------------------------------------------------------
# Graph
# --------------------------------------------------------------------------
class Edge:
    __slots__ = ("u", "v", "trial_id", "label", "category", "delta", "score",
                 "base", "edit_from", "edit_to", "agent_id", "notes", "origin")

    def __init__(self, u, v, **kw):
        self.u, self.v = u, v
        for k in self.__slots__[2:]:
            setattr(self, k, kw.get(k))

    @property
    def weight(self):
        """Lower cost for improving edits, higher for regressions."""
        d = self.delta
        if d is None:
            return 1.0
        if d > 0:
            return max(0.10, 1.0 - min(d, 7.0) / 7.0)
        if d == 0:
            return 1.0
        return 1.0 + min(-d, 50.0) / 5.0

    def short(self):
        d = "?" if self.delta is None else "%+.3f" % self.delta
        return "%-28s [%s] %s" % (self.label or "?", self.category or "?", d)


class RegStateGraph:
    def __init__(self):
        self.nodes = {}                      # key -> dict(origin, roles, scores, trials, regalloc)
        self.adj = collections.defaultdict(list)   # key -> [Edge]
        self.edges = []

    # -- construction -------------------------------------------------------
    def add_node(self, key, origin, **meta):
        n = self.nodes.setdefault(key, {"origin": set(), "trials": [], "regalloc": [],
                                        "scores": []})
        n["origin"].add(origin)
        for k, v in meta.items():
            n[k] = v
        return key

    def add_edge(self, u, v, **kw):
        e = Edge(u, v, origin=kw.pop("origin", "trial"), **kw)
        self.adj[u].append(e)
        self.edges.append(e)
        return e

    def neighbors(self, key):
        return self.adj.get(key, [])

    # -- search -------------------------------------------------------------
    def bfs(self, src, dst):
        """Fewest-hops path src->dst. Returns (path, edges) or None."""
        if src == dst:
            return [src], []
        prev = {src: None}
        q = collections.deque([src])
        while q:
            u = q.popleft()
            for e in self.neighbors(u):
                if e.v not in prev:
                    prev[e.v] = e
                    if e.v == dst:
                        path, es = [dst], []
                        while prev[path[-1]] is not None:
                            es.append(prev[path[-1]])
                            path.append(prev[path[-1]].u)
                        return list(reversed(path)), list(reversed(es))
                    q.append(e.v)
        return None

    def dijkstra(self, src, dst):
        """Lowest-cost path src->dst. Returns (path, edges, cost) or None."""
        dist = {src: 0.0}
        prev = {src: None}
        pq = [(0.0, src)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist.get(u, float("inf")):
                continue
            if u == dst:
                break
            for e in self.neighbors(u):
                nd = d + e.weight
                if nd < dist.get(e.v, float("inf")):
                    dist[e.v] = nd
                    prev[e.v] = e
                    heapq.heappush(pq, (nd, e.v))
        if dst not in dist:
            return None
        path, es = [dst], []
        while prev[path[-1]] is not None:
            es.append(prev[path[-1]])
            path.append(prev[path[-1]].u)
        return list(reversed(path)), list(reversed(es)), dist[dst]

    def reachable(self, src):
        seen, q = {src}, collections.deque([src])
        while q:
            u = q.popleft()
            for e in self.neighbors(u):
                if e.v not in seen:
                    seen.add(e.v)
                    q.append(e.v)
        return seen


# --------------------------------------------------------------------------
# Build the graph from the SQLite dataset
# --------------------------------------------------------------------------
def build_graph(db_path):
    con = sqlite3.connect(db_path)
    con.row_factory = sqlite3.Row
    g = RegStateGraph()

    # canonical fixed states ------------------------------------------------
    g.add_node(node_str(CURRENT), "domain", roles=CURRENT,
               note="current 93.4368 src/kart/KartState.cpp")
    g.add_node(node_str(TARGET), "domain", roles=TARGET,
               note="target colouring of the original binary")

    # a base-build node per distinct recorded base score --------------------
    base_nodes = {BASE86: node_str(parse_registers(
        next((r["registers"] for r in con.execute(
            "SELECT registers FROM trials WHERE label='baseline' LIMIT 1")), ""))),
        BASE93: node_str(CURRENT)}

    # regalloc builds -> richer nodes ---------------------------------------
    reg_builds = collections.defaultdict(dict)   # build_id -> role -> reg
    for r in con.execute("SELECT build_id,source,name,vreg,degree,reg,flags FROM regalloc"):
        name, reg, vreg = r["name"], r["reg"], r["vreg"]
        role = None
        if name.startswith("pe"):
            role = "pe"
        elif name.startswith("var_r28"):
            role = "var_r28"
        elif name.startswith("proxy"):
            role = "proxy"
        elif name.startswith("pool"):
            role = "pool"
        if role:
            reg_builds[r["build_id"]][role] = (reg, vreg, r["degree"], r["flags"])
            reg_builds[r["build_id"]].setdefault("_src", r["source"])

    for build, tab in reg_builds.items():
        roles = []
        for role in ROLES:
            roles.append(tab.get(role, (UNKNOWN,))[0])
        key = node_str(tuple(roles))
        g.add_node(key, "regalloc", roles=tuple(roles),
                   regalloc=(build, {k: v for k, v in tab.items() if k != "_src"}),
                   note=tab.get("_src", build))

    # trials -> edges --------------------------------------------------------
    for t in con.execute("SELECT * FROM trials"):
        to_key = node_str(parse_registers(t["registers"]))
        g.add_node(to_key, "trial", roles=parse_registers(t["registers"]))
        base = t["base"]
        if base is not None and abs(base - BASE86) < 1e-3:
            from_key = base_nodes[BASE86]
        elif base is not None and abs(base - BASE93) < 1e-3:
            from_key = base_nodes[BASE93]
        else:
            from_key = "base=%s" % base
            g.add_node(from_key, "synthetic", roles=(UNKNOWN,) * 4)
        g.add_edge(from_key, to_key, trial_id=t["trial_id"], label=t["label"],
                   category=t["category"], delta=t["delta"], score=t["score"],
                   base=base, edit_from=t["edit_from"], edit_to=t["edit_to"],
                   agent_id=t["agent_id"], notes=t["notes"])
        g.nodes[to_key]["trials"].append(t["trial_id"])
        g.nodes[to_key]["scores"].append(t["score"])

    # inferred regalloc edges: both recorded 86.99 baselines -> CURRENT via the
    # winning edit, so the richer vreg nodes are connected to the state space.
    win = next((e for e in g.edges if e.label == "proxyF-split"), None)
    if win is not None:
        for build, tab in reg_builds.items():
            roles = tuple(tab.get(role, (UNKNOWN,))[0] for role in ROLES)
            key = node_str(roles)
            if key != node_str(CURRENT) and base_nodes[BASE86] != key:
                g.add_edge(key, node_str(CURRENT), label="proxyF-split (regalloc-implied)",
                           category="lifetime-split", delta=win.delta, score=win.score,
                           base=BASE86, origin="regalloc-inferred",
                           notes="regalloc build %s -> 93.44 state" % build)
    con.close()
    return g, base_nodes


# --------------------------------------------------------------------------
# Analysis
# --------------------------------------------------------------------------
def neighbourhood(g, dst_key, maxdist=2):
    """Nodes nearest to dst, sorted by known-role Hamming distance."""
    dst = g.nodes[dst_key]["roles"]
    out = []
    for key, meta in g.nodes.items():
        if key == dst_key:
            continue
        d = distance(meta["roles"], dst)
        # require at least the two "invariant" roles (proxy,pool) to be known
        nknown = sum(1 for x in meta["roles"] if x != UNKNOWN)
        if nknown < 3:
            continue
        if d <= maxdist:
            out.append((d, nknown, key, known_diffs(meta["roles"], dst)))
    out.sort(key=lambda x: (x[0], -x[1]))
    return out


def missing_outgoing(g, src_key, dst_key):
    """From src, the required role transitions toward dst, and which existing
    trials already attempt a move in that direction (but land elsewhere)."""
    src = g.nodes[src_key]["roles"]
    dst = g.nodes[dst_key]["roles"]
    required = {ROLES[i]: (src[i], dst[i]) for i in range(len(ROLES))
                if src[i] != dst[i]}
    return required


def graph_stats(g):
    return {
        "nodes": len(g.nodes),
        "edges": len(g.edges),
        "categories": collections.Counter(e.category for e in g.edges),
        "origins": collections.Counter(e.origin for e in g.edges),
        "self_loops": sum(1 for e in g.edges if e.u == e.v),
        "neutral_edges": sum(1 for e in g.edges if e.delta == 0),
        "improving_edges": sum(1 for e in g.edges if e.delta and e.delta > 0),
        "regressing_edges": sum(1 for e in g.edges if e.delta and e.delta < 0),
    }


# --------------------------------------------------------------------------
# Candidate missing edits (the untried moves)
# --------------------------------------------------------------------------
# Each candidate targets the transition CURRENT -> TARGET, i.e. it must move
#   pe       r28 -> r30   (pe must out-rank var_r28 & the pool: vreg > 94)
#   var_r28  r30 -> r28   (var_r28 must fall back into / below the local block)
# The templates below encode the known mechanisms (R-SPLIT, R-VCOLOR-ORDER,
# R-VREG-BLOCKS) as concrete source edits applied on top of the 93.44 source.
_SRC_PE = "  f32* const pe = lbl_1_data_3918;\n"
_SRC_V28 = "  s32 var_r28 = (flags0 & 0x40000) != 0;\n"
_SRC_V28_SHIFT = "  s32 var_r28 = (flags0 >> 18) & 1;\n"
_SRC_PROXYF = "  KartObjectProxy* proxyF = proxy;\n"
_PE18 = "pe[18]"
_PE17 = "(pe + 17)"
_PE3 = "pe[3]"


def candidate_library():
    """Return [{name,intent,move,edits}]. edits = [(old,new), ...] in probe form."""
    C = []

    def add(name, intent, move, edits):
        C.append({"name": name, "intent": intent, "move": move,
                  "edits": [list(x) for x in edits]})

    # A. split pe into a second, address-taken, long-lived web (the proxyF
    #    analogue) so its copy is non-rematerializable and wins a high reg.
    add("peF-split-tail",
        "make pe a non-rematerializable second web for the tail (peF/&peF)",
        "pe r28->r30 ; var_r28 r30->r28",
        [(_SRC_PROXYF, _SRC_PROXYF + "  f32* peF = pe;\n  f32** ppeF = &peF;\n"),
         (_PE17, "(*ppeF + 17)"),
         (_PE3, "(*ppeF)[3]")])

    # B. literal address-take of pe (all uses) -- the recorded destructive move.
    add("pe-addr-all",
        "address-take pe across every use (reliable barrier, known ~70%)",
        "pe -> r30 (destructive)",
        [(_SRC_PE, _SRC_PE + "  f32* const* ppe = &pe;\n"),
         (_PE18, "(*ppe)[18]"),
         ("*((s32*)(pe + 17))", "*((s32*)(*ppe + 17))"),
         (_PE3, "(*ppe)[3]")])

    # C. late copy of pe introduced only in the var_r28==0 tail.
    add("pe-late-copy",
        "create pe's second web late, address-taken, around the tail use only",
        "pe r28->r30 ; var_r28 r30->r28",
        [("    if (var_r28 == 0) {\n",
          "    if (var_r28 == 0) {\n      f32* peLate = pe;\n      f32** ppeLate = &peLate;\n"),
         ("fabsf(temp_f31 * pe[3])", "fabsf(temp_f31 * (*ppeLate)[3])")])

    # D. v28-shift form (known to give pe=r29, var_r28=r27, pool=r30) PLUS a
    #    pe barrier, hoping to bump pe from r29 to r30.
    add("v28shift+peF-split",
        "combine the var_r28 shift form with a peF/&peF split",
        "pe r28->r30 ; var_r28 r30->r28",
        [(_SRC_V28, _SRC_V28_SHIFT),
         (_SRC_PROXYF, _SRC_PROXYF + "  f32* peF = pe;\n  f32** ppeF = &peF;\n"),
         (_PE17, "(*ppeF + 17)"),
         (_PE3, "(*ppeF)[3]")])

    # E. promote pe by making it a mutable, address-taken pointer and keep the
    #    mask form of var_r28 (the winning form).
    add("pe-nonconst-addr-tail",
        "drop const on pe and take its address for the tail region",
        "pe r28->r30 ; var_r28 r30->r28",
        [(_SRC_PE, "  f32* pe = lbl_1_data_3918;\n  f32** ppe = &pe;\n"),
         (_PE17, "(*ppe + 17)"),
         (_PE3, "(*ppe)[3]")])

    # F. force var_r28 into the declared-local block by computing it early
    #    through a named bool and consuming it once.
    add("var-r28-localize",
        "hoist var_r28 into the declared-local block so it can rank below pe",
        "var_r28 r30->r28",
        [(_SRC_V28, "  s32 var_r28 = 0;\n"),
         ("  bool var_r27 = (flags0 & 0x60) != 0;\n",
          "  bool var_r27 = (flags0 & 0x60) != 0;\n  var_r28 = (flags0 & 0x40000) != 0;\n")])

    # G. combine E and F.
    add("pe-addr + var-r28-localize",
        "address-take pe AND localise var_r28 together (both required moves)",
        "pe r28->r30 ; var_r28 r30->r28",
        [(_SRC_PE, "  f32* pe = lbl_1_data_3918;\n  f32** ppe = &pe;\n"),
         (_PE17, "(*ppe + 17)"),
         (_PE3, "(*ppe)[3]"),
         (_SRC_V28, "  s32 var_r28 = 0;\n"),
         ("  bool var_r27 = (flags0 & 0x60) != 0;\n",
          "  bool var_r27 = (flags0 & 0x60) != 0;\n  var_r28 = (flags0 & 0x40000) != 0;\n")])

    # H. store &pe into a slot and reload it late, extending pe's live range.
    add("pe-escapes-slot",
        "let &pe escape into a stack slot, reloading the value late",
        "pe r28->r30 ; var_r28 r30->r28",
        [(_SRC_PE, _SRC_PE + "  f32* const* peSlot = &pe;\n"),
         (_PE17, "(*peSlot + 17)"),
         (_PE3, "(*peSlot)[3]")])

    return C


# --------------------------------------------------------------------------
# Optional ground-truth harness (probe.py in %TEMP%\opencode\perm)
# --------------------------------------------------------------------------
def run_harness(cands, harness_dir):
    probe_path = os.path.join(harness_dir, "probe.py")
    if not os.path.isfile(probe_path):
        print("[harness] probe.py not found at", probe_path)
        return []
    sys.path.insert(0, harness_dir)
    import importlib.util
    spec = importlib.util.spec_from_file_location("probe", probe_path)
    probe = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(probe)

    jobs, meta = [], []
    for c in cands:
        edits = [tuple(e) for e in c["edits"]]
        text = probe.build(edits)
        jobs.append((c["name"], text))
        meta.append(c)
    print("\n[harness] base=%.4f  running %d candidates ..." % (BASE93, len(jobs)))
    res = probe.run(jobs)
    by_name = {n: (s, note) for n, s, note in res}
    out = []
    for c in meta:
        s, note = by_name.get(c["name"], (None, "?"))
        out.append({"name": c["name"], "score": s, "note": note,
                    "beat_base": bool(s is not None and s > BASE93 + 1e-9),
                    "move": c["move"], "intent": c["intent"]})
    return out


# --------------------------------------------------------------------------
# Report
# --------------------------------------------------------------------------
def report(db_path, emit=None, harness=False, harness_dir=DEFAULT_HARNESS_DIR):
    g, base_nodes = build_graph(db_path)
    cur, tgt = node_str(CURRENT), node_str(TARGET)

    stats = graph_stats(g)
    print("=" * 74)
    print("REGISTER-STATE GRAPH  (%s)" % os.path.basename(db_path))
    print("=" * 74)
    print("nodes=%d  edges=%d  self-loops=%d" % (stats["nodes"], stats["edges"], stats["self_loops"]))
    print("edges by outcome: improving=%d neutral=%d regressing=%d"
          % (stats["improving_edges"], stats["neutral_edges"], stats["regressing_edges"]))
    print("edges by category:", dict(stats["categories"]))
    print("edges by origin  :", dict(stats["origins"]))
    print()
    print("CURRENT %s   ->   TARGET %s" % (cur, tgt))
    req = missing_outgoing(g, cur, tgt)
    print("required role transitions:", {k: "%s->%s" % v for k, v in req.items()})

    # ---- path search ------------------------------------------------------
    print("\n-- path search ----------------------------------------------------")
    b = g.bfs(cur, tgt)
    d = g.dijkstra(cur, tgt)
    if b:
        print("fewest-hop path (%d hops):" % (len(b[1])))
        for e in b[1]:
            print("   %s --[%s]--> %s" % (e.u, e.short(), e.v))
    else:
        print("fewest-hop path: NONE (target node is not reachable from CURRENT)")
    if d:
        print("lowest-cost path (cost=%.2f):" % d[2])
        for e in d[1]:
            print("   %s --[%s]--> %s" % (e.u, e.short(), e.v))
    else:
        print("lowest-cost path: NONE")

    # is the target node populated by any measured trial?
    indeg = sum(1 for e in g.edges if e.v == tgt)
    trials_at_tgt = len(g.nodes.get(tgt, {}).get("trials", []))
    print("TARGET node declared anchor: True   measured trial edges into it: %d" % indeg)
    reach = g.reachable(cur)
    print("nodes reachable from CURRENT: %d / %d" % (len(reach), stats["nodes"]))

    # ---- neighbourhood of target -----------------------------------------
    print("\n-- neighbourhood of TARGET (nearest nodes) ------------------------")
    nb = neighbourhood(g, tgt)
    if not nb:
        print("  (none within distance 2 with >=3 known roles)")
    for dist, nknown, key, diffs in nb[:12]:
        print("  d=%d  %-20s  differs: %s" % (dist, key, diffs if diffs else "{}"))
    if not any(dist == 1 for dist, *_ in nb):
        print("  -> NO existing node is distance-1 from TARGET: every route needs >=2 role moves.")

    # ---- missing / untried edges -----------------------------------------
    print("\n-- missing EDGES required to reach TARGET --------------------------")
    for role, (a, b) in req.items():
        print("  %-8s %s -> %s   (no trial edge makes this move)" % (role, a, b))
    print("  existing outgoing tries from CURRENT:")
    seen = set()
    for e in g.neighbors(cur):
        k = (e.v, e.category)
        if k in seen:
            continue
        seen.add(k)
        print("     %-22s -> %-18s [%s] delta=%s" % (e.label, e.v, e.category, e.delta))

    # ---- candidates -------------------------------------------------------
    cands = candidate_library()
    print("\n-- candidate missing edits (untried moves) ------------------------")
    for c in cands:
        print("  * %-26s  %s" % (c["name"], c["intent"]))
        print("       move: %s" % c["move"])
        for o, n in c["edits"]:
            print("       - %r => %r" % (o, n))

    if emit:
        with open(emit, "w", encoding="utf-8") as fh:
            json.dump({"current": list(CURRENT), "target": list(TARGET),
                       "candidates": cands}, fh, indent=2)
        print("\nwrote candidates -> %s" % emit)

    results = None
    if harness:
        results = run_harness(cands, harness_dir)
        print("\n-- harness results (objdiff %%, base %.4f) -----------------------" % BASE93)
        for r in sorted(results, key=lambda r: (r["score"] is None, -(r["score"] or 0))):
            print("  %8s  %-26s %s%s" % (r["score"], r["name"],
                                          "BEAT" if r["beat_base"] else "", r["note"]))
        beats = [r for r in results if r["beat_base"]]
        print("  -> %d/%d candidates beat %.4f" % (len(beats), len(results), BASE93))

    return {"stats": stats, "path_bfs": bool(b), "path_dijkstra": bool(d),
            "target_present": tgt in g.nodes, "neighbourhood": nb,
            "required": req, "candidates": cands, "harness": results}


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--emit-candidates", default=None, metavar="JSON")
    ap.add_argument("--run-harness", action="store_true",
                    help="compile+objdiff the candidate edits via probe.py")
    ap.add_argument("--harness-dir", default=DEFAULT_HARNESS_DIR)
    args = ap.parse_args()
    report(args.db, emit=args.emit_candidates, harness=args.run_harness,
           harness_dir=args.harness_dir)


if __name__ == "__main__":
    main()
