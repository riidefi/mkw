#include "bta_sys.h"

#include <string.h>

#include "gki_buffer.h"
#include "gki_ppc.h"
#include "bte_logmsg.h"
#include "ptim.h"

// Extern function references.
// PAL: 0x801347ec
extern UNKNOWN_FUNCTION(bta_dm_immediate_disable);

// Symbol: bta_sys_rm_register
// PAL: 0x80131e64..0x80131e74
MARK_BINARY_BLOB(bta_sys_rm_register, 0x80131e64, 0x80131e74);
asm UNKNOWN_FUNCTION(bta_sys_rm_register) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x5dd8;
  stw r3, 0x80(r4);
  blr;
  // clang-format on
}

// Symbol: bta_sys_compress_register
// PAL: 0x80131e74..0x80131e84
MARK_BINARY_BLOB(bta_sys_compress_register, 0x80131e74, 0x80131e84);
asm UNKNOWN_FUNCTION(bta_sys_compress_register) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x5dd8;
  stw r3, 0x88(r4);
  blr;
  // clang-format on
}

// Symbol: bta_sys_pm_register
// PAL: 0x80131e84..0x80131e94
MARK_BINARY_BLOB(bta_sys_pm_register, 0x80131e84, 0x80131e94);
asm UNKNOWN_FUNCTION(bta_sys_pm_register) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x5dd8;
  stw r3, 0x84(r4);
  blr;
  // clang-format on
}

// Symbol: bta_sys_conn_open
// PAL: 0x80131e94..0x80131f58
MARK_BINARY_BLOB(bta_sys_conn_open, 0x80131e94, 0x80131f58);
asm UNKNOWN_FUNCTION(bta_sys_conn_open) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x24(r1);
  addi r6, r6, 0x5dd8;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r12, 0x80(r6);
  cmpwi r12, 0;
  beq lbl_80131ee4;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80131ee4:
  lis r3, 0x8033;
  addi r3, r3, 0x5dd8;
  lwz r12, 0x84(r3);
  cmpwi r12, 0;
  beq lbl_80131f10;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80131f10:
  lis r3, 0x8033;
  addi r3, r3, 0x5dd8;
  lwz r12, 0x88(r3);
  cmpwi r12, 0;
  beq lbl_80131f3c;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80131f3c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_sys_conn_close
