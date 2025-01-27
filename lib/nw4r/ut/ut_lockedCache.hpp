#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_LockedCache.h
// Credit: GibHaltmannKill

#include <rk_types.h>

#include <rvl/os/osMutex.h>
#include <rvl/os/osCache.h>
#include <rvl/os/osThread.h>

namespace nw4r {
namespace ut {
namespace LC {
void Enable();
void Disable();
bool Lock();
void Unlock();
void LoadBlocks(void*, void*, u32);
void StoreBlocks(void*, void*, u32);
void StoreData(void*, void*, u32);

inline void QueueWaitEx(u32 num) {
  while (LCQueueLength() != num)
    OSYieldThread();
}
} // namespace LC
} // namespace ut
} // namespace nw4r
