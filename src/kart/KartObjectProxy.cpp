#include "KartObjectProxy.hpp"
#include <cstddef>

#include <kart/KartMove.hpp>
#include <kart/KartBody.hpp>
#include <kart/KartDynamics.hpp>
#include <kart/KartWheel.hpp>
#include <kart/KartWheelPhysics.hpp>

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x800aef60
extern UNKNOWN_FUNCTION(List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs);
// PAL: 0x800aef80
extern UNKNOWN_FUNCTION(List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv);
// PAL: 0x800af180
extern UNKNOWN_FUNCTION(List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv);
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
extern UNKNOWN_FUNCTION(getMaxMtCharge__Q24Kart8KartMoveFv);
// PAL: 0x8057efec
extern UNKNOWN_FUNCTION(getMaxSmtCharge__Q24Kart8KartMoveFv);
// PAL: 0x8057eff8
extern UNKNOWN_FUNCTION(getAppliedHopStickX__Q24Kart8KartMoveFv);
// PAL: 0x80581720
extern UNKNOWN_FUNCTION(setScale__Q24Kart8KartMoveFQ23EGG8Vector3f);
// PAL: 0x80581a24
extern UNKNOWN_FUNCTION(empty__Q24Kart8KartMoveFl);
// PAL: 0x805832e4
extern UNKNOWN_FUNCTION(clearBoost__Q24Kart8KartMoveFv);
// PAL: 0x8058d47c
extern UNKNOWN_FUNCTION(unk_8058d47c);
// PAL: 0x80590100
extern UNKNOWN_FUNCTION(PlayerHolder_getPlayer);
// PAL: 0x80590a9c
extern UNKNOWN_FUNCTION(unk_80590a9c);
// PAL: 0x805946f4
extern UNKNOWN_FUNCTION(PlayerSub1c_startOobWipe);
// PAL: 0x80599eac
extern UNKNOWN_FUNCTION(hasFloorCollision__Q24Kart16KartWheelPhysicsCFv);
// PAL: 0x80599ec8
extern UNKNOWN_FUNCTION(getKartCollisionInfo__Q24Kart16KartWheelPhysicsCFv);
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
extern UNKNOWN_FUNCTION(setInertia__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x808646f0
extern UNKNOWN_FUNCTION(unk_808646f0); // Extern data references.
// PAL: 0x80891c58
// extern UNKNOWN_DATA(lbl_80891c58);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd730
extern UNKNOWN_DATA(spInstance__Q26System11RaceManager);
// PAL: 0x809c18f8
extern UNKNOWN_DATA(lbl_809c18f8);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
extern const u32 lbl_80891c58;
const u32 lbl_80891c58 = 0;
const u32 lbl_80891c5c[] = {0x3f800000, 0x00000003, 0x00000004, 0x00000005,
                            0x00000025, 0x00000026, 0x00000014};
const u32 lbl_80891c78[] = {0x42c80000};
const u32 lbl_80891c7c[] = {0xc8c8c8ff};

nw4r::ut::List Kart::KartObjectProxy::sList;
extern u32 bss_809c190c;
u32 bss_809c190c;

namespace Kart {

void KartObjectProxy::InitList() {
  List_Init(&sList, offsetof(KartObjectProxy, mNode));
}

void KartObjectProxy::SetupInList(KartAccessor* accessor) {
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
asm UNKNOWN_FUNCTION(setupSingle){
#include "asm/805901d0.s"
}

/*// Symbol: getPos__Q24Kart15KartObjectProxyCFv
// PAL: 0x8059020c..0x80590224
MARK_BINARY_BLOB(getPos__Q24Kart15KartObjectProxyCFv, 0x8059020c, 0x80590224);
asm UNKNOWN_FUNCTION(getPos__Q24Kart15KartObjectProxyCFv){
#include "asm/8059020c.s"
}*/
namespace Kart {
const EGG::Vector3f& KartObjectProxy::getPos() const { return kartDynamics()->pos; }
}

// Symbol: PlayerPointers_getPlayerPhysicsHolderPosition
// PAL: 0x80590224..0x80590238
MARK_BINARY_BLOB(PlayerPointers_getPlayerPhysicsHolderPosition, 0x80590224,
                 0x80590238);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolderPosition){
#include "asm/80590224.s"
}

// Symbol: various_stuff_set_player_position
// PAL: 0x80590238..0x80590264
MARK_BINARY_BLOB(various_stuff_set_player_position, 0x80590238, 0x80590264);
asm UNKNOWN_FUNCTION(various_stuff_set_player_position){
#include "asm/80590238.s"
}

// Symbol: PlayerPointers_getMat
// PAL: 0x80590264..0x80590278
MARK_BINARY_BLOB(PlayerPointers_getMat, 0x80590264, 0x80590278);
asm UNKNOWN_FUNCTION(PlayerPointers_getMat){
#include "asm/80590264.s"
}

// Symbol: unk_80590278
// PAL: 0x80590278..0x80590288
MARK_BINARY_BLOB(unk_80590278, 0x80590278, 0x80590288);
asm UNKNOWN_FUNCTION(unk_80590278){
#include "asm/80590278.s"
}

// Symbol: various_stuff_set_player_rotation
// PAL: 0x80590288..0x805902dc
MARK_BINARY_BLOB(various_stuff_set_player_rotation, 0x80590288, 0x805902dc);
asm UNKNOWN_FUNCTION(various_stuff_set_player_rotation){
#include "asm/80590288.s"
}

// Symbol: PlayerPointers_getWheelCount0
// PAL: 0x805902dc..0x805902ec
MARK_BINARY_BLOB(PlayerPointers_getWheelCount0, 0x805902dc, 0x805902ec);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelCount0){
#include "asm/805902dc.s"
}

// Symbol: PlayerPointers_getWheelCount1
// PAL: 0x805902ec..0x805902fc
MARK_BINARY_BLOB(PlayerPointers_getWheelCount1, 0x805902ec, 0x805902fc);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelCount1){
#include "asm/805902ec.s"
}

