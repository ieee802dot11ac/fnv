#pragma once

#include "nimain/NiMatrix3.h"
#include "nimain/NiPoint3.h"

class NiTransform {
public:
    NiMatrix3 m_Rotate; // 0x00
    NiPoint3 m_Translate; // 0x30
    float m_fScale; // 0x3c

    void MakeIdentity();
    bool operator!=(const NiTransform &) const;
    NiPoint3 operator*(const NiPoint3 &) const;
    NiTransform operator*(const NiTransform &) const;
    void Invert(NiTransform &) const;
    void InvertNonUniform(NiTransform &) const;
    bool IsIdentity() const;
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);
    NiTransform();
};
