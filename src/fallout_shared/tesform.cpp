#include "tesform.h"

TESForm::TESForm() {}

TESForm::~TESForm() {}

void TESForm::InitializeDataAllComponents() {}

void TESForm::ClearDataAllComponents() {}

TESForm *TESForm::GetFormByNumericID(uint aiSearchID) { return 0; }

TESForm *TESForm::GetFormByEditorID(const char *apSearchID) { return 0; }

void TESForm::InitializeFormDataStructures() {}

void TESForm::ReleaseFormDataStructures() {}

void TESForm::RemoveFromDataStructures() {}

// bool TESForm::Save(class TESFile *apFile) {

// 	return 0;
// }

void TESForm::CompressSaveBuffer() {}

// bool TESForm::SaveEdit(class TESFile *apFile) {

// 	return 0;
// }

bool TESForm::SavesBefore(TESForm *apForm) { return 0; }

// bool TESForm::SavesBefore(class FORM *apGroupFORM) {

// 	return 0;
// }

void TESForm::SetTemporary() {}

void TESForm::SetMaster(bool abMaster) {}

void TESForm::SetNoCollision(bool abNoCollision) {}

void TESForm::SetDelete(bool abDeleted) {}

void TESForm::SetEmpty(bool abEmpty) {}

void TESForm::SetResetDestruct(bool abVal) {}

void TESForm::SetDestroyed(bool abVal) {}

void TESForm::SetDestructible(bool abVal) {}

void TESForm::SetVATSTargetOverride(bool abVal) {}

void TESForm::SetAltered(bool abAltered) {}

void TESForm::SetQuestObject(bool abQuest) {
    if (abQuest) {
        iFormFlags |= 0x400;
    } else {
        iFormFlags &= ~0x400;
    }
    AddChange(1);
}

void TESForm::SetInPlaceableWater(bool abWater) {
    if (abWater) {
        iFormFlags |= 0x40;
    } else {
        iFormFlags &= ~0x40;
    }
    AddChange(1);
}

void TESForm::SetHavokDeath(bool abDeath) {
    if (abDeath) {
        iFormFlags |= 0x10000;
    } else {
        iFormFlags &= ~0x10000;
    }
    AddChange(1);
}

void TESForm::SetNeedToChangeProcess(bool abChange) {
    if (abChange) {
        iFormFlags |= 0x20000;
    } else {
        iFormFlags &= ~0x20000;
    }
}

void TESForm::SetIgnoreFriendlyHits(bool abIgnoreFriendlyHits) {
    if (abIgnoreFriendlyHits) {
        iFormFlags |= 0x100000;
    } else {
        iFormFlags &= ~0x100000;
    }
}

void TESForm::SetOnLocalMap(bool abVal) {
    if (abVal) {
        iFormFlags |= 0x200;
    } else {
        iFormFlags &= ~0x200;
    }
}

void TESForm::SetFireOff(bool abVal) {}

void TESForm::SetInitialized(bool abInit) {}

void TESForm::SetDisabled(bool abDisabled) {}

bool TESForm::IsDefaultForm(uint aiID) {
    if (aiID != 0 && aiID <= 0x7FF) {
        return true;
    }
    return 0;
}

void TESForm::AddChange(int aiChangeFlags) {}

void TESForm::ForceChange(int aiChangeFlags) {}

void TESForm::RemoveChange(int aiChangeFlags) {}

unsigned short TESForm::GetSaveSize(uint aiFlags) {
    if (aiFlags & 1)
        return 4;
    else
        return 0;
}

void TESForm::SaveGame(uint aiFlags) {}

void TESForm::LoadGame(uint aiFlags, uint aiCurrentFlags) {}

void TESForm::SaveGameDataOLD(void *apData, int aiSize) {}

void TESForm::LoadGameDataOLD(void *apData, int aiSize) {}

void TESForm::SaveNumericID(uint *apNumericID, int aiSize) {}

void TESForm::LoadNumericID(uint *apNumericID, int aiSize) {}

void TESForm::SaveGameDataOLD(short *apData, int aiSize) {}

