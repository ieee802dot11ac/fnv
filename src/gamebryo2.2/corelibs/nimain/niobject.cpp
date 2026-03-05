#include "niobject.h"
#include "gamebryo2.2/corelibs/nimain/nitarray.h"
#include "gamebryo2.2/corelibs/nimain/niviewerstrings.h"
#include "macros.h"
#include <cstring>
#include "nistream.h"
#include "nicloningprocess.h"

NiObject::NiObject() {}

NiObject::~NiObject() {}

NiObject *NiObject::Clone(void) {
    NiCloningProcess ncp(0x101);
    NiObject *o = CreateClone(ncp);
    ProcessClone(ncp);
    return o;
}

NiObject *NiObject::Clone(NiCloningProcess &kCloning) {
    NiObject *o = CreateClone(kCloning);
    ProcessClone(kCloning);
    return o;
}

void NiObject::CreateDeepCopy(NiPointer<NiObject> &aspObject) {
    NiStream temp_stream;
    temp_stream.InsertObject(this);
    char *buf;
    int i = 0;
    temp_stream.Save(buf, i);
    temp_stream.Load(buf, i);

    NiPointer<NiObject> o = nullptr;
    // some bullshit with temp_stream.m_kTopObjects
    aspObject = o;
}

void NiObject::LoadBinary(NiStream &stream) {
    if (stream.GetFileVersion() >= 0x5000006 && stream.GetFileVersion() < 0xA000072) {
        uint id;
        NiStreamLoadBinary(stream, id);
        SetGroup(stream.GetGroupFromID(id));
    }
}

bool NiObject::RegisterStreamables(NiStream &stream) {
    return stream.RegisterSaveObject(this);
}

const NiRTTI *NiObject::GetStreamableRTTI() const { return GetRTTI(); }

bool NiObject::IsEqual(NiObject *other) {
    if (other == nullptr) {
        return false;
    }
    const char *their_name = other->GetRTTI()->GetName();
    const char *my_name = GetRTTI()->GetName();
    if (std::strcmp(my_name, their_name)) {
        return false;
    }
    return true;
}

void NiObject::GetViewerStrings(NiTPrimitiveArray<char *> *pStrings) {
    ADDSTACK(0x10)
    NiAddViewerString(&ms_RTTI, pStrings);
    NiAddViewerString("this", (void *)this, pStrings);
    uint temp = m_uiRefCount; // why...?
    NiAddViewerString("m_uiRefCount", temp, pStrings);
}
