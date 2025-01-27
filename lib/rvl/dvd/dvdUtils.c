#include "dvdUtils.h"

#include <string.h>

// Symbol: DVDCompareDiskID
// PAL: 0x8016411c..0x8016420c
MARK_BINARY_BLOB(DVDCompareDiskID, 0x8016411c, 0x8016420c);
asm UNKNOWN_FUNCTION(DVDCompareDiskID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lbz r0, 0(r3);
  stw r31, 0xc(r1);
  mr r31, r4;
  extsb. r0, r0;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80164168;
  lbz r0, 0(r4);
  extsb. r0, r0;
  beq lbl_80164168;
  li r5, 4;
  bl strncmp;
  cmpwi r3, 0;
  beq lbl_80164168;
  li r3, 0;
  b lbl_801641f4;
lbl_80164168:
  lbz r0, 4(r30);
  extsb. r0, r0;
  beq lbl_80164198;
  lbz r0, 4(r31);
  extsb. r0, r0;
  beq lbl_80164198;
  addi r3, r30, 4;
  addi r4, r31, 4;
  li r5, 2;
  bl strncmp;
  cmpwi r3, 0;
  beq lbl_801641a0;
lbl_80164198:
  li r3, 0;
  b lbl_801641f4;
lbl_801641a0:
  lbz r3, 6(r30);
  cmplwi r3, 0xff;
  beq lbl_801641c8;
  lbz r0, 6(r31);
  cmplwi r0, 0xff;
  beq lbl_801641c8;
  cmplw r3, r0;
  beq lbl_801641c8;
  li r3, 0;
  b lbl_801641f4;
lbl_801641c8:
  lbz r3, 7(r30);
  cmplwi r3, 0xff;
  beq lbl_801641f0;
  lbz r0, 7(r31);
  cmplwi r0, 0xff;
  beq lbl_801641f0;
  cmplw r3, r0;
  beq lbl_801641f0;
  li r3, 0;
  b lbl_801641f4;
lbl_801641f0:
  li r3, 1;
lbl_801641f4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDGenerateDiskID
// PAL: 0x8016420c..0x80164294
MARK_BINARY_BLOB(DVDGenerateDiskID, 0x8016420c, 0x80164294);
asm UNKNOWN_FUNCTION(DVDGenerateDiskID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r28, r4;
  mr r29, r5;
  mr r27, r3;
  mr r30, r6;
  mr r31, r7;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  cmpwi r28, 0;
  beq lbl_80164258;
  mr r3, r27;
  mr r4, r28;
  li r5, 4;
  bl strncpy;
lbl_80164258:
  cmpwi r29, 0;
  beq lbl_80164270;
  mr r4, r29;
  addi r3, r27, 4;
  li r5, 2;
  bl strncpy;
lbl_80164270:
  stb r30, 6(r27);
  addi r11, r1, 0x20;
  mr r3, r27;
  stb r31, 7(r27);
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
