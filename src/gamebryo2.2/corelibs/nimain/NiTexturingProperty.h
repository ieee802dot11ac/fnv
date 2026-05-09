#pragma once

#include "nimain/NiProperty.h"
#include "nimain/NiTexture.h"
#include "nimain/NiTextureTransform.h"
#include "nisystem/NiFile.h"

class NiTexturingProperty : public NiProperty {
public:
    enum ApplyMode {
        APPLY_REPLACE = 0x0000,
        APPLY_DECAL = 0x0001,
        APPLY_MODULATE = 0x0002,
        APPLY_DEPRECATED = 0x0003,
        APPLY_DEPRECATED2 = 0x0004,
        APPLY_MAX_MODES = 0x0005,
    };
    enum ClampMode {
        CLAMP_S_CLAMP_T = 0x0000,
        CLAMP_S_WRAP_T = 0x0001,
        WRAP_S_CLAMP_T = 0x0002,
        WRAP_S_WRAP_T = 0x0003,
        CLAMP_MAX_MODES = 0x0004,
    };
    enum FilterMode {
        FILTER_NEAREST = 0x0000,
        FILTER_BILERP = 0x0001,
        FILTER_TRILERP = 0x0002,
        FILTER_NEAREST_MIPNEAREST = 0x0003,
        FILTER_NEAREST_MIPLERP = 0x0004,
        FILTER_BILERP_MIPNEAREST = 0x0005,
        FILTER_ANISO = 0x0006,
        FILTER_MAGLERP_MINANISO = 0x0007,
        FILTER_MAX_MODES = 0x0008,
    };
    enum MapClassID {
        MAP_CLASS_BASE = 0x0000,
        MAP_CLASS_BUMP = 0x0001,
        MAP_CLASS_PARALLAX = 0x0002,
        MAP_CLASS_SHADER = 0x0003,
        MAP_CLASS_MAX = 0x0004,
    };
    enum MapEnum {
        BASE_INDEX = 0x0000,
        DARK_INDEX = 0x0001,
        DETAIL_INDEX = 0x0002,
        GLOSS_INDEX = 0x0003,
        GLOW_INDEX = 0x0004,
        BUMP_INDEX = 0x0005,
        NORMAL_INDEX = 0x0006,
        PARALLAX_INDEX = 0x0007,
        DECAL_BASE = 0x0008,
        SHADER_BASE = 0x0009,
        INDEX_MAX = 0x000a,
    };

    class Map {
    public:
        Map(const NiTexturingProperty::Map &);
        Map(NiTexture *,
            uint,
            NiTexturingProperty::ClampMode,
            NiTexturingProperty::FilterMode,
            NiTextureTransform *);
        Map();
        virtual ~Map();
        bool operator==(const NiTexturingProperty::Map &) const;
        bool operator!=(const NiTexturingProperty::Map &) const;
        NiTexture *GetTexture() const;
        void SetTexture(NiTexture *);
        NiTexturingProperty::ClampMode GetClampMode() const;
        void SetClampMode(NiTexturingProperty::ClampMode);
        NiTexturingProperty::FilterMode GetFilterMode() const;
        void SetFilterMode(NiTexturingProperty::FilterMode);
        uint GetTextureIndex() const;
        void SetTextureIndex(uint);
        const NiTextureTransform *GetTextureTransform() const;
        NiTextureTransform *GetTextureTransform();
        void SetTextureTransform(NiTextureTransform *);
        bool IsEqual(NiTexturingProperty::Map *);
        virtual void LoadBinary(NiStream &);
        virtual void SaveBinary(NiStream &);
        virtual NiTexturingProperty::MapClassID GetClassID() const;

    protected:
        u16 m_uFlags; // 0x4
        NiPointer<NiTexture> m_spTexture; // 0x8
        NiTextureTransform *m_pkTextureTransform; // 0xc

