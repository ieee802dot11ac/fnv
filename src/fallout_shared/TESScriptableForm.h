#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

class Script;

class TESScriptableForm : public BaseFormComponent {
public:
    TESScriptableForm(const TESScriptableForm &);
    TESScriptableForm();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    void InitItem(TESForm *);
    Script *GetFormScript();
    const char *GetFormScriptEditorID();
    void SetFormScript(Script *);

    static Script *GetFormScript(TESForm *);
    static const char *GetFormScriptEditorID(TESForm *);
    static void SetFormScript(TESForm *, Script *);

private:
    Script *pFormScript; // 0x4
    bool bIsInitialized; // 0x8
};
