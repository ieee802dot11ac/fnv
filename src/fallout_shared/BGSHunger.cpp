#include "BGSHunger.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/magic/spellitem.h"
#include <cstring>

void BGSHungerStage::Copy(TESForm *apCopy) {
    BGSHungerStage *apCopy_Hungy = dynamic_cast<BGSHungerStage *>(apCopy);
    if (apCopy_Hungy != nullptr) {
        CopyAllComponents(apCopy_Hungy);
        // per-byte memcpy...?
        memcpy(&data, &apCopy_Hungy->data, sizeof(BGSHungerStageData));
    }
}

bool BGSHungerStage::Compare(TESForm *apCompare) {
    BGSHungerStage *apComp_Hungy = dynamic_cast<BGSHungerStage *>(apCompare);
    if (apComp_Hungy == nullptr) {
        return true;
    }
    if (CompareAllComponents(apComp_Hungy)) {
        return true;
    }
    if (memcmp(&data, &apComp_Hungy->data, sizeof(data)))
        return true;

    return false;
}

bool BGSHungerStage::Load(TESFile *apFile) {
    u8 form_type = apFile->GetTESForm();
    if (form_type != HUNG_ID)
        return false;
    ClearData();
    LoadForm(apFile);
    SetInitialized(false);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
            LOADOBJBOUND
            LOADEDITORID
        case DATA_ID: {
            LoadData(apFile, &data, sizeof(data));
            if (apFile->GetLittleEndian()) {
                data.Endian();
            }
        } break;
        default:
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

BGSHungerStage::BGSHungerStage() {
    SetFormType(HUNG_ID);
    data.Initialize();
}

void BGSHungerStage::ClearData() { RemoveStage(this); }

void BGSHungerStage::InitItem() {
    if (!GetInitialized()) {
        uint disease_fid = reinterpret_cast<uint>(data.pSickness);
        if (disease_fid != 0) {
            AddCompileIndex(disease_fid, GetFile(-1));
            data.pSickness = dynamic_cast<SpellItem *>(GetFormByNumericID(disease_fid));
        }
        SetInitialized(true);
        AddStage(this);
    }
}
