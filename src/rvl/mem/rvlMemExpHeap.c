#include "expHeap.h"

#include "heap.h"
#include "heapi.h"

#include <stdbool.h>
#include <stdlib.h>

// MEM_ExpBlockInsert inserts a block into the heap linked list.
static inline MEMiExpHeapMBlockHead*
MEM_ExpBlockInsert(MEMiExpMBlockList* list, MEMiExpHeapMBlockHead* target,
                   MEMiExpHeapMBlockHead* prev) {
  MEMiExpHeapMBlockHead* next;
  target->prev = prev;
  if (prev) {
    next = prev->next;
    prev->next = target;
  } else {
    next = list->head;
    list->head = target;
  }
  target->next = next;
  if (next)
    next->prev = target;
  else
    list->tail = target;
  return target;
}

// MEM_ExpBlockRemove removes a block from the heap linked list.
static inline MEMiExpHeapMBlockHead*
MEM_ExpBlockRemove(MEMiExpMBlockList* list, MEMiExpHeapMBlockHead* block) {
  MEMiExpHeapMBlockHead* prev = block->prev;
  MEMiExpHeapMBlockHead* next = block->next;
  if (prev)
    prev->next = next;
  else
    list->head = next;
  if (next)
    next->prev = prev;
  else
    list->tail = prev;
  return prev;
}

// MEM_BlockInit prepares a block for use.
static inline MEMiExpHeapMBlockHead* MEM_BlockInit(MEM_Extent* region,
                                                   u16 signature) {
  MEMiExpHeapMBlockHead* block = (MEMiExpHeapMBlockHead*)region->start;
  block->signature = signature;
  block->attribute.val = 0;
  u32 start = (u32)block + 0x10;
  block->blockSize = (u32)region->end - start;
  block->prev = NULL;
  block->next = NULL;
  return block;
}

// MEM_BlockAppend inserts a block at the end of a heap list.
static inline void MEM_BlockAppend(MEMiExpMBlockList* list,
                                   MEMiExpHeapMBlockHead* block) {
  (void)MEM_ExpBlockInsert(list, block, list->tail);
}

// MEM_ExpBlockGetExtent retrieves the memory extent of a given block.
static inline void MEM_ExpBlockGetExtent(MEM_Extent* region,
                                         MEMiExpHeapMBlockHead* block) {
  region->start = ptr_sub(block, block->attribute.fields.alignment);
  region->end = (void*)((u32)block + 0x10 + block->blockSize);
}

static void* MEM_ExpAllocNewBlock(MEMiExpHeapHead* expHeap,
                                  MEMiExpHeapMBlockHead* expBlockFree,
                                  void* block, u32 size, u16 dir) {
  MEM_Extent extFreeL;
  MEM_Extent extFreeR;
  MEMiExpHeapMBlockHead* expBlockFreePrev;
  // Get the extents before and after the free block.
  MEM_ExpBlockGetExtent(&extFreeL, expBlockFree);
  extFreeR.end = extFreeL.end;
  extFreeR.start = ptr_add(block, size);
  extFreeL.end = ptr_sub(block, 0x10);
  // Remove block from free list.
  expBlockFreePrev = MEM_ExpBlockRemove(&expHeap->freeList, expBlockFree);
  // Shrink or deallocate left extent.
  if ((u32)extFreeL.end - (u32)extFreeL.start < 0x14) {
    extFreeL.end = extFreeL.start;
  } else {
    expBlockFreePrev = MEM_ExpBlockInsert(
        &expHeap->freeList, MEM_BlockInit(&extFreeL, 'FR'), expBlockFreePrev);
  }
  // Shrink or deallocate right extent.
  if ((u32)extFreeR.end - (u32)extFreeR.start < 0x14) {
    extFreeR.start = extFreeR.end;
  } else {
    MEM_ExpBlockInsert(&expHeap->freeList, MEM_BlockInit(&extFreeR, 'FR'),
                       expBlockFreePrev);
  }
  // Optionally clear block.
  MEM_BlockZero((MEMiHeapHead*)((u32)expHeap - sizeof(MEMiHeapHead)),
                extFreeL.end, ptr_dist(extFreeL.end, extFreeR.start));
  // Mark block as used.
  MEMiExpHeapMBlockHead* expBlockUsed;
  MEM_Extent extent;
  extent.start = ptr_sub(block, 0x10);
  extent.end = extFreeR.start;
  expBlockUsed = MEM_BlockInit(&extent, 'UD');
  expBlockUsed->attribute.fields.dir = dir;
  expBlockUsed->attribute.fields.alignment =
      (u16)((u32)expBlockUsed - (u32)extFreeL.end);
  expBlockUsed->attribute.fields.groupID = (u8)expHeap->groupID;
  MEM_BlockAppend(&expHeap->usedList, expBlockUsed);
  return block;
}

