#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <rvl/pad/pad.h>

#include <system/KPadController.hpp>


extern "C" {
// PAL: 0x805230e0..0x8052313c
UNKNOWN_FUNCTION(syncDeviceCallback__Q26System12KPadDirectorFi);
// PAL: 0x8052313c..0x8052318c
UNKNOWN_FUNCTION(createInstance__Q26System12KPadDirectorFv);
// PAL: 0x8052318c..0x805231dc
UNKNOWN_FUNCTION(destroyInstance__Q26System12KPadDirectorFv);
// PAL: 0x805231dc..0x805232b0
UNKNOWN_FUNCTION(__dt__Q26System12KPadDirectorFv);
// PAL: 0x805232b0..0x805232f0
UNKNOWN_FUNCTION(__dt__Q26System19KPadDummyControllerFv);
// PAL: 0x805232f0..0x805234a0
UNKNOWN_FUNCTION(__ct__Q26System12KPadDirectorFv);
// PAL: 0x805234a0..0x80523520
UNKNOWN_FUNCTION(__ct__Q26System6KPadAIFv);
// PAL: 0x80523520..0x80523524
UNKNOWN_FUNCTION(initialize__Q26System12KPadDirectorFv);
// PAL: 0x80523524..0x805235ac
UNKNOWN_FUNCTION(reset2__Q26System12KPadDirectorFv);
// PAL: 0x805235ac..0x805235d4
UNKNOWN_FUNCTION(resetPlayersActivityStatus__Q26System12KPadDirectorFv);
// PAL: 0x805235d4..0x80523690
UNKNOWN_FUNCTION(checkPlayerActivityStatus__Q26System12KPadDirectorFUcUsUs);
// PAL: 0x80523690..0x80523724
UNKNOWN_FUNCTION(reset__Q26System12KPadDirectorFv);
// PAL: 0x80523724..0x805237ac
UNKNOWN_FUNCTION(stopAllMotors__Q26System12KPadDirectorFv);
// PAL: 0x805237ac..0x805237e8
UNKNOWN_FUNCTION(readPads__Q26System12KPadDirectorFv);
// PAL: 0x805237e8..0x805238f0
UNKNOWN_FUNCTION(calcControllers__Q26System12KPadDirectorFb);
// PAL: 0x805238f0..0x80523990
UNKNOWN_FUNCTION(calc__Q26System12KPadDirectorFv);
// PAL: 0x80523990..0x80523a58
UNKNOWN_FUNCTION(setController__Q26System12KPadDirectorFPQ26System4KPadQ26System18eControllerTypeUcb);
// PAL: 0x80523a58..0x80523a80
UNKNOWN_FUNCTION(getControllerType__Q26System12KPadDirectorFQ26System14eControlSource);
// PAL: 0x80523a80..0x80523bc8
UNKNOWN_FUNCTION(copyController__Q26System12KPadDirectorFPQ26System4KPadPQ26System4KPadb);
// PAL: 0x80523bc8..0x80523d10
UNKNOWN_FUNCTION(initMasterController__Q26System12KPadDirectorFv);
// PAL: 0x80523d10..0x80523eac
UNKNOWN_FUNCTION(setPlayerToMasterController__Q26System12KPadDirectorFUc);
// PAL: 0x80523eac..0x80523ebc
UNKNOWN_FUNCTION(resetMasterController__Q26System12KPadDirectorFv);
// PAL: 0x80523ebc..0x805240ec
UNKNOWN_FUNCTION(initPlayerController__Q26System12KPadDirectorFUcb);
// PAL: 0x805240ec..0x80524264
UNKNOWN_FUNCTION(setMasterToPlayerController__Q26System12KPadDirectorFUc);
// PAL: 0x80524264..0x8052427c
UNKNOWN_FUNCTION(resetPlayerController__Q26System12KPadDirectorFUc);
// PAL: 0x8052427c..0x805242d8
UNKNOWN_FUNCTION(resetPlayerControllers__Q26System12KPadDirectorFv);
// PAL: 0x805242d8..0x80524438
UNKNOWN_FUNCTION(initPlayerControllers__Q26System12KPadDirectorFv);
// PAL: 0x80524438..0x80524500
UNKNOWN_FUNCTION(setPlayerController__Q26System12KPadDirectorFUcQ26System14eControlSourceUc);
// PAL: 0x80524500..0x8052453c
UNKNOWN_FUNCTION(setGhostController__Q26System12KPadDirectorFUc);
// PAL: 0x8052453c..0x80524558
UNKNOWN_FUNCTION(setGhostController__Q26System12KPadDirectorFUcPUsb);
// PAL: 0x80524558..0x80524568
UNKNOWN_FUNCTION(unk_80524558);
// PAL: 0x80524568..0x80524580
UNKNOWN_FUNCTION(lockGhostProxies__Q26System12KPadDirectorFv);
// PAL: 0x80524580..0x805245cc
UNKNOWN_FUNCTION(startGhostProxies__Q26System12KPadDirectorFv);
// PAL: 0x805245cc..0x805245dc
UNKNOWN_FUNCTION(endGhostProxy__Q26System12KPadDirectorFUc);
// PAL: 0x805245dc..0x80524628
UNKNOWN_FUNCTION(endGhostProxies__Q26System12KPadDirectorFv);
// PAL: 0x80524628..0x805246c0
UNKNOWN_FUNCTION(getPadStatus__Q26System12KPadDirectorFUcP9PADStatus);
// PAL: 0x805246c0..0x80524718
UNKNOWN_FUNCTION(loadRumbleSettings__Q26System12KPadDirectorFv);
// PAL: 0x80524718..0x80524734
UNKNOWN_FUNCTION(unloadRumbleSettings__Q26System12KPadDirectorFv);
// PAL: 0x80524734..0x80524788
UNKNOWN_FUNCTION(syncDeviceCallbackImpl__Q26System12KPadDirectorFi);
// PAL: 0x80524788..0x805247e4
UNKNOWN_FUNCTION(startSync__Q26System12KPadDirectorFv);
// PAL: 0x805247e4..0x80524840
UNKNOWN_FUNCTION(stopSync__Q26System12KPadDirectorFv);
// PAL: 0x80524840..0x805248d8
UNKNOWN_FUNCTION(enableDpds__Q26System12KPadDirectorFPb);
// PAL: 0x805248d8..0x80524944
UNKNOWN_FUNCTION(restoreDpds__Q26System12KPadDirectorFPb);
// PAL: 0x80524944..0x80524998
UNKNOWN_FUNCTION(unk_80524944);
// PAL: 0x80524998..0x805249b0
UNKNOWN_FUNCTION(unk_80524998);
// PAL: 0x805249b0..0x805249c8
UNKNOWN_FUNCTION(unk_805249b0);
// PAL: 0x805249c8..0x80524a50
UNKNOWN_FUNCTION(stopAllMotors2__Q26System12KPadDirectorFv);
// PAL: 0x80524a50..0x80524a58
UNKNOWN_FUNCTION(unk_80524a50);
// PAL: 0x80524a58..0x80524aa8
UNKNOWN_FUNCTION(calcInner__Q26System16KPadAIControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState);
// PAL: 0x80524aa8..0x80524ab0
UNKNOWN_FUNCTION(getControlSource__Q26System16KPadAIControllerFv);
// PAL: 0x80524ab0..0x80524ab4
UNKNOWN_FUNCTION(calcInner__Q26System19KPadDummyControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState);
// PAL: 0x80524ab4..0x80524ac4
UNKNOWN_FUNCTION(__sinit__KPadDirector_cpp);
}


