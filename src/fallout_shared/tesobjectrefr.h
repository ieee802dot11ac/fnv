#pragma once

#include "bsaudio/bssoundhandle.h"
#include "fallout/misc/saveload/bgssaveformbuffer.h"
#include "fallout_shared/teschildcell.h"
#include "fallout_shared/tesfile.h"
#include "fallout_shared/tesform.h"
#include "fallout_shared/tesglobal.h"
#include "fallout_shared/tessound.h"
#include "nimain/niavobject.h"

class MagicCaster;
class MagicTarget;

struct OBJ_REFR {
    TESBoundObject *pObjectReference; // 0x00
    NiPoint3 Angle; // 0x04
    NiPoint3 Location; // 0x10
};

class TESObjectREFR : public TESForm, public TESChildCell {
    //   public: static SettingT<INISettingCollection> bPrimitivesOn;

    TESObjectREFR(const TESObjectREFR &);
    TESObjectREFR();
    virtual ~TESObjectREFR();
    virtual void InitializeData();
    virtual void ClearData();
    //   virtual TESForm* CreateDuplicateForm(bool, NiTPointerMap<TESForm *,TESForm *>*);
    //   virtual void PostDuplicateProcess(NiTPointerMap<TESForm *,TESForm *>*);
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void InitItem();
    bool SortsBeforeRef(TESObjectREFR *);
    virtual bool SavesBefore(FORM *);
    virtual bool SavesBefore(TESForm *);
    virtual bool BelongsInGroup(FORM *, bool, bool);
    //   virtual void CreateGroupData(FORM*, FORM_GROUP*);
    void AddLockChange();
    void SetLastFinishedSequence(const char *);
    bool HasRandomSound();
    TESSound *GetSound();
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void Revert(BGSLoadFormBuffer *);
    virtual void Revert(unsigned int);
    virtual void InitLoadGame(BGSLoadFormBuffer *);
    virtual void InitLoadGame(unsigned int, unsigned int);
    virtual void FinishInitLoadGame(unsigned int, unsigned int);
    unsigned short GetAttachedAnimationSaveSize();
    void SaveAttachedAnimation();
    void LoadAttachedAnimation(bool);
    void ResetAttachedAnimation();
    //   unsigned short GetHavokDataSaveSize(HavokSaveData*);
    void SaveHavokData(BGSSaveFormBuffer *);
    //   void SaveHavokData(HavokSaveData*);
    void LoadHavokData(BGSLoadFormBuffer *);
    void LoadHavokData(unsigned short);
    virtual bool GetEditorLocation(NiPoint3 &, NiPoint3 &, TESForm *&, TESForm *);
    bool MoveToEditorLocation(TESForm *);
    void Update3DPosition();
    //   MobileObject* AddTalkingActivatorMobileObjectREFR();
    //   MobileObject* GetMobileObjectExtra();
    void LoadHavokDataPreVersion81(unsigned short);
    //   virtual BSSoundHandle VoiceSoundFunction(TESTopic*, Actor*, bool, bool, bool,
    //   bool, bool);
    float SpeakSoundFunction(const char *, BSSoundHandle &, TESObjectREFR *, int);
    virtual void UpdateSoundCallBack();
    //   void SayForceGoodbyeGreetingToPlayer(TESTopic*, bool, bool);
    virtual void DamageObject(float, bool);
    virtual void CheckSaveGame(BGSSaveFormBuffer *);
    virtual void FinishLoadGame(BGSLoadFormBuffer *);
    // void GatherHavokSaveData(BGSHavokSaveData *);
    bool CheckSaveAnimation();
    void SaveAnimation(BGSSaveFormBuffer *);
    void LoadAnimation(BGSLoadFormBuffer *);
    void ResetAnimation();
    //   bool SetSequencePosition(NiControllerManager*, const char*, float);
    virtual ENUM_FORM_ID GetSavedFormType();
    bool GetDroppedRef();
    void SetDroppedRef(bool);
    bool GetCenterOnCreation();
    void SetCenterOnCreation(bool);
    virtual bool GetCastShadows();
    virtual void SetCastShadows(bool);
    virtual bool GetMotionBlur();
    virtual void SetMotionBlur(bool);
    virtual bool GetDangerous();
    virtual bool GetObstacle();
    virtual void SetDelete(bool);
    virtual bool GetOnLocalMap();
    virtual void SetOnLocalMap(bool);
    bool GetInaccessible();
    void SetInaccessible(bool);
    bool GetIsHiddenDoor();
    void SetIsHiddenDoor(bool);
    bool GetIgnoredBySandbox();
    void SetIgnoredBySandbox(bool);
    bool GetTargeted();
    void SetTargeted(bool);
    bool MustBeVisibleDistant();
    bool GetVisibleDistant();
    void SetVisibleDistant(bool);
    bool GetVisibleDistantHigh();
    void SetVisibleDistantHigh(bool);
    bool GetOverrideFadeDist(float &);
    void SetOverrideFadeDist(bool, float);
    bool GetIsImposter();
    void SetIsImposter(bool);
    bool GetIsStingerLOD();
    void SetIsStingerLOD(bool);
    bool GetIsInvisibleLODMultType();
    void SetIsInvisibleLODMultType(bool);
    bool HasTemp3D();
    void SetHasTemp3D(bool);
    bool IsCellLoaded();
    bool IsCellAttached();
    bool GetRefPersists();
    bool GetPersistFlagValue();
    void SetRefPersists(bool);
    bool MustRefPersist();
    bool IsMultiBoundRef();
    virtual bool GetQuestObject();
    virtual void SetQuestObject(bool);
    bool HasQuestObject();
    //   CellMopp* GetMopp();
    bool GetOriginalOpenByDefaultState();
    void GetMapNameForLocation(BSStringT<char> &);
    NiAVObject *GetActorBone(NiAVObject *, NiFixedString &);
    NiAVObject *GetActorBone(NiAVObject *, char *);
    virtual bool IsReference();
    bool Is3DCritical();
    //   ExtraDataList* GetExtra();
    //   BSExtraData* GetExtraData(unsigned char);
    //   void SetExtra(ExtraDataList*);
    bool GetMarkerUsed(unsigned int, bool);
    void SetMarkerUsed(unsigned int, bool);
    void SetMarkerReserved(unsigned int, bool);
    bool HasFreeMarker(bool);
    int GetFirstFreeMarkerIndex(bool);
    //   bool GetMarkerAtIndex(int, FurnitureMark&);
    //   bool GetClosestFreeSitMarker(const NiPoint3&, FurnitureMark&, unsigned int&,
    //   bool); bool GetClosestFreeSleepMarker(const NiPoint3&, FurnitureMark&, unsigned
    //   int&, bool); bool GetClosestFreeMarker(const NiPoint3&, bool, bool,
    //   FurnitureMark&, unsigned int&, bool);
    void FreeUpAllMarkers();
    bool IsFurniture();
    char GetUses();
    void SetUses(unsigned char);
    float GetCharge();
    void SetCharge(float);
    void SaveRagDollData();
    //   void RestoreRagDollData(RagDollData*);
    float GetHealth();
    void SetHealth(float);
    float GetRadius();
    void SetRadius(float);
    float GetTimeLeft();
    void SetTimeLeft(float);
    TESForm *GetOwner();
    TESGlobal *GetOwnershipGlobal();
    int GetOwnershipRank();
    TESForm *GetMyOwner();
    bool IsPartofEvilFaction();
    void SetOwner(TESForm *);
    void SetGlobal(TESGlobal *);
    void SetRank(int);
    void RemoveOwner();
    //   BGSEncounterZone* GetEncounterZone();
    //   BGSEncounterZone* GetLocationEncounterZone();
    //   void SetEncounterZone(BGSEncounterZone*);
    //   void SetSayToTopicInfo(TESTopicInfo*);
    //   TESTopicInfo* GetSayToTopicInfo();
    //   void SetSayToTopic(TESTopic*);
    //   TESTopic* GetSayToTopic();
    void SetSayToResponseID(unsigned int);
    unsigned int GetSayToResponseID();
    unsigned int GetCalcLevel(bool);
    //   virtual void SetActorCause(ActorCause*);
    //   virtual ActorCause* GetActorCause();
    bool IsAnOwner(Actor *, bool);
    bool IsOwnerEvil(TESForm *);
    int GetValue();
    int GetQuality();
    float GetWeight();
    int GetGoldCount();
    //   DoorTeleportData* AddTeleport();
    void RemoveTeleport();
    //   DoorTeleportData* GetTeleport();
    const NiPoint3 &GetLinkedDoorTeleportPosition();
    const NiPoint3 &GetLinkedDoorTeleportRotation();
    unsigned int GetSeed();
    void SetSeed(unsigned int);
    //   MapMarkerData* GetMapMarkerData();
    const char *GetMapMarkerName();
    //   AudioMarkerData* GetAudioMarkerData();
    const char *GetAudioMarkerName();
    //   AudioBuoyMarkerData* GetAudioBuoyMarkerData();
    //   REFR_LOCK* AddLock();
    void RemoveLock();
    //   REFR_LOCK* GetLock();
    //   REFR_LOCK* GetMyLock();
    int GetLockLevel();
    void UnLock();
    void Lock();
    //   ExtraLock* GetExtraLock();
    float GetRadioStationRadius();
    void SetRadioStationRadius(float);
    float GetRadioStaticPct();
    void SetRadioStaticPct(float);
    //   RADIO_RANGE_TYPE GetRadioStationRangeType();
    //   void SetRadioStationRangeType(RADIO_RANGE_TYPE);
    TESObjectREFR *GetRadioStationPositionRef();
    void SetRadioStationPositionRef(TESObjectREFR *);
    bool IsLeveledCreature();
    bool HasLeveledCreatureCalced();
    //   void SetLeveledCreature(TESActorBase*, TESActorBase*);
    void RestoreLeveledCreatureOriginalBase();
    float GetRawScale();
    float GetScale();
    void SetScale(float);
    virtual NiPoint3 GetStartingAngle();
    virtual NiPoint3 GetStartingLocation();
    virtual void SetStartingPosition(NiPoint3);
    bool CanBeMoved();
    bool HasScript();
    void InitScript();
    bool RunScript();
    //   Script* GetScriptPointer();
    //   ScriptLocals* GetScriptVariables();
    //   REFR_LIGHT* GetLight();
    void SetLight(NiAVObject *, bool);
    //   void SetLight(NiLight*);
    //   REFR_LIGHT* GetSpellEffectLight();
    //   void SetSpellEffectLight(NiPointLight*);
    virtual void UpdateRefLight();
    void AddLight(bool);
    void RemoveLight(bool);
    void KillLight(bool);
    unsigned int GetActionFlag();
    //   bool GetAction(OBJECT_ACTION);
    void RunActions();
    //   void SetActionFlag(OBJECT_ACTION);
    //   void SetAction(OBJECT_ACTION);
    //   void ClearAction(OBJECT_ACTION);
    void SetActionRef(TESObjectREFR *);
    TESObjectREFR *GetActionRef();
    void AddReferenceItem(TESObjectREFR *, int, bool, bool);
    //   void AddBoundObjectItem(TESBoundObject*, ExtraDataList*, int);
    //   virtual TESObjectREFR* RemoveItem(TESBoundObject*, ExtraDataList*, int, bool,
    //   bool, TESObjectREFR*, const NiPoint3*, const NiPoint3*, bool, bool); virtual void
    //   RemoveItemType(ENUM_FORM_ID, bool, int); virtual bool
    //   AddWornItem(TESBoundObject*, int, ExtraDataList*, bool); virtual bool
    //   RemoveWornItem(TESBoundObject*, int, ExtraDataList*); virtual void
    //   DoTrap(TrapEntry*, TargetEntry*); bool WearingObject(TESBoundObject*);
    bool HasObjectId(unsigned int);
    //   ItemChange* GetInventoryItem(TESBoundObject*, unsigned int);
    //   ItemChange* GetInventoryItem(int, bool);
    //   void GetOEIFastInventoryIterator(const bool, OEI_Fast_InventoryIterator**,
    //   InventoryChanges**);
    int GetInventoryCount(bool, bool);
    int GetInventoryObjectCount(TESBoundObject *);
    //   TESContainer* HasContainer();
    float GetWeightInContainer(bool);
    //   int MultiBoundCollectObjects(TESObjectCELL*);
    //   bool QBoundInsideMultibound(BSMultiBound*);
    //   bool QCenterInsideMultibound(BSMultiBound*);
    //   bool QVerticesInsideMultibound(BSMultiBound*, bool);
    //   bool QWithinMultibound(BSMultiBound*, bool);
    //   MultiBoundMarkerData* GetMultiBoundData();
    const NiPoint3 &GetMultiBoundHalfExtent();
    //   BSMultiBound* GetMultiBound();
    void FreeMultiBound();
    //   BSMultiBoundRoom* GetMultiBoundRoom();
    void FreeMultiBoundRoom();
    TESObjectREFR *GetMultiBoundRef();
    void SetMultiBoundRef(TESObjectREFR *);
    TESObjectREFR *GetXTarget();
    void SetXTarget(TESObjectREFR *);
    bool CheckUsesExternalEmittance();
    TESForm *GetEmittanceSource();
    void SetEmittanceSource(TESForm *);
    TESObjectREFR *GetRandomTeleportMarker();
    void SetRandomTeleportMarker(TESObjectREFR *);
    TESObjectREFR *GetLinkedRef();
    void SetLinkedRef(TESObjectREFR *);
    bool AreRefLinksCircular();
    void DrawRefLink(bool);
    //   void RedrawRefLinks(bool, BSMap<TESObjectREFR *,bool>*);
    void RedrawPlaneLinks(bool);
    void RedrawRoomLinks(bool);
    bool CheckActivateParentLoop();
    void DrawActivateRefLink(bool);
    void RedrawActivateRefLinks(bool);
    void DrawEnableRefLinks(bool);
    bool IsActivatingChildren();
    void InitChildActivates(TESObjectREFR *);
    bool UpdateChildActivates();
    void AddDecalRef(TESObjectREFR *, const NiPoint3 &, const NiPoint3 &);
    void RemoveDecalRef(TESObjectREFR *);
    //   REF_DECAL_DATA* GetDecalData(TESObjectREFR*);
    void ApplyAllDecals(bool);
    void ClearAllDecals();
    TESObjectREFR *GetMerchantContainer();
    void SetMerchantContainer(TESObjectREFR *);
    TESObjectREFR *GetEnableStateParent();
    void SetEnableStateParent(TESObjectREFR *);
    bool GetEnableStateInverse();
    void SetEnableStateInverse(bool);
    bool CheckEnableParentLoop();
    //   BSSimpleList<TESObjectREFR *>* GetEnableStateChildList();
    void UpdateEnableStateChildrenFlagsRecursive();
    //   TESWorldSpace* GetPackageStartLocationWorld();
    //   TESObjectCELL* GetPackageStartLocationInteriorCell();
    const NiPoint3 &GetPackageStartLocationCoord();
    //   void SetPackageStartLocation(TESWorldSpace*, TESObjectCELL*, const NiPoint3&,
    //   float); virtual void AddObjecttoContainer(TESBoundObject*, ExtraDataList*, int);
    virtual NiPoint3 GetLookingAtLocation();
    virtual MagicCaster *GetMagicCaster();
    virtual MagicTarget *GetMagicTarget();
    bool GetVATStarget();
    virtual bool IsChild(bool);
    //   virtual TESActorBase* GetTemplateActorBase();
    //   virtual void SetTemplateActorBase(TESActorBase*);
    //   virtual BSFaceGenNiNode* GetFaceNodeBiped(NiNode*);
    //   virtual BSFaceGenNiNode* GetFaceNodeSkinned(NiNode*);
    //   virtual BSFaceGenNiNode* GetFaceNode(NiNode*);
    //   virtual BSFaceGenAnimationData* GetFaceAnimationData(NiNode*);
    virtual bool ClampToGround();
    virtual bool DetachHavok();
    virtual void InitHavok();
    void CleanUpTraps();
    bool CheckAndAddHavokChangeFlag(NiAVObject *);
    void PreCalcTriStripsShapeAabb(NiAVObject *);
    bool Is3DHighPriority();
    virtual NiAVObject *Load3D(bool);
    void Release3DRelatedData();
    virtual void Set3D(NiAVObject *, bool);
    void Set3DSimple(NiAVObject *);
    void Set3DVerySimple(NiAVObject *);
    virtual NiAVObject *Get3D();
    void SetLoadedDataFlag(unsigned int, bool);
    bool GetLoadedDataFlag(unsigned int);
    void InitHavokForPlaceableWater();
    void InitHavokForPrimitiveTrigger();
    void InitHavokForCollisionObject();
    void InitHavokForAcousticSpace();
    virtual bool GetRandomAnim();
    void UpdateReference3D();
    void UnClone3D(TESObjectREFR *);
    bool ReplaceModel();
    void ClearInterpolators();
    unsigned int GetModelLength();
    const char *GetModel();
    float GetModelBoundSize();
    //   TESModel* GetTESModel();
    //   void SetOrientation(NiMatrix3);
    //   NiMatrix3 GetOrientation();
    //   NiMatrix3 MultipleMatrixByRace(NiMatrix3&);
    virtual NiPoint3 GetBoundMin();
    virtual NiPoint3 GetBoundMax();
    void InitAnimation();
    //   BSSimpleList<char const *>* BuildKFFileList(ANIM_GROUP_WEAPON_ENUM);
    virtual void UpdateAnimation();
    //   void EndSequence(NiControllerSequence*);
    //   virtual Animation* GetAnimation();
    //   Animation* SetAnimation(Animation*);
    virtual BipedAnim *GetBiped();
    virtual BipedAnim *GetCurrentBiped();
    virtual void SetBiped(BipedAnim *);
    //   void SetDismembered(BGSBodyPart::LIMB_ENUM, TESForm*, CAUSE_OF_DEATH,
    //   BGSBodyPart::LIMB_ENUM, bool); void SetLimbRemoved(BGSBodyPart::LIMB_ENUM, bool);
    //   bool GetDismembered(BGSBodyPart::LIMB_ENUM);
    //   CAUSE_OF_DEATH GetCauseofDeath();
    TESForm *GetDeathObject();
    //   BGSBodyPart::LIMB_ENUM GetLastHitLimb();
    //   void AttachWeapon(TESObjectWEAP*);
    void RemoveWeapon();
    //   void AttachShield(TESObjectARMO*);
    void RemoveShield(bool);
    //   void AttachTorch(TESObjectLIGH*);
    void RemoveTorch();
    //   void AttachAmmo(TESAmmo*);
    void RemoveAmmo();
    //   void AttachRing(TESObjectCLOT*, bool);
    void RemoveRing(bool);
    //   void AttachAmulet(TESObjectCLOT*);
    void RemoveAmulet();
    void UpdateMultiBoundPrimitive();
    bool GetIsOfType(TESBoundObject *);
    virtual void SetAltered(bool);
    virtual const char *GetFormEditorID();
    virtual void GetFormDetailedString(BSStringT<char> &);
    const char *GetFullName();
    TESBoundObject *GetObjectReference();
    const NiPoint3 &GetAngleOnReference();
    virtual const NiPoint3 &GetLocationOnReference();
    //   BGSWorldLocation GetWorldLocation();
    virtual void SetRunsInLow(bool);
    void SetObjectReference(TESBoundObject *);
    void SetAngleOnReference(NiPoint3);
    void SetAngleOnReferenceX(float);
    void SetAngleOnReferenceY(float);
    void SetAngleOnReferenceZ(float);
    void SetLocationOnReference(const NiPoint3 &);
    void SetLocationOnReferenceZ(float);
    void SetLocationOnReferenceX(float);
    void SetLocationOnReferenceY(float);
    void SetLocationOnReferenceSimple(const NiPoint3 &);
    virtual void MoveHavok(bool);
    virtual void SetActionComplete(bool);
    virtual void SetMovementComplete(bool);
    int GetCount();
    bool Activate(TESObjectREFR *, bool, TESBoundObject *, int);
    void Enable();
    void Disable();
    virtual void ResetInventory(bool);
    bool GetRespawn();
    void MarkAsPickedUp();
    void MarkAsDeleted();
    bool IsMarker();
    bool IsOcclusionMarker();
    virtual NiAVObject *GetFireNode();
    virtual void SetFireNode(NiAVObject *);
    //   virtual SIT_SLEEP_STATE GetSitSleepState();
    virtual bool IsNpc();
    virtual bool IsCreature();
    virtual bool IsExplosion();
    virtual bool IsProjectile();
    TESForm *GetSpace();
    bool GetInterior();
    //   TESWorldSpace* GetWorldSpace();
    //   virtual TESObjectCELL* GetSaveParentCell();
    //   TESObjectCELL* GetParentCell();
    //   virtual void SetParentCell(TESObjectCELL*);
    //   void SetParentCellSimple(TESObjectCELL*);
    virtual bool IsDead(bool);
    virtual bool IsKnockedOut();
    virtual bool IsParalyzed();
    float GetDistanceFromPoint(const NiPoint3 &);
    float GetDistanceFromReference(TESObjectREFR *, bool, bool);
    NiPoint3 GetDeltaForAngle(float);
    void ShowPrimitive(bool);
    void FixAttachedBSObjectSizeAndTransform();
    int GetTargetType();
    bool IsCrimeToActivate();
    void AttachSound(bool);
    bool CanHaveSound();
    bool ShouldPlaySound();
    void UpdateAddonNodeSounds(bool);
    void UpdateAddonNodeSoundsRecursive(NiAVObject *, bool);
    void ReleasePhantom();
    void CullChildMarkers(bool);
    //   virtual BSAnimNoteReceiver* CreateAnimNoteReceiver();
    //   virtual BSAnimNoteReceiver* GetAnimNoteReceiever();
    float GetRelevantWaterHeight();
    //   void SetInZone(WaterZone*, bool);
    TESObjectREFR *GetCurrentWaterObject();
    void SetCurrentWaterObject(TESObjectREFR *);
    bool QUnderwater();
    void SetUnderwater(bool);
    void RemoveFromAllWater(bool);
    bool GetLODObjectExists(bool);
    bool UpdateMultiboundShapeTransformsRecursive(NiAVObject *);
    //   LOADED_REF_DATA* GetLoadedData();

