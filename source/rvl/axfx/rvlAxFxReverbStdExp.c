#include "rvlAxFxReverbStdExp.h"

#include <string.h>
#include <math.h>

#include <rvl/os/osInterrupt.h>

#include "axfx.h"

const f32 unk_80388580 = 32000.0f;
const f32 unk_80388584 = 0.0f;
const f32 unk_80388588 = 1.0f;
const f32 unk_8038858c = 0.6f;
sdata2_ps_f32 unk_80388590 = {176.0f, -0.0f};
const f32 unk_80388598 = -0.33f;
const f32 unk_8038859c = 0.33f;
sdata2_ps_f32 unk_803885a0 = {-3.0f, 0.0f};
sdata2_ps_f32 unk_803885a8 = {2.5625f, 0.0f};
sdata2_ps_f32 unk_803885b0 = {0.95f, 0.0f};
sdata2_ps_f32 unk_803885b8 = {176.0f, 0.0f};

u32 AXFXReverbStdExp__EarlySizeTable[8] = {163, 317, 479,  641,
                                           797, 967, 1123, 1283};

u32 AXFXReverbStdExp__FilterSizeTable[7][4] = {
    {1789, 1999, 433, 149}, {149, 293, 251, 103},   {947, 1361, 433, 137},
    {1279, 1531, 509, 149}, {1531, 1847, 563, 179}, {1823, 2357, 571, 137},
    {1823, 2357, 571, 179}};

// Symbol: AXFXReverbStdExpGetMemSize
// PAL: 0x8012b47c..0x8012b4dc
MARK_BINARY_BLOB(AXFXReverbStdExpGetMemSize, 0x8012b47c, 0x8012b4dc);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpGetMemSize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lis r4, AXFXReverbStdExp__EarlySizeTable@ha;
  lis r6, AXFXReverbStdExp__FilterSizeTable@ha;
  lfs f1, unk_80388580;
  lfs f0, 0xb8(r3);
  la r6, AXFXReverbStdExp__FilterSizeTable@l(r6);
  la r4, AXFXReverbStdExp__EarlySizeTable@l(r4);
  lwz r5, 0x60(r6);
  fmuls f0, f1, f0;
  lwz r7, 0x1c(r4);
  lwz r4, 0x64(r6);
  lwz r3, 0x68(r6);
  fctiwz f0, f0;
  lwz r0, 0x6c(r6);
  stfd f0, 8(r1);
  lwz r6, 0xc(r1);
  add r6, r7, r6;
  add r6, r6, r5;
  add r6, r6, r4;
  add r6, r6, r3;
  add r6, r6, r0;
  mulli r3, r6, 0xc;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExpInit
// PAL: 0x8012b4dc..0x8012b658
MARK_BINARY_BLOB(AXFXReverbStdExpInit, 0x8012b4dc, 0x8012b658);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  bl OSDisableInterrupts;
  lfs f1, 0xb8(r30);
  li r0, 1;
  lfs f0, unk_80388584;
  mr r31, r3;
  stw r0, 0xb0(r30);
  fcmpo cr0, f1, f0;
  bge lbl_8012b54c;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0xb0(r30);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8012b63c;
lbl_8012b54c:
  lis r3, AXFXReverbStdExp__EarlySizeTable@ha;
  lfs f0, unk_80388580;
  la r3, AXFXReverbStdExp__EarlySizeTable@l(r3);
  lwz r0, 0x1c(r3);
  fmuls f1, f0, f1;
  stw r0, 0x14(r30);
  bl __cvt_fp2unsigned;
  stw r3, 0x30(r30);
  lis r4, AXFXReverbStdExp__FilterSizeTable@ha;
  la r4, AXFXReverbStdExp__FilterSizeTable@l(r4);
  mr r3, r30;
  lwz r0, 0x60(r4);
  stw r0, 0x5c(r30);
  lwz r0, 0x64(r4);
  stw r0, 0x60(r30);
  lwz r0, 0x68(r4);
  stw r0, 0x94(r30);
  lwz r0, 0x6c(r4);
  stw r0, 0x98(r30);
  bl AXFXReverbStdExp__AllocDelayLine;
  cmpwi r3, 0;
  bne lbl_8012b5d8;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0xb0(r30);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8012b63c;
