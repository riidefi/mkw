#pragma once

#include "memAllocator.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ceil() for 2^x aligned
#define fastceil_u32(value, align) (((value) + ((align)-1)) & ~((align)-1))
#define fastceil_ptr(ptr, align) ((void*)fastceil_u32((u32)(ptr), (align)))
// floor() for 2^x aligned
#define fastfloor_u32(value, align) ((value) & ~((align)-1))
#define fastfloor_ptr(ptr, align) ((void*)fastfloor_u32((u32)(ptr), (align)))

static inline void MEM_BlockZero(MEMiHeapHead* heap, void* address, u32 size) {
  if ((u16)heap->_unk38.parts.flags & 1) {
    (void)memset(address, 0, size);
  }
}

// These computations have to be inlined for an exact match.
static inline u32 cast_ptr_u32(const void* ptr) { return (u32)(ptr); }
static inline void* ptr_sub(void* ptr, u32 val) {
  return (void*)(cast_ptr_u32(ptr) - val);
}
static inline void* ptr_add(void* ptr, u32 val) {
  return (void*)(cast_ptr_u32(ptr) + val);
}

// ptr_dist returns the distance between two pointers.
// end address must be larger than start.
static inline u32 ptr_dist(const void* start, const void* end) {
  return cast_ptr_u32(end) - cast_ptr_u32(start);
}

// ptr_diff returns the difference between two pointers.
static inline int ptr_diff(const void* p1, const void* p2) {
  const u8* b1 = (const u8*)p1;
  const u8* b2 = (const u8*)p2;
  return b1 - b2;
}

#ifdef __cplusplus
}
#endif // __cplusplus
