#include "euart.h"

#include <rvl/os/osInterrupt.h>

#include <rvl/exi/exiBios.h>
#include <rvl/exi/exiCommon.h>

// Extern function references.
// PAL: 0x8019f33c
extern UNKNOWN_FUNCTION(OSGetConsoleType);

// Symbol: EUARTInit
// PAL: 0x80167b08..0x80167c04
MARK_BINARY_BLOB(EUARTInit, 0x80167b08, 0x80167c04);
asm UNKNOWN_FUNCTION(EUARTInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lwz r0, -0x64b8(r13);
  cmpwi r0, 0;
  beq lbl_80167b2c;
  li r3, 1;
  b lbl_80167bf0;
lbl_80167b2c:
  bl OSGetConsoleType;
  rlwinm. r0, r3, 0, 3, 3;
  bne lbl_80167b48;
  li r0, 2;
  li r3, 0;
  stw r0, -0x64b4(r13);
  b lbl_80167bf0;
lbl_80167b48:
  bl OSDisableInterrupts;
  li r0, 0xf2;
  mr r31, r3;
  stb r0, 8(r1);
  addi r6, r1, 8;
  li r3, 0;
  li r4, 1;
  lis r5, 0xb000;
  li r7, 1;
  bl EXIWriteReg;
  cmpwi r3, 0;
  bne lbl_80167b90;
  li r0, 5;
  mr r3, r31;
  stw r0, -0x64b4(r13);
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80167bf0;
lbl_80167b90:
  li r0, 0xf3;
  addi r6, r1, 8;
  stb r0, 8(r1);
  li r3, 0;
  li r4, 1;
  lis r5, 0xb000;
  li r7, 1;
  bl EXIWriteReg;
  cmpwi r3, 0;
  bne lbl_80167bd0;
  li r0, 5;
  mr r3, r31;
  stw r0, -0x64b4(r13);
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80167bf0;
lbl_80167bd0:
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r0, 0;
  li r3, 1;
  stw r3, -0x64b8(r13);
  li r3, 1;
  stw r0, -0x64b4(r13);
  stw r0, -0x64b0(r13);
lbl_80167bf0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: InitializeUART
// PAL: 0x80167c04..0x80167c4c
MARK_BINARY_BLOB(InitializeUART, 0x80167c04, 0x80167c4c);
asm UNKNOWN_FUNCTION(InitializeUART) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSGetConsoleType;
  rlwinm. r0, r3, 0, 3, 3;
  bne lbl_80167c2c;
  li r0, 0;
  li r3, 2;
  stw r0, -0x64ac(r13);
  b lbl_80167c3c;
lbl_80167c2c:
  lis r4, 0xa5ff;
  li r3, 0;
  addi r0, r4, 0x5a;
  stw r0, -0x64ac(r13);
lbl_80167c3c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: WriteUARTN
// PAL: 0x80167c4c..0x80167e78
MARK_BINARY_BLOB(WriteUARTN, 0x80167c4c, 0x80167e78);
asm UNKNOWN_FUNCTION(WriteUARTN) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  lwz r5, -0x64ac(r13);
  mr r30, r3;
  mr r31, r4;
  addis r0, r5, 0x5a01;
  cmplwi r0, 0x5a;
  beq lbl_80167c80;
  li r3, 2;
  b lbl_80167e60;
lbl_80167c80:
  lwz r0, -0x64b8(r13);
  cmpwi r0, 0;
  bne lbl_80167ca0;
  bl EUARTInit;
  cmpwi r3, 0;
  bne lbl_80167ca0;
  li r3, 2;
  b lbl_80167e60;
lbl_80167ca0:
  lwz r0, -0x64b8(r13);
  cmpwi r0, 0;
  bne lbl_80167cbc;
  li r0, 1;
  li r3, 2;
  stw r0, -0x64b4(r13);
  b lbl_80167e60;
lbl_80167cbc:
  li r3, 0;
  li r4, 1;
  li r5, 0;
  bl EXILock;
  cmpwi r3, 0;
  bne lbl_80167cdc;
  li r3, 0;
  b lbl_80167e60;
lbl_80167cdc:
  mr r4, r30;
  li r3, 0xd;
  b lbl_80167cfc;
lbl_80167ce8:
  lbz r0, 0(r4);
  cmpwi r0, 0xa;
  bne lbl_80167cf8;
  stb r3, 0(r4);
lbl_80167cf8:
  addi r4, r4, 1;
lbl_80167cfc:
  subf r0, r30, r4;
  cmplw r0, r31;
  blt lbl_80167ce8;
  lis r3, 0xb000;
  lwz r28, unk_803886c0;
  addi r0, r3, 0x100;
  li r26, 0;
  stw r0, 0x14(r1);
  lis r29, 0x3000;
  b lbl_80167e4c;
lbl_80167d24:
  mr r5, r28;
  li r3, 0;
  li r4, 1;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_80167d44;
  li r27, -1;
  b lbl_80167da0;
lbl_80167d44:
  addi r0, r29, 0x100;
  addi r4, r1, 8;
  stw r0, 8(r1);
  li r3, 0;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  li r3, 0;
  bl EXISync;
  addi r4, r1, 0xc;
  li r3, 0;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl EXIImm;
  li r3, 0;
  bl EXISync;
  li r3, 0;
  bl EXIDeselect;
  lwz r0, 0xc(r1);
  rlwinm r0, r0, 8, 0x1a, 0x1f;
  subfic r27, r0, 0x20;
lbl_80167da0:
  cmpwi r27, 0;
  bge lbl_80167db0;
  li r26, 3;
  b lbl_80167e54;
lbl_80167db0:
  cmpwi r27, 0x20;
  bne lbl_80167e4c;
  mr r5, r28;
  li r3, 0;
  li r4, 1;
  bl EXISelect;
  cmpwi r3, 0;
  bne lbl_80167dd8;
  li r26, 3;
  b lbl_80167e54;
lbl_80167dd8:
  addi r4, r1, 0x14;
  li r3, 0;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  li r3, 0;
  bl EXISync;
  b lbl_80167e34;
lbl_80167dfc:
  lbz r0, 0(r30);
  addi r4, r1, 0x10;
  li r3, 0;
  li r5, 4;
  slwi r0, r0, 0x18;
  li r6, 1;
  stw r0, 0x10(r1);
  li r7, 0;
  bl EXIImm;
  li r3, 0;
  bl EXISync;
  addi r30, r30, 1;
  addi r27, r27, -1;
  addi r31, r31, -1;
lbl_80167e34:
  cmpwi r27, 0;
  ble lbl_80167e44;
  cmpwi r31, 0;
  bne lbl_80167dfc;
lbl_80167e44:
  li r3, 0;
  bl EXIDeselect;
lbl_80167e4c:
  cmpwi r31, 0;
  bne lbl_80167d24;
lbl_80167e54:
  li r3, 0;
  bl EXIUnlock;
  mr r3, r26;
lbl_80167e60:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
