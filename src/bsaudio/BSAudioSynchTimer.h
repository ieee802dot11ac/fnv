#pragma once

#include <types.h>

class BSAudioSynchTimer {
public:
    BSAudioSynchTimer();
    ~BSAudioSynchTimer();
    void Update();
    void Restart();
    void Pause() { iFlags |= 1; }
    void UnPause() { iFlags &= ~1; }
    bool IsPaused() { return iFlags & 1; }
    int GetSynchTime();

private:
    uint32_t iMilliseconds; // 0x0
    uint32_t iLastUpdateTime; // 0x4
    uint32_t iFlags; // 0x8
};
