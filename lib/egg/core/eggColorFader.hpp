#pragma once
#include <rk_types.h>
#include <nw4r/ut/utColor.hpp>

namespace EGG {
class Fader {
public:
  enum EStatus {
    //! @brief The screen is completely blacked out.
    ESTATUS_OPAQUE = 0,
    //! @brief The screen is completely unblocked.
    ESTATUS_HIDDEN = 1,
    //! @brief Transition from OPAQUE -> HIDDEN
    ESTATUS_FADE_IN = 2,
    //! @brief Transition from HIDDEN -> OPAQUE
    ESTATUS_FADE_OUT = 3
  };

public:
  virtual void setStatus(EStatus status) = 0; //!< [vt+0x08]
  virtual EStatus getStatus() const = 0;      //!< [vt+0x0C]
  virtual bool fadeIn() = 0;                  //!< [vt+0x10]
  virtual bool fadeOut() = 0;                 //!< [vt+0x14]
  virtual int calc() = 0;                     //!< [vt+0x18]
  virtual void draw() = 0;                    //!< [vt+0x1C]
public:
  EStatus mStatus; // 04
};
class ColorFader : public Fader {
public:
  virtual ~ColorFader(); //!< [vt+0x24]

  enum ColorFaderFlag {
    FLAG_1 = 1, // calc() -> case mStatus == ESTATUS_2
    FLAG_2 = 2, // ctor
    FLAG_4 = 4, // unseen
    FLAG_8 = 8  // ctor
  };
  u8 mFlag; // 08
  // 1B implicit pad
  u16 mFrameCount; // 0A s/u? set to 20 in ctor
  u16 mFrame;      // set to 0 in ctor
  // 2B implicit pad
  nw4r::ut::Color mColor; //!< [+0x10] 10 - r, 11 - g, 12 - b, 13 - a
  f32 mLeftX;             //!< [+0x14]
  f32 mTopY;              //!< [+0x18]
  f32 mRightX;            //!< [+0x1C]
  f32 mBottomY;           //!< [+0x20]

  //! @brief Header definition. Linked into MKW at PAL 80007BC0.
  EStatus getStatus() const override { return this->mStatus; }

  //! @brief	A constructor
  //!
  //! @param[in] leftX	Left boundary of the screen in px.
  //! @param[in] bottomY	Bottom boundary of the screen in px.
  //! @param[in] width	Width of the screen in px.
  //! @param[in] height	Height of the screen in px.
  //! @param[in] color	Color of the fading screen.
  //! @param[in] status	State of the fader to set.
  //!						Acceptable states are OPAQUE and
  //! HIDDEN.
  //!
  //! @post
  //!		- mFrameCount = 20
  //!		- mFlag = FLAG_8 | FLAG_2
  //!		- Color set
  //!		- mLeftX, mBottomY, mRightX, mTopY set
  //!		- status and alpha set accordingly
  //!
  ColorFader(f32 leftX, f32 bottomY, f32 width, f32 height,
             nw4r::ut::Color color, Fader::EStatus status);

  //! @brief Sets the frame of the fade.
  //!
  //! @param[in] frame The frame to set. Must not be zero.
  //!
  //! @remarks Wii Sports function between ct and setColor. Not linked in MKW.
  //!
  void setFrame(u16 frame);

  //! @brief Sets the color. Does not modify alpha.
  //!
  //! @param[in] color Color to set.
  //!
  void setColor(nw4r::ut::Color color);

  //! @brief Sets the status of the color fader.
  //!
  //! @param[in] status	Status of the fader to set.
  //!						Acceptable states are OPAQUE and
  //! HIDDEN.
  //!
  void setStatus(Fader::EStatus status) override;

  //! @brief Fade in from pure blacked-out.
  //!
  //! @returns Whether or not this action was carried out. (If the screen was
  //! OPAQUE when called)
  //!
  bool fadeIn() override;

  //! @brief Fade out from no-obstruction.
  //!
  //! @returns Whether or not this action was carried out. (If the screen was
  //! HIDDEN when called)
  //!
  bool fadeOut() override;

  //! @brief Calculate the fader at the current frame.
  //!
  //! @returns Whether or not the operation was successful?
  //!
  int calc() override;

  //! @brief Draw the fader (translucent quad).
  void draw() override;
};
} // namespace EGG
