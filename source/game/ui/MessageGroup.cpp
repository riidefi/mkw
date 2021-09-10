#pragma once

#include "MessageGroup.hpp"

#include <stdio.h>

namespace UI {

MessageGroup::MessageGroup() : mHeader(nullptr), mInf(nullptr), mDat(nullptr), mStr(nullptr), mMid(nullptr) {}

MessageGroup::~MessageGroup() {}

extern "C" const void* ResourceManager_getFile(void*, u32, const char*, u32*);
extern void* sResourceManager;

void MessageGroup::load(const char* filename) {
  char path[0x60];
  snprintf(path, sizeof(path) - 1, "message/%s.bmg\0", filename);
  path[sizeof(path) - 1] = '\0'; // Redundant

  const void* file = ResourceManager_getFile(sResourceManager, 2, path, nullptr);

  load(file);
}

void MessageGroup::load(const void* file) {
  mHeader = (const Header*)file;

  const Block* block = (const Block*)((const u8*)file + 0x20);
  for (u32 i = 0; i < mHeader->numBlocks; i++) {
    const u8* blockData = block->data;

    switch (block->kind) {
    case BLOCK_KIND_INF:
      mInf = (const Inf*)blockData;
      break;
    case BLOCK_KIND_DAT:
      mDat = (const wchar_t*)blockData;
      break;
    case BLOCK_KIND_STR:
      mStr = blockData;
      break;
    case BLOCK_KIND_MID:
      mMid = (const Mid*)blockData;
      break;
    }

    block = (const Block*)((const u8*)block + block->size);
  }
}

s32 MessageGroup::getSlot(u32 messageId) {
  s32 result = -1;
  s32 min = 0;
  s32 max = ((u16**)this)[0x10/4][0] - 1;
  while (min <= max) {
    const s32 middle = (min + max) >> 1;
    if (mMid->messageIds[middle] == messageId) {
      result = middle;
      break;
    }

    if (mMid->messageIds[middle] < messageId) {
      min = middle + 1;
    } else {
      max = middle - 1;
    }
  }

  return result;
}

const wchar_t* MessageGroup::getMessage(s32 slot) {
  if (slot < 0 || slot >= mInf->numEntries) {
    return nullptr;
  }

  return mDat + (mInf->entries[slot].offset >> 1);
}

const u8* MessageGroup::getAttributes(s32 slot) {
  if (slot < 0 || slot >= mInf->numEntries) {
    return nullptr;
  }

  return &mInf->entries[slot].attributes;
}

} // namespace UI
