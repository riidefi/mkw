#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct rvlDvdFile {
  char _[0x3c];
};

unk32 DVDOpen(const char*, rvlDvdFile*);
u32 DVDReadPrio(rvlDvdFile*, void*, u32, unk32, unk32);
unk32 DVDClose(rvlDvdFile*);

#ifdef __cplusplus
}
#endif