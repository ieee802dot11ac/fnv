#pragma once

#include "fallout/misc/saveload/bgschangeflags.h"
#include "fallout/misc/saveload/bgssavegamebuffer.h"
#include "fallout/misc/saveload/bgssaveloadstructs.h"
#include "fallout_shared/tesform.h"

class BGSSaveFormBuffer : public BGSSaveGameBuffer {
    BGSSaveFormBuffer(const BGSSaveFormBuffer &);
    BGSSaveFormBuffer();
    // void Save(BGSSaveLoadFile*);
    void SetHeader(unsigned int, BGSChangeFlags, ENUM_FORM_ID, unsigned char);
    BGSChangeFlags GetChangeFlags();
    void SetChangeFlags(BGSChangeFlags);
    void AddChange(int);
    void RemoveChange(int);
    ENUM_FORM_ID GetFormType();
    unsigned char GetVersion();
    void SetForm(TESForm *);
    virtual TESForm *GetForm();
    virtual TESObjectREFR *GetReference();
    virtual Actor *GetActor();
    unsigned int GetOverhead();
    ~BGSSaveFormBuffer();

protected:
    BGSSaveLoadFormHeader Header; // 0x14
    TESForm *pForm; // 0x20
};
