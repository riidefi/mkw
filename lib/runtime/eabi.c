// PAL: 0x8002156C
extern void _savegpr_14(void);
// PAL: 0x80021570
extern void _savegpr_15(void);
// PAL: 0x80021574
extern void _savegpr_16(void);
// PAL: 0x80021578
extern void _savegpr_17(void);
// PAL: 0x8002157C
extern void _savegpr_18(void);
// PAL: 0x80021580
extern void _savegpr_19(void);
// PAL: 0x80021584
extern void _savegpr_20(void);
// PAL: 0x80021588
extern void _savegpr_21(void);
// PAL: 0x8002158C
extern void _savegpr_22(void);
// PAL: 0x80021590
extern void _savegpr_23(void);
// PAL: 0x80021594
extern void _savegpr_24(void);
// PAL: 0x80021598
extern void _savegpr_25(void);
// PAL: 0x8002159c
extern void _savegpr_26(void);
// PAL: 0x800215a0
extern void _savegpr_27(void);

// PAL: 0x800215b8
extern void _restgpr_14(void);
// PAL: 0x800215bc
extern void _restgpr_15(void);
// PAL: 0x800215c0
extern void _restgpr_16(void);
// PAL: 0x800215c4
extern void _restgpr_17(void);
// PAL: 0x800215c8
extern void _restgpr_18(void);
// PAL: 0x800215cc
extern void _restgpr_19(void);
// PAL: 0x800215d0
extern void _restgpr_20(void);
// PAL: 0x800215d4
extern void _restgpr_21(void);
// PAL: 0x800215d8
extern void _restgpr_22(void);
// PAL: 0x800215dc
extern void _restgpr_23(void);
// PAL: 0x800215e0
extern void _restgpr_24(void);
// PAL: 0x800215e4
extern void _restgpr_25(void);
// PAL: 0x800215e8
extern void _restgpr_26(void);
// PAL: 0x800215ec
extern void _restgpr_27(void);

extern void __div2u(void);
// PAL: 0x800216f0
extern void __div2i(void);
extern void __mod2u(void);
extern void __mod2i(void);
extern void __shl2i(void);
extern void __shr2u(void);
extern void __shr2i(void);

// PAL: 0x80021b00
void __cvt_dbl_ull(void);

unsigned long __cvt_fp2unsigned(double d);

static asm void __save_gpr(void) {
  // clang-format off
  nofralloc;
entry _savegpr_14
  stw r14,-72(r11);
entry _savegpr_15
  stw r15,-68(r11);
entry _savegpr_16
  stw r16,-64(r11);
entry _savegpr_17
  stw r17,-60(r11);
entry _savegpr_18
  stw r18,-56(r11);
entry _savegpr_19
  stw r19,-52(r11);
entry _savegpr_20
  stw r20,-48(r11);
entry _savegpr_21
  stw r21,-44(r11);
entry _savegpr_22
  stw r22,-40(r11);
entry _savegpr_23
  stw r23,-36(r11);
entry _savegpr_24
  stw r24,-32(r11);
entry _savegpr_25
  stw r25,-28(r11);
entry _savegpr_26
  stw r26,-24(r11);
entry _savegpr_27
  stw r27,-20(r11);
  stw r28,-16(r11);
  stw r29,-12(r11);
  stw r30,-8(r11);
  stw r31,-4(r11);
  blr;
  // clang-format on
}

static asm void __rest_gpr(void) {
  // clang-format off
  nofralloc;
entry _restgpr_14
  lwz r14,-72(r11);
entry _restgpr_15
  lwz r15,-68(r11);
entry _restgpr_16
  lwz r16,-64(r11);
entry _restgpr_17
  lwz r17,-60(r11);
entry _restgpr_18
  lwz r18,-56(r11);
entry _restgpr_19
  lwz r19,-52(r11);
entry _restgpr_20
  lwz r20,-48(r11);
entry _restgpr_21
  lwz r21,-44(r11);
entry _restgpr_22
  lwz r22,-40(r11);
entry _restgpr_23
  lwz r23,-36(r11);
entry _restgpr_24
  lwz r24,-32(r11);
entry _restgpr_25
  lwz r25,-28(r11);
entry _restgpr_26
  lwz r26,-24(r11);
entry _restgpr_27
  lwz r27,-20(r11);
  lwz r28,-16(r11);
  lwz r29,-12(r11);
  lwz r30,-8(r11);
  lwz r31,-4(r11);
  blr;
  // clang-format on
}
