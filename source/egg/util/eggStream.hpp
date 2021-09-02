/*!
 * @file
 * @brief The Stream class.
 */

#pragma once
#include <rk_types.h>

namespace EGG {
//! @brief The Stream class allows for reading binary / text streams from RAM.
//!
class Stream {
public:
  //! @brief The type of stream to be used when reading/writing.
  //!
  enum StreamFlags {
    STREAM_BINARY = 0, //!< assumed name
    STREAM_TEXT = 1
  };

  Stream(u8* data, u32 size);
  virtual ~Stream();

  void safeRead(void* data, u32 size);
  virtual void read(void* data, u32 size);
  virtual void write(void* data, u32 size);
  virtual bool eof();
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
