#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/tesicon.h"
class BGSMenuIcon : public TESForm, public TESIcon {
public:
    BGSMenuIcon(const BGSMenuIcon &);
    BGSMenuIcon();
    virtual ~BGSMenuIcon();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
};
