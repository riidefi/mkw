#include "wchar.h"
#include "stddef.h"

// Symbol: wcslen
// PAL: 0x80017998..0x800179d0
size_t wcslen(const wchar_t* str) {
  size_t len = -1;
  const wchar_t* data = str - 1;
  do {
    len++;
  } while (*++data);
  return len;
}

// Symbol: wcscpy
// PAL: 0x800179b4..0x800179d0
wchar_t* wcscpy(wchar_t* dst, const wchar_t* src) {
  const wchar_t* p1 = (wchar_t*)src - 1;
  wchar_t* p2 = (wchar_t*)dst - 1;
  while (*++p2 = *++p1) {
  }
  return (dst);
}

// Symbol: wcsncpy
// PAL: 0x800179d0..0x80017a14
wchar_t* wcsncpy(wchar_t* dst, const wchar_t* src, size_t n) {
  const wchar_t* p1 = src - 1;
  wchar_t* p2 = dst - 1;
  wchar_t zero = 0;
  n++;
  while (--n) {
    if (!(*++p2 = *++p1)) {
      while (--n)
        *++p2 = 0;
      break;
    }
  }
  return dst;
}

// Symbol: wcscmp
// PAL: 0x80017a14..0x80017a48
int wcscmp(const wchar_t* s1, const wchar_t* s2) {
  const wchar_t* p1 = (wchar_t*)s1 - 1;
  const wchar_t* p2 = (wchar_t*)s2 - 1;
  wchar_t c1, c2;
  while ((c1 = *++p1) == (c2 = *++p2))
    if (!c1)
      return 0;
  return c1 - c2;
}
