#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80130300..0x80130324
UNKNOWN_FUNCTION(hcisu_h2_usb_cback);
// PAL: 0x80130324..0x801306bc
UNKNOWN_FUNCTION(hcisu_h2_receive_msg);
// PAL: 0x801306bc..0x80130868
UNKNOWN_FUNCTION(hcisu_h2_send_msg_now);
// PAL: 0x80130868..0x80130894
UNKNOWN_FUNCTION(hcisu_h2_init);
// PAL: 0x80130894..0x801308fc
UNKNOWN_FUNCTION(hcisu_h2_open);
// PAL: 0x801308fc..0x80130930
UNKNOWN_FUNCTION(hcisu_h2_close);
// PAL: 0x80130930..0x80130960
UNKNOWN_FUNCTION(hcisu_h2_send);
// PAL: 0x80130960..0x8013099c
UNKNOWN_FUNCTION(hcisu_h2_handle_event);

#ifdef __cplusplus
}
#endif
