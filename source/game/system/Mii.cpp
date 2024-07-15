#include "Mii.hpp"
#include "decomp.h"

// relsymdefs
extern "C" {
#ifndef SHIFTABLE
// for the initializer list in the constructor
extern System::unkStruct defColor__6System;
REL_SYMBOL_AT(defColor__6System, 0x8088fd60)
#else
static const System::unkStruct defColor = (System::unkStruct){0xB8, 0x40, 0x30, 0xFF};
#endif
}

namespace System {

void Mii::init(s32 num) {
  this->_4 = num;
  this->_8 = 0;
  this->_9 = -1;
  this->_A4 = 0;
  this->_60 = (unkStruct){0xB8, 0x40, 0x30, 0xFF};
  this->_64 = 0;
  this->_C = 6;
  this->_A5 = 0;
  this->_A6 = 0;
}

} // namespace System
