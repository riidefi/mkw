#!/usr/bin/env python3
"""hypotheses_uc.py -- retrieval-driven hypothesis batch for updateCollisions.

Each hypothesis is derived from an UN-CROSSED combination of the KB's reusable
rules/findings (see kb_retrieval.py).  The runner compiles each candidate in a
scratch dir (never touching src/) and reports objdiff match_percent.

Run from the harness dir:
    cd %TEMP%/opencode/perm
    python C:/Users/nnnn/Documents/mkwii/subagent_data/tools/hypotheses_uc.py
"""
import os
import sys

PERM = os.path.join(os.environ["TEMP"], "opencode", "perm")
sys.path.insert(0, PERM)
import probe as P  # noqa: E402

# --------------------------------------------------------------------------- #
# exact anchors in the current (93.4368) source body
# --------------------------------------------------------------------------- #
D_PE = "  f32* const pe = lbl_1_data_3918;\n"
D_PROXY = "  KartObjectProxy* proxy = mProxy;\n"
I_FLAGS0 = "  u32 flags0 = (*pproxy)->kartState()->field(0);\n"
I_V28 = "  s32 var_r28 = (flags0 & 0x40000) != 0;\n"
I_V27 = "  bool var_r27 = (flags0 & 0x60) != 0;\n"
I_RELOAD = "  (*pproxy)->kartStateReload()->field(0) &= 0xFFFBE39F;\n"
I_PROXYF = "  KartObjectProxy* proxyF = proxy;\n"
TAIL = "  proxyF->kartWheelPhysics(0);\n  proxyF->getPos();\n"
GM3 = "if (gameMode - 3 == 0) {"
PIDX_DECL = "          s32 playerIdx = proxyF->getPlayerIdx();\n"
PIDX_CALL = "(rm->raceMode, (u8)playerIdx)"


def H(name, desc, edits):
    return (name, desc, edits)


