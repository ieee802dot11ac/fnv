#include "bssoundhandle.h"
#include "bsaudio/bsaudiomanager.h"

bool BSSoundHandle::Play(bool abLoopPlayback) {
    if (iSoundID == -1) {
        return false;
    } else {
        eState = ASSUMED_STATE_PLAYING;
        return BSAudioManager::QInstance().Play(iSoundID, abLoopPlayback);
    }
}

bool BSSoundHandle::PlayAfter(uint aiDelay, int aiPlayFlags) {
    if (iSoundID == -1) {
        return 0;
    } else {
        eState = ASSUMED_STATE_PLAYING;
        return BSAudioManager::QInstance().PlayAfter(iSoundID, aiDelay, aiPlayFlags);
    }
}

bool BSSoundHandle::Pause() {
    if (iSoundID == -1) {
        return 0;
    } else {
        eState = ASSUMED_STATE_PAUSED;
        return BSAudioManager::QInstance().Pause(iSoundID);
    }
}

bool BSSoundHandle::Stop() {
    if (iSoundID == -1) {
        return 0;
    } else {
        eState = ASSUMED_STATE_STOPPED;
        return BSAudioManager::QInstance().Stop(iSoundID);
    }
}

bool BSSoundHandle::IsPlaying() {
    if (iSoundID == -1) {
        return false;
    } else if (bAssumeSuccess) {
        return eState == ASSUMED_STATE_PLAYING;
    } else {
        return BSAudioManager::QInstance().IsPlaying(iSoundID);
    }
}

int BSSoundHandle::GetSoundType() {
    if (iSoundID == -1) {
        return 0;
    } else {
        return BSAudioManager::QInstance().GetSoundType(iSoundID);
    }
}

bool BSSoundHandle::SetStaticAttenuation(u16 aiStaticAttenutation) {
    if (iSoundID == -1) {
        return 0;
    } else {
        return BSAudioManager::QInstance().SetStaticAttenuation(
            iSoundID, aiStaticAttenutation
        );
    }
}

bool BSSoundHandle::SetVolume(float afNewVolume) {
    if (iSoundID == -1) {
        return 0;
    } else {
        return BSAudioManager::QInstance().SetVolume(iSoundID, afNewVolume);
    }
}

float BSSoundHandle::GetVolume() {
    if (iSoundID == -1) {
        return 0;
    } else {
        return BSAudioManager::QInstance().GetVolume(iSoundID);
    }
}