void* MEM_ExpAllocFromHead(MEMiHeapHead* heap, u32 size, int alignment) {
  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)((u32)heap + sizeof(MEMiHeapHead));
  const u32 special = expHeap->feature.fields.allocMode == 0;
  // Search heap for the next free block.
  MEMiExpHeapMBlockHead* curExpBlock = NULL; // current block we're looking at
  MEMiExpHeapMBlockHead* resExpBlock = NULL; // matching / result block
  u32 resSize = 0xffffffff;
  void* resMemBlock = NULL;
  // Begin search.
  for (curExpBlock = expHeap->freeList.head; curExpBlock;
       curExpBlock = curExpBlock->next) {
    void* block = (void*)((u32)curExpBlock + 0x10);
    void* alignedBlock = fastceil_ptr(block, alignment);
    u32 offset = (u32)alignedBlock - (u32)block;
    if (curExpBlock->blockSize >= size + offset &&
        resSize > curExpBlock->blockSize) {
      resExpBlock = curExpBlock;
      resSize = curExpBlock->blockSize;
      resMemBlock = alignedBlock;
      if (special || resSize == size)
        break;
    }
  }
  // Out of memory if no block found.
  if (!resExpBlock)
    return NULL;
  // Mark block as used.
  return MEM_ExpAllocNewBlock(expHeap, resExpBlock, resMemBlock, size, 0);
}

void* MEM_ExpAllocFromTail(MEMiHeapHead* heap, u32 size, int alignment) {
  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)((u32)heap + sizeof(MEMiHeapHead));
  const u32 special = expHeap->feature.fields.allocMode == 0;
  // Search heap backwards for the next free block.
  MEMiExpHeapMBlockHead* curExpBlock = NULL; // current block we're looking at
  MEMiExpHeapMBlockHead* resExpBlock = NULL; // matching / result block
  u32 resSize = 0xffffffff;
  void* resMemBlock = NULL;
  // Begin search.
  for (curExpBlock = expHeap->freeList.tail; curExpBlock;
       curExpBlock = curExpBlock->prev) {
    void* block = (void*)((u32)curExpBlock + 0x10);
    void* blockEnd = ptr_add(block, curExpBlock->blockSize);
    void* alignedBlock = fastfloor_ptr(ptr_sub(blockEnd, size), alignment);
    if ((int)alignedBlock - (int)block >= 0 &&
        resSize > curExpBlock->blockSize) {
      resExpBlock = curExpBlock;
      resSize = curExpBlock->blockSize;
      resMemBlock = alignedBlock;
      if (special || resSize == size)
        break;
    }
  }
  // Out of memory if no block found.
  if (!resExpBlock)
    return NULL;
  // Mark block as used.
  return MEM_ExpAllocNewBlock(expHeap, resExpBlock, resMemBlock, size, 1);
}

