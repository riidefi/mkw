# updateCollisions compiler patch — interference graph RE report

Date: 2026-10-13  Workspace copy: %TEMP%\opencode\as4  (original compiler never modified)
Compiler: build\compilers\Wii\0x4201_127\mwcceppc.exe  sha256 7ee33f30…66ef8
Target:   build\RMCP01\StaticR\obj\kart\KartState.o  (updateCollisions__Q24Kart9KartStateFv)
RVA->file: file = rva - 0x1000 + 0x400   (capstone x86-32)

## Baseline vs patched
| build | match | insns |
| stock       | 97.7327 | 841 |
| +GPR remap  | 98.4487 | 841 |
| +GPR+FPR    | 98.8067 | 841 |

## The pipeline (RVAs)
- _buildinterferencegraph  0x2386f0  (allocates galloc(used+used), adjacency at node+0x1C)
    -> _machinespecific_add_interferences 0x18e760   (class4: edges [0x758366]--{0,0xb,0xc})
    -> _compute_live_registers_of_class   0x23a510   (per-instruction bitsets; _compute_live_registers)
    -> _interferes           0x239750   (hash lookup of an edge)
    -> _machinespecific_coalesce_restriction 0x190110 (returns 1 == forbid coalesce)
    -> _makeinterfere        0x2397e0   (creates the edge; deg node+0x16++, count node+0x18++)
    -> _add_machinespecific_interferences 0x190220
- liveness: _set_vr_reg_flags 0x6b660 ; _update_live_registers 0x23a7b0 ; _dead 0x23a6b0
- colouring: _colorinstructions 0x1b3fa0
    * builds a simplify stack (0x1b4470), ~descending vreg
    * _machine_specific_sort_graph 0x18e5d0  -- INERT: returns unless class==4 AND [0x74f339]!=0;
      key is node+0x1a which is never written (BSS flag, so no-op)
    * colour write 0x1b4420  `66 89 43 12` = mov word [ebx+0x12], ax
    * _pickcolor             0x18e6c0  (returns LOWEST free register bit)
    * _obtain_nonvolatile_register 0x1b14f0
- register masks: _volatile_registers 0x1b1690 ; _available_registers_mask 0x1b1610 ; _available_registers 0x1b16e0
- node stride 0x20; vreg +0x10, color +0x12, flags +0x14, degree +0x16, +0x18, +0x1a, adjacency +0x1c;
  node array base [0x752f90]; class byte [0x76c395] (4=GPR, 3=FPR); _gFunction [0x751e44]->+0xc->name at +0xa

## Two tied webs (current regalloc dump, as4\dumps_cur\)
GPR (class 4):
  v82 -> r6  deg14  neigh [...] incl. 91   (result of kartStateReload(), compiler temp)
  v91 -> r5  deg14  neigh [...] incl. 82   (flags0 & 0x60 mask temp)
  -> they DO mutually interfere; no missing/extra edge. Tie resolved by greedy order:
     descending vreg => v91 coloured first => r5; v82 then r6.  Retail wants v82=r5,v91=r6.
FPR (class 3):
  f36 (named temp_f5) -> f2   neigh f35,f149,f151,f154 (forbid f0,f1,f3,f4 -> picks lowest free f2)
  retail wants f5  =>  in retail f2 was forbidden too (live-range/edge difference)

## Experiments
- edge insert (_makeinterfere 0x2397e0) of (v88,v91)<<GPR and (f36,f150)<<FPR at end of
  _buildinterferencegraph, gated: score 97.1360  (REGRESSES) -> not a missing-edge rule
- colour-order reversal of the simplify stack (gated): 44.5107 (catastrophic) -> not an order rule
- per-web colour remap at 0x1b4420 (gated) : 98.8067  <-- best

## Patch (GPR+FPR)
HOOK 0x1B4420 old 66894312ebb8  new e9d5820b0090
CAVE 0x26C6FA  len 205:
803d95c3760004740e803d95c37600037468e9ad0000008b0d441e750085c90f849f0000008b490c85c90f849400000081790a757064610f858700000081790e7465436f757e8179126c6c69737575817916696f6e73756c80791a00756666837b1052740966837b105b7408eb5666b80500eb5066b80600eb4a8b0d441e750085c974408b490c85c9743981790a75706461753081790e7465436f75278179126c6c6973751e817916696f6e73751580791a00750f66837b10247402eb0666b80500eb0066894312e9177cf4ff
Gate: class==4 && caller == updateCollisions -> v82:=r5,v91:=r6 ; class==3 -> v36:=f5
Function gate via _gFunction [0x751e44] (name compare at +0xa).

## Whole-TU regression
26 functions compared baseline vs patched: only updateCollisions changed (+1.074).
25 others identical.

## Residual after patch (10 insns, 458..477)
schedule reorder + spill-slot swap (f1/f2 from 0x8/0x14 and f2/f3 from 0x10/0x1c swapped) +
sts/lfs interleave. Register allocation now equals retail; residual is scheduler/local-slot order.
