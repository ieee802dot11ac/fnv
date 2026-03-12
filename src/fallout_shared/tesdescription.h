#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesform.h"

class TESDescription : public BaseFormComponent {
public:
    TESDescription(const TESDescription &);
    TESDescription();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    unsigned int GetDescriptionLength();
    virtual const char *GetDescription(TESForm *, CHUNK_ID);
    unsigned int GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned int);
    void LoadDescription(TESForm *, CHUNK_ID);
    TESDescription &operator=(const TESDescription &);

    static void SaveDescriptionData(TESDescription *, CHUNK_ID);
    static void LoadDescriptionData(TESDescription *, TESFile *);
    static unsigned int GetDescriptionLength(TESForm *);
    static const char *GetDescription(TESForm *);

protected:
    void SetDescription(const char *);

private:
    void UnLoadDescription();
    unsigned int lFileOffset; // 0x4
    static BSStringT<char> cDescription;
    static TESDescription *pCurrentDescription;
};