        void SetField(u16, u16, u16);
        u16 GetField(u16, u16) const;
        void SetBit(bool, u16);
        bool GetBit(u16) const;
    };
    class BumpMap : public Map {
    public:
        BumpMap(const NiTexturingProperty::BumpMap &);
        BumpMap(
            NiTexture *,
            uint,
            NiTexturingProperty::ClampMode,
            NiTexturingProperty::FilterMode,
            float,
            float,
            float,
            float,
            float,
            float
        );
        BumpMap();
        float GetLumaScale() const;
        void SetLumaScale(float);
        float GetLumaOffset() const;
        void SetLumaOffset(float);
        float GetBumpMat00() const;
        void SetBumpMat00(float);
        float GetBumpMat01() const;
        void SetBumpMat01(float);
        float GetBumpMat10() const;
        void SetBumpMat10(float);
        float GetBumpMat11() const;
        void SetBumpMat11(float);
        virtual ~BumpMap();
        bool operator==(const NiTexturingProperty::BumpMap &) const;
        bool operator!=(const NiTexturingProperty::BumpMap &) const;
        bool IsEqual(NiTexturingProperty::BumpMap *);
        virtual void LoadBinary(NiStream &);
        virtual void SaveBinary(NiStream &);
        virtual NiTexturingProperty::MapClassID GetClassID() const;

    protected:
        float m_fLumaScale; // 0x10
        float m_fLumaOffset; // 0x14
        float m_fBumpMat00; // 0x18
        float m_fBumpMat01; // 0x1c
        float m_fBumpMat10; // 0x20
        float m_fBumpMat11; // 0x24
    };
    class ParallaxMap : public Map {
    public:
        ParallaxMap(const NiTexturingProperty::ParallaxMap &);
        ParallaxMap(
            NiTexture *,
            uint,
            NiTexturingProperty::ClampMode,
            NiTexturingProperty::FilterMode,
            float
        );
        ParallaxMap();
        float GetOffset() const;
        void SetOffset(float);
        virtual ~ParallaxMap();
        bool operator==(const NiTexturingProperty::ParallaxMap &) const;
        bool operator!=(const NiTexturingProperty::ParallaxMap &) const;
        bool IsEqual(NiTexturingProperty::ParallaxMap *);
        virtual void LoadBinary(NiStream &);
        virtual void SaveBinary(NiStream &);
        virtual NiTexturingProperty::MapClassID GetClassID() const;

    protected:
        float m_fOffset; // 0x10
    };
    class ShaderMap : public Map {
    public:
        ShaderMap(const NiTexturingProperty::ShaderMap &);
        ShaderMap(
            NiTexture *,
            uint,
            NiTexturingProperty::ClampMode,
            NiTexturingProperty::FilterMode,
            uint
        );
        ShaderMap();
        uint GetID() const;
        void SetID(uint);
        virtual ~ShaderMap();
        bool operator==(const NiTexturingProperty::ShaderMap &) const;
        bool operator!=(const NiTexturingProperty::ShaderMap &) const;
        bool IsEqual(NiTexturingProperty::ShaderMap *);
        virtual void LoadBinary(NiStream &);
        virtual void SaveBinary(NiStream &);
        virtual NiTexturingProperty::MapClassID GetClassID() const;

