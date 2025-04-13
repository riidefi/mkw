#include <rvl/dvd/dvdFs.h>

#include "snd_dvdSoundArchive.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/snd/snd_DvdSoundArchive.cpp
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <string.h>

// Extern function references.
extern "C" {
// PAL: 0x8009de90
extern UNKNOWN_FUNCTION(unk_8009de90);
// PAL: 0x8009e610
extern UNKNOWN_FUNCTION(unk_8009e610);
// PAL: 0x8009e690
extern UNKNOWN_FUNCTION(unk_8009e690);
// PAL: 0x8009e6c0
extern UNKNOWN_FUNCTION(SoundArchiveFileReader_Init);
// PAL: 0x8009e770
extern UNKNOWN_FUNCTION(unk_8009e770);
// PAL: 0x8009e820
extern UNKNOWN_FUNCTION(unk_8009e820);
// PAL: 0x800b05e0
extern UNKNOWN_FUNCTION(Seek__Q34nw4r2ut13DvdFileStreamFlUl);
// PAL: 0x800b06b0
extern UNKNOWN_FUNCTION(__ct__Q34nw4r2ut19DvdLockedFileStreamFl);
// PAL: 0x800b0740
extern UNKNOWN_FUNCTION(__ct__Q34nw4r2ut19DvdLockedFileStreamFPC11DVDFileInfob);
// PAL: 0x800b07d0
extern UNKNOWN_FUNCTION(unk_800b07d0);
// PAL: 0x800b0870
extern UNKNOWN_FUNCTION(unk_800b0870);
}

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
