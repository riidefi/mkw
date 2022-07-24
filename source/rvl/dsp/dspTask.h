#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

extern u32 unk_80386624;
extern u32 unk_80386620;
extern u32 unk_8038661c;
extern u32 unk_80386618;
extern u32 unk_80386614;
extern u32 unk_80386610;

// PAL: 0x8015d688..0x8015dabc
UNKNOWN_FUNCTION(__DSPHandler);
// PAL: 0x8015dabc..0x8015dc60
UNKNOWN_FUNCTION(__DSP_exec_task);
// PAL: 0x8015dc60..0x8015ddec
UNKNOWN_FUNCTION(__DSP_boot_task);
// PAL: 0x8015ddec..0x8015de88
UNKNOWN_FUNCTION(__DSP_insert_task);
// PAL: 0x8015de88..0x8015df1c
UNKNOWN_FUNCTION(__DSP_remove_task);

#ifdef __cplusplus
}
#endif
