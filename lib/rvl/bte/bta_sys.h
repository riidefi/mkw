#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80131e64..0x80131e74
UNKNOWN_FUNCTION(bta_sys_rm_register);
// PAL: 0x80131e74..0x80131e84
UNKNOWN_FUNCTION(bta_sys_compress_register);
// PAL: 0x80131e84..0x80131e94
UNKNOWN_FUNCTION(bta_sys_pm_register);
// PAL: 0x80131e94..0x80131f58
UNKNOWN_FUNCTION(bta_sys_conn_open);
// PAL: 0x80131f58..0x8013201c
UNKNOWN_FUNCTION(bta_sys_conn_close);
// PAL: 0x8013201c..0x80132050
UNKNOWN_FUNCTION(bta_sys_sco_close);
// PAL: 0x80132050..0x80132084
UNKNOWN_FUNCTION(bta_sys_idle);
// PAL: 0x80132084..0x801320b8
UNKNOWN_FUNCTION(bta_sys_busy);
// PAL: 0x801320b8..0x8013211c
UNKNOWN_FUNCTION(bta_sys_init);
// PAL: 0x8013211c..0x80132208
UNKNOWN_FUNCTION(bta_sys_event);
// PAL: 0x80132208..0x80132228
UNKNOWN_FUNCTION(bta_sys_timer_update);
// PAL: 0x80132228..0x8013223c
UNKNOWN_FUNCTION(bta_sys_register);
// PAL: 0x8013223c..0x80132258
UNKNOWN_FUNCTION(bta_sys_sendmsg);
// PAL: 0x80132258..0x80132278
UNKNOWN_FUNCTION(bta_sys_start_timer);
// PAL: 0x80132278..0x8013228c
UNKNOWN_FUNCTION(bta_sys_stop_timer);
// PAL: 0x8013228c..0x801322f4
UNKNOWN_FUNCTION(bta_sys_disable);
// PAL: 0x801322f4..0x801322fc
UNKNOWN_FUNCTION(bta_sys_set_trace_level);

#ifdef __cplusplus
}
#endif
