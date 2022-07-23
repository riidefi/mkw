#include "bta_dm_pm.h"

#include <string.h>

#include "bd.h"
#include "bte_logmsg.h"
#include "bta_sys.h"
#include "gki_buffer.h"

// Extern function references.
// PAL: 0x801384c4
extern UNKNOWN_FUNCTION(BTM_SetLinkPolicy);
// PAL: 0x8013b0b4
extern UNKNOWN_FUNCTION(BTM_ReadLocalVersion);
// PAL: 0x8013d61c
extern UNKNOWN_FUNCTION(BTM_PmRegister);
// PAL: 0x8013d6d8
extern UNKNOWN_FUNCTION(BTM_SetPowerMode);
// PAL: 0x8013d8a8
extern UNKNOWN_FUNCTION(BTM_ReadPowerMode);

// Symbol: bta_dm_init_pm
// PAL: 0x80134e28..0x80134e90
MARK_BINARY_BLOB(bta_dm_init_pm, 0x80134e28, 0x80134e90);
asm UNKNOWN_FUNCTION(bta_dm_init_pm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  li r4, 0;
  stw r0, 0x14(r1);
  addi r3, r3, 0x6018;
  li r5, 0x2e;
  bl memset;
  lwz r3, -0x73d8(r13);
  lbz r0, 1(r3);
  cmpwi r0, 0;
  beq lbl_80134e80;
  lis r3, 0x8013;
  addi r3, r3, 0x4ea8;
  bl bta_sys_pm_register;
  lis r4, 0x8033;
  lis r5, 0x8013;
  addi r4, r4, 0x5f14;
  li r3, 3;
  addi r4, r4, 0x95;
  addi r5, r5, 0x55a8;
  bl BTM_PmRegister;
lbl_80134e80:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disable_pm
// PAL: 0x80134e90..0x80134ea8
MARK_BINARY_BLOB(bta_dm_disable_pm, 0x80134e90, 0x80134ea8);
asm UNKNOWN_FUNCTION(bta_dm_disable_pm) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r3, 4;
  addi r4, r4, 0x5f14;
  li r5, 0;
  addi r4, r4, 0x95;
  b BTM_PmRegister;
  // clang-format on
}

