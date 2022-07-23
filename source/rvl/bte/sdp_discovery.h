#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015814c..0x80158238
UNKNOWN_FUNCTION(sdpu_build_uuid_seq);
// PAL: 0x80158238..0x80158368
UNKNOWN_FUNCTION(sdp_snd_service_search_req);
// PAL: 0x80158368..0x8015839c
UNKNOWN_FUNCTION(sdp_disc_connected);
// PAL: 0x8015839c..0x801584dc
UNKNOWN_FUNCTION(sdp_disc_server_rsp);
// PAL: 0x801584dc..0x80158624
UNKNOWN_FUNCTION(process_service_search_rsp);
// PAL: 0x80158624..0x801588cc
UNKNOWN_FUNCTION(process_service_attr_rsp);
// PAL: 0x801588cc..0x80158ba0
UNKNOWN_FUNCTION(process_service_search_attr_rsp);
// PAL: 0x80158ba0..0x80158d8c
UNKNOWN_FUNCTION(save_attr_seq);
// PAL: 0x80158d8c..0x80158e2c
UNKNOWN_FUNCTION(add_record);
// PAL: 0x80158e2c..0x801593c4
UNKNOWN_FUNCTION(add_attr);

#ifdef __cplusplus
}
#endif
