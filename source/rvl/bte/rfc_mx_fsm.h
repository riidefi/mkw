#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801524e0..0x80152524
UNKNOWN_FUNCTION(rfc_mx_sm_execute);
// PAL: 0x80152524..0x80152738
UNKNOWN_FUNCTION(rfc_mx_sm_state_idle);
// PAL: 0x80152738..0x801528f4
UNKNOWN_FUNCTION(rfc_mx_sm_state_wait_conn_cnf);
// PAL: 0x801528f4..0x80152a1c
UNKNOWN_FUNCTION(rfc_mx_sm_state_configure);
// PAL: 0x80152a1c..0x80152b90
UNKNOWN_FUNCTION(rfc_mx_sm_sabme_wait_ua);
// PAL: 0x80152b90..0x80152cb0
UNKNOWN_FUNCTION(rfc_mx_sm_state_wait_sabme);
// PAL: 0x80152cb0..0x80152dc8
UNKNOWN_FUNCTION(rfc_mx_sm_state_connected);
// PAL: 0x80152dc8..0x80152f40
UNKNOWN_FUNCTION(rfc_mx_sm_state_disc_wait_ua);
// PAL: 0x80152f40..0x80153034
UNKNOWN_FUNCTION(rfc_mx_conf_cnf);
// PAL: 0x80153034..0x80153124
UNKNOWN_FUNCTION(rfc_mx_conf_ind);

#ifdef __cplusplus
}
#endif
