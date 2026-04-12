#pragma once

#include "fallout_shared/tempeffects/BSTempEffect.h"

class ActiveEffect;

class MagicHitEffect : public BSTempEffect {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    MagicHitEffect(const MagicHitEffect &);
    MagicHitEffect(TESObjectREFR *, ActiveEffect *);
    MagicHitEffect();
    virtual ~MagicHitEffect();
    virtual bool Update(float);
    virtual bool Init();
    void SetActiveEffect(ActiveEffect *);
    ActiveEffect *GetActiveEffect();
    TESObjectREFR *GetTarget();
    virtual void ClearTarget();
    bool GetFinished();
    void SetFinished(bool);
    void UpdateParentCell(NiAVObject *);
    virtual void UpdatePosition();
    virtual unsigned short GetSaveSize(ActiveEffect *, TESObjectREFR *);
    virtual void SaveGame(BGSSaveGameBuffer *);
    virtual void SaveGame(ActiveEffect *, TESObjectREFR *);
    virtual void LoadGame(BGSLoadGameBuffer *);
    virtual void LoadGame(ActiveEffect *, TESObjectREFR *);
    virtual void InitLoadGame(BGSLoadGameBuffer *);
    virtual void InitLoadGame(ActiveEffect *, TESObjectREFR *);
    virtual void FinishInitLoadGame(ActiveEffect *, TESObjectREFR *, void *);
    virtual void FinishLoadGame(BGSLoadGameBuffer *);
    virtual TEMP_EFFECT_TYPE GetType();

    static BSSimpleList<MagicHitEffect *> *InstantiateHitEffects(ActiveEffect *);

protected:
    ActiveEffect *pEffect; // 0x18
    TESObjectREFR *pTarget; // 0x1c
    float fAge; // 0x20
    bool bFinished; // 0x24
};
