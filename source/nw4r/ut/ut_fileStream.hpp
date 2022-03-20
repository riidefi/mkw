#pragma once

#include <rk_types.h>

// Credit: kiwi515

namespace nw4r {
namespace ut {

class FileStream {

  void Cancel();

  bool CancelAsync();

  class FilePosition {

    u32 mFileSize;
    u32 mFileOffset;

    u32 Skip(s32);
    u32 Append(s32);
    void Seek(s32, u32);
  };
};

} // namespace ut
} // namespace nw4r
