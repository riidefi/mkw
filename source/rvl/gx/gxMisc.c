#include "gxMisc.h"

#include <rvl/base/ppcArch.h>
#include <rvl/os/os.h>
#include <rvl/os/osContext.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "gx.h"
#include "gxInit.h"
#include "gxFifo.h"
#include "gxGeometry.h"
#include "gxTransform.h"

// Symbol: GXSetMisc
// PAL: 0x8016e5c8..0x8016e654
MARK_BINARY_BLOB(GXSetMisc, 0x8016e5c8, 0x8016e654);
asm UNKNOWN_FUNCTION(GXSetMisc) {
  // clang-format off
  nofralloc;
  cmpwi r3, 2;
  beq lbl_8016e624;
  bge lbl_8016e5e4;
  cmpwi r3, 0;
  beqlr;
  bge lbl_8016e5f0;
  blr;
lbl_8016e5e4:
  cmpwi r3, 4;
  bgelr;
  b lbl_8016e63c;
lbl_8016e5f0:
  clrlwi. r0, r4, 0x10;
  lwz r5, gx;
  sth r4, 4(r5);
  cntlzw r3, r0;
  li r0, 1;
  rlwinm r3, r3, 0x1b, 0x10, 0x1f;
  sth r3, 0(r5);
  sth r0, 2(r5);
  beqlr;
  lwz r0, 0x5fc(r5);
  ori r0, r0, 8;
  stw r0, 0x5fc(r5);
  blr;
lbl_8016e624:
  neg r0, r4;
  lwz r3, gx;
  or r0, r0, r4;
  srwi r0, r0, 0x1f;
  stb r0, 0x5f9(r3);
  blr;
lbl_8016e63c:
  neg r0, r4;
  lwz r3, gx;
  or r0, r0, r4;
  srwi r0, r0, 0x1f;
  stb r0, 0x5fa(r3);
  blr;
  // clang-format on
}

// Symbol: GXFlush
// PAL: 0x8016e654..0x8016e6b0
MARK_BINARY_BLOB(GXFlush, 0x8016e654, 0x8016e6b0);
asm UNKNOWN_FUNCTION(GXFlush) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lwz r3, gx;
  stw r0, 0x14(r1);
  lwz r0, 0x5fc(r3);
  cmpwi r0, 0;
  beq lbl_8016e674;
  bl __GXSetDirtyState;
lbl_8016e674:
  li r0, 0;
  lis r3, 0xcc01;
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  bl PPCSync;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXResetWriteGatherPipe
// PAL: 0x8016e6b0..0x8016e6e4
MARK_BINARY_BLOB(GXResetWriteGatherPipe, 0x8016e6b0, 0x8016e6e4);
asm UNKNOWN_FUNCTION(GXResetWriteGatherPipe) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
lbl_8016e6bc:
  bl PPCMfwpar;
  clrlwi. r0, r3, 0x1f;
  bne lbl_8016e6bc;
  lis r3, 0xc01;
  addi r3, r3, -32768;
  bl PPCMtwpar;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __GXAbort
// PAL: 0x8016e6e4..0x8016e848
MARK_BINARY_BLOB(__GXAbort, 0x8016e6e4, 0x8016e848);
asm UNKNOWN_FUNCTION(__GXAbort) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lwz r3, gx;
  lbz r0, 0x5fa(r3);
  cmpwi r0, 0;
  beq lbl_8016e7a4;
  bl __GXIsGPFifoReady;
  clrlwi. r0, r3, 0x18;
  beq lbl_8016e7a4;
  lwz r5, -0x646c(r13);
  lhz r0, 0x4e(r5);
lbl_8016e71c:
  mr r3, r0;
  lhz r4, 0x50(r5);
  lhz r0, 0x4e(r5);
  cmplw r0, r3;
  bne lbl_8016e71c;
  slwi r3, r0, 0x10;
  li r0, 0;
  or r27, r3, r4;
  li r29, 8;
  xoris r28, r0, 0x8000;
lbl_8016e744:
  bl OSGetTime;
  mr r31, r4;
  mr r30, r3;
