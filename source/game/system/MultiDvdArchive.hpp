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
UNKNOWN_FUNCTION(MultiDvdArchive_ct);
// PAL: 0x8052a648..0x8052a6dc
UNKNOWN_FUNCTION(init__Q26System15MultiDvdArchiveFv);
// PAL: 0x8052a6dc..0x8052a760
UNKNOWN_FUNCTION(MultiDvdArchive_dt);
// PAL: 0x8052a760..0x8052a800
UNKNOWN_FUNCTION(MultiDvdArchive_getFile);
// PAL: 0x8052a800..0x8052a864
UNKNOWN_FUNCTION(unk_8052a800);
// PAL: 0x8052a864..0x8052a954
UNKNOWN_FUNCTION(MultiDvdArchive_exists);
// PAL: 0x8052a954..0x8052aa88
UNKNOWN_FUNCTION(MultiDvdArchive_load);
// PAL: 0x8052aa88..0x8052aae8
UNKNOWN_FUNCTION(unk_8052aa88);
// PAL: 0x8052aae8..0x8052ab6c
UNKNOWN_FUNCTION(unk_8052aae8);
// PAL: 0x8052ab6c..0x8052ac40
UNKNOWN_FUNCTION(unk_8052ab6c);
// PAL: 0x8052ac40..0x8052aca0
UNKNOWN_FUNCTION(unk_8052ac40);
// PAL: 0x8052aca0..0x8052ad08
UNKNOWN_FUNCTION(unk_8052aca0);
// PAL: 0x8052ad08..0x8052ad80
UNKNOWN_FUNCTION(unk_8052ad08);
// PAL: 0x8052ad80..0x8052ae08
UNKNOWN_FUNCTION(unk_8052ad80);
// PAL: 0x8052ae08..0x8052ae5c
UNKNOWN_FUNCTION(unk_8052ae08);

#ifdef __cplusplus
}
#endif

#include "DvdArchive.hpp"

namespace System {

class MultiDvdArchive {
public:
    MultiDvdArchive();
    void init();
    virtual ~MultiDvdArchive();
private:
    DvdArchive *archives;
    u16 archiveCount;
    u8 _0a[0x10 - 0x0a];
    char **suffixes;
    u8 _14[0x18 - 0x14];
    u32 *kinds;
    void init(const char *);
};

}
