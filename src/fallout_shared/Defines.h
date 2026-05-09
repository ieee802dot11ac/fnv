#pragma once

#include "intrin.h"
#include "types.h"
#include <cstdlib> // IWYU pragma: keep

// inline uint EndianSwap(uint i) {
//     uint ui = i;
//     return ui >> 0x18 | ui << 0x18 | ui >> 8 & 0xFF00 | (ui & 0xFF00) << 8;
// }

inline void EndianSwapEq(u32 &i) {
    u32 j = i;
    i = _byteswap_ulong(j);
}

inline void EndianSwapEq(int &i) {
    u32 j = i;
    i = _byteswap_ulong(j);
}

inline void EndianSwapEq(uint &i) {
    u32 j = i;
    i = _byteswap_ulong(j);
}

#define LOADOBJBOUND                                                                     \
    case OBND_ID: {                                                                      \
        LoadObjectBound(apFile);                                                         \
    } break;
#define LOADEDITORID                                                                     \
    case EDID_ID: {                                                                      \
        void *buf = alloca(apFile->GetChunkSize());                                      \
        apFile->GetChunkData(buf, 0x200);                                                \
        SetFormEditorID(static_cast<const char *>(buf));                                 \
    } break;
