#include "NiExtraData.h"
#include "nimain/NiFixedString.h"
#include "nimain/NiObject.h"
#include "nimain/NiViewerStrings.h"
#include "nimain/nicloningprocess.h"
#include "nimain/nistream.h"

MAKERTTI(NiExtraData, NiObject)

NiExtraData::NiExtraData() {}

NiExtraData::NiExtraData(const NiFixedString& kName) { SetName(kName); }

NiExtraData::~NiExtraData() {}

void NiExtraData::SetName(const NiFixedString& kName) {
	ADDSTACK(0x10)
	m_kName = kName;
}

void NiExtraData::ClearName() { m_kName.Init(); }

void NiExtraData::CopyMembers(NiExtraData* pDest, NiCloningProcess& kCloning) {
	NiObject::CopyMembers(pDest, kCloning);
	pDest->SetName(m_kName);
}

NiObject* NiExtraData::CreateObject() {
	NiObject* obj = new ("D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2."
						 "2\\CoreLibs\\NiMain\\NiExtraData.cpp",
						 89, __FUNCTION__) NiExtraData;
	return obj;
}

bool NiExtraData::RegisterStreamables(NiStream& kStream) {
	if (NiObject::RegisterStreamables(kStream) == false) {
		return false;
	}
	if (kStream.RegisterFixedString(m_kName) == false) {
		return false;
	}
	return true;
}

void NiExtraData::SaveBinary(NiStream& kStream) {
	NiObject::SaveBinary(kStream);
	kStream.SaveFixedString(m_kName);
}

bool NiExtraData::IsEqual(NiObject* pkObject) {
	if (!NiObject::IsEqual(pkObject)) {
		return false;
	}
	NiExtraData* other = static_cast<NiExtraData*>(pkObject);
	if (m_kName != other->m_kName) {
		return false;
	}
	return true;
}

void NiExtraData::GetViewerStrings(NiTPrimitiveArray<char*>* pStrings) {
	NiAddViewerString(&ms_RTTI, pStrings);
	NiAddViewerString("m_pcName", GetName(), pStrings);
}
