#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801420ac..0x80142664
UNKNOWN_FUNCTION(btu_hcif_process_event);
// PAL: 0x80142664..0x801427f0
UNKNOWN_FUNCTION(btu_hcif_send_cmd);
// PAL: 0x801427f0..0x801428cc
UNKNOWN_FUNCTION(btu_hcif_connection_comp_evt);
// PAL: 0x801428cc..0x80142958
UNKNOWN_FUNCTION(btu_hcif_connection_request_evt);
// PAL: 0x80142958..0x80142a58
UNKNOWN_FUNCTION(btu_hcif_qos_setup_comp_evt);
// PAL: 0x80142a58..0x80142b38
UNKNOWN_FUNCTION(btu_hcif_esco_connection_comp_evt);
// PAL: 0x80142b38..0x80142c90
UNKNOWN_FUNCTION(btu_hcif_hdl_command_complete);
// PAL: 0x80142c90..0x80142da8
UNKNOWN_FUNCTION(btu_hcif_command_complete_evt);
// PAL: 0x80142da8..0x80142fa8
UNKNOWN_FUNCTION(btu_hcif_hdl_command_status);
// PAL: 0x80142fa8..0x801430d0
UNKNOWN_FUNCTION(btu_hcif_command_status_evt);
// PAL: 0x801430d0..0x80143228
UNKNOWN_FUNCTION(btu_hcif_cmd_timeout);
// PAL: 0x80143228..0x80143308
UNKNOWN_FUNCTION(btu_hcif_link_key_notification_evt);

#ifdef __cplusplus
}
#endif
