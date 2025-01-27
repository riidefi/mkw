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
// Symbol: NandUtil_read
// PAL: 0x8052b228..0x8052b3f8
MARK_BINARY_BLOB(NandUtil_read, 0x8052b228, 0x8052b3f8);
asm UNKNOWN_FUNCTION(NandUtil_read){
  // clang-format off
  nofralloc
  /* 8052B228 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 8052B22C 7C0802A6 */ mflr        r0
  /* 8052B230 3CE01062 */ lis         r7, 0x1062
  /* 8052B234 90010044 */ stw         r0, 0x44(r1)
  /* 8052B238 BEA10014 */ stmw        r21, 0x14(r1)
  /* 8052B23C 3BA00000 */ li          r29, 0x0
  /* 8052B240 3B000064 */ li          r24, 0x64
  /* 8052B244 7C791B78 */ mr          r25, r3
  /* 8052B248 7EFDC1D6 */ mullw       r23, r29, r24
  /* 8052B24C 7C9A2378 */ mr          r26, r4
  /* 8052B250 7CBB2B78 */ mr          r27, r5
  /* 8052B254 7CDC3378 */ mr          r28, r6
  /* 8052B258 3AA74DD3 */ addi        r21, r7, 0x4dd3
  /* 8052B25C 3BE00001 */ li          r31, 0x1
  /* 8052B260 3BC00008 */ li          r30, 0x8
  /* 8052B264 3EC08000 */ lis         r22, 0x8000
  lbl_8052b268:
  /* 8052B268 7F23CB78 */ mr          r3, r25
  /* 8052B26C 7F84E378 */ mr          r4, r28
  /* 8052B270 38A00000 */ li          r5, 0x0
  /* 8052B274 4BC706F1 */ bl          NANDSeek
  /* 8052B278 7C03E000 */ cmpw        r3, r28
  /* 8052B27C 4082000C */ bne-        lbl_8052b288
  /* 8052B280 3BC00000 */ li          r30, 0x0
  /* 8052B284 48000040 */ b           lbl_8052b2c4
  lbl_8052b288:
  /* 8052B288 38030003 */ addi        r0, r3, 0x3
  /* 8052B28C 28000001 */ cmplwi      r0, 1
  /* 8052B290 40810010 */ ble-        lbl_8052b2a0
  /* 8052B294 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B298 41820020 */ beq-        lbl_8052b2b8
  /* 8052B29C 48000024 */ b           lbl_8052b2c0
  lbl_8052b2a0:
  /* 8052B2A0 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B2A4 4180000C */ blt-        lbl_8052b2b0
  /* 8052B2A8 3BC00002 */ li          r30, 0x2
  /* 8052B2AC 48000018 */ b           lbl_8052b2c4
  lbl_8052b2b0:
  /* 8052B2B0 3BE00000 */ li          r31, 0x0
  /* 8052B2B4 48000010 */ b           lbl_8052b2c4
  lbl_8052b2b8:
  /* 8052B2B8 3BC00003 */ li          r30, 0x3
  /* 8052B2BC 48000008 */ b           lbl_8052b2c4
  lbl_8052b2c0:
  /* 8052B2C0 3BC00008 */ li          r30, 0x8
  lbl_8052b2c4:
  /* 8052B2C4 2C1F0000 */ cmpwi       r31, 0x0
  /* 8052B2C8 40820030 */ bne-        lbl_8052b2f8
  /* 8052B2CC 801600F8 */ lwz         r0, 0xf8(r22)
  /* 8052B2D0 5400F0BE */ srwi        r0, r0, 2
  /* 8052B2D4 7C150016 */ mulhwu      r0, r21, r0
  /* 8052B2D8 5403D1BE */ srwi        r3, r0, 6
  /* 8052B2DC 7C03C016 */ mulhwu      r0, r3, r24
  /* 8052B2E0 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B2E4 7C60BA14 */ add         r3, r0, r23
  /* 8052B2E8 4BC7F9C1 */ bl          OSSleepTicks
  /* 8052B2EC 3BBD0001 */ addi        r29, r29, 0x1
  /* 8052B2F0 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B2F4 4180FF74 */ blt+        lbl_8052b268
  lbl_8052b2f8:
  /* 8052B2F8 2C1E0000 */ cmpwi       r30, 0x0
  /* 8052B2FC 4182000C */ beq-        lbl_8052b308
  /* 8052B300 7FC3F378 */ mr          r3, r30
  /* 8052B304 480000E0 */ b           lbl_8052b3e4
  lbl_8052b308:
  /* 8052B308 3AA00000 */ li          r21, 0x0
  /* 8052B30C 3BA00064 */ li          r29, 0x64
  /* 8052B310 7F95E9D6 */ mullw       r28, r21, r29
  /* 8052B314 3C601062 */ lis         r3, 0x1062
  /* 8052B318 3F008000 */ lis         r24, 0x8000
  /* 8052B31C 3AE34DD3 */ addi        r23, r3, 0x4dd3
  lbl_8052b320:
  /* 8052B320 7F23CB78 */ mr          r3, r25
  /* 8052B324 7F44D378 */ mr          r4, r26
  /* 8052B328 7F65DB78 */ mr          r5, r27
  /* 8052B32C 4BC70479 */ bl          NANDRead
  /* 8052B330 7C03D840 */ cmplw       r3, r27
  /* 8052B334 4082000C */ bne-        lbl_8052b340
  /* 8052B338 3BC00000 */ li          r30, 0x0
  /* 8052B33C 48000070 */ b           lbl_8052b3ac
  lbl_8052b340:
  /* 8052B340 2C030000 */ cmpwi       r3, 0x0
  /* 8052B344 4180000C */ blt-        lbl_8052b350
  /* 8052B348 3BC00003 */ li          r30, 0x3
  /* 8052B34C 48000060 */ b           lbl_8052b3ac
  lbl_8052b350:
  /* 8052B350 38030003 */ addi        r0, r3, 0x3
  /* 8052B354 28000001 */ cmplwi      r0, 1
  /* 8052B358 40810028 */ ble-        lbl_8052b380
  /* 8052B35C 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052B360 41820038 */ beq-        lbl_8052b398
  /* 8052B364 2C03FFF1 */ cmpwi       r3, -0xf
  /* 8052B368 41820038 */ beq-        lbl_8052b3a0
  /* 8052B36C 2C03FFFB */ cmpwi       r3, -0x5
  /* 8052B370 41820030 */ beq-        lbl_8052b3a0
  /* 8052B374 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B378 41820028 */ beq-        lbl_8052b3a0
  /* 8052B37C 4800002C */ b           lbl_8052b3a8
  lbl_8052b380:
  /* 8052B380 2C150003 */ cmpwi       r21, 0x3
  /* 8052B384 4180000C */ blt-        lbl_8052b390
  /* 8052B388 3BC00002 */ li          r30, 0x2
  /* 8052B38C 48000020 */ b           lbl_8052b3ac
  lbl_8052b390:
  /* 8052B390 3BE00000 */ li          r31, 0x0
  /* 8052B394 48000018 */ b           lbl_8052b3ac
  lbl_8052b398:
  /* 8052B398 3BC00006 */ li          r30, 0x6
  /* 8052B39C 48000010 */ b           lbl_8052b3ac
  lbl_8052b3a0:
  /* 8052B3A0 3BC00003 */ li          r30, 0x3
  /* 8052B3A4 48000008 */ b           lbl_8052b3ac
  lbl_8052b3a8:
  /* 8052B3A8 3BC00008 */ li          r30, 0x8
  lbl_8052b3ac:
  /* 8052B3AC 2C1F0000 */ cmpwi       r31, 0x0
  /* 8052B3B0 40820030 */ bne-        lbl_8052b3e0
  /* 8052B3B4 801800F8 */ lwz         r0, 0xf8(r24)
  /* 8052B3B8 5400F0BE */ srwi        r0, r0, 2
  /* 8052B3BC 7C170016 */ mulhwu      r0, r23, r0
  /* 8052B3C0 5403D1BE */ srwi        r3, r0, 6
  /* 8052B3C4 7C03E816 */ mulhwu      r0, r3, r29
  /* 8052B3C8 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B3CC 7C60E214 */ add         r3, r0, r28
  /* 8052B3D0 4BC7F8D9 */ bl          OSSleepTicks
  /* 8052B3D4 3AB50001 */ addi        r21, r21, 0x1
  /* 8052B3D8 2C150003 */ cmpwi       r21, 0x3
  /* 8052B3DC 4180FF44 */ blt+        lbl_8052b320
  lbl_8052b3e0:
  /* 8052B3E0 7FC3F378 */ mr          r3, r30
  lbl_8052b3e4:
  /* 8052B3E4 BAA10014 */ lmw         r21, 0x14(r1)
  /* 8052B3E8 80010044 */ lwz         r0, 0x44(r1)
  /* 8052B3EC 7C0803A6 */ mtlr        r0
  /* 8052B3F0 38210040 */ addi        r1, r1, 0x40
  /* 8052B3F4 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_getLength
// PAL: 0x8052b3f8..0x8052b4d4
MARK_BINARY_BLOB(NandUtil_getLength, 0x8052b3f8, 0x8052b4d4);
asm UNKNOWN_FUNCTION(NandUtil_getLength){
  // clang-format off
  nofralloc
  /* 8052B3F8 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052B3FC 7C0802A6 */ mflr        r0
  /* 8052B400 3CA01062 */ lis         r5, 0x1062
  /* 8052B404 90010034 */ stw         r0, 0x34(r1)
  /* 8052B408 BEE1000C */ stmw        r23, 0xc(r1)
  /* 8052B40C 3B200000 */ li          r25, 0x0
  /* 8052B410 3BC00064 */ li          r30, 0x64
  /* 8052B414 7C771B78 */ mr          r23, r3
  /* 8052B418 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052B41C 7C982378 */ mr          r24, r4
  /* 8052B420 3B854DD3 */ addi        r28, r5, 0x4dd3
  /* 8052B424 3B600001 */ li          r27, 0x1
  /* 8052B428 3B400008 */ li          r26, 0x8
  /* 8052B42C 3FA08000 */ lis         r29, 0x8000
  lbl_8052b430:
  /* 8052B430 7EE3BB78 */ mr          r3, r23
  /* 8052B434 7F04C378 */ mr          r4, r24
  /* 8052B438 4BC70B15 */ bl          NANDGetLength
  /* 8052B43C 38030003 */ addi        r0, r3, 0x3
  /* 8052B440 28000001 */ cmplwi      r0, 1
  /* 8052B444 40810020 */ ble-        lbl_8052b464
  /* 8052B448 2C030000 */ cmpwi       r3, 0x0
  /* 8052B44C 41820010 */ beq-        lbl_8052b45c
  /* 8052B450 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052B454 41820028 */ beq-        lbl_8052b47c
  /* 8052B458 4800002C */ b           lbl_8052b484
  lbl_8052b45c:
  /* 8052B45C 3B400000 */ li          r26, 0x0
  /* 8052B460 48000028 */ b           lbl_8052b488
  lbl_8052b464:
  /* 8052B464 2C190003 */ cmpwi       r25, 0x3
  /* 8052B468 4180000C */ blt-        lbl_8052b474
  /* 8052B46C 3B400002 */ li          r26, 0x2
  /* 8052B470 48000018 */ b           lbl_8052b488
  lbl_8052b474:
  /* 8052B474 3B600000 */ li          r27, 0x0
  /* 8052B478 48000010 */ b           lbl_8052b488
  lbl_8052b47c:
  /* 8052B47C 3B400006 */ li          r26, 0x6
  /* 8052B480 48000008 */ b           lbl_8052b488
  lbl_8052b484:
  /* 8052B484 3B400008 */ li          r26, 0x8
  lbl_8052b488:
  /* 8052B488 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052B48C 40820030 */ bne-        lbl_8052b4bc
  /* 8052B490 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052B494 5400F0BE */ srwi        r0, r0, 2
  /* 8052B498 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052B49C 5403D1BE */ srwi        r3, r0, 6
  /* 8052B4A0 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052B4A4 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B4A8 7C60FA14 */ add         r3, r0, r31
  /* 8052B4AC 4BC7F7FD */ bl          OSSleepTicks
  /* 8052B4B0 3B390001 */ addi        r25, r25, 0x1
  /* 8052B4B4 2C190003 */ cmpwi       r25, 0x3
  /* 8052B4B8 4180FF78 */ blt+        lbl_8052b430
  lbl_8052b4bc:
  /* 8052B4BC 7F43D378 */ mr          r3, r26
  /* 8052B4C0 BAE1000C */ lmw         r23, 0xc(r1)
  /* 8052B4C4 80010034 */ lwz         r0, 0x34(r1)
  /* 8052B4C8 7C0803A6 */ mtlr        r0
  /* 8052B4CC 38210030 */ addi        r1, r1, 0x30
  /* 8052B4D0 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_write
// PAL: 0x8052b4d4..0x8052b684
MARK_BINARY_BLOB(NandUtil_write, 0x8052b4d4, 0x8052b684);
asm UNKNOWN_FUNCTION(NandUtil_write){
  // clang-format off
  nofralloc
  /* 8052B4D4 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 8052B4D8 7C0802A6 */ mflr        r0
  /* 8052B4DC 3CE01062 */ lis         r7, 0x1062
  /* 8052B4E0 90010044 */ stw         r0, 0x44(r1)
  /* 8052B4E4 BEA10014 */ stmw        r21, 0x14(r1)
  /* 8052B4E8 3BA00000 */ li          r29, 0x0
  /* 8052B4EC 3B000064 */ li          r24, 0x64
  /* 8052B4F0 7C791B78 */ mr          r25, r3
  /* 8052B4F4 7EFDC1D6 */ mullw       r23, r29, r24
  /* 8052B4F8 7C9A2378 */ mr          r26, r4
  /* 8052B4FC 7CBB2B78 */ mr          r27, r5
  /* 8052B500 7CDC3378 */ mr          r28, r6
  /* 8052B504 3AA74DD3 */ addi        r21, r7, 0x4dd3
  /* 8052B508 3BE00001 */ li          r31, 0x1
  /* 8052B50C 3BC00008 */ li          r30, 0x8
  /* 8052B510 3EC08000 */ lis         r22, 0x8000
  lbl_8052b514:
  /* 8052B514 7F23CB78 */ mr          r3, r25
  /* 8052B518 7F84E378 */ mr          r4, r28
  /* 8052B51C 38A00000 */ li          r5, 0x0
  /* 8052B520 4BC70445 */ bl          NANDSeek
  /* 8052B524 7C03E000 */ cmpw        r3, r28
  /* 8052B528 4082000C */ bne-        lbl_8052b534
  /* 8052B52C 3BC00000 */ li          r30, 0x0
  /* 8052B530 48000040 */ b           lbl_8052b570
  lbl_8052b534:
  /* 8052B534 38030003 */ addi        r0, r3, 0x3
  /* 8052B538 28000001 */ cmplwi      r0, 1
  /* 8052B53C 40810010 */ ble-        lbl_8052b54c
  /* 8052B540 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B544 41820020 */ beq-        lbl_8052b564
  /* 8052B548 48000024 */ b           lbl_8052b56c
  lbl_8052b54c:
  /* 8052B54C 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B550 4180000C */ blt-        lbl_8052b55c
  /* 8052B554 3BC00002 */ li          r30, 0x2
  /* 8052B558 48000018 */ b           lbl_8052b570
  lbl_8052b55c:
  /* 8052B55C 3BE00000 */ li          r31, 0x0
  /* 8052B560 48000010 */ b           lbl_8052b570
  lbl_8052b564:
  /* 8052B564 3BC00003 */ li          r30, 0x3
  /* 8052B568 48000008 */ b           lbl_8052b570
  lbl_8052b56c:
  /* 8052B56C 3BC00008 */ li          r30, 0x8
  lbl_8052b570:
  /* 8052B570 2C1F0000 */ cmpwi       r31, 0x0
  /* 8052B574 40820030 */ bne-        lbl_8052b5a4
  /* 8052B578 801600F8 */ lwz         r0, 0xf8(r22)
  /* 8052B57C 5400F0BE */ srwi        r0, r0, 2
  /* 8052B580 7C150016 */ mulhwu      r0, r21, r0
  /* 8052B584 5403D1BE */ srwi        r3, r0, 6
  /* 8052B588 7C03C016 */ mulhwu      r0, r3, r24
  /* 8052B58C 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B590 7C60BA14 */ add         r3, r0, r23
  /* 8052B594 4BC7F715 */ bl          OSSleepTicks
  /* 8052B598 3BBD0001 */ addi        r29, r29, 0x1
  /* 8052B59C 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B5A0 4180FF74 */ blt+        lbl_8052b514
  lbl_8052b5a4:
  /* 8052B5A4 2C1E0000 */ cmpwi       r30, 0x0
  /* 8052B5A8 4182000C */ beq-        lbl_8052b5b4
  /* 8052B5AC 7FC3F378 */ mr          r3, r30
  /* 8052B5B0 480000C0 */ b           lbl_8052b670
  lbl_8052b5b4:
  /* 8052B5B4 3AA00000 */ li          r21, 0x0
  /* 8052B5B8 3BA00064 */ li          r29, 0x64
  /* 8052B5BC 7F95E9D6 */ mullw       r28, r21, r29
  /* 8052B5C0 3C601062 */ lis         r3, 0x1062
  /* 8052B5C4 3F008000 */ lis         r24, 0x8000
  /* 8052B5C8 3AE34DD3 */ addi        r23, r3, 0x4dd3
  lbl_8052b5cc:
  /* 8052B5CC 7F23CB78 */ mr          r3, r25
  /* 8052B5D0 7F44D378 */ mr          r4, r26
  /* 8052B5D4 7F65DB78 */ mr          r5, r27
  /* 8052B5D8 4BC702AD */ bl          NANDWrite
  /* 8052B5DC 7C03D840 */ cmplw       r3, r27
  /* 8052B5E0 4082000C */ bne-        lbl_8052b5ec
  /* 8052B5E4 3BC00000 */ li          r30, 0x0
  /* 8052B5E8 48000050 */ b           lbl_8052b638
  lbl_8052b5ec:
  /* 8052B5EC 2C030000 */ cmpwi       r3, 0x0
  /* 8052B5F0 4180000C */ blt-        lbl_8052b5fc
  /* 8052B5F4 3BC00003 */ li          r30, 0x3
  /* 8052B5F8 48000040 */ b           lbl_8052b638
  lbl_8052b5fc:
  /* 8052B5FC 38030003 */ addi        r0, r3, 0x3
  /* 8052B600 28000001 */ cmplwi      r0, 1
  /* 8052B604 40810010 */ ble-        lbl_8052b614
  /* 8052B608 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052B60C 41820020 */ beq-        lbl_8052b62c
  /* 8052B610 48000024 */ b           lbl_8052b634
  lbl_8052b614:
  /* 8052B614 2C150003 */ cmpwi       r21, 0x3
  /* 8052B618 4180000C */ blt-        lbl_8052b624
  /* 8052B61C 3BC00002 */ li          r30, 0x2
  /* 8052B620 48000018 */ b           lbl_8052b638
  lbl_8052b624:
  /* 8052B624 3BE00000 */ li          r31, 0x0
  /* 8052B628 48000010 */ b           lbl_8052b638
  lbl_8052b62c:
  /* 8052B62C 3BC00006 */ li          r30, 0x6
  /* 8052B630 48000008 */ b           lbl_8052b638
  lbl_8052b634:
  /* 8052B634 3BC00008 */ li          r30, 0x8
  lbl_8052b638:
  /* 8052B638 2C1F0000 */ cmpwi       r31, 0x0
  /* 8052B63C 40820030 */ bne-        lbl_8052b66c
  /* 8052B640 801800F8 */ lwz         r0, 0xf8(r24)
  /* 8052B644 5400F0BE */ srwi        r0, r0, 2
  /* 8052B648 7C170016 */ mulhwu      r0, r23, r0
  /* 8052B64C 5403D1BE */ srwi        r3, r0, 6
  /* 8052B650 7C03E816 */ mulhwu      r0, r3, r29
  /* 8052B654 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B658 7C60E214 */ add         r3, r0, r28
  /* 8052B65C 4BC7F64D */ bl          OSSleepTicks
  /* 8052B660 3AB50001 */ addi        r21, r21, 0x1
  /* 8052B664 2C150003 */ cmpwi       r21, 0x3
  /* 8052B668 4180FF64 */ blt+        lbl_8052b5cc
  lbl_8052b66c:
  /* 8052B66C 7FC3F378 */ mr          r3, r30
  lbl_8052b670:
  /* 8052B670 BAA10014 */ lmw         r21, 0x14(r1)
  /* 8052B674 80010044 */ lwz         r0, 0x44(r1)
  /* 8052B678 7C0803A6 */ mtlr        r0
  /* 8052B67C 38210040 */ addi        r1, r1, 0x40
  /* 8052B680 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_check
// PAL: 0x8052b684..0x8052b754
MARK_BINARY_BLOB(NandUtil_check, 0x8052b684, 0x8052b754);
asm UNKNOWN_FUNCTION(NandUtil_check){
  // clang-format off
  nofralloc
  /* 8052B684 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052B688 7C0802A6 */ mflr        r0
  /* 8052B68C 3CC01062 */ lis         r6, 0x1062
  /* 8052B690 90010034 */ stw         r0, 0x34(r1)
  /* 8052B694 BEC10008 */ stmw        r22, 8(r1)
  /* 8052B698 3B200000 */ li          r25, 0x0
  /* 8052B69C 3BC00064 */ li          r30, 0x64
  /* 8052B6A0 7C761B78 */ mr          r22, r3
  /* 8052B6A4 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052B6A8 7C972378 */ mr          r23, r4
  /* 8052B6AC 7CB82B78 */ mr          r24, r5
  /* 8052B6B0 3B864DD3 */ addi        r28, r6, 0x4dd3
  /* 8052B6B4 3B600001 */ li          r27, 0x1
  /* 8052B6B8 3B400008 */ li          r26, 0x8
  /* 8052B6BC 3FA08000 */ lis         r29, 0x8000
  lbl_8052b6c0:
  /* 8052B6C0 7EC3B378 */ mr          r3, r22
  /* 8052B6C4 7EE4BB78 */ mr          r4, r23
  /* 8052B6C8 7F05C378 */ mr          r5, r24
  /* 8052B6CC 4BC73405 */ bl          NANDCheck
  /* 8052B6D0 38030003 */ addi        r0, r3, 0x3
  /* 8052B6D4 28000001 */ cmplwi      r0, 1
  /* 8052B6D8 40810014 */ ble-        lbl_8052b6ec
  /* 8052B6DC 2C030000 */ cmpwi       r3, 0x0
  /* 8052B6E0 40820024 */ bne-        lbl_8052b704
  /* 8052B6E4 3B400000 */ li          r26, 0x0
  /* 8052B6E8 48000020 */ b           lbl_8052b708
  lbl_8052b6ec:
  /* 8052B6EC 2C190003 */ cmpwi       r25, 0x3
  /* 8052B6F0 4180000C */ blt-        lbl_8052b6fc
  /* 8052B6F4 3B400002 */ li          r26, 0x2
  /* 8052B6F8 48000010 */ b           lbl_8052b708
  lbl_8052b6fc:
  /* 8052B6FC 3B600000 */ li          r27, 0x0
  /* 8052B700 48000008 */ b           lbl_8052b708
  lbl_8052b704:
  /* 8052B704 3B400008 */ li          r26, 0x8
  lbl_8052b708:
  /* 8052B708 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052B70C 40820030 */ bne-        lbl_8052b73c
  /* 8052B710 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052B714 5400F0BE */ srwi        r0, r0, 2
  /* 8052B718 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052B71C 5403D1BE */ srwi        r3, r0, 6
  /* 8052B720 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052B724 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B728 7C60FA14 */ add         r3, r0, r31
  /* 8052B72C 4BC7F57D */ bl          OSSleepTicks
  /* 8052B730 3B390001 */ addi        r25, r25, 0x1
  /* 8052B734 2C190003 */ cmpwi       r25, 0x3
  /* 8052B738 4180FF88 */ blt+        lbl_8052b6c0
  lbl_8052b73c:
  /* 8052B73C 7F43D378 */ mr          r3, r26
  /* 8052B740 BAC10008 */ lmw         r22, 8(r1)
  /* 8052B744 80010034 */ lwz         r0, 0x34(r1)
  /* 8052B748 7C0803A6 */ mtlr        r0
  /* 8052B74C 38210030 */ addi        r1, r1, 0x30
  /* 8052B750 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_createDir
// PAL: 0x8052b754..0x8052b84c
MARK_BINARY_BLOB(NandUtil_createDir, 0x8052b754, 0x8052b84c);
asm UNKNOWN_FUNCTION(NandUtil_createDir){
  // clang-format off
  nofralloc
  /* 8052B754 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052B758 7C0802A6 */ mflr        r0
  /* 8052B75C 3CA01062 */ lis         r5, 0x1062
  /* 8052B760 90010034 */ stw         r0, 0x34(r1)
  /* 8052B764 BEE1000C */ stmw        r23, 0xc(r1)
  /* 8052B768 3B200000 */ li          r25, 0x0
  /* 8052B76C 3BC00064 */ li          r30, 0x64
  /* 8052B770 7C771B78 */ mr          r23, r3
  /* 8052B774 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052B778 7C982378 */ mr          r24, r4
  /* 8052B77C 3B854DD3 */ addi        r28, r5, 0x4dd3
  /* 8052B780 3B600001 */ li          r27, 0x1
  /* 8052B784 3B400008 */ li          r26, 0x8
  /* 8052B788 3FA08000 */ lis         r29, 0x8000
  lbl_8052b78c:
  /* 8052B78C 7EE3BB78 */ mr          r3, r23
  /* 8052B790 7F04C378 */ mr          r4, r24
  /* 8052B794 38A00000 */ li          r5, 0x0
  /* 8052B798 4BC70449 */ bl          NANDCreateDir
  /* 8052B79C 38030003 */ addi        r0, r3, 0x3
  /* 8052B7A0 28000001 */ cmplwi      r0, 1
  /* 8052B7A4 40810030 */ ble-        lbl_8052b7d4
  /* 8052B7A8 2C030000 */ cmpwi       r3, 0x0
  /* 8052B7AC 41820020 */ beq-        lbl_8052b7cc
  /* 8052B7B0 2C03FFFA */ cmpwi       r3, -0x6
  /* 8052B7B4 41820018 */ beq-        lbl_8052b7cc
  /* 8052B7B8 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052B7BC 41820030 */ beq-        lbl_8052b7ec
  /* 8052B7C0 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B7C4 41820030 */ beq-        lbl_8052b7f4
  /* 8052B7C8 48000034 */ b           lbl_8052b7fc
  lbl_8052b7cc:
  /* 8052B7CC 3B400000 */ li          r26, 0x0
  /* 8052B7D0 48000030 */ b           lbl_8052b800
  lbl_8052b7d4:
  /* 8052B7D4 2C190003 */ cmpwi       r25, 0x3
  /* 8052B7D8 4180000C */ blt-        lbl_8052b7e4
  /* 8052B7DC 3B400002 */ li          r26, 0x2
  /* 8052B7E0 48000020 */ b           lbl_8052b800
  lbl_8052b7e4:
  /* 8052B7E4 3B600000 */ li          r27, 0x0
  /* 8052B7E8 48000018 */ b           lbl_8052b800
  lbl_8052b7ec:
  /* 8052B7EC 3B400006 */ li          r26, 0x6
  /* 8052B7F0 48000010 */ b           lbl_8052b800
  lbl_8052b7f4:
  /* 8052B7F4 3B400003 */ li          r26, 0x3
  /* 8052B7F8 48000008 */ b           lbl_8052b800
  lbl_8052b7fc:
  /* 8052B7FC 3B400008 */ li          r26, 0x8
  lbl_8052b800:
  /* 8052B800 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052B804 40820030 */ bne-        lbl_8052b834
  /* 8052B808 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052B80C 5400F0BE */ srwi        r0, r0, 2
  /* 8052B810 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052B814 5403D1BE */ srwi        r3, r0, 6
  /* 8052B818 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052B81C 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B820 7C60FA14 */ add         r3, r0, r31
  /* 8052B824 4BC7F485 */ bl          OSSleepTicks
  /* 8052B828 3B390001 */ addi        r25, r25, 0x1
  /* 8052B82C 2C190003 */ cmpwi       r25, 0x3
  /* 8052B830 4180FF5C */ blt+        lbl_8052b78c
  lbl_8052b834:
  /* 8052B834 7F43D378 */ mr          r3, r26
  /* 8052B838 BAE1000C */ lmw         r23, 0xc(r1)
  /* 8052B83C 80010034 */ lwz         r0, 0x34(r1)
  /* 8052B840 7C0803A6 */ mtlr        r0
  /* 8052B844 38210030 */ addi        r1, r1, 0x30
  /* 8052B848 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_getType
// PAL: 0x8052b84c..0x8052b95c
MARK_BINARY_BLOB(NandUtil_getType, 0x8052b84c, 0x8052b95c);
asm UNKNOWN_FUNCTION(NandUtil_getType){
  // clang-format off
  nofralloc
  /* 8052B84C 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 8052B850 7C0802A6 */ mflr        r0
  /* 8052B854 3CA01062 */ lis         r5, 0x1062
  /* 8052B858 90010044 */ stw         r0, 0x44(r1)
  /* 8052B85C BEA10014 */ stmw        r21, 0x14(r1)
  /* 8052B860 3BA00000 */ li          r29, 0x0
  /* 8052B864 3B200064 */ li          r25, 0x64
  /* 8052B868 7C7B1B78 */ mr          r27, r3
  /* 8052B86C 7F5DC9D6 */ mullw       r26, r29, r25
  /* 8052B870 7C9C2378 */ mr          r28, r4
  /* 8052B874 3AE54DD3 */ addi        r23, r5, 0x4dd3
  /* 8052B878 3BE00001 */ li          r31, 0x1
  /* 8052B87C 3BC00008 */ li          r30, 0x8
  /* 8052B880 3AC00002 */ li          r22, 0x2
  /* 8052B884 3AA00001 */ li          r21, 0x1
  /* 8052B888 3F008000 */ lis         r24, 0x8000
  lbl_8052b88c:
  /* 8052B88C 7F63DB78 */ mr          r3, r27
  /* 8052B890 38810008 */ addi        r4, r1, 0x8
  /* 8052B894 4BC72EDD */ bl          NANDGetType
  /* 8052B898 38030003 */ addi        r0, r3, 0x3
  /* 8052B89C 28000001 */ cmplwi      r0, 1
  /* 8052B8A0 4081004C */ ble-        lbl_8052b8ec
  /* 8052B8A4 2C030000 */ cmpwi       r3, 0x0
  /* 8052B8A8 41820018 */ beq-        lbl_8052b8c0
  /* 8052B8AC 2C03FFF4 */ cmpwi       r3, -0xc
  /* 8052B8B0 41820030 */ beq-        lbl_8052b8e0
  /* 8052B8B4 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B8B8 4182004C */ beq-        lbl_8052b904
  /* 8052B8BC 48000050 */ b           lbl_8052b90c
  lbl_8052b8c0:
  /* 8052B8C0 88010008 */ lbz         r0, 8(r1)
  /* 8052B8C4 3BC00000 */ li          r30, 0x0
  /* 8052B8C8 28000001 */ cmplwi      r0, 1
  /* 8052B8CC 4082000C */ bne-        lbl_8052b8d8
  /* 8052B8D0 92BC0000 */ stw         r21, 0(r28)
  /* 8052B8D4 4800003C */ b           lbl_8052b910
  lbl_8052b8d8:
  /* 8052B8D8 92DC0000 */ stw         r22, 0(r28)
  /* 8052B8DC 48000034 */ b           lbl_8052b910
  lbl_8052b8e0:
  /* 8052B8E0 3BC00000 */ li          r30, 0x0
  /* 8052B8E4 93DC0000 */ stw         r30, 0(r28)
  /* 8052B8E8 48000028 */ b           lbl_8052b910
  lbl_8052b8ec:
  /* 8052B8EC 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B8F0 4180000C */ blt-        lbl_8052b8fc
  /* 8052B8F4 3BC00002 */ li          r30, 0x2
  /* 8052B8F8 48000018 */ b           lbl_8052b910
  lbl_8052b8fc:
  /* 8052B8FC 3BE00000 */ li          r31, 0x0
  /* 8052B900 48000010 */ b           lbl_8052b910
  lbl_8052b904:
  /* 8052B904 3BC00003 */ li          r30, 0x3
  /* 8052B908 48000008 */ b           lbl_8052b910
  lbl_8052b90c:
  /* 8052B90C 3BC00008 */ li          r30, 0x8
  lbl_8052b910:
  /* 8052B910 2C1F0000 */ cmpwi       r31, 0x0
  /* 8052B914 40820030 */ bne-        lbl_8052b944
  /* 8052B918 801800F8 */ lwz         r0, 0xf8(r24)
  /* 8052B91C 5400F0BE */ srwi        r0, r0, 2
  /* 8052B920 7C170016 */ mulhwu      r0, r23, r0
  /* 8052B924 5403D1BE */ srwi        r3, r0, 6
  /* 8052B928 7C03C816 */ mulhwu      r0, r3, r25
  /* 8052B92C 1C830064 */ mulli       r4, r3, 0x64
  /* 8052B930 7C60D214 */ add         r3, r0, r26
  /* 8052B934 4BC7F375 */ bl          OSSleepTicks
  /* 8052B938 3BBD0001 */ addi        r29, r29, 0x1
  /* 8052B93C 2C1D0003 */ cmpwi       r29, 0x3
  /* 8052B940 4180FF4C */ blt+        lbl_8052b88c
  lbl_8052b944:
  /* 8052B944 7FC3F378 */ mr          r3, r30
  /* 8052B948 BAA10014 */ lmw         r21, 0x14(r1)
  /* 8052B94C 80010044 */ lwz         r0, 0x44(r1)
  /* 8052B950 7C0803A6 */ mtlr        r0
  /* 8052B954 38210040 */ addi        r1, r1, 0x40
  /* 8052B958 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_create
// PAL: 0x8052b95c..0x8052ba54
MARK_BINARY_BLOB(NandUtil_create, 0x8052b95c, 0x8052ba54);
asm UNKNOWN_FUNCTION(NandUtil_create){
  // clang-format off
  nofralloc
  /* 8052B95C 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052B960 7C0802A6 */ mflr        r0
  /* 8052B964 3CA01062 */ lis         r5, 0x1062
  /* 8052B968 90010034 */ stw         r0, 0x34(r1)
  /* 8052B96C BEE1000C */ stmw        r23, 0xc(r1)
  /* 8052B970 3B200000 */ li          r25, 0x0
  /* 8052B974 3BC00064 */ li          r30, 0x64
  /* 8052B978 7C771B78 */ mr          r23, r3
  /* 8052B97C 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052B980 7C982378 */ mr          r24, r4
  /* 8052B984 3B854DD3 */ addi        r28, r5, 0x4dd3
  /* 8052B988 3B600001 */ li          r27, 0x1
  /* 8052B98C 3B400008 */ li          r26, 0x8
  /* 8052B990 3FA08000 */ lis         r29, 0x8000
  lbl_8052b994:
  /* 8052B994 7EE3BB78 */ mr          r3, r23
  /* 8052B998 7F04C378 */ mr          r4, r24
  /* 8052B99C 38A00000 */ li          r5, 0x0
  /* 8052B9A0 4BC6FA9D */ bl          NANDCreate
  /* 8052B9A4 38030003 */ addi        r0, r3, 0x3
  /* 8052B9A8 28000001 */ cmplwi      r0, 1
  /* 8052B9AC 40810030 */ ble-        lbl_8052b9dc
  /* 8052B9B0 2C030000 */ cmpwi       r3, 0x0
  /* 8052B9B4 41820020 */ beq-        lbl_8052b9d4
  /* 8052B9B8 2C03FFFA */ cmpwi       r3, -0x6
  /* 8052B9BC 41820018 */ beq-        lbl_8052b9d4
  /* 8052B9C0 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052B9C4 41820030 */ beq-        lbl_8052b9f4
  /* 8052B9C8 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052B9CC 41820030 */ beq-        lbl_8052b9fc
  /* 8052B9D0 48000034 */ b           lbl_8052ba04
  lbl_8052b9d4:
  /* 8052B9D4 3B400000 */ li          r26, 0x0
  /* 8052B9D8 48000030 */ b           lbl_8052ba08
  lbl_8052b9dc:
  /* 8052B9DC 2C190003 */ cmpwi       r25, 0x3
  /* 8052B9E0 4180000C */ blt-        lbl_8052b9ec
  /* 8052B9E4 3B400002 */ li          r26, 0x2
  /* 8052B9E8 48000020 */ b           lbl_8052ba08
  lbl_8052b9ec:
  /* 8052B9EC 3B600000 */ li          r27, 0x0
  /* 8052B9F0 48000018 */ b           lbl_8052ba08
  lbl_8052b9f4:
  /* 8052B9F4 3B400006 */ li          r26, 0x6
  /* 8052B9F8 48000010 */ b           lbl_8052ba08
  lbl_8052b9fc:
  /* 8052B9FC 3B400003 */ li          r26, 0x3
  /* 8052BA00 48000008 */ b           lbl_8052ba08
  lbl_8052ba04:
  /* 8052BA04 3B400008 */ li          r26, 0x8
  lbl_8052ba08:
  /* 8052BA08 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052BA0C 40820030 */ bne-        lbl_8052ba3c
  /* 8052BA10 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052BA14 5400F0BE */ srwi        r0, r0, 2
  /* 8052BA18 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052BA1C 5403D1BE */ srwi        r3, r0, 6
  /* 8052BA20 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052BA24 1C830064 */ mulli       r4, r3, 0x64
  /* 8052BA28 7C60FA14 */ add         r3, r0, r31
  /* 8052BA2C 4BC7F27D */ bl          OSSleepTicks
  /* 8052BA30 3B390001 */ addi        r25, r25, 0x1
  /* 8052BA34 2C190003 */ cmpwi       r25, 0x3
  /* 8052BA38 4180FF5C */ blt+        lbl_8052b994
  lbl_8052ba3c:
  /* 8052BA3C 7F43D378 */ mr          r3, r26
  /* 8052BA40 BAE1000C */ lmw         r23, 0xc(r1)
  /* 8052BA44 80010034 */ lwz         r0, 0x34(r1)
  /* 8052BA48 7C0803A6 */ mtlr        r0
  /* 8052BA4C 38210030 */ addi        r1, r1, 0x30
  /* 8052BA50 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_delete
// PAL: 0x8052ba54..0x8052bb40
MARK_BINARY_BLOB(NandUtil_delete, 0x8052ba54, 0x8052bb40);
asm UNKNOWN_FUNCTION(NandUtil_delete){
  // clang-format off
  nofralloc
  /* 8052BA54 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052BA58 7C0802A6 */ mflr        r0
  /* 8052BA5C 3C801062 */ lis         r4, 0x1062
  /* 8052BA60 90010034 */ stw         r0, 0x34(r1)
  /* 8052BA64 BF010010 */ stmw        r24, 0x10(r1)
  /* 8052BA68 3B200000 */ li          r25, 0x0
  /* 8052BA6C 3BC00064 */ li          r30, 0x64
  /* 8052BA70 7C781B78 */ mr          r24, r3
  /* 8052BA74 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052BA78 3B844DD3 */ addi        r28, r4, 0x4dd3
  /* 8052BA7C 3B600001 */ li          r27, 0x1
  /* 8052BA80 3B400008 */ li          r26, 0x8
  /* 8052BA84 3FA08000 */ lis         r29, 0x8000
  lbl_8052ba88:
  /* 8052BA88 7F03C378 */ mr          r3, r24
  /* 8052BA8C 4BC6FB11 */ bl          NANDDelete
  /* 8052BA90 38030003 */ addi        r0, r3, 0x3
  /* 8052BA94 28000001 */ cmplwi      r0, 1
  /* 8052BA98 40810030 */ ble-        lbl_8052bac8
  /* 8052BA9C 2C030000 */ cmpwi       r3, 0x0
  /* 8052BAA0 41820020 */ beq-        lbl_8052bac0
  /* 8052BAA4 2C03FFF4 */ cmpwi       r3, -0xc
  /* 8052BAA8 41820018 */ beq-        lbl_8052bac0
  /* 8052BAAC 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052BAB0 41820030 */ beq-        lbl_8052bae0
  /* 8052BAB4 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052BAB8 41820030 */ beq-        lbl_8052bae8
  /* 8052BABC 48000034 */ b           lbl_8052baf0
  lbl_8052bac0:
  /* 8052BAC0 3B400000 */ li          r26, 0x0
  /* 8052BAC4 48000030 */ b           lbl_8052baf4
  lbl_8052bac8:
  /* 8052BAC8 2C190003 */ cmpwi       r25, 0x3
  /* 8052BACC 4180000C */ blt-        lbl_8052bad8
  /* 8052BAD0 3B400002 */ li          r26, 0x2
  /* 8052BAD4 48000020 */ b           lbl_8052baf4
  lbl_8052bad8:
  /* 8052BAD8 3B600000 */ li          r27, 0x0
  /* 8052BADC 48000018 */ b           lbl_8052baf4
  lbl_8052bae0:
  /* 8052BAE0 3B400006 */ li          r26, 0x6
  /* 8052BAE4 48000010 */ b           lbl_8052baf4
  lbl_8052bae8:
  /* 8052BAE8 3B400003 */ li          r26, 0x3
  /* 8052BAEC 48000008 */ b           lbl_8052baf4
  lbl_8052baf0:
  /* 8052BAF0 3B400008 */ li          r26, 0x8
  lbl_8052baf4:
  /* 8052BAF4 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052BAF8 40820030 */ bne-        lbl_8052bb28
  /* 8052BAFC 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052BB00 5400F0BE */ srwi        r0, r0, 2
  /* 8052BB04 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052BB08 5403D1BE */ srwi        r3, r0, 6
  /* 8052BB0C 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052BB10 1C830064 */ mulli       r4, r3, 0x64
  /* 8052BB14 7C60FA14 */ add         r3, r0, r31
  /* 8052BB18 4BC7F191 */ bl          OSSleepTicks
  /* 8052BB1C 3B390001 */ addi        r25, r25, 0x1
  /* 8052BB20 2C190003 */ cmpwi       r25, 0x3
  /* 8052BB24 4180FF64 */ blt+        lbl_8052ba88
  lbl_8052bb28:
  /* 8052BB28 7F43D378 */ mr          r3, r26
  /* 8052BB2C BB010010 */ lmw         r24, 0x10(r1)
  /* 8052BB30 80010034 */ lwz         r0, 0x34(r1)
  /* 8052BB34 7C0803A6 */ mtlr        r0
  /* 8052BB38 38210030 */ addi        r1, r1, 0x30
  /* 8052BB3C 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_setStatus
// PAL: 0x8052bb40..0x8052bc3c
MARK_BINARY_BLOB(NandUtil_setStatus, 0x8052bb40, 0x8052bc3c);
asm UNKNOWN_FUNCTION(NandUtil_setStatus){
  // clang-format off
  nofralloc
  /* 8052BB40 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052BB44 7C0802A6 */ mflr        r0
  /* 8052BB48 3CA01062 */ lis         r5, 0x1062
  /* 8052BB4C 90010034 */ stw         r0, 0x34(r1)
  /* 8052BB50 BEE1000C */ stmw        r23, 0xc(r1)
  /* 8052BB54 3B200000 */ li          r25, 0x0
  /* 8052BB58 3BC00064 */ li          r30, 0x64
  /* 8052BB5C 7C771B78 */ mr          r23, r3
  /* 8052BB60 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052BB64 7C982378 */ mr          r24, r4
  /* 8052BB68 3B854DD3 */ addi        r28, r5, 0x4dd3
  /* 8052BB6C 3B600001 */ li          r27, 0x1
  /* 8052BB70 3B400008 */ li          r26, 0x8
  /* 8052BB74 3FA08000 */ lis         r29, 0x8000
  lbl_8052bb78:
  /* 8052BB78 7EE3BB78 */ mr          r3, r23
  /* 8052BB7C 7F04C378 */ mr          r4, r24
  /* 8052BB80 4BC70A95 */ bl          NANDSetStatus
  /* 8052BB84 38030003 */ addi        r0, r3, 0x3
  /* 8052BB88 28000001 */ cmplwi      r0, 1
  /* 8052BB8C 40810030 */ ble-        lbl_8052bbbc
  /* 8052BB90 2C030000 */ cmpwi       r3, 0x0
  /* 8052BB94 41820020 */ beq-        lbl_8052bbb4
  /* 8052BB98 2C03FFF4 */ cmpwi       r3, -0xc
  /* 8052BB9C 41820038 */ beq-        lbl_8052bbd4
  /* 8052BBA0 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052BBA4 41820038 */ beq-        lbl_8052bbdc
  /* 8052BBA8 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052BBAC 41820038 */ beq-        lbl_8052bbe4
  /* 8052BBB0 4800003C */ b           lbl_8052bbec
  lbl_8052bbb4:
  /* 8052BBB4 3B400000 */ li          r26, 0x0
  /* 8052BBB8 48000038 */ b           lbl_8052bbf0
  lbl_8052bbbc:
  /* 8052BBBC 2C190003 */ cmpwi       r25, 0x3
  /* 8052BBC0 4180000C */ blt-        lbl_8052bbcc
  /* 8052BBC4 3B400002 */ li          r26, 0x2
  /* 8052BBC8 48000028 */ b           lbl_8052bbf0
  lbl_8052bbcc:
  /* 8052BBCC 3B600000 */ li          r27, 0x0
  /* 8052BBD0 48000020 */ b           lbl_8052bbf0
  lbl_8052bbd4:
  /* 8052BBD4 3B400004 */ li          r26, 0x4
  /* 8052BBD8 48000018 */ b           lbl_8052bbf0
  lbl_8052bbdc:
  /* 8052BBDC 3B400006 */ li          r26, 0x6
  /* 8052BBE0 48000010 */ b           lbl_8052bbf0
  lbl_8052bbe4:
  /* 8052BBE4 3B400003 */ li          r26, 0x3
  /* 8052BBE8 48000008 */ b           lbl_8052bbf0
  lbl_8052bbec:
  /* 8052BBEC 3B400008 */ li          r26, 0x8
  lbl_8052bbf0:
  /* 8052BBF0 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052BBF4 40820030 */ bne-        lbl_8052bc24
  /* 8052BBF8 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052BBFC 5400F0BE */ srwi        r0, r0, 2
  /* 8052BC00 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052BC04 5403D1BE */ srwi        r3, r0, 6
  /* 8052BC08 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052BC0C 1C830064 */ mulli       r4, r3, 0x64
  /* 8052BC10 7C60FA14 */ add         r3, r0, r31
  /* 8052BC14 4BC7F095 */ bl          OSSleepTicks
  /* 8052BC18 3B390001 */ addi        r25, r25, 0x1
  /* 8052BC1C 2C190003 */ cmpwi       r25, 0x3
  /* 8052BC20 4180FF58 */ blt+        lbl_8052bb78
  lbl_8052bc24:
  /* 8052BC24 7F43D378 */ mr          r3, r26
  /* 8052BC28 BAE1000C */ lmw         r23, 0xc(r1)
  /* 8052BC2C 80010034 */ lwz         r0, 0x34(r1)
  /* 8052BC30 7C0803A6 */ mtlr        r0
  /* 8052BC34 38210030 */ addi        r1, r1, 0x30
  /* 8052BC38 4E800020 */ blr
  // clang-format on
}

