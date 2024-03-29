#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80125bac..0x80125bb4
UNKNOWN_FUNCTION(__AXGetCommandListCycles);
// PAL: 0x80125bb4..0x80125be4
UNKNOWN_FUNCTION(__AXGetCommandListAddress);
// PAL: 0x80125be4..0x801265a4
UNKNOWN_FUNCTION(__AXNextFrame);
// PAL: 0x801265a4..0x801265e0
UNKNOWN_FUNCTION(__AXClInit);
// PAL: 0x801265e0..0x801265e8
UNKNOWN_FUNCTION(AXSetMode);
// PAL: 0x801265e8..0x801265f0
UNKNOWN_FUNCTION(AXGetMode);
// PAL: 0x801265f0..0x801265f8
UNKNOWN_FUNCTION(AXGetAuxAReturnVolume);
// PAL: 0x801265f8..0x80126600
UNKNOWN_FUNCTION(AXGetAuxBReturnVolume);
// PAL: 0x80126600..0x80126608
UNKNOWN_FUNCTION(AXGetAuxCReturnVolume);
// PAL: 0x80126608..0x80126620
UNKNOWN_FUNCTION(AXSetMasterVolume);
// PAL: 0x80126620..0x80126628
UNKNOWN_FUNCTION(AXSetAuxAReturnVolume);
// PAL: 0x80126628..0x80126630
UNKNOWN_FUNCTION(AXSetAuxBReturnVolume);
// PAL: 0x80126630..0x80126638
UNKNOWN_FUNCTION(AXSetAuxCReturnVolume);

#ifdef __cplusplus
}
#endif
