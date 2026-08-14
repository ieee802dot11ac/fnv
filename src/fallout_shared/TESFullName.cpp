#include "TESFullName.h"
#include "bsmain/messagehandler.h"
#include "stdlib.h"
#include <cstring>

void TESFullName::Save() {
	// if (cFullName.ByteLength() == -1)
	TESForm::AddChunkArray(FULL_ID, cFullName.String(),
						   cFullName.ByteLengthWithNull());
}

bool TESFullName::CompareComponent(BaseFormComponent* apCompareFC) {
	TESFullName* apCompName = dynamic_cast<TESFullName*>(apCompareFC);
	if (apCompName == nullptr)
		return true;
	if (cFullName != apCompName->cFullName)
		return true;
	return false;
}

void TESFullName::LoadFullNameChunk(TESFullName* apFullName, TESFile* apFile) {
	if (apFile == nullptr || apFullName == nullptr)
		return;
	CHUNK_ID id = apFile->GetTESChunk();
	if (id == FULL_ID) {
		uint csize = apFile->GetChunkSize();
		void* buf;
		if (csize != 0) {
			buf = alloca(apFile->GetChunkSize());
			apFile->GetChunkData(buf, 0);
		}
		apFullName->SetFullName(csize != 0 ? static_cast<const char*>(buf)
										   : nullptr);
	}
	char namebuf[260];
	strcpy_s(namebuf, sizeof(namebuf), apFullName->cFullName.String());
	uint namesiz = strlen(namebuf);
	if (namebuf[namesiz - 1] == ' ' && namebuf[0] != ' ') {
		Warning("EXTRA SPACE:  %s has at least one space after it.", namebuf);
	}
}

void TESFullName::CopyComponent(BaseFormComponent* apCopyFC) {
	TESFullName* apCopyName = dynamic_cast<TESFullName*>(apCopyFC);
	if (apCopyName != nullptr) {
		cFullName.Set(apCopyName->GetFullNameString());
	}
}
