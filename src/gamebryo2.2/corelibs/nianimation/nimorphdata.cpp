#include "nimorphdata.h"
#include "macros.h"
#include "nimain/nifixedstring.h"
#include "nimain/niobject.h"
#include "nimain/nipoint3.h"
#include "nimain/nistream.h"
#include "nimain/nitarray.h"
#include "nimain/niviewerstrings.h"

NiMorphData::MorphTarget::MorphTarget() {}

NiMorphData::MorphTarget::~MorphTarget() { delete m_aTargetVerts; }

void NiMorphData::MorphTarget::ReplaceTargetVerts(NiPoint3 *aTargetVerts) {
    delete[] m_aTargetVerts;
    m_aTargetVerts = aTargetVerts;
}

void NiMorphData::MorphTarget::LoadBinary(NiStream &kStream, uint uiNumVerts) {
    if (kStream.GetFileVersion() < VERSION(20, 1, 0, 1)) {
        kStream.LoadCStringAsFixedString(m_kName);
    } else {
        kStream.LoadFixedString(m_kName);
    }
}

void NiMorphData::MorphTarget::SaveBinary(NiStream &kStream, unsigned int uiNumVerts) {
    kStream.SaveFixedString(m_kName);
    if (uiNumVerts != 0) {
        const float *verts = reinterpret_cast<const float *>(m_aTargetVerts);
        NiStreamSaveBinary<float>(kStream, verts, uiNumVerts * 3);
    }
}

NiMorphData::NiMorphData() {
    m_uiNumTargets = 0;
    m_uiNumVertsPerTarget = 0;
    m_aMorphTargets = nullptr;
    m_bRelativeTargets = false;
}

NiMorphData::~NiMorphData() { delete[] m_aMorphTargets; }

NiObject *NiMorphData::CreateObject() {
    NiObject *obj = new (
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiAnimation\\NiMorphData.cpp",
        179,
        __FUNCTION__
    ) NiMorphData;
    return obj;
}

void NiMorphData::LoadBinary(NiStream &kStream) {
    NiObject::LoadBinary(kStream);
    ;
}

bool NiMorphData::RegisterStreamables(NiStream &kStream) {
    if (!NiObject::RegisterStreamables(kStream)) {
        return false;
    }
    for (int i = 0; i < m_uiNumTargets; i++) {
        (i < m_uiNumTargets ? &m_aMorphTargets[i] : nullptr)->RegisterStreamables(kStream);
    }
    return true;
}

void NiMorphData::SaveBinary(NiStream &kStream) {
    NiObject::SaveBinary(kStream);
    NiStreamSaveBinary(kStream, m_uiNumTargets);
    NiStreamSaveBinary(kStream, m_uiNumVertsPerTarget);
    u8 rel = m_bRelativeTargets;
    NiStreamSaveBinary(kStream, rel);
    for (int i = 0; i < m_uiNumTargets; i++) {
        m_aMorphTargets[i].SaveBinary(kStream, m_uiNumVertsPerTarget);
    }
}

bool NiMorphData::IsEqual(NiObject *pObject) {
    if (!NiObject::IsEqual(pObject)) {
        return false;
    }
    NiMorphData *other = static_cast<NiMorphData *>(pObject);
    if (m_uiNumTargets != other->m_uiNumTargets
        || m_uiNumVertsPerTarget != other->m_uiNumVertsPerTarget
        || m_bRelativeTargets != other->m_bRelativeTargets) {
        return false;
    }
    for (int i = 0; i < m_uiNumTargets; i++) {
        // no stack space allocated. there are no temps
        // the real question is how is it double-branching
        if (!(i < m_uiNumTargets ? &m_aMorphTargets[i] : nullptr)
                 ->IsEqual(
                     (i < other->m_uiNumTargets ? &other->m_aMorphTargets[i] : nullptr),
                     m_uiNumVertsPerTarget
                 )) {
            return false;
        }
    }
    return true;
}

void NiMorphData::GetViewerStrings(NiTPrimitiveArray<char *> *pStrings) {
    NiObject::GetViewerStrings(pStrings);
    NiAddViewerString(&ms_RTTI, pStrings);
    NiAddViewerString("m_uiNumTargets", m_uiNumTargets, pStrings);
    NiAddViewerString("m_uiNumVertsPerTarget", m_uiNumVertsPerTarget, pStrings);
    char *morphtarget = NiGetViewerString("MorphTarget");
    pStrings->Add(morphtarget);
    for (int i = 0; i < m_uiNumTargets; i++) {
        const NiFixedString &target_name =
            (i < m_uiNumTargets ? &m_aMorphTargets[i] : nullptr)->GetNameNoInline();
        const char *target_name_s = (const char *)target_name;
        NiAddViewerString("m_pcName", target_name_s, pStrings);
    }
    ADDSTACK(0x20)
}
