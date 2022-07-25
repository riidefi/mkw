#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8014d294..0x8014d3a8
UNKNOWN_FUNCTION(l2c_init);
// PAL: 0x8014d3a8..0x8014d6d8
UNKNOWN_FUNCTION(l2c_rcv_acl_data);
// PAL: 0x8014d6d8..0x8014e148
UNKNOWN_FUNCTION(process_l2cap_cmd);
// PAL: 0x8014e148..0x8014e198
UNKNOWN_FUNCTION(l2c_process_timeout);
// PAL: 0x8014e198..0x8014e2c4
UNKNOWN_FUNCTION(l2c_process_held_packets);

#ifdef __cplusplus
}
#endif
