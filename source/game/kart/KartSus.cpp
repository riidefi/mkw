#include "KartSus.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x8006db90
extern UNKNOWN_FUNCTION(SetMtx);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8022ff98
extern UNKNOWN_FUNCTION(makeR__Q23EGG9Matrix34fFRCQ23EGG8Vector3f);
// PAL: 0x802302c4
extern UNKNOWN_FUNCTION(makeT__Q23EGG9Matrix34fFRCQ23EGG8Vector3f);
// PAL: 0x802303f8
extern UNKNOWN_FUNCTION(multVector__Q23EGG9Matrix34fCFRCQ23EGG8Vector3f);
// PAL: 0x80230410
extern UNKNOWN_FUNCTION(multiplyTo__Q23EGG9Matrix34fCFRCQ23EGG9Matrix34fRQ23EGG9Matrix34f);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x8056e46c
extern UNKNOWN_FUNCTION(KartPart_vf_24);
// PAL: 0x805775d0
extern UNKNOWN_FUNCTION(unk_805775d0);
// PAL: 0x80577c0c
extern UNKNOWN_FUNCTION(unk_80577c0c);
// PAL: 0x80577cc4
extern UNKNOWN_FUNCTION(unk_80577cc4);
// PAL: 0x8058f52c
extern UNKNOWN_FUNCTION(unk_8058f52c);
// PAL: 0x80590278
extern UNKNOWN_FUNCTION(unk_80590278);
// PAL: 0x8059069c
extern UNKNOWN_FUNCTION(kartBody__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059090c
extern UNKNOWN_FUNCTION(various_stuff_get_kart_parts_disp_params);
// PAL: 0x8059091c
extern UNKNOWN_FUNCTION(various_stuff_get_bike_parts_disp_params);
// PAL: 0x80590c44
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0);
// PAL: 0x80590c94
extern UNKNOWN_FUNCTION(PlayerPointers_getBodyFront);
// PAL: 0x805914bc
extern UNKNOWN_FUNCTION(getScale__Q24Kart15KartObjectProxyFv);
// PAL: 0x80592848
extern UNKNOWN_FUNCTION(KartPart_ct);
// PAL: 0x80592920
extern UNKNOWN_FUNCTION(KartPart_vf_14);
// PAL: 0x80592b54
extern UNKNOWN_FUNCTION(KartPart_vf_10);
// PAL: 0x80592cbc
extern UNKNOWN_FUNCTION(KartPart_vf_0c);
// PAL: 0x80592cdc
extern UNKNOWN_FUNCTION(unk_80592cdc);
// PAL: 0x80592d04
extern UNKNOWN_FUNCTION(unk_80592d04);
// PAL: 0x80592d88
extern UNKNOWN_FUNCTION(unk_80592d88);
// PAL: 0x80592db0
extern UNKNOWN_FUNCTION(KartPart_vf_20);
// PAL: 0x80592df8
extern UNKNOWN_FUNCTION(KartPart_vf_28);
// PAL: 0x80592e5c
extern UNKNOWN_FUNCTION(KartPart_vf_2c);
// PAL: 0x80592ee0
extern UNKNOWN_FUNCTION(unk_80592ee0);
// PAL: 0x80592f4c
extern UNKNOWN_FUNCTION(unk_80592f4c);
// PAL: 0x80598b50
extern UNKNOWN_FUNCTION(unk_80598b50);
// PAL: 0x80598bdc
extern UNKNOWN_FUNCTION(unk_80598bdc);
// PAL: 0x80598bec
extern UNKNOWN_FUNCTION(unk_80598bec);
// PAL: 0x80598fe8
extern UNKNOWN_FUNCTION(unk_80598fe8);
// PAL: 0x80598ff8
extern UNKNOWN_FUNCTION(unk_80598ff8);
// PAL: 0x80599124
extern UNKNOWN_FUNCTION(unk_80599124);
// PAL: 0x80599134
extern UNKNOWN_FUNCTION(unk_80599134);
// PAL: 0x8059938c
extern UNKNOWN_FUNCTION(unk_8059938c);
// PAL: 0x805993cc
extern UNKNOWN_FUNCTION(unk_805993cc);
// PAL: 0x80599ed4
extern UNKNOWN_FUNCTION(__ct__Q24Kart14KartSusPhysicsFUlQ24Kart13KartWheelTypel);
// PAL: 0x80599f54
extern UNKNOWN_FUNCTION(reset__Q24Kart14KartSusPhysicsFv);
// PAL: 0x80599fa0
extern UNKNOWN_FUNCTION(init__Q24Kart14KartSusPhysicsFv);
// PAL: 0x8059a02c
extern UNKNOWN_FUNCTION(setInitialState__Q24Kart14KartSusPhysicsFv);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_80891f60[] = {
    0x00000000
};
const u32 lbl_80891f64[] = {
    0x40490fdb
};

