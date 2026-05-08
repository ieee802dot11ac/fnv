#pragma once

#include "nimain/NiObject.h"
#include "nimain/NiProperty.h"
#include "nimain/NiRTTI.h"
#include "nimain/NiTexture.h"

class NiShadeProperty : public NiProperty {
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
    NiShadeProperty(const NiShadeProperty &);
    NiShadeProperty();
    void SetSmooth(bool);
    bool GetSmooth() const;
    bool IsEqualFast(const NiShadeProperty &) const;
    virtual int Type() const;
    int GetShaderPropertyType();
    virtual ~NiShadeProperty();

    static NiObject *CreateObject();
    static int GetType();
    static NiShadeProperty *GetDefault();
    static void _SDMInit();
    static void _SDMShutdown();

protected:
    void SetField(u16, u16, u16);
    u16 GetField(u16, u16) const;
    void SetBit(bool, u16);
    bool GetBit(u16) const;
    void CopyMembers(NiShadeProperty *, NiCloningProcess &);
    u16 m_uFlags; // 0x18
    int iShaderPropertyType; // 0x1c
    static NiPointer<NiShadeProperty> ms_spDefault;
};

class BSShaderProperty : public NiShadeProperty {
public:
    enum EShaderPropertyFlag {
        BSSP_SPECULAR = 0x0000,
        BSSP_SKINNED = 0x0001,
        BSSP_LOWDETAIL = 0x0002,
        BSSP_VERTEX_ALPHA = 0x0003,
        BSSP_MOTION_BLUR = 0x0004,
        BSSP_SINGLEPASS = 0x0005,
        BSSP_FALLOFF = 0x0006,
        BSSP_ENVMAP = 0x0007,
        BSSP_ALPHATEX = 0x0008,
        BSSP_ZPREPASS = 0x0009,
        BSSP_FLAG_FACEGENBLEND = 0x000a,
        BSSP_FLAG_PARALLAX = 0x000b,
        BSSP_FLAG_MODELSPACENORMALS = 0x000c,
        BSSP_FLAG_NOPROJSHADOW = 0x000d,
        BSSP_FLAG_LANDSCAPE = 0x000e,
        BSSP_FLAG_REFRACTION = 0x000f,
        BSSP_FLAG_REFRACTION_FIRE = 0x0010,
        BSSP_FLAG_EYEREFLECT = 0x0011,
        BSSP_FLAG_HAIR = 0x0012,
        BSSP_FLAG_DYNAMICALPHA = 0x0013,
        BSSP_FLAG_LOCALMAP_CLEAR = 0x0014,
        BSSP_FLAG_WINDOWREFLECT = 0x0015,
        BSSP_FLAG_BILLBOARDTREE = 0x0016,
        BSSP_FLAG_SHADOWFRUSTUM = 0x0017,
        BSSP_FLAG_MULTIPLE_TEXTURES = 0x0018,
        BSSP_FLAG_REMAP_TEXTURES = 0x0019,
        BSSP_FLAG_DECAL = 0x001a,
        BSSP_FLAG_DYNAMIC_DECAL = 0x001b,
        BSSP_FLAG_PARALLAXOCCLUSION = 0x001c,
        BSSP_FLAG_EXTERNAL_EMITTANCE = 0x001d,
        BSSP_FLAG_SHADOWMAP = 0x001e,
        BSSP_FLAG_ZBUFFER_TEST = 0x001f,
        BSSP_FLAG_ZBUFFER_WRITE = 0x0020,
        BSSP_FLAG_LODLANDSCAPE = 0x0021,
        BSSP_FLAG_LODBUILDING = 0x0022,
        BSSP_FLAG_NOFADE = 0x0023,
        BSSP_FLAG_REFRACTION_TINT = 0x0024,
        BSSP_FLAG_VERTEXCOLORS = 0x0025,
        BSSP_1ST_PERSON = 0x0026,
        HSP_FLAG_PTFIRST = 0x0027,
        HSP_FLAG_2NDLIGHT = 0x0028,
        HSP_FLAG_3RDLIGHT = 0x0029,
        TGSP_FLAG_VERTEX_LIGHTING = 0x002a,
        TGSP_FLAG_UNIFORM_SCALE = 0x002b,
        TGSP_FLAG_FIT_SLOPE = 0x002c,
        TGSP_FLAG_BILLBOARD = 0x002d,
        BSSP_FLAG_SKIP_LANDLO_PASS = 0x002e,
        BSSP_FLAG_ENVMAP_LIGHTFADE = 0x002f,
        BSSP_FLAG_WIREFRAME = 0x0030,
        BSSP_FLAG_VATS_SELECTION = 0x0031,
        BSSP_FLAG_SHOW_IN_LOCAL_MAP = 0x0032,
        BSSP_FLAG_PREMULT_ALPHA = 0x0033,
        BSSP_FLAG_SKIP_NORMAL_MAPS = 0x0034,
        BSSP_FLAG_ALPHA_DECAL = 0x0035,
        BSSP_FLAG_NO_TRANSPARENCY_MULTISAMPLING = 0x0036,
        BSSP_FLAG_STINGER = 0x0037,
        BSSP_FLAG_COUNT = 0x0038,
    };

