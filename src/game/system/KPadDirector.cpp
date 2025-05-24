#include "KPadDirector.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80006038
extern UNKNOWN_FUNCTION(memset);
// PAL: 0x80020ff4
extern UNKNOWN_FUNCTION(__construct_array);
// PAL: 0x800210ec
extern UNKNOWN_FUNCTION(__destroy_arr);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8051e85c
extern UNKNOWN_FUNCTION(reset__Q26System18KPadRaceInputStateFv);
// PAL: 0x8051eba8
extern UNKNOWN_FUNCTION(__ct__Q26System14KPadControllerFv);
// PAL: 0x8051ed14
extern UNKNOWN_FUNCTION(calc__Q26System14KPadControllerFv);
// PAL: 0x8051f088
extern UNKNOWN_FUNCTION(__ct__Q26System17KPadWiiControllerFv);
// PAL: 0x8051ffd0
extern UNKNOWN_FUNCTION(__ct__Q26System16KPadGCControllerFv);
// PAL: 0x80520730
extern UNKNOWN_FUNCTION(__ct__Q26System19KPadGhostControllerFv);
// PAL: 0x80520924
extern UNKNOWN_FUNCTION(__dt__Q26System19KPadGhostControllerFv);
// PAL: 0x80520f64
extern UNKNOWN_FUNCTION(__ct__Q26System4KPadFv);
// PAL: 0x80521554
extern UNKNOWN_FUNCTION(setController__Q26System4KPadFPQ26System14KPadControllerPQ26System14KPadController);
// PAL: 0x805215d4
extern UNKNOWN_FUNCTION(startGhostProxy__Q26System10KPadPlayerFv);
// PAL: 0x80521688
extern UNKNOWN_FUNCTION(endGhostProxy__Q26System10KPadPlayerFv);
// PAL: 0x80521844
extern UNKNOWN_FUNCTION(setGhostController__Q26System10KPadPlayerFPQ26System14KPadControllerPQ26System14KPadControllerb);
// PAL: 0x80521930
extern UNKNOWN_FUNCTION(unk_80521930);
// PAL: 0x80521a34
extern UNKNOWN_FUNCTION(unk_80521a34);
// PAL: 0x80521d8c
extern UNKNOWN_FUNCTION(unk_80521d8c);
// PAL: 0x80521ed0
extern UNKNOWN_FUNCTION(unk_80521ed0);
// PAL: 0x805220bc
extern UNKNOWN_FUNCTION(__ct__Q26System10KPadPlayerFv);
// PAL: 0x805222f4
extern UNKNOWN_FUNCTION(__dt__Q26System10KPadPlayerFv);
// PAL: 0x80522358
extern UNKNOWN_FUNCTION(unk_80522358);
// PAL: 0x80522364
extern UNKNOWN_FUNCTION(init__Q26System18KPadControllerInfoFPQ26System14KPadController);
// PAL: 0x80522690
extern UNKNOWN_FUNCTION(unk_80522690);
// PAL: 0x8052279c
extern UNKNOWN_FUNCTION(__dt__Q26System6KPadAIFv);
// PAL: 0x80522874
extern UNKNOWN_FUNCTION(__dt__Q26System16KPadGCControllerFv);
// PAL: 0x80522934
extern UNKNOWN_FUNCTION(__dt__Q26System17KPadWiiControllerFv);
// PAL: 0x805230e0
extern UNKNOWN_FUNCTION(syncDeviceCallback__Q26System12KPadDirectorFi);
// PAL: 0x805232f0
extern UNKNOWN_FUNCTION(__ct__Q26System12KPadDirectorFv);
// PAL: 0x805234a0
extern UNKNOWN_FUNCTION(__ct__Q26System6KPadAIFv);
// PAL: 0x805237e8
extern UNKNOWN_FUNCTION(calcControllers__Q26System12KPadDirectorFb);
// PAL: 0x805250c8
extern UNKNOWN_FUNCTION(RumbleSettings_load);
// PAL: 0x80525204
extern UNKNOWN_FUNCTION(RumbleSettings_dt);
// PAL: 0x805411fc
extern UNKNOWN_FUNCTION(getFile__Q26System15ResourceManagerFlPCcPUl);// Extern data references.
// PAL: 0x8088fd10
extern UNKNOWN_DATA(lbl_8088fd10);
// PAL: 0x8088fd20
extern UNKNOWN_DATA(lbl_8088fd20);
// PAL: 0x8088fd2c
extern UNKNOWN_DATA(lbl_8088fd2c);
// PAL: 0x808b2db4
extern UNKNOWN_DATA(lbl_808b2db4);
// PAL: 0x808b2f2c
extern UNKNOWN_DATA(lbl_808b2f2c);
// PAL: 0x808b2fc8
extern UNKNOWN_DATA(lbl_808b2fc8);
// PAL: 0x808b2fd8
extern UNKNOWN_DATA(lbl_808b2fd8);
// PAL: 0x808b3020
extern UNKNOWN_DATA(lbl_808b3020);
// PAL: 0x808b30fc
extern UNKNOWN_DATA(lbl_808b30fc);
// PAL: 0x809bd708
extern UNKNOWN_DATA(lbl_809bd708);
// PAL: 0x809bd70c
extern UNKNOWN_DATA(spInstance__Q26System12KPadDirector);
// PAL: 0x809bd738
extern UNKNOWN_DATA(spInstance__Q26System15ResourceManager);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data


