#pragma once

#include "nimain/NiGeometry.h"
#include "nimain/NiParticlesData.h"
#include "nimain/NiRenderer.h"

class NiParticles : public NiGeometry {
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
    NiParticles(const NiParticles &);
    NiParticles(NiParticlesData *);
    NiParticles(
        unsigned short,
        NiPoint3 *,
        NiPoint3 *,
        NiColorA *,
        NiQuaternion *,
        float *,
        NiPoint3 *
    );
    float *GetRadii();
    float *GetSizes();
    NiQuaternion *GetRotations();
    unsigned char GetSubTextureOffsetCount();
    NiColorA *GetSubTextureOffsets();
    virtual void RenderImmediate(NiRenderer *);
    virtual void CalculateConsistency(bool);
    virtual NiParticles *IsParticlesGeom();
    virtual void OnVisible(NiCullingProcess &);
    virtual ~NiParticles();

    static NiObject *CreateObject();

protected:
    void CopyMembers(NiParticles *, NiCloningProcess &);
    NiParticles();
};
