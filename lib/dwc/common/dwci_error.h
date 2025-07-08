#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  DWC_ERROR_NONE = 0,
  DWC_ERROR_TYPE_1 = 1,
  DWC_ERROR_TYPE_2 = 2,
  DWC_ERROR_TYPE_3 = 3,
  DWC_ERROR_TYPE_4 = 4,
  DWC_ERROR_TYPE_5 = 5,
  DWC_ERROR_TYPE_6 = 6,
  DWC_ERROR_TYPE_7 = 7,
  DWC_ERROR_FATAL = 9,
} DWCErrorType;

//! @brief @return Return if there is an error.
//!
int DWCi_IsError();

//! @brief Set the static error data.
//!
//! @details   Cannot proceed if the last error before this function is called
//! is fatal.
//!
//! @param[in] lastError The last error encountered.
//! @param[in] errorCode Error code.
//!
void DWCi_SetError(int lastError, int errorCode);

#ifdef __cplusplus
}
#endif
