#include "ScriptEffect.h"
#include "fallout/magic/ActiveEffect.h"
#include "fallout/misc/saveload/BGSLoadFormBuffer.h"
#include "fallout_shared/magic/effectarchetype.h"
#include "fallout_shared/tesscriptshared.h"

bool bScriptEffectInitialized = EffectArchetypes::RegisterActiveEffect(
    EffectArchetypes::SCRIPT, ScriptEffect::Instantiate
);

ActiveEffect *ScriptEffect::Copy() {
    ScriptEffect *new_effect = new (
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ScriptEffect.cpp",
        55,
        __FUNCTION__
    ) ScriptEffect(pCaster, pSpell, pEffect);
    CopyData(new_effect);
    return new_effect;
}

ActiveEffect *ScriptEffect::Instantiate(
    MagicCaster *apCaster, MagicItem *apSpell, EffectItem *apEffect
) {
    ScriptEffect *new_effect = new (
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ScriptEffect.cpp",
        101,
        __FUNCTION__
    ) ScriptEffect(apCaster, apSpell, apEffect);

    return new_effect;
}

void ScriptEffect::Start() {
    if (pScript != nullptr) {
        pEffectLocals = pScript->CloneLocals();

        pScript->RunScriptEffectStart(pTarget->GetTargetStatsObject(), pEffectLocals);
    }
}

void ScriptEffect::Finish() {
    if (pScript != nullptr) {
        pScript->RunScriptEffectFinish(pTarget->GetTargetStatsObject(), pEffectLocals);
    }
    if (pEffectLocals != nullptr) {
        delete pEffectLocals;
        pEffectLocals = nullptr;
    }
}

void ScriptEffect::Update(float afSecondsElapsed) {
    if (pScript != nullptr) {
        pScript->RunScriptEffectUpdate(
            pTarget->GetTargetStatsObject(), pEffectLocals, afSecondsElapsed
        );
    }
}

void ScriptEffect::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {
    ActiveEffect::SaveGame(apSaveGameBuffer);
    bool b = pEffectLocals != nullptr;
    apSaveGameBuffer->SaveData(&b, sizeof(b), 0);
    if (b) {
        pEffectLocals->SaveGame(apSaveGameBuffer);
    }
}

void ScriptEffect::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {
    ActiveEffect::LoadGame(apLoadGameBuffer);
    bool has_locals = false;
    apLoadGameBuffer->LoadData(&has_locals, sizeof(has_locals));
    if (has_locals) {
        if (pEffectLocals == nullptr) {
            pEffectLocals = pScript->CloneLocals();
        }
        if (pEffectLocals) {
            pEffectLocals->LoadGame(apLoadGameBuffer);
        } else {
            ScriptLocals dump;
            dump.LoadGame(apLoadGameBuffer);
        }
    }
}

void ScriptEffect::CopyData(ActiveEffect *apDestination) {
    ActiveEffect::CopyData(apDestination);
    ScriptEffect *apDest_SE = dynamic_cast<ScriptEffect *>(apDestination);
    if (apDest_SE) {
        apDest_SE->pScript = pScript;
        if (pScript && pEffectLocals) {
            apDest_SE->pEffectLocals = pScript->CloneLocals();
            apDest_SE->pEffectLocals->CopyActionList(pEffectLocals);
        }
    }
}
