# Processes & proofs — complete log (Mario Kart Wii `updateCollisions`)

Every **process** this project ran and every **proof** it reached, logged whole and then
compared / contrasted. Machine-readable copies live in `subagent_data/subagents.db`
(tables `processes`, `comparisons`, `proofs`) + `processes.jsonl` / `comparisons.jsonl`.

Legend for a process line: **name** — purpose · steps · tools · result.

---

## 1. The processes (39)

### Matching-loop (6)
- **P-MATCH-LOOP** `edit → ninja build → objdiff-cli → repeat` — the base loop; produced 86.993 → 93.437. *(supersedes nothing; the spine of the work.)*
- **P-SCRATCH** decomp.me scratch iteration — GET/POST `/api/scratch`; scratch `hbr0m` re-posted as the score rose.
- **P-PERMUTER** decomp-permuter (patched scorer→objdiff, direct compile) — C-only; cannot parse the C++ TU → dead end here.
- **P-REGPARTS** regparts/regenum — instrument the vregs, enumerate 276 edits; proved registers are locked to structure.
- **P-ENGINE-TEXT** text-level mutation engine — broad candidate generation.
- **P-ENGINE-TS** tree-sitter AST engine — structural mutations (temp-intro / reorder / type).

### Harvest (8)
- **P-OBJDIFF** objdiff JSON (+ `-x`) — the score oracle; `-x` proved the rodata symbol name was score-irrelevant.
- **P-SYMBOLS** readelf/nm — symbol names/sizes/order.
- **P-SECTIONS** readelf `-S`/`-x` — section sizes + raw bytes (target/our `.rodata` byte-identical).
- **P-RELOC** readelf `-r` + reloc-symbol compare — identical references; located `r29=pool`, `r30=pe`.
- **P-CAPSTONE** instruction/register diff — residual is register-only + one CSE-locked block (later *corrected* by D3).
- **P-NOTE-SPLIT** `.note.split` — original TU order/data addresses match ours.
- **P-MAP** Metrowerks `.MAP` generation — produced the link map (mapdas input).
- **P-REGTUPLE** register-tuple extraction (objdump parse) — machine-comparable colour state per trial.

### Compiler-investigation (7)
- **P-CC-SWEEP** 28 MWCC builds — `0x4201_127` best; none reached 100%.
- **P-FLAG-SWEEP** ~70 flag combos — project flags optimal; colour invariant.
- **P-DBG-SETUP** mwcc-debugger setup + `Wii/0x4201_127` row derivation (CodeView blob; breakpoint fixes) — enabled everything vreg.
- **P-DBG-REGALLOC** regalloc graph dump — the vreg-index colouring rule + coalescing flags.
- **P-DBG-PCODE** PCode dump — found the coalescing `mr r385,r92`.
- **P-RENUMBER** renumbering analysis — turned the dump into R-VREG-BLOCKS.
- **P-DEGREE** degree/neighbour parsing — falsified the degree-priority model.

### External (6)
- **P-DTK** toolkit exploration (elf info/dwarf/sigs/disasm, dol diff/apply, map).
- **P-DOL-DIFF-REMAP** dol_diff + `tools/remap_elf_symbols.py` — made `ninja dol_diff` green.
- **P-SYNC-DOLDECOMP** file-level merge of doldecomp/mkw + contributions (took 5 files).
- **P-DECOMPME-API**, **P-GH-SEARCH**, **P-M2C** — publish, discover, decompile.

### Meta (4)
- **P-SWARM** multi-agent subagent swarm — ~35 agents; the proxyF win, then exhaustive confirmation.
- **P-DB** structured dataset construction (SQLite+8 tables+FTS).
- **P-TOOLS5** five tool paradigms (analytics / graph / retrieval / solver / ETL).
- **P-AUTOLOOP** automated hypothesise→test→log loop.

### Proof (4)
- **P-PROOF-NOPATH**, **P-PROOF-UNSAT**, **P-PROOF-UNSAT-EXT**, **P-PROOF-INVARIANCE** (see §2).

