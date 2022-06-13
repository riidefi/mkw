#include "MultiDvdArchive.hpp"

extern "C" {
// PAL: 0x80518e10
extern UNKNOWN_FUNCTION(load__10DvdArchiveFPcPQ23EGG4HeapilPQ23EGG4HeapUl);
// PAL: 0x80518fbc
extern UNKNOWN_FUNCTION(loadBuffer__10DvdArchiveFPvUlPQ23EGG4Heapl);
// PAL: 0x805190f0
extern UNKNOWN_FUNCTION(SArchive_ripFile);
// PAL: 0x80519240
extern UNKNOWN_FUNCTION(clear__10DvdArchiveFv);
// PAL: 0x805192cc
extern UNKNOWN_FUNCTION(unmount__10DvdArchiveFv);
// PAL: 0x80519420
extern UNKNOWN_FUNCTION(getFile__10DvdArchiveFPcPi);
// PAL: 0x805195d8
extern UNKNOWN_FUNCTION(SArchive_loadOther);
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);
}

// Symbol: MultiDvdArchive_create
// PAL: 0x8052a098..0x8052a1c8
MARK_BINARY_BLOB(MultiDvdArchive_create, 0x8052a098, 0x8052a1c8);
asm UNKNOWN_FUNCTION(MultiDvdArchive_create) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addi r0, r3, -3;
  cmplwi r0, 5;
  stw r31, 0xc(r1);
  li r31, 0;
  ble lbl_8052a0d4;
  cmpwi r3, 0;
  beq lbl_8052a0f4;
  cmpwi r3, 1;
  beq lbl_8052a134;
  cmpwi r3, 2;
  beq lbl_8052a174;
  b lbl_8052a1b0;
lbl_8052a0d4:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  beq lbl_8052a0ec;
  li r4, 1;
  bl MultiDvdArchive_ct;
lbl_8052a0ec:
  mr r31, r3;
  b lbl_8052a1b0;
