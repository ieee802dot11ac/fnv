#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/tesfile.h"
#include "fallout_shared/tesform.h"
class ActorValueInfo;
class ActorValueOwner;

class ActorValue {
public:
    enum Index {
        AGGRESSION = 0x0000,
        CONFIDENCE = 0x0001,
        ENERGY = 0x0002,
        RESPONSIBILITY = 0x0003,
        MOOD = 0x0004,
        STRENGTH = 0x0005,
        PERCEPTION = 0x0006,
        ENDURANCE = 0x0007,
        CHARISMA = 0x0008,
        INTELLIGENCE = 0x0009,
        AGILITY = 0x000a,
        LUCK = 0x000b,
        ACTION_POINTS = 0x000c,
        CARRY_WEIGHT = 0x000d,
        CRITICAL_CHANCE = 0x000e,
        HEALING_RATE = 0x000f,
        HEALTH = 0x0010,
        MELEE_DAMAGE = 0x0011,
        DAMAGE_RESISTANCE = 0x0012,
        POISON_RESISTANCE = 0x0013,
        RADIATION_RESISTANCE = 0x0014,
        SPEED_MULT = 0x0015,
        FATIGUE = 0x0016,
        KARMA = 0x0017,
        EXPERIENCE_POINTS = 0x0018,
        PERCEPTION_CONDITION = 0x0019,
        ENDURANCE_CONDITION = 0x001a,
        LEFT_ATTACK_CONDITION = 0x001b,
        RIGHT_ATTACK_CONDITION = 0x001c,
        LEFT_MOBILITY_CONDITION = 0x001d,
        RIGHT_MOBILITY_CONDITION = 0x001e,
        BRAIN_CONDITION = 0x001f,
        BARTER = 0x0020,
        BIG_GUNS = 0x0021,
        ENERGY_WEAPONS = 0x0022,
        EXPLOSIVES = 0x0023,
        LOCKPICK = 0x0024,
        MEDICINE = 0x0025,
        MELEE_WEAPONS = 0x0026,
        REPAIR = 0x0027,
        SCIENCE = 0x0028,
        SMALL_GUNS = 0x0029,
        SNEAK = 0x002a,
        SPEECH = 0x002b,
        SURVIVAL = 0x002c,
        UNARMED = 0x002d,
        INVENTORY_WEIGHT = 0x002e,
        PARALYSIS = 0x002f,
        INVISIBILITY = 0x0030,
        CHAMELEON = 0x0031,
        NIGHT_EYE_BONUS = 0x0032,
        TURBO = 0x0033,
        FIRE_RESISTANCE = 0x0034,
        WATER_BREATHING = 0x0035,
        RADIATION_RADS = 0x0036,
        BLOODY_MESS = 0x0037,
        UNARMED_DAMAGE = 0x0038,
        ASSISTANCE = 0x0039,
        ELECTRICAL_RESISTANCE = 0x003a,
        FROST_RESISTANCE = 0x003b,
        ENERGY_RESISTANCE = 0x003c,
        EMP_RESISTANCE = 0x003d,
        VARIABLE_01 = 0x003e,
        VARIABLE_02 = 0x003f,
        VARIABLE_03 = 0x0040,
        VARIABLE_04 = 0x0041,
        VARIABLE_05 = 0x0042,
        VARIABLE_06 = 0x0043,
        VARIABLE_07 = 0x0044,
        VARIABLE_08 = 0x0045,
        VARIABLE_09 = 0x0046,
        VARIABLE_10 = 0x0047,
        IGNORE_CRIPPLED_LIMBS = 0x0048,
        DEHYDRATION = 0x0049,
        HUNGER = 0x004a,
        SLEEPDEPREVATION = 0x004b,
        DAMAGE_THRESHOLD = 0x004c,
        ACTOR_VALUE_COUNT = 0x004d,
        AI_ATTRIBUTE_START = 0x0000,
        ATTRIBUTE_START = 0x0005,
        ACTOR_VALUE_START = 0x0000,
        DERIVED_ATTRIBUTE_START = 0x000c,
        CONDITION_START = 0x0019,
        SKILL_START = 0x0020,
        INT_START = 0x002e,
        VARIABLE_START = 0x003e,
        AI_ATTRIBUTE_END = 0x0005,
        ATTRIBUTE_END = 0x000c,
        CONDITION_END = 0x0020,
        DERIVED_ATTRIBUTE_END = 0x0020,
        SKILL_END = 0x002e,
        INT_END = 0x003e,
        VARIABLE_END = 0x004c,
        ATTRIBUTE_COUNT = 0x0007,
        DERIVED_ATTRIBUTE_COUNT = 0x0014,
        SKILL_COUNT = 0x000e,
        AI_ATTRIBUTE_COUNT = 0x0005,
        CONDITION_COUNT = 0x0007,
        INT_COUNT = 0x0010,
        VALUE_NONE = 0xff,
        SKILL_NONE = 0xff,
        ATTRIBUTE_NONE = 0xff,
    };
    enum Section {
        ATTRIBUTE = 0x0000,
        DERIVED_ATTRIBUTE = 0x0001,
        SKILL = 0x0002,
        AI_ATTRIBUTE = 0x0003,
        CONDITION = 0x0004,
        INT_VALUE = 0x0005,
        RESISTANCE = 0x0006,
        VARIABLE = 0x0007,
        SECTION_COUNT = 0x0008,
    };

