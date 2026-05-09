#pragma once

#include "fallout_shared/tessound.h"

class BGSPickupPutdownSounds : public BaseFormComponent {
public:
    BGSPickupPutdownSounds(const BGSPickupPutdownSounds &);
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save();
    void Load(TESFile *);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    void InitItem(TESForm *);
    TESSound *GetPickupSound();
    TESSound *GetPutdownSound();
    void SetPickupSound(TESSound *);
    void SetPutdownSound(TESSound *);

    static TESSound *GetPickupSound(TESForm *);
    static TESSound *GetPutdownSound(TESForm *);

private:
    TESSound *pPickupSound; // 0x4
    TESSound *pPutdownSound; // 0x8
};
