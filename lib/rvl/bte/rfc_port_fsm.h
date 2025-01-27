#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80153124..0x801531b4
UNKNOWN_FUNCTION(rfc_port_sm_execute);
// PAL: 0x801531b4..0x80153328
UNKNOWN_FUNCTION(rfc_port_sm_state_closed);
// PAL: 0x80153328..0x801534c4
UNKNOWN_FUNCTION(rfc_port_sm_sabme_wait_ua);
// PAL: 0x801534c4..0x80153680
UNKNOWN_FUNCTION(rfc_port_sm_term_wait_sec_check);
// PAL: 0x80153680..0x801537d0
UNKNOWN_FUNCTION(rfc_port_sm_orig_wait_sec_check);
// PAL: 0x801537d0..0x801539bc
UNKNOWN_FUNCTION(rfc_port_sm_opened);
// PAL: 0x801539bc..0x80153ad8
UNKNOWN_FUNCTION(rfc_port_sm_disc_wait_ua);
// PAL: 0x80153ad8..0x80153bc0
UNKNOWN_FUNCTION(rfc_process_pn);
// PAL: 0x80153bc0..0x80153ecc
UNKNOWN_FUNCTION(rfc_process_rpn);
// PAL: 0x80153ecc..0x80154038
UNKNOWN_FUNCTION(rfc_process_msc);
// PAL: 0x80154038..0x801540c4
UNKNOWN_FUNCTION(rfc_process_rls);
// PAL: 0x801540c4..0x801540c8
UNKNOWN_FUNCTION(rfc_process_nsc);
// PAL: 0x801540c8..0x801540d0
UNKNOWN_FUNCTION(rfc_process_test_rsp);
// PAL: 0x801540d0..0x80154134
UNKNOWN_FUNCTION(rfc_process_fcon);
// PAL: 0x80154134..0x80154198
UNKNOWN_FUNCTION(rfc_process_fcoff);
// PAL: 0x80154198..0x80154220
UNKNOWN_FUNCTION(rfc_process_l2cap_congestion);
// PAL: 0x80154220..0x801542c4
UNKNOWN_FUNCTION(rfc_set_port_state);

#ifdef __cplusplus
}
#endif
