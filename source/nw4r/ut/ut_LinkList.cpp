#include "ut_LinkList.hpp"

// Extern function references.
// PAL: 0x80229e14
extern UNKNOWN_FUNCTION(__dl__FPv);

// Symbol: __dt__Q44nw4r2ut6detail12LinkListImplFv
// PAL: 0x800af210..0x800af2a0
MARK_BINARY_BLOB(__dt__Q44nw4r2ut6detail12LinkListImplFv, 0x800af210,
                 0x800af2a0);
asm UNKNOWN_FUNCTION(__dt__Q44nw4r2ut6detail12LinkListImplFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_800af27c;
  lwz r7, 4(r3);
  addi r6, r3, 4;
  li r0, 0;
  b lbl_800af264;
lbl_800af23c:
  lwz r8, 0(r7);
  lwz r5, 4(r7);
  stw r5, 4(r8);
  stw r8, 0(r5);
  lwz r5, 0(r3);
  addi r5, r5, -1;
  stw r5, 0(r3);
  stw r0, 0(r7);
  stw r0, 4(r7);
  mr r7, r8;
lbl_800af264:
  cmplw r7, r6;
  bne lbl_800af23c;
  cmpwi r4, 0;
  ble lbl_800af27c;
  mr r3, r31;
  bl __dl__FPv;
lbl_800af27c:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol:
// Erase__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8Iterator
// PAL: 0x800af2a0..0x800af2f0
MARK_BINARY_BLOB(
    Erase__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8Iterator,
    0x800af2a0, 0x800af2f0);
asm UNKNOWN_FUNCTION(
    Erase__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8Iterator) {
  // clang-format off
  nofralloc;
  lwz r6, 0(r4);
  li r0, 0;
  lwz r5, 0(r6);
  b lbl_800af2d8;
lbl_800af2b0:
  lwz r7, 0(r6);
  lwz r4, 4(r6);
  stw r4, 4(r7);
  stw r7, 0(r4);
  lwz r4, 0(r3);
  addi r4, r4, -1;
  stw r4, 0(r3);
  stw r0, 0(r6);
  stw r0, 4(r6);
  mr r6, r7;
lbl_800af2d8:
  cmplw r6, r5;
  bne lbl_800af2b0;
  mr r3, r5;
  blr;
  // clang-format on
}

// Symbol: Clear__Q44nw4r2ut6detail12LinkListImplFv
// PAL: 0x800af2f0..0x800af340
MARK_BINARY_BLOB(Clear__Q44nw4r2ut6detail12LinkListImplFv, 0x800af2f0,
                 0x800af340);
asm UNKNOWN_FUNCTION(Clear__Q44nw4r2ut6detail12LinkListImplFv) {
  // clang-format off
  nofralloc;
  lwz r6, 4(r3);
  addi r5, r3, 4;
  li r0, 0;
  b lbl_800af328;
lbl_800af300:
  lwz r7, 0(r6);
  lwz r4, 4(r6);
  stw r4, 4(r7);
  stw r7, 0(r4);
  lwz r4, 0(r3);
  addi r4, r4, -1;
  stw r4, 0(r3);
  stw r0, 0(r6);
  stw r0, 4(r6);
  mr r6, r7;
lbl_800af328:
  cmplw r6, r5;
  bne lbl_800af300;
  blr;
  // clang-format on
}

// Symbol:
// Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode
// PAL: 0x800af340..0x800af370
MARK_BINARY_BLOB(
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode,
    0x800af340, 0x800af370);
asm UNKNOWN_FUNCTION(
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode) {
  // clang-format off
  nofralloc;
  lwz r4, 0(r4);
  lwz r6, 4(r4);
  stw r6, 4(r5);
  stw r4, 0(r5);
  stw r5, 4(r4);
  stw r5, 0(r6);
  lwz r4, 0(r3);
  addi r0, r4, 1;
  stw r0, 0(r3);
  mr r3, r5;
  blr;
  // clang-format on
}

// Symbol: Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode
// PAL: 0x800af370..0x800af3a0
MARK_BINARY_BLOB(
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode,
    0x800af370, 0x800af3a0);
asm UNKNOWN_FUNCTION(
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode) {
  // clang-format off
  nofralloc;
  lwz r6, 0(r4);
  li r0, 0;
  lwz r5, 4(r4);
  stw r5, 4(r6);
  stw r6, 0(r5);
  lwz r5, 0(r3);
  addi r5, r5, -1;
  stw r5, 0(r3);
  mr r3, r6;
  stw r0, 0(r4);
  stw r0, 4(r4);
  blr;
  // clang-format on
}
