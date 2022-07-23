#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80131940..0x80131980
UNKNOWN_FUNCTION(btu_task_init);
// PAL: 0x80131980..0x80131d0c
UNKNOWN_FUNCTION(btu_task_msg_handler);
// PAL: 0x80131d0c..0x80131d7c
UNKNOWN_FUNCTION(btu_start_timer);
// PAL: 0x80131d7c..0x80131d90
UNKNOWN_FUNCTION(btu_stop_timer);

#ifdef __cplusplus
}
#endif
