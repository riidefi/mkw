#include "cxStreamingUncompression.h"

// Symbol: CXInitUncompContextLZ
// PAL: 0x8015bef0..0x8015bf24
MARK_BINARY_BLOB(CXInitUncompContextLZ, 0x8015bef0, 0x8015bf24);
asm UNKNOWN_FUNCTION(CXInitUncompContextLZ) {
  // clang-format off
  nofralloc;
  li r6, 0;
  li r5, 3;
  li r0, 8;
  stw r4, 0(r3);
  stw r6, 4(r3);
  stb r6, 0x11(r3);
  stb r6, 0x12(r3);
  stw r6, 0xc(r3);
  stb r5, 0x10(r3);
  stb r0, 0x13(r3);
  stb r6, 0x14(r3);
  stw r6, 8(r3);
  blr;
  // clang-format on
}

// Symbol: CXReadUncompLZ
// PAL: 0x8015bf24..0x8015c2e0
MARK_BINARY_BLOB(CXReadUncompLZ, 0x8015bf24, 0x8015c2e0);
asm UNKNOWN_FUNCTION(CXReadUncompLZ) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  stw r31, 0xc(r1);
  lbz r0, 0x13(r3);
  cmpwi r0, 0;
  beq lbl_8015c070;
  cmplwi r0, 8;
  bne lbl_8015bf74;
  lbz r6, 0(r4);
  rlwinm r0, r6, 0, 0x18, 0x1b;
  cmpwi r0, 0x10;
  beq lbl_8015bf58;
  li r3, -1;
  b lbl_8015c2d4;
lbl_8015bf58:
  clrlwi. r0, r6, 0x1c;
  stb r0, 0x14(r3);
  beq lbl_8015bf74;
  cmplwi r0, 1;
  beq lbl_8015bf74;
  li r3, -1;
  b lbl_8015c2d4;
lbl_8015bf74:
  lwz r11, 8(r3);
  mr r10, r5;
  mr r9, r4;
  li r12, 0;
  li r6, 0;
  b lbl_8015c024;
lbl_8015bf8c:
  lbz r7, 0x13(r3);
  addi r0, r7, -1;
  clrlwi r7, r0, 0x18;
  stb r0, 0x13(r3);
  cmplwi r7, 3;
  bgt lbl_8015bfc4;
  subfic r0, r7, 3;
  lbz r7, 0(r9);
  slwi r0, r0, 3;
  lwz r8, 4(r3);
  slw r0, r7, r0;
  or r0, r8, r0;
  stw r0, 4(r3);
  b lbl_8015bfe8;
lbl_8015bfc4:
  cmplwi r7, 6;
  bgt lbl_8015bfe8;
  subfic r0, r7, 6;
  lbz r7, 0(r9);
  slwi r0, r0, 3;
  lwz r8, 4(r3);
  slw r0, r7, r0;
  or r0, r8, r0;
  stw r0, 4(r3);
lbl_8015bfe8:
  lbz r0, 0x13(r3);
  addi r9, r9, 1;
  addi r12, r12, 1;
  cmplwi r0, 4;
  bne lbl_8015c00c;
  lwz r0, 4(r3);
  cmpwi r0, 0;
  ble lbl_8015c00c;
  stb r6, 0x13(r3);
lbl_8015c00c:
  addic. r10, r10, -1;
  bne lbl_8015c024;
  lbz r0, 0x13(r3);
  cmpwi r0, 0;
  beq lbl_8015c024;
  b lbl_8015c048;
lbl_8015c024:
  lbz r0, 0x13(r3);
  cmpwi r0, 0;
  bne lbl_8015bf8c;
  cmpwi r11, 0;
  ble lbl_8015c048;
  lwz r0, 4(r3);
  cmpw r11, r0;
  bge lbl_8015c048;
  stw r11, 4(r3);
lbl_8015c048:
  subf. r5, r12, r5;
  add r4, r4, r12;
  bne lbl_8015c070;
  lbz r0, 0x13(r3);
  cmpwi r0, 0;
  bne lbl_8015c068;
  lwz r3, 4(r3);
  b lbl_8015c2d4;
lbl_8015c068:
  li r3, -1;
  b lbl_8015c2d4;
lbl_8015c070:
  li r0, 0;
  li r6, 1;
  li r11, 3;
  li r8, 8;
  b lbl_8015c2a8;
  b lbl_8015c278;
lbl_8015c088:
  cmpwi r5, 0;
  bne lbl_8015c098;
  lwz r3, 4(r3);
  b lbl_8015c2d4;
lbl_8015c098:
  lbz r7, 0x11(r3);
  rlwinm. r7, r7, 0, 0x18, 0x18;
  bne lbl_8015c1bc;
  lbz r9, 0(r4);
  addi r5, r5, -1;
  lwz r7, 0(r3);
  addi r4, r4, 1;
  stb r9, 0(r7);
  addi r9, r7, 1;
  lwz r7, 4(r3);
  stw r9, 0(r3);
  addi r7, r7, -1;
  stw r7, 4(r3);
  b lbl_8015c254;
  b lbl_8015c1bc;
