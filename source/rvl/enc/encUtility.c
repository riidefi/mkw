#include "encUtility.h"

#include <string.h>

#include <rvl/os/os.h>

static u32 enc_registered = 0;

// Symbol: ENCiCheckParameters
// PAL: 0x80166ad0..0x80166bc8
MARK_BINARY_BLOB(ENCiCheckParameters, 0x80166ad0, 0x80166bc8);
asm UNKNOWN_FUNCTION(ENCiCheckParameters) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lwz r0, enc_registered;
  mr r23, r3;
  mr r31, r4;
  mr r24, r5;
  cmpwi r0, 0;
  mr r25, r6;
  mr r26, r7;
  mr r27, r8;
  mr r28, r9;
  mr r29, r10;
  li r30, 0;
  bne lbl_80166b24;
  lwz r3, -0x7308(r13);
  bl OSRegisterVersion;
  li r0, 1;
  stw r0, enc_registered;
lbl_80166b24:
  cmpwi r27, 0;
  beq lbl_80166b38;
  lwz r0, 0(r27);
  stw r0, 0(r28);
  b lbl_80166b40;
lbl_80166b38:
  li r0, -1;
  stw r0, 0(r28);
lbl_80166b40:
  cmpwi r31, 0;
  beq lbl_80166b54;
  lwz r0, 0(r31);
  stw r0, 0(r24);
  b lbl_80166b60;
lbl_80166b54:
  li r0, -1;
  li r30, -3;
  stw r0, 0(r24);
lbl_80166b60:
  cmpwi r26, 0;
  bne lbl_80166b6c;
  li r30, -3;
lbl_80166b6c:
  cmpwi r23, 0;
  bne lbl_80166b84;
  li r3, 0;
  li r0, -1;
  stw r3, 0(r25);
  stw r0, 0(r24);
lbl_80166b84:
  lwz r0, 0(r28);
  cmpwi r0, 0;
  bge lbl_80166b98;
  li r0, 0;
  stw r0, 0(r29);
lbl_80166b98:
  cmpwi r30, 0;
  beq lbl_80166bac;
  li r0, 0;
  stw r0, 0(r31);
  stw r0, 0(r27);
lbl_80166bac:
  addi r11, r1, 0x30;
  mr r3, r30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ENCiCheckBreakType
// PAL: 0x80166bc8..0x80166bfc
MARK_BINARY_BLOB(ENCiCheckBreakType, 0x80166bc8, 0x80166bfc);
asm UNKNOWN_FUNCTION(ENCiCheckBreakType) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0xa;
  bne lbl_80166bd8;
  li r3, 1;
  blr;
lbl_80166bd8:
  cmplwi r3, 0xd;
  bne lbl_80166bf4;
  addi r0, r4, -10;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  addi r3, r3, 1;
  blr;
lbl_80166bf4:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: ENCiWriteBreakType
// PAL: 0x80166bfc..0x80166d0c
MARK_BINARY_BLOB(ENCiWriteBreakType, 0x80166bfc, 0x80166d0c);
asm UNKNOWN_FUNCTION(ENCiWriteBreakType) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  beq lbl_80166cb0;
  addi r5, r30, -1;
  li r4, 0;
  bl memset;
  cmpwi r31, 2;
  beq lbl_80166c88;
  bge lbl_80166c4c;
  cmpwi r31, 1;
  bge lbl_80166c58;
  b lbl_80166cec;
lbl_80166c4c:
  cmpwi r31, 4;
  bge lbl_80166cec;
  b lbl_80166c9c;
lbl_80166c58:
  add r3, r29, r30;
  li r0, 0xd;
  stb r0, -1(r3);
  addi r5, r30, -1;
  li r4, 0;
  bl memset;
  slwi r0, r30, 1;
  li r5, 0xa;
  add r4, r29, r0;
  li r3, 2;
  stb r5, -1(r4);
  b lbl_80166cf0;
lbl_80166c88:
  add r3, r29, r30;
  li r0, 0xd;
  stb r0, -1(r3);
  li r3, 1;
  b lbl_80166cf0;
lbl_80166c9c:
  add r3, r29, r30;
  li r0, 0xa;
  stb r0, -1(r3);
  li r3, 1;
  b lbl_80166cf0;
lbl_80166cb0:
  cmpwi r5, 2;
  beq lbl_80166cdc;
  bge lbl_80166cc8;
  cmpwi r5, 1;
  bge lbl_80166cd4;
  b lbl_80166cec;
lbl_80166cc8:
  cmpwi r5, 4;
  bge lbl_80166cec;
  b lbl_80166ce4;
lbl_80166cd4:
  li r3, 2;
  b lbl_80166cf0;
lbl_80166cdc:
  li r3, 1;
  b lbl_80166cf0;
lbl_80166ce4:
  li r3, 1;
  b lbl_80166cf0;
lbl_80166cec:
  li r3, 0;
lbl_80166cf0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
