#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80144618..0x801446c0
UNKNOWN_FUNCTION(btsnd_hcic_inquiry);
// PAL: 0x801446c0..0x80144720
UNKNOWN_FUNCTION(btsnd_hcic_inq_cancel);
// PAL: 0x80144720..0x801447e0
UNKNOWN_FUNCTION(btsnd_hcic_per_inq_mode);
// PAL: 0x801447e0..0x801448c0
UNKNOWN_FUNCTION(btsnd_hcic_create_conn);
// PAL: 0x801448c0..0x80144948
UNKNOWN_FUNCTION(btsnd_hcic_disconnect);
// PAL: 0x80144948..0x801449d4
UNKNOWN_FUNCTION(btsnd_hcic_add_SCO_conn);
// PAL: 0x801449d4..0x80144a34
UNKNOWN_FUNCTION(btsnd_hcic_accept_conn);
// PAL: 0x80144a34..0x80144a90
UNKNOWN_FUNCTION(btsnd_hcic_reject_conn);
// PAL: 0x80144a90..0x80144c30
UNKNOWN_FUNCTION(btsnd_hcic_link_key_req_reply);
// PAL: 0x80144c30..0x80144cd0
UNKNOWN_FUNCTION(btsnd_hcic_link_key_neg_reply);
// PAL: 0x80144cd0..0x80144eb4
UNKNOWN_FUNCTION(btsnd_hcic_pin_code_req_reply);
// PAL: 0x80144eb4..0x80144f54
UNKNOWN_FUNCTION(btsnd_hcic_pin_code_neg_reply);
// PAL: 0x80144f54..0x80144fe4
UNKNOWN_FUNCTION(btsnd_hcic_change_conn_type);
// PAL: 0x80144fe4..0x80145060
UNKNOWN_FUNCTION(btsnd_hcic_auth_request);
// PAL: 0x80145060..0x801450ec
UNKNOWN_FUNCTION(btsnd_hcic_set_conn_encrypt);
// PAL: 0x801450ec..0x801451c4
UNKNOWN_FUNCTION(btsnd_hcic_rmt_name_req);
// PAL: 0x801451c4..0x80145264
UNKNOWN_FUNCTION(btsnd_hcic_rmt_name_req_cancel);
// PAL: 0x80145264..0x801452e0
UNKNOWN_FUNCTION(btsnd_hcic_rmt_features_req);
// PAL: 0x801452e0..0x8014535c
UNKNOWN_FUNCTION(btsnd_hcic_rmt_ver_req);
// PAL: 0x8014535c..0x801453d8
UNKNOWN_FUNCTION(btsnd_hcic_read_rmt_clk_offset);
// PAL: 0x801453d8..0x801454d4
UNKNOWN_FUNCTION(btsnd_hcic_setup_esco_conn);
// PAL: 0x801454d4..0x801455bc
UNKNOWN_FUNCTION(btsnd_hcic_accept_esco_conn);
// PAL: 0x801455bc..0x8014561c
UNKNOWN_FUNCTION(btsnd_hcic_reject_esco_conn);
// PAL: 0x8014561c..0x801456d0
UNKNOWN_FUNCTION(btsnd_hcic_hold_mode);
// PAL: 0x801456d0..0x8014579c
UNKNOWN_FUNCTION(btsnd_hcic_sniff_mode);
// PAL: 0x8014579c..0x80145820
UNKNOWN_FUNCTION(btsnd_hcic_exit_sniff_mode);
// PAL: 0x80145820..0x801458d4
UNKNOWN_FUNCTION(btsnd_hcic_park_mode);
// PAL: 0x801458d4..0x80145958
UNKNOWN_FUNCTION(btsnd_hcic_exit_park_mode);
// PAL: 0x80145958..0x80145a08
UNKNOWN_FUNCTION(btsnd_hcic_switch_role);
// PAL: 0x80145a08..0x80145a9c
UNKNOWN_FUNCTION(btsnd_hcic_write_policy_set);
// PAL: 0x80145a9c..0x80145af8
UNKNOWN_FUNCTION(btsnd_hcic_reset);
// PAL: 0x80145af8..0x80145cb4
UNKNOWN_FUNCTION(btsnd_hcic_set_event_filter);
// PAL: 0x80145cb4..0x80145d28
UNKNOWN_FUNCTION(btsnd_hcic_write_pin_type);
// PAL: 0x80145d28..0x80145d88
UNKNOWN_FUNCTION(btsnd_hcic_read_stored_key);
// PAL: 0x80145d88..0x80145f48
UNKNOWN_FUNCTION(btsnd_hcic_write_stored_key);
// PAL: 0x80145f48..0x80145ff8
UNKNOWN_FUNCTION(btsnd_hcic_delete_stored_key);
// PAL: 0x80145ff8..0x80146138
UNKNOWN_FUNCTION(btsnd_hcic_change_name);
// PAL: 0x80146138..0x80146170
UNKNOWN_FUNCTION(btsnd_hcic_write_page_tout);
// PAL: 0x80146170..0x801461a0
UNKNOWN_FUNCTION(btsnd_hcic_write_scan_enable);
// PAL: 0x801461a0..0x801461e4
UNKNOWN_FUNCTION(btsnd_hcic_write_pagescan_cfg);
// PAL: 0x801461e4..0x80146228
UNKNOWN_FUNCTION(btsnd_hcic_write_inqscan_cfg);
// PAL: 0x80146228..0x8014629c
UNKNOWN_FUNCTION(btsnd_hcic_write_auth_enable);
// PAL: 0x8014629c..0x80146310
UNKNOWN_FUNCTION(btsnd_hcic_write_encr_mode);
// PAL: 0x80146310..0x80146354
UNKNOWN_FUNCTION(btsnd_hcic_write_dev_class);
// PAL: 0x80146354..0x80146398
UNKNOWN_FUNCTION(btsnd_hcic_write_auto_flush_tout);
// PAL: 0x80146398..0x80146454
UNKNOWN_FUNCTION(btsnd_hcic_set_host_buf_size);
// PAL: 0x80146454..0x801464e8
UNKNOWN_FUNCTION(btsnd_hcic_write_link_super_tout);
// PAL: 0x801464e8..0x80146558
UNKNOWN_FUNCTION(btsnd_hcic_write_cur_iac_lap);
// PAL: 0x80146558..0x801465b8
UNKNOWN_FUNCTION(btsnd_hcic_read_local_ver);
// PAL: 0x801465b8..0x80146614
UNKNOWN_FUNCTION(btsnd_hcic_read_local_features);
// PAL: 0x80146614..0x8014663c
UNKNOWN_FUNCTION(btsnd_hcic_read_buffer_size);
// PAL: 0x8014663c..0x8014669c
UNKNOWN_FUNCTION(btsnd_hcic_read_bd_addr);
// PAL: 0x8014669c..0x80146718
UNKNOWN_FUNCTION(btsnd_hcic_get_link_quality);
// PAL: 0x80146718..0x80146790
UNKNOWN_FUNCTION(btsnd_hcic_read_rssi);
// PAL: 0x80146790..0x80146bb0
UNKNOWN_FUNCTION(btsnd_hcic_set_afh_channels);
// PAL: 0x80146bb0..0x80146be0
UNKNOWN_FUNCTION(btsnd_hcic_write_inqscan_type);
// PAL: 0x80146be0..0x80146c10
UNKNOWN_FUNCTION(btsnd_hcic_write_inquiry_mode);
// PAL: 0x80146c10..0x80146c40
UNKNOWN_FUNCTION(btsnd_hcic_write_pagescan_type);
// PAL: 0x80146c40..0x80146d34
UNKNOWN_FUNCTION(btsnd_hcic_vendor_spec_cmd);

#ifdef __cplusplus
}
#endif
