#include "gxBump.h"

#include "gx.h"

extern const f32 unk_80388770;

// Symbol: GXSetTevIndirect
// PAL: 0x801717ac..0x80171814
MARK_BINARY_BLOB(GXSetTevIndirect, 0x801717ac, 0x80171814);
asm UNKNOWN_FUNCTION(GXSetTevIndirect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  li r12, 0;
  rlwimi r12, r4, 0, 0x1e, 0x1f;
  addi r4, r3, 0x10;
  stw r31, 0xc(r1);
  rlwimi r12, r5, 2, 0x1c, 0x1d;
  lis r11, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r11);
  rlwimi r12, r6, 4, 0x19, 0x1b;
  lwz r31, 0x1c(r1);
  li r0, 0;
  lbz r5, 0x1b(r1);
  rlwimi r12, r31, 7, 0x17, 0x18;
  lwz r3, gx;
  rlwimi r12, r7, 9, 0x13, 0x16;
  rlwimi r12, r8, 0xd, 0x10, 0x12;
  rlwimi r12, r9, 0x10, 0xd, 0xf;
  rlwimi r12, r5, 0x13, 0xc, 0xc;
  rlwimi r12, r10, 0x14, 0xb, 0xb;
  rlwimi r12, r4, 0x18, 0, 7;
  stw r12, -0x8000(r11);
  sth r0, 2(r3);
  lwz r31, 0xc(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetIndTexMtx
// PAL: 0x80171814..0x80171968
MARK_BINARY_BLOB(GXSetIndTexMtx, 0x80171814, 0x80171968);
asm void GXSetIndTexMtx(GXIndTexMtxID, const f32*, int) {
  // clang-format off
  nofralloc;
  cmpwi r3, 8;
  stwu r1, -0x40(r1);
  beq lbl_80171860;
  bge lbl_8017183c;
  cmpwi r3, 4;
  beq lbl_80171860;
  bge lbl_80171850;
  cmpwi r3, 1;
  bge lbl_80171848;
  b lbl_80171860;
lbl_8017183c:
  cmpwi r3, 0xc;
  bge lbl_80171860;
  b lbl_80171858;
lbl_80171848:
  addi r3, r3, -1;
  b lbl_80171864;
lbl_80171850:
  addi r3, r3, -5;
  b lbl_80171864;
lbl_80171858:
  addi r3, r3, -9;
  b lbl_80171864;
lbl_80171860:
  li r3, 0;
lbl_80171864:
  lfs f6, unk_80388770;
  slwi r0, r3, 2;
  lfs f1, 0(r4);
  subf r9, r3, r0;
  lfs f0, 0xc(r4);
  addi r8, r5, 0x11;
  fmuls f1, f6, f1;
  lfs f3, 4(r4);
  fmuls f0, f6, f0;
  lfs f2, 0x10(r4);
  fmuls f3, f6, f3;
  lis r6, 0xcc01;
  fctiwz f5, f1;
  lfs f1, 8(r4);
  fctiwz f4, f0;
  lfs f0, 0x14(r4);
  fmuls f2, f6, f2;
  li r7, 0x61;
  stfd f5, 8(r1);
  fctiwz f3, f3;
  fmuls f1, f6, f1;
  li r5, 0;
  lwz r0, 0xc(r1);
  fctiwz f2, f2;
  fmuls f0, f6, f0;
  fctiwz f1, f1;
  stfd f4, 0x10(r1);
  rlwimi r5, r0, 0, 0x15, 0x1f;
  fctiwz f0, f0;
  addi r3, r9, 6;
  lwz r0, 0x14(r1);
  stfd f3, 0x18(r1);
  li r4, 0;
  rlwimi r5, r0, 0xb, 0xa, 0x14;
  lwz r0, 0x1c(r1);
  rlwimi r5, r8, 0x16, 8, 9;
  rlwimi r5, r3, 0x18, 0, 7;
  stb r7, -0x8000(r6);
  rlwimi r4, r0, 0, 0x15, 0x1f;
  addi r3, r9, 7;
  stw r5, -0x8000(r6);
  li r5, 0;
  stfd f2, 0x20(r1);
  lwz r0, 0x24(r1);
  stfd f1, 0x28(r1);
  rlwimi r4, r0, 0xb, 0xa, 0x14;
  lwz r0, 0x2c(r1);
  rlwimi r4, r8, 0x14, 8, 9;
  rlwimi r4, r3, 0x18, 0, 7;
  stb r7, -0x8000(r6);
  rlwimi r5, r0, 0, 0x15, 0x1f;
  lwz r3, gx;
  stw r4, -0x8000(r6);
  addi r4, r9, 8;
  stfd f0, 0x30(r1);
  lwz r0, 0x34(r1);
  stb r7, -0x8000(r6);
  rlwimi r5, r0, 0xb, 0xa, 0x14;
  li r0, 0;
  rlwimi r5, r8, 0x12, 8, 9;
  rlwimi r5, r4, 0x18, 0, 7;
  stw r5, -0x8000(r6);
  sth r0, 2(r3);
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: GXSetIndTexCoordScale
// PAL: 0x80171968..0x80171a6c
MARK_BINARY_BLOB(GXSetIndTexCoordScale, 0x80171968, 0x80171a6c);
asm void GXSetIndTexCoordScale(GXIndTexStageID, GXIndTexScale, GXIndTexScale) {
  // clang-format off
  nofralloc;
  cmpwi r3, 2;
  beq lbl_801719f8;
  bge lbl_80171984;
  cmpwi r3, 0;
  beq lbl_80171990;
  bge lbl_801719c4;
  b lbl_80171a5c;
lbl_80171984:
  cmpwi r3, 4;
  bge lbl_80171a5c;
  b lbl_80171a2c;
lbl_80171990:
  lwz r8, gx;
  li r6, 0x25;
  lis r3, 0xcc01;
  li r0, 0x61;
  lwz r7, 0x178(r8);
  rlwimi r7, r4, 0, 0x1c, 0x1f;
  rlwimi r7, r5, 4, 0x18, 0x1b;
  rlwimi r7, r6, 0x18, 0, 7;
  stw r7, 0x178(r8);
  stb r0, -0x8000(r3);
  lwz r0, 0x178(r8);
  stw r0, -0x8000(r3);
  b lbl_80171a5c;
lbl_801719c4:
  lwz r8, gx;
  li r6, 0x25;
  lis r3, 0xcc01;
  li r0, 0x61;
  lwz r7, 0x178(r8);
  rlwimi r7, r4, 8, 0x14, 0x17;
  rlwimi r7, r5, 0xc, 0x10, 0x13;
  rlwimi r7, r6, 0x18, 0, 7;
  stw r7, 0x178(r8);
  stb r0, -0x8000(r3);
  lwz r0, 0x178(r8);
  stw r0, -0x8000(r3);
  b lbl_80171a5c;
lbl_801719f8:
  lwz r8, gx;
  li r6, 0x26;
  lis r3, 0xcc01;
  li r0, 0x61;
  lwz r7, 0x17c(r8);
  rlwimi r7, r4, 0, 0x1c, 0x1f;
  rlwimi r7, r5, 4, 0x18, 0x1b;
  rlwimi r7, r6, 0x18, 0, 7;
  stw r7, 0x17c(r8);
  stb r0, -0x8000(r3);
  lwz r0, 0x17c(r8);
  stw r0, -0x8000(r3);
  b lbl_80171a5c;
lbl_80171a2c:
  lwz r8, gx;
  li r6, 0x26;
  lis r3, 0xcc01;
  li r0, 0x61;
  lwz r7, 0x17c(r8);
  rlwimi r7, r4, 8, 0x14, 0x17;
  rlwimi r7, r5, 0xc, 0x10, 0x13;
  rlwimi r7, r6, 0x18, 0, 7;
  stw r7, 0x17c(r8);
  stb r0, -0x8000(r3);
  lwz r0, 0x17c(r8);
  stw r0, -0x8000(r3);
lbl_80171a5c:
  lwz r3, gx;
  li r0, 0;
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetIndTexOrder
// PAL: 0x80171a6c..0x80171b38
MARK_BINARY_BLOB(GXSetIndTexOrder, 0x80171a6c, 0x80171b38);
asm UNKNOWN_FUNCTION(GXSetIndTexOrder) {
  // clang-format off
  nofralloc;
  cmpwi r5, 0xff;
  bne lbl_80171a78;
  li r5, 0;
lbl_80171a78:
  cmpwi r4, 0xff;
  bne lbl_80171a84;
  li r4, 0;
lbl_80171a84:
  cmpwi r3, 2;
  beq lbl_80171adc;
  bge lbl_80171aa0;
  cmpwi r3, 0;
  beq lbl_80171aac;
  bge lbl_80171ac4;
  b lbl_80171b08;
lbl_80171aa0:
  cmpwi r3, 4;
  bge lbl_80171b08;
  b lbl_80171af4;
lbl_80171aac:
  lwz r3, gx;
  lwz r0, 0x170(r3);
  rlwimi r0, r5, 0, 0x1d, 0x1f;
  rlwimi r0, r4, 3, 0x1a, 0x1c;
  stw r0, 0x170(r3);
  b lbl_80171b08;
lbl_80171ac4:
  lwz r3, gx;
  lwz r0, 0x170(r3);
  rlwimi r0, r5, 6, 0x17, 0x19;
  rlwimi r0, r4, 9, 0x14, 0x16;
  stw r0, 0x170(r3);
  b lbl_80171b08;
lbl_80171adc:
  lwz r3, gx;
  lwz r0, 0x170(r3);
  rlwimi r0, r5, 0xc, 0x11, 0x13;
  rlwimi r0, r4, 0xf, 0xe, 0x10;
  stw r0, 0x170(r3);
  b lbl_80171b08;
lbl_80171af4:
  lwz r3, gx;
  lwz r0, 0x170(r3);
  rlwimi r0, r5, 0x12, 0xb, 0xd;
  rlwimi r0, r4, 0x15, 8, 0xa;
  stw r0, 0x170(r3);
lbl_80171b08:
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x170(r5);
  stw r3, -0x8000(r4);
  lwz r3, 0x5fc(r5);
  ori r3, r3, 3;
  stw r3, 0x5fc(r5);
  sth r0, 2(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetNumIndStages
// PAL: 0x80171b38..0x80171b58
MARK_BINARY_BLOB(GXSetNumIndStages, 0x80171b38, 0x80171b58);
asm void GXSetNumIndStages(int) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x254(r4);
  rlwimi r0, r3, 0x10, 0xd, 0xf;
  stw r0, 0x254(r4);
  lwz r0, 0x5fc(r4);
  ori r0, r0, 6;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetTevDirect
// PAL: 0x80171b58..0x80171ba0
MARK_BINARY_BLOB(GXSetTevDirect, 0x80171b58, 0x80171ba0);
asm void GXSetTevDirect(int) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0;
  stw r0, 0x14(r1);
  li r0, 0;
  li r6, 0;
  li r7, 0;
  stw r0, 8(r1);
  li r8, 0;
  li r9, 0;
  li r10, 0;
  stw r0, 0xc(r1);
  bl GXSetTevIndirect;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetTevIndWarp
// PAL: 0x80171ba0..0x80171bf4
MARK_BINARY_BLOB(GXSetTevIndWarp, 0x80171ba0, 0x80171bf4);
asm UNKNOWN_FUNCTION(GXSetTevIndWarp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r6, 0;
  li r8, 0;
  stw r0, 0x14(r1);
  beq lbl_80171bbc;
  li r8, 6;
lbl_80171bbc:
  li r6, 0;
  cmpwi r5, 0;
  stw r6, 8(r1);
  li r5, 0;
  stw r6, 0xc(r1);
  beq lbl_80171bd8;
  li r6, 7;
lbl_80171bd8:
  mr r9, r8;
  li r10, 0;
  bl GXSetTevIndirect;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __GXUpdateBPMask
// PAL: 0x80171bf4..0x80171bf8
UNKNOWN_FUNCTION(__GXUpdateBPMask) {}

// Symbol: __GXSetIndirectMask
// PAL: 0x80171bf8..0x80171c28
MARK_BINARY_BLOB(__GXSetIndirectMask, 0x80171bf8, 0x80171c28);
asm void __GXSetIndirectMask(int) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0;
  lwz r6, 0x174(r7);
  rlwimi r6, r3, 0, 0x18, 0x1f;
  stw r6, 0x174(r7);
  stb r5, -0x8000(r4);
  lwz r3, 0x174(r7);
  stw r3, -0x8000(r4);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: __GXFlushTextureState
// PAL: 0x80171c28..0x80171c4c
MARK_BINARY_BLOB(__GXFlushTextureState, 0x80171c28, 0x80171c4c);
asm UNKNOWN_FUNCTION(__GXFlushTextureState) {
  // clang-format off
  nofralloc;
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x174(r5);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  blr;
  // clang-format on
}
