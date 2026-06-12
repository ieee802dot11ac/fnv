#pragma once
#include "win_types.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG _InterlockedIncrement(LONG volatile *Addend);
LONG _InterlockedDecrement(LONG volatile *Addend);
ULONG _byteswap_ulong(ULONG);
void _ReadBarrier(void);
void _WriteBarrier(void);
void _ReadWriteBarrier(void);
void __emit(ULONG insn);

#define __lwsync() __emit(0x7c2004acU)
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_byteswap_ulong)
#pragma intrinsic(_ReadBarrier)
#pragma intrinsic(_WriteBarrier)
#pragma intrinsic(_ReadWriteBarrier)

#ifdef __cplusplus
}
#endif
