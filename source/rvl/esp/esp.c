#include "esp.h"

#include <rvl/ipc/ipcclt.h>

static s32 unk_80385908 = -1;
static char esp_path_[] = "/dev/es";

// Symbol: ESP_InitLib
// PAL: 0x801671d0..0x80167224
MARK_BINARY_BLOB(ESP_InitLib, 0x801671d0, 0x80167224);
asm UNKNOWN_FUNCTION(ESP_InitLib) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  lwz r0, unk_80385908;
  cmpwi r0, 0;
  bge lbl_8016720c;
  la r3, esp_path_;
  li r4, 0;
  bl IOS_Open;
  cmpwi r3, 0;
  stw r3, unk_80385908;
  bge lbl_8016720c;
  mr r31, r3;
lbl_8016720c:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ESP_CloseLib
// PAL: 0x80167224..0x8016726c
MARK_BINARY_BLOB(ESP_CloseLib, 0x80167224, 0x8016726c);
asm UNKNOWN_FUNCTION(ESP_CloseLib) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  stw r0, 0x14(r1);
  lwz r3, unk_80385908;
  cmpwi r3, 0;
  blt lbl_80167258;
  bl IOS_Close;
  cmpwi r3, 0;
  mr r4, r3;
  bne lbl_80167258;
  li r0, -1;
  stw r0, unk_80385908;
lbl_80167258:
  lwz r0, 0x14(r1);
  mr r3, r4;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ESP_LaunchTitle
// PAL: 0x8016726c..0x80167300
MARK_BINARY_BLOB(ESP_LaunchTitle, 0x8016726c, 0x80167300);
asm UNKNOWN_FUNCTION(ESP_LaunchTitle) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -288;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r10, r1, 0x20;
  lwz r9, unk_80385908;
  cmpwi r9, 0;
  bge lbl_801672a0;
  li r3, -1017;
  b lbl_801672ec;
lbl_801672a0:
  clrlwi. r0, r5, 0x1b;
  beq lbl_801672b0;
  li r3, -1017;
  b lbl_801672ec;
lbl_801672b0:
  li r8, 8;
  li r0, 0xd8;
  stw r4, 0x24(r1);
  li r4, 8;
  li r6, 0;
  stw r3, 0x20(r1);
  mr r3, r9;
  stw r5, 0xf8(r1);
  li r5, 2;
  stw r10, 0xf0(r1);
  stw r8, 0xf4(r1);
  stw r0, 0xfc(r1);
  bl IOS_IoctlvReboot;
  li r0, -1;
  stw r0, unk_80385908;
lbl_801672ec:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_ReadContentFile
// PAL: 0x80167300..0x801673a0
MARK_BINARY_BLOB(ESP_ReadContentFile, 0x80167300, 0x801673a0);
asm UNKNOWN_FUNCTION(ESP_ReadContentFile) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -288;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r8, r1, 0x20;
  lwz r6, unk_80385908;
  cmpwi r6, 0;
  blt lbl_80167348;
  cmpwi r3, 0;
  blt lbl_80167348;
  li r0, 0;
  cmplw r4, r0;
  beq lbl_80167348;
  cmpwi r5, 0;
  bne lbl_80167350;
lbl_80167348:
  li r3, -1017;
  b lbl_8016738c;
lbl_80167350:
  clrlwi. r0, r4, 0x1b;
  beq lbl_80167360;
  li r3, -1017;
  b lbl_8016738c;
lbl_80167360:
  li r0, 4;
  stw r3, 0x20(r1);
  mr r3, r6;
  li r6, 1;
  stw r4, 0xf8(r1);
  li r4, 0xa;
  stw r5, 0xfc(r1);
  li r5, 1;
  stw r8, 0xf0(r1);
  stw r0, 0xf4(r1);
  bl IOS_Ioctlv;
lbl_8016738c:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_SeekContentFile
// PAL: 0x801673a0..0x8016742c
MARK_BINARY_BLOB(ESP_SeekContentFile, 0x801673a0, 0x8016742c);
asm UNKNOWN_FUNCTION(ESP_SeekContentFile) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -288;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r8, r1, 0x20;
  addi r9, r1, 0x40;
  lwz r6, unk_80385908;
  addi r10, r1, 0x60;
  cmpwi r6, 0;
  bge lbl_801673dc;
  li r3, -1017;
  b lbl_80167418;