namespace System {
// Temporary definition
struct RumbleManager {
  u8 _00[0x10];
};

class KPadDirector {
public:
  enum eControllerType {

    //! @brief Wiimote, Nunchuck or Classic
    CONTROLLER_TYPE_WII = 0,

    //! @brief Gamecube
    CONTROLLER_TYPE_GC = 1,

    CONTROLLER_TYPE_OTHER = 3,
  };

public:
  static KPadDirector* spInstance;

  static KPadDirector* createInstance();
  static void destroyInstance();

  static void syncDeviceCallback(int result);

  static eControllerType getControllerType(eControlSource controlSource);

public:
  KPadDirector();
  virtual ~KPadDirector() {}                      // [vt+0x08]

  void initialize();

  void resetPlayersActivityStatus();
  bool checkPlayerActivityStatus(u8 playerIdx,
                                 u16 maxInactiveFrames,
                                 u16 maxDisconnectedFrames);

  void reset();
  void reset2(); // inlined in reset

  void stopAllMotors();
  void stopAllMotors2(); // stop gc motors first instead of wii motors first...

  void readPads();

  void calcControllers(bool isPaused);
  void calc();

  bool setController(KPad* dest, eControllerType type,
                     u8 playerIdx, bool noSet);
  bool copyController(KPad* dest, KPad* source, bool noSet);

  bool initMasterController();
  bool setPlayerToMasterController(u8 playerIdx);
  void resetMasterController();

  bool initPlayerController(u8 playerIdx, bool noSet = false);
  bool setMasterToPlayerController(u8 playerIdx);
  void resetPlayerController(u8 playerIdx);
  void resetPlayerControllers();
  u32 initPlayerControllers();
  void setPlayerController(u8 playerIdx, eControlSource controlSource,
                           u8 controllerIdx);

  void setGhostController(u8 playerIdx);
  void setGhostController(u8 playerIdx, u16* ghostBuffer, bool driftIsAuto);

  void lockGhostProxies();
  void startGhostProxies();
  void endGhostProxy(u8 playerIdx);
  void endGhostProxies();

  u32 getPadStatus(u8 padIdx, PADStatus* dest = nullptr);

  void loadRumbleSettings();
  void unloadRumbleSettings();

  void syncDeviceCallbackImpl(int result); // inlined in syncDeviceCallback
  void startSync();
  void stopSync();

  void enableDpds(bool* prevStates);
  void restoreDpds(bool* prevStates);

public:
  KPadPlayer mPlayers[4];                         // [this+0x0004]
  KPadAI mAIs[12];                                // [this+0x03b4]
  KPad mMaster;                                   // [this+0x15b4]
  bool _168c;
  u8 _168d;
  u8 _168e;
  u8 _168f;
  KPadDummyController mDummyController;           // [this+0x1690]
  KPadWiiController mWiiControllers[4];           // [this+0x1720]
  KPadGCController mGCControllers[4];             // [this+0x3ba0]
  KPadGhostController mGhostControllers[4];       // [this+0x3e60]
  RumbleManager mRumbleManager;                   // [this+0x4100]
  u8 _4110[0x10];
  PADStatus mPadStatuses[4];                      // [this+0x4120]
  u32 _4150;
  bool mIsPaused;                                 // [this+0x4154]
  bool mIsMirror;                                 // [this+0x4155]
  u8 _4156;
  u8 _4157;
  s32 _4158; // WPAD sync related
};

static_assert(sizeof(KPadDirector) == 0x415c);
} // namespace System
