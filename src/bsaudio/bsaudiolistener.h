#pragma once

#include "bscore/memorymanager.h"
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"

class BSAudioListener {
public:
    BSAudioListener(const BSAudioListener &);
    BSAudioListener() {}
    virtual ~BSAudioListener() { iEvironmentType = 0; }
    virtual void Init();
    virtual void SetPosition(const NiPoint3 &);
    virtual NiPoint3 &GetPosition();
    virtual void Update();
    virtual void SetOrientation(const NiPoint3 &, const NiPoint3 &);
    virtual NiPoint3 &GetFrontOrientation();
    virtual NiPoint3 &GetTopOrientation();
    virtual void SetVelocity(const NiPoint3 &);
    virtual void SetGain(float);
    float GetGain();
    virtual void SetEnvironmentType(uint);
    virtual uint GetEnvironmentType();
    virtual void SetRolloffFactor(float);
    float GetRolloffFactor();
    float GetVelocity();
    NiPoint3 &GetVelocityVector();
    BSAudioListener &operator=(const BSAudioListener &);

    BS_MEM_OVERLOADS

protected:
    NiPoint3 ListenerPosition; // 0x04
    NiPoint3 FrontOrientation; // 0x10
    NiPoint3 TopOrientation; // 0x1c
    NiPoint3 vVelocity; // 0x28
    uint dwTimeLastUpdated; // 0x34
    float fVelocity; // 0x38
    float fRolloffFactor; // 0x3c
    float fGain; // 0x40
    uint iEvironmentType; // 0x44
};
