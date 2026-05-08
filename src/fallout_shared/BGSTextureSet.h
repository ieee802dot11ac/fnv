#pragma once

#include "fallout_shared/tesobject.h"
#include "fallout_shared/testexture.h"
#include "nimain/NiTexture.h"

class BSTextureSet : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual const NiRTTI *GetRTTI() const;
    virtual const char *GetTextureFilename(BSShaderProperty::TextureTypeEnum) const;
    virtual void
    GetTexture(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture> &) const;
    virtual void SetTextureFilename(BSShaderProperty::TextureTypeEnum, const char *);
    BSTextureSet(const BSTextureSet &);
    BSTextureSet();
    virtual ~BSTextureSet();
};

class BSShaderTextureSet : public BSTextureSet {
public:
    static const NiRTTI ms_RTTI;

    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual const NiRTTI *GetRTTI() const;
    virtual const char *GetTextureFilename(BSShaderProperty::TextureTypeEnum) const;
    virtual void
    GetTexture(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture> &) const;
    virtual void SetTextureFilename(BSShaderProperty::TextureTypeEnum, const char *);
    BSShaderTextureSet(const BSShaderTextureSet &);
    BSShaderTextureSet();
    virtual ~BSShaderTextureSet();

    static NiObject *CreateObject();

protected:
    BSStringT<char> pTextureNames[7]; // 0x8
};

class BGSTextureSet : public TESBoundObject, public BSTextureSet {
public:
    BGSTextureSet(const BGSTextureSet &);
    BGSTextureSet();
    virtual ~BGSTextureSet();
    virtual void InitializeData();
    virtual void ClearData();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual NiAVObject *Clone3D(TESObjectREFR *);
    virtual void UnClone3D(TESObjectREFR *);
    bool HasDecalData();
    DecalData *GetDecalData();
    TESTexture *GetTESTexture(BGSTextureSet::TexType);
    void SetBGSTextureFilename(BGSTextureSet::TexType, const char *);
    BSTextureSet *GetAsShaderTextureSet();
    BSShaderTextureSet *CreateShaderTextureSet();
    virtual const char *GetTextureFilename(BSShaderProperty::TextureTypeEnum) const;
    virtual void
    GetTexture(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture> &) const;
    virtual void SetTextureFilename(BSShaderProperty::TextureTypeEnum, const char *);
    void QueueTextureSet(IO_TASK_PRIORITY, QueuedFile *, bool);
    bool QHasSpecular();
    void SetHasSpecular(bool);

    static void CreateNullTextureSet();
    static void ClearNullTextureSet();
    static BGSTextureSet *GetNullTextureSet();

protected:
    TESTexture pTextures[7]; // 0x48
    DecalData *pDecalData; // 0x9c
    u16 iFlags; // 0xa0
    BSFileEntry *pTextureFileEntries[7]; // 0xa4

    static CHUNK_ID pTextTypeChunk[7];
    static BGSTextureSet *pNullTextureSet;
};
