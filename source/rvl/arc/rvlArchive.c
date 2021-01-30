#include "rvlArchive.h"
#include "binary_format.h" // rvlArchiveHeader
#include <ctype.h>         // tolower

bool __rvlGetCurrentPath(rvlArchive* self, char* string, u32 capacity);

// pData must be nonconst
bool ARCInitHandle(void* pData, rvlArchive* pOut) {
  expects(pData != nullptr && pOut != nullptr);

  const rvlArchiveHeader* pHeader = (rvlArchiveHeader*)pData;
  if (!rvlArchiveHeaderVerify(pHeader))
    ARCHIVE_THROW_INVALID_HEADER();

  pOut->mHeader = pData;

  const rvlArchiveNode* nodes = rvlArchiveHeaderGetNodes(pHeader);
  pOut->mNodes = nodes;

  pOut->mFileData = rvlArchiveHeaderGetFileData(pHeader);
  // The right bound of the root node is the number of nodes
  pOut->mCount = nodes[0].folder.sibling_next;
  // Strings exist directly after the last node.
  pOut->mStrings = (const char*)(nodes + pOut->mCount);
  pOut->mFstSize = (u32)pHeader->nodes.size;
  pOut->mCurrentPath = 0;

  return true;
}

int ARCOpen(const rvlArchive* self, const char* path, rvlArchiveFile* pOut) {
  expects(self != nullptr && path != nullptr && pOut != nullptr);

  const rvlArchiveNode* nodes = self->mNodes;
  const s32 resolved = ARCConvertPathToEntrynum((rvlArchive*)self, path);

  if (!rvlArchiveEntryHandleIsValid(resolved)) {
    char current_path[128];

    __rvlGetCurrentPath((rvlArchive*)self, current_path, sizeof(current_path));
    ARCHIVE_LOG_FILE_NOT_FOUND(path, current_path);

    return false;
  }

  if (!rvlArchiveEntryHandleIsValid(resolved) ||
      rvlArchiveNodeIsFolder(nodes[resolved])) {
    return false;
  }

  pOut->parent = (rvlArchive*)self;
  pOut->offset = nodes[resolved].file.offset;
  pOut->size = nodes[resolved].file.size;
  return true;
}

int ARCFastOpen(const rvlArchive* self, s32 resolved, rvlArchiveFile* pOut) {
  expects(self != nullptr && pOut != nullptr);

  const rvlArchiveNode* nodes = self->mNodes;

  // Although resolve will never return a handle beyond the node count,
  // the user may, so an additional check is needed.
  if (!rvlArchiveEntryHandleIsValid(resolved) || resolved >= self->mCount ||
      rvlArchiveNodeIsFolder(nodes[resolved])) {
    return false;
  }

  pOut->parent = (rvlArchive*)self;
  pOut->offset = nodes[resolved].file.offset;
  pOut->size = nodes[resolved].file.size;

  return true;
}

// seen in debug builds as a standalone function
inline int __rvlPathCompare(const char* lhs, const char* rhs) {
  while (rhs[0] != '\0') {
    if (tolower(*lhs++) != tolower(*rhs++))
      return false;
  }

  if (lhs[0] == '/' || lhs[0] == '\0')
    return true;

  return false;
}

inline u32 __rvlPathCopy(char* dst, char* src, u32 capacity) {
  u32 i;
  for (i = capacity; i != 0 && src[0] != '\0'; --i)
    *dst++ = *src++;

  return capacity - i;
}

s32 ARCConvertPathToEntrynum(rvlArchive* self, const char* path) {
  s32 name_length;                                       // r7
  u32 it = self->mCurrentPath;                           // r8
  rvlArchiveNode* nodes = (rvlArchiveNode*)self->mNodes; // r9

  while (true) {
    // End of string -> return what we have
    if (path[0] == '\0')
      return it;

    // Ignore initial slash: /Path/File vs Path/File
    if (path[0] == '/') {
      it = 0;
      ++path;
      continue;
    }

    // Handle special cases:
    // -../-, -.., -./-, -.
    if (path[0] == '.') {
      if (path[1] == '.') {
        // Seek to parent ../
        if (path[2] == '/') {
          it = nodes[it].folder.parent;
          path += 3;
          continue;
        }
        // Return parent folder immediately
        if (path[2] == '\0')
          return nodes[it].folder.parent;
        // Malformed: fall through, causing infinite loop
        goto compare;
      }

      // "." directory does nothing
      if (path[1] == '/') {
        path += 2;
        continue;
      }

      // Ignore trailing dot
      if (path[1] == '\0')
        return it;
    }

  compare:
    // We've ensured the directory is not special.
    // Isolate the name of the current item in the path string.
    const char* name_end = path;
    while (name_end[0] != '\0' && name_end[0] != '/')
      ++name_end;

    // If the name was delimited by a '/' rather than truncated.
    // This must be expressed as a ternary, and an enum cannot be used..
    int name_delimited_by_slash = (name_end[0] != '\0') ? 1 : 0;
    name_length = name_end - path;

    // Traverse all children of the parent.
    const u32 anchor = it;
    ++it;
    while (it < nodes[anchor].folder.sibling_next) {
      while (true) {
        if (rvlArchiveNodeIsFolder(nodes[it]) ||
            name_delimited_by_slash != true) {
          char* name_of_it =
              ((char*)self->mStrings) + rvlArchiveNodeGetName(nodes[it]);

          // Skip empty directories
          if (name_of_it[0] == '.' && name_of_it[1] == '\0') {
            ++it;
            continue;
          }

          // Advance to the next item in the path
          if (__rvlPathCompare(path, name_of_it) == true) {
            goto descend;
          }
        }

        if (rvlArchiveNodeIsFolder(nodes[it])) {
          it = nodes[it].folder.sibling_next;
          break;
        }

        ++it;
        break;
      }
    }

    return -1;

  descend:
    // If the path was truncated, there is nowhere else to go
    // These basic blocks have to go here right at the end, accessed via a goto.
    // An odd choice.
    if (!name_delimited_by_slash)
      return it;

    path += name_length + 1;
  }
}

