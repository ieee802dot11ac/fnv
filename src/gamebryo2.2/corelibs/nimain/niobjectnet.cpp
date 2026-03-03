#include "niobjectnet.h"
#include "macros.h"
#include "niextradata.h"
#include "niobject.h"
#include "nitimecontroller.h"
#include "nistream.h"
#include "nicloningprocess.h"

NiObjectNET::NiObjectNET(void) : m_spControllers(nullptr) {}

NiObjectNET::~NiObjectNET() { RemoveAllExtraData(); }

void NiObjectNET::CopyMembers(NiObjectNET *pkDest, NiCloningProcess &kCloning) {
    NiObject::CopyMembers(pkDest, kCloning);
    if (kCloning.m_eCopyType == COPY_EXACT) {
        pkDest->SetName(m_kName);
    }
}

void NiObjectNET::ProcessClone(NiCloningProcess &kCloning) {
    NiObject::ProcessClone(kCloning);
    for (u16 i = 0; i < m_usExtraDataSize; i++) {
        NiExtraData *ned = m_ppkExtra[i];
        if (ned)
            ned->ProcessClone(kCloning);
    }
    if (m_spControllers) {
        m_spControllers->ProcessClone(kCloning);
    }
}

void NiObjectNET::DeleteExtraData(unsigned short usExtraDataIndex) {}

bool NiObjectNET::InsertExtraData(NiExtraData *pkExtra) { return false; }

bool NiObjectNET::SetExtraDataSize(unsigned short usSize) { return false; }

bool NiObjectNET::AddExtraData(NiFixedString const &kKey, NiExtraData *pkExtra) {
    return false;
}

bool NiObjectNET::AddExtraData(NiExtraData *pkExtra) { return false; }

NiExtraData *NiObjectNET::GetExtraData(NiFixedString const &kKey) const {
    return nullptr;
}

bool NiObjectNET::RemoveExtraData(NiFixedString const &kKey) { return false; }

bool NiObjectNET::RemoveExtraDataAt(unsigned short usExtraDataIndex) { return false; }

void NiObjectNET::RemoveAllExtraData() {}

void NiObjectNET::PrependController(NiTimeController *pkControl) {
    if (pkControl != nullptr) {
        NiTimeController *saved = m_spControllers;
        pkControl->SetNext(saved);
        m_spControllers = pkControl;
    }
    ADDSTACK(0x10)
}

void NiObjectNET::SetControllers(NiTimeController *pkControl) {
    m_spControllers = pkControl;
    ADDSTACK(0x10)
}

void NiObjectNET::RemoveController(NiTimeController *pkControl) {}

void NiObjectNET::RemoveAllControllers() { m_spControllers = nullptr; }

NiTimeController *NiObjectNET::GetController(NiRTTI const *pkRTTI) const {
    for (NiTimeController *timectrl = m_spControllers; timectrl != nullptr;
         timectrl = timectrl->GetNext()) {
        const NiRTTI *timetype = timectrl->GetRTTI();
        bool return_this;
        while (timetype != nullptr) {
            if (timetype == pkRTTI) {
                return_this = true;
                goto getout;
            } else {
                timetype = timetype->GetBaseRTTI();
            }
        }
        return_this = false;
    getout:
        if (return_this)
            return timectrl;
    }
    return nullptr;
}

void NiObjectNET::LoadBinary(NiStream &kStream) {
    NiObject::LoadBinary(kStream);
    if (kStream.GetFileVersion() < VERSION(20, 1, 0, 1)) {
        kStream.LoadCStringAsFixedString(m_kName);
    } else {
        kStream.LoadFixedString(m_kName);
    }
    if (kStream.GetFileVersion() < VERSION(5, 0, 0, 11)) {
        kStream.ReadLinkID();
    } else {
        kStream.ReadMultipleLinkIDs();
    }
    kStream.ReadLinkID();
}

void NiObjectNET::LinkObject(NiStream &kStream) {}

bool NiObjectNET::RegisterStreamables(NiStream &kStream) {
    if (!NiObject::RegisterStreamables(kStream)) {
        return false;
    } else if (!kStream.RegisterFixedString(m_kName)) {
        return false;
    } else {
        for (u16 i = 0; i < m_usExtraDataSize; i++) {
            NiExtraData *ptr = m_ppkExtra[i];
            if (ptr && ptr->IsStreamable())
                ptr->RegisterStreamables(kStream);
        }
        if (m_spControllers)
            m_spControllers->RegisterStreamables(kStream);
        return true;
    }
}

void NiObjectNET::SaveBinary(NiStream &kStream) {}

void NiObjectNET::PostLinkObject(NiStream &kStream) {}

bool NiObjectNET::IsEqual(NiObject *pkObject) {
    if (!NiObject::IsEqual(pkObject)) {
        return false;
    } else {
        ;
        ;
    }
}

const NiRTTI *NiObjectNET::GetRTTI() const { return &ms_RTTI; }
