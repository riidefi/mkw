/**
 * @file
 * @brief Heap implementations.
 */

#define HEAP_PRIVATE public

#include <stddef.h>

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggHeap.hpp>
#include <egg/core/eggThread.hpp>
#include <egg/eggInternal.hpp>
#include <nw4r/ut/utList.hpp>
#include <rvl/os/osError.h>
#include <rvl/os/osThread.h>

extern "C" struct OSThread* OSGetCurrentThread();

namespace EGG {

// bss
nw4r::ut::List Heap::sHeapList;
OSMutex Heap::sRootMutex;
// sbss
Heap* Heap::sCurrentHeap;
int Heap::sIsHeapListInitialized;
Heap* Heap::sAllocatableHeap;
ErrorCallback Heap::sErrorCallback;
HeapAllocCallback Heap::sAllocCallback;

void* Heap::sErrorCallbackArg;
void* Heap::sAllocCallbackArg;

Thread* Heap::sAllocatableThread;

#define SIZE_MB ((float)0x100000)

void Heap::initialize() {
  nw4r::ut::List_Init(&sHeapList, offsetof(Heap, mNode));
  OSInitMutex(&sRootMutex);
  sIsHeapListInitialized = true;
}
Heap::Heap(MEMiHeapHead* pHeap) : Disposer(), mHeapHandle(pHeap) {
  mParentBlock = nullptr;
  mParentHeap = nullptr;
  mName = "NoName";
  mFlag = 0;

  // Initialize child heap linked list.
  nw4r::ut::List_Init(&mChildren, offsetof(Disposer, mLink));

  // The static Heap members (set by initialize()) must be configured first.
  EGG_ASSERT(sIsHeapListInitialized, "eggHeap.cpp", 63,
             "Please call Heap::initialize()");

  // Add the heap to the static heap list.
  OSLockMutex(&sRootMutex);
  nw4r::ut::List_Append(&sHeapList, this);
  OSUnlockMutex(&sRootMutex);
}

Heap::~Heap() {
  OSLockMutex(&sRootMutex);
  nw4r::ut::List_Remove(&sHeapList, this);
  OSUnlockMutex(&sRootMutex);
}

#pragma dont_reuse_strings on
void* Heap::alloc(u32 size, int align, Heap* heap) {
  Heap* currentHeap = sCurrentHeap;                                 // r28
  Thread* currentThread = Thread::findThread(OSGetCurrentThread()); // r29

  if (sAllocatableThread != nullptr) {
    // this does absolutely nothing. possibly debug
    // message stripped?
    OSGetCurrentThread();
  }

  // If our thread defines a heap override, use it!
  if (currentThread != nullptr &&
      currentThread->getAllocatableHeap() != nullptr)
    heap = currentHeap = currentThread->getAllocatableHeap();

  // if sAllocatableHeap is not nullptr, it *must* be used
  // this has higher priority over the thread heap override!
  if (sAllocatableHeap != nullptr) {
    if (currentHeap != nullptr && heap == nullptr)
      heap = currentHeap;

    // This would be reached if
    // - sCurrentHeap && !heap && sCurrentHeap != sAlloctableHeap
    // - heap && heap != sAllocatableHeap
    if (heap != sAllocatableHeap) {
      OSReport(
          "cannot allocate from heap %x(%s) : allocatable heap is %x(%s)\n",
          heap, heap->mName, sAllocatableHeap, sAllocatableHeap->mName);

      const Heap* primary_heap =
          currentThread ? currentThread->getAllocatableHeap() : nullptr;

      OSReport("\tthread heap=%x\n", primary_heap);

      const char* primary_heap_name =
          currentThread ? (currentThread->getAllocatableHeap()
                               ? currentThread->getAllocatableHeap()->mName
                               : "none")
                        : "none";
      OSReport("\tthread heap=%s\n", primary_heap_name);
      if (sErrorCallback) {
        HeapErrorArg cb;
        cb.msg = "disable_but";
        cb.userdata = sErrorCallbackArg;
        sErrorCallback(&cb);
      }
      dumpAll();
      return nullptr;
    }
  }
  // alloc callback
  if (sAllocCallback) {
    HeapAllocArg arg;
    arg.heap = heap ? heap : currentHeap;
    arg.size = size;
    arg.align = align;
    arg.userArg = (int)sAllocCallbackArg;
    sAllocCallback(arg);
  }
  // If heap is non nullptr, use that
  if (heap != nullptr)
    return heap->alloc(size, align);

  // If we're here the argument heap is nullptr, so we can't use it.
  // We're left with using the static current heap. If that doesn't exist, we
  // can't do anything.
  if (currentHeap != nullptr) {
    void* allocated = currentHeap->alloc(size, align); // (r3), r27

    if (allocated == nullptr) {
      int arena_end = currentHeap->getArenaEnd(); // r29
      int max_avail = currentHeap->getAllocatableSize(4);
      int heap_size = arena_end - (u32)currentHeap;
      OSReport("heap (%p):(%.1fMBytes free %d)->alloc(size(%d:%.1fMBytes),%d "
               "align)\n",
               currentHeap, static_cast<f32>(heap_size) / SIZE_MB, max_avail,
               size, static_cast<f32>(size) / SIZE_MB, align);

      dumpAll();
    }

    return allocated;
  }

  OSReport("cannot allocate %d from heap %x\n", size, heap);
  dumpAll();

  return nullptr;
}

Heap* Heap::findParentHeap() {
  EGG_ASSERT(mHeapHandle, "eggHeap.cpp", 173, "mHeapHandle != nullptr");

  return mParentHeap;
}

Heap* Heap::findContainHeap(const void* memBlock) {
  Heap* containingHeap = nullptr;
  MEMiHeapHead* memContainHeap = MEMFindContainHeap(memBlock);
  if (memContainHeap) {
    containingHeap = nullptr;
    OSLockMutex(&sRootMutex);
    if (sIsHeapListInitialized) {
      Heap* lastObject = nullptr; // r4
      while ((lastObject = (Heap*)List_GetNext(&sHeapList, lastObject))) {
        if (lastObject->mHeapHandle == memContainHeap) {
          containingHeap = lastObject;
          break;
        }
      }
    }
    OSUnlockMutex(&sRootMutex);
  }
  return containingHeap;
}
void Heap::free(void* memBlock, Heap* heap) {
  // inside likely inline getContainHeap
  if (heap == nullptr) {
    MEMiHeapHead* containHeap = MEMFindContainHeap(memBlock); // r30
    // If our memory block is not inside a head, there is not much we can do.
    if (!containHeap)
      return;
    Heap* foundHeap = nullptr; // r29
    OSLockMutex(&sRootMutex);
    if (sIsHeapListInitialized) {
      Heap* iterHeap = nullptr; // r4
      while ((iterHeap = (Heap*)nw4r::ut::List_GetNext(&sHeapList, iterHeap)) !=
             nullptr) {
        if (iterHeap->mHeapHandle == containHeap) {
          foundHeap = iterHeap;
          break;
        }
      }
    }
    OSUnlockMutex(&sRootMutex);
    heap = foundHeap;
    if (foundHeap == nullptr)
      return;
  }
  heap->free(memBlock);
}

void Heap::dispose() {
  Disposer* it = nullptr;
  // This isn't an infinite loop: the destructor detaches itself..
  while ((it = (Disposer*)nw4r::ut::List_GetFirst(&mChildren)))
    it->~Disposer();
}

void Heap::dumpAll() {
  Heap* it = nullptr; // r27
  Heap* parent_it;    // r26
  // These are incremented, but never used. Likely used in stripped debug
  // message.
  u32 mem1_remaining = 0; // r30
  u32 mem2_remaining = 0; // r31

  while ((it = (Heap*)List_GetNext(&sHeapList, it))) {
    parent_it = nullptr; // r26

    if ((u32)it->getStartAddress() < 0x90000000) // MEM2
      mem1_remaining += it->getAllocatableSize(4);
    else
      mem2_remaining += it->getAllocatableSize(4);

    while ((parent_it = (Heap*)List_GetNext(&sHeapList, parent_it))) {
      if (it->getParentHeap() == parent_it)
        goto next;
    }
  next:;
  }
}

Heap* Heap::becomeCurrentHeap() {
  OSLockMutex(&Heap::sRootMutex);
  Heap* oldCurrentHeap = Heap::sCurrentHeap; // r30
  Heap::sCurrentHeap = this;
  OSUnlockMutex(&Heap::sRootMutex);
  return oldCurrentHeap;
}
} // namespace EGG

