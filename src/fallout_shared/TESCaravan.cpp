#include "TESCaravan.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/enums.h"
#include <cstring>

void TESCaravanCard::ClearData() {
    faceTexture.ClearDataComponent();
    backTexture.ClearDataComponent();
    memset(&data, 0, sizeof(data));
}

void TESCaravanCard::InitializeData() {
    faceTexture.InitializeDataComponent();
    backTexture.InitializeDataComponent();
    memset(&data, 0, sizeof(data));
}

void TESCaravanCard::InitItem() {
    if (!GetInitialized()) {
        TESModelTextureSwap::InitItem(this);
        TESScriptableForm::InitItem(this);
        BGSPickupPutdownSounds::InitItem(this);
        SetInitialized(true);
    }
}

void TESCaravanCard::Save() {
    StartForm();
    TESFullName::Save();
    TESModelTextureSwap::Save(MODL_ID, MODT_ID, MODS_ID);
    TESIcon::Save(ICON_ID);
    BGSMessageIcon::Save(MICO_ID);
    TESScriptableForm::Save();
    BGSPickupPutdownSounds::Save();
    faceTexture.Save(TX00_ID);
    backTexture.Save(TX01_ID);
    AddChunk(INTV_ID, data.iCardSuit);
    AddChunk(INTV_ID, data.iFaceValue);
    SaveData();
    CloseForm();
}

bool TESCaravanCard::Load(TESFile *apFile) {
    u8 formid = apFile->GetTESForm();
    bool carddata_firsthalf = false;
    if (formid != CCRD_ID)
        return false;
    LoadForm(apFile);
    SetInitialized(false);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
        case TX01_ID: {
            LoadTextureChunk(&backTexture, apFile);
        } break;
        case TX00_ID: {
            LoadTextureChunk(&faceTexture, apFile);
        } break;
        case DATA_ID: {
            LoadData(apFile, nullptr, 0);
        } break;
        case MODD_ID:
        case MODL_ID:
        case MOSD_ID: {
            LoadModelChunk(this, apFile);
        } break;
            LOADEDITORID
        case SCRI_ID: {
            Script *script = nullptr;
            apFile->GetChunkData(reinterpret_cast<int &>(script));
            SetFormScript(script);
            TESScriptableForm::InitItem(this);
        } break;
        case OBND_ID: {
            LoadObjectBound(apFile);
        } break;
        case YNAM_ID: {
            TESSound *sound = nullptr;
            apFile->GetChunkData(reinterpret_cast<int &>(sound));
            SetPickupSound(sound);
        } break;
        case FULL_ID: {
            LoadFullNameChunk(this, apFile);
        } break;
        case ZNAM_ID: {
            TESSound *sound = nullptr;
            apFile->GetChunkData(reinterpret_cast<int &>(sound));
            SetPutdownSound(sound);
        } break;
        case ICON_ID: {
            LoadTextureChunk(this, apFile);
        } break;
        case MICO_ID: {
            LoadMessageIcon(this, apFile);
        } break;
        case INTV_ID: {
            // sure. whatever
            if (!carddata_firsthalf) {
                apFile->GetChunkData(data.iCardSuit);
                carddata_firsthalf = true;
            } else {
                apFile->GetChunkData(data.iFaceValue);
            }
        } break;
        case MODS_ID: {
            auto csize = apFile->GetChunkSize();
            void *buf = alloca(csize);
            apFile->GetChunkData(buf, csize);
            UnpackTextureSwapChunkData(buf, apFile->GetFormVersion(), csize);
        } break;
        default:
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

NiAVObject *TESCaravanCard::Clone3D(TESObjectREFR *pRequester, bool deepCopy) {
    return nullptr;
}

u16 TESCaravanCard::GetSaveSize(uint aiFlags) { return 0; }

void TESCaravanCard::SaveGame(uint aiFlags) {}

void TESCaravanCard::LoadGame(uint aiFlags, uint aiCurrentFlags) {}

void TESCaravanCard::SaveGame(BGSSaveFormBuffer *apSaveGameBuffer) {}

void TESCaravanCard::LoadGame(BGSLoadFormBuffer *apLoadGameBuffer) {}

int TESCaravanCard::SortCardsFunc(const void *t1, const void *t2) { return 0; }

void TESCaravanMoney::ClearData() {
    anteModels[0].ClearDataComponent();
    anteModels[1].ClearDataComponent();
}

void TESCaravanMoney::InitializeData() {
    anteModels[0].InitializeDataComponent();
    anteModels[1].InitializeDataComponent();
}

void TESCaravanMoney::InitItem() {
    if (!GetInitialized()) {
        TESModelTextureSwap::InitItem(this);
        BGSPickupPutdownSounds::InitItem(this);
        SetInitialized(true);
    }
}

void TESCaravanMoney::Save() {
    StartForm();
    TESFullName::Save();
    TESModelTextureSwap::Save(MODL_ID, MODT_ID, MODS_ID);
    TESIcon::Save(ICON_ID);
    BGSMessageIcon::Save(MICO_ID);
    BGSPickupPutdownSounds::Save();
    SaveData();
    anteModels[0].Save(MOD2_ID, MODT_ID, MODS_ID);
    anteModels[1].Save(MOD3_ID, MODT_ID, MODS_ID);
    CloseForm();
}

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

void TESCaravanDeck::Save() {
    StartForm();
    TESFullName::Save();
    for (auto *cards = pDeck; cards != nullptr && cards->GetItem() != nullptr;
         cards = cards->GetNext()) {
        AddChunk(CARD_ID, cards->GetItem()->GetFormID());
    }
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    __SaveData(&data, sizeof(data));
    if (QEndianSwapOnSave()) {
        data.Endian();
    }
    CloseForm();
}

bool TESCaravanDeck::Compare(TESForm *apCompare) { return false; }

void TESCaravanCard::Copy(TESForm *apCopy) {}

void TESCaravanDeck::ClearData() {}

bool TESCaravanDeck::Load(TESFile *apFile) { return false; }

void TESCaravanDeck::Copy(TESForm *apCopy) {}

TESCaravanCard::~TESCaravanCard() { ClearData(); }
