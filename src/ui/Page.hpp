#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8060197c..0x80601a04
UNKNOWN_FUNCTION(Page_construct);
// PAL: 0x80601a04..0x80601a60
UNKNOWN_FUNCTION(Page_destroy);
// PAL: 0x80601a60..0x80601ad8
UNKNOWN_FUNCTION(Page_init);
// PAL: 0x80601ad8..0x80601adc
UNKNOWN_FUNCTION(Page_onInit);
// PAL: 0x80601adc..0x80601aec
UNKNOWN_FUNCTION(Page_fini);
// PAL: 0x80601aec..0x80601c08
UNKNOWN_FUNCTION(Page_activate);
// PAL: 0x80601c08..0x80601c48
UNKNOWN_FUNCTION(Page_deactivate);
// PAL: 0x80601c48..0x80601c64
UNKNOWN_FUNCTION(unk_80601c48);
// PAL: 0x80601c64..0x80601d24
UNKNOWN_FUNCTION(unk_80601c64);
// PAL: 0x80601d24..0x80601f44
UNKNOWN_FUNCTION(unk_80601d24);
// PAL: 0x80601f44..0x80602144
UNKNOWN_FUNCTION(unk_80601f44);
// PAL: 0x80602144..0x806022cc
UNKNOWN_FUNCTION(unk_80602144);
// PAL: 0x806022cc..0x80602338
UNKNOWN_FUNCTION(Page_calc);
// PAL: 0x80602338..0x8060235c
UNKNOWN_FUNCTION(unk_80602338);
// PAL: 0x8060235c..0x80602378
UNKNOWN_FUNCTION(draw__Q22UI4PageFUl);
// PAL: 0x80602378..0x8060238c
UNKNOWN_FUNCTION(unk_80602378);
// PAL: 0x8060238c..0x80602390
UNKNOWN_FUNCTION(unk_8060238c);
// PAL: 0x80602390..0x80602428
UNKNOWN_FUNCTION(Page_refocus);
// PAL: 0x80602428..0x8060244c
UNKNOWN_FUNCTION(unk_80602428);
// PAL: 0x8060244c..0x8060245c
UNKNOWN_FUNCTION(setAnimationDirection__Q22UI4PageFl);
// PAL: 0x8060245c..0x8060246c
UNKNOWN_FUNCTION(initChildren__Q22UI4PageFl);
// PAL: 0x8060246c..0x80602474
UNKNOWN_FUNCTION(insert__Q22UI4PageFlPQ22UI9UIControlUl);
// PAL: 0x80602474..0x8060247c
UNKNOWN_FUNCTION(setInputManager__Q22UI4PageFPQ22UI16MenuInputManager);
// PAL: 0x8060247c..0x80602488
UNKNOWN_FUNCTION(skipInAnimation__Q22UI4PageFv);
// PAL: 0x80602488..0x806024a4
UNKNOWN_FUNCTION(startReplace__Q22UI4PageFlf);
// PAL: 0x806024a4..0x806024b0
UNKNOWN_FUNCTION(skipOutAnimation__Q22UI4PageFv);
// PAL: 0x806024b0..0x80602530
UNKNOWN_FUNCTION(Page_changeSection);
// PAL: 0x80602530..0x806025b0
UNKNOWN_FUNCTION(unk_80602530);
// PAL: 0x806025b0..0x8060265c
UNKNOWN_FUNCTION(Page_push);
// PAL: 0x8060265c..0x806027ac
UNKNOWN_FUNCTION(unk_8060265c);
// PAL: 0x806027ac..0x806028cc
UNKNOWN_FUNCTION(unk_806027ac);
// PAL: 0x806028cc..0x80602920
UNKNOWN_FUNCTION(unk_806028cc);
// PAL: 0x80602920..0x80602960
UNKNOWN_FUNCTION(unk_80602920);
// PAL: 0x80602960..0x80602970
UNKNOWN_FUNCTION(unk_80602960);
// PAL: 0x80602970..0x806029f4
UNKNOWN_FUNCTION(unk_80602970);
// PAL: 0x806029f4..0x80602b04
UNKNOWN_FUNCTION(unk_806029f4);
// PAL: 0x80602b04..0x80602c60
UNKNOWN_FUNCTION(unk_80602b04);
// PAL: 0x80602c60..0x80602ce8
UNKNOWN_FUNCTION(unk_80602c60);
// PAL: 0x80602ce8..0x80602cf8
UNKNOWN_FUNCTION(unk_80602ce8);
// PAL: 0x80602cf8..0x80602d0c
UNKNOWN_FUNCTION(Page_playSfx);
// PAL: 0x80602d0c..0x80602d20
UNKNOWN_FUNCTION(unk_80602d0c);
// PAL: 0x80602d20..0x80602d2c
UNKNOWN_FUNCTION(unk_80602d20);

#ifdef __cplusplus
}
#endif


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
