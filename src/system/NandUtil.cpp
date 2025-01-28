#include "NandUtil.hpp"

int NandUtil_safeOpen(const char* a1, NANDFileInfo* a2, u8 a3, void* a4,
                      u32 a5) {
  int v5;  // r28
  int v8;  // r25
  int v11; // r30
  int v12; // r29

  v5 = 0;
  v8 = a3;
  v11 = 1;
  v12 = 8;
  for (int v5 = 0; v5 < 3; ++v5) {
    switch (NANDSafeOpen(a1, a2, v8, a4, a5)) {
    case 0:
      v12 = 0;
      break;
    case -3:
    case -2:
      if (v5 >= 3)
        v12 = 2; // not reached
      else
        v11 = 0;
      break;
    case -4:
      v12 = 6;
      break;
    case -15:
    case -5:
    case -1:
      v12 = 3;
      break;
    case -12:
      v12 = 4;
      break;
    default:
      v12 = 8;
      break;
    }
    if (v11)
      break;
    OSSleepTicks(OSMillisecondsToTicks(100ll));
  }
  return v12;
}
int NandUtil_open(const char* a1, NANDFileInfo* a2, u8 a3) {
  int v7; // r27
  int v8; // r26

  v7 = 1;
  v8 = 8;
  for (int v3 = 0; v3 < 3; ++v3) {
    switch (NANDOpen(a1, a2, a3)) {
    case 0:
      v8 = 0;
      break;
    case -3:
    case -2:
      if (v3 >= 3)
        v8 = 2; // not reached
      else
        v7 = 0;
      break;
    case -1:
      v8 = 3;
      break;
    case -12:
      v8 = 4;
      break;
    default:
      v8 = 8;
      break;
    }
    if (v7)
      break;
    OSSleepTicks(OSMillisecondsToTicks(100ll));
  }
  return v8;
}
int NandUtil_safeClose(NANDFileInfo* a1) {
  int v3; // r27
  int v4; // r26

  v3 = 1;
  v4 = 8;
  for (int v1 = 0; v1 < 3; ++v1) {
    switch (NANDSafeClose(a1)) {
    case 0:
      v4 = 0;
      break;
    case -3:
    case -2:
      if (v1 >= 3)
        v4 = 2; // not reached
      else
        v3 = 0;
      break;
    case -4:
      v4 = 6;
      break;
    case -1:
    case -14:
      v4 = 3;
      break;
    default:
      v4 = 8;
      break;
    }
    if (v3)
      break;
    OSSleepTicks(OSMillisecondsToTicks(100ll));
  }
  return v4;
}
int NandUtil_close(NANDFileInfo* a1) {
  int v3; // r27
  int v4; // r26

  v3 = 1;
  v4 = 8;

  for (int v1 = 0; v1 < 3; ++v1) {
    switch (NANDClose(a1)) {
    case 0:
      v4 = 0;
      break;
    case -3:
    case -2:
      if (v1 >= 3)
        v4 = 2; // not reached
      else
        v3 = 0;
      break;
    case -4:
      v4 = 6;
      break;
    case -1:
      v4 = 3;
      break;
    default:
      v4 = 8;
      break;
    }
    if (v3)
      break;
    OSSleepTicks(OSMillisecondsToTicks(100ll));
  }
  return v4;
}

void unk_8052bd38(void* first) {
  u16 tmp[4];
  NandUtil_getStatus(first, &tmp[0]);
}
