#include "gxFifo.h"

#include <string.h>

#include <rvl/base/ppcArch.h>
#include <rvl/os/osContext.h>
#include <rvl/os/osError.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "gx.h"

// Symbol: GXCPInterruptHandler
// PAL: 0x8016c668..0x8016c7c8
MARK_BINARY_BLOB(GXCPInterruptHandler, 0x8016c668, 0x8016c7c8);
asm UNKNOWN_FUNCTION(GXCPInterruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  lwz r31, gx;
  stw r30, 0x2d8(r1);
  mr r30, r4;
  lwz r3, -0x6474(r13);
  lhz r0, 0(r3);
  stw r0, 0xc(r31);
  lwz r0, 8(r31);
  rlwinm. r0, r0, 0x1d, 0x1f, 0x1f;
  beq lbl_8016c6e8;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0x1f, 0x1f, 0x1f;
  beq lbl_8016c6e8;
  lwz r3, -0x643c(r13);
  bl OSResumeThread;
  li r0, 0;
  lwz r3, gx;
  stw r0, -0x6440(r13);
  lwz r0, 0x10(r3);
  ori r0, r0, 3;
  stw r0, 0x10(r3);
  lwz r3, -0x6474(r13);
  sth r0, 4(r3);
  lwz r0, 8(r31);
  ori r0, r0, 4;
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 8(r31);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
lbl_8016c6e8:
  lwz r0, 8(r31);
  rlwinm. r0, r0, 0x1e, 0x1f, 0x1f;
  beq lbl_8016c750;
  lwz r0, 0xc(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8016c750;
  lwz r3, -0x644c(r13);
  li r0, 1;
  lwz r5, gx;
  addi r3, r3, 1;
  stw r3, -0x644c(r13);
  lwz r3, 8(r31);
  rlwinm r4, r3, 0, 0x1e, 0x1c;
  ori r4, r4, 8;
  stw r4, 8(r31);
  lwz r3, -0x6474(r13);
  sth r4, 2(r3);
  lwz r3, 0x10(r5);
  ori r3, r3, 1;
  rlwinm r4, r3, 0, 0x1f, 0x1d;
  stw r4, 0x10(r5);
  lwz r3, -0x6474(r13);
  sth r4, 4(r3);
  stw r0, -0x6440(r13);
  lwz r3, -0x643c(r13);
  bl OSSuspendThread;
lbl_8016c750:
  lwz r3, 8(r31);
  rlwinm. r0, r3, 0x1b, 0x1f, 0x1f;
  beq lbl_8016c7b0;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0x1c, 0x1f, 0x1f;
  beq lbl_8016c7b0;
  rlwinm r0, r3, 0, 0x1b, 0x19;
  stw r0, 8(r31);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, -0x6444(r13);
  cmpwi r0, 0;
  beq lbl_8016c7b0;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  lwz r12, -0x6444(r13);
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r30;
  bl OSSetCurrentContext;
lbl_8016c7b0:
  lwz r0, 0x2e4(r1);
  lwz r31, 0x2dc(r1);
  lwz r30, 0x2d8(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: GXInitFifoBase
// PAL: 0x8016c7c8..0x8016c854
MARK_BINARY_BLOB(GXInitFifoBase, 0x8016c7c8, 0x8016c854);
asm UNKNOWN_FUNCTION(GXInitFifoBase) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  add r7, r4, r5;
  addi r6, r5, -16384;
  stw r0, 0x24(r1);
  addi r7, r7, -4;
  rlwinm r0, r5, 0x1f, 1, 0x1a;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r4, 0(r3);
  stw r7, 4(r3);
  stw r5, 8(r3);
  stw r31, 0x1c(r3);
  stw r6, 0xc(r3);
  stw r0, 0x10(r3);
  bl OSDisableInterrupts;
  cmpwi r31, 0;
  stw r30, 0x14(r29);
  stw r30, 0x18(r29);
  stw r31, 0x1c(r29);
  bge lbl_8016c834;
  lwz r0, 8(r29);
  stw r0, 0x1c(r29);
lbl_8016c834:
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

// Symbol: CPGPLinkCheck
// PAL: 0x8016c854..0x8016c94c
MARK_BINARY_BLOB(CPGPLinkCheck, 0x8016c854, 0x8016c94c);
asm UNKNOWN_FUNCTION(CPGPLinkCheck) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r7, 0;
  stw r0, 0x14(r1);
  lbz r0, -0x6450(r13);
  cmpwi r0, 0;
  beq lbl_8016c87c;
  lbz r0, -0x644f(r13);
  cmpwi r0, 0;
  bne lbl_8016c884;
lbl_8016c87c:
  li r3, 0;
  b lbl_8016c93c;
lbl_8016c884:
  lis r4, 0x8034;
  lis r3, 0x8034;
  lwz r6, 0x3dc0(r4);
  lwz r4, 0x3de4(r3);
  cmplw r4, r6;
  bne lbl_8016c8a0;
  li r7, 1;
lbl_8016c8a0:
  lis r5, 0x8034;
  lis r3, 0x8034;
  addi r5, r5, 0x3dc0;
  addi r3, r3, 0x3de4;
  lwz r0, 4(r5);
  lwz r5, 4(r3);
  cmplw r5, r0;
  bne lbl_8016c8c4;
  addi r7, r7, 1;
lbl_8016c8c4:
  cmplwi r7, 2;
  bne lbl_8016c8d4;
  li r3, 1;
  b lbl_8016c93c;
lbl_8016c8d4:
  subf. r3, r6, r5;
  subf r6, r4, r0;
  li r0, 0;
  ble lbl_8016c8ec;
  cmpwi r6, 0;
  bgt lbl_8016c8fc;
lbl_8016c8ec:
  cmpwi r3, 0;
  bge lbl_8016c900;
  cmpwi r6, 0;
  bge lbl_8016c900;
lbl_8016c8fc:
  li r0, 1;
lbl_8016c900:
  cmpwi r0, 0;
  beq lbl_8016c938;
  lis r3, 0x8029;
  addi r3, r3, -24672;
  crclr 6;
  bl OSReport;
  lis r4, 0x8034;
  lis r3, 0x8029;
  addi r5, r4, 0x3dc0;
  lwz r4, 0x3dc0(r4);
  lwz r5, 4(r5);
  addi r3, r3, -24648;
  crclr 6;
  bl OSReport;
lbl_8016c938:
  li r3, 0;
lbl_8016c93c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetCPUFifo
// PAL: 0x8016c94c..0x8016cb2c
MARK_BINARY_BLOB(GXSetCPUFifo, 0x8016c94c, 0x8016cb2c);
asm UNKNOWN_FUNCTION(GXSetCPUFifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  bl OSDisableInterrupts;
  cmpwi r27, 0;
  mr r30, r3;
  bne lbl_8016c998;
  lis r4, 0x8034;
  li r0, 0;
  addi r4, r4, 0x3de4;
  stb r0, -0x6450(r13);
  stb r0, -0x6438(r13);
  stb r0, 0x22(r4);
  stb r0, 0x21(r4);
  bl OSRestoreInterrupts;
  b lbl_8016cb14;
lbl_8016c998:
  lis r28, 0x8034;
  lwz r3, 0(r27);
  lwz r0, 4(r27);
  addi r31, r28, 0x3de4;
  li r29, 1;
  stw r3, 0(r31);
  stw r0, 4(r31);
  lwz r3, 8(r27);
  lwz r0, 0xc(r27);
  stw r3, 8(r31);
  stw r0, 0xc(r31);
  lwz r3, 0x10(r27);
  lwz r0, 0x14(r27);
  stw r3, 0x10(r31);
  stw r0, 0x14(r31);
  lwz r3, 0x18(r27);
  lwz r0, 0x1c(r27);
  stw r3, 0x18(r31);
  stw r0, 0x1c(r31);
  lwz r0, 0x20(r27);
  stw r0, 0x20(r31);
  stb r29, -0x6450(r13);
  stb r29, 0x21(r31);
  bl CPGPLinkCheck;
  clrlwi. r0, r3, 0x18;
  beq lbl_8016ca84;
  lwz r4, 0x3de4(r28);
  li r0, 0;
  stb r29, -0x6438(r13);
  lwz r3, -0x6478(r13);
  clrlwi r4, r4, 2;
  stb r29, 0x22(r31);
  lwz r5, gx;
  stw r4, 0xc(r3);
  lwz r4, 4(r31);
  lwz r3, -0x6478(r13);
  clrlwi r4, r4, 2;
  stw r4, 0x10(r3);
  lwz r4, 0x18(r31);
  lwz r3, -0x6478(r13);
  rlwimi r0, r4, 0, 3, 0x1a;
  stw r0, 0x14(r3);
  lwz r0, 0x10(r5);
  ori r0, r0, 3;
  stw r0, 0x10(r5);
  lwz r3, -0x6474(r13);
  sth r0, 4(r3);
  lwz r0, 8(r5);
  ori r0, r0, 4;
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 8(r5);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 8(r5);
  ori r0, r0, 0x10;
  stw r0, 8(r5);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  b lbl_8016cb08;
lbl_8016ca84:
  lbz r0, -0x6438(r13);
  li r4, 0;
  stb r4, 0x22(r31);
  cmpwi r0, 0;
  beq lbl_8016cab4;
  lwz r3, gx;
  lwz r0, 8(r3);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stw r0, 8(r3);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  stb r4, -0x6438(r13);
lbl_8016cab4:
  lwz r7, gx;
  lis r3, 0x8034;
  addi r5, r3, 0x3de4;
  li r0, 0;
  lwz r4, 8(r7);
  rlwinm r6, r4, 0, 0x1e, 0x1b;
  stw r6, 8(r7);
  lwz r4, -0x6474(r13);
  sth r6, 2(r4);
  lwz r4, 0x3de4(r3);
  lwz r3, -0x6478(r13);
  clrlwi r4, r4, 2;
  stw r4, 0xc(r3);
  lwz r4, 4(r5);
  lwz r3, -0x6478(r13);
  clrlwi r4, r4, 2;
  stw r4, 0x10(r3);
  lwz r4, 0x18(r5);
  lwz r3, -0x6478(r13);
  rlwimi r0, r4, 0, 3, 0x1a;
  stw r0, 0x14(r3);
lbl_8016cb08:
  bl PPCSync;
  mr r3, r30;
  bl OSRestoreInterrupts;
lbl_8016cb14:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXSetGPFifo
// PAL: 0x8016cb2c..0x8016cdbc
MARK_BINARY_BLOB(GXSetGPFifo, 0x8016cb2c, 0x8016cdbc);
asm UNKNOWN_FUNCTION(GXSetGPFifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  bl OSDisableInterrupts;
  lwz r29, gx;
  cmpwi r27, 0;
  mr r28, r3;
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 8(r29);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0x1e, 0x1b;
  stw r0, 8(r29);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  bne lbl_8016cbb8;
  li r6, 0;
  lis r4, 0x8034;
  stb r6, -0x644f(r13);
  addi r4, r4, 0x3dc0;
  stb r6, -0x6438(r13);
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stw r0, 8(r29);
  lwz r5, -0x6474(r13);
  sth r0, 2(r5);
  stb r6, 0x21(r4);
  stb r6, 0x22(r4);
  bl OSRestoreInterrupts;
  b lbl_8016cda4;
lbl_8016cbb8:
  lis r3, 0x8034;
  lwz r6, 0(r27);
  lwz r0, 4(r27);
  addi r30, r3, 0x3dc0;
  li r31, 1;
  lwz r4, -0x6474(r13);
  stw r6, 0(r30);
  stw r0, 4(r30);
  lwz r5, 8(r27);
  lwz r0, 0xc(r27);
  stw r5, 8(r30);
  stw r0, 0xc(r30);
  lwz r5, 0x10(r27);
  lwz r0, 0x14(r27);
  stw r5, 0x10(r30);
  stw r0, 0x14(r30);
  lwz r5, 0x18(r27);
  lwz r0, 0x1c(r27);
  stw r5, 0x18(r30);
  stw r0, 0x1c(r30);
  lwz r0, 0x20(r27);
  stw r0, 0x20(r30);
  stb r31, -0x644f(r13);
  stb r31, 0x22(r30);
  sth r6, 0x20(r4);
  lwz r0, 4(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x24(r4);
  lwz r0, 0x1c(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x30(r4);
  lwz r0, 0x18(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x34(r4);
  lwz r0, 0x14(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x38(r4);
  lwz r0, 0xc(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x28(r4);
  lwz r0, 0x10(r30);
  lwz r4, -0x6474(r13);
  sth r0, 0x2c(r4);
  lwz r0, 0x3dc0(r3);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x22(r3);
  lwz r0, 4(r30);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x26(r3);
  lwz r0, 0x1c(r30);
  lwz r3, -0x6474(r13);
  srawi r0, r0, 0x10;
  sth r0, 0x32(r3);
  lwz r0, 0x18(r30);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x36(r3);
  lwz r0, 0x14(r30);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x3a(r3);
  lwz r0, 0xc(r30);
  lwz r3, -0x6474(r13);
  srwi r0, r0, 0x10;
  sth r0, 0x2a(r3);
  lwz r0, 0x10(r30);
  lwz r3, -0x6474(r13);
  srwi r0, r0, 0x10;
  sth r0, 0x2e(r3);
  bl PPCSync;
  bl CPGPLinkCheck;
  clrlwi. r0, r3, 0x18;
  beq lbl_8016cd1c;
  stb r31, -0x6438(r13);
  stb r31, 0x21(r30);
  lwz r0, 8(r29);
  ori r0, r0, 4;
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 8(r29);
  ori r0, r0, 0x10;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  b lbl_8016cd50;
lbl_8016cd1c:
  li r0, 0;
  stb r0, -0x6438(r13);
  stb r0, 0x21(r30);
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0x1e, 0x1b;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
lbl_8016cd50:
  lwz r0, 8(r29);
  mr r3, r28;
  lwz r4, -0x6474(r13);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  lwz r5, gx;
  rlwinm r0, r0, 0, 0x1b, 0x19;
  sth r0, 2(r4);
  lwz r0, 8(r29);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  lwz r0, 0x10(r5);
  ori r0, r0, 3;
  stw r0, 0x10(r5);
  lwz r4, -0x6474(r13);
  sth r0, 4(r4);
  lwz r0, 8(r29);
  ori r0, r0, 1;
  stw r0, 8(r29);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  bl OSRestoreInterrupts;
lbl_8016cda4:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __GXSaveFifo
// PAL: 0x8016cdbc..0x8016cebc
MARK_BINARY_BLOB(__GXSaveFifo, 0x8016cdbc, 0x8016cebc);
asm UNKNOWN_FUNCTION(__GXSaveFifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSDisableInterrupts;
  lbz r6, -0x6450(r13);
  cmpwi r6, 0;
  beq lbl_8016cdfc;
  lwz r5, -0x6478(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x3de4;
  lwz r0, 0x14(r5);
  rlwinm r5, r0, 0, 3, 0x1a;
  rlwinm r0, r0, 3, 0x1f, 0x1f;
  addis r5, r5, 0x8000;
  stb r0, 0x20(r4);
  stw r5, 0x18(r4);
lbl_8016cdfc:
  lbz r0, -0x644f(r13);
  cmpwi r0, 0;
  beq lbl_8016ce38;
  lwz r7, -0x6474(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x3dc0;
  lhz r0, 0x3a(r7);
  lhz r5, 0x38(r7);
  rlwimi r5, r0, 0x10, 0, 0xf;
  addis r0, r5, 0x8000;
  stw r0, 0x14(r4);
  lhz r0, 0x32(r7);
  lhz r5, 0x30(r7);
  rlwimi r5, r0, 0x10, 0, 0xf;
  stw r5, 0x1c(r4);
lbl_8016ce38:
  lbz r0, -0x6438(r13);
  cmpwi r0, 0;
  beq lbl_8016ce78;
  lis r8, 0x8034;
  lis r6, 0x8034;
  addi r8, r8, 0x3dc0;
  addi r6, r6, 0x3de4;
  lwz r7, 0x14(r8);
  lwz r5, 0x1c(r8);
  lwz r4, 0x18(r6);
  lbz r0, 0x20(r6);
  stw r7, 0x14(r6);
  stw r5, 0x1c(r6);
  stw r4, 0x18(r8);
  stb r0, 0x20(r8);
  b lbl_8016cea8;
lbl_8016ce78:
  cmpwi r6, 0;
  beq lbl_8016cea8;
  lis r5, 0x8034;
  addi r5, r5, 0x3de4;
  lwz r4, 0x14(r5);
  lwz r0, 0x18(r5);
  subf. r4, r4, r0;
  stw r4, 0x1c(r5);
  bge lbl_8016cea8;
  lwz r0, 8(r5);
  add r0, r4, r0;
  stw r0, 0x1c(r5);
lbl_8016cea8:
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __GXIsGPFifoReady
// PAL: 0x8016cebc..0x8016cec4
MARK_BINARY_BLOB(__GXIsGPFifoReady, 0x8016cebc, 0x8016cec4);
asm UNKNOWN_FUNCTION(__GXIsGPFifoReady) {
  // clang-format off
  nofralloc;
  lbz r3, -0x644f(r13);
  blr;
  // clang-format on
}

// Symbol: GXGetGPStatus
// PAL: 0x8016cec4..0x8016cf10
MARK_BINARY_BLOB(GXGetGPStatus, 0x8016cec4, 0x8016cf10);
asm void GXGetGPStatus(u8* overhi, u8* underlow, u8* readIdle, u8* cmdIdle,
                       u8* brkpt) {
  // clang-format off
  nofralloc;
  lwz r8, -0x6474(r13);
  lwz r9, gx;
  lhz r0, 0(r8);
  stw r0, 0xc(r9);
  clrlwi r0, r0, 0x1f;
  stb r0, 0(r3);
  lwz r0, 0xc(r9);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  stb r0, 0(r4);
  lwz r0, 0xc(r9);
  rlwinm r0, r0, 0x1e, 0x1f, 0x1f;
  stb r0, 0(r5);
  lwz r0, 0xc(r9);
  rlwinm r0, r0, 0x1d, 0x1f, 0x1f;
  stb r0, 0(r6);
  lwz r0, 0xc(r9);
  rlwinm r0, r0, 0x1c, 0x1f, 0x1f;
  stb r0, 0(r7);
  blr;
  // clang-format on
}

// Symbol: GXGetCPUFifo
// PAL: 0x8016cf10..0x8016cfa0
MARK_BINARY_BLOB(GXGetCPUFifo, 0x8016cf10, 0x8016cfa0);
asm UNKNOWN_FUNCTION(GXGetCPUFifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, -0x6450(r13);
  cmpwi r0, 0;
  bne lbl_8016cf38;
  li r3, 0;
  b lbl_8016cf8c;
lbl_8016cf38:
  bl __GXSaveFifo;
  lis r5, 0x8034;
  lwzu r4, 0x3de4(r5);
  li r3, 1;
  lwz r0, 4(r5);
  stw r4, 0(r31);
  stw r0, 4(r31);
  lwz r4, 8(r5);
  lwz r0, 0xc(r5);
  stw r4, 8(r31);
  stw r0, 0xc(r31);
  lwz r4, 0x10(r5);
  lwz r0, 0x14(r5);
  stw r4, 0x10(r31);
  stw r0, 0x14(r31);
  lwz r4, 0x18(r5);
  lwz r0, 0x1c(r5);
  stw r4, 0x18(r31);
  stw r0, 0x1c(r31);
  lwz r0, 0x20(r5);
  stw r0, 0x20(r31);
lbl_8016cf8c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetGPFifo
// PAL: 0x8016cfa0..0x8016d030
MARK_BINARY_BLOB(GXGetGPFifo, 0x8016cfa0, 0x8016d030);
asm int GXGetGPFifo(GXFifoObj* fifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, -0x644f(r13);
  cmpwi r0, 0;
  bne lbl_8016cfc8;
  li r3, 0;
  b lbl_8016d01c;
lbl_8016cfc8:
  bl __GXSaveFifo;
  lis r5, 0x8034;
  lwzu r4, 0x3dc0(r5);
  li r3, 1;
  lwz r0, 4(r5);
  stw r4, 0(r31);
  stw r0, 4(r31);
  lwz r4, 8(r5);
  lwz r0, 0xc(r5);
  stw r4, 8(r31);
  stw r0, 0xc(r31);
  lwz r4, 0x10(r5);
  lwz r0, 0x14(r5);
  stw r4, 0x10(r31);
  stw r0, 0x14(r31);
  lwz r4, 0x18(r5);
  lwz r0, 0x1c(r5);
  stw r4, 0x18(r31);
  stw r0, 0x1c(r31);
  lwz r0, 0x20(r5);
  stw r0, 0x20(r31);
lbl_8016d01c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetFifoPtrs
// PAL: 0x8016d030..0x8016d044
MARK_BINARY_BLOB(GXGetFifoPtrs, 0x8016d030, 0x8016d044);
asm void GXGetFifoPtrs(const GXFifoObj* fifo, void** readPtr, void** writePtr) {
  // clang-format off
  nofralloc;
  lwz r6, 0x14(r3);
  lwz r0, 0x18(r3);
  stw r6, 0(r4);
  stw r0, 0(r5);
  blr;
  // clang-format on
}

// Symbol: GXGetFifoCount
// PAL: 0x8016d044..0x8016d04c
MARK_BINARY_BLOB(GXGetFifoCount, 0x8016d044, 0x8016d04c);
asm UNKNOWN_FUNCTION(GXGetFifoCount) {
  // clang-format off
  nofralloc;
  lwz r3, 0x1c(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetFifoWrap
// PAL: 0x8016d04c..0x8016d054
MARK_BINARY_BLOB(GXGetFifoWrap, 0x8016d04c, 0x8016d054);
asm UNKNOWN_FUNCTION(GXGetFifoWrap) {
  // clang-format off
  nofralloc;
  lbz r3, 0x20(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetBreakPtCallback
// PAL: 0x8016d054..0x8016d098
MARK_BINARY_BLOB(GXSetBreakPtCallback, 0x8016d054, 0x8016d098);
asm UNKNOWN_FUNCTION(GXSetBreakPtCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r31, -0x6444(r13);
  bl OSDisableInterrupts;
  stw r30, -0x6444(r13);
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

// Symbol: GXEnableBreakPt
// PAL: 0x8016d098..0x8016d138
MARK_BINARY_BLOB(GXEnableBreakPt, 0x8016d098, 0x8016d138);
asm void GXEnableBreakPt(void* breakPtr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r6, gx;
  rlwinm r0, r31, 0x10, 0x12, 0x1f;
  lwz r4, 8(r6);
  rlwinm r5, r4, 0, 0, 0x1e;
  stw r5, 8(r6);
  lwz r4, -0x6474(r13);
  sth r5, 2(r4);
  lwz r4, -0x6474(r13);
  sth r31, 0x3c(r4);
  lwz r4, -0x6474(r13);
  sth r0, 0x3e(r4);
  lwz r0, 8(r6);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  rlwinm r0, r0, 0, 0x1b, 0x19;
  stw r0, 8(r6);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  lwz r0, 8(r6);
  ori r0, r0, 0x22;
  stw r0, 8(r6);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  stw r31, -0x6448(r13);
  lwz r0, 8(r6);
  ori r0, r0, 1;
  stw r0, 8(r6);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXDisableBreakPt
// PAL: 0x8016d138..0x8016d180
MARK_BINARY_BLOB(GXDisableBreakPt, 0x8016d138, 0x8016d180);
asm void GXDisableBreakPt(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSDisableInterrupts;
  lwz r6, gx;
  li r0, 0;
  lwz r4, 8(r6);
  rlwinm r4, r4, 0, 0x1f, 0x1d;
  rlwinm r5, r4, 0, 0x1b, 0x19;
  stw r5, 8(r6);
  lwz r4, -0x6474(r13);
  sth r5, 2(r4);
  stw r0, -0x6448(r13);
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __GXFifoInit
// PAL: 0x8016d180..0x8016d1fc
MARK_BINARY_BLOB(__GXFifoInit, 0x8016d180, 0x8016d1fc);
asm UNKNOWN_FUNCTION(__GXFifoInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8017;
  li r3, 0x11;
  stw r0, 0x14(r1);
  addi r4, r4, -14744;
  stw r31, 0xc(r1);
  bl __OSSetInterruptHandler;
  li r3, 0x4000;
  bl __OSUnmaskInterrupts;
  bl OSGetCurrentThread;
  li r31, 0;
  stw r3, -0x643c(r13);
  lis r3, 0x8034;
  li r4, 0;
  stw r31, -0x6440(r13);
  addi r3, r3, 0x3de4;
  li r5, 0x24;
  bl memset;
  lis r3, 0x8034;
  li r4, 0;
  addi r3, r3, 0x3dc0;
  li r5, 0x24;
  bl memset;
  stb r31, -0x6450(r13);
  stb r31, -0x644f(r13);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __GXCleanGPFifo
// PAL: 0x8016d1fc..0x8016d39c
MARK_BINARY_BLOB(__GXCleanGPFifo, 0x8016d1fc, 0x8016d39c);
asm UNKNOWN_FUNCTION(__GXCleanGPFifo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lbz r0, -0x644f(r13);
  cmpwi r0, 0;
  beq lbl_8016d37c;
  bl OSDisableInterrupts;
  lwz r29, gx;
  lis r30, 0x8034;
  mr r28, r3;
  li r31, 0;
  lwz r0, 8(r29);
  addi r30, r30, 0x3dc0;
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 8(r29);
  rlwinm r0, r0, 0, 0x1e, 0x1b;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 0x18(r30);
  stw r31, 0x1c(r30);
  lwz r3, -0x6474(r13);
  stw r0, 0x14(r30);
  sth r31, 0x30(r3);
  lwz r0, 0x18(r30);
  lwz r3, -0x6474(r13);
  sth r0, 0x34(r3);
  lwz r0, 0x14(r30);
  lwz r3, -0x6474(r13);
  sth r0, 0x38(r3);
  lwz r0, 0x1c(r30);
  lwz r3, -0x6474(r13);
  srawi r0, r0, 0x10;
  sth r0, 0x32(r3);
  lwz r0, 0x18(r30);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x36(r3);
  lwz r0, 0x14(r30);
  lwz r3, -0x6474(r13);
  rlwinm r0, r0, 0x10, 0x12, 0x1f;
  sth r0, 0x3a(r3);
  bl PPCSync;
  lbz r0, -0x6438(r13);
  cmpwi r0, 0;
  beq lbl_8016d328;
  lis r5, 0x8034;
  lwz r4, 0x18(r30);
  addi r5, r5, 0x3de4;
  lwz r3, 0x14(r30);
  lwz r0, 0x1c(r30);
  rlwimi r31, r4, 0, 3, 0x1a;
  stw r3, 0x14(r5);
  lwz r3, -0x6478(r13);
  stw r4, 0x18(r5);
  stw r0, 0x1c(r5);
  stw r31, 0x14(r3);
  lwz r0, 8(r29);
  ori r0, r0, 4;
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
  lwz r0, 8(r29);
  ori r0, r0, 0x10;
  stw r0, 8(r29);
  lwz r3, -0x6474(r13);
  sth r0, 2(r3);
lbl_8016d328:
  lwz r4, 8(r29);
  li r0, 0;
  lwz r6, gx;
  mr r3, r28;
  rlwinm r4, r4, 0, 0x1f, 0x1d;
  rlwinm r5, r4, 0, 0x1b, 0x19;
  stw r5, 8(r29);
  lwz r4, -0x6474(r13);
  sth r5, 2(r4);
  stw r0, -0x6448(r13);
  lwz r0, 0x10(r6);
  ori r0, r0, 3;
  stw r0, 0x10(r6);
  lwz r4, -0x6474(r13);
  sth r0, 4(r4);
  lwz r0, 8(r29);
  ori r0, r0, 1;
  stw r0, 8(r29);
  lwz r4, -0x6474(r13);
  sth r0, 2(r4);
  bl OSRestoreInterrupts;
lbl_8016d37c:
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

// Symbol: GXGetCurrentGXThread
// PAL: 0x8016d39c..0x8016d3a4
MARK_BINARY_BLOB(GXGetCurrentGXThread, 0x8016d39c, 0x8016d3a4);
asm UNKNOWN_FUNCTION(GXGetCurrentGXThread) {
  // clang-format off
  nofralloc;
  lwz r3, -0x643c(r13);
  blr;
  // clang-format on
}
