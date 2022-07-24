#include "dvdBroadway.h"

#include <string.h>

#include <rvl/ipc/ipcMain.h>
#include <rvl/ipc/ipcclt.h>
#include <rvl/os/osError.h>

// Symbol: doTransactionCallback
// PAL: 0x80164684..0x8016473c
MARK_BINARY_BLOB(doTransactionCallback, 0x80164684, 0x8016473c);
asm UNKNOWN_FUNCTION(doTransactionCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  lwz r5, 0xc(r4);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_801646c8;
  lis r3, 0x8029;
  addi r3, r3, -29232;
  crclr 6;
  bl OSReport;
  lis r3, 0xfeec;
  addi r0, r3, -9491;
  stw r0, 0xc(r31);
  b lbl_8016471c;
lbl_801646c8:
  li r6, 0;
  stb r6, -0x64e8(r13);
  lwz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_8016471c;
  lbz r0, -0x64c8(r13);
  li r5, 1;
  stb r5, -0x64e7(r13);
  cmplwi r0, 1;
  bne lbl_801646f8;
  stb r6, -0x64c8(r13);
  ori r3, r3, 8;
lbl_801646f8:
  clrlwi. r0, r3, 0x1f;
  beq lbl_80164708;
  li r0, 0;
  stw r0, -0x64d4(r13);
lbl_80164708:
  lwz r12, 0(r4);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, -0x64e7(r13);
lbl_8016471c:
  li r0, 0;
  li r3, 0;
  stb r0, 8(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: doPrepareCoverRegisterCallback
// PAL: 0x8016473c..0x801647f8
MARK_BINARY_BLOB(doPrepareCoverRegisterCallback, 0x8016473c, 0x801647f8);
asm UNKNOWN_FUNCTION(doPrepareCoverRegisterCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  lis r6, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, 0x3560;
  stw r31, 0xc(r1);
  mr r31, r4;
  lwz r0, 0x3580(r6);
  li r6, 0;
  stb r6, -0x64e8(r13);
  stw r0, 4(r5);
  lwz r5, 0xc(r4);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_8016479c;
  lis r3, 0x8029;
  addi r3, r3, -29232;
  crclr 6;
  bl OSReport;
  lis r3, 0xfeec;
  addi r0, r3, -9491;
  stw r0, 0xc(r31);
  b lbl_801647d8;
lbl_8016479c:
  lwz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_801647d8;
  lbz r0, -0x64c8(r13);
  li r5, 1;
  stb r5, -0x64e7(r13);
  cmplwi r0, 1;
  bne lbl_801647c4;
  stb r6, -0x64c8(r13);
  ori r3, r3, 8;
lbl_801647c4:
  lwz r12, 0(r4);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, -0x64e7(r13);
lbl_801647d8:
  li r0, 0;
  li r3, 0;
  stb r0, 8(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowFinalize
// PAL: 0x801647f8..0x80164848
MARK_BINARY_BLOB(DVDLowFinalize, 0x801647f8, 0x80164848);
asm UNKNOWN_FUNCTION(DVDLowFinalize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r3, -0x7318(r13);
  bl IOS_Close;
  cmpwi r3, 0;
  beq lbl_8016482c;
  lis r3, 0x8029;
  addi r3, r3, -29136;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164838;
lbl_8016482c:
  li r0, 0;
  li r3, 1;
  stb r0, -0x64db(r13);
lbl_80164838:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowInit
// PAL: 0x80164848..0x80164aac
MARK_BINARY_BLOB(DVDLowInit, 0x80164848, 0x80164aac);
asm UNKNOWN_FUNCTION(DVDLowInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lbz r0, -0x64db(r13);
  cmpwi r0, 0;
  bne lbl_801649f0;
  li r0, 1;
  stb r0, -0x64db(r13);
  bl IPCCltInit;
  cmpwi r3, 0;
  beq lbl_8016489c;
  mr r4, r3;
  addi r3, r31, 0x88;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164a94;
lbl_8016489c:
  bl IPCGetBufferLo;
  mr r30, r3;
  bl IPCGetBufferHi;
  clrlwi. r0, r30, 0x1b;
  beq lbl_801648b8;
  addi r0, r30, 0x1f;
  clrlwi r30, r0, 0x1b;
lbl_801648b8:
  addi r0, r30, 0x80;
  cmplw r0, r3;
  ble lbl_801648d4;
  addi r3, r31, 0xa8;
  li r4, 0x80;
  crclr 6;
  bl OSReport;
lbl_801648d4:
  addi r3, r30, 0x80;
  bl IPCSetBufferLo;
  cmpwi r30, 0;
  stw r30, -0x64cc(r13);
  bne lbl_801648fc;
  addi r3, r31, 0xe4;
  crclr 6;
  bl OSReport;
  li r0, 0;
  b lbl_80164960;
lbl_801648fc:
  bl IPCGetBufferLo;
  mr r30, r3;
  bl IPCGetBufferHi;
  clrlwi. r0, r30, 0x1b;
  beq lbl_80164918;
  addi r0, r30, 0x1f;
  clrlwi r30, r0, 0x1b;
lbl_80164918:
  addi r0, r30, 0x20;
  cmplw r0, r3;
  ble lbl_80164934;
  addi r3, r31, 0xa8;
  li r4, 0x20;
  crclr 6;
  bl OSReport;
lbl_80164934:
  addi r3, r30, 0x20;
  bl IPCSetBufferLo;
  cmpwi r30, 0;
  stw r30, -0x64d0(r13);
  bne lbl_8016495c;
  addi r3, r31, 0x10c;
  crclr 6;
  bl OSReport;
  li r0, 0;
  b lbl_80164960;
lbl_8016495c:
  li r0, 1;
lbl_80164960:
  cmpwi r0, 0;
  bne lbl_80164970;
  li r3, 0;
  b lbl_80164a94;
lbl_80164970:
  lbz r0, -0x64dc(r13);
  cmpwi r0, 0;
  bne lbl_801649f0;
  li r5, 0;
  lis r4, 0x8034;
  stwu r5, 0x34e0(r4);
  lis r3, 0xfeec;
  li r0, 1;
  li r6, 2;
  stw r5, 4(r4);
  addi r3, r3, -9491;
  stb r5, 8(r4);
  stw r3, 0xc(r4);
  stw r5, 0x10(r4);
  stw r5, 0x20(r4);
  stw r5, 0x24(r4);
  stb r5, 0x28(r4);
  stw r3, 0x2c(r4);
  stw r0, 0x30(r4);
  stw r5, 0x40(r4);
  stw r5, 0x44(r4);
  stb r5, 0x48(r4);
  stw r3, 0x4c(r4);
  stw r6, 0x50(r4);
  li r6, 3;
  stw r5, 0x60(r4);
  stw r5, 0x64(r4);
  stb r5, 0x68(r4);
  stw r3, 0x6c(r4);
  stw r6, 0x70(r4);
  stw r5, -0x64e0(r13);
  stb r0, -0x64dc(r13);
lbl_801649f0:
  lwz r3, -0x64d0(r13);
  addi r4, r13, -29456;
  li r5, 0x20;
  bl strncpy;
  lwz r3, -0x64d0(r13);
  li r4, 0;
  bl IOS_Open;
  cmpwi r3, 0;
  stw r3, -0x7318(r13);
  blt lbl_80164a20;
  li r3, 1;
  b lbl_80164a94;
lbl_80164a20:
  cmpwi r3, -5;
  beq lbl_80164a6c;
  bge lbl_80164a38;
  cmpwi r3, -6;
  bge lbl_80164a44;
  b lbl_80164a80;
lbl_80164a38:
  cmpwi r3, -1;
  beq lbl_80164a58;
  b lbl_80164a80;
lbl_80164a44:
  addi r3, r31, 0x12c;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164a94;
lbl_80164a58:
  addi r3, r31, 0x178;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164a94;
lbl_80164a6c:
  addi r3, r31, 0x1c0;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164a94;
lbl_80164a80:
  mr r4, r3;
  addi r3, r31, 0x20c;
  crclr 6;
  bl OSReport;
  li r3, 0;
lbl_80164a94:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowReadDiskID
// PAL: 0x80164aac..0x80164c34
MARK_BINARY_BLOB(DVDLowReadDiskID, 0x80164aac, 0x80164c34);
asm UNKNOWN_FUNCTION(DVDLowReadDiskID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8034;
  li r10, 1;
  stw r0, 0x24(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0x1c(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  lwz r9, -0x64e0(r13);
  stb r10, -0x64e8(r13);
  slwi r8, r9, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80164b24;
  mr r4, r9;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80164b20:
  b lbl_80164b20;
lbl_80164b24:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80164b44;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80164b40:
  b lbl_80164b40;
lbl_80164b44:
  stwx r4, r7, r8;
  addi r0, r9, 1;
  cmpwi r0, 4;
  stw r10, 4(r6);
  stb r10, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80164b68;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80164b68:
  lis r4, 0x8034;
  cmpwi r3, 0;
  slwi r0, r9, 5;
  addi r4, r4, 0x34e0;
  add r29, r4, r0;
  bne lbl_80164b8c;
  addi r3, r31, 0x2e8;
  crclr 6;
  bl OSReport;
lbl_80164b8c:
  lwz r3, -0x64e4(r13);
  addi r0, r3, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  blt lbl_80164ba8;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80164ba8:
  lwz r3, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r4, 0x70;
  stbx r4, r3, r0;
  mr r7, r30;
  mr r10, r29;
  addi r9, r9, 0x4684;
  lwz r0, -0x64e4(r13);
  li r4, 0x70;
  lwz r5, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  li r8, 0x20;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80164c14;
  mr r4, r3;
  addi r3, r31, 0x324;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r29);
  b lbl_80164c18;
lbl_80164c14:
  li r3, 1;
lbl_80164c18:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDLowOpenPartition
// PAL: 0x80164c34..0x80164e9c
MARK_BINARY_BLOB(DVDLowOpenPartition, 0x80164c34, 0x80164e9c);
asm UNKNOWN_FUNCTION(DVDLowOpenPartition) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r9, 0x8034;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  addi r9, r9, 0x34e0;
  stw r31, 0x1c(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  beq lbl_80164c84;
  clrlwi. r0, r4, 0x1b;
  beq lbl_80164c84;
  addi r3, r31, 0x360;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164e7c;
lbl_80164c84:
  cmpwi r6, 0;
  beq lbl_80164ca8;
  clrlwi. r0, r6, 0x1b;
  beq lbl_80164ca8;
  addi r3, r31, 0x398;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164e7c;
lbl_80164ca8:
  cmpwi r7, 0;
  beq lbl_80164ccc;
  clrlwi. r0, r7, 0x1b;
  beq lbl_80164ccc;
  addi r3, r31, 0x398;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_80164e7c;
lbl_80164ccc:
  lwz r29, -0x64e0(r13);
  li r28, 1;
  addi r12, r9, 0;
  stb r28, -0x64e8(r13);
  slwi r30, r29, 5;
  add r11, r12, r30;
  lbz r10, 8(r11);
  neg r0, r10;
  or r0, r0, r10;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80164d1c;
  mr r4, r29;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80164d18:
  b lbl_80164d18;
lbl_80164d1c:
  lwz r10, 0xc(r11);
  addis r0, r10, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80164d3c;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80164d38:
  b lbl_80164d38;
lbl_80164d3c:
  stwx r8, r12, r30;
  addi r0, r29, 1;
  cmpwi r0, 4;
  stw r28, 4(r11);
  stb r28, 8(r11);
  stw r0, -0x64e0(r13);
  blt lbl_80164d60;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80164d60:
  lwz r8, -0x64e4(r13);
  slwi r11, r29, 5;
  addi r10, r9, 0;
  addi r0, r8, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r10, r11;
  blt lbl_80164d88;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80164d88:
  lwz r8, -0x64cc(r13);
  slwi r0, r0, 5;
  li r10, 0x8b;
  cmpwi r4, 0;
  stbx r10, r8, r0;
  addi r8, r9, 0xc0;
  li r0, 0x20;
  lwz r10, -0x64e4(r13);
  lwz r11, -0x64cc(r13);
  slwi r10, r10, 5;
  add r10, r11, r10;
  stw r3, 4(r10);
  lwz r3, -0x64e4(r13);
  lwz r10, -0x64cc(r13);
  slwi r3, r3, 5;
  stw r0, 4(r8);
  add r0, r10, r3;
  stw r0, 0xc0(r9);
  stw r4, 8(r8);
  bne lbl_80164de4;
  li r0, 0;
  stw r0, 0xc(r8);
  b lbl_80164dec;
lbl_80164de4:
  li r0, 0x2a4;
  stw r0, 0xc(r8);
lbl_80164dec:
  addi r3, r9, 0xc0;
  cmpwi r6, 0;
  stw r6, 0x10(r3);
  bne lbl_80164e08;
  li r0, 0;
  stw r0, 0x14(r3);
  b lbl_80164e0c;
lbl_80164e08:
  stw r5, 0x14(r3);
lbl_80164e0c:
  addi r10, r9, 0xc0;
  addi r5, r9, 0x120;
  li r4, 0x49e4;
  li r0, 0x20;
  stw r7, 0x18(r10);
  lis r8, 0x8016;
  lwz r3, -0x7318(r13);
  mr r7, r10;
  stw r4, 0x1c(r10);
  mr r9, r30;
  addi r8, r8, 0x4684;
  li r4, 0x8b;
  stw r5, 0x20(r10);
  li r5, 3;
  li r6, 2;
  stw r0, 0x24(r10);
  bl IOS_IoctlvAsync;
  cmpwi r3, 0;
  beq lbl_80164e78;
  mr r4, r3;
  addi r3, r31, 0x3d0;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80164e7c;
lbl_80164e78:
  li r3, 1;
lbl_80164e7c:
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

// Symbol: DVDLowOpenPartitionWithTmdAndTicketView
// PAL: 0x80164e9c..0x80165100
MARK_BINARY_BLOB(DVDLowOpenPartitionWithTmdAndTicketView, 0x80164e9c,
                 0x80165100);
asm UNKNOWN_FUNCTION(DVDLowOpenPartitionWithTmdAndTicketView) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r8, 0;
  lis r10, 0x8034;
  lis r31, 0x8029;
  addi r10, r10, 0x34e0;
  addi r31, r31, -29232;
  beq lbl_80164ed8;
  clrlwi. r0, r8, 0x1b;
  beq lbl_80164ed8;
  li r3, 0;
  b lbl_801650e8;
lbl_80164ed8:
  cmpwi r6, 0;
  bne lbl_80164ef8;
  addi r3, r31, 0x458;
  addi r4, r31, 0x4c8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801650e8;
lbl_80164ef8:
  clrlwi. r0, r6, 0x1b;
  beq lbl_80164f18;
  addi r3, r31, 0x47c;
  addi r4, r31, 0x4c8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801650e8;
lbl_80164f18:
  cmpwi r4, 0;
  bne lbl_80164f38;
  addi r3, r31, 0x4f0;
  addi r4, r31, 0x4c8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801650e8;
lbl_80164f38:
  clrlwi. r0, r4, 0x1b;
  beq lbl_80164f58;
  addi r3, r31, 0x51c;
  addi r4, r31, 0x4c8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801650e8;
lbl_80164f58:
  lwz r28, -0x64e0(r13);
  li r27, 1;
  addi r29, r10, 0;
  stb r27, -0x64e8(r13);
  slwi r30, r28, 5;
  add r12, r29, r30;
  lbz r11, 8(r12);
  neg r0, r11;
  or r0, r0, r11;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80164fa8;
  mr r4, r28;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80164fa4:
  b lbl_80164fa4;
lbl_80164fa8:
  lwz r11, 0xc(r12);
  addis r0, r11, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80164fc8;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80164fc4:
  b lbl_80164fc4;
lbl_80164fc8:
  stwx r9, r29, r30;
  addi r0, r28, 1;
  cmpwi r0, 4;
  stw r27, 4(r12);
  stb r27, 8(r12);
  stw r0, -0x64e0(r13);
  blt lbl_80164fec;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80164fec:
  lwz r9, -0x64e4(r13);
  slwi r12, r28, 5;
  addi r11, r10, 0;
  addi r0, r9, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r11, r12;
  blt lbl_80165014;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165014:
  lwz r9, -0x64cc(r13);
  slwi r0, r0, 5;
  li r11, 0x94;
  cmpwi r8, 0;
  stbx r11, r9, r0;
  addi r9, r10, 0xc0;
  li r11, 0x20;
  li r0, 0xd8;
  lwz r12, -0x64e4(r13);
  lwz r29, -0x64cc(r13);
  slwi r12, r12, 5;
  add r12, r29, r12;
  stw r3, 4(r12);
  lwz r3, -0x64e4(r13);
  lwz r12, -0x64cc(r13);
  slwi r3, r3, 5;
  stw r11, 4(r9);
  add r3, r12, r3;
  stw r3, 0xc0(r10);
  stw r4, 8(r9);
  stw r0, 0xc(r9);
  stw r6, 0x10(r9);
  stw r5, 0x14(r9);
  stw r8, 0x18(r9);
  bne lbl_80165084;
  li r0, 0;
  stw r0, 0x1c(r9);
  b lbl_80165088;
lbl_80165084:
  stw r7, 0x1c(r9);
lbl_80165088:
  addi r7, r10, 0xc0;
  addi r3, r10, 0x120;
  li r0, 0x20;
  lis r8, 0x8016;
  stw r3, 0x20(r7);
  mr r9, r30;
  lwz r3, -0x7318(r13);
  addi r8, r8, 0x4684;
  stw r0, 0x24(r7);
  li r4, 0x94;
  li r5, 4;
  li r6, 1;
  bl IOS_IoctlvAsync;
  cmpwi r3, 0;
  beq lbl_801650e4;
  mr r4, r3;
  addi r3, r31, 0x3d0;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_801650e8;
lbl_801650e4:
  li r3, 1;
lbl_801650e8:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDLowGetNoDiscBufferSizes
// PAL: 0x80165100..0x8016530c
MARK_BINARY_BLOB(DVDLowGetNoDiscBufferSizes, 0x80165100, 0x8016530c);
asm UNKNOWN_FUNCTION(DVDLowGetNoDiscBufferSizes) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  beq lbl_8016512c;
  cmpwi r5, 0;
  bne lbl_80165144;
lbl_8016512c:
  addi r3, r31, 0x560;
  addi r4, r31, 0x544;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801652f4;
lbl_80165144:
  clrlwi. r0, r4, 0x1b;
  beq lbl_80165164;
  addi r3, r31, 0x584;
  addi r4, r31, 0x544;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801652f4;
lbl_80165164:
  clrlwi. r0, r5, 0x1b;
  beq lbl_80165184;
  addi r3, r31, 0x5ac;
  addi r4, r31, 0x544;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801652f4;
lbl_80165184:
  lwz r11, -0x64e0(r13);
  lis r9, 0x8034;
  li r12, 1;
  slwi r10, r11, 5;
  addi r9, r9, 0x34e0;
  add r8, r9, r10;
  stb r12, -0x64e8(r13);
  lbz r7, 8(r8);
  neg r0, r7;
  or r0, r0, r7;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_801651d8;
  mr r4, r11;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_801651d4:
  b lbl_801651d4;
lbl_801651d8:
  lwz r7, 0xc(r8);
  addis r0, r7, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_801651f8;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_801651f4:
  b lbl_801651f4;
lbl_801651f8:
  stwx r6, r9, r10;
  addi r0, r11, 1;
  cmpwi r0, 4;
  stw r12, 4(r8);
  stb r12, 8(r8);
  stw r0, -0x64e0(r13);
  blt lbl_8016521c;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_8016521c:
  lwz r6, -0x64e4(r13);
  lis r7, 0x8034;
  slwi r8, r11, 5;
  addi r0, r6, 1;
  addi r7, r7, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r7, r8;
  blt lbl_80165248;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165248:
  lwz r6, -0x64cc(r13);
  lis r8, 0x8016;
  slwi r0, r0, 5;
  li r7, 0x92;
  stbx r7, r6, r0;
  lis r11, 0x8034;
  addi r7, r11, 0x35a0;
  li r10, 0x20;
  lwz r6, -0x64e4(r13);
  li r0, 4;
  lwz r12, -0x64cc(r13);
  mr r9, r30;
  slwi r6, r6, 5;
  addi r8, r8, 0x4684;
  add r6, r12, r6;
  stw r3, 4(r6);
  li r6, 2;
  lwz r3, -0x64e4(r13);
  lwz r12, -0x64cc(r13);
  slwi r3, r3, 5;
  stw r4, 8(r7);
  add r12, r12, r3;
  lwz r3, -0x7318(r13);
  stw r5, 0x10(r7);
  li r4, 0x92;
  li r5, 1;
  stw r12, 0x35a0(r11);
  stw r10, 4(r7);
  stw r0, 0xc(r7);
  stw r0, 0x14(r7);
  bl IOS_IoctlvAsync;
  cmpwi r3, 0;
  beq lbl_801652f0;
  mr r5, r3;
  addi r3, r31, 0x5d4;
  addi r4, r31, 0x544;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_801652f4;
lbl_801652f0:
  li r3, 1;
lbl_801652f4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowGetNoDiscOpenPartitionParams
// PAL: 0x8016530c..0x801655a4
MARK_BINARY_BLOB(DVDLowGetNoDiscOpenPartitionParams, 0x8016530c, 0x801655a4);
asm UNKNOWN_FUNCTION(DVDLowGetNoDiscOpenPartitionParams) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  cmpwi r4, 0;
  lis r31, 0x8029;
  lwz r28, 0x38(r1);
  addi r31, r31, -29232;
  beq lbl_80165364;
  cmpwi r5, 0;
  beq lbl_80165364;
  cmpwi r6, 0;
  beq lbl_80165364;
  cmpwi r7, 0;
  beq lbl_80165364;
  cmpwi r8, 0;
  beq lbl_80165364;
  cmpwi r9, 0;
  beq lbl_80165364;
  cmpwi r10, 0;
  bne lbl_8016537c;
lbl_80165364:
  addi r3, r31, 0x560;
  addi r4, r31, 0x604;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8016558c;
lbl_8016537c:
  clrlwi. r0, r4, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r5, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r6, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r7, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r8, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r9, 0x1b;
  bne lbl_801653b4;
  clrlwi. r0, r10, 0x1b;
  beq lbl_801653cc;
lbl_801653b4:
  addi r3, r31, 0x628;
  addi r4, r31, 0x604;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8016558c;
lbl_801653cc:
  lwz r26, -0x64e0(r13);
  lis r24, 0x8034;
  li r27, 1;
  slwi r25, r26, 5;
  addi r24, r24, 0x34e0;
  add r12, r24, r25;
  stb r27, -0x64e8(r13);
  lbz r11, 8(r12);
  neg r0, r11;
  or r0, r0, r11;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165420;
  mr r4, r26;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_8016541c:
  b lbl_8016541c;
lbl_80165420:
  lwz r11, 0xc(r12);
  addis r0, r11, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165440;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_8016543c:
  b lbl_8016543c;
lbl_80165440:
  stwx r28, r24, r25;
  addi r0, r26, 1;
  cmpwi r0, 4;
  stw r27, 4(r12);
  stb r27, 8(r12);
  stw r0, -0x64e0(r13);
  blt lbl_80165464;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165464:
  lwz r11, -0x64e4(r13);
  lis r12, 0x8034;
  slwi r24, r26, 5;
  addi r0, r11, 1;
  addi r12, r12, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r12, r24;
  blt lbl_80165490;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165490:
  lwz r11, -0x64cc(r13);
  lis r26, 0x8034;
  slwi r0, r0, 5;
  li r12, 0x90;
  stbx r12, r11, r0;
  addi r28, r26, 0x35a0;
  li r27, 0x20;
  li r29, 4;
  lwz r0, -0x64e4(r13);
  li r12, 0x2a4;
  lwz r24, -0x64cc(r13);
  lis r11, 2;
  slwi r25, r0, 5;
  add r25, r24, r25;
  addi r0, r11, -32768;
  stw r3, 4(r25);
  lis r11, 0x8016;
  lwz r3, -0x64e4(r13);
  lwz r25, -0x64cc(r13);
  slwi r3, r3, 5;
  stw r4, 0x18(r28);
  add r25, r25, r3;
  lwz r3, -0x7318(r13);
  stw r6, 0x28(r28);
  li r4, 0x90;
  li r6, 7;
  stw r25, 0x35a0(r26);
  stw r27, 4(r28);
  stw r5, 8(r28);
  stw r29, 0xc(r28);
  stw r7, 0x10(r28);
  stw r29, 0x14(r28);
  stw r12, 0x1c(r28);
  stw r5, 0x20(r28);
  stw r29, 0x24(r28);
  lwz r12, 0(r5);
  li r5, 3;
  stw r8, 0x38(r28);
  addi r8, r11, 0x4684;
  stw r12, 0x2c(r28);
  stw r7, 0x30(r28);
  stw r29, 0x34(r28);
  lwz r11, 0(r7);
  mr r7, r28;
  stw r9, 0x40(r28);
  mr r9, r30;
  stw r11, 0x3c(r28);
  stw r29, 0x44(r28);
  stw r10, 0x48(r28);
  stw r0, 0x4c(r28);
  bl IOS_IoctlvAsync;
  cmpwi r3, 0;
  beq lbl_80165588;
  mr r5, r3;
  addi r3, r31, 0x5d4;
  addi r4, r31, 0x604;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_8016558c;
lbl_80165588:
  li r3, 1;
lbl_8016558c:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: DVDLowClosePartition
// PAL: 0x801655a4..0x80165708
MARK_BINARY_BLOB(DVDLowClosePartition, 0x801655a4, 0x80165708);
asm UNKNOWN_FUNCTION(DVDLowClosePartition) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e4(r13);
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  blt lbl_801655dc;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_801655dc:
  lwz r4, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r5, 0x8c;
  stbx r5, r4, r0;
  li r9, 1;
  addi r7, r7, 0x34e0;
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_8016563c;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165638:
  b lbl_80165638;
lbl_8016563c:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_8016565c;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165658:
  b lbl_80165658;
lbl_8016565c:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80165680;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165680:
  lwz r0, -0x64e4(r13);
  lis r3, 0x8034;
  slwi r5, r4, 5;
  lwz r4, -0x64cc(r13);
  addi r3, r3, 0x34e0;
  lis r9, 0x8016;
  add r30, r3, r5;
  slwi r0, r0, 5;
  add r5, r4, r0;
  lwz r3, -0x7318(r13);
  mr r10, r30;
  addi r9, r9, 0x4684;
  li r4, 0x8c;
  li r6, 0x20;
  li r7, 0;
  li r8, 0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_801656ec;
  mr r4, r3;
  addi r3, r31, 0x668;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_801656f0;
lbl_801656ec:
  li r3, 1;
lbl_801656f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowUnencryptedRead
// PAL: 0x80165708..0x8016589c
MARK_BINARY_BLOB(DVDLowUnencryptedRead, 0x80165708, 0x8016589c);
asm UNKNOWN_FUNCTION(DVDLowUnencryptedRead) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r9, 0x8034;
  li r12, 1;
  stw r0, 0x14(r1);
  addi r9, r9, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r11, -0x64e0(r13);
  stb r12, -0x64e8(r13);
  slwi r10, r11, 5;
  add r8, r9, r10;
  lbz r7, 8(r8);
  neg r0, r7;
  or r0, r0, r7;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165778;
  mr r4, r11;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165774:
  b lbl_80165774;
lbl_80165778:
  lwz r7, 0xc(r8);
  addis r0, r7, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165798;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165794:
  b lbl_80165794;
lbl_80165798:
  stwx r6, r9, r10;
  addi r0, r11, 1;
  cmpwi r0, 4;
  stw r12, 4(r8);
  stb r12, 8(r8);
  stw r0, -0x64e0(r13);
  blt lbl_801657bc;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_801657bc:
  lwz r6, -0x64e4(r13);
  lis r7, 0x8034;
  stw r4, -0x64d4(r13);
  slwi r8, r11, 5;
  addi r0, r6, 1;
  addi r7, r7, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r7, r8;
  blt lbl_801657ec;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_801657ec:
  lwz r6, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r7, 0x8d;
  stbx r7, r6, r0;
  mr r7, r3;
  mr r8, r4;
  mr r10, r30;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r3, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r4, 4(r3);
  li r4, 0x8d;
  lwz r0, -0x64e4(r13);
  lwz r3, -0x64cc(r13);
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r5, 8(r3);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80165880;
  mr r4, r3;
  addi r3, r31, 0x6a8;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80165884;
lbl_80165880:
  li r3, 1;
lbl_80165884:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowStopMotor
// PAL: 0x8016589c..0x80165a30
MARK_BINARY_BLOB(DVDLowStopMotor, 0x8016589c, 0x80165a30);
asm UNKNOWN_FUNCTION(DVDLowStopMotor) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r8, 0x8034;
  li r11, 1;
  stw r0, 0x14(r1);
  addi r8, r8, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r10, -0x64e0(r13);
  stb r11, -0x64e8(r13);
  slwi r9, r10, 5;
  add r7, r8, r9;
  lbz r6, 8(r7);
  neg r0, r6;
  or r0, r0, r6;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_8016590c;
  mr r4, r10;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165908:
  b lbl_80165908;
lbl_8016590c:
  lwz r6, 0xc(r7);
  addis r0, r6, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_8016592c;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165928:
  b lbl_80165928;
lbl_8016592c:
  stwx r5, r8, r9;
  addi r0, r10, 1;
  cmpwi r0, 4;
  stw r11, 4(r7);
  stb r11, 8(r7);
  stw r0, -0x64e0(r13);
  blt lbl_80165950;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165950:
  lwz r5, -0x64e4(r13);
  lis r6, 0x8034;
  slwi r7, r10, 5;
  addi r0, r5, 1;
  addi r6, r6, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r6, r7;
  blt lbl_8016597c;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_8016597c:
  lwz r5, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r6, 0xe3;
  stbx r6, r5, r0;
  lis r9, 0x8016;
  mr r10, r30;
  addi r7, r7, 0x3560;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r5, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  li r8, 0x20;
  add r5, r5, r0;
  stw r3, 4(r5);
  lwz r0, -0x64e4(r13);
  lwz r3, -0x64cc(r13);
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r4, 8(r3);
  li r4, 0xe3;
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80165a14;
  mr r4, r3;
  addi r3, r31, 0x6e8;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80165a18;
lbl_80165a14:
  li r3, 1;
lbl_80165a18:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowInquiry
// PAL: 0x80165a30..0x80165b98
MARK_BINARY_BLOB(DVDLowInquiry, 0x80165a30, 0x80165b98);
asm UNKNOWN_FUNCTION(DVDLowInquiry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8034;
  li r10, 1;
  stw r0, 0x14(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r9, -0x64e0(r13);
  stb r10, -0x64e8(r13);
  slwi r8, r9, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165aa0;
  mr r4, r9;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165a9c:
  b lbl_80165a9c;
lbl_80165aa0:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165ac0;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165abc:
  b lbl_80165abc;
lbl_80165ac0:
  stwx r4, r7, r8;
  addi r0, r9, 1;
  cmpwi r0, 4;
  stw r10, 4(r6);
  stb r10, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80165ae4;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165ae4:
  lwz r4, -0x64e4(r13);
  lis r5, 0x8034;
  slwi r6, r9, 5;
  addi r0, r4, 1;
  addi r5, r5, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r5, r6;
  blt lbl_80165b10;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165b10:
  lwz r4, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r5, 0x12;
  stbx r5, r4, r0;
  mr r7, r3;
  mr r10, r30;
  addi r9, r9, 0x4684;
  lwz r0, -0x64e4(r13);
  li r4, 0x12;
  lwz r5, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  li r8, 0x20;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80165b7c;
  mr r4, r3;
  addi r3, r31, 0x768;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80165b80;
lbl_80165b7c:
  li r3, 1;
lbl_80165b80:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowRequestError
// PAL: 0x80165b98..0x80165d00
MARK_BINARY_BLOB(DVDLowRequestError, 0x80165b98, 0x80165d00);
asm UNKNOWN_FUNCTION(DVDLowRequestError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8034;
  li r9, 1;
  stw r0, 0x14(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165c04;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165c00:
  b lbl_80165c00;
lbl_80165c04:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165c24;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165c20:
  b lbl_80165c20;
lbl_80165c24:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80165c48;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165c48:
  lwz r3, -0x64e4(r13);
  lis r5, 0x8034;
  slwi r4, r4, 5;
  addi r0, r3, 1;
  addi r5, r5, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r5, r4;
  blt lbl_80165c74;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165c74:
  lwz r3, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r4, 0xe0;
  stbx r4, r3, r0;
  lis r9, 0x8016;
  mr r10, r30;
  addi r7, r7, 0x3560;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r5, -0x64cc(r13);
  li r4, 0xe0;
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  li r6, 0x20;
  li r8, 0x20;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80165ce4;
  mr r4, r3;
  addi r3, r31, 0x7a0;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80165ce8;
lbl_80165ce4:
  li r3, 1;
lbl_80165ce8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowSetSpinupFlag
// PAL: 0x80165d00..0x80165d0c
MARK_BINARY_BLOB(DVDLowSetSpinupFlag, 0x80165d00, 0x80165d0c);
asm UNKNOWN_FUNCTION(DVDLowSetSpinupFlag) {
  // clang-format off
  nofralloc;
  stw r3, -0x64d8(r13);
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: DVDLowReset
// PAL: 0x80165d0c..0x80165e88
MARK_BINARY_BLOB(DVDLowReset, 0x80165d0c, 0x80165e88);
asm UNKNOWN_FUNCTION(DVDLowReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8034;
  li r9, 1;
  stw r0, 0x14(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165d78;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165d74:
  b lbl_80165d74;
lbl_80165d78:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165d98;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165d94:
  b lbl_80165d94;
lbl_80165d98:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80165dbc;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165dbc:
  lwz r3, -0x64e4(r13);
  lis r5, 0x8034;
  slwi r4, r4, 5;
  addi r0, r3, 1;
  addi r5, r5, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r5, r4;
  blt lbl_80165de8;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165de8:
  lwz r3, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r4, 0x8a;
  stbx r4, r3, r0;
  mr r10, r30;
  addi r9, r9, 0x4684;
  li r4, 0x8a;
  lwz r0, -0x64e4(r13);
  li r6, 0x20;
  lwz r3, -0x64cc(r13);
  li r7, 0;
  slwi r0, r0, 5;
  lwz r5, -0x64d8(r13);
  add r3, r3, r0;
  li r8, 0;
  stw r5, 4(r3);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80165e6c;
  mr r4, r3;
  addi r3, r31, 0x860;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80165e70;
lbl_80165e6c:
  li r3, 1;
lbl_80165e70:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowAudioBufferConfig
// PAL: 0x80165e88..0x8016601c
MARK_BINARY_BLOB(DVDLowAudioBufferConfig, 0x80165e88, 0x8016601c);
asm UNKNOWN_FUNCTION(DVDLowAudioBufferConfig) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r8, 0x8034;
  li r11, 1;
  stw r0, 0x14(r1);
  addi r8, r8, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r10, -0x64e0(r13);
  stb r11, -0x64e8(r13);
  slwi r9, r10, 5;
  add r7, r8, r9;
  lbz r6, 8(r7);
  neg r0, r6;
  or r0, r0, r6;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80165ef8;
  mr r4, r10;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80165ef4:
  b lbl_80165ef4;
lbl_80165ef8:
  lwz r6, 0xc(r7);
  addis r0, r6, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80165f18;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80165f14:
  b lbl_80165f14;
lbl_80165f18:
  stwx r5, r8, r9;
  addi r0, r10, 1;
  cmpwi r0, 4;
  stw r11, 4(r7);
  stb r11, 8(r7);
  stw r0, -0x64e0(r13);
  blt lbl_80165f3c;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80165f3c:
  lwz r5, -0x64e4(r13);
  lis r6, 0x8034;
  slwi r7, r10, 5;
  addi r0, r5, 1;
  addi r6, r6, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r6, r7;
  blt lbl_80165f68;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80165f68:
  lwz r5, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r6, 0xe4;
  stbx r6, r5, r0;
  lis r9, 0x8016;
  mr r10, r30;
  addi r7, r7, 0x3560;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r5, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  li r8, 0x20;
  add r5, r5, r0;
  stw r3, 4(r5);
  lwz r0, -0x64e4(r13);
  lwz r3, -0x64cc(r13);
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r4, 8(r3);
  li r4, 0xe4;
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80166000;
  mr r4, r3;
  addi r3, r31, 0x898;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166004;
lbl_80166000:
  li r3, 1;
lbl_80166004:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowReportKey
// PAL: 0x8016601c..0x801661b0
MARK_BINARY_BLOB(DVDLowReportKey, 0x8016601c, 0x801661b0);
asm UNKNOWN_FUNCTION(DVDLowReportKey) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r9, 0x8034;
  li r12, 1;
  stw r0, 0x14(r1);
  addi r9, r9, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r11, -0x64e0(r13);
  stb r12, -0x64e8(r13);
  slwi r10, r11, 5;
  add r8, r9, r10;
  lbz r7, 8(r8);
  neg r0, r7;
  or r0, r0, r7;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_8016608c;
  mr r4, r11;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80166088:
  b lbl_80166088;
lbl_8016608c:
  lwz r7, 0xc(r8);
  addis r0, r7, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_801660ac;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_801660a8:
  b lbl_801660a8;
lbl_801660ac:
  stwx r6, r9, r10;
  addi r0, r11, 1;
  cmpwi r0, 4;
  stw r12, 4(r8);
  stb r12, 8(r8);
  stw r0, -0x64e0(r13);
  blt lbl_801660d0;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_801660d0:
  lwz r6, -0x64e4(r13);
  lis r7, 0x8034;
  slwi r8, r11, 5;
  addi r0, r6, 1;
  addi r7, r7, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r7, r8;
  blt lbl_801660fc;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_801660fc:
  lwz r6, -0x64cc(r13);
  srwi r11, r4, 0x10;
  slwi r0, r0, 5;
  li r4, 0xa4;
  stbx r4, r6, r0;
  mr r7, r3;
  lis r9, 0x8016;
  mr r10, r30;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r3, -0x64cc(r13);
  li r4, 0xa4;
  slwi r0, r0, 5;
  li r6, 0x20;
  add r3, r3, r0;
  li r8, 0x20;
  stw r11, 4(r3);
  lwz r0, -0x64e4(r13);
  lwz r3, -0x64cc(r13);
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r5, 8(r3);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80166194;
  mr r4, r3;
  addi r3, r31, 0xa98;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166198;
lbl_80166194:
  li r3, 1;
lbl_80166198:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowSetMaximumRotation
// PAL: 0x801661b0..0x80166330
MARK_BINARY_BLOB(DVDLowSetMaximumRotation, 0x801661b0, 0x80166330);
asm UNKNOWN_FUNCTION(DVDLowSetMaximumRotation) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8034;
  li r10, 1;
  stw r0, 0x14(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r9, -0x64e0(r13);
  stb r10, -0x64e8(r13);
  slwi r8, r9, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80166220;
  mr r4, r9;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_8016621c:
  b lbl_8016621c;
lbl_80166220:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80166240;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_8016623c:
  b lbl_8016623c;
lbl_80166240:
  stwx r4, r7, r8;
  addi r0, r9, 1;
  cmpwi r0, 4;
  stw r10, 4(r6);
  stb r10, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80166264;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80166264:
  lwz r4, -0x64e4(r13);
  lis r5, 0x8034;
  slwi r6, r9, 5;
  addi r0, r4, 1;
  addi r5, r5, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r5, r6;
  blt lbl_80166290;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80166290:
  lwz r4, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r5, 0xdd;
  stbx r5, r4, r0;
  rlwinm r5, r3, 0x10, 0x1e, 0x1f;
  mr r10, r30;
  addi r9, r9, 0x4684;
  lwz r0, -0x64e4(r13);
  li r4, 0xdd;
  lwz r3, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  li r7, 0;
  add r3, r3, r0;
  li r8, 0;
  stw r5, 4(r3);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80166314;
  mr r4, r3;
  addi r3, r31, 0xc4c;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166318;
lbl_80166314:
  li r3, 1;
lbl_80166318:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowRead
// PAL: 0x80166330..0x801664e0
MARK_BINARY_BLOB(DVDLowRead, 0x80166330, 0x801664e0);
asm UNKNOWN_FUNCTION(DVDLowRead) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  clrlwi. r0, r3, 0x1b;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  beq lbl_80166368;
  addi r3, r31, 0xc8c;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_801664c8;
lbl_80166368:
  lwz r11, -0x64e0(r13);
  lis r9, 0x8034;
  li r12, 1;
  slwi r10, r11, 5;
  addi r9, r9, 0x34e0;
  add r8, r9, r10;
  stb r12, -0x64e8(r13);
  lbz r7, 8(r8);
  neg r0, r7;
  or r0, r0, r7;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_801663bc;
  mr r4, r11;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_801663b8:
  b lbl_801663b8;
lbl_801663bc:
  lwz r7, 0xc(r8);
  addis r0, r7, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_801663dc;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_801663d8:
  b lbl_801663d8;
lbl_801663dc:
  stwx r6, r9, r10;
  addi r0, r11, 1;
  cmpwi r0, 4;
  stw r12, 4(r8);
  stb r12, 8(r8);
  stw r0, -0x64e0(r13);
  blt lbl_80166400;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80166400:
  lwz r6, -0x64e4(r13);
  lis r7, 0x8034;
  stw r4, -0x64d4(r13);
  slwi r8, r11, 5;
  addi r0, r6, 1;
  addi r7, r7, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r7, r8;
  blt lbl_80166430;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80166430:
  lwz r6, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r7, 0x71;
  stbx r7, r6, r0;
  mr r7, r3;
  mr r8, r4;
  mr r10, r30;
  lwz r0, -0x64e4(r13);
  addi r9, r9, 0x4684;
  lwz r3, -0x64cc(r13);
  li r6, 0x20;
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r4, 4(r3);
  li r4, 0x71;
  lwz r0, -0x64e4(r13);
  lwz r3, -0x64cc(r13);
  slwi r0, r0, 5;
  add r3, r3, r0;
  stw r5, 8(r3);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_801664c4;
  mr r4, r3;
  addi r3, r31, 0xccc;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_801664c8;
lbl_801664c4:
  li r3, 1;
lbl_801664c8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowSeek
// PAL: 0x801664e0..0x8016665c
MARK_BINARY_BLOB(DVDLowSeek, 0x801664e0, 0x8016665c);
asm UNKNOWN_FUNCTION(DVDLowSeek) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8034;
  li r10, 1;
  stw r0, 0x14(r1);
  addi r7, r7, 0x34e0;
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r9, -0x64e0(r13);
  stb r10, -0x64e8(r13);
  slwi r8, r9, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80166550;
  mr r4, r9;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_8016654c:
  b lbl_8016654c;
lbl_80166550:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80166570;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_8016656c:
  b lbl_8016656c;
lbl_80166570:
  stwx r4, r7, r8;
  addi r0, r9, 1;
  cmpwi r0, 4;
  stw r10, 4(r6);
  stb r10, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80166594;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80166594:
  lwz r4, -0x64e4(r13);
  lis r5, 0x8034;
  slwi r6, r9, 5;
  addi r0, r4, 1;
  addi r5, r5, 0x34e0;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  add r30, r5, r6;
  blt lbl_801665c0;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_801665c0:
  lwz r4, -0x64cc(r13);
  lis r9, 0x8016;
  slwi r0, r0, 5;
  li r5, 0xab;
  stbx r5, r4, r0;
  mr r10, r30;
  addi r9, r9, 0x4684;
  li r4, 0xab;
  lwz r0, -0x64e4(r13);
  li r6, 0x20;
  lwz r5, -0x64cc(r13);
  li r7, 0;
  slwi r0, r0, 5;
  li r8, 0;
  add r5, r5, r0;
  stw r3, 4(r5);
  lwz r0, -0x64e4(r13);
  lwz r5, -0x64cc(r13);
  slwi r0, r0, 5;
  lwz r3, -0x7318(r13);
  add r5, r5, r0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80166640;
  mr r4, r3;
  addi r3, r31, 0xd00;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166644;
lbl_80166640:
  li r3, 1;
lbl_80166644:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowGetCoverRegister
// PAL: 0x8016665c..0x8016666c
MARK_BINARY_BLOB(DVDLowGetCoverRegister, 0x8016665c, 0x8016666c);
asm UNKNOWN_FUNCTION(DVDLowGetCoverRegister) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  addi r3, r3, 0x3560;
  lwz r3, 4(r3);
  blr;
  // clang-format on
}

// Symbol: DVDLowGetStatusRegister
// PAL: 0x8016666c..0x80166678
MARK_BINARY_BLOB(DVDLowGetStatusRegister, 0x8016666c, 0x80166678);
asm UNKNOWN_FUNCTION(DVDLowGetStatusRegister) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  lwz r3, 0x3660(r3);
  blr;
  // clang-format on
}

// Symbol: DVDLowPrepareCoverRegister
// PAL: 0x80166678..0x801667e0
MARK_BINARY_BLOB(DVDLowPrepareCoverRegister, 0x80166678, 0x801667e0);
asm UNKNOWN_FUNCTION(DVDLowPrepareCoverRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e4(r13);
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  blt lbl_801666b0;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_801666b0:
  lwz r4, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r5, 0x7a;
  stbx r5, r4, r0;
  li r9, 1;
  addi r7, r7, 0x34e0;
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80166710;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_8016670c:
  b lbl_8016670c;
lbl_80166710:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80166730;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_8016672c:
  b lbl_8016672c;
lbl_80166730:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80166754;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80166754:
  lwz r0, -0x64e4(r13);
  lis r3, 0x8034;
  slwi r5, r4, 5;
  lwz r4, -0x64cc(r13);
  addi r3, r3, 0x34e0;
  lis r7, 0x8034;
  add r30, r3, r5;
  slwi r0, r0, 5;
  lis r9, 0x8016;
  lwz r3, -0x7318(r13);
  add r5, r4, r0;
  mr r10, r30;
  addi r7, r7, 0x3580;
  addi r9, r9, 0x473c;
  li r4, 0x7a;
  li r6, 0x20;
  li r8, 0x20;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_801667c4;
  mr r4, r3;
  addi r3, r31, 0xdb0;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_801667c8;
lbl_801667c4:
  li r3, 1;
lbl_801667c8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowPrepareStatusRegister
// PAL: 0x801667e0..0x80166948
MARK_BINARY_BLOB(DVDLowPrepareStatusRegister, 0x801667e0, 0x80166948);
asm UNKNOWN_FUNCTION(DVDLowPrepareStatusRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e4(r13);
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  blt lbl_80166818;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_80166818:
  lwz r4, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r5, 0x95;
  stbx r5, r4, r0;
  li r9, 1;
  addi r7, r7, 0x34e0;
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_80166878;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_80166874:
  b lbl_80166874;
lbl_80166878:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80166898;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80166894:
  b lbl_80166894;
lbl_80166898:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_801668bc;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_801668bc:
  lwz r0, -0x64e4(r13);
  lis r3, 0x8034;
  slwi r5, r4, 5;
  lwz r4, -0x64cc(r13);
  addi r3, r3, 0x34e0;
  lis r7, 0x8034;
  add r30, r3, r5;
  slwi r0, r0, 5;
  lis r9, 0x8016;
  lwz r3, -0x7318(r13);
  add r5, r4, r0;
  mr r10, r30;
  addi r7, r7, 0x3660;
  addi r9, r9, 0x4684;
  li r4, 0x95;
  li r6, 0x20;
  li r8, 0x20;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_8016692c;
  mr r4, r3;
  addi r3, r31, 0xdf4;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166930;
lbl_8016692c:
  li r3, 1;
lbl_80166930:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDLowGetImmBufferReg
// PAL: 0x80166948..0x80166954
MARK_BINARY_BLOB(DVDLowGetImmBufferReg, 0x80166948, 0x80166954);
asm UNKNOWN_FUNCTION(DVDLowGetImmBufferReg) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  lwz r3, 0x3560(r3);
  blr;
  // clang-format on
}

// Symbol: DVDLowUnmaskStatusInterrupts
// PAL: 0x80166954..0x8016695c
MARK_BINARY_BLOB(DVDLowUnmaskStatusInterrupts, 0x80166954, 0x8016695c);
asm UNKNOWN_FUNCTION(DVDLowUnmaskStatusInterrupts) {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: DVDLowMaskCoverInterrupt
// PAL: 0x8016695c..0x80166964
MARK_BINARY_BLOB(DVDLowMaskCoverInterrupt, 0x8016695c, 0x80166964);
asm UNKNOWN_FUNCTION(DVDLowMaskCoverInterrupt) {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: DVDLowClearCoverInterrupt
// PAL: 0x80166964..0x80166ac8
MARK_BINARY_BLOB(DVDLowClearCoverInterrupt, 0x80166964, 0x80166ac8);
asm UNKNOWN_FUNCTION(DVDLowClearCoverInterrupt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -29232;
  stw r30, 8(r1);
  lwz r4, -0x64e4(r13);
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r0, -0x64e4(r13);
  blt lbl_8016699c;
  li r0, 0;
  stw r0, -0x64e4(r13);
lbl_8016699c:
  lwz r4, -0x64cc(r13);
  lis r7, 0x8034;
  slwi r0, r0, 5;
  li r5, 0x86;
  stbx r5, r4, r0;
  li r9, 1;
  addi r7, r7, 0x34e0;
  lwz r4, -0x64e0(r13);
  stb r9, -0x64e8(r13);
  slwi r8, r4, 5;
  add r6, r7, r8;
  lbz r5, 8(r6);
  neg r0, r5;
  or r0, r0, r5;
  srwi r0, r0, 0x1f;
  cmplwi r0, 1;
  bne lbl_801669fc;
  addi r3, r31, 0x240;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0x278;
  crclr 6;
  bl OSReport;
lbl_801669f8:
  b lbl_801669f8;
lbl_801669fc:
  lwz r5, 0xc(r6);
  addis r0, r5, 0x115;
  cmplwi r0, 0xdaed;
  beq lbl_80166a1c;
  addi r3, r31, 0x2a8;
  crclr 6;
  bl OSReport;
lbl_80166a18:
  b lbl_80166a18;
lbl_80166a1c:
  stwx r3, r7, r8;
  addi r0, r4, 1;
  cmpwi r0, 4;
  stw r9, 4(r6);
  stb r9, 8(r6);
  stw r0, -0x64e0(r13);
  blt lbl_80166a40;
  li r0, 0;
  stw r0, -0x64e0(r13);
lbl_80166a40:
  lwz r0, -0x64e4(r13);
  lis r3, 0x8034;
  slwi r5, r4, 5;
  lwz r4, -0x64cc(r13);
  addi r3, r3, 0x34e0;
  lis r9, 0x8016;
  add r30, r3, r5;
  slwi r0, r0, 5;
  add r5, r4, r0;
  lwz r3, -0x7318(r13);
  mr r10, r30;
  addi r9, r9, 0x4684;
  li r4, 0x86;
  li r6, 0x20;
  li r7, 0;
  li r8, 0;
  bl IOS_IoctlAsync;
  cmpwi r3, 0;
  beq lbl_80166aac;
  mr r4, r3;
  addi r3, r31, 0xe3c;
  crclr 6;
  bl OSReport;
  li r0, 0;
  li r3, 0;
  stb r0, 8(r30);
  b lbl_80166ab0;
lbl_80166aac:
  li r3, 1;
lbl_80166ab0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDLowTestAlarm
// PAL: 0x80166ac8..0x80166ad0
MARK_BINARY_BLOB(__DVDLowTestAlarm, 0x80166ac8, 0x80166ad0);
asm UNKNOWN_FUNCTION(__DVDLowTestAlarm) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}
