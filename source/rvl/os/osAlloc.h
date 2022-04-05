#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSAllocCell OSAllocCell;
struct OSAllocCell {
  OSAllocCell* pred;
  OSAllocCell* succ;
  s32 size;
};
typedef struct OSAllocHeap {
  s32 size;
  OSAllocCell* free;
  OSAllocCell* allocated;
} OSAllocHeap;

// PAL: 0x801a0d9c..0x801a0e48
OSAllocCell* DLInsert(OSAllocCell* list, OSAllocCell* cell);
// PAL: 0x801a0e48..0x801a0f40
void* OSAllocFromHeap(int, u32);
// PAL: 0x801a0f40..0x801a0fb8
void OSFreeToHeap(int, void*);
// PAL: 0x801a0fb8..0x801a0fc8
int OSSetCurrentHeap(int);
// PAL: 0x801a0fc8..0x801a1038
void* OSInitAlloc(void*, void*, int);
// PAL: 0x801a1038..0x801a10a4
int OSCreateHeap(void*, void*);

extern volatile int __OSCurrentHeap;

#ifdef __cplusplus
}
#endif
