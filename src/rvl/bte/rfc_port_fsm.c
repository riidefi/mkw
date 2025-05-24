#include "rfc_port_fsm.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_sec.h"
#include "port_rfc.h"
#include "port_utils.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: rfc_port_sm_execute
// PAL: 0x80153124..0x801531b4
MARK_BINARY_BLOB(rfc_port_sm_execute, 0x80153124, 0x801531b4);
asm UNKNOWN_FUNCTION(rfc_port_sm_execute) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  mr r6, r4;
  bne lbl_80153160;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  bltlr;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r6;
  addi r3, r3, 1;
  addi r4, r4, 0x7330;
  b LogMsg_1;
  blr;
lbl_80153160:
  lbz r0, 0x68(r3);
  cmpwi r0, 3;
  beq lbl_801531a4;
  bge lbl_80153188;
  cmpwi r0, 1;
  beq lbl_8015319c;
  bge lbl_801531a0;
  cmpwi r0, 0;
  bge lbl_80153198;
  blr;
lbl_80153188:
  cmpwi r0, 5;
  beq lbl_801531ac;
  bgelr;
  b lbl_801531a8;
lbl_80153198:
  b rfc_port_sm_state_closed;
lbl_8015319c:
  b rfc_port_sm_sabme_wait_ua;
lbl_801531a0:
  b rfc_port_sm_orig_wait_sec_check;
lbl_801531a4:
  b rfc_port_sm_term_wait_sec_check;
lbl_801531a8:
  b rfc_port_sm_opened;
lbl_801531ac:
  b rfc_port_sm_disc_wait_ua;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_state_closed
// PAL: 0x801531b4..0x80153328
MARK_BINARY_BLOB(rfc_port_sm_state_closed, 0x801531b4, 0x80153328);
asm UNKNOWN_FUNCTION(rfc_port_sm_state_closed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r4, 0xe;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bgt lbl_801532e4;
  lis r6, 0x8028;
  slwi r0, r4, 2;
  addi r6, r6, 0x7388;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lbz r0, 0xd(r30);
  li r5, 2;
  lis r8, 0x8015;
  stb r5, 0x68(r3);
  lwz r4, 0x6c(r3);
  mr r9, r30;
  srwi r7, r0, 1;
  addi r8, r8, 0x6340;
  addi r3, r4, 0x62;
  li r4, 3;
  li r5, 1;
  li r6, 3;
  bl btm_sec_mx_access_request;
  b lbl_80153310;
  b lbl_80153310;
  mr r3, r5;
  bl GKI_freebuf;
  b lbl_801532e4;
  lbz r0, 0xd(r30);
  li r5, 3;
  lis r8, 0x8015;
  stb r5, 0x68(r3);
  lwz r4, 0x6c(r3);
  mr r9, r30;
  srwi r7, r0, 1;
  addi r8, r8, 0x6340;
  addi r3, r4, 0x62;
  li r4, 3;
  li r5, 0;
  li r6, 3;
  bl btm_sec_mx_access_request;
  b lbl_80153310;
  b lbl_80153310;
  bl rfc_port_closed;
  b lbl_80153310;
  mr r3, r5;
  bl GKI_freebuf;
  lwz r3, 0x6c(r30);
  li r5, 0;
  lbz r4, 0xd(r30);
  bl rfc_send_dm;
  b lbl_80153310;
  lwz r3, 0x6c(r3);
  li r5, 0;
  lbz r4, 0xd(r30);
  bl rfc_send_dm;
  b lbl_80153310;
  lwz r3, 0x6c(r3);
  bl Port_TimeOutCloseMux;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80153310;
  lis r4, 0x8028;
  lbz r5, 0x68(r30);
  mr r6, r31;
  lis r3, 9;
  addi r4, r4, 0x7344;
  bl LogMsg_2;
  b lbl_80153310;
lbl_801532e4:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80153310;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x7364;
  bl LogMsg_1;
lbl_80153310:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_sabme_wait_ua
// PAL: 0x80153328..0x801534c4
MARK_BINARY_BLOB(rfc_port_sm_sabme_wait_ua, 0x80153328, 0x801534c4);
asm UNKNOWN_FUNCTION(rfc_port_sm_sabme_wait_ua) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r4, 0xe;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bgt lbl_80153480;
  lis r6, 0x8028;
  slwi r0, r4, 2;
  addi r6, r6, 0x73f0;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801534ac;
  lis r4, 0x8028;
  lbz r5, 0x68(r30);
  mr r6, r31;
  lis r3, 9;
  addi r4, r4, 0x7344;
  bl LogMsg_2;
  b lbl_801534ac;
  li r4, 3;
  bl rfc_port_timer_start;
  lwz r3, 0x6c(r30);
  lbz r4, 0xd(r30);
  bl rfc_send_disc;
  li r3, 0;
  li r0, 5;
  stb r3, 0x69(r30);
  stb r0, 0x68(r30);
  b lbl_801534ac;
  bl rfc_port_closed;
  b lbl_801534ac;
  mr r3, r5;
  bl GKI_freebuf;
  b lbl_80153480;
  bl rfc_port_timer_stop;
  li r0, 4;
  lwz r3, 0x6c(r30);
  stb r0, 0x68(r30);
  li r6, 0;
  lbz r4, 0xd(r30);
  lhz r5, 0x6a(r3);
  bl PORT_DlcEstablishCnf;
  b lbl_801534ac;
  lwz r3, 0x6c(r3);
  li r6, 1;
  lbz r4, 0xd(r30);
  lhz r5, 0x6a(r3);
  bl PORT_DlcEstablishCnf;
  mr r3, r30;
  bl rfc_port_closed;
  b lbl_801534ac;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r30);
  bl rfc_send_ua;
  lwz r3, 0x6c(r30);
  li r6, 1;
  lbz r4, 0xd(r30);
  lhz r5, 0x6a(r3);
  bl PORT_DlcEstablishCnf;
  mr r3, r30;
  bl rfc_port_closed;
  b lbl_801534ac;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r30);
  bl rfc_send_ua;
  b lbl_801534ac;
  mr r3, r5;
  bl GKI_freebuf;
  b lbl_801534ac;
  li r0, 0;
  lwz r5, 0x6c(r3);
  stb r0, 0x68(r3);
  li r6, 1;
  mr r3, r5;
  lbz r4, 0xd(r30);
  lhz r5, 0x6a(r5);
  bl PORT_DlcEstablishCnf;
  b lbl_801534ac;