lbl_8052a0f4:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 2;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  b lbl_8052a1b0;
lbl_8052a134:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 4;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  b lbl_8052a1b0;
lbl_8052a174:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 2;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
lbl_8052a1b0:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a1c8
// PAL: 0x8052a1c8..0x8052a21c
MARK_BINARY_BLOB(unk_8052a1c8, 0x8052a1c8, 0x8052a21c);
asm UNKNOWN_FUNCTION(unk_8052a1c8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CourseMultiDvdArchive_init
// PAL: 0x8052a21c..0x8052a2a8
MARK_BINARY_BLOB(CourseMultiDvdArchive_init, 0x8052a21c, 0x8052a2a8);
asm UNKNOWN_FUNCTION(CourseMultiDvdArchive_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_init;
  lhz r0, 8(r31);
  lis r4, 0;
  addi r4, r4, 0;
  cmplwi r0, 1;
  ble lbl_8052a264;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a264:
  lhz r0, 8(r31);
  cmplwi r0, 2;
  ble lbl_8052a27c;
  lwz r3, 0x18(r31);
  li r0, 4;
  stw r0, 8(r3);
lbl_8052a27c:
  lhz r0, 8(r31);
  cmplwi r0, 3;
  ble lbl_8052a294;
  lwz r3, 0x18(r31);
  li r0, 4;
  stw r0, 0xc(r3);
lbl_8052a294:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a2a8
// PAL: 0x8052a2a8..0x8052a2fc
MARK_BINARY_BLOB(unk_8052a2a8, 0x8052a2a8, 0x8052a2fc);
asm UNKNOWN_FUNCTION(unk_8052a2a8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 2;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a2fc
// PAL: 0x8052a2fc..0x8052a36c
MARK_BINARY_BLOB(unk_8052a2fc, 0x8052a2fc, 0x8052a36c);
asm UNKNOWN_FUNCTION(unk_8052a2fc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_init;
  lis r3, 0;
  lhz r0, 8(r31);
  lwz r4, 0(r3);
  lis r3, 0;
  cmplwi r0, 1;
  lwz r0, 0x5c(r4);
  addi r3, r3, 0;
  slwi r0, r0, 2;
  lwzx r4, r3, r0;
  ble lbl_8052a358;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a358:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a36c
// PAL: 0x8052a36c..0x8052a3c0
MARK_BINARY_BLOB(unk_8052a36c, 0x8052a36c, 0x8052a3c0);
asm UNKNOWN_FUNCTION(unk_8052a36c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 2;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_ct;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a3c0
// PAL: 0x8052a3c0..0x8052a430
MARK_BINARY_BLOB(unk_8052a3c0, 0x8052a3c0, 0x8052a430);
asm UNKNOWN_FUNCTION(unk_8052a3c0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl MultiDvdArchive_init;
  lis r3, 0;
  lhz r0, 8(r31);
  lwz r4, 0(r3);
  lis r3, 0;
  cmplwi r0, 1;
  lwz r0, 0x5c(r4);
  addi r3, r3, 0;
  slwi r0, r0, 2;
  lwzx r4, r3, r0;
  ble lbl_8052a41c;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a41c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a430
// PAL: 0x8052a430..0x8052a488
MARK_BINARY_BLOB(unk_8052a430, 0x8052a430, 0x8052a488);
asm UNKNOWN_FUNCTION(unk_8052a430) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a46c;
  li r4, 0;
  bl MultiDvdArchive_dt;
  cmpwi r31, 0;
  ble lbl_8052a46c;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a46c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a488
// PAL: 0x8052a488..0x8052a4e0
MARK_BINARY_BLOB(unk_8052a488, 0x8052a488, 0x8052a4e0);
asm UNKNOWN_FUNCTION(unk_8052a488) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a4c4;
  li r4, 0;
  bl MultiDvdArchive_dt;
  cmpwi r31, 0;
  ble lbl_8052a4c4;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a4c4:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a4e0
// PAL: 0x8052a4e0..0x8052a538
MARK_BINARY_BLOB(unk_8052a4e0, 0x8052a4e0, 0x8052a538);
asm UNKNOWN_FUNCTION(unk_8052a4e0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a51c;
  li r4, 0;
  bl MultiDvdArchive_dt;
  cmpwi r31, 0;
  ble lbl_8052a51c;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a51c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: MultiDvdArchive_ct
// PAL: 0x8052a538..0x8052a648
MARK_BINARY_BLOB(MultiDvdArchive_ct, 0x8052a538, 0x8052a648);
asm UNKNOWN_FUNCTION(MultiDvdArchive_ct) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0;
  stw r0, 0x24(r1);
  mulli r5, r4, 0x24;
  addi r6, r6, 0;
  stmw r27, 0xc(r1);
  li r31, 0;
  mr r28, r4;
  mr r27, r3;
  stw r31, 4(r3);
  stw r6, 0(r3);
  sth r4, 8(r3);
  stw r31, 0x10(r3);
  addi r3, r5, 0x10;
  bl unk_805553b0;
  lis r4, 0;
  lis r5, 0;
  mr r7, r28;
  li r6, 0x24;
  addi r4, r4, 0;
  addi r5, r5, 0;
  bl unk_805553b0;
  stw r3, 4(r27);
  rlwinm r30, r28, 2, 0xe, 0x1d;
  mr r3, r30;
  bl unk_805553b0;
  stw r3, 0x10(r27);
  mr r3, r30;
  bl unk_805553b0;
  stw r3, 0x14(r27);
  mr r3, r30;
  bl unk_805553b0;
  stw r3, 0x18(r27);
  mr r3, r30;
  bl unk_805553b0;
  lis r4, 0;
  stw r3, 0xc(r27);
  lwz r30, 0(r4);
  li r28, 0;
  b lbl_8052a620;
lbl_8052a5dc:
  rlwinm r29, r28, 2, 0xe, 0x1d;
  li r3, 0x80;
  bl unk_805553b0;
  lwz r6, 0x10(r27);
  mr r4, r30;
  li r5, 0x80;
  stwx r3, r6, r29;
  lwz r3, 0x10(r27);
  lwzx r3, r3, r29;
  bl unk_805553b0;
  lwz r3, 0x18(r27);
  addi r28, r28, 1;
  stwx r31, r3, r29;
  lwz r3, 0xc(r27);
  stwx r31, r3, r29;
  lwz r3, 0x14(r27);
  stwx r31, r3, r29;
lbl_8052a620:
  lhz r0, 8(r27);
  clrlwi r3, r28, 0x10;
  cmplw r3, r0;
  blt lbl_8052a5dc;
  mr r3, r27;
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: MultiDvdArchive_init
// PAL: 0x8052a648..0x8052a6dc
MARK_BINARY_BLOB(MultiDvdArchive_init, 0x8052a648, 0x8052a6dc);
asm UNKNOWN_FUNCTION(MultiDvdArchive_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  lwz r30, 0(r4);
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
  b lbl_8052a6ac;
lbl_8052a67c:
  clrlwi r0, r29, 0x10;
  cmplw r0, r3;
  bge lbl_8052a6a8;
  lwz r3, 0x18(r28);
  rlwinm r0, r29, 2, 0xe, 0x1d;
  mr r4, r30;
  li r5, 0x80;
  stwx r31, r3, r0;
  lwz r3, 0x10(r28);
  lwzx r3, r3, r0;
  bl unk_805553b0;
lbl_8052a6a8:
  addi r29, r29, 1;
lbl_8052a6ac:
  lhz r3, 8(r28);
  clrlwi r0, r29, 0x10;
  cmplw r0, r3;
  blt lbl_8052a67c;
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

// Symbol: MultiDvdArchive_dt
// PAL: 0x8052a6dc..0x8052a760
MARK_BINARY_BLOB(MultiDvdArchive_dt, 0x8052a6dc, 0x8052a760);
asm UNKNOWN_FUNCTION(MultiDvdArchive_dt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a744;
  lis r5, 0;
  lis r4, 0;
  addi r5, r5, 0;
  stw r5, 0(r3);
  lwz r3, 4(r3);
  addi r4, r4, 0;
  bl unk_805553b0;
  lwz r3, 0x10(r30);
  bl unk_805553b0;
  lwz r3, 0x18(r30);
  bl unk_805553b0;
  lwz r3, 0xc(r30);
  bl unk_805553b0;
  cmpwi r31, 0;
  ble lbl_8052a744;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a744:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: MultiDvdArchive_getFile
// PAL: 0x8052a760..0x8052a800
MARK_BINARY_BLOB(MultiDvdArchive_getFile, 0x8052a760, 0x8052a800);
asm UNKNOWN_FUNCTION(MultiDvdArchive_getFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r29, r5;
  mr r27, r3;
  mr r28, r4;
  li r5, 0;
  lhz r6, 8(r3);
  addi r30, r6, -1;
  mulli r31, r30, 0x24;
  b lbl_8052a7e0;
lbl_8052a790:
  lwz r0, 4(r27);
  li r4, 0;
  add r3, r0, r31;
  lwz r0, 0x20(r3);
  cmpwi r0, 4;
  beq lbl_8052a7b4;
  lwz r0, 0x20(r3);
  cmpwi r0, 5;
  bne lbl_8052a7b8;
lbl_8052a7b4:
  li r4, 1;
lbl_8052a7b8:
  cmpwi r4, 0;
  beq lbl_8052a7d8;
  mr r4, r28;
  mr r5, r29;
  bl getFile__10DvdArchiveFPcPi;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8052a7e8;
lbl_8052a7d8:
  addi r31, r31, -36;
  addi r30, r30, -1;
lbl_8052a7e0:
  cmpwi r30, 0;
  bge lbl_8052a790;
lbl_8052a7e8:
  lmw r27, 0xc(r1);
  mr r3, r5;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8052a800
// PAL: 0x8052a800..0x8052a864
MARK_BINARY_BLOB(unk_8052a800, 0x8052a800, 0x8052a864);
asm UNKNOWN_FUNCTION(unk_8052a800) {
  // clang-format off
  nofralloc;
  lhz r6, 8(r3);
  li r7, 0;
  b lbl_8052a850;
lbl_8052a80c:
  clrlwi r0, r7, 0x10;
  lwz r5, 4(r3);
  mulli r0, r0, 0x24;
  li r4, 0;
  add r5, r5, r0;
  lwz r0, 0x20(r5);
  cmpwi r0, 4;
  beq lbl_8052a838;
  lwz r0, 0x20(r5);
  cmpwi r0, 5;
  bne lbl_8052a83c;
lbl_8052a838:
  li r4, 1;
lbl_8052a83c:
  cmpwi r4, 0;
  beq lbl_8052a84c;
  li r3, 1;
  blr;
lbl_8052a84c:
  addi r7, r7, 1;
lbl_8052a850:
  clrlwi r0, r7, 0x10;
  cmplw r0, r6;
  blt lbl_8052a80c;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: MultiDvdArchive_exists
// PAL: 0x8052a864..0x8052a954
MARK_BINARY_BLOB(MultiDvdArchive_exists, 0x8052a864, 0x8052a954);
asm UNKNOWN_FUNCTION(MultiDvdArchive_exists) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stmw r27, 0x10c(r1);
  lis r30, 0;
  mr r27, r3;
  mr r28, r4;
  li r29, 0;
  addi r31, r30, 0;
  b lbl_8052a92c;
lbl_8052a88c:
  lwz r3, 0x18(r27);
  rlwinm r0, r29, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8052a8b4;
  cmpwi r3, 1;
  beq lbl_8052a8d8;
  cmpwi r3, 2;
  beq lbl_8052a8f8;
  b lbl_8052a928;
lbl_8052a8b4:
  lwz r4, 0x10(r27);
  mr r6, r28;
  addi r3, r1, 8;
  addi r5, r30, 0;
  lwzx r7, r4, r0;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a910;
lbl_8052a8d8:
  lwz r6, 0x10(r27);
  addi r3, r1, 8;
  addi r5, r31, 5;
  li r4, 0x100;
  lwzx r6, r6, r0;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a910;
lbl_8052a8f8:
  lwz r3, 0x14(r27);
  lwzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_8052a910;
  li r3, 1;
  b lbl_8052a940;
lbl_8052a910:
  addi r3, r1, 8;
  bl unk_805553b0;
  cmpwi r3, -1;
  beq lbl_8052a928;
  li r3, 1;
  b lbl_8052a940;
lbl_8052a928:
  addi r29, r29, 1;
lbl_8052a92c:
  lhz r0, 8(r27);
  clrlwi r3, r29, 0x10;
  cmplw r3, r0;
  blt lbl_8052a88c;
  li r3, 0;
lbl_8052a940:
  lmw r27, 0x10c(r1);
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: MultiDvdArchive_load
// PAL: 0x8052a954..0x8052aa88
MARK_BINARY_BLOB(MultiDvdArchive_load, 0x8052a954, 0x8052aa88);
asm UNKNOWN_FUNCTION(MultiDvdArchive_load) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  lis r8, 0;
  stw r0, 0x134(r1);
  stmw r23, 0x10c(r1);
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  addi r31, r8, 0;
  li r30, 0;
  b lbl_8052aa64;
lbl_8052a988:
  lwz r3, 0x18(r25);
  rlwinm r24, r30, 2, 0xe, 0x1d;
  li r23, 1;
  lwzx r0, r3, r24;
  cmpwi r0, 0;
  beq lbl_8052a9b4;
  cmpwi r0, 1;
  beq lbl_8052a9d8;
  cmpwi r0, 2;
  beq lbl_8052a9f8;
  b lbl_8052aa60;
lbl_8052a9b4:
  lwz r4, 0x10(r25);
  mr r6, r26;
  addi r3, r1, 8;
  addi r5, r31, 8;
  lwzx r7, r4, r24;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a9fc;
lbl_8052a9d8:
  lwz r6, 0x10(r25);
  addi r3, r1, 8;
  addi r5, r31, 0xd;
  li r4, 0x100;
  lwzx r6, r6, r24;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a9fc;
lbl_8052a9f8:
  li r23, 0;
lbl_8052a9fc:
  cmpwi r23, 0;
  beq lbl_8052aa34;
  clrlwi r0, r30, 0x10;
  lwz r3, 4(r25);
  mulli r0, r0, 0x24;
  mr r5, r27;
  mr r8, r28;
  mr r9, r29;
  add r3, r3, r0;
  addi r4, r1, 8;
  li r6, 1;
  li r7, 8;
  bl load__10DvdArchiveFPcPQ23EGG4HeapilPQ23EGG4HeapUl;
  b lbl_8052aa60;
lbl_8052aa34:
  clrlwi r0, r30, 0x10;
  lwz r4, 0x14(r25);
  lwz r3, 0xc(r25);
  mulli r0, r0, 0x24;
  lwz r8, 4(r25);
  mr r6, r27;
  lwzx r5, r3, r24;
  li r7, 1;
  lwzx r4, r4, r24;
  add r3, r8, r0;
  bl loadBuffer__10DvdArchiveFPvUlPQ23EGG4Heapl;
lbl_8052aa60:
  addi r30, r30, 1;
lbl_8052aa64:
  lhz r0, 8(r25);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8052a988;
  lmw r23, 0x10c(r1);
  lwz r0, 0x134(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

// Symbol: unk_8052aa88
// PAL: 0x8052aa88..0x8052aae8
MARK_BINARY_BLOB(unk_8052aa88, 0x8052aa88, 0x8052aae8);
asm UNKNOWN_FUNCTION(unk_8052aa88) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_8052aac0;
lbl_8052aaa8:
  clrlwi r0, r31, 0x10;
  lwz r3, 4(r30);
  mulli r0, r0, 0x24;
  add r3, r3, r0;
  bl unmount__10DvdArchiveFv;
  addi r31, r31, 1;
lbl_8052aac0:
  lhz r0, 8(r30);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8052aaa8;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052aae8
// PAL: 0x8052aae8..0x8052ab6c
MARK_BINARY_BLOB(unk_8052aae8, 0x8052aae8, 0x8052ab6c);
asm UNKNOWN_FUNCTION(unk_8052aae8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  b lbl_8052ab3c;
lbl_8052ab18:
  clrlwi r0, r31, 0x10;
  lwz r3, 4(r28);
  mulli r4, r0, 0x24;
  lwz r0, 4(r29);
  mr r5, r30;
  add r3, r3, r4;
  add r4, r0, r4;
  bl SArchive_loadOther;
  addi r31, r31, 1;
lbl_8052ab3c:
  lhz r0, 8(r28);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8052ab18;
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

// Symbol: unk_8052ab6c
// PAL: 0x8052ab6c..0x8052ac40
MARK_BINARY_BLOB(unk_8052ab6c, 0x8052ab6c, 0x8052ac40);
asm UNKNOWN_FUNCTION(unk_8052ab6c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  lis r6, 0;
  stw r0, 0x124(r1);
  stmw r27, 0x10c(r1);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  addi r31, r6, 0;
  li r30, 0;
  b lbl_8052ac1c;
lbl_8052ab98:
  lwz r3, 0x18(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8052abb8;
  cmpwi r3, 1;
  beq lbl_8052abdc;
  b lbl_8052ac18;
lbl_8052abb8:
  lwz r4, 0x10(r27);
  mr r6, r28;
  addi r3, r1, 8;
  addi r5, r31, 0x10;
  lwzx r7, r4, r0;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052abf8;
lbl_8052abdc:
  lwz r6, 0x10(r27);
  addi r3, r1, 8;
  addi r5, r31, 0x15;
  li r4, 0x100;
  lwzx r6, r6, r0;
  crclr 6;
  bl unk_805553b0;
lbl_8052abf8:
  clrlwi r0, r30, 0x10;
  lwz r3, 4(r27);
  mulli r0, r0, 0x24;
  mr r5, r29;
  addi r4, r1, 8;
  li r6, 8;
  add r3, r3, r0;
  bl SArchive_ripFile;
lbl_8052ac18:
  addi r30, r30, 1;
lbl_8052ac1c:
  lhz r0, 8(r27);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8052ab98;
  lmw r27, 0x10c(r1);
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: unk_8052ac40
// PAL: 0x8052ac40..0x8052aca0
MARK_BINARY_BLOB(unk_8052ac40, 0x8052ac40, 0x8052aca0);
asm UNKNOWN_FUNCTION(unk_8052ac40) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_8052ac78;
lbl_8052ac60:
  clrlwi r0, r31, 0x10;
  lwz r3, 4(r30);
  mulli r0, r0, 0x24;
  add r3, r3, r0;
  bl clear__10DvdArchiveFv;
  addi r31, r31, 1;
lbl_8052ac78:
  lhz r0, 8(r30);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8052ac60;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052aca0
// PAL: 0x8052aca0..0x8052ad08
MARK_BINARY_BLOB(unk_8052aca0, 0x8052aca0, 0x8052ad08);
asm UNKNOWN_FUNCTION(unk_8052aca0) {
  // clang-format off
  nofralloc;
  lhz r6, 8(r3);
  li r7, 0;
  li r8, 0;
  b lbl_8052acf4;
lbl_8052acb0:
  clrlwi r0, r8, 0x10;
  lwz r5, 4(r3);
  mulli r0, r0, 0x24;
  li r4, 0;
  add r5, r5, r0;
  lwz r0, 0x20(r5);
  cmpwi r0, 4;
  beq lbl_8052acdc;
  lwz r0, 0x20(r5);
  cmpwi r0, 5;
  bne lbl_8052ace0;
lbl_8052acdc:
  li r4, 1;
lbl_8052ace0:
  cmpwi r4, 0;
  beq lbl_8052acf0;
  lwz r0, 0xc(r5);
  add r7, r7, r0;
lbl_8052acf0:
  addi r8, r8, 1;
lbl_8052acf4:
  clrlwi r0, r8, 0x10;
  cmplw r0, r6;
  blt lbl_8052acb0;
  mr r3, r7;
  blr;
  // clang-format on
}

// Symbol: unk_8052ad08
// PAL: 0x8052ad08..0x8052ad80
MARK_BINARY_BLOB(unk_8052ad08, 0x8052ad08, 0x8052ad80);
asm UNKNOWN_FUNCTION(unk_8052ad08) {
  // clang-format off
  nofralloc;
  lhz r6, 8(r3);
  li r7, 0;
  li r8, 0;
  b lbl_8052ad6c;
lbl_8052ad18:
  clrlwi r0, r8, 0x10;
  lwz r5, 4(r3);
  mulli r0, r0, 0x24;
  li r4, 0;
  add r5, r5, r0;
  lwz r0, 0x20(r5);
  cmpwi r0, 4;
  beq lbl_8052ad44;
  lwz r0, 0x20(r5);
  cmpwi r0, 5;
  bne lbl_8052ad48;
lbl_8052ad44:
  li r4, 1;
lbl_8052ad48:
  cmpwi r4, 0;
  beq lbl_8052ad68;
  cmpwi r7, 0;
  beq lbl_8052ad64;
  lwz r0, 8(r5);
  cmplw r7, r0;
  bge lbl_8052ad68;
lbl_8052ad64:
  lwz r7, 8(r5);
lbl_8052ad68:
  addi r8, r8, 1;
lbl_8052ad6c:
  clrlwi r0, r8, 0x10;
  cmplw r0, r6;
  blt lbl_8052ad18;
  mr r3, r7;
  blr;
  // clang-format on
}

// Symbol: unk_8052ad80
// PAL: 0x8052ad80..0x8052ae08
MARK_BINARY_BLOB(unk_8052ad80, 0x8052ad80, 0x8052ae08);
asm UNKNOWN_FUNCTION(unk_8052ad80) {
  // clang-format off
  nofralloc;
  lhz r6, 8(r3);
  li r7, 0;
  li r8, 0;
  b lbl_8052adf4;
lbl_8052ad90:
  clrlwi r0, r8, 0x10;
  lwz r5, 4(r3);
  mulli r0, r0, 0x24;
  li r4, 0;
  add r5, r5, r0;
  lwz r0, 0x20(r5);
  cmpwi r0, 4;
  beq lbl_8052adbc;
  lwz r0, 0x20(r5);
  cmpwi r0, 5;
  bne lbl_8052adc0;
lbl_8052adbc:
  li r4, 1;
lbl_8052adc0:
  cmpwi r4, 0;
  beq lbl_8052adf0;
  cmpwi r7, 0;
  beq lbl_8052ade4;
  lwz r4, 0xc(r5);
  lwz r0, 8(r5);
  add r0, r4, r0;
  cmplw r7, r0;
  ble lbl_8052adf0;
lbl_8052ade4:
  lwz r4, 0xc(r5);
  lwz r0, 8(r5);
  add r7, r4, r0;
lbl_8052adf0:
  addi r8, r8, 1;
lbl_8052adf4:
  clrlwi r0, r8, 0x10;
  cmplw r0, r6;
  blt lbl_8052ad90;
  mr r3, r7;
  blr;
  // clang-format on
}

// Symbol: unk_8052ae08
// PAL: 0x8052ae08..0x8052ae5c
MARK_BINARY_BLOB(unk_8052ae08, 0x8052ae08, 0x8052ae5c);
asm UNKNOWN_FUNCTION(unk_8052ae08) {
  // clang-format off
  nofralloc;
  lhz r5, 8(r3);
  li r6, 0;
  li r7, 0;
  b lbl_8052ae48;
lbl_8052ae18:
  clrlwi r0, r7, 0x10;
  lwz r4, 4(r3);
  mulli r0, r0, 0x24;
  add r4, r4, r0;
  lwz r4, 0x20(r4);
  addi r0, r4, -2;
  cntlzw r0, r0;
  rlwinm. r0, r0, 0x1b, 5, 0x1f;
  beq lbl_8052ae44;
  addi r0, r6, 1;
  clrlwi r6, r0, 0x10;
lbl_8052ae44:
  addi r7, r7, 1;
lbl_8052ae48:
  clrlwi r0, r7, 0x10;
  cmplw r0, r5;
  blt lbl_8052ae18;
  mr r3, r6;
  blr;
  // clang-format on
}
