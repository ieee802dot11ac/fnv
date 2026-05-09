#pragma once

#include "nimain/Ni2DBuffer.h"
#include "nimain/NiObject.h"
#include "nimain/NiPixelFormat.h"
#include "nimain/NiRenderer.h"

class NiDepthStencilBuffer;

class NiRenderTargetGroup : public NiObject {
public:
    class RendererData {
    public:
        virtual ~RendererData();
        RendererData(const NiRenderTargetGroup::RendererData &);
        RendererData();
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiRenderTargetGroup();
    virtual unsigned int GetWidth(unsigned int) const;
    virtual unsigned int GetHeight(unsigned int) const;
    virtual unsigned int GetDepthStencilWidth() const;
    virtual unsigned int GetDepthStencilHeight() const;
    bool HasDepthStencil() const;
    bool IsValid() const;
    bool CheckMSAAPrefConsistency();
    virtual const NiPixelFormat *GetPixelFormat(unsigned int) const;
    virtual const NiPixelFormat *GetDepthStencilPixelFormat() const;
    virtual unsigned int GetBufferCount() const;
    virtual bool AttachBuffer(Ni2DBuffer *, unsigned int);
    virtual bool AttachDepthStencilBuffer(NiDepthStencilBuffer *);
    virtual Ni2DBuffer *GetBuffer(unsigned int) const;
    virtual NiDepthStencilBuffer *GetDepthStencilBuffer() const;
    virtual bool GetResolveDepthBufferMode() const;
    virtual void SetResolveDepthBufferMode(bool);
    virtual const NiRenderTargetGroup::RendererData *GetRendererData() const;
    virtual void SetRendererData(NiRenderTargetGroup::RendererData *);
    virtual Ni2DBuffer::RendererData *GetBufferRendererData(unsigned int) const;
    virtual Ni2DBuffer::RendererData *GetDepthStencilBufferRendererData() const;
    NiRenderTargetGroup(const NiRenderTargetGroup &);

    static NiObject *CreateObject();
    static NiRenderTargetGroup *
    Create(Ni2DBuffer *, NiRenderer *, NiDepthStencilBuffer *);
    static NiRenderTargetGroup *Create(Ni2DBuffer *, NiRenderer *, bool, bool);
    static NiRenderTargetGroup *Create(unsigned int, NiRenderer *);

protected:
    NiRenderTargetGroup();

public:
    bool bForceNoMSAASurface; // 0x08
    bool bAddDSRestoreSurface; // 0x09
    unsigned int uiDepthBase; // 0x0c
protected:
    bool bResolveDepth; // 0x10
public:
    unsigned short usTargetCount; // 0x12
protected:
    NiPointer<Ni2DBuffer> m_aspBuffers[4]; // 0x14
    uint m_uiNumBuffers; // 0x24
    NiPointer<NiDepthStencilBuffer> m_spDepthStencilBuffer; // 0x28
    NiRenderTargetGroup::RendererData *m_pkRendererData; // 0x2c
};
