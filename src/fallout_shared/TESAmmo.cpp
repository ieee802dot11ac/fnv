#include "TESAmmo.h"
#include "bsmain/Setting.h"
#include "fallout_shared/BGSDestructibleObjectForm.h"
#include "fallout_shared/BGSMessageIcon.h"
#include "fallout_shared/BGSPickupPutdownSounds.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESModelTextureSwap.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/XGameSetting.h"
#include "fallout_shared/enums.h"
#include <cstring>

SETTING(GameSettingCollection, iMaxArrowsInQuiver, 20)

void TESAmmo::SaveGame(uint aiFlags) {
	TESForm::SaveGame(aiFlags);
	TESValueForm::SaveGame(aiFlags);
}

void TESAmmo::LoadGame(uint aiFlags, uint aiCurrentFlags) {
	TESForm::LoadGame(aiFlags, aiCurrentFlags);
	TESValueForm::LoadGame(aiFlags, aiCurrentFlags);
}

void TESAmmo::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer) {
	TESForm::SaveGame(apSaveGameBuffer);
	TESValueForm::SaveGame(apSaveGameBuffer);
}

void TESAmmo::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) {
	TESForm::LoadGame(apLoadGameBuffer);
	TESValueForm::LoadGame(apLoadGameBuffer);
}

void TESAmmo::InitItem() {
	if (GetInitialized())
		return;

	TESScriptableForm::InitItem(this);
	BGSDestructibleObjectForm::InitItem(this);
	TESModelTextureSwap::InitItem(this);
	BGSPickupPutdownSounds::InitItem(this);

	SetInitialized(true);
}

void TESAmmo::Save() {
	TESForm::StartForm();
	TESFullName::Save();
	TESModelTextureSwap::Save(MODL_ID, MODT_ID, MODS_ID);
	TESIcon::Save(ICON_ID);
	BGSMessageIcon::Save(MICO_ID);
	TESScriptableForm::Save();
	BGSDestructibleObjectForm::Save();
	BGSPickupPutdownSounds::Save();
	ENDIAN(data)
	__SaveData(&data, sizeof(data));
	ENDIAN(data)
	ENDIAN(NVdata)
	__SaveData(&NVdata, sizeof(NVdata));
	ENDIAN(NVdata)

	AddChunkArray(ONAM_ID, cDesc, cDesc.ByteLengthWithNull());
	AddChunkArray(CLNM_ID, cAbbrev, cAbbrev.ByteLengthWithNull());

	for (auto* amefs = GetAmmoEffectList(); amefs != nullptr;) {
		auto* amef = amefs->GetItem();
		if (amef == nullptr)
			break;
		amefs = amefs->GetNext();
		AddChunk(RCID_ID, amef->GetFormID());
	}
	CloseForm();
}

void TESAmmo::BuildMenuString(char* astrResult, uint auiResultLen) {}

void TESAmmo::InitializeData() {
	memset(&data, 0, sizeof(data));
	memset(&NVdata, 0, sizeof(NVdata));
	cDesc.Set(nullptr, 0);
	cAbbrev.Set(nullptr, 0);
}

bool TESAmmo::Load(TESFile* apFile) {
	u8 formid = apFile->GetTESForm();
	if (formid != AMMO_ID)
		return false;
	LoadForm(apFile);
	SetInitialized(false);
	for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
		 chunk = apFile->GetTESChunk()) {
		switch (chunk) {
			LOADOBJBOUND
			LOADEDITORID
		case DATA_ID: {
			LoadData(apFile, &data, sizeof(AMMO_EFFECT_DATA));
			if (apFile->GetLittleEndian()) {
				data.Endian();
			}
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

bool TESAmmo::Compare(TESForm* apCompare) {
	TESAmmo* apCompAmmo = dynamic_cast<TESAmmo*>(apCompare);
	if (apCompAmmo == nullptr) {
		return true;
	}
	if (CompareAllComponents(apCompAmmo))
		return true;
	if (memcmp(&data, &apCompAmmo->data, sizeof(data)))
		return true;

	return false;
}

TESAmmo::~TESAmmo() {}

void TESAmmo::Copy(TESForm* apCopy) {
	TESAmmo* apCopyAmmo = dynamic_cast<TESAmmo*>(apCopy);
	if (apCopyAmmo != nullptr) {
		memcpy(&data, &apCopyAmmo->data, sizeof(data));
		memcpy(&NVdata, &apCopyAmmo->NVdata, sizeof(NVdata));
		CopyAllComponents(apCopy);
	}
}

NiAVObject* TESAmmo::Clone3D(TESObjectREFR* pRequester, bool deepCopy) {
	return nullptr;
}

TESAmmo::TESAmmo() {
	SetFormType(AMMO_ID);
	InitializeData();
}
