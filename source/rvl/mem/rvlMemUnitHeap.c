#include "unitHeap.h"

#include "heap.h"
#include "heapi.h"

MEMHeapHandle MEMCreateUnitHeapEx(void* start, u32 heapSize, u32 memBlockSize,
                                  int align, u16 flags) {
  MEMiHeapHead* heap = (MEMiHeapHead*)fastceil_ptr(start, 4);
  void* heapEnd = fastfloor_ptr(ptr_add(start, heapSize), 4);

  if (ptr_diff(heap, heapEnd) > 0)
    return NULL;

  memBlockSize = fastceil_u32(memBlockSize, align);

  MEMiUntHeapHead* unitHeap =
      (MEMiUntHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  void* heapStart =
      fastceil_ptr(ptr_add(unitHeap, sizeof(MEMiUntHeapHead)), align);

  if (ptr_diff(heapStart, heapEnd) > 0)
    return NULL;

  u32 count = ptr_dist(heapStart, heapEnd) / memBlockSize;
  if (count == 0)
    return NULL;

  heapEnd = ptr_add(heapStart, count * memBlockSize);

  MEMiInitHeapHead(heap, 'UNTH', heapStart, heapEnd, flags);

  unitHeap->free_list = (MEMiUntHeapMBlockHead*)heapStart;
  unitHeap->unit_size = memBlockSize;

  MEMiUntHeapMBlockHead* block = unitHeap->free_list;
  for (int i = 0; i < count - 1; ++i, block = block->succ)
    block->succ = (MEMiUntHeapMBlockHead*)ptr_add(block, memBlockSize);
  block->succ = NULL;

  return heap;
}
