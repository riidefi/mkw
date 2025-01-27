#include "osFont.h"

// Extern function references.
// PAL: 0x801a90c4
extern UNKNOWN_FUNCTION(__OSReadROM);
// PAL: 0x801ab410
extern UNKNOWN_FUNCTION(OSUTF8to32);
// PAL: 0x801ab520
extern UNKNOWN_FUNCTION(OSUTF16to32);
// PAL: 0x801ab590
extern UNKNOWN_FUNCTION(OSUTF32toANSI);
// PAL: 0x801ab608
extern UNKNOWN_FUNCTION(OSUTF32toSJIS);

// Symbol: GetFontCode
// PAL: 0x801a56dc..0x801a5810
MARK_BINARY_BLOB(GetFontCode, 0x801a56dc, 0x801a5810);
asm UNKNOWN_FUNCTION(GetFontCode) {
  // clang-format off
  nofralloc;
  cmplwi r3, 1;
  bne lbl_801a57f0;
  cmplwi r4, 0x20;
  blt lbl_801a570c;
  cmplwi r4, 0xdf;
  bgt lbl_801a570c;
  addi r0, r4, -32;
  lis r3, 0x8029;
  slwi r0, r0, 1;
  addi r3, r3, -1296;
  lhzx r3, r3, r0;
  blr;
lbl_801a570c:
  cmplwi r4, 0x889e;
  ble lbl_801a5778;
  cmplwi r4, 0x9872;
  bgt lbl_801a5778;
  rlwinm r3, r4, 0x18, 0x18, 0x1f;
  clrlwi r4, r4, 0x18;
  addi r3, r3, -136;
  li r0, 0;
  cmplwi r4, 0x40;
  mulli r3, r3, 0xbc;
  blt lbl_801a574c;
  cmplwi r4, 0xfc;
  bgt lbl_801a574c;
  cmplwi r4, 0x7f;
  beq lbl_801a574c;
  li r0, 1;
lbl_801a574c:
  cmpwi r0, 0;
  bne lbl_801a575c;
  li r3, 0;
  blr;
lbl_801a575c:
  addi r4, r4, -64;
  cmpwi r4, 0x40;
  blt lbl_801a576c;
  addi r4, r4, -1;
lbl_801a576c:
  add r3, r3, r4;
  addi r3, r3, 0x2be;
  blr;
lbl_801a5778:
  cmplwi r4, 0x8140;
  blt lbl_801a5808;
  cmplwi r4, 0x879e;
  bge lbl_801a5808;
  rlwinm r3, r4, 0x18, 0x18, 0x1f;
  clrlwi r4, r4, 0x18;
  addi r3, r3, -129;
  li r0, 0;
  cmplwi r4, 0x40;
  mulli r3, r3, 0xbc;
  blt lbl_801a57b8;
  cmplwi r4, 0xfc;
  bgt lbl_801a57b8;
  cmplwi r4, 0x7f;
  beq lbl_801a57b8;
  li r0, 1;
lbl_801a57b8:
  cmpwi r0, 0;
  bne lbl_801a57c8;
  li r3, 0;
  blr;
lbl_801a57c8:
  addi r4, r4, -64;
  cmpwi r4, 0x40;
  blt lbl_801a57d8;
  addi r4, r4, -1;
lbl_801a57d8:
  add r0, r3, r4;
  lis r3, 0x8029;
  slwi r0, r0, 1;
  addi r3, r3, -912;
  lhzx r3, r3, r0;
  blr;
lbl_801a57f0:
  cmplwi r4, 0x20;
  ble lbl_801a5808;
  cmplwi r4, 0xff;
  bgt lbl_801a5808;
  addi r3, r4, -32;
  blr;
lbl_801a5808:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: Decode
// PAL: 0x801a5810..0x801a59b4
MARK_BINARY_BLOB(Decode, 0x801a5810, 0x801a59b4);
asm UNKNOWN_FUNCTION(Decode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lwz r5, 0xc(r3);
  addi r30, r3, 0x10;
  lwz r0, 4(r3);
  li r8, 0;
  add r29, r3, r5;
  lwz r9, 8(r3);
  li r11, 0;
  lis r5, 0x8000;
lbl_801a5844:
  cmpwi r11, 0;
  bne lbl_801a5858;
  lwz r12, 0(r30);
  li r11, 0x20;
  addi r30, r30, 4;
lbl_801a5858:
  rlwinm. r6, r12, 0, 0, 0;
  beq lbl_801a5874;
  lbz r6, 0(r29);
  addi r29, r29, 1;
  stbx r6, r4, r8;
  addi r8, r8, 1;
  b lbl_801a598c;
lbl_801a5874:
  add r7, r3, r9;
  lbzx r6, r3, r9;
  lbz r7, 1(r7);
  addi r9, r9, 2;
  rlwimi r7, r6, 8, 0x10, 0x17;
  srawi. r10, r7, 0xc;
  clrlwi r6, r7, 0x14;
  subf r7, r6, r8;
  bne lbl_801a58a8;
  lbz r6, 0(r29);
  addi r29, r29, 1;
  addi r10, r6, 0x12;
  b lbl_801a58ac;
lbl_801a58a8:
  addi r10, r10, 2;
lbl_801a58ac:
  cmpwi cr1, r10, 0;
  li r6, 0;
  ble cr1, lbl_801a598c;
  cmpwi r10, 8;
  addi r27, r10, -8;
  ble lbl_801a5958;
  li r28, 0;
  blt cr1, lbl_801a58dc;
  addi r26, r5, -2;
  cmpw r10, r26;
  bgt lbl_801a58dc;
  li r28, 1;
lbl_801a58dc:
  cmpwi r28, 0;
  beq lbl_801a5958;
  addi r31, r27, 7;
  add r28, r4, r8;
  srwi r31, r31, 3;
  mtctr r31;
  cmpwi r27, 0;
  ble lbl_801a5958;
lbl_801a58fc:
  add r26, r4, r7;
  add r27, r8, r4;
  lbz r31, -1(r26);
  addi r8, r8, 8;
  addi r6, r6, 8;
  stb r31, 0(r28);
  addi r28, r28, 8;
  lbzx r31, r4, r7;
  addi r7, r7, 8;
  stb r31, 1(r27);
  lbz r31, 1(r26);
  stb r31, 2(r27);
  lbz r31, 2(r26);
  stb r31, 3(r27);
  lbz r31, 3(r26);
  stb r31, 4(r27);
  lbz r31, 4(r26);
  stb r31, 5(r27);
  lbz r31, 5(r26);
  stb r31, 6(r27);
  lbz r31, 6(r26);
  stb r31, 7(r27);
  bdnz lbl_801a58fc;
lbl_801a5958:
  subf r31, r6, r10;
  add r28, r4, r8;
  mtctr r31;
  cmpw r6, r10;
  bge lbl_801a598c;
lbl_801a596c:
  add r10, r4, r7;
  addi r6, r6, 1;
  lbz r10, -1(r10);
  addi r8, r8, 1;
  addi r7, r7, 1;
  stb r10, 0(r28);
  addi r28, r28, 1;
  bdnz lbl_801a596c;
lbl_801a598c:
  cmpw r8, r0;
  slwi r12, r12, 1;
  addi r11, r11, -1;
  blt lbl_801a5844;
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSSetFontEncode
// PAL: 0x801a59b4..0x801a5a34
MARK_BINARY_BLOB(OSSetFontEncode, 0x801a59b4, 0x801a5a34);
asm UNKNOWN_FUNCTION(OSSetFontEncode) {
  // clang-format off
  nofralloc;
  lhz r0, -0x7130(r13);
  cmplwi r0, 0xffff;
  beq lbl_801a59c4;
  b lbl_801a5a08;
lbl_801a59c4:
  lis r4, 0x8000;
  lwz r0, 0xcc(r4);
  cmpwi r0, 0;
  beq lbl_801a59dc;
  blt lbl_801a59f0;
  b lbl_801a59f0;
lbl_801a59dc:
  lis r4, 0xcc00;
  lhz r0, 0x206e(r4);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  sth r0, -0x7130(r13);
  b lbl_801a59f8;
lbl_801a59f0:
  li r0, 0;
  sth r0, -0x7130(r13);
lbl_801a59f8:
  lis r4, 0x801a;
  clrlwi r0, r0, 0x10;
  addi r4, r4, 0x5e5c;
  stw r4, -0x6328(r13);
lbl_801a5a08:
  cmplwi cr1, r3, 5;
  bgt cr1, lbl_801a5a2c;
  cmplwi r3, 3;
  sth r3, -0x7130(r13);
  blt lbl_801a5a2c;
  bgt cr1, lbl_801a5a2c;
  lis r3, 0x801a;
  addi r3, r3, 0x5f58;
  stw r3, -0x6328(r13);
lbl_801a5a2c:
  mr r3, r0;
  blr;
  // clang-format on
}

// Symbol: ReadFont
// PAL: 0x801a5a34..0x801a5d34
MARK_BINARY_BLOB(ReadFont, 0x801a5a34, 0x801a5d34);
asm UNKNOWN_FUNCTION(ReadFont) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmplwi r4, 1;
  mr r28, r3;
  mr r29, r4;
  mr r26, r5;
  bne lbl_801a5ab4;
  lis r4, 0x1b;
  lis r3, 5;
  mr r27, r28;
  addi r31, r4, -256;
  addi r30, r3, -12288;
  b lbl_801a5aa8;
lbl_801a5a74:
  cmpwi r30, 0x100;
  li r25, 0x100;
  bgt lbl_801a5a84;
  mr r25, r30;
lbl_801a5a84:
  subf r30, r25, r30;
lbl_801a5a88:
  mr r3, r27;
  mr r4, r25;
  mr r5, r31;
  bl __OSReadROM;
  cmpwi r3, 0;
  beq lbl_801a5a88;
  add r31, r31, r25;
  add r27, r27, r25;
lbl_801a5aa8:
  cmpwi r30, 0;
  bgt lbl_801a5a74;
  b lbl_801a5b04;
lbl_801a5ab4:
  lis r3, 0x20;
  mr r27, r28;
  addi r31, r3, -12544;
  li r30, 0x3000;
  b lbl_801a5afc;
lbl_801a5ac8:
  cmpwi r30, 0x100;
  li r25, 0x100;
  bgt lbl_801a5ad8;
  mr r25, r30;
lbl_801a5ad8:
  subf r30, r25, r30;
lbl_801a5adc:
  mr r3, r27;
  mr r4, r25;
  mr r5, r31;
  bl __OSReadROM;
  cmpwi r3, 0;
  beq lbl_801a5adc;
  add r31, r31, r25;
  add r27, r27, r25;
lbl_801a5afc:
  cmpwi r30, 0;
  bgt lbl_801a5ac8;
lbl_801a5b04:
  lbz r0, 0(r28);
  cmplwi r0, 0x59;
  bne lbl_801a5b30;
  lbz r0, 1(r28);
  cmplwi r0, 0x61;
  bne lbl_801a5b30;
  lbz r0, 2(r28);
  cmplwi r0, 0x79;
  bne lbl_801a5b30;
  lwz r27, 4(r28);
  b lbl_801a5b34;
lbl_801a5b30:
  li r27, 0;
lbl_801a5b34:
  cmpwi r27, 0;
  bne lbl_801a5b44;
  li r3, 0;
  b lbl_801a5d1c;
lbl_801a5b44:
  mr r3, r28;
  mr r4, r26;
  bl Decode;
  cmplwi r29, 1;
  bne lbl_801a5d18;
  mr r3, r29;
  lhz r28, -0x6688(r2);
  lhz r29, -0x6686(r2);
  li r4, 0x54;
  lhz r30, -0x6684(r2);
  lhz r31, -0x6682(r2);
  bl GetFontCode;
  lhz r9, 0x1a(r26);
  lhz r4, 0x1c(r26);
  lhz r0, 0x1e(r26);
  mullw r10, r9, r4;
  lwz r5, 0x24(r26);
  rlwinm r4, r0, 2, 0, 0x1a;
  lhz r6, 0x12(r26);
  rlwinm r0, r0, 3, 0x1f, 0x1f;
  lhz r7, 0x10(r26);
  divw r12, r3, r10;
  add r0, r0, r4;
  add r4, r26, r5;
  lwz r8, 0x14(r26);
  srawi r11, r0, 1;
  mullw r0, r12, r10;
  subf r3, r0, r3;
  divw r5, r3, r9;
  mullw r0, r5, r9;
  mullw r5, r5, r6;
  subf r25, r0, r3;
  addi r6, r5, 4;
  mullw r25, r25, r7;
  addi r10, r5, 5;
  srawi r3, r6, 3;
  slwi r0, r6, 0x1d;
  addze r9, r3;
  srwi r7, r6, 0x1f;
  mullw r12, r12, r8;
  srawi r3, r25, 3;
  subf r0, r7, r0;
  addze r8, r3;
  rotlwi r3, r0, 3;
  slwi r0, r25, 0x1d;
  srwi r6, r25, 0x1f;
  srwi r12, r12, 1;
  mullw r9, r11, r9;
  add r7, r3, r7;
  subf r0, r6, r0;
  add r4, r4, r12;
  rotlwi r3, r0, 3;
  slwi r0, r8, 4;
  add r3, r3, r6;
  add r9, r4, r9;
  slwi r8, r7, 1;
  slwi r6, r10, 0x1d;
  srawi r3, r3, 2;
  add r9, r9, r0;
  add r9, r9, r8;
  srwi r7, r10, 0x1f;
  addze r3, r3;
  addi r8, r5, 6;
  sthx r28, r9, r3;
  subf r6, r7, r6;
  rotlwi r6, r6, 3;
  add r6, r6, r7;
  lhz r11, 0x1e(r26);
  slwi r9, r6, 1;
  srwi r7, r8, 0x1f;
  rlwinm r12, r11, 2, 0, 0x1a;
  rlwinm r11, r11, 3, 0x1f, 0x1f;
  add r11, r11, r12;
  slwi r6, r8, 0x1d;
  srawi r11, r11, 1;
  srawi r10, r10, 3;
  subf r6, r7, r6;
  addze r10, r10;
  rotlwi r6, r6, 3;
  add r6, r6, r7;
  mullw r10, r11, r10;
  slwi r6, r6, 1;
  add r7, r4, r10;
  add r7, r7, r0;
  add r7, r7, r9;
  sthx r29, r7, r3;
  lhz r7, 0x1e(r26);
  rlwinm r9, r7, 2, 0, 0x1a;
  rlwinm r7, r7, 3, 0x1f, 0x1f;
  add r7, r7, r9;
  srawi r9, r7, 1;
  srawi r7, r8, 3;
  addze r7, r7;
  mullw r7, r9, r7;
  add r7, r4, r7;
  add r7, r7, r0;
  add r7, r7, r6;
  sthx r30, r7, r3;
  addi r7, r5, 7;
  slwi r5, r7, 0x1d;
  lhz r8, 0x1e(r26);
  srwi r6, r7, 0x1f;
  subf r5, r6, r5;
  rlwinm r9, r8, 2, 0, 0x1a;
  rlwinm r8, r8, 3, 0x1f, 0x1f;
  add r8, r8, r9;
  rotlwi r5, r5, 3;
  srawi r8, r8, 1;
  srawi r7, r7, 3;
  add r5, r5, r6;
  addze r6, r7;
  mullw r6, r8, r6;
  slwi r5, r5, 1;
  add r4, r4, r6;
  add r4, r4, r0;
  add r4, r4, r5;
  sthx r31, r4, r3;
lbl_801a5d18:
  mr r3, r27;
lbl_801a5d1c:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: OSLoadFont
// PAL: 0x801a5d34..0x801a5e5c
MARK_BINARY_BLOB(OSLoadFont, 0x801a5d34, 0x801a5e5c);
asm UNKNOWN_FUNCTION(OSLoadFont) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mr r5, r3;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  lhz r0, -0x7130(r13);
  cmplwi r0, 0xffff;
  beq lbl_801a5d60;
  b lbl_801a5da4;
lbl_801a5d60:
  lis r4, 0x8000;
  lwz r0, 0xcc(r4);
  cmpwi r0, 0;
  beq lbl_801a5d78;
  blt lbl_801a5d8c;
  b lbl_801a5d8c;
lbl_801a5d78:
  lis r4, 0xcc00;
  lhz r0, 0x206e(r4);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  sth r0, -0x7130(r13);
  b lbl_801a5d94;
lbl_801a5d8c:
  li r0, 0;
  sth r0, -0x7130(r13);
lbl_801a5d94:
  lis r4, 0x801a;
  clrlwi r0, r0, 0x10;
  addi r4, r4, 0x5e5c;
  stw r4, -0x6328(r13);
lbl_801a5da4:
  clrlwi r0, r0, 0x10;
  cmpwi r0, 2;
  beq lbl_801a5e3c;
  bge lbl_801a5dc4;
  cmpwi r0, 0;
  beq lbl_801a5dd0;
  bge lbl_801a5de8;
  b lbl_801a5e3c;
lbl_801a5dc4:
  cmpwi r0, 6;
  bge lbl_801a5e3c;
  b lbl_801a5e00;
lbl_801a5dd0:
  stw r3, -0x631c(r13);
  mr r3, r30;
  li r4, 0;
  bl ReadFont;
  mr r31, r3;
  b lbl_801a5e40;
lbl_801a5de8:
  stw r3, -0x6320(r13);
  mr r3, r30;
  li r4, 1;
  bl ReadFont;
  mr r31, r3;
  b lbl_801a5e40;
lbl_801a5e00:
  stw r3, -0x631c(r13);
  mr r3, r30;
  li r4, 0;
  bl ReadFont;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_801a5e40;
  lwz r0, -0x631c(r13);
  li r4, 1;
  add r5, r0, r3;
  mr r3, r30;
  stw r5, -0x6320(r13);
  bl ReadFont;
  add r31, r31, r3;
  b lbl_801a5e40;
lbl_801a5e3c:
  li r31, 0;
lbl_801a5e40:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ParseStringS
// PAL: 0x801a5e5c..0x801a5f58
MARK_BINARY_BLOB(ParseStringS, 0x801a5e5c, 0x801a5f58);
asm UNKNOWN_FUNCTION(ParseStringS) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 1;
  li r7, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r6;
  stw r30, 8(r1);
  mr r30, r4;
  beq lbl_801a5eac;
  bge lbl_801a5f2c;
  cmpwi r3, 0;
  bge lbl_801a5e94;
  b lbl_801a5f2c;
lbl_801a5e94:
  lbz r7, 0(r4);
  lwz r6, -0x631c(r13);
  cmpwi r7, 0;
  beq lbl_801a5f2c;
  addi r30, r4, 1;
  b lbl_801a5f2c;
lbl_801a5eac:
  lbz r7, 0(r4);
  lwz r6, -0x6320(r13);
  cmpwi r7, 0;
  beq lbl_801a5f2c;
  cmplwi r7, 0x81;
  addi r30, r4, 1;
  li r0, 0;
  blt lbl_801a5ed4;
  cmplwi r7, 0x9f;
  ble lbl_801a5ee4;
lbl_801a5ed4:
  cmplwi r7, 0xe0;
  blt lbl_801a5ee8;
  cmplwi r7, 0xfc;
  bgt lbl_801a5ee8;
lbl_801a5ee4:
  li r0, 1;
lbl_801a5ee8:
  cmpwi r0, 0;
  beq lbl_801a5f2c;
  lbz r4, 0(r30);
  li r0, 0;
  cmplwi r4, 0x40;
  blt lbl_801a5f14;
  cmplwi r4, 0xfc;
  bgt lbl_801a5f14;
  cmplwi r4, 0x7f;
  beq lbl_801a5f14;
  li r0, 1;
lbl_801a5f14:
  cmpwi r0, 0;
  beq lbl_801a5f2c;
  lbz r0, 0(r30);
  rlwimi r0, r7, 8, 8, 0x17;
  addi r30, r30, 1;
  clrlwi r7, r0, 0x10;
lbl_801a5f2c:
  stw r6, 0(r5);
  mr r4, r7;
  bl GetFontCode;
  stw r3, 0(r31);
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ParseStringW
// PAL: 0x801a5f58..0x801a6114
MARK_BINARY_BLOB(ParseStringW, 0x801a5f58, 0x801a6114);
asm UNKNOWN_FUNCTION(ParseStringW) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  li r30, 0;
  cmpwi r3, 3;
  stw r30, 8(r1);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  beq lbl_801a6054;
  bge lbl_801a5fa8;
  cmpwi r3, 1;
  beq lbl_801a5fd0;
  bge lbl_801a6090;
  cmpwi r3, 0;
  bge lbl_801a5fb8;
  b lbl_801a6090;
lbl_801a5fa8:
  cmpwi r3, 5;
  beq lbl_801a607c;
  bge lbl_801a6090;
  b lbl_801a6068;
lbl_801a5fb8:
  lbz r30, 0(r4);
  lwz r31, -0x631c(r13);
  cmpwi r30, 0;
  beq lbl_801a6090;
  addi r27, r4, 1;
  b lbl_801a6090;
lbl_801a5fd0:
  lbz r30, 0(r4);
  lwz r31, -0x6320(r13);
  cmpwi r30, 0;
  beq lbl_801a6090;
  cmplwi r30, 0x81;
  addi r27, r4, 1;
  li r0, 0;
  blt lbl_801a5ff8;
  cmplwi r30, 0x9f;
  ble lbl_801a6008;
lbl_801a5ff8:
  cmplwi r30, 0xe0;
  blt lbl_801a600c;
  cmplwi r30, 0xfc;
  bgt lbl_801a600c;
lbl_801a6008:
  li r0, 1;
lbl_801a600c:
  cmpwi r0, 0;
  beq lbl_801a6090;
  lbz r3, 0(r27);
  li r0, 0;
  cmplwi r3, 0x40;
  blt lbl_801a6038;
  cmplwi r3, 0xfc;
  bgt lbl_801a6038;
  cmplwi r3, 0x7f;
  beq lbl_801a6038;
  li r0, 1;
lbl_801a6038:
  cmpwi r0, 0;
  beq lbl_801a6090;
  lbz r0, 0(r27);
  rlwimi r0, r30, 8, 8, 0x17;
  addi r27, r27, 1;
  clrlwi r30, r0, 0x10;
  b lbl_801a6090;
lbl_801a6054:
  mr r3, r27;
  addi r4, r1, 8;
  bl OSUTF8to32;
  mr r27, r3;
  b lbl_801a6090;
lbl_801a6068:
  mr r3, r27;
  addi r4, r1, 8;
  bl OSUTF16to32;
  mr r27, r3;
  b lbl_801a6090;
lbl_801a607c:
  lwz r0, 0(r4);
  cmpwi r0, 0;
  stw r0, 8(r1);
  beq lbl_801a6090;
  addi r27, r4, 4;
lbl_801a6090:
  lwz r3, 8(r1);
  cmpwi r3, 0;
  beq lbl_801a60e4;
  lwz r31, -0x631c(r13);
  li r26, 0;
  bl OSUTF32toANSI;
  clrlwi. r30, r3, 0x18;
  beq lbl_801a60c8;
  lwz r0, -0x6324(r13);
  cmpwi r0, 0;
  beq lbl_801a60e4;
  lwz r0, 8(r1);
  cmplwi r0, 0x7f;
  bgt lbl_801a60e4;
lbl_801a60c8:
  lwz r3, 8(r1);
  bl OSUTF32toSJIS;
  clrlwi. r0, r3, 0x10;
  mr r30, r3;
  beq lbl_801a60e4;
  li r26, 1;
  lwz r31, -0x6320(r13);
lbl_801a60e4:
  stw r31, 0(r28);
  mr r3, r26;
  clrlwi r4, r30, 0x10;
  bl GetFontCode;
  stw r3, 0(r29);
  addi r11, r1, 0x30;
  mr r3, r27;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: OSGetFontTexel
// PAL: 0x801a6114..0x801a63a4
MARK_BINARY_BLOB(OSGetFontTexel, 0x801a6114, 0x801a63a4);
asm UNKNOWN_FUNCTION(OSGetFontTexel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_17;
  lhz r0, -0x7130(r13);
  mr r29, r4;
  mr r30, r5;
  mr r17, r6;
  cmplwi r0, 0xffff;
  mr r31, r7;
  beq lbl_801a6148;
  b lbl_801a618c;
lbl_801a6148:
  lis r4, 0x8000;
  lwz r0, 0xcc(r4);
  cmpwi r0, 0;
  beq lbl_801a6160;
  blt lbl_801a6174;
  b lbl_801a6174;
lbl_801a6160:
  lis r4, 0xcc00;
  lhz r0, 0x206e(r4);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  sth r0, -0x7130(r13);
  b lbl_801a617c;
lbl_801a6174:
  li r0, 0;
  sth r0, -0x7130(r13);
lbl_801a617c:
  lis r4, 0x801a;
  clrlwi r0, r0, 0x10;
  addi r4, r4, 0x5e5c;
  stw r4, -0x6328(r13);
lbl_801a618c:
  lwz r12, -0x6328(r13);
  mr r4, r3;
  clrlwi r3, r0, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  mtctr r12;
  bctrl;
  lwz r4, 0xc(r1);
  slwi r0, r17, 2;
  srawi r0, r0, 3;
  lwz r11, 8(r1);
  lhz r9, 0x1a(r4);
  addze r0, r0;
  lhz r5, 0x1c(r4);
  slwi r8, r0, 5;
  lwz r6, 0x24(r4);
  addi r23, r4, 0x2c;
  mullw r10, r9, r5;
  lwz r5, 0x14(r4);
  add r22, r4, r6;
  lhz r7, 0x12(r4);
  lhz r6, 0x10(r4);
  li r24, 0;
  divw r12, r11, r10;
  mullw r0, r12, r10;
  subf r11, r0, r11;
  divw r10, r11, r9;
  mullw r9, r10, r9;
  mullw r0, r12, r5;
  subf r26, r9, r11;
  srwi r0, r0, 1;
  mullw r27, r10, r7;
  add r22, r22, r0;
  mullw r26, r26, r6;
  b lbl_801a6360;
lbl_801a6218:
  add r7, r27, r24;
  slwi r0, r24, 0x1d;
  srawi r5, r7, 3;
  srwi r4, r24, 0x1f;
  addze r9, r5;
  slwi r6, r7, 0x1d;
  srawi r5, r24, 3;
  srwi r7, r7, 0x1f;
  addze r5, r5;
  subf r0, r4, r0;
  mullw r5, r5, r8;
  subf r6, r7, r6;
  rotlwi r0, r0, 3;
  rotlwi r6, r6, 3;
  add r0, r0, r4;
  add r4, r6, r7;
  slwi r10, r4, 1;
  add r11, r29, r5;
  slwi r12, r0, 2;
  li r25, 0;
  b lbl_801a634c;
lbl_801a626c:
  lhz r4, 0x1e(r4);
  add r28, r30, r25;
  add r5, r26, r25;
  li r0, 0xf0;
  rlwinm r6, r4, 2, 0, 0x1a;
  rlwinm r4, r4, 3, 0x1f, 0x1f;
  add r4, r4, r6;
  slwi r20, r28, 0x1d;
  srawi r7, r4, 1;
  srwi r19, r28, 0x1f;
  mullw r7, r7, r9;
  slwi r6, r5, 0x1d;
  srwi r4, r5, 0x1f;
  srawi r18, r5, 3;
  subf r6, r4, r6;
  clrlwi r21, r28, 0x1f;
  rotlwi r17, r6, 3;
  addze r6, r18;
  add r17, r17, r4;
  subf r20, r19, r20;
  xor r21, r21, r19;
  slwi r5, r5, 0x1e;
  srawi r18, r17, 2;
  rotlwi r20, r20, 3;
  subf r17, r4, r5;
  subf. r21, r19, r21;
  addze r5, r18;
  add r20, r20, r19;
  srawi r18, r28, 3;
  rotlwi r17, r17, 2;
  add r7, r22, r7;
  slwi r6, r6, 4;
  add r7, r7, r6;
  addze r19, r18;
  add r7, r7, r10;
  srwi r21, r20, 0x1f;
  add r28, r17, r4;
  slwi r6, r19, 5;
  add r4, r21, r20;
  lbzx r7, r7, r5;
  add r6, r11, r6;
  slwi r21, r28, 1;
  srawi r4, r4, 1;
  subfic r5, r21, 6;
  add r6, r6, r12;
  sraw r5, r7, r5;
  lbzx r7, r6, r4;
  clrlwi r5, r5, 0x1e;
  lbzx r5, r23, r5;
  beq lbl_801a6338;
  li r0, 0xf;
lbl_801a6338:
  and r0, r5, r0;
  addi r25, r25, 1;
  clrlwi r0, r0, 0x18;
  or r0, r7, r0;
  stbx r0, r6, r4;
lbl_801a634c:
  lwz r4, 0xc(r1);
  lhz r0, 0x10(r4);
  cmpw r25, r0;
  blt lbl_801a626c;
  addi r24, r24, 1;
lbl_801a6360:
  lhz r0, 0x12(r4);
  cmpw r24, r0;
  blt lbl_801a6218;
  cmpwi r31, 0;
  beq lbl_801a638c;
  lwz r5, 0xc(r1);
  lwz r4, 8(r1);
  lhz r0, 0x22(r5);
  add r0, r5, r0;
  lbzx r0, r4, r0;
  stw r0, 0(r31);
lbl_801a638c:
  addi r11, r1, 0x50;
  bl _restgpr_17;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: OSGetFontTexture
// PAL: 0x801a63a4..0x801a64f4
MARK_BINARY_BLOB(OSGetFontTexture, 0x801a63a4, 0x801a64f4);
asm void OSGetFontTexture(void*, u8**, int*, int*, int*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r7;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r4;
  lhz r0, -0x7130(r13);
  cmplwi r0, 0xffff;
  beq lbl_801a63e0;
  b lbl_801a6424;
lbl_801a63e0:
  lis r4, 0x8000;
  lwz r0, 0xcc(r4);
  cmpwi r0, 0;
  beq lbl_801a63f8;
  blt lbl_801a640c;
  b lbl_801a640c;
lbl_801a63f8:
  lis r4, 0xcc00;
  lhz r0, 0x206e(r4);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  sth r0, -0x7130(r13);
  b lbl_801a6414;
lbl_801a640c:
  li r0, 0;
  sth r0, -0x7130(r13);
lbl_801a6414:
  lis r4, 0x801a;
  clrlwi r0, r0, 0x10;
  addi r4, r4, 0x5e5c;
  stw r4, -0x6328(r13);
lbl_801a6424:
  lwz r12, -0x6328(r13);
  mr r4, r3;
  clrlwi r3, r0, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  mtctr r12;
  bctrl;
  lwz r7, 0xc(r1);
  cmpwi r31, 0;
  lwz r6, 8(r1);
  lhz r5, 0x1a(r7);
  lhz r4, 0x1c(r7);
  lwz r0, 0x24(r7);
  mullw r5, r5, r4;
  lwz r4, 0x14(r7);
  add r0, r7, r0;
  divw r6, r6, r5;
  mullw r4, r4, r6;
  add r0, r4, r0;
  stw r0, 0(r28);
  lwz r8, 0xc(r1);
  lwz r4, 8(r1);
  lhz r7, 0x1a(r8);
  lhz r5, 0x1c(r8);
  mullw r6, r6, r7;
  lhz r0, 0x10(r8);
  mullw r5, r6, r5;
  subf r5, r5, r4;
  divw r6, r5, r7;
  mullw r4, r6, r7;
  subf r4, r4, r5;
  mullw r0, r4, r0;
  stw r0, 0(r29);
  lwz r4, 0xc(r1);
  lhz r0, 0x12(r4);
  mullw r0, r6, r0;
  stw r0, 0(r30);
  beq lbl_801a64d4;
  lwz r5, 0xc(r1);
  lwz r4, 8(r1);
  lhz r0, 0x22(r5);
  add r0, r5, r0;
  lbzx r0, r4, r0;
  stw r0, 0(r31);
lbl_801a64d4:
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

// Symbol: OSGetFontWidth
// PAL: 0x801a64f4..0x801a65ac
MARK_BINARY_BLOB(OSGetFontWidth, 0x801a64f4, 0x801a65ac);
asm int OSGetFontWidth(void*, u32*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  lhz r0, -0x7130(r13);
  cmplwi r0, 0xffff;
  beq lbl_801a6518;
  b lbl_801a655c;
lbl_801a6518:
  lis r4, 0x8000;
  lwz r0, 0xcc(r4);
  cmpwi r0, 0;
  beq lbl_801a6530;
  blt lbl_801a6544;
  b lbl_801a6544;
lbl_801a6530:
  lis r4, 0xcc00;
  lhz r0, 0x206e(r4);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  sth r0, -0x7130(r13);
  b lbl_801a654c;
lbl_801a6544:
  li r0, 0;
  sth r0, -0x7130(r13);
lbl_801a654c:
  lis r4, 0x801a;
  clrlwi r0, r0, 0x10;
  addi r4, r4, 0x5e5c;
  stw r4, -0x6328(r13);
lbl_801a655c:
  lwz r12, -0x6328(r13);
  mr r4, r3;
  clrlwi r3, r0, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  mtctr r12;
  bctrl;
  cmpwi r31, 0;
  beq lbl_801a6598;
  lwz r5, 0xc(r1);
  lwz r4, 8(r1);
  lhz r0, 0x22(r5);
  add r0, r5, r0;
  lbzx r0, r4, r0;
  stw r0, 0(r31);
lbl_801a6598:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
