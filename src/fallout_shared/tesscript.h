#pragma once

#include "fallout_shared/tesform.h"
#include "fallout_shared/tesobject.h"
#include "fallout_shared/tesscriptshared.h"
#include "fallout_shared/tesscriptvariable.h"
#include "fallout_shared/tesscriptcompiler.h"

class Script : public TESForm {
public:
    Script(const Script &);
    Script();
    virtual ~Script();
    virtual void InitializeData();
    virtual void ClearData();
    void Init(ScriptCompileData *);
    bool NeedsUpdate(ScriptCompileData *);
    void CopyResultScript(Script *);
    bool CompareResultScripts(Script *);
    void SetCompileData(unsigned int, char *);
    void SaveResultScript();
    virtual void Save();
    virtual bool SaveEdit(TESFile *);
    virtual bool Load(TESFile *);
    SCRIPT_HEADER *GetHeader();
    char *GetText();
    unsigned int GetTextLength() const;
    void SetText(const char *);
    char *GetCompiledData();
    ScriptLocals *CloneLocals();
    BSSimpleList<SCRIPT_LOCAL *> *CreateLocalList();
    bool Run(TESObjectREFR *, ScriptLocals *, TESObjectREFR *, bool);
    void RunScriptEffectStart(TESObjectREFR *, ScriptLocals *);
    void RunScriptEffectFinish(TESObjectREFR *, ScriptLocals *);
    void RunScriptEffectUpdate(TESObjectREFR *, ScriptLocals *, float);
    void CompileAndRun(ScriptCompiler *, COMPILER_NAME, TESObjectREFR *);
    const char *GetVariableName(unsigned int);
    unsigned int ConvertIndexToID(unsigned int);
    char FindVariable(const char *, unsigned int *);
    void InitItem(TESForm *);
    virtual void InitItem();
    bool GetIsCompiled();
    void SetIsCompiled(bool);
    //    void SetOwnerQuest(TESQuest*);
    //    TESQuest* GetOwnerQuest();
    BSSimpleList<ScriptVariable *> *GetVariableList();
    SCRIPT_REFERENCED_OBJECT *GetReferencedObject(unsigned int, ScriptLocals *);
    BSSimpleList<SCRIPT_REFERENCED_OBJECT *> *GetReferencedObjectList();
    void ClearProfilerTimer();
    void AddProfilerTime(float);
    float GetProfilerTimer();
    float GetQuestScriptGetSecondsBuffer();

protected:
    void ClearLocalVariableRefObjects();
    void ClearAllReferenceObjects();
    void ClearVariableList();
    void EndianData();

private:
    SCRIPT_HEADER m_header; // 0x28
    char *m_text; // 0x3c
    char *m_data; // 0x40
    float fProfilerTimer; // 0x44
    float fQuestScriptDelay; // 0x48
    float fQuestScriptGetSecondsBuffer; // 0x4c
    //   TESQuest* pOwnerQuest; // 0x50
    BSSimpleList<SCRIPT_REFERENCED_OBJECT *> listRefObjects; // 0x54
    BSSimpleList<ScriptVariable *> listVariables; // 0x5c
    static TESForm *pCrimeVictim;
    //   static BSCriticalSection ScriptRefListCrit;
    static BSSimpleList<TESObjectREFR *> ReferencesToEnable;
    static BSSimpleList<TESObjectREFR *> ReferencesToDisable;
    static BSSimpleList<TESObjectREFR *> ReferencesToDelete;
    static BSSimpleList<TESObjectREFR *> ReferencesToFadeDisable;
    static bool m_bSystemOutput;
    static char m_cButtonValue;
    static unsigned int m_iButtonOwner;
    static Script *pLastRefSearchScript;
    static ScriptLocals *pLastScriptLocals;
    static unsigned int iLastRefSearchIndex;
    static SCRIPT_REFERENCED_OBJECT *pLastRefObject;

#pragma region Every Script Builtin
public:
    static bool VerboseOutput();
    static void SavePendingReferences(BGSSaveFormBuffer *);
    static void LoadPendingReferences(BGSLoadFormBuffer *);
    static void RevertPendingReferences(BGSLoadFormBuffer *);
    //   static void InitActionList(TESObjectREFR*, ExtraDataList*);
    static void CopyReferencedObjectList(
        BSSimpleList<SCRIPT_REFERENCED_OBJECT *> *,
        BSSimpleList<SCRIPT_REFERENCED_OBJECT *> *,
        Script *
    );
    static void CopyVariableList(
        BSSimpleList<ScriptVariable *> *, BSSimpleList<ScriptVariable *> *, Script *
    );
    //   static bool SetActionFlag(TESForm*, ExtraDataList*, unsigned int);
    static bool ParseParameters(
        const SCRIPT_PARAMETER *,
        const char *,
        unsigned int &,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        ...
    );
    static bool GetValue(
        double &,
        const char *,
        unsigned int &,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        bool
    );
    static void PutNumericIDInDouble(const unsigned int &, double &);
    static void GetNumericIDFromDouble(unsigned int &, const double &);
    static bool UnimplementedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MessageBoxFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool BuildMessageBoxStringFromParameters(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &,
        const char *,
        BSStringT<char> &
    );
    static bool BuildMessageBoxButtonsFromParameters(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &,
        BSStringT<char> *
    );
    static void HandleMessageMenu();
    static bool MessageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetButtonPressedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsWaterObjectFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDistanceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddItemFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveItemFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DropItemFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveMeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DropMeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveAllItemsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveAllTypedItemsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnFireFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnNPCActivateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnActivateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnOpenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnCloseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnGrabFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnDestructionStageChangeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnReleaseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ActivateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActionRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool BugFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayerSpellBook(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMapMarkersFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleConversationStatsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleFullHelp(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCombatStatsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMagicStatsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleVerboseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleGodModeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCollisionGeometryFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCharControllerShapeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMaterialGeometryFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SaveWorldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleBordersFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleProjectileDebugFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMenusFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleSafeZoneFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleSkyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCollisionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleLeavesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleWireframeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDebugTextFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDebugTextFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RunMemoryPass(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleLiteBriteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowScenegraphFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowFullScenegraphFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowViewerStringsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleLODLandFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetLODObjectDistanceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTerminalMenuPosFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MovePipboyKnobFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HighlightBodyPartFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HighlightAdditionalReferenceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DeactivateAllHighlightsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerHUDShudderFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HelpFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleNavMeshFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TogglePathlinesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableNavMesh(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EnableNavMesh(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PickRefByIDFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetLightingPassesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleGrassUpdateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetFogDepthFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetClipDistFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleShadowVolumesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetImageSpaceGlowParamFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddDecal(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HairTint(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleAiDetection(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleAI(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowHeadTrackTarget(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleHighProcess(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleLowProcess(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMiddleLowProcess(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMiddleHighProcess(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleAISchedules(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SpeakSoundFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleScriptsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleGrassFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RefreshINIFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleEmotionsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestCode(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestDegradeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PrintAILists(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PrintNPCDialog(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CenterOnCellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CenterOnExteriorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CenterOnWorldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDialogSubtitle(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowRenderPasses(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool FreezeRendererAccumulation(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleOcclusion(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputMemContexts(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetMemContexts(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputMemStats(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputMemStatsFullWalk(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputTextureUseMap(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputArchiveProfile(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool QuitGame(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SaveIniFiles(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PurgeCellBuffers(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RevertWorld(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDetectionStats(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTargetRefraction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTargetFalloff(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTargetDOF(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleFullScreenMotionBlur(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetMotionBlur(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMotionBlur(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleFootIK(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleGrabIK(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleLookIK(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleRagdollAnim(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DrawSkeleton(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetVelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTargetRefractionFire(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleRefractionDebug(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCombatAI(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleFlyCam(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TogglePathingInfoFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetUFOCamSpeedMult(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleTestLight(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleMultibound(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddOcclusionPlane(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetGlobalRadialBlur(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleBoundVisGeometry(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleEOFImageSpace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DumpMenuPackingInfo(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasLoaded3DFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPermanentActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetBaseActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActorValueInfoFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetSizeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DamageActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RestoreActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGameSettingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetGameSettingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetINISettingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetINISettingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowINISettingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool KillActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool KillAllActorsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResurrectActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceActorValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RadioShutOffFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsGoreDisabledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActorsInHighFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowVarsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowQuestVarsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowQuestsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetQuestObjectFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetEssentialFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RotateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPosFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPosFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetStartingPosFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAngleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetStartingAngleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAngleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAtStartFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static void SetPosBase(TESObjectREFR *, char, float);
    static void SetAngleBase(TESObjectREFR *, char, float);
    static void SetScaleBase(TESObjectREFR *, float);
    static void SetRigidBodyMassBase(TESObjectREFR *, float);
    static void DamageObjectBase(TESObjectREFR *, float);
    static void MatchFaceGeometryBase(TESObjectREFR *, TESObjectREFR *, int);
    static bool GetCurrentTimeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSecondsPassedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayGroupFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool LoopGroupFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayExplosionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SkipAnimFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartCombatFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopCombatFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopCombatAlarmOnActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetScaleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetScaleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModScaleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLOSFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddSpellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveSpellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CastFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CastImmediateOnSelfFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DispelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DispelAllSpellsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaySoundFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaySound3DFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StreamMusicFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayMusicFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool FadeSFXFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetLocationSpecificLoadScreensOnlyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CalcPathToPointFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CalcLowPathToPointFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowAnimFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool Show1stPersonFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MenuModeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GameModeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ScriptEffectStartFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ScriptEffectFinishFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ScriptEffectUpdateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ScriptEffectElapsedTimeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EnableFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDisabledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLockedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLockLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsLockBrokenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableAllActors(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsFormTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsVoiceTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaceAtMeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SaveGame(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool LoadGame(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool Autosave(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceSave(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CopySaveGames(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ExportBetaComment(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCellNode(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleTrees(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCameraFOV(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ReloadShaders(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DumpTexturePalette(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DumpModelMap(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SexChange(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetLastExtDoorActivated(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDisease(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVampire(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetClothingValue(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameFaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameRace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameSex(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameFactionAsPC(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameRaceAsPC(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SameSexAsPC(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDetected(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDead(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetItemCount(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGold(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSleeping(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSitting(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFurnitureMarkerID(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsCurrentFurnitureRef(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsCurrentFurnitureObj(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTalkedToPC(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTalkedToPCParam(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetQuestRunning(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetQuestCompleted(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IgnoreRenderPass(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetStage(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetStageDone(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartQuestFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopQuestFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetStageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFactionRankDifference(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAlarmed(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsPleasant(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsCloudy(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsRaining(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsSnowing(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWindSpeedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWeatherPercentFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsCurrentWeatherFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAttacked(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsCreature(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetShouldAttack(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInCell(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInCellParam(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInWorldspace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCellPublicFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInSameCell(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsClass(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsRace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsCreatureType(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsSex(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsPlayableRace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInFaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCIsClass(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCIsRace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCIsSex(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCInFaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsID(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsChild(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsUsedItem(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsUsedItemType(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetUsedItemLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetUsedItemActivateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MessageBoxIconFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsRef(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFactionRank(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetFactionRank(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModFactionRank(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFactionReaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetFactionReaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModFactionReaction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestAllCellsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RenderTestCellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RenderTestHereFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGlobalValue(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDisposition(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetRandomPercent(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLevel(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetArmorRating(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDayOfWeekFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPCInJailFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModDisposition(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDeadCount(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowMap(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartConversation(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddTopicFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SayFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SayToFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EvaluatePackageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetAIFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SendAssaultAlarmFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModPCMiscStat(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCMiscStat(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAlertFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAlertFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool LookFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopLookFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetSkyParamFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetHDRParamFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PrintHDRParamFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleHDRDebugFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowPivotFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static void
    CheckFlagFunction(unsigned int, TESObjectREFR *, TESForm *, ScriptLocals *, double &);
    static bool OnAddFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnEquipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnUnequipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnDropFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnHitFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnHitWithFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnDeathFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnMurderFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnCombatEndFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnPackageStartFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnPackageEndFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnPackageChangeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnLoadFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnMagicEffectHitFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnSellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnTriggerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnTriggerEnterFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnTriggerLeaveFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnStartCombatFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ActorOnEquipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ActorOnUnequipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnResetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OnSayToDoneFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EnablePlayerControlsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisablePlayerControlsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerControlsDisabledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetHeadingAngleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsWeaponOutFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsWeaponInListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PickIdleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayIdleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayVATSCamerasFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsTorchOutFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsShieldOutFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsFacingUpFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsLeftUpFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetKnockedStateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWeaponAnimTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsWeaponSkillTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCurrentAIPackageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsWaitingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsIdlePlayingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsTalkingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWalkSpeedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowQuestLogFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowFullQuestLogFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CompleteQuestFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowQuestTargetsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool LockFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool UnlockFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCrimeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCrimeKnownFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsGuard(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFatiguePercentageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetHealthPercentageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCurrentAIProcedureFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTrespassWarningLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsTrespassingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInMyOwnedCellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsContinuingPackagePCNearFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddScriptPackageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveScriptPackageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CanHaveFlamesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasFlamesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddFlamesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveFlamesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetOpenStateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MoveToFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MoveToQuestTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static void MoveToFunctionBase(TESObjectREFR *, TESObjectREFR *, float, float, float);
    static bool MoveToFadeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsCurrentPackageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddFaceAnimNoteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool WakeUpPCFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPCSleepingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPCAMurdererFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCombatStyleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SelectPlayerSpellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDetectionLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorDetected(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetEquippedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool WaitFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopWaitingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsSwimming(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerSleepHours(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPlayerSleepHours(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAmountStolenSoldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModAmountStolenSoldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCExpelledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCExpelledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCFactionMurderFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCFactionMurderFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerEnemyofFactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPlayerEnemyofFactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPCFactionAttackFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCFactionAttackFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDestroyedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDestroyedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActionRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSelfFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetContainerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCombatTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPackageTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetParentRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLinkedRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetForceRun(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetForceRun(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetForceSneak(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetForceSneak(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AdvanceLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasMagicEffectFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsSpellTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSpellUsageNumberFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSModeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSTargetHeightFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDefaultOpenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDefaultOpenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetOpenStateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowClassMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowRaceMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowBarberMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowPlasticSurgeonMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowNameMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowBarterMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowSurgeryMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowHackingMiniGame(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowComputersInterface(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowRepairMenuFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowTraitMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPersuasionNumberFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTotalPersuasionNumberFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetSandmanFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCannibalFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsClassDefaultFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsMyClassDefaultFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ReloadCurrentClimate(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ReloadCurrentWeather(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestSeenData(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestLocalMap(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetChargenValue(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowSpellmakingMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetGhostFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGhostFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EquipItemFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool UnEquipItemFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetClassFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetUnconsciousFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetUnconsciousFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetRestrainedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetRestrainedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceFleeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceTakeCoverFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetOffersServiceNowFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActiveWeather(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ReleaseWeatherOverride(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModBarterGoldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetBarterGoldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetBarterGoldFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsTimePassingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TrapUpdateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModPCSkillFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModPCAttributeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCanPCFastTravelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetArmorRatingUpperFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetOwnershipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetOwnershipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCellOwnershipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCellOwnershipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsHorseStolenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCellFullNameFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActorFullNameFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsSneakingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsRunningFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFriendHitFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInCombatFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPackageDurationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayMagicShader(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayMagicEffect(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopMagicShader(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StopMagicEffect(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PreloadMagicEffect(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActorAlpha(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetCellFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsAnimPlayingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EnableLinkedPathPointsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableLinkedPathPointsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInInteriorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlayBinkFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceWeather(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleActorAI(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorsAIOff(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAllReachable(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAllVisible(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetNoAvoidance(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorUsingATorchFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetFallDamageTimerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsXBoxFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPS3Function(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPCFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DamageWeaponFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWeaponHealthFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorEvilFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorVictimFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIdleDoneOnceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetNoRumorsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetNoRumorsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWhichServiceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerHitShaderFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleWaterSystem(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleWaterRadius(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModifyWaterShader(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModifyWaterShaderShallowColor(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModifyWaterShaderDeepColor(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModifyWaterShaderReflectionColor(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowWhoDetectsPlayer(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool Reset3DStateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorRidingHorseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerHasLastRiddenHorseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddAchievement(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetRigidBodyMass(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DuplicateAllItemsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInDangerousWaterFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EssentailDeathReloadFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool BeginTrace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetShowQuestItemsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DuplicateNPCStatsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetHealthFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIgnoreFriendlyHitsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetIgnoreFriendlyHitsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayersLastRiddenHorseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActorRefractionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RunCellTest(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetItemValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartAllQuests(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CompleteAllQuestStages(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool FlushPersistantActors(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DeleteReference(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleFogOfWar(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OutputLocalMapPictures(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SendCrimeAlarmFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetSceneIsComplex(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetGamma(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool WasteMemory(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearAdaptedLight(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCastShadows(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetHUDGlowConstants(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTreeMipmapBias(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceCloseFile(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartMasterFileSeekData(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DumpMasterFileSeekData(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsEssentialFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayerMovingIntoNewSpaceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CreateFullCopyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DeleteFullCopyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTimeDeadFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DamageObjectFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLastPlayerActionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayerActionActiveFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTalkingActivatorActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetTalkingActivatorActorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsActorTalkingThroughActivatorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RewardExperiencePointsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddPerkFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemovePerkFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasPerkFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAllyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetEnemyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddNoteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveNoteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetHasNoteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddFactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveFactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDispositionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDepthOfField(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetDepthOfFieldRange(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetGlobalTimeMultiplierFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetHitLocationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPC1stPersonFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetActorsAIFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearOwnershipFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PushActorAwayFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCauseofDeathFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsLimbGoneFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetKillingBlowLimbFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ApplyImageSpaceModifier(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveImageSpaceModifier(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasFriendDispositionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool FriendDispositionBoostFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCellImageSpace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetImageSpace(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowCharGenMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowLockpickMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetSPECIALPoints(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddSPECIALPoints(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTagSkills(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddTagSkills(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowLockpickMenuDebug(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetKillerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetKillerObjectFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFactionCombatReactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsMovingFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsTurningFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAnimActionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool UseWeaponFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EvaluateSpellConditionsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SendSherlockDebugPage(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DebugCombatPlanFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCombatActionCostFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleCombatDebugFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceCombatGroupStrategyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaceLocationMarkerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearLocationMarkersFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowInventoryFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetPerformanceTimers(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDecalDebug(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDecalRendering(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetImageSpaceModifiersEnable(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ExistsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGroupMemberCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetGroupTargetCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetObjectiveCompletedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetObjectiveDisplayedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetObjectiveCompletedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetObjectiveDisplayedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlantedExplosiveFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CompleteAllObjectivesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TogglePrimitivesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsObjectTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDialogueEmotionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDialogueEmotionValueFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleVATSLight(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerScreenBlood(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearScreenBlood(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleScreenBloodTest(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerScreenSplatter(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearScreenSplatter(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetScreenSplatterTexture(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetScreenSplatterFade(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetDialogueFlags(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetAllTerminals(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetAudioMultiThreading(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveMerchantContainer(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetMerchantContainer(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowWarningFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerEnterFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MarkForDeleteFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddItemHealthPercentFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaceAtMeHealthPercentFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CloseAllMenusFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static TESObjectREFR *
    PlaceAtMeFunctionBase(TESObjectREFR *, TESObject *, int, int, int, float);
    static bool PipboyRadio(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetNPCRadio(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetBroadcastState(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetBroadcastState(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartRadioConversation(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceRadioStationUpdateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ExitGame(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetInZoneFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetFactionRelationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsLastPlayedIdleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPlayerTeammateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerTeammateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerTeammateCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool OpenTeammateContainerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearFactionPlayerEnemyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearActorsFactionsPlayerEnemyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActorCrimePlayerEnemyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetActorFactionPlayerEnemyFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetMinorCrimeCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetMajorCrimeCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPlayerTagSkillFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayerTagSkillFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerGrabbedRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayerGrabbedRefFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool PlaceLeveledActorAtMeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDestructionStageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearDestructionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetAggroRadiusViolatedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsAlignmentFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetQuestFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetQuestDelayFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceActiveQuestFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetThreatRatioFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MatchFaceGeometryFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIsUsedItemEquipTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetPlayerName(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool FireWeaponFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowTutorialMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AgeRaceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool MatchRaceFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCYoungFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCToddlerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleActorMover(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowSPECIALBookMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowLoveTesterMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowTraitSelectMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowSlotMachineMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowBlackJackMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowRouletteMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowCaravanMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddCardToPlayer(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsPlayerInRegion(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCasinoCheatLevel(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetConcussedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetZoneRespawnsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetVATSTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetMapMarkerVisibleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetInventoryFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TriggerLODApocalypseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CreateDetectionEventFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetWeaponHealthPercFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetWeaponHealthPercFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModWeaponHealthPercFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetRadiationLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowCharGenMenuModValues(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetRumbleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetNoActivationSound(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ClearNoActivationSound(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsGreetingPlayerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartSandmanFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool StartCannibalFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool HasBeenEatenFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IgnoreCrimeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetIgnoreCrimeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetLastHitCriticalFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetPipboyManagerFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsCombatTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RewardKarmaFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSRightAreaFreeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSLeftAreaFreeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSFrontAreaFreeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSBackAreaFreeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSRightTargetVisibleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSLeftTargetVisibleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSFrontTargetVisibleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetVATSBackTargetVisibleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AttachAshPileFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCritStageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsInCritStageFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveFromAllFactionsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetXPForNextLevelFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceTerminalBackFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDepthBiasFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetMinimalUseFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetPCCanUsePowerArmorFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowQuestStagesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleSPURenderBatchFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleSPUTransformUpdateFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ForceRSXCrashFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EvalActorTextures(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ModifyFaceGen(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableAllMinesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DetonatePlacedExplosivesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetEmitterParticleMax(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetMPSParticleMax(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTaskThreadSleepFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetTaskThreadUpdateSleepFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetSecuritronExpression(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SwapTextureOnRef(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool UnimplementedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsInCritStageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool HasBeenEatenConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetWeaponHealthPercConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetMapMarkerVisibleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsUsedItemEquipTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetThreatRatioConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsAlignmentConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDestructionStageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsPlayerGrabbedRefConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetInZoneConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsWaterObjectConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDistanceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPosConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetAngleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetStartingPosConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetStartingAngleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetMenuModeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetSecondsPassedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool HasLoaded3DConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetActorValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPermanentActorValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetBaseActorValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCurrentTimeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetScaleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetLOSConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDisabledConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDiseaseConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetVampireConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetSandmanConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetClothingValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool SameFactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool SameRaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool SameSexConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    SameFactionAsPCConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool SameRaceAsPCConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool SameSexAsPCConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDetectedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDeadConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetItemCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetGoldConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetSleepingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetSittingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFurnitureMarkerIDConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsCurrentFurnitureRefConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsCurrentFurnitureObjConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetTalkedToPCConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetScriptVariableConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetQuestRunningConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetQuestCompletedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetStageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetStageDoneConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFactionRankDifferenceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetAlarmedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsPleasantConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsCloudyConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsRainingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsSnowingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetWindSpeedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetWeatherPercentConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsCurrentWeatherConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetAttackedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsCreatureConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetShouldAttackConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetInCellConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetInWorldspaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetInSameCellConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsClassConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsRaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsCreatureTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsSexConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsPlayableRaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetInFactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPCIsClassConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPCIsRaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPCIsSexConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPCInFactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsIDConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsVoiceTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsChildConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsUsedItemConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsUsedItemTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetUsedItemLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetUsedItemActivateConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsRefConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFactionRankConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetGlobalValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetLocalValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDispositionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetRandomPercentConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetArmorRatingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDeadCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetAlertConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPlayerControlsDisabledConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetHeadingAngleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsWeaponOutConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsWeaponInListConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsTorchOutConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsShieldOutConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsYieldingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsFacingUpConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsLeftUpConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetKnockedStateConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetWeaponAnimTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsWeaponSkillTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCurrentAIPackageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsWaitingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsIdlePlayingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetCrimeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsGuardConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFatiguePercentageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetHealthPercentageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsTalkingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetWalkSpeedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCurrentAIProcedureConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetTrespassWarningLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsTrespassingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsInMyOwnedCellConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsContinuingPackagePCNearConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool CanHaveFlamesConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool HasFlamesConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetOpenStateConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsCurrentPackageConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDayOfWeekConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsPCSleepingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsPCAMurdererConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDetectionLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetLockedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetLockLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsLockBrokenConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetEquippedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsSwimmingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetAmountStolenSoldConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsInListConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCasinoWinningsLevelConditionalFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsPlayerInRegionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPCExpelledConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPCFactionMurderConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPlayerEnemyofFactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPCFactionAttackConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetDestroyedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    HasMagicEffectConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDefaultOpenConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsSpellTargetConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetSpellUsageNumberConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetVATSModeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSTargetHeightConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPersuasionNumberConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetTotalPersuasionNumberConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetCannibalConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsClassDefaultConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsMyClassDefaultConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetGhostConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetUnconsciousConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetRestrainedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetOffersServiceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetBarterGoldConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetInvestmentGoldConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsTimePassingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetArmorRatingUpperConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetOwnershipConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCellOwnershipConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsHorseStolenConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPlayerHasLastRiddenHorseConditionFunction(
        TESObjectREFR *, void *, void *, double &
    );
    static bool IsSneakingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsRunningConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetFriendHitConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsInCombatConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsInInteriorConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsActorUsingATorchConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetPCMiscStatConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsActorEvilConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsActorVictimConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIdleDoneOnceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetNoRumorsConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetWhichServiceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsActorRidingHorseConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsInDangerousWaterConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIgnoreFriendlyHitsConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsPlayersLastRiddenHorseConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsXboxConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsPS3ConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsPCConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsEssentialConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsActorConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsPlayerMovingIntoNewSpaceConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetTimeDeadConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetLastPlayerActionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsPlayerActionActiveConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetTalkingActivatorActorConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsActorTalkingThroughActivatorConditionFunction(
        TESObjectREFR *, void *, void *, double &
    );
    static bool
    GetHitLocationConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsPC1stPersonConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetHasNoteConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetCauseofDeathConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsLimbGoneConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetKillingBlowLimbConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    HasFriendDispositionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetKillerConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetKillerObjectConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFactionCombatReactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsMovingConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetIsTurningConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetAnimActionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool ExistsConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetGroupMemberCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetGroupTargetCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPlantedExplosiveConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIsObjectTypeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDialogueEmotionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetDialogueEmotionValueConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetFactionRelationConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsLastPlayedIdleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool HasPerkConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool DebugMilesPS3Function(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetConsoleOutputFileFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TestRaceSexTerminalFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool
    GetPlayerTeammateConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetPlayerTeammateCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetActorCrimePlayerEnemyConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetActorFactionPlayerEnemyConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetMinorCrimeCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetMajorCrimeCountConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetAggroRadiusViolatedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetConcussedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetRadiationLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsGreetingPlayerConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetLastHitCriticalConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsCombatTargetConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSRightAreaFreeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSLeftAreaFreeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSBackAreaFreeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSFrontAreaFreeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSRightTargetVisibleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSLeftTargetVisibleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSBackTargetVisibleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetVATSFrontTargetVisibleConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetXPForNextLevelConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetIgnoreCrimeConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsGoreDisabledConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetActorsInHighConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetReputationConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetReputationPctConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetReputationThresholdConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetObjectiveDisplayedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    GetObjectiveCompletedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool ForceFileCacheFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DumpNiUpdatesFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SinFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool CosFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool TanFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SqrtFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool LogFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AbsFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AutoDisplayObjectives(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool KillQuestUpdates(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsImageSpaceActiveFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddFormToFormListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddNPCToLeveledListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddCreatureToLeveledListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddItemToLeveledListFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemapWaterTypeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsCodeRedeemedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RedeemCodeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RevokeCodeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool EnableWeaponModFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetReputationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveReputationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddReputationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveReputationExactFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool AddReputationExactFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetReputationFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetReputationPctFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetReputationThresholdFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetOwnerLastTargetFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetForceHitReactionFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool
    GetForceHitReactionConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool UnlockChallengeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ChallengeLockedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool
    ChallengeLockedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool GetChallengeCompletedFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool RemoveRecurringFromChallengeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool
    GetChallengeCompletedConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool PlaceAtReticleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ObjectUnderReticleFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool
    IsPlayerTagSkillConditionFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsHardcoreConditionalFunction(TESObjectREFR *, void *, void *, double &);
    static bool
    IsAlwaysHardcoreConditionalFunction(TESObjectREFR *, void *, void *, double &);
    static bool IsHardcoreFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetHardcoreFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool DisableHardcoreTracking(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsAlwaysHardcoreFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ResetXPFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ToggleDemigodModeFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool ShowRecipeMenu(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetCasinoWinningsLevel(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool SetCasinoWinningsLevel(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool GetDLCCountFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static bool IsDLCInstalledFunction(
        const SCRIPT_PARAMETER *,
        const char *,
        TESObjectREFR *,
        TESObjectREFR *,
        Script *,
        ScriptLocals *,
        double &,
        unsigned int &
    );
    static void AddPendingDisabledReference(TESObjectREFR *, bool);
    static void AddPendingEnabledReference(TESObjectREFR *);
    static bool IsPendingEnabledReference(TESObjectREFR *);
    static bool IsPendingDisabledReference(TESObjectREFR *);
    static bool IsPendingFadeDisabledReference(TESObjectREFR *);
    static void RemoveDelayedScriptActionReference(TESObjectREFR *);
    static void RunDelayedScriptActionsOnReferences();
    static void SetProcessScripts(bool);
    static bool GetProcessScripts();
    static void ClearAllProfilerTimers();
    static void DisplayDebugText(int, int *, int *);
    static void ClearCachedValues();
    static void SetCrimeVictim(TESForm *);
    static void ClearButtonPressed();
    static void ClearOptimizations();

#pragma endregion
};
