#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_SoundMemoryAllocatable.h
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <rk_types.h>

namespace nw4r {
namespace snd {

struct SoundMemoryAllocatable {
  virtual ~SoundMemoryAllocatable() {} // 0x08
  virtual void* Alloc(u32) = 0;        // 0x0c
};

} // namespace snd
} // namespace nw4r
