#pragma once

#include <rk_types.h>

#include <rvl/os/os.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osMutex.h>
#include "rvlMemList.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RII_CLIENT

typedef struct MEMAllocator MEMAllocator;

typedef void* (*MEMFuncAllocatorAlloc)(MEMAllocator*, u32);
typedef void (*MEMFuncAllocatorFree)(MEMAllocator*, void*);

typedef struct MEMAllocatorFunc MEMAllocatorFunc;
struct MEMAllocatorFunc {
  MEMFuncAllocatorAlloc alloc; // 0x00
  MEMFuncAllocatorFree free;   // 0x04
};

struct MEMAllocator {
  const MEMAllocatorFunc* func; // 0x00
  void* heap;                   // 0x04
  u32 _unk08;                   // 0x08
  u32 _unk0C;                   // 0x0C
};

typedef struct MEMiHeapHead MEMiHeapHead;

struct MEMiHeapHead {
  u32 _unk00;        // 0x00
  MEMLink link;      // 0x04
  MEMList list;      // 0x0c
  void* arena_start; // 0x18
  void* arena_end;   // 0x1C
  OSMutex mutex;     // 0x20
  // No idea what this is.
  union {
    u32 val; // 0x38
    struct {
      u32 _0_24 : 24; // 0x38
      u32 flags : 8;  // 0x38
    } parts;
  } _unk38;
};

typedef MEMiHeapHead* MEMHeapHandle;

// PAL: 0x80199b58
void* MEM_AllocForExpHeap_(MEMAllocator* alloc, u32 size);
// PAL: 0x80199b68
void MEM_FreeForExpHeap_(MEMAllocator* alloc, void* data);
// PAL: 0x80199b70
void* MEM_AllocForUnitHeap(MEMAllocator* alloc, u32 size);
// PAL: 0x80199b90
void MEM_FreeForUnitHeap(MEMAllocator* alloc, void* data);
// PAL: 0x80199b98
void* MEMAllocFromAllocator(MEMAllocator* alloc, u32 size);
// PAL: 0x80199ba8
void MEMFreeToAllocator(MEMAllocator* alloc, void* data);
// PAL: 0x80199bb8
void MEMInitAllocatorForExpHeap(MEMAllocator*, MEMHeapHandle, int);
// PAL: 0x80199bd4
void MEMInitAllocatorForUnitHeap(MEMAllocator*, MEMHeapHandle);

MEMiHeapHead* MEMFindContainHeap(const void*);

#else
//#include <revolution/mem.h>
#endif

#ifdef __cplusplus
} // extern "C"
#endif
