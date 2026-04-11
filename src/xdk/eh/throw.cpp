#include "xdk/xapilibi/errhandlingapi.h"
#include "seh.hpp"

static const EHExceptionRecord ExceptionTemplate = {
    0xE06D7363, 1, nullptr, nullptr, 3, { 0x19930520, nullptr, nullptr }
};

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
