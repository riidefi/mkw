#include "fxReverbHiExp.h"

#include <string.h>
#include <math.h>

#include <rvl/os/osInterrupt.h>

#include "axfx.h"

const f32 unk_803884d0 = 32000.0f;
const f32 unk_803884d4 = 0.0f;
const f32 unk_803884d8 = 1.0f;
const f32 unk_803884dc = 0.6f;
sdata2_ps_f32 unk_803884e0 = {0.5f, 0.0f};
sdata2_ps_f32 unk_803884e8 = {176.0f, -0.0f};
sdata2_ps_f32 unk_803884f0 = {-3.0f, 0.0f};
sdata2_ps_f32 unk_803884f8 = {2.5625f, 0.0f};
sdata2_ps_f32 unk_80388500 = {0.95f, 0.0f};
sdata2_ps_f32 unk_80388508 = {176.0f, 0.0f};

u32 AXFXReverbHiExp__EarlySizeTable[8][3] = {
    {157, 479, 829},    {317, 809, 1117},  {479, 941, 1487},
    {641, 1259, 1949},  {797, 1667, 2579}, {967, 1901, 2903},
    {1123, 2179, 3413}, {1279, 2477, 3889}};

f32 AXFXReverbHiExp__EarlyCoefTable[8][3] = {
    {0.4f, -1.0f, 0.3f},   {0.5f, -0.95f, 0.3f}, {0.6f, -0.9f, 0.3f},
    {0.75f, -0.85f, 0.3f}, {-0.9f, 0.8f, 0.3f},  {-1.0f, 0.7f, 0.3f},
    {-1.0f, 0.7f, 0.3f},   {-1.0f, 0.7f, 0.3f}};

u32 AXFXReverbHiExp__FilterSizeTable[7][8] = {
    {1789, 1999, 2333, 433, 149, 47, 73, 67},
    {149, 293, 449, 251, 103, 47, 73, 67},
    {947, 1361, 1531, 433, 137, 47, 73, 67},
    {1279, 1531, 1973, 509, 149, 47, 73, 67},
    {1531, 1847, 2297, 563, 179, 47, 73, 67},
    {1823, 2357, 2693, 571, 137, 47, 73, 67},
    {1823, 2357, 2693, 571, 179, 47, 73, 67}};

// Symbol: AXFXReverbHiExpGetMemSize
// PAL: 0x801280b8..0x80128140
MARK_BINARY_BLOB(AXFXReverbHiExpGetMemSize, 0x801280b8, 0x80128140);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpGetMemSize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lis r4, AXFXReverbHiExp__EarlySizeTable@ha;
  la r4, AXFXReverbHiExp__EarlySizeTable@l(r4);
  lis r9, AXFXReverbHiExp__FilterSizeTable@ha;
  lfs f1, unk_803884d0;
  la r9, AXFXReverbHiExp__FilterSizeTable@l(r9);
  lfs f0, 0x114(r3);
  lwz r10, 0x5c(r4);
  fmuls f0, f1, f0;
  lwz r0, 0xc0(r9);
  lwz r8, 0xc4(r9);
  lwz r7, 0xc8(r9);
  fctiwz f0, f0;
  lwz r6, 0xcc(r9);
  lwz r5, 0xd0(r9);
  lwz r4, 0xd4(r9);
  stfd f0, 8(r1);
  lwz r3, 0xc(r1);
  add r10, r10, r3;
  lwz r3, 0xd8(r9);
  add r10, r10, r0;
  lwz r0, 0xdc(r9);
  add r10, r10, r8;
  add r10, r10, r7;
  add r10, r10, r6;
  add r10, r10, r5;
  slwi r5, r10, 2;
  subf r10, r10, r5;
  add r10, r10, r4;
  add r10, r10, r3;
  add r10, r10, r0;
  slwi r3, r10, 2;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpInit
// PAL: 0x80128140..0x801282dc
MARK_BINARY_BLOB(AXFXReverbHiExpInit, 0x80128140, 0x801282dc);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpInit) {
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
  lfs f1, 0x114(r30);
  li r0, 1;
  lfs f0, unk_803884d4;
  mr r31, r3;
  stw r0, 0x10c(r30);
  fcmpo cr0, f1, f0;
  bge lbl_801281b0;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x10c(r30);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801282c0;
lbl_801281b0:
  lis r3, AXFXReverbHiExp__EarlySizeTable@ha;
  lfs f0, unk_803884d0;
  la r3, AXFXReverbHiExp__EarlySizeTable@l(r3);
  lwz r0, 0x5c(r3);
  fmuls f1, f0, f1;
  stw r0, 0x1c(r30);
  bl __cvt_fp2unsigned;
  stw r3, 0x40(r30);
  lis r4, AXFXReverbHiExp__FilterSizeTable@ha;
  la r4, AXFXReverbHiExp__FilterSizeTable@l(r4);
  mr r3, r30;
  lwz r0, 0xc0(r4);
  stw r0, 0x80(r30);
  lwz r0, 0xc4(r4);
  stw r0, 0x84(r30);
  lwz r0, 0xc8(r4);
  stw r0, 0x88(r30);
  lwz r0, 0xcc(r4);
  stw r0, 0xc0(r30);
  lwz r0, 0xd0(r4);
  stw r0, 0xc4(r30);
  lwz r0, 0xd4(r4);
  stw r0, 0xec(r30);
  lwz r0, 0xd8(r4);
  stw r0, 0xf0(r30);
  lwz r0, 0xdc(r4);
  stw r0, 0xf4(r30);
  bl AXFXReverbHiExp__AllocDelayLine;
  cmpwi r3, 0;
  bne lbl_8012825c;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x10c(r30);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801282c0;
lbl_8012825c:
  mr r3, r30;
  bl AXFXReverbHiExp__BzeroDelayLines;
  mr r3, r30;
  bl AXFXReverbHiExp__InitParams;
  cmpwi r3, 0;
  bne lbl_801282a8;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r30);
  mr r29, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x10c(r30);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801282c0;
lbl_801282a8:
  lwz r0, 0x10c(r30);
  mr r3, r31;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x10c(r30);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801282c0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpSettings
// PAL: 0x801282dc..0x801283ac
MARK_BINARY_BLOB(AXFXReverbHiExpSettings, 0x801282dc, 0x801283ac);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpSettings) {
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
  lwz r0, 0x10c(r29);
  mr r30, r3;
  ori r0, r0, 1;
  stw r0, 0x10c(r29);
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x10c(r29);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r29;
  bl AXFXReverbHiExpInit;
  cmpwi r3, 0;
  bne lbl_80128374;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x10c(r29);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80128390;
lbl_80128374:
  lwz r0, 0x10c(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x10c(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80128390:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpSettingsUpdate
// PAL: 0x801283ac..0x80128460
MARK_BINARY_BLOB(AXFXReverbHiExpSettingsUpdate, 0x801283ac, 0x80128460);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsUpdate) {
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
  lwz r0, 0x10c(r29);
  mr r30, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x10c(r29);
  bl AXFXReverbHiExp__BzeroDelayLines;
  mr r3, r29;
  bl AXFXReverbHiExp__InitParams;
  cmpwi r3, 0;
  bne lbl_80128428;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r29);
  mr r31, r3;
  mr r3, r29;
  ori r0, r0, 1;
  stw r0, 0x10c(r29);
  bl AXFXReverbHiExp__FreeDelayLine;
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80128444;
lbl_80128428:
  lwz r0, 0x10c(r29);
  mr r3, r30;
  ori r0, r0, 2;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x10c(r29);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80128444:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExpShutdown
// PAL: 0x80128460..0x801284b4
MARK_BINARY_BLOB(AXFXReverbHiExpShutdown, 0x80128460, 0x801284b4);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpShutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, 0x10c(r30);
  mr r31, r3;
  mr r3, r30;
  ori r0, r0, 1;
  stw r0, 0x10c(r30);
  bl AXFXReverbHiExp__FreeDelayLine;
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

// Symbol: AXFXReverbHiExpCallback
// PAL: 0x801284b4..0x801289d0
MARK_BINARY_BLOB(AXFXReverbHiExpCallback, 0x801284b4, 0x801289d0);
asm UNKNOWN_FUNCTION(AXFXReverbHiExpCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_25;
  lwz r0, 0x10c(r4);
  cmpwi r0, 0;
  beq lbl_801284e0;
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0x10c(r4);
  b lbl_801289b8;
lbl_801284e0:
  lwz r7, 0x138(r4);
  lwz r6, 0(r3);
  lwz r5, 4(r3);
  cmpwi r7, 0;
  lwz r0, 8(r3);
  stw r6, 0x2c(r1);
  stw r5, 0x30(r1);
  stw r0, 0x34(r1);
  beq lbl_8012851c;
  lwz r5, 0(r7);
  lwz r3, 4(r7);
  lwz r0, 8(r7);
  stw r5, 8(r1);
  stw r3, 0xc(r1);
  stw r0, 0x10(r1);
lbl_8012851c:
  lwz r7, 0x13c(r4);
  cmpwi r7, 0;
  beq lbl_80128534;
  lwz r3, 0(r7);
  lwz r5, 4(r7);
  lwz r6, 8(r7);
lbl_80128534:
  lfs f0, unk_803884d8;
  li r31, 0;
  lfs f1, 0x108(r4);
  li r29, 0;
  lfs f5, unk_803884dc;
  lis r0, 0x4330;
  lfs f3, 0x134(r4);
  fsubs f4, f0, f1;
  lfs f2, unk_803884e0;
  li r30, 3;
  lfs f0, 0x12c(r4);
  fmuls f5, f5, f3;
  lfs f3, 0xf8(r4);
  fmuls f6, f2, f0;
  lfd f0, unk_803884e8;
lbl_80128570:
  mr r9, r4;
  mr r10, r4;
  mr r11, r4;
  addi r7, r1, 8;
  addi r8, r1, 0x2c;
  addi r12, r1, 0x14;
  mtctr r30;
lbl_8012858c:
  lwz r26, 0x138(r4);
  cmpwi r26, 0;
  beq lbl_801285cc;
  lwz r27, 0(r7);
  lwz r28, 0(r8);
  lwz r26, 0(r27);
  addi r27, r27, 4;
  lwz r28, 0(r28);
  stw r0, 0x38(r1);
  add r26, r28, r26;
  xoris r26, r26, 0x8000;
  stw r27, 0(r7);
  stw r26, 0x3c(r1);
  lfd f2, 0x38(r1);
  fsubs f11, f2, f0;
  b lbl_801285e8;
lbl_801285cc:
  lwz r26, 0(r8);
  stw r0, 0x40(r1);
  lwz r26, 0(r26);
  xoris r26, r26, 0x8000;
  stw r26, 0x44(r1);
  lfd f2, 0x40(r1);
  fsubs f11, f2, f0;
lbl_801285e8:
  lwz r28, 0xc(r4);
  lwz r27, 0x10(r4);
  lwz r26, 0x14(r4);
  slwi r28, r28, 2;
  lwz r25, 0(r9);
  slwi r27, r27, 2;
  lfs f9, 0x20(r4);
  slwi r26, r26, 2;
  lfsx f8, r25, r28;
  lfs f7, 0x24(r4);
  lfsx f2, r25, r27;
  fmuls f8, f9, f8;
  lfs f10, 0x28(r4);
  lfsx f9, r25, r26;
  fmuls f2, f7, f2;
  stfsx f11, r25, r26;
  fmuls f7, f10, f9;
  fadds f2, f8, f2;
  lwz r27, 0x3c(r4);
  cmpwi r27, 0;
  fadds f2, f7, f2;
  beq lbl_80128658;
  lwz r27, 0x38(r4);
  lwz r28, 0x2c(r9);
  slwi r27, r27, 2;
  lfsx f9, r28, r27;
  stfsx f11, r28, r27;
  b lbl_8012865c;
lbl_80128658:
  fmr f9, f11;
lbl_8012865c:
  lwz r27, 0x68(r4);
  lwz r25, 0x44(r10);
  slwi r27, r27, 2;
  lfs f7, 0x8c(r4);
  lfsx f8, r25, r27;
  lfs f10, unk_803884d4;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r25, r27;
  lwz r27, 0x6c(r4);
  lwz r26, 0x48(r10);
  slwi r27, r27, 2;
  lfs f7, 0x90(r4);
  lfsx f8, r26, r27;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r26, r27;
  lwz r27, 0x70(r4);
  lwz r28, 0x4c(r10);
  slwi r27, r27, 2;
  lfs f7, 0x94(r4);
  lfsx f8, r28, r27;
  fmuls f7, f8, f7;
  fadds f10, f10, f8;
  fadds f7, f9, f7;
  stfsx f7, r28, r27;
  lwz r27, 0xb0(r4);
  lwz r25, 0x98(r11);
  slwi r27, r27, 2;
  lfsx f8, r25, r27;
  fmuls f7, f8, f3;
  fadds f7, f10, f7;
  stfsx f7, r25, r27;
  fmuls f7, f7, f3;
  lwz r27, 0xb4(r4);
  lwz r26, 0x9c(r11);
  fsubs f8, f8, f7;
  slwi r27, r27, 2;
  lfsx f9, r26, r27;
  fmuls f7, f9, f3;
  fadds f7, f8, f7;
  fmuls f8, f7, f3;
  stfsx f7, r26, r27;
  lfs f7, 0xfc(r9);
  fsubs f8, f9, f8;
  fmuls f7, f1, f7;
  fmuls f8, f4, f8;
  fadds f9, f8, f7;
  stfs f9, 0xfc(r9);
  lwz r27, 0xd4(r9);
  lwz r28, 0xc8(r9);
  slwi r27, r27, 2;
  lfsx f8, r28, r27;
  fmuls f7, f8, f3;
  fadds f7, f9, f7;
  stfsx f7, r28, r27;
  fmuls f7, f7, f3;
  lwz r27, 0xd4(r9);
  fsubs f7, f8, f7;
  addi r27, r27, 1;
  stw r27, 0xd4(r9);
  lwz r28, 0xe0(r9);
  stfs f7, 0(r12);
  cmplw r27, r28;
  blt lbl_8012876c;
  stw r29, 0xd4(r9);
lbl_8012876c:
  lfs f7, 0(r12);
  addi r7, r7, 4;
  addi r8, r8, 4;
  addi r9, r9, 4;
  fmuls f7, f7, f5;
  addi r10, r10, 0xc;
  addi r11, r11, 8;
  fadds f2, f7, f2;
  stfs f2, 0(r12);
  addi r12, r12, 4;
  bdnz lbl_8012858c;
  lfs f12, 0x18(r1);
  lfs f11, 0x1c(r1);
  lfs f10, 0x14(r1);
  fadds f2, f12, f11;
  lwz r12, 0x2c(r1);
  fadds f7, f10, f11;
  lwz r8, 0x34(r1);
  addi r11, r12, 4;
  lwz r10, 0x30(r1);
  fmuls f9, f2, f6;
  addi r7, r8, 4;
  fmuls f8, f7, f6;
  addi r9, r10, 4;
  lfs f2, 0x140(r4);
  fadds f13, f10, f12;
  fadds f9, f10, f9;
  stw r11, 0x2c(r1);
  fadds f8, f12, f8;
  fmuls f7, f13, f6;
  stw r7, 0x34(r1);
  fmuls f2, f9, f2;
  stfs f9, 0x20(r1);
  fadds f7, f11, f7;
  fctiwz f2, f2;
  stfs f8, 0x24(r1);
  stfs f7, 0x28(r1);
  stfd f2, 0x40(r1);
  lwz r11, 0x44(r1);
  stw r9, 0x30(r1);
  stw r11, 0(r12);
  lfs f2, 0x140(r4);
  fmuls f2, f8, f2;
  fctiwz f2, f2;
  stfd f2, 0x38(r1);
  lwz r7, 0x3c(r1);
  stw r7, 0(r10);
  lfs f2, 0x140(r4);
  fmuls f2, f7, f2;
  fctiwz f2, f2;
  stfd f2, 0x48(r1);
  lwz r7, 0x4c(r1);
  stw r7, 0(r8);
  lwz r7, 0x13c(r4);
  cmpwi r7, 0;
  beq lbl_801288a0;
  lfs f2, 0x144(r4);
  fmuls f2, f9, f2;
  fctiwz f2, f2;
  stfd f2, 0x48(r1);
  lwz r7, 0x4c(r1);
  stw r7, 0(r3);
  addi r3, r3, 4;
  lfs f2, 0x144(r4);
  fmuls f2, f8, f2;
  fctiwz f2, f2;
  stfd f2, 0x40(r1);
  lwz r7, 0x44(r1);
  stw r7, 0(r5);
  addi r5, r5, 4;
  lfs f2, 0x144(r4);
  fmuls f2, f7, f2;
  fctiwz f2, f2;
  stfd f2, 0x38(r1);
  lwz r7, 0x3c(r1);
  stw r7, 0(r6);
  addi r6, r6, 4;
lbl_801288a0:
  lwz r7, 0xc(r4);
  addi r8, r7, 1;
  stw r8, 0xc(r4);
  lwz r7, 0x18(r4);
  cmplw r8, r7;
  blt lbl_801288bc;
  stw r29, 0xc(r4);
lbl_801288bc:
  lwz r7, 0x10(r4);
  addi r8, r7, 1;
  stw r8, 0x10(r4);
  lwz r7, 0x18(r4);
  cmplw r8, r7;
  blt lbl_801288d8;
  stw r29, 0x10(r4);
lbl_801288d8:
  lwz r7, 0x14(r4);
  addi r9, r4, 8;
  addi r8, r7, 1;
  stw r8, 0x14(r4);
  lwz r7, 0x18(r4);
  cmplw r8, r7;
  blt lbl_801288f8;
  stw r29, 0xc(r9);
lbl_801288f8:
  lwz r8, 0x3c(r4);
  cmpwi r8, 0;
  beq lbl_8012891c;
  lwz r7, 0x38(r4);
  addi r7, r7, 1;
  cmplw r7, r8;
  stw r7, 0x38(r4);
  blt lbl_8012891c;
  stw r29, 0x38(r4);
lbl_8012891c:
  lwz r7, 0x68(r4);
  addi r8, r7, 1;
  stw r8, 0x68(r4);
  lwz r7, 0x74(r4);
  cmplw r8, r7;
  blt lbl_80128938;
  stw r29, 0x68(r4);
lbl_80128938:
  lwz r7, 0x6c(r4);
  addi r8, r7, 1;
  stw r8, 0x6c(r4);
  lwz r7, 0x78(r4);
  cmplw r8, r7;
  blt lbl_80128954;
  stw r29, 0x6c(r4);
lbl_80128954:
  lwz r7, 0x70(r4);
  addi r9, r4, 8;
  addi r8, r7, 1;
  stw r8, 0x70(r4);
  lwz r7, 0x7c(r4);
  cmplw r8, r7;
  blt lbl_80128974;
  stw r29, 0x68(r9);
lbl_80128974:
  lwz r7, 0xb0(r4);
  addi r8, r7, 1;
  stw r8, 0xb0(r4);
  lwz r7, 0xb8(r4);
  cmplw r8, r7;
  blt lbl_80128990;
  stw r29, 0xb0(r4);
lbl_80128990:
  lwz r7, 0xb4(r4);
  addi r8, r7, 1;
  stw r8, 0xb4(r4);
  lwz r7, 0xbc(r4);
  cmplw r8, r7;
  blt lbl_801289ac;
  stw r29, 0xb4(r4);
lbl_801289ac:
  addi r31, r31, 1;
  cmplwi r31, 0x60;
  blt lbl_80128570;
lbl_801289b8:
  addi r11, r1, 0x70;
  bl _restgpr_25;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExp__AllocDelayLine
// PAL: 0x801289d0..0x80128b44
MARK_BINARY_BLOB(AXFXReverbHiExp__AllocDelayLine, 0x801289d0, 0x80128b44);
asm UNKNOWN_FUNCTION(AXFXReverbHiExp__AllocDelayLine) {
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
lbl_801289fc:
  lwz r0, 0x1c(r23);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0(r30);
  bne lbl_80128a24;
  li r3, 0;
  b lbl_80128b2c;
lbl_80128a24:
  lwz r0, 0x40(r23);
  cmpwi r0, 0;
  beq lbl_80128a54;
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x2c(r30);
  bne lbl_80128a58;
  li r3, 0;
  b lbl_80128b2c;
lbl_80128a54:
  stw r31, 0x2c(r30);
lbl_80128a58:
  mr r26, r23;
  mr r27, r29;
  li r25, 0;
lbl_80128a64:
  lwz r0, 0x80(r26);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x44(r27);
  bne lbl_80128a8c;
  li r3, 0;
  b lbl_80128b2c;
lbl_80128a8c:
  addi r25, r25, 1;
  addi r27, r27, 4;
  cmplwi r25, 3;
  addi r26, r26, 4;
  blt lbl_80128a64;
  mr r27, r23;
  mr r26, r28;
  li r25, 0;
lbl_80128aac:
  lwz r0, 0xc0(r27);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0x98(r26);
  bne lbl_80128ad4;
  li r3, 0;
  b lbl_80128b2c;
lbl_80128ad4:
  addi r25, r25, 1;
  addi r26, r26, 4;
  cmplwi r25, 2;
  addi r27, r27, 4;
  blt lbl_80128aac;
  lwz r0, 0xec(r30);
  lwz r12, __AXFXAlloc;
  slwi r3, r0, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  stw r3, 0xc8(r30);
  bne lbl_80128b10;
  li r3, 0;
  b lbl_80128b2c;
lbl_80128b10:
  addi r24, r24, 1;
  addi r29, r29, 0xc;
  cmplwi r24, 3;
  addi r28, r28, 8;
  addi r30, r30, 4;
  blt lbl_801289fc;
  li r3, 1;
lbl_80128b2c:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExp__BzeroDelayLines
// PAL: 0x80128b44..0x80128c68
MARK_BINARY_BLOB(AXFXReverbHiExp__BzeroDelayLines, 0x80128b44, 0x80128c68);
asm UNKNOWN_FUNCTION(AXFXReverbHiExp__BzeroDelayLines) {
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
lbl_80128b6c:
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80128b88;
  lwz r0, 0x1c(r24);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80128b88:
  lwz r3, 0x2c(r31);
  cmpwi r3, 0;
  beq lbl_80128ba4;
  lwz r0, 0x40(r24);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80128ba4:
  mr r27, r30;
  mr r28, r24;
  li r26, 0;
lbl_80128bb0:
  lwz r3, 0x44(r27);
  cmpwi r3, 0;
  beq lbl_80128bcc;
  lwz r0, 0x80(r28);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80128bcc:
  addi r26, r26, 1;
  addi r28, r28, 4;
  cmplwi r26, 3;
  addi r27, r27, 4;
  blt lbl_80128bb0;
  mr r28, r29;
  mr r27, r24;
  li r26, 0;
lbl_80128bec:
  lwz r3, 0x98(r28);
  cmpwi r3, 0;
  beq lbl_80128c08;
  lwz r0, 0xc0(r27);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80128c08:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 2;
  addi r28, r28, 4;
  blt lbl_80128bec;
  lwz r3, 0xc8(r31);
  cmpwi r3, 0;
  beq lbl_80128c38;
  lwz r0, 0xec(r31);
  li r4, 0;
  slwi r5, r0, 2;
  bl memset;
lbl_80128c38:
  addi r25, r25, 1;
  addi r30, r30, 0xc;
  cmplwi r25, 3;
  addi r29, r29, 8;
  addi r31, r31, 4;
  blt lbl_80128b6c;
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExp__FreeDelayLine
// PAL: 0x80128c68..0x80128d7c
MARK_BINARY_BLOB(AXFXReverbHiExp__FreeDelayLine, 0x80128c68, 0x80128d7c);
asm UNKNOWN_FUNCTION(AXFXReverbHiExp__FreeDelayLine) {
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
lbl_80128c90:
  lwz r3, 0(r30);
  cmpwi r3, 0;
  beq lbl_80128cac;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0(r30);
lbl_80128cac:
  lwz r3, 0x2c(r30);
  cmpwi r3, 0;
  beq lbl_80128cc8;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x2c(r30);
lbl_80128cc8:
  mr r27, r29;
  li r26, 0;
lbl_80128cd0:
  lwz r3, 0x44(r27);
  cmpwi r3, 0;
  beq lbl_80128cec;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x44(r27);
lbl_80128cec:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 3;
  blt lbl_80128cd0;
  mr r27, r28;
  li r26, 0;
lbl_80128d04:
  lwz r3, 0x98(r27);
  cmpwi r3, 0;
  beq lbl_80128d20;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0x98(r27);
lbl_80128d20:
  addi r26, r26, 1;
  addi r27, r27, 4;
  cmplwi r26, 2;
  blt lbl_80128d04;
  lwz r3, 0xc8(r30);
  cmpwi r3, 0;
  beq lbl_80128d4c;
  lwz r12, __AXFXFree;
  mtctr r12;
  bctrl;
  stw r31, 0xc8(r30);
lbl_80128d4c:
  addi r25, r25, 1;
  addi r29, r29, 0xc;
  cmplwi r25, 3;
  addi r28, r28, 8;
  addi r30, r30, 4;
  blt lbl_80128c90;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiExp__InitParams
// PAL: 0x80128d7c..0x801290a0
MARK_BINARY_BLOB(AXFXReverbHiExp__InitParams, 0x80128d7c, 0x801290a0);
asm UNKNOWN_FUNCTION(AXFXReverbHiExp__InitParams) {
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
  lwz r4, 0x110(r3);
  lis r31, AXFXReverbHiExp__EarlySizeTable@ha;
  mr r30, r3;
  cmplwi r4, 8;
  la r31, AXFXReverbHiExp__EarlySizeTable@l(r31);
  blt lbl_80128dc8;
  li r3, 0;
  b lbl_80129070;
lbl_80128dc8:
  lfs f4, 0x118(r3);
  lfs f2, unk_803884d4;
  fcmpo cr0, f4, f2;
  blt lbl_80128de4;
  lfs f0, 0x114(r3);
  fcmpo cr0, f4, f0;
  ble lbl_80128dec;
lbl_80128de4:
  li r3, 0;
  b lbl_80129070;
lbl_80128dec:
  lwz r0, 0x11c(r3);
  cmplwi r0, 6;
  blt lbl_80128e00;
  li r3, 0;
  b lbl_80129070;
lbl_80128e00:
  lfs f0, 0x120(r3);
  fcmpo cr0, f0, f2;
  bge lbl_80128e14;
  li r3, 0;
  b lbl_80129070;
lbl_80128e14:
  lfs f0, 0x124(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128e2c;
  lfs f1, unk_803884d8;
  fcmpo cr0, f0, f1;
  ble lbl_80128e34;
lbl_80128e2c:
  li r3, 0;
  b lbl_80129070;
lbl_80128e34:
  lfs f0, 0x128(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128e48;
  fcmpo cr0, f0, f1;
  ble lbl_80128e50;
lbl_80128e48:
  li r3, 0;
  b lbl_80129070;
lbl_80128e50:
  lfs f0, 0x12c(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128e64;
  fcmpo cr0, f0, f1;
  ble lbl_80128e6c;
lbl_80128e64:
  li r3, 0;
  b lbl_80129070;
lbl_80128e6c:
  lfs f3, 0x130(r3);
  fcmpo cr0, f3, f2;
  blt lbl_80128e80;
  fcmpo cr0, f3, f1;
  ble lbl_80128e88;
lbl_80128e80:
  li r3, 0;
  b lbl_80129070;
lbl_80128e88:
  lfs f0, 0x134(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128e9c;
  fcmpo cr0, f0, f1;
  ble lbl_80128ea4;
lbl_80128e9c:
  li r3, 0;
  b lbl_80129070;
lbl_80128ea4:
  lfs f0, 0x140(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128eb8;
  fcmpo cr0, f0, f1;
  ble lbl_80128ec0;
lbl_80128eb8:
  li r3, 0;
  b lbl_80129070;
lbl_80128ec0:
  lfs f0, 0x144(r3);
  fcmpo cr0, f0, f2;
  blt lbl_80128ed4;
  fcmpo cr0, f0, f1;
  ble lbl_80128edc;
lbl_80128ed4:
  li r3, 0;
  b lbl_80129070;
lbl_80128edc:
  mulli r8, r4, 0xc;
  addi r9, r31, 0;
  lfs f0, unk_803884d0;
  addi r5, r31, 0x60;
  lfs f2, unk_803884dc;
  li r27, 0;
  add r7, r9, r8;
  fmuls f1, f0, f4;
  lwz r6, 8(r7);
  add r4, r5, r8;
  stw r6, 0x18(r3);
  lwzx r0, r9, r8;
  subf r0, r0, r6;
  stw r0, 0xc(r3);
  lfsx f0, r5, r8;
  fmuls f0, f3, f0;
  fmuls f0, f2, f0;
  stfs f0, 0x20(r3);
  lwz r0, 4(r7);
  subf r0, r0, r6;
  stw r0, 0x10(r3);
  lfs f0, 4(r4);
  fmuls f0, f3, f0;
  fmuls f0, f2, f0;
  stfs f0, 0x24(r3);
  lwz r0, 8(r7);
  subf r0, r0, r6;
  stw r0, 0x14(r3);
  lfs f0, 8(r4);
  fmuls f0, f3, f0;
  stw r27, 0x38(r3);
  fmuls f0, f2, f0;
  stfs f0, 0x28(r3);
  bl __cvt_fp2unsigned;
  stw r3, 0x3c(r30);
  mr r26, r30;
  lfd f29, unk_80388508;
  addi r28, r31, 0xc0;
  lfs f30, unk_803884f0;
  li r24, 0;
  lfs f31, unk_803884d0;
  li r25, 0;
  lis r29, 0x4330;
lbl_80128f88:
  stw r27, 0x68(r26);
  lfd f1, unk_803884f8;
  lwz r0, 0x11c(r30);
  stw r29, 8(r1);
  slwi r0, r0, 5;
  add r0, r25, r0;
  lwzx r0, r28, r0;
  stw r0, 0xc(r1);
  lfd f0, 8(r1);
  stw r0, 0x74(r26);
  fsubs f2, f0, f29;
  lfs f0, 0x120(r30);
  fmuls f2, f30, f2;
  fmuls f0, f31, f0;
  fdivs f2, f2, f0;
  bl pow;
  frsp f0, f1;
  addi r24, r24, 1;
  cmplwi r24, 3;
  addi r25, r25, 4;
  stfs f0, 0x8c(r26);
  addi r26, r26, 4;
  blt lbl_80128f88;
  lwz r0, 0x11c(r30);
  li r4, 0;
  stw r4, 0xb0(r30);
  addi r3, r31, 0xc0;
  slwi r0, r0, 5;
  lfs f1, unk_803884d8;
  add r3, r3, r0;
  lfs f0, 0x128(r30);
  lwz r0, 0xc(r3);
  fsubs f1, f1, f0;
  lfs f0, unk_80388500;
  stw r0, 0xb8(r30);
  lfs f2, 0x124(r30);
  stw r4, 0xb4(r30);
  fcmpo cr0, f1, f0;
  lwz r0, 0x10(r3);
  stw r0, 0xbc(r30);
  stw r4, 0xd4(r30);
  lwz r0, 0x14(r3);
  stw r0, 0xe0(r30);
  stw r4, 0xd8(r30);
  lwz r0, 0x18(r3);
  stw r0, 0xe4(r30);
  stw r4, 0xdc(r30);
  lwz r0, 0x1c(r3);
  stw r0, 0xe8(r30);
  stfs f2, 0xf8(r30);
  stfs f1, 0x108(r30);
  ble lbl_8012905c;
  stfs f0, 0x108(r30);
lbl_8012905c:
  lfs f0, unk_803884d4;
  li r3, 1;
  stfs f0, 0xfc(r30);
  stfs f0, 0x100(r30);
  stfs f0, 0x104(r30);
lbl_80129070:
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
