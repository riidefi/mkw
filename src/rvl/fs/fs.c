#include "fs.h"

#include <string.h>

#include <rvl/ipc/ipcclt.h>
#include <rvl/os/osError.h>

// Extern function references.
// PAL: 0x80193030
extern UNKNOWN_FUNCTION(IPCGetBufferHi);
// PAL: 0x80193038
extern UNKNOWN_FUNCTION(IPCGetBufferLo);
// PAL: 0x80193040
extern UNKNOWN_FUNCTION(IPCSetBufferLo);
// PAL: 0x80193048
extern UNKNOWN_FUNCTION(strnlen);
// PAL: 0x80193a18
extern UNKNOWN_FUNCTION(IOS_CloseAsync);
// PAL: 0x80193b80
extern UNKNOWN_FUNCTION(IOS_ReadAsync);
// PAL: 0x80193c80
extern UNKNOWN_FUNCTION(IOS_Read);
// PAL: 0x80193d88
extern UNKNOWN_FUNCTION(IOS_WriteAsync);
// PAL: 0x80193e88
extern UNKNOWN_FUNCTION(IOS_Write);
// PAL: 0x80193f90
extern UNKNOWN_FUNCTION(IOS_SeekAsync);
// PAL: 0x80194070
extern UNKNOWN_FUNCTION(IOS_Seek);
// PAL: 0x80194158
extern UNKNOWN_FUNCTION(IOS_IoctlAsync);
// PAL: 0x801944fc
extern UNKNOWN_FUNCTION(IOS_IoctlvAsync);
// PAL: 0x801945e0
extern UNKNOWN_FUNCTION(IOS_Ioctlv);
// PAL: 0x801949b8
extern UNKNOWN_FUNCTION(iosCreateHeap);
// PAL: 0x80194cec
extern UNKNOWN_FUNCTION(iosAllocAligned);
// PAL: 0x80194cf0
extern UNKNOWN_FUNCTION(iosFree);

u32 _unk_80385920 = 0xFFFFFFFF;
char _unk_80385928[] = "/dev/fs";
u32 _unk_80386784;
u32 _unk_80386780;
u32 _unk_8038677c;
u32 _unk_80386778;
u32 _unk_80386774;
u32 _unk_80386770;

// Symbol: ISFS_OpenLib
// PAL: 0x80169bcc..0x80169cf4
MARK_BINARY_BLOB(ISFS_OpenLib, 0x80169bcc, 0x80169cf4);
asm UNKNOWN_FUNCTION(ISFS_OpenLib) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  lwz r0, _unk_80386770;
  cmpwi r0, 0;
  bne lbl_80169c00;
  bl IPCGetBufferLo;
  stw r3, _unk_8038677c;
  bl IPCGetBufferHi;
  stw r3, _unk_80386780;
lbl_80169c00:
  lwz r3, _unk_8038677c;
  lwz r0, _unk_80386770;
  addi r3, r3, 0x1f;
  rlwinm r3, r3, 0, 0, 0x1a;
  cmpwi r0, 0;
  stw r3, _unk_80386774;
  bne lbl_80169c44;
  lwz r0, _unk_80386780;
  addi r4, r3, 0x40;
  cmplw r4, r0;
  ble lbl_80169c44;
  lis r3, 0x8029;
  addi r3, r3, -25312;
  crclr 6;
  bl OSReport;
  li r31, -22;
  b lbl_80169cd8;
lbl_80169c44:
  la r4, _unk_80385928;
  bl strcpy;
  lwz r3, _unk_80386774;
  li r4, 0;
  bl IOS_Open;
  cmpwi r3, 0;
  stw r3, _unk_80385920;
  bge lbl_80169c6c;
  mr r31, r3;
  b lbl_80169cd8;
lbl_80169c6c:
  lwz r4, _unk_80386770;
  lwz r30, _unk_80386774;
  cmpwi r4, 0;
  bne lbl_80169ca4;
  lwz r0, _unk_80386780;
  addi r3, r30, 0x1540;
  cmplw r3, r0;
  ble lbl_80169ca4;
  lis r3, 0x8029;
  addi r3, r3, -25312;
  crclr 6;
  bl OSReport;
  li r31, -22;
  b lbl_80169cd8;
lbl_80169ca4:
  cmpwi r4, 0;
  bne lbl_80169cbc;
  addi r3, r30, 0x1540;
  bl IPCSetBufferLo;
  li r0, 1;
  stw r0, _unk_80386770;
lbl_80169cbc:
  mr r3, r30;
  li r4, 0x1540;
  bl iosCreateHeap;
  cmpwi r3, 0;
  stw r3, _unk_80386784;
  bge lbl_80169cd8;
  li r31, -22;
