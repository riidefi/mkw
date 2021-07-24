#pragma once

#define UNKNOWN_FUNCTION(name) void name(void)

#pragma section "binary_blobs"
#define SECTION_BINARY_BLOBS __declspec(section "binary_blobs")
#define MARK_BINARY_BLOB(name, start, stop)                                    \
  SECTION_BINARY_BLOBS static const char MARK_BINARY_BLOB_##name[] =           \
      "BINARY_BLOB: " #name "\t" #start "\t" #stop "\n"                        \
      __attribute__((force_export))

// Compiler intrinsics.

// PAL: 0x80021588
extern void _savegpr_21(void);
// PAL: 0x8002158C
extern void _savegpr_22(void);
// PAL: 0x80021590
extern void _savegpr_23(void);
// PAL: 0x80021594
extern void _savegpr_24(void);
// PAL: 0x80021598
extern void _savegpr_25(void);
// PAL: 0x8002159c
extern void _savegpr_26(void);
// PAL: 0x800215a0
extern void _savegpr_27(void);

// PAL: 0x800215d4
extern void _restgpr_21(void);
// PAL: 0x800215d8
extern void _restgpr_22(void);
// PAL: 0x800215dc
extern void _restgpr_23(void);
// PAL: 0x800215e0
extern void _restgpr_24(void);
// PAL: 0x800215e4
extern void _restgpr_25(void);
// PAL: 0x800215e8
extern void _restgpr_26(void);
// PAL: 0x800215ec
extern void _restgpr_27(void);

extern void __div2u(void);
// PAL: 0x800216f0
extern void __div2i(void);
extern void __mod2u(void);
extern void __mod2i(void);
extern void __shl2i(void);
extern void __shr2u(void);
extern void __shr2i(void);
