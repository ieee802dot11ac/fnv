#pragma once

#include "nimain/nistream.h"
#include "types.h"
class NiPixelFormat {
public:
    enum Component {
        COMP_RED = 0x0000,
        COMP_GREEN = 0x0001,
        COMP_BLUE = 0x0002,
        COMP_ALPHA = 0x0003,
        COMP_COMPRESSED = 0x0004,
        COMP_OFFSET_U = 0x0005,
        COMP_OFFSET_V = 0x0006,
        COMP_OFFSET_W = 0x0007,
        COMP_OFFSET_Q = 0x0008,
        COMP_LUMA = 0x0009,
        COMP_HEIGHT = 0x000a,
        COMP_VECTOR_X = 0x000b,
        COMP_VECTOR_Y = 0x000c,
        COMP_VECTOR_Z = 0x000d,
        COMP_PADDING = 0x000e,
        COMP_INTENSITY = 0x000f,
        COMP_INDEX = 0x0010,
        COMP_DEPTH = 0x0011,
        COMP_STENCIL = 0x0012,
        COMP_EMPTY = 0x0013,
        COMP_MAX = 0x0014,
        NUM_COMPS = 0x0004,
    };

    enum Format {
        FORMAT_RGB = 0x0000,
        FORMAT_RGBA = 0x0001,
        FORMAT_PAL = 0x0002,
        FORMAT_PALALPHA = 0x0003,
        FORMAT_DXT1 = 0x0004,
        FORMAT_DXT3 = 0x0005,
        FORMAT_DXT5 = 0x0006,
        FORMAT_RGB24NONINTERLEAVED = 0x0007,
        FORMAT_BUMP = 0x0008,
        FORMAT_BUMPLUMA = 0x0009,
        FORMAT_RENDERERSPECIFIC = 0x000a,
        FORMAT_ONE_CHANNEL = 0x000b,
        FORMAT_TWO_CHANNEL = 0x000c,
        FORMAT_THREE_CHANNEL = 0x000d,
        FORMAT_FOUR_CHANNEL = 0x000e,
        FORMAT_DEPTH_STENCIL = 0x000f,
        FORMAT_UNKNOWN = 0x0010,
        FORMAT_MAX = 0x0011,
    };

    enum Representation {
        REP_FIXED = 0x0000,
        REP_HALF = 0x0001,
        REP_FLOAT = 0x0002,
        REP_INDEX = 0x0003,
        REP_COMPRESSED = 0x0004,
        REP_UNKNOWN = 0x0005,
        REP_MAX = 0x0006,
    };

    enum Tiling {
        TILE_NONE = 0x0000,
        TILE_XENON = 0x0001,
        TILE_MAX = 0x0002,
    };

    class NiComponentSpec { /* Size=0xc */
    public:
        Component m_eComponent; // 0x0
        Representation m_eRepresentation; // 0x4
        u8 m_ucBitsPerComponent; // 0x8
        bool m_bSigned; // 0x9
    };

