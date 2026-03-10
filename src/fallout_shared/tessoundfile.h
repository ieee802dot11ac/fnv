#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesform.h"

class TESSoundFile : public BaseFormComponent {
public:
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    unsigned int GetSoundFileLength();
    const char *GetSoundFile();
    virtual void SetSoundFile(const char *);
    TESSoundFile(const TESSoundFile &);
    TESSoundFile();
    ~TESSoundFile();

    static unsigned int GetSoundFileLength(TESForm *);
    static const char *GetSoundFile(TESForm *);

protected:
    BSStringT<char> cSoundFile; // 0x4
};
