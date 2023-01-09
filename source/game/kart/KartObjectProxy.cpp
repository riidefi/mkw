#include "KartObjectProxy.hpp"
#include <cstddef>

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x800aef60
extern UNKNOWN_FUNCTION(List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs);
// PAL: 0x800aef80
extern UNKNOWN_FUNCTION(List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv);
// PAL: 0x800af180
extern UNKNOWN_FUNCTION(List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv);
// PAL: 0x80199d04
extern UNKNOWN_FUNCTION(PSMTXIdentity);
// PAL: 0x80199d30
extern UNKNOWN_FUNCTION(PSMTXCopy);
// PAL: 0x80521a34
extern UNKNOWN_FUNCTION(unk_80521a34);
// PAL: 0x805275ec
extern UNKNOWN_FUNCTION(isMii);
// PAL: 0x80560648
extern UNKNOWN_FUNCTION(unk_80560648);
// PAL: 0x805674f4
extern UNKNOWN_FUNCTION(unk_805674f4);
// PAL: 0x8056b8ec
extern UNKNOWN_FUNCTION(unk_8056b8ec);
// PAL: 0x8056b910
extern UNKNOWN_FUNCTION(unk_8056b910);
// PAL: 0x8056bbcc
extern UNKNOWN_FUNCTION(unk_8056bbcc);
// PAL: 0x8056bd08
extern UNKNOWN_FUNCTION(unk_8056bd08);
// PAL: 0x8056ca48
extern UNKNOWN_FUNCTION(unk_8056ca48);
// PAL: 0x8056cb5c
extern UNKNOWN_FUNCTION(unk_8056cb5c);
// PAL: 0x8057efe0
extern UNKNOWN_FUNCTION(unk_8057efe0);
// PAL: 0x8057efec
extern UNKNOWN_FUNCTION(unk_8057efec);
// PAL: 0x8057eff8
extern UNKNOWN_FUNCTION(unk_8057eff8);
// PAL: 0x80581720
extern UNKNOWN_FUNCTION(unk_80581720);
// PAL: 0x80581a24
extern UNKNOWN_FUNCTION(unk_80581a24);
// PAL: 0x805832e4
extern UNKNOWN_FUNCTION(unk_805832e4);
// PAL: 0x8058d47c
extern UNKNOWN_FUNCTION(unk_8058d47c);
// PAL: 0x80590100
extern UNKNOWN_FUNCTION(PlayerHolder_getPlayer);
// PAL: 0x80590a9c
extern UNKNOWN_FUNCTION(unk_80590a9c);
// PAL: 0x805946f4
extern UNKNOWN_FUNCTION(PlayerSub1c_startOobWipe);
// PAL: 0x80599eac
extern UNKNOWN_FUNCTION(WheelPhysics_hasFloorCollision);
// PAL: 0x80599ec8
extern UNKNOWN_FUNCTION(WheelPhysics_getCollisionData);
// PAL: 0x8059c0b8
extern UNKNOWN_FUNCTION(unk_8059c0b8);
// PAL: 0x805a49bc
extern UNKNOWN_FUNCTION(unk_805a49bc);
// PAL: 0x805a4dbc
extern UNKNOWN_FUNCTION(unk_805a4dbc);
// PAL: 0x805a4ddc
extern UNKNOWN_FUNCTION(unk_805a4ddc);
// PAL: 0x805a4dec
extern UNKNOWN_FUNCTION(unk_805a4dec);
// PAL: 0x805a4e20
extern UNKNOWN_FUNCTION(unk_805a4e20);
// PAL: 0x805a6ab8
extern UNKNOWN_FUNCTION(unk_805a6ab8);
// PAL: 0x805a6dcc
extern UNKNOWN_FUNCTION(unk_805a6dcc);
// PAL: 0x805b4e84
extern UNKNOWN_FUNCTION(PlayerPhysics_initInertia1);
// PAL: 0x808646f0
extern UNKNOWN_FUNCTION(unk_808646f0);// Extern data references.
// PAL: 0x80891c58
//extern UNKNOWN_DATA(lbl_80891c58);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd730
extern UNKNOWN_DATA(lbl_809bd730);
// PAL: 0x809c18f8
extern UNKNOWN_DATA(lbl_809c18f8);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
extern const u32 lbl_80891c58;
const u32 lbl_80891c58 = 0;
const u32 lbl_80891c5c[] = {
    0x3f800000, 0x00000003, 0x00000004, 0x00000005,
    0x00000025, 0x00000026, 0x00000014
};
const u32 lbl_80891c78[] = {
    0x42c80000
};
const u32 lbl_80891c7c[] = {
    0xc8c8c8ff
};


nw4r::ut::List Kart::KartObjectProxy::sList;
extern u32 bss_809c190c;
u32 bss_809c190c;

namespace Kart {

void KartObjectProxy::initList() {
  List_Init(&sList, offsetof(KartObjectProxy, mNode));
}

void KartObjectProxy::setupInList(KartAccessor* accessor) {
  KartObjectProxy* component = nullptr;
  while ((component = (KartObjectProxy*)List_GetNext(&sList, component))) {
    component->mAccessor = accessor;
  }
}

KartObjectProxy::KartObjectProxy() : mAccessor(nullptr) {
  List_Append(&sList, this);
}

} // namespace Kart

// Symbol: setupSingle
// PAL: 0x805901d0..0x8059020c
MARK_BINARY_BLOB(setupSingle, 0x805901d0, 0x8059020c);
asm UNKNOWN_FUNCTION(setupSingle) {
#include "asm/805901d0.s"
}

// Symbol: PlayerPointers_getPlayerPosition
// PAL: 0x8059020c..0x80590224
MARK_BINARY_BLOB(PlayerPointers_getPlayerPosition, 0x8059020c, 0x80590224);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerPosition) {
#include "asm/8059020c.s"
}

// Symbol: PlayerPointers_getPlayerPhysicsHolderPosition
// PAL: 0x80590224..0x80590238
MARK_BINARY_BLOB(PlayerPointers_getPlayerPhysicsHolderPosition, 0x80590224, 0x80590238);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolderPosition) {
#include "asm/80590224.s"
}

// Symbol: various_stuff_set_player_position
// PAL: 0x80590238..0x80590264
MARK_BINARY_BLOB(various_stuff_set_player_position, 0x80590238, 0x80590264);
asm UNKNOWN_FUNCTION(various_stuff_set_player_position) {
#include "asm/80590238.s"
}

// Symbol: PlayerPointers_getMat
// PAL: 0x80590264..0x80590278
MARK_BINARY_BLOB(PlayerPointers_getMat, 0x80590264, 0x80590278);
asm UNKNOWN_FUNCTION(PlayerPointers_getMat) {
#include "asm/80590264.s"
}

// Symbol: unk_80590278
// PAL: 0x80590278..0x80590288
MARK_BINARY_BLOB(unk_80590278, 0x80590278, 0x80590288);
asm UNKNOWN_FUNCTION(unk_80590278) {
#include "asm/80590278.s"
}

// Symbol: various_stuff_set_player_rotation
// PAL: 0x80590288..0x805902dc
MARK_BINARY_BLOB(various_stuff_set_player_rotation, 0x80590288, 0x805902dc);
asm UNKNOWN_FUNCTION(various_stuff_set_player_rotation) {
#include "asm/80590288.s"
}

