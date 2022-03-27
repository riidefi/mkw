#pragma once

#include <decomp.h>

#include "ut_font.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_RomFont.h
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {
struct RomFont : Font {
  static u16 mFontEncode;

  void* mBuffer;

  CharWidths mDefaultCharWidths;

  u16 mAlternateChar;

  RomFont();
  ~RomFont();

  bool Unload(void*);
  bool Load(void*);
  u32 GetRequireBufferSize();

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

  bool HandleUndefinedChar(u16) const; // inlined
  bool SetAlternateChar(u16);

  void SetLineFeed(int);
  int GetCharWidth(u16) const;
  CharWidths GetCharWidths(u16) const;

  void GetGlyph(Glyph*, u16) const;
  bool HasGlyph(u16) const;

  FontEncoding GetEncoding() const;
};

} // namespace ut
} // namespace nw4r
