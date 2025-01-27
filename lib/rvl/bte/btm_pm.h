#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013d61c..0x8013d6d8
UNKNOWN_FUNCTION(BTM_PmRegister);
// PAL: 0x8013d6d8..0x8013d8a8
UNKNOWN_FUNCTION(BTM_SetPowerMode);
// PAL: 0x8013d8a8..0x8013d960
UNKNOWN_FUNCTION(BTM_ReadPowerMode);
// PAL: 0x8013d960..0x8013d9d8
UNKNOWN_FUNCTION(btm_pm_reset);
// PAL: 0x8013d9d8..0x8013da28
UNKNOWN_FUNCTION(btm_pm_sm_alloc);
// PAL: 0x8013da28..0x8013dc44
UNKNOWN_FUNCTION(btm_pm_compare_modes);
// PAL: 0x8013dc44..0x8013dda4
UNKNOWN_FUNCTION(btm_pm_get_set_mode);
// PAL: 0x8013dda4..0x8013dfd8
UNKNOWN_FUNCTION(btm_pm_snd_md_req);
// PAL: 0x8013dfd8..0x8013e088
UNKNOWN_FUNCTION(btm_pm_proc_cmd_status);
// PAL: 0x8013e088..0x8013e2b0
UNKNOWN_FUNCTION(btm_pm_proc_mode_change);

#ifdef __cplusplus
}
#endif
