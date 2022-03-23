#pragma once

#include <rk_types.h>
#include <rvl/os/osMutex.h>
#include <rvl/os/osInterrupt.h>

#include "ut_dvdFileStream.hpp"

// Stolen from ogws.
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

class DvdLockedFileStream : DvdFileStream {
public:
  DvdLockedFileStream(s32);
  DvdLockedFileStream(const DVDFileInfo*, bool);

  virtual ~DvdLockedFileStream();

  void Close();
  int Read(void*, u32);
  s32 Peek(void*, u32);
  void Cancel();

  bool CanAsync() const override INLINE_ELSEWHERE({return false});
  bool PeekAsync(void*, u32, AsyncFunctor, void*) override
      INLINE_ELSEWHERE({return false});
  bool ReadAsync(void*, u32, AsyncFunctor, void*) override
      INLINE_ELSEWHERE({return false});

  const detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override
      INLINE_ELSEWHERE({ return &typeInfo; });

public:
  static bool sInitialized;
  static OSMutex sMutex;
  static OSThreadQueue sThreadQueue;
  volatile bool mCancelFlag;

  static detail::RuntimeTypeInfo typeInfo;

private:
  inline void InitMutex_() {
    s32 r31 = OSDisableInterrupts();

    if (!sInitialized) {
      OSInitMutex(&sMutex);
      OSInitThreadQueue(&sThreadQueue);
      sInitialized = true;
    }

    OSRestoreInterrupts(r31);
  }

  inline void CancelMutex_() {
    s32 enabled = OSDisableInterrupts();
    mCancelFlag = true;
    OSWakeupThread(&sThreadQueue);
    (void)OSRestoreInterrupts(enabled);
  }

  inline bool LockMutex_() {
    s32 ints = OSDisableInterrupts();
    while (!OSTryLockMutex(&sMutex)) {
      OSSleepThread(&sThreadQueue);
      if (mCancelFlag) {
        OSRestoreInterrupts(ints);
        return false;
      }
    }
    OSRestoreInterrupts(ints);
    return true;
  }

  inline void UnlockMutex_() {
    s32 ints = OSDisableInterrupts();
    OSUnlockMutex(&sMutex);
    OSWakeupThread(&sThreadQueue);
    OSRestoreInterrupts(ints);
  }
};

} // namespace ut
} // namespace nw4r
