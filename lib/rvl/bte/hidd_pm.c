#include "hidd_pm.h"

#include <string.h>

#include "bte_task1.h"
#include "btm_pm.h"

// Symbol: hidd_pm_set_now
// PAL: 0x80146f24..0x801470fc
MARK_BINARY_BLOB(hidd_pm_set_now, 0x80146f24, 0x801470fc);
asm UNKNOWN_FUNCTION(hidd_pm_set_now) {
  // clang-format off
  nofralloc;
lbl_80146f24:
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  li r5, 0;
  stw r0, 0x24(r1);
  addi r4, r4, -29200;
  stw r31, 0x1c(r1);
  lbz r0, 0x6e(r4);
  stw r5, 0xc(r1);
  cmpwi r0, 0;
  stw r5, 0x10(r1);
  sth r5, 0x14(r1);
  stb r5, 8(r1);
  bne lbl_80146f90;
  lbz r6, 0x6a(r4);
  lbz r5, 8(r3);
  cmplw r5, r6;
  bne lbl_80146fa8;
  cmpwi r5, 0;
  beq lbl_80146f90;
  lhz r4, 0x6c(r4);
  lhz r0, 2(r3);
  cmplw r4, r0;
  blt lbl_80146fa8;
  lhz r0, 0(r3);
  cmplw r4, r0;
  bgt lbl_80146fa8;
lbl_80146f90:
  lis r4, 0x8034;
  li r0, 0xff;
  addi r4, r4, -29200;
  li r3, 1;
  stb r0, 0x78(r4);
  b lbl_801470e8;
lbl_80146fa8:
  cmpwi r5, 2;
  beq lbl_8014702c;
  bge lbl_80146fc0;
  cmpwi r5, 0;
  beq lbl_80146fcc;
  b lbl_801470a0;
lbl_80146fc0:
  cmpwi r5, 4;
  bge lbl_801470a0;
  b lbl_80147068;
lbl_80146fcc:
  cmplwi r6, 2;
  bne lbl_80146ffc;
  lis r31, 0x8034;
  addi r5, r1, 0xc;
  addi r4, r31, -29200;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  addi r4, r31, -29200;
  li r0, 1;
  stb r3, 8(r1);
  stb r0, 0x6e(r4);
  b lbl_801470a0;
lbl_80146ffc:
  cmplwi r6, 3;
  bne lbl_801470a0;
  lis r31, 0x8034;
  addi r5, r1, 0xc;
  addi r4, r31, -29200;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  addi r4, r31, -29200;
  li r0, 1;
  stb r3, 8(r1);
  stb r0, 0x6e(r4);
  b lbl_801470a0;
lbl_8014702c:
  cmpwi r6, 0;
  beq lbl_80147040;
  addi r3, r1, 0xc;
  bl lbl_80146f24;
  b lbl_801470a0;
lbl_80147040:
  lis r31, 0x8034;
  mr r5, r3;
  addi r4, r31, -29200;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  addi r4, r31, -29200;
  li r0, 1;
  stb r3, 8(r1);
  stb r0, 0x6e(r4);
  b lbl_801470a0;
lbl_80147068:
  cmpwi r6, 0;
  beq lbl_8014707c;
  addi r3, r1, 0xc;
  bl lbl_80146f24;
  b lbl_801470a0;
lbl_8014707c:
  lis r31, 0x8034;
  mr r5, r3;
  addi r4, r31, -29200;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  addi r4, r31, -29200;
  li r0, 1;
  stb r3, 8(r1);
  stb r0, 0x6e(r4);
lbl_801470a0:
  lbz r4, 8(r1);
  cmplwi r4, 1;
  bgt lbl_801470b4;
  li r3, 1;
  b lbl_801470e8;
lbl_801470b4:
  lis r3, 0x8034;
  addi r0, r4, 0x37;
  addi r3, r3, -29200;
  stb r0, 8(r1);
  lwz r12, 0xc4(r3);
  cmpwi r12, 0;
  beq lbl_801470e4;
  lbz r4, 0x6f(r3);
  addi r5, r1, 8;
  li r3, 4;
  mtctr r12;
  bctrl;
lbl_801470e4:
  li r3, 0;
lbl_801470e8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidd_pm_proc_mode_change
// PAL: 0x801470fc..0x80147254
MARK_BINARY_BLOB(hidd_pm_proc_mode_change, 0x801470fc, 0x80147254);
asm UNKNOWN_FUNCTION(hidd_pm_proc_mode_change) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, -29200;
  stw r29, 0x14(r1);
  mr r29, r4;
  lbz r0, 0x140(r30);
  stb r3, 8(r1);
  cmpwi r0, 0;
  sth r5, 0xa(r1);
  beq lbl_80147238;
  li r31, 0;
  clrlwi. r0, r3, 0x18;
  stb r31, 0x6e(r30);
  beq lbl_80147168;
  lwz r12, 0xc4(r30);
  cmpwi r12, 0;
  beq lbl_80147238;
  addi r5, r1, 8;
  lbz r4, 0x6f(r30);
  li r3, 4;
  mtctr r12;
  bctrl;
  b lbl_80147238;
lbl_80147168:
  lbz r0, 0x78(r30);
  clrlwi r3, r5, 0x10;
  stb r4, 0x6a(r30);
  cmplwi r0, 0xff;
  sth r5, 0x6c(r30);
  beq lbl_801471d0;
  cmplw r0, r4;
  bne lbl_801471a8;
  cmpwi r0, 0;
  beq lbl_801471bc;
  lhz r0, 0x72(r30);
  cmplw r3, r0;
  blt lbl_801471a8;
  lhz r0, 0x70(r30);
  cmplw r3, r0;
  ble lbl_801471bc;
lbl_801471a8:
  lis r3, 0x8034;
  addi r3, r3, -29200;
  addi r3, r3, 0x70;
  bl hidd_pm_set_now;
  b lbl_80147210;
lbl_801471bc:
  lis r3, 0x8034;
  li r0, 0xff;
  addi r3, r3, -29200;
  stb r0, 0x78(r3);
  b lbl_80147210;
lbl_801471d0:
  cmpwi r4, 0;
  bne lbl_80147210;
  addi r3, r30, 0x70;
  addi r4, r30, 0x4c;
  li r5, 0xa;
  bl memcpy;
  addi r3, r30, 0x4c;
  bl hidd_pm_set_now;
  lis r3, 0x8014;
  stb r31, 0x6f(r30);
  addi r3, r3, 0x7254;
  li r4, 0x16;
  stw r3, 0x44(r30);
  addi r3, r30, 0x34;
  li r5, 0x3c;
  bl btu_start_timer;
lbl_80147210:
  lis r3, 0x8034;
  addi r3, r3, -29200;
  lwz r12, 0xc4(r3);
  cmpwi r12, 0;
  beq lbl_80147238;
  mr r4, r29;
  addi r5, r1, 0xa;
  li r3, 3;
  mtctr r12;
  bctrl;
lbl_80147238:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidd_pm_inact_timeout
// PAL: 0x80147254..0x801472a0
MARK_BINARY_BLOB(hidd_pm_inact_timeout, 0x80147254, 0x801472a0);
asm UNKNOWN_FUNCTION(hidd_pm_inact_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 0xa;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, -29200;
  addi r3, r31, 0x70;
  addi r4, r31, 0x56;
  bl memcpy;
  addi r3, r31, 0x56;
  bl hidd_pm_set_now;
  li r0, 1;
  stb r0, 0x6f(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
