#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8052a098..0x8052a1c8
UNKNOWN_FUNCTION(MultiDvdArchive_create);
// PAL: 0x8052a1c8..0x8052a21c
UNKNOWN_FUNCTION(unk_8052a1c8);
// PAL: 0x8052a21c..0x8052a2a8
UNKNOWN_FUNCTION(CourseMultiDvdArchive_init);
// PAL: 0x8052a2a8..0x8052a2fc
UNKNOWN_FUNCTION(unk_8052a2a8);
// PAL: 0x8052a2fc..0x8052a36c
UNKNOWN_FUNCTION(unk_8052a2fc);
// PAL: 0x8052a36c..0x8052a3c0
UNKNOWN_FUNCTION(unk_8052a36c);
// PAL: 0x8052a3c0..0x8052a430
UNKNOWN_FUNCTION(unk_8052a3c0);
// PAL: 0x8052a430..0x8052a488
UNKNOWN_FUNCTION(unk_8052a430);
// PAL: 0x8052a488..0x8052a4e0
UNKNOWN_FUNCTION(unk_8052a488);
// PAL: 0x8052a4e0..0x8052a538
UNKNOWN_FUNCTION(unk_8052a4e0);
// PAL: 0x8052a538..0x8052a648
UNKNOWN_FUNCTION(__ct__Q26System15MultiDvdArchiveFUs);
// PAL: 0x8052a648..0x8052a6dc
UNKNOWN_FUNCTION(init__Q26System15MultiDvdArchiveFv);
// PAL: 0x8052a6dc..0x8052a760
UNKNOWN_FUNCTION(__dt__Q26System15MultiDvdArchiveFv);

#ifdef __cplusplus
}
#endif

#include "DvdArchive.hpp"

#include "rvl/dvd/dvd.h"

namespace System {

class MultiDvdArchive {
public:
    MultiDvdArchive(u16 archiveCount);
    void clear();
    bool exists(const char* name);
    void* getFile(const char* filename, size_t* size);
    void unmount();
    void rip(const char* name, EGG::Heap* heap);
    void load(const char *filename, EGG::Heap *param_3, EGG::Heap *heap, unk32 param_5);
    void loadOther(MultiDvdArchive* other, EGG::Heap* heap);
    bool isLoaded();
    void* getEarliestResBufInMem();
    void* getFarthestResBufInMem();
    int totalArchiveSize();
    u16 rippedArchiveCount();
    void init();
    virtual ~MultiDvdArchive();
private:
    DvdArchive *archives;
    u16 archiveCount;
    u32* fileSizes;
    char **suffixes;
    void** fileStarts;
    u32 *kinds;
};

}
