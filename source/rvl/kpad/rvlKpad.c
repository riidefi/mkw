#include "kpad.h"

#include <math.h>
#include <string.h>

#include <rvl/mtx/mtx.h>
#include <rvl/os/os.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/wpad/wpad.h>

typedef struct KPADInsideStatus {
  u32 content[334];
} KPADInsideStatus;

KPADInsideStatus kpad_inside_status[4];
f32 _unk_80346cc0[3][4];

char _unk_8028e998[] =
    "<< RVL_SDK - KPAD \trelease build: Aug  8 2007 02:05:53 (0x4199_60831) >>";
char* _unk_80385998 = _unk_8028e998;
char _unk_8028e9e4[] = {0x00, 0x01, 0x03, 0x02, 0x00, 0x04,
                        0x01, 0x05, 0x00, 0x07, 0x01, 0x08};

f32 _unk_8038599c = 1.0f;
f32 _unk_803859a0 = 69.420f;
MKW_PATCH_WORD(_unk_803859a0, 0);
f32 _unk_803859a4 = -1.0f;
f32 _unk_803859a8 = 1.0f;
f32 _unk_803859ac = 69.420f;
MKW_PATCH_WORD(_unk_803859ac, 0);
u32 _unk_803859b0 = 0x3E4CCCCD;
u32 _unk_803859b4 = 0x3D4CCCCD;
u32 _unk_803859b8 = 0x3D8F5C29;
u32 _unk_803859bc = 0x3D75C28F;
u16 _unk_803859c0 = 0x0064;
u32 _unk_803859c4 = 0x3D4CCCCD;
u32 _unk_803859c8 = 0x40400000;
u32 _unk_803859cc = 0x3D23D70A;
u32 _unk_803859d0 = 0x3F666666;
u32 _unk_803859d4 = 0x3F666666;
u32 _unk_803859d8 = 0x3F666666;
u32 _unk_803859dc = 0x3F333333;
u32 _unk_803859e0 = 0x3DCCCCCD;
u32 _unk_803859e4 = 0x0F;
u32 _unk_803859e8 = 0x47;
u32 _unk_803859ec = 0x0000003C;
u32 _unk_803859f0 = 0x00000134;
u32 _unk_803859f4 = 0x0000001E;
u32 _unk_803859f8 = 0x000000B4;
float _unk_803859fc = 3.4f;
float _unk_80385a00 = 2.1f;
float _unk_80385a04 = 24.0f;

const f32 _unk_80388800 = 0.0;
const f32 _unk_80388804 = 0.5;
const f32 _unk_80388808 = 0.383864;
const f32 _unk_8038880c = -1.0;
const f32 _unk_80388810 = 1.0;
const f32 _unk_80388814 = -0.75;
const f32 _unk_80388818 = 0.75;
const f32 _unk_8038881c = 2.0;
const f64 _unk_80388820 = 4.503601774854144E15;
const f32 _unk_80388828 = 0.001953125;
const f32 _unk_8038882c = 0.99902344;
const f32 _unk_80388830 = 0.74902344;
const u16 _unk_80388834 = 0x0001;
const u16 _unk_80388836 = 0x0001;
const u32 _unk_80388838 = 0x00010000;
const u16 _unk_8038883c = 0x0001;
const u16 _unk_8038883e = 0x0001;
const u32 _unk_80388840 = 0x00010000;
const f32 _unk_80388844 = 0.01;
const f32 _unk_80388848 = 0.005;
const f32 _unk_8038884c = 0.017453292;
const f64 _unk_80388850 = 4.503599627370496E15;
const f32 _unk_80388858 = 0.2f;
const f32 _unk_8038885c = -0.2f;

f32 _unk_80386834;
f32 _unk_80386830;
u32 _unk_8038682c;
u32 _unk_80386828;
u32 _unk_80386824;
u32 _unk_80386820;
u32 _unk_8038681c;
u32 _unk_80386818;

// Symbol: KPADSetFSStickClamp
// PAL: 0x801950a0..0x801950b4
MARK_BINARY_BLOB(KPADSetFSStickClamp, 0x801950a0, 0x801950b4);
asm UNKNOWN_FUNCTION(KPADSetFSStickClamp) {
  // clang-format off
  nofralloc;
  extsb r3, r3;
  extsb r0, r4;
  stw r3, _unk_803859e4;
  stw r0, _unk_803859e8;
  blr;
  // clang-format on
}

// Symbol: KPADSetPosParam
// PAL: 0x801950b4..0x801950d0
MARK_BINARY_BLOB(KPADSetPosParam, 0x801950b4, 0x801950d0);
asm UNKNOWN_FUNCTION(KPADSetPosParam) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stfs f1, 0x84(r3);
  stfs f2, 0x88(r3);
  blr;
  // clang-format on
}

// Symbol: KPADSetHoriParam
MARK_BINARY_BLOB(KPADSetHoriParam, 0x801950d0, 0x801950ec);
asm UNKNOWN_FUNCTION(KPADSetHoriParam) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stfs f1, 0x8c(r3);
  stfs f2, 0x90(r3);
  blr;
  // clang-format on
}

// Symbol: KPADSetDistParam
MARK_BINARY_BLOB(KPADSetDistParam, 0x801950ec, 0x80195108);
asm UNKNOWN_FUNCTION(KPADSetDistParam) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stfs f1, 0x94(r3);
  stfs f2, 0x98(r3);
  blr;
  // clang-format on
}

// Symbol: KPADSetAccParam
MARK_BINARY_BLOB(KPADSetAccParam, 0x80195108, 0x80195124);
asm UNKNOWN_FUNCTION(KPADSetAccParam) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stfs f1, 0x9c(r3);
  stfs f2, 0xa0(r3);
  blr;
  // clang-format on
}

// Symbol: reset_kpad
// PAL: 0x80195124..0x801952f8
MARK_BINARY_BLOB(reset_kpad, 0x80195124, 0x801952f8);
asm UNKNOWN_FUNCTION(reset_kpad) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  addi r0, r3, 0xc4;
  lfs f6, _unk_8038880c;
  li r4, -1;
  stw r31, 0x1c(r1);
  lfs f5, _unk_80388810;
  stw r30, 0x18(r1);
  li r30, 0;
  lfs f4, _unk_80388814;
  stw r29, 0x14(r1);
  addi r29, r3, 0xe8;
  lfs f3, _unk_80388818;
  stb r30, 0x51d(r3);
  lfs f1, 0xa4(r3);
  lfs f0, _unk_803859c4;
  lhz r5, 0x4d0(r3);
  fadds f0, f6, f0;
  lfs f2, _unk_80388800;
  lwz r11, 0xb0(r3);
  lwz r10, 0xb4(r3);
  stfs f0, 0x4f4(r3);
  lfs f0, _unk_803859c4;
  fsubs f0, f5, f0;
  stfs f0, 0x4fc(r3);
  lfs f0, _unk_803859c4;
  fadds f0, f4, f0;
  stfs f0, 0x4f8(r3);
  lfs f0, _unk_803859c4;
  fsubs f0, f3, f0;
  stfs f0, 0x500(r3);
  lfs f0, _unk_803859cc;
  fdivs f0, f5, f0;
  stfs f0, 0x504(r3);
  lfs f0, _unk_803859cc;
  fdivs f0, f6, f0;
  stfs f0, 0x508(r3);
  lfs f0, _unk_803859b8;
  fmuls f0, f0, f0;
  stfs f0, 0x50c(r3);
  lfs f0, _unk_80386834;
  stfs f0, 0x514(r3);
  lfs f3, _unk_80386830;
  fdivs f0, f3, f1;
  stfs f3, 0x510(r3);
  stw r30, 8(r3);
  stw r30, 4(r3);
  stw r30, 0(r3);
  sth r30, 0x4cc(r3);
  sth r5, 0x4ce(r3);
  stb r30, 0x5e(r3);
  stb r30, 0x4ca(r3);
  lwz r8, _unk_80386828;
  lwz r7, _unk_8038682c;
  stfs f5, 0x4b8(r3);
  stfs f2, 0x4bc(r3);
  lwz r6, 0x4b8(r3);
  stw r8, 0x28(r3);
  lwz r5, 0x4bc(r3);
  stw r7, 0x2c(r3);
  stw r8, 0x20(r3);
  stw r7, 0x24(r3);
  stfs f2, 0x30(r3);
  stfs f5, 0x4b0(r3);
  stfs f5, 0x34(r3);
  stfs f2, 0x4b4(r3);
  stfs f2, 0x38(r3);
  lwz r31, _unk_80386828;
  lwz r12, _unk_8038682c;
  stfs f2, 0x14(r3);
  stfs f2, 0xc(r3);
  lwz r7, 0x14(r3);
  stfs f6, 0x10(r3);
  lwz r9, 0xc(r3);
  lwz r8, 0x10(r3);
  stw r31, 0x3c(r3);
  stw r12, 0x40(r3);
  stfs f2, 0x44(r3);
  stfs f5, 0x54(r3);
  stfs f2, 0x58(r3);
  stfs f1, 0x48(r3);
  stfs f2, 0x50(r3);
  stfs f2, 0x4c(r3);
  stfs f1, 0x49c(r3);
  stfs f0, 0x4a0(r3);
  stfs f0, 0x490(r3);
  stw r11, 0x494(r3);
  stw r10, 0x498(r3);
  stfs f5, 0x18(r3);
  stfs f2, 0x1c(r3);
  stw r9, 0x4a4(r3);
  stw r8, 0x4a8(r3);
  stw r7, 0x4ac(r3);
  stw r6, 0x4c0(r3);
  stw r5, 0x4c4(r3);
  lhz r5, _unk_803859c0;
  sth r5, 0x4c8(r3);
  sth r30, 0x10c(r3);
lbl_801952a8:
  stb r4, 8(r29);
  addi r29, r29, -12;
  cmplw r29, r0;
  bge lbl_801952a8;
  addi r5, r3, 0x100;
  addi r0, r3, 0xf4;
  li r4, -1;
lbl_801952c4:
  stb r4, 8(r5);
  addi r5, r5, -12;
  cmplw r5, r0;
  bge lbl_801952c4;
  li r4, 0;
  li r0, 1;
  stb r4, 0x10f(r3);
  stb r0, 0x51e(r3);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: calc_button_repeat
// PAL: 0x801952f8..0x8019548c
MARK_BINARY_BLOB(calc_button_repeat, 0x801952f8, 0x8019548c);
asm UNKNOWN_FUNCTION(calc_button_repeat) {
  // clang-format off
  nofralloc;
  lwz r0, 4(r3);
  cmpwi r0, 0;
  bne lbl_80195310;
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80195348;
lbl_80195310:
  lwz r0, 4(r3);
  li r7, 0;
  lhz r6, 0x4d0(r3);
  cmpwi r0, 0;
  sth r7, 0x4cc(r3);
  sth r6, 0x4ce(r3);
  beq lbl_801953bc;
  lhz r0, 0x4d2(r3);
  cmpwi r0, 0;
  beq lbl_801953bc;
  lwz r0, 0(r3);
  oris r0, r0, 0x8000;
  stw r0, 0(r3);
  b lbl_801953bc;
lbl_80195348:
  lwz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_801953bc;
  lhz r0, 0x4cc(r3);
  add r0, r0, r5;
  clrlwi r6, r0, 0x10;
  sth r0, 0x4cc(r3);
  cmplwi r6, 0x9c40;
  blt lbl_80195378;
  addis r6, r6, 0xffff;
  addi r0, r6, 0x63c0;
  sth r0, 0x4cc(r3);
lbl_80195378:
  lhz r8, 0x4cc(r3);
  lhz r7, 0x4ce(r3);
  cmplw r8, r7;
  blt lbl_801953bc;
  lwz r6, 0(r3);
  cmplwi r8, 0x4e20;
  lhz r0, 0x4d2(r3);
  oris r6, r6, 0x8000;
  add r0, r7, r0;
  stw r6, 0(r3);
  sth r0, 0x4ce(r3);
  blt lbl_801953bc;
  clrlwi r6, r0, 0x10;
  addi r7, r8, -20000;
  addi r0, r6, -20000;
  sth r7, 0x4cc(r3);
  sth r0, 0x4ce(r3);
lbl_801953bc:
  cmplwi r4, 2;
  bnelr;
  lwz r0, 0x64(r3);
  cmpwi r0, 0;
  bne lbl_801953dc;
  lwz r0, 0x68(r3);
  cmpwi r0, 0;
  beq lbl_80195414;
lbl_801953dc:
  lwz r0, 0x64(r3);
  li r5, 0;
  lhz r4, 0x4d0(r3);
  cmpwi r0, 0;
  sth r5, 0x4d4(r3);
  sth r4, 0x4d6(r3);
  beqlr;
  lhz r0, 0x4d2(r3);
  cmpwi r0, 0;
  beqlr;
  lwz r0, 0x60(r3);
  oris r0, r0, 0x8000;
  stw r0, 0x60(r3);
  blr;
lbl_80195414:
  lwz r0, 0x60(r3);
  cmpwi r0, 0;
  beqlr;
  lhz r0, 0x4d4(r3);
  add r0, r0, r5;
  clrlwi r4, r0, 0x10;
  sth r0, 0x4d4(r3);
  cmplwi r4, 0x9c40;
  blt lbl_80195444;
  addis r4, r4, 0xffff;
  addi r0, r4, 0x63c0;
  sth r0, 0x4d4(r3);
lbl_80195444:
  lhz r6, 0x4d4(r3);
  lhz r5, 0x4d6(r3);
  cmplw r6, r5;
  bltlr;
  lwz r4, 0x60(r3);
  cmplwi r6, 0x4e20;
  lhz r0, 0x4d2(r3);
  oris r4, r4, 0x8000;
  add r0, r5, r0;
  stw r4, 0x60(r3);
  sth r0, 0x4d6(r3);
  bltlr;
  clrlwi r4, r0, 0x10;
  addi r5, r6, -20000;
  addi r0, r4, -20000;
  sth r5, 0x4d4(r3);
  sth r0, 0x4d6(r3);
  blr;
  // clang-format on
}

