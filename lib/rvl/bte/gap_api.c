#include "gap_api.h"

#include <string.h>

#include "gap_conn.h"

// Symbol: GAP_Init
// PAL: 0x80143460..0x801434c0
MARK_BINARY_BLOB(GAP_Init, 0x80143460, 0x801434c0);
asm UNKNOWN_FUNCTION(GAP_Init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x3ac;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r3, r31, -30144;
  bl memset;
  lis r5, 0x8014;
  lis r3, 0x8014;
  addi r5, r5, 0x41d4;
  addi r4, r31, -30144;
  addi r3, r3, 0x41e0;
  li r0, 5;
  stw r5, 0x20(r4);
  stw r3, 0x24(r4);
  stb r0, 0x28(r4);
  bl gap_conn_init;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
