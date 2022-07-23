#include "gki_ppc.h"

#include <string.h>
#include <rvl/os/osInterrupt.h>

#include "gki_buffer.h"
#include "gki_time.h"

// Extern function references.
// PAL: 0x801cb9d8
extern UNKNOWN_FUNCTION(App_MEMalloc);
// PAL: 0x801cba28
extern UNKNOWN_FUNCTION(App_MEMfree);

// Symbol: GKI_init
// PAL: 0x80130070..0x80130100
MARK_BINARY_BLOB(GKI_init, 0x80130070, 0x80130100);
asm UNKNOWN_FUNCTION(GKI_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x3;
  li r4, 0;
  stw r0, 0x14(r1);
  addi r5, r5, -0x7520;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lis r30, 0x8031;
  addi r3, r30, -0x6640;
  bl memset;
  bl gki_buffer_init;
  bl gki_timers_init;
  addi r31, r30, -0x6640;
  li r4, 1;
  addis r3, r31, 3;
  li r0, 0;
  stb r4, -0x77fe(r3);
  stw r0, -0x7818(r3);
  stw r0, -0x77b8(r3);
  sth r0, -0x77f4(r3);
  stb r0, -0x6640(r30);
  bl OSEnableInterrupts;
  lbz r0, -0x6640(r30);
  slwi r0, r0, 2;
  add r4, r31, r0;
  stw r3, 4(r4);
  lbz r3, -0x6640(r30);
  addi r0, r3, 1;
  stb r0, -0x6640(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_shutdown
// PAL: 0x80130100..0x801301a8
MARK_BINARY_BLOB(GKI_shutdown, 0x80130100, 0x801301a8);
asm UNKNOWN_FUNCTION(GKI_shutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl OSDisableInterrupts;
  lis r30, 0x8031;
  li r0, 0;
  lbz r5, -0x6640(r30);
  addi r31, r30, -0x6640;
  addis r4, r31, 3;
  slwi r5, r5, 2;
  add r5, r31, r5;
  stw r3, 4(r5);
  lbz r3, -0x6640(r30);
  addi r3, r3, 1;
  stb r3, -0x6640(r30);
  stb r0, -0x77fe(r4);
  lbz r3, -0x6640(r30);
  addi r3, r3, -1;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  stb r3, -0x6640(r30);
  add r3, r31, r0;
  lwz r3, 4(r3);
  bl OSRestoreInterrupts;
  b lbl_80130184;
lbl_80130168:
  lbz r3, -0x6640(r30);
  addi r3, r3, -1;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  stb r3, -0x6640(r30);
  add r3, r31, r0;
  lwz r3, 4(r3);
  bl OSRestoreInterrupts;
lbl_80130184:
  lbz r0, -0x6640(r30);
  cmpwi r0, 0;
  bne lbl_80130168;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_run
// PAL: 0x801301a8..0x801301ac
MARK_BINARY_BLOB(GKI_run, 0x801301a8, 0x801301ac);
asm UNKNOWN_FUNCTION(GKI_run) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: GKI_sched_lock
// PAL: 0x801301ac..0x801301b0
MARK_BINARY_BLOB(GKI_sched_lock, 0x801301ac, 0x801301b0);
asm UNKNOWN_FUNCTION(GKI_sched_lock) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: GKI_sched_unlock
// PAL: 0x801301b0..0x801301b4
MARK_BINARY_BLOB(GKI_sched_unlock, 0x801301b0, 0x801301b4);
asm UNKNOWN_FUNCTION(GKI_sched_unlock) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: GKI_delay
// PAL: 0x801301b4..0x801301b8
MARK_BINARY_BLOB(GKI_delay, 0x801301b4, 0x801301b8);
asm UNKNOWN_FUNCTION(GKI_delay) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: GKI_send_event
// PAL: 0x801301b8..0x8013025c
MARK_BINARY_BLOB(GKI_send_event, 0x801301b8, 0x8013025c);
asm UNKNOWN_FUNCTION(GKI_send_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 8;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  blt lbl_801301e4;
  li r3, 1;
  b lbl_80130244;
lbl_801301e4:
  bl OSDisableInterrupts;
  lis r7, 0x8031;
  rlwinm r0, r30, 1, 0x17, 0x1e;
  lbz r5, -0x6640(r7);
  addi r6, r7, -0x6640;
  addis r4, r6, 3;
  slwi r5, r5, 2;
  add r5, r6, r5;
  add r4, r4, r0;
  stw r3, 4(r5);
  lbz r3, -0x6640(r7);
  addi r0, r3, 1;
  stb r0, -0x6640(r7);
  lhz r0, -0x77f8(r4);
  or r0, r0, r31;
  sth r0, -0x77f8(r4);
  lbz r3, -0x6640(r7);
  addi r3, r3, -1;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  stb r3, -0x6640(r7);
  add r3, r6, r0;
  lwz r3, 4(r3);
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_80130244:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_get_taskid
// PAL: 0x8013025c..0x80130264
MARK_BINARY_BLOB(GKI_get_taskid, 0x8013025c, 0x80130264);
asm UNKNOWN_FUNCTION(GKI_get_taskid) {
  // clang-format off
  nofralloc;
  li r3, 2;
  blr;
  // clang-format on
}

// Symbol: GKI_enable
// PAL: 0x80130264..0x80130288
MARK_BINARY_BLOB(GKI_enable, 0x80130264, 0x80130288);
asm UNKNOWN_FUNCTION(GKI_enable) {
  // clang-format off
  nofralloc;
  lis r5, 0x8031;
  lbz r4, -0x6640(r5);
  addi r3, r5, -0x6640;
  addi r4, r4, -1;
  rlwinm r0, r4, 2, 0x16, 0x1d;
  stb r4, -0x6640(r5);
  add r3, r3, r0;
  lwz r3, 4(r3);
  b OSRestoreInterrupts;
  // clang-format on
}

// Symbol: GKI_disable
// PAL: 0x80130288..0x801302cc
MARK_BINARY_BLOB(GKI_disable, 0x80130288, 0x801302cc);
asm UNKNOWN_FUNCTION(GKI_disable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSDisableInterrupts;
  lis r5, 0x8031;
  lbz r0, -0x6640(r5);
  addi r4, r5, -0x6640;
  slwi r0, r0, 2;
  add r4, r4, r0;
  stw r3, 4(r4);
  lbz r3, -0x6640(r5);
  addi r0, r3, 1;
  stb r0, -0x6640(r5);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_exception
// PAL: 0x801302cc..0x801302d0
MARK_BINARY_BLOB(GKI_exception, 0x801302cc, 0x801302d0);
asm UNKNOWN_FUNCTION(GKI_exception) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: GKI_os_malloc
// PAL: 0x801302d0..0x801302fc
MARK_BINARY_BLOB(GKI_os_malloc, 0x801302d0, 0x801302fc);
asm UNKNOWN_FUNCTION(GKI_os_malloc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl App_MEMalloc;
  cmpwi r3, 0;
  bne lbl_801302ec;
  li r3, 0;
lbl_801302ec:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GKI_os_free
// PAL: 0x801302fc..0x80130300
MARK_BINARY_BLOB(GKI_os_free, 0x801302fc, 0x80130300);
asm UNKNOWN_FUNCTION(GKI_os_free) {
  // clang-format off
  nofralloc;
  b App_MEMfree;
  // clang-format on
}
