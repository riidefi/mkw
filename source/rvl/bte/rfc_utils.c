#include "rfc_utils.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "port_rfc.h"
#include "rfc_mx_fsm.h"
#include "rfc_port_fsm.h"
#include "l2c_api.h"

// Symbol: rfc_calc_fcs
// PAL: 0x80155e38..0x80155e70
MARK_BINARY_BLOB(rfc_calc_fcs, 0x80155e38, 0x80155e70);
asm UNKNOWN_FUNCTION(rfc_calc_fcs) {
  // clang-format off
  nofralloc;
  lis r5, 0x8025;
  li r6, 0xff;
  addi r5, r5, -13752;
  b lbl_80155e58;
lbl_80155e48:
  lbz r0, 0(r4);
  addi r4, r4, 1;
  xor r0, r6, r0;
  lbzx r6, r5, r0;
lbl_80155e58:
  clrlwi. r0, r3, 0x10;
  addi r3, r3, -1;
  bne lbl_80155e48;
  subfic r0, r6, 0xff;
  clrlwi r3, r0, 0x18;
  blr;
  // clang-format on
}

// Symbol: rfc_check_fcs
// PAL: 0x80155e70..0x80155ebc
MARK_BINARY_BLOB(rfc_check_fcs, 0x80155e70, 0x80155ebc);
asm UNKNOWN_FUNCTION(rfc_check_fcs) {
  // clang-format off
  nofralloc;
  lis r6, 0x8025;
  li r7, 0xff;
  addi r6, r6, -13752;
  b lbl_80155e90;
lbl_80155e80:
  lbz r0, 0(r4);
  addi r4, r4, 1;
  xor r0, r7, r0;
  lbzx r7, r6, r0;
lbl_80155e90:
  clrlwi. r0, r3, 0x10;
  addi r3, r3, -1;
  bne lbl_80155e80;
  lis r3, 0x8025;
  xor r0, r7, r5;
  addi r3, r3, -13752;
  lbzx r3, r3, r0;
  addi r0, r3, -207;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  blr;
  // clang-format on
}

