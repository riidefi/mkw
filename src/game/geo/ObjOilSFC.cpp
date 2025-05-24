#include "ObjOilSFC.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80590a5c
extern UNKNOWN_FUNCTION(getPlayerIdx__Q24Kart15KartObjectProxyCFv);
// PAL: 0x806ab33c
extern UNKNOWN_FUNCTION(unk_806ab33c);
// PAL: 0x8070010c
extern UNKNOWN_FUNCTION(unk_8070010c);
// PAL: 0x8081efec
extern UNKNOWN_FUNCTION(unk_8081efec); // Extern data references.
// PAL: 0x808a0458
extern UNKNOWN_DATA(lbl_808a0458);
// PAL: 0x808c6008
extern UNKNOWN_DATA(lbl_808c6008);
// PAL: 0x809c21d0
extern UNKNOWN_DATA(lbl_809c21d0);
// PAL: 0x809c2690
extern UNKNOWN_DATA(lbl_809c2690);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806dd934
// PAL: 0x806dd934..0x806dd998
MARK_BINARY_BLOB(unk_806dd934, 0x806dd934, 0x806dd998);
asm UNKNOWN_FUNCTION(unk_806dd934){
#include "asm/806dd934.s"
}

// Symbol: unk_806dd998
// PAL: 0x806dd998..0x806dd9d8
MARK_BINARY_BLOB(unk_806dd998, 0x806dd998, 0x806dd9d8);
asm UNKNOWN_FUNCTION(unk_806dd998){
#include "asm/806dd998.s"
}

// Symbol: unk_806dd9d8
// PAL: 0x806dd9d8..0x806dda54
MARK_BINARY_BLOB(unk_806dd9d8, 0x806dd9d8, 0x806dda54);
asm UNKNOWN_FUNCTION(unk_806dd9d8){
#include "asm/806dd9d8.s"
}

// Symbol: unk_806dda54
// PAL: 0x806dda54..0x806dda80
MARK_BINARY_BLOB(unk_806dda54, 0x806dda54, 0x806dda80);
asm UNKNOWN_FUNCTION(unk_806dda54){
#include "asm/806dda54.s"
}

// Symbol: unk_806dda80
// PAL: 0x806dda80..0x806dda84
MARK_BINARY_BLOB(unk_806dda80, 0x806dda80, 0x806dda84);
asm UNKNOWN_FUNCTION(unk_806dda80) {
#include "asm/806dda80.s"
}
