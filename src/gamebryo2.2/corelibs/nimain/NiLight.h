#pragma once

#include "nimain/NiColor.h"
#include "nimain/NiDynamicEffect.h"

class NiLight : public NiDynamicEffect {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiLight(const NiLight &);
    NiLight();
    virtual ~NiLight();
    void SetDimmer(float);
    float GetDimmer() const;
    void SetAmbientColor(const NiColor &);
    const NiColor &GetAmbientColor() const;
    void SetDiffuseColor(const NiColor &);
    const NiColor &GetDiffuseColor() const;
    void SetSpecularColor(const NiColor &);
    const NiColor &GetSpecularColor() const;
    void *GetRendererData() const;
    void SetRendererData(void *);

protected:
    void CopyMembers(NiLight *, NiCloningProcess &);

    float m_fDimmer; // 0x0f0
    NiColor m_kAmb; // 0x0f4
    NiColor m_kDiff; // 0x100
    NiColor m_kSpec; // 0x10c
    void *m_pvRendererData; // 0x118
};
