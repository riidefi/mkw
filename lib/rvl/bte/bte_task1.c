#include "bte_task1.h"

#include <rvl/os/os.h>

#include "gki_buffer.h"
#include "gki_time.h"
#include "gki_ppc.h"
#include "bta_sys.h"
#include "bte_init.h"
#include "btm_acl.h"
#include "btm_devctl.h"
#include "btm_discovery.h"
#include "btm_inq.h"
#include "btm_sco.h"

// Extern function references.
// PAL: 0x801420ac
extern UNKNOWN_FUNCTION(btu_hcif_process_event);
// PAL: 0x80142664
extern UNKNOWN_FUNCTION(btu_hcif_send_cmd);
// PAL: 0x801430d0
extern UNKNOWN_FUNCTION(btu_hcif_cmd_timeout);
// PAL: 0x80143308
extern UNKNOWN_FUNCTION(btu_init_core);
// PAL: 0x801485a4
extern UNKNOWN_FUNCTION(hidh_proc_repage_timeout);
// PAL: 0x8014d174
extern UNKNOWN_FUNCTION(l2c_link_segments_xmitted);
// PAL: 0x8014d3a8
extern UNKNOWN_FUNCTION(l2c_rcv_acl_data);
// PAL: 0x8014e148
extern UNKNOWN_FUNCTION(l2c_process_timeout);
// PAL: 0x80156304
extern UNKNOWN_FUNCTION(rfcomm_process_timeout);
// PAL: 0x80159ea8
extern UNKNOWN_FUNCTION(sdp_conn_timeout);

