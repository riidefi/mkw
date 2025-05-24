#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8012fb18..0x8012fbd4
UNKNOWN_FUNCTION(gki_timers_init);
// PAL: 0x8012fbd4..0x8012fbe8
UNKNOWN_FUNCTION(GKI_get_tick_count);
// PAL: 0x8012fbe8..0x8012fd38
UNKNOWN_FUNCTION(GKI_start_timer);
// PAL: 0x8012fd38..0x8012fdc0
UNKNOWN_FUNCTION(GKI_stop_timer);
// PAL: 0x8012fdc0..0x8012fdd4
UNKNOWN_FUNCTION(GKI_init_timer_list);
// PAL: 0x8012fdd4..0x8012fe60
UNKNOWN_FUNCTION(GKI_update_timer_list);
// PAL: 0x8012fe60..0x8012ff4c
UNKNOWN_FUNCTION(GKI_add_to_timer_list);
// PAL: 0x8012ff4c..0x80130070
UNKNOWN_FUNCTION(GKI_remove_from_timer_list);

#ifdef __cplusplus
}
#endif
