#include "indexedgeometry.h"

// CIndexedGeometry::CIndexedGeometry(CWindEngine *pWindEngine, bool bRetainTexCoords) {}
CIndexedGeometry::~CIndexedGeometry() {}
void CIndexedGeometry::CombineStrips(bool bToggleFaceOrdering) {}
// void CIndexedGeometry::ComputeExtents(CRegion &cExtents) const {}
void CIndexedGeometry::SetNumLodLevels(u16 nLevels) {}
// void CIndexedGeometry::Transform(CTransform const &cTransform) {}
void CIndexedGeometry::AddStrip(u16 nLodLevel, u16 *pStrip, u16 nStripLength) {}
void CIndexedGeometry::AddVertexColor(const float *pColor) {}
void CIndexedGeometry::AddVertexCoord(const float *pCoord) {}
void CIndexedGeometry::AddVertexNormal(const float *pNormal) {}
void CIndexedGeometry::AddVertexTexCoord0(const float *pTexCoord, short sIndex) {}
void CIndexedGeometry::AddVertexTexCoord1(const float *pTexCoord) {}
void CIndexedGeometry::AddVertexWind(float fWindWeight, u8 ucWindMatrixIndex) {}
void CIndexedGeometry::AddVertexTangent(const float *pTangent) {}
void CIndexedGeometry::AddVertexBinormal(const float *pBinormal) {}
void CIndexedGeometry::ResetStripCounter(u16 nLodLevel) {}
u16 **CIndexedGeometry::GetStripsPointer(u16 nLodLevel) const { return nullptr; }
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
