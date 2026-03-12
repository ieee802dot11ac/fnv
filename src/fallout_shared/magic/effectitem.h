#pragma once

#include "fallout_shared/magic/effectsetting.h"
#include "fallout_shared/magic/magicsystem.h"
#include "fallout_shared/tescondition.h"

class MagicItem;

struct EffectItemData { /* Size=0x14 */
    int iMagnitude; // 0x00
    int iArea; // 0x04
    int iDuration; // 0x08
    MagicSystem::Range iRange; // 0x0c
    ActorValue::Index iActorValue; // 0x10

    void Endian();
};

class EffectItem {
public:
    EffectItem(const EffectItem &);
    EffectItem();
    EffectItem(EffectSetting *);
    EffectItem(EffectItem *);
    ~EffectItem();
    void Save();
    bool Load(TESFile *, const char *);
    void Copy(EffectItem *);
    bool Compare(EffectItem *);
    bool MatchesEffect(EffectItem *);
    void InitItem(TESForm *);
    BSStringT<char> GetEffectString(MagicItem *, float);
    BSStringT<char> GetEffectString(MagicSystem::SpellType, float, bool, bool, bool);
    EffectSetting *GetEffectSetting();
    const char *GetIcon();
    int GetMagnitude();
    bool SetMagnitude(int);
    int GetArea();
    bool SetArea(int);
    int GetDuration();
    bool SetDuration(int);
    MagicSystem::Range GetRange();
    bool SetRange(MagicSystem::Range);
    int IsAssociatedItemUsed();
    bool IsActorValueUsed();
    bool IsScriptEffect();
    bool IsDisabled();
    bool IsHostile();
    void SetHostile(bool);
    bool IsUsageMonitorEffect();
    void GetEffectName(char *);
    BSStringT<char> GetEffectName() const;
    ActorValue::Index GetAssociatedSkill();
    ActorValue::Index GetActorValueIndex();
    void SetActorValueIndex(ActorValue::Index);
    Script *GetScript();
    float GetCost(Actor *);
    float GetRawCost();
    TESCondition *GetConditions();
    void SetConditions(TESCondition *);
    void SetEffect(EffectSetting *);

private:
    void Initialize(EffectSetting *);
    EffectItemData data; // 0x00
    EffectSetting *pEffectSetting; // 0x14
    float fRawCost; // 0x18
    TESCondition Conditions; // 0x1c
};
