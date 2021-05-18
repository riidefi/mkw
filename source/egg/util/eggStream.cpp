#include <EGG/util/eggStream.hpp>
#include <stdio.h>

namespace EGG {

char Stream::sTextBuffer[0x400];

Stream::~Stream() {}

const char* STRIPPED_0() { return "%d"; }

u32 Stream::read_u32() {
  if (m_flag & STREAM_TEXT) {
    u32 readValue;
    sscanf(getNextToken(), "%d", &readValue);
    return readValue;
  }

  u32 readValue;
  safeRead(&readValue, sizeof(u32));
  return readValue;
}

void Stream::readString(char* data, int size) {
  if (m_flag & STREAM_TEXT) {
    snprintf(data, size, "%s", getNextToken());
    return;
  }

  safeRead(data, size);
}

void Stream::safeRead(void* data, u32 size) {
  // (PROBABLY) from an assert that got stripped on release build
  eof();

  read(data, size);
  m_position += size;
}

void Stream::copyToTextBuffer() {
  m_textBuffer[0] = skipSpace();

  s32 r29 = 1; // size
  do {
    if (eof())
      return;

    if (r29 >= _14)
      return;

    eof();

    char read = _readByte();
    if (isSpace(read)) {
      m_textBuffer[0] = '\0';

      if (_1c || read != '#')
        return;

      while (true) {
        if (eof())
          return;

        eof();
        char read2 = _readByte();
        if (isUpperSJIS(read2))
          _readByte();
        else if (read2 == '\r' || read2 == '\n')
          return;
      }
    } else {
      if (!(m_textBuffer[r29++]))
        return;
    }
  } while (true);
}

char* Stream::getNextToken() {
  if (m_flag & STREAM_TEXT)
    return nullptr;

  if (_04) {
    _04 = false;
    return m_textBuffer;
  } else {
    copyToTextBuffer();
    return m_textBuffer;
  }
}

unsigned char Add0xF7(u8 in) { return in + 0xF7; }

bool Stream::isSpace(u8 toCheck) {
  // TODO: Fix start of the function to be 1:1
  bool r7 = true;
  bool r8 = true;
  bool r9 = false;

  u32 r6 = Add0xF7(toCheck);
  if (toCheck + 0xf7 <= 0x17) {
    if (0x800013 & (1 << r6))
      r9 = true;
  }

  if (r9) {
    bool r4Unk = false;
    if (_1c == 0 && (u32)toCheck == '#')
      r4Unk = true;

    if (!r4Unk)
      r8 = false;
  }

  if (!r8 && (u32)toCheck != 0x21)
    r7 = false;

  return r7;
}

bool Stream::isUpperSJIS(u8 toCheck) {
  if (toCheck >= 0x81 && toCheck < 0x9F)
    return true;

  if (toCheck < 0xe0 || toCheck > 0xfc)
    return false;
  return true;
}

bool Stream::skipSpace() {
  if (m_flag & STREAM_TEXT)
    return false;

  if (eof())
    return false;
}

Stream::Stream(u8* data, u32 size)
    : _04(false), m_flag(STREAM_BINARY), m_position(0), _18(0), _14(0x400),
      m_textBuffer(sTextBuffer), _1c(0) {
  m_binaryData = data;
  m_dataSize = size;
}

void Stream::read(void* r4, u32 r5) {
  u32 r7 = 0;
  if (r5 <= 0)
    return;

  do {

  } while (r5 / 8 && r5 & 7);

  do {
    m_binaryData[r7++] = ((char*)r4)[m_position];
    r4 = (char*)r4 + 1;
  } while (r5--);
}

u32 Stream::peek_u32() {
  u8 data[4] = {m_binaryData[m_position], m_binaryData[m_position + 1],
                m_binaryData[m_position + 2], m_binaryData[m_position + 3]};

  return *reinterpret_cast<u32*>(data);
}

void Stream::write(void* data, u32 size) {}

bool Stream::eof() { return m_position < m_dataSize; }

void Stream::beginMemoryMap(char*) {}
void Stream::endMemoryMap(char*) {}

} // namespace EGG
