/**
 * @file
 * @brief Heap implementations.
 */
#include <egg/core/eggHeap.hpp>
#include <egg/eggInternal.hpp>
#include <nw4r/ut/utList.hpp>
#include <rvl/os/osThread.h>

namespace EGG {

// bss
nw4r::ut::List Heap::sHeapList;
OSMutex Heap::sRootMutex;
// sbss
Heap* Heap::sCurrentHeap;
int Heap::sIsHeapListInitialized;
Heap* Heap::sAllocatableHeap;

void* Heap::sErrorCallback;
void* Heap::sAllocCallback;

void* Heap::sErrorCallbackArg;
void* Heap::sAllocCallbackArg;

Thread* Heap::sAllocatableThread;

#define SIZE_MB 0x100000

void Heap::initialize() {
  nw4r::ut::List_Init(&sHeapList, 32);
  OSInitMutex(&sRootMutex);
  sIsHeapListInitialized = true;
}
Heap::Heap(rvlHeap* pHeap) : Disposer(), mHeapHandle(pHeap) {
  mParentBlock = nullptr;
  mParentHeap = nullptr;
  mName = "NoName";
  mFlag = 0;

  // Initialize child heap linked list.
  nw4r::ut::List_Init(&mChildren, 8);

  // The static Heap members (set by initialize()) must be configured first.
  EGG_ASSERT(sIsHeapListInitialized, "eggHeap.cpp", 63,
             "Please call Heap::initialize()");

  // Add the heap to the static heap list.
  OSLockMutex(&sRootMutex);
  nw4r::ut::List_Append(&sHeapList, this);
  OSUnlockMutex(&sRootMutex);
}

} // namespace EGG