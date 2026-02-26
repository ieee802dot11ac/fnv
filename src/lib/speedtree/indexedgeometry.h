#pragma once

#include "lib/speedtree/windengine.h"
#include <types.h>
#include <vector>
#include "speedtreert.h"

class CIndexedGeometry {
public:
    CIndexedGeometry(CWindEngine *, bool);
    ~CIndexedGeometry();
    void EnableManualLighting(bool);
    void EnableVertexWeighting(bool);
    void CombineStrips(bool);
    // void ComputeExtents(CRegion &) const;
    bool IsVertexWeightingEnabled() const;
    void SetNumLodLevels(u16);
    void SetWindMethod(CSpeedTreeRT::EWindMethod);
    // void Transform(CTransform const &);
    float GetTrunkWidth() const;
    void SetTrunkWidth(const float);
    float GetTrunkLength() const;
    void SetTrunkLength(const float);
    void AddStrip(u16 nLodLevel, u16 *pStrip, u16 nStripLength);
    void AddVertexColor(const float *pColor);
    void AddVertexCoord(const float *pCoord);
    void AddVertexNormal(const float *pNormal);
    void AddVertexTexCoord0(const float *pTexCoord, short sIndex);
    void AddVertexTexCoord1(const float *pTexCoord);
    void AddVertexWind(float fWindWeight, u8 ucWindMatrixIndex);
    void AddVertexTangent(const float *pTangent);
    void AddVertexBinormal(const float *pBinormal);
    void ResetStripCounter(u16 nLodLevel);
    u16 **GetStripsPointer(u16 nLodLevel) const;
    bool ComputeWindEffect(u16 nLodLevel);
    void DeleteLodStrip(u16 usLodLevel);
    void AdvanceStripCounter();
    u16 GetStripCounter();
    void SetVertexCounter(u16);
    u16 GetNumLodLevels();
    void AdvanceVertexCounter();
    u16 GetVertexCounter();
    void ResetVertexCounter();
    u16 GetNumStrips(short) const;
    u16 *GetStrip(u16, u16 &) const;
    u16 const *GetStripLengthsPointer(short) const;
    unsigned long const *GetVertexColors() const;
    const float *GetVertexCoords() const;
    const float *GetVertexNormals() const;
    const float *GetVertexBinormals() const;
    const float *GetVertexTangents() const;
    const float *GetVertexTexCoords0() const;
    const float *GetVertexTexCoords1() const;
    const float *GetVertexWindWeights() const;
    u8 const *GetVertexWindMatrixIndices() const;
    u32 GetTriangleCount(u16) const;
    const float *GetVertexCoord(uint) const;
    u16 GetVertexCount() const;
    u16 GetVertexSize() const;
    u8 const *GetVertexTexIndices() const;
    const float *GetVertexTexCoord0(uint) const;
    void FreeVertexColors();
    void FreeVertexWindData();
    void FreeVertexTexCoords1();
    void Invalidate();
    bool IsValid() const;
    void Validate();
    void ChangeTexCoord(u8, float *);

private:
    unsigned long ColorFloatsToLong(const float *) const;
    void DeleteIndexData();
    const float *GetOrigVertexCoord(uint) const;
    bool m_bRetainTexCoords; // 0x0
    CWindEngine *m_pWindEngine; // 0x4
    bool m_bVertexWeighting; // 0x8
    bool m_bManualLighting; // 0x9
    bool *m_pVertexWindComputed; // 0xC
    u16 m_nVertexSize; // 0x10
    bool m_bValid; // 0x12
    CSpeedTreeRT::EWindMethod m_eWindMethod; // 0x14
    float m_fTrunkWidth; // 0x18
    float m_fTrunkLength; // 0x1C
    u16 m_nNumLodLevels; // 0x20
    u16 m_nVertexCounter; // 0x22
    u16 m_nVertexCounterLodLevel; // 0x24
    u16 m_nStripCounter; // 0x26
    std::vector<int> m_vTriangleCounts; // 0x28
    std::vector<std::vector<u16> > m_vStripLengths; // 0x38
    std::vector<std::vector<u16 *> > m_vStrips; // 0x48
    std::vector<u32> m_vColors; // 0x58
    std::vector<float> m_vCoords; // 0x68
    std::vector<float> m_vOrigCoords; // 0x78
    std::vector<float> m_vNormals; // 0x88
    std::vector<float> m_vBinormals; // 0x98
    std::vector<float> m_vTangents; // 0xA8
    std::vector<float> m_vTexCoords0; // 0xB8
    std::vector<float> m_vOrigTexCoords0; // 0xC8
    std::vector<u8> m_vTexIndices0; // 0xD8
    std::vector<float> m_vTexCoords1; // 0xE8
    std::vector<float> m_vWindWeights; // 0xF8
    std::vector<u8> m_vWindMatrixIndices; // 0x108
};
