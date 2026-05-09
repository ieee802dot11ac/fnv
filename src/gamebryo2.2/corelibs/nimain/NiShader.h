#pragma once

#include "nimain/NiDynamicEffectState.h"
#include "nimain/NiGeometry.h"
#include "nimain/NiPropertyState.h"
#include "nimain/NiRTTI.h"
#include "nimain/NiRefObject.h"

class NiShader : public NiRefObject {
public:
    class NiShaderInstanceDescriptor {
    public:
        static const NiRTTI ms_RTTI;

        RTTI_BASEDEFS

        NiShaderInstanceDescriptor *DynamicCast(const NiRTTI *) const;
        virtual ~NiShaderInstanceDescriptor();
        NiShaderInstanceDescriptor(const NiShaderInstanceDescriptor &);
        NiShaderInstanceDescriptor();

        static bool IsExactKindOf(const NiRTTI *, const NiShaderInstanceDescriptor *);
        static bool IsKindOf(const NiRTTI *, const NiShaderInstanceDescriptor *);
        static NiShaderInstanceDescriptor *
        DynamicCast(const NiRTTI *, const NiShaderInstanceDescriptor *);
    };

    static const NiRTTI ms_RTTI;

    RTTI_BASEDEFS

    NiShader *DynamicCast(const NiRTTI *) const;
    NiShader(const NiShader &);
    NiShader();
    virtual ~NiShader();
    const NiFixedString &GetName() const;
    uint GetImplementation() const;
    virtual bool IsInitialized();
    virtual bool Initialize();
    virtual bool SetupGeometry(NiGeometry *);
    virtual uint PreProcessPipeline(
        NiGeometry *,
        const NiSkinInstance *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint UpdatePipeline(
        NiGeometry *,
        const NiSkinInstance *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint SetupRenderingPass(
        NiGeometry *,
        const NiSkinInstance *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint SetupTransformations(
        NiGeometry *,
        const NiSkinInstance *,
        const NiSkinPartition::Partition *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint SetupBoneMatrices(
        NiGeometry *,
        const NiSkinInstance *,
        const NiSkinPartition::Partition *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint SetupShaderPrograms(
        NiGeometry *,
        const NiSkinInstance *,
        const NiSkinPartition::Partition *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual NiGeometryData::RendererData *PrepareGeometryForRendering(
        NiGeometry *,
        const NiSkinPartition::Partition *,
        NiGeometryData::RendererData *,
        const NiPropertyState *
    );
    virtual uint PostRender(
        NiGeometry *,
        const NiSkinInstance *,
        const NiSkinPartition::Partition *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual uint PostProcessPipeline(
        NiGeometry *,
        const NiSkinInstance *,
        NiGeometryData::RendererData *,
        const NiPropertyState *,
        const NiDynamicEffectState *,
        const NiTransform &,
        const NiBound &
    );
    virtual void SetupGeometryTextures(const NiPropertyState *);
    virtual void SetupGeometryConstants(const NiPropertyState *);
    virtual void SetupGeometryAlphaBlending(const NiPropertyState *);
    virtual void SetupGeometryAlphaTesting(const NiPropertyState *);
    virtual void SetupGeometryRenderStates(const NiPropertyState *, bool);
    virtual void PostGeometry(const NiPropertyState *);
    virtual uint FirstPass();
    virtual uint NextPass();
    virtual bool IsGenericallyConfigurable();
    virtual NiShaderDeclaration *CreateShaderDeclaration(uint, uint);
    virtual bool AppendRenderPass(uint &);
    // virtual bool SetAlphaOverride(uint, bool, bool, NiAlphaProperty::AlphaFunction,
    // bool, NiAlphaProperty::AlphaFunction);
    virtual bool SetUsesNiRenderState(bool);
    // virtual bool SetGPUProgram(uint, NiGPUProgram *, uint &);
    // virtual NiShaderConstantMap *CreateShaderConstantMap(uint, uint);
    virtual bool
    AppendTextureSampler(uint, uint &, const NiFixedString &, const NiFixedString &, uint);
    void SetName(const NiFixedString &);
    void SetImplementation(uint);
    virtual const NiShaderInstanceDescriptor *GetShaderInstanceDesc() const;

    static bool IsExactKindOf(const NiRTTI *, const NiShader *);
    static bool IsKindOf(const NiRTTI *, const NiShader *);
    static NiShader *DynamicCast(const NiRTTI *, const NiShader *);

protected:
    NiFixedString m_kName; // 0x08
    uint m_uiImplementation; // 0x0c
    bool m_bInitialized; // 0x10
};