lbl_801673dc:
  li r0, 4;
  stw r3, 0x20(r1);
  mr r3, r6;
  li r6, 0;
  stw r4, 0x40(r1);
  li r4, 0x23;
  stw r5, 0x60(r1);
  li r5, 3;
  stw r8, 0xf0(r1);
  stw r0, 0xf4(r1);
  stw r9, 0xf8(r1);
  stw r0, 0xfc(r1);
  stw r10, 0x100(r1);
  stw r0, 0x104(r1);
  bl IOS_Ioctlv;
lbl_80167418:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_ListTitleContentsOnCard
// PAL: 0x8016742c..0x80167544
MARK_BINARY_BLOB(ESP_ListTitleContentsOnCard, 0x8016742c, 0x80167544);
asm UNKNOWN_FUNCTION(ESP_ListTitleContentsOnCard) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r11, r1, 0x20;
  stw r31, -4(r12);
  mr r31, r6;
  addi r12, r1, 0x40;
  lwz r10, unk_80385908;
  cmpwi r10, 0;
  blt lbl_80167470;
  li r8, 0;
  cmplw r6, r8;
  bne lbl_80167478;
lbl_80167470:
  li r3, -1017;
  b lbl_8016752c;
lbl_80167478:
  clrlwi. r0, r5, 0x1b;
  beq lbl_80167488;
  li r3, -1017;
  b lbl_8016752c;
lbl_80167488:
  cmplw r5, r8;
  stw r4, 0x24(r1);
  stw r3, 0x20(r1);
  bne lbl_801674d8;
  li r5, 8;
  li r0, 4;
  stw r5, 0xf4(r1);
  mr r3, r10;
  li r4, 0x10;
  li r5, 1;
  stw r11, 0xf0(r1);
  li r6, 1;
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  bne lbl_8016752c;
  lwz r0, 0x40(r1);
  stw r0, 0(r31);
  b lbl_8016752c;
lbl_801674d8:
  lwz r9, 0(r6);
  cmpwi r9, 0;
  bne lbl_801674ec;
  li r3, -1017;
  b lbl_8016752c;
lbl_801674ec:
  li r8, 8;
  li r0, 4;
  stw r5, 0x100(r1);
  mr r3, r10;
  li r4, 0x11;
  li r5, 2;
  stw r9, 0x40(r1);
  stw r11, 0xf0(r1);
  stw r8, 0xf4(r1);
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  lwz r0, 0(r6);
  li r6, 1;
  slwi r0, r0, 2;
  stw r0, 0x104(r1);
  bl IOS_Ioctlv;
lbl_8016752c:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_GetTicketViews
// PAL: 0x80167544..0x8016765c
MARK_BINARY_BLOB(ESP_GetTicketViews, 0x80167544, 0x8016765c);
asm UNKNOWN_FUNCTION(ESP_GetTicketViews) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r11, r1, 0x20;
  stw r31, -4(r12);
  mr r31, r6;
  addi r12, r1, 0x40;
  lwz r10, unk_80385908;
  cmpwi r10, 0;
  blt lbl_80167588;
  li r8, 0;
  cmplw r6, r8;
  bne lbl_80167590;
lbl_80167588:
  li r3, -1017;
  b lbl_80167644;
lbl_80167590:
  clrlwi. r0, r5, 0x1b;
  beq lbl_801675a0;
  li r3, -1017;
  b lbl_80167644;
lbl_801675a0:
  cmplw r5, r8;
  stw r4, 0x24(r1);
  stw r3, 0x20(r1);
  bne lbl_801675f0;
  li r5, 8;
  li r0, 4;
  stw r5, 0xf4(r1);
  mr r3, r10;
  li r4, 0x12;
  li r5, 1;
  stw r11, 0xf0(r1);
  li r6, 1;
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  bne lbl_80167644;
  lwz r0, 0x40(r1);
  stw r0, 0(r31);
  b lbl_80167644;
lbl_801675f0:
  lwz r9, 0(r6);
  cmpwi r9, 0;
  bne lbl_80167604;
  li r3, -1017;
  b lbl_80167644;
lbl_80167604:
  li r8, 8;
  li r0, 4;
  stw r5, 0x100(r1);
  mr r3, r10;
  li r4, 0x13;
  li r5, 2;
  stw r9, 0x40(r1);
  stw r11, 0xf0(r1);
  stw r8, 0xf4(r1);
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  lwz r0, 0(r6);
  li r6, 1;
  mulli r0, r0, 0xd8;
  stw r0, 0x104(r1);
  bl IOS_Ioctlv;
lbl_80167644:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_DiGetTicketView
// PAL: 0x8016765c..0x80167700
MARK_BINARY_BLOB(ESP_DiGetTicketView, 0x8016765c, 0x80167700);
asm UNKNOWN_FUNCTION(ESP_DiGetTicketView) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -288;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  lwz r0, unk_80385908;
  cmpwi r0, 0;
  blt lbl_80167690;
  li r5, 0;
  cmplw r4, r5;
  bne lbl_80167698;
