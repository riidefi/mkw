#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801515d4..0x80151750
UNKNOWN_FUNCTION(port_select_mtu);
// PAL: 0x80151750..0x8015182c
UNKNOWN_FUNCTION(port_release_port);
// PAL: 0x8015182c..0x80151880
UNKNOWN_FUNCTION(port_find_mcb_dlci_port);
// PAL: 0x80151880..0x80151908
UNKNOWN_FUNCTION(port_find_dlci_port);
// PAL: 0x80151908..0x80151978
UNKNOWN_FUNCTION(port_flow_control_user);
// PAL: 0x80151978..0x801519e0
UNKNOWN_FUNCTION(port_get_signal_changes);
// PAL: 0x801519e0..0x80151bac
UNKNOWN_FUNCTION(port_flow_control_peer);

#ifdef __cplusplus
}
#endif
