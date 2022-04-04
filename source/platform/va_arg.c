#include "va_arg.h"

// Symbol: __va_arg
// PAL: 0x80021270..0x80021338
MARK_BINARY_BLOB(__va_arg, 0x80021270, 0x80021338);
asm UNKNOWN_FUNCTION(__va_arg) {
  // clang-format off
  nofralloc;
  lbz r7, 0(r3);
  cmpwi r4, 3;
  mr r6, r3;
  li r0, 8;
  extsb r7, r7;
  li r8, 4;
  li r9, 1;
  li r5, 0;
  li r10, 0;
  li r11, 4;
  bne lbl_800212b4;
  lbz r7, 1(r3);
  addi r6, r3, 1;
  li r8, 8;
  li r10, 0x20;
  extsb r7, r7;
  li r11, 8;
lbl_800212b4:
  cmpwi r4, 2;
  bne lbl_800212d4;
  clrlwi. r0, r7, 0x1f;
  li r8, 8;
  li r0, 7;
  beq lbl_800212d0;
  li r5, 1;
lbl_800212d0:
  li r9, 2;
lbl_800212d4:
  cmpw r7, r0;
  bge lbl_800212fc;
  add r7, r7, r5;
  lwz r0, 8(r3);
  mullw r5, r7, r11;
  add r3, r0, r10;
  add r0, r7, r9;
  stb r0, 0(r6);
  add r5, r5, r3;
  b lbl_80021324;
lbl_800212fc:
  li r0, 8;
  stb r0, 0(r6);
  addi r0, r8, -1;
  lwz r5, 4(r3);
  nor r6, r0, r0;
  add r5, r8, r5;
  addi r0, r5, -1;
  and r5, r6, r0;
  add r0, r5, r8;
  stw r0, 4(r3);
lbl_80021324:
  cmpwi r4, 0;
  bne lbl_80021330;
  lwz r5, 0(r5);
lbl_80021330:
  mr r3, r5;
  blr;
  // clang-format on
}
