#include "hidd_conn.h"

#include "bte_logmsg.h"
#include "l2c_api.h"

// Symbol: hidd_conn_initiate
// PAL: 0x80146d9c..0x80146e5c
MARK_BINARY_BLOB(hidd_conn_initiate, 0x80146d9c, 0x80146e5c);
asm UNKNOWN_FUNCTION(hidd_conn_initiate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lis r29, 0x8034;
  addi r29, r29, -29200;
  lbz r0, 0x141(r29);
  cmplwi r0, 4;
  blt lbl_80146ddc;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x4f50;
  bl LogMsg_0;
lbl_80146ddc:
  li r0, 0;
  li r30, 1;
  lis r31, 0x8034;
  sth r0, 0x14(r29);
  addi r4, r31, -29200;
  li r3, 0x11;
  sth r0, 0x16(r29);
  stb r30, 0x11(r29);
  bl L2CA_ConnectReq;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x14(r29);
  bne lbl_80146e38;
  addi r3, r31, -29200;
  lbz r0, 0x141(r3);
  cmplwi r0, 2;
  blt lbl_80146e30;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x4f68;
  bl LogMsg_0;
lbl_80146e30:
  li r3, 0xe;
  b lbl_80146e40;
lbl_80146e38:
  stb r30, 0x10(r29);
  li r3, 0;
lbl_80146e40:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
