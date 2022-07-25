#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80143ffc..0x801441d4
UNKNOWN_FUNCTION(btm_cback);
// PAL: 0x801441d4..0x801441e0
UNKNOWN_FUNCTION(gap_btm_cback0);
// PAL: 0x801441e0..0x801441ec
UNKNOWN_FUNCTION(gap_btm_cback1);
// PAL: 0x801441ec..0x80144404
UNKNOWN_FUNCTION(gap_find_addr_name_cb);
// PAL: 0x80144404..0x801445b8
UNKNOWN_FUNCTION(gap_find_addr_inq_cb);
// PAL: 0x801445b8..0x80144618
UNKNOWN_FUNCTION(gap_convert_btm_status);

#ifdef __cplusplus
}
#endif
