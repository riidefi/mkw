#include "heap.h"

#include <stdbool.h>
#include <string.h>

#include "rvl/os/osThread.h"

// PAL: 0x80346cf0 @bss
static MEMList MEM_RootList;
// PAL: 0x80386838 @sbss
static u32 MEM_RootListInitialized = false;
// PAL: 0x80346d00 @bss
static OSMutex MEM_GlobalLock;

// MEM_FindHeap searches the heap linked list for the heap that holds the given
// arena.
//
// PAL: 0x801981ec
static MEMiHeapHead* MEM_FindHeap(MEMList* list, const void* arena) {
  MEMiHeapHead* next = NULL;
  while ((next = (MEMiHeapHead*)MEMGetNextListObject(list, next)) != NULL) {
    if ((u32)(next->arena_start) <= (u32)arena &&
        (u32)arena < (u32)(next->arena_end)) {
      MEMiHeapHead* recursed = MEM_FindHeap(&next->list, arena);
      if (recursed)
        return recursed;
      return next;
    }
  }
  return NULL;
}

static inline MEMList* MEM_FindHeapList(const MEMiHeapHead* search) {
  MEMList* list = &MEM_RootList;
  MEMiHeapHead* heap = MEM_FindHeap(&MEM_RootList, search);
  if (heap) {
    list = &heap->list;
  }
  return list;
}

void MEMiInitHeapHead(MEMiHeapHead* heap, u32 arg2, void* start, void* end,
                      u16 flags) {
  heap->_unk00 = arg2;
  heap->arena_start = start;
  heap->arena_end = end;
  heap->_unk38.val = 0;
  heap->_unk38.parts.flags = (u8)flags;
  MEMInitList(&heap->list, 0x4);
  if (!MEM_RootListInitialized) {
    MEMInitList(&MEM_RootList, 0x4);
    OSInitMutex(&MEM_GlobalLock);
    MEM_RootListInitialized = true;
  }
  OSInitMutex(&heap->mutex); // TODO remove
  OSLockMutex(&MEM_GlobalLock);
  MEMAppendListObject(MEM_FindHeapList(heap), heap);
  OSUnlockMutex(&MEM_GlobalLock);
}

void MEMiFinalizeHeap(MEMiHeapHead* heap) {
  OSLockMutex(&MEM_GlobalLock);
  MEMRemoveListObject(MEM_FindHeapList(heap), heap);
  OSUnlockMutex(&MEM_GlobalLock);
  heap->_unk00 = 0;
}

MEMHeapHandle MEMFindContainHeap(const void* arena) {
  return MEM_FindHeap(&MEM_RootList, arena);
}