// .bss


// Symbol: syncDeviceCallback__Q26System12KPadDirectorFi
// PAL: 0x805230e0..0x8052313c
MARK_BINARY_BLOB(syncDeviceCallback__Q26System12KPadDirectorFi, 0x805230e0, 0x8052313c);
asm UNKNOWN_FUNCTION(syncDeviceCallback__Q26System12KPadDirectorFi) {
  #include "asm/805230e0.s"
}

// Symbol: createInstance__Q26System12KPadDirectorFv
// PAL: 0x8052313c..0x8052318c
MARK_BINARY_BLOB(createInstance__Q26System12KPadDirectorFv, 0x8052313c, 0x8052318c);
asm UNKNOWN_FUNCTION(createInstance__Q26System12KPadDirectorFv) {
  #include "asm/8052313c.s"
}

// Symbol: destroyInstance__Q26System12KPadDirectorFv
// PAL: 0x8052318c..0x805231dc
MARK_BINARY_BLOB(destroyInstance__Q26System12KPadDirectorFv, 0x8052318c, 0x805231dc);
asm UNKNOWN_FUNCTION(destroyInstance__Q26System12KPadDirectorFv) {
  #include "asm/8052318c.s"
}

// Symbol: __dt__Q26System12KPadDirectorFv
// PAL: 0x805231dc..0x805232b0
MARK_BINARY_BLOB(__dt__Q26System12KPadDirectorFv, 0x805231dc, 0x805232b0);
asm UNKNOWN_FUNCTION(__dt__Q26System12KPadDirectorFv) {
  #include "asm/805231dc.s"
}

// Symbol: __dt__Q26System19KPadDummyControllerFv
// PAL: 0x805232b0..0x805232f0
MARK_BINARY_BLOB(__dt__Q26System19KPadDummyControllerFv, 0x805232b0, 0x805232f0);
asm UNKNOWN_FUNCTION(__dt__Q26System19KPadDummyControllerFv) {
  #include "asm/805232b0.s"
}

// Symbol: __ct__Q26System12KPadDirectorFv
// PAL: 0x805232f0..0x805234a0
MARK_BINARY_BLOB(__ct__Q26System12KPadDirectorFv, 0x805232f0, 0x805234a0);
asm UNKNOWN_FUNCTION(__ct__Q26System12KPadDirectorFv) {
  #include "asm/805232f0.s"
}

// Symbol: __ct__Q26System6KPadAIFv
// PAL: 0x805234a0..0x80523520
MARK_BINARY_BLOB(__ct__Q26System6KPadAIFv, 0x805234a0, 0x80523520);
asm UNKNOWN_FUNCTION(__ct__Q26System6KPadAIFv) {
  #include "asm/805234a0.s"
}

// Symbol: initialize__Q26System12KPadDirectorFv
// PAL: 0x80523520..0x80523524
MARK_BINARY_BLOB(initialize__Q26System12KPadDirectorFv, 0x80523520, 0x80523524);
asm UNKNOWN_FUNCTION(initialize__Q26System12KPadDirectorFv) {
  #include "asm/80523520.s"
}

