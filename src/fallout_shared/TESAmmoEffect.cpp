#include "TESAmmoEffect.h"
#include "bsmain/Setting.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/XGameSetting.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesfullname.h"
#include "stdlib.h"
#include <cstring>

SETTING(GameSettingCollection, sAmmoEffectDAM, "DAM")
SETTING(GameSettingCollection, sAmmoEffectDR, "Target DR")
SETTING(GameSettingCollection, sAmmoEffectDT, "Target DT")
SETTING(GameSettingCollection, sAmmoEffectSpread, "Gun Spread")
SETTING(GameSettingCollection, sAmmoEffectCondition, "Gun CND")
SETTING(GameSettingCollection, sAmmoEffectFatigue, "Target Fatigue")

void AMMO_EFFECT_DATA::Endian() {
    EndianSwapEq(reinterpret_cast<u32 &>(iAmmoEffectType));
    EndianSwapEq(reinterpret_cast<u32 &>(iOperation));
    EndianSwapEq(reinterpret_cast<u32 &>(fValue));
}

bool TESAmmoEffect::Load(TESFile *apFile) {
    u8 formid = apFile->GetTESForm();
    if (formid != AMEF_ID)
        return false;
    LoadForm(apFile);
    SetInitialized(false);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
            LOADOBJBOUND
            LOADEDITORID
        case DATA_ID: {
            LoadData(apFile, &data, sizeof(AMMO_EFFECT_DATA));
            if (apFile->GetLittleEndian()) {
                data.Endian();
            }
        } break;
        case FULL_ID: {
            LoadFullNameChunk(this, apFile);
        } break;
        default:
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

void TESAmmoEffect::Save() {
    TESForm::StartForm();
    TESFullName::Save();
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    __SaveData(&data, sizeof(data));
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    CloseForm();
}

void TESAmmoEffect::Copy(TESForm *apCopy) {
    TESAmmoEffect *apCopy_AE = dynamic_cast<TESAmmoEffect *>(apCopy);
    if (apCopy_AE != nullptr) {
        memcpy(&data, &apCopy_AE->data, sizeof(data));
        CopyAllComponents(apCopy);
    }
}

bool TESAmmoEffect::Compare(TESForm *apCompare) {
    TESAmmoEffect *apComp_AE = dynamic_cast<TESAmmoEffect *>(apCompare);
    if (apComp_AE == nullptr) {
        return true;
    }
    if (memcmp(&data, &apComp_AE->data, sizeof(data)))
        return true;
    if (CompareAllComponents(apComp_AE)) {
        return true;
    }
    return false;
}

TESAmmoEffect::TESAmmoEffect() {
    std::memset(&data, 0, sizeof(data));
    SetFormType(AMEF_ID);
}
