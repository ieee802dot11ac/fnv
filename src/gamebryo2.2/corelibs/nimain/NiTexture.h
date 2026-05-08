#pragma once

#include "nimain/BSDegradePriority.h"
#include "nimain/NiColor.h"
#include "nimain/NiObjectNET.h"
#include "nimain/NiPixelData.h"
#include "nimain/NiPixelFormat.h"
#include "nisystem/NiCriticalSection.h"
class NiTexture : public NiObjectNET {
public:
    class FormatPrefs {
    public:
        enum AlphaFormat {
            NONE = 0x0000,
            BINARY = 0x0001,
            SMOOTH = 0x0002,
            ALPHA_DEFAULT = 0x0003,
        };

        enum MipFlag {
            NO = 0x0000,
            YES = 0x0001,
            MIP_DEFAULT = 0x0002,
        };

        enum PixelLayout {
            PALETTIZED_8 = 0x0000,
            HIGH_COLOR_16 = 0x0001,
            TRUE_COLOR_32 = 0x0002,
            COMPRESSED = 0x0003,
            BUMPMAP = 0x0004,
            PALETTIZED_4 = 0x0005,
            PIX_DEFAULT = 0x0006,
            SINGLE_COLOR_8 = 0x0007,
            SINGLE_COLOR_16 = 0x0008,
            SINGLE_COLOR_32 = 0x0009,
            DOUBLE_COLOR_32 = 0x000a,
            DOUBLE_COLOR_64 = 0x000b,
            FLOAT_COLOR_32 = 0x000c,
            FLOAT_COLOR_64 = 0x000d,
            FLOAT_COLOR_128 = 0x000e,
        };

        PixelLayout m_ePixelLayout; // 0x0
        AlphaFormat m_eAlphaFmt; // 0x4
        MipFlag m_eMipMapped; // 0x8

        FormatPrefs();
    };

    class RendererData : public NiObject {
    public:
        enum CreationFailure {
            NONE = 0x0000,
            GENERIC = 0x80000000,
            NO2DMATCH = 0x80000001,
            NOCUBEMAPMATCH = 0x80000002,
            NOCONVERTER = 0x80000003,
            FAILEDCONVERT = 0x80000004,
            FILENOTFOUND = 0x80000005,
            BADDIMENSIONS = 0x80000006,
            CUBEMAPFAILEDCONVERT = 0x80000007,
            CUBEMAPFILENOTFOUND = 0x80000008,
            CUBEMAPBADDIMENSIONS = 0x80000009,
            CREATEFAIL_COUNT = 0x000a,
        };

        static unsigned int iLoadMethod;

        RendererData(NiTexture *);
        virtual ~RendererData();
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;
        void SetWidth(unsigned int);
        void SetHeight(unsigned int);
        const NiPixelFormat *GetPixelFormat() const;
        BSDegradePriority &QDegradePriority();
        virtual void Upgrade(NiTexture *);
        virtual void Degrade(NiTexture *);
        virtual unsigned int ComputeAliasSize();
        bool GetFlag(unsigned int);
        void SetFlag(unsigned int, bool);

        static void _SDMInit();
        static void _SDMShutdown();
        static void
        SetTextureFailureCallback(NiPixelData *(*)(NiTexture *, CreationFailure));
        static NiPixelData *DefaultTextureFailureCallback(NiTexture *, CreationFailure);
        static void SetTextureReplacementFormat(const NiPixelFormat &);

    protected:
        RendererData();

        NiTexture *m_pkTexture; // 0x08
        uint m_uiWidth; // 0x0c
        uint m_uiHeight; // 0x10
        NiPixelFormat m_kPixelFormat; // 0x14
        BSDegradePriority DegradePriorityRange; // 0x58
        u8 cFlags; // 0x5c

        static NiPixelData *(*ms_pfnTextureFailureCallback)(NiTexture *, CreationFailure);
        static NiPointer<NiPixelData> ms_aspReplacementData[10];
        static NiPixelFormat ms_kReplacementFormat;
        static NiPixelData *
        GetReplacementData(NiTexture *, NiTexture::RendererData::CreationFailure, bool);
        static NiPixelData *MakeDataFromColors(
            const NiColorA &, const NiColorA &, const NiPixelFormat &, unsigned int
        );
        static void ReportDataCreationError(NiTexture::RendererData::CreationFailure);
    };

    static const NiRTTI ms_RTTI;
    static bool bLoadDirectToRenderer;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiTexture(const NiTexture &);
    NiTexture();
    virtual ~NiTexture();
    PRIORITY_STATE QState();
    void SetState(PRIORITY_STATE);
    bool GetFlag(unsigned int);
    void SetFlag(unsigned int, bool);
    virtual void Upgrade();
    virtual void Degrade();
    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;
    virtual const NiFixedString &GetFilename() const;
    virtual unsigned int GetMemorySize();
    const NiTexture::FormatPrefs &GetFormatPreferences() const;
    const NiPixelFormat *GetPixelFormat() const;
    void SetRendererData(NiTexture::RendererData *);
    void ReplaceRendererData(NiTexture::RendererData *);
    NiTexture::RendererData *GetRendererData() const;
    NiTexture *GetListNext();
    NiTexture *GetListPrev();

    static void SetLoadMethod(unsigned int);
    static unsigned int QLoadMethod();
    static bool GetMipmapByDefault();
    static void SetMipmapByDefault(bool);
    static NiTexture *GetListHead();
    static NiTexture *GetListTail();
    static void LockTextureList();
    static void UnlockTextureList();

protected:
    NiTexture::FormatPrefs m_kFormatPrefs; // 0x18
    NiTexture::RendererData *m_pkRendererData; // 0x24
    NiTexture *m_pkPrev; // 0x28
    NiTexture *m_pkNext; // 0x2c
    static NiTexture *ms_pkHead;
    static NiTexture *ms_pkTail;
    static NiCriticalSection ms_kTextureListCriticalSection;
    static bool ms_bMipmapByDefault;
    void AddTextureToList();
    void RemoveTextureFromList();
};
