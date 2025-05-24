#include "eggSaveBanner.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(memcpy);
extern UNKNOWN_FUNCTION(NANDCreate);
extern UNKNOWN_FUNCTION(NANDWrite);
extern UNKNOWN_FUNCTION(NANDMove);
extern UNKNOWN_FUNCTION(NANDOpen);
extern UNKNOWN_FUNCTION(NANDClose);
extern UNKNOWN_FUNCTION(NANDGetHomeDir);
extern UNKNOWN_FUNCTION(NANDGetType);
extern UNKNOWN_FUNCTION(NANDInitBanner);
extern UNKNOWN_FUNCTION(TPLBind);
extern UNKNOWN_FUNCTION(TPLGet);
extern UNKNOWN_FUNCTION(alloc__Q23EGG4HeapFUliPQ23EGG4Heap);
extern UNKNOWN_FUNCTION(free__Q23EGG4HeapFPvPQ23EGG4Heap);
extern UNKNOWN_FUNCTION(__nw__FUlPQ23EGG4Heapi);
}

// Symbol: SaveBanner_create
// PAL: 0x8023a884..0x8023a8ec
MARK_BINARY_BLOB(SaveBanner_create, 0x8023a884, 0x8023a8ec);
asm UNKNOWN_FUNCTION(SaveBanner_create) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, -0x5d08(r13);
  cmpwi r0, 0;
  bne lbl_8023a8d4;
  cmpwi r3, 0;
  bne lbl_8023a8b0;
  lwz r31, -0x5d60(r13);
lbl_8023a8b0:
  mr r4, r31;
  li r3, 0x14;
  li r5, 4;
  bl __nw__FUlPQ23EGG4Heapi;
  cmpwi r3, 0;
  beq lbl_8023a8d0;
  mr r4, r31;
  bl SaveBanner_construct;
lbl_8023a8d0:
  stw r3, -0x5d08(r13);
lbl_8023a8d4:
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  lwz r3, -0x5d08(r13);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SaveBanner_initBanner
// PAL: 0x8023a8ec..0x8023aa04
MARK_BINARY_BLOB(SaveBanner_initBanner, 0x8023a8ec, 0x8023aa04);
asm UNKNOWN_FUNCTION(SaveBanner_initBanner) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r31, r4;
  mr r4, r5;
  mr r5, r6;
  mr r30, r3;
  mr r6, r7;
  lwz r8, 4(r31);
  addi r0, r8, -1;
  stw r0, 4(r3);
  lwz r3, 0x10(r3);
  bl NANDInitBanner;
  mr r3, r31;
  bl TPLBind;
  mr r3, r31;
  li r4, 0;
  bl TPLGet;
  lwz r4, 0(r3);
  li r5, 0x6000;
  lwz r6, 0x10(r30);
  lwz r4, 8(r4);
  addi r3, r6, 0xa0;
  bl memcpy;
  li r25, 0;
  li r27, 0;
  li r26, 0;
  li r28, 3;
  li r29, 2;
  b lbl_8023a9c0;
lbl_8023a968:
  mr r3, r31;
  addi r4, r25, 1;
  bl TPLGet;
  cmpwi r3, 0;
  beq lbl_8023a9b4;
  lwz r0, 0x10(r30);
  li r5, 0x1200;
  lwz r3, 0(r3);
  add r6, r0, r27;
  lwz r4, 8(r3);
  addi r3, r6, 0x60a0;
  bl memcpy;
  lwz r5, 0x10(r30);
  slw r3, r28, r26;
  slw r0, r29, r26;
  lhz r4, 8(r5);
  andc r3, r4, r3;
  or r0, r3, r0;
  sth r0, 8(r5);
lbl_8023a9b4:
  addi r27, r27, 0x1200;
  addi r26, r26, 2;
  addi r25, r25, 1;
lbl_8023a9c0:
  lwz r0, 4(r30);
  cmplw r25, r0;
  blt lbl_8023a968;
  cmplwi r0, 8;
  bge lbl_8023a9f0;
  lwz r5, 0x10(r30);
  slwi r0, r0, 1;
  li r3, 3;
  lhz r4, 8(r5);
  slw r0, r3, r0;
  andc r0, r4, r0;
  sth r0, 8(r5);
