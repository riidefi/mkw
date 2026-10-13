#!/usr/bin/env python3
"""kb_retrieval.py -- retrieval + synthesis over the updateCollisions subagent KB.

Two retrieval layers over every row of subagents.db (trials / findings / rules /
agents / regalloc):

  1. lexical  : the pre-built SQLite FTS5 indexes (fts_trials, fts_findings,
                fts_agents).  rules/regalloc have no FTS table, so they are
                covered by the semantic layer below.
  2. semantic : a hand-rolled TF-IDF vector space with domain synonym
                expansion (no sklearn / network needed).  This is what lets a
                *conceptual* query such as

                    "a value that cannot be rematerialized created after the
                     constant pool"

                rank the vreg-index / pool / rematerialization rows even though
                almost none of those words appear literally in a single row.

API:
    search(query, k=10, sources=None)   -> ranked list[dict]
    synthesize(topic, k=8)              -> dict + printable candidate hypotheses
    propose_hypotheses(topics)          -> un-crossed construct combinations

CLI:
    python kb_retrieval.py search "rematerializable value after pool"
    python kb_retrieval.py synth  "pe rematerialization vreg pool gameMode"
    python kb_retrieval.py uncross
    python kb_retrieval.py sql "SELECT ..."
"""
import os
import re
import math
import json
import sqlite3
import argparse
from collections import Counter, defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.dirname(HERE)
DB = os.path.join(DATA, "subagents.db")

TOKEN_RE = re.compile(r"[a-z0-9_]+")

# domain synonyms -> canonical concept tokens.  A query token expands to all of
# its aliases (and vice-versa) so surface wording does not gate recall.
SYNONYMS = {
    "remateriali": ["rematerialize", "rematerialized", "rematerialization",
                    "remat", "fold", "folded", "constant", "address"],
    "rematerialize": ["remateriali", "fold", "constant"],
    "rematerialized": ["remateriali", "fold", "constant"],
    "rematerialization": ["remateriali", "fold", "constant"],
    "coalesc": ["coalesce", "coalesced", "coalescing", "coalesceinto",
                "fc_oalescedinto", "copy", "propagation"],
    "coalesce": ["coalesc", "copy", "propagation"],
    "coalescing": ["coalesc", "copy"],
    "vreg": ["vregs", "virtual", "index", "color", "colour", "coloring",
             "colouring", "regalloc", "web", "node"],
    "colour": ["color", "vreg", "regalloc", "coloring", "colouring", "assignment"],
    "color": ["colour", "vreg", "regalloc", "assignment"],
    "regalloc": ["register", "allocation", "color", "colour", "vreg", "web"],
    "pool": ["rodata", "constant", "literal", "sda", "sdata", "temp"],
    "rodata": ["pool", "constant", "literal"],
    "pe": ["lbl_1_data_3918", "3918", "global", "array", "pointer", "address"],
    "proxy": ["mproxy", "pproxy", "kartobjectproxy", "proxyf", "pointer"],
    "proxyf": ["proxy", "split", "lifetime"],
    "split": ["lifetime", "live", "range", "web", "copy", "duplicate"],
    "lifetime": ["split", "live", "range", "web"],
    "live": ["lifetime", "range", "overlap", "web"],
    "gamemode": ["game", "mode", "scenario", "racemode"],
    "playeridx": ["player", "index", "clrlwi", "u8"],
    "registers": ["register", "saved", "gpr", "r28", "r29", "r30", "r31"],
    "r28": ["register", "saved"],
    "r29": ["register", "saved"],
    "r30": ["register", "saved"],
    "r31": ["register", "saved"],
}

# the physical-slot tuple this dataset normalises to
REG_SLOTS = ["pe", "var_r28", "proxy", "pool"]


# --------------------------------------------------------------------------- #
# corpus
# --------------------------------------------------------------------------- #
def _rules():
    return [
        ("pe", "f32* const pe = lbl_1_data_3918;"),
        ("var_r28", "s32 var_r28 = (flags0 >> 18) & 1;  [or mask form]"),
        ("proxy", "KartObjectProxy* proxy = mProxy;  (+ pproxy = &proxy)"),
        ("pool", "compiler rodata literal pool (lbl_1_rodata_27D0)"),
        ("flags0", "u32 flags0 = (*pproxy)->kartState()->field(0);"),
        ("gameMode", "rc->mRaceScenario.mSettings.mGameMode"),
        ("playerIdx", "proxyF->getPlayerIdx()"),
        ("ci.flags", "u32 f = ci.flags;  (KartCollisionInfo::flags)"),
    ]


