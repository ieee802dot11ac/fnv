#pragma once

#include "fallout_shared/magic/effectarchetype.h"
#include "fallout_shared/magic/magicitem.h"
#include "fallout_shared/magic/magicsystem.h"
#include "fallout_shared/magic/spellitem.h"
#include "fallout_shared/tesobjectrefr.h"

class Actor;
class ActiveEffect;
class AlchemyItem;
class MagicCaster;

class MagicTarget {
public:
    MagicTarget(const MagicTarget &);
    MagicTarget();
    ~MagicTarget();
    void Dispel();
    void Dispel(const EffectArchetypes::ArchetypeID, MagicCaster *);
    void Dispel(const EffectSetting *, MagicItem *);
    void Dispel(const EffectSetting *, MagicCaster *);
    void Dispel(MagicSystem::SpellType);
    void Dispel(EffectItem *, MagicItem *, MagicCaster *);
    void Dispel(MagicItem *, MagicCaster *, ActiveEffect *);
    void Dispel(TESBoundObject *, bool);
    void DispelAllSpells(bool);
    bool IsSpellTarget(MagicItem *, bool);
    bool IsLastEffect(MagicItem *, ActiveEffect *);
    bool IsEffectTarget(const EffectArchetypes::ArchetypeID, bool);
    bool IsEnchantmentTarget(TESBoundObject *);
    bool HasEffect(const EffectSetting *);
    bool HasDamageHealthEffect();
    bool HasHostileEffect(MagicCaster *);
    float GetEffectMagnitude(const EffectSetting *);
    float GetUsageMonitorEffectMagnitude(MagicItem *);
    virtual bool AddTarget(MagicCaster *, MagicItem *, ActiveEffect *, bool);
    void UpdateTarget(float);
    void StartSpell(MagicItem *);
    bool CheckAddEffect(MagicCaster *, MagicItem *, ActiveEffect *);
    virtual TESObjectREFR *GetTargetStatsObject();
    virtual BSSimpleList<ActiveEffect *> *GetActiveEffectList();
    virtual bool MagicTargetIsActor();
    Actor *GetTargetAsActor();
    bool HasRecoverableActorValueEffect(ActorValue::Index);
    void EvaluateSpellConditions();
    bool CheckAddiction(AlchemyItem *);
    void SetDisplacementSpell(MagicItem *, MagicItem *);
    bool IsAddicted(MagicItem *, bool);
    virtual bool IsInvulnerable();
    unsigned int GetMagicTargetFormID();

    static MagicTarget *GetMagicTargetByNumericID(unsigned int);

protected:
    virtual void EffectAdded(ActiveEffect *);
    virtual void EffectRemoved(ActiveEffect *);
    virtual void EffectReflected(MagicCaster *, ActiveEffect *);
    virtual void EffectAbsorbed(MagicCaster *, ActiveEffect *);
    virtual float CheckResistance(MagicCaster *, MagicItem *, ActiveEffect *);
    virtual bool CheckAbsorb(MagicCaster *, MagicItem *, ActiveEffect *, bool);
    virtual bool CheckReflect(MagicCaster *, MagicItem *, ActiveEffect *);
    bool StackEffectDuration(MagicItem *, MagicCaster *, ActiveEffect *);
    bool ResetEffectElapsedTime(MagicItem *, MagicCaster *, ActiveEffect *);

private:
    void RemoveEffect(ActiveEffect *, bool);
    void ShowState(char *, int);
    void QueueSpellDispel(MagicItem *, MagicCaster *, ActiveEffect *);
    void DispelQueuedSpells();
    static int ActiveEffectListCompareFn(ActiveEffect *, ActiveEffect *);

    bool bShowTargetStats; // 0x4
    bool bUpdating; // 0x5
    BSSimpleList<SpellDispelData *> PostUpdateDispelList; // 0x8
};
