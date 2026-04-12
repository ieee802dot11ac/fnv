#pragma once

#include "fallout/magic/ActiveEffect.h"
#include "fallout_shared/tesscript.h"

class ScriptEffect : public ActiveEffect {
public:
    ScriptEffect(MagicCaster *apCaster, MagicItem *apSpell, EffectItem *apEffect)
        : ActiveEffect(apCaster, apSpell, apEffect) {
        pScript = apEffect->GetScript();
        pEffectLocals = nullptr;
    }
    virtual ~ScriptEffect() { delete pEffectLocals; }
    virtual ActiveEffect *Copy();
    Script *GetScript();
    virtual void Start();
    virtual void Finish();
    virtual void Update(float);
    virtual unsigned short GetSaveSize(Actor *);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(Actor *);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(Actor *);
    virtual void Revert(Actor *);

    static ActiveEffect *Instantiate(MagicCaster *, MagicItem *, EffectItem *);

protected:
    virtual void CopyData(ActiveEffect *);

private:
    Script *pScript; // 0x48
    ScriptLocals *pEffectLocals; // 0x4c
};