u32 MEM_ExpRecycleRegion(MEMiExpHeapHead* expHeap, const MEM_Extent* ext) {
  MEMiExpHeapMBlockHead* blockFree = NULL;
  MEM_Extent extFree = *ext;
  MEMiExpHeapMBlockHead* block;
  for (block = expHeap->freeList.head; block; block = block->next) {
    if (block < ext->start) {
      blockFree = block;
      continue;
    }
    if (block == ext->end) {
      extFree.end = (void*)((u32)block + 0x10 + block->blockSize);
      MEM_ExpBlockRemove(&expHeap->freeList, block);
    }
    break;
  }
  if (blockFree && (void*)((u32)blockFree + sizeof(MEMiExpHeapMBlockHead) +
                           blockFree->blockSize) == ext->start) {
    extFree.start = blockFree;
    blockFree = MEM_ExpBlockRemove(&expHeap->freeList, blockFree);
  }
  if (ptr_dist(extFree.start, extFree.end) < sizeof(MEMiExpHeapMBlockHead))
    return false;
  MEM_ExpBlockInsert(&expHeap->freeList, MEM_BlockInit(&extFree, 'FR'),
                     blockFree);
  return true;
}

static inline MEMiHeapHead* MEM_ExpHeapInit(void* begin, void* end, u16 flags) {
  MEMiHeapHead* heap = (MEMiHeapHead*)begin;
  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  MEMiInitHeapHead(heap, 'EXPH', ptr_add(expHeap, sizeof(MEMiExpHeapHead)), end,
                   flags);
  expHeap->groupID = 0;
  expHeap->feature.val = 0;
  expHeap->feature.fields.allocMode = 0;
  {
    MEMiExpHeapMBlockHead* block;
    MEM_Extent region;
    region.start = heap->arena_start;
    region.end = heap->arena_end;
    block = MEM_BlockInit(&region, 'FR');
    expHeap->freeList.head = block;
    expHeap->freeList.tail = block;
    expHeap->usedList.head = NULL;
    expHeap->usedList.tail = NULL;
    return heap;
  }
}

MEMHeapHandle MEMCreateExpHeapEx(void* addr, u32 size, u16 flags) {
  void* end = fastfloor_ptr(ptr_add(addr, size), 4);
  addr = fastceil_ptr(addr, 4);
  if ((u32)addr > (u32)end || ptr_dist(addr, end) < 0x64) {
    return NULL;
  }
  return MEM_ExpHeapInit(addr, end, flags);
}

void* MEMDestroyExpHeap(MEMHeapHandle heap) {
  MEMiFinalizeHeap(heap);
  return (void*)heap;
}

void* MEMAllocFromExpHeapEx(MEMHeapHandle heap, u32 size, int dir) {
  void* memory = NULL;
  if (size == 0)
    size = 1;
  size = fastceil_u32(size, 4);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  if (dir >= 0)
    memory = MEM_ExpAllocFromHead(heap, size, dir);
  else
    memory = MEM_ExpAllocFromTail(heap, size, -dir);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return memory;
}

#ifdef __cplusplus
extern "C" {
#endif

// Referenced by assembly.
void _restgpr_26();
void _savegpr_26();
#ifdef __cplusplus
}
#endif

