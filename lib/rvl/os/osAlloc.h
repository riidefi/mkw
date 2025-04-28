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

OSAllocCell* DLInsert(OSAllocCell* list, OSAllocCell* cell);
void* OSAllocFromHeap(int, u32);
void OSFreeToHeap(int, void*);
int OSSetCurrentHeap(int);
void* OSInitAlloc(void*, void*, int);
int OSCreateHeap(void*, void*);

extern volatile int __OSCurrentHeap;

#ifdef __cplusplus
}
#endif
