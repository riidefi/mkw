#include "ptim.h"

#include "gki_buffer.h"
#include "gki_time.h"
#include "bta_sys.h"

// Symbol: ptim_init
// PAL: 0x801322fc..0x80132348
MARK_BINARY_BLOB(ptim_init, 0x801322fc, 0x80132348);
asm UNKNOWN_FUNCTION(ptim_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl GKI_init_timer_list;
  stw r30, 0xc(r29);
  stb r31, 0x10(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ptim_timer_update
// PAL: 0x80132348..0x801323fc
MARK_BINARY_BLOB(ptim_timer_update, 0x80132348, 0x801323fc);
asm UNKNOWN_FUNCTION(ptim_timer_update) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r4, 0xc(r3);
  bl GKI_update_timer_list;
  b lbl_801323bc;
lbl_8013236c:
  mr r3, r30;
  mr r4, r31;
  bl GKI_remove_from_timer_list;
  lwz r12, 8(r31);
  cmpwi r12, 0;
  beq lbl_80132394;
  mr r3, r31;
  mtctr r12;
  bctrl;
  b lbl_801323bc;
lbl_80132394:
  lhz r0, 0x14(r31);
  cmpwi r0, 0;
  beq lbl_801323bc;
  li r3, 8;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_801323bc;
  lhz r0, 0x14(r31);
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_801323bc:
  lwz r31, 0(r30);
  cmpwi r31, 0;
  beq lbl_801323d4;
  lwz r0, 0xc(r31);
  cmpwi r0, 0;
  ble lbl_8013236c;
lbl_801323d4:
  cmpwi r31, 0;
  bne lbl_801323e4;
  lbz r3, 0x10(r30);
  bl GKI_stop_timer;
lbl_801323e4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ptim_start_timer
// PAL: 0x801323fc..0x8013249c
MARK_BINARY_BLOB(ptim_start_timer, 0x801323fc, 0x8013249c);
asm UNKNOWN_FUNCTION(ptim_start_timer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8013245c;
  lis r4, 0x6666;
  lwz r0, 0xc(r28);
  addi r4, r4, 0x6667;
  lbz r3, 0x10(r3);
  mulhw r0, r4, r0;
  li r5, 1;
  srawi r0, r0, 2;
  srwi r4, r0, 0x1f;
  add r4, r0, r4;
  bl GKI_start_timer;
lbl_8013245c:
  mr r3, r28;
  mr r4, r29;
  bl GKI_remove_from_timer_list;
  sth r30, 0x14(r29);
  mr r3, r28;
  mr r4, r29;
  stw r31, 0xc(r29);
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

// Symbol: ptim_stop_timer
// PAL: 0x8013249c..0x801324dc
MARK_BINARY_BLOB(ptim_stop_timer, 0x8013249c, 0x801324dc);
asm UNKNOWN_FUNCTION(ptim_stop_timer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl GKI_remove_from_timer_list;
  lwz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_801324c8;
  lbz r3, 0x10(r31);
  bl GKI_stop_timer;
lbl_801324c8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
