#include "port_api.h"

#include <string.h>

#include "rfc_l2cap_if.h"

// Symbol: RFCOMM_Init
// PAL: 0x80150188..0x801501d8
MARK_BINARY_BLOB(RFCOMM_Init, 0x80150188, 0x801501d8);
asm UNKNOWN_FUNCTION(RFCOMM_Init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x418;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r3, r31, -25816;
  bl memset;
  addi r3, r31, -25816;
  li r4, 1;
  li r0, 5;
  stb r4, 0x65(r3);
  stb r0, 0x414(r3);
  bl rfcomm_l2cap_if_init;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
