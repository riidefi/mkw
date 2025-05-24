#include "SectionDirector.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80008e84
extern UNKNOWN_FUNCTION(getStaticInstance__Q26System8RKSystemFv);
// PAL: 0x8000b154
extern UNKNOWN_FUNCTION(SystemManager_shutdownSystem);
// PAL: 0x8000b188
extern UNKNOWN_FUNCTION(SystemManager_returnToMenu);
// PAL: 0x8000b1bc
extern UNKNOWN_FUNCTION(SystemManager_restart);
// PAL: 0x8000b22c
extern UNKNOWN_FUNCTION(unk_8000b22c);
// PAL: 0x80078920
extern UNKNOWN_FUNCTION(LytInit__Q24nw4r3lytFv);
// PAL: 0x80162b50
extern UNKNOWN_FUNCTION(DVDGetDriveStatus);
// PAL: 0x80162bfc
extern UNKNOWN_FUNCTION(DVDPause);
// PAL: 0x80162c38
extern UNKNOWN_FUNCTION(DVDResume);
// PAL: 0x801aaca8
extern UNKNOWN_FUNCTION(OSSleepTicks);
// PAL: 0x8021522c
extern UNKNOWN_FUNCTION(ColorFader_setColor);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229de0
extern UNKNOWN_FUNCTION(__nw__FUlPQ23EGG4Heapi);
// PAL: 0x80229e14
extern UNKNOWN_FUNCTION(unk_805107d0);
// PAL: 0x8051088c
extern UNKNOWN_FUNCTION(unk_8051088c);
// PAL: 0x8051afe8
extern UNKNOWN_FUNCTION(unk_8051afe8);
// PAL: 0x8051b094
extern UNKNOWN_FUNCTION(unk_8051b094);
// PAL: 0x8051bed0
extern UNKNOWN_FUNCTION(getGameScene);
// PAL: 0x805276e0
extern UNKNOWN_FUNCTION(unk_805276e0);
// PAL: 0x8052bff8
extern UNKNOWN_FUNCTION(NandManager_init);
// PAL: 0x805b9300
extern UNKNOWN_FUNCTION(unk_805b9300);
// PAL: 0x805b9304
extern UNKNOWN_FUNCTION(unk_805b9304);
// PAL: 0x805b9344
extern UNKNOWN_FUNCTION(unk_805b9344);
// PAL: 0x805e2f60
extern UNKNOWN_FUNCTION(SM98_construct);
// PAL: 0x805e2ff8
extern UNKNOWN_FUNCTION(SM98_destroy);
// PAL: 0x8061ae6c
extern UNKNOWN_FUNCTION(SM34_construct);
// PAL: 0x8061ae7c
extern UNKNOWN_FUNCTION(SM34_destroy);
// PAL: 0x8061aebc
extern UNKNOWN_FUNCTION(SM34_init);
// PAL: 0x8061af20
extern UNKNOWN_FUNCTION(SM34_calc);
// PAL: 0x8061b338
extern UNKNOWN_FUNCTION(unk_8061b338);
// PAL: 0x8061b5a4
extern UNKNOWN_FUNCTION(unk_8061b5a4);
// PAL: 0x806209e8
extern UNKNOWN_FUNCTION(SaveGhostManager_construct);
// PAL: 0x80620a8c
extern UNKNOWN_FUNCTION(SaveGhostManager_destroy);
// PAL: 0x80620b04
extern UNKNOWN_FUNCTION(unk_80620b04);
// PAL: 0x80620b40
extern UNKNOWN_FUNCTION(SaveGhostManager_calc);
// PAL: 0x80620c5c
extern UNKNOWN_FUNCTION(unk_80620c5c);
// PAL: 0x806211dc
extern UNKNOWN_FUNCTION(SaveGhostManager_processAllRequests);
// PAL: 0x806213a4
extern UNKNOWN_FUNCTION(unk_806213a4);
// PAL: 0x80621434
extern UNKNOWN_FUNCTION(SaveGhostManager_saveLicensesIfDirty);
// PAL: 0x80621d0c
extern UNKNOWN_FUNCTION(Section_construct);
// PAL: 0x80621d84
extern UNKNOWN_FUNCTION(Section_destroy);
// PAL: 0x80621e00
extern UNKNOWN_FUNCTION(Section_init);
// PAL: 0x806220b0
extern UNKNOWN_FUNCTION(Section_load);
// PAL: 0x806221d8
extern UNKNOWN_FUNCTION(Section_deinit);
// PAL: 0x806223a0
extern UNKNOWN_FUNCTION(unk_806223a0);
// PAL: 0x806224f8
extern UNKNOWN_FUNCTION(Section_calc);
// PAL: 0x80622ae0
extern UNKNOWN_FUNCTION(unk_80622ae0);
// PAL: 0x80622b4c
extern UNKNOWN_FUNCTION(unk_80622b4c);
// PAL: 0x80622c08
extern UNKNOWN_FUNCTION(unk_80622c08);
// PAL: 0x80622ec8
extern UNKNOWN_FUNCTION(unk_80622ec8);
// PAL: 0x80622f88
extern UNKNOWN_FUNCTION(unk_80622f88);
// PAL: 0x80631588
extern UNKNOWN_FUNCTION(Section_getSceneId);
// PAL: 0x80631734
extern UNKNOWN_FUNCTION(Section_getResourceName);
// PAL: 0x80631a58
extern UNKNOWN_FUNCTION(Section_hasBackModel);
// PAL: 0x80631af8
extern UNKNOWN_FUNCTION(SectionId_hasDriver);
// PAL: 0x80634b80
extern UNKNOWN_FUNCTION(Section_getPriority);
// PAL: 0x80634d40
extern UNKNOWN_FUNCTION(SectionManager_construct);
// PAL: 0x8063550c
extern UNKNOWN_FUNCTION(unk_8063550c);
// PAL: 0x80635a3c
extern UNKNOWN_FUNCTION(SectionManager_setNextSection);
// PAL: 0x80635ac8
extern UNKNOWN_FUNCTION(SectionManager_startChangeSection);
// PAL: 0x80637998
extern UNKNOWN_FUNCTION(SystemMessageGroup_construct);
// PAL: 0x806379c8
extern UNKNOWN_FUNCTION(SystemMessageGroup_destroy);
// PAL: 0x80637a20
extern UNKNOWN_FUNCTION(SystemMessageGroup_load);
// PAL: 0x806561a8
extern UNKNOWN_FUNCTION(unk_806561a8);
// PAL: 0x80656e44
extern UNKNOWN_FUNCTION(unk_80656e44);
// PAL: 0x80668fa4
extern UNKNOWN_FUNCTION(unk_80668fa4);
// PAL: 0x80669264
extern UNKNOWN_FUNCTION(unk_80669264);
// PAL: 0x8066b418
extern UNKNOWN_FUNCTION(unk_8066b418);
// PAL: 0x807178ec
extern UNKNOWN_FUNCTION(unk_807178ec);
// PAL: 0x80782528
extern UNKNOWN_FUNCTION(unk_80782528); // Extern data references.
// PAL: 0x80385fc0
extern void* sInstance__Q23EGG14AsyncDvdStatus;
// PAL: 0x80385fc8
extern UNKNOWN_DATA(spInstance__Q26System8RKSystem);
// PAL: 0x80386000
extern UNKNOWN_DATA(sInstance__Q26System13SystemManager);
// PAL: 0x809bd6e0
extern UNKNOWN_DATA(lbl_809bd6e0);
// PAL: 0x809bd6f8
extern UNKNOWN_DATA(lbl_809bd6f8);
// PAL: 0x809bd720
extern UNKNOWN_DATA(lbl_809bd720);
// PAL: 0x809bd740
extern UNKNOWN_DATA(spInstance__Q26System9InitScene);
// PAL: 0x809c1e38
extern UNKNOWN_DATA(lbl_809c1e38);
// PAL: 0x809c20d8
extern UNKNOWN_DATA(lbl_809c20d8);
// PAL: 0x809c2144
extern UNKNOWN_DATA(lbl_809c2144);
// PAL: 0x809c2898
extern UNKNOWN_DATA(lbl_809c2898);
// PAL: 0x809c2df0
extern UNKNOWN_DATA(lbl_809c2df0);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: Section_getPriority
// PAL: 0x80634b80..0x80634c90
MARK_BINARY_BLOB(Section_getPriority, 0x80634b80, 0x80634c90);
asm UNKNOWN_FUNCTION(Section_getPriority){
#include "asm/80634b80.s"
}

