#include <string.h>

#include "mem_cpy.h"

// Symbol: memchr
// PAL: 0x8000f2bc..0x8000f2e8
void* memchr(const void* ptr, int value, size_t num) {
  const unsigned char* str;
  unsigned int v = value & 0xff;
  for (str = (unsigned char*)ptr - 1, num++; --num;)
    if ((*++str & 0xff) == v)
      return (void*)str;
  return NULL;
}

// Symbol: __memrchr
// PAL: 0x8000f2e8..0x8000f314
void* __memrchr(const void* ptr, int value, size_t num) {
  const unsigned char* str;
  unsigned int v = value & 0xff;
  for (str = (unsigned char*)(ptr) + num, num++; --num;)
    if (*--str == v)
      return (void*)str;
  return NULL;
}

// Symbol: memcmp
// PAL: 0x8000f314..0x8000f360
int memcmp(const void* s1, const void* s2, size_t n) {
  const unsigned char* p1;
  const unsigned char* p2;
  for (p1 = (const unsigned char*)(s1)-1, p2 = (const unsigned char*)(s2)-1, n++; --n;)
    if (*++p1 != *++p2)
      return *p1 < *p2 ? -1 : 1;
  return 0;
}
