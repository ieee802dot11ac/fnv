#pragma once

#include "nimain/NiProperty.h"
#include "nimain/NiTPointerList.h"

class NiPropertyState {
public:
    NiPropertyState(const NiPropertyState &);
    NiPropertyState();
    ~NiPropertyState();
    NiPropertyState &operator=(const NiPropertyState &);
    NiPointer<NiProperty> &operator[](int);
    void Reset();
    void SetProperty(NiProperty *);
    void GetProperties(NiProperty **) const;
    void SwapProperties(NiTPointerList<NiPointer<NiProperty> > &);
    class NiAlphaProperty *GetAlpha() const;
    class NiDitherProperty *GetDither() const;
    class NiCullingProperty *GetCulling() const;
    class NiMaterialProperty *GetMaterial() const;
    class NiRendererSpecificProperty *GetRendererSpecific() const;
    class NiShadeProperty *GetShade() const;
    class NiSpecularProperty *GetSpecular() const;
    class NiStencilProperty *GetStencil() const;
    class NiTexturingProperty *GetTexturing() const;
    class NiVertexColorProperty *GetVertexColor() const;
    class NiWireframeProperty *GetWireframe() const;
    class NiZBufferProperty *GetZBuffer() const;

protected:
    NiPointer<NiProperty> m_aspProps[7]; // 0x0
};