lbl_8016e750:
  bl OSGetTime;
  subfc r4, r31, r4;
  subfe r0, r30, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r29;
  subfe r3, r3, r28;
  subfe r3, r28, r28;
  neg. r3, r3;
  beq lbl_8016e750;
  lwz r5, -0x646c(r13);
  lhz r0, 0x4e(r5);
lbl_8016e77c:
  mr r3, r0;
  lhz r4, 0x50(r5);
  lhz r0, 0x4e(r5);
  cmplw r0, r3;
  bne lbl_8016e77c;
  slwi r0, r0, 0x10;
  or r0, r0, r4;
  cmplw r0, r27;
  mr r27, r0;
  bne lbl_8016e744;
lbl_8016e7a4:
  li r0, 1;
  lis r3, 0xcc00;
  stw r0, 0x3018(r3);
  bl OSGetTime;
  li r0, 0;
  mr r31, r4;
  mr r30, r3;
  li r29, 0x32;
  xoris r28, r0, 0x8000;
lbl_8016e7c8:
  bl OSGetTime;
  subfc r4, r31, r4;
  subfe r0, r30, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r29;
  subfe r3, r3, r28;
  subfe r3, r28, r28;
  neg. r3, r3;
  beq lbl_8016e7c8;
  li r30, 0;
  lis r3, 0xcc00;
  stw r30, 0x3018(r3);
  bl OSGetTime;
  xoris r31, r30, 0x8000;
  mr r28, r4;
  mr r29, r3;
  li r30, 5;
lbl_8016e80c:
  bl OSGetTime;
  subfc r4, r28, r4;
  subfe r0, r29, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r30;
  subfe r3, r3, r31;
  subfe r3, r31, r31;
  neg. r3, r3;
  beq lbl_8016e80c;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXAbortFrame
// PAL: 0x8016e848..0x8016e9fc
MARK_BINARY_BLOB(GXAbortFrame, 0x8016e848, 0x8016e9fc);
asm UNKNOWN_FUNCTION(GXAbortFrame) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lwz r31, gx;
  lbz r0, 0x5fa(r31);
  cmpwi r0, 0;
  beq lbl_8016e908;
  bl __GXIsGPFifoReady;
  clrlwi. r0, r3, 0x18;
  beq lbl_8016e908;
  lwz r5, -0x646c(r13);
  lhz r3, 0x4e(r5);
lbl_8016e880:
  mr r0, r3;
  lhz r4, 0x50(r5);
  lhz r3, 0x4e(r5);
  cmplw r3, r0;
  bne lbl_8016e880;
  slwi r3, r3, 0x10;
  li r0, 0;
  or r26, r3, r4;
  li r28, 8;
  xoris r27, r0, 0x8000;
lbl_8016e8a8:
  bl OSGetTime;
  mr r30, r4;
  mr r29, r3;
lbl_8016e8b4:
  bl OSGetTime;
  subfc r4, r30, r4;
  subfe r0, r29, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r28;
  subfe r3, r3, r27;
  subfe r3, r27, r27;
  neg. r3, r3;
  beq lbl_8016e8b4;
  lwz r5, -0x646c(r13);
  lhz r4, 0x4e(r5);
lbl_8016e8e0:
  mr r0, r4;
  lhz r3, 0x50(r5);
  lhz r4, 0x4e(r5);
  cmplw r4, r0;
  bne lbl_8016e8e0;
  slwi r0, r4, 0x10;
  or r0, r0, r3;
  cmplw r0, r26;
  mr r26, r0;
  bne lbl_8016e8a8;
lbl_8016e908:
  li r0, 1;
  lis r3, 0xcc00;
  stw r0, 0x3018(r3);
  bl OSGetTime;
  li r0, 0;
  mr r30, r4;
  mr r29, r3;
  li r28, 0x32;
  xoris r27, r0, 0x8000;
lbl_8016e92c:
  bl OSGetTime;
  subfc r4, r30, r4;
  subfe r0, r29, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r28;
  subfe r3, r3, r27;
  subfe r3, r27, r27;
  neg. r3, r3;
  beq lbl_8016e92c;
  li r29, 0;
  lis r3, 0xcc00;
  stw r29, 0x3018(r3);
  bl OSGetTime;
  xoris r30, r29, 0x8000;
  mr r27, r4;
  mr r28, r3;
  li r29, 5;
