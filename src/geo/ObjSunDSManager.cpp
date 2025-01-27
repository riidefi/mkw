#include "ObjSunDSManager.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x8001329c
extern UNKNOWN_FUNCTION(strcmp);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229ee0
extern UNKNOWN_FUNCTION(__dla__FPv);
// PAL: 0x806dda84
extern UNKNOWN_FUNCTION(unk_806dda84);
// PAL: 0x806ddaf4
extern UNKNOWN_FUNCTION(unk_806ddaf4);
// PAL: 0x8082b3a8
extern UNKNOWN_FUNCTION(unk_8082b3a8);
// PAL: 0x8082b3b8
extern UNKNOWN_FUNCTION(ObjManager_groupGetCount); // Extern data references.
// PAL: 0x808a04f0
extern UNKNOWN_DATA(lbl_808a04f0);
// PAL: 0x808c6420
extern UNKNOWN_DATA(lbl_808c6420);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806de624
// PAL: 0x806de624..0x806de780
MARK_BINARY_BLOB(unk_806de624, 0x806de624, 0x806de780);
asm UNKNOWN_FUNCTION(unk_806de624){
#include "asm/806de624.s"
}

// Symbol: unk_806de780
// PAL: 0x806de780..0x806de7fc
MARK_BINARY_BLOB(unk_806de780, 0x806de780, 0x806de7fc);
asm UNKNOWN_FUNCTION(unk_806de780) {
#include "asm/806de780.s"
}
