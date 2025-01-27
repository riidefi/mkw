#include "eggCompress.hpp"

extern "C" u16 sSkipTable[256];

static void findMatch(const u8* src, int srcPos, int maxSize, int* matchOffset,
                      int* matchSize);
static int searchWindow(const u8* needle, int needleSize, const u8* haystack,
                        int haystackSize);
static void computeSkipTable(const u8* needle, int needleSize);

int EGG::encodeSZS(const u8* src, u8* dst, int srcSize) {
  int srcPos;
  int groupHeaderPos;
  int dstPos;
  u8 groupHeaderBitRaw;

  dst[0] = 'Y';
  dst[1] = 'a';
  dst[2] = 'z';
  dst[3] = '1';
  dst[4] = 0;
  dst[5] = srcSize >> 16;
  dst[6] = srcSize >> 8;
  dst[7] = srcSize;
  dst[16] = 0;

  srcPos = 0;
  groupHeaderBitRaw = 0x80;
  groupHeaderPos = 16;
  dstPos = 17;
  while (srcPos < srcSize) {
    int matchOffset;
    int firstMatchLen;
    findMatch(src, srcPos, srcSize, &matchOffset, &firstMatchLen);
    if (firstMatchLen > 2) {
      int secondMatchOffset;
      int secondMatchLen;
      findMatch(src, srcPos + 1, srcSize, &secondMatchOffset, &secondMatchLen);
      if (firstMatchLen + 1 < secondMatchLen) {
        // Put a single byte
        dst[groupHeaderPos] |= groupHeaderBitRaw;
        groupHeaderBitRaw = groupHeaderBitRaw >> 1;
        dst[dstPos++] = src[srcPos++];
        if (!groupHeaderBitRaw) {
          groupHeaderBitRaw = 0x80;
          groupHeaderPos = dstPos;
          dst[dstPos++] = 0;
        }
        // Use the second match
        firstMatchLen = secondMatchLen;
        matchOffset = secondMatchOffset;
      }
      matchOffset = srcPos - matchOffset - 1;
      if (firstMatchLen < 18) {
        matchOffset |= ((firstMatchLen - 2) << 12);
        dst[dstPos] = matchOffset >> 8;
        dst[dstPos + 1] = matchOffset;
        dstPos += 2;
      } else {
        dst[dstPos] = matchOffset >> 8;
        dst[dstPos + 1] = matchOffset;
        dst[dstPos + 2] = firstMatchLen - 18;
        dstPos += 3;
      }
      srcPos += firstMatchLen;
    } else {
      // Put a single byte
      dst[groupHeaderPos] |= groupHeaderBitRaw;
      dst[dstPos++] = src[srcPos++];
    }

    // Write next group header
    groupHeaderBitRaw >>= 1;
    if (!groupHeaderBitRaw) {
      groupHeaderBitRaw = 0x80;
      groupHeaderPos = dstPos;
      dst[dstPos++] = 0;
    }
  }

  return dstPos;
}

void findMatch(const u8* src, int srcPos, int maxSize, int* matchOffset,
               int* matchSize) {
  // SZS backreference types:
  // (2 bytes) N >= 2:  NR RR    -> maxMatchSize=16+2,    windowOffset=4096+1
  // (3 bytes) N >= 18: 0R RR NN -> maxMatchSize=0xFF+18, windowOffset=4096+1
  int window = srcPos > 4096 ? srcPos - 4096 : 0;
  int windowSize = 3;
  int maxMatchSize = (maxSize - srcPos) <= 273 ? maxSize - srcPos : 273;
  if (maxMatchSize < 3) {
    *matchSize = 0;
    *matchOffset = 0;
    return;
  }

  int windowOffset;
  int foundMatchOffset;
  while (window < srcPos &&
         (windowOffset = searchWindow(&src[srcPos], windowSize, &src[window],
                                      srcPos + windowSize - window)) <
             srcPos - window) {
    for (; windowSize < maxMatchSize; ++windowSize) {
      if (src[window + windowOffset + windowSize] != src[srcPos + windowSize])
        break;
    }
    if (windowSize == maxMatchSize) {
      *matchOffset = window + windowOffset;
      *matchSize = maxMatchSize;
      return;
    }
    foundMatchOffset = window + windowOffset;
    ++windowSize;
    window += windowOffset + 1;
  }
  *matchOffset = foundMatchOffset;
  *matchSize = windowSize > 3 ? windowSize - 1 : 0;
}

static int searchWindow(const u8* needle, int needleSize, const u8* haystack,
                        int haystackSize) {
  int itHaystack; // r8
  int itNeedle;   // r9

  if (needleSize > haystackSize)
    return haystackSize;
  computeSkipTable(needle, needleSize);

  // Scan forwards for the last character in the needle
  for (itHaystack = needleSize - 1;;) {
    while (1) {
// https://decomp.me/scratch/F4KVk
#ifdef NON_MATCHING
      if (needle[needleSize - 1] == haystack[itHaystack])
        break;
#else
      if (*(u8*)(needleSize + ((u32)needle) - 1) == haystack[itHaystack])
        break;
#endif
      itHaystack += sSkipTable[haystack[itHaystack]];
    }
    --itHaystack;
    itNeedle = needleSize - 2;
    break;
  Difference:
    // The entire needle was not found, continue search
    int skip = sSkipTable[haystack[itHaystack]];
    if (needleSize - itNeedle > skip)
      skip = needleSize - itNeedle;
    itHaystack += skip;
  }

  // Scan backwards for the first difference
  int remainingBytes = itNeedle;
  for (int j = 0; j <= remainingBytes; ++j) {
    if (haystack[itHaystack] != needle[itNeedle]) {
      goto Difference;
    }
    --itHaystack;
    --itNeedle;
  }
  return itHaystack + 1;
}

static void computeSkipTable(const u8* needle, int needleSize) {
  for (int i = 0; i < 256; ++i) {
    sSkipTable[i] = needleSize;
  }
  for (int i = 0; i < needleSize; ++i) {
    sSkipTable[needle[i]] = needleSize - i - 1;
  }
}
