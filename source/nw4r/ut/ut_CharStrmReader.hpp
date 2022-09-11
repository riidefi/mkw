#pragma once

#include <rk_types.h>

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_CharStrmReader.h
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

struct CharStrmReader {
  const char* mStrm;
  u16 (CharStrmReader::*mFunc)();

  inline CharStrmReader(u16 (CharStrmReader::*func)())
      : mStrm(NULL), mFunc(func) {}

  u16 ReadNextCharUTF8();
  u16 ReadNextCharUTF16();
  u16 ReadNextCharCP1252();
  u16 ReadNextCharSJIS();

  template <typename T> inline T GetChar(int offset) const {
    const T* strm = reinterpret_cast<const T*>(mStrm);
    return strm[offset];
  }

  template <typename T> inline void StepStrm(int offset) volatile {
    mStrm += sizeof(T) * offset;
  }

  inline u16 Next() { return (this->*mFunc)(); }

  inline void Set(const char* pStrm) { mStrm = pStrm; }

  inline void Set(const wchar_t* pStrm) {
    mStrm = reinterpret_cast<const char*>(pStrm);
  }
};

} // namespace ut
} // namespace nw4r
