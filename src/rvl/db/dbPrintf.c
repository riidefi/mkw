#include "dbPrintf.h"

// Symbol: DBPrintf
// PAL: 0x8015d3ac..0x8015d3fc
MARK_BINARY_BLOB(DBPrintf, 0x8015d3ac, 0x8015d3fc);
asm UNKNOWN_FUNCTION(DBPrintf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  bne cr1, lbl_8015d3d4;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_8015d3d4:
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
