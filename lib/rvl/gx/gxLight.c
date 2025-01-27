#include "gxLight.h"

#include <math.h>

extern const f32 unk_80388700;
extern const f32 unk_80388704;
extern const f32 unk_80388708;
extern const f32 unk_8038870c;
extern const f32 unk_80388710;
extern const f32 unk_80388714;
extern const f32 unk_80388718;
extern const f32 unk_8038871c;
extern const f32 unk_80388720;
extern const f32 unk_80388724;
extern const f32 unk_80388728;
extern const f32 unk_8038872c;
extern const f32 unk_80388730;

// Symbol: GXInitLightAttn
// PAL: 0x8016ff04..0x8016ff20
MARK_BINARY_BLOB(GXInitLightAttn, 0x8016ff04, 0x8016ff20);
asm void GXInitLightAttn(GXLightObj*, float, float, float, float, float,
                         float) {
  // clang-format off
  nofralloc;
  stfs f1, 0x10(r3);
  stfs f2, 0x14(r3);
  stfs f3, 0x18(r3);
  stfs f4, 0x1c(r3);
  stfs f5, 0x20(r3);
  stfs f6, 0x24(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitLightAttnA
// PAL: 0x8016ff20..0x8016ff30
MARK_BINARY_BLOB(GXInitLightAttnA, 0x8016ff20, 0x8016ff30);
asm void GXInitLightAttnA(GXLightObj*, float, float, float) {
  // clang-format off
  nofralloc;
  stfs f1, 0x10(r3);
  stfs f2, 0x14(r3);
  stfs f3, 0x18(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitLightAttnK
// PAL: 0x8016ff30..0x8016ff40
MARK_BINARY_BLOB(GXInitLightAttnK, 0x8016ff30, 0x8016ff40);
asm void GXInitLightAttnK(GXLightObj*, float, float, float) {
  // clang-format off
  nofralloc;
  stfs f1, 0x1c(r3);
  stfs f2, 0x20(r3);
  stfs f3, 0x24(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitLightSpot
// PAL: 0x8016ff40..0x801700c8
MARK_BINARY_BLOB(GXInitLightSpot, 0x8016ff40, 0x801700c8);
asm void GXInitLightSpot(GXLightObj*, float, GXSpotFn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lfs f0, unk_80388700;
  stw r0, 0x14(r1);
  fcmpo cr0, f1, f0;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  cror 2, 0, 2;
  beq lbl_8016ff78;
  lfs f0, unk_80388704;
  fcmpo cr0, f1, f0;
  ble lbl_8016ff7c;
lbl_8016ff78:
  li r31, 0;
lbl_8016ff7c:
  lfs f2, unk_80388708;
  lfs f0, unk_8038870c;
  fmuls f1, f2, f1;
  fdivs f1, f1, f0;
  bl cos;
  cmplwi r31, 6;
  frsp f5, f1;
  bgt lbl_80170098;
  lis r3, 0x8029;
  slwi r0, r31, 2;
  addi r3, r3, -23688;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lfs f0, unk_80388710;
  lfs f1, unk_80388714;
  fmuls f3, f0, f5;
  lfs f6, unk_80388700;
  b lbl_801700a4;
  lfs f2, unk_80388718;
  fneg f0, f5;
  lfs f6, unk_80388700;
  fsubs f1, f2, f5;
  fdivs f1, f2, f1;
  fmuls f3, f0, f1;
  b lbl_801700a4;
  lfs f2, unk_80388718;
  fneg f0, f5;
  lfs f3, unk_80388700;
  fsubs f1, f2, f5;
  fdivs f6, f2, f1;
  fmuls f1, f0, f6;
  b lbl_801700a4;
  lfs f3, unk_80388718;
  lfs f1, unk_8038871c;
  fsubs f2, f3, f5;
  fsubs f0, f5, f1;
  fmuls f2, f2, f2;
  fmuls f0, f5, f0;
  fdivs f2, f3, f2;
  fmuls f3, f2, f0;
  fmuls f1, f1, f2;
  fneg f6, f2;
  b lbl_801700a4;
  lfs f4, unk_80388718;
  lfs f0, unk_80388724;
  fsubs f3, f4, f5;
  lfs f2, unk_80388720;
  fadds f1, f4, f5;
  fmuls f3, f3, f3;
  fmuls f0, f0, f1;
  fdivs f1, f4, f3;
  fmuls f6, f2, f1;
  fmuls f1, f0, f1;
  fmuls f3, f6, f5;
  b lbl_801700a4;
  lfs f4, unk_80388718;
  lfs f0, unk_8038871c;
  fsubs f3, f4, f5;
  lfs f1, unk_80388724;
  fmuls f2, f0, f5;
  lfs f0, unk_80388728;
  fmuls f1, f1, f5;
  fmuls f3, f3, f3;
  fmuls f2, f2, f5;
  fdivs f3, f4, f3;
  fmuls f2, f3, f2;
  fmuls f1, f1, f3;
  fmuls f6, f0, f3;
  fsubs f3, f4, f2;
  b lbl_801700a4;
lbl_80170098:
  lfs f1, unk_80388700;
  lfs f3, unk_80388718;
  fmr f6, f1;
lbl_801700a4:
  stfs f3, 0x10(r30);
  stfs f1, 0x14(r30);
  stfs f6, 0x18(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitLightDistAttn
// PAL: 0x801700c8..0x80170198
MARK_BINARY_BLOB(GXInitLightDistAttn, 0x801700c8, 0x80170198);
asm void GXInitLightDistAttn(GXLightObj*, float, float, GXDistAttnFn) {
  // clang-format off
  nofralloc;
  lfs f0, unk_80388700;
  fcmpo cr0, f1, f0;
  bge lbl_801700d8;
  li r4, 0;
lbl_801700d8:
  lfs f0, unk_80388700;
  fcmpo cr0, f2, f0;
  cror 2, 0, 2;
  beq lbl_801700f8;
  lfs f0, unk_80388718;
  fcmpo cr0, f2, f0;
  cror 2, 1, 2;
  bne lbl_801700fc;
lbl_801700f8:
  li r4, 0;
lbl_801700fc:
  cmpwi r4, 2;
  beq lbl_8017013c;
  bge lbl_80170118;
  cmpwi r4, 0;
  beq lbl_8017017c;
  bge lbl_80170124;
  b lbl_8017017c;
lbl_80170118:
  cmpwi r4, 4;
  bge lbl_8017017c;
  b lbl_80170160;
lbl_80170124:
  lfs f5, unk_80388718;
  fmuls f0, f2, f1;
  lfs f4, unk_80388700;
  fsubs f1, f5, f2;
  fdivs f3, f1, f0;
  b lbl_80170188;
lbl_8017013c:
  lfs f5, unk_80388718;
  fmuls f3, f2, f1;
  lfs f4, unk_8038872c;
  fsubs f2, f5, f2;
  fmuls f0, f1, f3;
  fmuls f1, f4, f2;
  fdivs f3, f1, f3;
  fdivs f4, f1, f0;
  b lbl_80170188;
lbl_80170160:
  fmuls f0, f2, f1;
  lfs f5, unk_80388718;
  lfs f3, unk_80388700;
  fsubs f2, f5, f2;
  fmuls f0, f1, f0;
  fdivs f4, f2, f0;
  b lbl_80170188;
lbl_8017017c:
  lfs f3, unk_80388700;
  lfs f5, unk_80388718;
  fmr f4, f3;
lbl_80170188:
  stfs f5, 0x1c(r3);
  stfs f3, 0x20(r3);
  stfs f4, 0x24(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitLightPos
// PAL: 0x80170198..0x801701a8
MARK_BINARY_BLOB(GXInitLightPos, 0x80170198, 0x801701a8);
asm void GXInitLightPos(GXLightObj*, float, float, float) {
  // clang-format off
  nofralloc;
  stfs f1, 0x28(r3);
  stfs f2, 0x2c(r3);
  stfs f3, 0x30(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetLightPos
// PAL: 0x801701a8..0x801701c4
MARK_BINARY_BLOB(GXGetLightPos, 0x801701a8, 0x801701c4);
asm void GXGetLightPos(const GXLightObj*, float*, float*, float*) {
  // clang-format off
  nofralloc;
  lfs f0, 0x28(r3);
  lfs f1, 0x2c(r3);
  stfs f0, 0(r4);
  lfs f0, 0x30(r3);
  stfs f1, 0(r5);
  stfs f0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: GXInitLightDir
// PAL: 0x801701c4..0x801701e0
MARK_BINARY_BLOB(GXInitLightDir, 0x801701c4, 0x801701e0);
asm void GXInitLightDir(GXLightObj*, float, float, float) {
  // clang-format off
  nofralloc;
  fneg f4, f1;
  fneg f1, f2;
  fneg f0, f3;
  stfs f4, 0x34(r3);
  stfs f1, 0x38(r3);
  stfs f0, 0x3c(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetLightDir
// PAL: 0x801701e0..0x80170208
MARK_BINARY_BLOB(GXGetLightDir, 0x801701e0, 0x80170208);
asm void GXGetLightDir(const GXLightObj*, float*, float*, float*) {
  // clang-format off
  nofralloc;
  lfs f0, 0x34(r3);
  lfs f1, 0x38(r3);
  fneg f2, f0;
  lfs f0, 0x3c(r3);
  fneg f1, f1;
  fneg f0, f0;
  stfs f2, 0(r4);
  stfs f1, 0(r5);
  stfs f0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: GXInitSpecularDir
// PAL: 0x80170208..0x80170314
MARK_BINARY_BLOB(GXInitSpecularDir, 0x80170208, 0x80170314);
asm void GXInitSpecularDir(GXLightObj*, float, float, float) {
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
  stfd f27, 0x20(r1);
  psq_st f27, 40(r1), 0, 0;
  stfd f26, 0x10(r1);
  psq_st f26, 24(r1), 0, 0;
  fneg f31, f1;
  fneg f30, f2;
  lfs f4, unk_80388718;
  fneg f6, f3;
  stw r31, 0xc(r1);
  fmuls f5, f31, f31;
  fmr f26, f1;
  fadds f29, f4, f6;
  lfs f0, unk_80388700;
  fmuls f4, f30, f30;
  mr r31, r3;
  fmr f27, f2;
  fmuls f6, f29, f29;
  fadds f1, f5, f4;
  fmr f28, f3;
  fadds f1, f6, f1;
  fcmpu cr0, f0, f1;
  beq lbl_8017029c;
  bl sqrt;
  frsp f1, f1;
  lfs f0, unk_80388718;
  fdivs f1, f0, f1;
lbl_8017029c:
  lfs f0, unk_80388730;
  fmuls f5, f31, f1;
  fmuls f4, f30, f1;
  fmuls f3, f29, f1;
  fmuls f2, f0, f26;
  stfs f5, 0x34(r31);
  fmuls f1, f0, f27;
  fmuls f0, f0, f28;
  stfs f4, 0x38(r31);
  stfs f3, 0x3c(r31);
  stfs f2, 0x28(r31);
  stfs f1, 0x2c(r31);
  stfs f0, 0x30(r31);
  psq_l f31, 104(r1), 0, 0;
  lfd f31, 0x60(r1);
  psq_l f30, 88(r1), 0, 0;
  lfd f30, 0x50(r1);
  psq_l f29, 72(r1), 0, 0;
  lfd f29, 0x40(r1);
  psq_l f28, 56(r1), 0, 0;
  lfd f28, 0x30(r1);
  psq_l f27, 40(r1), 0, 0;
  lfd f27, 0x20(r1);
  psq_l f26, 24(r1), 0, 0;
  lfd f26, 0x10(r1);
  lwz r31, 0xc(r1);
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: GXInitLightColor
// PAL: 0x80170314..0x80170320
MARK_BINARY_BLOB(GXInitLightColor, 0x80170314, 0x80170320);
asm void GXInitLightColor(GXLightObj*, GXColor*) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r4);
  stw r0, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: GXLoadLightObjImm
// PAL: 0x80170320..0x8017039c
MARK_BINARY_BLOB(GXLoadLightObjImm, 0x80170320, 0x8017039c);
asm UNKNOWN_FUNCTION(GXLoadLightObjImm) {
  // clang-format off
  nofralloc;
  cntlzw r0, r4;
  lis r4, 0xcc01;
  subfic r5, r0, 0x1f;
  li r0, 0x10;
  rlwinm r5, r5, 4, 0x19, 0x1b;
  stb r0, -0x8000(r4);
  addi r0, r5, 0x600;
  oris r0, r0, 0xf;
  stw r0, -0x8000(r4);
  lwz r0, 0xc(r3);
  xor r6, r6, r6;
  psq_l f5, 16(r3), 0, 0;
  psq_l f4, 24(r3), 0, 0;
  psq_l f3, 32(r3), 0, 0;
  psq_l f2, 40(r3), 0, 0;
  psq_l f1, 48(r3), 0, 0;
  psq_l f0, 56(r3), 0, 0;
  stwu r6, -0x8000(r4);
  stw r6, 0(r4);
  stw r6, 0(r4);
  stw r0, 0(r4);
  psq_st f5, 0(r4), 0, 0;
  psq_st f4, 0(r4), 0, 0;
  psq_st f3, 0(r4), 0, 0;
  psq_st f2, 0(r4), 0, 0;
  psq_st f1, 0(r4), 0, 0;
  psq_st f0, 0(r4), 0, 0;
  li r0, 1;
  lwz r3, gx;
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetChanAmbColor
// PAL: 0x8017039c..0x80170474
MARK_BINARY_BLOB(GXSetChanAmbColor, 0x8017039c, 0x80170474);
asm void GXSetChanAmbColor(int, GXColor) {
  // clang-format off
  nofralloc;
  cmpwi r3, 3;
  beq lbl_80170418;
  bge lbl_801703c0;
  cmpwi r3, 1;
  beq lbl_801703e8;
  bge lbl_80170400;
  cmpwi r3, 0;
  bge lbl_801703d0;
  blr;
lbl_801703c0:
  cmpwi r3, 5;
  beq lbl_8017043c;
  bgelr;
  b lbl_80170430;
lbl_801703d0:
  lwz r3, gx;
  li r8, 0;
  lwz r0, 0(r4);
  lwz r7, 0xa8(r3);
  rlwimi r7, r0, 0, 0, 0x17;
  b lbl_8017044c;
lbl_801703e8:
  lwz r3, gx;
  li r8, 1;
  lwz r0, 0(r4);
  lwz r7, 0xac(r3);
  rlwimi r7, r0, 0, 0, 0x17;
  b lbl_8017044c;
lbl_80170400:
  lwz r3, gx;
  li r8, 0;
  lbz r0, 3(r4);
  lwz r7, 0xa8(r3);
  rlwimi r7, r0, 0, 0x18, 0x1f;
  b lbl_8017044c;
lbl_80170418:
  lwz r3, gx;
  li r8, 1;
  lbz r0, 3(r4);
  lwz r7, 0xac(r3);
  rlwimi r7, r0, 0, 0x18, 0x1f;
  b lbl_8017044c;
lbl_80170430:
  lwz r7, 0(r4);
  li r8, 0;
  b lbl_8017044c;
lbl_8017043c:
  lwz r7, 0(r4);
  li r8, 1;
  b lbl_8017044c;
  blr;
lbl_8017044c:
  lwz r6, gx;
  li r3, 0x100;
  slwi r0, r8, 2;
  lwz r5, 0x5fc(r6);
  slw r4, r3, r8;
  add r3, r6, r0;
  or r0, r5, r4;
  stw r0, 0x5fc(r6);
  stw r7, 0xa8(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetChanMatColor
// PAL: 0x80170474..0x8017054c
MARK_BINARY_BLOB(GXSetChanMatColor, 0x80170474, 0x8017054c);
asm void GXSetChanMatColor(int, GXColor) {
  // clang-format off
  nofralloc;
  cmpwi r3, 3;
  beq lbl_801704f0;
  bge lbl_80170498;
  cmpwi r3, 1;
  beq lbl_801704c0;
  bge lbl_801704d8;
  cmpwi r3, 0;
  bge lbl_801704a8;
  blr;
lbl_80170498:
  cmpwi r3, 5;
  beq lbl_80170514;
  bgelr;
  b lbl_80170508;
lbl_801704a8:
  lwz r3, gx;
  li r8, 0;
  lwz r0, 0(r4);
  lwz r7, 0xb0(r3);
  rlwimi r7, r0, 0, 0, 0x17;
  b lbl_80170524;
lbl_801704c0:
  lwz r3, gx;
  li r8, 1;
  lwz r0, 0(r4);
  lwz r7, 0xb4(r3);
  rlwimi r7, r0, 0, 0, 0x17;
  b lbl_80170524;
lbl_801704d8:
  lwz r3, gx;
  li r8, 0;
  lbz r0, 3(r4);
  lwz r7, 0xb0(r3);
  rlwimi r7, r0, 0, 0x18, 0x1f;
  b lbl_80170524;
lbl_801704f0:
  lwz r3, gx;
  li r8, 1;
  lbz r0, 3(r4);
  lwz r7, 0xb4(r3);
  rlwimi r7, r0, 0, 0x18, 0x1f;
  b lbl_80170524;
lbl_80170508:
  lwz r7, 0(r4);
  li r8, 0;
  b lbl_80170524;
lbl_80170514:
  lwz r7, 0(r4);
  li r8, 1;
  b lbl_80170524;
  blr;
lbl_80170524:
  lwz r6, gx;
  li r3, 0x400;
  slwi r0, r8, 2;
  lwz r5, 0x5fc(r6);
  slw r4, r3, r8;
  add r3, r6, r0;
  or r0, r5, r4;
  stw r0, 0x5fc(r6);
  stw r7, 0xb0(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetNumChans
// PAL: 0x8017054c..0x80170570
MARK_BINARY_BLOB(GXSetNumChans, 0x8017054c, 0x80170570);
asm void GXSetNumChans(int nChans) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x254(r4);
  rlwimi r0, r3, 4, 0x19, 0x1b;
  stw r0, 0x254(r4);
  lwz r0, 0x5fc(r4);
  oris r0, r0, 0x100;
  ori r0, r0, 4;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetChanCtrl
// PAL: 0x80170570..0x80170614
MARK_BINARY_BLOB(GXSetChanCtrl, 0x80170570, 0x80170614);
asm void GXSetChanCtrl(int, int, int, int, int, int, int) {
  // clang-format off
  nofralloc;
  cmpwi r9, 0;
  li r10, 0;
  rlwimi r10, r4, 1, 0x1e, 0x1e;
  clrlwi r11, r3, 0x1e;
  rlwimi r10, r6, 0, 0x1f, 0x1f;
  rlwimi r10, r5, 6, 0x19, 0x19;
  bne lbl_80170590;
  li r8, 0;
lbl_80170590:
  subfic r5, r9, 2;
  addi r4, r9, -2;
  neg r0, r9;
  rlwimi r10, r8, 7, 0x17, 0x18;
  or r4, r5, r4;
  lwz r5, gx;
  rlwimi r10, r4, 0xa, 0x16, 0x16;
  or r0, r0, r9;
  rlwimi r10, r0, 0xb, 0x15, 0x15;
  slwi r4, r11, 2;
  rlwimi r10, r7, 2, 0x1a, 0x1d;
  li r0, 0x1000;
  add r4, r5, r4;
  cmpwi r3, 4;
  rlwimi r10, r7, 7, 0x11, 0x14;
  slw r0, r0, r11;
  stw r10, 0xb8(r4);
  lwz r4, 0x5fc(r5);
  or r0, r4, r0;
  stw r0, 0x5fc(r5);
  bne lbl_801705f8;
  stw r10, 0xc0(r5);
  lwz r0, 0x5fc(r5);
  ori r0, r0, 0x5000;
  stw r0, 0x5fc(r5);
  blr;
lbl_801705f8:
  cmpwi r3, 5;
  bnelr;
  stw r10, 0xc4(r5);
  lwz r0, 0x5fc(r5);
  ori r0, r0, 0xa000;
  stw r0, 0x5fc(r5);
  blr;
  // clang-format on
}
