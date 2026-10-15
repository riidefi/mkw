# Field notes — `KartState::updateCollisions` register-wall subagent log

> **STATUS: 99.7613% landed (`sync-doldecomp`, role-swap sqrt block, 838 insns, 2 objdiff units).**
> For the current consolidated state, the measurement rule, the exhausted-vector list, the artifact
> index and the 10 open hypotheses, read **`CONSOLIDATED_PROOFS_updateCollisions.md` first**. This file
> is the chronological round log (A…W).

Repo: `C:\Users\nnnn\Documents\mkwii` (Mario Kart Wii matching decomp, PowerPC, MWCC `Wii/0x4201_127`).
Function: `KartState::updateCollisions` in `src/kart/KartState.cpp`.
Target: `build/RMCP01/StaticR/obj/kart/KartState.o` (`updateCollisions__Q24Kart9KartStateFv`).

## Result in one line
`KartState::updateCollisions` = **99.642%** (838/838 instructions, target size) with the stock
compiler `Wii/0x4201_127`, up from **86.993%**. Seven source *shapes* did it:
1. `pe` via a sub-address temp (`p3 = lbl+3; pe = p3-3;`) → **r30** (94.3914);
2. `s8`/`u8 playerIdx` → defeats the `(u8)`-cast CSE → 4× `clrlwi` + 838 insns (95.9427);
3. a typed virtual call → vtable temp **r12** (97.0167);
4. an inline `dotZY` boundary (97.7327);
5. swapped flags-block accessors → fixes the r5/r6 tie (98.4487);
6. `dotZY` named-locals body (98.6873);
7. **inline wall-dot**: hoisted zeroed copies `za=sp20; zb=ci.wallNrm` + a manual sp20-first dot (99.642).

Ladder: `86.9928 → 89.7375 → 93.4368 → 94.3914 → 95.9427 → 97.0167 → 97.7327 → 98.4487 → 98.6873 → **99.642**`.
The last **3 instructions** are ONE FPR colour tie (`temp_f5` f2 vs retail f5), proven
scheduler-locked (unreachable from source; the needed interference edge never forms). A gated
compiler patch verifies **100.0000** but is answer-encoding and is NOT landed.

Harness used by every agent (fast, safe — compiles in `%TEMP%`, does not edit the repo):
```
cd C:\Users\nnnn\AppData\Local\Temp\opencode\perm
python -c "import probe as P; P.run([('name', P.build([(old_text,new_text)]))])"
# P.PRE / P.BODY / P.POST ; 93.4368 == current base == no change
```
Oracle: `build\tools\objdiff-cli.exe diff -p . -u StaticR/kart/KartState -o out.json --format json`
(`match_percent` of `updateCollisions__…`). Compiler internals: `cadmic/mwcc-debugger`
(Windows port in `%TEMP%\opencode\mhtri`), dumps in `build/mwcc-debug/dumps/`.

## The winning edit (kept)
```cpp
// before:  s32 var_r28 = (flags0 >> 18) & 1;
s32 var_r28 = (flags0 & 0x40000) != 0;
...
(*pproxy)->kartStateReload()->field(0) &= 0xFFFBE39F;
KartObjectProxy* proxyF = proxy;          // NEW: second web for the tail
// every (*pproxy)-> AFTER the reload line becomes proxyF->
```
Effect: `proxy`'s long-lived web is split; MWCC can no longer coalesce the whole thing into
one node, and the new web wins the target's `r26`. `proxyF -> r26` now matches the target.

---

## Round 1 (5 agents) — attack the 3-cycle head-on

| # | Angle | What it did | Outcome |
|---|---|---|---|
| 1 | Source-form enumeration | ~120 distinct spellings of `proxy`/`pproxy` (const/volatile/cast/reference/alias/split-liveness) + 432 structural×type combos | **No gain.** Baseline `(proxy=r30,pe=r28,v28=r26)` is a fixed point; movers only regress (84.6 etc.) |
| 2 | Permuter at scale | ~28,000 candidate compile+objdiff via the engines | **WIN 93.4368** — `proxyF=proxy` split + `var_r28` mask form (see above) |
| 3 | mwcc-debugger PCode | Dumped PCode per pass; found the exact coalescing instruction | `&proxy` forces a stack home; `memory-reference-rewrite` promotes it via **`mr r385,r92`** → `r92`+`r385` coalesce (`fCoalescedInto`, deg 283). Removing it (drop `pproxy`) → 84.6062 |
| 4 | Idiom mining (in-repo) | Found `KartSusPhysics::setInitialState` (100%) uses **split per-region locals** (`physics`, `physics2`) | Applied a 2nd proxy local → **89.7375** |
| 5 | Degree/neighbour model | Parsed the interference graph (degrees, priority order) | Priority is **not** degree-driven; observed order ≈ descending vreg id. Degree edits don't move saved regs |

## Round 2 (5 agents) — push the residual (`pe` r28↔r30, `var_r28` r30↔r28)

| # | Angle | Key result |
|---|---|---|
| A | Split `pe`'s lifetime | **Fails**: `pe` is not address-taken, so every `peF=pe` copy coalesces away (byte-identical). pe never left r28 |
| B | Fix `var_r28` | No gain; clarified the earlier "var_r28→r0" was a **dead duplicate node** — the live value is an anonymous temp at r30 |
| C | Permuter ~51k | **No gain**; 3000 valid declaration permutations never put `pe` in r30 |
| D | Debugger on the 93.44 build | **KEY**: colourer walks saved group by **DESCENDING vreg id**: `v143→r31, v94(v28)→r30, v88(pool)→r29, v69(pe)→r28`. To give `pe` r30, its vreg must exceed 94 |
| E | Idiom mining | Only r28/r30 swapped; `pe`(v69) and `var_r28`(v94) live ranges overlap almost fully; no idiom flips them |

## Meta round (5 agents) — reconcile the conflicting data

| # | Angle | Key result |
|---|---|---|
| 1 | Derive the vreg-index rule | Locals form **one contiguous block numbered in reverse declaration order** (first-declared = highest id; `pe`=v69 because it is first-declared). Compiler temps sit **above** the block. `pe = temp_floor − 1`, and **`pool − pe ≈ 19` is invariant** to adding/removing locals |
| 2 | Coalescing: proxy vs pe | The active ingredient is **overlapping live range**, not address-taking per se: `proxy` is used before *and* after the `proxyF` line, so copy-prop can't merge them; `pe`/`var_r28`/`flags0` are **rematerializable** (constant address / tiny expr) so copies fold |
| 3 | Classify split successes | Split recolours **iff** (a) non-rematerializable AND (b) copy live-range not a subset of the original. Address-taken is the reliable barrier (works for `proxy`, fails for `pe`) |
| 4 | Cross-compare dumps | Normalized `(edit → vreg-table)` for baseline vs 93.44; derived the renumbering rule (local block shifts ±1; temps above). Predicted edits all ≤ base |
| 5 | No-op vs register-mover mining | Tabulated 7 register-combos over ~475 mover rows; the only mover that lifts `pe` is the `var_r28` shift form → reaches **pe=r29, not r30** |

## Round 3 (5 agents) — new ideas from the vreg insight

| # | Angle | Key result |
|---|---|---|
| A | Make `pe` a backend temp | **Fails**: MWCC rematerializes global addresses — 15 inline uses produced **15 separate `lis`**; `pe` lands in caller-saved r4 (64.7%). Every declaration form canonicalizes to local v69 |
| B | Close the 4-instruction gap | **Fails**: CSE merges all `(u8)playerIdx` forms into one `clrlwi`; the only form giving 4×`clrlwi` is a `u8` local, which overshoots to 841 instrs and wrecks the allocation (91.8%) |
| C | Mine external decomps | SFA/melee/tww/mkdd/kar all use the **same** plain pointer-to-global idiom we already have; none beat 93.4368 |
| D | Alternative `pe` structures | reference/array-ref/struct/union/inline-getter/`#define` — all canonicalize to local v69 or regress (64–93%) |
| E | Reduce float-temp pool index | **Disproven**: the 18 temps above `pe` are **integer** temps (field loads / call temps); float temps live in the separate FPR space, so the pool's GPR vreg stays v88 in every dump |

---

## The two rules that fell out (reusable)
1. **Colour order = descending vreg id.** MWCC's Chaitin pass hands saved registers
   `r31, r30, r29, …` to webs in **descending vreg-index** order — *not* by degree.
   Declared locals occupy one block numbered **in reverse declaration order**; compiler
   temps are numbered **above** the whole block. Consequence: a first-declared local (like
   `pe`, v69) can **never** out-rank a compiler temp (the rodata pool, v88) by reordering.
2. **A lifetime split only recolours if the value is non-rematerializable and the copy's live
   range is not a subset of the original.** Address-taken values (like `proxy` via `&proxy`)
   are the reliable way to create a genuinely independent web; rematerializable values
   (constant addresses, small pure expressions) fold every copy back.

## Honest conclusion / gotchas
- The residual is a **frontend vreg-numbering artefact**: the original's `pe` was a
  long-lived backend temp created **after** the pool (vreg > 94); ours is a declared local
  pinned at v69. No source reordering/type/cast/structure reaches that.
- Forcing the target colours via `&pe` **does** give `pe=r30` — but collapses the surrounding
  codegen to ~63%. It is the only mechanism, and it is destructive.
- A separate, real **4-instruction size gap** (ours 834 vs target 838; `gameMode`/`playerIdx`
  block + `sp20` slots) is CSE-locked in this MWCC build.
- Practical guidance for the next agent: **run the debugger before permuting.** The
  `mwcc-debugger` regalloc dump (vreg ids, degrees, coalescing flags) turns "guess the
  source shape" into "read the exact colouring"; the winning `proxyF` split was found in
  ~28k permuter candidates, but the *reason* only became clear from the debugger.

## Artifacts
- Winning source: `src/kart/KartState.cpp` (93.4368%); snapshot `%TEMP%\opencode\perm\best_proxy2.cpp`.
- Regalloc dumps: `build\mwcc-debug\dumps\regalloc-gpr-pass-1-{assigned,all}.txt`,
  `backend-*.txt`; baseline backup `%TEMP%\opencode\dumps_backup_93_44`.
