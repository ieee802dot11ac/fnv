#pragma once

#include "nimain/NiObjectNET.h"
#include "nimain/NiUpdateData.h"
class NiProperty : public NiObjectNET {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiProperty(const NiProperty &);
    NiProperty();
    virtual int Type() const;
    virtual void Update(NiUpdateData &);
    virtual ~NiProperty();

protected:
    void CopyMembers(NiProperty *, NiCloningProcess &);
};
