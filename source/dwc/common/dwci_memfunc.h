#pragma once

#include <dwc/common/dwc_memfunc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DWCi_MEMFUNC_SIGNATURE 'DWCM'

typedef struct {
  u32 magic; // 00 DWCi_MEMFUNC_SIGNATURE
  u32 size;  // 04
  u32 _[6];  // 08
} DWCi_AllocateHeader;

DWCi_AllocateHeader* DWCi_GetAllocateHeader(void* block);

void* DWCi_SetAllocateHeader(DWCi_AllocateHeader* blockHeader, u32 size);

u32 DWCi_GetAllocateSize(void* block);

void DWCi_SetMemFunc(DWCAllocEx allocator, DWCFreeEx freer);

void* DWCi_GsMalloc(u32 size);
void* DWCi_GsRealloc(void* block, u32 size);
void* DWCi_GsFree(void* block);
void DWCi_GsMemalign(int align, u32 size);

#ifdef __cplusplus
}
#endif