// Symbol: PlayerPointers_getWheelCount0
// PAL: 0x805902dc..0x805902ec
MARK_BINARY_BLOB(PlayerPointers_getWheelCount0, 0x805902dc, 0x805902ec);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelCount0) {
#include "asm/805902dc.s"
}

// Symbol: PlayerPointers_getWheelCount1
// PAL: 0x805902ec..0x805902fc
MARK_BINARY_BLOB(PlayerPointers_getWheelCount1, 0x805902ec, 0x805902fc);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelCount1) {
#include "asm/805902ec.s"
}

// Symbol: unk_805902fc
// PAL: 0x805902fc..0x8059030c
MARK_BINARY_BLOB(unk_805902fc, 0x805902fc, 0x8059030c);
asm UNKNOWN_FUNCTION(unk_805902fc) {
#include "asm/805902fc.s"
}

// Symbol: unk_8059030c
// PAL: 0x8059030c..0x8059031c
MARK_BINARY_BLOB(unk_8059030c, 0x8059030c, 0x8059031c);
asm UNKNOWN_FUNCTION(unk_8059030c) {
#include "asm/8059030c.s"
}

// Symbol: unk_8059031c
// PAL: 0x8059031c..0x80590338
MARK_BINARY_BLOB(unk_8059031c, 0x8059031c, 0x80590338);
asm UNKNOWN_FUNCTION(unk_8059031c) {
#include "asm/8059031c.s"
}

// Symbol: unk_80590338
// PAL: 0x80590338..0x80590350
MARK_BINARY_BLOB(unk_80590338, 0x80590338, 0x80590350);
asm UNKNOWN_FUNCTION(unk_80590338) {
#include "asm/80590338.s"
}

// Symbol: unk_80590350
// PAL: 0x80590350..0x80590368
MARK_BINARY_BLOB(unk_80590350, 0x80590350, 0x80590368);
asm UNKNOWN_FUNCTION(unk_80590350) {
#include "asm/80590350.s"
}

// Symbol: unk_80590368
// PAL: 0x80590368..0x80590380
MARK_BINARY_BLOB(unk_80590368, 0x80590368, 0x80590380);
asm UNKNOWN_FUNCTION(unk_80590368) {
#include "asm/80590368.s"
}

// Symbol: unk_80590380
// PAL: 0x80590380..0x80590390
MARK_BINARY_BLOB(unk_80590380, 0x80590380, 0x80590390);
asm UNKNOWN_FUNCTION(unk_80590380) {
#include "asm/80590380.s"
}

// Symbol: unk_80590390
// PAL: 0x80590390..0x805903ac
MARK_BINARY_BLOB(unk_80590390, 0x80590390, 0x805903ac);
asm UNKNOWN_FUNCTION(unk_80590390) {
#include "asm/80590390.s"
}

// Symbol: PlayerPointers_getPlayerPhysicsHolder
// PAL: 0x805903ac..0x805903bc
MARK_BINARY_BLOB(PlayerPointers_getPlayerPhysicsHolder, 0x805903ac, 0x805903bc);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolder) {
#include "asm/805903ac.s"
}

// Symbol: unk_805903bc
// PAL: 0x805903bc..0x805903cc
MARK_BINARY_BLOB(unk_805903bc, 0x805903bc, 0x805903cc);
asm UNKNOWN_FUNCTION(unk_805903bc) {
#include "asm/805903bc.s"
}

// Symbol: PlayerPointers_getPlayerPhysics
// PAL: 0x805903cc..0x805903e0
MARK_BINARY_BLOB(PlayerPointers_getPlayerPhysics, 0x805903cc, 0x805903e0);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysics) {
#include "asm/805903cc.s"
}

// Symbol: unk_805903e0
// PAL: 0x805903e0..0x805903f4
MARK_BINARY_BLOB(unk_805903e0, 0x805903e0, 0x805903f4);
asm UNKNOWN_FUNCTION(unk_805903e0) {
#include "asm/805903e0.s"
}

// Symbol: KartAccessor_getInput
// PAL: 0x805903f4..0x8059041c
MARK_BINARY_BLOB(KartAccessor_getInput, 0x805903f4, 0x8059041c);
asm UNKNOWN_FUNCTION(KartAccessor_getInput) {
#include "asm/805903f4.s"
}

// Symbol: unk_8059041c
// PAL: 0x8059041c..0x80590478
MARK_BINARY_BLOB(unk_8059041c, 0x8059041c, 0x80590478);
asm UNKNOWN_FUNCTION(unk_8059041c) {
#include "asm/8059041c.s"
}

// Symbol: unk_80590478
// PAL: 0x80590478..0x80590570
MARK_BINARY_BLOB(unk_80590478, 0x80590478, 0x80590570);
asm UNKNOWN_FUNCTION(unk_80590478) {
#include "asm/80590478.s"
}

// Symbol: unk_80590570
// PAL: 0x80590570..0x80590650
MARK_BINARY_BLOB(unk_80590570, 0x80590570, 0x80590650);
asm UNKNOWN_FUNCTION(unk_80590570) {
#include "asm/80590570.s"
}

// Symbol: PlayerPointers_isReal
// PAL: 0x80590650..0x80590664
MARK_BINARY_BLOB(PlayerPointers_isReal, 0x80590650, 0x80590664);
asm UNKNOWN_FUNCTION(PlayerPointers_isReal) {
#include "asm/80590650.s"
}

// Symbol: PlayerPointers_isCpu
// PAL: 0x80590664..0x80590678
MARK_BINARY_BLOB(PlayerPointers_isCpu, 0x80590664, 0x80590678);
asm UNKNOWN_FUNCTION(PlayerPointers_isCpu) {
#include "asm/80590664.s"
}

// Symbol: PlayerPointers_isGhost
// PAL: 0x80590678..0x8059068c
MARK_BINARY_BLOB(PlayerPointers_isGhost, 0x80590678, 0x8059068c);
asm UNKNOWN_FUNCTION(PlayerPointers_isGhost) {
#include "asm/80590678.s"
}

// Symbol: PlayerModel_isMii
// PAL: 0x8059068c..0x8059069c
MARK_BINARY_BLOB(PlayerModel_isMii, 0x8059068c, 0x8059069c);
asm UNKNOWN_FUNCTION(PlayerModel_isMii) {
#include "asm/8059068c.s"
}

// Symbol: PlayerPointers_getKartBody
// PAL: 0x8059069c..0x805906a8
MARK_BINARY_BLOB(PlayerPointers_getKartBody, 0x8059069c, 0x805906a8);
asm UNKNOWN_FUNCTION(PlayerPointers_getKartBody) {
#include "asm/8059069c.s"
}

// Symbol: unk_805906a8
// PAL: 0x805906a8..0x805906b4
MARK_BINARY_BLOB(unk_805906a8, 0x805906a8, 0x805906b4);
asm UNKNOWN_FUNCTION(unk_805906a8) {
#include "asm/805906a8.s"
}

// Symbol: PlayerPointers_getWheel0
// PAL: 0x805906b4..0x805906c8
MARK_BINARY_BLOB(PlayerPointers_getWheel0, 0x805906b4, 0x805906c8);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheel0) {
#include "asm/805906b4.s"
}

// Symbol: unk_805906c8
// PAL: 0x805906c8..0x805906dc
MARK_BINARY_BLOB(unk_805906c8, 0x805906c8, 0x805906dc);
asm UNKNOWN_FUNCTION(unk_805906c8) {
#include "asm/805906c8.s"
}

