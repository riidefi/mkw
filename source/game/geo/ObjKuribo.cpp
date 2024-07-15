#include "ObjKuribo.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x800213e4
extern UNKNOWN_FUNCTION(unk_800213e4);
// PAL: 0x80021450
extern UNKNOWN_FUNCTION(__ptmf_scall);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80085110
extern UNKNOWN_FUNCTION(SinFIdx__Q24nw4r4mathFf);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229ee0
extern UNKNOWN_FUNCTION(__dla__FPv);
// PAL: 0x80243b6c
extern UNKNOWN_FUNCTION(normalise2__Q23EGG8Vector3fFv);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x80514838
extern UNKNOWN_FUNCTION(Vec3_add);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x80537b80
extern UNKNOWN_FUNCTION(unk_80537b80);
// PAL: 0x80557340
extern UNKNOWN_FUNCTION(unk_80557340);
// PAL: 0x805573cc
extern UNKNOWN_FUNCTION(unk_805573cc);
// PAL: 0x80590478
extern UNKNOWN_FUNCTION(unk_80590478);
// PAL: 0x80590a5c
extern UNKNOWN_FUNCTION(getPlayerIdx__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590d08
extern UNKNOWN_FUNCTION(playerPointers_getSpeed);
// PAL: 0x806b38a8
extern UNKNOWN_FUNCTION(unk_806b38a8);
// PAL: 0x806b5a38
extern UNKNOWN_FUNCTION(unk_806b5a38);
// PAL: 0x806db3a0
extern UNKNOWN_FUNCTION(unk_806db3a0);
// PAL: 0x806dc5e0
extern UNKNOWN_FUNCTION(unk_806dc5e0);
// PAL: 0x806dc790
extern UNKNOWN_FUNCTION(unk_806dc790);
// PAL: 0x806dc9d8
extern UNKNOWN_FUNCTION(unk_806dc9d8);
// PAL: 0x806dcb58
extern UNKNOWN_FUNCTION(unk_806dcb58);
// PAL: 0x806dcd48
extern UNKNOWN_FUNCTION(unk_806dcd48);
// PAL: 0x806dcddc
extern UNKNOWN_FUNCTION(unk_806dcddc);
// PAL: 0x806dd128
extern UNKNOWN_FUNCTION(unk_806dd128);
// PAL: 0x8078f500
extern UNKNOWN_FUNCTION(checkSphereFull__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x80799fbc
extern UNKNOWN_FUNCTION(unk_80799fbc);
// PAL: 0x8081efec
extern UNKNOWN_FUNCTION(unk_8081efec);
// PAL: 0x808204b8
extern UNKNOWN_FUNCTION(unk_808204b8);
// PAL: 0x808204fc
extern UNKNOWN_FUNCTION(unk_808204fc);
// PAL: 0x80820eb8
extern UNKNOWN_FUNCTION(unk_80820eb8);
// PAL: 0x80821640
extern UNKNOWN_FUNCTION(unk_80821640);
// PAL: 0x80821910
extern UNKNOWN_FUNCTION(unk_80821910); // Extern data references.
// PAL: 0x808a0378
extern UNKNOWN_DATA(lbl_808a0378);
// PAL: 0x808a037c
extern UNKNOWN_DATA(lbl_808a037c);
// PAL: 0x808a0390
extern UNKNOWN_DATA(lbl_808a0390);
// PAL: 0x808a039c
extern UNKNOWN_DATA(lbl_808a039c);
// PAL: 0x808a03a0
extern UNKNOWN_DATA(lbl_808a03a0);
// PAL: 0x808a03a8
extern UNKNOWN_DATA(lbl_808a03a8);
// PAL: 0x808a03dc
extern UNKNOWN_DATA(lbl_808a03dc);
// PAL: 0x808a66cc
extern UNKNOWN_DATA(lbl_808a66cc);
// PAL: 0x808c5d70
extern UNKNOWN_DATA(lbl_808c5d70);
// PAL: 0x808c5d88
extern UNKNOWN_DATA(lbl_808c5d88);
// PAL: 0x808c5d98
extern UNKNOWN_DATA(lbl_808c5d98);
// PAL: 0x808c5d9c
extern UNKNOWN_DATA(lbl_808c5d9c);
// PAL: 0x808c5da0
extern UNKNOWN_DATA(lbl_808c5da0);
// PAL: 0x808c5e10
extern UNKNOWN_DATA(lbl_808c5e10);
// PAL: 0x808c5f0c
extern UNKNOWN_DATA(lbl_808c5f0c);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd730
extern UNKNOWN_DATA(spInstance__Q26System11RaceManager);
// PAL: 0x809c2f44
extern UNKNOWN_DATA(spInstance__Q25Field11CourseModel);
// PAL: 0x809c3618
extern UNKNOWN_DATA(lbl_809c3618);
// PAL: 0x809c3c04
extern UNKNOWN_DATA(VEC_INFINITY);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: ObjKuribo_construct
// PAL: 0x806db184..0x806db33c
MARK_BINARY_BLOB(ObjKuribo_construct, 0x806db184, 0x806db33c);
asm UNKNOWN_FUNCTION(ObjKuribo_construct){
#include "asm/806db184.s"
}

// Symbol: unk_806db33c
// PAL: 0x806db33c..0x806db3a0
MARK_BINARY_BLOB(unk_806db33c, 0x806db33c, 0x806db3a0);
asm UNKNOWN_FUNCTION(unk_806db33c){
#include "asm/806db33c.s"
}

// Symbol: unk_806db3a0
// PAL: 0x806db3a0..0x806db40c
MARK_BINARY_BLOB(unk_806db3a0, 0x806db3a0, 0x806db40c);
asm UNKNOWN_FUNCTION(unk_806db3a0){
#include "asm/806db3a0.s"
}

// Symbol: unk_806db40c
// PAL: 0x806db40c..0x806db5ac
MARK_BINARY_BLOB(unk_806db40c, 0x806db40c, 0x806db5ac);
asm UNKNOWN_FUNCTION(unk_806db40c){
#include "asm/806db40c.s"
}

// Symbol: unk_806db5ac
// PAL: 0x806db5ac..0x806db5b0
MARK_BINARY_BLOB(unk_806db5ac, 0x806db5ac, 0x806db5b0);
asm UNKNOWN_FUNCTION(unk_806db5ac){
#include "asm/806db5ac.s"
}

// Symbol: unk_806db5b0
// PAL: 0x806db5b0..0x806db764
MARK_BINARY_BLOB(unk_806db5b0, 0x806db5b0, 0x806db764);
asm UNKNOWN_FUNCTION(unk_806db5b0){
#include "asm/806db5b0.s"
}

// Symbol: unk_806db764
// PAL: 0x806db764..0x806dba98
MARK_BINARY_BLOB(unk_806db764, 0x806db764, 0x806dba98);
asm UNKNOWN_FUNCTION(unk_806db764){
#include "asm/806db764.s"
}

// Symbol: unk_806dba98
// PAL: 0x806dba98..0x806dc21c
MARK_BINARY_BLOB(unk_806dba98, 0x806dba98, 0x806dc21c);
asm UNKNOWN_FUNCTION(unk_806dba98){
#include "asm/806dba98.s"
}

// Symbol: unk_806dc21c
// PAL: 0x806dc21c..0x806dc220
MARK_BINARY_BLOB(unk_806dc21c, 0x806dc21c, 0x806dc220);
asm UNKNOWN_FUNCTION(unk_806dc21c){
#include "asm/806dc21c.s"
}

// Symbol: unk_806dc220
// PAL: 0x806dc220..0x806dc3f4
MARK_BINARY_BLOB(unk_806dc220, 0x806dc220, 0x806dc3f4);
asm UNKNOWN_FUNCTION(unk_806dc220){
#include "asm/806dc220.s"
}

// Symbol: unk_806dc3f4
// PAL: 0x806dc3f4..0x806dc3f8
MARK_BINARY_BLOB(unk_806dc3f4, 0x806dc3f4, 0x806dc3f8);
asm UNKNOWN_FUNCTION(unk_806dc3f4){
#include "asm/806dc3f4.s"
}

// Symbol: unk_806dc3f8
// PAL: 0x806dc3f8..0x806dc460
MARK_BINARY_BLOB(unk_806dc3f8, 0x806dc3f8, 0x806dc460);
asm UNKNOWN_FUNCTION(unk_806dc3f8){
#include "asm/806dc3f8.s"
}

// Symbol: unk_806dc460
// PAL: 0x806dc460..0x806dc5e0
MARK_BINARY_BLOB(unk_806dc460, 0x806dc460, 0x806dc5e0);
asm UNKNOWN_FUNCTION(unk_806dc460){
#include "asm/806dc460.s"
}

// Symbol: unk_806dc5e0
// PAL: 0x806dc5e0..0x806dc77c
MARK_BINARY_BLOB(unk_806dc5e0, 0x806dc5e0, 0x806dc77c);
asm UNKNOWN_FUNCTION(unk_806dc5e0){
#include "asm/806dc5e0.s"
}

// Symbol: unk_806dc77c
// PAL: 0x806dc77c..0x806dc790
MARK_BINARY_BLOB(unk_806dc77c, 0x806dc77c, 0x806dc790);
asm UNKNOWN_FUNCTION(unk_806dc77c){
#include "asm/806dc77c.s"
}

// Symbol: unk_806dc790
// PAL: 0x806dc790..0x806dc978
MARK_BINARY_BLOB(unk_806dc790, 0x806dc790, 0x806dc978);
asm UNKNOWN_FUNCTION(unk_806dc790){
#include "asm/806dc790.s"
}

// Symbol: unk_806dc978
// PAL: 0x806dc978..0x806dc9d8
MARK_BINARY_BLOB(unk_806dc978, 0x806dc978, 0x806dc9d8);
asm UNKNOWN_FUNCTION(unk_806dc978){
#include "asm/806dc978.s"
}

// Symbol: unk_806dc9d8
// PAL: 0x806dc9d8..0x806dcb58
MARK_BINARY_BLOB(unk_806dc9d8, 0x806dc9d8, 0x806dcb58);
asm UNKNOWN_FUNCTION(unk_806dc9d8){
#include "asm/806dc9d8.s"
}

// Symbol: unk_806dcb58
// PAL: 0x806dcb58..0x806dcc9c
MARK_BINARY_BLOB(unk_806dcb58, 0x806dcb58, 0x806dcc9c);
asm UNKNOWN_FUNCTION(unk_806dcb58){
#include "asm/806dcb58.s"
}

// Symbol: unk_806dcc9c
// PAL: 0x806dcc9c..0x806dcd48
MARK_BINARY_BLOB(unk_806dcc9c, 0x806dcc9c, 0x806dcd48);
asm UNKNOWN_FUNCTION(unk_806dcc9c){
#include "asm/806dcc9c.s"
}

// Symbol: unk_806dcd48
// PAL: 0x806dcd48..0x806dcdd0
MARK_BINARY_BLOB(unk_806dcd48, 0x806dcd48, 0x806dcdd0);
asm UNKNOWN_FUNCTION(unk_806dcd48){
#include "asm/806dcd48.s"
}

// Symbol: unk_806dcdd0
// PAL: 0x806dcdd0..0x806dcddc
MARK_BINARY_BLOB(unk_806dcdd0, 0x806dcdd0, 0x806dcddc);
asm UNKNOWN_FUNCTION(unk_806dcdd0){
#include "asm/806dcdd0.s"
}

// Symbol: unk_806dcddc
// PAL: 0x806dcddc..0x806dcfd8
MARK_BINARY_BLOB(unk_806dcddc, 0x806dcddc, 0x806dcfd8);
asm UNKNOWN_FUNCTION(unk_806dcddc){
#include "asm/806dcddc.s"
}

// Symbol: unk_806dcfd8
// PAL: 0x806dcfd8..0x806dd038
MARK_BINARY_BLOB(unk_806dcfd8, 0x806dcfd8, 0x806dd038);
asm UNKNOWN_FUNCTION(unk_806dcfd8){
#include "asm/806dcfd8.s"
}

// Symbol: unk_806dd038
// PAL: 0x806dd038..0x806dd128
MARK_BINARY_BLOB(unk_806dd038, 0x806dd038, 0x806dd128);
asm UNKNOWN_FUNCTION(unk_806dd038){
#include "asm/806dd038.s"
}

// Symbol: unk_806dd128
// PAL: 0x806dd128..0x806dd270
MARK_BINARY_BLOB(unk_806dd128, 0x806dd128, 0x806dd270);
asm UNKNOWN_FUNCTION(unk_806dd128){
#include "asm/806dd128.s"
}

// Symbol: unk_806dd270
// PAL: 0x806dd270..0x806dd278
MARK_BINARY_BLOB(unk_806dd270, 0x806dd270, 0x806dd278);
asm UNKNOWN_FUNCTION(unk_806dd270){
#include "asm/806dd270.s"
}

// Symbol: unk_806dd278
// PAL: 0x806dd278..0x806dd2c8
MARK_BINARY_BLOB(unk_806dd278, 0x806dd278, 0x806dd2c8);
asm UNKNOWN_FUNCTION(unk_806dd278){
#include "asm/806dd278.s"
}

// Symbol: unk_806dd2c8
// PAL: 0x806dd2c8..0x806dd2d0
MARK_BINARY_BLOB(unk_806dd2c8, 0x806dd2c8, 0x806dd2d0);
asm UNKNOWN_FUNCTION(unk_806dd2c8){
#include "asm/806dd2c8.s"
}

// Symbol: unk_806dd2d0
// PAL: 0x806dd2d0..0x806dd2d8
MARK_BINARY_BLOB(unk_806dd2d0, 0x806dd2d0, 0x806dd2d8);
asm UNKNOWN_FUNCTION(unk_806dd2d0) {
#include "asm/806dd2d0.s"
}
