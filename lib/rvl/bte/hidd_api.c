#include "hidd_api.h"

#include <string.h>

// Symbol: HID_DevInit
// PAL: 0x80146d34..0x80146d9c
MARK_BINARY_BLOB(HID_DevInit, 0x80146d34, 0x80146d9c);
asm UNKNOWN_FUNCTION(HID_DevInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x144;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r3, r31, -29200;
  bl memset;
  lis r3, 0x8014;
  addi r5, r31, -29200;
  li r6, 1;
  li r4, 0x40;
  addi r3, r3, 0x6e5c;
  li r0, 0;
  stb r6, 0xca(r5);
  sth r4, 0xcc(r5);
  stb r6, 0x106(r5);
  sth r4, 0x108(r5);
  stw r3, 0x2c(r5);
  stb r0, 0x141(r5);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