// .data
#pragma explicit_zero_data on
u32 lbl_808b65b0[] = {
    0x00000000, 0x00000000, (u32)&unk_8059938c, (u32)&KartPart_vf_0c,
    (u32)&KartPart_vf_10, (u32)&KartPart_vf_14, (u32)&unk_80599124, (u32)&unk_80599134,
    (u32)&KartPart_vf_20, (u32)&KartPart_vf_24, (u32)&KartPart_vf_28, (u32)&KartPart_vf_2c,
    (u32)&unk_80592ee0, (u32)&unk_80592f4c, (u32)&unk_80592cdc, (u32)&unk_80592d04,
    (u32)&unk_80592d88, (u32)&unk_80598bdc
};
u32 lbl_808b65f8[] = {
    0x00000000, 0x00000000, (u32)&unk_805993cc, (u32)&KartPart_vf_0c,
    (u32)&KartPart_vf_10, (u32)&KartPart_vf_14, (u32)&unk_80598fe8, (u32)&unk_80598ff8,
    (u32)&KartPart_vf_20, (u32)&KartPart_vf_24, (u32)&KartPart_vf_28, (u32)&KartPart_vf_2c,
    (u32)&unk_80592ee0, (u32)&unk_80592f4c, (u32)&unk_80592cdc, (u32)&unk_80592d04,
    (u32)&unk_80592d88, (u32)&unk_80598bdc
};
u32 lbl_808b6640[] = {
    0x00000000, 0x00000000, (u32)&unk_8058f52c, (u32)&KartPart_vf_0c,
    (u32)&KartPart_vf_10, (u32)&KartPart_vf_14, (u32)&unk_80598b50, (u32)&unk_80598bec,
    (u32)&KartPart_vf_20, (u32)&KartPart_vf_24, (u32)&KartPart_vf_28, (u32)&KartPart_vf_2c,
    (u32)&unk_80592ee0, (u32)&unk_80592f4c, (u32)&unk_80592cdc, (u32)&unk_80592d04,
    (u32)&unk_80592d88, (u32)&unk_80598bdc
};
#pragma explicit_zero_data off

// .bss


// Symbol: KartSus_ct
// PAL: 0x80598b08..0x80598b50
MARK_BINARY_BLOB(KartSus_ct, 0x80598b08, 0x80598b50);
asm UNKNOWN_FUNCTION(KartSus_ct) {
  #include "asm/80598b08.s"
}

// Symbol: unk_80598b50
// PAL: 0x80598b50..0x80598b60
MARK_BINARY_BLOB(unk_80598b50, 0x80598b50, 0x80598b60);
asm UNKNOWN_FUNCTION(unk_80598b50) {
  #include "asm/80598b50.s"
}

// Symbol: KartSus_init
// PAL: 0x80598b60..0x80598bd4
MARK_BINARY_BLOB(KartSus_init, 0x80598b60, 0x80598bd4);
asm UNKNOWN_FUNCTION(KartSus_init) {
  #include "asm/80598b60.s"
}

// Symbol: KartSus_initPhysics
// PAL: 0x80598bd4..0x80598bdc
MARK_BINARY_BLOB(KartSus_initPhysics, 0x80598bd4, 0x80598bdc);
asm UNKNOWN_FUNCTION(KartSus_initPhysics) {
  #include "asm/80598bd4.s"
}

// Symbol: unk_80598bdc
// PAL: 0x80598bdc..0x80598be4
MARK_BINARY_BLOB(unk_80598bdc, 0x80598bdc, 0x80598be4);
asm UNKNOWN_FUNCTION(unk_80598bdc) {
  #include "asm/80598bdc.s"
}

// Symbol: tire0_set_initial_physics_values
// PAL: 0x80598be4..0x80598bec
MARK_BINARY_BLOB(tire0_set_initial_physics_values, 0x80598be4, 0x80598bec);
asm UNKNOWN_FUNCTION(tire0_set_initial_physics_values) {
  #include "asm/80598be4.s"
}

// Symbol: unk_80598bec
// PAL: 0x80598bec..0x80598fe8
MARK_BINARY_BLOB(unk_80598bec, 0x80598bec, 0x80598fe8);
asm UNKNOWN_FUNCTION(unk_80598bec) {
  #include "asm/80598bec.s"
}

// Symbol: unk_80598fe8
// PAL: 0x80598fe8..0x80598ff8
MARK_BINARY_BLOB(unk_80598fe8, 0x80598fe8, 0x80598ff8);
asm UNKNOWN_FUNCTION(unk_80598fe8) {
  #include "asm/80598fe8.s"
}

// Symbol: unk_80598ff8
// PAL: 0x80598ff8..0x80599124
MARK_BINARY_BLOB(unk_80598ff8, 0x80598ff8, 0x80599124);
asm UNKNOWN_FUNCTION(unk_80598ff8) {
  #include "asm/80598ff8.s"
}

// Symbol: unk_80599124
// PAL: 0x80599124..0x80599134
MARK_BINARY_BLOB(unk_80599124, 0x80599124, 0x80599134);
asm UNKNOWN_FUNCTION(unk_80599124) {
  #include "asm/80599124.s"
}

// Symbol: unk_80599134
// PAL: 0x80599134..0x8059938c
MARK_BINARY_BLOB(unk_80599134, 0x80599134, 0x8059938c);
asm UNKNOWN_FUNCTION(unk_80599134) {
  #include "asm/80599134.s"
}

// Symbol: unk_8059938c
// PAL: 0x8059938c..0x805993cc
MARK_BINARY_BLOB(unk_8059938c, 0x8059938c, 0x805993cc);
asm UNKNOWN_FUNCTION(unk_8059938c) {
  #include "asm/8059938c.s"
}

// Symbol: unk_805993cc
// PAL: 0x805993cc..0x8059940c
MARK_BINARY_BLOB(unk_805993cc, 0x805993cc, 0x8059940c);
asm UNKNOWN_FUNCTION(unk_805993cc) {
  #include "asm/805993cc.s"
}

