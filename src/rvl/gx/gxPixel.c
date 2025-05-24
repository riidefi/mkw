#include "gxPixel.h"

#include <math.h>

// Extern function references.
// PAL: 0x80171c28
extern UNKNOWN_FUNCTION(__GXFlushTextureState);

extern const f32 unk_80388778;
extern const f32 unk_8038877c;
extern const f32 unk_80388780;
extern const f64 unk_80388788;
extern const f64 unk_80388790;
extern const f64 unk_80388798;
extern const f64 unk_803887a0;
extern const f64 unk_803887a8;
extern const f64 unk_803887b0;
extern const f32 unk_803887b8;
extern const f32 unk_803887bc;
extern const f64 unk_803887c0;

// Symbol: GXSetFog
// PAL: 0x801722cc..0x801724f8
MARK_BINARY_BLOB(GXSetFog, 0x801722cc, 0x801724f8);
asm void GXSetFog(int, f32, f32, f32, f32, GXColor) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stfd f31, 0x30(r1);
  psq_st f31, 56(r1), 0, 0;
  li r8, 0;
  li r9, 0;
  stw r31, 0x2c(r1);
  clrlwi r31, r3, 0x1d;
  stw r30, 0x28(r1);
  rlwinm. r30, r3, 0x1d, 0x1f, 0x1f;
  stw r29, 0x24(r1);
  mr r29, r4;
  stw r28, 0x20(r1);
  beq lbl_80172350;
  fcmpu cr0, f4, f3;
  beq lbl_80172318;
  fcmpu cr0, f2, f1;
  bne lbl_80172328;
lbl_80172318:
  lfs f0, unk_80388778;
  stfs f0, 0xc(r1);
  stfs f0, 8(r1);
  b lbl_80172440;
lbl_80172328:
  fsubs f6, f2, f1;
  lfs f5, unk_8038877c;
  fsubs f2, f4, f3;
  fsubs f0, f1, f3;
  fdivs f3, f5, f6;
  fmuls f1, f3, f2;
  fmuls f0, f3, f0;
  stfs f1, 0xc(r1);
  stfs f0, 8(r1);
  b lbl_80172440;
lbl_80172350:
  fcmpu cr0, f4, f3;
  beq lbl_80172360;
  fcmpu cr0, f2, f1;
  bne lbl_80172370;
lbl_80172360:
  lfs f3, unk_80388778;
  lfs f4, unk_80388780;
  fmr f31, f3;
  b lbl_8017238c;
lbl_80172370:
  fsubs f0, f4, f3;
  fsubs f2, f2, f1;
  fmuls f3, f4, f3;
  fdivs f4, f4, f0;
  fmuls f0, f0, f2;
  fdivs f31, f1, f2;
  fdivs f3, f3, f0;
lbl_8017238c:
  lfs f1, unk_80388780;
  li r28, 0;
  lfd f0, unk_80388788;
  b lbl_801723a4;
lbl_8017239c:
  fmuls f4, f4, f1;
  addi r28, r28, 1;
lbl_801723a4:
  fcmpo cr0, f4, f0;
  bgt lbl_8017239c;
  lfd f0, unk_80388798;
  lfs f2, unk_80388790;
  lfs f1, unk_80388778;
  b lbl_801723c4;
lbl_801723bc:
  fmuls f4, f4, f2;
  addi r28, r28, -1;
lbl_801723c4:
  fcmpo cr0, f4, f1;
  mfcr r0;
  rlwinm. r0, r0, 2, 0x1f, 0x1f;
  beq lbl_801723dc;
  fcmpo cr0, f4, f0;
  blt lbl_801723bc;
