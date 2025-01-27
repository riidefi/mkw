#include "ut_resFontBase.hpp"

namespace nw4r {
namespace ut {
namespace detail {

__declspec(section ".data")
    u16 (CharStrmReader::*unk_80274e68)() = &CharStrmReader::ReadNextCharCP1252;

// Symbol: __ct__Q44nw4r2ut6detail11ResFontBaseFv
// PAL: 0x800b1f90..0x800b1ff0
MARK_BINARY_BLOB(__ct__Q44nw4r2ut6detail11ResFontBaseFv, 0x800b1f90,
                 0x800b1ff0);
asm ResFontBase::ResFontBase() {
  // clang-format off
  nofralloc;
  lis r4, 0x8027;
  lis r5, 0x8027;
  addi r4, r4, 0x4e08;
  stw r4, 0(r3);
  lis r7, 0x8027;
  addi r5, r5, 0x4e74;
  lwzu r6, 0x4e68(r7);
  lis r4, 1;
  lwz r0, 4(r7);
  stw r0, 8(r3);
  addi r0, r4, -1;
  li r4, 0;
  stw r6, 4(r3);
  lwz r6, 8(r7);
  stw r6, 0xc(r3);
  stw r5, 0(r3);
  stw r4, 0x10(r3);
  stw r4, 0x14(r3);
  sth r4, 0x18(r3);
  sth r0, 0x1a(r3);
  blr;
  // clang-format on
}

// Symbol: __dt__Q44nw4r2ut6detail11ResFontBaseFv
// PAL: 0x800b1ff0..0x800b2030
MARK_BINARY_BLOB(__dt__Q44nw4r2ut6detail11ResFontBaseFv, 0x800b1ff0,
                 0x800b2030);
asm ResFontBase::~ResFontBase() {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_800b2018;
  cmpwi r4, 0;
  ble lbl_800b2018;
  bl __dl__FPv;
lbl_800b2018:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol:
// SetResourceBuffer__Q44nw4r2ut6detail11ResFontBaseFPvPQ34nw4r2ut15FontInformation
// PAL: 0x800b2030..0x800b2040
MARK_BINARY_BLOB(
    SetResourceBuffer__Q44nw4r2ut6detail11ResFontBaseFPvPQ34nw4r2ut15FontInformation,
    0x800b2030, 0x800b2040);
asm void ResFontBase::SetResourceBuffer(void*, FontInformation*) {
  // clang-format off
  nofralloc;
  stw r4, 0x10(r3);
  stw r5, 0x14(r3);
  blr;
  // clang-format on
}

// Symbol: GetWidth__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2040..0x800b2050
MARK_BINARY_BLOB(GetWidth__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2040,
                 0x800b2050);
asm int ResFontBase::GetWidth() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r3, 0x15(r3);
  blr;
  // clang-format on
}

// Symbol: GetHeight__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2050..0x800b2060
MARK_BINARY_BLOB(GetHeight__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2050,
                 0x800b2060);
asm int ResFontBase::GetHeight() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r3, 0x14(r3);
  blr;
  // clang-format on
}

// Symbol: GetAscent__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2060..0x800b2070
MARK_BINARY_BLOB(GetAscent__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2060,
                 0x800b2070);
asm int ResFontBase::GetAscent() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r3, 0x16(r3);
  blr;
  // clang-format on
}

// Symbol: GetDescent__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2070..0x800b2090
MARK_BINARY_BLOB(GetDescent__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2070,
                 0x800b2090);
asm int ResFontBase::GetDescent() const {
  // clang-format off
  nofralloc;
  lwz r4, 0x14(r3);
  lbz r3, 0x16(r4);
  lbz r0, 0x14(r4);
  subf r3, r3, r0;
  blr;
  // clang-format on
}

// Symbol: GetBaselinePos__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2090..0x800b20b0
MARK_BINARY_BLOB(GetBaselinePos__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2090,
                 0x800b20b0);
asm int ResFontBase::GetBaselinePos() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lwz r3, 8(r3);
  lbz r3, 2(r3);
  extsb r3, r3;
  blr;
  // clang-format on
}

