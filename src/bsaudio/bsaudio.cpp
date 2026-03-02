#include "bsaudio.h"
#include "bsaudio/bsaudiomanager.h"
#include "bsaudio/bssoundhandle.h"
#include "bscore/memorycontexttracker.h"
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"

BSAudio::BSAudio() {}

BSAudio::~BSAudio() {}

void BSAudio::Init(void *pHandle) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        79
    );
    ;
}

void BSAudio::Shutdown() {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        99
    );
    if (IsAudioEnabled()) {
        if (bMultiThread) {
            BSAudioManager::QInstance().StopAudioThread();
        }
        bInitialized = false;
        BSAudioManager::QInstance().Shutdown();
    }
}

void BSAudio::SetMultiThreaded(bool abUseMultipleThreads) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        118
    );
    if (!IsAudioEnabled()) {
        return;
    }
    if (abUseMultipleThreads && !bMultiThread) {
        BSAudioManager::QInstance().StartAudioThread();
    } else if (!abUseMultipleThreads && bMultiThread) {
        BSAudioManager::QInstance().SuspendAudioThread();
    }
    bMultiThread = abUseMultipleThreads;
}

BSSoundHandle BSAudio::GetSoundHandleByNumericID(uint aiFormID, uint aiTypeFlags) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        152
    );
    return BSAudioManager::QInstance().GetSoundHandleByNumericID(aiFormID, aiTypeFlags);
}

BSSoundHandle BSAudio::GetSoundHandleByFilename(
    const char *apFilename, uint aiTypeFlags, void *apSettingsContext
) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        162
    );
    return BSAudioManager::QInstance().GetSoundHandleByFilename(
        apFilename, aiTypeFlags, apSettingsContext
    );
}

BSSoundHandle BSAudio::GetSoundHandleByName(const char *apSoundName, uint aiTypeFlags) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        172
    );
    return BSAudioManager::QInstance().GetSoundHandleByName(apSoundName, aiTypeFlags);
}

BSSoundHandle
BSAudio::SpawnSoundReference(uint aiFormID, uint aiTypeFlags, NiPoint3 aLoc, uint aiID) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        184
    );
    BSSoundHandle h =
        BSAudioManager::QInstance().GetSoundHandleByNumericID(aiFormID, aiTypeFlags);
    h.SetPosition(aLoc.x, aLoc.y, aLoc.z);
    h.Play(true);
    return h;
}

void BSAudio::Update(bool abPlayGameWorldSounds) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        193
    );
    return BSAudioManager::QInstance().Update(abPlayGameWorldSounds);
}

void BSAudio::SetConditions(float afCurrentGamehour, uint aiWeatherConditions) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        193
    );
    return BSAudioManager::QInstance().SetConditions(
        afCurrentGamehour, aiWeatherConditions
    );
}

void BSAudio::PositionListener(NiPoint3 aNewPosition) {
    BSAudioManager::QInstance().PositionListener(aNewPosition);
}

void BSAudio::SetListenerUnderwater(bool abIsUnderwater) {
    BSAudioManager::QInstance().SetListenerUnderwater(abIsUnderwater);
}

void BSAudio::SetEnvironment(uint aiEnviroType) {
    // pListener->SetEnvironment(aiEnviroType);
}

float BSAudio::GetMasterVolume() { return BSAudioManager::QInstance().GetMasterVolume(); }

float BSAudio::GetFootVolume() { return BSAudioManager::QInstance().GetFootVolume(); }

float BSAudio::GetVoiceVolume() { return BSAudioManager::QInstance().GetVoiceVolume(); }

float BSAudio::GetEffectVolume() { return BSAudioManager::QInstance().GetEffectVolume(); }

float BSAudio::GetMusicVolume() { return BSAudioManager::QInstance().GetMusicVolume(); }

float BSAudio::GetRadioVolume() { return BSAudioManager::QInstance().GetRadioVolume(); }

void BSAudio::SetMasterVolume(float afNewVol) {
    BSAudioManager::QInstance().SetMasterVolume(afNewVol);
}

void BSAudio::SetFootVolume(float afNewVol) {
    BSAudioManager::QInstance().SetFootVolume(afNewVol);
}

void BSAudio::SetVoiceVolume(float afNewVol) {
    BSAudioManager::QInstance().SetVoiceVolume(afNewVol);
}

void BSAudio::SetEffectVolume(float afNewVol) {
    BSAudioManager::QInstance().SetEffectVolume(afNewVol);
}

void BSAudio::SetMusicVolume(float afNewVol) {
    BSAudioManager::QInstance().SetMusicVolume(afNewVol);
}

void BSAudio::SetRadioVolume(float afNewVol) {
    BSAudioManager::QInstance().SetRadioVolume(afNewVol);
}

void BSAudio::VolumeChanged() { BSAudioManager::QInstance().VolumeChanged(); }