lbl_80153480:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_801534ac;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x73c4;
  bl LogMsg_1;
lbl_801534ac:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_term_wait_sec_check
// PAL: 0x801534c4..0x80153680
MARK_BINARY_BLOB(rfc_port_sm_term_wait_sec_check, 0x801534c4, 0x80153680);
asm UNKNOWN_FUNCTION(rfc_port_sm_term_wait_sec_check) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8028;
  cmplwi r4, 0xf;
  stw r0, 0x14(r1);
  addi r7, r7, 0x7330;
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  bgt lbl_80153640;
  lis r6, 0x8028;
  slwi r0, r4, 2;
  addi r6, r6, 0x7488;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lbz r0, 0(r5);
  cmpwi r0, 0;
  beq lbl_8015353c;
  lwz r3, 0x6c(r3);
  cmpwi r3, 0;
  beq lbl_80153668;
  lbz r4, 0xd(r30);
  li r5, 1;
  bl rfc_send_dm;
  mr r3, r30;
  li r4, 0xf;
  bl port_rfc_closed;
  b lbl_80153668;
lbl_8015353c:
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r30);
  lhz r5, 0x6a(r3);
  bl PORT_DlcEstablishInd;
  b lbl_80153668;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80153668;
  lbz r5, 0x68(r30);
  mr r6, r4;
  addi r4, r7, 0x14;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_80153668;
  lwz r3, 0x6c(r3);
  addi r3, r3, 0x62;
  bl btm_sec_abort_access_req;
  mr r3, r30;
  bl rfc_port_closed;
  b lbl_80153668;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801535b4;
  addi r4, r7, 0xfc;
  lis r3, 9;
  bl LogMsg_0;
