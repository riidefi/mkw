#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_ResFontBase.h
// Credit: GibHaltmannKill

#include <rk_types.h>
#include <decomp.h>

#include "ut_font.hpp"

namespace nw4r {
namespace ut {
struct FontWidth {
  u16 mFirstChar;
  u16 mLastChar;
  FontWidth* mNext;         // at 0x4
  CharWidths mWidthTable[]; // at 0x8 (flexible array member)
};

enum FontMapping { FontMap_Linear, FontMap_Array, FontMap_Morphism };

struct FontCodeMap {
  u16 mFirstChar;
  u16 mLastChar;
  u16 mType;
  FontCodeMap* mNext; // at 0x8
  u16 mGlyphTable[];  // at 0xc (flexible array member)
};

struct FontTextureGlyph {
  u8 mCellWidth;  // at 0x0
  u8 mCellHeight; // at 0x1

  s8 mBaselinePos; // at 0x2

  u8 mMaxCharWidth; // at 0x3

  int WORD_0x4; // at 0x4

  short UNK_0x8;
  u16 mFormat; // at 0xa

  u16 SHORT_0xC;
  u16 SHORT_0xE;
  u16 SHORT_0x10;
  u16 SHORT_0x12;
  u8* PTR_0x14;
};

struct FontInformation {
  char UNK_0x0;
  s8 mLineFeed; // at 0x1

  u16 mAlternateChar;

  CharWidths mDefaultCharWidths; // at 0x4
  u8 mEncoding;                  // at 0x7
  FontTextureGlyph* mTextureGlyph;
  FontWidth* mWidthList;
  FontCodeMap* mCodeMapList;
  u8 mHeight; // at 0x14
  u8 mWidth;  // at 0x15

  u8 mAscent; // at 0x16
};

namespace detail {
struct ResFontBase : Font {
  void* mBuffer;
  FontInformation* mFontInfo;

  ResFontBase();
  ~ResFontBase();

  void SetResourceBuffer(void*, FontInformation*);
  int GetWidth() const;
  int GetHeight() const;
  int GetAscent() const;
  int GetDescent() const;
  int GetBaselinePos() const;
  int GetCellHeight() const;
  int GetCellWidth() const;
  int GetMaxCharWidth() const;
  int GetType() const;
  int GetTextureFormat() const;
  int GetLineFeed() const;
  CharWidths GetDefaultCharWidths() const;
  void SetDefaultCharWidths(const CharWidths&);
  bool SetAlternateChar(u16);
  void SetLineFeed(int);
  int GetCharWidth(u16) const;
  CharWidths GetCharWidths(u16) const;
  void GetGlyph(Glyph*, u16) const;
  bool HasGlyph(u16) const;
  FontEncoding GetEncoding() const;

  int GetGlyphFromIndex(Glyph*, u16) const;
  u16 FindGlyphIndex(const FontCodeMap*, u16) const;

  // Inlined functions
  u16 GetGlyphIndex(u16) const;
  u16 FindGlyphIndex(u16) const;

  const CharWidths& GetCharWidthsFromIndex(u16) const;
  const CharWidths& GetCharWidthsFromIndex(const FontWidth*, u16) const;
};
} // namespace detail
} // namespace ut
} // namespace nw4r
