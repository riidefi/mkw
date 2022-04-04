#include "ansi_files.h"

#include <stdio.h>

// Extern function references.
// PAL: 0x8000c818
extern UNKNOWN_FUNCTION(free);
// PAL: 0x8000ed18
extern UNKNOWN_FUNCTION(fflush);

// Symbol: __close_all
// PAL: 0x8000c948..0x8000c9ec
MARK_BINARY_BLOB(__close_all, 0x8000c948, 0x8000c9ec);
asm void __close_all(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  li r30, 3;
  stw r29, 0x14(r1);
  lis r29, 0x8027;
  addi r29, r29, 0xcf0;
  b lbl_8000c9c8;
lbl_8000c974:
  lwz r0, 4(r29);
  rlwinm. r0, r0, 0xa, 0x1d, 0x1f;
  beq lbl_8000c988;
  mr r3, r29;
  bl fclose;
lbl_8000c988:
  mr r3, r29;
  lwz r29, 0x4c(r29);
  lbz r0, 0xc(r3);
  cmpwi r0, 0;
  beq lbl_8000c9a4;
  bl free;
  b lbl_8000c9c8;
lbl_8000c9a4:
  lwz r0, 4(r3);
  cmpwi r29, 0;
  rlwimi r0, r30, 0x16, 7, 9;
  stw r0, 4(r3);
  beq lbl_8000c9c8;
  lbz r0, 0xc(r29);
  cmpwi r0, 0;
  beq lbl_8000c9c8;
  stw r31, 0x4c(r3);
lbl_8000c9c8:
  cmpwi r29, 0;
  bne lbl_8000c974;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __flush_line_buffered_output_files
// PAL: 0x8000c9ec..0x8000ca70
MARK_BINARY_BLOB(__flush_line_buffered_output_files, 0x8000c9ec, 0x8000ca70);
asm int __flush_line_buffered_output_files(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  lis r30, 0x8027;
  addi r30, r30, 0xcf0;
  b lbl_8000ca4c;
lbl_8000ca10:
  lwz r3, 4(r30);
  rlwinm. r0, r3, 0xa, 0x1d, 0x1f;
  beq lbl_8000ca48;
  rlwinm. r0, r3, 7, 0x1f, 0x1f;
  beq lbl_8000ca48;
  lwz r0, 8(r30);
  srwi r0, r0, 0x1d;
  cmplwi r0, 1;
  bne lbl_8000ca48;
  mr r3, r30;
  bl fflush;
  cmpwi r3, 0;
  beq lbl_8000ca48;
  li r31, -1;
lbl_8000ca48:
  lwz r30, 0x4c(r30);
lbl_8000ca4c:
  cmpwi r30, 0;
  bne lbl_8000ca10;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __flush_all
// PAL: 0x8000ca70..0x8000cadc
MARK_BINARY_BLOB(__flush_all, 0x8000ca70, 0x8000cadc);
asm int __flush_all(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  lis r30, 0x8027;
  addi r30, r30, 0xcf0;
  b lbl_8000cab8;
lbl_8000ca94:
  lwz r0, 4(r30);
  rlwinm. r0, r0, 0xa, 0x1d, 0x1f;
  beq lbl_8000cab4;
  mr r3, r30;
  bl fflush;
  cmpwi r3, 0;
  beq lbl_8000cab4;
  li r31, -1;
lbl_8000cab4:
  lwz r30, 0x4c(r30);
lbl_8000cab8:
  cmpwi r30, 0;
  bne lbl_8000ca94;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
