#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/testexture.h"

class TESEyes : public TESForm, public TESFullName, public TESTexture {
public:
    TESEyes(const TESEyes &);
    TESEyes();
    virtual ~TESEyes() {}
    virtual void InitializeData();
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    bool IsPlayable();
    void SetPlayable(bool abPlayable) {
        if (abPlayable)
            cFlags |= BIT(0);
        else
            cFlags &= ~BIT(0);
    }
    bool CanBeMale() { return ~cFlags & BIT(1); }
    void SetCanBeMale(bool abMale) {
        if (abMale)
            cFlags &= ~BIT(1);
        else
            cFlags |= BIT(1);
    }
    bool CanBeFemale() { return ~cFlags & BIT(2); }
    void SetCanBeFemale(bool abFemale) {
        if (abFemale)
            cFlags &= ~BIT(2);
        else
            cFlags |= BIT(2);
    }
    bool CanBeEyesForNPC(class TESNPC *);

    BS_MEM_OVERLOADS

protected:
    char cFlags; // 0x40
};