void* operator new(size_t size) { return EGG::Heap::alloc(size, 4, nullptr); }
void* operator new[](size_t size, u32 align) {
  return EGG::Heap::alloc(size, align, nullptr);
}
void* operator new(size_t size, EGG::Heap* heap, int align) {
  return EGG::Heap::alloc(size, align, heap);
}
void* operator new[](size_t size) { return EGG::Heap::alloc(size, 4, nullptr); }
void* operator new[](size_t size, int align) {
  return EGG::Heap::alloc(size, align, nullptr);
}
void* operator new[](size_t size, EGG::Heap* heap, int align) {
  return EGG::Heap::alloc(size, align, heap);
}

void operator delete(void* memBlock) {
  MEMiHeapHead* containHeap = MEMFindContainHeap(memBlock); // r30
  // If our memory block is not inside a head, there is not much we can do.
  if (!containHeap)
    return;
  EGG::Heap* foundHeap = nullptr; // r29
  OSLockMutex(&EGG::Heap::sRootMutex);
  if (EGG::Heap::sIsHeapListInitialized) {
    EGG::Heap* iterHeap = nullptr; // r4
    while ((iterHeap = (EGG::Heap*)nw4r::ut::List_GetNext(
                &EGG::Heap::sHeapList, iterHeap)) != nullptr) {
      if (iterHeap->mHeapHandle == containHeap) {
        foundHeap = iterHeap;
        break;
      }
    }
  }
  OSUnlockMutex(&EGG::Heap::sRootMutex);
  EGG::Heap* heap = foundHeap;
  if (foundHeap == nullptr)
    return;
  heap->free(memBlock);
}
void operator delete[](void* memBlock) {
  MEMiHeapHead* containHeap = MEMFindContainHeap(memBlock); // r30
  // If our memory block is not inside a head, there is not much we can do.
  if (!containHeap)
    return;
  EGG::Heap* foundHeap = nullptr; // r29
  OSLockMutex(&EGG::Heap::sRootMutex);
  if (EGG::Heap::sIsHeapListInitialized) {
    EGG::Heap* iterHeap = nullptr; // r4
    while ((iterHeap = (EGG::Heap*)nw4r::ut::List_GetNext(
                &EGG::Heap::sHeapList, iterHeap)) != nullptr) {
      if (iterHeap->mHeapHandle == containHeap) {
        foundHeap = iterHeap;
        break;
      }
    }
  }
  OSUnlockMutex(&EGG::Heap::sRootMutex);
  EGG::Heap* heap = foundHeap;
  if (foundHeap == nullptr)
    return;
  heap->free(memBlock);
}
