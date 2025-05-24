#include "bte_hcisu.h"

#include "gki_buffer.h"

// Symbol: bte_hcisu_send
// PAL: 0x801315a0..0x801315c0
MARK_BINARY_BLOB(bte_hcisu_send, 0x801315a0, 0x801315c0);
asm UNKNOWN_FUNCTION(bte_hcisu_send) {
  // clang-format off
  nofralloc;
  sth r4, 0(r3);
  lwz r4, -0x6628(r13);
  cmpwi r4, 0;
  beq lbl_801315bc;
  lwz r12, 0xc(r4);
  mtctr r12;
  bctr;
lbl_801315bc:
  b GKI_freebuf;
  // clang-format on
}

// Symbol: bte_hcisu_task
// PAL: 0x801315c0..0x80131624
MARK_BINARY_BLOB(bte_hcisu_task, 0x801315c0, 0x80131624);
asm UNKNOWN_FUNCTION(bte_hcisu_task) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r3, -0x6628(r13);
  cmpwi r3, 0;
  beq lbl_80131614;
  lwz r12, 0(r3);
  cmpwi r12, 0;
  beq lbl_801315f8;
  li r3, 2;
  li r4, 1;
  li r5, 0x800;
  mtctr r12;
  bctrl;
lbl_801315f8:
  lwz r3, -0x6628(r13);
  lwz r12, 4(r3);
  cmpwi r12, 0;
  beq lbl_80131614;
  lwz r3, -0x6624(r13);
  mtctr r12;
  bctrl;
lbl_80131614:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bte_hcisu_close
// PAL: 0x80131624..0x80131648
MARK_BINARY_BLOB(bte_hcisu_close, 0x80131624, 0x80131648);
asm UNKNOWN_FUNCTION(bte_hcisu_close) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6628(r13);
  cmpwi r3, 0;
  beqlr;
  lwz r12, 8(r3);
  cmpwi r12, 0;
  beqlr;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: bta_ci_hci_msg_handler
// PAL: 0x80131648..0x80131658
MARK_BINARY_BLOB(bta_ci_hci_msg_handler, 0x80131648, 0x80131658);
asm UNKNOWN_FUNCTION(bta_ci_hci_msg_handler) {
  // clang-format off
  nofralloc;
  mr r5, r3;
  li r3, 2;
  li r4, 0;
  b GKI_send_msg;
  // clang-format on
}