// Symbol: PlayerPointers_getWheel1
// PAL: 0x805906dc..0x805906f0
MARK_BINARY_BLOB(PlayerPointers_getWheel1, 0x805906dc, 0x805906f0);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheel1) {
#include "asm/805906dc.s"
}

// Symbol: unk_805906f0
// PAL: 0x805906f0..0x80590704
MARK_BINARY_BLOB(unk_805906f0, 0x805906f0, 0x80590704);
asm UNKNOWN_FUNCTION(unk_805906f0) {
#include "asm/805906f0.s"
}

// Symbol: PlayerPointers_getWheelPhysicsHolder
// PAL: 0x80590704..0x8059071c
MARK_BINARY_BLOB(PlayerPointers_getWheelPhysicsHolder, 0x80590704, 0x8059071c);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysicsHolder) {
#include "asm/80590704.s"
}

// Symbol: unk_8059071c
// PAL: 0x8059071c..0x80590734
MARK_BINARY_BLOB(unk_8059071c, 0x8059071c, 0x80590734);
asm UNKNOWN_FUNCTION(unk_8059071c) {
#include "asm/8059071c.s"
}

// Symbol: PlayerPointers_getWheelPhysics
// PAL: 0x80590734..0x8059074c
MARK_BINARY_BLOB(PlayerPointers_getWheelPhysics, 0x80590734, 0x8059074c);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysics) {
#include "asm/80590734.s"
}

// Symbol: unk_8059074c
// PAL: 0x8059074c..0x80590764
MARK_BINARY_BLOB(unk_8059074c, 0x8059074c, 0x80590764);
asm UNKNOWN_FUNCTION(unk_8059074c) {
#include "asm/8059074c.s"
}

// Symbol: PlayerPointers_getPlayerSub
// PAL: 0x80590764..0x80590770
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub, 0x80590764, 0x80590770);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub) {
#include "asm/80590764.s"
}

// Symbol: unk_80590770
// PAL: 0x80590770..0x8059077c
MARK_BINARY_BLOB(unk_80590770, 0x80590770, 0x8059077c);
asm UNKNOWN_FUNCTION(unk_80590770) {
#include "asm/80590770.s"
}

// Symbol: PlayerPointers_getPlayerSub10
// PAL: 0x8059077c..0x80590788
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub10, 0x8059077c, 0x80590788);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub10) {
#include "asm/8059077c.s"
}

// Symbol: unk_80590788
// PAL: 0x80590788..0x80590794
MARK_BINARY_BLOB(unk_80590788, 0x80590788, 0x80590794);
asm UNKNOWN_FUNCTION(unk_80590788) {
#include "asm/80590788.s"
}

// Symbol: PlayerPointers_getSnd
// PAL: 0x80590794..0x805907a0
MARK_BINARY_BLOB(PlayerPointers_getSnd, 0x80590794, 0x805907a0);
asm UNKNOWN_FUNCTION(PlayerPointers_getSnd) {
#include "asm/80590794.s"
}

// Symbol: unk_805907a0
// PAL: 0x805907a0..0x805907b0
MARK_BINARY_BLOB(unk_805907a0, 0x805907a0, 0x805907b0);
asm UNKNOWN_FUNCTION(unk_805907a0) {
#include "asm/805907a0.s"
}

// Symbol: unk_805907b0
// PAL: 0x805907b0..0x805907c0
MARK_BINARY_BLOB(unk_805907b0, 0x805907b0, 0x805907c0);
asm UNKNOWN_FUNCTION(unk_805907b0) {
#include "asm/805907b0.s"
}

// Symbol: PlayerPointers_get34
// PAL: 0x805907c0..0x805907cc
MARK_BINARY_BLOB(PlayerPointers_get34, 0x805907c0, 0x805907cc);
asm UNKNOWN_FUNCTION(PlayerPointers_get34) {
#include "asm/805907c0.s"
}

// Symbol: unk_805907cc
// PAL: 0x805907cc..0x805907d8
MARK_BINARY_BLOB(unk_805907cc, 0x805907cc, 0x805907d8);
asm UNKNOWN_FUNCTION(unk_805907cc) {
#include "asm/805907cc.s"
}

// Symbol: PlayerPointers_getCollisionGroup
// PAL: 0x805907d8..0x805907ec
MARK_BINARY_BLOB(PlayerPointers_getCollisionGroup, 0x805907d8, 0x805907ec);
asm UNKNOWN_FUNCTION(PlayerPointers_getCollisionGroup) {
#include "asm/805907d8.s"
}

// Symbol: unk_805907ec
// PAL: 0x805907ec..0x80590800
MARK_BINARY_BLOB(unk_805907ec, 0x805907ec, 0x80590800);
asm UNKNOWN_FUNCTION(unk_805907ec) {
#include "asm/805907ec.s"
}

// Symbol: unk_80590800
// PAL: 0x80590800..0x8059081c
MARK_BINARY_BLOB(unk_80590800, 0x80590800, 0x8059081c);
asm UNKNOWN_FUNCTION(unk_80590800) {
#include "asm/80590800.s"
}

// Symbol: PlayerPointers_getVehicleBodyCollisionData
// PAL: 0x8059081c..0x80590834
MARK_BINARY_BLOB(PlayerPointers_getVehicleBodyCollisionData, 0x8059081c, 0x80590834);
asm UNKNOWN_FUNCTION(PlayerPointers_getVehicleBodyCollisionData) {
#include "asm/8059081c.s"
}

// Symbol: PlayerPointers_getWheelCollisionData
// PAL: 0x80590834..0x8059084c
MARK_BINARY_BLOB(PlayerPointers_getWheelCollisionData, 0x80590834, 0x8059084c);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelCollisionData) {
#include "asm/80590834.s"
}

// Symbol: PlayerPointers_getPlayerSub18
// PAL: 0x8059084c..0x80590858
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub18, 0x8059084c, 0x80590858);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub18) {
#include "asm/8059084c.s"
}

// Symbol: unk_80590858
// PAL: 0x80590858..0x80590864
MARK_BINARY_BLOB(unk_80590858, 0x80590858, 0x80590864);
asm UNKNOWN_FUNCTION(unk_80590858) {
#include "asm/80590858.s"
}

// Symbol: unk_80590864
// PAL: 0x80590864..0x80590874
MARK_BINARY_BLOB(unk_80590864, 0x80590864, 0x80590874);
asm UNKNOWN_FUNCTION(unk_80590864) {
#include "asm/80590864.s"
}

// Symbol: PlayerPointers_getPlayerStats
// PAL: 0x80590874..0x80590888
MARK_BINARY_BLOB(PlayerPointers_getPlayerStats, 0x80590874, 0x80590888);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerStats) {
#include "asm/80590874.s"
}

// Symbol: PlayerPointers_getBsp
// PAL: 0x80590888..0x8059089c
MARK_BINARY_BLOB(PlayerPointers_getBsp, 0x80590888, 0x8059089c);
asm UNKNOWN_FUNCTION(PlayerPointers_getBsp) {
#include "asm/80590888.s"
}

// Symbol: unk_8059089c
// PAL: 0x8059089c..0x805908b4
MARK_BINARY_BLOB(unk_8059089c, 0x8059089c, 0x805908b4);
asm UNKNOWN_FUNCTION(unk_8059089c) {
#include "asm/8059089c.s"
}

