#include "TESEyes.h"
#include "stdlib.h"

void TESEyes::InitializeData() { cFlags = 0; }

void TESEyes::Save() {
    StartForm();
    TESFullName::Save();
    TESTexture::Save(ICON_ID);
    AddChunk(DATA_ID, static_cast<u8>(cFlags));
    CloseForm();
}

bool TESEyes::Load(TESFile *apFile) {
    if (apFile->GetTESForm() != EYES_ID)
        return false;
    LoadForm(apFile);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
        case OBND_ID: {
            LoadObjectBound(apFile);
        } break;
        case EDID_ID: {
            void *buf = alloca(apFile->GetChunkSize());
            apFile->GetChunkData(buf, 0x200);
            SetFormEditorID(static_cast<const char *>(buf));
        } break;
        case DATA_ID: {
            apFile->GetChunkData(&cFlags, sizeof(cFlags));
        } break;
        case ICON_ID: {
            LoadTextureChunk(this, apFile);
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

bool TESEyes::IsPlayable() { return cFlags & BIT(0); }

void TESEyes::Copy(TESForm *apCopy) {
    TESEyes *apCopy_Eyes = dynamic_cast<TESEyes *>(apCopy);
    if (apCopy_Eyes != nullptr) {
        CopyAllComponents(apCopy);
        SetPlayable(apCopy_Eyes->IsPlayable());
        SetCanBeMale(apCopy_Eyes->CanBeMale());
        SetCanBeFemale(apCopy_Eyes->CanBeFemale());
    }
}

bool TESEyes::Compare(TESForm *apCompare) {
    TESEyes *apComp_Eyes = dynamic_cast<TESEyes *>(apCompare);
    if (apComp_Eyes == nullptr) {
        return true;
    }
    if (CompareAllComponents(apComp_Eyes)) {
        return true;
    }
    if (apComp_Eyes->IsPlayable() != IsPlayable())
        return true;
    if (apComp_Eyes->CanBeMale() != CanBeMale())
        return true;
    if (apComp_Eyes->CanBeFemale() != CanBeFemale())
        return true;

    return false;
}

bool TESEyes::CanBeEyesForNPC(TESNPC *apNPC) { return true; }

TESEyes::TESEyes() {}

// TESEyes::~TESEyes() {}
