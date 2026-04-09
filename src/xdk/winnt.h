#pragma once
#include "win_types.h"
#include "intrin.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[4];
} EXCEPTION_RECORD;

inline LONG InterlockedIncrement(LONG volatile *Addend) {
    return _InterlockedIncrement(Addend);
}
inline LONG InterlockedDecrement(LONG volatile *Addend) {
    return _InterlockedDecrement(Addend);
}

#ifdef __cplusplus
}
#endif
