#include "ObjTaimatsu.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80222ccc
extern UNKNOWN_FUNCTION(unk_80222ccc);
// PAL: 0x80225f14
extern UNKNOWN_FUNCTION(unk_80225f14);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8067dcc0
extern UNKNOWN_FUNCTION(unk_8067dcc0);
// PAL: 0x8081efec
extern UNKNOWN_FUNCTION(unk_8081efec);
// PAL: 0x808204b8
extern UNKNOWN_FUNCTION(unk_808204b8);
// PAL: 0x8082051c
extern UNKNOWN_FUNCTION(unk_8082051c); // Extern data references.
// PAL: 0x808a0510
extern UNKNOWN_DATA(lbl_808a0510);
// PAL: 0x808a0520
extern UNKNOWN_DATA(lbl_808a0520);
// PAL: 0x808c6510
extern UNKNOWN_DATA(lbl_808c6510);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809c21d0
extern UNKNOWN_DATA(lbl_809c21d0);
// PAL: 0x809c2280
extern UNKNOWN_DATA(lbl_809c2280);
// PAL: 0x809c2284
extern UNKNOWN_DATA(lbl_809c2284);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806de7fc
// PAL: 0x806de7fc..0x806de914
MARK_BINARY_BLOB(unk_806de7fc, 0x806de7fc, 0x806de914);
asm UNKNOWN_FUNCTION(unk_806de7fc){
#include "asm/806de7fc.s"
}

// Symbol: unk_806de914
// PAL: 0x806de914..0x806de9b0
MARK_BINARY_BLOB(unk_806de914, 0x806de914, 0x806de9b0);
asm UNKNOWN_FUNCTION(unk_806de914){
#include "asm/806de914.s"
}

// Symbol: unk_806de9b0
// PAL: 0x806de9b0..0x806dea1c
MARK_BINARY_BLOB(unk_806de9b0, 0x806de9b0, 0x806dea1c);
asm UNKNOWN_FUNCTION(unk_806de9b0){
#include "asm/806de9b0.s"
}

// Symbol: unk_806dea1c
// PAL: 0x806dea1c..0x806deb40
MARK_BINARY_BLOB(unk_806dea1c, 0x806dea1c, 0x806deb40);
asm UNKNOWN_FUNCTION(unk_806dea1c) {
#include "asm/806dea1c.s"
}
