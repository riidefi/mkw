#pragma once

namespace EGG {

class Video;
class Heap;

class BaseSystem {
public:
  static BaseSystem* sSystem;

  //! Returns a pointer to the video manager.
  virtual Video* getVideo() = 0; // [vt+0x08]

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
