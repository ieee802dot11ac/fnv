#pragma once

#include "bscore/memorymanager.h"

enum GAMEDATA_STATUS : int {
    GAMEDATA_STATUS_NOT_READY = 0x0000,
    GAMEDATA_STATUS_OK = 0x0001,
    GAMEDATA_STATUS_ERROR = 0x0002,
    GAMEDATA_STATUS_FULL = 0x0003,
};

class BSGameDataSystemUtility { /* Size=0x850 */

public:
    virtual ~BSGameDataSystemUtility();
    virtual void Initialize();
    virtual void Destroy() {}
    bool QActive();
    bool QNewGameData() const;
    virtual void CheckSpace(int) {}
    virtual void DataInit(int) {}
    virtual void DoMessage(const char *) {}
    int QFreeSpaceKB() const;
    GAMEDATA_STATUS QStatus() const;
    const char *QGameDataDir() const;
    const char *QContentInfoDir() const;
    BSGameDataSystemUtility(const BSGameDataSystemUtility &);
    BSGameDataSystemUtility &operator=(const BSGameDataSystemUtility &);

    static BSGameDataSystemUtility &QInstance();

    BS_MEM_OVERLOADS

protected:
    BSGameDataSystemUtility();
    bool bIsActive; // 0x004
    bool bNewGameData; // 0x005
    GAMEDATA_STATUS eGameDataStatus_; // 0x008
    char cGameDataDir[1055]; // 0x00c
    char cContentInfoDir[1055]; // 0x42b
    int iFreeSpaceKB_; // 0x84c
};
