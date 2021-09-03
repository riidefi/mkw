#pragma once

#include <rk_types.h>

namespace UI {

class UIControl;

class ControlGroup {
public:
  ControlGroup();
  ~ControlGroup();

  // After construction, create() must be called once to put the group
  // in a valid state. Calling create() twice is a memory leak.
  void create(UIControl* parent, int size);
  void create(UIControl* parent, UIControl* root, int size);

  void insert(int index, UIControl* control, int pass);
  UIControl* at(int index);
  inline UIControl* operator[](int index) { return at(index); }

  struct Functor {
    virtual void operator()(UIControl* control) = 0;
  };

  // Call a function on every element
  void debug(); // effective no-op
  void init();  // initialize every control

  void calc();              // call each frame
  void draw(int draw_pass); // call each frame

  void solve();                     // solve positioning
  void transform(Functor& functor); // a la std::transform

  UIControl* getParent() { return mParent; }
  UIControl* getRoot() { return mRoot; }

private:
  UIControl** mData;
  UIControl** mDataSorted; // By z_index
  UIControl* mParent;
  UIControl* mRoot;
  s32 mSize;

  inline void create() {
    if (mSize <= 0)
      return;

    mData = new UIControl*[mSize];
    mDataSorted = new UIControl*[mSize];

    for (int i = 0; i < mSize; ++i) {
      mData[i] = nullptr;
      mDataSorted[i] = nullptr;
    }
  }
};

} // namespace UI
