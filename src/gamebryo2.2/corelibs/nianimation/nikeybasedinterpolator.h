#pragma once

#include "nianimation/niinterpolator.h"
#include "nianimation/nianimationkey.h"

class NiKeyBasedInterpolator : public NiInterpolator {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const { return &ms_RTTI; }
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiKeyBasedInterpolator();
    virtual uint16_t GetKeyChannelCount() const;
    virtual uint32_t GetKeyCount(uint16_t) const;
    virtual NiAnimationKey::KeyType GetKeyType(uint16_t) const;
    virtual NiAnimationKey::KeyContent GetKeyContent(uint16_t) const;
    virtual NiAnimationKey *GetKeyArray(uint16_t) const;
    virtual unsigned char GetKeyStride(uint16_t) const;
    virtual bool GetChannelPosed(uint16_t) const;
    uint32_t GetAllocatedSize(uint16_t) const;
    NiAnimationKey *GetKeyAt(uint, u16) const;
    void FillDerivedValues(uint16_t);
    NiAnimationKey *
    GetAnim(uint32_t &, NiAnimationKey::KeyType &, unsigned char &, uint16_t) const;
    virtual void GetActiveTimeRange(float &, float &) const;
    NiKeyBasedInterpolator(const NiKeyBasedInterpolator &);
    NiKeyBasedInterpolator &operator=(const NiKeyBasedInterpolator &);

protected:
    NiKeyBasedInterpolator();
    void CopyMembers(NiKeyBasedInterpolator *, NiCloningProcess &);
};
