#pragma once
#include "win_types.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG _InterlockedIncrement(LONG volatile *Addend);
LONG _InterlockedDecrement(LONG volatile *Addend);

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

#ifdef __cplusplus
}
#endif
