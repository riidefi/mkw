#include "lyt_init.hpp"

#include <rvl/os/os.h>

namespace nw4r {
namespace lyt {

static const char* NW4R_LYT_VERSION_STRING =
    "<< NW4R    - LYT 	final   build: Mar  8 2008 20:59:41 (0x4201_127) >>";

void LytInit() {
  OSRegisterVersion(NW4R_LYT_VERSION_STRING);
  OSInitFastCast();
}

} // namespace lyt
} // namespace nw4r
