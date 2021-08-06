#include "osAlloc.h"

// Symbol: DLInsert
// Function signature is unknown.
// PAL: 0x801a0d9c..0x801a0e48
MARK_BINARY_BLOB(DLInsert, 0x801a0d9c, 0x801a0e48);
asm UNKNOWN_FUNCTION(DLInsert) {
  // clang-format off
  nofralloc;
  mr r7, r3;
  li r6, 0;
  b lbl_801a0db8;
lbl_801a0da8:
  cmplw r4, r7;
  ble lbl_801a0dc0;
  mr r6, r7;
  lwz r7, 4(r7);
lbl_801a0db8:
  cmpwi r7, 0;
  bne lbl_801a0da8;
lbl_801a0dc0:
  cmpwi r7, 0;
  stw r7, 4(r4);
  stw r6, 0(r4);
  beq lbl_801a0e04;
  stw r4, 0(r7);
  lwz r5, 8(r4);
  add r0, r4, r5;
  cmplw r0, r7;
  bne lbl_801a0e04;
  lwz r0, 8(r7);
  add r0, r5, r0;
  stw r0, 8(r4);
  lwz r7, 4(r7);
  cmpwi r7, 0;
  stw r7, 4(r4);
  beq lbl_801a0e04;
  stw r4, 0(r7);
lbl_801a0e04:
  cmpwi r6, 0;
  beq lbl_801a0e40;
  stw r4, 4(r6);
  lwz r5, 8(r6);
  add r0, r6, r5;
  cmplw r0, r4;
  bnelr;
  lwz r0, 8(r4);
  cmpwi r7, 0;
  add r0, r5, r0;
  stw r0, 8(r6);
  stw r7, 4(r6);
  beqlr;
  stw r6, 0(r7);
  blr;
lbl_801a0e40:
  mr r3, r4;
  blr;
  // clang-format on
}

