#pragma once

#include "win_types.h"

#ifdef __cplusplus
extern "C" {
#endif

LPVOID TlsGetValue(DWORD dwTlsIndex);

#ifdef __cplusplus
}
#endif
