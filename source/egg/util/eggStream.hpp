/*!
 * @file
 * @brief The Stream class.
 */

#pragma once
#include <rk_types.h>
#include <decomp.h>

namespace EGG {

struct Stream {
  virtual ~Stream();
};

//! @brief The Stream class allows for reading binary / text streams from RAM.
//!
class RamStream : Stream {
public:
  //! @brief The type of stream to be used when reading/writing.
  //!
  enum StreamFlags {
    STREAM_BINARY = 0, //!< assumed name
    STREAM_TEXT = 1
  };

  RamStream(u8* data, u32 size);
  virtual ~RamStream();

  void safeRead(void* data, u32 size);
  virtual void read(void* data, u32 size);
  virtual void write(void* data, u32 size);
  virtual bool eof() const;
  virtual void beginMemoryMap(char*);
  virtual void endMemoryMap(char*);
  virtual u32 peek_u32();

  void copyToTextBuffer();
  char* getNextToken();

  void readString(char* data, int size);
  u32 read_u32();
  inline u8 _readByte() {
    char data;
    read((u32*)&data, sizeof(char));
    m_position += sizeof(char);
    return data;
  }

  bool skipSpace();
  bool isSpace(u8);
  bool isUpperSJIS(u8);

  static char sTextBuffer[0x400];

private:
  // 0 - vtbl
  bool _04;           // _04
  u32 m_position;     // _08
  u16 m_flag;         // _0c
  char* m_textBuffer; // _10
  s32 _14;            // _14, buffer size?
  u32 _18;            // _18
  u8 _1c;             // _1c
  u8* m_binaryData;   // _20
  u32 m_dataSize;     // _24
};
} // namespace EGG

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80241b60..0x80241ba0
UNKNOWN_FUNCTION(__dt__Q23EGG6StreamFv);
// PAL: 0x80241ba0..0x80241bfc
UNKNOWN_FUNCTION(read_u32__Q23EGG6StreamFv);
// PAL: 0x80241bfc..0x80241c68
UNKNOWN_FUNCTION(readString__Q23EGG6StreamFPci);
// PAL: 0x80241c68..0x80241ce0
UNKNOWN_FUNCTION(saferead__Q23EGG6StreamFPvUl);
// PAL: 0x80241ce0..0x80241eac
UNKNOWN_FUNCTION(copyToTextBuffer__Q23EGG6StreamFv);
// PAL: 0x80241eac..0x80241f0c
UNKNOWN_FUNCTION(getNextToken__Q23EGG6StreamFv);
// PAL: 0x80241f0c..0x80241f9c
UNKNOWN_FUNCTION(isSpace__Q23EGG6StreamFUc);
// PAL: 0x80241f9c..0x80241fcc
UNKNOWN_FUNCTION(isUpperSJIS__Q23EGG6StreamFUc);
// PAL: 0x80241fcc..0x802421d4
UNKNOWN_FUNCTION(skipSpace__Q23EGG6StreamFv);
// PAL: 0x802421d4..0x80242218
UNKNOWN_FUNCTION(__ct__Q23EGG9RamStreamFPUcUl);
// PAL: 0x80242218..0x80242328
UNKNOWN_FUNCTION(read__Q23EGG9RamStreamFPvUl);
// PAL: 0x80242328..0x80242364
UNKNOWN_FUNCTION(peek_u32__Q23EGG9RamStreamFv);
// PAL: 0x80242364..0x80242474
UNKNOWN_FUNCTION(write__Q23EGG9RamStreamFPvUl);
// PAL: 0x80242474..0x80242490
UNKNOWN_FUNCTION(eof__Q23EGG9RamStreamCFv);
// PAL: 0x80242490..0x80242494
UNKNOWN_FUNCTION(beginMemoryMap__Q23EGG9RamStreamFPc);
// PAL: 0x80242494..0x80242498
UNKNOWN_FUNCTION(endMemoryMap__Q23EGG9RamStreamFPc);

#ifdef __cplusplus
}
#endif
