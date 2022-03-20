#pragma once

#include <rk_types.h>

#include <rvl/nand/nand.h>

// Stolen from ogws.
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {
class NandFileStream {

public:
  // PAL: 0x800b0ad0..0x800b0b40
  NandFileStream(const char*, u32);
  // PAL: 0x800b0b40..0x800b0bb0
  NandFileStream(const NANDFileInfo*, u32, bool);
  // PAL: 0x800b0bb0..0x800b0c30
  ~NandFileStream();

  // PAL: 0x800b0c30..0x800b0d20
  bool Open(const char*, u32);
  // PAL: 0x800b0d20..0x800b14a0
  bool Open(const NANDFileInfo*, u32, bool);
  // PAL: 0x800b14a0..0x800b14f0
  void Close();
  // PAL: 0x800b14f0..0x800b1570
  int Read(void*, u32);
  // PAL: 0x800b1570..0x800b1620
  bool ReadAsync(void*, u32, u32, void*);
  // PAL: 0x800b1620..0x800b16a0
  void Write(const void*, u32);
  // PAL: 0x800b16a0..0x800b1750
  bool WriteAsync(const void*, u32, u32, void*);
  // PAL: 0x800b1750..0x800b1758
  void Seek(s32, u32);
};

} // namespace ut
} // namespace nw4r
