#include "TESValueForm.h"
#include "fallout_shared/TESForm.h"
#include "fallout/misc/saveload/bgssaveformbuffer.h"
#include "fallout/misc/saveload/BGSLoadFormBuffer.h"
#include "fallout_shared/magic/magicitem.h"

bool TESValueForm::CompareComponent(BaseFormComponent *apCompareFC) {
    TESValueForm *apCompareVF = dynamic_cast<TESValueForm *>(apCompareFC);
    if (apCompareVF == nullptr) {
        return true;
    }
    bool b;
    b = iValue != apCompareVF->iValue ? true : false;
    return b;
}

int TESValueForm::GetFormValue(TESForm *apForm) {
    TESValueForm *apVF = dynamic_cast<TESValueForm *>(apForm);
    if (apVF) {
        return apVF->GetFormValue();
    }
    MagicItem *apMI = dynamic_cast<MagicItem *>(apForm);
    if (apMI) {
        return apMI->GetCost(nullptr);
    }
    // AlchemyItem *apAI = dynamic_cast<AlchemyItem *>(apForm);
    // if (apAI) {
    //     return apAI->GetCost(nullptr);
    // }
    return -1;
}

void TESValueForm::SetFormValue(int aiValue) {
    iValue = aiValue;
    TESForm *apCopyForm = dynamic_cast<TESForm *>(this);
    if (apCopyForm) {
        apCopyForm->GetSaveSize(2);
    }
}

u16 TESValueForm::GetSaveSize(uint aiFlags) {
    u16 siz = 0;
    if (aiFlags & 2)
        siz = 4;
    return siz;
}

void TESValueForm::SaveGame(unsigned int) {}

void TESValueForm::LoadGame(unsigned int, unsigned int) {}

void TESValueForm::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {
    if (apSaveGameBuffer->GetChangeFlags().CheckFlags(2)) {
        apSaveGameBuffer->SaveDataEndian(&iValue, sizeof(iValue), 4, 0);
    }
}

void TESValueForm::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {
    if (apLoadGameBuffer->GetChangeFlags().CheckFlags(2)) {
        apLoadGameBuffer->LoadDataEndian(&iValue, sizeof(iValue), 4);
    }
}

TESValueForm::TESValueForm() { iValue = 0; }

TESValueForm::~TESValueForm() {}

void TESValueForm::CopyComponent(BaseFormComponent *apCopyFC) {
    TESValueForm *apCopyVF = dynamic_cast<TESValueForm *>(apCopyFC);
    if (apCopyVF) {
        apCopyVF->SetFormValue(iValue);
    }
}
