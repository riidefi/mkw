#include "hidd_mgmt.h"

#include "bte_logmsg.h"
#include "bte_task1.h"
#include "hidd_conn.h"

// Symbol: hidd_proc_repage_timeout
// PAL: 0x80146e5c..0x80146f24
MARK_BINARY_BLOB(hidd_proc_repage_timeout, 0x80146e5c, 0x80146f24);
asm UNKNOWN_FUNCTION(hidd_proc_repage_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8034;
  stw r0, 0x14(r1);
  addi r3, r3, -29200;
  stw r31, 0xc(r1);
  lbz r0, 0x141(r3);
  cmplwi r0, 5;
  blt lbl_80146e94;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 4;
  addi r4, r4, 0x4f80;
  bl LogMsg_0;
lbl_80146e94:
  lis r31, 0x8034;
  addi r31, r31, -29200;
  lbz r3, 9(r31);
  addi r0, r3, 1;
  stb r0, 9(r31);
  bl hidd_conn_initiate;
  clrlwi. r0, r3, 0x18;
  beq lbl_80146ef8;
  lbz r0, 9(r31);
  cmplwi r0, 0xf;
  ble lbl_80146ee4;
  lwz r12, 0xc4(r31);
  li r0, 0;
  stb r0, 8(r31);
  li r3, 1;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  b lbl_80146f10;
lbl_80146ee4:
  addi r3, r31, 0x1c;
  li r4, 0x16;
  li r5, 1;
  bl btu_start_timer;
  b lbl_80146f10;
lbl_80146ef8:
  lwz r12, 0xc4(r31);
  li r3, 2;
  lbz r4, 9(r31);
  li r5, 0;
  mtctr r12;
  bctrl;
lbl_80146f10:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
