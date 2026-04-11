#include "indexedgeometry.h"
#include "lib/speedtree/speedtreert.h"
#include "macros.h"

CIndexedGeometry::CIndexedGeometry(CWindEngine *pWindEngine, bool bRetainTexCoords)
    : m_bRetainTexCoords(bRetainTexCoords), m_pWindEngine(pWindEngine),
      m_bVertexWeighting(false), m_bManualLighting(false), m_pVertexWindComputed(nullptr),
      m_nVertexSize(0), m_bValid(1), m_eWindMethod(CSpeedTreeRT::WIND_NONE),
      m_nNumLodLevels(0), m_nVertexCounter(0), m_nVertexCounterLodLevel(0),
      m_nStripCounter(0
      ) { ADDSTACK(0x80) };

CIndexedGeometry::~CIndexedGeometry() {
    void *wind_ptr = m_pVertexWindComputed;
    SPEEDTREE_FREE(wind_ptr);
    m_pVertexWindComputed = nullptr;
    DeleteIndexData();
    ADDSTACK(0x40)
}

void CIndexedGeometry::CombineStrips(bool bToggleFaceOrdering) {}

// void CIndexedGeometry::ComputeExtents(CRegion &cExtents) const {}

void CIndexedGeometry::SetNumLodLevels(u16 nLevels) {
    m_vStripLengths.clear();
    m_vStrips.clear();
    m_vTriangleCounts.clear();
    m_nNumLodLevels = nLevels;
    m_vStripLengths.resize(nLevels);
    m_vStrips.resize(nLevels);
    m_vTriangleCounts.resize(nLevels);
    for (int i = 0; i < nLevels; i++) {
        m_vTriangleCounts[i] = 0;
    }
    ADDSTACK(0xB0)
}

// void CIndexedGeometry::Transform(CTransform const &cTransform) {}

void CIndexedGeometry::AddStrip(u16 nLodLevel, u16 *pStrip, u16 nStripLength) {}

void CIndexedGeometry::AddVertexColor(const float *pColor) {}

void CIndexedGeometry::AddVertexCoord(const float *pCoord) {
    float coords[3];
    coords[0] = pCoord[0];
    coords[1] = pCoord[1];
    coords[2] = pCoord[2];
    m_vCoords.push_back(coords[0]);
    m_vCoords.push_back(coords[1]);
    m_vCoords.push_back(coords[2]);
    if (m_bVertexWeighting && m_eWindMethod == CSpeedTreeRT::WIND_CPU) {
        m_vOrigCoords.push_back(coords[0]);
        m_vOrigCoords.push_back(coords[1]);
        m_vOrigCoords.push_back(coords[2]);
    }
}

void CIndexedGeometry::AddVertexNormal(const float *pNormal) {
    ADDSTACK(0x20)
    m_vNormals.push_back(pNormal[0]);
    m_vNormals.push_back(pNormal[1]);
    m_vNormals.push_back(pNormal[2]);
}

void CIndexedGeometry::AddVertexTexCoord0(const float *pTexCoord, short sIndex) {}

void CIndexedGeometry::AddVertexTexCoord1(const float *pTexCoord) {
    m_vTexCoords1.push_back(pTexCoord[0]);
    if (CSpeedTreeRT::GetTextureFlip()) {
        float inv_v = -pTexCoord[1];
        m_vTexCoords1.push_back(inv_v);
    } else {
        m_vTexCoords1.push_back(pTexCoord[1]);
    }
    ADDSTACK(0x10)
}

void CIndexedGeometry::AddVertexWind(float fWindWeight, u8 ucWindMatrixIndex) {}

void CIndexedGeometry::AddVertexTangent(const float *pTangent) {
    float tangents[3];
    tangents[0] = pTangent[0];
    tangents[1] = pTangent[1];
    tangents[2] = pTangent[2];
    m_vTangents.push_back(tangents[0]);
    m_vTangents.push_back(tangents[1]);
    m_vTangents.push_back(tangents[2]);
    ADDSTACK(0x10)
}

void CIndexedGeometry::AddVertexBinormal(const float *pBinormal) {
    float binormals[3];
    binormals[0] = pBinormal[0];
    binormals[1] = pBinormal[1];
    binormals[2] = pBinormal[2];
    m_vBinormals.push_back(binormals[0]);
    m_vBinormals.push_back(binormals[1]);
    m_vBinormals.push_back(binormals[2]);
    ADDSTACK(0x10)
}

void CIndexedGeometry::ResetStripCounter(u16 nLodLevel) {
    m_nVertexCounterLodLevel = nLodLevel;
    m_nStripCounter = 0;
    m_vTriangleCounts[nLodLevel] = 0;
}

u16 **CIndexedGeometry::GetStripsPointer(u16 nLodLevel) const {
    return m_vStrips[nLodLevel].size() != 0
        ? const_cast<u16 **>(m_vStrips[nLodLevel].data())
        : nullptr;
}

bool CIndexedGeometry::ComputeWindEffect(u16 nLodLevel) { return false; }

void CIndexedGeometry::DeleteLodStrip(u16 usLodLevel) {}

void CIndexedGeometry::DeleteIndexData() {}

const float *CIndexedGeometry::GetVertexCoord(uint nVertexIndex) const {
    return &m_vCoords[nVertexIndex * 3];
}

const float *CIndexedGeometry::GetVertexTexCoord0(uint nVertexIndex) const {
    return &m_vTexCoords0[nVertexIndex * 2];
}

const float *CIndexedGeometry::GetOrigVertexCoord(uint nVertexIndex) const {
    return &m_vOrigCoords[nVertexIndex * 3];
}

void CIndexedGeometry::ChangeTexCoord(u8 chChangedMapIndex, float *pNewTexCoords) {}
