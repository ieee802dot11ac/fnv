#pragma once

#include "nirefobject.h"
#include "nirtti.h"
#include "niobjectgroup.h"
#include "nismartpointer.h"

class NiStream;
class NiCloningProcess;

class NiObject : public NiRefObject {
public:
    static const NiRTTI ms_RTTI;
    virtual const NiRTTI *GetRTTI() const;
    bool IsExactKindOf(const NiRTTI *) const;
    static bool IsExactKindOf(const NiRTTI *, const NiObject *);
    bool IsKindOf(const NiRTTI *) const;
    static bool IsKindOf(const NiRTTI *, const NiObject *);
    // virtual NiNode *IsNode();
    // virtual BSFadeNode *IsFadeNode();
    // virtual BSMultiBoundNode *IsMultiBoundNode();
    // virtual NiGeometry *IsGeometry();
    // virtual NiTriBasedGeom *IsTriBasedGeom();
    // virtual NiTriStrips *IsTriStrips();
    // virtual NiTriShape *IsTriShape();
    // virtual BSSegmentedTriShape *IsSegmentedTriShape();
    // virtual BSResizableTriShape *IsResizableTriShape();
    // virtual NiParticles *IsParticlesGeom();
    // virtual NiLines *IsLinesGeom();
    // virtual bhkNiCollisionObject *IsBhkNiCollisionObject();
    // virtual bhkBlendCollisionObject *IsBhkBlendCollisionObject();
    // virtual bhkRigidBody *IsBhkRigidBody() const;
    // virtual bhkLimitedHingeConstraint *IsBhkLimitedHingeConstraint();
    NiObject *DynamicCast(const NiRTTI *__restrict) const;
    static NiObject *DynamicCast(const NiRTTI *__restrict, const NiObject *);
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    static NiObject *CreateObject();
    // virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    // virtual void AddViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiObject();
    NiObject *Clone(NiCloningProcess &);
    NiObject *Clone();
    NiObject *CreateSharedClone(NiCloningProcess &);
    virtual void ProcessClone(NiCloningProcess &);
    void CreateDeepCopy(NiPointer<NiObject> &);
    virtual void PostLinkObject(NiStream &);
    virtual bool StreamCanSkip();
    virtual const NiRTTI *GetStreamableRTTI() const;
    // virtual void SetBound(BSNiBound *);
    virtual uint GetBlockAllocationSize() const;
    virtual NiObjectGroup *GetGroup() const;
    virtual void SetGroup(NiObjectGroup *);
    // virtual NiControllerManager *IsNiControllerManager();

protected:
    NiObject();
    void CopyMembers(NiObject *, NiCloningProcess &);

private:
    NiObject(const NiObject &);
    NiObject &operator=(const NiObject &);
};
