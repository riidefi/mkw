#include "cnt.h"

#include <stdio.h>

#include <rvl/arc/rvlArchive.h>
#include <rvl/os/osError.h>
#include <rvl/nand/nand.h>

// Extern function references.
// PAL: 0x80167300
extern UNKNOWN_FUNCTION(ESP_ReadContentFile);
// PAL: 0x801673a0
extern UNKNOWN_FUNCTION(ESP_SeekContentFile);

// Symbol: contentFastOpenNAND
// PAL: 0x8015bc80..0x8015bcec
MARK_BINARY_BLOB(contentFastOpenNAND, 0x8015bc80, 0x8015bcec);
asm UNKNOWN_FUNCTION(contentFastOpenNAND) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  addi r5, r1, 8;
  stw r30, 0x18(r1);
  mr r30, r3;
  bl ARCFastOpen;
  cmpwi r3, 0;
  bne lbl_8015bcb4;
  li r3, -5009;
  b lbl_8015bcd4;
lbl_8015bcb4:
  stw r30, 0(r31);
  li r0, 0;
  li r3, 0;
  lwz r4, 0xc(r1);
  stw r4, 4(r31);
  lwz r4, 0x10(r1);
  stw r4, 8(r31);
  stw r0, 0xc(r31);
lbl_8015bcd4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: CNTConvertPathToEntrynum
// PAL: 0x8015bcec..0x8015bcf0
MARK_BINARY_BLOB(CNTConvertPathToEntrynum, 0x8015bcec, 0x8015bcf0);
asm UNKNOWN_FUNCTION(CNTConvertPathToEntrynum) {
  // clang-format off
  nofralloc;
  b ARCConvertPathToEntrynum;
  // clang-format on
}

// Symbol: CNTGetLength
// PAL: 0x8015bcf0..0x8015bcf8
MARK_BINARY_BLOB(CNTGetLength, 0x8015bcf0, 0x8015bcf8);
asm UNKNOWN_FUNCTION(CNTGetLength) {
  // clang-format off
  nofralloc;
  lwz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: contentReadNAND
// PAL: 0x8015bcf8..0x8015bd98
MARK_BINARY_BLOB(contentReadNAND, 0x8015bcf8, 0x8015bd98);
asm UNKNOWN_FUNCTION(contentReadNAND) {
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
  lwz r0, 0xc(r3);
  add. r4, r0, r6;
  blt lbl_8015bd34;
  lwz r0, 8(r3);
  cmplw r4, r0;
  ble lbl_8015bd3c;
lbl_8015bd34:
  li r3, -5009;
  b lbl_8015bd7c;
lbl_8015bd3c:
  lwz r3, 0(r3);
  li r5, 0;
  lwz r0, 4(r29);
  lwz r3, 0x1c(r3);
  add r4, r0, r4;
  bl ESP_SeekContentFile;
  cmpwi r3, 0;
  bge lbl_8015bd64;
  bl __CNTConvertErrorCode;
  b lbl_8015bd7c;
lbl_8015bd64:
  lwz r3, 0(r29);
  mr r4, r30;
  mr r5, r31;
  lwz r3, 0x1c(r3);
  bl ESP_ReadContentFile;
  bl __CNTConvertErrorCode;
lbl_8015bd7c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: contentCloseNAND
// PAL: 0x8015bd98..0x8015bda0
MARK_BINARY_BLOB(contentCloseNAND, 0x8015bd98, 0x8015bda0);
asm UNKNOWN_FUNCTION(contentCloseNAND) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: __CNTConvertErrorCode
// PAL: 0x8015bda0..0x8015bef0
MARK_BINARY_BLOB(__CNTConvertErrorCode, 0x8015bda0, 0x8015bef0);
asm UNKNOWN_FUNCTION(__CNTConvertErrorCode) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1a;
  mr r12, r1;
  subfic r11, r11, -1024;
  stwux r1, r1, r11;
  mflr r0;
  lis r4, 0x8025;
  stw r0, 4(r12);
  addi r4, r4, -13480;
  li r0, 0x4f;
  addi r6, r1, 0x13c;
  stw r31, -4(r12);
  lis r31, 0x8028;
  addi r31, r31, 0x7ea0;
  addi r5, r4, -4;
  stw r30, -8(r12);
  stw r29, -0xc(r12);
  mr r29, r3;
  mtctr r0;
lbl_8015bde8:
  lwz r4, 4(r5);
  lwzu r0, 8(r5);
  stw r4, 4(r6);
  stwu r0, 8(r6);
  bdnz lbl_8015bde8;
  cmpwi r3, 0;
  li r30, 0;
  li r4, 0;
  blt lbl_8015be14;
  mr r3, r29;
  b lbl_8015bed0;
lbl_8015be14:
  li r0, 0x4f;
  addi r5, r1, 0x140;
  mtctr r0;
lbl_8015be20:
  lwzx r0, r5, r4;
  cmpw r3, r0;
  bne lbl_8015be8c;
  cmpwi r3, -114;
  beq lbl_8015be54;
  cmpwi r3, -116;
  beq lbl_8015be54;
  cmpwi r3, -117;
  beq lbl_8015be54;
  cmpwi r3, -9;
  beq lbl_8015be54;
  cmpwi r3, -12;
  bne lbl_8015be78;
lbl_8015be54:
  mr r5, r29;
  addi r3, r1, 0xc0;
  addi r4, r31, 0x98;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0xc0;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
lbl_8015be78:
  addi r0, r30, 1;
  addi r3, r1, 0x140;
  slwi r0, r0, 2;
  lwzx r3, r3, r0;
  b lbl_8015bed0;
lbl_8015be8c:
  addi r30, r30, 2;
  addi r4, r4, 8;
  bdnz lbl_8015be20;
  mr r4, r29;
  addi r3, r31, 0xac;
  crclr 6;
  bl OSReport;
  mr r5, r29;
  addi r3, r1, 0x40;
  addi r4, r31, 0xe0;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0x40;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
  li r3, -5063;
lbl_8015bed0:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  lwz r30, -8(r10);
  lwz r29, -0xc(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}
