#pragma once

#include <rk_types.h> // expects
#include <stdbool.h>  // bool

#include <rvl/os/osError.h>

struct rvlArchiveNode {
  union {
    struct {
      u32 is_folder : 8;
      u32 name : 24;
    };
    u32 packed_type_name;
  };
  union {
    struct {
      u32 offset;
      u32 size;
    } file;
    struct {
      u32 parent;
      u32 sibling_next;
    } folder;
  };
};

// Bitfield access of a packed_type_name X produces a pattern (X >> 24), which
// does not match access done by masking.
#define rvlArchiveNodeIsFolder(node) ((node).packed_type_name & 0xff000000)
// In some cases (X << 8 >> 8) does not collapse to a mask.
#define rvlArchiveNodeGetName(node) ((node).packed_type_name & 0x00ffffff)

struct rvlArchiveHeader {
  u32 magic; // 00
  struct {
    s32 offset; // 04
    s32 size;   // 08
  } nodes;
  struct {
    s32 offset; // 0C
  } files;

  u8 _10[0x10];
};

typedef struct rvlArchiveNode rvlArchiveNode;
typedef struct rvlArchiveHeader rvlArchiveHeader;

enum { RVL_ARCHIVE_FILE_MAGIC = 0x55aa382d };

static inline bool rvlArchiveHeaderVerify(const rvlArchiveHeader* self) {
  // Verify the "U8" magic
  if (self->magic != RVL_ARCHIVE_FILE_MAGIC)
    return false;

  return true;
}
static inline const rvlArchiveNode*
rvlArchiveHeaderGetNodes(const rvlArchiveHeader* self) {
  expects(self->nodes.offset > sizeof(rvlArchiveHeader));
  return (const rvlArchiveNode*)((u8*)self + self->nodes.offset);
}
static inline const u8*
rvlArchiveHeaderGetFileData(const rvlArchiveHeader* self) {
  expects(self->files.offset > sizeof(rvlArchiveHeader));
  return (const u8*)((u8*)self + self->files.offset);
}

#define ARCHIVE_THROW_INVALID_HEADER()                                         \
  OSPanic("arc.c", 74, "ARCInitHandle: bad archive format")
#define ARCHIVE_LOG_FILE_NOT_FOUND(file, root)                                 \
  OSReport("Warning: ARCOpen(): file '%s' was not found under %s in the "      \
           "archive.\n",                                                       \
           file, root)
