#include "nand.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <rvl/fs/fs.h>
#include <rvl/os/os.h>
#include <rvl/os/osError.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osReset.h>

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

char _unk_8028ea20[] =
    "<< RVL_SDK - NAND \trelease build: Dec 11 2007 01:35:48 "
    "(0x4199_60831) >>";
char _unk_8028ea80[64] = "/" __attribute__((aligned(32)));
struct {
  void* func;
  u32 _unk_04;
  u32 _unk_08;
  u32 _unk_0c;
} _unk_8028eac0 = {
    (void*)(nandOnShutdown),
    0x000000FF,
    0,
    0,
};
char _unk_8028ead0[] = "/shared2";
char _unk_8028eadc[] = "/shared2/";
char _unk_8028eae8[] = "ISFS error code: %d";
char _unk_8028eafc[] = "CAUTION!  Unexpected error code [%d] was found.\n";
char _unk_8028eb30[] = "ISFS unexpected error code: %d";
char _unk_8028eb50[] = "Failed to set home directory.\n";
char _unk_8028eb70[] = "/title/00010000";
char _unk_8028eb80[] = "/title/00010001";
char _unk_8028eb90[] = "/title/00010003";
char _unk_8028eba0[] = "/title/00010004";
char _unk_8028ebb0[] = "/title/00010005";
char _unk_8028ebc0[] = "/title/00010006";
char _unk_8028ebd0[] = "/title/00010007";
char _unk_8028ebe0[] = "/shared2/title";

char* _unk_80385a28 = _unk_8028ea20;
char _unk_80385a2c[] = "/";
u32 _unk_80385a30 = 0xFF;
MKW_PATCH_WORD(_unk_80385a30, 0); // can't place a zero in .sdata natively
char _unk_80385a34[] = ".";
char _unk_80385a38[] = "..";
char _unk_80385a3c[] = "/%s";
char _unk_80385a40[] = "%s/%s";
u32 _unk_80385a48 = 0xFF;
MKW_PATCH_WORD(_unk_80385a48, 0);
u32 _unk_80385a4c = 0x00200000;
char _unk_80385a50[] = "/meta";
char _unk_80385a58[] = "/ticket";
u32 _unk_80385a60 = 0xffffff01;

char* _unk_8028ebf0[] = {
    _unk_80385a50, _unk_80385a58, _unk_8028eb70, _unk_8028eb80,
    _unk_8028eb90, _unk_8028eba0, _unk_8028ebb0, _unk_8028ebc0,
    _unk_8028ebd0, _unk_8028ebe0, NULL,          NULL,
};
char _unk_8028ec20[] = "/shared2/test2/nanderr.log";

// .sbss
u32 _unk_80386854;
u32 _unk_80386850;
u64 _unk_80386848;

// Symbol: nandRemoveTailToken
// PAL: 0x8019daa0..0x8019db74
MARK_BINARY_BLOB(nandRemoveTailToken, 0x8019daa0, 0x8019db74);
asm UNKNOWN_FUNCTION(nandRemoveTailToken) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lbz r0, 0(r4);
  stw r31, 0x1c(r1);
  cmpwi r0, 0x2f;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bne lbl_8019daec;
  lbz r0, 1(r4);
  extsb. r0, r0;
  bne lbl_8019daec;
  li r4, 0x2f;
  li r0, 0;
  stb r4, 0(r3);
  stb r0, 1(r3);
  b lbl_8019db58;
lbl_8019daec:
  mr r3, r30;
  bl strlen;
  addic. r31, r3, -1;
  addi r0, r31, 1;
  add r3, r30, r31;
  mtctr r0;
  blt lbl_8019db58;
lbl_8019db08:
  lbz r0, 0(r3);
  cmpwi r0, 0x2f;
  bne lbl_8019db4c;
  cmpwi r31, 0;
  beq lbl_8019db38;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  bl strncpy;
  li r0, 0;
  stbx r0, r29, r31;
  b lbl_8019db58;
lbl_8019db38:
  li r3, 0x2f;
  li r0, 0;
  stb r3, 0(r29);
  stb r0, 1(r29);
  b lbl_8019db58;
lbl_8019db4c:
  addi r31, r31, -1;
  addi r3, r3, -1;
  bdnz lbl_8019db08;
