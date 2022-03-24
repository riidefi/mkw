#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a4aa4..0x801a4dc8
UNKNOWN_FUNCTION(ScreenReport);
// PAL: 0x801a4dc8..0x801a4ec4
UNKNOWN_FUNCTION(ConfigureVideo);
// PAL: 0x801a4ec4..0x801a50dc
UNKNOWN_FUNCTION(OSFatal);
// PAL: 0x801a50dc..0x801a56dc
UNKNOWN_FUNCTION(Halt);

#ifdef __cplusplus
}
#endif