bool BSAudio::IsListenerUnderwater() {
    return BSAudioManager::QInstance().IsListenerUnderwater();
}

float BSAudio::GetMasterSecondaryVolume() {
    return BSAudioManager::QInstance().GetMasterSecondaryVolume();
}

float BSAudio::GetFootSecondaryVolume() {
    return BSAudioManager::QInstance().GetFootSecondaryVolume();
}

float BSAudio::GetVoiceSecondaryVolume() {
    return BSAudioManager::QInstance().GetVoiceSecondaryVolume();
}

float BSAudio::GetEffectSecondaryVolume() {
    return BSAudioManager::QInstance().GetEffectSecondaryVolume();
}

float BSAudio::GetMusicSecondaryVolume() {
    return BSAudioManager::QInstance().GetMusicSecondaryVolume();
}

float BSAudio::GetRadioSecondaryVolume() {
    return BSAudioManager::QInstance().GetRadioSecondaryVolume();
}

void BSAudio::SetMasterSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetMasterSecondaryVolume(afNewVol);
}

void BSAudio::SetFootSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetFootSecondaryVolume(afNewVol);
}

void BSAudio::SetVoiceSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetVoiceSecondaryVolume(afNewVol);
}

void BSAudio::SetEffectSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetEffectSecondaryVolume(afNewVol);
}

void BSAudio::SetMusicSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetMusicSecondaryVolume(afNewVol);
}

void BSAudio::SetRadioSecondaryVolume(float afNewVol) {
    BSAudioManager::QInstance().SetRadioSecondaryVolume(afNewVol);
}

void BSAudio::ClearSecondaryVolumes() {
    BSAudioManager::QInstance().ClearSecondaryVolumes();
}

void BSAudio::Precache(char *apSoundName, uint aiFlags) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        294
    );
    BSAudioManager::QInstance().Precache(apSoundName, aiFlags);
}

void BSAudio::Precache(uint aiFormID, uint aiFlags) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        302
    );
    BSAudioManager::QInstance().Precache(aiFormID, aiFlags);
}

void BSAudio::Precache(
    char const *apFilenameToCache, uint aiFlags, void *apSettingsContext
) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        310
    );
    BSAudioManager::QInstance().Precache(apFilenameToCache, aiFlags, apSettingsContext);
}

void BSAudio::SetAudioCacheSizeInK(uint aiNewSize) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        318
    );
    BSAudioManager::QInstance().SetAudioCacheSizeInK(aiNewSize);
}

uint BSAudio::GetAudioCacheSizeInK() {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        325
    );
    return BSAudioManager::QInstance().GetAudioCacheSizeInK();
}

void BSAudio::SetCacheEnabled(bool abEnableCache) {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        332
    );
    BSAudioManager::QInstance().SetCacheEnabled(abEnableCache);
}

bool BSAudio::GetCacheEnabled() {
    AutoMemContext amc(
        MEM_CONTEXT_AUDIO,
        true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\BSAudio\\BSAudio.cpp",
        339
    );
    return BSAudioManager::QInstance().GetCacheEnabled();
}

void BSAudio::MuteType(uint aiType, uint aiFadeTimeMS, uint aiMillibels) {
    BSAudioManager::QInstance().MuteAllOfType(aiType, aiFadeTimeMS, aiMillibels);
}

void BSAudio::UnMuteType(uint aiType, uint aiFadeTimeMS) {
    BSAudioManager::QInstance().UnMuteAllOfType(aiType, aiFadeTimeMS);
}

void BSAudio::KillAllOfType(uint aiType, uint aiFadeTimeMS) {
    BSAudioManager::QInstance().KillAllOfType(aiType, aiFadeTimeMS);
}

void BSAudio::PauseAllOfType(uint aiType, bool abExactMatch) {
    BSAudioManager::QInstance().PauseAllOfType(aiType, abExactMatch);
}

void BSAudio::UnPauseAllOfType(uint aiType, bool abExactMatch) {
    BSAudioManager::QInstance().UnPauseAllOfType(aiType, abExactMatch);
}

void BSAudio::StopMovingSounds(NiAVObject *apObj, float afFadeSeconds, uint aiFlags) {
    BSAudioManager::QInstance().StopMovingSounds(apObj, afFadeSeconds, aiFlags);
}

void BSAudio::EnterDialogue() { BSAudioManager::QInstance(); }

void BSAudio::ExitDialogue() { BSAudioManager::QInstance(); }

void BSAudio::PauseSynchTimer() {
    if (pfnSynchPausedCallback) {
        pfnSynchPausedCallback();
    }
    SynchTimer.Pause();
}

void BSAudio::UnPauseSynchTimer() {
    if (pfnSynchUnPausedCallback) {
        pfnSynchUnPausedCallback();
    }
    SynchTimer.UnPause();
}

void BSAudio::EndAllSoundsOfType(uint aiType) {}
