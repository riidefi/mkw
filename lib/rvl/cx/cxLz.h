#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CXUncompContextLZ {
  u8 _[24];
} CXUncompContextLZ;

typedef enum CXResult { CXResultSuccess = 0 } CXResult;

void CXInitUncompContextLZ(CXUncompContextLZ* pCtx, void* pDst);
CXResult CXReadUncompLZ(CXUncompContextLZ* pCtx, const void* pSrc, u32 len);
u32 CXGetUncompressedSize(const void* pBinary);

#ifdef __cplusplus
}
#endif
