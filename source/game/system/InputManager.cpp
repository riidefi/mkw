#include "InputManager.hpp"

#include <platform/string.h>

#include <game/system/ResourceManager.hpp>


// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80020ff4
extern UNKNOWN_FUNCTION(__construct_array);
// PAL: 0x800210ec
extern UNKNOWN_FUNCTION(__destroy_arr);
// PAL: 0x801bf634
extern UNKNOWN_FUNCTION(WPADStartSyncSimple);
// PAL: 0x801bf63c
extern UNKNOWN_FUNCTION(WPADStopSimpleSync);
// PAL: 0x801bf640
extern UNKNOWN_FUNCTION(WPADSetSyncDeviceCallback);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8051e85c
extern UNKNOWN_FUNCTION(RaceInputState_reset);
// PAL: 0x8051eba8
extern UNKNOWN_FUNCTION(Controller_construct);
// PAL: 0x8051ed14
extern UNKNOWN_FUNCTION(calc__Q26System10ControllerFv);
// PAL: 0x8051f088
extern UNKNOWN_FUNCTION(WiiController_construct);
// PAL: 0x8051ffd0
extern UNKNOWN_FUNCTION(GcController_construct);
// PAL: 0x80520730
extern UNKNOWN_FUNCTION(GhostController_construct);
// PAL: 0x80520924
extern UNKNOWN_FUNCTION(GhostController_destroy);
// PAL: 0x80520f64
extern UNKNOWN_FUNCTION(KartInput_construct);
// PAL: 0x80521554
extern void setController__Q26System9KartInputFPQ26System10ControllerPQ26System10Controller(void*, void*, void*);
// PAL: 0x805215d4
extern void GhostPadProxy_start(void*);
// PAL: 0x80521688
extern void GhostPadProxy_end(void*);
// PAL: 0x80521844
extern void PlayerKartInput_setGhostController(void*, void*, void*, bool);
// PAL: 0x80521930
extern void unk_80521930(void*);
// PAL: 0x80521a34
extern void unk_80521a34(float, void*, int, int);
// PAL: 0x80521d8c
extern UNKNOWN_FUNCTION(unk_80521d8c);
// PAL: 0x80521ed0
extern UNKNOWN_FUNCTION(unk_80521ed0);
// PAL: 0x805220bc
extern UNKNOWN_FUNCTION(PlayerKartInput_construct);
// PAL: 0x805222f4
extern UNKNOWN_FUNCTION(PlayerKartInput_destroy);
// PAL: 0x80522358
extern void unk_80522358(void*);
// PAL: 0x80522364
extern void unk_80522364(void*, void*);
// PAL: 0x80522690
extern UNKNOWN_FUNCTION(unk_80522690);
// PAL: 0x8052279c
extern UNKNOWN_FUNCTION(AiKartInput_destroy);
// PAL: 0x80522874
extern UNKNOWN_FUNCTION(GcController_destroy);
// PAL: 0x80522934
extern UNKNOWN_FUNCTION(WiiController_destroy);
// PAL: 0x805230e0
extern UNKNOWN_FUNCTION(callback__6SystemFi);
// PAL: 0x805232f0
extern UNKNOWN_FUNCTION(__ct__Q26System12InputManagerFv);
// PAL: 0x805234a0
extern UNKNOWN_FUNCTION(AiKartInput_construct);
// PAL: 0x805237e8
extern UNKNOWN_FUNCTION(calcPads__Q26System12InputManagerFb);
// PAL: 0x805250c8
extern UNKNOWN_FUNCTION(load__Q26System14RumbleSettingsFPv);
// PAL: 0x80525204
extern UNKNOWN_FUNCTION(RumbleSettings_dt);
// PAL: 0x805411fc
extern UNKNOWN_FUNCTION(getFile__Q26System15ResourceManagerFlPCcPUl);// Extern data references.
// PAL: 0x8088fd10
extern u32 lbl_8088fd10[];
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
extern UNKNOWN_DATA(spInstance__Q26System12InputManager);
// PAL: 0x809bd738
extern UNKNOWN_DATA(spInstance__Q26System15ResourceManager);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data


