#pragma once

#include "fallout_shared/actorvalue.h"
#include "fallout_shared/tesform.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tessound.h"
#include "fallout_shared/magic/magicsystem.h"

class EffectSetting : public TESForm,
                      public TESModel,
                      public TESDescription,
                      public TESFullName,
                      public TESIcon {
public:
    enum EffectFlag {
        HOSTILE = 0x0001,
        RECOVER = 0x0002,
        DETRIMENTAL = 0x0004,
        MAGNITUDE_PERCENT = 0x0008,
        RANGE_SELF = 0x0010,
        RANGE_TOUCH = 0x0020,
        RANGE_TARGET = 0x0040,
        NO_DURATION = 0x0080,
        NO_MAGNITUDE = 0x0100,
        NO_AREA = 0x0200,
        PERSIST = 0x0400,
        CREATE_SPELLMAKING = 0x0800,
        GORY_VISUALS = 0x1000,
        DISPLAY_EFFECT_NAME = 0x2000,
        LIGHT_NEGATE = 0x4000,
        NO_RECAST = 0x8000,
        USE_ASSOCIATED_WEAPON = 0x00010000,
        USE_ASSOCIATED_ARMOR = 0x00020000,
        USE_ASSOCIATED_CREATURE = 0x00040000,
        USE_ASSOCIATED_SKILL = 0x00080000,
        USE_ASSOCIATED_ATTR = 0x00100000,
        PLAYER_KNOWS = 0x00200000,
        DISABLED = 0x00400000,
        MARKER_EFFECT = 0x00800000,
        PAINLESS = 0x01000000,
        PROJECTILE_TYPE_BIT0 = 0x02000000,
        PROJECTILE_TYPE_BIT1 = 0x04000000,
        NO_HIT_EFFECT = 0x08000000,
        NO_DEATH_DISPEL = 0x10000000,
        HAVOK_EXPLOSION = 0x20000000,
        MAGNITUDE_LEVEL = 0x40000000,
        MAGNITUDE_FEET = 0x80000000,
    };

    struct EffectSettingData {
        unsigned int iFlags; // 0x00
        float fBaseCost; // 0x04
        TESForm *pAssociatedItem; // 0x08
        ActorValue::Index iAssociatedSkill; // 0x0c
        ActorValue::Index iResistVariable; // 0x10
        short iNumCounterEffects; // 0x14
        TESObjectLIGH *pLight; // 0x18
        float fSpeed; // 0x1c
        // TESEffectShader *pEffectShader; // 0x20
        // TESEffectShader *pEnchantEffect; // 0x24
        TESSound *pCastSound; // 0x28
        TESSound *pBoltSound; // 0x2c
        TESSound *pHitSound; // 0x30
        TESSound *pAreaSound; // 0x34
        float fCEEnchantFactor; // 0x38
        float fCEBarterFactor; // 0x3c
        // EffectArchetypes::ArchetypeID eArchetype; // 0x40
        ActorValue::Index eAssociatedActorValue; // 0x44

        void Endian();
    };

    EffectSetting(const EffectSetting &);
    EffectSetting();
    virtual ~EffectSetting();
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void InitItem();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    bool IsFlagSet(EffectSetting::EffectFlag);
    bool IsFlagSetAll(unsigned int);
    bool IsFlagSetAny(unsigned int);
    void SetFlag(EffectSetting::EffectFlag, bool);
    void Disable();
    void Enable();
    bool IsDisabled();
    int IsRangeAll();
    int GetRangeFlags();
    bool ShouldNegateMagnitude(ActorValue::Index);
    bool IsAssociatedFormUsed();
    bool IsAssociatedActorValueUsed();
    bool IsAssociatedActorValueFixed();
    bool IsScriptEffect();
    MagicSystem::ProjectileType GetProjectileType();
    void SetProjectileType(MagicSystem::ProjectileType);
    BSStringT<char> GetEffectName() const;
    void SetEffectName(const char *);
    float GetBaseCost();
    void SetBaseCost(float);
    TESForm *GetAssociatedForm();
    void SetAssociatedForm(TESForm *);
    ActorValue::Index GetAssociatedActorValue();
    void SetAssociatedActorValue(ActorValue::Index);
    ActorValue::Index GetAssociatedSkill();
    void SetAssociatedSkill(ActorValue::Index);
    BSSimpleList<EffectSetting *> *GetCounterEffects();
    int GetNumCounterEffects();
    void SetCounterEffects(BSSimpleList<EffectSetting *> *);
    ActorValue::Index GetResistanceVariable();
    void SetResistanceVariable(ActorValue::Index);
    bool FilterCompare(EffectSetting *, bool, unsigned int);
    TESSound *GetCastSound();
    void SetCastSound(TESSound *);
    TESSound *GetBoltSound();
    void SetBoltSound(TESSound *);
    TESSound *GetHitSound();
    void SetHitSound(TESSound *);
    TESSound *GetAreaSound();
    void SetAreaSound(TESSound *);
    TESObjectLIGH *GetLight();
    void SetLight(TESObjectLIGH *);
    // TESEffectShader *GetEffectShader();
    // void SetEffectShader(TESEffectShader *);
    // TESEffectShader *GetEnchantEffectShader();
    // void SetEnchantEffectShader(TESEffectShader *);
    void SetProjectileSpeed(float);
    float GetProjectileSpeed();
    void SetConstantEffectEnchantmentFactor(float);
    float GetConstantEffectEnchantmentFactor();
    void SetConstantEffectBarterFactor(float);
    float GetConstantEffectBarterFactor();
    // EffectArchetypes::ArchetypeID GetEffectArchetype();
    // void SetEffectArchetype(EffectArchetypes::ArchetypeID);
    virtual char *GetObjectTypeName();
    bool IsAssociatedItemLoaded();
    bool IsAssociatedItemQueued();
    int IncAssociatedItemLoadedCount();
    int DecAssociatedItemLoadedCount();
    int QueueAssociatedItem();
    int QueueAssociatedItemFinished();
    bool IsEffectLoaded();
    bool IsEffectQueued();
    int IncEffectLoadedCount();
    int DecEffectLoadedCount();
    int QueueEffect();
    int QueueEffectFinished();

    static EffectSetting *CreateFilter();

    bool (*pFilterValidationFunction)(EffectSetting *, void *); // 0x60
    void *pFilterValidationItem; // 0x64
protected:
    EffectSetting::EffectSettingData data; // 0x68
    BSSimpleList<EffectSetting *> counterEffects; // 0xb0
    int iEffectLoadedCount; // 0xb8
    int iAssociatedItemLoadedCount; // 0xbc

private:
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetNumCounterEffects(short);
};
