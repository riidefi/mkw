#include "gxGeometry.h"

#include "gx.h"

// Extern function references.
// PAL: 0x8016d814
extern UNKNOWN_FUNCTION(__GXSetVCD);
// PAL: 0x8016d8c4
extern UNKNOWN_FUNCTION(__GXCalculateVLim);
// PAL: 0x8016dfcc
extern UNKNOWN_FUNCTION(__GXSetVAT);
// PAL: 0x801712f0
extern UNKNOWN_FUNCTION(__GXSetSUTexRegs);
// PAL: 0x80171bf4
extern UNKNOWN_FUNCTION(__GXUpdateBPMask);
// PAL: 0x80172fd8
extern UNKNOWN_FUNCTION(__GXSetProjection);
// PAL: 0x801732e8
extern UNKNOWN_FUNCTION(__GXSetViewport);
// PAL: 0x80173544
extern UNKNOWN_FUNCTION(__GXSetMatrixIndex);

// Symbol: __GXSetDirtyState
// PAL: 0x8016ee78..0x8016f0f0
MARK_BINARY_BLOB(__GXSetDirtyState, 0x8016ee78, 0x8016f0f0);
asm UNKNOWN_FUNCTION(__GXSetDirtyState) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r31, gx;
  stw r30, 8(r1);
  lwz r30, 0x5fc(r31);
  clrlwi. r0, r30, 0x1f;
  beq lbl_8016eea0;
  bl __GXSetSUTexRegs;
lbl_8016eea0:
  rlwinm. r0, r30, 0, 0x1e, 0x1e;
  beq lbl_8016eeac;
  bl __GXUpdateBPMask;
lbl_8016eeac:
  rlwinm. r0, r30, 0, 0x1d, 0x1d;
  beq lbl_8016eed4;
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x254(r5);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
lbl_8016eed4:
  rlwinm. r0, r30, 0, 0x1c, 0x1c;
  beq lbl_8016eee0;
  bl __GXSetVCD;
lbl_8016eee0:
  rlwinm. r0, r30, 0, 0x1b, 0x1b;
  beq lbl_8016eeec;
  bl __GXSetVAT;
lbl_8016eeec:
  rlwinm. r0, r30, 0, 0x1b, 0x1c;
  beq lbl_8016eef8;
  bl __GXCalculateVLim;
lbl_8016eef8:
  rlwinm. r30, r30, 0, 0, 0x17;
  beq lbl_8016f0d0;
  rlwinm. r4, r30, 0, 0x14, 0x17;
  beq lbl_8016ef98;
  rlwinm. r0, r4, 0, 0x17, 0x17;
  beq lbl_8016ef2c;
  lis r3, 0xcc01;
  li r0, 0x10;
  stb r0, -0x8000(r3);
  li r0, 0x100a;
  stw r0, -0x8000(r3);
  lwz r0, 0xa8(r31);
  stw r0, -0x8000(r3);
lbl_8016ef2c:
  rlwinm. r0, r4, 0, 0x16, 0x16;
  beq lbl_8016ef50;
  lis r3, 0xcc01;
  li r0, 0x10;
  stb r0, -0x8000(r3);
  li r0, 0x100b;
  stw r0, -0x8000(r3);
  lwz r0, 0xac(r31);
  stw r0, -0x8000(r3);
lbl_8016ef50:
  rlwinm. r0, r4, 0, 0x15, 0x15;
  beq lbl_8016ef74;
  lis r3, 0xcc01;
  li r0, 0x10;
  stb r0, -0x8000(r3);
  li r0, 0x100c;
  stw r0, -0x8000(r3);
  lwz r0, 0xb0(r31);
  stw r0, -0x8000(r3);
lbl_8016ef74:
  rlwinm. r0, r4, 0, 0x14, 0x14;
  beq lbl_8016ef98;
  lis r3, 0xcc01;
  li r0, 0x10;
  stb r0, -0x8000(r3);
  li r0, 0x100d;
  stw r0, -0x8000(r3);
  lwz r0, 0xb4(r31);
  stw r0, -0x8000(r3);
