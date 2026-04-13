#pragma once

#include "types.h"

inline void EndianSwap(u32 *i) {
    u32 j =
        *i & 0xFF000000 >> 24 | *i & 0xFF0000 >> 8 | *i & 0xFF00 << 8 | *i & 0xFF << 24;
}