// Symbol: btu_task_init
// PAL: 0x80131940..0x80131980
MARK_BINARY_BLOB(btu_task_init, 0x80131940, 0x80131980);
asm UNKNOWN_FUNCTION(btu_task_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 1;
  stw r0, 0x14(r1);
  li r0, 0;
  stb r3, -0x73a0(r13);
  stw r3, -0x739c(r13);
  stw r0, -0x6618(r13);
  stw r0, -0x6614(r13);
  bl btu_init_core;
  bl BTE_InitStack;
  bl bta_sys_init;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btu_task_msg_handler
// PAL: 0x80131980..0x80131d0c
MARK_BINARY_BLOB(btu_task_msg_handler, 0x80131980, 0x80131d0c);
asm UNKNOWN_FUNCTION(btu_task_msg_handler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  li r30, 0;
  bl OSGetTime;
  lwz r3, -0x6618(r13);
  addi r0, r3, 1;
  stw r0, -0x6618(r13);
  bl GKI_disable;
  lwz r0, -0x739c(r13);
  cmpwi r0, 0;
  beq lbl_801319cc;
  li r3, 0;
  li r0, 1;
  stw r3, -0x739c(r13);
  stb r0, -0x73a0(r13);
  b lbl_801319e0;
lbl_801319cc:
  lbz r3, -0x73a0(r13);
  addi r0, r3, 1;
  stb r0, -0x73a0(r13);
  bl GKI_enable;
  b lbl_80131cf4;
lbl_801319e0:
  bl GKI_enable;
  lwz r3, -0x6614(r13);
  li r31, 5;
  lwz r4, -0x6618(r13);
  addi r0, r3, 0x1f4;
  cmplw r4, r0;
  ble lbl_80131a04;
  stw r4, -0x6614(r13);
  ori r31, r31, 0x30;
lbl_80131a04:
  lis r3, 0x8033;
  addi r29, r3, 0x5d50;
  b lbl_80131ce4;
lbl_80131a10:
  clrlwi. r0, r31, 0x1f;
  li r30, 1;
  beq lbl_80131b28;
  b lbl_80131b14;
lbl_80131a20:
  lhz r0, 0(r3);
  li r30, 0;
  rlwinm r28, r0, 0, 0x10, 0x17;
  cmpwi r28, 0x1200;
  beq lbl_80131a80;
  bge lbl_80131a50;
  cmpwi r28, 0x1100;
  beq lbl_80131a68;
  bge lbl_80131aac;
  cmpwi r28, 0x1000;
  beq lbl_80131a8c;
  b lbl_80131aac;
lbl_80131a50:
  cmpwi r28, 0x1900;
  beq lbl_80131a74;
  bge lbl_80131aac;
  cmpwi r28, 0x1600;
  beq lbl_80131aa0;
  b lbl_80131aac;
lbl_80131a68:
  mr r3, r27;
  bl l2c_rcv_acl_data;
  b lbl_80131b14;
lbl_80131a74:
  mr r3, r27;
  bl l2c_link_segments_xmitted;
  b lbl_80131b14;
lbl_80131a80:
  mr r3, r27;
  bl btm_route_sco_data;
  b lbl_80131b14;
lbl_80131a8c:
  mr r3, r27;
  bl btu_hcif_process_event;
  mr r3, r27;
  bl GKI_freebuf;
  b lbl_80131b14;
lbl_80131aa0:
  mr r3, r27;
  bl btu_hcif_send_cmd;
  b lbl_80131b14;
lbl_80131aac:
  li r26, 0;
  li r4, 0;
  b lbl_80131af0;
lbl_80131ab8:
  rlwinm r0, r26, 3, 0x15, 0x1c;
  add r3, r29, r0;
  lwz r12, 0x14(r3);
  cmpwi cr1, r12, 0;
  beq cr1, lbl_80131aec;
  lhz r0, 0x10(r3);
  cmplw r28, r0;
  bne lbl_80131aec;
  beq cr1, lbl_80131aec;
  mr r3, r27;
  mtctr r12;
  bctrl;
  li r4, 1;
lbl_80131aec:
  addi r26, r26, 1;
lbl_80131af0:
  cmpwi r4, 0;
  bne lbl_80131b04;
  clrlwi r0, r26, 0x18;
  cmplwi r0, 6;
  blt lbl_80131ab8;
lbl_80131b04:
  cmpwi r4, 0;
  bne lbl_80131b14;
  mr r3, r27;
  bl GKI_freebuf;
lbl_80131b14:
  li r3, 0;
  bl GKI_read_mbox;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_80131a20;
lbl_80131b28:
  rlwinm. r0, r31, 0, 0x1b, 0x1b;
  beq lbl_80131ca4;
  addi r3, r29, 0x40;
  li r4, 1;
  bl GKI_update_timer_list;
  rlwinm r0, r31, 0, 0x1c, 0x1a;
  clrlwi r31, r0, 0x10;
  b lbl_80131c8c;
lbl_80131b48:
  mr r4, r28;
  addi r3, r29, 0x40;
  li r30, 0;
  bl GKI_remove_from_timer_list;
  lhz r0, 0x14(r28);
  cmpwi r0, 0xa;
  beq lbl_80131bf4;
  bge lbl_80131b94;
  cmpwi r0, 5;
  beq lbl_80131be8;
  bge lbl_80131b84;
  cmpwi r0, 1;
  beq lbl_80131bc4;
  bge lbl_80131bdc;
  b lbl_80131c38;
lbl_80131b84:
  cmpwi r0, 8;
  beq lbl_80131bfc;
  bge lbl_80131bd0;
  b lbl_80131c38;
lbl_80131b94:
  cmpwi r0, 0x3c;
  beq lbl_80131c10;
  bge lbl_80131bb8;
  cmpwi r0, 0x16;
  beq lbl_80131c24;
  bge lbl_80131c38;
  cmpwi r0, 0xd;
  bge lbl_80131c38;
  b lbl_80131c04;
lbl_80131bb8:
  cmpwi r0, 0x42;
  beq lbl_80131c18;
  b lbl_80131c38;
lbl_80131bc4:
  mr r3, r28;
  bl btm_dev_timeout;
  b lbl_80131c8c;
lbl_80131bd0:
  mr r3, r28;
  bl btm_acl_timeout;
  b lbl_80131c8c;
lbl_80131bdc:
  mr r3, r28;
  bl l2c_process_timeout;
  b lbl_80131c8c;
lbl_80131be8:
  lwz r3, 0x10(r28);
  bl sdp_conn_timeout;
  b lbl_80131c8c;
lbl_80131bf4:
  bl btm_inq_rmt_name_failed;
  b lbl_80131c8c;
lbl_80131bfc:
  bl btm_discovery_timeout;
  b lbl_80131c8c;
lbl_80131c04:
  mr r3, r28;
  bl rfcomm_process_timeout;
  b lbl_80131c8c;
lbl_80131c10:
  bl btu_hcif_cmd_timeout;
  b lbl_80131c8c;
lbl_80131c18:
  mr r3, r28;
  bl hidh_proc_repage_timeout;
  b lbl_80131c8c;
lbl_80131c24:
  lwz r12, 0x10(r28);
  mr r3, r28;
  mtctr r12;
  bctrl;
  b lbl_80131c8c;
lbl_80131c38:
  li r27, 0;
  li r4, 0;
  b lbl_80131c78;
lbl_80131c44:
  rlwinm r0, r27, 3, 0x15, 0x1c;
  add r3, r29, r0;
  lwz r12, 4(r3);
  cmpwi r12, 0;
  beq lbl_80131c74;
  lwz r0, 0(r3);
  cmplw r0, r28;
  bne lbl_80131c74;
  mr r3, r28;
  mtctr r12;
  bctrl;
  li r4, 1;
lbl_80131c74:
  addi r27, r27, 1;
lbl_80131c78:
  cmpwi r4, 0;
  bne lbl_80131c8c;
  clrlwi r0, r27, 0x18;
  cmplwi r0, 2;
  blt lbl_80131c44;
lbl_80131c8c:
  lwz r28, 0x40(r29);
  cmpwi r28, 0;
  beq lbl_80131ca4;
  lwz r0, 0xc(r28);
  cmpwi r0, 0;
  beq lbl_80131b48;
lbl_80131ca4:
  rlwinm. r0, r31, 0, 0x1d, 0x1d;
  beq lbl_80131cc8;
  b lbl_80131cb8;
lbl_80131cb0:
  li r30, 0;
  bl bta_sys_event;
lbl_80131cb8:
  li r3, 2;
  bl GKI_read_mbox;
  cmpwi r3, 0;
  bne lbl_80131cb0;
lbl_80131cc8:
  rlwinm. r0, r31, 0, 0x1a, 0x1a;
  beq lbl_80131cdc;
  rlwinm r0, r31, 0, 0x1b, 0x19;
  clrlwi r31, r0, 0x10;
  bl bta_sys_timer_update;
lbl_80131cdc:
  rlwinm. r0, r31, 0, 0x10, 0x10;
  bne lbl_80131cec;
lbl_80131ce4:
  cmpwi r30, 0;
  beq lbl_80131a10;
lbl_80131cec:
  li r0, 1;
  stw r0, -0x739c(r13);
lbl_80131cf4:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btu_start_timer
// PAL: 0x80131d0c..0x80131d7c
MARK_BINARY_BLOB(btu_start_timer, 0x80131d0c, 0x80131d7c);
asm UNKNOWN_FUNCTION(btu_start_timer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5d50;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  mr r4, r28;
  addi r3, r31, 0x40;
  bl GKI_remove_from_timer_list;
  sth r29, 0x14(r28);
  mr r4, r28;
  addi r3, r31, 0x40;
  stw r30, 0xc(r28);
  bl GKI_add_to_timer_list;
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

// Symbol: btu_stop_timer
// PAL: 0x80131d7c..0x80131d90
MARK_BINARY_BLOB(btu_stop_timer, 0x80131d7c, 0x80131d90);
asm UNKNOWN_FUNCTION(btu_stop_timer) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  mr r4, r3;
  addi r5, r5, 0x5d50;
  addi r3, r5, 0x40;
  b GKI_remove_from_timer_list;
  // clang-format on
}
