#include "osRtc.h"

#include "osCache.h"
#include "osInterrupt.h"

// Extern function references.
// PAL: 0x80167f68
extern UNKNOWN_FUNCTION(EXIImm);
// PAL: 0x801681e4
extern UNKNOWN_FUNCTION(EXIImmEx);
// PAL: 0x80168288
extern UNKNOWN_FUNCTION(EXIDma);
// PAL: 0x80168380
extern UNKNOWN_FUNCTION(EXISync);
// PAL: 0x801689d0
extern UNKNOWN_FUNCTION(EXISelect);
// PAL: 0x80168b00
extern UNKNOWN_FUNCTION(EXIDeselect);
// PAL: 0x80169164
extern UNKNOWN_FUNCTION(EXILock);
// PAL: 0x80169260
extern UNKNOWN_FUNCTION(EXIUnlock);

// Symbol: WriteSramCallback
// PAL: 0x801a8a9c..0x801a8bd4
MARK_BINARY_BLOB(WriteSramCallback, 0x801a8a9c, 0x801a8bd4);
asm UNKNOWN_FUNCTION(WriteSramCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  lis r5, 0x801b;
  stw r0, 0x24(r1);
  addi r6, r6, 0x7440;
  li r3, 0;
  addi r5, r5, -30052;
  stw r31, 0x1c(r1);
  li r4, 1;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lwz r31, 0x40(r6);
  subfic r29, r31, 0x40;
  add r30, r6, r31;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a8aec;
  li r0, 0;
  b lbl_801a8b9c;
lbl_801a8aec:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a8b14;
  li r3, 0;
  bl EXIUnlock;
  li r0, 0;
  b lbl_801a8b9c;
lbl_801a8b14:
  slwi r3, r31, 6;
  addi r4, r1, 8;
  addi r0, r3, 0x100;
  li r5, 4;
  oris r0, r0, 0xa000;
  li r3, 0;
  stw r0, 8(r1);
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  mr r4, r30;
  srwi r0, r0, 5;
  mr r5, r29;
  or r29, r31, r0;
  li r3, 0;
  li r6, 1;
  bl EXIImmEx;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r29, r29, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r29, r29, r0;
  bl EXIUnlock;
  cntlzw r0, r29;
  srwi r0, r0, 5;
lbl_801a8b9c:
  lis r3, 0x8034;
  cmpwi r0, 0;
  addi r3, r3, 0x7440;
  stw r0, 0x4c(r3);
  beq lbl_801a8bb8;
  li r0, 0x40;
  stw r0, 0x40(r3);
lbl_801a8bb8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSInitSram
// PAL: 0x801a8bd4..0x801a8dd4
MARK_BINARY_BLOB(__OSInitSram, 0x801a8bd4, 0x801a8dd4);
asm UNKNOWN_FUNCTION(__OSInitSram) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r4, 0x40;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, 0x7440;
  stw r0, 0x44(r30);
  mr r3, r30;
  stw r0, 0x48(r30);
  bl DCInvalidateRange;
  li r3, 0;
  li r4, 1;
  li r5, 0;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a8c28;
  li r3, 0;
  b lbl_801a8cec;
lbl_801a8c28:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a8c50;
  li r3, 0;
  bl EXIUnlock;
  li r3, 0;
  b lbl_801a8cec;
lbl_801a8c50:
  lis r3, 0x2000;
  addi r4, r1, 8;
  addi r0, r3, 0x100;
  li r5, 4;
  stw r0, 8(r1);
  li r3, 0;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  mr r4, r30;
  srwi r0, r0, 5;
  li r3, 0;
  or r30, r31, r0;
  li r5, 0x40;
  li r6, 0;
  li r7, 0;
  bl EXIDma;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXISync;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXIUnlock;
  cntlzw r0, r30;
  srwi r3, r0, 5;
lbl_801a8cec:
  lis r31, 0x8034;
  li r0, 0x40;
  addi r31, r31, 0x7440;
  stw r3, 0x4c(r31);
  stw r0, 0x40(r31);
  bl OSDisableInterrupts;
  lwz r0, 0x48(r31);
  cmpwi r0, 0;
  beq lbl_801a8d1c;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801a8d2c;
lbl_801a8d1c:
  li r0, 1;
  stw r3, 0x44(r31);
  addi r3, r31, 0x14;
  stw r0, 0x48(r31);
lbl_801a8d2c:
  lhz r30, 0x28(r3);
  li r3, 0;
  li r4, 0x14;
  bl UnlockSram;
  rlwinm r0, r30, 0, 0x11, 0x15;
  cmplwi r0, 0x5000;
  beq lbl_801a8d54;
  rlwinm r0, r30, 0, 0x18, 0x19;
  cmplwi r0, 0xc0;
  bne lbl_801a8d58;
lbl_801a8d54:
  li r30, 0;
lbl_801a8d58:
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  addi r4, r4, 0x7440;
  lwz r0, 0x48(r4);
  cmpwi r0, 0;
  beq lbl_801a8d7c;
  bl OSRestoreInterrupts;
  li r5, 0;
  b lbl_801a8d8c;
lbl_801a8d7c:
  li r0, 1;
  stw r3, 0x44(r4);
  addi r5, r4, 0x14;
  stw r0, 0x48(r4);
lbl_801a8d8c:
  lhz r0, 0x28(r5);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  bne lbl_801a8dac;
  li r3, 0;
  li r4, 0x14;
  bl UnlockSram;
  b lbl_801a8dbc;
lbl_801a8dac:
  sth r30, 0x28(r5);
  li r3, 1;
  li r4, 0x14;
  bl UnlockSram;
lbl_801a8dbc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: UnlockSram
// PAL: 0x801a8dd4..0x801a90b4
MARK_BINARY_BLOB(UnlockSram, 0x801a8dd4, 0x801a90b4);
asm UNKNOWN_FUNCTION(UnlockSram) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  beq lbl_801a907c;
  cmpwi r4, 0;
  bne lbl_801a8f28;
  lis r8, 0x8034;
  addi r8, r8, 0x7440;
  lbz r3, 0x13(r8);
  clrlwi r0, r3, 0x1e;
  cmplwi r0, 2;
  ble lbl_801a8e1c;
  rlwinm r0, r3, 0, 0x18, 0x1d;
  stb r0, 0x13(r8);
lbl_801a8e1c:
  lis r3, 0x8034;
  li r0, 0;
  addi r3, r3, 0x7440;
  addi r7, r8, 0xc;
  addi r5, r3, 0x14;
  sth r0, 2(r8);
  addi r3, r5, 1;
  subf r3, r7, r3;
  cmplw r7, r5;
  sth r0, 0(r8);
  srwi r3, r3, 1;
  bge lbl_801a8f28;
  rlwinm. r0, r3, 0x1e, 2, 0x1f;
  mtctr r0;
  beq lbl_801a8ef8;
lbl_801a8e58:
  lhz r6, 0(r8);
  lhz r0, 0(r7);
  lhz r5, 2(r8);
  add r0, r6, r0;
  sth r0, 0(r8);
  clrlwi r6, r0, 0x10;
  lhz r0, 0(r7);
  nor r0, r0, r0;
  add r0, r5, r0;
  sth r0, 2(r8);
  clrlwi r5, r0, 0x10;
  lhz r0, 2(r7);
  add r0, r6, r0;
  sth r0, 0(r8);
  clrlwi r6, r0, 0x10;
  lhz r0, 2(r7);
  nor r0, r0, r0;
  add r0, r5, r0;
  sth r0, 2(r8);
  clrlwi r5, r0, 0x10;
  lhz r0, 4(r7);
  add r0, r6, r0;
  sth r0, 0(r8);
  clrlwi r6, r0, 0x10;
  lhz r0, 4(r7);
  nor r0, r0, r0;
  add r0, r5, r0;
  sth r0, 2(r8);
  clrlwi r5, r0, 0x10;
  lhz r0, 6(r7);
  add r0, r6, r0;
  sth r0, 0(r8);
  lhz r0, 6(r7);
  addi r7, r7, 8;
  nor r0, r0, r0;
  add r0, r5, r0;
  sth r0, 2(r8);
  bdnz lbl_801a8e58;
  andi. r3, r3, 3;
  beq lbl_801a8f28;
lbl_801a8ef8:
  mtctr r3;
lbl_801a8efc:
  lhz r6, 0(r8);
  lhz r0, 0(r7);
  lhz r5, 2(r8);
  add r0, r6, r0;
  sth r0, 0(r8);
  lhz r0, 0(r7);
  addi r7, r7, 2;
  nor r0, r0, r0;
  add r0, r5, r0;
  sth r0, 2(r8);
  bdnz lbl_801a8efc;
lbl_801a8f28:
  lis r3, 0x8034;
  addi r3, r3, 0x7440;
  lwz r0, 0x40(r3);
  cmplw r4, r0;
  bge lbl_801a8f40;
  stw r4, 0x40(r3);
lbl_801a8f40:
  lis r4, 0x8034;
  addi r4, r4, 0x7440;
  lwz r0, 0x40(r4);
  cmplwi r0, 0x14;
  bgt lbl_801a8f78;
  lhz r3, 0x3c(r4);
  rlwinm r0, r3, 0, 0x11, 0x15;
  cmplwi r0, 0x5000;
  beq lbl_801a8f70;
  rlwinm r0, r3, 0, 0x18, 0x19;
  cmplwi r0, 0xc0;
  bne lbl_801a8f78;
lbl_801a8f70:
  li r0, 0;
  sth r0, 0x3c(r4);
lbl_801a8f78:
  lis r6, 0x8034;
  lis r5, 0x801b;
  addi r6, r6, 0x7440;
  li r3, 0;
  lwz r31, 0x40(r6);
  addi r5, r5, -30052;
  li r4, 1;
  subfic r29, r31, 0x40;
  add r30, r6, r31;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a8fb0;
  li r0, 0;
  b lbl_801a9060;
lbl_801a8fb0:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a8fd8;
  li r3, 0;
  bl EXIUnlock;
  li r0, 0;
  b lbl_801a9060;
lbl_801a8fd8:
  slwi r3, r31, 6;
  addi r4, r1, 8;
  addi r0, r3, 0x100;
  li r5, 4;
  oris r0, r0, 0xa000;
  li r3, 0;
  stw r0, 8(r1);
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  mr r4, r30;
  srwi r0, r0, 5;
  mr r5, r29;
  or r29, r31, r0;
  li r3, 0;
  li r6, 1;
  bl EXIImmEx;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r29, r29, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r29, r29, r0;
  bl EXIUnlock;
  cntlzw r0, r29;
  srwi r0, r0, 5;
lbl_801a9060:
  lis r3, 0x8034;
  cmpwi r0, 0;
  addi r3, r3, 0x7440;
  stw r0, 0x4c(r3);
  beq lbl_801a907c;
  li r0, 0x40;
  stw r0, 0x40(r3);
lbl_801a907c:
  lis r31, 0x8034;
  li r0, 0;
  addi r31, r31, 0x7440;
  stw r0, 0x48(r31);
  lwz r3, 0x44(r31);
  bl OSRestoreInterrupts;
  lwz r3, 0x4c(r31);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSSyncSram
// PAL: 0x801a90b4..0x801a90c4
MARK_BINARY_BLOB(__OSSyncSram, 0x801a90b4, 0x801a90c4);
asm UNKNOWN_FUNCTION(__OSSyncSram) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  addi r3, r3, 0x7440;
  lwz r3, 0x4c(r3);
  blr;
  // clang-format on
}

