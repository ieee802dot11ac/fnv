#pragma once
#include "win_types.h"
#include "intrin.h"

inline LONG InterlockedIncrement(LONG volatile *Addend) {
    return _InterlockedIncrement(Addend);
}
inline LONG InterlockedDecrement(LONG volatile *Addend) {
    return _InterlockedDecrement(Addend);
}