// Symbol: unk_805902fc
// PAL: 0x805902fc..0x8059030c
MARK_BINARY_BLOB(unk_805902fc, 0x805902fc, 0x8059030c);
asm UNKNOWN_FUNCTION(unk_805902fc){
#include "asm/805902fc.s"
}

// Symbol: unk_8059030c
// PAL: 0x8059030c..0x8059031c
MARK_BINARY_BLOB(unk_8059030c, 0x8059030c, 0x8059031c);
asm UNKNOWN_FUNCTION(unk_8059030c){
#include "asm/8059030c.s"
}

// Symbol: unk_8059031c
// PAL: 0x8059031c..0x80590338
MARK_BINARY_BLOB(unk_8059031c, 0x8059031c, 0x80590338);
asm UNKNOWN_FUNCTION(unk_8059031c){
#include "asm/8059031c.s"
}

// Symbol: unk_80590338
// PAL: 0x80590338..0x80590350
MARK_BINARY_BLOB(unk_80590338, 0x80590338, 0x80590350);
asm UNKNOWN_FUNCTION(unk_80590338){
#include "asm/80590338.s"
}

// Symbol: unk_80590350
// PAL: 0x80590350..0x80590368
MARK_BINARY_BLOB(unk_80590350, 0x80590350, 0x80590368);
asm UNKNOWN_FUNCTION(unk_80590350){
#include "asm/80590350.s"
}

// Symbol: unk_80590368
// PAL: 0x80590368..0x80590380
MARK_BINARY_BLOB(unk_80590368, 0x80590368, 0x80590380);
asm UNKNOWN_FUNCTION(unk_80590368){
#include "asm/80590368.s"
}

// Symbol: unk_80590380
// PAL: 0x80590380..0x80590390
MARK_BINARY_BLOB(unk_80590380, 0x80590380, 0x80590390);
asm UNKNOWN_FUNCTION(unk_80590380){
#include "asm/80590380.s"
}

// Symbol: unk_80590390
// PAL: 0x80590390..0x805903ac
MARK_BINARY_BLOB(unk_80590390, 0x80590390, 0x805903ac);
asm UNKNOWN_FUNCTION(unk_80590390){
#include "asm/80590390.s"
}

namespace Kart {
KartPhysics* KartObjectProxy::kartPhysics() { return mAccessor->mBody->getPhysics(); }

const KartPhysics* KartObjectProxy::kartPhysics() const { return mAccessor->mBody->getPhysics(); }

KartDynamics* KartObjectProxy::kartDynamics() { return mAccessor->mBody->getPhysics()->mpDynamics; }

const KartDynamics* KartObjectProxy::kartDynamics() const { return mAccessor->mBody->getPhysics()->mpDynamics; }
}

// Symbol: KartAccessor_getInput
// PAL: 0x805903f4..0x8059041c
MARK_BINARY_BLOB(KartAccessor_getInput, 0x805903f4, 0x8059041c);
asm UNKNOWN_FUNCTION(KartAccessor_getInput){
#include "asm/805903f4.s"
}

// Symbol: unk_8059041c
// PAL: 0x8059041c..0x80590478
MARK_BINARY_BLOB(unk_8059041c, 0x8059041c, 0x80590478);
asm UNKNOWN_FUNCTION(unk_8059041c){
#include "asm/8059041c.s"
}

// Symbol: unk_80590478
// PAL: 0x80590478..0x80590570
MARK_BINARY_BLOB(unk_80590478, 0x80590478, 0x80590570);
asm UNKNOWN_FUNCTION(unk_80590478){
#include "asm/80590478.s"
}

// Symbol: unk_80590570
// PAL: 0x80590570..0x80590650
MARK_BINARY_BLOB(unk_80590570, 0x80590570, 0x80590650);
asm UNKNOWN_FUNCTION(unk_80590570){
#include "asm/80590570.s"
}

// Symbol: PlayerPointers_isReal
// PAL: 0x80590650..0x80590664
MARK_BINARY_BLOB(PlayerPointers_isReal, 0x80590650, 0x80590664);
asm UNKNOWN_FUNCTION(PlayerPointers_isReal){
#include "asm/80590650.s"
}

// Symbol: PlayerPointers_isCpu
// PAL: 0x80590664..0x80590678
MARK_BINARY_BLOB(PlayerPointers_isCpu, 0x80590664, 0x80590678);
asm UNKNOWN_FUNCTION(PlayerPointers_isCpu){
#include "asm/80590664.s"
}

// Symbol: PlayerPointers_isGhost
// PAL: 0x80590678..0x8059068c
MARK_BINARY_BLOB(PlayerPointers_isGhost, 0x80590678, 0x8059068c);
asm UNKNOWN_FUNCTION(PlayerPointers_isGhost){
#include "asm/80590678.s"
}

// Symbol: PlayerModel_isMii
// PAL: 0x8059068c..0x8059069c
MARK_BINARY_BLOB(PlayerModel_isMii, 0x8059068c, 0x8059069c);
asm UNKNOWN_FUNCTION(PlayerModel_isMii) {
#include "asm/8059068c.s"
}

