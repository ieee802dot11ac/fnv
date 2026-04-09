#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "win_types.h"
#include "winnt.h"

VOID RaiseException(
    DWORD dwExceptionCode,
    DWORD dwExceptionFlags,
    DWORD nNumberOfArguments,
    const ULONG_PTR *lpArguments
);

#ifdef __cplusplus
}
#endif
