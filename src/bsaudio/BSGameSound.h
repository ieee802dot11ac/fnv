#pragma once

#include "bsaudio/BSAudioManager.h"
#include "bscore/memorymanager.h"
#include "nimain/NiPoint3.h"

class BSGameSound { /* Size=0x198 */
public:
    BSGameSound(const BSGameSound &);
    BSGameSound();
    BSGameSound(const char *);
    virtual ~BSGameSound();
    void QueueMessage(BSSoundMessage *);
    // NiTPointerList<BSSoundMessage *> *GetMessageQueue();
    bool HasQueuedMessages();
    bool SetFilename(const char *, bool);
    const char *GetFileName() const;
    void Init();
    void SetID(unsigned int);
    unsigned int GetID() const;
    bool HasBeenOpened() const;
    bool IsOpening() const;
    void SetOpening(bool);
    bool IsTimeRestricted() const;
    void SetTimeRestricted(bool);
    bool IsReady() const;
    void SetReady(bool);
    bool IsValid() const;
    void SetValid(bool);
    virtual bool IsPlaying() { return (iStateFlags & 0x20); }
    void SetPlaying(bool);
    virtual bool IsInDecay() { return (iStateFlags & 0x80000); }
    void SetIsInDecay(bool);
    void SetSynchPause(bool);
    bool IsSynchPaused() const;
    virtual bool IsPaused() { return (iStateFlags & 0x40); }
    void SetPaused(bool);
    virtual float GetVolume() { return fCurrentVolume; }
    bool IsInaudible() const;
    virtual void SetInaudible(bool abIn) {
        int new_value;
        if (abIn) {
            new_value = iStateFlags | 0x20000;
        } else {
            new_value = iStateFlags & ~0x20000;
        }
        iStateFlags = new_value;
    }
    void VolumeChanged();
    void SetCompletionCallback(void (*)(void *, bool));
    void (*GetCompletionCallback())(void *, bool);
    void SetPlayCallback(void (*)(void *, int));
    void (*GetPlayCallback())(void *, int);
    bool GetRadioPause() const;
    void SetRadioPause(bool);
    void SetCompletionContext(void *);
    void *GetCompletionContext() const;
    void SetPlayContext(void *);
    void *GetPlayContext() const;
    virtual void SetEnvironmentType(unsigned int aiEnvType) {
        iEnvironmentType = aiEnvType;
    }
    unsigned int GetEnvironmentType() const;
    bool IsFading() const;
    void SetFading(bool);
    bool IsSeeking() const;
    void SetSeeking(bool);
    bool IsSilent() const;
    void SetSilent(bool);
    bool IsSoundFinished() const;
    void SetSoundFinished(bool);
    void SetHasPlayed(bool);
    bool HasPlayed() const;
    const char *GetName() const;
    unsigned int GetSize() const;
    bool IsSimpleLoop() const;
    bool IsLoopingSound() const;
    bool IsEnvelopeLoop() const;
    bool IsEnvelopeLoopFast() const;
    bool IsEnvelopeLoopSlow() const;
    bool IsBeamEmitter() const;
    bool IsOneShot() const;
    bool IsBattleSound() const;
    bool IsRegionSound() const;
    bool HasVariableFreq() const;
    void SetVariableFreq(bool);
    void SetFreqVariance(unsigned char);
    unsigned char GetFreqVariance() const;
    void SetModFrequency(float);
    float GetModFrequency() const;
    bool Is3DSound() const;
    bool Is2DRadiusSound() const;
    bool IsVoice() const;
    unsigned int GetSoundType() const;
    void SetSoundType(unsigned int);
    unsigned int GetModFlags() const;
    void SetModFlags(unsigned int);
    void SetBeginTime(float);
    float GetBeginTime() const;
    void SetEndTime(float);
    float GetEndTime() const;
    void SetWeatherFlags(unsigned int);
    int GetDuration() const;
    void SetDuration(int);
    void SetStaticAttenuation(unsigned short);
    unsigned short GetStaticAttenuation() const;
    void SetReverbAttenuation(unsigned short);
    unsigned short GetReverbAttenuation() const;
    void SetSystemAttenuation(unsigned short);
    unsigned short GetSystemAttenuation() const;
    void SetFaderAttenuation(unsigned short);
    unsigned short GetFaderAttenuation() const;
    void SetDistanceAttenuation(unsigned short);
    unsigned short GetDistanceAttenuation() const;
    bool CanPlayNow(unsigned int, float);
    bool IsCached() const;
    void SetCached(bool);
    bool IsInMemory() const;
    void SetInMemory(bool);
    bool IsStreaming() const;
    void SetStreaming(bool);
    float GetLastDistanceToListener() const;
    void SetDistanceToListener(float);
    unsigned int GetSynchStartTime();
    void SetSynchStartTime(unsigned int);
    void ClearSynchStartTime();
    bool IsExternallySynched();
    void SetBeamEnd(NiPoint3);
    const NiPoint3 &GetBeamEnd() const;
    bool IsValidBeam() const;
    void SetValidBeam(bool);
    void SetPriority(unsigned int);
    unsigned int GetPriority();
    virtual bool PriorityTest(BSGameSound *apToCompare) {
        return iPriority < apToCompare->iPriority;
    }
    virtual bool PriorityTest(unsigned int aiToCompare) {
        return iPriority < aiToCompare;
    }
    void SetLoopPoints(unsigned int, unsigned int);
    unsigned int GetLoopStart();
    unsigned int GetLoopEnd();
    bool GetMuteWhenSumberged() const;
    void SetMuteWhenSumberged(bool);
    void HandlePlayCallback();
    virtual bool Open();
    virtual bool Prepare();
    virtual void Copy(BSGameSound *, bool);
    virtual bool Play(bool);
    virtual bool Pause();
    virtual bool Stop();
    virtual bool SetVolume(float);
    virtual void UpdateEmitterPosition();
    virtual bool Update(unsigned int);
    virtual bool ProcessDataRequest(int);
    virtual void SetEmitterPosition(NiPoint3);
    virtual void SetEmitterPosition(float, float, float);
    virtual NiPoint3 GetEmitterPosition();
    virtual void SetEmitterOrientation(float, float, float);
    virtual void SetMinMax(float, float);
    virtual void SetAttenuationCurve(
        unsigned short, unsigned short, unsigned short, unsigned short, unsigned short
    );
    float GetMin();
    float GetMax();
    virtual bool SetFrequency(float);
    virtual float GetFrequency();
    virtual void Seek(unsigned int);
    void SetCleanupDelay(unsigned int);
    unsigned int GetCleanupDelay();
    float GetMinDistance() const;
    float GetMaxDistance() const;
    bool CalculateHashes(bool);
    bool HaveHashedBeenCalculated();
    bool MatchesSoundHash(unsigned int);
    bool MatchesSoundHash(BSGameSound *);
    bool MatchesDirectoryHash(unsigned int);
    bool MatchesDirectoryHash(BSGameSound *);
    unsigned int GetSoundHash();
    unsigned int GetDirHash();

