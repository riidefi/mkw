#pragma once

#include <stdbool.h>  // bool
#include <rk_types.h> // expects

void OSPanic(...);
void OSReport(...);

struct rxNode {
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
#define rxNodeIsFolder(node) ((node).packed_type_name & 0xff000000)
// In some cases (X << 8 >> 8) does not collapse to a mask.
#define rxNodeGetName(node) ((node).packed_type_name & 0x00ffffff)

struct rxArchiveHeader {
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

typedef struct rxNode rxNode;
typedef struct rxArchiveHeader rxArchiveHeader;

enum { RX_ARCHIVE_FILE_MAGIC = 0x55aa382d };

static bool rxArchiveHeaderVerify(const rxArchiveHeader* self) {
  // Verify the "U8" magic
  if (self->magic != RX_ARCHIVE_FILE_MAGIC)
    return false;

  return true;
}
static const rxNode* rxArchiveHeaderGetNodes(const rxArchiveHeader* self) {
  expects(self->nodes.offset > sizeof(rxArchiveHeader));
  return (const rxNode*)((u8*)self + self->nodes.offset);
}
static const u8* rxArchiveHeaderGetFileData(const rxArchiveHeader* self) {
  expects(self->files.offset > sizeof(rxArchiveHeader));
  return (const u8*)((u8*)self + self->files.offset);
}

#define ARCHIVE_THROW_INVALID_HEADER()                                         \
  OSPanic("arc.c", 74, "ARCInitHandle: bad archive format")
#define ARCHIVE_LOG_FILE_NOT_FOUND(file, root)                                 \
  OSReport("Warning: ARCOpen(): file '%s' was not found under %s in the "      \
           "archive.\n",                                                       \
           file, root)
