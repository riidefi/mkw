#include "ipcclt.h"

#include <string.h>

#include <rvl/os/os.h>
#include <rvl/os/osCache.h>
#include <rvl/os/osContext.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "ipcMain.h"

// Extern function references.
// PAL: 0x801949b8
extern UNKNOWN_FUNCTION(iosCreateHeap);
// PAL: 0x80194cec
extern UNKNOWN_FUNCTION(iosAllocAligned);
// PAL: 0x80194cf0
extern UNKNOWN_FUNCTION(iosFree);
// PAL: 0x80194edc
extern UNKNOWN_FUNCTION(IPCiProfInit);
// PAL: 0x80194f94
extern UNKNOWN_FUNCTION(IPCiProfQueueReq);
// PAL: 0x80195014
extern UNKNOWN_FUNCTION(IPCiProfAck);
// PAL: 0x80195024
extern UNKNOWN_FUNCTION(IPCiProfReply);

u32 _unk_80385990 = 1;
u32 _unk_80385994 = 0xffffffff;

u32 _unk_8038680c;
u32 _unk_80386808;
u32 _unk_80386804;
u32 _unk_80386800;

// Symbol: strnlen
// PAL: 0x80193048..0x80193074
MARK_BINARY_BLOB(strnlen, 0x80193048, 0x80193074);
asm UNKNOWN_FUNCTION(strnlen) {
  // clang-format off
  nofralloc;
  mr r5, r3;
  b lbl_80193054;
lbl_80193050:
  addi r5, r5, 1;
lbl_80193054:
  lbz r0, 0(r5);
  cmpwi r0, 0;
  beq lbl_8019306c;
  cmpwi r4, 0;
  addi r4, r4, -1;
  bne lbl_80193050;
lbl_8019306c:
  subf r3, r3, r5;
  blr;
  // clang-format on
}

