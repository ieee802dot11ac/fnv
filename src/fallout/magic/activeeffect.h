#pragma once

#include "bsaudio/bssoundhandle.h"
#include "fallout/magic/magictarget.h"
#include "fallout_shared/magic/magicitem.h"
#include "fallout_shared/magic/magicsystem.h"

class ActiveEffect {
    enum ActiveEffectFlags {
        NO_HITEFFECT_FORCED = 0x0001,
        NO_HITEFFECT_SHADER = 0x0002,
        NO_HITEFFECT_NIF = 0x0004,
        NO_SOUND = 0x0008,
        NO_INTIAL_FLARE = 0x0010,
        DEFERRED_SOUND = 0x0020,
        DEFERRED_HITEFFECT = 0x0040,
        HAS_CONDITIONS = 0x0080,
        FROM_WORN_ENCHANTMENT = 0x0100,
        WAS_DISPELED = 0x0200,
        EFFECT_DEAD = -2147483648,
    };

public:
    ActiveEffect(const ActiveEffect &);
    ActiveEffect(MagicCaster *, MagicItem *, EffectItem *);
    virtual ~ActiveEffect();
    virtual ActiveEffect *Copy();
    void AdjustEffectiveness(float);
    virtual void Finalize();
    void SetTarget(MagicTarget *);
    MagicTarget *GetTarget();
    void SetCaster(MagicCaster *);
    MagicCaster *GetCaster();
    MagicItem *GetSpell();
    MagicSystem::SpellType GetSpellType();
    EffectItem *GetEffectItem();
    EffectSetting *GetEffectSetting();
    float GetMagnitude();
    void SetMagnitude(float);
    float GetDuration();
    void SetDuration(float);
    void SetElapsedTime(float);
    float GetElapsedTime();
    void SetEnchantmentSource(TESBoundObject *);
    TESBoundObject *GetEnchantmentSource();
    void SetDisplacementSpell(MagicItem *);
    MagicItem *GetDisplacementSpell();
    bool CheckDisplacementSpellOnTarget();
    void Dispel(bool);
    bool IsFinished();
    bool IsStarted();
    bool IsActive();
    bool FromWornEnchantment();
    bool WasDispeled();
    virtual void Update(float);
    void EvaluateConditions(float, bool);
    BSSimpleList<MagicHitEffect *> *GetHitEffects();
    void RemoveHitEffect(MagicHitEffect *);
    void SetHitEffects(BSSimpleList<MagicHitEffect *> *);
    void ForceNoHitEffect();
    bool IsFlagSet(ActiveEffectFlags);
    void SetFlag(ActiveEffectFlags);
    void ClearFlag(ActiveEffectFlags);
    void SetDead(bool);
    bool IsDead();
    virtual unsigned short GetSaveSize(Actor *);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(Actor *);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(Actor *);
    virtual void InitLoadGame(BGSLoadFormBuffer *);
    virtual void InitLoadGame(Actor *);
    virtual void FinishInitLoadGame(Actor *);
    virtual void Revert(BGSLoadFormBuffer *);
    virtual void Revert(Actor *);
    virtual bool CheckDeletedCaster(MagicCaster *);
    virtual bool IsCausingDamage();
    virtual void FinishLoadGame(BGSLoadFormBuffer *);
    bool HasConditions();

    static unsigned short GetActiveEffectSaveSize(ActiveEffect *, Actor *);
    static void SaveActiveEffect(BGSSaveFormBuffer *, ActiveEffect *);
    static void SaveActiveEffect(ActiveEffect *, Actor *);
    static ActiveEffect *LoadActiveEffect(BGSLoadFormBuffer *);
    static ActiveEffect *LoadActiveEffect(Actor *);
    static unsigned short
    GetActiveEffectListSaveSize(BSSimpleList<ActiveEffect *> *, Actor *);
    static void SaveActiveEffectList(BGSSaveFormBuffer *, BSSimpleList<ActiveEffect *> *);
    static void SaveActiveEffectList(BSSimpleList<ActiveEffect *> *, Actor *);
    static void LoadActiveEffectList(BGSLoadFormBuffer *, BSSimpleList<ActiveEffect *> *);
    static void LoadActiveEffectList(BSSimpleList<ActiveEffect *> *, Actor *);
    static void InitLoadGameActiveEffectList(BSSimpleList<ActiveEffect *> *, Actor *);
    static void
    FinishInitLoadGameActiveEffectList(BSSimpleList<ActiveEffect *> *, Actor *);
    static void
    RevertActiveEffectList(BGSLoadFormBuffer *, BSSimpleList<ActiveEffect *> *);
    static void RevertActiveEffectList(BSSimpleList<ActiveEffect *> *, Actor *);
    static void
    InitLoadActiveEffectList(BGSLoadFormBuffer *, BSSimpleList<ActiveEffect *> *);
    static void
    FinishLoadActiveEffectList(BGSLoadFormBuffer *, BSSimpleList<ActiveEffect *> *);

protected:
    virtual void CopyData(ActiveEffect *);
    virtual bool CheckCast(MagicCaster *);
    virtual bool CheckTarget(MagicTarget *);
    virtual void Start();
    virtual void Continue();
    virtual void Finish();
    void UpdateEffect(float);
    void StartSound();

    float fElapsedSeconds; // 0x04
    MagicItem *pSpell; // 0x08
    EffectItem *pEffect; // 0x0c
    bool bActive; // 0x10
    bool bStarted; // 0x11
    bool bFinished; // 0x12
    bool bDone; // 0x13
    bool bWornEnchantment; // 0x14
    int iFlags; // 0x18
    float fMagnitude; // 0x1c
    float fDuration; // 0x20
    MagicTarget *pTarget; // 0x24
    MagicCaster *pCaster; // 0x28
    MagicSystem::SpellType eSpellType; // 0x2c
    BSSoundHandle PersistentSound; // 0x30
    TESBoundObject *pSource; // 0x3c
    BSSimpleList<MagicHitEffect *> *pHitEffects; // 0x40
    MagicItem *pDisplacementSpell; // 0x44
};
