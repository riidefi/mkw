// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/src/RevoSDK/TRK/__mem.c
// Decompiled by GibHaltmannKill.

#include <string.h>

// PAL: 0x80005f34
__declspec(section ".init") void* memcpy(void* dest, const void* src,
                                         u32 count) {
  const char* csrc = (const char*)src;
  char* cdest = (char*)dest;

  if (src >= dest) {
    csrc--;
    cdest--;
    count++;

    while (--count) {
      *++cdest = *++csrc;
    }
  } else {
    csrc += count;
    cdest += count;
    count++;

    while (--count) {
      *--cdest = *--csrc;
    }
  }
  return dest;
}

// PAL: 0x80005f84
__declspec(section ".init") static void __fill_mem(void* dest, int val,
                                                   u32 count) {
  char* cdest = (char*)dest;
  int cval = (unsigned char)val;
  int* idest = (int*)dest;
  int r0;
  cdest--;
  if (count >= 0x20) {
    r0 = ~(int)(cdest)&3;

    if (r0) {
      count -= r0;

      do {
        *++cdest = cval;
      } while (--r0);
    }

    if (cval) {
      cval = (cval << 0x18) | (cval << 0x10) | (cval << 0x8) | cval;
    }

    r0 = count >> 5;
    idest = (int*)(cdest - 3);

    if (r0) {
      do {
        idest[1] = cval; // 4
        --r0;
        idest[2] = cval;      // 8
        idest[3] = cval;      // c
        idest[4] = cval;      // 10
        idest[5] = cval;      // 14
        idest[6] = cval;      // 18
        idest[7] = cval;      // 1c
        *(idest += 8) = cval; // 20
      } while (r0);
    }

    r0 = (count >> 2) & 7;

    if (r0) {
      do {
        *++idest = cval;
      } while (--r0);
    }

    cdest = (char*)idest + 3;
    count &= 3;
  }

  if (count) {
    do {
      *++cdest = cval;
    } while (--count);
  }
}

// PAL: 0x80006038
__declspec(section ".init") void* memset(void* dest, int val, u32 count) {
  __fill_mem(dest, val, count);
  return dest;
}
