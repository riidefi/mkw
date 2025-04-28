#pragma once

#include "memAllocator.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct MEMiFrmHeapState MEMiFrmHeapState;
struct MEMiFrmHeapState {
  u32 tag;
  void* head;
  void* tail;
  MEMiFrmHeapState* state;
};

typedef struct MEMiFrmHeapHead MEMiFrmHeapHead;
struct MEMiFrmHeapHead {
  void* head;
  void* tail;
  MEMiFrmHeapState* state;
};

MEMHeapHandle MEMCreateFrmHeapEx(void* start, u32 size, u16 flags);
void* MEMDestroyFrmHeap(MEMHeapHandle);
void* MEMAllocFromFrmHeapEx(MEMHeapHandle heap, u32 size, int align);
void MEMFreeToFrmHeap(MEMHeapHandle, int);
u32 MEMGetAllocatableSizeForFrmHeapEx(MEMHeapHandle, int);
int MEMRecordStateForFrmHeap(MEMHeapHandle, u32);
int MEMFreeByStateToFrmHeap(MEMHeapHandle, u32);

#ifdef __cplusplus
}
#endif // __cplusplus
