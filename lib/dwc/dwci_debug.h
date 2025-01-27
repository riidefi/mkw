#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef DEBUG
#ifndef DWCiAssert
#define DWCiAssert(exp, file, line, msg)                                       \
  (void)((exp) || (OSPanic(file, line, msg), 0))
#endif
#else
#ifndef DWCiAssert
#define DWCiAssert(exp, file, line, msg) ((void)0)
#endif
#endif

#ifdef __cplusplus
}
#endif
