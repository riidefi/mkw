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

// Extern function references.
// PAL: 0x801671d0
extern UNKNOWN_FUNCTION(ESP_InitLib);
// PAL: 0x80167224
extern UNKNOWN_FUNCTION(ESP_CloseLib);
// PAL: 0x80167904
extern UNKNOWN_FUNCTION(ESP_GetDataDir);
// PAL: 0x8016799c
extern UNKNOWN_FUNCTION(ESP_GetTitleId);
// PAL: 0x8016b16c
extern UNKNOWN_FUNCTION(ISFS_Seek);
// PAL: 0x8016b1fc
extern UNKNOWN_FUNCTION(ISFS_Read);
// PAL: 0x8016b21c
extern UNKNOWN_FUNCTION(ISFS_ReadAsync);
// PAL: 0x8016b2c0
extern UNKNOWN_FUNCTION(ISFS_Write);
// PAL: 0x8016b2e0
extern UNKNOWN_FUNCTION(ISFS_WriteAsync);
// PAL: 0x8016b384
extern UNKNOWN_FUNCTION(ISFS_Close);

// .sdata
char _unk_80385a10[] = "/";
char _unk_80385a14[] = "/%s";

// Symbol: nandCreate
// PAL: 0x8019b314..0x8019b43c
MARK_BINARY_BLOB(nandCreate, 0x8019b314, 0x8019b43c);
asm UNKNOWN_FUNCTION(nandCreate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 0x18(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0x1c(r1);
  mr r30, r7;
  mr r31, r8;
  addi r3, r1, 0x18;
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x10(r1);
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019b3b8;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019b3b8;
  li r3, -102;
  b lbl_8019b424;
lbl_8019b3b8:
  rlwinm. r0, r27, 0, 0x1b, 0x1b;
  bne lbl_8019b3c8;
  li r3, -101;
  b lbl_8019b424;
lbl_8019b3c8:
  mr r3, r27;
  addi r4, r1, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019b40c;
  lis r8, nandCallback@ha;
  lwz r5, 0x10(r1);
  lwz r6, 0xc(r1);
  mr r4, r28;
  lwz r7, 8(r1);
  mr r9, r29;
  addi r3, r1, 0x18;
  la r8, nandCallback@l(r8);
  bl ISFS_CreateFileAsync;
  b lbl_8019b424;
lbl_8019b40c:
  lwz r5, 0x10(r1);
  mr r4, r28;
  lwz r6, 0xc(r1);
  addi r3, r1, 0x18;
  lwz r7, 8(r1);
  bl ISFS_CreateFile;
lbl_8019b424:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: NANDCreate
// PAL: 0x8019b43c..0x8019b4b0
MARK_BINARY_BLOB(NANDCreate, 0x8019b43c, 0x8019b4b0);
asm s32 NANDCreate(const char*, u8, u8) {
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
  beq lbl_8019b490;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl nandCreate;
  bl nandConvertErrorCode;
  b lbl_8019b494;
lbl_8019b490:
  li r3, -128;
lbl_8019b494:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDPrivateCreate
// PAL: 0x8019b4b0..0x8019b524
MARK_BINARY_BLOB(NANDPrivateCreate, 0x8019b4b0, 0x8019b524);
asm UNKNOWN_FUNCTION(NANDPrivateCreate) {
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
  beq lbl_8019b504;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 1;
  bl nandCreate;
  bl nandConvertErrorCode;
  b lbl_8019b508;
lbl_8019b504:
  li r3, -128;
lbl_8019b508:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDPrivateCreateAsync
// PAL: 0x8019b524..0x8019b59c
MARK_BINARY_BLOB(NANDPrivateCreateAsync, 0x8019b524, 0x8019b59c);
asm UNKNOWN_FUNCTION(NANDPrivateCreateAsync) {
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
  bne lbl_8019b560;
  li r3, -128;
  b lbl_8019b584;
lbl_8019b560:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r28;
  mr r5, r29;
  mr r6, r31;
  li r7, 1;
  li r8, 1;
  bl nandCreate;
  bl nandConvertErrorCode;
lbl_8019b584:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDDelete
// PAL: 0x8019b59c..0x8019b64c
MARK_BINARY_BLOB(NANDDelete, 0x8019b59c, 0x8019b64c);
asm s32 NANDDelete(const char*) {
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b5c4;
  li r3, -128;
  b lbl_8019b638;
lbl_8019b5c4:
  li r0, 0;
  mr r4, r31;
  stw r0, 8(r1);
  addi r3, r1, 8;
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
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019b62c;
  li r3, -102;
  b lbl_8019b634;
lbl_8019b62c:
  addi r3, r1, 8;
  bl ISFS_Delete;
lbl_8019b634:
  bl nandConvertErrorCode;
lbl_8019b638:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
}

// Symbol: NANDPrivateDelete
// PAL: 0x8019b64c..0x8019b6e4
MARK_BINARY_BLOB(NANDPrivateDelete, 0x8019b64c, 0x8019b6e4);
asm UNKNOWN_FUNCTION(NANDPrivateDelete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b674;
  li r3, -128;
  b lbl_8019b6d0;
lbl_8019b674:
  li r0, 0;
  mr r4, r31;
  stw r0, 8(r1);
  addi r3, r1, 8;
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
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  bl ISFS_Delete;
  bl nandConvertErrorCode;
lbl_8019b6d0:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: NANDPrivateDeleteAsync
// PAL: 0x8019b6e4..0x8019b7a4
MARK_BINARY_BLOB(NANDPrivateDeleteAsync, 0x8019b6e4, 0x8019b7a4);
asm UNKNOWN_FUNCTION(NANDPrivateDeleteAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stw r31, 0x5c(r1);
  mr r31, r5;
  stw r30, 0x58(r1);
  mr r30, r4;
  stw r29, 0x54(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b71c;
  li r3, -128;
  b lbl_8019b788;
lbl_8019b71c:
  stw r30, 4(r31);
  li r0, 0;
  mr r4, r29;
  addi r3, r1, 8;
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
  bl nandGenerateAbsPath;
  lis r4, nandCallback@ha;
  mr r5, r31;
  addi r3, r1, 8;
  la r4, nandCallback@l(r4);
  bl ISFS_DeleteAsync;
  bl nandConvertErrorCode;
lbl_8019b788:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: NANDRead
// PAL: 0x8019b7a4..0x8019b80c
MARK_BINARY_BLOB(NANDRead, 0x8019b7a4, 0x8019b80c);
asm s32 NANDRead(NANDFileInfo*, void*, u32) {
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
  beq lbl_8019b7ec;
  lwz r3, 0(r29);
  mr r4, r30;
  mr r5, r31;
  bl ISFS_Read;
  bl nandConvertErrorCode;
  b lbl_8019b7f0;
lbl_8019b7ec:
  li r3, -128;
lbl_8019b7f0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDReadAsync
// PAL: 0x8019b80c..0x8019b884
MARK_BINARY_BLOB(NANDReadAsync, 0x8019b80c, 0x8019b884);
asm s32 NANDReadAsync(NANDFileInfo*, void*, u32, NANDAsyncCallback, void*) {
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
  bne lbl_8019b848;
  li r3, -128;
  b lbl_8019b86c;
lbl_8019b848:
  stw r30, 4(r31);
  lis r6, nandCallback @ha;
  mr r4, r28;
  mr r5, r29;
  lwz r3, 0(r27);
  mr r7, r31;
  la r6, nandCallback @l(r6);
  bl ISFS_ReadAsync;
  bl nandConvertErrorCode;
lbl_8019b86c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDWrite
// PAL: 0x8019b884..0x8019b8ec
MARK_BINARY_BLOB(NANDWrite, 0x8019b884, 0x8019b8ec);
asm s32 NANDWrite(NANDFileInfo*, const void*, u32) {
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
  beq lbl_8019b8cc;
  lwz r3, 0(r29);
  mr r4, r30;
  mr r5, r31;
  bl ISFS_Write;
  bl nandConvertErrorCode;
  b lbl_8019b8d0;
lbl_8019b8cc:
  li r3, -128;
lbl_8019b8d0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDWriteAsync
// PAL: 0x8019b8ec..0x8019b964
MARK_BINARY_BLOB(NANDWriteAsync, 0x8019b8ec, 0x8019b964);
asm s32 NANDWriteAsync(NANDFileInfo*, const void*, u32, NANDAsyncCallback,
                       void*) {
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
  bne lbl_8019b928;
  li r3, -128;
  b lbl_8019b94c;
lbl_8019b928:
  stw r30, 4(r31);
  lis r6, nandCallback @ha;
  mr r4, r28;
  mr r5, r29;
  lwz r3, 0(r27);
  mr r7, r31;
  la r6, nandCallback @l(r6);
  bl ISFS_WriteAsync;
  bl nandConvertErrorCode;
lbl_8019b94c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSeek
// PAL: 0x8019b964..0x8019ba04
MARK_BINARY_BLOB(NANDSeek, 0x8019b964, 0x8019ba04);
asm s32 NANDSeek(NANDFileInfo*, u32, s32) {
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
  bne lbl_8019b99c;
  li r3, -128;
  b lbl_8019b9e8;
lbl_8019b99c:
  cmpwi r31, 1;
  lwz r3, 0(r29);
  li r5, -1;
  beq lbl_8019b9d0;
  bge lbl_8019b9bc;
  cmpwi r31, 0;
  bge lbl_8019b9c8;
  b lbl_8019b9dc;
lbl_8019b9bc:
  cmpwi r31, 3;
  bge lbl_8019b9dc;
  b lbl_8019b9d8;
lbl_8019b9c8:
  li r5, 0;
  b lbl_8019b9dc;
lbl_8019b9d0:
  li r5, 1;
  b lbl_8019b9dc;
lbl_8019b9d8:
  li r5, 2;
lbl_8019b9dc:
  mr r4, r30;
  bl ISFS_Seek;
  bl nandConvertErrorCode;
lbl_8019b9e8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSeekAsync
// PAL: 0x8019ba04..0x8019bab4
MARK_BINARY_BLOB(NANDSeekAsync, 0x8019ba04, 0x8019bab4);
asm s32 NANDSeekAsync(NANDFileInfo*, s32, s32, NANDCallback) {
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
  bne lbl_8019ba40;
  li r3, -128;
  b lbl_8019ba9c;
lbl_8019ba40:
  stw r30, 4(r31);
  cmpwi r29, 1;
  li r5, -1;
  lwz r3, 0(r27);
  beq lbl_8019ba78;
  bge lbl_8019ba64;
  cmpwi r29, 0;
  bge lbl_8019ba70;
  b lbl_8019ba84;
lbl_8019ba64:
  cmpwi r29, 3;
  bge lbl_8019ba84;
  b lbl_8019ba80;
lbl_8019ba70:
  li r5, 0;
  b lbl_8019ba84;
lbl_8019ba78:
  li r5, 1;
  b lbl_8019ba84;
lbl_8019ba80:
  li r5, 2;
lbl_8019ba84:
  lis r6, nandCallback @ha;
  mr r4, r28;
  mr r7, r31;
  la r6, nandCallback @l(r6);
  bl ISFS_SeekAsync;
  bl nandConvertErrorCode;
lbl_8019ba9c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandCreateDir
// PAL: 0x8019bab4..0x8019bbe0
MARK_BINARY_BLOB(nandCreateDir, 0x8019bab4, 0x8019bbe0);
asm UNKNOWN_FUNCTION(nandCreateDir) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 0x18(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0x1c(r1);
  mr r30, r7;
  mr r31, r8;
  addi r3, r1, 0x18;
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019bb4c;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019bb4c;
  li r3, -102;
  b lbl_8019bbc8;
lbl_8019bb4c:
  rlwinm. r0, r27, 0, 0x1b, 0x1b;
  bne lbl_8019bb5c;
  li r3, -101;
  b lbl_8019bbc8;
lbl_8019bb5c:
  li r0, 0;
  mr r3, r27;
  stw r0, 0x10(r1);
  addi r4, r1, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019bbb0;
  lis r8, nandCallback@ha;
  lwz r5, 0x10(r1);
  lwz r6, 0xc(r1);
  mr r4, r28;
  lwz r7, 8(r1);
  mr r9, r29;
  addi r3, r1, 0x18;
  la r8, nandCallback@l(r8);
  bl ISFS_CreateDirAsync;
  b lbl_8019bbc8;
lbl_8019bbb0:
  lwz r5, 0x10(r1);
  mr r4, r28;
  lwz r6, 0xc(r1);
  addi r3, r1, 0x18;
  lwz r7, 8(r1);
  bl ISFS_CreateDir;
lbl_8019bbc8:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: NANDCreateDir
// PAL: 0x8019bbe0..0x8019bc54
MARK_BINARY_BLOB(NANDCreateDir, 0x8019bbe0, 0x8019bc54);
asm s32 NANDCreateDir(const char*, u8, u8) {
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
  beq lbl_8019bc34;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl nandCreateDir;
  bl nandConvertErrorCode;
  b lbl_8019bc38;
lbl_8019bc34:
  li r3, -128;
lbl_8019bc38:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateCreateDir
// PAL: 0x8019bc54..0x8019bcc8
MARK_BINARY_BLOB(NANDPrivateCreateDir, 0x8019bc54, 0x8019bcc8);
asm UNKNOWN_FUNCTION(NANDPrivateCreateDir) {
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
  beq lbl_8019bca8;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 1;
  bl nandCreateDir;
  bl nandConvertErrorCode;
  b lbl_8019bcac;
lbl_8019bca8:
  li r3, -128;
lbl_8019bcac:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDPrivateCreateDirAsync
// PAL: 0x8019bcc8..0x8019bd40
MARK_BINARY_BLOB(NANDPrivateCreateDirAsync, 0x8019bcc8, 0x8019bd40);
asm UNKNOWN_FUNCTION(NANDPrivateCreateDirAsync) {
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
  bne lbl_8019bd04;
  li r3, -128;
  b lbl_8019bd28;
lbl_8019bd04:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r28;
  mr r5, r29;
  mr r6, r31;
  li r7, 1;
  li r8, 1;
  bl nandCreateDir;
  bl nandConvertErrorCode;
lbl_8019bd28:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: nandMove
// PAL: 0x8019bd40..0x8019bee8
MARK_BINARY_BLOB(nandMove, 0x8019bd40, 0x8019bee8);
asm UNKNOWN_FUNCTION(nandMove) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  li r0, 0;
  stw r31, 0xac(r1);
  mr r31, r7;
  stw r30, 0xa8(r1);
  mr r30, r6;
  stw r29, 0xa4(r1);
  mr r29, r5;
  stw r28, 0xa0(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x58;
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  stw r0, 0x60(r1);
  stw r0, 0x64(r1);
  stw r0, 0x68(r1);
  stw r0, 0x6c(r1);
  stw r0, 0x70(r1);
  stw r0, 0x74(r1);
  stw r0, 0x78(r1);
  stw r0, 0x7c(r1);
  stw r0, 0x80(r1);
  stw r0, 0x84(r1);
  stw r0, 0x88(r1);
  stw r0, 0x8c(r1);
  stw r0, 0x90(r1);
  stw r0, 0x94(r1);
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stb r0, 0x14(r1);
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  addi r4, r1, 0x58;
  bl nandGetRelativeName;
  mr r4, r28;
  addi r3, r1, 0x18;
  bl nandGenerateAbsPath;
  addi r3, r1, 0x18;
  la r4, _unk_80385a10;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019be50;
  addi r3, r1, 0x18;
  addi r5, r1, 8;
  la r4, _unk_80385a14;
  crclr 6;
  bl sprintf;
  b lbl_8019be68;
lbl_8019be50:
  addi r3, r1, 0x18;
  la r4, _unk_80385a10;
  bl strcat;
  addi r3, r1, 0x18;
  addi r4, r1, 8;
  bl strcat;
lbl_8019be68:
  cmpwi r31, 0;
  bne lbl_8019be98;
  addi r3, r1, 0x58;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  bne lbl_8019be90;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019be98;
lbl_8019be90:
  li r3, -102;
  b lbl_8019bec8;
lbl_8019be98:
  cmpwi r30, 0;
  beq lbl_8019bebc;
  lis r5, nandCallback@ha;
  mr r6, r29;
  addi r3, r1, 0x58;
  addi r4, r1, 0x18;
  la r5, nandCallback@l(r5);
  bl ISFS_RenameAsync;
  b lbl_8019bec8;
lbl_8019bebc:
  addi r3, r1, 0x58;
  addi r4, r1, 0x18;
  bl ISFS_Rename;
lbl_8019bec8:
  lwz r0, 0xb4(r1);
  lwz r31, 0xac(r1);
  lwz r30, 0xa8(r1);
  lwz r29, 0xa4(r1);
  lwz r28, 0xa0(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: NANDMove
// PAL: 0x8019bee8..0x8019bf4c
MARK_BINARY_BLOB(NANDMove, 0x8019bee8, 0x8019bf4c);
asm s32 NANDMove(const char*, const char*) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019bf30;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandMove;
  bl nandConvertErrorCode;
  b lbl_8019bf34;
lbl_8019bf30:
  li r3, -128;
lbl_8019bf34:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetLength
// PAL: 0x8019bf4c..0x8019bfd4
MARK_BINARY_BLOB(NANDGetLength, 0x8019bf4c, 0x8019bfd4);
asm s32 NANDGetLength(NANDFileInfo*, u32*) {
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -96;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  stw r31, -4(r12);
  mr r31, r4;
  stw r30, -8(r12);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019bf88;
  li r3, -128;
  b lbl_8019bfb8;
lbl_8019bf88:
  lwz r3, 0(r30);
  addi r4, r1, 0x20;
  bl ISFS_GetFileStats;
  cmpwi r3, 0;
  bne lbl_8019bfb4;
  cmpwi r31, 0;
  beq lbl_8019bfb4;
  lwz r0, 0x20(r1);
  stw r0, 0(r31);
  b lbl_8019bfb4;
  stw r0, 0(0);
lbl_8019bfb4:
  bl nandConvertErrorCode;
lbl_8019bfb8:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  lwz r30, -8(r10);
  mtlr r0;
  mr r1, r10;
  blr;
}

// Symbol: nandGetFileStatusAsyncCallback
// PAL: 0x8019bfd4..0x8019c048
MARK_BINARY_BLOB(nandGetFileStatusAsyncCallback, 0x8019bfd4, 0x8019c048);
asm UNKNOWN_FUNCTION(nandGetFileStatusAsyncCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  addi r0, r4, 0x53;
  rlwinm r6, r0, 0, 0, 0x1a;
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019c020;
  lwz r5, 0x74(r4);
  cmpwi r5, 0;
  beq lbl_8019c00c;
  lwz r0, 0(r6);
  stw r0, 0(r5);
lbl_8019c00c:
  lwz r4, 0x78(r4);
  cmpwi r4, 0;
  beq lbl_8019c020;
  lwz r0, 4(r6);
  stw r0, 0(r4);
lbl_8019c020:
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

// Symbol: NANDGetLengthAsync
// PAL: 0x8019c048..0x8019c0d8
MARK_BINARY_BLOB(NANDGetLengthAsync, 0x8019c048, 0x8019c0d8);
asm s32 NANDGetLengthAsync(NANDFileInfo*, u32*, NANDCallback,
                           NANDCommandBlock*) {
  nofralloc;
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
  bne lbl_8019c088;
  li r3, -128;
  b lbl_8019c0b8;
lbl_8019c088:
  li r3, 0;
  addi r0, r31, 0x53;
  stw r30, 4(r31);
  lis r5, nandGetFileStatusAsyncCallback @ha;
  mr r6, r31;
  rlwinm r4, r0, 0, 0, 0x1a;
  stw r29, 0x74(r31);
  la r5, nandGetFileStatusAsyncCallback @l(r5);
  stw r3, 0x78(r31);
  lwz r3, 0(r28);
  bl ISFS_GetFileStatsAsync;
  bl nandConvertErrorCode;
lbl_8019c0b8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandComposePerm
// PAL: 0x8019c0d8..0x8019c12c
MARK_BINARY_BLOB(nandComposePerm, 0x8019c0d8, 0x8019c12c);
asm UNKNOWN_FUNCTION(nandComposePerm) {
  // clang-format off
  nofralloc;
  clrlwi. r0, r4, 0x1f;
  li r7, 0;
  beq lbl_8019c0e8;
  ori r7, r7, 0x10;
lbl_8019c0e8:
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  beq lbl_8019c0f4;
  ori r7, r7, 0x20;
lbl_8019c0f4:
  clrlwi. r0, r5, 0x1f;
  beq lbl_8019c100;
  ori r7, r7, 4;
lbl_8019c100:
  rlwinm. r0, r5, 0, 0x1e, 0x1e;
  beq lbl_8019c10c;
  ori r7, r7, 8;
lbl_8019c10c:
  clrlwi. r0, r6, 0x1f;
  beq lbl_8019c118;
  ori r7, r7, 1;
lbl_8019c118:
  rlwinm. r0, r6, 0, 0x1e, 0x1e;
  beq lbl_8019c124;
  ori r7, r7, 2;
lbl_8019c124:
  stb r7, 0(r3);
  blr;
  // clang-format on
}

// Symbol: nandSplitPerm
// PAL: 0x8019c12c..0x8019c1b8
MARK_BINARY_BLOB(nandSplitPerm, 0x8019c12c, 0x8019c1b8);
asm UNKNOWN_FUNCTION(nandSplitPerm) {
  // clang-format off
  nofralloc;
  li r7, 0;
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  stw r7, 0(r4);
  stw r7, 0(r5);
  stw r7, 0(r6);
  beq lbl_8019c150;
  lwz r0, 0(r4);
  ori r0, r0, 1;
  stw r0, 0(r4);
lbl_8019c150:
  rlwinm. r0, r3, 0, 0x1a, 0x1a;
  beq lbl_8019c164;
  lwz r0, 0(r4);
  ori r0, r0, 2;
  stw r0, 0(r4);
lbl_8019c164:
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8019c178;
  lwz r0, 0(r5);
  ori r0, r0, 1;
  stw r0, 0(r5);
lbl_8019c178:
  rlwinm. r0, r3, 0, 0x1c, 0x1c;
  beq lbl_8019c18c;
  lwz r0, 0(r5);
  ori r0, r0, 2;
  stw r0, 0(r5);
lbl_8019c18c:
  clrlwi. r0, r3, 0x1f;
  beq lbl_8019c1a0;
  lwz r0, 0(r6);
  ori r0, r0, 1;
  stw r0, 0(r6);
lbl_8019c1a0:
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  beqlr;
  lwz r0, 0(r6);
  ori r0, r0, 2;
  stw r0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: nandGetStatus
// PAL: 0x8019c1b8..0x8019c30c
MARK_BINARY_BLOB(nandGetStatus, 0x8019c1b8, 0x8019c30c);
asm UNKNOWN_FUNCTION(nandGetStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  li r0, 0;
  stw r31, 0x6c(r1);
  mr r31, r7;
  stw r30, 0x68(r1);
  mr r30, r6;
  stw r29, 0x64(r1);
  mr r29, r5;
  stw r28, 0x60(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x20;
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019c254;
  addi r3, r1, 0x20;
  bl nandIsUnderPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c254;
  li r3, -102;
  b lbl_8019c2ec;
lbl_8019c254:
  cmpwi r30, 0;
  beq lbl_8019c28c;
  lis r10, nandGetStatusCallback@ha;
  stw r29, 8(r1);
  mr r4, r28;
  addi r3, r1, 0x20;
  addi r5, r28, 4;
  addi r6, r29, 0x20;
  addi r7, r29, 0x24;
  addi r8, r29, 0x28;
  addi r9, r29, 0x2c;
  la r10, nandGetStatusCallback@l(r10);
  bl ISFS_GetAttrAsync;
  b lbl_8019c2ec;
lbl_8019c28c:
  li r0, 0;
  mr r4, r28;
  stw r0, 0x1c(r1);
  addi r3, r1, 0x20;
  addi r5, r28, 4;
  addi r6, r1, 0x1c;
  stw r0, 0x18(r1);
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  bl ISFS_GetAttr;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8019c2e8;
  lwz r4, 0x18(r1);
  addi r3, r28, 7;
  lwz r5, 0x14(r1);
  lwz r6, 0x10(r1);
  bl nandComposePerm;
  lwz r0, 0x1c(r1);
  stb r0, 6(r28);
lbl_8019c2e8:
  mr r3, r31;
lbl_8019c2ec:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  lwz r29, 0x64(r1);
  lwz r28, 0x60(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: nandGetStatusCallback
// PAL: 0x8019c30c..0x8019c380
MARK_BINARY_BLOB(nandGetStatusCallback, 0x8019c30c, 0x8019c380);
asm UNKNOWN_FUNCTION(nandGetStatusCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bne lbl_8019c350;
  lwz r5, 0x14(r4);
  lwz r0, 0x20(r4);
  addi r3, r5, 7;
  stb r0, 6(r5);
  lwz r4, 0x24(r4);
  lwz r5, 0x28(r31);
  lwz r6, 0x2c(r31);
  bl nandComposePerm;
lbl_8019c350:
  mr r3, r30;
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDGetStatus
// PAL: 0x8019c380..0x8019c3e4
MARK_BINARY_BLOB(NANDGetStatus, 0x8019c380, 0x8019c3e4);
asm s32 NANDGetStatus(const char*, NANDStatus*) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c3c8;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandGetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c3cc;
lbl_8019c3c8:
  li r3, -128;
lbl_8019c3cc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateGetStatus
// PAL: 0x8019c3e4..0x8019c448
MARK_BINARY_BLOB(NANDPrivateGetStatus, 0x8019c3e4, 0x8019c448);
asm UNKNOWN_FUNCTION(NANDPrivateGetStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c42c;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandGetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c430;
lbl_8019c42c:
  li r3, -128;
lbl_8019c430:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDPrivateGetStatusAsync
// PAL: 0x8019c448..0x8019c4cc
MARK_BINARY_BLOB(NANDPrivateGetStatusAsync, 0x8019c448, 0x8019c4cc);
asm UNKNOWN_FUNCTION(NANDPrivateGetStatusAsync) {
  // clang-format off
  nofralloc;
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
  bne lbl_8019c488;
  li r3, -128;
  b lbl_8019c4ac;
lbl_8019c488:
  stw r30, 4(r31);
  mr r3, r28;
  mr r4, r29;
  mr r5, r31;
  stw r29, 0x14(r31);
  li r6, 1;
  li r7, 1;
  bl nandGetStatus;
  bl nandConvertErrorCode;
lbl_8019c4ac:
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

// Symbol: nandSetStatus
// PAL: 0x8019c4cc..0x8019c614
MARK_BINARY_BLOB(nandSetStatus, 0x8019c4cc, 0x8019c614);
asm UNKNOWN_FUNCTION(nandSetStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  li r0, 0;
  stw r31, 0x6c(r1);
  mr r31, r7;
  stw r30, 0x68(r1);
  mr r30, r6;
  stw r29, 0x64(r1);
  mr r29, r5;
  stw r28, 0x60(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x20;
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019c568;
  addi r3, r1, 0x20;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c568;
  li r3, -102;
  b lbl_8019c5f4;
lbl_8019c568:
  lbz r3, 7(r28);
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  bne lbl_8019c57c;
  li r3, -101;
  b lbl_8019c5f4;
lbl_8019c57c:
  li r0, 0;
  addi r4, r1, 0x18;
  stw r0, 0x18(r1);
  addi r5, r1, 0x14;
  addi r6, r1, 0x10;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019c5d4;
  stw r29, 8(r1);
  lis r10, nandCallback@ha;
  lwz r4, 0(r28);
  addi r3, r1, 0x20;
  lhz r5, 4(r28);
  la r10, nandCallback@l(r10);
  lbz r6, 6(r28);
  lwz r7, 0x18(r1);
  lwz r8, 0x14(r1);
  lwz r9, 0x10(r1);
  bl ISFS_SetAttrAsync;
  b lbl_8019c5f4;
lbl_8019c5d4:
  lwz r4, 0(r28);
  addi r3, r1, 0x20;
  lhz r5, 4(r28);
  lbz r6, 6(r28);
  lwz r7, 0x18(r1);
  lwz r8, 0x14(r1);
  lwz r9, 0x10(r1);
  bl ISFS_SetAttr;
lbl_8019c5f4:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  lwz r29, 0x64(r1);
  lwz r28, 0x60(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: NANDSetStatus
// PAL: 0x8019c614..0x8019c678
MARK_BINARY_BLOB(NANDSetStatus, 0x8019c614, 0x8019c678);
asm s32 NANDSetStatus(const char*, const NANDStatus*) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c65c;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandSetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c660;
lbl_8019c65c:
  li r3, -128;
lbl_8019c660:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateSetStatus
// PAL: 0x8019c678..0x8019c6dc
MARK_BINARY_BLOB(NANDPrivateSetStatus, 0x8019c678, 0x8019c6dc);
asm UNKNOWN_FUNCTION(NANDPrivateSetStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c6c0;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandSetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c6c4;
lbl_8019c6c0:
  li r3, -128;
lbl_8019c6c4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDSetUserData
// PAL: 0x8019c6dc..0x8019c6e4
void NANDSetUserData(NANDCommandBlock* block, void* userData) {
  block->userData = userData;
}

// Symbol: NANDGetUserData
// PAL: 0x8019c6e4..0x8019c6ec
void* NANDGetUserData(const NANDCommandBlock* block) { return block->userData; }
