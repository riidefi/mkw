#include "Page.hpp"
#include "ControlGroup.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021584
extern UNKNOWN_FUNCTION(_savegpr_20);
// PAL: 0x800215d0
extern UNKNOWN_FUNCTION(_restgpr_20);
// PAL: 0x805c23e4
extern UNKNOWN_FUNCTION(__ct__Q22UI12ControlGroupFv);
// PAL: 0x805c2400
extern UNKNOWN_FUNCTION(__dt__Q22UI12ControlGroupFv);
// PAL: 0x805c2620
extern UNKNOWN_FUNCTION(create__Q22UI12ControlGroupFPQ22UI4Pagei);
// PAL: 0x805c27dc
extern UNKNOWN_FUNCTION(insert__Q22UI12ControlGroupFiPQ22UI9UIControli);
// PAL: 0x805c2868
extern UNKNOWN_FUNCTION(init__Q22UI12ControlGroupFv);
// PAL: 0x805c28d8
extern UNKNOWN_FUNCTION(calc__Q22UI12ControlGroupFv);
// PAL: 0x805c2948
extern UNKNOWN_FUNCTION(draw__Q22UI12ControlGroupFi);
// PAL: 0x805c2ad0
extern UNKNOWN_FUNCTION(transform__Q22UI12ControlGroupFRQ32UI12ControlGroup7Functor);
// PAL: 0x805eed70
extern UNKNOWN_FUNCTION(InputThing_activate);
// PAL: 0x805f2100
extern UNKNOWN_FUNCTION(unk_805f2100);
// PAL: 0x8060265c
extern UNKNOWN_FUNCTION(unk_8060265c);
// PAL: 0x80602b04
extern UNKNOWN_FUNCTION(unk_80602b04);
// PAL: 0x80622e00
extern UNKNOWN_FUNCTION(Section_activatePage);
// PAL: 0x80635a3c
extern UNKNOWN_FUNCTION(SectionManager_setNextSection);
// PAL: 0x80635ac8
extern UNKNOWN_FUNCTION(SectionManager_startChangeSection);
// PAL: 0x80635b2c
extern UNKNOWN_FUNCTION(SectionManager_startReinit);
// PAL: 0x8063d0b8
extern UNKNOWN_FUNCTION(UIControl_solve);
// PAL: 0x8063d0e0
extern UNKNOWN_FUNCTION(UIControl_onPageEvent);
// PAL: 0x8063d284
extern UNKNOWN_FUNCTION(UIControl_getAnimStartFrame);
// PAL: 0x807146a8
extern UNKNOWN_FUNCTION(unk_807146a8);
// PAL: 0x8071476c
extern UNKNOWN_FUNCTION(unk_8071476c);// Extern data references.
// PAL: 0x80385fc8
extern UNKNOWN_DATA(spInstance__Q26System8RKSystem);
// PAL: 0x80896820
extern UNKNOWN_DATA(lbl_80896820);
// PAL: 0x80896824
extern UNKNOWN_DATA(lbl_80896824);
// PAL: 0x80896828
extern UNKNOWN_DATA(lbl_80896828);
// PAL: 0x80896838
extern UNKNOWN_DATA(lbl_80896838);
// PAL: 0x808ba5c0
extern UNKNOWN_DATA(lbl_808ba5c0);
// PAL: 0x808ba624
extern UNKNOWN_DATA(lbl_808ba624);
// PAL: 0x808ba630
extern UNKNOWN_DATA(lbl_808ba630);
// PAL: 0x808ba63c
extern UNKNOWN_DATA(lbl_808ba63c);
// PAL: 0x809c1c90
extern UNKNOWN_DATA(lbl_809c1c90);
// PAL: 0x809c1e38
extern UNKNOWN_DATA(lbl_809c1e38);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data


// .bss


// Symbol: Page_construct
// PAL: 0x8060197c..0x80601a04
MARK_BINARY_BLOB(Page_construct, 0x8060197c, 0x80601a04);
asm UNKNOWN_FUNCTION(Page_construct) {
  #include "asm/8060197c.s"
}

// Symbol: Page_destroy
// PAL: 0x80601a04..0x80601a60
MARK_BINARY_BLOB(Page_destroy, 0x80601a04, 0x80601a60);
asm UNKNOWN_FUNCTION(Page_destroy) {
  #include "asm/80601a04.s"
}

// Symbol: Page_init
// PAL: 0x80601a60..0x80601ad8
MARK_BINARY_BLOB(Page_init, 0x80601a60, 0x80601ad8);
asm UNKNOWN_FUNCTION(Page_init) {
  #include "asm/80601a60.s"
}

// Symbol: Page_onInit
// PAL: 0x80601ad8..0x80601adc
MARK_BINARY_BLOB(Page_onInit, 0x80601ad8, 0x80601adc);
asm UNKNOWN_FUNCTION(Page_onInit) {
  #include "asm/80601ad8.s"
}

