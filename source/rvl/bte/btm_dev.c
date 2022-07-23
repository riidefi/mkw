#include "btm_dev.h"

#include <string.h>

#include "btm_acl.h"
#include "btm_devctl.h"
#include "btm_inq.h"

// Symbol: BTM_SecAddDevice
// PAL: 0x801399a0..0x80139b28
MARK_BINARY_BLOB(BTM_SecAddDevice, 0x801399a0, 0x80139b28);
asm UNKNOWN_FUNCTION(BTM_SecAddDevice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r9, 0x8033;
  mr r24, r3;
  addi r9, r9, 0x6278;
  mr r25, r4;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  mr r29, r8;
  addi r30, r9, 0x1f30;
  li r31, 0;
lbl_801399dc:
  lbz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139a04;
  mr r4, r24;
  addi r3, r30, 0x1c;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139a04;
  b lbl_80139a18;
lbl_80139a04:
  addi r31, r31, 1;
  addi r30, r30, 0x88;
  cmpwi r31, 0x10;
  blt lbl_801399dc;
  li r30, 0;
lbl_80139a18:
  cmpwi r30, 0;
  bne lbl_80139a3c;
  mr r3, r24;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80139a54;
  li r3, 0;
  b lbl_80139b10;
lbl_80139a3c:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r3, 0x1974(r4);
  stw r3, 0xc(r30);
  addi r0, r3, 1;
  stw r0, 0x1974(r4);
lbl_80139a54:
  cmpwi r25, 0;
  beq lbl_80139a6c;
  mr r4, r25;
  addi r3, r30, 0x22;
  li r5, 3;
  bl memcpy;
lbl_80139a6c:
  addi r3, r30, 0x35;
  li r4, 0;
  li r5, 0x41;
  bl memset;
  cmpwi r26, 0;
  beq lbl_80139aac;
  lbz r0, 0(r26);
  cmpwi r0, 0;
  beq lbl_80139aac;
  lbz r0, 0x76(r30);
  mr r4, r26;
  addi r3, r30, 0x35;
  li r5, 0x40;
  ori r0, r0, 8;
  stb r0, 0x76(r30);
  bl strncpy;
lbl_80139aac:
  cmpwi r27, 0;
  beq lbl_80139ac8;
  mr r4, r27;
  addi r3, r30, 0x77;
  li r5, 8;
  bl memcpy;
  b lbl_80139ad8;
lbl_80139ac8:
  addi r3, r30, 0x77;
  li r4, 0;
  li r5, 8;
  bl memset;
lbl_80139ad8:
  lwz r0, 0(r28);
  cmpwi r29, 0;
  stw r0, 0x10(r30);
  lwz r0, 4(r28);
  stw r0, 0x14(r30);
  beq lbl_80139b0c;
  lbz r0, 0x76(r30);
  mr r4, r29;
  addi r3, r30, 0x25;
  li r5, 0x10;
  ori r0, r0, 0x10;
  stb r0, 0x76(r30);
  bl memcpy;
lbl_80139b0c:
  li r3, 1;
lbl_80139b10:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: BTM_SecDeleteDevice
// PAL: 0x80139b28..0x80139bd4
MARK_BINARY_BLOB(BTM_SecDeleteDevice, 0x80139b28, 0x80139bd4);
asm UNKNOWN_FUNCTION(BTM_SecDeleteDevice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x1f30;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_80139b54:
  lbz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139b7c;
  mr r4, r29;
  addi r3, r30, 0x1c;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139b7c;
  b lbl_80139b90;
lbl_80139b7c:
  addi r31, r31, 1;
  addi r30, r30, 0x88;
  cmpwi r31, 0x10;
  blt lbl_80139b54;
  li r30, 0;
lbl_80139b90:
  cmpwi r30, 0;
  bne lbl_80139ba0;
  li r3, 0;
  b lbl_80139bb8;
lbl_80139ba0:
  li r0, 0;
  mr r3, r29;
  stb r0, 0x76(r30);
  li r4, 0;
  bl BTM_DeleteStoredLinkKey;
  li r3, 1;
lbl_80139bb8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_SecReadDevName
// PAL: 0x80139bd4..0x80139c74
MARK_BINARY_BLOB(BTM_SecReadDevName, 0x80139bd4, 0x80139c74);
asm UNKNOWN_FUNCTION(BTM_SecReadDevName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x1f30;
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
lbl_80139c08:
  lbz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139c30;
  mr r4, r28;
  addi r3, r30, 0x1c;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139c30;
  b lbl_80139c44;
lbl_80139c30:
  addi r31, r31, 1;
  addi r30, r30, 0x88;
  cmpwi r31, 0x10;
  blt lbl_80139c08;
  li r30, 0;
lbl_80139c44:
  cmpwi r30, 0;
  beq lbl_80139c50;
  addi r29, r30, 0x35;
lbl_80139c50:
  lwz r31, 0x1c(r1);
  mr r3, r29;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_alloc_dev
// PAL: 0x80139c74..0x80139d94
MARK_BINARY_BLOB(btm_sec_alloc_dev, 0x80139c74, 0x80139d94);
asm UNKNOWN_FUNCTION(btm_sec_alloc_dev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  li r0, 0x10;
  addi r4, r4, 0x6278;
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 0;
  mtctr r0;
lbl_80139ca4:
  lbz r0, 0x1fa6(r4);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  bne lbl_80139cc8;
  mulli r0, r3, 0x88;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  addi r31, r3, 0x1f30;
  b lbl_80139cd4;
lbl_80139cc8:
  addi r4, r4, 0x88;
  addi r3, r3, 1;
  bdnz lbl_80139ca4;
lbl_80139cd4:
  cmpwi r31, 0;
  bne lbl_80139ce4;
  bl btm_find_oldest_dev;
  mr r31, r3;
lbl_80139ce4:
  mr r3, r31;
  li r4, 0;
  li r5, 0x88;
  bl memset;
  li r3, 0x80;
  li r0, 0;
  stb r3, 0x76(r31);
  mr r3, r30;
  stb r0, 0x85(r31);
  bl BTM_InqDbRead;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_80139d2c;
  addi r3, r31, 0x22;
  addi r4, r4, 8;
  li r5, 3;
  bl memcpy;
  b lbl_80139d44;
lbl_80139d2c:
  lis r4, 0x8033;
  addi r3, r31, 0x22;
  addi r4, r4, 0x6278;
  li r5, 3;
  addi r4, r4, 0x27ba;
  bl memcpy;
lbl_80139d44:
  mr r4, r30;
  addi r3, r31, 0x1c;
  li r5, 6;
  bl memcpy;
  mr r3, r30;
  bl BTM_GetHCIConnHandle;
  sth r3, 0x18(r31);
  lis r5, 0x8033;
  addi r5, r5, 0x6278;
  mr r3, r31;
  lwz r4, 0x1974(r5);
  stw r4, 0xc(r31);
  addi r0, r4, 1;
  stw r0, 0x1974(r5);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_find_dev_by_handle
// PAL: 0x80139d94..0x80139e4c
MARK_BINARY_BLOB(btm_find_dev_by_handle, 0x80139d94, 0x80139e4c);
asm UNKNOWN_FUNCTION(btm_find_dev_by_handle) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r0, 4;
  addi r4, r4, 0x6278;
  li r5, 0;
  addi r4, r4, 0x1f30;
  mtctr r0;
lbl_80139dac:
  lbz r0, 0x76(r4);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139dcc;
  lhz r0, 0x18(r4);
  cmplw r0, r3;
  bne lbl_80139dcc;
  mr r3, r4;
  blr;
lbl_80139dcc:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139df0;
  lhz r0, 0x18(r4);
  cmplw r0, r3;
  bne lbl_80139df0;
  mr r3, r4;
  blr;
lbl_80139df0:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139e14;
  lhz r0, 0x18(r4);
  cmplw r0, r3;
  bne lbl_80139e14;
  mr r3, r4;
  blr;
lbl_80139e14:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139e38;
  lhz r0, 0x18(r4);
  cmplw r0, r3;
  bne lbl_80139e38;
  mr r3, r4;
  blr;
lbl_80139e38:
  addi r5, r5, 3;
  addi r4, r4, 0x88;
  bdnz lbl_80139dac;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: btm_find_dev
// PAL: 0x80139e4c..0x80139ed4
MARK_BINARY_BLOB(btm_find_dev, 0x80139e4c, 0x80139ed4);
asm UNKNOWN_FUNCTION(btm_find_dev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  addi r31, r4, 0x1f30;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_80139e78:
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139ea4;
  mr r4, r29;
  addi r3, r31, 0x1c;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139ea4;
  mr r3, r31;
  b lbl_80139eb8;
lbl_80139ea4:
  addi r30, r30, 1;
  addi r31, r31, 0x88;
  cmpwi r30, 0x10;
  blt lbl_80139e78;
  li r3, 0;
lbl_80139eb8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_find_oldest_dev
// PAL: 0x80139ed4..0x8013a06c
MARK_BINARY_BLOB(btm_find_oldest_dev, 0x80139ed4, 0x8013a06c);
asm UNKNOWN_FUNCTION(btm_find_oldest_dev) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  li r6, -1;
  addi r5, r3, 0x1f30;
  li r7, 0;
  mr r3, r5;
  mtctr r0;
lbl_80139ef4:
  lbz r4, 0x76(r5);
  rlwinm. r0, r4, 0, 0x18, 0x18;
  beq lbl_80139f1c;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_80139f1c;
  lwz r0, 0xc(r5);
  cmplw r0, r6;
  bge lbl_80139f1c;
  mr r3, r5;
  mr r6, r0;
lbl_80139f1c:
  lbz r4, 0xfe(r5);
  addi r5, r5, 0x88;
  rlwinm. r0, r4, 0, 0x18, 0x18;
  beq lbl_80139f48;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_80139f48;
  lwz r0, 0xc(r5);
  cmplw r0, r6;
  bge lbl_80139f48;
  mr r3, r5;
  mr r6, r0;
lbl_80139f48:
  lbz r4, 0xfe(r5);
  addi r5, r5, 0x88;
  rlwinm. r0, r4, 0, 0x18, 0x18;
  beq lbl_80139f74;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_80139f74;
  lwz r0, 0xc(r5);
  cmplw r0, r6;
  bge lbl_80139f74;
  mr r3, r5;
  mr r6, r0;
lbl_80139f74:
  lbz r4, 0xfe(r5);
  addi r5, r5, 0x88;
  rlwinm. r0, r4, 0, 0x18, 0x18;
  beq lbl_80139fa0;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_80139fa0;
  lwz r0, 0xc(r5);
  cmplw r0, r6;
  bge lbl_80139fa0;
  mr r3, r5;
  mr r6, r0;
lbl_80139fa0:
  addi r7, r7, 3;
  addi r5, r5, 0x88;
  bdnz lbl_80139ef4;
  addis r0, r6, 1;
  cmplwi r0, 0xffff;
  bnelr;
  lis r4, 0x8033;
  li r0, 4;
  addi r4, r4, 0x6278;
  li r5, 0;
  addi r4, r4, 0x1f30;
  mtctr r0;
lbl_80139fd0:
  lbz r0, 0x76(r4);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80139ff0;
  lwz r0, 0xc(r4);
  cmplw r0, r6;
  bge lbl_80139ff0;
  mr r3, r4;
  mr r6, r0;
lbl_80139ff0:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013a014;
  lwz r0, 0xc(r4);
  cmplw r0, r6;
  bge lbl_8013a014;
  mr r3, r4;
  mr r6, r0;
lbl_8013a014:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013a038;
  lwz r0, 0xc(r4);
  cmplw r0, r6;
  bge lbl_8013a038;
  mr r3, r4;
  mr r6, r0;
lbl_8013a038:
  lbz r0, 0xfe(r4);
  addi r4, r4, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013a05c;
  lwz r0, 0xc(r4);
  cmplw r0, r6;
  bge lbl_8013a05c;
  mr r3, r4;
  mr r6, r0;
lbl_8013a05c:
  addi r5, r5, 3;
  addi r4, r4, 0x88;
  bdnz lbl_80139fd0;
  blr;
  // clang-format on
}
