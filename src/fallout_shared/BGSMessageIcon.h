#pragma once

#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesfile.h"
#include "fallout_shared/tesicon.h"
class BGSMessageIcon : public BaseFormComponent {
public:
    BGSMessageIcon(const BGSMessageIcon &);
    BGSMessageIcon();
    ~BGSMessageIcon();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save(CHUNK_ID);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    TESIcon *GetIcon();
    const char *GetMessageIconTextureName();
    uint GetMessageIconTextureNameLength() const;
    void SetMessageIconTextureName(const char *);

    static void LoadMessageIcon(BGSMessageIcon *, TESFile *);

private:
    TESIcon Icon; // 0x4
};