    static const NiPixelFormat PAL4;
    static const NiPixelFormat PALA4;
    static const NiPixelFormat PAL8;
    static const NiPixelFormat PALA8;
    static const NiPixelFormat RGB24;
    static const NiPixelFormat RGBA32;
    static const NiPixelFormat BUMP16;
    static const NiPixelFormat BUMPLUMA32;
    static const NiPixelFormat RGBA16;
    static const NiPixelFormat ARGB16;
    static const NiPixelFormat BGRA16;
    static const NiPixelFormat DXT1;
    static const NiPixelFormat DXT3;
    static const NiPixelFormat DXT5;
    static const NiPixelFormat R16;
    static const NiPixelFormat R32;
    static const NiPixelFormat RG32;
    static const NiPixelFormat RG64;
    static const NiPixelFormat RGBA64;
    static const NiPixelFormat RGBA128;
    static const NiPixelFormat I8;
    static const NiPixelFormat A8;
    static const NiPixelFormat BGR233;
    static const NiPixelFormat BGRA2338;
    static const NiPixelFormat RGB555;
    static const NiPixelFormat BGR555;
    static const NiPixelFormat BGR565;
    static const NiPixelFormat RGBA5551;
    static const NiPixelFormat BGRA5551;
    static const NiPixelFormat BGRX5551;
    static const NiPixelFormat BGRA4444;
    static const NiPixelFormat BGRX4444;
    static const NiPixelFormat RGBA1010102;
    static const NiPixelFormat BGRA1010102;
    static const NiPixelFormat RGBA1010102F;
    static const NiPixelFormat GR1616;
    static const NiPixelFormat BGR888;
    static const NiPixelFormat BGRA8888;
    static const NiPixelFormat BGRX8888;
    static const NiPixelFormat RGBX8888;
    static const NiPixelFormat ARGB8888;
    static const NiPixelFormat BUMPLUMA556;
    static const NiPixelFormat PA88;
    static const NiPixelFormat L8;
    static const NiPixelFormat L16;
    static const NiPixelFormat LA88;
    static const NiPixelFormat LA44;
    static const NiPixelFormat BUMPWQ8888;
    static const NiPixelFormat BUMP1616;
    static const NiPixelFormat BUMPW101111;
    static const NiPixelFormat BUMPLUMAX8888;
    static const NiPixelFormat BUMPWA1010102;
    static const NiPixelFormat RENDERERSPECIFICCOMPRESSED;
    static const NiPixelFormat RENDERERSPECIFIC16;
    static const NiPixelFormat RENDERERSPECIFIC32;
    static const NiPixelFormat RENDERERSPECIFIC64;
    static const NiPixelFormat DEPTH16;
    static const NiPixelFormat DEPTH32;
    static const NiPixelFormat STENCILDEPTH115;
    static const NiPixelFormat STENCILDEPTH824;
    static const NiPixelFormat STENCILDEPTH824F;
    static const NiPixelFormat XDEPTH824;
    static const NiPixelFormat STENCILXDEPTH4424;

    NiPixelFormat(
        Format,
        u8,
        Tiling,
        bool,
        uint,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool
    );
    NiPixelFormat(
        Format,
        Component,
        Representation,
        u8,
        Component,
        Representation,
        u8,
        Component,
        Representation,
        u8,
        Component,
        Representation,
        u8
    );
    NiPixelFormat(
        Format,
        Component,
        Representation,
        u8,
        Component,
        Representation,
        u8,
        Component,
        Representation,
        u8
    );
    NiPixelFormat(Format, Component, Representation, u8, Component, Representation, u8);
    NiPixelFormat(Format, Component, Representation, u8);
    NiPixelFormat();
    Format GetFormat() const;
    u8 GetBitsPerPixel() const;
    uint GetRendererHint() const;
    uint GetExtraData() const;
    Tiling GetTiling() const;
    bool GetLittleEndian() const;
    void SetFormat(Format);
    void SetBitsPerPixel(u8);
    void SetRendererHint(uint);
    void SetExtraData(uint);
    void SetTiling(Tiling);
    void SetLittleEndian(bool);
    bool GetComponent(uint, Component &, Representation &, u8 &, bool &) const;
    void SetComponent(uint, Component, Representation, u8, bool);
    uint GetNumComponents() const;
    bool GetPalettized() const;
    bool GetPaletteHasAlpha() const;
    bool GetCompressed() const;
    uint GetMask(Component) const;
    u8 GetBits(Component) const;
    u8 GetShift(Component) const;
    u8 QBitsPerPixel() const;
    bool operator==(const NiPixelFormat &) const;
    bool operator!=(const NiPixelFormat &) const;
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);

    static NiPixelFormat CreateFromRGBAMasks(u8, uint, uint, uint, uint);

protected:
    void InitPixelFormat(
        Format,
        u8,
        Tiling,
        bool,
        uint,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool,
        Component,
        Representation,
        u8,
        bool
    );
    void ConvertOldPixelFormat(Format, u8, uint *);

    void SetField(u8, u8, u8);
    u8 GetField(u8, u8) const;
    void SetBit(bool, u8);
    bool GetBit(u8) const;

    u8 m_uFlags; // 0x00
    u8 m_ucBitsPerPixel; // 0x01
    Format m_eFormat; // 0x04
    Tiling m_eTiling; // 0x08
    uint m_uiRendererHint; // 0x0c
    uint m_uiExtraData; // 0x10
    NiComponentSpec m_akComponents[4]; // 0x14
    static uint CalcMaskSize(uint);
};
