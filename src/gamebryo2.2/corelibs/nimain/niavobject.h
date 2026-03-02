#pragma once

#include "niobjectnet.h"
#include "nipoint3.h"

class NiAVObject : public NiObjectNET {
public:
    static const NiRTTI ms_RTTI;
    // static BSSpinLock PropertyStateCrit;

protected:
    static uint32_t uiIgnoreReportHit;
    // static NiBound NullBoundS;

public:
    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    // virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiAVObject();
    // const NiNode *GetParent() const;
    // NiNode *GetParent();
    // void Update(NiUpdateData &);
    // void UpdateSelected(NiUpdateData &);
    // virtual void UpdateControllers(NiUpdateData &);
    // void UpdateObjectControllers(NiUpdateData &, bool);
    void UpdateProperties();
    void UpdateEffects();
    // virtual void SetBound(BSNiBound *);
    void SetTranslate(float, float, float);
    void SetTranslate(const NiPoint3 &);
    const NiPoint3 &GetTranslate() const;
    // void SetRotate(const NiQuaternion &);
    void SetRotate(float, float, float, float);
    // void SetRotate(const NiMatrix3 &);
    // void GetRotate(NiQuaternion &) const;
    void GetRotate(float &, float &, float &, float &) const;
    // const NiMatrix3 &GetRotate() const;
    // void SetRotateAboutCenter(const NiMatrix3 &, const NiPoint3 &, const NiPoint3 &);
    void SetScale(float);
    float GetScale() const;
    // virtual void ApplyTransform(const NiMatrix3 &, const NiPoint3 &, bool);
    const NiPoint3 &GetWorldTranslate() const;
    // const NiMatrix3 &GetWorldRotate() const;
    float GetWorldScale() const;
    // const NiBound &GetWorldBound() const;
    float GetWorldBoundRadius();
    void CreateBoundIfNone();
    // const NiTPointerList<NiPointer<NiProperty> > &GetPropertyList() const;
    // NiTPointerList<NiPointer<NiProperty> > &GetPropertyList();
    // void AttachProperty(NiProperty *);
    // void DetachProperty(NiProperty *);
    void DetachAllProperties();
    // NiProperty *GetProperty(int32_t) const;
    // void RemoveProperty(int32_t, NiPointer<NiProperty> &);
    void RemoveProperty(int32_t);
    virtual void SetMaterialNeedsUpdate(bool);
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool);
    void SetAppCulled(bool);
    bool GetAppCulled() const;
    virtual NiAVObject *GetObjectByName(const NiFixedString &);
    bool GetSelectiveUpdate() const;
    void SetSelectiveUpdate(bool);
    bool GetSelectiveUpdateTransforms() const;
    void SetSelectiveUpdateTransforms(bool);
    bool GetSelectiveUpdateControllers() const;
    void SetSelectiveUpdateControllers(bool);
    bool GetSelectiveUpdateRigid() const;
    void SetSelectiveUpdateRigid(bool);
    bool GetSelectiveUpdateTransformsOverride() const;
    void SetSelectiveUpdateTransformsOverride(bool);
    virtual void SetSelectiveUpdateFlags(bool &, bool, bool &);
    bool GetNoDecals() const;
    void SetNoDecals(bool);
    bool QAlwaysDraw() const;
    void SetAlwaysDraw(bool);
    bool QFixedBound();
    void SetFixedBound(bool);
    bool GetTransIsIdentity() const;
    void SetTransIsIdentity(bool);
    bool QFadedIn() const;
    void SetFadedIn(bool);
    bool QIgnoreFade() const;
    void SetIgnoreFade(bool);
    bool QLODFadingOut() const;
    void SetLODFadingOut(bool);
    bool QHasMovingSound() const;
    void SetHasMovingSound(bool);
    bool QShadowReceiver() const;
    void SetShadowReceiver(bool);
    bool QHighDetail() const;
    void SetHighDetail(bool);
    bool QAlreadyTraversed() const;
    void SetAlreadyTraversed(bool);
    bool QRelevantImposter() const;
    void SetRelevantImposter(bool);
    bool GetWorldBoundChange();
    void SetWorldBoundChange(bool);
    bool QPlayer();
    void SetPlayer(bool);
    bool QHasPropController() const;
    void SetHasPropController(bool);
    bool QHasOrphanedBound() const;
    void SetOrphanedBound(bool);
    void SetDisplayObject(bool);
    bool GetDisplayObject() const;
    // void SetCollisionObject(NiCollisionObject *);
    // NiCollisionObject *GetCollisionObject() const;
    void SetWorldTranslate(const NiPoint3 &);
    // void SetWorldRotate(const NiMatrix3 &);
    void SetWorldScale(float);
    // void SetWorldBound(const NiBound &);
    // virtual void UpdateDownwardPass(NiUpdateData &, uint32_t);
    // virtual void UpdateSelectedDownwardPass(NiUpdateData &, uint32_t);
    // virtual void UpdateRigidDownwardPass(NiUpdateData &, uint32_t);
    int32_t IsVisualObject() const;
    int32_t IsUnCulledVisualObject() const;
    // virtual void UpdatePropertiesDownward(NiPropertyState *);
    // virtual void UpdateEffectsDownward(NiDynamicEffectState *);
    // virtual void UpdateWorldData(NiUpdateData &);
    virtual void UpdateWorldBound();
    void UpdateWorldLoc();
    // virtual void UpdateTransformAndBounds(NiUpdateData &);
    // virtual void PreAttachUpdate(NiNode *, NiUpdateData &);
    // virtual void PreAttachUpdateProperties(NiNode *);
    // virtual void PreAttachUpdateEffects(NiNode *);
    virtual void PostAttachUpdate();
    // void PushLocalProperties(NiPropertyState *, bool, NiPropertyState *&);
    // void AttachParent(NiNode *);
    void DetachParent();
    // void Cull(NiCullingProcess &);
    // virtual void OnVisible(NiCullingProcess &);
    // void DoSelectedUpdate(NiUpdateData &, uint32_t);
    virtual void ProcessClone(NiCloningProcess &);
    // const NiTransform &GetWorldTransform() const;
    // const NiTransform &GetLocalTransform() const;
    // virtual void PurgeRendererData(NiRenderer *);
    NiAVObject(const NiAVObject &);
    NiAVObject &operator=(const NiAVObject &);

    static void IgnoreReportHit();
    static void ResetReportHit();
    static bool QIgnoreReportHit();
    static void _SDMInit();

