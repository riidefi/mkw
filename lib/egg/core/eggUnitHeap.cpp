/*!
 * @file
 * @brief EGG wraper for unit heaps (each element uniform size).
 */

#include <nw4r/ut/utInlines.hpp>

#define HEAP_PRIVATE public

#include <egg/core/eggAllocator.hpp>
#include <egg/core/eggUnitHeap.hpp>

inline void* operator new(unsigned long, void* p) { return p; }

namespace EGG {

enum {
  UNIT_HEAP_BASE_SIZE = (sizeof(UnitHeap) - sizeof(MEMiUntHeapHead)),
  UNIT_HEAP_ALIGN = 4
};

UnitHeap::~UnitHeap() {
  dispose();
  MEMDestroyUnitHeap(mHeapHandle);
}
UnitHeap* UnitHeap::create(void* block, u32 size, u32 unit_size, s32 align,
                           u16 flag) {
  u32 end_addr = nw4r::ut::RoundDown<u32>((u32)block + size, UNIT_HEAP_ALIGN);
  u32 start_addr = nw4r::ut::RoundUp<u32>((u32)block, UNIT_HEAP_ALIGN);

  UnitHeap* ret = nullptr;

  // Note: really need the full size
  if (start_addr > end_addr ||
      end_addr - start_addr < UNIT_HEAP_BASE_SIZE + UNIT_HEAP_ALIGN) {
    ret = nullptr;
  } else {
    MEMHeapHandle hnd = MEMCreateUnitHeapEx(
        reinterpret_cast<void*>(start_addr + UNIT_HEAP_BASE_SIZE),
        end_addr - start_addr - UNIT_HEAP_BASE_SIZE, unit_size, align, flag);

    if (hnd) {
      Heap* contain =
          Heap::findContainHeap(reinterpret_cast<void*>(start_addr));

      UnitHeap* new_heap =
          new (reinterpret_cast<void*>(start_addr)) UnitHeap(hnd);
      ret = new_heap;
      new_heap->mParentHeap = contain;
    }
  }

  return ret;
}
UnitHeap* UnitHeap::create(u32 size, u32 unit_size, EGG::Heap* heap, s32 align,
                           u16 flag) {
  UnitHeap* ret = nullptr;
  void* block;

  if (!heap)
    heap = Heap::sCurrentHeap;
  if (size == -1)
    size = heap->getAllocatableSize(4);

  block = heap->alloc(size, UNIT_HEAP_ALIGN);
  if (block) {
    if ((ret = create(block, size, unit_size, align, flag)) !=
        nullptr) // INLINE
      ret->mParentHeap = heap;
    else
      heap->free(block);
  }

  return ret;
}
void UnitHeap::destroy() {
  Heap* parentHeap = findParentHeap();
  this->~UnitHeap();
  if (parentHeap)
    parentHeap->free(this);
}

void* UnitHeap::alloc(u32 size, s32 /* align */) {
  // TODO use proper accessors
  if (size > *((u32*)((u8*)mHeapHandle + 0x40)))
    return nullptr;
  return MEMAllocFromUnitHeap(mHeapHandle);
}
void UnitHeap::free(void* block) { MEMFreeToUnitHeap(mHeapHandle, block); }

u32 UnitHeap::resizeForMBlock(void*, u32) { return 0; }

u32 UnitHeap::getAllocatableSize(s32 /* align */) { return 0; }

u32 UnitHeap::adjust() { return 0; }

void UnitHeap::initAllocator(Allocator* allocator, s32 /* align */) {
  return MEMInitAllocatorForUnitHeap(allocator->getHandle(), mHeapHandle);
}

u32 UnitHeap::calcHeapSize(u32 unit_size, u32 unit_count, s32 align) {
  return MEMCalcHeapSizeForUnitHeap(unit_size, unit_count, align) +
         UNIT_HEAP_BASE_SIZE;
}

Heap::eHeapKind UnitHeap::getHeapKind() const { return HEAP_KIND_UNIT; }

} // namespace EGG
