#pragma once

#include <rk_types.h>

#include <rk_common.h>

#include <decomp.h>

#include <rvl/pad/pad.h>

#include <system/KPadController.hpp>

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
  KPadAI mAIs[MAX_PLAYER_COUNT];                  // [this+0x03b4]
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
