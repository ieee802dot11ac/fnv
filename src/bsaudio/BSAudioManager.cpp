#include "bsaudiomanager.h"
#include "bsaudio/bsaudio.h"

BSAudioManager &BSAudioManager::QInstance() {
    static BSAudioManager s_Instance;
    return s_Instance;
}

BSAudioManager::BSAudioManager() {}

BSAudioManager::~BSAudioManager() {}

void BSAudioManager::Initialize() {}

void BSAudioManager::Shutdown() {}

void BSAudioManager::InitializeAudio() {}

void BSAudioManager::StartAudioThread() {}

void BSAudioManager::SuspendAudioThread() {}

void BSAudioManager::StopAudioThread() {}

void BSAudioManager::Update(bool abPlayGameWorldSounds) {
    if (!bPrecacheCompleted) {
        BSAudio::QInstance().Precache("UIMenuMode", 0);
        BSAudio::QInstance().Precache("UIMenuFocus", 0x20000);
        BSAudio::QInstance().Precache("UIMenuCancel", 0x20001);
        BSAudio::QInstance().Precache("UIMenuTab", 0x20000);
        BSAudio::QInstance().Precache("UIMenuOK", 0x20001);
        BSAudio::QInstance().Precache("UIMenuPrevNext", 1);
        BSAudio::QInstance().Precache("WPNRifleAssaultFire3D", 0x102);
        BSAudio::QInstance().Precache("FXBulletImpactConc", 0x102);
        BSAudio::QInstance().Precache("UIScreenLoadMicroFiche01", 0x101);
        BSAudio::QInstance().Precache("UILoadScreenInitial", 0x101);
        bPrecacheCompleted = true;
    }
    SynchVoiceStates();
    if (!BSAudio::QInstance().IsMultiThreaded()) {
        QInstance().Process();
    }
}

void BSAudioManager::SetConditions(float afCurrentGamehour, uint aiWeatherConditions) {
    iWeatherFlags = aiWeatherConditions;
    fCurrentGamehour = afCurrentGamehour;
}

void BSAudioManager::SynchVoiceStates() {}

// void BSAudioManager::SetVoiceState(uint aiID, BSGameSound *apSound) {

// }

float BSAudioManager::GetCorrectedVolume(float afBaseVolume, uint aiTypeFlags) {
    return 0.0f;
}

BSSoundMessage *BSAudioManager::GetFreeMessage() { return FreeMessages.Pop(); }

void BSAudioManager::FreeMessage(BSSoundMessage *apMsgToFree) {}

BSSoundMessage *BSAudioManager::GetFreeQueueMessage() { return FreeQueueMessages.Pop(); }

void BSAudioManager::FreeQueueMessage(BSSoundMessage *apMsgToFree) {}

void BSAudioManager::ComposeMessage(
    SOUND_MSG aMsg,
    uint aiID,
    int aiData,
    void *apPointerData,
    NiPointer<NiAVObject> aspSmartPointerData,
    NiPoint3 aVector
) {}

bool BSAudioManager::Play(uint aiSoundID, bool abLoopPlayback) { return 0; }

bool BSAudioManager::PlayAfter(uint aiSoundID, uint aiDelay, int aiPlayFlags) {
    return 0;
}

bool BSAudioManager::Pause(uint aiSoundID) { return 0; }

bool BSAudioManager::Stop(uint aiSoundID) { return 0; }

void BSAudioManager::StopMovingSounds(
    NiAVObject *apObj, float afFadeSeconds, uint aiFlags
) {}

bool BSAudioManager::SetStaticAttenuation(
    uint aiSoundID, unsigned short aiStaticAttenutation
) {
    return 0;
}

bool BSAudioManager::SetFrequency(uint aiSoundID, float afNewFrequency) { return 0; }

bool BSAudioManager::SetModFrequency(uint aiSoundID, float afNewFrequency) { return 0; }

bool BSAudioManager::SetFrequencyVariance(uint aiSoundID, unsigned char aiFreqVariance) {
    return 0;
}

bool BSAudioManager::SetBalance(uint aiSoundID, int aiNewBalance) { return 0; }

bool BSAudioManager::SetPosition(uint aiSoundID, float afX, float afY, float afZ) {
    return 0;
}

bool BSAudioManager::SetBeamEnd(uint aiSoundID, float afX, float afY, float afZ) {
    return 0;
}

void BSAudioManager::SetMinMax(uint aiSoundID, float afMin, float afMax) {}

void BSAudioManager::SetAttenuationCurve(
    uint aiSoundID,
    unsigned short aiPt1,
    unsigned short aiPt2,
    unsigned short aiPt3,
    unsigned short aiPt4,
    unsigned short aiPt5
) {}

void BSAudioManager::SetReverbAttenuation(uint aiSoundID, unsigned short aiReverbAtt) {}

bool BSAudioManager::SetOrientation(uint aiSoundID, float afX, float afY, float afZ) {
    return 0;
}

bool BSAudioManager::Release(uint aiSoundID) { return 0; }

bool BSAudioManager::SetCompletionCallback(
    uint aiSoundID, void (*apfnCallback)(void *, bool), void *apSoundContext
) {
    return 0;
}

bool BSAudioManager::SetPlayCallback(
    uint aiSoundID, void (*apfnCallback)(void *, int), void *apSoundContext
) {
    return 0;
}

bool BSAudioManager::SetVolume(uint aiSoundID, float afNewVolume) { return 0; }

void BSAudioManager::VolumeChanged() {}

void BSAudioManager::SetObjectToFollow(uint aiID, NiAVObject *apObj) {}

