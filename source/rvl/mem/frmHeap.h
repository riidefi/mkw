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

// PAL: 0x80199444
MEMHeapHandle MEMCreateFrmHeapEx(void* start, u32 size, u16 flags);
// PAL: 0x801994b4
void* MEMDestroyFrmHeap(MEMHeapHandle);
// PAL: 0x801994e4
void* MEMAllocFromFrmHeapEx(MEMHeapHandle heap, u32 size, int align);
// PAL: 0x80199604
void MEMFreeToFrmHeap(MEMHeapHandle, int);

#ifdef __cplusplus
}
#endif // __cplusplus