// .bss


namespace System {

void callback(int param) {
  InputManager::spInstance->callback(param);
}

InputManager* InputManager::createInstance() {
  if (!spInstance) {
    spInstance = new InputManager;
  }
  return spInstance;
}

void InputManager::destroyInstance() {
  if (spInstance) {
    delete spInstance;
  }
  spInstance = nullptr;
}
} // namespace System

// Symbol: __dt__Q26System12InputManagerFv
// PAL: 0x805231dc..0x805232b0
MARK_BINARY_BLOB(__dt__Q26System12InputManagerFv, 0x805231dc, 0x805232b0);
asm UNKNOWN_FUNCTION(__dt__Q26System12InputManagerFv) {
  #include "asm/805231dc.s"
}

// Symbol: unk_805232b0
// PAL: 0x805232b0..0x805232f0
MARK_BINARY_BLOB(unk_805232b0, 0x805232b0, 0x805232f0);
asm UNKNOWN_FUNCTION(unk_805232b0) {
  #include "asm/805232b0.s"
}

// Symbol: __ct__Q26System12InputManagerFv
// PAL: 0x805232f0..0x805234a0
MARK_BINARY_BLOB(__ct__Q26System12InputManagerFv, 0x805232f0, 0x805234a0);
asm UNKNOWN_FUNCTION(__ct__Q26System12InputManagerFv) {
  #include "asm/805232f0.s"
}

// Symbol: AiKartInput_construct
// PAL: 0x805234a0..0x80523520
MARK_BINARY_BLOB(AiKartInput_construct, 0x805234a0, 0x80523520);
asm UNKNOWN_FUNCTION(AiKartInput_construct) {
  #include "asm/805234a0.s"
}

namespace System {

void InputManager::initialize() {

}

void InputManager::_reset() {
  memset(mPadStatuses, 0, sizeof(mPadStatuses[0])); // only reset first pad??

  for (u8 i = 0; i < 4; ++i) {
    mPlayerInputs[i].reset();
  }

  unk_80522358(this);
  unk_80522690();

  _4156 = 0;
  mIsPaused = false;
  _168c = false;
}

void InputManager::reset2() {
  _reset();
}

void InputManager::clearSomePlayerInputFields() {
  mPlayerInputs[0]._c2 = 0;
  mPlayerInputs[0]._c4 = 0;
  mPlayerInputs[1]._c2 = 0;
  mPlayerInputs[1]._c4 = 0;
  mPlayerInputs[2]._c2 = 0;
  mPlayerInputs[2]._c4 = 0;
  mPlayerInputs[3]._c2 = 0;
  mPlayerInputs[3]._c4 = 0;
}

bool InputManager::checkSomePlayerInputFields(s32 playerIdx, u16 cmp1, u16 cmp2) {
  Controller* con = mPlayerInputs[playerIdx].mController;
  s32 conId = con ? con->getControllerId() : -1;
  if ((conId < 4 || 5 < conId) && (conId != -1)) {
    if (mPlayerInputs[playerIdx]._c2 > cmp1) {
      return true;
    }
    if (mPlayerInputs[playerIdx]._c4 > cmp2) {
      return true;
    }
  }
  return false;
}

void InputManager::reset() {
  _reset();
  calcPads(false);
}

void InputManager::clear() {
  for (u8 i = 0; i < 4; i++) {
    mWiiControllers[i].stopMotorHard();
  }
  for (u8 i = 0; i < 4; i++) {
    mGCControllers[i].stopMotorHard();
  }
}

void InputManager::readPads() {
  PADRead(mPadStatuses);
  PADClampCircle2(mPadStatuses, 2);
}

const u32 PAD_MASKS[] = {
  1 << 31,
  1 << 30,
  1 << 29,
  1 << 28,
};

void InputManager::calcPads(bool isPaused) {
  // TODO: grab the number of elements from a constant
  for (u8 i = 0; i < 4; i++) {
    mWiiControllers[i].calc();
  }

  u32 mask = 0;
  for (u8 i = 0; i < 4; i++) {
    mGCControllers[i].calc();

    int errType;
    switch (mPadStatuses[i].err) {
    case 0:
      errType = 0;
      break;
    case -1:
      errType = 2;
      break;
    default:
      errType = 1;
      break;
    }
    if (errType == 2) {
      mask |= PAD_MASKS[i];
    }
  }
  if (mask != 0) {
    PADReset(mask);
  }

  if (isPaused) {
    return;
  }

  for (u8 i = 0; i < 4; i++) {
    mGhostControllers[i].calc();
  }
}

void InputManager::calc() {
  readPads();
  calcPads(mIsPaused);

  for (int i = 0; i < 4; ++i) {
    mPlayerInputs[i].calc(mIsPaused);
  }

  mInputDesuka.unk_0c(0);
}

bool InputManager::setPlayerControllerSomething(KartInput* input, int conType, u32 conIdx, bool flag) {
  bool wasSet = false;
  switch (conType) {
  case 0:
    { // brackets to silence warning until function that gets inline is defined
      WiiController& wiiCon = mWiiControllers[conIdx];
      if (wiiCon.mOk) {
        if (!flag) {
          input->setController(&wiiCon, nullptr);
        }
        input->mController3 = input->mController; // probably inlined
        unk_80522364(&input->mInputIdentity, input->mController);
        wasSet = true;
      }
      break;
    }
  case 1:
    GCController& gcCon = mGCControllers[conIdx];
    if (gcCon.mOk) {
      if (!flag) {
        input->setController(&gcCon, nullptr);
      }
      input->mController3 = input->mController; // probably inlined
      unk_80522364(&input->mInputIdentity, input->mController);
      wasSet = true;
    }
    break;
  }
  return wasSet;
}

int InputManager::getControllerType(int type) {
  int result = 3;
  switch (type) {
  case 3:
    result = 1;
    break;
  case 0:
  case 1:
  case 2:
    result = 0;
    break;
  default:
    break;
  }
  return result;
}
} // namespace System