// Symbol: PlayerPointers_getBspWheel
// PAL: 0x805908b4..0x805908d4
MARK_BINARY_BLOB(PlayerPointers_getBspWheel, 0x805908b4, 0x805908d4);
asm UNKNOWN_FUNCTION(PlayerPointers_getBspWheel) {
#include "asm/805908b4.s"
}

// Symbol: unk_805908d4
// PAL: 0x805908d4..0x805908e4
MARK_BINARY_BLOB(unk_805908d4, 0x805908d4, 0x805908e4);
asm UNKNOWN_FUNCTION(unk_805908d4) {
#include "asm/805908d4.s"
}

// Symbol: PlayerPointers_getKartDriverDispParams
// PAL: 0x805908e4..0x805908f4
MARK_BINARY_BLOB(PlayerPointers_getKartDriverDispParams, 0x805908e4, 0x805908f4);
asm UNKNOWN_FUNCTION(PlayerPointers_getKartDriverDispParams) {
#include "asm/805908e4.s"
}

// Symbol: unk_805908f4
// PAL: 0x805908f4..0x8059090c
MARK_BINARY_BLOB(unk_805908f4, 0x805908f4, 0x8059090c);
asm UNKNOWN_FUNCTION(unk_805908f4) {
#include "asm/805908f4.s"
}

// Symbol: various_stuff_get_kart_parts_disp_params
// PAL: 0x8059090c..0x8059091c
MARK_BINARY_BLOB(various_stuff_get_kart_parts_disp_params, 0x8059090c, 0x8059091c);
asm UNKNOWN_FUNCTION(various_stuff_get_kart_parts_disp_params) {
#include "asm/8059090c.s"
}

// Symbol: various_stuff_get_bike_parts_disp_params
// PAL: 0x8059091c..0x8059092c
MARK_BINARY_BLOB(various_stuff_get_bike_parts_disp_params, 0x8059091c, 0x8059092c);
asm UNKNOWN_FUNCTION(various_stuff_get_bike_parts_disp_params) {
#include "asm/8059091c.s"
}

// Symbol: unk_8059092c
// PAL: 0x8059092c..0x80590958
MARK_BINARY_BLOB(unk_8059092c, 0x8059092c, 0x80590958);
asm UNKNOWN_FUNCTION(unk_8059092c) {
#include "asm/8059092c.s"
}

// Symbol: unk_80590958
// PAL: 0x80590958..0x8059098c
MARK_BINARY_BLOB(unk_80590958, 0x80590958, 0x8059098c);
asm UNKNOWN_FUNCTION(unk_80590958) {
#include "asm/80590958.s"
}

// Symbol: unk_8059098c
// PAL: 0x8059098c..0x805909b8
MARK_BINARY_BLOB(unk_8059098c, 0x8059098c, 0x805909b8);
asm UNKNOWN_FUNCTION(unk_8059098c) {
#include "asm/8059098c.s"
}

// Symbol: unk_805909b8
// PAL: 0x805909b8..0x805909c8
MARK_BINARY_BLOB(unk_805909b8, 0x805909b8, 0x805909c8);
asm UNKNOWN_FUNCTION(unk_805909b8) {
#include "asm/805909b8.s"
}

// Symbol: unk_805909c8
// PAL: 0x805909c8..0x805909f4
MARK_BINARY_BLOB(unk_805909c8, 0x805909c8, 0x805909f4);
asm UNKNOWN_FUNCTION(unk_805909c8) {
#include "asm/805909c8.s"
}

// Symbol: unk_805909f4
// PAL: 0x805909f4..0x80590a04
MARK_BINARY_BLOB(unk_805909f4, 0x805909f4, 0x80590a04);
asm UNKNOWN_FUNCTION(unk_805909f4) {
#include "asm/805909f4.s"
}

// Symbol: unk_80590a04
// PAL: 0x80590a04..0x80590a10
MARK_BINARY_BLOB(unk_80590a04, 0x80590a04, 0x80590a10);
asm UNKNOWN_FUNCTION(unk_80590a04) {
#include "asm/80590a04.s"
}

// Symbol: PlayerPointers_getVehicleType
// PAL: 0x80590a10..0x80590a28
MARK_BINARY_BLOB(PlayerPointers_getVehicleType, 0x80590a10, 0x80590a28);
asm UNKNOWN_FUNCTION(PlayerPointers_getVehicleType) {
#include "asm/80590a10.s"
}

// Symbol: unk_80590a28
// PAL: 0x80590a28..0x80590a40
MARK_BINARY_BLOB(unk_80590a28, 0x80590a28, 0x80590a40);
asm UNKNOWN_FUNCTION(unk_80590a28) {
#include "asm/80590a28.s"
}

// Symbol: PlayerPointers_getModel
// PAL: 0x80590a40..0x80590a4c
MARK_BINARY_BLOB(PlayerPointers_getModel, 0x80590a40, 0x80590a4c);
asm UNKNOWN_FUNCTION(PlayerPointers_getModel) {
#include "asm/80590a40.s"
}

// Symbol: unk_80590a4c
// PAL: 0x80590a4c..0x80590a5c
MARK_BINARY_BLOB(unk_80590a4c, 0x80590a4c, 0x80590a5c);
asm UNKNOWN_FUNCTION(unk_80590a4c) {
#include "asm/80590a4c.s"
}

// Symbol: PlayerPointers_getPlayerIdx
// PAL: 0x80590a5c..0x80590a6c
MARK_BINARY_BLOB(PlayerPointers_getPlayerIdx, 0x80590a5c, 0x80590a6c);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerIdx) {
#include "asm/80590a5c.s"
}

// Symbol: PlayerPointers_isBike
// PAL: 0x80590a6c..0x80590a7c
MARK_BINARY_BLOB(PlayerPointers_isBike, 0x80590a6c, 0x80590a7c);
asm UNKNOWN_FUNCTION(PlayerPointers_isBike) {
#include "asm/80590a6c.s"
}

// Symbol: PlayerPointers_getVehicle
// PAL: 0x80590a7c..0x80590a8c
MARK_BINARY_BLOB(PlayerPointers_getVehicle, 0x80590a7c, 0x80590a8c);
asm UNKNOWN_FUNCTION(PlayerPointers_getVehicle) {
#include "asm/80590a7c.s"
}

// Symbol: unk_80590a8c
// PAL: 0x80590a8c..0x80590a9c
MARK_BINARY_BLOB(unk_80590a8c, 0x80590a8c, 0x80590a9c);
asm UNKNOWN_FUNCTION(unk_80590a8c) {
#include "asm/80590a8c.s"
}

// Symbol: unk_80590a9c
// PAL: 0x80590a9c..0x80590c44
MARK_BINARY_BLOB(unk_80590a9c, 0x80590a9c, 0x80590c44);
asm UNKNOWN_FUNCTION(unk_80590a9c) {
#include "asm/80590a9c.s"
}

// Symbol: PlayerPointers_getPlayerMatCol0
// PAL: 0x80590c44..0x80590c6c
MARK_BINARY_BLOB(PlayerPointers_getPlayerMatCol0, 0x80590c44, 0x80590c6c);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0) {
#include "asm/80590c44.s"
}

