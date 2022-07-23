#include "uusb_ppc.h"

#include <string.h>

#include "gki_buffer.h"
#include "gki_ppc.h"

// Extern function references.
// PAL: 0x8014ce4c
extern UNKNOWN_FUNCTION(l2cap_link_chk_pkt_start);
// PAL: 0x8014d01c
extern UNKNOWN_FUNCTION(l2cap_link_chk_pkt_end);
// PAL: 0x80193478
extern UNKNOWN_FUNCTION(IPCCltInit);
// PAL: 0x801a2068
extern UNKNOWN_FUNCTION(OSSwitchFiberEx);
// PAL: 0x801b7778
extern UNKNOWN_FUNCTION(IUSB_OpenLib);
// PAL: 0x801b7870
extern UNKNOWN_FUNCTION(IUSB_CloseLib);
// PAL: 0x801b7a20
extern UNKNOWN_FUNCTION(IUSB_OpenDeviceIds);
// PAL: 0x801b7b64
extern UNKNOWN_FUNCTION(IUSB_CloseDevice);
// PAL: 0x801b7fc4
extern UNKNOWN_FUNCTION(unk_801b7fc4);
// PAL: 0x801b8038
extern UNKNOWN_FUNCTION(unk_801b8038);
// PAL: 0x801b80ac
extern UNKNOWN_FUNCTION(unk_801b80ac);
// PAL: 0x801b86c4
extern UNKNOWN_FUNCTION(IUSB_WriteCtrlMsgAsync);

// Symbol: __ntd_get_allocated_mem_size
// PAL: 0x8013099c..0x801309a8
MARK_BINARY_BLOB(__ntd_get_allocated_mem_size, 0x8013099c, 0x801309a8);
u32 __ntd_get_allocated_mem_size() { return 0x14a78; }

