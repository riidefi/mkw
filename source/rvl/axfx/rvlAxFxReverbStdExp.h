#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8012b47c..0x8012b4dc
UNKNOWN_FUNCTION(AXFXReverbStdExpGetMemSize);
// PAL: 0x8012b4dc..0x8012b658
UNKNOWN_FUNCTION(AXFXReverbStdExpInit);
// PAL: 0x8012b658..0x8012b728
UNKNOWN_FUNCTION(AXFXReverbStdExpSettings);
// PAL: 0x8012b728..0x8012b7dc
UNKNOWN_FUNCTION(AXFXReverbStdExpSettingsUpdate);
// PAL: 0x8012b7dc..0x8012b830
UNKNOWN_FUNCTION(AXFXReverbStdExpShutdown);
// PAL: 0x8012b830..0x8012bb9c
UNKNOWN_FUNCTION(AXFXReverbStdExpCallback);
// PAL: 0x8012bb9c..0x8012bce0
UNKNOWN_FUNCTION(AXFXReverbStdExp__AllocDelayLine);
// PAL: 0x8012bce0..0x8012bde0
UNKNOWN_FUNCTION(AXFXReverbStdExp__BzeroDelayLines);
// PAL: 0x8012bde0..0x8012bed0
UNKNOWN_FUNCTION(AXFXReverbStdExp__FreeDelayLine);
// PAL: 0x8012bed0..0x8012c17c
UNKNOWN_FUNCTION(AXFXReverbStdExp__InitParams);

#ifdef __cplusplus
}
#endif