namespace Kart {

KartBody* KartObjectProxy::kartBody() { return mAccessor->mBody; }

const KartBody* KartObjectProxy::kartBody() const { return mAccessor->mBody; }

KartSus* KartObjectProxy::kartSus(s32 idx) { return mAccessor->mSus[idx]; }

const KartSus* KartObjectProxy::kartSus(s32 idx) const {
  return mAccessor->mSus[idx];
}

KartWheel* KartObjectProxy::kartWheel(s32 idx) { return mAccessor->mWheels[idx]; }

const KartWheel* KartObjectProxy::kartWheel(s32 idx) const {
  return mAccessor->mWheels[idx];
}

} // namespace Kart

// Symbol: PlayerPointers_getWheelPhysicsHolder
// PAL: 0x80590704..0x8059071c
MARK_BINARY_BLOB(PlayerPointers_getWheelPhysicsHolder, 0x80590704, 0x8059071c);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysicsHolder){
#include "asm/80590704.s"
}

// Symbol: unk_8059071c
// PAL: 0x8059071c..0x80590734
MARK_BINARY_BLOB(unk_8059071c, 0x8059071c, 0x80590734);
asm UNKNOWN_FUNCTION(unk_8059071c){
#include "asm/8059071c.s"
}

// Symbol: PlayerPointers_getWheelPhysics
// PAL: 0x80590734..0x8059074c
MARK_BINARY_BLOB(PlayerPointers_getWheelPhysics, 0x80590734, 0x8059074c);
asm UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysics){
#include "asm/80590734.s"
}

// Symbol: unk_8059074c
// PAL: 0x8059074c..0x80590764
MARK_BINARY_BLOB(unk_8059074c, 0x8059074c, 0x80590764);
asm UNKNOWN_FUNCTION(unk_8059074c) {
#include "asm/8059074c.s"
}

namespace Kart {

KartPhysicsEngine* KartObjectProxy::kartPhysicsEngine() { return mAccessor->mPhysicsEngine; }

const KartPhysicsEngine* KartObjectProxy::kartPhysicsEngine() const { return mAccessor->mPhysicsEngine; }

KartMove* KartObjectProxy::kartMove() { return mAccessor->mMove; }

const KartMove* KartObjectProxy::kartMove() const { return mAccessor->mMove; }

KartSnd* KartObjectProxy::kartSnd() { return mAccessor->mSnd; }

} // namespace Kart

// Symbol: unk_805907a0
// PAL: 0x805907a0..0x805907b0
MARK_BINARY_BLOB(unk_805907a0, 0x805907a0, 0x805907b0);
asm UNKNOWN_FUNCTION(unk_805907a0){
#include "asm/805907a0.s"
}

// Symbol: unk_805907b0
// PAL: 0x805907b0..0x805907c0
MARK_BINARY_BLOB(unk_805907b0, 0x805907b0, 0x805907c0);
asm UNKNOWN_FUNCTION(unk_805907b0) {
#include "asm/805907b0.s"
}

namespace Kart {

KartAccessor_34* KartObjectProxy::kartAccessor_34() { return mAccessor->m_34; }

MaybeShadow* KartObjectProxy::maybeShadow() { return mAccessor->mMaybeShadow; }

HitboxGroup* KartObjectProxy::hitboxGroup() { return kartBody()->getPhysics()->mpHitboxGroup; }

const HitboxGroup* KartObjectProxy::hitboxGroup() const { return kartBody()->getPhysics()->mpHitboxGroup; }

const HitboxGroup* KartObjectProxy::wheelHitbox(s32 wheelIdx) const { return kartWheel(wheelIdx)->getPhysics()->getHitbox(); }

const KartCollisionInfo* KartObjectProxy::bodyColInfo() const { return &hitboxGroup()->getKartCollisionInfo(); }

const KartCollisionInfo* KartObjectProxy::wheelColInfo(s32 idx) const { return &kartWheel(idx)->getPhysics()->getKartCollisionInfo(); }

KartCollide* KartObjectProxy::kartCollide() { return mAccessor->mCollide; }

const KartCollide* KartObjectProxy::kartCollide() const {
  return mAccessor->mCollide;
}

KartParam* KartObjectProxy::kartParam() const { return mAccessor->kartSettings->kartParam; }
KartStats* KartObjectProxy::kartStats() const { return mAccessor->kartSettings->kartParam->stats; }
BSP* KartObjectProxy::bsp() const { return mAccessor->kartSettings->kartParam->bsp; }
BspHitbox* KartObjectProxy::bspHitboxes() const { return mAccessor->kartSettings->kartParam->bsp->hitboxes; }
BspWheel* KartObjectProxy::bspWheel(s32 idx) const { return &mAccessor->kartSettings->kartParam->bsp->wheels[idx]; }
}

// Symbol: unk_805908d4
// PAL: 0x805908d4..0x805908e4
MARK_BINARY_BLOB(unk_805908d4, 0x805908d4, 0x805908e4);
asm UNKNOWN_FUNCTION(unk_805908d4){
#include "asm/805908d4.s"
}

// Symbol: PlayerPointers_getKartDriverDispParams
// PAL: 0x805908e4..0x805908f4
MARK_BINARY_BLOB(PlayerPointers_getKartDriverDispParams, 0x805908e4,
                 0x805908f4);
asm UNKNOWN_FUNCTION(PlayerPointers_getKartDriverDispParams){
#include "asm/805908e4.s"
}

// Symbol: unk_805908f4
// PAL: 0x805908f4..0x8059090c
MARK_BINARY_BLOB(unk_805908f4, 0x805908f4, 0x8059090c);
asm UNKNOWN_FUNCTION(unk_805908f4){
#include "asm/805908f4.s"
}

// Symbol: various_stuff_get_kart_parts_disp_params
// PAL: 0x8059090c..0x8059091c
MARK_BINARY_BLOB(various_stuff_get_kart_parts_disp_params, 0x8059090c,
                 0x8059091c);