// Symbol: bta_dm_pm_cback
// PAL: 0x80134ea8..0x80135228
MARK_BINARY_BLOB(bta_dm_pm_cback, 0x80134ea8, 0x80135228);
asm UNKNOWN_FUNCTION(bta_dm_pm_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_23;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  addi r3, r1, 0xc;
  bl BTM_ReadLocalVersion;
  clrlwi. r0, r3, 0x18;
  bne lbl_80134f44;
  lhz r0, 0x12(r1);
  cmplwi r0, 0xf;
  bne lbl_80134f44;
  lbz r0, 0xc(r1);
  cmplwi r0, 3;
  bge lbl_80134f44;
  cmplwi r25, 4;
  bne lbl_80134f20;
  lis r5, 0x8025;
  mr r3, r28;
  addi r5, r5, -14600;
  addi r4, r1, 8;
  lhz r0, 4(r5);
  andi. r0, r0, 0xb;
  sth r0, 8(r1);
  bl BTM_SetLinkPolicy;
  b lbl_80134f44;
lbl_80134f20:
  cmplwi r25, 5;
  bne lbl_80134f44;
  lis r5, 0x8025;
  mr r3, r28;
  addi r5, r5, -14600;
  addi r4, r1, 8;
  lhz r0, 4(r5);
  sth r0, 8(r1);
  bl BTM_SetLinkPolicy;
lbl_80134f44:
  lwz r5, -0x73d8(r13);
  li r30, 1;
  lbz r4, 1(r5);
  b lbl_80134f88;
lbl_80134f54:
  clrlwi r3, r30, 0x18;
  rlwinm r0, r30, 2, 0x16, 0x1d;
  subf r0, r3, r0;
  add r3, r5, r0;
  lbzx r0, r5, r0;
  cmplw r26, r0;
  bne lbl_80134f84;
  lbz r0, 1(r3);
  cmplwi r0, 0xff;
  beq lbl_80134f94;
  cmplw r27, r0;
  beq lbl_80134f94;
lbl_80134f84:
  addi r30, r30, 1;
lbl_80134f88:
  clrlwi r0, r30, 0x18;
  cmplw r0, r4;
  ble lbl_80134f54;
lbl_80134f94:
  lbz r0, 1(r5);
  clrlwi r3, r30, 0x18;
  cmplw r3, r0;
  bgt lbl_80135210;
  lis r23, 0x8033;
  li r31, 0;
  addi r23, r23, 0x5f14;
lbl_80134fb0:
  rlwinm r29, r31, 5, 0x13, 0x1a;
  add r24, r23, r29;
  lbz r0, 0xb6(r24);
  cmpwi r0, 0;
  beq lbl_80134ff0;
  mr r4, r28;
  addi r3, r24, 0xb0;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_80134ff0;
  mr r3, r24;
  addi r3, r3, 0x98;
  bl bta_sys_stop_timer;
  li r0, 0;
  stb r0, 0xb6(r24);
  b lbl_80134ffc;
lbl_80134ff0:
  addi r31, r31, 1;
  cmplwi r31, 3;
  blt lbl_80134fb0;
lbl_80134ffc:
  clrlwi r4, r30, 0x18;
  rlwinm r3, r30, 2, 0x16, 0x1d;
  subf r30, r4, r3;
  lwz r0, -0x73d8(r13);
  lwz r4, -0x73d4(r13);
  rlwinm r31, r25, 3, 0x15, 0x1c;
  add r3, r0, r30;
  lbz r0, 2(r3);
  mulli r0, r0, 0x4a;
  add r0, r4, r0;
  add r3, r0, r31;
  lbz r0, 2(r3);
  cmpwi r0, 0;
  beq lbl_80135210;
  lis r23, 0x8033;
  li r29, 0;
  addi r24, r23, 0x6018;
  b lbl_80135084;
lbl_80135044:
  clrlwi r3, r29, 0x18;
  rlwinm r0, r29, 3, 0x15, 0x1c;
  add r0, r0, r3;
  add r3, r24, r0;
  lbz r0, 7(r3);
  cmplw r26, r0;
  bne lbl_80135080;
  lbz r0, 8(r3);
  cmplw r27, r0;
  bne lbl_80135080;
  mr r4, r28;
  addi r3, r3, 1;
  bl bdcmp;
  cmpwi r3, 0;
  beq lbl_80135094;
lbl_80135080:
  addi r29, r29, 1;
lbl_80135084:
  lbz r0, 0x6018(r23);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_80135044;
lbl_80135094:
  lwz r0, -0x73d8(r13);
  lwz r4, -0x73d4(r13);
  add r3, r0, r30;
  lbz r0, 2(r3);
  mulli r0, r0, 0x4a;
  add r0, r4, r0;
  add r3, r0, r31;
  lbz r0, 2(r3);
  cmplwi r0, 0x10;
  bne lbl_80135128;
  lis r27, 0x8033;
  clrlwi r3, r29, 0x18;
  lbz r0, 0x6018(r27);
  cmplw r3, r0;
  beq lbl_80135194;
  addi r26, r27, 0x6018;
  b lbl_8013510c;
lbl_801350d8:
  clrlwi r6, r29, 0x18;
  rlwinm r4, r29, 3, 0x15, 0x1c;
  addi r3, r6, 1;
  li r5, 9;
  slwi r0, r3, 3;
  add r4, r4, r6;
  add r0, r0, r3;
  add r3, r26, r4;
  add r4, r26, r0;
  addi r3, r3, 1;
  addi r4, r4, 1;
  bl memcpy;
  addi r29, r29, 1;
lbl_8013510c:
  lbz r3, 0x6018(r27);
  clrlwi r0, r29, 0x18;
  cmplw r0, r3;
  blt lbl_801350d8;
  addi r0, r3, -1;
  stb r0, 0x6018(r27);
  b lbl_80135194;
lbl_80135128:
  lis r30, 0x8033;
  clrlwi r4, r29, 0x18;
  lbz r0, 0x6018(r30);
  cmplw r4, r0;
  bne lbl_80135194;
  cmplwi r0, 5;
  bne lbl_80135164;
  lbz r0, -0x6610(r13);
  cmplwi r0, 2;
  blt lbl_80135210;
  lis r4, 0x8028;
  li r3, 0x501;
  addi r4, r4, 0x2a08;
  bl LogMsg_0;
  b lbl_80135210;
lbl_80135164:
  rlwinm r3, r29, 3, 0x15, 0x1c;
  addi r0, r30, 0x6018;
  add r3, r3, r4;
  mr r4, r28;
  add r5, r0, r3;
  stb r26, 7(r5);
  addi r3, r5, 1;
  stb r27, 8(r5);
  bl bdcpy;
  lbz r3, 0x6018(r30);
  addi r0, r3, 1;
  stb r0, 0x6018(r30);
lbl_80135194:
  lis r3, 0x8033;
  li r24, 0;
  addi r26, r3, 0x5f14;
  b lbl_801351d8;
lbl_801351a4:
  clrlwi r0, r24, 0x18;
  mr r4, r28;
  mulli r23, r0, 0xb;
  add r3, r26, r23;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801351d4;
  add r3, r26, r23;
  li r0, 0;
  stb r0, 9(r3);
  stb r0, 0xa(r3);
  b lbl_801351e8;
lbl_801351d4:
  addi r24, r24, 1;
lbl_801351d8:
  lbz r0, 0x4d(r26);
  clrlwi r3, r24, 0x18;
  cmplw r3, r0;
  blt lbl_801351a4;
lbl_801351e8:
  lis r6, 0x8033;
  clrlwi r5, r29, 0x18;
  rlwinm r0, r29, 3, 0x15, 0x1c;
  mr r3, r28;
  addi r6, r6, 0x6018;
  li r4, 0;
  add r0, r0, r5;
  add r5, r6, r0;
  stb r25, 9(r5);
  bl bta_dm_pm_set_mode;
lbl_80135210:
  addi r11, r1, 0x40;
  bl _restgpr_23;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pm_set_mode
// PAL: 0x80135228..0x801355a8
MARK_BINARY_BLOB(bta_dm_pm_set_mode, 0x80135228, 0x801355a8);
asm UNKNOWN_FUNCTION(bta_dm_pm_set_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_20;
  lis r5, 0x8033;
  mr r20, r3;
  addi r28, r5, 0x5f14;
  mr r21, r4;
  lbz r0, 0x4d(r28);
  li r27, 0;
  li r26, 0;
  li r25, 0;
  cmpwi r0, 0;
  li r24, 0;
  li r23, 0;
  li r22, 0;
  beq lbl_80135590;
  li r30, 0;
  b lbl_801352a4;
lbl_80135278:
  clrlwi r0, r30, 0x18;
  mr r4, r20;
  mulli r29, r0, 0xb;
  add r3, r28, r29;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801352a0;
  add r24, r28, r29;
  lbz r25, 0xa(r24);
  b lbl_801352b4;
lbl_801352a0:
  addi r30, r30, 1;
lbl_801352a4:
  lbz r0, 0x4d(r28);
  clrlwi r3, r30, 0x18;
  cmplw r3, r0;
  blt lbl_80135278;
lbl_801352b4:
  cmpwi r24, 0;
  beq lbl_80135590;
  lis r30, 0x8033;
  li r28, 0;
  addi r31, r30, 0x6018;
  b lbl_801353f8;
lbl_801352cc:
  clrlwi r3, r28, 0x18;
  rlwinm r0, r28, 3, 0x15, 0x1c;
  add r29, r0, r3;
  mr r4, r20;
  add r3, r31, r29;
  addi r3, r3, 1;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801353f4;
  lwz r7, -0x73d8(r13);
  add r8, r31, r29;
  lbz r3, 8(r8);
  li r9, 1;
  lbz r6, 1(r7);
  lbz r4, 7(r8);
  b lbl_80135340;
lbl_8013530c:
  clrlwi r5, r9, 0x18;
  rlwinm r0, r9, 2, 0x16, 0x1d;
  subf r0, r5, r0;
  add r5, r7, r0;
  lbzx r0, r7, r0;
  cmplw r0, r4;
  bne lbl_8013533c;
  lbz r0, 1(r5);
  cmplwi r0, 0xff;
  beq lbl_8013534c;
  cmplw r0, r3;
  beq lbl_8013534c;
lbl_8013533c:
  addi r9, r9, 1;
lbl_80135340:
  clrlwi r0, r9, 0x18;
  cmplw r0, r6;
  ble lbl_8013530c;
lbl_8013534c:
  clrlwi r3, r9, 0x18;
  rlwinm r0, r9, 2, 0x16, 0x1d;
  subf r3, r3, r0;
  lbz r0, 9(r8);
  add r4, r7, r3;
  lwz r3, -0x73d4(r13);
  lbz r4, 2(r4);
  slwi r0, r0, 3;
  mulli r4, r4, 0x4a;
  add r5, r3, r4;
  add r3, r5, r0;
  lbz r0, 0(r5);
  lbz r4, 2(r3);
  or r23, r23, r0;
  and. r0, r25, r4;
  bne lbl_801353bc;
  add r3, r31, r29;
  clrlwi r0, r27, 0x18;
  lbz r3, 9(r3);
  slwi r3, r3, 3;
  add r5, r5, r3;
  lbz r3, 2(r5);
  cmplw r3, r0;
  or r22, r22, r3;
  ble lbl_801353f4;
  lhz r26, 4(r5);
  mr r27, r4;
  b lbl_801353f4;
lbl_801353bc:
  lbz r3, 6(r3);
  and. r0, r25, r3;
  bne lbl_801353f4;
  add r4, r31, r29;
  clrlwi r0, r27, 0x18;
  lbz r4, 9(r4);
  slwi r4, r4, 3;
  add r5, r5, r4;
  lbz r4, 6(r5);
  cmplw r4, r0;
  or r22, r22, r4;
  ble lbl_801353f4;
  mr r27, r3;
  lhz r26, 8(r5);
lbl_801353f4:
  addi r28, r28, 1;
lbl_801353f8:
  lbz r0, 0x6018(r30);
  clrlwi r3, r28, 0x18;
  cmplw r3, r0;
  blt lbl_801352cc;
  clrlwi. r0, r27, 0x1e;
  beq lbl_80135430;
  clrlwi r3, r23, 0x18;
  clrlwi r0, r27, 0x18;
  and. r0, r3, r0;
  bne lbl_80135430;
  and r0, r23, r22;
  clrlwi. r27, r0, 0x1e;
  bne lbl_80135430;
  li r26, 0;
lbl_80135430:
  cmpwi r21, 0;
  bne lbl_801354d4;
  cmpwi r26, 0;
  beq lbl_801354d4;
  lis r21, 0x8033;
  li r0, 3;
  addi r21, r21, 0x5f14;
  li r4, 0;
  mtctr r0;
lbl_80135454:
  rlwinm r22, r4, 5, 0x13, 0x1a;
  add r3, r21, r22;
  lbz r0, 0xb6(r3);
  cmpwi r0, 0;
  bne lbl_801354a0;
  li r0, 1;
  mr r4, r20;
  stb r0, 0xb6(r3);
  addi r3, r3, 0xb0;
  bl bdcpy;
  lis r4, 0x8013;
  add r3, r21, r22;
  addi r4, r4, 0x5620;
  mr r5, r26;
  stw r4, 0xa0(r3);
  addi r3, r3, 0x98;
  li r4, 0;
  bl bta_sys_start_timer;
  b lbl_80135590;
lbl_801354a0:
  addi r4, r4, 1;
  clrlwi r0, r4, 0x18;
  bdnz lbl_80135454;
  cmplwi r0, 3;
  bne lbl_801354d4;
  lbz r0, -0x6610(r13);
  cmplwi r0, 2;
  blt lbl_80135590;
  lis r4, 0x8028;
  li r3, 0x501;
  addi r4, r4, 0x2a34;
  bl LogMsg_0;
  b lbl_80135590;
lbl_801354d4:
  clrlwi. r0, r27, 0x18;
  beq lbl_80135590;
  cmplwi r0, 1;
  bne lbl_80135524;
  li r0, 1;
  mr r3, r20;
  stb r0, 9(r24);
  addi r4, r1, 9;
  bl BTM_ReadPowerMode;
  lbz r0, 9(r1);
  cmplwi r0, 3;
  beq lbl_80135590;
  lis r3, 0x8033;
  lwz r5, -0x73d0(r13);
  addi r3, r3, 0x5f14;
  mr r4, r20;
  lbz r3, 0x95(r3);
  addi r5, r5, 0xa;
  bl BTM_SetPowerMode;
  b lbl_80135590;
lbl_80135524:
  cmplwi r0, 2;
  bne lbl_80135568;
  li r0, 2;
  mr r3, r20;
  stb r0, 9(r24);
  addi r4, r1, 8;
  bl BTM_ReadPowerMode;
  lbz r0, 8(r1);
  cmplwi r0, 2;
  beq lbl_80135590;
  lis r3, 0x8033;
  lwz r5, -0x73d0(r13);
  addi r3, r3, 0x5f14;
  mr r4, r20;
  lbz r3, 0x95(r3);
  bl BTM_SetPowerMode;
  b lbl_80135590;
lbl_80135568:
  cmplwi r0, 4;
  bne lbl_80135590;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x5f14;
  stb r0, 0x14(r1);
  lbz r3, 0x95(r3);
  mr r4, r20;
  addi r5, r1, 0xc;
  bl BTM_SetPowerMode;
lbl_80135590:
  addi r11, r1, 0x50;
  bl _restgpr_20;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pm_btm_cback
// PAL: 0x801355a8..0x80135620
MARK_BINARY_BLOB(bta_dm_pm_btm_cback, 0x801355a8, 0x80135620);
asm UNKNOWN_FUNCTION(bta_dm_pm_btm_cback) {
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
  li r3, 0x14;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80135608;
  li r0, 0x109;
  mr r4, r27;
  sth r0, 0(r3);
  stb r28, 0xe(r3);
  sth r29, 0x10(r3);
  stb r30, 0x12(r3);
  addi r3, r3, 8;
  bl bdcpy;
  mr r3, r31;
  bl bta_sys_sendmsg;
lbl_80135608:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pm_timer_cback
// PAL: 0x80135620..0x80135718
MARK_BINARY_BLOB(bta_dm_pm_timer_cback, 0x80135620, 0x80135718);
asm UNKNOWN_FUNCTION(bta_dm_pm_timer_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x5f14;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  li r30, 0;
  lbz r0, 0xb6(r4);
  cmpwi r0, 0;
  beq lbl_80135664;
  addi r0, r4, 0x98;
  cmplw r0, r3;
  bne lbl_80135664;
  li r0, 0;
  stb r0, 0xb6(r4);
  b lbl_801356b8;
lbl_80135664:
  lbz r0, 0xd6(r4);
  li r30, 1;
  cmpwi r0, 0;
  beq lbl_8013568c;
  addi r0, r4, 0xb8;
  cmplw r0, r3;
  bne lbl_8013568c;
  li r0, 0;
  stb r0, 0xd6(r4);
  b lbl_801356b8;
lbl_8013568c:
  lbz r0, 0xf6(r4);
  li r30, 2;
  cmpwi r0, 0;
  beq lbl_801356b4;
  addi r0, r4, 0xd8;
  cmplw r0, r3;
  bne lbl_801356b4;
  li r0, 0;
  stb r0, 0xf6(r4);
  b lbl_801356b8;
lbl_801356b4:
  li r30, 3;
lbl_801356b8:
  cmplwi r30, 3;
  beq lbl_80135700;
  li r3, 0xe;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80135700;
  lis r4, 0x8033;
  li r5, 0x10a;
  addi r4, r4, 0x5f14;
  rlwinm r0, r30, 5, 0x13, 0x1a;
  sth r5, 0(r3);
  add r4, r4, r0;
  addi r4, r4, 0xb0;
  addi r3, r3, 8;
  bl bdcpy;
  mr r3, r31;
  bl bta_sys_sendmsg;
lbl_80135700:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pm_btm_status
// PAL: 0x80135718..0x80135838
MARK_BINARY_BLOB(bta_dm_pm_btm_status, 0x80135718, 0x80135838);
asm UNKNOWN_FUNCTION(bta_dm_pm_btm_status) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r30, 0x8033;
  mr r31, r3;
  addi r30, r30, 0x5f14;
  li r27, 0;
lbl_8013573c:
  rlwinm r28, r27, 5, 0x13, 0x1a;
  add r29, r30, r28;
  lbz r0, 0xb6(r29);
  cmpwi r0, 0;
  beq lbl_8013577c;
  addi r3, r29, 0xb0;
  addi r4, r31, 8;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_8013577c;
  mr r3, r29;
  addi r3, r3, 0x98;
  bl bta_sys_stop_timer;
  li r0, 0;
  stb r0, 0xb6(r29);
  b lbl_80135788;
lbl_8013577c:
  addi r27, r27, 1;
  cmplwi r27, 3;
  blt lbl_8013573c;
lbl_80135788:
  lbz r0, 0xe(r31);
  cmpwi r0, 0;
  beq lbl_80135798;
  b lbl_80135820;
lbl_80135798:
  lbz r0, 0x12(r31);
  cmpwi r0, 0;
  beq lbl_80135814;
  lis r3, 0x8033;
  li r29, 0;
  addi r30, r3, 0x5f14;
  b lbl_80135800;
lbl_801357b4:
  clrlwi r0, r29, 0x18;
  addi r4, r31, 8;
  mulli r28, r0, 0xb;
  add r3, r30, r28;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801357fc;
  add r5, r30, r28;
  lbz r0, 9(r5);
  clrlwi. r6, r0, 0x1e;
  beq lbl_80135820;
  lbz r0, 0xa(r5);
  addi r3, r31, 8;
  li r4, 0;
  or r0, r0, r6;
  stb r0, 0xa(r5);
  bl bta_dm_pm_set_mode;
  b lbl_80135820;
lbl_801357fc:
  addi r29, r29, 1;
lbl_80135800:
  lbz r0, 0x4d(r30);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_801357b4;
  b lbl_80135820;
lbl_80135814:
  addi r3, r31, 8;
  li r4, 0;
  bl bta_dm_pm_set_mode;
lbl_80135820:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pm_timer
// PAL: 0x80135838..0x80135844
MARK_BINARY_BLOB(bta_dm_pm_timer, 0x80135838, 0x80135844);
asm UNKNOWN_FUNCTION(bta_dm_pm_timer) {
  // clang-format off
  nofralloc;
  li r4, 1;
  addi r3, r3, 8;
  b bta_dm_pm_set_mode;
  // clang-format on
}
