#pragma once

#include "bscore/bssimplelist.h"
#include "fallout/ai/mobileobject.h"
#include "fallout/magic/magictarget.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/teschildcell.h"
#include "fallout_shared/tesform.h"
#include "nimain/nipoint3.h"

class Actor : public MobileObject,
			  public MagicCaster,
			  public MagicTarget,
			  public ActorValueOwner,
			  public CachedValuesOwner { /* Size=0x1c4 */
	/* 0x0000: fields for MobileObject */
	/* 0x0098: fields for MagicCaster */
	/* 0x00a4: fields for MagicTarget */
	/* 0x00b4: fields for ActorValueOwner */
	/* 0x00b8: fields for CachedValuesOwner */
  public:
	bhkRagdollController* pRagdollController;		  // 0x00bc
	bhkRagdollPenetrationUtil* pPenetrationDetection; // 0x00c0
	DIALOGUE_EMOTION ePersuasionEmotion;			  // 0x00c4
	float fEmotionValue;							  // 0x00c8
	bool bProcessMe;								  // 0x00cc
	Actor* pMyKiller;								  // 0x00d0
	bool bMurderAlarm;								  // 0x00d4
	float fCheckMyDeadBodyTimer;					  // 0x00d8
	float fDeadBodyAlarm;							  // 0x00dc
	ModifierList pPermanentModifiers;				  // 0x00e0
	ModifierList pBaseValueOverrides;				  // 0x00f0
	bool bBlockPostAnim;							  // 0x0100
  protected:
	bool bReloadTargetQueued;								// 0x0101
	bool bRunsInLow;										// 0x0102
	BSSimpleList<CastPowerItem*> CastPowers;				// 0x0104
	BSSimpleList<DispositionModifier*> DispModifierList;	// 0x010c
	bool bInCombat;											// 0x0114
	ACTOR_LIFE_STATE eLifeState;							// 0x0118
	ACTOR_CRITICAL_STAGE eCriticalStage;					// 0x011c
	ANIM_GROUP_ENUM eQueuedattack;							// 0x0120
	float fLastUpdate;										// 0x0124
	bool bDeadFlag;											// 0x0128
	int iVisFlags;											// 0x012c
	uint iLastSeenTime;										// 0x0130
	bool bForceRun;											// 0x0134
	bool bForceSneak;										// 0x0135
	bool bForceUpdateQuestTarget;							// 0x0136
	bool bSearchingInCombat;								// 0x0137
	Actor* pCurrentCombatTarget;							// 0x0138
	BSSimpleArray<Actor*, 1024>* pCurrentCombatTargetArray; // 0x013c
	BSSimpleArray<Actor*, 1024>* pCurrentCombatMemberArray; // 0x0140
	bool bAttackOnNextTheft;								// 0x0144
	int iThiefCrimeStamp;									// 0x0148
	uint iMinorCrimes;										// 0x014c
	uint iMajorCrimes;										// 0x0150
	bool bIgnoreCrime;										// 0x0154
	bool bEVPBuffered;										// 0x0155
	bool bResetAI;											// 0x0156
	TESActorBase* pTemplateActorBase;						// 0x0158
	bool bInWater;											// 0x015c
	bool bSwimming;											// 0x015d
	bool bUpdateLighting;									// 0x015e
	int iActionValue;										// 0x0160
	float fTimeronAction;									// 0x0164
	float fHeadTrackTimer;									// 0x0168
	bool bWasInFrustum;										// 0x016c
	bool bShouldRotateToTrack;								// 0x016d
	NiPoint3 EditorLocCoord;								// 0x0170
	float fEditorLocZRot;									// 0x017c
	TESForm* pEditorLocForm;								// 0x0180
	bool bSetOnDeath;										// 0x0184
	bool bContainerReset;									// 0x0185
	float fGunSkillGun;										// 0x0188
	float fGunSkillHUD;										// 0x018c
	float fGunSkillActor;									// 0x0190
	float fGunSkillVATS;									// 0x0194
	float fCurrentWeaponCondition;							// 0x0198
	bool bFootIKInRange;									// 0x019c
	bool bPlayerTeammate;									// 0x019d
	bool bLightingUpdatedNonMoving;							// 0x019e
	ActorMover* pActorMover;								// 0x01a0
	void* pLastHitData;										// 0x01a4
	TESPackage* pInitialPackage;							// 0x01a8
	float fRadiationResistanceMult;							// 0x01ac
  public:
	ContinuousBeamProjectile* pContinuousBeamPersistant; // 0x01b0
  protected:
	int iEmotion;						   // 0x01b4
	int iEmotionValue;					   // 0x01b8
	SIT_SLEEP_STATE cCurrentSitSleepState; // 0x01bc
	bool bTurretBehavior;				   // 0x01c0
	bool bForceHitReaction;				   // 0x01c1

  public:
	static SettingT<INISettingCollection> fDialogHitSoundCooldownMin;
	static SettingT<INISettingCollection> fDialogHitSoundCooldownMax;
	static uint uiDialogHitSoundCooldownNext;
	static bool bAllPointsVisible;

  protected:
	static MobileObject* pTalkingToPlayer;
	static BSCriticalSection SpeakSoundCriticalSection;

  public:
	TESPackage* GetPackage();
	Actor(const Actor&);
	Actor(bool);
	void ConstructorInitialize(bool);
	virtual ~Actor();
	virtual NiAVObject* Load3D(bool);
	void CreateRagdollInstance(NiAVObject*, bool, bool, bool);
	void UpdateRagdollAnimation(bool);
	bool UpdateRagdollAnimState(bool, float);
	void FadeSkins(NiAVObject*, float);
	TESActorBase* GetActorBase();
	virtual const NiPoint3& GetLocationOnReference();
	char GetLastTurn();
	void SetLastTurn(char);
	void InitLightingPropertyPtr(NiAVObject*);
	void PlayPickUpSound(TESBoundObject*, bool, bool);
	const char* GetPickUpSoundName(TESBoundObject*, bool, bool);
	void AddDeathItems();
	bool GetNoPersuasion();
	bool GetNoLeftArm();
	bool GetNoRightArm();
	bool GetNoHead();
	bool HasShadow();
	bool CanCheckCorpses();
	bool CanUseIdle(TESIdleForm*);
	virtual float GetHeading(bool);
	bool HasBlood();
	BGSTextureSet* GetBloodDecalTexture(BGSImpactDataSet*);
	const char* GetBloodSprayModel(BGSImpactDataSet*);
	bool BreathesUnderwater();
	bool BreathesAboveWater();
	bool CheckBreathTimer();
	bool SwimsOnly();
	bool DoesSwim();
	bool DoesWalk();
	bool DoesFly();
	bool FightsInWater();
	bool GetUseBipedAnims();
	bool HasNoRumors();
	bool GetEssential();
	bool GetRespawn();
	virtual void SetHeading(TESObjectREFR*);
	virtual void SetHeading(float);
	bool QDoubleGravity();
	bool IsRunning();
	bool CanRun();
	virtual bool CalculateCachedConditionPreventsRun();
	bool GetConditionPreventsRun();
	void ResetConditionPreventsRun();
	bool IsSwimming();
	void SetSwimming();
	bool IsSneaking();
	bool IsMoving();
	bool IsTurning();
	virtual bool IsParalyzed();
	bool IsFightingOrAlarmed();
	bool IsAllowedToSwim();
	bool IsAllowedToFall();
	bool IsWaiting();
	bool IsSleeping();
	bool IsEating();
	bool IsJumping();
	bool IsSurfacing();
	bool ShouldSkipFallOutBehavior(FALLOUT_BEHAVIORS);
	virtual bool IsActoraGuard();
	virtual void SetActorGuard(bool);
	virtual void SetEquippedWeight(float);
	virtual float GetEquippedWeight();
	virtual bhkCharacterController* Jump();
	float GetGunSkill(GUN_SKILL_ENUM);
	void SetAlert(bool);
	bool GetAlert();
	bool GetAlertSearch();
	virtual void CleanUpPointersOnDisable();
	bool GetSearchingInCombat();
	void SetSearchingInCombat(bool);
	Actor* GetCurrentCombatTarget();
	bool IsCombatGroupMember(Actor*);
	void UpdateCombatData();
	bool GetGhost();
	void SetGhost(bool);
	bool CanSkipActorUpdate();
	void ClearMoveModeAll();
	void SetWantWeaponDrawn(bool);
	bool GetWantWeaponDrawn();
	NiPoint3 GetWeaponReleasePoint();
	SEX GetSex();
	bool IsAutoCalc();
	void PlaceHorseAtMarker(TESObjectREFR*, float&, NiPoint3);
	virtual int GetFame();
	virtual int GetInfamy();
	virtual bool IsActor();
	bool ShouldActorAvoidRadiation();
	const char* GetClassFullName();
	const char* GetRaceFullName();
	virtual TESWorldSpace* GetEditorLocationWorld();
	virtual TESObjectCELL* GetEditorLocationInteriorCell();
	virtual NiPoint3 GetEditorLocationCoord();
	void SetEditorLocation(TESWorldSpace*, TESObjectCELL*, const NiPoint3&,
						   float);
	void SetEditorLocation();
	void SetEditorLocationForm(TESForm*);
	virtual bool HasEditorLocation();
	virtual bool GetEditorLocation(NiPoint3&, NiPoint3&, TESForm*&, TESForm*);
	void IncrementMinorCrimes();
	int GetMinorCrimesNumber();
	void IncrementMajorCrimes();
	int GetMajorCrimesNumber();
	void SetActorRefEssential(bool);
	bool IsActorRefEssential();
	void SetAlwaysShowSubtitlesFlag(bool);
	bool AlwaysShowSubtitles();
	virtual void SetIgnoreCrime(bool);
	virtual bool GetIgnoreCrime();
	void Kill(Actor*, float);
	void SetAttackOnThieft(bool);
	void DropAddOnObjects();
	virtual void Resurrect(bool, bool, bool);
	virtual void ResetInventory(bool);
	void GetOutofFurnitureQuick();
	bool PutActorInChairBedQuick(TESObjectREFR*, FurnitureMark*, int, bool);
	uint16_t GetLevel();
	virtual uint16_t GetActorLevel();
	void SetSpellPoints(int);
	void ModSpellPoints(int);
	WeaponObject* SetHavokWeapon(bool);
	WeaponObject* SetHavokWeapon();
	virtual void SetAdvanceNumber(int);
	virtual int GetAdvanceNumber();
	virtual void SetSkillAdvanceDelayed(ActorValue::Index);
	virtual ActorValue::Index GetSkillAdvanceDelayed();
	float GetFatigue();
	virtual bool DoDamage(float, float, Actor*);
	float GetFatiguePercentage();
	float GetHealthPercentage();
	virtual void UseActionPoints(float);
	virtual void UseActionPoints(ActionPoints::Action);
	void RestoreHealth(float);
	void RestoreFatigue(float);
	void RestoreActionPoints(float);
	void RestoreActorValue(ActorValue::Index, float);
	void RestoreFullHealthAndConditions();
	float GetHealingRate();
	float GetEndurance();
	float GetPerceptionCondition();
	float GetMedicineEffectivenessMultiplier();
	float GetSurvivalEffectivenessMultiplier();
	uint GetBarterGoldBase();
	void SetBarterGoldBase(uint);
	int GetActorBaseAggression();
	int GetActorBaseConfidence();
	int GetActorBaseEnergyLevel();
	int GetActorBaseResponsibility();
	int GetActorBaseMood();
	float GetActorBaseSpeedMult();
	virtual int GetDisposition(Actor*, DispositionParamData*);
	virtual void Process(float);
	virtual void Update(float);
	void UpdateActor3DPosition();
	virtual void UpdateMovement(float, bool);
	virtual void UpdateNonRenderSafeMovement(float, bool);
	virtual void UpdateAnimation(float);
	virtual void UpdateAnimationMovementNoWorldUpdate();
	void ResetLoadedAnimations();
	void StartGreetingPlayer(TESTopic*);
	virtual Animation* GetAnimation();
	bool GetAnimationMoveDelta(NiPoint3&);
	void UpdateAnimationMovement(Animation*, float);
	virtual void UpdateRefLight();
	void SetForceUpdateQuest(bool);
	int GetCurrentPackageProcedure();
	const NiPoint3 GetCurrentPackageCoordinate();
	bool IsCurrentPackage(TESPackage*);
	const char* GetCurrentPackageType();
	PackageLocation* GetCurrentPackageLocation();
	virtual TESObjectREFR* GetCurrentTarget();
	TESObjectREFR* GetCurrentPackageDoorRef();
	void SetCurrentTarget(TESObjectREFR*);
	TESObjectREFR* GetCurrentPackageTarget();
	TESPackage* GetCurrentEditorPackage();
	TESPackage* GetPackageSetAsPcurrent();
	void UnlockLockDoorsProcedure();
	void EvaluatePackage(bool, bool);
	bool WillBuyObject(Actor*);
	bool WillSellObject(Actor*);
	void InitiateDoNothingPackage();
	void InitiateUseWeaponPackage(TESBoundObject*, TESObjectREFR*,
								  TESObjectREFR*, int, TESObjectREFR*, bool,
								  bool, bool, bool);
	void InitiateSummonCreatureDefendPackage(Actor*);
	void InitiateAggroRadiusGuardPackage(Actor*);
	void InitiateExplosionReactionPackage(TESObjectREFR*, Actor*);
	void InitiateGrenadeMineReactionPackage(TESObjectREFR*, Actor*, bool);
	void InitiateSurfacePackage();
	void InitiateAvoidPackage(TESObjectREFR*, float);
	void InitiateMovementBlockedPackage();
	bool IsinSpectator();
	bool IsAlarmed();
	void ClearProcessAcquireList();
	ItemChange* CreateWeaponAmmoAcquireList(PACKAGE_OBJECT_TYPE);
	void StealAlarm(TESObjectREFR*, TESBoundObject*, int, int, TESForm*);
	void PickpocketAlarm(TESObjectREFR*, TESBoundObject*, int);
	void AttackAlarm(TESObjectREFR*, bool, bool);
	void MurderAlarm(TESObjectREFR*);
	int TrespassAlarm(TESObjectREFR*, TESForm*, int);
	void MoveActorAndFollowers(TESObjectREFR*, bool, bool);
	void MoveActorAndFollowers(const NiPoint3&, float, TESObjectCELL*,
							   TESWorldSpace*, bool, bool);
	float GetRadius();
	float GetWidth();
	float GetLength();
	float GetForwardLength();
	float GetHeight();
	float GetSneakHeight(bool);
	bool CanSneak();
	float IsPointDeepUnderWater(const float, TESObjectCELL*);
	bool IsPointDeepUnderWater(const NiPoint3&, TESObjectCELL*, float);
	virtual float GetTurningSpeed();
	float GetCurrentSpeed();
	float GetMaxCarryWeight();
	float GetEquippedEncumbrance();
	virtual bool IsOverEncumbered();
	virtual bool IsCreature();
	virtual bool IsHumanoidCreature();
	virtual bool IsPc();
	bool IsVampire();
	bool IsMountPointClear();
	virtual bool GetCannibal();
	virtual void SetCannibal(bool);
	virtual bool GetSandman();
	virtual void SetSandman(bool);
	bool GetHasBeenEaten();
	void SetHasBeenEaten(bool);
	virtual void InitiateSandmanPackage(Actor*, TESObjectREFR*, FurnitureMark*,
										unsigned char);
	virtual void InitiateCannibalPackage(Actor*);
	virtual TESRace* GetRace();
	TESClass* GetClass();
	bool ShouldKill(TESObjectREFR*);
	bool ShouldBuy(TESObjectREFR*, TESBoundObject*);
	bool ShouldPickUp(TESObjectREFR*);
	bool ShouldTalkTo(TESObjectREFR*);
	bool CanTalk();
	bool ShouldSteal(TESObjectREFR*, TESBoundObject*);
	bool ShouldExamine(TESObjectREFR*);
	int GetDetectionLevelAgainstActor(bool, Actor*, bool&, bool, bool, bool,
									  bool*);
	DETECTION_LEVEL GetDetectionLevelValue(Actor*);
	int GetDetectionLevel(Actor*);
	void InitPackageLocations(bool);
	void EndMovement();
	void EndInterruptPackage(bool);
	TESCombatStyle* GetCombatStyle();
	bool PathFindImmediate();
	void SetCombatStyle(TESCombatStyle*);
	float GetSellValuePercentage(Actor*);
	float GetBuyValuePercentage(Actor*);
	void TogglePathLines();
	float GetEyeLevel();
	virtual float GetReach();
	bool LineOfSight(NiPoint3&, bool, bool);
	bool LineOfSight(bool, TESObjectREFR*, bool, ACTOR_SEGMENT_INVIEW*, bool);
	bool IsPointInViewCone(const NiPoint3&, float);
	bool HasLineOfSight(Actor*);
	bool Has360LineOfSight(Actor*);
	void GetEyeVector(NiPoint3&, NiPoint3&, bool);
	NiPoint3 GetActorsLastPositionDetected(Actor*);
	float GetActorsLastTimeDetected(Actor*);
	bool CanMove();
	bool CanRotate();
	bool CanSpeak();
	virtual bool IsDead(bool);
	virtual bool IsDying();
	virtual bool IsKnockedOut();
	bool CanKnockDown();
	bool IsUnConscious();
	void SetUnConscious(bool);
	bool IsRestrained();
	void SetRestrained(bool);
	bool IsReanimated();
	void SetReanimated(bool);
	virtual void SetRefraction(bool, float);
	virtual void SetRagDoll(bool);
	virtual bool HasRagDoll();
	virtual ACTOR_TYPE GetActorType();
	virtual void SetActionComplete(bool);
	virtual void SetMovementComplete(bool);
	virtual bool ChangeProcessLevel();
	void GetMissedPacks(BSSimpleList<TESPackage*>*, float);
	SkillLevel::Value GetSkillLevel(ActorValue::Index);
	virtual float GetAcrobatics();
	virtual int GetBaseActorValue(ActorValue::Index);
	virtual float GetBaseActorFloatValue(ActorValue::Index);
	virtual int GetActorValue(ActorValue::Index);
	virtual float GetActorFloatValue(ActorValue::Index);
	virtual void SetActorValue(ActorValue::Index, float);
	virtual void SetActorValue(ActorValue::Index, int);
	virtual void TempModActorValue(ActorValue::Index, float, Actor*);
	virtual void TempModActorValue(ActorValue::Index, int, Actor*);
	virtual void PermanentModActorValue(ActorValue::Index, float, Actor*);
	virtual void PermanentModActorValue(ActorValue::Index, int, Actor*);
	virtual void DamageModActorValue(ActorValue::Index, float, Actor*);
	virtual void DamageModActorValue(ActorValue::Index, int, Actor*);
	virtual void ModActorBaseValue(ActorValue::Index, float);
	virtual void ModActorBaseValue(ActorValue::Index, int);
	virtual TESForm* GetAsForm();
	void CheckSkillLevelChange(ActorValue::Index, bool);
	float DifficultyLevelCheckModHealth(ActorValue::Index, float, Actor*);
	int DifficultyLevelCheckModHealth(ActorValue::Index, int, Actor*);
	float DifficultyLevelAdjustHealthModifier(float, Actor*);
	virtual bhkCharacterController* Move(float, NiPoint3&, uint);
	virtual void DoTrap(TrapEntry*, TargetEntry*);
	bool PutItemInReference(TESBoundObject*, ExtraDataList*, TESObjectREFR*,
							int, uint);
	void PayGoldToActor(Actor*, int);
	ItemChange* GetItemBeingEscorted();
	ItemChange* GetArmorBeingWorn(BIPED_OBJECT);
	int GetItemCountinContainer(TESBoundObject*);
	int GetTypeItemCount(ENUM_FORM_ID);
	bool RechargeAllEnchanted();
	virtual ItemChange* GetBestWeapon(COMBAT_WEAPON_TYPE);
	virtual ItemChange* GetBestAmmo();
	ItemChange* GetBestLight();
	bool CanUseWeapon(TESObjectWEAP*, bool);
	ItemChange* GetRandomWornArmor(bool);
	virtual void ResetArmorRating();
	virtual bool DamageEquipment(ItemChange*, float, bool);
	void UpdateWeaponConditionEffects(bool);
	virtual TESObjectREFR* DropObject(TESObject*, ExtraDataList*, int,
									  const NiPoint3*, const NiPoint3*);
	virtual void PickUpObject(TESObjectREFR*, int, bool);
	ItemChange* CanBeDisarmed();
	bool CheckAttackDisarm(Actor*, ActorValue::Index);
	bool CheckBlockDisarm(Actor*);
	bool CheckBlockStagger();
	virtual void AddObjecttoContainer(TESBoundObject*, ExtraDataList*, int);
	int GetBootWeight(ItemChange*);
	void AdjustArrowsInQuiver(BipedAnim*, NiNode*);
	void StopAttack();
	void ReloadTargets(bool);
	void FlushReloadTargetQueque();
	ItemChange* GetBestFoodItem();
	int GetGoldAmount();
	void Eat(TESBoundObject*, ExtraDataList*, bool);
	bool DrinkPotion(AlchemyItem*, ExtraDataList*, bool);
	virtual void CastScroll(TESObjectBOOK*, MagicTarget*);
	bool HasObjects(TESBoundObject*, PACKAGE_OBJECT_TYPE, int, uint,
					PACKAGE_OBJECT_TYPE&);
	void CastAlchemy(BSSimpleList<MagicItem*>*);
	void CastAlchemy(MagicItem*, bool);
	virtual bool CheckCastWhenStrikesEnchantment(ItemChange*, Actor*,
												 Projectile*, bool&);
	virtual void UpdateWornEnchantments(float);
	bool CanCastWornEnchantment(TESBoundObject*, ExtraDataList*);
	bool CanCastWornEnchantment(ItemChange*);
	void CheckEquipWornEnchantment(TESBoundObject*, ExtraDataList*);
	void CheckStaffEnchantment(ItemChange*);
	void StartStaffCast(ItemChange*);
	void CastPermanentMagic(bool);
	void DispelPermanentMagic();
	void PreloadPermanentMagic();
	void UnloadPermanentMagic();
	virtual bool AddSpell(SpellItem*);
	virtual bool RemoveSpell(SpellItem*);
	virtual void StartCast();
	void AttachCastingArt(MagicItem*);
	void CheckMagicNode();
	virtual NiNode* GetMagicNode();
	void UpdateMagic(bool);
	void QueueReplacementLocomotion(bool, Animation*, const char*, QueuedFile*);
	void QueueReplacementLocomotion(bool, QueuedFile*);
	void QueueReplacementLocomotions(bool);
	bool IsCrippled();
	virtual bool ReloadWeapon(TESObjectWEAP*, int, bool);
	virtual bool ReloadWeaponNV(TESObjectWEAP*, int, bool, bool);
	void QueueReload();
	bool IsReloading();
	int GetCurrentAmmoClipCount();
	float GetCurrentAmmoClipPercent();
	virtual uint UseAmmo(int);
	bool ShouldUseAmmo(TESObjectWEAP*);
	void AlertAccompanyToPackageChange();
	virtual MagicCaster* GetMagicCaster();
	virtual MagicTarget* GetMagicTarget();
	virtual bool CheckCast(MagicItem*, float*, MagicItem::CannotCastReason*,
						   bool);
	virtual bool CheckAbsorb(MagicCaster*, MagicItem*, ActiveEffect*, bool);
	virtual bool CheckReflect(MagicCaster*, MagicItem*, ActiveEffect*);
	virtual float CheckResistance(MagicCaster*, MagicItem*, ActiveEffect*);
	virtual void SpellCast(MagicItem*, bool);
	virtual void CastAbility(SpellItem*, bool);
	virtual void TransferDisease(SpellItem*, MagicTarget*, bool);
	virtual bool AddTarget(MagicCaster*, MagicItem*, ActiveEffect*, bool);
	virtual void EffectAdded(ActiveEffect*);
	virtual void EffectRemoved(ActiveEffect*);
	virtual void EffectAbsorbed(MagicCaster*, ActiveEffect*);
	virtual void EffectReflected(MagicCaster*, ActiveEffect*);
	virtual void CheckTempModifiers();
	virtual bool MagicTargetIsActor();
	bool IsInCombatantFaction();
	bool IsInCombatWithGuard();
	virtual CombatGroup* GetCombatGroup();
	virtual void SetCombatGroup(CombatGroup*);
	float GetWeaponDamagePerSecond();
	void ResetDamagePerSecond();
	float CalculateCombatStrength(float);
	bool CanAttackActor(Actor*);
	bool GetShouldAttackActor(Actor*, bool, FIGHT_REACTION&, bool);
	bool GetShouldHelp(Actor*);
	bool IsVisible(int);
	void SetVisibilityMask(bool, int);
	void PickAnimations(float, float);
	uint16_t GetAnimGroup(ANIM_GROUP_ENUM, ItemChange*, bool, Animation*);
	float GetAnimGroupDuration(ANIM_GROUP_ENUM);
	void SetAnimAction(ANIMATION_ACTION, BSAnimGroupSequence*);
	ANIMATION_ACTION GetAnimAction();
	void ForceIdleAnimation();
	bool IsHeavyBodyArmorWorn();
	bool IsPowerBodyArmorWorn();
	bool HasBackPackWorn();
	bool IsPowerArmorHelmetWorn();
	void HandlePostAnimationActions();
	float GetSpellCost(MagicItem*);
	virtual bool InitiateTresPassPackage(TrespassPackage*);
	virtual void UpdateInDialogue(float, DialogueResponse*, bool);
	virtual void UpdateNonRenderSafeDialogueUpdate(float);
	virtual float SpeakSoundFunction(const char*, BSSoundHandle&,
									 DIALOGUE_EMOTION, uint, int, TESIdleForm*,
									 TESIdleForm*, TESObjectREFR*, bool, bool,
									 bool, bool, bool);
	virtual BSSoundHandle VoiceSoundFunction(TESTopic*, Actor*, bool, bool,
											 bool, bool);
	bool ShouldModulateVoice();
	virtual bool InitiateDialogue(TESPackage*);
	virtual bool InitiateDialogue(MobileObject*, PackageLocation*,
								  PackageLocation*, bool, bool, bool, TESTopic*,
								  bool, bool);
	virtual void EndDialogue();
	virtual MobileObject* SetUpTalkingActivatorActor(MobileObject*,
													 MobileObject*&);
	void InitiateAlarm(Crime*, int, bool, Actor*);
	virtual void InitiateSpectator();
	virtual void InitiateFlee(TESObjectREFR*, bool, bool, bool, TESObjectCELL*,
							  TESObjectREFR*, float, float);
	virtual void InitiateSearchForAttacker(TESObjectREFR*, NiPoint3, bool);
	void InitiateStealWarning(Actor*, TESForm*);
	void InitiatePickPocketWarning(Actor*);
	bool IsProcessingTresPassAlarm();
	void InitiateBackUpPackage();
	bool IsAngryWithPlayer();
	void InitiateFindWeaponorArrow(bool, int);
	virtual void InitiateGetUpPackage();
	virtual void PutCreatedPackage(TESPackage*, bool, bool);
	void ProcessMove(TESObjectREFR*);
	virtual void EvaluateDetection(float);
	virtual float GetDetectionTimer();
	virtual void ReduceDetectionTimer();
	int GetDispositionForEmotions();
	bool OffersServicesPackage();
	bool GetOfferBarter();
	bool GetOfferRepair();
	void UpdateAlpha();
	virtual void SetAlpha(float);
	virtual float GetAlpha();
	float GetAlphaMult();
	void SetAlphaMult(float);
	void FadeIn();
	void FadeOut();
	float GetFadePercent();
	virtual void StartCombat(Actor*, CombatGroup*, bool, bool, bool, int, bool,
							 TESPackage*);
	virtual CombatController* GetCombatController();
	CombatController* QCombatController();
	virtual bool IsInCombat(bool);
	bool IsInCombat();
	void ClearInCombat(bool);
	virtual Actor* GetCombatTarget();
	virtual void UpdateCombat();
	virtual void StopCombat(Actor*);
	virtual void PerformOneRoundofCombat();
	void HandleCombatProcessLevelChange(PROCESS_TYPE, PROCESS_TYPE);
	virtual float GetArmorRating();
	virtual float GetArmorThreshold();
	virtual int GetAttackDamage();
	bool IsInCombatWithActor(Actor*);
	bool IsFleeing(bool);
	bool IsTalking();
	virtual bool IsTresPassing();
	virtual void SetTresPassing();
	float GetRadiationResistanceMult();
	void ResetRadiationResistanceMult();
	bool IsFollowing(Actor*);
	bool IsFollowing();
	bool IsEscorterBehind();
	bool IsSameProcessLevel(Actor*);
	bool IsRefractive();
	virtual bool GetUsesAttackPercents();
	virtual unsigned char GetPowerAttackPercent(POWER_ATTACK_TYPE);
	NiPoint3 GetWeaponPosition(bool);
	bool IsWeaponDrawn();
	TESObjectWEAP* GetCurrentWeapon();
	ANIM_GROUP_WEAPON_ENUM GetCurrentWeaponAnimType();
	void StartWeaponGroup(ANIM_GROUP_ENUM, Animation*);
	ANIM_GROUP_ENUM GetIronSightsAttack(Animation*, ANIM_GROUP_ENUM,
										TESObjectWEAP*);
	virtual NiAVObject* GetFireNode();
	virtual void SetFireNode(NiAVObject*);
	float GetWalkSpeed();
	float GetRunSpeed();
	void SetWalkRunFlagDirty();
	void SetWalkSpeed(float);
	void SetRunSpeed(float);
	virtual float CalculateWalkSpeed();
	virtual float CalculateRunSpeed();
	float GetSwimWalkSpeed();
	float GetSwimRunSpeed();
	float GetFlySpeed();
	void AdjustSpeedForFollowing(float&, float, float);
	int ModifyMoveModeForFollow(int, float, float);
	virtual void ModifyDispositionTowardActor(Actor*, float);
	virtual float GetDispositionModifierTowardActor(Actor*);
	void ClearDispositionModifiers();
	virtual void RemoveActorInDispositionModifier(Actor*);
	virtual NiPoint3 GetLookingAtLocation();
	virtual NiPoint3 GetStartingAngle();
	virtual NiPoint3 GetStartingLocation();
	virtual void SetStartingPosition();
	ACTOR_LIFE_STATE GetLifeState();
	void SetLifeState(ACTOR_LIFE_STATE);
	void ClearDeathState();
	ACTOR_CRITICAL_STAGE GetCriticalStage();
	void SetCriticalStage(ACTOR_CRITICAL_STAGE);
	void ApplyCriticalStage();
	TESObjectREFR* GetHeadingTarget();
	bool MoveToSafePoint(bool);
	bool IsInvalidPosition(const NiPoint3&, bool);
	void HandleInvalidPosition();
	void RemoveFleeTarget(TESObjectREFR*);
	bool IsContinuingPackageforPC();
	void SetIsContinuingPackage(bool);
	virtual bool MovetoHigh();
	virtual bool MovetoLow();
	virtual bool MovetoMiddleLow();
	virtual bool MovetoMiddleHigh();
	bool IsCloseToGround(float);
	bool IsRunningRunOnce();
	bool GetShowHealthBar();
	bool GetInWater();
	virtual SIT_SLEEP_STATE GetSitSleepState();
	void SetCachedSitSleepState(SIT_SLEEP_STATE);
	virtual bool HasBeenAttacked();
	virtual void SetBeenAttacked(bool);
	void ResetFaceData();
	void FindASpellToUse(PACKAGE_OBJECT_TYPE);
	BSSimpleList<SpellItem*>* FindSpells(bool);
	NiPoint3 GetCoverPoint(float, NiPoint3);
	void HitMe(HitData*, char);
	virtual void HitMe(Actor*, float, float, const NiPoint3&, const NiPoint3&);
	NiNode* GetClosestBone(NiPoint3, NiPoint3);
	BGSBodyPart::LIMB_ENUM GetDamageLocation(NiNode*);
	void DismemberLimbs(HitData*, TESForm*, CAUSE_OF_DEATH);
	void Dismember(HitData*, ActorValue::Index, BGSBodyPart::LIMB_ENUM,
				   TESForm*, CAUSE_OF_DEATH, int, int, bool);
	void ScriptDismember(CAUSE_OF_DEATH, BGSBodyPart::LIMB_ENUM, Actor*);
	bool IsSkinnedToLimb(NiAVObject*, NiNode*);
	void FillBoneArray(NiNode*, bool);
	NiAVObject* ExplodeLimb(BGSBodyPart::LIMB_ENUM, NiAVObject*,
							const NiTransform&, bool);
	void HideDismemberedLimb(BGSBodyPart::LIMB_ENUM, NiNode*, NiAVObject*,
							 bool);
	void UnhideDismemberedLimb(BGSBodyPart::LIMB_ENUM, NiNode*);
	void DismemberLimb(ActorValue::Index, BGSBodyPart::LIMB_ENUM, bool, bool,
					   bool, bool);
	void UpdateDismemberedLimbVel();
	void ClearDismemberedLimbs();
	void CreateDismemberedLimbs();
	bool RemoveDismemberedLimb(BGSBodyPart::LIMB_ENUM);
	bool RestoreDismemberedLimb(BGSBodyPart::LIMB_ENUM);
	bool GetForceRun();
	void SetForceRun(bool);
	bool GetForceSneak();
	void SetForceSneak(bool);
	virtual void UseSkill(ActorValue::Index, uint);
	virtual void UseSkill(ActorValue::Index, SKILL_ACTION, float);
	virtual void UseSkill(ActorValue::Index, float, TESSkill*);
	virtual void RewardExperience(int);
	void WaitforPlayerAtJailMarker(TESObjectREFR*, bool);
	virtual uint16_t GetSaveSize(uint);
	virtual void SaveGame(BGSSaveFormBuffer*);
	virtual void SaveGame(uint);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void LoadGame(uint, uint);
	virtual void Revert(BGSLoadFormBuffer*);
	virtual void Revert(uint);
	virtual void InitLoadGame(BGSLoadFormBuffer*);
	virtual void InitLoadGame(uint, uint);
	virtual void FinishInitLoadGame(uint, uint);
	bool CheckShouldSaveHavokData(uint);
	virtual void CheckSaveGame(BGSSaveFormBuffer*);
	virtual void FinishLoadGame(BGSLoadFormBuffer*);
	void CheckDeletedCaster(MagicCaster*);
	void ClearProcessItems();
	BSFaceGenAnimationData* GetFaceAnimationData();
	void Heal();
	virtual MagicItem* GetCurrentSpell();
	virtual TESActorBase* GetTemplateActorBase();
	virtual void SetTemplateActorBase(TESActorBase*);
	void TriggerPain(bool, bool);
	void CheckInCombat();
	void RemoveCastPower(SpellItem*);
	bool IsLocationSafe(NiPoint3&);
	Actor* GetCommandingActor();
	bool GetBlocked();
	virtual float GetTemporaryModifier(ActorValue::Index);
	virtual float GetDamageModifier(ActorValue::Index);
	virtual float GetPermanentModifier(ActorValue::Index);
	virtual float GetBaseValueOverride(ActorValue::Index, bool&);
	virtual void SetBaseValueOverride(ActorValue::Index, float);
	virtual bool IsAtPoint(const NiPoint3&, float, bool, bool);
	virtual void AddGunWobble();
	int GetFactionReaction(Actor*, int&, TESFaction*&, TESFaction*&);
	int GetFactionMinorCrime();
	int GetFactionMajorCrime();
	void AddFactionMinorCrime(int, bool);
	void AddFactionMajorCrime(int, bool);
	FIGHT_REACTION GetFactionFightReaction(Actor*, bool&);
	uint IntegrateFactionLists(TESFaction**, uint, BSSimpleList<FACTION_RANK*>*,
							   BSSimpleList<FACTION_RANK*>*);
	ACTOR_AGGRESSION GetActorAggression();
	ACTOR_ASSISTANCE GetActorAssistance();
	void RemoveEnemyFlagFromAllFactions();
	int GetFactionRank(TESFaction*, bool);
	void SetFactionRank(TESFaction*, char);
	void ModFactionRank(TESFaction*, char, bool);
	bool IsInEvilFactionsOnly();
	bool SetFactionsThatCareAboutCrime(Actor*, Crime*);
	void AddBackCrime(Crime*);
	bool HasFactionThatCaresAboutCrime();
	void QueueEquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool,
						  bool);
	void QueueUnEquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool,
							bool);
	void AddFaction(TESFaction*, int);
	bool IsInFaction(TESFaction*);
	void RemoveFaction(TESFaction*);
	HitData* GetLastHitData();
	void SetLastHitData(HitData*);
	void ClearLastHitData();
	HitData* GetLastAttackHitData();
	void SetLastAttackHitData(HitData*);
	void ClearLastAttackHitData();
	void PlayHitSound(HitData*);
	void CreateBlood(float, HitData*);
	void CreateBloodOnWeapon(float, HitData*, Actor*);
	void ProcessDamageImpacts();
	virtual void AddPerk(BGSPerk*, unsigned char, bool);
	virtual void RemovePerk(BGSPerk*, bool);
	virtual unsigned char GetPerkRank(BGSPerk*, bool);
	virtual void AddPerkEntry(BGSPerkEntry*, bool);
	virtual void RemovePerkEntry(BGSPerkEntry*, bool);
	virtual BSSimpleList<BGSPerkEntry*>* GetPerkEntryList(unsigned char, bool);
	bool GetPlayerTeammate();
	virtual void StartAnimOn1stPerson(uint16_t, ACTION_FLAGS);
	bool StartAttack(ANIM_GROUP_ENUM);
	bool QueueAttack(ANIM_GROUP_ENUM);
	bool IsAttacking();
	bool SetBlock(bool);
	void PostAnimBlock();
	void BlockHit(bool);
	void Recoil();
	void Stagger();
	ANIM_GROUP_ENUM Dodge(unsigned char);
	void SetIronSights(bool, bool, bool);
	bool GetIronSights();
	int GetActionSoundValue();
	void SetActionSoundValue(int);
	void RegisterGrabIKNote();
	virtual void SetRunOnceExtraPackage(TESPackage*, char);
	void AddFollower(Actor*);
	bool HasFollower(Actor*);
	bool CouldBeFollowing(Actor*);
	void MeleeAttack(bool, bool);
	bool IsPlayerTeammate();
	void SetPlayerTeammate(bool);
	void UpdateGuardingBehavior();
	void EquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool, bool);
	bool UnEquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool, bool);
	virtual bool IsImmobile();
	virtual bool IsChild(bool);
	bool CanChildUseObject(TESObjectREFR*);
	virtual bool IsInvulnerable();
	float GetVATSAreaFree(TESObjectREFR*, float);
	float GetVATSTargetVisible(TESObjectREFR*, float);
	bool QUpdateLighting();
	void SetUpdateLighting(bool);
	bool ShouldReset(uint);
	void SetLastSeenTime();
	bool IsAnimIdleQuequed();
	bool IsPlayingLowerBodySpecialIdle();
	bool IsTryingToEnterFurniture();
	void DoDeathStuff();
	virtual void HandleHealthDamage(Actor*, float);
	bool SetLocalVariableOnActor(char*, double);
	double GetLocalVariableOnActor(char*);
	void SetReloadSpeed();
	void SetEquipSpeed();

  protected:
	virtual void AttackedBy(Actor*, ActiveEffect*);
	Actor* FindMeleeTarget();
	void CombatHit(Actor*, bool, Projectile*, char);
	virtual void HandleBlockedAttack(float, float, Actor*, Projectile*);
	bool ObjectHit(bool);
	void FakeWeaponHitSound(NiPoint3, TESObjectREFR*, bhkRigidBody*,
							MATERIAL_TYPE);
	void DoWeaponKillForce(HitData*);
	virtual bool GetEVPBuffered();
	bool GetResetAI();
	virtual void PrecacheData();
	virtual bool AddWornItem(TESBoundObject*, int, ExtraDataList*, bool);
	bool RemoveWornItem(TESBoundObject*, int, ExtraDataList*, bool, bool);
	virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
	virtual void SetCurrentSpell(MagicItem*);
	virtual MagicTarget* GetDesiredTarget();
	virtual void SetDesiredTarget(MagicTarget*);
	virtual float GetMagicEffectivenessModifier(bool, float);
	bool GetShouldCheckMagicNode();
	void SetShouldCheckMagicNode(bool);
	virtual TESObjectREFR* GetCasterStatsObject();
	virtual TESObjectREFR* GetTargetStatsObject();
	float GetUpdateTimeSinceLastUpdate();
	void AddCastPower(SpellItem*);
	bool IsInCastPowerList(SpellItem*);
	void UpdateCastPowers(float);
	CastPowerItem* GetCastPowerItem(SpellItem*);
	void DeleteCastPowers();
	bool CheckSummonedActor();
	float ComputeTargetDesirability(TESObjectREFR*);
	bool CanHeadTrack(TESObjectREFR*, bool);
	virtual void ProcessTracking(float);
	virtual void ProcessEmotions(float);
	bool ShouldRotateToTrack(TESObjectREFR*);
	TESObjectREFR* GetBestDefaultHeadTrackTarget();
	void ResetCachedGunSkill();
	void ResetCachedWeaponCondition();
	void SetCachedWeaponCondition(float);
	float GetCachedWeaponCondition();
	void UpdateActorMover(float);
	void SetPathingDoorReference(TESObjectREFR*);
	virtual void CreateActorMover();
	virtual void DestroyActorMover();

  public:
	bool SetPathfindingGoal(TESObjectREFR*, float, PathingAvoidNodeArray*);
	bool SetPathfindingGoal(const NiPoint3&, TESObjectCELL*, TESWorldSpace*,
							float, PathingAvoidNodeArray*);
	bool SetPathfindingGoal(PathingRequest*);
	bool SetPathfindingGoalAndAngle(TESObjectREFR*, float,
									PathingAvoidNodeArray*);
	bool SetPathfindingGoalAndAngle(const NiPoint3&, TESObjectCELL*,
									TESWorldSpace*, float, float,
									PathingAvoidNodeArray*);
	bool SetPathfindingFlee(const PathingRequestFlee*);
	bool SetPathfindingLOSGoal(const PathingRequestLOS*);
	bool SetPathfindingHide(const PathingRequestHide*);
	bool SetPathfindingSafeStraightLine(const PathingRequestSafeStraightLine*);
	PathingRequest* GetCurrentPathingRequest();
	bool RequestRotate(float, bool);
	bool RequestRotate(NiPoint3, bool);
	bool RotateActor(float, bool);
	void StopMoving();
	void ForceStopMoving();
	void ResumeMoving();
	void BuildRequest(PathingRequest*, const NiPoint3&, TESForm*, float,
					  PathingAvoidNodeArray*);
	void BuildRequest(PathingRequest*, const NiPoint3&, TESObjectCELL*,
					  TESWorldSpace*, float, PathingAvoidNodeArray*);
	bool IsPathValid() const;
	bool IsPathingComplete() const;
	bool IsWaitingOnPath() const;
	bool IsPathing() const;
	bool IsRotating() const;
	bool IsWaitingForAvoidance() const;
	bool DidPathingFail() const;
	bool IsStoppingMovement() const;
	void SetMoveMode(uint);
	void ClearMoveMode(uint);
	void ForceMoveMode(uint);
	void ClearForcedMoveMode();
	void SetLookAtTarget(NiPoint3);
	bool HasLookAtTarget();
	void ClearLookAtTarget();
	const NiPoint3& GetCachedMoveDelta() const;
	bool GetCurrentPathfindingGoal(PathingLocation*);
	bool GetCurrentPathfindingGoal(NiPoint3*);
	bool GetNextTetherPoint(NiPoint3&) const;
	NiPoint3 GetNextNodeLocation();
	uint GetMoveMode();
	virtual NiPoint3 CalculateAnticipatedLocation(float);
	uint GetCurrentNodeIndex();
	bool GetNodeLocation(uint, NiPoint3&);
	PathingLocation* GetFailedPathDestination();
	void HandleDeletedReferenceForActorMover(TESObjectREFR*);
	void PrintActorMoverDebugText(IDebugText*, int);
	void PrintActorMoverPathBuildingStatus(IDebugText*, int, int);
	void PrintActorMoverCurrentStatus(IDebugText*, int, int);
	bool DrawActorCurrentPath(NiPointer<NiNode>&, int);
	void ToggleDrawPaths(int);
	void UpdateCurrentDebugGeometry();
	bool GetKnockedDownMovementDelta(NiPoint3&);
	bool ApplyConstrTemplate(NiNode*);
	virtual int GetSpeakingEmotion();
	virtual void SetSpeakingEmotion(int);
	virtual int GetSpeakingEmotionValue();
	virtual void SetSpeakingEmotionValue(int);
	void ActivatedReference(TESObjectREFR*, TESBoundObject*, int, bool);
	virtual float CalculateCachedRadius();
	virtual float CalculateCachedWidth();
	virtual float CalculateCachedLength();
	virtual float CalculateCachedForwardLength();
	virtual float CalculateCachedWeaponDPS();
	virtual float CalculateCachedMedicineEffectivenessMult();
	virtual float CalculateCachedSurvivalEffectivenessMult();
	virtual float CalculateCachedParalysis();
	virtual float CalculateCachedHealingRate();
	virtual float CalculateCachedEndurance();
	virtual float CalculateCachedPerceptionCondition();
	virtual float CalculateCachedEyeLevel();
	virtual int CalculateCachedActorAggression();
	virtual int CalculateCachedActorAssistance();
	virtual float CalculateCachedWalkSpeed();
	virtual float CalculateCachedRunSpeed();
	bool GetTurretBehavior();
	void SetTurretBehavior(bool);
	bool GetForceHitReaction();

  public:
	static bool EvaluateReferenceforHorseMarker(TESObjectREFR*, int);
	static float GetInventoryWeight(ActorValueOwner*, ActorValue::Index);
	static void RemovePickedUpObjectFromWorld(TESObjectREFR*, bool);
	static void ConditionModifiedCallback(ActorValueOwner*, ActorValue::Index,
										  float, float, ActorValueOwner*);
	static void MobilityConditionModifiedCallback(ActorValueOwner*,
												  ActorValue::Index, float,
												  float, ActorValueOwner*);
	static void AggressionModifiedCallback(ActorValueOwner*, ActorValue::Index,
										   float, float, ActorValueOwner*);
	static void AssistanceModifiedCallback(ActorValueOwner*, ActorValue::Index,
										   float, float, ActorValueOwner*);
	static void InventoryWeightModifiedCallback(ActorValueOwner*,
												ActorValue::Index, float, float,
												ActorValueOwner*);
	static void DamageResistanceModifiedCallback(ActorValueOwner*,
												 ActorValue::Index, float,
												 float, ActorValueOwner*);
	static void DamageThresholdModifiedCallback(ActorValueOwner*,
												ActorValue::Index, float, float,
												ActorValueOwner*);
	static void MedicineSkillModifiedCallback(ActorValueOwner*,
											  ActorValue::Index, float, float,
											  ActorValueOwner*);
	static void SurvivalSkillModifiedCallback(ActorValueOwner*,
											  ActorValue::Index, float, float,
											  ActorValueOwner*);
	static void ParalysisModifiedCallback(ActorValueOwner*, ActorValue::Index,
										  float, float, ActorValueOwner*);
	static void HealingRateModifiedCallback(ActorValueOwner*, ActorValue::Index,
											float, float, ActorValueOwner*);
	static void EnduranceModifiedCallback(ActorValueOwner*, ActorValue::Index,
										  float, float, ActorValueOwner*);
	static void HealthFatigueModifiedCallback(ActorValueOwner*,
											  ActorValue::Index, float, float,
											  ActorValueOwner*);
	static void RadiationResistanceModifiedCallback(ActorValueOwner*,
													ActorValue::Index, float,
													float, ActorValueOwner*);
	static void QueueReplacementLocomotion(Actor*, float, float, float);
	static float GetBaseDamageResistance(ActorValueOwner*, ActorValue::Index);
	static float GetBaseDamageThreshold(ActorValueOwner*, ActorValue::Index);
	static void CheckRadiationLevelChange(ActorValueOwner*, ActorValue::Index,
										  float, float, ActorValueOwner*);
	static void CheckDehydrationLevelChange(ActorValueOwner*, ActorValue::Index,
											float, float, ActorValueOwner*);
	static void CheckHungerLevelChange(ActorValueOwner*, ActorValue::Index,
									   float, float, ActorValueOwner*);
	static void CheckSleepDeprevationLevelChange(ActorValueOwner*,
												 ActorValue::Index, float,
												 float, ActorValueOwner*);
	static void HandleGrabIKNote(TESObjectREFR*, BSAnimNote*);
	static void SayToCallBack(void*, bool);
	static void ChangeDialogueAnimation(void*, bool);
	static void DialogueConversationCallBack(void*, bool);
};
