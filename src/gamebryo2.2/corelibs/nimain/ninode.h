#pragma once

#include "nimain/niavobject.h"
#include "nimain/nitobjectlist.h"

class NiNode : public NiAVObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiNode(const NiNode &);
    NiNode(unsigned int);
    virtual ~NiNode();
    unsigned int GetArrayCount() const;
    unsigned int GetChildCount() const;
    virtual void AttachChild(NiAVObject *, bool);
    virtual void InsertChildAt(unsigned int, NiAVObject *);
    // virtual void SetBound(BSNiBound *);
    virtual void DetachChild(NiAVObject *, NiPointer<NiAVObject> &);
    virtual void DetachChild(NiAVObject *);
    virtual void DetachChildAt(unsigned int, NiPointer<NiAVObject> &);
    virtual void DetachChildAt(unsigned int);
    virtual void SetAt(unsigned int, NiAVObject *, NiPointer<NiAVObject> &);
    virtual void SetAt(unsigned int, NiAVObject *);
    NiAVObject *GetAt(unsigned int) const;
    NiAVObject *GetAtChecked(unsigned int) const;
    void SetChildArraySize(unsigned int);
    // virtual void ApplyTransform(const NiMatrix3 &, const NiPoint3 &, bool);
    virtual NiAVObject *GetObjectByName(const NiFixedString &);
    // virtual void UpdateControllers(NiUpdateData &);
    // virtual void UpdateDownwardPass(NiUpdateData &, unsigned int);
    // virtual void UpdateSelectedDownwardPass(NiUpdateData &, unsigned int);
    virtual void UpdateUpwardPass();
    virtual void UpdateWorldBound();
    // virtual void UpdateRigidDownwardPass(NiUpdateData &, unsigned int);
    // virtual void UpdateTransformAndBounds(NiUpdateData &);
    // void UpdatePropertiesUpward(NiPropertyState *&);
    // virtual void UpdatePropertiesDownward(NiPropertyState *);
    // virtual void OnVisible(NiCullingProcess &);
    void RemoveAllChildren();
    void DetachAllChildren();
    void CompactChildArray();
    virtual void SetSelectiveUpdateFlags(bool &, bool, bool &);
    // virtual void PurgeRendererData(NiRenderer *);
    virtual void ProcessClone(NiCloningProcess &);
    virtual NiNode *IsNode();
    bool QPickOff();
    void SetPickOff(bool);
    bool QNotVisible();
    void SetNotVisible(bool);
    bool QPreProcessedNode();
    void SetPreProcessedNode(bool);
    NiNode &operator=(const NiNode &);
    static NiObject *CreateObject();
    static bool SameTopology(NiAVObject *, NiAVObject *);

protected:
    void CopyMembers(NiNode *, NiCloningProcess &);
    // void
    // CopyEffectListClones(const NiTPointerList<NiDynamicEffect *> *, NiCloningProcess
    // &);
    NiTObjectArray<NiPointer<NiAVObject> > m_kChildren; // 0xc0
};
