#include <rvl/dvd/dvdFs.h>

#include "snd_dvdSoundArchive.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/snd/snd_DvdSoundArchive.cpp
// Credit: kiwi515
// Credit: GibHaltmannKill
// TODO Symbol names are best guesses.

namespace nw4r {
namespace snd {

// Symbol: __ct__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80090fc0..0x80091010
DvdSoundArchive::DvdSoundArchive() : mOpenFlag(false) {}

// Symbol: __dt__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80091010..0x80091090
DvdSoundArchive::~DvdSoundArchive() { Close(); }

// bool DvdSoundArchive::Open(const char* path)

// Symbol: Close__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x800911d0..0x80091210
void DvdSoundArchive::Close() {
  DVDClose(&mFileInfo);
  mOpenFlag = false;
  SoundArchive::Shutdown();
}

// void* DvdSoundArchive::OpenStream(void* buf, int size, u32 offset, u32 limit) const 


// void* DvdSoundArchive::OpenExtStream(void* buf, int size, const char* path, u32 offset, u32 limit) const

// Symbol: detail_GetRequiredStreamBufferSize__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80091380..0x80091390
int DvdSoundArchive::detail_GetRequiredStreamBufferSize() const { return 0x78; }

// bool DvdSoundArchive::LoadHeader(void* buf, u32 size)

} // namespace snd
} // namespace nw4r