lbl_801535b4:
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80153668;
  b lbl_80153668;
  lwz r3, 0x6c(r3);
  addi r3, r3, 0x62;
  bl btm_sec_abort_access_req;
  li r0, 0;
  lwz r3, 0x6c(r30);
  stb r0, 0x68(r30);
  lbz r4, 0xd(r30);
  bl rfc_send_ua;
  lwz r3, 0x6c(r30);
  lbz r4, 0xd(r30);
  bl PORT_DlcReleaseInd;
  b lbl_80153668;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80153668;
  lbz r0, 0(r5);
  cmpwi r0, 0;
  beq lbl_80153628;
  lwz r3, 0x6c(r3);
  cmpwi r3, 0;
  beq lbl_80153668;
  lbz r4, 0xd(r30);
  li r5, 1;
  bl rfc_send_dm;
  b lbl_80153668;
lbl_80153628:
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r30);
  bl rfc_send_ua;
  li r0, 4;
  stb r0, 0x68(r30);
  b lbl_80153668;
lbl_80153640:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80153668;
  lis r3, 9;
  mr r5, r4;
  addi r3, r3, 1;
  addi r4, r7, 0x128;
  bl LogMsg_1;
lbl_80153668:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_orig_wait_sec_check
// PAL: 0x80153680..0x801537d0
MARK_BINARY_BLOB(rfc_port_sm_orig_wait_sec_check, 0x80153680, 0x801537d0);
asm UNKNOWN_FUNCTION(rfc_port_sm_orig_wait_sec_check) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8028;
  cmplwi r4, 0xf;
  stw r0, 0x14(r1);
  addi r7, r7, 0x7330;
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  bgt lbl_80153790;
  lis r6, 0x8028;
  slwi r0, r4, 2;
  addi r6, r6, 0x7528;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lbz r0, 0(r5);
  cmpwi r0, 0;
  beq lbl_801536f0;
  lwz r3, 0x6c(r3);
  li r5, 0;
  lbz r4, 0xd(r30);
  li r6, 0x70;
  bl PORT_DlcEstablishCnf;
  mr r3, r30;
  bl rfc_port_closed;
  b lbl_801537b8;
lbl_801536f0:
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r30);
  bl rfc_send_sabme;
  mr r3, r30;
  li r4, 0x3c;
  bl rfc_port_timer_start;
  li r0, 1;
  stb r0, 0x68(r30);
  b lbl_801537b8;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801537b8;
  lbz r5, 0x68(r30);
  mr r6, r4;
  addi r4, r7, 0x14;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_801537b8;
  lwz r3, 0x6c(r3);
  addi r3, r3, 0x62;
  bl btm_sec_abort_access_req;
  mr r3, r30;
  bl rfc_port_closed;
  b lbl_801537b8;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80153778;
  addi r4, r7, 0x198;
  lis r3, 9;
  bl LogMsg_0;
lbl_80153778:
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_801537b8;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_801537b8;
lbl_80153790:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_801537b8;
  lis r3, 9;
  mr r5, r4;
  addi r3, r3, 1;
  addi r4, r7, 0x1c8;
  bl LogMsg_1;
lbl_801537b8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_opened
// PAL: 0x801537d0..0x801539bc
MARK_BINARY_BLOB(rfc_port_sm_opened, 0x801537d0, 0x801539bc);
asm UNKNOWN_FUNCTION(rfc_port_sm_opened) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r4, 0xe;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  mr r30, r4;
  bgt lbl_80153978;
  lis r6, 0x8028;
  slwi r0, r4, 2;
  addi r6, r6, 0x758c;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801539a4;
  lis r4, 0x8028;
  lbz r5, 0x68(r31);
  mr r6, r30;
  lis r3, 9;
  addi r4, r4, 0x7344;
  bl LogMsg_2;
  b lbl_801539a4;
  li r4, 3;
  bl rfc_port_timer_start;
  lwz r3, 0x6c(r31);
  lbz r4, 0xd(r31);
  bl rfc_send_disc;
  li r3, 0;
  li r0, 5;
  stb r3, 0x69(r31);
  stb r0, 0x68(r31);
  b lbl_801539a4;
  bl rfc_port_closed;
  b lbl_801539a4;
  lwz r4, 0x6c(r3);
  lbz r0, 0x72(r4);
  cmplwi r0, 2;
  bne lbl_801538c0;
  lhz r4, 2(r5);
  lhz r0, 0x14(r3);
  cmplw r4, r0;
  bge lbl_801538c0;
  lbz r0, 0x3d(r3);
  cmpwi r0, 0;
  bne lbl_801538c0;
  lhz r0, 0x9a(r3);
  lhz r4, 0x9c(r3);
  cmplw r4, r0;
  ble lbl_801538c0;
  subf r0, r0, r4;
  clrlwi r0, r0, 0x18;
  sth r0, 6(r5);
  lhz r0, 0x9c(r3);
  sth r0, 0x9a(r3);
  b lbl_801538c8;
