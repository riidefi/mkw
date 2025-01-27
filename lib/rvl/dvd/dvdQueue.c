#include "dvdQueue.h"

#include <rvl/os/osInterrupt.h>

// Symbol: __DVDRestartMotor
// PAL: 0x801635bc..0x801635c0
UNKNOWN_FUNCTION(__DVDRestartMotor) {}

// Symbol: __DVDClearWaitingQueue
// PAL: 0x801635c0..0x801635f8
MARK_BINARY_BLOB(__DVDClearWaitingQueue, 0x801635c0, 0x801635f8);
asm UNKNOWN_FUNCTION(__DVDClearWaitingQueue) {
  // clang-format off
  nofralloc;
  lis r6, 0x8034;
  addi r6, r6, 0x3230;
  addi r5, r6, 8;
  stw r6, 0(r6);
  addi r4, r6, 0x10;
  addi r3, r6, 0x18;
  stw r6, 4(r6);
  stw r5, 8(r6);
  stw r5, 0xc(r6);
  stw r4, 0x10(r6);
  stw r4, 0x14(r6);
  stw r3, 0x18(r6);
  stw r3, 0x1c(r6);
  blr;
  // clang-format on
}

// Symbol: __DVDPushWaitingQueue
// PAL: 0x801635f8..0x80163660
MARK_BINARY_BLOB(__DVDPushWaitingQueue, 0x801635f8, 0x80163660);
asm UNKNOWN_FUNCTION(__DVDPushWaitingQueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  slwi r0, r30, 3;
  addi r4, r4, 0x3230;
  add r5, r4, r0;
  lwz r4, 4(r5);
  stw r31, 0(r4);
  lwz r0, 4(r5);
  stw r0, 4(r31);
  stw r5, 0(r31);
  stw r31, 4(r5);
  bl OSRestoreInterrupts;
  lwz r31, 0xc(r1);
  li r3, 1;
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDPopWaitingQueue
// PAL: 0x80163660..0x80163700
MARK_BINARY_BLOB(__DVDPopWaitingQueue, 0x80163660, 0x80163700);
asm UNKNOWN_FUNCTION(__DVDPopWaitingQueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  li r0, 4;
  li r31, 0;
  addi r4, r4, 0x3230;
  mtctr r0;
lbl_80163688:
  lwz r0, 0(r4);
  cmplw r0, r4;
  beq lbl_801636d8;
  bl OSRestoreInterrupts;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  slwi r0, r31, 3;
  addi r4, r4, 0x3230;
  lwzx r31, r4, r0;
  add r5, r4, r0;
  lwz r0, 0(r31);
  stw r0, 0(r5);
  lwz r4, 0(r31);
  stw r5, 4(r4);
  bl OSRestoreInterrupts;
  li r0, 0;
  mr r3, r31;
  stw r0, 0(r31);
  stw r0, 4(r31);
  b lbl_801636ec;
lbl_801636d8:
  addi r4, r4, 8;
  addi r31, r31, 1;
  bdnz lbl_80163688;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_801636ec:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDCheckWaitingQueue
// PAL: 0x80163700..0x80163758
MARK_BINARY_BLOB(__DVDCheckWaitingQueue, 0x80163700, 0x80163758);
asm UNKNOWN_FUNCTION(__DVDCheckWaitingQueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  li r0, 4;
  addi r4, r4, 0x3230;
  mtctr r0;
lbl_80163720:
  lwz r0, 0(r4);
  cmplw r0, r4;
  beq lbl_80163738;
  bl OSRestoreInterrupts;
  li r3, 1;
  b lbl_80163748;
lbl_80163738:
  addi r4, r4, 8;
  bdnz lbl_80163720;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_80163748:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDGetNextWaitingQueue
// PAL: 0x80163758..0x801637b8
MARK_BINARY_BLOB(__DVDGetNextWaitingQueue, 0x80163758, 0x801637b8);
asm UNKNOWN_FUNCTION(__DVDGetNextWaitingQueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  li r0, 4;
  addi r4, r4, 0x3230;
  mtctr r0;
lbl_8016377c:
  lwz r31, 0(r4);
  cmplw r31, r4;
  beq lbl_80163794;
  bl OSRestoreInterrupts;
  mr r3, r31;
  b lbl_801637a4;
lbl_80163794:
  addi r4, r4, 8;
  bdnz lbl_8016377c;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_801637a4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDDequeueWaitingQueue
// PAL: 0x801637b8..0x80163818
MARK_BINARY_BLOB(__DVDDequeueWaitingQueue, 0x801637b8, 0x80163818);
asm UNKNOWN_FUNCTION(__DVDDequeueWaitingQueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r4, 4(r31);
  lwz r5, 0(r31);
  cmpwi r4, 0;
  beq lbl_801637e8;
  cmpwi r5, 0;
  bne lbl_801637f4;
lbl_801637e8:
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80163804;
lbl_801637f4:
  stw r5, 0(r4);
  stw r4, 4(r5);
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80163804:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
