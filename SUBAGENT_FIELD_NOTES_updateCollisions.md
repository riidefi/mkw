# Field notes — `KartState::updateCollisions` register-wall subagent log

Repo: `C:\Users\nnnn\Documents\mkwii` (Mario Kart Wii matching decomp, PowerPC, MWCC `Wii/0x4201_127`).
Function: `KartState::updateCollisions` in `src/kart/KartState.cpp`.
Target: `build/RMCP01/StaticR/obj/kart/KartState.o` (`updateCollisions__Q24Kart9KartStateFv`).

## Result in one line
20 subagents (3 rounds of 5 + 1 meta round of 5) took the function **86.993% → 93.437%** by
de-cycling `proxy` (a lifetime split), then **proved** the remaining ~6.6% is a frontend
vreg-numbering artefact — not a missing source lever.

Score ladder: `86.9928` (baseline) → `89.7375` (proxy2 split) → **`93.4368`** (proxyF split +
`var_r28` mask form). Nothing in ~150k+ candidates beat `93.4368`.

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







