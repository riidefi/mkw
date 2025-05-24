#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801593c4..0x80159564
UNKNOWN_FUNCTION(sdp_init);
// PAL: 0x80159564..0x80159628
UNKNOWN_FUNCTION(sdp_connect_ind);
// PAL: 0x80159628..0x801597b8
UNKNOWN_FUNCTION(sdp_connect_cfm);
// PAL: 0x801597b8..0x801598f4
UNKNOWN_FUNCTION(sdp_config_ind);
// PAL: 0x801598f4..0x80159a70
UNKNOWN_FUNCTION(sdp_config_cfm);
// PAL: 0x80159a70..0x80159b68
UNKNOWN_FUNCTION(sdp_disconnect_ind);
// PAL: 0x80159b68..0x80159c3c
UNKNOWN_FUNCTION(sdp_data_ind);
// PAL: 0x80159c3c..0x80159d50
UNKNOWN_FUNCTION(sdp_conn_originate);
// PAL: 0x80159d50..0x80159dec
UNKNOWN_FUNCTION(sdp_disconnect);
// PAL: 0x80159dec..0x80159ea8
UNKNOWN_FUNCTION(sdp_disconnect_cfm);
// PAL: 0x80159ea8..0x80159f30
UNKNOWN_FUNCTION(sdp_conn_timeout);

#ifdef __cplusplus
}
#endif
