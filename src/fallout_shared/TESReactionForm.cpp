#include "TESReactionForm.h"
#include "fallout_shared/TESForm.h"

void TESReactionForm::InitializeDataComponent() { m_cGroupFormType = FACT_ID; }

TESReactionForm::TESReactionForm() { InitializeDataComponent(); }

void TESReactionForm::Save() {
    if (GetReactionList() == nullptr)
        return;
    bool swapendian = TESForm::QEndianSwapOnSave();
    for (auto *reactions = GetReactionList();
         reactions != nullptr && !reactions->IsEmpty();
         reactions = reactions->GetNext()) {
        if (swapendian) {
            reactions->GetItem()->Endian();
        }
        GROUP_REACTION gr = *reactions->GetItem();
        TESForm::__AddChunkData(XNAM_ID, &gr, sizeof(GROUP_REACTION));
        if (swapendian) {
            reactions->GetItem()->Endian();
        }
    }
}

bool TESReactionForm::CompareComponent(BaseFormComponent *apCompareFC) { return 0; }

int TESReactionForm::GetReaction(TESForm *apForm) { return 0; }

FIGHT_REACTION TESReactionForm::GetFactionCombatRelation(TESForm *apForm) {
    return FIGHT_REACTION_NEUTRAL;
}

u16 TESReactionForm::GetSaveSize(uint aiFlags) { return 0; }

void TESReactionForm::SaveGame(uint aiFlags) {}

void TESReactionForm::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

void TESReactionForm::FreeReactionList() {
    for (auto *reactions = GetReactionList(); reactions->GetItem() != nullptr;) {
        delete reactions->GetItem();
        if (reactions->GetNext() != nullptr) {
            auto *next = reactions->GetNext();
            *next = *reactions;
            next->SetNext(nullptr);
            delete reactions;
            // reactions = next;
        } else {
            reactions->GetItem() = nullptr;
        }
    }
}

void TESReactionForm::InitItem(TESForm *apOwner) {}

void TESReactionForm::CopyComponent(BaseFormComponent *apCopyFC) {}

void TESReactionForm::SetReaction(TESForm *apForm, int aiReaction) {}

void TESReactionForm::ModReaction(TESForm *apForm, int aiReaction) {}

void TESReactionForm::SetFightReaction(TESForm *apForm, int aiFightReaction) {}

void TESReactionForm::LoadGame(uint aiFlags, uint aiCurrentFlags) {}

void TESReactionForm::InitLoadGame(uint aiFlags, uint aiOldFlags) {}

void TESReactionForm::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

void TESReactionForm::InitLoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

void TESReactionForm::ClearDataComponent() { FreeReactionList(); }

TESReactionForm::~TESReactionForm() { ClearDataComponent(); }
