#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_SoundArchive.h
// Credit: GibHaltmannKill

#include <rk_types.h>
#include <decomp.h>

namespace nw4r {
namespace snd {

class SoundArchive {
public:
  virtual ~SoundArchive();                                          // 0x8
  virtual const void* detail_GetFileAddress(u32) const = 0;         // 0xc
  virtual const void* detail_GetWaveDataFileAddress(u32) const = 0; // 0x10
  virtual int detail_GetRequiredStreamBufferSize() const = 0;       // 0x14
  virtual void* OpenStream(void*, int, u32, u32) const = 0;         // 0x18
  virtual void* OpenExtStream(void*, int, const char*, u32,
                              u32) const = 0; // 0x1c

  void* mFileReader;             // 0x4
  char mExternalFileRoot[0x100]; // 0x8

public:
  SoundArchive();

  // PAL: 0x8009dea0
  void Shutdown();
};

} // namespace snd
} // namespace nw4r
