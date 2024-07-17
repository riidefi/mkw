#include "KartMove.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021584
extern UNKNOWN_FUNCTION(_savegpr_20);
// PAL: 0x80021598
extern UNKNOWN_FUNCTION(_savegpr_25);
// PAL: 0x8002159c
extern UNKNOWN_FUNCTION(_savegpr_26);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215d0
extern UNKNOWN_FUNCTION(_restgpr_20);
// PAL: 0x800215e4
extern UNKNOWN_FUNCTION(_restgpr_25);
// PAL: 0x800215e8
extern UNKNOWN_FUNCTION(_restgpr_26);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80025fb0
extern UNKNOWN_FUNCTION(Panic);
// PAL: 0x80026050
extern UNKNOWN_FUNCTION(VWarning);
// PAL: 0x80085110
extern UNKNOWN_FUNCTION(SinFIdx__Q24nw4r4mathFf);
// PAL: 0x800853c0
extern UNKNOWN_FUNCTION(Atan2FIdx__Q24nw4r4mathFff);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8022f80c
extern UNKNOWN_FUNCTION(sqrt__Q23EGG5MathfFf);
// PAL: 0x8022f8e4
extern UNKNOWN_FUNCTION(atan2_Q23EGG5MathfFff);
// PAL: 0x8022ff98
extern UNKNOWN_FUNCTION(makeR__Q23EGG9Matrix34fFRCQ23EGG8Vector3f);
// PAL: 0x802303bc
extern UNKNOWN_FUNCTION(setAxisRotation__Q23EGG9Matrix34fFRCQ23EGG8Vector3ff);
// PAL: 0x80239dfc
extern UNKNOWN_FUNCTION(set__Q23EGG5QuatfFffff);
// PAL: 0x80239e10
extern UNKNOWN_FUNCTION(setRPY__Q23EGG5QuatfFRCQ23EGG8Vector3f);
// PAL: 0x80239f58
extern UNKNOWN_FUNCTION(setRPY__Q23EGG5QuatfFfff);
// PAL: 0x8023a0a0
extern UNKNOWN_FUNCTION(setAxisRotation__Q23EGG5QuatfFRCQ23EGG8Vector3ff);
// PAL: 0x8023a168
extern UNKNOWN_FUNCTION(normalise__Q23EGG5QuatfFv);
// PAL: 0x8023a2d0
extern UNKNOWN_FUNCTION(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f);
// PAL: 0x8023a5c4
extern UNKNOWN_FUNCTION(slerpTo__Q23EGG5QuatfCFRCQ23EGG5QuatffRQ23EGG5Quatf);
// PAL: 0x8023a788
extern UNKNOWN_FUNCTION(
    makeVectorRotation__Q23EGG5QuatfFRQ23EGG8Vector3fRQ23EGG8Vector3f);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x805147d4
