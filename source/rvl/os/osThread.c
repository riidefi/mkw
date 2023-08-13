#include "osThread.h"

#include "os.h"
#include "osAlarm.h"
#include "osError.h"
#include "osContext.h"
#include "osInterrupt.h"

// Extern function references.
// PAL: 0x801a8088
extern UNKNOWN_FUNCTION(__OSUnlockAllMutex);

u32 _unk_80385ae0 = 0x801a95a8;

u32 _unk_80386920;
u32 _unk_8038691c;
u32 _unk_80386918;

// Symbol: OSSetSwitchThreadCallback
// PAL: 0x801a95ac..0x801a961c
MARK_BINARY_BLOB(OSSetSwitchThreadCallback, 0x801a95ac, 0x801a961c);
asm OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  cmpwi r30, 0;
  lwz r31, _unk_80385ae0;
  beq lbl_801a95d8;
  b lbl_801a95e0;
lbl_801a95d8:
  lis r30, 0x801b;
  addi r30, r30, -27224;
lbl_801a95e0:
  stw r30, _unk_80385ae0;
  bl OSRestoreInterrupts;
  lis r3, 0x801b;
  addi r3, r3, -27224;
  cmplw r31, r3;
  bne lbl_801a9600;
  li r3, 0;
  b lbl_801a9604;
lbl_801a9600:
  mr r3, r31;
