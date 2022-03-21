#include "ut_romFont.hpp"

#include <rvl/os/osFont.h>

#include "utInlines.hpp"

// Stolen from ogws.
// Credit: GibHaltmannKill
// Credit: kiwi515

namespace nw4r {
namespace ut {

namespace {
inline bool IsCP1252Char(u16 ch) { return (ch >= 0x20) && (ch <= 0xFF); }

inline bool IsSJISHalfWidthChar(u16 ch) {
  if (ch > 0xFF)
    return false;

  return ((ch >= 0x20) && (ch <= 0x7E)) || ((ch >= 0xA1) && (ch <= 0xDF));
}

static inline bool IsSJISLeadByte(u8 hi) {
  return (hi >= 0x81) && (hi <= 0x98);
}

static inline bool IsSJISTrailByte(u8 lo) {
  return (lo >= 0x40) && (lo <= 0xFC);
}

inline bool IsSJISFullWidthChar(u16 ch) {
  u8 hi;
  u8 lo;

  hi = BitExtract<u16>(ch, 8, 8);
  lo = BitExtract<u16>(ch, 8, 0);

  return IsSJISLeadByte(hi) && IsSJISTrailByte(lo);
}
} // namespace

u16 RomFont::mFontEncode = -1;

// Symbol: RomFont_ct
// PAL: 0x800b1a20..0x800b1a80
RomFont::RomFont()
    : mBuffer(), mAlternateChar('\?') //, mDefaultCharWidths()
{
  mDefaultCharWidths.BYTE_0x0 = 0;
  mDefaultCharWidths.BYTE_0x1 = 0;
  mDefaultCharWidths.BYTE_0x2 = 0;
}

// Symbol: RomFont_dt
// PAL: 0x800b1a80..0x800b1ac0
RomFont::~RomFont() {}

// PAL: 0x800b1ac0..0x800b1ae0
void* RomFont::Unload() {
  void* buffer = mBuffer;
  mBuffer = NULL;
  return buffer;
}

// PAL: 0x800b1ae0..0x800b1af0
int RomFont::GetWidth() const {
  return static_cast<OSFontHeader*>(mBuffer)->charWidth;
}

// PAL: 0x800b1af0..0x800b1b50
int RomFont::GetHeight() const { return GetAscent() + GetDescent(); }

// PAL: 0x800b1b50..0x800b1b60
int RomFont::GetAscent() const {
  return static_cast<OSFontHeader*>(mBuffer)->ascent;
}

// PAL: 0x800b1b60..0x800b1b70
int RomFont::GetDescent() const {
  return static_cast<OSFontHeader*>(mBuffer)->descent;
}

// PAL: 0x800b1b70..0x800b1b80
int RomFont::GetBaselinePos() const {
  return static_cast<OSFontHeader*>(mBuffer)->ascent;
}

// PAL: 0x800b1b80..0x800b1b90
int RomFont::GetCellHeight() const {
  return static_cast<OSFontHeader*>(mBuffer)->cellHeight;
}

// PAL: 0x800b1b90..0x800b1ba0
int RomFont::GetCellWidth() const {
  return static_cast<OSFontHeader*>(mBuffer)->cellWidth;
}

// PAL: 0x800b1ba0..0x800b1bb0
int RomFont::GetMaxCharWidth() const {
  return static_cast<OSFontHeader*>(mBuffer)->charWidth;
}

// PAL: 0x800b1bb0..0x800b1bc0
int RomFont::GetType() const { return 1; }

// PAL: 0x800b1bc0..0x800b1bd0
int RomFont::GetTextureFormat() const { return 0; }

// PAL: 0x800b1bd0..0x800b1be0
int RomFont::GetLineFeed() const {
  return static_cast<OSFontHeader*>(mBuffer)->linefeed;
}

// PAL: 0x800b1be0..0x800b1c00
CharWidths RomFont::GetDefaultCharWidths() const { return mDefaultCharWidths; }

// PAL: 0x800b1c00..0x800b1c20
void RomFont::SetDefaultCharWidths(const CharWidths& rDefaultCharWidths) {
  mDefaultCharWidths = rDefaultCharWidths;
}

bool RomFont::HandleUndefinedChar(u16 undefChar) const {
  return HasGlyph(undefChar) ? undefChar : mAlternateChar;
}

// PAL: 0x800b1c20..0x800b1cb0
bool RomFont::SetAlternateChar(u16 alt) {

  u16 prevAlt;

  u8 lo;
  u8 hi;

  bool cond;

  prevAlt = mAlternateChar;

  mAlternateChar = 0xFFFF;

  // cond = HandleUndefinedChar(alt);
  switch (mFontEncode) {
  case OS_ENCODE_CP1252:
    cond = IsCP1252Char(alt);
    break;
  case OS_ENCODE_SJIS:
    cond = IsSJISHalfWidthChar(alt) ||
           (hi = BitExtract<u16>(alt, 8, 8), lo = BitExtract<u16>(alt, 8, 0),
            IsSJISLeadByte(hi) && IsSJISTrailByte(lo));
    break;
  }

  if ((cond ? alt : mAlternateChar) != 0xFFFF) {
    mAlternateChar = alt;
    return true;
  }

  mAlternateChar = prevAlt;
  return false;
}

// PAL: 0x800b1cb0..0x800b1cc0
void RomFont::SetLineFeed(int lf) {
  static_cast<OSFontHeader*>(mBuffer)->linefeed = lf;
}

// PAL: 0x800b1cc0..0x800b1d50
int RomFont::GetCharWidth(u16 ch) const {
  bool cond;

  u8 hi;
  u8 lo;

  u8 nch;

  u32 width;
  char str[4];

  cond = HandleUndefinedChar(ch);

  ch = cond ? ch : mAlternateChar;

  if ((nch = BitExtract<u16>(ch, 8, 8)) == 0) {
    str[0] = ch;
    str[1] = '\0';
  } else {
    str[0] = nch;
    str[1] = ch;
    str[2] = '\0';
  }

  OSGetFontWidth(str, &width);

  return width;
}

// PAL: 0x800b1d50..0x800b1da0
CharWidths RomFont::GetCharWidths(u16 ch) const {
  u8 chWidth = GetCharWidth(ch);

  CharWidths widths;

  widths.BYTE_0x1 = chWidth;
  widths.BYTE_0x0 = 0;
  widths.BYTE_0x2 = chWidth;

  return widths;
}

// PAL: 0x800b1da0..0x800b1ea0
void RomFont::GetGlyph(Glyph* pGlyph, u16 ch) const {
  bool cond;

  u8 hi;
  u8 lo;

  u8 nch;

  u8* stack_0x18;
  int stack_0x14;
  int stack_0x10;
  int stack_0xc;

  char str[4];

  OSFontHeader* header;

  cond = HandleUndefinedChar(ch);

  ch = cond ? ch : mAlternateChar;

  if ((nch = BitExtract<u16>(ch, 8, 8)) == 0) {
    str[0] = ch;
    str[1] = '\0';
  } else {
    str[0] = nch;
    str[1] = ch;
    str[2] = '\0';
  }

  OSGetFontTexture(str, &stack_0x18, &stack_0x14, &stack_0x10, &stack_0xc);

  pGlyph->PTR_0x0 = stack_0x18;

  pGlyph->BYTE_0x4 = 0;
  pGlyph->cellWidth = stack_0xc;
  pGlyph->BYTE_0x6 = stack_0xc;
  pGlyph->cellHeight = static_cast<OSFontHeader*>(mBuffer)->cellHeight;

  pGlyph->WORD_0x8 = 0;

  pGlyph->SHORT_0xC = static_cast<OSFontHeader*>(mBuffer)->SHORT_0x1E;
  pGlyph->SHORT_0xE = static_cast<OSFontHeader*>(mBuffer)->SHORT_0x20;
  pGlyph->SHORT_0x10 = stack_0x14;
  pGlyph->SHORT_0x12 = stack_0x10;
}

bool RomFont::HasGlyph(u16 c) const {
  switch (mFontEncode) {
  case OS_ENCODE_CP1252:
    return IsCP1252Char(c);
  case OS_ENCODE_SJIS:
    return (IsSJISHalfWidthChar(c) || IsSJISFullWidthChar(c));
  default:
    return false;
  }
}

// PAL: 800b1f60
FontEncoding RomFont::GetEncoding() const {
  switch (mFontEncode) {
  case OS_ENCODE_CP1252:
    return FontEnc_CP1252;
  case OS_ENCODE_SJIS:
    return FontEnc_SJIS;
  }

  return FontEnc_CP1252;
}

} // namespace ut
} // namespace nw4r
