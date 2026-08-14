#include "TESWeightForm.h"

void TESWeightForm::InitializeDataComponent() { fWeight = 0.0f; }

void TESWeightForm::CopyComponent(BaseFormComponent* apCopyFC) {
	TESWeightForm* apCopyWF = dynamic_cast<TESWeightForm*>(apCopyFC);
	if (apCopyWF) {
		fWeight = apCopyWF->fWeight;
	}
}

bool TESWeightForm::CompareComponent(BaseFormComponent* apCompareFC) {
	TESWeightForm* apCompareWF = dynamic_cast<TESWeightForm*>(apCompareFC);
	if (apCompareWF == nullptr) {
		return true;
	}
	bool b;
	b = fWeight != apCompareWF->fWeight ? true : false;
	return b;
}

float TESWeightForm::GetFormWeight(TESForm* apForm, bool abIsHardcore) {
	if (apForm != nullptr) {
		apForm->GetFormType();
	}
	return -1.0f;
}

TESWeightForm::TESWeightForm() { fWeight = 0.0f; }

TESWeightForm::~TESWeightForm() {}