lbl_8016e970:
  bl OSGetTime;
  subfc r4, r27, r4;
  subfe r0, r28, r3;
  xoris r3, r0, 0x8000;
  subfc r0, r4, r29;
  subfe r3, r3, r30;
  subfe r3, r30, r30;
  neg. r3, r3;
  beq lbl_8016e970;
  bl __GXIsGPFifoReady;
  clrlwi. r0, r3, 0x18;
  beq lbl_8016e9e4;
  bl __GXCleanGPFifo;
  bl __GXInitRevisionBits;
  li r0, 0;
  stw r0, 0x5fc(r31);
  b lbl_8016e9b8;
  bl __GXSetDirtyState;
lbl_8016e9b8:
  li r0, 0;
  lis r3, 0xcc01;
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  stw r0, -0x8000(r3);
  bl PPCSync;
lbl_8016e9e4:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXSetDrawSync
// PAL: 0x8016e9fc..0x8016eab0
MARK_BINARY_BLOB(GXSetDrawSync, 0x8016e9fc, 0x8016eab0);
asm void GXSetDrawSync(u16 token) {
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
  lis r4, 0xcc01;
  li r5, 0x61;
  stb r5, -0x8000(r4);
  oris r6, r29, 0x4800;
  li r0, 0x47;
  lwz r30, gx;
  stw r6, -0x8000(r4);
  rlwimi r6, r29, 0, 0x10, 0x1f;
  rlwimi r6, r0, 0x18, 0, 7;
  mr r29, r3;
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  lwz r0, 0x5fc(r30);
  cmpwi r0, 0;
  beq lbl_8016ea5c;
  bl __GXSetDirtyState;
lbl_8016ea5c:
  li r31, 0;
  lis r3, 0xcc01;
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  bl PPCSync;
  mr r3, r29;
  bl OSRestoreInterrupts;
  sth r31, 2(r30);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXDraw
// PAL: 0x8016eab0..0x8016eb70
MARK_BINARY_BLOB(GXDraw, 0x8016eab0, 0x8016eb70);
asm UNKNOWN_FUNCTION(GXDraw) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl OSDisableInterrupts;
  lis r5, 0xcc01;
  li r0, 0x61;
  lis r4, 0x4500;
  stb r0, -0x8000(r5);
  addi r0, r4, 2;
  lwz r4, gx;
  stw r0, -0x8000(r5);
  mr r30, r3;
  lwz r0, 0x5fc(r4);
  cmpwi r0, 0;
  beq lbl_8016eaf8;
  bl __GXSetDirtyState;
lbl_8016eaf8:
  li r31, 0;
  lis r3, 0xcc01;
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  stw r31, -0x8000(r3);
  bl PPCSync;
  stb r31, -0x6428(r13);
  mr r3, r30;
  bl OSRestoreInterrupts;
  bl OSDisableInterrupts;
  mr r30, r3;
  b lbl_8016eb44;
lbl_8016eb3c:
  addi r3, r13, -25648;
  bl OSSleepThread;
lbl_8016eb44:
  lbz r0, -0x6428(r13);
  cmpwi r0, 0;
  beq lbl_8016eb3c;
  mr r3, r30;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXTexModeSync
// PAL: 0x8016eb70..0x8016eb94
MARK_BINARY_BLOB(GXTexModeSync, 0x8016eb70, 0x8016eb94);
asm UNKNOWN_FUNCTION(GXTexModeSync) {
  // clang-format off
  nofralloc;
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x22c(r5);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  blr;
  // clang-format on
}

// Symbol: GXPokeAlphaMode
// PAL: 0x8016eb94..0x8016eba4
MARK_BINARY_BLOB(GXPokeAlphaMode, 0x8016eb94, 0x8016eba4);
asm UNKNOWN_FUNCTION(GXPokeAlphaMode) {
  // clang-format off
  nofralloc;
  lwz r5, -0x6470(r13);
  rlwimi r4, r3, 8, 0, 0x17;
  sth r4, 6(r5);
  blr;
  // clang-format on
}

// Symbol: GXPokeAlphaRead
// PAL: 0x8016eba4..0x8016ebbc
MARK_BINARY_BLOB(GXPokeAlphaRead, 0x8016eba4, 0x8016ebbc);
asm UNKNOWN_FUNCTION(GXPokeAlphaRead) {
  // clang-format off
  nofralloc;
  li r0, 0;
  lwz r4, -0x6470(r13);
  rlwimi r0, r3, 0, 0x1e, 0x1f;
  ori r0, r0, 4;
  sth r0, 8(r4);
  blr;
  // clang-format on
}

// Symbol: GXPokeAlphaUpdate
// PAL: 0x8016ebbc..0x8016ebd0
MARK_BINARY_BLOB(GXPokeAlphaUpdate, 0x8016ebbc, 0x8016ebd0);
asm UNKNOWN_FUNCTION(GXPokeAlphaUpdate) {
  // clang-format off
  nofralloc;
  lwz r4, -0x6470(r13);
  lhz r0, 2(r4);
  rlwimi r0, r3, 4, 0x1b, 0x1b;
  sth r0, 2(r4);
  blr;
  // clang-format on
}

// Symbol: GXPokeBlendMode
// PAL: 0x8016ebd0..0x8016ec2c
MARK_BINARY_BLOB(GXPokeBlendMode, 0x8016ebd0, 0x8016ec2c);
asm UNKNOWN_FUNCTION(GXPokeBlendMode) {
  // clang-format off
  nofralloc;
  lwz r7, -0x6470(r13);
  cmpwi r3, 1;
  li r0, 0;
  lhz r9, 2(r7);
  beq lbl_8016ebec;
  cmpwi r3, 3;
  bne lbl_8016ebf0;
lbl_8016ebec:
  li r0, 1;
lbl_8016ebf0:
  addi r7, r3, -3;
  rlwimi r9, r0, 0, 0x1f, 0x1f;
  addi r0, r3, -2;
  lwz r3, -0x6470(r13);
  cntlzw r8, r7;
  cntlzw r7, r0;
  li r0, 0x41;
  rlwimi r9, r8, 6, 0x14, 0x14;
  rlwimi r9, r7, 0x1c, 0x1e, 0x1e;
  rlwimi r9, r6, 0xc, 0x10, 0x13;
  rlwimi r9, r4, 8, 0x15, 0x17;
  rlwimi r9, r5, 5, 0x18, 0x1a;
  rlwimi r9, r0, 0x18, 0, 7;
  sth r9, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXPokeColorUpdate
// PAL: 0x8016ec2c..0x8016ec40
MARK_BINARY_BLOB(GXPokeColorUpdate, 0x8016ec2c, 0x8016ec40);
asm UNKNOWN_FUNCTION(GXPokeColorUpdate) {
  // clang-format off
  nofralloc;
  lwz r4, -0x6470(r13);
  lhz r0, 2(r4);
  rlwimi r0, r3, 3, 0x1c, 0x1c;
  sth r0, 2(r4);
  blr;
  // clang-format on
}

// Symbol: GXPokeDstAlpha
// PAL: 0x8016ec40..0x8016ec58
MARK_BINARY_BLOB(GXPokeDstAlpha, 0x8016ec40, 0x8016ec58);
asm UNKNOWN_FUNCTION(GXPokeDstAlpha) {
  // clang-format off
  nofralloc;
  lwz r5, -0x6470(r13);
  li r0, 0;
  rlwimi r0, r4, 0, 0x18, 0x1f;
  rlwimi r0, r3, 8, 0x17, 0x17;
  sth r0, 4(r5);
  blr;
  // clang-format on
}

// Symbol: GXPokeDither
// PAL: 0x8016ec58..0x8016ec6c
MARK_BINARY_BLOB(GXPokeDither, 0x8016ec58, 0x8016ec6c);
asm UNKNOWN_FUNCTION(GXPokeDither) {
  // clang-format off
  nofralloc;
  lwz r4, -0x6470(r13);
  lhz r0, 2(r4);
  rlwimi r0, r3, 2, 0x1d, 0x1d;
  sth r0, 2(r4);
  blr;
  // clang-format on
}

// Symbol: GXPokeZMode
// PAL: 0x8016ec6c..0x8016ec88
MARK_BINARY_BLOB(GXPokeZMode, 0x8016ec6c, 0x8016ec88);
asm UNKNOWN_FUNCTION(GXPokeZMode) {
  // clang-format off
  nofralloc;
  lwz r6, -0x6470(r13);
  li r0, 0;
  rlwimi r0, r3, 0, 0x1f, 0x1f;
  rlwimi r0, r4, 1, 0x1c, 0x1e;
  rlwimi r0, r5, 4, 0x1b, 0x1b;
  sth r0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: GXSetDrawSyncCallback
// PAL: 0x8016ec88..0x8016eccc
MARK_BINARY_BLOB(GXSetDrawSyncCallback, 0x8016ec88, 0x8016eccc);
asm UNKNOWN_FUNCTION(GXSetDrawSyncCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r31, -0x6420(r13);
  bl OSDisableInterrupts;
  stw r30, -0x6420(r13);
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXTokenInterruptHandler
// PAL: 0x8016eccc..0x8016ed50
MARK_BINARY_BLOB(GXTokenInterruptHandler, 0x8016eccc, 0x8016ed50);
asm UNKNOWN_FUNCTION(GXTokenInterruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  stw r30, 0x2d8(r1);
  mr r30, r4;
  lwz r0, -0x6420(r13);
  lwz r3, -0x6470(r13);
  cmpwi r0, 0;
  lhz r31, 0xe(r3);
  beq lbl_8016ed28;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  lwz r12, -0x6420(r13);
  mr r3, r31;
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r30;
  bl OSSetCurrentContext;
lbl_8016ed28:
  lwz r3, -0x6470(r13);
  lhz r0, 0xa(r3);
  ori r0, r0, 4;
  sth r0, 0xa(r3);
  lwz r0, 0x2e4(r1);
  lwz r31, 0x2dc(r1);
  lwz r30, 0x2d8(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: GXSetDrawDoneCallback
// PAL: 0x8016ed50..0x8016ed94
MARK_BINARY_BLOB(GXSetDrawDoneCallback, 0x8016ed50, 0x8016ed94);
asm UNKNOWN_FUNCTION(GXSetDrawDoneCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r31, -0x6424(r13);
  bl OSDisableInterrupts;
  stw r30, -0x6424(r13);
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXFinishInterruptHandler
// PAL: 0x8016ed94..0x8016ee14
MARK_BINARY_BLOB(GXFinishInterruptHandler, 0x8016ed94, 0x8016ee14);
asm UNKNOWN_FUNCTION(GXFinishInterruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  li r3, 1;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  mr r31, r4;
  lwz r5, -0x6470(r13);
  lhz r0, 0xa(r5);
  ori r0, r0, 8;
  sth r0, 0xa(r5);
  lwz r0, -0x6424(r13);
  stb r3, -0x6428(r13);
  cmpwi r0, 0;
  beq lbl_8016edf8;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  lwz r12, -0x6424(r13);
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r31;
  bl OSSetCurrentContext;
lbl_8016edf8:
  addi r3, r13, -25648;
  bl OSWakeupThread;
  lwz r0, 0x2e4(r1);
  lwz r31, 0x2dc(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: __GXPEInit
// PAL: 0x8016ee14..0x8016ee78
MARK_BINARY_BLOB(__GXPEInit, 0x8016ee14, 0x8016ee78);
asm UNKNOWN_FUNCTION(__GXPEInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8017;
  li r3, 0x12;
  stw r0, 0x14(r1);
  addi r4, r4, -4916;
  bl __OSSetInterruptHandler;
  lis r4, 0x8017;
  li r3, 0x13;
  addi r4, r4, -4716;
  bl __OSSetInterruptHandler;
  addi r3, r13, -25648;
  bl OSInitThreadQueue;
  li r3, 0x2000;
  bl __OSUnmaskInterrupts;
  li r3, 0x1000;
  bl __OSUnmaskInterrupts;
  lwz r3, -0x6470(r13);
  lhz r0, 0xa(r3);
  ori r0, r0, 0xf;
  sth r0, 0xa(r3);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
