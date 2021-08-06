#include "osArena.h"

// Symbol: OSGetMEM1ArenaHi
// Function signature is unknown.
// PAL: 0x801a10a4..0x801a10ac
MARK_BINARY_BLOB(OSGetMEM1ArenaHi, 0x801a10a4, 0x801a10ac);
asm UNKNOWN_FUNCTION(OSGetMEM1ArenaHi) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6348(r13);
  blr;
  // clang-format on
}

// Symbol: OSGetMEM2ArenaHi
// Function signature is unknown.
// PAL: 0x801a10ac..0x801a10b4
MARK_BINARY_BLOB(OSGetMEM2ArenaHi, 0x801a10ac, 0x801a10b4);
asm UNKNOWN_FUNCTION(OSGetMEM2ArenaHi) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6344(r13);
  blr;
  // clang-format on
}

// Symbol: OSGetArenaHi
// Function signature is unknown.
// PAL: 0x801a10b4..0x801a10bc
MARK_BINARY_BLOB(OSGetArenaHi, 0x801a10b4, 0x801a10bc);
asm UNKNOWN_FUNCTION(OSGetArenaHi) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6348(r13);
  blr;
  // clang-format on
}

// Symbol: OSGetMEM1ArenaLo
// Function signature is unknown.
// PAL: 0x801a10bc..0x801a10c4
MARK_BINARY_BLOB(OSGetMEM1ArenaLo, 0x801a10bc, 0x801a10c4);
asm UNKNOWN_FUNCTION(OSGetMEM1ArenaLo) {
  // clang-format off
  nofralloc;
  lwz r3, -0x7160(r13);
  blr;
  // clang-format on
}

// Symbol: OSGetMEM2ArenaLo
// Function signature is unknown.
// PAL: 0x801a10c4..0x801a10cc
MARK_BINARY_BLOB(OSGetMEM2ArenaLo, 0x801a10c4, 0x801a10cc);
asm UNKNOWN_FUNCTION(OSGetMEM2ArenaLo) {
  // clang-format off
  nofralloc;
  lwz r3, -0x715c(r13);
  blr;
  // clang-format on
}

// Symbol: OSGetArenaLo
// Function signature is unknown.
// PAL: 0x801a10cc..0x801a10d4
MARK_BINARY_BLOB(OSGetArenaLo, 0x801a10cc, 0x801a10d4);
asm UNKNOWN_FUNCTION(OSGetArenaLo) {
  // clang-format off
  nofralloc;
  lwz r3, -0x7160(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetArenaHi_0
// Function signature is unknown.
// PAL: 0x801a10d4..0x801a10dc
MARK_BINARY_BLOB(OSSetArenaHi_0, 0x801a10d4, 0x801a10dc);
asm UNKNOWN_FUNCTION(OSSetArenaHi_0) {
  // clang-format off
  nofralloc;
  stw r3, -0x6348(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetMEM2ArenaHi
// Function signature is unknown.
// PAL: 0x801a10dc..0x801a10e4
MARK_BINARY_BLOB(OSSetMEM2ArenaHi, 0x801a10dc, 0x801a10e4);
asm UNKNOWN_FUNCTION(OSSetMEM2ArenaHi) {
  // clang-format off
  nofralloc;
  stw r3, -0x6344(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetArenaHi
// Function signature is unknown.
// PAL: 0x801a10e4..0x801a10ec
MARK_BINARY_BLOB(OSSetArenaHi, 0x801a10e4, 0x801a10ec);
asm UNKNOWN_FUNCTION(OSSetArenaHi) {
  // clang-format off
  nofralloc;
  stw r3, -0x6348(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetArenaLo_0
// Function signature is unknown.
// PAL: 0x801a10ec..0x801a10f4
MARK_BINARY_BLOB(OSSetArenaLo_0, 0x801a10ec, 0x801a10f4);
asm UNKNOWN_FUNCTION(OSSetArenaLo_0) {
  // clang-format off
  nofralloc;
  stw r3, -0x7160(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetMEM2ArenaLo
// Function signature is unknown.
// PAL: 0x801a10f4..0x801a10fc
MARK_BINARY_BLOB(OSSetMEM2ArenaLo, 0x801a10f4, 0x801a10fc);
asm UNKNOWN_FUNCTION(OSSetMEM2ArenaLo) {
  // clang-format off
  nofralloc;
  stw r3, -0x715c(r13);
  blr;
  // clang-format on
}

// Symbol: OSSetArenaLo
// Function signature is unknown.
// PAL: 0x801a10fc..0x801a1104
MARK_BINARY_BLOB(OSSetArenaLo, 0x801a10fc, 0x801a1104);
asm UNKNOWN_FUNCTION(OSSetArenaLo) {
  // clang-format off
  nofralloc;
  stw r3, -0x7160(r13);
  blr;
  // clang-format on
}

// Symbol: OSAllocFromMEM1ArenaLo
// Function signature is unknown.
// PAL: 0x801a1104..0x801a1138
MARK_BINARY_BLOB(OSAllocFromMEM1ArenaLo, 0x801a1104, 0x801a1138);
asm UNKNOWN_FUNCTION(OSAllocFromMEM1ArenaLo) {
  // clang-format off
  nofralloc;
  lwz r0, -0x7160(r13);
  addi r5, r4, -1;
  nor r6, r5, r5;
  add r5, r4, r0;
  addi r0, r5, -1;
  and r0, r6, r0;
  add r3, r0, r3;
  add r4, r3, r4;
  mr r3, r0;
  addi r0, r4, -1;
  and r0, r6, r0;
  stw r0, -0x7160(r13);
  blr;
  // clang-format on
}
