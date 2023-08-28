#include "KPadBase.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern data references.
// PAL: 0x8088fcc0
extern UNKNOWN_DATA(lbl_8088fcc0);
// PAL: 0x8088fcc4
extern UNKNOWN_DATA(lbl_8088fcc4);
// PAL: 0x8088fcc8
extern UNKNOWN_DATA(lbl_8088fcc8);
// PAL: 0x8088fcd0
extern UNKNOWN_DATA(lbl_8088fcd0);
// PAL: 0x809bd70c
extern UNKNOWN_DATA(spInstance__Q26System12InputManager);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data


// .bss

// Symbol: reset__Q26System18KPadRaceInputStateFv
// PAL: 0x8051e85c..0x8051e89c
MARK_BINARY_BLOB(reset__Q26System18KPadRaceInputStateFv, 0x8051e85c, 0x8051e89c);
asm UNKNOWN_FUNCTION(reset__Q26System18KPadRaceInputStateFv) {
  #include "asm/8051e85c.s"
}

// Symbol: eq__Q26System18KPadRaceInputStateFPQ26System18KPadRaceInputState
// PAL: 0x8051e89c..0x8051e904
MARK_BINARY_BLOB(eq__Q26System18KPadRaceInputStateFPQ26System18KPadRaceInputState, 0x8051e89c, 0x8051e904);
asm UNKNOWN_FUNCTION(eq__Q26System18KPadRaceInputStateFPQ26System18KPadRaceInputState) {
  #include "asm/8051e89c.s"
}

// Symbol: reset__Q26System16KPadUIInputStateFv
// PAL: 0x8051e904..0x8051e960
MARK_BINARY_BLOB(reset__Q26System16KPadUIInputStateFv, 0x8051e904, 0x8051e960);
asm UNKNOWN_FUNCTION(reset__Q26System16KPadUIInputStateFv) {
  #include "asm/8051e904.s"
}

// Symbol: setStickXMirrored__Q26System18KPadRaceInputStateFUc
// PAL: 0x8051e960..0x8051e9e8
MARK_BINARY_BLOB(setStickXMirrored__Q26System18KPadRaceInputStateFUc, 0x8051e960, 0x8051e9e8);
asm UNKNOWN_FUNCTION(setStickXMirrored__Q26System18KPadRaceInputStateFUc) {
  #include "asm/8051e960.s"
}

// Symbol: setStickXUnmirrored__Q26System18KPadRaceInputStateFUc
// PAL: 0x8051e9e8..0x8051ea28
MARK_BINARY_BLOB(setStickXUnmirrored__Q26System18KPadRaceInputStateFUc, 0x8051e9e8, 0x8051ea28);
asm UNKNOWN_FUNCTION(setStickXUnmirrored__Q26System18KPadRaceInputStateFUc) {
  #include "asm/8051e9e8.s"
}

// Symbol: rawStickToFloat__6SystemFUc
// PAL: 0x8051ea28..0x8051ea60
MARK_BINARY_BLOB(rawStickToFloat__6SystemFUc, 0x8051ea28, 0x8051ea60);
asm UNKNOWN_FUNCTION(rawStickToFloat__6SystemFUc) {
  #include "asm/8051ea28.s"
}

// Symbol: setStickY__Q26System18KPadRaceInputStateFUc
// PAL: 0x8051ea60..0x8051eaa0
MARK_BINARY_BLOB(setStickY__Q26System18KPadRaceInputStateFUc, 0x8051ea60, 0x8051eaa0);
asm UNKNOWN_FUNCTION(setStickY__Q26System18KPadRaceInputStateFUc) {
  #include "asm/8051ea60.s"
}

// Symbol: setStickXMirrored__Q26System16KPadUIInputStateFUc
// PAL: 0x8051eaa0..0x8051eb28
MARK_BINARY_BLOB(setStickXMirrored__Q26System16KPadUIInputStateFUc, 0x8051eaa0, 0x8051eb28);
asm UNKNOWN_FUNCTION(setStickXMirrored__Q26System16KPadUIInputStateFUc) {
  #include "asm/8051eaa0.s"
}

// Symbol: setStickY__Q26System16KPadUIInputStateFUc
// PAL: 0x8051eb28..0x8051eb68
MARK_BINARY_BLOB(setStickY__Q26System16KPadUIInputStateFUc, 0x8051eb28, 0x8051eb68);
asm UNKNOWN_FUNCTION(setStickY__Q26System16KPadUIInputStateFUc) {
  #include "asm/8051eb28.s"
}

// Symbol: setTrick__Q26System18KPadRaceInputStateFUc
// PAL: 0x8051eb68..0x8051eba8
MARK_BINARY_BLOB(setTrick__Q26System18KPadRaceInputStateFUc, 0x8051eb68, 0x8051eba8);
asm UNKNOWN_FUNCTION(setTrick__Q26System18KPadRaceInputStateFUc) {
  #include "asm/8051eb68.s"
}

