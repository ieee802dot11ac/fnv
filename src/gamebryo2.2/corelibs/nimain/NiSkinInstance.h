#pragma once

#include "nimain/NiAVObject.h"
#include "nimain/NiGeometryData.h"
#include "nimain/NiObject.h"
#include "nimain/NiSkinPartition.h"
class NiSkinInstance : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiSkinInstance(const NiSkinInstance &);
    NiSkinInstance();
    NiSkinInstance(NiSkinData *, NiAVObject *, NiAVObject **);
    virtual ~NiSkinInstance();
    NiSkinData *GetSkinData() const;
    NiAVObject *GetRootParent() const;
    NiAVObject **GetBones() const;
    NiSkinPartition *GetSkinPartition() const;
    void Deform(
        NiGeometryDataIteratorNiPoint3 *,
        NiGeometryDataIteratorNiBlendWeights *,
        NiGeometryDataIteratorNiBlendIndices *,
        NiGeometryDataIteratorNiPoint3 *,
        uint,
        NiPoint3 *,
        NiPoint3 *,
        uint
    ) const;
    void Deform(
        const NiPoint3 *,
        const NiPoint3 *,
        uint,
        NiPoint3 *,
        NiPoint3 *,
        NiPoint3 *,
        NiPoint3 *,
        uint
    ) const;
    void Deform(
        const NiGeometryData *, NiPoint3 *, NiPoint3 *, NiPoint3 *, NiPoint3 *, uint
    ) const;
    virtual void SetBound(BSNiBound *);
    void UpdateModelBound(NiBound &);
    void GetWorldToSkinTransform(NiTransform &) const;
    void ConcatWorldToSkinTransform(const NiTransform &, NiTransform &) const;
    void GetBoneWorldTransform(uint, NiTransform &) const;
    void ConcatBoneWorldTransform(uint, const NiTransform &, NiTransform &) const;
    void GetSkinToBoneTransform(uint, NiTransform &) const;
    void ConcatSkinToBoneTransform(uint, const NiTransform &, NiTransform &) const;
    void ConcatBoneWorldTransformAndSkinToBoneTransform(uint, NiTransform &) const;
    bool ContainsVertexData(NiShaderDeclaration::ShaderParameter) const;
    void GetBoneToRootParentTransform(NiTransform &, uint) const;
    void GetBoneToRPHelper(NiAVObject *, NiAVObject *, NiTransform &) const;
    NiAVObject *GetLowestCommonAncestor(NiAVObject *, NiAVObject *) const;
    void SetSkinData(NiSkinData *);
    void SetRootParent(NiAVObject *);
    void SetBone(uint, NiAVObject *);
    void SetSkinPartition(NiSkinPartition *);
    uint GetFrameID() const;
    void SetFrameID(uint);
    void SetBoneMatrices(void *, uint);
    void SetBoneMatrixInfo(uint, uint);
    uint GetNumBoneMatrices() const;
    uint GetBoneMatrixRegisters() const;
    void *GetBoneMatrices() const;
    uint GetBoneMatrixAllocatedSize() const;
    virtual void PostLinkObject(NiStream &);

    static NiObject *CreateObject();

protected:
    void CopyMembers(NiSkinInstance *, NiCloningProcess &);
    bool NeedClone(NiCloningProcess &) const;
    NiPointer<NiSkinData> m_spSkinData; // 0x08
    NiPointer<NiSkinPartition> m_spSkinPartition; // 0x0c
    NiAVObject *m_pkRootParent; // 0x10
    NiAVObject **m_ppkBones; // 0x14
    uint m_uiFrameID; // 0x18
    uint m_uiNumMatrices; // 0x1c
    uint m_uiNumRegisters; // 0x20
    uint m_uiAllocatedSize; // 0x24
    void *m_pvBoneMatrices; // 0x28
    void *m_pvPrevBoneMatrices; // 0x2c
    void *m_pvSkinToWorldWorldToSkinMatrix; // 0x30
};
