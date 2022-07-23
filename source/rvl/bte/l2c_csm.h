#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8014ac2c..0x8014ac78
UNKNOWN_FUNCTION(l2c_csm_execute);
// PAL: 0x8014ac78..0x8014af0c
UNKNOWN_FUNCTION(l2c_csm_closed);
// PAL: 0x8014af0c..0x8014b07c
UNKNOWN_FUNCTION(l2c_csm_orig_w4_sec_comp);
// PAL: 0x8014b07c..0x8014b1e4
UNKNOWN_FUNCTION(l2c_csm_term_w4_sec_comp);
// PAL: 0x8014b1e4..0x8014b428
UNKNOWN_FUNCTION(l2c_csm_w4_l2cap_connect_rsp);
// PAL: 0x8014b428..0x8014b600
UNKNOWN_FUNCTION(l2c_csm_w4_l2ca_connect_rsp);
// PAL: 0x8014b600..0x8014b9c8
UNKNOWN_FUNCTION(l2c_csm_config);
// PAL: 0x8014b9c8..0x8014bc24
UNKNOWN_FUNCTION(l2c_csm_open);
// PAL: 0x8014bc24..0x8014be08
UNKNOWN_FUNCTION(l2c_csm_w4_l2cap_disconnect_rsp);
// PAL: 0x8014be08..0x8014bf64
UNKNOWN_FUNCTION(l2c_csm_w4_l2ca_disconnect_rsp);
// PAL: 0x8014bf64..0x8014c108
UNKNOWN_FUNCTION(forward_peer_data);

#ifdef __cplusplus
}
#endif