// Symbol: unk_80523a80
// PAL: 0x80523a80..0x80523bc8
MARK_BINARY_BLOB(unk_80523a80, 0x80523a80, 0x80523bc8);
asm UNKNOWN_FUNCTION(unk_80523a80) {
  #include "asm/80523a80.s"
}

// Symbol: unk_80523bc8
// PAL: 0x80523bc8..0x80523d10
MARK_BINARY_BLOB(unk_80523bc8, 0x80523bc8, 0x80523d10);
asm UNKNOWN_FUNCTION(unk_80523bc8) {
  #include "asm/80523bc8.s"
}

// Symbol: unk_80523d10
// PAL: 0x80523d10..0x80523eac
MARK_BINARY_BLOB(unk_80523d10, 0x80523d10, 0x80523eac);
asm UNKNOWN_FUNCTION(unk_80523d10) {
  #include "asm/80523d10.s"
}

// Symbol: unk_80523eac
// PAL: 0x80523eac..0x80523ebc
MARK_BINARY_BLOB(unk_80523eac, 0x80523eac, 0x80523ebc);
asm UNKNOWN_FUNCTION(unk_80523eac) {
  #include "asm/80523eac.s"
}

// Symbol: tryRegister__Q26System12InputManagerFUlb
// PAL: 0x80523ebc..0x805240ec
MARK_BINARY_BLOB(tryRegister__Q26System12InputManagerFUlb, 0x80523ebc, 0x805240ec);
asm UNKNOWN_FUNCTION(tryRegister__Q26System12InputManagerFUlb) {
  #include "asm/80523ebc.s"
}

// Symbol: unk_805240ec
// PAL: 0x805240ec..0x80524264
MARK_BINARY_BLOB(unk_805240ec, 0x805240ec, 0x80524264);
asm UNKNOWN_FUNCTION(unk_805240ec) {
  #include "asm/805240ec.s"
}

