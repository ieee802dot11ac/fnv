#pragma once

#include "nimain/NiPalette.h"
#include "nimain/NiPixelFormat.h"
class NiPixelData : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiPixelData(const NiPixelData &);
    NiPixelData(uint, uint, const NiPixelFormat &, uint, uint);
    virtual ~NiPixelData();
    uint GetNumMipmapLevels() const;
    uint GetNumFaces() const;
    uint GetWidth(uint, uint) const;
    uint GetHeight(uint, uint) const;
    uint GetPixelStride() const;
    uint GetSizeInBytes(uint, uint) const;
    int GetOffsetInBytes(uint, uint) const;
    uint GetTotalSizeInBytes() const;
    uint GetFaceSizeInBytes() const;
    const NiPixelFormat &GetPixelFormat() const;
    void SetPalette(NiPalette *);
    NiPalette *GetPalette();
    const NiPalette *GetPalette() const;
    u8 *GetPixels(uint, uint);
    const u8 *GetPixels(uint, uint) const;
    void MarkAsChanged();
    uint GetRevisionID() const;
    u8 *operator()(uint, uint, uint, uint);
    const u8 *operator()(uint, uint, uint, uint) const;
    void SetNoConvert(bool);
    bool QNoConvert();

    static NiObject *CreateObject();
    static uint ComputeMipmapLevels(uint, uint);

protected:
    NiPixelData();

    NiPixelFormat m_kPixelFormat; // 0x08
    NiPointer<NiPalette> m_spPalette; // 0x4c
    u8 *m_pucPixels; // 0x50
    uint *m_puiWidth; // 0x54
    uint *m_puiHeight; // 0x58
    uint *m_puiOffsetInBytes; // 0x5c
    uint m_uiMipmapLevels; // 0x60
    uint m_uiPixelStride; // 0x64
    uint m_uiRevID; // 0x68
    uint m_uiFaces; // 0x6c
    bool bNoConvert; // 0x70

    void AllocateData(uint, uint, uint);
    void FreeData();
};
