#pragma once

#include "memAllocator.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// MEMiExpHeapMBlockHead is the heap block header.
typedef struct MEMiExpHeapMBlockHead MEMiExpHeapMBlockHead;
struct MEMiExpHeapMBlockHead {
  u16 signature; // 0x00
  union {
    u16 val; // 0x02
    struct {
      u16 dir : 1; // 0x02
      u16 alignment : 7;
      u16 groupID : 8; // 0x03
    } fields;
  } attribute;
  u32 blockSize;               // 0x04
  MEMiExpHeapMBlockHead* prev; // 0x08
  MEMiExpHeapMBlockHead* next; // 0x0C
};

// MEMiExpMBlockList is the header of the free/used blocks double-linked list.
typedef struct MEMiExpMBlockList MEMiExpMBlockList;
struct MEMiExpMBlockList {
  MEMiExpHeapMBlockHead* head;
  MEMiExpHeapMBlockHead* tail;
};

// MEMiExpHeapHead is the extended heap header.
typedef struct MEMiExpHeapHead MEMiExpHeapHead;
struct MEMiExpHeapHead {
  MEMiExpMBlockList freeList;
  MEMiExpMBlockList usedList;
  u16 groupID;
  union {
    u16 val;
    struct {
      u16 _unk0_15 : 15;
      u16 allocMode : 1;
    } fields;
  } feature;
};

typedef struct MEM_Extent {
  void* start;
  void* end;
} MEM_Extent;

typedef void (*MEMExpHeapVisitor)(void* block, MEMHeapHandle heap,
                                  u32 user_data);

// PAL: 0x8019899c
void* MEM_ExpAllocFromHead(MEMiHeapHead*, u32, int);
// PAL: 0x80198a78
void* MEM_ExpAllocFromTail(MEMiHeapHead*, u32, int);
// PAL: 0x80198b40
u32 MEM_ExpRecycleRegion(MEMiExpHeapHead*, const MEM_Extent*);
// PAL: 0x80198ca8
MEMHeapHandle MEMCreateExpHeapEx(void* begin, u32 size, u16 flags);
// PAL: 0x80198d58
void* MEMDestroyExpHeap(MEMHeapHandle);
// PAL: 0x80198d88
void* MEMAllocFromExpHeapEx(MEMHeapHandle heap, u32 size, int align);
// PAL: 0x80198e38
u32 MEMResizeForMBlockExpHeap(MEMHeapHandle heap, void* block, u32 size);
// PAL: 0x80199038
void MEMFreeToExpHeap(MEMHeapHandle heap, void* block);
// PAL: 0x80199104
u32 MEMGetTotalFreeSizeForExpHeap(MEMHeapHandle heap);
// PAL: 0x80199180
u32 MEMGetAllocatableSizeForExpHeapEx(MEMHeapHandle heap, s32 align);
// PAL: 0x80199258
u16 MEMSetGroupIDForExpHeap(MEMHeapHandle heap, u16 group_id);
// PAL: 0x801992a8
void MEMVisitAllocatedForExpHeap(MEMHeapHandle heap, MEMExpHeapVisitor visitor,
                                 u32 user_data);
// PAL: 0x80199344
u32 MEMGetSizeForMBlockExpHeap(const void*);
// PAL: 0x8019934c
u16 MEMGetGroupIDForMBlockExpHeap(const void*);
// PAL: 0x80199358
u32 MEMAdjustExpHeap(MEMHeapHandle heap);

void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, MEMHeapHandle heap,
                                int align);

#ifdef __cplusplus
}
#endif // __cplusplus