asm UNKNOWN_FUNCTION(various_stuff_get_kart_parts_disp_params){
#include "asm/8059090c.s"
}

// Symbol: various_stuff_get_bike_parts_disp_params
// PAL: 0x8059091c..0x8059092c
MARK_BINARY_BLOB(various_stuff_get_bike_parts_disp_params, 0x8059091c,
                 0x8059092c);
asm UNKNOWN_FUNCTION(various_stuff_get_bike_parts_disp_params){
#include "asm/8059091c.s"
}

// Symbol: unk_8059092c
// PAL: 0x8059092c..0x80590958
MARK_BINARY_BLOB(unk_8059092c, 0x8059092c, 0x80590958);
asm UNKNOWN_FUNCTION(unk_8059092c){
#include "asm/8059092c.s"
}

// Symbol: unk_80590958
// PAL: 0x80590958..0x8059098c
MARK_BINARY_BLOB(unk_80590958, 0x80590958, 0x8059098c);
asm UNKNOWN_FUNCTION(unk_80590958){
#include "asm/80590958.s"
}

// Symbol: unk_8059098c
// PAL: 0x8059098c..0x805909b8
MARK_BINARY_BLOB(unk_8059098c, 0x8059098c, 0x805909b8);
asm UNKNOWN_FUNCTION(unk_8059098c){
#include "asm/8059098c.s"
}

// Symbol: unk_805909b8
// PAL: 0x805909b8..0x805909c8
MARK_BINARY_BLOB(unk_805909b8, 0x805909b8, 0x805909c8);
asm UNKNOWN_FUNCTION(unk_805909b8){
#include "asm/805909b8.s"
}

// Symbol: unk_805909c8
// PAL: 0x805909c8..0x805909f4
MARK_BINARY_BLOB(unk_805909c8, 0x805909c8, 0x805909f4);
asm UNKNOWN_FUNCTION(unk_805909c8) {
#include "asm/805909c8.s"
}

namespace Kart {

s32 KartObjectProxy::getHopStickX() { return kartMove()->hopStickX(); }

s32 KartObjectProxy::getAppliedHopStickX() {
  return kartMove()->getAppliedHopStickX();
}

} // namespace Kart

// Symbol: PlayerPointers_getVehicleType
// PAL: 0x80590a10..0x80590a28
MARK_BINARY_BLOB(PlayerPointers_getVehicleType, 0x80590a10, 0x80590a28);
asm UNKNOWN_FUNCTION(PlayerPointers_getVehicleType){
#include "asm/80590a10.s"
}

// Symbol: unk_80590a28
// PAL: 0x80590a28..0x80590a40
MARK_BINARY_BLOB(unk_80590a28, 0x80590a28, 0x80590a40);
asm UNKNOWN_FUNCTION(unk_80590a28) {
#include "asm/80590a28.s"
}

namespace Kart {

KartModel* KartObjectProxy::kartModel() { return mAccessor->mModel; }

} // namespace Kart

// Symbol: unk_80590a4c
// PAL: 0x80590a4c..0x80590a5c
MARK_BINARY_BLOB(unk_80590a4c, 0x80590a4c, 0x80590a5c);
asm UNKNOWN_FUNCTION(unk_80590a4c){
#include "asm/80590a4c.s"
}

namespace Kart {
u8 KartObjectProxy::getPlayerIdx() const { return mAccessor->kartSettings->playerIdx; }
}

// Symbol: PlayerPointers_isBike
// PAL: 0x80590a6c..0x80590a7c
MARK_BINARY_BLOB(PlayerPointers_isBike, 0x80590a6c, 0x80590a7c);
asm UNKNOWN_FUNCTION(PlayerPointers_isBike){
#include "asm/80590a6c.s"
}

// Symbol: PlayerPointers_getVehicle
// PAL: 0x80590a7c..0x80590a8c
MARK_BINARY_BLOB(PlayerPointers_getVehicle, 0x80590a7c, 0x80590a8c);
asm UNKNOWN_FUNCTION(PlayerPointers_getVehicle){
#include "asm/80590a7c.s"
}

// Symbol: unk_80590a8c
// PAL: 0x80590a8c..0x80590a9c
MARK_BINARY_BLOB(unk_80590a8c, 0x80590a8c, 0x80590a9c);
asm UNKNOWN_FUNCTION(unk_80590a8c){
#include "asm/80590a8c.s"
}

// Symbol: unk_80590a9c
// PAL: 0x80590a9c..0x80590c44
MARK_BINARY_BLOB(unk_80590a9c, 0x80590a9c, 0x80590c44);
asm UNKNOWN_FUNCTION(unk_80590a9c){
#include "asm/80590a9c.s"
}

// Symbol: PlayerPointers_getPlayerMatCol0
// PAL: 0x80590c44..0x80590c6c
MARK_BINARY_BLOB(PlayerPointers_getPlayerMatCol0, 0x80590c44, 0x80590c6c);
asm UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0){
#include "asm/80590c44.s"
}

// Symbol: unk_80590c6c
// PAL: 0x80590c6c..0x80590c94
MARK_BINARY_BLOB(unk_80590c6c, 0x80590c6c, 0x80590c94);
asm UNKNOWN_FUNCTION(unk_80590c6c){
#include "asm/80590c6c.s"
}

// Symbol: PlayerPointers_getBodyFront
// PAL: 0x80590c94..0x80590cbc
MARK_BINARY_BLOB(PlayerPointers_getBodyFront, 0x80590c94, 0x80590cbc);
asm UNKNOWN_FUNCTION(PlayerPointers_getBodyFront){
#include "asm/80590c94.s"
}

