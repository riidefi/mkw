#include "gxFrameBuf.h"

// Extern function references.
// PAL: 0x80170738
extern UNKNOWN_FUNCTION(__GetImageTileCount);

extern const f32 unk_803886f0;
extern const f32 unk_803886f8;

// Symbol: GXSetDispCopySrc
// PAL: 0x8016f438..0x8016f478
MARK_BINARY_BLOB(GXSetDispCopySrc, 0x8016f438, 0x8016f478);
asm void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height) {
  // clang-format off
  nofralloc;
  li r7, 0;
  addi r0, r5, -1;
  rlwimi r7, r3, 0, 0x16, 0x1f;
  li r3, 0;
  rlwimi r7, r4, 0xa, 0xc, 0x15;
  li r4, 0x49;
  rlwimi r3, r0, 0, 0x16, 0x1f;
  addi r0, r6, -1;
  rlwimi r3, r0, 0xa, 0xc, 0x15;
  lwz r5, gx;
  rlwimi r7, r4, 0x18, 0, 7;
  li r0, 0x4a;
  stw r7, 0x230(r5);
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x234(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetTexCopySrc
// PAL: 0x8016f478..0x8016f4b8
MARK_BINARY_BLOB(GXSetTexCopySrc, 0x8016f478, 0x8016f4b8);
asm UNKNOWN_FUNCTION(GXSetTexCopySrc) {
  // clang-format off
  nofralloc;
  li r7, 0;
  addi r0, r5, -1;
  rlwimi r7, r3, 0, 0x16, 0x1f;
  li r3, 0;
  rlwimi r7, r4, 0xa, 0xc, 0x15;
  li r4, 0x49;
  rlwimi r3, r0, 0, 0x16, 0x1f;
  addi r0, r6, -1;
  rlwimi r3, r0, 0xa, 0xc, 0x15;
  lwz r5, gx;
  rlwimi r7, r4, 0x18, 0, 7;
  li r0, 0x4a;
  stw r7, 0x240(r5);
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x244(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetDispCopyDst
// PAL: 0x8016f4b8..0x8016f4dc
MARK_BINARY_BLOB(GXSetDispCopyDst, 0x8016f4b8, 0x8016f4dc);
asm void GXSetDispCopyDst(u16 width, u16 height) {
  // clang-format off
  nofralloc;
  rlwinm r0, r3, 1, 0x10, 0x1e;
  lwz r4, gx;
  srawi r0, r0, 5;
  li r3, 0;
  rlwimi r3, r0, 0, 0x16, 0x1f;
  li r0, 0x4d;
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x238(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetTexCopyDst
// PAL: 0x8016f4dc..0x8016f5f8
MARK_BINARY_BLOB(GXSetTexCopyDst, 0x8016f4dc, 0x8016f5f8);
asm UNKNOWN_FUNCTION(GXSetTexCopyDst) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lwz r7, gx;
  cmpwi r5, 0x13;
  stw r0, 0x34(r1);
  li r0, 0;
  mr r9, r3;
  mr r8, r4;
  stw r31, 0x2c(r1);
  clrlwi r31, r5, 0x1c;
  stw r30, 0x28(r1);
  mr r30, r6;
  stw r29, 0x24(r1);
  stw r28, 0x20(r1);
  stb r0, 0x250(r7);
  bne lbl_8016f520;
  li r31, 0xb;
lbl_8016f520:
  cmpwi r5, 0x26;
  beq lbl_8016f540;
  bge lbl_8016f558;
  cmpwi r5, 4;
  bge lbl_8016f558;
  cmpwi r5, 0;
  bge lbl_8016f540;
  b lbl_8016f558;
lbl_8016f540:
  li r0, 3;
  lwz r3, 0x24c(r7);
  rlwimi r3, r0, 0xf, 0xf, 0x10;
  addi r29, r7, 0x24c;
  stw r3, 0x24c(r7);
  b lbl_8016f56c;
lbl_8016f558:
  li r0, 2;
  lwz r3, 0x24c(r7);
  rlwimi r3, r0, 0xf, 0xf, 0x10;
  addi r29, r7, 0x24c;
  stw r3, 0x24c(r7);
lbl_8016f56c:
  rlwinm r0, r5, 0x1c, 0x1f, 0x1f;
  mr r3, r5;
  stb r0, 0x250(r7);
  mr r5, r8;
  lwz r28, gx;
  mr r4, r9;
  lwz r0, 0(r29);
  rlwimi r0, r31, 0, 0x1c, 0x1c;
  addi r6, r1, 0x10;
  addi r7, r1, 0xc;
  stw r0, 0(r29);
  addi r8, r1, 8;
  bl __GetImageTileCount;
  li r0, 0;
  li r3, 0;
  stw r0, 0x248(r28);
  li r0, 0x4d;
  lwz r5, 0x10(r1);
  lwz r4, 8(r1);
  mullw r4, r5, r4;
  rlwimi r3, r4, 0, 0x16, 0x1f;
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x248(r28);
  lwz r0, 0(r29);
  rlwimi r0, r30, 9, 0x16, 0x16;
  rlwimi r0, r31, 4, 0x19, 0x1b;
  stw r0, 0(r29);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: GXSetDispCopyFrame2Field
// PAL: 0x8016f5f8..0x8016f618
MARK_BINARY_BLOB(GXSetDispCopyFrame2Field, 0x8016f5f8, 0x8016f618);
asm UNKNOWN_FUNCTION(GXSetDispCopyFrame2Field) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x23c(r4);
  rlwimi r0, r3, 0xc, 0x12, 0x13;
  stw r0, 0x23c(r4);
  lwz r0, 0x24c(r4);
  rlwinm r0, r0, 0, 0x14, 0x11;
  stw r0, 0x24c(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetCopyClamp
// PAL: 0x8016f618..0x8016f640
MARK_BINARY_BLOB(GXSetCopyClamp, 0x8016f618, 0x8016f640);
asm UNKNOWN_FUNCTION(GXSetCopyClamp) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x23c(r4);
  rlwimi r0, r3, 0, 0x1f, 0x1f;
  rlwimi r0, r3, 0, 0x1e, 0x1e;
  stw r0, 0x23c(r4);
  lwz r0, 0x24c(r4);
  rlwimi r0, r3, 0, 0x1f, 0x1f;
  rlwimi r0, r3, 0, 0x1e, 0x1e;
  stw r0, 0x24c(r4);
  blr;
  // clang-format on
}

// Symbol: GXGetNumXfbLines
// PAL: 0x8016f640..0x8016f6cc
MARK_BINARY_BLOB(GXGetNumXfbLines, 0x8016f640, 0x8016f6cc);
asm u16 GXGetNumXfbLines(u16 efb_height, f32 y_scale_factor) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lfs f0, unk_803886f0;
  stw r0, 0x14(r1);
  fdivs f1, f0, f1;
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __cvt_fp2unsigned;
  addi r0, r31, -1;
  clrlwi r4, r3, 0x17;
  slwi r0, r0, 8;
  divwu r3, r0, r4;
  cmplwi r4, 0x80;
  addi r3, r3, 1;
  ble lbl_8016f6a8;
  cmplwi r4, 0x100;
  bge lbl_8016f6a8;
  b lbl_8016f68c;
lbl_8016f688:
  srwi r4, r4, 1;
lbl_8016f68c:
  clrlwi. r0, r4, 0x1f;
  beq lbl_8016f688;
  divwu r0, r31, r4;
  mullw r0, r0, r4;
  subf. r0, r0, r31;
  bne lbl_8016f6a8;
  addi r3, r3, 1;
lbl_8016f6a8:
  cmplwi r3, 0x400;
  ble lbl_8016f6b4;
  li r3, 0x400;
lbl_8016f6b4:
  lwz r31, 0xc(r1);
  clrlwi r3, r3, 0x10;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetYScaleFactor
// PAL: 0x8016f6cc..0x8016f8fc
MARK_BINARY_BLOB(GXGetYScaleFactor, 0x8016f6cc, 0x8016f8fc);
asm f32 GXGetYScaleFactor(u16 efb_height, u16 xfb_height) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  stfd f31, 0x60(r1);
  psq_st f31, 104(r1), 0, 0;
  stfd f30, 0x50(r1);
  psq_st f30, 88(r1), 0, 0;
  stfd f29, 0x40(r1);
  psq_st f29, 72(r1), 0, 0;
  stfd f28, 0x30(r1);
  psq_st f28, 56(r1), 0, 0;
  lis r0, 0x4330;
  lfd f3, unk_803886f8;
  stw r0, 8(r1);
  lfs f0, unk_803886f0;
  stw r4, 0xc(r1);
  lfd f1, 8(r1);
  stw r0, 0x10(r1);
  fsubs f2, f1, f3;
  stw r3, 0x14(r1);
  lfd f1, 0x10(r1);
  stw r31, 0x2c(r1);
  fsubs f1, f1, f3;
  stw r30, 0x28(r1);
  fdivs f28, f2, f1;
  stw r29, 0x24(r1);
  mr r29, r4;
  stw r28, 0x20(r1);
  mr r28, r3;
  mr r30, r29;
  fdivs f1, f0, f28;
  bl __cvt_fp2unsigned;
  addi r0, r28, -1;
  clrlwi r4, r3, 0x17;
  slwi r31, r0, 8;
  divwu r3, r31, r4;
  cmplwi r4, 0x80;
  addi r3, r3, 1;
  ble lbl_8016f794;
  cmplwi r4, 0x100;
  bge lbl_8016f794;
  b lbl_8016f778;
lbl_8016f774:
  srwi r4, r4, 1;
lbl_8016f778:
  clrlwi. r0, r4, 0x1f;
  beq lbl_8016f774;
  divwu r0, r28, r4;
  mullw r0, r0, r4;
  subf. r0, r0, r28;
  bne lbl_8016f794;
  addi r3, r3, 1;
lbl_8016f794:
  cmplwi r3, 0x400;
  ble lbl_8016f7a0;
  li r3, 0x400;
lbl_8016f7a0:
  lfd f31, unk_803886f8;
  lfs f30, unk_803886f0;
  b lbl_8016f820;
lbl_8016f7ac:
  addi r30, r30, -1;
  stw r28, 0x14(r1);
  stw r30, 0xc(r1);
  lfd f0, 0x10(r1);
  lfd f1, 8(r1);
  fsubs f0, f0, f31;
  fsubs f1, f1, f31;
  fdivs f28, f1, f0;
  fdivs f1, f30, f28;
  bl __cvt_fp2unsigned;
  clrlwi r4, r3, 0x17;
  divwu r3, r31, r4;
  cmplwi r4, 0x80;
  addi r3, r3, 1;
  ble lbl_8016f814;
  cmplwi r4, 0x100;
  bge lbl_8016f814;
  b lbl_8016f7f8;
lbl_8016f7f4:
  srwi r4, r4, 1;
lbl_8016f7f8:
  clrlwi. r0, r4, 0x1f;
  beq lbl_8016f7f4;
  divwu r0, r28, r4;
  mullw r0, r0, r4;
  subf. r0, r0, r28;
  bne lbl_8016f814;
  addi r3, r3, 1;
lbl_8016f814:
  cmplwi r3, 0x400;
  ble lbl_8016f820;
  li r3, 0x400;
lbl_8016f820:
  cmplw r3, r29;
  bgt lbl_8016f7ac;
  fmr f29, f28;
  lfd f30, unk_803886f8;
  lfs f31, unk_803886f0;
  b lbl_8016f8b0;
lbl_8016f838:
  addi r30, r30, 1;
  stw r28, 0x14(r1);
  fmr f29, f28;
  stw r30, 0xc(r1);
  lfd f0, 0x10(r1);
  lfd f1, 8(r1);
  fsubs f0, f0, f30;
  fsubs f1, f1, f30;
  fdivs f28, f1, f0;
  fdivs f1, f31, f28;
  bl __cvt_fp2unsigned;
  clrlwi r4, r3, 0x17;
  divwu r3, r31, r4;
  cmplwi r4, 0x80;
  addi r3, r3, 1;
  ble lbl_8016f8a4;
  cmplwi r4, 0x100;
  bge lbl_8016f8a4;
  b lbl_8016f888;
lbl_8016f884:
  srwi r4, r4, 1;
lbl_8016f888:
  clrlwi. r0, r4, 0x1f;
  beq lbl_8016f884;
  divwu r0, r28, r4;
  mullw r0, r0, r4;
  subf. r0, r0, r28;
  bne lbl_8016f8a4;
  addi r3, r3, 1;
lbl_8016f8a4:
  cmplwi r3, 0x400;
  ble lbl_8016f8b0;
  li r3, 0x400;
lbl_8016f8b0:
  cmplw r3, r29;
  blt lbl_8016f838;
  fmr f1, f29;
  psq_l f31, 104(r1), 0, 0;
  lfd f31, 0x60(r1);
  psq_l f30, 88(r1), 0, 0;
  lfd f30, 0x50(r1);
  psq_l f29, 72(r1), 0, 0;
  lfd f29, 0x40(r1);
  psq_l f28, 56(r1), 0, 0;
  lfd f28, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: GXSetDispCopyYScale
// PAL: 0x8016f8fc..0x8016f9c8
MARK_BINARY_BLOB(GXSetDispCopyYScale, 0x8016f8fc, 0x8016f9c8);
asm u32 GXSetDispCopyYScale(f32 y_scale_factor) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lfs f0, unk_803886f0;
  stw r0, 0x14(r1);
  fdivs f1, f0, f1;
  bl __cvt_fp2unsigned;
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0x4e;
  li r5, 0;
  clrlwi r7, r3, 0x17;
  rlwimi r5, r3, 0, 0x17, 0x1f;
  lwz r6, gx;
  rlwimi r5, r0, 0x18, 0, 7;
  li r0, 0;
  stw r5, -0x8000(r4);
  subfic r3, r7, 0x100;
  cmplwi r7, 0x80;
  sth r0, 2(r6);
  addi r0, r7, -256;
  or r3, r3, r0;
  lwz r0, 0x23c(r6);
  rlwimi r0, r3, 0xb, 0x15, 0x15;
  stw r0, 0x23c(r6);
  lwz r0, 0x234(r6);
  rlwinm r3, r0, 0x16, 0x16, 0x1f;
  addi r4, r3, 1;
  addi r0, r4, -1;
  slwi r0, r0, 8;
  divwu r3, r0, r7;
  addi r3, r3, 1;
  ble lbl_8016f9ac;
  cmplwi r7, 0x100;
  bge lbl_8016f9ac;
  b lbl_8016f990;
lbl_8016f98c:
  srwi r7, r7, 1;
lbl_8016f990:
  clrlwi. r0, r7, 0x1f;
  beq lbl_8016f98c;
  divwu r0, r4, r7;
  mullw r0, r0, r7;
  subf. r0, r0, r4;
  bne lbl_8016f9ac;
  addi r3, r3, 1;
lbl_8016f9ac:
  cmplwi r3, 0x400;
  ble lbl_8016f9b8;
  li r3, 0x400;
lbl_8016f9b8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetCopyClear
// PAL: 0x8016f9c8..0x8016fa40
MARK_BINARY_BLOB(GXSetCopyClear, 0x8016f9c8, 0x8016fa40);
asm void GXSetCopyClear(GXColor, u32 zClear) {
  // clang-format off
  nofralloc;
  lbz r6, 0(r3);
  lis r7, 0xcc01;
  li r8, 0x61;
  lbz r0, 3(r3);
  li r10, 0;
  stb r8, -0x8000(r7);
  rlwimi r10, r6, 0, 0x18, 0x1f;
  li r9, 0x4f;
  rlwimi r10, r0, 8, 0x10, 0x17;
  lbz r0, 2(r3);
  rlwimi r10, r9, 0x18, 0, 7;
  li r6, 0;
  stw r10, -0x8000(r7);
  rlwimi r6, r0, 0, 0x18, 0x1f;
  lbz r3, 1(r3);
  li r0, 0x50;
  stb r8, -0x8000(r7);
  li r5, 0;
  rlwimi r6, r3, 8, 0x10, 0x17;
  lwz r3, gx;
  rlwimi r6, r0, 0x18, 0, 7;
  li r0, 0x51;
  stw r6, -0x8000(r7);
  rlwimi r5, r4, 0, 8, 0x1f;
  rlwimi r5, r0, 0x18, 0, 7;
  li r0, 0;
  stb r8, -0x8000(r7);
  stw r5, -0x8000(r7);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetCopyFilter
// PAL: 0x8016fa40..0x8016fc24
MARK_BINARY_BLOB(GXSetCopyFilter, 0x8016fa40, 0x8016fc24);
asm void GXSetCopyFilter(u8, const u8[12][2], u8, const u8[7]) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  beq lbl_8016fb3c;
  lbz r8, 0(r4);
  li r0, 0;
  lbz r10, 1(r4);
  li r3, 0;
  rlwimi r0, r8, 0, 0x1c, 0x1f;
  lbz r7, 6(r4);
  rlwimi r0, r10, 4, 0x18, 0x1b;
  lbz r8, 0xc(r4);
  rlwimi r3, r7, 0, 0x1c, 0x1f;
  li r7, 0;
  rlwimi r7, r8, 0, 0x1c, 0x1f;
  lbz r10, 0xd(r4);
  lbz r11, 7(r4);
  li r8, 0;
  rlwimi r7, r10, 4, 0x18, 0x1b;
  lbz r10, 2(r4);
  lbz r9, 0x12(r4);
  rlwimi r3, r11, 4, 0x18, 0x1b;
  rlwimi r0, r10, 8, 0x14, 0x17;
  lbz r10, 0xe(r4);
  rlwimi r8, r9, 0, 0x1c, 0x1f;
  lbz r9, 0x13(r4);
  rlwimi r7, r10, 8, 0x14, 0x17;
  lbz r10, 3(r4);
  rlwimi r8, r9, 4, 0x18, 0x1b;
  lbz r9, 0x14(r4);
  rlwimi r0, r10, 0xc, 0x10, 0x13;
  lbz r10, 0xf(r4);
  rlwimi r8, r9, 8, 0x14, 0x17;
  lbz r9, 0x15(r4);
  rlwimi r7, r10, 0xc, 0x10, 0x13;
  lbz r10, 4(r4);
  lbz r11, 8(r4);
  rlwimi r8, r9, 0xc, 0x10, 0x13;
  rlwimi r0, r10, 0x10, 0xc, 0xf;
  lbz r10, 0x10(r4);
  lbz r9, 0x16(r4);
  rlwimi r3, r11, 8, 0x14, 0x17;
  lbz r11, 9(r4);
  rlwimi r7, r10, 0x10, 0xc, 0xf;
  lbz r10, 5(r4);
  rlwimi r8, r9, 0x10, 0xc, 0xf;
  lbz r9, 0x11(r4);
  rlwimi r3, r11, 0xc, 0x10, 0x13;
  lbz r11, 0xa(r4);
  rlwimi r0, r10, 0x14, 8, 0xb;
  lbz r10, 0xb(r4);
  rlwimi r7, r9, 0x14, 8, 0xb;
  lbz r4, 0x17(r4);
  li r9, 1;
  rlwimi r3, r11, 0x10, 0xc, 0xf;
  rlwimi r3, r10, 0x14, 8, 0xb;
  rlwimi r8, r4, 0x14, 8, 0xb;
  rlwimi r0, r9, 0x18, 0, 7;
  li r10, 2;
  li r9, 3;
  li r4, 4;
  rlwimi r3, r10, 0x18, 0, 7;
  rlwimi r7, r9, 0x18, 0, 7;
  rlwimi r8, r4, 0x18, 0, 7;
  b lbl_8016fb5c;
lbl_8016fb3c:
  lis r8, 0x166;
  lis r3, 0x266;
  lis r7, 0x366;
  lis r4, 0x466;
  addi r0, r8, 0x6666;
  addi r3, r3, 0x6666;
  addi r7, r7, 0x6666;
  addi r8, r4, 0x6666;
lbl_8016fb5c:
  lis r9, 0xcc01;
  li r10, 0x61;
  stb r10, -0x8000(r9);
  cmpwi r5, 0;
  li r4, 0x53;
  li r11, 0;
  stw r0, -0x8000(r9);
  li r0, 0x54;
  li r12, 0;
  rlwimi r11, r4, 0x18, 0, 7;
  stb r10, -0x8000(r9);
  rlwimi r12, r0, 0x18, 0, 7;
  stw r3, -0x8000(r9);
  stb r10, -0x8000(r9);
  stw r7, -0x8000(r9);
  stb r10, -0x8000(r9);
  stw r8, -0x8000(r9);
  beq lbl_8016fbe0;
  lbz r4, 0(r6);
  lbz r0, 4(r6);
  rlwimi r11, r4, 0, 0x1a, 0x1f;
  lbz r3, 1(r6);
  rlwimi r12, r0, 0, 0x1a, 0x1f;
  lbz r5, 2(r6);
  rlwimi r11, r3, 6, 0x14, 0x19;
  lbz r3, 5(r6);
  lbz r4, 3(r6);
  rlwimi r11, r5, 0xc, 0xe, 0x13;
  lbz r0, 6(r6);
  rlwimi r12, r3, 6, 0x14, 0x19;
  rlwimi r11, r4, 0x12, 8, 0xd;
  rlwimi r12, r0, 0xc, 0xe, 0x13;
  b lbl_8016fbfc;
lbl_8016fbe0:
  li r3, 0x15;
  rlwinm r11, r11, 0, 0, 0x13;
  rlwimi r12, r3, 0, 0x1a, 0x1f;
  li r0, 0x16;
  rlwimi r11, r3, 0xc, 0xe, 0x13;
  rlwimi r11, r0, 0x12, 8, 0xd;
  rlwinm r12, r12, 0, 0x1a, 0xd;
lbl_8016fbfc:
  lis r4, 0xcc01;
  li r5, 0x61;
  stb r5, -0x8000(r4);
  li r0, 0;
  lwz r3, gx;
  stw r11, -0x8000(r4);
  stb r5, -0x8000(r4);
  stw r12, -0x8000(r4);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetDispCopyGamma
// PAL: 0x8016fc24..0x8016fc38
MARK_BINARY_BLOB(GXSetDispCopyGamma, 0x8016fc24, 0x8016fc38);
asm UNKNOWN_FUNCTION(GXSetDispCopyGamma) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x23c(r4);
  rlwimi r0, r3, 7, 0x17, 0x18;
  stw r0, 0x23c(r4);
  blr;
  // clang-format on
}

// Symbol: GXCopyDisp
// PAL: 0x8016fc38..0x8016fd74
MARK_BINARY_BLOB(GXCopyDisp, 0x8016fc38, 0x8016fd74);
asm void GXCopyDisp(void*, u8) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_8016fc6c;
  lwz r7, gx;
  lis r5, 0xcc01;
  li r0, 0x61;
  lwz r6, 0x228(r7);
  stb r0, -0x8000(r5);
  ori r6, r6, 0xf;
  stw r6, -0x8000(r5);
  lwz r6, 0x220(r7);
  stb r0, -0x8000(r5);
  rlwinm r0, r6, 0, 0, 0x1d;
  stw r0, -0x8000(r5);
lbl_8016fc6c:
  cmpwi r4, 0;
  li r12, 0;
  bne lbl_8016fc90;
  lwz r5, gx;
  lwz r0, 0x22c(r5);
  addi r10, r5, 0x22c;
  clrlwi r0, r0, 0x1d;
  cmplwi r0, 3;
  bne lbl_8016fcc0;
lbl_8016fc90:
  lwz r5, gx;
  lwz r7, 0x22c(r5);
  addi r10, r5, 0x22c;
  rlwinm r0, r7, 0x1a, 0x1f, 0x1f;
  cmplwi r0, 1;
  bne lbl_8016fcc0;
  lis r6, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r6);
  rlwinm r0, r7, 0, 0x1a, 0x18;
  li r12, 1;
  stw r0, -0x8000(r6);
lbl_8016fcc0:
  lis r8, 0xcc01;
  li r9, 0x61;
  stb r9, -0x8000(r8);
  li r6, 0;
  lwz r11, gx;
  rlwimi r6, r3, 0x1b, 8, 0x1f;
  li r3, 0x4b;
  li r0, 0x52;
  lwz r7, 0x230(r11);
  rlwimi r6, r3, 0x18, 0, 7;
  cmpwi r4, 0;
  stw r7, -0x8000(r8);
  stb r9, -0x8000(r8);
  lwz r3, 0x234(r11);
  stw r3, -0x8000(r8);
  stb r9, -0x8000(r8);
  lwz r3, 0x238(r11);
  stw r3, -0x8000(r8);
  stb r9, -0x8000(r8);
  stw r6, -0x8000(r8);
  lwz r3, 0x23c(r11);
  rlwimi r3, r4, 0xb, 0x14, 0x14;
  ori r3, r3, 0x4000;
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x23c(r11);
  stb r9, -0x8000(r8);
  lwz r0, 0x23c(r11);
  stw r0, -0x8000(r8);
  beq lbl_8016fd4c;
  stb r9, -0x8000(r8);
  lwz r0, 0x228(r11);
  stw r0, -0x8000(r8);
  stb r9, -0x8000(r8);
  lwz r0, 0x220(r11);
  stw r0, -0x8000(r8);
lbl_8016fd4c:
  cmpwi r12, 0;
  beq lbl_8016fd68;
  lis r3, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r3);
  lwz r0, 0(r10);
  stw r0, -0x8000(r3);
lbl_8016fd68:
  li r0, 0;
  sth r0, 2(r5);
  blr;
  // clang-format on
}

// Symbol: GXCopyTex
// PAL: 0x8016fd74..0x8016fecc
MARK_BINARY_BLOB(GXCopyTex, 0x8016fd74, 0x8016fecc);
asm UNKNOWN_FUNCTION(GXCopyTex) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_8016fda8;
  lwz r7, gx;
  lis r5, 0xcc01;
  li r0, 0x61;
  lwz r6, 0x228(r7);
  stb r0, -0x8000(r5);
  ori r6, r6, 0xf;
  stw r6, -0x8000(r5);
  lwz r6, 0x220(r7);
  stb r0, -0x8000(r5);
  rlwinm r0, r6, 0, 0, 0x1d;
  stw r0, -0x8000(r5);
lbl_8016fda8:
  lwz r9, gx;
  li r11, 0;
  lbz r0, 0x250(r9);
  lwz r6, 0x22c(r9);
  cmpwi r0, 0;
  beq lbl_8016fdd8;
  clrlwi r0, r6, 0x1d;
  cmplwi r0, 3;
  beq lbl_8016fdd8;
  li r0, 3;
  li r11, 1;
  rlwimi r6, r0, 0, 0x1d, 0x1f;
lbl_8016fdd8:
  cmpwi r4, 0;
  bne lbl_8016fdec;
  clrlwi r0, r6, 0x1d;
  cmplwi r0, 3;
  bne lbl_8016fe00;
lbl_8016fdec:
  rlwinm r0, r6, 0x1a, 0x1f, 0x1f;
  cmplwi r0, 1;
  bne lbl_8016fe00;
  li r11, 1;
  rlwinm r6, r6, 0, 0x1a, 0x18;
lbl_8016fe00:
  cmpwi r11, 0;
  beq lbl_8016fe18;
  lis r5, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r5);
  stw r6, -0x8000(r5);
lbl_8016fe18:
  lis r7, 0xcc01;
  li r8, 0x61;
  stb r8, -0x8000(r7);
  li r5, 0;
  lwz r10, gx;
  rlwimi r5, r3, 0x1b, 8, 0x1f;
  li r3, 0x4b;
  li r0, 0x52;
  lwz r6, 0x240(r10);
  rlwimi r5, r3, 0x18, 0, 7;
  cmpwi r4, 0;
  stw r6, -0x8000(r7);
  stb r8, -0x8000(r7);
  lwz r3, 0x244(r10);
  stw r3, -0x8000(r7);
  stb r8, -0x8000(r7);
  lwz r3, 0x248(r10);
  stw r3, -0x8000(r7);
  stb r8, -0x8000(r7);
  stw r5, -0x8000(r7);
  lwz r3, 0x24c(r10);
  rlwimi r3, r4, 0xb, 0x14, 0x14;
  rlwinm r3, r3, 0, 0x12, 0x10;
  rlwimi r3, r0, 0x18, 0, 7;
  stw r3, 0x24c(r10);
  stb r8, -0x8000(r7);
  lwz r0, 0x24c(r10);
  stw r0, -0x8000(r7);
  beq lbl_8016fea4;
  stb r8, -0x8000(r7);
  lwz r0, 0x228(r10);
  stw r0, -0x8000(r7);
  stb r8, -0x8000(r7);
  lwz r0, 0x220(r10);
  stw r0, -0x8000(r7);
lbl_8016fea4:
  cmpwi r11, 0;
  beq lbl_8016fec0;
  lis r3, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r3);
  lwz r0, 0x22c(r9);
  stw r0, -0x8000(r3);
lbl_8016fec0:
  li r0, 0;
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXClearBoundingBox
// PAL: 0x8016fecc..0x8016ff04
MARK_BINARY_BLOB(GXClearBoundingBox, 0x8016fecc, 0x8016ff04);
asm UNKNOWN_FUNCTION(GXClearBoundingBox) {
  // clang-format off
  nofralloc;
  lis r5, 0xcc01;
  li r6, 0x61;
  lis r3, 0x5500;
  stb r6, -0x8000(r5);
  addi r0, r3, 0x3ff;
  stw r0, -0x8000(r5);
  lis r3, 0x5600;
  addi r4, r3, 0x3ff;
  lwz r3, gx;
  stb r6, -0x8000(r5);
  li r0, 0;
  stw r4, -0x8000(r5);
  sth r0, 2(r3);
  blr;
  // clang-format on
}
