#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  DWC_ALLOCTYPE_AUTH,
  DWC_ALLOCTYPE_AC,
  DWC_ALLOCTYPE_BM,
  DWC_ALLOCTYPE_UTIL,
  DWC_ALLOCTYPE_BASE,
  DWC_ALLOCTYPE_LANMATCH,
  DWC_ALLOCTYPE_GHTTP,
  DWC_ALLOCTYPE_RANKING,
  DWC_ALLOCTYPE_ENC,
  DWC_ALLOCTYPE_GS,
  DWC_ALLOCTYPE_ND,
  DWC_ALLOCTYPE_OPTION_CF,
  DWC_ALLOCTYPE_NHTTP,
  DWC_ALLOCTYPE_MAIL,
  DWC_ALLOCTYPE_NUM
} DWCAllocType;

typedef void* (*DWCAllocEx)(DWCAllocType name, u32 size, int align);
typedef void (*DWCFreeEx)(DWCAllocType name, void* ptr, u32 size);

void* DWC_Alloc(DWCAllocType name, u32 size);
void* DWC_AllocEx(DWCAllocType name, u32 size, int align);
void DWC_Free(DWCAllocType name, void* ptr, u32 size);
void* DWC_Realloc(DWCAllocType name, void* ptr, u32 oldsize, u32 newsize);
void* DWC_ReallocEx(DWCAllocType name, void* ptr, u32 oldsize, u32 newsize,
                    int align);

#ifdef __cplusplus
}
#endif
