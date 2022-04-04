#include "mem_cpy.h"

// Symbol: __copy_longs_aligned
// PAL: 0x8000f360..0x8000f41c
MARK_BINARY_BLOB(__copy_longs_aligned, 0x8000f360, 0x8000f41c);
asm UNKNOWN_FUNCTION(__copy_longs_aligned) {
  // clang-format off
  nofralloc;
  neg r0, r3;
  addi r7, r4, -1;
  clrlwi. r6, r0, 0x1e;
  addi r3, r3, -1;
  beq lbl_8000f388;
  subf r5, r6, r5;
lbl_8000f378:
  lbzu r0, 1(r7);
  addic. r6, r6, -1;
  stbu r0, 1(r3);
  bne lbl_8000f378;
lbl_8000f388:
  rlwinm. r4, r5, 0x1b, 5, 0x1f;
  addi r6, r7, -3;
  addi r3, r3, -3;
  beq lbl_8000f3e0;
lbl_8000f398:
  lwz r0, 4(r6);
  addic. r4, r4, -1;
  stw r0, 4(r3);
  lwz r0, 8(r6);
  stw r0, 8(r3);
  lwz r0, 0xc(r6);
  stw r0, 0xc(r3);
  lwz r0, 0x10(r6);
  stw r0, 0x10(r3);
  lwz r0, 0x14(r6);
  stw r0, 0x14(r3);
  lwz r0, 0x18(r6);
  stw r0, 0x18(r3);
  lwz r0, 0x1c(r6);
  stw r0, 0x1c(r3);
  lwzu r0, 0x20(r6);
  stwu r0, 0x20(r3);
  bne lbl_8000f398;
lbl_8000f3e0:
  rlwinm. r4, r5, 0x1e, 0x1d, 0x1f;
  beq lbl_8000f3f8;
lbl_8000f3e8:
  lwzu r0, 4(r6);
  addic. r4, r4, -1;
  stwu r0, 4(r3);
  bne lbl_8000f3e8;
lbl_8000f3f8:
  clrlwi. r5, r5, 0x1e;
  addi r4, r6, 3;
  addi r3, r3, 3;
  beqlr;
lbl_8000f408:
  lbzu r0, 1(r4);
  addic. r5, r5, -1;
  stbu r0, 1(r3);
  bne lbl_8000f408;
  blr;
  // clang-format on
}

// Symbol: __copy_longs_rev_aligned
// PAL: 0x8000f41c..0x8000f4c4
MARK_BINARY_BLOB(__copy_longs_rev_aligned, 0x8000f41c, 0x8000f4c4);
asm UNKNOWN_FUNCTION(__copy_longs_rev_aligned) {
  // clang-format off
  nofralloc;
  add r6, r3, r5;
  add r4, r4, r5;
  clrlwi. r3, r6, 0x1e;
  beq lbl_8000f440;
  subf r5, r3, r5;
lbl_8000f430:
  lbzu r0, -1(r4);
  addic. r3, r3, -1;
  stbu r0, -1(r6);
  bne lbl_8000f430;
lbl_8000f440:
  rlwinm. r3, r5, 0x1b, 5, 0x1f;
  beq lbl_8000f490;
lbl_8000f448:
  lwz r0, -4(r4);
  addic. r3, r3, -1;
  stw r0, -4(r6);
  lwz r0, -8(r4);
  stw r0, -8(r6);
  lwz r0, -0xc(r4);
  stw r0, -0xc(r6);
  lwz r0, -0x10(r4);
  stw r0, -0x10(r6);
  lwz r0, -0x14(r4);
  stw r0, -0x14(r6);
  lwz r0, -0x18(r4);
  stw r0, -0x18(r6);
  lwz r0, -0x1c(r4);
  stw r0, -0x1c(r6);
  lwzu r0, -0x20(r4);
  stwu r0, -0x20(r6);
  bne lbl_8000f448;
lbl_8000f490:
  rlwinm. r3, r5, 0x1e, 0x1d, 0x1f;
  beq lbl_8000f4a8;
lbl_8000f498:
  lwzu r0, -4(r4);
  addic. r3, r3, -1;
  stwu r0, -4(r6);
  bne lbl_8000f498;
lbl_8000f4a8:
  clrlwi. r5, r5, 0x1e;
  beqlr;
lbl_8000f4b0:
  lbzu r0, -1(r4);
  addic. r5, r5, -1;
  stbu r0, -1(r6);
  bne lbl_8000f4b0;
  blr;
  // clang-format on
}