lbl_801a9604:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSThreadInit
// PAL: 0x801a961c..0x801a98a0
MARK_BINARY_BLOB(__OSThreadInit, 0x801a961c, 0x801a98a0);
asm UNKNOWN_FUNCTION(__OSThreadInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r3, 2;
  li r6, 1;
  stw r0, 0x24(r1);
  li r4, 0;
  li r5, 0x10;
  li r0, -1;
  stw r31, 0x1c(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x7498;
  stw r30, 0x18(r1);
  addi r30, r31, 0;
  stw r29, 0x14(r1);
  lis r29, 0x8000;
  sth r3, 0x2c8(r30);
  mr r3, r30;
  sth r6, 0x2ca(r30);
  stw r5, 0x2d4(r30);
  stw r5, 0x2d0(r30);
  stw r4, 0x2cc(r30);
  stw r0, 0x2d8(r30);
  stw r4, 0x2f0(r30);
  stw r4, 0x2ec(r30);
  stw r4, 0x2e8(r30);
  stw r4, 0x2f8(r30);
  stw r4, 0x2f4(r30);
  stw r30, 0xd8(r29);
  bl OSClearContext;
  mr r3, r30;
  bl OSSetCurrentContext;
  lis r4, 0x803a;
  lis r5, 0x8039;
  addi r4, r4, -28288;
  lis r3, 0xdeae;
  addi r5, r5, -28292;
  stw r4, 0x304(r30);
  addi r0, r3, -17730;
  mr r4, r30;
  stw r5, 0x308(r30);
  stw r0, 0(r5);
  lwz r12, _unk_80385ae0;
  lwz r3, 0xe4(r29);
  mtctr r12;
  bctrl;
  stw r30, 0xe4(r29);
  bl OSGetStackPointer;
  lwz r4, 0xe4(r29);
  lwz r4, 0x308(r4);
  addi r8, r4, 4;
  cmplw cr1, r8, r3;
  bge cr1, lbl_801a97a8;
  subf r5, r8, r3;
  addi r6, r3, -32;
  addi r4, r5, 3;
  srawi r0, r4, 2;
  addze r0, r0;
  cmpwi r0, 8;
  ble lbl_801a9780;
  li r7, 0;
  bgt cr1, lbl_801a9734;
  rlwinm. r0, r5, 0, 0, 0;
  li r5, 1;
  bne lbl_801a9728;
  rlwinm. r0, r4, 0, 0, 0;
  beq lbl_801a9728;
  li r5, 0;
lbl_801a9728:
  cmpwi r5, 0;
  beq lbl_801a9734;
  li r7, 1;
lbl_801a9734:
  cmpwi r7, 0;
  beq lbl_801a9780;
  addi r0, r6, 0x1f;
  li r4, 0;
  subf r0, r8, r0;
  srwi r0, r0, 5;
  mtctr r0;
  cmplw r8, r6;
  bge lbl_801a9780;
lbl_801a9758:
  stw r4, 0(r8);
  stw r4, 4(r8);
  stw r4, 8(r8);
  stw r4, 0xc(r8);
  stw r4, 0x10(r8);
  stw r4, 0x14(r8);
  stw r4, 0x18(r8);
  stw r4, 0x1c(r8);
  addi r8, r8, 0x20;
  bdnz lbl_801a9758;
lbl_801a9780:
  addi r0, r3, 3;
  li r4, 0;
  subf r0, r8, r0;
  srwi r0, r0, 2;
  mtctr r0;
  cmplw r8, r3;
  bge lbl_801a97a8;
lbl_801a979c:
  stw r4, 0(r8);
  addi r8, r8, 4;
  bdnz lbl_801a979c;
lbl_801a97a8:
  li r3, 0;
  li r0, 2;
  stw r3, _unk_80386920;
  addi r4, r31, 0x318;
  stw r3, _unk_8038691c;
  mtctr r0;
lbl_801a97c0:
  stw r3, 4(r4);
  stw r3, 0(r4);
  stw r3, 0xc(r4);
  stw r3, 8(r4);
  stw r3, 0x14(r4);
  stw r3, 0x10(r4);
  stw r3, 0x1c(r4);
  stw r3, 0x18(r4);
  stw r3, 0x24(r4);
  stw r3, 0x20(r4);
  stw r3, 0x2c(r4);
  stw r3, 0x28(r4);
  stw r3, 0x34(r4);
  stw r3, 0x30(r4);
  stw r3, 0x3c(r4);
  stw r3, 0x38(r4);
  stw r3, 0x44(r4);
  stw r3, 0x40(r4);
  stw r3, 0x4c(r4);
  stw r3, 0x48(r4);
  stw r3, 0x54(r4);
  stw r3, 0x50(r4);
  stw r3, 0x5c(r4);
  stw r3, 0x58(r4);
  stw r3, 0x64(r4);
  stw r3, 0x60(r4);
  stw r3, 0x6c(r4);
  stw r3, 0x68(r4);
  stw r3, 0x74(r4);
  stw r3, 0x70(r4);
  stw r3, 0x7c(r4);
  stw r3, 0x78(r4);
  addi r4, r4, 0x80;
  bdnz lbl_801a97c0;
  li r4, 0;
  lis r3, 0x8000;
  stw r4, 0xe0(r3);
  stw r4, 0xdc(r3);
  stw r30, 0xdc(r3);
  b lbl_801a9864;
  stw r30, 0x2fc(r4);
lbl_801a9864:
  li r29, 0;
  stw r4, 0x300(r30);
  lis r4, 0x8000;
  addi r3, r31, 0x418;
  stw r29, 0x2fc(r30);
  stw r30, 0xe0(r4);
  bl OSClearContext;
  stw r29, _unk_80386918;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSInitThreadQueue
// PAL: 0x801a98a0..0x801a98b0
MARK_BINARY_BLOB(OSInitThreadQueue, 0x801a98a0, 0x801a98b0);
asm void OSInitThreadQueue(struct OSThreadQueue*) {
  // clang-format off
  nofralloc;
  li r0, 0;
  stw r0, 4(r3);
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: OSGetCurrentThread
// PAL: 0x801a98b0..0x801a98b4
MARK_BINARY_BLOB(OSGetCurrentThread, 0x801a98b0, 0x801a98b4);
asm OSThread* OSGetCurrentThread() {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  lwz r3, 0xe4(r3);
  blr;
  // clang-format on
}

// Symbol: OSIsThreadTerminated
// PAL: 0x801a98bc..0x801a98e8
MARK_BINARY_BLOB(OSIsThreadTerminated, 0x801a98bc, 0x801a98e8);
asm int OSIsThreadTerminated(OSThread*) {
  // clang-format off
  nofralloc;
  lhz r0, 0x2c8(r3);
  li r3, 1;
  cmplwi r0, 8;
  beq lbl_801a98d8;
  cmpwi r0, 0;
  beq lbl_801a98d8;
  li r3, 0;
lbl_801a98d8:
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

// Symbol: OSDisableScheduler
// PAL: 0x801a98e8..0x801a9924
MARK_BINARY_BLOB(OSDisableScheduler, 0x801a98e8, 0x801a9924);
asm UNKNOWN_FUNCTION(OSDisableScheduler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lwz r31, _unk_80386918;
  addi r0, r31, 1;
  stw r0, _unk_80386918;
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSEnableScheduler
// PAL: 0x801a9924..0x801a9960
MARK_BINARY_BLOB(OSEnableScheduler, 0x801a9924, 0x801a9960);
asm UNKNOWN_FUNCTION(OSEnableScheduler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lwz r31, _unk_80386918;
  addi r0, r31, -1;
  stw r0, _unk_80386918;
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: UnsetRun
// PAL: 0x801a9960..0x801a99c8
MARK_BINARY_BLOB(UnsetRun, 0x801a9960, 0x801a99c8);
asm UNKNOWN_FUNCTION(UnsetRun) {
  // clang-format off
  nofralloc;
  lwz r5, 0x2e0(r3);
  lwz r4, 0x2dc(r3);
  cmpwi r5, 0;
  lwz r6, 0x2e4(r3);
  bne lbl_801a997c;
  stw r6, 4(r4);
  b lbl_801a9980;
lbl_801a997c:
  stw r6, 0x2e4(r5);
lbl_801a9980:
  cmpwi r6, 0;
  bne lbl_801a9990;
  stw r5, 0(r4);
  b lbl_801a9994;
lbl_801a9990:
  stw r5, 0x2e0(r6);
lbl_801a9994:
  lwz r0, 0(r4);
  cmpwi r0, 0;
  bne lbl_801a99bc;
  lwz r0, 0x2d0(r3);
  li r4, 1;
  lwz r5, _unk_80386920;
  subfic r0, r0, 0x1f;
  slw r0, r4, r0;
  andc r0, r5, r0;
  stw r0, _unk_80386920;
lbl_801a99bc:
  li r0, 0;
  stw r0, 0x2dc(r3);
  blr;
  // clang-format on
}

// Symbol: __OSGetEffectivePriority
// PAL: 0x801a99c8..0x801a9a04
MARK_BINARY_BLOB(__OSGetEffectivePriority, 0x801a99c8, 0x801a9a04);
asm UNKNOWN_FUNCTION(__OSGetEffectivePriority) {
  // clang-format off
  nofralloc;
  lwz r4, 0x2d4(r3);
  lwz r3, 0x2f4(r3);
  b lbl_801a99f4;
lbl_801a99d4:
  lwz r5, 0(r3);
  cmpwi r5, 0;
  beq lbl_801a99f0;
  lwz r0, 0x2d0(r5);
  cmpw r0, r4;
  bge lbl_801a99f0;
  mr r4, r0;
lbl_801a99f0:
  lwz r3, 0x10(r3);
lbl_801a99f4:
  cmpwi r3, 0;
  bne lbl_801a99d4;
  mr r3, r4;
  blr;
  // clang-format on
}

// Symbol: SetEffectivePriority
// PAL: 0x801a9a04..0x801a9bb8
MARK_BINARY_BLOB(SetEffectivePriority, 0x801a9a04, 0x801a9bb8);
asm UNKNOWN_FUNCTION(SetEffectivePriority) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lhz r0, 0x2c8(r3);
  cmpwi r0, 3;
  beq lbl_801a9b9c;
  bge lbl_801a9a40;
  cmpwi r0, 1;
  beq lbl_801a9a4c;
  bge lbl_801a9b90;
  b lbl_801a9b9c;
lbl_801a9a40:
  cmpwi r0, 5;
  bge lbl_801a9b9c;
  b lbl_801a9ab8;
lbl_801a9a4c:
  bl UnsetRun;
  lis r3, 0x8034;
  slwi r0, r31, 3;
  addi r3, r3, 0x77b0;
  stw r31, 0x2d0(r30);
  add r3, r3, r0;
  stw r3, 0x2dc(r30);
  lwz r4, 4(r3);
  cmpwi r4, 0;
  bne lbl_801a9a7c;
  stw r30, 0(r3);
  b lbl_801a9a80;
lbl_801a9a7c:
  stw r30, 0x2e0(r4);
lbl_801a9a80:
  li r0, 0;
  stw r4, 0x2e4(r30);
  lwz r4, 0x2dc(r30);
  li r3, 1;
  stw r0, 0x2e0(r30);
  stw r30, 4(r4);
  lwz r0, 0x2d0(r30);
  lwz r4, _unk_80386920;
  subfic r0, r0, 0x1f;
  slw r0, r3, r0;
  or r0, r4, r0;
  stw r0, _unk_80386920;
  stw r3, _unk_8038691c;
  b lbl_801a9b9c;
lbl_801a9ab8:
  lwz r6, 0x2e0(r3);
  lwz r7, 0x2e4(r3);
  cmpwi r6, 0;
  bne lbl_801a9ad4;
  lwz r5, 0x2dc(r3);
  stw r7, 4(r5);
  b lbl_801a9ad8;
lbl_801a9ad4:
  stw r7, 0x2e4(r6);
lbl_801a9ad8:
  cmpwi r7, 0;
  bne lbl_801a9aec;
  lwz r5, 0x2dc(r3);
  stw r6, 0(r5);
  b lbl_801a9af0;
lbl_801a9aec:
  stw r6, 0x2e0(r7);
lbl_801a9af0:
  stw r4, 0x2d0(r3);
  lwz r5, 0x2dc(r3);
  lwz r6, 0(r5);
  b lbl_801a9b04;
lbl_801a9b00:
  lwz r6, 0x2e0(r6);
lbl_801a9b04:
  cmpwi r6, 0;
  beq lbl_801a9b1c;
  lwz r4, 0x2d0(r6);
  lwz r0, 0x2d0(r3);
  cmpw r4, r0;
  ble lbl_801a9b00;
lbl_801a9b1c:
  cmpwi r6, 0;
  bne lbl_801a9b54;
  lwz r4, 4(r5);
  cmpwi r4, 0;
  bne lbl_801a9b38;
  stw r3, 0(r5);
  b lbl_801a9b3c;
lbl_801a9b38:
  stw r3, 0x2e0(r4);
lbl_801a9b3c:
  li r0, 0;
  stw r4, 0x2e4(r3);
  lwz r4, 0x2dc(r3);
  stw r0, 0x2e0(r3);
  stw r3, 4(r4);
  b lbl_801a9b7c;
lbl_801a9b54:
  stw r6, 0x2e0(r3);
  lwz r4, 0x2e4(r6);
  stw r3, 0x2e4(r6);
  cmpwi r4, 0;
  stw r4, 0x2e4(r3);
  bne lbl_801a9b78;
  lwz r4, 0x2dc(r3);
  stw r3, 0(r4);
  b lbl_801a9b7c;
lbl_801a9b78:
  stw r3, 0x2e0(r4);
lbl_801a9b7c:
  lwz r3, 0x2f0(r3);
  cmpwi r3, 0;
  beq lbl_801a9b9c;
  lwz r3, 8(r3);
  b lbl_801a9ba0;
lbl_801a9b90:
  li r0, 1;
  stw r0, _unk_8038691c;
  stw r4, 0x2d0(r3);
lbl_801a9b9c:
  li r3, 0;
lbl_801a9ba0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSPromoteThread
// PAL: 0x801a9bb8..0x801a9c08
MARK_BINARY_BLOB(__OSPromoteThread, 0x801a9bb8, 0x801a9c08);
asm UNKNOWN_FUNCTION(__OSPromoteThread) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
lbl_801a9bcc:
  lwz r0, 0x2cc(r3);
  cmpwi r0, 0;
  bgt lbl_801a9bf4;
  lwz r0, 0x2d0(r3);
  cmpw r0, r31;
  ble lbl_801a9bf4;
  mr r4, r31;
  bl SetEffectivePriority;
  cmpwi r3, 0;
  bne lbl_801a9bcc;
lbl_801a9bf4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SelectThread
// PAL: 0x801a9c08..0x801a9e30
MARK_BINARY_BLOB(SelectThread, 0x801a9c08, 0x801a9e30);
asm UNKNOWN_FUNCTION(SelectThread) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, _unk_80386918;
  cmpwi r0, 0;
  ble lbl_801a9c34;
  li r3, 0;
  b lbl_801a9e18;
lbl_801a9c34:
  bl OSGetCurrentContext;
  lis r4, 0x8000;
  lwz r5, 0xe4(r4);
  cmplw r3, r5;
  beq lbl_801a9c50;
  li r3, 0;
  b lbl_801a9e18;
lbl_801a9c50:
  cmpwi r5, 0;
  beq lbl_801a9d18;
  lhz r0, 0x2c8(r5);
  cmplwi r0, 2;
  bne lbl_801a9cf4;
  cmpwi r30, 0;
  bne lbl_801a9c88;
  lwz r3, _unk_80386920;
  lwz r0, 0x2d0(r5);
  cntlzw r3, r3;
  cmpw r0, r3;
  bgt lbl_801a9c88;
  li r3, 0;
  b lbl_801a9e18;
lbl_801a9c88:
  li r0, 1;
  lis r3, 0x8034;
  sth r0, 0x2c8(r5);
  addi r3, r3, 0x77b0;
  lwz r0, 0x2d0(r5);
  slwi r0, r0, 3;
  add r3, r3, r0;
  stw r3, 0x2dc(r5);
  lwz r4, 4(r3);
  cmpwi r4, 0;
  bne lbl_801a9cbc;
  stw r5, 0(r3);
  b lbl_801a9cc0;
lbl_801a9cbc:
  stw r5, 0x2e0(r4);
lbl_801a9cc0:
  stw r4, 0x2e4(r5);
  li r0, 0;
  li r3, 1;
  stw r0, 0x2e0(r5);
  lwz r4, 0x2dc(r5);
  stw r5, 4(r4);
  lwz r0, 0x2d0(r5);
  lwz r4, _unk_80386920;
  subfic r0, r0, 0x1f;
  slw r0, r3, r0;
  or r0, r4, r0;
  stw r0, _unk_80386920;
  stw r3, _unk_8038691c;
lbl_801a9cf4:
  lhz r0, 0x1a2(r5);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  bne lbl_801a9d18;
  mr r3, r5;
  bl OSSaveContext;
  cmpwi r3, 0;
  beq lbl_801a9d18;
  li r3, 0;
  b lbl_801a9e18;
lbl_801a9d18:
  lwz r0, _unk_80386920;
  cmpwi r0, 0;
  bne lbl_801a9d7c;
  lwz r12, _unk_80385ae0;
  lis r31, 0x8000;
  lwz r3, 0xe4(r31);
  li r4, 0;
  mtctr r12;
  bctrl;
  li r0, 0;
  lis r3, 0x8034;
  stw r0, 0xe4(r31);
  addi r3, r3, 0x78b0;
  bl OSSetCurrentContext;
lbl_801a9d50:
  bl OSEnableInterrupts;
lbl_801a9d54:
  lwz r0, _unk_80386920;
  cmpwi r0, 0;
  beq lbl_801a9d54;
  bl OSDisableInterrupts;
  lwz r0, _unk_80386920;
  cmpwi r0, 0;
  beq lbl_801a9d50;
  lis r3, 0x8034;
  addi r3, r3, 0x78b0;
  bl OSClearContext;
lbl_801a9d7c:
  li r4, 0;
  lis r3, 0x8034;
  stw r4, _unk_8038691c;
  addi r3, r3, 0x77b0;
  lwz r0, _unk_80386920;
  cntlzw r5, r0;
  slwi r0, r5, 3;
  lwzux r30, r3, r0;
  lwz r6, 0x2e0(r30);
  cmpwi r6, 0;
  bne lbl_801a9db0;
  stw r4, 4(r3);
  b lbl_801a9db4;
lbl_801a9db0:
  stw r4, 0x2e4(r6);
lbl_801a9db4:
  cmpwi r6, 0;
  stw r6, 0(r3);
  bne lbl_801a9dd8;
  subfic r0, r5, 0x1f;
  li r3, 1;
  lwz r4, _unk_80386920;
  slw r0, r3, r0;
  andc r0, r4, r0;
  stw r0, _unk_80386920;
lbl_801a9dd8:
  li r3, 0;
  li r0, 2;
  stw r3, 0x2dc(r30);
  lis r31, 0x8000;
  mr r4, r30;
  sth r0, 0x2c8(r30);
  lwz r12, _unk_80385ae0;
  lwz r3, 0xe4(r31);
  mtctr r12;
  bctrl;
  stw r30, 0xe4(r31);
  mr r3, r30;
  bl OSSetCurrentContext;
  mr r3, r30;
  bl OSLoadContext;
  mr r3, r30;
lbl_801a9e18:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSReschedule
// PAL: 0x801a9e30..0x801a9e48
MARK_BINARY_BLOB(__OSReschedule, 0x801a9e30, 0x801a9e48);
asm UNKNOWN_FUNCTION(__OSReschedule) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beqlr;
  li r3, 0;
  b SelectThread;
  blr;
  // clang-format on
}

// Symbol: OSYieldThread
// PAL: 0x801a9e48..0x801a9e84
MARK_BINARY_BLOB(OSYieldThread, 0x801a9e48, 0x801a9e84);
asm UNKNOWN_FUNCTION(OSYieldThread) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  mr r31, r3;
  li r3, 1;
  bl SelectThread;
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSCreateThread
// PAL: 0x801a9e84..0x801aa0f0
MARK_BINARY_BLOB(OSCreateThread, 0x801a9e84, 0x801aa0f0);
asm int OSCreateThread(OSThread* thread, void* (*callable)(void*),
                       void* user_data, void* stack, u32 stack_size, s32 prio,
                       u16 flag) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r8, 0;
  mr r31, r3;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  blt lbl_801a9eb8;
  cmpwi r8, 0x1f;
  ble lbl_801a9ec0;
lbl_801a9eb8:
  li r3, 0;
  b lbl_801aa0d8;
lbl_801a9ec0:
  li r30, 0;
  li r7, 1;
  clrlwi r0, r9, 0x1f;
  li r29, -1;
  rlwinm r6, r6, 0, 0, 0x1c;
  sth r7, 0x2c8(r3);
  addi r5, r6, -8;
  sth r0, 0x2ca(r3);
  stw r8, 0x2d4(r3);
  stw r8, 0x2d0(r3);
  stw r7, 0x2cc(r3);
  stw r29, 0x2d8(r3);
  stw r30, 0x2f0(r3);
  stw r30, 0x2ec(r3);
  stw r30, 0x2e8(r3);
  stw r30, 0x2f8(r3);
  stw r30, 0x2f4(r3);
  stw r30, -8(r6);
  stw r30, -4(r6);
  bl OSInitContext;
  lis r5, 0x801b;
  subf r4, r28, r27;
  addi r5, r5, -24336;
  lis r3, 0xdeae;
  stw r5, 0x84(r31);
  addi r0, r3, -17730;
  stw r26, 0xc(r31);
  stw r27, 0x304(r31);
  stw r4, 0x308(r31);
  stw r0, 0(r4);
  stw r30, 0x30c(r31);
  stw r30, 0x310(r31);
  stw r30, 0x314(r31);
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  addi r4, r4, 0x70f0;
  lwz r0, 0x40(r4);
  cmpwi r0, 0;
  beq lbl_801aa0a0;
  lwz r5, 0x19c(r31);
  li r0, 2;
  lhz r4, 0x1a2(r31);
  addi r6, r31, 0x90;
  ori r5, r5, 0x900;
  addi r7, r31, 0x1c8;
  ori r4, r4, 1;
  stw r5, 0x19c(r31);
  sth r4, 0x1a2(r31);
  lwz r4, _unk_80385aa8;
  rlwinm r4, r4, 0, 0x18, 0x1c;
  ori r4, r4, 4;
  stw r4, 0x194(r31);
  mtctr r0;
lbl_801a9f94:
  stw r29, 4(r6);
  stw r29, 0(r6);
  stw r29, 4(r7);
  stw r29, 0(r7);
  stw r29, 0xc(r6);
  stw r29, 8(r6);
  stw r29, 0xc(r7);
  stw r29, 8(r7);
  stw r29, 0x14(r6);
  stw r29, 0x10(r6);
  stw r29, 0x14(r7);
  stw r29, 0x10(r7);
  stw r29, 0x1c(r6);
  stw r29, 0x18(r6);
  stw r29, 0x1c(r7);
  stw r29, 0x18(r7);
  stw r29, 0x24(r6);
  stw r29, 0x20(r6);
  stw r29, 0x24(r7);
  stw r29, 0x20(r7);
  stw r29, 0x2c(r6);
  stw r29, 0x28(r6);
  stw r29, 0x2c(r7);
  stw r29, 0x28(r7);
  stw r29, 0x34(r6);
  stw r29, 0x30(r6);
  stw r29, 0x34(r7);
  stw r29, 0x30(r7);
  stw r29, 0x3c(r6);
  stw r29, 0x38(r6);
  stw r29, 0x3c(r7);
  stw r29, 0x38(r7);
  stw r29, 0x44(r6);
  stw r29, 0x40(r6);
  stw r29, 0x44(r7);
  stw r29, 0x40(r7);
  stw r29, 0x4c(r6);
  stw r29, 0x48(r6);
  stw r29, 0x4c(r7);
  stw r29, 0x48(r7);
  stw r29, 0x54(r6);
  stw r29, 0x50(r6);
  stw r29, 0x54(r7);
  stw r29, 0x50(r7);
  stw r29, 0x5c(r6);
  stw r29, 0x58(r6);
  stw r29, 0x5c(r7);
  stw r29, 0x58(r7);
  stw r29, 0x64(r6);
  stw r29, 0x60(r6);
  stw r29, 0x64(r7);
  stw r29, 0x60(r7);
  stw r29, 0x6c(r6);
  stw r29, 0x68(r6);
  stw r29, 0x6c(r7);
  stw r29, 0x68(r7);
  stw r29, 0x74(r6);
  stw r29, 0x70(r6);
  stw r29, 0x74(r7);
  stw r29, 0x70(r7);
  stw r29, 0x7c(r6);
  stw r29, 0x78(r6);
  addi r6, r6, 0x80;
  stw r29, 0x7c(r7);
  stw r29, 0x78(r7);
  addi r7, r7, 0x80;
  bdnz lbl_801a9f94;
lbl_801aa0a0:
  lis r4, 0x8000;
  lwz r5, 0xe0(r4);
  cmpwi r5, 0;
  bne lbl_801aa0b8;
  stw r31, 0xdc(r4);
  b lbl_801aa0bc;
lbl_801aa0b8:
  stw r31, 0x2fc(r5);
lbl_801aa0bc:
  li r0, 0;
  stw r5, 0x300(r31);
  lis r4, 0x8000;
  stw r0, 0x2fc(r31);
  stw r31, 0xe0(r4);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801aa0d8:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSExitThread
// PAL: 0x801aa0f0..0x801aa1d4
MARK_BINARY_BLOB(OSExitThread, 0x801aa0f0, 0x801aa1d4);
asm UNKNOWN_FUNCTION(OSExitThread) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bl OSDisableInterrupts;
  lis r31, 0x8000;
  mr r29, r3;
  lwz r30, 0xe4(r31);
  mr r3, r30;
  bl OSClearContext;
  lhz r0, 0x2ca(r30);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801aa174;
  lwz r4, 0x2fc(r30);
  lwz r3, 0x300(r30);
  cmpwi r4, 0;
  bne lbl_801aa14c;
  stw r3, 0xe0(r31);
  b lbl_801aa150;
lbl_801aa14c:
  stw r3, 0x300(r4);
lbl_801aa150:
  cmpwi r3, 0;
  bne lbl_801aa164;
  lis r3, 0x8000;
  stw r4, 0xdc(r3);
  b lbl_801aa168;
lbl_801aa164:
  stw r4, 0x2fc(r3);
lbl_801aa168:
  li r0, 0;
  sth r0, 0x2c8(r30);
  b lbl_801aa180;
lbl_801aa174:
  li r0, 8;
  sth r0, 0x2c8(r30);
  stw r28, 0x2d8(r30);
lbl_801aa180:
  mr r3, r30;
  bl __OSUnlockAllMutex;
  addi r3, r30, 0x2e8;
  bl OSWakeupThread;
  li r0, 1;
  stw r0, _unk_8038691c;
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aa1ac;
  li r3, 0;
  bl SelectThread;
lbl_801aa1ac:
  mr r3, r29;
  bl OSRestoreInterrupts;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSCancelThread
// PAL: 0x801aa1d4..0x801aa3ac
MARK_BINARY_BLOB(OSCancelThread, 0x801aa1d4, 0x801aa3ac);
asm void OSCancelThread(OSThread*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lhz r0, 0x2c8(r30);
  mr r31, r3;
  cmpwi r0, 3;
  beq lbl_801aa2fc;
  bge lbl_801aa214;
  cmpwi r0, 1;
  beq lbl_801aa220;
  bge lbl_801aa238;
  b lbl_801aa2fc;
lbl_801aa214:
  cmpwi r0, 5;
  bge lbl_801aa2fc;
  b lbl_801aa244;
lbl_801aa220:
  lwz r0, 0x2cc(r30);
  cmpwi r0, 0;
  bgt lbl_801aa308;
  mr r3, r30;
  bl UnsetRun;
  b lbl_801aa308;
lbl_801aa238:
  li r0, 1;
  stw r0, _unk_8038691c;
  b lbl_801aa308;
lbl_801aa244:
  lwz r4, 0x2e0(r30);
  lwz r5, 0x2e4(r30);
  cmpwi r4, 0;
  bne lbl_801aa260;
  lwz r3, 0x2dc(r30);
  stw r5, 4(r3);
  b lbl_801aa264;
lbl_801aa260:
  stw r5, 0x2e4(r4);
lbl_801aa264:
  cmpwi r5, 0;
  bne lbl_801aa278;
  lwz r3, 0x2dc(r30);
  stw r4, 0(r3);
  b lbl_801aa27c;
lbl_801aa278:
  stw r4, 0x2e0(r5);
lbl_801aa27c:
  lwz r0, 0x2cc(r30);
  li r3, 0;
  stw r3, 0x2dc(r30);
  cmpwi r0, 0;
  bgt lbl_801aa308;
  lwz r3, 0x2f0(r30);
  cmpwi r3, 0;
  beq lbl_801aa308;
  lwz r3, 8(r3);
lbl_801aa2a0:
  lwz r0, 0x2cc(r3);
  cmpwi r0, 0;
  bgt lbl_801aa308;
  lwz r4, 0x2d4(r3);
  lwz r5, 0x2f4(r3);
  b lbl_801aa2d8;
lbl_801aa2b8:
  lwz r6, 0(r5);
  cmpwi r6, 0;
  beq lbl_801aa2d4;
  lwz r0, 0x2d0(r6);
  cmpw r0, r4;
  bge lbl_801aa2d4;
  mr r4, r0;
lbl_801aa2d4:
  lwz r5, 0x10(r5);
lbl_801aa2d8:
  cmpwi r5, 0;
  bne lbl_801aa2b8;
  lwz r0, 0x2d0(r3);
  cmpw r0, r4;
  beq lbl_801aa308;
  bl SetEffectivePriority;
  cmpwi r3, 0;
  bne lbl_801aa2a0;
  b lbl_801aa308;
lbl_801aa2fc:
  mr r3, r31;
  bl OSRestoreInterrupts;
  b lbl_801aa394;
lbl_801aa308:
  mr r3, r30;
  bl OSClearContext;
  lhz r0, 0x2ca(r30);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801aa360;
  lwz r4, 0x2fc(r30);
  lwz r5, 0x300(r30);
  cmpwi r4, 0;
  bne lbl_801aa338;
  lis r3, 0x8000;
  stw r5, 0xe0(r3);
  b lbl_801aa33c;
lbl_801aa338:
  stw r5, 0x300(r4);
lbl_801aa33c:
  cmpwi r5, 0;
  bne lbl_801aa350;
  lis r3, 0x8000;
  stw r4, 0xdc(r3);
  b lbl_801aa354;
lbl_801aa350:
  stw r4, 0x2fc(r5);
lbl_801aa354:
  li r0, 0;
  sth r0, 0x2c8(r30);
  b lbl_801aa368;
lbl_801aa360:
  li r0, 8;
  sth r0, 0x2c8(r30);
lbl_801aa368:
  mr r3, r30;
  bl __OSUnlockAllMutex;
  addi r3, r30, 0x2e8;
  bl OSWakeupThread;
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aa38c;
  li r3, 0;
  bl SelectThread;
lbl_801aa38c:
  mr r3, r31;
  bl OSRestoreInterrupts;
lbl_801aa394:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSJoinThread
// PAL: 0x801aa3ac..0x801aa4ec
MARK_BINARY_BLOB(OSJoinThread, 0x801aa3ac, 0x801aa4ec);
asm UNKNOWN_FUNCTION(OSJoinThread) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  bl OSDisableInterrupts;
  lhz r0, 0x2ca(r31);
  mr r30, r3;
  clrlwi. r0, r0, 0x1f;
  bne lbl_801aa458;
  lhz r0, 0x2c8(r31);
  cmplwi r0, 8;
  beq lbl_801aa458;
  lwz r0, 0x2e8(r31);
  cmpwi r0, 0;
  bne lbl_801aa458;
  addi r3, r31, 0x2e8;
  bl OSSleepThread;
  lhz r0, 0x2c8(r31);
  cmpwi r0, 0;
  bne lbl_801aa414;
  li r0, 0;
  b lbl_801aa440;
lbl_801aa414:
  lis r3, 0x8000;
  lwz r3, 0xdc(r3);
  b lbl_801aa434;
lbl_801aa420:
  cmplw r31, r3;
  bne lbl_801aa430;
  li r0, 1;
  b lbl_801aa440;
lbl_801aa430:
  lwz r3, 0x2fc(r3);
lbl_801aa434:
  cmpwi r3, 0;
  bne lbl_801aa420;
  li r0, 0;
lbl_801aa440:
  cmpwi r0, 0;
  bne lbl_801aa458;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801aa4d0;
lbl_801aa458:
  lhz r0, 0x2c8(r31);
  cmplwi r0, 8;
  bne lbl_801aa4c4;
  cmpwi r29, 0;
  beq lbl_801aa474;
  lwz r0, 0x2d8(r31);
  stw r0, 0(r29);
lbl_801aa474:
  lwz r4, 0x2fc(r31);
  lwz r5, 0x300(r31);
  cmpwi r4, 0;
  bne lbl_801aa490;
  lis r3, 0x8000;
  stw r5, 0xe0(r3);
  b lbl_801aa494;
lbl_801aa490:
  stw r5, 0x300(r4);
lbl_801aa494:
  cmpwi r5, 0;
  bne lbl_801aa4a8;
  lis r3, 0x8000;
  stw r4, 0xdc(r3);
  b lbl_801aa4ac;
lbl_801aa4a8:
  stw r4, 0x2fc(r5);
lbl_801aa4ac:
  li r0, 0;
  mr r3, r30;
  sth r0, 0x2c8(r31);
  bl OSRestoreInterrupts;
  li r3, 1;
  b lbl_801aa4d0;
lbl_801aa4c4:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_801aa4d0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSDetachThread
// PAL: 0x801aa4ec..0x801aa58c
MARK_BINARY_BLOB(OSDetachThread, 0x801aa4ec, 0x801aa58c);
asm void OSDetachThread(OSThread*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lhz r0, 0x2c8(r30);
  mr r31, r3;
  lhz r4, 0x2ca(r30);
  cmplwi r0, 8;
  ori r3, r4, 1;
  sth r3, 0x2ca(r30);
  bne lbl_801aa564;
  lwz r4, 0x2fc(r30);
  lwz r5, 0x300(r30);
  cmpwi r4, 0;
  bne lbl_801aa540;
  lis r3, 0x8000;
  stw r5, 0xe0(r3);
  b lbl_801aa544;
lbl_801aa540:
  stw r5, 0x300(r4);
lbl_801aa544:
  cmpwi r5, 0;
  bne lbl_801aa558;
  lis r3, 0x8000;
  stw r4, 0xdc(r3);
  b lbl_801aa55c;
lbl_801aa558:
  stw r4, 0x2fc(r5);
lbl_801aa55c:
  li r0, 0;
  sth r0, 0x2c8(r30);
lbl_801aa564:
  addi r3, r30, 0x2e8;
  bl OSWakeupThread;
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

// Symbol: OSResumeThread
// PAL: 0x801aa58c..0x801aa824
MARK_BINARY_BLOB(OSResumeThread, 0x801aa58c, 0x801aa824);
asm s32 OSResumeThread(OSThread*) {
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
  lwz r30, 0x2cc(r29);
  mr r31, r3;
  addic. r0, r30, -1;
  stw r0, 0x2cc(r29);
  bge lbl_801aa5cc;
  li r0, 0;
  stw r0, 0x2cc(r29);
  b lbl_801aa7fc;
lbl_801aa5cc:
  bne lbl_801aa7fc;
  lhz r0, 0x2c8(r29);
  cmpwi r0, 4;
  beq lbl_801aa688;
  bge lbl_801aa7e8;
  cmpwi r0, 1;
  beq lbl_801aa5ec;
  b lbl_801aa7e8;
lbl_801aa5ec:
  lwz r5, 0x2d4(r29);
  lwz r4, 0x2f4(r29);
  b lbl_801aa618;
lbl_801aa5f8:
  lwz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_801aa614;
  lwz r0, 0x2d0(r3);
  cmpw r0, r5;
  bge lbl_801aa614;
  mr r5, r0;
lbl_801aa614:
  lwz r4, 0x10(r4);
lbl_801aa618:
  cmpwi r4, 0;
  bne lbl_801aa5f8;
  lis r3, 0x8034;
  slwi r0, r5, 3;
  addi r3, r3, 0x77b0;
  stw r5, 0x2d0(r29);
  add r3, r3, r0;
  stw r3, 0x2dc(r29);
  lwz r4, 4(r3);
  cmpwi r4, 0;
  bne lbl_801aa64c;
  stw r29, 0(r3);
  b lbl_801aa650;
lbl_801aa64c:
  stw r29, 0x2e0(r4);
lbl_801aa650:
  li r0, 0;
  stw r4, 0x2e4(r29);
  lwz r4, 0x2dc(r29);
  li r3, 1;
  stw r0, 0x2e0(r29);
  stw r29, 4(r4);
  lwz r0, 0x2d0(r29);
  lwz r4, _unk_80386920;
  subfic r0, r0, 0x1f;
  slw r0, r3, r0;
  or r0, r4, r0;
  stw r0, _unk_80386920;
  stw r3, _unk_8038691c;
  b lbl_801aa7e8;
lbl_801aa688:
  lwz r4, 0x2e0(r29);
  lwz r5, 0x2e4(r29);
  cmpwi r4, 0;
  bne lbl_801aa6a4;
  lwz r3, 0x2dc(r29);
  stw r5, 4(r3);
  b lbl_801aa6a8;
lbl_801aa6a4:
  stw r5, 0x2e4(r4);
lbl_801aa6a8:
  cmpwi r5, 0;
  bne lbl_801aa6bc;
  lwz r3, 0x2dc(r29);
  stw r4, 0(r3);
  b lbl_801aa6c0;
lbl_801aa6bc:
  stw r4, 0x2e0(r5);
lbl_801aa6c0:
  lwz r0, 0x2d4(r29);
  lwz r4, 0x2f4(r29);
  b lbl_801aa6ec;
lbl_801aa6cc:
  lwz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_801aa6e8;
  lwz r3, 0x2d0(r3);
  cmpw r3, r0;
  bge lbl_801aa6e8;
  mr r0, r3;
lbl_801aa6e8:
  lwz r4, 0x10(r4);
lbl_801aa6ec:
  cmpwi r4, 0;
  bne lbl_801aa6cc;
  stw r0, 0x2d0(r29);
  lwz r4, 0x2dc(r29);
  lwz r5, 0(r4);
  b lbl_801aa708;
lbl_801aa704:
  lwz r5, 0x2e0(r5);
lbl_801aa708:
  cmpwi r5, 0;
  beq lbl_801aa720;
  lwz r3, 0x2d0(r5);
  lwz r0, 0x2d0(r29);
  cmpw r3, r0;
  ble lbl_801aa704;
lbl_801aa720:
  cmpwi r5, 0;
  bne lbl_801aa758;
  lwz r3, 4(r4);
  cmpwi r3, 0;
  bne lbl_801aa73c;
  stw r29, 0(r4);
  b lbl_801aa740;
lbl_801aa73c:
  stw r29, 0x2e0(r3);
lbl_801aa740:
  li r0, 0;
  stw r3, 0x2e4(r29);
  lwz r3, 0x2dc(r29);
  stw r0, 0x2e0(r29);
  stw r29, 4(r3);
  b lbl_801aa780;
lbl_801aa758:
  stw r5, 0x2e0(r29);
  lwz r3, 0x2e4(r5);
  stw r29, 0x2e4(r5);
  cmpwi r3, 0;
  stw r3, 0x2e4(r29);
  bne lbl_801aa77c;
  lwz r3, 0x2dc(r29);
  stw r29, 0(r3);
  b lbl_801aa780;
lbl_801aa77c:
  stw r29, 0x2e0(r3);
lbl_801aa780:
  lwz r3, 0x2f0(r29);
  cmpwi r3, 0;
  beq lbl_801aa7e8;
  lwz r3, 8(r3);
lbl_801aa790:
  lwz r0, 0x2cc(r3);
  cmpwi r0, 0;
  bgt lbl_801aa7e8;
  lwz r4, 0x2d4(r3);
  lwz r5, 0x2f4(r3);
  b lbl_801aa7c8;
lbl_801aa7a8:
  lwz r6, 0(r5);
  cmpwi r6, 0;
  beq lbl_801aa7c4;
  lwz r0, 0x2d0(r6);
  cmpw r0, r4;
  bge lbl_801aa7c4;
  mr r4, r0;
lbl_801aa7c4:
  lwz r5, 0x10(r5);
lbl_801aa7c8:
  cmpwi r5, 0;
  bne lbl_801aa7a8;
  lwz r0, 0x2d0(r3);
  cmpw r0, r4;
  beq lbl_801aa7e8;
  bl SetEffectivePriority;
  cmpwi r3, 0;
  bne lbl_801aa790;
lbl_801aa7e8:
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aa7fc;
  li r3, 0;
  bl SelectThread;
lbl_801aa7fc:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSSuspendThread
// PAL: 0x801aa824..0x801aa9b8
MARK_BINARY_BLOB(OSSuspendThread, 0x801aa824, 0x801aa9b8);
asm s32 OSSuspendThread(OSThread*) {
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
  lwz r30, 0x2cc(r29);
  mr r31, r3;
  addi r0, r30, 1;
  cmpwi r30, 0;
  stw r0, 0x2cc(r29);
  bne lbl_801aa990;
  lhz r0, 0x2c8(r29);
  cmpwi r0, 3;
  beq lbl_801aa97c;
  bge lbl_801aa87c;
  cmpwi r0, 1;
  beq lbl_801aa898;
  bge lbl_801aa888;
  b lbl_801aa97c;
lbl_801aa87c:
  cmpwi r0, 5;
  bge lbl_801aa97c;
  b lbl_801aa8a4;
lbl_801aa888:
  li r0, 1;
  stw r0, _unk_8038691c;
  sth r0, 0x2c8(r29);
  b lbl_801aa97c;
lbl_801aa898:
  mr r3, r29;
  bl UnsetRun;
  b lbl_801aa97c;
lbl_801aa8a4:
  lwz r4, 0x2e0(r29);
  lwz r5, 0x2e4(r29);
  cmpwi r4, 0;
  bne lbl_801aa8c0;
  lwz r3, 0x2dc(r29);
  stw r5, 4(r3);
  b lbl_801aa8c4;
lbl_801aa8c0:
  stw r5, 0x2e4(r4);
lbl_801aa8c4:
  cmpwi r5, 0;
  bne lbl_801aa8d8;
  lwz r3, 0x2dc(r29);
  stw r4, 0(r3);
  b lbl_801aa8dc;
lbl_801aa8d8:
  stw r4, 0x2e0(r5);
lbl_801aa8dc:
  li r0, 0x20;
  lwz r3, 0x2dc(r29);
  stw r0, 0x2d0(r29);
  lwz r4, 4(r3);
  cmpwi r4, 0;
  bne lbl_801aa8fc;
  stw r29, 0(r3);
  b lbl_801aa900;
lbl_801aa8fc:
  stw r29, 0x2e0(r4);
lbl_801aa900:
  li r0, 0;
  stw r4, 0x2e4(r29);
  lwz r3, 0x2dc(r29);
  stw r0, 0x2e0(r29);
  stw r29, 4(r3);
  lwz r3, 0x2f0(r29);
  cmpwi r3, 0;
  beq lbl_801aa97c;
  lwz r3, 8(r3);
lbl_801aa924:
  lwz r0, 0x2cc(r3);
  cmpwi r0, 0;
  bgt lbl_801aa97c;
  lwz r4, 0x2d4(r3);
  lwz r5, 0x2f4(r3);
  b lbl_801aa95c;
lbl_801aa93c:
  lwz r6, 0(r5);
  cmpwi r6, 0;
  beq lbl_801aa958;
  lwz r0, 0x2d0(r6);
  cmpw r0, r4;
  bge lbl_801aa958;
  mr r4, r0;
lbl_801aa958:
  lwz r5, 0x10(r5);
lbl_801aa95c:
  cmpwi r5, 0;
  bne lbl_801aa93c;
  lwz r0, 0x2d0(r3);
  cmpw r0, r4;
  beq lbl_801aa97c;
  bl SetEffectivePriority;
  cmpwi r3, 0;
  bne lbl_801aa924;
lbl_801aa97c:
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aa990;
  li r3, 0;
  bl SelectThread;
lbl_801aa990:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSSleepThread
// PAL: 0x801aa9b8..0x801aaaa4
MARK_BINARY_BLOB(OSSleepThread, 0x801aa9b8, 0x801aaaa4);
asm void OSSleepThread(struct OSThreadQueue*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lis r4, 0x8000;
  li r0, 4;
  lwz r4, 0xe4(r4);
  mr r31, r3;
  sth r0, 0x2c8(r4);
  stw r30, 0x2dc(r4);
  lwz r5, 0(r30);
  b lbl_801aa9f8;
lbl_801aa9f4:
  lwz r5, 0x2e0(r5);
lbl_801aa9f8:
  cmpwi r5, 0;
  beq lbl_801aaa10;
  lwz r3, 0x2d0(r5);
  lwz r0, 0x2d0(r4);
  cmpw r3, r0;
  ble lbl_801aa9f4;
lbl_801aaa10:
  cmpwi r5, 0;
  bne lbl_801aaa44;
  lwz r3, 4(r30);
  cmpwi r3, 0;
  bne lbl_801aaa2c;
  stw r4, 0(r30);
  b lbl_801aaa30;
lbl_801aaa2c:
  stw r4, 0x2e0(r3);
lbl_801aaa30:
  stw r3, 0x2e4(r4);
  li r0, 0;
  stw r0, 0x2e0(r4);
  stw r4, 4(r30);
  b lbl_801aaa68;
lbl_801aaa44:
  stw r5, 0x2e0(r4);
  lwz r3, 0x2e4(r5);
  stw r4, 0x2e4(r5);
  cmpwi r3, 0;
  stw r3, 0x2e4(r4);
  bne lbl_801aaa64;
  stw r4, 0(r30);
  b lbl_801aaa68;
lbl_801aaa64:
  stw r4, 0x2e0(r3);
lbl_801aaa68:
  li r0, 1;
  stw r0, _unk_8038691c;
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aaa84;
  li r3, 0;
  bl SelectThread;
lbl_801aaa84:
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

// Symbol: OSWakeupThread
// PAL: 0x801aaaa4..0x801aab98
MARK_BINARY_BLOB(OSWakeupThread, 0x801aaaa4, 0x801aab98);
asm void OSWakeupThread(struct OSThreadQueue*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lis r5, 0x8034;
  mr r31, r3;
  addi r5, r5, 0x77b0;
  li r6, 0;
  li r3, 1;
  b lbl_801aab58;
lbl_801aaad8:
  lwz r4, 0x2e0(r8);
  cmpwi r4, 0;
  bne lbl_801aaaec;
  stw r6, 4(r30);
  b lbl_801aaaf0;
lbl_801aaaec:
  stw r6, 0x2e4(r4);
lbl_801aaaf0:
  stw r4, 0(r30);
  sth r3, 0x2c8(r8);
  lwz r0, 0x2cc(r8);
  cmpwi r0, 0;
  bgt lbl_801aab58;
  lwz r0, 0x2d0(r8);
  slwi r0, r0, 3;
  add r4, r5, r0;
  stw r4, 0x2dc(r8);
  lwz r7, 4(r4);
  cmpwi r7, 0;
  bne lbl_801aab28;
  stw r8, 0(r4);
  b lbl_801aab2c;
lbl_801aab28:
  stw r8, 0x2e0(r7);
lbl_801aab2c:
  stw r7, 0x2e4(r8);
  stw r6, 0x2e0(r8);
  lwz r4, 0x2dc(r8);
  stw r8, 4(r4);
  lwz r0, 0x2d0(r8);
  lwz r4, _unk_80386920;
  subfic r0, r0, 0x1f;
  slw r0, r3, r0;
  or r0, r4, r0;
  stw r0, _unk_80386920;
  stw r3, _unk_8038691c;
lbl_801aab58:
  lwz r8, 0(r30);
  cmpwi r8, 0;
  bne lbl_801aaad8;
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aab78;
  li r3, 0;
  bl SelectThread;
lbl_801aab78:
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

// Symbol: OSSetThreadPriority
// PAL: 0x801aab98..0x801aaca8
MARK_BINARY_BLOB(OSSetThreadPriority, 0x801aab98, 0x801aaca8);
asm UNKNOWN_FUNCTION(OSSetThreadPriority) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  blt lbl_801aabc8;
  cmpwi r4, 0x1f;
  ble lbl_801aabd0;
lbl_801aabc8:
  li r3, 0;
  b lbl_801aac68;
lbl_801aabd0:
  bl OSDisableInterrupts;
  lwz r0, 0x2d4(r29);
  mr r31, r3;
  cmpw r0, r30;
  beq lbl_801aac5c;
  stw r30, 0x2d4(r29);
lbl_801aabe8:
  lwz r0, 0x2cc(r29);
  cmpwi r0, 0;
  bgt lbl_801aac48;
  lwz r4, 0x2d4(r29);
  lwz r3, 0x2f4(r29);
  b lbl_801aac20;
lbl_801aac00:
  lwz r5, 0(r3);
  cmpwi r5, 0;
  beq lbl_801aac1c;
  lwz r0, 0x2d0(r5);
  cmpw r0, r4;
  bge lbl_801aac1c;
  mr r4, r0;
lbl_801aac1c:
  lwz r3, 0x10(r3);
lbl_801aac20:
  cmpwi r3, 0;
  bne lbl_801aac00;
  lwz r0, 0x2d0(r29);
  cmpw r0, r4;
  beq lbl_801aac48;
  mr r3, r29;
  bl SetEffectivePriority;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_801aabe8;
lbl_801aac48:
  lwz r0, _unk_8038691c;
  cmpwi r0, 0;
  beq lbl_801aac5c;
  li r3, 0;
  bl SelectThread;
lbl_801aac5c:
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801aac68:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSGetAlarmUserData;
  bl OSResumeThread;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSSleepTicks
// PAL: 0x801aaca8..0x801aad5c
MARK_BINARY_BLOB(OSSleepTicks, 0x801aaca8, 0x801aad5c);
asm void OSSleepTicks(OSTime ticks) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  stw r30, 0x48(r1);
  stw r29, 0x44(r1);
  mr r29, r3;
  stw r28, 0x40(r1);
  mr r28, r4;
  bl OSDisableInterrupts;
  lis r4, 0x8000;
  mr r30, r3;
  lwz r31, 0xe4(r4);
  cmpwi r31, 0;
  bne lbl_801aacec;
  bl OSRestoreInterrupts;
  b lbl_801aad3c;
lbl_801aacec:
  addi r3, r1, 8;
  bl OSCreateAlarm;
  mr r4, r31;
  addi r3, r1, 8;
  bl OSSetAlarmTag;
  mr r4, r31;
  addi r3, r1, 8;
  bl OSSetAlarmUserData;
  lis r7, 0x801b;
  mr r6, r28;
  mr r5, r29;
  addi r3, r1, 8;
  addi r7, r7, -21372;
  bl OSSetAlarm;
  mr r3, r31;
  bl OSSuspendThread;
  addi r3, r1, 8;
  bl OSCancelAlarm;
  mr r3, r30;
  bl OSRestoreInterrupts;
lbl_801aad3c:
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
