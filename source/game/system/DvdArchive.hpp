#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggArchive.hpp>
#include <egg/core/eggHeap.hpp>

// TODO: when DvdRipper is decompiled, replace the function call in load() and remove this line
extern void * DvdRipper_loadToMainRAM(char *path, u8 *dst, EGG::Heap *heap, s32 allocDirection, u32 offset, s32 *param_6, u32 *fileSize);

enum ArchiveState {
    DVD_ARCHIVE_STATE_CLEARED = 0,
    DVD_ARCHIVE_STATE_RIPPED = 2,
    DVD_ARCHIVE_STATE_DECOMPRESSED = 3,
    DVD_ARCHIVE_STATE_MOUNTED = 4
};

class DvdArchive {
public:
    DvdArchive();
    virtual ~DvdArchive();
    virtual void init() = 0;
    void _mount(EGG::Heap *archiveHeap);
    void _UNKNOWN();
    void load(char *path, EGG::Heap *archiveHeap, int decompress, u8 param_4, EGG::Heap *filePath, u32 param_6);
    void decompress(char *path, EGG::Heap *archiveHeap, u32 _unused);
private:
    EGG::Archive *mArchive;
    void *mArchiveStart;
    u32 mArchiveSize;
    EGG::Heap *mArchiveHeap;
    void *mFileStart;
    u32 mFileSize;
    EGG::Heap *mFileHeap;
    volatile ArchiveState mStatus;

    inline void clearArchive() {
        if (!mArchiveStart) return;

        mArchiveHeap->free(mArchiveStart);
        mArchiveStart = nullptr;
        mArchiveSize = NULL;
        mArchiveHeap = nullptr;
        return;
    }
    inline void clearFile() {
        if (!mFileStart) return;

        mFileHeap->free(mFileStart);
        mFileStart = nullptr;
        mFileSize = NULL;
        mFileHeap = nullptr;
        return;
    }
    inline void mount(EGG::Heap *archiveHeap) {
        mArchive = EGG::Archive::mount(mArchiveStart, archiveHeap, 4);
        mStatus = DVD_ARCHIVE_STATE_MOUNTED;
    }
    inline void move() {
        mArchiveStart = mFileStart;
        mArchiveSize = mFileSize;
        mArchiveHeap = mFileHeap;
        mFileStart = 0;
        mFileSize = 0;
        mFileHeap = 0;
        mStatus = DVD_ARCHIVE_STATE_DECOMPRESSED;
    }
    volatile bool isRipped() const { return mStatus == 2; }
};

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80518cc0..0x80518cf4
UNKNOWN_FUNCTION(DvdArchive_ct);
// PAL: 0x80518cf4..0x80518dcc
UNKNOWN_FUNCTION(DvdArchive_dt);
// PAL: 0x80518dcc..0x80518e0c
UNKNOWN_FUNCTION(DvdArchive_mount);
// PAL: 0x80518e0c..0x80518e10
UNKNOWN_FUNCTION(FUN_80518e0c);
// PAL: 0x80518e10..0x80518fa4
UNKNOWN_FUNCTION(load__10DvdArchiveFPcPQ23EGG4HeapiUcPQ23EGG4HeapUl);
// PAL: 0x80518fa4..0x80518fbc
UNKNOWN_FUNCTION(SArchive_load);
// PAL: 0x80518fbc..0x80519040
UNKNOWN_FUNCTION(SArchive_load2);
// PAL: 0x80519040..0x805190e8
UNKNOWN_FUNCTION(unk_80519040);
// PAL: 0x805190e8..0x805190f0
UNKNOWN_FUNCTION(unk_805190e8);
// PAL: 0x805190f0..0x805191a4
UNKNOWN_FUNCTION(SArchive_ripFile);
// PAL: 0x805191a4..0x80519240
UNKNOWN_FUNCTION(unk_805191a4);
// PAL: 0x80519240..0x805192cc
UNKNOWN_FUNCTION(SArchive_destroyBuffers);
// PAL: 0x805192cc..0x80519370
UNKNOWN_FUNCTION(DvdArchive_unmount);
// PAL: 0x80519370..0x805193c8
UNKNOWN_FUNCTION(unk_80519370);
// PAL: 0x805193c8..0x80519420
UNKNOWN_FUNCTION(unk_805193c8);
// PAL: 0x80519420..0x80519508
UNKNOWN_FUNCTION(unk_80519420);
// PAL: 0x80519508..0x805195a4
UNKNOWN_FUNCTION(decompress__10DvdArchiveFPcPQ23EGG4HeapUl);
// PAL: 0x805195a4..0x805195d8
UNKNOWN_FUNCTION(unk_805195a4);
// PAL: 0x805195d8..0x80519670
UNKNOWN_FUNCTION(SArchive_loadOther);

#ifdef __cplusplus
}
#endif
