#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80155e38..0x80155e70
UNKNOWN_FUNCTION(rfc_calc_fcs);
// PAL: 0x80155e70..0x80155ebc
UNKNOWN_FUNCTION(rfc_check_fcs);
// PAL: 0x80155ebc..0x80156014
UNKNOWN_FUNCTION(rfc_alloc_multiplexer_channel);
// PAL: 0x80156014..0x8015609c
UNKNOWN_FUNCTION(rfc_release_multiplexer_channel);
// PAL: 0x8015609c..0x80156110
UNKNOWN_FUNCTION(rfc_timer_start);
// PAL: 0x80156110..0x80156168
UNKNOWN_FUNCTION(rfc_timer_stop);
// PAL: 0x80156168..0x801561e8
UNKNOWN_FUNCTION(rfc_port_timer_start);
// PAL: 0x801561e8..0x80156240
UNKNOWN_FUNCTION(rfc_port_timer_stop);
// PAL: 0x80156240..0x80156304
UNKNOWN_FUNCTION(rfc_check_mcb_active);
// PAL: 0x80156304..0x80156340
UNKNOWN_FUNCTION(rfcomm_process_timeout);
// PAL: 0x80156340..0x80156394
UNKNOWN_FUNCTION(rfc_sec_check_complete);
// PAL: 0x80156394..0x801564ec
UNKNOWN_FUNCTION(rfc_port_closed);
// PAL: 0x801564ec..0x80156578
UNKNOWN_FUNCTION(rfc_inc_credit);
// PAL: 0x80156578..0x801565b4
UNKNOWN_FUNCTION(rfc_dec_credit);
// PAL: 0x801565b4..0x80156618
UNKNOWN_FUNCTION(rfc_check_send_cmd);

#ifdef __cplusplus
}
#endif
