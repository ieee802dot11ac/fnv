#include "TESHealthForm.h"
// #include "fallout_shared/TESObjectWEAP.h"

void TESHealthForm::InitializeDataComponent() { iHealth = 100; }

void TESHealthForm::CopyComponent(BaseFormComponent* apCopyFC) {
	TESHealthForm* apCopyHealth = dynamic_cast<TESHealthForm*>(apCopyFC);
	if (apCopyHealth != nullptr) {
		iHealth = apCopyHealth->iHealth;
	}
}

bool TESHealthForm::CompareComponent(BaseFormComponent* apCompareFC) {
	TESHealthForm* apCompHealth = dynamic_cast<TESHealthForm*>(apCompareFC);
	if (apCompHealth == nullptr)
		return true;
	if (iHealth != apCompHealth->iHealth)
		return true;
	return false;
}

TESHealthForm* TESHealthForm::GetFormAsHealthForm(TESForm* apForm) {
	if (apForm == nullptr)
		return 0;
	ENUM_FORM_ID formtype = apForm->GetFormType();
	switch (formtype) {
	// case WEAP_ID: return static_cast<TESObjectWEAP*>(apForm);
	// case ARMO_ID: return static_cast<TESObjectARMO*>(apForm);
	// case NPC__ID:
	// case CREA_ID: return static_cast<TESNPC*>(apForm);
	default:
		return 0;
	}
	return nullptr;
}

uint TESHealthForm::GetFormHealth(TESForm* apForm) {
	if (apForm == nullptr)
		return 0;
	ENUM_FORM_ID formtype = apForm->GetFormType();
	switch (formtype) {
	// case WEAP_ID: return
	// static_cast<TESObjectWEAP*>(apForm)->GetFormHealth(); case ARMO_ID:
	// return static_cast<TESObjectARMO*>(apForm)->GetFormHealth(); case
	// NPC__ID: case CREA_ID: return
	// static_cast<TESNPC*>(apForm)->GetFormHealth();
	default:
		return 0;
	}
	return 0;
}

TESHealthForm::TESHealthForm() { InitializeDataComponent(); }

TESHealthForm::~TESHealthForm() {}
