#pragma once

#include <rk_types.h>

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_Glyph.h
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

struct Glyph {
  u8* PTR_0x0;

  s8 BYTE_0x4;
  u8 cellWidth; // at 0x5
  s8 BYTE_0x6;
  u8 cellHeight; // at 0x7

  // char BYTES_0x4[4];

  int WORD_0x8;

  unsigned short SHORT_0xC;
  unsigned short SHORT_0xE;
  unsigned short SHORT_0x10;
  unsigned short SHORT_0x12;
};

} // namespace ut
} // namespace nw4r
