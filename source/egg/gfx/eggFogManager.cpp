#include "eggFogManager.hpp"

extern "C" UNKNOWN_FUNCTION(unk_8006f440);
extern "C" UNKNOWN_FUNCTION(unk_80226f04);
extern "C" UNKNOWN_FUNCTION(unk_80227018);
extern "C" UNKNOWN_FUNCTION(__nw__FUl);
extern "C" UNKNOWN_FUNCTION(__nwa__FUl);

// Symbol: unk_802271bc
// PAL: 0x802271bc..0x8022725c
MARK_BINARY_BLOB(unk_802271bc, 0x802271bc, 0x8022725c);
asm UNKNOWN_FUNCTION(unk_802271bc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x802a;
  stw r0, 0x24(r1);
  li r0, 0;
  addi r5, r5, 0x3058;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r5, 0(r3);
  stb r0, 4(r3);
  sth r4, 8(r3);
  sth r4, 0xa(r3);
  rlwinm r3, r4, 2, 0xe, 0x1d;
  bl __nwa__FUl;
  stw r3, 0xc(r29);
  li r30, 0;
  li r31, 0;
  b lbl_80227230;
lbl_8022720c:
  li r3, 0x20;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_80227220;
  bl unk_80226f04;
lbl_80227220:
  lwz r4, 0xc(r29);
  addi r30, r30, 1;
  stwx r3, r4, r31;
  addi r31, r31, 4;
lbl_80227230:
  lhz r0, 8(r29);
  cmpw r30, r0;
  blt lbl_8022720c;
  lwz r31, 0x1c(r1);
  mr r3, r29;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022725c
// PAL: 0x8022725c..0x80227274
MARK_BINARY_BLOB(unk_8022725c, 0x8022725c, 0x80227274);
asm UNKNOWN_FUNCTION(unk_8022725c) {
  // clang-format off
  nofralloc;
  lbz r4, 4(r3);
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  bnelr;
  ori r0, r4, 4;
  stb r0, 4(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80227274
// PAL: 0x80227274..0x802272b8
MARK_BINARY_BLOB(unk_80227274, 0x80227274, 0x802272b8);
asm UNKNOWN_FUNCTION(unk_80227274) {
  // clang-format off
  nofralloc;
  li r7, 0;
  li r6, 0;
  b lbl_802272a8;
lbl_80227280:
  lwz r5, 0xc(r3);
  addi r7, r7, 1;
  lfs f0, 0x18(r4);
  lwzx r5, r5, r6;
  stfs f0, 0x10(r5);
  lwz r5, 0xc(r3);
  lfs f0, 0x1c(r4);
  lwzx r5, r5, r6;
  addi r6, r6, 4;
  stfs f0, 0x14(r5);
lbl_802272a8:
  lhz r0, 8(r3);
  cmpw r7, r0;
  blt lbl_80227280;
  blr;
  // clang-format on
}

// Symbol: unk_802272b8
// PAL: 0x802272b8..0x8022734c
MARK_BINARY_BLOB(unk_802272b8, 0x802272b8, 0x8022734c);
asm UNKNOWN_FUNCTION(unk_802272b8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  b lbl_80227310;
lbl_802272e8:
  mr r3, r29;
  mr r4, r30;
  bl unk_8006f440;
  stw r3, 8(r1);
  addi r4, r1, 8;
  lwz r3, 0xc(r28);
  lwzx r3, r3, r31;
  bl unk_80227018;
  addi r31, r31, 4;
  addi r30, r30, 1;
lbl_80227310:
  lhz r0, 8(r28);
  cmpw r30, r0;
  blt lbl_802272e8;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  lis r3, 0x8025;
  addi r3, r3, 0x7730;
  addi r3, r3, 5;
  blr;
  // clang-format on
}

// Symbol: unk_8022734c
// PAL: 0x8022734c..0x802273e8
MARK_BINARY_BLOB(unk_8022734c, 0x8022734c, 0x802273e8);
asm UNKNOWN_FUNCTION(unk_8022734c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lbz r0, 8(r4);
  stw r31, 0x1c(r1);
  cmpwi r0, 0;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_802273c8;
  lhz r5, 0x10(r4);
  lhz r0, 0xa(r3);
  cmplw r5, r0;
  blt lbl_8022738c;
  mr r5, r0;
lbl_8022738c:
  clrlwi r31, r5, 0x10;
  addi r30, r4, 0x14;
  li r29, 0;
  b lbl_802273bc;
lbl_8022739c:
  clrlwi r0, r29, 0x10;
  lwz r4, 0xc(r28);
  mulli r0, r0, 0x30;
  rlwinm r3, r29, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r30, r0;
  bl unk_8022746c;
  addi r29, r29, 1;
lbl_802273bc:
  clrlwi r0, r29, 0x10;
  cmplw r0, r31;
  blt lbl_8022739c;
lbl_802273c8:
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

// Symbol: unk_802273e8
// PAL: 0x802273e8..0x8022746c
MARK_BINARY_BLOB(unk_802273e8, 0x802273e8, 0x8022746c);
asm UNKNOWN_FUNCTION(unk_802273e8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lhz r31, 0xa(r3);
  stw r30, 0x18(r1);
  addi r30, r4, 0x14;
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
  sth r31, 0x10(r4);
  b lbl_8022743c;
lbl_8022741c:
  clrlwi r0, r29, 0x10;
  lwz r4, 0xc(r28);
  mulli r0, r0, 0x30;
  rlwinm r3, r29, 2, 0xe, 0x1d;
  lwzx r3, r4, r3;
  add r4, r30, r0;
  bl unk_8022747c;
  addi r29, r29, 1;
lbl_8022743c:
  clrlwi r0, r29, 0x10;
  cmplw r0, r31;
  blt lbl_8022741c;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  blr;
  // clang-format on
}

// Symbol: unk_8022746c
// PAL: 0x8022746c..0x8022747c
MARK_BINARY_BLOB(unk_8022746c, 0x8022746c, 0x8022747c);
asm UNKNOWN_FUNCTION(unk_8022746c) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: unk_8022747c
// PAL: 0x8022747c..0x80227664
MARK_BINARY_BLOB(unk_8022747c, 0x8022747c, 0x80227664);
asm UNKNOWN_FUNCTION(unk_8022747c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_24;
  li r27, 0;
  stw r27, 8(r1);
  mr r30, r3;
  mr r31, r4;
  stw r27, 0x10(r1);
  lbz r26, 8(r1);
  stw r27, 0x14(r1);
  lbz r25, 9(r1);
  lbz r24, 0xa(r1);
  lbz r12, 0xb(r1);
  lbz r11, 0x10(r1);
  lbz r10, 0x11(r1);
  lbz r9, 0x12(r1);
  lbz r8, 0x13(r1);
  lbz r7, 0x14(r1);
  lbz r6, 0x15(r1);
  lbz r5, 0x16(r1);
  lbz r0, 0x17(r1);
  stb r26, 0(r4);
  stb r25, 1(r4);
  stb r24, 2(r4);
  stb r12, 3(r4);
  stw r27, 4(r4);
  stb r11, 8(r4);
  stb r10, 9(r4);
  stb r9, 0xa(r4);
  stb r8, 0xb(r4);
  stb r7, 0xc(r4);
  stb r6, 0xd(r4);
  stb r5, 0xe(r4);
  stb r0, 0xf(r4);
  lwz r12, 0(r3);
  stw r27, 0xc(r1);
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
  li r24, 0;
lbl_80227544:
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  lbzx r0, r3, r24;
  addi r24, r24, 1;
  cmpwi r24, 4;
  stb r0, 0(r29);
  addi r29, r29, 1;
  blt lbl_80227544;
  li r0, 0;
  stw r0, 0x28(r1);
  mr r3, r30;
  mr r4, r31;
  stw r0, 0x2c(r1);
  lbz r24, 0x28(r1);
  stw r0, 0x30(r1);
  lbz r25, 0x29(r1);
  stw r0, 0x34(r1);
  lbz r26, 0x2a(r1);
  stw r0, 0x18(r1);
  lbz r27, 0x2b(r1);
  stw r0, 0x1c(r1);
  lfs f3, 0x18(r1);
  stw r0, 0x20(r1);
  lfs f2, 0x1c(r1);
  stw r0, 0x24(r1);
  lfs f1, 0x20(r1);
  lfs f0, 0x24(r1);
  lbz r28, 0x2c(r1);
  lbz r30, 0x2d(r1);
  lbz r29, 0x2e(r1);
  lbz r12, 0x2f(r1);
  lbz r11, 0x30(r1);
  lbz r10, 0x31(r1);
  lbz r9, 0x32(r1);
  lbz r8, 0x33(r1);
  lbz r7, 0x34(r1);
  lbz r6, 0x35(r1);
  lbz r5, 0x36(r1);
  lbz r0, 0x37(r1);
  stfs f3, 0x10(r31);
  stfs f2, 0x14(r31);
  stfs f1, 0x18(r31);
  stfs f0, 0x1c(r31);
  stb r24, 0x20(r31);
  stb r25, 0x21(r31);
  stb r26, 0x22(r31);
  stb r27, 0x23(r31);
  stb r28, 0x24(r31);
  stb r30, 0x25(r31);
  stb r29, 0x26(r31);
  stb r12, 0x27(r31);
  stb r11, 0x28(r31);
  stb r10, 0x29(r31);
  stb r9, 0x2a(r31);
  stb r8, 0x2b(r31);
  stb r7, 0x2c(r31);
  stb r6, 0x2d(r31);
  stb r5, 0x2e(r31);
  stb r0, 0x2f(r31);
  lwz r12, 0(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  addi r11, r1, 0x60;
  bl _restgpr_24;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: unk_80227664
// PAL: 0x80227664..0x802276c0
MARK_BINARY_BLOB(unk_80227664, 0x80227664, 0x802276c0);
asm UNKNOWN_FUNCTION(unk_80227664) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8022768c;
  cmpwi r4, 0;
  ble lbl_8022768c;
  bl __dl__FPv;
lbl_8022768c:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lhz r3, 0xa(r3);
  addi r0, r3, -1;
  mulli r3, r0, 0x30;
  addi r3, r3, 0x44;
  blr;
  li r3, 0;
  blr;
  // clang-format on
}
