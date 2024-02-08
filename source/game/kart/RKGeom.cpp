#include "RKGeom.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x8001182c
extern UNKNOWN_FUNCTION(vsnprintf);
// PAL: 0x8022f80c
extern UNKNOWN_FUNCTION(sqrt__Q23EGG5MathfFf);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x805af330
extern UNKNOWN_FUNCTION(unk_805af330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_80892538[] = {
    0x3f800000
};
const u32 lbl_8089253c[] = {
    0x00000000
};
const u32 lbl_80892540[] = {
    0x43300000, 0x80000000
};
const u32 lbl_80892548[] = {
    0x43300000, 0x00000000
};
const u32 lbl_80892550[] = {
    0xbf800000, 0x00000000
};

// .data
#pragma explicit_zero_data on
u32 lbl_808b6e70[] = {
    0x00000000, 0x00000000, (u32)&unk_805af330, 0x00000000
};
#pragma explicit_zero_data off

// .bss
u8 lbl_809c19f0[256];


// Symbol: unk_805ae7b4
// PAL: 0x805ae7b4..0x805ae8d0
MARK_BINARY_BLOB(unk_805ae7b4, 0x805ae7b4, 0x805ae8d0);
asm UNKNOWN_FUNCTION(unk_805ae7b4) {
  #include "asm/805ae7b4.s"
}

// Symbol: unk_805ae8d0
// PAL: 0x805ae8d0..0x805ae9ec
MARK_BINARY_BLOB(unk_805ae8d0, 0x805ae8d0, 0x805ae9ec);
asm UNKNOWN_FUNCTION(unk_805ae8d0) {
  #include "asm/805ae8d0.s"
}

// Symbol: VEC3_perpInPlane
// PAL: 0x805ae9ec..0x805aead8
MARK_BINARY_BLOB(VEC3_perpInPlane, 0x805ae9ec, 0x805aead8);
asm UNKNOWN_FUNCTION(VEC3_perpInPlane) {
  #include "asm/805ae9ec.s"
}

// Symbol: unk_805aead8
// PAL: 0x805aead8..0x805aeb88
MARK_BINARY_BLOB(unk_805aead8, 0x805aead8, 0x805aeb88);
asm UNKNOWN_FUNCTION(unk_805aead8) {
  #include "asm/805aead8.s"
}

namespace RKGeom {
void projUnit(EGG::Vector3f &dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
  f32 dot = v1.dot(v0);
  dst.x = v1.x * dot;
  dst.y = v1.y * dot;
  dst.z = v1.z * dot;
}

void rejUnit(EGG::Vector3f &dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
  f32 dot = v1.dot(v0);
  dst.x = v0.x - v1.x * dot;
  dst.y = v0.y - v1.y * dot;
  dst.z = v0.z - v1.z * dot;
}

void projAndRej(EGG::Vector3f &proj, EGG::Vector3f &rej, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
    projUnit(proj, v0, v1);
    rej.x = v0.x - proj.x;
    rej.y = v0.y - proj.y;
    rej.z = v0.z - proj.z;
}
}

// Symbol: f32_interpolate__6RKGeomFfRfRCfRCf
// PAL: 0x805aec8c..0x805aeca8
MARK_BINARY_BLOB(f32_interpolate__6RKGeomFfRfRCfRCf, 0x805aec8c, 0x805aeca8);
asm UNKNOWN_FUNCTION(f32_interpolate__6RKGeomFfRfRCfRCf) {
  #include "asm/805aec8c.s"
}

// Symbol: unk_805aeca8
// PAL: 0x805aeca8..0x805aed14
MARK_BINARY_BLOB(unk_805aeca8, 0x805aeca8, 0x805aed14);
asm UNKNOWN_FUNCTION(unk_805aeca8) {
  #include "asm/805aeca8.s"
}

// Symbol: unk_805aed14
// PAL: 0x805aed14..0x805aee14
MARK_BINARY_BLOB(unk_805aed14, 0x805aed14, 0x805aee14);
asm UNKNOWN_FUNCTION(unk_805aed14) {
  #include "asm/805aed14.s"
}

// Symbol: unk_805aee14
// PAL: 0x805aee14..0x805aeec4
MARK_BINARY_BLOB(unk_805aee14, 0x805aee14, 0x805aeec4);
asm UNKNOWN_FUNCTION(unk_805aee14) {
  #include "asm/805aee14.s"
}

// Symbol: unk_805aeec4
// PAL: 0x805aeec4..0x805aef6c
MARK_BINARY_BLOB(unk_805aeec4, 0x805aeec4, 0x805aef6c);
asm UNKNOWN_FUNCTION(unk_805aeec4) {
  #include "asm/805aeec4.s"
}

// Symbol: unk_805aef6c
// PAL: 0x805aef6c..0x805af020
MARK_BINARY_BLOB(unk_805aef6c, 0x805aef6c, 0x805af020);
asm UNKNOWN_FUNCTION(unk_805aef6c) {
  #include "asm/805aef6c.s"
}

// Symbol: unk_805af020
// PAL: 0x805af020..0x805af048
MARK_BINARY_BLOB(unk_805af020, 0x805af020, 0x805af048);
asm UNKNOWN_FUNCTION(unk_805af020) {
  #include "asm/805af020.s"
}

// Symbol: unk_805af048
// PAL: 0x805af048..0x805af0f0
MARK_BINARY_BLOB(unk_805af048, 0x805af048, 0x805af0f0);
asm UNKNOWN_FUNCTION(unk_805af048) {
  #include "asm/805af048.s"
}

// Symbol: unk_805af0f0
// PAL: 0x805af0f0..0x805af148
MARK_BINARY_BLOB(unk_805af0f0, 0x805af0f0, 0x805af148);
asm UNKNOWN_FUNCTION(unk_805af0f0) {
  #include "asm/805af0f0.s"
}

// Symbol: unk_805af148
// PAL: 0x805af148..0x805af1bc
MARK_BINARY_BLOB(unk_805af148, 0x805af148, 0x805af1bc);
asm UNKNOWN_FUNCTION(unk_805af148) {
  #include "asm/805af148.s"
}

// Symbol: unk_805af1bc
// PAL: 0x805af1bc..0x805af228
MARK_BINARY_BLOB(unk_805af1bc, 0x805af1bc, 0x805af228);
asm UNKNOWN_FUNCTION(unk_805af1bc) {
  #include "asm/805af1bc.s"
}

// Symbol: unk_805af228
// PAL: 0x805af228..0x805af330
MARK_BINARY_BLOB(unk_805af228, 0x805af228, 0x805af330);
asm UNKNOWN_FUNCTION(unk_805af228) {
  #include "asm/805af228.s"
}

// Symbol: unk_805af330
// PAL: 0x805af330..0x805af370
MARK_BINARY_BLOB(unk_805af330, 0x805af330, 0x805af370);
asm UNKNOWN_FUNCTION(unk_805af330) {
  #include "asm/805af330.s"
}

