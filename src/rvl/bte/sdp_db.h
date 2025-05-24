#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80157480..0x801575bc
UNKNOWN_FUNCTION(sdp_db_service_search);
// PAL: 0x801575bc..0x80157694
UNKNOWN_FUNCTION(find_uuid_in_seq);
// PAL: 0x80157694..0x801576f0
UNKNOWN_FUNCTION(sdp_db_find_record);
// PAL: 0x801576f0..0x80157730
UNKNOWN_FUNCTION(sdp_db_find_attr_in_rec);
// PAL: 0x80157730..0x80157810
UNKNOWN_FUNCTION(SDP_CreateRecord);
// PAL: 0x80157810..0x80157924
UNKNOWN_FUNCTION(SDP_DeleteRecord);
// PAL: 0x80157924..0x80157cbc
UNKNOWN_FUNCTION(SDP_AddAttribute);
// PAL: 0x80157cbc..0x80157d94
UNKNOWN_FUNCTION(SDP_AddUuidSequence);
// PAL: 0x80157d94..0x80157f10
UNKNOWN_FUNCTION(SDP_AddServiceClassIdList);
// PAL: 0x80157f10..0x8015814c
UNKNOWN_FUNCTION(SDP_DeleteAttribute);

#ifdef __cplusplus
}
#endif