lbl_8015c0d4:
  lbz r9, 0x10(r3);
  lbz r7, 0x14(r3);
  addi r9, r9, -1;
  cmpwi r7, 0;
  stb r9, 0x10(r3);
  bne lbl_8015c104;
  lbz r7, 0(r4);
  addi r4, r4, 1;
  stb r0, 0x10(r3);
  addi r7, r7, 0x30;
  stw r7, 0xc(r3);
  b lbl_8015c1ac;
lbl_8015c104:
  clrlwi r7, r9, 0x18;
  cmpwi r7, 1;
  beq lbl_8015c17c;
  bge lbl_8015c120;
  cmpwi r7, 0;
  bge lbl_8015c198;
  b lbl_8015c1ac;
lbl_8015c120:
  cmpwi r7, 3;
  bge lbl_8015c1ac;
  lbz r7, 0(r4);
  addi r4, r4, 1;
  srawi r9, r7, 4;
  stw r7, 0xc(r3);
  cmpwi r9, 1;
  bne lbl_8015c150;
  rlwinm r7, r7, 0x10, 0xc, 0xf;
  addi r7, r7, 0x1110;
  stw r7, 0xc(r3);
  b lbl_8015c1ac;
lbl_8015c150:
  cmpwi r9, 0;
  bne lbl_8015c16c;
  rlwinm r7, r7, 8, 0x14, 0x17;
  stb r6, 0x10(r3);
  addi r7, r7, 0x110;
  stw r7, 0xc(r3);
  b lbl_8015c1ac;
lbl_8015c16c:
  addi r7, r7, 0x10;
  stb r0, 0x10(r3);
  stw r7, 0xc(r3);
  b lbl_8015c1ac;
lbl_8015c17c:
  lbz r7, 0(r4);
  addi r4, r4, 1;
  lwz r9, 0xc(r3);
  slwi r7, r7, 8;
  add r7, r9, r7;
  stw r7, 0xc(r3);
  b lbl_8015c1ac;
lbl_8015c198:
  lbz r7, 0(r4);
  addi r4, r4, 1;
  lwz r9, 0xc(r3);
  add r7, r9, r7;
  stw r7, 0xc(r3);
lbl_8015c1ac:
  addic. r5, r5, -1;
  bne lbl_8015c1bc;
  lwz r3, 4(r3);
  b lbl_8015c2d4;
lbl_8015c1bc:
  lbz r7, 0x10(r3);
  cmpwi r7, 0;
  bne lbl_8015c0d4;
  lwz r10, 0xc(r3);
  addi r5, r5, -1;
  lwz r12, 4(r3);
  srawi r9, r10, 4;
  lbz r7, 0(r4);
  cmpw r9, r12;
  rlwimi r7, r10, 8, 0x14, 0x17;
  stw r9, 0xc(r3);
  addi r31, r7, 1;
  addi r4, r4, 1;
  stb r11, 0x10(r3);
  ble lbl_8015c248;
  lwz r7, 8(r3);
  cmpwi r7, 0;
  bne lbl_8015c20c;
  li r3, -4;
  b lbl_8015c2d4;
lbl_8015c20c:
  stw r12, 0xc(r3);
  b lbl_8015c248;
lbl_8015c214:
  lwz r9, 0(r3);
  subf r7, r31, r9;
  lbz r7, 0(r7);
  stb r7, 0(r9);
  lwz r10, 0(r3);
  lwz r9, 4(r3);
  lwz r7, 0xc(r3);
  addi r10, r10, 1;
  addi r9, r9, -1;
  stw r10, 0(r3);
  addi r7, r7, -1;
  stw r9, 4(r3);
  stw r7, 0xc(r3);
lbl_8015c248:
  lwz r7, 0xc(r3);
  cmpwi r7, 0;
  bgt lbl_8015c214;
lbl_8015c254:
  lwz r7, 4(r3);
  cmpwi r7, 0;
  beq lbl_8015c2b4;
  lbz r9, 0x11(r3);
  lbz r7, 0x12(r3);
  rlwinm r9, r9, 1, 0x18, 0x1e;
  addi r7, r7, -1;
  stb r9, 0x11(r3);
  stb r7, 0x12(r3);
lbl_8015c278:
  lbz r7, 0x12(r3);
  cmpwi r7, 0;
  bne lbl_8015c088;
  cmpwi r5, 0;
  bne lbl_8015c294;
  lwz r3, 4(r3);
  b lbl_8015c2d4;
lbl_8015c294:
  lbz r7, 0(r4);
  addi r5, r5, -1;
  stb r8, 0x12(r3);
  addi r4, r4, 1;
  stb r7, 0x11(r3);
lbl_8015c2a8:
  lwz r7, 4(r3);
  cmpwi r7, 0;
  bgt lbl_8015c278;
lbl_8015c2b4:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_8015c2d0;
  cmplwi r5, 0x20;
  ble lbl_8015c2d0;
  li r3, -3;
  b lbl_8015c2d4;
lbl_8015c2d0:
  li r3, 0;
lbl_8015c2d4:
  lwz r31, 0xc(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
