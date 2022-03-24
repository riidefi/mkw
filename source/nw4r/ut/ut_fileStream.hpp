#pragma once

#include <rk_types.h>

#include "ut_IOStream.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_FileStream.h
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

class FileStream : public IOStream {
public:
  inline FileStream() : BOOL_0x4(false), ASYNC_0xC(NULL), PTR_0x10(NULL) {}
  inline virtual ~FileStream() {}

  void Cancel();

  bool CancelAsync(AsyncFunctor, void*);

  class FilePosition {
  public:
    inline FilePosition() : mFileSize(), mFileOffset() {}

    inline u32 Tell() const { return mFileOffset; }

    inline u32 GetFileSize() const { return mFileSize; }

    inline void SetFileSize(u32 fileSize) { mFileSize = fileSize; }

  public:
    u32 mFileSize;
    u32 mFileOffset;

    u32 Skip(s32);
    u32 Append(s32);
    void Seek(s32, u32);
  };

protected:
  bool BOOL_0x4;
  u32 WORD_0x8;
  AsyncFunctor ASYNC_0xC;
  void* PTR_0x10;
  static detail::RuntimeTypeInfo typeInfo;
};

} // namespace ut
} // namespace nw4r