// FIXME: un-skill-issue this symbol
// Symbol: reset__Q26System12InputManagerFvPlayerController
// PAL: 0x80524264..0x8052427c
MARK_BINARY_BLOB(reset__Q26System12InputManagerFvPlayerController, 0x80524264, 0x8052427c);
asm UNKNOWN_FUNCTION(reset__Q26System12InputManagerFvPlayerController) {
  #include "asm/80524264.s"
}

// Symbol: unk_8052427c
// PAL: 0x8052427c..0x805242d8
MARK_BINARY_BLOB(unk_8052427c, 0x8052427c, 0x805242d8);
asm UNKNOWN_FUNCTION(unk_8052427c) {
  #include "asm/8052427c.s"
}

// Symbol: initControllers__Q26System12InputManagerFv
// PAL: 0x805242d8..0x80524438
MARK_BINARY_BLOB(initControllers__Q26System12InputManagerFv, 0x805242d8, 0x80524438);
asm UNKNOWN_FUNCTION(initControllers__Q26System12InputManagerFv) {
  #include "asm/805242d8.s"
}

namespace System {

void InputManager::setPlayerInput(u8 playerIdx, int type, u8 conIdx) {
  int conType = getControllerType(type);
  switch (conType) {
  case 1:
      mPlayerInputs[playerIdx].setController(&mGCControllers[conIdx], 0);
      break;
  case 0:
      mPlayerInputs[playerIdx].setController(&mWiiControllers[conIdx], 0);
      break;
  default:
      break;
  }

  // probably inlined
  PlayerInput& playerInput = mPlayerInputs[playerIdx];
  playerInput.mController3 = playerInput.mController;
  unk_80522364(&playerInput.mInputIdentity, playerInput.mController);
}

void InputManager::setGhostController(u8 playerIdx) {
  setGhostController(playerIdx, 0, mPlayerInputs[playerIdx].isDriftAuto());
}

void InputManager::setGhostController(u8 playerIdx, void* inputs, bool isDriftAuto) {
  PlayerKartInput_setGhostController(&mPlayerInputs[playerIdx], &mGhostControllers[playerIdx],
                                     inputs, isDriftAuto);
}

void InputManager::unk_80524558(u8 playerIdx) {
  unk_80521930(&mPlayerInputs[playerIdx]);
}

void InputManager::initGhostProxies() {
  for (int i = 0; i < 4; ++i) {
    mPlayerInputs[i].isLocked = true;
  }
}

void InputManager::startGhostProxies() {
  for (int i = 0; i < 4; ++i) {
    GhostPadProxy_start(&mPlayerInputs[i]);
  }
}

void InputManager::endGhostProxy(u8 playerIdx) {
  GhostPadProxy_end(&mPlayerInputs[playerIdx]);
}

void InputManager::endGhostProxies() {
  for (int i = 0; i < 4; ++i) {
    GhostPadProxy_end(&mPlayerInputs[i]);
  }
}

int InputManager::getPadStatus(u32 padIdx, PADStatus* dest) {
  if (dest) {
    *dest = mPadStatuses[padIdx];
  }

  switch (mPadStatuses[padIdx].err) {
  case 0:
    return 0;
  case -1:
    return 2;
  default:
    return 1;
  };
}

//extern const char unk8088fd28[1];
//const char unk8088fd28[1] = "";

void InputManager::loadRumbleSettings() {
  // TODO: make an enum for archiveIdx (0 is for COMMON)
  void* krmData = ResourceManager::spInstance.nonvol->getFile(0, "/vibration.krm", nullptr);
  if (krmData) {
    mRumbleSettings.load(krmData);
  }
}
} // namespace System

// // Symbol: loadRumbleSettings__Q26System12InputManagerFv
// // PAL: 0x805246c0..0x80524718
// MARK_BINARY_BLOB(loadRumbleSettings__Q26System12InputManagerFv, 0x805246c0, 0x80524718);
// asm UNKNOWN_FUNCTION(loadRumbleSettings__Q26System12InputManagerFv) {
//   #include "asm/805246c0.s"
// }

