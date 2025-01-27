#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801322fc..0x80132348
UNKNOWN_FUNCTION(ptim_init);
// PAL: 0x80132348..0x801323fc
UNKNOWN_FUNCTION(ptim_timer_update);
// PAL: 0x801323fc..0x8013249c
UNKNOWN_FUNCTION(ptim_start_timer);
// PAL: 0x8013249c..0x801324dc
UNKNOWN_FUNCTION(ptim_stop_timer);

#ifdef __cplusplus
}
#endif
