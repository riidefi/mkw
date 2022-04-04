#include "eggViewport.hpp"

// Extern function references.
// PAL: 0x802145c0
extern "C" UNKNOWN_FUNCTION(__ct__Q23EGG10BoundBox2fFv);

// Symbol: __ct__Q23EGG8ViewportFv
// PAL: 0x80244074..0x802440b4
MARK_BINARY_BLOB(__ct__Q23EGG8ViewportFv, 0x80244074, 0x802440b4);
asm UNKNOWN_FUNCTION(__ct__Q23EGG8ViewportFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q23EGG10BoundBox2fFv;
  lfs f0, -0x5e88(r2);
  mr r3, r31;
  stfs f0, 0x10(r31);
  stfs f0, 0x14(r31);
  stfs f0, 0x18(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

extern "C" void eggViewport_Calc_TODO();

// Symbol: set__Q23EGG8ViewportFiiii
// PAL: 0x802440b4..0x80244134
MARK_BINARY_BLOB(set__Q23EGG8ViewportFiiii, 0x802440b4, 0x80244134);
asm UNKNOWN_FUNCTION(set__Q23EGG8ViewportFiiii) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r9, 0x4330;
  xoris r8, r4, 0x8000;
  stw r9, 8(r1);
  xoris r5, r5, 0x8000;
  lfd f4, -0x5e80(r2);
  xoris r4, r6, 0x8000;
  stw r8, 0xc(r1);
  lfd f0, 8(r1);
  stw r9, 0x10(r1);
  fsubs f3, f0, f4;
  stw r0, 0x24(r1);
  xoris r0, r7, 0x8000;
  stw r5, 0x14(r1);
  lfd f0, 0x10(r1);
  stw r4, 0xc(r1);
  fsubs f2, f0, f4;
  stw r0, 0x14(r1);
  lfd f1, 8(r1);
  lfd f0, 0x10(r1);
  fsubs f1, f1, f4;
  stfs f3, 0(r3);
  fsubs f0, f0, f4;
  stfs f2, 4(r3);
  stfs f1, 8(r3);
  stfs f0, 0xc(r3);
  bl eggViewport_Calc_TODO;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: eggViewport_Calc_TODO
// PAL: 0x80244134..0x80244160
MARK_BINARY_BLOB(eggViewport_Calc_TODO, 0x80244134, 0x80244160);
asm UNKNOWN_FUNCTION(eggViewport_Calc_TODO) {
  // clang-format off
  nofralloc;
  lfs f3, 8(r3);
  lfs f2, 0(r3);
  lfs f1, 0xc(r3);
  lfs f0, 4(r3);
  fsubs f2, f3, f2;
  fsubs f0, f1, f0;
  stfs f2, 0x10(r3);
  stfs f0, 0x14(r3);
  fdivs f0, f2, f0;
  stfs f0, 0x18(r3);
  blr;
  // clang-format on
}
