#pragma once

#include "nimain/NiObject.h"
#include "nimain/NiTPointerMap.h"
#include "nimain/NiTPrimitiveSet.h"
#include "nimain/NiTriBasedGeomData.h"

class NiSkinData;

class NiSkinPartition : public NiObject {
public:
    class Interaction {
    public:
        uint m_uiBone; // 0x0
        float m_fWeight; // 0x4
    };

    class VertexInteractions : public NiTPrimitiveSet<Interaction> {
    public:
        unsigned int GetBone(unsigned int) const;
        float GetWeight(unsigned int) const;
        float FindWeight(unsigned int) const;
        bool RemoveBone(unsigned int);
        void Unitize();
        void SortByWeight();
        void Truncate(unsigned int);
        bool SameBones(const VertexInteractions &) const;
        VertexInteractions(const VertexInteractions &);
        VertexInteractions();
        ~VertexInteractions();

    protected:
        static int CompareWeights(const void *, const void *);
    };

    class BoneSet : public NiTPrimitiveSet<u16> {
    public:
        bool Contains(const BoneSet &) const;
        uint MergedSize(const BoneSet &) const;
        void Merge(const BoneSet &);
        bool ContainsTriangle(const u16 *, const VertexInteractions *) const;
        bool ContainsVertex(const VertexInteractions &) const;
        void Sort();
        void SetWValue(int);
        int QWValue();
        BoneSet(const BoneSet &);
        BoneSet();
        ~BoneSet();

    protected:
        int iWValue; // 0xc

        static int CompareBones(const void *, const void *);
    };

    class BoneSetMerger {
    public:
        BoneSetMerger(const BoneSet &, const BoneSet &);
        bool Done() const;
        u16 GetNext();

    protected:
        uint m_uiIndex[2]; // 0x00
        u16 m_usEl[2]; // 0x08
        const BoneSet &m_kSet0; // 0x0c
        const BoneSet &m_kSet1; // 0x10
    };

    class TriangleSet : public NiTPrimitiveSet<u16> {
    public:
        void AddTriangles(uint, const uint *, uint);
        TriangleSet(const TriangleSet &);
        TriangleSet();
        ~TriangleSet();
    };

    class Partition { /* Size=0x2c */
    public:
        u16 *m_pusBones; // 0x04
        float *m_pfWeights; // 0x08
        u16 *m_pusVertexMap; // 0x0c
        u8 *m_pucBonePalette; // 0x10
        u16 *m_pusTriList; // 0x14
        u16 *m_pusStripLengths; // 0x18
        u16 m_usVertices; // 0x1c
        u16 m_usTriangles; // 0x1e
        u16 m_usBones; // 0x20
        u16 m_usStrips; // 0x22
        u16 m_usBonesPerVertex; // 0x24
        NiGeometryData::RendererData *m_pkBuffData; // 0x28

        Partition(const Partition &);
        Partition();
        virtual ~Partition();
        void Create(
            const TriangleSet &,
            const BoneSet &,
            const NiTriBasedGeomData *,
            const VertexInteractions *,
            bool,
            bool,
            u8,
            uint
        );
        void LoadBinary(NiStream &);
        void SaveBinary(NiStream &);
        bool IsEqual(const Partition &);
        void PostPrecache(bool);
        uint GetStripLengthSum() const;

    protected:
        u16 *CreateVertexMap(const TriangleSet &, const NiTriBasedGeomData *);
        void
        CreateTriangleList(const TriangleSet &, const NiTriBasedGeomData *, const u16 *);
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiSkinPartition(const NiSkinPartition &);
    NiSkinPartition();
    virtual ~NiSkinPartition();
    bool MakePartitions(
        const NiTriBasedGeomData *, const NiSkinData *, u8, u8, bool, int *, u16 *, bool *
    );
    void ReplacePartitions(Partition *, uint);
    bool ResizePartitions(u8, u8);
    uint GetPartitionCount() const;
    const Partition *GetPartitions() const;
    Partition *GetPartitions();
    void SetPartitions(Partition *, uint);

    static NiObject *CreateObject();

protected:
    bool MakeBoneSets(
        const NiTriBasedGeomData *,
        const NiSkinData *,
        u8,
        VertexInteractions *,
        NiTPrimitiveSet<BoneSet *> &,
        uint *&,
        const int *
    );
    VertexInteractions *CreateVertexInteractions(uint, const NiSkinData *);
    bool
    RemoveExcessInteractions(const NiTriBasedGeomData *, u8, u8, VertexInteractions *);
    void CreateInitialBoneSets(
        const NiTriBasedGeomData *,
        VertexInteractions *,
        NiTPrimitiveSet<BoneSet *> &,
        const int *
    );
    void MergeBoneSets(u8, NiTPrimitiveSet<BoneSet *> &);
    void
    MakeBoneMap(NiTPointerMap<uint, float> &, const u16 *, const VertexInteractions *);
    void MergeIntoPartition(Partition &, Partition *, uint, uint, u8, u8, u16 *, uint);

    uint m_uiPartitions; // 0x8
    Partition *m_pkPartitions; // 0xc

    static int AssignTriangle(
        NiTPrimitiveSet<BoneSet *> &, const u16 *, VertexInteractions *, bool *, bool
    );
};