// Symbol: reset2__Q26System12KPadDirectorFv
// PAL: 0x80523524..0x805235ac
MARK_BINARY_BLOB(reset2__Q26System12KPadDirectorFv, 0x80523524, 0x805235ac);
asm UNKNOWN_FUNCTION(reset2__Q26System12KPadDirectorFv) {
  #include "asm/80523524.s"
}

// Symbol: resetPlayersActivityStatus__Q26System12KPadDirectorFv
// PAL: 0x805235ac..0x805235d4
MARK_BINARY_BLOB(resetPlayersActivityStatus__Q26System12KPadDirectorFv, 0x805235ac, 0x805235d4);
asm UNKNOWN_FUNCTION(resetPlayersActivityStatus__Q26System12KPadDirectorFv) {
  #include "asm/805235ac.s"
}

// Symbol: checkPlayerActivityStatus__Q26System12KPadDirectorFUcUsUs
// PAL: 0x805235d4..0x80523690
MARK_BINARY_BLOB(checkPlayerActivityStatus__Q26System12KPadDirectorFUcUsUs, 0x805235d4, 0x80523690);
asm UNKNOWN_FUNCTION(checkPlayerActivityStatus__Q26System12KPadDirectorFUcUsUs) {
  #include "asm/805235d4.s"
}

// Symbol: reset__Q26System12KPadDirectorFv
// PAL: 0x80523690..0x80523724
MARK_BINARY_BLOB(reset__Q26System12KPadDirectorFv, 0x80523690, 0x80523724);
asm UNKNOWN_FUNCTION(reset__Q26System12KPadDirectorFv) {
  #include "asm/80523690.s"
}

// Symbol: stopAllMotors__Q26System12KPadDirectorFv
// PAL: 0x80523724..0x805237ac
MARK_BINARY_BLOB(stopAllMotors__Q26System12KPadDirectorFv, 0x80523724, 0x805237ac);
asm UNKNOWN_FUNCTION(stopAllMotors__Q26System12KPadDirectorFv) {
  #include "asm/80523724.s"
}

// Symbol: readPads__Q26System12KPadDirectorFv
// PAL: 0x805237ac..0x805237e8
MARK_BINARY_BLOB(readPads__Q26System12KPadDirectorFv, 0x805237ac, 0x805237e8);
asm UNKNOWN_FUNCTION(readPads__Q26System12KPadDirectorFv) {
  #include "asm/805237ac.s"
}

// Symbol: calcControllers__Q26System12KPadDirectorFb
// PAL: 0x805237e8..0x805238f0
MARK_BINARY_BLOB(calcControllers__Q26System12KPadDirectorFb, 0x805237e8, 0x805238f0);
asm UNKNOWN_FUNCTION(calcControllers__Q26System12KPadDirectorFb) {
  #include "asm/805237e8.s"
}

// Symbol: calc__Q26System12KPadDirectorFv
// PAL: 0x805238f0..0x80523990
MARK_BINARY_BLOB(calc__Q26System12KPadDirectorFv, 0x805238f0, 0x80523990);
asm UNKNOWN_FUNCTION(calc__Q26System12KPadDirectorFv) {
  #include "asm/805238f0.s"
}

// Symbol: setController__Q26System12KPadDirectorFPQ26System4KPadQ26System18eControllerTypeUcb
// PAL: 0x80523990..0x80523a58
MARK_BINARY_BLOB(setController__Q26System12KPadDirectorFPQ26System4KPadQ26System18eControllerTypeUcb, 0x80523990, 0x80523a58);
asm UNKNOWN_FUNCTION(setController__Q26System12KPadDirectorFPQ26System4KPadQ26System18eControllerTypeUcb) {
  #include "asm/80523990.s"
}

// Symbol: getControllerType__Q26System12KPadDirectorFQ26System14eControlSource
// PAL: 0x80523a58..0x80523a80
MARK_BINARY_BLOB(getControllerType__Q26System12KPadDirectorFQ26System14eControlSource, 0x80523a58, 0x80523a80);
asm UNKNOWN_FUNCTION(getControllerType__Q26System12KPadDirectorFQ26System14eControlSource) {
  #include "asm/80523a58.s"
}

// Symbol: copyController__Q26System12KPadDirectorFPQ26System4KPadPQ26System4KPadb
// PAL: 0x80523a80..0x80523bc8
MARK_BINARY_BLOB(copyController__Q26System12KPadDirectorFPQ26System4KPadPQ26System4KPadb, 0x80523a80, 0x80523bc8);
asm UNKNOWN_FUNCTION(copyController__Q26System12KPadDirectorFPQ26System4KPadPQ26System4KPadb) {
  #include "asm/80523a80.s"
}

