# Consolidated proofs, artifacts & hypotheses — `KartState::updateCollisions` (MKW)

> **READ-FIRST BRIEFING FOR SUBAGENTS.** This is the single authoritative, up-to-date state.
> It supersedes the historical `PROCESSES_AND_PROOFS.md` (93.4%-era) and complements the
> chronological `SUBAGENT_FIELD_NOTES_updateCollisions.md` (rounds A…W). Do **not** re-run
> anything in the **EXHAUSTED** table (§6). Aim only at the **10 hypotheses** (§8).

---

## 0. Target, toolchain, metric

- **Repo** `C:\Users\nnnn\Documents\mkwii`, branch `sync-doldecomp`, HEAD `859afcd`.
- **Function** `KartState::updateCollisions` (838 instructions retail; the residual is entirely the sqrt block ~lines 451–460).
- **Compiler** `build/compilers/Wii/0x4201_127/mwcceppc.exe`; flags in `agentkit.FLAGS` (identical to `%TEMP%\opencode\perm\h.py`). The toolchain/flags are proven original (12/16 functions + all `.data` already 100%).
- **Metric (proved, round V-A8, from objdiff `diff/code.rs`):** objdiff aligns the two instruction streams **by opcode** (Patience/LCS) and reports
  `match% = 1 − (#rows carrying diff_kind) / max(len_target, len_ours)`.
  Every row costs **1 unit**; a **moved** instruction = `INSERT`+`DELETE` = **2**; a same-slot operand change = **1** `ARG_MISMATCH`; a same-slot opcode change = **1** `REPLACE`.
- **Current committed source = 99.7613** (838 insns; units = `498 INSERT` + `503 DELETE`).

## 1. Retail block ground truth (indices 492…506)

| idx | insn | colour | meaning |
|---|---|---|---|
| 492 | `lfs f3, 0(r29)` | f3 | const `0.0f` |
| 495 | `fmuls f0, f3, f3` | f0 | y2 = y² (y=0) |
| 496/497 | `lfs f1,0x2c(r31)` / `stfs f1,0xb0(r20)` | f1 | `_a8.z` pair (short range) |
| 498 | `lfs f5, 0x24(r31)` | f5 | temp5 = wallNrm.x |
| 499 | `lfs f4, 0x2c(r31)` | f4 | temp4 = wallNrm.z |
| 500 | `fmuls f1, f5, f5` | f1 | t5sq = x² |
| 501 | `stfs f5, 0x2c(r1)` | f5 | X = accum.x |
| 502 | `fmuls f2, f4, f4` | f2 | t4sq = z² |
| 503 | `stfs f4, 0x34(r1)` | f4 | Z = accum.z |
| 504 | `fadds f0, f1, f0` | f0 | sum1 |
| 505 | `stfs f3, 0x30(r1)` | f3 | Y = accum.y |
| 506 | `fadds f1, f2, f0` | f1 | sum2 |

Store order x,z,y. `ci.wallNrm` is normalised just above; `_a8.{x,y,z}` are copies of it; `accum` is an `EGG::Vector3f`.

## 2. The current best form (committed; adopted in round U)

```cpp
          f32 temp_f4 = ci.wallNrm.z;          // d45: temp_f4 declared FIRST (vreg f36)
          f32 temp_f5 = ci.wallNrm.x;          //                 temp_f5 second (vreg f35)
          accum.x = temp_f5;
          accum.z = temp_f4;
          accum.y = 0.0f;
          if (EGG::Mathf::sqrt(((_a8.z * _a8.z) + ((temp_f5 * temp_f5) + (accum.y * accum.y)))) < 0.05f) {
```
Its emitted stream: pair 496/497 (f1) → **`fmuls f2,f1,f1` @498** → temp5/temp4 loads 499/500 → t5sq 501 → X 502 → Z 503 → fadds 504 → Y 505 → fadds 506.
**All colours are retail-exact**; the ONLY residual is the multiply's position (2 units).

## 3. The mechanism (why 2 units is the floor)

