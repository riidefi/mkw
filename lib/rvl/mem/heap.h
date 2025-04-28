#pragma once

#include "memAllocator.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void MEMiInitHeapHead(MEMiHeapHead*, u32, void*, void*, u16);
void MEMiFinalizeHeap(MEMiHeapHead*);
MEMHeapHandle MEMFindContainHeap(const void*);

#ifdef __cplusplus
}
#endif // __cplusplus