// Symbol: Page_fini
// PAL: 0x80601adc..0x80601aec
MARK_BINARY_BLOB(Page_fini, 0x80601adc, 0x80601aec);
asm UNKNOWN_FUNCTION(Page_fini) {
  #include "asm/80601adc.s"
}

// Symbol: Page_activate
// PAL: 0x80601aec..0x80601c08
MARK_BINARY_BLOB(Page_activate, 0x80601aec, 0x80601c08);
asm UNKNOWN_FUNCTION(Page_activate) {
  #include "asm/80601aec.s"
}

// Symbol: Page_deactivate
// PAL: 0x80601c08..0x80601c48
MARK_BINARY_BLOB(Page_deactivate, 0x80601c08, 0x80601c48);
asm UNKNOWN_FUNCTION(Page_deactivate) {
  #include "asm/80601c08.s"
}

// Symbol: unk_80601c48
// PAL: 0x80601c48..0x80601c64
MARK_BINARY_BLOB(unk_80601c48, 0x80601c48, 0x80601c64);
asm UNKNOWN_FUNCTION(unk_80601c48) {
  #include "asm/80601c48.s"
}

// Symbol: unk_80601c64
// PAL: 0x80601c64..0x80601d24
MARK_BINARY_BLOB(unk_80601c64, 0x80601c64, 0x80601d24);
asm UNKNOWN_FUNCTION(unk_80601c64) {
  #include "asm/80601c64.s"
}

// Symbol: unk_80601d24
// PAL: 0x80601d24..0x80601f44
MARK_BINARY_BLOB(unk_80601d24, 0x80601d24, 0x80601f44);
asm UNKNOWN_FUNCTION(unk_80601d24) {
  #include "asm/80601d24.s"
}

// Symbol: unk_80601f44
// PAL: 0x80601f44..0x80602144
MARK_BINARY_BLOB(unk_80601f44, 0x80601f44, 0x80602144);
asm UNKNOWN_FUNCTION(unk_80601f44) {
  #include "asm/80601f44.s"
}

// Symbol: unk_80602144
// PAL: 0x80602144..0x806022cc
MARK_BINARY_BLOB(unk_80602144, 0x80602144, 0x806022cc);
asm UNKNOWN_FUNCTION(unk_80602144) {
  #include "asm/80602144.s"
}

// Symbol: Page_calc
// PAL: 0x806022cc..0x80602338
MARK_BINARY_BLOB(Page_calc, 0x806022cc, 0x80602338);
asm UNKNOWN_FUNCTION(Page_calc) {
  #include "asm/806022cc.s"
}

// Symbol: unk_80602338
// PAL: 0x80602338..0x8060235c
MARK_BINARY_BLOB(unk_80602338, 0x80602338, 0x8060235c);
asm UNKNOWN_FUNCTION(unk_80602338) {
  #include "asm/80602338.s"
}

namespace UI {

void Page::draw(u32 pass) {
    if (mState > 5 || mState < 3) {
        return;
    }

    mControlGroup.draw(pass);
}

}

// Symbol: unk_80602378
// PAL: 0x80602378..0x8060238c
MARK_BINARY_BLOB(unk_80602378, 0x80602378, 0x8060238c);
asm UNKNOWN_FUNCTION(unk_80602378) {
  #include "asm/80602378.s"
}

// Symbol: unk_8060238c
// PAL: 0x8060238c..0x80602390
MARK_BINARY_BLOB(unk_8060238c, 0x8060238c, 0x80602390);
asm UNKNOWN_FUNCTION(unk_8060238c) {
  #include "asm/8060238c.s"
}

// Symbol: Page_refocus
// PAL: 0x80602390..0x80602428
MARK_BINARY_BLOB(Page_refocus, 0x80602390, 0x80602428);
asm UNKNOWN_FUNCTION(Page_refocus) {
  #include "asm/80602390.s"
}

// Symbol: unk_80602428
// PAL: 0x80602428..0x8060244c
MARK_BINARY_BLOB(unk_80602428, 0x80602428, 0x8060244c);
asm UNKNOWN_FUNCTION(unk_80602428) {
  #include "asm/80602428.s"
}

namespace UI {

void Page::setAnimationDirection(s32 animationDirection) {
    if (animationDirection == -1) {
        return;
    }

    mAnimationDirection = animationDirection;
}

void Page::initChildren(s32 capacity) {
    mControlGroup.create(this, capacity);
}

void Page::insert(s32 index, UIControl* control, u32 drawPass) {
    mControlGroup.insert(index, control, drawPass);
}

void Page::setInputManager(MenuInputManager* inputManager) {
    mInputManager = inputManager;
}

void Page::skipInAnimation(void) {
    mNextStateRequested = true;
}

void Page::startReplace(s32 animationDirection, f32 delay) {
  setAnimationDirection(animationDirection);
  mAnimationDelay = delay;
  mNextStateRequested = true;
}

void Page::skipOutAnimation(void) {
    mNextStateRequested = true;
}

}