// Symbol: GetCellHeight__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b20b0..0x800b20f0
MARK_BINARY_BLOB(GetCellHeight__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b20b0,
                 0x800b20f0);
asm int ResFontBase::GetCellHeight() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lwz r3, 8(r3);
  lbz r3, 1(r3);
  blr;
  // clang-format on
}

asm int ResFontBase::GetCellWidth() const {
  nofralloc;
  lwz r3, 0x14(r3);
  lwz r3, 8(r3);
  lbz r3, 0(r3);
  blr;
  // clang-format on
}

asm int ResFontBase::GetMaxCharWidth() const {
  nofralloc;
  lwz r3, 0x14(r3);
  lwz r3, 8(r3);
  lbz r3, 3(r3);
  blr;
  // clang-format on
}

int ResFontBase::GetType() const { return 2; }

// Symbol: GetTextureFormat__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b20f0..0x800b2130
MARK_BINARY_BLOB(GetTextureFormat__Q44nw4r2ut6detail11ResFontBaseCFv,
                 0x800b20f0, 0x800b2130);
asm int ResFontBase::GetTextureFormat() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lwz r3, 8(r3);
  lhz r3, 0xa(r3);
  blr;
  // clang-format on
}

asm int ResFontBase::GetLineFeed() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r3, 1(r3);
  extsb r3, r3;
  blr;
  // clang-format on
}

asm CharWidths ResFontBase::GetDefaultCharWidths() const {
  // clang-format off
  lwz r4, 0x14(r3);
  lhz r0, 4(r4);
  slwi r3, r0, 0x10;
  lbz r0, 6(r4);
  rlwimi r3, r0, 8, 0x10, 0x17;
  blr;
  // clang-format on
}

// Symbol:
// SetDefaultCharWidths__Q44nw4r2ut6detail11ResFontBaseFRCQ34nw4r2ut10CharWidths
// PAL: 0x800b2130..0x800b2150
MARK_BINARY_BLOB(
    SetDefaultCharWidths__Q44nw4r2ut6detail11ResFontBaseFRCQ34nw4r2ut10CharWidths,
    0x800b2130, 0x800b2150);
asm void ResFontBase::SetDefaultCharWidths(const CharWidths&) {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r0, 0(r4);
  stb r0, 4(r3);
  lbz r0, 1(r4);
  stb r0, 5(r3);
  lbz r0, 2(r4);
  stb r0, 6(r3);
  blr;
  // clang-format on
}

// Symbol: SetAlternateChar__Q44nw4r2ut6detail11ResFontBaseFUs
// PAL: 0x800b2150..0x800b2210
MARK_BINARY_BLOB(SetAlternateChar__Q44nw4r2ut6detail11ResFontBaseFUs,
                 0x800b2150, 0x800b2210);
asm bool ResFontBase::SetAlternateChar(u16) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lhz r0, 0x18(r3);
  cmplw r4, r0;
  bne lbl_800b2178;
  lhz r0, 0x1a(r3);
  b lbl_800b21dc;
lbl_800b2178:
  sth r4, 0x18(r3);
  mr r5, r4;
  lwz r6, 0x14(r3);
  lwz r6, 0x10(r6);
  b lbl_800b21c4;
  nop;
lbl_800b2190:
  lhz r0, 0(r6);
  cmplw r0, r4;
  bgt lbl_800b21c0;
  lhz r0, 2(r6);
  cmplw r4, r0;
  bgt lbl_800b21c0;
  mr r3, r31;
  mr r4, r6;
  bl FindGlyphIndex;
  sth r3, 0x1a(r31);
  clrlwi r0, r3, 0x10;
  b lbl_800b21dc;
lbl_800b21c0:
  lwz r6, 8(r6);
lbl_800b21c4:
  cmpwi r6, 0;
  bne lbl_800b2190;
  lis r4, 1;
  addi r0, r4, -1;
  sth r0, 0x1a(r3);
  clrlwi r0, r0, 0x10;
lbl_800b21dc:
  cmplwi r0, 0xffff;
  beq lbl_800b21f4;
  lwz r4, 0x14(r31);
  li r3, 1;
  sth r0, 2(r4);
  b lbl_800b21f8;
