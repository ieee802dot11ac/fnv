#pragma once

#define MAKERTTI(cls, base) const NiRTTI cls ::ms_RTTI(#cls, &base::ms_RTTI);
#define MAKEROOTRTTI(cls) const NiRTTI cls ::ms_RTTI(#cls, nullptr);
#define RTTI_BASEDEFS                                                                    \
    virtual const NiRTTI *GetRTTI() const;                                               \
    bool IsExactKindOf(const NiRTTI *) const;                                            \
    bool IsKindOf(const NiRTTI *) const;                                                 \
    virtual class NiNode *IsNode();                                                      \
    virtual class BSFadeNode *IsFadeNode();                                              \
    virtual class BSMultiBoundNode *IsMultiBoundNode();                                  \
    virtual class NiGeometry *IsGeometry();                                              \
    virtual class NiTriBasedGeom *IsTriBasedGeom();                                      \
    virtual class NiTriStrips *IsTriStrips();                                            \
    virtual class NiTriShape *IsTriShape();                                              \
    virtual class BSSegmentedTriShape *IsSegmentedTriShape();                            \
    virtual class BSResizableTriShape *IsResizableTriShape();                            \
    virtual class NiParticles *IsParticlesGeom();                                        \
    virtual class NiLines *IsLinesGeom();                                                \
    virtual class bhkNiCollisionObject *IsBhkNiCollisionObject();                        \
    virtual class bhkBlendCollisionObject *IsBhkBlendCollisionObject();                  \
    virtual class bhkRigidBody *IsBhkRigidBody() const;                                  \
    virtual class bhkLimitedHingeConstraint *IsBhkLimitedHingeConstraint();

class NiRTTI {
public:
    NiRTTI(const char *, const NiRTTI *);
    const char *GetName() const { return m_pcName; }
    const NiRTTI *GetBaseRTTI() const { return m_pkBaseRTTI; }

protected:
    const char *m_pcName; // 0x0
    const NiRTTI *m_pkBaseRTTI; // 0x4
};
