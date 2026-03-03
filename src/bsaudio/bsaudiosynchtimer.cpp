#include "bsaudiosynchtimer.h"
#include "xapilibi/sysinfoapi.h"

BSAudioSynchTimer::BSAudioSynchTimer() {
    iFlags = 0;
    iMilliseconds = 600000;
    iLastUpdateTime = GetTickCount();
}

BSAudioSynchTimer::~BSAudioSynchTimer() {
    iFlags = 0;
    iMilliseconds = 600000;
    iLastUpdateTime = GetTickCount();
}

void BSAudioSynchTimer::Update() {
    int tc = GetTickCount();
    int delta = tc - iLastUpdateTime;
    if (!bool(((iFlags & 1) == 0) ^ 1)) {
        iMilliseconds += delta;
    }
    iLastUpdateTime = tc;
}

void BSAudioSynchTimer::Restart() {
    iFlags = 0;
    iMilliseconds = 600000;
    iLastUpdateTime = GetTickCount();
}
