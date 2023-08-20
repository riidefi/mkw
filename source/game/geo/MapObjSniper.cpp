#include "MapObjSniper.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x806ed150
extern UNKNOWN_FUNCTION(unk_806ed150);
// PAL: 0x806f10fc
extern UNKNOWN_FUNCTION(unk_806f10fc);
// PAL: 0x8081f064
extern UNKNOWN_FUNCTION(unk_8081f064); // Extern data references.
// PAL: 0x802a4100
extern UNKNOWN_DATA(lbl_802a4100);
// PAL: 0x802a4148
extern UNKNOWN_DATA(lbl_802a4148);
// PAL: 0x808a046c
extern UNKNOWN_DATA(lbl_808a046c);
// PAL: 0x808a0478
extern UNKNOWN_DATA(lbl_808a0478);
// PAL: 0x808c60f8
extern UNKNOWN_DATA(lbl_808c60f8);
// PAL: 0x809c22b0
extern UNKNOWN_DATA(lbl_809c22b0);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806dda84
// PAL: 0x806dda84..0x806ddaf4
MARK_BINARY_BLOB(unk_806dda84, 0x806dda84, 0x806ddaf4);
asm UNKNOWN_FUNCTION(unk_806dda84){
#include "asm/806dda84.s"
}

// Symbol: unk_806ddaf4
// PAL: 0x806ddaf4..0x806ddb34
MARK_BINARY_BLOB(unk_806ddaf4, 0x806ddaf4, 0x806ddb34);
asm UNKNOWN_FUNCTION(unk_806ddaf4){
#include "asm/806ddaf4.s"
}

// Symbol: unk_806ddb34
// PAL: 0x806ddb34..0x806ddc44
MARK_BINARY_BLOB(unk_806ddb34, 0x806ddb34, 0x806ddc44);
asm UNKNOWN_FUNCTION(unk_806ddb34){
#include "asm/806ddb34.s"
}

// Symbol: unk_806ddc44
// PAL: 0x806ddc44..0x806ddcb0
MARK_BINARY_BLOB(unk_806ddc44, 0x806ddc44, 0x806ddcb0);
asm UNKNOWN_FUNCTION(unk_806ddc44) {
#include "asm/806ddc44.s"
}
