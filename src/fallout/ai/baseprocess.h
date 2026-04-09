#pragma once

#include "bscore/bssimplelist.h"
#include "fallout_shared/bipedanim.h"
#include "fallout_shared/magic/magicitem.h"

class MobileObject;
class Actor;

class BaseProcess { /* Size=0x30 */
public:
    enum FADE_STATE {
        FADE_NORMAL = 0x0000,
        FADE_IN = 0x0001,
        FADE_OUT = 0x0002,
        FADE_TELEPORT_IN = 0x0003,
        FADE_TELEPORT_OUT = 0x0004,
        FADE_OUT_DISABLE = 0x0005,
        FADE_OUT_DELETE = 0x0006,
        FADE_OUT_MOVE = 0x0007,
    };
    enum HEAD_TRACK_TYPE {
        HEAD_TRACK_TYPE_DEFAULT = 0x0000,
        HEAD_TRACK_TYPE_ACTION = 0x0001,
        HEAD_TRACK_TYPE_SCRIPT = 0x0002,
        HEAD_TRACK_TYPE_COMBAT = 0x0003,
        HEAD_TRACK_TYPE_DIALOG = 0x0004,
        HEAD_TRACK_TYPE_USE_WEAPON = 0x0005,
        HEAD_TRACK_TYPE_COUNT = 0x0006,
    };
    enum POSTANIM_ACTION {
        POSTANIM_ACTION_NONE = 0x0000,
        POSTANIM_ACTION_FIRE_WEAPON = 0x0001,
        POSTANIM_ACTION_RELOAD_WEAPON = 0x0002,
        POSTANIM_ACTION_SIT_SLEEP = 0x0004,
        POSTANIM_ACTION_GET_UP = 0x0008,
        POSTANIM_ACTION_PLAY_IDLE = 0x0010,
        POSTANIM_ACTION_DIE = 0x0020,
        POSTANIM_ACTION_EQUIP_UNEQUIP_WEAPON = 0x0040,
        POSTANIM_ACTION_PICK_IDLE_CALL = 0x0080,
        POSTANIM_ACTION_HAND_GRIP_WEAPON = 0x0100,
        POSTANIM_ACTION_GETOUT_OF_FURNITURE = 0x0200,
        POSTANIM_FORCEIDLE_ANIMATION = 0x0400,
        POSTANIM_FREEUP_SPECIAL_IDLE = 0x0800,
        POSTANIM_RELOAD_TARGETS = 0x1000,
        POSTANIM_ACTION_IDLE_LOADED = 0x2000,
        POSTANIM_ACTION_HAVOKWEAPON = 0x4000,
        POSTANIM_ACTION_BLOCK = 0x8000,
        POSTANIM_ACTION_SET_IRON_SIGHTS = 0x00010000,
        POSTANIM_ACTION_EXPEL_SHELLCASING = 0x00020000,
        POSTANIM_ACTION_RELOAD_SINGLE = 0x00040000,
        POSTANIM_ACTION_START_LOOPING_RELOAD = 0x00080000,
    };
    ActorPackage CurrentPackage; // 0x04
    float fSystemTimeClock; // 0x1c
    float fHourLastProcessed; // 0x20
    unsigned int iDateLastProcessed; // 0x24
    PROCESS_TYPE eLevel; // 0x28
    CachedValues *pCachedValues; // 0x2c

