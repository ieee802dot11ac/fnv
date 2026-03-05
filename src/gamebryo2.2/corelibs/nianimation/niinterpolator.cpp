#include "nianimation/niinterpolator.h"
#include "nimain/nicloningprocess.h"
#include "nimain/niobject.h"
#include "nimain/niviewerstrings.h"

const float NiInterpolator::INVALID_FLOAT = -3.4028235e38;
const float fuckyou = 3.4028235e38;

NiInterpolator::NiInterpolator() { m_fLastTime = -fuckyou; }

NiInterpolator::~NiInterpolator() {}

// bool NiInterpolator::Update(float, NiObjectNET*, NiQuatTransform&) {
// 	return 0;
// }

// bool NiInterpolator::Update(float, NiObjectNET*, NiColorA&) {
// 	return 0;
// }

bool NiInterpolator::Update(float fTime, NiObjectNET *pkInterpTarget, NiPoint3 &) {
    return 0;
}

// bool NiInterpolator::Update(float, NiObjectNET*, NiQuaternion&) {
// 	return 0;
// }

bool NiInterpolator::Update(float, NiObjectNET *, float &) { return 0; }

bool NiInterpolator::Update(float, NiObjectNET *, bool &) { return 0; }

void NiInterpolator::GetActiveTimeRange(float &fBeginKeyTime, float &fEndKeyTime) const {
    fBeginKeyTime = 0.0f;
    fEndKeyTime = 0.0f;
}

void NiInterpolator::GuaranteeTimeRange(float fStartTime, float fEndTime) {}

NiInterpolator *
NiInterpolator::GetSequenceInterpolator(float fStartTime, float fEndTime) {
    NiInterpolator *interp = static_cast<NiInterpolator *>(Clone());
    interp->SetUpDependencies();
    return interp;
}

void NiInterpolator::CopyMembers(NiInterpolator *pkDest, NiCloningProcess &kCloning) {
    NiObject::CopyMembers(pkDest, kCloning);
}

void NiInterpolator::LoadBinary(NiStream &kStream) { NiObject::LoadBinary(kStream); }

bool NiInterpolator::IsEqual(NiObject *pObject) { return NiObject::IsEqual(pObject); }

inline void StackFakematch() { u8 pad[4]; }

void NiInterpolator::GetViewerStrings(NiTPrimitiveArray<char *> *pStrings) {
    NiObject::GetViewerStrings(pStrings);
    NiAddViewerString(&ms_RTTI, pStrings);
    StackFakematch();
}
