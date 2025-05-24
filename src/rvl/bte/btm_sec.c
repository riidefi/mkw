#include "btm_sec.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_task1.h"
#include "bte_logmsg.h"
#include "btm_dev.h"
#include "btm_devctl.h"
#include "btm_inq.h"

static const u8 unk_803886ad = 0xFF;
static const u8 unk_803886ac = 0xFF;
static const u8 unk_803886ab = 0xFF;
static const u8 unk_803886aa = 0xFF;
static const u8 unk_803886a9 = 0xFF;
static const u8 unk_803886a8 = 0xFF;

extern void sdata2_use(const u8*);

void sdata2_ordering() {
  sdata2_use(&unk_803886a8);
  sdata2_use(&unk_803886a9);
  sdata2_use(&unk_803886aa);
  sdata2_use(&unk_803886ab);
  sdata2_use(&unk_803886ac);
  sdata2_use(&unk_803886ad);
}

// Extern function references.
// PAL: 0x801447e0
extern UNKNOWN_FUNCTION(btsnd_hcic_create_conn);
// PAL: 0x801448c0
extern UNKNOWN_FUNCTION(btsnd_hcic_disconnect);
// PAL: 0x80144a34
extern UNKNOWN_FUNCTION(btsnd_hcic_reject_conn);
// PAL: 0x80144a90
extern UNKNOWN_FUNCTION(btsnd_hcic_link_key_req_reply);
// PAL: 0x80144c30
extern UNKNOWN_FUNCTION(btsnd_hcic_link_key_neg_reply);
// PAL: 0x80144cd0
extern UNKNOWN_FUNCTION(btsnd_hcic_pin_code_req_reply);
// PAL: 0x80144eb4
extern UNKNOWN_FUNCTION(btsnd_hcic_pin_code_neg_reply);
// PAL: 0x80144fe4
extern UNKNOWN_FUNCTION(btsnd_hcic_auth_request);
// PAL: 0x80145060
extern UNKNOWN_FUNCTION(btsnd_hcic_set_conn_encrypt);
// PAL: 0x80145cb4
extern UNKNOWN_FUNCTION(btsnd_hcic_write_pin_type);
// PAL: 0x80146228
extern UNKNOWN_FUNCTION(btsnd_hcic_write_auth_enable);
// PAL: 0x8014629c
extern UNKNOWN_FUNCTION(btsnd_hcic_write_encr_mode);
// PAL: 0x8014c108
extern UNKNOWN_FUNCTION(l2c_link_hci_conn_req);
// PAL: 0x8014e2c4
extern UNKNOWN_FUNCTION(l2cu_allocate_lcb);
// PAL: 0x8014fe28
extern UNKNOWN_FUNCTION(l2cu_create_conn);

