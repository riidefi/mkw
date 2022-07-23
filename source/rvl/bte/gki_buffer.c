#include "gki_buffer.h"

#include "gki_ppc.h"

// Symbol: gki_init_free_queue
// PAL: 0x8012e6d4..0x8012e8f4
MARK_BINARY_BLOB(gki_init_free_queue, 0x8012e6d4, 0x8012e8f4);
asm UNKNOWN_FUNCTION(gki_init_free_queue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_18;
  addi r12, r4, 3;
  lis r4, 0x8031;
  rlwinm r9, r12, 0, 0, 0x1d;
  rlwinm r11, r3, 2, 0x16, 0x1d;
  addi r26, r9, 0xc;
  addi r4, r4, -0x6640;
  clrlwi r8, r26, 0x10;
  rlwinm r0, r3, 4, 0x14, 0x1b;
  mullw r7, r8, r5;
  addi r10, r4, 0x54;
  rlwinm r4, r3, 1, 0x17, 0x1e;
  addis r25, r10, 3;
  rlwinm r12, r12, 0, 0x10, 0x1d;
  add r24, r25, r11;
  add r11, r6, r7;
  stw r6, -0x75e4(r24);
  add r7, r25, r4;
  li r4, 0;
  stw r11, -0x75c0(r24);
  add r11, r25, r0;
  cmpwi r5, 0;
  sth r26, -0x759c(r7);
  li r7, 0;
  sth r12, -0x766c(r11);
  sth r5, -0x766a(r11);
  sth r4, -0x7668(r11);
  sth r4, -0x7666(r11);
  stw r6, -0x7674(r11);
  beq lbl_8012e8c8;
  cmplwi r5, 8;
  addis r11, r5, 1;
  addi r11, r11, -8;
  ble lbl_8012e87c;
  clrlwi r12, r11, 0x10;
  lis r27, 0xddbb;
  addi r11, r12, 7;
  li r24, 0xf0;
  srwi r11, r11, 3;
  addi r26, r27, -0x2246;
  li r25, 0;
  mtctr r11;
  cmplwi r12, 0;
  ble lbl_8012e87c;
lbl_8012e794:
  stb r24, 5(r6);
  add r18, r6, r8;
  add r19, r18, r8;
  add r4, r6, r9;
  stb r3, 4(r6);
  add r20, r19, r8;
  add r21, r20, r8;
  add r27, r18, r9;
  stb r25, 6(r6);
  add r22, r21, r8;
  add r23, r22, r8;
  add r28, r19, r9;
  stw r26, 8(r4);
  add r4, r23, r8;
  add r31, r20, r9;
  add r30, r21, r9;
  stw r18, 0(r6);
  add r29, r22, r9;
  add r12, r23, r9;
  add r11, r4, r9;
  stb r24, 5(r18);
  add r6, r4, r8;
  addi r7, r7, 8;
  stb r3, 4(r18);
  stb r25, 6(r18);
  stw r26, 8(r27);
  stw r19, 0(r18);
  stb r24, 5(r19);
  stb r3, 4(r19);
  stb r25, 6(r19);
  stw r26, 8(r28);
  stwx r20, r18, r8;
  stb r24, 5(r20);
  stb r3, 4(r20);
  stb r25, 6(r20);
  stw r26, 8(r31);
  stwx r21, r19, r8;
  stb r24, 5(r21);
  stb r3, 4(r21);
  stb r25, 6(r21);
  stw r26, 8(r30);
  stwx r22, r20, r8;
  stb r24, 5(r22);
  stb r3, 4(r22);
  stb r25, 6(r22);
  stw r26, 8(r29);
  stwx r23, r21, r8;
  stb r24, 5(r23);
  stb r3, 4(r23);
  stb r25, 6(r23);
  stw r26, 8(r12);
  stwx r4, r22, r8;
  stb r24, 5(r4);
  stb r3, 4(r4);
  stb r25, 6(r4);
  stw r26, 8(r11);
  stwx r6, r23, r8;
  bdnz lbl_8012e794;
lbl_8012e87c:
  clrlwi r12, r7, 0x10;
  lis r31, 0xddbb;
  subf r11, r12, r5;
  li r29, 0xf0;
  addi r31, r31, -0x2246;
  li r30, 0;
  mtctr r11;
  cmplw r12, r5;
  bge lbl_8012e8c8;
lbl_8012e8a0:
  stb r29, 5(r6);
  add r5, r6, r9;
  mr r4, r6;
  addi r7, r7, 1;
  stb r3, 4(r6);
  stb r30, 6(r6);
  add r6, r6, r8;
  stw r31, 8(r5);
  stw r6, 0(r4);
  bdnz lbl_8012e8a0;
lbl_8012e8c8:
  li r5, 0;
  addis r3, r10, 3;
  stw r5, 0(r4);
  add r3, r3, r0;
  addi r11, r1, 0x40;
  stw r4, -0x7670(r3);
  bl _restgpr_18;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: gki_buffer_init
// PAL: 0x8012e8f4..0x8012eba0
MARK_BINARY_BLOB(gki_buffer_init, 0x8012e8f4, 0x8012eba0);
asm UNKNOWN_FUNCTION(gki_buffer_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8031;
  li r6, 0;
  stw r0, 0x14(r1);
  li r0, 2;
  addi r3, r3, -0x6640;
  li r4, 0;
  stw r31, 0xc(r1);
  addi r31, r3, 0x54;
  mtctr r0;
lbl_8012e920:
  rlwinm r0, r6, 4, 0x14, 0x1b;
  addi r6, r6, 1;
  add r5, r31, r0;
  addis r3, r5, 3;
  rlwinm r0, r6, 4, 0x14, 0x1b;
  stw r4, -0x7774(r3);
  add r5, r31, r0;
  addi r6, r6, 1;
  stw r4, -0x76f4(r3);
  rlwinm r0, r6, 4, 0x14, 0x1b;
  addi r6, r6, 1;
  stw r4, -0x7770(r3);
  stw r4, -0x76f0(r3);
  stw r4, -0x776c(r3);
  stw r4, -0x76ec(r3);
  stw r4, -0x7768(r3);
  stw r4, -0x76e8(r3);
  addis r3, r5, 3;
  add r5, r31, r0;
  rlwinm r0, r6, 4, 0x14, 0x1b;
  stw r4, -0x7774(r3);
  addi r6, r6, 1;
  stw r4, -0x76f4(r3);
  stw r4, -0x7770(r3);
  stw r4, -0x76f0(r3);
  stw r4, -0x776c(r3);
  stw r4, -0x76ec(r3);
  stw r4, -0x7768(r3);
  stw r4, -0x76e8(r3);
  addis r3, r5, 3;
  add r5, r31, r0;
  stw r4, -0x7774(r3);
  stw r4, -0x76f4(r3);
  stw r4, -0x7770(r3);
  stw r4, -0x76f0(r3);
  stw r4, -0x776c(r3);
  stw r4, -0x76ec(r3);
  stw r4, -0x7768(r3);
  stw r4, -0x76e8(r3);
  addis r3, r5, 3;
  stw r4, -0x7774(r3);
  stw r4, -0x76f4(r3);
  stw r4, -0x7770(r3);
  stw r4, -0x76f0(r3);
  stw r4, -0x776c(r3);
  stw r4, -0x76ec(r3);
  stw r4, -0x7768(r3);
  stw r4, -0x76e8(r3);
  bdnz lbl_8012e920;
  li r0, 3;
  li r10, 0;
  li r7, 0;
  mtctr r0;
lbl_8012e9f4:
  rlwinm r0, r10, 2, 0x16, 0x1d;
  rlwinm r4, r10, 1, 0x17, 0x1e;
  add r8, r31, r0;
  addis r6, r8, 3;
  rlwinm r0, r10, 4, 0x14, 0x1b;
  stw r7, -0x75e4(r6);
  addis r4, r4, 3;
  add r9, r31, r0;
  addi r10, r10, 1;
  stw r7, -0x75c0(r6);
  addi r5, r4, -0x759c;
  rlwinm r0, r10, 2, 0x16, 0x1d;
  rlwinm r4, r10, 1, 0x17, 0x1e;
  sthx r7, r31, r5;
  add r8, r31, r0;
  addis r3, r9, 3;
  rlwinm r0, r10, 4, 0x14, 0x1b;
  stw r7, -0x7674(r3);
  addis r4, r4, 3;
  addis r6, r8, 3;
  add r9, r31, r0;
  stw r7, -0x7670(r3);
  addi r10, r10, 1;
  addi r5, r4, -0x759c;
  sth r7, -0x766c(r3);
  rlwinm r0, r10, 2, 0x16, 0x1d;
  add r8, r31, r0;
  rlwinm r4, r10, 1, 0x17, 0x1e;
  sth r7, -0x766a(r3);
  rlwinm r0, r10, 4, 0x14, 0x1b;
  addis r4, r4, 3;
  addi r10, r10, 1;
  sth r7, -0x7668(r3);
  sth r7, -0x7666(r3);
  addis r3, r9, 3;
  add r9, r31, r0;
  stw r7, -0x75e4(r6);
  stw r7, -0x75c0(r6);
  addis r6, r8, 3;
  sthx r7, r31, r5;
  addi r5, r4, -0x759c;
  stw r7, -0x7674(r3);
  stw r7, -0x7670(r3);
  sth r7, -0x766c(r3);
  sth r7, -0x766a(r3);
  sth r7, -0x7668(r3);
  sth r7, -0x7666(r3);
  addis r3, r9, 3;
  stw r7, -0x75e4(r6);
  stw r7, -0x75c0(r6);
  sthx r7, r31, r5;
  stw r7, -0x7674(r3);
  stw r7, -0x7670(r3);
  sth r7, -0x766c(r3);
  sth r7, -0x766a(r3);
  sth r7, -0x7668(r3);
  sth r7, -0x7666(r3);
  bdnz lbl_8012e9f4;
  lis r4, 0x1;
  addis r3, r31, 3;
  addi r0, r4, -0x10;
  mr r6, r31;
  sth r0, -0x7584(r3);
  li r3, 0;
  li r4, 0x40;
  li r5, 0x30;
  bl gki_init_free_queue;
  addi r6, r31, 0xe40;
  li r3, 1;
  li r4, 0x80;
  li r5, 0x1a;
  bl gki_init_free_queue;
  addi r6, r31, 0x1c78;
  li r3, 2;
  li r4, 0x294;
  li r5, 0x2d;
  bl gki_init_free_queue;
  addis r6, r31, 1;
  li r3, 3;
  li r4, 0x708;
  li r5, 0x1e;
  addi r6, r6, -0x6d68;
  bl gki_init_free_queue;
  addis r6, r31, 1;
  li r3, 4;
  li r4, 0x2000;
  li r5, 9;
  addi r6, r6, 0x66f0;
  bl gki_init_free_queue;
  addis r6, r31, 3;
  li r0, 0;
  stb r0, -0x7582(r6);
  li r0, 1;
  li r5, 2;
  li r4, 3;
  stb r0, -0x7581(r6);
  li r3, 4;
  li r0, 5;
  stb r5, -0x7580(r6);
  stb r4, -0x757f(r6);
  stb r3, -0x757e(r6);
  stb r0, -0x7579(r6);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_init_q
// PAL: 0x8012eba0..0x8012ebb4
MARK_BINARY_BLOB(GKI_init_q, 0x8012eba0, 0x8012ebb4);
asm UNKNOWN_FUNCTION(GKI_init_q) {
  // clang-format off
  nofralloc;
  li r0, 0;
  stw r0, 4(r3);
  stw r0, 0(r3);
  sth r0, 8(r3);
  blr;
  // clang-format on
}

// Symbol: GKI_getbuf
// PAL: 0x8012ebb4..0x8012ed54
MARK_BINARY_BLOB(GKI_getbuf, 0x8012ebb4, 0x8012ed54);
asm UNKNOWN_FUNCTION(GKI_getbuf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8031;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  addi r4, r4, -0x6640;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  addi r30, r4, 0x54;
  bne lbl_8012ebfc;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -0xa;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x26d8;
  bl GKI_exception;
  li r3, 0;
  b lbl_8012ed3c;
lbl_8012ebfc:
  addis r4, r30, 3;
  li r31, 0;
  lbz r5, -0x7579(r4);
  b lbl_8012ec38;
lbl_8012ec0c:
  clrlwi r4, r31, 0x18;
  addis r4, r4, 3;
  addi r0, r4, -0x7582;
  lbzx r0, r30, r0;
  slwi r4, r0, 4;
  addis r4, r4, 3;
  addi r0, r4, -0x766c;
  lhzx r0, r30, r0;
  cmplw r3, r0;
  ble lbl_8012ec44;
  addi r31, r31, 1;
lbl_8012ec38:
  clrlwi r0, r31, 0x18;
  cmplw r0, r5;
  blt lbl_8012ec0c;
lbl_8012ec44:
  clrlwi r0, r31, 0x18;
  cmplw r0, r5;
  bne lbl_8012ec70;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -9;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x26f0;
  bl GKI_exception;
  li r3, 0;
  b lbl_8012ed3c;
lbl_8012ec70:
  bl GKI_disable;
  addis r6, r30, 3;
  li r5, 1;
  lbz r7, -0x7579(r6);
  b lbl_8012ed28;
lbl_8012ec84:
  clrlwi r4, r31, 0x18;
  lhz r3, -0x7584(r6);
  addis r4, r4, 3;
  addi r0, r4, -0x7582;
  lbzx r4, r30, r0;
  slw r0, r5, r4;
  and. r0, r3, r0;
  bne lbl_8012ed24;
  rlwinm r0, r4, 4, 0x14, 0x1b;
  add r4, r6, r0;
  lhz r3, -0x7668(r4);
  lhz r0, -0x766a(r4);
  cmplw r3, r0;
  bge lbl_8012ed24;
  lwz r30, -0x7674(r4);
  lwz r0, 0(r30);
  cmpwi r0, 0;
  stw r0, -0x7674(r4);
  bne lbl_8012ecd8;
  li r0, 0;
  stw r0, -0x7670(r4);
lbl_8012ecd8:
  lhz r3, -0x7668(r4);
  addi r0, r3, 1;
  sth r0, -0x7668(r4);
  clrlwi r3, r0, 0x10;
  lhz r0, -0x7666(r4);
  cmplw r3, r0;
  ble lbl_8012ecfc;
  lhz r0, -0x7668(r4);
  sth r0, -0x7666(r4);
lbl_8012ecfc:
  bl GKI_enable;
  bl GKI_get_taskid;
  stb r3, 5(r30);
  li r4, 1;
  li r0, 0;
  addi r3, r30, 8;
  stb r4, 6(r30);
  stw r0, 0(r30);
  stb r0, 7(r30);
  b lbl_8012ed3c;
lbl_8012ed24:
  addi r31, r31, 1;
lbl_8012ed28:
  clrlwi r0, r31, 0x18;
  cmplw r0, r7;
  blt lbl_8012ec84;
  bl GKI_enable;
  li r3, 0;
lbl_8012ed3c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_getpoolbuf
// PAL: 0x8012ed54..0x8012ee3c
MARK_BINARY_BLOB(GKI_getpoolbuf, 0x8012ed54, 0x8012ee3c);
asm UNKNOWN_FUNCTION(GKI_getpoolbuf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8031;
  cmplwi r3, 9;
  stw r0, 0x14(r1);
  addi r4, r4, -0x6640;
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  addi r30, r4, 0x54;
  blt lbl_8012ed88;
  li r3, 0;
  b lbl_8012ee24;
lbl_8012ed88:
  bl GKI_disable;
  rlwinm r31, r31, 4, 0x14, 0x1b;
  addis r0, r30, 3;
  add r4, r0, r31;
  lhz r3, -0x7668(r4);
  lhz r0, -0x766a(r4);
  cmplw r3, r0;
  bge lbl_8012ee10;
  lwz r31, -0x7674(r4);
  lwz r0, 0(r31);
  cmpwi r0, 0;
  stw r0, -0x7674(r4);
  bne lbl_8012edc4;
  li r0, 0;
  stw r0, -0x7670(r4);
lbl_8012edc4:
  lhz r3, -0x7668(r4);
  addi r0, r3, 1;
  sth r0, -0x7668(r4);
  clrlwi r3, r0, 0x10;
  lhz r0, -0x7666(r4);
  cmplw r3, r0;
  ble lbl_8012ede8;
  lhz r0, -0x7668(r4);
  sth r0, -0x7666(r4);
lbl_8012ede8:
  bl GKI_enable;
  bl GKI_get_taskid;
  stb r3, 5(r31);
  li r4, 1;
  li r0, 0;
  addi r3, r31, 8;
  stb r4, 6(r31);
  stw r0, 0(r31);
  stb r0, 7(r31);
  b lbl_8012ee24;
lbl_8012ee10:
  bl GKI_enable;
  addis r0, r30, 3;
  add r3, r0, r31;
  lhz r3, -0x766c(r3);
  bl GKI_getbuf;
lbl_8012ee24:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_freebuf
// PAL: 0x8012ee3c..0x8012efac
MARK_BINARY_BLOB(GKI_freebuf, 0x8012ee3c, 0x8012efac);
asm UNKNOWN_FUNCTION(GKI_freebuf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8028;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  addi r5, r5, 0x26d8;
  stw r31, 0xc(r1);
  beq lbl_8012eed4;
  addi r31, r3, -8;
  clrlwi. r0, r31, 0x1f;
  beq lbl_8012ee70;
  li r0, 0;
  b lbl_8012ee9c;
lbl_8012ee70:
  lbz r0, 4(r31);
  cmplwi r0, 9;
  bge lbl_8012ee98;
  lis r4, 0x8031;
  rlwinm r0, r0, 4, 0x14, 0x1b;
  addi r4, r4, -0x6640;
  addis r4, r4, 3;
  add r4, r4, r0;
  lhz r0, -0x7618(r4);
  b lbl_8012ee9c;
lbl_8012ee98:
  li r0, 0;
lbl_8012ee9c:
  add r4, r3, r0;
  clrlwi. r0, r4, 0x1f;
  beq lbl_8012eeb0;
  li r0, 1;
  b lbl_8012eecc;
lbl_8012eeb0:
  lis r3, 0xddbb;
  lwz r4, 0(r4);
  addi r0, r3, -0x2246;
  subf r3, r4, r0;
  subf r0, r0, r4;
  or r0, r3, r0;
  srwi r0, r0, 0x1f;
lbl_8012eecc:
  clrlwi. r0, r0, 0x18;
  beq lbl_8012eeec;
lbl_8012eed4:
  lis r3, 0x1;
  addi r4, r5, 0x30;
  addi r0, r3, -1;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  b lbl_8012ef98;
lbl_8012eeec:
  lbz r0, 6(r31);
  cmplwi r0, 1;
  beq lbl_8012ef10;
  lis r3, 0x1;
  addi r4, r5, 0x48;
  addi r0, r3, -4;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  b lbl_8012ef98;
lbl_8012ef10:
  lbz r0, 4(r31);
  cmplwi r0, 9;
  blt lbl_8012ef34;
  lis r3, 0x1;
  addi r4, r5, 0x5c;
  addi r0, r3, -3;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  b lbl_8012ef98;
lbl_8012ef34:
  bl GKI_disable;
  lbz r0, 4(r31);
  lis r3, 0x8031;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  slwi r0, r0, 4;
  add r4, r3, r0;
  lwz r3, -0x761c(r4);
  cmpwi r3, 0;
  beq lbl_8012ef64;
  stw r31, 0(r3);
  b lbl_8012ef68;
lbl_8012ef64:
  stw r31, -0x7620(r4);
lbl_8012ef68:
  stw r31, -0x761c(r4);
  li r3, 0;
  li r0, 0xf0;
  stw r3, 0(r31);
  stb r3, 6(r31);
  stb r0, 5(r31);
  lhz r3, -0x7614(r4);
  cmpwi r3, 0;
  beq lbl_8012ef94;
  addi r0, r3, -1;
  sth r0, -0x7614(r4);
lbl_8012ef94:
  bl GKI_enable;
lbl_8012ef98:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_get_buf_size
// PAL: 0x8012efac..0x8012eff0
MARK_BINARY_BLOB(GKI_get_buf_size, 0x8012efac, 0x8012eff0);
asm UNKNOWN_FUNCTION(GKI_get_buf_size) {
  // clang-format off
  nofralloc;
  addi r3, r3, -8;
  clrlwi. r0, r3, 0x1f;
  beq lbl_8012efc0;
  li r3, 0;
  blr;
lbl_8012efc0:
  lbz r0, 4(r3);
  cmplwi r0, 9;
  bge lbl_8012efe8;
  lis r3, 0x8031;
  rlwinm r0, r0, 4, 0x14, 0x1b;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  add r3, r3, r0;
  lhz r3, -0x7618(r3);
  blr;
lbl_8012efe8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: GKI_send_msg
// PAL: 0x8012eff0..0x8012f1ac
MARK_BINARY_BLOB(GKI_send_msg, 0x8012eff0, 0x8012f1ac);
asm UNKNOWN_FUNCTION(GKI_send_msg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8031;
  lis r6, 0x8028;
  stw r0, 0x24(r1);
  cmplwi r3, 8;
  addi r7, r7, -0x6640;
  addi r6, r6, 0x26d8;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  addi r30, r7, 0x54;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bge lbl_8012f050;
  cmplwi r4, 4;
  bge lbl_8012f050;
  addis r0, r30, 3;
  add r3, r0, r3;
  lbz r0, -0x7854(r3);
  cmpwi r0, 0;
  bne lbl_8012f070;
lbl_8012f050:
  lis r3, 0x1;
  addi r4, r6, 0x68;
  addi r0, r3, -5;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_8012f18c;
lbl_8012f070:
  addi r31, r5, -8;
  clrlwi. r0, r31, 0x1f;
  beq lbl_8012f084;
  li r0, 0;
  b lbl_8012f0a8;
lbl_8012f084:
  lbz r0, 4(r31);
  cmplwi r0, 9;
  bge lbl_8012f0a4;
  addis r3, r7, 3;
  rlwinm r0, r0, 4, 0x14, 0x1b;
  add r3, r3, r0;
  lhz r0, -0x7618(r3);
  b lbl_8012f0a8;
lbl_8012f0a4:
  li r0, 0;
lbl_8012f0a8:
  add r4, r5, r0;
  clrlwi. r0, r4, 0x1f;
  beq lbl_8012f0bc;
  li r0, 1;
  b lbl_8012f0d8;
lbl_8012f0bc:
  lis r3, 0xddbb;
  lwz r4, 0(r4);
  addi r0, r3, -0x2246;
  subf r3, r4, r0;
  subf r0, r0, r4;
  or r0, r3, r0;
  srwi r0, r0, 0x1f;
lbl_8012f0d8:
  clrlwi. r0, r0, 0x18;
  beq lbl_8012f0f8;
  lis r3, 0x1;
  addi r4, r6, 0x80;
  addi r0, r3, -1;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  b lbl_8012f18c;
lbl_8012f0f8:
  lbz r0, 6(r31);
  cmplwi r0, 1;
  beq lbl_8012f11c;
  lis r3, 0x1;
  addi r4, r6, 0x98;
  addi r0, r3, -6;
  clrlwi r3, r0, 0x10;
  bl GKI_exception;
  b lbl_8012f18c;
lbl_8012f11c:
  bl GKI_disable;
  rlwinm r4, r28, 4, 0x14, 0x1b;
  addis r0, r30, 3;
  rlwinm r5, r29, 2, 0x16, 0x1d;
  add r0, r0, r4;
  add r3, r0, r5;
  lwz r0, -0x7774(r3);
  cmpwi r0, 0;
  beq lbl_8012f14c;
  lwz r3, -0x76f4(r3);
  stw r31, 0(r3);
  b lbl_8012f150;
lbl_8012f14c:
  stw r31, -0x7774(r3);
lbl_8012f150:
  addis r0, r30, 3;
  li r3, 0;
  add r4, r0, r4;
  add r4, r4, r5;
  li r0, 2;
  stw r31, -0x76f4(r4);
  stw r3, 0(r31);
  stb r0, 6(r31);
  stb r28, 5(r31);
  bl GKI_enable;
  li r0, 1;
  mr r3, r28;
  slw r0, r0, r29;
  clrlwi r4, r0, 0x10;
  bl GKI_send_event;
lbl_8012f18c:
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

// Symbol: GKI_read_mbox
// PAL: 0x8012f1ac..0x8012f25c
MARK_BINARY_BLOB(GKI_read_mbox, 0x8012f1ac, 0x8012f25c);
asm UNKNOWN_FUNCTION(GKI_read_mbox) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl GKI_get_taskid;
  clrlwi r0, r3, 0x18;
  mr r31, r3;
  cmplwi r0, 8;
  li r30, 0;
  bge lbl_8012f1e8;
  cmplwi r29, 4;
  blt lbl_8012f1f0;
lbl_8012f1e8:
  li r3, 0;
  b lbl_8012f240;
lbl_8012f1f0:
  bl GKI_disable;
  lis r3, 0x8031;
  rlwinm r4, r31, 4, 0x14, 0x1b;
  addi r3, r3, -0x6640;
  rlwinm r6, r29, 2, 0x16, 0x1d;
  addis r0, r3, 3;
  add r3, r0, r4;
  addi r7, r3, -0x7720;
  lwzx r5, r7, r6;
  cmpwi r5, 0;
  beq lbl_8012f238;
  lwz r4, 0(r5);
  li r3, 0;
  li r0, 1;
  addi r30, r5, 8;
  stwx r4, r7, r6;
  stw r3, 0(r5);
  stb r0, 6(r5);
lbl_8012f238:
  bl GKI_enable;
  mr r3, r30;
lbl_8012f240:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GKI_enqueue
// PAL: 0x8012f25c..0x8012f398
MARK_BINARY_BLOB(GKI_enqueue, 0x8012f25c, 0x8012f398);
asm UNKNOWN_FUNCTION(GKI_enqueue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  addi r31, r4, -8;
  clrlwi. r0, r31, 0x1f;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  beq lbl_8012f290;
  li r0, 0;
  b lbl_8012f2bc;
lbl_8012f290:
  lbz r0, 4(r31);
  cmplwi r0, 9;
  bge lbl_8012f2b8;
  lis r3, 0x8031;
  rlwinm r0, r0, 4, 0x14, 0x1b;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  add r3, r3, r0;
  lhz r0, -0x7618(r3);
  b lbl_8012f2bc;
lbl_8012f2b8:
  li r0, 0;
lbl_8012f2bc:
  add r4, r4, r0;
  clrlwi. r0, r4, 0x1f;
  beq lbl_8012f2d0;
  li r0, 1;
  b lbl_8012f2ec;
lbl_8012f2d0:
  lis r3, 0xddbb;
  lwz r4, 0(r4);
  addi r0, r3, -0x2246;
  subf r3, r4, r0;
  subf r0, r0, r4;
  or r0, r3, r0;
  srwi r0, r0, 0x1f;
lbl_8012f2ec:
  clrlwi. r0, r0, 0x18;
  beq lbl_8012f310;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -1;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x2788;
  bl GKI_exception;
  b lbl_8012f37c;
lbl_8012f310:
  lbz r0, 6(r31);
  cmplwi r0, 1;
  beq lbl_8012f338;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -7;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x27a4;
  bl GKI_exception;
  b lbl_8012f37c;
lbl_8012f338:
  bl GKI_disable;
  lwz r0, 0(r29);
  cmpwi r0, 0;
  beq lbl_8012f354;
  lwz r3, 4(r29);
  stw r31, -8(r3);
  b lbl_8012f358;
lbl_8012f354:
  stw r30, 0(r29);
lbl_8012f358:
  lhz r4, 8(r29);
  li r3, 0;
  stw r30, 4(r29);
  li r0, 2;
  addi r4, r4, 1;
  sth r4, 8(r29);
  stw r3, 0(r31);
  stb r0, 6(r31);
  bl GKI_enable;
lbl_8012f37c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GKI_enqueue_head
// PAL: 0x8012f398..0x8012f4d8
MARK_BINARY_BLOB(GKI_enqueue_head, 0x8012f398, 0x8012f4d8);
asm UNKNOWN_FUNCTION(GKI_enqueue_head) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  addi r31, r4, -8;
  clrlwi. r0, r31, 0x1f;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  beq lbl_8012f3cc;
  li r0, 0;
  b lbl_8012f3f8;
lbl_8012f3cc:
  lbz r0, 4(r31);
  cmplwi r0, 9;
  bge lbl_8012f3f4;
  lis r3, 0x8031;
  rlwinm r0, r0, 4, 0x14, 0x1b;
  addi r3, r3, -0x6640;
  addis r3, r3, 3;
  add r3, r3, r0;
  lhz r0, -0x7618(r3);
  b lbl_8012f3f8;
lbl_8012f3f4:
  li r0, 0;
lbl_8012f3f8:
  add r4, r4, r0;
  clrlwi. r0, r4, 0x1f;
  beq lbl_8012f40c;
  li r0, 1;
  b lbl_8012f428;
lbl_8012f40c:
  lis r3, 0xddbb;
  lwz r4, 0(r4);
  addi r0, r3, -0x2246;
  subf r3, r4, r0;
  subf r0, r0, r4;
  or r0, r3, r0;
  srwi r0, r0, 0x1f;
lbl_8012f428:
  clrlwi. r0, r0, 0x18;
  beq lbl_8012f44c;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -1;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x2788;
  bl GKI_exception;
  b lbl_8012f4bc;
lbl_8012f44c:
  lbz r0, 6(r31);
  cmplwi r0, 1;
  beq lbl_8012f474;
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -7;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x27c4;
  bl GKI_exception;
  b lbl_8012f4bc;
lbl_8012f474:
  bl GKI_disable;
  lwz r3, 0(r29);
  cmpwi r3, 0;
  beq lbl_8012f494;
  addi r0, r3, -8;
  stw r0, 0(r31);
  stw r30, 0(r29);
  b lbl_8012f4a4;
lbl_8012f494:
  stw r30, 0(r29);
  li r0, 0;
  stw r30, 4(r29);
  stw r0, 0(r31);
lbl_8012f4a4:
  lhz r3, 8(r29);
  li r0, 2;
  addi r3, r3, 1;
  sth r3, 8(r29);
  stb r0, 6(r31);
  bl GKI_enable;
lbl_8012f4bc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GKI_dequeue
// PAL: 0x8012f4d8..0x8012f578
MARK_BINARY_BLOB(GKI_dequeue, 0x8012f4d8, 0x8012f578);
asm UNKNOWN_FUNCTION(GKI_dequeue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl GKI_disable;
  cmpwi r30, 0;
  beq lbl_8012f508;
  lhz r0, 8(r30);
  cmpwi r0, 0;
  bne lbl_8012f514;
lbl_8012f508:
  bl GKI_enable;
  li r3, 0;
  b lbl_8012f560;
lbl_8012f514:
  lwz r31, 0(r30);
  lwz r3, -8(r31);
  cmpwi r3, 0;
  beq lbl_8012f530;
  addi r0, r3, 8;
  stw r0, 0(r30);
  b lbl_8012f53c;
lbl_8012f530:
  li r0, 0;
  stw r0, 0(r30);
  stw r0, 4(r30);
lbl_8012f53c:
  lhz r4, 8(r30);
  li r3, 0;
  li r0, 1;
  addi r4, r4, -1;
  sth r4, 8(r30);
  stw r3, -8(r31);
  stb r0, -2(r31);
  bl GKI_enable;
  mr r3, r31;
lbl_8012f560:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_remove_from_queue
// PAL: 0x8012f578..0x8012f63c
MARK_BINARY_BLOB(GKI_remove_from_queue, 0x8012f578, 0x8012f63c);
asm UNKNOWN_FUNCTION(GKI_remove_from_queue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl GKI_disable;
  lwz r3, 0(r30);
  cmplw r31, r3;
  bne lbl_8012f5b4;
  bl GKI_enable;
  mr r3, r30;
  bl GKI_dequeue;
  b lbl_8012f624;
lbl_8012f5b4:
  addi r5, r31, -8;
  addi r3, r3, -8;
  b lbl_8012f614;
lbl_8012f5c0:
  lwz r0, 0(r3);
  cmplw r0, r5;
  bne lbl_8012f610;
  lwz r0, 0(r5);
  stw r0, 0(r3);
  lwz r0, 4(r30);
  cmplw r31, r0;
  bne lbl_8012f5e8;
  addi r0, r3, 8;
  stw r0, 4(r30);
lbl_8012f5e8:
  lhz r4, 8(r30);
  li r3, 0;
  li r0, 1;
  addi r4, r4, -1;
  sth r4, 8(r30);
  stw r3, 0(r5);
  stb r0, 6(r5);
  bl GKI_enable;
  mr r3, r31;
  b lbl_8012f624;
lbl_8012f610:
  mr r3, r0;
lbl_8012f614:
  cmpwi r3, 0;
  bne lbl_8012f5c0;
  bl GKI_enable;
  li r3, 0;
lbl_8012f624:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_getfirst
// PAL: 0x8012f63c..0x8012f644
MARK_BINARY_BLOB(GKI_getfirst, 0x8012f63c, 0x8012f644);
asm UNKNOWN_FUNCTION(GKI_getfirst) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  blr;
  // clang-format on
}

// Symbol: GKI_getnext
// PAL: 0x8012f644..0x8012f660
MARK_BINARY_BLOB(GKI_getnext, 0x8012f644, 0x8012f660);
asm UNKNOWN_FUNCTION(GKI_getnext) {
  // clang-format off
  nofralloc;
  lwz r3, -8(r3);
  cmpwi r3, 0;
  beq lbl_8012f658;
  addi r3, r3, 8;
  blr;
lbl_8012f658:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: GKI_queue_is_empty
// PAL: 0x8012f660..0x8012f670
MARK_BINARY_BLOB(GKI_queue_is_empty, 0x8012f660, 0x8012f670);
asm UNKNOWN_FUNCTION(GKI_queue_is_empty) {
  // clang-format off
  nofralloc;
  lhz r0, 8(r3);
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  blr;
  // clang-format on
}

// Symbol: GKI_create_pool
// PAL: 0x8012f670..0x8012f9b8
MARK_BINARY_BLOB(GKI_create_pool, 0x8012f670, 0x8012f9b8);
asm UNKNOWN_FUNCTION(GKI_create_pool) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r7, 0x8031;
  cmplwi r3, 0xfff3;
  addi r7, r7, -0x6640;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  addi r30, r7, 0x54;
  ble lbl_8012f6ac;
  li r3, 0xff;
  b lbl_8012f9a0;
lbl_8012f6ac:
  li r0, 3;
  li r31, 0;
  mtctr r0;
lbl_8012f6b8:
  rlwinm r5, r31, 2, 0x16, 0x1d;
  addis r5, r5, 3;
  addi r0, r5, -0x75e4;
  lwzx r0, r30, r0;
  cmpwi r0, 0;
  beq lbl_8012f710;
  addi r31, r31, 1;
  rlwinm r5, r31, 2, 0x16, 0x1d;
  addis r5, r5, 3;
  addi r0, r5, -0x75e4;
  lwzx r0, r30, r0;
  cmpwi r0, 0;
  beq lbl_8012f710;
  addi r31, r31, 1;
  rlwinm r5, r31, 2, 0x16, 0x1d;
  addis r5, r5, 3;
  addi r0, r5, -0x75e4;
  lwzx r0, r30, r0;
  cmpwi r0, 0;
  beq lbl_8012f710;
  addi r31, r31, 1;
  bdnz lbl_8012f6b8;
lbl_8012f710:
  clrlwi r0, r31, 0x18;
  cmplwi r0, 9;
  bne lbl_8012f724;
  li r3, 0xff;
  b lbl_8012f9a0;
lbl_8012f724:
  addi r0, r3, 3;
  cmpwi r6, 0;
  rlwinm r3, r0, 0, 0, 0x1d;
  addi r0, r3, 0xc;
  mullw r3, r0, r4;
  bne lbl_8012f744;
  bl GKI_os_malloc;
  mr r6, r3;
lbl_8012f744:
  cmpwi r6, 0;
  beq lbl_8012f99c;
  mr r4, r27;
  mr r5, r28;
  clrlwi r3, r31, 0x18;
  bl gki_init_free_queue;
  lis r3, 0x8031;
  rlwinm r5, r31, 4, 0x14, 0x1b;
  addi r3, r3, -0x6640;
  li r4, 0;
  addi r3, r3, 0x54;
  addis r6, r5, 3;
  addis r5, r3, 3;
  lbz r5, -0x7579(r5);
  addi r0, r6, -0x766c;
  lhzx r7, r3, r0;
  mtctr r5;
  cmpwi r5, 0;
  ble lbl_8012f7bc;
lbl_8012f790:
  addis r6, r4, 3;
  addi r0, r6, -0x7582;
  lbzx r0, r3, r0;
  slwi r6, r0, 4;
  addis r6, r6, 3;
  addi r0, r6, -0x766c;
  lhzx r0, r3, r0;
  cmplw r7, r0;
  ble lbl_8012f7bc;
  addi r4, r4, 1;
  bdnz lbl_8012f790;
lbl_8012f7bc:
  cmpw r5, r4;
  ble lbl_8012f924;
  subf r0, r4, r5;
  addi r8, r4, 8;
  cmpwi r0, 8;
  ble lbl_8012f8fc;
  addis r6, r3, 3;
  li r9, 0;
  lbz r0, -0x7579(r6);
  li r10, 0;
  li r11, 0;
  li r7, 0;
  cmpw r0, r4;
  blt lbl_8012f808;
  lis r6, 0x8000;
  addi r0, r6, 1;
  cmpw r4, r0;
  blt lbl_8012f808;
  li r7, 1;
lbl_8012f808:
  cmpwi r7, 0;
  beq lbl_8012f82c;
  addis r7, r3, 3;
  lis r6, 0x8000;
  lbz r7, -0x7579(r7);
  addi r0, r6, 1;
  cmpw r7, r0;
  blt lbl_8012f82c;
  li r11, 1;
lbl_8012f82c:
  cmpwi r11, 0;
  beq lbl_8012f844;
  addis r0, r4, -0x8000;
  cmplwi r0, 0;
  beq lbl_8012f844;
  li r10, 1;
lbl_8012f844:
  cmpwi r10, 0;
  beq lbl_8012f88c;
  addis r6, r3, 3;
  neg r0, r4;
  lbz r10, -0x7579(r6);
  rlwinm r0, r0, 0, 0, 0;
  li r6, 1;
  rlwinm r7, r10, 0, 0, 0;
  cmpw r7, r0;
  bne lbl_8012f880;
  subf r0, r4, r10;
  rlwinm r0, r0, 0, 0, 0;
  cmpw r7, r0;
  beq lbl_8012f880;
  li r6, 0;
lbl_8012f880:
  cmpwi r6, 0;
  beq lbl_8012f88c;
  li r9, 1;
lbl_8012f88c:
  cmpwi r9, 0;
  beq lbl_8012f8fc;
  addi r0, r5, 7;
  subf r0, r8, r0;
  srwi r0, r0, 3;
  mtctr r0;
  cmpw r5, r8;
  ble lbl_8012f8fc;
lbl_8012f8ac:
  add r6, r3, r5;
  addi r5, r5, -8;
  addis r6, r6, 3;
  lbz r0, -0x7583(r6);
  stb r0, -0x7582(r6);
  lbz r0, -0x7584(r6);
  stb r0, -0x7583(r6);
  lbz r0, -0x7585(r6);
  stb r0, -0x7584(r6);
  lbz r0, -0x7586(r6);
  stb r0, -0x7585(r6);
  lbz r0, -0x7587(r6);
  stb r0, -0x7586(r6);
  lbz r0, -0x7588(r6);
  stb r0, -0x7587(r6);
  lbz r0, -0x7589(r6);
  stb r0, -0x7588(r6);
  lbz r0, -0x758a(r6);
  stb r0, -0x7589(r6);
  bdnz lbl_8012f8ac;
lbl_8012f8fc:
  subf r0, r4, r5;
  mtctr r0;
  cmpw r5, r4;
  ble lbl_8012f924;
lbl_8012f90c:
  add r6, r3, r5;
  addi r5, r5, -1;
  addis r6, r6, 3;
  lbz r0, -0x7583(r6);
  stb r0, -0x7582(r6);
  bdnz lbl_8012f90c;
lbl_8012f924:
  addis r0, r3, 3;
  clrlwi r5, r31, 0x18;
  add r4, r0, r4;
  lis r3, 0x8031;
  addi r3, r3, -0x6640;
  cmplwi r5, 9;
  stb r31, -0x7582(r4);
  addi r3, r3, 0x54;
  bge lbl_8012f984;
  cmplwi r29, 1;
  bne lbl_8012f96c;
  addis r4, r3, 3;
  li r0, 1;
  lhz r3, -0x7584(r4);
  slw r0, r0, r5;
  or r0, r3, r0;
  sth r0, -0x7584(r4);
  b lbl_8012f984;
lbl_8012f96c:
  addis r4, r3, 3;
  li r0, 1;
  lhz r3, -0x7584(r4);
  slw r0, r0, r5;
  andc r0, r3, r0;
  sth r0, -0x7584(r4);
lbl_8012f984:
  addis r5, r30, 3;
  mr r3, r31;
  lbz r4, -0x7579(r5);
  addi r0, r4, 1;
  stb r0, -0x7579(r5);
  b lbl_8012f9a0;
lbl_8012f99c:
  li r3, 0xff;
lbl_8012f9a0:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GKI_delete_pool
// PAL: 0x8012f9b8..0x8012fb18
MARK_BINARY_BLOB(GKI_delete_pool, 0x8012f9b8, 0x8012fb18);
asm UNKNOWN_FUNCTION(GKI_delete_pool) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r27, 0x8031;
  cmplwi r3, 9;
  addi r27, r27, -0x6640;
  mr r30, r3;
  addi r31, r27, 0x54;
  bge lbl_8012fb00;
  rlwinm r26, r3, 2, 0x16, 0x1d;
  addis r0, r31, 3;
  add r3, r0, r26;
  lwz r0, -0x75e4(r3);
  cmpwi r0, 0;
  bne lbl_8012fa00;
  b lbl_8012fb00;
lbl_8012fa00:
  bl GKI_disable;
  addis r4, r31, 3;
  rlwinm r0, r30, 4, 0x14, 0x1b;
  add r3, r4, r0;
  lhz r0, -0x7668(r3);
  cmpwi r0, 0;
  bne lbl_8012fae4;
  li r28, 0;
  add r29, r4, r26;
  sth r28, -0x766c(r3);
  sth r28, -0x766a(r3);
  sth r28, -0x7668(r3);
  sth r28, -0x7666(r3);
  stw r28, -0x7674(r3);
  stw r28, -0x7670(r3);
  lwz r3, -0x75e4(r29);
  bl GKI_os_free;
  addis r4, r31, 3;
  stw r28, -0x75e4(r29);
  add r3, r4, r26;
  rlwinm r0, r30, 1, 0x17, 0x1e;
  stw r28, -0x75c0(r3);
  add r3, r4, r0;
  mr r7, r31;
  li r6, 0;
  sth r28, -0x759c(r3);
  lbz r4, -0x7579(r4);
  b lbl_8012fa8c;
lbl_8012fa70:
  clrlwi r3, r6, 0x18;
  addis r3, r3, 3;
  addi r0, r3, -0x7582;
  lbzx r0, r7, r0;
  cmplw r30, r0;
  beq lbl_8012fa98;
  addi r6, r6, 1;
lbl_8012fa8c:
  clrlwi r0, r6, 0x18;
  cmplw r0, r4;
  blt lbl_8012fa70;
lbl_8012fa98:
  addis r4, r7, 3;
  b lbl_8012fabc;
lbl_8012faa0:
  clrlwi r3, r6, 0x18;
  addi r6, r6, 1;
  addis r3, r3, 3;
  addi r3, r3, -0x7582;
  add r3, r7, r3;
  lbz r0, 1(r3);
  stb r0, 0(r3);
lbl_8012fabc:
  lbz r3, -0x7579(r4);
  clrlwi r5, r6, 0x18;
  addi r0, r3, -1;
  cmpw r5, r0;
  blt lbl_8012faa0;
  addis r4, r31, 3;
  lbz r3, -0x7579(r4);
  addi r0, r3, -1;
  stb r0, -0x7579(r4);
  b lbl_8012fafc;
lbl_8012fae4:
  lis r3, 0x1;
  lis r4, 0x8028;
  addi r0, r3, -8;
  clrlwi r3, r0, 0x10;
  addi r4, r4, 0x2808;
  bl GKI_exception;
lbl_8012fafc:
  bl GKI_enable;
lbl_8012fb00:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