// Symbol: calc_acc
// PAL: 0x8019548c..0x80195540
MARK_BINARY_BLOB(calc_acc, 0x8019548c, 0x80195540);
asm UNKNOWN_FUNCTION(calc_acc) {
  // clang-format off
  nofralloc;
  lfs f2, 0(r4);
  lwz r0, 0x534(r3);
  fsubs f3, f1, f2;
  cmpwi r0, 0;
  bne lbl_801954f8;
  lfs f0, _unk_80388800;
  fcmpo cr0, f3, f0;
  bge lbl_801954b4;
  fneg f2, f3;
  b lbl_801954b8;
lbl_801954b4:
  fmr f2, f3;
lbl_801954b8:
  lfs f0, 0x9c(r3);
  fcmpo cr0, f2, f0;
  cror 2, 1, 2;
  bne lbl_801954d0;
  lfs f2, _unk_80388810;
  b lbl_801954dc;
lbl_801954d0:
  fdivs f2, f2, f0;
  fmuls f2, f2, f2;
  fmuls f2, f2, f2;
lbl_801954dc:
  lfs f1, 0xa0(r3);
  lfs f0, 0(r4);
  fmuls f2, f2, f1;
  fmuls f1, f2, f3;
  fadds f0, f0, f1;
  stfs f0, 0(r4);
  blr;
lbl_801954f8:
  lfs f1, 0x9c(r3);
  fneg f0, f1;
  fcmpo cr0, f3, f0;
  bge lbl_80195520;
  fadds f1, f3, f1;
  lfs f0, 0xa0(r3);
  fmuls f0, f0, f1;
  fadds f0, f2, f0;
  stfs f0, 0(r4);
  blr;
lbl_80195520:
  fcmpo cr0, f3, f1;
  blelr;
  fsubs f1, f3, f1;
  lfs f0, 0xa0(r3);
  fmuls f0, f0, f1;
  fadds f0, f2, f0;
  stfs f0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: calc_acc_horizon
// PAL: 0x80195540..0x801956d4
MARK_BINARY_BLOB(calc_acc_horizon, 0x80195540, 0x801956d4);
asm UNKNOWN_FUNCTION(calc_acc_horizon) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stfd f31, 0x20(r1);
  psq_st f31, 40(r1), 0, 0;
  stfd f30, 0x10(r1);
  psq_st f30, 24(r1), 0, 0;
  stw r31, 0xc(r1);
  mr r31, r3;
  lfs f1, 0x4a4(r3);
  lfs f0, 0x4a8(r3);
  fmuls f1, f1, f1;
  fmuls f0, f0, f0;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f8, f1;
  lfs f0, _unk_80388800;
  fcmpu cr0, f0, f8;
  beq lbl_801956b0;
  lfs f2, _unk_8038881c;
  fcmpo cr0, f8, f2;
  cror 2, 1, 2;
  bne lbl_801955a0;
  b lbl_801956b0;
lbl_801955a0:
  lfs f0, 0x4a4(r31);
  lfs f1, 0x4a8(r31);
  fdivs f9, f0, f8;
  lfs f0, _unk_80388810;
  fdivs f10, f1, f8;
  fcmpo cr0, f8, f0;
  ble lbl_801955c0;
  fsubs f8, f2, f8;
lbl_801955c0:
  lfs f0, 0xac(r31);
  lfs f6, 0xa8(r31);
  fmuls f4, f0, f10;
  lfs f7, _unk_803859b4;
  fmuls f5, f6, f9;
  lfs f3, 0x4b8(r31);
  fmuls f2, f0, f9;
  lfs f1, 0x4bc(r31);
  fmuls f0, f6, f10;
  fmuls f6, f8, f7;
  fadds f4, f5, f4;
  fsubs f0, f2, f0;
  fmuls f8, f8, f6;
  fsubs f2, f4, f3;
  fsubs f0, f0, f1;
  fmuls f2, f8, f2;
  fmuls f0, f8, f0;
  fadds f31, f3, f2;
  fadds f30, f1, f0;
  fmuls f1, f31, f31;
  fmuls f0, f30, f30;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f1, f1;
  lfs f0, _unk_80388800;
  fcmpu cr0, f0, f1;
  beq lbl_801956b0;
  fdivs f7, f31, f1;
  lfs f5, 0x4c0(r31);
  lfs f4, 0x4c4(r31);
  lfs f0, 0x50c(r31);
  fdivs f6, f30, f1;
  stfs f7, 0x4b8(r31);
  stfs f6, 0x4bc(r31);
  fsubs f2, f7, f5;
  fsubs f3, f6, f4;
  lfs f1, _unk_803859bc;
  fmuls f1, f1, f2;
  fadds f1, f5, f1;
  fsubs f2, f7, f1;
  stfs f1, 0x4c0(r31);
  lfs f1, _unk_803859bc;
  fmuls f2, f2, f2;
  fmuls f1, f1, f3;
  fadds f1, f4, f1;
  fsubs f3, f6, f1;
  stfs f1, 0x4c4(r31);
  fmuls f1, f3, f3;
  fadds f1, f2, f1;
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  bne lbl_801956a8;
  lhz r3, 0x4c8(r31);
  cmpwi r3, 0;
  beq lbl_801956b0;
  addi r0, r3, -1;
  sth r0, 0x4c8(r31);
  b lbl_801956b0;
lbl_801956a8:
  lhz r0, _unk_803859c0;
  sth r0, 0x4c8(r31);
lbl_801956b0:
  psq_l f31, 40(r1), 0, 0;
  lfd f31, 0x20(r1);
  psq_l f30, 24(r1), 0, 0;
  lfd f30, 0x10(r1);
  lwz r0, 0x34(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: calc_acc_vertical
// PAL: 0x801956d4..0x801957f8
MARK_BINARY_BLOB(calc_acc_vertical, 0x801956d4, 0x801957f8);
asm UNKNOWN_FUNCTION(calc_acc_vertical) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stfd f31, 0x30(r1);
  psq_st f31, 56(r1), 0, 0;
  stfd f30, 0x20(r1);
  psq_st f30, 40(r1), 0, 0;
  stfd f29, 0x10(r1);
  psq_st f29, 24(r1), 0, 0;
  stw r31, 0xc(r1);
  mr r31, r3;
  lfs f1, 0x4a4(r3);
  lfs f0, 0x4a8(r3);
  fmuls f1, f1, f1;
  fmuls f0, f0, f0;
  fadds f30, f1, f0;
  fmr f1, f30;
  bl sqrt;
  lfs f0, 0x4ac(r31);
  frsp f31, f1;
  fneg f29, f0;
  fmuls f0, f29, f29;
  fadds f1, f30, f0;
  bl sqrt;
  frsp f5, f1;
  lfs f0, _unk_80388800;
  fcmpu cr0, f0, f5;
  beq lbl_801957cc;
  lfs f1, _unk_8038881c;
  fcmpo cr0, f5, f1;
  cror 2, 1, 2;
  bne lbl_80195758;
  b lbl_801957cc;
lbl_80195758:
  fdivs f2, f31, f5;
  lfs f0, _unk_80388810;
  fdivs f29, f29, f5;
  fcmpo cr0, f5, f0;
  ble lbl_80195770;
  fsubs f5, f1, f5;
lbl_80195770:
  lfs f0, _unk_803859b4;
  lfs f3, 0x54(r31);
  fmuls f4, f5, f0;
  lfs f1, 0x58(r31);
  fsubs f2, f2, f3;
  fsubs f0, f29, f1;
  fmuls f5, f5, f4;
  fmuls f2, f5, f2;
  fmuls f0, f5, f0;
  fadds f31, f3, f2;
  fadds f30, f1, f0;
  fmuls f1, f31, f31;
  fmuls f0, f30, f30;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f2, f1;
  lfs f0, _unk_80388800;
  fcmpu cr0, f0, f2;
  beq lbl_801957cc;
  fdivs f1, f31, f2;
  fdivs f0, f30, f2;
  stfs f1, 0x54(r31);
  stfs f0, 0x58(r31);
lbl_801957cc:
  psq_l f31, 56(r1), 0, 0;
  lfd f31, 0x30(r1);
  psq_l f30, 40(r1), 0, 0;
  lfd f30, 0x20(r1);
  psq_l f29, 24(r1), 0, 0;
  lfd f29, 0x10(r1);
  lwz r0, 0x44(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: read_kpad_acc
// PAL: 0x801957f8..0x80195c60
MARK_BINARY_BLOB(read_kpad_acc, 0x801957f8, 0x80195c60);
asm UNKNOWN_FUNCTION(read_kpad_acc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  lis r5, 0x4330;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r4;
  stw r30, 0x48(r1);
  mr r30, r3;
  lbz r0, 0x36(r4);
  stw r5, 0x30(r1);
  cmpwi r0, 6;
  stw r5, 0x38(r1);
  beq lbl_80195c48;
  bge lbl_80195848;
  cmpwi r0, 3;
  beq lbl_80195c48;
  bge lbl_80195858;
  cmpwi r0, 1;
  bge lbl_80195858;
  b lbl_80195c48;
lbl_80195848:
  cmpwi r0, 9;
  bge lbl_80195c48;
  b lbl_80195858;
  b lbl_80195c48;
lbl_80195858:
  lha r0, 2(r4);
  lfd f3, _unk_80388820;
  neg r0, r0;
  lfs f1, 0x4dc(r3);
  xoris r0, r0, 0x8000;
  lfs f0, _unk_80388800;
  stw r0, 0x34(r1);
  lfs f4, _unk_803859fc;
  lfd f2, 0x30(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_8019589c;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_801958a8;
  b lbl_801958ac;
lbl_8019589c:
  fcmpo cr0, f1, f4;
  ble lbl_801958a8;
  b lbl_801958ac;
lbl_801958a8:
  fmr f4, f1;
lbl_801958ac:
  stfs f4, 0x4a4(r3);
  lfd f3, _unk_80388820;
  lha r0, 6(r4);
  lfs f1, 0x4e4(r3);
  neg r0, r0;
  lfs f0, _unk_80388800;
  xoris r0, r0, 0x8000;
  lfs f4, _unk_803859fc;
  stw r0, 0x3c(r1);
  lfd f2, 0x38(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_801958f4;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_80195900;
  b lbl_80195904;
lbl_801958f4:
  fcmpo cr0, f1, f4;
  ble lbl_80195900;
  b lbl_80195904;
lbl_80195900:
  fmr f4, f1;
lbl_80195904:
  stfs f4, 0x4a8(r3);
  lfd f3, _unk_80388820;
  lha r0, 4(r4);
  lfs f1, 0x4e0(r3);
  xoris r0, r0, 0x8000;
  lfs f0, _unk_80388800;
  stw r0, 0x34(r1);
  lfs f4, _unk_803859fc;
  lfd f2, 0x30(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_80195948;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_80195954;
  b lbl_80195958;
lbl_80195948:
  fcmpo cr0, f1, f4;
  ble lbl_80195954;
  b lbl_80195958;
lbl_80195954:
  fmr f4, f1;
lbl_80195958:
  lwz r6, 0xc(r3);
  addi r4, r30, 0xc;
  lwz r5, 0x10(r3);
  lwz r0, 0x14(r3);
  stfs f4, 0x4ac(r3);
  mr r3, r30;
  lfs f1, 0x4a4(r30);
  stw r6, 0x14(r1);
  stw r5, 0x18(r1);
  stw r0, 0x1c(r1);
  bl calc_acc;
  lfs f1, 0x4a8(r30);
  mr r3, r30;
  addi r4, r30, 0x10;
  bl calc_acc;
  lfs f1, 0x4ac(r30);
  mr r3, r30;
  addi r4, r30, 0x14;
  bl calc_acc;
  lfs f1, 0xc(r30);
  lfs f0, 0x10(r30);
  fmuls f1, f1, f1;
  lfs f2, 0x14(r30);
  fmuls f0, f0, f0;
  fmuls f2, f2, f2;
  fadds f0, f1, f0;
  fadds f1, f2, f0;
  bl sqrt;
  lfs f2, 0x14(r1);
  frsp f6, f1;
  lfs f0, 0xc(r30);
  lfs f1, 0x18(r1);
  fsubs f5, f2, f0;
  lfs f0, 0x10(r30);
  lfs f2, 0x1c(r1);
  fsubs f4, f1, f0;
  lfs f0, 0x14(r30);
  fmuls f1, f5, f5;
  fsubs f3, f2, f0;
  stfs f6, 0x18(r30);
  fmuls f0, f4, f4;
  stfs f5, 0x14(r1);
  fmuls f2, f3, f3;
  fadds f0, f1, f0;
  stfs f4, 0x18(r1);
  stfs f3, 0x1c(r1);
  fadds f1, f2, f0;
  bl sqrt;
  frsp f0, f1;
  mr r3, r30;
  stfs f0, 0x1c(r30);
  bl calc_acc_horizon;
  mr r3, r30;
  bl calc_acc_vertical;
  lbz r0, 0x29(r31);
  extsb. r0, r0;
  bne lbl_80195c48;
  lbz r0, 0x28(r31);
  cmplwi r0, 1;
  bne lbl_80195c48;
  lbz r0, 0x36(r31);
  cmplwi r0, 4;
  beq lbl_80195a60;
  cmplwi r0, 5;
  beq lbl_80195a60;
  b lbl_80195c48;
lbl_80195a60:
  lha r0, 0x2a(r31);
  lfd f3, _unk_80388820;
  neg r0, r0;
  lfs f1, 0x4e8(r30);
  xoris r0, r0, 0x8000;
  lfs f0, _unk_80388800;
  stw r0, 0x3c(r1);
  lfs f4, _unk_80385a00;
  lfd f2, 0x38(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_80195aa4;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_80195ab0;
  b lbl_80195ab4;
lbl_80195aa4:
  fcmpo cr0, f1, f4;
  ble lbl_80195ab0;
  b lbl_80195ab4;
lbl_80195ab0:
  fmr f4, f1;
lbl_80195ab4:
  stfs f4, 0x20(r1);
  lfd f3, _unk_80388820;
  lha r0, 0x2e(r31);
  lfs f1, 0x4f0(r30);
  neg r0, r0;
  lfs f0, _unk_80388800;
  xoris r0, r0, 0x8000;
  lfs f4, _unk_80385a00;
  stw r0, 0x34(r1);
  lfd f2, 0x30(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_80195afc;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_80195b08;
  b lbl_80195b0c;
lbl_80195afc:
  fcmpo cr0, f1, f4;
  ble lbl_80195b08;
  b lbl_80195b0c;
lbl_80195b08:
  fmr f4, f1;
lbl_80195b0c:
  stfs f4, 0x24(r1);
  lfd f3, _unk_80388820;
  lha r0, 0x2c(r31);
  lfs f1, 0x4ec(r30);
  xoris r0, r0, 0x8000;
  lfs f0, _unk_80388800;
  stw r0, 0x3c(r1);
  lfs f4, _unk_80385a00;
  lfd f2, 0x38(r1);
  fsubs f2, f2, f3;
  fmuls f1, f2, f1;
  fcmpo cr0, f1, f0;
  bge lbl_80195b50;
  fneg f4, f4;
  fcmpo cr0, f1, f4;
  bge lbl_80195b5c;
  b lbl_80195b60;
lbl_80195b50:
  fcmpo cr0, f1, f4;
  ble lbl_80195b5c;
  b lbl_80195b60;
lbl_80195b5c:
  fmr f4, f1;
lbl_80195b60:
  stfs f4, 0x28(r1);
  lbz r0, 0x526(r30);
  cmpwi r0, 0;
  beq lbl_80195b84;
  addi r4, r1, 0x20;
  lis r3, 0x8034;
  mr r5, r4;
  addi r3, r3, 0x6cc0;
  bl PSMTXMultVec;
lbl_80195b84:
  lwz r6, 0x68(r30);
  mr r3, r30;
  lwz r5, 0x6c(r30);
  addi r4, r30, 0x68;
  lwz r0, 0x70(r30);
  stw r6, 8(r1);
  lfs f1, 0x20(r1);
  stw r5, 0xc(r1);
  stw r0, 0x10(r1);
  bl calc_acc;
  lfs f1, 0x24(r1);
  mr r3, r30;
  addi r4, r30, 0x6c;
  bl calc_acc;
  lfs f1, 0x28(r1);
  mr r3, r30;
  addi r4, r30, 0x70;
  bl calc_acc;
  lfs f1, 0x68(r30);
  lfs f0, 0x6c(r30);
  fmuls f1, f1, f1;
  lfs f2, 0x70(r30);
  fmuls f0, f0, f0;
  fmuls f2, f2, f2;
  fadds f0, f1, f0;
  fadds f1, f2, f0;
  bl sqrt;
  lfs f2, 8(r1);
  frsp f6, f1;
  lfs f0, 0x68(r30);
  lfs f1, 0xc(r1);
  fsubs f5, f2, f0;
  lfs f0, 0x6c(r30);
  lfs f2, 0x10(r1);
  fsubs f4, f1, f0;
  lfs f0, 0x70(r30);
  fmuls f1, f5, f5;
  fsubs f3, f2, f0;
  stfs f6, 0x74(r30);
  fmuls f0, f4, f4;
  stfs f5, 8(r1);
  fmuls f2, f3, f3;
  fadds f0, f1, f0;
  stfs f4, 0xc(r1);
  stfs f3, 0x10(r1);
  fadds f1, f2, f0;
  bl sqrt;
  frsp f0, f1;
  stfs f0, 0x78(r30);
lbl_80195c48:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  lwz r30, 0x48(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: select_2obj_first
// PAL: 0x80195c60..0x80195e48
MARK_BINARY_BLOB(select_2obj_first, 0x80195c60, 0x80195e48);
asm UNKNOWN_FUNCTION(select_2obj_first) {
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
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lfs f30, _unk_803859d0;
  mr r25, r3;
  lfs f29, _unk_80388800;
  addi r29, r3, 0xc4;
  lfs f31, _unk_80388810;
  addi r31, r3, 0xe8;
lbl_80195cb4:
  lbz r0, 8(r29);
  extsb. r0, r0;
  bne lbl_80195db4;
  addi r28, r29, 0xc;
  addi r30, r25, 0xe8;
lbl_80195cc8:
  lbz r0, 8(r28);
  extsb. r0, r0;
  bne lbl_80195da8;
  lfs f3, 0(r28);
  lfs f2, 0(r29);
  lfs f1, 4(r28);
  lfs f0, 4(r29);
  fsubs f27, f3, f2;
  fsubs f28, f1, f0;
  fmuls f1, f27, f27;
  fmuls f0, f28, f28;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f0, f1;
  lfs f5, 0xb0(r25);
  lfs f2, 0xb4(r25);
  lfs f1, 0x510(r25);
  fdivs f3, f31, f0;
  lfs f0, 0x514(r25);
  fmuls f27, f27, f3;
  fmuls f28, f28, f3;
  fmuls f6, f1, f3;
  fmuls f4, f5, f27;
  fmuls f3, f2, f28;
  fmuls f2, f2, f27;
  fmuls f1, f5, f28;
  fadds f3, f4, f3;
  fcmpo cr0, f6, f0;
  fsubs f2, f2, f1;
  stfs f3, 8(r1);
  stfs f2, 0xc(r1);
  cror 2, 0, 2;
  beq lbl_80195da8;
  lfs f0, _unk_803859c8;
  fcmpo cr0, f6, f0;
  cror 2, 1, 2;
  beq lbl_80195da8;
  lfs f1, 0x4b8(r25);
  lfs f0, 0x4bc(r25);
  fmuls f1, f1, f3;
  fmuls f0, f0, f2;
  fadds f0, f1, f0;
  fcmpo cr0, f0, f29;
  bge lbl_80195d94;
  fneg f0, f0;
  fcmpo cr0, f0, f30;
  ble lbl_80195da8;
  fmr f30, f0;
  mr r27, r28;
  mr r26, r29;
  b lbl_80195da8;
lbl_80195d94:
  fcmpo cr0, f0, f30;
  ble lbl_80195da8;
  fmr f30, f0;
  mr r27, r29;
  mr r26, r28;
lbl_80195da8:
  addi r28, r28, 0xc;
  cmplw r28, r30;
  ble lbl_80195cc8;
lbl_80195db4:
  addi r29, r29, 0xc;
  cmplw r29, r31;
  blt lbl_80195cb4;
  lfs f0, _unk_803859d0;
  fcmpu cr0, f30, f0;
  bne lbl_80195dd4;
  li r3, 0;
  b lbl_80195e08;
lbl_80195dd4:
  lwz r4, 0(r27);
  li r3, 2;
  lwz r0, 4(r27);
  stw r4, 0xf4(r25);
  stw r0, 0xf8(r25);
  lwz r0, 8(r27);
  stw r0, 0xfc(r25);
  lwz r4, 0(r26);
  lwz r0, 4(r26);
  stw r4, 0x100(r25);
  stw r0, 0x104(r25);
  lwz r0, 8(r26);
  stw r0, 0x108(r25);
lbl_80195e08:
  psq_l f31, 120(r1), 0, 0;
  lfd f31, 0x70(r1);
  psq_l f30, 104(r1), 0, 0;
  lfd f30, 0x60(r1);
  psq_l f29, 88(r1), 0, 0;
  lfd f29, 0x50(r1);
  psq_l f28, 72(r1), 0, 0;
  lfd f28, 0x40(r1);
  psq_l f27, 56(r1), 0, 0;
  addi r11, r1, 0x30;
  lfd f27, 0x30(r1);
  bl _restgpr_25;
  lwz r0, 0x84(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: select_2obj_continue
// PAL: 0x80195e48..0x80196070
MARK_BINARY_BLOB(select_2obj_continue, 0x80195e48, 0x80196070);
asm UNKNOWN_FUNCTION(select_2obj_continue) {
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
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lfs f31, _unk_8038881c;
  mr r31, r3;
  lfs f29, _unk_80388800;
  addi r28, r3, 0xc4;
  lfs f30, _unk_80388810;
  addi r30, r3, 0xe8;
lbl_80195e9c:
  lbz r0, 8(r28);
  extsb. r0, r0;
  bne lbl_80195fdc;
  addi r27, r28, 0xc;
  addi r29, r31, 0xe8;
lbl_80195eb0:
  lbz r0, 8(r27);
  extsb. r0, r0;
  bne lbl_80195fd0;
  lfs f3, 0(r27);
  lfs f2, 0(r28);
  lfs f1, 4(r27);
  lfs f0, 4(r28);
  fsubs f28, f3, f2;
  fsubs f27, f1, f0;
  fmuls f1, f28, f28;
  fmuls f0, f27, f27;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f2, f1;
  lfs f1, 0x510(r31);
  lfs f0, 0x514(r31);
  fdivs f4, f30, f2;
  fmuls f3, f28, f4;
  fmuls f2, f27, f4;
  fmuls f4, f4, f1;
  stfs f3, 8(r1);
  fcmpo cr0, f4, f0;
  stfs f2, 0xc(r1);
  cror 2, 0, 2;
  beq lbl_80195fd0;
  lfs f0, _unk_803859c8;
  fcmpo cr0, f4, f0;
  cror 2, 1, 2;
  beq lbl_80195fd0;
  lfs f0, 0x49c(r31);
  fsubs f4, f4, f0;
  fcmpo cr0, f4, f29;
  bge lbl_80195f40;
  lfs f0, 0x508(r31);
  fmuls f4, f4, f0;
  b lbl_80195f48;
lbl_80195f40:
  lfs f0, 0x504(r31);
  fmuls f4, f4, f0;
lbl_80195f48:
  fcmpo cr0, f4, f30;
  cror 2, 1, 2;
  beq lbl_80195fd0;
  lfs f3, 0x494(r31);
  lfs f2, 8(r1);
  lfs f1, 0x498(r31);
  lfs f0, 0xc(r1);
  fmuls f2, f3, f2;
  fmuls f0, f1, f0;
  fadds f1, f2, f0;
  fcmpo cr0, f1, f29;
  bge lbl_80195f84;
  fneg f1, f1;
  li r0, 1;
  b lbl_80195f88;
lbl_80195f84:
  li r0, 0;
lbl_80195f88:
  lfs f0, _unk_803859d4;
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  beq lbl_80195fd0;
  fsubs f1, f30, f1;
  fsubs f0, f30, f0;
  fdivs f0, f1, f0;
  fadds f4, f4, f0;
  fcmpo cr0, f4, f31;
  bge lbl_80195fd0;
  fmr f31, f4;
  cmpwi r0, 0;
  beq lbl_80195fc8;
  mr r26, r27;
  mr r25, r28;
  b lbl_80195fd0;
lbl_80195fc8:
  mr r26, r28;
  mr r25, r27;
lbl_80195fd0:
  addi r27, r27, 0xc;
  cmplw r27, r29;
  ble lbl_80195eb0;
lbl_80195fdc:
  addi r28, r28, 0xc;
  cmplw r28, r30;
  blt lbl_80195e9c;
  lfs f0, _unk_8038881c;
  fcmpu cr0, f0, f31;
  bne lbl_80195ffc;
  li r3, 0;
  b lbl_80196030;
lbl_80195ffc:
  lwz r4, 0(r26);
  li r3, 2;
  lwz r0, 4(r26);
  stw r4, 0xf4(r31);
  stw r0, 0xf8(r31);
  lwz r0, 8(r26);
  stw r0, 0xfc(r31);
  lwz r4, 0(r25);
  lwz r0, 4(r25);
  stw r4, 0x100(r31);
  stw r0, 0x104(r31);
  lwz r0, 8(r25);
  stw r0, 0x108(r31);
lbl_80196030:
  psq_l f31, 120(r1), 0, 0;
  lfd f31, 0x70(r1);
  psq_l f30, 104(r1), 0, 0;
  lfd f30, 0x60(r1);
  psq_l f29, 88(r1), 0, 0;
  lfd f29, 0x50(r1);
  psq_l f28, 72(r1), 0, 0;
  lfd f28, 0x40(r1);
  psq_l f27, 56(r1), 0, 0;
  addi r11, r1, 0x30;
  lfd f27, 0x30(r1);
  bl _restgpr_25;
  lwz r0, 0x84(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: select_1obj_first
// PAL: 0x80196070..0x80196224
MARK_BINARY_BLOB(select_1obj_first, 0x80196070, 0x80196224);
asm UNKNOWN_FUNCTION(select_1obj_first) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  addi r8, r3, 0xc4;
  addi r0, r3, 0xf4;
  lfs f5, 0xb0(r3);
  lfs f0, 0x4b8(r3);
  lfs f3, 0xb4(r3);
  lfs f1, 0x4bc(r3);
  fmuls f4, f5, f0;
  fmuls f2, f3, f0;
  lfs f0, 0x4a0(r3);
  fmuls f3, f3, f1;
  fmuls f1, f5, f1;
  fadds f7, f4, f3;
  fsubs f8, f2, f1;
  fmuls f7, f7, f0;
  fmuls f8, f8, f0;
lbl_801960b0:
  lbz r4, 8(r8);
  extsb. r4, r4;
  bne lbl_8019620c;
  lfs f2, 0(r8);
  lfs f0, 4(r8);
  fsubs f1, f2, f7;
  lfs f3, 0x4f4(r3);
  fsubs f6, f0, f8;
  fadds f5, f2, f7;
  fadds f4, f0, f8;
  stfs f1, 0x10(r1);
  fcmpo cr0, f1, f3;
  stfs f6, 0x14(r1);
  stfs f5, 8(r1);
  stfs f4, 0xc(r1);
  cror 2, 0, 2;
  beq lbl_80196124;
  lfs f2, 0x4fc(r3);
  fcmpo cr0, f1, f2;
  cror 2, 1, 2;
  beq lbl_80196124;
  lfs f1, 0x4f8(r3);
  fcmpo cr0, f6, f1;
  cror 2, 0, 2;
  beq lbl_80196124;
  lfs f0, 0x500(r3);
  fcmpo cr0, f6, f0;
  cror 2, 1, 2;
  bne lbl_8019619c;
lbl_80196124:
  lfs f1, 8(r1);
  lfs f0, 0x4f4(r3);
  fcmpo cr0, f1, f0;
  ble lbl_8019620c;
  lfs f0, 0x4fc(r3);
  fcmpo cr0, f1, f0;
  bge lbl_8019620c;
  lfs f1, 0xc(r1);
  lfs f0, 0x4f8(r3);
  fcmpo cr0, f1, f0;
  ble lbl_8019620c;
  lfs f0, 0x500(r3);
  fcmpo cr0, f1, f0;
  bge lbl_8019620c;
  lwz r5, 0(r8);
  li r4, 0;
  lwz r7, 4(r8);
  li r0, -1;
  lwz r6, 0x10(r1);
  stw r5, 0x100(r3);
  lwz r5, 0x14(r1);
  stw r7, 0x104(r3);
  lwz r7, 8(r8);
  stw r7, 0x108(r3);
  stw r6, 0xf4(r3);
  stw r5, 0xf8(r3);
  stb r4, 0xfc(r3);
  stb r0, 0xfd(r3);
  li r3, -1;
  b lbl_8019621c;
lbl_8019619c:
  fcmpo cr0, f5, f3;
  cror 2, 0, 2;
  beq lbl_801961cc;
  fcmpo cr0, f5, f2;
  cror 2, 1, 2;
  beq lbl_801961cc;
  fcmpo cr0, f4, f1;
  cror 2, 0, 2;
  beq lbl_801961cc;
  fcmpo cr0, f4, f0;
  cror 2, 1, 2;
  bne lbl_8019620c;
lbl_801961cc:
  lwz r5, 0(r8);
  li r4, 0;
  lwz r7, 4(r8);
  li r0, -1;
  lwz r6, 8(r1);
  stw r5, 0xf4(r3);
  lwz r5, 0xc(r1);
  stw r7, 0xf8(r3);
  lwz r7, 8(r8);
  stw r7, 0xfc(r3);
  stw r6, 0x100(r3);
  stw r5, 0x104(r3);
  stb r4, 0x108(r3);
  stb r0, 0x109(r3);
  li r3, -1;
  b lbl_8019621c;
lbl_8019620c:
  addi r8, r8, 0xc;
  cmplw r8, r0;
  blt lbl_801960b0;
  li r3, 0;
lbl_8019621c:
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: select_1obj_continue
// PAL: 0x80196224..0x80196398
MARK_BINARY_BLOB(select_1obj_continue, 0x80196224, 0x80196398);
asm UNKNOWN_FUNCTION(select_1obj_continue) {
  // clang-format off
  nofralloc;
  lfs f0, _unk_803859e0;
  addi r6, r3, 0xf4;
  addi r0, r3, 0x10c;
  fmuls f4, f0, f0;
lbl_80196234:
  lbz r4, 8(r6);
  extsb. r4, r4;
  bne lbl_801962a4;
  lbz r4, 9(r6);
  extsb. r4, r4;
  bne lbl_801962a4;
  addi r7, r3, 0xc4;
  addi r4, r3, 0xf4;
lbl_80196254:
  lbz r5, 8(r7);
  extsb. r5, r5;
  bne lbl_80196298;
  lfs f3, 0(r6);
  lfs f2, 0(r7);
  lfs f1, 4(r6);
  lfs f0, 4(r7);
  fsubs f2, f3, f2;
  fsubs f0, f1, f0;
  fmuls f1, f2, f2;
  fmuls f0, f0, f0;
  fadds f0, f1, f0;
  fcmpo cr0, f0, f4;
  bge lbl_80196298;
  fmr f4, f0;
  mr r8, r6;
  mr r9, r7;
lbl_80196298:
  addi r7, r7, 0xc;
  cmplw r7, r4;
  blt lbl_80196254;
lbl_801962a4:
  addi r6, r6, 0xc;
  cmplw r6, r0;
  blt lbl_80196234;
  lfs f0, _unk_803859e0;
  fmuls f0, f0, f0;
  fcmpu cr0, f4, f0;
  bne lbl_801962c8;
  li r3, 0;
  blr;
lbl_801962c8:
  lwz r5, 0(r9);
  addi r0, r3, 0xf4;
  lwz r4, 4(r9);
  cmplw r8, r0;
  stw r5, 0(r8);
  stw r4, 4(r8);
  lwz r0, 8(r9);
  stw r0, 8(r8);
  lfs f5, 0xb0(r3);
  lfs f0, 0x4b8(r3);
  lfs f3, 0xb4(r3);
  lfs f1, 0x4bc(r3);
  fmuls f4, f5, f0;
  fmuls f2, f3, f0;
  lfs f0, 0x490(r3);
  fmuls f3, f3, f1;
  fmuls f1, f5, f1;
  fadds f3, f4, f3;
  fsubs f1, f2, f1;
  fmuls f2, f0, f3;
  stfs f3, 0x494(r3);
  fmuls f3, f0, f1;
  stfs f1, 0x498(r3);
  bne lbl_80196354;
  lfs f0, 0(r8);
  li r4, 0;
  li r0, -1;
  fadds f0, f0, f2;
  stfs f0, 0x100(r3);
  lfs f0, 4(r8);
  fadds f0, f0, f3;
  stb r4, 0x108(r3);
  stb r0, 0x109(r3);
  stfs f0, 0x104(r3);
  b lbl_8019637c;
lbl_80196354:
  lfs f0, 0(r8);
  li r4, 0;
  li r0, -1;
  fsubs f0, f0, f2;
  stfs f0, 0xf4(r3);
  lfs f0, 4(r8);
  fsubs f0, f0, f3;
  stb r4, 0xfc(r3);
  stb r0, 0xfd(r3);
  stfs f0, 0xf8(r3);
lbl_8019637c:
  lbz r0, 0x5e(r3);
  extsb. r0, r0;
  bge lbl_80196390;
  li r3, -1;
  blr;
lbl_80196390:
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: calc_dpd_variable
// PAL: 0x80196398..0x80196964
MARK_BINARY_BLOB(calc_dpd_variable, 0x80196398, 0x80196964);
asm UNKNOWN_FUNCTION(calc_dpd_variable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  extsb. r0, r4;
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  bne lbl_801963c8;
  li r0, 0;
  stb r0, 0x5e(r3);
  b lbl_8019694c;
lbl_801963c8:
  lfs f4, 0xb0(r3);
  lfs f1, 0x494(r3);
  lfs f2, 0xb4(r3);
  fmuls f3, f4, f1;
  lfs f0, 0x498(r3);
  fmuls f1, f2, f1;
  lbz r0, 0x5e(r3);
  fmuls f2, f2, f0;
  fmuls f0, f4, f0;
  extsb. r0, r0;
  fadds f3, f3, f2;
  fsubs f2, f1, f0;
  stfs f3, 0x10(r1);
  stfs f2, 0x14(r1);
  bne lbl_80196430;
  lwz r4, 0x10(r1);
  lwz r0, 0x14(r1);
  stw r4, 0x34(r3);
  lfs f0, _unk_80388800;
  stw r0, 0x38(r3);
  lwz r4, _unk_80386828;
  lwz r0, _unk_8038682c;
  stw r4, 0x3c(r3);
  stw r0, 0x40(r3);
  stfs f0, 0x44(r3);
  b lbl_801965f8;
lbl_80196430:
  lfs f1, 0x34(r3);
  lfs f0, 0x38(r3);
  fsubs f3, f3, f1;
  fsubs f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 8(r1);
  fmuls f0, f2, f2;
  stfs f2, 0xc(r1);
  fadds f1, f1, f0;
  bl sqrt;
  lwz r0, 0x52c(r30);
  frsp f2, f1;
  cmpwi r0, 0;
  bne lbl_8019652c;
  lfs f0, 0x8c(r30);
  fcmpo cr0, f2, f0;
  cror 2, 1, 2;
  bne lbl_80196480;
  lfs f4, _unk_80388810;
  b lbl_8019648c;
lbl_80196480:
  fdivs f4, f2, f0;
  fmuls f4, f4, f4;
  fmuls f4, f4, f4;
lbl_8019648c:
  lfs f0, 0x90(r30);
  lfs f3, 8(r1);
  fmuls f4, f4, f0;
  lfs f1, 0xc(r1);
  lfs f2, 0x34(r30);
  lfs f0, 0x38(r30);
  fmuls f3, f4, f3;
  fmuls f1, f4, f1;
  fadds f3, f2, f3;
  fadds f2, f0, f1;
  fmuls f1, f3, f3;
  stfs f3, 8(r1);
  fmuls f0, f2, f2;
  stfs f2, 0xc(r1);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f4, f1;
  lfs f0, 8(r1);
  lfs f2, 0xc(r1);
  lfs f1, 0x34(r30);
  fdivs f3, f0, f4;
  lfs f0, 0x38(r30);
  fdivs f2, f2, f4;
  stfs f3, 8(r1);
  fsubs f3, f3, f1;
  stfs f2, 0xc(r1);
  fsubs f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 0x3c(r30);
  fmuls f0, f2, f2;
  stfs f2, 0x40(r30);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f0, f1;
  lwz r3, 8(r1);
  lwz r0, 0xc(r1);
  stw r3, 0x34(r30);
  stfs f0, 0x44(r30);
  stw r0, 0x38(r30);
  b lbl_801965f8;
lbl_8019652c:
  lfs f0, 0x8c(r30);
  fcmpo cr0, f2, f0;
  ble lbl_801965e0;
  fsubs f0, f2, f0;
  lfs f4, 0x90(r30);
  lfs f3, 8(r1);
  lfs f1, 0xc(r1);
  fdivs f5, f0, f2;
  lfs f2, 0x34(r30);
  lfs f0, 0x38(r30);
  fmuls f4, f4, f5;
  fmuls f3, f3, f4;
  fmuls f1, f1, f4;
  fadds f3, f2, f3;
  fadds f2, f0, f1;
  fmuls f1, f3, f3;
  stfs f3, 8(r1);
  fmuls f0, f2, f2;
  stfs f2, 0xc(r1);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f4, f1;
  lfs f0, 8(r1);
  lfs f2, 0xc(r1);
  lfs f1, 0x34(r30);
  fdivs f3, f0, f4;
  lfs f0, 0x38(r30);
  fdivs f2, f2, f4;
  stfs f3, 8(r1);
  fsubs f3, f3, f1;
  stfs f2, 0xc(r1);
  fsubs f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 0x3c(r30);
  fmuls f0, f2, f2;
  stfs f2, 0x40(r30);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f0, f1;
  lwz r3, 8(r1);
  lwz r0, 0xc(r1);
  stw r3, 0x34(r30);
  stfs f0, 0x44(r30);
  stw r0, 0x38(r30);
  b lbl_801965f8;
lbl_801965e0:
  lwz r3, _unk_80386828;
  lwz r0, _unk_8038682c;
  lfs f0, _unk_80388800;
  stw r3, 0x3c(r30);
  stw r0, 0x40(r30);
  stfs f0, 0x44(r30);
lbl_801965f8:
  lfs f1, 0x510(r30);
  lfs f0, 0x490(r30);
  lbz r0, 0x5e(r30);
  fdivs f2, f1, f0;
  extsb. r0, r0;
  bne lbl_80196624;
  lfs f0, _unk_80388800;
  stfs f2, 0x48(r30);
  stfs f0, 0x4c(r30);
  stfs f0, 0x50(r30);
  b lbl_80196714;
lbl_80196624:
  lfs f1, 0x48(r30);
  lfs f0, _unk_80388800;
  fsubs f4, f2, f1;
  fcmpo cr0, f4, f0;
  bge lbl_80196640;
  fneg f3, f4;
  b lbl_80196644;
lbl_80196640:
  fmr f3, f4;
lbl_80196644:
  lwz r0, 0x530(r30);
  cmpwi r0, 0;
  bne lbl_801966b4;
  lfs f0, 0x94(r30);
  fcmpo cr0, f3, f0;
  cror 2, 1, 2;
  bne lbl_80196668;
  lfs f3, _unk_80388810;
  b lbl_80196674;
lbl_80196668:
  fdivs f3, f3, f0;
  fmuls f3, f3, f3;
  fmuls f3, f3, f3;
lbl_80196674:
  lfs f1, 0x98(r30);
  lfs f0, _unk_80388800;
  fmuls f3, f3, f1;
  fmuls f1, f3, f4;
  fcmpo cr0, f1, f0;
  stfs f1, 0x4c(r30);
  bge lbl_8019669c;
  fneg f0, f1;
  stfs f0, 0x50(r30);
  b lbl_801966a0;
lbl_8019669c:
  stfs f1, 0x50(r30);
lbl_801966a0:
  lfs f1, 0x48(r30);
  lfs f0, 0x4c(r30);
  fadds f0, f1, f0;
  stfs f0, 0x48(r30);
  b lbl_80196714;
lbl_801966b4:
  lfs f0, 0x94(r30);
  fcmpo cr0, f3, f0;
  ble lbl_80196708;
  fsubs f2, f3, f0;
  lfs f1, 0x98(r30);
  lfs f0, _unk_80388800;
  fdivs f2, f2, f3;
  fmuls f1, f1, f2;
  fmuls f1, f1, f4;
  fcmpo cr0, f1, f0;
  stfs f1, 0x4c(r30);
  bge lbl_801966f0;
  fneg f0, f1;
  stfs f0, 0x50(r30);
  b lbl_801966f4;
lbl_801966f0:
  stfs f1, 0x50(r30);
lbl_801966f4:
  lfs f1, 0x48(r30);
  lfs f0, 0x4c(r30);
  fadds f0, f1, f0;
  stfs f0, 0x48(r30);
  b lbl_80196714;
lbl_80196708:
  lfs f0, _unk_80388800;
  stfs f0, 0x4c(r30);
  stfs f0, 0x50(r30);
lbl_80196714:
  lfs f2, 0x498(r30);
  lfs f0, 0xb4(r30);
  fneg f1, f2;
  lbz r0, 0x5e(r30);
  lfs f5, 0x494(r30);
  fmuls f3, f2, f0;
  lfs f4, 0xb0(r30);
  extsb. r0, r0;
  fmuls f0, f5, f0;
  lfs f7, 0xf4(r30);
  fmuls f2, f1, f4;
  lfs f6, 0x100(r30);
  fmuls f5, f5, f4;
  lfs f4, 0xf8(r30);
  lfs f1, 0x104(r30);
  fadds f7, f7, f6;
  lfs f8, _unk_80388804;
  fadds f3, f5, f3;
  fadds f6, f4, f1;
  lfs f4, 0xac(r30);
  fmuls f7, f8, f7;
  fadds f2, f2, f0;
  lfs f1, 0xa8(r30);
  fmuls f5, f8, f6;
  fmuls f9, f3, f7;
  lfs f6, 0xb8(r30);
  fmuls f7, f2, f7;
  fmuls f0, f3, f5;
  lfs f3, 0xbc(r30);
  fmuls f8, f2, f5;
  lfs f5, 0xc0(r30);
  fneg f2, f4;
  fadds f7, f7, f0;
  fsubs f8, f9, f8;
  fneg f0, f1;
  fsubs f3, f3, f7;
  fsubs f6, f6, f8;
  fmuls f6, f5, f6;
  fmuls f5, f5, f3;
  fmuls f3, f2, f6;
  stfs f6, 8(r1);
  fmuls f2, f1, f5;
  fmuls f1, f0, f6;
  stfs f5, 0xc(r1);
  fmuls f0, f4, f5;
  fadds f3, f3, f2;
  fsubs f2, f1, f0;
  stfs f3, 0x10(r1);
  stfs f2, 0x14(r1);
  bne lbl_80196808;
  lwz r3, 0x10(r1);
  lwz r0, 0x14(r1);
  stw r3, 0x20(r30);
  lfs f0, _unk_80388800;
  stw r0, 0x24(r30);
  lwz r3, _unk_80386828;
  lwz r0, _unk_8038682c;
  stw r3, 0x28(r30);
  stw r0, 0x2c(r30);
  stfs f0, 0x30(r30);
  b lbl_80196948;
lbl_80196808:
  lfs f1, 0x20(r30);
  lfs f0, 0x24(r30);
  fsubs f3, f3, f1;
  fsubs f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 8(r1);
  fmuls f0, f2, f2;
  stfs f2, 0xc(r1);
  fadds f1, f1, f0;
  bl sqrt;
  lwz r0, 0x528(r30);
  frsp f4, f1;
  cmpwi r0, 0;
  bne lbl_801968c0;
  lfs f0, 0x84(r30);
  fcmpo cr0, f4, f0;
  cror 2, 1, 2;
  bne lbl_80196858;
  lfs f2, _unk_80388810;
  b lbl_80196864;
lbl_80196858:
  fdivs f2, f4, f0;
  fmuls f2, f2, f2;
  fmuls f2, f2, f2;
lbl_80196864:
  lfs f0, 0x88(r30);
  lfs f1, 8(r1);
  fmuls f2, f2, f0;
  lfs f0, 0xc(r1);
  fmuls f3, f2, f1;
  fmuls f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 0x28(r30);
  fmuls f0, f2, f2;
  stfs f2, 0x2c(r30);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f4, f1;
  lfs f3, 0x20(r30);
  lfs f2, 0x28(r30);
  lfs f1, 0x24(r30);
  lfs f0, 0x2c(r30);
  fadds f2, f3, f2;
  stfs f4, 0x30(r30);
  fadds f0, f1, f0;
  stfs f2, 0x20(r30);
  stfs f0, 0x24(r30);
  b lbl_80196948;
lbl_801968c0:
  lfs f0, 0x84(r30);
  fcmpo cr0, f4, f0;
  ble lbl_80196930;
  fsubs f3, f4, f0;
  lfs f2, 0x88(r30);
  lfs f1, 8(r1);
  lfs f0, 0xc(r1);
  fdivs f3, f3, f4;
  fmuls f2, f2, f3;
  fmuls f3, f2, f1;
  fmuls f2, f2, f0;
  fmuls f1, f3, f3;
  stfs f3, 0x28(r30);
  fmuls f0, f2, f2;
  stfs f2, 0x2c(r30);
  fadds f1, f1, f0;
  bl sqrt;
  frsp f4, f1;
  lfs f3, 0x20(r30);
  lfs f2, 0x28(r30);
  lfs f1, 0x24(r30);
  lfs f0, 0x2c(r30);
  fadds f2, f3, f2;
  stfs f4, 0x30(r30);
  fadds f0, f1, f0;
  stfs f2, 0x20(r30);
  stfs f0, 0x24(r30);
  b lbl_80196948;
lbl_80196930:
  lwz r3, _unk_80386828;
  lwz r0, _unk_8038682c;
  lfs f0, _unk_80388800;
  stw r3, 0x28(r30);
  stw r0, 0x2c(r30);
  stfs f0, 0x30(r30);
lbl_80196948:
  stb r31, 0x5e(r30);
lbl_8019694c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: read_kpad_dpd
// PAL: 0x80196964..0x80196dbc
MARK_BINARY_BLOB(read_kpad_dpd, 0x80196964, 0x80196dbc);
asm UNKNOWN_FUNCTION(read_kpad_dpd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stfd f31, 0x30(r1);
  psq_st f31, 56(r1), 0, 0;
  stfd f30, 0x20(r1);
  psq_st f30, 40(r1), 0, 0;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  lbz r0, 0x36(r4);
  cmplwi r0, 2;
  beq lbl_801969a8;
  cmplwi r0, 5;
  beq lbl_801969a8;
  cmplwi r0, 8;
  bne lbl_80196a48;
lbl_801969a8:
  lfd f4, _unk_80388820;
  addi r8, r4, 0x20;
  lfs f3, _unk_80388828;
  addi r9, r3, 0xe8;
  lfs f2, _unk_8038882c;
  addi r0, r3, 0xc4;
  lfs f1, _unk_80388830;
  li r4, -1;
  lis r7, 0x4330;
  li r5, 0;
lbl_801969d0:
  lhz r6, 4(r8);
  cmpwi r6, 0;
  beq lbl_80196a30;
  lha r6, 0(r8);
  stw r7, 8(r1);
  xoris r6, r6, 0x8000;
  stw r6, 0xc(r1);
  lfd f0, 8(r1);
  stw r7, 0x10(r1);
  fsubs f0, f0, f4;
  fmuls f0, f3, f0;
  fsubs f0, f0, f2;
  stfs f0, 0(r9);
  lha r6, 2(r8);
  xoris r6, r6, 0x8000;
  stw r6, 0x14(r1);
  lfd f0, 0x10(r1);
  fsubs f0, f0, f4;
  fmuls f0, f3, f0;
  fsubs f0, f0, f1;
  stfs f0, 4(r9);
  stb r5, 8(r9);
  stb r5, 9(r9);
  b lbl_80196a34;
lbl_80196a30:
  stb r4, 8(r9);
lbl_80196a34:
  addi r9, r9, -12;
  addi r8, r8, -8;
  cmplw r9, r0;
  bge lbl_801969d0;
  b lbl_80196a64;
lbl_80196a48:
  addi r5, r3, 0xe8;
  addi r0, r3, 0xc4;
  li r4, -1;
lbl_80196a54:
  stb r4, 8(r5);
  addi r5, r5, -12;
  cmplw r5, r0;
  bge lbl_80196a54;
lbl_80196a64:
  addi r7, r3, 0xe8;
  addi r6, r3, 0xc4;
  mr r4, r7;
lbl_80196a70:
  lbz r0, 8(r4);
  extsb. r0, r0;
  blt lbl_80196ad0;
  lfs f1, 0(r4);
  lfs f0, 0x4f4(r3);
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  beq lbl_80196ac4;
  lfs f0, 0x4fc(r3);
  fcmpo cr0, f1, f0;
  cror 2, 1, 2;
  beq lbl_80196ac4;
  lfs f1, 4(r4);
  lfs f0, 0x4f8(r3);
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  beq lbl_80196ac4;
  lfs f0, 0x500(r3);
  fcmpo cr0, f1, f0;
  cror 2, 1, 2;
  bne lbl_80196ad0;
lbl_80196ac4:
  lbz r0, 8(r4);
  ori r0, r0, 1;
  stb r0, 8(r4);
lbl_80196ad0:
  addi r4, r4, -12;
  cmplw r4, r6;
  bge lbl_80196a70;
lbl_80196adc:
  lbz r0, 8(r6);
  extsb. r0, r0;
  bne lbl_80196b2c;
  addi r5, r6, 0xc;
lbl_80196aec:
  lbz r4, 8(r5);
  extsb. r0, r4;
  bne lbl_80196b20;
  lfs f1, 0(r6);
  lfs f0, 0(r5);
  fcmpu cr0, f1, f0;
  bne lbl_80196b20;
  lfs f1, 4(r6);
  lfs f0, 4(r5);
  fcmpu cr0, f1, f0;
  bne lbl_80196b20;
  ori r0, r4, 2;
  stb r0, 8(r5);
lbl_80196b20:
  addi r5, r5, 0xc;
  cmplw r5, r7;
  ble lbl_80196aec;
lbl_80196b2c:
  addi r6, r6, 0xc;
  cmplw r6, r7;
  blt lbl_80196adc;
  li r0, 0;
  addi r5, r3, 0xe8;
  sth r0, 0x10c(r3);
  addi r0, r3, 0xc4;
lbl_80196b48:
  lbz r4, 8(r5);
  extsb. r4, r4;
  bne lbl_80196b60;
  lha r4, 0x10c(r3);
  addi r4, r4, 1;
  sth r4, 0x10c(r3);
lbl_80196b60:
  addi r5, r5, -12;
  cmplw r5, r0;
  bge lbl_80196b48;
  lfs f1, 0x54(r3);
  lfs f0, _unk_803859dc;
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  beq lbl_80196c70;
  lbz r0, 0x5e(r3);
  extsb r0, r0;
  cmpwi r0, 2;
  beq lbl_80196b98;
  cmpwi r0, -2;
  bne lbl_80196bdc;
lbl_80196b98:
  lha r0, 0x10c(r3);
  cmpwi r0, 2;
  blt lbl_80196bb8;
  mr r3, r31;
  bl select_2obj_continue;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
lbl_80196bb8:
  lha r0, 0x10c(r31);
  cmpwi r0, 1;
  blt lbl_80196c70;
  mr r3, r31;
  bl select_1obj_continue;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
  b lbl_80196c70;
lbl_80196bdc:
  cmpwi r0, 1;
  beq lbl_80196bec;
  cmpwi r0, -1;
  bne lbl_80196c30;
lbl_80196bec:
  lha r0, 0x10c(r3);
  cmpwi r0, 2;
  blt lbl_80196c0c;
  mr r3, r31;
  bl select_2obj_first;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
lbl_80196c0c:
  lha r0, 0x10c(r31);
  cmpwi r0, 1;
  blt lbl_80196c70;
  mr r3, r31;
  bl select_1obj_continue;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
  b lbl_80196c70;
lbl_80196c30:
  lha r0, 0x10c(r3);
  cmpwi r0, 2;
  blt lbl_80196c50;
  mr r3, r31;
  bl select_2obj_first;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
lbl_80196c50:
  lha r0, 0x10c(r31);
  cmpwi r0, 1;
  bne lbl_80196c70;
  mr r3, r31;
  bl select_1obj_first;
  extsb. r0, r3;
  mr r30, r3;
  bne lbl_80196c74;
lbl_80196c70:
  li r30, 0;
lbl_80196c74:
  extsb. r0, r30;
  beq lbl_80196d80;
  lfs f3, 0x100(r31);
  lfs f2, 0xf4(r31);
  lfs f1, 0x104(r31);
  lfs f0, 0xf8(r31);
  fsubs f30, f3, f2;
  fsubs f31, f1, f0;
  fmuls f1, f30, f30;
  fmuls f0, f31, f31;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f3, f1;
  lfs f0, _unk_80388810;
  lhz r0, 0x4c8(r31);
  lfs f4, 0xb0(r31);
  fdivs f2, f0, f3;
  lfs f1, 0x510(r31);
  lfs f0, 0xb4(r31);
  cmpwi r0, 0;
  stfs f3, 0x490(r31);
  fmuls f30, f30, f2;
  fmuls f31, f31, f2;
  fmuls f5, f1, f2;
  fmuls f3, f4, f30;
  stfs f30, 0x494(r31);
  fmuls f2, f0, f31;
  fmuls f1, f0, f30;
  stfs f5, 0x49c(r31);
  fmuls f0, f4, f31;
  fadds f2, f3, f2;
  stfs f31, 0x498(r31);
  fsubs f3, f1, f0;
  stfs f2, 0x4b0(r31);
  stfs f3, 0x4b4(r31);
  bne lbl_80196d38;
  lfs f0, 0x4b8(r31);
  lfs f1, 0x4bc(r31);
  fmuls f2, f2, f0;
  lfs f0, _unk_803859d8;
  fmuls f1, f3, f1;
  fadds f1, f2, f1;
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  bne lbl_80196d38;
  li r0, 1;
  li r30, 0;
  stb r0, 0x108(r31);
  stb r0, 0xfc(r31);
lbl_80196d38:
  lbz r0, 0x5e(r31);
  cmpwi r0, 2;
  bne lbl_80196d74;
  extsb r0, r30;
  cmpwi r0, 2;
  bne lbl_80196d74;
  lbz r3, 0x4ca(r31);
  cmplwi r3, 0xc8;
  bne lbl_80196d68;
  lfs f0, 0x490(r31);
  stfs f0, 0x4a0(r31);
  b lbl_80196d88;
lbl_80196d68:
  addi r0, r3, 1;
  stb r0, 0x4ca(r31);
  b lbl_80196d88;
lbl_80196d74:
  li r0, 0;
  stb r0, 0x4ca(r31);
  b lbl_80196d88;
lbl_80196d80:
  li r0, 0;
  stb r0, 0x4ca(r31);
lbl_80196d88:
  mr r3, r31;
  extsb r4, r30;
  bl calc_dpd_variable;
  psq_l f31, 56(r1), 0, 0;
  lfd f31, 0x30(r1);
  psq_l f30, 40(r1), 0, 0;
  lfd f30, 0x20(r1);
  lwz r31, 0x1c(r1);
  lwz r0, 0x44(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: clamp_stick_circle
// PAL: 0x80196dbc..0x80196ee4
MARK_BINARY_BLOB(clamp_stick_circle, 0x80196dbc, 0x80196ee4);
asm UNKNOWN_FUNCTION(clamp_stick_circle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stfd f31, 0x50(r1);
  psq_st f31, 88(r1), 0, 0;
  stfd f30, 0x40(r1);
  psq_st f30, 72(r1), 0, 0;
  stfd f29, 0x30(r1);
  psq_st f29, 56(r1), 0, 0;
  stfd f28, 0x20(r1);
  psq_st f28, 40(r1), 0, 0;
  lis r8, 0x4330;
  xoris r0, r4, 0x8000;
  xoris r5, r5, 0x8000;
  stw r0, 0xc(r1);
  xoris r4, r6, 0x8000;
  lfd f4, _unk_80388820;
  xoris r0, r7, 0x8000;
  stw r8, 8(r1);
  lfd f0, 8(r1);
  stw r8, 0x10(r1);
  fsubs f31, f0, f4;
  stw r5, 0x14(r1);
  lfd f0, 0x10(r1);
  fmuls f1, f31, f31;
  stw r4, 0xc(r1);
  fsubs f30, f0, f4;
  stw r0, 0x14(r1);
  lfd f3, 8(r1);
  fmuls f0, f30, f30;
  lfd f2, 0x10(r1);
  stw r31, 0x1c(r1);
  fsubs f29, f3, f4;
  fsubs f28, f2, f4;
  mr r31, r3;
  fadds f1, f1, f0;
  bl sqrt;
  frsp f2, f1;
  fcmpo cr0, f2, f29;
  cror 2, 0, 2;
  bne lbl_80196e70;
  lfs f0, _unk_80388800;
  stfs f0, 4(r31);
  stfs f0, 0(r31);
  b lbl_80196eb0;
lbl_80196e70:
  fcmpo cr0, f2, f28;
  cror 2, 1, 2;
  bne lbl_80196e90;
  fdivs f1, f31, f2;
  fdivs f0, f30, f2;
  stfs f1, 0(r31);
  stfs f0, 4(r31);
  b lbl_80196eb0;
lbl_80196e90:
  fsubs f1, f2, f29;
  fsubs f0, f28, f29;
  fdivs f0, f1, f0;
  fdivs f0, f0, f2;
  fmuls f1, f31, f0;
  fmuls f0, f30, f0;
  stfs f1, 0(r31);
  stfs f0, 4(r31);
lbl_80196eb0:
  psq_l f31, 88(r1), 0, 0;
  lfd f31, 0x50(r1);
  psq_l f30, 72(r1), 0, 0;
  lfd f30, 0x40(r1);
  psq_l f29, 56(r1), 0, 0;
  lfd f29, 0x30(r1);
  psq_l f28, 40(r1), 0, 0;
  lfd f28, 0x20(r1);
  lwz r0, 0x64(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: clamp_stick_cross
// PAL: 0x80196ee4..0x80197108
MARK_BINARY_BLOB(clamp_stick_cross, 0x80196ee4, 0x80197108);
asm UNKNOWN_FUNCTION(clamp_stick_cross) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  lis r0, 0x4330;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r0, 8(r1);
  stw r0, 0x10(r1);
  bge lbl_80196f80;
  neg r0, r4;
  cmpw r0, r6;
  bgt lbl_80196f24;
  lfs f0, _unk_80388800;
  stfs f0, 0(r3);
  b lbl_80196f70;
lbl_80196f24:
  cmpw r0, r7;
  blt lbl_80196f38;
  lfs f0, _unk_80388810;
  stfs f0, 0(r3);
  b lbl_80196f70;
lbl_80196f38:
  add r4, r4, r6;
  subf r0, r6, r7;
  neg r4, r4;
  lfd f2, _unk_80388820;
  xoris r4, r4, 0x8000;
  xoris r0, r0, 0x8000;
  stw r4, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 0(r3);
lbl_80196f70:
  lfs f0, 0(r3);
  fneg f0, f0;
  stfs f0, 0(r3);
  b lbl_80196fdc;
lbl_80196f80:
  cmpw r4, r6;
  bgt lbl_80196f94;
  lfs f0, _unk_80388800;
  stfs f0, 0(r3);
  b lbl_80196fdc;
lbl_80196f94:
  cmpw r4, r7;
  blt lbl_80196fa8;
  lfs f0, _unk_80388810;
  stfs f0, 0(r3);
  b lbl_80196fdc;
lbl_80196fa8:
  subf r4, r6, r4;
  subf r0, r6, r7;
  xoris r4, r4, 0x8000;
  lfd f2, _unk_80388820;
  xoris r0, r0, 0x8000;
  stw r4, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 0(r3);
lbl_80196fdc:
  cmpwi r5, 0;
  bge lbl_80197058;
  neg r0, r5;
  cmpw r0, r6;
  bgt lbl_80196ffc;
  lfs f0, _unk_80388800;
  stfs f0, 4(r3);
  b lbl_80197048;
lbl_80196ffc:
  cmpw r0, r7;
  blt lbl_80197010;
  lfs f0, _unk_80388810;
  stfs f0, 4(r3);
  b lbl_80197048;
lbl_80197010:
  add r4, r5, r6;
  subf r0, r6, r7;
  neg r4, r4;
  lfd f2, _unk_80388820;
  xoris r4, r4, 0x8000;
  xoris r0, r0, 0x8000;
  stw r4, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 4(r3);
lbl_80197048:
  lfs f0, 4(r3);
  fneg f0, f0;
  stfs f0, 4(r3);
  b lbl_801970b4;
lbl_80197058:
  cmpw r5, r6;
  bgt lbl_8019706c;
  lfs f0, _unk_80388800;
  stfs f0, 4(r3);
  b lbl_801970b4;
lbl_8019706c:
  cmpw r5, r7;
  blt lbl_80197080;
  lfs f0, _unk_80388810;
  stfs f0, 4(r3);
  b lbl_801970b4;
lbl_80197080:
  subf r4, r6, r5;
  subf r0, r6, r7;
  xoris r4, r4, 0x8000;
  lfd f2, _unk_80388820;
  xoris r0, r0, 0x8000;
  stw r4, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 4(r3);
lbl_801970b4:
  lfs f0, 0(r3);
  lfs f1, 4(r3);
  fmuls f2, f0, f0;
  lfs f0, _unk_80388810;
  fmuls f1, f1, f1;
  fadds f1, f2, f1;
  fcmpo cr0, f1, f0;
  ble lbl_801970f4;
  bl sqrt;
  frsp f2, f1;
  lfs f1, 0(r31);
  lfs f0, 4(r31);
  fdivs f1, f1, f2;
  fdivs f0, f0, f2;
  stfs f1, 0(r31);
  stfs f0, 4(r31);
lbl_801970f4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: read_kpad_stick
// PAL: 0x80197108..0x80197380
MARK_BINARY_BLOB(read_kpad_stick, 0x80197108, 0x80197380);
asm UNKNOWN_FUNCTION(read_kpad_stick) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lis r5, 0x4330;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, 0x8019;
  addi r31, r31, 0x6ee4;
  stw r30, 0x28(r1);
  addi r30, r3, 0x60;
  stw r29, 0x24(r1);
  mr r29, r4;
  lwz r0, _unk_80386820;
  stw r5, 8(r1);
  cmpwi r0, 0;
  stw r5, 0x10(r1);
  beq lbl_80197150;
  lis r31, 0x8019;
  addi r31, r31, 0x6dbc;
lbl_80197150:
  lbz r6, 0x28(r4);
  cmplwi r6, 1;
  bne lbl_801971e0;
  lbz r5, 0x36(r4);
  addi r0, r5, 0xfd;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 2;
  bgt lbl_801971e0;
  lbz r0, 0x51e(r3);
  cmpwi r0, 0;
  beq lbl_801971b4;
  li r0, 0;
  lfs f2, _unk_80388800;
  stb r0, 0x51e(r3);
  lfs f1, _unk_8038880c;
  lwz r3, _unk_80386828;
  lwz r0, _unk_8038682c;
  lfs f0, _unk_80388810;
  stw r3, 0(r30);
  stw r0, 4(r30);
  stfs f2, 0x10(r30);
  stfs f2, 8(r30);
  stfs f1, 0xc(r30);
  stfs f0, 0x14(r30);
  stfs f2, 0x18(r30);
lbl_801971b4:
  lbz r4, 0x30(r4);
  mr r12, r31;
  lbz r5, 0x31(r29);
  mr r3, r30;
  extsb r4, r4;
  lwz r6, _unk_803859e4;
  extsb r5, r5;
  lwz r7, _unk_803859e8;
  mtctr r12;
  bctrl;
  b lbl_80197364;
lbl_801971e0:
  cmplwi r6, 2;
  bne lbl_80197364;
  lbz r5, 0x36(r4);
  addi r0, r5, 0xfa;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 2;
  bgt lbl_80197364;
  lbz r0, 0x51e(r3);
  cmpwi r0, 0;
  beq lbl_80197254;
  li r7, 0;
  lfs f0, _unk_80388800;
  stb r7, 0x51e(r3);
  lhz r0, 0x4d0(r3);
  lwz r6, _unk_80386828;
  lwz r5, _unk_8038682c;
  stw r6, 0xc(r30);
  stw r5, 0x10(r30);
  lwz r6, _unk_80386828;
  lwz r5, _unk_8038682c;
  stw r6, 0x14(r30);
  stw r5, 0x18(r30);
  stfs f0, 0x20(r30);
  stfs f0, 0x1c(r30);
  stw r7, 8(r30);
  stw r7, 4(r30);
  stw r7, 0(r30);
  sth r7, 0x4d4(r3);
  sth r0, 0x4d6(r3);
lbl_80197254:
  mr r12, r31;
  addi r3, r30, 0xc;
  lha r4, 0x2c(r4);
  lha r5, 0x2e(r29);
  lwz r6, _unk_803859ec;
  lwz r7, _unk_803859f0;
  mtctr r12;
  bctrl;
  mr r12, r31;
  addi r3, r30, 0x14;
  lha r4, 0x30(r29);
  lha r5, 0x32(r29);
  lwz r6, _unk_803859ec;
  lwz r7, _unk_803859f0;
  mtctr r12;
  bctrl;
  lwz r5, _unk_803859f4;
  lbz r0, 0x34(r29);
  lwz r4, _unk_803859f8;
  cmpw r0, r5;
  bgt lbl_801972b4;
  lfs f0, _unk_80388800;
  stfs f0, 0x1c(r30);
  b lbl_801972fc;
lbl_801972b4:
  cmpw r0, r4;
  blt lbl_801972c8;
  lfs f0, _unk_80388810;
  stfs f0, 0x1c(r30);
  b lbl_801972fc;
lbl_801972c8:
  subf r3, r5, r0;
  subf r0, r5, r4;
  xoris r3, r3, 0x8000;
  lfd f2, _unk_80388820;
  xoris r0, r0, 0x8000;
  stw r3, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 0x1c(r30);
lbl_801972fc:
  lwz r5, _unk_803859f4;
  lbz r0, 0x35(r29);
  lwz r4, _unk_803859f8;
  cmpw r0, r5;
  bgt lbl_8019731c;
  lfs f0, _unk_80388800;
  stfs f0, 0x20(r30);
  b lbl_80197364;
lbl_8019731c:
  cmpw r0, r4;
  blt lbl_80197330;
  lfs f0, _unk_80388810;
  stfs f0, 0x20(r30);
  b lbl_80197364;
lbl_80197330:
  subf r3, r5, r0;
  subf r0, r5, r4;
  xoris r3, r3, 0x8000;
  lfd f2, _unk_80388820;
  xoris r0, r0, 0x8000;
  stw r3, 0xc(r1);
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f2;
  fsubs f0, f0, f2;
  fdivs f0, f1, f0;
  stfs f0, 0x20(r30);
lbl_80197364:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: KPADRead
// PAL: 0x80197380..0x80197aac
MARK_BINARY_BLOB(KPADRead, 0x80197380, 0x80197aac);
asm UNKNOWN_FUNCTION(KPADRead) {
  // clang-format off
  nofralloc;
  stwu r1, -0xc0(r1);
  mflr r0;
  stw r0, 0xc4(r1);
  addi r11, r1, 0xc0;
  bl _savegpr_14;
  mulli r0, r3, 0x538;
  lis r7, 0x4330;
  lis r6, 0x8034;
  stw r7, 0x50(r1);
  mr r27, r3;
  addi r6, r6, 0x57e0;
  stw r7, 0x58(r1);
  mr r28, r4;
  mr r14, r5;
  add r31, r6, r0;
  li r30, 0;
  bl WPADGetStatus;
  cmpwi r3, 3;
  beq lbl_801973d4;
  li r3, 0;
  b lbl_80197a94;
lbl_801973d4:
  bl OSDisableInterrupts;
  lbz r0, 0x51c(r31);
  mr r17, r3;
  cmpwi r0, 0;
  beq lbl_801973f4;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80197a94;
lbl_801973f4:
  li r16, 1;
  mr r3, r27;
  stb r16, 0x51c(r31);
  li r4, 0;
  bl WPADProbe;
  cmpwi r3, -1;
  mr r15, r3;
  bne lbl_80197468;
  lwz r0, 0x4d8(r31);
  cmpwi cr1, r0, 0;
  beq cr1, lbl_80197468;
  lbz r0, 0x522(r31);
  cmpwi r0, 0;
  beq lbl_80197468;
  lbz r0, 0x523(r31);
  cmpwi r0, 0;
  bne lbl_80197468;
  beq cr1, lbl_80197460;
  bne lbl_80197460;
  stb r16, 0x523(r31);
  mr r3, r27;
  li r4, 1;
  lwz r12, 0x4d8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, 0x522(r31);
lbl_80197460:
  li r0, 0;
  stb r0, 0x51f(r31);
lbl_80197468:
  mr r3, r17;
  bl OSRestoreInterrupts;
  lbz r0, 0x51d(r31);
  cmpwi r0, 0;
  beq lbl_80197488;
  stb r15, 0x5d(r31);
  mr r3, r31;
  bl reset_kpad;
lbl_80197488:
  lis r4, 0x8019;
  mr r3, r27;
  addi r4, r4, 0x7dd8;
  bl WPADSetSamplingCallback;
  lbz r0, 0x10f(r31);
  cmpwi r0, 0;
  beq lbl_80197a88;
  cmpwi r28, 0;
  beq lbl_80197a88;
  cmpwi r14, 0;
  beq lbl_80197a88;
  bl OSDisableInterrupts;
  lbz r29, 0x10f(r31);
  cmplw r29, r14;
  mr r30, r29;
  ble lbl_801974cc;
  mr r30, r14;
lbl_801974cc:
  li r4, 0;
  mr r0, r30;
  stb r4, 0x10f(r31);
  mulli r5, r30, 0x84;
  lbz r4, 0x10e(r31);
  add r5, r28, r5;
  subf. r6, r30, r4;
  bge lbl_801974f0;
  addi r6, r6, 0x10;
lbl_801974f0:
  addi r5, r5, -132;
  b lbl_801975f4;
lbl_801974f8:
  mulli r4, r6, 0x38;
  addi r6, r6, 1;
  cmpwi r6, 0x10;
  add r4, r31, r4;
  lhz r8, 0x110(r4);
  lhz r7, 0x112(r4);
  sth r8, -0x84(r5);
  sth r7, -0x82(r5);
  lhz r8, 0x114(r4);
  lhz r7, 0x116(r4);
  sth r8, -0x80(r5);
  sth r7, -0x7e(r5);
  lhz r8, 0x118(r4);
  lhz r7, 0x11a(r4);
  sth r8, -0x7c(r5);
  sth r7, -0x7a(r5);
  lhz r8, 0x11c(r4);
  lhz r7, 0x11e(r4);
  sth r8, -0x78(r5);
  sth r7, -0x76(r5);
  lhz r8, 0x120(r4);
  lhz r7, 0x122(r4);
  sth r8, -0x74(r5);
  sth r7, -0x72(r5);
  lhz r8, 0x124(r4);
  lhz r7, 0x126(r4);
  sth r8, -0x70(r5);
  sth r7, -0x6e(r5);
  lhz r8, 0x128(r4);
  lhz r7, 0x12a(r4);
  sth r8, -0x6c(r5);
  sth r7, -0x6a(r5);
  lhz r8, 0x12c(r4);
  lhz r7, 0x12e(r4);
  sth r8, -0x68(r5);
  sth r7, -0x66(r5);
  lhz r8, 0x130(r4);
  lhz r7, 0x132(r4);
  sth r8, -0x64(r5);
  sth r7, -0x62(r5);
  lhz r8, 0x134(r4);
  lhz r7, 0x136(r4);
  sth r8, -0x60(r5);
  sth r7, -0x5e(r5);
  lhz r8, 0x138(r4);
  lhz r7, 0x13a(r4);
  sth r8, -0x5c(r5);
  sth r7, -0x5a(r5);
  lhz r8, 0x13c(r4);
  lhz r7, 0x13e(r4);
  sth r8, -0x58(r5);
  sth r7, -0x56(r5);
  lhz r8, 0x140(r4);
  lhz r7, 0x142(r4);
  sth r8, -0x54(r5);
  sth r7, -0x52(r5);
  lhz r7, 0x144(r4);
  lhz r4, 0x146(r4);
  sth r7, -0x50(r5);
  sth r4, -0x4e(r5);
  addi r5, r5, -132;
  blt lbl_801975f4;
  li r6, 0;
lbl_801975f4:
  addic. r0, r0, -1;
  bne lbl_801974f8;
  mulli r0, r6, 0x38;
  add r16, r31, r0;
  lhz r15, 0x13a(r16);
  lhz r0, 0x136(r16);
  stw r15, 0x74(r1);
  lhz r15, 0x13c(r16);
  sth r0, 0x3e(r1);
  lwz r0, 0x74(r1);
  stw r15, 0x60(r1);
  lhz r15, 0x13e(r16);
  sth r0, 0x42(r1);
  lwz r0, 0x60(r1);
  stw r15, 0x64(r1);
  lhz r15, 0x140(r16);
  sth r0, 0x44(r1);
  lwz r0, 0x64(r1);
  stw r15, 0x68(r1);
  lhz r15, 0x142(r16);
  sth r0, 0x46(r1);
  lwz r0, 0x68(r1);
  stw r15, 0x6c(r1);
  lhz r15, 0x144(r16);
  sth r0, 0x48(r1);
  lwz r0, 0x6c(r1);
  stw r15, 0x70(r1);
  lhz r17, 0x110(r16);
  lhz r18, 0x112(r16);
  lhz r19, 0x114(r16);
  lhz r20, 0x116(r16);
  lhz r21, 0x118(r16);
  lhz r22, 0x11a(r16);
  lhz r23, 0x11c(r16);
  lhz r24, 0x11e(r16);
  lhz r25, 0x120(r16);
  lhz r26, 0x122(r16);
  lhz r12, 0x124(r16);
  lhz r11, 0x126(r16);
  lhz r10, 0x128(r16);
  lhz r9, 0x12a(r16);
  lhz r8, 0x12c(r16);
  lhz r7, 0x12e(r16);
  lhz r6, 0x130(r16);
  lhz r5, 0x132(r16);
  lhz r4, 0x134(r16);
  lhz r14, 0x138(r16);
  lhz r15, 0x146(r16);
  sth r0, 0x4a(r1);
  lwz r0, 0x70(r1);
  sth r17, 0x18(r1);
  sth r18, 0x1a(r1);
  sth r19, 0x1c(r1);
  sth r20, 0x1e(r1);
  sth r21, 0x20(r1);
  sth r22, 0x22(r1);
  sth r23, 0x24(r1);
  sth r24, 0x26(r1);
  sth r25, 0x28(r1);
  sth r26, 0x2a(r1);
  sth r12, 0x2c(r1);
  sth r11, 0x2e(r1);
  sth r10, 0x30(r1);
  sth r9, 0x32(r1);
  sth r8, 0x34(r1);
  sth r7, 0x36(r1);
  sth r6, 0x38(r1);
  sth r5, 0x3a(r1);
  sth r4, 0x3c(r1);
  sth r14, 0x40(r1);
  sth r0, 0x4c(r1);
  sth r15, 0x4e(r1);
  bl OSRestoreInterrupts;
  lhz r10, _unk_80388834;
  mr r3, r27;
  lhz r9, _unk_80388836;
  addi r5, r1, 0x10;
  lhz r8, _unk_80388838;
  li r4, 0;
  lhz r7, _unk_8038883c;
  lhz r6, _unk_8038883e;
  lhz r0, _unk_80388840;
  sth r10, 0x10(r1);
  sth r9, 0x12(r1);
  sth r8, 0x14(r1);
  sth r7, 8(r1);
  sth r6, 0xa(r1);
  sth r0, 0xc(r1);
  bl WPADGetAccGravityUnit;
  lha r5, 0x10(r1);
  lha r4, 0x14(r1);
  lha r3, 0x12(r1);
  mullw r0, r4, r5;
  mullw. r0, r0, r3;
  beq lbl_801977c4;
  xoris r0, r5, 0x8000;
  xoris r3, r3, 0x8000;
  stw r0, 0x54(r1);
  xoris r0, r4, 0x8000;
  lfd f4, _unk_80388820;
  lfd f0, 0x50(r1);
  stw r3, 0x5c(r1);
  fsubs f2, f0, f4;
  lfs f3, _unk_80388810;
  stw r0, 0x54(r1);
  lfd f1, 0x58(r1);
  lfd f0, 0x50(r1);
  fdivs f2, f3, f2;
  fsubs f1, f1, f4;
  stfs f2, 0x4dc(r31);
  fsubs f0, f0, f4;
  fdivs f1, f3, f1;
  fdivs f0, f3, f0;
  stfs f1, 0x4e0(r31);
  stfs f0, 0x4e4(r31);
  b lbl_801977d4;
lbl_801977c4:
  lfs f0, _unk_80388844;
  stfs f0, 0x4dc(r31);
  stfs f0, 0x4e0(r31);
  stfs f0, 0x4e4(r31);
lbl_801977d4:
  mr r3, r27;
  addi r5, r1, 8;
  li r4, 1;
  bl WPADGetAccGravityUnit;
  lha r5, 8(r1);
  lha r4, 0xc(r1);
  lha r3, 0xa(r1);
  mullw r0, r4, r5;
  mullw. r0, r0, r3;
  beq lbl_80197850;
  xoris r0, r5, 0x8000;
  xoris r3, r3, 0x8000;
  stw r0, 0x5c(r1);
  xoris r0, r4, 0x8000;
  lfd f4, _unk_80388820;
  lfd f0, 0x58(r1);
  stw r3, 0x54(r1);
  fsubs f2, f0, f4;
  lfs f3, _unk_80388810;
  stw r0, 0x5c(r1);
  lfd f1, 0x50(r1);
  lfd f0, 0x58(r1);
  fdivs f2, f3, f2;
  fsubs f1, f1, f4;
  stfs f2, 0x4e8(r31);
  fsubs f0, f0, f4;
  fdivs f1, f3, f1;
  fdivs f0, f3, f0;
  stfs f1, 0x4ec(r31);
  stfs f0, 0x4f0(r31);
  b lbl_80197860;
lbl_80197850:
  lfs f0, _unk_80388848;
  stfs f0, 0x4e8(r31);
  stfs f0, 0x4ec(r31);
  stfs f0, 0x4f0(r31);
lbl_80197860:
  mulli r0, r30, 0x84;
  lis r3, 1;
  mr r6, r30;
  addi r9, r3, -1;
  add r14, r28, r0;
  li r4, 0xfd;
  mr r8, r9;
  mr r7, r9;
  addi r5, r14, -132;
lbl_80197884:
  cmplwi r6, 1;
  addi r5, r5, -132;
  ble lbl_80197898;
  mr r3, r5;
  b lbl_8019789c;
lbl_80197898:
  addi r3, r1, 0x18;
lbl_8019789c:
  lbz r0, 0x29(r3);
  extsb r0, r0;
  cmpwi r0, -2;
  beq lbl_801978fc;
  bge lbl_801978bc;
  cmpwi r0, -7;
  beq lbl_801978fc;
  b lbl_80197900;
lbl_801978bc:
  cmpwi r0, 0;
  beq lbl_801978c8;
  b lbl_80197900;
lbl_801978c8:
  lbz r4, 0x28(r3);
  cmplwi r4, 1;
  bne lbl_801978e0;
  lhz r8, 0(r3);
  li r9, 0;
  b lbl_801978fc;
lbl_801978e0:
  cmplwi r4, 2;
  bne lbl_801978f4;
  lhz r9, 0x2a(r3);
  li r8, 0;
  b lbl_801978fc;
lbl_801978f4:
  li r9, 0;
  li r8, 0;
lbl_801978fc:
  lhz r7, 0(r3);
lbl_80197900:
  addic. r6, r6, -1;
  bne lbl_80197884;
  cmplwi r7, 0xffff;
  bne lbl_80197930;
lbl_80197910:
  mr r3, r28;
  mr r4, r31;
  li r5, 0x84;
  bl memcpy;
  addic. r30, r30, -1;
  addi r28, r28, 0x84;
  bne lbl_80197910;
  b lbl_80197a88;
lbl_80197930:
  cmplwi r8, 0xffff;
  bne lbl_8019793c;
  lwz r8, 0(r31);
lbl_8019793c:
  cmplwi r9, 0xffff;
  bne lbl_80197948;
  lwz r9, 0x60(r31);
lbl_80197948:
  andi. r0, r7, 0x9fff;
  lwz r3, 0(r31);
  rlwimi r0, r8, 0, 0x11, 0x12;
  cmplwi r4, 2;
  clrlwi r5, r3, 0x10;
  xor r3, r0, r5;
  stw r0, 0(r31);
  and r0, r3, r0;
  stw r0, 4(r31);
  and r0, r3, r5;
  stw r0, 8(r31);
  bne lbl_8019799c;
  lwz r3, 0x60(r31);
  clrlwi r0, r9, 0x10;
  clrlwi r5, r3, 0x10;
  stw r0, 0x60(r31);
  xor r3, r0, r5;
  and r0, r3, r0;
  stw r0, 0x64(r31);
  and r0, r3, r5;
  stw r0, 0x68(r31);
lbl_8019799c:
  mr r3, r31;
  mr r5, r29;
  bl calc_button_repeat;
  mr r15, r30;
  addi r14, r14, -132;
  li r18, 1;
  li r17, 0;
  li r16, 0x10;
lbl_801979bc:
  cmplwi r15, 1;
  addi r14, r14, -132;
  ble lbl_801979d0;
  mr r19, r14;
  b lbl_801979d4;
lbl_801979d0:
  addi r19, r1, 0x18;
lbl_801979d4:
  lbz r0, 0x29(r19);
  stb r0, 0x5d(r31);
  lbz r4, 0x28(r19);
  lbz r0, 0x5c(r31);
  cmplw r0, r4;
  beq lbl_80197a08;
  lbz r3, 0x29(r19);
  addi r0, r3, 2;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 2;
  bgt lbl_80197a08;
  stb r4, 0x5c(r31);
  stb r18, 0x51e(r31);
lbl_80197a08:
  lbz r0, 0x36(r19);
  stb r0, 0x5f(r31);
  lbz r0, 0x29(r19);
  extsb. r0, r0;
  beq lbl_80197a2c;
  bge lbl_80197a54;
  cmpwi r0, -7;
  beq lbl_80197a38;
  b lbl_80197a54;
lbl_80197a2c:
  mr r3, r31;
  mr r4, r19;
  bl read_kpad_stick;
lbl_80197a38:
  mr r3, r31;
  mr r4, r19;
  bl read_kpad_acc;
  mr r3, r31;
  mr r4, r19;
  bl read_kpad_dpd;
  b lbl_80197a58;
lbl_80197a54:
  stb r17, 0x5e(r31);
lbl_80197a58:
  addi r5, r14, 0x80;
  addi r4, r31, -4;
  mtctr r16;
lbl_80197a64:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_80197a64;
  lwz r0, 4(r4);
  addic. r15, r15, -1;
  stw r0, 4(r5);
  bne lbl_801979bc;
lbl_80197a88:
  li r0, 0;
  mr r3, r30;
  stb r0, 0x51c(r31);
lbl_80197a94:
  addi r11, r1, 0xc0;
  bl _restgpr_14;
  lwz r0, 0xc4(r1);
  mtlr r0;
  addi r1, r1, 0xc0;
  blr;
  // clang-format on
}

// Symbol: KPADInit
// PAL: 0x80197aac..0x80197da0
MARK_BINARY_BLOB(KPADInit, 0x80197aac, 0x80197da0);
asm UNKNOWN_FUNCTION(KPADInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stfd f31, 0x80(r1);
  psq_st f31, 136(r1), 0, 0;
  stfd f30, 0x70(r1);
  psq_st f30, 120(r1), 0, 0;
  stfd f29, 0x60(r1);
  psq_st f29, 104(r1), 0, 0;
  stfd f28, 0x50(r1);
  psq_st f28, 88(r1), 0, 0;
  stfd f27, 0x40(r1);
  psq_st f27, 72(r1), 0, 0;
  addi r11, r1, 0x40;
  bl _savegpr_23;
  bl WPADInit;
  lis r25, 0x8034;
  li r4, 0;
  addi r3, r25, 0x57e0;
  li r5, 0x14e0;
  bl memset;
  bl WPADGetDpdSensitivity;
  clrlwi r3, r3, 0x18;
  lis r0, 0x4330;
  stw r3, 0xc(r1);
  lis r3, 1;
  lis r29, 0x8034;
  addi r24, r25, 0x57e0;
  stw r0, 8(r1);
  addi r27, r3, -25536;
  lfd f1, _unk_80388850;
  addi r30, r29, 0x6cc0;
  lfd f0, 8(r1);
  li r23, 0;
  lfs f31, _unk_80388810;
  li r31, -1;
  fsubs f0, f0, f1;
  lfs f29, _unk_80388800;
  lfs f30, _unk_8038884c;
  li r26, 0;
  li r28, 1;
  li r25, 0xfd;
  fadds f0, f31, f0;
  stfs f0, _unk_803859c8;
lbl_80197b5c:
  stb r28, 0x520(r24);
  lfs f27, _unk_80388810;
  stb r26, 0x521(r24);
  lfs f28, _unk_80388818;
  fmuls f1, f27, f27;
  stb r25, 0x5c(r24);
  fmuls f0, f28, f28;
  lfs f2, _unk_8038599c;
  stb r26, 0x5f(r24);
  lwz r3, _unk_803859a0;
  stfs f2, 0xa4(r24);
  fadds f1, f1, f0;
  lwz r0, _unk_803859a4;
  stw r3, 0xa8(r24);
  lwz r3, _unk_803859a8;
  stw r0, 0xac(r24);
  lwz r0, _unk_803859ac;
  stw r3, 0xb0(r24);
  lwz r3, _unk_80386818;
  stw r0, 0xb4(r24);
  lwz r0, _unk_8038681c;
  stw r3, 0xb8(r24);
  stw r0, 0xbc(r24);
  bl sqrt;
  lfs f0, 0xb8(r24);
  frsp f1, f1;
  fcmpo cr0, f0, f29;
  bge lbl_80197bd4;
  fadds f27, f27, f0;
  b lbl_80197bd8;
lbl_80197bd4:
  fsubs f27, f27, f0;
lbl_80197bd8:
  lfs f0, 0xbc(r24);
  fcmpo cr0, f0, f29;
  bge lbl_80197bec;
  fadds f28, f28, f0;
  b lbl_80197bf0;
lbl_80197bec:
  fsubs f28, f28, f0;
lbl_80197bf0:
  fcmpo cr0, f27, f28;
  bge lbl_80197bfc;
  b lbl_80197c00;
lbl_80197bfc:
  fmr f27, f28;
lbl_80197c00:
  fdivs f1, f1, f27;
  lfs f0, _unk_80385a04;
  stfs f31, 0x6cc0(r29);
  stfs f29, 4(r30);
  stfs f29, 8(r30);
  stfs f29, 0xc(r30);
  stfs f1, 0xc0(r24);
  fmuls f1, f30, f0;
  stfs f29, 0x9c(r24);
  stfs f29, 0x94(r24);
  stfs f29, 0x8c(r24);
  stfs f29, 0x84(r24);
  stfs f31, 0xa0(r24);
  stfs f31, 0x98(r24);
  stfs f31, 0x90(r24);
  stfs f31, 0x88(r24);
  stw r26, 0x534(r24);
  stw r26, 0x530(r24);
  stw r26, 0x52c(r24);
  stw r26, 0x528(r24);
  sth r27, 0x4d0(r24);
  sth r26, 0x4d2(r24);
  sth r26, 0x4cc(r24);
  sth r27, 0x4ce(r24);
  sth r26, 0x4d4(r24);
  sth r27, 0x4d6(r24);
  stb r28, 0x524(r24);
  stb r28, 0x525(r24);
  stb r26, 0x526(r24);
  stfs f29, 0x10(r30);
  bl cos;
  frsp f2, f1;
  lfs f0, _unk_80385a04;
  fmuls f1, f30, f0;
  stfs f2, 0x14(r30);
  bl sin;
  fneg f2, f1;
  lfs f0, _unk_80385a04;
  stfs f29, 0x1c(r30);
  fmuls f1, f30, f0;
  frsp f0, f2;
  stfs f29, 0x20(r30);
  stfs f0, 0x18(r30);
  bl sin;
  frsp f2, f1;
  lfs f0, _unk_80385a04;
  fmuls f1, f30, f0;
  stfs f2, 0x24(r30);
  bl cos;
  frsp f0, f1;
  stfs f29, 0x2c(r30);
  mr r3, r24;
  li r4, 0;
  stfs f0, 0x28(r30);
lbl_80197cd8:
  addi r4, r4, 1;
  stb r31, 0x139(r3);
  cmplwi r4, 0x10;
  addi r3, r3, 0x38;
  blt lbl_80197cd8;
  addi r23, r23, 1;
  addi r24, r24, 0x538;
  cmpwi r23, 4;
  blt lbl_80197b5c;
  lfs f28, _unk_803859b0;
  bl OSDisableInterrupts;
  lfs f0, _unk_80388808;
  stfs f28, _unk_803859b0;
  fdivs f0, f28, f0;
  stfs f0, _unk_80386834;
  stfs f0, _unk_80386830;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  li r25, 3;
  addi r3, r3, 0x57e0;
  li r31, 1;
  addi r26, r3, 0xfa8;
lbl_80197d30:
  bl WPADGetStatus;
  cmpwi r3, 3;
  bne lbl_80197d48;
  mr r3, r25;
  li r4, 0;
  bl WPADControlMotor;
lbl_80197d48:
  addic. r25, r25, -1;
  stb r31, 0x51d(r26);
  addi r26, r26, -1336;
  bge lbl_80197d30;
  lwz r3, _unk_80385998;
  bl OSRegisterVersion;
  psq_l f31, 136(r1), 0, 0;
  lfd f31, 0x80(r1);
  psq_l f30, 120(r1), 0, 0;
  lfd f30, 0x70(r1);
  psq_l f29, 104(r1), 0, 0;
  lfd f29, 0x60(r1);
  psq_l f28, 88(r1), 0, 0;
  lfd f28, 0x50(r1);
  psq_l f27, 72(r1), 0, 0;
  addi r11, r1, 0x40;
  lfd f27, 0x40(r1);
  bl _restgpr_23;
  lwz r0, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: KPADDisableDPD
// PAL: 0x80197da0..0x80197dbc
MARK_BINARY_BLOB(KPADDisableDPD, 0x80197da0, 0x80197dbc);
asm UNKNOWN_FUNCTION(KPADDisableDPD) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  li r4, 0;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stb r4, 0x520(r3);
  blr;
  // clang-format on
}

// Symbol: KPADEnableDPD
// PAL: 0x80197dbc..0x80197dd8
MARK_BINARY_BLOB(KPADEnableDPD, 0x80197dbc, 0x80197dd8);
asm UNKNOWN_FUNCTION(KPADEnableDPD) {
  // clang-format off
  nofralloc;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  li r4, 1;
  addi r3, r3, 0x57e0;
  add r3, r3, r0;
  stb r4, 0x520(r3);
  blr;
  // clang-format on
}

// Symbol: KPADiSamplingCallback
// PAL: 0x80197dd8..0x801980b0
MARK_BINARY_BLOB(KPADiSamplingCallback, 0x80197dd8, 0x801980b0);
asm UNKNOWN_FUNCTION(KPADiSamplingCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stfd f31, 0x30(r1);
  psq_st f31, 56(r1), 0, 0;
  stfd f30, 0x20(r1);
  psq_st f30, 40(r1), 0, 0;
  lis r4, 0x8034;
  mulli r0, r3, 0x538;
  stw r31, 0x1c(r1);
  addi r4, r4, 0x57e0;
  stw r30, 0x18(r1);
  add r31, r4, r0;
  addi r4, r1, 8;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  bl WPADProbe;
  cmpwi r3, -1;
  beq lbl_80198068;
  lbz r28, 0x10e(r31);
  cmplwi r28, 0x10;
  blt lbl_80197e38;
  li r28, 0;
lbl_80197e38:
  mulli r0, r28, 0x38;
  mr r3, r29;
  add r4, r31, r0;
  addi r30, r4, 0x110;
  mr r4, r30;
  bl WPADRead;
  mr r3, r29;
  bl WPADGetDataFormat;
  stb r3, 0x36(r30);
  addi r0, r28, 1;
  stb r0, 0x10e(r31);
  lbz r3, 0x10f(r31);
  cmplwi r3, 0x10;
  bge lbl_80197e78;
  addi r0, r3, 1;
  stb r0, 0x10f(r31);
lbl_80197e78:
  lbz r0, 0x524(r31);
  cmpwi r0, 0;
  beq lbl_80197f38;
  lbz r0, 0x525(r31);
  cmpwi r0, 0;
  beq lbl_80197eb0;
  bl WPADGetSensorBarPosition;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bne lbl_80197ea8;
  lfs f0, _unk_80388858;
  b lbl_80197eb4;
lbl_80197ea8:
  lfs f0, _unk_8038885c;
  b lbl_80197eb4;
lbl_80197eb0:
  lfs f0, _unk_80388800;
lbl_80197eb4:
  lfs f30, _unk_80388810;
  fneg f2, f0;
  lfs f31, _unk_80388818;
  lfs f3, _unk_80388800;
  fmuls f1, f30, f30;
  fmuls f0, f31, f31;
  stfs f3, 0xb8(r31);
  fadds f1, f1, f0;
  stfs f2, 0xbc(r31);
  bl sqrt;
  lfs f2, 0xb8(r31);
  frsp f3, f1;
  lfs f0, _unk_80388800;
  fcmpo cr0, f2, f0;
  bge lbl_80197ef8;
  fadds f30, f30, f2;
  b lbl_80197efc;
lbl_80197ef8:
  fsubs f30, f30, f2;
lbl_80197efc:
  lfs f1, 0xbc(r31);
  lfs f0, _unk_80388800;
  fcmpo cr0, f1, f0;
  bge lbl_80197f14;
  fadds f31, f31, f1;
  b lbl_80197f18;
lbl_80197f14:
  fsubs f31, f31, f1;
lbl_80197f18:
  fcmpo cr0, f30, f31;
  bge lbl_80197f24;
  b lbl_80197f28;
lbl_80197f24:
  fmr f30, f31;
lbl_80197f28:
  fdivs f0, f3, f30;
  li r0, 0;
  stfs f0, 0xc0(r31);
  stb r0, 0x524(r31);
lbl_80197f38:
  lwz r0, 8(r1);
  cmpwi r0, 0xfb;
  bge lbl_80197f68;
  cmpwi r0, 1;
  beq lbl_80197f84;
  bge lbl_80197f5c;
  cmpwi r0, 0;
  bge lbl_80197f7c;
  b lbl_80198068;
lbl_80197f5c:
  cmpwi r0, 3;
  bge lbl_80198068;
  b lbl_80197f8c;
lbl_80197f68:
  cmpwi r0, 0xff;
  beq lbl_80197f7c;
  bge lbl_80198068;
  cmpwi r0, 0xfd;
  bge lbl_80198068;
lbl_80197f7c:
  li r28, 0;
  b lbl_80197f90;
lbl_80197f84:
  li r28, 2;
  b lbl_80197f90;
lbl_80197f8c:
  li r28, 4;
lbl_80197f90:
  lbz r0, 0x520(r31);
  cmpwi r0, 0;
  beq lbl_80197fa0;
  addi r28, r28, 1;
lbl_80197fa0:
  mr r3, r29;
  bl WPADIsDpdEnabled;
  cmpwi r3, 0;
  beq lbl_80197fb8;
  lbz r4, 0x521(r31);
  b lbl_80197fbc;
lbl_80197fb8:
  li r4, 0;
lbl_80197fbc:
  lis r3, 0x8029;
  slwi r0, r28, 1;
  addi r3, r3, -5660;
  add r28, r3, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_80198050;
  lwz r0, 0x4d8(r31);
  cmpwi r0, 0;
  beq lbl_80198014;
  lbz r0, 0x522(r31);
  cmpwi r0, 0;
  bne lbl_80198014;
  li r0, 1;
  mr r3, r29;
  stb r0, 0x522(r31);
  li r4, 0;
  lwz r12, 0x4d8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, 0x523(r31);
lbl_80198014:
  lbz r0, 0x51f(r31);
  cmpwi r0, 0;
  bne lbl_80198068;
  li r0, 1;
  lis r5, 0x801a;
  stb r0, 0x51f(r31);
  mr r3, r29;
  lbz r4, 0(r28);
  addi r5, r5, -32592;
  bl WPADControlDpd;
  cmpwi r3, 0;
  bne lbl_80198068;
  lbz r0, 0(r28);
  stb r0, 0x521(r31);
  b lbl_80198068;
lbl_80198050:
  lbz r4, 1(r28);
  lbz r0, 0x36(r30);
  cmplw r0, r4;
  beq lbl_80198068;
  mr r3, r29;
  bl WPADSetDataFormat;
lbl_80198068:
  lwz r12, 0x518(r31);
  cmpwi r12, 0;
  beq lbl_80198080;
  mr r3, r29;
  mtctr r12;
  bctrl;
lbl_80198080:
  psq_l f31, 56(r1), 0, 0;
  lfd f31, 0x30(r1);
  psq_l f30, 40(r1), 0, 0;
  lfd f30, 0x20(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x44(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: KPADiControlDpdCallback
// PAL: 0x801980b0..0x8019812c
MARK_BINARY_BLOB(KPADiControlDpdCallback, 0x801980b0, 0x8019812c);
asm UNKNOWN_FUNCTION(KPADiControlDpdCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  mulli r0, r3, 0x538;
  addi r5, r5, 0x57e0;
  stw r31, 0xc(r1);
  add r31, r5, r0;
  bne lbl_80198110;
  lwz r0, 0x4d8(r31);
  cmpwi r0, 0;
  beq lbl_80198110;
  lbz r0, 0x523(r31);
  cmpwi r0, 0;
  bne lbl_80198110;
  li r0, 1;
  li r4, 1;
  stb r0, 0x523(r31);
  lwz r12, 0x4d8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, 0x522(r31);
lbl_80198110:
  li r0, 0;
  stb r0, 0x51f(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: KPADGetUnifiedWpadStatus
// PAL: 0x8019812c..0x801981ec
MARK_BINARY_BLOB(KPADGetUnifiedWpadStatus, 0x8019812c, 0x801981ec);
asm UNKNOWN_FUNCTION(KPADGetUnifiedWpadStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mulli r0, r3, 0x538;
  lis r3, 0x8034;
  cmplwi r5, 0x10;
  addi r3, r3, 0x57e0;
  mr r25, r4;
  mr r26, r5;
  add r29, r3, r0;
  ble lbl_80198164;
  li r26, 0x10;
lbl_80198164:
  bl OSDisableInterrupts;
  lbz r27, 0x10e(r29);
  mr r28, r3;
  li r31, -4;
  b lbl_801981c0;
lbl_80198178:
  cmpwi r27, 0;
  li r30, 0xf;
  beq lbl_80198188;
  addi r30, r27, -1;
lbl_80198188:
  mr r27, r30;
  bl WPADGetStatus;
  cmpwi r3, 3;
  beq lbl_801981a4;
  mulli r0, r30, 0x38;
  add r3, r29, r0;
  stb r31, 0x139(r3);
lbl_801981a4:
  mulli r0, r30, 0x38;
  mr r3, r25;
  li r5, 0x38;
  add r4, r29, r0;
  addi r4, r4, 0x110;
  bl memcpy;
  addi r25, r25, 0x38;
lbl_801981c0:
  cmpwi r26, 0;
  addi r26, r26, -1;
  bne lbl_80198178;
  mr r3, r28;
  bl OSRestoreInterrupts;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
