#pragma once

#include "bscore/memorymanager.h"
class ActiveEffect;
class MagicCaster;
class MagicItem;

struct SpellDispelData {
    MagicItem *pSpell; // 0x0
    MagicCaster *pCaster; // 0x4
    ActiveEffect *pActiveEffect; // 0x8

    SpellDispelData();
    BS_MEM_OVERLOADS
};
