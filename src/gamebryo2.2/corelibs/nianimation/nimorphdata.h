#pragma once

#include "bscore/memorymanager.h"
#include "nimain/niobject.h"
#include "nimain/nipoint3.h"

class NiMorphData : public NiObject {
public:
    class MorphTarget {
    public:
        MorphTarget(const NiMorphData::MorphTarget &);
        MorphTarget();
        ~MorphTarget();
        NiPoint3 *GetTargetVerts() const;
        NiPoint3 GetTargetVert(uint) const;
        void ReplaceTargetVerts(NiPoint3 *);
        void SetName(const NiFixedString &);
        const NiFixedString &GetName();
        void LoadBinary(NiStream &, uint);
        void SaveBinary(NiStream &, uint);
        void RegisterStreamables(NiStream &);
        // NiInterpolator* GetLegacyInterpolator();
        // void SetLegacyInterpolator(NiInterpolator*);
        float GetLegacyWeight() const;
        bool IsEqual(MorphTarget *, uint);

        BS_MEM_OVERLOADS

    protected:
        NiPoint3 *m_aTargetVerts; // 0x0
        NiFixedString m_kName; // 0x4
        float m_fLegacyWeight; // 0x8
        // NiPointer<NiInterpolator> m_spLegacyInterpolator; // 0xc
    };
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiMorphData(const NiMorphData &);
    NiMorphData();
    virtual ~NiMorphData();
    uint GetNumTargets() const;
    uint GetNumVertsPerTarget() const;
    NiMorphData::MorphTarget *GetTargets() const;
    NiMorphData::MorphTarget *GetTarget(uint) const;
    void ReplaceTargets(NiMorphData::MorphTarget *, uint, uint);
    NiPoint3 *GetTargetVerts(uint) const;
    bool GetRelativeTargets() const;
    void SetRelativeTargets(bool);
    void SetAndAdjustRelativeTargets(bool);
    NiMorphData &operator=(const NiMorphData &);

    static NiObject *CreateObject();

protected:
    uint m_uiNumTargets; // 0x08
    uint m_uiNumVertsPerTarget; // 0x0c
    NiMorphData::MorphTarget *m_aMorphTargets; // 0x10
    bool m_bRelativeTargets; // 0x14
};
