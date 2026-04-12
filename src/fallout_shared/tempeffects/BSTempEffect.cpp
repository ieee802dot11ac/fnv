#include "BSTempEffect.h"
#include "nimain/NiRTTI.h"

MAKEROOTRTTI(BSTempEffect)

BSSimpleList<NiPointer<BSTempEffect> > BSTempEffect::kDecalList;

BSTempEffect::BSTempEffect(TESObjectCELL *apCell, float afLifetime) {
    pCell = apCell;
    fLifetime = afLifetime;
    fAge = 0.0f;
    bInitialized = false;
}

const NiRTTI *BSTempEffect::GetRTTI() const { return &ms_RTTI; }

void BSTempEffect::Initialize() { bInitialized = true; }

BSTempEffect::~BSTempEffect() {
    pCell = nullptr;
    fLifetime = 0.0f;
    fAge = 0.0f;
    bInitialized = false;
}

bool BSTempEffect::Update(float afTimeDelta) {
    fAge += afTimeDelta;
    if (fAge > fLifetime)
        return false;
    return true;
}

u16 BSTempEffect::GetSaveSize() { return 12; }

void BSTempEffect::SaveGame() {}

bool BSTempEffect::LoadGame() { return false; }

void BSTempEffect::SaveGame(BGSSaveGameBuffer *apSaveGameBuffer) {
    apSaveGameBuffer->SaveDataEndian(&fLifetime, sizeof(fLifetime), 4, 0);
    apSaveGameBuffer->SaveDataEndian(&fAge, sizeof(fAge), 4, 0);
    apSaveGameBuffer->SaveData(&bInitialized, sizeof(bInitialized), 0);
}

void BSTempEffect::LoadGame(BGSLoadGameBuffer *apLoadGameBuffer) {
    apLoadGameBuffer->LoadDataEndian(&fLifetime, sizeof(fLifetime), 4);
    apLoadGameBuffer->LoadDataEndian(&fAge, sizeof(fAge), 4);
    apLoadGameBuffer->LoadData(&bInitialized, sizeof(bInitialized));
}
