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

## 8. The 10 NEW hypotheses (not covered by §6)

Each is **measurable** (`K.score_region`/`K.dump`) and **independent** of the exhausted grids. Ordered by expected yield.

**H1 — TU function ordering.** The greedy dealivergence depends on the surrounding *emitted* code (round Z5: removing `updateWipe` changes the allocation). Re-test at the 99.7613 base by moving `updateCollisions` relative to its neighbours, or lightly perturbing the preceding emitted function, to flip the f2/f5 choice. *Why new:* only lightly probed pre-role-swap. *Measure:* score of the role-swap block across neighbour permutations. *Anti-waste:* only permutation, not new trees.

**H2 — Function-scoped `#pragma`.** MWCC honours per-function pragmas (`#pragma scheduling`, `#pragma global_optimizer`, `#pragma peephole`, `#pragma opt_common_subs`, push/pop) that may alter the list-scheduler/allocator for the block. Enumerate around the function (gate OFF must stay byte-identical). *Why new:* round Z tested global flags, not function-scoped pragma families at this base.

**H3 — Role-swap source × all 9 compiler versions.** Round U probed only the *HEAD* source across builds. Re-run the *role-swap* block under `1.0RC1`/`1.0a` (whose allocator may be non-greedy like retail) — they reproduced HEAD's block structure exactly, so the role-swap may reach 1/0 units there. *Why new:* never tested the winning source on other builds. *Cheap.*

**H4 — THEN-block perturbation.** The `sp20` re-store body (inside the replaceable region) sets accum.x/z/y after the branch. Permute/rewrite those three stores (order, operand, `*(f32*)&`) to change post-block liveness and the FPR cascade. *Why new:* the THEN block was always held fixed.

**H5 — Full-prologue permutation (custom base).** The region currently starts at the first temp decl; `ci.wallNrm.normalise(); _a8.{x,y,z} = ci.wallNrm.{x,y,z};` sit *before* it and were never permuted. Build a custom base that moves those lines into the region and permute their order/interleaving with the temps. *Why new:* the one prologue segment never searched.

**H6 — Inlining boundary at the new base.** Wrap the sum in a `static inline`/force-inlined helper (or an `EGG` vector helper) so the FPR web is built differently but inlines to 17 insns. Round Y tested helpers at 97.7 for the saved-register band; retest on the role-swap base for an FPR recolour. *Why new:* not retested post-role-swap.

**H7 — Compile-context / sibling-function perturbation.** Perturb other functions in the TU (dummy float code, extra literals, reordered float pools) to shift the shared FPR scratch pool / rodata and the colouring. *Why new:* Z4/Z5 ran pre-role-swap; the rodata pool and neighbours changed since.

**H8 — Legitimate build-config sweep at the new base.** Re-test `-O` sub-options, `-schedule`, `-ipa` levels, `-inline` levels *on the adopted source* (per-file), looking for a config where the retail schedule falls out. *Why new:* flags were "proven original" at 97.7; re-confirm at 99.7613 and check sub-options.

**H9 — Alignment: turn INSERT+DELETE into a single REPLACE (1 unit).** Under the §0 rule, if our **slot 498** held an opcode retail also has there (a load), the moved multiply could align as one `REPLACE` (1 unit) instead of `INSERT`+`DELETE` (2). Search 17-insn opcode permutations where our 498 is a load and the multiply sits where retail has an `fmuls`. *Why new:* §V only examined the two candidate forms, not the alignment-optimal opcode ordering. *Measure:* unit kinds + score.

**H10 — Outer-block restructuring.** The sqrt block is nested inside `if ((za.z*zb.z + …) < 0.0f || _68 >= 1.0f)`. The `za`/`zb` wall-dot locals and that outer condition pin FPRs. Restructure the outer `if` (or the wall-dot expression) — semantically identical — to free/reassign a register feeding the sqrt cascade. *Why new:* only the sqrt interior was ever searched; the enclosing block was fixed.

## 9. Anti-waste rules for subagents

1. **Read this file first**; check §6 before generating candidates. If your idea is in §6, stop.
2. Use `agentkit` with your **own** id; it caches scores/units/colours by source hash — re-scoring a known candidate is instant and never duplicated.
3. Every candidate must be **semantically identical** and must **not add an instruction** (838 insns; 839+ = fake match, rejected).
4. Report: best region text, `score`, `units` (kinds), `temp_f5`/`temp_f4`/`pair` colours + multiply slot; and whether it beats 99.7613.
5. Never modify `src/` or commit; only write your own `f5<id>.py` + `agentkit` artifacts.