protected:
    NiAVObject();
    void CopyMembers(NiAVObject *, NiCloningProcess &);
    void SetSortObject(bool);
    bool GetSortObject() const;
    void SetField(uint32_t, uint32_t, uint32_t);
    uint32_t GetField(uint32_t, uint32_t) const;
    void SetBit(bool, uint32_t);
    bool GetBit(uint32_t) const;
    void CopyTransforms(const NiAVObject *);
    // void CloneProperties(
    //     NiAVObject *, NiTPointerList<NiPointer<NiProperty> > *, NiCloningProcess &
    // );
    // void
    // ProcessPropertyClones(NiTPointerList<NiPointer<NiProperty> > *, NiCloningProcess
    // &);
    bool HasTransformController() const;
    bool HasPropertyController() const;

    //   protected: NiNode* m_pkParent; // 0x18
    //   protected: NiPointer<NiCollisionObject> m_spCollisionObject; // 0x1c
    //   public: BSNiBound* m_kWorldBound; // 0x20
    //   protected: NiTPointerList<NiPointer<NiProperty> > m_kPropertyList; // 0x24
protected:
    uint32_t m_uFlags; // 0x30
    //   protected: NiTransform m_kLocal; // 0x40
    //   protected: NiTransform m_kWorld; // 0x80
};
