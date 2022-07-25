#include "wbt_ext.h"

#include <string.h>

// Extern function references.
// PAL: 0x80156c4c
extern UNKNOWN_FUNCTION(SDP_SetLocalDiRecord);
// PAL: 0x80156fac
extern UNKNOWN_FUNCTION(SDP_GetLocalDiRecord);
// PAL: 0x80157924
extern UNKNOWN_FUNCTION(SDP_AddAttribute);
// PAL: 0x80157cbc
extern UNKNOWN_FUNCTION(SDP_AddUuidSequence);

// Symbol: WBT_ExtCreateRecord
// PAL: 0x80143380..0x80143460
MARK_BINARY_BLOB(WBT_ExtCreateRecord, 0x80143380, 0x80143460);
asm UNKNOWN_FUNCTION(WBT_ExtCreateRecord) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  li r0, 0x1002;
  addi r3, r1, 0x14;
  addi r4, r1, 0x10;
  stw r31, 0x11c(r1);
  li r31, 0;
  stw r30, 0x118(r1);
  stw r31, 0x10(r1);
  sth r0, 8(r1);
  bl SDP_GetLocalDiRecord;
  clrlwi. r0, r3, 0x10;
  beq lbl_80143400;
  addi r30, r1, 0x16;
  li r4, 0;
  mr r3, r30;
  li r5, 0xfa;
  bl memset;
  li r0, 1;
  li r3, 0xf;
  sth r3, 0x16(r1);
  mr r3, r30;
  addi r4, r1, 0x10;
  sth r0, 0x18(r1);
  stb r0, 0x1e(r1);
  bl SDP_SetLocalDiRecord;
  clrlwi. r0, r3, 0x10;
  beq lbl_80143400;
  stw r31, 0x10(r1);
  li r3, 0;
  b lbl_80143448;
lbl_80143400:
  lwz r3, 0x10(r1);
  addi r6, r1, 8;
  li r4, 5;
  li r5, 1;
  bl SDP_AddUuidSequence;
  li r0, 0;
  li r4, 1;
  lis r3, 1;
  stb r0, 0xc(r1);
  addi r0, r3, -32767;
  lwz r3, 0x10(r1);
  stb r4, 0xd(r1);
  clrlwi r4, r0, 0x10;
  addi r7, r1, 0xc;
  li r5, 1;
  li r6, 2;
  bl SDP_AddAttribute;
  li r3, 1;
lbl_80143448:
  lwz r0, 0x124(r1);
  lwz r31, 0x11c(r1);
  lwz r30, 0x118(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}
