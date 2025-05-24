#include "btm_main.h"

#include <string.h>

#include "btm_acl.h"
#include "btm_devctl.h"
#include "btm_inq.h"
#include "btm_sco.h"
#include "btm_sec.h"

// Symbol: btm_init
// PAL: 0x8013d5c0..0x8013d61c
MARK_BINARY_BLOB(btm_init, 0x8013d5c0, 0x8013d61c);
asm UNKNOWN_FUNCTION(btm_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x27c4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r3, r31, 0x6278;
  bl memset;
  addi r3, r31, 0x6278;
  li r0, 0;
  stb r0, 0x27c0(r3);
  bl btm_inq_db_init;
  bl btm_acl_init;
  li r3, 2;
  bl btm_sec_init;
  bl btm_sco_init;
  bl btm_dev_init;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