// Symbol: SectionManager_initStaticInstance
// PAL: 0x80634c90..0x80634cc8
MARK_BINARY_BLOB(SectionManager_initStaticInstance, 0x80634c90, 0x80634cc8);
asm UNKNOWN_FUNCTION(SectionManager_initStaticInstance){
#include "asm/80634c90.s"
}

// Symbol: SectionManager_destroyStaticInstance
// PAL: 0x80634cc8..0x80634d40
MARK_BINARY_BLOB(SectionManager_destroyStaticInstance, 0x80634cc8, 0x80634d40);
asm UNKNOWN_FUNCTION(SectionManager_destroyStaticInstance){
#include "asm/80634cc8.s"
}

// Symbol: SectionManager_construct
// PAL: 0x80634d40..0x80634dc4
MARK_BINARY_BLOB(SectionManager_construct, 0x80634d40, 0x80634dc4);
asm UNKNOWN_FUNCTION(SectionManager_construct){
#include "asm/80634d40.s"
}

// Symbol: SectionManager_destroy
// PAL: 0x80634dc4..0x80634e44
MARK_BINARY_BLOB(SectionManager_destroy, 0x80634dc4, 0x80634e44);
asm UNKNOWN_FUNCTION(SectionManager_destroy){
#include "asm/80634dc4.s"
}

