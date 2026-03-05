#pragma once

#include "nimain/niobject.h"
#include "nimain/niobjectnet.h"
#include "nimain/nipoint3.h"

class NiInterpolator : public NiObject {
public:
    static const NiRTTI ms_RTTI;
    static const unsigned char INVALID_BOOL;
    static const float INVALID_FLOAT;
    //   static const NiQuaternion INVALID_QUATERNION;
    //   static const NiPoint3 INVALID_POINT3;
    //   static const NiColorA INVALID_COLORA;

    virtual const NiRTTI *GetRTTI() const { return &ms_RTTI; }
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiInterpolator();
    //   virtual bool Update(float, NiObjectNET*, NiQuatTransform&);
    //   virtual bool Update(float, NiObjectNET*, NiColorA&);
    virtual bool Update(float, NiObjectNET *, NiPoint3 &);
    //   virtual bool Update(float, NiObjectNET*, NiQuaternion&);
    virtual bool Update(float, NiObjectNET *, float &);
    virtual bool Update(float, NiObjectNET *, bool &);
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    void ForceNextUpdate();
    virtual void GetActiveTimeRange(float &, float &) const;
    virtual void GuaranteeTimeRange(float, float);
    virtual NiInterpolator *GetSequenceInterpolator(float, float);
    virtual bool ResolveDependencies(class NiAVObjectPalette *);
    virtual bool SetUpDependencies() { return true; }
    virtual bool AlwaysUpdate() const;
    virtual class NiBoolInterpolator *IsNiBoolInterpolator();
    NiInterpolator(const NiInterpolator &);
    NiInterpolator &operator=(const NiInterpolator &);

protected:
    NiInterpolator();
    bool TimeHasChanged(float);
    void CopyMembers(NiInterpolator *, NiCloningProcess &);
    float m_fLastTime; // 0x8
};
