#include "BSGameSound.h"

BSGameSound::BSGameSound(const char *apFilename) { Init(); }

BSGameSound::BSGameSound() { Init(); }

BSGameSound::~BSGameSound() {}

bool BSGameSound::Is3DSound() const { return (iSoundTypeFlags & 0x2); }

bool BSGameSound::CalculateHashes(bool abAllowDiskAccess) {
    if (pFilename) {
        return SetFilename(pFilename, abAllowDiskAccess);
    } else {
        return 0;
    }
}

uint BSGameSound::GetNameHash(const char *pString) {
    uint hash = 0;
    if (!pString) {
        return hash;
    }
    // BUG: the first character doesn't get hashed
    for (const char *it = pString; *++it != 0;) {
        hash = *it + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}