// Symbol: unk_80590cbc
// PAL: 0x80590cbc..0x80590cd0
MARK_BINARY_BLOB(unk_80590cbc, 0x80590cbc, 0x80590cd0);
asm UNKNOWN_FUNCTION(unk_80590cbc){
#include "asm/80590cbc.s"
}

// Symbol: unk_80590cd0
// PAL: 0x80590cd0..0x80590ce4
MARK_BINARY_BLOB(unk_80590cd0, 0x80590cd0, 0x80590ce4);
asm UNKNOWN_FUNCTION(unk_80590cd0){
#include "asm/80590cd0.s"
}

// Symbol: PlayerPointers_getMalCol2
// PAL: 0x80590ce4..0x80590cf8
MARK_BINARY_BLOB(PlayerPointers_getMalCol2, 0x80590ce4, 0x80590cf8);
asm UNKNOWN_FUNCTION(PlayerPointers_getMalCol2) {
#include "asm/80590ce4.s"
}

namespace Kart {

f32 KartObjectProxy::getVehicleSpeed() { return kartMove()->speed(); }

} // namespace Kart

// Symbol: playerPointers_getSpeed
// PAL: 0x80590d08..0x80590d20
MARK_BINARY_BLOB(playerPointers_getSpeed, 0x80590d08, 0x80590d20);
asm UNKNOWN_FUNCTION(playerPointers_getSpeed) {
#include "asm/80590d08.s"
}

namespace Kart {

KartAction* KartObjectProxy::kartAction() { return mAccessor->mAction; }

const KartAction* KartObjectProxy::kartAction() const {
  return mAccessor->mAction;
}

} // namespace Kart

// Symbol: unk_80590d38
// PAL: 0x80590d38..0x80590d5c
MARK_BINARY_BLOB(unk_80590d38, 0x80590d38, 0x80590d5c);
asm UNKNOWN_FUNCTION(unk_80590d38){
#include "asm/80590d38.s"
}

// Symbol: unk_80590d5c
// PAL: 0x80590d5c..0x80590d88
MARK_BINARY_BLOB(unk_80590d5c, 0x80590d5c, 0x80590d88);
asm UNKNOWN_FUNCTION(unk_80590d5c){
#include "asm/80590d5c.s"
}

// Symbol: unk_80590d88
// PAL: 0x80590d88..0x80590d94
MARK_BINARY_BLOB(unk_80590d88, 0x80590d88, 0x80590d94);
asm UNKNOWN_FUNCTION(unk_80590d88) {
#include "asm/80590d88.s"
}

namespace Kart {

void KartObjectProxy::empty(s16 arg) { kartMove()->empty(arg); }

} // namespace Kart

// Symbol: unk_80590da4
// PAL: 0x80590da4..0x80590db4
MARK_BINARY_BLOB(unk_80590da4, 0x80590da4, 0x80590db4);
asm UNKNOWN_FUNCTION(unk_80590da4) {
#include "asm/80590da4.s"
}

namespace Kart {

void KartObjectProxy::clearBoost() { kartMove()->clearBoost(); }

f32 KartObjectProxy::getSpeedRatioCapped() {
  return kartMove()->speedRatioCapped();
}

f32 KartObjectProxy::getSpeedRatio() { return kartMove()->speedRatio(); }

bool KartObjectProxy::hasCamera() { return mAccessor->mCamera; }

void KartObjectProxy::setCamera(KartCamera* camera) {
  mAccessor->mCamera = camera;
}

} // namespace Kart

// Symbol: unk_80590e04
// PAL: 0x80590e04..0x80590e28
MARK_BINARY_BLOB(unk_80590e04, 0x80590e04, 0x80590e28);
asm UNKNOWN_FUNCTION(unk_80590e04){
#include "asm/80590e04.s"
}

// Symbol: unk_80590e28
// PAL: 0x80590e28..0x80590e40
MARK_BINARY_BLOB(unk_80590e28, 0x80590e28, 0x80590e40);
asm UNKNOWN_FUNCTION(unk_80590e28){
#include "asm/80590e28.s"
}

// Symbol: unk_80590e40
// PAL: 0x80590e40..0x80590e58
MARK_BINARY_BLOB(unk_80590e40, 0x80590e40, 0x80590e58);
asm UNKNOWN_FUNCTION(unk_80590e40){
#include "asm/80590e40.s"
}

// Symbol: unk_80590e58
// PAL: 0x80590e58..0x80590e70
MARK_BINARY_BLOB(unk_80590e58, 0x80590e58, 0x80590e70);
asm UNKNOWN_FUNCTION(unk_80590e58){
#include "asm/80590e58.s"
}

// Symbol: unk_80590e70
// PAL: 0x80590e70..0x80590e88
MARK_BINARY_BLOB(unk_80590e70, 0x80590e70, 0x80590e88);
asm UNKNOWN_FUNCTION(unk_80590e70) {
#include "asm/80590e70.s"
}

namespace Kart {

void KartObjectProxy::empty() {}

} // namespace Kart

// Symbol: unk_80590e8c
// PAL: 0x80590e8c..0x80590ea4
MARK_BINARY_BLOB(unk_80590e8c, 0x80590e8c, 0x80590ea4);
asm UNKNOWN_FUNCTION(unk_80590e8c){
#include "asm/80590e8c.s"
}

// Symbol: unk_80590ea4
// PAL: 0x80590ea4..0x80590ed8
MARK_BINARY_BLOB(unk_80590ea4, 0x80590ea4, 0x80590ed8);
asm UNKNOWN_FUNCTION(unk_80590ea4){
#include "asm/80590ea4.s"
}

