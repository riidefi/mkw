# Artefacts — `KartState::updateCollisions`

The **durable** collection for the `updateCollisions` investigation. Everything here is
listed in the DB's `artifacts` table (`sqlite3 subagents.db "select * from artifacts"`).

The full raw scratch — ~220 000 candidate files / ~3.1 GB of compiled objects — lived only
in `%TEMP%\opencode\perm\sub1..sub10` and is **not** archived (it is regenerable from the
harness + the edits recorded in the DB/field notes).

## `wins/` — the score ladder (the four winning source *shapes* + the final)

| file | score | shape |
|---|---|---|
| `00_86.9928_proxyF_split.cpp` | 86.9928 | `proxy` lifetime split (`KartObjectProxy* proxyF = proxy;`) + `var_r28` mask form — the first win |
| `01_94.3914_subaddr_temp.cpp` | 94.3914 | **sub-address temp**: `p3 = lbl_1_data_3918 + 3; pe = p3 - 3;` → `pe` becomes a compiler temp → colours **r30**; `var_r28`/`var_r27` declared first |
| `02_95.9427_s8_playerIdx.cpp` | 95.9427 | `s8`/`u8 playerIdx` defeats the `(u8)`-cast CSE → **4× `clrlwi`** + `cmpwi` + **838 insns**; `RaceManager* rm` before `RaceConfig* rc` |
| `03_97.0167_typed_vcall.cpp` | 97.0167 | **typed virtual call** (`((KMVT*)rm->raceMode)->f12(...)`) → vtable temp **r12** |
| `04_97.7327_dotZY_final.cpp` | 97.7327 | **inline `dotZY` boundary** → fixes the `zeroY` stack-slot order — the current best |
| `final_KartState.cpp` | 97.7327 | snapshot of the committed `src/kart/KartState.cpp` (authoritative) |

## `compiler-patch/` — the (non-standard) gated compiler patch
- `FINAL_patch.json` — the AS5/FPR2 clean-gate patch (hook RVA `0x1b4420` + 156-byte cave
  `0x26c6fa`; gate `_copts[0x6D]` set via `-pragma "report_heap_info on"`). Produces **99.1647**
  but is **answer-encoding / non-reproducible** — deliberately **not** landed.
- `final_patch.py` — AS1's per-byte patcher (the scratch `r5`/`r6` swap → 98.4487).
- `RESULTS.md`, `as4_REPORT.md` — AS5's gate survey / re-test table and AS4's interference-graph RE.

## `harness/` — the tooling
- `h.py` — scores a source string: compiles it with MWCC `Wii/0x4201_127` (project flags) and
  reports objdiff `updateCollisions` match%.
- `make_ws.py` — builds the private trusted workspaces (`sub1..subN`): snapshot + repointed
  `h.py`/`probe.py` + a 93.4x/97.x baseline check.
- `probe.py` — the PRE/BODY/POST probe harness.

## `decompme/` — `hbr0m.zip`
The decomp.me scratch bundle (scratch `hbr0m`) with its `ctx.cpp` and the WIP source at the
86.99-era state.

## Notes
- `05_expr` — no further source shape beat 97.7327: the last **19 instructions** are a hard
  allocator/scheduler fixed point under `0x4201_127` (see the DB `findings`/`proofs`).
- The compiler-patch files are kept **for the record only** (they document the allocator/
  scheduler internals); do not wire them into the build.
