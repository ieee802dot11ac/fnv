#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tesmodel.h"
#include "fallout_shared/testexture.h"

class TESHair : public TESForm, public TESFullName, public TESModel, public TESTexture {
public:
    TESHair(const TESHair &);
    TESHair();
    virtual ~TESHair();
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
    bool IsFixedColor();
    void SetFixedColor(bool);
    bool CanBeHairForNPC(class TESNPC *);

protected:
    char cFlags; // 0x58
};
