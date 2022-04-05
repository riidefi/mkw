#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8012802c..0x80128090
UNKNOWN_FUNCTION(AXFXReverbHiInit);
// PAL: 0x80128090..0x801280b4
UNKNOWN_FUNCTION(AXFXReverbHiShutdown);
// PAL: 0x801280b4..0x801280b8
UNKNOWN_FUNCTION(AXFXReverbHiCallback);

#ifdef __cplusplus
}
#endif
