#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a10a4..0x801a10ac
void* OSGetMEM1ArenaHi();
// PAL: 0x801a10ac..0x801a10b4
void* OSGetMEM2ArenaHi();
// PAL: 0x801a10b4..0x801a10bc
void* OSGetArenaHi();
// PAL: 0x801a10bc..0x801a10c4
void* OSGetMEM1ArenaLo();
// PAL: 0x801a10c4..0x801a10cc
void* OSGetMEM2ArenaLo();
// PAL: 0x801a10cc..0x801a10d4
void* OSGetArenaLo();
// PAL: 0x801a10d4..0x801a10dc
void OSSetMEM1ArenaHi(void*);
// PAL: 0x801a10dc..0x801a10e4
void OSSetMEM2ArenaHi(void*);
// PAL: 0x801a10e4..0x801a10ec
void OSSetArenaHi(void*);
// PAL: 0x801a10ec..0x801a10f4
void OSSetMEM1ArenaLo(void*);
// PAL: 0x801a10f4..0x801a10fc
void OSSetMEM2ArenaLo(void*);
// PAL: 0x801a10fc..0x801a1104
void OSSetArenaLo(void*);
// PAL: 0x801a1104..0x801a1138
void* OSAllocFromMEM1ArenaLo(u32 size, u32 align);

#ifdef __cplusplus
}
#endif
