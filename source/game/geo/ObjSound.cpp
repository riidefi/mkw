#include "ObjSound.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8070e7b8
extern UNKNOWN_FUNCTION(unk_8070e7b8);
// PAL: 0x8081efec
extern UNKNOWN_FUNCTION(unk_8081efec); // Extern data references.
// PAL: 0x808c61e8
extern UNKNOWN_DATA(lbl_808c61e8);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806ddcb0
// PAL: 0x806ddcb0..0x806ddd20
MARK_BINARY_BLOB(unk_806ddcb0, 0x806ddcb0, 0x806ddd20);
asm UNKNOWN_FUNCTION(unk_806ddcb0){
#include "asm/806ddcb0.s"
}

// Symbol: unk_806ddd20
// PAL: 0x806ddd20..0x806ddda0
MARK_BINARY_BLOB(unk_806ddd20, 0x806ddd20, 0x806ddda0);
asm UNKNOWN_FUNCTION(unk_806ddd20){
#include "asm/806ddd20.s"
}

// Symbol: unk_806ddda0
// PAL: 0x806ddda0..0x806dddbc
MARK_BINARY_BLOB(unk_806ddda0, 0x806ddda0, 0x806dddbc);
asm UNKNOWN_FUNCTION(unk_806ddda0){
#include "asm/806ddda0.s"
}

// Symbol: unk_806dddbc
// PAL: 0x806dddbc..0x806dddc0
MARK_BINARY_BLOB(unk_806dddbc, 0x806dddbc, 0x806dddc0);
asm UNKNOWN_FUNCTION(unk_806dddbc){
#include "asm/806dddbc.s"
}

// Symbol: unk_806dddc0
// PAL: 0x806dddc0..0x806dddc8
MARK_BINARY_BLOB(unk_806dddc0, 0x806dddc0, 0x806dddc8);
asm UNKNOWN_FUNCTION(unk_806dddc0){
#include "asm/806dddc0.s"
}

// Symbol: unk_806dddc8
// PAL: 0x806dddc8..0x806dddcc
MARK_BINARY_BLOB(unk_806dddc8, 0x806dddc8, 0x806dddcc);
asm UNKNOWN_FUNCTION(unk_806dddc8){
#include "asm/806dddc8.s"
}

// Symbol: unk_806dddcc
// PAL: 0x806dddcc..0x806dddd0
MARK_BINARY_BLOB(unk_806dddcc, 0x806dddcc, 0x806dddd0);
asm UNKNOWN_FUNCTION(unk_806dddcc){
#include "asm/806dddcc.s"
}

// Symbol: unk_806dddd0
// PAL: 0x806dddd0..0x806dddd4
MARK_BINARY_BLOB(unk_806dddd0, 0x806dddd0, 0x806dddd4);
asm UNKNOWN_FUNCTION(unk_806dddd0){
#include "asm/806dddd0.s"
}

// Symbol: unk_806dddd4
// PAL: 0x806dddd4..0x806dddd8
MARK_BINARY_BLOB(unk_806dddd4, 0x806dddd4, 0x806dddd8);
asm UNKNOWN_FUNCTION(unk_806dddd4) {
#include "asm/806dddd4.s"
}
