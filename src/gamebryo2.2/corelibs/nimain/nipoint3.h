#pragma once
#include <types.h>

class NiPoint3 {
public:
    float x; // 0x0
    float y; // 0x4
    float z; // 0x8
    NiPoint3(float, float, float);
    NiPoint3();
    float &operator[](int);
    float const &operator[](int) const;
    bool operator==(NiPoint3 const &) const;
    bool operator!=(NiPoint3 const &) const;
    NiPoint3 operator+(NiPoint3 const &) const;
    NiPoint3 operator-() const;
    NiPoint3 operator-(NiPoint3 const &) const;
    NiPoint3 operator*(float) const;
    float operator*(NiPoint3 const &) const;
    NiPoint3 operator/(float) const;
    static NiPoint3 ComponentProduct(NiPoint3 const &, NiPoint3 const &);
    NiPoint3 &operator+=(NiPoint3 const &);
    NiPoint3 &operator-=(NiPoint3 const &);
    NiPoint3 &operator*=(float);
    NiPoint3 &operator/=(float);
    float Length() const;
    float SqrLength() const;
    float XYLength() const;
    float SqrXYLength() const;
    float Dot(NiPoint3 const &) const;
    void Unitize();
    float UnitizeGetLength();
    NiPoint3 Cross(NiPoint3 const &) const;
    NiPoint3 UnitCross(NiPoint3 const &) const;
    NiPoint3 Perpendicular() const;
    static NiPoint3 const ZERO;
    static NiPoint3 const UNIT_X;
    static NiPoint3 const UNIT_Y;
    static NiPoint3 const UNIT_Z;
    static NiPoint3 const UNIT_ALL;
    static NiPoint3 const INFINITY_POINT3;
    // static void LoadBinary(NiStream &, NiPoint3 *, uint);
    // void LoadBinary(NiStream &);
    // static void SaveBinary(NiStream &, NiPoint3 *, uint);
    // void SaveBinary(NiStream &);
    char *GetViewerString(char const *) const;
    static void _SDMInit();
    static void _SDMShutdown();
    static void UnitizeVectors(NiPoint3 *, uint, uint);
    static void UnitizeVector(NiPoint3 &);
    static float VectorLength(NiPoint3 const &);
    static void PointsPlusEqualFloatTimesPoints(
        NiPoint3 *__restrict, float, NiPoint3 const *__restrict, uint
    );
    static void WeightedPointsPlusWeightedPoints(
        NiPoint3 *__restrict, float, NiPoint3 const *__restrict, uint
    );

protected:
    static uint *InitSqrtTable();
    static uint *ms_pSqrtTable;
};
