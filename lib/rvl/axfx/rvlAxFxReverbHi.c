#include "fxReverbHi.h"

#include "fxReverbHiExp.h"

// Symbol: AXFXReverbHiInit
// PAL: 0x8012802c..0x80128090
MARK_BINARY_BLOB(AXFXReverbHiInit, 0x8012802c, 0x80128090);
asm UNKNOWN_FUNCTION(AXFXReverbHiInit) {
  // clang-format off
  nofralloc;
  lfs f7, 0x158(r3);
  li r0, 0;
  lfs f2, 0.0f;
  li r4, 5;
  lfs f6, 0x150(r3);
  lfs f5, 0x148(r3);
  lfs f4, 0x154(r3);
  lfs f3, 0x15c(r3);
  lfs f1, 1.0f;
  lfs f0, 0x14c(r3);
  stw r4, 0x110(r3);
  stfs f7, 0x114(r3);
  stfs f7, 0x118(r3);
  stw r0, 0x11c(r3);
  stfs f6, 0x120(r3);
  stfs f5, 0x124(r3);
  stfs f4, 0x128(r3);
  stfs f3, 0x12c(r3);
  stfs f2, 0x130(r3);
  stfs f1, 0x134(r3);
  stw r0, 0x138(r3);
  stw r0, 0x13c(r3);
  stfs f0, 0x140(r3);
  stfs f2, 0x144(r3);
  b AXFXReverbHiExpInit;
  // clang-format on
}

// Symbol: AXFXReverbHiShutdown
// PAL: 0x80128090..0x801280b4
MARK_BINARY_BLOB(AXFXReverbHiShutdown, 0x80128090, 0x801280b4);
asm UNKNOWN_FUNCTION(AXFXReverbHiShutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl AXFXReverbHiExpShutdown;
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXFXReverbHiCallback
// PAL: 0x801280b4..0x801280b8
MARK_BINARY_BLOB(AXFXReverbHiCallback, 0x801280b4, 0x801280b8);
asm UNKNOWN_FUNCTION(AXFXReverbHiCallback) {
  nofralloc;
  b AXFXReverbHiExpCallback;
}
