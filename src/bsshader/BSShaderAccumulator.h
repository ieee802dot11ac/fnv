#pragma once

#include "bsshader/BSShaderManager.h"
#include "bsshader/BSShaderProperty.h"
#include "nimain/NiAVObject.h"
#include "nimain/NiAlphaAccumulator.h"
#include "nimain/NiCamera.h"
#include "nimain/NiColor.h"
#include "nimain/NiGeometry.h"
#include "bsshader/ShadowSceneLight.h"
#include "nimain/NiTPointerMap.h"
#include "nimain/nismartpointer.h"
#include "nisystem/NiCriticalSection.h"

class BSShaderAccumulator : public NiAlphaAccumulator {
public:
    enum DepthTransformationEnum {
        VTRANS_DEFAULT = 0x0000,
        VTRANS_SKINNED = 0x0001,
        VTRANS_3XDEFAULT = 0x0002,
        VTRANS_3XSKINNED = 0x0003,
        VTRANS_COUNT = 0x0004,
    };
    enum WATER_SIDE {
        ABOVE_WATER = 0x0000,
        BELOW_WATER = 0x0001,
    };
    enum etAccumulationMode {
        BSSA_ACCUMNORMAL = 0x0000,
        BSSA_ACCUMDEPTHMAP = 0x0001,
        BSSA_ACCUMLOD = 0x0002,
        BSSA_ACCUMNONE = 0x0003,
    };