// Symbol: initMasterController__Q26System12KPadDirectorFv
// PAL: 0x80523bc8..0x80523d10
MARK_BINARY_BLOB(initMasterController__Q26System12KPadDirectorFv, 0x80523bc8, 0x80523d10);
asm UNKNOWN_FUNCTION(initMasterController__Q26System12KPadDirectorFv) {
  #include "asm/80523bc8.s"
}

// Symbol: setPlayerToMasterController__Q26System12KPadDirectorFUc
// PAL: 0x80523d10..0x80523eac
MARK_BINARY_BLOB(setPlayerToMasterController__Q26System12KPadDirectorFUc, 0x80523d10, 0x80523eac);
asm UNKNOWN_FUNCTION(setPlayerToMasterController__Q26System12KPadDirectorFUc) {
  #include "asm/80523d10.s"
}

// Symbol: resetMasterController__Q26System12KPadDirectorFv
// PAL: 0x80523eac..0x80523ebc
MARK_BINARY_BLOB(resetMasterController__Q26System12KPadDirectorFv, 0x80523eac, 0x80523ebc);
asm UNKNOWN_FUNCTION(resetMasterController__Q26System12KPadDirectorFv) {
  #include "asm/80523eac.s"
}

// Symbol: initPlayerController__Q26System12KPadDirectorFUcb
// PAL: 0x80523ebc..0x805240ec
MARK_BINARY_BLOB(initPlayerController__Q26System12KPadDirectorFUcb, 0x80523ebc, 0x805240ec);
asm UNKNOWN_FUNCTION(initPlayerController__Q26System12KPadDirectorFUcb) {
  #include "asm/80523ebc.s"
}

// Symbol: setMasterToPlayerController__Q26System12KPadDirectorFUc
// PAL: 0x805240ec..0x80524264
MARK_BINARY_BLOB(setMasterToPlayerController__Q26System12KPadDirectorFUc, 0x805240ec, 0x80524264);
asm UNKNOWN_FUNCTION(setMasterToPlayerController__Q26System12KPadDirectorFUc) {
  #include "asm/805240ec.s"
}

// Symbol: resetPlayerController__Q26System12KPadDirectorFUc
// PAL: 0x80524264..0x8052427c
MARK_BINARY_BLOB(resetPlayerController__Q26System12KPadDirectorFUc, 0x80524264, 0x8052427c);
asm UNKNOWN_FUNCTION(resetPlayerController__Q26System12KPadDirectorFUc) {
  #include "asm/80524264.s"
}

// Symbol: resetPlayerControllers__Q26System12KPadDirectorFv
// PAL: 0x8052427c..0x805242d8
MARK_BINARY_BLOB(resetPlayerControllers__Q26System12KPadDirectorFv, 0x8052427c, 0x805242d8);
asm UNKNOWN_FUNCTION(resetPlayerControllers__Q26System12KPadDirectorFv) {
  #include "asm/8052427c.s"
}

// Symbol: initPlayerControllers__Q26System12KPadDirectorFv
// PAL: 0x805242d8..0x80524438
MARK_BINARY_BLOB(initPlayerControllers__Q26System12KPadDirectorFv, 0x805242d8, 0x80524438);
asm UNKNOWN_FUNCTION(initPlayerControllers__Q26System12KPadDirectorFv) {
  #include "asm/805242d8.s"
}

// Symbol: setPlayerController__Q26System12KPadDirectorFUcQ26System14eControlSourceUc
// PAL: 0x80524438..0x80524500
MARK_BINARY_BLOB(setPlayerController__Q26System12KPadDirectorFUcQ26System14eControlSourceUc, 0x80524438, 0x80524500);
asm UNKNOWN_FUNCTION(setPlayerController__Q26System12KPadDirectorFUcQ26System14eControlSourceUc) {
  #include "asm/80524438.s"
}

// Symbol: setGhostController__Q26System12KPadDirectorFUc
// PAL: 0x80524500..0x8052453c
MARK_BINARY_BLOB(setGhostController__Q26System12KPadDirectorFUc, 0x80524500, 0x8052453c);
asm UNKNOWN_FUNCTION(setGhostController__Q26System12KPadDirectorFUc) {
  #include "asm/80524500.s"
}

