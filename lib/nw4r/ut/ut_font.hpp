#pragma once

#include <rk_types.h>

// Source: https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_Font.h
// Credit: GibHaltmannKill

#include "ut_CharStrmReader.hpp"
#include "ut_glyph.hpp"

namespace nw4r {
namespace ut {
struct CharWidths {
  char BYTE_0x0;
  char BYTE_0x1;
  char BYTE_0x2;
};

enum FontEncoding { FontEnc_UTF8, FontEnc_UTF16, FontEnc_SJIS, FontEnc_CP1252 };

struct Font {
  __declspec(weak) virtual ~Font() {} // 0x8

  virtual int GetWidth() const = 0;   // 0xc
  virtual int GetHeight() const = 0;  // 0x10
  virtual int GetAscent() const = 0;  // 0x14
  virtual int GetDescent() const = 0; // 0x18
  virtual int GetBaselinePos() const = 0;
  virtual int GetCellHeight() const = 0;
  virtual int GetCellWidth() const = 0;
  virtual int GetMaxCharWidth() const = 0;
  virtual int GetType() const = 0;
  virtual int GetTextureFormat() const = 0;
  virtual int GetLineFeed() const = 0;
  virtual CharWidths GetDefaultCharWidths() const = 0;
  virtual void SetDefaultCharWidths(const CharWidths&) = 0;
  virtual bool SetAlternateChar(u16) = 0;
  virtual void SetLineFeed(int) = 0;
  virtual int GetCharWidth(u16) const = 0;
  virtual CharWidths GetCharWidths(u16) const = 0;
  virtual void GetGlyph(Glyph*, u16) const = 0;
  virtual bool HasGlyph(u16) const = 0;
  virtual FontEncoding GetEncoding() const = 0;

  u16 (CharStrmReader::*mReaderFunc)();

  void InitReaderFunc(FontEncoding);

  inline CharStrmReader GetCharStrmReader() const
      __attribute__((never_inline)) {
    return CharStrmReader(mReaderFunc);
  }

  inline Font() : mReaderFunc(&CharStrmReader::ReadNextCharCP1252) {}
};

} // namespace ut
} // namespace nw4r
