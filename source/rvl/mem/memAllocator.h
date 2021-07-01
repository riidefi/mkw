#pragma once

#include <rk_types.h>

#include "rvl/os/osThread.h"
#include "rvlMemList.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RII_CLIENT
struct MEMAllocator {
  char _[0x10];
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
      u32 _24_32 : 8; // 0x38
    } parts;
  } _unk38;
};

typedef MEMiHeapHead* MEMHeapHandle;

MEMiHeapHead* MEMFindContainHeap(const void*);

#else
#include <revolution/mem.h>
#endif

#ifdef __cplusplus
} // extern "C"
#endif
