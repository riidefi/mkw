#include "gxTransform.h"

#include "gx.h"

extern const f32 unk_803887e8;
extern const f32 unk_803887ec;
extern const f32 unk_803887f0;
extern const f32 unk_803887f4;
extern const f32 unk_803887f8;

// Symbol: __GXSetProjection
// PAL: 0x80172fd8..0x8017301c
MARK_BINARY_BLOB(__GXSetProjection, 0x80172fd8, 0x8017301c);
asm UNKNOWN_FUNCTION(__GXSetProjection) {
  // clang-format off
  nofralloc;
  lis r4, 0xcc01;
  li r0, 0x10;
  lis r3, 6;
  stb r0, -0x8000(r4);
  addi r0, r3, 0x1020;
  lwz r3, gx;
  stw r0, -0x8000(r4);
  addi r5, r4, -32768;
  psq_l f2, 1324(r3), 0, 0;
  psq_l f1, 1332(r3), 0, 0;
  psq_l f0, 1340(r3), 0, 0;
  psq_st f2, 0(r5), 0, 0;
  psq_st f1, 0(r5), 0, 0;
  psq_st f0, 0(r5), 0, 0;
  lwz r0, 0x528(r3);
  stw r0, -0x8000(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetProjection
// PAL: 0x8017301c..0x80173080
MARK_BINARY_BLOB(GXSetProjection, 0x8017301c, 0x80173080);
asm void GXSetProjection(const f32*, u32) {
  // clang-format off
  nofralloc;
  lwz r5, gx;
  cmpwi r4, 1;
  lfs f1, 0(r3);
  stw r4, 0x528(r5);
  lfs f0, 0x14(r3);
  stfs f1, 0x52c(r5);
  lfs f1, 0x28(r3);
  stfs f0, 0x534(r5);
  lfs f0, 0x2c(r3);
  stfs f1, 0x53c(r5);
  stfs f0, 0x540(r5);
  bne lbl_80173060;
  lfs f1, 0xc(r3);
  lfs f0, 0x1c(r3);
  stfs f1, 0x530(r5);
  stfs f0, 0x538(r5);
  b lbl_80173070;
lbl_80173060:
  lfs f1, 8(r3);
  lfs f0, 0x18(r3);
  stfs f1, 0x530(r5);
  stfs f0, 0x538(r5);
lbl_80173070:
  lwz r0, 0x5fc(r5);
  oris r0, r0, 0x800;
  stw r0, 0x5fc(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetProjectionv
// PAL: 0x80173080..0x801730cc
MARK_BINARY_BLOB(GXSetProjectionv, 0x80173080, 0x801730cc);
asm UNKNOWN_FUNCTION(GXSetProjectionv) {
  // clang-format off
  nofralloc;
  lfs f1, unk_803887e8;
  lfs f0, 0(r3);
  fcmpu cr0, f1, f0;
  bne lbl_80173098;
  li r0, 0;
  b lbl_8017309c;
lbl_80173098:
  li r0, 1;
lbl_8017309c:
  lwz r4, gx;
  stw r0, 0x528(r4);
  psq_l f2, 4(r3), 0, 0;
  psq_l f1, 12(r3), 0, 0;
  psq_l f0, 20(r3), 0, 0;
  psq_st f2, 1324(r4), 0, 0;
  psq_st f1, 1332(r4), 0, 0;
  psq_st f0, 1340(r4), 0, 0;
  lwz r0, 0x5fc(r4);
  oris r0, r0, 0x800;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXGetProjectionv
// PAL: 0x801730cc..0x8017310c
MARK_BINARY_BLOB(GXGetProjectionv, 0x801730cc, 0x8017310c);
asm UNKNOWN_FUNCTION(GXGetProjectionv) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x528(r4);
  cmpwi r0, 0;
  beq lbl_801730e4;
  lfs f0, unk_803887ec;
  b lbl_801730e8;
lbl_801730e4:
  lfs f0, unk_803887e8;
lbl_801730e8:
  stfs f0, 0(r3);
  lwz r4, gx;
  psq_l f2, 1324(r4), 0, 0;
  psq_l f1, 1332(r4), 0, 0;
  psq_l f0, 1340(r4), 0, 0;
  psq_st f2, 4(r3), 0, 0;
  psq_st f1, 12(r3), 0, 0;
  psq_st f0, 20(r3), 0, 0;
  blr;
  // clang-format on
}

// Symbol: GXLoadPosMtxImm
// PAL: 0x8017310c..0x8017315c
MARK_BINARY_BLOB(GXLoadPosMtxImm, 0x8017310c, 0x8017315c);
asm void GXLoadPosMtxImm(const f32 mtxPtr[3][4], u32 id2) {
  // clang-format off
  nofralloc;
  lis r5, 0xcc01;
  li r0, 0x10;
  slwi r4, r4, 2;
  stb r0, -0x8000(r5);
  oris r0, r4, 0xb;
  stw r0, -0x8000(r5);
  addi r4, r5, -32768;
  psq_l f5, 0(r3), 0, 0;
  psq_l f4, 8(r3), 0, 0;
  psq_l f3, 16(r3), 0, 0;
  psq_l f2, 24(r3), 0, 0;
  psq_l f1, 32(r3), 0, 0;
  psq_l f0, 40(r3), 0, 0;
  psq_st f5, 0(r4), 0, 0;
  psq_st f4, 0(r4), 0, 0;
  psq_st f3, 0(r4), 0, 0;
  psq_st f2, 0(r4), 0, 0;
  psq_st f1, 0(r4), 0, 0;
  psq_st f0, 0(r4), 0, 0;
  blr;
  // clang-format on
}

// Symbol: GXLoadPosMtxIndx
// PAL: 0x8017315c..0x80173188
MARK_BINARY_BLOB(GXLoadPosMtxIndx, 0x8017315c, 0x80173188);
asm UNKNOWN_FUNCTION(GXLoadPosMtxIndx) {
  // clang-format off
  nofralloc;
  slwi r0, r4, 2;
  li r6, 0;
  rlwimi r6, r0, 0, 0x14, 0x1f;
  lis r4, 0xcc01;
  li r0, 0x20;
  li r5, 0xb;
  rlwimi r6, r5, 0xc, 0x10, 0x13;
  stb r0, -0x8000(r4);
  rlwimi r6, r3, 0x10, 0, 0xf;
  stw r6, -0x8000(r4);
  blr;
  // clang-format on
}

// Symbol: GXLoadNrmMtxImm
// PAL: 0x80173188..0x801731e0
MARK_BINARY_BLOB(GXLoadNrmMtxImm, 0x80173188, 0x801731e0);
asm UNKNOWN_FUNCTION(GXLoadNrmMtxImm) {
  // clang-format off
  nofralloc;
  slwi r0, r4, 2;
  lis r5, 0xcc01;
  subf r4, r4, r0;
  li r0, 0x10;
  addi r4, r4, 0x400;
  stb r0, -0x8000(r5);
  oris r0, r4, 8;
  stw r0, -0x8000(r5);
  addi r4, r5, -32768;
  psq_l f5, 0(r3), 0, 0;
  lfs f4, 8(r3);
  psq_l f3, 16(r3), 0, 0;
  lfs f2, 0x18(r3);
  psq_l f1, 32(r3), 0, 0;
  lfs f0, 0x28(r3);
  psq_st f5, 0(r4), 0, 0;
  stfs f4, -0x8000(r5);
  psq_st f3, 0(r4), 0, 0;
  stfs f2, -0x8000(r5);
  psq_st f1, 0(r4), 0, 0;
  stfs f0, -0x8000(r5);
  blr;
  // clang-format on
}

// Symbol: GXLoadNrmMtxIndx3x3
// PAL: 0x801731e0..0x80173214
MARK_BINARY_BLOB(GXLoadNrmMtxIndx3x3, 0x801731e0, 0x80173214);
asm UNKNOWN_FUNCTION(GXLoadNrmMtxIndx3x3) {
  // clang-format off
  nofralloc;
  slwi r0, r4, 2;
  lis r5, 0xcc01;
  subf r4, r4, r0;
  li r6, 0;
  li r0, 0x28;
  addi r4, r4, 0x400;
  stb r0, -0x8000(r5);
  rlwimi r6, r4, 0, 0x14, 0x1f;
  li r4, 8;
  rlwimi r6, r4, 0xc, 0x10, 0x13;
  rlwimi r6, r3, 0x10, 0, 0xf;
  stw r6, -0x8000(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetCurrentMtx
// PAL: 0x80173214..0x80173234
MARK_BINARY_BLOB(GXSetCurrentMtx, 0x80173214, 0x80173234);
asm void GXSetCurrentMtx(u32) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x80(r4);
  rlwimi r0, r3, 0, 0x1a, 0x1f;
  stw r0, 0x80(r4);
  lwz r0, 0x5fc(r4);
  oris r0, r0, 0x400;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXLoadTexMtxImm
// PAL: 0x80173234..0x801732e8
MARK_BINARY_BLOB(GXLoadTexMtxImm, 0x80173234, 0x801732e8);
asm UNKNOWN_FUNCTION(GXLoadTexMtxImm) {
  // clang-format off
  nofralloc;
  cmplwi r4, 0x40;
  blt lbl_8017324c;
  addi r0, r4, -64;
  slwi r4, r0, 2;
  addi r7, r4, 0x500;
  b lbl_80173250;
lbl_8017324c:
  slwi r7, r4, 2;
lbl_80173250:
  cmpwi r5, 1;
  bne lbl_80173260;
  li r4, 8;
  b lbl_80173264;
lbl_80173260:
  li r4, 0xc;
lbl_80173264:
  addi r6, r4, -1;
  lis r4, 0xcc01;
  li r0, 0x10;
  cmpwi r5, 0;
  slwi r5, r6, 0x10;
  stb r0, -0x8000(r4);
  or r0, r7, r5;
  stw r0, -0x8000(r4);
  bne lbl_801732c0;
  addi r4, r4, -32768;
  psq_l f5, 0(r3), 0, 0;
  psq_l f4, 8(r3), 0, 0;
  psq_l f3, 16(r3), 0, 0;
  psq_l f2, 24(r3), 0, 0;
  psq_l f1, 32(r3), 0, 0;
  psq_l f0, 40(r3), 0, 0;
  psq_st f5, 0(r4), 0, 0;
  psq_st f4, 0(r4), 0, 0;
  psq_st f3, 0(r4), 0, 0;
  psq_st f2, 0(r4), 0, 0;
  psq_st f1, 0(r4), 0, 0;
  psq_st f0, 0(r4), 0, 0;
  blr;
lbl_801732c0:
  addi r4, r4, -32768;
  psq_l f3, 0(r3), 0, 0;
  psq_l f2, 8(r3), 0, 0;
  psq_l f1, 16(r3), 0, 0;
  psq_l f0, 24(r3), 0, 0;
  psq_st f3, 0(r4), 0, 0;
  psq_st f2, 0(r4), 0, 0;
  psq_st f1, 0(r4), 0, 0;
  psq_st f0, 0(r4), 0, 0;
  blr;
  // clang-format on
}

// Symbol: __GXSetViewport
// PAL: 0x801732e8..0x80173378
MARK_BINARY_BLOB(__GXSetViewport, 0x801732e8, 0x80173378);
asm UNKNOWN_FUNCTION(__GXSetViewport) {
  // clang-format off
  nofralloc;
  lwz r6, gx;
  lis r3, 5;
  lfs f6, unk_803887f0;
  lis r4, 0xcc01;
  lfs f2, 0x550(r6);
  li r5, 0x10;
  lfs f3, 0x54c(r6);
  addi r0, r3, 0x101a;
  fneg f1, f2;
  lfs f0, 0x544(r6);
  fmuls f7, f3, f6;
  lfs f4, 0x548(r6);
  fmuls f5, f2, f6;
  lfs f3, 0x554(r6);
  fmuls f8, f1, f6;
  lfs f2, 0x560(r6);
  lfs f1, 0x558(r6);
  fadds f6, f0, f7;
  lfs f0, 0x55c(r6);
  fmuls f3, f3, f2;
  fmuls f9, f1, f2;
  stb r5, -0x8000(r4);
  lfs f2, unk_803887f4;
  fadds f1, f4, f5;
  stw r0, -0x8000(r4);
  fsubs f3, f9, f3;
  stfs f7, -0x8000(r4);
  fadds f4, f2, f6;
  fadds f1, f2, f1;
  stfs f8, -0x8000(r4);
  fadds f0, f9, f0;
  stfs f3, -0x8000(r4);
  stfs f4, -0x8000(r4);
  stfs f1, -0x8000(r4);
  stfs f0, -0x8000(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetViewportJitter
// PAL: 0x80173378..0x801733b4
MARK_BINARY_BLOB(GXSetViewportJitter, 0x80173378, 0x801733b4);
asm void GXSetViewportJitter(f32, f32, f32, f32, f32, f32, u32) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  bne lbl_80173388;
  lfs f0, unk_803887f0;
  fsubs f2, f2, f0;
lbl_80173388:
  lwz r3, gx;
  stfs f1, 0x544(r3);
  stfs f2, 0x548(r3);
  stfs f3, 0x54c(r3);
  stfs f4, 0x550(r3);
  stfs f5, 0x554(r3);
  stfs f6, 0x558(r3);
  lwz r0, 0x5fc(r3);
  oris r0, r0, 0x1000;
  stw r0, 0x5fc(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetViewport
// PAL: 0x801733b4..0x801733e0
MARK_BINARY_BLOB(GXSetViewport, 0x801733b4, 0x801733e0);
asm void GXSetViewport(f32, f32, f32, f32, f32, f32) {
  // clang-format off
  nofralloc;
  lwz r3, gx;
  stfs f1, 0x544(r3);
  stfs f2, 0x548(r3);
  stfs f3, 0x54c(r3);
  stfs f4, 0x550(r3);
  stfs f5, 0x554(r3);
  stfs f6, 0x558(r3);
  lwz r0, 0x5fc(r3);
  oris r0, r0, 0x1000;
  stw r0, 0x5fc(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetViewportv
// PAL: 0x801733e0..0x80173400
MARK_BINARY_BLOB(GXGetViewportv, 0x801733e0, 0x80173400);
asm UNKNOWN_FUNCTION(GXGetViewportv) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  psq_l f2, 1348(r4), 0, 0;
  psq_l f1, 1356(r4), 0, 0;
  psq_l f0, 1364(r4), 0, 0;
  psq_st f2, 0(r3), 0, 0;
  psq_st f1, 8(r3), 0, 0;
  psq_st f0, 16(r3), 0, 0;
  blr;
  // clang-format on
}

// Symbol: GXSetZScaleOffset
// PAL: 0x80173400..0x80173430
MARK_BINARY_BLOB(GXSetZScaleOffset, 0x80173400, 0x80173430);
asm UNKNOWN_FUNCTION(GXSetZScaleOffset) {
  // clang-format off
  nofralloc;
  lfs f3, unk_803887f8;
  lfs f0, unk_803887ec;
  fmuls f1, f3, f1;
  lwz r3, gx;
  fmuls f2, f3, f2;
  fadds f0, f0, f1;
  stfs f2, 0x55c(r3);
  stfs f0, 0x560(r3);
  lwz r0, 0x5fc(r3);
  oris r0, r0, 0x1000;
  stw r0, 0x5fc(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetScissor
// PAL: 0x80173430..0x80173498
MARK_BINARY_BLOB(GXSetScissor, 0x80173430, 0x80173498);
asm void GXSetScissor(u32, u32, u32, u32) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  addi r4, r4, 0x156;
  addi r9, r3, 0x156;
  lis r7, 0xcc01;
  lwz r0, 0x148(r8);
  rlwimi r0, r4, 0, 0x15, 0x1f;
  rlwimi r0, r9, 0xc, 9, 0x13;
  add r6, r4, r6;
  stw r0, 0x148(r8);
  add r3, r9, r5;
  addi r5, r6, -1;
  li r4, 0x61;
  lwz r6, 0x14c(r8);
  addi r3, r3, -1;
  rlwimi r6, r5, 0, 0x15, 0x1f;
  li r0, 0;
  rlwimi r6, r3, 0xc, 9, 0x13;
  stw r6, 0x14c(r8);
  stb r4, -0x8000(r7);
  lwz r3, 0x148(r8);
  stw r3, -0x8000(r7);
  stb r4, -0x8000(r7);
  lwz r3, 0x14c(r8);
  stw r3, -0x8000(r7);
  sth r0, 2(r8);
  blr;
  // clang-format on
}

// Symbol: GXGetScissor
// PAL: 0x80173498..0x801734e0
MARK_BINARY_BLOB(GXGetScissor, 0x80173498, 0x801734e0);
asm UNKNOWN_FUNCTION(GXGetScissor) {
  // clang-format off
  nofralloc;
  lwz r7, gx;
  lwz r0, 0x148(r7);
  lwz r8, 0x14c(r7);
  rlwinm r10, r0, 0x14, 0x15, 0x1f;
  clrlwi r9, r0, 0x15;
  addi r7, r10, -342;
  rlwinm r0, r8, 0x14, 0x15, 0x1f;
  stw r7, 0(r3);
  addi r7, r9, -342;
  subf r3, r10, r0;
  clrlwi r0, r8, 0x15;
  stw r7, 0(r4);
  addi r4, r3, 1;
  subf r3, r9, r0;
  stw r4, 0(r5);
  addi r0, r3, 1;
  stw r0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: GXSetScissorBoxOffset
// PAL: 0x801734e0..0x8017351c
MARK_BINARY_BLOB(GXSetScissorBoxOffset, 0x801734e0, 0x8017351c);
asm void GXSetScissorBoxOffset(s32, s32) {
  // clang-format off
  nofralloc;
  addi r0, r3, 0x156;
  li r6, 0;
  rlwimi r6, r0, 0x1f, 0x16, 0x1f;
  lis r5, 0xcc01;
  li r0, 0x61;
  addi r3, r4, 0x156;
  stb r0, -0x8000(r5);
  rlwimi r6, r3, 9, 0xc, 0x15;
  li r0, 0x59;
  lwz r3, gx;
  rlwimi r6, r0, 0x18, 0, 7;
  stw r6, -0x8000(r5);
  li r0, 0;
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetClipMode
// PAL: 0x8017351c..0x80173544
MARK_BINARY_BLOB(GXSetClipMode, 0x8017351c, 0x80173544);
asm UNKNOWN_FUNCTION(GXSetClipMode) {
  // clang-format off
  nofralloc;
  lis r6, 0xcc01;
  li r0, 0x10;
  stb r0, -0x8000(r6);
  li r5, 0x1005;
  lwz r4, gx;
  li r0, 1;
  stw r5, -0x8000(r6);
  stw r3, -0x8000(r6);
  sth r0, 2(r4);
  blr;
  // clang-format on
}

// Symbol: __GXSetMatrixIndex
// PAL: 0x80173544..0x801735cc
MARK_BINARY_BLOB(__GXSetMatrixIndex, 0x80173544, 0x801735cc);
asm UNKNOWN_FUNCTION(__GXSetMatrixIndex) {
  // clang-format off
  nofralloc;
  cmpwi r3, 5;
  bge lbl_80173588;
  lis r5, 0xcc01;
  li r0, 8;
  stb r0, -0x8000(r5);
  li r0, 0x30;
  lwz r6, gx;
  li r3, 0x10;
  stb r0, -0x8000(r5);
  li r0, 0x1018;
  lwz r4, 0x80(r6);
  stw r4, -0x8000(r5);
  stb r3, -0x8000(r5);
  stw r0, -0x8000(r5);
  lwz r0, 0x80(r6);
  stw r0, -0x8000(r5);
  b lbl_801735c0;
lbl_80173588:
  lis r5, 0xcc01;
  li r0, 8;
  stb r0, -0x8000(r5);
  li r0, 0x40;
  lwz r6, gx;
  li r3, 0x10;
  stb r0, -0x8000(r5);
  li r0, 0x1019;
  lwz r4, 0x84(r6);
  stw r4, -0x8000(r5);
  stb r3, -0x8000(r5);
  stw r0, -0x8000(r5);
  lwz r0, 0x84(r6);
  stw r0, -0x8000(r5);
lbl_801735c0:
  li r0, 1;
  sth r0, 2(r6);
  blr;
  // clang-format on
}
