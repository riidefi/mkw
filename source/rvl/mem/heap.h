#pragma once

#include "memAllocator.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// PAL: 0x8019832c
void MEMiInitHeapHead(MEMiHeapHead*, u32, void*, void*, u16);

#ifdef __cplusplus
}
#endif // __cplusplus
