#pragma once

#include "system/ResourceManager.hpp"

#include <rk_types.h>

namespace Net {

struct RACEHEADER1Packet {
  u8 _00[0x28 - 0x00];
};
static_assert(sizeof(RACEHEADER1Packet) == 0x28);

struct RACEHEADER1Data {
  u32 _00;
  u8 _04[0x14 - 0x04];
  // This can take on values outside of the current courseId enum, maybe they're different types? 
  System::CourseId courseId;
  u8 _18[0x20 - 0x18];
  u8 playerIdToAidMapping[12];
  u8 _2c[0x30 - 0x2c];
};
static_assert(sizeof(RACEHEADER1Data) == 0x30);

class RACEHEADER1Handler {
public: 
  void setPrepared();

  void reset();

  bool courseValid() const;

  inline s32 getCourseId() const;

  const u8 *getPlayerIdToAidMapping() const;

  static RACEHEADER1Handler *getInstance() {
    return spInstance;
  }
private:
  bool m_prepared;
  u8 _001[0x008 - 0x001];
  u32 m_unk8;
  u8 _00c[0x020 - 0x00c]; 
  RACEHEADER1Data m_RH1Datas[12];

  static RACEHEADER1Handler *spInstance;
};
static_assert(sizeof(RACEHEADER1Handler) == 0x260);

}
