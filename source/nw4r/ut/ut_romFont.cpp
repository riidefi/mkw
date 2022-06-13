#include "ut_romFont.hpp"

#include <rvl/os/osFont.h>

#include "ut_CharStrmReader.hpp"

namespace nw4r {
namespace ut {

__declspec(section ".data")
    u16 (CharStrmReader::*unk_80274da0)() = &CharStrmReader::ReadNextCharCP1252;

// Symbol: RomFont_ct
// PAL: 0x800b1a20..0x800b1a80
MARK_BINARY_BLOB(RomFont_ct, 0x800b1a20, 0x800b1a80);
asm RomFont::RomFont() {
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
// PAL: 0x800b1a80..0x800b1ac0
MARK_BINARY_BLOB(RomFont_dt, 0x800b1a80, 0x800b1ac0);
asm RomFont::~RomFont() {
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
// PAL: 0x800b1ac0..0x800b1ae0
MARK_BINARY_BLOB(RomFont_Unload, 0x800b1ac0, 0x800b1ae0);
asm bool RomFont::Unload(void*) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  lwz r3, 0x10(r3);
  li r0, 0;
  stw r0, 0x10(r4);
  blr;
  // clang-format on
}

// Symbol: GetWidth__Q34nw4r2ut7RomFontCFv
// PAL: 0x800b1ae0..0x800b1af0
MARK_BINARY_BLOB(GetWidth__Q34nw4r2ut7RomFontCFv, 0x800b1ae0, 0x800b1af0);
asm int RomFont::GetWidth() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: GetHeight__Q34nw4r2ut7RomFontCFv
// PAL: 0x800b1af0..0x800b1b50
MARK_BINARY_BLOB(GetHeight__Q34nw4r2ut7RomFontCFv, 0x800b1af0, 0x800b1b50);
asm int RomFont::GetHeight() const {
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
// PAL: 0x800b1b50..0x800b1b60
MARK_BINARY_BLOB(RomFont_GetAscent, 0x800b1b50, 0x800b1b60);
asm int RomFont::GetAscent() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 8(r3);
  blr;

  // clang-format on
}

// Symbol: RomFont_GetDescent
// PAL: 0x800b1b60..0x800b1b70
MARK_BINARY_BLOB(RomFont_GetDescent, 0x800b1b60, 0x800b1b70);
asm int RomFont::GetDescent() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xa(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetBaselinePos
// PAL: 0x800b1b70..0x800b1b80
MARK_BINARY_BLOB(RomFont_GetBaselinePos, 0x800b1b70, 0x800b1b80);
asm int RomFont::GetBaselinePos() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetCellHeight
// PAL: 0x800b1b80..0x800b1b90
MARK_BINARY_BLOB(RomFont_GetCellHeight, 0x800b1b80, 0x800b1b90);
asm int RomFont::GetCellHeight() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0x12(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetCellWidth
// PAL: 0x800b1b90..0x800b1ba0
MARK_BINARY_BLOB(RomFont_GetCellWidth, 0x800b1b90, 0x800b1ba0);
asm int RomFont::GetCellWidth() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0x10(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetMaxCharWidth
// PAL: 0x800b1ba0..0x800b1bb0
MARK_BINARY_BLOB(RomFont_GetMaxCharWidth, 0x800b1ba0, 0x800b1bb0);
asm int RomFont::GetMaxCharWidth() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: RomFont_GetType
// PAL: 0x800b1bb0..0x800b1bc0
MARK_BINARY_BLOB(RomFont_GetType, 0x800b1bb0, 0x800b1bc0);
asm int RomFont::GetType() const {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: RomFont_GetTextureFormat
// PAL: 0x800b1bc0..0x800b1bd0
MARK_BINARY_BLOB(RomFont_GetTextureFormat, 0x800b1bc0, 0x800b1bd0);
asm int RomFont::GetTextureFormat() const {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: GetLineFeed__Q34nw4r2ut7RomFontCFv
// PAL: 0x800b1bd0..0x800b1be0
MARK_BINARY_BLOB(GetLineFeed__Q34nw4r2ut7RomFontCFv, 0x800b1bd0, 0x800b1be0);
asm int RomFont::GetLineFeed() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  lhz r3, 0xe(r3);
  blr;
  // clang-format on
}

// Symbol: GetDefaultCharWidths__Q34nw4r2ut7RomFontCFv
// PAL: 0x800b1be0..0x800b1c00
MARK_BINARY_BLOB(GetDefaultCharWidths__Q34nw4r2ut7RomFontCFv, 0x800b1be0,
                 0x800b1c00);
asm CharWidths RomFont::GetDefaultCharWidths() const {
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

// Symbol: SetDefaultCharWidths__Q34nw4r2ut7RomFontFRCQ34nw4r2ut10CharWidths
// PAL: 0x800b1c00..0x800b1c20
MARK_BINARY_BLOB(
    SetDefaultCharWidths__Q34nw4r2ut7RomFontFRCQ34nw4r2ut10CharWidths,
    0x800b1c00, 0x800b1c20);
asm void RomFont::SetDefaultCharWidths(const CharWidths&) {
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
// PAL: 0x800b1c20..0x800b1cb0
MARK_BINARY_BLOB(SetAlternateChar__Q34nw4r2ut7RomFontFUs, 0x800b1c20,
                 0x800b1cb0);
asm bool RomFont::SetAlternateChar(u16) {
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

// Symbol: SetLineFeed__Q34nw4r2ut7RomFontFi
// PAL: 0x800b1cb0..0x800b1cc0
MARK_BINARY_BLOB(SetLineFeed__Q34nw4r2ut7RomFontFi, 0x800b1cb0, 0x800b1cc0);
asm void RomFont::SetLineFeed(int) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  sth r4, 0xe(r3);
  blr;
  // clang-format on
}

// Symbol: GetCharWidth__Q34nw4r2ut7RomFontCFUs
// PAL: 0x800b1cc0..0x800b1d50
MARK_BINARY_BLOB(GetCharWidth__Q34nw4r2ut7RomFontCFUs, 0x800b1cc0, 0x800b1d50);
asm int RomFont::GetCharWidth(u16) const {
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

// Symbol: GetCharWidths__Q34nw4r2ut7RomFontCFUs
// PAL: 0x800b1d50..0x800b1da0
MARK_BINARY_BLOB(GetCharWidths__Q34nw4r2ut7RomFontCFUs, 0x800b1d50, 0x800b1da0);
asm CharWidths RomFont::GetCharWidths(u16) const {
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
// PAL: 0x800b1da0..0x800b1ea0
MARK_BINARY_BLOB(GetGlyph__Q34nw4r2ut7RomFontCFPQ34nw4r2ut5GlyphUs, 0x800b1da0,
                 0x800b1ea0);
asm void RomFont::GetGlyph(Glyph*, u16) const {
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

u16 unk_80384dc8 = 0xFFFF;

// Symbol: HasGlyph__Q34nw4r2ut7RomFontCFUs
// PAL: 0x800b1ea0..0x800b1f60
MARK_BINARY_BLOB(HasGlyph__Q34nw4r2ut7RomFontCFUs, 0x800b1ea0, 0x800b1f60);
asm bool RomFont::HasGlyph(u16) const {
  // clang-format off
  nofralloc;
  lhz r0, unk_80384dc8;
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

// Symbol: RomFont_800b1f60
// PAL: 0x800b1f60..0x800b1f90
MARK_BINARY_BLOB(RomFont_800b1f60, 0x800b1f60, 0x800b1f90);
asm FontEncoding RomFont::GetEncoding() const {
  // clang-format off
  nofralloc;
  lhz r0, unk_80384dc8;
  cmpwi r0, 0;
  beq lbl_800b1f78;
  cmpwi r0, 1;
  beq lbl_800b1f80;
  b lbl_800b1f88;
lbl_800b1f78:
  li r3, 3;
  blr;
lbl_800b1f80:
  li r3, 2;
  blr;
lbl_800b1f88:
  li r3, 3;
  blr;
  // clang-format on
}

} // namespace ut
} // namespace nw4r
