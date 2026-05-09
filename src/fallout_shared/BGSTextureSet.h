#pragma once

#include "fallout_shared/DecalData.h"
#include "fallout_shared/tesobject.h"
#include "fallout_shared/testexture.h"
#include "bsshader/BSShaderProperty.h"
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
    enum TexType {
        TEXTYPE_BASE = 0x0000,
        TEXTYPE_NORMAL = 0x0001,
        TEXTYPE_ENV_MASK = 0x0002,
        TEXTYPE_GLOW = 0x0003,
        TEXTYPE_HEIGHT = 0x0004,
        TEXTYPE_ENV = 0x0005,
        TEXTYPE_SPECULAR = 0x0006,
        TEXTYPE_COUNT = 0x0007,
    };

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
    // void QueueTextureSet(IO_TASK_PRIORITY, QueuedFile *, bool);
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