    enum Flags {
        FAST_MODIFIER = 0x0001,
        CREATURE_MAPPED = 0x0002,
        EFFECT_SKILL = 0x0004,
        MAX_TEN = 0x0008,
        MAX_ONE_HUNDRED = 0x0010,
        DAMAGE_MIN_ZERO = 0x0020,
        DERIVED_PLUS_BASE = 0x0040,
        DERIVED_IF_AUTOCALC = 0x0080,
        ENUMERATION = 0x0100,
        DAMAGE_IS_POSITIVE = 0x0200,
        COMBAT_SKILL = 0x0400,
        DERIVED_ALWAYS = 0x0800,
        CREATURE_NOT_DERIVED = 0x1000,
        DEPRECATED = 0x2000,
        NO_SCRIPT_MODAV = 0x4000,
        MIN_ONE = 0x8000,
    };

    static const char *GetActorValueName(Index);
    static const char *GetActorValueDesc(Index);
    static const char *GetActorValueIcon(Index);
    static const char *GetItemWeaponTypeBadge(Index);
    static const char *GetActorValueScriptName(Index);
    static const char *GetActorValueAbbreviation(Index);
    static ActorValueInfo *GetActorValueInfo(Index);
    static Index GetActorValueIndex(char *);
    static Index ToActorValue(Section, char);
    static char ToArrayIndex(Section, Index);
    static unsigned int GetSectionCount(Section);
    static bool IsAttribute(Index);
    static bool IsDerivedAttribute(Index);
    static bool IsSkill(Index);
    static bool IsAIAttribute(Index);
    static bool IsIntValue(Index);
    static bool IsVariable(Index);
    static bool IsResistance(Index);
    static char ToAttributeArrayIndex(Index);
    static Section GetSection(Index);
    static bool IsFlagSet(Index, Flags);
    static void SetFlag(Index, Flags, bool);
    static bool GetDerivedActorValue(ActorValueOwner *, Index, float &);
    static Index GetMappedActorValue(ActorValueOwner *, Index);
    static bool HasModifiedCallback(Index);
    static void
    CheckCallModifiedCallback(ActorValueOwner *, Index, float, float, ActorValueOwner *);
    static float CheckClampDamageModifier(ActorValueOwner *, Index, float);
    static Index *GetDependentActorValues(Index, int &);
    static void RegisterActorValues();
    static void FreeActorValues();
    static int ClampActorValue(Index, int);
    static float ClampActorValue(Index, float);

private:
    static void RegisterActorValue(
        Index,
        char *,
        Section,
        unsigned int,
        float (*)(ActorValueOwner *, Index),
        Index (*)(ActorValueOwner *, Index),
        void (*)(ActorValueOwner *, Index, float, float, ActorValueOwner *),
        int,
        ...
    );

    ActorValueInfo *pActorValueInfo[77];
    static ActorValue Instance;

    ActorValue();
    ~ActorValue();
};

class ActorValueInfo
    : public TESForm /*, public TESFullName, public TESDescription, public TESIcon*/ {
public:
    char *sScriptName; // 0x48
    BSStringT<char> sAbbreviation; // 0x4c
    unsigned int uFlags; // 0x54
    ActorValue::Section eAVType; // 0x58
    float (*pDerivationFunction)(ActorValueOwner *, ActorValue::Index); // 0x5c
    ActorValue::Index (*pMappingFunction)(ActorValueOwner *, ActorValue::Index); // 0x60
    void (*pModifiedCallback)(
        ActorValueOwner *, ActorValue::Index, float, float, ActorValueOwner *
    ); // 0x64
    int iNumDependentActorValues; // 0x68
    ActorValue::Index DependentActorValues[15]; // 0x6c
    int iEnumCount; // 0xa8
    char *sEnumNames[10]; // 0xac

    ActorValueInfo(const ActorValueInfo &);
    ActorValueInfo(ActorValue::Index, char *);
    virtual ~ActorValueInfo();
    void SetEnumerated(int, ...);
    const char *GetEnumeratedName(int);
    virtual void Save();
    virtual void InitItem();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual char *GetDefaultPath() const;
    ActorValueInfo &operator=(const ActorValueInfo &);

    static unsigned int GetActorValueFormID(ActorValue::Index);
    static ActorValue::Index GetActorValueIndex(unsigned int);
};

class ActorValueOwner {
public:
    virtual int GetBaseActorValue(ActorValue::Index);
    virtual float GetBaseActorFloatValue(ActorValue::Index);
    virtual int GetActorValue(ActorValue::Index);
    virtual float GetActorFloatValue(ActorValue::Index);
    virtual float GetTemporaryModifier(ActorValue::Index);
    virtual float GetDamageModifier(ActorValue::Index);
    virtual float GetPermanentModifier(ActorValue::Index);
    virtual int GetPermanentActorValue(ActorValue::Index);
    virtual float GetPermanentActorFloatValue(ActorValue::Index);
    virtual TESForm *GetAsForm();
    int GetClampedActorValue(ActorValue::Index);
    float GetClampedActorFloatValue(ActorValue::Index);
    virtual unsigned short GetActorLevel();
    ActorValueOwner(const ActorValueOwner &);
    ActorValueOwner();
    ActorValueOwner &operator=(const ActorValueOwner &);
};
