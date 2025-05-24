#include "bta_hh_act.h"

#include <string.h>
#include "bte_logmsg.h"
#include "bta_sys.h"
#include "gki_buffer.h"
#include "bd.h"
#include "utl.h"

// Extern function references.
// PAL: 0x8013735c
extern UNKNOWN_FUNCTION(bta_hh_sm_execute);
// PAL: 0x801379ec
extern UNKNOWN_FUNCTION(bta_hh_clean_up_kdev);
// PAL: 0x80137a6c
extern UNKNOWN_FUNCTION(bta_hh_add_device_to_list);
// PAL: 0x80137b28
extern UNKNOWN_FUNCTION(bta_hh_tod_spt);
// PAL: 0x80137b7c
extern UNKNOWN_FUNCTION(bta_hh_trace_dev_db);
// PAL: 0x801472a0
extern UNKNOWN_FUNCTION(HID_HostGetSDPRecord);
// PAL: 0x801477b8
extern UNKNOWN_FUNCTION(HID_HostInit);
// PAL: 0x801477fc
extern UNKNOWN_FUNCTION(HID_HostRegister);
// PAL: 0x80147878
extern UNKNOWN_FUNCTION(HID_HostDeregister);
// PAL: 0x8014795c
extern UNKNOWN_FUNCTION(HID_HostAddDev);
// PAL: 0x80147aec
extern UNKNOWN_FUNCTION(HID_HostRemoveDev);
// PAL: 0x80147bb4
extern UNKNOWN_FUNCTION(HID_HostOpenDev);
// PAL: 0x80147c18
extern UNKNOWN_FUNCTION(HID_HostWriteDev);
// PAL: 0x80147d58
extern UNKNOWN_FUNCTION(HID_HostCloseDev);
// PAL: 0x80147df8
extern UNKNOWN_FUNCTION(HID_HostSetSecurityLevel);
// PAL: 0x8014f974
extern UNKNOWN_FUNCTION(l2cu_find_ccb_by_cid);
// PAL: 0x801d0968
extern UNKNOWN_FUNCTION(bta_hh_co_data);
// PAL: 0x801d09a4
extern UNKNOWN_FUNCTION(bta_hh_co_open);
// PAL: 0x801d09b4
extern UNKNOWN_FUNCTION(bta_hh_co_close);

