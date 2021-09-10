#include "UIControl.hpp"

namespace UI {

UIControl::UIControl()
    : mGroup(nullptr), mZIndex(0.0f), mHidden(false), mDrawPass(0),
      mAnimated(true), mAnimStartFrame(0.0f), mOnShowSfxId(-1),
      mOnHideSfxId(-1) {}

struct UnkStruct {
  ~UnkStruct();
};

UnkStruct::~UnkStruct() {}

UIControl::~UIControl() {}

void UIControl::debug() { mChildren.debug(); }

void UIControl::init() {
  initSelf();
  mChildren.init();
}

void UIControl::calc() {
  calcSelf();
  mChildren.calc();
}

void UIControl::draw(int draw_pass) {
  if (getParent() == nullptr && mDrawPass != draw_pass)
    return;

  if (mHidden)
    return;

  mChildren.draw(draw_pass);
}

void UIControl::solve(float frame) {
  if (!mAnimated)
    frame = 0.0f;

  solveAnim(elem(POS_FIXED).trans.x, frame);
}

extern void SpawnSfx(s32 id, s32, void*); // 807146A8
#define SFX_ID_NULL (~0u)

void UIControl::onPageEvent(PageEventTrigger event, u32 page_id) {
  if (event == EVENT_PAGE_OPEN && mOnShowSfxId != SFX_ID_NULL) {
    SpawnSfx(mOnShowSfxId, -1, getGroup()->getPage());
  } else if (event == EVENT_PAGE_CLOSE && mOnHideSfxId != SFX_ID_NULL) {
    SpawnSfx(mOnHideSfxId, -1, getGroup()->getPage());
  }

  onPageEventSelf(event, page_id);
}

extern float*** spMenuData_; // 809C1E38

#define BLEND_COLORS(a, b) ((((a) + 1) * ((b) + 1) - 1) >> 8)

void UIControl::solveAnim(float& page_anim_x, float frame) {
  page_anim_x = -spMenuData_[0][0][0x3F0 / 4] * frame;

  UIControl* parent = getParent();
  if (parent) {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x +
        elem(POS_FIXED).trans.x * parent->elem(POS_ARTIST_REL).scale.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y +
        elem(POS_FIXED).trans.y * parent->elem(POS_ARTIST_REL).scale.y;
    //  mScreenSpace.translate.x =
    //      artistPos.translate.x + (fixedPos.translate.x *
    //      parent.artistPos.scale.x);
    //  mScreenSpace.translate.y =
    //      artistPos.translate.y + fixedPos.translate.y *
    //      parent.artistPos.scale.y;
  } else {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x + elem(POS_FIXED).trans.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y + elem(POS_FIXED).trans.y;
    //  mScreenSpace.translate.x = artistPos.translate.x + fixedPos.translate.x;
    //  mScreenSpace.translate.y = artistPos.translate.y + fixedPos.translate.y;
  }

  elem(POS_SCREENSPACE).trans.z =
      elem(POS_ARTIST_REL).trans.z + elem(POS_FIXED).trans.z;
  // mScreenSpace.translate.z = artistPos.translate.z + fixedPos.translate.z;

  elem(POS_SCREENSPACE).scale.x =
      elem(POS_ARTIST_REL).scale.x * elem(POS_FIXED).scale.x;
  elem(POS_SCREENSPACE).scale.y =
      elem(POS_ARTIST_REL).scale.y * elem(POS_FIXED).scale.y;
  // mScreenSpace.scale.x = artistPos.scale.x * fixedPos.scale.x;
  // mScreenSpace.scale.y = artistPos.scale.y * fixedPos.scale.y;

  elem(POS_SCREENSPACE).opacity =
      BLEND_COLORS(elem(POS_ARTIST_REL).opacity, elem(POS_FIXED).opacity);
  // mScreenSpace.alpha = ((artistPos.alpha + 1) * (fixedPos.alpha + 1) - 1) >>
  // 8;
}

void UIControl::initChildren(u32 capacity) { mChildren.create(this, capacity); }

void UIControl::insertChild(u32 index, UIControl* child) {
  mChildren.insert(index, child, mDrawPass);
}

void UIControl::onGroupAttached(ControlGroup* group, u32 draw_pass) {
  mGroup = group;
  mDrawPass = draw_pass;
}

void UIControl::setSfxIds(u32 on_show, u32 on_hide) {
  mOnShowSfxId = on_show;
  mOnHideSfxId = on_hide;
}

const char* UIControl::getTypeName_Public() const { return getTypeName(); }

const char* UIControl::getTypeName() const { return "UIControl"; }

void UIControl::solve_propagate() {
  UIControl* parent = getParent();
  if (parent) {
    elem(POS_ARTIST_REL).trans.x =
        parent->elem(POS_ARTIST_REL).trans.x +
        elem(POS_PROGRAMMER_REL).trans.x * parent->elem(POS_ARTIST_REL).scale.x;
    elem(POS_ARTIST_REL).trans.y =
        parent->elem(POS_ARTIST_REL).trans.y +
        elem(POS_PROGRAMMER_REL).trans.y * parent->elem(POS_ARTIST_REL).scale.y;
    //  artistPos.translate.x =
    //      parent->artistPos.translate.x +
    //      (programmerPos.translate.x * parent->artistPos.scale.x);
    //  artistPos.translate.y =
    //      parent->artistPos.translate.y +
    //      (programmerPos.translate.y * parent->artistPos.scale.y);

    elem(POS_ARTIST_REL).trans.z =
        elem(POS_PROGRAMMER_REL).trans.z + parent->elem(POS_ARTIST_REL).trans.z;
    //  artistPos.translate.z =
    //      programmerPos.translate.z + parent->artistPos.translate.z;

    elem(POS_ARTIST_REL).scale.x =
        elem(POS_PROGRAMMER_REL).scale.x * parent->elem(POS_ARTIST_REL).scale.x;
    elem(POS_ARTIST_REL).scale.y =
        elem(POS_PROGRAMMER_REL).scale.y * parent->elem(POS_ARTIST_REL).scale.y;
    // artistPos.scale.x = programmerPos.scale.x * parent->artistPos.scale.x;
    // artistPos.scale.y = programmerPos.scale.y * parent->artistPos.scale.y;

    elem(POS_ARTIST_REL).opacity = BLEND_COLORS(
        elem(POS_PROGRAMMER_REL).opacity, parent->elem(POS_ARTIST_REL).opacity);
    // artistPos.alpha =
    //     ((programmerPos.alpha + 1) * (grp->mParent->artistPos.alpha + 1) - 1)
    //     >> 8;
  } else {
    elem(POS_ARTIST_REL) = elem(POS_PROGRAMMER_REL);
    // artistPos.translate.x = programmerPos.translate.x;
    // artistPos.translate.y = programmerPos.translate.y;
    // artistPos.translate.z = programmerPos.translate.z;
    // artistPos.scale.x = programmerPos.scale.x;
    // artistPos.scale.y = programmerPos.scale.y;
    // artistPos.alpha = programmerPos.alpha
  }
  parent = getParent();
  if (parent) {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x +
        elem(POS_FIXED).trans.x * parent->elem(POS_ARTIST_REL).scale.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y +
        elem(POS_FIXED).trans.y * parent->elem(POS_ARTIST_REL).scale.y;
    //  mScreenSpace.translate.x =
    //      artistPos.translate.x +
    //      (fixedPos.translate.x * parent->artistPos.scale.x);
    //  mScreenSpace.translate.y =
    //      (artistPos.translate.y +
    //       (fixedPos.translate.y * parent->artistPos.scale.y));
  } else {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x + elem(POS_FIXED).trans.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y + elem(POS_FIXED).trans.y;
    //  mScreenSpace.translate.x = artistPos.translate.x + fixedPos.translate.x;
    //  mScreenSpace.translate.y = artistPos.translate.y + fixedPos.translate.y;
  }

  elem(POS_SCREENSPACE).trans.z =
      elem(POS_ARTIST_REL).trans.z + elem(POS_FIXED).trans.z;
  // mScreenSpace.translate.z = artistPos.translate.z + fixedPos.translate.z;

  elem(POS_SCREENSPACE).scale.x =
      elem(POS_ARTIST_REL).scale.x * elem(POS_FIXED).scale.x;
  elem(POS_SCREENSPACE).scale.y =
      elem(POS_ARTIST_REL).scale.y * elem(POS_FIXED).scale.y;
  // mScreenSpace.scale.x = artistPos.scale.x * fixedPos.scale.x;
  // mScreenSpace.scale.y = artistPos.scale.y * fixedPos.scale.y;

  elem(POS_SCREENSPACE).opacity =
      BLEND_COLORS(elem(POS_ARTIST_REL).opacity, elem(POS_FIXED).opacity);
  // mScreenSpace.alpha = ((artistPos.alpha + 1) * (fixedPos.alpha + 1) - 1) >>
  // 8;

  //
  // Recurse down to children
  //
  mChildren.solve();
}

void UIControl::solve_screenSpace() {
  UIControl* parent = getParent();

  if (parent) {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x +
        elem(POS_FIXED).trans.x * parent->elem(POS_ARTIST_REL).scale.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y +
        elem(POS_FIXED).trans.y * parent->elem(POS_ARTIST_REL).scale.y;
    //  mScreenSpace.translate.x =
    //      artistPos.translate.x +
    //      (fixedPos.translate.x * parent->artistPos.scale.x);
    //  mScreenSpace.translate.y =
    //      (artistPos.translate.y +
    //       (fixedPos.translate.y * parent->artistPos.scale.y));
  } else {
    elem(POS_SCREENSPACE).trans.x =
        elem(POS_ARTIST_REL).trans.x + elem(POS_FIXED).trans.x;
    elem(POS_SCREENSPACE).trans.y =
        elem(POS_ARTIST_REL).trans.y + elem(POS_FIXED).trans.y;
    //  mScreenSpace.translate.x = artistPos.translate.x + fixedPos.translate.x;
    //  mScreenSpace.translate.y = (artistPos.translate.y +
    //      fixedPos.translate.y);
  }

  elem(POS_SCREENSPACE).trans.z =
      elem(POS_ARTIST_REL).trans.z + elem(POS_FIXED).trans.z;
  // mScreenSpace.translate.z = artistPos.translate.z + fixedPos.translate.z;

  elem(POS_SCREENSPACE).scale.x =
      elem(POS_ARTIST_REL).scale.x * elem(POS_FIXED).scale.x;
  elem(POS_SCREENSPACE).scale.y =
      elem(POS_ARTIST_REL).scale.y * elem(POS_FIXED).scale.y;
  // mScreenSpace.scale.x = artistPos.scale.x * fixedPos.scale.x;
  // mScreenSpace.scale.y = artistPos.scale.y * fixedPos.scale.y;

  elem(POS_SCREENSPACE).opacity =
      BLEND_COLORS(elem(POS_ARTIST_REL).opacity, elem(POS_FIXED).opacity);
  // mScreenSpace.alpha = ((artistPos.alpha + 1) * (fixedPos.alpha + 1) - 1) >>
  // 8;
}

#undef BLEND_COLORS

} // namespace UI