    protected:
        uint m_uiID; // 0x10
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiTexturingProperty(const NiTexturingProperty &);
    NiTexturingProperty(NiPixelData *, const NiFixedString &, NiTexture::FormatPrefs &);
    NiTexturingProperty(const char *, NiFile *);
    NiTexturingProperty();
    virtual ~NiTexturingProperty();
    NiTexturingProperty::Map *GetBaseMap();
    const NiTexturingProperty::Map *GetBaseMap() const;
    void SetBaseMap(NiTexturingProperty::Map *);
    NiTexturingProperty::Map *GetDarkMap();
    const NiTexturingProperty::Map *GetDarkMap() const;
    void SetDarkMap(NiTexturingProperty::Map *);
    NiTexturingProperty::Map *GetDetailMap();
    const NiTexturingProperty::Map *GetDetailMap() const;
    void SetDetailMap(NiTexturingProperty::Map *);
    NiTexturingProperty::Map *GetGlossMap();
    const NiTexturingProperty::Map *GetGlossMap() const;
    void SetGlossMap(NiTexturingProperty::Map *);
    NiTexturingProperty::Map *GetGlowMap();
    const NiTexturingProperty::Map *GetGlowMap() const;
    void SetGlowMap(NiTexturingProperty::Map *);
    NiTexturingProperty::BumpMap *GetBumpMap();
    const NiTexturingProperty::BumpMap *GetBumpMap() const;
    void SetBumpMap(NiTexturingProperty::BumpMap *);
    NiTexturingProperty::Map *GetNormalMap();
    const NiTexturingProperty::Map *GetNormalMap() const;
    void SetNormalMap(NiTexturingProperty::Map *);
    NiTexturingProperty::ParallaxMap *GetParallaxMap();
    const NiTexturingProperty::ParallaxMap *GetParallaxMap() const;
    void SetParallaxMap(NiTexturingProperty::ParallaxMap *);
    NiTexturingProperty::Map *GetDecalMap(uint);
    const NiTexturingProperty::Map *GetDecalMap(uint) const;
    void SetDecalMap(uint, NiTexturingProperty::Map *);
    uint GetDecalArrayCount() const;
    uint GetDecalMapCount() const;
    NiTexturingProperty::ShaderMap *GetShaderMap(uint);
    const NiTexturingProperty::ShaderMap *GetShaderMap(uint) const;
    void SetShaderMap(uint, NiTexturingProperty::ShaderMap *);
    uint GetShaderArrayCount() const;
    uint GetShaderMapCount() const;
    NiTexturingProperty::ApplyMode GetApplyMode() const;
    void SetApplyMode(NiTexturingProperty::ApplyMode);
    bool IsEqualFast(const NiTexturingProperty &) const;
    virtual int Type() const;
    bool IsMultiTexture() const;
    NiTexture *GetBaseTexture() const;
    void SetBaseTexture(NiTexture *);
    NiTexturingProperty::ClampMode GetBaseClampMode() const;
    void SetBaseClampMode(NiTexturingProperty::ClampMode);
    NiTexturingProperty::FilterMode GetBaseFilterMode() const;
    void SetBaseFilterMode(NiTexturingProperty::FilterMode);
    uint GetBaseTextureIndex() const;
    void SetBaseTextureIndex(uint);
    NiTextureTransform *GetBaseTextureTransform() const;
    void SetBaseTextureTransform(NiTextureTransform *);
    const NiTPrimitiveArray<NiTexturingProperty::Map *> &GetMaps() const;
    void SetMap(uint, NiTexturingProperty::Map *);
    bool ValidMapExists(NiTexturingProperty::MapEnum, uint) const;

    static NiObject *CreateObject();
    static int GetType();
    static NiTexturingProperty *GetDefault();
    static void _SDMInit();
    static void _SDMShutdown();
    static char *GetViewerString(const char *, NiTexturingProperty::ApplyMode);
    static char *GetViewerString(const char *, NiTexturingProperty::FilterMode);
    static char *GetViewerString(const char *, NiTexturingProperty::ClampMode);
    static const NiFixedString &GetMapNameFromID(uint);
    static bool GetMapIDFromName(const NiFixedString &, uint &);

protected:
    void CopyMembers(NiTexturingProperty *, NiCloningProcess &);
    void SetField(u16, u16, u16);
    u16 GetField(u16, u16) const;
    void SetBit(bool, u16);
    bool GetBit(u16) const;
    void SetMultiTexture(NiTexturingProperty::Map *);
    void InitializeDecalCount();
    void IncrementDecalCount();
    void DecrementDecalCount();

    static NiPointer<NiTexturingProperty> ms_spDefault;
    static NiFixedString ms_akMapIDtoNames[10];

    u16 m_uFlags; // 0x18
    NiTPrimitiveArray<NiTexturingProperty::Map *> m_kMaps; // 0x1c
    NiTPrimitiveArray<NiTexturingProperty::ShaderMap *> *m_pkShaderMaps; // 0x2c
};
