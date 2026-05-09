#pragma once

#include "nimain/NiObject.h"
#include "nimain/NiRenderedTexture.h"

class NiRenderTargetGroup;
class BSRenderedTexture;
class NiDepthStencilBuffer;

class BSRenderedTexture : public NiObject {
public:
    BSRenderedTexture(const BSRenderedTexture &);
    BSRenderedTexture(
        NiRenderedTexture *, NiRenderedTexture *, bool, NiDepthStencilBuffer *
    );
    BSRenderedTexture(NiRenderedTexture *, bool, NiDepthStencilBuffer *);
    virtual ~BSRenderedTexture();
    NiRenderedTexture *GetTexture(int);
    operator NiRenderedTexture *();
    NiRenderTargetGroup *GetGroup();
    operator NiRenderTargetGroup *();
    void ClearRenderedTextures();
    void RestoreEDRAM();
    void UsePreRestoreGroup();
    uint GetWidth(int);
    uint GetHeight(int);

    static BSRenderedTexture *
    Create(const NiFixedString &, Ni2DBuffer *, bool, NiDepthStencilBuffer *);
    static BSRenderedTexture *Create(
        const NiFixedString &,
        uint,
        uint,
        Ni2DBuffer::MultiSamplePreference,
        bool,
        NiDepthStencilBuffer *,
        NiRenderedTexture *,
        uint
    );
    static BSRenderedTexture *Create(
        const NiFixedString &,
        uint,
        uint,
        NiTexture::FormatPrefs &,
        Ni2DBuffer::MultiSamplePreference,
        bool,
        NiDepthStencilBuffer *,
        NiRenderedTexture *,
        uint
    );
    static void BeginTexture(BSRenderedTexture *, uint);
    static void Start(uint, NiRenderTargetGroup *);
    static void Start(uint, BSRenderedTexture *);
    static void BeginDefault(uint);
    static void Begin(NiRenderTargetGroup *, uint);
    static void End();
    static void EndAll();
    static void Stop();
    static void StartOffscreen(uint, NiRenderTargetGroup *);
    static void StopOffscreen();
    static NiRenderTargetGroup *GetCurrent();
    static uint QNumTargets();
    static bool QDefaultActive();
    static bool QOutsideFrame();
    static NiDepthStencilBuffer *
    GetDepthStencilBuffer(NiRenderedTexture *, NiDepthStencilBuffer *);

protected:
    NiPointer<NiRenderTargetGroup> spGroup[6]; // 0x08
    NiPointer<NiRenderTargetGroup> spPreRestoreGroup; // 0x20
    NiPointer<NiRenderTargetGroup> spRestoreGroup; // 0x24
    NiPointer<NiRenderTargetGroup> spPostRestoreGroup; // 0x28
public:
    int iAliasedType; // 0x2c
protected:
    NiPointer<NiRenderedTexture> spTexture[4]; // 0x30

    static uint iNumTargets;
    static NiPointer<NiRenderTargetGroup> spRenderTargets[10];
    static const int MAX_RENDER_TARGETS;

    static void UseGroup(NiRenderTargetGroup *, uint);
    static void Push(NiRenderTargetGroup *);
    static void Pop();
};