### Release (4)
- **P-KB** field notes / KB (PR #275); **P-PR13**; **P-PR14**; **P-PR275**.

---

## 2. The proofs (4)
1. **no-path** — state-graph BFS/Dijkstra: the target colour state `{r30,r28,r26,r29}` is
   unreachable from the current one; target node has 0 in-edges.
2. **colour UNSAT** — z3 model of R-COLOR-ORDER / R-VREG-BLOCKS / R-SPLIT: the
   source-realizable target colouring is unsatisfiable (`pe` can't out-rank the pool).
3. **extended / full UNSAT** — adding the structural constraints keeps it UNSAT and *closes*
   the "make the pool a local" escape; the structural closure needs a −3-instruction
   compensation no known lever provides.
4. **measurement-invariance** — 28 compilers × ~70 flags × 3000 decl perms × 58k permuter ×
   5 tool paradigms: **nothing beats 93.4368**.

---

## 3. Comparisons (23) and what they mean
Subsumes (6) · Supersedes (2) · Complements (13) · Contrasts-with (2). The load-bearing ones:

| A | B | relation | meaning |
|---|---|---|---|
| P-MATCH-LOOP | P-PERMUTER | subsumes | the manual loop is general; the permuter automates it (but C-only → unusable here) |
| P-DEGREE | P-DBG-REGALLOC | contrasts-with | **naive degree-priority is falsified by the actual vreg-index priority** |
| P-DBG-REGALLOC | P-RENUMBER | supersedes | data → rule (R-VREG-BLOCKS) |
| P-OBJDIFF | P-CAPSTONE | complements | score alone hides *which* registers differ; capstone names them |
| P-PROOF-NOPATH | P-PROOF-UNSAT | complements | empirical vs deductive proofs of the same unreachability (independent, agreeing) |
| P-PROOF-UNSAT | P-PROOF-UNSAT-EXT | supersedes | the extended model removes an escape the basic one left open |
| P-SWARM | P-AUTOLOOP | contrasts-with | broad interpretable human-in-the-loop agents **vs** narrow reproducible automation |
| P-DB | P-TOOLS5 | complements | substrate vs consumers |
| P-PR14 | P-PR275 | complements | the function (doldecomp) vs the reusable technique (KB) |

---

## 4. Contrast analysis — which processes worked, which failed, and *why*

**Clusters that succeeded.**
- *Source-shape search* (P-MATCH-LOOP, P-ENGINE-TEXT/TS, P-SWARM, P-AUTOLOOP): the **only**
  cluster that moved the score (86.993 → 93.437), and it needed breadth (thousands of
  candidates) — the win was found by a permuter runner, then *explained* by the debugger.
- *Compiler-internals* (P-DBG-*) and *harvest* (P-OBJDIFF/RELOC/CAPSTONE): did not change the
  score, but converted guesswork into **rules** (vreg-index colouring, R-SPLIT) and **proofs**.
  This is the distinguishing property of the whole effort: tools that don't move the needle
  still produced the decisive understanding.

**Clusters that failed, and the failure mode.**
- *Automated source search alone* (P-PERMUTER, P-REGPARTS, P-ENGINE-TS, P-AUTOLOOP): all
  plateau at **93.4368**. Failure mode: the compiler's colouring is a deterministic function of
  the *frontend vreg numbering*, which is not reachable by equivalent source edits.
- *Compiler/flag axes* (P-CC-SWEEP, P-FLAG-SWEEP): orthogonal to the problem; the optimum is
  already at the project settings.
- *Structural-only* fixes (gameMode/playerIdx block) and *colour-only* fixes are
  **decoupled** (E4): fixing the 838-instruction size does not move `pe` to r30 and vice-versa.

**The decisive contrast.**
- **Empirical search peaks at 93.4368** (P-SWARM/P-TOOLS5); **deductive proof shows the peak is
  the ceiling** (P-PROOF-UNSAT/-EXT). The two are *independent* — searched empirically and
  proven formally — and they **agree**: the residual is a frontend vreg-numbering artefact,
  not a missing lever.
- **P-SWARM vs P-AUTOLOOP** is the methodological contrast: a parallel, interpretable swarm
  found the win and the rules; a deterministic loop then reproduced them headlessly — the
  swarm is for discovery, the loop for regression.
- **Isolation (round E) vs shared harness (round D)**: identical methods, different
  infrastructure — round D poisoned its own measurements by sharing one source file; round E
  (private copies) produced clean, reproducible numbers. *Process infrastructure changed the
  validity of the results, not the methods.*

## 5. Through-line
Read end-to-end, the processes form a funnel: **harvest** (P-OBJDIFF/SYMBOLS/RELOC/CAPSTONE) →
**compiler internals** (P-DBG-*) → **rules** (R-COLOR-ORDER/VREG-BLOCKS/SPLIT) → **search**
(P-SWARM/TOOLS5/AUTOLOOP) → **proofs** (no-path/UNSAT). Each stage narrowed the residual until
only a frontend vreg artefact remained, which the proofs show cannot be produced by equivalent
source — the honest finish at **93.437%**.
