#include "__start.h"

#include <decomp.h>
#include <string.h>

#include "__ppc_eabi_init.h"

static u32 _STACK_BASE_ : 0x80399180;
static u32 _SDA_BASE_ : 0x8038cc00;
static u32 _SDA2_BASE_ : 0x8038efa0;

u8 __debug_bba;

// Extern function references.
// PAL: 0x8000b6b0
extern int main(int argc, char* argv[]);
// PAL: 0x8001c3e4
extern UNKNOWN_FUNCTION(InitMetroTRK_BBA);
// PAL: 0x8015d314
extern UNKNOWN_FUNCTION(DBInit);
// PAL: 0x8019fc68
extern UNKNOWN_FUNCTION(OSInit);
// PAL: 0x801a8a80
extern UNKNOWN_FUNCTION(OSResetSystem);
// PAL: 0x801ae524
extern UNKNOWN_FUNCTION(__init_user);
// PAL: 0x801ae58c
extern void exit(int);

static u32 __OSPADButton : 0x800030e4;
extern void* trk_section_table;
extern void* trk_bss_entry;

// Symbol: __check_pad3
// PAL: 0x80006068..0x80006090
MARK_BINARY_BLOB(__check_pad3, 0x80006068, 0x80006090);
__declspec(section ".init") asm void __check_pad3() {
  // clang-format off
  nofralloc;
  lis r3, __OSPADButton@ha;
  lhz r0, __OSPADButton@l(r3);
  andi. r0, r0, 0xeef;
  cmpwi r0, 0xeef;
  bnelr;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  b OSResetSystem;
  blr;
  // clang-format on
}

// Symbol: __set_debug_bba
// PAL: 0x80006090..0x8000609c
__declspec(section ".init") void __set_debug_bba() { __debug_bba = 1; }

// Symbol: __get_debug_bba
// PAL: 0x8000609c..0x800060a4
__declspec(section ".init") u8 __get_debug_bba() { return __debug_bba; }

// Symbol: __start
// PAL: 0x800060a4..0x80006210
MARK_BINARY_BLOB(__start, 0x800060a4, 0x80006210);
__declspec(section ".init") asm void __start() {
  // clang-format off
  nofralloc;
  bl __init_registers;
  bl __init_hardware;
  li r0, -1;
  stwu r1, -8(r1);
  stw r0, 4(r1);
  stw r0, 0(r1);
  bl __init_data;
  li r0, 0;
  lis r6, 0x8000;
  addi r6, r6, 0x44;
  stw r0, 0(r6);
  lis r6, 0x8000;
  addi r6, r6, 0xf4;
  lwz r6, 0(r6);
  cmplwi r6, 0;
  beq lbl_800060ec;
  lwz r7, 0xc(r6);
  b lbl_8000610c;
lbl_800060ec:
  lis r5, 0x8000;
  addi r5, r5, 0x34;
  lwz r5, 0(r5);
  cmplwi r5, 0;
  beq lbl_80006148;
  lis r7, 0x8000;
  addi r7, r7, 0x30e8;
  lwz r7, 0(r7);
lbl_8000610c:
  li r5, 0;
  cmplwi r7, 2;
  beq lbl_80006138;
  cmplwi r7, 3;
  li r5, 1;
  beq lbl_80006138;
  cmplwi r7, 4;
  bne lbl_80006148;
  li r5, 2;
  bl __set_debug_bba;
  b lbl_80006148;
lbl_80006138:
  lis r6, 0x8002;
  addi r6, r6, -15540;
  mtlr r6;
  blrl;
lbl_80006148:
  lis r6, 0x8000;
  addi r6, r6, 0xf4;
  lwz r5, 0(r6);
  cmplwi r5, 0;
  beq+ lbl_800061b8;
  lwz r6, 8(r5);
  cmplwi r6, 0;
  beq+ lbl_800061b8;
  add r6, r5, r6;
  lwz r14, 0(r6);
  cmplwi r14, 0;
  beq lbl_800061b8;
  addi r15, r6, 4;
  mtctr r14;
lbl_80006180:
  addi r6, r6, 4;
  lwz r7, 0(r6);
  add r7, r7, r5;
  stw r7, 0(r6);
  bdnz lbl_80006180;
  lis r5, 0x8000;
  addi r5, r5, 0x34;
  rlwinm r7, r15, 0, 0, 0x1a;
  stw r7, 0(r5);
  lis r5, 0x8000;
  addi r5, r5, 0x3110;
  rlwinm r7, r15, 0, 0, 0x1a;
  stw r7, 0(r5);
  b lbl_800061c0;
lbl_800061b8:
  li r14, 0;
  li r15, 0;
lbl_800061c0:
  bl DBInit;
  bl OSInit;
  lis r4, 0x8000;
  addi r4, r4, 0x30e6;
  lhz r3, 0(r4);
  andi. r5, r3, 0x8000;
  beq lbl_800061e8;
  andi. r3, r3, 0x7fff;
  cmplwi r3, 1;
  bne lbl_800061ec;
lbl_800061e8:
  bl __check_pad3;
lbl_800061ec:
  bl __get_debug_bba;
  cmplwi r3, 1;
  bne lbl_800061fc;
  bl InitMetroTRK_BBA;
lbl_800061fc:
  bl __init_user;
  mr r3, r14;
  mr r4, r15;
  bl main;
  b exit;
  // clang-format on
}

