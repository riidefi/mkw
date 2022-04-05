#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXSPB {
  char unknown[120];
} AXSPB;

// PAL: 0x80126e30..0x80126e3c
AXSPB* __AXGetStudio();
// PAL: 0x80126e3c..0x80126ea8
UNKNOWN_FUNCTION(__AXDepopFadeMain);
// PAL: 0x80126ea8..0x80126f14
UNKNOWN_FUNCTION(__AXDepopFadeRmt);
// PAL: 0x80126f14..0x8012708c
UNKNOWN_FUNCTION(__AXPrintStudio);
// PAL: 0x8012708c..0x801270e4
void __AXSPBInit();
// PAL: 0x801270e4..0x80127250
UNKNOWN_FUNCTION(__AXDepopVoice);

#ifdef __cplusplus
}
#endif
