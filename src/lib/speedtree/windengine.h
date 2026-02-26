#pragma once

#include "speedtreert.h"

class CWindMatrices {
public:
    CWindMatrices();
    ~CWindMatrices();
    // CTransform &GetMatrix(unsigned short) const;
    unsigned short GetSize() const;
    void Resize(unsigned short);
    void SetMatrix(unsigned short, float const *);

private:
    unsigned short m_usNumMatrices; // 0x0
    // CTransform *m_pMatrices; // 0x4
};

class CWindEngine {
public:
    CWindEngine();
    float GetWindStrength() const;
    float SetWindStrength(float, float, float);
    void SetWindStrengthAndLeafAngles(float, float const *, float const *, uint);
    // void Init(SIdvWindInfo const &);
    static void SetTime(float);
    float GetFrequencyTimeShift() const;
    CSpeedTreeRT::EWindMethod GetBranchWindMethod() const;
    void SetBranchWindMethod(CSpeedTreeRT::EWindMethod);
    CSpeedTreeRT::EWindMethod GetFrondWindMethod() const;
    void SetFrondWindMethod(CSpeedTreeRT::EWindMethod);
    CSpeedTreeRT::EWindMethod GetLeafWindMethod() const;
    void SetLeafWindMethod(CSpeedTreeRT::EWindMethod);
    bool GetLeafRockingState() const;
    void SetLeafRockingState(bool);
    // void RockLeaf(float, float, int, CRotTransform &) const;
    // void RockLeaf(float, float, int, float, CRotTransform &) const;
    static uint GetNumWindMatrices();
    static void SetNumWindMatrices(unsigned short);
    // static CTransform &GetWindMatrix(unsigned short);
    static void SetWindMatrix(unsigned short, float const *);
    void GetLocalMatrices(uint &, uint &);
    void SetLocalMatrices(uint, uint);
    void ResetLeafWindState();
    bool UsingExternalRockAngles() const;
    void SetSpeedWindRockScalar(float);
    float GetSpeedWindRockScalar() const;
    void SetSpeedWindRustleScalar(float);
    float GetSpeedWindRustleScalar() const;

private:
    static float m_fTime;
    float m_fTimeFrequencyShift; // 0x0
    float m_fWindStrength; // 0x4
    CSpeedTreeRT::EWindMethod m_eBranchMethod; // 0x8
    CSpeedTreeRT::EWindMethod m_eFrondMethod; // 0xC
    CSpeedTreeRT::EWindMethod m_eLeafMethod; // 0x10
    bool m_bRockingLeaves; // 0x14
    float m_fLeafFactors[2]; // 0x18
    float m_fLeafFrequency; // 0x20
    float m_fLeafThrow; // 0x24
    uint m_nStartingMatrix; // 0x28
    uint m_nMatrixSpan; // 0x2C
    uint m_uiNumLeafAngles; // 0x30
    float const *m_pRockingAngles; // 0x34
    float const *m_pRustleAngles; // 0x38
    float m_fSpeedWindRockScalar; // 0x3C
    float m_fSpeedWindRustleScalar; // 0x40
    static CWindMatrices m_cWindMatrices;
};
