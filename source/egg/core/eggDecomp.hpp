#pragma once

#include <rk_types.h>

namespace EGG {

namespace Decomp {
// PAL: 0x80218ba4..0x80218c2c
void decode(unsigned char*, unsigned char*);
// PAL: 0x80218c2c..0x80218dc0
void decodeSZS(unsigned char*, unsigned char*);
// PAL: 0x80218dc0..0x80218ff0
void decodeASH(unsigned char*, unsigned char*);
// PAL: 0x80218ff0..0x802198f8
void decodeASR(unsigned char*, unsigned char*);
// PAL: 0x802198f8..0x8021997c
int checkCompressed(unsigned char*);
// PAL: 0x8021997c..0x80219a7c
int getExpandSize(unsigned char*);
// PAL: 0x80219a7c..0x80219b84
int getBitsCode(unsigned char*, int, int);
// PAL: 0x80219b84..0x80219c10
int getBit1c(unsigned char*, int);
// PAL: 0x80219c10..0x80219d34
void readTree9(unsigned char*, unsigned short*, unsigned short*,
               unsigned short*);
// PAL: 0x80219d34..0x80219e68
void readTree12(unsigned char*, unsigned short*, unsigned short*,
                unsigned short*);
} // namespace Decomp

} // namespace EGG
