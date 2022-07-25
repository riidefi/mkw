#include "utl.h"

// Extern function references.
// PAL: 0x8012ee3c
extern UNKNOWN_FUNCTION(GKI_freebuf);

// Symbol: utl_freebuf
// PAL: 0x801324dc..0x80132520
MARK_BINARY_BLOB(utl_freebuf, 0x801324dc, 0x80132520);
asm UNKNOWN_FUNCTION(utl_freebuf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_8013250c;
  mr r3, r0;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0(r31);
lbl_8013250c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