// Symbol: __copy_longs_unaligned
// PAL: 0x8000f4c4..0x8000f584
MARK_BINARY_BLOB(__copy_longs_unaligned, 0x8000f4c4, 0x8000f584);
asm UNKNOWN_FUNCTION(__copy_longs_unaligned) {
  // clang-format off
  nofralloc;
  neg r0, r3;
  addi r7, r4, -1;
  clrlwi. r6, r0, 0x1e;
  addi r3, r3, -1;
  beq lbl_8000f4ec;
  subf r5, r6, r5;
lbl_8000f4dc:
  lbzu r0, 1(r7);
  addic. r6, r6, -1;
  stbu r0, 1(r3);
  bne lbl_8000f4dc;
lbl_8000f4ec:
  addi r0, r7, 1;
  addi r4, r3, -3;
  clrlwi r10, r0, 0x1e;
  srwi r6, r5, 3;
  subf r7, r10, r7;
  rlwinm r11, r0, 3, 0x1b, 0x1c;
  lwzu r8, 1(r7);
  subfic r12, r11, 0x20;
lbl_8000f50c:
  lwz r9, 4(r7);
  slw r3, r8, r11;
  addic. r6, r6, -1;
  srw r0, r9, r12;
  or r0, r3, r0;
  stw r0, 4(r4);
  slw r3, r9, r11;
  lwzu r8, 8(r7);
  srw r0, r8, r12;
  or r0, r3, r0;
  stwu r0, 8(r4);
  bne lbl_8000f50c;
  rlwinm. r0, r5, 0, 0x1d, 0x1d;
  beq lbl_8000f558;
  lwzu r0, 4(r7);
  slw r3, r8, r11;
  srw r0, r0, r12;
  or r0, r3, r0;
  stwu r0, 4(r4);
lbl_8000f558:
  clrlwi. r5, r5, 0x1e;
  addi r6, r7, 3;
  addi r3, r4, 3;
  beqlr;
  subfic r0, r10, 4;
  subf r6, r0, r6;
lbl_8000f570:
  lbzu r0, 1(r6);
  addic. r5, r5, -1;
  stbu r0, 1(r3);
  bne lbl_8000f570;
  blr;
  // clang-format on
}

// Symbol: __copy_longs_rev_unaligned
// PAL: 0x8000f584..0x8000f630
MARK_BINARY_BLOB(__copy_longs_rev_unaligned, 0x8000f584, 0x8000f630);
asm UNKNOWN_FUNCTION(__copy_longs_rev_unaligned) {
  // clang-format off
  nofralloc;
  add r12, r3, r5;
  add r11, r4, r5;
  clrlwi. r3, r12, 0x1e;
  beq lbl_8000f5a8;
  subf r5, r3, r5;
lbl_8000f598:
  lbzu r0, -1(r11);
  addic. r3, r3, -1;
  stbu r0, -1(r12);
  bne lbl_8000f598;
lbl_8000f5a8:
  rlwinm r9, r11, 3, 0x1b, 0x1c;
  clrlwi r8, r11, 0x1e;
  subfic r10, r9, 0x20;
  srwi r4, r5, 3;
  subfic r0, r8, 4;
  add r11, r11, r0;
  lwzu r6, -4(r11);
lbl_8000f5c4:
  lwz r7, -4(r11);
  srw r0, r6, r10;
  addic. r4, r4, -1;
  slw r3, r7, r9;
  or r0, r3, r0;
  stw r0, -4(r12);
  srw r0, r7, r10;
  lwzu r6, -8(r11);
  slw r3, r6, r9;
  or r0, r3, r0;
  stwu r0, -8(r12);
  bne lbl_8000f5c4;
  rlwinm. r0, r5, 0, 0x1d, 0x1d;
  beq lbl_8000f610;
  lwzu r3, -4(r11);
  srw r0, r6, r10;
  slw r3, r3, r9;
  or r0, r3, r0;
  stwu r0, -4(r12);
lbl_8000f610:
  clrlwi. r5, r5, 0x1e;
  beqlr;
  add r11, r11, r8;
lbl_8000f61c:
  lbzu r0, -1(r11);
  addic. r5, r5, -1;
  stbu r0, -1(r12);
  bne lbl_8000f61c;
  blr;
  // clang-format on
}
