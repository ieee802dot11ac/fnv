#include "TESAttributes.h"
#include "fallout/misc/saveload/BGSLoadFormBuffer.h"
#include "fallout/misc/saveload/bgssaveformbuffer.h"
#include "fallout_shared/actorvalue.h"
#include <cstring>

void TESAttributes::InitializeDataComponent() {
	for (int i = 0; i < 7; i++) {
		cAttribute[i] = 5;
	}
}

uint TESAttributes::Save(void* apData) {
	memcpy(apData, cAttribute, 7);
	return 7;
}

// https://decomp.me/scratch/c36Vi
uint TESAttributes::Load(void* apData) {
	memcpy(cAttribute, apData, 7);
	return 7;
}

u8 TESAttributes::GetAttributeValue(ActorValue::Index aeAttribute) const {
	return cAttribute[aeAttribute - ActorValue::ATTRIBUTE_START];
}

void TESAttributes::SetAttributeValue(ActorValue::Index aeAttribute, u8 acValue,
									  bool abMarkChange) {
	cAttribute[aeAttribute - ActorValue::ATTRIBUTE_START] = acValue;
	if (abMarkChange) {
		TESForm* form = dynamic_cast<TESForm*>(this);
		if (form)
			form->AddChange(4);
	}
}

void TESAttributes::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer) {
	if (apSaveGameBuffer->GetChangeFlags().CheckFlags(BIT(2)))
		apSaveGameBuffer->SaveData(cAttribute, 7, 0);
}

void TESAttributes::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) {
	if (apLoadGameBuffer->GetChangeFlags().CheckFlags(BIT(2)))
		apLoadGameBuffer->LoadData(cAttribute, 7);
}

TESAttributes::TESAttributes() { InitializeDataComponent(); }

TESAttributes::~TESAttributes() {}

void TESAttributes::CopyComponent(BaseFormComponent* apCopyFC) {
	TESAttributes* apCopyAttrs = dynamic_cast<TESAttributes*>(apCopyFC);
	if (apCopyAttrs != nullptr) {
		for (int i = 0; i < 7; i++) {
			cAttribute[i] = apCopyAttrs->GetAttributeValue(
				ActorValue::ToActorValue(ActorValue::ATTRIBUTE, i));
		}
	}
}

bool TESAttributes::CompareComponent(BaseFormComponent* apCompFC) {
	TESAttributes* apCompAttrs = dynamic_cast<TESAttributes*>(apCompFC);
	if (apCompAttrs == nullptr)
		return true;
	for (int i = 0; i < 7; i++) {
		if (cAttribute[i] !=
			apCompAttrs->GetAttributeValue(
				ActorValue::ToActorValue(ActorValue::ATTRIBUTE, i)))
			return true;
	}
	return false;
}
