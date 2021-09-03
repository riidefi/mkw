#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a56dc..0x801a5810
UNKNOWN_FUNCTION(GetFontCode);
// PAL: 0x801a5810..0x801a59b4
UNKNOWN_FUNCTION(Decode);
// PAL: 0x801a59b4..0x801a5a34
UNKNOWN_FUNCTION(OSSetFontEncode);
// PAL: 0x801a5a34..0x801a5d34
UNKNOWN_FUNCTION(ReadFont);
// PAL: 0x801a5d34..0x801a5e5c
UNKNOWN_FUNCTION(OSLoadFont);
// PAL: 0x801a5e5c..0x801a5f58
UNKNOWN_FUNCTION(ParseStringS);
// PAL: 0x801a5f58..0x801a6114
UNKNOWN_FUNCTION(ParseStringW);
// PAL: 0x801a6114..0x801a63a4
UNKNOWN_FUNCTION(OSGetFontTexel);
// PAL: 0x801a63a4..0x801a64f4
UNKNOWN_FUNCTION(OSGetFontTexture);
// PAL: 0x801a64f4..0x801a65ac
UNKNOWN_FUNCTION(OSGetFontWidth);

#ifdef __cplusplus
}
#endif