// Symbol: unk_80590ed8
// PAL: 0x80590ed8..0x80590ef8
MARK_BINARY_BLOB(unk_80590ed8, 0x80590ed8, 0x80590ef8);
asm UNKNOWN_FUNCTION(unk_80590ed8){
#include "asm/80590ed8.s"
}

// Symbol: unk_80590ef8
// PAL: 0x80590ef8..0x80590f18
MARK_BINARY_BLOB(unk_80590ef8, 0x80590ef8, 0x80590f18);
asm UNKNOWN_FUNCTION(unk_80590ef8){
#include "asm/80590ef8.s"
}

// Symbol: unk_80590f18
// PAL: 0x80590f18..0x80590f38
MARK_BINARY_BLOB(unk_80590f18, 0x80590f18, 0x80590f38);
asm UNKNOWN_FUNCTION(unk_80590f18){
#include "asm/80590f18.s"
}

// Symbol: unk_80590f38
// PAL: 0x80590f38..0x80590f58
MARK_BINARY_BLOB(unk_80590f38, 0x80590f38, 0x80590f58);
asm UNKNOWN_FUNCTION(unk_80590f38){
#include "asm/80590f38.s"
}

// Symbol: unk_80590f58
// PAL: 0x80590f58..0x80590f70
MARK_BINARY_BLOB(unk_80590f58, 0x80590f58, 0x80590f70);
asm UNKNOWN_FUNCTION(unk_80590f58){
#include "asm/80590f58.s"
}

// Symbol: unk_80590f70
// PAL: 0x80590f70..0x80590f90
MARK_BINARY_BLOB(unk_80590f70, 0x80590f70, 0x80590f90);
asm UNKNOWN_FUNCTION(unk_80590f70){
#include "asm/80590f70.s"
}

// Symbol: unk_80590f90
// PAL: 0x80590f90..0x80590f9c
MARK_BINARY_BLOB(unk_80590f90, 0x80590f90, 0x80590f9c);
asm UNKNOWN_FUNCTION(unk_80590f90){
#include "asm/80590f90.s"
}

// Symbol: unk_80590f9c
// PAL: 0x80590f9c..0x8059102c
MARK_BINARY_BLOB(unk_80590f9c, 0x80590f9c, 0x8059102c);
asm UNKNOWN_FUNCTION(unk_80590f9c){
#include "asm/80590f9c.s"
}

// Symbol: unk_8059102c
// PAL: 0x8059102c..0x80591038
MARK_BINARY_BLOB(unk_8059102c, 0x8059102c, 0x80591038);
asm UNKNOWN_FUNCTION(unk_8059102c){
#include "asm/8059102c.s"
}

// Symbol: unk_80591038
// PAL: 0x80591038..0x80591044
MARK_BINARY_BLOB(unk_80591038, 0x80591038, 0x80591044);
asm UNKNOWN_FUNCTION(unk_80591038){
#include "asm/80591038.s"
}

// Symbol: unk_80591044
// PAL: 0x80591044..0x80591050
MARK_BINARY_BLOB(unk_80591044, 0x80591044, 0x80591050);
asm UNKNOWN_FUNCTION(unk_80591044){
#include "asm/80591044.s"
}

// Symbol: unk_80591050
// PAL: 0x80591050..0x80591070
MARK_BINARY_BLOB(unk_80591050, 0x80591050, 0x80591070);
asm UNKNOWN_FUNCTION(unk_80591050) {
#include "asm/80591050.s"
}

namespace Kart {

KartAccessor_54* KartObjectProxy::kartAccessor_54() { return mAccessor->m_54; }

} // namespace Kart

// Symbol: unk_8059107c
// PAL: 0x8059107c..0x8059108c
MARK_BINARY_BLOB(unk_8059107c, 0x8059107c, 0x8059108c);
asm UNKNOWN_FUNCTION(unk_8059107c) {
#include "asm/8059107c.s"
}

namespace Kart {

KartBlink* KartObjectProxy::kartBlink() { return mAccessor->mBlink; }

const KartBlink* KartObjectProxy::kartBlink() const {
  return mAccessor->mBlink;
}

KartAccessor_5c* KartObjectProxy::kartAccessor_5c() { return mAccessor->m_5c; }

f32 KartObjectProxy::getBaseSpeed() { return kartMove()->baseSpeed(); }

KartEnemy* KartObjectProxy::kartEnemy() { return mAccessor->mEnemy; }

} // namespace Kart

// Symbol: unk_805910cc
// PAL: 0x805910cc..0x805910e4
MARK_BINARY_BLOB(unk_805910cc, 0x805910cc, 0x805910e4);
asm UNKNOWN_FUNCTION(unk_805910cc){
#include "asm/805910cc.s"
}

// Symbol: unk_805910e4
// PAL: 0x805910e4..0x805910fc
MARK_BINARY_BLOB(unk_805910e4, 0x805910e4, 0x805910fc);
asm UNKNOWN_FUNCTION(unk_805910e4){
#include "asm/805910e4.s"
}

// Symbol: unk_805910fc
// PAL: 0x805910fc..0x80591138
MARK_BINARY_BLOB(unk_805910fc, 0x805910fc, 0x80591138);
asm UNKNOWN_FUNCTION(unk_805910fc){
#include "asm/805910fc.s"
}

// Symbol: unk_80591138
// PAL: 0x80591138..0x80591170
MARK_BINARY_BLOB(unk_80591138, 0x80591138, 0x80591170);
asm UNKNOWN_FUNCTION(unk_80591138){
#include "asm/80591138.s"
}

// Symbol: unk_80591170
// PAL: 0x80591170..0x805911a8
MARK_BINARY_BLOB(unk_80591170, 0x80591170, 0x805911a8);
asm UNKNOWN_FUNCTION(unk_80591170){
#include "asm/80591170.s"
}