- Debugger: `%TEMP%\opencode\mhtri\tools\mwcc-debugger\` (derived `Wii/0x4201_127` row in
  `versions.py`), driver `run_debugger.py`.
- Harness/engines: `%TEMP%\opencode\perm\` (`probe.py`, `h.py`, `hill.py`, `tsperm.py`, …).
- Upstream PRs: doldecomp/mkw **#13** (dol_diff symbol remap tool) and **#14** (this function).

---

## Tooling built over the dataset (`subagent_data/`)
A structured dataset (SQLite + FTS + JSONL) was built from these runs; see
`subagent_data/README.md`. Five agents each built a *different kind of tool* over it:

| tool | paradigm | headline |
|---|---|---|
| `tools/analyze_db.py` | analytics | only `lifetime-split` ever beats; token→move correlation; `sum_vreg→score` r=0.77 (confirms descending-vreg colouring) |
| `tools/regstate_graph.py` | graph | **no path** from current to target colour state (BFS+Dijkstra) |
| `tools/kb_retrieval.py` | retrieval | FTS+TF-IDF search/synthesis; 7 uncrossed mechanism×node gaps |
| `tools/colour_solver.py` | solver (z3) | **UNSAT** proof that the target colouring is unreachable from source |
| `tools/run_and_log.py` | ETL | runs candidates, extracts the colour tuple, writes rows back to the DB |

## Formal results (`proofs` table)
- **no-path** — `regstate_graph.py`: no recorded/newly-tested edit moves
  `{pe=r28,var_r28=r30,proxy=r26,pool=r29}` → `{pe=r30,var_r28=r28,…}`; the target node has
  0 measured in-edges and no node is distance 1.
- **infeasibility (UNSAT)** — `colour_solver.py`: `pe=r30` requires `v(pe)>v(pool)`; a local
  has `v ≤ local_top < v(pool)` (R-VREG-BLOCKS), and a split copy folds because `pe` is a
  rematerializable constant address (R-SPLIT) ⇒ the source-realizable target colouring is
  **unsatisfiable** on this frontend.
- **measurement-invariance** — 28 compilers, ~70 flag combos, 3000 declaration permutations,
  58k+ permuter candidates, and every structure/loop/TU-context edit: all ≤ 93.4368.

## Harvest-method inventory
`subagent_data` also records **every unique data-harvesting method used in the project**
(40 rows, table `harvest_methods`, categories: measure, disasm, symbols, reloc, data,
compiler, permuter, external, vreg-internals, edit-generation, meta) — from `objdiff` JSON
and `readelf` symbol/reloc dumps, through `capstone` register diffs and the MWCC debugger's
regalloc graph, to the compiler/flag sweeps, the permuter engines, dtk, decomp.me, GitHub
search, and the DB-driven analytics/graph/solver/retrieval/ETL tools.

## Dataset-driven round (5 agents, tools on the expanded DB)
Run *using* the expanded database (harvest_methods / tools_built / proofs) rather than
probing blindly:

| agent | tool/angle | outcome |
|---|---|---|
| D1 | harvest-method **gap coverage** (`tools/harvest_coverage.py`) | mapped each method's real grain; found gaps (renumbering forward-only; reloc only function-grain; pool/TU-order unused). Per-EXPRESSION reloc compare proved `pe[18]`/`pe+17`/`pe[3]` symbol refs identical. No gain |
| D2 | **proof-boundary attack** | each UNSAT assumption is individually necessary (relaxing origin/remat/pool flips UNSAT→SAT) but the model over-approximates; the real requirement is a genuinely independent split web (address-taking, destructive). No gain |
| D3 | **cross-method corroboration mining** | found CORRECTIONS (see below) + independently re-verified the single-method findings. No gain |
| D4 | **method transplant** (capstone aligned per-instruction; .note.split; objsymbol) | located the EXACT first divergence (idx 329 `clrlwi`→`mr r0,r3`; `gameMode`); inferred the original's `pe` was a frontend temp above the pool. No gain |
| D5 | **autoloop** (`tools/autoloop.py`) | chained retrieval→run_and_log→graph→solver for 4×20 candidates; added 69 trials + 326 regalloc rows; independently reproduced UNSAT. No gain |

### Corrections this round (now in the DB `findings` table)
- **The residual is NOT register-only.** A mnemonic-aligned diff (834 vs 838 insns) shows
  ~14 structural slots: 3 extra `clrlwi`, `addic.`↔`cmpwi` for `gameMode`, a spill/stack-slot
  reorder, an `fadds` reorder — on top of the `pe`/`var_r28` swap. (`harvest_methods[10]`'s
  "register-only" and proof-3's framing were wrong; proof 3 already noted the 4-insn gap.)
- **R-COLOR-ORDER is scoped**: descending-vreg→descending-reg holds only for the *overlapping
  live-across* group; non-overlapping webs reuse the highest free register (`v85→r31` while
  `v94→r30`).
- **R3-E/F12 overstated**: the pool vreg is 89 at base86 and 88 at base93 (per-build, not a
  cross-build invariant).
- **D2**: the UNSAT model over-approximates — a non-rematerializable `pe` *plus* a split still
  lands `pe=r28` (92.96), so the true requirement is a genuinely independent split (destructive).
- **D5/AUTOLOOP** independently returned the same `UNSAT` / no-path result on the grown DB.

### Data-integrity gotcha (for future swarms)
The fast harness reads `src/kart/KartState.cpp` at import and writes candidates to a shared
dir; with concurrent agents it clobbers results (the same text scored 93.44/90.45/70.52/61.98
across processes). Always pin a frozen snapshot + a per-process TMP dir when parallelising.

## Combination round (5 agents, isolated workspaces)
Round E each agent made a **private copy** of the source + harness first (`$W\KartState_base.cpp`,
SHA256 `13FBD570…1A21A7`), so the 5 running in parallel no longer fought over shared files
(round D poisoned several results that way). Focus: **combine** the accumulated findings.

| agent | combination focus | result |
|---|---|---|
| E1 | R-SPLIT + the ~14 structural-slot fixes; 23,433 combos of 2–6 edits | nothing beat 93.4368; nothing reached 838 insns or `pe=r30` |
| E2 | coordinated whole-function vreg rewrite | **cancelled** (too long) |
| E3 | extended the z3 model to include the structural slots | **FULL model (colour+structure) UNSAT**; the structural coupling pins `pe=v69<pool=v88`, closing the "pool-as-local" escape; the structural closure needs a −3-instruction compensation no known lever provides (the only 4×`clrlwi` lever costs +7) |
| E4 | re-ran autoloop with corrected findings + structural candidate pool (125 candidates) | no gain; **7 candidates reached 838 insns but the size fix is DECOUPLED from the colour swap** (still `pe=r28`) |
| E5 | combined sibling/TU-context evidence | the sibling `PlayerSub1c_updateFromInput` holds the data pointer **below** the pool (`r28`/`r31`) — i.e. it corroborates OUR base, not the target; the target is the *inverted* case; TU-order is not a lever |

### Decisive combination result
The last unknown is now pinned: **the 838-instruction size gap and the `pe`/`var_r28` colour
swap are independent.** Even with the correct 838-instruction structure the colouring stays
`pe=r28`, because `pe` remains a declared local (v69 < pool v88). E3 turns this into an
extended UNSAT proof (colours + structure jointly unsatisfiable by one source shape); E5 shows
the apparent "missing sibling idiom" is a red herring (the sibling matches our base).

Round-E outcome logged in `subagent_data` (`agents`/`trials`/`findings`/`proofs`):
agents now 32, trials 123, findings 32, proofs 4.

## Proof/process/Nintendo/compilation round (5 agents, trusted workspaces)
Five agents were each handed a **pre-built, pre-verified workspace** (`%TEMP%\opencode\perm\subN`,
snapshot SHA `13FBD570…`, harness repointed, private `db.sqlite`, baseline already measured) so
they did not fight over shared files.

| agent | focus | result |
|---|---|---|
| F1 | **all proofs** → premises → new hypotheses | all 4 proofs survive; refinements: proof-1 is a *sampled induction* (not exhaustive), and the address-take route lands `pe=r20` (**not r30** — corrects `findings[9]`) |
| F2 | **processes/comparisons** → contrasts | under-used variants applied; enriched no-path reproduced; **instruction-grain reloc compare ruled out the "different symbol" escape** |
| F3 | **Nintendo decomps** | **new external corroboration** — `zcanann/SFA-Decomp docs/allocation_model.md` independently finds cross-tier saved-band order above width 4 *anti-predictive* and its model **declines the reloc-bearing address-materialization class** (exactly our `pe`); melee `allocator-rules.md` and tww `regalloc.md` agree |
| F4 | **how MK Wii was compiled** | **CodeWarrior for Wii `0x4201_127`** (Freescale MWCC 4.2 build 142), confirmed by the game's own libs embedding `(0x4201_127)` (RFL/NW4R strings); links RVL_SDK/NW4R/EGG/MSL/DWC. Nintendo-specific only in the patched-SDK distribution, not the compiler core |
| F5 | **synthesis** (external × local) | the target's `data-ptr@r30 > pool@r29` shape appears in **5 other Nintendo target functions, all 0%** (no known source) |

### v14 vs v15 `.comment` (resolved)
The target object's `.comment` reports **Version 14**; our MWCC emits **Version 15** (both
`Compiler version 4.0.0.1`). This is **metadata, not a compiler mismatch**: the original REL
carries no `.comment` string (stripped), and the decomp config sets `mw_comment_version: 14`,
which dtk *writes into the split objects*. It does not fingerprint the compiler and does not
affect codegen or matching. The genuine compiler identity is the embedded `(0x4201_127)` in the
game's own libraries.

Net: the round **strengthened** the result (a third, independent, external corroboration) and
resolved the toolchain; nothing beat **93.4368**.

## Parallel redo of 10 processes (10 agents, private trusted workspaces)
The user asked to **re-run the 10 core processes simultaneously** now that the harness is fast.
`make_ws.py` built **sub1..sub10** (each pre-verified at 93.4368), and 10 agents ran one process
each, logging only to their own workspace/DB. **7 completed, 3 cancelled as too slow.** All
reproduced the ceiling.

| # | process redone | scale | result |
|---|---|---|---|
| G1 | compiler sweep | 28 builds | `0x4201_127` best; **no build emits `pe=r30`** |
| G2 | flag sweep | 80 combos | none beat it; **no flag gives `pe=r30`** (`var_r28` alone owns r30) |
| G3 | text permuter | — | **cancelled** (subsumed by G4/G6) |
| G4 | tree-sitter AST permuter | ~12,100 cands | best = identity edit; `pe` web split **coalesces** |
| G5 | hill-climb permuter | — | **cancelled** |
| G6 | lifetime-split enumeration | 2,829 combos | every split **folds or ties**; zero recolour |
| G7 | source-form enumeration | — | **cancelled** (subsumed by G8/G9) |
| G8 | **capstone aligned register-diff** | full function | **exact map**: first divergence idx10 (`lis r30` vs `lis r28`); 23 structural slots (`playerIdx` `mr r0,r3`+4×`clrlwi` vs one hoisted `clrlwi`; `cmpwi r5,3` vs `addic. r0,r5,-3`; `zeroY` fp spill schedule) + 38 register-only sites (`pe r30↔r28`, `var_r28 r28↔r30`, `r12↔r5`) |
| G9 | **reloc/symbol comparison** | instruction grain | **63/63 relocs identical** (type/symbol/addend; only a constant `+0x10` shift from the 4 extra insns); `.rodata`/`.data` byte-identical → the "different symbol/data" escape is **dead** |
| G10 | tool-chain autoloop | ~969 cands | private DB grew 123→733 trials (~6×); `refine_db` still `{target_reachable:false, solver:'unsat'}` |

### What the redo actually added
- **G8/G9 are new hard artefacts**: the residual is now *fully enumerated* — a 23-slot structural
  map plus a 38-site register map, and a proof that every relocation matches. No remaining
  "unknown/might-differ" pocket.
- **G1/G2 re-confirm** the compiler/flag axis is dead, in parallel and at higher density
  (28 builds, 80 combos).
- **G6 kills the last source-shaped lever**: exhaustive splits never recolour.

Logged into `subagent_data/subagents.db` (`agents` G1–G10, `trials` ×7, `findings` ×4) and the
`measurement-invariance` proof was widened to include 2,829 splits + the parallel redo. Nothing
beat **93.4368**; the wall is unchanged.

## External-repo survey (round H, 6 agents)
Six user-supplied MKW-related repos, one agent each (clone → deep-read → DB rows → hypothesis).
**None contains a reference `updateCollisions` source** — the blocker stays compiler-internal.

| repo | what it is | result |
|---|---|---|
| `aplumafreak500/DisMKW` | pret-style **asm** disassembly of NTSC-U (RMCE01) | StaticR `.text` is one `.incbin`; no KartState/updateCollisions; devkitPPC/as, not MWCC |
| `SeekyCt/mkw-structures` | pseudo-C++ docs of the **old** `Player*` hierarchy | no `Kart*` symbols, **but** proves `PlayerSub1c == our KartState` (`__ct` `0x805943b4`, `PlayerSub1c::updateCollisions` `0x80594bd4`) and finds **zero** field type/width/offset differences in every collision struct |
| `riidefi/mkwutil` | 404 — it was the in-repo buildsystem, removed (`a0645548`), superseded by dtk | only unique tool = TU detection; no regalloc content |
| `snailspeed3/mkw` | the **canonical** MKW decomp (`riidefi`'s account renamed, `fork:false`) | behind our tree; `updateCollisions` still unimplemented (our PR #309) |
| `mkw-sp/mkw-sp` | runtime source-port (binary patches) | no source; hooks `KartState_calcCollisions+0x7a8` |
| `GnomedDev/mkw-spc` | runtime source-port (binary patches) | no source; same `+0x7a8` hook |

### New hard facts
- **External symbol confirmation**: `KartState_calcCollisions = 0x80594bd4` (both `mkw-sp{s,s,c}` `symbols.txt`) = our `updateCollisions` (`__ct` `0x805943b4` + `0x820`); cross-checked on `KartCollide_checkItem`.
- **Target bytes re-confirmed**: both patches preserve the retail instruction at `+0x7a8` = `lfs f0, 0x24(r31)` → `stfs f0, 0xa8(r20)` (`_a8.x = *(r31+0x24)`, `r20=this`) — byte-identical to our `build/RMCP01/StaticR/asm/kart/KartState.s` at `0x8509C`. Our target asm is right there.
- `KartState` (0xc0) layout cross-validated by three independent projects.
- Header nits (not `updateCollisions`): `KartMove.hpp` `+0x10` is `float speedMultiplier` upstream (we keep padding); 3 `KartState.hpp` enum labels disagree.

### Best hypothesis (H6)
In the target prologue `pe` and the rodata pool are **sibling** `lis+addi` callee-saved temps (`r30`/`r29`) — i.e. retail `pe` was a *frontend address temp created alongside the pool*, **not** a first-declared local (`v69`). The untested lever is a source form that makes MWCC emit `pe` as a body-level loop-invariant address temp instead of hoisting `f32* pe = lbl_1_data_3918;` at the top. NB the naive version (inline the global at each use) was already tested (R3-A → 64.68, rematerialised). H5's "we never read `+0x24`" is a misread — that is `ci.wallNrm.x`.

Rows: `agents` H1–H6, `findings` ×36 merged into `subagent_data`. Nothing beat **93.4368**.

## External-repo survey, part 2 (round I, 2 agents)
| repo | what it is | result |
|---|---|---|
| `SwareJonge/MKW-Dolphin-Speedometer` | C# overlay that `ReadProcessMemory`s Dolphin | no code/asm/MWCC content; only runtime RAM offsets (RMCP01 player-base `0x9C18F8`, input `0x42E324`, airtime `@+0x21A`) that match no decomp symbol |
| `vabold/Kinoko` | C++23 reimplementation of MKW physics, annotated with retail addresses | no usable C source, **but** `KartState::calcCollisions @addr{0x80594BD4}` = our function, and `Status.hh` confirms our flag *numbering* exactly while showing several enum *labels* are wrong |

### New facts
- Kinoko `Status.hh`: our clear masks are all correct (`0xFFFBE39F`={5,6,10,11,12,18}, `0xFFFF7FFF`={15}, `~0x880`={103,107}); labels to fix — bit3=`DriftManual` (we: `HOPPING`), bit12=`AllWheelsCollision`, bit15=`AirtimeOver20` (we: `ALL_WHEELS_COLLISION`), bit19=`Hop` (we: `AUTO_DRIFT`), bit28=`DriftAuto` (we: `IN_BULLET`), bit32=`InAction` (we: `HIT_ITEM_OR_OBJ`). Player-type band also off-by-one.
- Kinoko's own regalloc dump reaches the target shape via anonymous backend temps (`r98→r30`, `r145→r31` above the float pool `r88→r29`).

### Hypotheses tested, faithfully implemented (both refuted)
- **I1** — declare `pe` inside a nested scope opened *after* the `kartStateReload` line (so its vreg is issued after those temps): compiles, **92.8401**. Declaring it after `proxyF` instead: **86.40**.
- **I2** — one aggregate `struct Ctx{f32* pe; KartObjectProxy* proxy;} ctx = {lbl_1_data_3918, proxy}; Ctx* pctx = &ctx;` with every use via `pctx->`: compiles, **53.9813** — taking the aggregate's address destroys codegen, exactly as `R-SPLIT` predicts.

Net: both refuse; the wall stands at **93.4368**. Rows merged (`agents` I1–I2, `findings` ×13).

## External-repo survey, part 3 (round J, 2 agents; `mkw-spc` skipped = H6)
| repo | what it is | result |
|---|---|---|
| `VIPTankz/Wii-RL` | RL harness (ICML'25) driving RMCP01 inside Felk's Dolphin Python fork | no codegen/MWCC content; runtime RAM pointer chains; confirms the RMCP01 MD5 `e7b1ff1fabb0789482ce2cb0661d986e` |
| `kinnay/Nintendo-File-Formats` | mdBook of modern (3DS/WiiU/Switch) runtime formats | no DOL/REL/symbol/MWCC/object/content docs — zero build relevance |

### Hypotheses tested with faithful implementations (both refuted)
- **J1** — scoped alias of `pe` at its last use only (`f32* peS = lbl_1_data_3918; f32** ppeS = &peS; … fabsf(temp_f31 * (*ppeS)[3])`), so the rewrite temp exists but the stack home is confined: **92.7208**.
- **J2** — `#pragma opt_* off` around `updateCollisions`: `opt_common_subs off` **57.9572** (= the flag sweep's `-opt nocse`), `opt_propagation off` **83.8902**, `global_optimizer off` **49.1803**, `opt_lifetimes`/`opt_usedef_mem_limit off` **93.4368** (pragma accepted, no effect).

