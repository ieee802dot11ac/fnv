#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesform.h"

class TESTexture : public BaseFormComponent {
public:
    TESTexture(const TESTexture &);
    TESTexture();
    ~TESTexture();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save(CHUNK_ID);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    unsigned int GetTextureNameLength() const;
    const char *GetTextureName() const;
    void SetTextureName(const char *);
    virtual unsigned int GetMaxAllowedSize();
    virtual const char *GetAsNormalFile(BSStringT<char> &) const;
    virtual const char *GetAsSpecularFile(BSStringT<char> &) const;
    virtual char *GetDefaultPath() const;
    TESTexture &operator=(const TESTexture &);

    static unsigned int GetTextureNameLength(TESForm *);
    static const char *GetTextureName(TESForm *, TESObjectREFR *);
    static void GetAsNormalFile(const char *, char *);
    static const char *GetAsNormalFile(BSStringT<char> &, const char *);
    static const char *NormalFileToRegularFile(BSStringT<char> &, const char *);
    static void GetAsSpecularFile(const char *, char *);
    static const char *GetAsSpecularFile(BSStringT<char> &, const char *);
    static void GetAsSkinFile(const char *, char *);
    static bool IsTextureChunk(CHUNK_ID);
    static void LoadTextureChunk(TESTexture *, TESFile *);
    static const char *GetMessageIconName(TESForm *, TESObjectREFR *);

protected:
    BSStringT<char> TextureName; // 0x4
};
