#pragma once
#include "win_types.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG _InterlockedIncrement(LONG volatile *Addend);
LONG _InterlockedDecrement(LONG volatile *Addend);
ULONG _byteswap_ulong(ULONG);

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_byteswap_ulong)

#ifdef __cplusplus
}
#endif
