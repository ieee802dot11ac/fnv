#include "TESScript.h"
#include "fallout_shared/TESScriptShared.h"
#include "fallout_shared/tesobjectrefr.h"
#include "types.h"
#include <cstring>

TLS bool Script::m_bSystemOutput = false;
TLS TESForm *Script::pCrimeVictim = nullptr;
TLS ScriptLocals *Script::pLastScriptLocals = nullptr;
TLS uint Script::iLastRefSearchIndex = -1;
TLS SCRIPT_REFERENCED_OBJECT *Script::pLastRefObject = nullptr;
TLS ScriptLocals *ScriptLocals::pLastVarSearchScriptLocals = nullptr;
TLS uint ScriptLocals::iLastVarSearchID = -1;
TLS SCRIPT_LOCAL *ScriptLocals::pLastVar = nullptr;
TLS Script *Script::pLastRefSearchScript = nullptr;

static int iTotalBSTaskCount;
char Script::m_cButtonValue = -1;
uint Script::m_iButtonOwner = 0;
static bool bProcessScripts = true;

ScriptLocals::ScriptLocals() {
    memset(this, 0, sizeof(ScriptLocals));
    m_pMasterScript = nullptr;
    m_pScriptEffectData = nullptr;
}

void ScriptLocals::ClearOptimizations() {
    pLastVarSearchScriptLocals = nullptr;
    iLastVarSearchID = -1;
    pLastVar = nullptr;
}

void Script::InitializeData() {
    memset(&m_header, 0, sizeof(SCRIPT_HEADER));
    m_data = nullptr;
    m_text = nullptr;
    m_bSystemOutput = false;
    fProfilerTimer = 0.0;
    fQuestScriptDelay = 0.0;
    SetFormType(SCPT_ID);
    fQuestScriptGetSecondsBuffer = 0.0;
}

bool Script::SaveEdit(TESFile *pFile) { return TESForm::Save(pFile); }

void Script::Save() {
    StartForm();
    if (QEndianSwapOnSave())
        m_header.Endian();
    __AddChunkData(SCHR_ID, &m_header, sizeof(SCRIPT_HEADER));
    if (QEndianSwapOnSave())
        m_header.Endian();
    CloseForm();
}

void Script::SaveResultScript() {
    if (QEndianSwapOnSave())
        m_header.Endian();
    __AddChunkData(SCHR_ID, &m_header, sizeof(SCRIPT_HEADER));
    if (QEndianSwapOnSave())
        m_header.Endian();
}

void Script::InitActionList(TESObjectREFR *ownerObject, ExtraDataList *apExtra) {}

void Script::RunScriptEffectStart(
    TESObjectREFR *apTargetRef, ScriptLocals *apEffectLocals
) {
    ScriptRunManager::Instance()->Run(
        this, apTargetRef, apEffectLocals, nullptr, false, true, false, 0.0f
    );
}

void Script::RunScriptEffectFinish(
    TESObjectREFR *apTargetRef, ScriptLocals *apEffectLocals
) {
    ScriptRunManager::Instance()->Run(
        this, apTargetRef, apEffectLocals, nullptr, false, false, true, 0.0f
    );
}

void Script::RunScriptEffectUpdate(
    TESObjectREFR *apTargetRef, ScriptLocals *apEffectLocals, float afSecondsElapsed
) {
    ScriptRunManager::Instance()->Run(
        this, apTargetRef, apEffectLocals, nullptr, false, false, false, afSecondsElapsed
    );
}

void Script::SetProcessScripts(bool abProcessScripts) {
    bProcessScripts = abProcessScripts;
}

bool Script::GetProcessScripts() { return bProcessScripts; }

void Script::PutNumericIDInDouble(const uint &aiID, double &adVal) {
    const u8 *id = reinterpret_cast<const u8 *>(&aiID);
    u8 *val = reinterpret_cast<u8 *>(&adVal);
    val[0] = id[0];
    val[1] = id[1];
    val[2] = id[2];
    val[3] = id[3];
}

void Script::GetNumericIDFromDouble(uint &aiID, const double &adVal) {
    u8 *id = reinterpret_cast<u8 *>(&aiID);
    const u8 *val = reinterpret_cast<const u8 *>(&adVal);
    id[0] = val[0];
    id[1] = val[1];
    id[2] = val[2];
    id[3] = val[3];
}

void Script::ClearOptimizations() {
    pLastRefSearchScript = nullptr;
    pLastScriptLocals = nullptr;
    iLastRefSearchIndex = -1;
    pLastRefObject = nullptr;
}

void ScriptLocals::ClearActionFlags() {
    BSSimpleList<ACTION_OBJECT *> *actions = m_pActionList;
    while (actions) {
        ACTION_OBJECT *action = actions->GetItem();
        if (action == nullptr)
            return;
        actions = actions->GetNext();
        action->iFlags = 0;
    }
}

ACTION_OBJECT *
ScriptLocals::GetActionObject(TESForm *apActionForm, bool abReturnDefault) {
    if (m_pActionList == nullptr)
        return nullptr;
    BSSimpleList<ACTION_OBJECT *> *actions = m_pActionList;
    ACTION_OBJECT *action = nullptr;
    while (actions) {
        ACTION_OBJECT *ao = actions->GetItem();
        if (ao == nullptr)
            break;
        if (ao->pForm == apActionForm)
            return ao;
        if (ao->pForm == nullptr)
            action = ao;
        actions = actions->GetNext();
    }
    if (abReturnDefault)
        return action;
    else
        return nullptr;
}

Script::Script() { InitializeData(); }
