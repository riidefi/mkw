#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80137c5c..0x80137c78
UNKNOWN_FUNCTION(btm_acl_init);
// PAL: 0x80137c78..0x80137cfc
UNKNOWN_FUNCTION(btm_handle_to_acl_index);
// PAL: 0x80137cfc..0x80138010
UNKNOWN_FUNCTION(btm_acl_created);
// PAL: 0x80138010..0x801380d4
UNKNOWN_FUNCTION(btm_acl_removed);
// PAL: 0x801380d4..0x80138138
UNKNOWN_FUNCTION(btm_acl_device_down);
// PAL: 0x80138138..0x80138354
UNKNOWN_FUNCTION(BTM_SwitchRole);
// PAL: 0x80138354..0x801384c4
UNKNOWN_FUNCTION(btm_acl_encrypt_change);
// PAL: 0x801384c4..0x801386b4
UNKNOWN_FUNCTION(BTM_SetLinkPolicy);
// PAL: 0x801386b4..0x801386c4
UNKNOWN_FUNCTION(BTM_SetDefaultLinkPolicy);
// PAL: 0x801386c4..0x801387c8
UNKNOWN_FUNCTION(btm_read_link_policy_complete);
// PAL: 0x801387c8..0x80138854
UNKNOWN_FUNCTION(btm_read_remote_version_complete);
// PAL: 0x80138854..0x80138a80
UNKNOWN_FUNCTION(btm_read_remote_features_complete);
// PAL: 0x80138a80..0x80138a90
UNKNOWN_FUNCTION(BTM_SetDefaultLinkSuperTout);
// PAL: 0x80138a90..0x80138b68
UNKNOWN_FUNCTION(BTM_IsAclConnectionUp);
// PAL: 0x80138b68..0x80138bc4
UNKNOWN_FUNCTION(BTM_GetNumAclLinks);
// PAL: 0x80138bc4..0x80138bd4
UNKNOWN_FUNCTION(btm_get_acl_disc_reason_code);
// PAL: 0x80138bd4..0x80138c70
UNKNOWN_FUNCTION(BTM_GetHCIConnHandle);
// PAL: 0x80138c70..0x80138d0c
UNKNOWN_FUNCTION(btm_process_clk_off_comp_evt);
// PAL: 0x80138d0c..0x80138f00
UNKNOWN_FUNCTION(btm_acl_role_changed);
// PAL: 0x80138f00..0x80138f5c
UNKNOWN_FUNCTION(btm_acl_timeout);
// PAL: 0x80138f5c..0x801390fc
UNKNOWN_FUNCTION(btm_get_max_packet_size);
// PAL: 0x801390fc..0x80139140
UNKNOWN_FUNCTION(BTM_AclRegisterForChanges);
// PAL: 0x80139140..0x80139218
UNKNOWN_FUNCTION(btm_qos_setup_complete);
// PAL: 0x80139218..0x80139354
UNKNOWN_FUNCTION(BTM_ReadRSSI);
// PAL: 0x80139354..0x80139490
UNKNOWN_FUNCTION(BTM_ReadLinkQuality);
// PAL: 0x80139490..0x801395ac
UNKNOWN_FUNCTION(btm_read_rssi_complete);
// PAL: 0x801395ac..0x801396c4
UNKNOWN_FUNCTION(btm_read_link_quality_complete);
// PAL: 0x801396c4..0x80139780
UNKNOWN_FUNCTION(btm_remove_acl);
// PAL: 0x80139780..0x801399a0
UNKNOWN_FUNCTION(btm_chg_all_acl_pkt_types);

#ifdef __cplusplus
}
#endif
