#include "TESSkill.h"
#include "bsmain/Setting.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/XGameSetting.h"
#include "fallout_shared/actorvalue.h"
#include "fallout_shared/enums.h"
#include "stdlib.h"
#include <cstring>

static SETTING(GameSettingCollection, sSpecNameCombat, "Strength");
static SETTING(GameSettingCollection, sSpecNameMagic, "Magic");
static SETTING(GameSettingCollection, sSpecNameStealth, "Stealth");
static SETTING(
    GameSettingCollection,
    sNoviceSkillLevelText,
    "You have a basic understanding of this skill."
);

void SKILL_DATA::Endian() {
    EndianSwapEq(reinterpret_cast<u32 &>(eIndex));
    EndianSwapEq(reinterpret_cast<u32 &>(eAttribute));
    EndianSwapEq(reinterpret_cast<u32 &>(eSpecialization));
    EndianSwapEq(reinterpret_cast<u32 &>(fActionValue[0]));
    EndianSwapEq(reinterpret_cast<u32 &>(fActionValue[1]));
}

void TESSkill::Save() {
    StartForm();
    AddChunk(INDX_ID, uint(data.eIndex));
    TESDescription::Save();
    TESTexture::Save(ICON_ID);
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    __SaveData(&data, sizeof(data));
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    SaveDescriptionData(&SkillLevelText[0], ANAM_ID);
    SaveDescriptionData(&SkillLevelText[1], JNAM_ID);
    SaveDescriptionData(&SkillLevelText[2], ENAM_ID);
    SaveDescriptionData(&SkillLevelText[3], MNAM_ID);
    CloseForm();
}

bool TESSkill::Load(TESFile *apFile) {
    if (apFile->GetTESForm() != HAIR_ID)
        return false;
    LoadForm(apFile);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
        case DESC_ID: {
            LoadDescriptionData(this, apFile);
        } break;
        case OBND_ID: {
            LoadObjectBound(apFile);
        } break;
        case EDID_ID: {
            void *buf = alloca(apFile->GetChunkSize());
            apFile->GetChunkData(buf, 0x200);
            SetFormEditorID(static_cast<const char *>(buf));
        } break;
        case DATA_ID: {
            LoadData(apFile, &data, sizeof(SKILL_DATA));
        } break;

        case ANAM_ID: {
            LoadDescriptionData(&SkillLevelText[0], apFile);
        } break;
        case JNAM_ID: {
            LoadDescriptionData(&SkillLevelText[1], apFile);
        } break;
        case ENAM_ID: {
            LoadDescriptionData(&SkillLevelText[2], apFile);
        } break;
        case MNAM_ID: {
            LoadDescriptionData(&SkillLevelText[3], apFile);
        } break;
        case ICON_ID: {
            LoadTextureChunk(this, apFile);
        } break;
        default: {
            // if (apFile->GetLittleEndian()) {
            //     data.Endian();
            // }
        } break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

void TESSkill::Copy(TESForm *apCopy) {
    TESSkill *apCopy_Skill = dynamic_cast<TESSkill *>(apCopy);
    if (apCopy_Skill != nullptr) {
        CopyAllComponents(apCopy);
        memcpy(&data, &apCopy_Skill->data, sizeof(data));
        for (int i = 0; i < 4; i++) {
            SkillLevelText[i].CopyComponent(&apCopy_Skill->SkillLevelText[i]);
        }
    }
}

bool TESSkill::Compare(TESForm *apCompare) {
    TESSkill *apComp_Skill = dynamic_cast<TESSkill *>(apCompare);
    if (apComp_Skill == nullptr) {
        return true;
    }
    if (CompareAllComponents(apComp_Skill)) {
        return true;
    }
    if (memcmp(&data, &apComp_Skill->data, sizeof(data)))
        return true;
    for (int i = 0; i < 4; i++) {
        if (SkillLevelText[i].CompareComponent(&apComp_Skill->SkillLevelText[i]))
            return true;
    }
    return false;
}

void TESSkill::ResetData() {
    data.eIndex = ActorValue::SKILL_NONE;
    data.eSpecialization = SPECIALIZATION_COMBAT;
    data.eAttribute = ActorValue::ATTRIBUTE_START;
    data.fActionValue[0] = 1.0f;
    data.fActionValue[1] = 1.0f;
    for (int i = 0; i < 4; i++) {
        SkillLevelText[i].InitializeDataComponent();
    }
    SetAltered(false);
    auto files = GetFileList();
    if (files)
        files->RemoveAll();
}

void TESSkill::InitializeData() { ResetData(); }

TESSkill::TESSkill() {
    SetFormType(SKIL_ID);
    ResetData();
}