    BaseProcess(const BaseProcess &);
    BaseProcess();
    virtual ~BaseProcess();
    virtual void Copy(BaseProcess *);
    virtual void HandleDeletedReference(TESObjectREFR *);
    PROCESS_TYPE GetProcessLevel();
    void SetProcessLevel(PROCESS_TYPE);
    virtual void Update(MobileObject *, float);
    virtual void Update(MobileObject *);
    virtual void UpdateMissedPackages(MobileObject *, bool);
    virtual const NiPoint3 GetCurrentPackageLocation(Actor *);
    virtual NiPoint3 GetLastPositionDetected(Actor *, int);
    virtual float GetLastTimeDetected(Actor *, int);
    virtual bool CheckforNewPackage(Actor *, bool);
    virtual void ComputeLastTimeProcessed();
    virtual bool IsWandering();
    void SetLastTimeProcessed(float);
    float GetLastTimeProcessed();
    unsigned int GetLastDateProcessed();
    void SetLastDateProcessed(unsigned int);
    virtual int GetProcessedDay();
    virtual int GetProcessedMonth();
    virtual int GetProcessedYear();
    virtual void SetPackageEvaluateHour(int);
    virtual int GetPackageEvaluateHour();
    virtual bool SetupSpecialIdle(
        MobileObject *, TESIdleForm *, AnimIdle::PLAY_TYPE_ENUM, bool, bool, bool
    );
    virtual void SetLastSeenLocation();
    virtual MagicItem *GetCurrentPackageSpell();
    virtual void SetCurrentPackageSpell(MagicItem *);
    virtual void PerformOneRoundofCombat(Actor *, int);
    virtual void ClearFaceAnimationData();
    virtual void UpdateHealthBar(Actor *);
    virtual bool GetIdleDoneOnce();
    virtual void SetIdleDoneOnce(bool);
    virtual bool EvaluateDetection(Actor *);
    virtual void EvaluateCombatDetectionLists(Actor *);
    virtual bool ShouldRunPlayerDetection(Actor *);
    virtual bool ProcessActivateOneHour(Actor *, float);
    virtual bool IsDoingSayTo();
    virtual void ProcessSandman(Actor *);
    virtual void ProcessCannibal(Actor *);
    virtual void ClearFurniture(Actor *);
    virtual void SetDoingSayTo(bool);
    virtual bool SetTargetForPackage(Actor *);
    virtual TESObjectREFR *SetLocationForPackage(Actor *, bool);
    virtual TESObjectREFR *GetCurrentDestinationReference(Actor *, bool);
    virtual NiPoint3 GetCurrentDestinationCoordinate(Actor *, bool);
    virtual TESObjectCELL *GetCurrentDestinationCell(Actor *);
    virtual TESWorldSpace *GetCurrentDestinationWorldSpace(Actor *);
    virtual float GetCurrentDestinationRadius(Actor *);
    virtual MobileObject *GetDialogTarget();
    virtual void ClearDialogTarget();
    virtual bool CheckAndStartCombatControllerForPackage(Actor *, TESPackage *, bool);
    virtual bool ShouldUpdateCombatControllerOrEndCombat(Actor *, TESPackage *&);
    virtual float GetSocialTalkTimer();
    virtual void SetSocialTalkTimer(float);
    virtual void RemoveSpokenToActor(Actor *);
    virtual void ProcessRemoveWorn(Actor *, bool);
    virtual void CreateFollowforEscort(Actor *, TESPackage *, bool);
    virtual bool GetDetectAlert();
    virtual void SetDetectAlert(bool);
    virtual void RandomlyPlaySpecialIdles(Actor *);
    virtual void PostAnimFreeUpSpecialIdle(Actor *);
    virtual void ResetSearchTimer();
    virtual void ModEssentialDownTimer();
    virtual float GetEssentialDownTimer();
    virtual void SetEssentialDownTimer(float);
    virtual void ResetSearchChatterTimer();
    virtual DetectionState *
    InsertIntoDetectionList(Actor *, DETECTION_LEVEL, bool, int, int, bool, bool);
    virtual BSSimpleList<DetectionState *> *GetWhoDetectsMe(Actor *);
    virtual DetectionEvent *GetActorsDetectionEvent(Actor *);
    virtual void SetActorsDetectionEvent(Actor *, NiPoint3, int, int, TESObjectREFR *);
    virtual void RemoveDetectionEvent();
    virtual void CheckForExpiredDetectionEvent();
    virtual float GetWeaponScore();
    virtual void SetWeaponScore(float);
    virtual bool GetPickpocketed();
    virtual void SetPickpocketed(bool);
    void ResetDelayTimer();
    void ResetTalkTimer();
    virtual void SetCurrentActionComplete(bool);
    virtual bool GetCurrentActionComplete();
    virtual void SetCurrentMovementComplete(bool);
    virtual bool GetCurrentMovementComplete();
    virtual TESObjectREFR *GetTarget();
    virtual void SetTarget(TESObjectREFR *);
    virtual TESObjectREFR *GetDoor();
    virtual void SetDoor(TESObjectREFR *);
    virtual void SetAcquireObject(ObjectstoAcquire *);
    virtual ObjectstoAcquire *GetSavedAcquireObject();
    virtual void SetSavedAcquireObject(ObjectstoAcquire *);
    virtual BSFaceGenAnimationData *GetFaceAnimationData(Actor *);
    virtual ItemChange *GetCurrentWeapon();
    virtual ItemChange *GetCurrentAmmo();
    virtual bool GetLipQuequed();
    virtual void SetLipQuequed(bool);
    virtual int GetNumberOfItemsActivated();
    virtual void SetNumberOfItemsActivated(int);
    virtual bool SetCurrentWeapon(ItemChange *, NiNode *, bool);
    virtual bool SetCurrentTorch(ItemChange *);
    virtual bool SetCurrentAmmo(ItemChange *);
    virtual bool SetCurrentShield(ItemChange *);
    virtual void ResolveEquipmentQueue(Actor *);
    virtual bool IsItemQueued(TESBoundObject *, ExtraDataList *, bool);
    virtual void AddQueuedItem(
        Actor *,
        bool,
        TESBoundObject *,
        int,
        ExtraDataList *,
        bool,
        bool,
        bool,
        bool,
        bool,
        bool
    );
    virtual void RemoveQueuedItem(TESBoundObject *, ExtraDataList *);
    virtual void RemoveAllQueuedItems();
    virtual NiAVObject *GetFireNode();
    virtual void SetFireNode(NiAVObject *);
    virtual void StoreBonePointers(NiControllerManager *, NiNode *);
    virtual NiNode *GetWeaponBone(BipedAnim *);
    virtual NiNode *GetTorchBone(BipedAnim *);
    virtual NiNode *GetShieldBone(BipedAnim *);
    virtual NiNode *GetQuiverBone(BipedAnim *);
    virtual NiNode *GetRightWeaponBone(BipedAnim *);
    virtual NiNode *GetLeftWeaponBone(BipedAnim *);
    virtual bool IsCurrentWeaponGrenade();
    virtual bool IsCurrentWeaponMine();
    virtual bool IsCurrentWeaponGrenadeOrMine();
    virtual bool IsCurrentWeaponThrown();
    virtual Animation *GetAnimation();
    virtual bool GetLockedLocation();
    virtual void SetLockedLocation(bool);
    virtual bool GetIsAggressor();
    virtual void SetIsAggressor(bool);
    virtual void ForceWeaponDrawnSheathed(bool, BipedAnim *, Animation *, Actor *);
    virtual void SetItemBeingUsed(TESBoundObject *);
    virtual TESBoundObject *GetItemBeingUsed();
    virtual void UpdateReparentWeapon(Actor *);
    virtual void CreateFollownoEscort(Actor *, bool);
    virtual float GetAwarePlayerTimer();
    virtual void ModAwarePlayerTimer(float);
    virtual void SetCombatDelayTimer(float);
    virtual bool CheckCombatDelayTimer();
    virtual void AddTalkedtoActor(Actor *);
    virtual bool ComputeCanInitiateDialogueWithNPC(Actor *, Actor *);
    virtual bool ComputeCanRespondToDialogueFromNPC(Actor *, Actor *);
    virtual bool IsActorInsideAmbushArea(Actor *, Actor *);
    virtual bool CheckIfThereSomeoneTalkWith(Actor *);
    virtual bool ComputeAllowSandboxConversation(Actor *, Actor *);
    virtual float GetPotentialThreatDamage(Actor *, Actor *);
    virtual TESPackage *GetRunOncePackage();
    virtual void SetRunOncePackage(TESPackage *, MobileObject *);
    virtual void ClearRunOncePackage();
    virtual void SetRunOnceProcedureIndex(int);
    virtual int GetRunOnceProcedureIndex();
    virtual void AddToRunOnceProcedureIndex(int);
    virtual void ClearGreetingInfoData();
    virtual bool IsPackageDone(Actor *);
    virtual TESPackage *GetCurrentPackage();
    virtual void SetCurrentPackage(TESPackage *, MobileObject *);
    virtual void ClearCurrentPackage();
    virtual void SetCurrentProcedureIndex(int);
    virtual int GetCurrentProcedureIndex();
    virtual void AddToCurrentProcedureIndex(int);
    virtual void SetupNewPackage();
    virtual DialogueItem *GetSubtitleItem();
    virtual void SetSubtitleItem(DialogueItem *);
    virtual void
    AddAvoidPathingArea(Actor *, NiPoint3, float, float, TESObjectREFR *, TESObjectSTAT *);
    virtual PathingAvoidNodeArray *CreateAvoidArray(Actor *);
    virtual bool IsAvoidAreaInAvoidPathingList(TESObjectREFR *);
    virtual void SetAvoidWaitTimer(float);
    virtual void RemoveAvoidPathingNode(TESObjectREFR *);
    virtual float GetHeadTrackChangeTimer();
    virtual void SetHeadTrackChangeTimer(float);
    virtual void ClearLastHeadTrackTarget();
    ActorPackageData *GetCurrentPackageInstanceData();
    virtual ActorPackageData *GetRunOncePackageInstanceData();
    virtual ActorPackageData *GetInstanceDataThatIsRunning();
    virtual ActorPackage *GetActorPackageThatIsRunning();
    virtual TESPackage *GetPackageThatIsRunning();
    virtual int GetProcedureIndexRunning();
    virtual void SetProcedureIndexRunning(int);
    virtual void AddToProcedureIndexRunning(MobileObject *, int);
    virtual bhkCharacterController *GetCharController();
    virtual void SetCharController(NiPointer<bhkCharacterController>);
    virtual void EndMoveMessage(Actor *);
    virtual void ProcessFollow(Actor *, bool, int, bool);
    virtual void ProcessPursue(Actor *, bool, bool, int);
    virtual void ProcessFlee(Actor *);
    virtual void ProcessGreet(Actor *, TESTopic *, bool, bool, bool, bool);
    virtual void ProcessObserveCombat(Actor *);
    virtual void ProcessGetUpOneHour(Actor *);
    virtual bool SitOrSleep(Actor *);
    virtual bool ShouldDisableCharController(TESObjectREFR *, unsigned int);
    virtual bool ProcessGetUp(Actor *);
    virtual void ProcessTravel(Actor *, bool, bool, int, bool);
    virtual WadingWaterData *GetWadingWaterData();
    virtual void RemoveDetectionActor(Actor *, int);
    virtual void SetDetectionTimer(float);
    virtual bool GetLineSightonActor(Actor *, Actor *, int, bool);
    virtual bool Get360LineSightonActor(Actor *, Actor *, int);
    virtual int GetDetectionActor(Actor *, int);
    virtual bool GetTalkingtoPC();
    virtual void SetTalkingtoPC(bool);
    virtual void UpdateFollowers(Actor *, float);
    virtual int GetEmotionsDispostion(Actor *, TESObjectREFR *);
    virtual DIALOGUE_EMOTION GetLastSpeakingEmotion() const;
    virtual void SetLastSpeakingEmotion(DIALOGUE_EMOTION);
    virtual void RunDetection(Actor *, float);
    virtual float GetDetectionTimer();
    virtual void ReduceDetectionTimer();
    virtual void SetBreathTimer(float);
    virtual float GetBreathTimer();
    virtual void SetSurfacing(bool);
    virtual bool GetSurfacing();
    virtual bool GetGreetingFlag();
    virtual void SetGreetingFlag(bool);
    virtual float GetSoundDelay();
    virtual void SetSoundDelay(float);
    virtual bool GetAlert();
    virtual void SetAlert(bool);
    virtual bool GetFinishingCombatPackage();
    virtual void SetFinishingCombatPackage(bool);
    virtual ItemChange *CreateWeaponAcquireList(Actor *, PACKAGE_OBJECT_TYPE);
    virtual void ClearAcquireList();
    virtual float GetIdleTimer();
    virtual void SetIdleTimer(float);
    virtual bool EnterCombat(
        Actor *,
        Actor *,
        bool,
        bool,
        CombatGroup *,
        bool,
        bool,
        bool,
        char,
        bool,
        bool,
        bool,
        TESPackage *
    );
    virtual void GuardCallforHelp(Actor *, Actor *);
    virtual void CallforHelp(Actor *, Actor *, Crime *);
    virtual void SetNumberGuardsArresting(int);
    virtual int CalculateMoveMode(Actor *, float, float, float, bool, bool);
    virtual void SetActorsAnimation(Actor *, int, bool);
    virtual void FinishDying(Actor *);
    virtual bool ProcessStandOff(Actor *, float, int);
    virtual bool IsRunningRunOnce();
    virtual bool IsAFollower();
    virtual void SetFollower(bool);
    virtual int GetWeaponCondition(Actor *);
    virtual bool GetWaitingforLipFile();
    virtual void SetWaitingforLipFile(bool);
    virtual void SetLipFileFailed(bool);
    virtual bool GetLipFileFailed();
    virtual LipSynchAnim *GetLipAnim();
    virtual void SetLipAnim(LipSynchAnim *);
    virtual void SetPlantedExplosive(bool);
    virtual bool GetPlantedExplosive();
    virtual TESIdleForm *GetLastIdlePlayed();
    virtual void SetLastIdlePlayed(TESIdleForm *);
    virtual void FreeUpSpecialIdle(Actor *);
    virtual int GetActorValue(TESActorBase *, ActorValue::Index, Actor *);
    virtual float GetActorFloatValue(TESActorBase *, ActorValue::Index, Actor *);
    virtual void TempModActorValue(Actor *, ActorValue::Index, float);
    virtual void TempModActorValue(Actor *, ActorValue::Index, int);
    virtual void DamageModActorValue(Actor *, ActorValue::Index, float);
    virtual void DamageModActorValue(Actor *, ActorValue::Index, int);
    virtual void SetCachedActorValueOutOfDate(ActorValue::Index);
    virtual void InitializeActiveEffectList();
    virtual BSSimpleList<ActiveEffect *> *GetActiveEffectList();
    virtual void DestroyActiveEffectList();
    virtual void CastAbility(MagicCaster *, SpellItem *, bool);
    virtual void TransferDisease(MagicCaster *, SpellItem *, MagicTarget *, bool);
    virtual MagicItem *GetCurrentSpell();
    virtual void SetCurrentSpell(MagicItem *);
    virtual MagicTarget *GetDesiredTarget();
    virtual void SetDesiredTarget(MagicTarget *);
    virtual bool GetShouldCheckMagicNode();
    virtual void SetShouldCheckMagicNode(bool);
    virtual void Move(MobileObject *, NiPoint3);
    virtual ANIMATION_ACTION GetAnimAction();
    virtual BSAnimGroupSequence *GetAnimActionAnimSeq();
    virtual void SetAnimAction(ANIMATION_ACTION, BSAnimGroupSequence *);
    virtual bool GetAutomaticFireAtLeastOnce();
    virtual void SetAutomaticFireAtLeastOnce(bool);
    virtual bool CanAttack();
    virtual bool CanForceGreet(Actor *);
    virtual void SetIronSights(bool);
    virtual bool GetIronSights();
    virtual bool HasMovementAnim(ANIM_GROUP_ENUM);
    virtual KNOCK_STATE_ENUM GetKnockState();
    virtual void SetKnockState(KNOCK_STATE_ENUM);
    virtual void KnockDown(Actor *);
    virtual void KnockExplosion(Actor *, NiPoint3, float);
    virtual void UpdateKnockState(Actor *);
    virtual void ClearKnockState(Actor *);
    virtual void SetAimSequence(AIM_ENUM, BSAnimGroupSequence *);
    virtual void UpdateAimSequences(Actor *);
    virtual float GetAimLooking();
    virtual void AddGunDrift(float);
    virtual void ClearAutomaticShotsToFire(bool);
    virtual unsigned char GetAutomaticShotsToFire(Actor *);
    virtual void SetShotsToFire(unsigned char);
    virtual unsigned char GetShotsToFire();
    virtual float GetAutomaticShotDelay();
    virtual void AttackCallback(int);
    virtual bool GetWantWeaponDrawn();
    virtual void SetWantWeaponDrawn(bool);
    virtual bool GetWeaponDrawn();
    virtual void SetWeaponDrawn(Actor *, bool);
    virtual void SaveWeaponLastPos(NiPoint3);
    virtual const NiPoint3 *GetWeaponLastPos();
    virtual void Update3dModel(Actor *);
    virtual void Set3DUpdateFlag(RESET_3D_FLAGS);
    virtual void Clear3DUpdateFlag(RESET_3D_FLAGS);
    virtual void ClearAll3DUpdateFlags();
    virtual bool Get3DUpdateFlag(RESET_3D_FLAGS);
    virtual unsigned char GetAll3DUpdateFlags();
    virtual void ClearObjectFromAcquireList(TESObjectREFR *);
    virtual void ClearObjectFromAcquireList(unsigned int);
    virtual TESObjectREFR *GetLastGreeted();
    virtual void SetLastGreeted(TESObjectREFR *);
    virtual BSSoundHandle GetSoundHandle(ACTOR_SOUND_HANDLE);
    virtual void SetSoundHandle(ACTOR_SOUND_HANDLE, BSSoundHandle);
    virtual void StopSoundHandle(ACTOR_SOUND_HANDLE);
    virtual void StartTorchSound(Actor *);
    virtual bool GetMovementStoped();
    virtual void ClearMovementStoped();
    virtual void SetDetectionModifier(float);
    virtual void SetDetectionModifierTimer();
    virtual float GetDetectionModifier();
    virtual float GetGreetingTimer();
    virtual void SetGreetingTimer(float);
    virtual bool IsTalking(MobileObject *);
    virtual SIT_SLEEP_STATE GetSitSleepState();
    virtual void
    SetSitSleepState(Actor *, SIT_SLEEP_STATE, TESObjectREFR *, unsigned char);
    virtual unsigned int GetFurnitureMarkerID();
    virtual TESObjectREFR *GetCurrentFurniture();
    virtual void ClearCurrentFurniture(TESObjectREFR *);
    virtual unsigned int GetCurrentFurnitureIndex();
    virtual FurnitureMark *GetFurnitureMarker();
    virtual bool LoadDynamicIdle(Actor *);
    virtual void LoadSitSleepIdle(Actor *, Animation *);
    virtual bool ContinuingPackageforPC();
    virtual void SetContinuingPackage(bool);
    virtual bool IsTargetActivated();
    virtual void SetTargetActivated(bool);
    virtual bool HasBeenAttacked();
    virtual void SetBeenAttacked(bool);
    virtual BSShaderPPLightingProperty *GetLightingShaderProperty();
    virtual void SetLightingShaderProperty(BSShaderPPLightingProperty *);
    virtual void CalculateLightValue(Actor *, bool);
    virtual DetectionState *GetDetectionState(Actor *, int);
    virtual DetectionState *InsertIntoDetectionArray(Actor *, DETECTION_LEVEL);
    virtual float GetLightLevelTimer();
    virtual void SetLightLevelTimer(float);
    virtual TESObjectREFR *GetGenericLocation();
    virtual void SetGenericLocation(TESObjectREFR *);
    virtual TESObjectREFR *GetSecondGenericLocation();
    virtual void SetSecondGenericLocation(TESObjectREFR *);
    virtual void ClearCurrentDataforProcess(Actor *);
    virtual void SetCommandingActor(Actor *);
    virtual Actor *GetCommandingActor();
    virtual void SetLastBoundWeapon(TESObjectWEAP *);
    virtual TESObjectWEAP *GetLastBoundWeapon();
    virtual void SetPackageEndTimerValue(float);
    virtual float GetPackageEndTimerValue();
    virtual void SetFurniture(TESObjectREFR *, unsigned char, FurnitureMark *);
    virtual void RemoveAndAttachItems(MobileObject *);
    virtual unsigned short GetSaveSize(unsigned int, MobileObject *);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int, MobileObject *);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int, MobileObject *);
    virtual void InitLoadGame(BGSLoadFormBuffer *);
    virtual void InitLoadGame(unsigned int, unsigned int, MobileObject *);
    virtual void FinishInitLoadGame(unsigned int, unsigned int, MobileObject *);
    virtual void Revert(BGSLoadFormBuffer *);
    virtual void Revert(unsigned int, MobileObject *);
    virtual void FinishLoadGame(BGSLoadFormBuffer *);
    virtual TESEffectShader *GetWeaponEnchantmentVisuals();
    virtual void SetWeaponEnchantmentVisuals(TESEffectShader *);
    virtual bool GetShouldRefreshMagicShadersEffects();
    virtual void SetShouldRefreshMagicShadersEffects(bool, bool, bool);
    virtual void RefreshMagicShaderEffects(Actor *);
    virtual void SetBeginIdlesPlayed(bool);
    virtual bool GetBeginIdlesPlayed();
    virtual void SetEndIdlesPlayed(bool);
    virtual bool GetEndIdlesPlayed();
    virtual void StartNewPackage(Actor *, TESPackage *);
    virtual void ChangePackage(Actor *, TESPackage *);
    virtual void PackageDone(Actor *, TESPackage *);
    virtual bool IsPackageDoneOnce();
    virtual void SetPackageDoneOnce(bool);
    virtual float GetAlphaMult();
    virtual void SetAlphaMult(float);
    virtual float GetScriptRefractionPower();
    virtual void SetScriptRefractionPower(float);
    virtual void UpdateWadingWater(Actor *);
    virtual int GetNumberGuardsArresting();
    virtual void ModNumberGuardsArresting(int);
    virtual bool ShouldCheckFlare(BSSimpleList<ActiveEffect *> *, MagicSystem::FlareType);
    virtual void SetRefreshFlareFlags();
    virtual BSSimpleList<SpellItem *> *GetLeveledSpells(Actor *, bool);
    virtual void SetHasHealingSpells(int);
    virtual int GetHasHealingSpells();
    virtual void SetHasHealingPotions(int);
    virtual int GetHasHealingPotions();
    virtual float GetTemporaryModifier(ActorValue::Index);
    virtual float GetPermanentModifier(ActorValue::Index);
    virtual float GetDamageModifier(ActorValue::Index);
    virtual BSBound *GetBSBound();
    virtual void SetBSBound(BSBound *);
    virtual void SetForceNextUpdate(bool);
    virtual bool GetForceNextUpdate();
    virtual void SetNeedTalkPlayer(bool);
    virtual bool GetNeedTalkPlayer();
    virtual BSSimpleList<Actor *> *GetAggroRadiusActorList();
    virtual void NotifyGuardAboutActivation(Actor *, TESObjectREFR *, TESObjectREFR *);
    virtual BaseProcess::FADE_STATE GetFadeState();
    virtual void AddPostAnimationAction(BaseProcess::POSTANIM_ACTION);
    virtual BaseProcess::POSTANIM_ACTION GetPostAnimationActions();
    virtual void ClearPostAnimationActions();
    virtual void RemovePostAnimationAction(BaseProcess::POSTANIM_ACTION);
    virtual void SetDefaultHeadTrackTarget(TESObjectREFR *);
    virtual void SetActionHeadTrackTarget(TESObjectREFR *);
    virtual void SetScriptHeadTrackTarget(TESObjectREFR *);
    virtual void SetCombatHeadTrackTarget(TESObjectREFR *);
    virtual void SetDialogHeadTrackTarget(TESObjectREFR *);
    virtual void SetUseWeaponHeadTrackTarget(TESObjectREFR *);
    virtual void SetHeadTrackTarget(BaseProcess::HEAD_TRACK_TYPE, TESObjectREFR *);
    virtual void ClearDefaultHeadTrackTarget();
    virtual void ClearActionHeadTrackTarget(bool);
    virtual void ClearScriptHeadTrackTarget(bool);
    virtual void ClearCombatHeadTrackTarget();
    virtual void ClearDialogHeadTrackTarget(bool);
    virtual void ClearUseWeaponHeadTrackTarget(bool);
    virtual void ModDetectionModifierTimer();
    virtual float GetDetectionModifierTimer();
    virtual void ClearAllHeadTrackTargets();
    virtual void RemoveHeadTrackTarget(TESObjectREFR *);
    virtual bool CanSetDefaultHeadTrackTarget();
    virtual bool CanSetActionHeadTrackTarget();
    virtual bool CanSetCombatHeadTrackTarget();
    virtual TESObjectREFR *GetCurrentHeadTrackTarget(BaseProcess::HEAD_TRACK_TYPE);
    virtual TESObjectREFR *GetCurrentHeadTrackTarget();
    virtual BaseProcess::HEAD_TRACK_TYPE GetCurrentHeadTrackType();
    virtual const char *GetCurrentHeadTrackTypeString();
    virtual void SetForceRotate(bool);
    virtual bool GetForceRotate();
    virtual TESObjectREFR *GetLastHeadTrackTarget();
    virtual bool IsInLastDefaultTargetArray(TESObjectREFR *);
    virtual void SetIsSummonedCreature(bool);
    virtual bool GetIsSummonedCreature();
    virtual float GetDeathTime();
    virtual void SetDeathTime(float);
    virtual void AddAttachedArrow(ArrowProjectile *);
    virtual void RemoveAttachedArrow(ArrowProjectile *);
    virtual void MoveAttachedArrowsToParentCell(TESObjectREFR *);
    virtual BSSimpleList<ArrowProjectile *> *GetAttachedArrowList();
    virtual void CreateMuzzleFlash(Projectile *, TESObjectREFR *);
    virtual MuzzleFlash *GetCurrentMuzzleFlash();
    virtual bool GetEnableMuzzleFlash();
    virtual void EnableMuzzleFlash();
    virtual void ClearMuzzleFlash();
    virtual void StoreDamageNodes(NiNode *, BGSBodyPartData *);
    virtual void StoreDismemberedLimbNode(BGSBodyPart::LIMB_ENUM, NiNode *);
    virtual NiNode *GetDamageNode(BGSBodyPart::LIMB_ENUM);
    virtual NiAVObject *GetHeadNode();
    virtual NiAVObject *GetTorsoNode();
    virtual bool IsSustainedFire();
    virtual void SetSustainedFire(bool);
    virtual void UpdateArmorWorn(Actor *);
    virtual bool IsHeavyBodyArmorWorn();
    virtual bool IsPowerBodyArmorWorn();
    virtual bool IsPowerArmorHelmetWorn();
    virtual bool HasBackPackWorn();
    virtual void SetCurrentlyReanimating(bool);
    virtual bool GetCurrentlyReanimating();
    virtual void UpdateRadiation(Actor *, float);
    virtual void TryReserveProjectileClones(Actor *);
    virtual void SetAnimActionSuccess(int);
    virtual void FinishSetupSpecialIdle(Actor *);
    virtual void SavePackageToExtraData(MobileObject *);
    virtual void LoadPackageFromExtraData(MobileObject *);
    virtual TESIdleForm *GetCurrentProcessIdle();
    virtual void SetCurrentProcessIdle(TESIdleForm *);
    virtual void SetCurrentProcessAnimIdleLoaded(AnimIdle *, KFModel *);
    virtual AnimIdle *GetCurrentProcessAnimIdle();
    virtual KFModel *GetCurrentProcessAnimIdleKF();
    virtual void ModTrackedDamage(Actor *, float);
    virtual float GetTrackedDamage();
    virtual float GetActorLightLevel();
    virtual void SetActorLightLevel(float);
    virtual void
    DeferHideDismemberedLimb(BGSBodyPart::LIMB_ENUM, NiNode *, NiAVObject *, bool);
    virtual void UpdateDeferredHideDismemberedLimbs(Actor *, float);
    virtual void SetCreatureLipSynchAnim(LipSynchAnim *);
    virtual LipSynchAnim *GetCreatureLipSynchAnim();
    virtual void SetCreatureLipSynchStartTime(unsigned int);
    virtual unsigned int GetCreatureLipSynchStartTime();
    virtual void AddRadiationMagicDelta(float);
    virtual void RemoveRadiationMagicDelta(float);
    virtual float GetRadiationMagicDelta();
    virtual void SetRadiationWaterDelta(float);
    virtual float GetRadiationWaterDelta();
    virtual void SetRadiationDelta(float);
    virtual float GetRadiationDelta();
    virtual HitData *GetLastHitData();
    virtual void SetLastHitData(HitData *);
    virtual void ClearLastHitData();
    virtual HitData *GetLastAttackHitData();
    virtual void SetLastAttackHitData(HitData *);
    virtual void ClearLastAttackHitData();
    virtual int GetWeaponConditionStage();
    virtual void SetWeaponConditionStage(int);
    virtual BSFaceGenNiNode *GetFaceNode();
    virtual void SetFaceNode(BSFaceGenNiNode *);
    virtual BSFaceGenNiNode *GetFaceSkinnedNode();
    virtual void SetFaceSkinnedNode(BSFaceGenNiNode *);
    virtual NiAVObject *GetHeadAnims();
    virtual void SetHeadAnims(NiAVObject *);
    virtual void CheckCachedValueFlags(Actor *);
    virtual void SetPathLookAtTarget(TESObjectREFR *);
    virtual void ClearPathLookTarget(TESObjectREFR *);
    bool HasCachedValues();
    void SetCachedValueDirty(CachedValues::Flags);
    bool IsCachedValueFlagSet(CachedValues::Flags);
    void SetCachedValueFlag(CachedValues::Flags, bool);
    float GetCachedRadius(CachedValuesOwner *);
    float GetCachedWidth(CachedValuesOwner *);
    float GetCachedLength(CachedValuesOwner *);
    float GetCachedForwardLength(CachedValuesOwner *);
    float GetCachedWeaponDPS(CachedValuesOwner *);
    float GetCachedMedicineEffectivenessMult(CachedValuesOwner *);
    float GetCachedParalysis(CachedValuesOwner *);
    float GetCachedHealingRate(CachedValuesOwner *);
    float GetCachedEndurance(CachedValuesOwner *);
    float GetCachedPerceptionCondition(CachedValuesOwner *);
    float GetCachedEyeLevel(CachedValuesOwner *);
    int GetCachedActorAggression(CachedValuesOwner *);
    int GetCachedActorAssistance(CachedValuesOwner *);
    float GetCachedWalkSpeed(CachedValuesOwner *);
    float GetCachedRunSpeed(CachedValuesOwner *);
    bool GetCachedConditionPreventsRun(CachedValuesOwner *);
    float GetCachedSurvivalEffectivenessMult(CachedValuesOwner *);
    void SetCachedRadius(float);
    void SetCachedWidth(float);
    void SetCachedLength(float);
    void SetCachedForwardLength(float);
    void SetCachedWeaponDPS(float);
    void SetCachedMedicineEffectivenessMult(float);
    void SetCachedParalysis(float);
    void SetCachedHealingRate(float);
    void SetCachedEndurance(float);
    void SetCachedPerceptionCondition(float);
    void SetCachedEyeLevel(float);
    void SetCachedActorAggression(int);
    void SetCachedActorAssistance(int);
    void SetCachedWalkSpeed(float);
    void SetCachedRunSpeed(float);
    void SetCachedConditionPreventsRun(bool);
    void SetCachedSurvivalEffectivenessMult(float);
};
