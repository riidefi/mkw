#include "eggLightManager.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(PSMTXInverse);
// PAL: 0x801a162c
extern UNKNOWN_FUNCTION(DCFlushRange);
// PAL: 0x80228490
extern UNKNOWN_FUNCTION(unk_80228490);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229e14
extern UNKNOWN_FUNCTION(unk_8022b6d4);
// PAL: 0x8022b7c0
extern UNKNOWN_FUNCTION(unk_8022b7c0);
// PAL: 0x8022b8d0
extern UNKNOWN_FUNCTION(unk_8022b8d0);
// PAL: 0x8022b9dc
extern UNKNOWN_FUNCTION(unk_8022b9dc);
// PAL: 0x8022bd04
extern UNKNOWN_FUNCTION(unk_8022bd04);
// PAL: 0x8022bf34
extern UNKNOWN_FUNCTION(unk_8022bf34);
// PAL: 0x8022c09c
extern UNKNOWN_FUNCTION(unk_8022c09c);
// PAL: 0x8022c1bc
extern UNKNOWN_FUNCTION(egglightsomething);
// PAL: 0x8022e7bc
extern UNKNOWN_FUNCTION(unk_8022e7bc);
// PAL: 0x8022ece0
extern UNKNOWN_FUNCTION(unk_8022ece0);
}

extern u8 unk_80388d81, unk_80388d82, unk_80388d83;
extern u8 unk_80388d80, unk_80388b40;
extern float unk_80388d84, unk_80388d88;
extern double unk_80388d90;

