#include "gki_time.h"

#include "gki_ppc.h"

// Symbol: gki_timers_init
// PAL: 0x8012fb18..0x8012fbd4
MARK_BINARY_BLOB(gki_timers_init, 0x8012fb18, 0x8012fbd4);
asm UNKNOWN_FUNCTION(gki_timers_init) {
  // clang-format off
  nofralloc;
  lis r3, 0x8031;
  li r0, 0;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  stw r0, -0x77c8(r3);
  stw r0, -0x77c4(r3);
  stw r0, -0x77c0(r3);
  stw r0, -0x77a0(r3);
  stw r0, -0x7780(r3);
  stw r0, -0x7760(r3);
  stw r0, -0x7740(r3);
  stw r0, -0x77bc(r3);
  stw r0, -0x779c(r3);
  stw r0, -0x777c(r3);
  stw r0, -0x775c(r3);
  stw r0, -0x773c(r3);
  stw r0, -0x77b8(r3);
  stw r0, -0x7798(r3);
  stw r0, -0x7778(r3);
  stw r0, -0x7758(r3);
  stw r0, -0x7738(r3);
  stw r0, -0x77b4(r3);
  stw r0, -0x7794(r3);
  stw r0, -0x7774(r3);
  stw r0, -0x7754(r3);
  stw r0, -0x7734(r3);
  stw r0, -0x77b0(r3);
  stw r0, -0x7790(r3);
  stw r0, -0x7770(r3);
  stw r0, -0x7750(r3);
  stw r0, -0x7730(r3);
  stw r0, -0x77ac(r3);
  stw r0, -0x778c(r3);
  stw r0, -0x776c(r3);
  stw r0, -0x774c(r3);
  stw r0, -0x772c(r3);
  stw r0, -0x77a8(r3);
  stw r0, -0x7788(r3);
  stw r0, -0x7768(r3);
  stw r0, -0x7748(r3);
  stw r0, -0x7728(r3);
  stw r0, -0x77a4(r3);
  stw r0, -0x7784(r3);
  stw r0, -0x7764(r3);
  stw r0, -0x7744(r3);
  stw r0, -0x7724(r3);
  blr;
  // clang-format on
}

// Symbol: GKI_get_tick_count
// PAL: 0x8012fbd4..0x8012fbe8
MARK_BINARY_BLOB(GKI_get_tick_count, 0x8012fbd4, 0x8012fbe8);
asm UNKNOWN_FUNCTION(GKI_get_tick_count) {
  // clang-format off
  nofralloc;
  lis r3, 0x8031;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  lwz r3, -0x77d8(r3);
  blr;
  // clang-format on
}

