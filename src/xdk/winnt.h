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

inline LONG InterlockedIncrement(LONG *Addend) {
    LONG v = _InterlockedIncrement(Addend);
    __lwsync();
    return v;
}

inline LONG InterlockedDecrement(LONG *Addend) {
    LONG v = _InterlockedDecrement(Addend);
    __lwsync();
    return v;
}

#ifdef __cplusplus
}
#endif