// Symbol: unk_80590c6c
// PAL: 0x80590c6c..0x80590c94
MARK_BINARY_BLOB(unk_80590c6c, 0x80590c6c, 0x80590c94);
asm UNKNOWN_FUNCTION(unk_80590c6c) {
#include "asm/80590c6c.s"
}

// Symbol: PlayerPointers_getBodyFront
// PAL: 0x80590c94..0x80590cbc
MARK_BINARY_BLOB(PlayerPointers_getBodyFront, 0x80590c94, 0x80590cbc);
asm UNKNOWN_FUNCTION(PlayerPointers_getBodyFront) {
#include "asm/80590c94.s"
}

// Symbol: unk_80590cbc
// PAL: 0x80590cbc..0x80590cd0
MARK_BINARY_BLOB(unk_80590cbc, 0x80590cbc, 0x80590cd0);
asm UNKNOWN_FUNCTION(unk_80590cbc) {
#include "asm/80590cbc.s"
}

// Symbol: unk_80590cd0
// PAL: 0x80590cd0..0x80590ce4
MARK_BINARY_BLOB(unk_80590cd0, 0x80590cd0, 0x80590ce4);
asm UNKNOWN_FUNCTION(unk_80590cd0) {
#include "asm/80590cd0.s"
}

// Symbol: PlayerPointers_getMalCol2
// PAL: 0x80590ce4..0x80590cf8
MARK_BINARY_BLOB(PlayerPointers_getMalCol2, 0x80590ce4, 0x80590cf8);
asm UNKNOWN_FUNCTION(PlayerPointers_getMalCol2) {
#include "asm/80590ce4.s"
}

// Symbol: PlayerPointers_getPlayerSub10Speed
// PAL: 0x80590cf8..0x80590d08
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub10Speed, 0x80590cf8, 0x80590d08);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub10Speed) {
#include "asm/80590cf8.s"
}

// Symbol: playerPointers_getSpeed
// PAL: 0x80590d08..0x80590d20
MARK_BINARY_BLOB(playerPointers_getSpeed, 0x80590d08, 0x80590d20);
asm UNKNOWN_FUNCTION(playerPointers_getSpeed) {
#include "asm/80590d08.s"
}

// Symbol: PlayerPointers_getPlayerSub14
// PAL: 0x80590d20..0x80590d2c
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub14, 0x80590d20, 0x80590d2c);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub14) {
#include "asm/80590d20.s"
}

// Symbol: unk_80590d2c
// PAL: 0x80590d2c..0x80590d38
MARK_BINARY_BLOB(unk_80590d2c, 0x80590d2c, 0x80590d38);
asm UNKNOWN_FUNCTION(unk_80590d2c) {
#include "asm/80590d2c.s"
}

// Symbol: unk_80590d38
// PAL: 0x80590d38..0x80590d5c
MARK_BINARY_BLOB(unk_80590d38, 0x80590d38, 0x80590d5c);
asm UNKNOWN_FUNCTION(unk_80590d38) {
#include "asm/80590d38.s"
}

// Symbol: unk_80590d5c
// PAL: 0x80590d5c..0x80590d88
MARK_BINARY_BLOB(unk_80590d5c, 0x80590d5c, 0x80590d88);
asm UNKNOWN_FUNCTION(unk_80590d5c) {
#include "asm/80590d5c.s"
}

// Symbol: unk_80590d88
// PAL: 0x80590d88..0x80590d94
MARK_BINARY_BLOB(unk_80590d88, 0x80590d88, 0x80590d94);
asm UNKNOWN_FUNCTION(unk_80590d88) {
#include "asm/80590d88.s"
}

// Symbol: unk_80590d94
// PAL: 0x80590d94..0x80590da4
MARK_BINARY_BLOB(unk_80590d94, 0x80590d94, 0x80590da4);
asm UNKNOWN_FUNCTION(unk_80590d94) {
#include "asm/80590d94.s"
}

// Symbol: unk_80590da4
// PAL: 0x80590da4..0x80590db4
MARK_BINARY_BLOB(unk_80590da4, 0x80590da4, 0x80590db4);
asm UNKNOWN_FUNCTION(unk_80590da4) {
#include "asm/80590da4.s"
}

// Symbol: unk_80590db4
// PAL: 0x80590db4..0x80590dc0
MARK_BINARY_BLOB(unk_80590db4, 0x80590db4, 0x80590dc0);
asm UNKNOWN_FUNCTION(unk_80590db4) {
#include "asm/80590db4.s"
}

// Symbol: PlayerPointers_getSpeedRatioCapped
// PAL: 0x80590dc0..0x80590dd0
MARK_BINARY_BLOB(PlayerPointers_getSpeedRatioCapped, 0x80590dc0, 0x80590dd0);
asm UNKNOWN_FUNCTION(PlayerPointers_getSpeedRatioCapped) {
#include "asm/80590dc0.s"
}

// Symbol: unk_80590dd0
// PAL: 0x80590dd0..0x80590de0
MARK_BINARY_BLOB(unk_80590dd0, 0x80590dd0, 0x80590de0);
asm UNKNOWN_FUNCTION(unk_80590dd0) {
#include "asm/80590dd0.s"
}

// Symbol: unk_80590de0
// PAL: 0x80590de0..0x80590df8
MARK_BINARY_BLOB(unk_80590de0, 0x80590de0, 0x80590df8);
asm UNKNOWN_FUNCTION(unk_80590de0) {
#include "asm/80590de0.s"
}

// Symbol: PlayerPointers_setCamera
// PAL: 0x80590df8..0x80590e04
MARK_BINARY_BLOB(PlayerPointers_setCamera, 0x80590df8, 0x80590e04);
asm UNKNOWN_FUNCTION(PlayerPointers_setCamera) {
#include "asm/80590df8.s"
}

// Symbol: unk_80590e04
// PAL: 0x80590e04..0x80590e28
MARK_BINARY_BLOB(unk_80590e04, 0x80590e04, 0x80590e28);
asm UNKNOWN_FUNCTION(unk_80590e04) {
#include "asm/80590e04.s"
}

// Symbol: unk_80590e28
// PAL: 0x80590e28..0x80590e40
MARK_BINARY_BLOB(unk_80590e28, 0x80590e28, 0x80590e40);
asm UNKNOWN_FUNCTION(unk_80590e28) {
#include "asm/80590e28.s"
}

// Symbol: unk_80590e40
// PAL: 0x80590e40..0x80590e58
MARK_BINARY_BLOB(unk_80590e40, 0x80590e40, 0x80590e58);
asm UNKNOWN_FUNCTION(unk_80590e40) {
#include "asm/80590e40.s"
}

// Symbol: unk_80590e58
// PAL: 0x80590e58..0x80590e70
MARK_BINARY_BLOB(unk_80590e58, 0x80590e58, 0x80590e70);
asm UNKNOWN_FUNCTION(unk_80590e58) {
#include "asm/80590e58.s"
}

// Symbol: unk_80590e70
// PAL: 0x80590e70..0x80590e88
MARK_BINARY_BLOB(unk_80590e70, 0x80590e70, 0x80590e88);
asm UNKNOWN_FUNCTION(unk_80590e70) {
#include "asm/80590e70.s"
}

// Symbol: unk_80590e88
// PAL: 0x80590e88..0x80590e8c
MARK_BINARY_BLOB(unk_80590e88, 0x80590e88, 0x80590e8c);
asm UNKNOWN_FUNCTION(unk_80590e88) {
#include "asm/80590e88.s"
}

