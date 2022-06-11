#include "eggLightObject.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(unk_80077660);
// PAL: 0x80077680
extern UNKNOWN_FUNCTION(unk_80077680);
// PAL: 0x800776d0
extern UNKNOWN_FUNCTION(unk_800776d0);
// PAL: 0x80077710
extern UNKNOWN_FUNCTION(unk_80077710);
// PAL: 0x80077750
extern UNKNOWN_FUNCTION(unk_80077750);
// PAL: 0x80077790
extern UNKNOWN_FUNCTION(unk_80077790);
// PAL: 0x800777d0
extern UNKNOWN_FUNCTION(unk_800777d0);
// PAL: 0x80077810
extern UNKNOWN_FUNCTION(unk_80077810);
// PAL: 0x80077890
extern UNKNOWN_FUNCTION(unk_80077890);
// PAL: 0x80085ab0
extern UNKNOWN_FUNCTION(VEC3TransformNormal);
// PAL: 0x8016ff04
extern UNKNOWN_FUNCTION(GXInitLightAttn);
// PAL: 0x8016ff20
extern UNKNOWN_FUNCTION(GXInitLightAttnA);
// PAL: 0x8016ff30
extern UNKNOWN_FUNCTION(GXInitLightAttnK);
// PAL: 0x8016ff40
extern UNKNOWN_FUNCTION(GXInitLightSpot);
// PAL: 0x801700c8
extern UNKNOWN_FUNCTION(GXInitLightDistAttn);
// PAL: 0x80170198
extern UNKNOWN_FUNCTION(GXInitLightPos);
// PAL: 0x801701c4
extern UNKNOWN_FUNCTION(GXInitLightDir);
// PAL: 0x80170314
extern UNKNOWN_FUNCTION(GXInitLightColor);
// PAL: 0x8019a91c
extern UNKNOWN_FUNCTION(PSMTXMultVec);
// PAL: 0x8019ac08
extern UNKNOWN_FUNCTION(PSVECScale);
// PAL: 0x8019ac68
extern UNKNOWN_FUNCTION(PSVECMag);
// PAL: 0x8019ad08
extern UNKNOWN_FUNCTION(C_VECHalfAngle);
// PAL: 0x8022b414
extern UNKNOWN_FUNCTION(unk_8022b414);
}

extern unk unk_80388d98, unk_80388da0, unk_80388da8, unk_80388db0, unk_80388d9c,
    unk_80388da4, unk_80388d98, unk_80388da0, unk_80388da8, unk_80388db0,
    unk_80388d9c, unk_80388da4, unk_80388b44, unk_80388b45, unk_80388b46,
    unk_80388b47, unk_80388b40, unk_80388b41, unk_80388b42, unk_80388b43,
    unk_80388dac, unk_80388db4;
extern unk unk_80388dc0, unk_80388db8, unk_80388dc8, unk_80388dcc;

