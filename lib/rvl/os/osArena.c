#include "osArena.h"

static void* __OSMEM1ArenaHi = (void*)0x00000000;
static void* __OSMEM1ArenaLo = (void*)0xffffffff;
static void* __OSMEM2ArenaHi = (void*)0x00000000;
static void* __OSMEM2ArenaLo = (void*)0xffffffff;

// Symbol: OSGetMEM1ArenaHi
void* OSGetMEM1ArenaHi() { return __OSMEM1ArenaHi; }

// Symbol: OSGetMEM2ArenaHi
void* OSGetMEM2ArenaHi() { return __OSMEM2ArenaHi; }

// Symbol: OSGetArenaHi
void* OSGetArenaHi() { return __OSMEM1ArenaHi; }

// Symbol: OSGetMEM1ArenaLo
void* OSGetMEM1ArenaLo() { return __OSMEM1ArenaLo; }

// Symbol: OSGetMEM2ArenaLo
void* OSGetMEM2ArenaLo() { return __OSMEM2ArenaLo; }

// Symbol: OSGetArenaLo
void* OSGetArenaLo() { return __OSMEM1ArenaLo; }

// Symbol: OSSetMEM1ArenaHi
void OSSetMEM1ArenaHi(void* x) { __OSMEM1ArenaHi = x; }

// Symbol: OSSetMEM2ArenaHi
void OSSetMEM2ArenaHi(void* x) { __OSMEM2ArenaHi = x; }

// Symbol: OSSetArenaHi
void OSSetArenaHi(void* x) { __OSMEM1ArenaHi = x; }

// Symbol: OSSetMEM1ArenaLo
void OSSetMEM1ArenaLo(void* x) { __OSMEM1ArenaLo = x; }

// Symbol: OSSetMEM2ArenaLo
void OSSetMEM2ArenaLo(void* x) { __OSMEM2ArenaLo = x; }

// Symbol: OSSetArenaLo
void OSSetArenaLo(void* x) { __OSMEM1ArenaLo = x; }

// Symbol: OSAllocFromMEM1ArenaLo
void* OSAllocFromMEM1ArenaLo(u32 size, u32 align) {
  void* lo = OSGetMEM1ArenaLo();
  u8* arenaLo = lo = (void*)(((u32)(lo) + (align)-1) & ~((align)-1));
  arenaLo += size;
  arenaLo = (u8*)(((u32)(arenaLo) + (align)-1) & ~((align)-1));
  OSSetMEM1ArenaLo(arenaLo);
  return lo;
}
