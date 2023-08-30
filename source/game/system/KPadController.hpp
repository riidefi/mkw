#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>

#include <rvl/kpad/kpad.h>
#include <rvl/pad/pad.h>
#include <rvl/wpad/wpad.h>


extern "C" {
// PAL: 0x8051e85c..0x8051e89c
UNKNOWN_FUNCTION(reset__Q26System18KPadRaceInputStateFv);
// PAL: 0x8051e89c..0x8051e904
UNKNOWN_FUNCTION(__eq__Q26System18KPadRaceInputStateCFRCQ26System18KPadRaceInputState);
// PAL: 0x8051e904..0x8051e960
UNKNOWN_FUNCTION(reset__Q26System16KPadUIInputStateFv);
// PAL: 0x8051e960..0x8051e9e8
UNKNOWN_FUNCTION(setStickXMirrored__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051e9e8..0x8051ea28
UNKNOWN_FUNCTION(setStickXUnmirrored__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051ea28..0x8051ea60
UNKNOWN_FUNCTION(rawStickToFloat__6SystemFUc);
// PAL: 0x8051ea60..0x8051eaa0
UNKNOWN_FUNCTION(setStickY__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051eaa0..0x8051eb28
UNKNOWN_FUNCTION(setStickXMirrored__Q26System16KPadUIInputStateFUc);
// PAL: 0x8051eb28..0x8051eb68
UNKNOWN_FUNCTION(setStickY__Q26System16KPadUIInputStateFUc);
// PAL: 0x8051eb68..0x8051eba8
UNKNOWN_FUNCTION(setTrick__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051eba8..0x8051ec94
UNKNOWN_FUNCTION(__ct__Q26System14KPadControllerFv);
// PAL: 0x8051ec94..0x8051ecd4
UNKNOWN_FUNCTION(__dt__Q26System18KPadRaceInputStateFv);
// PAL: 0x8051ecd4..0x8051ed14
UNKNOWN_FUNCTION(__dt__Q26System16KPadUIInputStateFv);
// PAL: 0x8051ed14..0x8051f00c
UNKNOWN_FUNCTION(calc__Q26System14KPadControllerFv);
// PAL: 0x8051f00c..0x8051f010
UNKNOWN_FUNCTION(stopMotorHard__Q26System14KPadControllerFv);
// PAL: 0x8051f010..0x8051f074
UNKNOWN_FUNCTION(updateBatteryStatus__Q26System14KPadControllerFv);
// PAL: 0x8051f074..0x8051f07c
UNKNOWN_FUNCTION(getBatteryLevelAsync__Q26System14KPadControllerFv);
// PAL: 0x8051f07c..0x8051f088
UNKNOWN_FUNCTION(vf_3c__Q26System14KPadControllerFv);
// PAL: 0x8051f088..0x8051f1ec
UNKNOWN_FUNCTION(__ct__Q26System17KPadWiiControllerFv);
// PAL: 0x8051f1ec..0x8051f22c
UNKNOWN_FUNCTION(__dt__Q26System14KPadControllerFv);
// PAL: 0x8051f22c..0x8051f308
UNKNOWN_FUNCTION(reset__Q26System17KPadWiiControllerFb);
// PAL: 0x8051f308..0x8051f37c
UNKNOWN_FUNCTION(reset__Q26System14KPadControllerFb);
// PAL: 0x8051f37c..0x8051f384
UNKNOWN_FUNCTION(setIsDriftAuto__Q26System14KPadControllerFb);
// PAL: 0x8051f384..0x8051f3b4
UNKNOWN_FUNCTION(updateBatteryCallback__Q26System17KPadWiiControllerFii);
// PAL: 0x8051f3b4..0x8051f3d0
UNKNOWN_FUNCTION(updateBattery__Q26System17KPadWiiControllerFi);
// PAL: 0x8051f3d0..0x8051f410
UNKNOWN_FUNCTION(getBatteryLevelAsync__Q26System17KPadWiiControllerFv);
// PAL: 0x8051f410..0x8051fa7c
UNKNOWN_FUNCTION(calcClassic__Q26System17KPadWiiControllerFP21KPADUnifiedWpadStatusPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState);
// PAL: 0x8051fa7c..0x8051fbe0
UNKNOWN_FUNCTION(raceToUIInputFreestyle__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState);
// PAL: 0x8051fbe0..0x8051fc84
UNKNOWN_FUNCTION(raceToUIInputCore__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState);
// PAL: 0x8051fc84..0x8051ffb8
UNKNOWN_FUNCTION(calcInner__Q26System17KPadWiiControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState);
// PAL: 0x8051ffb8..0x8051ffd0
UNKNOWN_FUNCTION(setDpdEnabled__Q26System17KPadWiiControllerFb);
// PAL: 0x8051ffd0..0x80520118
UNKNOWN_FUNCTION(__ct__Q26System16KPadGCControllerFv);
// PAL: 0x80520118..0x805201b0
UNKNOWN_FUNCTION(reset__Q26System16KPadGCControllerFb);
// PAL: 0x805201b0..0x805206fc
UNKNOWN_FUNCTION(calcInner__Q26System16KPadGCControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState);
// PAL: 0x805206fc..0x80520730
UNKNOWN_FUNCTION(isRumbleEnabled__Q26System16KPadGCControllerFv);
// PAL: 0x80520730..0x80520924
UNKNOWN_FUNCTION(GhostController_construct);
// PAL: 0x80520924..0x80520998
UNKNOWN_FUNCTION(GhostController_destroy);
// PAL: 0x80520998..0x80520a4c
UNKNOWN_FUNCTION(unk_80520998);
// PAL: 0x80520a4c..0x80520a60
UNKNOWN_FUNCTION(unk_80520a4c);
// PAL: 0x80520a60..0x80520b18
UNKNOWN_FUNCTION(unk_80520a60);
// PAL: 0x80520b18..0x80520b9c
UNKNOWN_FUNCTION(unk_80520b18);
// PAL: 0x80520b9c..0x80520d4c
UNKNOWN_FUNCTION(GhostController_calcInner);
// PAL: 0x80520d4c..0x80520eb4
UNKNOWN_FUNCTION(DirectionButtonsStream_readFrame);
// PAL: 0x80520eb4..0x80520ebc
UNKNOWN_FUNCTION(DirectionButtonsStream_getSequenceSize);
// PAL: 0x80520ebc..0x80520f2c
UNKNOWN_FUNCTION(Input_vf_20);
// PAL: 0x80520f2c..0x80520f64
UNKNOWN_FUNCTION(unk_80520f2c);
// PAL: 0x80520f64..0x80521110
UNKNOWN_FUNCTION(KartInput_construct);
// PAL: 0x80521110..0x80521198
UNKNOWN_FUNCTION(Input_vf_10);
// PAL: 0x80521198..0x80521554
UNKNOWN_FUNCTION(Input_vf_0c);
// PAL: 0x80521554..0x805215d4
UNKNOWN_FUNCTION(KartInput_setController);
// PAL: 0x805215d4..0x80521688
UNKNOWN_FUNCTION(GhostPadProxy_start);
// PAL: 0x80521688..0x80521768
UNKNOWN_FUNCTION(GhostPadProxy_end);
// PAL: 0x80521768..0x80521844
UNKNOWN_FUNCTION(PlayerInput_calc);
// PAL: 0x80521844..0x80521930
UNKNOWN_FUNCTION(PlayerKartInput_setGhostController);
// PAL: 0x80521930..0x805219ac
UNKNOWN_FUNCTION(unk_80521930);
// PAL: 0x805219ac..0x80521a34
UNKNOWN_FUNCTION(unk_805219ac);
// PAL: 0x80521a34..0x80521acc
UNKNOWN_FUNCTION(unk_80521a34);
// PAL: 0x80521acc..0x80521d84
UNKNOWN_FUNCTION(unk_80521acc);
// PAL: 0x80521d84..0x80521d8c
UNKNOWN_FUNCTION(unk_80521d84);
// PAL: 0x80521d8c..0x80521e48
UNKNOWN_FUNCTION(unk_80521d8c);
// PAL: 0x80521e48..0x80521ed0
UNKNOWN_FUNCTION(unk_80521e48);
// PAL: 0x80521ed0..0x80521f8c
UNKNOWN_FUNCTION(unk_80521ed0);
// PAL: 0x80521f8c..0x80522014
UNKNOWN_FUNCTION(unk_80521f8c);
// PAL: 0x80522014..0x80522078
UNKNOWN_FUNCTION(unk_80522014);
// PAL: 0x80522078..0x8052208c
UNKNOWN_FUNCTION(unk_80522078);
// PAL: 0x8052208c..0x80522090
UNKNOWN_FUNCTION(Controller_startMotor);
// PAL: 0x80522090..0x805220a4
UNKNOWN_FUNCTION(unk_80522090);
// PAL: 0x805220a4..0x805220a8
UNKNOWN_FUNCTION(Controller_stopMotor);
// PAL: 0x805220a8..0x805220bc
UNKNOWN_FUNCTION(unk_805220a8);
// PAL: 0x805220bc..0x805222b4
UNKNOWN_FUNCTION(PlayerKartInput_construct);
// PAL: 0x805222b4..0x805222f4
UNKNOWN_FUNCTION(KartInput_destroy);
// PAL: 0x805222f4..0x80522358
UNKNOWN_FUNCTION(PlayerKartInput_destroy);
// PAL: 0x80522358..0x80522364
UNKNOWN_FUNCTION(unk_80522358);
// PAL: 0x80522364..0x80522494
UNKNOWN_FUNCTION(unk_80522364);
// PAL: 0x80522494..0x8052249c
UNKNOWN_FUNCTION(Controller_getChan);
// PAL: 0x8052249c..0x8052250c
UNKNOWN_FUNCTION(unk_8052249c);
// PAL: 0x8052250c..0x805225a4
UNKNOWN_FUNCTION(unk_8052250c);
// PAL: 0x805225a4..0x80522690
UNKNOWN_FUNCTION(unk_805225a4);
// PAL: 0x80522690..0x805226f4
UNKNOWN_FUNCTION(unk_80522690);
// PAL: 0x805226f4..0x805226f8
UNKNOWN_FUNCTION(Input_setInputState);
// PAL: 0x805226f8..0x80522700
UNKNOWN_FUNCTION(unk_805226f8);
// PAL: 0x80522700..0x80522708
UNKNOWN_FUNCTION(unk_80522700);
// PAL: 0x80522708..0x8052279c
UNKNOWN_FUNCTION(PlayerKartInput_reset);
// PAL: 0x8052279c..0x805227dc
UNKNOWN_FUNCTION(AiKartInput_destroy);
// PAL: 0x805227dc..0x8052281c
UNKNOWN_FUNCTION(unk_805227dc);
// PAL: 0x8052281c..0x80522824
UNKNOWN_FUNCTION(Controller_isDpdEnabled);
// PAL: 0x80522824..0x80522828
UNKNOWN_FUNCTION(Controller_controlDpd);
// PAL: 0x80522828..0x8052282c
UNKNOWN_FUNCTION(GhostController_setDriftIsAuto);
// PAL: 0x8052282c..0x80522834
UNKNOWN_FUNCTION(unk_8052282c);
// PAL: 0x80522834..0x80522840
UNKNOWN_FUNCTION(unk_80522834);
// PAL: 0x80522840..0x8052284c
UNKNOWN_FUNCTION(GcController_stopMotorHard);
// PAL: 0x8052284c..0x80522858
UNKNOWN_FUNCTION(GcController_stopMotor);
// PAL: 0x80522858..0x80522864
UNKNOWN_FUNCTION(GcController_startMotor);
// PAL: 0x80522864..0x8052286c
UNKNOWN_FUNCTION(GcController_getChan);
// PAL: 0x8052286c..0x80522874
UNKNOWN_FUNCTION(unk_8052286c);
// PAL: 0x80522874..0x805228b4
UNKNOWN_FUNCTION(GcController_destroy);
// PAL: 0x805228b4..0x805228c4
UNKNOWN_FUNCTION(WiiController_stopMotorHard);
// PAL: 0x805228c4..0x805228d0
UNKNOWN_FUNCTION(WiiController_stopMotor);
// PAL: 0x805228d0..0x805228dc
UNKNOWN_FUNCTION(WiiController_startMotor);
// PAL: 0x805228dc..0x805228f4
UNKNOWN_FUNCTION(unk_805228dc);
// PAL: 0x805228f4..0x80522924
UNKNOWN_FUNCTION(WiiController_isDpdEnabled);
// PAL: 0x80522924..0x8052292c
UNKNOWN_FUNCTION(WiiController_getChan);
// PAL: 0x8052292c..0x80522934
UNKNOWN_FUNCTION(unk_8052292c);
// PAL: 0x80522934..0x80522974
UNKNOWN_FUNCTION(WiiController_destroy);
}


namespace System {

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

class KPadController {
public:
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
  virtual float vf_24();                          // [vt+0x24]
  virtual void setDpdEnabled(bool enabled);       // [vt+0x28]
  virtual bool isDpdEnabled();                    // [vt+0x2c]
  virtual void updateBatteryStatus();             // [vt+0x30]
  virtual int getChan();                          // [vt+0x34]
  virtual void setIsDriftAuto(bool isAuto);       // [vt+0x38]
  virtual void* vf_3c();                          // [vt+0x3c]
  virtual u32 getBatteryLevelAsync();             // [vt+0x40]
  virtual void reset(bool isDriftAuto);           // [vt+0x44]

public:
  KPadRaceInputState mRaceInputState;             // [this+0x04]
  KPadUIInputState mUIInputState;                 // [this+0x1c]
  bool mIsConnected;                              // [this+0x50]
  bool mIsDriftAuto;                              // [this+0x51]
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

class KPadWiiControllerData;

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
  void reset(bool isDriftAuto) override;          // [vt+0x44]

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
  void reset(bool isDriftAuto) override;          // [vt+0x44]

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
} // namespace System