// Symbol: GKI_start_timer
// PAL: 0x8012fbe8..0x8012fd38
MARK_BINARY_BLOB(GKI_start_timer, 0x8012fbe8, 0x8012fd38);
asm UNKNOWN_FUNCTION(GKI_start_timer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r29, r4;
  mr r31, r5;
  bl GKI_get_taskid;
  cmpwi r29, 0;
  mr r28, r3;
  li r30, 0;
  bgt lbl_8012fc20;
  li r29, 1;
lbl_8012fc20:
  neg r0, r31;
  or r0, r0, r31;
  srawi r0, r0, 0x1f;
  and r31, r29, r0;
  bl GKI_disable;
  lis r4, 0x8031;
  lis r3, 0x8000;
  addi r4, r4, -0x6640;
  addis r5, r4, 3;
  addi r4, r3, -1;
  lwz r3, -0x77c8(r5);
  lwz r0, -0x77c4(r5);
  subf r3, r3, r0;
  subf r0, r3, r4;
  cmpw r0, r29;
  ble lbl_8012fc64;
  add r4, r29, r3;
lbl_8012fc64:
  cmpwi r27, 1;
  beq lbl_8012fc9c;
  bge lbl_8012fcbc;
  cmpwi r27, 0;
  bge lbl_8012fc7c;
  b lbl_8012fcbc;
lbl_8012fc7c:
  lis r3, 0x8031;
  rlwinm r5, r28, 2, 0x16, 0x1d;
  addi r3, r3, -0x6640;
  addis r0, r3, 3;
  add r3, r0, r5;
  stw r31, -0x7780(r3);
  stw r4, -0x77a0(r3);
  b lbl_8012fcc0;
lbl_8012fc9c:
  lis r3, 0x8031;
  rlwinm r5, r28, 2, 0x16, 0x1d;
  addi r3, r3, -0x6640;
  addis r0, r3, 3;
  add r3, r0, r5;
  stw r31, -0x7740(r3);
  stw r4, -0x7760(r3);
  b lbl_8012fcc0;
lbl_8012fcbc:
  li r30, 1;
lbl_8012fcc0:
  cmpwi r30, 0;
  bne lbl_8012fd1c;
  cmpwi r29, 0;
  ble lbl_8012fd1c;
  lis r3, 0x8031;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  lwz r4, -0x77c4(r3);
  cmpwi r4, 0;
  beq lbl_8012fcfc;
  lwz r0, -0x77c8(r3);
  cmpw r29, r0;
  bge lbl_8012fd1c;
  cmpwi r0, 0;
  ble lbl_8012fd1c;
lbl_8012fcfc:
  lis r3, 0x8031;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  lwz r0, -0x77c8(r3);
  subf r0, r0, r4;
  add r0, r29, r0;
  stw r0, -0x77c4(r3);
  stw r29, -0x77c8(r3);
lbl_8012fd1c:
  bl GKI_enable;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GKI_stop_timer
// PAL: 0x8012fd38..0x8012fdc0
MARK_BINARY_BLOB(GKI_stop_timer, 0x8012fd38, 0x8012fdc0);
asm UNKNOWN_FUNCTION(GKI_stop_timer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl GKI_get_taskid;
  cmpwi r31, 1;
  beq lbl_8012fd8c;
  bge lbl_8012fdac;
  cmpwi r31, 0;
  bge lbl_8012fd68;
  b lbl_8012fdac;
lbl_8012fd68:
  lis r4, 0x8031;
  rlwinm r3, r3, 2, 0x16, 0x1d;
  addi r4, r4, -0x6640;
  li r5, 0;
  addis r0, r4, 3;
  add r3, r0, r3;
  stw r5, -0x7780(r3);
  stw r5, -0x77a0(r3);
  b lbl_8012fdac;
lbl_8012fd8c:
  lis r4, 0x8031;
  rlwinm r3, r3, 2, 0x16, 0x1d;
  addi r4, r4, -0x6640;
  li r5, 0;
  addis r0, r4, 3;
  add r3, r0, r3;
  stw r5, -0x7740(r3);
  stw r5, -0x7760(r3);
lbl_8012fdac:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_init_timer_list
// PAL: 0x8012fdc0..0x8012fdd4
MARK_BINARY_BLOB(GKI_init_timer_list, 0x8012fdc0, 0x8012fdd4);
asm UNKNOWN_FUNCTION(GKI_init_timer_list) {
  // clang-format off
  nofralloc;
  li r0, 0;
  stw r0, 0(r3);
  stw r0, 4(r3);
  stw r0, 8(r3);
  blr;
  // clang-format on
}

// Symbol: GKI_update_timer_list
// PAL: 0x8012fdd4..0x8012fe60
MARK_BINARY_BLOB(GKI_update_timer_list, 0x8012fdd4, 0x8012fe60);
asm UNKNOWN_FUNCTION(GKI_update_timer_list) {
  // clang-format off
  nofralloc;
  lwz r6, 0(r3);
  li r7, 0;
  b lbl_8012fde8;
lbl_8012fde0:
  lwz r6, 0(r6);
  addi r7, r7, 1;
lbl_8012fde8:
  cmpwi r6, 0;
  beq lbl_8012fdfc;
  lwz r0, 0xc(r6);
  cmpwi r0, 0;
  ble lbl_8012fde0;
lbl_8012fdfc:
  mr r8, r4;
  li r0, 0;
  b lbl_8012fe28;
lbl_8012fe08:
  lwz r9, 0xc(r6);
  subf. r5, r8, r9;
  stw r5, 0xc(r6);
  bgt lbl_8012fe20;
  stw r0, 0xc(r6);
  addi r7, r7, 1;
lbl_8012fe20:
  subf r8, r9, r8;
  lwz r6, 0(r6);
lbl_8012fe28:
  cmpwi r6, 0;
  beq lbl_8012fe38;
  cmpwi r8, 0;
  bgt lbl_8012fe08;
lbl_8012fe38:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  ble lbl_8012fe58;
  subf. r0, r4, r0;
  stw r0, 8(r3);
  bge lbl_8012fe58;
  li r0, 0;
  stw r0, 8(r3);
lbl_8012fe58:
  mr r3, r7;
  blr;
  // clang-format on
}

// Symbol: GKI_add_to_timer_list
// PAL: 0x8012fe60..0x8012ff4c
MARK_BINARY_BLOB(GKI_add_to_timer_list, 0x8012fe60, 0x8012ff4c);
asm UNKNOWN_FUNCTION(GKI_add_to_timer_list) {
  // clang-format off
  nofralloc;
  lwz r5, 0xc(r4);
  cmpwi r5, 0;
  bltlr;
  lwz r0, 8(r3);
  cmpw r5, r0;
  blt lbl_8012fec8;
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8012fe8c;
  stw r4, 0(r3);
  b lbl_8012fea4;
lbl_8012fe8c:
  lwz r5, 4(r3);
  cmpwi r5, 0;
  beq lbl_8012fe9c;
  stw r4, 0(r5);
lbl_8012fe9c:
  lwz r0, 4(r3);
  stw r0, 4(r4);
lbl_8012fea4:
  li r0, 0;
  stw r0, 0(r4);
  stw r4, 4(r3);
  lwz r0, 8(r3);
  lwz r5, 0xc(r4);
  subf r0, r0, r5;
  stw r0, 0xc(r4);
  stw r5, 8(r3);
  b lbl_8012ff40;
lbl_8012fec8:
  lwz r6, 0(r3);
  b lbl_8012fee8;
lbl_8012fed0:
  cmpwi r5, 0;
  ble lbl_8012fee4;
  lwz r0, 0xc(r4);
  subf r0, r5, r0;
  stw r0, 0xc(r4);
lbl_8012fee4:
  lwz r6, 0(r6);
lbl_8012fee8:
  lwz r5, 0xc(r6);
  lwz r0, 0xc(r4);
  cmpw r0, r5;
  bgt lbl_8012fed0;
  lwz r0, 0(r3);
  cmplw r6, r0;
  bne lbl_8012ff18;
  stw r0, 0(r4);
  lwz r5, 0(r3);
  stw r4, 4(r5);
  stw r4, 0(r3);
  b lbl_8012ff30;
lbl_8012ff18:
  lwz r3, 4(r6);
  stw r4, 0(r3);
  lwz r0, 4(r6);
  stw r0, 4(r4);
  stw r4, 4(r6);
  stw r6, 0(r4);
lbl_8012ff30:
  lwz r3, 0xc(r4);
  lwz r0, 0xc(r6);
  subf r0, r3, r0;
  stw r0, 0xc(r6);
lbl_8012ff40:
  li r0, 1;
  stb r0, 0x16(r4);
  blr;
  // clang-format on
}

// Symbol: GKI_remove_from_timer_list
// PAL: 0x8012ff4c..0x80130070
MARK_BINARY_BLOB(GKI_remove_from_timer_list, 0x8012ff4c, 0x80130070);
asm UNKNOWN_FUNCTION(GKI_remove_from_timer_list) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beqlr;
  lbz r0, 0x16(r4);
  cmpwi r0, 0;
  beqlr;
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8012ff70;
  blr;
lbl_8012ff70:
  lwz r6, 0(r4);
  cmpwi r6, 0;
  beq lbl_8012ff90;
  lwz r5, 0xc(r6);
  lwz r0, 0xc(r4);
  add r0, r5, r0;
  stw r0, 0xc(r6);
  b lbl_8012ffa0;
lbl_8012ff90:
  lwz r5, 0xc(r4);
  lwz r0, 8(r3);
  subf r0, r5, r0;
  stw r0, 8(r3);
lbl_8012ffa0:
  lwz r0, 0(r3);
  cmplw r0, r4;
  bne lbl_8012ffdc;
  lwz r5, 0(r4);
  cmpwi r5, 0;
  stw r5, 0(r3);
  beq lbl_8012ffc4;
  li r0, 0;
  stw r0, 4(r5);
lbl_8012ffc4:
  lwz r0, 4(r3);
  cmplw r0, r4;
  bne lbl_80130054;
  li r0, 0;
  stw r0, 4(r3);
  b lbl_80130054;
lbl_8012ffdc:
  lwz r0, 4(r3);
  cmplw r0, r4;
  bne lbl_80130004;
  lwz r5, 4(r4);
  cmpwi r5, 0;
  stw r5, 4(r3);
  beq lbl_80130054;
  li r0, 0;
  stw r0, 0(r5);
  b lbl_80130054;
lbl_80130004:
  lwz r3, 0(r4);
  cmpwi r3, 0;
  beqlr;
  lwz r0, 4(r3);
  cmplw r0, r4;
  bnelr;
  lwz r0, 4(r4);
  stw r0, 4(r3);
  b lbl_8013002c;
  blr;
lbl_8013002c:
  lwz r3, 4(r4);
  cmpwi r3, 0;
  beqlr;
  lwz r0, 0(r3);
  cmplw r0, r4;
  bnelr;
  lwz r0, 0(r4);
  stw r0, 0(r3);
  b lbl_80130054;
  blr;
lbl_80130054:
  li r3, 0;
  lis r0, 0x8000;
  stw r3, 4(r4);
  stw r3, 0(r4);
  stw r0, 0xc(r4);
  stb r3, 0x16(r4);
  blr;
  // clang-format on
}
