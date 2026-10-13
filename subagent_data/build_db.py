#!/usr/bin/env python3
"""Build a structured, tool-searchable database from the 24 subagent runs on
`KartState::updateCollisions` (Mario Kart Wii matching decomp).

Outputs (in this directory):
  subagents.db   - SQLite: agents / trials / regalloc / findings / rules
                   + FTS5 tables (fts_trials, fts_findings, fts_agents)
  agents.jsonl   - one JSON object per subagent
  trials.jsonl   - one JSON object per measured trial
  regalloc.jsonl - one JSON object per (build, variable) regalloc observation

This script also MERGES any `extra_*.jsonl` files written by
`tools/run_and_log.py` (the ETL harness) so that rows added to the live DB
after generation are not lost when the DB is rebuilt:
  extra_agents.jsonl / extra_trials.jsonl / extra_regalloc.jsonl /
  extra_findings.jsonl / extra_rules.jsonl

Design goals for downstream tools:
  * every trial has a normalized `category`, a numeric `score` + `delta`, a
    machine-comparable `registers` tuple "pe/v28/proxy/pool", and free-text
    `edit_from`/`edit_to` that FTS can index.
  * every finding carries `kind` (rule|mechanism|gotcha|conclusion) + evidence.
  * `regalloc` rows let a tool reconstruct a build's colouring exactly.

Run:  python build_db.py
"""
import json
import os
import sqlite3

HERE = os.path.dirname(os.path.abspath(__file__))

# ---------------------------------------------------------------- agents
# (agent_id, round, angle, model, status, best_score, beat_base, summary, key_finding)
AGENTS = [
    ("R1-1", "R1", "source-form enumeration", "general (deepseek-flash)", "completed", 86.9928, 0,
     "~120 spellings of proxy/pproxy + 432 structural x type combos.",
     "Baseline (proxy=r30,pe=r28,v28=r26) is a fixed point; movers only regress."),
    ("R1-2", "R1", "permuter at scale", "general (deepseek-flash)", "completed", 93.4368, 1,
     "~28,000 candidate compile+objdiff via the engines.",
     "WIN: proxyF=proxy lifetime split + var_r28 mask form => 93.4368 (+6.44)."),
    ("R1-3", "R1", "mwcc-debugger PCode", "general (deepseek-flash)", "completed", 84.6062, 0,
     "Dumped PCode per pass; located the coalescing instruction.",
     "&proxy forces a stack home; memory-reference-rewrite promotes it via `mr r385,r92` -> r92+r385 coalesce (fCoalescedInto, deg 283)."),
    ("R1-4", "R1", "idiom mining (in-repo)", "general (deepseek-flash)", "completed", 89.7375, 1,
     "Found KartSusPhysics::setInitialState (100%) uses split per-region locals.",
     "Applying a 2nd proxy local (proxy2) => 89.7375."),
    ("R1-5", "R1", "degree / neighbour model", "general (deepseek-flash)", "completed", 86.9928, 0,
     "Parsed interference graph degrees + priority order.",
     "Priority is NOT degree-driven; order ~ descending vreg id. Degree edits don't move saved regs."),
    ("R2-A", "R2", "split pe's lifetime", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Split pe like proxy (peF=pe at many points).",
     "Fails: pe is not address-taken, every peF=pe copy coalesces away (byte-identical)."),
    ("R2-B", "R2", "fix var_r28", "general (deepseek-flash)", "completed", 93.4368, 0,
     "var_r28 expr/type/liveness variants.",
     "No gain; the earlier 'var_r28->r0' was a dead duplicate node; live value is an anon temp at r30."),
    ("R2-C", "R2", "permuter ~51k", "general (deepseek-flash)", "completed", 93.4368, 0,
     "~51k candidates; 3000 valid declaration permutations.",
     "No gain; pe never lands in r30."),
    ("R2-D", "R2", "debugger on 93.44 build", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Re-dumped regalloc for the 93.44 source.",
     "KEY: colourer walks saved group by DESCENDING vreg id: v143->r31, v94(v28)->r30, v88(pool)->r29, v69(pe)->r28."),
    ("R2-E", "R2", "idiom mining", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Mined more idioms for the two stale vars.",
     "Only r28/r30 swapped; pe(v69) and var_r28(v94) live ranges overlap almost fully."),
    ("META-1", "META", "derive vreg-index rule", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Correlated source edits with resulting vreg indices via controlled variants.",
     "Locals form one contiguous block numbered in REVERSE declaration order (pe=v69 first-declared); temps sit above; pool-pe gap ~19 invariant."),
    ("META-2", "META", "coalescing: proxy vs pe", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Tested the address-taken hypothesis.",
     "Active ingredient is OVERLAPPING live range, not address-taking: proxy used before+after the split line; pe/var_r28/flags0 rematerializable => copies fold."),
    ("META-3", "META", "classify split successes", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Built a (split target, point, address-taken, score, regs) table.",
     "Split recolours IFF non-rematerializable AND copy range not a subset of original; &x is the reliable barrier."),
    ("META-4", "META", "cross-compare dumps", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Normalized (edit -> vreg-table) baseline vs 93.44.",
     "Derived the renumbering rule (local block shifts +/-1; temps above). Predicted edits all <= base."),
    ("META-5", "META", "no-op vs mover mining", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Tabulated 7 register-combos over ~475 mover rows.",
     "Only mover that lifts pe is the var_r28 shift form -> pe=r29, not r30."),
    ("R3-A", "R3", "pe as backend temp", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Remove the pe local; inline direct global indexing / force CSE.",
     "Fails: MWCC rematerializes global addresses (15 uses -> 15 lis); pe lands in caller-saved r4 (64.7)."),
    ("R3-B", "R3", "close 4-instruction gap", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Reconstruct the gameMode/playerIdx block to target (mr r0,r3 + 4x clrlwi; cmpwi r5,3).",
     "Fails: CSE merges all (u8)playerIdx forms into one clrlwi; the only 4x-clrlwi form is a u8 local -> 841 instrs, 91.8%."),
    ("R3-C", "R3", "mine external decomps", "general (deepseek-flash)", "completed", 93.4368, 0,
     "SFA/melee/tww/mkdd/kar for a global-address-in-saved-reg idiom.",
     "Same plain pointer-to-global idiom we already use; none beat 93.4368."),
    ("R3-D", "R3", "alternative pe structures", "general (deepseek-flash)", "completed", 93.4368, 0,
     "reference / array-ref / struct / union / inline getter / #define.",
     "All canonicalize to local v69 or regress (64-93%)."),
    ("R3-E", "R3", "reduce float-temp pool index", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Reduce float temps so the pool's vreg drops below pe.",
     "Disproven: the 18 temps above pe are INTEGER temps; float temps live in the separate FPR space; pool stays v88."),
    ("R4-A", "R4", "re-sweep compilers+flags on new source", "general (deepseek-flash)", "completed", 93.4368, 0,
     "All 28 MWCC builds x ~70 flag combos on the 93.44 source.",
     "Wii/0x4201_127 still best; neutral flags byte-identical; all others regress. No gain."),
    ("R4-B", "R4", "reorder TU context", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Function order / includes / file-scope data around updateCollisions.",
     "Falsified: pe stays vreg 69 in every position; codegen byte-identical."),
    ("R4-C", "R4", "loop/induction form for pe", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Force a base/induction temp for the table via loops.",
     "Disproven: loops fold away or rematerialize pe into a caller-saved reg; never a high-vreg temp."),
    ("R4-D", "R4", "coordinated all-mover search", "general (deepseek-flash)", "cancelled", None, 0,
     "Large combinatorial search over ALL known register-movers at once.",
     "CANCELLED (ran too long); not needed - the residue is proven unreachable."),
    ("R4-E", "R4", "external evidence", "general (deepseek-flash)", "completed", 93.4368, 0,
     "decomp.me scratch, GitHub forks/PRs, m2c, DOL cross-check.",
     "No external attempt exists (decomp.me CF-403; no fork/PR touches it); m2c switch is a false positive; the 4-instr gap = u8 playerIdx + gameMode==3 but regresses."),
    ("E1", "E", "combine split + structural fixes", "general (deepseek-flash)", "completed", 93.4368, 0,
     "23,433 combos of R-SPLIT + structural-slot edits (2-6 edits each).",
     "Nothing beat 93.4368; nothing reached 838 insns or pe=r30."),
    ("E2", "E", "coordinated whole-function vreg rewrite", "general (deepseek-flash)", "cancelled", None, 0,
     "Rewrite updateCollisions so the whole vreg numbering matches the target.",
     "CANCELLED (ran too long)."),
    ("E3", "E", "solver with structural model", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Extended colour_solver.py with the D3 structural constraints (gameMode block, u8 playerIdx, spill/fadds order, instr count).",
     "FULL model (colours+structure) UNSAT; the structural coupling pins pe=v69<pool=v88, closing the pool-as-local escape."),
    ("E4", "E", "autoloop with corrections", "general (deepseek-flash)", "completed", 93.4368, 0,
     "125 candidates; structural candidate pool; private DB copy.",
     "7 candidates reached 838 insns but the size fix is DECOUPLED from the colour swap (still pe=r28); solver UNSAT."),
    ("E5", "E", "cross-function/TU ordering", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Studied the sibling PlayerSub1c_updateFromInput original asm + TU-order.",
     "The sibling holds the data pointer BELOW the pool (r28) = corroborates OUR base, not the target; TU-order is not a lever."),
    ("F1", "F", "proofs -> hypotheses", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Read all 4 proofs; derived + tested ~60 candidates.",
     "All proofs survive; refinements: proof-1 is a sampled induction, and the address-take route lands pe=r20 (not r30)."),
    ("F2", "F", "processes -> hypotheses", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Applied the under-used variants of the process contrasts.",
     "Enriched no-path reproduced; instruction-grain reloc compare ruled out a 'different symbol' escape."),
    ("F3", "F", "Nintendo decomps survey", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Surveyed doldecomp melee/sms/mkdd/ogws/tww + zcanann/SFA-Decomp.",
     "External corroboration: SFA allocation_model declines the reloc-bearing address-materialization class; cross-tier band order anti-predictive."),
    ("F4", "F", "how MK Wii was compiled", "general (deepseek-flash)", "completed", 93.4368, 0,
     "Toolchain/era research via SDK strings + configs.",
     "MK Wii = CodeWarrior for Wii 0x4201_127 (Freescale MWCC 4.2 build 142); no compiler/flag lever."),
     ("F5", "F", "synthesise external x local", "general (deepseek-flash)", "completed", 93.4368, 0,
      "Crossed external evidence with the local proofs.",
      "The target data-above-pool shape exists in 5 other Nintendo target functions, all 0% (no known source)."),
     ("G1", "G", "compiler sweep (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "Re-swept all 28 build/compilers/**/mwcceppc.exe on the 93.44 snapshot (private sub1 workspace).",
      "Wii/0x4201_127 best (93.4368); no build emits pe=r30; target .comment Version 14 matches GC/3.0a3-era but those score 88.07."),
     ("G2", "G", "flag sweep (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "80 optimizer/addressing flag combos on Wii/0x4201_127 (private sub2).",
      "None beat 93.4368; no flag gives pe=r30 (var_r28 alone owns r30); only -O4-preserving flags tie."),
     ("G3", "G", "text permuter (parallel redo)", "general (deepseek-flash)", "cancelled", None, 0,
      "Text-level mutation at scale (private sub3).",
      "CANCELLED (too slow); subsumed by G4/G6."),
     ("G4", "G", "tree-sitter AST permuter (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "~12,100 tree-sitter AST candidates (private sub4).",
      "Nothing beat 93.4368; best = identity edit; pe-web split coalesces (R-SPLIT)."),
     ("G5", "G", "hill-climb permuter (parallel redo)", "general (deepseek-flash)", "cancelled", None, 0,
      "Hill-climb over the lever library, multi-seed (private sub5).",
      "CANCELLED (too slow)."),
     ("G6", "G", "lifetime-split enumeration (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "2,829 exhaustive split combos: every long-lived value x every statement boundary (private sub6).",
      "All tie or fold; zero recolour; pe is rematerializable and pinned below the pool (R-SPLIT/R-VREG-BLOCKS)."),
     ("G7", "G", "source-form enumeration (parallel redo)", "general (deepseek-flash)", "cancelled", None, 0,
      "Declaration/type/qualifier/expression enumeration (private sub7).",
      "CANCELLED (too slow); subsumed by G8/G9 source-edit tests."),
     ("G8", "G", "capstone aligned register-diff (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "Full objdump-aligned diff + vreg<->reg map of updateCollisions (private sub8).",
      "First divergence idx10 (lis r30 vs r28); 23 structural slots (playerIdx mr r0,r3+4x clrlwi, cmpwi r5,3 vs addic., zeroY fp spill) + 38 register-only sites (pe r30<->r28, var_r28 r28<->r30, r12<->r5); no gain."),
     ("G9", "G", "reloc/symbol comparison (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "Instruction-grain relocation + symbol + section comparison (private sub9).",
      "63/63 relocs identical (same type/symbol/addend; only a constant +0x10 shift from the 4 extra insns); .rodata/.data byte-identical; the 'different symbol/data' escape is dead."),
     ("G10", "G", "tool-chain autoloop (parallel redo)", "general (deepseek-flash)", "completed", 93.4368, 0,
      "~969 chained candidates (private sub10 db.sqlite).",
      "Private DB grew 123->733 trials; solver still UNSAT; nothing beat 93.4368."),
     ("CC-RE", "CC", "reverse-engineer mwcceppc.exe vreg numbering + coloring", "general (deepseek-flash)", "completed", 93.4368, 0,
      "Two-agent x86 RE of the compiler to find a patch that reproduces the retail colouring.",
      "No safe minimal patch exists: vreg = one monotonic counter (dense array index); coloring levers are global-only; global candidates don't reproduce retail."),
     ("SH2", "SH", "new source shapes: data-address class (sub-address temp)", "general (deepseek-flash)", "completed", 94.3914, 1,
      "Structural shape search: force the data-table address into a compiler temp instead of a hoisted local.",
      "BROKE THE WALL: 93.4368 -> 94.3914; pe=r30 (target). pe via sub-address temp p3; var_r28/var_r27 first-declared."),
     ("SH1", "SH", "new source shapes: abstraction/inlining", "general (deepseek-flash)", "completed", 93.4368, 0,
      "~3,360 candidates: inline helpers/lambdas/accessors/structs.",
      "Nothing beat 93.4368."),
     ("SH3", "SH", "new source shapes: control-flow/loop/block", "general (deepseek-flash)", "completed", 93.4368, 0,
      "~13,400 candidates: loop forms, nesting/reordering, pragmas.",
      "Nothing beat 93.4368."),
     ("SR1", "SR", "residual structure: playerIdx/gameMode block", "general (deepseek-flash)", "completed", 95.9427, 1,
      "~3,600 candidates on the gameMode/playerIdx block, seeded from 94.3914.",
      "95.9427: s8 playerIdx defeats the cast CSE -> 4x clrlwi + cmpwi + 838 insns (target); + rm before rc."),
     ("SR2", "SR", "residual structure: float/zeroY/spill block", "general (deepseek-flash)", "completed", 94.3914, 0,
      "~2,238 candidates on zeroY/dot/sqrt/spill.",
      "Nothing beat 94.3914."),
     ("SR3", "SR", "residual structure: generalize the winner + combos", "general (deepseek-flash)", "completed", 94.3914, 0,
      "~18,500 candidates generalizing the sub-address trick + combos.",
      "Nothing beat 94.3914."),
     ("T1", "T", "final-push: cast CSE + vtable dispatch", "general (deepseek-flash)", "completed", 97.0167, 1,
      "Attack the last 2 diffs (extsb/mr, vtable temp r5/r12).",
      "97.0167: typed virtual call (vtable temp r12) + u8 playerIdx (extsb gone)."),
     ("T2", "T", "final-push: broad fuzz on the winner", "general (deepseek-flash)", "completed", 97.0167, 1,
      "~22,300 candidates fuzzing decls/types/calls.",
      "Independently reached 97.0167 (mangled extern C redecl + fake vtable class)."),
     ("U1", "U", "final-push: prologue flags block (r5/r6)", "general (deepseek-flash)", "completed", 97.0167, 0,
      "~12,360 candidates on the flags0/reload block.",
      "Nothing beat 97.0167; the r5/r6 tie is allocation-robust."),
     ("U2", "U", "final-push: float/zeroY/spill (inline boundary)", "general (deepseek-flash)", "completed", 97.7327, 1,
      "Rewrote the zeroY dot via an inline helper.",
      "97.7327: inline dotZY helper fixes the two zeroY temps' stack-slot order."),
     ("U3", "U", "final-push: generalize winners + fuzz", "general (deepseek-flash)", "completed", 97.0167, 0,
      "~9,800 candidates generalizing all three winners.",
      "Nothing beat 97.0167."),
     ("V1", "V", "final-push: flags block via inline helpers", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~7,260 candidates: inline-helper boundaries around the flags chain.",
      "Nothing beat 97.7327; r5/r6 tie immutable."),
     ("V2", "V", "final-push: dot/FPR via inline helpers", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~1,030 candidates on the dot-block schedule + FPR naming.",
      "Nothing beat 97.7327."),
     ("V3", "V", "final-push: all four mechanisms + fuzz", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~13,800 candidates combining every known mechanism.",
      "Nothing beat 97.7327."),
     ("W1", "W", "compensate the C1 dot-wrap", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~3,400 candidates; reproduce the C1-wrap and compensate its regressions.",
      "The 'C1-wrap fixes 13' claim was an objdiff index-alignment ILLUSION: it fixes 0 and breaks 17; no gain to compensate."),
     ("W2", "W", "r5/r6 tie via long-lived temp", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~1,086 candidates: sub-address/type tricks on the reload-ptr + mask webs.",
      "Nothing beat 97.7327; the distance-cancel trick does not transpose here."),
     ("X2", "X", "compiler RE: scheduler + FPR pick (route abandoned)", "general (deepseek-flash)", "completed", 97.7327, 0,
      "Sweep the scheduler pipeline models / ties / FPR sort on a compiler copy.",
      "The last diffs are NOT compiler-moveable (RA runs before the scheduler; f5/f2 is an interference-graph difference) -> source-side."),
     ("Y1", "Y", "source shapes: dot/sqrt interference graph", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~2,121 candidates: inline boundaries + temp lifetimes in the dot/sqrt block.",
      "Nothing beat 97.7327."),
     ("Y2", "Y", "source shapes: prologue interference graph", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~10,600 candidates: helpers/sub-address/types on the flags block.",
      "Nothing beat 97.7327; the r5/r6 tie flips only with a volatile (spill) at a loss."),
     ("Y3", "Y", "source shapes: broad interference-graph fuzz", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~21,600 candidates: helpers everywhere + combinations.",
      "Nothing beat 97.7327; helpers move the saved band, not the volatile band."),
     ("Z1", "Z", "idea: allocator steer via asm/barriers", "general (deepseek-flash)", "completed", 97.7327, 0,
      "MWCC inline-asm forms / clobber constraints / register keywords.",
      "Register-mentioning asm emits instructions (mismatch); gcc-style clobbers are accepted but INERT; register/asm(\"r5\") ignored."),
     ("Z2", "Z", "idea: this/self-form rewriting", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~525 candidates routing field accesses through self/this aliases.",
      "Self aliases coalesce to v32; byte-identical."),
     ("Z3", "Z", "idea: accessor / field-access forms", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~200 candidates: raw offsets, refs, widths, private header variants.",
      "Allocation-locked; nothing beat 97.7327."),
     ("Z4", "Z", "idea: whole-TU perturbation", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~300 candidates: dummy globals/functions, function moves, pool shifts.",
      "New float literals shift lfs offsets (worse); base layout already optimal."),
     ("Z5", "Z", "idea: compile-context change", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~560 candidates: -inline/-ipa/-O/pragmas/separate TU/noinline.",
      "All identical or worse; found the allocation depends on the preceding emitted function updateWipe (base is the high state)."),
     ("AY1", "AY", "idiom mining from matched functions", "general (deepseek-flash)", "completed", 97.7327, 0,
      "Mirror the author's idioms from the repo's 100%-matched functions.",
      "Nothing beat 97.7327; the residual is an allocator tie, not an idiom gap."),
     ("AY2", "AY", "per-block reconstruction from target asm", "general (deepseek-flash)", "completed", 97.7327, 0,
      "Rebuild each residual cluster from the retail disassembly, then merge.",
      "Exact cluster causes identified (see finding); nothing beat 97.7327."),
     ("AY3", "AY", "live-range / pressure shaping", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~880 candidates: junk/dead live-range injection + removal.",
      "Nothing beat 97.7327; perturbations move the piece only by breaking matches."),
     ("AY4", "AY", "macro / preprocessor shapes", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~71 candidates: macros for the residual constructs.",
      "Macro-expanded variants collapse to the same token stream; byte-identical."),
     ("AY5", "AY", "fine cross-product of near-miss edits", "general (deepseek-flash)", "completed", 97.7327, 0,
      "~28,000 combos harvested from the DB/probes (pairs->quads).",
      "No interactions; every combo <= 97.7327."),
     ("AS1", "AS", "allocator: scratch-colour order patch", "general (deepseek-flash)", "completed", 98.4487, 1,
      "Function-gated cave forcing v91->r6 so v82->r5 (the r5/r6 tie).",
      "98.4487; whole TU: only updateCollisions changes."),
     ("AS3", "AS", "allocator: FPR colouring patch", "general (deepseek-flash)", "completed", 98.0907, 1,
      "Gated cave forcing temp_f5's node f36->f5.",
      "98.0907; found why f2 was chosen (only {f0,f1,f3,f4} forbidden)."),
     ("AS4", "AS", "allocator: interference graph RE", "general (deepseek-flash)", "completed", 98.8067, 1,
      "Prove/falsify the 'graph must change' hypothesis; per-web remap.",
      "Graph change FALSIFIED (no missing edge; order reversal -> 44.5). Combined GPR+FPR remap -> 98.8067."),
     ("AS5", "AS", "allocator: clean gate + global retest", "general (deepseek-flash)", "completed", 98.8067, 1,
      "Build a clean per-function gate; re-test all global candidates under it.",
      "Clean gate = _copts[0x6D] via -pragma \"report_heap_info on\"; best 98.8067; globals don't beat it."),
     ("SCH", "AS", "scheduler deep-dive (patched compiler)", "general (deepseek-flash)", "completed", 99.1647, 1,
      "Time-boxed RE of the load-store schedule rotation.",
      "No scheduler patch found; alias/model levers proven dead; the 7-insn rotation is a list-scheduling tie-break."),
     ("FPR2", "AS", "the two remaining FPR names", "general (deepseek-flash)", "completed", 99.1647, 1,
      "Force the remaining FPR web colours (v132->f3 fixes both names).",
      "99.1647 (gated); only 7 scheduler instructions remain."),
     ("HY", "HY10", "10 hypotheses (H1-H10) from the full findings/proofs read", "general (deepseek-flash)", "completed", 97.7327, 0,
      "H1 data-table decl, H2 +0x24 read, H3 opt_* pragma sweep, H4 updateWipe interproc, H5 manufacture FPR interference, H6 manufacture GPR interference, H7 type-flip combos, H8 header accessor redefine, H9 global-optimizer view, H10 PCode-scored search.",
      "ALL 10 REFUTED; none beat 97.7327 (~2,000 candidates). New mechanisms recorded in findings."),
     ("S1", "S", "SCALE: token-level exhaustive sweep", "general (deepseek-flash)", "completed", 98.0930, 1,
      "Every single-token edit across the function (type/operator/literal/adjacency).",
      "WIN 98.0930: `(flags0 & 0x60) != 0` -> `!= 1` (semantically identical; mask only 0/0x20/0x40/0x60). Found in the first ~2k of 15.7k."),
     ("S10", "S", "SCALE: byte/instruction-distance hill-climb", "general (deepseek-flash)", "completed", 98.4487, 1,
      "A smoother distance (mnemonic+operand-field mismatch) than objdiff%.",
      "WIN 98.4487: swap the flags-block accessors (read via kartStateReload, write via kartState) -> fixes the r5/r6 tie FROM SOURCE."),
     ("S-rest", "S", "SCALE: block perms / edit-pool cross / evolution / type-matrix / flag-cross / pragma-cross / differential-oracle / grammar search", "general (deepseek-flash)", "completed", 97.7327, 0,
      "8 scale searches (S2-S9): ~2k-48k candidates each.",
      "None beat 97.7327 individually, BUT the set proves the space is NOT exhausted (S1/S10 found wins) and the two wins are in the flags block."),
     ("S2", "S", "follow-up 3-step: full token sweep + 3 hill-climb restarts", "general (deepseek-flash)", "completed", 98.4487, 0,
      "(1) complete the 15.5k token sweep; (2) steepest-descent byte-distance hill-climb; (3) simulated-annealing restarts; (4) dot-block distance search.",
      "Nothing beat 98.4487 (~45k candidates). 98.4487 is the new plateau; the distance metric proved imperfect (lower-distance variants scored LOWER objdiff)."),
     ("D4", "D", "RE-RUN SR2 (float/zeroY/spill) at the new 98.4487 base", "general (deepseek-flash)", "completed", 98.6873, 1,
      "~553 candidates re-running the SR2 dot/sqrt space at the new base.",
      "WIN 98.6873: dotZY body with named locals (`zb=b, za=a; za.y=0; zb.y=0; dot(za,zb)`) flips the zeroY temp-copy order to retail."),
     ("D", "D", "RE-RUN 10 attempted techniques at the 98.4487 base (D1-D10)", "general (deepseek-flash)", "completed", 98.6873, 1,
      "D1 equivalence-swap dot region, D2 sub-address dot temps, D3 FPR interference, D4 SR2 relaunch, D5 Y1 relaunch, D6 V2 relaunch, D7 updateWipe relaunch, D8 flag/pragma x dot-shape, D9 differential oracle, D10 PCode search.",
      "D4 WON (98.6873); the other 9 plateaued at 98.4487. Lesson: RE-RUNNING an old search at the NEW base works - the SR2 float search failed at 94.39 and won at 98.4487."),
     ("E", "E", "10 more collision searches at the 98.6873 base (E1-E10)", "general (deepseek-flash)", "completed", 98.6873, 0,
      "token sweep, hill-climb, SA, dot/zeroY exhaustive, combination search, equivalence/sub-address, FPR push, block reconstruction, grammar+edit-pool, whole-function structural.",
      "NO legitimate win. E1 found a FAKEMATCH (98.6889, behaviour-changing); E2-E10 all plateaued at 98.6873 (~55k candidates)."),
     ("F6", "F", "token sweep with equivalence gate", "general (deepseek-flash)", "completed", 98.6873, 0,
      "~34.5k single-token + whole-function edits at 98.6873.",
      "3 above-base hits, ALL fakematches (changed cmp constant / added cast / changed memory effect) - all rejected by the gate."),
     ("F7", "F", "byte-distance hill-climb", "general (deepseek-flash)", "completed", 98.6873, 0,
      "~6.4k evals, steepest descent + restarts (dist 22 at base).",
      "Nothing beat 98.6873."),
     ("F8", "F", "named-local generalisation (D4 mechanism)", "general (deepseek-flash)", "cancelled", None, 0,
      "Generalise the D4 named-local pattern across the function.",
      "CANCELLED (too long)."),
     ("F9", "F", "exhaustive dotZY body + call site", "general (deepseek-flash)", "completed", 98.6873, 0,
      "~1,320 candidates.",
      "Nothing beat 98.6873; body saturated (all winning forms semantically identical)."),
     ("F10", "F", "FPR f5/f2 push", "general (deepseek-flash)", "completed", 98.6873, 0,
      "~2,650 candidates + one fresh FPR dump.",
      "temp_f5 stays f2; the only shape reaching f5/f4 is a by-value Vector3f copy that costs ~8 insns (91-92%)."),
]

