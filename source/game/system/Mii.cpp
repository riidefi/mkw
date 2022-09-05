#include "Mii.hpp"

namespace System {

const unkStruct defColor = {0xB8, 0x40, 0x30, 0xFF};

void Mii::init(s32 num) {
  this->_4 = num;
  this->_8 = 0;
  this->_9 = -1;
  this->_A4 = 0;
  this->_60 = defColor;
  this->_64 = 0;
  this->_C = 6;
  this->_A5 = 0;
  this->_A6 = 0;
}

} // namespace System
