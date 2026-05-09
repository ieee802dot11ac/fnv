#pragma once

#include "nimain/NiMatrix3.h"
#include "nimain/NiPoint2.h"

class NiTextureTransform {
public:
    enum TransformMethod {
        MAYA_DEPRECATED_TRANSFORM = 0x0000,
        MAX_TRANSFORM = 0x0001,
        MAYA_TRANSFORM = 0x0002,
    };

    static const NiTextureTransform IDENTITY;

    NiTextureTransform(
        const NiPoint2 &,
        float,
        const NiPoint2 &,
        const NiPoint2 &,
        NiTextureTransform::TransformMethod
    );
    NiTextureTransform();
    const NiMatrix3 *GetMatrix() const;
    void MakeIdentity();
    NiPoint2 GetTranslate() const;
    void SetTranslate(const NiPoint2 &);
    float GetRotate() const;
    void SetRotate(float);
    NiPoint2 GetScale() const;
    void SetScale(const NiPoint2 &);
    NiTextureTransform::TransformMethod GetTransformMethod() const;
    void SetTransformMethod(NiTextureTransform::TransformMethod);
    NiPoint2 GetCenter() const;
    void SetCenter(const NiPoint2 &);
    bool operator==(const NiTextureTransform &) const;
    bool operator!=(const NiTextureTransform &) const;
    void LoadBinary(NiStream &);
    void SaveBinary(NiStream &);

protected:
    void UpdateMatrix() const;

    NiPoint2 m_kTranslate; // 0x00
    float m_fRotate; // 0x08
    NiPoint2 m_kScale; // 0x0c
    NiPoint2 m_kCenter; // 0x14
    bool m_bMatrixDirty; // 0x1c
    NiMatrix3 m_kMatrix; // 0x20
    NiTextureTransform::TransformMethod m_eMethod; // 0x50
};
