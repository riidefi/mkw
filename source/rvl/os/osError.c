#include "osError.h"

#include <rvl/base/ppcArch.h>
#include <string.h>

#include "os.h"
#include "osContext.h"
#include "osInterrupt.h"
#include "osThread.h"

u32 _unk_80385aa8 = 0xf8;

// Symbol: OSReport
// PAL: 0x801a25d0..0x801a265c
MARK_BINARY_BLOB(OSReport, 0x801a25d0, 0x801a265c);
asm void OSReport(const char* msg, ...) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  bne cr1, lbl_801a2604;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_801a2604:
  addi r11, r1, 0x88;
  addi r0, r1, 8;
  lis r12, 0x100;
  stw r3, 8(r1);
  addi r31, r1, 0x68;
  stw r4, 0xc(r1);
  mr r4, r31;
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  stw r12, 0x68(r1);
  stw r11, 0x6c(r1);
  stw r0, 0x70(r1);
  bl vprintf;
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: OSVReport
// PAL: 0x801a265c..0x801a2660
void OSVReport(const char* msg, va_list arg) { vprintf(msg, arg); }

// Symbol: OSPanic
// PAL: 0x801a2660..0x801a278c
MARK_BINARY_BLOB(OSPanic, 0x801a2660, 0x801a278c);
asm void OSPanic(const char* file, int line, const char* msg, ...) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  stw r30, 0x88(r1);
  mr r30, r4;
  stw r29, 0x84(r1);
  mr r29, r5;
  stw r28, 0x80(r1);
  mr r28, r3;
  bne cr1, lbl_801a26ac;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_801a26ac:
  lis r31, 0x8029;
  stw r3, 8(r1);
  addi r31, r31, -2816;
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  bl OSDisableInterrupts;
  addi r5, r1, 0x98;
  addi r0, r1, 8;
  lis r3, 0x300;
  stw r5, 0x6c(r1);
  addi r4, r1, 0x68;
  stw r3, 0x68(r1);
  mr r3, r29;
  stw r0, 0x70(r1);
  bl vprintf;
  mr r4, r28;
  mr r5, r30;
  addi r3, r31, 0;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x18;
  crclr 6;
  bl OSReport;
  li r30, 0;
  bl OSGetStackPointer;
  mr r29, r3;
  b lbl_801a2748;
lbl_801a272c:
  lwz r5, 0(r29);
  mr r4, r29;
  lwz r6, 4(r29);
  addi r3, r31, 0x40;
  crclr 6;
  bl OSReport;
  lwz r29, 0(r29);
lbl_801a2748:
  cmpwi r29, 0;
  beq lbl_801a2768;
  addis r0, r29, 1;
  cmplwi r0, 0xffff;
  beq lbl_801a2768;
  cmplwi r30, 0x10;
  addi r30, r30, 1;
  blt lbl_801a272c;
