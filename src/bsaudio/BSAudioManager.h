#pragma once

#include "bscore/memorymanager.h"
#include <types.h>
#include "bsaudio/bssoundhandle.h"
#include "gamebryo2.2/corelibs/nimain/niavobject.h"

enum SOUND_MSG {
    MINVALID_MSG = 0x0000,
    MPLAY = 0x0001,
    MPLAYLOOPING = 0x0002,
    MPAUSE = 0x0003,
    MSTOP = 0x0004,
    MPLAY_AFTER = 0x0005,
    MSTOP_AFTER = 0x0006,
    MMUTE = 0x0007,
    MUNMUTE = 0x0008,
    MFADE_OUT = 0x0009,
    MFADE_TO = 0x000a,
    MFADE_IN = 0x000b,
    MFADE_FROM = 0x000c,
    MDIALOGUE_FADE = 0x000d,
    MVOLUME_LEVELS_CHANGED = 0x000e,
    MFREE_IF_STOPPED = 0x000f,
    MSET_VOLUME = 0x0010,
    MINCREASE_VOLUME_TO = 0x0011,
    MDECREASE_VOLUME_TO = 0x0012,
    MSET_FREQUENCY = 0x0013,
    MSET_FREQUENCY_VARIANCE = 0x0014,
    MINCREASE_FREQUENCY_TO = 0x0015,
    MDECREASE_FREQUENCY_TO = 0x0016,
    MKILL_ALL_SOUNDS = 0x0017,
    MMUTE_ALL_OFTYPE = 0x0018,
    MUNMUTE_ALL_OFTYPE = 0x0019,
    MPAUSE_ALL_OFTYPE = 0x001a,
    MUNPAUSE_ALL_OFTYPE = 0x001b,
    MPAUSE_ALL_OFTYPE_EXACT = 0x001c,
    MUNPAUSE_ALL_OFTYPE_EXACT = 0x001d,
    MSET_POS = 0x001e,
    MSET_BEAM_END = 0x001f,
    MSET_ORIENT = 0x0020,
    MSET_STATIC_ATTENUATION = 0x0021,
    MSET_REVERB_ATTENUATION = 0x0022,
    MSET_MINMAX_DISTANCE = 0x0023,
    MSET_ATTENUATION_CURVE = 0x0024,
    MADD_SOUND_TO_LIST = 0x0025,
    MDELETE_SOUND = 0x0026,
    MREGISTER_MOVING_SOUND = 0x0027,
    MPURGE_MOVING_SOUNDS = 0x0028,
    MSTOP_MOVING_SOUNDS = 0x0029,
    MKILL_ALL_OFTYPE = 0x002a,
    MMUTE_ALL_LOOPS = 0x002b,
    MUNMUTE_ALL_LOOPS = 0x002c,
    MFORCE_LOOP = 0x002d,
    MSET_SOUND_TYPE = 0x002e,
    MSET_WEATHER_TYPES = 0x002f,
    MPRECACHE_COMBAT_SOUNDS = 0x0030,
    MENABLE_SOUND_CACHE = 0x0031,
    MCACHE_SIZE_CHANGED = 0x0032,
    MADD_SOUND_TO_CACHE = 0x0033,
    MTERMINATE_THREAD = 0x0034,
    MSUSPEND_THREAD = 0x0035,
    MERROR_TOO_MANY_SOUNDS = 0x0036,
    MSET_UNDERWATER = 0x0037,
    MSET_LISTENER_POSITION = 0x0038,
    MDATA_REQUEST = 0x0039,
    MSET_COMPLETION_CALLBACK = 0x003a,
    MSET_PLAY_CALLBACK = 0x003b,
    MSET_SYNCH_START = 0x003c,
    MCLEAR_SYNCH_START = 0x003d,
    MSET_TIME_CONSTRAINTS = 0x003e,
    MSEEK = 0x003f,
    MSET_AT_LISTENER = 0x0040,
    MSET_PRIORITY = 0x0041,
    MSET_MOD_FREQUENCY = 0x0042,
};

class BSSoundMessage {
public:
    BSSoundMessage(const BSSoundMessage &);
    BSSoundMessage(BSSoundMessage *);
    BSSoundMessage(SOUND_MSG, int, int, int, NiPointer<NiAVObject>, NiPoint3);
    BSSoundMessage(SOUND_MSG, int, int, void *, NiPointer<NiAVObject>, NiPoint3);
    BSSoundMessage();
    ~BSSoundMessage();
    SOUND_MSG Message();
    int SID();
    int Data();
    void SetData(int);
    void *PData();
    int Data2();
    void SetPData(void *);
    void SPData(NiPointer<NiAVObject> &);
    void SetSPData(NiPointer<NiAVObject>);
    void GetVector3(NiPoint3);
    NiPoint3 GetVector3();
    uint16_t GetCurveValue(int);
    void SetCurveValue(int, uint16_t);
    NiPointer<NiAVObject> GetSPData();
    void Set(SOUND_MSG, int, int, int, NiPointer<NiAVObject>, NiPoint3);
    void Set(SOUND_MSG, int, int, void *, NiPointer<NiAVObject>, NiPoint3);
    BSSoundMessage &operator=(const BSSoundMessage &);

