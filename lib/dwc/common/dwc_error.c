#include "dwc_error.h"

#include "dwci_error.h"

//! @brief The last error code encountered.
//!
int stDwcErrorCode;

//! @brief The last error type encountered.
//!
int stDwcLastError;

int DWC_GetLastError(int* errorCode) {
  if (errorCode)
    *errorCode = stDwcErrorCode;

  return stDwcLastError;
}

int DWC_GetLastErrorEx(int* errorCode, int* errorType) {
  if (errorCode)
    *errorCode = stDwcErrorCode;
  if (errorType) {
    switch (stDwcLastError) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
      *errorType = 6;
      break;
    case 6:
      if (stDwcErrorCode == -80430)
        *errorType = 2;
      else
        *errorType = 3;
      break;
    case 7:
      *errorType = 4;
      break;
    case 10:
    case 11:
    case 12:
    case 13:
      *errorType = 1;
      break;
    case 1:
    case DWCErrorFatal:
      *errorType = 7;
      break;

    case 14:
      *errorType = 5;
      break;
    case 15:
    case 17:
    case 19:
      *errorType = 6;
      break;
    case 16:
    case 20:
    case 21:
      *errorType = 2;
      break;
    case 18:
      *errorType = 1;
      break;
    default:
      *errorType = 0;
      break;
    }
  }
  return stDwcLastError;
}

void DWC_ClearError() {
  if (stDwcLastError != DWCErrorFatal) {
    stDwcLastError = DWCErrorNone;
    stDwcErrorCode = 0;
  }
}

int DWCi_IsError() { return stDwcLastError != DWCErrorNone; }

void DWCi_SetError(int lastError, int errorCode) {
  if (stDwcLastError != DWCErrorFatal) {
    stDwcLastError = lastError;
    stDwcErrorCode = errorCode;
  }
#ifdef DEBUG
  if (stDwcLastError == DWCErrorFatal)
    DWC_Printf(-1, "FATALERROR_SET\n");
#endif
}
