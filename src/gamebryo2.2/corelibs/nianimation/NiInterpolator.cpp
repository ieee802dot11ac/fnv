#include "nianimation/NiInterpolator.h"
#include "nimain/NiObject.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiRTTI.h"
#include "nimain/nicloningprocess.h"
#include "nimain/NiViewerStrings.h"

const NiPoint3
    NiInterpolator::INVALID_POINT3(-3.4028235e38, -3.4028235e38, -3.4028235e38);
const u8 NiInterpolator::INVALID_BOOL = 2;
const float NiInterpolator::INVALID_FLOAT = -3.4028235e38;

MAKERTTI(NiInterpolator, NiObject)

NiInterpolator::NiInterpolator() { m_fLastTime = -NI_INFINITY; }

NiInterpolator::~NiInterpolator() {}

bool NiInterpolator::Update(float fTime, NiObjectNET *pkInterpTarget, NiPoint3 &) {
    return 0;
}

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
