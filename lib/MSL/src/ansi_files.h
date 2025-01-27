#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8000c948..0x8000c9ec
void __close_all(void);
// PAL: 0x8000c9ec..0x8000ca70
int __flush_line_buffered_output_files(void);
// PAL: 0x8000ca70..0x8000cadc
int __flush_all(void);

#ifdef __cplusplus
}
#endif
