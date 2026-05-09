#include "TESCaravan.h"

void TESCaravanCard::ClearData() {}

void TESCaravanCard::InitializeData() {}

void TESCaravanCard::InitItem() {}

void TESCaravanCard::Save() {}

bool TESCaravanCard::Load(TESFile *apFile) { return false; }

NiAVObject *TESCaravanCard::Clone3D(TESObjectREFR *pRequester, bool deepCopy) {
    return nullptr;
}

u16 TESCaravanCard::GetSaveSize(uint aiFlags) { return 0; }

void TESCaravanCard::SaveGame(uint aiFlags) {}

void TESCaravanCard::LoadGame(uint aiFlags, uint aiCurrentFlags) {}

void TESCaravanCard::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

void TESCaravanCard::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

int TESCaravanCard::SortCardsFunc(const void *t1, const void *t2) { return 0; }

void TESCaravanMoney::ClearData() {}

void TESCaravanMoney::InitializeData() {}

void TESCaravanMoney::InitItem() {}

void TESCaravanMoney::Save() {}

bool TESCaravanMoney::Load(TESFile *apFile) { return false; }

void TESCaravanMoney::Copy(TESForm *apCopy) {}

bool TESCaravanMoney::Compare(TESForm *apCompare) { return false; }

NiAVObject *TESCaravanMoney::Clone3D(TESObjectREFR *pRequester, bool deepCopy) {
    return nullptr;
}

u16 TESCaravanMoney::GetSaveSize(uint aiFlags) { return 0; }

void TESCaravanMoney::SaveGame(uint aiFlags) {}

void TESCaravanMoney::LoadGame(uint aiFlags, uint aiCurrentFlags) {}

void TESCaravanMoney::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

void TESCaravanMoney::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

bool TESCaravanCard::Compare(TESForm *apCompare) { return false; }

void TESCaravanDeck::InitializeData() {}

void TESCaravanDeck::Save() {}

bool TESCaravanDeck::Compare(TESForm *apCompare) { return false; }

void TESCaravanCard::Copy(TESForm *apCopy) {}

void TESCaravanDeck::ClearData() {}

bool TESCaravanDeck::Load(TESFile *apFile) { return false; }

void TESCaravanDeck::Copy(TESForm *apCopy) {}