void BSAudioManager::Seek(uint aiSoundID, uint aiMilliseconds) {}

void BSAudioManager::SetAtListener(uint aiSoundID, bool abSetAtListener) {}

void BSAudioManager::SetSynchStartTime(uint aiSoundID, uint aiStartTime) {}

void BSAudioManager::ClearSynchStartTime(uint aiSoundID) {}

void BSAudioManager::SetPriority(uint aiSoundID, uint aiPriority) {}

void BSAudioManager::SetTimeConstraints(
    uint aiSoundID, unsigned char aiStart, unsigned char aiStop
) {}

void BSAudioManager::FadeOut(uint aiID, uint aiMilliseconds, uint aiFollowUpAction) {}

void BSAudioManager::FadeIn(uint aiID, uint aiMilliseconds, uint aiFollowUpAction) {}

void BSAudioManager::FadeInPlay(uint aiID, uint aiMilliseconds) {}

bool BSAudioManager::IsValid(uint aiSoundID) { return 0; }

int BSAudioManager::GetDuration(uint aiSoundID) { return 0; }

float BSAudioManager::GetVolume(uint aiSoundID) { return 0.0f; }

bool BSAudioManager::IsPlaying(uint aiSoundID) { return 0; }

uint BSAudioManager::GetSoundType(uint aiSoundID) { return 0; }

void BSAudioManager::MuteAllOfType(
    uint aiTargetType, uint aiFadeTimeMS, uint aiMillibels
) {}

void BSAudioManager::UnMuteAllOfType(uint aiTargetType, uint aiFadeTimeMS) {}

void BSAudioManager::PauseAllOfType(uint aiType, bool abExactMatch) {}

void BSAudioManager::UnPauseAllOfType(uint aiType, bool abExactMatch) {}

void BSAudioManager::KillAllOfType(uint aiTargetType, uint aiFadeTimeMS) {}

// void BSAudioManager::AddToCache(BSGameSound *apToCache) {}

// BSGameSound *BSAudioManager::GetFromCache(
//     uint aiSoundHash, uint aiDirectoryHash, uint aiFlagsToApply
// ) {}

bool BSAudioManager::IsInCache(uint aiSoundHash, bool abFuzzy) { return 0; }

void BSAudioManager::Precache(char *apToCache, uint aiFlags) {}

void BSAudioManager::Precache(uint apToCache, uint aiFlags) {}

void BSAudioManager::Precache(
    char const *apFilenameToCache, uint aiFlags, void *apSettingsContext
) {}

// void BSAudioManager::Precache(BSGameSound *apToCache) {}

void BSAudioManager::Process() {}

void BSAudioManager::ProcessMessages() {}

void BSAudioManager::ProcessSoundUpdates() {}

void BSAudioManager::UpdateMovingSounds() {}

void BSAudioManager::PositionListener(NiPoint3 aNewPosition) {}

void BSAudioManager::SetListenerUnderwater(bool abIsUnderwater) {}

bool BSAudioManager::ProcessMessage(BSSoundMessage *apMsg) { return 0; }

// BSSoundHandle
// BSAudioManager::GetSoundHandleByName(char const *apSoundName, uint aiTypeFlags) {}

// BSSoundHandle BSAudioManager::GetSoundHandleByNumericID(uint aiBaseID, uint
// aiTypeFlags) {

// }

// BSSoundHandle BSAudioManager::GetSoundHandleByFilename(
//     char const *apFilename, uint aiTypeFlags, void *apSettingsContext
// ) {}

// BSSoundHandle BSAudioManager::SpawnSoundReference(
//     uint aiFormID, uint aiTypeFlags, NiPoint3 aLoc, uint aiID
// ) {}

// int BSAudioManager::AudioStringCompareFn(
//     AudioDebugString *apCompare1, AudioDebugString *apCompare2
// ) {}

// BSSimpleList<AudioDebugString *> *BSAudioManager::GetDebugString(uint aiPage) {}

void BSAudioManager::SetAudioCacheSizeInK(uint aiNewSize) {}

uint BSAudioManager::GetAudioCacheSizeInK() { return 0; }

void BSAudioManager::SetCacheEnabled(bool abEnableCache) {}

bool BSAudioManager::GetCacheEnabled() { return 0; }

bool BSAudioManager::IsPausedType(uint aiType) { return 0; }

bool BSAudioManager::SetPausedType(uint aiType, bool bExact) { return 0; }

bool BSAudioManager::ClearPausedType(uint aiType, bool bExact) { return 0; }

// void BSAudioManager::RemoveLoadTask(AudioLoadTask *pTask) {}

// AudioLoadTask::AudioLoadTask(BSGameSound *apSound) {}

// AudioLoadTask::~AudioLoadTask() {}

// void AudioLoadTask::Run() {}

// void AudioLoadTask::Finish() {}

// void AudioLoadTask::Cancel(BS_TASK_STATE aePreviousState, void *apTaskOwner) {}

// bool AudioLoadTask::GetDescription(char *apDescription, uint aiBufferSize) {}

// uint BSAudioManagerThread::ThreadProc() {}

AudioMessageStack::AudioMessageStack() {
    iCount = 0;
    pTop = nullptr;
    bBottomless = false;
    iTimeLastAllocated = 0;
}

AudioMessageStack::~AudioMessageStack() {
    for (int i = iCount; i != 0; i--) {
        RELEASE(pTop);
    }
}

void AudioMessageStack::Push(BSSoundMessage *apMsg) {}

BSSoundMessage *AudioMessageStack::Pop() { return nullptr; }
