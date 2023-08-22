#pragma once

#include <rk_types.h>

#include <decomp.h>

// Source:
// https://github.com/doldecomp/ogws/blob/master/include/egg/core/eggXfbManager.h

namespace EGG {
class Heap;
class Xfb;
class XfbManager {
public:
  inline XfbManager(Heap* heap)
    : mListHead(nullptr), mListTail(nullptr),
      mCopiedXfb(nullptr), mShowXfb(nullptr) {}
  ~XfbManager() {}

  bool isReadytoCopy() const {
    return mListTail != mShowXfb && mListTail != mListHead;
  }

  bool attach(Xfb*);
  void copyEFB(bool);
  void setNextFrameBuffer();
  void postVRetrace();

private:
  Xfb* mListHead;  // at 0x0
  Xfb* mListTail;  // at 0x4
  Xfb* mCopiedXfb; // at 0x8
  Xfb* mShowXfb;   // at 0xC
};
} // namespace EGG

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80244200..0x80244268
UNKNOWN_FUNCTION(attach__Q23EGG10XfbManagerFPQ23EGG3Xfb);
// PAL: 0x80244268..0x802442e8
UNKNOWN_FUNCTION(copyEFB__Q23EGG10XfbManagerFb);
// PAL: 0x802442e8..0x80244350
UNKNOWN_FUNCTION(setNextFrameBuffer__Q23EGG10XfbManagerFv);
// PAL: 0x80244350..0x802443ac
UNKNOWN_FUNCTION(postVRetrace__Q23EGG10XfbManagerFv);

#ifdef __cplusplus
}
#endif
