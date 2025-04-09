#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <rvl/os/osContext.h>

#ifdef __cplusplus
extern "C" {
#endif

void DCEnable(void);
void DCInvalidateRange(void*, u32);
void DCFlushRange(void*, u32);
void DCStoreRange(void*, u32);
void DCFlushRangeNoSync(void*, u32);
void DCStoreRangeNoSync(void*, u32);
void DCZeroRange(void*, u32);
void ICInvalidateRange(void*, u32);
void ICFlashInvalidate(void);
void ICEnable(void);
void __LCEnable(void);
void LCEnable(void);
void LCDisable(void);
void LCLoadBlocks(void* dst, void* src, u32 num);
void LCStoreBlocks(void* dst, void* src, u32 num);
u32 LCStoreData(void* dst, void* src, u32 num);
u32 LCQueueLength(void);
void LCQueueWait(u32);
void DMAErrorHandler(u8 error, OSContext* ctx, u32 dsisr, u32 dar, ...);
void __OSCacheInit(void);


#ifdef __cplusplus
}
#endif
