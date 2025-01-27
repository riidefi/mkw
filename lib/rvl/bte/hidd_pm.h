#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80146f24..0x801470fc
UNKNOWN_FUNCTION(hidd_pm_set_now);
// PAL: 0x801470fc..0x80147254
UNKNOWN_FUNCTION(hidd_pm_proc_mode_change);
// PAL: 0x80147254..0x801472a0
UNKNOWN_FUNCTION(hidd_pm_inact_timeout);

#ifdef __cplusplus
}
#endif
