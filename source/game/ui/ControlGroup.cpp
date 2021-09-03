#include "ControlGroup.hpp"
#include "UIControl.hpp"

namespace UI {

ControlGroup::ControlGroup()
    : mData(nullptr), mDataSorted(nullptr), mParent(nullptr), mRoot(nullptr),
      mSize(0) {}

ControlGroup::~ControlGroup() {
  delete[] mDataSorted;
  delete[] mData;
}

void ControlGroup::create(UIControl* parent, int capacity) {
  mParent = parent;
  mRoot = parent->getRoot();
  mSize = capacity;

  create();
}

void ControlGroup::create(UIControl* parent, UIControl* root, int capacity) {
  mParent = parent;
  mRoot = root;
  mSize = capacity;

  create();
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
  for (int i = 0; i < mSize - 1; ++i) {
    UIControl* key = mDataSorted[i];

    int j = i;
    for (; j > 0 && mDataSorted[j - 1]->getZIndex() > key->getZIndex(); --j) {
      mDataSorted[j] = mDataSorted[j - 1];
    }
    mDataSorted[j] = key;
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
