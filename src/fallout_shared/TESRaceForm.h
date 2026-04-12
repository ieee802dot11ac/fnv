#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

class TESRaceForm : public BaseFormComponent {
public:
    TESRaceForm(const TESRaceForm &);
    TESRaceForm();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    void InitItem(TESForm *);
    TESRace *GetFormRace() const;
    const char *GetFormRaceEditorID();
    void SetFormRace(TESRace *);

    static TESRace *GetFormRace(TESForm *);
    static const char *GetFormRaceEditorID(TESForm *);

private:
    TESRace *pFormRace;
};