// Symbol: __OSReadROM
// PAL: 0x801a90c4..0x801a91e8
MARK_BINARY_BLOB(__OSReadROM, 0x801a90c4, 0x801a91e8);
asm UNKNOWN_FUNCTION(__OSReadROM) {
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
  bl DCInvalidateRange;
  li r3, 0;
  li r4, 1;
  li r5, 0;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a910c;
  li r3, 0;
  b lbl_801a91cc;
lbl_801a910c:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a9134;
  li r3, 0;
  bl EXIUnlock;
  li r3, 0;
  b lbl_801a91cc;
lbl_801a9134:
  slwi r0, r31, 6;
  addi r4, r1, 8;
  stw r0, 8(r1);
  li r3, 0;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  mr r4, r29;
  srwi r0, r0, 5;
  mr r5, r30;
  or r31, r31, r0;
  li r3, 0;
  li r6, 0;
  li r7, 0;
  bl EXIDma;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXISync;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIUnlock;
  cntlzw r0, r31;
  srwi r3, r0, 5;
lbl_801a91cc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSGetWirelessID
// PAL: 0x801a91e8..0x801a9260
MARK_BINARY_BLOB(OSGetWirelessID, 0x801a91e8, 0x801a9260);
asm UNKNOWN_FUNCTION(OSGetWirelessID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  addi r4, r4, 0x7440;
  lwz r0, 0x48(r4);
  cmpwi r0, 0;
  beq lbl_801a9220;
  bl OSRestoreInterrupts;
  li r5, 0;
  b lbl_801a9230;
lbl_801a9220:
  li r0, 1;
  stw r3, 0x44(r4);
  addi r5, r4, 0x14;
  stw r0, 0x48(r4);
lbl_801a9230:
  slwi r0, r31, 1;
  li r3, 0;
  add r5, r5, r0;
  li r4, 0x14;
  lhz r31, 0x1c(r5);
  bl UnlockSram;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSSetWirelessID
// PAL: 0x801a9260..0x801a92fc
MARK_BINARY_BLOB(OSSetWirelessID, 0x801a9260, 0x801a92fc);
asm UNKNOWN_FUNCTION(OSSetWirelessID) {
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
  addi r4, r4, 0x7440;
  lwz r0, 0x48(r4);
  cmpwi r0, 0;
  beq lbl_801a92a0;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801a92b0;
lbl_801a92a0:
  li r0, 1;
  stw r3, 0x44(r4);
  addi r3, r4, 0x14;
  stw r0, 0x48(r4);
lbl_801a92b0:
  slwi r0, r30, 1;
  add r3, r3, r0;
  lhz r0, 0x1c(r3);
  cmplw r31, r0;
  beq lbl_801a92d8;
  sth r31, 0x1c(r3);
  li r3, 1;
  li r4, 0x14;
  bl UnlockSram;
  b lbl_801a92e4;
lbl_801a92d8:
  li r3, 0;
  li r4, 0x14;
  bl UnlockSram;
lbl_801a92e4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSGetRTCFlags
// PAL: 0x801a92fc..0x801a9418
MARK_BINARY_BLOB(__OSGetRTCFlags, 0x801a92fc, 0x801a9418);
asm UNKNOWN_FUNCTION(__OSGetRTCFlags) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r4, 1;
  li r5, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  li r3, 0;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a9334;
  li r3, 0;
  b lbl_801a9400;
lbl_801a9334:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a935c;
  li r3, 0;
  bl EXIUnlock;
  li r3, 0;
  b lbl_801a9400;
lbl_801a935c:
  lis r3, 0x2100;
  addi r4, r1, 8;
  addi r0, r3, 0x800;
  li r5, 4;
  stw r0, 8(r1);
  li r3, 0;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  addi r4, r1, 8;
  srwi r0, r0, 5;
  li r3, 0;
  or r31, r31, r0;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXISync;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIUnlock;
  lwz r4, 8(r1);
  cntlzw r0, r31;
  srwi r3, r0, 5;
  stw r4, 0(r30);
lbl_801a9400:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSClearRTCFlags
// PAL: 0x801a9418..0x801a9528
MARK_BINARY_BLOB(__OSClearRTCFlags, 0x801a9418, 0x801a9528);
asm UNKNOWN_FUNCTION(__OSClearRTCFlags) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r3, 0;
  li r4, 1;
  stw r0, 0x24(r1);
  li r0, 0;
  li r5, 0;
  stw r31, 0x1c(r1);
  stw r0, 8(r1);
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_801a9450;
  li r3, 0;
  b lbl_801a9514;
lbl_801a9450:
  li r3, 0;
  li r4, 1;
  li r5, 3;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_801a9478;
  li r3, 0;
  bl EXIUnlock;
  li r3, 0;
  b lbl_801a9514;
lbl_801a9478:
  lis r3, 0xa100;
  addi r4, r1, 0xc;
  addi r0, r3, 0x800;
  li r5, 4;
  stw r0, 0xc(r1);
  li r3, 0;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r31, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  addi r4, r1, 8;
  srwi r0, r0, 5;
  li r3, 0;
  or r31, r31, r0;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXISync;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  li r3, 0;
  srwi r0, r0, 5;
  or r31, r31, r0;
  bl EXIUnlock;
  cntlzw r0, r31;
  srwi r3, r0, 5;
lbl_801a9514:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
