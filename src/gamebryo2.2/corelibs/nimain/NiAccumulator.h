#pragma once

#include "nimain/NiCamera.h"
#include "nimain/NiObject.h"
#include "nimain/NiVisibleArray.h"

class NiAccumulator : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    NiAccumulator(const NiAccumulator &);
    NiAccumulator();
    virtual ~NiAccumulator();
    virtual void StartAccumulating(const NiCamera *);
    virtual void FinishAccumulating();
    virtual void RegisterObjectArray(NiVisibleArray &);
    virtual bool RegisterObject(NiGeometry *);
    bool IsAccumulating() const;
    virtual bool AddShared(NiAVObject *);
    virtual void ClearSharedMap();

protected:
    void CopyMembers(NiAccumulator *, NiCloningProcess &);
    const NiCamera *m_pkCamera; // 0x8
};
