#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a15ec..0x801a1600
void DCEnable(void);
// PAL: 0x801a1600..0x801a162c
void DCInvalidateRange(void*, u32);
// PAL: 0x801a162c..0x801a165c
void DCFlushRange(void*, u32);
// PAL: 0x801a165c..0x801a168c
void DCStoreRange(void*, u32);
// PAL: 0x801a168c..0x801a16b8
void DCFlushRangeNoSync(void*, u32);
// PAL: 0x801a16b8..0x801a16e4
void DCStoreRangeNoSync(void*, u32);
// PAL: 0x801a16e4..0x801a1710
void DCZeroRange(void*, u32);
// PAL: 0x801a1710..0x801a1744
void ICInvalidateRange(void*, u32);
// PAL: 0x801a1744..0x801a1754
void ICFlashInvalidate(void);
// PAL: 0x801a1754..0x801a1768
void ICEnable(void);
// PAL: 0x801a1768..0x801a1834
void __LCEnable(void);
// PAL: 0x801a1834..0x801a186c
void LCEnable(void);
// PAL: 0x801a186c..0x801a1894
void LCDisable(void);
// PAL: 0x801a1894..0x801a18b8
void LCLoadBlocks(void* dst, void* src, u32 num);
// PAL: 0x801a18b8..0x801a18dc
void LCStoreBlocks(void* dst, void* src, u32 num);
// PAL: 0x801a18dc..0x801a197c
u32 LCStoreData(void* dst, void* src, u32 num);
// PAL: 0x801a197c..0x801a1988
u32 LCQueueLength(void);
// PAL: 0x801a1988..0x801a199c
void LCQueueWait(u32);
// PAL: 0x801a199c..0x801a1ae4
UNKNOWN_FUNCTION(DMAErrorHandler);
// PAL: 0x801a1ae4..0x801a1c1c
UNKNOWN_FUNCTION(__OSCacheInit);

#ifdef __cplusplus
}
#endif
