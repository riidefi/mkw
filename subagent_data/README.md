# subagent_data — structured dataset of the `updateCollisions` subagent runs

Machine-readable record of the ~96 agent runs, every discriminative experiment, **every
data-harvesting method used across the whole project**, the **tools built over the data**,
and the **formal results** reached. Built for **tooling**, not prose: fixed columns,
normalized categories, numeric `score`/`delta`, a comparable `registers` tuple, and **FTS5**.

**Outcome:** `KartState::updateCollisions` went **86.9928 → 97.7327** (838/838 instructions)
on the stock compiler via four source *shapes*, then plateaued; the last 19 instructions are
allocator/scheduler-locked (see `../SUBAGENT_FIELD_NOTES_updateCollisions.md`).

## Files
| file | what |
|---|---|
| `subagents.db` | SQLite: `agents`, `trials`, `regalloc`, `findings`, `rules`, `harvest_methods`, `tools_built`, `proofs` + FTS5 |
| `schema.sql` | exact DDL (`sqlite3 subagents.db .schema`) |
| `agents.jsonl` `trials.jsonl` `regalloc.jsonl` `findings.jsonl` `rules.jsonl` | mirrors |
| `harvest_methods.jsonl` `tools_built.jsonl` `proofs.jsonl` | mirrors |
| `extra_*.jsonl` | rows appended by tools (merged on rebuild) |
| `tools/` | the DB-driven tools (see below) |
| `artifacts/` | the durable artefact collection (winning sources, compiler patch, harness, decomp.me) — see `artifacts/README.md` |
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
artifacts(artifact_id, kind, path, round, score, description)   # the durable files under artifacts/
```
- See `../PROCESSES_AND_PROOFS.md` for the prose log of the processes + comparisons + proofs.
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
- **counterexample(escape) [SUPERSEDES the proofs below]**: the target colour state IS reachable —
  **93.4368 → 94.3914** with `pe=r30` via a sub-address temp (`p3 = lbl+3; pe = p3-3`) plus
  declaring `var_r28`/`var_r27` first. The proofs below all *assumed* `pe` stayed a declared local.
- **no-path [FALSIFIED]**, **infeasibility(UNSAT) [FALSIFIED]**,
  **measurement-invariance [FALSIFIED]**: each was premise-limited (a declared local `pe`); the
  sub-address escape makes `pe` a compiler temp. Kept for the record; do not rely on them.
- **infeasibility(UNSAT, extended/full) [superseded]**: same caveat.
- The real, surviving result is empirical: the **last 19 instructions** (GPR prologue colour tie +
  FPR names + dot/sqrt schedule) are allocator/scheduler-locked under `0x4201_127` — ~150k+
  candidates and a full compiler RE (allocator *and* scheduler) found no source shape.

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

-- the durable artefact collection (winning sources / compiler patch / harness)
SELECT artifact_id,kind,score,path FROM artifacts ORDER BY artifact_id;

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
- `agents` ≈ 96 across ~22 rounds (R1–R4, META, D, E, F, G, H, I, J, K, L, CC, SH, SR, T, U, V,
  W, X, Y, Z, AY, AS). Score ladder: `86.9928 → 89.7375 → 93.4368 → 94.3914 → 95.9427 → 97.0167 → 97.7327`.
- `trials` = representative discriminative set (not all ~150k candidates); full corpus pointers in
  `../SUBAGENT_FIELD_NOTES_updateCollisions.md`.
- Nothing here is a fakematch; the committed source is at **97.7327** with the stock compiler. The
  non-standard gated-compiler build (99.1647) is deliberately **not** landed.
