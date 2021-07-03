#include "memAllocator.h"

#include "expHeap.h"

void* MEM_AllocForExpHeap_(MEMAllocator* alloc, u32 size) {
  MEMHeapHandle heap = (MEMHeapHandle)alloc->heap;
  int alignment = (int)alloc->_unk08;
  return MEMAllocFromExpHeapEx(heap, size, alignment);
}
