#pragma once

#ifdef __cplusplus
extern "C" {
#endif

enum dwcError { DWCErrorNone = 0, DWCErrorFatal = 9 };

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
