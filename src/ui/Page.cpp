#include "Page.hpp"
#include "ControlGroup.hpp"

namespace UI {

void Page::draw(u32 pass) {
    if (mState > 5 || mState < 3) {
        return;
    }

    mControlGroup.draw(pass);
}

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