    static unsigned int GetNameHash(const char *);

    BS_MEM_OVERLOADS

protected:
    bool OpenResult(bool);

    unsigned int iSoundID; // 0x004
    unsigned int iSoundTypeFlags; // 0x008
    unsigned int iModifierFlags; // 0x00c
    unsigned int iStateFlags; // 0x010
    int iDurationInMS; // 0x014
    unsigned short iStaticAttenuation; // 0x018
    unsigned short iReverbAttenuation; // 0x01a
    unsigned short iSystemAttenuation; // 0x01c
    unsigned short iDistanceAttenuation; // 0x01e
    unsigned short iFaderAttenuation; // 0x020
    float fCurrentVolume; // 0x024
    float fBeginTime; // 0x028
    float fEndTime; // 0x02c
    unsigned int iWeatherFlags; // 0x030
    unsigned short iSamplesPerSecond; // 0x034
    char pFilename[260]; // 0x036
    float fMaxDist; // 0x13c
    float fMinDist; // 0x140
    unsigned int iSoundHash; // 0x144
    unsigned int iDirectoryHash; // 0x148
    unsigned int iSoundSize; // 0x14c
    float fDistanceToListener; // 0x150
    unsigned int iEnvironmentType; // 0x154
    unsigned char iFreqVariance; // 0x158
    unsigned short iModSamplesPerSecond; // 0x15a
    unsigned int iSynchStartTime; // 0x15c
    unsigned int iCleanupDelayInMS; // 0x160
    void (*fnCompletionCallback)(void *, bool); // 0x164
    void (*fnPlayedCallback)(void *, int); // 0x168
    void *pSoundCompletionContext; // 0x16c
    void *pSoundPlayContext; // 0x170
    unsigned int iLoopStart; // 0x174
    unsigned int iLoopEnd; // 0x178
    NiPoint3 vBeamEnd; // 0x17c
    unsigned int iPriority; // 0x188
    // NiTPointerList<BSSoundMessage *> QueuedMessages; // 0x18c
};