class Corpus:
    """One uniform document per DB row, plus the two indexes over it."""

    def __init__(self, db_path=DB):
        self.db_path = db_path
        self.rows = []
        self._load()
        self._build_semantic()

    # -- loading ----------------------------------------------------------- #
    def _load(self):
        con = sqlite3.connect(self.db_path)
        con.row_factory = sqlite3.Row
        c = con.cursor()
        for r in c.execute("SELECT * FROM trials"):
            self._add(
                "trial", r["trial_id"],
                f"trial {r['label']} [{r['category']}] {r['edit_from']} -> "
                f"{r['edit_to']}",
                " ".join(str(r[k]) for k in
                         ("label", "category", "edit_from", "edit_to", "notes",
                          "registers") if r[k] is not None),
                {k: r[k] for k in r.keys()})
        for r in c.execute("SELECT * FROM findings"):
            self._add(
                "finding", r["finding_id"],
                f"finding {r['kind']} by {r['agent_id']}",
                " ".join(str(r[k]) for k in ("kind", "statement", "evidence")
                         if r[k] is not None),
                {k: r[k] for k in r.keys()})
        for r in c.execute("SELECT * FROM rules"):
            self._add(
                "rule", r["rule_id"], f"rule {r['rule_id']}",
                " ".join(str(r[k]) for k in
                         ("statement", "evidence", "consequence")
                         if r[k] is not None),
                {k: r[k] for k in r.keys()})
        for r in c.execute("SELECT * FROM agents"):
            self._add(
                "agent", r["agent_id"],
                f"agent {r['agent_id']} ({r['round']}) {r['angle']}",
                " ".join(str(r[k]) for k in
                         ("angle", "summary", "key_finding", "model", "status")
                         if r[k] is not None),
                {k: r[k] for k in r.keys()})
        for r in c.execute("SELECT * FROM regalloc"):
            self._add(
                "regalloc", r["id"],
                f"regalloc {r['build_id']}/{r['name']} v{r['vreg']} -> {r['reg']}",
                " ".join(str(r[k]) for k in
                         ("build_id", "source", "name", "reg", "flags")
                         if r[k] is not None),
                {k: r[k] for k in r.keys()})
        con.close()

    def _add(self, kind, rid, title, text, payload):
        self.rows.append({
            "doc_id": f"{kind}:{rid}",
            "kind": kind,
            "rid": rid,
            "title": title,
            "text": text,
            "payload": payload,
        })

    # -- semantic (hand-rolled TF-IDF + cosine) ---------------------------- #
    @staticmethod
    def _tokens(text):
        toks = TOKEN_RE.findall(text.lower())
        out = []
        for t in toks:
            out.append(t)
            # keep "var_r28"/"r28" style compounds searchable as parts too
            if "_" in t:
                out.extend(p for p in t.split("_") if p)
        return out

    def _expand(self, tokens):
        out = list(tokens)
        for t in tokens:
            for a in SYNONYMS.get(t, ()):
                out.append(a)
        return out

    def _build_semantic(self):
        self.N = len(self.rows)
        self.df = Counter()
        raw = []
        for row in self.rows:
            toks = self._tokens(row["title"] + " " + row["text"])
            raw.append(toks)
            for t in set(toks):
                self.df[t] += 1
        self.idf = {t: math.log((self.N + 1) / (d + 1)) + 1.0
                    for t, d in self.df.items()}
        self.doc_vec = []
        for toks in raw:
            self.doc_vec.append(self._vector(toks))

    def _vector(self, tokens):
        tf = Counter(self._expand(tokens))
        vec = {}
        for t, n in tf.items():
            if t in self.idf:
                vec[t] = (1.0 + math.log(n)) * self.idf[t]
        norm = math.sqrt(sum(v * v for v in vec.values())) or 1.0
        return {t: v / norm for t, v in vec.items()}

    def _sem(self, query):
        qv = self._vector(self._tokens(query))
        scores = {}
        for i, dv in enumerate(self.doc_vec):
            # sparse dot product (both unit-normalised => cosine)
            s = 0.0
            small, big = (qv, dv) if len(qv) < len(dv) else (dv, qv)
            for t, v in small.items():
                s += v * big.get(t, 0.0)
            if s:
                scores[i] = s
        return scores

    # -- lexical (FTS5) ---------------------------------------------------- #
    @staticmethod
    def _fts_query(query):
        toks = [t for t in TOKEN_RE.findall(query.lower()) if len(t) > 1]
        if not toks:
            return None
        # OR the terms and allow prefix matching for recall
        return " OR ".join(f'"{t}"*' for t in toks)

    def _lexical(self, query):
        mq = self._fts_query(query)
        if not mq:
            return {}
        con = sqlite3.connect(self.db_path)
        c = con.cursor()
        hits = defaultdict(float)
        # map (table -> doc kind, id column)
        for table, kind in (("fts_trials", "trial"),
                            ("fts_findings", "finding"),
                            ("fts_agents", "agent")):
            try:
                rows = c.execute(
                    f"SELECT rowid, bm25({table}) AS r FROM {table} "
                    f"WHERE {table} MATCH ? ORDER BY r LIMIT 200", (mq,)
                ).fetchall()
            except sqlite3.OperationalError:
                continue
            for rank, (rowid, r) in enumerate(rows):
                # bm25 is lower=better; convert to a bounded bonus
                hits[f"{kind}:{rowid}"] += 1.0 / (1.0 + rank)
        con.close()
        return hits

    # -- public ------------------------------------------------------------ #
    def search(self, query, k=10, sources=None, weights=(1.0, 0.6)):
        """Hybrid search.  `sources` filters by kind (subset of trial/finding/
        rule/agent/regalloc).  Returns ranked dicts with score + provenance."""
        sem = weights[0]
        lex = weights[1]
        scores = {}
        for i, s in self._sem(query).items():
            scores[i] = sem * s
        for doc_id, bonus in self._lexical(query).items():
            idx = self._index.get(doc_id)
            if idx is not None:
                scores[idx] = scores.get(idx, 0.0) + lex * bonus
        if not scores:  # fall back to pure token overlap for odd queries
            qt = set(self._tokens(query))
            for i, row in enumerate(self.rows):
                ov = len(qt & set(self._tokens(row["title"] + " " + row["text"])))
                if ov:
                    scores[i] = ov / max(1, len(qt))
        ranked = []
        for i, s in scores.items():
            row = self.rows[i]
            if sources and row["kind"] not in sources:
                continue
            ranked.append({**row, "score": round(s, 4)})
        ranked.sort(key=lambda r: -r["score"])
        return ranked[:k]

    # filled lazily so _lexical can map doc_id -> row index
    @property
    def _index(self):
        if not hasattr(self, "_idx_cache"):
            self._idx_cache = {r["doc_id"]: i for i, r in enumerate(self.rows)}
        return self._idx_cache

    def by_kind(self, kind):
        return [r for r in self.rows if r["kind"] == kind]

    def sql(self, q, args=()):
        con = sqlite3.connect(self.db_path)
        con.row_factory = sqlite3.Row
        try:
            return [dict(r) for r in con.execute(q, args).fetchall()]
        finally:
            con.close()


