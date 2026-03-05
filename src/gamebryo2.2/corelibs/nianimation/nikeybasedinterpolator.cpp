#include "nikeybasedinterpolator.h"
#include "nianimation/nianimationkey.h"
#include "nianimation/niinterpolator.h"
#include "nimain/niviewerstrings.h"

NiKeyBasedInterpolator::NiKeyBasedInterpolator() {}

NiKeyBasedInterpolator::~NiKeyBasedInterpolator() {}

void NiKeyBasedInterpolator::GetActiveTimeRange(
    float &fBeginKeyTime, float &fEndKeyTime
) const {}

NiAnimationKey *NiKeyBasedInterpolator::GetKeyAt(uint uiWhichKey, u16 usChannel) const {
    u8 stride = GetKeyStride(usChannel);
    NiAnimationKey *keys = GetKeyArray(usChannel);
    return (NiAnimationKey *)&(((u8 *)keys)[uiWhichKey * stride]);
}

void NiKeyBasedInterpolator::CopyMembers(
    NiKeyBasedInterpolator *pkDest, NiCloningProcess &kCloning
) {
    NiInterpolator::CopyMembers(pkDest, kCloning);
}

void NiKeyBasedInterpolator::LoadBinary(NiStream &kStream) {
    NiInterpolator::LoadBinary(kStream);
}

bool NiKeyBasedInterpolator::RegisterStreamables(NiStream &kStream) {
    return NiInterpolator::RegisterStreamables(kStream);
}

bool NiKeyBasedInterpolator::IsEqual(NiObject *pObject) {
    return NiInterpolator::IsEqual(pObject);
}

inline void StackFakematch() { u8 pad[4]; }

void NiKeyBasedInterpolator::GetViewerStrings(NiTPrimitiveArray<char *> *pStrings) {
    NiInterpolator::GetViewerStrings(pStrings);
    NiAddViewerString(&ms_RTTI, pStrings);
    StackFakematch();
}
