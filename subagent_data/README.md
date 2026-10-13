# subagent_data — structured dataset of the `updateCollisions` subagent runs

Machine-readable record of the 26 agent runs, every discriminative experiment, **every
data-harvesting method used across the whole project**, the **tools built over the data**,
and the **formal proofs** reached. Built for **tooling**, not prose: fixed columns,
normalized categories, numeric `score`/`delta`, a comparable `registers` tuple, and **FTS5**.

## Files
| file | what |
|---|---|
| `subagents.db` | SQLite: `agents`, `trials`, `regalloc`, `findings`, `rules`, `harvest_methods`, `tools_built`, `proofs` + FTS5 |
| `schema.sql` | exact DDL (`sqlite3 subagents.db .schema`) |
| `agents.jsonl` `trials.jsonl` `regalloc.jsonl` `findings.jsonl` `rules.jsonl` | mirrors |
| `harvest_methods.jsonl` `tools_built.jsonl` `proofs.jsonl` | mirrors |
| `extra_*.jsonl` | rows appended by tools (merged on rebuild) |
| `tools/` | the DB-driven tools (see below) |
| `build_db.py` | regenerates everything (merges `extra_*.jsonl`) |
| `README.md` | this file |

Rebuild: `python build_db.py` (idempotent; picks up `extra_*.jsonl`).

## Schema (all tables)
```
agents(agent_id, round, angle, model, status, best_score, beat_base, summary, key_finding)
trials(trial_id, agent_id, label, category, edit_from, edit_to,
       score, base, delta, registers, instr_count, beat, notes)
regalloc(id, build_id, source, name, vreg, degree, reg, flags)
findings(finding_id, agent_id, kind, statement, evidence)     # kind: rule|mechanism|gotcha|consequence|result
rules(rule_id, statement, evidence, consequence)
harvest_methods(method_id, name, category, tool, collects, command, used_for)
tools_built(tool_id, name, paradigm, path, purpose, key_output)
proofs(proof_id, kind, statement, method, evidence)
processes(process_id, name, category, purpose, steps, tools, result, agents)
comparisons(cmp_id, a, b, relationship, note)   # relationship: subsumes|supersedes|complements|contrasts-with
```
- See `../PROCESSES_AND_PROOFS.md` for the prose log of all 39 processes + 23 comparisons + 4 proofs.
- `trials.category` ∈ {reference, declaration, lifetime-split, coalescing, type, expression,
  structure, loop, flag, tu-context}. `registers` = `"pe/var_r28/proxy/pool"` (`-` unmeasured).
- `harvest_methods.category` ∈ {measure, disasm, symbols, reloc, data, compiler, permuter,
  external, vreg-internals, edit-generation, meta}.
- `tools_built.paradigm` ∈ {analytics, graph, retrieval, solver, ETL, harness, internals, linking}.

## Tools in `tools/` (all read `subagents.db`)
| tool | paradigm | what it does |
|---|---|---|
| `analyze_db.py` | analytics | joins tables; delta-by-category; token→register-move correlation; regalloc↔score; ranked untried levers |
| `regstate_graph.py` | graph | builds a register-state graph; BFS/Dijkstra to the target colour state; emits `candidates.json` |
| `kb_retrieval.py` | retrieval | FTS + TF-IDF semantic search; `synthesize()`; `uncross()` mechanism×node gaps |
| `colour_solver.py` | solver | encodes the MWCC colour model in z3 (or a fallback); solves for / proves the target colouring |
| `run_and_log.py` | ETL | runs candidates, extracts the colour tuple from the object, writes rows back + refreshes FTS |
| `hypotheses_uc.py` | runner | the retrieval-driven hypothesis test batch |

## Formal results (table `proofs`)
- **no-path** (from `regstate_graph.py`): no recorded/newly-tested edit moves the colour state
  `{pe=r28,var_r28=r30,proxy=r26,pool=r29}` → `{pe=r30,var_r28=r28,…}`; the target node has 0 in-edges.
- **infeasibility (UNSAT)** (from `colour_solver.py`): `pe=r30` needs `v(pe)>v(pool)`; a local has
  `v ≤ local_top < v(pool)` (R-VREG-BLOCKS); a split copy folds because `pe` is a rematerializable
  constant address (R-SPLIT) ⇒ the source-realizable target colouring is **unsatisfiable**.
- **measurement-invariance**: no compiler (28 builds) / flag (~70 combos) / declaration / type /
  structure / loop / TU-context edit beats 93.4368.

## Query examples (SQL)
```sql
-- every trial that improved on its base (the only outcomes worth proposing)
SELECT agent_id,label,score,base,delta,registers FROM trials WHERE beat=1;

-- rank lever classes by effect
SELECT category, COUNT(*), MAX(delta), MIN(delta) FROM trials GROUP BY category;

-- which harvest method found what
SELECT category,tool,collects,used_for FROM harvest_methods ORDER BY category;

-- the tools + their headline outputs
SELECT name,paradigm,key_output FROM tools_built;

-- FTS + join
SELECT t.label,t.score,t.registers FROM fts_trials f JOIN trials t ON t.trial_id=f.rowid
 WHERE fts_trials MATCH 'coalesc OR remateriali*';

-- reconstruct a build's colouring (descending vreg id = assignment order)
SELECT name,vreg,degree,reg,flags FROM regalloc WHERE build_id='base93' ORDER BY vreg DESC;
```

## Tooling conventions
1. Join by `agent_id` across `agents`/`trials`/`findings` to attribute evidence.
2. Filter by `category`/`paradigm`; sort by `delta`; `registers` is a fixed tuple a planner can match.
3. Join `trials.registers` to `regalloc` to explain *why* a score changed (vreg/degree/coalescing).
4. FTS for free text; `beat=1` rows are the only fix candidates.
5. `harvest_methods` + `tools_built` are the catalogue of how this dataset was produced and consumed.

## Coverage / status
- `agents` = 26 (25 rounds R1/R2/META/R3/R4 + 1 ETL); base ladder `86.9928 → 89.7375 → 93.4368`.
- `trials` = representative discriminative set (not all ~150k candidates); full corpus pointers in
  `../SUBAGENT_FIELD_NOTES_updateCollisions.md`.
- Nothing here is a fakematch; the three `rules` + three `proofs` are the reusable deliverables.
