#include "fxReverbHiExpDpl2.h"

#include <string.h>
#include <math.h>

#include <rvl/ax/cl.h>
#include <rvl/os/osInterrupt.h>

#include "axfx.h"

const f32 unk_80388510 = 32000.0f;
const f32 unk_80388514 = 0.0f;
const f32 unk_80388518 = 1.0f;
const f32 unk_8038851c = 0.6f;
sdata2_ps_f32 unk_80388520 = {0.333333f, 0.0f};
sdata2_ps_f32 unk_80388528 = {176.0f, -0.0f};
sdata2_ps_f32 unk_80388530 = {-3.0f, 0.0f};
sdata2_ps_f32 unk_80388538 = {2.5625f, 0.0f};
sdata2_ps_f32 unk_80388540 = {0.95f, 0.0f};
sdata2_ps_f32 unk_80388548 = {176.0f, 0.0f};

u32 AXFXReverbHiExpDpl2__EarlySizeTable[8][3] = {
    {157, 479, 829},    {317, 809, 1117},  {479, 941, 1487},
    {641, 1259, 1949},  {797, 1667, 2579}, {967, 1901, 2903},
    {1123, 2179, 3413}, {1279, 2477, 3889}};

f32 AXFXReverbHiExpDpl2__EarlyCoefTable[8][3] = {
    {0.4f, -1.0f, 0.3f},   {0.5f, -0.95f, 0.3f}, {0.6f, -0.9f, 0.3f},
    {0.75f, -0.85f, 0.3f}, {-0.9f, 0.8f, 0.3f},  {-1.0f, 0.7f, 0.3f},
    {-1.0f, 0.7f, 0.3f},   {-1.0f, 0.7f, 0.3f}};

u32 AXFXReverbHiExpDpl2__FilterSizeTable[7][9] = {
    {1789, 1999, 2333, 433, 149, 47, 73, 67, 71},
    {149, 293, 449, 251, 103, 47, 73, 67, 71},
    {947, 1361, 1531, 433, 137, 47, 73, 67, 71},
    {1279, 1531, 1973, 509, 149, 47, 73, 67, 71},
    {1531, 1847, 2297, 563, 179, 47, 73, 67, 71},
    {1823, 2357, 2693, 571, 137, 47, 73, 67, 71},
    {1823, 2357, 2693, 571, 179, 47, 73, 67, 71}};

// Symbol: AXFXReverbHiExpGetMemSizeDpl2
// PAL: 0x801290a0..0x8012912c
MARK_BINARY_BLOB(AXFXReverbHiExpGetMemSizeDpl2, 0x801290a0, 0x8012912c);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpGetMemSizeDpl2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lis r4, AXFXReverbHiExpDpl2__EarlySizeTable@ha;
  la r4, AXFXReverbHiExpDpl2__EarlySizeTable@l(r4);
  lis r9, AXFXReverbHiExpDpl2__FilterSizeTable@ha;
  lfs f1, unk_80388510;
  la r9, AXFXReverbHiExpDpl2__FilterSizeTable@l(r9);
  lfs f0, 0x144(r3);
  lwz r10, 0x5c(r4);
  fmuls f0, f1, f0;
  lwz r3, 0xd8(r9);
  lwz r0, 0xdc(r9);
  lwz r8, 0xe0(r9);
  fctiwz f0, f0;
  lwz r7, 0xe4(r9);
  lwz r6, 0xe8(r9);
  lwz r5, 0xec(r9);
  stfd f0, 8(r1);
  lwz r4, 0xc(r1);
  add r10, r10, r4;
  lwz r4, 0xf0(r9);
  add r10, r10, r3;
  lwz r3, 0xf4(r9);
  add r10, r10, r0;
  lwz r0, 0xf8(r9);
  add r10, r10, r8;
  add r10, r10, r7;
  add r10, r10, r6;
  slwi r10, r10, 2;
  add r10, r10, r5;
  add r10, r10, r4;
  add r10, r10, r3;
  add r10, r10, r0;
  slwi r3, r10, 2;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpInitDpl2
