#include "osArena.h"

static void* __OSMEM1ArenaHi = (void*)0x00000000;
static void* __OSMEM1ArenaLo = (void*)0xffffffff;
static void* __OSMEM2ArenaHi = (void*)0x00000000;
static void* __OSMEM2ArenaLo = (void*)0xffffffff;

// Symbol: OSGetMEM1ArenaHi
// PAL: 0x801a10a4..0x801a10ac
void* OSGetMEM1ArenaHi() { return __OSMEM1ArenaHi; }

// Symbol: OSGetMEM2ArenaHi
// PAL: 0x801a10ac..0x801a10b4
void* OSGetMEM2ArenaHi() { return __OSMEM2ArenaHi; }

// Symbol: OSGetArenaHi
// PAL: 0x801a10b4..0x801a10bc
void* OSGetArenaHi() { return __OSMEM1ArenaHi; }

// Symbol: OSGetMEM1ArenaLo
// PAL: 0x801a10bc..0x801a10c4
void* OSGetMEM1ArenaLo() { return __OSMEM1ArenaLo; }

// Symbol: OSGetMEM2ArenaLo
// PAL: 0x801a10c4..0x801a10cc
void* OSGetMEM2ArenaLo() { return __OSMEM2ArenaLo; }

// Symbol: OSGetArenaLo
// PAL: 0x801a10cc..0x801a10d4
void* OSGetArenaLo() { return __OSMEM1ArenaLo; }

// Symbol: OSSetMEM1ArenaHi
// PAL: 0x801a10d4..0x801a10dc
void OSSetMEM1ArenaHi(void* x) { __OSMEM1ArenaHi = x; }

// Symbol: OSSetMEM2ArenaHi
// PAL: 0x801a10dc..0x801a10e4
void OSSetMEM2ArenaHi(void* x) { __OSMEM2ArenaHi = x; }

// Symbol: OSSetArenaHi
// PAL: 0x801a10e4..0x801a10ec
void OSSetArenaHi(void* x) { __OSMEM1ArenaHi = x; }

// Symbol: OSSetMEM1ArenaLo
// PAL: 0x801a10ec..0x801a10f4
void OSSetMEM1ArenaLo(void* x) { __OSMEM1ArenaLo = x; }

// Symbol: OSSetMEM2ArenaLo
// PAL: 0x801a10f4..0x801a10fc
void OSSetMEM2ArenaLo(void* x) { __OSMEM2ArenaLo = x; }

// Symbol: OSSetArenaLo
// PAL: 0x801a10fc..0x801a1104
void OSSetArenaLo(void* x) { __OSMEM1ArenaLo = x; }

// Symbol: OSAllocFromMEM1ArenaLo
// PAL: 0x801a1104..0x801a1138
void* OSAllocFromMEM1ArenaLo(u32 size, u32 align) {
  void* lo = OSGetMEM1ArenaLo();
  u8* arenaLo = lo = (void*)(((u32)(lo) + (align)-1) & ~((align)-1));
  arenaLo += size;
  arenaLo = (u8*)(((u32)(arenaLo) + (align)-1) & ~((align)-1));
  OSSetMEM1ArenaLo(arenaLo);
  return lo;
}