// Symbol: NandUtil_getStatus
// PAL: 0x8052bc3c..0x8052bd38
MARK_BINARY_BLOB(NandUtil_getStatus, 0x8052bc3c, 0x8052bd38);
asm int NandUtil_getStatus(void*, void*) {
  // clang-format off
  nofralloc
  /* 8052BC3C 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052BC40 7C0802A6 */ mflr        r0
  /* 8052BC44 3CA01062 */ lis         r5, 0x1062
  /* 8052BC48 90010034 */ stw         r0, 0x34(r1)
  /* 8052BC4C BEE1000C */ stmw        r23, 0xc(r1)
  /* 8052BC50 3B200000 */ li          r25, 0x0
  /* 8052BC54 3BC00064 */ li          r30, 0x64
  /* 8052BC58 7C771B78 */ mr          r23, r3
  /* 8052BC5C 7FF9F1D6 */ mullw       r31, r25, r30
  /* 8052BC60 7C982378 */ mr          r24, r4
  /* 8052BC64 3B854DD3 */ addi        r28, r5, 0x4dd3
  /* 8052BC68 3B600001 */ li          r27, 0x1
  /* 8052BC6C 3B400008 */ li          r26, 0x8
  /* 8052BC70 3FA08000 */ lis         r29, 0x8000
  lbl_8052bc74:
  /* 8052BC74 7EE3BB78 */ mr          r3, r23
  /* 8052BC78 7F04C378 */ mr          r4, r24
  /* 8052BC7C 4BC70705 */ bl          NANDGetStatus
  /* 8052BC80 38030003 */ addi        r0, r3, 0x3
  /* 8052BC84 28000001 */ cmplwi      r0, 1
  /* 8052BC88 40810030 */ ble-        lbl_8052bcb8
  /* 8052BC8C 2C030000 */ cmpwi       r3, 0x0
  /* 8052BC90 41820020 */ beq-        lbl_8052bcb0
  /* 8052BC94 2C03FFF4 */ cmpwi       r3, -0xc
  /* 8052BC98 41820038 */ beq-        lbl_8052bcd0
  /* 8052BC9C 2C03FFFC */ cmpwi       r3, -0x4
  /* 8052BCA0 41820038 */ beq-        lbl_8052bcd8
  /* 8052BCA4 2C03FFFF */ cmpwi       r3, -0x1
  /* 8052BCA8 41820038 */ beq-        lbl_8052bce0
  /* 8052BCAC 4800003C */ b           lbl_8052bce8
  lbl_8052bcb0:
  /* 8052BCB0 3B400000 */ li          r26, 0x0
  /* 8052BCB4 48000038 */ b           lbl_8052bcec
  lbl_8052bcb8:
  /* 8052BCB8 2C190003 */ cmpwi       r25, 0x3
  /* 8052BCBC 4180000C */ blt-        lbl_8052bcc8
  /* 8052BCC0 3B400002 */ li          r26, 0x2
  /* 8052BCC4 48000028 */ b           lbl_8052bcec
  lbl_8052bcc8:
  /* 8052BCC8 3B600000 */ li          r27, 0x0
  /* 8052BCCC 48000020 */ b           lbl_8052bcec
  lbl_8052bcd0:
  /* 8052BCD0 3B400004 */ li          r26, 0x4
  /* 8052BCD4 48000018 */ b           lbl_8052bcec
  lbl_8052bcd8:
  /* 8052BCD8 3B400006 */ li          r26, 0x6
  /* 8052BCDC 48000010 */ b           lbl_8052bcec
  lbl_8052bce0:
  /* 8052BCE0 3B400003 */ li          r26, 0x3
  /* 8052BCE4 48000008 */ b           lbl_8052bcec
  lbl_8052bce8:
  /* 8052BCE8 3B400008 */ li          r26, 0x8
  lbl_8052bcec:
  /* 8052BCEC 2C1B0000 */ cmpwi       r27, 0x0
  /* 8052BCF0 40820030 */ bne-        lbl_8052bd20
  /* 8052BCF4 801D00F8 */ lwz         r0, 0xf8(r29)
  /* 8052BCF8 5400F0BE */ srwi        r0, r0, 2
  /* 8052BCFC 7C1C0016 */ mulhwu      r0, r28, r0
  /* 8052BD00 5403D1BE */ srwi        r3, r0, 6
  /* 8052BD04 7C03F016 */ mulhwu      r0, r3, r30
  /* 8052BD08 1C830064 */ mulli       r4, r3, 0x64
  /* 8052BD0C 7C60FA14 */ add         r3, r0, r31
  /* 8052BD10 4BC7EF99 */ bl          OSSleepTicks
  /* 8052BD14 3B390001 */ addi        r25, r25, 0x1
  /* 8052BD18 2C190003 */ cmpwi       r25, 0x3
  /* 8052BD1C 4180FF58 */ blt+        lbl_8052bc74
  lbl_8052bd20:
  /* 8052BD20 7F43D378 */ mr          r3, r26
  /* 8052BD24 BAE1000C */ lmw         r23, 0xc(r1)
  /* 8052BD28 80010034 */ lwz         r0, 0x34(r1)
  /* 8052BD2C 7C0803A6 */ mtlr        r0
  /* 8052BD30 38210030 */ addi        r1, r1, 0x30
  /* 8052BD34 4E800020 */ blr
  // clang-format on
}

void unk_8052bd38(void* first) {
  u16 tmp[4];
  NandUtil_getStatus(first, &tmp[0]);
}
