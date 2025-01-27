#include "exiCommon.h"

#include "exiBios.h"

const u32 unk_803886c0 = 4;

// Symbol: EXIWriteReg
// PAL: 0x80169a40..0x80169bcc
MARK_BINARY_BLOB(EXIWriteReg, 0x80169a40, 0x80169bcc);
asm UNKNOWN_FUNCTION(EXIWriteReg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r7, 2;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r5, 8(r1);
  beq lbl_80169a8c;
  bge lbl_80169aa0;
  cmpwi r7, 1;
  bge lbl_80169a7c;
  b lbl_80169aa0;
lbl_80169a7c:
  lbz r0, 0(r6);
  slwi r0, r0, 0x18;
  stw r0, 0xc(r1);
  b lbl_80169abc;
lbl_80169a8c:
  lhz r3, 0(r6);
  rlwinm r0, r3, 8, 8, 0xf;
  rlwimi r0, r3, 0x18, 0, 7;
  stw r0, 0xc(r1);
  b lbl_80169abc;
lbl_80169aa0:
  lwz r4, 0(r6);
  rlwinm r3, r4, 8, 8, 0xf;
  rlwinm r0, r4, 0x18, 0x10, 0x17;
  rlwimi r3, r4, 0x18, 0, 7;
  rlwimi r0, r4, 8, 0x18, 0x1f;
  or r0, r3, r0;
  stw r0, 0xc(r1);
lbl_80169abc:
  mr r3, r31;
  mr r4, r29;
  li r5, 0;
  bl EXILock;
  cntlzw r0, r3;
  rlwinm. r30, r0, 0x1b, 5, 0x1f;
  beq lbl_80169ae0;
  li r3, 0;
  b lbl_80169bb0;
lbl_80169ae0:
  mr r3, r31;
  mr r4, r29;
  li r5, 4;
  bl EXISelect;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or. r30, r30, r0;
  beq lbl_80169b10;
  mr r3, r31;
  bl EXIUnlock;
  li r3, 0;
  b lbl_80169bb0;
lbl_80169b10:
  mr r3, r31;
  addi r4, r1, 8;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  mr r3, r31;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXISync;
  cntlzw r0, r3;
  mr r3, r31;
  srwi r0, r0, 5;
  addi r4, r1, 0xc;
  or r30, r30, r0;
  li r5, 4;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  mr r3, r31;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXISync;
  cntlzw r0, r3;
  mr r3, r31;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  mr r3, r31;
  srwi r0, r0, 5;
  or r30, r30, r0;
  bl EXIUnlock;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
  cntlzw r0, r30;
  srwi r3, r0, 5;
lbl_80169bb0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
