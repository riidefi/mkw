#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801315a0..0x801315c0
UNKNOWN_FUNCTION(bte_hcisu_send);
// PAL: 0x801315c0..0x80131624
UNKNOWN_FUNCTION(bte_hcisu_task);
// PAL: 0x80131624..0x80131648
UNKNOWN_FUNCTION(bte_hcisu_close);
// PAL: 0x80131648..0x80131658
UNKNOWN_FUNCTION(bta_ci_hci_msg_handler);

#ifdef __cplusplus
}
#endif