// Symbol: unk_80590e8c
// PAL: 0x80590e8c..0x80590ea4
MARK_BINARY_BLOB(unk_80590e8c, 0x80590e8c, 0x80590ea4);
asm UNKNOWN_FUNCTION(unk_80590e8c) {
#include "asm/80590e8c.s"
}

// Symbol: unk_80590ea4
// PAL: 0x80590ea4..0x80590ed8
MARK_BINARY_BLOB(unk_80590ea4, 0x80590ea4, 0x80590ed8);
asm UNKNOWN_FUNCTION(unk_80590ea4) {
#include "asm/80590ea4.s"
}

// Symbol: unk_80590ed8
// PAL: 0x80590ed8..0x80590ef8
MARK_BINARY_BLOB(unk_80590ed8, 0x80590ed8, 0x80590ef8);
asm UNKNOWN_FUNCTION(unk_80590ed8) {
#include "asm/80590ed8.s"
}

// Symbol: unk_80590ef8
// PAL: 0x80590ef8..0x80590f18
MARK_BINARY_BLOB(unk_80590ef8, 0x80590ef8, 0x80590f18);
asm UNKNOWN_FUNCTION(unk_80590ef8) {
#include "asm/80590ef8.s"
}

// Symbol: unk_80590f18
// PAL: 0x80590f18..0x80590f38
MARK_BINARY_BLOB(unk_80590f18, 0x80590f18, 0x80590f38);
asm UNKNOWN_FUNCTION(unk_80590f18) {
#include "asm/80590f18.s"
}

// Symbol: unk_80590f38
// PAL: 0x80590f38..0x80590f58
MARK_BINARY_BLOB(unk_80590f38, 0x80590f38, 0x80590f58);
asm UNKNOWN_FUNCTION(unk_80590f38) {
#include "asm/80590f38.s"
}

// Symbol: unk_80590f58
// PAL: 0x80590f58..0x80590f70
MARK_BINARY_BLOB(unk_80590f58, 0x80590f58, 0x80590f70);
asm UNKNOWN_FUNCTION(unk_80590f58) {
#include "asm/80590f58.s"
}

// Symbol: unk_80590f70
// PAL: 0x80590f70..0x80590f90
MARK_BINARY_BLOB(unk_80590f70, 0x80590f70, 0x80590f90);
asm UNKNOWN_FUNCTION(unk_80590f70) {
#include "asm/80590f70.s"
}

// Symbol: unk_80590f90
// PAL: 0x80590f90..0x80590f9c
MARK_BINARY_BLOB(unk_80590f90, 0x80590f90, 0x80590f9c);
asm UNKNOWN_FUNCTION(unk_80590f90) {
#include "asm/80590f90.s"
}

// Symbol: unk_80590f9c
// PAL: 0x80590f9c..0x8059102c
MARK_BINARY_BLOB(unk_80590f9c, 0x80590f9c, 0x8059102c);
asm UNKNOWN_FUNCTION(unk_80590f9c) {
#include "asm/80590f9c.s"
}

// Symbol: unk_8059102c
// PAL: 0x8059102c..0x80591038
MARK_BINARY_BLOB(unk_8059102c, 0x8059102c, 0x80591038);
asm UNKNOWN_FUNCTION(unk_8059102c) {
#include "asm/8059102c.s"
}

// Symbol: unk_80591038
// PAL: 0x80591038..0x80591044
MARK_BINARY_BLOB(unk_80591038, 0x80591038, 0x80591044);
asm UNKNOWN_FUNCTION(unk_80591038) {
#include "asm/80591038.s"
}

// Symbol: unk_80591044
// PAL: 0x80591044..0x80591050
MARK_BINARY_BLOB(unk_80591044, 0x80591044, 0x80591050);
asm UNKNOWN_FUNCTION(unk_80591044) {
#include "asm/80591044.s"
}

// Symbol: unk_80591050
// PAL: 0x80591050..0x80591070
MARK_BINARY_BLOB(unk_80591050, 0x80591050, 0x80591070);
asm UNKNOWN_FUNCTION(unk_80591050) {
#include "asm/80591050.s"
}

// Symbol: unk_80591070
// PAL: 0x80591070..0x8059107c
MARK_BINARY_BLOB(unk_80591070, 0x80591070, 0x8059107c);
asm UNKNOWN_FUNCTION(unk_80591070) {
#include "asm/80591070.s"
}

// Symbol: unk_8059107c
// PAL: 0x8059107c..0x8059108c
MARK_BINARY_BLOB(unk_8059107c, 0x8059107c, 0x8059108c);
asm UNKNOWN_FUNCTION(unk_8059107c) {
#include "asm/8059107c.s"
}

// Symbol: unk_8059108c
// PAL: 0x8059108c..0x80591098
MARK_BINARY_BLOB(unk_8059108c, 0x8059108c, 0x80591098);
asm UNKNOWN_FUNCTION(unk_8059108c) {
#include "asm/8059108c.s"
}

// Symbol: unk_80591098
// PAL: 0x80591098..0x805910a4
MARK_BINARY_BLOB(unk_80591098, 0x80591098, 0x805910a4);
asm UNKNOWN_FUNCTION(unk_80591098) {
#include "asm/80591098.s"
}

// Symbol: unk_805910a4
// PAL: 0x805910a4..0x805910b0
MARK_BINARY_BLOB(unk_805910a4, 0x805910a4, 0x805910b0);
asm UNKNOWN_FUNCTION(unk_805910a4) {
#include "asm/805910a4.s"
}

// Symbol: unk_805910b0
// PAL: 0x805910b0..0x805910c0
MARK_BINARY_BLOB(unk_805910b0, 0x805910b0, 0x805910c0);
asm UNKNOWN_FUNCTION(unk_805910b0) {
#include "asm/805910b0.s"
}

// Symbol: PlayerPointers_getPlayerSub20
// PAL: 0x805910c0..0x805910cc
MARK_BINARY_BLOB(PlayerPointers_getPlayerSub20, 0x805910c0, 0x805910cc);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerSub20) {
#include "asm/805910c0.s"
}

// Symbol: unk_805910cc
// PAL: 0x805910cc..0x805910e4
MARK_BINARY_BLOB(unk_805910cc, 0x805910cc, 0x805910e4);
asm UNKNOWN_FUNCTION(unk_805910cc) {
#include "asm/805910cc.s"
}

// Symbol: unk_805910e4
// PAL: 0x805910e4..0x805910fc
MARK_BINARY_BLOB(unk_805910e4, 0x805910e4, 0x805910fc);
asm UNKNOWN_FUNCTION(unk_805910e4) {
#include "asm/805910e4.s"
}

// Symbol: unk_805910fc
// PAL: 0x805910fc..0x80591138
MARK_BINARY_BLOB(unk_805910fc, 0x805910fc, 0x80591138);
asm UNKNOWN_FUNCTION(unk_805910fc) {
#include "asm/805910fc.s"
}

// Symbol: unk_80591138
// PAL: 0x80591138..0x80591170
MARK_BINARY_BLOB(unk_80591138, 0x80591138, 0x80591170);
asm UNKNOWN_FUNCTION(unk_80591138) {
#include "asm/80591138.s"
}

// Symbol: unk_80591170
// PAL: 0x80591170..0x805911a8
MARK_BINARY_BLOB(unk_80591170, 0x80591170, 0x805911a8);
asm UNKNOWN_FUNCTION(unk_80591170) {
#include "asm/80591170.s"
}

