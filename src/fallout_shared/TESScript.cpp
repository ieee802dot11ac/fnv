#include "TESScript.h"
#include "fallout_shared/tesscriptshared.h"
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
