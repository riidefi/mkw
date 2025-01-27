#include "osAlloc.h"

volatile int __OSCurrentHeap = -1;

static OSAllocHeap* OS_AllocHeapArray;
static int OS_AllocNumHeaps;
static void* OS_AllocArenaStart;
static void* OS_AllocArenaStop;

// Symbol: DLInsert
// PAL: 0x801a0d9c..0x801a0e48
OSAllocCell* DLInsert(OSAllocCell* list, OSAllocCell* cell) {
  OSAllocCell* pred;
  OSAllocCell* succ;
  for (succ = list, pred = NULL; succ; pred = succ, succ = succ->succ)
    if (cell <= succ)
      break;
  cell->succ = succ;
  cell->pred = pred;
  if (succ) {
    succ->pred = cell;
    if ((char*)cell + cell->size == (char*)succ) {
      cell->size += succ->size;
      cell->succ = succ = succ->succ;
      if (succ)
        succ->pred = cell;
    }
  }
  if (pred) {
    pred->succ = cell;
    if ((char*)pred + pred->size == (char*)cell) {
      pred->size += cell->size;
      pred->succ = succ;
      if (succ)
        succ->pred = pred;
    }
    return list;
  } else {
    return cell;
  }
}

static inline OSAllocCell* DLExtract(OSAllocCell* list, OSAllocCell* cell) {
  if (cell->succ)
    cell->succ->pred = cell->pred;
  if (!cell->pred) {
    return cell->succ;
  } else {
    cell->pred->succ = cell->succ;
    return list;
  }
}

static inline OSAllocCell* DLAddFront(OSAllocCell* list, OSAllocCell* cell) {
  cell->succ = list;
  cell->pred = NULL;
  if (list)
    list->pred = cell;
  return cell;
}

// Symbol: OSAllocFromHeap
// PAL: 0x801a0e48..0x801a0f40
void* OSAllocFromHeap(int heapIdx, u32 size) {
  OSAllocHeap* heap = &OS_AllocHeapArray[heapIdx];
  size += 0x20;
  size = (size + 0x1f) & 0xffffffe0;
  OSAllocCell* cell;
  for (cell = heap->free; cell != NULL; cell = cell->succ)
    if ((s32)size <= cell->size)
      break;
  if (!cell)
    return NULL;
  int rightBytes = cell->size - (int)size;
  if ((u32)rightBytes < 64) {
    heap->free = DLExtract(heap->free, cell);
  } else {
    cell->size = (int)size;
    OSAllocCell* rightCell = (OSAllocCell*)((char*)cell + size);
    rightCell->size = rightBytes;
    rightCell->pred = cell->pred;
    rightCell->succ = cell->succ;
    if (rightCell->succ)
      rightCell->succ->pred = rightCell;
    if (rightCell->pred) {
      rightCell->pred->succ = rightCell;
    } else {
      heap->free = rightCell;
    }
  }
  heap->allocated = DLAddFront(heap->allocated, cell);
  return (void*)((char*)cell + 32);
}

// Symbol: OSFreeToHeap
// PAL: 0x801a0f40..0x801a0fb8
void OSFreeToHeap(int heapIdx, void* data) {
  OSAllocCell* cell = (OSAllocCell*)((u32)data - 0x20);
  OSAllocHeap* heap = &OS_AllocHeapArray[heapIdx];
  heap->allocated = DLExtract(heap->allocated, cell);
  heap->free = DLInsert(heap->free, cell);
}

// Symbol: OSSetCurrentHeap
// PAL: 0x801a0fb8..0x801a0fc8
int OSSetCurrentHeap(int newHeap) {
  int oldHeap = __OSCurrentHeap;
  __OSCurrentHeap = newHeap;
  return oldHeap;
}

// Symbol: OSInitAlloc
// PAL: 0x801a0fc8..0x801a1038
void* OSInitAlloc(void* a1, void* a2, int count) {
  u32 size = sizeof(OSAllocHeap) * count;
  OS_AllocHeapArray = a1;
  OS_AllocNumHeaps = count;
  for (int i = 0; i < OS_AllocNumHeaps; i++) {
    OSAllocHeap* heap = &OS_AllocHeapArray[i];
    heap->size = -1;
    heap->free = heap->allocated = NULL;
  }
  __OSCurrentHeap = -1;
  a1 = (void*)((char*)OS_AllocHeapArray + size);
  a1 = (void*)(((u32)a1 + 31) & ~31);
  OS_AllocArenaStart = a1;
  OS_AllocArenaStop = (void*)(((u32)a2) & ~31);
  return a1;
}

// Symbol: OSCreateHeap
// PAL: 0x801a1038..0x801a10a4
int OSCreateHeap(void* start, void* stop) {
  start = (void*)(((u32)start + 0x1f) & 0xffffffe0);
  stop = (void*)((u32)stop & 0xffffffe0);
  for (int i = 0; i < OS_AllocNumHeaps; i++) {
    OSAllocHeap* heap = &OS_AllocHeapArray[i];
    if (heap->size < 0) {
      heap->size = (char*)stop - (char*)start;
      OSAllocCell* cell = (OSAllocCell*)start;
      cell->pred = NULL;
      cell->succ = NULL;
      cell->size = heap->size;
      heap->free = cell;
      heap->allocated = 0;
      return i;
    }
  }
  return -1;
}
