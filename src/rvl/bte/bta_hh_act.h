#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80135844..0x801359b8
UNKNOWN_FUNCTION(bta_hh_api_enable);
// PAL: 0x801359b8..0x80135abc
UNKNOWN_FUNCTION(bta_hh_api_disable);
// PAL: 0x80135abc..0x80135b60
UNKNOWN_FUNCTION(bta_hh_disc_cmpl);
// PAL: 0x80135b60..0x80135c94
UNKNOWN_FUNCTION(bta_hh_sdp_cback);
// PAL: 0x80135c94..0x80135e28
UNKNOWN_FUNCTION(bta_hh_start_sdp);
// PAL: 0x80135e28..0x80135f90
UNKNOWN_FUNCTION(bta_hh_sdp_cmpl);
// PAL: 0x80135f90..0x80135ff8
UNKNOWN_FUNCTION(bta_hh_api_disc_act);
// PAL: 0x80135ff8..0x80136120
UNKNOWN_FUNCTION(bta_hh_open_cmpl_act);
// PAL: 0x80136120..0x801361d8
UNKNOWN_FUNCTION(bta_hh_open_act);
// PAL: 0x801361d8..0x80136230
UNKNOWN_FUNCTION(bta_hh_data_act);
// PAL: 0x80136230..0x80136498
UNKNOWN_FUNCTION(bta_hh_handsk_act);
// PAL: 0x80136498..0x80136690
UNKNOWN_FUNCTION(bta_hh_ctrl_dat_act);
// PAL: 0x80136690..0x80136890
UNKNOWN_FUNCTION(bta_hh_close_act);
// PAL: 0x80136890..0x801368ac
UNKNOWN_FUNCTION(bta_hh_get_dscp_act);
// PAL: 0x801368ac..0x80136a10
UNKNOWN_FUNCTION(bta_hh_maint_dev_act);
// PAL: 0x80136a10..0x80136b2c
UNKNOWN_FUNCTION(bta_hh_get_acl_q_info);
// PAL: 0x80136b2c..0x80136cf4
UNKNOWN_FUNCTION(bta_hh_write_dev_act);
// PAL: 0x80136cf4..0x80136f8c
UNKNOWN_FUNCTION(bta_hh_cback);

#ifdef __cplusplus
}
#endif