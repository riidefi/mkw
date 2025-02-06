#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>

#include <rvl/kpad/kpad.h>
#include <rvl/pad/pad.h>
#include <rvl/wpad/wpad.h>
namespace System {

class KPadGhostButtonsStream;
class KPadRecorder;
class KPadWiiControllerData;
class RumbleManager;

////////// INPUT STATE /////////////////

struct KPadRaceInputState {
  inline KPadRaceInputState() { reset(); }
  virtual ~KPadRaceInputState() {}                // [vt+0x08]

  void reset();

  bool operator==(const KPadRaceInputState& rhs) const;

  void setStickXMirrored(u8 x);
  void setStickXUnmirrored(u8 x);
  void setStickY(u8 y);
  void setTrick(u8 trick);

  u16 mButtons;                                   // [this+0x04]
  u16 mButtonsRaw;                                // [this+0x06]
  EGG::Vector2f mStick;                           // [this+0x08]
  u8 mStickXRaw;                                  // [this+0x10]
  u8 mStickYRaw;                                  // [this+0x11]
  u8 mTrick;                                      // [this+0x12]
  u8 mTrickRaw;                                   // [this+0x13]
  struct {                                        // [this+0x14]
    bool mIsValid: 1;
    bool mFlags_1: 1;
    bool mFlags_2: 1;
    bool mFlags_3: 1;
    bool mFlags_4: 1;
    bool mFlags_5: 1;
    bool mFlags_6: 1;
    bool mFlags_7: 1;
  };
  u8 _15;
  u8 _16;
  u8 _17;
};

static_assert(sizeof(KPadRaceInputState) == 0x18);

struct KPadUIInputState {
  inline KPadUIInputState() { reset(); }
  virtual ~KPadUIInputState() {}                  // [vt+0x08]

  void reset();

  void setStickXMirrored(u8 x);
  void setStickY(u8 y);

  u16 mButtons;                                   // [this+0x04]
  u16 mButtonsRaw;                                // [this+0x06]
  EGG::Vector2f mStick;                           // [this+0x08]
  u8 _10[0x08];
  u8 mStickXRaw;                                  // [this+0x18]
  u8 mStickYRaw;                                  // [this+0x19]
  u8 _1a;
  u8 _1b;
  EGG::Vector2f mPointerPos;                      // [this+0x1c]
  EGG::Vector2f mPointerHorizontal;               // [this+0x24]
  float mPointerDist;                             // [this+0x2c]
  struct {                                        // [this+0x30]
    volatile u8 mFlags_0: 1; // volatile feels like a hack...
    u8 mFlags_1: 1;
    u8 mFlags_2: 1;
    u8 mFlags_3: 1;
    u8 mFlags_4: 1;
    u8 mFlags_5: 1;
    u8 mFlags_6: 1;
    u8 mFlags_7: 1;
  };
  u8 _31;
  u8 _32;
  u8 _33;
};

static_assert(sizeof(KPadUIInputState) == 0x34);

////////// CONTROLLER //////////////////

enum eControlSource {
  CONTROL_SOURCE_UNKNOWN    = -1,

  //! @brief Wiimote
  //!
  CONTROL_SOURCE_CORE       = 0,

  //! @brief Wiimote+Nunchuck
  //!
  CONTROL_SOURCE_FREESTYLE  = 2,

  //! @brief Classic controller
  //!
  CONTROL_SOURCE_CLASSIC    = 3,

  //! @brief Gamecube controller
  //!
  CONTROL_SOURCE_GAMECUBE   = 4,

  CONTROL_SOURCE_GHOST      = 5,

  CONTROL_SOURCE_AI         = 6,
};

class KPadController {
public:
  KPadController();
  virtual ~KPadController() {}                    // [vt+0x08]

  void calc();

  //! @brief [vt+0x0c] Called by `calc`.
  //!
  virtual void calcInner(KPadRaceInputState* raceInputState,
                         KPadUIInputState* uiInputState) = 0;

  virtual eControlSource getControlSource();      // [vt+0x10]
  virtual bool isRumbleEnabled();                 // [vt+0x14]
  virtual void startMotor();                      // [vt+0x18]
  virtual void stopMotor();                       // [vt+0x1c]
  virtual void stopMotorHard() {}                 // [vt+0x20]
  virtual double getStreamSize();                 // [vt+0x24]
  virtual void setDpdEnabled(bool enabled);       // [vt+0x28]
  virtual bool isDpdEnabled();                    // [vt+0x2c]
  virtual void updateBatteryStatus();             // [vt+0x30]
  virtual int getChan();                          // [vt+0x34]
  virtual void setDriftIsAuto(bool isAuto);       // [vt+0x38]
  virtual void* vf_3c();                          // [vt+0x3c]
  virtual u32 getBatteryLevelAsync();             // [vt+0x40]
  virtual void reset(bool driftIsAuto);           // [vt+0x44]

public:
  KPadRaceInputState mRaceInputState;             // [this+0x04]
  KPadUIInputState mUIInputState;                 // [this+0x1c]
  bool mIsConnected;                              // [this+0x50]
  bool mDriftIsAuto;                              // [this+0x51]
  u8 _52;
  u8 _53;
  u32 mBattery;                                   // [this+0x54]
  bool mOutOfBattery;                             // [this+0x58]
  u8 _59;
  u8 _5a;
  u8 _5b;
  KPadUIInputState mPrevUIInputState;             // [this+0x5c]
};

static_assert(sizeof(KPadController) == 0x90);

class KPadWiiController : public KPadController {
public:
  KPadWiiController();
  virtual ~KPadWiiController() {};                // [vt+0x08]

