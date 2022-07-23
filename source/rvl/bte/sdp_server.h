#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80159f30..0x8015a084
UNKNOWN_FUNCTION(sdp_server_handle_client_req);
// PAL: 0x8015a084..0x8015a494
UNKNOWN_FUNCTION(process_service_search);
// PAL: 0x8015a494..0x8015a824
UNKNOWN_FUNCTION(process_service_attr_req);
// PAL: 0x8015a824..0x8015ac40
UNKNOWN_FUNCTION(process_service_search_attr_req);

#ifdef __cplusplus
}
#endif
