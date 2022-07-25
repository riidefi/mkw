#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8014e2c4..0x8014e398
UNKNOWN_FUNCTION(l2cu_allocate_lcb);
// PAL: 0x8014e398..0x8014e498
UNKNOWN_FUNCTION(l2cu_release_lcb);
// PAL: 0x8014e498..0x8014e520
UNKNOWN_FUNCTION(l2cu_find_lcb_by_bd_addr);
// PAL: 0x8014e520..0x8014e5b0
UNKNOWN_FUNCTION(l2cu_find_lcb_by_handle);
// PAL: 0x8014e5b0..0x8014e5c0
UNKNOWN_FUNCTION(l2cu_get_conn_role);
// PAL: 0x8014e5c0..0x8014e684
UNKNOWN_FUNCTION(l2cu_build_header);
// PAL: 0x8014e684..0x8014e780
UNKNOWN_FUNCTION(l2cu_send_peer_cmd_reject);
// PAL: 0x8014e780..0x8014e844
UNKNOWN_FUNCTION(l2cu_send_peer_connect_req);
// PAL: 0x8014e844..0x8014e91c
UNKNOWN_FUNCTION(l2cu_send_peer_connect_rsp);
// PAL: 0x8014e91c..0x8014e9dc
UNKNOWN_FUNCTION(l2cu_reject_connection);
// PAL: 0x8014e9dc..0x8014ecd4
UNKNOWN_FUNCTION(l2cu_send_peer_config_req);
// PAL: 0x8014ecd4..0x8014efcc
UNKNOWN_FUNCTION(l2cu_send_peer_config_rsp);
// PAL: 0x8014efcc..0x8014f180
UNKNOWN_FUNCTION(l2cu_send_peer_config_rej);
// PAL: 0x8014f180..0x8014f254
UNKNOWN_FUNCTION(l2cu_send_peer_disc_req);
// PAL: 0x8014f254..0x8014f314
UNKNOWN_FUNCTION(l2cu_send_peer_disc_rsp);
// PAL: 0x8014f314..0x8014f484
UNKNOWN_FUNCTION(l2cu_send_peer_echo_req);
// PAL: 0x8014f484..0x8014f620
UNKNOWN_FUNCTION(l2cu_send_peer_echo_rsp);
// PAL: 0x8014f620..0x8014f6c4
UNKNOWN_FUNCTION(l2cu_send_peer_info_rsp);
// PAL: 0x8014f6c4..0x8014f7d0
UNKNOWN_FUNCTION(l2cu_allocate_ccb);
// PAL: 0x8014f7d0..0x8014f974
UNKNOWN_FUNCTION(l2cu_release_ccb);
// PAL: 0x8014f974..0x8014f9d0
UNKNOWN_FUNCTION(l2cu_find_ccb_by_cid);
// PAL: 0x8014f9d0..0x8014fa1c
UNKNOWN_FUNCTION(l2cu_allocate_rcb);
// PAL: 0x8014fa1c..0x8014fa2c
UNKNOWN_FUNCTION(l2cu_release_rcb);
// PAL: 0x8014fa2c..0x8014fae4
UNKNOWN_FUNCTION(l2cu_find_rcb_by_psm);
// PAL: 0x8014fae4..0x8014fc2c
UNKNOWN_FUNCTION(l2cu_process_peer_cfg_req);
// PAL: 0x8014fc2c..0x8014fc6c
UNKNOWN_FUNCTION(l2cu_process_peer_cfg_rsp);
// PAL: 0x8014fc6c..0x8014fd7c
UNKNOWN_FUNCTION(l2cu_process_our_cfg_req);
// PAL: 0x8014fd7c..0x8014fdbc
UNKNOWN_FUNCTION(l2cu_process_our_cfg_rsp);
// PAL: 0x8014fdbc..0x8014fe28
UNKNOWN_FUNCTION(l2cu_device_reset);
// PAL: 0x8014fe28..0x8014ff40
UNKNOWN_FUNCTION(l2cu_create_conn);
// PAL: 0x8014ff40..0x80150010
UNKNOWN_FUNCTION(l2cu_create_conn_after_switch);
// PAL: 0x80150010..0x801500a0
UNKNOWN_FUNCTION(l2cu_find_lcb_by_state);
// PAL: 0x801500a0..0x80150188
UNKNOWN_FUNCTION(l2cu_lcb_disconnecting);

#ifdef __cplusplus
}
#endif
