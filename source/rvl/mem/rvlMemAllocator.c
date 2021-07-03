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