lbl_8016ef98:
  rlwinm r7, r30, 0, 7, 7;
  rlwimi. r7, r30, 0, 0x10, 0x13;
  beq lbl_8016f010;
  rlwinm. r0, r7, 0, 7, 7;
  li r6, 0x100e;
  beq lbl_8016efd0;
  lwz r5, 0x254(r31);
  lis r3, 0xcc01;
  li r4, 0x10;
  li r0, 0x1009;
  stb r4, -0x8000(r3);
  rlwinm r4, r5, 0x1c, 0x1d, 0x1f;
  stw r0, -0x8000(r3);
  stw r4, -0x8000(r3);
lbl_8016efd0:
  mr r5, r31;
  rlwinm r7, r7, 0x14, 0x1c, 0x1f;
  li r4, 0x10;
  lis r3, 0xcc01;
  b lbl_8016f008;
lbl_8016efe4:
  clrlwi. r0, r7, 0x1f;
  beq lbl_8016effc;
  stb r4, -0x8000(r3);
  stw r6, -0x8000(r3);
  lwz r0, 0xb8(r5);
  stw r0, -0x8000(r3);
lbl_8016effc:
  srwi r7, r7, 1;
  addi r5, r5, 4;
  addi r6, r6, 1;
lbl_8016f008:
  cmpwi r7, 0;
  bne lbl_8016efe4;
lbl_8016f010:
  andis. r8, r30, 0x2ff;
  beq lbl_8016f098;
  rlwinm. r0, r8, 0, 6, 6;
  li r6, 0x1040;
  beq lbl_8016f044;
  lwz r5, 0x254(r31);
  lis r3, 0xcc01;
  li r4, 0x10;
  li r0, 0x103f;
  stb r4, -0x8000(r3);
  clrlwi r4, r5, 0x1c;
  stw r0, -0x8000(r3);
  stw r4, -0x8000(r3);
lbl_8016f044:
  mr r7, r31;
  rlwinm r8, r8, 0x10, 0x18, 0x1f;
  li r4, 0x10;
  lis r3, 0xcc01;
  b lbl_8016f090;
lbl_8016f058:
  clrlwi. r0, r8, 0x1f;
  addi r5, r6, 0x10;
  beq lbl_8016f084;
  stb r4, -0x8000(r3);
  stw r6, -0x8000(r3);
  lwz r0, 0xc8(r7);
  stw r0, -0x8000(r3);
  stb r4, -0x8000(r3);
  stw r5, -0x8000(r3);
  lwz r0, 0xe8(r7);
  stw r0, -0x8000(r3);
lbl_8016f084:
  srwi r8, r8, 1;
  addi r6, r6, 1;
  addi r7, r7, 4;
lbl_8016f090:
  cmpwi r8, 0;
  bne lbl_8016f058;
lbl_8016f098:
  rlwinm. r0, r30, 0, 5, 5;
  beq lbl_8016f0b0;
  li r3, 0;
  bl __GXSetMatrixIndex;
  li r3, 5;
  bl __GXSetMatrixIndex;
lbl_8016f0b0:
  rlwinm. r0, r30, 0, 3, 3;
  beq lbl_8016f0bc;
  bl __GXSetViewport;
lbl_8016f0bc:
  rlwinm. r0, r30, 0, 4, 4;
  beq lbl_8016f0c8;
  bl __GXSetProjection;
lbl_8016f0c8:
  li r0, 1;
  sth r0, 2(r31);
lbl_8016f0d0:
  li r0, 0;
  stw r0, 0x5fc(r31);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXBegin
// PAL: 0x8016f0f0..0x8016f23c
MARK_BINARY_BLOB(GXBegin, 0x8016f0f0, 0x8016f23c);
asm void GXBegin(int, int formatIndex, int) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lwz r31, gx;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r0, 0x5fc(r31);
  cmpwi r0, 0;
  beq lbl_8016f12c;
  bl __GXSetDirtyState;
