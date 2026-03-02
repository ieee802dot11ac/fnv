#pragma once

#include "gamebryo2.2/corelibs/nimain/nipoint3.h"
#include <types.h>
#include <win_types.h>

class Main {
public:
    Main(Main const &); /* compiler_generated() */
    Main();
    ~Main();
    void Main_AudioInit();
    // void InitTES(NiNode *);
    void InitRenderer();
    void InitSceneGraph();
    void Swap();
    void PostSwapProcess();
    // void DrawWorld(BSRenderedTexture *, bool, bool);
    // void DrawWorldRenderedMenu(BSRenderedTexture *, bool);
    // void DrawWorldWireframe(BSRenderedTexture *, bool);
    // void DrawWorldStandard(BSRenderedTexture *, bool);
    // void DrawWorldMenu3D(BSRenderedTexture *);
    // void DrawWorld_End(BSRenderedTexture *, ImageSpaceManager *, NiXenonRenderer *, Sun
    // *); void DrawWorld_StopRenderTarget(bool, BSRenderedTexture *); void
    // DrawWorld_RenderedMenu(NiGeometry *, NiXenonRenderer *); void
    // DrawWorld_ImageSpace(bool, BSRenderedTexture *, NiXenonRenderer *,
    // BSRenderedTexture *); void DrawWorld_DoDepth(BSShaderAccumulator *,
    // BSRenderedTexture *); void DrawWorld_DoVolumetricFog(BSShaderAccumulator *,
    // BSRenderedTexture *);
    void DrawWorld_DrawRenderedMenuParent();
    void DrawWorld_MTSetup1stPerson();
    // void DrawWorld_MTRender1stPerson(NiXenonRenderer *, NiGeometry *, Sun *,
    // BSRenderedTexture *); void DrawWorld_DoVelocity(ImageSpaceManager *,
    // NiXenonRenderer *, BSRenderedTexture *); void
    // DrawWorld_CopyMenuBG(ImageSpaceManager *, NiXenonRenderer *, bool,
    // BSRenderedTexture *);
    void DrawWorld_Navmesh();
    // void DrawWorld_RestartRenderTexture(BSRenderedTexture *, bool, unsigned __int32);
    void DrawWorld_VATS(bool);
    // void DrawWorld_Refraction(BSShaderAccumulator *, BSRenderedTexture *);
    // void DrawWorld_Add1stPersonToDepthBuffer(BSRenderedTexture *);
    // void DrawWorld_ResolveDepth(BSRenderedTexture *);
    void DrawWorld_UpdateWater();
    void DrawWorld_WaitForParallelUpdate();
    // Sun *DrawWorld_Init();
    bool DrawWorld_VATSOcclusionQuery();
    void DrawWorld_UpdateOffscreenBuffers();
    // BSRenderedTexture *DrawWorld_InitRenderTexture(NiXenonRenderer *, BSRenderedTexture
    // *, bool, bool);
    // void DrawWorld_DrawScene(Sun *, bool, bool, bool);
    // void DrawWorld_ScreenSplatter(NiXenonRenderer *);
    void UpdateOffscreenInterface();
    void OnIdle();
    void OnIdle_ScaleLOD();
    void OnIdle_FixActorBones();
    void OnIdle_UpdateMessageBox();
    void OnIdle_UpdateTimer();
    void OnIdle_PollControls();
    void OnIdle_HandleMenuBackground();
    void OnIdle_UpdateAudio();
    void OnIdle_UpdateProcessLists();
    void OnIdle_UpdatePlayer();
    void OnIdle_UpdateCurrentGridCell();
    void OnIdle_UpdateAnimationsAndEffects();
    void OnIdle_DoInterfaceIdle();
    void OnIdle_UpdateImageSpace(bool);
    void OnIdle_PostThreadsProcess();
    bool UpdateTextures(float);
    bool IsLocationHighDetail(const NiPoint3 &);
    void ForceUpdateTextures();
    void RestoreTextureRangeDefaults();
    void RunCameraPath();
    void UpdateNonRenderSafeAITasks();
    void RunScripts();
    void DisplayDebugText();
    // static TESObjectREFR *GetDebugTextRef();
    static void ClearDebugTextRef();
    void QuitGame();
    void ResetGame();
    void SetGame();
    bool GameReset();
    bool GameOver();
    void ReloadGame();
    bool GameReload();
    bool IsInMenuMode();
    void ChangeSignedInPlayer();
    void PerformGameReset(bool);
    static void ForceFileCacheCallback(bool);
    static void InitSky();
    // void SetCustomLaunchData(CustomLaunchData *);
    bool IsThisAReboot();
    void SetActive(bool);
    bool GetActive();
    void SetOnIdle(bool);
    bool GetOnIdle();
    HWND *GetWindow();
    HINSTANCE *GetInstance();
    unsigned long GetThread() const;
    void *GetThreadHandle() const;
    // Controls *GetControls();
    bool WmMouseMove(s32, s32);
    void KillMenuBGTexture();
    // static NiAVObject *GetSceneGraph(BSSherlockCommandManager::SG_TYPE);
    // static SceneGraph *GetWorldSceneGraph();
    // static NiNode *WorldRootNode();
    // static NiCamera *WorldRootCamera();
    // static BSMultiBoundNode *SkyRootNode();
    // static NiNode *WeatherRootNode();
    // static SceneGraph *MenuRootNode();
    // static NiCamera *MenuRootCamera();
    // static SceneGraph *MenuRootNode3D();
    // static NiCamera *MenuRootCamera3D();
    static void FreeMenuRootNode();
    static void FreeMenuRootNode3D();
    static void CreateMenuRootNode();
    static void CreateMenuRootNode3D();
    // static NiNode *LandLODNode();
    // static NiNode *ObjectLODNode();
    // static NiNode *WaterLODNode();
    static void SetSceneIsComplex(bool);
    static bool GetSceneIsComplex();
    // static BSParticleSystemManager *GetMasterParticleSystemManager();
    void RenderMenuBackground();
    static s32 iNumberLOSPicks;
    static s32 iNumberActorsDetection;
    bool QQuit();
    // static TESObjectREFR *pDebugTextReference;
    static u32 QFrameCount();
    bool GetFreezeTime();
    void SetFreezeTime(bool);
    bool GetFlyCamera();
    void SetFlyCamera(bool);
    // NiRenderedTexture *GetMenuBGTexture();
    static float QFrameAnimTime();
    static bool QFaderToBlackVisible();
    static bool GetOpenConsole();
    static void SetOpenConsole(bool);
    // BSShaderAccumulator *QDrawWorldAccum();
    bool bResumeLoadingThread; // 0x0
protected:
    bool bQuitGame; // 0x1
    bool bResetGame; // 0x2
    bool bGameActive; // 0x3
    bool bOnIdle; // 0x4
    bool bReloadContent; // 0x5
    bool bFlyCamera; // 0x6
    bool bFreezeTime; // 0x7
    // CustomLaunchData *pLaunchData; // 0x8
    bool bThisIsAReboot; // 0xC
    HWND hWnd; // 0x10
    HINSTANCE hInstance; // 0x14
    unsigned long iThreadID; // 0x18
    void *hThreadHandle; // 0x1C
    // ScrapHeap PackedTaskHeap; // 0x20
    // BSPackedTaskQueue TaskQueue; // 0x34
    // ScrapHeap SecondaryPackedTaskHeap; // 0x5C
    // BSPackedTaskQueue SecondaryTaskQueue; // 0x70
    // NiPointer<BSShaderAccumulator> spDrawWorldAccum; // 0x98
    // NiPointer<BSShaderAccumulator> spDraw1stPersonAccum; // 0x9C
    // NiPointer<BSShaderAccumulator> spDraw1stPersonDepthAccum; // 0xA0
    // NiPointer<BSShaderAccumulator> spScreenSplatterAccum; // 0xA4
    // NiPointer<BSShaderAccumulator> spRenderedMenuAccum; // 0xA8
    bool bRenderingMenuBG; // 0xAC
    // NiPointer<NiCamera> sp1stPersonAdjustedCamera; // 0xB0
public:
    // static NiPointer<BSRenderedTexture> spMenuBGTexture;
    // static NiPointer<BSRenderedTexture> spInterfaceFXTex;
    // static NiPointer<BSRenderedTexture> spVATSTex;
protected:
    void TakeMenuBackgroundPicture();
    bool LoadPluginsFromFile(char const *, char const *);
    static bool bOpenConsole;
    static u32 iFrameCounter;
    // static NiPointer<SceneGraph> spWorldRoot;
    // static NiPointer<SceneGraph> spMenuRoot;
    // static NiPointer<SceneGraph> sp3DMenuRoot;
    // static NiPointer<BSMultiBoundNode> spSkyRoot;
    // static NiPointer<NiNode> spWeatherRoot;
    // static NiNode *pLandLOD;
    // static NiNode *pObjectLOD;
    // static NiNode *pWaterLOD;
    // static NiPointer<BSParticleSystemManager> spParticleSystemManager;
    // static NiPointer<BSFogProperty> spFog;
    // static Sky *pSky;
    static bool bStaticMenuBG;
    static bool bMenuBGReady;
    static bool bSceneIsComplex;
    static bool bInMenuMode;
    static bool bInDialog;
    static bool bFaderToBlackVisible;
    static bool bInConsole;
    static float fFrameAnimTime;
    // static NiPointer<NiScreenElements> spMenuBGGeometry;
};

void Main_ShaderInit(void);