lbl_801723dc:
  addi r0, r28, 1;
  li r3, 1;
  slw r3, r3, r0;
  lfs f0, unk_803887a0;
  lis r0, 0x4330;
  lfd f2, unk_803887a8;
  xoris r3, r3, 0x8000;
  stw r0, 0x10(r1);
  fmuls f1, f0, f4;
  stw r3, 0x14(r1);
  lfd f0, 0x10(r1);
  fsubs f0, f0, f2;
  fdivs f0, f3, f0;
  stfs f0, 0xc(r1);
  bl __cvt_fp2unsigned;
  addi r0, r28, 1;
  li r8, 0;
  rlwimi r8, r3, 0, 8, 0x1f;
  li r9, 0;
  rlwimi r9, r0, 0, 0x1b, 0x1f;
  li r3, 0xef;
  li r0, 0xf0;
  stfs f31, 8(r1);
  rlwimi r8, r3, 0x18, 0, 7;
  rlwimi r9, r0, 0x18, 0, 7;
lbl_80172440:
  lwz r3, 0xc(r1);
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0xee;
  li r6, 0;
  stb r5, -0x8000(r4);
  rlwimi r6, r3, 0x14, 0x15, 0x1f;
  lwz r10, 8(r1);
  rlwimi r6, r3, 0x14, 0xd, 0x14;
  li r7, 0;
  rlwimi r6, r3, 0x14, 0xc, 0xc;
  li r3, 0xf1;
  rlwimi r6, r0, 0x18, 0, 7;
  rlwimi r7, r10, 0x14, 0x15, 0x1f;
  stw r6, -0x8000(r4);
  rlwimi r7, r10, 0x14, 0xd, 0x14;
  rlwimi r7, r10, 0x14, 0xc, 0xc;
  lwz r0, 0(r29);
  stb r5, -0x8000(r4);
  rlwimi r7, r30, 0x14, 0xb, 0xb;
  rlwimi r7, r31, 0x15, 8, 0xa;
  li r6, 0;
  stw r8, -0x8000(r4);
  rlwimi r7, r3, 0x18, 0, 7;
  rlwimi r6, r0, 0x18, 8, 0x1f;
  li r0, 0xf2;
  stb r5, -0x8000(r4);
  rlwimi r6, r0, 0x18, 0, 7;
  lwz r3, gx;
  li r0, 0;
  stw r9, -0x8000(r4);
  stb r5, -0x8000(r4);
  stw r7, -0x8000(r4);
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  sth r0, 2(r3);
  psq_l f31, 56(r1), 0, 0;
  lfd f31, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: GXInitFogAdjTable
// PAL: 0x801724f8..0x80172658
MARK_BINARY_BLOB(GXInitFogAdjTable, 0x801724f8, 0x80172658);
asm void GXInitFogAdjTable(u16* table, u16 width, const f32[4][4]) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stfd f31, 0x70(r1);
  psq_st f31, 120(r1), 0, 0;
  stfd f30, 0x60(r1);
  psq_st f30, 104(r1), 0, 0;
  stfd f29, 0x50(r1);
  psq_st f29, 88(r1), 0, 0;
  stfd f28, 0x40(r1);
  psq_st f28, 72(r1), 0, 0;
  stfd f27, 0x30(r1);
  psq_st f27, 56(r1), 0, 0;
  stfd f26, 0x20(r1);
  psq_st f26, 40(r1), 0, 0;
  lfd f1, unk_803887b0;
  stw r31, 0x1c(r1);
  lfs f0, 0x3c(r5);
  stw r30, 0x18(r1);
  fcmpu cr0, f1, f0;
  stw r29, 0x14(r1);
  bne lbl_80172570;
  lfs f2, 0x28(r5);
  lfs f0, unk_8038877c;
  lfs f1, 0x2c(r5);
  fsubs f2, f2, f0;
  lfs f0, 0(r5);
  fdivs f1, f1, f2;
  fdivs f26, f1, f0;
  b lbl_80172584;
lbl_80172570:
  lfs f2, unk_8038877c;
  lfs f1, 0(r5);
  lfs f0, unk_803887b8;
  fdivs f26, f2, f1;
  fmuls f1, f0, f26;
lbl_80172584:
  lis r31, 0x4330;
  stw r4, 0xc(r1);
  lfd f28, unk_803887c0;
  fmuls f29, f1, f1;
  stw r31, 8(r1);
  mr r30, r3;
  lfs f0, unk_80388790;
  li r29, 0;
  lfd f1, 8(r1);
  lfs f30, unk_8038877c;
  fsubs f1, f1, f28;
  lfs f31, unk_803887bc;
  fdivs f27, f0, f1;
