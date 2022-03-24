#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_SoundArchiveFile.h
// Credit: GibHaltmannKill

#include <rk_types.h>
#include <decomp.h>

namespace nw4r {
namespace snd {
namespace detail {

class SoundArchiveFileReader {

public:
  SoundArchiveFileReader();

private:
  char _unk00[40];
  void* _unk28;
  void* _unk2c;
  void* _unk30;
  void* _unk34;
  void* _unk38;
  void* _unk3c;
  void* _unk40;
};

} // namespace detail
} // namespace snd
} // namespace nw4r