// Symbol: Page_changeSection
// PAL: 0x806024b0..0x80602530
MARK_BINARY_BLOB(Page_changeSection, 0x806024b0, 0x80602530);
asm UNKNOWN_FUNCTION(Page_changeSection) {
  #include "asm/806024b0.s"
}

// Symbol: unk_80602530
// PAL: 0x80602530..0x806025b0
MARK_BINARY_BLOB(unk_80602530, 0x80602530, 0x806025b0);
asm UNKNOWN_FUNCTION(unk_80602530) {
  #include "asm/80602530.s"
}

// Symbol: Page_push
// PAL: 0x806025b0..0x8060265c
MARK_BINARY_BLOB(Page_push, 0x806025b0, 0x8060265c);
asm UNKNOWN_FUNCTION(Page_push) {
  #include "asm/806025b0.s"
}

// Symbol: unk_8060265c
// PAL: 0x8060265c..0x806027ac
MARK_BINARY_BLOB(unk_8060265c, 0x8060265c, 0x806027ac);
asm UNKNOWN_FUNCTION(unk_8060265c) {
  #include "asm/8060265c.s"
}

// Symbol: unk_806027ac
// PAL: 0x806027ac..0x806028cc
MARK_BINARY_BLOB(unk_806027ac, 0x806027ac, 0x806028cc);
asm UNKNOWN_FUNCTION(unk_806027ac) {
  #include "asm/806027ac.s"
}

// Symbol: unk_806028cc
// PAL: 0x806028cc..0x80602920
MARK_BINARY_BLOB(unk_806028cc, 0x806028cc, 0x80602920);
asm UNKNOWN_FUNCTION(unk_806028cc) {
  #include "asm/806028cc.s"
}

// Symbol: unk_80602920
// PAL: 0x80602920..0x80602960
MARK_BINARY_BLOB(unk_80602920, 0x80602920, 0x80602960);
asm UNKNOWN_FUNCTION(unk_80602920) {
  #include "asm/80602920.s"
}

// Symbol: unk_80602960
// PAL: 0x80602960..0x80602970
MARK_BINARY_BLOB(unk_80602960, 0x80602960, 0x80602970);
asm UNKNOWN_FUNCTION(unk_80602960) {
  #include "asm/80602960.s"
}

// Symbol: unk_80602970
// PAL: 0x80602970..0x806029f4
MARK_BINARY_BLOB(unk_80602970, 0x80602970, 0x806029f4);
asm UNKNOWN_FUNCTION(unk_80602970) {
  #include "asm/80602970.s"
}

// Symbol: unk_806029f4
// PAL: 0x806029f4..0x80602b04
MARK_BINARY_BLOB(unk_806029f4, 0x806029f4, 0x80602b04);
asm UNKNOWN_FUNCTION(unk_806029f4) {
  #include "asm/806029f4.s"
}

// Symbol: unk_80602b04
// PAL: 0x80602b04..0x80602c60
MARK_BINARY_BLOB(unk_80602b04, 0x80602b04, 0x80602c60);
asm UNKNOWN_FUNCTION(unk_80602b04) {
  #include "asm/80602b04.s"
}

// Symbol: unk_80602c60
// PAL: 0x80602c60..0x80602ce8
MARK_BINARY_BLOB(unk_80602c60, 0x80602c60, 0x80602ce8);
asm UNKNOWN_FUNCTION(unk_80602c60) {
  #include "asm/80602c60.s"
}

// Symbol: unk_80602ce8
// PAL: 0x80602ce8..0x80602cf8
MARK_BINARY_BLOB(unk_80602ce8, 0x80602ce8, 0x80602cf8);
asm UNKNOWN_FUNCTION(unk_80602ce8) {
  #include "asm/80602ce8.s"
}

// Symbol: Page_playSfx
// PAL: 0x80602cf8..0x80602d0c
MARK_BINARY_BLOB(Page_playSfx, 0x80602cf8, 0x80602d0c);
asm UNKNOWN_FUNCTION(Page_playSfx) {
  #include "asm/80602cf8.s"
}

// Symbol: unk_80602d0c
// PAL: 0x80602d0c..0x80602d20
MARK_BINARY_BLOB(unk_80602d0c, 0x80602d0c, 0x80602d20);
asm UNKNOWN_FUNCTION(unk_80602d0c) {
  #include "asm/80602d0c.s"
}

// Symbol: unk_80602d20
// PAL: 0x80602d20..0x80602d2c
MARK_BINARY_BLOB(unk_80602d20, 0x80602d20, 0x80602d2c);
asm UNKNOWN_FUNCTION(unk_80602d20) {
  #include "asm/80602d20.s"
}

