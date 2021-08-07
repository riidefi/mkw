#include "osLink.h"

#include <string.h>

#include "osCache.h"
#include "osError.h"

// Symbol: OSNotifyLink
// PAL: 0x801a6d30..0x801a6d34
void OSNotifyLink(OSModuleInfo*) {}

// Symbol: OSNotifyPreLink
// PAL: 0x801a6d34..0x801a6d38
void OSNotifyPreLink(OSModuleInfo*) {}

// Symbol: OSNotifyPostLink
// PAL: 0x801a6d38..0x801a6d3c
void OSNotifyPostLink(OSModuleHeader*, OSModuleHeader*) {}

// Symbol: Relocate
// PAL: 0x801a6d3c..0x801a6ffc
MARK_BINARY_BLOB(Relocate, 0x801a6d3c, 0x801a6ffc);
asm int Relocate(OSModuleHeader*, OSModuleHeader*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  cmpwi r3, 0;
  mr r26, r3;
  mr r27, r4;
  beq lbl_801a6d68;
  lwz r31, 0(r3);
  b lbl_801a6d6c;
lbl_801a6d68:
  li r31, 0;
lbl_801a6d6c:
  lwz r24, 0x28(r4);
  lwz r0, 0x2c(r4);
  add r3, r24, r0;
  addi r0, r3, 7;
  subf r0, r24, r0;
  srwi r0, r0, 3;
  mtctr r0;
  cmplw r24, r3;
  bge lbl_801a6da4;
lbl_801a6d90:
  lwz r0, 0(r24);
  cmplw r0, r31;
  beq lbl_801a6dac;
  addi r24, r24, 8;
  bdnz lbl_801a6d90;
lbl_801a6da4:
  li r3, 0;
  b lbl_801a6fe4;
lbl_801a6dac:
  mr r3, r26;
  mr r4, r27;
  bl OSNotifyPreLink;
  lwz r30, 4(r24);
  li r29, 0;
  lis r25, 0x8029;
  b lbl_801a6fa0;
lbl_801a6dc8:
  lhz r0, 0(r30);
  cmpwi r31, 0;
  add r28, r28, r0;
  beq lbl_801a6df0;
  lbz r0, 3(r30);
  lwz r3, 0x10(r26);
  slwi r0, r0, 3;
  lwzx r0, r3, r0;
  rlwinm r3, r0, 0, 0, 0x1e;
  b lbl_801a6df4;
lbl_801a6df0:
  li r3, 0;
lbl_801a6df4:
  cmpwi r4, 6;
  beq lbl_801a6ebc;
  bge lbl_801a6e2c;
  cmpwi r4, 2;
  beq lbl_801a6e6c;
  bge lbl_801a6e1c;
  cmpwi r4, 0;
  beq lbl_801a6f9c;
  bge lbl_801a6e5c;
  b lbl_801a6f90;
lbl_801a6e1c:
  cmpwi r4, 4;
  beq lbl_801a6e98;
  bge lbl_801a6ea8;
  b lbl_801a6e88;
lbl_801a6e2c:
  cmpwi r4, 0xc9;
  beq lbl_801a6f9c;
  bge lbl_801a6e50;
  cmpwi r4, 0xa;
  beq lbl_801a6ef4;
  blt lbl_801a6ed8;
  cmpwi r4, 0xe;
  bge lbl_801a6f90;
  b lbl_801a6f14;
lbl_801a6e50:
  cmpwi r4, 0xcb;
  bge lbl_801a6f90;
  b lbl_801a6f34;
lbl_801a6e5c:
  lwz r0, 4(r30);
  add r0, r3, r0;
  stw r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6e6c:
  lwz r0, 4(r30);
  lwz r4, 0(r28);
  add r3, r3, r0;
  rlwinm r0, r4, 0, 0x1e, 5;
  rlwimi r0, r3, 0, 6, 0x1d;
  stw r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6e88:
  lwz r0, 4(r30);
  add r0, r3, r0;
  sth r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6e98:
  lwz r0, 4(r30);
  add r0, r3, r0;
  sth r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6ea8:
  lwz r0, 4(r30);
  add r0, r3, r0;
  srwi r0, r0, 0x10;
  sth r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6ebc:
  lwz r0, 4(r30);
  add r0, r3, r0;
  srwi r3, r0, 0x10;
  rlwinm r0, r0, 0x11, 0x1f, 0x1f;
  add r0, r3, r0;
  sth r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6ed8:
  lwz r0, 4(r30);
  lwz r4, 0(r28);
  add r3, r3, r0;
  rlwinm r0, r4, 0, 0x1e, 0xf;
  rlwimi r0, r3, 0, 0x10, 0x1d;
  stw r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6ef4:
  lwz r0, 4(r30);
  lwz r4, 0(r28);
  add r0, r3, r0;
  subf r3, r28, r0;
  rlwinm r0, r4, 0, 0x1e, 5;
  rlwimi r0, r3, 0, 6, 0x1d;
  stw r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6f14:
  lwz r0, 4(r30);
  lwz r4, 0(r28);
  add r0, r3, r0;
  subf r3, r28, r0;
  rlwinm r0, r4, 0, 0x1e, 0xf;
  rlwimi r0, r3, 0, 0x10, 0x1d;
  stw r0, 0(r28);
  b lbl_801a6f9c;
lbl_801a6f34:
  lbz r0, 3(r30);
  cmpwi r29, 0;
  lwz r3, 0x10(r27);
  slwi r0, r0, 3;
  add r23, r3, r0;
  lwzx r0, r3, r0;
  rlwinm r28, r0, 0, 0, 0x1e;
  beq lbl_801a6f74;
  lwz r0, 0(r29);
  lwz r4, 4(r29);
  rlwinm r24, r0, 0, 0, 0x1e;
  mr r3, r24;
  bl DCFlushRange;
  lwz r4, 4(r29);
  mr r3, r24;
  bl ICInvalidateRange;
lbl_801a6f74:
  lwz r0, 0(r23);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801a6f88;
  mr r29, r23;
  b lbl_801a6f9c;
lbl_801a6f88:
  li r29, 0;
  b lbl_801a6f9c;
lbl_801a6f90:
  addi r3, r25, 0x630;
  crclr 6;
  bl OSReport;
lbl_801a6f9c:
  addi r30, r30, 8;
lbl_801a6fa0:
  lbz r4, 2(r30);
  cmplwi r4, 0xcb;
  bne lbl_801a6dc8;
  cmpwi r29, 0;
  beq lbl_801a6fd4;
  lwz r0, 0(r29);
  lwz r4, 4(r29);
  rlwinm r25, r0, 0, 0, 0x1e;
  mr r3, r25;
  bl DCFlushRange;
  lwz r4, 4(r29);
  mr r3, r25;
  bl ICInvalidateRange;
lbl_801a6fd4:
  mr r3, r26;
  mr r4, r27;
  bl OSNotifyPostLink;
  li r3, 1;
lbl_801a6fe4:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: Link
// PAL: 0x801a6ffc..0x801a72dc
MARK_BINARY_BLOB(Link, 0x801a6ffc, 0x801a72dc);
asm int Link(OSModuleInfo* info, void* bss, int fixed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  lwz r6, 0x1c(r3);
  stb r0, 0x33(r3);
  cmplwi r6, 3;
  bgt lbl_801a7078;
  cmplwi r6, 2;
  blt lbl_801a7080;
  lwz r5, 0x40(r3);
  cmpwi r5, 0;
  beq lbl_801a705c;
  divwu r0, r3, r5;
  mullw r0, r0, r5;
  subf. r0, r0, r3;
  bne lbl_801a7078;
lbl_801a705c:
  lwz r5, 0x44(r3);
  cmpwi r5, 0;
  beq lbl_801a7080;
  divwu r0, r4, r5;
  mullw r0, r0, r5;
  subf. r0, r0, r4;
  beq lbl_801a7080;
lbl_801a7078:
  li r3, 0;
  b lbl_801a72bc;
lbl_801a7080:
  lis r5, 0x8000;
  lwz r6, 0x30cc(r5);
  cmpwi r6, 0;
  bne lbl_801a7098;
  stw r3, 0x30c8(r5);
  b lbl_801a709c;
lbl_801a7098:
  stw r3, 4(r6);
lbl_801a709c:
  li r0, 0;
  stw r6, 8(r3);
  lis r5, 0x8000;
  stw r0, 4(r3);
  stw r3, 0x30cc(r5);
  lwz r0, 0x10(r3);
  lwz r6, 0x24(r3);
  add r7, r0, r3;
  lwz r5, 0x28(r3);
  lwz r0, 0x1c(r3);
  add r6, r6, r3;
  add r5, r5, r3;
  stw r7, 0x10(r3);
  cmplwi r0, 3;
  stw r6, 0x24(r3);
  stw r5, 0x28(r3);
  blt lbl_801a70ec;
  lwz r0, 0x48(r3);
  add r0, r0, r3;
  stw r0, 0x48(r3);
lbl_801a70ec:
  li r6, 1;
  li r5, 8;
  b lbl_801a7134;
lbl_801a70f8:
  lwz r0, 0x10(r3);
  add r7, r0, r5;
  lwzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_801a7118;
  add r0, r0, r3;
  stw r0, 0(r7);
  b lbl_801a712c;
lbl_801a7118:
  lwz r0, 4(r7);
  cmpwi r0, 0;
  beq lbl_801a712c;
  stb r6, 0x33(r3);
  stw r4, 0(r7);
lbl_801a712c:
  addi r5, r5, 8;
  addi r6, r6, 1;
lbl_801a7134:
  lwz r0, 0xc(r3);
  cmplw r6, r0;
  blt lbl_801a70f8;
  lwz r5, 0x28(r3);
  b lbl_801a7158;
lbl_801a7148:
  lwz r0, 4(r5);
  add r0, r0, r3;
  stw r0, 4(r5);
  addi r5, r5, 8;
lbl_801a7158:
  lwz r4, 0x28(r3);
  lwz r0, 0x2c(r3);
  add r0, r4, r0;
  cmplw r5, r0;
  blt lbl_801a7148;
  lbz r0, 0x30(r3);
  cmpwi r0, 0;
  beq lbl_801a7194;
  lwz r4, 0x10(r3);
  rlwinm r0, r0, 3, 0x15, 0x1c;
  lwz r5, 0x34(r3);
  lwzx r0, r4, r0;
  rlwinm r0, r0, 0, 0, 0x1e;
  add r0, r5, r0;
  stw r0, 0x34(r3);
lbl_801a7194:
  lbz r0, 0x31(r3);
  cmpwi r0, 0;
  beq lbl_801a71bc;
  lwz r4, 0x10(r3);
  rlwinm r0, r0, 3, 0x15, 0x1c;
  lwz r5, 0x38(r3);
  lwzx r0, r4, r0;
  rlwinm r0, r0, 0, 0, 0x1e;
  add r0, r5, r0;
  stw r0, 0x38(r3);
lbl_801a71bc:
  lbz r0, 0x32(r3);
  cmpwi r0, 0;
  beq lbl_801a71e4;
  lwz r4, 0x10(r3);
  rlwinm r0, r0, 3, 0x15, 0x1c;
  lwz r5, 0x3c(r3);
  lwzx r0, r4, r0;
  rlwinm r0, r0, 0, 0, 0x1e;
  add r0, r5, r0;
  stw r0, 0x3c(r3);
lbl_801a71e4:
  lis r4, 0x8000;
  lwz r4, 0x30d0(r4);
  cmpwi r4, 0;
  beq lbl_801a7200;
  lwz r0, 0x14(r3);
  add r0, r0, r4;
  stw r0, 0x14(r3);
lbl_801a7200:
  mr r4, r29;
  li r3, 0;
  bl Relocate;
  lis r3, 0x8000;
  lwz r28, 0x30c8(r3);
  b lbl_801a723c;
lbl_801a7218:
  mr r3, r29;
  mr r4, r28;
  bl Relocate;
  cmplw r28, r29;
  beq lbl_801a7238;
  mr r3, r28;
  mr r4, r29;
  bl Relocate;
lbl_801a7238:
  lwz r28, 4(r28);
lbl_801a723c:
  cmpwi r28, 0;
  bne lbl_801a7218;
  cmpwi r31, 0;
  beq lbl_801a72a0;
  lwz r4, 0x28(r29);
  lwz r0, 0x2c(r29);
  mr r5, r4;
  add r3, r4, r0;
  addi r0, r3, 7;
  subf r0, r4, r0;
  srwi r0, r0, 3;
  mtctr r0;
  cmplw r4, r3;
  bge lbl_801a72a0;
lbl_801a7274:
  lwz r3, 0(r5);
  cmpwi r3, 0;
  beq lbl_801a728c;
  lwz r0, 0(r29);
  cmplw r3, r0;
  bne lbl_801a7298;
lbl_801a728c:
  subf r0, r4, r5;
  stw r0, 0x2c(r29);
  b lbl_801a72a0;
lbl_801a7298:
  addi r5, r5, 8;
  bdnz lbl_801a7274;
lbl_801a72a0:
  lwz r5, 0x20(r29);
  mr r3, r30;
  li r4, 0;
  bl memset;
  mr r3, r29;
  bl OSNotifyLink;
  li r3, 1;
lbl_801a72bc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSLink
// PAL: 0x801a72dc..0x801a72e4
int OSLink(OSModuleInfo* info, void* bss) { return Link(info, bss, 0); }

OSModuleQueue __OSModuleInfoList : 0x800030c8;
const void* __OSStringTable : 0x800030d0;

// Symbol: __OSModuleInit
// PAL: 0x801a72e4..0x801a72fc
void __OSModuleInit(void) {
  __OSModuleInfoList.head = __OSModuleInfoList.tail = 0;
  __OSStringTable = 0;
}
