#include "errhandlingapi.h"
#include "seh.hpp"

static EHExceptionRecord ExceptionTemplate;

void _CxxThrowException(void *pExceptionObject, const _s_ThrowInfo *pThrowInfo) {
    EHExceptionRecord blob = ExceptionTemplate;
    blob.params.pExceptionObject = pExceptionObject;
    blob.params.pThrowInfo = pThrowInfo;
    if (pThrowInfo && pThrowInfo->attributes & 8) {
        blob.params.magicNumber = 0x1994000;
    }
    RaiseException(
        blob.ExceptionCode,
        blob.ExceptionFlags,
        blob.NumberParameters,
        reinterpret_cast<const ULONG_PTR *>(&blob.params)
    );
}
