#include "TESDescription.h"
#include "bscore/bsstring.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesfile.h"

TESDescription *TESDescription::pCurrentDescription = nullptr;
BSStringT<char> TESDescription::cDescription;

void TESDescription::LoadDescriptionData(TESDescription *apDesc, TESFile *apFile) {
    if (apDesc && apFile) {
        apDesc->lFileOffset = apFile->GetOffset();
    }
}

void TESDescription::SaveDescriptionData(TESDescription *apDesc, CHUNK_ID aiChunk) {
    if (apDesc == nullptr)
        return;
}

bool TESDescription::CompareComponent(BaseFormComponent *apCompareFC) {
    TESDescription *apCompareFC_Desc = dynamic_cast<TESDescription *>(apCompareFC);
    if (apCompareFC_Desc == nullptr) {
        return true;
    }
    // copy cDescription? i guess?
    return (cDescription.StrCmp(apCompareFC_Desc->GetDescription(), false) != 0) ? 0 : 1;
}

void TESDescription::InitializeDataComponent() {
    cDescription.Set(nullptr, 0);
    pCurrentDescription = nullptr;
    lFileOffset = 0;
}

void TESDescription::Save() { SaveDescriptionData(this, DESC_ID); }

void TESDescription::CopyComponent(BaseFormComponent *apCopyFC) {
    TESDescription *apCopyFC_Desc = dynamic_cast<TESDescription *>(apCopyFC);
    if (apCopyFC_Desc != nullptr) {
        cDescription.Set(apCopyFC_Desc->GetDescription(), 0);
        lFileOffset = apCopyFC_Desc->lFileOffset;
    }
}

void TESDescription::LoadDescription(TESForm *apForm, CHUNK_ID aeChunk) {}

TESDescription::TESDescription() { InitializeDataComponent(); }

const char *TESDescription::GetDescription(TESForm *apForm, CHUNK_ID aeChunk) {
    // if (pDataHandler->bLoadingFiles) {
    LoadDescription(apForm ? apForm : dynamic_cast<TESForm *>(this), aeChunk);
    // }
    if (cDescription.String() == nullptr) {
        return "";
    } else
        return cDescription.String();
}
