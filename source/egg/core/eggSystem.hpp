#pragma once

namespace EGG {

class Video;

class BaseSystem {
public:
  static BaseSystem* sSystem;

  //! Returns a pointer to the video manager.
  virtual Video* getVideo() = 0; // [vt+0x08]
};

} // namespace EGG
