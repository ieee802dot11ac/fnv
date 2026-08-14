#include "ActiveEffect.h"
#include "fallout_shared/enums.h"

void ActiveEffect::CopyData(ActiveEffect* apDestination) {
	apDestination->fElapsedSeconds = fElapsedSeconds;
	apDestination->pSpell = pSpell;
	apDestination->pEffect = pEffect;
	apDestination->bActive = bActive;
	apDestination->bStarted = bStarted;
	apDestination->bFinished = bFinished;
	apDestination->bDone = bDone;
	apDestination->bWornEnchantment = bWornEnchantment;
	apDestination->fMagnitude = fMagnitude;
	apDestination->fDuration = fDuration;
	apDestination->pTarget = pTarget;
	apDestination->pCaster = pCaster;
	apDestination->eSpellType = eSpellType;
	// apDestination->PersistentSound = PersistentSound;
	apDestination->pSource = pSource;
	// apDestination->pHitEffects = pHitEffects;
	apDestination->iFlags = iFlags;
	apDestination->pDisplacementSpell = pDisplacementSpell;
}

void ActiveEffect::SetEnchantmentSource(TESBoundObject* apSource) {
	pSource = apSource;
	if (apSource != nullptr) {
		if (apSource->GetFormType() != ARMO_ID &&
			apSource->GetFormType() != CLOT_ID)
			return;
		iFlags |= 0x100;
	}
}

void ActiveEffect::SaveActiveEffect(ActiveEffect* apEffect, Actor* apActor) {}

ActiveEffect* ActiveEffect::LoadActiveEffect(Actor* apActor) { return nullptr; }

bool ActiveEffect::CheckDeletedCaster(MagicCaster* apCaster) {
	if (apCaster == pCaster) {
		return false;
	}
	pCaster = nullptr;
	return true;
}

ActiveEffect*
ActiveEffect::LoadActiveEffect(BGSLoadFormBuffer* apLoadGameBuffer) {
	return nullptr;
}

ActiveEffect::ActiveEffect(MagicCaster* apCaster, MagicItem* apSpell,
						   EffectItem* apEffect) {
	pSpell = apSpell;
	eSpellType = apSpell->GetSpellType();
	pEffect = apEffect;
	bActive = true;
	bStarted = false;
	bFinished = false;
	bDone = false;
	fElapsedSeconds = 0.0f;
	fMagnitude = apEffect->GetMagnitude();
	fDuration = apEffect->GetDuration();
	auto* conds = apEffect->GetConditions();
	pCaster = apCaster;
	pTarget = nullptr;
	pSource = nullptr;
	pHitEffects = nullptr;
	iFlags = 0;
	pDisplacementSpell = nullptr;
	if (apEffect && conds) {
		bool noconds = conds->GetConditionItemListConst()->IsEmpty();
		if (!noconds) {
			iFlags |= HAS_CONDITIONS;
		}
	}
}

ActiveEffect* ActiveEffect::Copy() {
	ActiveEffect* new_effect = new (
		"D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect."
		"cpp",
		124, __FUNCTION__) ActiveEffect(pCaster, pSpell, pEffect);
	CopyData(new_effect);
	return new_effect;
}

void ActiveEffect::StartSound() {
	TESSound* hitsound = pEffect->GetEffectSetting()->GetHitSound();
	uint soundid;
	if (hitsound != nullptr) {
		soundid = hitsound->GetFormID();
	}
	// thar be some bullshite of the highest order here
	// MagicItem->GetSpellType?? i think??
	if (soundid != 0 && pTarget != nullptr) {
		if (PersistentSound.IsValid()) {
			PersistentSound.Stop();
			PersistentSound.Release();
		}
	}
}

ActiveEffect::~ActiveEffect() {
	if (pHitEffects) {
	}
	delete pHitEffects;
	if (PersistentSound.IsValid()) {
		PersistentSound.Stop();
		PersistentSound.Release();
	}
}

void ActiveEffect::Finalize() {
	if (!IsFlagSet(HAS_CONDITIONS) && GetDisplacementSpell() == nullptr)
		return;
	EvaluateConditions(0.0f, true);
}

void ActiveEffect::Dispel(bool abNow) {
	bDone = true;
	SetFlag(WAS_DISPELED);
	if (abNow) {
		UpdateEffect(0.0f);
	}
}
