#pragma once

#include <rvl/mem/memAllocator.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct MEMiUntHeapMBlockHead {
  MEMiUntHeapMBlockHead* succ;
};

struct MEMiUntHeapHead {
  MEMiUntHeapMBlockHead* free_list;
  u32 unit_size;
};

MEMHeapHandle MEMCreateUnitHeapEx(void* begin, u32 size, u32 unit_size,
                                  int align, u16 flags);

void* MEMDestroyUnitHeap(MEMHeapHandle heap);

void* MEMAllocFromUnitHeap(MEMHeapHandle heap);

void MEMFreeToUnitHeap(MEMHeapHandle heap, void* block);

u32 MEMCountFreeBlockForUnitHeap(MEMHeapHandle heap);

u32 MEMCalcHeapSizeForUnitHeap(u32 unit_size, u32 unit_count, int align);

void MEMInitAllocatorForUnitHeap(MEMAllocator* allocator, MEMHeapHandle heap);

#ifdef __cplusplus
}
#endif // __cplusplus