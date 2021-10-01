#pragma once

// Credit: kiwi51

#include <rk_types.h>

namespace nw4r {
namespace snd {

struct SoundMemoryAllocatable {
  virtual ~SoundMemoryAllocatable() {} // 0x08
  virtual void* Alloc(u32) = 0;        // 0x0c
};

} // namespace snd
} // namespace nw4r
