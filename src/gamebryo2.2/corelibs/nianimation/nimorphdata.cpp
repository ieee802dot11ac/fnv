#include "nimorphdata.h"
#include "nimain/nitarray.h"
#include "nimain/niviewerstrings.h"

NiMorphData::MorphTarget::MorphTarget() {}

NiMorphData::MorphTarget::~MorphTarget() { delete m_aTargetVerts; }

NiMorphData::NiMorphData() {
    m_uiNumTargets = 0;
    m_uiNumVertsPerTarget = 0;
    m_aMorphTargets = nullptr;
    m_bRelativeTargets = false;
}

NiMorphData::~NiMorphData() { delete[] m_aMorphTargets; }

bool NiMorphData::RegisterStreamables(NiStream &kStream) {
    if (!NiObject::RegisterStreamables(kStream)) {
        return false;
    }
    for (int i = 0; i < m_uiNumTargets; i++) {
        m_aMorphTargets[i].RegisterStreamables(kStream);
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
}