lbl_8016f12c:
  lwz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_8016f20c;
  lwz r7, gx;
  lis r3, 0xcc01;
  li r0, 0x98;
  li r6, 0;
  lhz r5, 4(r7);
  lhz r4, 6(r7);
  stb r0, -0x8000(r3);
  mullw. r5, r5, r4;
  lhz r0, 4(r7);
  sth r0, -0x8000(r3);
  beq lbl_8016f204;
  addi r3, r5, 3;
  addi r7, r5, -32;
  srwi r0, r3, 2;
  cmplwi r0, 8;
  ble lbl_8016f1dc;
  cmplwi r3, 3;
  li r0, 0;
  blt lbl_8016f190;
  cmplw r5, r3;
  bgt lbl_8016f190;
  li r0, 1;
lbl_8016f190:
  cmpwi r0, 0;
  beq lbl_8016f1dc;
  addi r0, r7, 0x1f;
  li r4, 0;
  srwi r0, r0, 5;
  lis r3, 0xcc01;
  mtctr r0;
  cmplwi r7, 0;
  ble lbl_8016f1dc;
lbl_8016f1b4:
  stw r4, -0x8000(r3);
  addi r6, r6, 0x20;
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  bdnz lbl_8016f1b4;
lbl_8016f1dc:
  addi r0, r5, 3;
  li r4, 0;
  subf r0, r6, r0;
  lis r3, 0xcc01;
  srwi r0, r0, 2;
  mtctr r0;
  cmplw r6, r5;
  bge lbl_8016f204;
lbl_8016f1fc:
  stw r4, -0x8000(r3);
  bdnz lbl_8016f1fc;
lbl_8016f204:
  li r0, 1;
  sth r0, 2(r31);
lbl_8016f20c:
  lis r3, 0xcc01;
  or r0, r29, r28;
  stb r0, -0x8000(r3);
  sth r30, -0x8000(r3);
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

// Symbol: __GXSendFlushPrim
// PAL: 0x8016f23c..0x8016f314
MARK_BINARY_BLOB(__GXSendFlushPrim, 0x8016f23c, 0x8016f314);
asm UNKNOWN_FUNCTION(__GXSendFlushPrim) {
  // clang-format off
  nofralloc;
  lwz r6, gx;
  lis r3, 0xcc01;
  li r0, 0x98;
  li r7, 0;
  lhz r5, 4(r6);
  lhz r4, 6(r6);
  stb r0, -0x8000(r3);
  mullw. r8, r5, r4;
  lhz r0, 4(r6);
  sth r0, -0x8000(r3);
  beq lbl_8016f308;
  addi r3, r8, 3;
  addi r5, r8, -32;
  srwi r0, r3, 2;
  cmplwi r0, 8;
  ble lbl_8016f2e0;
  cmplwi r3, 3;
  li r0, 0;
  blt lbl_8016f294;
  cmplw r8, r3;
  bgt lbl_8016f294;
  li r0, 1;
lbl_8016f294:
  cmpwi r0, 0;
  beq lbl_8016f2e0;
  addi r0, r5, 0x1f;
  li r4, 0;
  srwi r0, r0, 5;
  lis r3, 0xcc01;
  mtctr r0;
  cmplwi r5, 0;
  ble lbl_8016f2e0;
lbl_8016f2b8:
  stw r4, -0x8000(r3);
  addi r7, r7, 0x20;
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  stw r4, -0x8000(r3);
  bdnz lbl_8016f2b8;
lbl_8016f2e0:
  addi r0, r8, 3;
  li r4, 0;
  subf r0, r7, r0;
  lis r3, 0xcc01;
  srwi r0, r0, 2;
  mtctr r0;
  cmplw r7, r8;
  bge lbl_8016f308;
lbl_8016f300:
  stw r4, -0x8000(r3);
  bdnz lbl_8016f300;
lbl_8016f308:
  li r0, 1;
  sth r0, 2(r6);
  blr;
  // clang-format on
}