// Symbol: unk_805911a8
// PAL: 0x805911a8..0x805911c0
MARK_BINARY_BLOB(unk_805911a8, 0x805911a8, 0x805911c0);
asm UNKNOWN_FUNCTION(unk_805911a8){
#include "asm/805911a8.s"
}

// Symbol: unk_805911c0
// PAL: 0x805911c0..0x805911d8
MARK_BINARY_BLOB(unk_805911c0, 0x805911c0, 0x805911d8);
asm UNKNOWN_FUNCTION(unk_805911c0) {
#include "asm/805911c0.s"
}

namespace Kart {

s16 KartObjectProxy::getDriftState() { return kartMove()->driftState(); }

s16 KartObjectProxy::getMtCharge() { return kartMove()->mtCharge(); }

s16 KartObjectProxy::getSmtCharge() { return kartMove()->smtCharge(); }

s16 KartObjectProxy::getMaxMtCharge() { return kartMove()->getMaxMtCharge(); }

s16 KartObjectProxy::getMaxSmtCharge() { return kartMove()->getMaxSmtCharge(); }

} // namespace Kart

// Symbol: unk_80591220
// PAL: 0x80591220..0x80591264
MARK_BINARY_BLOB(unk_80591220, 0x80591220, 0x80591264);
asm UNKNOWN_FUNCTION(unk_80591220){
#include "asm/80591220.s"
}

// Symbol: unk_80591264
// PAL: 0x80591264..0x80591314
MARK_BINARY_BLOB(unk_80591264, 0x80591264, 0x80591314);
asm UNKNOWN_FUNCTION(unk_80591264){
#include "asm/80591264.s"
}

// Symbol: unk_80591314
// PAL: 0x80591314..0x80591344
MARK_BINARY_BLOB(unk_80591314, 0x80591314, 0x80591344);
asm UNKNOWN_FUNCTION(unk_80591314){
#include "asm/80591314.s"
}

// Symbol: unk_80591344
// PAL: 0x80591344..0x80591378
MARK_BINARY_BLOB(unk_80591344, 0x80591344, 0x80591378);
asm UNKNOWN_FUNCTION(unk_80591344){
#include "asm/80591344.s"
}

// Symbol: unk_80591378
// PAL: 0x80591378..0x805913a8
MARK_BINARY_BLOB(unk_80591378, 0x80591378, 0x805913a8);
asm UNKNOWN_FUNCTION(unk_80591378){
#include "asm/80591378.s"
}

// Symbol: unk_805913a8
// PAL: 0x805913a8..0x805913fc
MARK_BINARY_BLOB(unk_805913a8, 0x805913a8, 0x805913fc);
asm UNKNOWN_FUNCTION(unk_805913a8) {
#include "asm/805913a8.s"
}

namespace Kart {

bool KartObjectProxy::isDrivingIdle() {
  return kartMove()->drivingDirection() == KartMove::DRIVING_DIRECTION_IDLE;
}

s16 KartObjectProxy::getBackwardsAllowCounter() {
  return kartMove()->backwardsAllowCounter();
}

KartAccessor_44* KartObjectProxy::kartAccessor_44() { return mAccessor->m_44; }

KartAccessor_48* KartObjectProxy::kartAccessor_48() { return mAccessor->m_48; }

KartNetSender* KartObjectProxy::kartNetSender() { return mAccessor->mSender; }

KartNetReceiver* KartObjectProxy::kartNetReceiver() {
  return mAccessor->mReceiver;
}

} // namespace Kart

// Symbol: PlayerPointers_getRacedataFactoryFlags
// PAL: 0x80591458..0x80591468
MARK_BINARY_BLOB(PlayerPointers_getRacedataFactoryFlags, 0x80591458,
                 0x80591468);
asm UNKNOWN_FUNCTION(PlayerPointers_getRacedataFactoryFlags){
#include "asm/80591458.s"
}

// Symbol: unk_80591468
// PAL: 0x80591468..0x80591478
MARK_BINARY_BLOB(unk_80591468, 0x80591468, 0x80591478);
asm UNKNOWN_FUNCTION(unk_80591468) {
#include "asm/80591468.s"
}

namespace Kart {

void KartObjectProxy::setScale(const EGG::Vector3f& scale) {
  kartMove()->setScale(scale);
}

const EGG::Vector3f& KartObjectProxy::getScale() { return kartMove()->scale(); }

} // namespace Kart

// Symbol: unk_805914cc
// PAL: 0x805914cc..0x805914e4
MARK_BINARY_BLOB(unk_805914cc, 0x805914cc, 0x805914e4);
asm UNKNOWN_FUNCTION(unk_805914cc){
#include "asm/805914cc.s"
}

// Symbol: unk_805914e4
// PAL: 0x805914e4..0x805914f4
MARK_BINARY_BLOB(unk_805914e4, 0x805914e4, 0x805914f4);
asm UNKNOWN_FUNCTION(unk_805914e4) {
#include "asm/805914e4.s"
}

namespace Kart {

bool KartObjectProxy::inRespawn() {
  return kartMove()->respawnTimer() > 0 || kartMove()->someTimer() > 0;
}

BoxColUnit* KartObjectProxy::kartEntity() { return mAccessor->mEntity; }

KartAccessor_50* KartObjectProxy::kartAccessor_50() { return mAccessor->m_50; }

} // namespace Kart

// Symbol: unk_80591538
// PAL: 0x80591538..0x80591608
MARK_BINARY_BLOB(unk_80591538, 0x80591538, 0x80591608);
asm UNKNOWN_FUNCTION(unk_80591538){
#include "asm/80591538.s"
}