lbl_80169cd8:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: _isfsFuncCb
// PAL: 0x80169cf4..0x80169e74
MARK_BINARY_BLOB(_isfsFuncCb, 0x80169cf4, 0x80169e74);
asm UNKNOWN_FUNCTION(_isfsFuncCb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi cr1, r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  blt cr1, lbl_80169e20;
  lwz r0, 0x108(r4);
  cmpwi r0, 3;
  beq lbl_80169d80;
  bge lbl_80169d38;
  cmpwi r0, 1;
  beq lbl_80169d48;
  bge lbl_80169d5c;
  b lbl_80169e20;
lbl_80169d38:
  cmpwi r0, 5;
  beq lbl_80169e10;
  bge lbl_80169e20;
  b lbl_80169dd8;
lbl_80169d48:
  bne cr1, lbl_80169e20;
  lwz r3, 0x10c(r4);
  li r5, 0x1c;
  bl memcpy;
  b lbl_80169e20;
lbl_80169d5c:
  bne cr1, lbl_80169e20;
  addi r0, r4, 0x3f;
  lwz r3, 0x10c(r4);
  rlwinm r4, r0, 0, 0, 0x1a;
  addi r0, r4, 0x5f;
  rlwinm r4, r0, 0, 0, 0x1a;
  lwz r0, 0(r4);
  stw r0, 0(r3);
  b lbl_80169e20;
lbl_80169d80:
  bne cr1, lbl_80169e20;
  addi r0, r4, 0x5f;
  lwz r3, 0x10c(r4);
  rlwinm r5, r0, 0, 0, 0x1a;
  lwz r0, 0(r5);
  stw r0, 0(r3);
  lhz r0, 4(r5);
  lwz r3, 0x110(r4);
  sth r0, 0(r3);
  lbz r0, 0x49(r5);
  lwz r3, 0x114(r4);
  stw r0, 0(r3);
  lbz r0, 0x46(r5);
  lwz r3, 0x118(r4);
  stw r0, 0(r3);
  lbz r0, 0x47(r5);
  lwz r3, 0x11c(r4);
  stw r0, 0(r3);
  lbz r0, 0x48(r5);
  lwz r3, 0x120(r4);
  stw r0, 0(r3);
  b lbl_80169e20;
lbl_80169dd8:
  bne cr1, lbl_80169e20;
  addi r0, r4, 0x3f;
  lwz r3, 0x10c(r4);
  rlwinm r5, r0, 0, 0, 0x1a;
  addi r0, r5, 0x5f;
  rlwinm r6, r0, 0, 0, 0x1a;
  lwz r5, 0(r6);
  addi r0, r6, 0x23;
  rlwinm r6, r0, 0, 0, 0x1a;
  stw r5, 0(r3);
  lwz r0, 0(r6);
  lwz r3, 0x110(r4);
  stw r0, 0(r3);
  b lbl_80169e20;
lbl_80169e10:
  bne cr1, lbl_80169e20;
  lwz r3, 0x10c(r4);
  li r5, 8;
  bl memcpy;
lbl_80169e20:
  li r0, 0;
  stw r0, _unk_80386778;
  lwz r12, 0x100(r31);
  cmpwi r12, 0;
  beq lbl_80169e44;
  mr r3, r30;
  lwz r4, 0x104(r31);
  mtctr r12;
  bctrl;
lbl_80169e44:
  cmpwi r31, 0;
  beq lbl_80169e58;
  lwz r3, _unk_80386784;
  mr r4, r31;
  bl iosFree;
lbl_80169e58:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ISFS_CreateDir
// PAL: 0x80169e74..0x80169f68
MARK_BINARY_BLOB(ISFS_CreateDir, 0x80169e74, 0x80169f68);
asm UNKNOWN_FUNCTION(ISFS_CreateDir) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r3, 0;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  li r30, 0;
  beq lbl_80169ec8;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_80169ec8;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_80169ed0;
lbl_80169ec8:
  li r31, -101;
  b lbl_80169f34;
lbl_80169ed0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80169ef4;
  li r31, -22;
  b lbl_80169f34;
lbl_80169ef4:
  mr r4, r25;
  addi r5, r31, 1;
  addi r3, r3, 6;
  bl memcpy;
  stb r26, 0x49(r30);
  mr r5, r30;
  li r4, 3;
  li r6, 0x4c;
  stb r27, 0x46(r30);
  li r7, 0;
  li r8, 0;
  stb r28, 0x47(r30);
  stb r29, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_Ioctl;
  mr r31, r3;
lbl_80169f34:
  cmpwi r30, 0;
  beq lbl_80169f4c;
  beq lbl_80169f4c;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_80169f4c:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_CreateDirAsync
// PAL: 0x80169f68..0x8016a05c
MARK_BINARY_BLOB(ISFS_CreateDirAsync, 0x80169f68, 0x8016a05c);
asm UNKNOWN_FUNCTION(ISFS_CreateDirAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  cmpwi r3, 0;
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  beq lbl_80169fc0;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_80169fc0;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_80169fc8;
lbl_80169fc0:
  li r3, -101;
  b lbl_8016a044;
lbl_80169fc8:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80169fec;
  li r3, -118;
  b lbl_8016a044;
lbl_80169fec:
  stw r28, 0x100(r3);
  li r0, 0;
  mr r4, r23;
  addi r5, r31, 1;
  stw r29, 0x104(r3);
  stw r0, 0x108(r3);
  addi r3, r3, 6;
  bl memcpy;
  stb r24, 0x49(r30);
  lis r9, 0x8017;
  mr r5, r30;
  mr r10, r30;
  stb r25, 0x46(r30);
  addi r9, r9, -25356;
  li r4, 3;
  li r6, 0x4c;
  stb r26, 0x47(r30);
  li r7, 0;
  li r8, 0;
  stb r27, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_IoctlAsync;
lbl_8016a044:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_ReadDir
// PAL: 0x8016a05c..0x8016a1b0
MARK_BINARY_BLOB(ISFS_ReadDir, 0x8016a05c, 0x8016a1b0);
asm UNKNOWN_FUNCTION(ISFS_ReadDir) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  li r29, 0;
  beq lbl_8016a0b8;
  cmpwi r5, 0;
  beq lbl_8016a0b8;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a0b8;
  clrlwi. r0, r4, 0x1b;
  bne lbl_8016a0b8;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a0c0;
lbl_8016a0b8:
  li r31, -101;
  b lbl_8016a17c;
lbl_8016a0c0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8016a0e4;
  li r31, -22;
  b lbl_8016a17c;
lbl_8016a0e4:
  addi r0, r3, 0x3f;
  mr r4, r26;
  rlwinm r30, r0, 0, 0, 0x1a;
  addi r5, r31, 1;
  mr r3, r30;
  bl memcpy;
  stw r30, 0(r29);
  li r3, 0x40;
  addi r0, r30, 0x5f;
  cmpwi r27, 0;
  stw r3, 4(r29);
  rlwinm r30, r0, 0, 0, 0x1a;
  li r3, 4;
  stw r30, 8(r29);
  stw r3, 0xc(r29);
  beq lbl_8016a150;
  lwz r0, 0(r28);
  li r5, 2;
  li r6, 2;
  stw r0, 0(r30);
  stw r27, 0x10(r29);
  lwz r0, 0(r28);
  mulli r0, r0, 0xd;
  stw r0, 0x14(r29);
  stw r30, 0x18(r29);
  stw r3, 0x1c(r29);
  b lbl_8016a158;
lbl_8016a150:
  li r5, 1;
  li r6, 1;
lbl_8016a158:
  lwz r3, _unk_80385920;
  mr r7, r29;
  li r4, 4;
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8016a17c;
  lwz r0, 0(r30);
  stw r0, 0(r28);
lbl_8016a17c:
  cmpwi r29, 0;
  beq lbl_8016a194;
  beq lbl_8016a194;
  lwz r3, _unk_80386784;
  mr r4, r29;
  bl iosFree;
lbl_8016a194:
  addi r11, r1, 0x20;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_ReadDirAsync
// PAL: 0x8016a1b0..0x8016a2f8
MARK_BINARY_BLOB(ISFS_ReadDirAsync, 0x8016a1b0, 0x8016a2f8);
asm UNKNOWN_FUNCTION(ISFS_ReadDirAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r3, 0;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  beq lbl_8016a210;
  cmpwi r5, 0;
  beq lbl_8016a210;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a210;
  clrlwi. r0, r4, 0x1b;
  bne lbl_8016a210;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a218;
lbl_8016a210:
  li r3, -101;
  b lbl_8016a2e0;
lbl_8016a218:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a23c;
  li r3, -118;
  b lbl_8016a2e0;
lbl_8016a23c:
  stw r28, 0x100(r3);
  li r6, 2;
  addi r0, r3, 0x3f;
  mr r4, r25;
  stw r29, 0x104(r3);
  rlwinm r29, r0, 0, 0, 0x1a;
  addi r5, r31, 1;
  stw r6, 0x108(r3);
  stw r27, 0x10c(r3);
  mr r3, r29;
  bl memcpy;
  stw r29, 0(r30);
  li r3, 0x40;
  addi r0, r29, 0x5f;
  cmpwi r26, 0;
  stw r3, 4(r30);
  rlwinm r4, r0, 0, 0, 0x1a;
  li r3, 4;
  stw r4, 8(r30);
  stw r3, 0xc(r30);
  beq lbl_8016a2bc;
  lwz r0, 0(r27);
  li r5, 2;
  li r6, 2;
  stw r0, 0(r4);
  stw r26, 0x10(r30);
  lwz r0, 0(r27);
  mulli r0, r0, 0xd;
  stw r0, 0x14(r30);
  stw r4, 0x18(r30);
  stw r3, 0x1c(r30);
  b lbl_8016a2c4;
lbl_8016a2bc:
  li r5, 1;
  li r6, 1;
lbl_8016a2c4:
  lis r8, 0x8017;
  lwz r3, _unk_80385920;
  mr r7, r30;
  mr r9, r30;
  addi r8, r8, -25356;
  li r4, 4;
  bl IOS_IoctlvAsync;
lbl_8016a2e0:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_SetAttr
// PAL: 0x8016a2f8..0x8016a3fc
MARK_BINARY_BLOB(ISFS_SetAttr, 0x8016a2f8, 0x8016a3fc);
asm UNKNOWN_FUNCTION(ISFS_SetAttr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  cmpwi r3, 0;
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  li r30, 0;
  beq lbl_8016a354;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a354;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a35c;
lbl_8016a354:
  li r31, -101;
  b lbl_8016a3c8;
lbl_8016a35c:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a380;
  li r31, -22;
  b lbl_8016a3c8;
lbl_8016a380:
  mr r4, r23;
  addi r5, r31, 1;
  addi r3, r3, 6;
  bl memcpy;
  stw r24, 0(r30);
  mr r5, r30;
  li r4, 5;
  li r6, 0x4c;
  sth r25, 4(r30);
  li r7, 0;
  li r8, 0;
  stb r26, 0x49(r30);
  stb r27, 0x46(r30);
  stb r28, 0x47(r30);
  stb r29, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_Ioctl;
  mr r31, r3;
lbl_8016a3c8:
  cmpwi r30, 0;
  beq lbl_8016a3e0;
  beq lbl_8016a3e0;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_8016a3e0:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_SetAttrAsync
// PAL: 0x8016a3fc..0x8016a500
MARK_BINARY_BLOB(ISFS_SetAttrAsync, 0x8016a3fc, 0x8016a500);
asm UNKNOWN_FUNCTION(ISFS_SetAttrAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_21;
  cmpwi r3, 0;
  lwz r29, 0x48(r1);
  mr r21, r3;
  mr r22, r4;
  mr r23, r5;
  mr r24, r6;
  mr r25, r7;
  mr r26, r8;
  mr r27, r9;
  mr r28, r10;
  beq lbl_8016a45c;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a45c;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a464;
lbl_8016a45c:
  li r3, -101;
  b lbl_8016a4e8;
lbl_8016a464:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a488;
  li r3, -118;
  b lbl_8016a4e8;
lbl_8016a488:
  stw r28, 0x100(r3);
  li r0, 0;
  mr r4, r21;
  addi r5, r31, 1;
  stw r29, 0x104(r3);
  stw r0, 0x108(r3);
  addi r3, r3, 6;
  bl memcpy;
  stw r22, 0(r30);
  lis r9, 0x8017;
  mr r5, r30;
  mr r10, r30;
  sth r23, 4(r30);
  addi r9, r9, -25356;
  li r4, 5;
  li r6, 0x4c;
  stb r24, 0x49(r30);
  li r7, 0;
  li r8, 0;
  stb r25, 0x46(r30);
  stb r26, 0x47(r30);
  stb r27, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_IoctlAsync;
lbl_8016a4e8:
  addi r11, r1, 0x40;
  bl _restgpr_21;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: ISFS_GetAttr
// PAL: 0x8016a500..0x8016a658
MARK_BINARY_BLOB(ISFS_GetAttr, 0x8016a500, 0x8016a658);
asm UNKNOWN_FUNCTION(ISFS_GetAttr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  cmpwi r3, 0;
  mr r30, r3;
  mr r23, r4;
  mr r24, r5;
  mr r25, r6;
  mr r26, r7;
  mr r27, r8;
  mr r28, r9;
  li r29, 0;
  beq lbl_8016a58c;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a58c;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  beq lbl_8016a58c;
  cmpwi r23, 0;
  beq lbl_8016a58c;
  cmpwi r24, 0;
  beq lbl_8016a58c;
  cmpwi r25, 0;
  beq lbl_8016a58c;
  cmpwi r26, 0;
  beq lbl_8016a58c;
  cmpwi r27, 0;
  beq lbl_8016a58c;
  cmpwi r28, 0;
  bne lbl_8016a594;
lbl_8016a58c:
  li r31, -101;
  b lbl_8016a624;
lbl_8016a594:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8016a5b8;
  li r31, -22;
  b lbl_8016a624;
lbl_8016a5b8:
  mr r4, r30;
  addi r5, r31, 1;
  bl memcpy;
  addi r0, r29, 0x5f;
  lwz r3, _unk_80385920;
  rlwinm r30, r0, 0, 0, 0x1a;
  mr r5, r29;
  mr r7, r30;
  li r4, 6;
  li r6, 0x40;
  li r8, 0x4c;
  bl IOS_Ioctl;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8016a624;
  lwz r0, 0(r30);
  stw r0, 0(r23);
  lhz r0, 4(r30);
  sth r0, 0(r24);
  lbz r0, 0x49(r30);
  stw r0, 0(r25);
  lbz r0, 0x46(r30);
  stw r0, 0(r26);
  lbz r0, 0x47(r30);
  stw r0, 0(r27);
  lbz r0, 0x48(r30);
  stw r0, 0(r28);
lbl_8016a624:
  cmpwi r29, 0;
  beq lbl_8016a63c;
  beq lbl_8016a63c;
  lwz r3, _unk_80386784;
  mr r4, r29;
  bl iosFree;
lbl_8016a63c:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_GetAttrAsync
// PAL: 0x8016a658..0x8016a78c
MARK_BINARY_BLOB(ISFS_GetAttrAsync, 0x8016a658, 0x8016a78c);
asm UNKNOWN_FUNCTION(ISFS_GetAttrAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_21;
  cmpwi r3, 0;
  lwz r29, 0x48(r1);
  mr r21, r3;
  mr r22, r4;
  mr r23, r5;
  mr r24, r6;
  mr r25, r7;
  mr r26, r8;
  mr r27, r9;
  mr r28, r10;
  beq lbl_8016a6e8;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a6e8;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  beq lbl_8016a6e8;
  cmpwi r22, 0;
  beq lbl_8016a6e8;
  cmpwi r23, 0;
  beq lbl_8016a6e8;
  cmpwi r24, 0;
  beq lbl_8016a6e8;
  cmpwi r25, 0;
  beq lbl_8016a6e8;
  cmpwi r26, 0;
  beq lbl_8016a6e8;
  cmpwi r27, 0;
  bne lbl_8016a6f0;
lbl_8016a6e8:
  li r3, -101;
  b lbl_8016a774;
lbl_8016a6f0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a714;
  li r3, -118;
  b lbl_8016a774;
lbl_8016a714:
  stw r22, 0x10c(r3);
  li r0, 3;
  mr r4, r21;
  addi r5, r31, 1;
  stw r23, 0x110(r3);
  stw r24, 0x114(r3);
  stw r25, 0x118(r3);
  stw r26, 0x11c(r3);
  stw r27, 0x120(r3);
  stw r28, 0x100(r3);
  stw r29, 0x104(r3);
  stw r0, 0x108(r3);
  bl memcpy;
  addi r0, r30, 0x5f;
  lis r9, 0x8017;
  lwz r3, _unk_80385920;
  mr r5, r30;
  mr r10, r30;
  rlwinm r7, r0, 0, 0, 0x1a;
  addi r9, r9, -25356;
  li r4, 6;
  li r6, 0x40;
  li r8, 0x4c;
  bl IOS_IoctlAsync;
lbl_8016a774:
  addi r11, r1, 0x40;
  bl _restgpr_21;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: ISFS_Delete
// PAL: 0x8016a78c..0x8016a864
MARK_BINARY_BLOB(ISFS_Delete, 0x8016a78c, 0x8016a864);
asm UNKNOWN_FUNCTION(ISFS_Delete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
  beq lbl_8016a7d4;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a7d4;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a7dc;
lbl_8016a7d4:
  li r31, -101;
  b lbl_8016a82c;
lbl_8016a7dc:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a800;
  li r31, -22;
  b lbl_8016a82c;
lbl_8016a800:
  mr r4, r29;
  addi r5, r31, 1;
  bl memcpy;
  lwz r3, _unk_80385920;
  mr r5, r30;
  li r4, 7;
  li r6, 0x40;
  li r7, 0;
  li r8, 0;
  bl IOS_Ioctl;
  mr r31, r3;
lbl_8016a82c:
  cmpwi r30, 0;
  beq lbl_8016a844;
  beq lbl_8016a844;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_8016a844:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_DeleteAsync
// PAL: 0x8016a864..0x8016a934
MARK_BINARY_BLOB(ISFS_DeleteAsync, 0x8016a864, 0x8016a934);
asm UNKNOWN_FUNCTION(ISFS_DeleteAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  beq lbl_8016a8ac;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a8ac;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a8b4;
lbl_8016a8ac:
  li r3, -101;
  b lbl_8016a91c;
lbl_8016a8b4:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016a8d8;
  li r3, -118;
  b lbl_8016a91c;
lbl_8016a8d8:
  mr r4, r27;
  addi r5, r31, 1;
  bl memcpy;
  stw r28, 0x100(r30);
  lis r9, 0x8017;
  li r0, 0;
  mr r5, r30;
  stw r29, 0x104(r30);
  mr r10, r30;
  addi r9, r9, -25356;
  li r4, 7;
  stw r0, 0x108(r30);
  li r6, 0x40;
  li r7, 0;
  li r8, 0;
  lwz r3, _unk_80385920;
  bl IOS_IoctlAsync;
lbl_8016a91c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_Rename
// PAL: 0x8016a934..0x8016aa38
MARK_BINARY_BLOB(ISFS_Rename, 0x8016a934, 0x8016aa38);
asm UNKNOWN_FUNCTION(ISFS_Rename) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r27, r3;
  mr r28, r4;
  li r29, 0;
  beq lbl_8016a99c;
  cmpwi r4, 0;
  beq lbl_8016a99c;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016a99c;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r30, r3;
  beq lbl_8016a99c;
  mr r3, r28;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016a9a4;
lbl_8016a99c:
  li r30, -101;
  b lbl_8016aa04;
lbl_8016a9a4:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8016a9c8;
  li r30, -22;
  b lbl_8016aa04;
lbl_8016a9c8:
  mr r4, r27;
  addi r5, r30, 1;
  bl memcpy;
  mr r4, r28;
  addi r3, r29, 0x40;
  addi r5, r31, 1;
  bl memcpy;
  lwz r3, _unk_80385920;
  mr r5, r29;
  li r4, 8;
  li r6, 0x80;
  li r7, 0;
  li r8, 0;
  bl IOS_Ioctl;
  mr r30, r3;
lbl_8016aa04:
  cmpwi r29, 0;
  beq lbl_8016aa1c;
  beq lbl_8016aa1c;
  lwz r3, _unk_80386784;
  mr r4, r29;
  bl iosFree;
lbl_8016aa1c:
  addi r11, r1, 0x20;
  mr r3, r30;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_RenameAsync
// PAL: 0x8016aa38..0x8016ab3c
MARK_BINARY_BLOB(ISFS_RenameAsync, 0x8016aa38, 0x8016ab3c);
asm UNKNOWN_FUNCTION(ISFS_RenameAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r3, 0;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  beq lbl_8016aaa4;
  cmpwi r4, 0;
  beq lbl_8016aaa4;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016aaa4;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r30, r3;
  beq lbl_8016aaa4;
  mr r3, r26;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016aaac;
lbl_8016aaa4:
  li r3, -101;
  b lbl_8016ab24;
lbl_8016aaac:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8016aad0;
  li r3, -118;
  b lbl_8016ab24;
lbl_8016aad0:
  stw r27, 0x100(r3);
  li r0, 0;
  mr r4, r25;
  addi r5, r30, 1;
  stw r28, 0x104(r3);
  stw r0, 0x108(r3);
  bl memcpy;
  mr r4, r26;
  addi r3, r29, 0x40;
  addi r5, r31, 1;
  bl memcpy;
  lis r9, 0x8017;
  lwz r3, _unk_80385920;
  mr r5, r29;
  mr r10, r29;
  addi r9, r9, -25356;
  li r4, 8;
  li r6, 0x80;
  li r7, 0;
  li r8, 0;
  bl IOS_IoctlAsync;
lbl_8016ab24:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_GetUsage
// PAL: 0x8016ab3c..0x8016ac74
MARK_BINARY_BLOB(ISFS_GetUsage, 0x8016ab3c, 0x8016ac74);
asm UNKNOWN_FUNCTION(ISFS_GetUsage) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r30, r3;
  mr r26, r4;
  mr r27, r5;
  li r28, 0;
  beq lbl_8016ab98;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016ab98;
  cmpwi r4, 0;
  beq lbl_8016ab98;
  cmpwi r5, 0;
  beq lbl_8016ab98;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016aba0;
lbl_8016ab98:
  li r31, -101;
  b lbl_8016ac40;
lbl_8016aba0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r28, r3;
  bne lbl_8016abc4;
  li r31, -22;
  b lbl_8016ac40;
lbl_8016abc4:
  addi r0, r3, 0x37;
  mr r4, r30;
  rlwinm r29, r0, 0, 0, 0x1a;
  addi r5, r31, 1;
  mr r3, r29;
  bl memcpy;
  stw r29, 0(r28);
  li r4, 0x40;
  addi r3, r29, 0x5f;
  li r0, 4;
  stw r4, 4(r28);
  rlwinm r30, r3, 0, 0, 0x1a;
  addi r3, r30, 0x23;
  mr r7, r28;
  stw r30, 8(r28);
  rlwinm r29, r3, 0, 0, 0x1a;
  li r4, 0xc;
  li r5, 1;
  stw r0, 0xc(r28);
  li r6, 2;
  stw r29, 0x10(r28);
  stw r0, 0x14(r28);
  lwz r3, _unk_80385920;
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8016ac40;
  lwz r0, 0(r30);
  stw r0, 0(r26);
  lwz r0, 0(r29);
  stw r0, 0(r27);
lbl_8016ac40:
  cmpwi r28, 0;
  beq lbl_8016ac58;
  beq lbl_8016ac58;
  lwz r3, _unk_80386784;
  mr r4, r28;
  bl iosFree;
lbl_8016ac58:
  addi r11, r1, 0x20;
  mr r3, r31;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_CreateFile
// PAL: 0x8016ac74..0x8016ad68
MARK_BINARY_BLOB(ISFS_CreateFile, 0x8016ac74, 0x8016ad68);
asm UNKNOWN_FUNCTION(ISFS_CreateFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r3, 0;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  li r30, 0;
  beq lbl_8016acc8;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016acc8;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016acd0;
lbl_8016acc8:
  li r31, -101;
  b lbl_8016ad34;
lbl_8016acd0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016acf4;
  li r31, -22;
  b lbl_8016ad34;
lbl_8016acf4:
  mr r4, r25;
  addi r5, r31, 1;
  addi r3, r3, 6;
  bl memcpy;
  stb r26, 0x49(r30);
  mr r5, r30;
  li r4, 9;
  li r6, 0x4c;
  stb r27, 0x46(r30);
  li r7, 0;
  li r8, 0;
  stb r28, 0x47(r30);
  stb r29, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_Ioctl;
  mr r31, r3;
lbl_8016ad34:
  cmpwi r30, 0;
  beq lbl_8016ad4c;
  beq lbl_8016ad4c;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_8016ad4c:
  addi r11, r1, 0x30;
  mr r3, r31;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_CreateFileAsync
// PAL: 0x8016ad68..0x8016ae5c
MARK_BINARY_BLOB(ISFS_CreateFileAsync, 0x8016ad68, 0x8016ae5c);
asm UNKNOWN_FUNCTION(ISFS_CreateFileAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  cmpwi r3, 0;
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  beq lbl_8016adc0;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  blt lbl_8016adc0;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016adc8;
lbl_8016adc0:
  li r3, -101;
  b lbl_8016ae44;
lbl_8016adc8:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016adec;
  li r3, -118;
  b lbl_8016ae44;
lbl_8016adec:
  stw r28, 0x100(r3);
  li r0, 0;
  mr r4, r23;
  addi r5, r31, 1;
  stw r29, 0x104(r3);
  stw r0, 0x108(r3);
  addi r3, r3, 6;
  bl memcpy;
  stb r24, 0x49(r30);
  lis r9, 0x8017;
  mr r5, r30;
  mr r10, r30;
  stb r25, 0x46(r30);
  addi r9, r9, -25356;
  li r4, 9;
  li r6, 0x4c;
  stb r26, 0x47(r30);
  li r7, 0;
  li r8, 0;
  stb r27, 0x48(r30);
  lwz r3, _unk_80385920;
  bl IOS_IoctlAsync;
lbl_8016ae44:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: ISFS_Open
// PAL: 0x8016ae5c..0x8016af24
MARK_BINARY_BLOB(ISFS_Open, 0x8016ae5c, 0x8016af24);
asm UNKNOWN_FUNCTION(ISFS_Open) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  beq lbl_8016aea0;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016aea8;
lbl_8016aea0:
  li r31, -101;
  b lbl_8016aee8;
lbl_8016aea8:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016aecc;
  li r31, -22;
  b lbl_8016aee8;
lbl_8016aecc:
  mr r4, r28;
  addi r5, r31, 1;
  bl memcpy;
  mr r3, r30;
  mr r4, r29;
  bl IOS_Open;
  mr r31, r3;
lbl_8016aee8:
  cmpwi r30, 0;
  beq lbl_8016af00;
  beq lbl_8016af00;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_8016af00:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_OpenAsync
// PAL: 0x8016af24..0x8016afdc
MARK_BINARY_BLOB(ISFS_OpenAsync, 0x8016af24, 0x8016afdc);
asm UNKNOWN_FUNCTION(ISFS_OpenAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  beq lbl_8016af64;
  li r4, 0x40;
  bl strnlen;
  cmplwi r3, 0x40;
  mr r31, r3;
  bne lbl_8016af6c;
lbl_8016af64:
  li r3, -101;
  b lbl_8016afc4;
lbl_8016af6c:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016af90;
  li r3, -118;
  b lbl_8016afc4;
lbl_8016af90:
  stw r28, 0x100(r3);
  li r0, 0;
  mr r4, r26;
  addi r5, r31, 1;
  stw r29, 0x104(r3);
  stw r0, 0x108(r3);
  bl memcpy;
  lis r5, 0x8017;
  mr r3, r30;
  mr r4, r27;
  mr r6, r30;
  addi r5, r5, -25356;
  bl IOS_OpenAsync;
lbl_8016afc4:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_GetFileStats
// PAL: 0x8016afdc..0x8016b0ac
MARK_BINARY_BLOB(ISFS_GetFileStats, 0x8016afdc, 0x8016b0ac);
asm UNKNOWN_FUNCTION(ISFS_GetFileStats) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  beq lbl_8016b010;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b018;
lbl_8016b010:
  li r31, -101;
  b lbl_8016b074;
lbl_8016b018:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8016b03c;
  li r31, -22;
  b lbl_8016b074;
lbl_8016b03c:
  mr r3, r31;
  mr r7, r30;
  li r4, 0xb;
  li r5, 0;
  li r6, 0;
  li r8, 8;
  bl IOS_Ioctl;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8016b074;
  mr r3, r29;
  mr r4, r30;
  li r5, 8;
  bl memcpy;
lbl_8016b074:
  cmpwi r30, 0;
  beq lbl_8016b08c;
  beq lbl_8016b08c;
  lwz r3, _unk_80386784;
  mr r4, r30;
  bl iosFree;
lbl_8016b08c:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_GetFileStatsAsync
// PAL: 0x8016b0ac..0x8016b16c
MARK_BINARY_BLOB(ISFS_GetFileStatsAsync, 0x8016b0ac, 0x8016b16c);
asm UNKNOWN_FUNCTION(ISFS_GetFileStatsAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  beq lbl_8016b0e8;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b0f0;
lbl_8016b0e8:
  li r3, -101;
  b lbl_8016b14c;
lbl_8016b0f0:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  bne lbl_8016b110;
  li r3, -118;
  b lbl_8016b14c;
lbl_8016b110:
  stw r30, 0x100(r3);
  lis r9, 0x8017;
  li r0, 5;
  mr r7, r3;
  stw r31, 0x104(r3);
  mr r10, r3;
  addi r9, r9, -25356;
  li r4, 0xb;
  stw r0, 0x108(r3);
  li r5, 0;
  li r6, 0;
  li r8, 8;
  stw r29, 0x10c(r3);
  mr r3, r28;
  bl IOS_IoctlAsync;
lbl_8016b14c:
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

// Symbol: ISFS_Seek
// PAL: 0x8016b16c..0x8016b170
MARK_BINARY_BLOB(ISFS_Seek, 0x8016b16c, 0x8016b170);
asm UNKNOWN_FUNCTION(ISFS_Seek) {
  nofralloc;
  b IOS_Seek;
}

// Symbol: ISFS_SeekAsync
// PAL: 0x8016b170..0x8016b1fc
MARK_BINARY_BLOB(ISFS_SeekAsync, 0x8016b170, 0x8016b1fc);
asm UNKNOWN_FUNCTION(ISFS_SeekAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  lwz r3, _unk_80386784;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  bne lbl_8016b1b8;
  li r3, -118;
  b lbl_8016b1e4;
lbl_8016b1b8:
  stw r30, 0x100(r3);
  lis r6, 0x8017;
  li r0, 0;
  mr r4, r28;
  stw r31, 0x104(r3);
  mr r5, r29;
  mr r7, r3;
  addi r6, r6, -25356;
  stw r0, 0x108(r3);
  mr r3, r27;
  bl IOS_SeekAsync;
lbl_8016b1e4:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_Read
// PAL: 0x8016b1fc..0x8016b21c
MARK_BINARY_BLOB(ISFS_Read, 0x8016b1fc, 0x8016b21c);
asm UNKNOWN_FUNCTION(ISFS_Read) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_8016b20c;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b214;
lbl_8016b20c:
  li r3, -101;
  blr;
lbl_8016b214:
  b IOS_Read;
  blr;
  // clang-format on
}

// Symbol: ISFS_ReadAsync
// PAL: 0x8016b21c..0x8016b2c0
MARK_BINARY_BLOB(ISFS_ReadAsync, 0x8016b21c, 0x8016b2c0);
asm UNKNOWN_FUNCTION(ISFS_ReadAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r4, 0;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  beq lbl_8016b254;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b25c;
lbl_8016b254:
  li r3, -101;
  b lbl_8016b2a8;
lbl_8016b25c:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  bne lbl_8016b27c;
  li r3, -118;
  b lbl_8016b2a8;
lbl_8016b27c:
  stw r30, 0x100(r3);
  lis r6, 0x8017;
  li r0, 0;
  mr r4, r28;
  stw r31, 0x104(r3);
  mr r5, r29;
  mr r7, r3;
  addi r6, r6, -25356;
  stw r0, 0x108(r3);
  mr r3, r27;
  bl IOS_ReadAsync;
lbl_8016b2a8:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_Write
// PAL: 0x8016b2c0..0x8016b2e0
MARK_BINARY_BLOB(ISFS_Write, 0x8016b2c0, 0x8016b2e0);
asm UNKNOWN_FUNCTION(ISFS_Write) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_8016b2d0;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b2d8;
lbl_8016b2d0:
  li r3, -101;
  blr;
lbl_8016b2d8:
  b IOS_Write;
  blr;
  // clang-format on
}

// Symbol: ISFS_WriteAsync
// PAL: 0x8016b2e0..0x8016b384
MARK_BINARY_BLOB(ISFS_WriteAsync, 0x8016b2e0, 0x8016b384);
asm UNKNOWN_FUNCTION(ISFS_WriteAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r4, 0;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  beq lbl_8016b318;
  clrlwi. r0, r4, 0x1b;
  beq lbl_8016b320;
lbl_8016b318:
  li r3, -101;
  b lbl_8016b36c;
lbl_8016b320:
  lwz r3, _unk_80386784;
  li r4, 0x140;
  li r5, 0x20;
  bl iosAllocAligned;
  cmpwi r3, 0;
  bne lbl_8016b340;
  li r3, -118;
  b lbl_8016b36c;
lbl_8016b340:
  stw r30, 0x100(r3);
  lis r6, 0x8017;
  li r0, 0;
  mr r4, r28;
  stw r31, 0x104(r3);
  mr r5, r29;
  mr r7, r3;
  addi r6, r6, -25356;
  stw r0, 0x108(r3);
  mr r3, r27;
  bl IOS_WriteAsync;
lbl_8016b36c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_Close
// PAL: 0x8016b384..0x8016b388
MARK_BINARY_BLOB(ISFS_Close, 0x8016b384, 0x8016b388);
asm UNKNOWN_FUNCTION(ISFS_Close) {
  // clang-format off
  nofralloc;
  b IOS_Close;
  // clang-format on
}

// Symbol: ISFS_CloseAsync
// PAL: 0x8016b388..0x8016b40c
MARK_BINARY_BLOB(ISFS_CloseAsync, 0x8016b388, 0x8016b40c);
asm UNKNOWN_FUNCTION(ISFS_CloseAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  li r5, 0x20;
  stw r30, 0x18(r1);
  mr r30, r4;
  li r4, 0x140;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r3, _unk_80386784;
  bl iosAllocAligned;
  cmpwi r3, 0;
  bne lbl_8016b3cc;
  li r3, -118;
  b lbl_8016b3f0;
lbl_8016b3cc:
  stw r30, 0x100(r3);
  lis r4, 0x8017;
  li r0, 0;
  mr r5, r3;
  stw r31, 0x104(r3);
  addi r4, r4, -25356;
  stw r0, 0x108(r3);
  mr r3, r29;
  bl IOS_CloseAsync;
lbl_8016b3f0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ISFS_ShutdownAsync
// PAL: 0x8016b40c..0x8016b49c
MARK_BINARY_BLOB(ISFS_ShutdownAsync, 0x8016b40c, 0x8016b49c);
asm UNKNOWN_FUNCTION(ISFS_ShutdownAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 0x20;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  li r4, 0x140;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r3, _unk_80386784;
  bl iosAllocAligned;
  lwz r0, _unk_80385920;
  cmpwi r0, 0;
  bge lbl_8016b44c;
  li r3, -101;
  b lbl_8016b484;
lbl_8016b44c:
  stw r30, 0x100(r3);
  lis r9, 0x8017;
  li r0, 0;
  mr r10, r3;
  stw r31, 0x104(r3);
  addi r9, r9, -25356;
  li r4, 0xd;
  li r5, 0;
  stw r0, 0x108(r3);
  li r6, 0;
  li r7, 0;
  li r8, 0;
  lwz r3, _unk_80385920;
  bl IOS_IoctlAsync;
lbl_8016b484:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