lbl_801538c0:
  li r0, 0;
  sth r0, 6(r5);
lbl_801538c8:
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r31);
  bl rfc_send_buf_uih;
  mr r3, r31;
  bl rfc_dec_credit;
  b lbl_801539a4;
  b lbl_801539a4;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r31);
  bl rfc_send_ua;
  b lbl_801539a4;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r31);
  bl PORT_DlcReleaseInd;
  mr r3, r31;
  bl rfc_port_closed;
  b lbl_801539a4;
  li r0, 0;
  lbz r4, 0xd(r31);
  stb r0, 0x68(r3);
  lwz r3, 0x6c(r3);
  bl rfc_send_ua;
  lwz r3, 0x6c(r31);
  lbz r4, 0xd(r31);
  bl PORT_DlcReleaseInd;
  b lbl_801539a4;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r31);
  bl PORT_DataInd;
  b lbl_801539a4;
  lwz r3, 0x6c(r3);
  bl Port_TimeOutCloseMux;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801539a4;
  lis r4, 0x8028;
  lbz r5, 0x68(r31);
  mr r6, r30;
  lis r3, 9;
  addi r4, r4, 0x7344;
  bl LogMsg_2;
  b lbl_801539a4;
lbl_80153978:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_801539a4;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x7568;
  bl LogMsg_1;
lbl_801539a4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_port_sm_disc_wait_ua
// PAL: 0x801539bc..0x80153ad8
MARK_BINARY_BLOB(rfc_port_sm_disc_wait_ua, 0x801539bc, 0x80153ad8);
asm UNKNOWN_FUNCTION(rfc_port_sm_disc_wait_ua) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r4, 0xe;
  mr r6, r4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bgt lbl_80153a98;
  lis r7, 0x8028;
  slwi r0, r4, 2;
  addi r7, r7, 0x75f4;
  lwzx r7, r7, r0;
  mtctr r7;
  bctr;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80153ac4;
  lis r4, 0x8028;
  lbz r5, 0x68(r31);
  lis r3, 9;
  addi r4, r4, 0x7344;
  bl LogMsg_2;
  b lbl_80153ac4;
  bl rfc_port_closed;
  b lbl_80153ac4;
  mr r3, r5;
  bl GKI_freebuf;
  b lbl_80153ac4;
  lwz r3, 0x6c(r3);
  li r0, 1;
  stb r0, 0x74(r3);
  mr r3, r31;
  bl rfc_port_closed;
  b lbl_80153ac4;
  lwz r3, 0x6c(r3);
  li r5, 1;
  lbz r4, 0xd(r31);
  bl rfc_send_dm;
  b lbl_80153ac4;
  lwz r3, 0x6c(r3);
  li r5, 1;
  lbz r4, 0xd(r31);
  bl rfc_send_dm;
  b lbl_80153ac4;
  mr r3, r5;
  bl GKI_freebuf;
  lwz r3, 0x6c(r31);
  li r5, 0;
  lbz r4, 0xd(r31);
  bl rfc_send_dm;
  b lbl_80153ac4;
  bl rfc_port_closed;
  b lbl_80153ac4;
lbl_80153a98:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80153ac4;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r6;
  addi r3, r3, 1;
  addi r4, r4, 0x75c8;
  bl LogMsg_1;