// Symbol: BTM_SecRegister
// PAL: 0x8013f0e8..0x8013f160
MARK_BINARY_BLOB(BTM_SecRegister, 0x8013f0e8, 0x8013f160);
asm UNKNOWN_FUNCTION(BTM_SecRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x14(r1);
  addi r6, r6, 0x6278;
  lwz r5, 0(r3);
  lwz r4, 4(r3);
  lbz r0, 0x27c0(r6);
  stw r5, 0x190c(r6);
  cmplwi r0, 4;
  stw r4, 0x1910(r6);
  lwz r4, 8(r3);
  lwz r0, 0xc(r3);
  stw r4, 0x1914(r6);
  stw r0, 0x1918(r6);
  lwz r4, 0x10(r3);
  lwz r0, 0x14(r3);
  stw r4, 0x191c(r6);
  stw r0, 0x1920(r6);
  blt lbl_8013f14c;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x40f0;
  bl LogMsg_0;
lbl_8013f14c:
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SecAddRmtNameNotifyCallback
// PAL: 0x8013f160..0x8013f1b0
MARK_BINARY_BLOB(BTM_SecAddRmtNameNotifyCallback, 0x8013f160, 0x8013f1b0);
asm UNKNOWN_FUNCTION(BTM_SecAddRmtNameNotifyCallback) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r0, 2;
  addi r4, r4, 0x6278;
  li r5, 0;
  mtctr r0;
lbl_8013f174:
  lwz r0, 0x192c(r4);
  cmpwi r0, 0;
  bne lbl_8013f19c;
  lis r4, 0x8033;
  slwi r0, r5, 2;
  addi r4, r4, 0x6278;
  add r4, r4, r0;
  stw r3, 0x192c(r4);
  li r3, 1;
  blr;
lbl_8013f19c:
  addi r4, r4, 4;
  addi r5, r5, 1;
  bdnz lbl_8013f174;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: BTM_SecDeleteRmtNameNotifyCallback
// PAL: 0x8013f1b0..0x8013f204
MARK_BINARY_BLOB(BTM_SecDeleteRmtNameNotifyCallback, 0x8013f1b0, 0x8013f204);
asm UNKNOWN_FUNCTION(BTM_SecDeleteRmtNameNotifyCallback) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r0, 2;
  addi r4, r4, 0x6278;
  li r5, 0;
  mtctr r0;
lbl_8013f1c4:
  lwz r0, 0x192c(r4);
  cmplw r0, r3;
  bne lbl_8013f1f0;
  lis r3, 0x8033;
  slwi r0, r5, 2;
  addi r3, r3, 0x6278;
  li r5, 0;
  add r4, r3, r0;
  stw r5, 0x192c(r4);
  li r3, 1;
  blr;
lbl_8013f1f0:
  addi r4, r4, 4;
  addi r5, r5, 1;
  bdnz lbl_8013f1c4;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: BTM_SetPinType
// PAL: 0x8013f204..0x8013f2b4
MARK_BINARY_BLOB(BTM_SetPinType, 0x8013f204, 0x8013f2b4);
asm UNKNOWN_FUNCTION(BTM_SetPinType) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x24(r1);
  addi r6, r6, 0x6278;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x27c0(r6);
  cmplwi r0, 3;
  blt lbl_8013f25c;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r29;
  mr r6, r30;
  mr r7, r31;
  addi r3, r3, 2;
  addi r4, r4, 0x4188;
  bl LogMsg_3;
lbl_8013f25c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x64e(r3);
  cmplwi r0, 1;
  ble lbl_8013f278;
  mr r3, r29;
  bl btsnd_hcic_write_pin_type;
lbl_8013f278:
  lis r6, 0x8033;
  mr r4, r30;
  addi r6, r6, 0x6278;
  mr r5, r31;
  stb r29, 0x20(r6);
  addi r3, r6, 0x22;
  stb r31, 0x21(r6);
  bl memcpy;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_SetSecurityLevel
// PAL: 0x8013f2b4..0x8013f4dc
MARK_BINARY_BLOB(BTM_SetSecurityLevel, 0x8013f2b4, 0x8013f4dc);
asm UNKNOWN_FUNCTION(BTM_SetSecurityLevel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_20;
  lis r10, 0x8033;
  lis r31, 0x8028;
  addi r10, r10, 0x6278;
  lis r11, 1;
  mr r20, r3;
  mr r21, r4;
  mr r22, r5;
  mr r23, r6;
  mr r24, r7;
  mr r25, r8;
  mr r26, r9;
  addi r31, r31, 0x40f0;
  addi r28, r11, -1;
  addi r30, r10, 0x1990;
  li r27, 0;
  li r29, 0;
lbl_8013f308:
  lbz r0, 0xe(r30);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013f370;
  lhz r0, 0xc(r30);
  cmplw r0, r24;
  bne lbl_8013f380;
  lwz r0, 0(r30);
  cmplw r0, r25;
  bne lbl_8013f380;
  lbz r0, 0xf(r30);
  cmplw r22, r0;
  bne lbl_8013f380;
  mr r3, r21;
  addi r4, r30, 0x10;
  li r5, 0x15;
  bl strncmp;
  cmpwi r3, 0;
  beq lbl_8013f368;
  mr r3, r21;
  addi r4, r30, 0x26;
  li r5, 0x15;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8013f380;
lbl_8013f368:
  li r27, 1;
  b lbl_8013f390;
lbl_8013f370:
  cmpwi r27, 0;
  bne lbl_8013f380;
  li r27, 1;
  mr r28, r29;
lbl_8013f380:
  addi r29, r29, 1;
  addi r30, r30, 0x3c;
  cmplwi r29, 0x18;
  blt lbl_8013f308;
lbl_8013f390:
  cmpwi r27, 0;
  beq lbl_8013f498;
  clrlwi r0, r29, 0x10;
  cmplwi r0, 0x18;
  blt lbl_8013f3c0;
  clrlwi r0, r28, 0x10;
  lis r3, 0x8033;
  mulli r0, r0, 0x3c;
  mr r29, r28;
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  addi r30, r3, 0x1990;
lbl_8013f3c0:
  sth r24, 0xc(r30);
  cmpwi r20, 0;
  stb r22, 0xf(r30);
  stw r25, 0(r30);
  beq lbl_8013f3f8;
  stw r26, 4(r30);
  mr r4, r21;
  addi r3, r30, 0x10;
  li r5, 0x15;
  lbz r0, 0xe(r30);
  rlwinm r0, r0, 0, 0x1d, 0x19;
  stb r0, 0xe(r30);
  bl strncpy;
  b lbl_8013f418;
lbl_8013f3f8:
  stw r26, 8(r30);
  mr r4, r21;
  addi r3, r30, 0x26;
  li r5, 0x15;
  lbz r0, 0xe(r30);
  rlwinm r0, r0, 0, 0x18, 0x1c;
  stb r0, 0xe(r30);
  bl strncpy;
lbl_8013f418:
  lbz r4, 0xe(r30);
  ori r0, r23, 0x80;
  lis r3, 0x8033;
  or r0, r4, r0;
  stb r0, 0xe(r30);
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013f464;
  lis r3, 0xd;
  mr r6, r22;
  mr r7, r20;
  mr r8, r24;
  mr r9, r25;
  mr r10, r26;
  addi r3, r3, 2;
  addi r4, r31, 0xe0;
  clrlwi r5, r29, 0x10;
  bl LogMsg_6;
lbl_8013f464:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013f4c0;
  lis r3, 0xd;
  lbz r5, 0xe(r30);
  mr r6, r21;
  addi r4, r31, 0x128;
  addi r3, r3, 2;
  li r7, 0x15;
  bl LogMsg_3;
  b lbl_8013f4c0;
lbl_8013f498:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013f4c0;
  lis r3, 0xd;
  addi r4, r31, 0x170;
  addi r3, r3, 1;
  li r5, 0x18;
  bl LogMsg_1;
lbl_8013f4c0:
  addi r11, r1, 0x40;
  mr r3, r27;
  bl _restgpr_20;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: BTM_PINCodeReply
// PAL: 0x8013f4dc..0x8013f5a0
MARK_BINARY_BLOB(BTM_PINCodeReply, 0x8013f4dc, 0x8013f5a0);
asm UNKNOWN_FUNCTION(BTM_PINCodeReply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r30, 0x8033;
  mr r25, r3;
  addi r30, r30, 0x6278;
  mr r26, r4;
  lwz r0, 0x194c(r30);
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  cmpwi r0, 0;
  beq lbl_8013f588;
  addi r3, r30, 0x193c;
  bl btu_stop_timer;
  li r31, 0;
  addi r3, r30, 0x1954;
  stw r31, 0x194c(r30);
  li r4, 0xff;
  li r5, 6;
  bl memset;
  cmpwi r26, 0;
  beq lbl_8013f554;
  li r0, 0xe;
  mr r3, r25;
  stb r0, 0x27bf(r30);
  bl btsnd_hcic_pin_code_neg_reply;
  b lbl_8013f588;
lbl_8013f554:
  stb r31, 0x27bf(r30);
  mr r3, r25;
  mr r4, r27;
  mr r5, r28;
  bl btsnd_hcic_pin_code_req_reply;
  mr r3, r25;
  bl btm_find_dev;
  cmpwi r3, 0;
  beq lbl_8013f588;
  lwz r0, 0(r29);
  stw r0, 0x10(r3);
  lwz r0, 4(r29);
  stw r0, 0x14(r3);
lbl_8013f588:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: BTM_DeviceAuthorized
// PAL: 0x8013f5a0..0x8013f77c
MARK_BINARY_BLOB(BTM_DeviceAuthorized, 0x8013f5a0, 0x8013f77c);
asm UNKNOWN_FUNCTION(BTM_DeviceAuthorized) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r4;
  bl btm_find_dev;
  cmpwi cr1, r3, 0;
  mr r31, r3;
  bne cr1, lbl_8013f61c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013f75c;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r30);
  addi r3, r3, 1;
  lbz r6, 1(r30);
  addi r4, r4, 0x4290;
  lbz r7, 2(r30);
  lbz r8, 3(r30);
  lbz r9, 4(r30);
  lbz r10, 5(r30);
  bl LogMsg_6;
  b lbl_8013f75c;
lbl_8013f61c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013f658;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r4, 0x42f0;
  beq cr1, lbl_8013f650;
  lbz r6, 0x7f(r31);
  b lbl_8013f654;
lbl_8013f650:
  li r6, 0;
lbl_8013f654:
  bl LogMsg_2;
lbl_8013f658:
  cmpwi r28, 0;
  bne lbl_8013f67c;
  lbz r0, 0x76(r31);
  ori r0, r0, 1;
  stb r0, 0x76(r31);
  lwz r0, 0(r29);
  stw r0, 0x10(r31);
  lwz r0, 4(r29);
  stw r0, 0x14(r31);
lbl_8013f67c:
  lbz r0, 0x7f(r31);
  cmplwi r0, 4;
  bne lbl_8013f75c;
  li r29, 0;
  cmpwi r28, 0;
  stb r29, 0x7f(r31);
  beq lbl_8013f6f0;
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_8013f75c;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_8013f6cc;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_8013f6cc;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_8013f6cc;
  stw r29, 4(r3);
lbl_8013f6cc:
  lwz r12, 4(r31);
  mr r3, r30;
  mr r5, r28;
  lwz r4, 8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
  b lbl_8013f75c;
lbl_8013f6f0:
  mr r3, r31;
  bl btm_sec_execute_procedure;
  clrlwi r0, r3, 0x18;
  mr r4, r3;
  cmplwi r0, 1;
  beq lbl_8013f75c;
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_8013f75c;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_8013f73c;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_8013f73c;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_8013f73c;
  stw r29, 4(r3);
lbl_8013f73c:
  lwz r12, 4(r31);
  clrlwi r5, r4, 0x18;
  mr r3, r30;
  lwz r4, 8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
lbl_8013f75c:
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

// Symbol: BTM_SecBond
// PAL: 0x8013f77c..0x8013fb48
MARK_BINARY_BLOB(BTM_SecBond, 0x8013f77c, 0x8013fb48);
asm UNKNOWN_FUNCTION(BTM_SecBond) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r7, 0x8033;
  lis r31, 0x8028;
  addi r7, r7, 0x6278;
  mr r28, r3;
  lbz r0, 0x27c0(r7);
  mr r29, r4;
  mr r26, r5;
  mr r27, r6;
  cmplwi r0, 3;
  addi r31, r31, 0x40f0;
  blt lbl_8013f7e4;
  lis r3, 0xd;
  lbz r5, 0(r28);
  lbz r6, 1(r28);
  addi r3, r3, 2;
  lbz r7, 2(r28);
  addi r4, r31, 0x230;
  lbz r8, 3(r28);
  lbz r9, 4(r28);
  lbz r10, 5(r28);
  bl LogMsg_6;
lbl_8013f7e4:
  cmplwi r29, 0x10;
  ble lbl_8013f818;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_8013f810;
  mr r5, r29;
  addi r4, r31, 0x260;
  lis r3, 0xd;
  bl LogMsg_1;
lbl_8013f810:
  li r3, 5;
  b lbl_8013fb30;
lbl_8013f818:
  mr r3, r28;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8013f868;
  mr r3, r28;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8013f868;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_8013f860;
  addi r4, r31, 0x280;
  lis r3, 0xd;
  bl LogMsg_0;
lbl_8013f860:
  li r3, 3;
  b lbl_8013fb30;
lbl_8013f868:
  lhz r0, 0x18(r30);
  cmplwi r0, 0xffff;
  beq lbl_8013f8ac;
  lbz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013f8ac;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013f8a4;
  lis r3, 0xd;
  addi r4, r31, 0x2a0;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8013f8a4:
  li r3, 0;
  b lbl_8013fb30;
lbl_8013f8ac:
  mr r3, r28;
  li r4, 0;
  bl BTM_DeleteStoredLinkKey;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013f8c8;
  li r3, 3;
  b lbl_8013fb30;
lbl_8013f8c8:
  li r0, 0x50;
  lis r3, 0x8033;
  stb r0, 0x81(r30);
  li r0, 1;
  cmpwi r29, 0;
  addi r3, r3, 0x6278;
  stb r0, 0x80(r30);
  lwz r0, 0(r27);
  stw r0, 0x10(r30);
  lwz r0, 4(r27);
  stw r0, 0x14(r30);
  stb r29, 0x197f(r3);
  beq lbl_8013f90c;
  mr r4, r26;
  mr r5, r29;
  addi r3, r3, 0x1980;
  bl memcpy;
lbl_8013f90c:
  lbz r3, 0x76(r30);
  li r0, -23;
  and r0, r3, r0;
  stb r0, 0x76(r30);
  lbz r0, 0x23(r30);
  clrlwi r0, r0, 0x1b;
  cmpwi r0, 5;
  bne lbl_8013f95c;
  lbz r0, 0x24(r30);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_8013f95c;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x20(r4);
  cmplwi r0, 1;
  beq lbl_8013f95c;
  li r0, 1;
  li r3, 1;
  stb r0, 0x197c(r4);
  bl btsnd_hcic_write_pin_type;
lbl_8013f95c:
  lis r29, 0x8033;
  li r27, 0;
  addi r29, r29, 0x6278;
  stb r27, 0x197e(r29);
  lhz r0, 0x18(r30);
  cmplwi r0, 0xffff;
  beq lbl_8013f9b0;
  lbz r3, 0x76(r30);
  li r0, 1;
  rlwinm r3, r3, 0, 0x1c, 0x1a;
  stb r3, 0x76(r30);
  stb r0, 0x7f(r30);
  lhz r3, 0x18(r30);
  bl btsnd_hcic_auth_request;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013f9a4;
  li r3, 3;
  b lbl_8013fb30;
lbl_8013f9a4:
  stb r27, 0x197d(r29);
  li r3, 1;
  b lbl_8013fb30;
lbl_8013f9b0:
  lbz r0, 0x1978(r29);
  cmplwi r0, 3;
  beq lbl_8013fa20;
  lbz r0, 0x27c0(r29);
  cmplwi r0, 5;
  blt lbl_8013f9d8;
  lis r3, 0xd;
  addi r4, r31, 0x2c0;
  addi r3, r3, 4;
  bl LogMsg_0;
lbl_8013f9d8:
  li r3, 1;
  bl btsnd_hcic_write_auth_enable;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013fa10;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_8013fa08;
  addi r4, r31, 0x2e4;
  lis r3, 0xd;
  bl LogMsg_0;
lbl_8013fa08:
  li r3, 3;
  b lbl_8013fb30;
lbl_8013fa10:
  lis r3, 0x8033;
  li r0, 1;
  addi r3, r3, 0x6278;
  stb r0, 0x197b(r3);
lbl_8013fa20:
  lis r3, 0x8033;
  li r0, 1;
  addi r3, r3, 0x6278;
  stb r0, 0x197d(r3);
  bl BTM_ReadLocalFeatures;
  lbz r4, 0(r3);
  li r0, 0;
  mr r3, r28;
  stb r0, 0x85(r30);
  rlwinm r27, r4, 0x1b, 0x1f, 0x1f;
  bl BTM_InqDbRead;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_8013fa7c;
  lhz r0, 0(r4);
  mr r3, r28;
  lbz r5, 0xb(r4);
  mr r8, r27;
  lbz r6, 0xd(r4);
  ori r7, r0, 0x8000;
  li r4, 0x18;
  bl btsnd_hcic_create_conn;
  b lbl_8013fa98;
lbl_8013fa7c:
  lhz r7, 0x1a(r30);
  mr r3, r28;
  mr r8, r27;
  li r4, 0x18;
  li r5, 1;
  li r6, 0;
  bl btsnd_hcic_create_conn;
lbl_8013fa98:
  clrlwi. r0, r3, 0x18;
  beq lbl_8013faa8;
  li r3, 1;
  b lbl_8013fb30;
lbl_8013faa8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_8013fac8;
  addi r4, r31, 0x2e4;
  lis r3, 0xd;
  bl LogMsg_0;
lbl_8013fac8:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197b(r4);
  cmpwi r0, 0;
  beq lbl_8013fb2c;
  lbz r0, 0x27c0(r4);
  li r3, 0;
  stb r3, 0x197b(r4);
  cmplwi r0, 5;
  blt lbl_8013fb10;
  lbz r5, 0x1978(r4);
  lis r3, 0xd;
  addi r3, r3, 4;
  addi r4, r31, 0x2fc;
  addi r0, r5, -3;
  cntlzw r0, r0;
  srwi r5, r0, 5;
  bl LogMsg_1;
lbl_8013fb10:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x1978(r3);
  addi r0, r3, -3;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_write_auth_enable;
lbl_8013fb2c:
  li r3, 3;
lbl_8013fb30:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_l2cap_access_req
// PAL: 0x8013fb48..0x8013ffac
MARK_BINARY_BLOB(btm_sec_l2cap_access_req, 0x8013fb48, 0x8013ffac);
asm UNKNOWN_FUNCTION(btm_sec_l2cap_access_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r31, 0x8028;
  mr r24, r3;
  mr r25, r4;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  addi r31, r31, 0x40f0;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8013fbec;
  mr r3, r24;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8013fbec;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013fbc4;
  lis r3, 0xd;
  mr r5, r25;
  addi r3, r3, 1;
  addi r4, r31, 0x410;
  bl LogMsg_1;
lbl_8013fbc4:
  cmpwi r28, 0;
  beq lbl_8013fbe4;
  mr r12, r28;
  mr r3, r24;
  li r4, 0;
  li r5, 3;
  mtctr r12;
  bctrl;
lbl_8013fbe4:
  li r3, 3;
  b lbl_8013ff94;
lbl_8013fbec:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  sth r26, 0x18(r30);
  addi r4, r3, 0x1990;
  li r3, 0;
  mtctr r0;
lbl_8013fc08:
  lbz r0, 0xe(r4);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fc24;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fc24;
  b lbl_8013fcd4;
lbl_8013fc24:
  lbz r0, 0x4a(r4);
  addi r4, r4, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fc44;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fc44;
  b lbl_8013fcd4;
lbl_8013fc44:
  lbz r0, 0x4a(r4);
  addi r4, r4, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fc64;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fc64;
  b lbl_8013fcd4;
lbl_8013fc64:
  lbz r0, 0x4a(r4);
  addi r4, r4, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fc84;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fc84;
  b lbl_8013fcd4;
lbl_8013fc84:
  lbz r0, 0x4a(r4);
  addi r4, r4, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fca4;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fca4;
  b lbl_8013fcd4;
lbl_8013fca4:
  lbz r0, 0x4a(r4);
  addi r4, r4, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fcc4;
  lhz r0, 0xc(r4);
  cmplw r0, r25;
  bne lbl_8013fcc4;
  b lbl_8013fcd4;
lbl_8013fcc4:
  addi r3, r3, 5;
  addi r4, r4, 0x3c;
  bdnz lbl_8013fc08;
  li r4, 0;
lbl_8013fcd4:
  cmpwi r4, 0;
  bne lbl_8013fd2c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_8013fd04;
  lis r3, 0xd;
  mr r5, r25;
  addi r3, r3, 1;
  addi r4, r31, 0x448;
  bl LogMsg_1;
lbl_8013fd04:
  cmpwi r28, 0;
  beq lbl_8013fd24;
  mr r12, r28;
  mr r3, r24;
  li r4, 0;
  li r5, 4;
  mtctr r12;
  bctrl;
lbl_8013fd24:
  li r3, 4;
  b lbl_8013ff94;
lbl_8013fd2c:
  cmpwi r27, 0;
  beq lbl_8013fd44;
  beq lbl_8013fd48;
  lwz r0, 0(r30);
  cmpwi r0, 0;
  bne lbl_8013fd48;
lbl_8013fd44:
  stw r4, 0(r30);
lbl_8013fd48:
  lis r3, 0x8033;
  li r0, 6;
  addi r3, r3, 0x6278;
  lbz r29, 0xe(r4);
  addi r7, r3, 0x1990;
  li r6, 0;
  li r5, 0;
  mtctr r0;
lbl_8013fd68:
  lbz r0, 0xe(r7);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fda0;
  lhz r3, 0xc(r7);
  lhz r0, 0xc(r4);
  cmplw r3, r0;
  bne lbl_8013fda0;
  cmpwi r6, 0;
  bne lbl_8013fe64;
  cmplw r4, r7;
  bne lbl_8013fda0;
  li r6, 1;
  b lbl_8013fda0;
  b lbl_8013fe64;
lbl_8013fda0:
  lbz r0, 0x4a(r7);
  addi r7, r7, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fddc;
  lhz r3, 0xc(r7);
  lhz r0, 0xc(r4);
  cmplw r3, r0;
  bne lbl_8013fddc;
  cmpwi r6, 0;
  bne lbl_8013fe64;
  cmplw r4, r7;
  bne lbl_8013fddc;
  li r6, 1;
  b lbl_8013fddc;
  b lbl_8013fe64;
lbl_8013fddc:
  lbz r0, 0x4a(r7);
  addi r7, r7, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fe18;
  lhz r3, 0xc(r7);
  lhz r0, 0xc(r4);
  cmplw r3, r0;
  bne lbl_8013fe18;
  cmpwi r6, 0;
  bne lbl_8013fe64;
  cmplw r4, r7;
  bne lbl_8013fe18;
  li r6, 1;
  b lbl_8013fe18;
  b lbl_8013fe64;
lbl_8013fe18:
  lbz r0, 0x4a(r7);
  addi r7, r7, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013fe54;
  lhz r3, 0xc(r7);
  lhz r0, 0xc(r4);
  cmplw r3, r0;
  bne lbl_8013fe54;
  cmpwi r6, 0;
  bne lbl_8013fe64;
  cmplw r4, r7;
  bne lbl_8013fe54;
  li r6, 1;
  b lbl_8013fe54;
  b lbl_8013fe64;
lbl_8013fe54:
  addi r5, r5, 3;
  addi r7, r7, 0x3c;
  bdnz lbl_8013fd68;
  li r7, 0;
lbl_8013fe64:
  cmpwi r7, 0;
  beq lbl_8013febc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013fe94;
  lis r3, 0xd;
  mr r5, r25;
  addi r3, r3, 3;
  addi r4, r31, 0x48c;
  bl LogMsg_1;
lbl_8013fe94:
  cmpwi r28, 0;
  beq lbl_8013feb4;
  mr r12, r28;
  mr r3, r24;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
lbl_8013feb4:
  li r3, 0;
  b lbl_8013ff94;
lbl_8013febc:
  stw r28, 4(r30);
  li r0, 0;
  lis r3, 0x8033;
  stw r0, 8(r30);
  addi r3, r3, 0x6278;
  stb r29, 0x81(r30);
  stb r27, 0x80(r30);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013ff08;
  lis r3, 0xd;
  lbz r7, 0x7f(r30);
  lbz r8, 0x76(r30);
  mr r5, r25;
  mr r6, r26;
  mr r9, r29;
  addi r3, r3, 3;
  addi r4, r31, 0x4d0;
  bl LogMsg_5;
lbl_8013ff08:
  cmpwi r27, 0;
  bne lbl_8013ff54;
  clrlwi. r0, r29, 0x1f;
  beq lbl_8013ff54;
  lbz r0, 0x76(r30);
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0x76(r30);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013ff54;
  lis r3, 0xd;
  lwz r5, 0x14(r30);
  lwz r6, 0x10(r30);
  addi r3, r3, 3;
  lbz r7, 0x76(r30);
  addi r4, r31, 0x528;
  bl LogMsg_3;
lbl_8013ff54:
  mr r3, r30;
  bl btm_sec_execute_procedure;
  clrlwi r5, r3, 0x18;
  mr r25, r3;
  cmplwi r5, 1;
  beq lbl_8013ff90;
  cmpwi r28, 0;
  beq lbl_8013ff90;
  mr r12, r28;
  mr r3, r24;
  lwz r4, 8(r30);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r30);
lbl_8013ff90:
  mr r3, r25;
lbl_8013ff94:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_sec_mx_access_request
// PAL: 0x8013ffac..0x80140248
MARK_BINARY_BLOB(btm_sec_mx_access_request, 0x8013ffac, 0x80140248);
asm UNKNOWN_FUNCTION(btm_sec_mx_access_request) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r24, r3;
  mr r25, r4;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  mr r29, r8;
  mr r30, r9;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80140024;
  mr r3, r24;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80140024;
  cmpwi r29, 0;
  beq lbl_80140230;
  mr r12, r29;
  mr r3, r24;
  mr r4, r30;
  li r5, 3;
  mtctr r12;
  bctrl;
  b lbl_80140230;
lbl_80140024:
  lis r3, 0x8033;
  li r0, 8;
  addi r3, r3, 0x6278;
  li r4, 0;
  addi r5, r3, 0x1990;
  mtctr r0;
lbl_8014003c:
  lbz r0, 0xe(r5);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8014008c;
  lhz r0, 0xc(r5);
  cmplw r0, r25;
  bne lbl_8014008c;
  lwz r0, 0(r5);
  cmplw r0, r27;
  bne lbl_8014008c;
  cmpwi r26, 0;
  beq lbl_80140074;
  lwz r0, 4(r5);
  cmplw r0, r28;
  beq lbl_80140144;
lbl_80140074:
  cmpwi r26, 0;
  bne lbl_8014008c;
  lwz r0, 8(r5);
  cmplw r0, r28;
  bne lbl_8014008c;
  b lbl_80140144;
lbl_8014008c:
  lbz r0, 0x4a(r5);
  addi r5, r5, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_801400e0;
  lhz r0, 0xc(r5);
  cmplw r0, r25;
  bne lbl_801400e0;
  lwz r0, 0(r5);
  cmplw r0, r27;
  bne lbl_801400e0;
  cmpwi r26, 0;
  beq lbl_801400c8;
  lwz r0, 4(r5);
  cmplw r0, r28;
  beq lbl_80140144;
lbl_801400c8:
  cmpwi r26, 0;
  bne lbl_801400e0;
  lwz r0, 8(r5);
  cmplw r0, r28;
  bne lbl_801400e0;
  b lbl_80140144;
lbl_801400e0:
  lbz r0, 0x4a(r5);
  addi r5, r5, 0x3c;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80140134;
  lhz r0, 0xc(r5);
  cmplw r0, r25;
  bne lbl_80140134;
  lwz r0, 0(r5);
  cmplw r0, r27;
  bne lbl_80140134;
  cmpwi r26, 0;
  beq lbl_8014011c;
  lwz r0, 4(r5);
  cmplw r0, r28;
  beq lbl_80140144;
lbl_8014011c:
  cmpwi r26, 0;
  bne lbl_80140134;
  lwz r0, 8(r5);
  cmplw r0, r28;
  bne lbl_80140134;
  b lbl_80140144;
lbl_80140134:
  addi r4, r4, 2;
  addi r5, r5, 0x3c;
  bdnz lbl_8014003c;
  li r5, 0;
lbl_80140144:
  cmpwi r5, 0;
  bne lbl_801401a0;
  cmpwi r29, 0;
  beq lbl_8014016c;
  mr r12, r29;
  mr r3, r24;
  mr r4, r30;
  li r5, 4;
  mtctr r12;
  bctrl;
lbl_8014016c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 1;
  blt lbl_80140230;
  lis r4, 0x8028;
  mr r5, r25;
  mr r6, r27;
  mr r7, r28;
  addi r4, r4, 0x4648;
  lis r3, 0xd;
  bl LogMsg_3;
  b lbl_80140230;
lbl_801401a0:
  stw r5, 0(r31);
  mr r3, r31;
  lbz r0, 0xe(r5);
  stb r0, 0x81(r31);
  stb r26, 0x80(r31);
  stw r29, 4(r31);
  stw r30, 8(r31);
  lbz r0, 0x76(r31);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0x76(r31);
  bl btm_sec_execute_procedure;
  clrlwi r0, r3, 0x18;
  mr r5, r3;
  cmplwi r0, 1;
  beq lbl_80140230;
  cmpwi r29, 0;
  beq lbl_80140230;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80140210;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80140210;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_80140210;
  li r0, 0;
  stw r0, 4(r3);
lbl_80140210:
  mr r12, r29;
  mr r3, r24;
  mr r4, r30;
  clrlwi r5, r5, 0x18;
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
lbl_80140230:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_sec_conn_req
// PAL: 0x80140248..0x80140374
MARK_BINARY_BLOB(btm_sec_conn_req, 0x80140248, 0x80140374);
asm UNKNOWN_FUNCTION(btm_sec_conn_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x197a(r5);
  cmpwi r0, 0;
  beq lbl_801402dc;
  bl btm_find_dev;
  cmpwi r3, 0;
  beq lbl_80140294;
  lbz r0, 0x76(r3);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_801402dc;
lbl_80140294:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_801402bc;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x4688;
  bl LogMsg_0;
lbl_801402bc:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80140358;
  mr r4, r29;
  li r5, 0xf;
  bl btsnd_hcic_reject_conn;
  b lbl_80140358;
lbl_801402dc:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x1934(r3);
  cmpwi r12, 0;
  beq lbl_80140328;
  mr r3, r29;
  mr r4, r30;
  mtctr r12;
  bctrl;
  clrlwi. r0, r3, 0x18;
  bne lbl_80140328;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80140358;
  mr r4, r29;
  li r5, 0xf;
  bl btsnd_hcic_reject_conn;
  b lbl_80140358;
lbl_80140328:
  lis r31, 0x8033;
  mr r4, r29;
  addi r31, r31, 0x6278;
  li r5, 6;
  addi r3, r31, 0x27b4;
  bl memcpy;
  mr r4, r30;
  addi r3, r31, 0x27ba;
  li r5, 3;
  bl memcpy;
  mr r3, r29;
  bl l2c_link_hci_conn_req;
lbl_80140358:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_init
// PAL: 0x80140374..0x80140390
MARK_BINARY_BLOB(btm_sec_init, 0x80140374, 0x80140390);
asm UNKNOWN_FUNCTION(btm_sec_init) {
  // clang-format off
  nofralloc;
  lis r6, 0x8033;
  li r4, 0xff;
  addi r6, r6, 0x6278;
  li r5, 6;
  stb r3, 0x1978(r6);
  addi r3, r6, 0x1954;
  b memset;
  // clang-format on
}

// Symbol: btm_sec_dev_reset
// PAL: 0x80140390..0x801403d0
MARK_BINARY_BLOB(btm_sec_dev_reset, 0x80140390, 0x801403d0);
asm UNKNOWN_FUNCTION(btm_sec_dev_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x14(r1);
  addi r3, r3, 0x6278;
  lbz r0, 0x1978(r3);
  cmplwi r0, 3;
  bne lbl_801403c0;
  li r3, 1;
  bl btsnd_hcic_write_auth_enable;
  li r3, 1;
  bl btsnd_hcic_write_encr_mode;
lbl_801403c0:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_abort_access_req
// PAL: 0x801403d0..0x80140484
MARK_BINARY_BLOB(btm_sec_abort_access_req, 0x801403d0, 0x80140484);
asm UNKNOWN_FUNCTION(btm_sec_abort_access_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8014046c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x1920(r3);
  cmpwi r12, 0;
  beq lbl_80140420;
  mr r3, r30;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  mtctr r12;
  bctrl;
lbl_80140420:
  lbz r0, 0x7f(r31);
  cmplwi r0, 4;
  beq lbl_80140434;
  cmplwi r0, 1;
  bne lbl_8014046c;
lbl_80140434:
  li r3, 0;
  stb r3, 0x7f(r31);
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80140464;
  lwz r4, 0(r31);
  cmpwi r4, 0;
  beq lbl_80140464;
  lwz r0, 0(r4);
  cmplwi r0, 3;
  bne lbl_80140464;
  stw r3, 4(r4);
lbl_80140464:
  li r0, 0;
  stw r0, 4(r31);
lbl_8014046c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_rmt_name_request_complete
// PAL: 0x80140484..0x8014076c
MARK_BINARY_BLOB(btm_sec_rmt_name_request_complete, 0x80140484, 0x8014076c);
asm UNKNOWN_FUNCTION(btm_sec_rmt_name_request_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r27, r3;
  mr r28, r4;
  mr r30, r5;
  beq lbl_801404b8;
  bl btm_find_dev;
  mr r31, r3;
  b lbl_80140560;
lbl_801404b8:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  li r4, 0;
  addi r31, r3, 0x1f30;
  mtctr r0;
lbl_801404d0:
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_801404e8;
  lbz r0, 0x7f(r31);
  cmplwi r0, 3;
  beq lbl_80140554;
lbl_801404e8:
  lbz r0, 0xfe(r31);
  addi r4, r4, 1;
  addi r31, r31, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80140508;
  lbz r0, 0x7f(r31);
  cmplwi r0, 3;
  beq lbl_80140554;
lbl_80140508:
  lbz r0, 0xfe(r31);
  addi r4, r4, 1;
  addi r31, r31, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80140528;
  lbz r0, 0x7f(r31);
  cmplwi r0, 3;
  beq lbl_80140554;
lbl_80140528:
  lbz r0, 0xfe(r31);
  addi r4, r4, 1;
  addi r31, r31, 0x88;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80140548;
  lbz r0, 0x7f(r31);
  cmplwi r0, 3;
  beq lbl_80140554;
lbl_80140548:
  addi r4, r4, 1;
  addi r31, r31, 0x88;
  bdnz lbl_801404d0;
lbl_80140554:
  cmpwi r4, 0x10;
  bne lbl_80140560;
  li r31, 0;
lbl_80140560:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_801405a0;
  cmpwi r31, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x46c4;
  beq lbl_80140598;
  lbz r6, 0x7f(r31);
  b lbl_8014059c;
lbl_80140598:
  li r6, 0;
lbl_8014059c:
  bl LogMsg_2;
lbl_801405a0:
  cmpwi r31, 0;
  beq lbl_80140754;
  cmpwi r30, 0;
  bne lbl_80140608;
  mr r4, r28;
  addi r3, r31, 0x35;
  li r5, 0x40;
  bl memcpy;
  lbz r0, 0x76(r31);
  lis r29, 0x8033;
  addi r29, r29, 0x6278;
  li r28, 0;
  ori r0, r0, 8;
  stb r0, 0x76(r31);
lbl_801405d8:
  lwz r12, 0x192c(r29);
  cmpwi r12, 0;
  beq lbl_801405f8;
  mr r3, r27;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  mtctr r12;
  bctrl;
lbl_801405f8:
  addi r28, r28, 1;
  addi r29, r29, 4;
  cmpwi r28, 2;
  blt lbl_801405d8;
lbl_80140608:
  lbz r0, 0x82(r31);
  cmpwi r0, 0;
  beq lbl_801406a8;
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_8014062c;
  lbz r0, 0x85(r31);
  cmpwi r0, 0;
  beq lbl_80140754;
lbl_8014062c:
  li r0, 0;
  lis r3, 0x8033;
  stb r0, 0x82(r31);
  addi r3, r3, 0x6278;
  lwz r12, 0x1914(r3);
  cmpwi r12, 0;
  beq lbl_80140664;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  addi r6, r31, 0x25;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_80140664:
  lis r29, 0x8033;
  li r28, 0;
  addi r29, r29, 0x6278;
lbl_80140670:
  lwz r12, 0x1924(r29);
  cmpwi r12, 0;
  beq lbl_80140698;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  addi r6, r31, 0x25;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_80140698:
  addi r28, r28, 1;
  addi r29, r29, 4;
  cmpwi r28, 2;
  blt lbl_80140670;
lbl_801406a8:
  lbz r3, 0x81(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_801406dc;
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_801406dc;
  li r0, -81;
  li r4, 0x13;
  and r0, r3, r0;
  stb r0, 0x81(r31);
  lhz r3, 0x18(r31);
  bl btsnd_hcic_disconnect;
  b lbl_80140754;
lbl_801406dc:
  lbz r0, 0x7f(r31);
  cmplwi r0, 3;
  bne lbl_80140754;
  li r29, 0;
  cmpwi r30, 0;
  stb r29, 0x7f(r31);
  beq lbl_80140720;
  lwz r12, 4(r31);
  cmpwi r12, 0;
  beq lbl_80140754;
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  li r5, 0xa;
  mtctr r12;
  bctrl;
  stw r29, 4(r31);
  b lbl_80140754;
lbl_80140720:
  mr r3, r31;
  bl btm_sec_execute_procedure;
  clrlwi r5, r3, 0x18;
  cmplwi r5, 1;
  beq lbl_80140754;
  lwz r12, 4(r31);
  cmpwi r12, 0;
  beq lbl_80140754;
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  mtctr r12;
  bctrl;
  stw r29, 4(r31);
lbl_80140754:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_auth_complete
// PAL: 0x8014076c..0x80140ab0
MARK_BINARY_BLOB(btm_sec_auth_complete, 0x8014076c, 0x80140ab0);
asm UNKNOWN_FUNCTION(btm_sec_auth_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r29, r3;
  mr r30, r4;
  bl btm_find_dev_by_handle;
  lis r4, 0x8033;
  mr r31, r3;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_801407d0;
  cmpwi r31, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x46fc;
  beq lbl_801407c8;
  lbz r6, 0x7f(r31);
  b lbl_801407cc;
lbl_801407c8:
  li r6, 0;
lbl_801407cc:
  bl LogMsg_2;
lbl_801407d0:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197b(r4);
  cmpwi r0, 0;
  beq lbl_80140838;
  lbz r0, 0x27c0(r4);
  li r3, 0;
  stb r3, 0x197b(r4);
  cmplwi r0, 5;
  blt lbl_8014081c;
  lbz r3, 0x1978(r4);
  lis r4, 0x8028;
  lis r5, 0xd;
  addi r0, r3, -3;
  addi r4, r4, 0x43ec;
  cntlzw r0, r0;
  addi r3, r5, 4;
  srwi r5, r0, 5;
  bl LogMsg_1;
lbl_8014081c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x1978(r3);
  addi r0, r3, -3;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_write_auth_enable;
lbl_80140838:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197c(r4);
  cmpwi r0, 0;
  beq lbl_8014085c;
  li r0, 0;
  lbz r3, 0x20(r4);
  stb r0, 0x197c(r4);
  bl btsnd_hcic_write_pin_type;
lbl_8014085c:
  cmpwi r31, 0;
  beq lbl_801408f0;
  lbz r3, 0x81(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_801408f0;
  lis r27, 0x8033;
  addi r27, r27, 0x6278;
  lbz r0, 0x197d(r27);
  cmpwi r0, 0;
  bne lbl_801408f0;
  li r0, -81;
  and r0, r3, r0;
  stb r0, 0x81(r31);
  lbz r26, 0x197e(r27);
  cmpwi r26, 0;
  beq lbl_801408f0;
  mr r3, r29;
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  mr r28, r3;
  beq lbl_801408f0;
  lbz r0, 0x81(r3);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_801408c4;
  stb r26, 0x197e(r27);
  b lbl_801408f0;
lbl_801408c4:
  lbz r27, 0x7f(r3);
  cmplwi r27, 5;
  beq lbl_801408f0;
  li r0, 5;
  mr r4, r26;
  stb r0, 0x7f(r3);
  mr r3, r29;
  bl btsnd_hcic_disconnect;
  clrlwi. r0, r3, 0x18;
  bne lbl_801408f0;
  stb r27, 0x7f(r28);
lbl_801408f0:
  cmpwi r31, 0;
  beq lbl_80140a98;
  lbz r0, 0x7f(r31);
  cmplwi r0, 1;
  beq lbl_8014093c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x191c(r3);
  cmpwi r12, 0;
  beq lbl_80140a98;
  cmpwi r30, 0;
  beq lbl_80140a98;
  mr r6, r30;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  mtctr r12;
  bctrl;
  b lbl_80140a98;
lbl_8014093c:
  cmplwi r30, 0xc;
  bne lbl_80140958;
  lbz r0, 0x76(r31);
  rlwinm r0, r0, 0, 0x1d, 0x1e;
  cmpwi r0, 6;
  bne lbl_80140958;
  li r30, 0;
lbl_80140958:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x191c(r3);
  cmpwi r12, 0;
  beq lbl_80140984;
  mr r6, r30;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  mtctr r12;
  bctrl;
lbl_80140984:
  li r29, 0;
  stb r29, 0x7f(r31);
  lbz r3, 0x81(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_801409b4;
  li r0, -81;
  li r4, 0x13;
  and r0, r3, r0;
  stb r0, 0x81(r31);
  lhz r3, 0x18(r31);
  bl btsnd_hcic_disconnect;
  b lbl_80140a98;
lbl_801409b4:
  cmpwi r30, 0;
  beq lbl_80140a20;
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_80140a10;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_801409f0;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_801409f0;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_801409f0;
  stw r29, 4(r3);
lbl_801409f0:
  lwz r12, 4(r31);
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  li r5, 0xa;
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
lbl_80140a10:
  lhz r3, 0x18(r31);
  li r4, 5;
  bl btsnd_hcic_disconnect;
  b lbl_80140a98;
lbl_80140a20:
  lbz r0, 0x76(r31);
  mr r3, r31;
  ori r0, r0, 2;
  stb r0, 0x76(r31);
  bl btm_sec_execute_procedure;
  clrlwi r0, r3, 0x18;
  mr r4, r3;
  cmplwi r0, 1;
  beq lbl_80140a98;
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_80140a98;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80140a78;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80140a78;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_80140a78;
  stw r29, 4(r3);
lbl_80140a78:
  lwz r12, 4(r31);
  clrlwi r5, r4, 0x18;
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
lbl_80140a98:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_mkey_comp_event
// PAL: 0x80140ab0..0x80140bac
MARK_BINARY_BLOB(btm_sec_mkey_comp_event, 0x80140ab0, 0x80140bac);
asm UNKNOWN_FUNCTION(btm_sec_mkey_comp_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  bl btm_find_dev_by_handle;
  lis r4, 0x8033;
  lbz r7, unk_803886a8;
  addi r4, r4, 0x6278;
  lbz r6, unk_803886a9;
  lbz r0, 0x27c0(r4);
  mr r31, r3;
  lbz r5, unk_803886aa;
  lbz r4, unk_803886ab;
  cmplwi r0, 4;
  lbz r3, unk_803886ac;
  lbz r0, unk_803886ad;
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r4, 0xb(r1);
  stb r3, 0xc(r1);
  stb r0, 0xd(r1);
  blt lbl_80140b48;
  cmpwi r31, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r4, 0x4730;
  beq lbl_80140b40;
  lbz r6, 0x7f(r31);
  b lbl_80140b44;
lbl_80140b40:
  li r6, 0;
lbl_80140b44:
  bl LogMsg_2;
lbl_80140b48:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x27b0(r3);
  cmpwi r12, 0;
  beq lbl_80140b90;
  cmpwi r31, 0;
  bne lbl_80140b7c;
  mr r4, r29;
  mr r5, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
  b lbl_80140b90;
lbl_80140b7c:
  mr r4, r29;
  mr r5, r30;
  addi r3, r31, 0x1c;
  mtctr r12;
  bctrl;
lbl_80140b90:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_encrypt_change
// PAL: 0x80140bac..0x80140ce8
MARK_BINARY_BLOB(btm_sec_encrypt_change, 0x80140bac, 0x80140ce8);
asm UNKNOWN_FUNCTION(btm_sec_encrypt_change) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  bl btm_find_dev_by_handle;
  lis r4, 0x8033;
  mr r30, r3;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_80140c0c;
  cmpwi r30, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x4760;
  beq lbl_80140c04;
  lbz r6, 0x7f(r30);
  b lbl_80140c08;
lbl_80140c04:
  li r6, 0;
lbl_80140c08:
  bl LogMsg_2;
lbl_80140c0c:
  cmpwi r30, 0;
  beq lbl_80140cd0;
  cmplwi r31, 0x23;
  bne lbl_80140c48;
  lis r7, 0x8033;
  lis r6, 0x8014;
  addi r7, r7, 0x6278;
  li r4, 0x16;
  addi r6, r6, 0x1f98;
  stw r30, 0x1938(r7);
  addi r3, r7, 0x195c;
  li r5, 1;
  stw r6, 0x196c(r7);
  bl btu_start_timer;
  b lbl_80140cd0;
lbl_80140c48:
  cmpwi r31, 0;
  beq lbl_80140c7c;
  lwz r12, 4(r30);
  cmpwi r12, 0;
  beq lbl_80140cd0;
  addi r3, r30, 0x1c;
  lwz r4, 8(r30);
  li r5, 0xa;
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r30);
  b lbl_80140cd0;
lbl_80140c7c:
  lbz r0, 0x76(r30);
  ori r0, r0, 6;
  stb r0, 0x76(r30);
  lbz r0, 0x7f(r30);
  cmplwi r0, 2;
  bne lbl_80140cd0;
  li r31, 0;
  mr r3, r30;
  stb r31, 0x7f(r30);
  bl btm_sec_execute_procedure;
  clrlwi r5, r3, 0x18;
  cmplwi r5, 1;
  beq lbl_80140cd0;
  lwz r12, 4(r30);
  cmpwi r12, 0;
  beq lbl_80140cd0;
  addi r3, r30, 0x1c;
  lwz r4, 8(r30);
  mtctr r12;
  bctrl;
  stw r31, 4(r30);
lbl_80140cd0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_is_bonding
// PAL: 0x80140ce8..0x80140d28
MARK_BINARY_BLOB(btm_sec_is_bonding, 0x80140ce8, 0x80140d28);
asm UNKNOWN_FUNCTION(btm_sec_is_bonding) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  beq lbl_80140d14;
  lbz r0, 0x81(r3);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80140d14;
  li r3, 1;
  b lbl_80140d18;
lbl_80140d14:
  li r3, 0;
lbl_80140d18:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_connected
// PAL: 0x80140d28..0x801411a8
MARK_BINARY_BLOB(btm_sec_connected, 0x80140d28, 0x801411a8);
asm UNKNOWN_FUNCTION(btm_sec_connected) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  bl btm_find_dev;
  lis r4, 0x8033;
  mr r31, r3;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_80140d88;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r28;
  mr r6, r29;
  mr r7, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x4794;
  bl LogMsg_3;
lbl_80140d88:
  cmpwi r31, 0;
  bne lbl_80140db4;
  cmpwi r29, 0;
  bne lbl_80141190;
  mr r3, r27;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80140dd4;
  b lbl_80141190;
  b lbl_80141190;
lbl_80140db4:
  lis r4, 0x8033;
  li r0, 1;
  addi r4, r4, 0x6278;
  lwz r3, 0x1974(r4);
  stw r3, 0xc(r31);
  addi r3, r3, 1;
  stw r3, 0x1974(r4);
  stb r0, 0x85(r31);
lbl_80140dd4:
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80140e6c;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197b(r4);
  cmpwi r0, 0;
  beq lbl_80140e48;
  lbz r0, 0x27c0(r4);
  li r3, 0;
  stb r3, 0x197b(r4);
  cmplwi r0, 5;
  blt lbl_80140e2c;
  lbz r3, 0x1978(r4);
  lis r4, 0x8028;
  lis r5, 0xd;
  addi r0, r3, -3;
  addi r4, r4, 0x43ec;
  cntlzw r0, r0;
  addi r3, r5, 4;
  srwi r5, r0, 5;
  bl LogMsg_1;
lbl_80140e2c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x1978(r3);
  addi r0, r3, -3;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_write_auth_enable;
lbl_80140e48:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197c(r4);
  cmpwi r0, 0;
  beq lbl_80140e6c;
  li r0, 0;
  lbz r3, 0x20(r4);
  stb r0, 0x197c(r4);
  bl btsnd_hcic_write_pin_type;
lbl_80140e6c:
  cmpwi r29, 0;
  beq lbl_80140fdc;
  cmplwi r29, 5;
  beq lbl_80140ec8;
  cmplwi r29, 6;
  beq lbl_80140ec8;
  cmplwi r29, 0xe;
  beq lbl_80140ec8;
  cmplwi r29, 0x18;
  beq lbl_80140ec8;
  cmplwi r29, 0x26;
  beq lbl_80140ec8;
  cmplwi r29, 0x29;
  beq lbl_80140ec8;
  cmplwi r29, 0x25;
  beq lbl_80140ec8;
  cmplwi r29, 0x17;
  beq lbl_80140ec8;
  cmplwi r29, 0x22;
  beq lbl_80140ec8;
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80140f54;
lbl_80140ec8:
  lbz r3, 0x81(r31);
  li r0, -81;
  lis r28, 0x8033;
  and r0, r3, r0;
  stb r0, 0x81(r31);
  addi r28, r28, 0x6278;
  lbz r0, 0x76(r31);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stb r0, 0x76(r31);
  lwz r0, 0x194c(r28);
  cmpwi r0, 0;
  beq lbl_80140f0c;
  addi r3, r28, 0x193c;
  bl btu_stop_timer;
  li r0, 0;
  li r29, 0xe;
  stw r0, 0x194c(r28);
lbl_80140f0c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27bf(r3);
  cmplwi r0, 0xe;
  bne lbl_80140f24;
  li r29, 0xe;
lbl_80140f24:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x191c(r3);
  cmpwi r12, 0;
  beq lbl_80141190;
  mr r6, r29;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  mtctr r12;
  bctrl;
  b lbl_80141190;
lbl_80140f54:
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_80141190;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80140f8c;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80140f8c;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_80140f8c;
  li r0, 0;
  stw r0, 4(r3);
lbl_80140f8c:
  cmplwi r29, 8;
  beq lbl_80140fa4;
  cmplwi r29, 0x1f;
  beq lbl_80140fa4;
  cmplwi r29, 4;
  bne lbl_80140fc0;
lbl_80140fa4:
  lwz r12, 4(r31);
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  li r5, 8;
  mtctr r12;
  bctrl;
  b lbl_80141190;
lbl_80140fc0:
  lwz r12, 4(r31);
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  li r5, 0xa;
  mtctr r12;
  bctrl;
  b lbl_80141190;
lbl_80140fdc:
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_801410bc;
  lbz r0, 0x82(r31);
  cmpwi r0, 0;
  beq lbl_801410bc;
  li r0, 0;
  lis r3, 0x8033;
  stb r0, 0x82(r31);
  addi r3, r3, 0x6278;
  lwz r12, 0x1914(r3);
  cmpwi r12, 0;
  beq lbl_8014102c;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  addi r6, r31, 0x25;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_8014102c:
  lis r29, 0x8033;
  li r30, 0;
  addi r29, r29, 0x6278;
lbl_80141038:
  lwz r12, 0x1924(r29);
  cmpwi r12, 0;
  beq lbl_80141060;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  addi r6, r31, 0x25;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_80141060:
  addi r30, r30, 1;
  addi r29, r29, 4;
  cmpwi r30, 2;
  blt lbl_80141038;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x191c(r3);
  cmpwi r12, 0;
  beq lbl_8014109c;
  addi r3, r31, 0x1c;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  li r6, 0;
  mtctr r12;
  bctrl;
lbl_8014109c:
  lbz r5, 0x81(r31);
  li r0, -81;
  mr r3, r28;
  li r4, 0x13;
  and r0, r5, r0;
  stb r0, 0x81(r31);
  bl btsnd_hcic_disconnect;
  b lbl_80141190;
lbl_801410bc:
  sth r28, 0x18(r31);
  cmpwi r30, 0;
  lbz r0, 0x76(r31);
  rlwinm r0, r0, 0, 0x18, 0x1c;
  stb r0, 0x76(r31);
  beq lbl_801410e0;
  lbz r0, 0x76(r31);
  ori r0, r0, 6;
  stb r0, 0x76(r31);
lbl_801410e0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x1978(r3);
  cmplwi r0, 3;
  bne lbl_80141100;
  lbz r0, 0x76(r31);
  ori r0, r0, 2;
  stb r0, 0x76(r31);
lbl_80141100:
  li r0, 0;
  stb r0, 0x84(r31);
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_80141120;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80141190;
lbl_80141120:
  mr r3, r31;
  bl btm_sec_execute_procedure;
  clrlwi r0, r3, 0x18;
  mr r4, r3;
  cmplwi r0, 1;
  beq lbl_80141190;
  lwz r0, 4(r31);
  cmpwi r0, 0;
  beq lbl_80141190;
  lbz r0, 0x80(r31);
  cmpwi r0, 0;
  beq lbl_80141170;
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_80141170;
  lwz r0, 0(r3);
  cmplwi r0, 3;
  bne lbl_80141170;
  li r0, 0;
  stw r0, 4(r3);
lbl_80141170:
  lwz r12, 4(r31);
  clrlwi r5, r4, 0x18;
  addi r3, r31, 0x1c;
  lwz r4, 8(r31);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 4(r31);
lbl_80141190:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_disconnect
// PAL: 0x801411a8..0x80141264
MARK_BINARY_BLOB(btm_sec_disconnect, 0x801411a8, 0x80141264);
asm UNKNOWN_FUNCTION(btm_sec_disconnect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_801411e4;
  li r3, 5;
  b lbl_80141244;
lbl_801411e4:
  lbz r0, 0x81(r3);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80141204;
  lis r4, 0x8033;
  li r3, 0;
  addi r4, r4, 0x6278;
  stb r29, 0x197e(r4);
  b lbl_80141244;
lbl_80141204:
  lbz r30, 0x7f(r3);
  cmplwi r30, 5;
  bne lbl_80141218;
  li r3, 1;
  b lbl_80141244;
lbl_80141218:
  li r0, 5;
  mr r4, r29;
  stb r0, 0x7f(r3);
  mr r3, r28;
  bl btsnd_hcic_disconnect;
  clrlwi. r0, r3, 0x18;
  beq lbl_8014123c;
  li r3, 1;
  b lbl_80141244;
lbl_8014123c:
  stb r30, 0x7f(r31);
  li r3, 3;
lbl_80141244:
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

// Symbol: btm_sec_disconnected
// PAL: 0x80141264..0x801413a0
MARK_BINARY_BLOB(btm_sec_disconnected, 0x80141264, 0x801413a0);
asm UNKNOWN_FUNCTION(btm_sec_disconnected) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80141388;
  lbz r0, 0x81(r3);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_801412e8;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r12, 0x191c(r4);
  cmpwi r12, 0;
  beq lbl_801412e8;
  cmplwi r31, 0x17;
  bne lbl_801412d0;
  addi r4, r3, 0x22;
  addi r5, r3, 0x35;
  li r6, 0x17;
  mtctr r12;
  addi r3, r3, 0x1c;
  bctrl;
  b lbl_801412e8;
lbl_801412d0:
  addi r4, r3, 0x22;
  addi r5, r3, 0x35;
  li r6, 5;
  mtctr r12;
  addi r3, r3, 0x1c;
  bctrl;
lbl_801412e8:
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lwz r0, 0x194c(r31);
  cmpwi r0, 0;
  beq lbl_80141358;
  addi r3, r31, 0x1954;
  addi r4, r30, 0x1c;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80141358;
  addi r3, r31, 0x193c;
  bl btu_stop_timer;
  li r0, 0;
  addi r3, r31, 0x1954;
  stw r0, 0x194c(r31);
  li r4, 0xff;
  li r5, 6;
  bl memset;
  lwz r12, 0x191c(r31);
  cmpwi r12, 0;
  beq lbl_80141358;
  addi r3, r30, 0x1c;
  addi r4, r30, 0x22;
  addi r5, r30, 0x35;
  li r6, 0xe;
  mtctr r12;
  bctrl;
lbl_80141358:
  lis r4, 1;
  li r3, 0;
  addi r0, r4, -1;
  sth r0, 0x18(r30);
  stb r3, 0x7f(r30);
  lbz r0, 0x76(r30);
  rlwinm r0, r0, 0, 0x18, 0x1c;
  stb r0, 0x76(r30);
  lbz r0, 0x81(r30);
  rlwinm r0, r0, 0, 0x18, 0x18;
  stb r0, 0x81(r30);
  stw r3, 4(r30);
lbl_80141388:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_link_key_notification
// PAL: 0x801413a0..0x8014154c
MARK_BINARY_BLOB(btm_sec_link_key_notification, 0x801413a0, 0x8014154c);
asm UNKNOWN_FUNCTION(btm_sec_link_key_notification) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r29, r3;
  mr r30, r4;
  mr r27, r5;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_801413e4;
  mr r3, r29;
  bl btm_sec_alloc_dev;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80141534;
lbl_801413e4:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141424;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r29);
  addi r3, r3, 3;
  lbz r6, 1(r29);
  addi r4, r4, 0x47d8;
  lbz r7, 2(r29);
  lbz r8, 3(r29);
  lbz r9, 4(r29);
  lbz r10, 5(r29);
  bl LogMsg_6;
lbl_80141424:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141450;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r27;
  addi r3, r3, 3;
  addi r4, r4, 0x481c;
  bl LogMsg_1;
lbl_80141450:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x636(r3);
  cmplwi r0, 1;
  bge lbl_80141470;
  li r0, 0xff;
  stb r0, 0x83(r31);
  b lbl_80141474;
lbl_80141470:
  stb r27, 0x83(r31);
lbl_80141474:
  lbz r0, 0x76(r31);
  mr r4, r30;
  addi r3, r31, 0x25;
  li r5, 0x10;
  ori r0, r0, 0x10;
  stb r0, 0x76(r31);
  bl memcpy;
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_801414b4;
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_801414c0;
  lbz r0, 0x85(r31);
  cmpwi r0, 0;
  bne lbl_801414c0;
lbl_801414b4:
  li r0, 1;
  stb r0, 0x82(r31);
  b lbl_80141534;
lbl_801414c0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x1914(r3);
  cmpwi r12, 0;
  beq lbl_801414f0;
  mr r3, r29;
  mr r6, r30;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_801414f0:
  lis r28, 0x8033;
  li r27, 0;
  addi r28, r28, 0x6278;
lbl_801414fc:
  lwz r12, 0x1924(r28);
  cmpwi r12, 0;
  beq lbl_80141524;
  mr r3, r29;
  mr r6, r30;
  addi r4, r31, 0x22;
  addi r5, r31, 0x35;
  lbz r7, 0x83(r31);
  mtctr r12;
  bctrl;
lbl_80141524:
  addi r27, r27, 1;
  addi r28, r28, 4;
  cmpwi r27, 2;
  blt lbl_801414fc;
lbl_80141534:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_link_key_request
// PAL: 0x8014154c..0x8014167c
MARK_BINARY_BLOB(btm_sec_link_key_request, 0x8014154c, 0x8014167c);
asm UNKNOWN_FUNCTION(btm_sec_link_key_request) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  bl btm_find_dev;
  lis r4, 0x8033;
  mr r31, r3;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_801415ac;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r30);
  addi r3, r3, 3;
  lbz r6, 1(r30);
  addi r4, r4, 0x4848;
  lbz r7, 2(r30);
  lbz r8, 3(r30);
  lbz r9, 4(r30);
  lbz r10, 5(r30);
  bl LogMsg_6;
lbl_801415ac:
  cmpwi r31, 0;
  beq lbl_801415d0;
  lbz r0, 0x76(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_801415d0;
  mr r3, r30;
  addi r4, r31, 0x25;
  bl btsnd_hcic_link_key_req_reply;
  b lbl_80141664;
lbl_801415d0:
  cmpwi r31, 0;
  bne lbl_801415e4;
  mr r3, r30;
  bl btm_sec_alloc_dev;
  mr r31, r3;
lbl_801415e4:
  lbz r0, 0x81(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  bne lbl_8014165c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x1918(r3);
  cmpwi r12, 0;
  beq lbl_8014165c;
  cmpwi r31, 0;
  beq lbl_80141634;
  mr r3, r30;
  addi r4, r31, 0x25;
  mtctr r12;
  bctrl;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014165c;
  mr r3, r30;
  addi r4, r31, 0x25;
  bl btsnd_hcic_link_key_req_reply;
  b lbl_80141664;
lbl_80141634:
  mr r3, r30;
  addi r4, r1, 8;
  mtctr r12;
  bctrl;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014165c;
  mr r3, r30;
  addi r4, r1, 8;
  bl btsnd_hcic_link_key_req_reply;
  b lbl_80141664;
lbl_8014165c:
  mr r3, r30;
  bl btsnd_hcic_link_key_neg_reply;
lbl_80141664:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_pin_code_request_timeout
// PAL: 0x8014167c..0x801416f0
MARK_BINARY_BLOB(btm_sec_pin_code_request_timeout, 0x8014167c, 0x801416f0);
asm UNKNOWN_FUNCTION(btm_sec_pin_code_request_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 4;
  blt lbl_801416b4;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x4888;
  bl LogMsg_0;
lbl_801416b4:
  li r0, 0;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  stw r0, 0x194c(r31);
  addi r3, r3, 0x1954;
  li r4, 0xff;
  li r5, 6;
  bl memset;
  addi r3, r31, 0x27b4;
  bl btsnd_hcic_pin_code_neg_reply;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_pin_code_request
// PAL: 0x801416f0..0x80141a4c
MARK_BINARY_BLOB(btm_sec_pin_code_request, 0x801416f0, 0x80141a4c);
asm UNKNOWN_FUNCTION(btm_sec_pin_code_request) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r29, 0x8033;
  lis r31, 0x8028;
  addi r29, r29, 0x6278;
  mr r27, r3;
  lbz r0, 0x27c0(r29);
  addi r31, r31, 0x40f0;
  li r28, 0;
  li r30, 0;
  cmplwi r0, 4;
  blt lbl_80141754;
  lis r3, 0xd;
  lbz r5, 0(r27);
  lbz r6, 1(r27);
  addi r3, r3, 3;
  lbz r7, 2(r27);
  addi r4, r31, 0x7bc;
  lbz r8, 3(r27);
  lbz r9, 4(r27);
  lbz r10, 5(r27);
  bl LogMsg_6;
lbl_80141754:
  lbz r0, 0x1979(r29);
  cmpwi r0, 0;
  bne lbl_80141840;
  lbz r0, 0x20(r29);
  cmplwi r0, 1;
  bne lbl_80141840;
  mr r3, r27;
  bl btm_find_dev;
  cmpwi r3, 0;
  bne lbl_80141818;
  lis r3, 0x8033;
  li r0, 2;
  addi r3, r3, 0x6278;
  addi r3, r3, 0x1f30;
  mtctr r0;
lbl_80141790:
  lbz r0, 0x76(r3);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0xfe(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x186(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x20e(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x296(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x31e(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x3a6(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  lbz r0, 0x42e(r3);
  addi r30, r30, 1;
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_80141818;
  addi r30, r30, 1;
  addi r3, r3, 0x440;
  bdnz lbl_80141790;
lbl_80141818:
  cmpwi r30, 0x10;
  blt lbl_8014182c;
  mr r3, r27;
  bl btsnd_hcic_pin_code_neg_reply;
  b lbl_80141a34;
lbl_8014182c:
  lbz r4, 0x21(r29);
  mr r3, r27;
  addi r5, r29, 0x22;
  bl btsnd_hcic_pin_code_req_reply;
  b lbl_80141a34;
lbl_80141840:
  mr r3, r27;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80141860;
  mr r3, r27;
  bl btm_sec_alloc_dev;
  mr r30, r3;
lbl_80141860:
  lis r3, 0x8033;
  mr r4, r27;
  addi r3, r3, 0x6278;
  li r5, 6;
  addi r3, r3, 0x1954;
  bl memcpy;
  cmpwi r30, 0;
  beq lbl_801419f0;
  mr r3, r27;
  addi r4, r29, 0x27b4;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_801418a8;
  addi r3, r30, 0x22;
  addi r4, r29, 0x27ba;
  li r5, 3;
  bl memcpy;
lbl_801418a8:
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80141950;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_801418d8;
  lis r3, 0xd;
  addi r4, r31, 0x7fc;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_801418d8:
  lbz r4, 0x197f(r29);
  mr r3, r27;
  addi r5, r29, 0x1980;
  bl btsnd_hcic_pin_code_req_reply;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x197b(r4);
  cmpwi r0, 0;
  beq lbl_801419f4;
  lbz r0, 0x27c0(r4);
  li r3, 0;
  stb r3, 0x197b(r4);
  cmplwi r0, 5;
  blt lbl_80141930;
  lbz r5, 0x1978(r4);
  lis r3, 0xd;
  addi r3, r3, 4;
  addi r4, r31, 0x82c;
  addi r0, r5, -3;
  cntlzw r0, r0;
  srwi r5, r0, 5;
  bl LogMsg_1;
lbl_80141930:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x1978(r3);
  addi r0, r3, -3;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_write_auth_enable;
  b lbl_801419f4;
lbl_80141950:
  lbz r0, 0x1979(r29);
  cmpwi r0, 0;
  bne lbl_80141990;
  lwz r0, 0x1910(r29);
  cmpwi r0, 0;
  beq lbl_80141990;
  lbz r0, 0x80(r30);
  cmpwi r0, 0;
  bne lbl_80141998;
  lbz r0, 0x23(r30);
  clrlwi r0, r0, 0x1b;
  cmpwi r0, 5;
  bne lbl_80141998;
  lbz r0, 0x24(r30);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_80141998;
lbl_80141990:
  li r28, 1;
  b lbl_801419f4;
lbl_80141998:
  mr r4, r27;
  addi r3, r29, 0x27b4;
  li r5, 6;
  bl memcpy;
  addi r3, r29, 0x27ba;
  addi r4, r30, 0x22;
  li r5, 3;
  bl memcpy;
  lis r5, 0x8014;
  addi r3, r29, 0x193c;
  addi r5, r5, 0x167c;
  li r4, 0x16;
  stw r5, 0x194c(r29);
  li r5, 0x3c;
  bl btu_start_timer;
  lwz r12, 0x1910(r29);
  mr r3, r27;
  addi r4, r30, 0x22;
  addi r5, r30, 0x35;
  mtctr r12;
  bctrl;
  b lbl_801419f4;
lbl_801419f0:
  li r28, 1;
lbl_801419f4:
  cmpwi r28, 0;
  beq lbl_80141a34;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 2;
  blt lbl_80141a2c;
  lis r3, 0xd;
  lbz r5, 0x1979(r29);
  lwz r6, 0x1910(r29);
  mr r7, r30;
  addi r3, r3, 1;
  addi r4, r31, 0x85c;
  bl LogMsg_3;
lbl_80141a2c:
  mr r3, r27;
  bl btsnd_hcic_pin_code_neg_reply;
lbl_80141a34:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_update_clock_offset
// PAL: 0x80141a4c..0x80141a9c
MARK_BINARY_BLOB(btm_sec_update_clock_offset, 0x80141a4c, 0x80141a9c);
asm UNKNOWN_FUNCTION(btm_sec_update_clock_offset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  beq lbl_80141a88;
  ori r31, r31, 0x8000;
  sth r31, 0x1a(r3);
  addi r3, r3, 0x1c;
  bl BTM_InqDbRead;
  cmpwi r3, 0;
  beq lbl_80141a88;
  sth r31, 0(r3);
lbl_80141a88:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_execute_procedure
// PAL: 0x80141a9c..0x80141e7c
MARK_BINARY_BLOB(btm_sec_execute_procedure, 0x80141a9c, 0x80141e7c);
asm UNKNOWN_FUNCTION(btm_sec_execute_procedure) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x40f0;
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_80141af0;
  lis r3, 0xd;
  lbz r5, 0x81(r30);
  lbz r6, 0x76(r30);
  addi r3, r3, 3;
  lbz r7, 0x7f(r30);
  addi r4, r31, 0x8ac;
  bl LogMsg_3;
lbl_80141af0:
  lbz r0, 0x7f(r30);
  cmpwi r0, 0;
  beq lbl_80141b04;
  li r3, 1;
  b lbl_80141e60;
lbl_80141b04:
  lhz r0, 0x18(r30);
  cmplwi cr1, r0, 0xffff;
  bne cr1, lbl_80141b6c;
  addi r3, r30, 0x1c;
  bl l2cu_allocate_lcb;
  cmpwi r3, 0;
  bne lbl_80141b48;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_80141b40;
  lis r3, 8;
  addi r4, r31, 0x8ec;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80141b40:
  li r3, 3;
  b lbl_80141e60;
lbl_80141b48:
  bl l2cu_create_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_80141b5c;
  li r3, 3;
  b lbl_80141e60;
lbl_80141b5c:
  li r0, 1;
  li r3, 1;
  stb r0, 0x80(r30);
  b lbl_80141e60;
lbl_80141b6c:
  lbz r0, 0x76(r30);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80141bfc;
  beq cr1, lbl_80141bfc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141ba0;
  lis r3, 0xd;
  addi r4, r31, 0x910;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80141ba0:
  lbz r29, 0x7f(r30);
  li r0, 3;
  addi r3, r30, 0x1c;
  li r4, 0;
  stb r0, 0x7f(r30);
  li r5, 2;
  li r6, 0x1e;
  li r7, 0;
  bl btm_initiate_rem_name;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80141bdc;
  stb r29, 0x7f(r30);
  li r0, 0;
  b lbl_80141be0;
lbl_80141bdc:
  li r0, 1;
lbl_80141be0:
  cmpwi r0, 0;
  beq lbl_80141bf0;
  li r3, 1;
  b lbl_80141e60;
lbl_80141bf0:
  lbz r0, 0x76(r30);
  ori r0, r0, 8;
  stb r0, 0x76(r30);
lbl_80141bfc:
  lbz r4, 0x76(r30);
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  bne lbl_80141c8c;
  lbz r3, 0x80(r30);
  cmpwi r3, 0;
  beq lbl_80141c20;
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_80141c34;
lbl_80141c20:
  cmpwi r3, 0;
  bne lbl_80141c8c;
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80141c8c;
lbl_80141c34:
  lhz r0, 0x18(r30);
  cmplwi r0, 0xffff;
  beq lbl_80141c8c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141c64;
  lis r3, 0xd;
  addi r4, r31, 0x934;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80141c64:
  li r0, 1;
  lhz r3, 0x18(r30);
  stb r0, 0x7f(r30);
  bl btsnd_hcic_auth_request;
  clrlwi. r0, r3, 0x18;
  bne lbl_80141c84;
  li r3, 3;
  b lbl_80141e60;
lbl_80141c84:
  li r3, 1;
  b lbl_80141e60;
lbl_80141c8c:
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  bne lbl_80141d30;
  lbz r3, 0x80(r30);
  cmpwi r3, 0;
  beq lbl_80141cac;
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  bne lbl_80141cc0;
lbl_80141cac:
  cmpwi r3, 0;
  bne lbl_80141d30;
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_80141d30;
lbl_80141cc0:
  lhz r0, 0x18(r30);
  cmplwi r0, 0xffff;
  beq lbl_80141d30;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141cf0;
  lis r3, 0xd;
  addi r4, r31, 0x95c;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80141cf0:
  lhz r3, 0x18(r30);
  li r4, 1;
  bl btsnd_hcic_set_conn_encrypt;
  clrlwi. r0, r3, 0x18;
  bne lbl_80141d0c;
  li r3, 0;
  b lbl_80141d18;
lbl_80141d0c:
  li r0, 2;
  li r3, 1;
  stb r0, 0x7f(r30);
lbl_80141d18:
  cmpwi r3, 0;
  bne lbl_80141d28;
  li r3, 3;
  b lbl_80141e60;
lbl_80141d28:
  li r3, 1;
  b lbl_80141e60;
lbl_80141d30:
  clrlwi. r0, r4, 0x1f;
  bne lbl_80141e00;
  lbz r3, 0x80(r30);
  cmpwi r3, 0;
  beq lbl_80141d50;
  lbz r0, 0x81(r30);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80141d64;
lbl_80141d50:
  cmpwi r3, 0;
  bne lbl_80141e00;
  lbz r0, 0x81(r30);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80141e00;
lbl_80141d64:
  lwz r3, 0x10(r30);
  addis r0, r3, 1;
  cmplwi r0, 0xffff;
  beq lbl_80141d7c;
  li r0, 0;
  b lbl_80141d98;
lbl_80141d7c:
  lwz r3, 0x14(r30);
  addis r0, r3, 1;
  cmplwi r0, 0xffff;
  beq lbl_80141d94;
  li r0, 0;
  b lbl_80141d98;
lbl_80141d94:
  li r0, 1;
lbl_80141d98:
  cmpwi r0, 0;
  bne lbl_80141e00;
  lwz r3, 0(r30);
  lbz r3, 0xf(r3);
  cmplwi r3, 0x2e;
  bge lbl_80141e00;
  rlwinm r0, r3, 0x1d, 0x1b, 0x1d;
  clrlwi r4, r3, 0x1b;
  add r3, r30, r0;
  li r5, 1;
  lwz r0, 0x10(r3);
  slw r3, r5, r4;
  and. r0, r3, r0;
  bne lbl_80141e00;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141df4;
  lis r3, 0xd;
  addi r4, r31, 0x980;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80141df4:
  mr r3, r30;
  bl btm_sec_start_authorization;
  b lbl_80141e60;
lbl_80141e00:
  lbz r0, 0x81(r30);
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  rlwinm r0, r0, 0, 0x18, 0x19;
  stb r0, 0x81(r30);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141e38;
  lis r3, 0xd;
  lwz r5, 0x14(r30);
  lwz r6, 0x10(r30);
  addi r3, r3, 3;
  addi r4, r31, 0x9a8;
  bl LogMsg_2;
lbl_80141e38:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141e5c;
  lis r3, 0xd;
  addi r4, r31, 0x9d0;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80141e5c:
  li r3, 0;
lbl_80141e60:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_sec_start_authorization
// PAL: 0x80141e7c..0x80141f98
MARK_BINARY_BLOB(btm_sec_start_authorization, 0x80141e7c, 0x80141f98);
asm UNKNOWN_FUNCTION(btm_sec_start_authorization) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r6, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x76(r3);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80141eb0;
  lhz r0, 0x18(r3);
  cmplwi r0, 0xffff;
  bne lbl_80141f48;
lbl_80141eb0:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r0, 0x190c(r4);
  cmpwi r0, 0;
  bne lbl_80141ecc;
  li r3, 4;
  b lbl_80141f80;
lbl_80141ecc:
  lwz r4, 0(r3);
  cmpwi r4, 0;
  beq lbl_80141ef8;
  lbz r0, 0x80(r3);
  cmpwi r0, 0;
  beq lbl_80141eec;
  addi r6, r4, 0x10;
  b lbl_80141ef0;
lbl_80141eec:
  addi r6, r4, 0x26;
lbl_80141ef0:
  lbz r7, 0xf(r4);
  b lbl_80141efc;
lbl_80141ef8:
  li r7, 0;
lbl_80141efc:
  li r0, 4;
  lis r4, 0x8033;
  stb r0, 0x7f(r3);
  addi r4, r4, 0x6278;
  addi r5, r3, 0x35;
  lbz r8, 0x80(r3);
  lwz r12, 0x190c(r4);
  addi r4, r3, 0x22;
  mtctr r12;
  addi r3, r3, 0x1c;
  bctrl;
  clrlwi. r0, r3, 0x18;
  bne lbl_80141f80;
  lbz r4, 0x76(r30);
  li r0, 0;
  stb r0, 0x7f(r30);
  ori r0, r4, 1;
  stb r0, 0x76(r30);
  b lbl_80141f80;
lbl_80141f48:
  lbz r31, 0x7f(r3);
  li r0, 3;
  li r4, 0;
  li r5, 2;
  stb r0, 0x7f(r3);
  li r6, 0x1e;
  li r7, 0;
  addi r3, r3, 0x1c;
  bl btm_initiate_rem_name;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80141f7c;
  stb r31, 0x7f(r30);
lbl_80141f7c:
  li r3, 1;
lbl_80141f80:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_sec_collision_timeout
// PAL: 0x80141f98..0x80142078
MARK_BINARY_BLOB(btm_sec_collision_timeout, 0x80141f98, 0x80142078);
asm UNKNOWN_FUNCTION(btm_sec_collision_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x14(r1);
  addi r3, r3, 0x6278;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80141fd4;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x4ae4;
  bl LogMsg_0;
lbl_80141fd4:
  lis r31, 0x8033;
  li r30, 0;
  addi r31, r31, 0x6278;
  stw r30, 0x196c(r31);
  lwz r3, 0x1938(r31);
  bl btm_sec_execute_procedure;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80142060;
  lwz r4, 0x1938(r31);
  lwz r0, 4(r4);
  cmpwi r0, 0;
  beq lbl_80142060;
  lbz r0, 0x80(r4);
  cmpwi r0, 0;
  beq lbl_80142030;
  lwz r4, 0(r4);
  cmpwi r4, 0;
  beq lbl_80142030;
  lwz r0, 0(r4);
  cmplwi r0, 3;
  bne lbl_80142030;
  stw r30, 4(r4);
lbl_80142030:
  lis r31, 0x8033;
  clrlwi r5, r3, 0x18;
  addi r31, r31, 0x6278;
  lwz r4, 0x1938(r31);
  lwz r12, 4(r4);
  addi r3, r4, 0x1c;
  lwz r4, 8(r4);
  mtctr r12;
  bctrl;
  lwz r3, 0x1938(r31);
  li r0, 0;
  stw r0, 4(r3);
lbl_80142060:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_read_trusted_mask
// PAL: 0x80142078..0x801420ac
MARK_BINARY_BLOB(btm_read_trusted_mask, 0x80142078, 0x801420ac);
asm UNKNOWN_FUNCTION(btm_read_trusted_mask) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl btm_find_dev;
  cmpwi r3, 0;
  beq lbl_80142098;
  addi r3, r3, 0x10;
  b lbl_8014209c;
lbl_80142098:
  li r3, 0;
lbl_8014209c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
