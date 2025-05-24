#include "ut_font.hpp"

// Source: https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_Font.h
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {
void Font::InitReaderFunc(FontEncoding enc) {
  switch (enc) {
  case FontEnc_UTF8:
    mReaderFunc = &CharStrmReader::ReadNextCharUTF8;
    return;
  case FontEnc_UTF16:
    mReaderFunc = &CharStrmReader::ReadNextCharUTF16;
    return;
  case FontEnc_SJIS:
    mReaderFunc = &CharStrmReader::ReadNextCharSJIS;
    return;
  case FontEnc_CP1252:
  default:
    mReaderFunc = &CharStrmReader::ReadNextCharCP1252;
    return;
  }
}
} // namespace ut
} // namespace nw4r
