#include "KartSettings.hpp"

extern "C" {
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);// Extern data references.
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
}

namespace Kart {
// Symbol: __ct__Q24Kart12KartSettingsFv
// PAL: 0x80592fc0..0x8059308c
MARK_BINARY_BLOB(__ct__Q24Kart12KartSettingsFv, 0x80592fc0, 0x8059308c);
asm KartSettings::KartSettings() {
  #include "asm/80592fc0.s"
}
}