// PAL: 0x80131f58..0x8013201c
MARK_BINARY_BLOB(bta_sys_conn_close, 0x80131f58, 0x8013201c);
asm UNKNOWN_FUNCTION(bta_sys_conn_close) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x24(r1);
  addi r6, r6, 0x5dd8;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r12, 0x80(r6);
  cmpwi r12, 0;
  beq lbl_80131fa8;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_80131fa8:
  lis r3, 0x8033;
  addi r3, r3, 0x5dd8;
  lwz r12, 0x84(r3);
  cmpwi r12, 0;
  beq lbl_80131fd4;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_80131fd4:
  lis r3, 0x8033;
  addi r3, r3, 0x5dd8;
  lwz r12, 0x88(r3);
  cmpwi r12, 0;
  beq lbl_80132000;
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_80132000:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_sys_sco_close
// PAL: 0x8013201c..0x80132050
MARK_BINARY_BLOB(bta_sys_sco_close, 0x8013201c, 0x80132050);
asm UNKNOWN_FUNCTION(bta_sys_sco_close) {
  // clang-format off
  nofralloc;
  lis r6, 0x8033;
  mr r0, r4;
  addi r6, r6, 0x5dd8;
  lwz r12, 0x84(r6);
  mr r6, r5;
  cmpwi r12, 0;
  beqlr;
  mr r4, r3;
  mr r5, r0;
  li r3, 5;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: bta_sys_idle
// PAL: 0x80132050..0x80132084
MARK_BINARY_BLOB(bta_sys_idle, 0x80132050, 0x80132084);
asm UNKNOWN_FUNCTION(bta_sys_idle) {
  // clang-format off
  nofralloc;
  lis r6, 0x8033;
  mr r0, r4;
  addi r6, r6, 0x5dd8;
  lwz r12, 0x84(r6);
  mr r6, r5;
  cmpwi r12, 0;
  beqlr;
  mr r4, r3;
  mr r5, r0;
  li r3, 6;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: bta_sys_busy
// PAL: 0x80132084..0x801320b8
MARK_BINARY_BLOB(bta_sys_busy, 0x80132084, 0x801320b8);
asm UNKNOWN_FUNCTION(bta_sys_busy) {
  // clang-format off
  nofralloc;
  lis r6, 0x8033;
  mr r0, r4;
  addi r6, r6, 0x5dd8;
  lwz r12, 0x84(r6);
  mr r6, r5;
  cmpwi r12, 0;
  beqlr;
  mr r4, r3;
  mr r5, r0;
  li r3, 7;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: bta_sys_init
// PAL: 0x801320b8..0x8013211c
MARK_BINARY_BLOB(bta_sys_init, 0x801320b8, 0x8013211c);
asm UNKNOWN_FUNCTION(bta_sys_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x8c;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r3, r31, 0x5dd8;
  bl memset;
  lwz r5, -0x73b8(r13);
  addi r31, r31, 0x5dd8;
  addi r3, r31, 0x68;
  li r4, 0x3e8;
  lbz r5, 3(r5);
  bl ptim_init;
  bl GKI_get_taskid;
  stb r3, 0x7d(r31);
  lwz r3, -0x73b8(r13);
  lbz r0, 4(r3);
  stb r0, -0x6610(r13);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_sys_event
// PAL: 0x8013211c..0x80132208
MARK_BINARY_BLOB(bta_sys_event, 0x8013211c, 0x80132208);
asm UNKNOWN_FUNCTION(bta_sys_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 1;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_80132158;
  lis r4, 0x8028;
  lhz r5, 0(r30);
  addi r4, r4, 0x2890;
  li r3, 0x503;
  bl LogMsg_1;
lbl_80132158:
  lis r3, 0x8033;
  lhz r4, 0(r30);
  addi r3, r3, 0x5dd8;
  lbz r0, 0x7e(r3);
  srawi r5, r4, 8;
  cmpwi r0, 0;
  beq lbl_8013218c;
  cmplwi r4, 0x101;
  bne lbl_80132180;
  bl bta_dm_immediate_disable;
lbl_80132180:
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_801321f0;
lbl_8013218c:
  clrlwi r0, r5, 0x18;
  cmplwi r0, 0x1a;
  bge lbl_801321c0;
  rlwinm r0, r5, 2, 0x16, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_801321c0;
  lwz r12, 0(r3);
  mr r3, r30;
  mtctr r12;
  bctrl;
  mr r31, r3;
  b lbl_801321e0;
lbl_801321c0:
  lbz r0, -0x6610(r13);
  cmplwi r0, 2;
  blt lbl_801321e0;
  lis r4, 0x8028;
  clrlwi r5, r5, 0x18;
  addi r4, r4, 0x28a4;
  li r3, 0x501;
  bl LogMsg_1;
lbl_801321e0:
  clrlwi. r0, r31, 0x18;
  beq lbl_801321f0;
  mr r3, r30;
  bl GKI_freebuf;
lbl_801321f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_sys_timer_update
// PAL: 0x80132208..0x80132228
MARK_BINARY_BLOB(bta_sys_timer_update, 0x80132208, 0x80132228);
asm UNKNOWN_FUNCTION(bta_sys_timer_update) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x5dd8;
  lbz r0, 0x7c(r3);
  cmpwi r0, 0;
  bnelr;
  addi r3, r3, 0x68;
  b ptim_timer_update;
  blr;
  // clang-format on
}

// Symbol: bta_sys_register
// PAL: 0x80132228..0x8013223c
MARK_BINARY_BLOB(bta_sys_register, 0x80132228, 0x8013223c);
asm UNKNOWN_FUNCTION(bta_sys_register) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  addi r5, r5, 0x5dd8;
  stwx r4, r5, r0;
  blr;
  // clang-format on
}

// Symbol: bta_sys_sendmsg
// PAL: 0x8013223c..0x80132258
MARK_BINARY_BLOB(bta_sys_sendmsg, 0x8013223c, 0x80132258);
asm UNKNOWN_FUNCTION(bta_sys_sendmsg) {
  // clang-format off
  nofralloc;
  lwz r4, -0x73b8(r13);
  lis r6, 0x8033;
  addi r6, r6, 0x5dd8;
  mr r5, r3;
  lbz r3, 0x7d(r6);
  lbz r4, 2(r4);
  b GKI_send_msg;
  // clang-format on
}

// Symbol: bta_sys_start_timer
// PAL: 0x80132258..0x80132278
MARK_BINARY_BLOB(bta_sys_start_timer, 0x80132258, 0x80132278);
asm UNKNOWN_FUNCTION(bta_sys_start_timer) {
  // clang-format off
  nofralloc;
  lis r7, 0x8033;
  mr r0, r4;
  addi r7, r7, 0x5dd8;
  mr r6, r5;
  mr r4, r3;
  mr r5, r0;
  addi r3, r7, 0x68;
  b ptim_start_timer;
  // clang-format on
}

// Symbol: bta_sys_stop_timer
// PAL: 0x80132278..0x8013228c
MARK_BINARY_BLOB(bta_sys_stop_timer, 0x80132278, 0x8013228c);
asm UNKNOWN_FUNCTION(bta_sys_stop_timer) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  mr r4, r3;
  addi r5, r5, 0x5dd8;
  addi r3, r5, 0x68;
  b ptim_stop_timer;
  // clang-format on
}

// Symbol: bta_sys_disable
// PAL: 0x8013228c..0x801322f4
MARK_BINARY_BLOB(bta_sys_disable, 0x8013228c, 0x801322f4);
asm UNKNOWN_FUNCTION(bta_sys_disable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5dd8;
  stw r30, 8(r1);
  li r30, 0;
lbl_801322ac:
  lwz r3, 0(r31);
  cmpwi r3, 0;
  beq lbl_801322cc;
  lwz r12, 4(r3);
  cmpwi r12, 0;
  beq lbl_801322cc;
  mtctr r12;
  bctrl;
lbl_801322cc:
  addi r30, r30, 1;
  addi r31, r31, 4;
  cmpwi r30, 0x1a;
  blt lbl_801322ac;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_sys_set_trace_level
// PAL: 0x801322f4..0x801322fc
MARK_BINARY_BLOB(bta_sys_set_trace_level, 0x801322f4, 0x801322fc);
asm UNKNOWN_FUNCTION(bta_sys_set_trace_level) {
  // clang-format off
  nofralloc;
  stb r3, -0x6610(r13);
  blr;
  // clang-format on
}
