#pragma once

#include "nimain/NiDynamicEffect.h"
#include "nimain/NiTexture.h"
#include "nimain/NiTexturingProperty.h"

class NiTextureEffect : public NiDynamicEffect {
public:
    enum CoordGenType {
        WORLD_PARALLEL = 0x0000,
        WORLD_PERSPECTIVE = 0x0001,
        SPHERE_MAP = 0x0002,
        SPECULAR_CUBE_MAP = 0x0003,
        DIFFUSE_CUBE_MAP = 0x0004,
        NUM_COORD_GEN = 0x0005,
    };
    enum TextureType {
        PROJECTED_LIGHT = 0x0000,
        PROJECTED_SHADOW = 0x0001,
        ENVIRONMENT_MAP = 0x0002,
        FOG_MAP = 0x0003,
        TEXTURE_TYPE_MAX = 0x0004,
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiTextureEffect(const NiTextureEffect &);
    NiTextureEffect();
    virtual ~NiTextureEffect();
    const NiMatrix3 &GetModelProjectionMatrix() const;
    void SetModelProjectionMatrix(const NiMatrix3 &);
    const NiPoint3 &GetModelProjectionTranslation() const;
    void SetModelProjectionTranslation(const NiPoint3 &);
    const NiMatrix3 &GetWorldProjectionMatrix() const;
    const NiPoint3 &GetWorldProjectionTranslation() const;
    NiTexture *GetEffectTexture() const;
    void SetEffectTexture(NiTexture *);
    NiTexturingProperty::FilterMode GetTextureFilter() const;
    void SetTextureFilter(NiTexturingProperty::FilterMode);
    NiTexturingProperty::ClampMode GetTextureClamp() const;
    void SetTextureClamp(NiTexturingProperty::ClampMode);
    TextureType GetTextureType() const;
    void SetTextureType(TextureType);
    CoordGenType GetTextureCoordGen() const;
    void SetTextureCoordGen(CoordGenType);
    bool GetClippingPlaneEnable() const;
    void SetClippingPlaneEnable(bool);
    const NiPlane &GetModelClippingPlane() const;
    void SetModelClippingPlane(const NiPlane &);
    const NiPlane &GetWorldClippingPlane() const;

    static NiObject *CreateObject();
    static char *GetViewerString(const char *, CoordGenType);
    static char *GetViewerString(const char *, TextureType);
    static const NiFixedString &GetTypeNameFromID(unsigned int);
    static bool GetTypeIDFromName(const NiFixedString &, unsigned int &);
    static void _SDMInit();
    static void _SDMShutdown();

protected:
    static NiFixedString ms_akTextureTypeStrings[4];
    void CopyMembers(NiTextureEffect *, NiCloningProcess &);
    virtual void UpdateWorldData(NiUpdateData &);
    void UpdateProjection();

    NiMatrix3 m_kModelProjMat; // 0x0f0
    NiPoint3 m_kModelProjTrans; // 0x120
    NiMatrix3 m_kWorldProjMat; // 0x130
    NiPoint3 m_kWorldProjTrans; // 0x160
    NiPointer<NiTexture> m_spTexture; // 0x16c
    NiTexturingProperty::FilterMode m_eFilter; // 0x170
    NiTexturingProperty::ClampMode m_eClamp; // 0x174
    TextureType m_eTextureMode; // 0x178
    CoordGenType m_eCoordMode; // 0x17c
    bool m_bPlaneEnable; // 0x180
    NiPlane m_kModelPlane; // 0x184
    NiPlane m_kWorldPlane; // 0x194
};
