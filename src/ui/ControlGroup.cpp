#include "ControlGroup.hpp"
#include "UIControl.hpp"

namespace UI {

ControlGroup::ControlGroup()
    : mData(nullptr), mDataSorted(nullptr), mParent(nullptr), mPage(nullptr),
      mSize(0) {}

ControlGroup::~ControlGroup() {
  delete[] mDataSorted;
  delete[] mData;
}

void ControlGroup::create(UIControl* parent, int capacity) {
  mParent = parent;
  mPage = parent->getPage();
  mSize = capacity;

  if (capacity <= 0) {
    return;
  }

  mData = new UIControl*[capacity];
  mDataSorted = new UIControl*[capacity];

  for (int i = 0; i < capacity; ++i) {
    mData[i] = nullptr;
    mDataSorted[i] = nullptr;
  }
}

void ControlGroup::create(Page* page, int capacity) {
  mParent = nullptr;
  mPage = page;
  mSize = capacity;

  if (capacity <= 0) {
    return;
  }

  mData = new UIControl*[capacity];
  mDataSorted = new UIControl*[capacity];

  for (int i = 0; i < capacity; ++i) {
    mData[i] = nullptr;
    mDataSorted[i] = nullptr;
  }
}

void ControlGroup::insert(int index, UIControl* control, int pass) {
  mData[index] = control;
  mDataSorted[index] = control;
  control->onGroupAttached(this, pass);
}

void ControlGroup::debug() {
  for (int i = 0; i < mSize; ++i) {
    mData[i]->debug();
  }
}

void ControlGroup::init() {
  for (int i = 0; i < mSize; ++i) {
    mData[i]->init();
  }
}
void ControlGroup::calc() {
  for (int i = 0; i < mSize; ++i) {
    mData[i]->calc();
  }
}

void ControlGroup::draw(int draw_pass) {
  UIControl* c0;
  for (int i = 0; i < mSize - 1; ++i) {
    c0 = mDataSorted[i];
    s32 minIdx = i;
    f32 minZIndex = mDataSorted[i]->getZIndex();

    int j;
    for (j = i + 1; j < mSize; ++j) {
      if (mDataSorted[j]->getZIndex() < minZIndex) {
        minIdx = j;
        minZIndex = mDataSorted[j]->getZIndex();
      }
    }

    if (minIdx != i) {
      mDataSorted[i] = mDataSorted[minIdx];
      mDataSorted[minIdx] = c0;
    }
  }

  for (int i = 0; i < mSize; ++i) {
    mDataSorted[i]->draw(draw_pass);
  }
}

void ControlGroup::solve() {
  for (int i = 0; i < mSize; ++i) {
    mData[i]->solve_propagate();
  }
}

UIControl* ControlGroup::at(int index) { return mData[index]; }

void ControlGroup::transform(ControlGroup::Functor& functor) {
  for (int i = 0; i < mSize; ++i) {
    functor(mData[i]);
    mData[i]->getChildren()->transform(functor);
  }
}

} // namespace UI
