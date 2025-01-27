#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013f0e8..0x8013f160
UNKNOWN_FUNCTION(BTM_SecRegister);
// PAL: 0x8013f160..0x8013f1b0
UNKNOWN_FUNCTION(BTM_SecAddRmtNameNotifyCallback);
// PAL: 0x8013f1b0..0x8013f204
UNKNOWN_FUNCTION(BTM_SecDeleteRmtNameNotifyCallback);
// PAL: 0x8013f204..0x8013f2b4
UNKNOWN_FUNCTION(BTM_SetPinType);
// PAL: 0x8013f2b4..0x8013f4dc
UNKNOWN_FUNCTION(BTM_SetSecurityLevel);
// PAL: 0x8013f4dc..0x8013f5a0
UNKNOWN_FUNCTION(BTM_PINCodeReply);
// PAL: 0x8013f5a0..0x8013f77c
UNKNOWN_FUNCTION(BTM_DeviceAuthorized);
// PAL: 0x8013f77c..0x8013fb48
UNKNOWN_FUNCTION(BTM_SecBond);
// PAL: 0x8013fb48..0x8013ffac
UNKNOWN_FUNCTION(btm_sec_l2cap_access_req);
// PAL: 0x8013ffac..0x80140248
UNKNOWN_FUNCTION(btm_sec_mx_access_request);
// PAL: 0x80140248..0x80140374
UNKNOWN_FUNCTION(btm_sec_conn_req);
// PAL: 0x80140374..0x80140390
UNKNOWN_FUNCTION(btm_sec_init);
// PAL: 0x80140390..0x801403d0
UNKNOWN_FUNCTION(btm_sec_dev_reset);
// PAL: 0x801403d0..0x80140484
UNKNOWN_FUNCTION(btm_sec_abort_access_req);
// PAL: 0x80140484..0x8014076c
UNKNOWN_FUNCTION(btm_sec_rmt_name_request_complete);
// PAL: 0x8014076c..0x80140ab0
UNKNOWN_FUNCTION(btm_sec_auth_complete);
// PAL: 0x80140ab0..0x80140bac
UNKNOWN_FUNCTION(btm_sec_mkey_comp_event);
// PAL: 0x80140bac..0x80140ce8
UNKNOWN_FUNCTION(btm_sec_encrypt_change);
// PAL: 0x80140ce8..0x80140d28
UNKNOWN_FUNCTION(btm_sec_is_bonding);
// PAL: 0x80140d28..0x801411a8
UNKNOWN_FUNCTION(btm_sec_connected);
// PAL: 0x801411a8..0x80141264
UNKNOWN_FUNCTION(btm_sec_disconnect);
// PAL: 0x80141264..0x801413a0
UNKNOWN_FUNCTION(btm_sec_disconnected);
// PAL: 0x801413a0..0x8014154c
UNKNOWN_FUNCTION(btm_sec_link_key_notification);
// PAL: 0x8014154c..0x8014167c
UNKNOWN_FUNCTION(btm_sec_link_key_request);
// PAL: 0x8014167c..0x801416f0
UNKNOWN_FUNCTION(btm_sec_pin_code_request_timeout);
// PAL: 0x801416f0..0x80141a4c
UNKNOWN_FUNCTION(btm_sec_pin_code_request);
// PAL: 0x80141a4c..0x80141a9c
UNKNOWN_FUNCTION(btm_sec_update_clock_offset);
// PAL: 0x80141a9c..0x80141e7c
UNKNOWN_FUNCTION(btm_sec_execute_procedure);
// PAL: 0x80141e7c..0x80141f98
UNKNOWN_FUNCTION(btm_sec_start_authorization);
// PAL: 0x80141f98..0x80142078
UNKNOWN_FUNCTION(btm_sec_collision_timeout);
// PAL: 0x80142078..0x801420ac
UNKNOWN_FUNCTION(btm_read_trusted_mask);

#ifdef __cplusplus
}
#endif
