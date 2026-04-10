#pragma once

#include "gamebryo2.2/corelibs/nimain/niavobject.h"
#include <types.h>
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"

class BSSoundHandle {
public:
    enum ASSUMED_STATE {
        ASSUMED_STATE_INITIALIZED = 0x0000,
        ASSUMED_STATE_PLAYING = 0x0001,
        ASSUMED_STATE_STOPPED = 0x0002,
        ASSUMED_STATE_PAUSED = 0x0003,
    };

    BSSoundHandle(const BSSoundHandle &handle)
        : iSoundID(handle.iSoundID), bAssumeSuccess(handle.bAssumeSuccess),
          eState(handle.eState) {}
    BSSoundHandle(uint);
    BSSoundHandle();
    ~BSSoundHandle() {}
    void Clear();
    bool Play(bool);
    bool PlayAfter(uint, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetModFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(uint16_t);
    int GetDuration();
    bool SetPosition(const NiPoint3 &point);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(const NiPoint3 &);
    bool SetBeamEnd(float, float, float);
    void SetMinMax(float, float);
    void SetAttenuationCurve(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    void SetReverbAttenuation(uint16_t);
    bool SetOrientation(float, float, float);
    uint GetID() const;
    void SetObjectToFollow(NiAVObject *);
    void Seek(uint);
    void SetFollowsListener(bool);
    void SetCompletionCallback(void (*)(void *, bool), void *);
    void SetPlayCallback(void (*)(void *, int), void *);
    bool Release();
    bool FadeInPlay(uint);
    bool FadeOutAndRelease(uint);
    bool FadeOut(uint);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(uint);
    void ClearSynchStartTime();
    void SetPriority(uint);
    void SetAssumeSuccess(bool);
    ASSUMED_STATE QState() const;
    BSSoundHandle &operator=(const BSSoundHandle &);
    bool operator==(uint) const;
    bool operator==(const BSSoundHandle &) const;
    bool operator!=(uint);
    bool operator!=(const BSSoundHandle &) const;

    static void SetAddMovingSoundCallback(void (*)(NiAVObject *));

protected:
    uint iSoundID; // 0x0
    bool bAssumeSuccess; // 0x4
    ASSUMED_STATE eState; // 0x8

    static void (*pfnAddMovingSoundCallback)(NiAVObject *);
};
