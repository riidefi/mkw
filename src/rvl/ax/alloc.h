#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80124edc..0x80124ef0
UNKNOWN_FUNCTION(__AXGetStackHead);
// PAL: 0x80124ef0..0x80124f9c
UNKNOWN_FUNCTION(__AXServiceCallbackStack);
// PAL: 0x80124f9c..0x8012504c
void __AXAllocInit(void);
// PAL: 0x8012504c..0x80125068
UNKNOWN_FUNCTION(__AXPushFreeStack);
// PAL: 0x80125068..0x80125078
UNKNOWN_FUNCTION(__AXPushCallbackStack);
// PAL: 0x80125078..0x801250fc
UNKNOWN_FUNCTION(__AXRemoveFromStack);
// PAL: 0x801250fc..0x80125178
UNKNOWN_FUNCTION(AXFreeVoice);
// PAL: 0x80125178..0x80125394
UNKNOWN_FUNCTION(AXAcquireVoice);

#ifdef __cplusplus
}
#endif
