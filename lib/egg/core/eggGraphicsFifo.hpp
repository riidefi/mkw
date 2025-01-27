/**
 * @file
 * @brief Contains code for the GraphicsFifo wrapper.
 */

#pragma once

#include <rk_types.h>

struct GXFifoObj;

namespace EGG {

class Heap;

//! @brief Wrapper for GX Graphics fifo.
//!
class GraphicsFifo {
public:
  //! @brief Holds the state of the Graphics Processor at any given moment.
  //!
  //! @details Pointers to all members passed as arguments to GXGetGPStatus().
  //!
  struct GPStatus {
    u8 overhi;   //!< [+0x00] If high watermark has been passed.
    u8 underlow; //!< [+0x01] If low watermark has been passed.
    u8 readIdle; //!< [+0x02] If the GP read unit is idle.
    u8 cmdIdle;  //!< [+0x03] If all commands been flushed to XF.
    u8 brkpt;    //!< [+0x04] If FIFO has reached a breakpoint and GP reads
                 //!<         have been stopped.
  };

  virtual ~GraphicsFifo();

  //! @brief Creates the global GraphicsFifo.
  //!
  //! @param[in] fifoSize Size of the FIFO to create. Will be rounded to 32B.
  //! @param[in] heap     Heap to create the FIFO in. If nullptr, default heap
  //! used.
  //!
  //! @pre If heap is nullptr, default heap used.
  //!
  //! @return The initialized GraphicsFifo.
  //!
  static GraphicsFifo* create(u32 fifoSize, Heap* heap);

private:
  //! @brief Initializes the GraphicsFifo (called by create).
  //!
  //! @param[in] fifoSize Size of the FIFO to create. Will be rounded to 32B.
  //! @param[in] heap     Heap to create the FIFO in.
  //!
  //! @pre heap must not be nullptr.
  //!
  //! @return The initialized GraphicsFifo.
  //!
  GraphicsFifo(unsigned int fifoSize, Heap* heap);

  GXFifoObj* mFifoObj;   //!< Pointer to the GXFifoObj* (+0x04)
  void* mBufBase;        //!< Pointer to the buffer base. (+0x08)
  unsigned int mBufSize; //!< Size of the buffer. (+0x0C)

  // Global instance. Not used.
  static GraphicsFifo* sGraphicsFifo;

  // Holds GXGetGPStatus results
  static GPStatus sGpStatus;
};

} // namespace EGG
