// Symbol: nandCreate
// Function signature is unknown.
// PAL: 0x8019b314..0x8019b43c
asm void nandCreate(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 0x18(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0x1c(r1);
  mr r30, r7;
  mr r31, r8;
  addi r3, r1, 0x18;
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x10(r1);
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019b3b8;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019b3b8;
  li r3, -102;
  b lbl_8019b424;
lbl_8019b3b8:
  rlwinm. r0, r27, 0, 0x1b, 0x1b;
  bne lbl_8019b3c8;
  li r3, -101;
  b lbl_8019b424;
lbl_8019b3c8:
  mr r3, r27;
  addi r4, r1, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019b40c;
  lis r8, 0x801a;
  lwz r5, 0x10(r1);
  lwz r6, 0xc(r1);
  mr r4, r28;
  lwz r7, 8(r1);
  mr r9, r29;
  addi r3, r1, 0x18;
  addi r8, r8, -7072;
  bl 0x8016ad68;
  b lbl_8019b424;
lbl_8019b40c:
  lwz r5, 0x10(r1);
  mr r4, r28;
  lwz r6, 0xc(r1);
  addi r3, r1, 0x18;
  lwz r7, 8(r1);
  bl 0x8016ac74;
lbl_8019b424:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: NANDCreate
// Function signature is unknown.
// PAL: 0x8019b43c..0x8019b4b0
asm void NANDCreate(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019b490;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl nandCreate;
  bl nandConvertErrorCode;
  b lbl_8019b494;
lbl_8019b490:
  li r3, -128;
lbl_8019b494:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateCreate
// Function signature is unknown.
// PAL: 0x8019b4b0..0x8019b524
asm void NANDPrivateCreate(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019b504;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 1;
  bl nandCreate;
  bl nandConvertErrorCode;
  b lbl_8019b508;
lbl_8019b504:
  li r3, -128;
lbl_8019b508:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateCreateAsync
// Function signature is unknown.
// PAL: 0x8019b524..0x8019b59c
asm void NANDPrivateCreateAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b560;
  li r3, -128;
  b lbl_8019b584;
lbl_8019b560:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r28;
  mr r5, r29;
  mr r6, r31;
  li r7, 1;
  li r8, 1;
  bl nandCreate;
  bl nandConvertErrorCode;
lbl_8019b584:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDDelete
// Function signature is unknown.
// PAL: 0x8019b59c..0x8019b64c
asm void NANDDelete(void) {
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b5c4;
  li r3, -128;
  b lbl_8019b638;
lbl_8019b5c4:
  li r0, 0;
  mr r4, r31;
  stw r0, 8(r1);
  addi r3, r1, 8;
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019b62c;
  li r3, -102;
  b lbl_8019b634;
lbl_8019b62c:
  addi r3, r1, 8;
  bl 0x8016a78c;
lbl_8019b634:
  bl nandConvertErrorCode;
lbl_8019b638:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
}

// Symbol: NANDPrivateDelete
// Function signature is unknown.
// PAL: 0x8019b64c..0x8019b6e4
asm void NANDPrivateDelete(void) {
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b674;
  li r3, -128;
  b lbl_8019b6d0;
lbl_8019b674:
  li r0, 0;
  mr r4, r31;
  stw r0, 8(r1);
  addi r3, r1, 8;
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  bl 0x8016a78c;
  bl nandConvertErrorCode;
lbl_8019b6d0:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
}

// Symbol: NANDPrivateDeleteAsync
// Function signature is unknown.
// PAL: 0x8019b6e4..0x8019b7a4
asm void NANDPrivateDeleteAsync(void) {
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stw r31, 0x5c(r1);
  mr r31, r5;
  stw r30, 0x58(r1);
  mr r30, r4;
  stw r29, 0x54(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b71c;
  li r3, -128;
  b lbl_8019b788;
lbl_8019b71c:
  stw r30, 4(r31);
  li r0, 0;
  mr r4, r29;
  addi r3, r1, 8;
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  lis r4, 0x801a;
  mr r5, r31;
  addi r3, r1, 8;
  addi r4, r4, -7072;
  bl 0x8016a864;
  bl nandConvertErrorCode;
lbl_8019b788:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
}

// Symbol: NANDRead
// Function signature is unknown.
// PAL: 0x8019b7a4..0x8019b80c
asm void NANDRead(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019b7ec;
  lwz r3, 0(r29);
  mr r4, r30;
  mr r5, r31;
  bl 0x8016b1fc;
  bl nandConvertErrorCode;
  b lbl_8019b7f0;
lbl_8019b7ec:
  li r3, -128;
lbl_8019b7f0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDReadAsync
// Function signature is unknown.
// PAL: 0x8019b80c..0x8019b884
asm void NANDReadAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b848;
  li r3, -128;
  b lbl_8019b86c;
lbl_8019b848:
  stw r30, 4(r31);
  lis r6, 0x801a;
  mr r4, r28;
  mr r5, r29;
  lwz r3, 0(r27);
  mr r7, r31;
  addi r6, r6, -7072;
  bl 0x8016b21c;
  bl nandConvertErrorCode;
lbl_8019b86c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDWrite
// Function signature is unknown.
// PAL: 0x8019b884..0x8019b8ec
asm void NANDWrite(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019b8cc;
  lwz r3, 0(r29);
  mr r4, r30;
  mr r5, r31;
  bl 0x8016b2c0;
  bl nandConvertErrorCode;
  b lbl_8019b8d0;
lbl_8019b8cc:
  li r3, -128;
lbl_8019b8d0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDWriteAsync
// Function signature is unknown.
// PAL: 0x8019b8ec..0x8019b964
asm void NANDWriteAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b928;
  li r3, -128;
  b lbl_8019b94c;
lbl_8019b928:
  stw r30, 4(r31);
  lis r6, 0x801a;
  mr r4, r28;
  mr r5, r29;
  lwz r3, 0(r27);
  mr r7, r31;
  addi r6, r6, -7072;
  bl 0x8016b2e0;
  bl nandConvertErrorCode;
lbl_8019b94c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSeek
// Function signature is unknown.
// PAL: 0x8019b964..0x8019ba04
asm void NANDSeek(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019b99c;
  li r3, -128;
  b lbl_8019b9e8;
lbl_8019b99c:
  cmpwi r31, 1;
  lwz r3, 0(r29);
  li r5, -1;
  beq lbl_8019b9d0;
  bge lbl_8019b9bc;
  cmpwi r31, 0;
  bge lbl_8019b9c8;
  b lbl_8019b9dc;
lbl_8019b9bc:
  cmpwi r31, 3;
  bge lbl_8019b9dc;
  b lbl_8019b9d8;
lbl_8019b9c8:
  li r5, 0;
  b lbl_8019b9dc;
lbl_8019b9d0:
  li r5, 1;
  b lbl_8019b9dc;
lbl_8019b9d8:
  li r5, 2;
lbl_8019b9dc:
  mr r4, r30;
  bl 0x8016b16c;
  bl nandConvertErrorCode;
lbl_8019b9e8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSeekAsync
// Function signature is unknown.
// PAL: 0x8019ba04..0x8019bab4
asm void NANDSeekAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019ba40;
  li r3, -128;
  b lbl_8019ba9c;
lbl_8019ba40:
  stw r30, 4(r31);
  cmpwi r29, 1;
  li r5, -1;
  lwz r3, 0(r27);
  beq lbl_8019ba78;
  bge lbl_8019ba64;
  cmpwi r29, 0;
  bge lbl_8019ba70;
  b lbl_8019ba84;
lbl_8019ba64:
  cmpwi r29, 3;
  bge lbl_8019ba84;
  b lbl_8019ba80;
lbl_8019ba70:
  li r5, 0;
  b lbl_8019ba84;
lbl_8019ba78:
  li r5, 1;
  b lbl_8019ba84;
lbl_8019ba80:
  li r5, 2;
lbl_8019ba84:
  lis r6, 0x801a;
  mr r4, r28;
  mr r7, r31;
  addi r6, r6, -7072;
  bl 0x8016b170;
  bl nandConvertErrorCode;
lbl_8019ba9c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandCreateDir
// Function signature is unknown.
// PAL: 0x8019bab4..0x8019bbe0
asm void nandCreateDir(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 0x18(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0x1c(r1);
  mr r30, r7;
  mr r31, r8;
  addi r3, r1, 0x18;
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019bb4c;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019bb4c;
  li r3, -102;
  b lbl_8019bbc8;
lbl_8019bb4c:
  rlwinm. r0, r27, 0, 0x1b, 0x1b;
  bne lbl_8019bb5c;
  li r3, -101;
  b lbl_8019bbc8;
lbl_8019bb5c:
  li r0, 0;
  mr r3, r27;
  stw r0, 0x10(r1);
  addi r4, r1, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019bbb0;
  lis r8, 0x801a;
  lwz r5, 0x10(r1);
  lwz r6, 0xc(r1);
  mr r4, r28;
  lwz r7, 8(r1);
  mr r9, r29;
  addi r3, r1, 0x18;
  addi r8, r8, -7072;
  bl 0x80169f68;
  b lbl_8019bbc8;
lbl_8019bbb0:
  lwz r5, 0x10(r1);
  mr r4, r28;
  lwz r6, 0xc(r1);
  addi r3, r1, 0x18;
  lwz r7, 8(r1);
  bl 0x80169e74;
lbl_8019bbc8:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: NANDCreateDir
// Function signature is unknown.
// PAL: 0x8019bbe0..0x8019bc54
asm void NANDCreateDir(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019bc34;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  bl nandCreateDir;
  bl nandConvertErrorCode;
  b lbl_8019bc38;
lbl_8019bc34:
  li r3, -128;
lbl_8019bc38:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateCreateDir
// Function signature is unknown.
// PAL: 0x8019bc54..0x8019bcc8
asm void NANDPrivateCreateDir(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019bca8;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  li r8, 1;
  bl nandCreateDir;
  bl nandConvertErrorCode;
  b lbl_8019bcac;
lbl_8019bca8:
  li r3, -128;
lbl_8019bcac:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateCreateDirAsync
// Function signature is unknown.
// PAL: 0x8019bcc8..0x8019bd40
asm void NANDPrivateCreateDirAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019bd04;
  li r3, -128;
  b lbl_8019bd28;
lbl_8019bd04:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r28;
  mr r5, r29;
  mr r6, r31;
  li r7, 1;
  li r8, 1;
  bl nandCreateDir;
  bl nandConvertErrorCode;
lbl_8019bd28:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandMove
// Function signature is unknown.
// PAL: 0x8019bd40..0x8019bee8
asm void nandMove(void) {
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  li r0, 0;
  stw r31, 0xac(r1);
  mr r31, r7;
  stw r30, 0xa8(r1);
  mr r30, r6;
  stw r29, 0xa4(r1);
  mr r29, r5;
  stw r28, 0xa0(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x58;
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  stw r0, 0x60(r1);
  stw r0, 0x64(r1);
  stw r0, 0x68(r1);
  stw r0, 0x6c(r1);
  stw r0, 0x70(r1);
  stw r0, 0x74(r1);
  stw r0, 0x78(r1);
  stw r0, 0x7c(r1);
  stw r0, 0x80(r1);
  stw r0, 0x84(r1);
  stw r0, 0x88(r1);
  stw r0, 0x8c(r1);
  stw r0, 0x90(r1);
  stw r0, 0x94(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stb r0, 0x14(r1);
  bl nandGenerateAbsPath;
  addi r3, r1, 8;
  addi r4, r1, 0x58;
  bl nandGetRelativeName;
  mr r4, r28;
  addi r3, r1, 0x18;
  bl nandGenerateAbsPath;
  addi r3, r1, 0x18;
  addi r4, r13, -29168;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019be50;
  addi r3, r1, 0x18;
  addi r5, r1, 8;
  addi r4, r13, -29164;
  crclr 6;
  bl sprintf;
  b lbl_8019be68;
lbl_8019be50:
  addi r3, r1, 0x18;
  addi r4, r13, -29168;
  bl strcat;
  addi r3, r1, 0x18;
  addi r4, r1, 8;
  bl strcat;
lbl_8019be68:
  cmpwi r31, 0;
  bne lbl_8019be98;
  addi r3, r1, 0x58;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  bne lbl_8019be90;
  addi r3, r1, 0x18;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019be98;
lbl_8019be90:
  li r3, -102;
  b lbl_8019bec8;
lbl_8019be98:
  cmpwi r30, 0;
  beq lbl_8019bebc;
  lis r5, 0x801a;
  mr r6, r29;
  addi r3, r1, 0x58;
  addi r4, r1, 0x18;
  addi r5, r5, -7072;
  bl 0x8016aa38;
  b lbl_8019bec8;
lbl_8019bebc:
  addi r3, r1, 0x58;
  addi r4, r1, 0x18;
  bl 0x8016a934;
lbl_8019bec8:
  lwz r0, 0xb4(r1);
  lwz r31, 0xac(r1);
  lwz r30, 0xa8(r1);
  lwz r29, 0xa4(r1);
  lwz r28, 0xa0(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
}

// Symbol: NANDMove
// Function signature is unknown.
// PAL: 0x8019bee8..0x8019bf4c
asm void NANDMove(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019bf30;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandMove;
  bl nandConvertErrorCode;
  b lbl_8019bf34;
lbl_8019bf30:
  li r3, -128;
lbl_8019bf34:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetLength
// Function signature is unknown.
// PAL: 0x8019bf4c..0x8019bfd4
asm void NANDGetLength(void) {
  nofralloc;
  clrlwi r11, r1, 0x1b;
  mr r12, r1;
  subfic r11, r11, -96;
  stwux r1, r1, r11;
  mflr r0;
  stw r0, 4(r12);
  stw r31, -4(r12);
  mr r31, r4;
  stw r30, -8(r12);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019bf88;
  li r3, -128;
  b lbl_8019bfb8;
lbl_8019bf88:
  lwz r3, 0(r30);
  addi r4, r1, 0x20;
  bl 0x8016afdc;
  cmpwi r3, 0;
  bne lbl_8019bfb4;
  cmpwi r31, 0;
  beq lbl_8019bfb4;
  lwz r0, 0x20(r1);
  stw r0, 0(r31);
  b lbl_8019bfb4;
  stw r0, 0(0);
lbl_8019bfb4:
  bl nandConvertErrorCode;
lbl_8019bfb8:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  lwz r30, -8(r10);
  mtlr r0;
  mr r1, r10;
  blr;
}

// Symbol: nandGetFileStatusAsyncCallback
// Function signature is unknown.
// PAL: 0x8019bfd4..0x8019c048
asm void nandGetFileStatusAsyncCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  addi r0, r4, 0x53;
  rlwinm r6, r0, 0, 0, 0x1a;
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019c020;
  lwz r5, 0x74(r4);
  cmpwi r5, 0;
  beq lbl_8019c00c;
  lwz r0, 0(r6);
  stw r0, 0(r5);
lbl_8019c00c:
  lwz r4, 0x78(r4);
  cmpwi r4, 0;
  beq lbl_8019c020;
  lwz r0, 4(r6);
  stw r0, 0(r4);
lbl_8019c020:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetLengthAsync
// Function signature is unknown.
// PAL: 0x8019c048..0x8019c0d8
asm void NANDGetLengthAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c088;
  li r3, -128;
  b lbl_8019c0b8;
lbl_8019c088:
  li r3, 0;
  addi r0, r31, 0x53;
  stw r30, 4(r31);
  lis r5, 0x801a;
  mr r6, r31;
  rlwinm r4, r0, 0, 0, 0x1a;
  stw r29, 0x74(r31);
  addi r5, r5, -16428;
  stw r3, 0x78(r31);
  lwz r3, 0(r28);
  bl 0x8016b0ac;
  bl nandConvertErrorCode;
lbl_8019c0b8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandComposePerm
// Function signature is unknown.
// PAL: 0x8019c0d8..0x8019c12c
asm void nandComposePerm(void) {
  nofralloc;
  clrlwi. r0, r4, 0x1f;
  li r7, 0;
  beq lbl_8019c0e8;
  ori r7, r7, 0x10;
lbl_8019c0e8:
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  beq lbl_8019c0f4;
  ori r7, r7, 0x20;
lbl_8019c0f4:
  clrlwi. r0, r5, 0x1f;
  beq lbl_8019c100;
  ori r7, r7, 4;
lbl_8019c100:
  rlwinm. r0, r5, 0, 0x1e, 0x1e;
  beq lbl_8019c10c;
  ori r7, r7, 8;
lbl_8019c10c:
  clrlwi. r0, r6, 0x1f;
  beq lbl_8019c118;
  ori r7, r7, 1;
lbl_8019c118:
  rlwinm. r0, r6, 0, 0x1e, 0x1e;
  beq lbl_8019c124;
  ori r7, r7, 2;
lbl_8019c124:
  stb r7, 0(r3);
  blr;
}

// Symbol: nandSplitPerm
// Function signature is unknown.
// PAL: 0x8019c12c..0x8019c1b8
asm void nandSplitPerm(void) {
  nofralloc;
  li r7, 0;
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  stw r7, 0(r4);
  stw r7, 0(r5);
  stw r7, 0(r6);
  beq lbl_8019c150;
  lwz r0, 0(r4);
  ori r0, r0, 1;
  stw r0, 0(r4);
lbl_8019c150:
  rlwinm. r0, r3, 0, 0x1a, 0x1a;
  beq lbl_8019c164;
  lwz r0, 0(r4);
  ori r0, r0, 2;
  stw r0, 0(r4);
lbl_8019c164:
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8019c178;
  lwz r0, 0(r5);
  ori r0, r0, 1;
  stw r0, 0(r5);
lbl_8019c178:
  rlwinm. r0, r3, 0, 0x1c, 0x1c;
  beq lbl_8019c18c;
  lwz r0, 0(r5);
  ori r0, r0, 2;
  stw r0, 0(r5);
lbl_8019c18c:
  clrlwi. r0, r3, 0x1f;
  beq lbl_8019c1a0;
  lwz r0, 0(r6);
  ori r0, r0, 1;
  stw r0, 0(r6);
lbl_8019c1a0:
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  beqlr;
  lwz r0, 0(r6);
  ori r0, r0, 2;
  stw r0, 0(r6);
  blr;
}

// Symbol: nandGetStatus
// Function signature is unknown.
// PAL: 0x8019c1b8..0x8019c30c
asm void nandGetStatus(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  li r0, 0;
  stw r31, 0x6c(r1);
  mr r31, r7;
  stw r30, 0x68(r1);
  mr r30, r6;
  stw r29, 0x64(r1);
  mr r29, r5;
  stw r28, 0x60(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x20;
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019c254;
  addi r3, r1, 0x20;
  bl nandIsUnderPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c254;
  li r3, -102;
  b lbl_8019c2ec;
lbl_8019c254:
  cmpwi r30, 0;
  beq lbl_8019c28c;
  lis r10, 0x801a;
  stw r29, 8(r1);
  mr r4, r28;
  addi r3, r1, 0x20;
  addi r5, r28, 4;
  addi r6, r29, 0x20;
  addi r7, r29, 0x24;
  addi r8, r29, 0x28;
  addi r9, r29, 0x2c;
  addi r10, r10, -15604;
  bl 0x8016a658;
  b lbl_8019c2ec;
lbl_8019c28c:
  li r0, 0;
  mr r4, r28;
  stw r0, 0x1c(r1);
  addi r3, r1, 0x20;
  addi r5, r28, 4;
  addi r6, r1, 0x1c;
  stw r0, 0x18(r1);
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  bl 0x8016a500;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8019c2e8;
  lwz r4, 0x18(r1);
  addi r3, r28, 7;
  lwz r5, 0x14(r1);
  lwz r6, 0x10(r1);
  bl nandComposePerm;
  lwz r0, 0x1c(r1);
  stb r0, 6(r28);
lbl_8019c2e8:
  mr r3, r31;
lbl_8019c2ec:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  lwz r29, 0x64(r1);
  lwz r28, 0x60(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: nandGetStatusCallback
// Function signature is unknown.
// PAL: 0x8019c30c..0x8019c380
asm void nandGetStatusCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bne lbl_8019c350;
  lwz r5, 0x14(r4);
  lwz r0, 0x20(r4);
  addi r3, r5, 7;
  stb r0, 6(r5);
  lwz r4, 0x24(r4);
  lwz r5, 0x28(r31);
  lwz r6, 0x2c(r31);
  bl nandComposePerm;
lbl_8019c350:
  mr r3, r30;
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetStatus
// Function signature is unknown.
// PAL: 0x8019c380..0x8019c3e4
asm void NANDGetStatus(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c3c8;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandGetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c3cc;
lbl_8019c3c8:
  li r3, -128;
lbl_8019c3cc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateGetStatus
// Function signature is unknown.
// PAL: 0x8019c3e4..0x8019c448
asm void NANDPrivateGetStatus(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c42c;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandGetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c430;
lbl_8019c42c:
  li r3, -128;
lbl_8019c430:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateGetStatusAsync
// Function signature is unknown.
// PAL: 0x8019c448..0x8019c4cc
asm void NANDPrivateGetStatusAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c488;
  li r3, -128;
  b lbl_8019c4ac;
lbl_8019c488:
  stw r30, 4(r31);
  mr r3, r28;
  mr r4, r29;
  mr r5, r31;
  stw r29, 0x14(r31);
  li r6, 1;
  li r7, 1;
  bl nandGetStatus;
  bl nandConvertErrorCode;
lbl_8019c4ac:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandSetStatus
// Function signature is unknown.
// PAL: 0x8019c4cc..0x8019c614
asm void nandSetStatus(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  li r0, 0;
  stw r31, 0x6c(r1);
  mr r31, r7;
  stw r30, 0x68(r1);
  mr r30, r6;
  stw r29, 0x64(r1);
  mr r29, r5;
  stw r28, 0x60(r1);
  mr r28, r4;
  mr r4, r3;
  addi r3, r1, 0x20;
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  stw r0, 0x50(r1);
  stw r0, 0x54(r1);
  stw r0, 0x58(r1);
  stw r0, 0x5c(r1);
  bl nandGenerateAbsPath;
  cmpwi r31, 0;
  bne lbl_8019c568;
  addi r3, r1, 0x20;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c568;
  li r3, -102;
  b lbl_8019c5f4;
lbl_8019c568:
  lbz r3, 7(r28);
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  bne lbl_8019c57c;
  li r3, -101;
  b lbl_8019c5f4;
lbl_8019c57c:
  li r0, 0;
  addi r4, r1, 0x18;
  stw r0, 0x18(r1);
  addi r5, r1, 0x14;
  addi r6, r1, 0x10;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  bl nandSplitPerm;
  cmpwi r30, 0;
  beq lbl_8019c5d4;
  stw r29, 8(r1);
  lis r10, 0x801a;
  lwz r4, 0(r28);
  addi r3, r1, 0x20;
  lhz r5, 4(r28);
  addi r10, r10, -7072;
  lbz r6, 6(r28);
  lwz r7, 0x18(r1);
  lwz r8, 0x14(r1);
  lwz r9, 0x10(r1);
  bl 0x8016a3fc;
  b lbl_8019c5f4;
lbl_8019c5d4:
  lwz r4, 0(r28);
  addi r3, r1, 0x20;
  lhz r5, 4(r28);
  lbz r6, 6(r28);
  lwz r7, 0x18(r1);
  lwz r8, 0x14(r1);
  lwz r9, 0x10(r1);
  bl 0x8016a2f8;
lbl_8019c5f4:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  lwz r29, 0x64(r1);
  lwz r28, 0x60(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: NANDSetStatus
// Function signature is unknown.
// PAL: 0x8019c614..0x8019c678
asm void NANDSetStatus(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c65c;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandSetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c660;
lbl_8019c65c:
  li r3, -128;
lbl_8019c660:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateSetStatus
// Function signature is unknown.
// PAL: 0x8019c678..0x8019c6dc
asm void NANDPrivateSetStatus(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  beq lbl_8019c6c0;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandSetStatus;
  bl nandConvertErrorCode;
  b lbl_8019c6c4;
lbl_8019c6c0:
  li r3, -128;
lbl_8019c6c4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDSetUserData
// Function signature is unknown.
// PAL: 0x8019c6dc..0x8019c6e4
asm void NANDSetUserData(void) {
  nofralloc;
  stw r4, 0(r3);
  blr;
}

// Symbol: NANDGetUserData
// Function signature is unknown.
// PAL: 0x8019c6e4..0x8019c6ec
asm void NANDGetUserData(void) {
  nofralloc;
  lwz r3, 0(r3);
  blr;
}

// Symbol: nandOpen
// Function signature is unknown.
// PAL: 0x8019c6ec..0x8019c800
asm void nandOpen(void) {
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_27;
  li r0, 0;
  mr r27, r4;
  stw r0, 8(r1);
  mr r4, r3;
  mr r28, r5;
  mr r29, r6;
  stw r0, 0xc(r1);
  mr r30, r7;
  addi r3, r1, 8;
  li r31, 0;
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  cmpwi r30, 0;
  bne lbl_8019c784;
  addi r3, r1, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019c784;
  li r3, -102;
  b lbl_8019c7e8;
lbl_8019c784:
  cmpwi r27, 2;
  beq lbl_8019c7b4;
  bge lbl_8019c79c;
  cmpwi r27, 1;
  bge lbl_8019c7ac;
  b lbl_8019c7b8;
lbl_8019c79c:
  cmpwi r27, 4;
  bge lbl_8019c7b8;
  li r31, 3;
  b lbl_8019c7b8;
lbl_8019c7ac:
  li r31, 1;
  b lbl_8019c7b8;
lbl_8019c7b4:
  li r31, 2;
lbl_8019c7b8:
  cmpwi r29, 0;
  beq lbl_8019c7dc;
  lis r5, 0x801a;
  mr r4, r31;
  mr r6, r28;
  addi r3, r1, 8;
  addi r5, r5, -13816;
  bl 0x8016af24;
  b lbl_8019c7e8;
lbl_8019c7dc:
  mr r4, r31;
  addi r3, r1, 8;
  bl 0x8016ae5c;
lbl_8019c7e8:
  addi r11, r1, 0x60;
  bl _restgpr_27;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
}

// Symbol: NANDOpen
// Function signature is unknown.
// PAL: 0x8019c800..0x8019c88c
asm void NANDOpen(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c838;
  li r3, -128;
  b lbl_8019c870;
lbl_8019c838:
  mr r3, r29;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandOpen;
  cmpwi r3, 0;
  blt lbl_8019c86c;
  li r0, 1;
  stw r3, 0(r30);
  li r3, 0;
  stb r0, 0x8a(r30);
  b lbl_8019c870;
lbl_8019c86c:
  bl nandConvertErrorCode;
lbl_8019c870:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateOpen
// Function signature is unknown.
// PAL: 0x8019c88c..0x8019c918
asm void NANDPrivateOpen(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c8c4;
  li r3, -128;
  b lbl_8019c8fc;
lbl_8019c8c4:
  mr r3, r29;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  bl nandOpen;
  cmpwi r3, 0;
  blt lbl_8019c8f8;
  li r0, 1;
  stw r3, 0(r30);
  li r3, 0;
  stb r0, 0x8a(r30);
  b lbl_8019c8fc;
lbl_8019c8f8:
  bl nandConvertErrorCode;
lbl_8019c8fc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDOpenAsync
// Function signature is unknown.
// PAL: 0x8019c918..0x8019c990
asm void NANDOpenAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c954;
  li r3, -128;
  b lbl_8019c978;
lbl_8019c954:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r29;
  mr r5, r31;
  stw r28, 8(r31);
  li r6, 1;
  li r7, 0;
  bl nandOpen;
  bl nandConvertErrorCode;
lbl_8019c978:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDPrivateOpenAsync
// Function signature is unknown.
// PAL: 0x8019c990..0x8019ca08
asm void NANDPrivateOpenAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019c9cc;
  li r3, -128;
  b lbl_8019c9f0;
lbl_8019c9cc:
  stw r30, 4(r31);
  mr r3, r27;
  mr r4, r29;
  mr r5, r31;
  stw r28, 8(r31);
  li r6, 1;
  li r7, 1;
  bl nandOpen;
  bl nandConvertErrorCode;
lbl_8019c9f0:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandOpenCallback
// Function signature is unknown.
// PAL: 0x8019ca08..0x8019ca80
asm void nandOpenCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  blt lbl_8019ca58;
  lwz r5, 8(r4);
  li r6, 2;
  li r0, 1;
  stw r3, 0(r5);
  li r3, 0;
  lwz r5, 8(r4);
  stb r6, 0x89(r5);
  lwz r5, 8(r4);
  stb r0, 0x8a(r5);
  lwz r12, 4(r4);
  mtctr r12;
  bctrl;
  b lbl_8019ca6c;
lbl_8019ca58:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019ca6c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDClose
// Function signature is unknown.
// PAL: 0x8019ca80..0x8019caec
asm void NANDClose(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019caa8;
  li r3, -128;
  b lbl_8019cad8;
lbl_8019caa8:
  lbz r0, 0x8a(r31);
  cmplwi r0, 1;
  beq lbl_8019cabc;
  li r3, -8;
  b lbl_8019cad8;
lbl_8019cabc:
  lwz r3, 0(r31);
  bl 0x8016b384;
  cmpwi r3, 0;
  bne lbl_8019cad4;
  li r0, 2;
  stb r0, 0x8a(r31);
lbl_8019cad4:
  bl nandConvertErrorCode;
lbl_8019cad8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDCloseAsync
// Function signature is unknown.
// PAL: 0x8019caec..0x8019cb74
asm void NANDCloseAsync(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cb24;
  li r3, -128;
  b lbl_8019cb58;
lbl_8019cb24:
  lbz r0, 0x8a(r29);
  cmplwi r0, 1;
  beq lbl_8019cb38;
  li r3, -8;
  b lbl_8019cb58;
lbl_8019cb38:
  stw r30, 4(r31);
  lis r4, 0x801a;
  mr r5, r31;
  stw r29, 8(r31);
  addi r4, r4, -9660;
  lwz r3, 0(r29);
  bl 0x8016b388;
  bl nandConvertErrorCode;
lbl_8019cb58:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSafeOpen
// Function signature is unknown.
// PAL: 0x8019cb74..0x8019cb80
asm void NANDSafeOpen(void) {
  nofralloc;
  li r8, 0;
  li r9, 0;
  b nandSafeOpen;
}

// Symbol: nandSafeOpen
// Function signature is unknown.
// PAL: 0x8019cb80..0x8019cf28
asm void nandSafeOpen(void) {
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  addi r11, r1, 0x90;
  bl _savegpr_25;
  mr r25, r3;
  mr r28, r4;
  mr r27, r5;
  mr r29, r6;
  mr r30, r7;
  mr r26, r8;
  mr r31, r9;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cbc4;
  li r3, -128;
  b lbl_8019cf10;
lbl_8019cbc4:
  cmpwi r31, 0;
  beq lbl_8019cbdc;
  clrlwi. r0, r30, 0x12;
  beq lbl_8019cbdc;
  li r3, -8;
  b lbl_8019cf10;
lbl_8019cbdc:
  li r0, 0;
  stb r27, 0x88(r28);
  mr r4, r25;
  addi r3, r28, 8;
  stb r0, 0x89(r28);
  bl nandGenerateAbsPath;
  cmpwi r26, 0;
  bne lbl_8019cc14;
  addi r3, r28, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019cc14;
  li r3, -1;
  b lbl_8019cf10;
lbl_8019cc14:
  cmplwi r27, 1;
  bne lbl_8019cc68;
  addi r3, r28, 8;
  li r4, 1;
  bl 0x8016ae5c;
  cmpwi r3, 0;
  blt lbl_8019cc60;
  li r0, 2;
  cmpwi r31, 0;
  stw r3, 0(r28);
  stb r0, 0x89(r28);
  bne lbl_8019cc50;
  li r0, 3;
  stb r0, 0x8a(r28);
  b lbl_8019cc58;
lbl_8019cc50:
  li r0, 5;
  stb r0, 0x8a(r28);
lbl_8019cc58:
  li r3, 0;
  b lbl_8019cf10;
lbl_8019cc60:
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cc68:
  addi r0, r27, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019cf0c;
  li r0, 0;
  lis r3, 0x8029;
  stw r0, 0x20(r1);
  addi r3, r3, -5648;
  li r26, -1;
  li r4, 0;
  stw r0, 0x24(r1);
  li r5, 3;
  li r6, 3;
  li r7, 3;
  stw r0, 0x28(r1);
  stb r0, 0x2c(r1);
  bl 0x80169e74;
  cmpwi r3, 0;
  beq lbl_8019ccc4;
  cmpwi r3, -105;
  beq lbl_8019ccc4;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ccc4:
  li r0, 1;
  addi r3, r28, 8;
  stb r0, 0x89(r28);
  addi r4, r1, 0x1c;
  addi r5, r1, 8;
  addi r6, r1, 0x18;
  addi r7, r1, 0x14;
  addi r8, r1, 0x10;
  addi r9, r1, 0xc;
  bl 0x8016a500;
  cmpwi r3, 0;
  beq lbl_8019ccfc;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ccfc:
  addi r3, r28, 8;
  li r4, 1;
  bl 0x8016ae5c;
  cmpwi r3, 0;
  stw r3, 4(r28);
  bge lbl_8019cd1c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cd1c:
  li r0, 2;
  cmpwi r31, 0;
  stb r0, 0x89(r28);
  bne lbl_8019cd8c;
  bl OSDisableInterrupts;
  lwz r26, -0x63c0(r13);
  addi r0, r26, 1;
  stw r0, -0x63c0(r13);
  bl OSRestoreInterrupts;
  lis r5, 0x8029;
  mr r6, r26;
  addi r3, r1, 0x30;
  addi r4, r13, -29160;
  addi r5, r5, -5648;
  crclr 6;
  bl sprintf;
  addi r3, r1, 0x30;
  li r4, 0;
  li r5, 3;
  li r6, 0;
  li r7, 0;
  bl 0x80169e74;
  cmpwi r3, 0;
  beq lbl_8019cd84;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cd84:
  li r0, 3;
  stb r0, 0x89(r28);
lbl_8019cd8c:
  addi r3, r1, 0x20;
  addi r4, r28, 8;
  bl nandGetRelativeName;
  cmpwi r31, 0;
  bne lbl_8019cdc8;
  lis r4, 0x8029;
  lis r5, 0x8029;
  mr r6, r26;
  addi r3, r28, 0x48;
  addi r4, r4, -5636;
  addi r5, r5, -5648;
  addi r7, r1, 0x20;
  crclr 6;
  bl sprintf;
  b lbl_8019cde4;
lbl_8019cdc8:
  lis r5, 0x8029;
  addi r3, r28, 0x48;
  addi r5, r5, -5648;
  addi r6, r1, 0x20;
  addi r4, r13, -29152;
  crclr 6;
  bl sprintf;
lbl_8019cde4:
  lwz r4, 0x18(r1);
  addi r3, r28, 0x48;
  lwz r5, 0x14(r1);
  lwz r6, 0x10(r1);
  lwz r7, 0xc(r1);
  bl 0x8016ac74;
  cmpwi r3, 0;
  beq lbl_8019ce0c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ce0c:
  li r0, 4;
  cmplwi r27, 2;
  stb r0, 0x89(r28);
  bne lbl_8019ce30;
  addi r3, r28, 0x48;
  li r4, 2;
  bl 0x8016ae5c;
  stw r3, 0(r28);
  b lbl_8019ce48;
lbl_8019ce30:
  cmplwi r27, 3;
  bne lbl_8019ce48;
  addi r3, r28, 0x48;
  li r4, 3;
  bl 0x8016ae5c;
  stw r3, 0(r28);
lbl_8019ce48:
  lwz r3, 0(r28);
  cmpwi r3, 0;
  bge lbl_8019ce5c;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019ce5c:
  li r0, 5;
  lwz r26, 4(r28);
  stb r0, 0x89(r28);
  mr r27, r3;
lbl_8019ce6c:
  mr r3, r26;
  mr r4, r29;
  mr r5, r30;
  bl 0x8016b1fc;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8019ce90;
  li r5, 0;
  b lbl_8019ceb0;
lbl_8019ce90:
  bge lbl_8019ce98;
  b lbl_8019ceb0;
lbl_8019ce98:
  mr r3, r27;
  mr r4, r29;
  bl 0x8016b2c0;
  cmpwi r3, 0;
  bge lbl_8019ce6c;
  mr r5, r3;
lbl_8019ceb0:
  cmpwi r5, 0;
  beq lbl_8019cec4;
  mr r3, r5;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cec4:
  lwz r3, 0(r28);
  li r4, 0;
  li r5, 0;
  bl 0x8016b16c;
  cmpwi r3, 0;
  beq lbl_8019cee4;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cee4:
  cmpwi r31, 0;
  beq lbl_8019cef8;
  li r0, 5;
  stb r0, 0x8a(r28);
  b lbl_8019cf00;
lbl_8019cef8:
  li r0, 3;
  stb r0, 0x8a(r28);
lbl_8019cf00:
  li r3, 0;
  bl nandConvertErrorCode;
  b lbl_8019cf10;
lbl_8019cf0c:
  li r3, -8;
lbl_8019cf10:
  addi r11, r1, 0x90;
  bl _restgpr_25;
  lwz r0, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
}

// Symbol: NANDSafeClose
// Function signature is unknown.
// PAL: 0x8019cf28..0x8019d104
asm void NANDSafeClose(void) {
  nofralloc;
  li r4, 0;
  b lbl_8019cf30;
lbl_8019cf30:
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  li r0, 0;
  stw r31, 0x5c(r1);
  stw r30, 0x58(r1);
  mr r30, r4;
  stw r29, 0x54(r1);
  mr r29, r3;
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019cfa8;
  li r3, -128;
  b lbl_8019d0e8;
lbl_8019cfa8:
  lbz r0, 0x8a(r29);
  cmplwi r0, 3;
  bne lbl_8019cfbc;
  cmpwi r30, 0;
  beq lbl_8019cfd4;
lbl_8019cfbc:
  cmplwi r0, 5;
  bne lbl_8019cfcc;
  cmpwi r30, 0;
  bne lbl_8019cfd4;
lbl_8019cfcc:
  li r3, -8;
  b lbl_8019d0e8;
lbl_8019cfd4:
  lbz r3, 0x88(r29);
  cmplwi r3, 1;
  bne lbl_8019d01c;
  lwz r3, 0(r29);
  bl 0x8016b384;
  cmpwi r3, 0;
  bne lbl_8019d014;
  li r0, 7;
  cmpwi r30, 0;
  stb r0, 0x89(r29);
  bne lbl_8019d00c;
  li r0, 4;
  stb r0, 0x8a(r29);
  b lbl_8019d014;
lbl_8019d00c:
  li r0, 6;
  stb r0, 0x8a(r29);
lbl_8019d014:
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d01c:
  addi r0, r3, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d0d4;
  lwz r3, 0(r29);
  bl 0x8016b384;
  cmpwi r3, 0;
  beq lbl_8019d044;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d044:
  li r31, 6;
  lwz r3, 4(r29);
  stb r31, 0x89(r29);
  bl 0x8016b384;
  cmpwi r3, 0;
  beq lbl_8019d064;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d064:
  li r0, 7;
  addi r3, r29, 0x48;
  stb r0, 0x89(r29);
  addi r4, r29, 8;
  bl 0x8016a934;
  cmpwi r3, 0;
  beq lbl_8019d088;
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d088:
  li r0, 8;
  cmpwi r30, 0;
  stb r0, 0x89(r29);
  bne lbl_8019d0c8;
  addi r3, r1, 8;
  addi r4, r29, 0x48;
  bl nandGetParentDirectory;
  addi r3, r1, 8;
  bl 0x8016a78c;
  cmpwi r3, 0;
  bne lbl_8019d0cc;
  li r4, 9;
  li r0, 4;
  stb r4, 0x89(r29);
  stb r0, 0x8a(r29);
  b lbl_8019d0cc;
lbl_8019d0c8:
  stb r31, 0x8a(r29);
lbl_8019d0cc:
  bl nandConvertErrorCode;
  b lbl_8019d0e8;
lbl_8019d0d4:
  lis r3, 0x8029;
  addi r3, r3, -5624;
  crclr 6;
  bl OSReport;
  li r3, -8;
lbl_8019d0e8:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
}

// Symbol: NANDPrivateSafeOpenAsync
// Function signature is unknown.
// PAL: 0x8019d104..0x8019d130
asm void NANDPrivateSafeOpenAsync(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r10, 1;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r0, 8(r1);
  bl nandSafeOpenAsync;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandSafeOpenAsync
// Function signature is unknown.
// PAL: 0x8019d130..0x8019d298
asm void nandSafeOpenAsync(void) {
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lwz r31, 0x38(r1);
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  mr r30, r10;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019d17c;
  li r3, -128;
  b lbl_8019d280;
lbl_8019d17c:
  cmpwi r31, 0;
  beq lbl_8019d194;
  clrlwi. r0, r27, 0x12;
  beq lbl_8019d194;
  li r3, -8;
  b lbl_8019d280;
lbl_8019d194:
  li r0, 0;
  stb r25, 0x88(r24);
  mr r4, r23;
  addi r3, r24, 8;
  stb r0, 0x89(r24);
  stw r31, 0xb8(r29);
  bl nandGenerateAbsPath;
  cmpwi r30, 0;
  bne lbl_8019d1d0;
  addi r3, r24, 8;
  bl nandIsPrivatePath;
  cmpwi r3, 0;
  beq lbl_8019d1d0;
  li r3, -1;
  b lbl_8019d280;
lbl_8019d1d0:
  cmplwi r25, 1;
  bne lbl_8019d210;
  lis r5, 0x801a;
  stw r24, 8(r29);
  mr r6, r29;
  addi r3, r24, 8;
  stw r28, 4(r29);
  addi r5, r5, -10616;
  li r4, 1;
  bl 0x8016af24;
  cmpwi r3, 0;
  bne lbl_8019d208;
  li r3, 0;
  b lbl_8019d280;
lbl_8019d208:
  bl nandConvertErrorCode;
  b lbl_8019d280;
lbl_8019d210:
  addi r0, r25, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d27c;
  li r31, 0;
  lis r3, 0x8029;
  lis r8, 0x801a;
  stw r24, 8(r29);
  mr r9, r29;
  addi r3, r3, -5648;
  stw r28, 4(r29);
  addi r8, r8, -11624;
  li r4, 0;
  li r5, 3;
  stw r31, 0x7c(r29);
  li r6, 3;
  li r7, 3;
  stw r26, 0x80(r29);
  stw r27, 0x84(r29);
  bl 0x80169f68;
  cmpwi r3, 0;
  bne lbl_8019d26c;
  b lbl_8019d274;
lbl_8019d26c:
  bl nandConvertErrorCode;
  mr r31, r3;
lbl_8019d274:
  mr r3, r31;
  b lbl_8019d280;
lbl_8019d27c:
  li r3, -8;
lbl_8019d280:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
}

// Symbol: nandSafeOpenCallback
// Function signature is unknown.
// PAL: 0x8019d298..0x8019d688
asm void nandSafeOpenCallback(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x74(r1);
  stw r31, 0x6c(r1);
  stw r30, 0x68(r1);
  mr r30, r4;
  bge lbl_8019d2cc;
  cmpwi r3, -105;
  bne lbl_8019d65c;
  lwz r0, 0x7c(r4);
  cmpwi r0, 0;
  bne lbl_8019d65c;
lbl_8019d2cc:
  lwz r0, 0x7c(r4);
  li r6, -117;
  lwz r31, 8(r4);
  cmpwi r0, 0;
  bne lbl_8019d2e8;
  li r0, 1;
  stb r0, 0x89(r31);
lbl_8019d2e8:
  lwz r0, 0x7c(r4);
  cmpwi r0, 2;
  bne lbl_8019d300;
  stw r3, 4(r31);
  li r0, 2;
  stb r0, 0x89(r31);
lbl_8019d300:
  lwz r5, 0x7c(r4);
  cmpwi r5, 2;
  bne lbl_8019d324;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  beq lbl_8019d324;
  addi r0, r5, 2;
  stw r0, 0x7c(r4);
  b lbl_8019d330;
lbl_8019d324:
  lwz r5, 0x7c(r4);
  addi r0, r5, 1;
  stw r0, 0x7c(r4);
lbl_8019d330:
  lwz r0, 0x7c(r4);
  cmpwi r0, 1;
  bne lbl_8019d370;
  lis r10, 0x801a;
  stw r4, 8(r1);
  addi r3, r31, 8;
  addi r5, r4, 0x1c;
  addi r6, r4, 0x20;
  addi r7, r4, 0x24;
  addi r8, r4, 0x28;
  addi r9, r4, 0x2c;
  addi r10, r10, -11624;
  addi r4, r4, 0x18;
  bl 0x8016a658;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d370:
  cmpwi r0, 2;
  bne lbl_8019d398;
  lis r5, 0x801a;
  mr r6, r30;
  addi r3, r31, 8;
  li r4, 1;
  addi r5, r5, -11624;
  bl 0x8016af24;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d398:
  cmpwi r0, 3;
  bne lbl_8019d400;
  bl OSDisableInterrupts;
  lwz r31, -0x63c0(r13);
  addi r0, r31, 1;
  stw r0, -0x63c0(r13);
  bl OSRestoreInterrupts;
  lis r5, 0x8029;
  stw r31, 0x8c(r30);
  mr r6, r31;
  addi r3, r1, 0x20;
  addi r5, r5, -5648;
  addi r4, r13, -29160;
  crclr 6;
  bl sprintf;
  lis r8, 0x801a;
  mr r9, r30;
  addi r3, r1, 0x20;
  li r4, 0;
  addi r8, r8, -11624;
  li r5, 3;
  li r6, 0;
  li r7, 0;
  bl 0x80169f68;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d400:
  cmpwi r0, 4;
  bne lbl_8019d498;
  addi r3, r1, 0x10;
  addi r4, r31, 8;
  bl nandGetRelativeName;
  lwz r0, 0xb8(r30);
  cmpwi r0, 0;
  bne lbl_8019d450;
  li r0, 3;
  lis r4, 0x8029;
  stb r0, 0x89(r31);
  lis r5, 0x8029;
  addi r3, r31, 0x48;
  addi r4, r4, -5636;
  lwz r6, 0x8c(r30);
  addi r5, r5, -5648;
  addi r7, r1, 0x10;
  crclr 6;
  bl sprintf;
  b lbl_8019d46c;
lbl_8019d450:
  lis r5, 0x8029;
  addi r3, r31, 0x48;
  addi r5, r5, -5648;
  addi r6, r1, 0x10;
  addi r4, r13, -29152;
  crclr 6;
  bl sprintf;
lbl_8019d46c:
  lis r8, 0x801a;
  lwz r4, 0x20(r30);
  lwz r5, 0x24(r30);
  mr r9, r30;
  lwz r6, 0x28(r30);
  addi r3, r31, 0x48;
  lwz r7, 0x2c(r30);
  addi r8, r8, -11624;
  bl 0x8016ad68;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d498:
  cmpwi r0, 5;
  bne lbl_8019d504;
  li r0, 4;
  stb r0, 0x89(r31);
  lbz r0, 0x88(r31);
  cmplwi r0, 2;
  bne lbl_8019d4d4;
  lis r5, 0x801a;
  mr r6, r30;
  addi r3, r31, 0x48;
  li r4, 2;
  addi r5, r5, -11624;
  bl 0x8016af24;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d4d4:
  cmplwi r0, 3;
  bne lbl_8019d4fc;
  lis r5, 0x801a;
  mr r6, r30;
  addi r3, r31, 0x48;
  li r4, 3;
  addi r5, r5, -11624;
  bl 0x8016af24;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d4fc:
  li r6, -117;
  b lbl_8019d638;
lbl_8019d504:
  cmpwi r0, 6;
  bne lbl_8019d544;
  stw r3, 0(r31);
  li r3, 5;
  lis r6, 0x801a;
  li r0, 7;
  stb r3, 0x89(r31);
  mr r7, r30;
  addi r6, r6, -11624;
  stw r0, 0x7c(r4);
  lwz r4, 0x80(r4);
  lwz r3, 4(r31);
  lwz r5, 0x84(r30);
  bl 0x8016b21c;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d544:
  cmpwi r0, 7;
  bne lbl_8019d570;
  lis r6, 0x801a;
  lwz r3, 4(r31);
  lwz r4, 0x80(r4);
  mr r7, r30;
  lwz r5, 0x84(r30);
  addi r6, r6, -11624;
  bl 0x8016b21c;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d570:
  cmpwi r0, 8;
  bne lbl_8019d5d4;
  cmpwi r3, 0;
  ble lbl_8019d5ac;
  li r0, 6;
  lis r6, 0x801a;
  stw r0, 0x7c(r4);
  mr r5, r3;
  lwz r4, 0x80(r4);
  mr r7, r30;
  lwz r3, 0(r31);
  addi r6, r6, -11624;
  bl 0x8016b2e0;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d5ac:
  bne lbl_8019d638;
  lis r6, 0x801a;
  lwz r3, 0(r31);
  mr r7, r30;
  li r4, 0;
  addi r6, r6, -11624;
  li r5, 0;
  bl 0x8016b170;
  mr r6, r3;
  b lbl_8019d638;
lbl_8019d5d4:
  cmpwi r0, 9;
  bne lbl_8019d638;
  cmpwi r3, 0;
  bne lbl_8019d620;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d5fc;
  li r0, 3;
  stb r0, 0x8a(r31);
  b lbl_8019d604;
lbl_8019d5fc:
  li r0, 5;
  stb r0, 0x8a(r31);
lbl_8019d604:
  li r3, 0;
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d620:
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d638:
  cmpwi r6, 0;
  beq lbl_8019d670;
  mr r3, r6;
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
  b lbl_8019d670;
lbl_8019d65c:
  bl nandConvertErrorCode;
  lwz r12, 4(r30);
  mr r4, r30;
  mtctr r12;
  bctrl;
lbl_8019d670:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: nandReadOpenCallback
// Function signature is unknown.
// PAL: 0x8019d688..0x8019d720
asm void nandReadOpenCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  blt lbl_8019d6f8;
  lwz r5, 8(r4);
  li r0, 2;
  stw r3, 0(r5);
  lwz r3, 8(r4);
  stb r0, 0x89(r3);
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d6d4;
  lwz r3, 8(r4);
  li r0, 3;
  stb r0, 0x8a(r3);
  b lbl_8019d6e0;
lbl_8019d6d4:
  lwz r3, 8(r4);
  li r0, 5;
  stb r0, 0x8a(r3);
lbl_8019d6e0:
  lwz r12, 4(r31);
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019d70c;
lbl_8019d6f8:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019d70c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDSafeCloseAsync
// Function signature is unknown.
// PAL: 0x8019d720..0x8019d824
asm void NANDSafeCloseAsync(void) {
  nofralloc;
  li r6, 0;
  b lbl_8019d728;
lbl_8019d728:
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019d768;
  li r3, -128;
  b lbl_8019d804;
lbl_8019d768:
  lbz r0, 0x8a(r28);
  cmplwi r0, 3;
  bne lbl_8019d77c;
  cmpwi r31, 0;
  beq lbl_8019d794;
lbl_8019d77c:
  cmplwi r0, 5;
  bne lbl_8019d78c;
  cmpwi r31, 0;
  bne lbl_8019d794;
lbl_8019d78c:
  li r3, -8;
  b lbl_8019d804;
lbl_8019d794:
  stw r31, 0xb8(r30);
  lbz r3, 0x88(r28);
  cmplwi r3, 1;
  bne lbl_8019d7c4;
  stw r28, 8(r30);
  lis r4, 0x801a;
  mr r5, r30;
  stw r29, 4(r30);
  addi r4, r4, -9752;
  lwz r3, 0(r28);
  bl 0x8016b388;
  b lbl_8019d800;
lbl_8019d7c4:
  addi r0, r3, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_8019d7fc;
  li r0, 0xa;
  lis r4, 0x801a;
  stw r28, 8(r30);
  mr r5, r30;
  addi r4, r4, -10204;
  stw r29, 4(r30);
  stw r0, 0x7c(r30);
  lwz r3, 0(r28);
  bl 0x8016b388;
  b lbl_8019d800;
lbl_8019d7fc:
  li r3, -101;
lbl_8019d800:
  bl nandConvertErrorCode;
lbl_8019d804:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandSafeCloseCallback
// Function signature is unknown.
// PAL: 0x8019d824..0x8019d9e8
asm void nandSafeCloseCallback(void) {
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x54(r1);
  stw r31, 0x4c(r1);
  mr r31, r4;
  bne lbl_8019d9c0;
  lwz r0, 0x7c(r4);
  li r6, -117;
  lwz r7, 8(r4);
  cmpwi r0, 0xc;
  bne lbl_8019d85c;
  li r0, 8;
  stb r0, 0x89(r7);
lbl_8019d85c:
  lwz r5, 0x7c(r4);
  cmpwi r5, 0xc;
  bne lbl_8019d880;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  beq lbl_8019d880;
  addi r0, r5, 2;
  stw r0, 0x7c(r4);
  b lbl_8019d88c;
lbl_8019d880:
  lwz r5, 0x7c(r4);
  addi r0, r5, 1;
  stw r0, 0x7c(r4);
lbl_8019d88c:
  lwz r0, 0x7c(r4);
  cmpwi r0, 0xb;
  bne lbl_8019d8bc;
  li r0, 6;
  lis r4, 0x801a;
  stb r0, 0x89(r7);
  mr r5, r31;
  addi r4, r4, -10204;
  lwz r3, 4(r7);
  bl 0x8016b388;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d8bc:
  cmpwi r0, 0xc;
  bne lbl_8019d8ec;
  li r0, 7;
  lis r5, 0x801a;
  stb r0, 0x89(r7);
  mr r6, r31;
  addi r3, r7, 0x48;
  addi r4, r7, 8;
  addi r5, r5, -10204;
  bl 0x8016aa38;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d8ec:
  cmpwi r0, 0xd;
  bne lbl_8019d960;
  li r0, 0;
  addi r3, r1, 8;
  stw r0, 8(r1);
  addi r4, r7, 0x48;
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGetParentDirectory;
  lis r4, 0x801a;
  mr r5, r31;
  addi r3, r1, 8;
  addi r4, r4, -10204;
  bl 0x8016a864;
  mr r6, r3;
  b lbl_8019d99c;
lbl_8019d960:
  cmpwi r0, 0xe;
  bne lbl_8019d99c;
  lwz r0, 0xb8(r4);
  cmpwi r0, 0;
  bne lbl_8019d97c;
  li r0, 9;
  stb r0, 0x89(r7);
lbl_8019d97c:
  li r0, 4;
  stb r0, 0x8a(r7);
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  b lbl_8019d9d4;
lbl_8019d99c:
  cmpwi r6, 0;
  beq lbl_8019d9d4;
  mr r3, r6;
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  b lbl_8019d9d4;
lbl_8019d9c0:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_8019d9d4:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
}

// Symbol: nandReadCloseCallback
// Function signature is unknown.
// PAL: 0x8019d9e8..0x8019da44
asm void nandReadCloseCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019da1c;
  lwz r5, 8(r4);
  li r6, 7;
  li r0, 4;
  stb r6, 0x89(r5);
  lwz r4, 8(r4);
  stb r0, 0x8a(r4);
lbl_8019da1c:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandCloseCallback
// Function signature is unknown.
// PAL: 0x8019da44..0x8019daa0
asm void nandCloseCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_8019da78;
  lwz r5, 8(r4);
  li r6, 7;
  li r0, 2;
  stb r6, 0x89(r5);
  lwz r4, 8(r4);
  stb r0, 0x8a(r4);
lbl_8019da78:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandRemoveTailToken
// Function signature is unknown.
// PAL: 0x8019daa0..0x8019db74
asm void nandRemoveTailToken(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lbz r0, 0(r4);
  stw r31, 0x1c(r1);
  cmpwi r0, 0x2f;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bne lbl_8019daec;
  lbz r0, 1(r4);
  extsb. r0, r0;
  bne lbl_8019daec;
  li r4, 0x2f;
  li r0, 0;
  stb r4, 0(r3);
  stb r0, 1(r3);
  b lbl_8019db58;
lbl_8019daec:
  mr r3, r30;
  bl strlen;
  addic. r31, r3, -1;
  addi r0, r31, 1;
  add r3, r30, r31;
  mtctr r0;
  blt lbl_8019db58;
lbl_8019db08:
  lbz r0, 0(r3);
  cmpwi r0, 0x2f;
  bne lbl_8019db4c;
  cmpwi r31, 0;
  beq lbl_8019db38;
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  bl strncpy;
  li r0, 0;
  stbx r0, r29, r31;
  b lbl_8019db58;
lbl_8019db38:
  li r3, 0x2f;
  li r0, 0;
  stb r3, 0(r29);
  stb r0, 1(r29);
  b lbl_8019db58;
lbl_8019db4c:
  addi r31, r31, -1;
  addi r3, r3, -1;
  bdnz lbl_8019db08;
lbl_8019db58:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandGetHeadToken
// Function signature is unknown.
// PAL: 0x8019db74..0x8019dc48
asm void nandGetHeadToken(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r31, r5;
  li r30, 0;
  b lbl_8019dc20;
lbl_8019dba0:
  lbz r0, 0(r31);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  bne lbl_8019dbf0;
  mr r3, r27;
  mr r4, r29;
  mr r5, r30;
  bl strncpy;
  add r4, r30, r29;
  li r3, 0;
  lbz r0, 1(r4);
  stbx r3, r27, r30;
  extsb. r0, r0;
  bne lbl_8019dbe0;
  stb r3, 0(r28);
  b lbl_8019dc30;
lbl_8019dbe0:
  mr r3, r28;
  addi r4, r4, 1;
  bl strcpy;
  b lbl_8019dc30;
lbl_8019dbf0:
  cmpwi r0, 0;
  bne lbl_8019dc18;
  mr r3, r27;
  mr r4, r29;
  mr r5, r30;
  bl strncpy;
  li r0, 0;
  stbx r0, r27, r30;
  stb r0, 0(r28);
  b lbl_8019dc30;
lbl_8019dc18:
  addi r30, r30, 1;
  addi r31, r31, 1;
lbl_8019dc20:
  mr r3, r29;
  bl strlen;
  cmplw r30, r3;
  ble lbl_8019dba0;
lbl_8019dc30:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandGetRelativeName
// Function signature is unknown.
// PAL: 0x8019dc48..0x8019dce0
asm void nandGetRelativeName(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r13, -29140;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dc84;
  mr r3, r30;
  addi r4, r13, -29136;
  bl strcpy;
  b lbl_8019dcc8;
lbl_8019dc84:
  mr r3, r31;
  bl strlen;
  addic. r4, r3, -1;
  addi r0, r4, 1;
  add r3, r31, r4;
  mtctr r0;
  blt lbl_8019dcb8;
lbl_8019dca0:
  lbz r0, 0(r3);
  cmpwi r0, 0x2f;
  beq lbl_8019dcb8;
  addi r4, r4, -1;
  addi r3, r3, -1;
  bdnz lbl_8019dca0;
lbl_8019dcb8:
  add r4, r31, r4;
  mr r3, r30;
  addi r4, r4, 1;
  bl strcpy;
lbl_8019dcc8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandConvertPath
// Function signature is unknown.
// PAL: 0x8019dce0..0x8019de1c
asm void nandConvertPath(void) {
  nofralloc;
lbl_8019dce0:
  stwu r1, -0x220(r1);
  mflr r0;
  stw r0, 0x224(r1);
  stw r31, 0x21c(r1);
  mr r31, r5;
  stw r30, 0x218(r1);
  mr r30, r4;
  stw r29, 0x214(r1);
  mr r29, r3;
  mr r3, r31;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019dd24;
  mr r3, r29;
  mr r4, r30;
  bl strcpy;
  b lbl_8019de00;
lbl_8019dd24:
  mr r5, r31;
  addi r3, r1, 0x188;
  addi r4, r1, 0x108;
  bl nandGetHeadToken;
  addi r3, r1, 0x188;
  addi r4, r13, -29132;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dd5c;
  mr r3, r29;
  mr r4, r30;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019dd5c:
  addi r3, r1, 0x188;
  addi r4, r13, -29128;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019dd90;
  mr r4, r30;
  addi r3, r1, 0x88;
  bl nandRemoveTailToken;
  mr r3, r29;
  addi r4, r1, 0x88;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019dd90:
  lbz r0, 0x188(r1);
  extsb. r0, r0;
  beq lbl_8019ddf4;
  mr r3, r30;
  addi r4, r13, -29140;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8019ddc8;
  addi r3, r1, 8;
  addi r5, r1, 0x188;
  addi r4, r13, -29124;
  crclr 6;
  bl sprintf;
  b lbl_8019dde0;
lbl_8019ddc8:
  mr r5, r30;
  addi r3, r1, 8;
  addi r6, r1, 0x188;
  addi r4, r13, -29120;
  crclr 6;
  bl sprintf;
lbl_8019dde0:
  mr r3, r29;
  addi r4, r1, 8;
  addi r5, r1, 0x108;
  bl lbl_8019dce0;
  b lbl_8019de00;
lbl_8019ddf4:
  mr r3, r29;
  mr r4, r30;
  bl strcpy;
lbl_8019de00:
  lwz r0, 0x224(r1);
  lwz r31, 0x21c(r1);
  lwz r30, 0x218(r1);
  lwz r29, 0x214(r1);
  mtlr r0;
  addi r1, r1, 0x220;
  blr;
}

// Symbol: nandIsPrivatePath
// Function signature is unknown.
// PAL: 0x8019de1c..0x8019de50
asm void nandIsPrivatePath(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8029;
  li r5, 8;
  stw r0, 0x14(r1);
  addi r4, r4, -5424;
  bl strncmp;
  cntlzw r0, r3;
  srwi r3, r0, 5;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandIsUnderPrivatePath
// Function signature is unknown.
// PAL: 0x8019de50..0x8019dea8
asm void nandIsUnderPrivatePath(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8029;
  li r5, 9;
  stw r0, 0x14(r1);
  addi r4, r4, -5412;
  stw r31, 0xc(r1);
  mr r31, r3;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019de90;
  lbz r0, 9(r31);
  extsb. r0, r0;
  beq lbl_8019de90;
  li r3, 1;
  b lbl_8019de94;
lbl_8019de90:
  li r3, 0;
lbl_8019de94:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandIsInitialized
// Function signature is unknown.
// PAL: 0x8019dea8..0x8019debc
asm void nandIsInitialized(void) {
  nofralloc;
  lwz r3, -0x63b8(r13);
  addi r0, r3, -2;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  blr;
}

// Symbol: nandReportErrorCode
// Function signature is unknown.
// PAL: 0x8019debc..0x8019dec0
asm void nandReportErrorCode(void) {
  nofralloc;
  blr;
}

// Symbol: nandConvertErrorCode
// Function signature is unknown.
// PAL: 0x8019dec0..0x8019e020
asm void nandConvertErrorCode(void) {
  nofralloc;
  clrlwi r11, r1, 0x1a;
  mr r12, r1;
  subfic r11, r11, -768;
  stwux r1, r1, r11;
  mflr r0;
  lis r4, 0x8025;
  stw r0, 4(r12);
  addi r4, r4, 0x2c88;
  li r0, 0x29;
  addi r6, r1, 0x13c;
  stw r31, -4(r12);
  lis r31, 0x8029;
  addi r31, r31, -5600;
  addi r5, r4, -4;
  stw r30, -8(r12);
  stw r29, -0xc(r12);
  mr r29, r3;
  mtctr r0;
lbl_8019df08:
  lwz r4, 4(r5);
  lwzu r0, 8(r5);
  stw r4, 4(r6);
  stwu r0, 8(r6);
  bdnz lbl_8019df08;
  cmpwi r3, 0;
  li r30, 0;
  li r4, 0;
  blt lbl_8019df34;
  mr r3, r29;
  b lbl_8019e000;
lbl_8019df34:
  li r0, 0x29;
  addi r5, r1, 0x140;
  mtctr r0;
lbl_8019df40:
  lwzx r0, r5, r4;
  cmpw r3, r0;
  bne lbl_8019dfb4;
  cmpwi r3, -114;
  beq lbl_8019df74;
  cmpwi r3, -116;
  beq lbl_8019df74;
  cmpwi r3, -117;
  beq lbl_8019df74;
  cmpwi r3, -9;
  beq lbl_8019df74;
  cmpwi r3, -12;
  bne lbl_8019df98;
lbl_8019df74:
  mr r5, r29;
  addi r3, r1, 0xc0;
  addi r4, r31, 0xc8;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0xc0;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
lbl_8019df98:
  mr r3, r29;
  bl nandReportErrorCode;
  addi r0, r30, 1;
  addi r3, r1, 0x140;
  slwi r0, r0, 2;
  lwzx r3, r3, r0;
  b lbl_8019e000;
lbl_8019dfb4:
  addi r30, r30, 2;
  addi r4, r4, 8;
  bdnz lbl_8019df40;
  mr r4, r29;
  addi r3, r31, 0xdc;
  crclr 6;
  bl OSReport;
  mr r5, r29;
  addi r3, r1, 0x40;
  addi r4, r31, 0x110;
  crclr 6;
  bl sprintf;
  addi r4, r1, 0x40;
  li r3, 0;
  crclr 6;
  bl NANDLoggingAddMessageAsync;
  mr r3, r29;
  bl nandReportErrorCode;
  li r3, -64;
lbl_8019e000:
  lwz r10, 0(r1);
  lwz r0, 4(r10);
  lwz r31, -4(r10);
  lwz r30, -8(r10);
  lwz r29, -0xc(r10);
  mtlr r0;
  mr r1, r10;
  blr;
}

// Symbol: nandGenerateAbsPath
// Function signature is unknown.
// PAL: 0x8019e020..0x8019e0e8
asm void nandGenerateAbsPath(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  mr r3, r31;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e05c;
  mr r3, r30;
  addi r4, r13, -29136;
  bl strcpy;
  b lbl_8019e0d0;
lbl_8019e05c:
  lbz r0, 0(r31);
  cmpwi r0, 0x2f;
  bne lbl_8019e070;
  li r0, 0;
  b lbl_8019e074;
lbl_8019e070:
  li r0, 1;
lbl_8019e074:
  cmpwi r0, 0;
  beq lbl_8019e094;
  lis r4, 0x8029;
  mr r3, r30;
  mr r5, r31;
  addi r4, r4, -5504;
  bl nandConvertPath;
  b lbl_8019e0d0;
lbl_8019e094:
  mr r3, r30;
  mr r4, r31;
  bl strcpy;
  mr r3, r30;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e0d0;
  add r4, r3, r30;
  lbz r0, -1(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e0d0;
  addic. r0, r3, -1;
  beq lbl_8019e0d0;
  li r0, 0;
  stb r0, -1(r4);
lbl_8019e0d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandGetParentDirectory
// Function signature is unknown.
// PAL: 0x8019e0e8..0x8019e18c
asm void nandGetParentDirectory(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  mr r3, r30;
  bl strlen;
  addi r0, r3, 1;
  mr r31, r3;
  add r4, r30, r3;
  mtctr r0;
  cmpwi r3, 0;
  blt lbl_8019e140;
lbl_8019e128:
  lbz r0, 0(r4);
  cmpwi r0, 0x2f;
  beq lbl_8019e140;
  addi r31, r31, -1;
  addi r4, r4, -1;
  bdnz lbl_8019e128;
lbl_8019e140:
  cmpwi r31, 0;
  bne lbl_8019e158;
  mr r3, r29;
  addi r4, r13, -29140;
  bl strcpy;
  b lbl_8019e170;
lbl_8019e158:
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  bl strncpy;
  li r0, 0;
  stbx r0, r29, r31;
lbl_8019e170:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDInit
// Function signature is unknown.
// PAL: 0x8019e18c..0x8019e2b8
asm void NANDInit(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8029;
  addi r31, r31, -5600;
  stw r30, 0x18(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x63b8(r13);
  cmpwi r0, 1;
  bne lbl_8019e1c4;
  bl OSRestoreInterrupts;
  li r3, -3;
  b lbl_8019e2a0;
lbl_8019e1c4:
  cmpwi r0, 2;
  bne lbl_8019e1d8;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_8019e2a0;
lbl_8019e1d8:
  li r0, 1;
  stw r0, -0x63b8(r13);
  bl OSRestoreInterrupts;
  bl 0x80169bcc;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8019e288;
  bl 0x801671d0;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8019e210;
  addi r3, r1, 8;
  bl 0x8016799c;
  mr r30, r3;
lbl_8019e210:
  cmpwi r30, 0;
  bne lbl_8019e230;
  lis r5, 0x8034;
  lwz r3, 8(r1);
  lwz r4, 0xc(r1);
  addi r5, r5, 0x6d20;
  bl 0x80167904;
  mr r30, r3;
lbl_8019e230:
  cmpwi r30, 0;
  bne lbl_8019e248;
  lis r4, 0x8034;
  addi r3, r31, 0x60;
  addi r4, r4, 0x6d20;
  bl strcpy;
lbl_8019e248:
  bl 0x80167224;
  cmpwi r30, 0;
  beq lbl_8019e260;
  addi r3, r31, 0x130;
  crclr 6;
  bl OSReport;
lbl_8019e260:
  addi r3, r31, 0xa0;
  bl OSRegisterResetFunction;
  bl OSDisableInterrupts;
  li r0, 2;
  stw r0, -0x63b8(r13);
  bl OSRestoreInterrupts;
  lwz r3, -0x71d8(r13);
  bl OSRegisterVersion;
  li r3, 0;
  b lbl_8019e2a0;
lbl_8019e288:
  bl OSDisableInterrupts;
  li r0, 0;
  stw r0, -0x63b8(r13);
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl nandConvertErrorCode;
lbl_8019e2a0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: nandOnShutdown
// Function signature is unknown.
// PAL: 0x8019e2b8..0x8019e390
asm void nandOnShutdown(void) {
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  cmpwi r3, 0;
  bne lbl_8019e368;
  cmplwi r4, 2;
  bne lbl_8019e360;
  li r26, 0;
  stw r26, 8(r1);
  bl OSGetTime;
  lis r5, 0x801a;
  mr r27, r4;
  mr r28, r3;
  addi r4, r1, 8;
  addi r3, r5, -7292;
  bl 0x8016b40c;
  lis r3, 0x1062;
  lis r30, 0x8000;
  addi r29, r3, 0x4dd3;
  li r31, 0x1f4;
  b lbl_8019e320;
lbl_8019e314:
  lwz r0, 8(r1);
  cmpwi r0, 0;
  bne lbl_8019e360;
lbl_8019e320:
  bl OSGetTime;
  lwz r0, 0xf8(r30);
  subfc r4, r27, r4;
  subfe r3, r28, r3;
  li r5, 0;
  srwi r0, r0, 2;
  mulhwu r0, r29, r0;
  srwi r6, r0, 6;
  bl __div2i;
  xoris r0, r3, 0x8000;
  xoris r5, r26, 0x8000;
  subfc r3, r31, r4;
  subfe r5, r5, r0;
  subfe r5, r0, r0;
  neg. r5, r5;
  bne lbl_8019e314;
lbl_8019e360:
  li r3, 1;
  b lbl_8019e36c;
lbl_8019e368:
  li r3, 1;
lbl_8019e36c:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  li r0, 1;
  stw r0, 0(r4);
  blr;
}

// Symbol: NANDGetCurrentDir
// Function signature is unknown.
// PAL: 0x8019e390..0x8019e40c
asm void NANDGetCurrentDir(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, -0x63b8(r13);
  cmpwi r0, 2;
  bne lbl_8019e3bc;
  li r0, 1;
  b lbl_8019e3c0;
lbl_8019e3bc:
  li r0, 0;
lbl_8019e3c0:
  cmpwi r0, 0;
  bne lbl_8019e3d0;
  li r3, -128;
  b lbl_8019e3f4;
lbl_8019e3d0:
  bl OSDisableInterrupts;
  lis r4, 0x8029;
  mr r31, r3;
  mr r3, r30;
  addi r4, r4, -5504;
  bl strcpy;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_8019e3f4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDGetHomeDir
// Function signature is unknown.
// PAL: 0x8019e40c..0x8019e460
asm void NANDGetHomeDir(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, -0x63b8(r13);
  cmpwi r0, 2;
  bne lbl_8019e42c;
  li r0, 1;
  b lbl_8019e430;
lbl_8019e42c:
  li r0, 0;
lbl_8019e430:
  cmpwi r0, 0;
  bne lbl_8019e440;
  li r3, -128;
  b lbl_8019e450;
lbl_8019e440:
  lis r4, 0x8034;
  addi r4, r4, 0x6d20;
  bl strcpy;
  li r3, 0;
lbl_8019e450:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandCallback
// Function signature is unknown.
// PAL: 0x8019e460..0x8019e49c
asm void nandCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandGetType
// Function signature is unknown.
// PAL: 0x8019e49c..0x8019e770
asm void nandGetType(void) {
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_27;
  mr r27, r3;
  mr r30, r4;
  mr r28, r5;
  mr r29, r6;
  mr r31, r7;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e4d8;
  li r3, -101;
  b lbl_8019e758;
lbl_8019e4d8:
  cmpwi r29, 0;
  beq lbl_8019e5e4;
  mr r3, r27;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e500;
  addi r3, r28, 0x34;
  addi r4, r13, -29136;
  bl strcpy;
  b lbl_8019e574;
lbl_8019e500:
  lbz r0, 0(r27);
  cmpwi r0, 0x2f;
  bne lbl_8019e514;
  li r0, 0;
  b lbl_8019e518;
lbl_8019e514:
  li r0, 1;
lbl_8019e518:
  cmpwi r0, 0;
  beq lbl_8019e538;
  lis r4, 0x8029;
  mr r5, r27;
  addi r3, r28, 0x34;
  addi r4, r4, -5504;
  bl nandConvertPath;
  b lbl_8019e574;
lbl_8019e538:
  mr r4, r27;
  addi r3, r28, 0x34;
  bl strcpy;
  addi r3, r28, 0x34;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e574;
  add r4, r3, r28;
  lbz r0, 0x33(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e574;
  addic. r0, r3, -1;
  beq lbl_8019e574;
  li r0, 0;
  stb r0, 0x33(r4);
lbl_8019e574:
  cmpwi r31, 0;
  bne lbl_8019e5c0;
  lis r4, 0x8029;
  addi r3, r28, 0x34;
  addi r4, r4, -5412;
  li r5, 9;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019e5ac;
  lbz r0, 0x3d(r28);
  extsb. r0, r0;
  beq lbl_8019e5ac;
  li r0, 1;
  b lbl_8019e5b0;
lbl_8019e5ac:
  li r0, 0;
lbl_8019e5b0:
  cmpwi r0, 0;
  beq lbl_8019e5c0;
  li r3, -102;
  b lbl_8019e758;
lbl_8019e5c0:
  lis r6, 0x801a;
  stw r30, 0x88(r28);
  mr r7, r28;
  addi r3, r28, 0x34;
  addi r5, r28, 0x30;
  addi r6, r6, -6148;
  li r4, 0;
  bl 0x8016a1b0;
  b lbl_8019e758;
lbl_8019e5e4:
  li r0, 0;
  mr r3, r27;
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  stw r0, 0x48(r1);
  stw r0, 0x4c(r1);
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8019e648;
  addi r3, r1, 0x10;
  addi r4, r13, -29136;
  bl strcpy;
  b lbl_8019e6c0;
lbl_8019e648:
  lbz r0, 0(r27);
  cmpwi r0, 0x2f;
  bne lbl_8019e65c;
  li r0, 0;
  b lbl_8019e660;
lbl_8019e65c:
  li r0, 1;
lbl_8019e660:
  cmpwi r0, 0;
  beq lbl_8019e680;
  lis r4, 0x8029;
  mr r5, r27;
  addi r3, r1, 0x10;
  addi r4, r4, -5504;
  bl nandConvertPath;
  b lbl_8019e6c0;
lbl_8019e680:
  mr r4, r27;
  addi r3, r1, 0x10;
  bl strcpy;
  addi r3, r1, 0x10;
  bl strlen;
  cmpwi r3, 0;
  beq lbl_8019e6c0;
  addi r0, r1, 0x10;
  add r4, r3, r0;
  lbz r0, -1(r4);
  cmpwi r0, 0x2f;
  bne lbl_8019e6c0;
  addic. r0, r3, -1;
  beq lbl_8019e6c0;
  li r0, 0;
  stb r0, -1(r4);
lbl_8019e6c0:
  cmpwi r31, 0;
  bne lbl_8019e70c;
  lis r4, 0x8029;
  addi r3, r1, 0x10;
  addi r4, r4, -5412;
  li r5, 9;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_8019e6f8;
  lbz r0, 0x19(r1);
  extsb. r0, r0;
  beq lbl_8019e6f8;
  li r0, 1;
  b lbl_8019e6fc;
lbl_8019e6f8:
  li r0, 0;
lbl_8019e6fc:
  cmpwi r0, 0;
  beq lbl_8019e70c;
  li r3, -102;
  b lbl_8019e758;
lbl_8019e70c:
  li r0, 0;
  addi r3, r1, 0x10;
  stw r0, 8(r1);
  addi r5, r1, 8;
  li r4, 0;
  bl 0x8016a05c;
  cmpwi r3, 0;
  beq lbl_8019e734;
  cmpwi r3, -102;
  bne lbl_8019e744;
lbl_8019e734:
  li r0, 2;
  li r3, 0;
  stb r0, 0(r30);
  b lbl_8019e758;
lbl_8019e744:
  cmpwi r3, -101;
  bne lbl_8019e758;
  li r0, 1;
  li r3, 0;
  stb r0, 0(r30);
lbl_8019e758:
  addi r11, r1, 0x70;
  bl _restgpr_27;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
}

// Symbol: NANDGetType
// Function signature is unknown.
// PAL: 0x8019e770..0x8019e7b4
asm void NANDGetType(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, -0x63b8(r13);
  cmpwi r0, 2;
  beq lbl_8019e790;
  li r3, -128;
  b lbl_8019e7a4;
lbl_8019e790:
  li r5, 0;
  li r6, 0;
  li r7, 0;
  bl nandGetType;
  bl nandConvertErrorCode;
lbl_8019e7a4:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDPrivateGetTypeAsync
// Function signature is unknown.
// PAL: 0x8019e7b4..0x8019e7fc
asm void NANDPrivateGetTypeAsync(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, -0x63b8(r13);
  cmpwi r0, 2;
  beq lbl_8019e7d4;
  li r3, -128;
  b lbl_8019e7ec;
lbl_8019e7d4:
  stw r5, 4(r6);
  mr r5, r6;
  li r6, 1;
  li r7, 1;
  bl nandGetType;
  bl nandConvertErrorCode;
lbl_8019e7ec:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandGetTypeCallback
// Function signature is unknown.
// PAL: 0x8019e7fc..0x8019e874
asm void nandGetTypeCallback(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  beq lbl_8019e820;
  cmpwi r3, -102;
  bne lbl_8019e834;
lbl_8019e820:
  lwz r4, 0x88(r4);
  li r0, 2;
  li r3, 0;
  stb r0, 0(r4);
  b lbl_8019e84c;
lbl_8019e834:
  cmpwi r3, -101;
  bne lbl_8019e84c;
  lwz r4, 0x88(r4);
  li r0, 1;
  li r3, 0;
  stb r0, 0(r4);
lbl_8019e84c:
  bl nandConvertErrorCode;
  lwz r12, 4(r31);
  mr r4, r31;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: nandGetHomeDir
// Function signature is unknown.
// PAL: 0x8019e874..0x8019e880
asm void nandGetHomeDir(void) {
  nofralloc;
  lis r3, 0x8034;
  addi r3, r3, 0x6d20;
  blr;
}

// Symbol: NANDInitBanner
// Function signature is unknown.
// PAL: 0x8019e880..0x8019e95c
asm void NANDInitBanner(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 1;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  addi r5, r7, -3936;
  stw r29, 0x14(r1);
  mr r29, r4;
  li r4, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl 0x80006038;
  lis r3, 0x5749;
  stw r29, 4(r28);
  addi r0, r3, 0x424e;
  addi r4, r13, -29112;
  stw r0, 0(r28);
  mr r3, r30;
  bl wcscmp;
  cmpwi r3, 0;
  bne lbl_8019e8f4;
  addi r3, r28, 0x20;
  addi r4, r13, -29108;
  li r5, 0x20;
  bl wcsncpy;
  b lbl_8019e904;
lbl_8019e8f4:
  mr r4, r30;
  addi r3, r28, 0x20;
  li r5, 0x20;
  bl wcsncpy;
lbl_8019e904:
  mr r3, r31;
  addi r4, r13, -29112;
  bl wcscmp;
  cmpwi r3, 0;
  bne lbl_8019e92c;
  addi r3, r28, 0x60;
  addi r4, r13, -29108;
  li r5, 0x20;
  bl wcsncpy;
  b lbl_8019e93c;
lbl_8019e92c:
  mr r4, r31;
  addi r3, r28, 0x60;
  li r5, 0x20;
  bl wcsncpy;
lbl_8019e93c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDSecretGetUsage
// Function signature is unknown.
// PAL: 0x8019e95c..0x8019ea14
asm void NANDSecretGetUsage(void) {
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stw r31, 0x5c(r1);
  mr r31, r5;
  stw r30, 0x58(r1);
  mr r30, r4;
  stw r29, 0x54(r1);
  mr r29, r3;
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019e994;
  li r3, -128;
  b lbl_8019e9f8;
lbl_8019e994:
  li r0, 0;
  mr r4, r29;
  stw r0, 8(r1);
  addi r3, r1, 8;
  stw r0, 0xc(r1);
  stw r0, 0x10(r1);
  stw r0, 0x14(r1);
  stw r0, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r0, 0x20(r1);
  stw r0, 0x24(r1);
  stw r0, 0x28(r1);
  stw r0, 0x2c(r1);
  stw r0, 0x30(r1);
  stw r0, 0x34(r1);
  stw r0, 0x38(r1);
  stw r0, 0x3c(r1);
  stw r0, 0x40(r1);
  stw r0, 0x44(r1);
  bl nandGenerateAbsPath;
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 8;
  bl 0x8016ab3c;
  bl nandConvertErrorCode;
lbl_8019e9f8:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
}

// Symbol: nandCalcUsage
// Function signature is unknown.
// PAL: 0x8019ea14..0x8019ead0
asm void nandCalcUsage(void) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  stw r31, 0(r3);
  li r3, -117;
  stw r31, 0(r4);
  b lbl_8019eaa4;
lbl_8019ea50:
  stw r31, 0xc(r1);
  addi r4, r1, 0xc;
  addi r5, r1, 8;
  stw r31, 8(r1);
  lwz r3, 0(r30);
  bl 0x8016ab3c;
  cmpwi r3, 0;
  bne lbl_8019ea94;
  lwz r4, 0(r28);
  lwz r0, 0xc(r1);
  add r0, r4, r0;
  stw r0, 0(r28);
  lwz r4, 0(r29);
  lwz r0, 8(r1);
  add r0, r4, r0;
  stw r0, 0(r29);
  b lbl_8019eaa0;
lbl_8019ea94:
  cmpwi r3, -106;
  bne lbl_8019eab0;
  li r3, 0;
lbl_8019eaa0:
  addi r30, r30, 4;
lbl_8019eaa4:
  lwz r0, 0(r30);
  cmpwi r0, 0;
  bne lbl_8019ea50;
lbl_8019eab0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Symbol: NANDCheck
// Function signature is unknown.
// PAL: 0x8019ead0..0x8019ebd8
asm void NANDCheck(void) {
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  li r0, -1;
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  stw r0, 0x14(r1);
  stw r0, 0x10(r1);
  stw r0, 0xc(r1);
  stw r0, 8(r1);
  bl nandIsInitialized;
  cmpwi r3, 0;
  bne lbl_8019eb1c;
  li r3, -128;
  b lbl_8019ebbc;
lbl_8019eb1c:
  bl nandGetHomeDir;
  addi r4, r1, 0x14;
  addi r5, r1, 0x10;
  bl 0x8016ab3c;
  cmpwi r3, 0;
  beq lbl_8019eb3c;
  bl nandConvertErrorCode;
  b lbl_8019ebbc;
lbl_8019eb3c:
  lis r5, 0x8029;
  addi r3, r1, 0xc;
  addi r4, r1, 8;
  addi r5, r5, -5136;
  bl nandCalcUsage;
  cmpwi r3, 0;
  beq lbl_8019eb60;
  bl nandConvertErrorCode;
  b lbl_8019ebbc;
lbl_8019eb60:
  lwz r0, 0x14(r1);
  li r5, 0;
  lwz r4, 8(r1);
  add r0, r0, r29;
  lwz r3, 0xc(r1);
  cmplwi r0, 0x400;
  lwz r0, 0x10(r1);
  ble lbl_8019eb84;
  ori r5, r5, 1;
lbl_8019eb84:
  add r0, r0, r30;
  cmplwi r0, 0x21;
  ble lbl_8019eb94;
  ori r5, r5, 2;
lbl_8019eb94:
  add r0, r3, r29;
  cmplwi r0, 0x4400;
  ble lbl_8019eba4;
  ori r5, r5, 4;
lbl_8019eba4:
  add r0, r4, r30;
  cmplwi r0, 0xfa0;
  ble lbl_8019ebb4;
  ori r5, r5, 8;
lbl_8019ebb4:
  stw r5, 0(r31);
  li r3, 0;
lbl_8019ebbc:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
}

// Symbol: reserveFileDescriptor
// Function signature is unknown.
// PAL: 0x8019ebd8..0x8019ec2c
asm void reserveFileDescriptor(void) {
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x71a0(r13);
  cmpwi r0, -255;
  bne lbl_8019ec08;
  li r0, -254;
  li r31, 0;
  stw r0, -0x71a0(r13);
  b lbl_8019ec0c;
lbl_8019ec08:
  li r31, 1;
lbl_8019ec0c:
  bl OSRestoreInterrupts;
  cntlzw r0, r31;
  lwz r31, 0xc(r1);
  srwi r3, r0, 5;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}

// Symbol: NANDLoggingAddMessageAsync
// Function signature is unknown.
// PAL: 0x8019ec2c..0x8019ed24
asm void NANDLoggingAddMessageAsync(void) {
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  mr r31, r4;
  stw r30, 0x78(r1);
  mr r30, r3;
  bne cr1, lbl_8019ec6c;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_8019ec6c:
  stw r3, 8(r1);
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  bl reserveFileDescriptor;
  cmpwi r3, 0;
  bne lbl_8019eca0;
  li r3, 0;
  b lbl_8019ed0c;
lbl_8019eca0:
  addi r4, r1, 0x88;
  addi r0, r1, 8;
  lis r5, 0x200;
  lis r3, 0x8034;
  stw r5, 0x68(r1);
  addi r6, r1, 0x68;
  mr r5, r31;
  addi r3, r3, 0x6d80;
  stw r4, 0x6c(r1);
  li r4, 0x100;
  stw r0, 0x70(r1);
  bl vsnprintf;
  li r0, 1;
  lis r3, 0x8029;
  lis r5, 0x801a;
  stw r30, -0x63b0(r13);
  addi r3, r3, -5088;
  li r4, 3;
  stw r0, -0x63ac(r13);
  addi r5, r5, -4828;
  li r6, 0;
  bl 0x8016af24;
  cmpwi r3, 0;
  bne lbl_8019ed08;
  li r3, 1;
  b lbl_8019ed0c;
lbl_8019ed08:
  li r3, 0;
lbl_8019ed0c:
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
}

// Symbol: asyncRoutine
// Function signature is unknown.
// PAL: 0x8019ed24..0x8019f1a8
asm void asyncRoutine(void) {
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  mr r31, r3;
  stw r30, 0x88(r1);
  lis r30, 0x8034;
  addi r30, r30, 0x6d80;
  lwz r4, -0x63ac(r13);
  addi r0, r4, 1;
  cmpwi r0, 2;
  stw r0, -0x63ac(r13);
  bne lbl_8019edbc;
  cmpwi r3, 0;
  blt lbl_8019eda0;
  lis r6, 0x801a;
  stw r3, -0x71a0(r13);
  addi r6, r6, -4828;
  li r4, 0;
  li r5, 0;
  li r7, 0;
  bl 0x8016b170;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019eda0:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019edbc:
  cmpwi r0, 3;
  bne lbl_8019ee28;
  cmpwi r3, 0;
  bne lbl_8019ee0c;
  lis r6, 0x801a;
  lwz r3, -0x71a0(r13);
  addi r4, r30, 0x100;
  li r5, 0x100;
  addi r6, r6, -4828;
  li r7, 0;
  bl 0x8016b21c;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee0c:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee28:
  cmpwi r0, 4;
  bne lbl_8019ee94;
  cmpwi r3, 0x100;
  bne lbl_8019ee78;
  lis r6, 0x801a;
  lwz r3, -0x71a0(r13);
  addi r6, r6, -4828;
  li r4, 0;
  li r5, 0;
  li r7, 0;
  bl 0x8016b170;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee78:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019ee94:
  cmpwi r0, 5;
  bne lbl_8019eff0;
  cmpwi r3, 0;
  bne lbl_8019efd4;
  addi r3, r30, 0x100;
  li r0, 0;
  stb r0, 0xff(r3);
  bl atoi;
  mr r31, r3;
  addi r3, r30, 0x200;
  li r4, 0x20;
  li r5, 0xfe;
  bl 0x80006038;
  bl OSGetTime;
  addi r5, r1, 0x58;
  bl OSTicksToCalendarTime;
  bl nandGetHomeDir;
  mr r4, r3;
  addi r3, r1, 0x18;
  addi r4, r4, 7;
  li r5, 0x11;
  bl strncpy;
  li r0, 0x2d;
  li r4, 0;
  stb r4, 0x29(r1);
  lis r3, 0x8208;
  lis r5, 0x8029;
  addi r4, r1, 0x18;
  stb r0, 0x20(r1);
  addi r0, r3, 0x2083;
  lwz r3, 0x5c(r1);
  mulhw r0, r0, r31;
  addi r6, r30, 0;
  stw r3, 8(r1);
  addi r5, r5, -5060;
  lwz r3, 0x58(r1);
  add r0, r0, r31;
  stw r3, 0xc(r1);
  srawi r0, r0, 5;
  addi r3, r30, 0x200;
  stw r4, 0x10(r1);
  srwi r4, r0, 0x1f;
  add r0, r0, r4;
  stw r6, 0x14(r1);
  mulli r0, r0, 0x3f;
  li r4, 0x100;
  lwz r8, 0x68(r1);
  subf r6, r0, r31;
  lwz r7, 0x6c(r1);
  lwz r9, 0x64(r1);
  addi r6, r6, 1;
  lwz r10, 0x60(r1);
  addi r8, r8, 1;
  crclr 6;
  bl snprintf;
  cmpwi r3, 0x100;
  bge lbl_8019ef84;
  addi r4, r30, 0x200;
  li r0, 0x20;
  stbx r0, r4, r3;
lbl_8019ef84:
  addi r4, r30, 0x200;
  li r3, 0xd;
  li r0, 0xa;
  lis r6, 0x801a;
  stb r3, 0xfe(r4);
  addi r6, r6, -4828;
  lwz r3, -0x71a0(r13);
  li r5, 0x100;
  stb r0, 0xff(r4);
  li r7, 0;
  bl 0x8016b2e0;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019efd4:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019eff0:
  cmpwi r0, 6;
  bne lbl_8019f068;
  cmpwi r3, 0x100;
  bne lbl_8019f04c;
  addi r3, r30, 0x100;
  bl atoi;
  mr r0, r3;
  lis r6, 0x801a;
  lwz r3, -0x71a0(r13);
  slwi r4, r0, 8;
  addi r6, r6, -4828;
  li r5, 0;
  li r7, 0;
  bl 0x8016b170;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f04c:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f068:
  cmpwi r0, 7;
  bne lbl_8019f0e0;
  addi r3, r30, 0x100;
  bl atoi;
  slwi r0, r3, 8;
  cmpw r31, r0;
  bne lbl_8019f0c4;
  lis r6, 0x801a;
  lwz r3, -0x71a0(r13);
  addi r4, r30, 0x200;
  li r5, 0x100;
  addi r6, r6, -4828;
  li r7, 0;
  bl 0x8016b2e0;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f0c4:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f0e0:
  cmpwi r0, 8;
  bne lbl_8019f144;
  cmpwi r3, 0x100;
  bne lbl_8019f128;
  lis r4, 0x801a;
  lwz r3, -0x71a0(r13);
  addi r4, r4, -4828;
  li r5, 0;
  bl 0x8016b388;
  cmpwi r3, 0;
  beq lbl_8019f190;
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f128:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f144:
  cmpwi r0, 9;
  bne lbl_8019f190;
  cmpwi r3, 0;
  bne lbl_8019f178;
  lwz r12, -0x63b0(r13);
  li r0, -255;
  stw r0, -0x71a0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 1;
  mtctr r12;
  bctrl;
  b lbl_8019f190;
lbl_8019f178:
  lwz r12, -0x63b0(r13);
  cmpwi r12, 0;
  beq lbl_8019f190;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8019f190:
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  lwz r30, 0x88(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
}

