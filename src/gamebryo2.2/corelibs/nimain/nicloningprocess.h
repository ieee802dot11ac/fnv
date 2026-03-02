#pragma once

#include <types.h>
#include "niobjectnet.h"

class NiCloningProcess {
public:
    NiCloningProcess(uint);
    ~NiCloningProcess();
    // NiTPointerMap<NiObject *, NiObject *> *m_pkCloneMap; // 0x0
    // NiTPointerMap<NiObject *, bool> *m_pkProcessMap; // 0x4
    NiObjectNET::CopyType m_eCopyType; // 0x8
    char m_cAppendChar; // 0xC
};
