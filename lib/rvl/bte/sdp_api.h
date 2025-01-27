#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80156618..0x80156990
UNKNOWN_FUNCTION(SDP_InitDiscoveryDb);
// PAL: 0x80156990..0x801569ec
UNKNOWN_FUNCTION(SDP_ServiceSearchRequest);
// PAL: 0x801569ec..0x80156a50
UNKNOWN_FUNCTION(SDP_ServiceSearchAttributeRequest);
// PAL: 0x80156a50..0x80156a78
UNKNOWN_FUNCTION(SDP_FindAttributeInRec);
// PAL: 0x80156a78..0x80156b44
UNKNOWN_FUNCTION(SDP_FindServiceInDb);
// PAL: 0x80156b44..0x80156c4c
UNKNOWN_FUNCTION(SDP_FindServiceUUIDInDb);
// PAL: 0x80156c4c..0x80156fac
UNKNOWN_FUNCTION(SDP_SetLocalDiRecord);
// PAL: 0x80156fac..0x8015745c
UNKNOWN_FUNCTION(SDP_GetLocalDiRecord);
// PAL: 0x8015745c..0x80157480
UNKNOWN_FUNCTION(SDP_SetTraceLevel);

#ifdef __cplusplus
}
#endif
