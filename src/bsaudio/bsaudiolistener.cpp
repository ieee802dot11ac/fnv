#include "bsaudiolistener.h"
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"

NiPoint3 &BSAudioListener::GetPosition() { return ListenerPosition; }

NiPoint3 &BSAudioListener::GetFrontOrientation() { return FrontOrientation; }

NiPoint3 &BSAudioListener::GetTopOrientation() { return TopOrientation; }

void BSAudioListener::SetGain(float afGain) { fGain = afGain; }

void BSAudioListener::SetEnvironmentType(uint aiType) { iEvironmentType = aiType; }

void BSAudioListener::SetRolloffFactor(float afRolloffFactor) {
    fRolloffFactor = afRolloffFactor;
}

void fakematch() { BSAudioListener bal; }