  //! @brief [vt+0x0c]
  void calcInner(KPadRaceInputState* raceInputState,
                 KPadUIInputState* uiInputState) override;

  eControlSource getControlSource() override;     // [vt+0x10]
  bool isRumbleEnabled() override;                // [vt+0x14]
  void startMotor() override;                     // [vt+0x18]
  void stopMotor() override;                      // [vt+0x1c]
  void stopMotorHard() override;                  // [vt+0x20]
  void setDpdEnabled(bool enabled) override;      // [vt+0x28]
  bool isDpdEnabled() override;                   // [vt+0x2c]
  int getChan() override;                         // [vt+0x34]
  u32 getBatteryLevelAsync() override;            // [vt+0x40]
  void reset(bool driftIsAuto) override;          // [vt+0x44]

private:

  // Calc inputs for Classic
  void calcClassic(KPADUnifiedWpadStatus* kpadUnifiedWpadStatus,
                   KPadRaceInputState* raceInputState,
                   KPadUIInputState* uiInputState);

  // Convert race input to UI input for Wiimote
  void raceToUIInputCore(KPadUIInputState* dst, KPadRaceInputState* src);

  // Convert race input to UI input for Nunchuck
  void raceToUIInputFreestyle(KPadUIInputState* dst, KPadRaceInputState* src);

  // Callback used in `getBatteryLevelAsync`
  static void updateBatteryCallback(int chan, int result);

  // Inlined in `updateBatteryCallback`
  void updateBattery(int result);

public:
  KPADStatus mKpadStatuses[0x10];                 // [this+0x090]
  u8 mKpadStatusCount;                            // [this+0x8d0]
  u8 _8d1;
  u8 _8d2;
  u8 _8d3;
  int mChan;                                      // [this+0x8d4]
  int mType;                                      // [this+0x8d8]
  eControlSource mControlSource;                  // [this+0x8dc]
  WPADInfo mWpadInfo;                             // [this+0x8e0]
  u16 _8f8;
  u8 _8fa;
  u8 _8fb;
  u16 _8fc;
  u16 _8fe;
  int mWpadType;                                  // [this+0x900]
  bool mClassicIsInDrift;                         // [this+0x904]
  u8 _905;
  u16 _906;
  EGG::Vector2f mPointerPos;                      // [this+0x908]
  EGG::Vector2f mPointerHorizontal;               // [this+0x910]
  f32 mPointerDist;                               // [this+0x918]
  KPadWiiControllerData* mWiiControllerData;      // [this+0x91c]
};

static_assert(sizeof(KPadWiiController) == 0x920);

class KPadGCController : public KPadController {
public:
  KPadGCController();
  virtual ~KPadGCController() {}                  // [vt+0x08]

  //! @brief [vt+0x0c]
  void calcInner(KPadRaceInputState* raceInputState,
                 KPadUIInputState* uiInputState) override;

  eControlSource getControlSource() override;     // [vt+0x10]
  bool isRumbleEnabled() override;                // [vt+0x14]
  void startMotor() override;                     // [vt+0x18]
  void stopMotor() override;                      // [vt+0x1c]
  void stopMotorHard() override;                  // [vt+0x20]
  int getChan() override;                         // [vt+0x34]
  void reset(bool driftIsAuto) override;          // [vt+0x44]

public:
  PADStatus mPadStatus;                           // [this+0x90]
  int mChan;                                      // [this+0x9c]
  EGG::Vector2f mSubstick;                        // [this+0xa0]
  u16 _a8;
  bool _aa;
  u8 _ab;
  u16 _ac;
  u8 _ae;
  u8 _af;
};

static_assert(sizeof(KPadGCController) == 0xb0);

class KPadGhostController : public KPadController {
public:
  KPadGhostController();
  virtual ~KPadGhostController();                 // [vt+0x08]

  //! @brief [vt+0x0c]
  void calcInner(KPadRaceInputState* raceInputState,
                 KPadUIInputState* uiInputState) override;

  eControlSource getControlSource() override;     // [vt+0x10]
  double getStreamSize() override;                // [vt+0x24]
  void setDriftIsAuto(bool isAuto) override;      // [vt+0x38]
  void reset(bool driftIsAuto) override;          // [vt+0x44]