// PAL: 0x8012912c..0x801292ec
MARK_BINARY_BLOB(AXFXReverbHiExpInitDpl2, 0x8012912c, 0x801292ec);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpInitDpl2) {
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
  mr r31, r3;
  bl AXGetMode;
  cmplwi r3, 2;
  beq lbl_8012916c;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801292d0;
lbl_8012916c:
  lfs f1, 0x144(r30);
  li r0, 1;
  lfs f0, unk_80388514;
  stw r0, 0x13c(r30);
  fcmpo cr0, f1, f0;
  bge lbl_801291b8;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x13c(r30);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801292d0;
lbl_801291b8:
  lis r3, AXFXReverbHiExpDpl2__EarlySizeTable@ha;
  lfs f0, unk_80388510;
  la r3, AXFXReverbHiExpDpl2__EarlySizeTable@l(r3);
  lwz r0, 0x5c(r3);
  fmuls f1, f0, f1;
  stw r0, 0x20(r30);
  bl __cvt_fp2unsigned;
  stw r3, 0x48(r30);
  lis r4, AXFXReverbHiExpDpl2__FilterSizeTable@ha;
  la r4, AXFXReverbHiExpDpl2__FilterSizeTable@l(r4);
  mr r3, r30;
  lwz r0, 0xd8(r4);
  stw r0, 0x94(r30);
  lwz r0, 0xdc(r4);
  stw r0, 0x98(r30);
  lwz r0, 0xe0(r4);
  stw r0, 0x9c(r30);
  lwz r0, 0xe4(r4);
  stw r0, 0xdc(r30);
  lwz r0, 0xe8(r4);
  stw r0, 0xe0(r30);
  lwz r0, 0xec(r4);
  stw r0, 0x114(r30);
  lwz r0, 0xf0(r4);
  stw r0, 0x118(r30);
  lwz r0, 0xf4(r4);
  stw r0, 0x11c(r30);
  lwz r0, 0xf8(r4);
  stw r0, 0x120(r30);
  bl AXFXReverbHiExpDpl2__AllocDelayLine;
  cmpwi r3, 0;
  bne lbl_8012926c;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x13c(r30);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801292d0;
lbl_8012926c:
  mr r3, r30;
  bl AXFXReverbHiExpDpl2__BzeroDelayLines;
  mr r3, r30;
  bl AXFXReverbHiExpDpl2__InitParams;
  cmpwi r3, 0;
  bne lbl_801292b8;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x13c(r30);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801292d0;
lbl_801292b8:
  lwz r0, 0x13c(r30);
  mr r3, r31;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x13c(r30);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801292d0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpSettingsDpl2
// PAL: 0x801292ec..0x801293bc
MARK_BINARY_BLOB(AXFXReverbHiExpSettingsDpl2, 0x801292ec, 0x801293bc);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsDpl2) {
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
  lwz r0, 0x13c(r29);
  mr r30, r3;
  ori r0, r0, 1;
  stw r0, 0x13c(r29);
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x13c(r29);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r29;
  bl AXFXReverbHiExpInitDpl2;
  cmpwi r3, 0;
  bne lbl_80129384;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x13c(r29);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801293a0;
lbl_80129384:
  lwz r0, 0x13c(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x13c(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801293a0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpSettingsUpdateDpl2
// PAL: 0x801293bc..0x80129470
MARK_BINARY_BLOB(AXFXReverbHiExpSettingsUpdateDpl2, 0x801293bc, 0x80129470);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsUpdateDpl2) {
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
  lwz r0, 0x13c(r29);
  mr r30, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x13c(r29);
  bl AXFXReverbHiExpDpl2__BzeroDelayLines;
  mr r3, r29;
  bl AXFXReverbHiExpDpl2__InitParams;
  cmpwi r3, 0;
  bne lbl_80129438;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x13c(r29);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80129454;
lbl_80129438:
  lwz r0, 0x13c(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x13c(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80129454:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpShutdownDpl2
// PAL: 0x80129470..0x801294c4
MARK_BINARY_BLOB(AXFXReverbHiExpShutdownDpl2, 0x80129470, 0x801294c4);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpShutdownDpl2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, 0x13c(r30);
  mr r31, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x13c(r30);
  bl AXFXReverbHiExpDpl2__FreeDelayLine;
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

// Symbol: AXFXReverbHiExpCallbackDpl2
// PAL: 0x801294c4..0x80129a74
MARK_BINARY_BLOB(AXFXReverbHiExpCallbackDpl2, 0x801294c4, 0x80129a74);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpCallbackDpl2) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  stfd f31, 0xa0(r1);
  psq_st f31, 168(r1), 0, 0;
  stfd f30, 0x90(r1);
  psq_st f30, 152(r1), 0, 0;
  addi r11, r1, 0x90;
  bl _savegpr_24;
  lwz r0, 0x13c(r4);
  cmpwi r0, 0;
  beq lbl_80129500;
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0x13c(r4);
  b lbl_80129a4c;
lbl_80129500:
  lwz r8, 0x168(r4);
  lwz r7, 0(r3);
  lwz r6, 4(r3);
  cmpwi r8, 0;
  lwz r5, 8(r3);
  lwz r0, 0xc(r3);
  stw r7, 0x38(r1);
  stw r6, 0x3c(r1);
  stw r5, 0x40(r1);
  stw r0, 0x44(r1);
  beq lbl_8012954c;
  lwz r6, 0(r8);
  lwz r5, 4(r8);
  lwz r3, 8(r8);
  lwz r0, 0xc(r8);
  stw r6, 8(r1);
  stw r5, 0xc(r1);
  stw r3, 0x10(r1);
  stw r0, 0x14(r1);
lbl_8012954c:
  lwz r8, 0x16c(r4);
  cmpwi r8, 0;
  beq lbl_80129568;
  lwz r3, 0(r8);
  lwz r5, 4(r8);
  lwz r6, 8(r8);
  lwz r7, 0xc(r8);
lbl_80129568:
  lfs f0, unk_80388518;
  li r30, 0;
  lfs f1, 0x138(r4);
  li r28, 0;
  lfs f5, unk_8038851c;
  lis r0, 0x4330;
  lfs f3, 0x164(r4);
  fsubs f4, f0, f1;
  lfs f2, unk_80388520;
  li r29, 4;
  lfs f0, 0x15c(r4);
  fmuls f5, f5, f3;
  lfs f3, 0x124(r4);
  fmuls f6, f2, f0;
  lfd f0, unk_80388528;
lbl_801295a4:
  mr r10, r4;
  mr r11, r4;
  mr r12, r4;
  addi r8, r1, 8;
  addi r9, r1, 0x38;
  addi r31, r1, 0x18;
  mtctr r29;
lbl_801295c0:
  lwz r25, 0x168(r4);
  cmpwi r25, 0;
  beq lbl_80129600;
  lwz r26, 0(r8);
  lwz r27, 0(r9);
  lwz r25, 0(r26);
  addi r26, r26, 4;
  lwz r27, 0(r27);
  stw r0, 0x48(r1);
  add r25, r27, r25;
  xoris r25, r25, 0x8000;
  stw r26, 0(r8);
  stw r25, 0x4c(r1);
  lfd f2, 0x48(r1);
  fsubs f11, f2, f0;
  b lbl_8012961c;
lbl_80129600:
  lwz r25, 0(r9);
  stw r0, 0x50(r1);
  lwz r25, 0(r25);
  xoris r25, r25, 0x8000;
  stw r25, 0x54(r1);
  lfd f2, 0x50(r1);
  fsubs f11, f2, f0;
lbl_8012961c:
  lwz r27, 0x10(r4);
  lwz r26, 0x14(r4);
  lwz r25, 0x18(r4);
  slwi r27, r27, 2;
  lwz r24, 0(r10);
  slwi r26, r26, 2;
  lfs f9, 0x24(r4);
  slwi r25, r25, 2;
  lfsx f8, r24, r27;
  lfs f7, 0x28(r4);
  lfsx f2, r24, r26;
  fmuls f8, f9, f8;
  lfs f10, 0x2c(r4);
  lfsx f9, r24, r25;
  fmuls f2, f7, f2;
  stfsx f11, r24, r25;
  fmuls f7, f10, f9;
  fadds f2, f8, f2;
  lwz r26, 0x44(r4);
  cmpwi r26, 0;
  fadds f2, f7, f2;
  beq lbl_8012968c;
  lwz r26, 0x40(r4);
  lwz r27, 0x30(r10);
  slwi r26, r26, 2;
  lfsx f9, r27, r26;
  stfsx f11, r27, r26;
  b lbl_80129690;
lbl_8012968c:
  fmr f9, f11;
lbl_80129690:
  lwz r26, 0x7c(r4);
  lwz r24, 0x4c(r11);
  slwi r26, r26, 2;
  lfs f7, 0xa0(r4);
  lfsx f8, r24, r26;
  lfs f10, unk_80388514;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r24, r26;
  lwz r26, 0x80(r4);
  lwz r25, 0x50(r11);
  slwi r26, r26, 2;
  lfs f7, 0xa4(r4);
  lfsx f8, r25, r26;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r25, r26;
  lwz r26, 0x84(r4);
  lwz r27, 0x54(r11);
  slwi r26, r26, 2;
  lfs f7, 0xa8(r4);
  lfsx f8, r27, r26;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r27, r26;
  lwz r26, 0xcc(r4);
  lwz r24, 0xac(r12);
  slwi r26, r26, 2;
  lfsx f8, r24, r26;
  fmuls f7, f8, f3;
  fadds f7, f10, f7;
  stfsx f7, r24, r26;
  fmuls f7, f7, f3;
  lwz r26, 0xd0(r4);
  lwz r25, 0xb0(r12);
  fsubs f8, f8, f7;
  slwi r26, r26, 2;
  lfsx f9, r25, r26;
  fmuls f7, f9, f3;
  fadds f7, f8, f7;
  fmuls f8, f7, f3;
  stfsx f7, r25, r26;
  lfs f7, 0x128(r10);
  fsubs f8, f9, f8;
  fmuls f7, f1, f7;
  fmuls f8, f4, f8;
  fadds f9, f8, f7;
  stfs f9, 0x128(r10);
  lwz r26, 0xf4(r10);
  lwz r27, 0xe4(r10);
  slwi r26, r26, 2;
  lfsx f8, r27, r26;
  fmuls f7, f8, f3;
  fadds f7, f9, f7;
  stfsx f7, r27, r26;
  fmuls f7, f7, f3;
  lwz r26, 0xf4(r10);
  fsubs f7, f8, f7;
  addi r27, r26, 1;
  stw r27, 0xf4(r10);
  lwz r26, 0x104(r10);
  stfs f7, 0(r31);
  cmplw r27, r26;
  blt lbl_801297a0;
  stw r28, 0xf4(r10);
lbl_801297a0:
  lfs f7, 0(r31);
  addi r8, r8, 4;
  addi r9, r9, 4;
  addi r10, r10, 4;
  fmuls f7, f7, f5;
  addi r11, r11, 0xc;
  addi r12, r12, 8;
  fadds f2, f7, f2;
  stfs f2, 0(r31);
  addi r31, r31, 4;
  bdnz lbl_801295c0;
  lfs f31, 0x1c(r1);
  lfs f13, 0x20(r1);
  lfs f10, 0x18(r1);
  fadds f7, f31, f13;
  lfs f12, 0x24(r1);
  fadds f2, f10, f13;
  lwz r26, 0x38(r1);
  fadds f11, f10, f31;
  lwz r9, 0x44(r1);
  fadds f7, f12, f7;
  addi r27, r26, 4;
  fadds f8, f12, f2;
  addi r8, r9, 4;
  lwz r31, 0x3c(r1);
  fadds f30, f12, f11;
  fmuls f9, f7, f6;
  lwz r11, 0x40(r1);
  lfs f2, 0x170(r4);
  addi r12, r31, 4;
  addi r10, r11, 4;
  fmuls f8, f8, f6;
  fadds f10, f10, f9;
  stw r27, 0x38(r1);
  fadds f9, f31, f8;
  fmuls f7, f30, f6;
  stw r8, 0x44(r1);
  fmuls f2, f10, f2;
  stfs f10, 0x28(r1);
  fadds f8, f13, f7;
  fctiwz f2, f2;
  stfs f9, 0x2c(r1);
  fadds f7, f13, f11;
  stfs f8, 0x30(r1);
  stfd f2, 0x50(r1);
  fmuls f7, f7, f6;
  lwz r27, 0x54(r1);
  fadds f7, f12, f7;
  stw r12, 0x3c(r1);
  stw r27, 0(r26);
  lfs f2, 0x170(r4);
  stfs f7, 0x34(r1);
  fmuls f2, f9, f2;
  stw r10, 0x40(r1);
  fctiwz f2, f2;
  stfd f2, 0x48(r1);
  lwz r8, 0x4c(r1);
  stw r8, 0(r31);
  lfs f2, 0x170(r4);
  fmuls f2, f8, f2;
  fctiwz f2, f2;
  stfd f2, 0x58(r1);
  lwz r8, 0x5c(r1);
  stw r8, 0(r11);
  lfs f2, 0x170(r4);
  fmuls f2, f7, f2;
  fctiwz f2, f2;
  stfd f2, 0x60(r1);
  lwz r8, 0x64(r1);
  stw r8, 0(r9);
  lwz r8, 0x16c(r4);
  cmpwi r8, 0;
  beq lbl_80129934;
  lfs f2, 0x174(r4);
  fmuls f2, f10, f2;
  fctiwz f2, f2;
  stfd f2, 0x60(r1);
  lwz r8, 0x64(r1);
  stw r8, 0(r3);
  addi r3, r3, 4;
  lfs f2, 0x174(r4);
  fmuls f2, f9, f2;
  fctiwz f2, f2;
  stfd f2, 0x58(r1);
  lwz r8, 0x5c(r1);
  stw r8, 0(r5);
  addi r5, r5, 4;
  lfs f2, 0x174(r4);
  fmuls f2, f8, f2;
  fctiwz f2, f2;
  stfd f2, 0x50(r1);
  lwz r8, 0x54(r1);
  stw r8, 0(r6);
  addi r6, r6, 4;
  lfs f2, 0x174(r4);
  fmuls f2, f7, f2;
  fctiwz f2, f2;
  stfd f2, 0x48(r1);
  lwz r8, 0x4c(r1);
  stw r8, 0(r7);
  addi r7, r7, 4;
lbl_80129934:
  lwz r8, 0x10(r4);
  addi r9, r8, 1;
  stw r9, 0x10(r4);
  lwz r8, 0x1c(r4);
  cmplw r9, r8;
  blt lbl_80129950;
  stw r28, 0x10(r4);
lbl_80129950:
  lwz r8, 0x14(r4);
  addi r9, r8, 1;
  stw r9, 0x14(r4);
  lwz r8, 0x1c(r4);
  cmplw r9, r8;
  blt lbl_8012996c;
  stw r28, 0x14(r4);
lbl_8012996c:
  lwz r8, 0x18(r4);
  addi r10, r4, 8;
  addi r9, r8, 1;
  stw r9, 0x18(r4);
  lwz r8, 0x1c(r4);
  cmplw r9, r8;
  blt lbl_8012998c;
  stw r28, 0x10(r10);
lbl_8012998c:
  lwz r9, 0x44(r4);
  cmpwi r9, 0;
  beq lbl_801299b0;
  lwz r8, 0x40(r4);
  addi r8, r8, 1;
  cmplw r8, r9;
  stw r8, 0x40(r4);
  blt lbl_801299b0;
  stw r28, 0x40(r4);
lbl_801299b0:
  lwz r8, 0x7c(r4);
  addi r9, r8, 1;
  stw r9, 0x7c(r4);
  lwz r8, 0x88(r4);
  cmplw r9, r8;
  blt lbl_801299cc;
  stw r28, 0x7c(r4);
lbl_801299cc:
  lwz r8, 0x80(r4);
  addi r9, r8, 1;
  stw r9, 0x80(r4);
  lwz r8, 0x8c(r4);
  cmplw r9, r8;
  blt lbl_801299e8;
  stw r28, 0x80(r4);
lbl_801299e8:
  lwz r8, 0x84(r4);
  addi r10, r4, 8;
  addi r9, r8, 1;
  stw r9, 0x84(r4);
  lwz r8, 0x90(r4);
  cmplw r9, r8;
  blt lbl_80129a08;
  stw r28, 0x7c(r10);
lbl_80129a08:
  lwz r8, 0xcc(r4);
  addi r9, r8, 1;
  stw r9, 0xcc(r4);
  lwz r8, 0xd4(r4);
  cmplw r9, r8;
  blt lbl_80129a24;
  stw r28, 0xcc(r4);
lbl_80129a24:
  lwz r8, 0xd0(r4);
  addi r9, r8, 1;
  stw r9, 0xd0(r4);
  lwz r8, 0xd8(r4);
  cmplw r9, r8;
  blt lbl_80129a40;
  stw r28, 0xd0(r4);
lbl_80129a40:
  addi r30, r30, 1;
  cmplwi r30, 0x60;
  blt lbl_801295a4;
lbl_80129a4c:
  psq_l f31, 168(r1), 0, 0;
  lfd f31, 0xa0(r1);
  psq_l f30, 152(r1), 0, 0;
  addi r11, r1, 0x90;
  lfd f30, 0x90(r1);
  bl _restgpr_24;
  lwz r0, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpDpl2__AllocDelayLine
// PAL: 0x80129a74..0x80129be8
MARK_BINARY_BLOB(AXFXReverbHiExpDpl2__AllocDelayLine, 0x80129a74, 0x80129be8);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__AllocDelayLine) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  mr r23, r3;
  li r24, 0;
  mr r30, r23;
  li r31, 0;
  mr r29, r23;
  mr r28, r23;
lbl_80129aa0:
  lwz r0, 0x20(r23);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0(r30);
  bne lbl_80129ac8;
  li r3, 0;
  b lbl_80129bd0;
lbl_80129ac8:
  lwz r0, 0x48(r23);
  cmpwi r0, 0;
  beq lbl_80129af8;
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x30(r30);
  bne lbl_80129afc;
  li r3, 0;
  b lbl_80129bd0;
lbl_80129af8:
  stw r31, 0x30(r30);
lbl_80129afc:
  mr r26, r23;
  mr r27, r29;
  li r25, 0;
lbl_80129b08:
  lwz r0, 0x94(r26);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x4c(r27);
  bne lbl_80129b30;
  li r3, 0;
  b lbl_80129bd0;
lbl_80129b30:
  addi r25, r25, 1;
  addi r27, r27, 4;
  cmplwi r25, 3;
  addi r26, r26, 4;
  blt lbl_80129b08;
  mr r27, r23;
  mr r26, r28;
  li r25, 0;
lbl_80129b50:
  lwz r0, 0xdc(r27);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0xac(r26);
  bne lbl_80129b78;
  li r3, 0;
  b lbl_80129bd0;
lbl_80129b78:
  addi r25, r25, 1;
  addi r26, r26, 4;
  cmplwi r25, 2;
  addi r27, r27, 4;
  blt lbl_80129b50;
  lwz r0, 0x114(r30);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0xe4(r30);
  bne lbl_80129bb4;
  li r3, 0;
  b lbl_80129bd0;
lbl_80129bb4:
  addi r24, r24, 1;
  addi r29, r29, 0xc;
  cmplwi r24, 4;
  addi r28, r28, 8;
  addi r30, r30, 4;
  blt lbl_80129aa0;
  li r3, 1;
lbl_80129bd0:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpDpl2__BzeroDelayLines
// PAL: 0x80129be8..0x80129d0c
MARK_BINARY_BLOB(AXFXReverbHiExpDpl2__BzeroDelayLines, 0x80129be8, 0x80129d0c);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__BzeroDelayLines) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r24, r3;
  li r25, 0;
  mr r31, r24;
  mr r30, r24;
  mr r29, r24;
lbl_80129c10:
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80129c2c;
  lwz r0, 0x20(r24);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80129c2c:
  lwz r3, 0x30(r31);
  cmpwi r3, 0;
  beq lbl_80129c48;
  lwz r0, 0x48(r24);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80129c48:
  mr r27, r30;
  mr r28, r24;
  li r26, 0;
lbl_80129c54:
  lwz r3, 0x4c(r27);
  cmpwi r3, 0;
  beq lbl_80129c70;
  lwz r0, 0x94(r28);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80129c70:
  addi r26, r26, 1;
  addi r28, r28, 4;
  cmplwi r26, 3;
  addi r27, r27, 4;
  blt lbl_80129c54;
  mr r28, r29;
  mr r27, r24;
  li r26, 0;
lbl_80129c90:
  lwz r3, 0xac(r28);
  cmpwi r3, 0;
  beq lbl_80129cac;
  lwz r0, 0xdc(r27);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80129cac:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 2;
  addi r28, r28, 4;
  blt lbl_80129c90;
  lwz r3, 0xe4(r31);
  cmpwi r3, 0;
  beq lbl_80129cdc;
  lwz r0, 0x114(r31);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80129cdc:
  addi r25, r25, 1;
  addi r30, r30, 0xc;
  cmplwi r25, 4;
  addi r29, r29, 8;
  addi r31, r31, 4;
  blt lbl_80129c10;
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpDpl2__FreeDelayLine
// PAL: 0x80129d0c..0x80129e20
MARK_BINARY_BLOB(AXFXReverbHiExpDpl2__FreeDelayLine, 0x80129d0c, 0x80129e20);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__FreeDelayLine) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  li r25, 0;
  mr r30, r3;
  li r31, 0;
  mr r29, r3;
  mr r28, r3;
lbl_80129d34:
  lwz r3, 0(r30);
  cmpwi r3, 0;
  beq lbl_80129d50;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0(r30);
lbl_80129d50:
  lwz r3, 0x30(r30);
  cmpwi r3, 0;
  beq lbl_80129d6c;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x30(r30);
lbl_80129d6c:
  mr r27, r29;
  li r26, 0;
lbl_80129d74:
  lwz r3, 0x4c(r27);
  cmpwi r3, 0;
  beq lbl_80129d90;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x4c(r27);
lbl_80129d90:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 3;
  blt lbl_80129d74;
  mr r27, r28;
  li r26, 0;
lbl_80129da8:
  lwz r3, 0xac(r27);
  cmpwi r3, 0;
  beq lbl_80129dc4;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0xac(r27);
lbl_80129dc4:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 2;
  blt lbl_80129da8;
  lwz r3, 0xe4(r30);
  cmpwi r3, 0;
  beq lbl_80129df0;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0xe4(r30);
lbl_80129df0:
  addi r25, r25, 1;
  addi r29, r29, 0xc;
  cmplwi r25, 4;
  addi r28, r28, 8;
  addi r30, r30, 4;
  blt lbl_80129d34;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpDpl2__InitParams
// PAL: 0x80129e20..0x8012a154
MARK_BINARY_BLOB(AXFXReverbHiExpDpl2__InitParams, 0x80129e20, 0x8012a154);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__InitParams) {
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
  bl _savegpr_24;
  lwz r4, 0x140(r3);
  lis r31, AXFXReverbHiExpDpl2__EarlySizeTable@ha;
  mr r30, r3;
  cmplwi r4, 8;
  la r31, AXFXReverbHiExpDpl2__EarlySizeTable@l(r31);
  blt lbl_80129e6c;
  li r3, 0;
  b lbl_8012a124;
lbl_80129e6c:
  lfs f4, 0x148(r3);
  lfs f2, unk_80388514;
  fcmpo cr0, f4, f2;
  blt lbl_80129e88;
  lfs f0, 0x144(r3);
  fcmpo cr0, f4, f0;
  ble lbl_80129e90;
lbl_80129e88:
  li r3, 0;
  b lbl_8012a124;
lbl_80129e90:
  lwz r0, 0x14c(r3);
  cmplwi r0, 6;
  blt lbl_80129ea4;
  li r3, 0;
  b lbl_8012a124;
lbl_80129ea4:
  lfs f0, 0x150(r3);
  fcmpo cr0, f0, f2;
  bge lbl_80129eb8;
  li r3, 0;
  b lbl_8012a124;
lbl_80129eb8:
  lfs f0, 0x154(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129ed0;
  lfs f1, unk_80388518;
  fcmpo cr0, f0, f1;
  ble lbl_80129ed8;
lbl_80129ed0:
  li r3, 0;
  b lbl_8012a124;
lbl_80129ed8:
  lfs f0, 0x158(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129eec;
  fcmpo cr0, f0, f1;
  ble lbl_80129ef4;
lbl_80129eec:
  li r3, 0;
  b lbl_8012a124;
lbl_80129ef4:
  lfs f0, 0x15c(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129f08;
  fcmpo cr0, f0, f1;
  ble lbl_80129f10;
lbl_80129f08:
  li r3, 0;
  b lbl_8012a124;
lbl_80129f10:
  lfs f3, 0x160(r3);
  fcmpo cr0, f3, f2;
  blt lbl_80129f24;
  fcmpo cr0, f3, f1;
  ble lbl_80129f2c;
lbl_80129f24:
  li r3, 0;
  b lbl_8012a124;
lbl_80129f2c:
  lfs f0, 0x164(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129f40;
  fcmpo cr0, f0, f1;
  ble lbl_80129f48;
lbl_80129f40:
  li r3, 0;
  b lbl_8012a124;
lbl_80129f48:
  lfs f0, 0x170(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129f5c;
  fcmpo cr0, f0, f1;
  ble lbl_80129f64;
lbl_80129f5c:
  li r3, 0;
  b lbl_8012a124;
lbl_80129f64:
  lfs f0, 0x174(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80129f78;
  fcmpo cr0, f0, f1;
  ble lbl_80129f80;
lbl_80129f78:
  li r3, 0;
  b lbl_8012a124;
lbl_80129f80:
  mulli r8, r4, 0xc;
  addi r9, r31, 0;
  lfs f0, unk_80388510;
  addi r5, r31, 0x60;
  lfs f2, unk_8038851c;
  li r27, 0;
  add r7, r9, r8;
  fmuls f1, f0, f4;
  lwz r6, 8(r7);
  add r4, r5, r8;
  stw r6, 0x1c(r3);
  lwzx r0, r9, r8;
  subf r0, r0, r6;
  stw r0, 0x10(r3);
  lfsx f0, r5, r8;
  fmuls f0, f3, f0;
  fmuls f0, f2, f0;
  stfs f0, 0x24(r3);
  lwz r0, 4(r7);
  subf r0, r0, r6;
  stw r0, 0x14(r3);
  lfs f0, 4(r4);
  fmuls f0, f3, f0;
  fmuls f0, f2, f0;
  stfs f0, 0x28(r3);
  lwz r0, 8(r7);
  subf r0, r0, r6;
  stw r0, 0x18(r3);
  lfs f0, 8(r4);
  fmuls f0, f3, f0;
  stw r27, 0x40(r3);
  fmuls f0, f2, f0;
  stfs f0, 0x2c(r3);
  bl __cvt_fp2unsigned;
  stw r3, 0x44(r30);
  mr r26, r30;
  lfd f29, unk_80388548;
  addi r28, r31, 0xc0;
  lfs f30, unk_80388530;
  li r24, 0;
  lfs f31, unk_80388510;
  li r25, 0;
  lis r29, 0x4330;
lbl_8012a02c:
  stw r27, 0x7c(r26);
  lfd f1, unk_80388538;
  lwz r0, 0x14c(r30);
  stw r29, 8(r1);
  mulli r0, r0, 0x24;
  add r0, r25, r0;
  lwzx r0, r28, r0;
  stw r0, 0xc(r1);
  lfd f0, 8(r1);
  stw r0, 0x88(r26);
  fsubs f2, f0, f29;
  lfs f0, 0x150(r30);
  fmuls f2, f30, f2;
  fmuls f0, f31, f0;
  fdivs f2, f2, f0;
  bl pow;
  frsp f0, f1;
  addi r24, r24, 1;
  cmplwi r24, 3;
  addi r25, r25, 4;
  stfs f0, 0xa0(r26);
  addi r26, r26, 4;
  blt lbl_8012a02c;
  lwz r0, 0x14c(r30);
  li r4, 0;
  stw r4, 0xcc(r30);
  addi r3, r31, 0xc0;
  mulli r0, r0, 0x24;
  lfs f2, unk_80388518;
  lfs f1, 0x158(r30);
  lfs f0, unk_80388540;
  add r3, r3, r0;
  fsubs f1, f2, f1;
  lwz r0, 0xc(r3);
  lfs f2, 0x154(r30);
  stw r0, 0xd4(r30);
  fcmpo cr0, f1, f0;
  stw r4, 0xd0(r30);
  lwz r0, 0x10(r3);
  stw r0, 0xd8(r30);
  stw r4, 0xf4(r30);
  lwz r0, 0x14(r3);
  stw r0, 0x104(r30);
  stw r4, 0xf8(r30);
  lwz r0, 0x18(r3);
  stw r0, 0x108(r30);
  stw r4, 0xfc(r30);
  lwz r0, 0x1c(r3);
  stw r0, 0x10c(r30);
  stw r4, 0x100(r30);
  lwz r0, 0x20(r3);
  stw r0, 0x110(r30);
  stfs f2, 0x124(r30);
  stfs f1, 0x138(r30);
  ble lbl_8012a10c;
  stfs f0, 0x138(r30);
lbl_8012a10c:
  lfs f0, unk_80388514;
  li r3, 1;
  stfs f0, 0x128(r30);
  stfs f0, 0x12c(r30);
  stfs f0, 0x130(r30);
  stfs f0, 0x134(r30);
lbl_8012a124:
  psq_l f31, 88(r1), 0, 0;
  lfd f31, 0x50(r1);
  psq_l f30, 72(r1), 0, 0;
  lfd f30, 0x40(r1);
  psq_l f29, 56(r1), 0, 0;
  addi r11, r1, 0x30;
  lfd f29, 0x30(r1);
  bl _restgpr_24;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}
