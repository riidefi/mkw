#pragma once

namespace EGG {

class Display;
class Video;
class Heap;

class BaseSystem {
public:
  static BaseSystem* sSystem;

  //! Returns a pointer to the video manager.
  virtual Video* getVideo() = 0; // [vt+0x08]
  virtual Heap* getSysHeap() = 0; // [vt+0x0C]
  virtual Display* getDisplay() = 0; // [vt+0x10]

public:
  unsigned int _04;
  unsigned int _08;
  unsigned int _0c;
  unsigned int _10;
  unsigned int _14;
  Heap * mRootHeapMem1;
  Heap * mRootHeapMem2;
};

} // namespace EGG
