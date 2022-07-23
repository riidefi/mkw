#include "bd.h"

// Symbol: bdcpy
// PAL: 0x80131d90..0x80131dc4
MARK_BINARY_BLOB(bdcpy, 0x80131d90, 0x80131dc4);
asm UNKNOWN_FUNCTION(bdcpy) {
  // clang-format off
  nofralloc;
  lbz r9, 0(r4);
  lbz r8, 1(r4);
  lbz r7, 2(r4);
  lbz r6, 3(r4);
  lbz r5, 4(r4);
  lbz r0, 5(r4);
  stb r9, 0(r3);
  stb r8, 1(r3);
  stb r7, 2(r3);
  stb r6, 3(r3);
  stb r5, 4(r3);
  stb r0, 5(r3);
  blr;
  // clang-format on
}

// Symbol: bdcmp
// PAL: 0x80131dc4..0x80131e64
MARK_BINARY_BLOB(bdcmp, 0x80131dc4, 0x80131e64);
asm UNKNOWN_FUNCTION(bdcmp) {
  // clang-format off
  nofralloc;
  lbz r5, 0(r3);
  lbz r0, 0(r4);
  cmplw r5, r0;
  beq lbl_80131ddc;
  li r3, -1;
  blr;
lbl_80131ddc:
  lbz r5, 1(r3);
  addi r6, r3, 2;
  lbz r0, 1(r4);
  addi r3, r4, 2;
  cmplw r5, r0;
  beq lbl_80131dfc;
  li r3, -1;
  blr;
lbl_80131dfc:
  lbz r5, 0(r6);
  lbz r0, 0(r3);
  cmplw r5, r0;
  beq lbl_80131e14;
  li r3, -1;
  blr;
lbl_80131e14:
  lbz r5, 1(r6);
  lbz r0, 1(r3);
  cmplw r5, r0;
  beq lbl_80131e2c;
  li r3, -1;
  blr;
lbl_80131e2c:
  lbz r5, 2(r6);
  lbz r0, 2(r3);
  cmplw r5, r0;
  beq lbl_80131e44;
  li r3, -1;
  blr;
lbl_80131e44:
  lbz r5, 3(r6);
  lbz r0, 3(r3);
  cmplw r5, r0;
  beq lbl_80131e5c;
  li r3, -1;
  blr;
lbl_80131e5c:
  li r3, 0;
  blr;
  // clang-format on
}
