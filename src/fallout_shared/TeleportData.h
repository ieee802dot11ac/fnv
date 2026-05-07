#pragma once

#include "bscore/BSSimpleArray.h"
#include "fallout_shared/tesobjectrefr.h"
#include "nimain/NiPoint3.h"

struct ParentSpaceNode { /* Size=0xc */
    bool bWorldSpace; // 0x0
    class TESWorldSpace *pWorldSpace; // 0x4
    TESObjectCELL *pInteriorCell; // 0x8
};

struct TeleportLink {
    TESObjectREFR *pDoor; // 0x0
    NiPoint3 DoorTeleportLocation; // 0x4
};

class TeleportPath {
public:
    BSSimpleArray<ParentSpaceNode, 1024> Spaces; // 0x00
    BSSimpleArray<TeleportLink, 1024> Doors; // 0x10
    NiPoint3 Start; // 0x20
    NiPoint3 End; // 0x2c

    TeleportPath(const TeleportPath &);
    TeleportPath();
    ~TeleportPath();
    void Clear();
    float ComputeLength();
};
