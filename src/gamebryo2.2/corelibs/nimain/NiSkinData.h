#pragma once

#include "nimain/NiSkinPartition.h"

class NiSkinData : public NiObject {
public:
    class BoneVertData {
    public:
        u16 m_usVert; // 0x0
        float m_fWeight; // 0x4

        BoneVertData();
        void Endian();

        static int Compare(const void *, const void *);
    };

    class BoneData {
    public:
        NiTransform m_kSkinToBone; // 0x00
        NiBound m_kBound; // 0x40
        NiSkinData::BoneVertData *m_pkBoneVertData; // 0x50
        u16 m_usVerts; // 0x54

        BoneData();
        void SortAndMerge();
        NiSkinData::BoneData &operator=(const NiSkinData::BoneData &);
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    NiSkinData(const NiSkinData &);
    NiSkinData();
    NiSkinData(unsigned int, BoneData *, const NiTransform &, const NiPoint3 *);
    virtual ~NiSkinData();
    NiSkinPartition *GetSkinPartition(bool) const;
    unsigned int GetBoneCount() const;
    BoneData *GetBoneData() const;
    const NiTransform &GetRootParentToSkin() const;
    void SetSkinPartition(NiSkinPartition *, bool);
    bool RemoveUnusedVertices(const int *);
    void SortAndMergeBoneData();
    void FreeBoneVertData();

    static NiObject *CreateObject();

protected:
    void ComputeBoneBounds(const NiPoint3 *);

    NiPointer<NiSkinPartition> m_spSkinPartition; // 0x08
    NiTransform m_kRootParentToSkin; // 0x10
    BoneData *m_pkBoneData; // 0x50
    uint m_uiBones; // 0x54
};
