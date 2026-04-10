#include "nipoint3.h"

const NiPoint3 NiPoint3::ZERO(0, 0, 0);
const NiPoint3 NiPoint3::UNIT_X(1, 0, 0);
const NiPoint3 NiPoint3::UNIT_Y(0, 1, 0);
const NiPoint3 NiPoint3::UNIT_Z(0, 0, 1);
const NiPoint3 NiPoint3::UNIT_ALL(1, 1, 1);
const NiPoint3 NiPoint3::INFINITY_POINT3;

// MERGED!!! with NiColor::SaveBinary(NiStream&)
void NiPoint3::SaveBinary(NiStream &stream) {
    NiStreamSaveBinary(stream, x);
    NiStreamSaveBinary(stream, y);
    NiStreamSaveBinary(stream, z);
}

char *NiPoint3::GetViewerString(char const *pPrefix) const { return nullptr; }

uint *NiPoint3::InitSqrtTable() { return nullptr; }