// Symbol: setGhostController__Q26System12KPadDirectorFUcPUsb
// PAL: 0x8052453c..0x80524558
MARK_BINARY_BLOB(setGhostController__Q26System12KPadDirectorFUcPUsb, 0x8052453c, 0x80524558);
asm UNKNOWN_FUNCTION(setGhostController__Q26System12KPadDirectorFUcPUsb) {
  #include "asm/8052453c.s"
}

// Symbol: unk_80524558
// PAL: 0x80524558..0x80524568
MARK_BINARY_BLOB(unk_80524558, 0x80524558, 0x80524568);
asm UNKNOWN_FUNCTION(unk_80524558) {
  #include "asm/80524558.s"
}

// Symbol: lockGhostProxies__Q26System12KPadDirectorFv
// PAL: 0x80524568..0x80524580
MARK_BINARY_BLOB(lockGhostProxies__Q26System12KPadDirectorFv, 0x80524568, 0x80524580);
asm UNKNOWN_FUNCTION(lockGhostProxies__Q26System12KPadDirectorFv) {
  #include "asm/80524568.s"
}

// Symbol: startGhostProxies__Q26System12KPadDirectorFv
// PAL: 0x80524580..0x805245cc
MARK_BINARY_BLOB(startGhostProxies__Q26System12KPadDirectorFv, 0x80524580, 0x805245cc);
asm UNKNOWN_FUNCTION(startGhostProxies__Q26System12KPadDirectorFv) {
  #include "asm/80524580.s"
}

// Symbol: endGhostProxy__Q26System12KPadDirectorFUc
// PAL: 0x805245cc..0x805245dc
MARK_BINARY_BLOB(endGhostProxy__Q26System12KPadDirectorFUc, 0x805245cc, 0x805245dc);
asm UNKNOWN_FUNCTION(endGhostProxy__Q26System12KPadDirectorFUc) {
  #include "asm/805245cc.s"
}

// Symbol: endGhostProxies__Q26System12KPadDirectorFv
// PAL: 0x805245dc..0x80524628
MARK_BINARY_BLOB(endGhostProxies__Q26System12KPadDirectorFv, 0x805245dc, 0x80524628);
asm UNKNOWN_FUNCTION(endGhostProxies__Q26System12KPadDirectorFv) {
  #include "asm/805245dc.s"
}

// Symbol: getPadStatus__Q26System12KPadDirectorFUcP9PADStatus
// PAL: 0x80524628..0x805246c0
MARK_BINARY_BLOB(getPadStatus__Q26System12KPadDirectorFUcP9PADStatus, 0x80524628, 0x805246c0);
asm UNKNOWN_FUNCTION(getPadStatus__Q26System12KPadDirectorFUcP9PADStatus) {
  #include "asm/80524628.s"
}

// Symbol: loadRumbleSettings__Q26System12KPadDirectorFv
// PAL: 0x805246c0..0x80524718
MARK_BINARY_BLOB(loadRumbleSettings__Q26System12KPadDirectorFv, 0x805246c0, 0x80524718);
asm UNKNOWN_FUNCTION(loadRumbleSettings__Q26System12KPadDirectorFv) {
  #include "asm/805246c0.s"
}

// Symbol: unloadRumbleSettings__Q26System12KPadDirectorFv
// PAL: 0x80524718..0x80524734
MARK_BINARY_BLOB(unloadRumbleSettings__Q26System12KPadDirectorFv, 0x80524718, 0x80524734);
asm UNKNOWN_FUNCTION(unloadRumbleSettings__Q26System12KPadDirectorFv) {
  #include "asm/80524718.s"
}

// Symbol: syncDeviceCallbackImpl__Q26System12KPadDirectorFi
// PAL: 0x80524734..0x80524788
MARK_BINARY_BLOB(syncDeviceCallbackImpl__Q26System12KPadDirectorFi, 0x80524734, 0x80524788);
asm UNKNOWN_FUNCTION(syncDeviceCallbackImpl__Q26System12KPadDirectorFi) {
  #include "asm/80524734.s"
}

// Symbol: startSync__Q26System12KPadDirectorFv
// PAL: 0x80524788..0x805247e4
MARK_BINARY_BLOB(startSync__Q26System12KPadDirectorFv, 0x80524788, 0x805247e4);
asm UNKNOWN_FUNCTION(startSync__Q26System12KPadDirectorFv) {
  #include "asm/80524788.s"
}