// Symbol: unk_8022b6d4
// PAL: 0x8022b6d4..0x8022b7c0
MARK_BINARY_BLOB(unk_8022b6d4, 0x8022b6d4, 0x8022b7c0);
asm UNKNOWN_FUNCTION(unk_8022b6d4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  li r4, 1;
  lfs f7, unk_80388d98;
  li r0, 0x661;
  stw r31, 0xc(r1);
  li r31, 0;
  lfs f5, unk_80388da0;
  stw r30, 8(r1);
  lis r30, 0x802a;
  lfs f3, unk_80388da8;
  addi r30, r30, 0x3128;
  lfs f1, unk_80388db0;
  lfs f6, unk_80388d9c;
  lfs f4, unk_80388da4;
  lbz r12, unk_80388b44;
  lbz r11, unk_80388b45;
  lbz r10, unk_80388b46;
  lbz r9, unk_80388b47;
  lbz r8, unk_80388b40;
  lbz r7, unk_80388b41;
  lbz r6, unk_80388b42;
  lbz r5, unk_80388b43;
  lfs f2, unk_80388dac;
  lfs f0, unk_80388db4;
  stw r30, 0(r3);
  sth r31, 4(r3);
  sth r31, 6(r3);
  stfs f7, 8(r3);
  stfs f7, 0xc(r3);
  stfs f7, 0x10(r3);
  stfs f6, 0x14(r3);
  stfs f5, 0x18(r3);
  stfs f5, 0x1c(r3);
  stfs f7, 0x20(r3);
  stfs f4, 0x24(r3);
  stfs f7, 0x28(r3);
  stb r12, 0x2c(r3);
  stb r11, 0x2d(r3);
  stb r10, 0x2e(r3);
  stb r9, 0x2f(r3);
  stfs f3, 0x30(r3);
  stw r31, 0x34(r3);
  stfs f3, 0x38(r3);
  stb r8, 0x3c(r3);
  stb r7, 0x3d(r3);
  stb r6, 0x3e(r3);
  stb r5, 0x3f(r3);
  stw r4, 0x40(r3);
  stfs f2, 0x44(r3);
  stfs f1, 0x48(r3);
  stfs f1, 0x4c(r3);
  stw r31, 0x68(r3);
  stw r31, 0x6c(r3);
  stfs f0, 0x70(r3);
  sth r0, 0x76(r3);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8022b7c0
// PAL: 0x8022b7c0..0x8022b8d0
MARK_BINARY_BLOB(unk_8022b7c0, 0x8022b7c0, 0x8022b8d0);
asm UNKNOWN_FUNCTION(unk_8022b7c0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lfs f2, unk_80388d98;
  stw r0, 0x34(r1);
  lfs f0, unk_80388da0;
  stw r31, 0x2c(r1);
  mr r31, r3;
  lfs f1, unk_80388d9c;
  stfs f2, 8(r1);
  stfs f2, 0xc(r1);
  stfs f2, 0x10(r1);
  stfs f1, 0x14(r1);
  stfs f0, 0x18(r1);
  stfs f0, 0x1c(r1);
  stfs f1, 0x14(r3);
  stfs f0, 0x18(r3);
  stfs f0, 0x1c(r3);
  stfs f2, 8(r3);
  stfs f2, 0xc(r3);
  stfs f2, 0x10(r3);
  bl egglightsomething;
  addi r5, r2, -25692;
  addi r4, r2, -25696;
  lfs f0, unk_80388d98;
  li r3, 0;
  lfs f2, unk_80388db0;
  li r12, 0x661;
  lbz r11, unk_80388b44;
  li r0, 1;
  lbz r10, 1(r5);
  lbz r9, 2(r5);
  lbz r8, 3(r5);
  lbz r7, unk_80388b40;
  lbz r6, 1(r4);
  lbz r5, 2(r4);
  lbz r4, 3(r4);
  lfs f4, unk_80388da8;
  lfs f3, unk_80388dac;
  lfs f1, unk_80388db4;
  sth r12, 0x76(r31);
  stb r11, 0x2c(r31);
  stb r10, 0x2d(r31);
  stb r9, 0x2e(r31);
  stb r8, 0x2f(r31);
  stb r7, 0x3c(r31);
  stb r6, 0x3d(r31);
  stb r5, 0x3e(r31);
  stb r4, 0x3f(r31);
  stfs f4, 0x30(r31);
  stw r3, 0x34(r31);
  stw r0, 0x40(r31);
  stfs f3, 0x44(r31);
  stfs f2, 0x48(r31);
  stfs f2, 0x4c(r31);
  stw r3, 0x68(r31);
  stw r3, 0x6c(r31);
  stfs f1, 0x70(r31);
  stfs f0, 0x5c(r31);
  stfs f0, 0x50(r31);
  stfs f0, 0x60(r31);
  stfs f0, 0x54(r31);
  stfs f0, 0x64(r31);
  stfs f0, 0x58(r31);
  lwz r31, 0x2c(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022b8d0
// PAL: 0x8022b8d0..0x8022b9dc
MARK_BINARY_BLOB(unk_8022b8d0, 0x8022b8d0, 0x8022b9dc);
asm UNKNOWN_FUNCTION(unk_8022b8d0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  lis r5, 0x4330;
  lfd f5, unk_80388dc0;
  lbz r0, 0x2c(r3);
  stw r0, 0x1c(r1);
  lbz r4, 0x2d(r3);
  stw r5, 0x18(r1);
  lbz r0, 0x2e(r3);
  lfd f0, 0x18(r1);
  stw r4, 0x24(r1);
  fsubs f1, f0, f5;
  lfs f4, 0x30(r3);
  stw r5, 0x20(r1);
  lfs f8, 0x20(r3);
  fmuls f3, f1, f4;
  lfd f1, 0x20(r1);
  stw r0, 0x2c(r1);
  fsubs f1, f1, f5;
  lfs f0, unk_80388db8;
  stw r5, 0x28(r1);
  lfs f7, 0x24(r3);
  fcmpo cr0, f3, f0;
  fmuls f2, f1, f4;
  lfd f1, 0x28(r1);
  lfs f6, 0x28(r3);
  fsubs f1, f1, f5;
  stfs f8, 0x7c(r3);
  stfs f7, 0x80(r3);
  fmuls f1, f1, f4;
  stfs f6, 0x84(r3);
  stfs f3, 8(r1);
  stfs f2, 0xc(r1);
  stfs f1, 0x10(r1);
  cror 2, 0, 2;
  bne lbl_8022b960;
  b lbl_8022b964;
lbl_8022b960:
  fmr f3, f0;
lbl_8022b964:
  fctiwz f2, f3;
  lfs f1, 0xc(r1);
  lfs f0, unk_80388db8;
  stfd f2, 0x30(r1);
  fcmpo cr0, f1, f0;
  lwz r0, 0x34(r1);
  stb r0, 0x88(r3);
  cror 2, 0, 2;
  bne lbl_8022b98c;
  b lbl_8022b990;
lbl_8022b98c:
  fmr f1, f0;
lbl_8022b990:
  fctiwz f2, f1;
  lfs f1, 0x10(r1);
  lfs f0, unk_80388db8;
  stfd f2, 0x38(r1);
  fcmpo cr0, f1, f0;
  lwz r0, 0x3c(r1);
  stb r0, 0x89(r3);
  cror 2, 0, 2;
  bne lbl_8022b9b8;
  b lbl_8022b9bc;
lbl_8022b9b8:
  fmr f1, f0;
lbl_8022b9bc:
  fctiwz f0, f1;
  lbz r0, 0x2f(r3);
  stb r0, 0x8b(r3);
  stfd f0, 0x40(r1);
  lwz r0, 0x44(r1);
  stb r0, 0x8a(r3);
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_8022b9dc
// PAL: 0x8022b9dc..0x8022bc00
MARK_BINARY_BLOB(unk_8022b9dc, 0x8022b9dc, 0x8022bc00);
asm UNKNOWN_FUNCTION(unk_8022b9dc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r4;
  stw r30, 0x28(r1);
  mr r30, r3;
  lhz r0, 0x76(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8022bbe8;
  lwz r0, 0x34(r3);
  cmpwi r0, 1;
  bne lbl_8022ba7c;
  lfs f2, 0x28(r4);
  addi r3, r1, 0x14;
  lfs f1, 0x24(r4);
  lfs f0, 0x20(r4);
  fneg f2, f2;
  fneg f1, f1;
  fneg f0, f0;
  stfs f2, 0x1c(r1);
  stfs f0, 0x14(r1);
  stfs f1, 0x18(r1);
  bl PSVECMag;
  lfs f2, unk_80388d98;
  fcmpo cr0, f1, f2;
  ble lbl_8022ba6c;
  addi r3, r30, 0x20;
  addi r4, r1, 0x14;
  addi r5, r1, 8;
  bl C_VECHalfAngle;
  lfs f1, unk_80388da4;
  addi r3, r1, 8;
  addi r4, r30, 0x7c;
  bl PSVECScale;
  b lbl_8022ba7c;
lbl_8022ba6c:
  lfs f0, unk_80388da8;
  stfs f2, 0x80(r30);
  stfs f2, 0x7c(r30);
  stfs f0, 0x84(r30);
lbl_8022ba7c:
  lwz r0, 0x34(r30);
  cmpwi r0, 0;
  blt lbl_8022ba90;
  cmpwi r0, 1;
  ble lbl_8022bb68;
lbl_8022ba90:
  cmpwi r0, 3;
  beq lbl_8022baac;
  cmpwi r0, 4;
  beq lbl_8022bae4;
  cmpwi r0, 2;
  beq lbl_8022bb1c;
  b lbl_8022bbe8;
lbl_8022baac:
  lfs f1, unk_80388da4;
  lfs f0, 0x38(r30);
  lfs f2, unk_80388d98;
  fmuls f0, f1, f0;
  stfs f2, 0x98(r30);
  stfs f2, 0xa4(r30);
  stfs f2, 0x9c(r30);
  stfs f2, 0xa8(r30);
  stfs f1, 0xac(r30);
  stfs f0, 0xa0(r30);
  stfs f2, 0x94(r30);
  stfs f2, 0x90(r30);
  stfs f2, 0x8c(r30);
  b lbl_8022bbe8;
lbl_8022bae4:
  lfs f1, unk_80388da8;
  lfs f0, 0x38(r30);
  lfs f2, unk_80388d98;
  fmuls f0, f1, f0;
  stfs f2, 0x8c(r30);
  stfs f2, 0xa4(r30);
  stfs f2, 0x90(r30);
  stfs f2, 0xa8(r30);
  stfs f1, 0xac(r30);
  stfs f0, 0x94(r30);
  stfs f2, 0xa0(r30);
  stfs f2, 0x9c(r30);
  stfs f2, 0x98(r30);
  b lbl_8022bbe8;
lbl_8022bb1c:
  lfs f8, 0x20(r30);
  lfs f7, 0x24(r30);
  lfs f6, 0x28(r30);
  lfs f5, 8(r30);
  lfs f4, 0xc(r30);
  lfs f3, 0x10(r30);
  lfs f2, 0x14(r30);
  lfs f1, 0x18(r30);
  lfs f0, 0x1c(r30);
  stfs f8, 0xa4(r30);
  stfs f7, 0xa8(r30);
  stfs f6, 0xac(r30);
  stfs f5, 0x98(r30);
  stfs f4, 0x9c(r30);
  stfs f3, 0xa0(r30);
  stfs f2, 0x8c(r30);
  stfs f1, 0x90(r30);
  stfs f0, 0x94(r30);
  b lbl_8022bbe8;
lbl_8022bb68:
  mr r3, r31;
  addi r4, r30, 0x14;
  addi r5, r30, 0x8c;
  bl PSMTXMultVec;
  mr r3, r31;
  addi r4, r30, 8;
  addi r5, r30, 0x98;
  bl PSMTXMultVec;
  mr r4, r31;
  addi r3, r30, 0xa4;
  addi r5, r30, 0x7c;
  bl VEC3TransformNormal;
  addi r3, r30, 0xa4;
  bl PSVECMag;
  lfs f0, unk_80388d98;
  fcmpo cr0, f1, f0;
  ble lbl_8022bbdc;
  lfs f0, unk_80388da8;
  lfs f2, 0xa4(r30);
  fdivs f3, f0, f1;
  lfs f1, 0xa8(r30);
  lfs f0, 0xac(r30);
  fmuls f2, f2, f3;
  fmuls f1, f1, f3;
  fmuls f0, f0, f3;
  stfs f2, 0xa4(r30);
  stfs f1, 0xa8(r30);
  stfs f0, 0xac(r30);
  b lbl_8022bbe8;
lbl_8022bbdc:
  stfs f0, 0xac(r30);
  stfs f0, 0xa8(r30);
  stfs f0, 0xa4(r30);
lbl_8022bbe8:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022bc00
// PAL: 0x8022bc00..0x8022bd04
MARK_BINARY_BLOB(unk_8022bc00, 0x8022bc00, 0x8022bd04);
asm UNKNOWN_FUNCTION(unk_8022bc00) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  lis r10, 0x4330;
  lfs f2, 0xa4(r3);
  lfs f1, 0xa8(r3);
  lfs f0, 0xac(r3);
  stfs f0, 8(r5);
  lhz r0, 4(r3);
  stfs f2, 0(r5);
  lbz r9, 0x88(r3);
  slwi r0, r0, 2;
  stfs f1, 4(r5);
  lbz r8, 0x89(r3);
  lbz r7, 0x8a(r3);
  lbz r5, 0x8b(r3);
  stb r9, 0(r6);
  lwz r3, 0x48(r4);
  stb r8, 1(r6);
  lfs f0, unk_80388da8;
  stb r7, 2(r6);
  stb r5, 3(r6);
  lfsx f5, r3, r0;
  stw r10, 8(r1);
  fcmpo cr0, f5, f0;
  stw r10, 0x10(r1);
  bge lbl_8022bcec;
  stw r9, 0xc(r1);
  lfd f4, unk_80388dc0;
  lfd f0, 8(r1);
  stw r8, 0x14(r1);
  fsubs f1, f0, f4;
  lfd f0, 0x10(r1);
  stw r7, 0xc(r1);
  fmuls f3, f1, f5;
  fsubs f2, f0, f4;
  stw r5, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fctiwz f3, f3;
  fsubs f1, f1, f4;
  fsubs f0, f0, f4;
  stfd f3, 0x18(r1);
  fmuls f2, f2, f5;
  fmuls f1, f1, f5;
  lwz r5, 0x1c(r1);
  fmuls f0, f0, f5;
  fctiwz f2, f2;
  stb r5, 0(r6);
  fctiwz f1, f1;
  fctiwz f0, f0;
  stfd f2, 0x20(r1);
  stfd f1, 0x28(r1);
  lwz r4, 0x24(r1);
  stfd f0, 0x30(r1);
  lwz r3, 0x2c(r1);
  lwz r0, 0x34(r1);
  stb r4, 1(r6);
  stb r3, 2(r6);
  stb r0, 3(r6);
  b lbl_8022bcfc;
lbl_8022bcec:
  stb r9, 0(r6);
  stb r8, 1(r6);
  stb r7, 2(r6);
  stb r5, 3(r6);
lbl_8022bcfc:
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: unk_8022bd04
// PAL: 0x8022bd04..0x8022bf34
MARK_BINARY_BLOB(unk_8022bd04, 0x8022bd04, 0x8022bf34);
asm UNKNOWN_FUNCTION(unk_8022bd04) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lhz r5, 0x76(r3);
  stw r0, 0x34(r1);
  clrlwi. r0, r5, 0x1f;
  stw r31, 0x2c(r1);
  mr r31, r4;
  stw r30, 0x28(r1);
  mr r30, r3;
  beq lbl_8022bef0;
  rlwinm. r0, r5, 0, 0x19, 0x19;
  beq lbl_8022bef0;
  lbz r7, 0x88(r3);
  addi r4, r1, 0xc;
  lbz r6, 0x89(r3);
  lbz r5, 0x8a(r3);
  lbz r0, 0x8b(r3);
  mr r3, r31;
  stb r7, 0xc(r1);
  stb r6, 0xd(r1);
  stb r5, 0xe(r1);
  stb r0, 0xf(r1);
  bl GXInitLightColor;
  lwz r0, 0x40(r30);
  cmpwi r0, 1;
  beq lbl_8022bd80;
  cmpwi r0, 0;
  beq lbl_8022bdd4;
  cmpwi r0, 2;
  beq lbl_8022be08;
  b lbl_8022be30;
lbl_8022bd80:
  lfs f0, unk_80388dc8;
  addi r4, r1, 0x10;
  psq_l f2, 164(r30), 0, 0;
  mr r3, r31;
  ps_muls0 f1, f2, f0;
  psq_l f2, 172(r30), 1, 0;
  psq_st f1, 0(r4), 0, 0;
  ps_muls0 f1, f2, f0;
  psq_st f1, 8(r4), 1, 0;
  lfs f1, 0x10(r1);
  lfs f2, 0x14(r1);
  lfs f3, 0x18(r1);
  bl GXInitLightPos;
  lis r5, 0x8025;
  mr r3, r31;
  addi r4, r5, 0x7838;
  lfs f1, 0x7838(r5);
  lfs f2, 4(r4);
  lfs f3, 8(r4);
  bl GXInitLightDir;
  b lbl_8022be30;
lbl_8022bdd4:
  lfs f1, 0x8c(r30);
  mr r3, r31;
  lfs f2, 0x90(r30);
  lfs f3, 0x94(r30);
  bl GXInitLightPos;
  lis r5, 0x8025;
  mr r3, r31;
  addi r4, r5, 0x7838;
  lfs f1, 0x7838(r5);
  lfs f2, 4(r4);
  lfs f3, 8(r4);
  bl GXInitLightDir;
  b lbl_8022be30;
lbl_8022be08:
  lfs f1, 0x8c(r30);
  mr r3, r31;
  lfs f2, 0x90(r30);
  lfs f3, 0x94(r30);
  bl GXInitLightPos;
  lfs f1, 0xa4(r30);
  mr r3, r31;
  lfs f2, 0xa8(r30);
  lfs f3, 0xac(r30);
  bl GXInitLightDir;
lbl_8022be30:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8022be54;
  lfs f1, 0x50(r30);
  mr r3, r31;
  lfs f2, 0x54(r30);
  lfs f3, 0x58(r30);
  bl GXInitLightAttnA;
  b lbl_8022be78;
lbl_8022be54:
  lfs f1, 0x44(r30);
  mr r3, r31;
  lfs f0, unk_80388d98;
  fcmpo cr0, f1, f0;
  ble lbl_8022be6c;
  b lbl_8022be70;
lbl_8022be6c:
  lfs f1, unk_80388dcc;
lbl_8022be70:
  lwz r4, 0x68(r30);
  bl GXInitLightSpot;
lbl_8022be78:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x17, 0x17;
  beq lbl_8022be9c;
  lfs f1, 0x5c(r30);
  mr r3, r31;
  lfs f2, 0x60(r30);
  lfs f3, 0x64(r30);
  bl GXInitLightAttnK;
  b lbl_8022beb8;
lbl_8022be9c:
  lfs f1, 0x38(r30);
  mr r3, r31;
  lfs f0, 0x48(r30);
  lfs f2, 0x4c(r30);
  fmuls f1, f0, f1;
  lwz r4, 0x6c(r30);
  bl GXInitLightDistAttn;
lbl_8022beb8:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x14, 0x14;
  beq lbl_8022bf1c;
  lfs f2, 0x70(r30);
  mr r3, r31;
  lfs f0, unk_80388db0;
  lfs f1, unk_80388d98;
  fmuls f4, f2, f0;
  lfs f3, unk_80388da8;
  fmr f2, f1;
  fmr f5, f1;
  fsubs f6, f3, f4;
  bl GXInitLightAttn;
  b lbl_8022bf1c;
lbl_8022bef0:
  lbz r7, unk_80388b40;
  mr r3, r31;
  lbz r6, unk_80388b41;
  addi r4, r1, 8;
  lbz r5, unk_80388b42;
  lbz r0, unk_80388b43;
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl GXInitLightColor;
lbl_8022bf1c:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022bf34
// PAL: 0x8022bf34..0x8022c09c
MARK_BINARY_BLOB(unk_8022bf34, 0x8022bf34, 0x8022c09c);
asm UNKNOWN_FUNCTION(unk_8022bf34) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lhz r5, 0x76(r3);
  stw r0, 0x24(r1);
  clrlwi. r0, r5, 0x1f;
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  beq lbl_8022c078;
  rlwinm. r0, r5, 0, 0x19, 0x19;
  beq lbl_8022c078;
  mr r3, r31;
  bl unk_80077660;
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x16, 0x16;
  bne lbl_8022bf84;
  lwz r0, 0(r31);
  ori r0, r0, 0x10;
  stw r0, 0(r31);
lbl_8022bf84:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x15, 0x15;
  bne lbl_8022bf9c;
  lwz r0, 0(r31);
  ori r0, r0, 0x20;
  stw r0, 0(r31);
lbl_8022bf9c:
  lwz r0, 0(r31);
  mr r3, r31;
  lbz r7, 0x88(r30);
  addi r4, r1, 8;
  ori r0, r0, 4;
  stw r0, 0(r31);
  lbz r6, 0x89(r30);
  lbz r5, 0x8a(r30);
  lbz r0, 0x8b(r30);
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl unk_80077680;
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8022bff8;
  lfs f1, 0x50(r30);
  mr r3, r31;
  lfs f2, 0x54(r30);
  lfs f3, 0x58(r30);
  bl unk_80077790;
  b lbl_8022c01c;
lbl_8022bff8:
  lfs f1, 0x44(r30);
  mr r3, r31;
  lfs f0, unk_80388d98;
  fcmpo cr0, f1, f0;
  ble lbl_8022c010;
  b lbl_8022c014;
lbl_8022c010:
  lfs f1, unk_80388dcc;
lbl_8022c014:
  lwz r4, 0x68(r30);
  bl unk_80077750;
lbl_8022c01c:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x17, 0x17;
  beq lbl_8022c040;
  lfs f1, 0x5c(r30);
  mr r3, r31;
  lfs f2, 0x60(r30);
  lfs f3, 0x64(r30);
  bl unk_80077810;
  b lbl_8022c05c;
lbl_8022c040:
  lfs f1, 0x38(r30);
  mr r3, r31;
  lfs f0, 0x48(r30);
  lfs f2, 0x4c(r30);
  fmuls f1, f0, f1;
  lwz r4, 0x6c(r30);
  bl unk_800777d0;
lbl_8022c05c:
  lhz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x14, 0x14;
  beq lbl_8022c084;
  lfs f1, 0x70(r30);
  mr r3, r31;
  bl unk_80077890;
  b lbl_8022c084;
lbl_8022c078:
  lwz r0, 0(r4);
  rlwinm r0, r0, 0, 0x1e, 0x1c;
  stw r0, 0(r4);
lbl_8022c084:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022c09c
// PAL: 0x8022c09c..0x8022c1bc
MARK_BINARY_BLOB(unk_8022c09c, 0x8022c09c, 0x8022c1bc);
asm UNKNOWN_FUNCTION(unk_8022c09c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  lwz r0, 0(r4);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8022c1a0;
  lwz r0, 0x40(r3);
  cmpwi r0, 1;
  beq lbl_8022c0ec;
  cmpwi r0, 0;
  beq lbl_8022c134;
  cmpwi r0, 2;
  beq lbl_8022c158;
  b lbl_8022c178;
lbl_8022c0ec:
  mr r4, r31;
  addi r3, r1, 0x14;
  addi r5, r29, 0xa4;
  bl VEC3TransformNormal;
  addi r4, r1, 0x14;
  lfs f1, unk_80388dc8;
  psq_l f3, 0(r4), 0, 0;
  addi r3, r1, 8;
  lfs f0, unk_80388d98;
  ps_muls0 f2, f3, f1;
  psq_l f3, 8(r4), 1, 0;
  stfs f0, 0x18(r1);
  psq_st f2, 0(r3), 0, 0;
  ps_muls0 f2, f3, f1;
  psq_st f2, 8(r3), 1, 0;
  stfs f0, 0x1c(r1);
  stfs f0, 0x14(r1);
  b lbl_8022c178;
lbl_8022c134:
  mr r3, r31;
  addi r4, r29, 0x8c;
  addi r5, r1, 8;
  bl PSMTXMultVec;
  lfs f0, unk_80388d98;
  stfs f0, 0x1c(r1);
  stfs f0, 0x18(r1);
  stfs f0, 0x14(r1);
  b lbl_8022c178;
lbl_8022c158:
  mr r3, r31;
  addi r4, r29, 0x8c;
  addi r5, r1, 8;
  bl PSMTXMultVec;
  mr r4, r31;
  addi r3, r1, 0x14;
  addi r5, r29, 0xa4;
  bl VEC3TransformNormal;
lbl_8022c178:
  lfs f1, 8(r1);
  mr r3, r30;
  lfs f2, 0xc(r1);
  lfs f3, 0x10(r1);
  bl unk_800776d0;
  lfs f1, 0x14(r1);
  mr r3, r30;
  lfs f2, 0x18(r1);
  lfs f3, 0x1c(r1);
  bl unk_80077710;
lbl_8022c1a0:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: egglightsomething
// PAL: 0x8022c1bc..0x8022c260
MARK_BINARY_BLOB(egglightsomething, 0x8022c1bc, 0x8022c260);
asm UNKNOWN_FUNCTION(egglightsomething) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lfs f1, 8(r3);
  lfs f0, 0x14(r3);
  lfs f3, 0xc(r3);
  fsubs f4, f1, f0;
  lfs f2, 0x18(r3);
  lfs f1, 0x10(r3);
  lfs f0, 0x1c(r3);
  fsubs f2, f3, f2;
  stfs f4, 0x20(r3);
  fsubs f0, f1, f0;
  stfs f2, 0x24(r3);
  stfs f0, 0x28(r3);
  addi r3, r3, 0x20;
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r31);
  fcmpo cr0, f2, f0;
  ble lbl_8022c240;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r31), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r31), 1, 0;
  psq_st f1, 32(r31), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r31), 1, 0;
  b lbl_8022c24c;
lbl_8022c240:
  stfs f0, 0x28(r31);
  stfs f0, 0x24(r31);
  stfs f0, 0x20(r31);
lbl_8022c24c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8022c260
// PAL: 0x8022c260..0x8022c2b4
MARK_BINARY_BLOB(unk_8022c260, 0x8022c260, 0x8022c2b4);
asm UNKNOWN_FUNCTION(unk_8022c260) {
  // clang-format off
  nofralloc;
  lfs f2, 0x20(r3);
  lfs f6, 0x38(r3);
  lfs f1, 0x24(r3);
  fmuls f5, f2, f6;
  lfs f4, 0x14(r3);
  lfs f0, 0x28(r3);
  fmuls f3, f1, f6;
  lfs f2, 0x18(r3);
  fmuls f1, f0, f6;
  lfs f0, 0x1c(r3);
  fadds f4, f4, f5;
  fadds f2, f2, f3;
  fadds f0, f0, f1;
  stfs f4, 8(r3);
  stfs f2, 0xc(r3);
  stfs f0, 0x10(r3);
  blr;
  lis r3, 0x8025;
  addi r3, r3, 0x7844;
  addi r3, r3, 6;
  blr;
  // clang-format on
}

// Symbol: unk_8022c2b4
// PAL: 0x8022c2b4..0x8022c958
MARK_BINARY_BLOB(unk_8022c2b4, 0x8022c2b4, 0x8022c958);
asm UNKNOWN_FUNCTION(unk_8022c2b4) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  lbz r0, 8(r4);
  stw r31, 0x9c(r1);
  mr r31, r4;
  cmpwi r0, 0;
  stw r30, 0x98(r1);
  mr r30, r3;
  beq lbl_8022c2f0;
  cmpwi r0, 1;
  beq lbl_8022c4b8;
  cmpwi r0, 2;
  beq lbl_8022c680;
  b lbl_8022c840;
lbl_8022c2f0:
  lfs f5, 0x18(r4);
  li r9, 1;
  lfs f4, 0x1c(r4);
  lfs f3, 0x20(r4);
  lfs f2, 8(r3);
  lfs f1, 0xc(r3);
  lfs f0, 0x10(r3);
  fsubs f2, f2, f5;
  fsubs f1, f1, f4;
  lhz r5, 0x16(r4);
  fsubs f0, f0, f3;
  lbz r8, 0x10(r4);
  lbz r7, 0x11(r4);
  lhz r6, 0x14(r4);
  lbz r0, 0x12(r4);
  ori r5, r5, 0x660;
  lfs f6, 0x30(r4);
  stw r9, 0x40(r3);
  stw r8, 0x68(r3);
  stw r7, 0x6c(r3);
  sth r6, 4(r3);
  sth r5, 0x76(r3);
  stw r0, 0x34(r3);
  stfs f6, 0x30(r3);
  stfs f5, 0x50(r1);
  stfs f4, 0x54(r1);
  stfs f3, 0x58(r1);
  stfs f5, 0x14(r3);
  stfs f4, 0x18(r3);
  stfs f3, 0x1c(r3);
  stfs f2, 0x20(r3);
  stfs f1, 0x24(r3);
  stfs f0, 0x28(r3);
  addi r3, r3, 0x20;
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c3b4;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c3c0;
lbl_8022c3b4:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c3c0:
  lfs f5, 0x24(r31);
  addi r3, r30, 0x20;
  lfs f4, 0x28(r31);
  lfs f3, 0x2c(r31);
  lfs f2, 0x14(r30);
  lfs f1, 0x18(r30);
  lfs f0, 0x1c(r30);
  fsubs f2, f5, f2;
  fsubs f1, f4, f1;
  stfs f5, 0x44(r1);
  fsubs f0, f3, f0;
  stfs f4, 0x48(r1);
  stfs f3, 0x4c(r1);
  stfs f5, 8(r30);
  stfs f4, 0xc(r30);
  stfs f3, 0x10(r30);
  stfs f2, 0x20(r30);
  stfs f1, 0x24(r30);
  stfs f0, 0x28(r30);
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c448;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c454;
lbl_8022c448:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c454:
  lbz r10, 0x34(r31);
  li r0, 0;
  lbz r9, 0x35(r31);
  lbz r8, 0x36(r31);
  lbz r7, 0x37(r31);
  lbz r6, 0x38(r31);
  lbz r5, 0x39(r31);
  lbz r4, 0x3a(r31);
  lbz r3, 0x3b(r31);
  lfs f0, 0x3c(r31);
  lfs f1, 0x40(r31);
  lfs f2, 0x44(r31);
  stb r10, 0x2c(r30);
  stb r9, 0x2d(r30);
  stb r8, 0x2e(r30);
  stb r7, 0x2f(r30);
  stb r6, 0x3c(r30);
  stb r5, 0x3d(r30);
  stb r4, 0x3e(r30);
  stb r3, 0x3f(r30);
  stfs f0, 0x44(r30);
  stfs f1, 0x48(r30);
  stfs f2, 0x4c(r30);
  sth r0, 6(r30);
  b lbl_8022c840;
lbl_8022c4b8:
  lfs f5, 0x18(r4);
  lfs f4, 0x1c(r4);
  lfs f3, 0x20(r4);
  lfs f2, 8(r3);
  lfs f1, 0xc(r3);
  lfs f0, 0x10(r3);
  fsubs f2, f2, f5;
  lhz r0, 0x16(r4);
  fsubs f1, f1, f4;
  fsubs f0, f0, f3;
  lbz r9, 0x13(r4);
  rlwinm r5, r0, 0, 0x1f, 0x1d;
  lbz r8, 0x10(r4);
  lbz r7, 0x11(r4);
  lhz r6, 0x14(r4);
  lbz r0, 0x12(r4);
  lfs f6, 0x30(r4);
  stw r9, 0x40(r3);
  stw r8, 0x68(r3);
  stw r7, 0x6c(r3);
  sth r6, 4(r3);
  sth r5, 0x76(r3);
  stw r0, 0x34(r3);
  stfs f6, 0x30(r3);
  stfs f5, 0x38(r1);
  stfs f4, 0x3c(r1);
  stfs f3, 0x40(r1);
  stfs f5, 0x14(r3);
  stfs f4, 0x18(r3);
  stfs f3, 0x1c(r3);
  stfs f2, 0x20(r3);
  stfs f1, 0x24(r3);
  stfs f0, 0x28(r3);
  addi r3, r3, 0x20;
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c57c;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c588;
lbl_8022c57c:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c588:
  lfs f5, 0x24(r31);
  addi r3, r30, 0x20;
  lfs f4, 0x28(r31);
  lfs f3, 0x2c(r31);
  lfs f2, 0x14(r30);
  lfs f1, 0x18(r30);
  lfs f0, 0x1c(r30);
  fsubs f2, f5, f2;
  fsubs f1, f4, f1;
  stfs f5, 0x2c(r1);
  fsubs f0, f3, f0;
  stfs f4, 0x30(r1);
  stfs f3, 0x34(r1);
  stfs f5, 8(r30);
  stfs f4, 0xc(r30);
  stfs f3, 0x10(r30);
  stfs f2, 0x20(r30);
  stfs f1, 0x24(r30);
  stfs f0, 0x28(r30);
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c610;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c61c;
lbl_8022c610:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c61c:
  lbz r10, 0x34(r31);
  li r0, 0;
  lbz r9, 0x35(r31);
  lbz r8, 0x36(r31);
  lbz r7, 0x37(r31);
  lbz r6, 0x38(r31);
  lbz r5, 0x39(r31);
  lbz r4, 0x3a(r31);
  lbz r3, 0x3b(r31);
  lfs f0, 0x3c(r31);
  lfs f1, 0x40(r31);
  lfs f2, 0x44(r31);
  stb r10, 0x2c(r30);
  stb r9, 0x2d(r30);
  stb r8, 0x2e(r30);
  stb r7, 0x2f(r30);
  stb r6, 0x3c(r30);
  stb r5, 0x3d(r30);
  stb r4, 0x3e(r30);
  stb r3, 0x3f(r30);
  stfs f0, 0x44(r30);
  stfs f1, 0x48(r30);
  stfs f2, 0x4c(r30);
  sth r0, 6(r30);
  b lbl_8022c840;
lbl_8022c680:
  lfs f5, 0x18(r4);
  lfs f4, 0x1c(r4);
  lfs f3, 0x20(r4);
  lfs f2, 8(r3);
  lfs f1, 0xc(r3);
  lfs f0, 0x10(r3);
  fsubs f2, f2, f5;
  fsubs f1, f1, f4;
  lbz r9, 0x13(r4);
  fsubs f0, f0, f3;
  lbz r8, 0x10(r4);
  lbz r7, 0x11(r4);
  lhz r6, 0x14(r4);
  lhz r5, 0x16(r4);
  lbz r0, 0x12(r4);
  lfs f6, 0x30(r4);
  stw r9, 0x40(r3);
  stw r8, 0x68(r3);
  stw r7, 0x6c(r3);
  sth r6, 4(r3);
  sth r5, 0x76(r3);
  stw r0, 0x34(r3);
  stfs f6, 0x30(r3);
  stfs f5, 0x20(r1);
  stfs f4, 0x24(r1);
  stfs f3, 0x28(r1);
  stfs f5, 0x14(r3);
  stfs f4, 0x18(r3);
  stfs f3, 0x1c(r3);
  stfs f2, 0x20(r3);
  stfs f1, 0x24(r3);
  stfs f0, 0x28(r3);
  addi r3, r3, 0x20;
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c740;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c74c;
lbl_8022c740:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c74c:
  lfs f5, 0x24(r31);
  addi r3, r30, 0x20;
  lfs f4, 0x28(r31);
  lfs f3, 0x2c(r31);
  lfs f2, 0x14(r30);
  lfs f1, 0x18(r30);
  lfs f0, 0x1c(r30);
  fsubs f2, f5, f2;
  fsubs f1, f4, f1;
  stfs f5, 0x14(r1);
  fsubs f0, f3, f0;
  stfs f4, 0x18(r1);
  stfs f3, 0x1c(r1);
  stfs f5, 8(r30);
  stfs f4, 0xc(r30);
  stfs f3, 0x10(r30);
  stfs f2, 0x20(r30);
  stfs f1, 0x24(r30);
  stfs f0, 0x28(r30);
  bl PSVECMag;
  frsp f2, f1;
  lfs f0, unk_80388d98;
  stfs f1, 0x38(r30);
  fcmpo cr0, f2, f0;
  ble lbl_8022c7d4;
  lfs f0, unk_80388da8;
  psq_l f3, 32(r30), 0, 0;
  fdivs f0, f0, f2;
  ps_muls0 f1, f3, f0;
  psq_l f3, 40(r30), 1, 0;
  psq_st f1, 32(r30), 0, 0;
  ps_muls0 f1, f3, f0;
  psq_st f1, 40(r30), 1, 0;
  b lbl_8022c7e0;
lbl_8022c7d4:
  stfs f0, 0x28(r30);
  stfs f0, 0x24(r30);
  stfs f0, 0x20(r30);
lbl_8022c7e0:
  lbz r10, 0x34(r31);
  lbz r9, 0x35(r31);
  lbz r8, 0x36(r31);
  lbz r7, 0x37(r31);
  lbz r6, 0x38(r31);
  lbz r5, 0x39(r31);
  lbz r4, 0x3a(r31);
  lbz r3, 0x3b(r31);
  lfs f0, 0x3c(r31);
  lfs f1, 0x40(r31);
  lfs f2, 0x44(r31);
  lhz r0, 0x4c(r31);
  stb r10, 0x2c(r30);
  stb r9, 0x2d(r30);
  stb r8, 0x2e(r30);
  stb r7, 0x2f(r30);
  stb r6, 0x3c(r30);
  stb r5, 0x3d(r30);
  stb r4, 0x3e(r30);
  stb r3, 0x3f(r30);
  stfs f0, 0x44(r30);
  stfs f1, 0x48(r30);
  stfs f2, 0x4c(r30);
  sth r0, 6(r30);
lbl_8022c840:
  lbz r0, 0x2c(r30);
  lis r4, 0x4330;
  stw r0, 0x64(r1);
  lbz r3, 0x2d(r30);
  stw r4, 0x60(r1);
  lfd f5, unk_80388dc0;
  lfd f0, 0x60(r1);
  stw r3, 0x6c(r1);
  fsubs f1, f0, f5;
  lfs f4, 0x30(r30);
  stw r4, 0x68(r1);
  lbz r0, 0x2e(r30);
  fmuls f3, f1, f4;
  lfd f1, 0x68(r1);
  stw r0, 0x74(r1);
  fsubs f1, f1, f5;
  lfs f0, unk_80388db8;
  stw r4, 0x70(r1);
  lfs f8, 0x20(r30);
  fcmpo cr0, f3, f0;
  fmuls f2, f1, f4;
  lfd f1, 0x70(r1);
  lfs f7, 0x24(r30);
  fsubs f1, f1, f5;
  lfs f6, 0x28(r30);
  stfs f8, 0x7c(r30);
  fmuls f1, f1, f4;
  stfs f7, 0x80(r30);
  stfs f6, 0x84(r30);
  stfs f3, 8(r1);
  stfs f2, 0xc(r1);
  stfs f1, 0x10(r1);
  cror 2, 0, 2;
  bne lbl_8022c8cc;
  b lbl_8022c8d0;
lbl_8022c8cc:
  fmr f3, f0;
lbl_8022c8d0:
  fctiwz f2, f3;
  lfs f1, 0xc(r1);
  lfs f0, unk_80388db8;
  stfd f2, 0x78(r1);
  fcmpo cr0, f1, f0;
  lwz r0, 0x7c(r1);
  stb r0, 0x88(r30);
  cror 2, 0, 2;
  bne lbl_8022c8f8;
  b lbl_8022c8fc;
lbl_8022c8f8:
  fmr f1, f0;
lbl_8022c8fc:
  fctiwz f2, f1;
  lfs f1, 0x10(r1);
  lfs f0, unk_80388db8;
  stfd f2, 0x80(r1);
  fcmpo cr0, f1, f0;
  lwz r0, 0x84(r1);
  stb r0, 0x89(r30);
  cror 2, 0, 2;
  bne lbl_8022c924;
  b lbl_8022c928;
lbl_8022c924:
  fmr f1, f0;
lbl_8022c928:
  fctiwz f0, f1;
  lbz r0, 0x2f(r30);
  stb r0, 0x8b(r30);
  stfd f0, 0x88(r1);
  lwz r0, 0x8c(r1);
  stb r0, 0x8a(r30);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_8022c958
// PAL: 0x8022c958..0x8022ca4c
MARK_BINARY_BLOB(unk_8022c958, 0x8022c958, 0x8022ca4c);
asm UNKNOWN_FUNCTION(unk_8022c958) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lwz r26, 0x40(r3);
  lwz r27, 0x68(r3);
  lwz r28, 0x6c(r3);
  lhz r29, 4(r3);
  lhz r30, 0x76(r3);
  lwz r31, 0x34(r3);
  lfs f6, 0x30(r3);
  lfs f5, 0x14(r3);
  lfs f4, 0x18(r3);
  lfs f3, 0x1c(r3);
  lfs f2, 8(r3);
  lfs f1, 0xc(r3);
  lfs f0, 0x10(r3);
  lbz r12, 0x2c(r3);
  lbz r11, 0x2d(r3);
  lbz r10, 0x2e(r3);
  lbz r9, 0x2f(r3);
  lbz r8, 0x3c(r3);
  lbz r7, 0x3d(r3);
  lbz r6, 0x3e(r3);
  lbz r5, 0x3f(r3);
  lfs f7, 0x44(r3);
  lfs f8, 0x48(r3);
  lfs f9, 0x4c(r3);
  lhz r0, 6(r3);
  stb r11, 0x35(r4);
  addi r11, r1, 0x20;
  stb r26, 0x13(r4);
  stb r27, 0x10(r4);
  stb r28, 0x11(r4);
  sth r29, 0x14(r4);
  sth r30, 0x16(r4);
  stb r31, 0x12(r4);
  stfs f6, 0x30(r4);
  stfs f5, 0x18(r4);
  stfs f4, 0x1c(r4);
  stfs f3, 0x20(r4);
  stfs f2, 0x24(r4);
  stfs f1, 0x28(r4);
  stfs f0, 0x2c(r4);
  stb r12, 0x34(r4);
  stb r10, 0x36(r4);
  stb r9, 0x37(r4);
  stb r8, 0x38(r4);
  stb r7, 0x39(r4);
  stb r6, 0x3a(r4);
  stb r5, 0x3b(r4);
  stfs f7, 0x3c(r4);
  stfs f8, 0x40(r4);
  stfs f9, 0x44(r4);
  sth r0, 0x4c(r4);
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022ca4c
// PAL: 0x8022ca4c..0x8022d0f8
MARK_BINARY_BLOB(unk_8022ca4c, 0x8022ca4c, 0x8022d0f8);
asm UNKNOWN_FUNCTION(unk_8022ca4c) {
  // clang-format off
  nofralloc;
  stwu r1, -0xd0(r1);
  mflr r0;
  stw r0, 0xd4(r1);
  addi r11, r1, 0xd0;
  bl _savegpr_20;
  lbz r26, 8(r4);
  lis r20, 0x4330;
  lbz r21, 0(r4);
  lbz r22, 1(r4);
  cmplwi r26, 2;
  lbz r23, 2(r4);
  lbz r24, 3(r4);
  lwz r25, 4(r4);
  lbz r27, 9(r4);
  lbz r28, 0xa(r4);
  lbz r29, 0xb(r4);
  lbz r30, 0xc(r4);
  lbz r31, 0xd(r4);
  lbz r12, 0xe(r4);
  lbz r11, 0xf(r4);
  lbz r10, 0x13(r4);
  lbz r9, 0x10(r4);
  lbz r8, 0x11(r4);
  lhz r7, 0x14(r4);
  lhz r6, 0x16(r4);
  lbz r0, 0x12(r4);
  stw r20, 0x70(r1);
  stw r20, 0x78(r1);
  stb r21, 0x20(r1);
  stb r22, 0x21(r1);
  stb r23, 0x22(r1);
  stb r24, 0x23(r1);
  stw r25, 0x24(r1);
  stb r26, 0x28(r1);
  stb r27, 0x29(r1);
  stb r28, 0x2a(r1);
  stb r29, 0x2b(r1);
  stb r30, 0x2c(r1);
  stb r31, 0x2d(r1);
  stb r12, 0x2e(r1);
  stb r11, 0x2f(r1);
  stb r10, 0x33(r1);
  stb r9, 0x30(r1);
  stb r8, 0x31(r1);
  sth r7, 0x34(r1);
  sth r6, 0x36(r1);
  stb r0, 0x32(r1);
  bge lbl_8022cb18;
  li r0, 0;
  sth r0, 0x6c(r1);
  b lbl_8022cb20;
lbl_8022cb18:
  lhz r0, 0x4c(r4);
  sth r0, 0x6c(r1);
lbl_8022cb20:
  lfs f0, unk_80388d98;
  lfs f4, 0x30(r5);
  fcmpo cr0, f1, f0;
  lfs f3, 0x30(r4);
  bge lbl_8022cb38;
  b lbl_8022cb5c;
lbl_8022cb38:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cb4c;
  fmr f3, f4;
  b lbl_8022cb5c;
lbl_8022cb4c:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022cb5c:
  frsp f2, f3;
  lfs f0, unk_80388d98;
  stfs f3, 0x50(r1);
  fcmpo cr0, f2, f0;
  cror 2, 1, 2;
  bne lbl_8022cb78;
  b lbl_8022cb7c;
lbl_8022cb78:
  fmr f2, f0;
lbl_8022cb7c:
  lfs f0, unk_80388d98;
  stfs f2, 0x50(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x18(r5);
  lfs f3, 0x18(r4);
  bge lbl_8022cb98;
  b lbl_8022cbbc;
lbl_8022cb98:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cbac;
  fmr f3, f4;
  b lbl_8022cbbc;
lbl_8022cbac:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022cbbc:
  lfs f0, unk_80388d98;
  stfs f3, 0x38(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x1c(r5);
  lfs f3, 0x1c(r4);
  bge lbl_8022cbd8;
  b lbl_8022cbfc;
lbl_8022cbd8:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cbec;
  fmr f3, f4;
  b lbl_8022cbfc;
lbl_8022cbec:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022cbfc:
  lfs f0, unk_80388d98;
  stfs f3, 0x3c(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x20(r5);
  lfs f3, 0x20(r4);
  bge lbl_8022cc18;
  b lbl_8022cc3c;
lbl_8022cc18:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cc2c;
  fmr f3, f4;
  b lbl_8022cc3c;
lbl_8022cc2c:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022cc3c:
  lfs f0, unk_80388d98;
  stfs f3, 0x40(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x24(r5);
  lfs f3, 0x24(r4);
  bge lbl_8022cc58;
  b lbl_8022cc7c;
lbl_8022cc58:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cc6c;
  fmr f3, f4;
  b lbl_8022cc7c;
lbl_8022cc6c:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022cc7c:
  lfs f0, unk_80388d98;
  stfs f3, 0x44(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x28(r5);
  lfs f3, 0x28(r4);
  bge lbl_8022cc98;
  b lbl_8022ccbc;
lbl_8022cc98:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022ccac;
  fmr f3, f4;
  b lbl_8022ccbc;
lbl_8022ccac:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022ccbc:
  lfs f0, unk_80388d98;
  stfs f3, 0x48(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x2c(r5);
  lfs f3, 0x2c(r4);
  bge lbl_8022ccd8;
  b lbl_8022ccfc;
lbl_8022ccd8:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022ccec;
  fmr f3, f4;
  b lbl_8022ccfc;
lbl_8022ccec:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022ccfc:
  lfs f0, unk_80388d98;
  stfs f3, 0x4c(r1);
  fcmpo cr0, f1, f0;
  bge lbl_8022cd30;
  lbz r8, 0x34(r4);
  lbz r7, 0x35(r4);
  lbz r6, 0x36(r4);
  lbz r0, 0x37(r4);
  stb r8, 0x14(r1);
  stb r7, 0x15(r1);
  stb r6, 0x16(r1);
  stb r0, 0x17(r1);
  b lbl_8022ce60;
lbl_8022cd30:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cd60;
  lbz r8, 0x34(r5);
  lbz r7, 0x35(r5);
  lbz r6, 0x36(r5);
  lbz r0, 0x37(r5);
  stb r8, 0x14(r1);
  stb r7, 0x15(r1);
  stb r6, 0x16(r1);
  stb r0, 0x17(r1);
  b lbl_8022ce60;
lbl_8022cd60:
  lbz r6, 0x34(r4);
  fsubs f10, f0, f1;
  stw r6, 0x74(r1);
  lbz r0, 0x34(r5);
  stw r0, 0x7c(r1);
  lfd f0, 0x70(r1);
  lbz r6, 0x35(r4);
  stw r6, 0x74(r1);
  lfd f5, 0x78(r1);
  lbz r0, 0x35(r5);
  stw r0, 0x7c(r1);
  lfd f9, unk_80388dc0;
  lfd f4, 0x70(r1);
  lbz r6, 0x36(r4);
  fsubs f8, f0, f9;
  stw r6, 0x74(r1);
  fsubs f7, f5, f9;
  lfd f3, 0x78(r1);
  fsubs f6, f4, f9;
  lbz r0, 0x36(r5);
  stw r0, 0x7c(r1);
  fsubs f5, f3, f9;
  lfd f2, 0x70(r1);
  fmuls f8, f8, f10;
  lfd f0, 0x78(r1);
  fmuls f7, f7, f1;
  lbz r6, 0x37(r4);
  lbz r0, 0x37(r5);
  fsubs f4, f2, f9;
  stw r6, 0x74(r1);
  fsubs f3, f0, f9;
  fmuls f6, f6, f10;
  stw r0, 0x7c(r1);
  fmuls f5, f5, f1;
  lfd f2, 0x70(r1);
  fmuls f4, f4, f10;
  lfd f0, 0x78(r1);
  fsubs f2, f2, f9;
  fsubs f0, f0, f9;
  fmuls f3, f3, f1;
  fmuls f2, f2, f10;
  fmuls f0, f0, f1;
  fadds f3, f4, f3;
  fadds f5, f6, f5;
  fadds f7, f8, f7;
  fadds f0, f2, f0;
  fctiwz f4, f5;
  fctiwz f6, f7;
  fctiwz f3, f3;
  stfd f4, 0x88(r1);
  fctiwz f0, f0;
  stfd f6, 0x80(r1);
  lwz r7, 0x8c(r1);
  stfd f3, 0x90(r1);
  lwz r0, 0x84(r1);
  lwz r6, 0x94(r1);
  stfd f0, 0x98(r1);
  stb r0, 0x10(r1);
  lwz r0, 0x9c(r1);
  stb r7, 0x11(r1);
  stb r6, 0x12(r1);
  stb r0, 0x13(r1);
  lwz r0, 0x10(r1);
  stw r0, 0x14(r1);
lbl_8022ce60:
  lwz r0, 0x14(r1);
  stw r0, 0x1c(r1);
  lfs f0, unk_80388d98;
  lbz r8, 0x1c(r1);
  lbz r7, 0x1d(r1);
  fcmpo cr0, f1, f0;
  lbz r6, 0x1e(r1);
  lbz r0, 0x1f(r1);
  stb r8, 0x54(r1);
  stb r7, 0x55(r1);
  stb r6, 0x56(r1);
  stb r0, 0x57(r1);
  bge lbl_8022ceb8;
  lbz r8, 0x38(r4);
  lbz r7, 0x39(r4);
  lbz r6, 0x3a(r4);
  lbz r0, 0x3b(r4);
  stb r8, 0xc(r1);
  stb r7, 0xd(r1);
  stb r6, 0xe(r1);
  stb r0, 0xf(r1);
  b lbl_8022cfe8;
lbl_8022ceb8:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022cee8;
  lbz r8, 0x38(r5);
  lbz r7, 0x39(r5);
  lbz r6, 0x3a(r5);
  lbz r0, 0x3b(r5);
  stb r8, 0xc(r1);
  stb r7, 0xd(r1);
  stb r6, 0xe(r1);
  stb r0, 0xf(r1);
  b lbl_8022cfe8;
lbl_8022cee8:
  lbz r6, 0x38(r4);
  fsubs f10, f0, f1;
  stw r6, 0x74(r1);
  lbz r0, 0x38(r5);
  stw r0, 0x7c(r1);
  lfd f0, 0x70(r1);
  lbz r6, 0x39(r4);
  stw r6, 0x74(r1);
  lfd f5, 0x78(r1);
  lbz r0, 0x39(r5);
  stw r0, 0x7c(r1);
  lfd f9, unk_80388dc0;
  lfd f4, 0x70(r1);
  lbz r6, 0x3a(r4);
  fsubs f8, f0, f9;
  stw r6, 0x74(r1);
  fsubs f7, f5, f9;
  lfd f3, 0x78(r1);
  fsubs f6, f4, f9;
  lbz r0, 0x3a(r5);
  stw r0, 0x7c(r1);
  fsubs f5, f3, f9;
  lfd f2, 0x70(r1);
  fmuls f8, f8, f10;
  lfd f0, 0x78(r1);
  fmuls f7, f7, f1;
  lbz r6, 0x3b(r4);
  lbz r0, 0x3b(r5);
  fsubs f4, f2, f9;
  stw r6, 0x74(r1);
  fsubs f3, f0, f9;
  fmuls f6, f6, f10;
  stw r0, 0x7c(r1);
  fmuls f5, f5, f1;
  lfd f2, 0x70(r1);
  fmuls f4, f4, f10;
  lfd f0, 0x78(r1);
  fsubs f2, f2, f9;
  fsubs f0, f0, f9;
  fmuls f3, f3, f1;
  fmuls f2, f2, f10;
  fmuls f0, f0, f1;
  fadds f3, f4, f3;
  fadds f5, f6, f5;
  fadds f7, f8, f7;
  fadds f0, f2, f0;
  fctiwz f4, f5;
  fctiwz f6, f7;
  fctiwz f3, f3;
  stfd f4, 0x90(r1);
  fctiwz f0, f0;
  stfd f6, 0x98(r1);
  lwz r7, 0x94(r1);
  stfd f3, 0x88(r1);
  lwz r0, 0x9c(r1);
  lwz r6, 0x8c(r1);
  stfd f0, 0x80(r1);
  stb r0, 8(r1);
  lwz r0, 0x84(r1);
  stb r7, 9(r1);
  stb r6, 0xa(r1);
  stb r0, 0xb(r1);
  lwz r0, 8(r1);
  stw r0, 0xc(r1);
lbl_8022cfe8:
  lwz r0, 0xc(r1);
  stw r0, 0x18(r1);
  lfs f0, unk_80388d98;
  lbz r8, 0x18(r1);
  lbz r7, 0x19(r1);
  fcmpo cr0, f1, f0;
  lbz r6, 0x1a(r1);
  lbz r0, 0x1b(r1);
  stb r8, 0x58(r1);
  lfs f4, 0x3c(r5);
  stb r7, 0x59(r1);
  lfs f3, 0x3c(r4);
  stb r6, 0x5a(r1);
  stb r0, 0x5b(r1);
  bge lbl_8022d028;
  b lbl_8022d04c;
lbl_8022d028:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022d03c;
  fmr f3, f4;
  b lbl_8022d04c;
lbl_8022d03c:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022d04c:
  lfs f0, unk_80388d98;
  stfs f3, 0x5c(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x40(r5);
  lfs f3, 0x40(r4);
  bge lbl_8022d068;
  b lbl_8022d08c;
lbl_8022d068:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022d07c;
  fmr f3, f4;
  b lbl_8022d08c;
lbl_8022d07c:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f2, f3, f2;
  fadds f3, f2, f0;
lbl_8022d08c:
  lfs f0, unk_80388d98;
  stfs f3, 0x60(r1);
  fcmpo cr0, f1, f0;
  lfs f4, 0x44(r5);
  lfs f3, 0x44(r4);
  bge lbl_8022d0a8;
  b lbl_8022d0cc;
lbl_8022d0a8:
  lfs f0, unk_80388da8;
  fcmpo cr0, f1, f0;
  ble lbl_8022d0bc;
  fmr f3, f4;
  b lbl_8022d0cc;
lbl_8022d0bc:
  fsubs f2, f0, f1;
  fmuls f0, f4, f1;
  fmuls f1, f3, f2;
  fadds f3, f1, f0;
lbl_8022d0cc:
  stfs f3, 0x64(r1);
  addi r4, r1, 0x20;
  bl unk_8022b414;
  addi r11, r1, 0xd0;
  bl _restgpr_20;
  lwz r0, 0xd4(r1);
  mtlr r0;
  addi r1, r1, 0xd0;
  blr;
  li r3, 2;
  blr;
  // clang-format on
}
