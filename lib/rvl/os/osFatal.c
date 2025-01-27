#include "osFatal.h"

#include <rvl/base/ppcArch.h>
#include <string.h>

#include "os.h"
#include "osArena.h"
#include "osAudio.h"
#include "osCache.h"
#include "osContext.h"
#include "osError.h"
#include "osException.h"
#include "osInterrupt.h"
#include "osReset.h"

// Extern function references.
// PAL: 0x80168380
extern UNKNOWN_FUNCTION(EXISync);
// PAL: 0x801685fc
extern UNKNOWN_FUNCTION(EXISetExiCallback);
// PAL: 0x80168b00
extern UNKNOWN_FUNCTION(EXIDeselect);
// PAL: 0x80169164
extern UNKNOWN_FUNCTION(EXILock);
// PAL: 0x80169260
extern UNKNOWN_FUNCTION(EXIUnlock);
// PAL: 0x8016e848
extern UNKNOWN_FUNCTION(GXAbortFrame);
// PAL: 0x801a5d34
extern UNKNOWN_FUNCTION(OSLoadFont);
// PAL: 0x801a6114
extern UNKNOWN_FUNCTION(OSGetFontTexel);
// PAL: 0x801b90f4
extern UNKNOWN_FUNCTION(VISetPreRetraceCallback);
// PAL: 0x801b9138
extern UNKNOWN_FUNCTION(VISetPostRetraceCallback);
// PAL: 0x801b94a4
extern UNKNOWN_FUNCTION(VIInit);
// PAL: 0x801b9f6c
extern UNKNOWN_FUNCTION(VIConfigure);
// PAL: 0x801ba650
extern UNKNOWN_FUNCTION(VIConfigurePan);
// PAL: 0x801ba9a4
extern UNKNOWN_FUNCTION(VIFlush);
// PAL: 0x801baab8
extern UNKNOWN_FUNCTION(VISetNextFrameBuffer);
// PAL: 0x801bab2c
extern UNKNOWN_FUNCTION(VISetBlack);
// PAL: 0x801baba4
extern UNKNOWN_FUNCTION(VIGetRetraceCount);
// PAL: 0x801bacd8
extern UNKNOWN_FUNCTION(VIGetTvFormat);

char _unk_80385ac8[] = "%s\n";

asm void float_ordering() {
  lfs f1, 0.5f;
  lfs f1, 16.0f;
  lfs f1, 0.098f;
  lfs f1, 0.257f;
  lfs f1, 0.504f;
  lfs f1, 128.0f;
  lfs f1, 0.439f;
  lfs f1, -0.148f;
  lfs f1, 0.291f;
  lfs f1, 0.368f;
  lfs f1, 0.071f;
  lfs f1, 235.0f;
  lfs f1, 240.0f;
}