static u32 __rvlMakePathRecursive(rvlArchive* self, u32 resolved, char* string,
                                  u32 capacity) {
  rvlArchiveNode* nodes = (rvlArchiveNode*)self->mNodes;

  if (resolved == 0)
    return 0;

  char* name = ((char*)self->mStrings) + nodes[resolved].name;

  u32 written = __rvlMakePathRecursive(self, nodes[resolved].folder.parent,
                                       string, capacity);

  if (written == capacity)
    return written;

  string[written++] = '/';
  return written + __rvlPathCopy(string + written, name, capacity - written);
}

inline bool __rvlMakePath(rvlArchive* self, s32 resolved, char* string,
                          u32 capacity) {
  rvlArchiveNode* nodes = (rvlArchiveNode*)self->mNodes;

  u32 written = __rvlMakePathRecursive(self, resolved, string, capacity);
  if (written == capacity) {
    string[capacity - 1] = '\0';
    return false;
  }

  if (rvlArchiveNodeIsFolder(nodes[resolved])) {
    if (written == capacity - 1) {
      string[written] = '\0';
      return false;
    }

    string[written++] = '/';
  }

  string[written] = '\0';
  return true;
}

inline bool __rvlGetCurrentPath(rvlArchive* self, char* string, u32 capacity) {
  return __rvlMakePath(self, self->mCurrentPath, string, capacity);
}

void* ARCGetStartAddrInMem(rvlArchiveFile* self) {
  return (char*)(self->parent->mHeader) + self->offset;
}

s32 ARCGetStartOffset(const rvlArchiveFile* self) { return self->offset; }

u32 ARCGetLength(const rvlArchiveFile* self) { return self->size; }

bool ARCClose(rvlArchiveFile* self) { return true; }

bool ARCChangeDir(rvlArchive* self, const char* path) {
  const s32 resolved = ARCConvertPathToEntrynum((rvlArchive*)self, path);
  rvlArchiveNode* nodes = (rvlArchiveNode*)self->mNodes;

  if (!rvlArchiveEntryHandleIsValid(resolved) ||
      !rvlArchiveNodeIsFolder(nodes[resolved]))
    return false;

  self->mCurrentPath = resolved;
  return true;
}

bool ARCOpenDir(const rvlArchive* self, const char* path,
                rvlArchiveFolderRange* pOut) {
  const s32 resolved = ARCConvertPathToEntrynum((rvlArchive*)self, path);
  const rvlArchiveNode* nodes = self->mNodes;

  if (resolved < 0 || (nodes[resolved].packed_type_name & 0xff000000) == 0)
    return false;

  pOut->parent = (rvlArchive*)self;
  pOut->path_begin = resolved;
  pOut->path_it = resolved + 1;
  pOut->path_end = nodes[resolved].folder.sibling_next;
  return true;
}

bool ARCReadDir(rvlArchiveFolderRange* self, rvlArchiveEntry* pOut) {
  expects(self->parent != nullptr);

  u32 it;                // regalloc fun!
  rvlArchiveNode* nodes; // this must not be const lest regalloc change and the
                         // function grow in size

  rvlArchive* arc = self->parent;
  nodes = (rvlArchiveNode*)arc->mNodes;

  it = self->path_it;

  // while (A) produces a nop
  while (true) {
    if (it <= self->path_begin || self->path_end <= it)
      return false;

    pOut->parent = arc;
    pOut->path = it;
    // All non-file entries are folders.
    // Collapse to one specific value.
    pOut->node_type = rvlArchiveNodeIsFolder(nodes[it]) //
                          ? RVL_ARCHIVE_FOLDER
                          : RVL_ARCHIVE_FILE;
    pOut->name = arc->mStrings + nodes[it].name;

    // skip '.' directories
    if (pOut->name[0] == '.' && pOut->name[1] == '\0') {
      ++it;
      continue;
    }

    self->path_it = rvlArchiveNodeIsFolder(nodes[it]) //
                        ? nodes[it].folder.sibling_next
                        : it + 1;
    return true;
  }
}

bool ARCCloseDir(rvlArchiveFolderRange* self) { return true; }
