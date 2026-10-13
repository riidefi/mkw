# Compact gate for per-function compiler tweaks — results (as5)

## Gate primitive
- Option byte:  `_copts[0x6D]`  VA 0x74F395  (RVA 0x34F395)
- Driver sets it: `-pragma "report_heap_info on"`  (or `#pragma report_heap_info on`)
  - frontend writes it in `_CodeGen_ParsePragma`: on -> 0x66A4A (`mov byte [0x74f395],1`), off -> 0x669D6/0x66A1B
  - verified inert for KartState.cpp (score unchanged, object byte-identical)
- Function selector: `_gFunction` VA 0x751E44 -> [+0x0C] -> name chars at +0x0A  ("updateCollisions")
- Hook site: RVA 0x1b4420 in `_colorinstructions`; hook bytes `e9 d5 82 0b 00 90`
- Cave: RVA 0x26c6fa (.text tail padding; 0x106 bytes free)

## Re-test table (objdiff match % for updateCollisions)
gate OFF is always baseline (97.7327, inert); gate ON applies the candidate only to updateCollisions.

| candidate | site RVA(s) | gate-ON |
|---|---|---|
| reversed node scan (saved-reg hand-out order) | 0x1b1511 | 66.5871 |
| flipped tie-break 0x1b4634 (jne->je) | 0x1b4631/0x1b4634 | 97.7327 (no change) |
| force _pickcolor class-4 path | 0x18e704/0x18e70b | 55.8473 |
| _pickcolor mask/branch order swap | 0x18e711/0x18e716 | 97.7327 (no change) |
| FPR graph-sort enable | 0x18e5ec/0x18e5ed | MWCC internal crash |
| FPR sort comparator reversal (jl->jg) | 0x18e614 | 97.7327 (inert; sort disabled) |
| scheduler model @0x1b6ad0 forced k | 0x1b6ad0 | max 97.7327 (k=4,7); others 68.5-91.8 |
| GPR scratch override v91->r6,v82->r5 | 0x1b4420 | 98.4487 |
| FPR scratch override v36->f5 | 0x1b4420 | 98.0907 |
| GPR+FPR combined | 0x1b4420 | **98.8067** |

Best: 98.8067. 100% not reachable with these levers.
Residual (10 mismatches, idx 458..477): dot/sqrt load-store schedule rotation + FPR names (T f2/O f1, T f3/O f2).

## Option-state survey (gate candidates)
| VA | _copts off | setter | note |
|---|---|---|---|
| 0x74F339 | +0x11 | _CodeGen_UpdateObject 0x66616 (derived) | read by _machine_specific_sort_graph 0x18e5e5, _pickcolor 0x18e704; not pragma-settable |
| 0x74F342 | +0x1A | _CMach_SetBackEndOptions 0xF07E2 / scheduling pragma (PushOption id 0x1A) | scheduler model; read at _scheduleinstructions 0x1b6ad0 |
| 0x74F34E | +0x26 | _CodeGen_ParsePragma 0x6755E/0x6759D/0x675FE (`#pragma altivec_model`) | not inert (90.93) |
| 0x74F395 | +0x6D | _CodeGen_ParsePragma 0x66A4A (`#pragma report_heap_info on`) | INERT -> chosen |
| 0x74F3A9 | +0x81 | `#pragma strict_ieee_fp` (PushOption id 0x81) | inert |
| 0x74F399 | +0x71 | `#pragma prepare_compress` (PushOption id 0x71) | inert |
| 0x74F34F/50 | +0x27/28 | `#pragma altivec_vrsave` / `function_align` (_CPrep_PushOption 0x47c60) | inert |