- The FPR allocator is **greedy, lowest-free, in descending-vreg order**. `temp_f5` is the lowest FPR vreg → coloured **last**, so `temp_f5=f5` requires its neighbours to cover **f0,f1,f2,f3,f4** (5 distinct).
- The block naturally supplies only 4: `temp_f4=f4, const=f3, t5sq=f1, y2=f0`. The missing **f2** must come from a value **live across `temp_f5`'s def**.
- The only zero-inventory value that can be that f2 neighbour is the **z-square result** — and to cover temp_f5 it must be computed **early (@498)**, which is exactly the 2-unit move.
- Forcing the multiply to retail's **@502** makes it read the late `temp_f4`; then either (a) the `_a8.z` pair web extends across t5sq → pair recolours **f2** (its `lfs`+`stfs` = 2 units) + the mul operand (1 unit) = **3 units**, or (b) the honest `temp_f4²` leaves temp_f5 with only 4 neighbours → **f2** (the HEAD deadlock, **3 units**).
- Retail's simultaneous `temp_f5=f5 ∧ t4sq=f2 ∧ pair=f1` is a **non-greedy RA choice** = the **N2 gap** (round N). The edge `(temp_f5, t4sq)` is not source-reachable under `0x4201_127`.

## 3b. Optimality theorem — why exactly 2 units is the source maximum (proved first-hand, 2026-10-15)

