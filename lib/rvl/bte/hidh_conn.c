#include "hidh_conn.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_acl.h"
#include "btm_sec.h"
#include "l2c_api.h"

// Symbol: hidh_conn_reg
// PAL: 0x80148020..0x80148178
MARK_BINARY_BLOB(hidh_conn_reg, 0x80148020, 0x80148178);
asm UNKNOWN_FUNCTION(hidh_conn_reg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 1;
  li r6, 1;
  stw r0, 0x14(r1);
  addi r0, r3, -1;
  li r5, 0x280;
  li r3, 0x11;
  stw r31, 0xc(r1);
  lis r31, 0x8025;
  addi r4, r31, -13792;
  stw r30, 8(r1);
  lis r30, 0x8034;
  addi r30, r30, -28872;
  stb r6, 0x346(r30);
  sth r5, 0x348(r30);
  stb r6, 0x364(r30);
  sth r0, 0x366(r30);
  bl L2CA_Register;
  clrlwi. r0, r3, 0x18;
  bne lbl_80148098;
  lbz r0, 0x401(r30);
  cmplwi r0, 1;
  blt lbl_80148090;
  lis r4, 0x8028;
  lis r3, 0x1e;
  addi r4, r4, 0x50b8;
  bl LogMsg_0;
lbl_80148090:
  li r3, 0xe;
  b lbl_80148160;
lbl_80148098:
  addi r4, r31, -13792;
  li r3, 0x13;
  bl L2CA_Register;
  clrlwi. r0, r3, 0x18;
  bne lbl_801480d8;
  li r3, 0x11;
  bl L2CA_Deregister;
  lbz r0, 0x401(r30);
  cmplwi r0, 1;
  blt lbl_801480d0;
  lis r4, 0x8028;
  lis r3, 0x1e;
  addi r4, r4, 0x50d8;
  bl LogMsg_0;
lbl_801480d0:
  li r3, 0xe;
  b lbl_80148160;
lbl_801480d8:
  li r0, 0;
  li r3, 0;
  stb r0, 0(r30);
  stb r0, 0x10(r30);
  stb r0, 0x34(r30);
  stb r0, 0x44(r30);
  stb r0, 0x68(r30);
  stb r0, 0x78(r30);
  stb r0, 0x9c(r30);
  stb r0, 0xac(r30);
  stb r0, 0xd0(r30);
  stb r0, 0xe0(r30);
  stb r0, 0x104(r30);
  stb r0, 0x114(r30);
  stb r0, 0x138(r30);
  stb r0, 0x148(r30);
  stb r0, 0x16c(r30);
  stb r0, 0x17c(r30);
  stb r0, 0x1a0(r30);
  stb r0, 0x1b0(r30);
  stb r0, 0x1d4(r30);
  stb r0, 0x1e4(r30);
  stb r0, 0x208(r30);
  stb r0, 0x218(r30);
  stb r0, 0x23c(r30);
  stb r0, 0x24c(r30);
  stb r0, 0x270(r30);
  stb r0, 0x280(r30);
  stb r0, 0x2a4(r30);
  stb r0, 0x2b4(r30);
  stb r0, 0x2d8(r30);
  stb r0, 0x2e8(r30);
  stb r0, 0x30c(r30);
  stb r0, 0x31c(r30);
lbl_80148160:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hidh_conn_disconnect
// PAL: 0x80148178..0x8014821c
MARK_BINARY_BLOB(hidh_conn_disconnect, 0x80148178, 0x8014821c);
asm UNKNOWN_FUNCTION(hidh_conn_disconnect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -28872;
  mulli r3, r3, 0x34;
  stw r31, 0xc(r1);
  lbz r0, 0x401(r4);
  add r31, r4, r3;
  cmplwi r0, 4;
  blt lbl_801481b8;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x50fc;
  bl LogMsg_0;
lbl_801481b8:
  lhz r0, 0x14(r31);
  cmpwi r0, 0;
  bne lbl_801481d0;
  lhz r0, 0x16(r31);
  cmpwi r0, 0;
  beq lbl_801481fc;
lbl_801481d0:
  li r0, 5;
  stb r0, 0x10(r31);
  lhz r3, 0x16(r31);
  cmpwi r3, 0;
  beq lbl_801481e8;
  bl L2CA_DisconnectReq;
lbl_801481e8:
  lhz r3, 0x14(r31);
  cmpwi r3, 0;
  beq lbl_80148204;
  bl L2CA_DisconnectReq;
  b lbl_80148204;
lbl_801481fc:
  li r0, 0;
  stb r0, 0x10(r31);
lbl_80148204:
  lwz r31, 0xc(r1);
  li r3, 0;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hidh_sec_check_complete_term
// PAL: 0x8014821c..0x8014834c
MARK_BINARY_BLOB(hidh_sec_check_complete_term, 0x8014821c, 0x8014834c);
asm UNKNOWN_FUNCTION(hidh_sec_check_complete_term) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x4ec5;
  cmpwi r5, 0;
  stw r0, 0x14(r1);
  addi r3, r3, -5041;
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, -28872;
  subf r0, r31, r4;
  stw r30, 8(r1);
  mulhw r0, r3, r0;
  mr r30, r4;
  srawi r0, r0, 4;
  srwi r3, r0, 0x1f;
  add r0, r0, r3;
  clrlwi r6, r0, 0x18;
  bne lbl_801482a8;
  lbz r0, 0x10(r4);
  cmplwi r0, 6;
  bne lbl_801482a8;
  li r3, 0;
  li r0, 2;
  sth r3, 0x1a(r4);
  addi r3, r4, 1;
  lhz r5, 0x14(r30);
  li r6, 0;
  stb r0, 0x10(r4);
  li r7, 0;
  lbz r4, 0x12(r4);
  bl L2CA_ConnectRsp;
  lhz r3, 0x14(r30);
  addi r4, r31, 0x344;
  bl L2CA_ConfigReq;
  b lbl_80148334;
lbl_801482a8:
  cmpwi r5, 0;
  beq lbl_80148334;
  li r0, 0xf;
  lis r3, 0x8034;
  sth r0, 0x1a(r4);
  addi r3, r3, -28872;
  mulli r4, r6, 0x34;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  add r31, r3, r4;
  blt lbl_801482e8;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x50fc;
  bl LogMsg_0;
lbl_801482e8:
  lhz r0, 0x14(r31);
  cmpwi r0, 0;
  bne lbl_80148300;
  lhz r0, 0x16(r31);
  cmpwi r0, 0;
  beq lbl_8014832c;
lbl_80148300:
  li r0, 5;
  stb r0, 0x10(r31);
  lhz r3, 0x16(r31);
  cmpwi r3, 0;
  beq lbl_80148318;
  bl L2CA_DisconnectReq;
lbl_80148318:
  lhz r3, 0x14(r31);
  cmpwi r3, 0;
  beq lbl_80148334;
  bl L2CA_DisconnectReq;
  b lbl_80148334;
lbl_8014832c:
  li r0, 0;
  stb r0, 0x10(r31);
lbl_80148334:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_connect_ind
// PAL: 0x8014834c..0x801485a4
MARK_BINARY_BLOB(hidh_l2cif_connect_ind, 0x8014834c, 0x801485a4);
asm UNKNOWN_FUNCTION(hidh_l2cif_connect_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r7, 0x8034;
  lis r31, 0x8028;
  addi r7, r7, -28872;
  mr r26, r3;
  lbz r0, 0x401(r7);
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  cmplwi r0, 4;
  addi r31, r31, 0x50b8;
  li r25, 1;
  blt lbl_801483a4;
  lis r3, 0x1e;
  mr r6, r27;
  addi r4, r31, 0x58;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_801483a4:
  lis r30, 0x8034;
  li r24, 0;
  addi r30, r30, -28872;
lbl_801483b0:
  lbz r0, 0(r30);
  cmpwi r0, 0;
  beq lbl_801483d4;
  mr r3, r26;
  addi r4, r30, 1;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_801483e4;
lbl_801483d4:
  addi r24, r24, 1;
  addi r30, r30, 0x34;
  cmpwi r24, 0x10;
  blt lbl_801483b0;
lbl_801483e4:
  cmpwi r24, 0x10;
  bne lbl_80148408;
  mr r3, r26;
  mr r4, r29;
  mr r5, r27;
  li r6, 3;
  li r7, 0;
  bl L2CA_ConnectRsp;
  b lbl_8014858c;
lbl_80148408:
  mulli r0, r24, 0x34;
  lis r3, 0x8034;
  cmplwi r28, 0x13;
  addi r3, r3, -28872;
  add r30, r3, r0;
  bne lbl_80148484;
  lhz r0, 0x14(r30);
  cmpwi r0, 0;
  bne lbl_8014844c;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_80148448;
  lis r3, 0x1e;
  addi r4, r31, 0x8c;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80148448:
  li r25, 0;
lbl_8014844c:
  lbz r5, 0x10(r30);
  cmplwi r5, 2;
  beq lbl_801484b0;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_8014847c;
  lis r3, 0x1e;
  addi r4, r31, 0xc0;
  addi r3, r3, 1;
  bl LogMsg_1;
lbl_8014847c:
  li r25, 0;
  b lbl_801484b0;
lbl_80148484:
  lbz r5, 0x10(r30);
  cmpwi r5, 0;
  beq lbl_801484b0;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_801484ac;
  lis r3, 0x1e;
  addi r4, r31, 0xf0;
  addi r3, r3, 1;
  bl LogMsg_1;
lbl_801484ac:
  li r25, 0;
lbl_801484b0:
  cmpwi r25, 0;
  bne lbl_801484d4;
  mr r3, r26;
  mr r4, r29;
  mr r5, r27;
  li r6, 4;
  li r7, 0;
  bl L2CA_ConnectRsp;
  b lbl_8014858c;
lbl_801484d4:
  cmplwi r28, 0x11;
  bne lbl_80148530;
  li r0, 0;
  lis r8, 0x8015;
  stb r0, 0x11(r30);
  li r7, 0x100;
  li r0, 6;
  mr r9, r30;
  sth r27, 0x14(r30);
  addi r3, r30, 1;
  addi r8, r8, -32228;
  li r4, 0x11;
  stb r29, 0x12(r30);
  li r5, 0;
  li r6, 6;
  sth r7, 0x1a(r30);
  stb r0, 0x10(r30);
  lhz r0, 8(r30);
  rlwinm r0, r0, 0x11, 0x1f, 0x1f;
  neg r7, r0;
  addi r7, r7, 2;
  bl btm_sec_mx_access_request;
  b lbl_8014858c;
lbl_80148530:
  li r0, 3;
  mr r3, r26;
  stb r0, 0x10(r30);
  mr r4, r29;
  mr r5, r27;
  li r6, 0;
  sth r27, 0x16(r30);
  li r7, 0;
  bl L2CA_ConnectRsp;
  lis r26, 0x8034;
  mr r3, r27;
  addi r26, r26, -28872;
  addi r4, r26, 0x344;
  bl L2CA_ConfigReq;
  lbz r0, 0x401(r26);
  cmplwi r0, 4;
  blt lbl_8014858c;
  lis r3, 0x1e;
  mr r5, r28;
  mr r6, r27;
  addi r4, r31, 0x120;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_8014858c:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: hidh_proc_repage_timeout
// PAL: 0x801485a4..0x801486f0
MARK_BINARY_BLOB(hidh_proc_repage_timeout, 0x801485a4, 0x801486f0);
asm UNKNOWN_FUNCTION(hidh_proc_repage_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lis r29, 0x8034;
  addi r29, r29, -28872;
  stw r28, 0x10(r1);
  lwz r0, 0x10(r3);
  clrlwi r0, r0, 0x18;
  mulli r0, r0, 0x34;
  add r28, r29, r0;
  lbz r0, 0x10(r28);
  cmpwi r0, 0;
  bne lbl_80148688;
  li r5, 0;
  li r0, 0x100;
  sth r5, 0x14(r28);
  li r30, 1;
  addi r4, r28, 1;
  li r3, 0x11;
  sth r5, 0x16(r28);
  sth r0, 0x1a(r28);
  stb r30, 0x11(r28);
  bl L2CA_ConnectReq;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x14(r28);
  bne lbl_80148684;
  lbz r0, 0x401(r29);
  cmplwi r0, 2;
  blt lbl_8014863c;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x521c;
  bl LogMsg_0;
lbl_8014863c:
  lis r5, 0x8034;
  lis r3, 0x4ec5;
  addi r5, r5, -28872;
  li r4, 1;
  subf r0, r5, r28;
  addi r7, r3, -5041;
  mulhw r0, r7, r0;
  lwz r12, 0x340(r5);
  li r5, 0xe;
  li r6, 0;
  srawi r0, r0, 4;
  srwi r3, r0, 0x1f;
  add r0, r0, r3;
  mulhwu r0, r7, r0;
  rlwinm r3, r0, 0x1c, 0x18, 0x1f;
  mtctr r12;
  bctrl;
  b lbl_80148688;
lbl_80148684:
  stb r30, 0x10(r28);
lbl_80148688:
  lwz r0, 0x10(r31);
  lis r7, 0x8034;
  addi r7, r7, -28872;
  li r4, 2;
  mulli r0, r0, 0x34;
  li r6, 0;
  add r5, r7, r0;
  lbz r3, 0xc(r5);
  addi r0, r3, 1;
  stb r0, 0xc(r5);
  lwz r3, 0x10(r31);
  lwz r12, 0x340(r7);
  mulli r0, r3, 0x34;
  clrlwi r3, r3, 0x18;
  add r5, r7, r0;
  lbz r5, 0xc(r5);
  mtctr r12;
  bctrl;
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

// Symbol: hidh_sec_check_complete_orig
// PAL: 0x801486f0..0x80148904
MARK_BINARY_BLOB(hidh_sec_check_complete_orig, 0x801486f0, 0x80148904);
asm UNKNOWN_FUNCTION(hidh_sec_check_complete_orig) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r6, 0x8034;
  lis r3, 0x4ec5;
  addi r6, r6, -28872;
  lis r31, 0x8028;
  subf r0, r6, r4;
  addi r3, r3, -5041;
  mulhw r0, r3, r0;
  cmpwi r5, 0;
  mr r28, r4;
  mr r29, r5;
  addi r31, r31, 0x50b8;
  srawi r0, r0, 4;
  srwi r3, r0, 0x1f;
  add r0, r0, r3;
  clrlwi r30, r0, 0x18;
  bne lbl_80148858;
  lbz r0, 0x10(r4);
  cmplwi r0, 6;
  bne lbl_80148858;
  lbz r0, 0x401(r6);
  cmplwi r0, 4;
  blt lbl_8014876c;
  lis r3, 0x1e;
  addi r4, r31, 0x180;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_8014876c:
  mulli r0, r30, 0x34;
  lis r27, 0x8034;
  li r3, 0;
  addi r27, r27, -28872;
  sth r3, 0x1a(r28);
  add r26, r27, r0;
  addi r4, r26, 1;
  li r3, 0x13;
  bl L2CA_ConnectReq;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x16(r28);
  bne lbl_80148850;
  lbz r0, 0x401(r27);
  cmplwi r0, 2;
  blt lbl_801487b8;
  lis r3, 0x1e;
  addi r4, r31, 0x1a0;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_801487b8:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  blt lbl_801487dc;
  lis r3, 0x1e;
  addi r4, r31, 0x44;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_801487dc:
  lhz r0, 0x14(r26);
  cmpwi r0, 0;
  bne lbl_801487f4;
  lhz r0, 0x16(r26);
  cmpwi r0, 0;
  beq lbl_80148820;
lbl_801487f4:
  li r0, 5;
  stb r0, 0x10(r26);
  lhz r3, 0x16(r26);
  cmpwi r3, 0;
  beq lbl_8014880c;
  bl L2CA_DisconnectReq;
lbl_8014880c:
  lhz r3, 0x14(r26);
  cmpwi r3, 0;
  beq lbl_80148828;
  bl L2CA_DisconnectReq;
  b lbl_80148828;
lbl_80148820:
  li r0, 0;
  stb r0, 0x10(r26);
lbl_80148828:
  lis r5, 0x8034;
  mr r3, r30;
  addi r5, r5, -28872;
  li r4, 1;
  lwz r12, 0x340(r5);
  li r5, 0x200;
  li r6, 0;
  mtctr r12;
  bctrl;
  b lbl_801488ec;
lbl_80148850:
  li r0, 2;
  stb r0, 0x10(r28);
lbl_80148858:
  cmpwi r29, 0;
  beq lbl_801488ec;
  lbz r0, 0x10(r28);
  cmplwi r0, 6;
  bne lbl_801488ec;
  li r0, 0xf;
  lis r3, 0x8034;
  sth r0, 0x1a(r28);
  addi r3, r3, -28872;
  mulli r4, r30, 0x34;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  add r27, r3, r4;
  blt lbl_801488a0;
  lis r3, 0x1e;
  addi r4, r31, 0x44;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_801488a0:
  lhz r0, 0x14(r27);
  cmpwi r0, 0;
  bne lbl_801488b8;
  lhz r0, 0x16(r27);
  cmpwi r0, 0;
  beq lbl_801488e4;
lbl_801488b8:
  li r0, 5;
  stb r0, 0x10(r27);
  lhz r3, 0x16(r27);
  cmpwi r3, 0;
  beq lbl_801488d0;
  bl L2CA_DisconnectReq;
lbl_801488d0:
  lhz r3, 0x14(r27);
  cmpwi r3, 0;
  beq lbl_801488ec;
  bl L2CA_DisconnectReq;
  b lbl_801488ec;
lbl_801488e4:
  li r0, 0;
  stb r0, 0x10(r27);
lbl_801488ec:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_connect_cfm
// PAL: 0x80148904..0x80148c4c
MARK_BINARY_BLOB(hidh_l2cif_connect_cfm, 0x80148904, 0x80148c4c);
asm UNKNOWN_FUNCTION(hidh_l2cif_connect_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  li r5, 0;
  stw r0, 0x24(r1);
  li r0, 4;
  addi r6, r6, -28872;
  li r9, 0;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x50b8;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  mtctr r0;
lbl_8014894c:
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r7, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80148988;
  lbz r0, 0x10(r7);
  cmpwi r0, 0;
  beq lbl_80148988;
  lhz r0, 0x14(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
  lhz r0, 0x16(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
lbl_80148988:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r7, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_801489c8;
  lbz r0, 0x10(r7);
  cmpwi r0, 0;
  beq lbl_801489c8;
  lhz r0, 0x14(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
  lhz r0, 0x16(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
lbl_801489c8:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r7, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80148a08;
  lbz r0, 0x10(r7);
  cmpwi r0, 0;
  beq lbl_80148a08;
  lhz r0, 0x14(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
  lhz r0, 0x16(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
lbl_80148a08:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r7, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80148a48;
  lbz r0, 0x10(r7);
  cmpwi r0, 0;
  beq lbl_80148a48;
  lhz r0, 0x14(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
  lhz r0, 0x16(r7);
  cmplw r3, r0;
  beq lbl_80148a50;
lbl_80148a48:
  addi r30, r30, 1;
  bdnz lbl_8014894c;
lbl_80148a50:
  clrlwi r0, r30, 0x18;
  cmplwi r0, 0x10;
  beq lbl_80148a70;
  mulli r0, r0, 0x34;
  lis r5, 0x8034;
  addi r5, r5, -28872;
  add r9, r5, r0;
  addi r5, r9, 0x10;
lbl_80148a70:
  cmpwi r5, 0;
  beq lbl_80148ab4;
  lbz r0, 1(r5);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80148ab4;
  lhz r6, 4(r5);
  cmplw r3, r6;
  bne lbl_80148a9c;
  lbz r0, 0(r5);
  cmplwi r0, 1;
  bne lbl_80148ab4;
lbl_80148a9c:
  lhz r0, 6(r5);
  cmplw r3, r0;
  bne lbl_80148ae0;
  lbz r0, 0(r5);
  cmplwi r0, 2;
  beq lbl_80148ae0;
lbl_80148ab4:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_80148c2c;
  lis r3, 0x1e;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r31, 0x1bc;
  bl LogMsg_1;
  b lbl_80148c2c;
lbl_80148ae0:
  cmpwi r4, 0;
  beq lbl_80148ba8;
  cmplw r3, r6;
  bne lbl_80148afc;
  li r0, 0;
  sth r0, 4(r5);
  b lbl_80148b04;
lbl_80148afc:
  li r0, 0;
  sth r0, 6(r5);
lbl_80148b04:
  lis r3, 0x8034;
  clrlwi r4, r30, 0x18;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  mulli r4, r4, 0x34;
  cmplwi r0, 4;
  add r28, r3, r4;
  blt lbl_80148b34;
  lis r3, 0x1e;
  addi r4, r31, 0x44;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80148b34:
  lhz r0, 0x14(r28);
  cmpwi r0, 0;
  bne lbl_80148b4c;
  lhz r0, 0x16(r28);
  cmpwi r0, 0;
  beq lbl_80148b78;
lbl_80148b4c:
  li r0, 5;
  stb r0, 0x10(r28);
  lhz r3, 0x16(r28);
  cmpwi r3, 0;
  beq lbl_80148b64;
  bl L2CA_DisconnectReq;
lbl_80148b64:
  lhz r3, 0x14(r28);
  cmpwi r3, 0;
  beq lbl_80148b80;
  bl L2CA_DisconnectReq;
  b lbl_80148b80;
lbl_80148b78:
  li r0, 0;
  stb r0, 0x10(r28);
lbl_80148b80:
  lis r4, 0x8034;
  clrlwi r3, r30, 0x18;
  addi r4, r4, -28872;
  ori r5, r29, 0x100;
  lwz r12, 0x340(r4);
  li r4, 1;
  li r6, 0;
  mtctr r12;
  bctrl;
  b lbl_80148c2c;
lbl_80148ba8:
  cmplw r3, r6;
  bne lbl_80148bf0;
  li r0, 6;
  lis r8, 0x8015;
  stb r0, 0(r5);
  li r0, 0x100;
  addi r3, r9, 1;
  addi r8, r8, -30992;
  sth r0, 0xa(r5);
  li r4, 0x11;
  li r5, 1;
  li r6, 6;
  lhz r0, 8(r9);
  rlwinm r0, r0, 0x11, 0x1f, 0x1f;
  neg r7, r0;
  addi r7, r7, 2;
  bl btm_sec_mx_access_request;
  b lbl_80148bf8;
lbl_80148bf0:
  li r0, 3;
  stb r0, 0(r5);
lbl_80148bf8:
  lis r29, 0x8034;
  mr r3, r28;
  addi r29, r29, -28872;
  addi r4, r29, 0x344;
  bl L2CA_ConfigReq;
  lbz r0, 0x401(r29);
  cmplwi r0, 4;
  blt lbl_80148c2c;
  lis r3, 0x1e;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r31, 0x1e8;
  bl LogMsg_1;
lbl_80148c2c:
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

// Symbol: hidh_l2cif_config_ind
// PAL: 0x80148c4c..0x80148ef4
MARK_BINARY_BLOB(hidh_l2cif_config_ind, 0x80148c4c, 0x80148ef4);
asm UNKNOWN_FUNCTION(hidh_l2cif_config_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  li r0, 4;
  addi r5, r5, -28872;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  mtctr r0;
lbl_80148c88:
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r4, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80148cc4;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148cc4;
  lhz r0, 0x14(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
  lhz r0, 0x16(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
lbl_80148cc4:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r4, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80148d04;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148d04;
  lhz r0, 0x14(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
  lhz r0, 0x16(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
lbl_80148d04:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r4, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80148d44;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148d44;
  lhz r0, 0x14(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
  lhz r0, 0x16(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
lbl_80148d44:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r4, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80148d84;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148d84;
  lhz r0, 0x14(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
  lhz r0, 0x16(r4);
  cmplw r3, r0;
  beq lbl_80148d8c;
lbl_80148d84:
  addi r31, r31, 1;
  bdnz lbl_80148c88;
lbl_80148d8c:
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x10;
  beq lbl_80148dac;
  mulli r0, r0, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  add r30, r3, r0;
  addi r30, r30, 0x10;
lbl_80148dac:
  cmpwi r30, 0;
  bne lbl_80148de4;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_80148ed4;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r4, 0x52d4;
  bl LogMsg_1;
  b lbl_80148ed4;
lbl_80148de4:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  blt lbl_80148e10;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r4, 0x5300;
  bl LogMsg_1;
lbl_80148e10:
  lbz r0, 2(r29);
  cmpwi r0, 0;
  beq lbl_80148e28;
  lhz r0, 4(r29);
  cmplwi r0, 0x280;
  ble lbl_80148e34;
lbl_80148e28:
  li r0, 0x280;
  sth r0, 8(r30);
  b lbl_80148e38;
lbl_80148e34:
  sth r0, 8(r30);
lbl_80148e38:
  li r0, 0;
  mr r3, r28;
  stb r0, 0x20(r29);
  mr r4, r29;
  stb r0, 2(r29);
  sth r0, 0(r29);
  bl L2CA_ConfigRsp;
  lhz r0, 4(r30);
  cmplw r28, r0;
  bne lbl_80148e70;
  lbz r0, 1(r30);
  ori r0, r0, 2;
  stb r0, 1(r30);
  b lbl_80148e7c;
lbl_80148e70:
  lbz r0, 1(r30);
  ori r0, r0, 8;
  stb r0, 1(r30);
lbl_80148e7c:
  lbz r0, 1(r30);
  rlwinm r0, r0, 0, 0x1b, 0x1e;
  cmpwi r0, 0x1e;
  bne lbl_80148ed4;
  lbz r0, 0(r30);
  cmplwi r0, 3;
  bne lbl_80148ed4;
  clrlwi r3, r31, 0x18;
  li r4, 4;
  mulli r0, r3, 0x34;
  lis r6, 0x8034;
  stb r4, 0(r30);
  li r5, 1;
  addi r6, r6, -28872;
  add r4, r6, r0;
  stb r5, 0xa(r4);
  li r4, 0;
  li r5, 0;
  lwz r12, 0x340(r6);
  li r6, 0;
  mtctr r12;
  bctrl;
lbl_80148ed4:
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

// Symbol: hidh_l2cif_config_cfm
// PAL: 0x80148ef4..0x80149200
MARK_BINARY_BLOB(hidh_l2cif_config_cfm, 0x80148ef4, 0x80149200);
asm UNKNOWN_FUNCTION(hidh_l2cif_config_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r5, 0x8034;
  lis r31, 0x8028;
  addi r5, r5, -28872;
  mr r27, r3;
  lbz r0, 0x401(r5);
  mr r28, r4;
  addi r31, r31, 0x50b8;
  li r29, 0;
  cmplwi r0, 4;
  blt lbl_80148f48;
  lis r3, 0x1e;
  lhz r6, 0(r28);
  mr r5, r27;
  addi r4, r31, 0x274;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_80148f48:
  lis r3, 0x8034;
  li r0, 4;
  addi r3, r3, -28872;
  li r30, 0;
  mtctr r0;
lbl_80148f5c:
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r4, r3, r0;
  lbzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_80148f98;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148f98;
  lhz r0, 0x14(r4);
  cmplw r27, r0;
  beq lbl_80149060;
  lhz r0, 0x16(r4);
  cmplw r27, r0;
  beq lbl_80149060;
lbl_80148f98:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r4, r3, r0;
  lbzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_80148fd8;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80148fd8;
  lhz r0, 0x14(r4);
  cmplw r27, r0;
  beq lbl_80149060;
  lhz r0, 0x16(r4);
  cmplw r27, r0;
  beq lbl_80149060;
lbl_80148fd8:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r4, r3, r0;
  lbzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_80149018;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80149018;
  lhz r0, 0x14(r4);
  cmplw r27, r0;
  beq lbl_80149060;
  lhz r0, 0x16(r4);
  cmplw r27, r0;
  beq lbl_80149060;
lbl_80149018:
  addi r30, r30, 1;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x34;
  add r4, r3, r0;
  lbzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_80149058;
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80149058;
  lhz r0, 0x14(r4);
  cmplw r27, r0;
  beq lbl_80149060;
  lhz r0, 0x16(r4);
  cmplw r27, r0;
  beq lbl_80149060;
lbl_80149058:
  addi r30, r30, 1;
  bdnz lbl_80148f5c;
lbl_80149060:
  clrlwi r0, r30, 0x18;
  cmplwi r0, 0x10;
  beq lbl_80149080;
  mulli r0, r0, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  add r29, r3, r0;
  addi r29, r29, 0x10;
lbl_80149080:
  cmpwi r29, 0;
  bne lbl_801490b4;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_801491e8;
  lis r3, 0x1e;
  mr r5, r27;
  addi r3, r3, 1;
  addi r4, r31, 0x21c;
  bl LogMsg_1;
  b lbl_801491e8;
lbl_801490b4:
  lhz r0, 0(r28);
  cmpwi r0, 0;
  beq lbl_80149168;
  lis r3, 0x8034;
  clrlwi r4, r30, 0x18;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  mulli r4, r4, 0x34;
  cmplwi r0, 4;
  add r27, r3, r4;
  blt lbl_801490f0;
  lis r3, 0x1e;
  addi r4, r31, 0x44;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_801490f0:
  lhz r0, 0x14(r27);
  cmpwi r0, 0;
  bne lbl_80149108;
  lhz r0, 0x16(r27);
  cmpwi r0, 0;
  beq lbl_80149134;
lbl_80149108:
  li r0, 5;
  stb r0, 0x10(r27);
  lhz r3, 0x16(r27);
  cmpwi r3, 0;
  beq lbl_80149120;
  bl L2CA_DisconnectReq;
lbl_80149120:
  lhz r3, 0x14(r27);
  cmpwi r3, 0;
  beq lbl_8014913c;
  bl L2CA_DisconnectReq;
  b lbl_8014913c;
lbl_80149134:
  li r0, 0;
  stb r0, 0x10(r27);
lbl_8014913c:
  lis r4, 0x8034;
  lhz r0, 0(r28);
  addi r4, r4, -28872;
  clrlwi r3, r30, 0x18;
  lwz r12, 0x340(r4);
  ori r5, r0, 0x400;
  li r4, 1;
  li r6, 0;
  mtctr r12;
  bctrl;
  b lbl_801491e8;
lbl_80149168:
  lhz r0, 4(r29);
  cmplw r27, r0;
  bne lbl_80149184;
  lbz r0, 1(r29);
  ori r0, r0, 4;
  stb r0, 1(r29);
  b lbl_80149190;
lbl_80149184:
  lbz r0, 1(r29);
  ori r0, r0, 0x10;
  stb r0, 1(r29);
lbl_80149190:
  lbz r0, 1(r29);
  rlwinm r0, r0, 0, 0x1b, 0x1e;
  cmpwi r0, 0x1e;
  bne lbl_801491e8;
  lbz r0, 0(r29);
  cmplwi r0, 3;
  bne lbl_801491e8;
  clrlwi r3, r30, 0x18;
  li r4, 4;
  mulli r0, r3, 0x34;
  lis r6, 0x8034;
  stb r4, 0(r29);
  li r5, 1;
  addi r6, r6, -28872;
  add r4, r6, r0;
  stb r5, 0xa(r4);
  li r4, 0;
  li r5, 0;
  lwz r12, 0x340(r6);
  li r6, 0;
  mtctr r12;
  bctrl;
lbl_801491e8:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_disconnect_ind
// PAL: 0x80149200..0x801494c4
MARK_BINARY_BLOB(hidh_l2cif_disconnect_ind, 0x80149200, 0x801494c4);
asm UNKNOWN_FUNCTION(hidh_l2cif_disconnect_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r5, 0x8034;
  li r0, 4;
  mr r27, r3;
  mr r28, r4;
  addi r5, r5, -28872;
  li r30, 0;
  li r29, 0;
  li r31, 0;
  mtctr r0;
lbl_80149238:
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80149274;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_80149274;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
lbl_80149274:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_801492b4;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_801492b4;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
lbl_801492b4:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_801492f4;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_801492f4;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
lbl_801492f4:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80149334;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_80149334;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_8014933c;
lbl_80149334:
  addi r31, r31, 1;
  bdnz lbl_80149238;
lbl_8014933c:
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x10;
  beq lbl_8014935c;
  mulli r0, r0, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  add r30, r3, r0;
  addi r30, r30, 0x10;
lbl_8014935c:
  cmpwi r30, 0;
  bne lbl_80149394;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_801494ac;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r27;
  addi r3, r3, 1;
  addi r4, r4, 0x5358;
  bl LogMsg_1;
  b lbl_801494ac;
lbl_80149394:
  cmpwi r4, 0;
  beq lbl_801493a4;
  mr r3, r27;
  bl L2CA_DisconnectRsp;
lbl_801493a4:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  blt lbl_801493d0;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r27;
  addi r3, r3, 3;
  addi r4, r4, 0x5384;
  bl LogMsg_1;
lbl_801493d0:
  li r0, 5;
  stb r0, 0(r30);
  lhz r0, 4(r30);
  cmplw r27, r0;
  bne lbl_801493f0;
  li r0, 0;
  sth r0, 4(r30);
  b lbl_801493f8;
lbl_801493f0:
  li r0, 0;
  sth r0, 6(r30);
lbl_801493f8:
  lhz r0, 4(r30);
  cmpwi r0, 0;
  bne lbl_801494ac;
  lhz r0, 6(r30);
  cmpwi r0, 0;
  bne lbl_801494ac;
  clrlwi r0, r31, 0x18;
  lis r3, 0x8034;
  mulli r0, r0, 0x34;
  li r4, 0;
  addi r3, r3, -28872;
  cmpwi r28, 0;
  add r3, r3, r0;
  stb r4, 0xa(r3);
  stb r4, 0(r30);
  bne lbl_80149440;
  bl btm_get_acl_disc_reason_code;
  mr r29, r3;
lbl_80149440:
  clrlwi r0, r29, 0x10;
  lhz r5, 0xa(r30);
  cmplwi r0, 5;
  beq lbl_80149488;
  cmplwi r0, 6;
  beq lbl_80149488;
  cmplwi r0, 0xe;
  beq lbl_80149488;
  cmplwi r0, 0x18;
  beq lbl_80149488;
  cmplwi r0, 0x26;
  beq lbl_80149488;
  cmplwi r0, 0x29;
  beq lbl_80149488;
  cmplwi r0, 0x25;
  beq lbl_80149488;
  cmplwi r0, 0x17;
  bne lbl_8014948c;
lbl_80149488:
  li r5, 0xf;
lbl_8014948c:
  lis r4, 0x8034;
  clrlwi r3, r31, 0x18;
  addi r4, r4, -28872;
  li r6, 0;
  lwz r12, 0x340(r4);
  li r4, 1;
  mtctr r12;
  bctrl;
lbl_801494ac:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_disconnect_cfm
// PAL: 0x801494c4..0x8014970c
MARK_BINARY_BLOB(hidh_l2cif_disconnect_cfm, 0x801494c4, 0x8014970c);
asm UNKNOWN_FUNCTION(hidh_l2cif_disconnect_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x24(r1);
  li r0, 4;
  addi r4, r4, -28872;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
  mtctr r0;
lbl_801494f8:
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r5, r4, r0;
  lbzx r0, r4, r0;
  cmpwi r0, 0;
  beq lbl_80149534;
  lbz r0, 0x10(r5);
  cmpwi r0, 0;
  beq lbl_80149534;
  lhz r0, 0x14(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
  lhz r0, 0x16(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
lbl_80149534:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r5, r4, r0;
  lbzx r0, r4, r0;
  cmpwi r0, 0;
  beq lbl_80149574;
  lbz r0, 0x10(r5);
  cmpwi r0, 0;
  beq lbl_80149574;
  lhz r0, 0x14(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
  lhz r0, 0x16(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
lbl_80149574:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r5, r4, r0;
  lbzx r0, r4, r0;
  cmpwi r0, 0;
  beq lbl_801495b4;
  lbz r0, 0x10(r5);
  cmpwi r0, 0;
  beq lbl_801495b4;
  lhz r0, 0x14(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
  lhz r0, 0x16(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
lbl_801495b4:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r5, r4, r0;
  lbzx r0, r4, r0;
  cmpwi r0, 0;
  beq lbl_801495f4;
  lbz r0, 0x10(r5);
  cmpwi r0, 0;
  beq lbl_801495f4;
  lhz r0, 0x14(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
  lhz r0, 0x16(r5);
  cmplw r3, r0;
  beq lbl_801495fc;
lbl_801495f4:
  addi r31, r31, 1;
  bdnz lbl_801494f8;
lbl_801495fc:
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x10;
  beq lbl_8014961c;
  mulli r0, r0, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  add r30, r3, r0;
  addi r30, r30, 0x10;
lbl_8014961c:
  cmpwi r30, 0;
  bne lbl_80149654;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_801496f0;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r4, 0x53a8;
  bl LogMsg_1;
  b lbl_801496f0;
lbl_80149654:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 4;
  blt lbl_80149680;
  lis r3, 0x1e;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r4, 0x53d8;
  bl LogMsg_1;
lbl_80149680:
  lhz r0, 4(r30);
  cmplw r29, r0;
  bne lbl_80149698;
  li r0, 0;
  sth r0, 4(r30);
  b lbl_801496a0;
lbl_80149698:
  li r0, 0;
  sth r0, 6(r30);
lbl_801496a0:
  lhz r0, 4(r30);
  cmpwi r0, 0;
  bne lbl_801496f0;
  lhz r0, 6(r30);
  cmpwi r0, 0;
  bne lbl_801496f0;
  clrlwi r3, r31, 0x18;
  lis r7, 0x8034;
  mulli r0, r3, 0x34;
  li r8, 0;
  addi r7, r7, -28872;
  li r4, 1;
  add r5, r7, r0;
  li r6, 0;
  stb r8, 0xa(r5);
  stb r8, 0(r30);
  lwz r12, 0x340(r7);
  lhz r5, 0xa(r30);
  mtctr r12;
  bctrl;
lbl_801496f0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_cong_ind
// PAL: 0x8014970c..0x80149904
MARK_BINARY_BLOB(hidh_l2cif_cong_ind, 0x8014970c, 0x80149904);
asm UNKNOWN_FUNCTION(hidh_l2cif_cong_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  li r0, 4;
  addi r5, r5, -28872;
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r4;
  li r4, 0;
  mtctr r0;
lbl_8014973c:
  clrlwi r0, r4, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80149778;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_80149778;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_80149840;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_80149840;
lbl_80149778:
  addi r4, r4, 1;
  clrlwi r0, r4, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_801497b8;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_801497b8;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_80149840;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_80149840;
lbl_801497b8:
  addi r4, r4, 1;
  clrlwi r0, r4, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_801497f8;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_801497f8;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_80149840;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_80149840;
lbl_801497f8:
  addi r4, r4, 1;
  clrlwi r0, r4, 0x18;
  mulli r0, r0, 0x34;
  add r6, r5, r0;
  lbzx r0, r5, r0;
  cmpwi r0, 0;
  beq lbl_80149838;
  lbz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_80149838;
  lhz r0, 0x14(r6);
  cmplw r3, r0;
  beq lbl_80149840;
  lhz r0, 0x16(r6);
  cmplw r3, r0;
  beq lbl_80149840;
lbl_80149838:
  addi r4, r4, 1;
  bdnz lbl_8014973c;
lbl_80149840:
  clrlwi r0, r4, 0x18;
  cmplwi r0, 0x10;
  beq lbl_80149860;
  mulli r0, r0, 0x34;
  lis r4, 0x8034;
  addi r4, r4, -28872;
  add r31, r4, r0;
  addi r31, r31, 0x10;
lbl_80149860:
  cmpwi r31, 0;
  bne lbl_80149898;
  lis r4, 0x8034;
  addi r4, r4, -28872;
  lbz r0, 0x401(r4);
  cmplwi r0, 2;
  blt lbl_801498ec;
  lis r4, 0x8028;
  lis r6, 0x1e;
  mr r5, r3;
  addi r3, r6, 1;
  addi r4, r4, 0x5400;
  bl LogMsg_1;
  b lbl_801498ec;
lbl_80149898:
  lis r4, 0x8034;
  addi r4, r4, -28872;
  lbz r0, 0x401(r4);
  cmplwi r0, 4;
  blt lbl_801498c8;
  lis r4, 0x8028;
  lis r7, 0x1e;
  mr r5, r3;
  mr r6, r30;
  addi r3, r7, 3;
  addi r4, r4, 0x5438;
  bl LogMsg_2;
lbl_801498c8:
  cmpwi r30, 0;
  beq lbl_801498e0;
  lbz r0, 1(r31);
  ori r0, r0, 0x20;
  stb r0, 1(r31);
  b lbl_801498ec;
lbl_801498e0:
  lbz r0, 1(r31);
  rlwinm r0, r0, 0, 0x1b, 0x19;
  stb r0, 1(r31);
lbl_801498ec:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: hidh_l2cif_data_ind
// PAL: 0x80149904..0x80149c9c
MARK_BINARY_BLOB(hidh_l2cif_data_ind, 0x80149904, 0x80149c9c);
asm UNKNOWN_FUNCTION(hidh_l2cif_data_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  mr r5, r3;
  stw r0, 0x24(r1);
  li r0, 4;
  addi r6, r6, -28872;
  li r9, 0;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  lhz r7, 4(r4);
  add r7, r4, r7;
  mtctr r0;
lbl_80149944:
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r8, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80149980;
  lbz r0, 0x10(r8);
  cmpwi r0, 0;
  beq lbl_80149980;
  lhz r0, 0x14(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
  lhz r0, 0x16(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
lbl_80149980:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r8, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_801499c0;
  lbz r0, 0x10(r8);
  cmpwi r0, 0;
  beq lbl_801499c0;
  lhz r0, 0x14(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
  lhz r0, 0x16(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
lbl_801499c0:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r8, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80149a00;
  lbz r0, 0x10(r8);
  cmpwi r0, 0;
  beq lbl_80149a00;
  lhz r0, 0x14(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
  lhz r0, 0x16(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
lbl_80149a00:
  addi r31, r31, 1;
  clrlwi r0, r31, 0x18;
  mulli r0, r0, 0x34;
  add r8, r6, r0;
  lbzx r0, r6, r0;
  cmpwi r0, 0;
  beq lbl_80149a40;
  lbz r0, 0x10(r8);
  cmpwi r0, 0;
  beq lbl_80149a40;
  lhz r0, 0x14(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
  lhz r0, 0x16(r8);
  cmplw r3, r0;
  beq lbl_80149a48;
lbl_80149a40:
  addi r31, r31, 1;
  bdnz lbl_80149944;
lbl_80149a48:
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x10;
  beq lbl_80149a68;
  mulli r0, r0, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  add r9, r3, r0;
  addi r9, r9, 0x10;
lbl_80149a68:
  cmpwi r9, 0;
  bne lbl_80149aa4;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 2;
  blt lbl_80149a98;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x5470;
  bl LogMsg_1;
lbl_80149a98:
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80149c80;
lbl_80149aa4:
  lbz r7, 8(r7);
  lhz r6, 2(r4);
  lhz r3, 4(r4);
  rlwinm r0, r7, 0x1c, 0x1c, 0x1f;
  addi r6, r6, -1;
  clrlwi r8, r7, 0x1c;
  addi r3, r3, 1;
  cmpwi r0, 0xa;
  sth r6, 2(r4);
  clrlwi r7, r7, 0x1e;
  sth r3, 4(r4);
  beq lbl_80149be8;
  bge lbl_80149af0;
  cmpwi r0, 1;
  beq lbl_80149b2c;
  bge lbl_80149c78;
  cmpwi r0, 0;
  bge lbl_80149afc;
  b lbl_80149c78;
lbl_80149af0:
  cmpwi r0, 0xc;
  bge lbl_80149c78;
  b lbl_80149c30;
lbl_80149afc:
  lis r4, 0x8034;
  mr r5, r8;
  addi r4, r4, -28872;
  clrlwi r3, r31, 0x18;
  lwz r12, 0x340(r4);
  li r4, 7;
  li r6, 0;
  mtctr r12;
  bctrl;
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80149c80;
lbl_80149b2c:
  cmpwi r8, 5;
  beq lbl_80149b38;
  b lbl_80149bdc;
lbl_80149b38:
  lis r3, 0x8034;
  clrlwi r4, r31, 0x18;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  mulli r4, r4, 0x34;
  cmplwi r0, 4;
  add r29, r3, r4;
  blt lbl_80149b6c;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x50fc;
  bl LogMsg_0;
lbl_80149b6c:
  lhz r0, 0x14(r29);
  cmpwi r0, 0;
  bne lbl_80149b84;
  lhz r0, 0x16(r29);
  cmpwi r0, 0;
  beq lbl_80149bb0;
lbl_80149b84:
  li r0, 5;
  stb r0, 0x10(r29);
  lhz r3, 0x16(r29);
  cmpwi r3, 0;
  beq lbl_80149b9c;
  bl L2CA_DisconnectReq;
lbl_80149b9c:
  lhz r3, 0x14(r29);
  cmpwi r3, 0;
  beq lbl_80149bb8;
  bl L2CA_DisconnectReq;
  b lbl_80149bb8;
lbl_80149bb0:
  li r0, 0;
  stb r0, 0x10(r29);
lbl_80149bb8:
  lis r5, 0x8034;
  clrlwi r3, r31, 0x18;
  addi r5, r5, -28872;
  li r4, 8;
  lwz r12, 0x340(r5);
  li r5, 0;
  li r6, 0;
  mtctr r12;
  bctrl;
lbl_80149bdc:
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80149c80;
lbl_80149be8:
  clrlwi r3, r31, 0x18;
  lis r6, 0x8034;
  mulli r0, r3, 0x34;
  li r4, 5;
  addi r6, r6, -28872;
  add r6, r6, r0;
  lhz r0, 0x16(r6);
  cmplw r5, r0;
  bne lbl_80149c10;
  li r4, 3;
lbl_80149c10:
  lis r6, 0x8034;
  mr r5, r7;
  addi r6, r6, -28872;
  lwz r12, 0x340(r6);
  mr r6, r30;
  mtctr r12;
  bctrl;
  b lbl_80149c80;
lbl_80149c30:
  clrlwi r3, r31, 0x18;
  lis r6, 0x8034;
  mulli r0, r3, 0x34;
  li r4, 6;
  addi r6, r6, -28872;
  add r6, r6, r0;
  lhz r0, 0x16(r6);
  cmplw r5, r0;
  bne lbl_80149c58;
  li r4, 4;
lbl_80149c58:
  lis r6, 0x8034;
  mr r5, r7;
  addi r6, r6, -28872;
  lwz r12, 0x340(r6);
  mr r6, r30;
  mtctr r12;
  bctrl;
  b lbl_80149c80;
lbl_80149c78:
  mr r3, r30;
  bl GKI_freebuf;
lbl_80149c80:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_conn_snd_data
// PAL: 0x80149c9c..0x80149f38
MARK_BINARY_BLOB(hidh_conn_snd_data, 0x80149c9c, 0x80149f38);
asm UNKNOWN_FUNCTION(hidh_conn_snd_data) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_17;
  mulli r0, r3, 0x34;
  lis r3, 0x8034;
  mr r17, r4;
  addi r3, r3, -28872;
  add r27, r3, r0;
  mr r18, r7;
  lbz r0, 0x11(r27);
  mr r19, r8;
  li r21, 0;
  li r20, 0;
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  beq lbl_80149cf8;
  cmpwi r8, 0;
  beq lbl_80149cf0;
  mr r3, r19;
  bl GKI_freebuf;
lbl_80149cf0:
  li r3, 8;
  b lbl_80149f20;
lbl_80149cf8:
  cmpwi r4, 4;
  bge lbl_80149d0c;
  cmpwi r4, 1;
  beq lbl_80149d18;
  b lbl_80149d30;
lbl_80149d0c:
  cmpwi r4, 0xa;
  beq lbl_80149d24;
  bge lbl_80149d30;
lbl_80149d18:
  lhz r23, 0x14(r27);
  li r22, 2;
  b lbl_80149d38;
lbl_80149d24:
  lhz r23, 0x16(r27);
  li r22, 2;
  b lbl_80149d38;
lbl_80149d30:
  li r3, 5;
  b lbl_80149f20;
lbl_80149d38:
  cmplwi r4, 9;
  bne lbl_80149d48;
  li r21, 1;
  b lbl_80149d5c;
lbl_80149d48:
  cmplwi r4, 4;
  bne lbl_80149d5c;
  rlwinm. r0, r5, 0, 0x1c, 0x1c;
  beq lbl_80149d5c;
  li r21, 2;
lbl_80149d5c:
  clrlwi r30, r5, 0x1c;
  clrlwi r29, r6, 0x18;
  rlwinm r28, r6, 0x18, 0x18, 0x1f;
  li r31, 9;
lbl_80149d6c:
  cmpwi r19, 0;
  beq lbl_80149d7c;
  cmpwi r20, 0;
  beq lbl_80149db0;
lbl_80149d7c:
  mr r3, r22;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r26, r3;
  bne lbl_80149d98;
  li r3, 3;
  b lbl_80149f20;
lbl_80149d98:
  sth r31, 4(r3);
  li r4, 0;
  li r24, 0;
  li r25, 0;
  li r20, 0;
  b lbl_80149e14;
lbl_80149db0:
  lhz r3, 0x18(r27);
  lhz r24, 2(r19);
  addi r0, r3, -1;
  cmpw r24, r0;
  ble lbl_80149dfc;
  mr r3, r22;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r26, r3;
  bne lbl_80149de0;
  li r3, 3;
  b lbl_80149f20;
lbl_80149de0:
  sth r31, 4(r3);
  li r4, 1;
  lhz r3, 0x18(r27);
  lhz r24, 2(r19);
  addi r0, r3, -1;
  clrlwi r25, r0, 0x10;
  b lbl_80149e14;
lbl_80149dfc:
  lhz r3, 4(r19);
  mr r26, r19;
  mr r25, r24;
  li r4, 0;
  addi r0, r3, -1;
  sth r0, 4(r19);
lbl_80149e14:
  lhz r3, 4(r26);
  rlwinm r0, r17, 4, 0x14, 0x1b;
  cmplwi r17, 4;
  add r3, r26, r3;
  or r0, r0, r30;
  stb r0, 8(r3);
  addi r3, r3, 9;
  bne lbl_80149e48;
  cmpwi r18, 0;
  beq lbl_80149e48;
  stb r18, 0(r3);
  li r25, 1;
  li r24, 1;
lbl_80149e48:
  cmpwi r4, 0;
  beq lbl_80149e80;
  lhz r0, 4(r19);
  clrlwi r5, r25, 0x10;
  add r4, r19, r0;
  addi r4, r4, 8;
  bl memcpy;
  lhz r3, 4(r19);
  lhz r0, 2(r19);
  add r3, r3, r25;
  subf r0, r25, r0;
  sth r3, 4(r19);
  sth r0, 2(r19);
  b lbl_80149ea8;
lbl_80149e80:
  cmplwi r21, 1;
  bne lbl_80149e94;
  clrlwi r0, r25, 0x10;
  stbx r29, r3, r0;
  b lbl_80149ea8;
lbl_80149e94:
  cmplwi r21, 2;
  bne lbl_80149ea8;
  clrlwi r0, r25, 0x10;
  stbux r29, r3, r0;
  stb r28, 1(r3);
lbl_80149ea8:
  add r3, r25, r21;
  subf r24, r25, r24;
  addi r0, r3, 1;
  sth r0, 2(r26);
  lbz r0, 0x11(r27);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  bne lbl_80149ed8;
  mr r3, r23;
  mr r4, r26;
  bl L2CA_DataWrite;
  clrlwi. r0, r3, 0x18;
  bne lbl_80149ee0;
lbl_80149ed8:
  li r3, 8;
  b lbl_80149f20;
lbl_80149ee0:
  clrlwi. r0, r24, 0x10;
  beq lbl_80149ef0;
  li r17, 0xb;
  b lbl_80149f0c;
lbl_80149ef0:
  lhz r3, 0x18(r27);
  clrlwi r4, r25, 0x10;
  addi r0, r3, -1;
  cmpw r4, r0;
  bne lbl_80149f0c;
  li r17, 0xb;
  li r20, 1;
lbl_80149f0c:
  clrlwi. r0, r24, 0x10;
  bne lbl_80149d6c;
  cmpwi r20, 0;
  bne lbl_80149d6c;
  li r3, 0;
lbl_80149f20:
  addi r11, r1, 0x50;
  bl _restgpr_17;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: hidh_conn_initiate
// PAL: 0x80149f38..0x8014a034
MARK_BINARY_BLOB(hidh_conn_initiate, 0x80149f38, 0x8014a034);
asm UNKNOWN_FUNCTION(hidh_conn_initiate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  mulli r0, r3, 0x34;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, -28872;
  stw r29, 0x14(r1);
  add r29, r30, r0;
  lbz r0, 0x10(r29);
  cmpwi r0, 0;
  beq lbl_80149f74;
  li r3, 9;
  b lbl_8014a018;
lbl_80149f74:
  li r5, 0;
  li r0, 0x100;
  sth r5, 0x14(r29);
  li r31, 1;
  addi r4, r29, 1;
  li r3, 0x11;
  sth r5, 0x16(r29);
  sth r0, 0x1a(r29);
  stb r31, 0x11(r29);
  bl L2CA_ConnectReq;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x14(r29);
  bne lbl_8014a010;
  lbz r0, 0x401(r30);
  cmplwi r0, 2;
  blt lbl_80149fc8;
  lis r3, 0x1e;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x521c;
  bl LogMsg_0;
lbl_80149fc8:
  lis r5, 0x8034;
  lis r3, 0x4ec5;
  addi r5, r5, -28872;
  li r4, 1;
  subf r0, r5, r29;
  addi r7, r3, -5041;
  mulhw r0, r7, r0;
  lwz r12, 0x340(r5);
  li r5, 0xe;
  li r6, 0;
  srawi r0, r0, 4;
  srwi r3, r0, 0x1f;
  add r0, r0, r3;
  mulhwu r0, r7, r0;
  rlwinm r3, r0, 0x1c, 0x18, 0x1f;
  mtctr r12;
  bctrl;
  b lbl_8014a014;
lbl_8014a010:
  stb r31, 0x10(r29);
lbl_8014a014:
  li r3, 0;
lbl_8014a018:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: hidh_conn_dereg
// PAL: 0x8014a034..0x8014a060
MARK_BINARY_BLOB(hidh_conn_dereg, 0x8014a034, 0x8014a060);
asm UNKNOWN_FUNCTION(hidh_conn_dereg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0x11;
  stw r0, 0x14(r1);
  bl L2CA_Deregister;
  li r3, 0x13;
  bl L2CA_Deregister;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
