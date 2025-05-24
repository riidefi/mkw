/*!
 * @file
 * @brief EGG wraper for unit heaps (each element uniform size).
 */

#pragma once

#include <egg/core/eggHeap.hpp>
#include <rvl/mem/unitHeap.h>

namespace EGG {

class UnitHeap : public Heap, private MEMiUntHeapHead {
  inline UnitHeap(MEMHeapHandle heapHandle) : Heap(heapHandle) {}
  ~UnitHeap() override;
  // Always inline in mkw
  static inline UnitHeap* create(void* block, u32 size, u32 unit_size,
                                 s32 align, u16 flag);
  static UnitHeap* create(u32 size, u32 unit_size, EGG::Heap* heap, s32 align,
                          u16 flag);
  void destroy() override;
  void* alloc(u32 size, s32 align) override;
  void free(void* block) override;
  u32 resizeForMBlock(void*, u32) override;
  u32 getAllocatableSize(s32 align) override;
  u32 adjust() override;
  void initAllocator(Allocator* allocator, s32) override;
  static u32 calcHeapSize(u32 unit_size, u32 unit_count, s32 align);
  eHeapKind getHeapKind() const override;
};

} // namespace EGG
