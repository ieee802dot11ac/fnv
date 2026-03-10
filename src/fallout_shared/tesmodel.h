#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesform.h"

class TESTextureList {
public:
    TESTextureList();
    ~TESTextureList();
    bool ClearData();
    void SaveToBuffer(BSHashData *);
    void LoadFromBuffer(BSHashData *, unsigned int, TESForm *, const char *);
    void Save(CHUNK_ID, const char *);
    void Load(TESFile *, TESForm *, const char *);
    void Copy(TESTextureList *);
    unsigned char GetTextureCount();
    BSFileEntry **GetTextureOffsetArray();

protected:
    unsigned char cTextureCount; // 0x0
    BSFileEntry **pTextureOffsetArray; // 0x4
};

class TESModel : public BaseFormComponent {
public:
    TESModel(const TESModel &);
    TESModel();
    virtual ~TESModel();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    //   void Save(CHUNK_ID, CHUNK_ID);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    //   void SaveFlags(CHUNK_ID);
    unsigned int GetModelLength() const;
    virtual const char *GetModel() const;
    virtual void SetModel(const char *);
    void GetDistantModelName(char *);
    //   virtual TESModelTextureSwap* GetAsModelTextureSwap();
    bool GetFacegenModelAvailability();
    char QFlags();
    void SetFlags(char);
    bool QHasFacegenData();
    void SetHasFacegenData(bool);
    unsigned int GetSkinFlags();
    void SetSkinFlags(unsigned int);
    bool ClearTextureList();
    //   TESTextureList* GetTextureList();

    static unsigned int GetModelLength(TESForm *);
    static const char *GetModel(TESForm *);
    static void GetDistantModelName(char *, TESForm *);
    //   static bool IsModelChunk(CHUNK_ID);
    static void LoadModelChunk(TESModel *, TESFile *);
    static void LoadModelTextureChunk(TESModel *, TESFile *);

protected:
    BSStringT<char> cModel; // 0x04
    TESTextureList TextureList; // 0x0c
    unsigned char cFlags; // 0x14
};