Verified directly from the two objects (self-written ELF+capstone disassembler, `build/mwcc-debug/dis_count.py` / `compare_two.py`):
- Target and ours are both **838 instructions / 3352 bytes**; the sqrt block (indices 490–506) is 17 instructions with an **identical opcode multiset** (`lfs stfs lfs lfs fmuls stfs lfs stfs lfs lfs fmuls stfs fmuls stfs fadds stfs fadds`).
- Our role-swap stream vs retail: **LCS = 16/17 → unmatched rows = 2(17−16) = 2**, exactly objdiff's `INSERT@498 + DELETE@503`.
- The honest form (retail's own source) compiles to retail's stream **byte-identically except `temp_f5` = f2 vs f5** → 3 `ARG_MISMATCH` (rows 498/500/501). Verified by disassembly.

**Theorem.** Under `0x4201_127`, no semantically-equivalent source scores above 1 − 2/838 = **99.7613**.
*Proof.* Any equivalent form emits the same 17-instruction multiset. Two cases:
- **(A) opcode order = retail's.** The block is retail's stream; our greedy lowest-free allocator gives `temp_f5 = f2` (its neighbours carry only {f0,f1,f3,f4}; the only value that could supply f2 — the z² result — is defined at 502, *after* temp_f5 dies at 501). Hence rows 498/500/501 mismatch ⇒ **3 units**.
- **(B) opcode order ≠ retail's.** Two distinct permutations of the same multiset have LCS ≤ 16, so unmatched rows = 2(17−LCS) ≥ **2 units**.
Therefore units ≥ 2, with equality in (B) — attained by the role-swap (which also renders `temp_f5 = f5`, 0 arg-mismatches). ∎

The only escape from (A) toward 100% would be a source that both keeps retail's opcode order **and** supplies temp_f5 an f2 neighbour — impossible, since that needs a 5th live value = an extra instruction. This is the N2 gap, now as a lower bound.

## 3c. Closure lemmas — the residual is ONE boolean (so the searchable space is 2, not open-ended)

The point of these is to make any future attempt *decidable without compiling*: every source axis except one is provably inert, and the one live axis has exactly two values, both already resolved.

Notation: `temp_f5` = the value the source stores into `accum.x` and squares in the x-term (retail: the `wallNrm.x` load); `z2` = the z-term square `fmuls` (retail: `fmuls f2,f4,f4`). Block = indices 490–506.

- **L0 (forced value DAG).** The opcode **multiset** is forced by the computation: three squares ⇒ 3 `fmuls`, the sum ⇒ 2 `fadds`, `accum.x/.z/.y = ` ⇒ 3 `stfs`, the two `wallNrm` inputs ⇒ 2 `lfs`, the folded `accum.y` ⇒ 1 `lfs`/`li` constant, the `_a8.z` copy ⇒ 1 `lfs`+1 `stfs`. Any equivalent source that keeps the function at 838 instructions emits this multiset. The value DAG is then forced (three squares x²,y²,z²; adds x²+y² then z²+·; three stores; two input loads; one constant). *Empirical closure:* ~3,000 syntactic variants (operand spellings, `squaredLength()`/`lenSq()`/`dot`, guards, decl shapes, store orders, associations, TU context) each land on **2 units or worse** — none reaches a different 17-opcode arrangement above 99.7613.
- **L1 (neighbour count is 4).** In any stream equal to retail's, `temp_f5` lives `[load wallNrm.x .. store accum.x]`; exactly four values overlap it — the constant, y², x², and `temp_f4` (wallNrm.z). (Live-range analysis of the retail bytes; re-derived by hand.)
- **L2 (4 neighbours can never force f5).** Lowest-free colouring gives a vertex the least colour absent from its already-coloured neighbours. With ≤4 neighbours, at most 4 of {f0..f4} are blocked ⇒ the chosen colour is in {f0..f4}, never f5. **So `temp_f5 = f5` ⟺ it has ≥5 neighbours.**
- **L3 (only z² can be the 5th).** The only block value that can be an extra neighbour of `temp_f5` is `z2` (every other value is one of L1's four, or defined after `temp_f5` dies).
- **L4 (z² is a neighbour ⟺ it is defined early).** `z2`'s operand is a copy of `wallNrm.z`; the copies exist at the `_a8.z` store (footprint ready ~496) and the temp load (499). `z2`'s def = operand-ready + mul latency. It overlaps `temp_f5` **iff** it reads the *early* copy (def ≤ `store accum.x`); reading the late `temp_f4` copy puts it at 502 > 501 → not a neighbour.
- **L5 (the two cases — both measured).**
  - *z² reads the late copy (`temp_f4`/`accum.z`/`ci.wallNrm.z` loaded late)* → opcode order = retail's, `temp_f5 = f2` (L2) → **3 units** (rows 498/500/501). This is the honest form and every natural idiom.
  - *z² reads the early copy (`_a8.z`, forwarded)* → `temp_f5 = f5`, but the `fmuls` sits at 498 ≠ retail's 502 → one relocation ⇒ LCS 16 ⇒ **2 units**. This is the committed role-swap.
- **L6 (exhaustive).** L4's operand is either the late temp load or an early wallNrm.z copy; no third value exists (L3), and inventing one adds an instruction (fails the 838 match).

**Corollary (closure).** The *entire* remaining degree of freedom is the single boolean **“does `z2` read the early `wallNrm.z` copy?”** → *false* ⇒ 3 units, *true* ⇒ 2 units. Every other axis (x-source, y-source, operand spelling, declaration form, store order, association, spacing, guards, EGG API vs inline, TU/neighbour context, ABI-preserving flags, compiler version) is proven or measured **inert** (it folds to the same IR / object, or only perturbs the rodata pool / worsens). Therefore:

> **Searchable space = 2 states; both are resolved; nothing remains to brute-force.**
> Any new candidate can be classified by that one boolean without compiling, and its score is 99.642 (false) or 99.7613 (true). Breaking above 99.7613 requires an extra instruction (fake match) or a different compiler binary (the N2 mechanism).

## 3d. Rebuttal-proof — no copy/coalescing-only IR perturbation can mint a 5th neighbour

The only escape from §3b/§3c would be a source that keeps retail's emitted code but perturbs the *interference graph* through IR-only values (copies, CSE, coalescing) that never appear as instructions — giving `temp_f5` a 5th neighbour. This section rules that out.

**Definitions.** An FPR **web** = a maximal set of copy-related vregs sharing one register; the allocator's graph nodes are webs, edges = overlapping live ranges. A web is **materialized** if it holds its value across ≥1 instruction (spills included).

- **Lemma A (nodes ↔ emitted live-ranges).** Every graph node is a register live-range of the *emitted* code. A vreg that is not materialized is either deleted (DCE) or coalesced into a materialized web; neither yields an extra node. *(Only non-measured step; backed by the round-CC RE of `_colorinstructions` + the regalloc dumps, which show nodes = scheduled web live-ranges.)*
- **Lemma B (no phantom neighbours).** By A, `temp_f5`'s neighbours are exactly the register live-ranges overlapping `temp_f5`'s span **in the emitted code**. There is no way to hold a value live across `temp_f5` that is not visible as an emitted register live-range.
- **Lemma C (the window).** In retail's emitted code, the ranges overlapping `temp_f5`'s span are exactly `{const, y², t5sq, temp_f4}` (enumerated from the bytes; re-derived by hand). ⇒ 4 neighbours.
- **Lemma D (perturbation dichotomy).** Any source differing from the honest form changes the emitted code only by: *(i)* reordering/relocating instructions → opcode sequence ≠ retail's → LCS ≤ 16 → **≥2 units** (§3b-B); *(ii)* adding/removing instructions → ≠838 → **fake match**; or *(iii)* a source-only change (copies, spellings, guards, decl shapes, TU context) → **byte-identical** object → identical graph. *(iii) measured directly: the honest, `squaredLength()`, `lenSq()`, `accum`-sourced and `const`-decl forms all hash to the same `updateCollisions` bytes (`sha1 80317656cfe5…`, 838 insns); only the role-swap differs.*

**Theorem.** Under `0x4201_127`'s lowest-free allocator, `temp_f5 = f2` in every 838-instruction, retail-ordered form.
*Proof.* For `temp_f5 = f5` it needs ≥5 neighbours (§3c-L2), i.e. its register must stay live across a 5th value's range. By B, that value is an emitted register live-range; by C retail has only 4; to add a 5th one must change the emitted sequence — which by D is either ≥2 units (i) or not 838 (ii). Source-only changes don't move the graph (iii). Hence no case-A source gives f5; the ceiling is **2 units = 99.7613**. ∎

**Corollary (why this implicates the toolchain).** Retail's own emitted code has the *same* 4-neighbour window (C), so our allocator would assign `f2` to it as well — yet retail's binary has `f5`. Same graph, different answer ⇒ the *rule*, not the input, differs ⇒ the original allocator build differed (the N2 mechanism). The only alternative — a source that adds a 5th neighbour without touching the emitted code — is exactly what this proof excludes.

**Verification of Lemma A (checked, not assumed).** Two independent checks:
1. *Emitted-code graph ⇒ allocator graph.* `build/mwcc-debug/verify_lemmaA.py` rebuilds the block's FPR live-ranges and interference **directly from the machine code** and compares to the allocator dump:
   - honest form: `temp_f5 = f2 [498..501]`, neighbours **4** = `{f0@495(y2), f1@500(t5sq), f3@492(const), f4@499(temp4)}` — identical to `f35 -> f2, neighbors: 4 (f36 f148 f150 f153)`.
   - role-swap: `temp_f5 = f5 [499..502]`, neighbours **5** = `{f0@495, f1@501, f2@498(z-mul), f3@492, f4@500}` — identical to `f35 -> f5, neighbors: 5 (f36 f148 f151 f152 f155)`, and the 5th neighbour `f2@498` **is** the relocated `fmuls`.
   The block's web set is a bijection with the allocator node set (11 nodes ↔ 11 emitted webs); no phantom node overlaps `temp_f5`.
2. *Structural.* The graph is built at `backend-32-after-interference-graph` from the scheduled + DCE'd code (`backend-28`/`-31`); DCE guarantees every surviving vreg is used, i.e. materialized; every later pass (`peephole`, `copy-propagation`) only *merges or removes* vregs and never mints one. So node set = emitted live-ranges, in general — not just for this block.

Hence Lemma A holds for the two graphs that decide this function (4-neighbour honest, 5-neighbour role-swap), and structurally for MWCC's later-stage pipeline. The proof §3b/§3d is therefore complete: **no source (under `0x4201_127`) reaches `temp_f5=f5` without emitting the extra neighbour, so the block's `f5` must come from a different allocator binary.**

## 3e. Axiomatic proof

**Theorem.** Let `T` = the binary `build/compilers/Wii/0x4201_127/mwcceppc.exe` with the project flags. For every source `s` semantically equivalent to the retail sqrt block, if `T(s)` yields an 838-instruction `updateCollisions`, then `objdiff(T(s), retail) ≤ 1 − 2/838 = 99.7613`.

**Axioms** (M = measured/certified by artifacts; C = compiler property, backed by RE + the direct graph check in §3d).

- **AX1 (determinism, C).** `T` is a function: identical input ⇒ identical ELF object.
- **AX2 (metric, M).** objdiff aligns the two streams by opcode (LCS) and reports `1 − rows/max(len)`; a moved instruction = `INSERT`+`DELETE` = 2 rows.
- **AX3 (schedule stability, M).** For the block, the opcode sequence is identical at the pre-regalloc schedule (`backend-28`), post-DCE (`-31`) and post-RA schedule (`-45`); and it equals the emitted sequence (`-46`). *(Verified: the three stage dumps print the same 17-opcode order.)*
- **AX4 (webs = emitted live-ranges, C/M).** The interference graph's nodes are the AX3 schedule's webs; every node that has an edge is a materialized emitted live-range. *(Verified: build the machine-code interference graph and compare (§3d, identical). The regalloc dump lists 153 FPR entries but **31 have 0 neighbours** — the 20 frontend vregs the optimizer eliminates before scheduling (`backend-03…-24`, gone by `-25`) plus non-interfering short values; a zero-degree node cannot be anyone's neighbour, so only the 122 edge-bearing nodes matter, and all are materialized.)*
- **AX5 (frontend canonicity, M).** Sources differing only by value-DAG-preserving rewrites emit **byte-identical** objects. *(Verified: honest/`squaredLength`/`lenSq`/`accum`/`const` all hash to `sha1 80317656cfe5`.)*
- **AX6 (colour rule, C/M).** `T` colours webs lowest-free in descending-web order. *(Measured: `build/mwcc-debug/ax6_check.py` checks every web; **0 violations across all 150/152 pure-volatile webs** in both compiles; the 2 coalesced and 1 saved-register webs use their own mechanisms.)*
- **AX7 (forced multiset, M).** Any equivalent 838-form emits the same 17-opcode multiset (3 squares ⇒ 3 `fmuls`, the sum ⇒ 2 `fadds`, 3 `accum` stores, 2 input loads, 1 folded-`accum.y` constant). *(Measured across ~3,000 forms.)*

**Lemma 1 (neighbour bound).** In any 838-form with retail's opcode order, `temp_f5`'s web has exactly 4 neighbours: the const, y², x² and the z-load.
*Proof.* By AX3 the schedule is retail's; the only web whose range can overlap `temp_f5`'s `[load x .. store accum.x]` besides those three is the z-square, which (AX3 order) is defined after `store accum.x`, hence does not overlap. Enumeration of the block's webs is total (§3d). ∎

**Lemma 2 (no 5th web).** No source adds a 5th neighbouring web without leaving case A.
*Proof.* By AX4 a neighbouring web is a live-range of the emitted schedule; adding one changes the emitted opcode sequence/count. By AX5 a source-only change does not change the emitted sequence; by AX7 the multiset is fixed. Hence a 5th neighbour ⇒ opcode order ≠ retail's (case B) or ≠838. ∎

**Lemma 3 (lowest-free floor).** A web with ≤4 neighbours is never coloured above f4.
*Proof.* AX6: it takes the least colour absent from its (≤4) coloured neighbours, blocking ≤4 of `{f0..f4}`; so its colour ∈ `{f0..f4}`. Hence `temp_f5 = f5` requires ≥5 neighbours. ∎

**Proof of the theorem.** Any equivalent 838-form is case A or case B.
- *Case A (opcode order = retail's):* L1 ⇒ ≤4 neighbours ⇒ L3 ⇒ `temp_f5 ∈ {f0..f4} ≠ f5` ⇒ rows 498/500/501 mismatch ⇒ **3 units** (AX2).
- *Case B (opcode order ≠ retail's):* by AX7 the multiset is equal; two distinct permutations of one multiset have LCS ≤ 16 ⇒ `2(17−16) ≥ 2` units (AX2).
Hence units ≥ 2. The role-swap attains 2 (measured: `INSERT@498`+`DELETE@503`). Therefore the optimum is 2 units = `1 − 2/838`. ∎

**Axiom status.** All measured, now **across the TU** (not just `updateCollisions`):
- **AX6** — `ax6_check.py` / `axiom_sweep.py`: **0 violations across 194 pure-volatile webs in 5 functions** (`calcStartBoost`, `updateWipe`, `reset`, `resetCollisionFlags`, `updateCollisions`).
- **AX4** — machine-code interference graph vs allocator graph, per function (`isotest`): **`alloc-not-machine = 0`** for `updateCollisions` (23/24 edges), `calcStartBoost` (3/5), `updateWipe` (6/6). I.e. the allocator's graph is a *subset* of the emitted interference graph, so every edge-bearing node is a materialized emitted live-range. And edge-bearing nodes ≤ emitted webs in all 5 functions (no phantom interference nodes).
- **AX3/AX5/AX7** — stage-dump schedule identity / object-hash canonicity / ~3,000-form multiset sweep.
- **AX1** definitional.

So the axioms are no longer single-function observations; each holds across every function we dumped, with 0 counterexamples. The residual scope of "measured" is now only the *set of inputs dumped*, not a single function — and to lift it further one would run the same three checks on more TUs, but for `updateCollisions` and its whole TU every step is backed by an artifact.

## 4. Proven floors (every source family)

| family | units | score | note |
|---|---|---|---|
| HEAD honest `temp_f4*temp_f4` | 3 | **99.642** | temp_f5=f2; allocator floor for the honest form |
| **role-swap `_a8.z*_a8.z` (committed)** | **2** | **99.7613** | BEST; early z-mul result = temp_f5's f2 neighbour |
| mixed operand `_a8.z*temp_f4` | 3 | 99.642 | mul@502 retail-exact position, pair recolours f2 |
| store-forward (J `accum.z=_a8.z`) | ≥4 | ≤99.5227 | pair long-range steals f4 |
| Q X-carrier (`(accum.x=temp_f5)*0.0f`) | 4 | 99.5232 | X late, +0.0f insert |
| 839-insn "climb" (keep pair-mul **and** retail t4sq) | 1 | 99.8808 | **REJECTED — 1 insn longer = fake match** |

## 5. Non-source route (documented, not wired in)
- **N2 gated compiler patch** (`subagent_data/artifacts/compiler-patch/N2_principled_patch.json`): supplies the missing `(temp_f5, temp_f4²)` interference edge + simplify-stack relink; gate OFF = byte-identical to stock (99.7613), gate ON = **100.0000**. Non-standard (patched compiler + `-pragma` gate), kept as documentation.

## 6. EXHAUSTED vectors — DO NOT RE-RUN
| round | vector | #forms | best |
|---|---|---|---|
| Q | 535-form space sweep (matrix/hoist/bool/comma) | 535 | ≤99.642 |
| R/S/T | RA-graph, gap, store-order, z-forward families | ~700 | ≤99.5232 |
| U | tree shapes, comma/carriers, role-swap, mixed operand | ~150 | **99.7613** |
| **V** | tree/assoc/store/decl grids, named+comma, micro-levers, carriers, alignment | **~25,000** | 99.7613 |
| **W** | split position vs colour (5+5 agents) | ~18,000 | 99.7613 |
| **X** | H1–H10: TU ordering, function pragmas, role-swap×9 compilers, THEN-block, full prologue, inlining, compile context, build-config, alignment REPLACE, outer block | ~1,500 | 99.7613 |
| Z | asm barriers, self-aliasing, accessors, TU perturbation, compile context | ~2,500 | — |
| AY/AS/CT | idiom/live-range/macro/config + compiler internals | ~30,000 | — |

Covered within those: all tree associations; all 6 store orders; 2 decl orders; all operand spellings (`temp_f4`, `_a8.z`, `ci.wallNrm.z`, `_a8.x`, mixed, cast/paren/deref copies); named sub-results; comma sequencing; `*0.0f`/`+0.0f`/`*1.0f`/identity carriers; store→load forwarding & volatile reloads; memory-dependency entry; scheduler-priority probing; color-neighbourhood reshaping; pair-vs-temp_f4 f4 competition; sqrt/`sqrtf`/cast spellings; literal spellings; extra parens/`{}`/unary `+`; old families (J/P/Q/co/a8y/gap) crossed with the role-swap; objdiff alignment arithmetic. **All ≤ 99.7613.**

## 7. Artifacts (all under `build/mwcc-debug/` unless noted; `build/` is git-ignored but present locally)

**Harness / tooling**
- `agentkit.py` — isolated per-agent harness (unique scratch, cross-process dump lock, **dedup cache**). `K.brief()`, `K.exhausted()`, `K.hypotheses()`, `K.score_region()`, `K.dump()`, `K.units()`.
- `batch_probe.py`, `run_dbg2.py` (`%TEMP%\opencode\mhtri\`) — gdb pipeline dumper.
- `%TEMP%\opencode\perm\`: `h.py` (score core), `diffkind.py` (units), `pairdump.py`, `cmpalloc.py`, `blockdump.py`, `verprobe.py` (compiler sweep), `oobin.py`; `%TEMP%\opencode\verify\vwin2.py` (real-source verify).

**Batch scripts (per round)**: `f5batch2–30.py` (rounds Q–U), `f5u1–10*.py`, `f5p1–5.py`, `f5c1–5.py` (rounds V/W).

**Reports**: `A4_REPORT.md`, `c3_report.md`, `C4_REPORT.md`, `f5u7_findings.md`, `f5c1_findings.md`, `p5_report.md`, `u9_results.md`, `u3_results.json`, `p5_grid*.jsonl`.

**Object/asm oracle**: `build/RMCP01/StaticR/asm/kart/KartState.s:1110-1156`; target object `build/RMCP01/StaticR/obj/kart/KartState.o`.

## 8. Hypotheses H1–H10 — ALL TESTED (round X) — ALL REFUTED

Each ran independently (isolated `agentkit` ids h1–h10); none beat 99.7613 and none reduced the 2 units. **Now part of §6 — do not re-run.** Key datum per hypothesis:

| # | hypothesis | result / new datum |
|---|---|---|
| H1 | TU function ordering / neighbour permutation | ~25 arrangements: `temp_f5=f5`, units **invariant**. The round-Z5 "removing `updateWipe` changes allocation" signal is a **rodata/literal-pool offset artifact**, not an allocator change — the dummy function was confirmed emitted before the block yet changed nothing |
| H2 | function-scoped `#pragma` families | ~490 variants: every codegen-changing pragma (`scheduling off`, `global_optimizer off`, `opt_* off`, `optimize_for_size`) **worsens**; all defaults + region `on…off` → byte-identical |
| H3 | role-swap source × 9 MWCC versions | `0x4201_127` unique best (2 u, 839 total); `1.0RC1`/`1.0a` = 99.2840 **but 841 insns** (not a match); rest 93.1981. No version reaches 1/0 units |
| H4 | THEN-block (sp20 re-store) perturbation | all semantic forms normalise to identical codegen; the then-body does **not** participate in the multiply's fate |
| H5 | full-prologue permutation (custom base) | 204 variants; only byte-identical forms tie; prologue renumbering cannot create the live f2 neighbour |
| H6 | inlining boundary | ~60 helper forms all inline to the byte-identical 838-insn body |
| H7 | compile-context / sibling perturbation | only shifts the shared float pool (adds `ARG_MISMATCH` rows); colours + unit slots invariant |
| H8 | build-config (`-O`/`-schedule`/`-ipa`/`-fp`/…) sweep | 143 configs; base flags optimal; every ABI-intact config reproduces the 2-unit block; FMA / `-O4,s` / scheduler-off / higher sdata degrade |
| H9 | alignment: turn INSERT+DELETE into one REPLACE | a **moved** instruction is always INSERT+DELETE (2); a same-slot opcode substitution gives REPLACE (1) but the block's opcode multiset is fixed by the computation → **1 unit is unreachable from source** |
| H10 | outer-block (za/zb + outer `if`) restructuring | ~40 variants; byte-identical or worse; the outer block does not move the multiply or recolour temp_f5 |

**Two older claims corrected here:** the round-Z4/Z5 "compile-context changes the allocation" reading is **refuted** (H1/H7) — it was literal-pool drift; and the alignment "climb" (H9) is **formally** closed (moves cost 2 units; only substitutions cost 1, and the opcode multiset is fixed). Net: every remaining source/compiler/config/context/alignment lever is exhausted; **99.7613 / 2 units is the ceiling** and 100% needs the N2 gated compiler patch (§5).

## 9. Anti-waste rules for subagents

1. **Read this file first**; check §6 before generating candidates. If your idea is in §6, stop.
2. Use `agentkit` with your **own** id; it caches scores/units/colours by source hash — re-scoring a known candidate is instant and never duplicated.
3. Every candidate must be **semantically identical** and must **not add an instruction** (838 insns; 839+ = fake match, rejected).
4. Report: best region text, `score`, `units` (kinds), `temp_f5`/`temp_f4`/`pair` colours + multiply slot; and whether it beats 99.7613.
5. Never modify `src/` or commit; only write your own `f5<id>.py` + `agentkit` artifacts.
