/*!
 * @file
 * @brief System Manager
 */
#pragma once

#include <rk_types.h>
#include <rvl/os/os.h>
#include <rvl/os/osLink.h>

#include <egg/core/eggHeap.hpp>
#include <egg/core/eggTaskThread.hpp>

namespace System {

class SystemManager // sizeof=4352, vt at 0x54
{
public:
  static SystemManager* sInstance;

  struct SystemRipper {
    u8 mPathBuf[64]; //!< [+0x00] Buffer for the ripped path to placed in.
    EGG::Heap* pDvdRipperHeap; //!< [+0x40] Heap to use for DVD ripper methods.
    bool bTopAllocDir; //!< [+0x44] if true? allocDir=1(ALLOC_DIR_TOP)negative :
                       //!< allocDir=2(ALLOC_DIR_BOTTOM)positive
    u32* mRippedFileSizeOutput;  //!< [+0x48] Output filesize pointer for ripped
                                 //!< file.
    u8* pManualRipperDestBuffer; //!< [+0x4C] Used if pDvdRipperHeap is NULL as
                                 //!< the destination buffer.
    u8* mRippedDestBuf; //!< [+0x50] Used as dest buffer in read function.
  } mSystemRipper;

  //! @brief		Initialize the static instance for the system manager.
  //!
  //! @param[in]	pHeap Heap for the new instance to use.
  //!
  //! @return		Pointer to the new system manager.
  //!
  static SystemManager* initStaticInstance(EGG::Heap* PHeap);

  //! @brief [vt(+0x54)+0x08] Destroy the system manager.
  //!
  virtual ~SystemManager();

  SystemManager(EGG::Heap* heap);
  void NDEVArgParse();
  void LoadSymbols(OSModuleInfo* osmoduleinfo);
  void setupSystem(EGG::Heap* heap);

  //! @brief Properly shutdown the Wii.
  void shutdownSystem();

  //! @brief Properly return to the Wii main menu.
  //!
  void returnToMenu();

  //! @brief Properly restart the Wii.
  //!
  void restart();

  void setSystemPowerCallbacks(); // disable doRestart and doShutdown and set
                                  // Power / Reset callbacks

  void handlePowerState();           // handle doShutdown and doRestart
  const char* getRegionCode() const; // For this build, return 'RMCP'
  u32 sanitizeGameIDRegion(u32 gameName) const;

  // TODO
  u8* ripFromDiscAsync(const char path[64], EGG::Heap* heap, bool allocTop,
                       u32* fsizeOutput, u8* dst);
  u8* ripFromDisc(const char path[64], EGG::Heap* heap, bool allocTop,
                  u32* fsizeOutput, u8* dst);

  //! @brief Processes a rip request (used as function for ripping task thread)
  //!
  //! @details
  //!		If pDvdRipperHeap is set, the EGG::DvdRipper will create a
  //! buffer form the heap. The allocation direction is contrlled by
  //! bTopAllocDir. 		Otherwise, pManualRipperDestBuffer will be used.
  //!
  //! @post If set, the value pointed to by mRippedFileSizeOutput will be set.
  //!
  //! @return A pointer to the ripped file in memory.
  //!
  // Internal
  // static void* processRipRequest();

  //! @brief
  static u8* ripFromDisc(const char path[64], EGG::Heap* heap, bool allocTop,
                         u32* fsizeOutput);
  static u8* ripFromDisc(const char path[64], u8* dst, u32* fsizeOutput);
  static bool isPal50();

  //! @brief Stop the motors of all controllers on all channels.
  //!
  static void stopAllControllerMotors();

  u32 mAspectRatio;      //!< [+0x58] 1 - 16x9
  u32 mLanguage;         //!< [+0x5C] True language?
  u32 mResourceLanguage; //!< [+0x60] Same as above, but Dutch -> English
  u32 mProgressiveMode;  //!< [+0x64] 1 - on
  u32 mEuRgb60Mode;      //!< [+0x68] 1 - EURGB60
  int mb50Fps; //!< [+0x6C] Name is really a GUESS. An int. Possible some vi
               //!< type? PAL and EURGB set it to true but it's already true. So
               //!< possibly isEuro too?
  u32 mLaunchType; //!< [+0x70] Determiined by launch/return code

  f32 mFps60;       // 74 set 59.94f in CT
  f32 mFpsCurrent;  // 78 set 59.94f in CT, though always to 50 here?
  f32 mFrameSize60; // 0x7C for 60fps: 16.68335f (1000/59.94)

  bool bIsNdev; //!< [+0x80]
  // 81 unseen. pad?
  u16 _82;           // determined by return/launchcode
  u32 mMatchingArea; //!< [+0x84] set 15 in ct. everywhere: 2; australia/new
                     //!< zealand: 3
  u8* buf_88;        //!< [+0x88] 32 bytes
  u8* buf_8C;        //!< [+0x8C] 32 bytes
  u8* buf_90;        //!< [+0x90] 32 bytes

  u32 _94;
  char* pNdevArgument;  //!< [+0x98] first argument when loaded from ndev @see
                        //!< NDEVArgParse max size 48
  u32 mStaticTextStart; // 9C
  u32 mStaticTextEnd;   // A0 8038917C
  u32 mStaticTextSize;  // A4 8038917C - 0x80004000
  u32 _A8;
  EGG::Heap* mHeap; //!< [+0xAC] arg of ct. maybe another so name for now
  OSModuleInfo* _B0;
  bool doShutDown; //!< [+0xB4] If true, system will shut down in next
                   //!< handlePowerState()
  bool doRestart;  //!< [+0xB5] If true, system will restart in next
                   //!< handlePowerState()
  bool _B6;        // 0 in ct
  bool _B7; // if it's not enabled, power/reset callbacks won't shut down system

  OSMessageQueue _B8;           //!< [+0xB8] sizeof=0x20
  OSMessage _D8[4];             //!< [+0xD8]
  EGG::TaskThread* mTaskThread; //!< [+0xE8]
  OSThread* pCreatedInThread;   //!< [+0xEC] zeroed then OSGetThread() in ct

  u8 mYear;       //!< [+0xF0] clamped to 99 in ct
  u8 mMonth;      //!< [+0xF1] clamped to 12 in ct
  u8 mDayOfMonth; //!< [+0xF2] clamped to 31 in ct
  u8 _F3;         // 0 in ct
  u8 _F4;         // 0 in ct
  struct {
    s32 ID; // F8
    u8 unk[0x10fc - 4];
    u16 mLatitude;  // 10FC
    u16 mLongitude; // 10FE

    //! @brief	The check for region has to be in this function, as codwarrior
    //! doesn't optimize this as much as it would had
    //!			the comparison been outside.
    inline bool isRegion(s32 region) const {
#ifdef NTSCJ
      if (ID != -1)
        return ID >> 24 == region;
      return -1;
#else
      return ID == -1 ? 0 : ID >> 24 == region;
#endif
    }
  } mSimpleAddressData; // F8 -> 1100
};

} // namespace System