    //   public: static void GetCollisionObjectSize(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static void
    //   SaveHavokDataForCollisionObjectOld(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static void
    //   LoadHavokDataForCollisionObjectOld(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static void
    //   LoadHavokDataForCollisionObjectPreVersion81(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static unsigned short
    //   GetControllerManagerSaveSize(NiControllerManager*); static void
    //   SaveControllerManager(NiControllerManager*, BGSSaveGameBuffer*, float); static
    //   void SaveControllerManager(NiControllerManager*, float); static void
    //   LoadControllerManager(NiControllerManager*, BGSLoadGameBuffer*, float); static
    //   void LoadControllerManager(NiControllerManager*, NiAVObject*, float);
    static void SayToCallBack(void *, bool);
    static void SoundFileCallBack(void *, bool);
    //   static void GatherHavokSaveDataForCollisionObject(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static void
    //   SaveHavokDataForCollisionObject(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&); static void
    //   LoadHavokDataForCollisionObject(bhkNiCollisionObject*,
    //   bhkWorldNS::ObjectRecData&);
    static unsigned int GetLightingObjectType(NiAVObject *);
    static TESObjectREFR *CreateReference(unsigned char, bool);
    static bool IsReferenceFormType(ENUM_FORM_ID);
    static bool CanBeActivateParent(TESObjectREFR *, int);
    static bool CanBeEnableParent(TESObjectREFR *, int);
    static bool IsPersistentRef(TESObjectREFR *, int);
    static bool IsPersistentNonContainerRef(TESObjectREFR *, int);
    static bool IsPersistentActorRef(TESObjectREFR *, int);
    static bool IsNotMultiBoundRef(TESObjectREFR *, int);
    static bool IsPersistentRefOrInSameCell(TESObjectREFR *, int);
    static bool IsPersistentPlaceableWaterRef(TESObjectREFR *, int);
    static bool IsPlaceableWaterRef(TESObjectREFR *, int);
    static bool CanBeMerchantContainer(TESObjectREFR *, int);
    static bool IsDecalRef(TESObjectREFR *, int);
    static bool IsMultiBoundRef(TESObjectREFR *, int);
    static bool IsLight(TESObjectREFR *, int);
    static bool HasTimeControllers(NiAVObject *);
    static bool IsHavokStillActive(NiAVObject *);
    static void HavokActivateCallback(NiAVObject *);
    static void HavokDeactivateCallback(NiAVObject *);
    static bool AddAddonNodes(NiNode *);
    static bool AddMasterParticleAddonNodes(NiNode *);
    static bool RemoveMasterParticleAddonNodes(NiNode *);
    static bool RemoveAddonNodes(NiNode *);
    static bool RemoveSounds(NiNode *);
    static bool HasAddonNodes(NiNode *);
    static bool HasAddonFlags(NiNode *);
    static void RandomizeAddons(NiAVObject *, float);
    static bool IsValidRadioPositionRef(TESObjectREFR *, int);
    //   static bool QVerticesInsideMultiboundRecurse(NiAVObject*, BSMultiBound*, bool&,
    //   bool);
    static void SetDroppedItemData(TESObjectREFR *, TESObjectREFR *);
    //   static void FilteredAddObject(bhkNiCollisionObject*, bhkWorldNS::ObjectRecData&);
    static void SetBackgroundLoadingRef(TESObjectREFR *, NiAVObject *);
    static void ClearBackgroundLoadingRef();
    static TESObjectREFR *GetBackgroundLoadingRef();
    static NiAVObject *GetBackgroundLoading3D();
    static TESObjectREFR *FindReferenceFor3D(NiAVObject *);
    static NiPoint3 GetBoundMax(NiAVObject *);
    //   static void MoveRefToNewSpace(TESObjectREFR*, TESObjectCELL*, TESWorldSpace*);
    //   static bool GetDistant3DDataFromFile(TESFile*, DISTANT_3D_REF_DATA*);
    //   static void TransChangeCallback(bhkNiCollisionObject*, unsigned int);
    //   static void DebugDisplayCallback(NiGeometry*, const NiColor&);

protected:
    //   void InitCollisionObject(NiNode*, bool, NiCollisionGroup*);
    OBJ_REFR *GetData();
    void CreateLoadedData();
    void FreeLoadedData();

    TESSound *pRandomSound; // 0x2c
    OBJ_REFR data; // 0x30
    float fRefScale; // 0x4c
    TESObjectCELL *pParentCell; // 0x50
    // ExtraDataList m_Extra; // 0x54
    // LOADED_REF_DATA *pLoadedData; // 0x74

    static TESObjectREFR *pBackgroundLoadingRef;
    static NiAVObject *pBackgroundLoading3D;
};