extern UNKNOWN_FUNCTION(VEC3_fromNeg);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x80514d3c
extern UNKNOWN_FUNCTION(getItemPoint__Q26System9CourseMapCFUs);
// PAL: 0x8051896c
extern UNKNOWN_FUNCTION(unk_8051896c);
// PAL: 0x80518ab8
extern UNKNOWN_FUNCTION(Vec3_fromScale);
// PAL: 0x80518ae0
extern UNKNOWN_FUNCTION(getCannonPoint__Q26System9CourseMapCFUs);
// PAL: 0x80518b2c
extern UNKNOWN_FUNCTION(getMissionPoint__Q26System9CourseMapCFUs);
// PAL: 0x8053621c
extern UNKNOWN_FUNCTION(unk_8053621c);
// PAL: 0x80536230
extern UNKNOWN_FUNCTION(Raceinfo_isAtLeastStage);
// PAL: 0x80537830
extern UNKNOWN_FUNCTION(VEC3_fromCross);
// PAL: 0x80538e00
extern UNKNOWN_FUNCTION(unk_80538e00);
// PAL: 0x8053b6f8
extern UNKNOWN_FUNCTION(unk_8053b6f8);
// PAL: 0x8056754c
extern UNKNOWN_FUNCTION(unk_8056754c);
// PAL: 0x80567a88
extern UNKNOWN_FUNCTION(unk_80567a88);
// PAL: 0x80567ce4
extern UNKNOWN_FUNCTION(PlayerSub14_updateCollisionSpeed);
// PAL: 0x8056a2f0
extern UNKNOWN_FUNCTION(unk_8056a2f0);
// PAL: 0x8056a300
extern UNKNOWN_FUNCTION(unk_8056a300);
// PAL: 0x8056a6d8
extern UNKNOWN_FUNCTION(unk_8056a6d8);
// PAL: 0x8056ad44
extern UNKNOWN_FUNCTION(unk_8056ad44);
// PAL: 0x8056af10
extern UNKNOWN_FUNCTION(unk_8056af10);
// PAL: 0x8056afb4
extern UNKNOWN_FUNCTION(unk_8056afb4);
// PAL: 0x8056b060
extern UNKNOWN_FUNCTION(unk_8056b060);
// PAL: 0x8056b094
extern UNKNOWN_FUNCTION(unk_8056b094);
// PAL: 0x8056b168
extern UNKNOWN_FUNCTION(unk_8056b168);
// PAL: 0x8056b218
extern UNKNOWN_FUNCTION(unk_8056b218);
// PAL: 0x80571234
extern UNKNOWN_FUNCTION(unk_80571234);
// PAL: 0x805713d8
extern UNKNOWN_FUNCTION(unk_805713d8);
// PAL: 0x80573ec4
extern UNKNOWN_FUNCTION(unk_80573ec4);
// PAL: 0x80574108
extern UNKNOWN_FUNCTION(get_65);
// PAL: 0x80574114
extern UNKNOWN_FUNCTION(PlayerZipper_construct);
// PAL: 0x805741b0
extern UNKNOWN_FUNCTION(unk_805741b0);
// PAL: 0x80574340
extern UNKNOWN_FUNCTION(PlayerZipper_update);
// PAL: 0x805758e4
extern UNKNOWN_FUNCTION(PlayerZipper_end);
// PAL: 0x80575a44
extern UNKNOWN_FUNCTION(PlayerTrick_construct);
// PAL: 0x80575ae8
extern UNKNOWN_FUNCTION(PlayerTrick_reset);
// PAL: 0x80575d7c
extern UNKNOWN_FUNCTION(PlayerTrick_tryStart);
// PAL: 0x805763e4
extern UNKNOWN_FUNCTION(PlayerTrick_update);
// PAL: 0x805766b8
extern UNKNOWN_FUNCTION(PlayerTrick_end);
// PAL: 0x80577fc4
extern UNKNOWN_FUNCTION(PlayerSub10_construct);
// PAL: 0x8057829c
extern UNKNOWN_FUNCTION(PlayerSub10_resetHard);
// PAL: 0x805784d4
extern UNKNOWN_FUNCTION(PlayerSub10_init2);
// PAL: 0x80579a50
extern UNKNOWN_FUNCTION(unk_80579a50);
// PAL: 0x80579da8
extern UNKNOWN_FUNCTION(unk_80579da8);
// PAL: 0x80579fe4
extern UNKNOWN_FUNCTION(PlayerSub10_somethingWheelieBump);
// PAL: 0x8057a140
extern UNKNOWN_FUNCTION(PlayerSub10_updateDirs);
// PAL: 0x8057b028
extern UNKNOWN_FUNCTION(unk_8057b028);
// PAL: 0x8057b108
extern UNKNOWN_FUNCTION(PlayerSub10_computeWallCollisionSpeedFactor);
// PAL: 0x8057b2a0
extern UNKNOWN_FUNCTION(unk_8057b2a0);
// PAL: 0x8057b868
extern UNKNOWN_FUNCTION(get_acceleration_from_speed);
// PAL: 0x8057b9bc
extern UNKNOWN_FUNCTION(PlayerSub10_updateAcceleration);
// PAL: 0x8057c3d4
extern UNKNOWN_FUNCTION(PlayerSub10_updateOffroad);
// PAL: 0x8057c69c
extern UNKNOWN_FUNCTION(PlayerSub10_updateRotation);
// PAL: 0x8057d1d4
extern UNKNOWN_FUNCTION(PlayerSub10_updateStandstillBoostRot);
// PAL: 0x8057d398
extern UNKNOWN_FUNCTION(PlayerSub10_updateTop);
// PAL: 0x8057da5c
extern UNKNOWN_FUNCTION(PlayerSub10_hop);
// PAL: 0x8057dc44
extern UNKNOWN_FUNCTION(PlayerSub10_updateManualDrift);
// PAL: 0x8057e0dc
extern UNKNOWN_FUNCTION(PlayerSub10_updateAutoDrift);
// PAL: 0x8057e348
extern UNKNOWN_FUNCTION(unk_8057e348);
// PAL: 0x8057e3f4
extern UNKNOWN_FUNCTION(PlayerSub10_startManualDrift);
// PAL: 0x8057e804
extern UNKNOWN_FUNCTION(PlayerSub10_updateHopAndSlipdrift);
// PAL: 0x8057eab8
extern UNKNOWN_FUNCTION(unk_8057eab8);
// PAL: 0x8057fd18
extern UNKNOWN_FUNCTION(PlayerSub10_tryStartJumpPad);
// PAL: 0x80580778
extern UNKNOWN_FUNCTION(PlayerSub10_applyLightningEffect);
// PAL: 0x805810a8
extern UNKNOWN_FUNCTION(unk_805810a8);
// PAL: 0x805813e8
extern UNKNOWN_FUNCTION(unk_805813e8);
// PAL: 0x8058160c
extern UNKNOWN_FUNCTION(unk_8058160c);
// PAL: 0x80581720
extern UNKNOWN_FUNCTION(setScale__Q24Kart8KartMoveFQ23EGG8Vector3f);
// PAL: 0x80581824
extern UNKNOWN_FUNCTION(unk_80581824);
// PAL: 0x80581b1c
extern UNKNOWN_FUNCTION(PlayerSub10_updateInk);
// PAL: 0x80581c90
extern UNKNOWN_FUNCTION(PlayerSub10_somethingRespawnBoost);
// PAL: 0x80582530
extern UNKNOWN_FUNCTION(PlayerSub10_tryEndJumpPad);
// PAL: 0x805828cc
extern UNKNOWN_FUNCTION(unk_805828cc);
// PAL: 0x80582f9c
extern UNKNOWN_FUNCTION(PlayerSub10_releaseMt);
// PAL: 0x805837cc
extern UNKNOWN_FUNCTION(unk_805837cc);
// PAL: 0x80583b88
extern UNKNOWN_FUNCTION(PlayerSub10_updateStickyRoad);
// PAL: 0x80584044
extern UNKNOWN_FUNCTION(PlayerSub10_setInitialPhysicsValues);
// PAL: 0x8058473c
extern UNKNOWN_FUNCTION(unk_8058473c);
// PAL: 0x80584d58
extern UNKNOWN_FUNCTION(PlayerSub10_updateCannon);
// PAL: 0x8058539c
extern UNKNOWN_FUNCTION(PlayerPointers_getCannonPosAndDir);
// PAL: 0x805855bc
extern UNKNOWN_FUNCTION(unk_805855bc);
// PAL: 0x80585af8
extern UNKNOWN_FUNCTION(unk_80585af8);
// PAL: 0x805860bc
extern UNKNOWN_FUNCTION(unk_805860bc);
// PAL: 0x8058677c
extern UNKNOWN_FUNCTION(unk_8058677c);
// PAL: 0x805869dc
extern UNKNOWN_FUNCTION(PlayerSub10_updateDiving);
// PAL: 0x80586e90
extern UNKNOWN_FUNCTION(unk_80586e90);
// PAL: 0x80586fa8
extern UNKNOWN_FUNCTION(PlayerSub10_updateSlipstream);
// PAL: 0x805883f4
extern UNKNOWN_FUNCTION(unk_805883f4);
// PAL: 0x80588e24
extern UNKNOWN_FUNCTION(PlayerBoost_update);
// PAL: 0x80590100
extern UNKNOWN_FUNCTION(PlayerHolder_getPlayer);
// PAL: 0x8059018c
extern UNKNOWN_FUNCTION(__ct__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059020c
extern UNKNOWN_FUNCTION(getPos__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590238
extern UNKNOWN_FUNCTION(various_stuff_set_player_position);
// PAL: 0x80590264
extern UNKNOWN_FUNCTION(PlayerPointers_getMat);
// PAL: 0x80590288
extern UNKNOWN_FUNCTION(various_stuff_set_player_rotation);
// PAL: 0x805902dc
extern UNKNOWN_FUNCTION(PlayerPointers_getWheelCount0);
// PAL: 0x805902ec
extern UNKNOWN_FUNCTION(PlayerPointers_getWheelCount1);
// PAL: 0x8059031c
extern UNKNOWN_FUNCTION(unk_8059031c);
// PAL: 0x80590390
extern UNKNOWN_FUNCTION(unk_80590390);
// PAL: 0x805903ac
extern UNKNOWN_FUNCTION(kartPhysics__Q24Kart15KartObjectProxyFv);
// PAL: 0x805903cc
extern UNKNOWN_FUNCTION(kartDynamics__Q24Kart15KartObjectProxyFv);
// PAL: 0x805903f4
extern UNKNOWN_FUNCTION(KartAccessor_getInput);
// PAL: 0x8059041c
extern UNKNOWN_FUNCTION(unk_8059041c);
// PAL: 0x80590650
extern UNKNOWN_FUNCTION(PlayerPointers_isReal);
// PAL: 0x80590664
extern UNKNOWN_FUNCTION(PlayerPointers_isCpu);
// PAL: 0x80590678
extern UNKNOWN_FUNCTION(PlayerPointers_isGhost);
// PAL: 0x805906b4
extern UNKNOWN_FUNCTION(kartSus__Q24Kart15KartObjectProxyFl);
// PAL: 0x80590764
extern UNKNOWN_FUNCTION(kartPhysicsEngine__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059077c
extern UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590794
extern UNKNOWN_FUNCTION(kartSnd__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907a0
extern UNKNOWN_FUNCTION(unk_805907a0);
// PAL: 0x805907b0
extern UNKNOWN_FUNCTION(unk_805907b0);
// PAL: 0x8059081c
extern UNKNOWN_FUNCTION(bodyColInfo__Q24Kart15KartObjectProxyCFv);
// PAL: 0x8059084c
extern UNKNOWN_FUNCTION(kartCollide__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590874
extern UNKNOWN_FUNCTION(kartStats__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590888
extern UNKNOWN_FUNCTION(bsp__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590a10
extern UNKNOWN_FUNCTION(PlayerPointers_getVehicleType);
// PAL: 0x80590a40
extern UNKNOWN_FUNCTION(kartModel__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590a4c
extern UNKNOWN_FUNCTION(unk_80590a4c);
// PAL: 0x80590a5c
extern UNKNOWN_FUNCTION(getPlayerIdx__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590a6c
extern UNKNOWN_FUNCTION(PlayerPointers_isBike);
// PAL: 0x80590a8c
extern UNKNOWN_FUNCTION(unk_80590a8c);
// PAL: 0x80590a9c
extern UNKNOWN_FUNCTION(unk_80590a9c);
// PAL: 0x80590c6c
extern UNKNOWN_FUNCTION(unk_80590c6c);
// PAL: 0x80590c94
extern UNKNOWN_FUNCTION(PlayerPointers_getBodyFront);
// PAL: 0x80590cbc
extern UNKNOWN_FUNCTION(unk_80590cbc);
// PAL: 0x80590ce4
extern UNKNOWN_FUNCTION(PlayerPointers_getMalCol2);
// PAL: 0x80590cf8
extern UNKNOWN_FUNCTION(getVehicleSpeed__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d08
extern UNKNOWN_FUNCTION(playerPointers_getSpeed);
// PAL: 0x80590d20
extern UNKNOWN_FUNCTION(kartAction__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d5c
extern UNKNOWN_FUNCTION(unk_80590d5c);
// PAL: 0x80590da4
extern UNKNOWN_FUNCTION(unk_80590da4);
// PAL: 0x80590dc0
extern UNKNOWN_FUNCTION(getSpeedRatioCapped__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590e04
extern UNKNOWN_FUNCTION(unk_80590e04);
// PAL: 0x80590e28
extern UNKNOWN_FUNCTION(unk_80590e28);
// PAL: 0x80590e40
extern UNKNOWN_FUNCTION(unk_80590e40);
// PAL: 0x80590e58
extern UNKNOWN_FUNCTION(unk_80590e58);
// PAL: 0x80590e8c
extern UNKNOWN_FUNCTION(unk_80590e8c);
// PAL: 0x80590ea4
extern UNKNOWN_FUNCTION(unk_80590ea4);
// PAL: 0x80590ed8
extern UNKNOWN_FUNCTION(unk_80590ed8);
// PAL: 0x80590f38
extern UNKNOWN_FUNCTION(unk_80590f38);
// PAL: 0x80590f70
extern UNKNOWN_FUNCTION(unk_80590f70);
// PAL: 0x80590f90
extern UNKNOWN_FUNCTION(unk_80590f90);
// PAL: 0x8059102c
extern UNKNOWN_FUNCTION(unk_8059102c);
// PAL: 0x80591038
extern UNKNOWN_FUNCTION(unk_80591038);
// PAL: 0x80591044
extern UNKNOWN_FUNCTION(unk_80591044);
// PAL: 0x80591050
extern UNKNOWN_FUNCTION(unk_80591050);
// PAL: 0x8059108c
extern UNKNOWN_FUNCTION(kartBlink__Q24Kart15KartObjectProxyFv);
// PAL: 0x805910a4
extern UNKNOWN_FUNCTION(kartAccessor_5c__Q24Kart15KartObjectProxyFv);
// PAL: 0x805910c0
extern UNKNOWN_FUNCTION(kartEnemy__Q24Kart15KartObjectProxyFv);
// PAL: 0x805911a8
extern UNKNOWN_FUNCTION(unk_805911a8);
// PAL: 0x805911c0
extern UNKNOWN_FUNCTION(unk_805911c0);
// PAL: 0x80591428
extern UNKNOWN_FUNCTION(kartAccessor_44__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591440
extern UNKNOWN_FUNCTION(kartNetSender__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059144c
extern UNKNOWN_FUNCTION(kartNetReceiver__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591458
extern UNKNOWN_FUNCTION(PlayerPointers_getRacedataFactoryFlags);
// PAL: 0x80591468
extern UNKNOWN_FUNCTION(unk_80591468);
// PAL: 0x805914bc
extern UNKNOWN_FUNCTION(getScale__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059152c
extern UNKNOWN_FUNCTION(kartAccessor_50__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591618
extern UNKNOWN_FUNCTION(kartAccessor_60__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591664
extern UNKNOWN_FUNCTION(PlayerPointers_resetInertia);
// PAL: 0x80591784
extern UNKNOWN_FUNCTION(unk_80591784);
// PAL: 0x805917c0
extern UNKNOWN_FUNCTION(unk_805917c0);
// PAL: 0x805917f4
extern UNKNOWN_FUNCTION(unk_805917f4);
// PAL: 0x805918e0
extern UNKNOWN_FUNCTION(unk_805918e0);
// PAL: 0x80591924
extern UNKNOWN_FUNCTION(unk_80591924);
// PAL: 0x8059197c
extern UNKNOWN_FUNCTION(unk_8059197c);
// PAL: 0x80595cb4
extern UNKNOWN_FUNCTION(unk_80595cb4);
// PAL: 0x80597934
extern UNKNOWN_FUNCTION(unk_80597934);
// PAL: 0x80598338
extern UNKNOWN_FUNCTION(unk_80598338);
// PAL: 0x80598be4
extern UNKNOWN_FUNCTION(tire0_set_initial_physics_values);
// PAL: 0x8059b7b8
extern UNKNOWN_FUNCTION(unk_8059b7b8);
// PAL: 0x8059bc44
extern UNKNOWN_FUNCTION(unk_8059bc44);
// PAL: 0x8059c118
extern UNKNOWN_FUNCTION(cancelBullet);
// PAL: 0x8059d0c0
extern UNKNOWN_FUNCTION(unk_8059d0c0);
// PAL: 0x8059fc48
extern UNKNOWN_FUNCTION(addInstantaneousSpecialRot__Q24Kart11KartPhysicsFRCQ23EGG5Quatf);
// PAL: 0x8059fd0c
extern UNKNOWN_FUNCTION(addInstantaneousExtraRot__Q24Kart11KartPhysicsFRCQ23EGG5Quatf);
// PAL: 0x805a0410
extern UNKNOWN_FUNCTION(resetPendingOrientations__Q24Kart11KartPhysicsFv);
// PAL: 0x805ae7b4
extern UNKNOWN_FUNCTION(unk_805ae7b4);
// PAL: 0x805ae9ec
extern UNKNOWN_FUNCTION(VEC3_perpInPlane);
// PAL: 0x805aeb88
extern UNKNOWN_FUNCTION(projUnit__6RKGeomFRQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x805aebd0
extern UNKNOWN_FUNCTION(rejUnit__6RKGeomFRQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x805aec24
extern UNKNOWN_FUNCTION(projAndRej__6RKGeomFRQ23EGG8Vector3fRQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x805b4d24
extern UNKNOWN_FUNCTION(reset__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5ce8
extern UNKNOWN_FUNCTION(applyWrenchScaled__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3ff);
// PAL: 0x805b6388
extern UNKNOWN_FUNCTION(addForce__Q24Kart12KartDynamicsFRCQ23EGG8Vector3f);
// PAL: 0x806a1808
extern UNKNOWN_FUNCTION(unk_806a1808);
// PAL: 0x806a3948
extern UNKNOWN_FUNCTION(unk_806a3948);
// PAL: 0x806a3ac4
extern UNKNOWN_FUNCTION(unk_806a3ac4);
// PAL: 0x806a7c8c
extern UNKNOWN_FUNCTION(unk_806a7c8c);
// PAL: 0x806a7fa0
extern UNKNOWN_FUNCTION(unk_806a7fa0);
// PAL: 0x806aa1c8
extern UNKNOWN_FUNCTION(unk_806aa1c8);
// PAL: 0x806aa4cc
extern UNKNOWN_FUNCTION(unk_806aa4cc);
// PAL: 0x806aa988
extern UNKNOWN_FUNCTION(unk_806aa988);
// PAL: 0x806aaba8
extern UNKNOWN_FUNCTION(unk_806aaba8);
// PAL: 0x806abb1c
extern UNKNOWN_FUNCTION(unk_806abb1c);
// PAL: 0x806ac400
extern UNKNOWN_FUNCTION(unk_806ac400);
// PAL: 0x806b2964
extern UNKNOWN_FUNCTION(unk_806b2964);
// PAL: 0x806b2dac
extern UNKNOWN_FUNCTION(unk_806b2dac);
// PAL: 0x80708b44
extern UNKNOWN_FUNCTION(unk_80708b44);
// PAL: 0x80708bac
extern UNKNOWN_FUNCTION(unk_80708bac);
// PAL: 0x80708d48
extern UNKNOWN_FUNCTION(unk_80708d48);
// PAL: 0x80708ee4
extern UNKNOWN_FUNCTION(unk_80708ee4);
// PAL: 0x80709150
extern UNKNOWN_FUNCTION(unk_80709150);
// PAL: 0x8070b09c
extern UNKNOWN_FUNCTION(unk_8070b09c);
// PAL: 0x8070feb0
extern UNKNOWN_FUNCTION(unk_8070feb0);
// PAL: 0x8071e734
extern UNKNOWN_FUNCTION(unk_8071e734);
// PAL: 0x807263b0
extern UNKNOWN_FUNCTION(unk_807263b0);
// PAL: 0x80787d50
extern UNKNOWN_FUNCTION(unk_80787d50);
// PAL: 0x8078f320
extern UNKNOWN_FUNCTION(checkSpherePartialPush__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field14ColInfoPartialPUlfUl);
// PAL: 0x8078f500
extern UNKNOWN_FUNCTION(checkSphereFull__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8078f784
extern UNKNOWN_FUNCTION(checkSphereFullPush__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8079870c
extern UNKNOWN_FUNCTION(unk_8079870c);
// PAL: 0x80798848
extern UNKNOWN_FUNCTION(unk_80798848);
// PAL: 0x80798a30
extern UNKNOWN_FUNCTION(unk_80798a30);
// PAL: 0x80798b28
extern UNKNOWN_FUNCTION(unk_80798b28);
// PAL: 0x807b99d4
extern UNKNOWN_FUNCTION(unk_807b99d4);
// PAL: 0x807bd96c
extern UNKNOWN_FUNCTION(findClosestCollisionEntry__5FieldFPUlUl);
// PAL: 0x807c6a14
extern UNKNOWN_FUNCTION(unk_807c6a14);
// PAL: 0x807d396c
extern UNKNOWN_FUNCTION(unk_807d396c);
// PAL: 0x807d3d58
extern UNKNOWN_FUNCTION(unk_807d3d58);
// PAL: 0x807d3f10
extern UNKNOWN_FUNCTION(unk_807d3f10);
// PAL: 0x8082b3d4
extern UNKNOWN_FUNCTION(unk_8082b3d4);
// PAL: 0x8082b3ec
extern UNKNOWN_FUNCTION(unk_8082b3ec);
// PAL: 0x8082b400
extern UNKNOWN_FUNCTION(unk_8082b400);
// PAL: 0x808646f0
extern UNKNOWN_FUNCTION(unk_808646f0);
// PAL: 0x80865390
extern UNKNOWN_FUNCTION(unk_80865390);
// PAL: 0x808655b4
extern UNKNOWN_FUNCTION(unk_808655b4); // Extern data references.
// PAL: 0x802a4100
extern UNKNOWN_DATA(lbl_802a4100);
// PAL: 0x802a4118
extern UNKNOWN_DATA(RKSystem_ex);
// PAL: 0x802a4130
extern UNKNOWN_DATA(RKSystem_ey);
// PAL: 0x802a4148
extern UNKNOWN_DATA(lbl_802a4148);
// PAL: 0x80384ba0
extern UNKNOWN_DATA(zero__Q23EGG8Vector3f);
// PAL: 0x80384bd0
extern UNKNOWN_DATA(ey__Q23EGG8Vector3f);
// PAL: 0x80891a00
extern UNKNOWN_DATA(lbl_80891a00);
// PAL: 0x80891a04
extern UNKNOWN_DATA(lbl_80891a04);
// PAL: 0x80891a0c
extern UNKNOWN_DATA(lbl_80891a0c);
// PAL: 0x80891a18
extern UNKNOWN_DATA(lbl_80891a18);
// PAL: 0x80891a1c
extern UNKNOWN_DATA(lbl_80891a1c);
// PAL: 0x80891a20
extern UNKNOWN_DATA(lbl_80891a20);
// PAL: 0x80891a44
extern UNKNOWN_DATA(lbl_80891a44);
// PAL: 0x80891a4c
extern UNKNOWN_DATA(lbl_80891a4c);
// PAL: 0x80891a54
extern UNKNOWN_DATA(lbl_80891a54);
// PAL: 0x80891a58
extern UNKNOWN_DATA(lbl_80891a58);
// PAL: 0x80891a60
extern UNKNOWN_DATA(lbl_80891a60);
// PAL: 0x80891a90
extern UNKNOWN_DATA(lbl_80891a90);
// PAL: 0x80891ab4
extern UNKNOWN_DATA(lbl_80891ab4);
// PAL: 0x80891ac0
extern UNKNOWN_DATA(lbl_80891ac0);
// PAL: 0x80891ad0
extern UNKNOWN_DATA(lbl_80891ad0);
// PAL: 0x80891ad4
extern UNKNOWN_DATA(lbl_80891ad4);
// PAL: 0x808a6700
extern UNKNOWN_DATA(gColInfo);
// PAL: 0x808b5818
extern UNKNOWN_DATA(lbl_808b5818);
// PAL: 0x808b5844
extern UNKNOWN_DATA(lbl_808b5844);
// PAL: 0x808b5854
extern UNKNOWN_DATA(lbl_808b5854);
// PAL: 0x808b587c
extern UNKNOWN_DATA(lbl_808b587c);
// PAL: 0x808b5890
extern UNKNOWN_DATA(lbl_808b5890);
// PAL: 0x808b58f0
extern UNKNOWN_DATA(lbl_808b58f0);
// PAL: 0x808b5904
extern UNKNOWN_DATA(lbl_808b5904);
// PAL: 0x808b5954
extern UNKNOWN_DATA(lbl_808b5954);
// PAL: 0x808b596a
extern UNKNOWN_DATA(lbl_808b596a);
// PAL: 0x808b5994
extern UNKNOWN_DATA(lbl_808b5994);
// PAL: 0x808b59c0
extern UNKNOWN_DATA(lbl_808b59c0);
// PAL: 0x808b59c4
extern UNKNOWN_DATA(lbl_808b59c4);
// PAL: 0x808b59f4
extern UNKNOWN_DATA(lbl_808b59f4);
// PAL: 0x808b59f8
extern UNKNOWN_DATA(lbl_808b59f8);
// PAL: 0x808b59fc
extern UNKNOWN_DATA(lbl_808b59fc);
// PAL: 0x808b5a00
extern UNKNOWN_DATA(lbl_808b5a00);
// PAL: 0x808b5a14
extern UNKNOWN_DATA(lbl_808b5a14);
// PAL: 0x808b5a18
extern UNKNOWN_DATA(lbl_808b5a18);
// PAL: 0x808b5a48
extern UNKNOWN_DATA(lbl_808b5a48);
// PAL: 0x808b5aa8
extern UNKNOWN_DATA(lbl_808b5aa8);
// PAL: 0x808b5ab4
extern UNKNOWN_DATA(lbl_808b5ab4);
// PAL: 0x808b5ab8
extern UNKNOWN_DATA(lbl_808b5ab8);
// PAL: 0x808b5aba
extern UNKNOWN_DATA(lbl_808b5aba);
// PAL: 0x808b5abc
extern UNKNOWN_DATA(lbl_808b5abc);
// PAL: 0x808b5ac8
extern UNKNOWN_DATA(lbl_808b5ac8);
// PAL: 0x808b5ad8
extern UNKNOWN_DATA(lbl_808b5ad8);
// PAL: 0x808b5adc
extern UNKNOWN_DATA(lbl_808b5adc);
// PAL: 0x808b5ae0
extern UNKNOWN_DATA(lbl_808b5ae0);
// PAL: 0x808b5aec
extern UNKNOWN_DATA(lbl_808b5aec);
// PAL: 0x808b5af0
extern UNKNOWN_DATA(lbl_808b5af0);
// PAL: 0x808b5af4
extern UNKNOWN_DATA(lbl_808b5af4);
// PAL: 0x808b5b0c
extern UNKNOWN_DATA(lbl_808b5b0c);
// PAL: 0x808b5b10
extern UNKNOWN_DATA(lbl_808b5b10);
// PAL: 0x808b5b1c
extern UNKNOWN_DATA(lbl_808b5b1c);
// PAL: 0x808b5b28
extern UNKNOWN_DATA(lbl_808b5b28);
// PAL: 0x808b5b2a
extern UNKNOWN_DATA(lbl_808b5b2a);
// PAL: 0x808b5b30
extern UNKNOWN_DATA(lbl_808b5b30);
// PAL: 0x808b5b32
extern UNKNOWN_DATA(lbl_808b5b32);
// PAL: 0x808b5b64
extern UNKNOWN_DATA(lbl_808b5b64);
// PAL: 0x808b5b68
extern UNKNOWN_DATA(lbl_808b5b68);
// PAL: 0x808b5b70
extern UNKNOWN_DATA(lbl_808b5b70);
// PAL: 0x808b5b8c
extern UNKNOWN_DATA(lbl_808b5b8c);
// PAL: 0x808b5b90
extern UNKNOWN_DATA(lbl_808b5b90);
// PAL: 0x808b5bb4
extern UNKNOWN_DATA(lbl_808b5bb4);
// PAL: 0x808b5bb8
extern UNKNOWN_DATA(lbl_808b5bb8);
// PAL: 0x808b5bc4
extern UNKNOWN_DATA(lbl_808b5bc4);
// PAL: 0x808b5bc6
extern UNKNOWN_DATA(lbl_808b5bc6);
// PAL: 0x808b5bc8
extern UNKNOWN_DATA(lbl_808b5bc8);
// PAL: 0x808b5bcc
extern UNKNOWN_DATA(lbl_808b5bcc);
// PAL: 0x808b5c58
extern UNKNOWN_DATA(lbl_808b5c58);
// PAL: 0x808b5c90
extern UNKNOWN_DATA(lbl_808b5c90);
// PAL: 0x808b5cc2
extern UNKNOWN_DATA(lbl_808b5cc2);
// PAL: 0x808b5cc6
extern UNKNOWN_DATA(lbl_808b5cc6);
// PAL: 0x808b5cc8
extern UNKNOWN_DATA(lbl_808b5cc8);
// PAL: 0x808b5ccc
extern UNKNOWN_DATA(lbl_808b5ccc);
// PAL: 0x808b5cd0
extern UNKNOWN_DATA(lbl_808b5cd0);
// PAL: 0x808b5cd4
extern UNKNOWN_DATA(lbl_808b5cd4);
// PAL: 0x808b5ce0
extern UNKNOWN_DATA(lbl_808b5ce0);
// PAL: 0x808b5ce8
extern UNKNOWN_DATA(lbl_808b5ce8);
// PAL: 0x808b5ee8
extern UNKNOWN_DATA(lbl_808b5ee8);
// PAL: 0x808b5f60
extern UNKNOWN_DATA(lbl_808b5f60);
// PAL: 0x808b5fcc
extern UNKNOWN_DATA(lbl_808b5fcc);
// PAL: 0x808b5fd8
extern UNKNOWN_DATA(lbl_808b5fd8);
// PAL: 0x808b5fe4
extern UNKNOWN_DATA(lbl_808b5fe4);
// PAL: 0x809bd6e8
extern UNKNOWN_DATA(spInstance__Q26System9CourseMap);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd730
extern UNKNOWN_DATA(spInstance__Q26System11RaceManager);
// PAL: 0x809c18e0
extern UNKNOWN_DATA(lbl_809c18e0);
// PAL: 0x809c18f8
extern UNKNOWN_DATA(lbl_809c18f8);
// PAL: 0x809c21d0
extern UNKNOWN_DATA(lbl_809c21d0);
// PAL: 0x809c27f0
extern UNKNOWN_DATA(lbl_809c27f0);
// PAL: 0x809c28b8
extern UNKNOWN_DATA(lbl_809c28b8);
// PAL: 0x809c2f44
extern UNKNOWN_DATA(spInstance__Q25Field11CourseModel);
// PAL: 0x809c3618
extern UNKNOWN_DATA(lbl_809c3618);
// PAL: 0x809c3bdc
extern UNKNOWN_DATA(closestCollisionEntry__5Field);
// PAL: 0x809c3c04
extern UNKNOWN_DATA(VEC_INFINITY);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
// PAL: 0x809c4748
extern UNKNOWN_DATA(lbl_809c4748);
// PAL: 0x809c496c
extern UNKNOWN_DATA(lbl_809c496c);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: PlayerSub10_construct
// PAL: 0x80577fc4..0x8057811c
MARK_BINARY_BLOB(PlayerSub10_construct, 0x80577fc4, 0x8057811c);
asm UNKNOWN_FUNCTION(PlayerSub10_construct){
#include "asm/80577fc4.s"
}

// Symbol: PlayerBoost_destroy
// PAL: 0x8057811c..0x8057815c
MARK_BINARY_BLOB(PlayerBoost_destroy, 0x8057811c, 0x8057815c);
asm UNKNOWN_FUNCTION(PlayerBoost_destroy){
#include "asm/8057811c.s"
}

// Symbol: unk_8057815c
// PAL: 0x8057815c..0x8057819c
MARK_BINARY_BLOB(unk_8057815c, 0x8057815c, 0x8057819c);
asm UNKNOWN_FUNCTION(unk_8057815c){
#include "asm/8057815c.s"
}

// Symbol: unk_8057819c
// PAL: 0x8057819c..0x805781dc
MARK_BINARY_BLOB(unk_8057819c, 0x8057819c, 0x805781dc);
asm UNKNOWN_FUNCTION(unk_8057819c){
#include "asm/8057819c.s"
}

// Symbol: unk_805781dc
// PAL: 0x805781dc..0x8057821c
MARK_BINARY_BLOB(unk_805781dc, 0x805781dc, 0x8057821c);
asm UNKNOWN_FUNCTION(unk_805781dc){
#include "asm/805781dc.s"
}

// Symbol: PlayerSub10_initTrickZipper
// PAL: 0x8057821c..0x8057829c
MARK_BINARY_BLOB(PlayerSub10_initTrickZipper, 0x8057821c, 0x8057829c);
asm UNKNOWN_FUNCTION(PlayerSub10_initTrickZipper){
#include "asm/8057821c.s"
}

// Symbol: PlayerSub10_resetHard
// PAL: 0x8057829c..0x805784d4
MARK_BINARY_BLOB(PlayerSub10_resetHard, 0x8057829c, 0x805784d4);
asm UNKNOWN_FUNCTION(PlayerSub10_resetHard){
#include "asm/8057829c.s"
}

// Symbol: PlayerSub10_init2
// PAL: 0x805784d4..0x805788dc
MARK_BINARY_BLOB(PlayerSub10_init2, 0x805784d4, 0x805788dc);
asm UNKNOWN_FUNCTION(PlayerSub10_init2){
#include "asm/805784d4.s"
}

// Symbol: PlayerSub10_update
// PAL: 0x805788dc..0x80579960
MARK_BINARY_BLOB(PlayerSub10_update, 0x805788dc, 0x80579960);
asm UNKNOWN_FUNCTION(PlayerSub10_update){
#include "asm/805788dc.s"
}

// Symbol: unk_80579960
// PAL: 0x80579960..0x80579968
MARK_BINARY_BLOB(unk_80579960, 0x80579960, 0x80579968);
asm UNKNOWN_FUNCTION(unk_80579960){
#include "asm/80579960.s"
}

// Symbol: PlayerSub10_updateHopPhysics
// PAL: 0x80579968..0x805799ac
MARK_BINARY_BLOB(PlayerSub10_updateHopPhysics, 0x80579968, 0x805799ac);
asm UNKNOWN_FUNCTION(PlayerSub10_updateHopPhysics){
#include "asm/80579968.s"
}

// Symbol: PlayerSub10_respawn
// PAL: 0x805799ac..0x80579a50
MARK_BINARY_BLOB(PlayerSub10_respawn, 0x805799ac, 0x80579a50);
asm UNKNOWN_FUNCTION(PlayerSub10_respawn){
#include "asm/805799ac.s"
}

// Symbol: unk_80579a50
// PAL: 0x80579a50..0x80579ce4
MARK_BINARY_BLOB(unk_80579a50, 0x80579a50, 0x80579ce4);
asm UNKNOWN_FUNCTION(unk_80579a50){
#include "asm/80579a50.s"
}

// Symbol: unk_80579ce4
// PAL: 0x80579ce4..0x80579da8
MARK_BINARY_BLOB(unk_80579ce4, 0x80579ce4, 0x80579da8);
asm UNKNOWN_FUNCTION(unk_80579ce4){
#include "asm/80579ce4.s"
}

// Symbol: unk_80579da8
// PAL: 0x80579da8..0x80579f20
MARK_BINARY_BLOB(unk_80579da8, 0x80579da8, 0x80579f20);
asm UNKNOWN_FUNCTION(unk_80579da8){
#include "asm/80579da8.s"
}

// Symbol: unk_80579f20
// PAL: 0x80579f20..0x80579f6c
MARK_BINARY_BLOB(unk_80579f20, 0x80579f20, 0x80579f6c);
asm UNKNOWN_FUNCTION(unk_80579f20){
#include "asm/80579f20.s"
}

// Symbol: unk_80579f6c
// PAL: 0x80579f6c..0x80579fe4
MARK_BINARY_BLOB(unk_80579f6c, 0x80579f6c, 0x80579fe4);
asm UNKNOWN_FUNCTION(unk_80579f6c){
#include "asm/80579f6c.s"
}

// Symbol: PlayerSub10_somethingWheelieBump
// PAL: 0x80579fe4..0x8057a13c
MARK_BINARY_BLOB(PlayerSub10_somethingWheelieBump, 0x80579fe4, 0x8057a13c);
asm UNKNOWN_FUNCTION(PlayerSub10_somethingWheelieBump){
#include "asm/80579fe4.s"
}

// Symbol: unk_8057a13c
// PAL: 0x8057a13c..0x8057a140
MARK_BINARY_BLOB(unk_8057a13c, 0x8057a13c, 0x8057a140);
asm UNKNOWN_FUNCTION(unk_8057a13c){
#include "asm/8057a13c.s"
}

// Symbol: PlayerSub10_updateDirs
// PAL: 0x8057a140..0x8057a8b4
MARK_BINARY_BLOB(PlayerSub10_updateDirs, 0x8057a140, 0x8057a8b4);
asm UNKNOWN_FUNCTION(PlayerSub10_updateDirs){
#include "asm/8057a140.s"
}

// Symbol: PlayerSub10_updateTurn
// PAL: 0x8057a8b4..0x8057ab68
MARK_BINARY_BLOB(PlayerSub10_updateTurn, 0x8057a8b4, 0x8057ab68);
asm UNKNOWN_FUNCTION(PlayerSub10_updateTurn){
#include "asm/8057a8b4.s"
}

// Symbol: PlayerSub10_updateVehicleSpeed
// PAL: 0x8057ab68..0x8057b028
MARK_BINARY_BLOB(PlayerSub10_updateVehicleSpeed, 0x8057ab68, 0x8057b028);
asm UNKNOWN_FUNCTION(PlayerSub10_updateVehicleSpeed){
#include "asm/8057ab68.s"
}

// Symbol: unk_8057b028
// PAL: 0x8057b028..0x8057b108
MARK_BINARY_BLOB(unk_8057b028, 0x8057b028, 0x8057b108);
asm UNKNOWN_FUNCTION(unk_8057b028){
#include "asm/8057b028.s"
}

// Symbol: PlayerSub10_computeWallCollisionSpeedFactor
// PAL: 0x8057b108..0x8057b29c
MARK_BINARY_BLOB(PlayerSub10_computeWallCollisionSpeedFactor, 0x8057b108,
                 0x8057b29c);
asm UNKNOWN_FUNCTION(PlayerSub10_computeWallCollisionSpeedFactor){
#include "asm/8057b108.s"
}

// Symbol: unk_8057b29c
// PAL: 0x8057b29c..0x8057b2a0
MARK_BINARY_BLOB(unk_8057b29c, 0x8057b29c, 0x8057b2a0);
asm UNKNOWN_FUNCTION(unk_8057b29c){
#include "asm/8057b29c.s"
}

// Symbol: unk_8057b2a0
// PAL: 0x8057b2a0..0x8057b77c
MARK_BINARY_BLOB(unk_8057b2a0, 0x8057b2a0, 0x8057b77c);
asm UNKNOWN_FUNCTION(unk_8057b2a0){
#include "asm/8057b2a0.s"
}

// Symbol: unk_8057b77c
// PAL: 0x8057b77c..0x8057b868
MARK_BINARY_BLOB(unk_8057b77c, 0x8057b77c, 0x8057b868);
asm UNKNOWN_FUNCTION(unk_8057b77c){
#include "asm/8057b77c.s"
}

// Symbol: get_acceleration_from_speed
// PAL: 0x8057b868..0x8057b99c
MARK_BINARY_BLOB(get_acceleration_from_speed, 0x8057b868, 0x8057b99c);
asm UNKNOWN_FUNCTION(get_acceleration_from_speed){
#include "asm/8057b868.s"
}

// Symbol: PlayerSub10_setBulletHardSpeedLimit
// PAL: 0x8057b99c..0x8057b9ac
MARK_BINARY_BLOB(PlayerSub10_setBulletHardSpeedLimit, 0x8057b99c, 0x8057b9ac);
asm UNKNOWN_FUNCTION(PlayerSub10_setBulletHardSpeedLimit){
#include "asm/8057b99c.s"
}

// Symbol: PlayerSub10_setRegularHardSpeedLimit
// PAL: 0x8057b9ac..0x8057b9bc
MARK_BINARY_BLOB(PlayerSub10_setRegularHardSpeedLimit, 0x8057b9ac, 0x8057b9bc);
asm UNKNOWN_FUNCTION(PlayerSub10_setRegularHardSpeedLimit){
#include "asm/8057b9ac.s"
}

// Symbol: PlayerSub10_updateAcceleration
// PAL: 0x8057b9bc..0x8057c3c8
MARK_BINARY_BLOB(PlayerSub10_updateAcceleration, 0x8057b9bc, 0x8057c3c8);
asm UNKNOWN_FUNCTION(PlayerSub10_updateAcceleration){
#include "asm/8057b9bc.s"
}

// Symbol: PlayerSub10_getWheelieSoftSpeedLimitBonus
// PAL: 0x8057c3c8..0x8057c3d4
MARK_BINARY_BLOB(PlayerSub10_getWheelieSoftSpeedLimitBonus, 0x8057c3c8,
                 0x8057c3d4);
asm UNKNOWN_FUNCTION(PlayerSub10_getWheelieSoftSpeedLimitBonus){
#include "asm/8057c3c8.s"
}

// Symbol: PlayerSub10_updateOffroad
// PAL: 0x8057c3d4..0x8057c5e8
MARK_BINARY_BLOB(PlayerSub10_updateOffroad, 0x8057c3d4, 0x8057c5e8);
asm UNKNOWN_FUNCTION(PlayerSub10_updateOffroad){
#include "asm/8057c3d4.s"
}

// Symbol: unk_8057c5e8
// PAL: 0x8057c5e8..0x8057c69c
MARK_BINARY_BLOB(unk_8057c5e8, 0x8057c5e8, 0x8057c69c);
asm UNKNOWN_FUNCTION(unk_8057c5e8){
#include "asm/8057c5e8.s"
}

// Symbol: PlayerSub10_updateRotation
// PAL: 0x8057c69c..0x8057cdd4
MARK_BINARY_BLOB(PlayerSub10_updateRotation, 0x8057c69c, 0x8057cdd4);
asm UNKNOWN_FUNCTION(PlayerSub10_updateRotation){
#include "asm/8057c69c.s"
}

// Symbol: unk_8057cdd4
// PAL: 0x8057cdd4..0x8057cf0c
MARK_BINARY_BLOB(unk_8057cdd4, 0x8057cdd4, 0x8057cf0c);
asm UNKNOWN_FUNCTION(unk_8057cdd4){
#include "asm/8057cdd4.s"
}

// Symbol: PlayerSub10_updateVehicleRotationVector
// PAL: 0x8057cf0c..0x8057d1d4
MARK_BINARY_BLOB(PlayerSub10_updateVehicleRotationVector, 0x8057cf0c,
                 0x8057d1d4);
asm UNKNOWN_FUNCTION(PlayerSub10_updateVehicleRotationVector){
#include "asm/8057cf0c.s"
}

// Symbol: PlayerSub10_updateStandstillBoostRot
// PAL: 0x8057d1d4..0x8057d398
MARK_BINARY_BLOB(PlayerSub10_updateStandstillBoostRot, 0x8057d1d4, 0x8057d398);
asm UNKNOWN_FUNCTION(PlayerSub10_updateStandstillBoostRot){
#include "asm/8057d1d4.s"
}

// Symbol: PlayerSub10_updateTop
// PAL: 0x8057d398..0x8057d888
MARK_BINARY_BLOB(PlayerSub10_updateTop, 0x8057d398, 0x8057d888);
asm UNKNOWN_FUNCTION(PlayerSub10_updateTop){
#include "asm/8057d398.s"
}

// Symbol: PlayerSub10_updateTopDuringAirtime
// PAL: 0x8057d888..0x8057da18
MARK_BINARY_BLOB(PlayerSub10_updateTopDuringAirtime, 0x8057d888, 0x8057da18);
asm UNKNOWN_FUNCTION(PlayerSub10_updateTopDuringAirtime){
#include "asm/8057d888.s"
}

// Symbol: PlayerSub10_canHop
// PAL: 0x8057da18..0x8057da5c
MARK_BINARY_BLOB(PlayerSub10_canHop, 0x8057da18, 0x8057da5c);
asm UNKNOWN_FUNCTION(PlayerSub10_canHop){
#include "asm/8057da18.s"
}

// Symbol: PlayerSub10_hop
// PAL: 0x8057da5c..0x8057dc40
MARK_BINARY_BLOB(PlayerSub10_hop, 0x8057da5c, 0x8057dc40);
asm UNKNOWN_FUNCTION(PlayerSub10_hop){
#include "asm/8057da5c.s"
}

// Symbol: PlayerSub10_cancelWheelie
// PAL: 0x8057dc40..0x8057dc44
MARK_BINARY_BLOB(PlayerSub10_cancelWheelie, 0x8057dc40, 0x8057dc44);
asm UNKNOWN_FUNCTION(PlayerSub10_cancelWheelie){
#include "asm/8057dc40.s"
}

// Symbol: PlayerSub10_updateManualDrift
// PAL: 0x8057dc44..0x8057e0dc
MARK_BINARY_BLOB(PlayerSub10_updateManualDrift, 0x8057dc44, 0x8057e0dc);
asm UNKNOWN_FUNCTION(PlayerSub10_updateManualDrift){
#include "asm/8057dc44.s"
}

// Symbol: PlayerSub10_updateAutoDrift
// PAL: 0x8057e0dc..0x8057e348
MARK_BINARY_BLOB(PlayerSub10_updateAutoDrift, 0x8057e0dc, 0x8057e348);
asm UNKNOWN_FUNCTION(PlayerSub10_updateAutoDrift){
#include "asm/8057e0dc.s"
}

// Symbol: unk_8057e348
// PAL: 0x8057e348..0x8057e3f4
MARK_BINARY_BLOB(unk_8057e348, 0x8057e348, 0x8057e3f4);
asm UNKNOWN_FUNCTION(unk_8057e348){
#include "asm/8057e348.s"
}

// Symbol: PlayerSub10_startManualDrift
// PAL: 0x8057e3f4..0x8057e638
MARK_BINARY_BLOB(PlayerSub10_startManualDrift, 0x8057e3f4, 0x8057e638);
asm UNKNOWN_FUNCTION(PlayerSub10_startManualDrift){
#include "asm/8057e3f4.s"
}

// Symbol: unk_8057e638
// PAL: 0x8057e638..0x8057e6f4
MARK_BINARY_BLOB(unk_8057e638, 0x8057e638, 0x8057e6f4);
asm UNKNOWN_FUNCTION(unk_8057e638){
#include "asm/8057e638.s"
}

// Symbol: unk_8057e6f4
// PAL: 0x8057e6f4..0x8057e77c
MARK_BINARY_BLOB(unk_8057e6f4, 0x8057e6f4, 0x8057e77c);
asm UNKNOWN_FUNCTION(unk_8057e6f4){
#include "asm/8057e6f4.s"
}

// Symbol: unk_8057e77c
// PAL: 0x8057e77c..0x8057e804
MARK_BINARY_BLOB(unk_8057e77c, 0x8057e77c, 0x8057e804);
asm UNKNOWN_FUNCTION(unk_8057e77c){
#include "asm/8057e77c.s"
}

// Symbol: PlayerSub10_updateHopAndSlipdrift
// PAL: 0x8057e804..0x8057e99c
MARK_BINARY_BLOB(PlayerSub10_updateHopAndSlipdrift, 0x8057e804, 0x8057e99c);
asm UNKNOWN_FUNCTION(PlayerSub10_updateHopAndSlipdrift){
#include "asm/8057e804.s"
}

// Symbol: unk_8057e99c
// PAL: 0x8057e99c..0x8057ea50
MARK_BINARY_BLOB(unk_8057e99c, 0x8057e99c, 0x8057ea50);
asm UNKNOWN_FUNCTION(unk_8057e99c){
#include "asm/8057e99c.s"
}

// Symbol: unk_8057ea50
// PAL: 0x8057ea50..0x8057ea94
MARK_BINARY_BLOB(unk_8057ea50, 0x8057ea50, 0x8057ea94);
asm UNKNOWN_FUNCTION(unk_8057ea50){
#include "asm/8057ea50.s"
}

// Symbol: unk_8057ea94
// PAL: 0x8057ea94..0x8057eab8
MARK_BINARY_BLOB(unk_8057ea94, 0x8057ea94, 0x8057eab8);
asm UNKNOWN_FUNCTION(unk_8057ea94){
#include "asm/8057ea94.s"
}

// Symbol: unk_8057eab8
// PAL: 0x8057eab8..0x8057ec28
MARK_BINARY_BLOB(unk_8057eab8, 0x8057eab8, 0x8057ec28);
asm UNKNOWN_FUNCTION(unk_8057eab8){
#include "asm/8057eab8.s"
}

// Symbol: unk_8057ec28
// PAL: 0x8057ec28..0x8057ed20
MARK_BINARY_BLOB(unk_8057ec28, 0x8057ec28, 0x8057ed20);
asm UNKNOWN_FUNCTION(unk_8057ec28){
#include "asm/8057ec28.s"
}

// Symbol: unk_8057ed20
// PAL: 0x8057ed20..0x8057ed34
MARK_BINARY_BLOB(unk_8057ed20, 0x8057ed20, 0x8057ed34);
asm UNKNOWN_FUNCTION(unk_8057ed20){
#include "asm/8057ed20.s"
}

// Symbol: unk_8057ed34
// PAL: 0x8057ed34..0x8057ed8c
MARK_BINARY_BLOB(unk_8057ed34, 0x8057ed34, 0x8057ed8c);
asm UNKNOWN_FUNCTION(unk_8057ed34){
#include "asm/8057ed34.s"
}

// Symbol: unk_8057ed8c
// PAL: 0x8057ed8c..0x8057ee50
MARK_BINARY_BLOB(unk_8057ed8c, 0x8057ed8c, 0x8057ee50);
asm UNKNOWN_FUNCTION(unk_8057ed8c){
#include "asm/8057ed8c.s"
}

// Symbol: PlayerSub10_updateMtCharge
// PAL: 0x8057ee50..0x8057efe0
MARK_BINARY_BLOB(PlayerSub10_updateMtCharge, 0x8057ee50, 0x8057efe0);
asm UNKNOWN_FUNCTION(PlayerSub10_updateMtCharge){
#include "asm/8057ee50.s"
}

// Symbol: getMaxMtCharge__Q24Kart8KartMoveFv
// PAL: 0x8057efe0..0x8057efec
MARK_BINARY_BLOB(getMaxMtCharge__Q24Kart8KartMoveFv, 0x8057efe0, 0x8057efec);
asm UNKNOWN_FUNCTION(getMaxMtCharge__Q24Kart8KartMoveFv){
#include "asm/8057efe0.s"
}

// Symbol: getMaxSmtCharge__Q24Kart8KartMoveFv
// PAL: 0x8057efec..0x8057eff8
MARK_BINARY_BLOB(getMaxSmtCharge__Q24Kart8KartMoveFv, 0x8057efec, 0x8057eff8);
asm UNKNOWN_FUNCTION(getMaxSmtCharge__Q24Kart8KartMoveFv){
#include "asm/8057efec.s"
}

// Symbol: getAppliedHopStickX__Q24Kart8KartMoveFv
// PAL: 0x8057eff8..0x8057f024
MARK_BINARY_BLOB(getAppliedHopStickX__Q24Kart8KartMoveFv, 0x8057eff8,
                 0x8057f024);
asm UNKNOWN_FUNCTION(getAppliedHopStickX__Q24Kart8KartMoveFv){
#include "asm/8057eff8.s"
}

// Symbol: unk_8057f024
// PAL: 0x8057f024..0x8057f05c
MARK_BINARY_BLOB(unk_8057f024, 0x8057f024, 0x8057f05c);
asm UNKNOWN_FUNCTION(unk_8057f024){
#include "asm/8057f024.s"
}

// Symbol: unk_8057f05c
// PAL: 0x8057f05c..0x8057f090
MARK_BINARY_BLOB(unk_8057f05c, 0x8057f05c, 0x8057f090);
asm UNKNOWN_FUNCTION(unk_8057f05c){
#include "asm/8057f05c.s"
}

// Symbol: unk_8057f090
// PAL: 0x8057f090..0x8057f1d0
MARK_BINARY_BLOB(unk_8057f090, 0x8057f090, 0x8057f1d0);
asm UNKNOWN_FUNCTION(unk_8057f090){
#include "asm/8057f090.s"
}

// Symbol: unk_8057f1d0
// PAL: 0x8057f1d0..0x8057f3d8
MARK_BINARY_BLOB(unk_8057f1d0, 0x8057f1d0, 0x8057f3d8);
asm UNKNOWN_FUNCTION(unk_8057f1d0){
#include "asm/8057f1d0.s"
}

// Symbol: PlayerSub10_activateMushroom
// PAL: 0x8057f3d8..0x8057f630
MARK_BINARY_BLOB(PlayerSub10_activateMushroom, 0x8057f3d8, 0x8057f630);
asm UNKNOWN_FUNCTION(PlayerSub10_activateMushroom){
#include "asm/8057f3d8.s"
}

// Symbol: unk_8057f630
// PAL: 0x8057f630..0x8057f7a8
MARK_BINARY_BLOB(unk_8057f630, 0x8057f630, 0x8057f7a8);
asm UNKNOWN_FUNCTION(unk_8057f630){
#include "asm/8057f630.s"
}

// Symbol: PlayerSub10_endTrick
// PAL: 0x8057f7a8..0x8057f96c
MARK_BINARY_BLOB(PlayerSub10_endTrick, 0x8057f7a8, 0x8057f96c);
asm UNKNOWN_FUNCTION(PlayerSub10_endTrick){
#include "asm/8057f7a8.s"
}

// Symbol: PlayerSub10_activateZipperBoost
// PAL: 0x8057f96c..0x8057fb6c
MARK_BINARY_BLOB(PlayerSub10_activateZipperBoost, 0x8057f96c, 0x8057fb6c);
asm UNKNOWN_FUNCTION(PlayerSub10_activateZipperBoost){
#include "asm/8057f96c.s"
}

// Symbol: unk_8057fb6c
// PAL: 0x8057fb6c..0x8057fd18
MARK_BINARY_BLOB(unk_8057fb6c, 0x8057fb6c, 0x8057fd18);
asm UNKNOWN_FUNCTION(unk_8057fb6c){
#include "asm/8057fb6c.s"
}

// Symbol: PlayerSub10_tryStartJumpPad
// PAL: 0x8057fd18..0x805800bc
MARK_BINARY_BLOB(PlayerSub10_tryStartJumpPad, 0x8057fd18, 0x805800bc);
asm UNKNOWN_FUNCTION(PlayerSub10_tryStartJumpPad){
#include "asm/8057fd18.s"
}

// Symbol: unk_805800bc
// PAL: 0x805800bc..0x80580268
MARK_BINARY_BLOB(unk_805800bc, 0x805800bc, 0x80580268);
asm UNKNOWN_FUNCTION(unk_805800bc){
#include "asm/805800bc.s"
}

// Symbol: PlayerSub10_activateStar
// PAL: 0x80580268..0x805803f0
MARK_BINARY_BLOB(PlayerSub10_activateStar, 0x80580268, 0x805803f0);
asm UNKNOWN_FUNCTION(PlayerSub10_activateStar){
#include "asm/80580268.s"
}

// Symbol: unk_805803f0
// PAL: 0x805803f0..0x80580438
MARK_BINARY_BLOB(unk_805803f0, 0x805803f0, 0x80580438);
asm UNKNOWN_FUNCTION(unk_805803f0){
#include "asm/805803f0.s"
}

// Symbol: PlayerSub10_applyLightning
// PAL: 0x80580438..0x8058051c
MARK_BINARY_BLOB(PlayerSub10_applyLightning, 0x80580438, 0x8058051c);
asm UNKNOWN_FUNCTION(PlayerSub10_applyLightning){
#include "asm/80580438.s"
}

// Symbol: unk_8058051c
// PAL: 0x8058051c..0x805805ec
MARK_BINARY_BLOB(unk_8058051c, 0x8058051c, 0x805805ec);
asm UNKNOWN_FUNCTION(unk_8058051c){
#include "asm/8058051c.s"
}

// Symbol: unk_805805ec
// PAL: 0x805805ec..0x80580648
MARK_BINARY_BLOB(unk_805805ec, 0x805805ec, 0x80580648);
asm UNKNOWN_FUNCTION(unk_805805ec){
#include "asm/805805ec.s"
}

// Symbol: unk_80580648
// PAL: 0x80580648..0x805806a4
MARK_BINARY_BLOB(unk_80580648, 0x80580648, 0x805806a4);
asm UNKNOWN_FUNCTION(unk_80580648){
#include "asm/80580648.s"
}

// Symbol: unk_805806a4
// PAL: 0x805806a4..0x80580768
MARK_BINARY_BLOB(unk_805806a4, 0x805806a4, 0x80580768);
asm UNKNOWN_FUNCTION(unk_805806a4){
#include "asm/805806a4.s"
}

// Symbol: unk_80580768
// PAL: 0x80580768..0x80580778
MARK_BINARY_BLOB(unk_80580768, 0x80580768, 0x80580778);
asm UNKNOWN_FUNCTION(unk_80580768){
#include "asm/80580768.s"
}

// Symbol: PlayerSub10_applyLightningEffect
// PAL: 0x80580778..0x80580998
MARK_BINARY_BLOB(PlayerSub10_applyLightningEffect, 0x80580778, 0x80580998);
asm UNKNOWN_FUNCTION(PlayerSub10_applyLightningEffect){
#include "asm/80580778.s"
}

// Symbol: unk_80580998
// PAL: 0x80580998..0x80580a84
MARK_BINARY_BLOB(unk_80580998, 0x80580998, 0x80580a84);
asm UNKNOWN_FUNCTION(unk_80580998){
#include "asm/80580998.s"
}

// Symbol: unk_80580a84
// PAL: 0x80580a84..0x80580b14
MARK_BINARY_BLOB(unk_80580a84, 0x80580a84, 0x80580b14);
asm UNKNOWN_FUNCTION(unk_80580a84){
#include "asm/80580a84.s"
}

// Symbol: PlayerSub10_activateMega
// PAL: 0x80580b14..0x80580cdc
MARK_BINARY_BLOB(PlayerSub10_activateMega, 0x80580b14, 0x80580cdc);
asm UNKNOWN_FUNCTION(PlayerSub10_activateMega){
#include "asm/80580b14.s"
}

// Symbol: unk_80580cdc
// PAL: 0x80580cdc..0x80580dc0
MARK_BINARY_BLOB(unk_80580cdc, 0x80580cdc, 0x80580dc0);
asm UNKNOWN_FUNCTION(unk_80580cdc){
#include "asm/80580cdc.s"
}

// Symbol: unk_80580dc0
// PAL: 0x80580dc0..0x80580f28
MARK_BINARY_BLOB(unk_80580dc0, 0x80580dc0, 0x80580f28);
asm UNKNOWN_FUNCTION(unk_80580dc0){
#include "asm/80580dc0.s"
}

// Symbol: unk_80580f28
// PAL: 0x80580f28..0x80580f9c
MARK_BINARY_BLOB(unk_80580f28, 0x80580f28, 0x80580f9c);
asm UNKNOWN_FUNCTION(unk_80580f28){
#include "asm/80580f28.s"
}

// Symbol: unk_80580f9c
// PAL: 0x80580f9c..0x80581034
MARK_BINARY_BLOB(unk_80580f9c, 0x80580f9c, 0x80581034);
asm UNKNOWN_FUNCTION(unk_80580f9c){
#include "asm/80580f9c.s"
}

// Symbol: unk_80581034
// PAL: 0x80581034..0x805810a8
MARK_BINARY_BLOB(unk_80581034, 0x80581034, 0x805810a8);
asm UNKNOWN_FUNCTION(unk_80581034){
#include "asm/80581034.s"
}

// Symbol: unk_805810a8
// PAL: 0x805810a8..0x805813a4
MARK_BINARY_BLOB(unk_805810a8, 0x805810a8, 0x805813a4);
asm UNKNOWN_FUNCTION(unk_805810a8){
#include "asm/805810a8.s"
}

// Symbol: unk_805813a4
// PAL: 0x805813a4..0x805813e8
MARK_BINARY_BLOB(unk_805813a4, 0x805813a4, 0x805813e8);
asm UNKNOWN_FUNCTION(unk_805813a4){
#include "asm/805813a4.s"
}

// Symbol: unk_805813e8
// PAL: 0x805813e8..0x8058160c
MARK_BINARY_BLOB(unk_805813e8, 0x805813e8, 0x8058160c);
asm UNKNOWN_FUNCTION(unk_805813e8){
#include "asm/805813e8.s"
}

// Symbol: unk_8058160c
// PAL: 0x8058160c..0x80581720
MARK_BINARY_BLOB(unk_8058160c, 0x8058160c, 0x80581720);
asm UNKNOWN_FUNCTION(unk_8058160c) {
#include "asm/8058160c.s"
}

namespace Kart {

void KartMove::setScale(const EGG::Vector3f scale) {
  // mScale = scale;
  mScale.x = scale.x;
  mScale.y = scale.y;
  mScale.z = scale.z;
}

} // namespace Kart

// Symbol: unk_8058173c
// PAL: 0x8058173c..0x80581778
MARK_BINARY_BLOB(unk_8058173c, 0x8058173c, 0x80581778);
asm UNKNOWN_FUNCTION(unk_8058173c){
#include "asm/8058173c.s"
}

// Symbol: unk_80581778
// PAL: 0x80581778..0x80581824
MARK_BINARY_BLOB(unk_80581778, 0x80581778, 0x80581824);
asm UNKNOWN_FUNCTION(unk_80581778){
#include "asm/80581778.s"
}

// Symbol: unk_80581824
// PAL: 0x80581824..0x8058196c
MARK_BINARY_BLOB(unk_80581824, 0x80581824, 0x8058196c);
asm UNKNOWN_FUNCTION(unk_80581824){
#include "asm/80581824.s"
}

// Symbol: unk_8058196c
// PAL: 0x8058196c..0x805819a8
MARK_BINARY_BLOB(unk_8058196c, 0x8058196c, 0x805819a8);
asm UNKNOWN_FUNCTION(unk_8058196c){
#include "asm/8058196c.s"
}

// Symbol: unk_805819a8
// PAL: 0x805819a8..0x80581a24
MARK_BINARY_BLOB(unk_805819a8, 0x805819a8, 0x80581a24);
asm UNKNOWN_FUNCTION(unk_805819a8) {
#include "asm/805819a8.s"
}

namespace Kart {

void KartMove::empty(s32 arg) { (void)arg; }

} // namespace Kart

// Symbol: PlayerSub10_activateTc
// PAL: 0x80581a28..0x80581a40
MARK_BINARY_BLOB(PlayerSub10_activateTc, 0x80581a28, 0x80581a40);
asm UNKNOWN_FUNCTION(PlayerSub10_activateTc){
#include "asm/80581a28.s"
}

// Symbol: PlayerSub10_deactivateTc
// PAL: 0x80581a40..0x80581a58
MARK_BINARY_BLOB(PlayerSub10_deactivateTc, 0x80581a40, 0x80581a58);
asm UNKNOWN_FUNCTION(PlayerSub10_deactivateTc){
#include "asm/80581a40.s"
}

// Symbol: PlayerSub10_applyInk
// PAL: 0x80581a58..0x80581b1c
MARK_BINARY_BLOB(PlayerSub10_applyInk, 0x80581a58, 0x80581b1c);
asm UNKNOWN_FUNCTION(PlayerSub10_applyInk){
#include "asm/80581a58.s"
}

// Symbol: PlayerSub10_updateInk
// PAL: 0x80581b1c..0x80581c70
MARK_BINARY_BLOB(PlayerSub10_updateInk, 0x80581b1c, 0x80581c70);
asm UNKNOWN_FUNCTION(PlayerSub10_updateInk){
#include "asm/80581b1c.s"
}

// Symbol: unk_80581c70
// PAL: 0x80581c70..0x80581c90
MARK_BINARY_BLOB(unk_80581c70, 0x80581c70, 0x80581c90);
asm UNKNOWN_FUNCTION(unk_80581c70){
#include "asm/80581c70.s"
}

// Symbol: PlayerSub10_somethingRespawnBoost
// PAL: 0x80581c90..0x8058212c
MARK_BINARY_BLOB(PlayerSub10_somethingRespawnBoost, 0x80581c90, 0x8058212c);
asm UNKNOWN_FUNCTION(PlayerSub10_somethingRespawnBoost){
#include "asm/80581c90.s"
}

// Symbol: PlayerSub10_applyStartBoost
// PAL: 0x8058212c..0x80582278
MARK_BINARY_BLOB(PlayerSub10_applyStartBoost, 0x8058212c, 0x80582278);
asm UNKNOWN_FUNCTION(PlayerSub10_applyStartBoost){
#include "asm/8058212c.s"
}

// Symbol: unk_80582278
// PAL: 0x80582278..0x805823a4
MARK_BINARY_BLOB(unk_80582278, 0x80582278, 0x805823a4);
asm UNKNOWN_FUNCTION(unk_80582278){
#include "asm/80582278.s"
}

// Symbol: unk_805823a4
// PAL: 0x805823a4..0x80582488
MARK_BINARY_BLOB(unk_805823a4, 0x805823a4, 0x80582488);
asm UNKNOWN_FUNCTION(unk_805823a4){
#include "asm/805823a4.s"
}

// Symbol: unk_80582488
// PAL: 0x80582488..0x805824c8
MARK_BINARY_BLOB(unk_80582488, 0x80582488, 0x805824c8);
asm UNKNOWN_FUNCTION(unk_80582488){
#include "asm/80582488.s"
}

// Symbol: unk_805824c8
// PAL: 0x805824c8..0x805824f0
MARK_BINARY_BLOB(unk_805824c8, 0x805824c8, 0x805824f0);
asm UNKNOWN_FUNCTION(unk_805824c8){
#include "asm/805824c8.s"
}

// Symbol: unk_805824f0
// PAL: 0x805824f0..0x80582530
MARK_BINARY_BLOB(unk_805824f0, 0x805824f0, 0x80582530);
asm UNKNOWN_FUNCTION(unk_805824f0){
#include "asm/805824f0.s"
}

// Symbol: PlayerSub10_tryEndJumpPad
// PAL: 0x80582530..0x80582694
MARK_BINARY_BLOB(PlayerSub10_tryEndJumpPad, 0x80582530, 0x80582694);
asm UNKNOWN_FUNCTION(PlayerSub10_tryEndJumpPad){
#include "asm/80582530.s"
}

// Symbol: PlayerSub10_updateBoost
// PAL: 0x80582694..0x80582804
MARK_BINARY_BLOB(PlayerSub10_updateBoost, 0x80582694, 0x80582804);
asm UNKNOWN_FUNCTION(PlayerSub10_updateBoost){
#include "asm/80582694.s"
}

// Symbol: unk_80582804
// PAL: 0x80582804..0x805828cc
MARK_BINARY_BLOB(unk_80582804, 0x80582804, 0x805828cc);
asm UNKNOWN_FUNCTION(unk_80582804){
#include "asm/80582804.s"
}

// Symbol: unk_805828cc
// PAL: 0x805828cc..0x80582d94
MARK_BINARY_BLOB(unk_805828cc, 0x805828cc, 0x80582d94);
asm UNKNOWN_FUNCTION(unk_805828cc){
#include "asm/805828cc.s"
}

// Symbol: unk_80582d94
// PAL: 0x80582d94..0x80582db4
MARK_BINARY_BLOB(unk_80582d94, 0x80582d94, 0x80582db4);
asm UNKNOWN_FUNCTION(unk_80582d94){
#include "asm/80582d94.s"
}

// Symbol: unk_80582db4
// PAL: 0x80582db4..0x80582dd8
MARK_BINARY_BLOB(unk_80582db4, 0x80582db4, 0x80582dd8);
asm UNKNOWN_FUNCTION(unk_80582db4){
#include "asm/80582db4.s"
}

// Symbol: unk_80582dd8
// PAL: 0x80582dd8..0x80582e34
MARK_BINARY_BLOB(unk_80582dd8, 0x80582dd8, 0x80582e34);
asm UNKNOWN_FUNCTION(unk_80582dd8){
#include "asm/80582dd8.s"
}

// Symbol: unk_80582e34
// PAL: 0x80582e34..0x80582f38
MARK_BINARY_BLOB(unk_80582e34, 0x80582e34, 0x80582f38);
asm UNKNOWN_FUNCTION(unk_80582e34){
#include "asm/80582e34.s"
}

// Symbol: unk_80582f38
// PAL: 0x80582f38..0x80582f58
MARK_BINARY_BLOB(unk_80582f38, 0x80582f38, 0x80582f58);
asm UNKNOWN_FUNCTION(unk_80582f38){
#include "asm/80582f38.s"
}

// Symbol: unk_80582f58
// PAL: 0x80582f58..0x80582f7c
MARK_BINARY_BLOB(unk_80582f58, 0x80582f58, 0x80582f7c);
asm UNKNOWN_FUNCTION(unk_80582f58){
#include "asm/80582f58.s"
}

// Symbol: unk_80582f7c
// PAL: 0x80582f7c..0x80582f9c
MARK_BINARY_BLOB(unk_80582f7c, 0x80582f7c, 0x80582f9c);
asm UNKNOWN_FUNCTION(unk_80582f7c){
#include "asm/80582f7c.s"
}

// Symbol: PlayerSub10_releaseMt
// PAL: 0x80582f9c..0x8058327c
MARK_BINARY_BLOB(PlayerSub10_releaseMt, 0x80582f9c, 0x8058327c);
asm UNKNOWN_FUNCTION(PlayerSub10_releaseMt){
#include "asm/80582f9c.s"
}

// Symbol: unk_8058327c
// PAL: 0x8058327c..0x805832c4
MARK_BINARY_BLOB(unk_8058327c, 0x8058327c, 0x805832c4);
asm UNKNOWN_FUNCTION(unk_8058327c){
#include "asm/8058327c.s"
}

// Symbol: unk_805832c4
// PAL: 0x805832c4..0x805832e4
MARK_BINARY_BLOB(unk_805832c4, 0x805832c4, 0x805832e4);
asm UNKNOWN_FUNCTION(unk_805832c4){
#include "asm/805832c4.s"
}

// Symbol: clearBoost__Q24Kart8KartMoveFv
// PAL: 0x805832e4..0x80583424
MARK_BINARY_BLOB(clearBoost__Q24Kart8KartMoveFv, 0x805832e4, 0x80583424);
asm UNKNOWN_FUNCTION(clearBoost__Q24Kart8KartMoveFv){
#include "asm/805832e4.s"
}

// Symbol: unk_80583424
// PAL: 0x80583424..0x8058348c
MARK_BINARY_BLOB(unk_80583424, 0x80583424, 0x8058348c);
asm UNKNOWN_FUNCTION(unk_80583424){
#include "asm/80583424.s"
}

// Symbol: unk_8058348c
// PAL: 0x8058348c..0x80583658
MARK_BINARY_BLOB(unk_8058348c, 0x8058348c, 0x80583658);
asm UNKNOWN_FUNCTION(unk_8058348c){
#include "asm/8058348c.s"
}

// Symbol: unk_80583658
// PAL: 0x80583658..0x805837cc
MARK_BINARY_BLOB(unk_80583658, 0x80583658, 0x805837cc);
asm UNKNOWN_FUNCTION(unk_80583658){
#include "asm/80583658.s"
}

// Symbol: unk_805837cc
// PAL: 0x805837cc..0x80583b84
MARK_BINARY_BLOB(unk_805837cc, 0x805837cc, 0x80583b84);
asm UNKNOWN_FUNCTION(unk_805837cc){
#include "asm/805837cc.s"
}

// Symbol: unk_80583b84
// PAL: 0x80583b84..0x80583b88
MARK_BINARY_BLOB(unk_80583b84, 0x80583b84, 0x80583b88);
asm UNKNOWN_FUNCTION(unk_80583b84){
#include "asm/80583b84.s"
}

// Symbol: PlayerSub10_updateStickyRoad
// PAL: 0x80583b88..0x80583f2c
MARK_BINARY_BLOB(PlayerSub10_updateStickyRoad, 0x80583b88, 0x80583f2c);
asm UNKNOWN_FUNCTION(PlayerSub10_updateStickyRoad){
#include "asm/80583b88.s"
}

// Symbol: unk_80583f2c
// PAL: 0x80583f2c..0x80584044
MARK_BINARY_BLOB(unk_80583f2c, 0x80583f2c, 0x80584044);
asm UNKNOWN_FUNCTION(unk_80583f2c){
#include "asm/80583f2c.s"
}

// Symbol: PlayerSub10_setInitialPhysicsValues
// PAL: 0x80584044..0x80584334
MARK_BINARY_BLOB(PlayerSub10_setInitialPhysicsValues, 0x80584044, 0x80584334);
asm UNKNOWN_FUNCTION(PlayerSub10_setInitialPhysicsValues){
#include "asm/80584044.s"
}

// Symbol: PlayerSub10_doRespawn
// PAL: 0x80584334..0x80584648
MARK_BINARY_BLOB(PlayerSub10_doRespawn, 0x80584334, 0x80584648);
asm UNKNOWN_FUNCTION(PlayerSub10_doRespawn){
#include "asm/80584334.s"
}

// Symbol: unk_80584648
// PAL: 0x80584648..0x8058473c
MARK_BINARY_BLOB(unk_80584648, 0x80584648, 0x8058473c);
asm UNKNOWN_FUNCTION(unk_80584648){
#include "asm/80584648.s"
}

// Symbol: unk_8058473c
// PAL: 0x8058473c..0x80584928
MARK_BINARY_BLOB(unk_8058473c, 0x8058473c, 0x80584928);
asm UNKNOWN_FUNCTION(unk_8058473c){
#include "asm/8058473c.s"
}

// Symbol: unk_80584928
// PAL: 0x80584928..0x8058492c
MARK_BINARY_BLOB(unk_80584928, 0x80584928, 0x8058492c);
asm UNKNOWN_FUNCTION(unk_80584928){
#include "asm/80584928.s"
}

// Symbol: unk_8058492c
// PAL: 0x8058492c..0x80584930
MARK_BINARY_BLOB(unk_8058492c, 0x8058492c, 0x80584930);
asm UNKNOWN_FUNCTION(unk_8058492c){
#include "asm/8058492c.s"
}

// Symbol: unk_80584930
// PAL: 0x80584930..0x8058498c
MARK_BINARY_BLOB(unk_80584930, 0x80584930, 0x8058498c);
asm UNKNOWN_FUNCTION(unk_80584930){
#include "asm/80584930.s"
}

// Symbol: PlayerSub10_enterCannon
// PAL: 0x8058498c..0x80584d58
MARK_BINARY_BLOB(PlayerSub10_enterCannon, 0x8058498c, 0x80584d58);
asm UNKNOWN_FUNCTION(PlayerSub10_enterCannon){
#include "asm/8058498c.s"
}

// Symbol: PlayerSub10_updateCannon
// PAL: 0x80584d58..0x805852c8
MARK_BINARY_BLOB(PlayerSub10_updateCannon, 0x80584d58, 0x805852c8);
asm UNKNOWN_FUNCTION(PlayerSub10_updateCannon){
#include "asm/80584d58.s"
}

// Symbol: unk_805852c8
// PAL: 0x805852c8..0x8058539c
MARK_BINARY_BLOB(unk_805852c8, 0x805852c8, 0x8058539c);
asm UNKNOWN_FUNCTION(unk_805852c8){
#include "asm/805852c8.s"
}

// Symbol: PlayerPointers_getCannonPosAndDir
// PAL: 0x8058539c..0x805855bc
MARK_BINARY_BLOB(PlayerPointers_getCannonPosAndDir, 0x8058539c, 0x805855bc);
asm UNKNOWN_FUNCTION(PlayerPointers_getCannonPosAndDir){
#include "asm/8058539c.s"
}

// Symbol: unk_805855bc
// PAL: 0x805855bc..0x805858ac
MARK_BINARY_BLOB(unk_805855bc, 0x805855bc, 0x805858ac);
asm UNKNOWN_FUNCTION(unk_805855bc){
#include "asm/805855bc.s"
}

// Symbol: PlayerSub10_activateBullet
// PAL: 0x805858ac..0x80585a04
MARK_BINARY_BLOB(PlayerSub10_activateBullet, 0x805858ac, 0x80585a04);
asm UNKNOWN_FUNCTION(PlayerSub10_activateBullet){
#include "asm/805858ac.s"
}

// Symbol: unk_80585a04
// PAL: 0x80585a04..0x80585a28
MARK_BINARY_BLOB(unk_80585a04, 0x80585a04, 0x80585a28);
asm UNKNOWN_FUNCTION(unk_80585a04){
#include "asm/80585a04.s"
}

// Symbol: unk_80585a28
// PAL: 0x80585a28..0x80585a60
MARK_BINARY_BLOB(unk_80585a28, 0x80585a28, 0x80585a60);
asm UNKNOWN_FUNCTION(unk_80585a28){
#include "asm/80585a28.s"
}

// Symbol: unk_80585a60
// PAL: 0x80585a60..0x80585aa0
MARK_BINARY_BLOB(unk_80585a60, 0x80585a60, 0x80585aa0);
asm UNKNOWN_FUNCTION(unk_80585a60){
#include "asm/80585a60.s"
}

// Symbol: unk_80585aa0
// PAL: 0x80585aa0..0x80585ae8
MARK_BINARY_BLOB(unk_80585aa0, 0x80585aa0, 0x80585ae8);
asm UNKNOWN_FUNCTION(unk_80585aa0){
#include "asm/80585aa0.s"
}

// Symbol: unk_80585ae8
// PAL: 0x80585ae8..0x80585af8
MARK_BINARY_BLOB(unk_80585ae8, 0x80585ae8, 0x80585af8);
asm UNKNOWN_FUNCTION(unk_80585ae8){
#include "asm/80585ae8.s"
}

// Symbol: unk_80585af8
// PAL: 0x80585af8..0x805860bc
MARK_BINARY_BLOB(unk_80585af8, 0x80585af8, 0x805860bc);
asm UNKNOWN_FUNCTION(unk_80585af8){
#include "asm/80585af8.s"
}

// Symbol: unk_805860bc
// PAL: 0x805860bc..0x8058677c
MARK_BINARY_BLOB(unk_805860bc, 0x805860bc, 0x8058677c);
asm UNKNOWN_FUNCTION(unk_805860bc){
#include "asm/805860bc.s"
}

// Symbol: unk_8058677c
// PAL: 0x8058677c..0x805869dc
MARK_BINARY_BLOB(unk_8058677c, 0x8058677c, 0x805869dc);
asm UNKNOWN_FUNCTION(unk_8058677c){
#include "asm/8058677c.s"
}

// Symbol: PlayerSub10_updateDiving
// PAL: 0x805869dc..0x80586d18
MARK_BINARY_BLOB(PlayerSub10_updateDiving, 0x805869dc, 0x80586d18);
asm UNKNOWN_FUNCTION(PlayerSub10_updateDiving){
#include "asm/805869dc.s"
}

// Symbol: unk_80586d18
// PAL: 0x80586d18..0x80586db4
MARK_BINARY_BLOB(unk_80586d18, 0x80586d18, 0x80586db4);
asm UNKNOWN_FUNCTION(unk_80586d18){
#include "asm/80586d18.s"
}

// Symbol: unk_80586db4
// PAL: 0x80586db4..0x80586e90
MARK_BINARY_BLOB(unk_80586db4, 0x80586db4, 0x80586e90);
asm UNKNOWN_FUNCTION(unk_80586db4){
#include "asm/80586db4.s"
}

// Symbol: unk_80586e90
// PAL: 0x80586e90..0x80586fa8
MARK_BINARY_BLOB(unk_80586e90, 0x80586e90, 0x80586fa8);
asm UNKNOWN_FUNCTION(unk_80586e90){
#include "asm/80586e90.s"
}

// Symbol: PlayerSub10_updateSlipstream
// PAL: 0x80586fa8..0x805874c0
MARK_BINARY_BLOB(PlayerSub10_updateSlipstream, 0x80586fa8, 0x805874c0);
asm UNKNOWN_FUNCTION(PlayerSub10_updateSlipstream){
#include "asm/80586fa8.s"
}

// Symbol: unk_805874c0
// PAL: 0x805874c0..0x8058758c
MARK_BINARY_BLOB(unk_805874c0, 0x805874c0, 0x8058758c);
asm UNKNOWN_FUNCTION(unk_805874c0){
#include "asm/805874c0.s"
}

// Symbol: PlayerSub10_updateWheelie
// PAL: 0x8058758c..0x80587590
MARK_BINARY_BLOB(PlayerSub10_updateWheelie, 0x8058758c, 0x80587590);
asm UNKNOWN_FUNCTION(PlayerSub10_updateWheelie){
#include "asm/8058758c.s"
}

// Symbol: PlayerSub10_updateSpecialFloor
// PAL: 0x80587590..0x80587938
MARK_BINARY_BLOB(PlayerSub10_updateSpecialFloor, 0x80587590, 0x80587938);
asm UNKNOWN_FUNCTION(PlayerSub10_updateSpecialFloor){
#include "asm/80587590.s"
}

// Symbol: unk_80587938
// PAL: 0x80587938..0x805879a4
MARK_BINARY_BLOB(unk_80587938, 0x80587938, 0x805879a4);
asm UNKNOWN_FUNCTION(unk_80587938){
#include "asm/80587938.s"
}

// Symbol: unk_805879a4
// PAL: 0x805879a4..0x80587b30
MARK_BINARY_BLOB(unk_805879a4, 0x805879a4, 0x80587b30);
asm UNKNOWN_FUNCTION(unk_805879a4){
#include "asm/805879a4.s"
}

// Symbol: PlayerSub10Bike_init
// PAL: 0x80587b30..0x80587b78
MARK_BINARY_BLOB(PlayerSub10Bike_init, 0x80587b30, 0x80587b78);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_init){
#include "asm/80587b30.s"
}

// Symbol: PlayerSub10_destroy
// PAL: 0x80587b78..0x80587bb8
MARK_BINARY_BLOB(PlayerSub10_destroy, 0x80587b78, 0x80587bb8);
asm UNKNOWN_FUNCTION(PlayerSub10_destroy){
#include "asm/80587b78.s"
}

// Symbol: PlayerSub10Bike_initTrickZipper
// PAL: 0x80587bb8..0x80587c54
MARK_BINARY_BLOB(PlayerSub10Bike_initTrickZipper, 0x80587bb8, 0x80587c54);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_initTrickZipper){
#include "asm/80587bb8.s"
}

// Symbol: PlayerSub10Bike_setTurnParams
// PAL: 0x80587c54..0x80587d00
MARK_BINARY_BLOB(PlayerSub10Bike_setTurnParams, 0x80587c54, 0x80587d00);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_setTurnParams){
#include "asm/80587c54.s"
}

// Symbol: PlayerSub10Bike_init2
// PAL: 0x80587d00..0x80587d64
MARK_BINARY_BLOB(PlayerSub10Bike_init2, 0x80587d00, 0x80587d64);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_init2){
#include "asm/80587d00.s"
}

// Symbol: PlayerSub10Bike_updateWheelie
// PAL: 0x80587d64..0x80587d68
MARK_BINARY_BLOB(PlayerSub10Bike_updateWheelie, 0x80587d64, 0x80587d68);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_updateWheelie){
#include "asm/80587d64.s"
}

// Symbol: PlayerSub10Bike_updateVehicleRotationVector
// PAL: 0x80587d68..0x80588324
MARK_BINARY_BLOB(PlayerSub10Bike_updateVehicleRotationVector, 0x80587d68,
                 0x80588324);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_updateVehicleRotationVector){
#include "asm/80587d68.s"
}

// Symbol: PlayerSub10Bike_getWheelieSoftSpeedLimitBonus
// PAL: 0x80588324..0x80588350
MARK_BINARY_BLOB(PlayerSub10Bike_getWheelieSoftSpeedLimitBonus, 0x80588324,
                 0x80588350);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_getWheelieSoftSpeedLimitBonus){
#include "asm/80588324.s"
}

// Symbol: PlayerSub10Bike_startWheelie
// PAL: 0x80588350..0x805883c4
MARK_BINARY_BLOB(PlayerSub10Bike_startWheelie, 0x80588350, 0x805883c4);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_startWheelie){
#include "asm/80588350.s"
}

// Symbol: PlayerSub10Bike_cancelWheelie
// PAL: 0x805883c4..0x805883f4
MARK_BINARY_BLOB(PlayerSub10Bike_cancelWheelie, 0x805883c4, 0x805883f4);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_cancelWheelie){
#include "asm/805883c4.s"
}

// Symbol: unk_805883f4
// PAL: 0x805883f4..0x80588798
MARK_BINARY_BLOB(unk_805883f4, 0x805883f4, 0x80588798);
asm UNKNOWN_FUNCTION(unk_805883f4){
#include "asm/805883f4.s"
}

// Symbol: PlayerSub10Bike_tryStartWheelie
// PAL: 0x80588798..0x80588860
MARK_BINARY_BLOB(PlayerSub10Bike_tryStartWheelie, 0x80588798, 0x80588860);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_tryStartWheelie){
#include "asm/80588798.s"
}

// Symbol: unk_80588860
// PAL: 0x80588860..0x80588888
MARK_BINARY_BLOB(unk_80588860, 0x80588860, 0x80588888);
asm UNKNOWN_FUNCTION(unk_80588860){
#include "asm/80588860.s"
}

// Symbol: PlayerSub10Bike_updateMtCharge
// PAL: 0x80588888..0x80588950
MARK_BINARY_BLOB(PlayerSub10Bike_updateMtCharge, 0x80588888, 0x80588950);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_updateMtCharge){
#include "asm/80588888.s"
}

// Symbol: unk_80588950
// PAL: 0x80588950..0x80588b30
MARK_BINARY_BLOB(unk_80588950, 0x80588950, 0x80588b30);
asm UNKNOWN_FUNCTION(unk_80588950){
#include "asm/80588950.s"
}

// Symbol: unk_80588b30
// PAL: 0x80588b30..0x80588b58
MARK_BINARY_BLOB(unk_80588b30, 0x80588b30, 0x80588b58);
asm UNKNOWN_FUNCTION(unk_80588b30){
#include "asm/80588b30.s"
}

// Symbol: unk_80588b58
// PAL: 0x80588b58..0x80588cac
MARK_BINARY_BLOB(unk_80588b58, 0x80588b58, 0x80588cac);
asm UNKNOWN_FUNCTION(unk_80588b58){
#include "asm/80588b58.s"
}

// Symbol: unk_80588cac
// PAL: 0x80588cac..0x80588d28
MARK_BINARY_BLOB(unk_80588cac, 0x80588cac, 0x80588d28);
asm UNKNOWN_FUNCTION(unk_80588cac){
#include "asm/80588cac.s"
}

// Symbol: PlayerBoost_construct
// PAL: 0x80588d28..0x80588d74
MARK_BINARY_BLOB(PlayerBoost_construct, 0x80588d28, 0x80588d74);
asm UNKNOWN_FUNCTION(PlayerBoost_construct){
#include "asm/80588d28.s"
}

// Symbol: PlayerBoost_reset
// PAL: 0x80588d74..0x80588db0
MARK_BINARY_BLOB(PlayerBoost_reset, 0x80588d74, 0x80588db0);
asm UNKNOWN_FUNCTION(PlayerBoost_reset){
#include "asm/80588d74.s"
}

// Symbol: PlayerBoost_activate
// PAL: 0x80588db0..0x80588e18
MARK_BINARY_BLOB(PlayerBoost_activate, 0x80588db0, 0x80588e18);
asm UNKNOWN_FUNCTION(PlayerBoost_activate){
#include "asm/80588db0.s"
}

// Symbol: unk_80588e18
// PAL: 0x80588e18..0x80588e24
MARK_BINARY_BLOB(unk_80588e18, 0x80588e18, 0x80588e24);
asm UNKNOWN_FUNCTION(unk_80588e18){
#include "asm/80588e18.s"
}

// Symbol: PlayerBoost_update
// PAL: 0x80588e24..0x80588fc0
MARK_BINARY_BLOB(PlayerBoost_update, 0x80588e24, 0x80588fc0);
asm UNKNOWN_FUNCTION(PlayerBoost_update){
#include "asm/80588e24.s"
}

// Symbol: unk_80588fc0
// PAL: 0x80588fc0..0x80588fd0
MARK_BINARY_BLOB(unk_80588fc0, 0x80588fc0, 0x80588fd0);
asm UNKNOWN_FUNCTION(unk_80588fc0){
#include "asm/80588fc0.s"
}

// Symbol: unk_80588fd0
// PAL: 0x80588fd0..0x80588fe0
MARK_BINARY_BLOB(unk_80588fd0, 0x80588fd0, 0x80588fe0);
asm UNKNOWN_FUNCTION(unk_80588fd0){
#include "asm/80588fd0.s"
}

// Symbol: PlayerSub10Bike_checkWheelieSpeed
// PAL: 0x80588fe0..0x80589024
MARK_BINARY_BLOB(PlayerSub10Bike_checkWheelieSpeed, 0x80588fe0, 0x80589024);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_checkWheelieSpeed){
#include "asm/80588fe0.s"
}

// Symbol: getStarDuration
// PAL: 0x80589024..0x80589030
MARK_BINARY_BLOB(getStarDuration, 0x80589024, 0x80589030);
asm UNKNOWN_FUNCTION(getStarDuration){
#include "asm/80589024.s"
}

// Symbol: unk_80589030
// PAL: 0x80589030..0x8058905c
MARK_BINARY_BLOB(unk_80589030, 0x80589030, 0x8058905c);
asm UNKNOWN_FUNCTION(unk_80589030){
#include "asm/80589030.s"
}

// Symbol: unk_8058905c
// PAL: 0x8058905c..0x805890b0
MARK_BINARY_BLOB(unk_8058905c, 0x8058905c, 0x805890b0);
asm UNKNOWN_FUNCTION(unk_8058905c){
#include "asm/8058905c.s"
}

// Symbol: unk_805890b0
// PAL: 0x805890b0..0x80589118
MARK_BINARY_BLOB(unk_805890b0, 0x805890b0, 0x80589118);
asm UNKNOWN_FUNCTION(unk_805890b0){
#include "asm/805890b0.s"
}

// Symbol: unk_80589118
// PAL: 0x80589118..0x805891c0
MARK_BINARY_BLOB(unk_80589118, 0x80589118, 0x805891c0);
asm UNKNOWN_FUNCTION(unk_80589118){
#include "asm/80589118.s"
}

// Symbol: unk_805891c0
// PAL: 0x805891c0..0x8058920c
MARK_BINARY_BLOB(unk_805891c0, 0x805891c0, 0x8058920c);
asm UNKNOWN_FUNCTION(unk_805891c0){
#include "asm/805891c0.s"
}

// Symbol: unk_8058920c
// PAL: 0x8058920c..0x80589230
MARK_BINARY_BLOB(unk_8058920c, 0x8058920c, 0x80589230);
asm UNKNOWN_FUNCTION(unk_8058920c){
#include "asm/8058920c.s"
}

// Symbol: unk_80589230
// PAL: 0x80589230..0x80589254
MARK_BINARY_BLOB(unk_80589230, 0x80589230, 0x80589254);
asm UNKNOWN_FUNCTION(unk_80589230){
#include "asm/80589230.s"
}

// Symbol: unk_80589254
// PAL: 0x80589254..0x8058926c
MARK_BINARY_BLOB(unk_80589254, 0x80589254, 0x8058926c);
asm UNKNOWN_FUNCTION(unk_80589254){
#include "asm/80589254.s"
}

// Symbol: unk_8058926c
// PAL: 0x8058926c..0x80589308
MARK_BINARY_BLOB(unk_8058926c, 0x8058926c, 0x80589308);
asm UNKNOWN_FUNCTION(unk_8058926c){
#include "asm/8058926c.s"
}

// Symbol: unk_80589308
// PAL: 0x80589308..0x805893fc
MARK_BINARY_BLOB(unk_80589308, 0x80589308, 0x805893fc);
asm UNKNOWN_FUNCTION(unk_80589308){
#include "asm/80589308.s"
}

// Symbol: unk_805893fc
// PAL: 0x805893fc..0x80589400
MARK_BINARY_BLOB(unk_805893fc, 0x805893fc, 0x80589400);
asm UNKNOWN_FUNCTION(unk_805893fc){
#include "asm/805893fc.s"
}

// Symbol: PlayerSub10RealLocal_hop
// PAL: 0x80589400..0x80589440
MARK_BINARY_BLOB(PlayerSub10RealLocal_hop, 0x80589400, 0x80589440);
asm UNKNOWN_FUNCTION(PlayerSub10RealLocal_hop){
#include "asm/80589400.s"
}

// Symbol: PlayerSub10Bike_hop
// PAL: 0x80589440..0x80589480
MARK_BINARY_BLOB(PlayerSub10Bike_hop, 0x80589440, 0x80589480);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_hop){
#include "asm/80589440.s"
}

// Symbol: unk_80589480
// PAL: 0x80589480..0x80589514
MARK_BINARY_BLOB(unk_80589480, 0x80589480, 0x80589514);
asm UNKNOWN_FUNCTION(unk_80589480){
#include "asm/80589480.s"
}

// Symbol: unk_80589514
// PAL: 0x80589514..0x8058956c
MARK_BINARY_BLOB(unk_80589514, 0x80589514, 0x8058956c);
asm UNKNOWN_FUNCTION(unk_80589514){
#include "asm/80589514.s"
}

// Symbol: unk_8058956c
// PAL: 0x8058956c..0x805895cc
MARK_BINARY_BLOB(unk_8058956c, 0x8058956c, 0x805895cc);
asm UNKNOWN_FUNCTION(unk_8058956c){
#include "asm/8058956c.s"
}

// Symbol: unk_805895cc
// PAL: 0x805895cc..0x8058962c
MARK_BINARY_BLOB(unk_805895cc, 0x805895cc, 0x8058962c);
asm UNKNOWN_FUNCTION(unk_805895cc){
#include "asm/805895cc.s"
}

// Symbol: unk_8058962c
// PAL: 0x8058962c..0x805896b8
MARK_BINARY_BLOB(unk_8058962c, 0x8058962c, 0x805896b8);
asm UNKNOWN_FUNCTION(unk_8058962c){
#include "asm/8058962c.s"
}

// Symbol: unk_805896b8
// PAL: 0x805896b8..0x805896bc
MARK_BINARY_BLOB(unk_805896b8, 0x805896b8, 0x805896bc);
asm UNKNOWN_FUNCTION(unk_805896b8){
#include "asm/805896b8.s"
}

// Symbol: PlayerSub10Bike_getLeanRot
// PAL: 0x805896bc..0x805896c4
MARK_BINARY_BLOB(PlayerSub10Bike_getLeanRot, 0x805896bc, 0x805896c4);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_getLeanRot){
#include "asm/805896bc.s"
}

// Symbol: unk_805896c4
// PAL: 0x805896c4..0x80589704
MARK_BINARY_BLOB(unk_805896c4, 0x805896c4, 0x80589704);
asm UNKNOWN_FUNCTION(unk_805896c4){
#include "asm/805896c4.s"
}

// Symbol: PlayerSub10Bike_destroy
// PAL: 0x80589704..0x80589744
MARK_BINARY_BLOB(PlayerSub10Bike_destroy, 0x80589704, 0x80589744);
asm UNKNOWN_FUNCTION(PlayerSub10Bike_destroy){
#include "asm/80589704.s"
}

// Symbol: PlayerSub10_checkWheelie
// PAL: 0x80589744..0x8058974c
MARK_BINARY_BLOB(PlayerSub10_checkWheelie, 0x80589744, 0x8058974c);
asm UNKNOWN_FUNCTION(PlayerSub10_checkWheelie){
#include "asm/80589744.s"
}

// Symbol: PlayerSub10_getLeanRot
// PAL: 0x8058974c..0x80589758
MARK_BINARY_BLOB(PlayerSub10_getLeanRot, 0x8058974c, 0x80589758);
asm UNKNOWN_FUNCTION(PlayerSub10_getLeanRot){
#include "asm/8058974c.s"
}

// Symbol: unk_80589758
// PAL: 0x80589758..0x80589798
MARK_BINARY_BLOB(unk_80589758, 0x80589758, 0x80589798);
asm UNKNOWN_FUNCTION(unk_80589758){
#include "asm/80589758.s"
}

// Symbol: unk_80589798
// PAL: 0x80589798..0x805897d8
MARK_BINARY_BLOB(unk_80589798, 0x80589798, 0x805897d8);
asm UNKNOWN_FUNCTION(unk_80589798){
#include "asm/80589798.s"
}

// Symbol: unk_805897d8
// PAL: 0x805897d8..0x80589818
MARK_BINARY_BLOB(unk_805897d8, 0x805897d8, 0x80589818);
asm UNKNOWN_FUNCTION(unk_805897d8){
#include "asm/805897d8.s"
}

// Symbol: unk_80589818
// PAL: 0x80589818..0x80589830
MARK_BINARY_BLOB(unk_80589818, 0x80589818, 0x80589830);
asm UNKNOWN_FUNCTION(unk_80589818){
#include "asm/80589818.s"
}

// Symbol: unk_80589830
// PAL: 0x80589830..0x80589844
MARK_BINARY_BLOB(unk_80589830, 0x80589830, 0x80589844);
asm UNKNOWN_FUNCTION(unk_80589830){
#include "asm/80589830.s"
}

// Symbol: unk_80589844
// PAL: 0x80589844..0x8058985c
MARK_BINARY_BLOB(unk_80589844, 0x80589844, 0x8058985c);
asm UNKNOWN_FUNCTION(unk_80589844) {
#include "asm/80589844.s"
}