namespace System {

void InputManager::unloadRumbleSettings() {
  // possibly an inline of some sort of unload function
  if (mRumbleSettings.mKRMData) {
    mRumbleSettings.load(nullptr);
  }
}

void InputManager::callback(int param) {
  if (param != 1) {
      return;
  }

  switch (_4158) {
  case 0:
  case 2:
      _4158 = 0;
      break;
  case 1:
      _4158 = 2;
      break;
  case 3:
      _4158 = 0;
      break;
  default:
      break;
  }
}
} // namespace System

// Symbol: unk_80524788
// PAL: 0x80524788..0x805247e4
MARK_BINARY_BLOB(unk_80524788, 0x80524788, 0x805247e4);
asm UNKNOWN_FUNCTION(unk_80524788) {
  #include "asm/80524788.s"
}

// Symbol: unk_805247e4
// PAL: 0x805247e4..0x80524840
MARK_BINARY_BLOB(unk_805247e4, 0x805247e4, 0x80524840);
asm UNKNOWN_FUNCTION(unk_805247e4) {
  #include "asm/805247e4.s"
}

// Symbol: unk_80524840
// PAL: 0x80524840..0x805248d8
MARK_BINARY_BLOB(unk_80524840, 0x80524840, 0x805248d8);
asm UNKNOWN_FUNCTION(unk_80524840) {
  #include "asm/80524840.s"
}

// Symbol: unk_805248d8
// PAL: 0x805248d8..0x80524944
MARK_BINARY_BLOB(unk_805248d8, 0x805248d8, 0x80524944);
asm UNKNOWN_FUNCTION(unk_805248d8) {
  #include "asm/805248d8.s"
}

namespace System {

void unk_80524944(u8 playerIdx, int param2, u32 param3) {
  unk_80521a34(static_cast<float>(param3),
               &InputManager::spInstance->mPlayerInputs[playerIdx],
               param2, 1);
}
  extern const float ZERO_FLOAT3;
  const float ZERO_FLOAT3 = 0.0f;

} // namespace System

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

// Symbol: unk_805249c8
// PAL: 0x805249c8..0x80524a50
MARK_BINARY_BLOB(unk_805249c8, 0x805249c8, 0x80524a50);
asm UNKNOWN_FUNCTION(unk_805249c8) {
  #include "asm/805249c8.s"
}

// Symbol: unk_80524a50
// PAL: 0x80524a50..0x80524a58
MARK_BINARY_BLOB(unk_80524a50, 0x80524a50, 0x80524a58);
asm UNKNOWN_FUNCTION(unk_80524a50) {
  #include "asm/80524a50.s"
}

// Symbol: unk_80524a58
// PAL: 0x80524a58..0x80524aa8
MARK_BINARY_BLOB(unk_80524a58, 0x80524a58, 0x80524aa8);
asm UNKNOWN_FUNCTION(unk_80524a58) {
  #include "asm/80524a58.s"
}

// Symbol: AiController_vf10
// PAL: 0x80524aa8..0x80524ab0
MARK_BINARY_BLOB(AiController_vf10, 0x80524aa8, 0x80524ab0);
asm UNKNOWN_FUNCTION(AiController_vf10) {
  #include "asm/80524aa8.s"
}

// Symbol: unk_80524ab0
// PAL: 0x80524ab0..0x80524ab4
MARK_BINARY_BLOB(unk_80524ab0, 0x80524ab0, 0x80524ab4);
asm UNKNOWN_FUNCTION(unk_80524ab0) {
  #include "asm/80524ab0.s"
}

// Symbol: unk_80524ab4
// PAL: 0x80524ab4..0x80524ac4
MARK_BINARY_BLOB(unk_80524ab4, 0x80524ab4, 0x80524ac4);
asm UNKNOWN_FUNCTION(unk_80524ab4) {
  #include "asm/80524ab4.s"
}

