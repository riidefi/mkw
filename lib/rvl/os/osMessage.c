#include "osMessage.h"

#include "osInterrupt.h"
#include "osThread.h"

// Symbol: OSInitMessageQueue
// PAL: 0x801a72fc..0x801a735c
MARK_BINARY_BLOB(OSInitMessageQueue, 0x801a72fc, 0x801a735c);
asm void OSInitMessageQueue(OSMessageQueue* mq, OSMessage* msgArray,
                            s32 msgCount) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSInitThreadQueue;
  addi r3, r29, 8;
  bl OSInitThreadQueue;
  li r0, 0;
  stw r30, 0x10(r29);
  stw r31, 0x14(r29);
  stw r0, 0x18(r29);
  stw r0, 0x1c(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSSendMessage
// PAL: 0x801a735c..0x801a7424
MARK_BINARY_BLOB(OSSendMessage, 0x801a735c, 0x801a7424);
asm int OSSendMessage(OSMessageQueue* mq, OSMessage msg, s32 flags) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl OSDisableInterrupts;
  mr r30, r3;
  clrlwi r31, r31, 0x1f;
  b lbl_801a73b4;
lbl_801a7394:
  cmpwi r31, 0;
  bne lbl_801a73ac;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801a7404;
lbl_801a73ac:
  mr r3, r28;
  bl OSSleepThread;
lbl_801a73b4:
  lwz r4, 0x1c(r28);
  lwz r6, 0x14(r28);
  cmpw r6, r4;
  ble lbl_801a7394;
  lwz r0, 0x18(r28);
  addi r3, r28, 8;
  lwz r5, 0x10(r28);
  add r4, r0, r4;
  divw r0, r4, r6;
  mullw r0, r0, r6;
  subf r0, r0, r4;
  slwi r0, r0, 2;
  stwx r29, r5, r0;
  lwz r4, 0x1c(r28);
  addi r0, r4, 1;
  stw r0, 0x1c(r28);
  bl OSWakeupThread;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801a7404:
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

// Symbol: OSReceiveMessage
// PAL: 0x801a7424..0x801a7500
MARK_BINARY_BLOB(OSReceiveMessage, 0x801a7424, 0x801a7500);
asm int OSReceiveMessage(OSMessageQueue* mq, OSMessage* msg, s32 flags) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r4;
  bl OSDisableInterrupts;
  mr r29, r3;
  clrlwi r30, r30, 0x1f;
  b lbl_801a747c;
lbl_801a745c:
  cmpwi r30, 0;
  bne lbl_801a7474;
  mr r3, r29;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801a74e0;
lbl_801a7474:
  addi r3, r31, 8;
  bl OSSleepThread;
lbl_801a747c:
  lwz r0, 0x1c(r31);
  cmpwi r0, 0;
  beq lbl_801a745c;
  cmpwi r28, 0;
  beq lbl_801a74a4;
  lwz r0, 0x18(r31);
  lwz r3, 0x10(r31);
  slwi r0, r0, 2;
  lwzx r0, r3, r0;
  stw r0, 0(r28);
lbl_801a74a4:
  lwz r4, 0x18(r31);
  mr r3, r31;
  lwz r6, 0x14(r31);
  addi r7, r4, 1;
  lwz r4, 0x1c(r31);
  divw r5, r7, r6;
  addi r0, r4, -1;
  stw r0, 0x1c(r31);
  mullw r0, r5, r6;
  subf r0, r0, r7;
  stw r0, 0x18(r31);
  bl OSWakeupThread;
  mr r3, r29;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801a74e0:
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

// Symbol: OSJamMessage
// PAL: 0x801a7500..0x801a75d0
MARK_BINARY_BLOB(OSJamMessage, 0x801a7500, 0x801a75d0);
asm UNKNOWN_FUNCTION(OSJamMessage) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl OSDisableInterrupts;
  mr r30, r3;
  clrlwi r31, r31, 0x1f;
  b lbl_801a7558;
lbl_801a7538:
  cmpwi r31, 0;
  bne lbl_801a7550;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801a75b0;
lbl_801a7550:
  mr r3, r28;
  bl OSSleepThread;
lbl_801a7558:
  lwz r6, 0x14(r28);
  lwz r0, 0x1c(r28);
  cmpw r6, r0;
  ble lbl_801a7538;
  lwz r0, 0x18(r28);
  addi r3, r28, 8;
  lwz r4, 0x10(r28);
  add r5, r6, r0;
  addi r5, r5, -1;
  divw r0, r5, r6;
  mullw r0, r0, r6;
  subf r0, r0, r5;
  stw r0, 0x18(r28);
  slwi r0, r0, 2;
  stwx r29, r4, r0;
  lwz r4, 0x1c(r28);
  addi r0, r4, 1;
  stw r0, 0x1c(r28);
  bl OSWakeupThread;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801a75b0:
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
