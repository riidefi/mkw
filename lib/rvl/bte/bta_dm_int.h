#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80132520..0x80132630
UNKNOWN_FUNCTION(bta_dm_enable);
// PAL: 0x80132630..0x801326e0
UNKNOWN_FUNCTION(bta_dm_disable);
// PAL: 0x801326e0..0x8013279c
UNKNOWN_FUNCTION(bta_dm_disable_timer_cback);
// PAL: 0x8013279c..0x801327a4
UNKNOWN_FUNCTION(bta_dm_set_dev_name);
// PAL: 0x801327a4..0x801327ec
UNKNOWN_FUNCTION(bta_dm_set_visibility);
// PAL: 0x801327ec..0x8013285c
UNKNOWN_FUNCTION(bta_dm_bond);
// PAL: 0x8013285c..0x801328f8
UNKNOWN_FUNCTION(bta_dm_pin_reply);
// PAL: 0x801328f8..0x801329cc
UNKNOWN_FUNCTION(bta_dm_auth_reply);
// PAL: 0x801329cc..0x80132a2c
UNKNOWN_FUNCTION(bta_dm_search_start);
// PAL: 0x80132a2c..0x80132ab0
UNKNOWN_FUNCTION(bta_dm_search_cancel);
// PAL: 0x80132ab0..0x80132bc4
UNKNOWN_FUNCTION(bta_dm_discover);
// PAL: 0x80132bc4..0x80132de8
UNKNOWN_FUNCTION(bta_dm_inq_cmpl);
// PAL: 0x80132de8..0x80132f54
UNKNOWN_FUNCTION(bta_dm_rmt_name);
// PAL: 0x80132f54..0x80132fb8
UNKNOWN_FUNCTION(bta_dm_disc_rmt_name);
// PAL: 0x80132fb8..0x80133220
UNKNOWN_FUNCTION(bta_dm_sdp_result);
// PAL: 0x80133220..0x80133238
UNKNOWN_FUNCTION(bta_dm_search_cmpl);
// PAL: 0x80133238..0x80133288
UNKNOWN_FUNCTION(bta_dm_disc_result);
// PAL: 0x80133288..0x80133310
UNKNOWN_FUNCTION(bta_dm_search_result);
// PAL: 0x80133310..0x8013335c
UNKNOWN_FUNCTION(bta_dm_search_timer_cback);
// PAL: 0x8013335c..0x801333a0
UNKNOWN_FUNCTION(bta_dm_free_sdp_db);
// PAL: 0x801333a0..0x801333e8
UNKNOWN_FUNCTION(bta_dm_queue_search);
// PAL: 0x801333e8..0x80133430
UNKNOWN_FUNCTION(bta_dm_queue_disc);
// PAL: 0x80133430..0x80133474
UNKNOWN_FUNCTION(bta_dm_search_clear_queue);
// PAL: 0x80133474..0x801334b8
UNKNOWN_FUNCTION(bta_dm_search_cancel_cmpl);
// PAL: 0x801334b8..0x80133514
UNKNOWN_FUNCTION(bta_dm_search_cancel_transac_cmpl);
// PAL: 0x80133514..0x8013352c
UNKNOWN_FUNCTION(bta_dm_search_cancel_notify);
// PAL: 0x8013352c..0x801336cc
UNKNOWN_FUNCTION(bta_dm_find_services);
// PAL: 0x801336cc..0x801337ac
UNKNOWN_FUNCTION(bta_dm_discover_next_device);
// PAL: 0x801337ac..0x801337f4
UNKNOWN_FUNCTION(bta_dm_sdp_callback);
// PAL: 0x801337f4..0x80133884
UNKNOWN_FUNCTION(bta_dm_inq_results_cb);
// PAL: 0x80133884..0x801338d0
UNKNOWN_FUNCTION(bta_dm_inq_cmpl_cb);
// PAL: 0x801338d0..0x80133910
UNKNOWN_FUNCTION(bta_dm_service_search_remname_cback);
// PAL: 0x80133910..0x8013399c
UNKNOWN_FUNCTION(bta_dm_remname_cback);
// PAL: 0x8013399c..0x80133a24
UNKNOWN_FUNCTION(bta_dm_disc_remname_cback);
// PAL: 0x80133a24..0x80133a28
UNKNOWN_FUNCTION(bta_dm_cancel_rmt_name);
// PAL: 0x80133a28..0x80133af0
UNKNOWN_FUNCTION(bta_dm_authorize_cback);
// PAL: 0x80133af0..0x80133bb0
UNKNOWN_FUNCTION(bta_dm_pinname_cback);
// PAL: 0x80133bb0..0x80133ce0
UNKNOWN_FUNCTION(bta_dm_pin_cback);
// PAL: 0x80133ce0..0x80133ce8
UNKNOWN_FUNCTION(bta_dm_link_key_request_cback);
// PAL: 0x80133ce8..0x80133d84
UNKNOWN_FUNCTION(bta_dm_new_link_key_cback);
// PAL: 0x80133d84..0x80133e08
UNKNOWN_FUNCTION(bta_dm_authentication_complete_cback);
// PAL: 0x80133e08..0x80133e30
UNKNOWN_FUNCTION(bta_dm_local_addr_cback);
// PAL: 0x80133e30..0x80133e6c
UNKNOWN_FUNCTION(bta_dm_signal_strength);
// PAL: 0x80133e6c..0x80133f60
UNKNOWN_FUNCTION(bta_dm_signal_strength_timer_cback);
// PAL: 0x80133f60..0x80133fd0
UNKNOWN_FUNCTION(bta_dm_acl_change_cback);
// PAL: 0x80133fd0..0x80134250
UNKNOWN_FUNCTION(bta_dm_acl_change);
// PAL: 0x80134250..0x8013426c
UNKNOWN_FUNCTION(bta_dm_disable_conn_down_timer_cback);
// PAL: 0x8013426c..0x801342d8
UNKNOWN_FUNCTION(bta_dm_rssi_cback);
// PAL: 0x801342d8..0x80134344
UNKNOWN_FUNCTION(bta_dm_link_quality_cback);
// PAL: 0x80134344..0x80134428
UNKNOWN_FUNCTION(bta_dm_l2cap_server_compress_cback);
// PAL: 0x80134428..0x80134660
UNKNOWN_FUNCTION(bta_dm_compress_cback);
// PAL: 0x80134660..0x80134768
UNKNOWN_FUNCTION(bta_dm_rm_cback);
// PAL: 0x80134768..0x801347ec
UNKNOWN_FUNCTION(bta_dm_keep_acl);
// PAL: 0x801347ec..0x80134808
UNKNOWN_FUNCTION(bta_dm_immediate_disable);
// PAL: 0x80134808..0x8013480c
UNKNOWN_FUNCTION(bta_dm_reset_complete);
// PAL: 0x8013480c..0x8013485c
UNKNOWN_FUNCTION(bta_dm_send_hci_reset);

#ifdef __cplusplus
}
#endif
