#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801434c0..0x80143530
UNKNOWN_FUNCTION(gap_conn_init);
// PAL: 0x80143530..0x801436bc
UNKNOWN_FUNCTION(gap_connect_ind);
// PAL: 0x801436bc..0x80143898
UNKNOWN_FUNCTION(gap_connect_cfm);
// PAL: 0x80143898..0x801439d4
UNKNOWN_FUNCTION(gap_config_ind);
// PAL: 0x801439d4..0x80143bc0
UNKNOWN_FUNCTION(gap_config_cfm);
// PAL: 0x80143bc0..0x80143db8
UNKNOWN_FUNCTION(gap_disconnect_ind);
// PAL: 0x80143db8..0x80143ec8
UNKNOWN_FUNCTION(gap_data_ind);
// PAL: 0x80143ec8..0x80143ffc
UNKNOWN_FUNCTION(gap_congestion_ind);

#ifdef __cplusplus
}
#endif
