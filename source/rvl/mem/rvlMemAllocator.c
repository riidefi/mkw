#include "memAllocator.h"

#include "expHeap.h"
#include "heapi.h"
#include "unitHeap.h"

void* MEM_AllocForExpHeap_(MEMAllocator* alloc, u32 size) {
  MEMHeapHandle heap = (MEMHeapHandle)alloc->heap;
  int alignment = (int)alloc->_unk08;
  return MEMAllocFromExpHeapEx(heap, size, alignment);
}

void MEM_FreeForExpHeap_(MEMAllocator* alloc, void* data) {
  MEMHeapHandle heap = (MEMHeapHandle)alloc->heap;
  MEMFreeToExpHeap(heap, data);
}

void* MEM_AllocForUnitHeap(MEMAllocator* alloc, u32 size) {
  MEMHeapHandle heap = (MEMHeapHandle)alloc->heap;
  MEMiUntHeapHead* unitHeap =
      (MEMiUntHeapHead*)(ptr_add(heap, sizeof(MEMiHeapHead)));
  u32 unit_size = unitHeap->unit_size;
  if (size > unit_size)
    return NULL;
  return MEMAllocFromUnitHeap(heap);
}

void MEM_FreeForUnitHeap(MEMAllocator* alloc, void* data) {
  MEMHeapHandle const heap = (MEMHeapHandle)alloc->heap;
  MEMFreeToUnitHeap(heap, data);
}

void* MEMAllocFromAllocator(MEMAllocator* alloc, u32 size) {
  return (*alloc->func->alloc)(alloc, size);
}

void MEMFreeToAllocator(MEMAllocator* alloc, void* data) {
  (*alloc->func->free)(alloc, data);
}

void MEMInitAllocatorForExpHeap(MEMAllocator* alloc, MEMHeapHandle heap,
                                int align) {
  // PAL: 0x80388860
  static const MEMAllocatorFunc funcs = {
      MEM_AllocForExpHeap_,
      MEM_FreeForExpHeap_,
  };
  alloc->func = &funcs;
  alloc->heap = heap;
  alloc->_unk08 = (u32)align;
  alloc->_unk0C = 0;
}

void MEMInitAllocatorForUnitHeap(MEMAllocator* alloc, MEMHeapHandle heap) {
  // PAL: 0x80388868
  static const MEMAllocatorFunc funcs = {
      MEM_AllocForUnitHeap,
      MEM_FreeForUnitHeap,
  };
  alloc->func = &funcs;
  alloc->heap = heap;
  alloc->_unk08 = 0;
  alloc->_unk0C = 0;
}
