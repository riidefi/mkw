#include "__init_cpp_exceptions.h"
#include "ExceptionPPC.h"
#include "global_destructor_chain.h"
#include <rvl/os/__ppc_eabi_init.h>

static int fragmentID = -2;

static inline void* GetTOC(void) {
    register void* toc;

    // clang-format off
    asm {
        mr toc, r2
    };
    // clang-format on

    return toc;
}

void __init_cpp_exceptions(void) {
    if (fragmentID == -2) {
        fragmentID = __register_fragment(_eti_init_info, GetTOC());
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

extern void* const
    __init_cpp_exceptions_reference = __init_cpp_exceptions;
extern void* const
    __destroy_global_chain_reference = __destroy_global_chain;
extern void* const
    __fini_cpp_exceptions_reference = __fini_cpp_exceptions;