  bool hasGhostBuffer() const;
  void readGhostBuffer(u16* buttonsData, bool isAuto);

public:
  u16* mGhostBuffer;                              // [this+0x90]
  KPadGhostButtonsStream* mButtonsStreams[3];     // [this+0x94]
  u8 _a0;
  u8 _a1;
  u8 _a2;
  u8 _a3;
  u8 _a4;
  u8 _a5;
  bool _a6;
  u8 _a7;
};

static_assert(sizeof(KPadGhostController) == 0xa8);

class KPadAIController : public KPadController {
public:
  KPadAIController();
  virtual ~KPadAIController() {}                  // [vt+0x08]

  //! @brief [vt+0x0c] Copy `mAIRaceInputState` into `raceInputState`.
  //!
  void calcInner(KPadRaceInputState* raceInputState,
                 KPadUIInputState* uiInputState) override;

public:
  KPadRaceInputState mAIRaceInputState;           // [this+0x90]
};

static_assert(sizeof(KPadAIController) == 0xa8);

class KPadDummyController : public KPadController {
public:
  virtual ~KPadDummyController() {}               // [vt+0x08]

  //! @brief [vt+0x0c] Do nothing.
  //!
  void calcInner(KPadRaceInputState* raceInputState,
                 KPadUIInputState* uiInputState) override {}
};

////////// KPAD ////////////////////////

struct KPadControllerInfo {
  eControlSource mControlSource;
  struct Addr {
    u8 mBytes[6];

    void getDevAddr(int chan);
    bool operator==(const Addr& rhs) const;
  } mWiimoteAddr;
  u8 _0a;
  u8 _0b;
  int mChan;

  bool operator==(const KPadControllerInfo& rhs) const;
};

class KPad {
public:
  KPad();
  virtual ~KPad() {}                              // [vt+0x08]

  virtual void calc(bool isPaused);               // [vt+0x0c]
  virtual void reset();                           // [vt+0x10]
  // [vt+0x14]
  virtual void setInputState(KPadRaceInputState* raceInputState);
  virtual u16* getRecordedBuffer();               // [vt+0x18]
  virtual u32 getRecordedBufferSize();            // [vt+0x1c]
  virtual void initRumbleManagers();              // [vt+0x20]

  void setDriftIsAuto(u16 isAuto);

  void setController(KPadController* controller, KPadController* controller2);

  void startMotor();
  void stopMotor();
  void stopMotorHard();

public:
  KPadController* mController;                    // [this+0x04]
  KPadController* mController2;                   // [this+0x08]
  KPadController* mController3;                   // [this+0x0c]
  s32 _10; // Related to rumble
  s8 _14; // Related to rumble
  u8 _15;
  u8 _16;
  u8 _17;
  void* _18; // Related to rumble
  s8 _1c;
  u8 _1d;
  u8 _1e;
  u8 _1f;
  RumbleManager* mRumbleManager;                  // [this+0x20]
  RumbleManager* mRumbleManager2;                 // [this+0x24]
  KPadRaceInputState mRaceInputState;             // [this+0x28]
  KPadRaceInputState mPrevRaceInputState;         // [this+0x40]
  KPadUIInputState mUIInputState;                 // [this+0x58]
  KPadUIInputState mPrevUIPInputState;            // [this+0x8c]
  s16 _c0; // Is drift auto (?)
  u16 mInactivityFrames;                          // [this+0xc2]
  u16 mDisconnectedFrames;                        // [this+0xc4]
  bool _c6; // Is paused (?)
  u8 _c7;
  KPadControllerInfo mControllerInfo;             // [this+0xc8]
};

static_assert(sizeof(KPad) == 0xd8);

class KPadPlayer : public KPad {
public:
  virtual ~KPadPlayer();                          // [vt+0x08]

  void calc(bool isPaused) override;              // [vt+0x0c]
  void reset() override;                          // [vt+0x10]
  u16* getRecordedBuffer() override;              // [vt+0x18]
  u32 getRecordedBufferSize() override;           // [vt+0x1c]

  void startGhostProxy();
  void endGhostProxy();

  void setGhostController(KPadController* controller,
                          KPadController* controller2,
                          bool driftIsAuto);

public:
  u16* mGhostBuffer;                              // [this+0xd8]
  u16* mRecordedBuffer;                           // [this+0xdc]
  u32 mRecordedBufferSize;                        // [this+0xe0]
  bool mIsLocked;                                 // [this+0xe4]
  u8 _e5;
  u8 _e6;
  u8 _e7;
  KPadRecorder* mRecorder;                        // [this+0xe8]
};

static_assert(sizeof(KPadPlayer) == 0xec);

class KPadAI : public KPad {
public:
  virtual ~KPadAI() {};                           // [vt+0x08]

  // [vt+0x14]
  void setInputState(KPadRaceInputState* raceInputState) override;

public:
  KPadAIController mAIController;                 // [this+0xd8]
};

static_assert(sizeof(KPadAI) == 0x180);
} // namespace System
