#pragma once

#include <rvl/mem/memAllocator.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

MEMHeapHandle MEMCreateExpHeapEx(void* begin, u32 size, u16 flags);

void* MEMDestroyExpHeap(MEMHeapHandle heap);

void* MEMAllocFromExpHeapEx(MEMHeapHandle heap, u32 size, int align);

void MEMFreeToExpHeap(MEMHeapHandle heap, void* block);

u32 MEMResizeForMBlockExpHeap(MEMHeapHandle heap, void* block, u32 size);

u32 MEMGetTotalFreeSizeForExpHeap(MEMHeapHandle heap);
u32 MEMGetAllocatableSizeForExpHeapEx(MEMHeapHandle heap, int align);

typedef void (*MEMExpHeapVisitor)(void* block, MEMHeapHandle heap,
                                  u32 user_data);

void MEMVisitAllocatedForExpHeap(MEMHeapHandle heap, MEMExpHeapVisitor visitor,
                                 u32 user_data);

u32 MEMGetSizeForMBlockExpHeap(const void* block);

u16 MEMSetGroupIDForExpHeap(MEMHeapHandle heap, u16 group_id);
u16 MEMGetGroupIDForMBlockExpHeap(void* block);

u32 MEMAdjustExpHeap(MEMHeapHandle heap);


void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, MEMHeapHandle heap, int align);

#ifdef __cplusplus
}
#endif // __cplusplus