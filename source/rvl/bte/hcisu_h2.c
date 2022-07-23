#include "hcisu_h2.h"

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_main.h"
#include "l2c_link.h"
#include "uusb_ppc.h"

// Symbol: hcisu_h2_usb_cback
// PAL: 0x80130300..0x80130324
MARK_BINARY_BLOB(hcisu_h2_usb_cback, 0x80130300, 0x80130324);
asm UNKNOWN_FUNCTION(hcisu_h2_usb_cback) {
  // clang-format off
  nofralloc;
  cmpwi r3, 4;
  beq lbl_80130318;
  bgelr;
  cmpwi r3, 0;
  beqlr;
  blr;
lbl_80130318:
  extsb r3, r4;
  b bta_usb_close_evt;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_receive_msg
// PAL: 0x80130324..0x801306bc
MARK_BINARY_BLOB(hcisu_h2_receive_msg, 0x80130324, 0x801306bc);
asm UNKNOWN_FUNCTION(hcisu_h2_receive_msg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_14;
  lbz r0, 0x1e(r4);
  mr r15, r4;
  li r19, 0;
  cmplwi r0, 2;
  beq lbl_80130354;
  li r3, 0;
  b lbl_801306a4;
lbl_80130354:
  addi r20, r3, 1;
  rlwinm r0, r3, 1, 0xf, 0x1e;
  lis r31, 0x8033;
  add r22, r4, r3;
  clrlwi r16, r20, 0x10;
  rlwinm r23, r3, 2, 0xe, 0x1d;
  add r21, r4, r0;
  addi r31, r31, 0x24a0;
  li r29, 0;
  li r30, 4;
  addi r28, r2, -26944;
  li r25, 3;
  li r24, 2;
  lis r14, 0x8028;
  addi r26, r2, -26936;
  li r27, 1;
lbl_80130394:
  clrlwi r3, r16, 0x18;
  addi r4, r1, 8;
  li r5, 1;
  bl UUSB_Read;
  clrlwi. r0, r3, 0x10;
  beq lbl_801306a0;
  lbz r0, 0x1a(r22);
  li r17, 0;
  addi r19, r19, 1;
  cmpwi r0, 2;
  beq lbl_80130584;
  bge lbl_801303d4;
  cmpwi r0, 0;
  beq lbl_801303e4;
  bge lbl_8013048c;
  b lbl_80130680;
lbl_801303d4:
  cmpwi r0, 4;
  beq lbl_80130668;
  bge lbl_80130680;
  b lbl_801305d0;
lbl_801303e4:
  cmplwi r16, 1;
  bne lbl_80130400;
  li r3, 2;
  bl GKI_getpoolbuf;
  stwx r3, r15, r23;
  stb r30, 0x14(r22);
  b lbl_80130434;
lbl_80130400:
  cmplwi r16, 2;
  bne lbl_8013041c;
  li r3, 3;
  bl GKI_getpoolbuf;
  stwx r3, r15, r23;
  stb r24, 0x14(r22);
  b lbl_80130434;
lbl_8013041c:
  cmplwi r16, 3;
  bne lbl_80130680;
  li r3, 1;
  bl GKI_getpoolbuf;
  stwx r3, r15, r23;
  stb r25, 0x14(r22);
lbl_80130434:
  lwzx r3, r15, r23;
  cmpwi r3, 0;
  beq lbl_8013046c;
  sth r29, 2(r3);
  lbz r0, 0x14(r22);
  lwzx r3, r15, r23;
  slwi r0, r0, 1;
  add r4, r26, r0;
  lhz r0, -2(r4);
  sth r0, 0(r3);
  lwzx r3, r15, r23;
  sth r29, 4(r3);
  stb r27, 0x1a(r22);
  b lbl_8013047c;
lbl_8013046c:
  addi r4, r14, 0x2820;
  lis r3, 7;
  bl LogMsg_0;
  stb r24, 0x1a(r22);
lbl_8013047c:
  lbz r0, 0x14(r22);
  add r3, r28, r0;
  lbz r0, -1(r3);
  sth r0, 0xc(r21);
lbl_8013048c:
  lwzx r6, r15, r23;
  lbz r5, 8(r1);
  lhz r4, 2(r6);
  add r3, r6, r4;
  addi r0, r4, 1;
  stb r5, 8(r3);
  sth r0, 2(r6);
  lhz r3, 0xc(r21);
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x10;
  sth r3, 0xc(r21);
  bne lbl_80130578;
  lbz r0, 0x14(r22);
  lbz r18, 8(r1);
  cmplwi r0, 2;
  bne lbl_8013050c;
  lbz r0, 0x17(r22);
  rlwinm r4, r18, 8, 8, 0x17;
  lwzx r3, r15, r23;
  add r0, r4, r0;
  clrlwi r18, r0, 0x10;
  bl l2cap_link_chk_pkt_start;
  cmpwi r3, 0;
  stwx r3, r15, r23;
  bne lbl_8013050c;
  cmpwi r18, 0;
  sth r18, 0xc(r21);
  bne lbl_80130504;
  stb r29, 0x1a(r22);
  b lbl_80130680;
lbl_80130504:
  stb r30, 0x1a(r22);
  b lbl_80130680;
lbl_8013050c:
  sth r18, 0xc(r21);
  lwzx r3, r15, r23;
  bl GKI_get_buf_size;
  lbz r0, 0x14(r22);
  clrlwi r4, r3, 0x10;
  add r3, r28, r0;
  lbz r0, -1(r3);
  add r3, r18, r0;
  addi r0, r3, 8;
  cmplw r0, r4;
  ble lbl_8013055c;
  lwzx r3, r15, r23;
  bl GKI_freebuf;
  stwx r29, r15, r23;
  lis r3, 0x8028;
  addi r4, r3, 0x285c;
  stb r30, 0x1a(r22);
  lis r3, 7;
  bl LogMsg_0;
  b lbl_80130680;
lbl_8013055c:
  cmpwi r18, 0;
  beq lbl_8013056c;
  stb r25, 0x1a(r22);
  b lbl_80130680;
lbl_8013056c:
  stb r29, 0x1a(r22);
  li r17, 1;
  b lbl_80130680;
lbl_80130578:
  lbz r0, 8(r1);
  stb r0, 0x17(r22);
  b lbl_80130680;
lbl_80130584:
  lhz r3, 0xc(r21);
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x10;
  sth r3, 0xc(r21);
  bne lbl_801305c4;
  lbz r0, 0x14(r22);
  lbz r3, 8(r1);
  cmplwi r0, 2;
  bne lbl_801305b8;
  lbz r0, 0x17(r22);
  rlwinm r3, r3, 8, 8, 0x17;
  add r0, r3, r0;
  clrlwi r3, r0, 0x10;
lbl_801305b8:
  sth r3, 0xc(r21);
  stb r30, 0x1a(r22);
  b lbl_80130680;
lbl_801305c4:
  lbz r0, 8(r1);
  stb r0, 0x17(r22);
  b lbl_80130680;
lbl_801305d0:
  lwzx r7, r15, r23;
  clrlwi r3, r20, 0x18;
  lbz r6, 8(r1);
  lhz r5, 2(r7);
  add r4, r7, r5;
  addi r0, r5, 1;
  stb r6, 8(r4);
  sth r0, 2(r7);
  lhz r4, 0xc(r21);
  addi r0, r4, -1;
  sth r0, 0xc(r21);
  clrlwi r5, r0, 0x10;
  lwzx r4, r15, r23;
  lhz r0, 2(r4);
  add r4, r4, r0;
  addi r4, r4, 8;
  bl UUSB_Read;
  lwzx r4, r15, r23;
  add r19, r19, r3;
  lhz r0, 2(r4);
  add r0, r0, r3;
  sth r0, 2(r4);
  lhz r0, 0xc(r21);
  subf r3, r3, r0;
  clrlwi. r0, r3, 0x10;
  sth r3, 0xc(r21);
  bne lbl_80130680;
  lbz r0, 0x14(r22);
  cmplwi r0, 2;
  bne lbl_8013065c;
  bl l2cap_link_chk_pkt_end;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013065c;
  stb r29, 0x1a(r22);
  b lbl_80130680;
lbl_8013065c:
  stb r29, 0x1a(r22);
  li r17, 1;
  b lbl_80130680;
lbl_80130668:
  lhz r3, 0xc(r21);
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x10;
  sth r3, 0xc(r21);
  bne lbl_80130680;
  stb r29, 0x1a(r22);
lbl_80130680:
  cmpwi r17, 0;
  beq lbl_80130394;
  lbz r3, 0x1f(r31);
  li r4, 0;
  lwzx r5, r15, r23;
  bl GKI_send_msg;
  stwx r29, r15, r23;
  b lbl_80130394;
lbl_801306a0:
  mr r3, r19;
lbl_801306a4:
  addi r11, r1, 0x60;
  bl _restgpr_14;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_send_msg_now
// PAL: 0x801306bc..0x80130868
MARK_BINARY_BLOB(hcisu_h2_send_msg_now, 0x801306bc, 0x80130868);
asm UNKNOWN_FUNCTION(hcisu_h2_send_msg_now) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lhz r5, 0(r4);
  mr r27, r4;
  lhz r0, 4(r4);
  cmplwi r5, 0x2100;
  add r3, r4, r0;
  addi r6, r3, 8;
  bne lbl_801306f4;
  li r28, 2;
  b lbl_80130710;
lbl_801306f4:
  cmplwi r5, 0x2200;
  bne lbl_80130704;
  li r28, 3;
  b lbl_80130710;
lbl_80130704:
  cmplwi r5, 0x2000;
  bne lbl_80130710;
  li r28, 0;
lbl_80130710:
  cmplwi r5, 0x2100;
  bne lbl_80130834;
  lis r3, 0x8033;
  lhz r4, 2(r4);
  addi r30, r3, 0x5d50;
  lhz r0, 0x7e(r30);
  cmplw r4, r0;
  ble lbl_80130834;
  lbz r0, 1(r6);
  lbz r3, 0(r6);
  addi r6, r6, 2;
  rlwinm r0, r0, 8, 0x10, 0x17;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  andi. r0, r0, 0xcfff;
  ori r31, r0, 0x1000;
  srawi r29, r31, 8;
  b lbl_80130824;
lbl_80130758:
  mr r4, r6;
  mr r3, r28;
  mr r6, r27;
  bl UUSB_Write;
  lhz r3, 4(r27);
  lhz r0, 0x7c(r30);
  lhz r4, 2(r27);
  add r0, r3, r0;
  sth r0, 4(r27);
  clrlwi r0, r0, 0x10;
  add r3, r27, r0;
  lhz r0, 0x7c(r30);
  addi r6, r3, 0xa;
  subf r0, r0, r4;
  sth r0, 2(r27);
  stb r31, 8(r3);
  stb r29, 9(r3);
  lhz r3, 2(r27);
  lhz r0, 0x7e(r30);
  cmplw r3, r0;
  ble lbl_801307c8;
  lhz r0, 0x7c(r30);
  stb r0, 0(r6);
  lhz r0, 0x7c(r30);
  srawi r0, r0, 8;
  stb r0, 1(r6);
  addi r6, r6, 2;
  b lbl_801307e4;
lbl_801307c8:
  addi r0, r3, -4;
  stb r0, 0(r6);
  lhz r3, 2(r27);
  addi r0, r3, -4;
  srawi r0, r0, 8;
  stb r0, 1(r6);
  addi r6, r6, 2;
lbl_801307e4:
  lhz r3, 6(r27);
  cmpwi r3, 0;
  beq lbl_80130824;
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x10;
  sth r3, 6(r27);
  bne lbl_80130824;
  li r0, 0x1900;
  lis r3, 0x8033;
  sth r0, 0(r27);
  addi r3, r3, 0x24a0;
  mr r5, r27;
  li r4, 0;
  lbz r3, 0x1f(r3);
  bl GKI_send_msg;
  b lbl_80130850;
lbl_80130824:
  lhz r5, 0x7e(r30);
  lhz r0, 2(r27);
  cmplw r0, r5;
  bgt lbl_80130758;
lbl_80130834:
  lhz r5, 2(r27);
  mr r4, r6;
  mr r3, r28;
  mr r6, r27;
  bl UUSB_Write;
  mr r3, r27;
  bl GKI_freebuf;
lbl_80130850:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_init
// PAL: 0x80130868..0x80130894
MARK_BINARY_BLOB(hcisu_h2_init, 0x80130868, 0x80130894);
asm UNKNOWN_FUNCTION(hcisu_h2_init) {
  // clang-format off
  nofralloc;
  lis r6, 0x8033;
  li r0, 0;
  addi r6, r6, 0x24a0;
  stb r0, 0x1e(r6);
  stb r0, 0x1a(r6);
  stb r0, 0x1b(r6);
  stb r0, 0x1c(r6);
  stb r3, 0x1f(r6);
  stb r4, 0x20(r6);
  sth r5, 0x12(r6);
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_open
// PAL: 0x80130894..0x801308fc
MARK_BINARY_BLOB(hcisu_h2_open, 0x80130894, 0x801308fc);
asm UNKNOWN_FUNCTION(hcisu_h2_open) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  li r0, 0;
  addi r5, r5, 0x24a0;
  stb r0, 0x13(r1);
  li r0, 2;
  lbz r4, 0x1f(r5);
  lhz r6, 0(r3);
  sth r6, 0xc(r1);
  lhz r6, 2(r3);
  addi r3, r1, 8;
  sth r6, 0xe(r1);
  sth r4, 0x10(r1);
  stb r0, 0x1e(r5);
  bl UUSB_Register;
  lis r4, 0x8013;
  addi r3, r1, 8;
  addi r4, r4, 0x300;
  bl UUSB_Open;
  lwz r0, 0x24(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_close
// PAL: 0x801308fc..0x80130930
MARK_BINARY_BLOB(hcisu_h2_close, 0x801308fc, 0x80130930);
asm UNKNOWN_FUNCTION(hcisu_h2_close) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x14(r1);
  li r0, 0;
  addi r3, r3, 0x24a0;
  stb r0, 0x1e(r3);
  bl UUSB_Close;
  bl UUSB_Unregister;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_send
// PAL: 0x80130930..0x80130960
MARK_BINARY_BLOB(hcisu_h2_send, 0x80130930, 0x80130960);
asm UNKNOWN_FUNCTION(hcisu_h2_send) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8033;
  mr r4, r3;
  stw r0, 0x14(r1);
  addi r3, r5, 0x24a0;
  bl hcisu_h2_send_msg_now;
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hcisu_h2_handle_event
// PAL: 0x80130960..0x8013099c
MARK_BINARY_BLOB(hcisu_h2_handle_event, 0x80130960, 0x8013099c);
asm UNKNOWN_FUNCTION(hcisu_h2_handle_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x24a0;
  addi r0, r3, -8;
  lhz r3, 0x12(r4);
  subf r0, r3, r0;
  clrlwi r3, r0, 0x10;
  bl hcisu_h2_receive_msg;
  lwz r0, 0x14(r1);
  li r3, 0;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
