#pragma once
#include "../win_types.h"
#include "minwinbase.h"
#include "wtypesbase.h"

#ifdef __cplusplus
extern "C" {
#endif

VOID GetLocalTime(LPSYSTEMTIME lpSystemTime);
VOID GetSystemTime(LPSYSTEMTIME lpSystemTime);
VOID GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
DWORD GetTickCount();

#ifdef __cplusplus
}
#endif
