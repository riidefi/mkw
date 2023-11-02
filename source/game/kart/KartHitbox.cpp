#include "KartHitbox.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80020e34
extern UNKNOWN_FUNCTION(__construct_new_array);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x8023a2d0
extern UNKNOWN_FUNCTION(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f);
// PAL: 0x805b7f48
extern UNKNOWN_FUNCTION(hitbox_init);
// PAL: 0x805b821c
extern UNKNOWN_FUNCTION(CollisionData_init);
// PAL: 0x805b8480
extern UNKNOWN_FUNCTION(unk_805b8480);
// PAL: 0x805b883c
extern UNKNOWN_FUNCTION(astruct_1_init_max);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_808927a8[] = {
    0x00000000
};
const u32 lbl_808927ac[] = {
    0x3f800000
};
const u32 lbl_808927b0[] = {
    0x3f000000, 0x00000000, 0x3f800000, 0x00000000,
    0x3f800000, 0x00000000
};


// Symbol: hitbox_init
// PAL: 0x805b7f48..0x805b7f84
MARK_BINARY_BLOB(hitbox_init, 0x805b7f48, 0x805b7f84);
asm UNKNOWN_FUNCTION(hitbox_init) {
  #include "asm/805b7f48.s"
}

// Symbol: unk_805b7f84__Fv
// PAL: 0x805b7f84..0x805b7fbc
MARK_BINARY_BLOB(unk_805b7f84__Fv, 0x805b7f84, 0x805b7fbc);
asm UNKNOWN_FUNCTION(unk_805b7f84__Fv) {
  #include "asm/805b7f84.s"
}

// Symbol: Hitbox_update
// PAL: 0x805b7fbc..0x805b80a8
MARK_BINARY_BLOB(Hitbox_update, 0x805b7fbc, 0x805b80a8);
asm UNKNOWN_FUNCTION(Hitbox_update) {
  #include "asm/805b7fbc.s"
}

// Symbol: unk_805b80a8
// PAL: 0x805b80a8..0x805b8158
MARK_BINARY_BLOB(unk_805b80a8, 0x805b80a8, 0x805b8158);
asm UNKNOWN_FUNCTION(unk_805b80a8) {
  #include "asm/805b80a8.s"
}

// Symbol: unk_805b8158__Fv
// PAL: 0x805b8158..0x805b81d0
MARK_BINARY_BLOB(unk_805b8158__Fv, 0x805b8158, 0x805b81d0);
asm UNKNOWN_FUNCTION(unk_805b8158__Fv) {
  #include "asm/805b8158.s"
}

// Symbol: unk_805b81d0__Fv
// PAL: 0x805b81d0..0x805b81e4
MARK_BINARY_BLOB(unk_805b81d0__Fv, 0x805b81d0, 0x805b81e4);
asm UNKNOWN_FUNCTION(unk_805b81d0__Fv) {
  #include "asm/805b81d0.s"
}

// Symbol: unk_805b81e4__Fv
// PAL: 0x805b81e4..0x805b821c
MARK_BINARY_BLOB(unk_805b81e4__Fv, 0x805b81e4, 0x805b821c);
asm UNKNOWN_FUNCTION(unk_805b81e4__Fv) {
  #include "asm/805b81e4.s"
}

// Symbol: CollisionData_init
// PAL: 0x805b821c..0x805b82bc
MARK_BINARY_BLOB(CollisionData_init, 0x805b821c, 0x805b82bc);
asm UNKNOWN_FUNCTION(CollisionData_init) {
  #include "asm/805b821c.s"
}

// Symbol: __ct__Q24Kart11HitboxGroupFv
// PAL: 0x805b82bc..0x805b8330
MARK_BINARY_BLOB(__ct__Q24Kart11HitboxGroupFv, 0x805b82bc, 0x805b8330);
asm UNKNOWN_FUNCTION(__ct__Q24Kart11HitboxGroupFv) {
  #include "asm/805b82bc.s"
}

// Symbol: HitboxGroup_reset
// PAL: 0x805b8330..0x805b83d8
MARK_BINARY_BLOB(HitboxGroup_reset, 0x805b8330, 0x805b83d8);
asm UNKNOWN_FUNCTION(HitboxGroup_reset) {
  #include "asm/805b8330.s"
}

// Symbol: unk_805b83d8
// PAL: 0x805b83d8..0x805b8420
MARK_BINARY_BLOB(unk_805b83d8, 0x805b83d8, 0x805b8420);
asm UNKNOWN_FUNCTION(unk_805b83d8) {
  #include "asm/805b83d8.s"
}

// Symbol: unk_805b8420__Fv
// PAL: 0x805b8420..0x805b8480
MARK_BINARY_BLOB(unk_805b8420__Fv, 0x805b8420, 0x805b8480);
asm UNKNOWN_FUNCTION(unk_805b8420__Fv) {
  #include "asm/805b8420.s"
}

// Symbol: unk_805b8480
// PAL: 0x805b8480..0x805b84c0
MARK_BINARY_BLOB(unk_805b8480, 0x805b8480, 0x805b84c0);
asm UNKNOWN_FUNCTION(unk_805b8480) {
  #include "asm/805b8480.s"
}

// Symbol: astruct_1_init_bsp_params
// PAL: 0x805b84c0..0x805b86a8
MARK_BINARY_BLOB(astruct_1_init_bsp_params, 0x805b84c0, 0x805b86a8);
asm UNKNOWN_FUNCTION(astruct_1_init_bsp_params) {
  #include "asm/805b84c0.s"
}

// Symbol: unk_805b86a8
// PAL: 0x805b86a8..0x805b875c
MARK_BINARY_BLOB(unk_805b86a8, 0x805b86a8, 0x805b875c);
asm UNKNOWN_FUNCTION(unk_805b86a8) {
  #include "asm/805b86a8.s"
}

// Symbol: astruct_1_init_bsp_params_single
// PAL: 0x805b875c..0x805b883c
MARK_BINARY_BLOB(astruct_1_init_bsp_params_single, 0x805b875c, 0x805b883c);
asm UNKNOWN_FUNCTION(astruct_1_init_bsp_params_single) {
  #include "asm/805b875c.s"
}

// Symbol: astruct_1_init_max
// PAL: 0x805b883c..0x805b8984
MARK_BINARY_BLOB(astruct_1_init_max, 0x805b883c, 0x805b8984);
asm UNKNOWN_FUNCTION(astruct_1_init_max) {
  #include "asm/805b883c.s"
}

