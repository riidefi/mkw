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

void* MEMDestroyUnitHeap(MEMHeapHandle heap) {
  MEMiFinalizeHeap(heap);
  return (void*)heap;
}

void* MEMAllocFromUnitHeap(MEMHeapHandle heap) {
  MEMiUntHeapHead* unitHeap =
      (MEMiUntHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  // Pop the current block and set linked list head to next block.
  MEMiUntHeapMBlockHead* block = unitHeap->free_list;
  if (block)
    unitHeap->free_list = block->succ;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  if (block)
    MEM_BlockZero(heap, block, unitHeap->unit_size);
  return block;
}

void MEMFreeToUnitHeap(MEMHeapHandle heap, void* addr) {
  if (addr == NULL)
    return;

  MEMiUntHeapHead* unitHeap =
      (MEMiUntHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiUntHeapMBlockHead* block = (MEMiUntHeapMBlockHead*)addr;
  block->succ = unitHeap->free_list;
  unitHeap->free_list = block;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);
}

u32 MEMCalcHeapSizeForUnitHeap(u32 unit_size, u32 unit_count, int align) {
  return sizeof(MEMiHeapHead) + sizeof(MEMiUntHeapHead) + (align - 4) +
         unit_count * fastceil_u32(unit_size, align);
}