// Symbol: SectionManager_init
// PAL: 0x80634e44..0x80634fa0
MARK_BINARY_BLOB(SectionManager_init, 0x80634e44, 0x80634fa0);
asm UNKNOWN_FUNCTION(SectionManager_init){
#include "asm/80634e44.s"
}

// Symbol: unk_80634fa0
// PAL: 0x80634fa0..0x80634fbc
MARK_BINARY_BLOB(unk_80634fa0, 0x80634fa0, 0x80634fbc);
asm UNKNOWN_FUNCTION(unk_80634fa0){
#include "asm/80634fa0.s"
}

// Symbol: SectionManager_changeSection
// PAL: 0x80634fbc..0x80635080
MARK_BINARY_BLOB(SectionManager_changeSection, 0x80634fbc, 0x80635080);
asm UNKNOWN_FUNCTION(SectionManager_changeSection){
#include "asm/80634fbc.s"
}

// Symbol: unk_80635080
// PAL: 0x80635080..0x8063519c
MARK_BINARY_BLOB(unk_80635080, 0x80635080, 0x8063519c);
asm UNKNOWN_FUNCTION(unk_80635080){
#include "asm/80635080.s"
}

// Symbol: unk_8063519c
// PAL: 0x8063519c..0x806354b8
MARK_BINARY_BLOB(unk_8063519c, 0x8063519c, 0x806354b8);
asm UNKNOWN_FUNCTION(unk_8063519c){
#include "asm/8063519c.s"
}

// Symbol: unk_806354b8
// PAL: 0x806354b8..0x806354c0
MARK_BINARY_BLOB(unk_806354b8, 0x806354b8, 0x806354c0);
asm UNKNOWN_FUNCTION(unk_806354b8){
#include "asm/806354b8.s"
}

// Symbol: unk_806354c0
// PAL: 0x806354c0..0x8063550c
MARK_BINARY_BLOB(unk_806354c0, 0x806354c0, 0x8063550c);
asm UNKNOWN_FUNCTION(unk_806354c0){
#include "asm/806354c0.s"
}

// Symbol: unk_8063550c
// PAL: 0x8063550c..0x8063583c
MARK_BINARY_BLOB(unk_8063550c, 0x8063550c, 0x8063583c);
asm UNKNOWN_FUNCTION(unk_8063550c){
#include "asm/8063550c.s"
}

// Symbol: unk_8063583c
// PAL: 0x8063583c..0x80635890
MARK_BINARY_BLOB(unk_8063583c, 0x8063583c, 0x80635890);
asm UNKNOWN_FUNCTION(unk_8063583c){
#include "asm/8063583c.s"
}

