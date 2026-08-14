#include "TESHair.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/testexture.h"
#include "stdlib.h"

void TESHair::InitializeData() { cFlags = 0; }

void TESHair::Save() {
	StartForm();
	TESFullName::Save();
	TESModel::Save(MODL_ID, MODT_ID);
	TESTexture::Save(ICON_ID);
	TESForm::AddChunk(DATA_ID, static_cast<u8>(cFlags));
	CloseForm();
}

bool TESHair::Load(TESFile* apFile) {
	if (apFile->GetTESForm() != HAIR_ID)
		return false;
	LoadForm(apFile);
	for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
		 chunk = apFile->GetTESChunk()) {
		switch (chunk) {
			LOADOBJBOUND
			LOADEDITORID
		case DATA_ID: {
			apFile->GetChunkData(&cFlags, sizeof(cFlags));
		} break;
		case MODT_ID:
		case MODL_ID: {
			LoadModelChunk(this, apFile);
		} break;
		case ICON_ID: {
			LoadTextureChunk(this, apFile);
		} break;
		case FULL_ID: {
			LoadFullNameChunk(this, apFile);
		} break;
		default:
			break;
		}
		if (!apFile->NextChunk())
			break;
	}
	return true;
}

void TESHair::Copy(TESForm* apCopy) {
	TESHair* apCopy_Hair = dynamic_cast<TESHair*>(apCopy);
	if (apCopy_Hair != nullptr) {
		CopyAllComponents(apCopy);
		cFlags = apCopy_Hair->cFlags;
	}
}

bool TESHair::Compare(TESForm* apCompare) {
	TESHair* apComp_Hair = dynamic_cast<TESHair*>(apCompare);
	if (apComp_Hair == nullptr) {
		return true;
	}
	if (CompareAllComponents(apComp_Hair)) {
		return true;
	}
	if (apComp_Hair->cFlags != cFlags)
		return true;

	return false;
}

bool TESHair::IsPlayable() { return cFlags & BIT(0); }

bool TESHair::CanBeMale() { return ~cFlags & BIT(1); }

bool TESHair::CanBeFemale() { return ~cFlags & BIT(2); }

bool TESHair::CanBeHairForNPC(TESNPC* apNPC) { return true; }

TESHair::~TESHair() {}

TESHair::TESHair() {
	SetFormType(HAIR_ID);
	InitializeData();
}
