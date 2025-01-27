#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8000f360..0x8000f41c
void __copy_longs_aligned();
// PAL: 0x8000f41c..0x8000f4c4
void __copy_longs_rev_aligned();
// PAL: 0x8000f4c4..0x8000f584
void __copy_longs_unaligned();
// PAL: 0x8000f584..0x8000f630
void __copy_longs_rev_unaligned();

#ifdef __cplusplus
}
#endif