# --------------------------------------------------------------------------- #
# synthesis
# --------------------------------------------------------------------------- #
def _clean(text, n=240):
    text = re.sub(r"\s+", " ", str(text)).strip()
    return text if len(text) <= n else text[: n - 1] + "…"


def synthesize(kb, topic, k=8, sources=("rule", "finding", "trial")):
    """Pull the top rows for `topic` and stitch their statements/evidence into
    a candidate hypothesis.  Returns a dict (also pretty-printable)."""
    hits = kb.search(topic, k=k, sources=sources)
    rules = kb.by_kind("rule")
    # always surface the reusable rules -- they are the transformation grammar
    stmts, evid = [], []
    for h in hits:
        p = h["payload"]
        if h["kind"] == "rule":
            stmts.append(f"[{p['rule_id']}] {_clean(p['statement'])}")
            evid.append(f"{p['rule_id']}: {_clean(p['evidence'])}")
        elif h["kind"] == "finding":
            stmts.append(f"[{p['kind']}:{h['rid']}] {_clean(p['statement'])}")
            evid.append(f"find {h['rid']}: {_clean(p['evidence'])}")
        elif h["kind"] == "trial":
            stmts.append(f"[{p['label']} {p['score']}%] {_clean(p['edit_from'])} -> "
                         f"{_clean(p['edit_to'])}")
            evid.append(f"trial {p['trial_id']}: regs={p['registers']} "
                        f"instrs={p['instr_count']} beat={p['beat']} ({_clean(p['notes'])})")
    return {
        "topic": topic,
        "hits": hits,
        "statements": stmts,
        "evidence": evid,
        "rules": [f"[{r['rid']}] {r['payload']['statement']}" for r in rules],
        "hypothesis": _stitch(topic, stmts, rules),
    }


def _stitch(topic, stmts, rules):
    grammar = " ; ".join(f"{r['rid']}" for r in rules)
    return (
        f"CANDIDATE: apply the transformation grammar {{{grammar}}} to the "
        f"node(s) implicated by \"{topic}\". Evidence to reconcile: "
        + " | ".join(stmts[:6])
    )


