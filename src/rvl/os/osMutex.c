#include "osMutex.h"

#include "osInterrupt.h"
#include "osThread.h"

// Symbol: OSInitMutex
// PAL: 0x801a7eac..0x801a7ee4
MARK_BINARY_BLOB(OSInitMutex, 0x801a7eac, 0x801a7ee4);
asm void OSInitMutex(OSMutex*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSInitThreadQueue;
  li r0, 0;
  stw r0, 8(r31);
  stw r0, 0xc(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSLockMutex
// PAL: 0x801a7ee4..0x801a7fc0
MARK_BINARY_BLOB(OSLockMutex, 0x801a7ee4, 0x801a7fc0);
asm void OSLockMutex(OSMutex*) {
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
  mr r29, r3;
  bl OSGetCurrentThread;
  mr r30, r3;
  li r31, 0;
lbl_801a7f18:
  lwz r0, 8(r28);
  cmpwi r0, 0;
  bne lbl_801a7f60;
  lwz r3, 0xc(r28);
  stw r30, 8(r28);
  addi r0, r3, 1;
  stw r0, 0xc(r28);
  lwz r3, 0x2f8(r30);
  cmpwi r3, 0;
  bne lbl_801a7f48;
  stw r28, 0x2f4(r30);
  b lbl_801a7f4c;
lbl_801a7f48:
  stw r28, 0x10(r3);
lbl_801a7f4c:
  li r0, 0;
  stw r3, 0x14(r28);
  stw r0, 0x10(r28);
  stw r28, 0x2f8(r30);
  b lbl_801a7f98;
lbl_801a7f60:
  cmplw r0, r30;
  bne lbl_801a7f78;
  lwz r3, 0xc(r28);
  addi r0, r3, 1;
  stw r0, 0xc(r28);
  b lbl_801a7f98;
lbl_801a7f78:
  stw r28, 0x2f0(r30);
  lwz r3, 8(r28);
  lwz r4, 0x2d0(r30);
  bl __OSPromoteThread;
  mr r3, r28;
  bl OSSleepThread;
  stw r31, 0x2f0(r30);
  b lbl_801a7f18;
lbl_801a7f98:
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

// Symbol: OSUnlockMutex
// PAL: 0x801a7fc0..0x801a8088
MARK_BINARY_BLOB(OSUnlockMutex, 0x801a7fc0, 0x801a8088);
asm void OSUnlockMutex(OSMutex*) {
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
  mr r31, r3;
  bl OSGetCurrentThread;
  lwz r0, 8(r29);
  mr r30, r3;
  cmplw r0, r3;
  bne lbl_801a8064;
  lwz r0, 0xc(r29);
  addic. r0, r0, -1;
  stw r0, 0xc(r29);
  bne lbl_801a8064;
  lwz r4, 0x10(r29);
  lwz r5, 0x14(r29);
  cmpwi r4, 0;
  bne lbl_801a8020;
  stw r5, 0x2f8(r3);
  b lbl_801a8024;
lbl_801a8020:
  stw r5, 0x14(r4);
lbl_801a8024:
  cmpwi r5, 0;
  bne lbl_801a8034;
  stw r4, 0x2f4(r3);
  b lbl_801a8038;
lbl_801a8034:
  stw r4, 0x10(r5);
lbl_801a8038:
  li r0, 0;
  stw r0, 8(r29);
  lwz r4, 0x2d0(r3);
  lwz r0, 0x2d4(r3);
  cmpw r4, r0;
  bge lbl_801a805c;
  mr r3, r30;
  bl __OSGetEffectivePriority;
  stw r3, 0x2d0(r30);
lbl_801a805c:
  mr r3, r29;
  bl OSWakeupThread;
lbl_801a8064:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSUnlockAllMutex
// PAL: 0x801a8088..0x801a80f4
MARK_BINARY_BLOB(__OSUnlockAllMutex, 0x801a8088, 0x801a80f4);
asm UNKNOWN_FUNCTION(__OSUnlockAllMutex) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_801a80d0;
lbl_801a80a8:
  lwz r4, 0x10(r3);
  cmpwi r4, 0;
  bne lbl_801a80bc;
  stw r31, 0x2f8(r30);
  b lbl_801a80c0;
lbl_801a80bc:
  stw r31, 0x14(r4);
lbl_801a80c0:
  stw r4, 0x2f4(r30);
  stw r31, 0xc(r3);
  stw r31, 8(r3);
  bl OSWakeupThread;
lbl_801a80d0:
  lwz r3, 0x2f4(r30);
  cmpwi r3, 0;
  bne lbl_801a80a8;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSTryLockMutex
// PAL: 0x801a80f4..0x801a81b0
MARK_BINARY_BLOB(OSTryLockMutex, 0x801a80f4, 0x801a81b0);
asm s32 OSTryLockMutex(OSMutex*) {
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
  mr r31, r3;
  bl OSGetCurrentThread;
  lwz r0, 8(r29);
  cmpwi r0, 0;
  bne lbl_801a8168;
  lwz r4, 0xc(r29);
  stw r3, 8(r29);
  addi r0, r4, 1;
  stw r0, 0xc(r29);
  lwz r4, 0x2f8(r3);
  cmpwi r4, 0;
  bne lbl_801a814c;
  stw r29, 0x2f4(r3);
  b lbl_801a8150;
lbl_801a814c:
  stw r29, 0x10(r4);
lbl_801a8150:
  li r0, 0;
  stw r4, 0x14(r29);
  li r30, 1;
  stw r0, 0x10(r29);
  stw r29, 0x2f8(r3);
  b lbl_801a8188;
lbl_801a8168:
  cmplw r0, r3;
  bne lbl_801a8184;
  lwz r3, 0xc(r29);
  li r30, 1;
  addi r0, r3, 1;
  stw r0, 0xc(r29);
  b lbl_801a8188;
lbl_801a8184:
  li r30, 0;
lbl_801a8188:
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

// Symbol: OSInitCond
// PAL: 0x801a81b0..0x801a81b4
MARK_BINARY_BLOB(OSInitCond, 0x801a81b0, 0x801a81b4);
asm UNKNOWN_FUNCTION(OSInitCond) {
  // clang-format off
  nofralloc;
  b OSInitThreadQueue;
  // clang-format on
}

// Symbol: OSSignalCond
// PAL: 0x801a81b4..0x801a81b8
MARK_BINARY_BLOB(OSSignalCond, 0x801a81b4, 0x801a81b8);
asm UNKNOWN_FUNCTION(OSSignalCond) {
  // clang-format off
  nofralloc;
  b OSWakeupThread;
  // clang-format on
}
