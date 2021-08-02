#include "__init_cpp_exceptions.h"

#include "ExceptionPPC.h"
#include "global_destructor_chain.h"

static int fragmentID = -2;

static inline void __exception_info_constants(void** info, char** R2) {
  register char* temp;
  asm {	mr temp, r2; }
  *R2 = temp;
  *info = (void*)_eti_init_info_;
}

// Symbol: __init_cpp_exceptions
// PAL: 0x800211e4..0x80021220
void __init_cpp_exceptions(void) {
  char* R2;
  void* info;
  if (fragmentID == -2) {
    __exception_info_constants(&info, &R2);
    fragmentID = __register_fragment((struct __eti_init_info*)info, R2);
  }
}

// Symbol: __fini_cpp_exceptions
// PAL: 0x80021220..0x80021254
void __fini_cpp_exceptions(void) {
  if (fragmentID != -2) {
    __unregister_fragment(fragmentID);
    fragmentID = -2;
  }
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