lbl_800b21f4:
  li r3, 0;
lbl_800b21f8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SetLineFeed__Q44nw4r2ut6detail11ResFontBaseFi
// PAL: 0x800b2210..0x800b2220
MARK_BINARY_BLOB(SetLineFeed__Q44nw4r2ut6detail11ResFontBaseFi, 0x800b2210,
                 0x800b2220);
asm void ResFontBase::SetLineFeed(int) {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  stb r4, 1(r3);
  blr;
  // clang-format on
}

// Symbol: GetCharWidth__Q44nw4r2ut6detail11ResFontBaseCFUs
// PAL: 0x800b2220..0x800b2270
MARK_BINARY_BLOB(GetCharWidth__Q44nw4r2ut6detail11ResFontBaseCFUs, 0x800b2220,
                 0x800b2270);
asm int ResFontBase::GetCharWidth(u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r12, 0(r3);
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  srwi r0, r3, 0x18;
  stb r0, 8(r1);
  rlwinm r0, r3, 0x10, 0x18, 0x1f;
  stb r0, 9(r1);
  rlwinm r0, r3, 0x18, 0x18, 0x1f;
  mr r3, r0;
  stb r0, 0xa(r1);
  extsb r3, r3;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GetCharWidths__Q44nw4r2ut6detail11ResFontBaseCFUs
// PAL: 0x800b2270..0x800b2390
MARK_BINARY_BLOB(GetCharWidths__Q44nw4r2ut6detail11ResFontBaseCFUs, 0x800b2270,
                 0x800b2390);
asm CharWidths ResFontBase::GetCharWidths(u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lhz r0, 0x18(r3);
  cmplw r4, r0;
  bne lbl_800b2298;
  lhz r0, 0x1a(r3);
  b lbl_800b22fc;
lbl_800b2298:
  sth r4, 0x18(r3);
  mr r5, r4;
  lwz r6, 0x14(r3);
  lwz r6, 0x10(r6);
  b lbl_800b22e4;
  nop;
lbl_800b22b0:
  lhz r0, 0(r6);
  cmplw r0, r4;
  bgt lbl_800b22e0;
  lhz r0, 2(r6);
  cmplw r4, r0;
  bgt lbl_800b22e0;
  mr r3, r31;
  mr r4, r6;
  bl FindGlyphIndex;
  sth r3, 0x1a(r31);
  clrlwi r0, r3, 0x10;
  b lbl_800b22fc;
lbl_800b22e0:
  lwz r6, 8(r6);
lbl_800b22e4:
  cmpwi r6, 0;
  bne lbl_800b22b0;
  lis r4, 1;
  addi r0, r4, -1;
  sth r0, 0x1a(r3);
  clrlwi r0, r0, 0x10;
lbl_800b22fc:
  cmplwi r0, 0xffff;
  beq lbl_800b2308;
  b lbl_800b2310;
lbl_800b2308:
  lwz r3, 0x14(r31);
  lhz r0, 2(r3);
lbl_800b2310:
  lwz r6, 0x14(r31);
  clrlwi r3, r0, 0x10;
  lwz r4, 0xc(r6);
  b lbl_800b2354;
lbl_800b2320:
  lhz r5, 0(r4);
  cmplw r5, r3;
  bgt lbl_800b2350;
  lhz r0, 2(r4);
  cmplw r3, r0;
  bgt lbl_800b2350;
  subf r3, r5, r3;
  slwi r0, r3, 2;
  subf r0, r3, r0;
  add r3, r4, r0;
  addi r4, r3, 8;
  b lbl_800b2360;
lbl_800b2350:
  lwz r4, 4(r4);
lbl_800b2354:
  cmpwi r4, 0;
  bne lbl_800b2320;
  addi r4, r6, 4;
lbl_800b2360:
  lhz r0, 0(r4);
  lwz r31, 0xc(r1);
  slwi r3, r0, 0x10;
  lbz r0, 2(r4);
  rlwimi r3, r0, 8, 0x10, 0x17;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GetGlyph__Q44nw4r2ut6detail11ResFontBaseCFPQ34nw4r2ut5GlyphUs
// PAL: 0x800b2390..0x800b2460
MARK_BINARY_BLOB(GetGlyph__Q44nw4r2ut6detail11ResFontBaseCFPQ34nw4r2ut5GlyphUs,
                 0x800b2390, 0x800b2460);
asm void ResFontBase::GetGlyph(Glyph*, u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lhz r0, 0x18(r3);
  cmplw r5, r0;
  bne lbl_800b23c0;
  lhz r5, 0x1a(r3);
  b lbl_800b2418;
lbl_800b23c0:
  sth r5, 0x18(r3);
  lwz r4, 0x14(r3);
  lwz r4, 0x10(r4);
  b lbl_800b2400;
lbl_800b23d0:
  lhz r0, 0(r4);
  cmplw r0, r5;
  bgt lbl_800b23fc;
  lhz r0, 2(r4);
  cmplw r5, r0;
  bgt lbl_800b23fc;
  mr r3, r30;
  bl FindGlyphIndex;
  sth r3, 0x1a(r30);
  clrlwi r5, r3, 0x10;
  b lbl_800b2418;
lbl_800b23fc:
  lwz r4, 8(r4);
lbl_800b2400:
  cmpwi r4, 0;
  bne lbl_800b23d0;
  lis r4, 1;
  addi r0, r4, -1;
  sth r0, 0x1a(r3);
  clrlwi r5, r0, 0x10;
lbl_800b2418:
  cmplwi r5, 0xffff;
  mr r3, r30;
  mr r4, r31;
  beq lbl_800b242c;
  b lbl_800b2434;
lbl_800b242c:
  lwz r5, 0x14(r30);
  lhz r5, 2(r5);
lbl_800b2434:
  clrlwi r5, r5, 0x10;
  bl GetGlyphFromIndex
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: HasGlyph__Q44nw4r2ut6detail11ResFontBaseCFUs
// PAL: 0x800b2460..0x800b2520
MARK_BINARY_BLOB(HasGlyph__Q44nw4r2ut6detail11ResFontBaseCFUs, 0x800b2460,
                 0x800b2520);
asm bool ResFontBase::HasGlyph(u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lhz r0, 0x18(r3);
  cmplw r4, r0;
  bne lbl_800b2488;
  lhz r4, 0x1a(r3);
  b lbl_800b24ec;
lbl_800b2488:
  sth r4, 0x18(r3);
  mr r5, r4;
  lwz r6, 0x14(r3);
  lwz r6, 0x10(r6);
  b lbl_800b24d4;
  nop;
lbl_800b24a0:
  lhz r0, 0(r6);
  cmplw r0, r4;
  bgt lbl_800b24d0;
  lhz r0, 2(r6);
  cmplw r4, r0;
  bgt lbl_800b24d0;
  mr r3, r31;
  mr r4, r6;
  bl FindGlyphIndex;
  sth r3, 0x1a(r31);
  clrlwi r4, r3, 0x10;
  b lbl_800b24ec;
lbl_800b24d0:
  lwz r6, 8(r6);
lbl_800b24d4:
  cmpwi r6, 0;
  bne lbl_800b24a0;
  lis r4, 1;
  addi r0, r4, -1;
  sth r0, 0x1a(r3);
  clrlwi r4, r0, 0x10;
lbl_800b24ec:
  lis r3, 1;
  lwz r31, 0xc(r1);
  addi r0, r3, -1;
  clrlwi r0, r0, 0x10;
  subf r3, r4, r0;
  subf r0, r0, r4;
  or r0, r3, r0;
  srwi r3, r0, 0x1f;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GetEncoding__Q44nw4r2ut6detail11ResFontBaseCFv
// PAL: 0x800b2520..0x800b2530
MARK_BINARY_BLOB(GetEncoding__Q44nw4r2ut6detail11ResFontBaseCFv, 0x800b2520,
                 0x800b2530);
asm FontEncoding ResFontBase::GetEncoding() const {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  lbz r3, 7(r3);
  blr;
  // clang-format on
}

// Symbol: GetGlyphIndex__Q44nw4r2ut6detail11ResFontBaseCFUs
// PAL: 0x800b2530..0x800b25f0
MARK_BINARY_BLOB(GetGlyphIndex__Q44nw4r2ut6detail11ResFontBaseCFUs, 0x800b2530,
                 0x800b25f0);
asm u16 ResFontBase::GetGlyphIndex(u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lhz r0, 0x18(r3);
  cmplw r4, r0;
  bne lbl_800b2558;
  lhz r3, 0x1a(r3);
  b lbl_800b25bc;
lbl_800b2558:
  sth r4, 0x18(r3);
  mr r5, r4;
  lwz r6, 0x14(r3);
  lwz r6, 0x10(r6);
  b lbl_800b25a4;
  nop;
lbl_800b2570:
  lhz r0, 0(r6);
  cmplw r0, r4;
  bgt lbl_800b25a0;
  lhz r0, 2(r6);
  cmplw r4, r0;
  bgt lbl_800b25a0;
  mr r3, r31;
  mr r4, r6;
  bl FindGlyphIndex;
  sth r3, 0x1a(r31);
  clrlwi r3, r3, 0x10;
  b lbl_800b25bc;
lbl_800b25a0:
  lwz r6, 8(r6);
lbl_800b25a4:
  cmpwi r6, 0;
  bne lbl_800b2570;
  lis r4, 1;
  addi r0, r4, -1;
  sth r0, 0x1a(r3);
  clrlwi r3, r0, 0x10;
lbl_800b25bc:
  cmplwi r3, 0xffff;
  beq lbl_800b25c8;
  b lbl_800b25d0;
lbl_800b25c8:
  lwz r3, 0x14(r31);
  lhz r3, 2(r3);
lbl_800b25d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol:
// FindGlyphIndex__Q44nw4r2ut6detail11ResFontBaseCFPCQ34nw4r2ut11FontCodeMapUs
// PAL: 0x800b25f0..0x800b26c0
MARK_BINARY_BLOB(
    FindGlyphIndex__Q44nw4r2ut6detail11ResFontBaseCFPCQ34nw4r2ut11FontCodeMapUs,
    0x800b25f0, 0x800b26c0);
asm u16 ResFontBase::FindGlyphIndex(const FontCodeMap*, u16) const {
  // clang-format off
  nofralloc;
  lhz r0, 4(r4);
  lis r3, 1;
  addi r3, r3, -1;
  cmpwi r0, 0;
  beq lbl_800b2618;
  cmpwi r0, 1;
  beq lbl_800b2630;
  cmpwi r0, 2;
  beq lbl_800b2648;
  blr;
lbl_800b2618:
  lhz r0, 0(r4);
  lhz r3, 0xc(r4);
  subf r0, r0, r5;
  add r0, r3, r0;
  clrlwi r3, r0, 0x10;
  blr;
lbl_800b2630:
  lhz r0, 0(r4);
  subf r0, r0, r5;
  slwi r0, r0, 1;
  add r3, r4, r0;
  lhz r3, 0xc(r3);
  blr;
lbl_800b2648:
  addi r6, r4, 0xc;
  lhz r4, 0xc(r4);
  addi r7, r6, 2;
  addi r0, r4, -1;
  slwi r0, r0, 2;
  add r4, r6, r0;
  addi r6, r4, 2;
  b lbl_800b26b0;
lbl_800b2668:
  subf r0, r7, r6;
  srawi r0, r0, 2;
  addze r4, r0;
  srwi r0, r4, 0x1f;
  add r0, r0, r4;
  rlwinm r0, r0, 1, 0, 0x1d;
  add r4, r7, r0;
  lhzx r0, r7, r0;
  cmplw r0, r5;
  bge lbl_800b2698;
  addi r7, r4, 4;
  b lbl_800b26b0;
lbl_800b2698:
  cmplw r5, r0;
  bge lbl_800b26a8;
  addi r6, r4, -4;
  b lbl_800b26b0;
lbl_800b26a8:
  lhz r3, 2(r4);
  blr;
lbl_800b26b0:
  cmplw r7, r6;
  ble lbl_800b2668;
  blr;
  // clang-format on
}

// Symbol: GetCharWidthsFromIndex__Q44nw4r2ut6detail11ResFontBaseCFUs
// PAL: 0x800b26c0..0x800b2720
MARK_BINARY_BLOB(GetCharWidthsFromIndex__Q44nw4r2ut6detail11ResFontBaseCFUs,
                 0x800b26c0, 0x800b2720);
asm const CharWidths& ResFontBase::GetCharWidthsFromIndex(u16) const {
  // clang-format off
  nofralloc;
  lwz r5, 0x14(r3);
  lwz r6, 0xc(r5);
  b lbl_800b2704;
  nop;
lbl_800b26d0:
  lhz r3, 0(r6);
  cmplw r3, r4;
  bgt lbl_800b2700;
  lhz r0, 2(r6);
  cmplw r4, r0;
  bgt lbl_800b2700;
  subf r3, r3, r4;
  slwi r0, r3, 2;
  subf r0, r3, r0;
  add r3, r6, r0;
  addi r3, r3, 8;
  blr;
lbl_800b2700:
  lwz r6, 4(r6);
lbl_800b2704:
  cmpwi r6, 0;
  bne lbl_800b26d0;
  addi r3, r5, 4;
  blr;
  // clang-format on
}

// Symbol:
// GetGlyphFromIndex__Q44nw4r2ut6detail11ResFontBaseCFPQ34nw4r2ut5GlyphUs PAL:
// 0x800b2720..0x800b2830
MARK_BINARY_BLOB(
    GetGlyphFromIndex__Q44nw4r2ut6detail11ResFontBaseCFPQ34nw4r2ut5GlyphUs,
    0x800b2720, 0x800b2830);
asm int ResFontBase::GetGlyphFromIndex(Glyph*, u16) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lwz r6, 0x14(r3);
  lwz r6, 8(r6);
  lhz r31, 0xc(r6);
  lhz r0, 0xe(r6);
  lbz r7, 0(r6);
  mullw r10, r31, r0;
  lbz r8, 1(r6);
  addi r9, r7, 1;
  lwz r0, 4(r6);
  lwz r7, 0x14(r6);
  addi r8, r8, 1;
  divwu r12, r5, r10;
  mullw r10, r12, r10;
  subf r30, r10, r5;
  divwu r11, r30, r31;
  mullw r10, r11, r31;
  mullw r0, r12, r0;
  subf r10, r10, r30;
  add r0, r7, r0;
  stw r0, 0(r4);
  mullw r10, r10, r9;
  lwz r9, 0x14(r3);
  lwz r7, 0xc(r9);
  mullw r8, r11, r8;
  b lbl_800b27c4;
lbl_800b2790:
  lhz r3, 0(r7);
  cmplw r3, r5;
  bgt lbl_800b27c0;
  lhz r0, 2(r7);
  cmplw r5, r0;
  bgt lbl_800b27c0;
  subf r3, r3, r5;
  slwi r0, r3, 2;
  subf r0, r3, r0;
  add r3, r7, r0;
  addi r7, r3, 8;
  b lbl_800b27d0;
lbl_800b27c0:
  lwz r7, 4(r7);
lbl_800b27c4:
  cmpwi r7, 0;
  bne lbl_800b2790;
  addi r7, r9, 4;
lbl_800b27d0:
  lbz r0, 0(r7);
  addi r3, r10, 1;
  stb r0, 4(r4);
  addi r0, r8, 1;
  lbz r5, 1(r7);
  stb r5, 5(r4);
  lbz r5, 2(r7);
  stb r5, 6(r4);
  lbz r5, 1(r6);
  stb r5, 7(r4);
  lhz r5, 0xa(r6);
  stw r5, 8(r4);
  lhz r5, 0x10(r6);
  sth r5, 0xc(r4);
  lhz r5, 0x12(r6);
  sth r5, 0xe(r4);
  sth r3, 0x10(r4);
  sth r0, 0x12(r4);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

} // namespace detail
} // namespace ut
} // namespace nw4r
