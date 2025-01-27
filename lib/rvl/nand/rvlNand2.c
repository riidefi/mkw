#include "nand.h"
#include <decomp.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <rvl/fs/fs.h>
#include <rvl/os/os.h>
#include <rvl/os/osError.h>
#include <rvl/os/osInterrupt.h>

// .data
char _unk_8028e9f0[] = "/tmp/sys";
char _unk_8028e9fc[] = "%s/%08x/%s";
char _unk_8028ea08[] = "Illegal NANDFileInfo.\n";

// .sdata
char _unk_80385a18[] = "%s/%08x";
char _unk_80385a20[] = "%s/%s";

// .sbss
u32 _unk_80386840;

// Symbol: nandOpen
// PAL: 0x8019c6ec..0x8019c800
MARK_BINARY_BLOB(nandOpen, 0x8019c6ec, 0x8019c800);
asm UNKNOWN_FUNCTION(nandOpen) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 8(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0xc(r1);
  mr r30, r7;
  addi r3, r1, 8;
  li r31, 0;
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  cmpwi r30, 0;
  bne lbl_8019c784;
  addi r3, r1, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c784;
  li r3, -102;
  b lbl_8019c7e8;
lbl_8019c784:
  cmpwi r27, 2;
  beq lbl_8019c7b4;
  bge lbl_8019c79c;
  cmpwi r27, 1;
  bge lbl_8019c7ac;
  b lbl_8019c7b8;
lbl_8019c79c:
  cmpwi r27, 4;
  bge lbl_8019c7b8;
  li r31, 3;
  b lbl_8019c7b8;
lbl_8019c7ac:
  li r31, 1;
  b lbl_8019c7b8;
lbl_8019c7b4:
  li r31, 2;
lbl_8019c7b8:
  cmpwi r29, 0;
  beq lbl_8019c7dc;
  lis r5, nandOpenCallback@ha;
  mr r4, r31;
  mr r6, r28;
  addi r3, r1, 8;
  la r5, nandOpenCallback@l(r5);
  bl ISFS_OpenAsync;
  b lbl_8019c7e8;
lbl_8019c7dc:
  mr r4, r31;
  addi r3, r1, 8;
  bl ISFS_Open;
lbl_8019c7e8:
  addi r11, r1, 0x60;
  bl _restgpr_27;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: NANDOpen
// PAL: 0x8019c800..0x8019c88c
MARK_BINARY_BLOB(NANDOpen, 0x8019c800, 0x8019c88c);
asm s32 NANDOpen(const char*, NANDFileInfo*, u8) {
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
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c838;
  li r3, -128;
  b lbl_8019c870;
lbl_8019c838:
  mr r3, r29;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandOpen;
  cmpwi r3, 0;
  blt lbl_8019c86c;
  li r0, 1;
  stw r3, 0(r30);
  li r3, 0;
  stb r0, 0x8a(r30);
  b lbl_8019c870;
lbl_8019c86c:
  bl nandConvertErrorCode;
lbl_8019c870:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateOpen
// PAL: 0x8019c88c..0x8019c918
MARK_BINARY_BLOB(NANDPrivateOpen, 0x8019c88c, 0x8019c918);
asm UNKNOWN_FUNCTION(NANDPrivateOpen) {
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
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c8c4;
  li r3, -128;
  b lbl_8019c8fc;
lbl_8019c8c4:
  mr r3, r29;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandOpen;
  cmpwi r3, 0;
  blt lbl_8019c8f8;
  li r0, 1;
  stw r3, 0(r30);
  li r3, 0;
  stb r0, 0x8a(r30);
  b lbl_8019c8fc;
lbl_8019c8f8:
  bl nandConvertErrorCode;
lbl_8019c8fc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDOpenAsync
// PAL: 0x8019c918..0x8019c990
MARK_BINARY_BLOB(NANDOpenAsync, 0x8019c918, 0x8019c990);
asm s32 NANDOpenAsync(const char*, NANDFileInfo*, u8, NANDCallback,
                      NANDCommandBlock*) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c954;
  li r3, -128;
  b lbl_8019c978;
lbl_8019c954:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r29;
  mr r5, r31;
  stw r28, 8(r31);
  li r6, 1;
  li r7, 0;
  bl nandOpen;
  bl nandConvertErrorCode;
lbl_8019c978:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateOpenAsync
// PAL: 0x8019c990..0x8019ca08
MARK_BINARY_BLOB(NANDPrivateOpenAsync, 0x8019c990, 0x8019ca08);
asm UNKNOWN_FUNCTION(NANDPrivateOpenAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c9cc;
  li r3, -128;
  b lbl_8019c9f0;
lbl_8019c9cc:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r29;
  mr r5, r31;
  stw r28, 8(r31);
  li r6, 1;
  li r7, 1;
  bl nandOpen;
  bl nandConvertErrorCode;
lbl_8019c9f0:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: nandOpenCallback
// PAL: 0x8019ca08..0x8019ca80
MARK_BINARY_BLOB(nandOpenCallback, 0x8019ca08, 0x8019ca80);
asm UNKNOWN_FUNCTION(nandOpenCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  blt lbl_8019ca58;
  lwz r5, 8(r4);
  li r6, 2;
  li r0, 1;
  stw r3, 0(r5);
  li r3, 0;
  lwz r5, 8(r4);
  stb r6, 0x89(r5);
  lwz r5, 8(r4);
  stb r0, 0x8a(r5);
  lwz r12, 4(r4);
  mtctr r12;
  bctrl;
  b lbl_8019ca6c;
lbl_8019ca58:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019ca6c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDClose
// PAL: 0x8019ca80..0x8019caec
MARK_BINARY_BLOB(NANDClose, 0x8019ca80, 0x8019caec);
asm s32 NANDClose(NANDFileInfo*) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019caa8;
  li r3, -128;
  b lbl_8019cad8;
lbl_8019caa8:
  lbz r0, 0x8a(r31);
  cmplwi r0, 1;
  beq lbl_8019cabc;
  li r3, -8;
  b lbl_8019cad8;
lbl_8019cabc:
  lwz r3, 0(r31);
  bl ISFS_Close;
  cmpwi r3, 0;
  bne lbl_8019cad4;
  li r0, 2;
  stb r0, 0x8a(r31);
lbl_8019cad4:
  bl nandConvertErrorCode;
lbl_8019cad8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDCloseAsync
// PAL: 0x8019caec..0x8019cb74
MARK_BINARY_BLOB(NANDCloseAsync, 0x8019caec, 0x8019cb74);
asm s32 NANDCloseAsync(NANDFileInfo*, NANDCallback, NANDCommandBlock*) {
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
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cb24;
  li r3, -128;
  b lbl_8019cb58;
lbl_8019cb24:
  lbz r0, 0x8a(r29);
  cmplwi r0, 1;
  beq lbl_8019cb38;
  li r3, -8;
  b lbl_8019cb58;
lbl_8019cb38:
  stw r30, 4(r31);
  lis r4, nandCloseCallback @ha;
  mr r5, r31;
  stw r29, 8(r31);
  la r4, nandCloseCallback @l(r4);
  lwz r3, 0(r29);
  bl ISFS_CloseAsync;
  bl nandConvertErrorCode;
lbl_8019cb58:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSafeOpen
// PAL: 0x8019cb74..0x8019cb80
MARK_BINARY_BLOB(NANDSafeOpen, 0x8019cb74, 0x8019cb80);
asm s32 NANDSafeOpen(const char*, NANDFileInfo*, u8, void*, u32) {
  nofralloc;
  li r8, 0;
  li r9, 0;
  b nandSafeOpen;
}

// Symbol: nandSafeOpen
// PAL: 0x8019cb80..0x8019cf28
MARK_BINARY_BLOB(nandSafeOpen, 0x8019cb80, 0x8019cf28);
asm UNKNOWN_FUNCTION(nandSafeOpen) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  addi r11, r1, 0x90;
  bl _savegpr_25;
  mr r25, r3;
  mr r28, r4;
  mr r27, r5;
  mr r29, r6;
  mr r30, r7;
  mr r26, r8;
  mr r31, r9;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cbc4;
  li r3, -128;
  b lbl_8019cf10;
lbl_8019cbc4:
  cmpwi r31, 0;
  beq lbl_8019cbdc;
  clrlwi. r0, r30, 0x12;
  beq lbl_8019cbdc;
  li r3, -8;
  b lbl_8019cf10;
lbl_8019cbdc:
  li r0, 0;
  stb r27, 0x88(r28);
  mr r4, r25;
  addi r3, r28, 8;
  stb r0, 0x89(r28);
  bl nandGenerateAbsPath;
  cmpwi r26, 0;
  bne lbl_8019cc14;
  addi r3, r28, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019cc14;
  li r3, -1;
  b lbl_8019cf10;
lbl_8019cc14:
  cmplwi r27, 1;
  bne lbl_8019cc68;
  addi r3, r28, 8;
  li r4, 1;
  bl ISFS_Open;
  cmpwi r3, 0;
  blt lbl_8019cc60;
  li r0, 2;
  cmpwi r31, 0;
  stw r3, 0(r28);
  stb r0, 0x89(r28);
  bne lbl_8019cc50;
  li r0, 3;
  stb r0, 0x8a(r28);
  b lbl_8019cc58;
lbl_8019cc50:
  li r0, 5;
  stb r0, 0x8a(r28);
lbl_8019cc58:
  li r3, 0;
  b lbl_8019cf10;
lbl_8019cc60:
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cc68:
  addi r0, r27, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019cf0c;
  li r0, 0;
  lis r3, _unk_8028e9f0@ha;
  stw r0, 0x20(r1);
  la r3, _unk_8028e9f0@l(r3);
  li r26, -1;
  li r4, 0;
  stw r0, 0x24(r1);
  li r5, 3;
  li r6, 3;
  li r7, 3;
  stw r0, 0x28(r1);
  stb r0, 0x2c(r1);
  bl ISFS_CreateDir;
  cmpwi r3, 0;
  beq lbl_8019ccc4;
  cmpwi r3, -105;
  beq lbl_8019ccc4;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ccc4:
  li r0, 1;
  addi r3, r28, 8;
  stb r0, 0x89(r28);
  addi r4, r1, 0x1c;
  addi r5, r1, 8;
  addi r6, r1, 0x18;
  addi r7, r1, 0x14;
  addi r8, r1, 0x10;
  addi r9, r1, 0xc;
  bl ISFS_GetAttr;
  cmpwi r3, 0;
  beq lbl_8019ccfc;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ccfc:
  addi r3, r28, 8;
  li r4, 1;
  bl ISFS_Open;
  cmpwi r3, 0;
  stw r3, 4(r28);
  bge lbl_8019cd1c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cd1c:
  li r0, 2;
  cmpwi r31, 0;
  stb r0, 0x89(r28);
  bne lbl_8019cd8c;
  bl OSDisableInterrupts;
  lwz r26, _unk_80386840;
  addi r0, r26, 1;
  stw r0, _unk_80386840;
  bl OSRestoreInterrupts;
  lis r5, _unk_8028e9f0@ha;
  mr r6, r26;
  addi r3, r1, 0x30;
  la r4, _unk_80385a18;
  la r5, _unk_8028e9f0@l(r5);
  crclr 6;
  bl sprintf;
  addi r3, r1, 0x30;
  li r4, 0;
  li r5, 3;
  li r6, 0;
  li r7, 0;
  bl ISFS_CreateDir;
  cmpwi r3, 0;
  beq lbl_8019cd84;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cd84:
  li r0, 3;
  stb r0, 0x89(r28);
lbl_8019cd8c:
  addi r3, r1, 0x20;
  addi r4, r28, 8;
  bl nandGetRelativeName;
  cmpwi r31, 0;
  bne lbl_8019cdc8;
  lis r4, _unk_8028e9fc@ha;
  lis r5, _unk_8028e9f0@ha;
  mr r6, r26;
  addi r3, r28, 0x48;
  la r4, _unk_8028e9fc@l(r4);
  la r5, _unk_8028e9f0@l(r5);
  addi r7, r1, 0x20;
  crclr 6;
  bl sprintf;
  b lbl_8019cde4;
lbl_8019cdc8:
  lis r5, _unk_8028e9f0@ha;
  addi r3, r28, 0x48;
  la r5, _unk_8028e9f0@l(r5);
  addi r6, r1, 0x20;
  la r4, _unk_80385a20;
  crclr 6;
  bl sprintf;
lbl_8019cde4:
  lwz r4, 0x18(r1);
  addi r3, r28, 0x48;
  lwz r5, 0x14(r1);
  lwz r6, 0x10(r1);
  lwz r7, 0xc(r1);
  bl ISFS_CreateFile;
  cmpwi r3, 0;
  beq lbl_8019ce0c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ce0c:
  li r0, 4;
  cmplwi r27, 2;
  stb r0, 0x89(r28);
  bne lbl_8019ce30;
  addi r3, r28, 0x48;
  li r4, 2;
  bl ISFS_Open;
  stw r3, 0(r28);
  b lbl_8019ce48;
lbl_8019ce30:
  cmplwi r27, 3;
  bne lbl_8019ce48;
  addi r3, r28, 0x48;
  li r4, 3;
  bl ISFS_Open;
  stw r3, 0(r28);
lbl_8019ce48:
  lwz r3, 0(r28);
  cmpwi r3, 0;
  bge lbl_8019ce5c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ce5c:
  li r0, 5;
  lwz r26, 4(r28);
  stb r0, 0x89(r28);
  mr r27, r3;
lbl_8019ce6c:
  mr r3, r26;
  mr r4, r29;
  mr r5, r30;
  bl ISFS_Read;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8019ce90;
  li r5, 0;
  b lbl_8019ceb0;
lbl_8019ce90:
  bge lbl_8019ce98;
  b lbl_8019ceb0;
lbl_8019ce98:
  mr r3, r27;
  mr r4, r29;
  bl ISFS_Write;
  cmpwi r3, 0;
  bge lbl_8019ce6c;
  mr r5, r3;
lbl_8019ceb0:
  cmpwi r5, 0;
  beq lbl_8019cec4;
  mr r3, r5;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cec4:
  lwz r3, 0(r28);
  li r4, 0;
  li r5, 0;
  bl ISFS_Seek;
  cmpwi r3, 0;
  beq lbl_8019cee4;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cee4:
  cmpwi r31, 0;
  beq lbl_8019cef8;
  li r0, 5;
  stb r0, 0x8a(r28);
  b lbl_8019cf00;
lbl_8019cef8:
  li r0, 3;
  stb r0, 0x8a(r28);
lbl_8019cf00:
  li r3, 0;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cf0c:
  li r3, -8;
lbl_8019cf10:
  addi r11, r1, 0x90;
  bl _restgpr_25;
  lwz r0, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: NANDSafeClose
// PAL: 0x8019cf28..0x8019d104
MARK_BINARY_BLOB(NANDSafeClose, 0x8019cf28, 0x8019d104);
asm s32 NANDSafeClose(NANDFileInfo*) {
  nofralloc;
  li r4, 0;
  b lbl_8019cf30;
lbl_8019cf30:
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  li r0, 0;
  stw r31, 0x5c(r1);
  stw r30, 0x58(r1);
  mr r30, r4;
  stw r29, 0x54(r1);
  mr r29, r3;
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cfa8;
  li r3, -128;
  b lbl_8019d0e8;
lbl_8019cfa8:
  lbz r0, 0x8a(r29);
  cmplwi r0, 3;
  bne lbl_8019cfbc;
  cmpwi r30, 0;
  beq lbl_8019cfd4;
lbl_8019cfbc:
  cmplwi r0, 5;
  bne lbl_8019cfcc;
  cmpwi r30, 0;
  bne lbl_8019cfd4;
lbl_8019cfcc:
  li r3, -8;
  b lbl_8019d0e8;
lbl_8019cfd4:
  lbz r3, 0x88(r29);
  cmplwi r3, 1;
  bne lbl_8019d01c;
  lwz r3, 0(r29);
  bl ISFS_Close;
  cmpwi r3, 0;
  bne lbl_8019d014;
  li r0, 7;
  cmpwi r30, 0;
  stb r0, 0x89(r29);
  bne lbl_8019d00c;
  li r0, 4;
  stb r0, 0x8a(r29);
  b lbl_8019d014;
lbl_8019d00c:
  li r0, 6;
  stb r0, 0x8a(r29);
lbl_8019d014:
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d01c:
  addi r0, r3, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d0d4;
  lwz r3, 0(r29);
  bl ISFS_Close;
  cmpwi r3, 0;
  beq lbl_8019d044;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d044:
  li r31, 6;
  lwz r3, 4(r29);
  stb r31, 0x89(r29);
  bl ISFS_Close;
  cmpwi r3, 0;
  beq lbl_8019d064;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d064:
  li r0, 7;
  addi r3, r29, 0x48;
  stb r0, 0x89(r29);
  addi r4, r29, 8;
  bl ISFS_Rename;
  cmpwi r3, 0;
  beq lbl_8019d088;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d088:
  li r0, 8;
  cmpwi r30, 0;
  stb r0, 0x89(r29);
  bne lbl_8019d0c8;
  addi r3, r1, 8;
  addi r4, r29, 0x48;
  bl nandGetParentDirectory;
  addi r3, r1, 8;
  bl ISFS_Delete;
  cmpwi r3, 0;
  bne lbl_8019d0cc;
  li r4, 9;
  li r0, 4;
  stb r4, 0x89(r29);
  stb r0, 0x8a(r29);
  b lbl_8019d0cc;
lbl_8019d0c8:
  stb r31, 0x8a(r29);
lbl_8019d0cc:
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d0d4:
  lis r3, _unk_8028ea08 @ha;
  la r3, _unk_8028ea08 @l(r3);
  crclr 6;
  bl OSReport;
  li r3, -8;
lbl_8019d0e8:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
}

// Symbol: NANDPrivateSafeOpenAsync
// PAL: 0x8019d104..0x8019d130
MARK_BINARY_BLOB(NANDPrivateSafeOpenAsync, 0x8019d104, 0x8019d130);
asm UNKNOWN_FUNCTION(NANDPrivateSafeOpenAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r10, 1;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r0, 8(r1);
  bl nandSafeOpenAsync;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandSafeOpenAsync
// PAL: 0x8019d130..0x8019d298
MARK_BINARY_BLOB(nandSafeOpenAsync, 0x8019d130, 0x8019d298);
asm UNKNOWN_FUNCTION(nandSafeOpenAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lwz r31, 0x38(r1);
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  mr r30, r10;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019d17c;
  li r3, -128;
  b lbl_8019d280;
lbl_8019d17c:
  cmpwi r31, 0;
  beq lbl_8019d194;
  clrlwi. r0, r27, 0x12;
  beq lbl_8019d194;
  li r3, -8;
  b lbl_8019d280;
lbl_8019d194:
  li r0, 0;
  stb r25, 0x88(r24);
  mr r4, r23;
  addi r3, r24, 8;
  stb r0, 0x89(r24);
  stw r31, 0xb8(r29);
  bl nandGenerateAbsPath;
  cmpwi r30, 0;
  bne lbl_8019d1d0;
  addi r3, r24, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019d1d0;
  li r3, -1;
  b lbl_8019d280;
lbl_8019d1d0:
  cmplwi r25, 1;
  bne lbl_8019d210;
  lis r5, nandReadOpenCallback@ha;
  stw r24, 8(r29);
  mr r6, r29;
  addi r3, r24, 8;
  stw r28, 4(r29);
  la r5, nandReadOpenCallback@l(r5);
  li r4, 1;
  bl ISFS_OpenAsync;
  cmpwi r3, 0;
  bne lbl_8019d208;
  li r3, 0;
  b lbl_8019d280;
lbl_8019d208:
  bl nandConvertErrorCode;
  b lbl_8019d280;
lbl_8019d210:
  addi r0, r25, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d27c;
  li r31, 0;
  lis r3, _unk_8028e9f0@ha;
  lis r8, nandSafeOpenCallback@ha;
  stw r24, 8(r29);
  mr r9, r29;
  la r3, _unk_8028e9f0@l(r3);
  stw r28, 4(r29);
  la r8, nandSafeOpenCallback@l(r8);
  li r4, 0;
  li r5, 3;
  stw r31, 0x7c(r29);
  li r6, 3;
  li r7, 3;
  stw r26, 0x80(r29);
  stw r27, 0x84(r29);
  bl ISFS_CreateDirAsync;
  cmpwi r3, 0;
  bne lbl_8019d26c;
  b lbl_8019d274;
lbl_8019d26c:
  bl nandConvertErrorCode;
  mr r31, r3;
lbl_8019d274:
  mr r3, r31;
  b lbl_8019d280;
lbl_8019d27c:
  li r3, -8;
lbl_8019d280:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: nandSafeOpenCallback
// PAL: 0x8019d298..0x8019d688
MARK_BINARY_BLOB(nandSafeOpenCallback, 0x8019d298, 0x8019d688);
asm UNKNOWN_FUNCTION(nandSafeOpenCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x74(r1);
  stw r31, 0x6c(r1);
  stw r30, 0x68(r1);
  mr r30, r4;
  bge lbl_8019d2cc;
  cmpwi r3, -105;
  bne lbl_8019d65c;
  lwz r0, 0x7c(r4);
  cmpwi r0, 0;
  bne lbl_8019d65c;
lbl_8019d2cc:
  lwz r0, 0x7c(r4);
  li r6, -117;
  lwz r31, 8(r4);
  cmpwi r0, 0;
  bne lbl_8019d2e8;
  li r0, 1;
  stb r0, 0x89(r31);
lbl_8019d2e8:
  lwz r0, 0x7c(r4);
  cmpwi r0, 2;
  bne lbl_8019d300;
  stw r3, 4(r31);
  li r0, 2;
  stb r0, 0x89(r31);
lbl_8019d300:
  lwz r5, 0x7c(r4);
  cmpwi r5, 2;
  bne lbl_8019d324;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  beq lbl_8019d324;
  addi r0, r5, 2;
  stw r0, 0x7c(r4);
  b lbl_8019d330;
lbl_8019d324:
  lwz r5, 0x7c(r4);
  addi r0, r5, 1;
  stw r0, 0x7c(r4);
lbl_8019d330:
  lwz r0, 0x7c(r4);
  cmpwi r0, 1;
  bne lbl_8019d370;
  lis r10, nandSafeOpenCallback@ha;
  stw r4, 8(r1);
  addi r3, r31, 8;
  addi r5, r4, 0x1c;
  addi r6, r4, 0x20;
  addi r7, r4, 0x24;
  addi r8, r4, 0x28;
  addi r9, r4, 0x2c;
  la r10, nandSafeOpenCallback@l(r10);
  addi r4, r4, 0x18;
  bl ISFS_GetAttrAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d370:
  cmpwi r0, 2;
  bne lbl_8019d398;
  lis r5, nandSafeOpenCallback@ha;
  mr r6, r30;
  addi r3, r31, 8;
  li r4, 1;
  la r5, nandSafeOpenCallback@l(r5);
  bl ISFS_OpenAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d398:
  cmpwi r0, 3;
  bne lbl_8019d400;
  bl OSDisableInterrupts;
  lwz r31, _unk_80386840;
  addi r0, r31, 1;
  stw r0, _unk_80386840;
  bl OSRestoreInterrupts;
  lis r5, _unk_8028e9f0@ha;
  stw r31, 0x8c(r30);
  mr r6, r31;
  addi r3, r1, 0x20;
  la r5, _unk_8028e9f0@l(r5);
  la r4, _unk_80385a18;
  crclr 6;
  bl sprintf;
  lis r8, nandSafeOpenCallback@ha;
  mr r9, r30;
  addi r3, r1, 0x20;
  li r4, 0;
  la r8, nandSafeOpenCallback@l(r8);
  li r5, 3;
  li r6, 0;
  li r7, 0;
  bl ISFS_CreateDirAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d400:
  cmpwi r0, 4;
  bne lbl_8019d498;
  addi r3, r1, 0x10;
  addi r4, r31, 8;
  bl nandGetRelativeName;
  lwz r0, 0xb8(r30);
  cmpwi r0, 0;
  bne lbl_8019d450;
  li r0, 3;
  lis r4, _unk_8028e9fc@ha;
  stb r0, 0x89(r31);
  lis r5, _unk_8028e9f0@ha;
  addi r3, r31, 0x48;
  la r4, _unk_8028e9fc@l(r4);
  lwz r6, 0x8c(r30);
  la r5, _unk_8028e9f0@l(r5);
  addi r7, r1, 0x10;
  crclr 6;
  bl sprintf;
  b lbl_8019d46c;
lbl_8019d450:
  lis r5, _unk_8028e9f0@ha;
  addi r3, r31, 0x48;
  la r5, _unk_8028e9f0@l(r5);
  addi r6, r1, 0x10;
  la r4, _unk_80385a20;
  crclr 6;
  bl sprintf;
lbl_8019d46c:
  lis r8, nandSafeOpenCallback@ha;
  lwz r4, 0x20(r30);
  lwz r5, 0x24(r30);
  mr r9, r30;
  lwz r6, 0x28(r30);
  addi r3, r31, 0x48;
  lwz r7, 0x2c(r30);
  la r8, nandSafeOpenCallback@l(r8);
  bl ISFS_CreateFileAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d498:
  cmpwi r0, 5;
  bne lbl_8019d504;
  li r0, 4;
  stb r0, 0x89(r31);
  lbz r0, 0x88(r31);
  cmplwi r0, 2;
  bne lbl_8019d4d4;
  lis r5, nandSafeOpenCallback@ha;
  mr r6, r30;
  addi r3, r31, 0x48;
  li r4, 2;
  la r5, nandSafeOpenCallback@l(r5);
  bl ISFS_OpenAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d4d4:
  cmplwi r0, 3;
  bne lbl_8019d4fc;
  lis r5, nandSafeOpenCallback@ha;
  mr r6, r30;
  addi r3, r31, 0x48;
  li r4, 3;
  la r5, nandSafeOpenCallback@l(r5);
  bl ISFS_OpenAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d4fc:
  li r6, -117;
  b lbl_8019d638;
lbl_8019d504:
  cmpwi r0, 6;
  bne lbl_8019d544;
  stw r3, 0(r31);
  li r3, 5;
  lis r6, nandSafeOpenCallback@ha;
  li r0, 7;
  stb r3, 0x89(r31);
  mr r7, r30;
  la r6, nandSafeOpenCallback@l(r6);
  stw r0, 0x7c(r4);
  lwz r4, 0x80(r4);
  lwz r3, 4(r31);
  lwz r5, 0x84(r30);
  bl ISFS_ReadAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d544:
  cmpwi r0, 7;
  bne lbl_8019d570;
  lis r6, nandSafeOpenCallback@ha;
  lwz r3, 4(r31);
  lwz r4, 0x80(r4);
  mr r7, r30;
  lwz r5, 0x84(r30);
  la r6, nandSafeOpenCallback@l(r6);
  bl ISFS_ReadAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d570:
  cmpwi r0, 8;
  bne lbl_8019d5d4;
  cmpwi r3, 0;
  ble lbl_8019d5ac;
  li r0, 6;
  lis r6, nandSafeOpenCallback@ha;
  stw r0, 0x7c(r4);
  mr r5, r3;
  lwz r4, 0x80(r4);
  mr r7, r30;
  lwz r3, 0(r31);
  la r6, nandSafeOpenCallback@l(r6);
  bl ISFS_WriteAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d5ac:
  bne lbl_8019d638;
  lis r6, nandSafeOpenCallback@ha;
  lwz r3, 0(r31);
  mr r7, r30;
  li r4, 0;
  la r6, nandSafeOpenCallback@l(r6);
  li r5, 0;
  bl ISFS_SeekAsync;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d5d4:
  cmpwi r0, 9;
  bne lbl_8019d638;
  cmpwi r3, 0;
  bne lbl_8019d620;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d5fc;
  li r0, 3;
  stb r0, 0x8a(r31);
  b lbl_8019d604;
lbl_8019d5fc:
  li r0, 5;
  stb r0, 0x8a(r31);
lbl_8019d604:
  li r3, 0;
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d620:
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d638:
  cmpwi r6, 0;
  beq lbl_8019d670;
  mr r3, r6;
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d65c:
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
lbl_8019d670:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: nandReadOpenCallback
// PAL: 0x8019d688..0x8019d720
MARK_BINARY_BLOB(nandReadOpenCallback, 0x8019d688, 0x8019d720);
asm UNKNOWN_FUNCTION(nandReadOpenCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  blt lbl_8019d6f8;
  lwz r5, 8(r4);
  li r0, 2;
  stw r3, 0(r5);
  lwz r3, 8(r4);
  stb r0, 0x89(r3);
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d6d4;
  lwz r3, 8(r4);
  li r0, 3;
  stb r0, 0x8a(r3);
  b lbl_8019d6e0;
lbl_8019d6d4:
  lwz r3, 8(r4);
  li r0, 5;
  stb r0, 0x8a(r3);
lbl_8019d6e0:
  lwz r12, 4(r31);
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019d70c;
lbl_8019d6f8:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019d70c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDSafeCloseAsync
// PAL: 0x8019d720..0x8019d824
MARK_BINARY_BLOB(NANDSafeCloseAsync, 0x8019d720, 0x8019d824);
asm s32 NANDSafeCloseAsync(NANDFileInfo*, NANDCallback, NANDCommandBlock*) {
  nofralloc;
  li r6, 0;
  b lbl_8019d728;
lbl_8019d728:
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019d768;
  li r3, -128;
  b lbl_8019d804;
lbl_8019d768:
  lbz r0, 0x8a(r28);
  cmplwi r0, 3;
  bne lbl_8019d77c;
  cmpwi r31, 0;
  beq lbl_8019d794;
lbl_8019d77c:
  cmplwi r0, 5;
  bne lbl_8019d78c;
  cmpwi r31, 0;
  bne lbl_8019d794;
lbl_8019d78c:
  li r3, -8;
  b lbl_8019d804;
lbl_8019d794:
  stw r31, 0xb8(r30);
  lbz r3, 0x88(r28);
  cmplwi r3, 1;
  bne lbl_8019d7c4;
  stw r28, 8(r30);
  lis r4, nandReadCloseCallback @ha;
  mr r5, r30;
  stw r29, 4(r30);
  la r4, nandReadCloseCallback @l(r4);
  lwz r3, 0(r28);
  bl ISFS_CloseAsync;
  b lbl_8019d800;
lbl_8019d7c4:
  addi r0, r3, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d7fc;
  li r0, 0xa;
  lis r4, nandSafeCloseCallback @ha;
  stw r28, 8(r30);
  mr r5, r30;
  la r4, nandSafeCloseCallback @l(r4);
  stw r29, 4(r30);
  stw r0, 0x7c(r30);
  lwz r3, 0(r28);
  bl ISFS_CloseAsync;
  b lbl_8019d800;
lbl_8019d7fc:
  li r3, -101;
lbl_8019d800:
  bl nandConvertErrorCode;
lbl_8019d804:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandSafeCloseCallback
// PAL: 0x8019d824..0x8019d9e8
MARK_BINARY_BLOB(nandSafeCloseCallback, 0x8019d824, 0x8019d9e8);
asm UNKNOWN_FUNCTION(nandSafeCloseCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r4;
  bne lbl_8019d9c0;
  lwz r0, 0x7c(r4);
  li r6, -117;
  lwz r7, 8(r4);
  cmpwi r0, 0xc;
  bne lbl_8019d85c;
  li r0, 8;
  stb r0, 0x89(r7);
lbl_8019d85c:
  lwz r5, 0x7c(r4);
  cmpwi r5, 0xc;
  bne lbl_8019d880;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  beq lbl_8019d880;
  addi r0, r5, 2;
  stw r0, 0x7c(r4);
  b lbl_8019d88c;
lbl_8019d880:
  lwz r5, 0x7c(r4);
  addi r0, r5, 1;
  stw r0, 0x7c(r4);
lbl_8019d88c:
  lwz r0, 0x7c(r4);
  cmpwi r0, 0xb;
  bne lbl_8019d8bc;
  li r0, 6;
  lis r4, nandSafeCloseCallback@ha;
  stb r0, 0x89(r7);
  mr r5, r31;
  la r4, nandSafeCloseCallback@l(r4);
  lwz r3, 4(r7);
  bl ISFS_CloseAsync;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d8bc:
  cmpwi r0, 0xc;
  bne lbl_8019d8ec;
  li r0, 7;
  lis r5, nandSafeCloseCallback@ha;
  stb r0, 0x89(r7);
  mr r6, r31;
  addi r3, r7, 0x48;
  addi r4, r7, 8;
  la r5, nandSafeCloseCallback@l(r5);
  bl ISFS_RenameAsync;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d8ec:
  cmpwi r0, 0xd;
  bne lbl_8019d960;
  li r0, 0;
  addi r3, r1, 8;
  stw r0, 8(r1);
  addi r4, r7, 0x48;
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGetParentDirectory;
  lis r4, nandSafeCloseCallback@ha;
  mr r5, r31;
  addi r3, r1, 8;
  la r4, nandSafeCloseCallback@l(r4);
  bl ISFS_DeleteAsync;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d960:
  cmpwi r0, 0xe;
  bne lbl_8019d99c;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d97c;
  li r0, 9;
  stb r0, 0x89(r7);
lbl_8019d97c:
  li r0, 4;
  stb r0, 0x8a(r7);
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  b lbl_8019d9d4;
lbl_8019d99c:
  cmpwi r6, 0;
  beq lbl_8019d9d4;
  mr r3, r6;
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  b lbl_8019d9d4;
lbl_8019d9c0:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019d9d4:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: nandReadCloseCallback
// PAL: 0x8019d9e8..0x8019da44
MARK_BINARY_BLOB(nandReadCloseCallback, 0x8019d9e8, 0x8019da44);
asm UNKNOWN_FUNCTION(nandReadCloseCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019da1c;
  lwz r5, 8(r4);
  li r6, 7;
  li r0, 4;
  stb r6, 0x89(r5);
  lwz r4, 8(r4);
  stb r0, 0x8a(r4);
lbl_8019da1c:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandCloseCallback
// PAL: 0x8019da44..0x8019daa0
MARK_BINARY_BLOB(nandCloseCallback, 0x8019da44, 0x8019daa0);
asm UNKNOWN_FUNCTION(nandCloseCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019da78;
  lwz r5, 8(r4);
  li r6, 7;
  li r0, 2;
  stb r6, 0x89(r5);
  lwz r4, 8(r4);
  stb r0, 0x8a(r4);
lbl_8019da78:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
