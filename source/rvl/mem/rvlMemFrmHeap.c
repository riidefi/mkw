#include "frmHeap.h"

#include "heap.h"
#include "heapi.h"

#include <stdbool.h>
#include <stdlib.h>

static inline MEMiFrmHeapHead*
GetFrmHeapHeadPtrFromHeapHead_(MEMiHeapHead* heap) {
  return (MEMiFrmHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
}

static inline MEMiHeapHead*
GetHeapHeadPtrFromFrmHeapHead_(MEMiFrmHeapHead* frmHeap) {
  return (MEMiHeapHead*)ptr_sub(frmHeap, sizeof(MEMiHeapHead));
}

static inline MEMiHeapHead* MEM_FrameHeapInit(void* start, void* end,
                                              u16 flags) {
  MEMiHeapHead* pHeapHd = (MEMiHeapHead*)start;
  MEMiFrmHeapHead* pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead_(pHeapHd);

  MEMiInitHeapHead(pHeapHd, 'FRMH',
                   ptr_add(pFrmHeapHd, sizeof(MEMiFrmHeapHead)), end, flags);

  pFrmHeapHd->head = pHeapHd->arena_start;
  pFrmHeapHd->tail = pHeapHd->arena_end;

  pFrmHeapHd->state = NULL;

  return pHeapHd;
}

MEMHeapHandle MEMCreateFrmHeapEx(void* start, u32 size, u16 flags) {
  void* end = fastfloor_ptr(ptr_add(start, size), 4);
  start = fastceil_ptr(start, 4);

  if ((u32)(start) > (u32)(end) ||
      ptr_diff(start, end) < sizeof(MEMiHeapHead) + sizeof(MEMiFrmHeapHead)) {
    return NULL;
  }

  return MEM_FrameHeapInit(start, end, flags);
}

void* MEMDestroyFrmHeap(MEMHeapHandle heap) {
  MEMiFinalizeHeap(heap);
  return (void*)heap;
}

static inline void* MEM_FrmAllocFromHead(MEMiFrmHeapHead* frmHead, u32 size,
                                         int align) {
  void* newBlock = fastceil_ptr(frmHead->head, align);
  void* endAddress = ptr_add(newBlock, size);

  if ((u32)(endAddress) > (u32)(frmHead->tail))
    return NULL;

  MEM_BlockZero(GetHeapHeadPtrFromFrmHeapHead_(frmHead), frmHead->head,
                ptr_diff(frmHead->head, endAddress));
  frmHead->head = endAddress;
  return newBlock;
}

static void* MEM_FrmAllocFromTail(MEMiFrmHeapHead* frmHeap, u32 size,
                                  int align) {
  void* newBlock = fastfloor_ptr(ptr_sub(frmHeap->tail, size), align);

  if ((u32)(newBlock) < (u32)(frmHeap->head))
    return NULL;

  MEM_BlockZero(GetHeapHeadPtrFromFrmHeapHead_(frmHeap), newBlock,
                ptr_diff(newBlock, frmHeap->tail));
  frmHeap->tail = newBlock;
  return newBlock;
}

void* MEMAllocFromFrmHeapEx(MEMHeapHandle heap, u32 size, int alignment) {
  void* memory = NULL;
  MEMiFrmHeapHead* pFrmHeapHd;

  pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead_(heap);

  if (size == 0) {
    size = 1;
  }

  size = fastceil_u32(size, 4);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  if (alignment >= 0)
    memory = MEM_FrmAllocFromHead(pFrmHeapHd, size, alignment);
  else
    memory = MEM_FrmAllocFromTail(pFrmHeapHd, size, -alignment);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return memory;
}

static inline void MEM_FrmFreeHead(MEMiHeapHead* heap) {
  MEMiFrmHeapHead* frmHeap = GetFrmHeapHeadPtrFromHeapHead_(heap);
  frmHeap->head = heap->arena_start;
  frmHeap->state = NULL;
}

static inline void MEM_FrmFreeTail(MEMiHeapHead* heap) {
  MEMiFrmHeapHead* frmHeap = GetFrmHeapHeadPtrFromHeapHead_(heap);
  MEMiFrmHeapState* state;
  for (state = frmHeap->state; state; state = state->state)
    state->tail = heap->arena_end;
  frmHeap->tail = heap->arena_end;
}

void MEMFreeToFrmHeap(MEMHeapHandle heap, int mode) {
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);
  if (mode & 1)
    MEM_FrmFreeHead(heap);
  if (mode & 2)
    MEM_FrmFreeTail(heap);
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);
}

u32 OSDisableInterrupts(void);
u32 OSEnableInterrupts(void);
u32 OSRestoreInterrupts(u32 level);

u32 MEMGetAllocatableSizeForFrmHeapEx(MEMHeapHandle heap, int align) {
  align = abs(align);
  const MEMiFrmHeapHead* frmHeap = GetFrmHeapHeadPtrFromHeapHead_(heap);
  int interrupts = OSDisableInterrupts();
  const void* addr = fastceil_ptr(frmHeap->head, align);
  u32 retVal;
  if ((u32)addr > (u32)(frmHeap->tail))
    retVal = 0;
  else
    retVal = ptr_diff(addr, frmHeap->tail);
  OSRestoreInterrupts(interrupts);
  return retVal;
}

int MEMRecordStateForFrmHeap(MEMHeapHandle heap, u32 tag) {
  int ret;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiFrmHeapHead* frmHeap = GetFrmHeapHeadPtrFromHeapHead_(heap);
  void* oldHeadAllocator = frmHeap->head;
  MEMiFrmHeapState* state = (MEMiFrmHeapState*)MEM_FrmAllocFromHead(
      frmHeap, sizeof(MEMiFrmHeapState), 4);

  if (!state) {
    ret = false;
    goto ret_;
  }

  state->tag = tag;
  state->head = oldHeadAllocator;
  state->tail = frmHeap->tail;
  state->state = frmHeap->state;
  frmHeap->state = state;
  ret = true;

ret_:
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return ret;
}

int MEMFreeByStateToFrmHeap(MEMHeapHandle heap, u32 tag) {
  int ret;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiFrmHeapHead* frmHeap = GetFrmHeapHeadPtrFromHeapHead_(heap);
  MEMiFrmHeapState* state = frmHeap->state;

  if (tag != 0)
    for (; state; state = state->state)
      if (state->tag == tag)
        break;

  if (!state) {
    ret = false;
    goto ret_;
  }

  void* oldHeadAllocator = frmHeap->head;
  void* oldTailAllocator = frmHeap->tail;
  frmHeap->head = state->head;
  frmHeap->tail = state->tail;
  frmHeap->state = state->state;
  ret = true;

ret_:
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return ret;
}