__declspec(section ".init") asm void __init_registers(void) {
  li r0, 0x0;
  li r3, 0x0;
  li r4, 0x0;
  li r5, 0x0;
  li r6, 0x0;
  li r7, 0x0;
  li r8, 0x0;
  li r9, 0x0;
  li r10, 0x0;
  li r11, 0x0;
  li r12, 0x0;
  li r14, 0x0;
  li r15, 0x0;
  li r16, 0x0;
  li r17, 0x0;
  li r18, 0x0;
  li r19, 0x0;
  li r20, 0x0;
  li r21, 0x0;
  li r22, 0x0;
  li r23, 0x0;
  li r24, 0x0;
  li r25, 0x0;
  li r26, 0x0;
  li r27, 0x0;
  li r28, 0x0;
  li r29, 0x0;
  li r30, 0x0;
  li r31, 0x0;
  lis r1, _STACK_BASE_ @h;
  ori r1, r1, _STACK_BASE_ @l;
  lis r2, _SDA2_BASE_ @h;
  ori r2, r2, _SDA2_BASE_ @l;
  lis r13, _SDA_BASE_ @h;
  ori r13, r13, _SDA_BASE_ @l;
  blr;
}

// Symbol: __init_data
// PAL: 0x800062a0..0x80006348
MARK_BINARY_BLOB(__init_data, 0x800062a0, 0x80006348);
__declspec(section ".init") asm void __init_data() {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lis r29, trk_section_table@ha;
  la r29, trk_section_table@l(r29);
lbl_800062c0:
  lwz r30, 8(r29);
  cmpwi r30, 0;
  beq lbl_80006300;
  lwz r4, 0(r29);
  lwz r31, 4(r29);
  beq lbl_800062f8;
  cmplw r31, r4;
  beq lbl_800062f8;
  mr r3, r31;
  mr r5, r30;
  bl memcpy;
  mr r3, r31;
  mr r4, r30;
  bl __flush_cache;
lbl_800062f8:
  addi r29, r29, 0xc;
  b lbl_800062c0;
lbl_80006300:
  lis r29, trk_bss_entry@ha;
  la r29, trk_bss_entry@l(r29);
lbl_80006308:
  lwz r5, 4(r29);
  cmpwi r5, 0;
  beq lbl_8000632c;
  lwz r3, 0(r29);
  beq lbl_80006324;
  li r4, 0;
  bl memset;
lbl_80006324:
  addi r29, r29, 8;
  b lbl_80006308;
lbl_8000632c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