// Symbol: rfc_alloc_multiplexer_channel
// PAL: 0x80155ebc..0x80156014
MARK_BINARY_BLOB(rfc_alloc_multiplexer_channel, 0x80155ebc, 0x80156014);
asm UNKNOWN_FUNCTION(rfc_alloc_multiplexer_channel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r5, 0x8034;
  mr r27, r3;
  addi r31, r5, -25816;
  mr r28, r4;
  lbz r0, 0x408(r31);
  addi r3, r31, 0x3fe;
  li r30, 0;
  cmpwi r0, 0;
  beq lbl_80155f4c;
  mr r4, r27;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80155f4c;
  lbz r0, 0x414(r31);
  cmplwi r0, 4;
  blt lbl_80155f28;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x7730;
  bl LogMsg_0;
lbl_80155f28:
  mulli r0, r30, 0x78;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  add r3, r3, r0;
  addi r31, r3, 0x39c;
  mr r3, r31;
  bl btu_stop_timer;
  mr r3, r31;
  b lbl_80155ffc;
lbl_80155f4c:
  lis r31, 0x8034;
  addi r31, r31, -25816;
  lbz r3, 0x65(r31);
  addi r30, r3, 1;
  cmpwi r30, 1;
  blt lbl_80155f68;
  li r30, 0;
lbl_80155f68:
  mulli r0, r30, 0x78;
  add r3, r31, r0;
  lbz r0, 0x408(r3);
  addi r29, r3, 0x39c;
  cmpwi r0, 0;
  bne lbl_80155ff8;
  mr r3, r29;
  li r4, 0;
  li r5, 0x78;
  bl memset;
  mr r4, r27;
  addi r3, r29, 0x62;
  li r5, 6;
  bl memcpy;
  addi r3, r29, 0x18;
  bl GKI_init_q;
  stb r28, 0x6d(r29);
  lbz r0, 0x414(r31);
  cmplwi r0, 4;
  blt lbl_80155fd0;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  li r5, 0x3c;
  addi r4, r4, 0x7740;
  bl LogMsg_1;
lbl_80155fd0:
  stw r29, 0x10(r29);
  mr r3, r29;
  li r4, 0xb;
  li r5, 0x3c;
  bl btu_start_timer;
  lis r4, 0x8034;
  mr r3, r29;
  addi r4, r4, -25816;
  stb r30, 0x65(r4);
  b lbl_80155ffc;
lbl_80155ff8:
  li r3, 0;
lbl_80155ffc:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_release_multiplexer_channel
// PAL: 0x80156014..0x8015609c
MARK_BINARY_BLOB(rfc_release_multiplexer_channel, 0x80156014, 0x8015609c);
asm UNKNOWN_FUNCTION(rfc_release_multiplexer_channel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -25816;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80156050;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x7730;
  bl LogMsg_0;
lbl_80156050:
  mr r3, r31;
  bl btu_stop_timer;
  b lbl_80156060;
lbl_8015605c:
  bl GKI_freebuf;
lbl_80156060:
  addi r3, r31, 0x18;
  bl GKI_dequeue;
  cmpwi r3, 0;
  bne lbl_8015605c;
  mr r3, r31;
  li r4, 0;
  li r5, 0x78;
  bl memset;
  li r0, 0;
  stb r0, 0x6c(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_timer_start
// PAL: 0x8015609c..0x80156110
MARK_BINARY_BLOB(rfc_timer_start, 0x8015609c, 0x80156110);
asm UNKNOWN_FUNCTION(rfc_timer_start) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -25816;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_801560e4;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x7740;
  bl LogMsg_1;
lbl_801560e4:
  stw r30, 0x10(r30);
  mr r3, r30;
  mr r5, r31;
  li r4, 0xb;
  bl btu_start_timer;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_timer_stop
// PAL: 0x80156110..0x80156168
MARK_BINARY_BLOB(rfc_timer_stop, 0x80156110, 0x80156168);
asm UNKNOWN_FUNCTION(rfc_timer_stop) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -25816;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_8015614c;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x7730;
  bl LogMsg_0;
lbl_8015614c:
  mr r3, r31;
  bl btu_stop_timer;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_timer_start
// PAL: 0x80156168..0x801561e8
MARK_BINARY_BLOB(rfc_port_timer_start, 0x80156168, 0x801561e8);
asm UNKNOWN_FUNCTION(rfc_port_timer_start) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  addi r5, r5, -25816;
  stw r31, 0x1c(r1);
  addi r31, r3, 0x70;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_801561b8;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x7760;
  bl LogMsg_1;
lbl_801561b8:
  stw r29, 0x10(r31);
  mr r3, r31;
  mr r5, r30;
  li r4, 0xc;
  bl btu_start_timer;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_port_timer_stop
// PAL: 0x801561e8..0x80156240
MARK_BINARY_BLOB(rfc_port_timer_stop, 0x801561e8, 0x80156240);
asm UNKNOWN_FUNCTION(rfc_port_timer_stop) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -25816;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80156224;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x7784;
  bl LogMsg_0;
lbl_80156224:
  addi r3, r31, 0x70;
  bl btu_stop_timer;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_check_mcb_active
// PAL: 0x80156240..0x80156304
MARK_BINARY_BLOB(rfc_check_mcb_active, 0x80156240, 0x80156304);
asm UNKNOWN_FUNCTION(rfc_check_mcb_active) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 0;
  stw r0, 0x14(r1);
  li r0, 0x3d;
  stw r31, 0xc(r1);
  mr r31, r3;
  mtctr r0;
lbl_80156260:
  clrlwi r0, r5, 0x10;
  add r4, r3, r0;
  lbz r0, 0x24(r4);
  cmpwi r0, 0;
  beq lbl_80156280;
  li r0, 0;
  stb r0, 0x74(r3);
  b lbl_801562f0;
lbl_80156280:
  addi r5, r5, 1;
  bdnz lbl_80156260;
  lbz r0, 0x74(r3);
  cmpwi r0, 0;
  beq lbl_801562b0;
  li r0, 0;
  li r4, 8;
  stb r0, 0x74(r3);
  mr r3, r31;
  li r5, 0;
  bl rfc_mx_sm_execute;
  b lbl_801562f0;
lbl_801562b0:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_801562dc;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  li r5, 2;
  addi r4, r4, 0x7740;
  bl LogMsg_1;
lbl_801562dc:
  stw r31, 0x10(r31);
  mr r3, r31;
  li r4, 0xb;
  li r5, 2;
  bl btu_start_timer;
lbl_801562f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfcomm_process_timeout
// PAL: 0x80156304..0x80156340
MARK_BINARY_BLOB(rfcomm_process_timeout, 0x80156304, 0x80156340);
asm UNKNOWN_FUNCTION(rfcomm_process_timeout) {
  // clang-format off
  nofralloc;
  lhz r0, 0x14(r3);
  cmpwi r0, 0xc;
  beq lbl_8015632c;
  bgelr;
  cmpwi r0, 0xb;
  bltlr;
  lwz r3, 0x10(r3);
  li r4, 5;
  li r5, 0;
  b rfc_mx_sm_execute;
lbl_8015632c:
  lwz r3, 0x10(r3);
  li r4, 5;
  li r5, 0;
  b rfc_port_sm_execute;
  blr;
  // clang-format on
}

// Symbol: rfc_sec_check_complete
// PAL: 0x80156340..0x80156394
MARK_BINARY_BLOB(rfc_sec_check_complete, 0x80156340, 0x80156394);
asm UNKNOWN_FUNCTION(rfc_sec_check_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stb r5, 8(r1);
  lbz r0, 1(r4);
  cmpwi r0, 0;
  beq lbl_80156384;
  lbz r0, 0x68(r4);
  cmplwi r0, 2;
  beq lbl_80156374;
  cmplwi r0, 3;
  beq lbl_80156374;
  b lbl_80156384;
lbl_80156374:
  mr r3, r4;
  addi r5, r1, 8;
  li r4, 0xf;
  bl rfc_port_sm_execute;
lbl_80156384:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_closed
// PAL: 0x80156394..0x801564ec
MARK_BINARY_BLOB(rfc_port_closed, 0x80156394, 0x801564ec);
asm UNKNOWN_FUNCTION(rfc_port_closed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x24(r1);
  addi r4, r4, -25816;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x7730;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r4);
  lwz r30, 0x6c(r3);
  cmplwi r0, 5;
  blt lbl_801563e0;
  lis r3, 9;
  addi r4, r31, 0x68;
  addi r3, r3, 4;
  bl LogMsg_0;
lbl_801563e0:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80156404;
  lis r3, 9;
  addi r4, r31, 0x54;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80156404:
  addi r3, r29, 0x70;
  bl btu_stop_timer;
  li r4, 0;
  cmpwi r30, 0;
  stb r4, 0x68(r29);
  beq lbl_801564c4;
  lbz r3, 0xd(r29);
  li r0, 0x3d;
  li r5, 0;
  add r3, r30, r3;
  stb r4, 0x24(r3);
  stb r4, 0xd(r29);
  mtctr r0;
lbl_80156438:
  clrlwi r0, r5, 0x10;
  add r3, r30, r0;
  lbz r0, 0x24(r3);
  cmpwi r0, 0;
  beq lbl_80156458;
  li r0, 0;
  stb r0, 0x74(r30);
  b lbl_801564c4;
lbl_80156458:
  addi r5, r5, 1;
  bdnz lbl_80156438;
  lbz r0, 0x74(r30);
  cmpwi r0, 0;
  beq lbl_80156488;
  li r0, 0;
  mr r3, r30;
  stb r0, 0x74(r30);
  li r4, 8;
  li r5, 0;
  bl rfc_mx_sm_execute;
  b lbl_801564c4;
lbl_80156488:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_801564b0;
  lis r3, 9;
  addi r4, r31, 0x10;
  addi r3, r3, 3;
  li r5, 2;
  bl LogMsg_1;
lbl_801564b0:
  stw r30, 0x10(r30);
  mr r3, r30;
  li r4, 0xb;
  li r5, 2;
  bl btu_start_timer;
lbl_801564c4:
  mr r3, r29;
  li r4, 0x13;
  bl port_rfc_closed;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_inc_credit
// PAL: 0x801564ec..0x80156578
MARK_BINARY_BLOB(rfc_inc_credit, 0x801564ec, 0x80156578);
asm UNKNOWN_FUNCTION(rfc_inc_credit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r5, 0x6c(r3);
  lbz r0, 0x72(r5);
  cmplwi r0, 2;
  bne lbl_80156564;
  lhz r0, 0x98(r3);
  lis r5, 0x8034;
  addi r5, r5, -25816;
  add r6, r0, r4;
  sth r6, 0x98(r3);
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_80156548;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  clrlwi r5, r6, 0x10;
  addi r4, r4, 0x77a8;
  bl LogMsg_1;
lbl_80156548:
  lbz r0, 0x24(r31);
  cmplwi r0, 1;
  bne lbl_80156564;
  lwz r3, 0x6c(r31);
  li r5, 1;
  lbz r4, 0xd(r31);
  bl PORT_FlowInd;
lbl_80156564:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_dec_credit
// PAL: 0x80156578..0x801565b4
MARK_BINARY_BLOB(rfc_dec_credit, 0x80156578, 0x801565b4);
asm UNKNOWN_FUNCTION(rfc_dec_credit) {
  // clang-format off
  nofralloc;
  lwz r4, 0x6c(r3);
  lbz r0, 0x72(r4);
  cmplwi r0, 2;
  bnelr;
  lhz r4, 0x98(r3);
  cmpwi r4, 0;
  beq lbl_8015659c;
  addi r0, r4, -1;
  sth r0, 0x98(r3);
lbl_8015659c:
  lhz r0, 0x98(r3);
  cmpwi r0, 0;
  bnelr;
  li r0, 1;
  stb r0, 0x24(r3);
  blr;
  // clang-format on
}

// Symbol: rfc_check_send_cmd
// PAL: 0x801565b4..0x80156618
MARK_BINARY_BLOB(rfc_check_send_cmd, 0x801565b4, 0x80156618);
asm UNKNOWN_FUNCTION(rfc_check_send_cmd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_801565f8;
  addi r3, r3, 0x18;
  bl GKI_enqueue;
  b lbl_801565f8;
lbl_801565dc:
  addi r3, r31, 0x18;
  bl GKI_dequeue;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_80156604;
  lhz r3, 0x68(r31);
  bl L2CA_DataWrite;
lbl_801565f8:
  lbz r0, 0x73(r31);
  cmpwi r0, 0;
  beq lbl_801565dc;
lbl_80156604:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
