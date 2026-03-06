#pragma once

#include "nimain/nipoint3.h"
#include "nimain/nistream.h"

class NiSphere {
public:
    NiPoint3 m_kCenter; // 0x0
    float m_fRadius; // 0xc

    bool operator==(const NiSphere &) const;
    bool operator!=(const NiSphere &) const;
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);
    NiSphere();
};
