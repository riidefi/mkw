#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x800211e4..0x80021220
void __init_cpp_exceptions(void);
// PAL: 0x80021220..0x80021254
void __fini_cpp_exceptions(void);

#ifdef __cplusplus
}
#endif
