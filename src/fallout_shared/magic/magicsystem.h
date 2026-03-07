#pragma once

#include "fallout_shared/actorvalue.h"
#include "fallout_shared/tessound.h"

class MagicSystem {
public:
    enum CastingType {
        CAST_ONCE = 0x0000,
        WHEN_USED = 0x0001,
        WHEN_STRIKES = 0x0002,
        CONSTANT_EFFECT = 0x0003,
        CASTING_COUNT = 0x0004,
    };

    enum FlareType {
        FLARE_NONE = 0x0000,
        FLARE_FIRE = 0x0001,
        FLARE_FROST = 0x0002,
        FLARE_SHOCK = 0x0004,
        FLARE_WEAPON = 0x0008,
    };

    enum ProjectileType {
        BALL = 0x0000,
        BOLT = 0x0001,
        SPRAY = 0x0002,
        FOG = 0x0003,
        PROJECTILE_TYPE_COUNT = 0x0004,
    };

    enum Range {
        SELF = 0x0000,
        TOUCH = 0x0001,
        TARGET = 0x0002,
        RANGE_COUNT = 0x0003,
    };

    enum School {
        ALTERATION = 0x0000,
        CONJURATION = 0x0001,
        DESTRUCTION = 0x0002,
        ILLUSION = 0x0003,
        MYSTICISM = 0x0004,
        RESTORATION = 0x0005,
        SCHOOL_COUNT = 0x0006,
    };

    enum SpellType {
        SPELL = 0x0000,
        DISEASE = 0x0001,
        POWER = 0x0002,
        LESSER_POWER = 0x0003,
        ABILITY = 0x0004,
        POISON = 0x0005,
        ENCHANTMENT = 0x0006,
        POTION = 0x0007,
        WORTCRAFT = 0x0008,
        LEVELED_SPELL = 0x0009,
        ADDICTION = 0x000a,
        SPELL_TYPE_COUNT = 0x000b,
    };

    static bool IsSpellTypePermanent(SpellType);
    static const char *GetMagicSchoolName(School);
    static const char *GetMagicTypeName(SpellType);
    static const char *GetMagicItemCastName(CastingType);
    static const char *GetMagicRangeName(Range);
    static const char *GetMagicProjectileTypeName(ProjectileType);
    static ActorValue::Index MagicSchoolToSkill(School);
    static School MagicSkillToSchool(ActorValue::Index);
    static int GetWortcraftEffectCount(int);
    static void SetShowMagicStats(bool);
    static bool GetShowMagicStats();
    static void GenerateDefaultObjects();
    static TESSound *GetMagicFailureSound(School);
    static TESSound *GetEnchantDrawSound(School);
    static TESSound *GetEnchantHitSound(School);
    static float GetChameleonMaxRefraction();
    static float GetChameleonMinRefraction();
    static TESEffectShader *GetAbsorbShaderEffect();
    static TESEffectShader *GetReflectShaderEffect();
    static TESEffectShader *GetDetectLifeShaderEffect();
    static SpellItem *GetPipBoyLightSpell();
    static void GetProjectileDistance(ProjectileType, float &, float &);
    static bool CheckFlareFlag(FlareType, unsigned int);
    static bool ShouldEffectFlare(FlareType);
    static FlareType CheckEffectFlares(const EffectSetting *);
    static FlareType CheckEffectTriggersFlare(const EffectSetting *);
    static bool CheckBoundItemEffects(EffectItem *, EffectItem *);

private:
    static bool bShowMagicStats;
    static TESSound *pAlterationFailureSound;
    static TESSound *pConjurationFailureSound;
    static TESSound *pDestructionFailureSound;
    static TESSound *pIllusionFailureSound;
    static TESSound *pMysticismFailureSound;
    static TESSound *pRestorationFailureSound;
    static TESSound *pAlterationEnchantDrawSound;
    static TESSound *pConjurationEnchantDrawSound;
    static TESSound *pDestructionEnchantDrawSound;
    static TESSound *pIllusionEnchantDrawSound;
    static TESSound *pMysticismEnchantDrawSound;
    static TESSound *pRestorationEnchantDrawSound;
    static TESSound *pAlterationEnchantHitSound;
    static TESSound *pConjurationEnchantHitSound;
    static TESSound *pDestructionEnchantHitSound;
    static TESSound *pIllusionEnchantHitSound;
    static TESSound *pMysticismEnchantHitSound;
    static TESSound *pRestorationEnchantHitSound;
    static TESEffectShader *pAbsorbShaderEffect;
    static TESEffectShader *pReflectShaderEffect;
    static TESEffectShader *pDetectLifeShaderEffect;
    static SpellItem *pPipBoyLightSpell;
};
