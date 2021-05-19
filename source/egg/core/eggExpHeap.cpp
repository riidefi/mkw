/*!
 * @file
 * @brief EGG wraper for expanded heaps implementation.
 */

#include <EGG/core/eggExpHeap.hpp>
#include <new>
#include <nw4r/ut/inlines.h>

namespace EGG {

ExpHeap::~ExpHeap() {
  // Recursively free all memory
  Heap::dispose();

  // Destroy the wrapped MEM heap
  MEMDestroyExpHeap(this->mHeapHandle);
}

ExpHeap* ExpHeap::create(void* block, u32 size, u16 attr) {
  u32 heapEnd = nw4r::ut::RoundDown((u32)block + size, 4); // r3
  u32 heapStart = nw4r::ut::RoundUp((u32)block, 4);        // r27

  ExpHeap* createdHeap = NULL; // r30

  // This simplifies down to size > 0;
  // as size is unsigned, we know this check will always pass.
  if (heapStart <= heapEnd) {
    u32 arenaSize = heapEnd - heapStart; // r4

    // Enforce requirement for 56 byte ExpHeap object + minimum 4 bytes in heap.
    if (arenaSize >= 60) {
      // We reserve 56 bytes in the heap.
      MEMHeapHandle memHeap = MEMCreateExpHeapEx((void*)(heapStart + 56),
                                                 arenaSize - 56, attr); // r28

      if (memHeap) {
        Heap* containHeap = Heap::findContainHeap((void*)heapStart); // r31
        new ((void*)heapStart) ExpHeap(memHeap); // Inline
        ((ExpHeap*)heapStart)->mParentBlock = block;
        ((ExpHeap*)heapStart)->mParentHeap = containHeap;
        createdHeap = (ExpHeap*)heapStart;
      }
      return createdHeap;
    }
  }

  return 0;
}
ExpHeap* ExpHeap::create(u32 size, Heap* heap, u16 attr) {
  ExpHeap* newHeap = NULL;

  if (heap == NULL)
    heap = Heap::sCurrentHeap;
  if (size == -1)
    size = heap->getAllocatableSize(4);

  if ((void* block = heap->alloc(size, 4))) {
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

  this->~ExpHeap(); // arg=-1

  if (parentHeap)
    parentHeap->free(this);
}

void* ExpHeap::alloc(u32 size, s32 align) {
  if ((this->mFlag & HEAP_FLAG_LOCKED) != 0)
    OSPanic("eggExpHeap.cpp", 174, "DAME DAME\n");

  return MEMAllocFromExpHeapEx(this->mHeapHandle, size, align);
}

void ExpHeap::free(void* block) { MEMFreeToExpHeap(this->mHeapHandle, block); }

u32 ExpHeap::resizeForMBlock(void* memBlock, u32 size) {
  return MEMResizeForMBlockExpHeap(this->mHeapHandle, memBlock, size);
}
u32 ExpHeap::getTotalFreeSize() {
  return MEMGetTotalFreeSizeForExpHeap(this->mHeapHandle);
}
u32 ExpHeap::getAllocatableSize(s32 align) {
  return MEMGetAllocatableSizeForExpHeapEx(this->mHeapHandle, align);
}
u16 ExpHeap::setGroupID(u16 groupID) {
  return MEMSetGroupIDForExpHeap(this->mHeapHandle, groupID);
}
void ExpHeap::addGroupSize(void* block, MEMHeapHandle heap, u32 userParam) {
  u32 grpID = MEMGetGroupIDForMBlockExpHeap(block);
  // below may return
  ((GroupSizeRecord*)userParam)
      ->addSize((u16)grpID, MEMGetSizeForMBlockExpHeap(block));
}
void ExpHeap::calcGroupSize(GroupSizeRecord* record) {
  record->reset();
  MEMVisitAllocatedForExpHeap(this->mHeapHandle, addGroupSize, (u32)record);
}
u32 ExpHeap::adjust() {
  u32 adjustedSize = MEMAdjustExpHeap(this->mHeapHandle) + 56;

  if (adjustedSize > 56 && mParentHeap) {
    mParentHeap->resizeForMBlock(mParentBlock, adjustedSize);
    return adjustedSize;
  } else {
    return 0;
  }
}
void ExpHeap::initAllocator(Allocator* allocator, s32 align) {
  MEMInitAllocatorForExpHeap((MEMAllocator*)allocator, this->mHeapHandle,
                             align);
}
ExpHeap::GroupSizeRecord::GroupSizeRecord() { this->reset(); }
void ExpHeap::GroupSizeRecord::reset() {
  // CW optimizes this down to 8 sets of 32 byte writes.

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

//  MEMVisitAllocatedForExpHeap(this->mHeapHandle, &free_all_visitor, 0);
}
Heap::eHeapKind ExpHeap::getHeapKind() const {
  return Heap::HEAP_KIND_EXPANDED;
}

} // namespace EGG
