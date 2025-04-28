#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void* OSGetMEM1ArenaHi();
void* OSGetMEM2ArenaHi();
void* OSGetArenaHi();
void* OSGetMEM1ArenaLo();
void* OSGetMEM2ArenaLo();
void* OSGetArenaLo();
void OSSetMEM1ArenaHi(void*);
void OSSetMEM2ArenaHi(void*);
void OSSetArenaHi(void*);
void OSSetMEM1ArenaLo(void*);
void OSSetMEM2ArenaLo(void*);
void OSSetArenaLo(void*);
void* OSAllocFromMEM1ArenaLo(u32 size, u32 align);

#ifdef __cplusplus
}
#endif