HYPOTHESES = [
    H("H1_v28_firstlocal",
      "R-VREG-BLOCKS x var_r28: hoist var_r28 as the first-declared local so its "
      "web joins the reverse-order block below the pool (target r28).",
      [(D_PE, "  s32 var_r28;\n" + D_PE),
       (I_V28, "  var_r28 = (flags0 & 0x40000) != 0;\n")]),

    H("H2_v28_afterpe",
      "R-VREG-BLOCKS x var_r28: declare var_r28 as a named local right after pe.",
      [(D_PE, D_PE + "  s32 var_r28;\n"),
       (I_V28, "  var_r28 = (flags0 & 0x40000) != 0;\n")]),

    H("H3_flags0_addr",
      "R-SPLIT x flags0: address-take the (non-rematerializable) loaded flags0 "
      "and read var_r27 through the pointer, forcing a second live web.",
      [(I_FLAGS0, I_FLAGS0 + "  u32* pflags0 = &flags0;\n"),
       (I_V27, "  bool var_r27 = (*pflags0 & 0x60) != 0;\n")]),

    H("H4_flags0_reload",
      "R-SPLIT x flags0: a second independent load of field(0) for var_r27 so "
      "it cannot be CSE'd/rematerialized against flags0.",
      [(I_V27, "  u32 flags0b = (*pproxy)->kartState()->field(0);\n"
               "  bool var_r27 = (flags0b & 0x60) != 0;\n")]),

    H("H5_pe_constptr",
      "type x pe: make the pointee const (const f32* const).",
      [(D_PE, "  const f32* const pe = lbl_1_data_3918;\n")]),

    H("H6_pe_addr_copy",
      "R-SPLIT x pe: address-take a source pointer (forces a stack home = "
      "non-rematerializable) then copy the value back into pe.",
      [(D_PE, "  f32* peSource = lbl_1_data_3918;\n"
              "  f32** ppe = &peSource;\n"
              "  f32* const pe = *ppe;\n")]),

    H("H7_pe_static_const",
      "R-SPLIT x pe: launder pe through a function-local static const pointer "
      "(memory load => non-rematerializable, long-lived).",
      [(D_PE, "  static f32* const pePtr = lbl_1_data_3918;\n"
              "  f32* const pe = pePtr;\n")]),

    H("H8_pe_static_mut",
      "R-SPLIT x pe: function-local static (mutable) pointer holding the base.",
      [(D_PE, "  static f32* pePtr = lbl_1_data_3918;\n"
              "  f32* pe = pePtr;\n")]),

    H("H9_proxyG_tail",
      "R-SPLIT x proxy: a THIRD web for the two tail calls (extends the winning "
      "proxyF split).",
      [(I_PROXYF, I_PROXYF + "  KartObjectProxy* proxyG = proxyF;\n"),
       (TAIL, "  proxyG->kartWheelPhysics(0);\n  proxyG->getPos();\n")]),

    H("H10_v28_volatile",
      "R-SPLIT x var_r28: volatile forces a stack home (non-rematerializable).",
      [(I_V28, "  volatile s32 var_r28 = (flags0 & 0x40000) != 0;\n")]),

    H("H11_gm_eq3_pidx_u8",
      "R-SPLIT x gameMode/playerIdx: gameMode==3 + a u8 playerIdx local to force "
      "the target's 4x clrlwi (the 4-instr size gap).",
      [(GM3, "if (gameMode == 3) {"),
       (PIDX_DECL, "          u8 playerIdx = (u8)proxyF->getPlayerIdx();\n"),
       (PIDX_CALL, "(rm->raceMode, playerIdx)")]),

    H("H12_v28_shiftmask",
      "expression x var_r28: (flags0 & 0x40000) >> 18 (int, not bool) to keep "
      "var_r28 in the local block.",
      [(I_V28, "  s32 var_r28 = (flags0 & 0x40000) >> 18;\n")]),

    H("H13_v28_notnot",
      "expression x var_r28: !! operator form.",
      [(I_V28, "  s32 var_r28 = !!(flags0 & 0x40000);\n")]),

    H("H14_pe_decl_last",
      "R-VREG-BLOCKS x pe: move the pe declaration to just before proxyF (last "
      "local => lowest block slot) - probes the block renumbering.",
      [(D_PE, ""),
       (I_PROXYF, D_PE + I_PROXYF)]),

    H("H15_gm_eq3_only",
      "expression x gameMode: gameMode == 3 only (isolates the cmpwi form).",
      [(GM3, "if (gameMode == 3) {")]),

    H("H16_proxyG_plus_v28shift",
      "coalescing x {proxy,var_r28}: proxyG tail split combined with the shift "
      "form of var_r28 (the only known pe-mover).",
      [(I_PROXYF, I_PROXYF + "  KartObjectProxy* proxyG = proxyF;\n"),
       (TAIL, "  proxyG->kartWheelPhysics(0);\n  proxyG->getPos();\n"),
       (I_V28, "  s32 var_r28 = (flags0 >> 18) & 1;\n")]),

    H("H17_pe_type_noop_reload",
      "R-SPLIT x pe: second pointer initialised from the SAME global via an "
      "opaque indirection (peF used only at pe[3]/pe+17 tail).",
      [(D_PE, D_PE + "  f32* peF = pe;\n"),
       ("f32 var_f1 = fabsf(temp_f31 * pe[3]);",
        "f32 var_f1 = fabsf(temp_f31 * peF[3]);"),
       ("s32 hwg = *((s32*)(pe + 17));",
        "s32 hwg = *((s32*)(peF + 17));")]),

    # --- gameMode / playerIdx 4-instruction size gap (target: cmpwi r5,3 ;
    #     mr r0,r3 ; 4x clrlwi r4,r0,24) -------------------------------- #
    H("H18_gm_commuted",
      "expression x gameMode: 3 == gameMode (probe cmpwi operand register).",
      [(GM3, "if (3 == gameMode) {")]),

    H("H19_gm_eq_pid_deref",
      "gameMode==3 + playerIdx read through a byte pointer (defeat clrlwi CSE).",
      [(GM3, "if (gameMode == 3) {"),
       (PIDX_CALL, "(rm->raceMode, *(u8*)&playerIdx)")]),

    H("H20_pid_deref",
      "playerIdx via *(u8*)&playerIdx at the 4 call sites.",
      [(PIDX_CALL, "(rm->raceMode, *(u8*)&playerIdx)")]),

    H("H21_pid_andff",
      "playerIdx via (u8)(playerIdx & 0xff) at the 4 call sites.",
      [(PIDX_CALL, "(rm->raceMode, (u8)(playerIdx & 0xff))")]),

    H("H22_pid_volatile_u8",
      "playerIdx as a volatile u8 local (forces separate byte materialisations).",
      [(PIDX_DECL, "          volatile u8 playerIdx = (u8)proxyF->getPlayerIdx();\n"),
       (PIDX_CALL, "(rm->raceMode, playerIdx)")]),

    H("H23_gm_eq3_u8_local",
      "gameMode==3 plus a u8 playerIdx local (target 4x clrlwi form).",
      [(GM3, "if (gameMode == 3) {"),
       (PIDX_DECL, "          u8 playerIdx = (u8)proxyF->getPlayerIdx();\n"),
       (PIDX_CALL, "(rm->raceMode, playerIdx)")]),

    H("H24_pid_split_two",
      "R-SPLIT x playerIdx: a second local for the 9/10 branch so the byte cast "
      "is materialised twice (not CSE'd).",
      [(PIDX_DECL, "          s32 playerIdx = proxyF->getPlayerIdx();\n"
                   "          s32 playerIdx9 = playerIdx;\n"),
       ("          } else if (!(gameMode != 9 && gameMode != 10)) {",
        "          } else if (!(gameMode != 9 && gameMode != 10)) {\n"
        "            playerIdx = playerIdx9;")]),
]


def main():
    jobs = []
    for name, desc, edits in HYPOTHESES:
        text = P.build(edits)
        jobs.append((name, text))
    print("jobs:", len(jobs), flush=True)
    res = P.run(jobs)
    desc_by_name = {name: desc for name, desc, _ in HYPOTHESES}
    print("\n--- summary (desc) ---")
    for name, val, note in res:
        print(f"{str(val):>10}  {name:<28} {note}")
        print(f"            {desc_by_name.get(name, '')}")
    return res


if __name__ == "__main__":
    main()
