#pragma once

#include "nimain/NiPoint3.h"
#include "LIBCMT/vectorintrinsics.h"
#include "nimain/NiPoint4.h"

class NiMatrix3 { /* Size=0x30 */
public:
    NiPoint4 m_pEntry[3];
    static const NiMatrix3 ZERO;
    static const NiMatrix3 IDENTITY;

    NiMatrix3(const NiPoint3 &, const NiPoint3 &, const NiPoint3 &);
    NiMatrix3();
    void GetRow(unsigned int, float *) const;
    void GetRow(unsigned int, float &, float &, float &) const;
    void GetRow(unsigned int, NiPoint3 &) const;
    void SetRow(unsigned int, const float *);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, const NiPoint3 &);
    void GetCol(unsigned int, float *) const;
    void GetCol(unsigned int, float &, float &, float &) const;
    void GetCol(unsigned int, NiPoint3 &) const;
    void SetCol(unsigned int, const float *);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, const NiPoint3 &);
    float GetEntry(unsigned int, unsigned int) const;
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void MakeIdentity();
    void MakeDiagonal(float, float, float);
    void MakeXRotation(float);
    void MakeYRotation(float);
    void MakeZRotation(float);
    void MakeZRotationQ(float);
    void MakeRotation(float, const NiPoint3 &);
    void MakeRotation(float, float, float, float);
    bool operator==(const NiMatrix3 &) const;
    bool operator!=(const NiMatrix3 &) const;
    NiMatrix3 operator+(const NiMatrix3 &) const;
    NiMatrix3 operator-(const NiMatrix3 &) const;
    NiPoint3 operator*(const NiPoint3 &) const;
    NiMatrix3 operator*(float) const;
    NiMatrix3 operator*(const NiMatrix3 &) const;
    bool Inverse(NiMatrix3 &) const;
    NiMatrix3 Inverse() const;
    NiMatrix3 Transpose() const;
    void ExtractAngleAndAxis(float &, float &, float &, float &) const;
    bool ToEulerAnglesXYZ(float &, float &, float &) const;
    bool ToEulerAnglesXZY(float &, float &, float &) const;
    bool ToEulerAnglesYXZ(float &, float &, float &) const;
    bool ToEulerAnglesYZX(float &, float &, float &) const;
    bool ToEulerAnglesZXY(float &, float &, float &) const;
    bool ToEulerAnglesZYX(float &, float &, float &) const;
    void FromEulerAnglesXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void FromEulerAnglesZXY(float, float, float);
    void FromEulerAnglesZYX(float, float, float);
    bool Reorthogonalize();
    NiMatrix3 TransposeTimes(const NiMatrix3 &) const;
    NiMatrix3 Congruence(const NiMatrix3 &) const;
    void EigenSolveSymmetric(float *, NiPoint3 *);
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);
    char *GetViewerString(const char *) const;
    void Scale(float, float, float);
    bool Tridiagonal(float *, float *);
    bool QLAlgorithm(float *, float *);
    float Determinant();

    static void TransformVertices(
        const NiMatrix3 &, const NiPoint3 &, unsigned int, const NiPoint3 *, NiPoint3 *
    );
    static void
    TransformNormals(const NiMatrix3 &, unsigned int, const NiPoint3 *, NiPoint3 *);
    static void TransformVerticesAndNormals(
        const NiMatrix3 &,
        const NiPoint3 &,
        unsigned int,
        const NiPoint3 *,
        NiPoint3 *,
        const NiPoint3 *,
        NiPoint3 *
    );
    static XMMATRIX XMLoadFloat3x4(const float *);
    static void XMStoreFloat3x4(float *, XMMATRIX);
};
