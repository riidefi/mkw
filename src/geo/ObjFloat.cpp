#include "ObjFloat.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x8001329c
extern UNKNOWN_FUNCTION(strcmp);
// PAL: 0x8006db90
extern UNKNOWN_FUNCTION(SetMtx);
// PAL: 0x80085110
extern UNKNOWN_FUNCTION(SinFIdx__Q24nw4r4mathFf);
// PAL: 0x80199d04
extern UNKNOWN_FUNCTION(PSMTXIdentity);
// PAL: 0x80199d30
extern UNKNOWN_FUNCTION(PSMTXCopy);
// PAL: 0x80243b6c
extern UNKNOWN_FUNCTION(normalise2__Q23EGG8Vector3fFv);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x80514838
extern UNKNOWN_FUNCTION(Vec3_add);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x806b3900
extern UNKNOWN_FUNCTION(unk_806b3900);
// PAL: 0x806dd7d0
extern UNKNOWN_FUNCTION(unk_806dd7d0);
// PAL: 0x8081efec
extern UNKNOWN_FUNCTION(unk_8081efec);
// PAL: 0x808204b8
extern UNKNOWN_FUNCTION(unk_808204b8);
// PAL: 0x8082051c
extern UNKNOWN_FUNCTION(unk_8082051c);
// PAL: 0x808218b0
extern UNKNOWN_FUNCTION(unk_808218b0);
// PAL: 0x80821974
extern UNKNOWN_FUNCTION(unk_80821974); // Extern data references.
// PAL: 0x808a03e8
extern UNKNOWN_DATA(lbl_808a03e8);
// PAL: 0x808a03f0
extern UNKNOWN_DATA(lbl_808a03f0);
// PAL: 0x808a0420
extern UNKNOWN_DATA(lbl_808a0420);
// PAL: 0x808c5f18
extern UNKNOWN_DATA(lbl_808c5f18);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: unk_806dd2d8
// PAL: 0x806dd2d8..0x806dd440
MARK_BINARY_BLOB(unk_806dd2d8, 0x806dd2d8, 0x806dd440);
asm UNKNOWN_FUNCTION(unk_806dd2d8){
#include "asm/806dd2d8.s"
}

// Symbol: unk_806dd440
// PAL: 0x806dd440..0x806dd480
MARK_BINARY_BLOB(unk_806dd440, 0x806dd440, 0x806dd480);
asm UNKNOWN_FUNCTION(unk_806dd440){
#include "asm/806dd440.s"
}

// Symbol: unk_806dd480
// PAL: 0x806dd480..0x806dd5dc
MARK_BINARY_BLOB(unk_806dd480, 0x806dd480, 0x806dd5dc);
asm UNKNOWN_FUNCTION(unk_806dd480){
#include "asm/806dd480.s"
}

// Symbol: unk_806dd5dc
// PAL: 0x806dd5dc..0x806dd5e0
MARK_BINARY_BLOB(unk_806dd5dc, 0x806dd5dc, 0x806dd5e0);
asm UNKNOWN_FUNCTION(unk_806dd5dc){
#include "asm/806dd5dc.s"
}

// Symbol: unk_806dd5e0
// PAL: 0x806dd5e0..0x806dd7d0
MARK_BINARY_BLOB(unk_806dd5e0, 0x806dd5e0, 0x806dd7d0);
asm UNKNOWN_FUNCTION(unk_806dd5e0){
#include "asm/806dd5e0.s"
}

// Symbol: unk_806dd7d0
// PAL: 0x806dd7d0..0x806dd858
MARK_BINARY_BLOB(unk_806dd7d0, 0x806dd7d0, 0x806dd858);
asm UNKNOWN_FUNCTION(unk_806dd7d0){
#include "asm/806dd7d0.s"
}

// Symbol: unk_806dd858
// PAL: 0x806dd858..0x806dd924
MARK_BINARY_BLOB(unk_806dd858, 0x806dd858, 0x806dd924);
asm UNKNOWN_FUNCTION(unk_806dd858){
#include "asm/806dd858.s"
}

// Symbol: unk_806dd924
// PAL: 0x806dd924..0x806dd92c
MARK_BINARY_BLOB(unk_806dd924, 0x806dd924, 0x806dd92c);
asm UNKNOWN_FUNCTION(unk_806dd924){
#include "asm/806dd924.s"
}

// Symbol: unk_806dd92c
// PAL: 0x806dd92c..0x806dd934
MARK_BINARY_BLOB(unk_806dd92c, 0x806dd92c, 0x806dd934);
asm UNKNOWN_FUNCTION(unk_806dd92c) {
#include "asm/806dd92c.s"
}
