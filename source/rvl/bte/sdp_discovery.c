#include "sdp_discovery.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "l2c_api.h"
#include "sdp_main.h"
#include "sdp_utils.h"

// Symbol: sdpu_build_uuid_seq
// PAL: 0x8015814c..0x80158238
MARK_BINARY_BLOB(sdpu_build_uuid_seq, 0x8015814c, 0x80158238);
asm UNKNOWN_FUNCTION(sdpu_build_uuid_seq) {
  // clang-format off
  nofralloc;
  li r0, 0x35;
  addi r11, r3, 1;
  mr r10, r11;
  stb r0, 0(r3);
  li r9, 0;
  li r6, 0x1c;
  li r7, 0x1a;
  li r8, 0x19;
  mtctr r4;
  cmplwi r4, 0;
  addi r11, r11, 1;
  ble lbl_80158224;
lbl_8015817c:
  lhz r0, 0(r5);
  cmplwi r0, 2;
  bne lbl_801581a8;
  stb r8, 0(r11);
  lhz r0, 4(r5);
  srawi r0, r0, 8;
  stb r0, 1(r11);
  lhz r0, 4(r5);
  stb r0, 2(r11);
  addi r11, r11, 3;
  b lbl_80158218;
lbl_801581a8:
  cmplwi r0, 4;
  bne lbl_801581e8;
  stb r7, 0(r11);
  lwz r0, 4(r5);
  srwi r0, r0, 0x18;
  stb r0, 1(r11);
  lwz r0, 4(r5);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 2(r11);
  lwz r0, 4(r5);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 3(r11);
  lwz r0, 4(r5);
  stb r0, 4(r11);
  addi r11, r11, 5;
  b lbl_80158218;
lbl_801581e8:
  stb r6, 0(r11);
  li r4, 0;
  addi r11, r11, 1;
  b lbl_8015820c;
lbl_801581f8:
  add r3, r5, r4;
  addi r4, r4, 1;
  lbz r0, 4(r3);
  stb r0, 0(r11);
  addi r11, r11, 1;
lbl_8015820c:
  lhz r0, 0(r5);
  cmpw r4, r0;
  blt lbl_801581f8;
lbl_80158218:
  addi r9, r9, 1;
  addi r5, r5, 0x14;
  bdnz lbl_8015817c;
lbl_80158224:
  subf r4, r10, r11;
  mr r3, r11;
  addi r0, r4, -1;
  stb r0, 0(r10);
  blr;
  // clang-format on
}

