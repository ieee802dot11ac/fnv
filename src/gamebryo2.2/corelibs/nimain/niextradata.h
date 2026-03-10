#pragma once

#include "niobject.h"
#include "nifixedstring.h"

class NiExtraData : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    NiExtraData(const NiExtraData &);
    NiExtraData(const NiFixedString &);
    NiExtraData();
    virtual ~NiExtraData();
    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    const NiFixedString &GetName() const;
    void SetName(const NiFixedString &);
    virtual bool IsStreamable() const;
    virtual bool IsCloneable() const;
    void ClearName();
    NiExtraData &operator=(const NiExtraData &);

    static NiObject *CreateObject();

protected:
    void CopyMembers(NiExtraData *, NiCloningProcess &);
    NiFixedString m_kName; // 0x8
};
