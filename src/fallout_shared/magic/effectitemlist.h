#pragma once

#include "bscore/bssimplelist.h"
#include "fallout_shared/magic/effectitem.h"
#include "fallout_shared/magic/magicsystem.h"

class EffectItemList : public BSSimpleList<EffectItem *> {
public:
    EffectItemList(const EffectItemList &);
    EffectItemList();
    void AddEffect(EffectItem *);
    void RemoveEffect(EffectItem *);
    bool IsHostile();
    bool IsDisabled();
    bool CanBePoison();
    bool HasEffect(EffectSetting::EffectFlag);
    bool HasEffect(const EffectSetting *, ActorValue::Index);
    bool HasEffect(EffectItem *);
    bool HasScript(Script *);
    bool HasTargetEffect();
    bool HasTouchEffect();
    bool HasSelfEffect();
    bool HasAreaEffect();
    bool HasActorValueEffect();
    bool HasSummonedActorEffect();
    bool HasAssociatedItemEffect();
    void RemoveAllEffects();
    virtual bool IsMedicine();
    virtual bool IsFood();
    virtual float GetCost(Actor *);
    float GetRawCost();
    EffectItem *GetUsageMonitorEffect();
    virtual int GetMaxEffectCount();
    // virtual SkillLevel::Value GetLevel();
    EffectItem *GetCostliestEffect(MagicSystem::Range, bool);
    BSStringT<char> GetCostliestEffectString();
    BSStringT<char> GetMagicSchoolString();
    void BuildMenuString(char *, unsigned int);
    EffectItem *GetEffectItem(int);
    float GetEffectScore(
        EffectArchetypes::ArchetypeID, MagicSystem::Range, ActorValue::Index
    );
    ActorValue::Index GetAssociatedSkill();
    void Save();
    void Load(TESFile *, const char *);
    void Copy(EffectItemList *);
    bool Compare(EffectItemList *);
    unsigned char GetEffectItemIndex(EffectItem *);
    EffectItem *GetEffectItemByIndex(unsigned char);
    ~EffectItemList();

protected:
    int iHostileCount; // 0xc
};
