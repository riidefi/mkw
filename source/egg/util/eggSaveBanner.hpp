#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8023a884..0x8023a8ec
UNKNOWN_FUNCTION(SaveBanner_create);
// PAL: 0x8023a8ec..0x8023aa04
UNKNOWN_FUNCTION(SaveBanner_initBanner);
// PAL: 0x8023aa04..0x8023aa78
UNKNOWN_FUNCTION(SaveBanner_existBannerFile);
// PAL: 0x8023aa78..0x8023ab54
UNKNOWN_FUNCTION(SaveBanner_createBannerFile);
// PAL: 0x8023ab54..0x8023ab5c
UNKNOWN_FUNCTION(SaveBanner_saveBannerFile);
// PAL: 0x8023ab5c..0x8023ab64
UNKNOWN_FUNCTION(SaveBanner_isErrorOccured);
// PAL: 0x8023ab64..0x8023abd8
UNKNOWN_FUNCTION(SaveBanner_destroy);
// PAL: 0x8023abd8..0x8023ac3c
UNKNOWN_FUNCTION(SaveBanner_construct);
// PAL: 0x8023ac3c..0x8023ad10
UNKNOWN_FUNCTION(unk_8023ac3c);

#ifdef __cplusplus
}
#endif
