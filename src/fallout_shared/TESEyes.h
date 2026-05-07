#pragma once

#include "fallout_shared/tesfullname.h"
#include "fallout_shared/testexture.h"

class TESEyes : public TESForm, public TESFullName, public TESTexture {
public:
    TESEyes(const TESEyes &);
    TESEyes();
    virtual ~TESEyes();
    virtual void InitializeData();
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    bool IsPlayable();
    void SetPlayable(bool);
    bool CanBeMale();
    void SetCanBeMale(bool);
    bool CanBeFemale();
    void SetCanBeFemale(bool);
    bool CanBeEyesForNPC(class TESNPC *);

protected:
    char cFlags; // 0x40
};
