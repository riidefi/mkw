#pragma once

#include <rk_types.h>

#include <egg/math/eggVector.hpp>
#include <ui/ControlGroup.hpp>
#include <ui/RTTI.hpp>

namespace UI {

// css "position"
enum ElementPosition {
  //! Set by the programmer (css "relative")
  POS_PROGRAMMER_REL,

  //! Set by the layout artist in a .brctr file (css "relative")
  POS_ARTIST_REL,

  //! Propagated down from the root (css "fixed")
  POS_FIXED,

  //! The final position displayed on screen (device coordinates)
  POS_SCREENSPACE,

  //! Number of element positions
  POS_MAX
};

struct Element {
  // css "transform" {
  EGG::Vector3f trans; // css "translate"
  EGG::Vector2f scale; // css "scale"
  // }
  u8 opacity; // css "opacity"

  u8 _[3];

  inline void init() {
    trans.x = 0.0f;
    trans.y = 0.0f;
    trans.z = 0.0f;

    scale.x = 1.0f;
    scale.y = 1.0f;

    opacity = 0xFF;
  }
};

class UIControl {
public:
  UIControl();
  virtual ~UIControl();

  //
  // VFX
  //

  // Draw self + children
  virtual void init();
  virtual void calc();
  virtual void draw(int draw_pass);

protected:
  // Draw self only
  virtual void initSelf();
  virtual void calcSelf();

public:
  void solve(float frame);

  virtual void solveAnim(float& page_anim_x, float frame);

  // Something stripped
  void debug();

  //
  // SFX
  //

  enum PageEventTrigger { EVENT_PAGE_OPEN, EVENT_PAGE_CLOSE };

  void onPageEvent(PageEventTrigger event, u32 page_id);

protected:
  // Special behavior
  virtual void onPageEventSelf(PageEventTrigger event, u32 page_id);

  void setSfxIds(u32 on_show, u32 on_hide);

public:
  //
  // Hierarchy
  //

  void initChildren(u32 capacity);

  void insertChild(u32 index, UIControl* child);

  void onGroupAttached(ControlGroup* group, u32 draw_pass);

  void solve_propagate();
  void solve_screenSpace();

public:
  //
  // RTTI
  //

  const char* getTypeName_Public() const;

protected:
  virtual const TypeInfo& getTypeInfo() const;
  virtual const char* getTypeName() const;

  virtual void vf30();
  virtual void vf34();

  //
  // Positioning
  //

private:
  struct ElementPositionsArray {
    Deferred<Element> data[POS_MAX];

    ElementPositionsArray() {
      for (int i = 0; i < POS_MAX; ++i) {
        data[i].get().init();
      }
    }
  };
  ElementPositionsArray mElementPositions;

public:
  Element& elem(ElementPosition pos) {
    expects(pos < POS_MAX);
    return mElementPositions.data[pos];
  }
  const Element& elem(ElementPosition pos) const {
    expects(pos < POS_MAX);
    return mElementPositions.data[pos];
  }

private:
  ControlGroup* mGroup; // the true "parent" is mGroup->mParent
  ControlGroup mChildren;

public:
  inline ControlGroup* getGroup() { return mGroup; }
  inline UIControl* getParent() { return mGroup->getParent(); }
  inline Page* getPage() { return mGroup->getPage(); }
  inline ControlGroup* getChildren() { return &mChildren; }

  inline f32 getZIndex() const { return mZIndex; }

private:
  f32 mZIndex;

  bool mHidden;
  char _pad0[3];

  u32 mDrawPass;

  bool mAnimated;
  char _pad1[3];

  f32 mAnimStartFrame;

  s32 mOnShowSfxId;
  s32 mOnHideSfxId;
};

} // namespace UI
