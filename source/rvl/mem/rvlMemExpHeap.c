#include "expHeap.h"

#include <string.h>

// ceil() for 2^x aligned
#define fastceil_u32(value, align) (((value) + ((align)-1)) & ~((align)-1))
#define fastceil_ptr(ptr, align) ((void*)fastceil_u32((u32)(ptr), (align)))
// floor() for 2^x aligned
#define fastfloor_u32(value, align) ((value) & ~((align)-1))
#define fastfloor_ptr(ptr, align) ((void*)fastfloor_u32((u32)(ptr), (align)))

static inline void MEM_BlockZero(MEMiHeapHead* pHeapHd, void* address,
                                 u32 size) {
  if ((u16)pHeapHd->_unk38.parts._24_32 & 1) {
    (void)memset(address, 0, size);
  }
}

typedef struct MEM_Extent {
  void* start;
  void* end;
} MEM_Extent;

// These computations have to be inlined for an exact match.
static inline u32 cast_ptr_u32(const void* ptr) { return (u32)(ptr); }
static inline void* ptr_sub(void* ptr, u32 val) {
  return (void*)(cast_ptr_u32(ptr) - val);
}
static inline void* ptr_add(void* ptr, u32 val) {
  return (void*)(cast_ptr_u32(ptr) + val);
}

// MEM_BlockInsert inserts a block into the heap linked list.
static inline MEMiExpHeapMBlockHead*
MEM_BlockInsert(MEMiExpMBlockList* list, MEMiExpHeapMBlockHead* target,
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

// MEM_BlockRemove removes a block from the heap linked list.
static inline MEMiExpHeapMBlockHead*
MEM_BlockRemove(MEMiExpMBlockList* list, MEMiExpHeapMBlockHead* block) {
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

// ptr_diff returns the distance between two pointers.
// end address must be larger than start.
static inline u32 ptr_diff(const void* start, const void* end) {
  return cast_ptr_u32(end) - cast_ptr_u32(start);
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
  (void)MEM_BlockInsert(list, block, list->tail);
}

// MEM_BlockGetExtent retrieves the memory extent of a given block.
static inline void MEM_BlockGetExtent(MEM_Extent* region,
                                      MEMiExpHeapMBlockHead* block) {
  region->start = ptr_sub(block, block->attribute.fields.alignment);
  region->end = (void*)((u32)block + 0x10 + block->blockSize);
}

static void* MEM_AllocNewBlock(MEMiExpHeapHead* expHeap,
                               MEMiExpHeapMBlockHead* expBlockFree, void* block,
                               u32 size, u16 dir) {
  MEM_Extent extFreeL;
  MEM_Extent extFreeR;
  MEMiExpHeapMBlockHead* expBlockFreePrev;
  // Get the extents before and after the free block.
  MEM_BlockGetExtent(&extFreeL, expBlockFree);
  extFreeR.end = extFreeL.end;
  extFreeR.start = ptr_add(block, size);
  extFreeL.end = ptr_sub(block, 0x10);
  // Remove block from free list.
  expBlockFreePrev = MEM_BlockRemove(&expHeap->freeList, expBlockFree);
  // Shrink or deallocate left extent.
  if ((u32)extFreeL.end - (u32)extFreeL.start < 0x14) {
    extFreeL.end = extFreeL.start;
  } else {
    expBlockFreePrev = MEM_BlockInsert(
        &expHeap->freeList, MEM_BlockInit(&extFreeL, 'FR'), expBlockFreePrev);
  }
  // Shrink or deallocate right extent.
  if ((u32)extFreeR.end - (u32)extFreeR.start < 0x14) {
    extFreeR.start = extFreeR.end;
  } else {
    MEM_BlockInsert(&expHeap->freeList, MEM_BlockInit(&extFreeR, 'FR'),
                    expBlockFreePrev);
  }
  // Optionally clear block.
  MEM_BlockZero((MEMiHeapHead*)((u32)expHeap - sizeof(MEMiHeapHead)),
                extFreeL.end, ptr_diff(extFreeL.end, extFreeR.start));
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

void* MEM_AllocFromHead(MEMiHeapHead* heap, u32 size, int alignment) {
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
  return MEM_AllocNewBlock(expHeap, resExpBlock, resMemBlock, size, 0);
}

void* MEM_AllocFromTail(MEMiHeapHead* heap, u32 size, int alignment) {
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
  return MEM_AllocNewBlock(expHeap, resExpBlock, resMemBlock, size, 1);
}
