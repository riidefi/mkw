#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "ui/ControlGroup.hpp"

namespace UI {

class MenuInputManager;

class Page {
public:
  Page();
  virtual ~Page();

  void draw(u32 pass);
  void setAnimationDirection(s32 animationDirection);
  void initChildren(s32 capacity);
  void insert(s32 index, UIControl* control, u32 drawPass);
  void setInputManager(MenuInputManager* inputManager);
  void skipInAnimation(void);
  void startReplace(s32 animationDirection, f32 delay);
  void skipOutAnimation(void);

private:
  s32 mId;
  s32 mState;
  bool mNextStateRequested;
  u8 _0d[0x10 - 0x0d];
  s32 mAnimationDirection;
  f32 mAnimationStartFrame;
  f32 mAnimationDelay;
  s32 mFrame;
  u32 mUnknown;
  ControlGroup mControlGroup;
  MenuInputManager* mInputManager;
  u32 mNextAnimationSfxId;
  u32 mPrevAnimationSfxId;
};

static_assert(sizeof(Page) == 0x44);

} // namespace UI
