#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801280b8..0x80128140
UNKNOWN_FUNCTION(AXFXReverbHiExpGetMemSize);
// PAL: 0x80128140..0x801282dc
UNKNOWN_FUNCTION(AXFXReverbHiExpInit);
// PAL: 0x801282dc..0x801283ac
UNKNOWN_FUNCTION(AXFXReverbHiExpSettings);
// PAL: 0x801283ac..0x80128460
UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsUpdate);
// PAL: 0x80128460..0x801284b4
UNKNOWN_FUNCTION(AXFXReverbHiExpShutdown);
// PAL: 0x801284b4..0x801289d0
UNKNOWN_FUNCTION(AXFXReverbHiExpCallback);
// PAL: 0x801289d0..0x80128b44
UNKNOWN_FUNCTION(AXFXReverbHiExp__AllocDelayLine);
// PAL: 0x80128b44..0x80128c68
UNKNOWN_FUNCTION(AXFXReverbHiExp__BzeroDelayLines);
// PAL: 0x80128c68..0x80128d7c
UNKNOWN_FUNCTION(AXFXReverbHiExp__FreeDelayLine);
// PAL: 0x80128d7c..0x801290a0
UNKNOWN_FUNCTION(AXFXReverbHiExp__InitParams);

#ifdef __cplusplus
}
#endif
