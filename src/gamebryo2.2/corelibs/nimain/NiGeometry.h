#pragma once

#include "nimain/NiAVObject.h"
#include "nimain/NiColor.h"
#include "nimain/NiPoint2.h"

class NiGeometry : public NiAVObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiGeometry();
    unsigned short GetVertexCount() const;
    NiPoint3 *GetVertices() const;
    void SetActiveVertexCount(unsigned short);
    unsigned short GetActiveVertexCount() const;
    void CreateNormals(bool);
    NiPoint3 *GetNormals() const;
    NiGeometryData::DataFlags GetNormalBinormalTangentMethod() const;
    void StoreNormalBinormalTangent(NiGeometryData::DataFlags);
    void SetModelBound(const NiBound &);
    NiBound &GetModelBound() const;
    void CreateColors(bool);
    NiColorA *GetColors() const;
    void CreateTextures(bool, unsigned short);
    unsigned short GetTextureSets() const;
    NiPoint2 *GetTextures() const;
    NiPoint2 *GetTextureSet(unsigned short) const;
    void AppendTextureSet(NiPoint2 *);
    NiSkinInstance *GetSkinInstance() const;
    void SetSkinInstance(NiSkinInstance *);
    NiAdditionalGeometryData *GetAdditionalGeometryData();
    void SetAdditionalGeometryData(NiAdditionalGeometryData *);
    void SetSortObject(bool);
    bool GetSortObject() const;
    virtual void RenderImmediate(NiRenderer *);
    NiPropertyState *GetPropertyStateP();
    virtual NiGeometry *IsGeometry();
    virtual void OnlyRenderImmediate(NiRenderer *);
    virtual void SetBound(BSNiBound *);
    NiShader *GetShader() const;
    NiShader *GetShaderFromMaterial();
    void SetShader(NiShader *);
    virtual void SetModelData(NiGeometryData *);
    NiGeometryData *GetModelData() const;
    bool ContainsVertexData(NiShaderDeclaration::ShaderParameter) const;
    virtual void OnVisible(NiCullingProcess &);
    virtual void ApplyTransform(const NiMatrix3 &, const NiPoint3 &, bool);
    virtual void CalculateNormals();
    virtual void UpdatePropertiesDownward(NiPropertyState *);
    virtual void CalculateConsistency(bool);
    NiGeometryData::Consistency GetConsistency() const;
    void SetConsistency(NiGeometryData::Consistency);
    virtual void ProcessClone(NiCloningProcess &);
    virtual void PostLinkObject(NiStream &);
    virtual void SetSelectiveUpdateFlags(bool &, bool, bool &);
    virtual void PurgeRendererData(NiRenderer *);
    unsigned int QMemContext();
    NiGeometry(const NiGeometry &);
    virtual void UpdateWorldBound();

protected:
    NiGeometry();
    NiGeometry(NiGeometryData *);
    void CopyMembers(NiGeometry *, NiCloningProcess &);

    NiPropertyState m_PropertyState; // 0xc0
    NiPointer<NiGeometryData> m_spModelData; // 0xdc
    NiPointer<NiSkinInstance> m_spSkinInstance; // 0xe0
    NiShader *m_spShader; // 0xe4
    uint uiContext; // 0xe8
};
