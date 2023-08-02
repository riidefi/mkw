#include "eggXfb.hpp"

// Extern function references.
// PAL: 0x80229e04
extern "C" UNKNOWN_FUNCTION(__nwa__FUlPQ23EGG4Heapi);

// Symbol: __ct__Q23EGG3XfbFPQ23EGG4Heap
// PAL: 0x80244160..0x802441ec
MARK_BINARY_BLOB(__ct__Q23EGG3XfbFPQ23EGG4Heap, 0x80244160, 0x802441ec);
asm UNKNOWN_FUNCTION(__ct__Q23EGG3XfbFPQ23EGG4Heap) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0(r3);
  lhz r4, 8(r3);
  lhz r3, 4(r3);
  sth r3, 0(r30);
  sth r4, 2(r30);
  bl calcXfbSize__Q23EGG3XfbFii;
  cmpwi r31, 0;
  bne lbl_802441b4;
  lwz r31, -0x5d60(r13);
lbl_802441b4:
  mr r4, r31;
  li r5, 0x20;
  bl __nwa__FUlPQ23EGG4Heapi;
  li r0, 0;
  stw r3, 4(r30);
  mr r3, r30;
  stw r0, 0xc(r30);
  stw r0, 8(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

int EGG::Xfb::calcXfbSize(int p1, int p2) {
  return (p1 + 0xfu & 0xfff0) * p2 * 2;
}