// Symbol: unk_80591608
// PAL: 0x80591608..0x80591618
MARK_BINARY_BLOB(unk_80591608, 0x80591608, 0x80591618);
asm UNKNOWN_FUNCTION(unk_80591608) {
#include "asm/80591608.s"
}

namespace Kart {

KartAccessor_60* KartObjectProxy::kartAccessor_60() { return mAccessor->m_60; }

} // namespace Kart

// Symbol: unk_80591624
// PAL: 0x80591624..0x80591650
MARK_BINARY_BLOB(unk_80591624, 0x80591624, 0x80591650);
asm UNKNOWN_FUNCTION(unk_80591624) {
#include "asm/80591624.s"
}

namespace Kart {

bool KartObjectProxy::isSomeMoveFlagActive() {
  return kartMove()->flags() & 1 << 2;
}

} // namespace Kart

// Symbol: PlayerPointers_resetInertia
// PAL: 0x80591664..0x8059170c
MARK_BINARY_BLOB(PlayerPointers_resetInertia, 0x80591664, 0x8059170c);
asm UNKNOWN_FUNCTION(PlayerPointers_resetInertia){
#include "asm/80591664.s"
}

// Symbol: unk_8059170c
// PAL: 0x8059170c..0x80591784
MARK_BINARY_BLOB(unk_8059170c, 0x8059170c, 0x80591784);
asm UNKNOWN_FUNCTION(unk_8059170c){
#include "asm/8059170c.s"
}

// Symbol: unk_80591784
// PAL: 0x80591784..0x805917a0
MARK_BINARY_BLOB(unk_80591784, 0x80591784, 0x805917a0);
asm UNKNOWN_FUNCTION(unk_80591784){
#include "asm/80591784.s"
}

// Symbol: PlayerPointers_getOobWipeState
// PAL: 0x805917a0..0x805917b0
MARK_BINARY_BLOB(PlayerPointers_getOobWipeState, 0x805917a0, 0x805917b0);
asm UNKNOWN_FUNCTION(PlayerPointers_getOobWipeState){
#include "asm/805917a0.s"
}

// Symbol: unk_805917b0
// PAL: 0x805917b0..0x805917c0
MARK_BINARY_BLOB(unk_805917b0, 0x805917b0, 0x805917c0);
asm UNKNOWN_FUNCTION(unk_805917b0){
#include "asm/805917b0.s"
}

// Symbol: unk_805917c0
// PAL: 0x805917c0..0x805917f4
MARK_BINARY_BLOB(unk_805917c0, 0x805917c0, 0x805917f4);
asm UNKNOWN_FUNCTION(unk_805917c0){
#include "asm/805917c0.s"
}

// Symbol: unk_805917f4
// PAL: 0x805917f4..0x80591828
MARK_BINARY_BLOB(unk_805917f4, 0x805917f4, 0x80591828);
asm UNKNOWN_FUNCTION(unk_805917f4){
#include "asm/805917f4.s"
}

// Symbol: unk_80591828
// PAL: 0x80591828..0x8059184c
MARK_BINARY_BLOB(unk_80591828, 0x80591828, 0x8059184c);
asm UNKNOWN_FUNCTION(unk_80591828){
#include "asm/80591828.s"
}

// Symbol: unk_8059184c
// PAL: 0x8059184c..0x80591898
MARK_BINARY_BLOB(unk_8059184c, 0x8059184c, 0x80591898);
asm UNKNOWN_FUNCTION(unk_8059184c){
#include "asm/8059184c.s"
}

// Symbol: unk_80591898
// PAL: 0x80591898..0x805918bc
MARK_BINARY_BLOB(unk_80591898, 0x80591898, 0x805918bc);
asm UNKNOWN_FUNCTION(unk_80591898){
#include "asm/80591898.s"
}

// Symbol: unk_805918bc
// PAL: 0x805918bc..0x805918e0
MARK_BINARY_BLOB(unk_805918bc, 0x805918bc, 0x805918e0);
asm UNKNOWN_FUNCTION(unk_805918bc){
#include "asm/805918bc.s"
}

// Symbol: unk_805918e0
// PAL: 0x805918e0..0x80591904
MARK_BINARY_BLOB(unk_805918e0, 0x805918e0, 0x80591904);
asm UNKNOWN_FUNCTION(unk_805918e0) {
#include "asm/805918e0.s"
}

namespace Kart {

const KartHalfPipe* KartObjectProxy::kartHalfPipe() {
  return kartMove()->kartHalfPipe();
}

const KartJump* KartObjectProxy::kartJump() { return kartMove()->kartJump(); }

} // namespace Kart

// Symbol: unk_80591924
// PAL: 0x80591924..0x8059197c
MARK_BINARY_BLOB(unk_80591924, 0x80591924, 0x8059197c);
asm UNKNOWN_FUNCTION(unk_80591924){
#include "asm/80591924.s"
}

// Symbol: unk_8059197c
// PAL: 0x8059197c..0x80591998
MARK_BINARY_BLOB(unk_8059197c, 0x8059197c, 0x80591998);
asm UNKNOWN_FUNCTION(unk_8059197c){
#include "asm/8059197c.s"
}

// Symbol: unk_80591998
// PAL: 0x80591998..0x805919e8
MARK_BINARY_BLOB(unk_80591998, 0x80591998, 0x805919e8);
asm UNKNOWN_FUNCTION(unk_80591998){
#include "asm/80591998.s"
}

// Symbol: unk_805919e8
// PAL: 0x805919e8..0x805919f4
MARK_BINARY_BLOB(unk_805919e8, 0x805919e8, 0x805919f4);
asm UNKNOWN_FUNCTION(unk_805919e8) {
#include "asm/805919e8.s"
}