// Symbol: GXSetLineWidth
// PAL: 0x8016f314..0x8016f348
MARK_BINARY_BLOB(GXSetLineWidth, 0x8016f314, 0x8016f348);
asm UNKNOWN_FUNCTION(GXSetLineWidth) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  lis r5, 0xcc01;
  li r6, 0x61;
  li r0, 0;
  lwz r7, 0x7c(r8);
  rlwimi r7, r3, 0, 0x18, 0x1f;
  rlwimi r7, r4, 0x10, 0xd, 0xf;
  stw r7, 0x7c(r8);
  stb r6, -0x8000(r5);
  lwz r3, 0x7c(r8);
  stw r3, -0x8000(r5);
  sth r0, 2(r8);
  blr;
  // clang-format on
}

// Symbol: GXSetPointSize
// PAL: 0x8016f348..0x8016f37c
MARK_BINARY_BLOB(GXSetPointSize, 0x8016f348, 0x8016f37c);
asm UNKNOWN_FUNCTION(GXSetPointSize) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  lis r5, 0xcc01;
  li r6, 0x61;
  li r0, 0;
  lwz r7, 0x7c(r8);
  rlwimi r7, r3, 8, 0x10, 0x17;
  rlwimi r7, r4, 0x13, 0xa, 0xc;
  stw r7, 0x7c(r8);
  stb r6, -0x8000(r5);
  lwz r3, 0x7c(r8);
  stw r3, -0x8000(r5);
  sth r0, 2(r8);
  blr;
  // clang-format on
}

// Symbol: GXEnableTexOffsets
// PAL: 0x8016f37c..0x8016f3b8
MARK_BINARY_BLOB(GXEnableTexOffsets, 0x8016f37c, 0x8016f3b8);
asm UNKNOWN_FUNCTION(GXEnableTexOffsets) {
  // clang-format off
  nofralloc;
  lwz r9, gx;
  slwi r0, r3, 2;
  lis r6, 0xcc01;
  li r3, 0x61;
  add r8, r9, r0;
  li r0, 0;
  lwz r7, 0x108(r8);
  rlwimi r7, r4, 0x12, 0xd, 0xd;
  rlwimi r7, r5, 0x13, 0xc, 0xc;
  stw r7, 0x108(r8);
  stb r3, -0x8000(r6);
  lwz r3, 0x108(r8);
  stw r3, -0x8000(r6);
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXSetCullMode
// PAL: 0x8016f3b8..0x8016f3e0
MARK_BINARY_BLOB(GXSetCullMode, 0x8016f3b8, 0x8016f3e0);
asm UNKNOWN_FUNCTION(GXSetCullMode) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  rlwinm r5, r3, 0x1f, 0x1f, 0x1f;
  rlwimi r5, r3, 1, 0x1e, 0x1e;
  lwz r0, 0x254(r4);
  rlwimi r0, r5, 0xe, 0x10, 0x11;
  stw r0, 0x254(r4);
  lwz r0, 0x5fc(r4);
  ori r0, r0, 4;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetCoPlanar
// PAL: 0x8016f3e0..0x8016f414
MARK_BINARY_BLOB(GXSetCoPlanar, 0x8016f3e0, 0x8016f414);
asm UNKNOWN_FUNCTION(GXSetCoPlanar) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  lis r0, 0xfe08;
  lwz r6, 0x254(r7);
  rlwimi r6, r3, 0x13, 0xc, 0xc;
  stw r6, 0x254(r7);
  stb r5, -0x8000(r4);
  stw r0, -0x8000(r4);
  stb r5, -0x8000(r4);
  lwz r0, 0x254(r7);
  stw r0, -0x8000(r4);
  blr;
  // clang-format on
}

// Symbol: __GXSetGenMode
// PAL: 0x8016f414..0x8016f438
MARK_BINARY_BLOB(__GXSetGenMode, 0x8016f414, 0x8016f438);
asm UNKNOWN_FUNCTION(__GXSetGenMode) {
  // clang-format off
  nofralloc;
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x254(r5);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  blr;
  // clang-format on
}