lbl_80153ac4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_process_pn
// PAL: 0x80153ad8..0x80153bc0
MARK_BINARY_BLOB(rfc_process_pn, 0x80153ad8, 0x80153bc0);
asm UNKNOWN_FUNCTION(rfc_process_pn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r31, 0(r5);
  beq lbl_80153b60;
  lbz r0, 0x6c(r3);
  cmplwi r0, 6;
  beq lbl_80153b28;
  lhz r5, 0xe(r5);
  mr r4, r31;
  lbz r6, 0xa(r30);
  lbz r7, 0x11(r30);
  bl PORT_ParNegInd;
  b lbl_80153ba4;
lbl_80153b28:
  mr r4, r31;
  li r5, 0;
  bl rfc_send_dm;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80153ba4;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x7630;
  bl LogMsg_0;
  b lbl_80153ba4;
lbl_80153b60:
  mr r4, r31;
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  beq lbl_80153ba4;
  lbz r4, 0x69(r3);
  clrlwi. r0, r4, 0x1f;
  bne lbl_80153b80;
  b lbl_80153ba4;
lbl_80153b80:
  rlwinm r0, r4, 0, 0x18, 0x1e;
  stb r0, 0x69(r3);
  bl rfc_port_timer_stop;
  lhz r5, 0xe(r30);
  mr r3, r29;
  lbz r6, 0xa(r30);
  mr r4, r31;
  lbz r7, 0x11(r30);
  bl PORT_ParNegCnf;
lbl_80153ba4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_process_rpn
// PAL: 0x80153bc0..0x80153ecc
MARK_BINARY_BLOB(rfc_process_rpn, 0x80153bc0, 0x80153ecc);
asm UNKNOWN_FUNCTION(rfc_process_rpn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r6;
  stw r29, 0x24(r1);
  mr r29, r3;
  stw r28, 0x20(r1);
  mr r28, r4;
  lbz r4, 0(r6);
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  bne lbl_80153c38;
  cmpwi r28, 0;
  beq lbl_80153eac;
  addi r3, r1, 8;
  li r4, 0;
  li r5, 9;
  bl memset;
  mr r4, r30;
  addi r3, r1, 8;
  bl rfc_set_port_state;
  lbz r4, 0(r30);
  mr r3, r29;
  lhz r6, 0x12(r30);
  addi r5, r1, 8;
  bl PORT_PortNegInd;
  b lbl_80153eac;
lbl_80153c38:
  cmpwi r28, 0;
  beq lbl_80153cac;
  cmpwi r31, 0;
  beq lbl_80153cac;
  lbz r4, 0x51(r3);
  addi r6, r3, 0x51;
  lbz r0, 0x52(r3);
  li r5, 0;
  li r7, 0;
  stb r4, 8(r1);
  stb r0, 9(r1);
  lbz r4, 0x53(r3);
  lbz r0, 0x54(r3);
  stb r4, 0xa(r1);
  stb r0, 0xb(r1);
  lbz r4, 0x55(r3);
  lbz r0, 0x56(r3);
  stb r4, 0xc(r1);
  stb r0, 0xd(r1);
  lbz r4, 0x57(r3);
  lbz r0, 0x58(r3);
  stb r4, 0xe(r1);
  stb r0, 0xf(r1);
  lbz r0, 0x59(r3);
  mr r3, r29;
  stb r0, 0x10(r1);
  lbz r4, 0(r30);
  bl rfc_send_rpn;
  b lbl_80153eac;
lbl_80153cac:
  lbz r5, 0x51(r3);
  mr r4, r30;
  lbz r0, 0x52(r3);
  stb r5, 8(r1);
  stb r0, 9(r1);
  lbz r5, 0x53(r3);
  lbz r0, 0x54(r3);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  lbz r5, 0x55(r3);
  lbz r0, 0x56(r3);
  stb r5, 0xc(r1);
  stb r0, 0xd(r1);
  lbz r5, 0x57(r3);
  lbz r0, 0x58(r3);
  stb r5, 0xe(r1);
  stb r0, 0xf(r1);
  lbz r0, 0x59(r3);
  addi r3, r1, 8;
  stb r0, 0x10(r1);
  bl rfc_set_port_state;
  cmpwi r28, 0;
  beq lbl_80153d20;
  lbz r4, 0(r30);
  mr r3, r29;
  lhz r6, 0x12(r30);
  addi r5, r1, 8;
  bl PORT_PortNegInd;
  b lbl_80153eac;
lbl_80153d20:
  lbz r4, 0(r30);
  mr r3, r29;
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80153eac;
  lbz r0, 0x69(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1e;
  bne lbl_80153d48;
  b lbl_80153eac;
lbl_80153d48:
  bl rfc_port_timer_stop;
  lbz r3, 0x69(r31);
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  beq lbl_80153e04;
  rlwinm r0, r3, 0, 0x1f, 0x1d;
  stb r0, 0x69(r31);
  lbz r3, 8(r1);
  lbz r0, 9(r1);
  stb r3, 0x51(r31);
  stb r0, 0x52(r31);
  lbz r3, 0xa(r1);
  lbz r0, 0xb(r1);
  stb r3, 0x53(r31);
  stb r0, 0x54(r31);
  lbz r3, 0xc(r1);
  lbz r0, 0xd(r1);
  stb r3, 0x55(r31);
  stb r0, 0x56(r31);
  lbz r3, 0xe(r1);
  lbz r0, 0xf(r1);
  stb r3, 0x57(r31);
  stb r0, 0x58(r31);
  lbz r0, 0x10(r1);
  stb r0, 0x59(r31);
  lbz r0, 0xd(r1);
  cmplwi r0, 0xc;
  beq lbl_80153dbc;
  cmplwi r0, 0x30;
  bne lbl_80153dc8;
lbl_80153dbc:
  li r0, 0x3f7f;
  sth r0, 0x12(r30);
  b lbl_80153e0c;
lbl_80153dc8:
  li r0, 0xc;
  mr r3, r29;
  stb r0, 0x56(r31);
  addi r6, r31, 0x51;
  li r5, 1;
  li r7, 0xc00;
  lbz r0, 0x69(r31);
  ori r0, r0, 4;
  stb r0, 0x69(r31);
  lbz r4, 0(r30);
  bl rfc_send_rpn;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
  b lbl_80153eac;
lbl_80153e04:
  rlwinm r0, r3, 0, 0x1e, 0x1c;
  stb r0, 0x69(r31);
lbl_80153e0c:
  lhz r3, 0x12(r30);
  rlwinm r0, r3, 0, 0x14, 0x15;
  cmpwi r0, 0xc00;
  beq lbl_80153e28;
  rlwinm r0, r3, 0, 0x12, 0x13;
  cmpwi r0, 0x3000;
  bne lbl_80153e40;
lbl_80153e28:
  lbz r4, 0xd(r31);
  mr r3, r29;
  addi r5, r1, 8;
  li r6, 0;
  bl PORT_PortNegCnf;
  b lbl_80153eac;
lbl_80153e40:
  lbz r0, 0x56(r31);
  cmplwi r0, 0xc;
  bne lbl_80153e88;
  li r0, 0x30;
  mr r3, r29;
  stb r0, 0x56(r31);
  addi r6, r31, 0x51;
  li r5, 1;
  li r7, 0x3000;
  lbz r0, 0x69(r31);
  ori r0, r0, 4;
  stb r0, 0x69(r31);
  lbz r4, 0(r30);
  bl rfc_send_rpn;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
  b lbl_80153eac;
lbl_80153e88:
  cmplwi r0, 0x30;
  bne lbl_80153eac;
  li r0, 0;
  mr r3, r29;
  stb r0, 0x56(r31);
  addi r5, r1, 8;
  li r6, 0;
  lbz r4, 0xd(r31);
  bl PORT_PortNegCnf;
lbl_80153eac:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: rfc_process_msc
// PAL: 0x80153ecc..0x80154038
MARK_BINARY_BLOB(rfc_process_msc, 0x80153ecc, 0x80154038);
asm UNKNOWN_FUNCTION(rfc_process_msc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  mr r29, r4;
  lbz r27, 9(r5);
  lbz r4, 0(r5);
  mr r28, r3;
  mr r30, r5;
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80154020;
  rlwinm. r0, r27, 0, 0x1d, 0x1d;
  li r0, 0;
  stb r0, 8(r1);
  beq lbl_80153f1c;
  ori r0, r0, 1;
  stb r0, 8(r1);
lbl_80153f1c:
  rlwinm. r0, r27, 0, 0x1c, 0x1c;
  beq lbl_80153f30;
  lbz r0, 8(r1);
  ori r0, r0, 2;
  stb r0, 8(r1);
lbl_80153f30:
  rlwinm. r0, r27, 0, 0x19, 0x19;
  beq lbl_80153f44;
  lbz r0, 8(r1);
  ori r0, r0, 4;
  stb r0, 8(r1);
lbl_80153f44:
  rlwinm. r0, r27, 0, 0x18, 0x18;
  beq lbl_80153f58;
  lbz r0, 8(r1);
  ori r0, r0, 8;
  stb r0, 8(r1);
lbl_80153f58:
  rlwinm r0, r27, 0x1f, 0x1f, 0x1f;
  stb r0, 0xc(r1);
  lbz r0, 0xa(r30);
  cmpwi r0, 0;
  beq lbl_80153f74;
  lbz r5, 0xb(r30);
  b lbl_80153f78;
lbl_80153f74:
  li r5, 0;
lbl_80153f78:
  li r4, 0;
  li r0, 1;
  cmpwi r29, 0;
  stb r5, 9(r1);
  stb r4, 0xa(r1);
  stb r0, 0xb(r1);
  beq lbl_80153ff4;
  lbz r4, 0(r30);
  mr r3, r28;
  addi r6, r1, 8;
  li r5, 0;
  bl rfc_send_msc;
  lwz r3, 0x6c(r31);
  lbz r0, 0x72(r3);
  cmplwi r0, 2;
  beq lbl_80153fe0;
  lbz r3, 0xc(r1);
  stb r3, 0x63(r31);
  lbz r0, 0x24(r31);
  cmplw r3, r0;
  beq lbl_80153fe0;
  cntlzw r0, r3;
  lbz r4, 0(r30);
  mr r3, r28;
  rlwinm r5, r0, 0x1b, 0x18, 0x1f;
  bl PORT_FlowInd;
lbl_80153fe0:
  lbz r4, 0(r30);
  mr r3, r28;
  addi r5, r1, 8;
  bl PORT_ControlInd;
  b lbl_80154020;
lbl_80153ff4:
  lbz r4, 0x69(r3);
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  beq lbl_80154020;
  rlwinm r0, r4, 0, 0x1d, 0x1b;
  stb r0, 0x69(r3);
  mr r3, r31;
  bl rfc_port_timer_stop;
  lwz r3, 0x6c(r31);
  addi r5, r1, 8;
  lbz r4, 0xd(r31);
  bl PORT_ControlCnf;
lbl_80154020:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: rfc_process_rls
// PAL: 0x80154038..0x801540c4
MARK_BINARY_BLOB(rfc_process_rls, 0x80154038, 0x801540c4);
asm UNKNOWN_FUNCTION(rfc_process_rls) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80154080;
  lbz r4, 0(r5);
  lbz r5, 9(r5);
  bl PORT_LineStatusInd;
  lbz r4, 0(r31);
  mr r3, r30;
  lbz r6, 9(r31);
  li r5, 0;
  bl rfc_send_rls;
  b lbl_801540ac;
lbl_80154080:
  lbz r4, 0(r5);
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  beq lbl_801540ac;
  lbz r4, 0x69(r3);
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_801540a0;
  b lbl_801540ac;
lbl_801540a0:
  rlwinm r0, r4, 0, 0x1c, 0x1a;
  stb r0, 0x69(r3);
  bl rfc_port_timer_stop;
lbl_801540ac:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_process_nsc
// PAL: 0x801540c4..0x801540c8
MARK_BINARY_BLOB(rfc_process_nsc, 0x801540c4, 0x801540c8);
asm UNKNOWN_FUNCTION(rfc_process_nsc) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: rfc_process_test_rsp
// PAL: 0x801540c8..0x801540d0
MARK_BINARY_BLOB(rfc_process_test_rsp, 0x801540c8, 0x801540d0);
asm UNKNOWN_FUNCTION(rfc_process_test_rsp) {
  // clang-format off
  nofralloc;
  mr r3, r4;
  b GKI_freebuf;
  // clang-format on
}

// Symbol: rfc_process_fcon
// PAL: 0x801540d0..0x80154134
MARK_BINARY_BLOB(rfc_process_fcon, 0x801540d0, 0x80154134);
asm UNKNOWN_FUNCTION(rfc_process_fcon) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_80154120;
  lis r5, 0x8034;
  li r0, 0;
  addi r5, r5, -25816;
  li r4, 0;
  stb r0, 0x64(r5);
  bl rfc_send_fcon;
  lbz r0, 0x73(r31);
  cmpwi r0, 0;
  bne lbl_80154120;
  mr r3, r31;
  li r4, 0;
  li r5, 1;
  bl PORT_FlowInd;
lbl_80154120:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_process_fcoff
// PAL: 0x80154134..0x80154198
MARK_BINARY_BLOB(rfc_process_fcoff, 0x80154134, 0x80154198);
asm UNKNOWN_FUNCTION(rfc_process_fcoff) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_80154184;
  lis r4, 0x8034;
  li r0, 1;
  addi r4, r4, -25816;
  stb r0, 0x64(r4);
  lbz r0, 0x73(r3);
  cmpwi r0, 0;
  bne lbl_80154178;
  li r4, 0;
  li r5, 0;
  bl PORT_FlowInd;
lbl_80154178:
  mr r3, r31;
  li r4, 0;
  bl rfc_send_fcoff;
lbl_80154184:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_process_l2cap_congestion
// PAL: 0x80154198..0x80154220
MARK_BINARY_BLOB(rfc_process_l2cap_congestion, 0x80154198, 0x80154220);
asm UNKNOWN_FUNCTION(rfc_process_l2cap_congestion) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  stb r4, 0x73(r3);
  bne lbl_801541c8;
  li r4, 0;
  bl rfc_check_send_cmd;
lbl_801541c8:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x64(r3);
  cmpwi r0, 0;
  bne lbl_80154208;
  cmpwi r31, 0;
  bne lbl_801541f8;
  mr r3, r30;
  li r4, 0;
  li r5, 1;
  bl PORT_FlowInd;
  b lbl_80154208;
lbl_801541f8:
  mr r3, r30;
  li r4, 0;
  li r5, 0;
  bl PORT_FlowInd;
lbl_80154208:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_set_port_state
// PAL: 0x80154220..0x801542c4
MARK_BINARY_BLOB(rfc_set_port_state, 0x80154220, 0x801542c4);
asm UNKNOWN_FUNCTION(rfc_set_port_state) {
  // clang-format off
  nofralloc;
  lhz r0, 0x12(r4);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80154234;
  lbz r0, 0xa(r4);
  stb r0, 0(r3);
lbl_80154234:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80154248;
  lbz r0, 0xb(r4);
  stb r0, 1(r3);
lbl_80154248:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8015425c;
  lbz r0, 0xc(r4);
  stb r0, 2(r3);
lbl_8015425c:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_80154270;
  lbz r0, 0xd(r4);
  stb r0, 3(r3);
lbl_80154270:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80154284;
  lbz r0, 0xe(r4);
  stb r0, 4(r3);
lbl_80154284:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x12, 0x17;
  beq lbl_80154298;
  lbz r0, 0xf(r4);
  stb r0, 5(r3);
lbl_80154298:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  beq lbl_801542ac;
  lbz r0, 0x10(r4);
  stb r0, 7(r3);
lbl_801542ac:
  lhz r0, 0x12(r4);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beqlr;
  lbz r0, 0x11(r4);
  stb r0, 8(r3);
  blr;
  // clang-format on
}
