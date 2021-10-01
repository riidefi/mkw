#pragma once

#include <rk_types.h>

#include "decomp.h"

namespace nw4r {
namespace snd {

class DvdSoundArchive {
public:
  // PAL: 0x80090fc0..0x80091010
  DvdSoundArchive();
  // PAL: 0x80091010..0x80091090
  ~DvdSoundArchive();

  // PAL: 0x80091090..0x800911d0
  bool Open(const char* path);
  // PAL: 0x800911d0..0x80091210
  void Close();

  // PAL: 0x80091380..0x80091390
  int detail_GetRequiredStreamBufferSize__Q34nw4r3snd15DvdSoundArchiveFv();
  // PAL: 0x80091390..0x80091420
  bool LoadHeader(void* buf, u32 size);

private:
  // PAL: 0x80091210..0x800912c0
  void* OpenStream(void* buf, int size, u32 offset, u32 limit);
  // PAL: 0x800912c0..0x80091380
  void* OpenExtStream(void* buf, int size, const char* path, u32 offset,
                      u32 limit);
};

} // namespace snd
} // namespace nw4r
