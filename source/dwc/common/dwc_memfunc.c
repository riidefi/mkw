#include "dwc_memfunc.h"
#include "dwci_memfunc.h"

#include <Common/rk_types.h>
#include <DWC/dwci_debug.h>

#ifdef __cplusplus
extern "C" {
#endif

static DWCAllocEx s_alloc;
static DWCFreeEx s_free;

DWCi_AllocateHeader* DWCi_GetAllocateHeader(void* block) {
  DWCiAssert(*(u32*)((u32)block - 32) == DWCi_MEMFUNC_SIGNATURE,
             "dwc_memfunc.c", 56,
             "Failed assertion header->signature == DWCi_MEMFUNC_SIGNATURE");

  return (DWCi_AllocateHeader*)((u32)block - sizeof(DWCi_AllocateHeader));
}

void* DWCi_SetAllocateHeader(DWCi_AllocateHeader* blockHeader, u32 size) {
  blockHeader->magic = DWCi_MEMFUNC_SIGNATURE;
  blockHeader->size = size;
  return (void*)&blockHeader[1];
}

u32 DWCi_GetAllocateSize(void* block) {
  DWCi_AllocateHeader* pHeader = DWCi_GetAllocateHeade(block);

  DWCiAssert(pHeader, "dwc_memfunc.c", 75, "Failed assertion header != NULL");

  return pHeader->size;
}
void DWCi_SetMemFunc(DWCAllocEx allocator, DWCFreeEx freer) {
  s_alloc = allocator;
  s_free = freer;
}
void* DWC_Alloc(DWCAllocType type, u32 size) { DWC_AllocEx(type, size, 32); }
// TODO: Figure out what is in release and what isn't
void* DWC_AllocEx(DWCAllocType type, u32 size, int align) {
  void* block;

  DWCiAssert(DWCi_Np_GetInitFlag(), "dwc_memfunc.c", 158,
             "DWC hasn't initialized yet.");

  DWCiAssert(s_alloc, "dwc_memfunc.c", 160,
             "DWC_MEMFUNC: Allocator function isn't defined.\n");
  DWCiAssert(align <= 32 && align >= -32, "dwc_memfunc.c", 161,
             "DWC_Alloc() dosen't support to align over 32 bytes order");

  block = s_alloc(type, size + sizeof(DWCi_AllocateHeader), align);

#ifdef DEBUG
  DWCi_MemWatch_add(block, size + sizeof(DWCi_AllocateHeader), type);
#endif

  return block ? DWCi_SetAllocateHeader(block, size) : NULL;
}

void DWC_Free(DWCAllocType name, void* block, u32 size) {
  DWCiAssert(DWCi_Np_GetInitFlag(), "dwc_memfunc.c", 191,
             "DWC hasn't initialized yet.");

  DWCiAssert(s_free, "dwc_memfunc.c", 193,
             "DWC_MEMFUNC: Free function isn't defined.\n");

  if (block) {
    block = (void*)DWCi_GetAllocateHeader(block);

#ifdef DEBUG
    DWCi_MemWatch_del(block);
#endif

    s_free(name, block, size);
  }
}
void* DWC_Realloc(DWCAllocType type, void* block, u32 before, u32 after) {
  DWC_ReallocEx(type, block, before, after, 32);
}
void* DWC_ReallocEx(DWCAllocType type, void* block, u32 before, u32 after,
                    int align) {
  u32 allocSize;
  void* newBlock = DWC_AllocEx(type, after, align);

  if (newBlock == NULL)
    return 0;

  if (block) {
    // TODO: Double check this
    allocSize = DWCi_GetAllocateSize(block);

    DWCi_Np_CpuCopy8(block, newBlock, allocSize > after ? after : allocSize);
    DWC_Free(type, block, allocSize);
  }
  return newBlock;
}

void* DWCi_GsMalloc(u32 size) { return DWC_Alloc(DWC_ALLOCTYPE_GS, size); }
void* DWCi_GsRealloc(void* block, u32 size) {
  DWC_Realloc(DWC_ALLOCTYPE_GS, block, size, size);
}
void* DWCi_GsFree(void* block) { DWC_Free(DWC_ALLOCTYPE_GS, block, 0); }
void DWCi_GsMemalign(int align, u32 size) {
  DWC_AllocEx(DWC_ALLOCTYPE_GS, size, align);
}
// later in object.. (header??)
void DWCi_Np_CpuCopy8(void* src, void* dst, u32 size) {
  DWCi_Np_CPUCopyFast(dst, src, size);
}

#ifdef __cplusplus
}
#endif
