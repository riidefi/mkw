#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_SoundHeap.h
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <rk_types.h>

#include <rvl/os/osMutex.h>
#include "snd_frameHeap.hpp"
#include "snd_soundMemoryAllocatable.hpp"

namespace nw4r {
namespace snd {

struct SoundHeap : SoundMemoryAllocatable {
  SoundHeap();
  virtual ~SoundHeap(); // vt 0x08
  bool Create(void*, u32);
  void Destroy();
  virtual void* Alloc(u32); // vt 0x0c

  OSMutex mMutex; // 0x00
  detail::FrameHeap mFrameHeap;
};

} // namespace snd
} // namespace nw4r
