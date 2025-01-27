#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80148020..0x80148178
UNKNOWN_FUNCTION(hidh_conn_reg);
// PAL: 0x80148178..0x8014821c
UNKNOWN_FUNCTION(hidh_conn_disconnect);
// PAL: 0x8014821c..0x8014834c
UNKNOWN_FUNCTION(hidh_sec_check_complete_term);
// PAL: 0x8014834c..0x801485a4
UNKNOWN_FUNCTION(hidh_l2cif_connect_ind);
// PAL: 0x801485a4..0x801486f0
UNKNOWN_FUNCTION(hidh_proc_repage_timeout);
// PAL: 0x801486f0..0x80148904
UNKNOWN_FUNCTION(hidh_sec_check_complete_orig);
// PAL: 0x80148904..0x80148c4c
UNKNOWN_FUNCTION(hidh_l2cif_connect_cfm);
// PAL: 0x80148c4c..0x80148ef4
UNKNOWN_FUNCTION(hidh_l2cif_config_ind);
// PAL: 0x80148ef4..0x80149200
UNKNOWN_FUNCTION(hidh_l2cif_config_cfm);
// PAL: 0x80149200..0x801494c4
UNKNOWN_FUNCTION(hidh_l2cif_disconnect_ind);
// PAL: 0x801494c4..0x8014970c
UNKNOWN_FUNCTION(hidh_l2cif_disconnect_cfm);
// PAL: 0x8014970c..0x80149904
UNKNOWN_FUNCTION(hidh_l2cif_cong_ind);
// PAL: 0x80149904..0x80149c9c
UNKNOWN_FUNCTION(hidh_l2cif_data_ind);
// PAL: 0x80149c9c..0x80149f38
UNKNOWN_FUNCTION(hidh_conn_snd_data);
// PAL: 0x80149f38..0x8014a034
UNKNOWN_FUNCTION(hidh_conn_initiate);
// PAL: 0x8014a034..0x8014a060
UNKNOWN_FUNCTION(hidh_conn_dereg);

#ifdef __cplusplus
}
#endif
