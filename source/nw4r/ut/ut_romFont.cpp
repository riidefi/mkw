#include "ut_romFont.hpp"

#include <rvl/os/osFont.h>

// Symbol: RomFont_ct
// Function signature is unknown.
// PAL: 0x800b1a20..0x800b1a80
MARK_BINARY_BLOB(RomFont_ct, 0x800b1a20, 0x800b1a80);
asm UNKNOWN_FUNCTION(RomFont_ct) {
  // clang-format off
  nofralloc;
  lis r4, 0x8027;
  lis r5, 0x8027;
  addi r4, r4, 0x4e08;
  stw r4, 0(r3);
  lis r7, 0x8027;
  addi r5, r5, 0x4dac;
  lwzu r6, 0x4da0(r7);
  li r4, 0;
  lwz r0, 4(r7);
  stw r0, 8(r3);
  li r0, 0x3f;
  stw r6, 4(r3);
  lwz r6, 8(r7);
  stw r6, 0xc(r3);
  stw r5, 0(r3);
  stw r4, 0x10(r3);
  sth r0, 0x18(r3);
  stb r4, 0x14(r3);
  stb r4, 0x15(r3);
  stb r4, 0x16(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_dt
// Function signature is unknown.
// PAL: 0x800b1a80..0x800b1ac0
MARK_BINARY_BLOB(RomFont_dt, 0x800b1a80, 0x800b1ac0);
asm UNKNOWN_FUNCTION(RomFont_dt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_800b1aa8;
  cmpwi r4, 0;
  ble lbl_800b1aa8;
  bl __dl__FPv;
lbl_800b1aa8:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: RomFont_Unload
// Function signature is unknown.
// PAL: 0x800b1ac0..0x800b1ae0
MARK_BINARY_BLOB(RomFont_Unload, 0x800b1ac0, 0x800b1ae0);
asm UNKNOWN_FUNCTION(RomFont_Unload) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  lwz r3, 0x10(r3);
  li r0, 0;
  stw r0, 0x10(r4);
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1ae0
// Function signature is unknown.
// PAL: 0x800b1ae0..0x800b1af0
MARK_BINARY_BLOB(RomFont_800b1ae0, 0x800b1ae0, 0x800b1af0);
asm UNKNOWN_FUNCTION(RomFont_800b1ae0) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetRequireBufferSize
// Function signature is unknown.
// PAL: 0x800b1af0..0x800b1b50
MARK_BINARY_BLOB(RomFont_GetRequireBufferSize, 0x800b1af0, 0x800b1b50);
asm UNKNOWN_FUNCTION(RomFont_GetRequireBufferSize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r30);
  mr r31, r3;
  mr r3, r30;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  add r3, r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: RomFont_GetAscent
// Function signature is unknown.
// PAL: 0x800b1b50..0x800b1b60
MARK_BINARY_BLOB(RomFont_GetAscent, 0x800b1b50, 0x800b1b60);
asm UNKNOWN_FUNCTION(RomFont_GetAscent) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetDescent
// Function signature is unknown.
// PAL: 0x800b1b60..0x800b1b70
MARK_BINARY_BLOB(RomFont_GetDescent, 0x800b1b60, 0x800b1b70);
asm UNKNOWN_FUNCTION(RomFont_GetDescent) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xa(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetBaselinePos
// Function signature is unknown.
// PAL: 0x800b1b70..0x800b1b80
MARK_BINARY_BLOB(RomFont_GetBaselinePos, 0x800b1b70, 0x800b1b80);
asm UNKNOWN_FUNCTION(RomFont_GetBaselinePos) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetCellHeight
// Function signature is unknown.
// PAL: 0x800b1b80..0x800b1b90
MARK_BINARY_BLOB(RomFont_GetCellHeight, 0x800b1b80, 0x800b1b90);
asm UNKNOWN_FUNCTION(RomFont_GetCellHeight) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0x12(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetCellWidth
// Function signature is unknown.
// PAL: 0x800b1b90..0x800b1ba0
MARK_BINARY_BLOB(RomFont_GetCellWidth, 0x800b1b90, 0x800b1ba0);
asm UNKNOWN_FUNCTION(RomFont_GetCellWidth) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0x10(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetMaxCharWidth
// Function signature is unknown.
// PAL: 0x800b1ba0..0x800b1bb0
MARK_BINARY_BLOB(RomFont_GetMaxCharWidth, 0x800b1ba0, 0x800b1bb0);
asm UNKNOWN_FUNCTION(RomFont_GetMaxCharWidth) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetType
// Function signature is unknown.
// PAL: 0x800b1bb0..0x800b1bc0
MARK_BINARY_BLOB(RomFont_GetType, 0x800b1bb0, 0x800b1bc0);
asm UNKNOWN_FUNCTION(RomFont_GetType) {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: RomFont_GetTextureFormat
// Function signature is unknown.
// PAL: 0x800b1bc0..0x800b1bd0
MARK_BINARY_BLOB(RomFont_GetTextureFormat, 0x800b1bc0, 0x800b1bd0);
asm UNKNOWN_FUNCTION(RomFont_GetTextureFormat) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1bd0
// Function signature is unknown.
// PAL: 0x800b1bd0..0x800b1be0
MARK_BINARY_BLOB(RomFont_800b1bd0, 0x800b1bd0, 0x800b1be0);
asm UNKNOWN_FUNCTION(RomFont_800b1bd0) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xe(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1be0
// Function signature is unknown.
// PAL: 0x800b1be0..0x800b1c00
MARK_BINARY_BLOB(RomFont_800b1be0, 0x800b1be0, 0x800b1c00);
asm UNKNOWN_FUNCTION(RomFont_800b1be0) {
  // clang-format off
  nofralloc;
  lhz r0, 0x14(r3);
  mr r4, r3;
  slwi r3, r0, 0x10;
  lbz r0, 0x16(r4);
  rlwimi r3, r0, 8, 0x10, 0x17;
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1c00
// Function signature is unknown.
// PAL: 0x800b1c00..0x800b1c20
MARK_BINARY_BLOB(RomFont_800b1c00, 0x800b1c00, 0x800b1c20);
asm UNKNOWN_FUNCTION(RomFont_800b1c00) {
  // clang-format off
  nofralloc;
  lbz r6, 0(r4);
  lbz r5, 1(r4);
  lbz r0, 2(r4);
  stb r6, 0x14(r3);
  stb r5, 0x15(r3);
  stb r0, 0x16(r3);
  blr;
  // clang-format on
}

// Symbol: SetAlternateChar__Q34nw4r2ut7RomFontFUs
// Function signature is unknown.
// PAL: 0x800b1c20..0x800b1cb0
MARK_BINARY_BLOB(SetAlternateChar__Q34nw4r2ut7RomFontFUs, 0x800b1c20,
                 0x800b1cb0);
asm UNKNOWN_FUNCTION(SetAlternateChar__Q34nw4r2ut7RomFontFUs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 1;
  stw r0, 0x24(r1);
  addi r0, r5, -1;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r31, 0x18(r3);
  sth r0, 0x18(r3);
  lwz r12, 0(r3);
  lwz r12, 0x54(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_800b1c70;
  mr r0, r30;
  b lbl_800b1c74;
lbl_800b1c70:
  lhz r0, 0x18(r29);
lbl_800b1c74:
  clrlwi r0, r0, 0x10;
  cmplwi r0, 0xffff;
  beq lbl_800b1c8c;
  sth r30, 0x18(r29);
  li r3, 1;
  b lbl_800b1c94;
lbl_800b1c8c:
  sth r31, 0x18(r29);
  li r3, 0;
lbl_800b1c94:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1cb0
// Function signature is unknown.
// PAL: 0x800b1cb0..0x800b1cc0
MARK_BINARY_BLOB(RomFont_800b1cb0, 0x800b1cb0, 0x800b1cc0);
asm UNKNOWN_FUNCTION(RomFont_800b1cb0) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  sth r4, 0xe(r3);
  blr;
  // clang-format on
}

// Symbol: GetCharWidth__Q34nw4r2ut7RomFontCFUs
// Function signature is unknown.
// PAL: 0x800b1cc0..0x800b1d50
MARK_BINARY_BLOB(GetCharWidth__Q34nw4r2ut7RomFontCFUs, 0x800b1cc0, 0x800b1d50);
asm UNKNOWN_FUNCTION(GetCharWidth__Q34nw4r2ut7RomFontCFUs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  lwz r12, 0(r3);
  lwz r12, 0x54(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_800b1cf8;
  b lbl_800b1cfc;
lbl_800b1cf8:
  lhz r31, 0x18(r30);
lbl_800b1cfc:
  rlwinm. r3, r31, 0x18, 0x18, 0x1f;
  bne lbl_800b1d14;
  li r0, 0;
  stb r31, 8(r1);
  stb r0, 9(r1);
  b lbl_800b1d24;
lbl_800b1d14:
  li r0, 0;
  stb r3, 8(r1);
  stb r31, 9(r1);
  stb r0, 0xa(r1);
lbl_800b1d24:
  addi r3, r1, 8;
  addi r4, r1, 0xc;
  bl OSGetFontWidth;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x24(r1);
  lwz r3, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RomFont_800b1d50
// Function signature is unknown.
// PAL: 0x800b1d50..0x800b1da0
MARK_BINARY_BLOB(RomFont_800b1d50, 0x800b1d50, 0x800b1da0);
asm UNKNOWN_FUNCTION(RomFont_800b1d50) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r12, 0(r3);
  lwz r12, 0x48(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stb r0, 8(r1);
  mr r4, r3;
  stb r3, 9(r1);
  lhz r0, 8(r1);
  stb r3, 0xa(r1);
  slwi r3, r0, 0x10;
  lwz r0, 0x14(r1);
  rlwimi r3, r4, 8, 0x10, 0x17;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GetGlyph__Q34nw4r2ut7RomFontCFPQ34nw4r2ut5GlyphUs
// Function signature is unknown.
// PAL: 0x800b1da0..0x800b1ea0
MARK_BINARY_BLOB(GetGlyph__Q34nw4r2ut7RomFontCFPQ34nw4r2ut5GlyphUs, 0x800b1da0,
                 0x800b1ea0);
asm UNKNOWN_FUNCTION(GetGlyph__Q34nw4r2ut7RomFontCFPQ34nw4r2ut5GlyphUs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r4;
  mr r4, r31;
  stw r29, 0x24(r1);
  mr r29, r3;
  lwz r12, 0(r3);
  lwz r12, 0x54(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_800b1de4;
  b lbl_800b1de8;
lbl_800b1de4:
  lhz r31, 0x18(r29);
lbl_800b1de8:
  rlwinm. r3, r31, 0x18, 0x18, 0x1f;
  bne lbl_800b1e00;
  li r0, 0;
  stb r31, 8(r1);
  stb r0, 9(r1);
  b lbl_800b1e10;
lbl_800b1e00:
  li r0, 0;
  stb r3, 8(r1);
  stb r31, 9(r1);
  stb r0, 0xa(r1);
lbl_800b1e10:
  addi r3, r1, 8;
  addi r4, r1, 0x18;
  addi r5, r1, 0x14;
  addi r6, r1, 0x10;
  addi r7, r1, 0xc;
  bl OSGetFontTexture;
  lwz r0, 0x18(r1);
  li r4, 0;
  stw r0, 0(r30);
  stb r4, 4(r30);
  lwz r0, 0xc(r1);
  stb r0, 5(r30);
  lwz r0, 0xc(r1);
  stb r0, 6(r30);
  lwz r3, 0x10(r29);
  lhz r0, 0x12(r3);
  stb r0, 7(r30);
  stw r4, 8(r30);
  lwz r3, 0x10(r29);
  lhz r0, 0x1e(r3);
  sth r0, 0xc(r30);
  lwz r3, 0x10(r29);
  lhz r0, 0x20(r3);
  sth r0, 0xe(r30);
  lwz r0, 0x14(r1);
  sth r0, 0x10(r30);
  lwz r0, 0x10(r1);
  sth r0, 0x12(r30);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: HasGlyph__Q34nw4r2ut7RomFontCFUs
// Function signature is unknown.
// PAL: 0x800b1ea0..0x800b1f58
MARK_BINARY_BLOB(HasGlyph__Q34nw4r2ut7RomFontCFUs, 0x800b1ea0, 0x800b1f58);
asm UNKNOWN_FUNCTION(HasGlyph__Q34nw4r2ut7RomFontCFUs) {
  // clang-format off
  nofralloc;
  lhz r0, -0x7e38(r13);
  cmpwi r0, 0;
  beq lbl_800b1eb8;
  cmpwi r0, 1;
  beq lbl_800b1ed4;
  b lbl_800b1f58;
lbl_800b1eb8:
  cmplwi r4, 0x20;
  li r3, 0;
  bltlr;
  cmplwi r4, 0xff;
  bgtlr;
  li r3, 1;
  blr;
lbl_800b1ed4:
  cmplwi r4, 0xff;
  ble lbl_800b1ee4;
  li r0, 0;
  b lbl_800b1f0c;
lbl_800b1ee4:
  cmplwi r4, 0x20;
  li r0, 0;
  blt lbl_800b1ef8;
  cmplwi r4, 0x7e;
  ble lbl_800b1f08;
lbl_800b1ef8:
  cmplwi r4, 0xa1;
  blt lbl_800b1f0c;
  cmplwi r4, 0xdf;
  bgt lbl_800b1f0c;
lbl_800b1f08:
  li r0, 1;
lbl_800b1f0c:
  cmpwi r0, 0;
  li r3, 1;
  bnelr;
  rlwinm r5, r4, 0x18, 0x18, 0x1f;
  clrlwi r4, r4, 0x18;
  cmplwi r5, 0x81;
  li r0, 0;
  blt lbl_800b1f48;
  cmplwi r5, 0x98;
  bgt lbl_800b1f48;
  cmplwi r4, 0x40;
  blt lbl_800b1f48;
  cmplwi r4, 0xfc;
  bgt lbl_800b1f48;
  li r0, 1;
lbl_800b1f48:
  cmpwi r0, 0;
  bnelr;
  li r3, 0;
  blr;
lbl_800b1f58:
  li r3, 0;
  blr;
  // clang-format on
}
