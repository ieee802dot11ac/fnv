#pragma once

#include "fallout_shared/BGSClipRoundsForm.h"

void BGSClipRoundsForm::InitializeDataComponent() { cClipRounds = 12; }

void BGSClipRoundsForm::CopyComponent(BaseFormComponent* apCopyFC) {
	BGSClipRoundsForm* apCopyClip = dynamic_cast<BGSClipRoundsForm*>(apCopyFC);
	if (apCopyClip != nullptr) {
		cClipRounds = apCopyClip->cClipRounds;
	}
}

bool BGSClipRoundsForm::CompareComponent(BaseFormComponent* apCompFC) {
	BGSClipRoundsForm* apCompClip = dynamic_cast<BGSClipRoundsForm*>(apCompFC);
	if (apCompClip == nullptr)
		return true;
	if (cClipRounds != apCompClip->cClipRounds)
		return true;
	return false;
}

BGSClipRoundsForm::BGSClipRoundsForm() { InitializeDataComponent(); }

BGSClipRoundsForm::~BGSClipRoundsForm() {}