void TESForm::SaveGameDataOLD(int *apData, int aiSize) {}

void TESForm::LoadGameDataOLD(short *apData, int aiSize) {}

void TESForm::LoadGameDataOLD(int *apData, int aiSize) {}

// void TESForm::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

// void TESForm::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

bool TESForm::IsDefaultForm() const {
    if (iFormID != 0 && iFormID <= 0x7FF) {
        return true;
    }
    return 0;
}

// TESFile *TESForm::GetFile(int aiIndex) { return 0; }

// TESFile *TESForm::GetOwnerMaster() { return 0; }

// void TESForm::SetFile(TESFile *apFile) {}

// void TESForm::LoadForm(TESFile *apFile) {}

void TESForm::Copy(TESForm *apCopy) {}

bool TESForm::Compare(TESForm *apCopy) { return 0; }

void TESForm::CopyAllComponents(TESForm *apCopy) {}

bool TESForm::CompareAllComponents(TESForm *apCompare) { return 0; }

// void TESForm::CopyComponent(BaseFormComponent *apCopyFC) {}

// bool TESForm::CompareComponent(BaseFormComponent *apCompareFC) {}

// bool TESForm::BelongsInGroup(
//     FORM *apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly
// ) {}

// void TESForm::CreateGroupData(FORM *apOutGroupFORM, FORM_GROUP *apParentGroup) {}

void TESForm::StartForm() {}

void TESForm::CloseForm() {}

// void TESForm::AddChunk(CHUNK_ID aeChunkID) {}

// void TESForm::AddChunkArray(CHUNK_ID aeChunkID, char const *apData, uint aiSize) {}

// void TESForm::AddChunkArray(CHUNK_ID aeChunkID, float const *apData, uint aiCount) {}

// void TESForm::AddChunkArray(CHUNK_ID aeChunkID, short const *apData, uint aiCount) {}

// void TESForm::AddChunkArray32(CHUNK_ID aeChunkID, void const *apData, uint aiCount) {}

// void TESForm::AddChunkArray16(CHUNK_ID aeChunkID, void const *apData, uint aiCount) {}

// void TESForm::AddChunk(CHUNK_ID aeChunkID, char aiData) {}

// void TESForm::AddChunk(CHUNK_ID aeChunkID, uint aiData) {}

// void TESForm::AddChunk(CHUNK_ID aeChunkID, float afData) {}

// void TESForm::AddChunk(CHUNK_ID aeChunkID, unsigned short aiData) {}

// void TESForm::__AddChunkData(CHUNK_ID aeChunkID, void const *apData, uint aiSize) {}

// bool TESForm::ExpandChunk(CHUNK *apChunk, unsigned short asExpandSize) {}

void TESForm::FreeFormBuffer() {}

// bool TESForm::FindInFileFast(TESFile *apFile) {}

uint TESForm::GetFormIDAsSaved() { return 0; }

bool TESForm::FormIDMatchesWithoutIndex(uint aiID) const {
    return ((aiID ^ iFormID) & 0xFFFFFF) == 0;
}

void TESForm::SetFormID(uint aiID, bool abUpdateFile) {}

// void TESForm::AddCompileIndex(uint &aiID, TESFile *apFile) {}

bool TESForm::SetFormEditorID(char const *apEditorID) { return 0; }

bool TESForm::FixFormEditorID(char *apEditorID) { return 0; }

void TESForm::SaveData() {}

void TESForm::__SaveData(void *apData, uint aiSize) {}

// void TESForm::LoadData(TESFile *apFile, void *apData, unsigned short asSize) {}

uint TESForm::GetDataSizeAdded() { return 0; }

// TESForm *TESForm::CreateDuplicateForm(
//     bool abCreateEditorID, NiTPointerMap<TESForm *, TESForm *> *apCopyMap
// ) {}

// ENUM_FORM_ID TESForm::GetFormTypeFromFormString(uint aiFormString) {}

// void TESForm::GetFormDetailedString(BSStringT<char> &aString) {}