lbl_8012b5d8:
  mr r3, r30;
  bl AXFXReverbStdExp__BzeroDelayLines;
  mr r3, r30;
  bl AXFXReverbStdExp__InitParams;
  cmpwi r3, 0;
  bne lbl_8012b624;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0xb0(r30);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8012b63c;
lbl_8012b624:
  lwz r0, 0xb0(r30);
  mr r3, r31;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0xb0(r30);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_8012b63c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExpSettings
// PAL: 0x8012b658..0x8012b728
MARK_BINARY_BLOB(AXFXReverbStdExpSettings, 0x8012b658, 0x8012b728);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpSettings) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r29);
  mr r30, r3;
  ori r0, r0, 1;
  stw r0, 0xb0(r29);
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0xb0(r29);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r29;
  bl AXFXReverbStdExpInit;
  cmpwi r3, 0;
  bne lbl_8012b6f0;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0xb0(r29);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8012b70c;
lbl_8012b6f0:
  lwz r0, 0xb0(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0xb0(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_8012b70c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExpSettingsUpdate
// PAL: 0x8012b728..0x8012b7dc
MARK_BINARY_BLOB(AXFXReverbStdExpSettingsUpdate, 0x8012b728, 0x8012b7dc);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpSettingsUpdate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r29);
  mr r30, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0xb0(r29);
  bl AXFXReverbStdExp__BzeroDelayLines;
  mr r3, r29;
  bl AXFXReverbStdExp__InitParams;
  cmpwi r3, 0;
  bne lbl_8012b7a4;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0xb0(r29);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8012b7c0;
lbl_8012b7a4:
  lwz r0, 0xb0(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0xb0(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_8012b7c0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExpShutdown
// PAL: 0x8012b7dc..0x8012b830
MARK_BINARY_BLOB(AXFXReverbStdExpShutdown, 0x8012b7dc, 0x8012b830);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpShutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, 0xb0(r30);
  mr r31, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0xb0(r30);
  bl AXFXReverbStdExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExpCallback
// PAL: 0x8012b830..0x8012bb9c
MARK_BINARY_BLOB(AXFXReverbStdExpCallback, 0x8012b830, 0x8012bb9c);
asm UNKNOWN_FUNCTION(AXFXReverbStdExpCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_24;
  lwz r0, 0xb0(r4);
  cmpwi r0, 0;
  beq lbl_8012b85c;
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0xb0(r4);
  b lbl_8012bb84;
lbl_8012b85c:
  lwz r7, 0xd8(r4);
  lwz r6, 0(r3);
  lwz r5, 4(r3);
  cmpwi r7, 0;
  lwz r0, 8(r3);
  stw r6, 0x20(r1);
  stw r5, 0x24(r1);
  stw r0, 0x28(r1);
  beq lbl_8012b898;
  lwz r5, 0(r7);
  lwz r3, 4(r7);
  lwz r0, 8(r7);
  stw r5, 0x14(r1);
  stw r3, 0x18(r1);
  stw r0, 0x1c(r1);
lbl_8012b898:
  lwz r6, 0xdc(r4);
  cmpwi r6, 0;
  beq lbl_8012b8bc;
  lwz r5, 0(r6);
  lwz r3, 4(r6);
  lwz r0, 8(r6);
  stw r5, 8(r1);
  stw r3, 0xc(r1);
  stw r0, 0x10(r1);
lbl_8012b8bc:
  lfs f2, unk_80388588;
  li r28, 0;
  lfs f0, 0xac(r4);
  lis r3, 0x4330;
  lfs f3, unk_8038858c;
  li r0, 0;
  lfs f1, 0xd0(r4);
  fsubs f5, f2, f0;
  lfs f2, 0xd4(r4);
  li r27, 3;
  fmuls f6, f3, f1;
  lfs f1, 0x18(r4);
  fmuls f7, f3, f2;
  lfs f2, 0x64(r4);
  lfs f3, 0x68(r4);
  lfs f4, 0x9c(r4);
  lfd f11, unk_80388590;
lbl_8012b900:
  lwz r10, 0xc(r4);
  mr r7, r4;
  lwz r11, 0x28(r4);
  mr r8, r4;
  lwz r12, 0x4c(r4);
  addi r5, r1, 0x14;
  lwz r26, 0x50(r4);
  addi r6, r1, 0x20;
  lwz r25, 0x84(r4);
  addi r9, r1, 8;
  lwz r24, 0x88(r4);
  slwi r10, r10, 2;
  slwi r11, r11, 2;
  slwi r12, r12, 2;
  slwi r31, r26, 2;
  slwi r30, r25, 2;
  slwi r29, r24, 2;
  mtctr r27;
lbl_8012b948:
  lwz r24, 0xd8(r4);
  cmpwi r24, 0;
  beq lbl_8012b988;
  lwz r25, 0(r5);
  lwz r26, 0(r6);
  lwz r24, 0(r25);
  addi r25, r25, 4;
  lwz r26, 0(r26);
  stw r3, 0x30(r1);
  add r24, r26, r24;
  xoris r24, r24, 0x8000;
  stw r25, 0(r5);
  stw r24, 0x34(r1);
  lfd f8, 0x30(r1);
  fsubs f9, f8, f11;
  b lbl_8012b9a4;
lbl_8012b988:
  lwz r24, 0(r6);
  stw r3, 0x38(r1);
  lwz r24, 0(r24);
  xoris r24, r24, 0x8000;
  stw r24, 0x3c(r1);
  lfd f8, 0x38(r1);
  fsubs f9, f8, f11;
lbl_8012b9a4:
  lwz r24, 0(r7);
  lfsx f10, r10, r24;
  fmuls f8, f10, f1;
  fadds f8, f9, f8;
  stfsx f8, r10, r24;
  lwz r24, 0x2c(r4);
  cmpwi r24, 0;
  beq lbl_8012b9d4;
  lwz r24, 0x1c(r7);
  lfsx f12, r11, r24;
  stfsx f9, r11, r24;
  b lbl_8012b9d8;
lbl_8012b9d4:
  fmr f12, f9;
lbl_8012b9d8:
  lwz r24, 0x34(r8);
  fmuls f10, f10, f6;
  lwz r26, 0(r6);
  lfsx f9, r12, r24;
  addi r25, r26, 4;
  fmuls f8, f9, f2;
  stw r25, 0(r6);
  fadds f8, f12, f8;
  stfsx f8, r12, r24;
  lwz r25, 0x38(r8);
  lfsx f13, r31, r25;
  fmuls f8, f13, f3;
  fadds f9, f9, f13;
  fadds f8, f12, f8;
  stfsx f8, r31, r25;
  lwz r24, 0x6c(r8);
  lfsx f12, r30, r24;
  fmuls f8, f12, f4;
  fadds f8, f9, f8;
  fmuls f9, f8, f4;
  stfsx f8, r30, r24;
  lfs f8, 0xa0(r7);
  fsubs f9, f12, f9;
  fmuls f8, f0, f8;
  fmuls f9, f5, f9;
  fadds f9, f9, f8;
  stfs f9, 0xa0(r7);
  lwz r25, 0x70(r8);
  lfsx f12, r29, r25;
  fmuls f8, f12, f4;
  fadds f8, f9, f8;
  fmuls f9, f8, f4;
  stfsx f8, r29, r25;
  lfs f8, 0xe0(r4);
  fsubs f9, f12, f9;
  fmuls f9, f9, f7;
  fadds f9, f10, f9;
  fmuls f8, f9, f8;
  fctiwz f8, f8;
  stfd f8, 0x38(r1);
  lwz r25, 0x3c(r1);
  stw r25, 0(r26);
  lwz r25, 0xdc(r4);
  cmpwi r25, 0;
  beq lbl_8012bab0;
  lfs f8, 0xe4(r4);
  lwz r25, 0(r9);
  fmuls f8, f9, f8;
  addi r26, r25, 4;
  stw r26, 0(r9);
  fctiwz f8, f8;
  stfd f8, 0x38(r1);
  lwz r26, 0x3c(r1);
  stw r26, 0(r25);
lbl_8012bab0:
  addi r5, r5, 4;
  addi r6, r6, 4;
  addi r7, r7, 4;
  addi r8, r8, 8;
  addi r9, r9, 4;
  bdnz lbl_8012b948;
  lwz r6, 0xc(r4);
  lwz r5, 0x10(r4);
  addi r6, r6, 1;
  cmplw r6, r5;
  stw r6, 0xc(r4);
  blt lbl_8012bae4;
  stw r0, 0xc(r4);
lbl_8012bae4:
  lwz r6, 0x2c(r4);
  cmpwi r6, 0;
  beq lbl_8012bb08;
  lwz r5, 0x28(r4);
  addi r5, r5, 1;
  cmplw r5, r6;
  stw r5, 0x28(r4);
  blt lbl_8012bb08;
  stw r0, 0x28(r4);
lbl_8012bb08:
  lwz r6, 0x4c(r4);
  lwz r5, 0x54(r4);
  addi r6, r6, 1;
  cmplw r6, r5;
  stw r6, 0x4c(r4);
  blt lbl_8012bb24;
  stw r0, 0x4c(r4);
lbl_8012bb24:
  lwz r6, 0x50(r4);
  lwz r5, 0x58(r4);
  addi r6, r6, 1;
  cmplw r6, r5;
  stw r6, 0x50(r4);
  blt lbl_8012bb40;
  stw r0, 0x50(r4);
lbl_8012bb40:
  lwz r6, 0x84(r4);
  lwz r5, 0x8c(r4);
  addi r6, r6, 1;
  cmplw r6, r5;
  stw r6, 0x84(r4);
  blt lbl_8012bb5c;
  stw r0, 0x84(r4);
lbl_8012bb5c:
  lwz r6, 0x88(r4);
  lwz r5, 0x90(r4);
  addi r6, r6, 1;
  cmplw r6, r5;
  stw r6, 0x88(r4);
  blt lbl_8012bb78;
  stw r0, 0x88(r4);
lbl_8012bb78:
  addi r28, r28, 1;
  cmplwi r28, 0x60;
  blt lbl_8012b900;
lbl_8012bb84:
  addi r11, r1, 0x60;
  bl _restgpr_24;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExp__AllocDelayLine
// PAL: 0x8012bb9c..0x8012bce0
MARK_BINARY_BLOB(AXFXReverbStdExp__AllocDelayLine, 0x8012bb9c, 0x8012bce0);
asm UNKNOWN_FUNCTION(AXFXReverbStdExp__AllocDelayLine) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r24, r3;
  li r25, 0;
  mr r30, r24;
  li r31, 0;
  mr r29, r24;
lbl_8012bbc4:
  lwz r0, 0x14(r24);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0(r30);
  bne lbl_8012bbec;
  li r3, 0;
  b lbl_8012bcc8;
lbl_8012bbec:
  lwz r0, 0x30(r24);
  cmpwi r0, 0;
  beq lbl_8012bc1c;
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x1c(r30);
  bne lbl_8012bc20;
  li r3, 0;
  b lbl_8012bcc8;
lbl_8012bc1c:
  stw r31, 0x1c(r30);
lbl_8012bc20:
  mr r27, r24;
  mr r28, r29;
  li r26, 0;
lbl_8012bc2c:
  lwz r0, 0x5c(r27);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x34(r28);
  bne lbl_8012bc54;
  li r3, 0;
  b lbl_8012bcc8;
lbl_8012bc54:
  addi r26, r26, 1;
  addi r28, r28, 4;
  cmplwi r26, 2;
  addi r27, r27, 4;
  blt lbl_8012bc2c;
  mr r28, r24;
  mr r27, r29;
  li r26, 0;
lbl_8012bc74:
  lwz r0, 0x94(r28);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x6c(r27);
  bne lbl_8012bc9c;
  li r3, 0;
  b lbl_8012bcc8;
lbl_8012bc9c:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 2;
  addi r28, r28, 4;
  blt lbl_8012bc74;
  addi r25, r25, 1;
  addi r29, r29, 8;
  cmplwi r25, 3;
  addi r30, r30, 4;
  blt lbl_8012bbc4;
  li r3, 1;
lbl_8012bcc8:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExp__BzeroDelayLines
// PAL: 0x8012bce0..0x8012bde0
MARK_BINARY_BLOB(AXFXReverbStdExp__BzeroDelayLines, 0x8012bce0, 0x8012bde0);
asm UNKNOWN_FUNCTION(AXFXReverbStdExp__BzeroDelayLines) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r25, r3;
  li r26, 0;
  mr r31, r25;
  mr r30, r25;
lbl_8012bd04:
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_8012bd20;
  lwz r0, 0x14(r25);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_8012bd20:
  lwz r3, 0x1c(r31);
  cmpwi r3, 0;
  beq lbl_8012bd3c;
  lwz r0, 0x30(r25);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_8012bd3c:
  mr r28, r30;
  mr r29, r25;
  li r27, 0;
lbl_8012bd48:
  lwz r3, 0x34(r28);
  cmpwi r3, 0;
  beq lbl_8012bd64;
  lwz r0, 0x5c(r29);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_8012bd64:
  addi r27, r27, 1;
  addi r29, r29, 4;
  cmplwi r27, 2;
  addi r28, r28, 4;
  blt lbl_8012bd48;
  mr r29, r30;
  mr r28, r25;
  li r27, 0;
lbl_8012bd84:
  lwz r3, 0x6c(r29);
  cmpwi r3, 0;
  beq lbl_8012bda0;
  lwz r0, 0x94(r28);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_8012bda0:
  addi r27, r27, 1;
  addi r28, r28, 4;
  cmplwi r27, 2;
  addi r29, r29, 4;
  blt lbl_8012bd84;
  addi r26, r26, 1;
  addi r30, r30, 8;
  cmplwi r26, 3;
  addi r31, r31, 4;
  blt lbl_8012bd04;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExp__FreeDelayLine
// PAL: 0x8012bde0..0x8012bed0
MARK_BINARY_BLOB(AXFXReverbStdExp__FreeDelayLine, 0x8012bde0, 0x8012bed0);
asm UNKNOWN_FUNCTION(AXFXReverbStdExp__FreeDelayLine) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  li r26, 0;
  mr r30, r3;
  li r31, 0;
  mr r29, r3;
lbl_8012be04:
  lwz r3, 0(r30);
  cmpwi r3, 0;
  beq lbl_8012be20;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0(r30);
lbl_8012be20:
  lwz r3, 0x1c(r30);
  cmpwi r3, 0;
  beq lbl_8012be3c;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x1c(r30);
lbl_8012be3c:
  mr r28, r29;
  li r27, 0;
lbl_8012be44:
  lwz r3, 0x34(r28);
  cmpwi r3, 0;
  beq lbl_8012be60;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x34(r28);
lbl_8012be60:
  addi r27, r27, 1;
  addi r28, r28, 4;
  cmplwi r27, 2;
  blt lbl_8012be44;
  mr r28, r29;
  li r27, 0;
lbl_8012be78:
  lwz r3, 0x6c(r28);
  cmpwi r3, 0;
  beq lbl_8012be94;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x6c(r28);
lbl_8012be94:
  addi r27, r27, 1;
  addi r28, r28, 4;
  cmplwi r27, 2;
  blt lbl_8012be78;
  addi r26, r26, 1;
  addi r29, r29, 8;
  cmplwi r26, 3;
  addi r30, r30, 4;
  blt lbl_8012be04;
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbStdExp__InitParams
// PAL: 0x8012bed0..0x8012c17c
MARK_BINARY_BLOB(AXFXReverbStdExp__InitParams, 0x8012bed0, 0x8012c17c);
asm UNKNOWN_FUNCTION(AXFXReverbStdExp__InitParams) {
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
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lwz r5, 0xb4(r3);
  mr r31, r3;
  cmplwi r5, 8;
  blt lbl_8012bf14;
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf14:
  lfs f1, 0xbc(r3);
  lfs f2, unk_80388584;
  fcmpo cr0, f1, f2;
  blt lbl_8012bf30;
  lfs f0, 0xb8(r3);
  fcmpo cr0, f1, f0;
  ble lbl_8012bf38;
lbl_8012bf30:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf38:
  lwz r0, 0xc0(r3);
  cmplwi r0, 6;
  blt lbl_8012bf4c;
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf4c:
  lfs f0, 0xc4(r3);
  fcmpo cr0, f0, f2;
  bge lbl_8012bf60;
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf60:
  lfs f0, 0xc8(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012bf78;
  lfs f1, unk_80388588;
  fcmpo cr0, f0, f1;
  ble lbl_8012bf80;
lbl_8012bf78:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf80:
  lfs f0, 0xcc(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012bf94;
  fcmpo cr0, f0, f1;
  ble lbl_8012bf9c;
lbl_8012bf94:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bf9c:
  lfs f0, 0xd0(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012bfb0;
  fcmpo cr0, f0, f1;
  ble lbl_8012bfb8;
lbl_8012bfb0:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bfb8:
  lfs f0, 0xd4(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012bfcc;
  fcmpo cr0, f0, f1;
  ble lbl_8012bfd4;
lbl_8012bfcc:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bfd4:
  lfs f0, 0xe0(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012bfe8;
  fcmpo cr0, f0, f1;
  ble lbl_8012bff0;
lbl_8012bfe8:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012bff0:
  lfs f0, 0xe4(r3);
  fcmpo cr0, f0, f2;
  blt lbl_8012c004;
  fcmpo cr0, f0, f1;
  ble lbl_8012c00c;
lbl_8012c004:
  li r3, 0;
  b lbl_8012c14c;
lbl_8012c00c:
  li r0, 0;
  lis r4, AXFXReverbStdExp__EarlySizeTable@ha;
  stw r0, 0xc(r3);
  slwi r0, r5, 2;
  la r4, AXFXReverbStdExp__EarlySizeTable@l(r4);
  cmplwi r5, 3;
  lwzx r0, r4, r0;
  stw r0, 0x10(r3);
  bgt lbl_8012c03c;
  lfs f0, unk_80388598;
  stfs f0, 0x18(r3);
  b lbl_8012c044;
lbl_8012c03c:
  lfs f0, unk_8038859c;
  stfs f0, 0x18(r3);
lbl_8012c044:
  lfs f1, unk_80388580;
  li r28, 0;
  lfs f0, 0xbc(r3);
  stw r28, 0x28(r3);
  fmuls f1, f1, f0;
  bl __cvt_fp2unsigned;
  lis r29, 0x8028;
  stw r3, 0x2c(r31);
  lfd f29, unk_803885b8;
  mr r27, r31;
  lfs f30, unk_803885a0;
  addi r29, r29, 0x1ba0;
  lfs f31, unk_80388580;
  li r25, 0;
  li r26, 0;
  lis r30, 0x4330;
lbl_8012c084:
  stw r28, 0x4c(r27);
  lfd f1, unk_803885a8;
  lwz r0, 0xc0(r31);
  stw r30, 8(r1);
  slwi r0, r0, 4;
  add r0, r26, r0;
  lwzx r0, r29, r0;
  stw r0, 0xc(r1);
  lfd f0, 8(r1);
  stw r0, 0x54(r27);
  fsubs f2, f0, f29;
  lfs f0, 0xc4(r31);
  fmuls f2, f30, f2;
  fmuls f0, f31, f0;
  fdivs f2, f2, f0;
  bl pow;
  frsp f0, f1;
  addi r25, r25, 1;
  cmplwi r25, 2;
  addi r26, r26, 4;
  stfs f0, 0x64(r27);
  addi r27, r27, 4;
  blt lbl_8012c084;
  lwz r0, 0xc0(r31);
  li r4, 0;
  lis r3, AXFXReverbStdExp__FilterSizeTable@ha;
  stw r4, 0x84(r31);
  la r3, AXFXReverbStdExp__FilterSizeTable@l(r3);
  slwi r0, r0, 4;
  add r3, r3, r0;
  lfs f1, unk_80388588;
  lwz r0, 8(r3);
  lfs f0, 0xcc(r31);
  stw r0, 0x8c(r31);
  fsubs f1, f1, f0;
  lfs f0, unk_803885b0;
  stw r4, 0x88(r31);
  lfs f2, 0xc8(r31);
  lwz r0, 0xc(r3);
  fcmpo cr0, f1, f0;
  stw r0, 0x90(r31);
  stfs f2, 0x9c(r31);
  stfs f1, 0xac(r31);
  ble lbl_8012c138;
  stfs f0, 0xac(r31);
lbl_8012c138:
  lfs f0, unk_80388584;
  li r3, 1;
  stfs f0, 0xa0(r31);
  stfs f0, 0xa4(r31);
  stfs f0, 0xa8(r31);
lbl_8012c14c:
  psq_l f31, 88(r1), 0, 0;
  lfd f31, 0x50(r1);
  psq_l f30, 72(r1), 0, 0;
  lfd f30, 0x40(r1);
  psq_l f29, 56(r1), 0, 0;
  addi r11, r1, 0x30;
  lfd f29, 0x30(r1);
  bl _restgpr_25;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}
