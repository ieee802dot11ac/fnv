#pragma once

#include <types.h>
#include "bsaudio/bssoundhandle.h"
#include "bsaudio/bsaudiosynchtimer.h"
#include "bsaudio/bsaudiolistener.h"
#include "bscore/memorymanager.h"
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"
#include "gamebryo2.2/corelibs/nimain/niavobject.h"

class BSAudio { /* Size=0x38 */
    //   public: static SettingT<INISettingCollection> fDawnTime;
    //   public: static SettingT<INISettingCollection> fDayTime;
    //   public: static SettingT<INISettingCollection> fDuskTime;
    //   public: static SettingT<INISettingCollection> fNightTime;
public:
    static BSSoundHandle VatsLoopHandle;
    //   public: static SettingT<INISettingCollection> bEnableAudio;
    //   public: static SettingT<INISettingCollection> fTextToSpeechVolume;
    //   public: static SettingT<INISettingCollection> bEnableTextToSpeech;

    virtual ~BSAudio();
    virtual void *GetAudioObject();
    virtual void Init(void *);
    virtual void Shutdown();
    void SetMultiThreaded(bool);
    bool IsMultiThreaded() { return bMultiThread; }
    BSSoundHandle GetSoundHandleByNumericID(uint, uint);
    BSSoundHandle GetSoundHandleByFilename(const char *, uint, void *);
    BSSoundHandle GetSoundHandleByName(const char *, uint);
    BSSoundHandle SpawnSoundReference(uint, uint, NiPoint3, uint);
    void SetNumericIDCallback(bool (*)(uint, char *, uint *, void **));
    bool (*GetNumericIDCallback())(uint, char *, uint *, void **);
    void SetNameIDCallback(bool (*)(const char *, char *, uint *, void **));
    bool (*GetNameIDCallback())(const char *, char *, uint *, void **);
    void SetRandomFileCallback(bool (*)(char *));
    bool (*GetRandomFileCallback())(char *);
    void SetSettingsCallback(uint (*)(BSSoundHandle &, void *, uint *));
    uint (*GetSettingsCallback())(BSSoundHandle &, void *, uint *);
    virtual void SetLoopPointCallback(bool (*)(void *, uint *, uint *));
    virtual bool (*GetLoopPointCallback())(void *, uint *, uint *);
    void SetSynchPausedCallback(void (*)());
    void (*GetSynchPausedCallback())();
    void SetSynchUnPausedCallback(void (*)());
    void (*GetSynchUnPausedCallback())();
    void Update(bool);
    void SetConditions(float, uint);
    void PositionListener(NiPoint3);
    void OrientListener(NiPoint3, NiPoint3);
    void SetEnvironment(uint);
    BSAudioListener *GetListener();
    NiPoint3 GetListenerPosition();
    void SetListenerUnderwater(bool);
    bool IsInitialized();
    void EndAllSoundsOfType(uint);
    void EndAllMovingSounds();
    void EnterDialogue();
    void ExitDialogue();
    void StopMovingSounds(NiAVObject *, float, uint);
    void Precache(const char *, uint, void *);
    void Precache(uint, uint);
    void Precache(char *, uint);
    void SetAudioCacheSizeInK(uint);
    uint GetAudioCacheSizeInK();
    void SetCacheEnabled(bool);
    bool GetCacheEnabled();
    void Mute(uint, uint);
    void UnMute(uint);
    void MuteType(uint, uint, uint);
    void UnMuteType(uint, uint);
    void PauseWorldSounds();
    void UnPauseWorldSounds();
    void PauseAnimationSounds();
    void UnPauseAnimationSounds();
    void PauseWorldVoices();
    void UnPauseWorldVoices();
    void PauseAllOfType(uint, bool);
    void UnPauseAllOfType(uint, bool);
    void KillAllOfType(uint, uint);
    float GetMasterVolume();
    float GetFootVolume();
    float GetVoiceVolume();
    float GetEffectVolume();
    float GetMusicVolume();
    float GetRadioVolume();
    void SetMasterVolume(float);
    void SetFootVolume(float);
    void SetVoiceVolume(float);
    void SetEffectVolume(float);
    void SetMusicVolume(float);
    void SetRadioVolume(float);
    void VolumeChanged();
    float GetMasterSecondaryVolume();
    float GetFootSecondaryVolume();
    float GetVoiceSecondaryVolume();
    float GetEffectSecondaryVolume();
    float GetMusicSecondaryVolume();
    float GetRadioSecondaryVolume();
    void SetMasterSecondaryVolume(float);
    void SetFootSecondaryVolume(float);
    void SetVoiceSecondaryVolume(float);
    void SetEffectSecondaryVolume(float);
    void SetMusicSecondaryVolume(float);
    void SetRadioSecondaryVolume(float);
    void ClearSecondaryVolumes();
    uint GetSynchTime();
    void PauseSynchTimer();
    void UnPauseSynchTimer();
    bool IsSynchTimerPaused();
    void SynchTimerUpdate();
    void SetMusicStartOffset(uint);
    uint GetMusicStartOffset();
    void SetMusicSeek(bool);
    bool GetMusicSeek();
    // BSSimpleList<AudioDebugString *> *GetDebugString(uint);
    // virtual BSGameSound *CreateNewGameSound(const char *);
    virtual void FixSoundPath(char *);
    bool IsListenerUnderwater();
    bool IsAudioEnabled() { return bAudioEnabled; }
    virtual void PrintDebugInfo();

    static void QCreate();
    static BSAudio &QInstance() { return *pAudioInstance; }
    static float GetMinDialogDist();
    static float GetMaxDialogDist();

    BS_MEM_OVERLOADS

protected:
    BSAudio();
    bool bAudioEnabled; // 0x04
    bool bInitialized; // 0x05
    bool bMultiThread; // 0x06
    uint iMusicStartOffset; // 0x08
    bool bSeekMusic; // 0x0c
    BSAudioListener *pListener; // 0x10
    BSAudioSynchTimer SynchTimer; // 0x14

protected:
    static BSAudio *pAudioInstance;
    //   protected: static SettingT<INISettingCollection> fDialogMinDistance;
    //   protected: static SettingT<INISettingCollection> fDialogMaxDistance;

private:
    bool (*pfnIDCallback)(uint, char *, uint *, void **); // 0x20
    bool (*pfnNameCallback)(const char *, char *, uint *, void **); // 0x24
    bool (*pfnRandomFilenameCallback)(char *); // 0x28
    uint (*pfnSettingsCallback)(BSSoundHandle &, void *, uint *); // 0x2c
    void (*pfnSynchPausedCallback)(); // 0x30
    void (*pfnSynchUnPausedCallback)(); // 0x34
};
