#include "btu_hcif.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_hcisu.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "btm_acl.h"
#include "btm_devctl.h"
#include "btm_inq.h"
#include "btm_pm.h"
#include "btm_sco.h"
#include "btm_sec.h"
#include "hidd_pm.h"
#include "l2c_link.h"

// Symbol: btu_hcif_process_event
// PAL: 0x801420ac..0x80142664
MARK_BINARY_BLOB(btu_hcif_process_event, 0x801420ac, 0x80142664);
asm UNKNOWN_FUNCTION(btu_hcif_process_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x44(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x3c(r1);
  stw r30, 0x38(r1);
  stw r29, 0x34(r1);
  stw r28, 0x30(r1);
  lhz r5, 4(r3);
  lbz r0, 0x64e(r4);
  add r7, r3, r5;
  cmpwi r0, 0;
  lbz r3, 8(r7);
  lbz r4, 9(r7);
  bne lbl_801420fc;
  cmplwi r3, 0xe;
  beq lbl_801420fc;
  cmplwi r3, 0xf;
  bne lbl_80142644;
lbl_801420fc:
  cmpwi r3, 0x14;
  beq lbl_80142460;
  bge lbl_80142198;
  cmpwi r3, 0xa;
  beq lbl_8014236c;
  bge lbl_8014215c;
  cmpwi r3, 5;
  beq lbl_80142260;
  bge lbl_80142144;
  cmpwi r3, 2;
  beq lbl_80142228;
  bge lbl_80142138;
  cmpwi r3, 1;
  bge lbl_8014221c;
  b lbl_80142644;
lbl_80142138:
  cmpwi r3, 4;
  bge lbl_80142254;
  b lbl_80142248;
lbl_80142144:
  cmpwi r3, 8;
  beq lbl_8014232c;
  bge lbl_80142644;
  cmpwi r3, 7;
  bge lbl_801422c8;
  b lbl_801422a8;
lbl_8014215c:
  cmpwi r3, 0xf;
  beq lbl_801423c0;
  bge lbl_80142180;
  cmpwi r3, 0xd;
  beq lbl_801423a8;
  bge lbl_801423b4;
  cmpwi r3, 0xc;
  bge lbl_8014239c;
  b lbl_80142390;
lbl_80142180:
  cmpwi r3, 0x12;
  beq lbl_801423f4;
  bge lbl_80142454;
  cmpwi r3, 0x11;
  bge lbl_80142644;
  b lbl_801423cc;
lbl_80142198:
  cmpwi r3, 0x21;
  beq lbl_80142644;
  bge lbl_801421e0;
  cmpwi r3, 0x1c;
  beq lbl_80142574;
  bge lbl_801421d4;
  cmpwi r3, 0x17;
  beq lbl_8014252c;
  bge lbl_801421c8;
  cmpwi r3, 0x16;
  bge lbl_801424e8;
  b lbl_801424c8;
lbl_801421c8:
  cmpwi r3, 0x19;
  bge lbl_80142644;
  b lbl_80142568;
lbl_801421d4:
  cmpwi r3, 0x1e;
  beq lbl_801425c4;
  b lbl_80142644;
lbl_801421e0:
  cmpwi r3, 0xef;
  beq lbl_8014263c;
  bge lbl_80142210;
  cmpwi r3, 0x2c;
  beq lbl_801425e0;
  bge lbl_80142204;
  cmpwi r3, 0x23;
  bge lbl_80142644;
  b lbl_80142238;
lbl_80142204:
  cmpwi r3, 0x2e;
  bge lbl_80142644;
  b lbl_801425ec;
lbl_80142210:
  cmpwi r3, 0xff;
  beq lbl_8014263c;
  b lbl_80142644;
lbl_8014221c:
  lbz r3, 0xa(r7);
  bl btm_process_inq_complete;
  b lbl_80142644;
lbl_80142228:
  addi r3, r7, 0xa;
  li r4, 0;
  bl btm_process_inq_results;
  b lbl_80142644;
lbl_80142238:
  addi r3, r7, 0xa;
  li r4, 1;
  bl btm_process_inq_results;
  b lbl_80142644;
lbl_80142248:
  addi r3, r7, 0xa;
  bl btu_hcif_connection_comp_evt;
  b lbl_80142644;
lbl_80142254:
  addi r3, r7, 0xa;
  bl btu_hcif_connection_request_evt;
  b lbl_80142644;
lbl_80142260:
  lbz r0, 0xc(r7);
  lbz r3, 0xb(r7);
  slwi r0, r0, 8;
  lbz r31, 0xd(r7);
  add r0, r3, r0;
  clrlwi r28, r0, 0x14;
  mr r4, r31;
  mr r3, r28;
  bl l2c_link_hci_disc_comp;
  clrlwi. r0, r3, 0x18;
  bne lbl_80142298;
  mr r3, r28;
  mr r4, r31;
  bl btm_sco_removed;
lbl_80142298:
  mr r3, r28;
  mr r4, r31;
  bl btm_sec_disconnected;
  b lbl_80142644;
lbl_801422a8:
  lbz r0, 0xc(r7);
  lbz r3, 0xb(r7);
  slwi r0, r0, 8;
  lbz r4, 0xa(r7);
  add r0, r3, r0;
  clrlwi r3, r0, 0x10;
  bl btm_sec_auth_complete;
  b lbl_80142644;
lbl_801422c8:
  lbz r30, 0xa(r7);
  addi r0, r4, -7;
  lbz r3, 0xb(r7);
  addi r31, r7, 0x11;
  clrlwi r5, r0, 0x10;
  mr r6, r30;
  stb r3, 0x25(r1);
  mr r4, r31;
  addi r3, r1, 0x20;
  lbz r0, 0xc(r7);
  stb r0, 0x24(r1);
  lbz r0, 0xd(r7);
  stb r0, 0x23(r1);
  lbz r0, 0xe(r7);
  stb r0, 0x22(r1);
  lbz r0, 0xf(r7);
  stb r0, 0x21(r1);
  lbz r0, 0x10(r7);
  stb r0, 0x20(r1);
  bl btm_process_remote_name;
  mr r4, r31;
  mr r5, r30;
  addi r3, r1, 0x20;
  bl btm_sec_rmt_name_request_complete;
  b lbl_80142644;
lbl_8014232c:
  lbz r0, 0xc(r7);
  lbz r3, 0xb(r7);
  slwi r0, r0, 8;
  lbz r29, 0xa(r7);
  add r0, r3, r0;
  lbz r30, 0xd(r7);
  clrlwi r31, r0, 0x10;
  mr r4, r29;
  mr r3, r31;
  mr r5, r30;
  bl btm_acl_encrypt_change;
  mr r3, r31;
  mr r4, r29;
  mr r5, r30;
  bl btm_sec_encrypt_change;
  b lbl_80142644;
lbl_8014236c:
  lbz r0, 0xc(r7);
  lbz r3, 0xb(r7);
  slwi r0, r0, 8;
  lbz r4, 0xa(r7);
  add r0, r3, r0;
  lbz r5, 0xd(r7);
  clrlwi r3, r0, 0x10;
  bl btm_sec_mkey_comp_event;
  b lbl_80142644;
lbl_80142390:
  addi r3, r7, 0xa;
  bl btm_read_remote_features_complete;
  b lbl_80142644;
lbl_8014239c:
  addi r3, r7, 0xa;
  bl btm_read_remote_version_complete;
  b lbl_80142644;
lbl_801423a8:
  addi r3, r7, 0xa;
  bl btu_hcif_qos_setup_comp_evt;
  b lbl_80142644;
lbl_801423b4:
  addi r3, r7, 0xa;
  bl btu_hcif_command_complete_evt;
  b lbl_80142644;
lbl_801423c0:
  addi r3, r7, 0xa;
  bl btu_hcif_command_status_evt;
  b lbl_80142644;
lbl_801423cc:
  lis r4, 0x8028;
  lis r3, 7;
  addi r4, r4, 0x4b00;
  bl LogMsg_0;
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_80142644;
  li r3, 0;
  bl BTM_DeviceReset;
  b lbl_80142644;
lbl_801423f4:
  lbz r29, 0xa(r7);
  lbz r0, 0xb(r7);
  cmpwi r29, 0;
  stb r0, 0x1d(r1);
  lbz r0, 0xc(r7);
  stb r0, 0x1c(r1);
  lbz r0, 0xd(r7);
  stb r0, 0x1b(r1);
  lbz r0, 0xe(r7);
  stb r0, 0x1a(r1);
  lbz r0, 0xf(r7);
  stb r0, 0x19(r1);
  lbz r0, 0x10(r7);
  stb r0, 0x18(r1);
  lbz r31, 0x11(r7);
  bne lbl_80142440;
  mr r4, r31;
  addi r3, r1, 0x18;
  bl l2c_link_role_changed;
lbl_80142440:
  mr r3, r29;
  mr r5, r31;
  addi r4, r1, 0x18;
  bl btm_acl_role_changed;
  b lbl_80142644;
lbl_80142454:
  addi r3, r7, 0xa;
  bl l2c_link_process_num_completed_pkts;
  b lbl_80142644;
lbl_80142460:
  lbz r3, 0xc(r7);
  lbz r0, 0xf(r7);
  slwi r4, r3, 8;
  lbz r5, 0xb(r7);
  lbz r3, 0xe(r7);
  slwi r0, r0, 8;
  add r4, r5, r4;
  lbz r30, 0xd(r7);
  clrlwi r31, r4, 0x10;
  add r0, r3, r0;
  lbz r28, 0xa(r7);
  mr r4, r31;
  mr r5, r30;
  clrlwi r29, r0, 0x10;
  mr r3, r28;
  bl btm_sco_chk_pend_unpark;
  mr r3, r28;
  mr r4, r31;
  mr r5, r30;
  mr r6, r29;
  bl btm_pm_proc_mode_change;
  mr r3, r28;
  mr r4, r30;
  mr r5, r29;
  bl hidd_pm_proc_mode_change;
  b lbl_80142644;
lbl_801424c8:
  lbz r0, 0xa(r7);
  cmpwi r0, 0;
  beq lbl_80142644;
  li r0, 1;
  addi r3, r7, 9;
  stb r0, 9(r7);
  bl btm_return_link_keys_evt;
  b lbl_80142644;
lbl_801424e8:
  lbz r0, 0xa(r7);
  addi r3, r1, 0x10;
  stb r0, 0x15(r1);
  lbz r0, 0xb(r7);
  stb r0, 0x14(r1);
  lbz r0, 0xc(r7);
  stb r0, 0x13(r1);
  lbz r0, 0xd(r7);
  stb r0, 0x12(r1);
  lbz r0, 0xe(r7);
  stb r0, 0x11(r1);
  lbz r0, 0xf(r7);
  stb r0, 0x10(r1);
  bl l2c_pin_code_request;
  addi r3, r1, 0x10;
  bl btm_sec_pin_code_request;
  b lbl_80142644;
lbl_8014252c:
  lbz r0, 0xa(r7);
  addi r3, r1, 8;
  stb r0, 0xd(r1);
  lbz r0, 0xb(r7);
  stb r0, 0xc(r1);
  lbz r0, 0xc(r7);
  stb r0, 0xb(r1);
  lbz r0, 0xd(r7);
  stb r0, 0xa(r1);
  lbz r0, 0xe(r7);
  stb r0, 9(r1);
  lbz r0, 0xf(r7);
  stb r0, 8(r1);
  bl btm_sec_link_key_request;
  b lbl_80142644;
lbl_80142568:
  addi r3, r7, 0xa;
  bl btu_hcif_link_key_notification_evt;
  b lbl_80142644;
lbl_80142574:
  lbz r0, 0xa(r7);
  cmpwi r0, 0;
  bne lbl_80142644;
  lbz r3, 0xc(r7);
  lbz r0, 0xe(r7);
  slwi r4, r3, 8;
  lbz r5, 0xb(r7);
  lbz r3, 0xd(r7);
  slwi r0, r0, 8;
  add r4, r5, r4;
  add r0, r3, r0;
  clrlwi r29, r4, 0x14;
  clrlwi r28, r0, 0x10;
  mr r3, r29;
  mr r4, r28;
  bl btm_process_clk_off_comp_evt;
  mr r3, r29;
  mr r4, r28;
  bl btm_sec_update_clock_offset;
  b lbl_80142644;
lbl_801425c4:
  lbz r0, 0xb(r7);
  lbz r3, 0xa(r7);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r3, r0, 0x14;
  bl l2c_link_hci_qos_violation;
  b lbl_80142644;
lbl_801425e0:
  addi r3, r7, 0xa;
  bl btu_hcif_esco_connection_comp_evt;
  b lbl_80142644;
lbl_801425ec:
  lbz r4, 0xc(r7);
  lbz r3, 0x10(r7);
  lbz r0, 0x12(r7);
  slwi r6, r4, 8;
  lbz r8, 0xb(r7);
  slwi r3, r3, 8;
  lbz r5, 0xf(r7);
  slwi r0, r0, 8;
  add r9, r8, r6;
  lbz r4, 0x11(r7);
  add r8, r5, r3;
  lbz r3, 0xa(r7);
  add r0, r4, r0;
  lbz r5, 0xd(r7);
  lbz r6, 0xe(r7);
  clrlwi r7, r8, 0x10;
  clrlwi r4, r9, 0x10;
  clrlwi r8, r0, 0x10;
  bl btm_esco_proc_conn_chg;
  b lbl_80142644;
lbl_8014263c:
  addi r3, r7, 0xa;
  bl btm_vendor_specific_evt;
lbl_80142644:
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  lwz r29, 0x34(r1);
  lwz r28, 0x30(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_send_cmd
// PAL: 0x80142664..0x801427f0
MARK_BINARY_BLOB(btu_hcif_send_cmd, 0x80142664, 0x801427f0);
asm UNKNOWN_FUNCTION(btu_hcif_send_cmd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  beq lbl_801426ac;
  lis r3, 0x8033;
  addi r3, r3, 0x5d50;
  lhz r0, 0x6c(r3);
  cmpwi r0, 0;
  beq lbl_801426ac;
  mr r4, r31;
  addi r3, r3, 0x64;
  bl GKI_enqueue;
  li r31, 0;
lbl_801426ac:
  lis r4, 0x8033;
  addi r4, r4, 0x5d50;
  lhz r0, 0x80(r4);
  cmpwi r0, 0;
  bne lbl_801426e0;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x64e(r3);
  cmpwi r0, 0;
  bne lbl_801426e0;
  lhz r3, 0x6c(r4);
  addi r0, r3, 1;
  sth r0, 0x80(r4);
lbl_801426e0:
  lis r3, 0x8033;
  addi r30, r3, 0x5d50;
  b lbl_801427ac;
lbl_801426ec:
  cmpwi r31, 0;
  bne lbl_80142700;
  addi r3, r30, 0x64;
  bl GKI_dequeue;
  mr r31, r3;
lbl_80142700:
  cmpwi r31, 0;
  beq lbl_801427b8;
  lhz r0, 4(r31);
  add r3, r31, r0;
  lbz r0, 9(r3);
  lbz r3, 8(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  cmplwi r0, 0xc03;
  beq lbl_80142790;
  cmplwi r0, 0xc35;
  beq lbl_80142790;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80142790;
  mr r4, r31;
  li r5, 8;
  bl memcpy;
  lhz r3, 4(r29);
  lhz r0, 4(r31);
  add r3, r29, r3;
  lhz r5, 2(r31);
  add r4, r31, r0;
  addi r3, r3, 8;
  addi r4, r4, 8;
  bl memcpy;
  mr r4, r29;
  addi r3, r30, 0x70;
  bl GKI_enqueue;
  addi r3, r30, 0x4c;
  li r4, 0x3c;
  li r5, 8;
  bl btu_start_timer;
lbl_80142790:
  lhz r5, 0x80(r30);
  mr r3, r31;
  li r4, 0x2000;
  addi r0, r5, -1;
  sth r0, 0x80(r30);
  bl bte_hcisu_send;
  li r31, 0;
lbl_801427ac:
  lhz r0, 0x80(r30);
  cmpwi r0, 0;
  bne lbl_801426ec;
lbl_801427b8:
  cmpwi r31, 0;
  beq lbl_801427d4;
  lis r3, 0x8033;
  mr r4, r31;
  addi r3, r3, 0x5d50;
  addi r3, r3, 0x64;
  bl GKI_enqueue;
lbl_801427d4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_connection_comp_evt
// PAL: 0x801427f0..0x801428cc
MARK_BINARY_BLOB(btu_hcif_connection_comp_evt, 0x801427f0, 0x801428cc);
asm UNKNOWN_FUNCTION(btu_hcif_connection_comp_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  lbz r0, 2(r3);
  lbz r31, 0(r3);
  slwi r4, r0, 8;
  lbz r5, 1(r3);
  lbz r0, 3(r3);
  add r4, r5, r4;
  stb r0, 0xd(r1);
  clrlwi r30, r4, 0x14;
  lbz r0, 4(r3);
  stb r0, 0xc(r1);
  lbz r0, 5(r3);
  stb r0, 0xb(r1);
  lbz r0, 6(r3);
  stb r0, 0xa(r1);
  lbz r0, 7(r3);
  stb r0, 9(r1);
  lbz r0, 8(r3);
  stb r0, 8(r1);
  lbz r0, 9(r3);
  lbz r6, 0xa(r3);
  cmplwi r0, 1;
  bne lbl_80142880;
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 8;
  bl btm_sec_connected;
  mr r3, r31;
  mr r4, r30;
  addi r5, r1, 8;
  bl l2c_link_hci_conn_comp;
  b lbl_801428b4;
lbl_80142880:
  addi r3, r1, 0x10;
  li r4, 0;
  li r5, 0xe;
  bl memset;
  addi r3, r1, 0x14;
  addi r4, r1, 8;
  li r5, 6;
  bl memcpy;
  mr r3, r31;
  mr r5, r30;
  addi r4, r1, 8;
  addi r6, r1, 0x10;
  bl btm_sco_connected;
lbl_801428b4:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_connection_request_evt
// PAL: 0x801428cc..0x80142958
MARK_BINARY_BLOB(btu_hcif_connection_request_evt, 0x801428cc, 0x80142958);
asm UNKNOWN_FUNCTION(btu_hcif_connection_request_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lbz r0, 0(r3);
  stb r0, 0x11(r1);
  lbz r0, 1(r3);
  stb r0, 0x10(r1);
  lbz r0, 2(r3);
  stb r0, 0xf(r1);
  lbz r0, 3(r3);
  stb r0, 0xe(r1);
  lbz r0, 4(r3);
  stb r0, 0xd(r1);
  lbz r0, 5(r3);
  stb r0, 0xc(r1);
  lbz r0, 6(r3);
  stb r0, 0xa(r1);
  lbz r0, 7(r3);
  stb r0, 9(r1);
  lbz r0, 8(r3);
  stb r0, 8(r1);
  lbz r5, 9(r3);
  cmplwi r5, 1;
  bne lbl_8014293c;
  addi r3, r1, 0xc;
  addi r4, r1, 8;
  bl btm_sec_conn_req;
  b lbl_80142948;
lbl_8014293c:
  addi r3, r1, 0xc;
  addi r4, r1, 8;
  bl btm_sco_conn_req;
lbl_80142948:
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_qos_setup_comp_evt
// PAL: 0x80142958..0x80142a58
MARK_BINARY_BLOB(btu_hcif_qos_setup_comp_evt, 0x80142958, 0x80142a58);
asm UNKNOWN_FUNCTION(btu_hcif_qos_setup_comp_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  mr r6, r3;
  stw r0, 0x24(r1);
  addi r5, r1, 8;
  lbz r4, 2(r6);
  lbz r3, 0(r3);
  lbz r7, 1(r6);
  slwi r4, r4, 8;
  lbz r0, 3(r6);
  add r4, r7, r4;
  stb r0, 8(r1);
  clrlwi r4, r4, 0x10;
  lbz r0, 4(r6);
  stb r0, 9(r1);
  lbz r7, 8(r6);
  lbz r8, 7(r6);
  lbz r0, 6(r6);
  slwi r9, r7, 0x18;
  lbz r7, 5(r6);
  slwi r8, r8, 0x10;
  slwi r0, r0, 8;
  add r7, r8, r7;
  add r0, r9, r0;
  add r0, r7, r0;
  stw r0, 0xc(r1);
  lbz r7, 0xc(r6);
  lbz r8, 0xb(r6);
  lbz r0, 0xa(r6);
  slwi r9, r7, 0x18;
  lbz r7, 9(r6);
  slwi r8, r8, 0x10;
  slwi r0, r0, 8;
  add r7, r8, r7;
  add r0, r9, r0;
  add r0, r7, r0;
  stw r0, 0x14(r1);
  lbz r7, 0x10(r6);
  lbz r8, 0xf(r6);
  lbz r0, 0xe(r6);
  slwi r9, r7, 0x18;
  lbz r7, 0xd(r6);
  slwi r8, r8, 0x10;
  slwi r0, r0, 8;
  add r7, r8, r7;
  add r0, r9, r0;
  add r0, r7, r0;
  stw r0, 0x18(r1);
  lbz r8, 0x14(r6);
  lbz r7, 0x13(r6);
  lbz r0, 0x12(r6);
  slwi r8, r8, 0x18;
  lbz r6, 0x11(r6);
  slwi r7, r7, 0x10;
  slwi r0, r0, 8;
  add r6, r7, r6;
  add r0, r8, r0;
  add r0, r6, r0;
  stw r0, 0x1c(r1);
  bl btm_qos_setup_complete;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_esco_connection_comp_evt
// PAL: 0x80142a58..0x80142b38
MARK_BINARY_BLOB(btu_hcif_esco_connection_comp_evt, 0x80142a58, 0x80142b38);
asm UNKNOWN_FUNCTION(btu_hcif_esco_connection_comp_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  li r5, 6;
  stw r0, 0x34(r1);
  addi r4, r1, 8;
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  lbz r0, 2(r3);
  lbz r31, 0(r3);
  slwi r6, r0, 8;
  lbz r7, 1(r3);
  lbz r0, 3(r3);
  add r6, r7, r6;
  stb r0, 0xd(r1);
  clrlwi r30, r6, 0x10;
  lbz r0, 4(r3);
  stb r0, 0xc(r1);
  lbz r0, 5(r3);
  stb r0, 0xb(r1);
  lbz r0, 6(r3);
  stb r0, 0xa(r1);
  lbz r0, 7(r3);
  stb r0, 9(r1);
  lbz r0, 8(r3);
  stb r0, 8(r1);
  lbz r0, 9(r3);
  stb r0, 0x1a(r1);
  lbz r0, 0xa(r3);
  stb r0, 0x1b(r1);
  lbz r0, 0xb(r3);
  stb r0, 0x1c(r1);
  lbz r0, 0xd(r3);
  lbz r6, 0xc(r3);
  slwi r0, r0, 8;
  add r0, r6, r0;
  sth r0, 0x10(r1);
  lbz r0, 0xf(r3);
  lbz r6, 0xe(r3);
  slwi r0, r0, 8;
  add r0, r6, r0;
  sth r0, 0x12(r1);
  lbz r0, 0x10(r3);
  addi r3, r1, 0x14;
  stb r0, 0x1d(r1);
  bl memcpy;
  mr r3, r31;
  mr r5, r30;
  addi r4, r1, 8;
  addi r6, r1, 0x10;
  bl btm_sco_connected;
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_hdl_command_complete
// PAL: 0x80142b38..0x80142c90
MARK_BINARY_BLOB(btu_hcif_hdl_command_complete, 0x80142b38, 0x80142c90);
asm UNKNOWN_FUNCTION(btu_hcif_hdl_command_complete) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0xc14;
  mr r6, r3;
  beq lbl_80142c48;
  bge lbl_80142b9c;
  cmpwi r3, 0xc05;
  beq lbl_80142bfc;
  bge lbl_80142b78;
  cmpwi r3, 0x80c;
  beq lbl_80142c28;
  bge lbl_80142b6c;
  cmpwi r3, 0x402;
  beq lbl_80142bf4;
  b lbl_80142c70;
lbl_80142b6c:
  cmpwi r3, 0xc03;
  beq lbl_80142bf0;
  b lbl_80142c70;
lbl_80142b78:
  cmpwi r3, 0xc11;
  beq lbl_80142c0c;
  bge lbl_80142b90;
  cmpwi r3, 0xc0d;
  beq lbl_80142c04;
  b lbl_80142c70;
lbl_80142b90:
  cmpwi r3, 0xc13;
  bge lbl_80142c70;
  b lbl_80142c14;
lbl_80142b9c:
  cmpwi r3, 0x1009;
  beq lbl_80142c54;
  bge lbl_80142bcc;
  cmpwi r3, 0x1003;
  beq lbl_80142c3c;
  bge lbl_80142bc0;
  cmpwi r3, 0x1001;
  beq lbl_80142c1c;
  b lbl_80142c70;
lbl_80142bc0:
  cmpwi r3, 0x1005;
  beq lbl_80142c30;
  b lbl_80142c70;
lbl_80142bcc:
  cmpwi r3, 0x1404;
  beq lbl_80142c70;
  bge lbl_80142be4;
  cmpwi r3, 0x1403;
  bge lbl_80142c60;
  b lbl_80142c70;
lbl_80142be4:
  cmpwi r3, 0x1406;
  bge lbl_80142c70;
  b lbl_80142c68;
lbl_80142bf0:
  b btm_reset_complete;
lbl_80142bf4:
  li r3, 0;
  b btm_process_inq_complete;
lbl_80142bfc:
  mr r3, r4;
  b btm_event_filter_complete;
lbl_80142c04:
  mr r3, r4;
  b btm_read_stored_link_key_complete;
lbl_80142c0c:
  mr r3, r4;
  b btm_write_stored_link_key_complete;
lbl_80142c14:
  mr r3, r4;
  b btm_delete_stored_link_key_complete;
lbl_80142c1c:
  mr r3, r4;
  mr r4, r5;
  b btm_read_local_version_complete;
lbl_80142c28:
  mr r3, r4;
  b btm_read_link_policy_complete;
lbl_80142c30:
  mr r3, r4;
  mr r4, r5;
  b btm_read_hci_buf_size_complete;
lbl_80142c3c:
  mr r3, r4;
  mr r4, r5;
  b btm_read_local_features_complete;
lbl_80142c48:
  mr r3, r4;
  mr r4, r5;
  b btm_read_local_name_complete;
lbl_80142c54:
  mr r3, r4;
  mr r4, r5;
  b btm_read_local_addr_complete;
lbl_80142c60:
  mr r3, r4;
  b btm_read_link_quality_complete;
lbl_80142c68:
  mr r3, r4;
  b btm_read_rssi_complete;
lbl_80142c70:
  rlwinm r3, r3, 0, 0x10, 0x15;
  addis r0, r3, 0;
  cmplwi r0, 0xfc00;
  bnelr;
  mr r3, r4;
  mr r4, r6;
  b btm_vsc_complete;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_command_complete_evt
// PAL: 0x80142c90..0x80142da8
MARK_BINARY_BLOB(btu_hcif_command_complete_evt, 0x80142c90, 0x80142da8);
asm UNKNOWN_FUNCTION(btu_hcif_command_complete_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5d50;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0(r3);
  sth r0, 0x80(r31);
  lbz r0, 2(r3);
  lbz r3, 1(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r30, r0, 0x10;
  cmplwi r30, 0xc03;
  beq lbl_80142d6c;
  cmplwi r30, 0xc35;
  beq lbl_80142d6c;
  cmpwi r30, 0;
  beq lbl_80142d6c;
  addi r3, r31, 0x70;
  bl GKI_dequeue;
  cmpwi r3, 0;
  beq lbl_80142d38;
  lbz r0, 9(r3);
  cmplwi r30, 0xfc4c;
  lbz r4, 8(r3);
  slwi r0, r0, 8;
  add r0, r4, r0;
  clrlwi r0, r0, 0x10;
  bne lbl_80142d34;
  cmplw r0, r30;
  beq lbl_80142d34;
  mr r4, r3;
  addi r3, r31, 0x70;
  bl GKI_enqueue_head;
  b lbl_80142d88;
lbl_80142d34:
  bl GKI_freebuf;
lbl_80142d38:
  lis r31, 0x8033;
  addi r31, r31, 0x5d50;
  addi r3, r31, 0x70;
  bl GKI_queue_is_empty;
  clrlwi. r0, r3, 0x18;
  bne lbl_80142d64;
  addi r3, r31, 0x4c;
  li r4, 0x3c;
  li r5, 8;
  bl btu_start_timer;
  b lbl_80142d6c;
lbl_80142d64:
  addi r3, r31, 0x4c;
  bl btu_stop_timer;
lbl_80142d6c:
  addi r0, r29, -3;
  mr r3, r30;
  addi r4, r28, 3;
  clrlwi r5, r0, 0x10;
  bl btu_hcif_hdl_command_complete;
  li r3, 0;
  bl btu_hcif_send_cmd;
lbl_80142d88:
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

// Symbol: btu_hcif_hdl_command_status
// PAL: 0x80142da8..0x80142fa8
MARK_BINARY_BLOB(btu_hcif_hdl_command_status, 0x80142da8, 0x80142fa8);
asm UNKNOWN_FUNCTION(btu_hcif_hdl_command_status) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  cmpwi r3, 0x802;
  mr r6, r3;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  mr r30, r4;
  beq lbl_80142df0;
  bge lbl_80142ddc;
  cmpwi r3, 0x801;
  bge lbl_80142de4;
  b lbl_80142df0;
lbl_80142ddc:
  cmpwi r3, 0x807;
  bge lbl_80142df0;
lbl_80142de4:
  mr r3, r30;
  bl btm_pm_proc_cmd_status;
  b lbl_80142f90;
lbl_80142df0:
  cmpwi r4, 0;
  beq lbl_80142f90;
  cmpwi r3, 0x419;
  beq lbl_80142e4c;
  bge lbl_80142e28;
  cmpwi r3, 0x401;
  beq lbl_80142e40;
  bge lbl_80142e1c;
  cmpwi r3, 0xd;
  beq lbl_80142e74;
  b lbl_80142f70;
lbl_80142e1c:
  cmpwi r3, 0x405;
  beq lbl_80142ea0;
  b lbl_80142f70;
lbl_80142e28:
  cmpwi r3, 0x80b;
  beq lbl_80142e88;
  bge lbl_80142f70;
  cmpwi r3, 0x428;
  beq lbl_80142f0c;
  b lbl_80142f70;
lbl_80142e40:
  mr r3, r30;
  bl btm_process_inq_complete;
  b lbl_80142f90;
lbl_80142e4c:
  mr r6, r30;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  bl btm_process_remote_name;
  mr r5, r30;
  li r3, 0;
  li r4, 0;
  bl btm_sec_rmt_name_request_complete;
  b lbl_80142f90;
lbl_80142e74:
  mr r3, r30;
  li r4, 0;
  li r5, 0;
  bl btm_qos_setup_complete;
  b lbl_80142f90;
lbl_80142e88:
  mr r3, r30;
  li r4, 0;
  li r5, 0xff;
  bl btm_acl_role_changed;
  bl l2c_link_role_change_failed;
  b lbl_80142f90;
lbl_80142ea0:
  cmpwi r5, 0;
  beq lbl_80142f90;
  lbz r4, 1(r5);
  lis r31, 1;
  addi r0, r31, -1;
  addi r3, r1, 8;
  stb r4, 0xd(r1);
  clrlwi r4, r0, 0x10;
  li r6, 0;
  lbz r0, 2(r5);
  stb r0, 0xc(r1);
  lbz r0, 3(r5);
  stb r0, 0xb(r1);
  lbz r0, 4(r5);
  stb r0, 0xa(r1);
  lbz r0, 5(r5);
  stb r0, 9(r1);
  lbz r0, 6(r5);
  mr r5, r30;
  stb r0, 8(r1);
  bl btm_sec_connected;
  addi r0, r31, -1;
  mr r3, r30;
  addi r5, r1, 8;
  clrlwi r4, r0, 0x10;
  bl l2c_link_hci_conn_comp;
  b lbl_80142f90;
lbl_80142f0c:
  cmpwi r5, 0;
  beq lbl_80142f90;
  lbz r0, 2(r5);
  lbz r3, 1(r5);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r31, r0, 0x10;
  mr r3, r31;
  bl btm_is_sco_active;
  clrlwi. r0, r3, 0x18;
  beq lbl_80142f58;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl btm_esco_proc_conn_chg;
  b lbl_80142f90;
lbl_80142f58:
  mr r3, r30;
  mr r5, r31;
  addi r6, r1, 0x10;
  li r4, 0;
  bl btm_sco_connected;
  b lbl_80142f90;
lbl_80142f70:
  rlwinm r3, r3, 0, 0x10, 0x15;
  addis r0, r3, 0;
  cmplwi r0, 0xfc00;
  bne lbl_80142f90;
  mr r3, r5;
  mr r4, r6;
  li r5, 1;
  bl btm_vsc_complete;
lbl_80142f90:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_command_status_evt
// PAL: 0x80142fa8..0x801430d0
MARK_BINARY_BLOB(btu_hcif_command_status_evt, 0x80142fa8, 0x801430d0);
asm UNKNOWN_FUNCTION(btu_hcif_command_status_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r4, 0x8033;
  lbz r29, 0(r3);
  lbz r0, 1(r3);
  addi r4, r4, 0x5d50;
  li r31, 0;
  li r27, 0;
  sth r0, 0x80(r4);
  lbz r0, 3(r3);
  lbz r3, 2(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r28, r0, 0x10;
  cmplwi r28, 0xc03;
  beq lbl_80143090;
  cmplwi r28, 0xc35;
  beq lbl_80143090;
  cmpwi r28, 0;
  beq lbl_80143090;
  addi r3, r4, 0x70;
  bl GKI_dequeue;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8014305c;
  lhz r0, 4(r3);
  add r3, r3, r0;
  lbz r0, 9(r3);
  addi r27, r3, 0xa;
  lbz r3, 8(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r6, r0, 0x10;
  cmplw r6, r28;
  beq lbl_8014305c;
  lis r3, 7;
  lis r4, 0x8028;
  mr r5, r28;
  li r27, 0;
  addi r3, r3, 1;
  addi r4, r4, 0x4b18;
  bl LogMsg_2;
lbl_8014305c:
  lis r30, 0x8033;
  addi r30, r30, 0x5d50;
  addi r3, r30, 0x70;
  bl GKI_queue_is_empty;
  clrlwi. r0, r3, 0x18;
  bne lbl_80143088;
  addi r3, r30, 0x4c;
  li r4, 0x3c;
  li r5, 8;
  bl btu_start_timer;
  b lbl_80143090;
lbl_80143088:
  addi r3, r30, 0x4c;
  bl btu_stop_timer;
lbl_80143090:
  mr r3, r28;
  mr r4, r29;
  mr r5, r27;
  bl btu_hcif_hdl_command_status;
  cmpwi r31, 0;
  beq lbl_801430b0;
  mr r3, r31;
  bl GKI_freebuf;
lbl_801430b0:
  li r3, 0;
  bl btu_hcif_send_cmd;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_cmd_timeout
// PAL: 0x801430d0..0x80143228
MARK_BINARY_BLOB(btu_hcif_cmd_timeout, 0x801430d0, 0x80143228);
asm UNKNOWN_FUNCTION(btu_hcif_cmd_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 1;
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5d50;
  stw r30, 0x18(r1);
  addi r3, r31, 0x70;
  stw r29, 0x14(r1);
  sth r0, 0x80(r31);
  bl GKI_dequeue;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80143124;
  lis r3, 7;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x4b40;
  bl LogMsg_0;
  b lbl_8014320c;
lbl_80143124:
  addi r3, r31, 0x70;
  bl GKI_queue_is_empty;
  clrlwi. r0, r3, 0x18;
  bne lbl_80143144;
  addi r3, r31, 0x4c;
  li r4, 0x3c;
  li r5, 8;
  bl btu_start_timer;
lbl_80143144:
  lhz r0, 4(r30);
  lis r3, 7;
  lis r4, 0x8028;
  add r31, r30, r0;
  addi r3, r3, 1;
  lbz r0, 9(r31);
  addi r4, r4, 0x4b60;
  lbz r5, 8(r31);
  slwi r0, r0, 8;
  add r0, r5, r0;
  clrlwi r29, r0, 0x10;
  mr r5, r29;
  bl LogMsg_1;
  cmpwi r29, 0x419;
  beq lbl_801431c8;
  bge lbl_801431a8;
  cmpwi r29, 0x401;
  beq lbl_801431c8;
  bge lbl_8014319c;
  cmpwi r29, 0xd;
  beq lbl_801431c8;
  b lbl_801431dc;
lbl_8014319c:
  cmpwi r29, 0x405;
  beq lbl_801431c8;
  b lbl_801431dc;
lbl_801431a8:
  cmpwi r29, 0x802;
  beq lbl_801431dc;
  bge lbl_801431c0;
  cmpwi r29, 0x801;
  bge lbl_801431c8;
  b lbl_801431dc;
lbl_801431c0:
  cmpwi r29, 0x807;
  bge lbl_801431dc;
lbl_801431c8:
  mr r3, r29;
  addi r5, r31, 0xa;
  li r4, 0x1f;
  bl btu_hcif_hdl_command_status;
  b lbl_801431f4;
lbl_801431dc:
  li r0, 0x1f;
  mr r3, r29;
  stb r0, 8(r1);
  addi r4, r1, 8;
  li r5, 1;
  bl btu_hcif_hdl_command_complete;
lbl_801431f4:
  mr r3, r30;
  bl GKI_freebuf;
  li r3, 2;
  bl btm_report_device_status;
  li r3, 0;
  bl btu_hcif_send_cmd;
lbl_8014320c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_hcif_link_key_notification_evt
// PAL: 0x80143228..0x80143308
MARK_BINARY_BLOB(btu_hcif_link_key_notification_evt, 0x80143228, 0x80143308);
asm UNKNOWN_FUNCTION(btu_hcif_link_key_notification_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  addi r5, r3, 0x16;
  stw r0, 0x24(r1);
  addi r4, r1, 0x10;
  lbz r0, 0(r3);
  stb r0, 0xd(r1);
  lbz r0, 1(r3);
  stb r0, 0xc(r1);
  lbz r0, 2(r3);
  stb r0, 0xb(r1);
  lbz r0, 3(r3);
  stb r0, 0xa(r1);
  lbz r0, 4(r3);
  stb r0, 9(r1);
  lbz r0, 5(r3);
  stb r0, 8(r1);
  lbz r0, 6(r3);
  stb r0, 0x1f(r1);
  lbz r0, 7(r3);
  stb r0, 0x1e(r1);
  lbz r0, 8(r3);
  stb r0, 0x1d(r1);
  lbz r0, 9(r3);
  stb r0, 0x1c(r1);
  lbz r0, 0xa(r3);
  stb r0, 0x1b(r1);
  lbz r0, 0xb(r3);
  stb r0, 0x1a(r1);
  lbz r0, 0xc(r3);
  stb r0, 0x19(r1);
  lbz r0, 0xd(r3);
  stb r0, 0x18(r1);
  lbz r0, 0xe(r3);
  stb r0, 0x17(r1);
  lbz r0, 0xf(r3);
  stb r0, 0x16(r1);
  lbz r0, 0x10(r3);
  stb r0, 0x15(r1);
  lbz r0, 0x11(r3);
  stb r0, 0x14(r1);
  lbz r0, 0x12(r3);
  stb r0, 0x13(r1);
  lbz r0, 0x13(r3);
  stb r0, 0x12(r1);
  lbz r0, 0x14(r3);
  stb r0, 0x11(r1);
  lbz r0, 0x15(r3);
  addi r3, r1, 8;
  stb r0, 0x10(r1);
  lbz r5, 0(r5);
  bl btm_sec_link_key_notification;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
