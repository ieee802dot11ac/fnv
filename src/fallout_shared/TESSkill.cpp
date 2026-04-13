#include "TESSkill.h"
#include <cstring>

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

// void TESSkill::ResetData() {}

void TESSkill::InitializeData() { ResetData(); }

TESSkill::TESSkill() {
    SetFormType(SKIL_ID);
    ResetData();
}
