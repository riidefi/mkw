/*!
 * @file
 * @brief EGG wraper for expanded heaps implementation.
 */

#include <egg/core/eggExpHeap.hpp>
#include <nw4r/ut/utInlines.hpp>
#include <rvl/mem/expHeap.h>

inline void* operator new(unsigned long, void* p) { return p; }

namespace EGG {

enum {
  EXP_HEAP_BASE_SIZE = 56, // (sizeof(ExpHeap) - sizeof(...)),
  EXP_HEAP_ALIGN = 4
};

ExpHeap::~ExpHeap() {
  // Recursively free all memory
  Heap::dispose();

  // Destroy the wrapped MEM heap
  MEMDestroyExpHeap(mHeapHandle);
}

ExpHeap* ExpHeap::create(void* block, u32 size, u16 attr) {
  ExpHeap* createdHeap = nullptr; // r30

  u32 heapEnd = nw4r::ut::RoundDown((u32)block + size, EXP_HEAP_ALIGN); // r3
  u32 heapStart = nw4r::ut::RoundUp((u32)block, EXP_HEAP_ALIGN);        // r27

  // Enforce requirement for 56 byte ExpHeap object + minimum 4 bytes in heap.
  if (heapStart > heapEnd ||
      heapEnd - heapStart < EXP_HEAP_BASE_SIZE + EXP_HEAP_ALIGN) {
    createdHeap = nullptr;
  } else {
    // We reserve 56 bytes in the heap.
    MEMHeapHandle hnd = MEMCreateExpHeapEx(
        reinterpret_cast<void*>(heapStart + EXP_HEAP_BASE_SIZE),
        heapEnd - heapStart - EXP_HEAP_BASE_SIZE, attr); // r28

    if (hnd) {
      Heap* contain =
          Heap::findContainHeap(reinterpret_cast<void*>(heapStart)); // r31

      createdHeap = new (reinterpret_cast<void*>(heapStart)) ExpHeap(hnd);

      createdHeap->mParentBlock = block;
      createdHeap->mParentHeap = contain;
    }
  }

  return createdHeap;
}

ExpHeap* ExpHeap::create(u32 size, Heap* heap, u16 attr) {
  ExpHeap* newHeap = nullptr;

  if (heap == nullptr)
    heap = Heap::sCurrentHeap;
  if (size == -1)
    size = heap->getAllocatableSize(4);

  void* block = heap->alloc(size, 4);
  if (block) {
    newHeap = ExpHeap::create(block, size, attr);

    if (newHeap)
      newHeap->mParentHeap = heap;
    else
      heap->free(block);
  }

  return newHeap;
}

void ExpHeap::destroy() {
  Heap* parentHeap = findParentHeap();

  (*this).~ExpHeap();

  if (parentHeap)
    parentHeap->free(this);
}
extern "C" void OSPanic(const char* file, u32 line, const char* msg, ...);
void* ExpHeap::alloc(u32 size, s32 align) {
  if ((mFlag & HEAP_FLAG_LOCKED) != 0)
    OSPanic("eggExpHeap.cpp", 174, "DAME DAME\n");

  return MEMAllocFromExpHeapEx(mHeapHandle, size, align);
}

void ExpHeap::free(void* block) { MEMFreeToExpHeap(mHeapHandle, block); }

u32 ExpHeap::resizeForMBlock(void* memBlock, u32 size) {
  return MEMResizeForMBlockExpHeap(mHeapHandle, memBlock, size);
}

u32 ExpHeap::getTotalFreeSize() {
  return MEMGetTotalFreeSizeForExpHeap(mHeapHandle);
}

u32 ExpHeap::getAllocatableSize(s32 align) {
  return MEMGetAllocatableSizeForExpHeapEx(mHeapHandle, align);
}

u16 ExpHeap::setGroupID(u16 groupID) {
  return MEMSetGroupIDForExpHeap(mHeapHandle, groupID);
}

void ExpHeap::addGroupSize(void* block, MEMHeapHandle heap, u32 userParam) {
  u16 grpID = MEMGetGroupIDForMBlockExpHeap(block);
  // below may return
  ((GroupSizeRecord*)userParam)
      ->addSize(grpID, MEMGetSizeForMBlockExpHeap(block));
}

void ExpHeap::calcGroupSize(GroupSizeRecord* record) {
  record->reset();
  MEMVisitAllocatedForExpHeap(mHeapHandle, addGroupSize, (u32)record);
}

u32 ExpHeap::adjust() {
  u32 adjustedSize = MEMAdjustExpHeap(mHeapHandle) + 56;

  if (adjustedSize > 56 && mParentHeap) {
    mParentHeap->resizeForMBlock(mParentBlock, adjustedSize);
    return adjustedSize;
  }

  return nullptr;
}

void ExpHeap::initAllocator(Allocator* allocator, s32 align) {
  MEMInitAllocatorForExpHeap((MEMAllocator*)allocator, mHeapHandle, align);
}

ExpHeap::GroupSizeRecord::GroupSizeRecord() { reset(); }

void ExpHeap::GroupSizeRecord::reset() {
  u32* iterEntry = &entries[0];
  for (int i = 0; i < 256; i++) {
    *iterEntry = 0;
    iterEntry++;
  }
}

void ExpHeap::GroupSizeRecord::addSize(u16 groupID, u32 size) {
  entries[groupID] += size;
}

namespace {
void free_all_visitor(void* block, MEMHeapHandle heap, u32 userParam) {
  MEMFreeToExpHeap(heap, block);
}
} // namespace

void ExpHeap::freeAll() {
  Heap::dispose();

  MEMVisitAllocatedForExpHeap(mHeapHandle, &free_all_visitor, 0);
}

Heap::eHeapKind ExpHeap::getHeapKind() const {
  return Heap::HEAP_KIND_EXPANDED;
}

} // namespace EGG