    class RenderPass { /* Size=0x10 */
    public:
        NiGeometry *pGeometry; // 0x0
        u16 usPassEnum; // 0x4
        u8 eAccumulationHint; // 0x6
        bool bFirstPass; // 0x7
        bool bLastPass; // 0x8
        u8 ucNumLights; // 0x9
        u8 ucMaxNumLights; // 0xa
        u8 ucExtraParam; // 0xb
        ShadowSceneLight **ppSceneLights; // 0xc
        static unsigned int uiNewRenderPassCount;

        RenderPass(NiGeometry *, u16, bool, u8, ShadowSceneLight *, ...);
        ~RenderPass();
        void AllocateLightArray(u8);
        void FreeLightArray();
        void SetLights(u8, ShadowSceneLight *, ...);
    };

    static const NiRTTI ms_RTTI;
    static float fDepthBiasUnit;
    static NiCriticalSection BSSPGarbageCrit;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void PostLinkObject(NiStream &);
    BSShaderProperty(const BSShaderProperty &);
    BSShaderProperty();
    virtual ~BSShaderProperty();
    virtual void CopyTo(BSShaderProperty *) const;
    virtual void CopyToMembers(BSShaderProperty *) const;
    virtual bool SetupGeometry(NiGeometry *);
    virtual BSShaderProperty::RenderPassArray *
    GetRenderPasses(NiGeometry *, int, u16 &, unsigned int, BSShaderAccumulator *, bool);
    BSShaderProperty::RenderPassArray *QRenderPasses();
    void CheckCreateRenderPassArray(int);
    void CheckCreateDepthMapRenderPassArray(int);
    void CheckCreateLocalMapRenderPassArray(int);
    void CheckCreateSIBlockRenderPassArray(int);
    void CheckCreateConstAlphaRenderPassArray(int);
    void CheckCreateWaterFogRenderPassArray(int);
    void CheckSilhouetteRenderPassArray(int);
    virtual u16 GetNumberofPasses(NiGeometry *);
    virtual BSShaderProperty::RenderPassArray *GetSIBlockRenderPasses();
    virtual BSShaderProperty::RenderPass *GetRenderDepthPass(NiGeometry *);
    void SetLastRenderPassState(int);
    bool CompareFlags(BSShaderProperty *);
    bool GetFlag(unsigned int) const;
    void SetFlag(unsigned int, bool);
    void SetAlpha(float);
    float GetAlpha();
    float GetFadeAlpha();
    void SetFadeAlpha(float);
    void FreeRenderPasses();
    void ClearRenderPasses();
    void SetObjectType(unsigned int);
    unsigned int GetObjectType();
    int QShader() const;
    void SetShader(int);
    float QEnvmapScale() const;
    void SetEnvmapScale(float);
    virtual BSShaderProperty *ClarifyShader(NiGeometry *, bool, bool);
    virtual NiTexture *GetBaseTexture();
    virtual BSShaderProperty::RenderPassArray *GetWaterFogPassList(NiGeometry *);
    bool Get1stPerson() const;
    void Set1stPerson(bool);
    float GetDepthBias() const;
    void SetDepthBias(float);
    virtual void GetTextureUse(void (*)(NiTexture *, unsigned int, void *), void *);
    virtual void PrecacheTextures();
    void SetMotionBlurred(bool);
    float GetCameraDistance();

    static NiObject *CreateObject();
    static void ToggleMotionBlurRecurse(NiAVObject *);
    static void SetMotionBlurRecurse(NiAVObject *, bool);
    static void SetFlagRecurse(NiAVObject *, EShaderPropertyFlag, bool);
    static void ClearDebugStats();
    static void GetDebugStats(unsigned int &);
    static void ClearRenderPassGarbage();

protected:
    void CopyMembers(BSShaderProperty *, NiCloningProcess &);

    static const int NUM_FLAG_LONGS;
    static const int NUM_FLAG_BITS;

    uint ulFlags[2]; // 0x20
    float fAlpha; // 0x28
    float fFadeAlpha; // 0x2c
    float fEnvmapScale; // 0x30
    float fCameraDistance; // 0x34
    int iLastRenderPassState; // 0x38
    BSShaderProperty::RenderPassArray *pRenderPassList; // 0x3c
    BSShaderProperty::RenderPassArray *pDepthMapRenderPassList; // 0x40
    BSShaderProperty::RenderPassArray *pConstAlphaRenderPassList; // 0x44
    BSShaderProperty::RenderPassArray *pLocalMapRenderPassList; // 0x48
    BSShaderProperty::RenderPassArray *pSIBlockRenderPassList; // 0x4c
    BSShaderProperty::RenderPassArray *pWaterFogRenderPassList; // 0x50
    BSShaderProperty::RenderPassArray *pSilhouettePassList; // 0x54
    int iShader; // 0x58
    float fDepthBias; // 0x5c
    float fLastClearFrame; // 0x60
public:
    float fLastAccumFrame; // 0x64
};