lbl_801a2768:
  bl PPCHalt;
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  lwz r30, 0x88(r1);
  lwz r29, 0x84(r1);
  lwz r28, 0x80(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: OSSetErrorHandler
// PAL: 0x801a278c..0x801a2a14
MARK_BINARY_BLOB(OSSetErrorHandler, 0x801a278c, 0x801a2a14);
asm OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  mr r28, r4;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  rlwinm r0, r29, 2, 0xe, 0x1d;
  addi r4, r4, 0x70f0;
  cmplwi r29, 0x10;
  lwzx r30, r4, r0;
  mr r29, r3;
  stwx r28, r4, r0;
  bne lbl_801a29e8;
  bl PPCMfmsr;
  mr r31, r3;
  ori r3, r3, 0x2000;
  bl PPCMtmsr;
  bl PPCMffpscr;
  cmpwi r28, 0;
  beq lbl_801a2984;
  lis r5, 0x8000;
  lis r4, 0x6006;
  lwz r9, 0xdc(r5);
  addi r5, r4, -1793;
  li r8, -1;
  li r7, 4;
  li r0, 2;
  b lbl_801a2968;
lbl_801a2810:
  lwz r4, 0x19c(r9);
  ori r4, r4, 0x900;
  stw r4, 0x19c(r9);
  lhz r6, 0x1a2(r9);
  clrlwi. r4, r6, 0x1f;
  bne lbl_801a294c;
  ori r4, r6, 1;
  addi r6, r9, 0x90;
  sth r4, 0x1a2(r9);
  addi r4, r9, 0x1c8;
  mtctr r0;
lbl_801a283c:
  stw r8, 4(r6);
  stw r8, 0(r6);
  stw r8, 4(r4);
  stw r8, 0(r4);
  stw r8, 0xc(r6);
  stw r8, 8(r6);
  stw r8, 0xc(r4);
  stw r8, 8(r4);
  stw r8, 0x14(r6);
  stw r8, 0x10(r6);
  stw r8, 0x14(r4);
  stw r8, 0x10(r4);
  stw r8, 0x1c(r6);
  stw r8, 0x18(r6);
  stw r8, 0x1c(r4);
  stw r8, 0x18(r4);
  stw r8, 0x24(r6);
  stw r8, 0x20(r6);
  stw r8, 0x24(r4);
  stw r8, 0x20(r4);
  stw r8, 0x2c(r6);
  stw r8, 0x28(r6);
  stw r8, 0x2c(r4);
  stw r8, 0x28(r4);
  stw r8, 0x34(r6);
  stw r8, 0x30(r6);
  stw r8, 0x34(r4);
  stw r8, 0x30(r4);
  stw r8, 0x3c(r6);
  stw r8, 0x38(r6);
  stw r8, 0x3c(r4);
  stw r8, 0x38(r4);
  stw r8, 0x44(r6);
  stw r8, 0x40(r6);
  stw r8, 0x44(r4);
  stw r8, 0x40(r4);
  stw r8, 0x4c(r6);
  stw r8, 0x48(r6);
  stw r8, 0x4c(r4);
  stw r8, 0x48(r4);
  stw r8, 0x54(r6);
  stw r8, 0x50(r6);
  stw r8, 0x54(r4);
  stw r8, 0x50(r4);
  stw r8, 0x5c(r6);
  stw r8, 0x58(r6);
  stw r8, 0x5c(r4);
  stw r8, 0x58(r4);
  stw r8, 0x64(r6);
  stw r8, 0x60(r6);
  stw r8, 0x64(r4);
  stw r8, 0x60(r4);
  stw r8, 0x6c(r6);
  stw r8, 0x68(r6);
  stw r8, 0x6c(r4);
  stw r8, 0x68(r4);
  stw r8, 0x74(r6);
  stw r8, 0x70(r6);
  stw r8, 0x74(r4);
  stw r8, 0x70(r4);
  stw r8, 0x7c(r6);
  stw r8, 0x78(r6);
  addi r6, r6, 0x80;
  stw r8, 0x7c(r4);
  stw r8, 0x78(r4);
  addi r4, r4, 0x80;
  bdnz lbl_801a283c;
  stw r7, 0x194(r9);
lbl_801a294c:
  lwz r4, _unk_80385aa8;
  lwz r6, 0x194(r9);
  rlwinm r4, r4, 0, 0x18, 0x1c;
  or r4, r6, r4;
  and r4, r4, r5;
  stw r4, 0x194(r9);
  lwz r9, 0x2fc(r9);
lbl_801a2968:
  cmpwi r9, 0;
  bne lbl_801a2810;
  lwz r0, _unk_80385aa8;
  ori r31, r31, 0x900;
  rlwinm r0, r0, 0, 0x18, 0x1c;
  or r4, r3, r0;
  b lbl_801a29d0;
lbl_801a2984:
  lis r5, 0x8000;
  lis r4, 0x6006;
  lwz r6, 0xdc(r5);
  addi r4, r4, -1793;
  li r5, -2305;
  b lbl_801a29bc;
lbl_801a299c:
  lwz r0, 0x19c(r6);
  and r0, r0, r5;
  stw r0, 0x19c(r6);
  lwz r0, 0x194(r6);
  rlwinm r0, r0, 0, 0x1d, 0x17;
  and r0, r0, r4;
  stw r0, 0x194(r6);
  lwz r6, 0x2fc(r6);
lbl_801a29bc:
  cmpwi r6, 0;
  bne lbl_801a299c;
  li r0, -2305;
  rlwinm r4, r3, 0, 0x1d, 0x17;
  and r31, r31, r0;
lbl_801a29d0:
  lis r3, 0x6006;
  addi r0, r3, -1793;
  and r3, r4, r0;
  bl PPCMtfpscr;
  mr r3, r31;
  bl PPCMtmsr;
lbl_801a29e8:
  mr r3, r29;
  bl OSRestoreInterrupts;
  mr r3, r30;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSUnhandledException
// PAL: 0x801a2a14..0x801a2e84
MARK_BINARY_BLOB(__OSUnhandledException, 0x801a2a14, 0x801a2e84);
asm void __OSUnhandledException(u8, OSContext*, u32, u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lis r31, 0x8029;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  addi r31, r31, -2816;
  bl OSGetTime;
  lwz r5, 0x19c(r26);
  mr r29, r4;
  mr r30, r3;
  rlwinm. r0, r5, 0, 0x1e, 0x1e;
  bne lbl_801a2a6c;
  mr r4, r25;
  addi r3, r31, 0x5c;
  crclr 6;
  bl OSReport;
  b lbl_801a2bc8;
lbl_801a2a6c:
  cmplwi r25, 6;
  bne lbl_801a2b5c;
  rlwinm. r0, r5, 0, 0xb, 0xb;
  beq lbl_801a2b5c;
  lis r3, 0x8034;
  addi r3, r3, 0x70f0;
  lwz r0, 0x40(r3);
  cmpwi r0, 0;
  beq lbl_801a2b5c;
  li r25, 0x10;
  bl PPCMfmsr;
  mr r23, r3;
  ori r3, r3, 0x2000;
  bl PPCMtmsr;
  lis r3, 0x8000;
  lwz r3, 0xd8(r3);
  cmpwi r3, 0;
  beq lbl_801a2ab8;
  bl OSSaveFPUContext;
lbl_801a2ab8:
  bl PPCMffpscr;
  lis r24, 0x6006;
  addi r0, r24, -1793;
  and r3, r3, r0;
  bl PPCMtfpscr;
  mr r3, r23;
  bl PPCMtmsr;
  lis r23, 0x8000;
  lwz r0, 0xd8(r23);
  cmplw r0, r26;
  bne lbl_801a2b40;
  bl OSDisableScheduler;
  mr r4, r26;
  mr r5, r27;
  mr r6, r28;
  li r3, 0x10;
  crclr 6;
  lis r7, 0x8034;
  addi r7, r7, 0x70f0;
  lwz r12, 0x40(r7);
  mtctr r12;
  bctrl;
  lwz r4, 0x19c(r26);
  li r3, 0;
  addi r0, r24, -1793;
  rlwinm r4, r4, 0, 0x13, 0x11;
  stw r4, 0x19c(r26);
  stw r3, 0xd8(r23);
  lwz r3, 0x194(r26);
  and r0, r3, r0;
  stw r0, 0x194(r26);
  bl OSEnableScheduler;
  bl __OSReschedule;
  b lbl_801a2b54;
lbl_801a2b40:
  lwz r3, 0x19c(r26);
  li r0, 0;
  rlwinm r3, r3, 0, 0x13, 0x11;
  stw r3, 0x19c(r26);
  stw r0, 0xd8(r23);
lbl_801a2b54:
  mr r3, r26;
  bl OSLoadContext;
lbl_801a2b5c:
  lis r24, 0x8034;
  rlwinm r23, r25, 2, 0x16, 0x1d;
  addi r24, r24, 0x70f0;
  lwzx r0, r24, r23;
  cmpwi r0, 0;
  beq lbl_801a2ba8;
  bl OSDisableScheduler;
  mr r3, r25;
  mr r4, r26;
  mr r5, r27;
  mr r6, r28;
  crclr 6;
  lwzx r12, r24, r23;
  mtctr r12;
  bctrl;
  bl OSEnableScheduler;
  bl __OSReschedule;
  mr r3, r26;
  bl OSLoadContext;
lbl_801a2ba8:
  cmplwi r25, 8;
  bne lbl_801a2bb8;
  mr r3, r26;
  bl OSLoadContext;
lbl_801a2bb8:
  mr r4, r25;
  addi r3, r31, 0x7c;
  crclr 6;
  bl OSReport;
lbl_801a2bc8:
  addi r3, r13, -29012;
  crclr 6;
  bl OSReport;
  mr r3, r26;
  bl OSDumpContext;
  mr r4, r27;
  mr r5, r28;
  addi r3, r31, 0x94;
  crclr 6;
  bl OSReport;
  mr r6, r29;
  mr r5, r30;
  addi r3, r31, 0xc8;
  crclr 6;
  bl OSReport;
  cmplwi r25, 0xf;
  bgt lbl_801a2ccc;
  lis r3, 0x8029;
  slwi r0, r25, 2;
  addi r3, r3, -2084;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lwz r4, 0x198(r26);
  mr r5, r28;
  addi r3, r31, 0xd8;
  crclr 6;
  bl OSReport;
  b lbl_801a2ccc;
  lwz r4, 0x198(r26);
  addi r3, r31, 0x138;
  crclr 6;
  bl OSReport;
  b lbl_801a2ccc;
  lwz r4, 0x198(r26);
  mr r5, r28;
  addi r3, r31, 0x184;
  crclr 6;
  bl OSReport;
  b lbl_801a2ccc;
  lwz r4, 0x198(r26);
  mr r5, r28;
  addi r3, r31, 0x1e8;
  crclr 6;
  bl OSReport;
  b lbl_801a2ccc;
  addi r3, r13, -29012;
  crclr 6;
  bl OSReport;
  lis r25, 0xcc00;
  addi r3, r31, 0x248;
  lhz r4, 0x5030(r25);
  lhz r5, 0x5032(r25);
  crclr 6;
  bl OSReport;
  lhz r4, 0x5020(r25);
  addi r3, r31, 0x268;
  lhz r5, 0x5022(r25);
  crclr 6;
  bl OSReport;
  lis r4, 0xcd00;
  addi r3, r31, 0x288;
  lwz r4, 0x6014(r4);
  crclr 6;
  bl OSReport;
lbl_801a2ccc:
  lha r4, -0x6314(r13);
  addi r3, r31, 0x2a4;
  lwz r5, -0x6318(r13);
  lwz r7, __OSLastInterruptTime@hiword;
  lwz r8, -0x630c(r13);
  crclr 6;
  bl OSReport;
  bl PPCHalt;
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

asm void PackArgs() {
  // clang-format off
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r25, r4;
  mr r29, r5;
  mr r30, r3;
  li r4, 0;
  li r5, 0x2000;
  bl memset;
  cmpwi r25, 0;
  bne lbl_801a2d44;
  li r0, 0;
  stw r0, 8(r30);
  b lbl_801a2e68;
lbl_801a2d44:
  slwi r0, r25, 2;
  mr r31, r25;
  addi r26, r30, 0x2000;
  add r28, r29, r0;
  b lbl_801a2d80;
lbl_801a2d58:
  lwz r27, 0(r28);
  mr r3, r27;
  bl strlen;
  addi r0, r3, 1;
  mr r4, r27;
  subf r26, r0, r26;
  mr r3, r26;
  bl strcpy;
  subf r0, r30, r26;
  stw r0, 0(r28);
lbl_801a2d80:
  addic. r25, r25, -1;
  addi r28, r28, -4;
  bge lbl_801a2d58;
  addic. r3, r31, 1;
  subf r0, r30, r26;
  rlwinm r4, r0, 0, 0, 0x1d;
  li r7, 0;
  add r6, r30, r4;
  slwi r0, r3, 2;
  subf r6, r0, r6;
  beq lbl_801a2e58;
  cmplwi r3, 8;
  addi r3, r31, -7;
  ble lbl_801a2e24;
  addi r0, r3, 7;
  mr r4, r29;
  srwi r0, r0, 3;
  mr r5, r6;
  mtctr r0;
  cmplwi r3, 0;
  ble lbl_801a2e24;
lbl_801a2dd4:
  lwz r0, 0(r4);
  addi r7, r7, 8;
  stw r0, 0(r5);
  lwz r0, 4(r4);
  stw r0, 4(r5);
  lwz r0, 8(r4);
  stw r0, 8(r5);
  lwz r0, 0xc(r4);
  stw r0, 0xc(r5);
  lwz r0, 0x10(r4);
  stw r0, 0x10(r5);
  lwz r0, 0x14(r4);
  stw r0, 0x14(r5);
  lwz r0, 0x18(r4);
  stw r0, 0x18(r5);
  lwz r0, 0x1c(r4);
  addi r4, r4, 0x20;
  stw r0, 0x1c(r5);
  addi r5, r5, 0x20;
  bdnz lbl_801a2dd4;
lbl_801a2e24:
  addi r3, r31, 1;
  slwi r5, r7, 2;
  subf r0, r7, r3;
  add r4, r29, r5;
  add r5, r6, r5;
  mtctr r0;
  cmplw r7, r3;
  bge lbl_801a2e58;
lbl_801a2e44:
  lwz r0, 0(r4);
  addi r4, r4, 4;
  stw r0, 0(r5);
  addi r5, r5, 4;
  bdnz lbl_801a2e44;
lbl_801a2e58:
  addi r0, r6, -4;
  stw r31, -4(r6);
  subf r0, r30, r0;
  stw r0, 8(r30);
lbl_801a2e68:
  addi r11, r1, 0x30;
  li r3, 1;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