// Symbol: unk_805911a8
// PAL: 0x805911a8..0x805911c0
MARK_BINARY_BLOB(unk_805911a8, 0x805911a8, 0x805911c0);
asm UNKNOWN_FUNCTION(unk_805911a8) {
#include "asm/805911a8.s"
}

// Symbol: unk_805911c0
// PAL: 0x805911c0..0x805911d8
MARK_BINARY_BLOB(unk_805911c0, 0x805911c0, 0x805911d8);
asm UNKNOWN_FUNCTION(unk_805911c0) {
#include "asm/805911c0.s"
}

// Symbol: unk_805911d8
// PAL: 0x805911d8..0x805911e8
MARK_BINARY_BLOB(unk_805911d8, 0x805911d8, 0x805911e8);
asm UNKNOWN_FUNCTION(unk_805911d8) {
#include "asm/805911d8.s"
}

// Symbol: unk_805911e8
// PAL: 0x805911e8..0x805911f8
MARK_BINARY_BLOB(unk_805911e8, 0x805911e8, 0x805911f8);
asm UNKNOWN_FUNCTION(unk_805911e8) {
#include "asm/805911e8.s"
}

// Symbol: unk_805911f8
// PAL: 0x805911f8..0x80591208
MARK_BINARY_BLOB(unk_805911f8, 0x805911f8, 0x80591208);
asm UNKNOWN_FUNCTION(unk_805911f8) {
#include "asm/805911f8.s"
}

// Symbol: unk_80591208
// PAL: 0x80591208..0x80591214
MARK_BINARY_BLOB(unk_80591208, 0x80591208, 0x80591214);
asm UNKNOWN_FUNCTION(unk_80591208) {
#include "asm/80591208.s"
}

// Symbol: unk_80591214
// PAL: 0x80591214..0x80591220
MARK_BINARY_BLOB(unk_80591214, 0x80591214, 0x80591220);
asm UNKNOWN_FUNCTION(unk_80591214) {
#include "asm/80591214.s"
}

// Symbol: unk_80591220
// PAL: 0x80591220..0x80591264
MARK_BINARY_BLOB(unk_80591220, 0x80591220, 0x80591264);
asm UNKNOWN_FUNCTION(unk_80591220) {
#include "asm/80591220.s"
}

// Symbol: unk_80591264
// PAL: 0x80591264..0x80591314
MARK_BINARY_BLOB(unk_80591264, 0x80591264, 0x80591314);
asm UNKNOWN_FUNCTION(unk_80591264) {
#include "asm/80591264.s"
}

// Symbol: unk_80591314
// PAL: 0x80591314..0x80591344
MARK_BINARY_BLOB(unk_80591314, 0x80591314, 0x80591344);
asm UNKNOWN_FUNCTION(unk_80591314) {
#include "asm/80591314.s"
}

// Symbol: unk_80591344
// PAL: 0x80591344..0x80591378
MARK_BINARY_BLOB(unk_80591344, 0x80591344, 0x80591378);
asm UNKNOWN_FUNCTION(unk_80591344) {
#include "asm/80591344.s"
}

// Symbol: unk_80591378
// PAL: 0x80591378..0x805913a8
MARK_BINARY_BLOB(unk_80591378, 0x80591378, 0x805913a8);
asm UNKNOWN_FUNCTION(unk_80591378) {
#include "asm/80591378.s"
}

// Symbol: unk_805913a8
// PAL: 0x805913a8..0x805913fc
MARK_BINARY_BLOB(unk_805913a8, 0x805913a8, 0x805913fc);
asm UNKNOWN_FUNCTION(unk_805913a8) {
#include "asm/805913a8.s"
}

// Symbol: unk_805913fc
// PAL: 0x805913fc..0x80591418
MARK_BINARY_BLOB(unk_805913fc, 0x805913fc, 0x80591418);
asm UNKNOWN_FUNCTION(unk_805913fc) {
#include "asm/805913fc.s"
}

// Symbol: unk_80591418
// PAL: 0x80591418..0x80591428
MARK_BINARY_BLOB(unk_80591418, 0x80591418, 0x80591428);
asm UNKNOWN_FUNCTION(unk_80591418) {
#include "asm/80591418.s"
}

// Symbol: unk_80591428
// PAL: 0x80591428..0x80591434
MARK_BINARY_BLOB(unk_80591428, 0x80591428, 0x80591434);
asm UNKNOWN_FUNCTION(unk_80591428) {
#include "asm/80591428.s"
}

// Symbol: unk_80591434
// PAL: 0x80591434..0x80591440
MARK_BINARY_BLOB(unk_80591434, 0x80591434, 0x80591440);
asm UNKNOWN_FUNCTION(unk_80591434) {
#include "asm/80591434.s"
}

// Symbol: PlayerPointers_getRacedataFactory
// PAL: 0x80591440..0x8059144c
MARK_BINARY_BLOB(PlayerPointers_getRacedataFactory, 0x80591440, 0x8059144c);
asm UNKNOWN_FUNCTION(PlayerPointers_getRacedataFactory) {
#include "asm/80591440.s"
}

// Symbol: PlayerPointers_getRacedataHandler
// PAL: 0x8059144c..0x80591458
MARK_BINARY_BLOB(PlayerPointers_getRacedataHandler, 0x8059144c, 0x80591458);
asm UNKNOWN_FUNCTION(PlayerPointers_getRacedataHandler) {
#include "asm/8059144c.s"
}

// Symbol: PlayerPointers_getRacedataFactoryFlags
// PAL: 0x80591458..0x80591468
MARK_BINARY_BLOB(PlayerPointers_getRacedataFactoryFlags, 0x80591458, 0x80591468);
asm UNKNOWN_FUNCTION(PlayerPointers_getRacedataFactoryFlags) {
#include "asm/80591458.s"
}

// Symbol: unk_80591468
// PAL: 0x80591468..0x80591478
MARK_BINARY_BLOB(unk_80591468, 0x80591468, 0x80591478);
asm UNKNOWN_FUNCTION(unk_80591468) {
#include "asm/80591468.s"
}

// Symbol: unk_80591478
// PAL: 0x80591478..0x805914bc
MARK_BINARY_BLOB(unk_80591478, 0x80591478, 0x805914bc);
asm UNKNOWN_FUNCTION(unk_80591478) {
  #include "asm/80591478.s"
}

// Symbol: PlayerPointers_getScale
// PAL: 0x805914bc..0x805914cc
MARK_BINARY_BLOB(PlayerPointers_getScale, 0x805914bc, 0x805914cc);
asm UNKNOWN_FUNCTION(PlayerPointers_getScale) {
#include "asm/805914bc.s"
}

// Symbol: unk_805914cc
// PAL: 0x805914cc..0x805914e4
MARK_BINARY_BLOB(unk_805914cc, 0x805914cc, 0x805914e4);
asm UNKNOWN_FUNCTION(unk_805914cc) {
#include "asm/805914cc.s"
}

// Symbol: unk_805914e4
// PAL: 0x805914e4..0x805914f4
MARK_BINARY_BLOB(unk_805914e4, 0x805914e4, 0x805914f4);
asm UNKNOWN_FUNCTION(unk_805914e4) {
#include "asm/805914e4.s"
}