// Symbol: bta_hh_api_enable
// PAL: 0x80135844..0x801359b8
MARK_BINARY_BLOB(bta_hh_api_enable, 0x80135844, 0x801359b8);
asm UNKNOWN_FUNCTION(bta_hh_api_enable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 6;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stb r0, 8(r1);
  bl HID_HostInit;
  lis r31, 0x8033;
  li r4, 0;
  addi r3, r31, 0x6048;
  li r5, 0x230;
  bl memset;
  lbz r4, 8(r29);
  addi r3, r13, -29592;
  bl HID_HostSetSecurityLevel;
  lis r3, 0x8013;
  addi r3, r3, 0x6cf4;
  bl HID_HostRegister;
  clrlwi. r0, r3, 0x18;
  bne lbl_80135980;
  lwz r4, 0x30(r29);
  addi r12, r31, 0x6048;
  li r3, 0;
  li r0, 2;
  stw r4, 0x224(r12);
  li r29, 0;
  li r11, 1;
  li r10, 0xff;
  stb r3, 8(r1);
  li r9, 0x10;
  mtctr r0;
lbl_801358cc:
  rlwinm r3, r29, 5, 0x13, 0x1a;
  clrlwi r0, r29, 0x18;
  add r31, r12, r3;
  addi r8, r29, 1;
  stb r11, 0x2c(r31);
  add r30, r12, r0;
  addi r7, r29, 2;
  addi r6, r29, 3;
  stb r10, 0x26(r31);
  addi r5, r29, 4;
  addi r4, r29, 5;
  addi r3, r29, 6;
  stb r29, 0x22(r31);
  addi r0, r29, 7;
  addi r29, r29, 8;
  stb r9, 0x214(r30);
  stb r11, 0x4c(r31);
  stb r10, 0x46(r31);
  stb r8, 0x42(r31);
  stb r9, 0x215(r30);
  stb r11, 0x6c(r31);
  stb r10, 0x66(r31);
  stb r7, 0x62(r31);
  stb r9, 0x216(r30);
  stb r11, 0x8c(r31);
  stb r10, 0x86(r31);
  stb r6, 0x82(r31);
  stb r9, 0x217(r30);
  stb r11, 0xac(r31);
  stb r10, 0xa6(r31);
  stb r5, 0xa2(r31);
  stb r9, 0x218(r30);
  stb r11, 0xcc(r31);
  stb r10, 0xc6(r31);
  stb r4, 0xc2(r31);
  stb r9, 0x219(r30);
  stb r11, 0xec(r31);
  stb r10, 0xe6(r31);
  stb r3, 0xe2(r31);
  stb r9, 0x21a(r30);
  stb r11, 0x10c(r31);
  stb r10, 0x106(r31);
  stb r0, 0x102(r31);
  stb r9, 0x21b(r30);
  bdnz lbl_801358cc;
lbl_80135980:
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x6048;
  li r3, 0;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_api_disable
// PAL: 0x801359b8..0x80135abc
MARK_BINARY_BLOB(bta_hh_api_disable, 0x801359b8, 0x80135abc);
asm UNKNOWN_FUNCTION(bta_hh_api_disable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  addi r31, r3, 0x6048;
  stw r30, 0x18(r1);
  lwz r0, 0x224(r31);
  cmpwi r0, 0;
  beq lbl_80135aa4;
  lbz r0, 0x22d(r31);
  cmpwi r0, 0;
  bne lbl_80135a68;
  li r0, 0;
  stb r0, 8(r1);
  bl HID_HostDeregister;
  clrlwi. r0, r3, 0x18;
  beq lbl_80135a08;
  li r0, 6;
  stb r0, 8(r1);
lbl_80135a08:
  lis r31, 0x8033;
  li r30, 0;
  addi r31, r31, 0x6048;
lbl_80135a14:
  rlwinm r0, r30, 5, 0x13, 0x1a;
  add r3, r31, r0;
  addi r3, r3, 0x14;
  bl utl_freebuf;
  addi r30, r30, 1;
  cmplwi r30, 0x10;
  blt lbl_80135a14;
  lis r31, 0x8033;
  addi r31, r31, 0x6048;
  addi r3, r31, 0x228;
  bl utl_freebuf;
  lwz r12, 0x224(r31);
  addi r4, r1, 8;
  li r3, 1;
  mtctr r12;
  bctrl;
  mr r3, r31;
  li r4, 0;
  li r5, 0x230;
  bl memset;
  b lbl_80135aa4;
lbl_80135a68:
  li r0, 1;
  li r30, 0;
  stb r0, 0x22e(r31);
lbl_80135a74:
  rlwinm r0, r30, 5, 0x13, 0x1a;
  add r3, r31, r0;
  lbz r0, 0x2c(r3);
  cmplwi r0, 3;
  bne lbl_80135a98;
  addi r3, r3, 0x10;
  li r4, 0x1701;
  li r5, 0;
  bl bta_hh_sm_execute;
lbl_80135a98:
  addi r30, r30, 1;
  cmplwi r30, 0x10;
  blt lbl_80135a74;
lbl_80135aa4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_disc_cmpl
// PAL: 0x80135abc..0x80135b60
MARK_BINARY_BLOB(bta_hh_disc_cmpl, 0x80135abc, 0x80135b60);
asm UNKNOWN_FUNCTION(bta_hh_disc_cmpl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stb r0, 8(r1);
  bl HID_HostDeregister;
  clrlwi. r0, r3, 0x18;
  beq lbl_80135aec;
  li r0, 6;
  stb r0, 8(r1);
lbl_80135aec:
  lis r31, 0x8033;
  li r30, 0;
  addi r31, r31, 0x6048;
lbl_80135af8:
  rlwinm r0, r30, 5, 0x13, 0x1a;
  add r3, r31, r0;
  addi r3, r3, 0x14;
  bl utl_freebuf;
  addi r30, r30, 1;
  cmplwi r30, 0x10;
  blt lbl_80135af8;
  lis r31, 0x8033;
  addi r31, r31, 0x6048;
  addi r3, r31, 0x228;
  bl utl_freebuf;
  lwz r12, 0x224(r31);
  addi r4, r1, 8;
  li r3, 1;
  mtctr r12;
  bctrl;
  mr r3, r31;
  li r4, 0;
  li r5, 0x230;
  bl memset;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_sdp_cback
// PAL: 0x80135b60..0x80135c94
MARK_BINARY_BLOB(bta_hh_sdp_cback, 0x80135b60, 0x80135c94);
asm UNKNOWN_FUNCTION(bta_hh_sdp_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8033;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  li r0, 0x10;
  addi r6, r6, 0x6048;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stb r0, 8(r1);
  lwz r31, 0x210(r6);
  bne lbl_80135c58;
  lbz r0, 0x14(r31);
  cmpwi r0, 0;
  beq lbl_80135bac;
  ori r29, r4, 0x8000;
lbl_80135bac:
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_80135bd4;
  lis r4, 0x8028;
  mr r6, r3;
  mr r5, r31;
  clrlwi r7, r29, 0x10;
  addi r4, r4, 0x2a58;
  li r3, 0x503;
  bl LogMsg_3;
lbl_80135bd4:
  lbz r4, 0x64(r30);
  mr r3, r31;
  bl bta_hh_tod_spt;
  clrlwi. r0, r3, 0x18;
  beq lbl_80135c50;
  lbz r0, 0x16(r31);
  cmplwi r0, 0xff;
  bne lbl_80135c58;
  addi r3, r31, 8;
  clrlwi r4, r29, 0x10;
  addi r5, r1, 9;
  bl HID_HostAddDev;
  clrlwi. r0, r3, 0x18;
  stb r3, 8(r1);
  bne lbl_80135c44;
  lis r3, 0x8033;
  lbz r4, 9(r1);
  addi r3, r3, 0x6048;
  lbz r0, 0x12(r31);
  add r5, r3, r4;
  addi r6, r30, 0x68;
  stb r0, 0x214(r5);
  mr r3, r31;
  clrlwi r5, r29, 0x10;
  lbz r7, 0x64(r30);
  lbz r8, 0x15(r31);
  bl bta_hh_add_device_to_list;
  b lbl_80135c58;
lbl_80135c44:
  li r0, 0;
  stb r0, 0x15(r31);
  b lbl_80135c58;
lbl_80135c50:
  li r0, 0xff;
  stb r0, 8(r1);
lbl_80135c58:
  lis r3, 0x8033;
  addi r3, r3, 0x6048;
  addi r3, r3, 0x228;
  bl utl_freebuf;
  mr r3, r31;
  addi r5, r1, 8;
  li r4, 0x1707;
  bl bta_hh_sm_execute;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_start_sdp
// PAL: 0x80135c94..0x80135e28
MARK_BINARY_BLOB(bta_hh_start_sdp, 0x80135c94, 0x80135e28);
asm UNKNOWN_FUNCTION(bta_hh_start_sdp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0x10;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stb r0, 9(r1);
  lbz r5, 0xe(r4);
  lbz r0, 0x15(r3);
  stb r5, 0x14(r3);
  cmpwi r0, 0;
  lbz r0, 0xf(r4);
  stb r0, 0x1b(r3);
  beq lbl_80135d6c;
  lbz r0, -0x6610(r13);
  li r3, 0;
  stb r3, 9(r1);
  cmplwi r0, 5;
  blt lbl_80135cfc;
  lis r4, 0x8028;
  li r3, 0x504;
  addi r4, r4, 0x2ab0;
  bl LogMsg_0;
lbl_80135cfc:
  lbz r0, 0x16(r31);
  cmplwi r0, 0xff;
  bne lbl_80135d58;
  lhz r4, 0xe(r31);
  addi r3, r31, 8;
  addi r5, r1, 8;
  bl HID_HostAddDev;
  clrlwi. r0, r3, 0x18;
  stb r3, 9(r1);
  bne lbl_80135d58;
  lbz r4, 8(r1);
  mr r3, r31;
  lhz r5, 0xe(r31);
  li r6, 0;
  lbz r7, 0x13(r31);
  lbz r8, 0x15(r31);
  bl bta_hh_add_device_to_list;
  lis r3, 0x8033;
  lbz r0, 8(r1);
  addi r3, r3, 0x6048;
  lbz r4, 0x12(r31);
  add r3, r3, r0;
  stb r4, 0x214(r3);
lbl_80135d58:
  mr r3, r31;
  addi r5, r1, 9;
  li r4, 0x1707;
  bl bta_hh_sm_execute;
  b lbl_80135e0c;
lbl_80135d6c:
  lis r30, 0x8033;
  addi r30, r30, 0x6048;
  lwz r0, 0x228(r30);
  cmpwi r0, 0;
  bne lbl_80135df0;
  lwz r3, -0x73c0(r13);
  lhz r3, 8(r3);
  bl GKI_getbuf;
  stw r3, 0x228(r30);
  lis r6, 0x8013;
  lwz r5, -0x73c0(r13);
  mr r4, r3;
  stw r31, 0x210(r30);
  addi r3, r29, 8;
  addi r6, r6, 0x5b60;
  lhz r5, 8(r5);
  bl HID_HostGetSDPRecord;
  clrlwi. r5, r3, 0x18;
  stb r3, 9(r1);
  beq lbl_80135df0;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80135dd8;
  lis r4, 0x8028;
  li r3, 0x504;
  addi r4, r4, 0x2ae0;
  bl LogMsg_1;
lbl_80135dd8:
  li r0, 7;
  lis r3, 0x8033;
  addi r3, r3, 0x6048;
  stb r0, 9(r1);
  addi r3, r3, 0x228;
  bl utl_freebuf;
lbl_80135df0:
  lbz r0, 9(r1);
  cmpwi r0, 0;
  beq lbl_80135e0c;
  mr r3, r31;
  addi r5, r1, 9;
  li r4, 0x1707;
  bl bta_hh_sm_execute;
lbl_80135e0c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_sdp_cmpl
// PAL: 0x80135e28..0x80135f90
MARK_BINARY_BLOB(bta_hh_sdp_cmpl, 0x80135e28, 0x80135f90);
asm UNKNOWN_FUNCTION(bta_hh_sdp_cmpl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80135e68;
  lis r4, 0x8028;
  lbz r5, 0(r30);
  addi r4, r4, 0x2b30;
  li r3, 0x504;
  bl LogMsg_1;
lbl_80135e68:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 8;
  bl memset;
  lbz r0, 0x16(r29);
  addi r3, r1, 8;
  addi r4, r29, 8;
  stb r0, 0xf(r1);
  bl bdcpy;
  lbz r31, 0(r30);
  cmpwi r31, 0;
  bne lbl_80135efc;
  lbz r0, 0x19(r29);
  cmpwi r0, 0;
  bne lbl_80135eec;
  lbz r4, 0x14(r29);
  addi r3, r13, -29592;
  bl HID_HostSetSecurityLevel;
  lbz r3, 0x16(r29);
  bl HID_HostOpenDev;
  clrlwi. r5, r3, 0x18;
  mr r31, r3;
  beq lbl_80135efc;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80135ee0;
  lis r4, 0x8028;
  li r3, 0x504;
  addi r4, r4, 0x2b50;
  bl LogMsg_1;
lbl_80135ee0:
  lbz r3, 0x16(r29);
  bl HID_HostRemoveDev;
  b lbl_80135efc;
lbl_80135eec:
  mr r3, r29;
  li r4, 0x170b;
  li r5, 0;
  bl bta_hh_sm_execute;
lbl_80135efc:
  clrlwi. r0, r31, 0x18;
  beq lbl_80135f74;
  lbz r0, 0(r30);
  cmplwi r0, 0xff;
  bne lbl_80135f1c;
  li r0, 0xa;
  stb r0, 0xe(r1);
  b lbl_80135f24;
lbl_80135f1c:
  li r0, 7;
  stb r0, 0xe(r1);
lbl_80135f24:
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x6048;
  li r3, 2;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  mr r3, r29;
  li r4, 0x1701;
  li r5, 0;
  bl bta_hh_sm_execute;
  lbz r0, 0x15(r29);
  cmpwi r0, 0;
  bne lbl_80135f70;
  lbz r0, 0x19(r29);
  cmpwi r0, 0;
  bne lbl_80135f70;
  mr r3, r29;
  bl bta_hh_clean_up_kdev;
lbl_80135f70:
  bl bta_hh_trace_dev_db;
lbl_80135f74:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_api_disc_act
// PAL: 0x80135f90..0x80135ff8
MARK_BINARY_BLOB(bta_hh_api_disc_act, 0x80135f90, 0x80135ff8);
asm UNKNOWN_FUNCTION(bta_hh_api_disc_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  beq lbl_80135fb0;
  lhz r0, 6(r4);
  clrlwi r3, r0, 0x18;
  b lbl_80135fb4;
lbl_80135fb0:
  lbz r3, 0x16(r3);
lbl_80135fb4:
  li r0, 6;
  stb r3, 9(r1);
  stb r0, 8(r1);
  bl HID_HostCloseDev;
  clrlwi. r0, r3, 0x18;
  beq lbl_80135fe8;
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x6048;
  li r3, 3;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
lbl_80135fe8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_hh_open_cmpl_act
// PAL: 0x80135ff8..0x80136120
MARK_BINARY_BLOB(bta_hh_open_cmpl_act, 0x80135ff8, 0x80136120);
asm UNKNOWN_FUNCTION(bta_hh_open_cmpl_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  beq lbl_80136028;
  lhz r0, 6(r4);
  clrlwi r30, r0, 0x18;
  b lbl_8013602c;
lbl_80136028:
  lbz r30, 0x16(r3);
lbl_8013602c:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 8;
  bl memset;
  stb r30, 0xf(r1);
  addi r3, r1, 8;
  addi r4, r29, 8;
  bl bdcpy;
  lis r31, 0x8033;
  addi r31, r31, 0x6048;
  lbz r3, 0x22d(r31);
  addi r0, r3, 1;
  stb r0, 0x22d(r31);
  lbz r3, 0x16(r29);
  lbz r4, 0x13(r29);
  lhz r5, 0xe(r29);
  lbz r6, 0x15(r29);
  bl bta_hh_co_open;
  lbz r4, 0x15(r29);
  addi r5, r29, 8;
  li r3, 0x17;
  bl bta_sys_conn_open;
  lbz r5, 0x1b(r29);
  cmpwi r5, 0;
  beq lbl_801360e0;
  mr r3, r30;
  li r4, 7;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl HID_HostWriteDev;
  clrlwi. r0, r3, 0x18;
  stb r3, 0xe(r1);
  beq lbl_801360d4;
  lwz r12, 0x224(r31);
  li r0, 8;
  stb r0, 0xe(r1);
  addi r4, r1, 8;
  li r3, 2;
  mtctr r12;
  bctrl;
  b lbl_801360fc;
lbl_801360d4:
  li r0, 2;
  sth r0, 0x10(r29);
  b lbl_801360fc;
lbl_801360e0:
  li r0, 1;
  addi r4, r1, 8;
  stb r0, 0x1a(r29);
  li r3, 2;
  lwz r12, 0x224(r31);
  mtctr r12;
  bctrl;
lbl_801360fc:
  li r0, 0;
  stb r0, 0x19(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_open_act
// PAL: 0x80136120..0x801361d8
MARK_BINARY_BLOB(bta_hh_open_act, 0x80136120, 0x801361d8);
asm UNKNOWN_FUNCTION(bta_hh_open_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  beq lbl_80136150;
  lhz r0, 6(r4);
  clrlwi r5, r0, 0x18;
  b lbl_80136154;
lbl_80136150:
  lbz r5, 0x16(r3);
lbl_80136154:
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_80136170;
  lis r4, 0x8028;
  li r3, 0x503;
  addi r4, r4, 0x2b9c;
  bl LogMsg_1;
lbl_80136170:
  lbz r0, 0x15(r30);
  cmpwi r0, 0;
  beq lbl_80136190;
  mr r3, r30;
  mr r5, r31;
  li r4, 0x170b;
  bl bta_hh_sm_execute;
  b lbl_801361c0;
lbl_80136190:
  li r0, 1;
  addi r3, r1, 8;
  stb r0, 0x19(r30);
  li r4, 0;
  li r5, 0x10;
  bl memset;
  addi r3, r1, 0x10;
  addi r4, r30, 8;
  bl bdcpy;
  mr r3, r30;
  addi r4, r1, 8;
  bl bta_hh_start_sdp;
lbl_801361c0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_data_act
// PAL: 0x801361d8..0x80136230
MARK_BINARY_BLOB(bta_hh_data_act, 0x801361d8, 0x80136230);
asm UNKNOWN_FUNCTION(bta_hh_data_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mr r8, r3;
  stw r0, 0x14(r1);
  lwz r5, 0xc(r4);
  stw r5, 8(r1);
  lhz r0, 4(r5);
  lhz r3, 6(r4);
  add r4, r5, r0;
  lhz r5, 2(r5);
  lbz r6, 0x1b(r8);
  clrlwi r3, r3, 0x18;
  lbz r7, 0x13(r8);
  addi r4, r4, 8;
  lbz r8, 0x15(r8);
  bl bta_hh_co_data;
  addi r3, r1, 8;
  bl utl_freebuf;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_hh_handsk_act
// PAL: 0x80136230..0x80136498
MARK_BINARY_BLOB(bta_hh_handsk_act, 0x80136230, 0x80136498);
asm UNKNOWN_FUNCTION(bta_hh_handsk_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stw r31, 0x3c(r1);
  mr r31, r3;
  stw r30, 0x38(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x2a58;
  stw r29, 0x34(r1);
  mr r29, r4;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_801362d4;
  lhz r0, 0x10(r3);
  cmplwi r0, 9;
  bgt lbl_801362c0;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x2cd8;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r5, r30, 0x16c;
  b lbl_801362c4;
  addi r5, r30, 0x180;
  b lbl_801362c4;
  addi r5, r30, 0x194;
  b lbl_801362c4;
  addi r5, r30, 0x1ac;
  b lbl_801362c4;
  addi r5, r30, 0x1c4;
  b lbl_801362c4;
  addi r5, r30, 0x1d8;
  b lbl_801362c4;
  addi r5, r30, 0x1f0;
  b lbl_801362c4;
lbl_801362c0:
  addi r5, r30, 0x200;
lbl_801362c4:
  lwz r6, 8(r29);
  addi r4, r30, 0x210;
  li r3, 0x504;
  bl LogMsg_2;
lbl_801362d4:
  lhz r0, 0x10(r31);
  cmplwi r0, 9;
  bgt lbl_80136454;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x2cb0;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r3, r1, 0x18;
  li r4, 0;
  li r5, 0xa;
  bl memset;
  lbz r0, 0x16(r31);
  stb r0, 0x19(r1);
  lwz r0, 8(r29);
  cmpwi r0, 5;
  bge lbl_8013632c;
  cmpwi r0, 0;
  beq lbl_80136338;
  bge lbl_80136340;
  b lbl_80136348;
lbl_8013632c:
  cmpwi r0, 0x10;
  bge lbl_80136348;
  b lbl_80136348;
lbl_80136338:
  li r0, 0;
  b lbl_8013634c;
lbl_80136340:
  clrlwi r0, r0, 0x18;
  b lbl_8013634c;
lbl_80136348:
  li r0, 5;
lbl_8013634c:
  lis r3, 0x8033;
  stb r0, 0x18(r1);
  addi r3, r3, 0x6048;
  addi r4, r1, 0x18;
  lwz r12, 0x224(r3);
  lhz r3, 0x10(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  sth r0, 0x10(r31);
  b lbl_8013646c;
  lbz r0, 0x16(r31);
  stb r0, 9(r1);
  lwz r0, 8(r29);
  cmpwi r0, 5;
  bge lbl_8013639c;
  cmpwi r0, 0;
  beq lbl_801363a8;
  bge lbl_801363b0;
  b lbl_801363b8;
lbl_8013639c:
  cmpwi r0, 0x10;
  bge lbl_801363b8;
  b lbl_801363b8;
lbl_801363a8:
  li r0, 0;
  b lbl_801363bc;
lbl_801363b0:
  clrlwi r0, r0, 0x18;
  b lbl_801363bc;
lbl_801363b8:
  li r0, 5;
lbl_801363bc:
  lis r3, 0x8033;
  stb r0, 8(r1);
  addi r3, r3, 0x6048;
  addi r4, r1, 8;
  lwz r12, 0x224(r3);
  lhz r3, 0x10(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  sth r0, 0x10(r31);
  b lbl_8013646c;
  lwz r0, 8(r29);
  li r3, 0;
  cmpwi r0, 0;
  beq lbl_801363fc;
  li r3, 8;
lbl_801363fc:
  stb r3, 0x16(r1);
  addi r3, r1, 0x10;
  addi r4, r31, 8;
  lbz r0, 0x16(r31);
  stb r0, 0x17(r1);
  bl bdcpy;
  lis r5, 0x8033;
  addi r4, r1, 0x10;
  addi r5, r5, 0x6048;
  lhz r3, 0x10(r31);
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  bl bta_hh_trace_dev_db;
  li r0, 0;
  sth r0, 0x10(r31);
  lbz r0, 0x16(r1);
  cmpwi r0, 0;
  bne lbl_8013646c;
  li r0, 1;
  stb r0, 0x1a(r31);
  b lbl_8013646c;
lbl_80136454:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_8013646c;
  addi r4, r30, 0x23c;
  li r3, 0x504;
  bl LogMsg_0;
lbl_8013646c:
  lbz r4, 0x15(r31);
  addi r5, r31, 8;
  li r3, 0x17;
  bl bta_sys_idle;
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  lwz r29, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: bta_hh_ctrl_dat_act
// PAL: 0x80136498..0x80136690
MARK_BINARY_BLOB(bta_hh_ctrl_dat_act, 0x80136498, 0x80136690);
asm UNKNOWN_FUNCTION(bta_hh_ctrl_dat_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r3;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  lis r29, 0x8028;
  addi r29, r29, 0x2a58;
  lwz r4, 0xc(r4);
  lbz r0, -0x6610(r13);
  stw r4, 8(r1);
  cmplwi r0, 5;
  lhz r0, 4(r4);
  add r30, r4, r0;
  blt lbl_80136544;
  lhz r0, 0x10(r3);
  cmplwi r0, 9;
  bgt lbl_80136534;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x2d84;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r5, r29, 0x16c;
  b lbl_80136538;
  addi r5, r29, 0x180;
  b lbl_80136538;
  addi r5, r29, 0x194;
  b lbl_80136538;
  addi r5, r29, 0x1ac;
  b lbl_80136538;
  addi r5, r29, 0x1c4;
  b lbl_80136538;
  addi r5, r29, 0x1d8;
  b lbl_80136538;
  addi r5, r29, 0x1f0;
  b lbl_80136538;
lbl_80136534:
  addi r5, r29, 0x200;
lbl_80136538:
  addi r4, r29, 0x2a8;
  li r3, 0x504;
  bl LogMsg_1;
lbl_80136544:
  li r0, 0;
  stb r0, 0xc(r1);
  lbz r0, 0x16(r31);
  stb r0, 0xd(r1);
  lhz r4, 0x10(r31);
  cmpwi r4, 7;
  beq lbl_801365b4;
  bge lbl_8013657c;
  cmpwi r4, 5;
  beq lbl_801365b4;
  bge lbl_801365a8;
  cmpwi r4, 4;
  bge lbl_80136594;
  b lbl_801365b4;
lbl_8013657c:
  cmpwi r4, 9;
  beq lbl_801365b4;
  bge lbl_801365b4;
  lbz r0, 8(r30);
  stb r0, 0xe(r1);
  b lbl_80136628;
lbl_80136594:
  lwz r4, 8(r1);
  addi r3, r1, 0xe;
  li r5, 8;
  bl memcpy;
  b lbl_80136628;
lbl_801365a8:
  lbz r0, 8(r30);
  stb r0, 0xe(r1);
  b lbl_80136628;
lbl_801365b4:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80136628;
  cmplwi r4, 9;
  bgt lbl_80136618;
  lis r3, 0x8028;
  slwi r0, r4, 2;
  addi r3, r3, 0x2d5c;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r5, r29, 0x16c;
  b lbl_8013661c;
  addi r5, r29, 0x180;
  b lbl_8013661c;
  addi r5, r29, 0x194;
  b lbl_8013661c;
  addi r5, r29, 0x1ac;
  b lbl_8013661c;
  addi r5, r29, 0x1c4;
  b lbl_8013661c;
  addi r5, r29, 0x1d8;
  b lbl_8013661c;
  addi r5, r29, 0x1f0;
  b lbl_8013661c;
lbl_80136618:
  addi r5, r29, 0x200;
lbl_8013661c:
  addi r4, r29, 0x2cc;
  li r3, 0x504;
  bl LogMsg_1;
lbl_80136628:
  lbz r4, 0x15(r31);
  addi r5, r31, 8;
  li r3, 0x17;
  bl bta_sys_busy;
  lbz r4, 0x15(r31);
  addi r5, r31, 8;
  li r3, 0x17;
  bl bta_sys_idle;
  lis r5, 0x8033;
  addi r4, r1, 0xc;
  addi r5, r5, 0x6048;
  lhz r3, 0x10(r31);
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  li r0, 0;
  addi r3, r1, 8;
  sth r0, 0x10(r31);
  bl utl_freebuf;
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: bta_hh_close_act
// PAL: 0x80136690..0x80136890
MARK_BINARY_BLOB(bta_hh_close_act, 0x80136690, 0x80136890);
asm UNKNOWN_FUNCTION(bta_hh_close_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  li r30, 3;
  sth r0, 0xc(r1);
  lbz r0, 0x17(r3);
  lwz r6, 8(r4);
  cmpwi r0, 0;
  beq lbl_801366c8;
  li r30, 0xd;
lbl_801366c8:
  lbz r5, 0x16(r3);
  rlwinm. r0, r6, 0, 0x15, 0x17;
  stb r5, 0xd(r1);
  lwz r0, 8(r4);
  stb r0, 0xc(r1);
  bne lbl_801366fc;
  cmplwi r6, 0xf;
  beq lbl_801366fc;
  cmplwi r6, 0xe;
  beq lbl_801366fc;
  lbz r0, 0x1a(r3);
  cmpwi r0, 0;
  bne lbl_80136750;
lbl_801366fc:
  lbz r3, 0x16(r3);
  cmplwi r6, 0xf;
  li r0, 6;
  stb r3, 0x17(r1);
  bne lbl_80136714;
  li r0, 0xc;
lbl_80136714:
  stb r0, 0x16(r1);
  addi r3, r1, 0x10;
  addi r4, r31, 8;
  bl bdcpy;
  lbz r3, 0x16(r31);
  bl HID_HostCloseDev;
  lis r5, 0x8033;
  addi r4, r1, 0x10;
  addi r5, r5, 0x6048;
  li r3, 2;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  bl bta_hh_trace_dev_db;
  b lbl_80136878;
lbl_80136750:
  lbz r3, 0x16(r3);
  lbz r4, 0x15(r31);
  bl bta_hh_co_close;
  lbz r4, 0x15(r31);
  addi r5, r31, 8;
  li r3, 0x17;
  bl bta_sys_conn_close;
  lis r4, 0x8033;
  li r0, 0;
  addi r4, r4, 0x6048;
  lbz r3, 0x22d(r4);
  addi r3, r3, -1;
  stb r3, 0x22d(r4);
  stb r0, 0x1a(r31);
  lbz r0, 0xc(r1);
  cmpwi r0, 0;
  beq lbl_8013679c;
  li r0, 6;
  stb r0, 0xc(r1);
lbl_8013679c:
  lis r5, 0x8033;
  mr r3, r30;
  addi r5, r5, 0x6048;
  addi r4, r1, 0xc;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  lbz r0, 0x17(r31);
  cmpwi r0, 0;
  beq lbl_801367d4;
  lbz r3, 0x16(r31);
  bl HID_HostRemoveDev;
  mr r3, r31;
  bl bta_hh_clean_up_kdev;
lbl_801367d4:
  bl bta_hh_trace_dev_db;
  li r4, 0;
  lis r3, 0x8033;
  stb r4, 0x17(r31);
  addi r3, r3, 0x6048;
  sth r4, 0x10(r31);
  lbz r0, 0x22d(r3);
  cmpwi r0, 0;
  bne lbl_80136878;
  lbz r0, 0x22e(r3);
  cmpwi r0, 0;
  beq lbl_80136878;
  stb r4, 8(r1);
  bl HID_HostDeregister;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013681c;
  li r0, 6;
  stb r0, 8(r1);
lbl_8013681c:
  lis r31, 0x8033;
  li r30, 0;
  addi r31, r31, 0x6048;
lbl_80136828:
  rlwinm r0, r30, 5, 0x13, 0x1a;
  add r3, r31, r0;
  addi r3, r3, 0x14;
  bl utl_freebuf;
  addi r30, r30, 1;
  cmplwi r30, 0x10;
  blt lbl_80136828;
  lis r31, 0x8033;
  addi r31, r31, 0x6048;
  addi r3, r31, 0x228;
  bl utl_freebuf;
  lwz r12, 0x224(r31);
  addi r4, r1, 8;
  li r3, 1;
  mtctr r12;
  bctrl;
  mr r3, r31;
  li r4, 0;
  li r5, 0x230;
  bl memset;
lbl_80136878:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_get_dscp_act
// PAL: 0x80136890..0x801368ac
MARK_BINARY_BLOB(bta_hh_get_dscp_act, 0x80136890, 0x801368ac);
asm UNKNOWN_FUNCTION(bta_hh_get_dscp_act) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  mr r4, r3;
  addi r5, r5, 0x6048;
  li r3, 0xa;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: bta_hh_maint_dev_act
// PAL: 0x801368ac..0x80136a10
MARK_BINARY_BLOB(bta_hh_maint_dev_act, 0x801368ac, 0x80136a10);
asm UNKNOWN_FUNCTION(bta_hh_maint_dev_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r5, 6;
  stw r0, 0x24(r1);
  li r0, 0xff;
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  stb r5, 0x16(r1);
  stb r0, 0x17(r1);
  lhz r0, 0x10(r4);
  cmpwi r0, 0xc;
  beq lbl_8013697c;
  bge lbl_801369c0;
  cmpwi r0, 0xb;
  bge lbl_801368f4;
  b lbl_801369c0;
lbl_801368f4:
  addi r3, r1, 0x10;
  addi r4, r4, 8;
  bl bdcpy;
  lbz r3, 0x16(r30);
  cmplwi r3, 0xff;
  bne lbl_80136968;
  lhz r4, 0xe(r31);
  addi r3, r31, 8;
  addi r5, r1, 8;
  bl HID_HostAddDev;
  clrlwi. r0, r3, 0x18;
  bne lbl_80136974;
  lbz r4, 8(r1);
  li r0, 0;
  stb r0, 0x16(r1);
  mr r3, r30;
  li r6, 0;
  stb r4, 0x17(r1);
  lhz r5, 0xe(r31);
  lbz r7, 0x12(r31);
  lbz r8, 0x13(r31);
  bl bta_hh_add_device_to_list;
  lis r3, 0x8033;
  lbz r0, 8(r1);
  addi r3, r3, 0x6048;
  lbz r4, 0x12(r30);
  add r3, r3, r0;
  stb r4, 0x214(r3);
  b lbl_80136974;
lbl_80136968:
  li r0, 0;
  stb r3, 0x17(r1);
  stb r0, 0x16(r1);
lbl_80136974:
  bl bta_hh_trace_dev_db;
  b lbl_801369dc;
lbl_8013697c:
  lhz r0, 6(r4);
  addi r3, r1, 0x10;
  addi r4, r30, 8;
  stb r0, 0x17(r1);
  bl bdcpy;
  lbz r0, 0x1c(r30);
  cmplwi r0, 3;
  beq lbl_801369dc;
  lbz r3, 0x17(r1);
  bl HID_HostRemoveDev;
  clrlwi. r0, r3, 0x18;
  bne lbl_801369dc;
  li r0, 0;
  mr r3, r30;
  stb r0, 0x16(r1);
  bl bta_hh_clean_up_kdev;
  b lbl_801369dc;
lbl_801369c0:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_801369dc;
  lis r4, 0x8028;
  li r3, 0x504;
  addi r4, r4, 0x2db0;
  bl LogMsg_0;
lbl_801369dc:
  lis r5, 0x8033;
  addi r4, r1, 0x10;
  addi r5, r5, 0x6048;
  lhz r3, 0x10(r31);
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_get_acl_q_info
// PAL: 0x80136a10..0x80136b2c
MARK_BINARY_BLOB(bta_hh_get_acl_q_info, 0x80136a10, 0x80136b2c);
asm UNKNOWN_FUNCTION(bta_hh_get_acl_q_info) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_27;
  addi r3, r1, 8;
  li r31, 0;
  li r4, 0;
  li r5, 0x1e;
  bl memset;
  lis r30, 0x8034;
  lis r29, 0x8033;
  addi r30, r30, -28872;
  li r27, 0;
  addi r29, r29, 0x6048;
lbl_80136a4c:
  rlwinm r0, r27, 5, 0x13, 0x1a;
  add r3, r29, r0;
  lbz r0, 0x28(r3);
  cmpwi r0, 0;
  beq lbl_80136acc;
  lbz r0, 0x2c(r3);
  cmplwi r0, 3;
  bne lbl_80136acc;
  lbz r4, 0x26(r3);
  clrlwi r0, r31, 0x18;
  mulli r5, r0, 6;
  addi r28, r1, 8;
  li r3, 0;
  add r28, r28, r5;
  mulli r0, r4, 0x34;
  stb r4, 6(r28);
  add r4, r30, r0;
  lhz r4, 0x16(r4);
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  beq lbl_80136ac8;
  lwz r3, 0x10(r3);
  cmpwi r3, 0;
  beq lbl_80136ac8;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_80136ac8;
  lhz r0, 0x4c(r3);
  sth r0, 8(r28);
  lhz r0, 0x38(r3);
  sth r0, 0xa(r28);
lbl_80136ac8:
  addi r31, r31, 1;
lbl_80136acc:
  addi r27, r27, 1;
  cmplwi r27, 0x10;
  blt lbl_80136a4c;
  lis r4, 0x8034;
  lis r3, 0x8033;
  addi r4, r4, -27840;
  clrlwi r0, r31, 0x18;
  addi r3, r3, 0x6048;
  lhz r6, 4(r4);
  lhz r5, 2(r4);
  addi r4, r1, 8;
  lwz r12, 0x224(r3);
  li r3, 0xf;
  sth r6, 8(r1);
  sth r5, 0xa(r1);
  sth r0, 0xc(r1);
  mtctr r12;
  bctrl;
  addi r11, r1, 0x40;
  bl _restgpr_27;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: bta_hh_write_dev_act
// PAL: 0x80136b2c..0x80136cf4
MARK_BINARY_BLOB(bta_hh_write_dev_act, 0x80136b2c, 0x80136cf4);
asm UNKNOWN_FUNCTION(bta_hh_write_dev_act) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  sth r0, 8(r1);
  lbz r31, 8(r4);
  lbz r0, 0x16(r3);
  stb r0, 9(r1);
  lbz r3, 0x16(r3);
  lbz r4, 8(r4);
  lbz r5, 9(r30);
  lhz r6, 0xc(r30);
  lbz r7, 0xa(r30);
  lwz r8, 0x10(r30);
  bl HID_HostWriteDev;
  clrlwi. r5, r3, 0x18;
  beq lbl_80136c08;
  lbz r0, -0x6610(r13);
  cmplwi r0, 1;
  blt lbl_80136ba0;
  lis r4, 0x8028;
  li r3, 0x500;
  addi r4, r4, 0x2dc0;
  bl LogMsg_1;
lbl_80136ba0:
  li r0, 6;
  stb r0, 8(r1);
  lbz r0, 8(r30);
  cmplwi r0, 1;
  beq lbl_80136bdc;
  cmplwi r0, 0xa;
  beq lbl_80136bdc;
  lis r5, 0x8033;
  mr r3, r31;
  addi r5, r5, 0x6048;
  addi r4, r1, 8;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  b lbl_80136cd8;
lbl_80136bdc:
  lbz r0, 9(r30);
  cmplwi r0, 5;
  bne lbl_80136cd8;
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x6048;
  li r3, 0xd;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  b lbl_80136cd8;
lbl_80136c08:
  lbz r5, 8(r30);
  cmpwi r5, 0xa;
  beq lbl_80136c3c;
  bge lbl_80136c54;
  cmpwi r5, 1;
  beq lbl_80136c3c;
  blt lbl_80136c54;
  cmpwi r5, 4;
  bge lbl_80136c34;
  b lbl_80136c54;
  b lbl_80136c54;
lbl_80136c34:
  sth r31, 0x10(r29);
  b lbl_80136c70;
lbl_80136c3c:
  lbz r0, 9(r30);
  cmplwi r0, 5;
  bne lbl_80136c70;
  li r0, 1;
  stb r0, 0x17(r29);
  b lbl_80136c70;
lbl_80136c54:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80136c70;
  lis r4, 0x8028;
  li r3, 0x504;
  addi r4, r4, 0x2ddc;
  bl LogMsg_1;
lbl_80136c70:
  lbz r0, 8(r30);
  cmplwi r0, 1;
  beq lbl_80136ca0;
  lbz r4, 0x15(r29);
  addi r5, r29, 8;
  li r3, 0x17;
  bl bta_sys_busy;
  lbz r4, 0x15(r29);
  addi r5, r29, 8;
  li r3, 0x17;
  bl bta_sys_idle;
  b lbl_80136cd8;
lbl_80136ca0:
  lbz r0, 9(r30);
  cmplwi r0, 3;
  bne lbl_80136cc0;
  lbz r4, 0x15(r29);
  addi r5, r29, 8;
  li r3, 0x17;
  bl bta_sys_sco_close;
  b lbl_80136cd8;
lbl_80136cc0:
  cmplwi r0, 4;
  bne lbl_80136cd8;
  lbz r4, 0x15(r29);
  addi r5, r29, 8;
  li r3, 0x17;
  bl bta_sys_busy;
lbl_80136cd8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_cback
// PAL: 0x80136cf4..0x80136f8c
MARK_BINARY_BLOB(bta_hh_cback, 0x80136cf4, 0x80136f8c);
asm UNKNOWN_FUNCTION(bta_hh_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8028;
  stw r0, 0x24(r1);
  addi r7, r7, 0x2a58;
  stw r31, 0x1c(r1);
  li r31, 0x1710;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, -0x6610(r13);
  stw r6, 8(r1);
  cmplwi r0, 5;
  blt lbl_80136db0;
  cmplwi r4, 8;
  bgt lbl_80136da0;
  lis r3, 0x8028;
  slwi r0, r4, 2;
  addi r3, r3, 0x2f2c;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r5, r7, 0x3ac;
  b lbl_80136da4;
  addi r5, r7, 0x3c0;
  b lbl_80136da4;
  addi r5, r7, 0x3d4;
  b lbl_80136da4;
  addi r5, r7, 0x3ec;
  b lbl_80136da4;
  addi r5, r7, 0x404;
  b lbl_80136da4;
  addi r5, r7, 0x41c;
  b lbl_80136da4;
  addi r5, r7, 0x434;
  b lbl_80136da4;
  addi r5, r7, 0x44c;
  b lbl_80136da4;
  addi r5, r7, 0x464;
  b lbl_80136da4;
lbl_80136da0:
  addi r5, r7, 0x47c;
lbl_80136da4:
  addi r4, r7, 0x490;
  li r3, 0x504;
  bl LogMsg_1;
lbl_80136db0:
  cmplwi r29, 8;
  bgt lbl_80136f3c;
  lis r3, 0x8028;
  slwi r0, r29, 2;
  addi r3, r3, 0x2f08;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r31, 0x1702;
  b lbl_80136f3c;
  li r31, 0x1703;
  b lbl_80136f3c;
  li r31, 0x1704;
  b lbl_80136f3c;
  li r31, 0x1706;
  b lbl_80136f3c;
  li r31, 0x1705;
  b lbl_80136f3c;
  addi r3, r1, 8;
  bl utl_freebuf;
  b lbl_80136f3c;
  lis r4, 0x8033;
  li r0, 2;
  addi r4, r4, 0x6048;
  li r5, 0;
  mtctr r0;
lbl_80136e18:
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136e38;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136e38:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136e5c;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136e5c:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136e80;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136e80:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136ea4;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136ea4:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136ec8;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136ec8:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136eec;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136eec:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136f10;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136f10:
  addi r5, r5, 1;
  rlwinm r0, r5, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x26(r3);
  cmplw r28, r0;
  bne lbl_80136f34;
  li r0, 1;
  stb r0, 0x27(r3);
  b lbl_80136f3c;
lbl_80136f34:
  addi r5, r5, 1;
  bdnz lbl_80136e18;
lbl_80136f3c:
  cmplwi r31, 0x1710;
  beq lbl_80136f6c;
  li r3, 0x18;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80136f6c;
  sth r31, 0(r3);
  sth r28, 6(r3);
  stw r30, 8(r3);
  lwz r0, 8(r1);
  stw r0, 0xc(r3);
  bl bta_sys_sendmsg;
lbl_80136f6c:
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
