#include "tesform.h"
#include "fallout_shared/enums.h"
#include "bscore/bscoremessage.h"
#include <cstring>

TESForm::TESForm() {}

TESForm::~TESForm() {}

void TESForm::InitializeDataAllComponents() {}

void TESForm::ClearDataAllComponents() {}

TESForm *TESForm::GetFormByNumericID(uint aiSearchID) { return 0; }

TESForm *TESForm::GetFormByEditorID(const char *apSearchID) { return 0; }

void TESForm::InitializeFormDataStructures() {}

void TESForm::ReleaseFormDataStructures() {}

void TESForm::RemoveFromDataStructures() {}

bool TESForm::Save(TESFile *apFile) { return 0; }

void TESForm::CompressSaveBuffer() {}

bool TESForm::SaveEdit(TESFile *apFile) { return 0; }

bool TESForm::SavesBefore(TESForm *apForm) { return 0; }

// bool TESForm::SavesBefore(class FORM *apGroupFORM) {

// 	return 0;
// }

void TESForm::SetTemporary() {}

void TESForm::SetMaster(bool abMaster) {
    if (abMaster) {
        iFormFlags |= 1;
    } else {
        iFormFlags &= ~1;
    }
}

void TESForm::SetNoCollision(bool abNoCollision) {}

void TESForm::SetDelete(bool abDeleted) {}

void TESForm::SetEmpty(bool abEmpty) {}

void TESForm::SetResetDestruct(bool abVal) {
    if (abVal) {
        iFormFlags |= 0x2000;
    } else {
        iFormFlags &= ~0x2000;
    }
}

void TESForm::SetDestroyed(bool abVal) {
    if (abVal) {
        iFormFlags |= 0x800000;
    } else {
        iFormFlags &= ~0x800000;
    }
    AddChange(1);
}

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

void TESForm::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

// void TESForm::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

bool TESForm::IsDefaultForm() const {
    if (iFormID != 0 && iFormID <= 0x7FF) {
        return true;
    }
    return 0;
}

TESFile *TESForm::GetFile(int aiIndex) { return 0; }

TESFile *TESForm::GetOwnerMaster() { return 0; }

void TESForm::SetFile(TESFile *apFile) {}

void TESForm::LoadForm(TESFile *apFile) {}

void TESForm::Copy(TESForm *apCopy) {}

bool TESForm::Compare(TESForm *apCopy) { return 0; }

void TESForm::CopyAllComponents(TESForm *apCopy) {}

bool TESForm::CompareAllComponents(TESForm *apCompare) { return 0; }

void TESForm::CopyComponent(BaseFormComponent *apCopyFC) {}

bool TESForm::CompareComponent(BaseFormComponent *apCompareFC) { return false; }

// bool TESForm::BelongsInGroup(
//     FORM *apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly
// ) {}

// void TESForm::CreateGroupData(FORM *apOutGroupFORM, FORM_GROUP *apParentGroup) {}

void TESForm::CloseForm() {
    if (GetTemporary())
        return;
    FORM *f = (FORM *)pFormBuffer;
    f->length = iBufferSize - sizeof(FORM);
    if (bEndianSwapOnSave) {
        f->Endian();
    }
}

void TESForm::AddChunk(CHUNK_ID aeChunkID, uint aiData) {}

void TESForm::__AddChunkData(CHUNK_ID aeChunkID, void const *apData, uint aiSize) {
    BS_ASSERT_NOFUNC(
        (aiSize & 0xFFFF) != 0,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESForm.cpp",
        2147
    );
    int bufsiz = iBufferSize;

    memcpy((char *)pFormBuffer + bufsiz + 6, apData, aiSize);
}

// bool TESForm::ExpandChunk(CHUNK *apChunk, unsigned short asExpandSize) {}

void TESForm::StartForm() {
    if (!GetTemporary()) {
        iBufferSize = sizeof(FORM);
        FORM *form = new (
            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESForm.cpp",
            1878,
            __FUNCTION__
        ) FORM;
        pFormBuffer = form;
        uint flags = iFormFlags;
        form->flags = flags;
        if (cFormType != TES4_ID) {
            form->flags = flags & 0x30032FE0;
        }
        form->form = formEnumString[cFormType].iFormString;
        form->iFormID = iFormID;
        form->length = 0;
        form->sFormVersion = TESFile::GetFileFormVersion();
        form->iVersionControl = 0;
        form->sVCVersion = 0;
        SaveObjectBound();
    }
}

void TESForm::AddChunk(CHUNK_ID aeChunkID) { __AddChunkData(aeChunkID, nullptr, 0); }

void TESForm::AddChunkArray(CHUNK_ID aeChunkID, char const *apData, uint aiSize) {
    __AddChunkData(aeChunkID, apData, aiSize);
}

void TESForm::AddChunkArray(CHUNK_ID aeChunkID, float const *apData, uint aiCount) {}

void TESForm::AddChunkArray(CHUNK_ID aeChunkID, short const *apData, uint aiCount) {
    AddChunkArray16(aeChunkID, apData, aiCount);
}

void TESForm::AddChunkArray32(CHUNK_ID aeChunkID, void const *apData, uint aiCount) {}

void TESForm::AddChunkArray16(CHUNK_ID aeChunkID, void const *apData, uint aiCount) {
    aiCount *= 2;
    if (bEndianSwapOnSave) {
    }
    __AddChunkData(aeChunkID, apData, aiCount);
}

void TESForm::AddChunk(CHUNK_ID aeChunkID, s8 aiData) {}

void TESForm::AddChunk(CHUNK_ID aeChunkID, float afData) {}

void TESForm::AddChunk(CHUNK_ID aeChunkID, unsigned short aiData) {}

void TESForm::FreeFormBuffer() {}

bool TESForm::FindInFileFast(TESFile *apFile) { return false; }

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