// Symbol: ScreenReport
// PAL: 0x801a4aa4..0x801a4dc8
MARK_BINARY_BLOB(ScreenReport, 0x801a4aa4, 0x801a4dc8);
asm UNKNOWN_FUNCTION(ScreenReport) {
  // clang-format off
  nofralloc;
  stwu r1, -0x170(r1);
  mflr r0;
  stw r0, 0x174(r1);
  addi r11, r1, 0x170;
  bl _savegpr_17;
  mr r22, r3;
  mr r23, r4;
  mr r24, r6;
  mr r25, r7;
  mr r26, r8;
  mr r27, r9;
  addi r31, r5, -24;
  addi r30, r4, -48;
  lis r18, 0x8081;
  lis r19, 0x8889;
  li r17, 0;
  li r21, 0x18;
  li r20, 3;
lbl_801a4aec:
  cmpw r31, r26;
  blt lbl_801a4db0;
  mullw r0, r26, r23;
  mr r28, r25;
  add r0, r25, r0;
  slwi r0, r0, 1;
  add r29, r22, r0;
  b lbl_801a4da4;
lbl_801a4b0c:
  extsb r0, r3;
  cmpwi r0, 0xa;
  bne lbl_801a4b24;
  add r26, r26, r27;
  addi r10, r10, 1;
  b lbl_801a4aec;
lbl_801a4b24:
  cmpw r30, r28;
  bge lbl_801a4b34;
  add r26, r26, r27;
  b lbl_801a4aec;
lbl_801a4b34:
  li r6, 0;
  li r7, 0;
  mtctr r20;
lbl_801a4b40:
  clrlwi r0, r6, 0x1d;
  addi r3, r6, 1;
  add r0, r0, r7;
  addi r4, r1, 0x10;
  slwi r0, r0, 2;
  addi r5, r6, 2;
  add r4, r4, r0;
  addi r8, r6, 3;
  srwi r0, r3, 3;
  stw r17, 0(r4);
  mulli r0, r0, 0x18;
  clrlwi r3, r3, 0x1d;
  stw r17, 0x20(r4);
  addi r9, r6, 4;
  addi r11, r6, 6;
  add r0, r3, r0;
  stw r17, 0x40(r4);
  slwi r0, r0, 2;
  srwi r4, r5, 3;
  addi r3, r1, 0x10;
  add r3, r3, r0;
  clrlwi r5, r5, 0x1d;
  stw r17, 0(r3);
  mulli r4, r4, 0x18;
  addi r0, r6, 5;
  stw r17, 0x20(r3);
  addi r7, r7, 0x18;
  add r5, r5, r4;
  slwi r12, r5, 2;
  stw r17, 0x40(r3);
  srwi r5, r8, 3;
  addi r4, r1, 0x10;
  stwux r17, r4, r12;
  mulli r3, r5, 0x18;
  clrlwi r12, r8, 0x1d;
  stw r17, 0x20(r4);
  srwi r8, r9, 3;
  add r12, r12, r3;
  addi r5, r6, 7;
  stw r17, 0x40(r4);
  addi r3, r1, 0x10;
  slwi r12, r12, 2;
  clrlwi r9, r9, 0x1d;
  add r3, r3, r12;
  addi r4, r1, 0x10;
  stw r17, 0(r3);
  mulli r8, r8, 0x18;
  srwi r12, r0, 3;
  stw r17, 0x20(r3);
  clrlwi r0, r0, 0x1d;
  add r8, r9, r8;
  srwi r9, r11, 3;
  slwi r8, r8, 2;
  stw r17, 0x40(r3);
  add r4, r4, r8;
  addi r3, r1, 0x10;
  stw r17, 0(r4);
  mulli r12, r12, 0x18;
  clrlwi r11, r11, 0x1d;
  stw r17, 0x20(r4);
  srwi r8, r5, 3;
  add r0, r0, r12;
  addi r6, r6, 8;
  stw r17, 0x40(r4);
  slwi r0, r0, 2;
  addi r4, r1, 0x10;
  stwux r17, r3, r0;
  mulli r0, r9, 0x18;
  clrlwi r9, r5, 0x1d;
  stw r17, 0x20(r3);
  mr r5, r4;
  add r0, r11, r0;
  stw r17, 0x40(r3);
  slwi r0, r0, 2;
  stwux r17, r4, r0;
  mulli r0, r8, 0x18;
  stw r17, 0x20(r4);
  add r0, r9, r0;
  stw r17, 0x40(r4);
  slwi r0, r0, 2;
  stwux r17, r5, r0;
  stw r17, 0x20(r5);
  stw r17, 0x40(r5);
  bdnz lbl_801a4b40;
  mr r3, r10;
  addi r4, r1, 0x10;
  addi r7, r1, 8;
  li r5, 0;
  li r6, 6;
  bl OSGetFontTexel;
  mr r10, r3;
  li r7, 0;
  li r3, 0;
lbl_801a4cb4:
  srwi r0, r7, 3;
  clrlwi r6, r7, 0x1d;
  mulli r0, r0, 0x18;
  addi r5, r1, 0x10;
  mr r4, r28;
  li r8, 0;
  add r0, r6, r0;
  slwi r0, r0, 2;
  add r5, r5, r0;
  mtctr r21;
lbl_801a4cdc:
  rlwinm r6, r8, 2, 0, 0x1a;
  clrlwi r0, r8, 0x1d;
  subfic r0, r0, 7;
  lwzx r6, r5, r6;
  slwi r0, r0, 2;
  srw r0, r6, r0;
  clrlwi. r9, r0, 0x1c;
  beq lbl_801a4d78;
  lbz r6, 0(r24);
  add r0, r8, r3;
  slwi r12, r0, 1;
  addi r11, r18, -32639;
  mullw r9, r6, r9;
  clrlwi. r0, r4, 0x1f;
  add r6, r29, r12;
  addi r0, r19, -30583;
  mulli r9, r9, 0xef;
  mulhw r11, r11, r9;
  add r9, r11, r9;
  srawi r9, r9, 7;
  srwi r11, r9, 0x1f;
  add r9, r9, r11;
  mulhw r0, r0, r9;
  add r0, r0, r9;
  srawi r0, r0, 3;
  srwi r9, r0, 0x1f;
  add r9, r0, r9;
  addi r0, r9, 0x10;
  stbx r0, r29, r12;
  beq lbl_801a4d68;
  lbz r9, 1(r24);
  lbz r0, 2(r24);
  stb r9, -1(r6);
  stb r0, 1(r6);
  b lbl_801a4d78;
lbl_801a4d68:
  lbz r9, 2(r24);
  lbz r0, 1(r24);
  stb r9, -1(r6);
  stb r0, 1(r6);
lbl_801a4d78:
  addi r4, r4, 1;
  addi r8, r8, 1;
  bdnz lbl_801a4cdc;
  addi r7, r7, 1;
  add r3, r3, r23;
  cmplwi r7, 0x18;
  blt lbl_801a4cb4;
  lwz r3, 8(r1);
  slwi r0, r3, 1;
  add r28, r28, r3;
  add r29, r29, r0;
lbl_801a4da4:
  lbz r3, 0(r10);
  extsb. r0, r3;
  bne lbl_801a4b0c;
lbl_801a4db0:
  addi r11, r1, 0x170;
  bl _restgpr_17;
  lwz r0, 0x174(r1);
  mtlr r0;
  addi r1, r1, 0x170;
  blr;
  // clang-format on
}

