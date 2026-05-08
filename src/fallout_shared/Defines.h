#pragma once

#include "intrin.h"
#include "types.h"

// inline void EndianSwap(u32 *i) {
//     u32 j = (*i & 0xFF000000 >> 24) | (*i & 0xFF0000 >> 8) | (*i & 0xFF00 << 8)
//         | (*i & 0xFF << 24);
//     *i = j;
// }

inline uint EndianSwap(uint i) {
    uint ui = i;
    return ui >> 0x18 | ui << 0x18 | ui >> 8 & 0xFF00 | (ui & 0xFF00) << 8;
}

inline void EndianSwapEq(u32 &i) {
    // i = i >> 0x18 | i << 0x18 | i >> 8 & 0xFF00 | (i & 0xFF00) << 8;
    u32 j = i;
    i = _byteswap_ulong(j);
}