// Symbol: unk_805914f4
// PAL: 0x805914f4..0x80591520
MARK_BINARY_BLOB(unk_805914f4, 0x805914f4, 0x80591520);
asm UNKNOWN_FUNCTION(unk_805914f4) {
#include "asm/805914f4.s"
}

// Symbol: PlayerPointers_getEntity
// PAL: 0x80591520..0x8059152c
MARK_BINARY_BLOB(PlayerPointers_getEntity, 0x80591520, 0x8059152c);
asm UNKNOWN_FUNCTION(PlayerPointers_getEntity) {
#include "asm/80591520.s"
}

// Symbol: unk_8059152c
// PAL: 0x8059152c..0x80591538
MARK_BINARY_BLOB(unk_8059152c, 0x8059152c, 0x80591538);
asm UNKNOWN_FUNCTION(unk_8059152c) {
#include "asm/8059152c.s"
}

// Symbol: unk_80591538
// PAL: 0x80591538..0x80591608
MARK_BINARY_BLOB(unk_80591538, 0x80591538, 0x80591608);
asm UNKNOWN_FUNCTION(unk_80591538) {
#include "asm/80591538.s"
}

// Symbol: unk_80591608
// PAL: 0x80591608..0x80591618
MARK_BINARY_BLOB(unk_80591608, 0x80591608, 0x80591618);
asm UNKNOWN_FUNCTION(unk_80591608) {
#include "asm/80591608.s"
}

// Symbol: unk_80591618
// PAL: 0x80591618..0x80591624
MARK_BINARY_BLOB(unk_80591618, 0x80591618, 0x80591624);
asm UNKNOWN_FUNCTION(unk_80591618) {
#include "asm/80591618.s"
}

// Symbol: unk_80591624
// PAL: 0x80591624..0x80591650
MARK_BINARY_BLOB(unk_80591624, 0x80591624, 0x80591650);
asm UNKNOWN_FUNCTION(unk_80591624) {
#include "asm/80591624.s"
}

// Symbol: unk_80591650
// PAL: 0x80591650..0x80591664
MARK_BINARY_BLOB(unk_80591650, 0x80591650, 0x80591664);
asm UNKNOWN_FUNCTION(unk_80591650) {
#include "asm/80591650.s"
}

// Symbol: PlayerPointers_resetInertia
// PAL: 0x80591664..0x8059170c
MARK_BINARY_BLOB(PlayerPointers_resetInertia, 0x80591664, 0x8059170c);
asm UNKNOWN_FUNCTION(PlayerPointers_resetInertia) {
#include "asm/80591664.s"
}

// Symbol: unk_8059170c
// PAL: 0x8059170c..0x80591784
MARK_BINARY_BLOB(unk_8059170c, 0x8059170c, 0x80591784);
asm UNKNOWN_FUNCTION(unk_8059170c) {
#include "asm/8059170c.s"
}

// Symbol: unk_80591784
// PAL: 0x80591784..0x805917a0
MARK_BINARY_BLOB(unk_80591784, 0x80591784, 0x805917a0);
asm UNKNOWN_FUNCTION(unk_80591784) {
#include "asm/80591784.s"
}

// Symbol: PlayerPointers_getOobWipeState
// PAL: 0x805917a0..0x805917b0
MARK_BINARY_BLOB(PlayerPointers_getOobWipeState, 0x805917a0, 0x805917b0);
asm UNKNOWN_FUNCTION(PlayerPointers_getOobWipeState) {
#include "asm/805917a0.s"
}

// Symbol: unk_805917b0
// PAL: 0x805917b0..0x805917c0
MARK_BINARY_BLOB(unk_805917b0, 0x805917b0, 0x805917c0);
asm UNKNOWN_FUNCTION(unk_805917b0) {
#include "asm/805917b0.s"
}

// Symbol: unk_805917c0
// PAL: 0x805917c0..0x805917f4
MARK_BINARY_BLOB(unk_805917c0, 0x805917c0, 0x805917f4);
asm UNKNOWN_FUNCTION(unk_805917c0) {
#include "asm/805917c0.s"
}

// Symbol: unk_805917f4
// PAL: 0x805917f4..0x80591828
MARK_BINARY_BLOB(unk_805917f4, 0x805917f4, 0x80591828);
asm UNKNOWN_FUNCTION(unk_805917f4) {
#include "asm/805917f4.s"
}

// Symbol: unk_80591828
// PAL: 0x80591828..0x8059184c
MARK_BINARY_BLOB(unk_80591828, 0x80591828, 0x8059184c);
asm UNKNOWN_FUNCTION(unk_80591828) {
#include "asm/80591828.s"
}

// Symbol: unk_8059184c
// PAL: 0x8059184c..0x80591898
MARK_BINARY_BLOB(unk_8059184c, 0x8059184c, 0x80591898);
asm UNKNOWN_FUNCTION(unk_8059184c) {
#include "asm/8059184c.s"
}

// Symbol: unk_80591898
// PAL: 0x80591898..0x805918bc
MARK_BINARY_BLOB(unk_80591898, 0x80591898, 0x805918bc);
asm UNKNOWN_FUNCTION(unk_80591898) {
#include "asm/80591898.s"
}

// Symbol: unk_805918bc
// PAL: 0x805918bc..0x805918e0
MARK_BINARY_BLOB(unk_805918bc, 0x805918bc, 0x805918e0);
asm UNKNOWN_FUNCTION(unk_805918bc) {
#include "asm/805918bc.s"
}

// Symbol: unk_805918e0
// PAL: 0x805918e0..0x80591904
MARK_BINARY_BLOB(unk_805918e0, 0x805918e0, 0x80591904);
asm UNKNOWN_FUNCTION(unk_805918e0) {
#include "asm/805918e0.s"
}

// Symbol: PlayerPointers_getPlayerZipper
// PAL: 0x80591904..0x80591914
MARK_BINARY_BLOB(PlayerPointers_getPlayerZipper, 0x80591904, 0x80591914);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerZipper) {
#include "asm/80591904.s"
}

// Symbol: PlayerPointers_getPlayerTrick
// PAL: 0x80591914..0x80591924
MARK_BINARY_BLOB(PlayerPointers_getPlayerTrick, 0x80591914, 0x80591924);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerTrick) {
#include "asm/80591914.s"
}

// Symbol: unk_80591924
// PAL: 0x80591924..0x8059197c
MARK_BINARY_BLOB(unk_80591924, 0x80591924, 0x8059197c);
asm UNKNOWN_FUNCTION(unk_80591924) {
#include "asm/80591924.s"
}

// Symbol: unk_8059197c
// PAL: 0x8059197c..0x80591998
MARK_BINARY_BLOB(unk_8059197c, 0x8059197c, 0x80591998);
asm UNKNOWN_FUNCTION(unk_8059197c) {
#include "asm/8059197c.s"
}

// Symbol: unk_80591998
// PAL: 0x80591998..0x805919e8
MARK_BINARY_BLOB(unk_80591998, 0x80591998, 0x805919e8);
asm UNKNOWN_FUNCTION(unk_80591998) {
#include "asm/80591998.s"
}

// Symbol: unk_805919e8
// PAL: 0x805919e8..0x805919f4
MARK_BINARY_BLOB(unk_805919e8, 0x805919e8, 0x805919f4);
asm UNKNOWN_FUNCTION(unk_805919e8) {
#include "asm/805919e8.s"
}

