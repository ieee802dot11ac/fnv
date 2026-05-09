#pragma once

#include "bscore/BSSimpleArray.h"
#include "bsshader/BSRenderedTexture.h"
#include "d3dx9/d3dx9math.h"
#include "nimain/NiAVObject.h"
#include "nimain/NiCamera.h"
#include "nimain/NiCullingProcess.h"
#include "nimain/NiLight.h"

class BSShaderAccumulator;

class ShadowSceneLight : public NiRefObject {
public:
    static const int SSN_AMBIENT;
    static const int SSN_DIFFUSE;
    static const int SSN_TEXTURE;
    static const int SSN_SPECULAR;
    static const int SSN_SHADOWVOL;
    static const int SSN_SHADOWVOLWIRE;

    ShadowSceneLight(const ShadowSceneLight &);
    ShadowSceneLight();
    virtual ~ShadowSceneLight();
    bool Display(NiCullingProcess &);
    void TestFrustumCull(NiCullingProcess &);
    void AddObject(NiAVObject *);
    void AddTriGeom(NiTriBasedGeom *);
    void RemoveObject(NiAVObject *);
    void RemoveTriGeom(NiTriBasedGeom *, void *);
    void RemoveAllTriShapes();
    void RemoveAllRoots();
    bool BoundWithinLightRadius(const NiBound &, NiLight *, float);
    bool BoundWithinLightFrustum(const NiBound &);
    void SetLight(NiLight *);
    NiLight *GetLight();
    float GetLuminance();
    float UpdateLuminance(NiCamera *);
    float GetLuminanceAtPoint(NiPoint3, NiLight *);
    float GetViewLuminanceAtPoint(NiPoint3, NiPoint3, NiLight *);
    float GetLuminanceToBound(NiBound *);
    void SetCastShadow(bool);
    bool GetCastShadow();
    bool GetPointLight();
    bool GetAmbientLight();
    void SetDynamic(bool);
    bool GetDynamic();
    void SetDynamicPosition(NiPoint3);
    NiPoint3 GetDynamicPosition();
    void SetDynamicShadowMap(BSRenderedTexture *);
    BSRenderedTexture *GetDynamicShadowMap();
    float GetLODDimmer();
    float GetShadowLODDimmer();
    bool IsCubeShadowMap();
    void SetCubeShadowMap(bool);
    unsigned short GetFrustumCull();
    void RenderDepthMap(BSCubeMapCamera *, NiCullingProcess &);
    void SetSpotLight(bool);
    bool IsSpotLight();
    void SetSpotLightFOV(float);
    float GetSpotLightFOV();
    void SetSpotLightFalloff(float);
    float GetSpotLightFalloff();
    void ShowDebugTexture(bool);
    bool QShowDebugTexture();
    void ComputeWeightedShadowLight(BSShaderLightingProperty *, NiPoint3);
    void SetShadowScene(NiAVObject *);
    NiAVObject *GetShadowScene();
    void UpdateGeometryForShadowLight();
    void InsertUnusedFence();
    void RemoveUnusedGeom();
    void ClearRenderPasses();
    void SetFadeTarget(float, bool);
    bool IsFadedOut();
    float GetFadeAmount();
    bool IsFadingOut();
    bool IsFadingIn();
    const NiFrustumPlanes *GetFrustumPlanes();
    void SetClipSpacePlanes(float *);
    float *GetClipSpacePlanes();
    bool ClipSpacePlanesReady();
    void MTSetupFrustumDepthMap(BSCullingProcess &, int);
    void MTRenderFrustumDepthMap(BSCullingProcess &, int);
    BSSimpleArray<BSMultiBoundNode *, 1024> &QRooms();
    BSSimpleArray<BSPortal *, 1024> &QPortals();
    BSSimpleArray<NiNode *, 1024> &QProcessedNodes();
    void SetPortalGraph(BSPortalGraph *);
    BSPortalGraph *QPortalGraph();

public:
    static NiLines *MakeFrustumLines(float, float);

protected:
    void ParseObjectAddFrustum(NiAVObject *);
    void ParseObjectAddRadius(NiAVObject *);
    void ParseObjectRemove(NiNode *);
    void SetPointLight(bool);
    bool CubeFaceFrustumFrustumIntersection(NiBound, NiCullingProcess &, unsigned short);
    bool FrustumFrustumIntersection(NiCamera *, NiCamera *);
    void RenderCubeDepthMap(BSCubeMapCamera *, NiCullingProcess &);
    void RenderFrustumDepthMap(NiCullingProcess &);
    void UpdateGeometryForShadowLight_Recurse(NiAVObject *);

public:
    int iEnabledPasses; // 0x008
protected:
    float fLuminance; // 0x00c
public:
    D3DXMATRIX kViewProjection; // 0x010
    D3DXMATRIX kShadowView; // 0x050
    D3DXMATRIX kShadowProj; // 0x090
protected:
    float fLODDimmer; // 0x0d0
    float fShadowLODDimmer; // 0x0d4
    float fShadowLODDimmerTarget; // 0x0d8
    float fShadowLODDimmerElapsed; // 0x0dc
    NiTPointerList<NiPointer<NiTriBasedGeom> > lGeomList; // 0x0e0
    bool bCastShadow; // 0x0ec
    bool bCubeShadowMap; // 0x0ed
    NiPointer<NiTexture> spSpecularAttenuationTexture; // 0x0f0
    bool bPointLight; // 0x0f4
    bool bAmbientLight; // 0x0f5
    NiPointer<NiLight> spLight; // 0x0f8
    bool bDynamicLight; // 0x0fc
    NiPoint3 bPointPosition; // 0x100
    NiPointer<BSRenderedTexture> spDynamicShadowMap; // 0x10c
    unsigned short usFrustumCull; // 0x110
    NiPointer<NiAVObject> spFrustumVis; // 0x114
    bool bShadowSpotlight; // 0x118
    float fSpotlightFOV; // 0x11c
    float fSpotlightFalloff; // 0x120
    bool bShowDebugTexture; // 0x124
    NiPointer<NiAVObject> spShadowScene; // 0x128
    NiTPointerList<NiPointer<NiAVObject> > lRootList; // 0x12c
    void *kGeomListFence; // 0x138
    NiPointer<NiTriBasedGeom> kGeomListFenceObject; // 0x13c
    NiPointer<NiCamera> spShadowCamera; // 0x140
    NiFrustumPlanes kShadowCameraPlanes; // 0x144
    float pfClipSpacePlanes[24]; // 0x1a8
    bool bClipSpacePlanesReady; // 0x208
    NiPointer<BSShaderAccumulator> spShadowAccumulator; // 0x20c
    BSSimpleArray<BSMultiBoundNode *, 1024> kMultiboundRooms; // 0x210
    BSSimpleArray<BSPortal *, 1024> kPortals; // 0x220
    BSSimpleArray<NiNode *, 1024> kProcessedNodes; // 0x230
    BSPortalGraph *pPortalGraph; // 0x240
};
