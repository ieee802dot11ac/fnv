#include "BSGameDataSystemUtility.h"

BSGameDataSystemUtility::BSGameDataSystemUtility() {
    bIsActive = false;
    bNewGameData = false;
    eGameDataStatus_ = GAMEDATA_STATUS_NOT_READY;
    iFreeSpaceKB_ = 0;
}

BSGameDataSystemUtility::~BSGameDataSystemUtility() {}
