#include <rk_types.h>

void init_registers();

static u32 _STACK_BASE_ : 0x80399180;
static u32 _SDA_BASE_ : 0x8038cc00;
static u32 _SDA2_BASE_ : 0x8038efa0;

__declspec(section ".init") asm void init_registers(void) {
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
