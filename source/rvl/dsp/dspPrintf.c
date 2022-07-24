#include "dspPrintf.h"

// Symbol: __DSP_debug_printf
// PAL: 0x8015d638..0x8015d688
MARK_BINARY_BLOB(__DSP_debug_printf, 0x8015d638, 0x8015d688);
asm UNKNOWN_FUNCTION(__DSP_debug_printf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  bne cr1, lbl_8015d660;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_8015d660:
  stw r3, 8(r1);
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}