def render(syn):
    out = [f"# synthesize({syn['topic']!r})", "", "## top retrieved statements"]
    out += [f"  - {s}" for s in syn["statements"]] or ["  (none)"]
    out += ["", "## evidence"]
    out += [f"  - {e}" for e in syn["evidence"]] or ["  (none)"]
    out += ["", "## reusable rules (grammar)"]
    out += [f"  - {r}" for r in syn["rules"]]
    out += ["", "## candidate hypothesis", f"  {syn['hypothesis']}"]
    return "\n".join(out)


# --------------------------------------------------------------------------- #
# un-crossed-combination hypothesis generator
# --------------------------------------------------------------------------- #
# "mechanism"  x  "target node" pairs that the trials table has never crossed.
MECHANISMS = {
    "R-SPLIT": ("lifetime split (x2 = x): recolours iff non-rematerializable AND "
                "the copy's live range overlaps the original (not a subset)"),
    "R-COLOR-ORDER": ("colour by descending vreg id; a node must out-rank the "
                      "pool temp to take r30"),
    "R-VREG-BLOCKS": ("declared locals form one reverse-order block below all "
                      "temps; a first-declared local is pinned below the pool"),
}
TARGET_NODES = [
    ("pe", "f32* const pe = lbl_1_data_3918;  (rematerializable global address)"),
    ("var_r28", "s32 var_r28 = (flags0 & 0x40000) != 0;  (anon long-lived temp v94)"),
    ("pool", "compiler rodata literal pool temp (v88 -> r29)"),
    ("flags0", "u32 flags0 = (*pproxy)->kartState()->field(0);  (load)"),
    ("gameMode", "rc->mRaceScenario.mSettings.mGameMode  (4-instr size gap)"),
    ("proxy", "KartObjectProxy* proxy = mProxy;  (already split -> proxyF)"),
    ("ci.flags", "u32 f = ci.flags;  (long-lived loaded mask)"),
]


MECHANISM_TOKENS = {
    "R-SPLIT": {"split", "lifetime", "proxyf", "pef", "proxy2"},
    "R-COLOR-ORDER": {"vreg", "descending", "order", "degree"},
    "R-VREG-BLOCKS": {"decl", "declaration", "block", "reorder", "perm", "local"},
}
NODE_TOKENS = {
    "pe": {"pe", "pef", "3918"},
    "var_r28": {"var_r28", "v28", "r28"},
    "pool": {"pool", "rodata"},
    "flags0": {"flags0", "pf0"},
    "gameMode": {"gamemode", "mode"},
    "proxy": {"proxy", "mproxy", "pproxy"},
    "ci.flags": {"ci.flags", "flags"},
}


def propose_hypotheses(kb, topics=None, k=6):
    """Enumerate mechanism x target-node combinations and mark which ones the
    trials table already covers, so the caller only sees novel crossings."""
    trial_texts = [t["text"].lower() for t in kb.by_kind("trial")]
    results = []
    for mech, desc in MECHANISMS.items():
        for node, node_desc in TARGET_NODES:
            ntoks = NODE_TOKENS[node]
            mtoks = MECHANISM_TOKENS[mech]
            covered = any(
                any(nt in tt for nt in ntoks) and any(mt in tt for mt in mtoks)
                for tt in trial_texts
            )
            results.append({
                "key": f"{mech}::{node}", "mechanism": mech, "node": node,
                "mechanism_desc": desc, "node_desc": node_desc,
                "novel": not covered,
            })
    return results


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #
def _cli():
    ap = argparse.ArgumentParser(description=__doc__)
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("search")
    p.add_argument("query")
    p.add_argument("-k", type=int, default=10)
    p.add_argument("--sources", default=None,
                   help="comma list: trial,finding,rule,agent,regalloc")

    p = sub.add_parser("synth")
    p.add_argument("topic")
    p.add_argument("-k", type=int, default=8)

    sub.add_parser("uncross")

    p = sub.add_parser("sql")
    p.add_argument("query")

    a = ap.parse_args()
    kb = Corpus()
    if a.cmd == "search":
        src = a.sources.split(",") if a.sources else None
        for r in kb.search(a.query, k=a.k, sources=src):
            print(f"{r['score']:8.4f}  {r['doc_id']:<16} {r['title']}")
            print(f"          {_clean(r['text'], 200)}")
    elif a.cmd == "synth":
        print(render(synthesize(kb, a.topic, k=a.k)))
    elif a.cmd == "uncross":
        for h in propose_hypotheses(kb):
            flag = "NOVEL" if h["novel"] else "tested"
            print(f"[{flag}] {h['key']:<26} node={h['node']}")
            print(f"          {h['node_desc']}")
    elif a.cmd == "sql":
        for row in kb.sql(a.query):
            print(json.dumps(row, ensure_ascii=False))


if __name__ == "__main__":
    _cli()
