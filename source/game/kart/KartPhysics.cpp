#include "KartPhysics.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8022fac4
extern UNKNOWN_FUNCTION(makeIdentity__Q23EGG9Matrix34fFv);
// PAL: 0x80230118
extern UNKNOWN_FUNCTION(makeSQT__Q23EGG9Matrix34fFRCQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f);
// PAL: 0x80239dfc
extern UNKNOWN_FUNCTION(set__Q23EGG5QuatfFffff);
// PAL: 0x8023a5c4
extern UNKNOWN_FUNCTION(slerpTo__Q23EGG5QuatfCFRCQ23EGG5QuatffRQ23EGG5Quatf);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x8059f5bc
extern UNKNOWN_FUNCTION(PlayerPhysicsHolder_construct);
// PAL: 0x8059f6b8
extern UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysics);
// PAL: 0x8059f6f8
extern UNKNOWN_FUNCTION(unk_8059f6f8);
// PAL: 0x805b4af8
extern UNKNOWN_FUNCTION(__ct__Q24Kart12KartDynamicsFv);
// PAL: 0x805b4dc0
extern UNKNOWN_FUNCTION(init__Q24Kart12KartDynamicsFv);
// PAL: 0x805b4dc4
extern UNKNOWN_FUNCTION(setBspParams__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3fbf);
// PAL: 0x805b5170
extern UNKNOWN_FUNCTION(calc__Q24kart12KartDynamicsFffi);
// PAL: 0x805b5b64
extern UNKNOWN_FUNCTION(forceUpright__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5b68
extern UNKNOWN_FUNCTION(stabilize__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5ce8
extern UNKNOWN_FUNCTION(applyWrenchScaled__Q24kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3ff);
// PAL: 0x805b6388
extern UNKNOWN_FUNCTION(addForce__Q24Kart12KartDynamicsFRCQ23EGG8Vector3f);
// PAL: 0x805b82bc
extern UNKNOWN_FUNCTION(CollisionGroup_construct);
// PAL: 0x805b8330
extern UNKNOWN_FUNCTION(HitboxGroup_reset);
// PAL: 0x805b84c0
extern UNKNOWN_FUNCTION(astruct_1_init_bsp_params);// Extern data references.
// PAL: 0x802a4130
extern UNKNOWN_DATA(RKSystem_ey);
// PAL: 0x808b7300
extern UNKNOWN_DATA(__vt__Q24Kart16KartDynamicsBike);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_80892010[] = {
    0x42480000
};
const u32 lbl_80892014[] = {
    0x3f800000
};
const u32 lbl_80892018[] = {
    0x00000000, 0x3dcccccd
};
const u32 lbl_80892020[] = {
    0x34000000, 0x00000000
};

// .data
#pragma explicit_zero_data on
u32 __vt__Q24Kart11KartPhysics[] = {
    0x00000000, 0x00000000, (u32)&unk_8059f6f8, 0x00000000,
    0x00000000, (u32)&__dt__Q24Kart11KartPhysics, (u32)&stabilize__Q24Kart12KartDynamicsFv, (u32)&forceUpright__Q24Kart12KartDynamicsFv
};
u32 lbl_808b6a08[] = {
    0x3fc00000, 0x00000000
};
#pragma explicit_zero_data off

// .bss
u8 lbl_809c1990[4];
u8 lbl_809c1994[4];


// Symbol: PlayerPhysicsHolder_construct
// PAL: 0x8059f5bc..0x8059f678
MARK_BINARY_BLOB(PlayerPhysicsHolder_construct, 0x8059f5bc, 0x8059f678);
asm UNKNOWN_FUNCTION(PlayerPhysicsHolder_construct) {
  #include "asm/8059f5bc.s"
}

// Symbol: __dt__Q24Kart12KartDynamicsFv
// PAL: 0x8059f678..0x8059f6b8
MARK_BINARY_BLOB(__dt__Q24Kart12KartDynamicsFv, 0x8059f678, 0x8059f6b8);
asm UNKNOWN_FUNCTION(__dt__Q24Kart12KartDynamicsFv) {
  #include "asm/8059f678.s"
}

// Symbol: __dt__Q24Kart11KartPhysics
// PAL: 0x8059f6b8..0x8059f6f8
MARK_BINARY_BLOB(__dt__Q24Kart11KartPhysics, 0x8059f6b8, 0x8059f6f8);
asm UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysics) {
  #include "asm/8059f6b8.s"
}

// Symbol: unk_8059f6f8
// PAL: 0x8059f6f8..0x8059f788
MARK_BINARY_BLOB(unk_8059f6f8, 0x8059f6f8, 0x8059f788);
asm UNKNOWN_FUNCTION(unk_8059f6f8) {
  #include "asm/8059f6f8.s"
}

// Symbol: unk_8059f788
// PAL: 0x8059f788..0x8059f7c8
MARK_BINARY_BLOB(unk_8059f788, 0x8059f788, 0x8059f7c8);
asm UNKNOWN_FUNCTION(unk_8059f788) {
  #include "asm/8059f788.s"
}

// Symbol: unk_8059f7c8
// PAL: 0x8059f7c8..0x8059f968
MARK_BINARY_BLOB(unk_8059f7c8, 0x8059f7c8, 0x8059f968);
asm UNKNOWN_FUNCTION(unk_8059f7c8) {
  #include "asm/8059f7c8.s"
}

// Symbol: PlayerPhysicsHolder_update
// PAL: 0x8059f968..0x8059fc08
MARK_BINARY_BLOB(PlayerPhysicsHolder_update, 0x8059f968, 0x8059fc08);
asm UNKNOWN_FUNCTION(PlayerPhysicsHolder_update) {
  #include "asm/8059f968.s"
}

// Symbol: unk_8059fc08
// PAL: 0x8059fc08..0x8059fc30
MARK_BINARY_BLOB(unk_8059fc08, 0x8059fc08, 0x8059fc30);
asm UNKNOWN_FUNCTION(unk_8059fc08) {
  #include "asm/8059fc08.s"
}

// Symbol: unk_8059fc30
// PAL: 0x8059fc30..0x8059fc38
MARK_BINARY_BLOB(unk_8059fc30, 0x8059fc30, 0x8059fc38);
asm UNKNOWN_FUNCTION(unk_8059fc30) {
  #include "asm/8059fc30.s"
}

// Symbol: unk_8059fc38
// PAL: 0x8059fc38..0x8059fc48
MARK_BINARY_BLOB(unk_8059fc38, 0x8059fc38, 0x8059fc48);
asm UNKNOWN_FUNCTION(unk_8059fc38) {
  #include "asm/8059fc38.s"
}

// Symbol: unk_8059fc48
// PAL: 0x8059fc48..0x8059fd0c
MARK_BINARY_BLOB(unk_8059fc48, 0x8059fc48, 0x8059fd0c);
asm UNKNOWN_FUNCTION(unk_8059fc48) {
  #include "asm/8059fc48.s"
}

// Symbol: unk_8059fd0c
// PAL: 0x8059fd0c..0x8059fdd0
MARK_BINARY_BLOB(unk_8059fd0c, 0x8059fd0c, 0x8059fdd0);
asm UNKNOWN_FUNCTION(unk_8059fd0c) {
  #include "asm/8059fd0c.s"
}

// Symbol: unk_8059fdd0
// PAL: 0x8059fdd0..0x8059fe94
MARK_BINARY_BLOB(unk_8059fdd0, 0x8059fdd0, 0x8059fe94);
asm UNKNOWN_FUNCTION(unk_8059fdd0) {
  #include "asm/8059fdd0.s"
}

// Symbol: unk_8059fe94
// PAL: 0x8059fe94..0x8059ff58
MARK_BINARY_BLOB(unk_8059fe94, 0x8059fe94, 0x8059ff58);
asm UNKNOWN_FUNCTION(unk_8059fe94) {
  #include "asm/8059fe94.s"
}

// Symbol: unk_8059ff58
// PAL: 0x8059ff58..0x805a0050
MARK_BINARY_BLOB(unk_8059ff58, 0x8059ff58, 0x805a0050);
asm UNKNOWN_FUNCTION(unk_8059ff58) {
  #include "asm/8059ff58.s"
}

// Symbol: unk_805a0050
// PAL: 0x805a0050..0x805a00d0
MARK_BINARY_BLOB(unk_805a0050, 0x805a0050, 0x805a00d0);
asm UNKNOWN_FUNCTION(unk_805a0050) {
  #include "asm/805a0050.s"
}

// Symbol: unk_805a00d0
// PAL: 0x805a00d0..0x805a014c
MARK_BINARY_BLOB(unk_805a00d0, 0x805a00d0, 0x805a014c);
asm UNKNOWN_FUNCTION(unk_805a00d0) {
  #include "asm/805a00d0.s"
}

// Symbol: unk_805a014c
// PAL: 0x805a014c..0x805a01cc
MARK_BINARY_BLOB(unk_805a014c, 0x805a014c, 0x805a01cc);
asm UNKNOWN_FUNCTION(unk_805a014c) {
  #include "asm/805a014c.s"
}

// Symbol: unk_805a01cc
// PAL: 0x805a01cc..0x805a02b8
MARK_BINARY_BLOB(unk_805a01cc, 0x805a01cc, 0x805a02b8);
asm UNKNOWN_FUNCTION(unk_805a01cc) {
  #include "asm/805a01cc.s"
}

// Symbol: unk_805a02b8
// PAL: 0x805a02b8..0x805a0340
MARK_BINARY_BLOB(unk_805a02b8, 0x805a02b8, 0x805a0340);
asm UNKNOWN_FUNCTION(unk_805a02b8) {
  #include "asm/805a02b8.s"
}

// Symbol: PlayerPhysicsHolder_updateMat
// PAL: 0x805a0340..0x805a03c4
MARK_BINARY_BLOB(PlayerPhysicsHolder_updateMat, 0x805a0340, 0x805a03c4);
asm UNKNOWN_FUNCTION(PlayerPhysicsHolder_updateMat) {
  #include "asm/805a0340.s"
}

// Symbol: unk_805a03c4
// PAL: 0x805a03c4..0x805a0410
MARK_BINARY_BLOB(unk_805a03c4, 0x805a03c4, 0x805a0410);
asm UNKNOWN_FUNCTION(unk_805a03c4) {
  #include "asm/805a03c4.s"
}

// Symbol: PlayerPhysicsHolder_resetQuaternions
// PAL: 0x805a0410..0x805a0480
MARK_BINARY_BLOB(PlayerPhysicsHolder_resetQuaternions, 0x805a0410, 0x805a0480);
asm UNKNOWN_FUNCTION(PlayerPhysicsHolder_resetQuaternions) {
  #include "asm/805a0410.s"
}

// Symbol: unk_805a0480
// PAL: 0x805a0480..0x805a04a0
MARK_BINARY_BLOB(unk_805a0480, 0x805a0480, 0x805a04a0);
asm UNKNOWN_FUNCTION(unk_805a0480) {
  #include "asm/805a0480.s"
}

// Symbol: unk_805a04a0
// PAL: 0x805a04a0..0x805a0550
MARK_BINARY_BLOB(unk_805a04a0, 0x805a04a0, 0x805a0550);
asm UNKNOWN_FUNCTION(unk_805a04a0) {
  #include "asm/805a04a0.s"
}

