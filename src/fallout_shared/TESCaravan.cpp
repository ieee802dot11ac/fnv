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
        case MOSD_ID:
        case MODT_ID: {
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
        case ZNAM_ID: {
            TESSound *sound = nullptr;
            apFile->GetChunkData(reinterpret_cast<int &>(sound));
            SetPutdownSound(sound);
        } break;
        case FULL_ID: {
            LoadFullNameChunk(this, apFile);
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
            UnpackTextureSwapChunkData(buf, csize, apFile->GetFormVersion());
        } break;
        default:
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

int TESCaravanCard::SortCardsFunc(const void *t1, const void *t2) {
    const TESCaravanCard *c1 = *reinterpret_cast<const TESCaravanCard *const *>(t1);
    const TESCaravanCard *c2 = *reinterpret_cast<const TESCaravanCard *const *>(t2);
    if (int(c1->data.iFaceValue) > int(c2->data.iFaceValue))
        return true;
    return int(c1->data.iFaceValue) < int(c2->data.iFaceValue) ? -1 : 0;
}

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

bool TESCaravanMoney::Load(TESFile *apFile) {
    u8 formid = apFile->GetTESForm();
    bool carddata_firsthalf = false;
    if (formid != CMNY_ID)
        return false;
    LoadForm(apFile);
    SetInitialized(false);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
        case DATA_ID: {
            LoadData(apFile, nullptr, 0);
        } break;
        case MOD3_ID: {
            auto csize = apFile->GetChunkSize();
            void *buf = alloca(csize);
            apFile->GetChunkData(buf, 0);
            anteModels[1].SetModel(reinterpret_cast<const char *>(buf));
            LoadModelTextureChunk(&anteModels[1], apFile);
        } break;
        case MOD2_ID: {
            auto csize = apFile->GetChunkSize();
            void *buf = alloca(csize);
            apFile->GetChunkData(buf, 0);
            anteModels[0].SetModel(reinterpret_cast<const char *>(buf));
            LoadModelTextureChunk(&anteModels[0], apFile);
        } break;
            LOADEDITORID
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
            // hey guys. why are we loading raw pointers from disk.
            TESSound *sound = nullptr;
            apFile->GetChunkData(reinterpret_cast<int &>(sound));
            SetPutdownSound(sound);
        } break;
        case MICO_ID: {
            LoadMessageIcon(this, apFile);
        } break;
        case ICON_ID: {
            LoadTextureChunk(this, apFile);
        } break;
        case MODL_ID:
        case MODD_ID:
        case MODT_ID:
        case MOSD_ID: {
            LoadModelChunk(this, apFile);
        } break;
        case MODS_ID: {
            auto csize = apFile->GetChunkSize();
            void *buf = alloca(csize);
            apFile->GetChunkData(buf, csize);
            UnpackTextureSwapChunkData(buf, csize, apFile->GetFormVersion());
        } break;
        default:
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

void TESCaravanMoney::Copy(TESForm *apCopy) {
    TESCaravanMoney *apCopy_Money = dynamic_cast<TESCaravanMoney *>(apCopy);
    if (apCopy_Money != nullptr) {
        CopyAllComponents(apCopy_Money);
        anteModels[0].SetModel(apCopy_Money->anteModels[0].GetModel());
        anteModels[1].SetModel(apCopy_Money->anteModels[1].GetModel());
        SetFormType(apCopy->GetFormType());
    }
}

bool TESCaravanMoney::Compare(TESForm *apCompare) { return false; }

bool TESCaravanCard::Compare(TESForm *apCompare) { return false; }

void TESCaravanDeck::InitializeData() {
    pDeck = new (
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESCaravan.cpp",
        490,
        __FUNCTION__
    ) BSSimpleList<TESCaravanCard *>;
    data.iDeckSize = 0;
}

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

void TESCaravanCard::Copy(TESForm *apCopy) {
    TESCaravanCard *apCopy_Card = dynamic_cast<TESCaravanCard *>(apCopy);
    if (apCopy_Card != nullptr) {
        CopyAllComponents(apCopy_Card);
        faceTexture.SetTextureName(apCopy_Card->faceTexture.GetTextureName());
        backTexture.SetTextureName(apCopy_Card->backTexture.GetTextureName());
        data = apCopy_Card->data;
        SetFormType(apCopy->GetFormType());
    }
}

void TESCaravanDeck::ClearData() {
    pDeck->RemoveAll();
    memset(&data, 0, sizeof(data));
}

bool TESCaravanDeck::Load(TESFile *apFile) {
    u8 formid = apFile->GetTESForm();
    bool carddata_firsthalf = false;
    if (formid != CDCK_ID)
        return false;
    LoadForm(apFile);
    SetInitialized(false);
    for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
         chunk = apFile->GetTESChunk()) {
        switch (chunk) {
        case DATA_ID: {
            LoadData(apFile, &data, sizeof(CARAVANDECKDATA));
        } break;
            LOADEDITORID
        case OBND_ID: {
            LoadObjectBound(apFile);
        } break;
        case FULL_ID: {
            LoadFullNameChunk(this, apFile);
        } break;
        case CARD_ID: {
            uint card_fid;
            apFile->GetChunkData(card_fid);
            AddCompileIndex(card_fid, apFile);
            TESForm *card_form = GetFormByNumericID(card_fid);
            auto *card = reinterpret_cast<TESCaravanCard *>(card_form);
            if (pDeck != nullptr && !pDeck->IsEmpty()) {
                pDeck->AddHead(card);
                break;
            }
            if (card_form != nullptr)
                pDeck->GetItem() = card;
        } break;
        default:
            break;
        }
        if (chunk == DATA_ID && apFile->GetLittleEndian()) {
            data.Endian();
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

void TESCaravanDeck::Copy(TESForm *apCopy) {}

TESCaravanCard::~TESCaravanCard() { ClearData(); }

TESCaravanMoney::TESCaravanMoney() {
    SetFormType(CMNY_ID);
    InitializeData();
}

TESCaravanMoney::~TESCaravanMoney() { ClearData(); }

TESCaravanDeck::TESCaravanDeck() {
    SetFormType(CDCK_ID);
    InitializeData();
}

TESCaravanDeck::~TESCaravanDeck() { ClearData(); }

TESCaravanCard::TESCaravanCard() {
    SetFormType(CCRD_ID);
    InitializeData();
}
