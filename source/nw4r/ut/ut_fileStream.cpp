#include "ut_fileStream.hpp"

// Credit: kiwi515

namespace nw4r {
namespace ut {

namespace {
template <typename T> static inline T Clamp(T value, T min, T max) {
  if (max < value)
    return max;
  return (value < min) ? min : value;
}

template <typename T> static inline T Max(T t1, T t2) {
  return (t1 < t2) ? t2 : t1;
}
} // namespace

// PAL: 0x800afef0..0x800aff00
void FileStream::Cancel() {}

bool FileStream::CancelAsync() { return true; }

// PAL: 0x800aff10..0x800aff80
u32 FileStream::FilePosition::Skip(s32 offset) {
  if (offset) {
    s64 position = mFileOffset + offset;
    position = Clamp<s64>(position, 0, mFileSize);
    mFileOffset = static_cast<u32>(position);
  }

  return mFileOffset;
}

// PAL: 0x800aff80..0x800affd0
u32 FileStream::FilePosition::Append(s32 offset) {
  s64 r5 = mFileOffset + offset;

  if (r5 < 0LL) {
    mFileOffset = 0;
  } else {
    mFileOffset = r5;
    mFileSize = Max<u32>(mFileOffset, mFileSize);
  }

  return mFileOffset;
}

// PAL: 0x800affd0..0x800b0058
void FileStream::FilePosition::Seek(s32 offset, u32 origin) {
  switch (origin) {
  case 0:
    mFileOffset = 0;
    break;
  case 2:
    mFileOffset = mFileSize;
    break;
  case 1:
  default:
    break;
  }

  Skip(offset);
}

} // namespace ut
} // namespace nw4r
