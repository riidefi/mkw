#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_DvdSoundArchive.h
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <rk_types.h>
#include <decomp.h>

#include <rvl/dvd/dvd.h>

#include "snd_sndArchive.hpp"
#include "snd_soundArchiveFile.hpp"
namespace nw4r {
namespace snd {

class DvdSoundArchive : SoundArchive {
public:
  // PAL: 0x80090fc0..0x80091010
  DvdSoundArchive();
  // PAL: 0x80091010..0x80091090
  virtual ~DvdSoundArchive();

  // PAL: 0x80091090..0x800911d0
  bool Open(const char* path);
  // PAL: 0x800911d0..0x80091210
  void Close();

  // PAL: 0x80091650..0x80091658
  virtual const void* detail_GetFileAddress(u32) const;
  // PAL: 0x80091640..0x80091648
  virtual const void* detail_GetWaveDataFileAddress(u32) const;

  // PAL: 0x80091380..0x80091390
  virtual int detail_GetRequiredStreamBufferSize() const;
  // PAL: 0x80091390..0x80091420
  bool LoadHeader(void* buf, u32 size);

  // PAL: 0x80091210..0x800912c0
  virtual void* OpenStream(void* buf, int size, u32 offset, u32 limit) const;
  // PAL: 0x800912c0..0x80091380
  virtual void* OpenExtStream(void* buf, int size, const char* path, u32 offset,
                              u32 limit) const;

private:
  detail::SoundArchiveFileReader mFileReader;
  DVDFileInfo mFileInfo; // 0x14c
  bool mOpenFlag;        // 0x188
};

} // namespace snd
} // namespace nw4r