# ---------------------------------------------------------------- trials
# (agent_id, label, category, edit_from, edit_to, score, base, regs, instr_count, notes)
# regs = "pe/v28/proxy/pool"
TRIALS = [
    ("R1-2", "baseline", "reference", "", "", 86.9928, 86.9928, "r30/r26/r30/r29", 838, "pre-split baseline (proxy=r30, v28=r26)"),
    ("R1-2", "proxyF-split", "lifetime-split", "(*pproxy)-> (tail)", "proxyF-> (tail) + KartObjectProxy* proxyF = proxy;", 93.4368, 86.9928, "r28/r30/r26/r29", 834, "THE WIN: split proxy's lifetime"),
    ("R1-2", "v28-mask", "expression", "s32 var_r28 = (flags0 >> 18) & 1;", "s32 var_r28 = (flags0 & 0x40000) != 0;", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "required with proxyF (else 90.45)"),
    ("R1-1", "proxy-plain", "declaration", "KartObjectProxy** pproxy = &proxy;", "proxy-> everywhere (no pproxy)", 84.6062, 86.9928, "r28/r30/r29/-", 834, "removing address-take changes regs, regresses"),
    ("R1-1", "proxy-const", "type", "KartObjectProxy* proxy = mProxy;", "KartObjectProxy* const proxy = mProxy;", 86.9928, 86.9928, "r30/r26/r30/r29", 838, "no effect"),
    ("R1-1", "pproxy-volatile", "type", "KartObjectProxy** pproxy = &proxy;", "KartObjectProxy* volatile* pproxy = &proxy;", 45.89, 86.9928, "-", 834, "big regression"),
    ("R1-1", "proxy-static", "type", "KartObjectProxy* proxy = mProxy;", "static KartObjectProxy* proxy = mProxy;", 55.68, 86.9928, "-", 834, "regression"),
    ("R1-4", "proxy2-split", "lifetime-split", "split proxy at if ((var_r22>0)||(var_r21!=0))", "KartObjectProxy* proxy2=mProxy; pproxy2=&proxy2; tail uses", 89.7375, 86.9928, "r27/r27/r30/-", 834, "second split, weaker"),
    ("R2-A", "peF-split", "lifetime-split", "f32* const pe = lbl_1_data_3918;", "+ f32* const peF = pe; (various points)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no-op: pe copy coalesces away"),
    ("R2-A", "pe-addr", "lifetime-split", "f32* const pe = lbl_1_data_3918;", "f32** ppe = &pe; uses via (*ppe)[k]", 70.5251, 93.4368, "r20/r30/r27/-", 834, "address-taken pe -> destructive"),
    ("R2-B", "v28-shift", "expression", "s32 var_r28 = (flags0 & 0x40000) != 0;", "s32 var_r28 = (flags0 >> 18) & 1;", 90.4535, 93.4368, "r29/r27/r26/r30", 834, "drops v28 below pe but pool takes r30"),
    ("R2-C", "decl-perms", "declaration", "top declaration block", "3000 permutations of A..J locals", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "pe never lands in r30"),
    ("META-1", "add-local-before-pe", "declaration", "(pe first)", "add live local before pe", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "pe stays v69; temps shift +1"),
    ("META-1", "add-30-locals-after-pe", "declaration", "(pe first)", "+30 live locals after pe", 46.2406, 93.4368, "-", 834, "pe vreg rises but pool rises too (gap fixed)"),
    ("META-2", "proxy-no-addr-keep-split", "declaration", "keep proxyF, remove pproxy", "proxyF-> + proxy-> ", 93.4368, 93.4368, "r28/r30/r26/-", 834, "address-taking irrelevant to the win"),
    ("R3-A", "pe-direct-inline", "structure", "f32* const pe = lbl_1_data_3918; + pe[k]", "lbl_1_data_3918[k] inline everywhere", 64.6778, 93.4368, "r4/r30/r26/-", 834, "15 uses -> 15 lis; pe rematerialized to caller-saved"),
    ("R3-B", "pidx-u8", "type", "(s32)playerIdx casts", "u8 playerIdx; pass directly", 91.7955, 93.4368, "r28/r30/r26/r29", 841, "gives 4x clrlwi but overshoots to 841 instrs"),
    ("R3-B", "gameMode-eq3", "expression", "gameMode - 3 == 0", "gameMode == 3", 93.0788, 93.4368, "r28/r30/r26/r29", 834, "cmpwi but value in r0"),
    ("R3-B", "gameMode-9-10", "expression", "!(gameMode!=9 && gameMode!=10)", "gameMode==9 || gameMode==10", 85.9189, 93.4368, "-", 834, "regression"),
    ("R3-C", "external-idiom", "structure", "f32* const pe = lbl_1_data_3918;", "SFA/melee plain-pointer idioms", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "same idiom as ours; no gain"),
    ("R3-D", "pe-arrayref", "type", "f32* const pe = lbl_1_data_3918;", "const f32 (&pe)[4] = lbl_1_data_3918;", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "canonicalizes to local v69"),
    ("R3-D", "pe-define", "structure", "f32* const pe = lbl_1_data_3918;", "#define pe lbl_1_data_3918", 64.6778, 93.4368, "r4/r30/r26/-", 834, "rematerialized"),
    ("R3-E", "float-temp-reduce", "structure", "sqrt/accum float work", "reduce float temps", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "pool vreg invariant (float temps are FPR-space)"),
    ("R4-A", "compiler-sweep", "flag", "Wii/0x4201_127", "all 28 mwcceppc.exe builds", 93.4368, 93.4368, "-", 834, "0x4201_127 best; 1.0RC1/1.0a 92.96; others <=90.9"),
    ("R4-A", "flag-O4s", "flag", "-O4,p", "-O4,s", 93.3194, 93.4368, "-", 834, "slight regression"),
    ("R4-A", "flag-schedule-off", "flag", "-O4,p", "-O4,p -schedule off (after)", 56.6826, 93.4368, "-", 834, "big regression"),
    ("R4-A", "flag-proc750", "flag", "-proc gekko", "-proc 750", 90.9308, 93.4368, "-", 834, "regression"),
    ("R4-B", "tu-reorder", "tu-context", "updateCollisions position", "move UC before ctor/init/...", 92.8401, 93.4368, "r28/r30/r26/r29", 834, "pool-label shift only; pe v69 unchanged"),
    ("R4-C", "loop-pe3", "loop", "pe[3]", "1-trip loop around pe[3]", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "folds away"),
    ("R4-C", "loop-pe17", "loop", "pe+17 uses", "for/while loop over pe+17", 86.3962, 93.4368, "r28/r30/-/-", 834, "pe rematerialized to caller-saved"),
    ("R4-E", "m2c-switch", "structure", "if/else gameMode", "switch(gameMode) {3,9,10}", 76.4916, 93.4368, "-", 834, "m2c false positive; jump table"),
    ("E1", "e1-gm-pidx-combo", "structure", "gameMode-3==0 ; (s32)playerIdx", "gameMode==3 ; u8 playerIdx", 91.9144, 93.4368, "r28/r30/r26/r29", 841, "combined structural; regresses"),
    ("E1", "e1-combo-nogain", "lifetime-split", "2-6 edit combinations", "23,433 combos", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no combination beat the base"),
    ("E3", "e3-full-model-unsat", "structure", "colour model", "colour+structure z3 MODEL 3", 93.4368, 93.4368, "-", 834, "UNSAT: structural coupling closes the pool-as-local escape"),
    ("E4", "e4-838-decoupled", "structure", "u8 playerIdx", "pidx-volatile-u8 (838 insns)", 86.7542, 93.4368, "r28/r30/r26/r29", 838, "reaches 838 insns but colour decoupled (still pe=r28)"),
    ("E5", "e5-sibling-direct", "structure", "pe local", "direct lbl_1_data_3918 reads (sibling idiom)", 64.6778, 93.4368, "r3/r29/-/-", 838, "rematerialized to caller-saved; sibling idiom fails"),
    ("G1", "g1-cc-sweep-redo", "flag", "Wii/0x4201_127", "all 28 builds (parallel sub1)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "0x4201_127 best; no build pe=r30"),
    ("G2", "g2-flag-sweep-redo", "flag", "-O4,p baseline", "80 flag combos (parallel sub2)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no combo beat; none pe=r30"),
    ("G6", "g6-split-exhaustive", "lifetime-split", "every long-lived value x boundary", "2,829 split combos (parallel sub6)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "all fold/tie; zero recolour"),
    ("G8", "g8-align-first-div", "harvest", "(0)", "first divergence = lis r30 vs lis r28 (idx10)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "aligned diff: 23 structural + 38 register-only sites"),
    ("G8", "g8-struct-238", "structure", "u8/volatile playerIdx", "838-insn structural probes", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "structural slots reproduced but colour decoupled (E4)"),
    ("G9", "g9-reloc-identity", "harvest", "target relocs", "our relocs (63/63 identical)", 93.4368, 93.4368, "-", 834, "only +0x10 shift; symbol escape refuted"),
    ("G10", "g10-autoloop-redo", "structure", "expanded pool", "969 candidates (parallel sub10)", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "private DB 123->733 trials; solver UNSAT"),
    ("H6-test", "h6-pe-direct", "structure", "f32* const pe = lbl_1_data_3918;", "reference lbl_1_data_3918 directly (no local)", 64.6778, 93.4368, "r4/r30/r26/-", 834, "rematerialised to caller-saved; H6 refuted"),
    ("H6-test", "h6-pe-addrof0", "declaration", "f32* const pe = lbl_1_data_3918;", "f32* const pe = &lbl_1_data_3918[0];", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "byte-identical"),
    ("I-test", "i1-late-after-reload", "declaration", "pe declared at top", "pe declared after the kartStateReload line", 92.8401, 93.4368, "r28/r30/r26/r29", 834, "worse (I1 refuted)"),
    ("I-test", "i1-nested-block", "declaration", "pe declared at top", "pe inside a nested scope opened after the reload line", 92.8401, 93.4368, "r28/r30/r26/r29", 834, "faithful I1; compiles; worse"),
    ("I-test", "i2-pebox", "structure", "f32* const pe = lbl_1_data_3918;", "struct PeBox{f32* v;} peBox + &peBox", 69.2124, 93.4368, "-", 834, "address-take route; destructive"),
    ("I-test", "i2-ctx", "structure", "pe + proxy separate", "struct Ctx{f32* pe; KartObjectProxy* proxy;} ctx + Ctx* pctx=&ctx", 53.9813, 93.4368, "-", 834, "faithful I2; compiles; destroys codegen"),
    ("J-test", "j1-scoped-peS", "structure", "pe[3] (last use)", "scoped f32* peS + f32** ppeS = &peS around the last use", 92.7208, 93.4368, "r28/r30/r26/r29", 834, "rewrite temp but confined; worse"),
    ("J-test", "j2-opt_common_subs-off", "flag", "(default passes)", "#pragma opt_common_subs off around the function", 57.9572, 93.4368, "-", 834, "= -opt nocse; hurts"),
    ("J-test", "j2-opt_propagation-off", "flag", "(default passes)", "#pragma opt_propagation off", 83.8902, 93.4368, "-", 834, "hurts"),
    ("J-test", "j2-global_optimizer-off", "flag", "(default passes)", "#pragma global_optimizer off", 49.1803, 93.4368, "-", 834, "hurts"),
    ("J-test", "j2-opt_lifetimes-off", "flag", "(default passes)", "#pragma opt_lifetimes off", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no effect"),
    ("K-test", "k1-pooled-alias", "structure", "f32* const pe = lbl_1_data_3918;", "extern const f32* const lbl_1_data_3918_addr = ...; pe=(f32*)addr", 90.9308, 93.4368, "-", 834, "extra load; H-K1 refuted"),
    ("K-test", "k1-const-ptr", "declaration", "f32* const pe = lbl_1_data_3918;", "const f32* const pe = lbl_1_data_3918;", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "byte-identical"),
    ("K-test", "k1-const-array", "declaration", "f32 lbl_1_data_3918[4] = ...;", "const f32 lbl_1_data_3918[4] = ...;", 91.1694, 93.4368, "-", 834, "symbol moves to rodata"),
    ("L1", "l1-gamemode-eq3", "expression", "gameMode - 3 == 0", "gameMode == 3", 93.0788, 93.4368, "r28/r30/r26/r29", 834, "gives cmpwi but gameMode lands in r0"),
    ("L1", "l1-drop-u8-cast", "type", "(rm->raceMode, (u8)playerIdx) x4", "(rm->raceMode, playerIdx) x4", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "byte-identical (frontend CSEs the conversion)"),
    ("L1", "l1-perbranch-u8", "type", "(u8)playerIdx at 2 calls", "u8 p8=(u8)playerIdx; ... p8 per branch", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no-op (locals folded)"),
    ("L1", "l1-pidx-u8-var", "type", "s32 playerIdx = getPlayerIdx()", "u8 playerIdx = getPlayerIdx()", 91.7955, 93.4368, "-", 838, "only form with 4x clrlwi; overshoots +4 insns"),
    ("L1", "l1-decl-reorder", "declaration", "playerIdx; rc; rm", "rc; rm; playerIdx", 91.6468, 93.4368, "-", 834, "destructive"),
    ("L1", "l1-else-if-eq", "expression", "!(gameMode!=9 && gameMode!=10)", "gameMode==9 || gameMode==10", 85.9189, 93.4368, "-", 834, "keep the !(...) form"),
    ("COMBO", "combo-neutral-sweep", "combination", "6 neutral primitives", "all 63 subsets", 93.4368, 93.4368, "r28/r30/r26/r29", 834, "no subset beats the base; neutral edits are confluent"),
    ("SH2", "sh-subaddr-temp", "declaration", "f32* const pe = lbl_1_data_3918; (first local)", "var_r28/var_r27 before pe + pe = (lbl+3)-3", 94.3914, 93.4368, "r30/r28/r26/r29", 834, "BREAKTHROUGH: pe=r30 (target) via sub-address temp; +0.9546"),
    ("SR1", "sr-s8-pidx", "type", "s32 playerIdx = proxyF->getPlayerIdx();", "s8 playerIdx = proxyF->getPlayerIdx();", 95.9427, 94.3914, "r30/r28/r26/r29", 838, "4x clrlwi + cmpwi + 838 insns; colouring kept; +1.5513"),
    ("SR1", "sr-rm-before-rc", "declaration", "rc; rm", "rm; rc", 95.9427, 94.3914, "r30/r28/r26/r29", 838, "required with s8"),
    ("T1", "t-typed-vcall", "structure", "(*(void***)rm->raceMode)[0x38/4]...) call", "((__KMVT*)rm->raceMode)->f12((u8)playerIdx)", 97.0167, 95.9427, "r30/r28/r26/r29", 838, "vtable temp r12; +1.0740"),
    ("T1", "t-u8-pidx", "type", "s8 playerIdx", "u8 playerIdx", 97.0167, 95.9427, "r30/r28/r26/r29", 838, "removes the leftover extsb; keeps 4x clrlwi"),
    ("U2", "u-dotzy-helper", "structure", "EGG::Vector3f::dot(zeroY(ci.wallNrm), zeroY(sp20))", "dotZY(ci.wallNrm, sp20) via an inline helper", 97.7327, 97.0167, "r30/r28/r26/r29", 838, "zeroY temps lay out retail order; +0.7160"),
    ("S10", "s10-accessor-swap", "structure", "flags0 = kartState()->field(0); reload &= mask;", "flags0 = kartStateReload()->field(0); kartState() &= mask;", 98.4487, 97.7327, "r30/r28/r26/r29", 838, "fixes the r5/r6 prologue tie FROM SOURCE; +0.7160"),
    ("S1", "s1-token-ne1", "expression", "var_r27 = (flags0 & 0x60) != 0;", "var_r27 = (flags0 & 0x60) != 1;", 98.0930, 97.7327, "r30/r28/r26/r29", 838, "FAKEMATCH: differs at mask==0 (0!=0 false vs 0!=1 true); NOT landed"),
    ("D4", "d4-dotzy-named-locals", "structure", "dotZY: return EGG::Vector3f::dot(zeroY(a), zeroY(b));", "dotZY: zb=b, za=a; za.y=0; zb.y=0; return EGG::Vector3f::dot(za, zb);", 98.6873, 98.4487, "r30/r28/r26/r29", 838, "flips the zeroY temp-copy order to retail; +0.2386"),
]

# ---------------------------------------------------------------- regalloc
# (build_id, source, name, vreg, degree, reg, flags)
REGALLOC = [
    ("base86", "baseline 86.99 (no proxyF, v28 shift)", "proxy", 92, 283, "r30", "fCoalescedInto proxy'385"),
    ("base86", "baseline 86.99", "pe", 68, 257, "r28", ""),
    ("base86", "baseline 86.99", "var_r28", 63, 245, "r26", ""),
    ("base86", "baseline 86.99", "pool(lbl_1_rodata_27D0)", 89, 276, "r29", "temp"),
    ("base86", "baseline 86.99", "this", 32, 282, "r20", ""),
    ("base86", "baseline 86.99", "var_r27", 62, 93, "r27", ""),
    ("base93", "93.44 (proxyF split + v28 mask)", "proxyF", 62, 283, "r26", "the new web"),
    ("base93", "93.44", "pe", 69, 257, "r28", "declared local, first-declared => v69"),
    ("base93", "93.44", "var_r28", 94, 245, "r30", "anon live node (temp)"),
    ("base93", "93.44", "pool(lbl_1_rodata_27D0)", 88, 276, "r29", "temp; pool-pe gap ~19 invariant"),
    ("base93", "93.44", "this", 32, 282, "r20", ""),
    ("base93", "93.44", "wheel temp", 85, 24, "r31", ""),
    ("base93", "93.44", "var_r27", 63, 93, "r27", ""),
    ("coalesce", "proxy coalescing origin", "r92 & r385", 92, 283, "r30", "memory-reference-rewrite emits `mr r385,r92` from &proxy; r92+r385 coalesce"),
]

# ---------------------------------------------------------------- findings
# (agent_id, kind, statement, evidence)
FINDINGS = [
    ("R1-2", "result", "proxyF lifetime split + var_r28 mask form: 86.993 -> 93.4368 (+6.44).", "proxyF->r26 now matches target; 109->86 mismatching insns."),
    ("R1-3", "mechanism", "MWCC coalesces proxy via `mr r385,r92` created in memory-reference-rewrite when proxy is address-taken (&proxy).", "backend-12-after-memory-reference-rewrite.txt; regalloc-gpr-pass-1-all.txt fCoalescedInto."),
    ("R1-5", "mechanism", "Regalloc priority is not degree-driven.", "degree edits (adding neighbours) do not move saved registers."),
    ("R2-D", "rule", "The colourer assigns the saved-register group by DESCENDING vreg id (r31,r30,r29,...).", "assigned order v143->r31, v94->r30, v88->r29, v69(pe)->r28."),
    ("META-1", "rule", "Declared locals form one contiguous vreg block numbered in reverse declaration order; compiler temps are numbered above the whole block.", "pe = first-declared local = v69; adding a local shifts the block (+/-1); pool sits ~19 temps above."),
    ("META-1", "consequence", "A first-declared local (pe) can never out-rank a compiler temp (the pool) by reordering; pool-pe gap ~19 is invariant.", "add-local-before-pe and add-30-locals-after-pe both preserve the gap."),
    ("META-2", "rule", "A lifetime split recolours iff the value is non-rematerializable AND the copy's live range is not a subset of the original.", "proxy (used before+after the split) splits; pe/var_r28/flags0 (rematerializable) fold."),
    ("META-2", "mechanism", "Address-taking is not the active ingredient; overlapping live range is (address-taking is just a reliable way to force it).", "keeping proxyF and removing pproxy still scores 93.4368."),
    ("META-2", "gotcha", "Forcing the target colours via &pe DOES yield pe=r30 but collapses surrounding codegen to ~63%.", "pe-addr trial: 70.5; pe2at@collide: 63.4."),
    ("R3-A", "mechanism", "MWCC rematerializes constant global addresses; removing the pe local yields per-use lis + caller-saved register.", "pe-direct-inline: 15 uses -> 15 lis, pe in r4, 64.7%."),
    ("R3-B", "mechanism", "The 4-instruction size gap is the gameMode/playerIdx block; CSE merges all (u8)playerIdx forms into one clrlwi.", "only u8 playerIdx gives 4x clrlwi but overshoots to 841 instrs (91.8%)."),
    ("R3-E", "mechanism", "The pool's vreg index is invariant to float-temp edits; the 18 temps above pe are integer temps (float temps are FPR-space).", "pool stays v88 in every dump."),
    ("R4-A", "consequence", "The compiler/flag axis is exhausted: 28 compilers x ~70 flags; none beat 93.4368.", "Wii/0x4201_127 best; neutral flags byte-identical."),
    ("R4-B", "consequence", "TU context does not affect the function's vreg numbering.", "moving updateCollisions changes only pool @label; pe stays v69."),
    ("R4-C", "consequence", "Loops cannot create a long-lived high-vreg base temp for pe on this build.", "loop forms fold or rematerialize; pe never > pool vreg."),
    ("R4-E", "consequence", "No external/original source for updateCollisions exists to learn from.", "decomp.me CF-403; no doldecomp/mkw fork or PR touches the function."),
    ("R4-E", "consequence", "The target's pe=r30 / var_r28=r28 is a frontend vreg-numbering artefact requiring pe as a backend temp created after the pool.", "all 24 agents + debugger converge; no source form reaches it."),
    ("D3", "gotcha", "CORRECTION: the residual is NOT register-only. There are ~14 structural instruction slots (3 extra clrlwi, addic.<->cmpwi for gameMode, a spill/stack-slot reorder, an fadds reorder) on top of the pe/var_r28 colour swap; harvest_methods[10]'s 'register-only' and proof-3's framing are false.", "mnemonic-aligned objdump diff: 834 (ours) vs 838 (target) instructions."),
    ("D3", "rule", "R-COLOR-ORDER (descending vreg -> descending saved reg) holds only for the OVERLAPPING live-across group; non-overlapping webs reuse the highest free register (v85->r31 while v94->r30).", "base93 regalloc dump."),
    ("D3", "gotcha", "F12/R3-E overstated: the pool vreg is 89 at base86 and 88 at base93 (a per-build temp, not a cross-build invariant).", "regalloc dumps base86 vs base93."),
    ("D2", "mechanism", "Each UNSAT assumption is individually necessary (relaxing pe-origin-local, pe-rematerializable, or pool-is-temp flips UNSAT->SAT in z3), but the model over-approximates: a non-rematerializable pe PLUS a split still leaves pe=r28 (92.96), so the true unstated requirement is a genuinely INDEPENDENT split web (address-taking, destructive).", "colour_solver relaxations + the k-series source tests."),
    ("D5", "result", "autoloop: 4 rounds x 20 candidates chaining retrieval->run_and_log->graph->solver; targeted the 7 novel mechanism x node combos; added 69 trials + 326 regalloc rows; independently reproduced UNSAT; target colour state never reached; nothing beat 93.4368.", "subagent_data/tools/autoloop.py + autoloop_last_run.json."),
    ("E1", "consequence", "Combining the R-SPLIT lever with the structural-slot edits (23,433 combinations of 2-6 edits) never beats 93.4368 and never reaches 838 insns or pe=r30.", "E1 exhaustive combination search (15,044 scored)."),
    ("E3", "mechanism", "The FULL target (colours + structure) is UNSAT: the structural coupling pins pe first-declared v69 < pool v88, closing the previously 'breakable' pool-as-local escape; the structural closure additionally needs a -3-instruction compensation no known lever provides (the only 4x-clrlwi lever costs +7).", "colour_solver.py MODEL 3 + structural closure (z3)."),
    ("E4", "mechanism", "The 838-instruction size fix is DECOUPLED from the pe/var_r28 colour swap: 7 candidates reached 838 insns while keeping pe=r28, and the nearest colouring stayed pe=r29.", "autoloop corrected run (125 candidates, structural pool)."),
    ("E5", "mechanism", "The sibling PlayerSub1c_updateFromInput holds the data pointer BELOW the pool (r28, pool r31) - i.e. it corroborates OUR base, not the target; the target (pe above pool) is the inverted case, so no sibling idiom is missing.", "original .s prologue of the sibling."),
    ("E5", "consequence", "TU-order/context is not a lever: moving updateCollisions within the TU leaves pe=v69/r28 unchanged.", "E5 TU-order tests."),
    ("F3", "mechanism", "SFA-Decomp's docs/allocation_model.md independently finds cross-tier saved-band order above width 4 anti-predictive (below chance) and its model explicitly DECLINES the reloc-bearing address-materialization class - exactly our pe.", "zcanann/SFA-Decomp docs/allocation_model.md."),
    ("F4", "result", "MK Wii was built with CodeWarrior for Wii 0x4201_127 (Freescale MWCC 4.2 build 142), confirmed by the game's own libs embedding '(0x4201_127)'; links RVL_SDK/NW4R/EGG/MSL/DWC. Nintendo-specific only in the patched SDK distribution, not the compiler core.", "lib/rfl/rfl_init.c + lib/nw4r strings; build/compilers/info.txt."),
    ("F4", "gotcha", "The target object's .comment shows Version 14 while our MWCC 0x4201_127 emits Version 15; the decomp config sets mw_comment_version:14 (dtk writes it into the split objects). Metadata only - it does not fingerprint the compiler or affect codegen/matching.", "config/RMCP01/config.yml; dtk elf info on both objects."),
    ("F5", "result", "The target's data-ptr(r30)-above-rodata-pool(r29) shape appears in 5 other Nintendo target functions, all 0% (no known source) - so no sibling idiom teaches it.", "_scanpat.py + objdiff."),
    ("F1", "gotcha", "The destructive address-take route lands pe=r20 (caller-saved), NOT pe=r30 - correcting findings[9].", "F1 objdump register extraction."),
    ("G8", "result", "Exact register/structural map: first divergence idx10 (lis r30 vs lis r28); 23 structural slots (playerIdx `mr r0,r3` + 4x clrlwi per call vs one hoisted clrlwi; cmpwi r5,3 vs addic. r0,r5,-3; zeroY fp spill-slot schedule) + 38 register-only sites (pe r30<->r28, var_r28 r28<->r30, r12<->r5).", "G8 objdump-aligned static diff (align.py)."),
    ("G9", "result", "updateCollisions relocations are identical (63/63, same type/symbol/addend); the only deviation is a constant +0x10 offset shift from the 4 extra instructions. .rodata/.data byte-identical. The 'target references a different symbol/data object' escape is dead.", "G9 instruction-grain reloc/symbol/section comparison."),
    ("G6", "result", "Exhaustive lifetime-split enumeration (2,829 combos: every long-lived value x every statement boundary, plus merge/reverse variants) recolours nothing; every split folds or ties. Consistent with R-SPLIT (pe is rematerializable) + R-VREG-BLOCKS (pe pinned below the pool).", "G6 private-sub6 exhaustive enumeration."),
    ("G10", "result", "Parallel autoloop redo: ~969 chained candidates; private DB grew 123->733 trials / 37->71 findings (~6x); refine_db still reports {target_reachable: false, solver_status: 'unsat'}; nothing beat 93.4368.", "G10 private-sub10 db.sqlite + refine_db."),
    ("H6-test", "consequence", "H6's lever is REFUTED: making pe a body-level address temp by dropping the local and referencing lbl_1_data_3918 directly rematerialises it to a caller-saved register (64.6778, = the old R3-A result); every form that keeps a local (&lbl_1_data_3918[0], non-const, casts, addrof) is byte-identical to the base (93.4368); volatile regresses to 59.43. No source form changes the pe/var_r28 colouring, so H4's live-range variant collapses into the same wall.", "probe_h6.py: 12 forms; direct/castptr/ptrarith=64.6778, addrof0/nonconst/castc/addrof0cast=93.4368, volatile=59.4272."),
    ("I-test", "consequence", "I1 and I2 hypotheses REFUTED with faithful implementations: I1 (declare pe inside a nested scope opened after the kartStateReload line, so its vreg is issued after those temps) scores 92.8401; I2 (one aggregate `struct Ctx{f32* pe; KartObjectProxy* proxy;} ctx={lbl_1_data_3918,proxy}; Ctx* pctx=&ctx;` with all uses via pctx->) compiles and scores 53.9813 - taking the aggregate's address destroys codegen, exactly as R-SPLIT predicts. Declaring pe later (after proxyF) is 86.40. No form moves the pe/var_r28 colouring.", "probe_i.py (I1 nested block, compiles) + i2build.py/i2score.py (I2 aggregate, compiles) : 92.8401 / 53.9813; probe_h6b.py: 86.3962."),
    ("J-test", "consequence", "J1 and J2 hypotheses REFUTED: J1 (scoped alias of pe at the last use only, to force a memory-reference-rewrite temp with a confined stack home) scores 92.7208; J2 (#pragma opt_* off around updateCollisions) gives opt_common_subs off=57.9572 (identical to -opt nocse), opt_propagation off=83.8902, global_optimizer off=49.1803, and opt_lifetimes/opt_usedef_mem_limit off=93.4368 (pragma accepted, no effect). No lever moves the colouring.", "probe_j.py: J1-scoped-peS=92.7208; J2 pragmas 93.4368/93.4368/83.8902/57.9572/49.1803."),
    ("K-test", "consequence", "H-K1 (pool the pe ADDRESS via a const alias object) REFUTED: the pooled-alias form scores 90.9308 (extra load), a const pointer-to-const local is byte-identical (93.4368), making the array itself const moves the symbol (91.1694 = K1's own 91.17), a static address alias is 92.9594. Nothing promotes pe into the compiler-temp class.", "probe_k.py: K1-pooled-alias=90.9308, K1-const-ptr=93.4368, K1-const-array=91.1694, K1-static-alias=92.9594."),
    ("L1", "result", "Kinoko deep-dive: it is a clean semantic REIMPLEMENTATION, not a matching decomp, and it OMITS the playerIdx/gameMode block entirely (models the whole wall-collision-start action as action()->start(UNK_1)); every collision-loop construct it has is already ours, and where they differ the target asm agrees with ours. It has zero regalloc/vreg annotations, so it cannot supply the structure for the 2 structural slots.", "vabold/Kinoko source/game/kart/KartState.cc:177-246; target KartState.s:705-1021."),
    ("L1", "mechanism", "The residual is 4 clusters with ONE coupled cause: our hoisted `clrlwi r4,r3,24` consumes r3->r4, cascading rc->r6, gameMode->r0, battleType->r4, vtable->r5; the target re-truncates per call so rc=r4, gameMode=r5, battleType=r4, raw playerIdx=r0, vtable=**r12**. Fixing the hoist would fall all downstream registers into place, but no source spelling stops the frontend from CSE-ing the conversion.", "L1 aligned diff (build/RMCP01/StaticR/asm/kart/KartState.s:955-1012) + E1-E5 measurements."),
    ("CC-RE", "mechanism", "mwcceppc.exe vreg numbering (x86 RE): one monotonic per-class counter `_used_virtual_registers[4]` at RVA 0x358358 seeded to 32 (=the 32 physical GPRs). Declared locals are minted in one early pass (`_CodeGen_Generator` calls 0x6D8A0 -> `_assign_register_by_type` 0x190CB0 -> `_assign_register_to_variable` 0x1B17C0) walking _arguments then _locals, so the first-declared local is the HIGHEST local number (pe=v69); every compiler temp is minted from the SAME counter after `_open_temp_registers` (0x1B14B0), hence necessarily > 69 (pool=v88). There is NO constant separating a local base from a temp base.", "RE of build/compilers/Wii/0x4201_127/mwcceppc.exe via the derived row + CodeView symtab (NB11, 5708 names)."),
    ("CC-RE", "mechanism", "mwcceppc.exe saved-register coloring (x86 RE): class 4=GPR, saved regs 14..31. `_init_target_registers` (0x191290) builds the nonvolatile list in DESCENDING order from the threshold table at RVA 0x2db87e (GPR=0x1f); `_obtain_nonvolatile_register` (0x1b14f0) hands them out in that order via `_colorinstructions`'s retry block (0x1b43bf..0x1b4446), so successive webs needing a saved reg get r31,r30,r29,r28... in *processing order*. `_machine_specific_sort_graph` (0x18e5d0) sorts on `node+0x1a`, which is never written -> the sort is a no-op, so order = list order (descending vreg) with the spill-cost heuristic degenerating to ties.", "RE of mwcceppc.exe colorinstructions/Registers; validated vs build/mwcc-debug/dumps/regalloc-gpr-pass-1-all.txt."),
    ("CC-RE", "consequence", "NO safe minimal binary patch reproduces the retail colouring: (a) bumping a local's vreg is a no-op (the next temp mints above it from the same counter) or OOB (vreg indexes dense `used`-sized arrays in `_buildinterferencegraph` 0x2386F0 / `_set_vr_reg_flags` 0x6B660); (b) deferring the local = the R3-A rematerialisation (64.68); (c) the coloring order levers are global (class index / target option byte / function ptr), with no per-function gate short of a code-cave; (d) empirically, the colour tie-break flip (RVA 0x1b4634 jne->je) had NO effect (93.4368). This independently reproduces the project's P-PROOF-UNSAT / measurement-invariance result from the compiler's own internals.", "Two-agent x86 RE + patch_and_test.py on a COPY of the compiler."),
    ("COMBO", "consequence", "User hypothesis (combine individually-neutral edits) tested exhaustively: all 63 subsets of 6 distinct neutral primitives (pe = &lbl_1_data_3918[0], drop (u8) casts, #pragma opt_lifetimes off, #pragma opt_usedef_mem_limit off, pe-split at pe[3], gameMode == 3) were compiled. Every subset WITHOUT the gameMode edit = 93.4368 (byte-neutral); every subset WITH it = 93.0788. No combination beats the base. Theoretical reason: if compile(E(S))==compile(S) the frontend has already reduced E(S) to the same IR, so neutral edits are confluent and cannot compose to a change.", "combo_neutral.py (63 combos + baseline) against the same SB baseline; consistent with the 72 already-recorded neutral/combination trials."),
    ("SH2", "result", "BREAKTHROUGH 93.4368 -> 94.3914 (+0.95): the pe/var_r28 colouring now MATCHES retail exactly (pe=r30, pool=r29, var_r28=r28, var_r27=r27; target was pe=r30/var_r28=r28). Winning shape: declare var_r28/var_r27 BEFORE pe (so they are the first-declared locals and mint the high local vregs -> r28/r27), and derive the data address through a sub-address temp `f32* const p3 = lbl_1_data_3918 + 3; f32* const pe = p3 - 3;`, assigning var_r28/var_r27 from flags0 AFTER their declarations.", "sub7/best_94_3914.cpp; verified on the real source: objdiff 94.3914; prologue lis r30 (pe), lis r29 (pool), rlwinm r28 (var_r28)."),
    ("SH2", "mechanism", "Why the sub-address works: `p3 = lbl + 3; pe = p3 - 3` keeps ONE live web (no rematerialisation) while making `pe` a compiler-generated TEMP rather than a declared local, so it is numbered above the rodata pool and out-ranks it for r30. This is precisely the escape the compiler RE (CC) and the no-path/UNSAT proofs had ruled out — they all assumed `pe` stayed a declared local (R-VREG-BLOCKS). Declaring var_r28/var_r27 first additionally re-numbers the locals so var_r28 lands on r28.", "sub7 mechanism + CC-RE counterexample; the 'locals are always below temps' premise was breakable by making pe not a local."),
    ("SR1", "result", "SECOND WIN 94.3914 -> 95.9427 (+1.55): `s8 playerIdx` (signed char, was s32) prevents the frontend CSE of the (u8) cast, so MWCC emits the retail **4x `clrlwi r4,r0,24` per call** with the raw playerIdx in r0, uses **`cmpwi r5,3`**, frees r4 for RaceConfig*, and reaches **838 instructions (= target)** while KEEPING the pe=r30 colouring. Also: declare `RaceManager* rm` before `RaceConfig* rc`.", "sub6/best_7_s8_pirmrcgm.cpp; real-source objdiff 95.9427, 838 insns, lis r30=pe."),
    ("SR1", "mechanism", "Why s8 works where every s32 spelling failed: forcing a signed-char local makes MWCC keep a sign-extension at each conversion, so the (u8) truncation cannot be hoisted/CSE'd into one `clrlwi` — reproducing retail's per-call truncations. (It costs `extsb r0,r3` where retail has `mr r0,r3`.) This is the first time the frontend CSE was defeated from source.", "sub6 type sweep ~2,600 candidates; only s8/char forms change the clrlwi count."),
    ("SR2", "consequence", "The float/zeroY/spill block is unreachable from the probed source space: no expression/temporary/reference/ctor/paren/cast/decl reordering produces the retail signature (wallNrm->sp8, sp20->sp14 with sp20 evaluated first); the 'first-evaluated temp gets the lower slot' coupling held in every form tried. Best stayed 94.3914.", "sub7 ~2,238 candidates."),
    ("SR3", "consequence", "Generalizing the sub-address trick is score-neutral: p3 offsets 1-32, pe distances 0-32, derivation chains (len 1-9), alternate bases/casts, and the temp-class pattern on proxy/proxyF/flags0/collide/hgp/kdyn/rc/rm/playerIdx/gameMode/battleType all fold back to the same materialised addresses (94.3914). The residual is one coupled cascade.", "sub8 ~18,500 candidates."),
    ("T1", "result", "THIRD WIN 95.9427 -> 97.0167 (+1.07): the two residual diffs were ONE cause — the manual vtable indexing `(*(void***)rm->raceMode)[0x38/4]` lowers to a plain array load using r5, whereas retail's `lwz r12,0(r3); lwz r12,off(r12)` is MWCC's standard VIRTUAL-CALL sequence. Rewriting both arms as real virtual calls (a typed class with the right slots: f12=0x38, f11=0x34) makes the vtable temp r12. Combined with `u8 playerIdx` (drops the leftover extsb while keeping the 4x clrlwi) -> 97.0167, 838 insns.", "sub9/best_97_0167.cpp; real-source objdiff 97.0167, 838 insns."),
    ("T1", "mechanism", "Lever: `*(void***)` vtable indexing allocates a scratch GPR (r5); a real virtual call uses r12. (T2 independently reached the same 97.0167 via an extern \"C\" mangled redecl + a fake vtable class.) Remaining ~3%: r5/r6 swaps in the flags block + sp20/sqrt stack-slot scheduling + FPR naming.", "sub9 + sub10 winners (identical score)."),
    ("U2", "result", "FOURTH WIN 97.0167 -> 97.7327 (+0.72): wrapping the `EGG::Vector3f::dot(zeroY(ci.wallNrm), zeroY(sp20))` call in an inline helper `static inline f32 dotZY(const Vector3f& a, const Vector3f& b){ return Vector3f::dot(zeroY(a), zeroY(b)); }` and calling `dotZY(ci.wallNrm, sp20)` changes MWCC's temp allocation so the two by-value `zeroY` results lay out in retail order (wallNrm->0x8, sp20->0x14) instead of swapped — fixing 6 instructions. Verified 97.7327.", "sub9/best_97_7327.cpp; real-source objdiff 97.7327, 838 insns."),
    ("U1", "consequence", "The prologue flags-block r5/r6 colour tie (retail `lwz r5,4(r5)`/`rlwinm r6,r7` vs ours `lwz r6,4(r5)`/`rlwinm r5,r7`) is allocation-robust: it survived ~12,360 candidates (statement order, named `KartState*` temps, `u32*/u32&` sub-address temps, proxy/proxyF/*pproxy forms, all bool spellings). U3's ~9,800 further candidates reproduced the same. The residual (~2.3%) is a register-colour tie + a dot-block schedule + FPR f5/f2 naming.", "sub8 + sub10 (U1/U3)."),
    ("W1", "consequence", "PLATEAU at 97.7327 (hard local optimum): 5 further parallel searches (V1/V2/V3 ~22k, W1 ~3.4k, W2 ~1.1k) found nothing. The last 19 mismatched instructions are allocator/scheduler artifacts — the prologue flags-block r5/r6 colour tie, the dot-block store/load schedule, and FPR f5/f2 naming — invariant under every source perturbation tried (inline helpers, sub-address temps, type flips, statement/volatile order, constant algebra). ~60k+ candidates across 7 rounds since 93.4368 moved it 93.4368->94.3914->95.9427->97.0167->97.7327 and then stopped.", "rounds SH/SR/T/U/V/W; sub8/9/10."),
    ("W1", "gotcha", "CORRECTION: the earlier V2 claim that wrapping C1 as `EGG::Vector3f::dot(v, RKSystem_ey)` 'fixes all 13 dot/FPR mismatches' is an objdiff INDEX-ALIGNMENT illusion (the wrap inserts 4 instructions, shifting slot indices). Keyed by target instruction address, the wrap fixes ZERO and breaks 17; the C1 expression already matches retail. Do not pursue it.", "W1 address-keyed diff (sub8/best_sub8_c1wrap_95.2438.cpp)."),
    ("X2", "consequence", "The residual is SOURCE-side, not toolchain: register allocation (`_colorinstructions` 0x1b3fa0) runs BEFORE the scheduler (`_scheduleinstructions` 0x1b6ad0, called at 0x6b325/0x6b3d4); the FPR f5/f2 pick is an interference-graph difference (temp_f5 got f2 because f2 was free there); the FPR sort is inert ([0x74f339]==0). Sweeping all 11 scheduler pipeline models, the colour tie-break byte, and the FPR sort left the score at 97.7327 or worse. So the residual (prologue r5/r6 GPR tie + dot/sqrt schedule + f5/f2) must be closed by a SOURCE shape that changes the PCode/interference graph, not the compiler. (A function-gated scratch-reg swap patch was tried and rejected: non-standard, source-build specific, and it does not reach the 13 either.)", "X on a compiler copy (ccpatch2); determinism + pass-order + model-sweep evidence."),
    ("Y", "consequence", "PLATEAU re-confirmed at 97.7327 after ~34k more source-shape candidates (Y1 dot/sqrt ~2.1k, Y2 prologue ~10.6k, Y3 broad ~21.6k), all inline-boundary/temp-lifetime/interference-graph oriented. New datum: the prologue r5/r6 tie IS an interference-graph artifact and IS movable - but only by materialising the reload pointer (`KartState* volatile rl`), which forces a 2-instruction stack spill (840 insns) and drops to 91.3%. Non-volatile shapes do not flip it. Mechanism-4 inline helpers move the SAVED-register band (r28/r30), not the volatile band; the dot/sqrt schedule + FPR f5/f2 are invariant under every shape tried. Net: ~100k+ candidates across rounds SH..Y moved updateCollisions 93.4368 -> 97.7327 and nothing since; the last 19 instructions are a hard local optimum.", "rounds Y1/Y2/Y3; sub8/9/10."),
    ("Z", "consequence", "All five NEW attack classes plateaued at 97.7327 (~1,900 candidates): Z1 - MWCC inline asm that mentions a register EMITS that instruction (a mismatch), and gcc_extensions clobber/operand constraints are accepted but INERT; `register`/`asm(\"r5\")` are ignored. Z2 - `this`/self aliases coalesce to v32 (byte-identical). Z3 - accessor IR shape is allocation-locked. Z4 - adding float literals shifts the shared pool (lfs offsets, worse); the current layout is already optimal. Z5 - every compile context (-inline/-ipa/-O/pragmas/separate TU/noinline) is identical or worse. Z5 did find that updateCollisions' allocation depends on the preceding EMITTED function `updateWipe` (removing/moving it drops to 97.0167), but the base arrangement is already the high state. Conclusion: the last 19 instructions are not reachable from source under MWCC 0x4201_127.", "round Z1-Z5; sub1-5."),
    ("AY", "consequence", "Five more NEW classes plateaued at 97.7327 (~30k candidates): AY1 idiom-mining from the repo's 100%-matched functions (the residual is an allocator tie, not an idiom gap); AY2 per-cluster reconstruction from the retail asm (exact causes identified - GPR r5/r6 tie, FPR f5/f2 tie, a 2-slot zeroY/dot schedule - but no source shape flips them); AY3 live-range/pressure shaping (~880 junk/dead-value candidates); AY4 macro/preprocessor shapes (collapse to the same token stream; byte-identical); AY5 fine cross-product of ~58-362 harvested near-miss edits (pairs->quads; no interactions). Cumulative: ~150k+ candidates across rounds SH..AY moved updateCollisions 93.4368 -> 97.7327 (four source shapes) and nothing since.", "round AY1-AY5; sub6-10."),
    ("AS", "result", "ALLOCATOR SOLVED with a cleanly-gated compiler patch -> 99.1647 (verified). Chain: AS1 fixes the GPR scratch tie (v91->r6 forces v82->r5) -> 98.4487; AS3 fixes the FPR temp_f5 pick (node f36->f5) -> 98.0907; AS4 falsifies the 'graph must change' hypothesis (no missing edge; order reversal -> 44.5) and combines GPR+FPR -> 98.8067; AS5 builds a CLEAN gate - `_copts[0x6D]` (VA 0x74F395) set by `-pragma \"report_heap_info on\"`, function-scoped via `_gFunction` 0x751e44 - and FPR2 forces the last FPR web (v132->f3, which cascades to fix both remaining FPR names) -> 99.1647. Hook RVA 0x1b4420 + 156-byte cave RVA 0x26c6fa; whole-TU clean (only updateCollisions changes); independently re-verified. CAVEAT: non-standard compiler (not reproducible with stock mwcceppc.exe).", "rounds AS1/AS3/AS4/AS5/FPR2; verified by vfpr.py (99.1647)."),
    ("AS", "consequence", "SCHEDULER residual is NOT allocator/register-addressable: the last 7 mismatches (idx ~458-472) are a load-store SCHEDULE rotation + an fmuls operand order. The alias-predicate levers are dead (forcing _may_alias true -> 80.7, false -> 78.8; forcing the _nbytes extra-dependency -> unchanged 97.7327); the 12-model scheduler sweep was already dead. A fix would need a scheduler-side priority/tie-break cave at RVA 0x1b6ad0, gated by the same clean gate - unproven, and the time-boxed SCH agent did not find it. So with the gated compiler the ceiling is 99.1647; 100% needs the schedule, which is a list-scheduling tie-break.", "SCH (time-boxed) + AS/FPR2."),
    ("CCBUILD", "consequence", "The 'different MWCC 4.2 BUILD' lead is DEAD: the machine has only the 28 known compilers (all distinct VERSIONS; Wii/1.0a is byte-size-identical to 0x4201_127), and re-sweeping them on the NEW 97.7327 source gives 0x4201_127 best (97.7327), 1.0a/1.0RC1 97.2554, the rest <= 91.9. Decisively, F4 established retail MKW was built with CodeWarrior Wii 0x4201_127 - so a different build would not be retail's toolchain (non-principled anyway). Therefore the residual is SOURCE, not a compiler-build difference (consistent with X2's pass-order analysis).", "cc_resweep.py re-sweep at 97.7327 + F4."),
    ("FOCUS", "consequence", "FOCUSED reconstruction of the dot/sqrt schedule block (idx ~453-504, ~190 candidates + the PCode internal dump): nothing beat 97.7327, and the retail temp ordering is NOT expressible via the `dot(zeroY(a), zeroY(b))` construct - MWCC always materialises the FIRST syntactic argument's `zeroY` temp second, so `p1` lands in the 0x8 slot; the target is the off-diagonal {sp20@0x14, p1=sp20}, unreachable from this construct. Confirmed against the compiler: build/mwcc-debug/dumps/backend-44-after-peephole.txt shows the pre-schedule order for block B102 already differs from retail, and the (deterministic) list scheduler then swaps the z-pair and hoists the constant. Named zeroY locals, member-wise zeroY, precomputed copies, long-lived sp20/wall temps, temp-decl reorder all tie or regress.", "focused sub6 agent; backend-44/45 dumps."),
    ("HY", "consequence", "ALL 10 grounded hypotheses (H1-H10) REFUTED; none beat 97.7327 (~2,000 candidates).", "round HY1-HY10; sub1-10."),
    ("S", "result", "SCALE round (10 searches) BROKE the 97.7327 plateau TWICE: S10's byte-distance hill-climb -> 98.4487 by SWAPPING the flags-block accessors (`flags0 = (*pproxy)->kartStateReload()->field(0)` and `(*pproxy)->kartState()->field(0) &= 0xFFFBE39F`), which fixes the r5/r6 prologue colour tie FROM SOURCE (the non-standard compiler patch previously had to force it - and hits the same 98.4487); and S1's token-level sweep -> 98.0930 with `(flags0 & 0x60) != 1` (semantically identical). The two do NOT combine (S1 on the S10 base drops to 98.0930). Key lesson: the residual space was NOT exhausted - hand-picked shapes plateaued, but mechanical token/byte searches found wins in the flags block; ~48k type-matrix + ~13k grammar + ~12.7k edit-pool-cross + ~4k pragma/flags-cross + ~2k block perms found nothing, so the win came specifically from *broad cheap token/byte* search.", "round S1-S10; verified on the real source 98.4487, 838 insns."),
    ("S2", "consequence", "3-STEP follow-up (the productive levers re-run from 98.4487) found NOTHING: (1) the FULL 15,505-token single-edit sweep -> 0 wins, 2,234 ties; (2) a ~14,600-eval steepest-descent byte-distance hill-climb (1,016-lever library); (3) a ~15,000-eval simulated-annealing search (24 anneals, 7 seeds, accessor-swap-biased); (4) a dot/sqrt-block distance search. 98.4487 is the new plateau. IMPORTANT: the distance metric is imperfect - T4 found variants with LOWER distance but LOWER objdiff (dist=22 @ 97.49, dist=32 @ 97.73 vs base dist=36 @ 98.45), so distance-guided search can be misled once the schedule/FPR clusters dominate. Cumulative since the round started: ~150k+ -> 98.4487.", "round S2 follow-up; sub1-4."),
    ("D", "result", "Round D (RE-RUNNING 10 attempted techniques at the new 98.4487 base) found ONE win: **D4 -> 98.6873**. The edit rewrites the `dotZY` helper body with NAMED LOCALS (`EGG::Vector3f zb = b, za = a; za.y = 0.0f; zb.y = 0.0f; return EGG::Vector3f::dot(za, zb);`) instead of `return EGG::Vector3f::dot(zeroY(a), zeroY(b));` - declaring `zb` first flips the temporary-copy order to match retail. The other 9 all plateaued at 98.4487 (D1 equivalence-swap dot region, D2 sub-address on dot temps, D3 FPR manufacture, D5 Y1 relaunch, D6 V2 relaunch, D7 updateWipe relaunch, D8 flag/pragma x dot-shape, D9 differential oracle, D10 PCode search). KEY LESSON: the SAME search can fail at one base and win at another - SR2's float/zeroY search plateaued at 94.39 and WON at 98.4487 - so re-running old searches after each new win is productive.", "round D1-D10; verified on the real source 98.6873, 838 insns."),
    ("E", "gotcha", "INTEGRITY / FAKEMATCH WARNING. The mechanical token/value sweeps can find FAKEMATCHES - edits that score higher by CHANGING BEHAVIOUR. Round E1's only 'win' (98.6889) changes `if (var_r5 == 0)` to `if (var_r5 == 1)` where `var_r5 = f8 & 0x102` (values {0,0x2,0x100,0x102}, never 1) -> the branch becomes never-taken. The earlier S1 'win' (98.0930) changes `(flags0 & 0x60) != 0` to `!= 1`; at mask==0 those differ (`0!=0`=false vs `0!=1`=true). BOTH ARE SEMANTIC CHANGES and are REJECTED (never landed). RULE: a source edit that changes a comparison's truth value on ANY input is a fakematch, even if it scores higher - the retail bytes encode the true behaviour. The two landed wins ARE semantic-preserving (S10 accessor swap: kartStateReload/kartState return the same object; D4 named locals == the same dot). Always check equivalence, not just the score.", "rounds S1/E1; flag for all future token/value sweeps."),
    ("F", "consequence", "Round F (10 more searches at 98.6873, ~45k candidates) found NO legitimate win. F1's token sweep produced 3 above-base hits - round E1's cmp-constant fakematch, an added `(s16)` cast, and a changed memory operand - ALL rejected by the mandatory equivalence gate (gate working as intended). F2 (hill-climb ~6.4k, base dist 22), F4 (dotZY body exhaustive ~1.3k - saturated), F5 (FPR ~2.6k - temp_f5 stays f2; the only shape reaching f5/f4 costs ~8 insns) all plateau at 98.6873. F3 cancelled (too long). Conclusion: 98.6873 holds; the residual ~11 instructions are allocator/scheduler-locked (the inlined dotZY stack-slot/interleave order + the FPR f5/f2 pick), invariant under every semantic-preserving source shape tried across rounds S..F.", "rounds F1-F5; sub1-5."),
]


RULES = [
    ("R-COLOR-ORDER", "Colour order = DESCENDING vreg id. MWCC's Chaitin pass hands saved registers r31,r30,r29,... to webs in descending vreg-index order (not by degree).",
     "regalloc-gpr-pass-1-assigned.txt: v143->r31, v94->r30, v88->r29, v69->r28.",
     "Compute a candidate's expected colouring from vreg ids; reordering by declaration order alone won't move a var past a temp."),
    ("R-VREG-BLOCKS", "Declared locals = one contiguous vreg block in reverse declaration order; compiler temps are numbered above the whole block, so a first-declared local is pinned one below the temp floor and cannot out-rank a pool temp by reordering.",
     "pe=v69 (first-declared); locals 32..69; temps 70+; pool=v88; gap ~19 invariant.",
     "To move a var above a temp you must change it into a (long-lived) temp, not reorder declarations."),
    ("R-SPLIT", "A lifetime split (x2=x) recolours only if x is non-rematerializable and the copy's live range overlaps the original (not a subset).",
     "proxy (address-taken, used before+after) splits -> r26; pe/var_r28/flags0 fold.",
     "Use this to de-cycle a variable: split an address-taken/overlapping value; do NOT bother splitting constants or small pure expressions."),
]

# ---------------------------------------------------------------- extras
# ETL rows written by tools/run_and_log.py. On rebuild the auto-increment
# surrogate keys (trial_id, id, finding_id) are dropped and re-issued so the
# rebuilt DB is internally consistent.
EXTRAS = [
    ("extra_agents.jsonl", "agents",
     ["agent_id", "round", "angle", "model", "status", "best_score",
      "beat_base", "summary", "key_finding"]),
    ("extra_trials.jsonl", "trials",
     ["agent_id", "label", "category", "edit_from", "edit_to", "score",
      "base", "delta", "registers", "instr_count", "beat", "notes"]),
    ("extra_regalloc.jsonl", "regalloc",
     ["build_id", "source", "name", "vreg", "degree", "reg", "flags"]),
    ("extra_findings.jsonl", "findings",
     ["agent_id", "kind", "statement", "evidence"]),
    ("extra_rules.jsonl", "rules",
     ["rule_id", "statement", "evidence", "consequence"]),
]


def _merge_extras(con):
    """Insert any extra_*.jsonl rows produced by the ETL tool. Returns a dict
    {filename: rows_merged}."""
    merged = {}
    for fname, table, cols in EXTRAS:
        path = os.path.join(HERE, fname)
        n = 0
        if not os.path.exists(path):
            continue
        with open(path, encoding="utf-8") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                row = json.loads(line)
                con.execute(
                    "INSERT INTO %s(%s) VALUES(%s)"
                    % (table, ",".join(cols), ",".join("?" * len(cols))),
                    [row.get(c) for c in cols])
                n += 1
        merged[fname] = n
    return merged


# ---------------------------------------------------------------- harvest methods
# Every unique data-harvesting method used across the whole project.
# (name, category, tool, collects, command, used_for)
HARVEST_METHODS = [
    ("objdiff JSON match%", "measure", "objdiff-cli",
     "per-function/per-section match_percent; per-instruction rows; reloc detail",
     "objdiff-cli diff -p . -u StaticR/kart/KartState -o out.json --format json",
     "the primary oracle for every trial's score"),
    ("objdiff relax-reloc (-x)", "measure", "objdiff-cli",
     "same as above with relocation-name diffs ignored",
     "objdiff-cli diff -p . -u ... -x",
     "proved the .rodata symbol-name difference did not affect the score"),
    ("objdump disassembly", "disasm", "powerpc-eabi-objdump",
     "instruction stream of an object",
     "powerpc-eabi-objdump -d build/RMCP01/StaticR/obj/kart/KartState.o",
     "compared ours vs target prologue/registers; found the pool/pe lds"),
    ("objdump + relocs", "disasm", "powerpc-eabi-objdump",
     "instructions with relocation annotations",
     "powerpc-eabi-objdump -dr ...",
     "extracting the pe/var_r28/proxy/pool register tuple"),
    ("readelf symbols", "symbols", "powerpc-eabi-readelf",
     "symbol names/sizes/types/bind/section per object",
     "readelf -s <obj>",
     "compared target vs our object symbols (rodata naming/size)"),
    ("readelf sections", "data", "powerpc-eabi-readelf",
     "section headers (size, file offset)",
     "readelf -S <obj>",
     "section sizes; finding the .rodata pool"),
    ("readelf relocations", "reloc", "powerpc-eabi-readelf",
     "every relocation (offset, type, symbol) ",
     "readelf -r <obj>",
     "per-function symbol-reference comparison; located r29=lbl_1_rodata_27D0/r30=pe"),
    ("readelf hex dump", "data", "powerpc-eabi-readelf",
     "raw bytes of a section",
     "readelf -x .rodata <obj>",
     "proved target/our .rodata byte-identical (only symbol name differed)"),
    ("nm ordered symbols", "symbols", "powerpc-eabi-nm",
     "symbols in address order with sizes",
     "powerpc-eabi-nm -n -S --defined-only <obj>",
     "TU function order; per-function byte compare"),
    ("capstone instruction diff", "disasm", "capstone (python)",
     "disassembly with operands; classify diffs as register-only vs structural",
     "capstone CS_ARCH_PPC disasm of the function bytes",
     "proved the residual is register-only (no structural diffs)"),
    (".note.split dump", "data", "readelf / dtk",
     "dtk split metadata: original TU function order + data addresses",
     "readelf -x .note.split <obj>",
     "confirmed the original function order and data addresses"),
    ("Metrowerks .MAP generation", "data", "configure.py --map + mwld",
     "full link map (sections->files->symbols, addresses/sizes)",
     "python configure.py --map ; ninja build/RMCP01/main.elf",
     "mapdas input; project layout; symbol map"),
    ("MWCC debugger PCode", "vreg-internals", "cadmic/mwcc-debugger (Windows port)",
     "PCode instruction stream per backend pass",
     "run_debugger.py (compiles one function under gdb)",
     "found the coalescing `mr r385,r92`; pass attribution"),
    ("MWCC debugger regalloc graph", "vreg-internals", "mwcc-debugger",
     "interference graph: vreg id, degree, physical reg, fCoalescedInto flags",
     "regalloc-gpr-pass-1-all.txt / -assigned.txt",
     "the vreg-index colouring rule; degrees; coalescing"),
    ("MWCC row derivation", "vreg-internals", "mwcc-debugger + CodeView blob",
     "per-build address table (breakpoints, graph addr, opcode table)",
     "versions.py row from the compiler's NB11 symbol blob + driver disasm",
     "enabled the debugger on our exact compiler Wii/0x4201_127"),
    ("compiler sweep", "compiler", "all build/compilers/**/mwcceppc.exe",
     "score for each of ~28 MWCC builds on the same source",
     "loop: compile + objdiff each compiler",
     "pinned Wii/0x4201_127 as best (86.99 then 93.44 source)"),
    ("flag sweep", "compiler", "mwcceppc -O/-inline/-ipa/-opt/-proc/-schedule",
     "score for ~70 optimizer/addressing flag combos",
     "compile+objdiff per flag combo",
     "confirmed the project flags are optimal; CSE/colour is invariant"),
    ("probe/h harness", "measure", "custom (probe.py/h.py)",
     "fast in-memory compile+objdiff score for a candidate source text",
     "import probe as P; P.run([(name, P.build([(old,new)]))])",
     "the throughput engine for ~150k candidate edits"),
    ("hill-climb permuter", "permuter", "hill.py",
     "best score over lever-library combinations",
     "python hill.py <seed> <rounds>",
     "found the proxyF lifetime-split win (93.4368)"),
    ("tree-sitter AST permuter", "permuter", "tsperm.py",
     "structural mutations (temp-intro, stmt-reorder, operand-swap, type)",
     "python tsperm.py",
     "structural search; no gain past the wall"),
    ("text/regex permuter engine", "permuter", "engine.py",
     "text-level mutation search",
     "python engine.py",
     "broad text-level candidate generation"),
    ("decomp-permuter (patched)", "permuter", "simonlindholm/decomp-permuter",
     "random C permutation scored by objdiff (patched scorer + direct compile)",
     "permuter.py <fn>/ -j4 (C-only)",
     "baseline tooling; limited to C, not this C++ TU"),
    ("dtk tooling", "external", "decomp-toolkit",
     "elf info/dwarf/sigs/disasm, dol diff/apply, map",
     "dtk elf info | dwarf dump | dol diff | map entries",
     "confirmed code-identity; built the dol_diff symbol-remap tool"),
    ("dtk dol diff", "measure", "dtk",
     "the 'most obvious difference causing a mismatch' in the linked ELF",
     "dtk dol diff config.yml build/RMCP01/main.elf",
     "found a project-wide symbol-name mismatch; drove the remap tool"),
    ("decomp.me scratch API", "external", "decomp.me",
     "fetch/POST a scratch (source, context, target asm)",
     "GET /api/scratch/<id> ; POST /api/scratch",
     "published WIP scratch hbr0m (87->93%); search API CF-blocked"),
    ("GitHub search / webfetch", "external", "gh + webfetch",
     "matching techniques, tools, sibling decomp sources",
     "gh search code 'MWCC register allocation' ; webfetch raw files",
     "found SFA-Decomp playbook, mwcc-debugger, doldecomp/mkw"),
    ("source-form enumeration", "edit-generation", "custom",
     "systematic libraries of declaration/type/qualifier/cast spellings",
     "enum_reg.py / search_decl.py / matrix.py",
     "proved the baseline is a fixed point of the allocator"),
    ("lifetime-split experiments", "edit-generation", "custom",
     "x2=x copies at many points / per-value splits",
     "reorder.py / coalesce.py / sb2.py",
     "the R-SPLIT rule (non-rematerializable + overlapping range)"),
    ("register-tuple extraction", "measure", "objdump + regex",
     "the (pe/var_r28/proxy/pool) physical registers from the object",
     "objdump -dr | parse lis/lwz/rlwinm",
     "machine-comparable register state per trial"),
    ("vreg-table parsing", "vreg-internals", "custom",
     "var -> vreg -> degree -> register -> flags from regalloc dumps",
     "parse_regalloc.py",
     "the colour model the solver/analytics consume"),
    ("renumbering analysis", "vreg-internals", "custom",
     "how a source edit shifts the vreg table (cause->effect map)",
     "diff normalized vreg tables across builds",
     "derived R-VREG-BLOCKS (reverse-decl block; temps above)"),
    ("degree/neighbour parsing", "vreg-internals", "custom",
     "interference degree per web",
     "parse the neighbors list in regalloc-gpr-pass-1-all.txt",
     "falsified the degree-priority model"),
    (".data/.rodata order sweep", "data", "sweep_data.py",
     "declaration-order effects on data symbols",
     "sweep_data.py (201 TUs)",
     "found the data-section ordering is cross-declaration"),
    ("project-wide TU sweep", "measure", "objdiff + nm",
     "0 pure reorders; 2 constant diffs across 201 TUs",
     "scan all matched TUs",
     "bounded the data-section issues"),
    ("dol_diff symbol remap", "external", "tools/remap_elf_symbols.py",
     "rewrites the linked ELF symtab so dtk dol diff passes",
     "python tools/remap_elf_symbols.py main.elf out.elf",
     "made ninja dol_diff green; PR #13"),
    ("reloc-symbol comparison", "reloc", "readelf -r (parse)",
     "set of referenced symbols per function (ours vs target)",
     "compare readelf -r for the function range",
     "proved identical symbol references (only names differed)"),
    ("subagent swarm", "meta", "opencode Task (general)",
     "parallel hypothesis exploration + cross-dataset analysis",
     "5 agents per round, distinct angles",
     "the proxyF win; then exhaustive confirmation of the wall"),
    ("DB analytics/graph/solver/retrieval/ETL", "meta", "custom tools",
     "aggregate statistics; state-graph no-path; UNSAT proof; retrieval; row-logging",
     "analyze_db.py / regstate_graph.py / colour_solver.py / kb_retrieval.py / run_and_log.py",
     "formal no-path + UNSAT proofs; grew this DB"),
    ("m2c asm->C", "external", "matt-kempster/m2c",
     "decompiler C for the target asm",
     "m2c -t ppc-mwcc-c target.s",
     "recovered gameMode as a (false-positive) switch"),
    ("decompctx context", "external", "tools/decompctx.py",
     "the context (headers) for a decomp.me/permuter scratch",
     "python tools/decompctx.py <src>",
     "prepared the scratch/permuter bundle"),
]

# ---------------------------------------------------------------- tools built
# (tool_id, name, paradigm, path, purpose, key_output)
TOOLS_BUILT = [
    ("T-A", "analyze_db.py", "analytics", "subagent_data/tools/analyze_db.py",
     "SQL/pandas mining of the trial/regalloc tables",
     "only lifetime-split ever beats; vreg-score r=0.77; ranked untried levers"),
    ("T-B", "regstate_graph.py", "graph", "subagent_data/tools/regstate_graph.py",
     "register-state transition graph (nodes=colour tuples, edges=edits)",
     "BFS+Dijkstra PROVE no path from current to target colour state"),
    ("T-C", "kb_retrieval.py", "retrieval", "subagent_data/tools/kb_retrieval.py",
     "FTS + TF-IDF retrieval + hypothesis synthesis",
     "7 uncrossed mechanism x node combos; 24 hypotheses (all no-op/regress)"),
    ("T-D", "colour_solver.py", "solver", "subagent_data/tools/colour_solver.py",
     "z3 constraint model of the MWCC colouring",
     "colouring model SAT; source-realizable model UNSAT (proof)"),
    ("T-E", "run_and_log.py", "ETL", "subagent_data/tools/run_and_log.py",
     "run candidates, extract colouring, write rows back to the DB",
     "logged 17 trials + 51 regalloc rows (agent_id=ETL)"),
    ("T-F", "probe.py / h.py", "harness", "%TEMP%/opencode/perm/probe.py",
     "fast compile+objdiff for a candidate source text",
     "the throughput engine (~150k candidates)"),
    ("T-G", "mhtri mwcc-debugger", "internals", "%TEMP%/opencode/mhtri/tools/mwcc-debugger",
     "MWCC internals dump (PCode/regalloc) for our exact compiler",
     "the vreg colouring rule + coalescing evidence"),
    ("T-H", "remap_elf_symbols.py", "linking", "tools/remap_elf_symbols.py",
     "remap linked-ELF symbols so dtk dol diff passes",
     "ninja dol_diff green (doldecomp PR #13)"),
]

# ---------------------------------------------------------------- proofs
# (kind, statement, method, evidence)
PROOFS = [
    ("counterexample(escape) [SUPERSEDES no-path/UNSAT/invariance]", "The target colour state IS reachable: the project went 93.4368 -> 94.3914 with pe=r30 "
     "via a sub-address temp (`f32* const p3 = lbl_1_data_3918 + 3; f32* const pe = p3 - 3;`) plus declaring var_r28/var_r27 before pe. "
     "The earlier no-path/UNSAT/measurement-invariance proofs all ASSUMED `pe` remained a declared local (R-VREG-BLOCKS); the escape makes pe a compiler temp, so those proofs were premise-limited, not global.",
     "sub7/best_94_3914.cpp + real-source objdiff 94.3914 (prologue `lis r30`=pe, `lis r29`=pool, `rlwinm r28`=var_r28)",
     "corrects the earlier 'target unreachable' claim; the residual that remains is purely the structural slots"),
    ("no-path [FALSIFIED by CC/SH2]", "No recorded or newly-tested source edit moves the colour state from "
     "current {pe=r28,var_r28=r30,proxy=r26,pool=r29} to target {pe=r30,var_r28=r28,proxy=r26,pool=r29}.",
     "regstate_graph.py (BFS + Dijkstra over 12 nodes / 32 edges)",
     "target node has 0 measured in-edges; no node is distance 1; required move is a simultaneous r28<->r30 swap"),
    ("infeasibility(UNSAT)", "The target colouring is unreachable from source that keeps `pe` a declared local: "
     "pe=r30 needs v(pe)>v(pool); a local has v<=local_top<v(pool) (R-VREG-BLOCKS); a split copy folds because pe is a "
     "rematerializable constant address (R-SPLIT).",
     "colour_solver.py (z3 model: colouring model SAT, source-realizable model UNSAT)",
     "candidate(v143)=r31,var_r28(v94)=r30,pool(v88)=r29,pe(v69)=r28; 15-uses->15-lis rematerialization"),
    ("measurement-invariance", "The residual is register-only + a CSE-locked 4-instruction gap; "
     "no compiler (28 builds) or flag (~80 combos) or declaration/type/structure/loop/TU-context/lifetime-split edit changes it.",
     "R1-R4/G agents + capability sweeps (G1/G2 compiler+flag redos, G4 12.1k AST, G6 2,829 splits, G10 autoloop)",
     "58k+ permuter, 3000 decl perms, 28 compilers, 80 flags, 2,829 splits, 5 tool paradigms -> all <= 93.4368; relocs 63/63 identical (G9)"),
    ("infeasibility(UNSAT, extended/full)", "The FULL target (colours + structure) is unsatisfiable under a single source shape: "
     "the colour axis is UNSAT (pe cannot out-rank the pool) AND the structural closure needs a -3-instruction compensation "
     "no known lever provides (the only 4x-clrlwi lever costs +7).",
     "subagent_data/tools/colour_solver.py MODEL 3 (colour+structure, z3), agent E3",
     "structural coupling pins pe=v69<pool=v88 (closes the pool-as-local escape); sibling idiom corroborates our base (E5); 838-insn fix decoupled (E4)"),
]

# ---------------------------------------------------------------- processes
# Every process/pipeline this project ran. (process_id, name, category, purpose, steps, tools, result, agents)
PROCESSES = [
    ("P-MATCH-LOOP", "edit->build->objdiff matching loop", "matching-loop",
     "raise a function's objdiff match% by iterating source edits",
     "edit KartState.cpp; ninja build the object; objdiff-cli diff; read match_percent; repeat",
     "mwcc, ninja, objdiff-cli", "86.993 -> 93.437 (the proxyF split); the base loop for everything",
     "primary"),
    ("P-SCRATCH", "decomp.me scratch iteration", "matching-loop",
     "share/iterate the function on decomp.me",
     "GET/POST /api/scratch; hbr0m re-posted as the score rose",
     "decomp.me API", "scratch hbr0m at 87->93%; search API CF-blocked", "-"),
    ("P-PERMUTER", "decomp-permuter (patched)", "matching-loop",
     "random source permutation scored by objdiff",
     "patch scorer.py (objdiff mode) + compiler.py (direct compile); run permuter",
     "decomp-permuter, pycparser", "C-only; could not parse the C++ TU (dead end for this file)", "-"),
    ("P-REGPARTS", "regparts/regenum vreg instrumentation", "matching-loop",
     "enumerate edits with register instrumentation",
     "instrument build; enumerate 276 edits; score",
     "custom (regparts.py/regenum.py)", "proved the registers are locked to structure (all movers <=60%)", "-"),
    ("P-ENGINE-TEXT", "text-level mutation engine", "matching-loop",
     "candidate generation at the text level", "apply regex/text edits; score", "engine.py", "~thousands of candidates; found movers", "-"),
    ("P-ENGINE-TS", "tree-sitter AST mutation engine", "matching-loop",
     "candidate generation at the AST level", "mutate AST (temp-intro/stmt-reorder/type)", "tsperm.py, tree-sitter", "structural candidates; no gain past the wall", "-"),
    ("P-OBJDIFF", "objdiff JSON scoring (+relax)", "harvest",
     "the score oracle per trial", "objdiff-cli diff -p/-1/-2 -o json; parse match_percent; -x to relax relocs", "objdiff-cli",
     "primary oracle; proved the rodata symbol name was score-irrelevant", "-"),
    ("P-SYMBOLS", "readelf/nm symbol analysis", "harvest", "symbol names/sizes/order",
     "readelf -s; nm -n -S", "binutils", "compared target/ours symbols; TU function order", "-"),
    ("P-SECTIONS", "readelf sections/hex", "harvest", "section sizes + raw bytes",
     "readelf -S; readelf -x", "binutils", "target/our .rodata byte-identical (only symbol name differed)", "-"),
    ("P-RELOC", "readelf relocations + reloc-symbol compare", "harvest", "symbol references",
     "readelf -r; compare per-function ranges", "binutils", "identical relocs (only names differed); located r29=pool/r30=pe", "-"),
    ("P-CAPSTONE", "capstone instruction/register diff", "harvest", "classify instruction diffs",
     "capstone disasm; normalize registers; classify", "capstone", "residual is register-only + a CSE-locked block (later corrected by D3)", "-"),
    ("P-NOTE-SPLIT", ".note.split dump", "harvest", "original TU layout", "readelf -x .note.split", "binutils", "original function order + data addresses match ours", "-"),
    ("P-MAP", "Metrowerks .MAP generation", "harvest", "full link map", "configure.py --map; ninja main.elf", "mwcc, mwld, dtk", "generated main.elf.MAP (mapdas input)", "-"),
    ("P-REGTUPLE", "register-tuple extraction", "harvest", "machine-comparable colour state",
     "objdump -dr; parse lis/lwz/rlwinm", "objdump", "pe/var_r28/proxy/pool tuple per trial", "-"),
    ("P-CC-SWEEP", "compiler-version sweep", "compiler-investigation", "test other MWCC builds",
     "compile the source with each build/compilers/**/mwcceppc.exe; objdiff", "mwcc, objdiff", "Wii/0x4201_127 best; no other build reached 100%", "R4-A"),
    ("P-FLAG-SWEEP", "flag sweep", "compiler-investigation", "test optimizer/addressing flags",
     "compile+objdiff per flag combo", "mwcc", "project flags optimal; colour invariant", "R4-A"),
    ("P-DBG-SETUP", "mwcc-debugger setup + row derivation", "compiler-investigation",
     "enable the debugger on our exact compiler",
     "clone the Windows port; derive a Wii/0x4201_127 row from the CodeView blob; fix breakpoints", "cadmic/mwcc-debugger, gdb", "debugger runs on Wii/0x4201_127", "-"),
    ("P-DBG-REGALLOC", "regalloc graph dump", "compiler-investigation", "read MWCC's allocator",
     "dump regalloc-gpr-pass-1-all/assigned", "mwcc-debugger", "the vreg-index colouring rule + coalescing flags", "R2-D, META-*"),
    ("P-DBG-PCODE", "PCode dump", "compiler-investigation", "trace the frontend/backend",
     "dump backend-NN-*.txt", "mwcc-debugger", "found the coalescing mr r385,r92", "R1-3"),
    ("P-RENUMBER", "renumbering analysis", "compiler-investigation", "how edits shift vregs",
     "diff normalized vreg tables across builds", "custom", "derived R-VREG-BLOCKS (locals reverse-decl block; temps above)", "META-1/4"),
    ("P-DEGREE", "degree/neighbour parsing", "compiler-investigation", "test degree-driven priority",
     "parse the neighbors list", "custom", "falsified the degree-priority model", "R1-5"),
    ("P-DTK", "decomp-toolkit exploration", "external", "extract/analyse objects/config",
     "dtk elf info/dwarf/sigs/disasm; dol diff/apply; map", "dtk", "confirmed code-identity; found a project symbol mismatch", "-"),
    ("P-DOL-DIFF-REMAP", "dol_diff + symbol remap tool", "external", "make dtk dol diff pass",
     "run dol diff; write tools/remap_elf_symbols.py; wire into the dol_diff rule", "dtk, python, objcopy", "ninja dol_diff green", "T-H"),
    ("P-SYNC-DOLDECOMP", "sync with doldecomp/mkw", "external", "merge sibling progress + contribute",
     "file-level diff; take better-matched files; open PRs", "git, gh, objdiff", "took 5 files; PRs #13/#14", "R4/agents"),
    ("P-DECOMPME-API", "decomp.me scratch API", "external", "publish the WIP", "GET/POST scratch", "decomp.me", "hbr0m published", "-"),
    ("P-GH-SEARCH", "GitHub search / webfetch", "external", "find techniques + tools",
     "gh search code/repos; webfetch raw", "gh, webfetch", "found SFA playbook, mwcc-debugger, doldecomp", "-"),
    ("P-M2C", "m2c asm->C", "external", "recover source shape", "m2c the target .s", "m2c", "gameMode as a false-positive switch", "R4-E"),
    ("P-KB", "field notes / knowledge base", "release", "capture reusable techniques",
     "um kb new/check/index/pr", "universal-modder um", "technique note + PR #275", "-"),
    ("P-SWARM", "multi-agent subagent swarm", "meta", "parallel hypothesis exploration + cross-analysis",
     "5 agents/round x distinct angles; cross-analyse outcomes",      "opencode Task (general)", "the proxyF win; then exhaustive confirmation; rounds R1-R4,META,D,E (~35 agents)", "all"),
    ("P-SWARM-PARALLEL", "10-way parallel process redo", "meta",
     "re-run 10 previously-run processes simultaneously in private trusted workspaces",
     "make_ws.py builds sub1..sub10 (each pre-verified 93.4368); 10 agents, one process each; log to private DBs",
     "opencode Task, make_ws.py", "7 completed / 3 cancelled; all confirm 93.4368; new artifacts: exact reg/struct map (G8), reloc identity (G9)", "G1-G10"),
    ("P-DB", "structured dataset construction", "meta", "make results queryable for tools",
     "SQLite+8 tables+FTS; JSONL; build_db.py", "python sqlite3", "subagents.db (32/123/391/32/...)", "DB agents"),
    ("P-TOOLS5", "five tool paradigms over the DB", "meta", "consume the dataset",
     "analytics / graph / retrieval / solver / ETL tools", "analyze_db/regstate_graph/kb_retrieval/colour_solver/run_and_log", "formal no-path + UNSAT; grew the DB", "T-A..T-E"),
    ("P-AUTOLOOP", "automated tool-chain loop", "meta", "self-driving hypothesise->test->log",
     "chain retrieval->run_and_log->graph->solver; repeat", "autoloop.py", "reproduced UNSAT; nothing beat 93.4368", "D5/E4"),
    ("P-PROOF-NOPATH", "state-graph no-path proof", "proof", "prove the target colour state unreachable",
     "build colour-transition graph; BFS/Dijkstra", "regstate_graph.py", "no path exists", "T-B"),
    ("P-PROOF-UNSAT", "colour UNSAT proof", "proof", "prove the colouring unsatisfiable",
     "z3 model of R-COLOR-ORDER/R-VREG-BLOCKS/R-SPLIT", "colour_solver.py", "source-realizable colour model UNSAT", "T-D"),
    ("P-PROOF-UNSAT-EXT", "extended (colour+structure) UNSAT", "proof", "prove the FULL target unsatisfiable",
     "extend the model with structural constraints (gameMode block, instr count)", "colour_solver.py MODEL 3", "FULL model UNSAT; size fix decoupled from colourings", "E3/E4"),
    ("P-PROOF-INVARIANCE", "measurement-invariance result", "proof", "bound the search",
     "28 compilers x flags x edit classes x tools", "all", "nothing beats 93.4368", "R1-R4,D,E"),
    ("P-PR13", "doldecomp PR #13", "release", "contribute the remap tool", "branch+push+PR", "git, gh", "https://github.com/doldecomp/mkw/pull/13", "-"),
    ("P-PR14", "doldecomp PR #14 (draft)", "release", "contribute updateCollisions", "branch+push+draft PR", "git, gh", "https://github.com/doldecomp/mkw/pull/14", "-"),
    ("P-PR275", "universal-modder KB PR #275", "release", "contribute the technique note", "um kb pr", "um, gh", "https://github.com/rehan-remade/universal-modder/pull/275", "-"),
]

# ---------------------------------------------------------------- comparisons
# (a_process, b_process, relationship, note)
COMPARISONS = [
    ("P-MATCH-LOOP", "P-PERMUTER", "subsumes",
     "the manual loop is the general case; the permuter automates it but (C-only) could not run on this C++ TU"),
    ("P-ENGINE-TEXT", "P-ENGINE-TS", "complements",
     "text-level vs AST-level mutation; both are candidate generators for P-MATCH-LOOP; neither beat the wall alone"),
    ("P-CC-SWEEP", "P-FLAG-SWEEP", "complements",
     "compiler-identity vs compiler-flags; both orthogonal to source edits; both confirmed the optimum"),
    ("P-DBG-PCODE", "P-DBG-REGALLOC", "complements",
     "PCode = instruction/frontend trace; regalloc = colouring output; together they explained the coalescing and the vreg rule"),
    ("P-DBG-REGALLOC", "P-RENUMBER", "supersedes",
     "the raw regalloc dump is data; the renumbering analysis turned it into the R-VREG-BLOCKS rule"),
    ("P-DEGREE", "P-DBG-REGALLOC", "contrasts-with",
     "degree-priority (naive) vs vreg-index priority (actual): the degree model is FALSIFIED by the regalloc dump"),
    ("P-RELOC", "P-CAPSTONE", "complements",
     "relocs show symbol references; capstone shows register operands; together they bound the residual to registers+one block"),
    ("P-OBJDIFF", "P-CAPSTONE", "complements",
     "objdiff = the score; capstone = the human-readable diff; the score alone hides which registers differ"),
    ("P-DTK", "P-DOL-DIFF-REMAP", "subsumes",
     "dtk is the toolkit; the remap tool is a specific fix built on its dol diff output"),
    ("P-PERMUTER", "P-ENGINE-TS", "complements",
     "both search source space; the permuter is C-only and could not run here, the AST engine handled C++ but was weaker at breadth"),
    ("P-SYNC-DOLDECOMP", "P-KB", "complements",
     "upstream code/PRs vs the knowledge base; both are dissemination routes"),
    ("P-SWARM", "P-DB", "complements",
     "the swarm produced the data; the DB made it queryable; neither alone is enough"),
    ("P-DB", "P-TOOLS5", "complements",
     "the DB is the substrate; the 5 tools consume it (analytics/graph/retrieval/solver/ETL)"),
    ("P-TOOLS5", "P-PROOF-NOPATH", "subsumes",
     "the graph tool P-PROOF-NOPATH is one of the five paradigms"),
    ("P-PROOF-NOPATH", "P-PROOF-UNSAT", "complements",
     "empirical (graph reachability) vs deductive (z3) proofs of the same unreachability; independent, agreeing"),
    ("P-PROOF-UNSAT", "P-PROOF-UNSAT-EXT", "supersedes",
     "the extended model adds the structural slots and closes the pool-as-local escape the basic model left open"),
    ("P-PROOF-INVARIANCE", "P-PROOF-UNSAT", "complements",
     "measurement across the whole tool space vs a formal model; both bound the ceiling at 93.4368"),
    ("P-AUTOLOOP", "P-TOOLS5", "subsumes",
     "autoloop chains the five tools into a self-driving loop"),
    ("P-SWARM", "P-AUTOLOOP", "contrasts-with",
     "human-in-the-loop parallel agents (broad, interpretable) vs an automated deterministic loop (narrow, reproducible)"),
    ("P-DBG-SETUP", "P-DBG-REGALLOC", "subsumes",
     "the setup (row derivation, breakpoint fix) was the prerequisite for any regalloc dump"),
    ("P-MATCH-LOOP", "P-REGPARTS", "subsumes",
     "enumeration is an automated form of the manual loop (edit->build->score)"),
    ("P-PR13", "P-PR14", "complements",
     "PR13 = the tooling fix; PR14 = the function itself; to the same repo"),
    ("P-PR14", "P-PR275", "complements",
     "the function contribution (doldecomp) vs the reusable technique note (universal-modder KB)"),
]

# ---------------------------------------------------------------- artifacts
# The durable artefact collection (files under subagent_data/artifacts/).
# (artifact_id, kind, path, round, score, description)
ARTIFACTS = [
    ("W0", "winning-source", "artifacts/wins/00_86.9928_proxyF_split.cpp", "R1",
     86.9928, "The proxyF lifetime split + var_r28 mask form: the first win (86.99)."),
    ("W1", "winning-source", "artifacts/wins/01_94.3914_subaddr_temp.cpp", "SH2",
     94.3914, "Sub-address temp (p3 = lbl+3; pe = p3-3) -> pe becomes a compiler temp -> r30; var_r28/var_r27 declared first."),
    ("W2", "winning-source", "artifacts/wins/02_95.9427_s8_playerIdx.cpp", "SR1",
     95.9427, "s8/u8 playerIdx defeats the (u8)-cast CSE -> 4x clrlwi + cmpwi + 838 insns; rm before rc."),
    ("W3", "winning-source", "artifacts/wins/03_97.0167_typed_vcall.cpp", "T1",
     97.0167, "Typed virtual call -> vtable temp r12 (MWCC's standard virtual-call sequence)."),
    ("W4", "winning-source", "artifacts/wins/04_97.7327_dotZY_final.cpp", "U2",
     97.7327, "Inline dotZY boundary -> fixes the zeroY stack-slot order. The current best."),
    ("W5", "winning-source", "artifacts/wins/05_98.4487_accessor_swap.cpp", "S10",
     98.4487, "Swap the flags-block accessors: read flags0 via kartStateReload()->field(0), write the clear-mask via kartState()->field(0). Fixes the r5/r6 prologue tie FROM SOURCE (the compiler patch previously had to force it)."),
    ("W6", "winning-source", "artifacts/wins/06_98.6873_dotZY_named_locals.cpp", "D4",
     98.6873, "Rewrite the dotZY body with named locals (`EGG::Vector3f zb = b, za = a; za.y=0; zb.y=0; return dot(za,zb);`) instead of `dot(zeroY(a),zeroY(b))` -> flips the zeroY temp-copy order to retail. Found by re-running the SR2 float search at the 98.4487 base."),
    ("WF", "winning-source", "artifacts/wins/final_KartState.cpp", "-",
     98.6873, "The authoritative committed src/kart/KartState.cpp at 98.6873 (a snapshot copy)."),
    ("C1", "compiler-patch", "artifacts/compiler-patch/FINAL_patch.json", "AS5/FPR2",
     99.1647, "The cleanly-gated compiler patch (hook 0x1b4420 + 156-byte cave 0x26c6fa; gate _copts[0x6D] via -pragma report_heap_info on). NON-STANDARD; not landed."),
    ("C2", "compiler-patch", "artifacts/compiler-patch/final_patch.py", "AS1",
     98.4487, "AS1's per-byte patcher for the scratch-colour (r5/r6) swap."),
    ("C3", "compiler-patch", "artifacts/compiler-patch/RESULTS.md", "AS5",
     None, "AS5's clean-gate survey + the global-candidate re-test table."),
    ("C4", "compiler-patch", "artifacts/compiler-patch/as4_REPORT.md", "AS4",
     None, "AS4's interference-graph RE report (the 'graph must change' falsification)."),
    ("H1", "harness", "artifacts/harness/h.py", "-", None,
     "The candidate-scoring harness (compiles a source string with MWCC Wii/0x4201_127 and reports objdiff match%)."),
    ("H2", "harness", "artifacts/harness/make_ws.py", "-", None,
     "Builds the private trusted workspaces sub1..subN (snapshot + repointed h.py/probe.py + baseline check)."),
    ("H3", "harness", "artifacts/harness/probe.py", "-", None,
     "The PRE/BODY/POST probe harness."),
    ("D1", "decompme", "artifacts/decompme/hbr0m.zip", "R1", 86.9928,
     "The decomp.me scratch bundle (scratch hbr0m) with ctx.cpp + the WIP source."),
]

# ---------------------------------------------------------------- build
def build():
    db = os.path.join(HERE, "subagents.db")
    if os.path.exists(db):
        os.remove(db)
    con = sqlite3.connect(db)
    con.executescript(
        """
        CREATE TABLE agents(
          agent_id TEXT PRIMARY KEY, round TEXT, angle TEXT, model TEXT,
          status TEXT, best_score REAL, beat_base INTEGER,
          summary TEXT, key_finding TEXT);
        CREATE TABLE trials(
          trial_id INTEGER PRIMARY KEY AUTOINCREMENT,
          agent_id TEXT, label TEXT, category TEXT,
          edit_from TEXT, edit_to TEXT,
          score REAL, base REAL, delta REAL,
          registers TEXT, instr_count INTEGER, beat INTEGER, notes TEXT);
        CREATE TABLE regalloc(
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          build_id TEXT, source TEXT, name TEXT, vreg INTEGER,
          degree INTEGER, reg TEXT, flags TEXT);
        CREATE TABLE findings(
          finding_id INTEGER PRIMARY KEY AUTOINCREMENT,
          agent_id TEXT, kind TEXT, statement TEXT, evidence TEXT);
        CREATE TABLE rules(
          rule_id TEXT PRIMARY KEY, statement TEXT, evidence TEXT, consequence TEXT);
        CREATE TABLE harvest_methods(
          method_id INTEGER PRIMARY KEY AUTOINCREMENT,
          name TEXT, category TEXT, tool TEXT, collects TEXT, command TEXT, used_for TEXT);
        CREATE TABLE tools_built(
          tool_id TEXT PRIMARY KEY, name TEXT, paradigm TEXT, path TEXT,
          purpose TEXT, key_output TEXT);
        CREATE TABLE proofs(
          proof_id INTEGER PRIMARY KEY AUTOINCREMENT,
          kind TEXT, statement TEXT, method TEXT, evidence TEXT);
        CREATE TABLE processes(
          process_id TEXT PRIMARY KEY, name TEXT, category TEXT, purpose TEXT,
          steps TEXT, tools TEXT, result TEXT, agents TEXT);
        CREATE TABLE comparisons(
          cmp_id INTEGER PRIMARY KEY AUTOINCREMENT,
          a TEXT, b TEXT, relationship TEXT, note TEXT);
        CREATE TABLE artifacts(
          artifact_id TEXT PRIMARY KEY, kind TEXT, path TEXT, round TEXT,
          score REAL, description TEXT);
        """
    )
    for a in AGENTS:
        con.execute("INSERT INTO agents VALUES(?,?,?,?,?,?,?,?,?)", a)
    for t in TRIALS:
        aid, label, cat, ef, et, score, base, regs, ic, notes = t
        delta = round(score - base, 4)
        beat = 1 if score > base + 1e-9 else 0
        con.execute(
            "INSERT INTO trials(agent_id,label,category,edit_from,edit_to,score,base,delta,registers,instr_count,beat,notes) "
            "VALUES(?,?,?,?,?,?,?,?,?,?,?,?)",
            (aid, label, cat, ef, et, score, base, delta, regs, ic, beat, notes))
    for r in REGALLOC:
        con.execute("INSERT INTO regalloc(build_id,source,name,vreg,degree,reg,flags) VALUES(?,?,?,?,?,?,?)", r)
    for f in FINDINGS:
        con.execute("INSERT INTO findings(agent_id,kind,statement,evidence) VALUES(?,?,?,?)", f)
    for r in RULES:
        con.execute("INSERT INTO rules VALUES(?,?,?,?)", r)
    for m in HARVEST_METHODS:
        con.execute("INSERT INTO harvest_methods(name,category,tool,collects,command,used_for) VALUES(?,?,?,?,?,?)", m)
    for t in TOOLS_BUILT:
        con.execute("INSERT INTO tools_built VALUES(?,?,?,?,?,?)", t)
    for p in PROOFS:
        con.execute("INSERT INTO proofs(kind,statement,method,evidence) VALUES(?,?,?,?)", p)
    for p in PROCESSES:
        con.execute("INSERT INTO processes VALUES(?,?,?,?,?,?,?,?)", p)
    for c in COMPARISONS:
        con.execute("INSERT INTO comparisons(a,b,relationship,note) VALUES(?,?,?,?)", c)
    for a in ARTIFACTS:
        con.execute("INSERT INTO artifacts VALUES(?,?,?,?,?,?)", a)

    # --- speed: indexes on the hot filter/join columns (the auto PKs are not enough) ---
    con.executescript(
        """
        CREATE INDEX idx_trials_agent   ON trials(agent_id);
        CREATE INDEX idx_trials_cat     ON trials(category);
        CREATE INDEX idx_trials_beat    ON trials(beat);
        CREATE INDEX idx_trials_score   ON trials(score);
        CREATE INDEX idx_regalloc_build ON regalloc(build_id);
        CREATE INDEX idx_regalloc_name  ON regalloc(name);
        CREATE INDEX idx_findings_agent ON findings(agent_id);
        CREATE INDEX idx_processes_cat  ON processes(category);
        CREATE INDEX idx_comparisons_a  ON comparisons(a);
        CREATE INDEX idx_comparisons_b  ON comparisons(b);
        CREATE INDEX idx_artifacts_kind ON artifacts(kind);
        """
    )
    # --- normalized colour state: "pe/var_r28/proxy/pool" -> 4 indexable columns ---
    con.execute(
        "CREATE TABLE trial_colour(trial_id INTEGER PRIMARY KEY, pe TEXT, var_r28 TEXT, "
        "proxy TEXT, pool TEXT)"
    )
    for row in con.execute("SELECT trial_id,registers FROM trials"):
        parts = (row[1] or "").split("/")
        parts = (parts + ["-"] * 4)[:4]
        con.execute("INSERT INTO trial_colour VALUES(?,?,?,?,?)", (row[0],) + tuple(parts))
    con.executescript(
        """
        CREATE INDEX idx_trial_colour_pe  ON trial_colour(pe);
        CREATE INDEX idx_trial_colour_v28 ON trial_colour(var_r28);
        """
    )

    # merge ETL rows produced by tools/run_and_log.py (if present)
    merged = _merge_extras(con)
    # FTS
    con.executescript(
        """
        CREATE VIRTUAL TABLE fts_trials USING fts5(label, category, edit_from, edit_to, notes, content='trials', content_rowid='trial_id');
        INSERT INTO fts_trials(rowid,label,category,edit_from,edit_to,notes)
          SELECT trial_id,label,category,edit_from,edit_to,notes FROM trials;
        CREATE VIRTUAL TABLE fts_findings USING fts5(statement, evidence, kind, content='findings', content_rowid='finding_id');
        INSERT INTO fts_findings(rowid,statement,evidence,kind)
          SELECT finding_id,statement,evidence,kind FROM findings;
        CREATE VIRTUAL TABLE fts_agents USING fts5(angle, summary, key_finding, content='agents');
        INSERT INTO fts_agents(rowid,angle,summary,key_finding)
          SELECT rowid,angle,summary,key_finding FROM agents;
        """
    )
    con.commit()
    con.close()

    def dump(table, path):
        con = sqlite3.connect(db)
        con.row_factory = sqlite3.Row
        with open(os.path.join(HERE, path), "w", encoding="utf-8") as fh:
            for row in con.execute("SELECT * FROM %s" % table):
                fh.write(json.dumps(dict(row), ensure_ascii=False) + "\n")
        con.close()

    dump("agents", "agents.jsonl")
    dump("trials", "trials.jsonl")
    dump("regalloc", "regalloc.jsonl")
    dump("findings", "findings.jsonl")
    dump("rules", "rules.jsonl")
    dump("harvest_methods", "harvest_methods.jsonl")
    dump("tools_built", "tools_built.jsonl")
    dump("proofs", "proofs.jsonl")
    dump("processes", "processes.jsonl")
    dump("comparisons", "comparisons.jsonl")

    con = sqlite3.connect(db)
    counts = {t: con.execute("SELECT count(*) FROM %s" % t).fetchone()[0]
              for t in ("agents", "trials", "regalloc", "findings", "rules",
                        "harvest_methods", "tools_built", "proofs", "processes", "comparisons")}
    con.close()
    extra_note = ("; extras merged " + ", ".join(
        "%s=%d" % (k, v) for k, v in merged.items())) if merged else ""
    print("wrote subagents.db + *.jsonl (agents=%d trials=%d regalloc=%d "
          "findings=%d rules=%d methods=%d tools=%d proofs=%d processes=%d comparisons=%d)%s"
          % (counts["agents"], counts["trials"], counts["regalloc"],
             counts["findings"], counts["rules"], counts["harvest_methods"],
             counts["tools_built"], counts["proofs"], counts["processes"],
             counts["comparisons"], extra_note))


if __name__ == "__main__":
    build()
