#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CXUncompContextLZ {
  u8 _[24];
};
enum CXResult { CXResultSuccess = 0 };

void CXInitUncompContextLZ(CXUncompContextLZ* pCtx, void* pDst);
CXResult CXReadUncompLZ(CXUncompContextLZ* pCtx, const void* pSrc, u32 len);
u32 CXGetUncompressedSize(const void* pBinary);

#ifdef __cplusplus
}
#endif