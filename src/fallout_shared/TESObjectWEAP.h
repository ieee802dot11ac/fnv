#pragma once

#include "fallout_shared/BGSDestructibleObjectForm.h"
#include "fallout_shared/BGSEquipType.h"
#include "fallout_shared/BGSMessageIcon.h"
#include "fallout_shared/BGSPickupPutdownSounds.h"
#include "fallout_shared/TESHealthForm.h"
#include "fallout_shared/TESModelTextureSwap.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/TESValueForm.h"
#include "fallout_shared/TESWeightForm.h"
#include "fallout_shared/actorvalue.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/tesobject.h"

class TESObjectWEAP : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESAttackDamageForm,
                      public BGSAmmoForm,
                      public BGSClipRoundsForm,
                      public BGSDestructibleObjectForm,
                      public BGSRepairItemList,
                      public BGSEquipType,
                      public BGSPreloadable,
                      public BGSMessageIcon,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds {
public:
    TESObjectWEAP(const TESObjectWEAP &);
    TESObjectWEAP();
    virtual ~TESObjectWEAP();
    virtual void InitializeData();
    virtual void ClearData();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void InitItem();
    OBJ_WEAP *GetData();
    float GetModValue(unsigned int, unsigned char);
    void SetModValue(unsigned int, float, unsigned char);
    WEAPON_MOD_EFFECT GetModEffect(unsigned int);
    void SetModEffect(unsigned int, WEAPON_MOD_EFFECT);
    TESObjectIMOD *GetModItem(unsigned int);
    void SetModItem(unsigned int, TESObjectIMOD *);
    TESObjectSTAT *Get1stPersonModObject(unsigned char);
    void Set1stPersonModObject(unsigned char, TESObjectSTAT *);
    float GetModEffectValue(WEAPON_MOD_EFFECT, unsigned char);
    ANIM_GROUP_ENUM GetPowerAttackOverride();
    bool GetIsLoopingReload();
    void SetPowerAttackOverride(ANIM_GROUP_ENUM);
    void SetKillImpulse(float);
    float GetKillImpulse();
    void SetKillImpulseDistance(float);
    float GetKillImpulseDistance();
    int GetFormClipRounds(bool);
    float GetFormWeight(bool);
    int GetFormHealth(bool);
    float GetAmmoRegenRate(bool);
    void SetAmmoRegenRate(float);
    bool GetVATSSpecialAttackSilent();
    void SetVATSSpecialAttackSilent(bool);
    bool GetVATSSpecialAttackModRequirement();
    void SetVATSSpecialAttackModRequirement(bool);
    float GetSpeed();
    void SetSpeed(float);
    float GetAttackSpeed(bool);
    void SetAttackSpeed(float);
    float GetReach();
    void SetReach(float);
    bool IsAutomaticWeapon();
    void SetAutomaticWeapon(bool);
    bool HasScope();
    void SetHasScope(bool);
    bool HasNightScope();
    void SetHasNightScope(bool);
    bool HasModScope();
    void SetModScope(bool);
    bool GetCantDrop();
    void SetCantDrop(bool);
    bool GetHideBackpack();
    void SetHideBackpack(bool);
    bool IsEmbeddedWeapon();
    void SetEmbeddedWeapon(bool);
    bool GetUse1PISAnims();
    void SetUse1PISAnims(bool);
    bool GetUse3PISAnims();
    void SetUse3PISAnims(bool);
    const char *GetVATSAttackName();
    void SetVATSAttackName(const char *);
    const char *GetEmbeddedWeaponNode();
    void SetEmbeddedWeaponNode(const char *);
    ActorValue::Index GetEmbeddedWeaponConditionValue();
    void SetEmbeddedWeaponConditionValue(ActorValue::Index);
    unsigned char GetVATSToHitChance(bool);
    void SetVATSToHitChance(unsigned char);
    float GetShotsPerSecond();
    void SetShotsPerSecond(float);
    unsigned char GetAmmoPerShot();
    void SetAmmoPerShot(unsigned char);
    unsigned char GetNumProjectiles(bool, bool, Actor *);
    void SetNumProjectiles(unsigned char);
    float GetMinSpreadDegrees(bool);
    void SetMinSpreadDegrees(float);
    float GetSpreadDegrees(bool);
    void SetSpreadDegrees(float);
    float GetDriftDegrees();
    void SetDriftDegrees(float);
    ANIM_GROUP_ENUM GetReloadAnim(bool);
    void SetReloadAnim(ANIM_GROUP_ENUM);
    ANIM_GROUP_ENUM GetModReloadAnim();
    void SetModReloadAnim(ANIM_GROUP_ENUM);
    ANIM_GROUP_ENUM GetAttackAnim();
    void SetAttackAnim(ANIM_GROUP_ENUM);
    ANIM_GROUP_ENUM GetHandGripAnim();
    void SetHandGripAnim(ANIM_GROUP_ENUM);
    float GetIronSightFOV();
    void SetIronSightFOV(float);
    unsigned char GetConditionLevel();
    void SetConditionLevel(unsigned char);
    BGSProjectile *GetProjectile(ActorValueOwner *);
    BGSProjectile *GetProjectile(Actor *);
    void SetProjectile(BGSProjectile *);
    unsigned short GetCriticalDamage();
    void SetCriticalDamage(unsigned short);
    float GetCriticalChanceMult();
    void SetCriticalChanceMult(float);
    SpellItem *GetCriticalEffect();
    void SetCriticalEffect(SpellItem *);
    bool GetCriticalEffectOnDeath();
    void SetCriticalEffectOnDeath(bool);
    float GetVATSSpecialAttackDamageMultiplier();
    void SetVATSSpecialAttackDamageMultiplier(float);
    float GetVATSSpecialAttackAPCost();
    void SetVATSSpecialAttackAPCost(float);
    float GetVATSSpecialAttackSkillRequirement();
    void SetVATSSpecialAttackSkillRequirement(float);
    SpellItem *GetVATSSpecialAttackEffect();
    void SetVATSSpecialAttackEffect(SpellItem *);
    TESSound *GetAttackSound(bool);
    void SetAttackSound(TESSound *);
    TESSound *GetAttackSound2(bool);
    void SetAttackSound2(TESSound *);
    TESSound *GetAttackSound2D(bool);
    void SetAttackSound2D(TESSound *);
    void SetModAttackSound(TESSound *);
    TESSound *GetModAttackSound();
    void SetModAttackSound2(TESSound *);
    TESSound *GetModAttackSound2();
    void SetModAttackSound2D(TESSound *);
    TESSound *GetModAttackSound2D();
    TESSound *GetAttackLoop();
    void SetAttackLoop(TESSound *);
    TESSound *GetAttackFailSound();
    void SetAttackFailSound(TESSound *);
    TESSound *GetMeleeBlockSound();
    void SetMeleeBlockSound(TESSound *);
    TESSound *GetIdleSound();
    void SetIdleSound(TESSound *);
    TESSound *GetEquipSound();
    void SetEquipSound(TESSound *);
    TESSound *GetUnEquipSound();
    void SetUnEquipSound(TESSound *);
    float GetMinRange();
    void SetMinRange(float);
    float GetMaxRange();
    void SetMaxRange(float);
    float GetFiringRumbleLeftMotorStrength();
    void SetFiringRumbleLeftMotorStrength(float);
    float GetFiringRumbleRightMotorStrength();
    void SetFiringRumbleRightMotorStrength(float);
    float GetFiringRumbleDuration();
    void SetFiringRumbleDuration(float);
    BGSImpactDataSet *GetImpactDataSet();
    void SetImpactDataSet(BGSImpactDataSet *);
    WEAPONHITBEHAVIOR GetHitBehavior();
    void SetHitBehavior(WEAPONHITBEHAVIOR);
    TESObjectSTAT *Get1stPersonObject();
    void Set1stPersonObject(TESObjectSTAT *);
    float GetAPUsed();
    void SetAPUsed(float);
    float GetSemiAutomaticFireDelayMin();
    void SetSemiAutomaticFireDelayMin(float);
    float GetSemiAutomaticFireDelayMax();
    void SetSemiAutomaticFireDelayMax(float);
    int GetStrengthRequirement();
    void SetStrengthRequirement(int);
    bool CheckStrengthRequirement(unsigned int);
    int GetSkillRequirement();
    void SetSkillRequirement(int);
    bool CheckSkillRequirement(unsigned int);
    WEAPON_RUMBLE_PATTERN GetRumblePattern();
    void SetRumblePattern(WEAPON_RUMBLE_PATTERN);
    float GetFiringRumbleWavelength();
    void SetFiringRumbleWavelength(float);
    BGSTextureSet *GetDecalTextureSet(MATERIAL_TYPE);
    BGSImpactData *GetImpactData(MATERIAL_TYPE);
    TESModel &GetShellCasingModel();
    TESModel *GetScopeModel();
    TESEffectShader *GetScopeEffect();
    void SetScopeEffect(TESEffectShader *);
    TESModel *GetWorldTESModel();
    TESModel *GetModTESModel(unsigned char);
    int GetDamagePerSecond(float, bool, bool, int, float, float, bool, bool);
    ActorValue::Index GetWeaponSkill();
    float GetReloadTime(Animation *);
    float GetBaseReloadTime(Animation *);
    float GetJamTime(Animation *);
    ActorValue::Index GetWeaponResistance();
    WEAPON_TYPE GetWeaponType();
    void SetWeaponType(WEAPON_TYPE);
    bool IsTwoHandedWeapon();
    bool IsMeleeWeapon();
    bool IsRangedWeapon();
    bool IsGunWeapon();
    bool IsThrownWeapon();
    virtual MagicSystem::CastingType GetCastingType();
    bool GetIgnoreResist();
    void SetIgnoreResist(bool);
    bool GetIsPlayable();
    void SetIsPlayable(bool);
    bool GetIsPlayerOnly();
    void SetIsPlayerOnly(bool);
    bool GetIsMinorCrime();
    void SetIsMinorCrime(bool);
    bool GetIsRangeFixed();
    void SetIsRangeFixed(bool);
    bool GetPreventUseInNormalCombat();
    void SetPreventUseInNormalCombat(bool);
    bool GetNPCsUseAmmo();
    void SetNPCsUseAmmo(bool);
    bool GetNoJamAfterReload();
    void SetNoJamAfterReload(bool);
    bool GetOverrideAP();
    void SetOverrideAP(bool);
    bool GetOverrideDamageToWeaponMult();
    void SetOverrideDamageToWeaponMult(bool);
    bool GetBurstShot();
    void SetBurstShot(bool);
    bool GetLongVatsBurst();
    void SetLongVatsBurst(bool);
    bool GetAlternateRumble();
    void SetAlternateRumble(bool);
    float GetDamageToWeaponMult();
    void SetDamageToWeaponMult(float);
    float GetAnimShotsPerSecond();
    void SetAnimShotsPerSecond(float);
    float GetAnimReloadTime();
    void SetAnimReloadTime(float);
    float GetAnimJamTime();
    void SetAnimJamTime(float);
    float GetAimArc();
    void SetAimArc(float);
    float GetLimbDamageMult();
    void SetLimbDamageMult(float);
    float GetIronSightUseMult();
    void SetIronSightUseMult(float);
    float GetCookTime();
    void SetCookTime(float);
    SOUND_LEVEL GetSoundLevel(bool);
    int GetSoundLevelValue(bool);
    void SetSoundLevel(SOUND_LEVEL);
    COMBAT_WEAPON_TYPE GetCombatWeaponType();
    const char *GetFireNodeName();
    NiAVObject *GetFireNode(NiAVObject *);
    virtual char *GetObjectTypeName();
    NiPoint3 CalculateReleasePoint(TESObjectREFR *);
    TESAmmo *GetCurrentAmmo(Actor *);
    virtual bool Activate(TESObjectREFR *, TESObjectREFR *, bool, TESBoundObject *, int);
    void QueueFiles(IO_TASK_PRIORITY, QueuedFile *, bool);
    virtual void QueueFiles(IO_TASK_PRIORITY, QueuedFile *);
    void Fire(TESObjectREFR *);
    void ExpelShellCasing(TESObjectREFR *);
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);

