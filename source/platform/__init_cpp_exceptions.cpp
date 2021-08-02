#include "__init_cpp_exceptions.h"

#include "ExceptionPPC.h"
#include "global_destructor_chain.h"

// Symbol: __init_cpp_exceptions
// PAL: 0x800211e4..0x80021220
MARK_BINARY_BLOB(__init_cpp_exceptions, 0x800211e4, 0x80021220);
extern asm void __init_cpp_exceptions(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, -0x7fb8(r13);
  cmpwi r0, -2;
  bne lbl_80021210;
  lis r3, 0x8000;
  mr r4, r2;
  addi r3, r3, 0x7290;
  bl __register_fragment;
  stw r3, -0x7fb8(r13);
lbl_80021210:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __fini_cpp_exceptions
// PAL: 0x80021220..0x80021254
MARK_BINARY_BLOB(__fini_cpp_exceptions, 0x80021220, 0x80021254);
asm void __fini_cpp_exceptions(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r3, -0x7fb8(r13);
  cmpwi r3, -2;
  beq lbl_80021244;
  bl __unregister_fragment;
  li r0, -2;
  stw r0, -0x7fb8(r13);
lbl_80021244:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

#pragma section ".ctors$10"
__declspec(section ".ctors$10") extern void* const
    __init_cpp_exceptions_reference = __init_cpp_exceptions;
#pragma section ".dtors$10"
__declspec(section ".dtors$10") extern void* const
    __destroy_global_chain_reference = __destroy_global_chain;
#pragma section ".dtors$15"
__declspec(section ".dtors$15") extern void* const
    __fini_cpp_exceptions_reference = __fini_cpp_exceptions;
