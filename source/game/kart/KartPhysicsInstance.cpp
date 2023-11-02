
#include "KartPhysicsInstance.hpp"

#include "decomp.h"

namespace Kart {
void destroyPhysicsInstance(f32 idk) {
  _808b6a08 = idk;
  gKartPhysics = nullptr;
  _809c1994 = 0;
}
}

extern "C" {
extern u8 gKartPhysics__4Kart;
extern UNKNOWN_FUNCTION(setBspParams__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3fbf);
extern UNKNOWN_FUNCTION(__nw__FUl);
}

// Symbol: unk_805a04a0
// PAL: 0x805a04a0..0x805a0550
MARK_BINARY_BLOB(unk_805a04a0, 0x805a04a0, 0x805a0550);
asm UNKNOWN_FUNCTION(unk_805a04a0) {
  #include "asm/805a04a0.s"
}
