#pragma once

#include "fallout_shared/actorvalue.h"
#include "fallout_shared/tesobject.h"

class ActiveEffect;
class EffectItem;
class MagicCaster;
class MagicItem;

class EffectArchetypes {
public:
    struct ArchetypeDef {
        const char *pcName; // 0x0
        ActiveEffect *(*pInstantiateFunction)(
            MagicCaster *, MagicItem *, EffectItem *
        ); // 0x4
        unsigned int iFlags; // 0x8
        ActorValue::Index iFixedActorValue; // 0xc
    };
    enum ArchetypeFlag {
        DISABLED = 0x0001,
        ASSOCIATED_ACTORVALUE = 0x0002,
        ASSOCIATED_CREATURE = 0x0004,
        ASSOCIATED_NPC = 0x0008,
        ASSOCIATED_WEAPON = 0x0010,
        ASSOCIATED_ARMOR = 0x0020,
        ASSOCIATED_SCRIPT = 0x0040,
    };
    enum ArchetypeID {
        ARCHETYPE_NONE = 0xff,
        ARCHETYPE_START = 0x0000,
        VALUE_MODIFIER = 0x0000,
        SCRIPT = 0x0001,
        DISPEL = 0x0002,
        CURE_DISEASE = 0x0003,
        ABSORB = 0x0004,
        SHIELD = 0x0005,
        CALM = 0x0006,
        DEMORALIZE = 0x0007,
        FRENZY = 0x0008,
        COMMAND_CREATURE = 0x0009,
        COMMAND_HUMANOID = 0x000a,
        INVISIBILITY = 0x000b,
        CHAMELEON = 0x000c,
        LIGHT = 0x000d,
        DARKNESS = 0x000e,
        NIGHT_EYE = 0x000f,
        LOCK = 0x0010,
        OPEN = 0x0011,
        BOUND_ITEM = 0x0012,
        SUMMON_CREATURE = 0x0013,
        DETECT_LIFE = 0x0014,
        TELEKINESIS = 0x0015,
        DISINTEGRATE_ARMOR = 0x0016,
        DISINTEGRATE_WEAPON = 0x0017,
        PARALYZE = 0x0018,
        REANIMATE = 0x0019,
        SOUL_TRAP = 0x001a,
        TURN_UNDEAD = 0x001b,
        SUN_DAMAGE = 0x001c,
        VAMPIRISM = 0x001d,
        CURE_PARALYSIS = 0x001e,
        CURE_ADDICTION = 0x001f,
        CURE_POISON = 0x0020,
        CONCUSSION = 0x0021,
        VALUE_AND_PARTS = 0x0022,
        LIMB_CONDITION = 0x0023,
        TURBO = 0x0024,
        ARCHETYPE_COUNT = 0x0025,
    };

    static bool RegisterActiveEffect(
        ArchetypeID, ActiveEffect *(*)(MagicCaster *, MagicItem *, EffectItem *)
    );
    static ActiveEffect *
    Activate(MagicCaster *, MagicItem *, EffectItem *, TESBoundObject *);
    static const char *GetArchetypeName(ArchetypeID);
    static ActorValue::Index GetFixedActorValue(ArchetypeID);
    static bool CheckFlag(ArchetypeID, unsigned int);

private:
    static ArchetypeDef Archetypes[37];
};
