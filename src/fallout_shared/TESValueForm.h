#pragma once

#include "fallout/misc/saveload/bgssaveformbuffer.h"
#include "fallout_shared/baseformcomponent.h"

class TESValueForm : public BaseFormComponent {
public:
    TESValueForm(const TESValueForm &);
    TESValueForm();
    ~TESValueForm();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    int GetFormValue();
    void SetFormValue(int);
    virtual unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);

    static int GetFormValue(TESForm *);

private:
    uint iValue; // 0x4
};
