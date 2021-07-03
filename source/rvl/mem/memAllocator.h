#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RII_CLIENT
struct MEMAllocator {
  char _[0x10];
};
typedef struct MEMiHeapHead {
  char _[0x1c];
  u32 arena_end; // 0x20
  char _2[0x40 - 0x20];
  u32 _40;
} MEMiHeapHead;

typedef MEMiHeapHead* MEMHeapHandle;

MEMiHeapHead* MEMFindContainHeap(const void*);

#else
#include <revolution/mem.h>
#endif

#define rvlHeap MEMiHeapHead
#ifdef __cplusplus
} // extern "C"
#endif