// Symbol: unk_80635890
// PAL: 0x80635890..0x80635a2c
MARK_BINARY_BLOB(unk_80635890, 0x80635890, 0x80635a2c);
asm UNKNOWN_FUNCTION(unk_80635890){
#include "asm/80635890.s"
}

// Symbol: unk_80635a2c
// PAL: 0x80635a2c..0x80635a34
MARK_BINARY_BLOB(unk_80635a2c, 0x80635a2c, 0x80635a34);
asm UNKNOWN_FUNCTION(unk_80635a2c){
#include "asm/80635a2c.s"
}

// Symbol: unk_80635a34
// PAL: 0x80635a34..0x80635a3c
MARK_BINARY_BLOB(unk_80635a34, 0x80635a34, 0x80635a3c);
asm UNKNOWN_FUNCTION(unk_80635a34){
#include "asm/80635a34.s"
}

// Symbol: SectionManager_setNextSection
// PAL: 0x80635a3c..0x80635ac8
MARK_BINARY_BLOB(SectionManager_setNextSection, 0x80635a3c, 0x80635ac8);
asm UNKNOWN_FUNCTION(SectionManager_setNextSection){
#include "asm/80635a3c.s"
}

// Symbol: SectionManager_startChangeSection
// PAL: 0x80635ac8..0x80635b2c
MARK_BINARY_BLOB(SectionManager_startChangeSection, 0x80635ac8, 0x80635b2c);
asm UNKNOWN_FUNCTION(SectionManager_startChangeSection){
#include "asm/80635ac8.s"
}

// Symbol: SectionManager_startReinit
// PAL: 0x80635b2c..0x80635b70
MARK_BINARY_BLOB(SectionManager_startReinit, 0x80635b2c, 0x80635b70);
asm UNKNOWN_FUNCTION(SectionManager_startReinit){
#include "asm/80635b2c.s"
}

// Symbol: unk_80635b70
// PAL: 0x80635b70..0x80635c0c
MARK_BINARY_BLOB(unk_80635b70, 0x80635b70, 0x80635c0c);
asm UNKNOWN_FUNCTION(unk_80635b70){
#include "asm/80635b70.s"
}

// Symbol: unk_80635c0c
// PAL: 0x80635c0c..0x80635c74
MARK_BINARY_BLOB(unk_80635c0c, 0x80635c0c, 0x80635c74);
asm UNKNOWN_FUNCTION(unk_80635c0c){
#include "asm/80635c0c.s"
}

// Symbol: unk_80635c74
// PAL: 0x80635c74..0x80635cdc
MARK_BINARY_BLOB(unk_80635c74, 0x80635c74, 0x80635cdc);
asm UNKNOWN_FUNCTION(unk_80635c74){
#include "asm/80635c74.s"
}

// Symbol: SectionManager_getResourceName
// PAL: 0x80635cdc..0x80635ce4
MARK_BINARY_BLOB(SectionManager_getResourceName, 0x80635cdc, 0x80635ce4);
asm UNKNOWN_FUNCTION(SectionManager_getResourceName){
#include "asm/80635cdc.s"
}

// Symbol: unk_80635ce4
// PAL: 0x80635ce4..0x80635cec
MARK_BINARY_BLOB(unk_80635ce4, 0x80635ce4, 0x80635cec);
asm UNKNOWN_FUNCTION(unk_80635ce4){
#include "asm/80635ce4.s"
}

// Symbol: unk_80635cec
// PAL: 0x80635cec..0x80635cf4
MARK_BINARY_BLOB(unk_80635cec, 0x80635cec, 0x80635cf4);
asm UNKNOWN_FUNCTION(unk_80635cec){
#include "asm/80635cec.s"
}

// Symbol: unk_80635cf4
// PAL: 0x80635cf4..0x80635e08
MARK_BINARY_BLOB(unk_80635cf4, 0x80635cf4, 0x80635e08);
asm UNKNOWN_FUNCTION(unk_80635cf4){
#include "asm/80635cf4.s"
}

// Symbol: unk_80635e08
// PAL: 0x80635e08..0x80635eb8
MARK_BINARY_BLOB(unk_80635e08, 0x80635e08, 0x80635eb8);
asm UNKNOWN_FUNCTION(unk_80635e08) {
#include "asm/80635e08.s"
}