lbl_801725b8:
  addi r0, r29, 1;
  stw r31, 8(r1);
  slwi r0, r0, 5;
  stw r0, 0xc(r1);
  lfd f0, 8(r1);
  fsubs f0, f0, f28;
  fmuls f0, f0, f27;
  fmuls f0, f0, f26;
  fmuls f0, f0, f0;
  fdivs f0, f0, f29;
  fadds f1, f30, f0;
  bl sqrt;
  frsp f0, f1;
  fmuls f1, f31, f0;
  bl __cvt_fp2unsigned;
  addi r29, r29, 1;
  clrlwi r0, r3, 0x14;
  cmplwi r29, 0xa;
  sth r0, 0(r30);
  addi r30, r30, 2;
  blt lbl_801725b8;
  psq_l f31, 120(r1), 0, 0;
  lfd f31, 0x70(r1);
  psq_l f30, 104(r1), 0, 0;
  lfd f30, 0x60(r1);
  psq_l f29, 88(r1), 0, 0;
  lfd f29, 0x50(r1);
  psq_l f28, 72(r1), 0, 0;
  lfd f28, 0x40(r1);
  psq_l f27, 56(r1), 0, 0;
  lfd f27, 0x30(r1);
  psq_l f26, 40(r1), 0, 0;
  lfd f26, 0x20(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x84(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: GXSetFogRangeAdj
// PAL: 0x80172658..0x8017277c
MARK_BINARY_BLOB(GXSetFogRangeAdj, 0x80172658, 0x8017277c);
asm void GXSetFogRangeAdj(u8, u16, u16* table) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  beq lbl_80172744;
  lhz r12, 0(r5);
  li r11, 0;
  lhz r10, 2(r5);
  lis r6, 0xcc01;
  rlwimi r11, r12, 0, 0x14, 0x1f;
  li r0, 0x61;
  mr r9, r11;
  stb r0, -0x8000(r6);
  rlwimi r9, r10, 0xc, 8, 0x13;
  li r7, 0xe9;
  mr r8, r9;
  lhz r12, 4(r5);
  rlwimi r8, r7, 0x18, 0, 7;
  li r11, 0;
  rlwimi r11, r12, 0, 0x14, 0x1f;
  stw r8, -0x8000(r6);
  mr r9, r11;
  lhz r10, 6(r5);
  li r7, 0xea;
  stb r0, -0x8000(r6);
  rlwimi r9, r10, 0xc, 8, 0x13;
  lhz r12, 8(r5);
  mr r8, r9;
  li r11, 0;
  rlwimi r8, r7, 0x18, 0, 7;
  lhz r10, 0xa(r5);
  rlwimi r11, r12, 0, 0x14, 0x1f;
  stw r8, -0x8000(r6);
  mr r9, r11;
  li r7, 0xeb;
  rlwimi r9, r10, 0xc, 8, 0x13;
  stb r0, -0x8000(r6);
  mr r8, r9;
  lhz r12, 0xc(r5);
  rlwimi r8, r7, 0x18, 0, 7;
  li r11, 0;
  rlwimi r11, r12, 0, 0x14, 0x1f;
  stw r8, -0x8000(r6);
  mr r9, r11;
  lhz r10, 0xe(r5);
  li r7, 0xec;
  stb r0, -0x8000(r6);
  rlwimi r9, r10, 0xc, 8, 0x13;
  lhz r12, 0x10(r5);
  mr r8, r9;
  li r11, 0;
  rlwimi r8, r7, 0x18, 0, 7;
  lhz r10, 0x12(r5);
  stw r8, -0x8000(r6);
  rlwimi r11, r12, 0, 0x14, 0x1f;
  mr r9, r11;
  li r7, 0xed;
  rlwimi r9, r10, 0xc, 8, 0x13;
  stb r0, -0x8000(r6);
  mr r8, r9;
  rlwimi r8, r7, 0x18, 0, 7;
  stw r8, -0x8000(r6);
lbl_80172744:
  addi r0, r4, 0x156;
  li r6, 0;
  rlwimi r6, r0, 0, 0x16, 0x1f;
  lis r4, 0xcc01;
  li r0, 0x61;
  li r5, 0xe8;
  rlwimi r6, r3, 0xa, 0x15, 0x15;
  stb r0, -0x8000(r4);
  rlwimi r6, r5, 0x18, 0, 7;
  lwz r3, gx;
  stw r6, -0x8000(r4);
  li r0, 0;
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetBlendMode
// PAL: 0x8017277c..0x801727cc
MARK_BINARY_BLOB(GXSetBlendMode, 0x8017277c, 0x801727cc);
asm void GXSetBlendMode(u32, u32, u32, u32) {
  // clang-format off
  nofralloc;
  lwz r10, gx;
  addi r0, r3, -3;
  addi r8, r3, -2;
  lis r7, 0xcc01;
  cntlzw r0, r0;
  lwz r9, 0x220(r10);
  rlwimi r9, r0, 6, 0x14, 0x14;
  cntlzw r8, r8;
  li r0, 0x61;
  stb r0, -0x8000(r7);
  rlwimi r9, r3, 0, 0x1f, 0x1f;
  rlwimi r9, r8, 0x1c, 0x1e, 0x1e;
  li r0, 0;
  rlwimi r9, r6, 0xc, 0x10, 0x13;
  rlwimi r9, r4, 8, 0x15, 0x17;
  rlwimi r9, r5, 5, 0x18, 0x1a;
  stw r9, -0x8000(r7);
  stw r9, 0x220(r10);
  sth r0, 2(r10);
  blr;
  // clang-format on
}

// Symbol: GXSetColorUpdate
// PAL: 0x801727cc..0x801727f8
MARK_BINARY_BLOB(GXSetColorUpdate, 0x801727cc, 0x801727f8);
asm void GXSetColorUpdate(u8) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0;
  lwz r6, 0x220(r7);
  rlwimi r6, r3, 3, 0x1c, 0x1c;
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  stw r6, 0x220(r7);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: GXSetAlphaUpdate
// PAL: 0x801727f8..0x80172824
MARK_BINARY_BLOB(GXSetAlphaUpdate, 0x801727f8, 0x80172824);
asm void GXSetAlphaUpdate(u8) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0;
  lwz r6, 0x220(r7);
  rlwimi r6, r3, 4, 0x1b, 0x1b;
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  stw r6, 0x220(r7);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: GXSetZMode
// PAL: 0x80172824..0x80172858
MARK_BINARY_BLOB(GXSetZMode, 0x80172824, 0x80172858);
asm void GXSetZMode(u8, u32, u8) {
  // clang-format off
  nofralloc;
  lwz r9, gx;
  lis r6, 0xcc01;
  li r7, 0x61;
  li r0, 0;
  lwz r8, 0x228(r9);
  rlwimi r8, r3, 0, 0x1f, 0x1f;
  rlwimi r8, r4, 1, 0x1c, 0x1e;
  stb r7, -0x8000(r6);
  rlwimi r8, r5, 4, 0x1b, 0x1b;
  stw r8, -0x8000(r6);
  stw r8, 0x228(r9);
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXSetZCompLoc
// PAL: 0x80172858..0x80172888
MARK_BINARY_BLOB(GXSetZCompLoc, 0x80172858, 0x80172888);
asm void GXSetZCompLoc(u8) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0;
  lwz r6, 0x22c(r7);
  rlwimi r6, r3, 6, 0x19, 0x19;
  stw r6, 0x22c(r7);
  stb r5, -0x8000(r4);
  lwz r3, 0x22c(r7);
  stw r3, -0x8000(r4);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: GXSetPixelFmt
// PAL: 0x80172888..0x80172930
MARK_BINARY_BLOB(GXSetPixelFmt, 0x80172888, 0x80172930);
asm UNKNOWN_FUNCTION(GXSetPixelFmt) {
  // clang-format off
  nofralloc;
  lwz r9, gx;
  lis r6, 0x8029;
  slwi r7, r3, 2;
  addi r6, r6, -22984;
  lwz r8, 0x22c(r9);
  lwzx r0, r6, r7;
  mr r5, r8;
  rlwimi r5, r0, 0, 0x1d, 0x1f;
  rlwimi r5, r4, 3, 0x1a, 0x1c;
  cmplw r8, r5;
  stw r5, 0x22c(r9);
  beq lbl_801728ec;
  lis r5, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r5);
  addi r0, r3, -2;
  cntlzw r4, r0;
  lwz r0, 0x22c(r9);
  stw r0, -0x8000(r5);
  lwz r0, 0x254(r9);
  rlwimi r0, r4, 4, 0x16, 0x16;
  stw r0, 0x254(r9);
  lwz r0, 0x5fc(r9);
  ori r0, r0, 4;
  stw r0, 0x5fc(r9);
lbl_801728ec:
  lwzx r0, r6, r7;
  cmplwi r0, 4;
  bne lbl_80172924;
  addi r0, r3, -4;
  lwz r4, 0x224(r9);
  rlwimi r4, r0, 9, 0x15, 0x16;
  lis r3, 0xcc01;
  li r0, 0x42;
  rlwimi r4, r0, 0x18, 0, 7;
  stw r4, 0x224(r9);
  li r0, 0x61;
  stb r0, -0x8000(r3);
  lwz r0, 0x224(r9);
  stw r0, -0x8000(r3);
lbl_80172924:
  li r0, 0;
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXSetDither
// PAL: 0x80172930..0x8017295c
MARK_BINARY_BLOB(GXSetDither, 0x80172930, 0x8017295c);
asm UNKNOWN_FUNCTION(GXSetDither) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lis r4, 0xcc01;
  li r5, 0x61;
  li r0, 0;
  lwz r6, 0x220(r7);
  rlwimi r6, r3, 2, 0x1d, 0x1d;
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  stw r6, 0x220(r7);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: GXSetDstAlpha
// PAL: 0x8017295c..0x8017298c
MARK_BINARY_BLOB(GXSetDstAlpha, 0x8017295c, 0x8017298c);
asm void GXSetDstAlpha(u8, u8) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  lis r5, 0xcc01;
  li r6, 0x61;
  li r0, 0;
  lwz r7, 0x224(r8);
  rlwimi r7, r4, 0, 0x18, 0x1f;
  rlwimi r7, r3, 8, 0x17, 0x17;
  stb r6, -0x8000(r5);
  stw r7, -0x8000(r5);
  stw r7, 0x224(r8);
  sth r0, 2(r8);
  blr;
  // clang-format on
}

// Symbol: GXSetFieldMask
// PAL: 0x8017298c..0x801729c0
MARK_BINARY_BLOB(GXSetFieldMask, 0x8017298c, 0x801729c0);
asm UNKNOWN_FUNCTION(GXSetFieldMask) {
  // clang-format off
  nofralloc;
  lis r5, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r5);
  li r0, 0x44;
  li r6, 0;
  rlwimi r6, r4, 0, 0x1f, 0x1f;
  rlwimi r6, r3, 1, 0x1e, 0x1e;
  lwz r3, gx;
  rlwimi r6, r0, 0x18, 0, 7;
  li r0, 0;
  stw r6, -0x8000(r5);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetFieldMode
// PAL: 0x801729c0..0x80172a30
MARK_BINARY_BLOB(GXSetFieldMode, 0x801729c0, 0x80172a30);
asm UNKNOWN_FUNCTION(GXSetFieldMode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lwz r5, gx;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0xcc01;
  stw r30, 0x18(r1);
  li r30, 0x61;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0x7c(r5);
  rlwimi r0, r4, 0x16, 9, 9;
  stw r0, 0x7c(r5);
  stb r30, -0x8000(r31);
  lwz r0, 0x7c(r5);
  stw r0, -0x8000(r31);
  bl __GXFlushTextureState;
  stb r30, -0x8000(r31);
  oris r0, r29, 0x6800;
  stw r0, -0x8000(r31);
  bl __GXFlushTextureState;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
