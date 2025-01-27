#include "bte_main.h"

#include <rvl/os/osAlarm.h>
#include <rvl/os/osContext.h>
#include <rvl/os/os.h>

#include "gki_ppc.h"
#include "bta_api.h"
#include "bte_hcisu.h"
#include "bte_task1.h"

// Extern function references.
// PAL: 0x80143334
extern UNKNOWN_FUNCTION(BTE_Init);

// Symbol: BTUInterruptHandler
// PAL: 0x801317e8..0x80131800
MARK_BINARY_BLOB(BTUInterruptHandler, 0x801317e8, 0x80131800);
asm UNKNOWN_FUNCTION(BTUInterruptHandler) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  lis r3, 0x8013;
  addi r4, r4, 0x4d20;
  addi r3, r3, 0x1980;
  addi r4, r4, 0x1000;
  b OSSwitchFiber;
  // clang-format on
}

// Symbol: BTA_Init
// PAL: 0x80131800..0x801318dc
MARK_BINARY_BLOB(BTA_Init, 0x80131800, 0x801318dc);
asm UNKNOWN_FUNCTION(BTA_Init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r31, 0xc(r1);
  stw r0, -0x661c(r13);
  bl GKI_init;
  bl GKI_enable;
  bl BTE_Init;
  lis r4, 0x8025;
  addi r0, r13, -29608;
  addi r4, r4, -14624;
  stw r0, -0x6624(r13);
  li r3, 0;
  stw r4, -0x6628(r13);
  bl bte_hcisu_task;
  b lbl_8013184c;
lbl_80131844:
  li r3, 0x64;
  bl GKI_delay;
lbl_8013184c:
  lwz r0, -0x73f0(r13);
  cmpwi r0, 0;
  bne lbl_80131844;
  bl btu_task_init;
  lis r31, 0x8033;
  addi r3, r31, 0x5d20;
  bl OSCreateAlarm;
  bl OSGetTime;
  lis r5, 0x8000;
  lis r9, 0x8013;
  lwz r0, 0xf8(r5);
  lis r6, 0x1062;
  mr r5, r3;
  addi r9, r9, 0x17e8;
  addi r3, r6, 0x4dd3;
  srwi r0, r0, 2;
  mulhwu r0, r3, r0;
  mr r6, r4;
  addi r3, r31, 0x5d20;
  li r7, 0;
  rlwinm r8, r0, 0x1b, 5, 0x1e;
  bl OSSetPeriodicAlarm;
  li r3, 0;
  bl GKI_run;
  b lbl_801318b8;
lbl_801318b0:
  li r3, 0x7d0;
  bl GKI_delay;
lbl_801318b8:
  bl BTA_DmIsDeviceUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_801318b0;
  lwz r31, 0xc(r1);
  li r3, 0;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_CleanUp
// PAL: 0x801318dc..0x80131910
MARK_BINARY_BLOB(BTA_CleanUp, 0x801318dc, 0x80131910);
asm UNKNOWN_FUNCTION(BTA_CleanUp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r3, -0x661c(r13);
  lis r3, 0x8033;
  addi r3, r3, 0x5d20;
  bl OSCancelAlarm;
  bl bte_hcisu_close;
  bl GKI_shutdown;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_usb_close_evt
// PAL: 0x80131910..0x80131940
MARK_BINARY_BLOB(bta_usb_close_evt, 0x80131910, 0x80131940);
asm UNKNOWN_FUNCTION(bta_usb_close_evt) {
  // clang-format off
  nofralloc;
  lwz r12, -0x661c(r13);
  cmpwi r12, 0;
  beqlr;
  extsb. r0, r3;
  blt lbl_80131930;
  li r3, 0;
  mtctr r12;
  bctr;
lbl_80131930:
  li r3, 1;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}