// Symbol: ConfigureVideo
// PAL: 0x801a4dc8..0x801a4ec4
MARK_BINARY_BLOB(ConfigureVideo, 0x801a4dc8, 0x801a4ec4);
asm UNKNOWN_FUNCTION(ConfigureVideo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  li r6, 0x1e0;
  li r5, 0x28;
  stw r0, 0x54(r1);
  li r0, 0x280;
  sth r3, 0xc(r1);
  sth r6, 0xe(r1);
  sth r4, 0x10(r1);
  sth r5, 0x12(r1);
  sth r0, 0x16(r1);
  sth r4, 0x18(r1);
  bl VIGetTvFormat;
  cmpwi r3, 2;
  beq lbl_801a4e24;
  bge lbl_801a4e18;
  cmpwi r3, 0;
  beq lbl_801a4e24;
  bge lbl_801a4e80;
  b lbl_801a4e98;
lbl_801a4e18:
  cmpwi r3, 5;
  beq lbl_801a4e64;
  b lbl_801a4e98;
lbl_801a4e24:
  lis r3, 0xcc00;
  lhz r0, 0x206c(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801a4e4c;
  li r0, 0;
  li r3, 2;
  stw r3, 8(r1);
  sth r0, 0x14(r1);
  stw r0, 0x1c(r1);
  b lbl_801a4e98;
lbl_801a4e4c:
  li r3, 0;
  li r0, 1;
  stw r3, 8(r1);
  sth r3, 0x14(r1);
  stw r0, 0x1c(r1);
  b lbl_801a4e98;
lbl_801a4e64:
  li r4, 0x14;
  li r3, 0;
  li r0, 1;
  stw r4, 8(r1);
  sth r3, 0x14(r1);
  stw r0, 0x1c(r1);
  b lbl_801a4e98;
lbl_801a4e80:
  li r4, 4;
  li r3, 0x2f;
  li r0, 1;
  stw r4, 8(r1);
  sth r3, 0x14(r1);
  stw r0, 0x1c(r1);
lbl_801a4e98:
  addi r3, r1, 8;
  bl VIConfigure;
  li r3, 0;
  li r4, 0;
  li r5, 0x280;
  li r6, 0x1e0;
  bl VIConfigurePan;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: OSFatal
// PAL: 0x801a4ec4..0x801a50dc
MARK_BINARY_BLOB(OSFatal, 0x801a4ec4, 0x801a50dc);
asm UNKNOWN_FUNCTION(OSFatal) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  bl OSDisableInterrupts;
  bl OSDisableScheduler;
  lis r24, 0x8034;
  addi r3, r24, 0x7160;
  bl OSClearContext;
  addi r3, r24, 0x7160;
  bl OSSetCurrentContext;
  bl __OSStopAudioSystem;
  bl VIInit;
  li r3, 0x80;
  bl __OSUnmaskInterrupts;
  li r3, 1;
  bl VISetBlack;
  bl VIFlush;
  li r3, 0;
  bl VISetPreRetraceCallback;
  li r3, 0;
  bl VISetPostRetraceCallback;
  bl OSEnableInterrupts;
  bl VIGetRetraceCount;
  mr r24, r3;
lbl_801a4f38:
  bl VIGetRetraceCount;
  subf r0, r24, r3;
  cmpwi r0, 1;
  blt lbl_801a4f38;
  bl OSGetTime;
  lis r5, 0x1062;
  mr r30, r4;
  mr r31, r3;
  lis r25, 0x8000;
  addi r24, r5, 0x4dd3;
  li r26, 0;
lbl_801a4f64:
  li r3, 0;
  li r4, 0;
  bl __OSCallShutdownFunctions;
  cmpwi r3, 0;
  bne lbl_801a4fb4;
  bl OSGetTime;
  lwz r0, 0xf8(r25);
  subfc r6, r30, r4;
  subfe r5, r31, r3;
  xoris r4, r26, 0x8000;
  srwi r0, r0, 2;
  mulhwu r3, r24, r0;
  xoris r0, r5, 0x8000;
  srwi r3, r3, 6;
  mulli r3, r3, 0x3e8;
  subfc r3, r3, r6;
  subfe r4, r4, r0;
  subfe r4, r0, r0;
  neg. r4, r4;
  bne lbl_801a4f64;
lbl_801a4fb4:
  bl OSDisableInterrupts;
  li r3, 1;
  li r4, 0;
  bl __OSCallShutdownFunctions;
  li r3, 0;
  li r4, 0;
  bl EXISetExiCallback;
  li r3, 2;
  li r4, 0;
  bl EXISetExiCallback;
  b lbl_801a4ff8;
lbl_801a4fe0:
  li r3, 0;
  bl EXISync;
  li r3, 0;
  bl EXIDeselect;
  li r3, 0;
  bl EXIUnlock;
lbl_801a4ff8:
  li r3, 0;
  li r4, 1;
  li r5, 0;
  bl EXILock;
  cmpwi r3, 0;
  beq lbl_801a4fe0;
  li r3, 0;
  bl EXIUnlock;
  lis r3, 0xcd00;
lbl_801a501c:
  lwz r0, 0x680c(r3);
  clrlwi r0, r0, 0x1f;
  cmplwi r0, 1;
  beq lbl_801a501c;
  lis r4, 0x801a;
  li r3, 8;
  addi r4, r4, 0x448;
  bl __OSSetExceptionHandler;
  bl GXAbortFrame;
  lis r3, 0x8140;
  bl OSSetArenaLo;
  lis r4, 0x8000;
  lwz r3, 0x38(r4);
  cmpwi r3, 0;
  bne lbl_801a5064;
  lwz r3, 0x3110(r4);
  bl OSSetArenaHi;
  b lbl_801a5068;
lbl_801a5064:
  bl OSSetArenaHi;
lbl_801a5068:
  lbz r9, 0(r27);
  lis r10, 0x8034;
  lbz r8, 1(r27);
  stbu r9, 0x7428(r10);
  lbz r7, 2(r27);
  lbz r6, 3(r27);
  lbz r5, 0(r28);
  lbz r4, 1(r28);
  lbz r3, 2(r28);
  lbz r0, 3(r28);
  stb r8, 1(r10);
  stb r7, 2(r10);
  stb r6, 3(r10);
  stb r5, 4(r10);
  stb r4, 5(r10);
  stb r3, 6(r10);
  stb r0, 7(r10);
  stw r29, 8(r10);
  bl OSGetArenaHi;
  lis r5, 0x801a;
  mr r4, r3;
  addi r3, r5, 0x50dc;
  bl OSSwitchFiber;
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: Halt
// PAL: 0x801a50dc..0x801a56dc
MARK_BINARY_BLOB(Halt, 0x801a50dc, 0x801a56dc);
asm UNKNOWN_FUNCTION(Halt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  lis r0, 0x4330;
  stw r31, 0x4c(r1);
  stw r30, 0x48(r1);
  stw r29, 0x44(r1);
  stw r28, 0x40(r1);
  stw r0, 0x20(r1);
  stw r0, 0x28(r1);
  bl OSEnableInterrupts;
  lis r29, 0x8034;
  addi r29, r29, 0x7428;
  lwz r28, 8(r29);
  mr r3, r28;
  bl strlen;
  addi r30, r3, 1;
  li r4, 0x20;
  mr r3, r30;
  bl OSAllocFromMEM1ArenaLo;
  mr r4, r28;
  mr r5, r30;
  bl memmove;
  stw r3, 8(r29);
  lis r3, 0xa;
  addi r3, r3, 0x1004;
  li r4, 0x20;
  bl OSAllocFromMEM1ArenaLo;
  mr r31, r3;
  bl OSGetArenaLo;
  mr r4, r3;
  mr r3, r31;
  bl OSLoadFont;
  lis r3, 9;
  li r4, 0x20;
  addi r3, r3, 0x6000;
  bl OSAllocFromMEM1ArenaLo;
  lbz r4, 6(r29);
  mr r30, r3;
  lbz r5, 4(r29);
  stw r4, 0x24(r1);
  lbz r3, 5(r29);
  stw r5, 0x2c(r1);
  lfd f4, 0x20(r1);
  lfd f2, 0x28(r1);
  lfd f0, 4503599627370496.0;
  stw r3, 0x24(r1);
  fsubs f3, f2, f0;
  lfs f2, 0.257f;
  lfd f1, 0x20(r1);
  fsubs f7, f4, f0;
  stw r4, 0x2c(r1);
  fsubs f5, f1, f0;
  lfd f1, 0x28(r1);
  fmuls f6, f2, f3;
  stw r5, 0x24(r1);
  lfs f4, 0.504f;
  fsubs f3, f1, f0;
  lfd f2, 0x20(r1);
  fmuls f4, f4, f5;
  stw r3, 0x2c(r1);
  lfs f5, 0.098f;
  fsubs f9, f2, f0;
  lfd f1, 0x28(r1);
  fmuls f13, f5, f7;
  lfs f11, 0.439f;
  fadds f12, f6, f4;
  lfs f8, -0.148f;
  fsubs f7, f1, f0;
  stw r5, 0x24(r1);
  fmuls f10, f11, f3;
  lfs f6, 0.291f;
  lfd f1, 0x20(r1);
  fmuls f8, f8, f9;
  fmuls f6, f6, f7;
  stw r3, 0x2c(r1);
  fsubs f5, f1, f0;
  lfd f1, 0x28(r1);
  stw r4, 0x24(r1);
  fsubs f4, f1, f0;
  lfs f3, 0.368f;
  lfd f2, 0x20(r1);
  fmuls f5, f11, f5;
  lfs f1, 0.071f;
  fsubs f0, f2, f0;
  fmuls f2, f3, f4;
  lbz r0, 7(r29);
  fadds f3, f13, f12;
  fsubs f4, f8, f6;
  lfs f9, 16.0f;
  fsubs f2, f5, f2;
  fmuls f0, f1, f0;
  lfs f5, 0.5f;
  fadds f6, f9, f3;
  fadds f1, f10, f4;
  lfs f3, 128.0f;
  fsubs f0, f2, f0;
  fadds f4, f5, f6;
  lfs f7, 235.0f;
  fadds f1, f3, f1;
  fadds f0, f3, f0;
  stb r5, 0x18(r1);
  fcmpo cr0, f4, f7;
  fadds f2, f5, f1;
  stb r3, 0x19(r1);
  fadds f1, f5, f0;
  stb r4, 0x1a(r1);
  stb r0, 0x1b(r1);
  ble lbl_801a5294;
  b lbl_801a52a8;
lbl_801a5294:
  fcmpo cr0, f4, f9;
  bge lbl_801a52a0;
  b lbl_801a52a4;
lbl_801a52a0:
  fmr f9, f4;
lbl_801a52a4:
  fmr f7, f9;
lbl_801a52a8:
  fctiwz f0, f7;
  lfs f3, 240.0f;
  fcmpo cr0, f2, f3;
  stfd f0, 0x30(r1);
  lwz r0, 0x34(r1);
  stb r0, 0xc(r1);
  ble lbl_801a52c8;
  b lbl_801a52dc;
lbl_801a52c8:
  lfs f3, 16.0f;
  fcmpo cr0, f2, f3;
  bge lbl_801a52d8;
  b lbl_801a52dc;
lbl_801a52d8:
  fmr f3, f2;
lbl_801a52dc:
  fctiwz f0, f3;
  lfs f2, 240.0f;
  fcmpo cr0, f1, f2;
  stfd f0, 0x30(r1);
  lwz r0, 0x34(r1);
  stb r0, 0xd(r1);
  ble lbl_801a52fc;
  b lbl_801a5310;
lbl_801a52fc:
  lfs f2, 16.0f;
  fcmpo cr0, f1, f2;
  bge lbl_801a530c;
  b lbl_801a5310;
lbl_801a530c:
  fmr f2, f1;
lbl_801a5310:
  fctiwz f0, f2;
  li r0, 0;
  stb r0, 0xf(r1);
  mr r4, r30;
  li r5, 0;
  li r0, 0x14;
  stfd f0, 0x30(r1);
  lwz r3, 0x34(r1);
  stb r3, 0xe(r1);
  lwz r3, 0xc(r1);
  stw r3, 0x1c(r1);
  lbz r6, 0x1d(r1);
  lbz r7, 0x1e(r1);
  lbz r3, 0x1c(r1);
lbl_801a5348:
  mtctr r0;
lbl_801a534c:
  stb r3, 0(r4);
  stb r6, 1(r4);
  stb r3, 2(r4);
  stb r7, 3(r4);
  stb r3, 4(r4);
  stb r6, 5(r4);
  stb r3, 6(r4);
  stb r7, 7(r4);
  stb r3, 8(r4);
  stb r6, 9(r4);
  stb r3, 0xa(r4);
  stb r7, 0xb(r4);
  stb r3, 0xc(r4);
  stb r6, 0xd(r4);
  stb r3, 0xe(r4);
  stb r7, 0xf(r4);
  stb r3, 0x10(r4);
  stb r6, 0x11(r4);
  stb r3, 0x12(r4);
  stb r7, 0x13(r4);
  stb r3, 0x14(r4);
  stb r6, 0x15(r4);
  stb r3, 0x16(r4);
  stb r7, 0x17(r4);
  stb r3, 0x18(r4);
  stb r6, 0x19(r4);
  stb r3, 0x1a(r4);
  stb r7, 0x1b(r4);
  stb r3, 0x1c(r4);
  stb r6, 0x1d(r4);
  stb r3, 0x1e(r4);
  stb r7, 0x1f(r4);
  stb r3, 0x20(r4);
  stb r6, 0x21(r4);
  stb r3, 0x22(r4);
  stb r7, 0x23(r4);
  stb r3, 0x24(r4);
  stb r6, 0x25(r4);
  stb r3, 0x26(r4);
  stb r7, 0x27(r4);
  stb r3, 0x28(r4);
  stb r6, 0x29(r4);
  stb r3, 0x2a(r4);
  stb r7, 0x2b(r4);
  stb r3, 0x2c(r4);
  stb r6, 0x2d(r4);
  stb r3, 0x2e(r4);
  stb r7, 0x2f(r4);
  stb r3, 0x30(r4);
  stb r6, 0x31(r4);
  stb r3, 0x32(r4);
  stb r7, 0x33(r4);
  stb r3, 0x34(r4);
  stb r6, 0x35(r4);
  stb r3, 0x36(r4);
  stb r7, 0x37(r4);
  stb r3, 0x38(r4);
  stb r6, 0x39(r4);
  stb r3, 0x3a(r4);
  stb r7, 0x3b(r4);
  stb r3, 0x3c(r4);
  stb r6, 0x3d(r4);
  stb r3, 0x3e(r4);
  stb r7, 0x3f(r4);
  addi r4, r4, 0x40;
  bdnz lbl_801a534c;
  addi r5, r5, 1;
  cmpwi r5, 0x1e0;
  blt lbl_801a5348;
  mr r3, r30;
  bl VISetNextFrameBuffer;
  li r3, 0x280;
  li r4, 0x1e0;
  bl ConfigureVideo;
  bl VIFlush;
  bl VIGetRetraceCount;
  mr r28, r3;
lbl_801a5480:
  bl VIGetRetraceCount;
  subf r0, r28, r3;
  cmpwi r0, 2;
  blt lbl_801a5480;
  lbz r3, 2(r29);
  lbz r5, 0(r29);
  stw r3, 0x2c(r1);
  lbz r4, 1(r29);
  stw r5, 0x24(r1);
  lfd f4, 0x28(r1);
  lfd f2, 0x20(r1);
  lfd f0, 4503599627370496.0;
  stw r4, 0x2c(r1);
  fsubs f3, f2, f0;
  lfs f2, 0.257f;
  lfd f1, 0x28(r1);
  fsubs f7, f4, f0;
  stw r3, 0x24(r1);
  fsubs f5, f1, f0;
  lfd f1, 0x20(r1);
  fmuls f6, f2, f3;
  stw r5, 0x2c(r1);
  lfs f4, 0.504f;
  fsubs f3, f1, f0;
  lfd f2, 0x28(r1);
  fmuls f4, f4, f5;
  stw r4, 0x24(r1);
  lfs f5, 0.098f;
  fsubs f9, f2, f0;
  lfd f1, 0x20(r1);
  fmuls f13, f5, f7;
  lfs f11, 0.439f;
  fadds f12, f6, f4;
  lfs f8, -0.148f;
  fsubs f7, f1, f0;
  stw r5, 0x2c(r1);
  fmuls f10, f11, f3;
  lfs f6, 0.291f;
  lfd f1, 0x28(r1);
  fmuls f8, f8, f9;
  fmuls f6, f6, f7;
  stw r4, 0x24(r1);
  fsubs f5, f1, f0;
  lfd f1, 0x20(r1);
  stw r3, 0x2c(r1);
  fsubs f4, f1, f0;
  lfs f3, 0.368f;
  lfd f2, 0x28(r1);
  fmuls f5, f11, f5;
  lfs f1, 0.071f;
  fsubs f0, f2, f0;
  fmuls f2, f3, f4;
  lbz r0, 3(r29);
  fadds f3, f13, f12;
  fsubs f4, f8, f6;
  lfs f9, 16.0f;
  fsubs f2, f5, f2;
  fmuls f0, f1, f0;
  lfs f5, 0.5f;
  fadds f6, f9, f3;
  fadds f1, f10, f4;
  lfs f3, 128.0f;
  fsubs f0, f2, f0;
  fadds f4, f5, f6;
  lfs f7, 235.0f;
  fadds f1, f3, f1;
  fadds f0, f3, f0;
  stb r5, 0x10(r1);
  fcmpo cr0, f4, f7;
  fadds f2, f5, f1;
  stb r4, 0x11(r1);
  fadds f1, f5, f0;
  stb r3, 0x12(r1);
  stb r0, 0x13(r1);
  ble lbl_801a55b0;
  b lbl_801a55c4;
lbl_801a55b0:
  fcmpo cr0, f4, f9;
  bge lbl_801a55bc;
  b lbl_801a55c0;
lbl_801a55bc:
  fmr f9, f4;
lbl_801a55c0:
  fmr f7, f9;
lbl_801a55c4:
  fctiwz f0, f7;
  lfs f3, 240.0f;
  fcmpo cr0, f2, f3;
  stfd f0, 0x30(r1);
  lwz r0, 0x34(r1);
  stb r0, 8(r1);
  ble lbl_801a55e4;
  b lbl_801a55f8;
lbl_801a55e4:
  lfs f3, 16.0f;
  fcmpo cr0, f2, f3;
  bge lbl_801a55f4;
  b lbl_801a55f8;
lbl_801a55f4:
  fmr f3, f2;
lbl_801a55f8:
  fctiwz f0, f3;
  lfs f2, 240.0f;
  fcmpo cr0, f1, f2;
  stfd f0, 0x30(r1);
  lwz r0, 0x34(r1);
  stb r0, 9(r1);
  ble lbl_801a5618;
  b lbl_801a562c;
lbl_801a5618:
  lfs f2, 16.0f;
  fcmpo cr0, f1, f2;
  bge lbl_801a5628;
  b lbl_801a562c;
lbl_801a5628:
  fmr f2, f1;
lbl_801a562c:
  fctiwz f0, f2;
  li r0, 0;
  stb r0, 0xb(r1);
  mr r3, r30;
  lwz r10, 8(r29);
  addi r6, r1, 0x14;
  stfd f0, 0x30(r1);
  li r4, 0x280;
  li r5, 0x1e0;
  li r7, 0x30;
  lwz r0, 0x34(r1);
  li r8, 0x64;
  stb r0, 0xa(r1);
  lwz r0, 8(r1);
  stw r0, 0x14(r1);
  lhz r9, 0xe(r31);
  bl ScreenReport;
  lis r4, 9;
  mr r3, r30;
  addi r4, r4, 0x6000;
  bl DCFlushRange;
  li r3, 0;
  bl VISetBlack;
  bl VIFlush;
  bl VIGetRetraceCount;
  mr r30, r3;
lbl_801a5694:
  bl VIGetRetraceCount;
  subf r0, r30, r3;
  cmpwi r0, 1;
  blt lbl_801a5694;
  bl OSDisableInterrupts;
  lwz r4, 8(r29);
  la r3, _unk_80385ac8;
  crclr 6;
  bl OSReport;
  bl PPCHalt;
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  lwz r30, 0x48(r1);
  lwz r29, 0x44(r1);
  lwz r28, 0x40(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}
