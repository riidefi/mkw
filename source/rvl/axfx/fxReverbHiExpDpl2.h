#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801290a0..0x8012912c
UNKNOWN_FUNCTION(AXFXReverbHiExpGetMemSizeDpl2);
// PAL: 0x8012912c..0x801292ec
UNKNOWN_FUNCTION(AXFXReverbHiExpInitDpl2);
// PAL: 0x801292ec..0x801293bc
UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsDpl2);
// PAL: 0x801293bc..0x80129470
UNKNOWN_FUNCTION(AXFXReverbHiExpSettingsUpdateDpl2);
// PAL: 0x80129470..0x801294c4
UNKNOWN_FUNCTION(AXFXReverbHiExpShutdownDpl2);
// PAL: 0x801294c4..0x80129a74
UNKNOWN_FUNCTION(AXFXReverbHiExpCallbackDpl2);
// PAL: 0x80129a74..0x80129be8
UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__AllocDelayLine);
// PAL: 0x80129be8..0x80129d0c
UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__BzeroDelayLines);
// PAL: 0x80129d0c..0x80129e20
UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__FreeDelayLine);
// PAL: 0x80129e20..0x8012a154
UNKNOWN_FUNCTION(AXFXReverbHiExpDpl2__InitParams);

#ifdef __cplusplus
}
#endif