lbl_8019db58:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: nandGetHeadToken
// PAL: 0x8019db74..0x8019dc48
MARK_BINARY_BLOB(nandGetHeadToken, 0x8019db74, 0x8019dc48);
asm UNKNOWN_FUNCTION(nandGetHeadToken) {
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
  mr r31, r5;
  li r30, 0;
  b lbl_8019dc20;
lbl_8019dba0:
  lbz r0, 0(r31);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  bne lbl_8019dbf0;
  mr r3, r27;
  mr r4, r29;
  mr r5, r30;
  bl strncpy;
  add r4, r30, r29;
  li r3, 0;
  lbz r0, 1(r4);
  stbx r3, r27, r30;
  extsb. r0, r0;
  bne lbl_8019dbe0;
  stb r3, 0(r28);
  b lbl_8019dc30;
lbl_8019dbe0:
  mr r3, r28;
  addi r4, r4, 1;
  bl strcpy;
  b lbl_8019dc30;
lbl_8019dbf0:
  cmpwi r0, 0;
  bne lbl_8019dc18;
  mr r3, r27;
  mr r4, r29;
  mr r5, r30;
  bl strncpy;
  li r0, 0;
  stbx r0, r27, r30;
  stb r0, 0(r28);
  b lbl_8019dc30;
lbl_8019dc18:
  addi r30, r30, 1;
  addi r31, r31, 1;
lbl_8019dc20:
  mr r3, r29;
  bl strlen;
  cmplw r30, r3;
  ble lbl_8019dba0;
lbl_8019dc30:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: nandGetRelativeName
// PAL: 0x8019dc48..0x8019dce0
MARK_BINARY_BLOB(nandGetRelativeName, 0x8019dc48, 0x8019dce0);
asm UNKNOWN_FUNCTION(nandGetRelativeName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  la r3, _unk_80385a2c;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dc84;
  mr r3, r30;
  la r4, _unk_80385a30;
  bl strcpy;
  b lbl_8019dcc8;
lbl_8019dc84:
  mr r3, r31;
  bl strlen;
  addic. r4, r3, -1;
  addi r0, r4, 1;
  add r3, r31, r4;
  mtctr r0;
  blt lbl_8019dcb8;
lbl_8019dca0:
  lbz r0, 0(r3);
  cmpwi r0, 0x2f;
  beq lbl_8019dcb8;
  addi r4, r4, -1;
  addi r3, r3, -1;
  bdnz lbl_8019dca0;
lbl_8019dcb8:
  add r4, r31, r4;
  mr r3, r30;
  addi r4, r4, 1;
  bl strcpy;
lbl_8019dcc8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandConvertPath
// PAL: 0x8019dce0..0x8019de1c
MARK_BINARY_BLOB(nandConvertPath, 0x8019dce0, 0x8019de1c);
asm UNKNOWN_FUNCTION(nandConvertPath) {
  // clang-format off
  nofralloc;
lbl_8019dce0:
  stwu r1, -0x220(r1);
  mflr r0;
  stw r0, 0x224(r1);
  stw r31, 0x21c(r1);
  mr r31, r5;
  stw r30, 0x218(r1);
  mr r30, r4;
  stw r29, 0x214(r1);
  mr r29, r3;
  mr r3, r31;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019dd24;
  mr r3, r29;
  mr r4, r30;
  bl strcpy;
  b lbl_8019de00;
lbl_8019dd24:
  mr r5, r31;
  addi r3, r1, 0x188;
  addi r4, r1, 0x108;
  bl nandGetHeadToken;
  addi r3, r1, 0x188;
  la r4, _unk_80385a34;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dd5c;
  mr r3, r29;
  mr r4, r30;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019dd5c:
  addi r3, r1, 0x188;
  la r4, _unk_80385a38;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dd90;
  mr r4, r30;
  addi r3, r1, 0x88;
  bl nandRemoveTailToken;
  mr r3, r29;
  addi r4, r1, 0x88;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019dd90:
  lbz r0, 0x188(r1);
  extsb. r0, r0;
  beq lbl_8019ddf4;
  mr r3, r30;
  la r4, _unk_80385a2c;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019ddc8;
  addi r3, r1, 8;
  addi r5, r1, 0x188;
  la r4, _unk_80385a3c;
  crclr 6;
  bl sprintf;
  b lbl_8019dde0;
lbl_8019ddc8:
  mr r5, r30;
  addi r3, r1, 8;
  addi r6, r1, 0x188;
  la r4, _unk_80385a40;
  crclr 6;
  bl sprintf;
lbl_8019dde0:
  mr r3, r29;
  addi r4, r1, 8;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019ddf4:
  mr r3, r29;
  mr r4, r30;
  bl strcpy;
lbl_8019de00:
  lwz r0, 0x224(r1);
  lwz r31, 0x21c(r1);
  lwz r30, 0x218(r1);
  lwz r29, 0x214(r1);
  mtlr r0;
  addi r1, r1, 0x220;
  blr;
  // clang-format on
}

// Symbol: nandIsPrivatePath
// PAL: 0x8019de1c..0x8019de50
MARK_BINARY_BLOB(nandIsPrivatePath, 0x8019de1c, 0x8019de50);
asm UNKNOWN_FUNCTION(nandIsPrivatePath) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, _unk_8028ead0@ha;
  li r5, 8;
  stw r0, 0x14(r1);
  la r4, _unk_8028ead0@l(r4);
  bl strncmp;
  cntlzw r0, r3;
  srwi r3, r0, 5;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandIsUnderPrivatePath
// PAL: 0x8019de50..0x8019dea8
MARK_BINARY_BLOB(nandIsUnderPrivatePath, 0x8019de50, 0x8019dea8);
asm UNKNOWN_FUNCTION(nandIsUnderPrivatePath) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, _unk_8028eadc@ha;
  li r5, 9;
  stw r0, 0x14(r1);
  la r4, _unk_8028eadc@l(r4);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019de90;
  lbz r0, 9(r31);
  extsb. r0, r0;
  beq lbl_8019de90;
  li r3, 1;
  b lbl_8019de94;
lbl_8019de90:
  li r3, 0;
lbl_8019de94:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandIsInitialized
// PAL: 0x8019dea8..0x8019debc
MARK_BINARY_BLOB(nandIsInitialized, 0x8019dea8, 0x8019debc);
asm UNKNOWN_FUNCTION(nandIsInitialized) {
  // clang-format off
  nofralloc;
  lwz r3, _unk_80386848;
  addi r0, r3, -2;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  blr;
  // clang-format on
}

// Symbol: nandReportErrorCode
// PAL: 0x8019debc..0x8019dec0
MARK_BINARY_BLOB(nandReportErrorCode, 0x8019debc, 0x8019dec0);
asm UNKNOWN_FUNCTION(nandReportErrorCode) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: nandConvertErrorCode
// PAL: 0x8019dec0..0x8019e020
MARK_BINARY_BLOB(nandConvertErrorCode, 0x8019dec0, 0x8019e020);
asm UNKNOWN_FUNCTION(nandConvertErrorCode) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1a;
  mr r12, r1;
  subfic r11, r11, -768;
  stwux r1, r1, r11;
  mflr r0;
  lis r4, 0x8025;
  stw r0, 4(r12);
  addi r4, r4, 0x2c88;
  li r0, 0x29;
  addi r6, r1, 0x13c;
  stw r31, -4(r12);
  lis r31, _unk_8028ea20@ha;
  la r31, _unk_8028ea20@l(r31);
  addi r5, r4, -4;
  stw r30, -8(r12);
  stw r29, -0xc(r12);
  mr r29, r3;
  mtctr r0;
lbl_8019df08:
  lwz r4, 4(r5);
  lwzu r0, 8(r5);
  stw r4, 4(r6);
  stwu r0, 8(r6);
  bdnz lbl_8019df08;
  cmpwi r3, 0;
  li r30, 0;
  li r4, 0;
  blt lbl_8019df34;
  mr r3, r29;
  b lbl_8019e000;
lbl_8019df34:
  li r0, 0x29;
  addi r5, r1, 0x140;
  mtctr r0;
lbl_8019df40:
  lwzx r0, r5, r4;
  cmpw r3, r0;
  bne lbl_8019dfb4;
  cmpwi r3, -114;
  beq lbl_8019df74;
  cmpwi r3, -116;
  beq lbl_8019df74;
  cmpwi r3, -117;
  beq lbl_8019df74;
  cmpwi r3, -9;
  beq lbl_8019df74;
  cmpwi r3, -12;
  bne lbl_8019df98;
lbl_8019df74:
  mr r5, r29;
  addi r3, r1, 0xc0;
  addi r4, r31, 0xc8;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0xc0;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
lbl_8019df98:
  mr r3, r29;
  bl nandReportErrorCode;
  addi r0, r30, 1;
  addi r3, r1, 0x140;
  slwi r0, r0, 2;
  lwzx r3, r3, r0;
  b lbl_8019e000;
lbl_8019dfb4:
  addi r30, r30, 2;
  addi r4, r4, 8;
  bdnz lbl_8019df40;
  mr r4, r29;
  addi r3, r31, 0xdc;
  crclr 6;
  bl OSReport;
  mr r5, r29;
  addi r3, r1, 0x40;
  addi r4, r31, 0x110;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0x40;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
  mr r3, r29;
  bl nandReportErrorCode;
  li r3, -64;
lbl_8019e000:
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

// Symbol: nandGenerateAbsPath
// PAL: 0x8019e020..0x8019e0e8
MARK_BINARY_BLOB(nandGenerateAbsPath, 0x8019e020, 0x8019e0e8);
asm UNKNOWN_FUNCTION(nandGenerateAbsPath) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  mr r3, r31;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e05c;
  mr r3, r30;
  la r4, _unk_80385a30;
  bl strcpy;
  b lbl_8019e0d0;
lbl_8019e05c:
  lbz r0, 0(r31);
  cmpwi r0, 0x2f;
  bne lbl_8019e070;
  li r0, 0;
  b lbl_8019e074;
lbl_8019e070:
  li r0, 1;
lbl_8019e074:
  cmpwi r0, 0;
  beq lbl_8019e094;
  lis r4, _unk_8028ea80@ha;
  mr r3, r30;
  mr r5, r31;
  la r4, _unk_8028ea80@l(r4);
  bl nandConvertPath;
  b lbl_8019e0d0;
lbl_8019e094:
  mr r3, r30;
  mr r4, r31;
  bl strcpy;
  mr r3, r30;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e0d0;
  add r4, r3, r30;
  lbz r0, -1(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e0d0;
  addic. r0, r3, -1;
  beq lbl_8019e0d0;
  li r0, 0;
  stb r0, -1(r4);
lbl_8019e0d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandGetParentDirectory
// PAL: 0x8019e0e8..0x8019e18c
MARK_BINARY_BLOB(nandGetParentDirectory, 0x8019e0e8, 0x8019e18c);
asm UNKNOWN_FUNCTION(nandGetParentDirectory) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  mr r3, r30;
  bl strlen;
  addi r0, r3, 1;
  mr r31, r3;
  add r4, r30, r3;
  mtctr r0;
  cmpwi r3, 0;
  blt lbl_8019e140;
lbl_8019e128:
  lbz r0, 0(r4);
  cmpwi r0, 0x2f;
  beq lbl_8019e140;
  addi r31, r31, -1;
  addi r4, r4, -1;
  bdnz lbl_8019e128;
lbl_8019e140:
  cmpwi r31, 0;
  bne lbl_8019e158;
  mr r3, r29;
  la r4, _unk_80385a2c;
  bl strcpy;
  b lbl_8019e170;
lbl_8019e158:
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  bl strncpy;
  li r0, 0;
  stbx r0, r29, r31;
lbl_8019e170:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: NANDInit
// PAL: 0x8019e18c..0x8019e2b8
MARK_BINARY_BLOB(NANDInit, 0x8019e18c, 0x8019e2b8);
asm s32 NANDInit(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, _unk_8028ea20 @ha;
  la r31, _unk_8028ea20 @l(r31);
  stw r30, 0x18(r1);
  bl OSDisableInterrupts;
  lwz r0, _unk_80386848;
  cmpwi r0, 1;
  bne lbl_8019e1c4;
  bl OSRestoreInterrupts;
  li r3, -3;
  b lbl_8019e2a0;
lbl_8019e1c4:
  cmpwi r0, 2;
  bne lbl_8019e1d8;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8019e2a0;
lbl_8019e1d8:
  li r0, 1;
  stw r0, _unk_80386848;
  bl OSRestoreInterrupts;
  bl ISFS_OpenLib;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8019e288;
  bl ESP_InitLib;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8019e210;
  addi r3, r1, 8;
  bl ESP_GetTitleId;
  mr r30, r3;
lbl_8019e210:
  cmpwi r30, 0;
  bne lbl_8019e230;
  lis r5, 0x8034;
  lwz r3, 8(r1);
  lwz r4, 0xc(r1);
  addi r5, r5, 0x6d20;
  bl ESP_GetDataDir;
  mr r30, r3;
lbl_8019e230:
  cmpwi r30, 0;
  bne lbl_8019e248;
  lis r4, 0x8034;
  addi r3, r31, 0x60;
  addi r4, r4, 0x6d20;
  bl strcpy;
lbl_8019e248:
  bl ESP_CloseLib;
  cmpwi r30, 0;
  beq lbl_8019e260;
  addi r3, r31, 0x130;
  crclr 6;
  bl OSReport;
lbl_8019e260:
  addi r3, r31, 0xa0;
  bl OSRegisterShutdownFunction;
  bl OSDisableInterrupts;
  li r0, 2;
  stw r0, _unk_80386848;
  bl OSRestoreInterrupts;
  lwz r3, _unk_80385a28;
  bl OSRegisterVersion;
  li r3, 0;
  b lbl_8019e2a0;
lbl_8019e288:
  bl OSDisableInterrupts;
  li r0, 0;
  stw r0, _unk_80386848;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl nandConvertErrorCode;
lbl_8019e2a0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandOnShutdown
// PAL: 0x8019e2b8..0x8019e390
MARK_BINARY_BLOB(nandOnShutdown, 0x8019e2b8, 0x8019e390);
asm UNKNOWN_FUNCTION(nandOnShutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  cmpwi r3, 0;
  bne lbl_8019e368;
  cmplwi r4, 2;
  bne lbl_8019e360;
  li r26, 0;
  stw r26, 8(r1);
  bl OSGetTime;
  lis r5, 0x801a;
  mr r27, r4;
  mr r28, r3;
  addi r4, r1, 8;
  addi r3, r5, -7292;
  bl ISFS_ShutdownAsync;
  lis r3, 0x1062;
  lis r30, 0x8000;
  addi r29, r3, 0x4dd3;
  li r31, 0x1f4;
  b lbl_8019e320;
lbl_8019e314:
  lwz r0, 8(r1);
  cmpwi r0, 0;
  bne lbl_8019e360;
lbl_8019e320:
  bl OSGetTime;
  lwz r0, 0xf8(r30);
  subfc r4, r27, r4;
  subfe r3, r28, r3;
  li r5, 0;
  srwi r0, r0, 2;
  mulhwu r0, r29, r0;
  srwi r6, r0, 6;
  bl __div2i;
  xoris r0, r3, 0x8000;
  xoris r5, r26, 0x8000;
  subfc r3, r31, r4;
  subfe r5, r5, r0;
  subfe r5, r0, r0;
  neg. r5, r5;
  bne lbl_8019e314;
lbl_8019e360:
  li r3, 1;
  b lbl_8019e36c;
lbl_8019e368:
  li r3, 1;
lbl_8019e36c:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  li r0, 1;
  stw r0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: NANDGetCurrentDir
// PAL: 0x8019e390..0x8019e40c
MARK_BINARY_BLOB(NANDGetCurrentDir, 0x8019e390, 0x8019e40c);
asm s32 NANDGetCurrentDir(char[64]) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, _unk_80386848;
  cmpwi r0, 2;
  bne lbl_8019e3bc;
  li r0, 1;
  b lbl_8019e3c0;
lbl_8019e3bc:
  li r0, 0;
lbl_8019e3c0:
  cmpwi r0, 0;
  bne lbl_8019e3d0;
  li r3, -128;
  b lbl_8019e3f4;
lbl_8019e3d0:
  bl OSDisableInterrupts;
  lis r4, _unk_8028ea80 @ha;
  mr r31, r3;
  mr r3, r30;
  la r4, _unk_8028ea80 @l(r4);
  bl strcpy;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_8019e3f4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetHomeDir
// PAL: 0x8019e40c..0x8019e460
MARK_BINARY_BLOB(NANDGetHomeDir, 0x8019e40c, 0x8019e460);
asm s32 NANDGetHomeDir(char[64]) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, _unk_80386848;
  cmpwi r0, 2;
  bne lbl_8019e42c;
  li r0, 1;
  b lbl_8019e430;
lbl_8019e42c:
  li r0, 0;
lbl_8019e430:
  cmpwi r0, 0;
  bne lbl_8019e440;
  li r3, -128;
  b lbl_8019e450;
lbl_8019e440:
  lis r4, 0x8034;
  addi r4, r4, 0x6d20;
  bl strcpy;
  li r3, 0;
lbl_8019e450:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandCallback
// PAL: 0x8019e460..0x8019e49c
MARK_BINARY_BLOB(nandCallback, 0x8019e460, 0x8019e49c);
asm UNKNOWN_FUNCTION(nandCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
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

// Symbol: nandGetType
// PAL: 0x8019e49c..0x8019e770
MARK_BINARY_BLOB(nandGetType, 0x8019e49c, 0x8019e770);
asm UNKNOWN_FUNCTION(nandGetType) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  mr r27, r3;
  mr r30, r4;
  mr r28, r5;
  mr r29, r6;
  mr r31, r7;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e4d8;
  li r3, -101;
  b lbl_8019e758;
lbl_8019e4d8:
  cmpwi r29, 0;
  beq lbl_8019e5e4;
  mr r3, r27;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e500;
  addi r3, r28, 0x34;
  la r4, _unk_80385a30;
  bl strcpy;
  b lbl_8019e574;
lbl_8019e500:
  lbz r0, 0(r27);
  cmpwi r0, 0x2f;
  bne lbl_8019e514;
  li r0, 0;
  b lbl_8019e518;
lbl_8019e514:
  li r0, 1;
lbl_8019e518:
  cmpwi r0, 0;
  beq lbl_8019e538;
  lis r4, _unk_8028ea80@ha;
  mr r5, r27;
  addi r3, r28, 0x34;
  la r4, _unk_8028ea80@l(r4);
  bl nandConvertPath;
  b lbl_8019e574;
lbl_8019e538:
  mr r4, r27;
  addi r3, r28, 0x34;
  bl strcpy;
  addi r3, r28, 0x34;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e574;
  add r4, r3, r28;
  lbz r0, 0x33(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e574;
  addic. r0, r3, -1;
  beq lbl_8019e574;
  li r0, 0;
  stb r0, 0x33(r4);
lbl_8019e574:
  cmpwi r31, 0;
  bne lbl_8019e5c0;
  lis r4, _unk_8028eadc@ha;
  addi r3, r28, 0x34;
  la r4, _unk_8028eadc@l(r4);
  li r5, 9;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019e5ac;
  lbz r0, 0x3d(r28);
  extsb. r0, r0;
  beq lbl_8019e5ac;
  li r0, 1;
  b lbl_8019e5b0;
lbl_8019e5ac:
  li r0, 0;
lbl_8019e5b0:
  cmpwi r0, 0;
  beq lbl_8019e5c0;
  li r3, -102;
  b lbl_8019e758;
lbl_8019e5c0:
  lis r6, 0x801a;
  stw r30, 0x88(r28);
  mr r7, r28;
  addi r3, r28, 0x34;
  addi r5, r28, 0x30;
  addi r6, r6, -6148;
  li r4, 0;
  bl ISFS_ReadDirAsync;
  b lbl_8019e758;
lbl_8019e5e4:
  li r0, 0;
  mr r3, r27;
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
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e648;
  addi r3, r1, 0x10;
  la r4, _unk_80385a30;
  bl strcpy;
  b lbl_8019e6c0;
lbl_8019e648:
  lbz r0, 0(r27);
  cmpwi r0, 0x2f;
  bne lbl_8019e65c;
  li r0, 0;
  b lbl_8019e660;
lbl_8019e65c:
  li r0, 1;
lbl_8019e660:
  cmpwi r0, 0;
  beq lbl_8019e680;
  lis r4, _unk_8028ea80@ha;
  mr r5, r27;
  addi r3, r1, 0x10;
  la r4, _unk_8028ea80@l(r4);
  bl nandConvertPath;
  b lbl_8019e6c0;
lbl_8019e680:
  mr r4, r27;
  addi r3, r1, 0x10;
  bl strcpy;
  addi r3, r1, 0x10;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e6c0;
  addi r0, r1, 0x10;
  add r4, r3, r0;
  lbz r0, -1(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e6c0;
  addic. r0, r3, -1;
  beq lbl_8019e6c0;
  li r0, 0;
  stb r0, -1(r4);
lbl_8019e6c0:
  cmpwi r31, 0;
  bne lbl_8019e70c;
  lis r4, _unk_8028eadc@ha;
  addi r3, r1, 0x10;
  la r4, _unk_8028eadc@l(r4);
  li r5, 9;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019e6f8;
  lbz r0, 0x19(r1);
  extsb. r0, r0;
  beq lbl_8019e6f8;
  li r0, 1;
  b lbl_8019e6fc;
lbl_8019e6f8:
  li r0, 0;
lbl_8019e6fc:
  cmpwi r0, 0;
  beq lbl_8019e70c;
  li r3, -102;
  b lbl_8019e758;
lbl_8019e70c:
  li r0, 0;
  addi r3, r1, 0x10;
  stw r0, 8(r1);
  addi r5, r1, 8;
  li r4, 0;
  bl ISFS_ReadDir;
  cmpwi r3, 0;
  beq lbl_8019e734;
  cmpwi r3, -102;
  bne lbl_8019e744;
lbl_8019e734:
  li r0, 2;
  li r3, 0;
  stb r0, 0(r30);
  b lbl_8019e758;
lbl_8019e744:
  cmpwi r3, -101;
  bne lbl_8019e758;
  li r0, 1;
  li r3, 0;
  stb r0, 0(r30);
lbl_8019e758:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: NANDGetType
// PAL: 0x8019e770..0x8019e7b4
MARK_BINARY_BLOB(NANDGetType, 0x8019e770, 0x8019e7b4);
asm s32 NANDGetType(const char*, u8*) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, _unk_80386848;
  cmpwi r0, 2;
  beq lbl_8019e790;
  li r3, -128;
  b lbl_8019e7a4;
lbl_8019e790:
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandGetType;
  bl nandConvertErrorCode;
lbl_8019e7a4:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateGetTypeAsync
// PAL: 0x8019e7b4..0x8019e7fc
MARK_BINARY_BLOB(NANDPrivateGetTypeAsync, 0x8019e7b4, 0x8019e7fc);
asm UNKNOWN_FUNCTION(NANDPrivateGetTypeAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, _unk_80386848;
  cmpwi r0, 2;
  beq lbl_8019e7d4;
  li r3, -128;
  b lbl_8019e7ec;
lbl_8019e7d4:
  stw r5, 4(r6);
  mr r5, r6;
  li r6, 1;
  li r7, 1;
  bl nandGetType;
  bl nandConvertErrorCode;
lbl_8019e7ec:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: nandGetTypeCallback
// PAL: 0x8019e7fc..0x8019e874
MARK_BINARY_BLOB(nandGetTypeCallback, 0x8019e7fc, 0x8019e874);
asm UNKNOWN_FUNCTION(nandGetTypeCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  beq lbl_8019e820;
  cmpwi r3, -102;
  bne lbl_8019e834;
lbl_8019e820:
  lwz r4, 0x88(r4);
  li r0, 2;
  li r3, 0;
  stb r0, 0(r4);
  b lbl_8019e84c;
lbl_8019e834:
  cmpwi r3, -101;
  bne lbl_8019e84c;
  lwz r4, 0x88(r4);
  li r0, 1;
  li r3, 0;
  stb r0, 0(r4);
lbl_8019e84c:
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

// Symbol: nandGetHomeDir
// PAL: 0x8019e874..0x8019e880
u32 nandGetHomeDir() { return 0x80346d20; }

// Symbol: NANDInitBanner
// PAL: 0x8019e880..0x8019e95c
MARK_BINARY_BLOB(NANDInitBanner, 0x8019e880, 0x8019e95c);
asm void NANDInitBanner(NANDBanner*, u32, const u16*, const u16*) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 1;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  addi r5, r7, -3936;
  stw r29, 0x14(r1);
  mr r29, r4;
  li r4, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl memset;
  lis r3, 0x5749;
  stw r29, 4(r28);
  addi r0, r3, 0x424e;
  la r4, _unk_80385a48;
  stw r0, 0(r28);
  mr r3, r30;
  bl wcscmp;
  cmpwi r3, 0;
  bne lbl_8019e8f4;
  addi r3, r28, 0x20;
  la r4, _unk_80385a4c;
  li r5, 0x20;
  bl wcsncpy;
  b lbl_8019e904;
lbl_8019e8f4:
  mr r4, r30;
  addi r3, r28, 0x20;
  li r5, 0x20;
  bl wcsncpy;
lbl_8019e904:
  mr r3, r31;
  la r4, _unk_80385a48;
  bl wcscmp;
  cmpwi r3, 0;
  bne lbl_8019e92c;
  addi r3, r28, 0x60;
  la r4, _unk_80385a4c;
  li r5, 0x20;
  bl wcsncpy;
  b lbl_8019e93c;
lbl_8019e92c:
  mr r4, r31;
  addi r3, r28, 0x60;
  li r5, 0x20;
  bl wcsncpy;
lbl_8019e93c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSecretGetUsage
// PAL: 0x8019e95c..0x8019ea14
MARK_BINARY_BLOB(NANDSecretGetUsage, 0x8019e95c, 0x8019ea14);
asm UNKNOWN_FUNCTION(NANDSecretGetUsage) {
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
  bne lbl_8019e994;
  li r3, -128;
  b lbl_8019e9f8;
lbl_8019e994:
  li r0, 0;
  mr r4, r29;
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
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 8;
  bl ISFS_GetUsage;
  bl nandConvertErrorCode;
lbl_8019e9f8:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: nandCalcUsage
// PAL: 0x8019ea14..0x8019ead0
MARK_BINARY_BLOB(nandCalcUsage, 0x8019ea14, 0x8019ead0);
asm UNKNOWN_FUNCTION(nandCalcUsage) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  stw r31, 0(r3);
  li r3, -117;
  stw r31, 0(r4);
  b lbl_8019eaa4;
lbl_8019ea50:
  stw r31, 0xc(r1);
  addi r4, r1, 0xc;
  addi r5, r1, 8;
  stw r31, 8(r1);
  lwz r3, 0(r30);
  bl ISFS_GetUsage;
  cmpwi r3, 0;
  bne lbl_8019ea94;
  lwz r4, 0(r28);
  lwz r0, 0xc(r1);
  add r0, r4, r0;
  stw r0, 0(r28);
  lwz r4, 0(r29);
  lwz r0, 8(r1);
  add r0, r4, r0;
  stw r0, 0(r29);
  b lbl_8019eaa0;
lbl_8019ea94:
  cmpwi r3, -106;
  bne lbl_8019eab0;
  li r3, 0;
lbl_8019eaa0:
  addi r30, r30, 4;
lbl_8019eaa4:
  lwz r0, 0(r30);
  cmpwi r0, 0;
  bne lbl_8019ea50;
lbl_8019eab0:
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

// Symbol: NANDCheck
// PAL: 0x8019ead0..0x8019ebd8
MARK_BINARY_BLOB(NANDCheck, 0x8019ead0, 0x8019ebd8);
asm s32 NANDCheck(u32, u32, u32*) {
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  li r0, -1;
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019eb1c;
  li r3, -128;
  b lbl_8019ebbc;
lbl_8019eb1c:
  bl nandGetHomeDir;
  addi r4, r1, 0x14;
  addi r5, r1, 0x10;
  bl ISFS_GetUsage;
  cmpwi r3, 0;
  beq lbl_8019eb3c;
  bl nandConvertErrorCode;
  b lbl_8019ebbc;
lbl_8019eb3c:
  lis r5, _unk_8028ebf0 @ha;
  addi r3, r1, 0xc;
  addi r4, r1, 8;
  la r5, _unk_8028ebf0 @l(r5);
  bl nandCalcUsage;
  cmpwi r3, 0;
  beq lbl_8019eb60;
  bl nandConvertErrorCode;
  b lbl_8019ebbc;
lbl_8019eb60:
  lwz r0, 0x14(r1);
  li r5, 0;
  lwz r4, 8(r1);
  add r0, r0, r29;
  lwz r3, 0xc(r1);
  cmplwi r0, 0x400;
  lwz r0, 0x10(r1);
  ble lbl_8019eb84;
  ori r5, r5, 1;
lbl_8019eb84:
  add r0, r0, r30;
  cmplwi r0, 0x21;
  ble lbl_8019eb94;
  ori r5, r5, 2;
lbl_8019eb94:
  add r0, r3, r29;
  cmplwi r0, 0x4400;
  ble lbl_8019eba4;
  ori r5, r5, 4;
lbl_8019eba4:
  add r0, r4, r30;
  cmplwi r0, 0xfa0;
  ble lbl_8019ebb4;
  ori r5, r5, 8;
lbl_8019ebb4:
  stw r5, 0(r31);
  li r3, 0;
lbl_8019ebbc:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
}

// Symbol: reserveFileDescriptor
// PAL: 0x8019ebd8..0x8019ec2c
MARK_BINARY_BLOB(reserveFileDescriptor, 0x8019ebd8, 0x8019ec2c);
asm UNKNOWN_FUNCTION(reserveFileDescriptor) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lwz r0, _unk_80385a60;
  cmpwi r0, -255;
  bne lbl_8019ec08;
  li r0, -254;
  li r31, 0;
  stw r0, _unk_80385a60;
  b lbl_8019ec0c;
lbl_8019ec08:
  li r31, 1;
lbl_8019ec0c:
  bl OSRestoreInterrupts;
  cntlzw r0, r31;
  lwz r31, 0xc(r1);
  srwi r3, r0, 5;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: NANDLoggingAddMessageAsync
// PAL: 0x8019ec2c..0x8019ed24
MARK_BINARY_BLOB(NANDLoggingAddMessageAsync, 0x8019ec2c, 0x8019ed24);
asm UNKNOWN_FUNCTION(NANDLoggingAddMessageAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  mr r31, r4;
  stw r30, 0x78(r1);
  mr r30, r3;
  bne cr1, lbl_8019ec6c;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_8019ec6c:
  stw r3, 8(r1);
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  bl reserveFileDescriptor;
  cmpwi r3, 0;
  bne lbl_8019eca0;
  li r3, 0;
  b lbl_8019ed0c;
lbl_8019eca0:
  addi r4, r1, 0x88;
  addi r0, r1, 8;
  lis r5, 0x200;
  lis r3, 0x8034;
  stw r5, 0x68(r1);
  addi r6, r1, 0x68;
  mr r5, r31;
  addi r3, r3, 0x6d80;
  stw r4, 0x6c(r1);
  li r4, 0x100;
  stw r0, 0x70(r1);
  bl vsnprintf;
  li r0, 1;
  lis r3, _unk_8028ec20@ha;
  lis r5, 0x801a;
  stw r30, _unk_80386850;
  la r3, _unk_8028ec20@l(r3);
  li r4, 3;
  stw r0, _unk_80386854;
  addi r5, r5, -4828;
  li r6, 0;
  bl ISFS_OpenAsync;
  cmpwi r3, 0;
  bne lbl_8019ed08;
  li r3, 1;
  b lbl_8019ed0c;
lbl_8019ed08:
  li r3, 0;
lbl_8019ed0c:
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: asyncRoutine
// PAL: 0x8019ed24..0x8019f1a8
MARK_BINARY_BLOB(asyncRoutine, 0x8019ed24, 0x8019f1a8);
asm UNKNOWN_FUNCTION(asyncRoutine) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  mr r31, r3;
  stw r30, 0x88(r1);
  lis r30, 0x8034;
  addi r30, r30, 0x6d80;
  lwz r4, _unk_80386854;
  addi r0, r4, 1;
  cmpwi r0, 2;
  stw r0, _unk_80386854;
  bne lbl_8019edbc;
  cmpwi r3, 0;
  blt lbl_8019eda0;
  lis r6, 0x801a;
  stw r3, _unk_80385a60;
  addi r6, r6, -4828;
  li r4, 0;
  li r5, 0;
  li r7, 0;
  bl ISFS_SeekAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019eda0:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019edbc:
  cmpwi r0, 3;
  bne lbl_8019ee28;
  cmpwi r3, 0;
  bne lbl_8019ee0c;
  lis r6, 0x801a;
  lwz r3, _unk_80385a60;
  addi r4, r30, 0x100;
  li r5, 0x100;
  addi r6, r6, -4828;
  li r7, 0;
  bl ISFS_ReadAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee0c:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee28:
  cmpwi r0, 4;
  bne lbl_8019ee94;
  cmpwi r3, 0x100;
  bne lbl_8019ee78;
  lis r6, 0x801a;
  lwz r3, _unk_80385a60;
  addi r6, r6, -4828;
  li r4, 0;
  li r5, 0;
  li r7, 0;
  bl ISFS_SeekAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee78:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee94:
  cmpwi r0, 5;
  bne lbl_8019eff0;
  cmpwi r3, 0;
  bne lbl_8019efd4;
  addi r3, r30, 0x100;
  li r0, 0;
  stb r0, 0xff(r3);
  bl atoi;
  mr r31, r3;
  addi r3, r30, 0x200;
  li r4, 0x20;
  li r5, 0xfe;
  bl memset;
  bl OSGetTime;
  addi r5, r1, 0x58;
  bl OSTicksToCalendarTime;
  bl nandGetHomeDir;
  mr r4, r3;
  addi r3, r1, 0x18;
  addi r4, r4, 7;
  li r5, 0x11;
  bl strncpy;
  li r0, 0x2d;
  li r4, 0;
  stb r4, 0x29(r1);
  lis r3, 0x8208;
  lis r5, 0x8029;
  addi r4, r1, 0x18;
  stb r0, 0x20(r1);
  addi r0, r3, 0x2083;
  lwz r3, 0x5c(r1);
  mulhw r0, r0, r31;
  addi r6, r30, 0;
  stw r3, 8(r1);
  addi r5, r5, -5060;
  lwz r3, 0x58(r1);
  add r0, r0, r31;
  stw r3, 0xc(r1);
  srawi r0, r0, 5;
  addi r3, r30, 0x200;
  stw r4, 0x10(r1);
  srwi r4, r0, 0x1f;
  add r0, r0, r4;
  stw r6, 0x14(r1);
  mulli r0, r0, 0x3f;
  li r4, 0x100;
  lwz r8, 0x68(r1);
  subf r6, r0, r31;
  lwz r7, 0x6c(r1);
  lwz r9, 0x64(r1);
  addi r6, r6, 1;
  lwz r10, 0x60(r1);
  addi r8, r8, 1;
  crclr 6;
  bl snprintf;
  cmpwi r3, 0x100;
  bge lbl_8019ef84;
  addi r4, r30, 0x200;
  li r0, 0x20;
  stbx r0, r4, r3;
lbl_8019ef84:
  addi r4, r30, 0x200;
  li r3, 0xd;
  li r0, 0xa;
  lis r6, 0x801a;
  stb r3, 0xfe(r4);
  addi r6, r6, -4828;
  lwz r3, _unk_80385a60;
  li r5, 0x100;
  stb r0, 0xff(r4);
  li r7, 0;
  bl ISFS_WriteAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019efd4:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019eff0:
  cmpwi r0, 6;
  bne lbl_8019f068;
  cmpwi r3, 0x100;
  bne lbl_8019f04c;
  addi r3, r30, 0x100;
  bl atoi;
  mr r0, r3;
  lis r6, 0x801a;
  lwz r3, _unk_80385a60;
  slwi r4, r0, 8;
  addi r6, r6, -4828;
  li r5, 0;
  li r7, 0;
  bl ISFS_SeekAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f04c:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f068:
  cmpwi r0, 7;
  bne lbl_8019f0e0;
  addi r3, r30, 0x100;
  bl atoi;
  slwi r0, r3, 8;
  cmpw r31, r0;
  bne lbl_8019f0c4;
  lis r6, 0x801a;
  lwz r3, _unk_80385a60;
  addi r4, r30, 0x200;
  li r5, 0x100;
  addi r6, r6, -4828;
  li r7, 0;
  bl ISFS_WriteAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f0c4:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f0e0:
  cmpwi r0, 8;
  bne lbl_8019f144;
  cmpwi r3, 0x100;
  bne lbl_8019f128;
  lis r4, 0x801a;
  lwz r3, _unk_80385a60;
  addi r4, r4, -4828;
  li r5, 0;
  bl ISFS_CloseAsync;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f128:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f144:
  cmpwi r0, 9;
  bne lbl_8019f190;
  cmpwi r3, 0;
  bne lbl_8019f178;
  lwz r12, _unk_80386850;
  li r0, -255;
  stw r0, _unk_80385a60;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 1;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f178:
  lwz r12, _unk_80386850;
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8019f190:
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  lwz r30, 0x88(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}