Net: both refuse; the wall stands at **93.4368**. Rows merged (`agents` J1–J2, `findings` ×12).

## External-repo survey, part 4 (round K, 1 agent)
| repo | what it is | result |
|---|---|---|
| `stblr/Hanachan` | stblr's Rust reimplementation of the MKW physics engine (abandoned; its README points to `riidefi/mkw` / `mkw-sp`) | no codegen/MWCC tooling; PAL runtime probes (`rkrd/*.s`) independently pin the Player/PlayerSub10/PlayerSub1c offset map and the collision masks (`0x20e80fff`, `0x2000`, `0x100`, `0x1f`) — confirms semantics, no lever |

The agent also re-derived the wall independently from the objects + `backend-30-after-peephole.txt`: it is a **two-class flip** — target wants `pe` in MWCC's *compiler-temp* class (vreg above the pool) and `var_r28` in the *local* class; ours is inverted (`pe`=local v69→r28, pool=temp v88→r29, boolean temp `v94`→r30). It then ran ~50 targeted edits (decl permutations, `&var_r28`/`volatile`/reference, `const`/`static`/anon-namespace, `?:`/comma/casts, inline at 3 sites, `do{}while(0)`, real-loop LCM triggers, array-size changes) — **all ≤ 93.4368**.

### Hypothesis tested (refuted)
- **H-K1** — pool the `pe` *address* via a `const` alias object: `extern "C" const f32* const lbl_1_data_3918_addr = lbl_1_data_3918; … pe = (f32*)lbl_1_data_3918_addr;` → **90.9308** (extra load). A `const f32* const` local is byte-identical (**93.4368**); making the array itself `const` moves the symbol (**91.1694** = K1's own 91.17); a `static` address alias is **92.9594**.

Net: H-K1 refuted; the class boundary (local `v69` vs temp `v88`) is **not source-reachable** — the only remaining avenue is patching MWCC's frontend vreg numbering via `mwcc-debugger`.

## Kinoko deep-dive (round L, 1 agent — structure-focused second pass)
Kinoko is a clean semantic **reimplementation** and it **omits the playerIdx/gameMode block entirely** (models the wall-collision-start action as `action()->start(UNK_1)`, `source/game/kart/KartState.cc:240-246`), so it supplies nothing for the two structural slots. Every collision-loop construct it does have matches ours, and where Kinoko *rewrites* (e.g. `trickable = trickable || …` always-eval) the **target asm agrees with ours**. Zero regalloc/vreg annotations.

### The residual, restated precisely
Target **838** vs ours **834**; of 71 differing sites ~40 are branch displacements. Four clusters with **one coupled cause**: our hoisted `clrlwi r4,r3,24` consumes r3→r4, cascading `rc`→r6, `gameMode`→r0, `battleType`→r4, vtable→r5; the target re-truncates per call → `rc`=r4, `gameMode`=r5, `battleType`=r4, raw `playerIdx`=r0, vtable=**r12**.

### Edits measured (E1–E5), all ≤ 93.4368
| edit | score |
|---|---|
| `gameMode == 3` (gives `cmpwi`, but gameMode→r0) | 93.0788 |
| drop `(u8)` cast at the 4 calls | 93.4368 (byte-identical) |
| per-branch `u8 p8` locals | 93.4368 (folded) |
| `u8 playerIdx` (only 4×`clrlwi` form) | 91.7955 (+4 insns) |
| decl reorder `rc; rm; playerIdx` | 91.6468 |
| `gameMode==9 \|\| ==10` | 85.9189 |

Net: Kinoko closes nothing; the `pe`/`var_r28` swap and the `clrlwi` hoist are frontend-canonicalised in `0x4201_127` — the only route left is the MWCC frontend vreg path (or an asm/runtime patch). Rows merged (`agents` L1, `findings` ×7).

## Compiler-patch route (round CC — x86 RE of `mwcceppc.exe`)
The user asked to patch the compiler's frontend so a **clean-C** build emits the retail colouring (no asm, no source hack). Two agents reverse-engineered the 4.17 MB x86 PE (it ships a CodeView symtab, `NB11` / 5708 names — so it is far from opaque), and I ran a controlled patch experiment on a **copy** of the compiler.

### What the compiler actually does
- **Vreg numbering** — one monotonic per-class counter `_used_virtual_registers[4]` (RVA `0x358358`, seeded to 32 = the 32 physical GPRs). Declared locals are minted in one early pass (`_CodeGen_Generator` → `0x6D8A0` → `_assign_register_by_type` `0x190CB0` → `_assign_register_to_variable` `0x1B17C0`) walking `_arguments` then `_locals`; the first-declared local gets the highest local number (`pe`=`v69`). Every temp is minted from the **same** counter after `_open_temp_registers` (`0x1B14B0`), so it is necessarily above (`pool`=`v88`). **No constant separates a local base from a temp base** — the split is pure pass ordering.
- **Colouring** — class 4 = GPR, saved regs 14..31. `_init_target_registers` (`0x191290`) builds the nonvolatile list descending (`r31..r14`) from the threshold table at RVA `0x2db87e`; `_obtain_nonvolatile_register` (`0x1b14f0`) hands them out in processing order via `_colorinstructions`'s retry block (`0x1b43bf..0x1b4446`). `_machine_specific_sort_graph` (`0x18e5d0`) sorts on `node+0x1a`, which is **never written** → the sort is a no-op (order = list order, descending vreg).

### Why no patch works
- Bumping a local's number is a **no-op** (the next temp mints above it from the same counter) or **OOB memory corruption** (a vreg indexes dense `used`-sized arrays in `_buildinterferencegraph` `0x2386F0` / `_set_vr_reg_flags` `0x6B660`). Deferring the local = the R3-A rematerialisation (64.68%).
- The colouring-order levers are **global** (class index / target option byte / function pointer) with no per-function gate short of a code-cave, and the global candidates don't reproduce retail anyway.
- Empirically, flipping the colour tie-break (`0x1b4634` `jne`→`je`) on a compiler copy had **no effect** (93.4368).

This independently reproduces the project's `P-PROOF-UNSAT` / measurement-invariance result from the compiler's own internals. **Both bypass routes are closed** (asm is not a recompilation — it is the original bytes; a patched compiler is not the standard toolchain), so `updateCollisions` remains a `NonMatching` WIP at **93.4368**, its current best — not a decision, just its state. Rows merged (`agents` CC-RE, `findings` ×3).

## Combining neutral edits (user hypothesis)
Could edits that are *individually* canonicalised away change codegen *jointly*? Tested exhaustively: all **63 subsets** of 6 distinct neutral primitives (`pe = &lbl_1_data_3918[0]`, dropping the `(u8)` casts, `#pragma opt_lifetimes off`, `#pragma opt_usedef_mem_limit off`, splitting `pe` at `pe[3]`, and `gameMode == 3`) were compiled. Every subset **without** the `gameMode` edit stayed at **93.4368** (byte-neutral); every subset **with** it sat at **93.0788**. No subset beat the base. This matches the 72 neutral/combination trials already in the DB. Reason: if `compile(E(S)) == compile(S)`, the frontend has already reduced `E(S)` to the same IR, so neutral edits are confluent and cannot compose into a change.

## BREAKTHROUGH — new source shapes (round SH: 93.4368 → 94.3914)
A fresh **structural** shape search (leaf edits were exhausted). Three shape classes ran in parallel: SH1 abstraction/inlining (~3,360 cands) and SH3 control-flow/loop/block (~13,400 cands) found **nothing**, but **SH2 (data-address class) broke the wall** and it is verified on the real source (committed `fe02982`).

**The winning shape:**
```cpp
  using namespace System;
  bool var_r28;
  bool var_r27;
  f32* const p3 = lbl_1_data_3918 + 3;   // NEW: sub-address temp
  f32* const pe = p3 - 3;                // was: f32* const pe = lbl_1_data_3918;
  ...
  u32 flags0 = (*pproxy)->kartState()->field(0);
  var_r28 = (flags0 & 0x40000) != 0;      // assigned after its declaration
  var_r27 = (flags0 & 0x60) != 0;
```
**Why it works:** deriving the address through `p3` keeps **one** live web (nothing rematerialises) while making `pe` a *compiler-generated temp* rather than a declared local, so it is numbered **above** the rodata pool and out-ranks it for **r30**. Declaring `var_r28`/`var_r27` first makes them the first-declared locals (v69/v68 → **r28**/**r27**). On the real source: objdiff **94.3914** (was 93.4368), prologue `lis r30`=pe / `lis r29`=pool / `rlwinm r28`=var_r28 — **exactly the retail colouring**.

**This falsifies the project's `no-path` / `UNSAT` / `measurement-invariance` proofs** — every one assumed `pe` stayed a declared local (`R-VREG-BLOCKS`); the sub-address escape makes `pe` a temp. The remaining residual (~5.6%) is now purely the structural slots (the `gameMode`/`playerIdx` `clrlwi` hoist, the `sp20` schedule, branch displacements). This is the one axis worth attacking next.

## Residual-structure search, seeded from 94.3914 (round SR)
Three parallel searches. SR2 (float/zeroY/spill, ~2.2k) and SR3 (generalise the sub-address trick + combos, ~18.5k) found nothing — both confirmed hard plateaus. **SR1 (the `playerIdx`/`gameMode` block, ~3.6k) found a second win: 94.3914 → 95.9427** (committed `5127521`).

**The winning edit:**
```diff
           fn_1_809A8(proxy, 1);
-          s32 playerIdx = proxyF->getPlayerIdx();
+          s8 playerIdx = proxyF->getPlayerIdx();
+          RaceManager* rm = RaceManager::spInstance;
           RaceConfig* rc = RaceConfig::spInstance;
-          RaceManager* rm = RaceManager::spInstance;
           s32 gameMode = rc->mRaceScenario.mSettings.mGameMode;
-          if (gameMode - 3 == 0) {
+          if (gameMode == 3) {
```
**Why `s8` works where every `s32` spelling failed:** a signed-char local forces MWCC to keep a sign-extension at each conversion, so the `(u8)` truncation can no longer be hoisted/CSE'd into a single `clrlwi` — reproducing retail's **4× `clrlwi r4,r0,24`** with the raw `playerIdx` in `r0`, `cmpwi r5,3`, and `rc`→r4. Instruction count is now **838 = target**, colouring still `pe=r30`/`pool=r29`/`var_r28=r28`. (It costs `extsb r0,r3` where retail has `mr r0,r3`.)

**Residual (~4%) is now two diffs:** that `extsb`-vs-`mr`, and the vtable temp (`lwz r5,0(r3); lwz r12,0x38(r5)` vs retail `lwz r12,0(r3); lwz r12,0x38(r12)`).

## Final-push search, seeded from 95.9427 (round T)
Two searches (sub9, sub10) independently reached **97.0167** (`5127521`→`6bf31d5`). The two residual diffs were one cause:
- The manual vtable indexing `(*(void***)rm->raceMode)[0x38 / 4]` lowers to a plain array load using `r5`; retail's `lwz r12,0(r3); lwz r12,off(r12)` is MWCC's **standard virtual-call sequence**. Rewriting both arms as **real virtual calls** (a typed class with `f12`=0x38, `f11`=0x34) makes the vtable temp `r12`.
- `u8 playerIdx` (was `s8`) removes the leftover `extsb` while keeping the **4× `clrlwi`**.

Verified on the real source: objdiff **97.0167**, 838 instructions. (sub10 reached the same score via an `extern "C"` mangled redecl to change the return type + a fake vtable class.)

**Remaining ~3%:** the `r5`/`r6` swaps in the `flags0`/`var_r28`/`var_r27` block (indices 17-26), the `sp20 = ci.movement; sp20.normalise()` + `RKSystem_ey`/`sqrt` stack-slot schedule (454-504), and FPR naming (`f5`↔`f2`). These resisted the type/decl/`pragma`/`register`/`static`/`volatile`/`zeroY`/`sp20` fuzzing in both searches.

Progression: **93.4368 → 94.3914 → 95.9427 → 97.0167**.

## Final-push search, seeded from 97.0167 (round U)
Three searches. U1 (prologue flags block, ~12.4k) and U3 (generalise the winners, ~9.8k) found nothing. **U2 found a fourth win: 97.0167 → 97.7327** (`e09fa9e`).

**The winning edit:**
```cpp
static inline f32 dotZY(const EGG::Vector3f& a, const EGG::Vector3f& b) {
  return EGG::Vector3f::dot(zeroY(a), zeroY(b));
}
...
- ((EGG::Vector3f::dot(zeroY(ci.wallNrm), zeroY(sp20)) < 0.0f) ||
+ ((dotZY(ci.wallNrm, sp20) < 0.0f) ||
```
**Why it works:** the inline boundary changes MWCC's temp allocation so the two by-value `zeroY` results lay out in retail order (`wallNrm`→0x8, `sp20`→0x14) instead of swapped — 6 instructions fixed.

**Remaining ~2.3%:** the prologue flags-block `r5`/`r6` colour tie (allocation-robust: survived ~12.4k + 9.8k candidates), the dot-block store/load schedule, and FPR `f5`↔`f2` naming. Progression: **93.4368 → 94.3914 → 95.9427 → 97.0167 → 97.7327**.

## Plateau at 97.7327 (rounds V/W)
Five further parallel searches — V1/V2/V3 (~22k) and W1/W2 (~4.5k) — found **nothing**. The last **19 mismatched instructions** are allocator/scheduler-locked:
- **6 × prologue flags-block `r5`/`r6` colour tie** (reload-ptr temp vs `flags0 & 0x60` mask temp) — invariant under inline helpers, named `KartState*` temps, `u32*/u32&` sub-address temps, width flips, statement order, constant algebra;
- **13 × dot-block store/load schedule + FPR `f5`/`f2` naming** — every eager/`volatile`/helper form either reproduces the base or breaks more than it fixes.

W1 also **corrected a false lead**: the claim that wrapping `C1` as `EGG::Vector3f::dot(v, RKSystem_ey)` "fixes all 13" is an objdiff **index-alignment illusion** (the wrap inserts 4 instructions and shifts slot indices). Keyed by target *address*, it fixes **zero** and breaks 17 — the C1 expression already matches retail.

So **97.7327 is a hard local optimum** for source under MWCC `0x4201_127`; ~60k+ candidates across 7 rounds moved it from 93.4368 to 97.7327 and then stopped. The last 2.27% would need a compiler-allocator/scheduler change, not a source shape.

## Why the residual is source-side, not toolchain (round X — compiler route explored, abandoned)
The last diffs were attacked on the toolchain. **Register allocation runs *before* the scheduler** (`_colorinstructions` RVA 0x1b3fa0 is called at 0x6b17a; `_scheduleinstructions` RVA 0x1b6ad0 only at 0x6b325/0x6b3d4), the FPR `f5`/`f2` pick is an **interference-graph difference** (`temp_f5` got `f2` because `f2` was free there), and the FPR sort is **inert** (`[0x74f339]==0`). Sweeping all 11 scheduler pipeline models, the colour tie-break byte, and the FPR sort left the score at 97.7327 or worse. The only compiler lever that changed anything was a function-gated code cave swapping the two tied scratch webs — a **non-standard, source-build-specific hack the project does not use** (removed).

**Conclusion:** the residual follows from the **PCode / interference graph**, i.e. the **source** — so it must be closed by a source shape, not the compiler.

## Source-shape hunt for the last 19 (round Y)
Three searches (~34k candidates), all inline-boundary / temp-lifetime / interference-graph oriented (Y1 dot/sqrt ~2.1k, Y2 prologue ~10.6k, Y3 broad ~21.6k). **Nothing beat 97.7327.**
- The prologue `r5`/`r6` tie **is** an interference-graph artifact and **is** movable, but only by materialising the reload pointer (`KartState* volatile rl`), which forces a 2-instruction stack spill (840 insns) and drops to **91.3%**. No non-volatile shape flips it.
- Inline-helper boundaries move the **saved**-register band (`r28`/`r30`), not the volatile band.
- The dot/sqrt store-load schedule and FPR `f5`/`f2` naming are invariant under every expression grouping, declaration order, extra temp and helper boundary tried.

Net: ~100k+ candidates across rounds SH..Y moved `updateCollisions` **93.4368 -> 97.7327** (four source shapes) and nothing since. The last 19 instructions are a **hard local optimum** for source under MWCC `0x4201_127`.

## Five new attack classes (round Z) — all plateaued
| idea | result |
|---|---|
| **Z1** allocator steer via inline asm / barriers | MWCC emits the asm, so any register-mentioning barrier adds a mismatching instruction (`asm{mr r5,r5}` → 61.7); `#pragma gcc_extensions on` makes gcc-style clobber/operand constraints *compile but do nothing*; `register` / `asm("r5")` are ignored. **No steer possible.** |
| **Z2** `this`/self-form rewriting | ~525 variants; every `self`/`this` alias copy-propagates and coalesces to **v32** — `.text` byte-identical. |
| **Z3** accessor / field-access forms | ~200 variants (raw offsets, refs, widths, private-header `field()`): allocation-locked. |
| **Z4** whole-TU perturbation | ~300 variants; dummy code is neutral, but any new float literal shifts the shared pool (`lfs` offsets, worse) — the current layout is already optimal. |
| **Z5** compile-context change | ~560 variants (`-inline`/`-ipa`/`-O`/pragmas/separate TU/`noinline`): all identical or worse. **New datum:** the allocation depends on the preceding **emitted** function `updateWipe` (removing/moving it drops to 97.0167) — but the base arrangement is already the high state. |

None beat 97.7327. Together with rounds SH…Y (four wins from 93.4368, then a hard plateau), this closes every attack class tried: text/AST/hill-climb/exhaustive splits, compiler+flags, 8 external repos, compiler internals (allocation *and* scheduling), four shape mechanisms, and now asm barriers / self-aliasing / accessor IR / TU perturbation / compile context. **`updateCollisions` is a hard local optimum at 97.7327.**

## Five more classes (round AY) — all plateaued (~30k candidates)
| idea | result |
|---|---|
| **AY1** idiom mining from 100%-matched functions | residual is an allocator tie, not an idiom gap |
| **AY2** per-cluster reconstruction from the retail asm | exact causes identified — GPR `r5`/`r6` tie, FPR `f5`/`f2` tie, a 2-slot `zeroY`/dot schedule — but no source shape flips them |
| **AY3** live-range / pressure shaping (~880) | perturbations move the piece only by breaking matches |
| **AY4** macro / preprocessor shapes (~71) | macro-expanded forms collapse to the same token stream → byte-identical |
| **AY5** fine cross-product of ~58-362 near-miss edits (~28k, pairs→quads) | zero interactions; every combo ≤ 97.7327 |

**Cumulative:** ~150k+ candidates across rounds SH…AY moved `updateCollisions` **93.4368 → 97.7327** (four source shapes) and nothing since. The last 19 instructions are a hard allocator/scheduler outcome under `0x4201_127`.

## Allocator/Scheduler round (AS) — allocation solved, schedule not
The user asked for dedicated allocator/scheduler agents. Result: **a cleanly-gated compiler patch solves the register allocation** (verified **99.1647**); only a 7-instruction scheduler residual remains.
- **AS1** — force `v91→r6` so `v82→r5` (the GPR scratch tie) → 98.4487.
- **AS3** — force the `temp_f5` node `f36→f5` → 98.0907 (found why `f2`: only `{f0,f1,f3,f4}` forbidden ⇒ lowest free).
- **AS4** — the "graph must change" hypothesis is **falsified** (no missing edge; order reversal → 44.5); combined GPR+FPR remap → 98.8067.
- **AS5** — built a **clean gate**: `_copts[0x6D]` (VA `0x74F395`) set by `-pragma "report_heap_info on"`, function-scoped via `_gFunction`; re-tested all global candidates — none beats the remap.
- **FPR2** — force the last FPR web `v132→f3` (cascades to fix both remaining FPR names) → **99.1647** (hook RVA 0x1b4420 + 156-byte cave RVA 0x26c6fa; whole-TU clean; independently re-verified).
- **SCH** — time-boxed; the **7 remaining** (a load-store schedule rotation + an `fmuls` operand order) are **not** allocator/register-addressable. Alias-predicate levers are dead (forcing `_may_alias` true → 80.7, false → 78.8; forcing the `_nbytes` extra-dependency → unchanged); a fix would need a scheduler-side priority/tie-break cave at RVA `0x1b6ad0`, which was not found.

**Net:** `updateCollisions` = **97.7327** (stock compiler) / **99.1647** (cleanly-gated compiler, non-reproducible with the stock toolchain). The last 7 are a list-scheduling tie-break.

## Rounds S..CT — from 97.7327 to 98.6873, then the compiler ties
### S — scale searches (10 agents, fast harness)
Two wins. **S10** (a byte-distance hill-climb, found in ~540 evals) **swapped the flags-block accessors** — read `flags0` via `kartStateReload()->field(0)`, write the clear-mask via `kartState()->field(0)` — fixing the `r5`/`r6` prologue tie **from source** → 98.4487. **S1** (token sweep) found `(flags0 & 0x60) != 0` → `!= 1` → 98.0930 — **later judged a FAKEMATCH** (see below). The other 8 plateaued. Lesson: broad cheap token/byte search finds wins hand-picked shapes miss.

### D — re-run old searches at the new base (10 agents)
**D4** relaunched the old **SR2 float/`zeroY` search** (which had plateaued at 94.39) at the 98.4487 base and **won**: the `dotZY` body with **named locals** (`EGG::Vector3f zb = b, za = a; za.y = 0.0f; zb.y = 0.0f; return EGG::Vector3f::dot(za, zb);`) flips the temporary-copy order to retail → **98.6873**. Key lesson: the same search can fail at one base and win at another — re-run old searches after every new win.

### E/F — more searches, and the FAKEMATCH integrity rule
Rounds E/F (~100k candidates) found no legitimate win, but surfaced the rule that matters: a token/value sweep can score higher by **changing behaviour**. E1's "98.6889" changes `if (var_r5 == 0)` → `== 1` where `var_r5 = f8 & 0x102` (never 1 → the branch becomes never-taken); S1's "98.0930" changes `(flags0 & 0x60) != 0` → `!= 1` (differs at mask 0). **Both are semantic changes and were rejected.** From then on every agent ran an **equivalence gate**: an edit above the base must be semantically identical, not just higher-scoring. The two landed wins pass it (the accessor swap returns the same object; the named-locals dot is the same dot).

### G — property-reclaim hypotheses (10 agents)
Each reclaimed a "target property that a regressed shape had hit". All plateaued, with a decisive result: **the base already satisfies the reclaimed properties** — the `playerIdx`/`gameMode` block is **byte-identical to retail** (`cmpwi r5,3`, `rc=r4`, `gameMode=r5`, `battleType=r4`, raw `playerIdx=r0`, vtable=`r12`), and the GPR half of the compiler patch is already reproduced natively.

### CT — compiler ties only (10 agents, on compiler copies)
Pinned the last ~11 instructions to **two compiler-internal ties** and produced a whole-TU-clean gated fix:
- **FPR tie:** `temp_f5` (vreg 36) gets `f2` because only `{f0,f1,f3,f4}` are forbidden; retail is `f5`. A function-gated, **node-keyed** colour override at the `_colorinstructions` commit site (hook RVA `0x1b4420` + cave `0x26c6fa`) → **99.0453** (+0.358). No general `_pickcolor`/order/vreg-renumber change is safe (lowest-free, order-independent).
- **dotZY slot/schedule (8 insns):** the two by-value temp slots are assigned by `_assign_local_memory` (RVA `0x1a6430`, `object+0x48`) and a **model-4 list-scheduler** rotation (`_scheduleinstructions` RVA `0x1b6ad0`, table RVA `0x33dc11`, selector `0x1b6e60`). A slot swap alone **regresses** (98.4487) and no single scheduler entry reproduces the rotation.
- **Clean composable gate:** `_copts[0x6D]` (VA `0x74F395`) as a **bitmask** via `-pragma "report_heap_info <mask>"` + a function-name check; byte-identical to stock when unset.
- **No principled option exists:** ~430 option/pragma/flag configurations tested; the toolchain and flags are **proven the original** (12/16 functions + all 4 `.data` already 100%).

Progression: `93.4368 → 94.3914 → 95.9427 → 97.0167 → 97.7327 → 98.4487 → 98.6873` (stock) → `99.0453` (gated compiler patch, not landed).

## Rounds M/F — 99.642, then the verified 100%
### M — the one-decision wall breaks (98.6873 → 99.642)
The audit reduced the dotZY residual to ONE decision (the temp slot order). Three subagents independently found the fix; the landed form (`0c9acb6`) writes the wall-dot **inline**: after the `0.85f` check, hoist `EGG::Vector3f za = sp20; EGG::Vector3f zb = ci.wallNrm; za.y = 0.0f; zb.y = 0.0f;`, then an inner `if (((za.z * zb.z) + ((za.x * zb.x) + (za.y * zb.y)) < 0.0f) || (_68 >= 1.0f))`. Semantically identical, fixes all 6 slot/copy/role slots → **99.642** (838/838).

### F — the last 3 FPR instructions
~12k candidates prove `temp_f5` f2→f5 is **scheduler-locked**: the needed edge `temp_f5 ↔ temp_f4²` never forms (the pre-regalloc scheduler always stores `accum.x` before the `f4²` mul). Two gated compiler patches verify **100.0000** (whole-TU clean, gate OFF byte-identical): F5 (colour override `v36→f5`) and F6 (`makeinterfere(36,149)+(36,4)`). F7 showed the overlap alone flips to f4 — the tie lives in the production allocator's ordering.

### N — the last 3 are CLOSED by a principled gated patch (verified 100.0000)
N8's runtime probe pinned the decision: at `temp_f5`'s turn the allowed mask is `0x3FF4` (free `f2,f4..f13`) — **no scan direction reaches f5**; the retail build coloured the `f2`/`f4`/`f3` temps **before** `temp_f5` (a colouring-order difference). N1's exhaustive 575-run enumeration showed **14 of the 15 FPR edges already exist** — only `temp_f5 ↔ temp_f4²` (`(36,149)`) is missing. **N2 supplies exactly that**: `_makeinterfere(36,149)` + a simplify-stack relink (`37→35→36→34`), gated — the colours then fall out of the greedy allocator **naturally**, with **no hard-coded colour value**. Independently verified: gate ON = **100.0000** (0 mismatches); gate OFF = byte-identical to stock (**99.642**); whole-TU clean; second TU inert. Artifact: `artifacts/compiler-patch/N2_principled_patch.json`.

## Rounds LAT/Q — the latency mechanism, then the 535-form space sweep (2026-10-15)
### LAT — a source construct that flips temp_f5 to f5 DOES exist
`accum.x = temp_f5 + (temp_f4 - temp_f4);` makes the stock compiler colour the `temp_f5` load **f5**: the store's source becomes an `fadds` (latency 2), so the first scheduling pass emits the `temp_f4²` mul before the `accum.x` store → the missing `(36,149)` edge forms → f5. The wrinkle: the identity creates a second web (the `fadds` result), so the *store* uses `f3` — split web, net 98.8095. Decl-level identities (`temp_f5 = x - (z-z)`) regress to 98.2–98.6. This proved the register CAN move to f5 from source, via latency/dependency shaping rather than ordering alone.

### Q — exhaustive sweep: no inventory-preserving form reaches f5 (535 forms)
- **matrix (192)**: decl order × 6 store orders × 4 sqrt trees × named-ysq × named-t4sq → best = plain base 99.642, **0 f5**; registers seen: f0/f1/f2/f3/f31/split.
- **hoist (288)**: {none,t4,t5,t4t5,t4t5y,y} × decl × store × tree → *every* hoisted form scores below base (vreg numbering shifts colour but never to f5, and the final order degrades); top-20 all "none".
- **bool/len/sum (6)**: condition before the stores without FPR vregs → `bool under` costs 96.45 (bool materialization), `len2` 96.79, `sum2` 99.16 (split web). Never f5.
- **comma (40)**: `accum.x = temp_f5` embedded as a comma sub-expression in the sqrt condition (evaluation-order control, zero new FPR vregs) → web moves to f3/f4/split but never f5; best 99.16. Control form reproduced 99.642 exactly.
- **Inventory invariant**: every f5-producing form (latency identities) adds ≥1 instruction; with an 838-insn target that caps it at ≤98.81 < 99.642. Every zero-inventory-change form never reaches f5. **100% on stock requires edge (36,149) with zero inventory change — not found in 535 forms.**
- **Build-tree anatomy** (disproved a "stale object" worry): `build/RMCP01/StaticR/obj/kart/KartState.o` = retail TARGET (f5, fixed input); `build/RMCP01/src/kart/KartState.o` = our compile (f2, ninja-fresh); retail vs ours differ by exactly the 3 known insns (`KartState.s:1139-1148`).
- Harness note: detect the `temp_f5` web with `fmuls R,R,R` immediately followed by `stfs R,44(r1)` — earlier `stfs f?,44(r1)` (function-entry accum init) and the `_a8.x` `lfs ?,36(r31)` are decoys.

## Round R (f5batch8/9/10) — RA-graph anatomy of the f5 forms, scores, and the gap batch (2026-10-15)
### The colouring model, read off `regalloc-fpr-pass-1` dumps
Pass 1 colours vregs in descending order, smallest free colour, and a vreg may only see **already-coloured (higher-vreg) neighbours** at its turn. For `temp_f5 = f5` it needs five higher-vreg neighbours covering f0–f4, which needs both (i) the t4sq edge (x-store scheduled after the `temp_f4²` mul pre-RA — pre-RA and post-RA core order never differ in any dump) and (ii) `temp_f4`'s vreg **above** `temp_f5`'s. Reverse-decl numbering (last declared = lowest vreg) delivers (ii) when `temp_f4` is declared first; baseline declares `temp_f5` first so `temp_f4=f35 < temp_f5=f36` and `temp_f5` can only ever see `{const, t5sq, y2}` → f2. Decl-swap controls verified this (`gap_base_zx`: `temp_f4=f36→f4`, `temp_f5=f35→f2`, one edge away).
### The f5 forms that exist, and every one scores below baseline
Edge sources found: (a) y,x,z store order — the y-store jumps between `t5sq` and `t4sq` (family `s_a8y`/`s_ci_y`/`s_zby`/`a8y_named`/`s_then_stores_yxz`), (b) the `accum.y = ci.wallNrm.y` reload (`a8y_store_ciy`). Scores measured this round with `vwin2`: `a8y_store_ciy` = **98.4487** (838 insns, y-store late, best f5 form), `s_a8y` = 98.4487, `a8y_named` = 98.4487, `s_ci_y`/`s_zby`/`s_then_stores_yxz` = 98.3313 (839), `ciy_s_xzy` (retail instruction order + const y-store, shifted colour cascade) = 98.3313. All f5 forms cap at 98.45 < 99.642; every retail-order form fails the colour cascade (const lands f0 instead of f3 because a const created after the muls gets the highest vreg).
### Gap batch (f5batch10): the late-y2-load design fails on load placement
Design: baseline shape (const y-store, x,z,y IR order, y2 read from `ci.wallNrm.y`/`zb.y`/`_a8.y` inside the if-expr) so a fresh late lfs would sit between `t5sq` and `t4sq` and hand the mul>store tie to `t4sq` → edge with zero inventory change. Result: **no edge in any variant** (temp_f5 = f2/f4, scores not promising). The if-expr's lfs lands *between the two temp loads* instead (displacing `temp_f4`'s load after `t5sq`, so `t4sq` is never ready at the tie) — only a post-store statement load (`a8y_store_ciy`'s y-store) lands in the correct window, and that load necessarily replaces the const (see below). The one failure `gap_ciy_s` was a syntax error (rc=1), unimportant.
### The impossible triangle for 100% on stock
A block that is both colour-correct and inventory-correct needs (1) the const long-range neighbour (colours f3, requires y2 CSE'd from `accum.y = 0.0f` and the y-store on that same const), (2) a late *variable* lfs in the `t5sq`↔`t4sq` window (the only observed edge mechanism that keeps the y-store late), (3) exactly 17 block instructions. One y-store source cannot be both const and a fresh load, so at most two of three: baseline = (1)+(3) → 99.642 f2; `a8y_store_ciy` = (2)+(3) → 98.4487 f5; gap forms = (1)+(2) → 98.33 and still no edge. Combined with round Q's 535-form sweep this closes the source route: **no enumerated form does both f5 and retail order.** Consistent with N8 (mask `0x3FF4`, no scan reaches f5) and N2 (the edge is supplied by the gated patch, not by source).
### State at end of round
Working tree reverted to HEAD (`4ba044a`) and re-verified: **99.642, 838 insns, clean**. Batch scripts `build/mwcc-debug/f5batch9.py`, `f5batch10.py` kept for reproduction; the a8y/s-family `tu_*.cpp` + `dumps_*` artifacts remain on disk.

## Round S (f5batch11–16) — pushing f5 past 98.45, and the objdiff-units proof that 99.642 is the ceiling (2026-10-15)
### Harness fixes
- `expected an MZ image at 0x400000` in the dump runner = the compiler **exiting early on a syntax error** (gdb finds no image), not ASLR. Diagnose rc=1 candidates directly with `h.MWCC + h.FLAGS` — it found the batch11 bug: `STORES_XYZ` substituted mid-body without a trailing `;` (MWCC accepts `;;`; `wrap()` only appends `;` to the last line).
- objdiff scoring refined: `match% = 1 − diff_kind_count / total`. Dump the diff list with `objdiff-cli diff -1 TARGET -2 ours -o - --format json` → entries carrying `diff_kind` (`DIFF_ARG_MISMATCH` w/ `arg_diff.diff_index`, `DIFF_REPLACE`, `DIFF_INSERT`) are the only real units. Harness: `%TEMP%\opencode\perm\diffkind.py`.

### What was tested (all restored, HEAD verified after each batch)
- **posty/gap/prey (batch11)**: fresh reads at statement position (after the stores) → f3/f4 only, never f5. The y-load must sit in the post-`t5sq` scheduling window AND the x-store must cross `t4sq`.
- **combo_y0_ciy (+ inl)**: const y0 for y2 + late `accum.y = ci.wallNrm.y` store → **first f5 of the session**, 99.2849 (839). Instruction-identical to retail except one extra `lfs` + store shuffle.
- **aiy family (batch12)**: move `_a8.y = ci.wallNrm.y` out of the base so the `_a8.y` load can sit inside the region — only `aiy_top_xz` = f5, 98.3294 (838, order damage); requires custom base (line 449 removed) since `B.REGION` is a literal (`.find()`, not `re.search`).
- **h_* (batch13)**: store-order sweep **without** the fresh lfs → 0 f5 (f3/f4). The lfs is what flips the `t4sq`-vs-`z` scheduling tie (also flips the scheduler's choice); store order alone never crosses.
- **dupx_*/muly (batch14)**: a duplicated x-store late use is DSE'd; `temp_f5 * 0.0f` folds to a const. **Only a fresh variable load survives** — the allocator/scheduler kill every synthetic late use.
- **Store-order sweep on the combo core (batch15)**: all 6 permutations scored — xyz/yxz/yzx = 99.2849, xzy/zxy = 99.404, **co_zyx = 99.5232 (f5, 839) = best f5 form ever**; co_zyx_s/y0f/y0l all identical 99.5232; zby/zyx_ciy controls = f4.
- **zlf (batch16)**: move the edge load to `accum.z = ci.wallNrm.z` while keeping HEAD's const — the z-load **CSEs** with the still-live `temp_f4` value (no fresh lfs) → f4/f2. Live values forward; only a value that *died* earlier reloads — which is exactly why the edge only exists as `_a8.y`-died → y-store reload (co's mechanism).

### The objdiff-units proof: 99.642 is the source ceiling
- **HEAD = 99.642**: exactly 3 units, all the `f2`-vs-`f5` operands of `temp_f5` (`lfs f5,0x24(r31)`, `fmuls f1,f5,f5`, `stfs f5,0x2c(r1)`). Any single-colour deviation fixes nothing; only f5 fixes all 3.
- **co_zyx = 99.5232**: exactly 4 units — (1) const dest-reg (`lfs f3,0(r29)` retail vs our colour), (2) y2 operands (`fmuls f0,f3,f3`, cascade of 1), (3) `DIFF_REPLACE` of the x-store (ours sits after `fadds1`, retail's between `t5sq`/`t4sq`), (4) one `DIFF_INSERT` (the edge lfs).
- **Units 1+2 and f5 are mutually exclusive**: retail's const is `f3` only if it is a *long-range* neighbour. Make our const long (y2 from `accum.y = 0.0f`, y-store on that const) and the edge lfs takes f4 → `temp_f4` f5 → `temp_f5` **f6** (aiy family empirically: f6, 98.33). The lfs must overlap `temp_f5` (any in-block position does — proved by zlf/h batches), so f5 *requires* the const to stay short-range → const ≠ f3 → units 1+2 always present with f5. The short/long distinction: y2 as an *expression node* (created mid-IR) vs a *named decl* (low vreg) — both placements of `y0` tested give the same result.
- **Units 3+4 and f5 are mutually exclusive**: f5 needs the t4sq-cross, which forces x-store late (≠ retail position) and the extra lfs. No f2-form can match retail's f5 either.
- Therefore **f5 ⇒ dist ≥ 4 ⇒ ≤ 99.5232**, while HEAD's f2 form sits at dist 3 = **99.642**. Every enumerated form (batches 8–16, ~600 candidates this session incl. round Q's 535) falls on one side or the other.

### State at end of round
Tree restored to HEAD (`4ba044a`), re-verified: **99.642, 838 insns, clean** (only this field-notes file modified). Batch scripts `f5batch11.py`–`f5batch16.py`, `tu_*.cpp`, `dumps_*`, plus `diffkind.py` kept for reproduction.

## Round T (blockdump + f5batch19–23) — the z-forward f5 family, and the greedy-model proof of the 4-unit floor (2026-10-15)
### HEAD's block anatomy (blockdump.py: backend-31 block, every vreg annotated with its final colour)
Retail/HEAD sequence, indices via pairdump: 490 `_a8.x` pair, **492 const lfs (f3)**, 493 `_a8.y` pair, **495 y2 = const² (f0)**, **496/497 `_a8.z` pair (f1)**, 498/499 temp5/temp4 loads (f5/f4), 500 t5sq (f1), **501 X (f5)**, 502 t4sq (f2), **503 Z (f4)**, 504 fadds1 (f0), **505 Y = const (f3)**, 506 fadds2 (f1). The const's long range [492..505] comes from the **late-scheduled y-store** (it has no consumer, so the scheduler delays it past fadds1) — that is what makes const = f3. HEAD matches all of it except temp5 = f2 (units 498/500/501).
### Config J (f5batch20): the `_a8.z`-forward — first zero-inventory f5 family
Source: `accum.z = _a8.z;` (z-store forwards the `_a8.z` load, extending that vreg's range through the temp loads) + HEAD's y-side. **12/12 f5 hits** (all 6 orders × `_a8.z`/`zb.z`, s0); `ci.wallNrm.z` control never f5 (CSEs with temp_f4). Best: `J_zxy_a8_s0`/`J_xzy_a8_s0` = **99.5227** (838 insns, 4 units, *no* DIFF_INSERT — the edge reuses retail's own 496-load). This **refutes Round S's "units 1+2 always present with f5"**: J_zxy has const = f3 and y2 = const² (492/495 absent) because the edge came from the z-side, not an extra y-lfs. Remaining units: J_zxy = `_a8.z` colour (f2 vs f1 @496/497) + x/z store positions swapped (501/503); J_xzy = `_a8.z` colour + temp4 colour (499) + t4sq cascade (502) — positions exact.
### The greedy-model proof (validated on full colour maps from `regalloc-fpr-pass-1-all.txt`, cmpalloc regex fixed)
Pass 1 colours in descending vreg order, smallest free colour. The chain is *forced*: y2 (highest) = f0, t5sq = f1, t4sq = f2, const = f3 (its higher nbrs {y2,t5sq,t4sq} = {f0,f1,f2}); then the forward value f147 = lowest free of {f0,f1,f2,f3} **minus t4sq**: if z-store ≥ 502 (x-first orders) f147 ∋ t4sq → **f147 = f4** → blocks temp_f4 from f4 → temp4 = f2 (J_xzy); if z-first (z@501) f147 ∌ t4sq → **f147 = f2** → temp4 = f4, temp5 = f5 (J_zxy) but x loses the post-t5sq tie → position swap. Without any forward: temp5's nbrs = {y2,t5sq,const,temp4} = {f0,f1,f3,f4} → **f2 = HEAD**. So f147 ∈ {f2, f4} only (f1 impossible: any z ≥ 500 overlaps t5sq; f3 taken by const), and **f5 ⇒ ≥4 units; honest ⇒ exactly 3** — matching every measurement (batches 19–23 ≈ 100 more candidates: batch19 = ysq-decl variants, no f5 — a decl ysq gets a low vreg and kills y2's expression-node f0; batch22 = 48-variant K grid, f5 only in `d45ta*` = decls temp_f4-first + z-forward; batch23 = config L, the A-reload without named y0 — the reload lands on the y2 critical path *before* t5sq, no f5; y-store operand can be const (long → f3, no edge) or a forward (edge → const short), never both = Round R's triangle re-derived per-slot).
### State at end of round
Tree at HEAD, re-verified via `diffkind.py baseline`: **99.642, units 498/500/501** (retail `lfs/fmuls/stfs f5` vs ours f2), only field-notes modified. Kept: `f5batch19/20/22/23.py`, `blockdump.py`, fixed `cmpalloc.py`, `pairdump.py`, `tu_*`/`dumps_*` artifacts.

## Round U (verprobe + f5batch24–30) — the role-swap family, and the first source form ABOVE 99.642 (2026-10-15)
### Compiler axis closed (verprobe.py + oobin.py)
Probed the HEAD source under all 9 MWCC versions on hand. Only **0x4201_127 = 99.642**; **1.0RC1 / 1.0a = 99.1647** (sqrt block byte-for-byte identical to HEAD — verified by `oobin.py` on `v_1_0a.o` — temp5 still f2, plus 4 prologue/epilogue units); the other six = 92.9594. Retail's f5 is a **build-specific RA artifact** of the original toolchain, absent from every shipped version. Axis closed; `0x4201_127` stays.

### batch24 — sqrt tree shapes × {d54,d45} × xzy (LIFO hypothesis)
12 left-deep tree shapes. The cross `((t4sq + t5sq) + y2)` (`T_d45_h_abp_c`) produces the t4sq-cross + const = f3 but the cascade rotates (temp5 → f0). No f5.

### batch25 (U1–U6) — store orders, comma-X/comma-XZ, compare-RHS carriers
temp5 reached f0/f4, never f5. **Master rule:** whichever store (or comma item) is **first in IR** is hoisted into the `t5sq`↔`t4sq` window by the scheduler, shortening that value's range and rotating the whole cascade.

### batch26 (V1–V4) — all three stores in the comma condition
`V4_m0_x_z_y` = **first f5 hit** (temp5 = f5, temp4 = f4) via `... + (accum.x = temp_f5) * 0.0f + (accum.z = temp_f4) * 0.0f` — `*0.0f` folds to `0.0f` with no instruction, but the carrier's stores land at the carrier-add position → order damaged → 98.4524 (12 units).

### batch27 (P1–P4) — d45 + zero-inventory f5
`P4_d45_xzy` = f5 + **retail-exact instruction order, zero inventory**, 99.5227 (4 units; `_a8.z` pair = f4 vs retail f1, temp4 = f2 vs f4, t4sq operands). Confirms the z-forward family's 4-unit floor.

### batch28 (Q1–Q5) — d45, no z-forward, X-carrier
`Q1_yz` / `Q5_yz` = **temp5 = f5 AND temp4 = f4**, 99.5232 (4 units): X-store arg (X late), Y-store arg (Y early), fadds arg cascade, and one DIFF_INSERT (the carrier's `+0.0f`; only `*0.0f` folds). Q2_yz 98.6889; Q1_zy temp5 = f4. The X-carrier pulls X late enough to cover t4sq → temp4 = f4, but displaces both X and Y.

### batch29 (R) — THE ROLE SWAP: tree squares `_a8.z`, z-store keeps `temp_f4`
Move the forward from the **store** into the **tree**: `sqrt((_a8.z * _a8.z) + ((temp_f5*temp_f5) + (accum.y*accum.y)))` with the ordinary `accum.z = temp_f4` and d45 decls (a8zc = cross tree, ci = control). All 6 store orders × {a8z} → **12/12 f5 + f4 hits**.
- **`R_d45_a8z_xzy` = 99.7613 (2 units) — the first source form ABOVE 99.642.**
  Emission: pair 496/497 (f147 = **f1**, retail-exact), **z-mul `fmuls f2,f1,f1` @498**, temp5/temp4 loads 499/500, t5sq 501 (f1), X 502 (**f5**), Z 503 (**f4**), fadds1 504, Y 505 (**f3**), fadds2 506. Units = `DIFF_INSERT` @498 + `DIFF_DELETE` @503 (retail `fmuls f2,f4,f4`) — i.e. **only the z-mul's position/operands**; every colour is retail-exact.
  Mechanism: the early z-mul's *result* is live across `temp_f5`'s def, so it is `temp_f5`'s **f2-neighbour** — exactly what retail's `t4sq = f2` is (there, X precedes t4sq). temp5 nbrs = {z-mul=f2, y2=f0, const=f3, t5sq=f1, temp4=f4} → **f5**; temp4 = f4; the pair stays short [496..498] → **f1** (unlike the J z-forward family, where the long pair forces f2/f4).
- `R_d45_a8z_xyz` (retail store order) = 99.5227 — Y before the mul costs Y/fadds units; `_xzy` wins because Y is scheduled after fadds1.

### batch30 (S) — mixed-operand z-mul `(_a8.z * temp_f4)`
Semantically identical (`_a8.z == temp_f4 == wallNrm.z`), but the mul now needs the late temp4 load → schedules at the correct slot 502. 16/36 f5 + f4 hits; best **`S_d45_az_xzy` / `S_d45_za_xzy` = 99.642** (3 units: pair 496/497 = f2 vs f1 — the mul reads f147, extending the pair into the long-range domain — plus 502 operands `f2,f4` vs `f4,f4`). Ties HEAD; does not beat R.

### The pair-range ↔ mul-position tension (why R's last 2 units are the floor)
R's residual = the z-mul's *position*: it reads `_a8.z` (forward of the pair's f147, ready at the 496 load) so the scheduler hoists it to 498. Every attempt to *delay* the mul instead makes it read the live `temp_f4` → `temp_f4²` becomes temp4's only use → **temp4 = f2** = HEAD's deadlock. Empirically: relocating the `_a8.z` assign inside the region (`R_movepair`) still hoists the pair load and the tree's `_a8.z` CSEs with `temp_f4` → collapses to HEAD (temp5 = f2); `zb.z` is unsafe (pre-`normalise()` copy ≠ `wallNrm.z`); a volatile reload adds an `lfs` (INSERT) without removing the 2 units.
So under `0x4201_127`'s **greedy lowest-free** allocator: honest f2 form = **3 units (99.642)**; store-forward form = **≥4 units (≤99.5232)**; the **role-swap = exactly 2 units (99.7613)**, whose single residual is one early-scheduled `fmuls`. Retail's own block (`t4sq = f2` **and** temp4 = f4 simultaneously) needs a non-greedy colour decision — the **same N2 gap** (round N), now re-derived as the reason the last 2 units cannot be closed from source.

### Adopted
`src/kart/KartState.cpp` now carries `R_d45_a8z_xzy`. `vwin2.py` on the real source: **('win', 99.7613, '')**, **838 insns** (no inflation); `diffkind` units = 498 INSERT / 503 DELETE; residual comment updated (99.64 → 99.76). Kept: `f5batch24–30.py`, `verprobe.py`, `oobin.py`, `verprobe/v_*.o`, `tu_*`/`dumps_*`.

## Round V (10 subagents) — independent vectors confirm the 2-unit ceiling (2026-10-15)
Ten parallel agents, each with a distinct attack vector grounded in the Round U mechanism, ran on an isolated harness (`build/mwcc-debug/agentkit.py`: per-agent scratch + a cross-process lock serialising the gdb dumps; agents never touch `src/`). **None beat 99.7613; every vector re-derived the same wall.** Combined ≈25,000+ scored variants.
| ag | vector | n | best |
|---|---|---|---|
| A1 | z-mul operand spellings × placements (mixed operands delay the mul) | 210 | 99.7613 (mixed → mul@502 but pair f2 → 3 units) |
| A2 | alternative f2-neighbour over temp_f5's range | ~500 dumps | 99.7613 (any live-across f2 node is the early z-mul, or a pair load → ≥3) |
| A3 | full cartesian grid of the role-swap design | **10,368** | 99.7613 (0 above; per-axis bests saturate) |
| A4 | retail-source reconstruction / principled rewrites | ~7,000 | 99.7613 (new equivalent: accum-stores + `_a8.z²` tree) |
| A5 | named sub-results / comma-sequencing at the new base | ~200 | 99.7613 (named low-vreg forms still die) |
| A6 | critical-path / association & depth steering | 264 | 99.7613 (12 binary trees; the ready mul hoists to 498 in every shape) |
| A7 | old stalled families crossed with the role-swap | 621 | 99.7613 |
| A8 | objdiff alignment rule + unit arithmetic | ~1,200 | 99.7613; **rule derived** |
| A9 | source-visible micro-levers (spelling, literals, casts, parens) | ~1,000 | 99.7613 (all neutral) |
| A10 | role-swap × repositioning carriers (comma / `*0.0f`) | ~890 | 99.7613 |
### The alignment rule (A8, from objdiff `diff/code.rs`)
objdiff aligns the two streams **by opcode** (Patience/LCS) and computes `match% = 1 − (#rows with diff_kind)/max(len_target, len_ours)`. Every row costs 1; a **moved** instruction is INSERT+DELETE = **2**. Our block = retail's stream with `t4sq(fmuls f2,f4,f4)@502` removed and `z-mul(fmuls f2,f1,f1)@498` inserted → exactly 2 units. A 1-unit form needs retail order with temp_f5=f5; temp_f5 needs an f2 value live across its def, and every mechanism costs 2 rows (pair recolour, or the INSERT+DELETE move).
- **Instruction-adding "climb" (rejected):** keeping the pair→z-mul AND retail's t4sq (an extra `fmuls`) yields a 839-insn block scoring `1−1/839 = 99.8808` — but the function is then 1 instruction longer than retail, i.e. a fake match that fails the insn-count invariant and can never reach the build's 100%-exact criterion. Recorded for completeness; not adopted.
### The mechanism, closed (A1/A2/A3/A6)
`pair = f1` requires the z-mul to read **only** the early `_a8.z` (pair-forward f147, ready at 496) — but the list scheduler then hoists that mul to 498 (INSERT+DELETE). Moving it to retail's 502 requires reading the late `temp_f4` load, which **extends the `_a8.z` web across t5sq** → the pair's greedy colour drops to **f2** (its lfs+stfs recolour = 2 units); or, honest, `temp_f4²` becomes temp4's only use → temp_f5 collapses to **f2** (HEAD deadlock, 3 units). The only free f2-neighbour that keeps everything else retail-exact is the early z-mul **result** — exactly the 2-unit role-swap. So **99.7613 is the 838-insn source ceiling**; 0 units needs retail's non-greedy colour decision (the N2 patch).

## Round W (5+5 split: POSITION vs COLOUR) — the last 2 units resist both halves (2026-10-15)
The 2-unit residual is one relocated `fmuls` (our early z-square @498 vs retail's t4sq @502). Split into its two halves and attacked by 5 agents each (isolated `agentkit` ids; C5 cancelled as it re-swept grids A3/C3/P5 had already exhausted). **No form beat 99.7613; no 0/1-unit form exists.**
### POSITION half (p1–p5): can the multiply land at retail's 502?
- **p1 (memory-dependency entry):** store-to-load forwarding erases any re-read — `accum.z = temp_f4; sqrt(accum.z*accum.z …)` compiles byte-identical to HEAD (mul reads temp_f4's register, 99.642). A real reload (`volatile`) adds an `lfs` (+1 insn) and pushes the mul's web past temp_f5 → 99.2849.
- **p2/p4 (scheduler probing):** rule measured on `backend-27/28`: the list scheduler emits each arithmetic op **as soon as its last operand is ready**, via critical-path priority — so the `_a8.z` square commits immediately after the 496 pair load/store, ahead of the temp loads. Self-assign/comma def-chains fold; nothing lowers the ready-mul priority.
- **p3 (make 498 a load):** ACHIEVED — the mixed z-term `(_a8.z * temp_f4)` (also `_a8.z*ci.wallNrm.z`) emits retail's *exact* positions for 496–501 (incl. `lfs f5,0x24` lockstep at 498) and the mul at 502, 838 insns, temp_f5=f5/temp_f4=f4 — but costs the pair colour (f2 vs f1 @496/497) + the mul operand (f2 vs f4) = **3 units, 99.642**.
- **p5 (9,008-variant grid):** min = 2 units; the only `mul@502 ∧ temp_f5=f5` family is the mixed z-term above, at 3 units.
### COLOUR half (c1–c4): can temp_f5 keep f5 with the multiply late?
- **c1 (enumerate f2 sources):** the only node that can be a live **f2** neighbour of temp_f5 is the z-square result; making it a *late* f2 requires it to consume the pair (→ pair f2, operand f2≠f4) or temp_f4 (→ no overlap, temp_f5=f2). No third zero-inventory f2 source.
- **c2 (extend temp_f5 over t4sq):** if the X store moves after the mul (zxy, `temp_f4²`), temp_f5 *does* cross the late mul — but that t4sq then **reuses temp_f4's freed f2** (ranges disjoint) so temp_f5 still sees only {f0,f1,f2,f3} → f4; stores also swap (99.284, 6 units). The new neighbour must add a *fresh* colour, not re-share one.
- **c3/c4 (recolour the neighbourhood / move temp_f4 off f4):** the pair and temp_f4 **compete for f4 by degree** — whichever has more neighbours claims f4, the other falls to f2. Two near-misses reach `mul@502 ∧ temp_f5=f5 ∧ temp_f4=f4 ∧ pair=f1` but each pays 3 units (`t4|_a8.x²` recolours `_a8.x`→f2 @490/491 + x-mul operand @500; `a8z*t4` recolours the pair @496/497 + z-mul operand @502).
### Net
Both halves hit the same greedy-allocator wall: `temp_f5=f5` needs an f2 value live across its def; the only free one is the early z-square result, which forces the mul to 498 (the 2-unit role-swap). Retail's simultaneous `temp_f5=f5 ∧ t4sq=f2 ∧ pair=f1` is the non-greedy choice (N2). Confirmed with new measured rules (scheduler readiness rule; pair-vs-temp_f4 f4-degree competition). **99.7613 remains the 838-insn source ceiling.**

## Conclusion / current state
- **Committed source = 99.7613%** on `sync-doldecomp` (role-swap sqrt block), stock compiler `0x4201_127`, 838 insns, reproducible. The last 2 instructions are ONE early-scheduled `fmuls` (position-only; INSERT@498 + DELETE@503 under objdiff's opcode-alignment).
- **100% is VERIFIED** via the principled gated patch (N2: missing edge + stack order) — non-standard (patched compiler + gate pragma), deliberately kept as documentation, not wired into the build.
- **2026-10-15 sweeps**: 535 source forms (round Q) + rounds R/S/T/U RA-graph/gap/batch11–30 (~2000 candidates). Round T proved both old floors allocator-forced (honest = 3 units; any store-forward = ≥4); **round U broke the honest floor** with the role-swap (tree-forward instead of store-forward): the early z-mul's result becomes temp5's f2-neighbour while the pair stays short → 99.7613 (2 units). The residual is the single hoisted `fmuls`; delaying it re-collapses to the HEAD deadlock, and closing it needs retail's non-greedy colour choice (= N2). **Round V's 10 independent agents (~25,000 variants, incl. a 10,368-form cartesian grid) found 0 forms above 99.7613**; **Round W** split the residual into POSITION vs COLOUR (5+5 agents) — both halves re-derived the same greedy wall, and no 0/1-unit form exists.
- **Data**: `subagent_data/subagents.db` + `subagent_data/artifacts/` (wins 00..07, compiler patches incl. N2).
- **Honest bottom line: 99.7613 landable; 100% documented and verified (N2).**