// Symbol: uusb_CloseDeviceCB
// PAL: 0x801309a8..0x80130a3c
MARK_BINARY_BLOB(uusb_CloseDeviceCB, 0x801309a8, 0x80130a3c);
asm UNKNOWN_FUNCTION(uusb_CloseDeviceCB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  addi r31, r4, 0x24e0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r30, 0x24e0(r4);
  stb r30, 0x10(r31);
  stb r30, 0x11(r31);
  stb r30, 0x12(r31);
  stb r30, 0x13(r31);
  stb r30, -0x6640(r13);
  bl IUSB_CloseLib;
  bl GKI_disable;
  li r0, 5;
  stb r30, 0x28(r31);
  stb r0, 0x29(r31);
  stb r30, -0x663f(r13);
  bl GKI_enable;
  lwz r12, 0x20(r31);
  cmpwi r12, 0;
  beq lbl_80130a20;
  extsb r4, r29;
  li r3, 4;
  mtctr r12;
  bctrl;
lbl_80130a20:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: uusb_ReadIntrDataCB
// PAL: 0x80130a3c..0x80130b50
MARK_BINARY_BLOB(uusb_ReadIntrDataCB, 0x80130a3c, 0x80130b50);
asm UNKNOWN_FUNCTION(uusb_ReadIntrDataCB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r5, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x24e0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x29(r31);
  stb r5, 0x2b(r31);
  cmplwi r0, 2;
  beq lbl_80130a94;
  mr r3, r30;
  bl GKI_freebuf;
  lbz r3, 0x1c(r31);
  bl GKI_delete_pool;
  li r0, 0xff;
  stb r0, 0x1c(r31);
  b lbl_80130b34;
lbl_80130a94:
  li r0, 0;
  cmplw r4, r0;
  beq lbl_80130b30;
  cmpwi r3, 0;
  bgt lbl_80130ab4;
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80130b30;
lbl_80130ab4:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80130ad4;
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80130b30;
lbl_80130ad4:
  lhz r0, 4(r30);
  clrlwi r4, r29, 0x10;
  li r6, 0x1000;
  sth r29, 2(r30);
  add r5, r4, r0;
  mr r4, r30;
  addi r0, r5, 8;
  sth r6, 0(r30);
  rlwinm r5, r0, 0, 0, 0x1d;
  addi r5, r5, 4;
  bl memcpy;
  lis r5, 0x8033;
  lis r7, 0x8013;
  addi r5, r5, 0x2540;
  mr r3, r31;
  addi r8, r5, 0x1000;
  addi r7, r7, 0x1648;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  bl OSSwitchFiberEx;
  mr r3, r30;
  bl GKI_freebuf;
lbl_80130b30:
  bl uusb_issue_intr_read;
lbl_80130b34:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: uusb_ReadBulkDataCB
// PAL: 0x80130b50..0x80130cec
MARK_BINARY_BLOB(uusb_ReadBulkDataCB, 0x80130b50, 0x80130cec);
asm UNKNOWN_FUNCTION(uusb_ReadBulkDataCB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8033;
  addi r30, r30, 0x24e0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  lbz r0, 0x29(r30);
  cmplwi r0, 2;
  beq lbl_80130ba0;
  mr r3, r29;
  bl GKI_freebuf;
  lbz r3, 0x1d(r30);
  bl GKI_delete_pool;
  li r0, 0xff;
  stb r0, 0x1d(r30);
  b lbl_80130ccc;
lbl_80130ba0:
  cmpwi r3, 0;
  bgt lbl_80130bb4;
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80130c4c;
lbl_80130bb4:
  sth r3, 2(r4);
  li r3, 3;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r28, r3;
  bne lbl_80130bd8;
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80130c4c;
lbl_80130bd8:
  lhz r5, 2(r29);
  mr r4, r29;
  lhz r0, 4(r29);
  add r5, r5, r0;
  addi r0, r5, 8;
  rlwinm r5, r0, 0, 0, 0x1d;
  addi r5, r5, 4;
  bl memcpy;
  mr r3, r28;
  bl l2cap_link_chk_pkt_start;
  li r0, 0;
  mr r28, r3;
  cmplw r3, r0;
  beq lbl_80130c44;
  bl l2cap_link_chk_pkt_end;
  clrlwi. r0, r3, 0x18;
  beq lbl_80130c44;
  lis r5, 0x8033;
  lis r7, 0x8013;
  addi r5, r5, 0x3540;
  mr r3, r28;
  addi r8, r5, 0x1000;
  addi r7, r7, 0x1648;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  bl OSSwitchFiberEx;
lbl_80130c44:
  mr r3, r29;
  bl GKI_freebuf;
lbl_80130c4c:
  lis r30, 0x8033;
  addi r31, r30, 0x24e0;
lbl_80130c54:
  lbz r3, 0x1d(r31);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r28, r3;
  beq lbl_80130c54;
  li r4, 0x1100;
  addi r0, r3, 0x27;
  sth r4, 0(r3);
  li r4, 0;
  rlwinm r29, r0, 0, 0, 0x1a;
  addi r0, r3, 8;
  sth r4, 2(r3);
  subf r0, r0, r29;
  sth r0, 4(r3);
  bl GKI_get_buf_size;
  clrlwi r3, r3, 0x10;
  lhz r0, 4(r28);
  addi r5, r3, -40;
  lis r7, 0x8013;
  lwz r3, 0x24e0(r30);
  mr r6, r29;
  lbz r4, 0x11(r31);
  mr r8, r28;
  subf r5, r0, r5;
  addi r7, r7, 0xb50;
  bl unk_801b8038;
  cmpwi r3, 0;
  beq lbl_80130ccc;
  mr r3, r28;
  bl GKI_freebuf;
lbl_80130ccc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: uusb_issue_intr_read
// PAL: 0x80130cec..0x80130db8
MARK_BINARY_BLOB(uusb_issue_intr_read, 0x80130cec, 0x80130db8);
asm UNKNOWN_FUNCTION(uusb_issue_intr_read) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8033;
  addi r31, r30, 0x24e0;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
lbl_80130d10:
  lbz r3, 0x1c(r31);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80130d10;
  li r4, 0x1000;
  addi r0, r3, 0x27;
  sth r4, 0(r3);
  li r4, 0;
  rlwinm r28, r0, 0, 0, 0x1a;
  addi r0, r3, 8;
  sth r4, 2(r3);
  subf r0, r0, r28;
  sth r0, 4(r3);
  bl GKI_get_buf_size;
  clrlwi r3, r3, 0x10;
  lhz r0, 4(r29);
  addi r5, r3, -40;
  lis r7, 0x8013;
  lwz r3, 0x24e0(r30);
  mr r6, r28;
  lbz r4, 0x12(r31);
  mr r8, r29;
  subf r5, r0, r5;
  addi r7, r7, 0xa3c;
  bl unk_801b7fc4;
  cmpwi r3, 0;
  beq lbl_80130d88;
  mr r3, r29;
  bl GKI_freebuf;
lbl_80130d88:
  lis r3, 0x8033;
  li r0, 1;
  addi r3, r3, 0x24e0;
  stb r0, 0x2b(r3);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: uusb_WriteCtrlDataCB
// PAL: 0x80130db8..0x80130ea4
MARK_BINARY_BLOB(uusb_WriteCtrlDataCB, 0x80130db8, 0x80130ea4);
asm UNKNOWN_FUNCTION(uusb_WriteCtrlDataCB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  beq lbl_80130dfc;
  mr r3, r4;
  bl GKI_freebuf;
  bl GKI_disable;
  lis r4, 0x8033;
  addi r4, r4, 0x24e0;
  lbz r3, 0x48(r4);
  addi r0, r3, -1;
  stb r0, 0x48(r4);
  bl GKI_enable;
lbl_80130dfc:
  lis r30, 0x8033;
  addi r31, r30, 0x24e0;
  lbz r0, 0x48(r31);
  cmplwi r0, 5;
  bge lbl_80130e88;
  lhz r0, 0x44(r31);
  cmpwi r0, 0;
  beq lbl_80130e88;
  addi r3, r31, 0x3c;
  bl GKI_dequeue;
  stw r3, 8(r1);
  mr r29, r3;
  lis r10, 0x8013;
  li r4, 0x20;
  lhz r0, 4(r3);
  addi r10, r10, 0xdb8;
  lwz r3, 0x24e0(r30);
  li r5, 0;
  add r6, r29, r0;
  lhz r8, 2(r29);
  addi r9, r6, 8;
  li r7, 0;
  li r6, 0;
  bl IUSB_WriteCtrlMsgAsync;
  cmpwi r3, 0;
  bge lbl_80130e74;
  mr r4, r29;
  addi r3, r31, 0x3c;
  bl GKI_enqueue_head;
  b lbl_80130e88;
lbl_80130e74:
  bl GKI_disable;
  lbz r3, 0x48(r31);
  addi r0, r3, 1;
  stb r0, 0x48(r31);
  bl GKI_enable;
lbl_80130e88:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: uusb_WriteBulkDataCB
// PAL: 0x80130ea4..0x80130f84
MARK_BINARY_BLOB(uusb_WriteBulkDataCB, 0x80130ea4, 0x80130f84);
asm UNKNOWN_FUNCTION(uusb_WriteBulkDataCB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  beq lbl_80130ee8;
  mr r3, r4;
  bl GKI_freebuf;
  bl GKI_disable;
  lis r4, 0x8033;
  addi r4, r4, 0x24e0;
  lbz r3, 0x38(r4);
  addi r0, r3, -1;
  stb r0, 0x38(r4);
  bl GKI_enable;
lbl_80130ee8:
  lis r30, 0x8033;
  addi r31, r30, 0x24e0;
  lbz r0, 0x38(r31);
  cmplwi r0, 5;
  bge lbl_80130f68;
  lhz r0, 0x34(r31);
  cmpwi r0, 0;
  beq lbl_80130f68;
  addi r3, r31, 0x2c;
  bl GKI_dequeue;
  lhz r0, 4(r3);
  mr r29, r3;
  lis r7, 0x8013;
  lwz r3, 0x24e0(r30);
  add r6, r29, r0;
  lbz r4, 0x10(r31);
  lhz r5, 2(r29);
  mr r8, r29;
  addi r7, r7, 0xea4;
  addi r6, r6, 8;
  bl unk_801b80ac;
  cmpwi r3, 0;
  bge lbl_80130f54;
  mr r4, r29;
  addi r3, r31, 0x2c;
  bl GKI_enqueue_head;
  b lbl_80130f68;
lbl_80130f54:
  bl GKI_disable;
  lbz r3, 0x38(r31);
  addi r0, r3, 1;
  stb r0, 0x38(r31);
  bl GKI_enable;
lbl_80130f68:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: UUSB_Register
// PAL: 0x80130f84..0x8013118c
MARK_BINARY_BLOB(UUSB_Register, 0x80130f84, 0x8013118c);
asm UNKNOWN_FUNCTION(UUSB_Register) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x4c;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  lis r30, 0x8033;
  addi r3, r30, 0x24e0;
  bl memset;
  bl GKI_disable;
  addi r30, r30, 0x24e0;
  li r0, 5;
  stb r0, 0x29(r30);
  bl GKI_enable;
  lbz r0, -0x663f(r13);
  cmpwi r0, 0;
  bne lbl_80130fe0;
  li r3, 0;
  li r0, 1;
  stb r3, 0x28(r30);
  stb r0, -0x663f(r13);
lbl_80130fe0:
  bl IPCCltInit;
  cmpwi r3, 0;
  bne lbl_80131174;
  bl IUSB_OpenLib;
  cmpwi r3, 0;
  bne lbl_80131174;
  lbz r0, -0x6634(r13);
  lis r4, 0x8033;
  addi r4, r4, 0x24e0;
  cmplwi r0, 1;
  stw r31, 0x24(r4);
  bne lbl_80131024;
  lwz r3, -0x6630(r13);
  lwz r0, -0x662c(r13);
  stw r3, 0x14(r4);
  stw r0, 0x18(r4);
  b lbl_80131034;
lbl_80131024:
  li r3, 0x57e;
  li r0, 0x305;
  stw r3, 0x14(r4);
  stw r0, 0x18(r4);
lbl_80131034:
  lwz r0, -0x6638(r13);
  lis r6, 0x8033;
  addi r6, r6, 0x24e0;
  li r3, 0;
  cmplwi r0, 1;
  stb r3, 0x10(r6);
  lwz r5, 0x18(r6);
  stb r3, 0x11(r6);
  lwz r0, 0x14(r6);
  stb r3, 0x12(r6);
  stb r3, 0x13(r6);
  bne lbl_801310a8;
  lwz r3, -0x663c(r13);
  cmpwi r3, 0;
  bne lbl_80131088;
  clrlwi r4, r0, 0x10;
  clrlwi r5, r5, 0x10;
  addi r3, r13, -29672;
  bl IUSB_OpenDeviceIds;
  mr r30, r3;
  b lbl_801310bc;
lbl_80131088:
  cmplwi r3, 1;
  bne lbl_801310bc;
  clrlwi r4, r0, 0x10;
  clrlwi r5, r5, 0x10;
  addi r3, r13, -29668;
  bl IUSB_OpenDeviceIds;
  mr r30, r3;
  b lbl_801310bc;
lbl_801310a8:
  clrlwi r4, r0, 0x10;
  clrlwi r5, r5, 0x10;
  addi r3, r13, -29668;
  bl IUSB_OpenDeviceIds;
  mr r30, r3;
lbl_801310bc:
  cmpwi r30, 0;
  blt lbl_801310c8;
  stw r30, -0x73ec(r13);
lbl_801310c8:
  cmpwi r30, 0;
  blt lbl_80131174;
  lis r30, 0x8033;
  li r3, 2;
  addi r30, r30, 0x24e0;
  li r4, 0x82;
  li r0, 0x81;
  li r31, 0;
  stb r3, 0x10(r30);
  addi r3, r30, 0x2c;
  stb r4, 0x11(r30);
  stb r0, 0x12(r30);
  stb r31, 0x13(r30);
  bl GKI_init_q;
  stb r31, 0x38(r30);
  addi r3, r30, 0x3c;
  bl GKI_init_q;
  stb r31, 0x48(r30);
  li r3, 0x294;
  li r4, 0x2d;
  li r5, 1;
  li r6, 0;
  bl GKI_create_pool;
  stb r3, 0x1c(r30);
  li r3, 0x708;
  li r4, 0x1e;
  li r5, 1;
  li r6, 0;
  bl GKI_create_pool;
  lbz r0, 0x1c(r30);
  stb r3, 0x1d(r30);
  cmplwi r0, 0xff;
  beq lbl_80131174;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 0xff;
  bne lbl_8013115c;
  b lbl_80131174;
lbl_8013115c:
  bl GKI_disable;
  li r0, 4;
  stb r0, 0x29(r30);
  bl GKI_enable;
  li r0, 1;
  stw r0, -0x73f0(r13);
lbl_80131174:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: UUSB_Open
// PAL: 0x8013118c..0x80131294
MARK_BINARY_BLOB(UUSB_Open, 0x8013118c, 0x80131294);
asm UNKNOWN_FUNCTION(UUSB_Open) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8033;
  addi r31, r30, 0x24e0;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r4;
  lbz r0, 0x29(r31);
  cmplwi r0, 4;
  bne lbl_80131274;
  lbz r0, 0x1c(r31);
  cmplwi r0, 0xff;
  beq lbl_80131274;
  lbz r0, 0x1d(r31);
  cmplwi r0, 0xff;
  bne lbl_801311dc;
  b lbl_80131274;
lbl_801311dc:
  bl GKI_disable;
  li r0, 2;
  stw r28, 0x20(r31);
  stb r0, 0x29(r31);
  bl GKI_enable;
  bl uusb_issue_intr_read;
lbl_801311f4:
  lbz r3, 0x1d(r31);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r28, r3;
  beq lbl_801311f4;
  li r4, 0x1100;
  addi r0, r3, 0x27;
  sth r4, 0(r3);
  li r4, 0;
  rlwinm r29, r0, 0, 0, 0x1a;
  addi r0, r3, 8;
  sth r4, 2(r3);
  subf r0, r0, r29;
  sth r0, 4(r3);
  bl GKI_get_buf_size;
  clrlwi r3, r3, 0x10;
  lhz r0, 4(r28);
  addi r5, r3, -40;
  lis r7, 0x8013;
  lwz r3, 0x24e0(r30);
  mr r6, r29;
  lbz r4, 0x11(r31);
  mr r8, r28;
  subf r5, r0, r5;
  addi r7, r7, 0xb50;
  bl unk_801b8038;
  cmpwi r3, 0;
  beq lbl_8013126c;
  mr r3, r28;
  bl GKI_freebuf;
lbl_8013126c:
  li r0, 0;
  stw r0, -0x73f0(r13);
lbl_80131274:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: UUSB_Read
// PAL: 0x80131294..0x8013129c
MARK_BINARY_BLOB(UUSB_Read, 0x80131294, 0x8013129c);
asm UNKNOWN_FUNCTION(UUSB_Read) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: UUSB_Write
// PAL: 0x8013129c..0x801314b0
MARK_BINARY_BLOB(UUSB_Write, 0x8013129c, 0x801314b0);
asm UNKNOWN_FUNCTION(UUSB_Write) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r29, 0x8033;
  mr r25, r4;
  addi r30, r29, 0x24e0;
  mr r31, r5;
  lbz r0, 0x29(r30);
  li r28, 0;
  cmplwi r0, 2;
  beq lbl_801312d8;
  li r3, 0;
  b lbl_80131498;
lbl_801312d8:
  cmpwi r3, 2;
  beq lbl_801313cc;
  bge lbl_80131494;
  cmpwi r3, 0;
  beq lbl_801312f4;
  b lbl_80131494;
  b lbl_80131494;
lbl_801312f4:
  lbz r3, 0x1c(r30);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r26, r3;
  bne lbl_80131310;
  li r3, 0;
  b lbl_80131498;
lbl_80131310:
  addi r0, r3, 0x27;
  sth r31, 2(r3);
  rlwinm r27, r0, 0, 0, 0x1a;
  mr r4, r25;
  addi r0, r3, 8;
  mr r5, r31;
  subf r0, r0, r27;
  sth r0, 4(r3);
  mr r3, r27;
  bl memcpy;
  lbz r0, 0x48(r30);
  cmplwi r0, 5;
  bge lbl_80131384;
  lhz r0, 0x44(r30);
  cmpwi r0, 0;
  bne lbl_80131384;
  stw r26, 8(r1);
  lis r10, 0x8013;
  mr r8, r31;
  mr r9, r27;
  lwz r3, 0x24e0(r29);
  addi r10, r10, 0xdb8;
  li r4, 0x20;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl IUSB_WriteCtrlMsgAsync;
  mr r28, r3;
  b lbl_801313a0;
lbl_80131384:
  lis r3, 0x8033;
  mr r4, r26;
  addi r3, r3, 0x24e0;
  addi r3, r3, 0x3c;
  bl GKI_enqueue;
  li r3, 0;
  b lbl_80131498;
lbl_801313a0:
  cmpwi r3, 0;
  beq lbl_801313b4;
  mr r3, r26;
  bl GKI_freebuf;
  b lbl_80131494;
lbl_801313b4:
  bl GKI_disable;
  lbz r3, 0x48(r30);
  addi r0, r3, 1;
  stb r0, 0x48(r30);
  bl GKI_enable;
  b lbl_80131494;
lbl_801313cc:
  lbz r3, 0x1d(r30);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_801313e8;
  li r3, 0;
  b lbl_80131498;
lbl_801313e8:
  addi r0, r3, 0x27;
  sth r31, 2(r3);
  rlwinm r28, r0, 0, 0, 0x1a;
  mr r4, r25;
  addi r0, r3, 8;
  mr r5, r31;
  subf r0, r0, r28;
  sth r0, 4(r3);
  mr r3, r28;
  bl memcpy;
  lbz r0, 0x38(r30);
  cmplwi r0, 5;
  bge lbl_80131450;
  lhz r0, 0x34(r30);
  cmpwi r0, 0;
  bne lbl_80131450;
  lis r7, 0x8013;
  lwz r3, 0x24e0(r29);
  lbz r4, 0x10(r30);
  mr r5, r31;
  mr r6, r28;
  mr r8, r27;
  addi r7, r7, 0xea4;
  bl unk_801b80ac;
  mr r28, r3;
  b lbl_8013146c;
lbl_80131450:
  lis r3, 0x8033;
  mr r4, r27;
  addi r3, r3, 0x24e0;
  addi r3, r3, 0x2c;
  bl GKI_enqueue;
  li r3, 0;
  b lbl_80131498;
lbl_8013146c:
  cmpwi r3, 0;
  beq lbl_80131480;
  mr r3, r27;
  bl GKI_freebuf;
  b lbl_80131494;
lbl_80131480:
  bl GKI_disable;
  lbz r3, 0x38(r30);
  addi r0, r3, 1;
  stb r0, 0x38(r30);
  bl GKI_enable;
lbl_80131494:
  clrlwi r3, r28, 0x10;
lbl_80131498:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: UUSB_Close
// PAL: 0x801314b0..0x8013155c
MARK_BINARY_BLOB(UUSB_Close, 0x801314b0, 0x8013155c);
asm UNKNOWN_FUNCTION(UUSB_Close) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl GKI_disable;
  lis r3, 0x8033;
  li r0, 0;
  addi r31, r3, 0x24e0;
  stb r0, 0x29(r31);
  bl GKI_enable;
  lhz r0, 0x34(r31);
  cmpwi r0, 0;
  beq lbl_80131500;
  b lbl_801314f4;
lbl_801314e8:
  addi r3, r31, 0x2c;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_801314f4:
  lhz r0, 0x34(r31);
  cmpwi r0, 0;
  bne lbl_801314e8;
lbl_80131500:
  lis r3, 0x8033;
  addi r31, r3, 0x24e0;
  lhz r0, 0x44(r31);
  cmpwi r0, 0;
  beq lbl_80131530;
  b lbl_80131524;
lbl_80131518:
  addi r3, r31, 0x3c;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_80131524:
  lhz r0, 0x44(r31);
  cmpwi r0, 0;
  bne lbl_80131518;
lbl_80131530:
  lis r3, 0x8033;
  lis r4, 0x8013;
  lwz r3, 0x24e0(r3);
  addi r4, r4, 0x9a8;
  li r5, 0;
  bl IUSB_CloseDevice;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: UUSB_Unregister
// PAL: 0x8013155c..0x801315a0
MARK_BINARY_BLOB(UUSB_Unregister, 0x8013155c, 0x801315a0);
asm UNKNOWN_FUNCTION(UUSB_Unregister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl IUSB_CloseLib;
  bl GKI_disable;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x24e0;
  li r4, 5;
  stb r4, 0x29(r3);
  stb r0, 0x28(r3);
  stb r0, -0x663f(r13);
  bl GKI_enable;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