// Symbol: stopSync__Q26System12KPadDirectorFv
// PAL: 0x805247e4..0x80524840
MARK_BINARY_BLOB(stopSync__Q26System12KPadDirectorFv, 0x805247e4, 0x80524840);
asm UNKNOWN_FUNCTION(stopSync__Q26System12KPadDirectorFv) {
  #include "asm/805247e4.s"
}

// Symbol: enableDpds__Q26System12KPadDirectorFPb
// PAL: 0x80524840..0x805248d8
MARK_BINARY_BLOB(enableDpds__Q26System12KPadDirectorFPb, 0x80524840, 0x805248d8);
asm UNKNOWN_FUNCTION(enableDpds__Q26System12KPadDirectorFPb) {
  #include "asm/80524840.s"
}

// Symbol: restoreDpds__Q26System12KPadDirectorFPb
// PAL: 0x805248d8..0x80524944
MARK_BINARY_BLOB(restoreDpds__Q26System12KPadDirectorFPb, 0x805248d8, 0x80524944);
asm UNKNOWN_FUNCTION(restoreDpds__Q26System12KPadDirectorFPb) {
  #include "asm/805248d8.s"
}

// Symbol: unk_80524944
// PAL: 0x80524944..0x80524998
MARK_BINARY_BLOB(unk_80524944, 0x80524944, 0x80524998);
asm UNKNOWN_FUNCTION(unk_80524944) {
  #include "asm/80524944.s"
}

// Symbol: unk_80524998
// PAL: 0x80524998..0x805249b0
MARK_BINARY_BLOB(unk_80524998, 0x80524998, 0x805249b0);
asm UNKNOWN_FUNCTION(unk_80524998) {
  #include "asm/80524998.s"
}

// Symbol: unk_805249b0
// PAL: 0x805249b0..0x805249c8
MARK_BINARY_BLOB(unk_805249b0, 0x805249b0, 0x805249c8);
asm UNKNOWN_FUNCTION(unk_805249b0) {
  #include "asm/805249b0.s"
}

// Symbol: stopAllMotors2__Q26System12KPadDirectorFv
// PAL: 0x805249c8..0x80524a50
MARK_BINARY_BLOB(stopAllMotors2__Q26System12KPadDirectorFv, 0x805249c8, 0x80524a50);
asm UNKNOWN_FUNCTION(stopAllMotors2__Q26System12KPadDirectorFv) {
  #include "asm/805249c8.s"
}

// Symbol: unk_80524a50
// PAL: 0x80524a50..0x80524a58
MARK_BINARY_BLOB(unk_80524a50, 0x80524a50, 0x80524a58);
asm UNKNOWN_FUNCTION(unk_80524a50) {
  #include "asm/80524a50.s"
}

// Symbol: calcInner__Q26System16KPadAIControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x80524a58..0x80524aa8
MARK_BINARY_BLOB(calcInner__Q26System16KPadAIControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x80524a58, 0x80524aa8);
asm UNKNOWN_FUNCTION(calcInner__Q26System16KPadAIControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/80524a58.s"
}

// Symbol: getControlSource__Q26System16KPadAIControllerFv
// PAL: 0x80524aa8..0x80524ab0
MARK_BINARY_BLOB(getControlSource__Q26System16KPadAIControllerFv, 0x80524aa8, 0x80524ab0);
asm UNKNOWN_FUNCTION(getControlSource__Q26System16KPadAIControllerFv) {
  #include "asm/80524aa8.s"
}

// Symbol: calcInner__Q26System19KPadDummyControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x80524ab0..0x80524ab4
MARK_BINARY_BLOB(calcInner__Q26System19KPadDummyControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x80524ab0, 0x80524ab4);
asm UNKNOWN_FUNCTION(calcInner__Q26System19KPadDummyControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/80524ab0.s"
}

// Symbol: __sinit__KPadDirector_cpp
// PAL: 0x80524ab4..0x80524ac4
MARK_BINARY_BLOB(__sinit__KPadDirector_cpp, 0x80524ab4, 0x80524ac4);
asm UNKNOWN_FUNCTION(__sinit__KPadDirector_cpp) {
  #include "asm/80524ab4.s"
}

