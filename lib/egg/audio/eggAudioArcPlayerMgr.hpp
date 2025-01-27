#pragma once

#include <decomp.h>
#include <rk_types.h>

#include <nw4r/snd/snd_soundHeap.hpp>

namespace EGG {
class ArcPlayer {
public:
  // PAL: 0x80210590..0x80210624
  // ArcPlayer(void*); // ICE
  void ct(nw4r::snd::SoundHeap* heap);
  // PAL: 0x80210624..0x80210698
  ~ArcPlayer();

  // PAL: 0x80210698..0x80210fd4
  void setSteamBlocks(u32 blocks);
  // PAL: 0x80210fd4..0x80210fec
  void calc();
  // PAL: 0x80210fec..0x80211058
  void stopAllSound();
};

} // namespace EGG
