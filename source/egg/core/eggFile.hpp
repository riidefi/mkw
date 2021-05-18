#pragma once

namespace EGG {

class File {
public:
  virtual ~File() = 0;                              //!< [vt+0x08]
  virtual int open(const char* path) = 0;           //!< [vt+0x0C]
  virtual void close() = 0;                         //!< [vt+0x10]
  virtual int readData(void*, int, int) = 0;        //!< [vt+0x14]
  virtual int writeData(const void*, int, int) = 0; //!< [vt+0x18]
  virtual int getFileSize() const = 0;              //!< [vt+0x1C]

  // Look DVD added..
  virtual int open(int entryNum) = 0; //!< [vt+0x20]
  virtual int open(char* path) = 0;   //!< [vt+0x24]
};

} // namespace EGG