private:
    OBJ_WEAP data; // 0x104
    OBJ_WEAP_CRITICAL criticalData; // 0x1d0
    TESModel ShellCasingModel; // 0x1e0
    TESModel ScopeModel; // 0x1f8
    TESModel WorldModel; // 0x210
    TESEffectShader *pScopeEffect; // 0x228
    TESSound *pAttackSound; // 0x22c
    TESSound *pAttackSound2; // 0x230
    TESSound *pAttackSound2D; // 0x234
    TESSound *pAttackLoop; // 0x238
    TESSound *pAttackFailSound; // 0x23c
    TESSound *pMeleeBlockSound; // 0x240
    TESSound *pIdleSound; // 0x244
    TESSound *pEquipSound; // 0x248
    TESSound *pUnEquipSound; // 0x24c
    TESSound *pModSilencedSound; // 0x250
    TESSound *pModSilencedSound2; // 0x254
    TESSound *pModSilencedSound2D; // 0x258
    BGSImpactDataSet *pImpactDataSet; // 0x25c
    TESObjectSTAT *p1stPersonObject; // 0x260
    TESObjectSTAT *p1stPersonMod1Object; // 0x264
    TESObjectSTAT *p1stPersonMod2Object; // 0x268
    TESObjectSTAT *p1stPersonMod3Object; // 0x26c
    TESObjectSTAT *p1stPersonMod12Object; // 0x270
    TESObjectSTAT *p1stPersonMod23Object; // 0x274
    TESObjectSTAT *p1stPersonMod13Object; // 0x278
    TESObjectSTAT *p1stPersonMod123Object; // 0x27c
    TESModelTextureSwap WorldModelMod1; // 0x280
    TESModelTextureSwap WorldModelMod2; // 0x2a0
    TESModelTextureSwap WorldModelMod3; // 0x2c0
    TESModelTextureSwap WorldModelMod12; // 0x2e0
    TESModelTextureSwap WorldModelMod13; // 0x300
    TESModelTextureSwap WorldModelMod23; // 0x320
    TESModelTextureSwap WorldModelMod123; // 0x340
    TESObjectIMOD *pModObjectOne; // 0x360
    TESObjectIMOD *pModObjectTwo; // 0x364
    TESObjectIMOD *pModObjectThree; // 0x368
    BSStringT<char> EmbeddedWeaponNode; // 0x36c
    SOUND_LEVEL eSoundLevel; // 0x374
    BSStringT<char> VATSAttackName; // 0x378
    OBJ_WEAP_VATS_SPECIAL specialVATSData; // 0x380
    bool bIsLoopingReload; // 0x394
};
