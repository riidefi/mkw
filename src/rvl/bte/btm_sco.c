#include "btm_sco.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_acl.h"
#include "hcicmds.h"

// Symbol: btm_sco_init
// PAL: 0x8013e2b0..0x8013e2f4
MARK_BINARY_BLOB(btm_sco_init, 0x8013e2b0, 0x8013e2f4);
asm UNKNOWN_FUNCTION(btm_sco_init) {
  // clang-format off
  nofralloc;
  lis r3, 0x8025;
  lwzu r6, -0x3600(r3);
  lis r4, 1;
  lis r7, 0x8033;
  addi r8, r4, -1;
  lwz r5, 4(r3);
  addi r7, r7, 0x6278;
  lwz r4, 8(r3);
  lwz r3, 0xc(r3);
  li r0, 2;
  sth r8, 0x18f6(r7);
  stw r6, 0x18f8(r7);
  stw r5, 0x18fc(r7);
  stw r4, 0x1900(r7);
  stw r3, 0x1904(r7);
  stb r0, 0x1909(r7);
  blr;
  // clang-format on
}

// Symbol: btm_esco_conn_rsp
// PAL: 0x8013e2f4..0x8013e4d0
MARK_BINARY_BLOB(btm_esco_conn_rsp, 0x8013e2f4, 0x8013e4d0);
asm UNKNOWN_FUNCTION(btm_esco_conn_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r26, r3;
  mr r27, r4;
  mr r29, r5;
  mr r28, r6;
  li r31, 0;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8013e358;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_8013e4b8;
  lis r4, 0x8028;
  lis r3, 0xd;
  addi r4, r4, 0x3df0;
  bl LogMsg_0;
  b lbl_8013e4b8;
lbl_8013e358:
  cmplwi r26, 3;
  bge lbl_8013e374;
  mulli r0, r26, 0x34;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  addi r31, r3, 0x1854;
lbl_8013e374:
  cmpwi r27, 0;
  beq lbl_8013e3d4;
  cmpwi r31, 0;
  beq lbl_8013e398;
  lhz r3, 8(r31);
  addi r0, r3, -2;
  cntlzw r0, r0;
  rlwinm r0, r0, 0x1b, 0x10, 0x1f;
  sth r0, 8(r31);
lbl_8013e398:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x1908(r3);
  cmpwi r0, 0;
  bne lbl_8013e3c0;
  mr r3, r30;
  mr r4, r29;
  mr r5, r27;
  bl btsnd_hcic_reject_conn;
  b lbl_8013e4b8;
lbl_8013e3c0:
  mr r3, r30;
  mr r4, r29;
  mr r5, r27;
  bl btsnd_hcic_reject_esco_conn;
  b lbl_8013e4b8;
lbl_8013e3d4:
  li r3, 1;
  bl btm_chg_all_acl_pkt_types;
  li r0, 3;
  lis r3, 0x8033;
  sth r0, 8(r31);
  addi r3, r3, 0x6278;
  lbz r0, 0x1908(r3);
  cmpwi r0, 0;
  beq lbl_8013e4a8;
  lbz r0, 0x2e(r31);
  cmplwi r0, 2;
  bne lbl_8013e4a8;
  cmpwi r28, 0;
  beq lbl_8013e42c;
  lwz r3, 0(r28);
  lwz r0, 4(r28);
  stw r3, 0x14(r31);
  stw r0, 0x18(r31);
  lwz r3, 8(r28);
  lwz r0, 0xc(r28);
  stw r3, 0x1c(r31);
  stw r0, 0x20(r31);
lbl_8013e42c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r4, 0x1904(r3);
  sth r4, 0x20(r31);
  lhz r5, 0x656(r3);
  and r3, r4, r5;
  rlwinm. r0, r3, 0, 0x1a, 0x1c;
  clrlwi r28, r3, 0x1a;
  bne lbl_8013e458;
  ori r0, r28, 8;
  clrlwi r28, r0, 0x10;
lbl_8013e458:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x636(r3);
  cmplwi r0, 3;
  blt lbl_8013e47c;
  or r0, r4, r5;
  rlwinm r0, r0, 0, 0x16, 0x19;
  or r0, r28, r0;
  clrlwi r28, r0, 0x10;
lbl_8013e47c:
  lwz r5, 0x14(r31);
  mr r3, r30;
  lwz r6, 0x18(r31);
  mr r4, r29;
  lhz r7, 0x1c(r31);
  clrlwi r10, r28, 0x10;
  lhz r8, 0x1e(r31);
  lbz r9, 0x22(r31);
  bl btsnd_hcic_accept_esco_conn;
  sth r28, 0x20(r31);
  b lbl_8013e4b8;
lbl_8013e4a8:
  mr r3, r30;
  mr r4, r29;
  li r5, 0;
  bl btsnd_hcic_accept_conn;
lbl_8013e4b8:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sco_chk_pend_unpark
// PAL: 0x8013e4d0..0x8013e65c
MARK_BINARY_BLOB(btm_sco_chk_pend_unpark, 0x8013e4d0, 0x8013e65c);
asm UNKNOWN_FUNCTION(btm_sco_chk_pend_unpark) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_20;
  lis r28, 0x8033;
  mr r23, r3;
  addi r28, r28, 0x6278;
  mr r24, r4;
  mr r25, r5;
  li r27, 0;
  addi r26, r28, 0x1854;
  lis r30, 0xd;
  lis r31, 0x8028;
  lis r21, 0x8028;
  li r22, 3;
lbl_8013e510:
  lhz r0, 8(r26);
  cmplwi r0, 6;
  bne lbl_8013e634;
  cmpwi r25, 0;
  bne lbl_8013e634;
  cmpwi r23, 0;
  bne lbl_8013e634;
  addi r3, r26, 0x28;
  bl BTM_GetHCIConnHandle;
  clrlwi r5, r3, 0x10;
  mr r29, r3;
  cmplw r24, r5;
  bne lbl_8013e634;
  lbz r0, 0x27c0(r28);
  cmplwi r0, 3;
  blt lbl_8013e560;
  lbz r6, 0x1909(r28);
  addi r3, r30, 2;
  addi r4, r31, 0x3ecc;
  bl LogMsg_2;
lbl_8013e560:
  li r3, 1;
  bl btm_chg_all_acl_pkt_types;
  lbz r0, 0x1908(r28);
  cmpwi r0, 0;
  bne lbl_8013e594;
  lhz r0, 0x20(r26);
  clrlwi r3, r29, 0x10;
  rlwinm r4, r0, 5, 0x18, 0x1a;
  bl btsnd_hcic_add_SCO_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013e624;
  li r0, 3;
  b lbl_8013e628;
lbl_8013e594:
  lbz r0, 0x636(r28);
  lhz r3, 0x656(r28);
  lhz r4, 0x20(r26);
  cmplwi r0, 3;
  and r0, r4, r3;
  clrlwi r20, r0, 0x1a;
  blt lbl_8013e5c0;
  or r0, r4, r3;
  rlwinm r0, r0, 0, 0x16, 0x19;
  or r0, r20, r0;
  clrlwi r20, r0, 0x10;
lbl_8013e5c0:
  lbz r0, 0x27c0(r28);
  cmplwi r0, 3;
  blt lbl_8013e5f0;
  lwz r5, 0x14(r26);
  addi r3, r30, 2;
  lwz r6, 0x18(r26);
  addi r4, r21, 0x3e7c;
  lhz r7, 0x1c(r26);
  clrlwi r10, r20, 0x10;
  lhz r8, 0x1e(r26);
  lbz r9, 0x22(r26);
  bl LogMsg_6;
lbl_8013e5f0:
  lwz r4, 0x14(r26);
  clrlwi r3, r29, 0x10;
  lwz r5, 0x18(r26);
  clrlwi r9, r20, 0x10;
  lhz r6, 0x1c(r26);
  lhz r7, 0x1e(r26);
  lbz r8, 0x22(r26);
  bl btsnd_hcic_setup_esco_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013e620;
  li r0, 3;
  b lbl_8013e628;
lbl_8013e620:
  sth r20, 0x20(r26);
lbl_8013e624:
  li r0, 1;
lbl_8013e628:
  cmplwi r0, 1;
  bne lbl_8013e634;
  sth r22, 8(r26);
lbl_8013e634:
  addi r27, r27, 1;
  addi r26, r26, 0x34;
  cmplwi r27, 3;
  blt lbl_8013e510;
  addi r11, r1, 0x40;
  bl _restgpr_20;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: btm_sco_conn_req
// PAL: 0x8013e65c..0x8013e83c
MARK_BINARY_BLOB(btm_sco_conn_req, 0x8013e65c, 0x8013e83c);
asm UNKNOWN_FUNCTION(btm_sco_conn_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  lis r6, 0x8033;
  mr r30, r3;
  addi r6, r6, 0x6278;
  mr r29, r4;
  mr r31, r5;
  li r28, 0;
  addi r27, r6, 0x1854;
lbl_8013e68c:
  lhz r3, 8(r27);
  cmplwi r3, 1;
  bne lbl_8013e6a4;
  lbz r0, 0xd(r27);
  cmpwi r0, 0;
  bne lbl_8013e6ac;
lbl_8013e6a4:
  cmplwi r3, 3;
  bne lbl_8013e74c;
lbl_8013e6ac:
  mr r4, r30;
  addi r3, r27, 0x28;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013e74c;
  li r0, 1;
  mr r4, r30;
  stb r0, 0xd(r27);
  addi r3, r27, 0x28;
  li r5, 6;
  stb r31, 0x2e(r27);
  bl memcpy;
  lwz r0, 0x10(r27);
  cmpwi r0, 0;
  bne lbl_8013e704;
  mr r5, r30;
  clrlwi r3, r28, 0x10;
  li r4, 0;
  li r6, 0;
  bl btm_esco_conn_rsp;
  b lbl_8013e824;
lbl_8013e704:
  mr r4, r30;
  addi r3, r1, 0xa;
  li r5, 6;
  bl memcpy;
  mr r4, r29;
  addi r3, r1, 0x10;
  li r5, 3;
  bl memcpy;
  li r0, 2;
  stb r31, 0x13(r1);
  addi r4, r1, 8;
  li r3, 2;
  sth r0, 8(r27);
  lwz r12, 0x10(r27);
  sth r28, 8(r1);
  mtctr r12;
  bctrl;
  b lbl_8013e824;
lbl_8013e74c:
  addi r28, r28, 1;
  addi r27, r27, 0x34;
  cmplwi r28, 3;
  blt lbl_8013e68c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r0, 0x1850(r3);
  cmpwi r0, 0;
  beq lbl_8013e7e8;
  li r0, 3;
  addi r28, r3, 0x1854;
  li r27, 0;
  mtctr r0;
lbl_8013e780:
  lhz r0, 8(r28);
  cmpwi r0, 0;
  bne lbl_8013e7b8;
  li r0, 0;
  li r29, 1;
  stb r0, 0xc(r28);
  mr r4, r30;
  addi r3, r28, 0x28;
  li r5, 6;
  sth r29, 8(r28);
  stb r31, 0x2e(r28);
  bl memcpy;
  stb r29, 0xd(r28);
  b lbl_8013e7c4;
lbl_8013e7b8:
  addi r27, r27, 1;
  addi r28, r28, 0x34;
  bdnz lbl_8013e780;
lbl_8013e7c4:
  clrlwi r3, r27, 0x10;
  cmplwi r3, 3;
  bge lbl_8013e7e8;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r12, 0x1850(r4);
  mtctr r12;
  bctrl;
  b lbl_8013e824;
lbl_8013e7e8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013e810;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x3f1c;
  bl LogMsg_0;
lbl_8013e810:
  mr r5, r30;
  li r3, 3;
  li r4, 0xd;
  li r6, 0;
  bl btm_esco_conn_rsp;
lbl_8013e824:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_sco_connected
// PAL: 0x8013e83c..0x8013e9dc
MARK_BINARY_BLOB(btm_sco_connected, 0x8013e83c, 0x8013e9dc);
asm UNKNOWN_FUNCTION(btm_sco_connected) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r7, 0x8033;
  mr r24, r3;
  addi r7, r7, 0x6278;
  mr r25, r4;
  sth r3, 0x18f6(r7);
  mr r26, r5;
  mr r29, r6;
  addi r31, r7, 0x1854;
  li r27, 0;
  li r30, 0;
lbl_8013e878:
  lhz r28, 8(r31);
  addis r3, r28, 1;
  addi r0, r3, -1;
  clrlwi r0, r0, 0x10;
  cmplwi r0, 2;
  bgt lbl_8013e9b4;
  lbz r0, 0xd(r31);
  cmpwi r0, 0;
  beq lbl_8013e9b4;
  cmpwi r25, 0;
  beq lbl_8013e8bc;
  mr r4, r25;
  addi r3, r31, 0x28;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013e9b4;
lbl_8013e8bc:
  cmpwi r24, 0;
  beq lbl_8013e8fc;
  cmplwi r28, 3;
  bne lbl_8013e8f0;
  cmplwi r24, 0x23;
  beq lbl_8013e9c4;
  li r0, 0;
  clrlwi r3, r30, 0x10;
  sth r0, 8(r31);
  lwz r12, 4(r31);
  mtctr r12;
  bctrl;
  b lbl_8013e9c4;
lbl_8013e8f0:
  li r0, 1;
  sth r0, 8(r31);
  b lbl_8013e9c4;
lbl_8013e8fc:
  cmplwi r28, 1;
  bne lbl_8013e908;
  li r27, 1;
lbl_8013e908:
  li r0, 4;
  lis r3, 0x8033;
  sth r0, 8(r31);
  addi r3, r3, 0x6278;
  sth r26, 0xa(r31);
  lbz r0, 0x1908(r3);
  cmpwi r0, 0;
  bne lbl_8013e960;
  li r0, 0;
  cmpwi r27, 0;
  stb r0, 0x2e(r31);
  beq lbl_8013e9a0;
  lhz r6, 0x20(r31);
  clrlwi r3, r30, 0x10;
  lhz r5, 0x1c(r31);
  addi r4, r1, 8;
  lbz r0, 0x22(r31);
  sth r6, 0xa(r1);
  sth r5, 8(r1);
  stb r0, 0xc(r1);
  bl BTM_ChangeEScoLinkParms;
  b lbl_8013e9a0;
lbl_8013e960:
  cmpwi r29, 0;
  beq lbl_8013e9a0;
  lhz r3, 0(r29);
  lhz r0, 2(r29);
  sth r3, 0x24(r31);
  sth r0, 0x26(r31);
  lhz r3, 4(r29);
  lhz r0, 6(r29);
  sth r3, 0x28(r31);
  sth r0, 0x2a(r31);
  lhz r0, 8(r29);
  sth r0, 0x2c(r31);
  lhz r0, 0xa(r29);
  sth r0, 0x2e(r31);
  lhz r0, 0xc(r29);
  sth r0, 0x30(r31);
lbl_8013e9a0:
  lwz r12, 0(r31);
  clrlwi r3, r30, 0x10;
  mtctr r12;
  bctrl;
  b lbl_8013e9c4;
lbl_8013e9b4:
  addi r30, r30, 1;
  addi r31, r31, 0x34;
  cmplwi r30, 3;
  blt lbl_8013e878;
lbl_8013e9c4:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: BTM_RemoveSco
// PAL: 0x8013e9dc..0x8013ea94
MARK_BINARY_BLOB(BTM_RemoveSco, 0x8013e9dc, 0x8013ea94);
asm UNKNOWN_FUNCTION(BTM_RemoveSco) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  cmplwi r3, 3;
  stw r0, 0x14(r1);
  mulli r0, r3, 0x34;
  addi r4, r4, 0x6278;
  stw r31, 0xc(r1);
  add r31, r4, r0;
  stw r30, 8(r1);
  bge lbl_8013ea14;
  lhz r30, 0x185c(r31);
  cmpwi r30, 0;
  bne lbl_8013ea1c;
lbl_8013ea14:
  li r3, 7;
  b lbl_8013ea7c;
lbl_8013ea1c:
  lhz r0, 0x185e(r31);
  cmplwi r0, 0xffff;
  beq lbl_8013ea30;
  cmplwi r30, 6;
  bne lbl_8013ea50;
lbl_8013ea30:
  lis r3, 1;
  li r0, 0;
  addi r4, r3, -1;
  sth r4, 0x185e(r31);
  li r3, 0;
  sth r0, 0x185c(r31);
  stw r0, 0x1864(r31);
  b lbl_8013ea7c;
lbl_8013ea50:
  li r0, 5;
  li r4, 0x13;
  sth r0, 0x185c(r31);
  lhz r3, 0x185e(r31);
  bl btsnd_hcic_disconnect;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013ea78;
  sth r30, 0x185c(r31);
  li r3, 3;
  b lbl_8013ea7c;
lbl_8013ea78:
  li r3, 1;
lbl_8013ea7c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_remove_sco_links
// PAL: 0x8013ea94..0x8013eb18
MARK_BINARY_BLOB(btm_remove_sco_links, 0x8013ea94, 0x8013eb18);
asm UNKNOWN_FUNCTION(btm_remove_sco_links) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  addi r31, r4, 0x1854;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8013eac0:
  lbz r0, 0xd(r31);
  cmpwi r0, 0;
  beq lbl_8013eaec;
  mr r4, r29;
  addi r3, r31, 0x28;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013eaec;
  clrlwi r3, r30, 0x10;
  bl BTM_RemoveSco;
lbl_8013eaec:
  addi r30, r30, 1;
  addi r31, r31, 0x34;
  cmplwi r30, 3;
  blt lbl_8013eac0;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sco_removed
// PAL: 0x8013eb18..0x8013ec2c
MARK_BINARY_BLOB(btm_sco_removed, 0x8013eb18, 0x8013ec2c);
asm UNKNOWN_FUNCTION(btm_sco_removed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x14(r1);
  addi r5, r5, 0x6278;
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0;
  sth r4, 0x18f6(r5);
  lhz r0, 0x185c(r5);
  cmpwi r0, 7;
  bge lbl_8013eb58;
  cmpwi r0, 2;
  bge lbl_8013eb54;
  b lbl_8013eb58;
lbl_8013eb54:
  li r3, 1;
lbl_8013eb58:
  lhz r0, 0x1890(r5);
  cmpwi r0, 7;
  bge lbl_8013eb74;
  cmpwi r0, 2;
  bge lbl_8013eb70;
  b lbl_8013eb74;
lbl_8013eb70:
  addi r3, r3, 1;
lbl_8013eb74:
  lhz r0, 0x18c4(r5);
  cmpwi r0, 7;
  bge lbl_8013eb90;
  cmpwi r0, 2;
  bge lbl_8013eb8c;
  b lbl_8013eb90;
lbl_8013eb8c:
  addi r3, r3, 1;
lbl_8013eb90:
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bgt lbl_8013eba4;
  li r3, 0;
  bl btm_chg_all_acl_pkt_types;
lbl_8013eba4:
  lis r3, 0x8033;
  li r0, 3;
  addi r3, r3, 0x6278;
  li r6, 0;
  addi r5, r3, 0x1854;
  mtctr r0;
lbl_8013ebbc:
  lhz r0, 8(r5);
  cmpwi r0, 0;
  beq lbl_8013ec0c;
  cmplwi r0, 1;
  beq lbl_8013ec0c;
  lhz r0, 0xa(r5);
  cmplw r0, r31;
  bne lbl_8013ec0c;
  li r4, 0;
  lis r3, 1;
  sth r4, 8(r5);
  addi r0, r3, -1;
  clrlwi r3, r6, 0x10;
  sth r0, 0xa(r5);
  stb r4, 0xd(r5);
  stw r4, 0x10(r5);
  lwz r12, 4(r5);
  mtctr r12;
  bctrl;
  b lbl_8013ec18;
lbl_8013ec0c:
  addi r6, r6, 1;
  addi r5, r5, 0x34;
  bdnz lbl_8013ebbc;
lbl_8013ec18:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sco_acl_removed
// PAL: 0x8013ec2c..0x8013ece0
MARK_BINARY_BLOB(btm_sco_acl_removed, 0x8013ec2c, 0x8013ece0);
asm UNKNOWN_FUNCTION(btm_sco_acl_removed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x1854;
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
lbl_8013ec60:
  lhz r0, 8(r30);
  cmpwi r0, 0;
  beq lbl_8013ecb0;
  cmpwi r28, 0;
  beq lbl_8013ec98;
  mr r4, r28;
  addi r3, r30, 0x28;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013ecb0;
  lbz r0, 0xd(r30);
  cmpwi r0, 0;
  beq lbl_8013ecb0;
lbl_8013ec98:
  sth r31, 8(r30);
  clrlwi r3, r29, 0x10;
  stw r31, 0x10(r30);
  lwz r12, 4(r30);
  mtctr r12;
  bctrl;
lbl_8013ecb0:
  addi r29, r29, 1;
  addi r30, r30, 0x34;
  cmplwi r29, 3;
  blt lbl_8013ec60;
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

// Symbol: btm_route_sco_data
// PAL: 0x8013ece0..0x8013ece4
MARK_BINARY_BLOB(btm_route_sco_data, 0x8013ece0, 0x8013ece4);
asm UNKNOWN_FUNCTION(btm_route_sco_data) {
  // clang-format off
  nofralloc;
  b GKI_freebuf;
  // clang-format on
}

// Symbol: BTM_ChangeEScoLinkParms
// PAL: 0x8013ece4..0x8013ee8c
MARK_BINARY_BLOB(BTM_ChangeEScoLinkParms, 0x8013ece4, 0x8013ee8c);
asm UNKNOWN_FUNCTION(BTM_ChangeEScoLinkParms) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmplwi r3, 3;
  lis r30, 0x8028;
  mr r28, r4;
  addi r30, r30, 0x3df0;
  bge lbl_8013ed28;
  mulli r0, r3, 0x34;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  add r31, r3, r0;
  lhz r0, 0x185c(r31);
  cmplwi r0, 4;
  beq lbl_8013ed30;
lbl_8013ed28:
  li r3, 6;
  b lbl_8013ee74;
lbl_8013ed30:
  lbz r0, 0x1882(r31);
  addi r29, r31, 0x1868;
  cmpwi r0, 0;
  beq lbl_8013ed4c;
  lbz r0, 0x1908(r3);
  cmpwi r0, 0;
  bne lbl_8013edac;
lbl_8013ed4c:
  lis r3, 0x8033;
  lhz r4, 2(r4);
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  clrlwi r0, r0, 0x1d;
  and r0, r4, r0;
  sth r0, 0xc(r29);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013ed8c;
  lis r3, 0xd;
  lhz r5, 0x185e(r31);
  lhz r6, 0xc(r29);
  addi r3, r3, 2;
  addi r4, r30, 0x248;
  bl LogMsg_2;
lbl_8013ed8c:
  lhz r0, 0xc(r29);
  lhz r3, 0x185e(r31);
  rlwinm r4, r0, 5, 0x18, 0x1a;
  bl btsnd_hcic_change_conn_type;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013ee70;
  li r3, 3;
  b lbl_8013ee74;
lbl_8013edac:
  lbz r0, 0x636(r3);
  lhz r3, 0x656(r3);
  lhz r4, 2(r4);
  cmplwi r0, 3;
  and r0, r4, r3;
  clrlwi r27, r0, 0x1a;
  blt lbl_8013edd8;
  or r0, r4, r3;
  rlwinm r0, r0, 0, 0x16, 0x19;
  or r0, r27, r0;
  clrlwi r27, r0, 0x10;
lbl_8013edd8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013ee00;
  lis r3, 0xd;
  lhz r5, 0x185e(r31);
  addi r3, r3, 2;
  addi r4, r30, 0x28c;
  bl LogMsg_1;
lbl_8013ee00:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013ee3c;
  lis r3, 0xd;
  lwz r5, 0(r29);
  lwz r6, 4(r29);
  addi r3, r3, 2;
  lhz r7, 0(r28);
  addi r4, r30, 0x8c;
  lhz r8, 0xa(r29);
  clrlwi r10, r27, 0x10;
  lbz r9, 4(r28);
  bl LogMsg_6;
lbl_8013ee3c:
  lhz r3, 0x185e(r31);
  clrlwi r9, r27, 0x10;
  lwz r4, 0(r29);
  lwz r5, 4(r29);
  lhz r6, 0(r28);
  lhz r7, 0xa(r29);
  lbz r8, 4(r28);
  bl btsnd_hcic_setup_esco_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013ee6c;
  li r3, 3;
  b lbl_8013ee74;
lbl_8013ee6c:
  sth r27, 2(r28);
lbl_8013ee70:
  li r3, 1;
lbl_8013ee74:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_esco_proc_conn_chg
// PAL: 0x8013ee8c..0x8013ef90
MARK_BINARY_BLOB(btm_esco_proc_conn_chg, 0x8013ee8c, 0x8013ef90);
asm UNKNOWN_FUNCTION(btm_esco_proc_conn_chg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_24;
  lis r9, 0x8033;
  mr r24, r3;
  addi r9, r9, 0x6278;
  mr r25, r4;
  lbz r0, 0x27c0(r9);
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  cmplwi r0, 4;
  mr r29, r8;
  addi r31, r9, 0x1854;
  blt lbl_8013eeec;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r25;
  mr r6, r24;
  addi r3, r3, 3;
  addi r4, r4, 0x40b4;
  bl LogMsg_2;
lbl_8013eeec:
  li r0, 3;
  li r30, 0;
  mtctr r0;
lbl_8013eef8:
  lhz r0, 8(r31);
  cmplwi r0, 4;
  bne lbl_8013ef6c;
  lhz r0, 0xa(r31);
  cmplw r25, r0;
  bne lbl_8013ef6c;
  lwz r0, 0x10(r31);
  cmpwi r0, 0;
  beq lbl_8013ef78;
  addi r3, r1, 0xe;
  addi r4, r31, 0x28;
  li r5, 6;
  bl memcpy;
  sth r28, 0x24(r31);
  addi r4, r1, 8;
  li r3, 1;
  sth r29, 0x26(r31);
  stb r26, 0x2f(r31);
  stb r27, 0x30(r31);
  lwz r12, 0x10(r31);
  stb r24, 0x14(r1);
  sth r30, 8(r1);
  sth r28, 0xa(r1);
  sth r29, 0xc(r1);
  stb r26, 0x15(r1);
  stb r27, 0x16(r1);
  mtctr r12;
  bctrl;
  b lbl_8013ef78;
lbl_8013ef6c:
  addi r30, r30, 1;
  addi r31, r31, 0x34;
  bdnz lbl_8013eef8;
lbl_8013ef78:
  addi r11, r1, 0x40;
  bl _restgpr_24;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: btm_is_sco_active
// PAL: 0x8013ef90..0x8013f000
MARK_BINARY_BLOB(btm_is_sco_active, 0x8013ef90, 0x8013f000);
asm UNKNOWN_FUNCTION(btm_is_sco_active) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lhz r0, 0x185e(r4);
  cmplw r3, r0;
  bne lbl_8013efb8;
  lhz r0, 0x185c(r4);
  cmplwi r0, 4;
  bne lbl_8013efb8;
  li r3, 1;
  blr;
lbl_8013efb8:
  lhz r0, 0x1892(r4);
  cmplw r3, r0;
  bne lbl_8013efd8;
  lhz r0, 0x1890(r4);
  cmplwi r0, 4;
  bne lbl_8013efd8;
  li r3, 1;
  blr;
lbl_8013efd8:
  lhz r0, 0x18c6(r4);
  cmplw r3, r0;
  bne lbl_8013eff8;
  lhz r0, 0x18c4(r4);
  cmplwi r0, 4;
  bne lbl_8013eff8;
  li r3, 1;
  blr;
lbl_8013eff8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: btm_num_sco_links_active
// PAL: 0x8013f000..0x8013f060
MARK_BINARY_BLOB(btm_num_sco_links_active, 0x8013f000, 0x8013f060);
asm UNKNOWN_FUNCTION(btm_num_sco_links_active) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r3, 0;
  addi r4, r4, 0x6278;
  lhz r0, 0x185c(r4);
  cmpwi r0, 7;
  bge lbl_8013f028;
  cmpwi r0, 2;
  bge lbl_8013f024;
  b lbl_8013f028;
lbl_8013f024:
  li r3, 1;
lbl_8013f028:
  lhz r0, 0x1890(r4);
  cmpwi r0, 7;
  bge lbl_8013f044;
  cmpwi r0, 2;
  bge lbl_8013f040;
  b lbl_8013f044;
lbl_8013f040:
  addi r3, r3, 1;
lbl_8013f044:
  lhz r0, 0x18c4(r4);
  cmpwi r0, 7;
  bgelr;
  cmpwi r0, 2;
  bltlr;
  addi r3, r3, 1;
  blr;
  // clang-format on
}

// Symbol: btm_is_sco_active_by_bdaddr
// PAL: 0x8013f060..0x8013f0e8
MARK_BINARY_BLOB(btm_is_sco_active_by_bdaddr, 0x8013f060, 0x8013f0e8);
asm UNKNOWN_FUNCTION(btm_is_sco_active_by_bdaddr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x1854;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8013f08c:
  mr r4, r29;
  addi r3, r30, 0x28;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013f0b8;
  lhz r0, 8(r30);
  cmplwi r0, 4;
  bne lbl_8013f0b8;
  li r3, 1;
  b lbl_8013f0cc;
lbl_8013f0b8:
  addi r31, r31, 1;
  addi r30, r30, 0x34;
  cmplwi r31, 3;
  blt lbl_8013f08c;
  li r3, 0;
lbl_8013f0cc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
