#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

class TESHealthForm : public BaseFormComponent {
public:
    TESHealthForm();
    ~TESHealthForm();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    virtual uint GetFormHealth() { return iHealth; }
    void SetFormHealth(uint);

    static TESHealthForm *GetFormAsHealthForm(TESForm *);
    static uint GetFormHealth(TESForm *);

private:
    uint iHealth; // 0x4
};
