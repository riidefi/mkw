#include "lyt_init.hpp"

#include <rvl/os/os.h>

namespace nw4r {
namespace lyt {

static const char* VERSION =
    "<< NW4R    - LYT 	final   build: Mar  8 2008 20:59:41 (0x4201_127) >>";

void LytInit() {
  OSRegisterVersion(VERSION);
  OSInitFastCast();
}

} // namespace lyt
} // namespace nw4r
