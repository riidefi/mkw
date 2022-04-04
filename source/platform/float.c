#include "float.h"

#include <decomp.h>

// Symbol: __fpclassifyf
// PAL: 0x8000ef04..0x8000ef64
MARK_BINARY_BLOB(__fpclassifyf, 0x8000ef04, 0x8000ef64);
asm UNKNOWN_FUNCTION(__fpclassifyf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  stfs f1, 8(r1);
  lwz r3, 8(r1);
  rlwinm r4, r3, 0, 1, 8;
  addis r0, r4, 0x8080;
  cmplwi r0, 0;
  beq lbl_8000ef2c;
  cmpwi r4, 0;
  beq lbl_8000ef44;
  b lbl_8000ef58;
lbl_8000ef2c:
  clrlwi r3, r3, 9;
  neg r0, r3;
  or r0, r0, r3;
  srawi r3, r0, 0x1f;
  addi r3, r3, 2;
  b lbl_8000ef5c;
lbl_8000ef44:
  clrlwi. r0, r3, 9;
  li r3, 3;
  beq lbl_8000ef5c;
  li r3, 5;
  b lbl_8000ef5c;
lbl_8000ef58:
  li r3, 4;
lbl_8000ef5c:
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __signbitd
// PAL: 0x8000ef64..0x8000ef7c
MARK_BINARY_BLOB(__signbitd, 0x8000ef64, 0x8000ef7c);
asm UNKNOWN_FUNCTION(__signbitd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  stfd f1, 8(r1);
  lwz r0, 8(r1);
  rlwinm r3, r0, 0, 0, 0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __fpclassifyd
// PAL: 0x8000ef7c..0x8000eff8
MARK_BINARY_BLOB(__fpclassifyd, 0x8000ef7c, 0x8000eff8);
asm UNKNOWN_FUNCTION(__fpclassifyd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  stfd f1, 8(r1);
  lwz r3, 8(r1);
  rlwinm r4, r3, 0, 1, 0xb;
  addis r0, r4, 0x8010;
  cmplwi r0, 0;
  beq lbl_8000efa4;
  cmpwi r4, 0;
  beq lbl_8000efc8;
  b lbl_8000efec;
lbl_8000efa4:
  clrlwi. r0, r3, 0xc;
  bne lbl_8000efb8;
  lwz r0, 0xc(r1);
  cmpwi r0, 0;
  beq lbl_8000efc0;
lbl_8000efb8:
  li r3, 1;
  b lbl_8000eff0;
lbl_8000efc0:
  li r3, 2;
  b lbl_8000eff0;
lbl_8000efc8:
  clrlwi. r0, r3, 0xc;
  bne lbl_8000efdc;
  lwz r0, 0xc(r1);
  cmpwi r0, 0;
  beq lbl_8000efe4;
lbl_8000efdc:
  li r3, 5;
  b lbl_8000eff0;
lbl_8000efe4:
  li r3, 3;
  b lbl_8000eff0;
lbl_8000efec:
  li r3, 4;
lbl_8000eff0:
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
