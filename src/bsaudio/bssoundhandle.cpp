#include "bssoundhandle.h"
#include "bsaudio/bsaudio.h"
#include "bsaudio/bsaudiomanager.h"

bool BSSoundHandle::Play(bool abLoopPlayback) {
    if (iSoundID == -1) {
        return false;
    }
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::QInstance().Play(iSoundID, abLoopPlayback);
}

bool BSSoundHandle::PlayAfter(uint aiDelay, int aiPlayFlags) {
    if (iSoundID == -1) {
        return 0;
    }
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::QInstance().PlayAfter(iSoundID, aiDelay, aiPlayFlags);
}

bool BSSoundHandle::Pause() {
    if (iSoundID == -1) {
        return 0;
    }
    eState = ASSUMED_STATE_PAUSED;
    return BSAudioManager::QInstance().Pause(iSoundID);
}

bool BSSoundHandle::Stop() {
    if (iSoundID == -1) {
        return 0;
    }
    eState = ASSUMED_STATE_STOPPED;
    return BSAudioManager::QInstance().Stop(iSoundID);
}

bool BSSoundHandle::IsPlaying() {
    if (iSoundID == -1) {
        return false;
    }
    if (bAssumeSuccess) {
        return eState == ASSUMED_STATE_PLAYING;
    } else
        return BSAudioManager::QInstance().IsPlaying(iSoundID);
}

int BSSoundHandle::GetSoundType() {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().GetSoundType(iSoundID);
}

bool BSSoundHandle::SetStaticAttenuation(u16 aiStaticAttenutation) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetStaticAttenuation(
        iSoundID, aiStaticAttenutation
    );
}

bool BSSoundHandle::SetVolume(float afNewVolume) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetVolume(iSoundID, afNewVolume);
}

float BSSoundHandle::GetVolume() {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().GetVolume(iSoundID);
}

bool BSSoundHandle::SetFrequency(float afNewFrequency) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetFrequency(iSoundID, afNewFrequency);
}

bool BSSoundHandle::SetModFrequency(float afNewFrequency) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetModFrequency(iSoundID, afNewFrequency);
}

bool BSSoundHandle::SetFrequencyVariance(u8 aiFreqVariance) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetFrequencyVariance(iSoundID, aiFreqVariance);
}

bool BSSoundHandle::SetBalance(int aiNewBalance) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetBalance(iSoundID, aiNewBalance);
}

int BSSoundHandle::GetDuration() {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().GetDuration(iSoundID);
}

bool BSSoundHandle::SetPosition(float afX, float afY, float afZ) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetPosition(iSoundID, afX, afY, afZ);
}

bool BSSoundHandle::SetBeamEnd(float afX, float afY, float afZ) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetBeamEnd(iSoundID, afX, afY, afZ);
}

void BSSoundHandle::SetMinMax(float afMin, float afMax) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetMinMax(iSoundID, afMin, afMax);
    }
}

void BSSoundHandle::SetAttenuationCurve(
    u16 aiPt1, u16 aiPt2, u16 aiPt3, u16 aiPt4, u16 aiPt5
) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetAttenuationCurve(
            iSoundID, aiPt1, aiPt2, aiPt3, aiPt4, aiPt5
        );
    }
}

void BSSoundHandle::SetReverbAttenuation(u16 aiReverbAtt) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetReverbAttenuation(iSoundID, aiReverbAtt);
    }
}

bool BSSoundHandle::SetOrientation(float afX, float afY, float afZ) {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().SetOrientation(iSoundID, afX, afY, afZ);
}

bool BSSoundHandle::IsValid() {
    if (iSoundID == -1) {
        return 0;
    }
    return BSAudioManager::QInstance().IsValid(iSoundID);
}

bool BSSoundHandle::Release() {
    if (iSoundID == -1) {
        return 0;
    }
    bool b = BSAudioManager::QInstance().Release(iSoundID);
    if (b) {
        iSoundID = -1;
    }
    return b;
}

bool BSSoundHandle::FadeInPlay(uint aiMilliseconds) {
    if (iSoundID == -1) {
        return 0;
    }
    eState = ASSUMED_STATE_PLAYING;
    BSAudioManager::QInstance().FadeInPlay(iSoundID, aiMilliseconds);
    return true;
}

bool BSSoundHandle::FadeOutAndRelease(uint aiMilliseconds) {
    if (iSoundID == -1) {
        return 0;
    }
    BSAudioManager::QInstance().FadeOut(iSoundID, aiMilliseconds, 38);
    iSoundID = -1;
    return true;
}

bool BSSoundHandle::FadeOut(uint aiMilliseconds) {
    if (iSoundID == -1) {
        return 0;
    }
    eState = ASSUMED_STATE_STOPPED;
    BSAudioManager::QInstance().FadeOut(iSoundID, aiMilliseconds, 0);
    return true;
}

void BSSoundHandle::SetTimeConstraints(unsigned char aiStart, unsigned char aiStop) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetTimeConstraints(iSoundID, aiStart, aiStop);
    }
}

void BSSoundHandle::SetCompletionCallback(
    void (*apfnCallback)(void *, bool), void *apContext
) {
    if (!BSAudio::QInstance().IsAudioEnabled() && apfnCallback != nullptr) {
        apfnCallback(apContext, false);
    }
    if (iSoundID != -1) {
        BSAudioManager::QInstance().SetCompletionCallback(
            iSoundID, apfnCallback, apContext
        );
    }
}

void BSSoundHandle::SetPlayCallback(void (*apfnCallback)(void *, int), void *apContext) {
    if (!BSAudio::QInstance().IsAudioEnabled() && apfnCallback != nullptr) {
        apfnCallback(apContext, 5000);
    }
    if (iSoundID != -1) {
        BSAudioManager::QInstance().SetPlayCallback(iSoundID, apfnCallback, apContext);
    }
}

void BSSoundHandle::SetObjectToFollow(NiAVObject *apObj) {
    if (iSoundID == -1 || apObj == nullptr) {
    } else {
        if (pfnAddMovingSoundCallback) {
            pfnAddMovingSoundCallback(apObj);
        }
        BSAudioManager::QInstance().SetObjectToFollow(iSoundID, apObj);
    }
}

void BSSoundHandle::Seek(uint aiMilliseconds) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().Seek(iSoundID, aiMilliseconds);
    }
}

void BSSoundHandle::SetFollowsListener(bool abFollowsListener) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetAtListener(iSoundID, abFollowsListener);
    }
}

void BSSoundHandle::SetSynchStartTime(uint aiStartTime) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetSynchStartTime(iSoundID, aiStartTime);
    }
}

void BSSoundHandle::ClearSynchStartTime() {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().ClearSynchStartTime(iSoundID);
    }
}

void BSSoundHandle::SetPriority(uint aiPriority) {
    if (iSoundID == -1) {
    } else {
        BSAudioManager::QInstance().SetPriority(iSoundID, aiPriority);
    }
}
