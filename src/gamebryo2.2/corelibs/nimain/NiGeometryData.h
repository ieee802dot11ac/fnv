#pragma once

#include "nimain/BSNiBound.h"
#include "nimain/NiBound.h"
#include "nimain/NiColor.h"
#include "nimain/NiGeometryDataIterators.h"
#include "nimain/NiObject.h"
#include "nimain/NiPoint2.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiShaderDeclaration.h"
#include "nimain/nismartpointer.h"
#include "nisystem/NiCriticalSection.h"

class NiAdditionalGeometryData;

class NiGeometryData : public NiObject {
public:
    enum Consistency {
        MUTABLE = 0x0000,
        STATIC = 0x4000,
        CONSISTENCY_MASK = 0x7000,
    };

    enum DataFlags {
        NBT_METHOD_NONE = 0x0000,
        NBT_METHOD_NDL = 0x1000,
        NBT_METHOD_DEPRECATED = 0x2000,
        NBT_METHOD_ATI = 0x3000,
        NBT_METHOD_MASK = 0xf000,
        TEXTURE_SET_MASK = 0x0001,
    };

    class RendererData {
    public:
        virtual ~RendererData();
        virtual bool ContainsVertexData(NiShaderDeclaration::ShaderParameter) const;
        RendererData();
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiGeometryData();
    void CreateVertices(bool);
    u16 GetVertexCount() const;
    const NiPoint3 *GetVertices() const;
    NiPoint3 *GetVertices();
    virtual void SetActiveVertexCount(u16);
    virtual u16 GetActiveVertexCount() const;
    void CreateNormals(bool);
    const NiPoint3 *GetNormals() const;
    NiPoint3 *GetNormals();
    DataFlags GetNormalBinormalTangentMethod() const;
    void StoreNormalBinormalTangent(DataFlags);
    virtual void SetBound(BSNiBound *);
    void SetBound(const NiBound &);
    const NiBound &GetBound() const;
    NiBound &GetBound();
    void ClearNormals();
    void CreateColors(bool);
    const NiColorA *GetColors() const;
    NiColorA *GetColors();
    void CreateTextures(bool, u16);
    u16 GetTextureSets() const;
    const NiPoint2 *GetTextures() const;
    NiPoint2 *GetTextures();
    const NiPoint2 *GetTextureSet(u16) const;
    NiPoint2 *GetTextureSet(u16);
    void AppendTextureSet(NiPoint2 *);
    void Replace(u16, NiPoint3 *, NiPoint3 *, NiColorA *, NiPoint2 *, u16, DataFlags);
    virtual class NiTriStripsData *IsTriStripsData();
    virtual class NiTriShapeData *IsTriShapeData();
    bool LockPackedVertexData(bool);
    void UnlockPackedVertexData();
    void GetVerticesIterator(NiGeometryDataIteratorNiPoint3 &);
    void GetBlendWeightsIterator(NiGeometryDataIteratorNiBlendWeights &);
    void GetBlendIndicesIterator(NiGeometryDataIteratorNiBlendIndices &);
    void GetNormalsIterator(NiGeometryDataIteratorNiPoint3 &);
    void GetColorsIterator(NiGeometryDataIteratorNiColorA &);
    void GetTextureSetIterator(u16, NiGeometryDataIteratorNiPoint2 &);
    Consistency GetConsistency() const;
    void SetConsistency(Consistency);
    void MarkAsChanged(u16);
    unsigned int GetKeepFlags() const;
    void SetKeepFlags(unsigned int);
    RendererData *GetRendererData() const;
    void SetRendererData(RendererData *);
    unsigned int GetCompressFlags() const;
    void SetCompressFlags(unsigned int);
    NiAdditionalGeometryData *GetAdditionalGeometryData();
    void SetAdditionalGeometryData(NiAdditionalGeometryData *);
    virtual bool ContainsVertexData(NiShaderDeclaration::ShaderParameter) const;
    virtual unsigned int GetBlockAllocationSize() const;
    virtual NiObjectGroup *GetGroup() const;
    virtual void SetGroup(NiObjectGroup *);
    u16 GetRevisionID() const;
    void ClearRevisionID();
    u16 GetUniqueID() const;
    void SetData(u16, NiPoint3 *, NiPoint3 *, NiColorA *, NiPoint2 *, u16, DataFlags);
    void ReplaceData(u16, NiPoint3 *, NiPoint3 *, NiColorA *, NiPoint2 *, u16, DataFlags);
    virtual void CalculateNormals();
    void IndexSort(u16 *&, u16 *&, u8) const;
    int VertexCompare(u16, u16, u8) const;
    NiGeometryData(const NiGeometryData &);

protected:
    NiGeometryData();
    NiGeometryData(u16, NiPoint3 *, NiPoint3 *, NiColorA *, NiPoint2 *, u16, DataFlags);
    void IndexQSort(u16 *, u8, int, int) const;
    int ChoosePivot(u16 *, u8, int, int) const;
    void SetNumTextureSets(u16);
    void SetNormalBinormalTangentMethod(DataFlags);

protected:
    u16 m_usVertices; // 0x08
    u16 m_usID; // 0x0a
    u16 m_usDataFlags; // 0x0c
    u16 m_usDirtyFlags; // 0x0e
    NiBound m_kBound; // 0x10
    NiPoint3 *m_pkVertex; // 0x20
    NiPoint3 *m_pkNormal; // 0x24
    NiColorA *m_pkColor; // 0x28
    NiPoint2 *m_pkTexture; // 0x2c
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData; // 0x30
    RendererData *m_pkBuffData; // 0x34
    u8 m_ucKeepFlags; // 0x38
    u8 m_ucCompressFlags; // 0x39
    bool m_bVBLocked; // 0x3a
    bool m_bVBLockWrite; // 0x3b
    bool m_bSaveVertexData; // 0x3c

    static NiObjectGroup *m_pkGroup;
    static u16 ms_usNextID;
    static NiCriticalSection ms_kCritSec;
};