    BS_MEM_OVERLOADS

private:
    SOUND_MSG msg; // 0x00
    int iID; // 0x04
    int iData; // 0x08
    void *pData; // 0x0c
    NiPointer<NiAVObject> spData; // 0x10
    union { // 0x14
        float vector3[3];
        uint16_t curve[5];
    };
};

class AudioMessageStack {
public:
    AudioMessageStack();
    ~AudioMessageStack();
    void Push(BSSoundMessage *);
    BSSoundMessage *Pop();
    void SetBottomless(bool);

protected:
    uint iCount; // 0x0
    bool bBottomless; // 0x4
    BSSoundMessage *pTop; // 0x8
    uint iTimeLastAllocated; // 0xc
};

class BSAudioManager {
public:
    struct PAUSE_ENTRY {
        uint iPauseMask; // 0x0
        uint16_t iPauseState; // 0x4
    };

    virtual ~BSAudioManager();
    void Initialize();
    void InitializeAudio();
    void Shutdown();
    void StartAudioThread();
    void SuspendAudioThread();
    void StopAudioThread();
    void Update(bool);
    void SetConditions(float, uint);
    BSSoundHandle GetSoundHandleByNumericID(uint, uint);
    BSSoundHandle GetSoundHandleByFilename(const char *, uint, void *);
    BSSoundHandle GetSoundHandleByName(const char *, uint);
    BSSoundHandle
    SpawnSoundReference(uint aiFormID, uint aiTypeFlags, NiPoint3 aLoc, uint aiID);
    float GetCorrectedVolume(float, uint);
    void KillAllOfType(uint, uint);
    void MuteAllOfType(uint, uint, uint);
    void UnMuteAllOfType(uint, uint);
    void PauseAllOfType(uint, bool);
    void UnPauseAllOfType(uint, bool);
    bool Play(uint, bool);
    bool PlayAfter(uint, uint, int);
    bool Pause(uint);
    bool Stop(uint);
    void FadeOut(uint, uint, uint);
    void FadeIn(uint, uint, uint);
    void FadeInPlay(uint, uint);
    bool IsPlaying(uint);
    uint GetSoundType(uint);
    bool SetStaticAttenuation(uint, uint16_t);
    bool SetVolume(uint, float);
    float GetVolume(uint);
    bool SetFrequency(uint, float);
    bool SetModFrequency(uint, float);
    bool SetFrequencyVariance(uint, unsigned char);
    bool SetBalance(uint, int);
    int GetDuration(uint);
    bool SetPosition(uint, float, float, float);
    bool SetBeamEnd(uint, float, float, float);
    void SetMinMax(uint, float, float);
    void SetAttenuationCurve(uint, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    void SetReverbAttenuation(uint, uint16_t);
    bool SetOrientation(uint, float, float, float);
    bool IsValid(uint);
    bool Release(uint);
    bool SetCompletionCallback(uint, void (*)(void *, bool), void *);
    bool SetPlayCallback(uint, void (*)(void *, int), void *);
    void VolumeChanged();
    void SetObjectToFollow(uint, NiAVObject *);
    void Seek(uint, uint);
    void SetAtListener(uint, bool);
    void SetSynchStartTime(uint, uint);
    void ClearSynchStartTime(uint);
    void SetPriority(uint, uint);
    void SetTimeConstraints(uint, unsigned char, unsigned char);
    void StopMovingSounds(NiAVObject *, float, uint);
    void UpdateMovingSounds();
    void PositionListener(NiPoint3);
    void SetListenerUnderwater(bool);
    bool IsListenerUnderwater() { return bListenerUnderwater; }
    float GetMasterVolume() { return fMasterVolume; }
    float GetFootVolume() { return fFootVolume; }
    float GetVoiceVolume() { return fVoiceVolume; }
    float GetEffectVolume() { return fEffectsVolume; }
    float GetMusicVolume() { return fMusicVolume; }
    float GetRadioVolume() { return fRadioVolume; }
    void SetMasterVolume(float f) {
        fMasterVolume = f;
        VolumeChanged();
    }
    void SetFootVolume(float f) {
        fFootVolume = f;
        VolumeChanged();
    }
    void SetVoiceVolume(float f) {
        fVoiceVolume = f;
        VolumeChanged();
    }
    void SetEffectVolume(float f) {
        fEffectsVolume = f;
        VolumeChanged();
    }
    void SetMusicVolume(float f) {
        fMusicVolume = f;
        VolumeChanged();
    }
    void SetRadioVolume(float f) {
        fRadioVolume = f;
        VolumeChanged();
    }
    float GetMasterSecondaryVolume() { return fMasterSecondaryVolume; }
    float GetFootSecondaryVolume() { return fFootSecondaryVolume; }
    float GetVoiceSecondaryVolume() { return fVoiceSecondaryVolume; }
    float GetEffectSecondaryVolume() { return fEffectsSecondaryVolume; }
    float GetMusicSecondaryVolume() { return fMusicSecondaryVolume; }
    float GetRadioSecondaryVolume() { return fRadioSecondaryVolume; }
    void SetMasterSecondaryVolume(float f) {
        fMasterSecondaryVolume = f;
        VolumeChanged();
    }
    void SetFootSecondaryVolume(float f) {
        fFootSecondaryVolume = f;
        VolumeChanged();
    }
    void SetVoiceSecondaryVolume(float f) {
        fVoiceSecondaryVolume = f;
        VolumeChanged();
    }
    void SetEffectSecondaryVolume(float f) {
        fEffectsSecondaryVolume = f;
        VolumeChanged();
    }
    void SetMusicSecondaryVolume(float f) {
        fMusicSecondaryVolume = f;
        VolumeChanged();
    }
    void SetRadioSecondaryVolume(float f) {
        fRadioSecondaryVolume = f;
        VolumeChanged();
    }
    void ClearSecondaryVolumes();
    // BSSimpleList<AudioDebugString *> *GetDebugString(uint);
    uint GetNextID();
    void SetAudioCacheSizeInK(uint);
    uint GetAudioCacheSizeInK();
    void SetCacheEnabled(bool);
    bool GetCacheEnabled();
    void ComposeMessage(SOUND_MSG, uint, int, void *, NiPointer<NiAVObject>, NiPoint3);
    void Precache(const char *, uint, void *);
    void Precache(uint, uint);
    void Precache(char *, uint);
    bool IsInCache(uint, bool);
    void SetIgnoreGlobalTimeMultiplier(bool);
    // void RemoveLoadTask(AudioLoadTask *);
    BSAudioManager(const BSAudioManager &);
    BSAudioManager &operator=(const BSAudioManager &);

    static BSAudioManager &QInstance();

protected:
    BSAudioManager();

private:
    // void Precache(BSGameSound *);
    void Process();
    void ProcessMessages();
    bool ProcessMessage(BSSoundMessage *);
    void ProcessSoundUpdates();
    BSSoundMessage *GetFreeMessage();
    void FreeMessage(BSSoundMessage *);
    BSSoundMessage *GetFreeQueueMessage();
    void FreeQueueMessage(BSSoundMessage *);
    // void AddToCache(BSGameSound *);
    // BSGameSound *GetFromCache(uint, uint, uint);
    bool IsPausedType(uint);
    bool SetPausedType(uint, bool);
    bool ClearPausedType(uint, bool);
    // void SetVoiceState(uint, BSGameSound *);
    void SynchVoiceStates();
    int iMessageListIndex; // 0x004
    int iMessageProcessingListIndex; // 0x008
    // NiTPointerList<BSSoundMessage *> Messages[2]; // 0x00c
    AudioMessageStack FreeMessages; // 0x024
    AudioMessageStack FreeQueueMessages; // 0x034
    AudioMessageStack GarbageMessages; // 0x044
    // NiTPointerMap<int, BSGameSound *> SoundList; // 0x054
    // NiTPointerMap<int, BSSoundInfo *> SoundStateMap; // 0x064
    // NiTPointerMap<int, BSSoundInfo *> StateUpdateMap; // 0x074
    // NiTPointerMap<int, NiPointer<NiAVObject> > MovingRefrList; // 0x084
    // NiTPointerList<BSGameSound *> CachedSoundList; // 0x094
    uint iCurrentCachSize; // 0x0a0
    uint iWeatherFlags; // 0x0a4
    float fCurrentGamehour; // 0x0a8
    // BSCriticalSection MessageCritSection; // 0x0ac
    // BSCriticalSection StateCritSection; // 0x0d4
    // BSCriticalSection CacheCritSection; // 0x0fc
    // BSCriticalSection ProcessingCritSection; // 0x124
    // BSCriticalSection CacheLoadTaskCritSection; // 0x14c
    // NiTPointerList<AudioLoadTask *> CacheLoadTaskList; // 0x174
    uint iDelayTimerDelta; // 0x180
    bool bPrecacheCompleted; // 0x184
    bool bListenerMoved; // 0x185
    uint dwAudioThreadID; // 0x188
    // BSAudioManagerThread *pUpdateThread; // 0x18c
    float fMasterVolume; // 0x190
    float fFootVolume; // 0x194
    float fVoiceVolume; // 0x198
    float fEffectsVolume; // 0x19c
    float fMusicVolume; // 0x1a0
    float fRadioVolume; // 0x1a4
    float fMasterSecondaryVolume; // 0x1a8
    float fFootSecondaryVolume; // 0x1ac
    float fVoiceSecondaryVolume; // 0x1b0
    float fEffectsSecondaryVolume; // 0x1b4
    float fMusicSecondaryVolume; // 0x1b8
    float fRadioSecondaryVolume; // 0x1bc
    uint iMuteMask; // 0x1c0
    bool bDialogueFade; // 0x1c4
    bool bListenerUnderwater; // 0x1c5
    PAUSE_ENTRY *pPauseEntries; // 0x1c8
    uint iPauseListSize; // 0x1cc
    uint iNextID; // 0x1d0
    bool bIgnoreGlobalTimeMultiplier; // 0x1d4
    // static int AudioStringCompareFn(AudioDebugString *, AudioDebugString *);
};