    static const NiRTTI ms_RTTI;
    static bool (*pRegisterObjectFunc[16])(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool (*RegisterObjectCurrent)(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static void (*pFinishAccumulatingFunc[16])(BSShaderAccumulator *);
    static void (*FinishAccumulatingCurrent)(BSShaderAccumulator *);
    static NiPointer<NiNode> spRenderPassesScenegraph;
    static bool bRequestRenderPassesScenegraph;
    static bool bShowRenderPassesScenegraph;
    static bool bFreezeGeometryBatch;
    static bool bFrozenBatchAcquired;
    static bool bFreezeCamera;
    static NiPoint3 kFrozenCameraTranslate;
    static bool bOverheadDebugGeometry;
    static int iBatchRendererIndex;

    virtual const NiRTTI *GetRTTI() const;
    BSShaderAccumulator(const BSShaderAccumulator &);
    BSShaderAccumulator(BSShaderManager::BATCHRENDERER_CREATION_MODE, uint, uint);
    virtual ~BSShaderAccumulator();
    virtual void StartAccumulating(const NiCamera *);
    virtual bool RegisterObject(NiGeometry *);
    virtual void FinishAccumulating();
    virtual void FinishAccumulatingPreResolveDepth();
    virtual void FinishAccumulatingPostResolveDepth();
    void RenderDecals();
    virtual void RenderPassList(u16, bool);
    bool QAccumulate();
    void SetAccumulate(bool);
    void Set1stPerson(bool);
    void SetRenderNoShader(bool);
    void SetWaterReflection(bool);
    bool GetWaterReflection();
    void SetWaterRefraction(bool);
    bool GetWaterRefraction();
    void SetRenderDecals(bool);
    bool GetRenderDecals();
    void AddShadowVolumeLight(ShadowSceneLight *);
    void GetDebugStats(
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &,
        uint &
    );
    void ClearRenderPasses();
    void ClearRenderedGeometryCache();
    void ClearVolumetricFogGeometry();
    void ClearVelocityGeometry();
    void ClearAllQueries();
    uint GetRefractivePassCount();
    bool RenderNormals(NiCamera *, BSRenderedTexture *);
    void ClearGroupPasses(int);
    bool DoVolumetricFog();
    bool RenderVolumetricFog(NiCamera *, BSRenderedTexture *);
    void SetupDepth(NiCamera *, NiCamera *, BSRenderedTexture *);
    void GetDepthFromZBuffer(BSRenderedTexture *);
    void RenderDepth(NiCamera *, NiCamera *);
    void RenderVelocity(NiCamera *);
    void ClearDepthGeometry();
    void RenderScreenSplatter();
    void StartGroupingAlphas(const NiBound &, bool);
    void StopGroupingAlphas();
    bool IsGroupingAlphas();
    bool IsAlphaGroupZPrePass();
    void DoSunOcclusionQueury(NiGeometry *, uint, NiCamera *);
    void ResetSunOcclusion();
    float GetStoredSunOcclustionPercent();
    uint GetSunOcclusionPixelCount();
    void ClearSunQueries();
    void ClearBloodSplatter();
    NiGeometry *GetBoundTestGeometry();
    void SetBoundTestGeometry(NiGeometry *);
    void AddAndUpdateBoundVolume(uint, const NiBound &, bool);
    void RemoveBoundVolume(uint);
    bool IsBoundVolumeOccluded(uint, bool);
    uint GetBoundVolumePixelCount(uint);
    void ClearAllBoundVolumes();
    ShadowSceneNode *GetShadowSceneNode();
    void SetShadowSceneNode(ShadowSceneNode *);
    void SetHasWater(bool);
    bool GetHasWater();
    void SetUnderWater(bool);
    bool GetUnderWater();
    void SetCurrentWaterHeight(int);
    int GetCurrentWaterHeight();
    void SetWaterFogRenderTarget(BSRenderedTexture *);
    const NiCamera *GetCamera();
    void RenderBatches(
        BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum, bool, int
    );
    void ClearActivePasses();
    void RenderGeometryGroup(uint, bool);
    void SortAlphaPasses();
    bool
        QPassesWithinRange(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum);
    bool QWaterRefractionPassWithinRange(
        BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum
    );
    BSShaderManager::etRenderMode GetRenderMode();
    void SetRenderMode(BSShaderManager::etRenderMode);
    void SetShadowLight(ShadowSceneLight *);
    ShadowSceneLight *GetShadowLight();
    virtual bool AddShared(NiAVObject *);
    virtual void ClearSharedMap();
    NiColorA QSilhouetteColor();
    void SetSilhouetteColor(NiColorA &);

    static bool RegisterObject_Standard(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_Interface(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_Frozen(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_ScreenSplatter(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_LocalMap(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_WaterDepth(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static bool RegisterObject_ConstAlpha(
        BSShaderAccumulator *,
        NiGeometry *,
        const NiPropertyState *,
        BSShaderProperty *,
        BSShader *
    );
    static void FinishAccumulating_Standard(BSShaderAccumulator *);
    static void FinishAccumulating_Standard_PreResolveDepth(BSShaderAccumulator *);
    static void FinishAccumulating_Standard_PostResolveDepth(BSShaderAccumulator *);
    static void FinishAccumulating_FirstPerson(BSShaderAccumulator *);
    static void FinishAccumulating_Interface(BSShaderAccumulator *);
    static void FinishAccumulating_ScreenSplatter(BSShaderAccumulator *);
    static void FinishAccumulating_WaterDepth(BSShaderAccumulator *);
    static bool QUseInstancing();
    static void SetUseInstancing(bool);
    static void EnableOverdrawVisualization(bool);
    static void ClearDebugStats();
    static void ToggleRefractionDebugTexture();
    static void SetRunBoundingSphereTests(bool, bool);
    static void SetDisplayBoundingSpheres(bool);
    static bool IsShadowPass(uint);
    static void RenderPassImmediately(BSShaderProperty::RenderPass *, uint);

protected:
    void EvaluateSunOcclusionResults(uint);
    NiNode *CreateRenderPassTree();
    void RenderAlphaGeometry(BSShaderAccumulator::WATER_SIDE);
    void RenderAlphaGeometry();
    bool IsFoggingPass(u16, u16);
    short GetDisabledFogPass(u16);

    static int ModelDataSort(void *, void *);
    static int EnumDataSort(void *, void *);
    static bool IsClippingPass(uint);

public:
    BSShaderAccumulator::etAccumulationMode eAccumulationMode; // 0x034
    bool bWorldGeometry; // 0x038
    bool bCacheGeometry; // 0x039
    bool bDoDepthPasses; // 0x03a
protected:
    uint uiSunPixelCount; // 0x03c
    bool bWaitingForSunQueury; // 0x040
    float fPercentSunOccludedStored; // 0x044
    SunOcclusionTest pSunTests[3]; // 0x048
    bool bAccumulate; // 0x084
    bool b1stPerson; // 0x085
    bool bRenderNoShader; // 0x086
    u16 usQueryCount; // 0x088
    u16 usQuerySize; // 0x08a
    BSOcclusionQuery **ppOcclusionQuery; // 0x08c
    NiTPointerList<NiGeometry *> pVolumetricFogGeometry; // 0x090
    BSTPersistentList<NiTPointerAllocator<uint>, NiGeometry *>
        pRenderedGeometryCache[4]; // 0x09c
    BSTPersistentList<NiTPointerAllocator<uint>, NiGeometry *>
        pRendered1stPersonGeometryCache[4]; // 0x0ec
    NiPointer<NiGeometry> spBoundTestGeometry; // 0x13c
    NiTPointerList<ReferenceVolume *> ReferenceVolumeList; // 0x140
    uint uiLastOcclusionRef; // 0x14c
    bool bLastOcclusionResult; // 0x150
    NiColorA kSilhouetteColor; // 0x154
    bool bWaterReflection; // 0x164
    bool bWaterRefraction; // 0x165
    bool bCellHasWater; // 0x166
    bool bUnderWater; // 0x167
    int iCurrentWaterHeight; // 0x168
    bool bRenderDecals; // 0x16c
    BSInstanceRendering *pInstanceRenderer; // 0x170
    BSBatchRenderer *pBatchRenderer[2]; // 0x174
    uint *puicurrentPassA; // 0x17c
    int *picurrentBucketA; // 0x180
    bool *pbcurrentFirstPassA; // 0x184
    bool *pbcurrentActiveA; // 0x188
    uint uiBatchRendererCount; // 0x18c
    uint uiBatchRendererPassCount; // 0x190
    ShadowSceneNode *pActiveShadowSceneNode; // 0x194
    NiPointer<BSRenderedTexture> spWaterFogRenderTarget; // 0x198
    BSShaderManager::etRenderMode eRenderMode; // 0x19c
    NiPointer<ShadowSceneLight> spShadowLight; // 0x1a0
    BSShaderProperty::RenderPass kAlphaRenderPass; // 0x1a4
    NiTPointerMap<NiAVObject *, bool> kRoomSharedMap; // 0x1b4
    NiCriticalSection BSCPSharedCrit; // 0x200
    NiTPointerMap<NiAVObject *, bool> kRegisterMap; // 0x280
    NiCriticalSection BSCPRegisterCrit; // 0x300

    static uint lTotalGeometry;
    static uint lOccludedGeometry;
    static uint lOcclusionGeometry;
    static uint lOcclusionTriangles;
    static uint lTotalTriangles;
    static uint lTotalPasses;
    static uint lTotalPassTriangles;
    static uint lQueueMemory;
    static uint lWaitForQueryLoops;
    static uint lWaitForSunQueryFrames;
    static uint lWaitForBoundVolumeQueryLoops;
    static NiPointer<NiScreenElements> spOverdrawPolygons[17];
    static bool bShowRefractionDebugTexture;
    static bool bRunBoundingSphereOcclusion;
    static bool bResetBoundingSphereOcclusion;
    static bool bShowBoundingSpheres;
    static bool bUseInstancing;
};
