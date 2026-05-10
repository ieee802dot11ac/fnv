#pragma once

#include "nianimation/NiColorData.h"
#include "nianimation/NiColorKey.h"
#include "nianimation/NiKeyBasedInterpolator.h"
class NiColorInterpolator : public NiKeyBasedInterpolator {
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
    NiColorInterpolator(const NiColorInterpolator &);
    NiColorInterpolator(NiColorA);
    NiColorInterpolator(NiColorData *);
    virtual bool Update(float, NiObjectNET *, NiColorA &);
    virtual bool IsColorAValueSupported() const;
    NiColorData *GetColorData() const;
    void SetColorData(NiColorData *);
    void SetPoseValue(NiColorA);
    NiColorKey *GetKeys(uint &, NiAnimationKey::KeyType &, u8 &) const;
    void ReplaceKeys(NiColorKey *, uint, NiAnimationKey::KeyType);
    void SetKeys(NiColorKey *, uint, NiAnimationKey::KeyType);
    virtual u16 GetKeyChannelCount() const;
    virtual uint GetKeyCount(u16) const;
    virtual NiAnimationKey::KeyType GetKeyType(u16) const;
    virtual NiAnimationKey::KeyContent GetKeyContent(u16) const;
    virtual NiAnimationKey *GetKeyArray(u16) const;
    virtual u8 GetKeyStride(u16) const;
    virtual bool GetChannelPosed(u16) const;
    virtual void Collapse();
    virtual void GuaranteeTimeRange(float, float);
    virtual NiInterpolator *GetSequenceInterpolator(float, float);
    virtual ~NiColorInterpolator();

    static NiObject *CreateObject();

protected:
    void CopyMembers(NiColorInterpolator *, NiCloningProcess &);

    NiColorA m_kColorValue; // 0x0c
    NiPointer<NiColorData> m_spColorData; // 0x1c
    uint m_uiLastIdx; // 0x20
};
