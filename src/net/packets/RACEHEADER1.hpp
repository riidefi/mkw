#pragma once

#include <rk_types.h>

namespace Net {

struct RACEHEADER1Packet {
  u8 _00[0x28 - 0x00];
};
static_assert(sizeof(RACEHEADER1Packet) == 0x28);

class RACEHEADER1Handler {
public: 
  static RACEHEADER1Handler *getInstance() {
    return spInstance;
  }

  void setPrepared();

  void reset();

private:
  bool m_prepared;
  u8 _004[0x260 - 0x001];

  static RACEHEADER1Handler *spInstance;
};
static_assert(sizeof(RACEHEADER1Handler) == 0x260);

}
