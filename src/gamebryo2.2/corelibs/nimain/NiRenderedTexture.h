#pragma once

#include "d3d9i/d3d9types.h"
#include "nimain/Ni2DBuffer.h"
#include "nimain/NiTexture.h"

class NiRenderer;

class NiRenderedTexture : public NiTexture {
public:
    static const NiRTTI ms_RTTI;
    static bool bStaticRenderedTexture;
    static bool bStaticForceD3DFormat;
    static D3DFORMAT iStaticForcedD3DFormat;
    static bool bStaticForceEDRAMFormat;
    static D3DFORMAT iStaticForcedEDRAMFormat;

    virtual const NiRTTI *GetRTTI() const;
    virtual uint GetWidth() const;
    virtual uint GetHeight() const;
    virtual Ni2DBuffer *GetBuffer() const;
    uint QAliasOffset() const;
    NiRenderedTexture *QAliasTexture() const;
    void SetAliasOffset(uint);
    void SetAliasTexture(NiRenderedTexture *);
    uint ComputeAliasSize();
    NiRenderedTexture(const NiRenderedTexture &);
    virtual ~NiRenderedTexture();

    static NiRenderedTexture *Create(
        const NiFixedString &,
        Ni2DBuffer *,
        NiRenderer *,
        Ni2DBuffer::MultiSamplePreference
    );
    static NiRenderedTexture *Create(
        const NiFixedString &,
        uint,
        uint,
        NiRenderer *,
        NiTexture::FormatPrefs &,
        Ni2DBuffer::MultiSamplePreference,
        NiRenderedTexture *,
        uint
    );
    static NiRenderedTexture *Create(
        const NiFixedString &,
        uint,
        uint,
        NiRenderer *,
        Ni2DBuffer::MultiSamplePreference,
        NiRenderedTexture *,
        uint
    );

protected:
    NiRenderedTexture();

    NiPointer<Ni2DBuffer> m_spBuffer; // 0x30
    uint uiAliasOffset; // 0x34
    NiRenderedTexture *pAliasTexture; // 0x38
public:
    Ni2DBuffer::MultiSamplePreference eMSAA; // 0x3c
    bool bRenderedTexture; // 0x40
    bool bForceD3DFormat; // 0x41
    D3DFORMAT iForcedD3DFormat; // 0x44

    static NiTexture::FormatPrefs ms_kDefaultPrefs;
};
