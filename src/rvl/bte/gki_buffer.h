#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8012e6d4..0x8012e8f4
UNKNOWN_FUNCTION(gki_init_free_queue);
// PAL: 0x8012e8f4..0x8012eba0
UNKNOWN_FUNCTION(gki_buffer_init);
// PAL: 0x8012eba0..0x8012ebb4
UNKNOWN_FUNCTION(GKI_init_q);
// PAL: 0x8012ebb4..0x8012ed54
UNKNOWN_FUNCTION(GKI_getbuf);
// PAL: 0x8012ed54..0x8012ee3c
UNKNOWN_FUNCTION(GKI_getpoolbuf);
// PAL: 0x8012ee3c..0x8012efac
UNKNOWN_FUNCTION(GKI_freebuf);
// PAL: 0x8012efac..0x8012eff0
UNKNOWN_FUNCTION(GKI_get_buf_size);
// PAL: 0x8012eff0..0x8012f1ac
UNKNOWN_FUNCTION(GKI_send_msg);
// PAL: 0x8012f1ac..0x8012f25c
UNKNOWN_FUNCTION(GKI_read_mbox);
// PAL: 0x8012f25c..0x8012f398
UNKNOWN_FUNCTION(GKI_enqueue);
// PAL: 0x8012f398..0x8012f4d8
UNKNOWN_FUNCTION(GKI_enqueue_head);
// PAL: 0x8012f4d8..0x8012f578
UNKNOWN_FUNCTION(GKI_dequeue);
// PAL: 0x8012f578..0x8012f63c
UNKNOWN_FUNCTION(GKI_remove_from_queue);
// PAL: 0x8012f63c..0x8012f644
UNKNOWN_FUNCTION(GKI_getfirst);
// PAL: 0x8012f644..0x8012f660
UNKNOWN_FUNCTION(GKI_getnext);
// PAL: 0x8012f660..0x8012f670
UNKNOWN_FUNCTION(GKI_queue_is_empty);
// PAL: 0x8012f670..0x8012f9b8
UNKNOWN_FUNCTION(GKI_create_pool);
// PAL: 0x8012f9b8..0x8012fb18
UNKNOWN_FUNCTION(GKI_delete_pool);

#ifdef __cplusplus
}
#endif
