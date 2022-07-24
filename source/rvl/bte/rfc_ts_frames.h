#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801547f0..0x801548a0
UNKNOWN_FUNCTION(rfc_send_sabme);
// PAL: 0x801548a0..0x80154950
UNKNOWN_FUNCTION(rfc_send_ua);
// PAL: 0x80154950..0x80154a14
UNKNOWN_FUNCTION(rfc_send_dm);
// PAL: 0x80154a14..0x80154ac4
UNKNOWN_FUNCTION(rfc_send_disc);
// PAL: 0x80154ac4..0x80154c5c
UNKNOWN_FUNCTION(rfc_send_buf_uih);
// PAL: 0x80154c5c..0x80154d44
UNKNOWN_FUNCTION(rfc_send_pn);
// PAL: 0x80154d44..0x80154dc8
UNKNOWN_FUNCTION(rfc_send_fcon);
// PAL: 0x80154dc8..0x80154e4c
UNKNOWN_FUNCTION(rfc_send_fcoff);
// PAL: 0x80154e4c..0x80154f6c
UNKNOWN_FUNCTION(rfc_send_msc);
// PAL: 0x80154f6c..0x8015501c
UNKNOWN_FUNCTION(rfc_send_rls);
// PAL: 0x8015501c..0x80155138
UNKNOWN_FUNCTION(rfc_send_rpn);
// PAL: 0x80155138..0x801551e0
UNKNOWN_FUNCTION(rfc_send_test);
// PAL: 0x801551e0..0x801552a0
UNKNOWN_FUNCTION(rfc_send_credit);
// PAL: 0x801552a0..0x80155814
UNKNOWN_FUNCTION(rfc_parse_data);
// PAL: 0x80155814..0x80155e38
UNKNOWN_FUNCTION(rfc_process_mx_message);

#ifdef __cplusplus
}
#endif