// Symbol: unk_8022a38c
// PAL: 0x8022a38c..0x8022a49c
MARK_BINARY_BLOB(unk_8022a38c, 0x8022a38c, 0x8022a49c);
asm UNKNOWN_FUNCTION(unk_8022a38c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r8, 0x802a;
  li r7, 0;
  stw r0, 0x14(r1);
  addi r8, r8, 0x3100;
  li r0, -1;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  stw r8, 0(r3);
  sth r4, 4(r3);
  sth r5, 6(r3);
  sth r4, 8(r3);
  sth r5, 0xa(r3);
  stw r7, 0xc(r3);
  stw r7, 0x10(r3);
  stb r6, 0x18(r3);
  sth r7, 0x1a(r3);
  stw r7, 0x20(r3);
  stw r7, 0x24(r3);
  sth r0, 0x28(r3);
  li r3, 0x1c;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8022a3fc;
  mr r4, r30;
  bl unk_8022e7bc;
lbl_8022a3fc:
  lbz r0, 0x18(r30);
  stw r3, 0x20(r30);
  slwi r3, r0, 9;
  bl __nwa__FUl;
  lhz r0, 4(r30);
  stw r3, 0x1c(r30);
  slwi r3, r0, 2;
  bl __nwa__FUl;
  lhz r0, 6(r30);
  stw r3, 0xc(r30);
  slwi r3, r0, 3;
  bl __nwa__FUl;
  stw r3, 0x10(r30);
  li r31, 0;
  b lbl_8022a468;
lbl_8022a438:
  li r3, 0xb0;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8022a44c;
  bl unk_8022b6d4;
lbl_8022a44c:
  lwz r4, 0xc(r30);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
  lwz r3, 0xc(r30);
  lwzx r3, r3, r0;
  sth r31, 4(r3);
  addi r31, r31, 1;
lbl_8022a468:
  lhz r0, 4(r30);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8022a438;
  mr r3, r30;
  bl unk_8022a4a8;
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8022a49c
// PAL: 0x8022a49c..0x8022a4a8
MARK_BINARY_BLOB(unk_8022a49c, 0x8022a49c, 0x8022a4a8);
asm UNKNOWN_FUNCTION(unk_8022a49c) {
  // clang-format off
  nofralloc;
  sth r4, 8(r3);
  sth r5, 0xa(r3);
  blr;
  // clang-format on
}

// Symbol: unk_8022a4a8
// PAL: 0x8022a4a8..0x8022a5bc
MARK_BINARY_BLOB(unk_8022a4a8, 0x8022a4a8, 0x8022a5bc);
asm UNKNOWN_FUNCTION(unk_8022a4a8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  li r29, 0;
  b lbl_8022a4f8;
lbl_8022a4cc:
  lwz r3, 0xc(r31);
  rlwinm r0, r29, 2, 0xe, 0x1d;
  lwzx r30, r3, r0;
  mr r3, r30;
  bl unk_8022b7c0;
  clrlwi. r0, r29, 0x10;
  beq lbl_8022a4f4;
  lhz r0, 0x76(r30);
  rlwinm r0, r0, 0, 0x10, 0x1e;
  sth r0, 0x76(r30);
lbl_8022a4f4:
  addi r29, r29, 1;
lbl_8022a4f8:
  lhz r0, 4(r31);
  clrlwi r3, r29, 0x10;
  cmplw r3, r0;
  blt lbl_8022a4cc;
  li r10, 0;
  li r4, 0;
  b lbl_8022a560;
lbl_8022a514:
  lbz r7, unk_80388d81;
  rlwinm r9, r10, 3, 0xd, 0x1c;
  lwz r0, 0x10(r31);
  addi r10, r10, 1;
  lbz r6, unk_80388d82;
  lbz r5, unk_80388d83;
  add r8, r0, r9;
  lbz r3, unk_80388d80;
  stbx r3, r9, r0;
  stb r7, 1(r8);
  stb r6, 2(r8);
  stb r5, 3(r8);
  lwz r0, 0x10(r31);
  stb r3, 8(r1);
  add r3, r0, r9;
  stb r7, 9(r1);
  stb r6, 0xa(r1);
  stb r5, 0xb(r1);
  stw r4, 4(r3);
lbl_8022a560:
  lhz r0, 6(r31);
  clrlwi r3, r10, 0x10;
  cmplw r3, r0;
  blt lbl_8022a514;
  addi r3, r2, -25696;
  li r0, 0;
  lbz r6, unk_80388b40;
  lbz r5, 1(r3);
  lbz r4, 2(r3);
  lbz r3, 3(r3);
  stb r6, 0x14(r31);
  stb r5, 0x15(r31);
  stb r4, 0x16(r31);
  stb r3, 0x17(r31);
  stb r0, 0x19(r31);
  sth r0, 0x1a(r31);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022a5bc
// PAL: 0x8022a5bc..0x8022a6b4
MARK_BINARY_BLOB(unk_8022a5bc, 0x8022a5bc, 0x8022a6b4);
asm UNKNOWN_FUNCTION(unk_8022a5bc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lhz r0, 0x1a(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8022a680;
  li r30, 0;
  b lbl_8022a65c;
lbl_8022a5f4:
  lwz r4, 0xc(r28);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  lwzx r31, r4, r0;
  lhz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8022a650;
  lhz r0, 6(r31);
  mr r3, r31;
  slwi r0, r0, 2;
  lwzx r4, r4, r0;
  lfs f0, 0x14(r4);
  stfs f0, 0x14(r31);
  lfs f0, 0x18(r4);
  stfs f0, 0x18(r31);
  lfs f0, 0x1c(r4);
  stfs f0, 0x1c(r31);
  lfs f0, 8(r4);
  stfs f0, 8(r31);
  lfs f0, 0xc(r4);
  stfs f0, 0xc(r31);
  lfs f0, 0x10(r4);
  stfs f0, 0x10(r31);
  bl egglightsomething;
lbl_8022a650:
  mr r3, r31;
  bl unk_8022b8d0;
  addi r30, r30, 1;
lbl_8022a65c:
  lhz r0, 4(r28);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8022a5f4;
  lhz r0, 0x1a(r28);
  lwz r3, 0x20(r28);
  ori r0, r0, 4;
  sth r0, 0x1a(r28);
  bl unk_8022ece0;
lbl_8022a680:
  cmpwi r29, 0;
  beq lbl_8022a694;
  mr r3, r28;
  mr r4, r29;
  bl unk_8022a7ac;
lbl_8022a694:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022a6b4
// PAL: 0x8022a6b4..0x8022a780
MARK_BINARY_BLOB(unk_8022a6b4, 0x8022a6b4, 0x8022a780);
asm UNKNOWN_FUNCTION(unk_8022a6b4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  rlwinm r0, r5, 9, 0xf, 0x16;
  stmw r26, 0x38(r1);
  mr r26, r3;
  mr r27, r4;
  mr r28, r6;
  li r29, 0;
  lhz r8, 0x1a(r3);
  lwz r7, 0x1c(r3);
  ori r8, r8, 8;
  stb r5, 0x19(r3);
  add r31, r7, r0;
  sth r8, 0x1a(r3);
  b lbl_8022a72c;
lbl_8022a6f4:
  lwz r3, 0xc(r26);
  rlwinm r30, r29, 2, 0xe, 0x1d;
  mr r4, r27;
  lwzx r3, r3, r30;
  bl unk_8022b9dc;
  clrlwi r0, r29, 0x10;
  cmplwi r0, 8;
  bge lbl_8022a728;
  lwz r3, 0xc(r26);
  rlwinm r0, r29, 6, 0xa, 0x19;
  add r4, r31, r0;
  lwzx r3, r3, r30;
  bl unk_8022bd04;
lbl_8022a728:
  addi r29, r29, 1;
lbl_8022a72c:
  lhz r0, 4(r26);
  clrlwi r3, r29, 0x10;
  cmplw r3, r0;
  blt lbl_8022a6f4;
  mr r3, r31;
  li r4, 0x200;
  bl DCFlushRange;
  cmpwi r28, 0;
  beq lbl_8022a76c;
  mr r3, r27;
  addi r4, r1, 8;
  bl PSMTXInverse;
  mr r3, r26;
  mr r4, r28;
  addi r5, r1, 8;
  bl unk_8022a870;
lbl_8022a76c:
  lmw r26, 0x38(r1);
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_8022a780
// PAL: 0x8022a780..0x8022a7ac
MARK_BINARY_BLOB(unk_8022a780, 0x8022a780, 0x8022a7ac);
asm UNKNOWN_FUNCTION(unk_8022a780) {
  // clang-format off
  nofralloc;
  lhz r4, 0x1a(r3);
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  beq lbl_8022a79c;
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  beq lbl_8022a79c;
  rlwinm r0, r4, 0, 0x1c, 0x1a;
  sth r0, 0x1a(r3);
lbl_8022a79c:
  lhz r0, 0x1a(r3);
  rlwinm r0, r0, 0, 0x1e, 0x1b;
  sth r0, 0x1a(r3);
  blr;
  // clang-format on
}

// Symbol: unk_8022a7ac
// PAL: 0x8022a7ac..0x8022a870
MARK_BINARY_BLOB(unk_8022a7ac, 0x8022a7ac, 0x8022a870);
asm UNKNOWN_FUNCTION(unk_8022a7ac) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  lhz r0, 0x1a(r3);
  stmw r27, 0x1c(r1);
  mr r31, r3;
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  addi r30, r4, 0x2878;
  beq lbl_8022a7e8;
  lwz r0, 0x24(r3);
  mr r3, r30;
  stw r0, 8(r1);
  addi r4, r1, 8;
  lha r5, 0x28(r31);
  bl unk_80228490;
lbl_8022a7e8:
  li r7, 0;
  li r5, 0;
  li r6, 0;
  b lbl_8022a814;
lbl_8022a7f8:
  lwz r4, 0x10(r31);
  addi r7, r7, 1;
  lwz r3, 8(r30);
  lwzx r0, r4, r6;
  addi r6, r6, 8;
  stwx r0, r3, r5;
  addi r5, r5, 4;
lbl_8022a814:
  lhz r0, 6(r31);
  cmpw r7, r0;
  blt lbl_8022a7f8;
  li r27, 0;
  li r29, 0;
  li r28, 0;
  b lbl_8022a850;
lbl_8022a830:
  lwz r3, 0xc(r31);
  lwz r0, 4(r30);
  lwzx r3, r3, r28;
  add r4, r0, r29;
  bl unk_8022bf34;
  addi r29, r29, 0x44;
  addi r28, r28, 4;
  addi r27, r27, 1;
lbl_8022a850:
  lhz r0, 4(r31);
  cmpw r27, r0;
  blt lbl_8022a830;
  lmw r27, 0x1c(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022a870
// PAL: 0x8022a870..0x8022a8f0
MARK_BINARY_BLOB(unk_8022a870, 0x8022a870, 0x8022a8f0);
asm UNKNOWN_FUNCTION(unk_8022a870) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  li r29, 0;
  li r31, 0;
  li r30, 0;
  b lbl_8022a8c0;
lbl_8022a89c:
  lwz r3, 0xc(r26);
  mr r5, r28;
  lwz r0, 0x287c(r27);
  lwzx r3, r3, r30;
  add r4, r0, r31;
  bl unk_8022c09c;
  addi r31, r31, 0x44;
  addi r30, r30, 4;
  addi r29, r29, 1;
lbl_8022a8c0:
  lhz r0, 4(r26);
  cmpw r29, r0;
  blt lbl_8022a89c;
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  lis r3, 0x8025;
  addi r3, r3, 0x7828;
  addi r3, r3, 7;
  blr;
  // clang-format on
}

// Symbol: unk_8022a8f0
// PAL: 0x8022a8f0..0x8022aee4
MARK_BINARY_BLOB(unk_8022a8f0, 0x8022a8f0, 0x8022aee4);
asm UNKNOWN_FUNCTION(unk_8022a8f0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  lbz r0, 8(r4);
  stmw r22, 8(r1);
  mr r29, r3;
  cmpwi r0, 0;
  addi r30, r4, 0x10;
  beq lbl_8022a928;
  cmpwi r0, 1;
  beq lbl_8022a9e8;
  cmpwi r0, 2;
  beq lbl_8022ac6c;
  b lbl_8022aed0;
lbl_8022a928:
  lhz r4, 0(r30);
  lhz r0, 4(r3);
  cmplw r4, r0;
  blt lbl_8022a93c;
  mr r4, r0;
lbl_8022a93c:
  clrlwi r22, r4, 0x10;
  addi r23, r30, 0x20;
  li r24, 0;
  b lbl_8022a96c;
lbl_8022a94c:
  clrlwi r0, r24, 0x10;
  lwz r4, 0xc(r29);
  mulli r0, r0, 0x50;
  rlwinm r3, r24, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r23, r0;
  bl unk_8022b414;
  addi r24, r24, 1;
lbl_8022a96c:
  clrlwi r0, r24, 0x10;
  cmplw r0, r22;
  blt lbl_8022a94c;
  lwz r3, 0x10(r29);
  addi r5, r2, -25696;
  lbz r0, 4(r30);
  stb r0, 0(r3);
  lbz r0, 5(r30);
  stb r0, 1(r3);
  lbz r0, 6(r30);
  stb r0, 2(r3);
  lbz r0, 7(r30);
  stb r0, 3(r3);
  lbz r3, 8(r30);
  lwz r4, 0x10(r29);
  lbz r0, 9(r30);
  stb r3, 8(r4);
  lbz r3, 0xa(r30);
  stb r0, 9(r4);
  lbz r0, 0xb(r30);
  stb r3, 0xa(r4);
  lbz r6, unk_80388b40;
  stb r0, 0xb(r4);
  lbz r4, 1(r5);
  lbz r3, 2(r5);
  lbz r0, 3(r5);
  stb r6, 0x14(r29);
  stb r4, 0x15(r29);
  stb r3, 0x16(r29);
  stb r0, 0x17(r29);
  b lbl_8022aed0;
lbl_8022a9e8:
  lhz r4, 0(r30);
  lhz r0, 4(r3);
  cmplw r4, r0;
  blt lbl_8022a9fc;
  mr r4, r0;
lbl_8022a9fc:
  lhz r5, 6(r3);
  clrlwi r31, r4, 0x10;
  li r0, 8;
  cmplwi r5, 8;
  bgt lbl_8022aa14;
  mr r0, r5;
lbl_8022aa14:
  clrlwi r6, r0, 0x10;
  li r7, 0;
  cmpwi cr1, r6, 0;
  ble cr1, lbl_8022ac10;
  cmpwi r6, 8;
  addi r8, r6, -8;
  ble lbl_8022abc0;
  li r5, 0;
  blt cr1, lbl_8022aa4c;
  lis r4, 0x8000;
  addi r0, r4, -2;
  cmpw r6, r0;
  bgt lbl_8022aa4c;
  li r5, 1;
lbl_8022aa4c:
  cmpwi r5, 0;
  beq lbl_8022abc0;
  addi r0, r8, 7;
  mr r5, r30;
  srwi r0, r0, 3;
  li r4, 0;
  mtctr r0;
  cmpwi r8, 0;
  ble lbl_8022abc0;
lbl_8022aa70:
  lwz r0, 0x10(r3);
  addi r7, r7, 8;
  lbz r8, 4(r5);
  add r9, r0, r4;
  lbz r0, 5(r5);
  stb r8, 0(r9);
  lbz r8, 6(r5);
  stb r0, 1(r9);
  lbz r0, 7(r5);
  stb r8, 2(r9);
  lbz r10, 8(r5);
  stb r0, 3(r9);
  lbz r9, 9(r5);
  lwz r0, 0x10(r3);
  lbz r8, 0xa(r5);
  add r11, r0, r4;
  lbz r0, 0xb(r5);
  stb r10, 8(r11);
  lbz r10, 0xc(r5);
  stb r9, 9(r11);
  lbz r9, 0xd(r5);
  stb r8, 0xa(r11);
  lbz r8, 0xe(r5);
  stb r0, 0xb(r11);
  lbz r0, 0xf(r5);
  lwz r11, 0x10(r3);
  lbz r23, 0x10(r5);
  add r22, r11, r4;
  lbz r24, 0x11(r5);
  stb r10, 0x10(r22);
  lbz r12, 0x12(r5);
  stb r9, 0x11(r22);
  lbz r11, 0x13(r5);
  stb r8, 0x12(r22);
  lbz r10, 0x14(r5);
  stb r0, 0x13(r22);
  lbz r9, 0x15(r5);
  lwz r0, 0x10(r3);
  lbz r8, 0x16(r5);
  add r22, r0, r4;
  lbz r0, 0x17(r5);
  stb r23, 0x18(r22);
  lbz r23, 0x18(r5);
  stb r24, 0x19(r22);
  lbz r24, 0x19(r5);
  stb r12, 0x1a(r22);
  lbz r25, 0x1a(r5);
  stb r11, 0x1b(r22);
  lbz r28, 0x1b(r5);
  lwz r11, 0x10(r3);
  lbz r27, 0x1c(r5);
  add r22, r11, r4;
  lbz r26, 0x1d(r5);
  stb r10, 0x20(r22);
  lbz r12, 0x1e(r5);
  stb r9, 0x21(r22);
  lbz r11, 0x1f(r5);
  stb r8, 0x22(r22);
  lbz r10, 0x20(r5);
  stb r0, 0x23(r22);
  lbz r9, 0x21(r5);
  lwz r0, 0x10(r3);
  lbz r8, 0x22(r5);
  add r22, r0, r4;
  lbz r0, 0x23(r5);
  stb r23, 0x28(r22);
  addi r5, r5, 0x20;
  stb r24, 0x29(r22);
  stb r25, 0x2a(r22);
  stb r28, 0x2b(r22);
  lwz r28, 0x10(r3);
  add r23, r28, r4;
  stb r27, 0x30(r23);
  stb r26, 0x31(r23);
  stb r12, 0x32(r23);
  stb r11, 0x33(r23);
  lwz r11, 0x10(r3);
  add r11, r11, r4;
  addi r4, r4, 0x40;
  stb r10, 0x38(r11);
  stb r9, 0x39(r11);
  stb r8, 0x3a(r11);
  stb r0, 0x3b(r11);
  bdnz lbl_8022aa70;
lbl_8022abc0:
  slwi r4, r7, 2;
  subf r0, r7, r6;
  slwi r5, r7, 3;
  add r8, r30, r4;
  mtctr r0;
  cmpw r7, r6;
  bge lbl_8022ac10;
lbl_8022abdc:
  lwz r0, 0x10(r3);
  lbz r4, 4(r8);
  add r6, r0, r5;
  lbz r0, 5(r8);
  stb r4, 0(r6);
  addi r5, r5, 8;
  lbz r4, 6(r8);
  stb r0, 1(r6);
  lbz r0, 7(r8);
  addi r8, r8, 4;
  stb r4, 2(r6);
  stb r0, 3(r6);
  bdnz lbl_8022abdc;
lbl_8022ac10:
  lbz r6, 0x24(r30);
  addi r22, r30, 0x38;
  lbz r5, 0x25(r30);
  li r23, 0;
  lbz r4, 0x26(r30);
  lbz r0, 0x27(r30);
  stb r6, 0x14(r3);
  stb r5, 0x15(r3);
  stb r4, 0x16(r3);
  stb r0, 0x17(r3);
  b lbl_8022ac5c;
lbl_8022ac3c:
  clrlwi r0, r23, 0x10;
  lwz r4, 0xc(r29);
  mulli r0, r0, 0x50;
  rlwinm r3, r23, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r22, r0;
  bl unk_8022b414;
  addi r23, r23, 1;
lbl_8022ac5c:
  clrlwi r0, r23, 0x10;
  cmplw r0, r31;
  blt lbl_8022ac3c;
  b lbl_8022aed0;
lbl_8022ac6c:
  lhz r4, 0(r30);
  lhz r0, 8(r3);
  cmplw r4, r0;
  blt lbl_8022ac80;
  mr r4, r0;
lbl_8022ac80:
  lhz r5, 2(r30);
  clrlwi r23, r4, 0x10;
  lhz r0, 0xa(r3);
  cmplw r5, r0;
  blt lbl_8022ac98;
  mr r5, r0;
lbl_8022ac98:
  clrlwi r31, r5, 0x10;
  addi r22, r30, 0x18;
  li r24, 0;
  b lbl_8022acc8;
lbl_8022aca8:
  clrlwi r0, r24, 0x10;
  lwz r4, 0xc(r29);
  mulli r0, r0, 0x50;
  rlwinm r3, r24, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r22, r0;
  bl unk_8022b414;
  addi r24, r24, 1;
lbl_8022acc8:
  clrlwi r0, r24, 0x10;
  cmplw r0, r23;
  blt lbl_8022aca8;
  lhz r0, 0(r30);
  cmpwi r31, 0;
  lbz r4, 4(r30);
  li r5, 0;
  mulli r0, r0, 0x50;
  lbz r7, 5(r30);
  lbz r6, 6(r30);
  lbz r3, 7(r30);
  stb r4, 0x14(r29);
  add r4, r22, r0;
  stb r7, 0x15(r29);
  stb r6, 0x16(r29);
  stb r3, 0x17(r29);
  beq lbl_8022aed0;
  cmplwi r31, 8;
  addis r3, r31, 1;
  addi r3, r3, -8;
  ble lbl_8022ae84;
  clrlwi r3, r3, 0x10;
  addi r0, r3, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmplwi r3, 0;
  ble lbl_8022ae84;
lbl_8022ad34:
  lwz r6, 0x10(r29);
  rlwinm r0, r5, 3, 0xd, 0x1c;
  add r3, r4, r0;
  addi r5, r5, 8;
  add r7, r6, r0;
  lbzx r6, r4, r0;
  stb r6, 0(r7);
  lbz r6, 1(r3);
  stb r6, 1(r7);
  lbz r6, 2(r3);
  stb r6, 2(r7);
  lbz r6, 3(r3);
  stb r6, 3(r7);
  lbz r6, 8(r3);
  lwz r7, 0x10(r29);
  lbz r8, 9(r3);
  add r11, r7, r0;
  lbz r7, 0xa(r3);
  stb r6, 8(r11);
  lbz r6, 0xb(r3);
  stb r8, 9(r11);
  lbz r10, 0x10(r3);
  stb r7, 0xa(r11);
  lbz r9, 0x11(r3);
  stb r6, 0xb(r11);
  lbz r8, 0x12(r3);
  lwz r6, 0x10(r29);
  lbz r7, 0x13(r3);
  add r22, r6, r0;
  lbz r6, 0x18(r3);
  stb r10, 0x10(r22);
  lbz r12, 0x19(r3);
  stb r9, 0x11(r22);
  lbz r11, 0x1a(r3);
  stb r8, 0x12(r22);
  lbz r10, 0x1b(r3);
  stb r7, 0x13(r22);
  lbz r9, 0x20(r3);
  lwz r7, 0x10(r29);
  lbz r8, 0x21(r3);
  add r22, r7, r0;
  lbz r7, 0x22(r3);
  stb r6, 0x18(r22);
  lbz r6, 0x23(r3);
  stb r12, 0x19(r22);
  lbz r26, 0x28(r3);
  stb r11, 0x1a(r22);
  lbz r27, 0x29(r3);
  stb r10, 0x1b(r22);
  lbz r28, 0x2a(r3);
  lwz r10, 0x10(r29);
  lbz r30, 0x2b(r3);
  add r22, r10, r0;
  lbz r12, 0x30(r3);
  stb r9, 0x20(r22);
  lbz r11, 0x31(r3);
  stb r8, 0x21(r22);
  lbz r10, 0x32(r3);
  stb r7, 0x22(r22);
  lbz r9, 0x33(r3);
  stb r6, 0x23(r22);
  lbz r8, 0x38(r3);
  lwz r6, 0x10(r29);
  lbz r7, 0x39(r3);
  add r22, r6, r0;
  lbz r6, 0x3a(r3);
  stb r26, 0x28(r22);
  lbz r3, 0x3b(r3);
  stb r27, 0x29(r22);
  stb r28, 0x2a(r22);
  stb r30, 0x2b(r22);
  lwz r30, 0x10(r29);
  add r22, r30, r0;
  stb r12, 0x30(r22);
  stb r11, 0x31(r22);
  stb r10, 0x32(r22);
  stb r9, 0x33(r22);
  lwz r9, 0x10(r29);
  add r9, r9, r0;
  stb r8, 0x38(r9);
  stb r7, 0x39(r9);
  stb r6, 0x3a(r9);
  stb r3, 0x3b(r9);
  bdnz lbl_8022ad34;
lbl_8022ae84:
  clrlwi r3, r5, 0x10;
  subf r0, r3, r31;
  mtctr r0;
  cmplw r3, r31;
  bge lbl_8022aed0;
lbl_8022ae98:
  rlwinm r3, r5, 3, 0xd, 0x1c;
  lwz r0, 0x10(r29);
  add r6, r4, r3;
  addi r5, r5, 1;
  add r3, r0, r3;
  lbz r0, 0(r6);
  stb r0, 0(r3);
  lbz r0, 1(r6);
  stb r0, 1(r3);
  lbz r0, 2(r6);
  stb r0, 2(r3);
  lbz r0, 3(r6);
  stb r0, 3(r3);
  bdnz lbl_8022ae98;
lbl_8022aed0:
  lmw r22, 8(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022aee4
// PAL: 0x8022aee4..0x8022afd8
MARK_BINARY_BLOB(unk_8022aee4, 0x8022aee4, 0x8022afd8);
asm UNKNOWN_FUNCTION(unk_8022aee4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r30, r3;
  lhz r28, 8(r3);
  mr r31, r4;
  lhz r29, 0xa(r3);
  addi r27, r4, 0x28;
  li r26, 0;
  sth r28, 0x10(r4);
  sth r29, 0x12(r4);
  b lbl_8022af38;
lbl_8022af18:
  clrlwi r0, r26, 0x10;
  lwz r4, 0xc(r30);
  mulli r0, r0, 0x50;
  rlwinm r3, r26, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r27, r0;
  bl unk_8022b434;
  addi r26, r26, 1;
lbl_8022af38:
  clrlwi r0, r26, 0x10;
  cmplw r0, r28;
  blt lbl_8022af18;
  mulli r0, r28, 0x50;
  li r7, 0;
  li r3, 0;
  add r6, r27, r0;
  b lbl_8022af98;
lbl_8022af58:
  lwz r0, 0x10(r30);
  rlwinm r4, r7, 3, 0xd, 0x1c;
  add r5, r6, r4;
  addi r7, r7, 1;
  lbzux r0, r4, r0;
  stb r0, 0(r5);
  lbz r0, 1(r4);
  stb r0, 1(r5);
  lbz r0, 2(r4);
  stb r0, 2(r5);
  lbz r0, 3(r4);
  stb r0, 3(r5);
  stb r3, 7(r5);
  stb r3, 6(r5);
  stb r3, 5(r5);
  stb r3, 4(r5);
lbl_8022af98:
  clrlwi r0, r7, 0x10;
  cmplw r0, r29;
  blt lbl_8022af58;
  lbz r5, 0x14(r30);
  lbz r4, 0x15(r30);
  lbz r3, 0x16(r30);
  lbz r0, 0x17(r30);
  stb r5, 0x14(r31);
  stb r4, 0x15(r31);
  stb r3, 0x16(r31);
  stb r0, 0x17(r31);
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022afd8
// PAL: 0x8022afd8..0x8022b414
MARK_BINARY_BLOB(unk_8022afd8, 0x8022afd8, 0x8022b414);
asm UNKNOWN_FUNCTION(unk_8022afd8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stfd f31, 0x70(r1);
  psq_st f31, 120(r1), 0, 0;
  addi r11, r1, 0x70;
  bl _savegpr_24;
  lbz r0, 8(r4);
  lis r6, 0x4330;
  fmr f31, f1;
  stw r6, 0x20(r1);
  cmpwi r0, 2;
  mr r26, r3;
  stw r6, 0x28(r1);
  mr r27, r4;
  mr r28, r5;
  bne lbl_8022b3f4;
  lhz r6, 0x10(r4);
  lhz r0, 8(r3);
  cmplw r6, r0;
  blt lbl_8022b030;
  mr r6, r0;
lbl_8022b030:
  lhz r7, 0x12(r4);
  clrlwi r25, r6, 0x10;
  lhz r0, 0xa(r3);
  cmplw r7, r0;
  blt lbl_8022b048;
  mr r7, r0;
lbl_8022b048:
  clrlwi r31, r7, 0x10;
  addi r30, r4, 0x28;
  addi r29, r5, 0x28;
  li r24, 0;
  b lbl_8022b084;
lbl_8022b05c:
  clrlwi r0, r24, 0x10;
  lwz r3, 0xc(r26);
  mulli r5, r0, 0x50;
  fmr f1, f31;
  rlwinm r0, r24, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  add r4, r30, r5;
  add r5, r29, r5;
  bl unk_8022b424;
  addi r24, r24, 1;
lbl_8022b084:
  clrlwi r0, r24, 0x10;
  cmplw r0, r25;
  blt lbl_8022b05c;
  lfs f0, unk_80388d84;
  fcmpo cr0, f31, f0;
  bge lbl_8022b0c0;
  lbz r5, 0x14(r27);
  lbz r4, 0x15(r27);
  lbz r3, 0x16(r27);
  lbz r0, 0x17(r27);
  stb r5, 0x14(r1);
  stb r4, 0x15(r1);
  stb r3, 0x16(r1);
  stb r0, 0x17(r1);
  b lbl_8022b1f0;
lbl_8022b0c0:
  lfs f0, unk_80388d88;
  fcmpo cr0, f31, f0;
  ble lbl_8022b0f0;
  lbz r5, 0x14(r28);
  lbz r4, 0x15(r28);
  lbz r3, 0x16(r28);
  lbz r0, 0x17(r28);
  stb r5, 0x14(r1);
  stb r4, 0x15(r1);
  stb r3, 0x16(r1);
  stb r0, 0x17(r1);
  b lbl_8022b1f0;
lbl_8022b0f0:
  lbz r3, 0x14(r27);
  fsubs f9, f0, f31;
  stw r3, 0x24(r1);
  lbz r0, 0x14(r28);
  stw r0, 0x2c(r1);
  lfd f0, 0x20(r1);
  lbz r3, 0x15(r27);
  stw r3, 0x24(r1);
  lfd f4, 0x28(r1);
  lbz r0, 0x15(r28);
  stw r0, 0x2c(r1);
  lfd f8, unk_80388d90;
  lfd f3, 0x20(r1);
  lbz r3, 0x16(r27);
  fsubs f7, f0, f8;
  stw r3, 0x24(r1);
  fsubs f6, f4, f8;
  lfd f2, 0x28(r1);
  fsubs f5, f3, f8;
  lbz r0, 0x16(r28);
  stw r0, 0x2c(r1);
  fsubs f4, f2, f8;
  lfd f1, 0x20(r1);
  fmuls f7, f7, f9;
  lfd f0, 0x28(r1);
  fmuls f6, f6, f31;
  lbz r3, 0x17(r27);
  lbz r0, 0x17(r28);
  fsubs f3, f1, f8;
  stw r3, 0x24(r1);
  fsubs f2, f0, f8;
  fmuls f5, f5, f9;
  stw r0, 0x2c(r1);
  fmuls f4, f4, f31;
  lfd f1, 0x20(r1);
  fmuls f3, f3, f9;
  lfd f0, 0x28(r1);
  fsubs f1, f1, f8;
  fsubs f0, f0, f8;
  fmuls f2, f2, f31;
  fmuls f1, f1, f9;
  fmuls f0, f0, f31;
  fadds f2, f3, f2;
  fadds f4, f5, f4;
  fadds f6, f7, f6;
  fadds f0, f1, f0;
  fctiwz f3, f4;
  fctiwz f5, f6;
  fctiwz f2, f2;
  stfd f3, 0x38(r1);
  fctiwz f0, f0;
  stfd f5, 0x30(r1);
  lwz r4, 0x3c(r1);
  stfd f2, 0x40(r1);
  lwz r0, 0x34(r1);
  lwz r3, 0x44(r1);
  stfd f0, 0x48(r1);
  stb r0, 0x10(r1);
  lwz r0, 0x4c(r1);
  stb r4, 0x11(r1);
  stb r3, 0x12(r1);
  stb r0, 0x13(r1);
  lwz r0, 0x10(r1);
  stw r0, 0x14(r1);
lbl_8022b1f0:
  lhz r3, 0x10(r27);
  li r5, 0;
  lhz r0, 0x10(r28);
  lwz r4, 0x14(r1);
  mulli r3, r3, 0x50;
  stw r4, 0x1c(r1);
  lfs f2, unk_80388d84;
  lbz r4, 0x1c(r1);
  mulli r0, r0, 0x50;
  lbz r8, 0x1d(r1);
  add r3, r30, r3;
  lbz r7, 0x1e(r1);
  lbz r6, 0x1f(r1);
  stb r4, 0x14(r26);
  add r4, r29, r0;
  lfs f1, unk_80388d88;
  stb r8, 0x15(r26);
  lfd f0, unk_80388d90;
  stb r7, 0x16(r26);
  stb r6, 0x17(r26);
  mtctr r31;
  cmplwi r31, 0;
  ble lbl_8022b3f4;
lbl_8022b24c:
  fcmpo cr0, f31, f2;
  bge lbl_8022b280;
  rlwinm r0, r5, 3, 0xd, 0x1c;
  add r6, r3, r0;
  lbzx r9, r3, r0;
  lbz r8, 1(r6);
  lbz r7, 2(r6);
  lbz r6, 3(r6);
  stb r9, 0xc(r1);
  stb r8, 0xd(r1);
  stb r7, 0xe(r1);
  stb r6, 0xf(r1);
  b lbl_8022b3bc;
lbl_8022b280:
  fcmpo cr0, f31, f1;
  ble lbl_8022b2b4;
  rlwinm r0, r5, 3, 0xd, 0x1c;
  add r6, r4, r0;
  lbzx r9, r4, r0;
  lbz r8, 1(r6);
  lbz r7, 2(r6);
  lbz r6, 3(r6);
  stb r9, 0xc(r1);
  stb r8, 0xd(r1);
  stb r7, 0xe(r1);
  stb r6, 0xf(r1);
  b lbl_8022b3bc;
lbl_8022b2b4:
  rlwinm r0, r5, 3, 0xd, 0x1c;
  fsubs f9, f1, f31;
  lbzx r7, r3, r0;
  add r9, r3, r0;
  stw r7, 0x24(r1);
  add r8, r4, r0;
  lbzx r6, r4, r0;
  lfd f3, 0x20(r1);
  stw r6, 0x2c(r1);
  fsubs f5, f3, f0;
  lbz r7, 1(r9);
  lfd f3, 0x28(r1);
  stw r7, 0x24(r1);
  fsubs f4, f3, f0;
  lbz r6, 1(r8);
  stw r6, 0x2c(r1);
  fmuls f7, f5, f9;
  lfd f3, 0x20(r1);
  lbz r7, 2(r9);
  fsubs f5, f3, f0;
  stw r7, 0x24(r1);
  fmuls f6, f4, f31;
  lfd f3, 0x28(r1);
  lbz r6, 2(r8);
  fsubs f4, f3, f0;
  fadds f8, f7, f6;
  lfd f3, 0x20(r1);
  stw r6, 0x2c(r1);
  fmuls f7, f5, f9;
  fsubs f6, f3, f0;
  lfd f3, 0x28(r1);
  lbz r7, 3(r9);
  fmuls f4, f4, f31;
  lbz r6, 3(r8);
  fsubs f5, f3, f0;
  stw r6, 0x2c(r1);
  fmuls f6, f6, f9;
  fadds f7, f7, f4;
  stw r7, 0x24(r1);
  fmuls f5, f5, f31;
  lfd f3, 0x28(r1);
  fctiwz f8, f8;
  lfd f4, 0x20(r1);
  fsubs f3, f3, f0;
  stfd f8, 0x48(r1);
  fsubs f4, f4, f0;
  fctiwz f7, f7;
  lwz r6, 0x4c(r1);
  fmuls f3, f3, f31;
  fmuls f4, f4, f9;
  stfd f7, 0x40(r1);
  fadds f5, f6, f5;
  stb r6, 8(r1);
  fadds f3, f4, f3;
  lwz r6, 0x44(r1);
  fctiwz f4, f5;
  stb r6, 9(r1);
  fctiwz f3, f3;
  stfd f4, 0x38(r1);
  stfd f3, 0x30(r1);
  lwz r7, 0x3c(r1);
  lwz r6, 0x34(r1);
  stb r7, 0xa(r1);
  stb r6, 0xb(r1);
  lwz r6, 8(r1);
  stw r6, 0xc(r1);
lbl_8022b3bc:
  lwz r6, 0xc(r1);
  addi r5, r5, 1;
  stw r6, 0x18(r1);
  lwz r7, 0x10(r26);
  lbz r6, 0x18(r1);
  add r7, r7, r0;
  lbz r0, 0x19(r1);
  stb r6, 0(r7);
  lbz r6, 0x1a(r1);
  stb r0, 1(r7);
  lbz r0, 0x1b(r1);
  stb r6, 2(r7);
  stb r0, 3(r7);
  bdnz lbl_8022b24c;
lbl_8022b3f4:
  psq_l f31, 120(r1), 0, 0;
  addi r11, r1, 0x70;
  lfd f31, 0x70(r1);
  bl _restgpr_24;
  lwz r0, 0x84(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: unk_8022b414
// PAL: 0x8022b414..0x8022b424
MARK_BINARY_BLOB(unk_8022b414, 0x8022b414, 0x8022b424);
asm UNKNOWN_FUNCTION(unk_8022b414) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: unk_8022b424
// PAL: 0x8022b424..0x8022b434
MARK_BINARY_BLOB(unk_8022b424, 0x8022b424, 0x8022b434);
asm UNKNOWN_FUNCTION(unk_8022b424) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: unk_8022b434
// PAL: 0x8022b434..0x8022b66c
MARK_BINARY_BLOB(unk_8022b434, 0x8022b434, 0x8022b66c);
asm UNKNOWN_FUNCTION(unk_8022b434) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  addi r11, r1, 0x80;
  bl _savegpr_22;
  li r25, 0;
  stw r25, 8(r1);
  mr r30, r3;
  mr r31, r4;
  stw r25, 0x10(r1);
  lbz r24, 8(r1);
  stw r25, 0x14(r1);
  lbz r23, 9(r1);
  lbz r22, 0xa(r1);
  lbz r12, 0xb(r1);
  lbz r11, 0x10(r1);
  lbz r10, 0x11(r1);
  lbz r9, 0x12(r1);
  lbz r8, 0x13(r1);
  lbz r7, 0x14(r1);
  lbz r6, 0x15(r1);
  lbz r5, 0x16(r1);
  lbz r0, 0x17(r1);
  stb r24, 0(r4);
  stb r23, 1(r4);
  stb r22, 2(r4);
  stb r12, 3(r4);
  stw r25, 4(r4);
  stb r11, 8(r4);
  stb r10, 9(r4);
  stb r9, 0xa(r4);
  stb r8, 0xb(r4);
  stb r7, 0xc(r4);
  stb r6, 0xd(r4);
  stb r5, 0xe(r4);
  stb r0, 0xf(r4);
  lwz r12, 0(r3);
  stw r25, 0xc(r1);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  stb r3, 8(r31);
  mr r3, r30;
  lwz r12, 0(r30);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  stw r3, 4(r31);
  mr r29, r31;
  li r22, 0;
lbl_8022b4fc:
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  lbzx r0, r3, r22;
  addi r22, r22, 1;
  cmpwi r22, 4;
  stb r0, 0(r29);
  addi r29, r29, 1;
  blt lbl_8022b4fc;
  li r22, 0;
  stw r22, 0x18(r1);
  mr r3, r30;
  mr r4, r31;
  stw r22, 0x3c(r1);
  lbz r23, 0x18(r1);
  stw r22, 0x40(r1);
  lbz r24, 0x19(r1);
  stw r22, 0x54(r1);
  lbz r25, 0x1a(r1);
  stw r22, 0x1c(r1);
  lbz r26, 0x1b(r1);
  stw r22, 0x38(r1);
  lhz r27, 0x1c(r1);
  stw r22, 0x44(r1);
  lhz r28, 0x1e(r1);
  stw r22, 0x48(r1);
  lfs f4, 0x38(r1);
  stw r22, 0x4c(r1);
  lbz r30, 0x3c(r1);
  stw r22, 0x50(r1);
  lbz r29, 0x3d(r1);
  lbz r12, 0x3e(r1);
  lbz r11, 0x3f(r1);
  lbz r10, 0x40(r1);
  lbz r9, 0x41(r1);
  lbz r8, 0x42(r1);
  lbz r7, 0x43(r1);
  lfs f3, 0x44(r1);
  lfs f2, 0x48(r1);
  lfs f1, 0x4c(r1);
  lfs f0, 0x50(r1);
  lhz r6, 0x54(r1);
  lbz r5, 0x56(r1);
  lbz r0, 0x57(r1);
  stb r23, 0x10(r31);
  stb r24, 0x11(r31);
  stb r25, 0x12(r31);
  stb r26, 0x13(r31);
  sth r27, 0x14(r31);
  sth r28, 0x16(r31);
  stw r22, 0x18(r31);
  stw r22, 0x1c(r31);
  stw r22, 0x20(r31);
  stw r22, 0x24(r31);
  stw r22, 0x28(r31);
  stw r22, 0x2c(r31);
  stfs f4, 0x30(r31);
  stb r30, 0x34(r31);
  stb r29, 0x35(r31);
  stb r12, 0x36(r31);
  stb r11, 0x37(r31);
  stb r10, 0x38(r31);
  stb r9, 0x39(r31);
  stb r8, 0x3a(r31);
  stb r7, 0x3b(r31);
  stfs f3, 0x3c(r31);
  stfs f2, 0x40(r31);
  stfs f1, 0x44(r31);
  stfs f0, 0x48(r31);
  sth r6, 0x4c(r31);
  stb r5, 0x4e(r31);
  stb r0, 0x4f(r31);
  lwz r12, 0(r3);
  stw r22, 0x20(r1);
  lwz r12, 0xc(r12);
  stw r22, 0x24(r1);
  stw r22, 0x28(r1);
  stw r22, 0x2c(r1);
  stw r22, 0x30(r1);
  stw r22, 0x34(r1);
  mtctr r12;
  bctrl;
  addi r11, r1, 0x80;
  bl _restgpr_22;
  lwz r0, 0x84(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  li r3, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_8022b66c
// PAL: 0x8022b66c..0x8022b6d4
MARK_BINARY_BLOB(unk_8022b66c, 0x8022b66c, 0x8022b6d4);
asm UNKNOWN_FUNCTION(unk_8022b66c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8022b694;
  cmpwi r4, 0;
  ble lbl_8022b694;
  bl __dl__FPv;
lbl_8022b694:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lhz r4, 8(r3);
  lhz r0, 0xa(r3);
  addi r3, r4, -1;
  mulli r3, r3, 0x50;
  slwi r0, r0, 3;
  add r3, r0, r3;
  addi r3, r3, 0x78;
  blr;
  li r3, 2;
  blr;
  // clang-format on
}
