#pragma once

#include <rk_types.h>

#include "__ppc_eabi_linker.h"
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80020dd8..0x80020e0c
int __register_fragment(struct __eti_init_info* info, char* TOC);
// PAL: 0x80020e0c..0x80020e34
void __unregister_fragment(int fragmentID);

#ifdef __cplusplus
}
#endif