lbl_8023a9f0:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: SaveBanner_existBannerFile
// PAL: 0x8023aa04..0x8023aa78
MARK_BINARY_BLOB(SaveBanner_existBannerFile, 0x8023aa04, 0x8023aa78);
asm UNKNOWN_FUNCTION(SaveBanner_existBannerFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r4, r1, 8;
  stw r31, 0x1c(r1);
  mr r31, r3;
  lwz r3, -0x6c58(r13);
  bl NANDGetType;
  cmpwi r3, 0;
  stw r3, 0xc(r31);
  bne lbl_8023aa40;
  li r0, 0;
  stb r0, 8(r31);
  li r3, 1;
  b lbl_8023aa64;
lbl_8023aa40:
  cmpwi r3, -12;
  bne lbl_8023aa58;
  li r0, 0;
  stb r0, 8(r31);
  li r3, 0;
  b lbl_8023aa64;
lbl_8023aa58:
  li r0, 1;
  stb r0, 8(r31);
  li r3, 0;
lbl_8023aa64:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SaveBanner_createBannerFile
// PAL: 0x8023aa78..0x8023ab54
MARK_BINARY_BLOB(SaveBanner_createBannerFile, 0x8023aa78, 0x8023ab54);
asm UNKNOWN_FUNCTION(SaveBanner_createBannerFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  addi r6, r13, -27736;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r3;
  lwz r3, 4(r6);
  bl NANDCreate;
  cmpwi r3, 0;
  stw r3, 0xc(r31);
  beq lbl_8023aabc;
  cmpwi r3, -6;
  beq lbl_8023aabc;
  li r0, 1;
  stb r0, 8(r31);
  li r3, 0;
  b lbl_8023ab40;
lbl_8023aabc:
  mr r3, r31;
  li r4, 1;
  bl unk_8023ac3c;
  lbz r0, 8(r31);
  cmpwi r0, 0;
  beq lbl_8023aadc;
  li r3, 0;
  b lbl_8023ab40;
lbl_8023aadc:
  addi r3, r1, 8;
  bl NANDGetHomeDir;
  cmpwi r3, 0;
  stw r3, 0xc(r31);
  beq lbl_8023ab00;
  li r0, 1;
  stb r0, 8(r31);
  li r3, 0;
  b lbl_8023ab40;
lbl_8023ab00:
  addi r3, r13, -27736;
  addi r4, r1, 8;
  lwz r3, 4(r3);
  bl NANDMove;
  cmpwi r3, 0;
  stw r3, 0xc(r31);
  beq lbl_8023ab34;
  cmpwi r3, -6;
  beq lbl_8023ab34;
  li r0, 1;
  stb r0, 8(r31);
  li r3, 0;
  b lbl_8023ab40;
lbl_8023ab34:
  li r0, 0;
  stb r0, 8(r31);
  li r3, 1;
lbl_8023ab40:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: SaveBanner_saveBannerFile
// PAL: 0x8023ab54..0x8023ab5c
MARK_BINARY_BLOB(SaveBanner_saveBannerFile, 0x8023ab54, 0x8023ab5c);
asm UNKNOWN_FUNCTION(SaveBanner_saveBannerFile) {
  // clang-format off
  nofralloc;
  li r4, 0;
  b unk_8023ac3c;
  // clang-format on
}

// Symbol: SaveBanner_isErrorOccured
// PAL: 0x8023ab5c..0x8023ab64
MARK_BINARY_BLOB(SaveBanner_isErrorOccured, 0x8023ab5c, 0x8023ab64);
asm UNKNOWN_FUNCTION(SaveBanner_isErrorOccured) {
  // clang-format off
  nofralloc;
  lbz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: SaveBanner_destroy
// PAL: 0x8023ab64..0x8023abd8
MARK_BINARY_BLOB(SaveBanner_destroy, 0x8023ab64, 0x8023abd8);
asm UNKNOWN_FUNCTION(SaveBanner_destroy) {
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
  beq lbl_8023abbc;
  lwz r0, 0x10(r3);
  lis r4, 0x802a;
  addi r4, r4, 0x3dd0;
  stw r4, 0(r3);
  cmpwi r0, 0;
  beq lbl_8023abac;
  mr r3, r0;
  li r4, 0;
  bl free__Q23EGG4HeapFPvPQ23EGG4Heap;
lbl_8023abac:
  cmpwi r31, 0;
  ble lbl_8023abbc;
  mr r3, r30;
  bl __dl__FPv;
lbl_8023abbc:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SaveBanner_construct
// PAL: 0x8023abd8..0x8023ac3c
MARK_BINARY_BLOB(SaveBanner_construct, 0x8023abd8, 0x8023ac3c);
asm UNKNOWN_FUNCTION(SaveBanner_construct) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r6, 0x802a;
  mr r5, r4;
  stw r0, 0x14(r1);
  li r0, 0;
  addi r6, r6, 0x3dd0;
  li r7, 8;
  stw r31, 0xc(r1);
  mr r31, r3;
  li r4, 0x20;
  stw r6, 0(r3);
  lis r6, 1;
  stw r7, 4(r3);
  stb r0, 8(r3);
  stw r0, 0xc(r3);
  addi r3, r6, -3936;
  bl alloc__Q23EGG4HeapFUliPQ23EGG4Heap;
  stw r3, 0x10(r31);
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023ac3c
// PAL: 0x8023ac3c..0x8023ad10
MARK_BINARY_BLOB(unk_8023ac3c, 0x8023ac3c, 0x8023ad10);
asm UNKNOWN_FUNCTION(unk_8023ac3c) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  li r5, 2;
  stw r0, 0xa4(r1);
  slwi r0, r4, 2;
  addi r4, r13, -27736;
  stw r31, 0x9c(r1);
  stw r30, 0x98(r1);
  mr r30, r3;
  lwzx r3, r4, r0;
  addi r4, r1, 8;
  bl NANDOpen;
  cmpwi r3, 0;
  stw r3, 0xc(r30);
  beq lbl_8023ac88;
  li r0, 1;
  stb r0, 8(r30);
  li r3, 0;
  b lbl_8023acf8;
lbl_8023ac88:
  lwz r0, 4(r30);
  addi r3, r1, 8;
  lwz r4, 0x10(r30);
  mulli r5, r0, 0x1200;
  addi r31, r5, 0x60a0;
  mr r5, r31;
  bl NANDWrite;
  cmplw r3, r31;
  stw r3, 0xc(r30);
  beq lbl_8023acc8;
  li r0, 1;
  stb r0, 8(r30);
  addi r3, r1, 8;
  bl NANDClose;
  li r3, 0;
  b lbl_8023acf8;
lbl_8023acc8:
  addi r3, r1, 8;
  bl NANDClose;
  cmpwi r3, 0;
  stw r3, 0xc(r30);
  beq lbl_8023acec;
  li r0, 1;
  stb r0, 8(r30);
  li r3, 0;
  b lbl_8023acf8;
lbl_8023acec:
  li r0, 0;
  stb r0, 8(r30);
  li r3, 1;
lbl_8023acf8:
  lwz r0, 0xa4(r1);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}