lbl_80167690:
  li r3, -1017;
  b lbl_801676ec;
lbl_80167698:
  clrlwi. r0, r3, 0x1b;
  bne lbl_801676a8;
  clrlwi. r0, r4, 0x1b;
  beq lbl_801676b0;
lbl_801676a8:
  li r3, -1017;
  b lbl_801676ec;
lbl_801676b0:
  cmplw r3, r5;
  stw r3, 0xf0(r1);
  bne lbl_801676c4;
  stw r5, 0xf4(r1);
  b lbl_801676cc;
lbl_801676c4:
  li r0, 0x2a4;
  stw r0, 0xf4(r1);
lbl_801676cc:
  li r0, 0xd8;
  stw r4, 0xf8(r1);
  lwz r3, unk_80385908;
  li r4, 0x1b;
  stw r0, 0xfc(r1);
  li r5, 1;
  li r6, 1;
  bl IOS_Ioctlv;
lbl_801676ec:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_DiGetTmd
// PAL: 0x80167700..0x801677f0
MARK_BINARY_BLOB(ESP_DiGetTmd, 0x80167700, 0x801677f0);
asm UNKNOWN_FUNCTION(ESP_DiGetTmd) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r8, r1, 0x20;
  stw r31, -4(r12);
  mr r31, r4;
  lwz r6, unk_80385908;
  cmpwi r6, 0;
  blt lbl_80167740;
  li r5, 0;
  cmplw r4, r5;
  bne lbl_80167748;
lbl_80167740:
  li r3, -1017;
  b lbl_801677d8;
lbl_80167748:
  clrlwi. r0, r3, 0x1b;
  beq lbl_80167758;
  li r3, -1017;
  b lbl_801677d8;
lbl_80167758:
  cmplw r3, r5;
  bne lbl_80167794;
  li r0, 4;
  mr r3, r6;
  stw r8, 0xf0(r1);
  li r4, 0x39;
  li r5, 0;
  li r6, 1;
  stw r0, 0xf4(r1);
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  bne lbl_801677d8;
  lwz r0, 0x20(r1);
  stw r0, 0(r31);
  b lbl_801677d8;
lbl_80167794:
  lwz r5, 0(r4);
  cmpwi r5, 0;
  bne lbl_801677a8;
  li r3, -1017;
  b lbl_801677d8;
lbl_801677a8:
  li r0, 4;
  stw r3, 0xf8(r1);
  mr r3, r6;
  li r6, 1;
  stw r5, 0x20(r1);
  li r5, 1;
  stw r8, 0xf0(r1);
  stw r0, 0xf4(r1);
  lwz r0, 0(r4);
  li r4, 0x3a;
  stw r0, 0xfc(r1);
  bl IOS_Ioctlv;
lbl_801677d8:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_GetTmdView
// PAL: 0x801677f0..0x80167904
MARK_BINARY_BLOB(ESP_GetTmdView, 0x801677f0, 0x80167904);
asm UNKNOWN_FUNCTION(ESP_GetTmdView) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r11, r1, 0x20;
  stw r31, -4(r12);
  mr r31, r6;
  addi r12, r1, 0x40;
  lwz r10, unk_80385908;
  cmpwi r10, 0;
  blt lbl_80167834;
  li r8, 0;
  cmplw r6, r8;
  bne lbl_8016783c;
lbl_80167834:
  li r3, -1017;
  b lbl_801678ec;
lbl_8016783c:
  clrlwi. r0, r5, 0x1b;
  beq lbl_8016784c;
  li r3, -1017;
  b lbl_801678ec;
lbl_8016784c:
  cmplw r5, r8;
  stw r4, 0x24(r1);
  stw r3, 0x20(r1);
  bne lbl_8016789c;
  li r5, 8;
  li r0, 4;
  stw r5, 0xf4(r1);
  mr r3, r10;
  li r4, 0x14;
  li r5, 1;
  stw r11, 0xf0(r1);
  li r6, 1;
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  bne lbl_801678ec;
  lwz r0, 0x40(r1);
  stw r0, 0(r31);
  b lbl_801678ec;
lbl_8016789c:
  lwz r9, 0(r6);
  cmpwi r9, 0;
  bne lbl_801678b0;
  li r3, -1017;
  b lbl_801678ec;
