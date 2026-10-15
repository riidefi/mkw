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