// Symbol: sdp_snd_service_search_req
// PAL: 0x80158238..0x80158368
MARK_BINARY_BLOB(sdp_snd_service_search_req, 0x80158238, 0x80158368);
asm UNKNOWN_FUNCTION(sdp_snd_service_search_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8015827c;
  mr r3, r26;
  li r4, 6;
  bl sdp_disconnect;
  b lbl_80158350;
lbl_8015827c:
  li r0, 9;
  addi r30, r3, 0x11;
  sth r0, 4(r3);
  li r0, 2;
  addi r31, r30, 3;
  stb r0, 0x11(r3);
  addi r3, r31, 2;
  lhz r0, 0x470(r26);
  srawi r0, r0, 8;
  stb r0, 1(r30);
  lhz r0, 0x470(r26);
  stb r0, 2(r30);
  lhz r4, 0x470(r26);
  lwz r6, 0x410(r26);
  addi r0, r4, 1;
  sth r0, 0x470(r26);
  addi r5, r6, 0x10;
  lhz r4, 0xc(r6);
  bl sdpu_build_uuid_seq;
  lis r4, 0x8034;
  cmpwi r27, 0;
  addi r4, r4, -24768;
  addi r25, r3, 3;
  lhz r0, 0x462e(r4);
  srawi r0, r0, 8;
  stb r0, 0(r3);
  lhz r0, 0x462e(r4);
  stb r0, 1(r3);
  stb r27, 2(r3);
  beq lbl_80158310;
  cmpwi r28, 0;
  beq lbl_80158310;
  mr r3, r25;
  mr r4, r28;
  mr r5, r27;
  bl memcpy;
  add r25, r25, r27;
lbl_80158310:
  subf r4, r31, r25;
  li r3, 1;
  addi r6, r4, -2;
  subf r0, r30, r25;
  rlwinm r5, r6, 0x18, 0x18, 0x1f;
  mr r4, r29;
  stb r5, 0(r31);
  stb r6, 1(r31);
  stb r3, 0x474(r26);
  sth r0, 2(r29);
  lhz r3, 0x22(r26);
  bl L2CA_DataWrite;
  addi r3, r26, 8;
  li r4, 5;
  li r5, 0x1e;
  bl btu_start_timer;
lbl_80158350:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: sdp_disc_connected
// PAL: 0x80158368..0x8015839c
MARK_BINARY_BLOB(sdp_disc_connected, 0x80158368, 0x8015839c);
asm UNKNOWN_FUNCTION(sdp_disc_connected) {
  // clang-format off
  nofralloc;
  lbz r0, 0x475(r3);
  cmpwi r0, 0;
  beq lbl_80158388;
  li r0, 3;
  li r4, 0;
  stb r0, 0x474(r3);
  li r5, 0;
  b process_service_search_attr_rsp;
lbl_80158388:
  li r0, 0;
  li r4, 0;
  sth r0, 0x46c(r3);
  li r5, 0;
  b sdp_snd_service_search_req;
  // clang-format on
}

// Symbol: sdp_disc_server_rsp
// PAL: 0x8015839c..0x801584dc
MARK_BINARY_BLOB(sdp_disc_server_rsp, 0x8015839c, 0x801584dc);
asm UNKNOWN_FUNCTION(sdp_disc_server_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 1;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  addi r3, r3, 8;
  bl btu_stop_timer;
  lhz r0, 4(r29);
  lhz r3, 2(r29);
  add r4, r29, r0;
  lbz r31, 8(r4);
  addi r5, r3, -1;
  cmpwi r31, 5;
  sth r5, 2(r29);
  beq lbl_8015842c;
  bge lbl_801583fc;
  cmpwi r31, 3;
  beq lbl_80158408;
  b lbl_80158470;
lbl_801583fc:
  cmpwi r31, 7;
  beq lbl_80158450;
  b lbl_80158470;
lbl_80158408:
  lbz r0, 0x474(r28);
  cmplwi r0, 1;
  bne lbl_80158470;
  mr r3, r28;
  addi r4, r4, 9;
  clrlwi r5, r5, 0x10;
  bl process_service_search_rsp;
  li r30, 0;
  b lbl_80158470;
lbl_8015842c:
  lbz r0, 0x474(r28);
  cmplwi r0, 2;
  bne lbl_80158470;
  mr r3, r28;
  addi r4, r4, 9;
  clrlwi r5, r5, 0x10;
  bl process_service_attr_rsp;
  li r30, 0;
  b lbl_80158470;
lbl_80158450:
  lbz r0, 0x474(r28);
  cmplwi r0, 3;
  bne lbl_80158470;
  mr r3, r28;
  addi r4, r4, 9;
  clrlwi r5, r5, 0x10;
  bl process_service_search_attr_rsp;
  li r30, 0;
lbl_80158470:
  cmpwi r30, 0;
  beq lbl_801584bc;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_801584a8;
  lis r3, 0xa;
  lis r4, 0x8028;
  lbz r6, 0x474(r28);
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x78a8;
  bl LogMsg_2;
lbl_801584a8:
  lis r4, 1;
  mr r3, r28;
  addi r0, r4, -13;
  clrlwi r4, r0, 0x10;
  bl sdp_disconnect;
lbl_801584bc:
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

// Symbol: process_service_search_rsp
// PAL: 0x801584dc..0x80158624
MARK_BINARY_BLOB(process_service_search_rsp, 0x801584dc, 0x80158624);
asm UNKNOWN_FUNCTION(process_service_search_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  addi r5, r4, 8;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r6, 6(r4);
  lbz r0, 7(r4);
  slwi r4, r6, 8;
  lhz r9, 0x46c(r3);
  add r0, r4, r0;
  clrlwi r0, r0, 0x10;
  add r0, r9, r0;
  clrlwi. r6, r0, 0x10;
  sth r0, 0x46c(r3);
  bne lbl_8015855c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158544;
  lis r3, 0xa;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x78d0;
  bl LogMsg_0;
lbl_80158544:
  lis r4, 1;
  mr r3, r31;
  addi r0, r4, -16;
  clrlwi r4, r0, 0x10;
  bl sdp_disconnect;
  b lbl_80158610;
lbl_8015855c:
  lis r4, 0x8034;
  addi r4, r4, -24768;
  lhz r0, 0x462e(r4);
  cmplw r6, r0;
  ble lbl_801585b4;
  sth r0, 0x46c(r3);
  b lbl_801585b4;
lbl_80158578:
  rlwinm r0, r9, 2, 0xe, 0x1d;
  lbz r7, 0(r5);
  lbz r6, 1(r5);
  add r4, r3, r0;
  lbz r0, 2(r5);
  slwi r8, r7, 0x18;
  lbz r7, 3(r5);
  slwi r6, r6, 0x10;
  slwi r0, r0, 8;
  addi r5, r5, 4;
  add r6, r8, r6;
  addi r9, r9, 1;
  add r0, r7, r0;
  add r0, r6, r0;
  stw r0, 0x418(r4);
lbl_801585b4:
  lhz r0, 0x46c(r3);
  clrlwi r4, r9, 0x10;
  cmplw r4, r0;
  blt lbl_80158578;
  lbz r4, 0(r5);
  cmpwi r4, 0;
  beq lbl_801585f8;
  cmplwi r4, 0x10;
  ble lbl_801585e8;
  mr r3, r31;
  li r4, 5;
  bl sdp_disconnect;
  b lbl_80158610;
lbl_801585e8:
  mr r3, r31;
  addi r5, r5, 1;
  bl sdp_snd_service_search_req;
  b lbl_80158610;
lbl_801585f8:
  li r0, 2;
  li r4, 0;
  stb r0, 0x474(r3);
  mr r3, r31;
  li r5, 0;
  bl process_service_attr_rsp;
lbl_80158610:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: process_service_attr_rsp
// PAL: 0x80158624..0x801588cc
MARK_BINARY_BLOB(process_service_attr_rsp, 0x80158624, 0x801588cc);
asm UNKNOWN_FUNCTION(process_service_attr_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r4, 0;
  mr r26, r3;
  mr r27, r4;
  li r29, 0;
  beq lbl_80158718;
  lbz r5, 4(r4);
  addi r27, r4, 6;
  lbz r0, 5(r4);
  slwi r4, r5, 8;
  lhz r5, 0x24(r3);
  add r0, r4, r0;
  clrlwi r25, r0, 0x10;
  add r0, r5, r25;
  cmpwi r0, 0x3e8;
  ble lbl_80158680;
  li r4, 4;
  bl sdp_disconnect;
  b lbl_801588b4;
lbl_80158680:
  add r3, r3, r5;
  mr r4, r27;
  mr r5, r25;
  addi r3, r3, 0x26;
  bl memcpy;
  lhz r0, 0x24(r26);
  add r0, r0, r25;
  sth r0, 0x24(r26);
  lbzux r3, r27, r25;
  cmpwi r3, 0;
  beq lbl_801586cc;
  cmplwi r3, 0x10;
  ble lbl_801586c4;
  mr r3, r26;
  li r4, 5;
  bl sdp_disconnect;
  b lbl_801588b4;
lbl_801586c4:
  li r29, 1;
  b lbl_80158718;
lbl_801586cc:
  clrlwi r0, r0, 0x10;
  mr r3, r26;
  add r5, r26, r0;
  addi r4, r26, 0x26;
  addi r5, r5, 0x26;
  bl save_attr_seq;
  cmpwi r3, 0;
  bne lbl_80158704;
  lis r4, 1;
  mr r3, r26;
  addi r0, r4, -12;
  clrlwi r4, r0, 0x10;
  bl sdp_disconnect;
  b lbl_801588b4;
lbl_80158704:
  lhz r3, 0x46e(r26);
  li r0, 0;
  sth r0, 0x24(r26);
  addi r0, r3, 1;
  sth r0, 0x46e(r26);
lbl_80158718:
  lhz r3, 0x46e(r26);
  lhz r0, 0x46c(r26);
  cmplw r3, r0;
  bge lbl_801588a8;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r28, r3;
  bne lbl_8015874c;
  mr r3, r26;
  li r4, 6;
  bl sdp_disconnect;
  b lbl_801588b4;
lbl_8015874c:
  li r0, 9;
  lis r4, 0x8034;
  sth r0, 4(r3);
  addi r31, r3, 0x11;
  li r0, 4;
  addi r4, r4, -24768;
  stb r0, 0(r31);
  addi r3, r31, 3;
  mr r30, r3;
  lhz r0, 0x470(r26);
  addi r3, r3, 8;
  srawi r0, r0, 8;
  stb r0, 1(r31);
  lhz r0, 0x470(r26);
  stb r0, 2(r31);
  lhz r5, 0x470(r26);
  lhz r0, 0x46e(r26);
  addi r5, r5, 1;
  slwi r0, r0, 2;
  sth r5, 0x470(r26);
  add r5, r26, r0;
  lwz r0, 0x418(r5);
  srwi r0, r0, 0x18;
  stb r0, 5(r31);
  lhz r0, 0x46e(r26);
  slwi r0, r0, 2;
  add r5, r26, r0;
  lwz r0, 0x418(r5);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 6(r31);
  lhz r0, 0x46e(r26);
  slwi r0, r0, 2;
  add r5, r26, r0;
  lwz r0, 0x418(r5);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 7(r31);
  lhz r0, 0x46e(r26);
  slwi r0, r0, 2;
  add r5, r26, r0;
  lwz r0, 0x418(r5);
  stb r0, 8(r31);
  lhz r0, 0x462c(r4);
  srawi r0, r0, 8;
  stb r0, 9(r31);
  lhz r0, 0x462c(r4);
  stb r0, 0xa(r31);
  lwz r4, 0x410(r26);
  lhz r5, 0x4c(r4);
  cmpwi r5, 0;
  beq lbl_80158824;
  addi r4, r4, 0x4e;
  bl sdpu_build_attrib_seq;
  mr r25, r3;
  b lbl_80158834;
lbl_80158824:
  li r4, 0;
  li r5, 0;
  bl sdpu_build_attrib_seq;
  mr r25, r3;
lbl_80158834:
  cmpwi r29, 0;
  beq lbl_80158860;
  lbz r5, 0(r27);
  mr r3, r25;
  mr r4, r27;
  addi r5, r5, 1;
  bl memcpy;
  lbz r0, 0(r27);
  add r3, r0, r25;
  addi r4, r3, 1;
  b lbl_8015886c;
lbl_80158860:
  li r0, 0;
  addi r4, r25, 1;
  stb r0, 0(r25);
lbl_8015886c:
  subf r3, r30, r4;
  subf r0, r31, r4;
  addi r5, r3, -2;
  mr r4, r28;
  rlwinm r3, r5, 0x18, 0x18, 0x1f;
  stb r3, 0(r30);
  stb r5, 1(r30);
  sth r0, 2(r28);
  lhz r3, 0x22(r26);
  bl L2CA_DataWrite;
  addi r3, r26, 8;
  li r4, 5;
  li r5, 0x1e;
  bl btu_start_timer;
  b lbl_801588b4;
lbl_801588a8:
  mr r3, r26;
  li r4, 0;
  bl sdp_disconnect;
lbl_801588b4:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: process_service_search_attr_rsp
// PAL: 0x801588cc..0x80158ba0
MARK_BINARY_BLOB(process_service_search_attr_rsp, 0x801588cc, 0x80158ba0);
asm UNKNOWN_FUNCTION(process_service_search_attr_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  cmpwi r4, 0;
  mr r27, r3;
  mr r28, r4;
  li r29, 0;
  beq lbl_80158970;
  lbz r5, 4(r4);
  addi r28, r4, 6;
  lbz r0, 5(r4);
  slwi r4, r5, 8;
  lhz r5, 0x24(r3);
  add r0, r4, r0;
  clrlwi r26, r0, 0x10;
  add r0, r5, r26;
  cmpwi r0, 0x3e8;
  ble lbl_80158928;
  li r4, 4;
  bl sdp_disconnect;
  b lbl_80158b88;
lbl_80158928:
  add r3, r3, r5;
  mr r4, r28;
  mr r5, r26;
  addi r3, r3, 0x26;
  bl memcpy;
  lhz r0, 0x24(r27);
  add r0, r0, r26;
  sth r0, 0x24(r27);
  lbzux r0, r28, r26;
  cmpwi r0, 0;
  beq lbl_80158970;
  cmplwi r0, 0x10;
  ble lbl_8015896c;
  mr r3, r27;
  li r4, 5;
  bl sdp_disconnect;
  b lbl_80158b88;
lbl_8015896c:
  li r29, 1;
lbl_80158970:
  cmpwi r29, 0;
  bne lbl_80158980;
  cmpwi r28, 0;
  bne lbl_80158abc;
lbl_80158980:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_801589a4;
  mr r3, r27;
  li r4, 6;
  bl sdp_disconnect;
  b lbl_80158b88;
lbl_801589a4:
  li r0, 9;
  addi r31, r3, 0x11;
  sth r0, 4(r3);
  li r0, 6;
  addi r29, r31, 3;
  stb r0, 0x11(r3);
  addi r3, r29, 2;
  lhz r0, 0x470(r27);
  srawi r0, r0, 8;
  stb r0, 1(r31);
  lhz r0, 0x470(r27);
  stb r0, 2(r31);
  lhz r4, 0x470(r27);
  lwz r6, 0x410(r27);
  addi r0, r4, 1;
  sth r0, 0x470(r27);
  addi r5, r6, 0x10;
  lhz r4, 0xc(r6);
  bl sdpu_build_uuid_seq;
  lis r4, 0x8034;
  addi r6, r3, 2;
  addi r4, r4, -24768;
  lhz r0, 0x462c(r4);
  srawi r0, r0, 8;
  stb r0, 0(r3);
  lhz r0, 0x462c(r4);
  stb r0, 1(r3);
  lwz r4, 0x410(r27);
  lhz r5, 0x4c(r4);
  cmpwi r5, 0;
  beq lbl_80158a34;
  mr r3, r6;
  addi r4, r4, 0x4e;
  bl sdpu_build_attrib_seq;
  mr r26, r3;
  b lbl_80158a48;
lbl_80158a34:
  mr r3, r6;
  li r4, 0;
  li r5, 0;
  bl sdpu_build_attrib_seq;
  mr r26, r3;
lbl_80158a48:
  cmpwi r28, 0;
  beq lbl_80158a74;
  lbz r5, 0(r28);
  mr r3, r26;
  mr r4, r28;
  addi r5, r5, 1;
  bl memcpy;
  lbz r0, 0(r28);
  add r3, r0, r26;
  addi r4, r3, 1;
  b lbl_80158a80;
lbl_80158a74:
  li r0, 0;
  addi r4, r26, 1;
  stb r0, 0(r26);
lbl_80158a80:
  subf r3, r29, r4;
  subf r0, r31, r4;
  addi r5, r3, -2;
  mr r4, r30;
  rlwinm r3, r5, 0x18, 0x18, 0x1f;
  stb r3, 0(r29);
  stb r5, 1(r29);
  sth r0, 2(r30);
  lhz r3, 0x22(r27);
  bl L2CA_DataWrite;
  addi r3, r27, 8;
  li r4, 5;
  li r5, 0x1e;
  bl btu_start_timer;
  b lbl_80158b88;
lbl_80158abc:
  lbz r5, 0x26(r27);
  addi r3, r27, 0x27;
  srawi r0, r5, 3;
  cmpwi r0, 6;
  beq lbl_80158afc;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158b88;
  lis r3, 0xa;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x78f8;
  bl LogMsg_1;
  b lbl_80158b88;
lbl_80158afc:
  mr r4, r5;
  addi r5, r1, 8;
  bl sdpu_get_len_from_type;
  lhz r5, 0x24(r27);
  mr r4, r3;
  lwz r0, 8(r1);
  add r5, r27, r5;
  addi r26, r5, 0x26;
  add r0, r3, r0;
  cmplw r0, r26;
  beq lbl_80158b74;
  mr r3, r27;
  li r4, 5;
  bl sdp_disconnect;
  b lbl_80158b88;
  b lbl_80158b74;
lbl_80158b3c:
  lhz r0, 0x24(r27);
  mr r3, r27;
  add r5, r27, r0;
  addi r5, r5, 0x26;
  bl save_attr_seq;
  cmpwi r3, 0;
  mr r4, r3;
  bne lbl_80158b74;
  lis r4, 1;
  mr r3, r27;
  addi r0, r4, -12;
  clrlwi r4, r0, 0x10;
  bl sdp_disconnect;
  b lbl_80158b88;
lbl_80158b74:
  cmplw r4, r26;
  blt lbl_80158b3c;
  mr r3, r27;
  li r4, 0;
  bl sdp_disconnect;
lbl_80158b88:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: save_attr_seq
// PAL: 0x80158ba0..0x80158d8c
MARK_BINARY_BLOB(save_attr_seq, 0x80158ba0, 0x80158d8c);
asm UNKNOWN_FUNCTION(save_attr_seq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  lbz r6, 0(r4);
  lis r31, 0x8028;
  mr r26, r3;
  mr r27, r5;
  srawi r0, r6, 3;
  addi r31, r31, 0x78a8;
  cmpwi r0, 6;
  addi r3, r4, 1;
  beq lbl_80158c08;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158c00;
  lis r3, 0xa;
  mr r5, r6;
  addi r3, r3, 1;
  addi r4, r31, 0x50;
  bl LogMsg_1;
lbl_80158c00:
  li r3, 0;
  b lbl_80158d74;
lbl_80158c08:
  mr r4, r6;
  addi r5, r1, 0xc;
  bl sdpu_get_len_from_type;
  lwz r5, 0xc(r1);
  mr r30, r3;
  add r0, r3, r5;
  cmplw r0, r27;
  ble lbl_80158c54;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158c4c;
  lis r3, 0xa;
  addi r4, r31, 0x78;
  addi r3, r3, 1;
  bl LogMsg_1;
lbl_80158c4c:
  li r3, 0;
  b lbl_80158d74;
lbl_80158c54:
  lwz r3, 0x410(r26);
  addi r4, r26, 2;
  bl add_record;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_80158c98;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158c90;
  lis r3, 0xa;
  addi r4, r31, 0x98;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80158c90:
  li r3, 0;
  b lbl_80158d74;
lbl_80158c98:
  lwz r0, 0xc(r1);
  add r28, r30, r0;
  b lbl_80158d68;
lbl_80158ca4:
  lbz r29, 0(r30);
  addi r3, r30, 1;
  addi r5, r1, 8;
  mr r4, r29;
  bl sdpu_get_len_from_type;
  rlwinm r0, r29, 0x1d, 0x1b, 0x1f;
  cmpwi r0, 1;
  bne lbl_80158cd0;
  lwz r0, 8(r1);
  cmplwi r0, 2;
  beq lbl_80158d04;
lbl_80158cd0:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158cfc;
  lis r3, 0xa;
  lwz r6, 8(r1);
  mr r5, r29;
  addi r4, r31, 0xa8;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80158cfc:
  li r3, 0;
  b lbl_80158d74;
lbl_80158d04:
  lbz r4, 0(r3);
  mr r5, r27;
  lbz r0, 1(r3);
  li r7, 0;
  slwi r6, r4, 8;
  lwz r4, 0x410(r26);
  add r0, r6, r0;
  li r8, 0;
  clrlwi r6, r0, 0x10;
  addi r3, r3, 2;
  bl add_attr;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80158d68;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80158d60;
  lis r3, 0xa;
  addi r4, r31, 0x98;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80158d60:
  li r3, 0;
  b lbl_80158d74;
lbl_80158d68:
  cmplw r30, r28;
  blt lbl_80158ca4;
  mr r3, r30;
lbl_80158d74:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: add_record
// PAL: 0x80158d8c..0x80158e2c
MARK_BINARY_BLOB(add_record, 0x80158d8c, 0x80158e2c);
asm UNKNOWN_FUNCTION(add_record) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r5, 4(r3);
  cmplwi r5, 0x14;
  bge lbl_80158db8;
  li r3, 0;
  b lbl_80158e14;
lbl_80158db8:
  lwz r31, 0x68(r3);
  addi r0, r5, -20;
  stw r0, 4(r3);
  li r0, 0;
  addi r6, r31, 0x14;
  li r5, 6;
  stw r6, 0x68(r3);
  addi r3, r31, 0xc;
  stw r0, 0(r31);
  stw r0, 4(r31);
  bl memcpy;
  lwz r3, 8(r30);
  cmpwi r3, 0;
  bne lbl_80158e00;
  stw r31, 8(r30);
  b lbl_80158e10;
  b lbl_80158e00;
lbl_80158dfc:
  mr r3, r0;
lbl_80158e00:
  lwz r0, 4(r3);
  cmpwi r0, 0;
  bne lbl_80158dfc;
  stw r31, 4(r3);
lbl_80158e10:
  mr r3, r31;
lbl_80158e14:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: add_attr
// PAL: 0x80158e2c..0x801593c4
MARK_BINARY_BLOB(add_attr, 0x80158e2c, 0x801593c4);
asm UNKNOWN_FUNCTION(add_attr) {
  // clang-format off
  nofralloc;
lbl_80158e2c:
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_21;
  lbz r21, 0(r3);
  lis r31, 0x8028;
  mr r23, r4;
  mr r24, r5;
  mr r25, r6;
  mr r26, r7;
  mr r4, r21;
  addi r31, r31, 0x78a8;
  rlwinm r28, r8, 0, 0x18, 0x18;
  clrlwi r27, r8, 0x19;
  addi r5, r1, 8;
  addi r3, r3, 1;
  bl sdpu_get_len_from_type;
  lwz r0, 8(r1);
  mr r22, r3;
  rlwinm r6, r21, 0x1d, 0x1c, 0x1f;
  li r4, 0xc;
  clrlwi r5, r0, 0x14;
  cmplwi r5, 4;
  stw r5, 8(r1);
  ble lbl_80158e98;
  addi r4, r5, 8;
lbl_80158e98:
  addi r4, r4, 3;
  lwz r0, 4(r23);
  rlwinm r30, r4, 0, 0, 0x1d;
  cmplw r0, r30;
  bge lbl_80158eb4;
  li r3, 0;
  b lbl_801593ac;
lbl_80158eb4:
  lwz r29, 0x68(r23);
  rlwinm r0, r6, 0xc, 4, 0x13;
  cmplwi r6, 8;
  li r4, 0;
  sth r25, 4(r29);
  lwz r5, 8(r1);
  clrlwi r5, r5, 0x10;
  or r5, r5, r0;
  sth r5, 6(r29);
  stw r4, 0(r29);
  bgt lbl_8015932c;
  lis r5, 0x8028;
  slwi r4, r6, 2;
  addi r5, r5, 0x79e0;
  lwzx r5, r5, r4;
  mtctr r5;
  bctr;
  cmpwi r28, 0;
  beq lbl_80158fa8;
  lwz r0, 8(r1);
  cmplwi r0, 2;
  bne lbl_80158fa8;
  lbz r4, 0(r3);
  lbz r0, 1(r3);
  slwi r4, r4, 8;
  add r0, r4, r0;
  clrlwi r0, r0, 0x10;
  cmplwi r0, 4;
  bne lbl_80158fa8;
  lwz r5, 0x68(r23);
  cmplwi r27, 5;
  lwz r4, 4(r23);
  li r30, 0;
  addi r5, r5, 0xc;
  addi r0, r4, -12;
  stw r5, 0x68(r23);
  stw r0, 4(r23);
  lwz r0, 8(r1);
  add r4, r3, r0;
  addi r21, r4, 2;
  blt lbl_80158f80;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_80158f78;
  addi r4, r31, 0xd8;
  lis r3, 0xa;
  bl LogMsg_0;
lbl_80158f78:
  mr r3, r21;
  b lbl_801593ac;
lbl_80158f80:
  addi r0, r27, 1;
  mr r4, r23;
  mr r5, r24;
  mr r7, r29;
  clrlwi r8, r0, 0x18;
  li r6, 4;
  addi r3, r3, 2;
  bl lbl_80158e2c;
  mr r22, r3;
  b lbl_8015932c;
lbl_80158fa8:
  lwz r0, 8(r1);
  cmpwi r0, 3;
  beq lbl_80159034;
  bge lbl_80158fc8;
  cmpwi r0, 1;
  beq lbl_80158fd4;
  bge lbl_80158fe4;
  b lbl_80159034;
lbl_80158fc8:
  cmpwi r0, 5;
  bge lbl_80159034;
  b lbl_80159000;
lbl_80158fd4:
  lbz r0, 0(r3);
  addi r22, r3, 1;
  stb r0, 8(r29);
  b lbl_8015932c;
lbl_80158fe4:
  lbz r4, 0(r3);
  addi r22, r3, 2;
  lbz r0, 1(r3);
  slwi r3, r4, 8;
  add r0, r3, r0;
  sth r0, 8(r29);
  b lbl_8015932c;
lbl_80159000:
  lbz r5, 0(r3);
  addi r22, r3, 4;
  lbz r0, 2(r3);
  lbz r4, 1(r3);
  slwi r6, r5, 0x18;
  slwi r0, r0, 8;
  slwi r5, r4, 0x10;
  lbz r4, 3(r3);
  add r3, r6, r5;
  add r0, r4, r0;
  add r0, r3, r0;
  stw r0, 8(r29);
  b lbl_8015932c;
lbl_80159034:
  addi r3, r29, 8;
  li r4, 0;
  b lbl_80159054;
lbl_80159040:
  lbz r0, 0(r22);
  addi r4, r4, 1;
  addi r22, r22, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_80159054:
  lwz r0, 8(r1);
  cmpw r4, r0;
  blt lbl_80159040;
  b lbl_8015932c;
  lwz r5, 8(r1);
  cmpwi r5, 4;
  beq lbl_801590a8;
  bge lbl_80159080;
  cmpwi r5, 2;
  beq lbl_8015908c;
  b lbl_801591c8;
lbl_80159080:
  cmpwi r5, 0x10;
  beq lbl_80159100;
  b lbl_801591c8;
lbl_8015908c:
  lbz r4, 0(r3);
  addi r22, r3, 2;
  lbz r0, 1(r3);
  slwi r3, r4, 8;
  add r0, r3, r0;
  sth r0, 8(r29);
  b lbl_8015932c;
lbl_801590a8:
  lbz r7, 0(r3);
  addi r22, r3, 4;
  lbz r6, 1(r3);
  lis r4, 1;
  slwi r8, r7, 0x18;
  lbz r5, 2(r3);
  slwi r7, r6, 0x10;
  lbz r6, 3(r3);
  slwi r3, r5, 8;
  add r5, r8, r7;
  add r3, r6, r3;
  add r3, r5, r3;
  cmplw r3, r4;
  stw r3, 8(r29);
  bge lbl_8015932c;
  li r3, 2;
  ori r0, r0, 2;
  stw r3, 8(r1);
  sth r0, 6(r29);
  lwz r0, 8(r29);
  sth r0, 8(r29);
  b lbl_8015932c;
lbl_80159100:
  mr r3, r22;
  bl sdpu_is_base_uuid;
  clrlwi. r0, r3, 0x18;
  beq lbl_80159198;
  lbz r0, 0(r22);
  cmpwi r0, 0;
  bne lbl_80159154;
  lbz r0, 1(r22);
  cmpwi r0, 0;
  bne lbl_80159154;
  lhz r0, 6(r29);
  rlwinm r0, r0, 0, 0, 0x13;
  ori r0, r0, 2;
  sth r0, 6(r29);
  lbz r3, 2(r22);
  lbz r0, 3(r22);
  addi r22, r22, 0x10;
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 8(r29);
  b lbl_8015932c;
lbl_80159154:
  lhz r0, 6(r29);
  rlwinm r0, r0, 0, 0, 0x13;
  ori r0, r0, 4;
  sth r0, 6(r29);
  lbz r4, 0(r22);
  lbz r3, 1(r22);
  lbz r0, 2(r22);
  slwi r5, r4, 0x18;
  lbz r4, 3(r22);
  slwi r3, r3, 0x10;
  slwi r0, r0, 8;
  addi r22, r22, 0x10;
  add r3, r5, r3;
  add r0, r4, r0;
  add r0, r3, r0;
  stw r0, 8(r29);
  b lbl_8015932c;
lbl_80159198:
  addi r3, r29, 8;
  li r4, 0;
  b lbl_801591b8;
lbl_801591a4:
  lbz r0, 0(r22);
  addi r4, r4, 1;
  addi r22, r22, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_801591b8:
  lwz r0, 8(r1);
  cmpw r4, r0;
  blt lbl_801591a4;
  b lbl_8015932c;
lbl_801591c8:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_801591ec;
  lis r3, 0xa;
  addi r4, r31, 0xf4;
  addi r3, r3, 1;
  bl LogMsg_1;
lbl_801591ec:
  lwz r0, 8(r1);
  add r3, r22, r0;
  b lbl_801593ac;
  lwz r5, 0x68(r23);
  cmplwi r27, 5;
  lwz r4, 4(r23);
  li r30, 0;
  addi r5, r5, 0xc;
  addi r0, r4, -12;
  stw r5, 0x68(r23);
  stw r0, 4(r23);
  lwz r0, 8(r1);
  add r21, r3, r0;
  blt lbl_8015924c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_80159244;
  addi r4, r31, 0xd8;
  lis r3, 0xa;
  bl LogMsg_0;
lbl_80159244:
  mr r3, r21;
  b lbl_801593ac;
lbl_8015924c:
  cmpwi r28, 0;
  bne lbl_8015925c;
  cmplwi r25, 0xd;
  bne lbl_80159264;
lbl_8015925c:
  ori r0, r27, 0x80;
  clrlwi r27, r0, 0x18;
lbl_80159264:
  clrlwi r3, r27, 0x18;
  addi r25, r3, 1;
  b lbl_801592a0;
lbl_80159270:
  mr r3, r22;
  mr r4, r23;
  mr r5, r24;
  mr r7, r29;
  clrlwi r8, r25, 0x18;
  li r6, 0;
  bl lbl_80158e2c;
  cmpwi r3, 0;
  mr r22, r3;
  bne lbl_801592a0;
  li r3, 0;
  b lbl_801593ac;
lbl_801592a0:
  cmplw r22, r21;
  blt lbl_80159270;
  b lbl_8015932c;
  addi r3, r29, 8;
  li r4, 0;
  b lbl_801592cc;
lbl_801592b8:
  lbz r0, 0(r22);
  addi r4, r4, 1;
  addi r22, r22, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_801592cc:
  lwz r0, 8(r1);
  cmpw r4, r0;
  blt lbl_801592b8;
  b lbl_8015932c;
  lwz r5, 8(r1);
  cmpwi r5, 1;
  beq lbl_801592ec;
  b lbl_801592fc;
lbl_801592ec:
  lbz r0, 0(r3);
  addi r22, r3, 1;
  stb r0, 8(r29);
  b lbl_8015932c;
lbl_801592fc:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159320;
  lis r3, 0xa;
  addi r4, r31, 0x114;
  addi r3, r3, 1;
  bl LogMsg_1;
lbl_80159320:
  lwz r0, 8(r1);
  add r3, r22, r0;
  b lbl_801593ac;
lbl_8015932c:
  lwz r3, 0x68(r23);
  cmpwi r26, 0;
  lwz r0, 4(r23);
  add r3, r3, r30;
  subf r0, r30, r0;
  stw r3, 0x68(r23);
  stw r0, 4(r23);
  bne lbl_8015937c;
  lwz r3, 0(r24);
  cmpwi r3, 0;
  bne lbl_80159368;
  stw r29, 0(r24);
  b lbl_801593a8;
  b lbl_80159368;
lbl_80159364:
  mr r3, r0;
lbl_80159368:
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_80159364;
  stw r29, 0(r3);
  b lbl_801593a8;
lbl_8015937c:
  lwz r3, 8(r26);
  cmpwi r3, 0;
  bne lbl_80159398;
  stw r29, 8(r26);
  b lbl_801593a8;
  b lbl_80159398;
lbl_80159394:
  mr r3, r0;
lbl_80159398:
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_80159394;
  stw r29, 0(r3);
lbl_801593a8:
  mr r3, r22;
lbl_801593ac:
  addi r11, r1, 0x40;
  bl _restgpr_21;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}
