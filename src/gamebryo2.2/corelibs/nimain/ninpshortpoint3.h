#pragma once

#include "nipoint3.h"

class NiNPShortPoint3 {
public:
    short x; // 0
    short y; // 2
    short z; // 4

    NiNPShortPoint3(const NiNPShortPoint3 &);
    NiNPShortPoint3(short, short, short);
    NiNPShortPoint3();
    short &operator[](int) const;
    NiNPShortPoint3 &operator=(const NiPoint3 &);
    NiNPShortPoint3 &operator=(const NiNPShortPoint3 &);
    bool operator==(const NiPoint3 &) const;
    bool operator==(const NiNPShortPoint3 &) const;
    bool operator!=(const NiPoint3 &) const;
    bool operator!=(const NiNPShortPoint3 &) const;
    NiNPShortPoint3 operator+(const NiNPShortPoint3 &) const;
    NiNPShortPoint3 operator-() const;
    NiNPShortPoint3 operator-(const NiNPShortPoint3 &) const;
    NiNPShortPoint3 operator*(float) const;
    short operator*(const NiNPShortPoint3 &) const;
    NiNPShortPoint3 operator/(float) const;
    NiNPShortPoint3 &operator+=(const NiNPShortPoint3 &);
    NiNPShortPoint3 &operator-=(const NiNPShortPoint3 &);
    NiNPShortPoint3 &operator*=(float);
    NiNPShortPoint3 &operator/=(float);
    float Length() const;
    short SqrLength() const;
    short Dot(const NiNPShortPoint3 &) const;
    NiNPShortPoint3 Cross(const NiNPShortPoint3 &) const;
    float GetFloatX() const;
    float GetFloatY() const;
    float GetFloatZ() const;
    void SetFloatX(float);
    void SetFloatY(float);
    void SetFloatZ(float);
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);
    char *GetViewerString(const char *) const;

    static NiNPShortPoint3
    ComponentProduct(const NiNPShortPoint3 &, const NiNPShortPoint3 &);
    static const NiNPShortPoint3 &GetZERO();
    static const NiNPShortPoint3 &GetUNIT_X();
    static const NiNPShortPoint3 &GetUNIT_Y();
    static const NiNPShortPoint3 &GetUNIT_Z();
    static const NiNPShortPoint3 &GetUNIT_ALL();
};
