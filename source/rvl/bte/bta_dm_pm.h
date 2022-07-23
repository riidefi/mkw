#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80134e28..0x80134e90
UNKNOWN_FUNCTION(bta_dm_init_pm);
// PAL: 0x80134e90..0x80134ea8
UNKNOWN_FUNCTION(bta_dm_disable_pm);
// PAL: 0x80134ea8..0x80135228
UNKNOWN_FUNCTION(bta_dm_pm_cback);
// PAL: 0x80135228..0x801355a8
UNKNOWN_FUNCTION(bta_dm_pm_set_mode);
// PAL: 0x801355a8..0x80135620
UNKNOWN_FUNCTION(bta_dm_pm_btm_cback);
// PAL: 0x80135620..0x80135718
UNKNOWN_FUNCTION(bta_dm_pm_timer_cback);
// PAL: 0x80135718..0x80135838
UNKNOWN_FUNCTION(bta_dm_pm_btm_status);
// PAL: 0x80135838..0x80135844
UNKNOWN_FUNCTION(bta_dm_pm_timer);

#ifdef __cplusplus
}
#endif
