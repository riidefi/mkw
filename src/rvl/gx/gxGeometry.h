#pragma once

// Credit: kiwi515

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8016f0f0..0x8016f23c
void GXBegin(int, int formatIndex, int);
#define GXEnd() (void)0

// PAL: 0x8016ee78..0x8016f0f0
UNKNOWN_FUNCTION(__GXSetDirtyState);
// PAL: 0x8016f23c..0x8016f314
UNKNOWN_FUNCTION(__GXSendFlushPrim);
// PAL: 0x8016f314..0x8016f348
UNKNOWN_FUNCTION(GXSetLineWidth);
// PAL: 0x8016f348..0x8016f37c
UNKNOWN_FUNCTION(GXSetPointSize);
// PAL: 0x8016f37c..0x8016f3b8
UNKNOWN_FUNCTION(GXEnableTexOffsets);
// PAL: 0x8016f3b8..0x8016f3e0
UNKNOWN_FUNCTION(GXSetCullMode);
// PAL: 0x8016f3e0..0x8016f414
UNKNOWN_FUNCTION(GXSetCoPlanar);
// PAL: 0x8016f414..0x8016f438
UNKNOWN_FUNCTION(__GXSetGenMode);

#ifdef __cplusplus
}
#endif