lbl_801678b0:
  li r8, 8;
  li r0, 4;
  stw r5, 0x100(r1);
  mr r3, r10;
  li r4, 0x15;
  li r5, 2;
  stw r9, 0x40(r1);
  stw r11, 0xf0(r1);
  stw r8, 0xf4(r1);
  stw r12, 0xf8(r1);
  stw r0, 0xfc(r1);
  lwz r0, 0(r6);
  li r6, 1;
  stw r0, 0x104(r1);
  bl IOS_Ioctlv;
lbl_801678ec:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_GetDataDir
// PAL: 0x80167904..0x8016799c
MARK_BINARY_BLOB(ESP_GetDataDir, 0x80167904, 0x8016799c);
asm UNKNOWN_FUNCTION(ESP_GetDataDir) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -288;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r10, r1, 0x20;
  lwz r9, unk_80385908;
  cmpwi r9, 0;
  blt lbl_8016793c;
  li r0, 0;
  cmplw r5, r0;
  bne lbl_80167944;
lbl_8016793c:
  li r3, -1017;
  b lbl_80167988;
lbl_80167944:
  clrlwi. r0, r5, 0x1b;
  beq lbl_80167954;
  li r3, -1017;
  b lbl_80167988;
lbl_80167954:
  li r8, 8;
  li r0, 0x1e;
  stw r4, 0x24(r1);
  li r4, 0x1d;
  li r6, 1;
  stw r3, 0x20(r1);
  mr r3, r9;
  stw r5, 0xf8(r1);
  li r5, 1;
  stw r10, 0xf0(r1);
  stw r8, 0xf4(r1);
  stw r0, 0xfc(r1);
  bl IOS_Ioctlv;
lbl_80167988:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_GetTitleId
// PAL: 0x8016799c..0x80167a34
MARK_BINARY_BLOB(ESP_GetTitleId, 0x8016799c, 0x80167a34);
asm UNKNOWN_FUNCTION(ESP_GetTitleId) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  stw r31, -4(r12);
  mr r31, r3;
  lwz r4, unk_80385908;
  cmpwi r4, 0;
  blt lbl_801679d8;
  li r0, 0;
  cmplw r3, r0;
  bne lbl_801679e0;
lbl_801679d8:
  li r3, -1017;
  b lbl_80167a1c;
lbl_801679e0:
  addi r3, r1, 0x20;
  li r0, 8;
  stw r3, 0xf0(r1);
  mr r3, r4;
  li r4, 0x20;
  li r5, 0;
  stw r0, 0xf4(r1);
  li r6, 1;
  bl IOS_Ioctlv;
  cmpwi r3, 0;
  bne lbl_80167a1c;
  lwz r0, 0x20(r1);
  lwz r4, 0x24(r1);
  stw r4, 4(r31);
  stw r0, 0(r31);
lbl_80167a1c:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}

// Symbol: ESP_GetConsumption
// PAL: 0x80167a34..0x80167b08
MARK_BINARY_BLOB(ESP_GetConsumption, 0x80167a34, 0x80167b08);
asm UNKNOWN_FUNCTION(ESP_GetConsumption) {
  // clang-format off
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -320;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  addi r7, r1, 0xf0;
  addi r9, r1, 0x20;
  addi r10, r1, 0x40;
  stw r31, -4(r12);
  mr r31, r6;
  lwz r0, unk_80385908;
  cmpwi r0, 0;
  bge lbl_80167a74;
  li r3, -1017;
  b lbl_80167af0;
lbl_80167a74:
  clrlwi. r0, r5, 0x1b;
  beq lbl_80167a84;
  li r3, -1017;
  b lbl_80167af0;
lbl_80167a84:
  li r0, 0;
  li r8, 8;
  cmplw r5, r0;
  stw r4, 0x24(r1);
  stw r3, 0x20(r1);
  stw r9, 0xf0(r1);
  stw r8, 0xf4(r1);
  bne lbl_80167ab0;
  stw r0, 0xf8(r1);
  stw r0, 0xfc(r1);
  b lbl_80167ac8;
lbl_80167ab0:
  stw r5, 0xf8(r1);
  lwz r0, 0(r6);
  slwi r0, r0, 3;
  stw r0, 0xfc(r1);
  lwz r0, 0(r6);
  stw r0, 0x40(r1);
lbl_80167ac8:
  li r0, 4;
  stw r10, 0x100(r1);
  lwz r3, unk_80385908;
  li r4, 0x16;
  stw r0, 0x104(r1);
  li r5, 1;
  li r6, 2;
  bl IOS_Ioctlv;
  lwz r0, 0x40(r1);
  stw r0, 0(r31);
lbl_80167af0:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  mtlr r0;
  mr r1, r10;
  blr;
  // clang-format on
}