// Symbol: OSAllocFromHeap
// Function signature is unknown.
// PAL: 0x801a0e48..0x801a0f40
MARK_BINARY_BLOB(OSAllocFromHeap, 0x801a0e48, 0x801a0f40);
asm UNKNOWN_FUNCTION(OSAllocFromHeap) {
  // clang-format off
  nofralloc;
  mulli r3, r3, 0xc;
  lwz r5, -0x634c(r13);
  addi r0, r4, 0x3f;
  add r5, r5, r3;
  rlwinm r4, r0, 0, 0, 0x1a;
  lwz r3, 4(r5);
  mr r6, r3;
  b lbl_801a0e78;
lbl_801a0e68:
  lwz r0, 8(r6);
  cmpw r4, r0;
  ble lbl_801a0e80;
  lwz r6, 4(r6);
lbl_801a0e78:
  cmpwi r6, 0;
  bne lbl_801a0e68;
lbl_801a0e80:
  cmpwi r6, 0;
  bne lbl_801a0e90;
  li r3, 0;
  blr;
lbl_801a0e90:
  lwz r0, 8(r6);
  subf r0, r4, r0;
  cmplwi r0, 0x40;
  bge lbl_801a0ed8;
  lwz r4, 4(r6);
  cmpwi r4, 0;
  beq lbl_801a0eb4;
  lwz r0, 0(r6);
  stw r0, 0(r4);
lbl_801a0eb4:
  lwz r4, 0(r6);
  cmpwi r4, 0;
  bne lbl_801a0ec8;
  lwz r3, 4(r6);
  b lbl_801a0ed0;
lbl_801a0ec8:
  lwz r0, 4(r6);
  stw r0, 4(r4);
lbl_801a0ed0:
  stw r3, 4(r5);
  b lbl_801a0f18;
lbl_801a0ed8:
  stw r4, 8(r6);
  add r4, r6, r4;
  stw r0, 8(r4);
  lwz r0, 0(r6);
  stw r0, 0(r4);
  lwz r3, 4(r6);
  cmpwi r3, 0;
  stw r3, 4(r4);
  beq lbl_801a0f00;
  stw r4, 0(r3);
lbl_801a0f00:
  lwz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_801a0f14;
  stw r4, 4(r3);
  b lbl_801a0f18;
lbl_801a0f14:
  stw r4, 4(r5);
lbl_801a0f18:
  lwz r3, 8(r5);
  li r0, 0;
  stw r3, 4(r6);
  cmpwi r3, 0;
  stw r0, 0(r6);
  beq lbl_801a0f34;
  stw r6, 0(r3);
lbl_801a0f34:
  stw r6, 8(r5);
  addi r3, r6, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSFreeToHeap
// Function signature is unknown.
// PAL: 0x801a0f40..0x801a0fb8
MARK_BINARY_BLOB(OSFreeToHeap, 0x801a0f40, 0x801a0fb8);
asm UNKNOWN_FUNCTION(OSFreeToHeap) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  addi r4, r4, -32;
  stw r0, 0x14(r1);
  mulli r0, r3, 0xc;
  stw r31, 0xc(r1);
  lwz r5, -0x634c(r13);
  lwz r6, 4(r4);
  add r31, r5, r0;
  cmpwi r6, 0;
  lwz r3, 8(r31);
  beq lbl_801a0f78;
  lwz r0, 0(r4);
  stw r0, 0(r6);
lbl_801a0f78:
  lwz r5, 0(r4);
  cmpwi r5, 0;
  bne lbl_801a0f8c;
  lwz r3, 4(r4);
  b lbl_801a0f94;
lbl_801a0f8c:
  lwz r0, 4(r4);
  stw r0, 4(r5);
lbl_801a0f94:
  stw r3, 8(r31);
  lwz r3, 4(r31);
  bl DLInsert;
  stw r3, 4(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: set_CurrHeap
// Function signature is unknown.
// PAL: 0x801a0fb8..0x801a0fc8
MARK_BINARY_BLOB(set_CurrHeap, 0x801a0fb8, 0x801a0fc8);
asm UNKNOWN_FUNCTION(set_CurrHeap) {
  // clang-format off
  nofralloc;
  lwz r0, -0x7168(r13);
  stw r3, -0x7168(r13);
  mr r3, r0;
  blr;
  // clang-format on
}

// Symbol: OSInitAlloc
// Function signature is unknown.
// PAL: 0x801a0fc8..0x801a1038
MARK_BINARY_BLOB(OSInitAlloc, 0x801a0fc8, 0x801a1038);
asm UNKNOWN_FUNCTION(OSInitAlloc) {
  // clang-format off
  nofralloc;
  mulli r7, r5, 0xc;
  stw r3, -0x634c(r13);
  li r8, 0;
  stw r5, -0x6350(r13);
  li r6, 0;
  li r5, -1;
  li r3, 0;
  b lbl_801a1004;
lbl_801a0fe8:
  lwz r0, -0x634c(r13);
  addi r8, r8, 1;
  stwx r5, r6, r0;
  add r9, r0, r6;
  addi r6, r6, 0xc;
  stw r3, 8(r9);
  stw r3, 4(r9);
lbl_801a1004:
  lwz r0, -0x6350(r13);
  cmpw r8, r0;
  blt lbl_801a0fe8;
  lwz r3, -0x634c(r13);
  rlwinm r0, r4, 0, 0, 0x1a;
  li r4, -1;
  stw r0, -0x6358(r13);
  add r3, r3, r7;
  addi r0, r3, 0x1f;
  stw r4, -0x7168(r13);
  rlwinm r3, r0, 0, 0, 0x1a;
  stw r3, -0x6354(r13);
  blr;
  // clang-format on
}

// Symbol: OSCreateHeap
// Function signature is unknown.
// PAL: 0x801a1038..0x801a10a4
MARK_BINARY_BLOB(OSCreateHeap, 0x801a1038, 0x801a10a4);
asm UNKNOWN_FUNCTION(OSCreateHeap) {
  // clang-format off
  nofralloc;
  lwz r6, -0x6350(r13);
  addi r0, r3, 0x1f;
  rlwinm r7, r0, 0, 0, 0x1a;
  rlwinm r4, r4, 0, 0, 0x1a;
  lwz r5, -0x634c(r13);
  li r3, 0;
  mtctr r6;
  cmpwi r6, 0;
  ble lbl_801a109c;
lbl_801a105c:
  lwz r0, 0(r5);
  cmpwi r0, 0;
  bge lbl_801a1090;
  subf r0, r7, r4;
  li r4, 0;
  stw r0, 0(r5);
  stw r4, 0(r7);
  stw r4, 4(r7);
  lwz r0, 0(r5);
  stw r0, 8(r7);
  stw r7, 4(r5);
  stw r4, 8(r5);
  blr;
lbl_801a1090:
  addi r5, r5, 0xc;
  addi r3, r3, 1;
  bdnz lbl_801a105c;
lbl_801a109c:
  li r3, -1;
  blr;
  // clang-format on
}
