#include "TESGlobal.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesfile.h"

TESGlobal::TESGlobal() {
	cType = 0x73;
	SetFormType(GLOB_ID);
	fValue = 0.0f;
}

void TESGlobal::Save() {
	StartForm();
	AddChunk(FNAM_ID, static_cast<u8>(cType));
	AddChunk(FLTV_ID, fValue);
	CloseForm();
}

bool TESGlobal::Load(TESFile* apFile) {
	if (apFile->GetTESForm() != GLOB_ID)
		return false;
	LoadForm(apFile);
	for (CHUNK_ID chunk = apFile->GetTESChunk(); chunk != NO_CHUNK;
		 chunk = apFile->GetTESChunk()) {
		switch (chunk) {
			LOADOBJBOUND
			LOADEDITORID
		case FNAM_ID: {
			apFile->GetChunkData(&cType, sizeof(cType));
		} break;
		case FLTV_ID: {
			apFile->GetChunkData(fValue);
		} break;
		default:
			break;
		}
		if (!apFile->NextChunk())
			break;
	}
	return true;
}

void TESGlobal::Copy(TESForm* apCopy) {
	TESGlobal* apCopy_Global = dynamic_cast<TESGlobal*>(apCopy);
	if (apCopy_Global != nullptr) {
		CopyAllComponents(apCopy);
		cType = apCopy_Global->cType;
		fValue = apCopy_Global->fValue;
	}
}

bool TESGlobal::Compare(TESForm* apCompare) {
	TESGlobal* apComp_Global = dynamic_cast<TESGlobal*>(apCompare);
	if (apComp_Global == nullptr) {
		return true;
	}
	if (CompareAllComponents(apComp_Global)) {
		return true;
	}
	if (cType != apComp_Global->cType)
		return true;
	if (fValue != apComp_Global->fValue)
		return true;

	return false;
}