asm u32 MEMResizeForMBlockExpHeap(MEMHeapHandle heap, void* addr, u32 size) {
  nofralloc;
  stwu r1, -48(r1);
  mflr r0;
  stw r0, 52(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  addi r5, r5, 0x3;
  lwz r0, -12(r4);
  rlwinm r29, r5, 0x0, 0x0, 0x1d;
  addi r30, r4, -0x10;
  cmplw r29, r0;
  mr r27, r3;
  mr r28, r4;
  addi r31, r3, 0x3c;
  bne loc1;
loc0:
  mr r3, r29;
  b loc35;
loc1:
  lwz r0, 56(r3);
  rlwinm.r0, r0, 0x0, 0x1d, 0x1d;
  beq loc3;
loc2:
  addi r3, r3, 0x20;
  bl OSLockMutex;
loc3:
  lwz r26, 4(r30);
  cmplw r29, r26;
  ble loc30;
loc4:
  add r3, r30, r26;
  lwz r7, 0(r31);
  addi r0, r3, 0x10;
  b loc7;
loc5:
  cmplw r7, r0;
  beq loc8;
loc6:
  lwz r7, 12(r7);
loc7:
  cmpwi r7, 0x0;
  bne loc5;
loc8:
  cmpwi r7, 0x0;
  beq loc10;
loc9:
  lwz r4, 4(r7);
  add r3, r26, r4;
  addi r0, r3, 0x10;
  cmplw r29, r0;
  ble loc13;
loc10:
  lwz r0, 56(r27);
  rlwinm.r0, r0, 0x0, 0x1d, 0x1d;
  beq loc12;
loc11:
  addi r3, r27, 0x20;
  bl OSUnlockMutex;
loc12:
  li r3, 0x0;
  b loc35;
loc13:
  lwz r5, 8(r7);
  add r3, r7, r4;
  lhz r0, 2(r7);
  addi r6, r3, 0x10;
  cmpwi r5, 0x0;
  lwz r4, 12(r7);
  rlwinm r0, r0, 0x18, 0x19, 0x1f;
  subf r3, r0, r7;
  beq loc15;
loc14:
  stw r4, 12(r5);
  b loc16;
loc15:
  stw r4, 0(r31);
loc16:
  cmpwi r4, 0x0;
  beq loc18;
loc17:
  stw r5, 8(r4);
  b loc19;
loc18:
  stw r5, 4(r31);
loc19:
  add r7, r29, r28;
  subf r0, r7, r6;
  cmplwi r0, 0x10;
  bge loc21;
loc20:
  mr r7, r6;
loc21:
  subf r0, r7, r6;
  subf r4, r28, r7;
  cmplwi r0, 0x10;
  stw r4, 4(r30);
  blt loc28;
loc22:
  li r4, 0x4652;
  addi r0, r7, 0x10;
  sth r4, 0(r7);
  li r4, 0x0;
  subf r0, r0, r6;
  cmpwi r5, 0x0;
  sth r4, 2(r7);
  stw r0, 4(r7);
  stw r4, 12(r7);
  stw r5, 8(r7);
  beq loc24;
loc23:
  lwz r4, 12(r5);
  stw r7, 12(r5);
  b loc25;
loc24:
  lwz r4, 0(r31);
  stw r7, 0(r31);
loc25:
  cmpwi r4, 0x0;
  stw r4, 12(r7);
  beq loc27;
loc26:
  stw r7, 8(r4);
  b loc28;
loc27:
  stw r7, 4(r31);
loc28:
  lwz r0, 56(r27);
  subf r5, r3, r7;
  clrlwi.r0, r0, 0x1f;
  beq loc32;
loc29:
  li r4, 0x0;
  bl memset;
  b loc32;
loc30:
  add r0, r29, r28;
  mr r3, r31;
  stw r0, 8(r1);
  addi r4, r1, 0x8;
  lwz r0, 4(r30);
  add r5, r30, r0;
  addi r0, r5, 0x10;
  stw r0, 12(r1);
  stw r29, 4(r30);
  bl MEM_ExpRecycleRegion;
  cmpwi r3, 0x0;
  bne loc32;
loc31:
  stw r26, 4(r30);
loc32:
  lwz r0, 56(r27);
  rlwinm.r0, r0, 0x0, 0x1d, 0x1d;
  beq loc34;
loc33:
  addi r3, r27, 0x20;
  bl OSUnlockMutex;
loc34:
  lwz r3, 4(r30);
loc35:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 52(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
}

void MEMFreeToExpHeap(MEMHeapHandle heap, void* addr) {
  if (addr == NULL)
    return;

  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  MEMiExpHeapMBlockHead* block =
      (MEMiExpHeapMBlockHead*)ptr_sub(addr, sizeof(MEMiExpHeapMBlockHead));

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEM_Extent region;
  MEM_ExpBlockGetExtent(&region, block);
  (void)MEM_ExpBlockRemove(&expHeap->usedList, block);
  (void)MEM_ExpRecycleRegion(expHeap, &region);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);
}

// MEMGetTotalFreeSizeForExpHeap returns the total amount of free space on the
// heap.
u32 MEMGetTotalFreeSizeForExpHeap(MEMHeapHandle heap) {
  u32 ret = 0;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  // Loop over all blocks in the heap and count along the way.
  MEMiExpHeapMBlockHead* block;
  for (block = expHeap->freeList.head; block; block = block->next)
    ret += block->blockSize;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return ret;
}

u32 MEMGetAllocatableSizeForExpHeapEx(MEMHeapHandle heap, s32 alignment) {
  alignment = abs(alignment);

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  {
    MEMiExpHeapHead* expHeap =
        (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
    MEMiExpHeapMBlockHead* block;
    u32 maxSize = 0;
    u32 offsetMin = 0xFFFFFFFF;

    for (block = expHeap->freeList.head; block; block = block->next) {
      void* blockAddress1 = ptr_add(block, sizeof(MEMiExpHeapMBlockHead));
      void* baseAddress = fastceil_ptr(blockAddress1, alignment);
      void* endAddress1 = ptr_add(blockAddress1, block->blockSize);
      if ((u32)(baseAddress) < (u32)(endAddress1)) {
        void* blockAddress2 = ptr_add(block, sizeof(MEMiExpHeapMBlockHead));
        void* endAddress2 = ptr_add(blockAddress2, block->blockSize);
        const u32 blockSize = ptr_dist(baseAddress, endAddress2);
        const u32 offset = ptr_dist(blockAddress2, baseAddress);
        if (maxSize < blockSize ||
            (maxSize == blockSize && offsetMin > offset)) {
          maxSize = blockSize;
          offsetMin = offset;
        }
      }
    }

    if (((u16)heap->_unk38.parts.flags) & 0x04)
      OSUnlockMutex(&heap->mutex);

    return maxSize;
  }
}

u16 MEMSetGroupIDForExpHeap(MEMHeapHandle heap, u16 groupID) {
  u32 interrupts = OSDisableInterrupts();
  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  u16 old = expHeap->groupID;
  expHeap->groupID = groupID;
  OSRestoreInterrupts(interrupts);
  return old;
}

void MEMVisitAllocatedForExpHeap(MEMHeapHandle heap, MEMExpHeapVisitor visitor,
                                 u32 userParam) {
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  MEMiExpHeapMBlockHead* block = expHeap->usedList.head;
  while (block) {
    MEMiExpHeapMBlockHead* next = block->next;
    void* blockAddr = ptr_add(block, sizeof(MEMiExpHeapMBlockHead));
    (*visitor)(blockAddr, heap, userParam);
    block = next;
  }

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);
}

u32 MEMGetSizeForMBlockExpHeap(const void* addr) {
  const MEMiExpHeapMBlockHead* block =
      (const MEMiExpHeapMBlockHead*)((u32)addr - sizeof(MEMiExpHeapMBlockHead));
  return block->blockSize;
}

u16 MEMGetGroupIDForMBlockExpHeap(const void* data) {
  MEMiExpHeapMBlockHead* block =
      (MEMiExpHeapMBlockHead*)((u32)data - sizeof(MEMiExpHeapMBlockHead));
  return block->attribute.fields.groupID;
}

u32 MEMAdjustExpHeap(MEMHeapHandle heapHandle) {
  MEMiHeapHead* heap = heapHandle;
  MEMiExpHeapHead* expHeap =
      (MEMiExpHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
  u32 ret;

  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSLockMutex(&heap->mutex);

  MEMiExpHeapMBlockHead* block = expHeap->freeList.tail;
  if (block == NULL) {
    ret = 0;
    goto ret_;
  }

  void* const start = ptr_add(block, sizeof(MEMiExpHeapMBlockHead));
  void* const end = ptr_add(start, block->blockSize);
  u32 blockSize;

  if (end != heap->arena_end) {
    ret = 0;
    goto ret_;
  }

  MEM_ExpBlockRemove(&expHeap->freeList, block);
  blockSize = block->blockSize + sizeof(MEMiExpHeapMBlockHead);
  heap->arena_end = ptr_sub(heap->arena_end, blockSize);
  ret = ptr_dist(heap, heap->arena_end);

ret_:
  if (((u16)heap->_unk38.parts.flags) & 0x04)
    OSUnlockMutex(&heap->mutex);

  return ret;
}