// Symbol: IpcReplyHandler
// PAL: 0x80193074..0x801932cc
MARK_BINARY_BLOB(IpcReplyHandler, 0x80193074, 0x801932cc);
asm UNKNOWN_FUNCTION(IpcReplyHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  stw r30, 0x2d8(r1);
  mr r30, r4;
  stw r29, 0x2d4(r1);
  stw r28, 0x2d0(r1);
  bl IPCReadReg;
  cmpwi r3, 0;
  beq lbl_801932ac;
  addis r31, r3, 0x8000;
  li r3, 1;
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 4;
  bl IPCWriteReg;
  lis r0, 0x4000;
  lis r3, 0xcd00;
  stw r0, 0x30(r3);
  mr r3, r31;
  li r4, 0x20;
  bl DCInvalidateRange;
  lwz r0, 8(r31);
  cmpwi r0, 6;
  beq lbl_80193134;
  bge lbl_801930f4;
  cmpwi r0, 3;
  beq lbl_80193100;
  b lbl_80193230;
lbl_801930f4:
  cmpwi r0, 8;
  bge lbl_80193230;
  b lbl_8019316c;
lbl_80193100:
  lwz r3, 0xc(r31);
  cmpwi r3, 0;
  beq lbl_80193114;
  addis r0, r3, 0x8000;
  b lbl_80193118;
lbl_80193114:
  li r0, 0;
lbl_80193118:
  stw r0, 0xc(r31);
  lwz r4, 4(r31);
  cmpwi r4, 0;
  ble lbl_80193230;
  lwz r3, 0xc(r31);
  bl DCInvalidateRange;
  b lbl_80193230;
lbl_80193134:
  lwz r3, 0x18(r31);
  cmpwi r3, 0;
  beq lbl_80193148;
  addis r0, r3, 0x8000;
  b lbl_8019314c;
lbl_80193148:
  li r0, 0;
lbl_8019314c:
  stw r0, 0x18(r31);
  lwz r3, 0x10(r31);
  lwz r4, 0x14(r31);
  bl DCInvalidateRange;
  lwz r3, 0x18(r31);
  lwz r4, 0x1c(r31);
  bl DCInvalidateRange;
  b lbl_80193230;
lbl_8019316c:
  lwz r3, 0x18(r31);
  cmpwi r3, 0;
  beq lbl_80193180;
  addis r3, r3, 0x8000;
  b lbl_80193184;
lbl_80193180:
  li r3, 0;
lbl_80193184:
  stw r3, 0x18(r31);
  lwz r4, 0x10(r31);
  lwz r0, 0x14(r31);
  add r0, r4, r0;
  slwi r4, r0, 3;
  bl DCInvalidateRange;
  li r28, 0;
  li r29, 0;
  b lbl_801931e8;
lbl_801931a8:
  lwz r3, 0x18(r31);
  lwzx r3, r3, r29;
  cmpwi r3, 0;
  beq lbl_801931c0;
  addis r0, r3, 0x8000;
  b lbl_801931c4;
lbl_801931c0:
  li r0, 0;
lbl_801931c4:
  lwz r3, 0x18(r31);
  stwx r0, r3, r29;
  lwz r3, 0x18(r31);
  add r4, r3, r29;
  lwzx r3, r3, r29;
  lwz r4, 4(r4);
  bl DCInvalidateRange;
  addi r28, r28, 1;
  addi r29, r29, 8;
lbl_801931e8:
  lwz r3, 0x10(r31);
  lwz r0, 0x14(r31);
  add r0, r3, r0;
  cmplw r28, r0;
  blt lbl_801931a8;
  lwz r0, _unk_80386800;
  cmpwi r0, 0;
  beq lbl_80193230;
  lwz r0, _unk_80386808;
  cmplw r0, r31;
  bne lbl_80193230;
  lwz r3, _unk_80385990;
  li r0, 0;
  stw r0, _unk_80386800;
  cmpwi r3, 1;
  bge lbl_80193230;
  addi r0, r3, 1;
  stw r0, _unk_80385990;
lbl_80193230:
  lwz r0, 0x20(r31);
  cmpwi r0, 0;
  beq lbl_80193280;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  lwz r12, 0x20(r31);
  lwz r3, 4(r31);
  lwz r4, 0x24(r31);
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r30;
  bl OSSetCurrentContext;
  lwz r3, _unk_80385994;
  mr r4, r31;
  bl iosFree;
  b lbl_80193288;
lbl_80193280:
  addi r3, r31, 0x2c;
  bl OSWakeupThread;
lbl_80193288:
  li r3, 1;
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 8;
  bl IPCWriteReg;
  lwz r4, 8(r31);
  mr r3, r31;
  bl IPCiProfReply;
lbl_801932ac:
  lwz r0, 0x2e4(r1);
  lwz r31, 0x2dc(r1);
  lwz r30, 0x2d8(r1);
  lwz r29, 0x2d4(r1);
  lwz r28, 0x2d0(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: IPCInterruptHandler
// PAL: 0x801932cc..0x80193478
MARK_BINARY_BLOB(IPCInterruptHandler, 0x801932cc, 0x80193478);
asm UNKNOWN_FUNCTION(IPCInterruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 1;
  bl IPCReadReg;
  andi. r0, r3, 0x14;
  cmplwi r0, 0x14;
  bne lbl_80193308;
  mr r3, r30;
  mr r4, r31;
  bl IpcReplyHandler;
lbl_80193308:
  li r3, 1;
  bl IPCReadReg;
  andi. r0, r3, 0x22;
  cmplwi r0, 0x22;
  bne lbl_80193460;
  li r3, 1;
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 2;
  bl IPCWriteReg;
  lis r0, 0x4000;
  lis r3, 0xcd00;
  stw r0, 0x30(r3);
  lwz r31, _unk_80385990;
  cmpwi r31, 1;
  bge lbl_80193358;
  addi r31, r31, 1;
  stw r31, _unk_80385990;
  bl IPCiProfAck;
lbl_80193358:
  cmpwi r31, 0;
  ble lbl_80193460;
  lwz r0, _unk_80386800;
  cmpwi r0, 0;
  beq lbl_801933a0;
  lwz r3, _unk_80386804;
  li r0, 0;
  stw r0, 4(r3);
  lwz r3, _unk_80386804;
  stw r0, _unk_80386800;
  addi r3, r3, 0x2c;
  bl OSWakeupThread;
  li r3, 1;
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 8;
  bl IPCWriteReg;
lbl_801933a0:
  lis r4, 0x8034;
  addi r3, r4, 0x55c0;
  lwz r4, 0x55c0(r4);
  lwz r0, 4(r3);
  cmplw r0, r4;
  bge lbl_801933c0;
  subf r0, r4, r0;
  b lbl_801933cc;
lbl_801933c0:
  subf r0, r4, r0;
  cntlzw r0, r0;
  srwi r0, r0, 5;
lbl_801933cc:
  cmpwi r0, 0;
  bne lbl_80193460;
  lis r3, 0x8034;
  addi r3, r3, 0x55c0;
  lwz r0, 8(r3);
  slwi r0, r0, 2;
  add r3, r3, r0;
  lwz r4, 0x10(r3);
  cmpwi r4, 0;
  beq lbl_80193460;
  lwz r0, 0x28(r4);
  cmpwi r0, 0;
  beq lbl_8019340c;
  lwz r3, _unk_80385990;
  addi r0, r3, -1;
  stw r0, _unk_80385990;
lbl_8019340c:
  addis r4, r4, 0x8000;
  li r3, 0;
  bl IPCWriteReg;
  lis r7, 0x8034;
  lwz r3, _unk_80385990;
  addi r6, r7, 0x55c0;
  lwz r4, 0x55c0(r7);
  lwz r5, 8(r6);
  addi r0, r3, -1;
  stw r0, _unk_80385990;
  addi r4, r4, 1;
  addi r0, r5, 1;
  li r3, 1;
  clrlwi r0, r0, 0x1c;
  stw r4, 0x55c0(r7);
  stw r0, 8(r6);
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 1;
  bl IPCWriteReg;
lbl_80193460:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: IPCCltInit
// PAL: 0x80193478..0x8019352c
MARK_BINARY_BLOB(IPCCltInit, 0x80193478, 0x8019352c);
asm UNKNOWN_FUNCTION(IPCCltInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lwz r0, _unk_8038680c;
  stw r31, 0x1c(r1);
  cmpwi r0, 0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  bne lbl_8019350c;
  li r0, 1;
  stw r0, _unk_8038680c;
  bl IPCInit;
  bl IPCGetBufferLo;
  mr r29, r3;
  addi r31, r3, 0x1000;
  bl IPCGetBufferHi;
  cmplw r31, r3;
  ble lbl_801934cc;
  li r30, -22;
  b lbl_8019350c;
lbl_801934cc:
  mr r3, r29;
  li r4, 0x1000;
  bl iosCreateHeap;
  stw r3, _unk_80385994;
  mr r3, r31;
  bl IPCSetBufferLo;
  lis r4, 0x8019;
  li r3, 0x1b;
  addi r4, r4, 0x32cc;
  bl __OSSetInterruptHandler;
  li r3, 0x10;
  bl __OSUnmaskInterrupts;
  li r3, 1;
  li r4, 0x38;
  bl IPCWriteReg;
  bl IPCiProfInit;
lbl_8019350c:
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

// Symbol: IPCCltReInit
// PAL: 0x8019352c..0x801935a0
MARK_BINARY_BLOB(IPCCltReInit, 0x8019352c, 0x801935a0);
asm UNKNOWN_FUNCTION(IPCCltReInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  bl IPCGetBufferLo;
  mr r29, r3;
  addi r31, r3, 0x800;
  bl IPCGetBufferHi;
  cmplw r31, r3;
  ble lbl_80193568;
  li r30, -22;
  b lbl_80193580;
lbl_80193568:
  mr r3, r29;
  li r4, 0x800;
  bl iosCreateHeap;
  stw r3, _unk_80385994;
  mr r3, r31;
  bl IPCSetBufferLo;
lbl_80193580:
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

// Symbol: __ios_Ipc2
// PAL: 0x801935a0..0x801937e0
MARK_BINARY_BLOB(__ios_Ipc2, 0x801935a0, 0x801937e0);
asm UNKNOWN_FUNCTION(__ios_Ipc2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_801935d4;
  li r31, -4;
  b lbl_801937a0;
lbl_801935d4:
  cmpwi r4, 0;
  bne lbl_801935e4;
  addi r3, r3, 0x2c;
  bl OSInitThreadQueue;
lbl_801935e4:
  mr r3, r28;
  li r4, 0x20;
  bl DCFlushRange;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  mr r30, r3;
  addi r3, r4, 0x55c0;
  lwz r4, 0x55c0(r4);
  lwz r0, 4(r3);
  li r31, 0;
  cmplw r0, r4;
  bge lbl_8019361c;
  subf r0, r4, r0;
  b lbl_80193638;
lbl_8019361c:
  subf r4, r4, r0;
  li r3, 0x10;
  addi r0, r4, -16;
  orc r3, r4, r3;
  srwi r0, r0, 1;
  subf r0, r0, r3;
  srwi r0, r0, 0x1f;
lbl_80193638:
  cmpwi r0, 0;
  beq lbl_80193648;
  li r31, -8;
  b lbl_80193688;
lbl_80193648:
  lis r6, 0x8034;
  mr r3, r28;
  addi r6, r6, 0x55c0;
  lwz r0, 0xc(r6);
  slwi r0, r0, 2;
  add r4, r6, r0;
  stw r28, 0x10(r4);
  lwz r5, 0xc(r6);
  lwz r4, 4(r6);
  addi r0, r5, 1;
  clrlwi r5, r0, 0x1c;
  addi r0, r4, 1;
  stw r5, 0xc(r6);
  stw r0, 4(r6);
  lwz r4, 8(r28);
  bl IPCiProfQueueReq;
lbl_80193688:
  cmpwi r31, 0;
  beq lbl_801936b0;
  mr r3, r30;
  bl OSRestoreInterrupts;
  cmpwi r29, 0;
  beq lbl_801937a0;
  lwz r3, _unk_80385994;
  mr r4, r28;
  bl iosFree;
  b lbl_801937a0;
lbl_801936b0:
  lwz r0, _unk_80385990;
  cmpwi r0, 0;
  ble lbl_8019377c;
  lis r4, 0x8034;
  addi r3, r4, 0x55c0;
  lwz r4, 0x55c0(r4);
  lwz r0, 4(r3);
  cmplw r0, r4;
  bge lbl_801936dc;
  subf r0, r4, r0;
  b lbl_801936e8;
lbl_801936dc:
  subf r0, r4, r0;
  cntlzw r0, r0;
  srwi r0, r0, 5;
lbl_801936e8:
  cmpwi r0, 0;
  bne lbl_8019377c;
  lis r3, 0x8034;
  addi r3, r3, 0x55c0;
  lwz r0, 8(r3);
  slwi r0, r0, 2;
  add r3, r3, r0;
  lwz r4, 0x10(r3);
  cmpwi r4, 0;
  beq lbl_8019377c;
  lwz r0, 0x28(r4);
  cmpwi r0, 0;
  beq lbl_80193728;
  lwz r3, _unk_80385990;
  addi r0, r3, -1;
  stw r0, _unk_80385990;
lbl_80193728:
  addis r4, r4, 0x8000;
  li r3, 0;
  bl IPCWriteReg;
  lis r7, 0x8034;
  lwz r3, _unk_80385990;
  addi r6, r7, 0x55c0;
  lwz r4, 0x55c0(r7);
  lwz r5, 8(r6);
  addi r0, r3, -1;
  stw r0, _unk_80385990;
  addi r4, r4, 1;
  addi r0, r5, 1;
  li r3, 1;
  clrlwi r0, r0, 0x1c;
  stw r4, 0x55c0(r7);
  stw r0, 8(r6);
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 1;
  bl IPCWriteReg;
lbl_8019377c:
  cmpwi r29, 0;
  bne lbl_8019378c;
  addi r3, r28, 0x2c;
  bl OSSleepThread;
lbl_8019378c:
  mr r3, r30;
  bl OSRestoreInterrupts;
  cmpwi r29, 0;
  bne lbl_801937a0;
  lwz r31, 4(r28);
lbl_801937a0:
  cmpwi r28, 0;
  beq lbl_801937bc;
  cmpwi r29, 0;
  bne lbl_801937bc;
  lwz r3, _unk_80385994;
  mr r4, r28;
  bl iosFree;
lbl_801937bc:
  mr r3, r31;
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

// Symbol: IOS_OpenAsync
// PAL: 0x801937e0..0x801938f8
MARK_BINARY_BLOB(IOS_OpenAsync, 0x801937e0, 0x801938f8);
asm s32 IOS_OpenAsync(const char*, u32, IOSCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  addic. r0, r1, 8;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r31, r6;
  li r30, 0;
  bne lbl_80193818;
  li r30, -4;
  b lbl_80193860;
lbl_80193818:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_8019383c;
  li r30, -22;
  b lbl_80193860;
lbl_8019383c:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 1;
  lwz r4, 8(r1);
  stw r31, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r5, 8(r3);
lbl_80193860:
  cmpwi r30, 0;
  bne lbl_801938dc;
  lwz r31, 8(r1);
  li r30, 0;
  cmpwi r31, 0;
  bne lbl_80193880;
  li r30, -4;
  b lbl_801938c4;
lbl_80193880:
  mr r3, r27;
  li r4, 0x40;
  b lbl_80193890;
lbl_8019388c:
  addi r3, r3, 1;
lbl_80193890:
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_801938a8;
  cmpwi r4, 0;
  addi r4, r4, -1;
  bne lbl_8019388c;
lbl_801938a8:
  subf r4, r27, r3;
  mr r3, r27;
  addi r4, r4, 1;
  bl DCFlushRange;
  addis r0, r27, 0x8000;
  stw r0, 0xc(r31);
  stw r28, 0x10(r31);
lbl_801938c4:
  cmpwi r30, 0;
  bne lbl_801938dc;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r30, r3;
lbl_801938dc:
  addi r11, r1, 0x30;
  mr r3, r30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_Open
// PAL: 0x801938f8..0x80193a18
MARK_BINARY_BLOB(IOS_Open, 0x801938f8, 0x80193a18);
asm s32 IOS_Open(const char*, u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_80193930;
  li r30, -4;
  b lbl_80193978;
lbl_80193930:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193954;
  li r30, -22;
  b lbl_80193978;
lbl_80193954:
  li r5, 0;
  li r0, 1;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r5, 8(r3);
lbl_80193978:
  cmpwi r30, 0;
  bne lbl_801939f4;
  lwz r31, 8(r1);
  li r30, 0;
  cmpwi r31, 0;
  bne lbl_80193998;
  li r30, -4;
  b lbl_801939dc;
lbl_80193998:
  mr r3, r28;
  li r4, 0x40;
  b lbl_801939a8;
lbl_801939a4:
  addi r3, r3, 1;
lbl_801939a8:
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_801939c0;
  cmpwi r4, 0;
  addi r4, r4, -1;
  bne lbl_801939a4;
lbl_801939c0:
  subf r4, r28, r3;
  mr r3, r28;
  addi r4, r4, 1;
  bl DCFlushRange;
  addis r0, r28, 0x8000;
  stw r0, 0xc(r31);
  stw r29, 0x10(r31);
lbl_801939dc:
  cmpwi r30, 0;
  bne lbl_801939f4;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r30, r3;
lbl_801939f4:
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

// Symbol: IOS_CloseAsync
// PAL: 0x80193a18..0x80193ad8
MARK_BINARY_BLOB(IOS_CloseAsync, 0x80193a18, 0x80193ad8);
asm UNKNOWN_FUNCTION(IOS_CloseAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_80193a54;
  li r31, -4;
  b lbl_80193a9c;
lbl_80193a54:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193a78;
  li r31, -22;
  b lbl_80193a9c;
lbl_80193a78:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 2;
  lwz r4, 8(r1);
  stw r30, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r28, 8(r3);
lbl_80193a9c:
  cmpwi r31, 0;
  bne lbl_80193ab4;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80193ab4:
  mr r3, r31;
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

// Symbol: IOS_Close
// PAL: 0x80193ad8..0x80193b80
MARK_BINARY_BLOB(IOS_Close, 0x80193ad8, 0x80193b80);
asm s32 IOS_Close(u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r3;
  bne lbl_80193b04;
  li r31, -4;
  b lbl_80193b4c;
lbl_80193b04:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193b28;
  li r31, -22;
  b lbl_80193b4c;
lbl_80193b28:
  li r5, 0;
  li r0, 2;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r30, 8(r3);
lbl_80193b4c:
  cmpwi r31, 0;
  bne lbl_80193b64;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80193b64:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: IOS_ReadAsync
// PAL: 0x80193b80..0x80193c80
MARK_BINARY_BLOB(IOS_ReadAsync, 0x80193b80, 0x80193c80);
asm UNKNOWN_FUNCTION(IOS_ReadAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  addic. r0, r1, 8;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r31, r7;
  li r30, 0;
  bne lbl_80193bbc;
  li r30, -4;
  b lbl_80193c04;
lbl_80193bbc:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193be0;
  li r30, -22;
  b lbl_80193c04;
lbl_80193be0:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 3;
  lwz r4, 8(r1);
  stw r31, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r26, 8(r3);
lbl_80193c04:
  cmpwi r30, 0;
  bne lbl_80193c64;
  lwz r31, 8(r1);
  li r30, 0;
  cmpwi r31, 0;
  bne lbl_80193c24;
  li r30, -4;
  b lbl_80193c4c;
lbl_80193c24:
  mr r3, r27;
  mr r4, r28;
  bl DCInvalidateRange;
  cmpwi r27, 0;
  beq lbl_80193c40;
  addis r0, r27, 0x8000;
  b lbl_80193c44;
lbl_80193c40:
  li r0, 0;
lbl_80193c44:
  stw r0, 0xc(r31);
  stw r28, 0x10(r31);
lbl_80193c4c:
  cmpwi r30, 0;
  bne lbl_80193c64;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r30, r3;
lbl_80193c64:
  addi r11, r1, 0x30;
  mr r3, r30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_Read
// PAL: 0x80193c80..0x80193d88
MARK_BINARY_BLOB(IOS_Read, 0x80193c80, 0x80193d88);
asm UNKNOWN_FUNCTION(IOS_Read) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r4;
  bne lbl_80193cbc;
  li r30, -4;
  b lbl_80193d04;
lbl_80193cbc:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193ce0;
  li r30, -22;
  b lbl_80193d04;
lbl_80193ce0:
  li r5, 0;
  li r0, 3;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r31, 8(r3);
lbl_80193d04:
  cmpwi r30, 0;
  bne lbl_80193d64;
  lwz r31, 8(r1);
  li r30, 0;
  cmpwi r31, 0;
  bne lbl_80193d24;
  li r30, -4;
  b lbl_80193d4c;
lbl_80193d24:
  mr r3, r28;
  mr r4, r29;
  bl DCInvalidateRange;
  cmpwi r28, 0;
  beq lbl_80193d40;
  addis r0, r28, 0x8000;
  b lbl_80193d44;
lbl_80193d40:
  li r0, 0;
lbl_80193d44:
  stw r0, 0xc(r31);
  stw r29, 0x10(r31);
lbl_80193d4c:
  cmpwi r30, 0;
  bne lbl_80193d64;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r30, r3;
lbl_80193d64:
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

// Symbol: IOS_WriteAsync
// PAL: 0x80193d88..0x80193e88
MARK_BINARY_BLOB(IOS_WriteAsync, 0x80193d88, 0x80193e88);
asm UNKNOWN_FUNCTION(IOS_WriteAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  addic. r0, r1, 8;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  li r31, 0;
  bne lbl_80193dc4;
  li r31, -4;
  b lbl_80193e0c;
lbl_80193dc4:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193de8;
  li r31, -22;
  b lbl_80193e0c;
lbl_80193de8:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 4;
  lwz r4, 8(r1);
  stw r30, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r26, 8(r3);
lbl_80193e0c:
  cmpwi r31, 0;
  bne lbl_80193e6c;
  lwz r5, 8(r1);
  li r31, 0;
  cmpwi r5, 0;
  bne lbl_80193e2c;
  li r31, -4;
  b lbl_80193e54;
lbl_80193e2c:
  cmpwi r27, 0;
  beq lbl_80193e3c;
  addis r0, r27, 0x8000;
  b lbl_80193e40;
lbl_80193e3c:
  li r0, 0;
lbl_80193e40:
  stw r0, 0xc(r5);
  mr r3, r27;
  mr r4, r28;
  stw r28, 0x10(r5);
  bl DCFlushRange;
lbl_80193e54:
  cmpwi r31, 0;
  bne lbl_80193e6c;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80193e6c:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_Write
// PAL: 0x80193e88..0x80193f90
MARK_BINARY_BLOB(IOS_Write, 0x80193e88, 0x80193f90);
asm UNKNOWN_FUNCTION(IOS_Write) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_80193ec4;
  li r31, -4;
  b lbl_80193f0c;
lbl_80193ec4:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193ee8;
  li r31, -22;
  b lbl_80193f0c;
lbl_80193ee8:
  li r5, 0;
  li r0, 4;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r28, 8(r3);
lbl_80193f0c:
  cmpwi r31, 0;
  bne lbl_80193f6c;
  lwz r5, 8(r1);
  li r31, 0;
  cmpwi r5, 0;
  bne lbl_80193f2c;
  li r31, -4;
  b lbl_80193f54;
lbl_80193f2c:
  cmpwi r29, 0;
  beq lbl_80193f3c;
  addis r0, r29, 0x8000;
  b lbl_80193f40;
lbl_80193f3c:
  li r0, 0;
lbl_80193f40:
  stw r0, 0xc(r5);
  mr r3, r29;
  mr r4, r30;
  stw r30, 0x10(r5);
  bl DCFlushRange;
lbl_80193f54:
  cmpwi r31, 0;
  bne lbl_80193f6c;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80193f6c:
  mr r3, r31;
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

// Symbol: IOS_SeekAsync
// PAL: 0x80193f90..0x80194070
MARK_BINARY_BLOB(IOS_SeekAsync, 0x80193f90, 0x80194070);
asm UNKNOWN_FUNCTION(IOS_SeekAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  addic. r0, r1, 8;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  li r31, 0;
  bne lbl_80193fcc;
  li r31, -4;
  b lbl_80194014;
lbl_80193fcc:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80193ff0;
  li r31, -22;
  b lbl_80194014;
lbl_80193ff0:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 5;
  lwz r4, 8(r1);
  stw r30, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r26, 8(r3);
lbl_80194014:
  cmpwi r31, 0;
  bne lbl_80194054;
  lwz r3, 8(r1);
  li r31, 0;
  cmpwi r3, 0;
  bne lbl_80194034;
  li r31, -4;
  b lbl_8019403c;
lbl_80194034:
  stw r27, 0xc(r3);
  stw r28, 0x10(r3);
lbl_8019403c:
  cmpwi r31, 0;
  bne lbl_80194054;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80194054:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_Seek
// PAL: 0x80194070..0x80194158
MARK_BINARY_BLOB(IOS_Seek, 0x80194070, 0x80194158);
asm UNKNOWN_FUNCTION(IOS_Seek) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addic. r0, r1, 8;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bne lbl_801940ac;
  li r31, -4;
  b lbl_801940f4;
lbl_801940ac:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_801940d0;
  li r31, -22;
  b lbl_801940f4;
lbl_801940d0:
  li r5, 0;
  li r0, 5;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r28, 8(r3);
lbl_801940f4:
  cmpwi r31, 0;
  bne lbl_80194134;
  lwz r3, 8(r1);
  li r31, 0;
  cmpwi r3, 0;
  bne lbl_80194114;
  li r31, -4;
  b lbl_8019411c;
lbl_80194114:
  stw r29, 0xc(r3);
  stw r30, 0x10(r3);
lbl_8019411c:
  cmpwi r31, 0;
  bne lbl_80194134;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80194134:
  mr r3, r31;
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

// Symbol: IOS_IoctlAsync
// PAL: 0x80194158..0x80194290
MARK_BINARY_BLOB(IOS_IoctlAsync, 0x80194158, 0x80194290);
asm UNKNOWN_FUNCTION(IOS_IoctlAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_23;
  addic. r0, r1, 8;
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  mr r30, r10;
  li r31, 0;
  bne lbl_801941a0;
  li r31, -4;
  b lbl_801941e8;
lbl_801941a0:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_801941c4;
  li r31, -22;
  b lbl_801941e8;
lbl_801941c4:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 6;
  lwz r4, 8(r1);
  stw r30, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r23, 8(r3);
lbl_801941e8:
  cmpwi r31, 0;
  bne lbl_80194274;
  lwz r5, 8(r1);
  li r31, 0;
  cmpwi r5, 0;
  bne lbl_80194208;
  li r31, -4;
  b lbl_8019425c;
lbl_80194208:
  cmpwi r27, 0;
  stw r24, 0xc(r5);
  beq lbl_8019421c;
  addis r0, r27, 0x8000;
  b lbl_80194220;
lbl_8019421c:
  li r0, 0;
lbl_80194220:
  stw r0, 0x18(r5);
  cmpwi r25, 0;
  stw r28, 0x1c(r5);
  beq lbl_80194238;
  addis r0, r25, 0x8000;
  b lbl_8019423c;
lbl_80194238:
  li r0, 0;
lbl_8019423c:
  stw r0, 0x10(r5);
  mr r3, r25;
  mr r4, r26;
  stw r26, 0x14(r5);
  bl DCFlushRange;
  mr r3, r27;
  mr r4, r28;
  bl DCFlushRange;
lbl_8019425c:
  cmpwi r31, 0;
  bne lbl_80194274;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_80194274:
  addi r11, r1, 0x40;
  mr r3, r31;
  bl _restgpr_23;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: IOS_Ioctl
// PAL: 0x80194290..0x801943c0
MARK_BINARY_BLOB(IOS_Ioctl, 0x80194290, 0x801943c0);
asm s32 IOS_Ioctl(s32, s32, void*, u32, void*, u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  addic. r0, r1, 8;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  mr r30, r8;
  li r31, 0;
  bne lbl_801942d0;
  li r31, -4;
  b lbl_80194318;
lbl_801942d0:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_801942f4;
  li r31, -22;
  b lbl_80194318;
lbl_801942f4:
  li r5, 0;
  li r0, 6;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r25, 8(r3);
lbl_80194318:
  cmpwi r31, 0;
  bne lbl_801943a4;
  lwz r5, 8(r1);
  li r31, 0;
  cmpwi r5, 0;
  bne lbl_80194338;
  li r31, -4;
  b lbl_8019438c;
lbl_80194338:
  cmpwi r29, 0;
  stw r26, 0xc(r5);
  beq lbl_8019434c;
  addis r0, r29, 0x8000;
  b lbl_80194350;
lbl_8019434c:
  li r0, 0;
lbl_80194350:
  stw r0, 0x18(r5);
  cmpwi r27, 0;
  stw r30, 0x1c(r5);
  beq lbl_80194368;
  addis r0, r27, 0x8000;
  b lbl_8019436c;
lbl_80194368:
  li r0, 0;
lbl_8019436c:
  stw r0, 0x10(r5);
  mr r3, r27;
  mr r4, r28;
  stw r28, 0x14(r5);
  bl DCFlushRange;
  mr r3, r29;
  mr r4, r30;
  bl DCFlushRange;
lbl_8019438c:
  cmpwi r31, 0;
  bne lbl_801943a4;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_801943a4:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: __ios_Ioctlv
// PAL: 0x801943c0..0x801944fc
MARK_BINARY_BLOB(__ios_Ioctlv, 0x801943c0, 0x801944fc);
asm UNKNOWN_FUNCTION(__ios_Ioctlv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r29, r3;
  mr r30, r7;
  li r31, 0;
  bne lbl_801943f0;
  li r31, -4;
  b lbl_801944e0;
lbl_801943f0:
  stw r4, 0xc(r3);
  slwi r27, r5, 3;
  li r26, 0;
  li r28, 0;
  stw r5, 0x10(r3);
  stw r6, 0x14(r3);
  stw r7, 0x18(r3);
  b lbl_80194454;
lbl_80194410:
  lwz r3, 0x18(r29);
  add r0, r28, r27;
  add r4, r3, r0;
  lwzx r3, r3, r0;
  lwz r4, 4(r4);
  bl DCFlushRange;
  lwz r4, 0x18(r29);
  add r3, r28, r27;
  lwzx r5, r4, r3;
  cmpwi r5, 0;
  beq lbl_80194444;
  addis r0, r5, 0x8000;
  b lbl_80194448;
lbl_80194444:
  li r0, 0;
lbl_80194448:
  stwx r0, r4, r3;
  addi r28, r28, 8;
  addi r26, r26, 1;
lbl_80194454:
  lwz r0, 0x14(r29);
  cmplw r26, r0;
  blt lbl_80194410;
  li r27, 0;
  li r28, 0;
  b lbl_801944a8;
lbl_8019446c:
  lwz r0, 0x18(r29);
  add r4, r0, r28;
  lwzx r3, r28, r0;
  lwz r4, 4(r4);
  bl DCFlushRange;
  lwz r3, 0x18(r29);
  lwzx r4, r3, r28;
  cmpwi r4, 0;
  beq lbl_80194498;
  addis r0, r4, 0x8000;
  b lbl_8019449c;
lbl_80194498:
  li r0, 0;
lbl_8019449c:
  stwx r0, r3, r28;
  addi r28, r28, 8;
  addi r27, r27, 1;
lbl_801944a8:
  lwz r4, 0x10(r29);
  cmplw r27, r4;
  blt lbl_8019446c;
  lwz r0, 0x14(r29);
  lwz r3, 0x18(r29);
  add r0, r4, r0;
  slwi r4, r0, 3;
  bl DCFlushRange;
  cmpwi r30, 0;
  beq lbl_801944d8;
  addis r0, r30, 0x8000;
  b lbl_801944dc;
lbl_801944d8:
  li r0, 0;
lbl_801944dc:
  stw r0, 0x18(r29);
lbl_801944e0:
  addi r11, r1, 0x20;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: IOS_IoctlvAsync
// PAL: 0x801944fc..0x801945e0
MARK_BINARY_BLOB(IOS_IoctlvAsync, 0x801944fc, 0x801945e0);
asm UNKNOWN_FUNCTION(IOS_IoctlvAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  addic. r0, r1, 8;
  mr r24, r3;
  mr r25, r4;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  mr r29, r8;
  mr r30, r9;
  li r31, 0;
  bne lbl_80194540;
  li r31, -4;
  b lbl_80194588;
lbl_80194540:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80194564;
  li r31, -22;
  b lbl_80194588;
lbl_80194564:
  stw r29, 0x20(r3);
  li r5, 0;
  li r0, 7;
  lwz r4, 8(r1);
  stw r30, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r24, 8(r3);
lbl_80194588:
  cmpwi r31, 0;
  bne lbl_801945c4;
  lwz r3, 8(r1);
  mr r4, r25;
  mr r5, r26;
  mr r6, r27;
  mr r7, r28;
  bl __ios_Ioctlv;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_801945c4;
  lwz r3, 8(r1);
  mr r4, r29;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_801945c4:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_Ioctlv
// PAL: 0x801945e0..0x801946bc
MARK_BINARY_BLOB(IOS_Ioctlv, 0x801945e0, 0x801946bc);
asm UNKNOWN_FUNCTION(IOS_Ioctlv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  addic. r0, r1, 8;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  li r31, 0;
  bne lbl_8019461c;
  li r31, -4;
  b lbl_80194664;
lbl_8019461c:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80194640;
  li r31, -22;
  b lbl_80194664;
lbl_80194640:
  li r5, 0;
  li r0, 7;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r26, 8(r3);
lbl_80194664:
  cmpwi r31, 0;
  bne lbl_801946a0;
  lwz r3, 8(r1);
  mr r4, r27;
  mr r5, r28;
  mr r6, r29;
  mr r7, r30;
  bl __ios_Ioctlv;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_801946a0;
  lwz r3, 8(r1);
  li r4, 0;
  bl __ios_Ipc2;
  mr r31, r3;
lbl_801946a0:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: IOS_IoctlvReboot
// PAL: 0x801946bc..0x801949b8
MARK_BINARY_BLOB(IOS_IoctlvReboot, 0x801946bc, 0x801949b8);
asm UNKNOWN_FUNCTION(IOS_IoctlvReboot) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r30, r6;
  mr r29, r7;
  bl OSDisableInterrupts;
  lwz r0, _unk_80386800;
  cmpwi r0, 0;
  beq lbl_80194700;
  bl OSRestoreInterrupts;
  li r31, -10;
  b lbl_8019499c;
lbl_80194700:
  li r0, 1;
  stw r0, _unk_80386800;
  bl OSRestoreInterrupts;
  addic. r0, r1, 8;
  li r31, 0;
  bne lbl_80194720;
  li r31, -4;
  b lbl_80194768;
lbl_80194720:
  lwz r3, _unk_80385994;
  li r4, 0x40;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  stw r3, 8(r1);
  bne lbl_80194744;
  li r31, -22;
  b lbl_80194768;
lbl_80194744:
  li r5, 0;
  li r0, 7;
  stw r5, 0x20(r3);
  lwz r4, 8(r1);
  stw r5, 0x24(r4);
  lwz r4, 8(r1);
  stw r5, 0x28(r4);
  stw r0, 0(r3);
  stw r26, 8(r3);
lbl_80194768:
  cmpwi r31, 0;
  bne lbl_80194974;
  lwz r3, 8(r1);
  li r0, 1;
  mr r4, r27;
  mr r5, r28;
  stw r3, _unk_80386808;
  mr r6, r30;
  mr r7, r29;
  stw r0, 0x28(r3);
  lwz r3, 8(r1);
  bl __ios_Ioctlv;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80194974;
  lis r29, 0x8034;
  lwz r4, 8(r1);
  addi r3, r29, 0x5620;
  li r5, 0x40;
  bl memcpy;
  addi r3, r29, 0x5620;
  lwz r29, 8(r1);
  stw r3, _unk_80386804;
  addi r3, r3, 0x2c;
  bl OSInitThreadQueue;
  mr r3, r29;
  li r4, 0x20;
  bl DCFlushRange;
  bl OSDisableInterrupts;
  lis r4, 0x8034;
  mr r30, r3;
  addi r3, r4, 0x55c0;
  lwz r0, 0x55c0(r4);
  lwz r3, 4(r3);
  li r31, 0;
  cmplw r3, r0;
  bge lbl_80194808;
  subfic r0, r0, 0;
  add r0, r0, r3;
  b lbl_80194824;
lbl_80194808:
  subf r4, r0, r3;
  li r3, 0x10;
  addi r0, r4, -16;
  orc r3, r4, r3;
  srwi r0, r0, 1;
  subf r0, r0, r3;
  srwi r0, r0, 0x1f;
lbl_80194824:
  cmpwi r0, 0;
  beq lbl_80194834;
  li r31, -8;
  b lbl_80194874;
lbl_80194834:
  lis r6, 0x8034;
  mr r3, r29;
  addi r6, r6, 0x55c0;
  lwz r0, 0xc(r6);
  slwi r0, r0, 2;
  add r4, r6, r0;
  stw r29, 0x10(r4);
  lwz r5, 0xc(r6);
  lwz r4, 4(r6);
  addi r0, r5, 1;
  clrlwi r5, r0, 0x1c;
  addi r0, r4, 1;
  stw r5, 0xc(r6);
  stw r0, 4(r6);
  lwz r4, 8(r29);
  bl IPCiProfQueueReq;
lbl_80194874:
  cmpwi r31, 0;
  beq lbl_80194888;
  mr r3, r30;
  bl OSRestoreInterrupts;
  b lbl_80194974;
lbl_80194888:
  lwz r0, _unk_80385990;
  cmpwi r0, 0;
  ble lbl_80194958;
  lis r4, 0x8034;
  addi r3, r4, 0x55c0;
  lwz r0, 0x55c0(r4);
  lwz r3, 4(r3);
  cmplw r3, r0;
  bge lbl_801948b8;
  subfic r0, r0, 0;
  add r0, r0, r3;
  b lbl_801948c4;
lbl_801948b8:
  subf r0, r0, r3;
  cntlzw r0, r0;
  srwi r0, r0, 5;
lbl_801948c4:
  cmpwi r0, 0;
  bne lbl_80194958;
  lis r3, 0x8034;
  addi r3, r3, 0x55c0;
  lwz r0, 8(r3);
  slwi r0, r0, 2;
  add r3, r3, r0;
  lwz r4, 0x10(r3);
  cmpwi r4, 0;
  beq lbl_80194958;
  lwz r0, 0x28(r4);
  cmpwi r0, 0;
  beq lbl_80194904;
  lwz r3, _unk_80385990;
  addi r0, r3, -1;
  stw r0, _unk_80385990;
lbl_80194904:
  addis r4, r4, 0x8000;
  li r3, 0;
  bl IPCWriteReg;
  lis r7, 0x8034;
  lwz r3, _unk_80385990;
  addi r6, r7, 0x55c0;
  lwz r4, 0x55c0(r7);
  lwz r5, 8(r6);
  addi r0, r3, -1;
  stw r0, _unk_80385990;
  addi r4, r4, 1;
  addi r0, r5, 1;
  li r3, 1;
  clrlwi r0, r0, 0x1c;
  stw r4, 0x55c0(r7);
  stw r0, 8(r6);
  bl IPCReadReg;
  rlwinm r0, r3, 0, 0x1a, 0x1b;
  li r3, 1;
  ori r4, r0, 1;
  bl IPCWriteReg;
lbl_80194958:
  lwz r3, _unk_80386804;
  addi r3, r3, 0x2c;
  bl OSSleepThread;
  mr r3, r30;
  bl OSRestoreInterrupts;
  lwz r3, _unk_80386804;
  lwz r31, 4(r3);
lbl_80194974:
  lwz r4, 8(r1);
  li r0, 0;
  stw r0, _unk_80386800;
  cmpwi r4, 0;
  stw r0, _unk_80386808;
  beq lbl_8019499c;
  cmpwi r31, 0;
  beq lbl_8019499c;
  lwz r3, _unk_80385994;
  bl iosFree;
lbl_8019499c:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
