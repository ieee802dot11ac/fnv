#pragma once

#include "fallout_shared/magic/effectitemlist.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/magic/magicsystem.h"

class MagicItem : public TESFullName, public EffectItemList { /* Size=0x1c */
public:
    enum CannotCastReason {
        NOCAST_OK = 0x0000,
        NOCAST_MAGICKA = 0x0001,
        NOCAST_SILENCED = 0x0002,
        NOCAST_SKILLCHECK = 0x0003,
        NOCAST_POWERUSED = 0x0004,
        NOCAST_MULTIPLEBOUNDEFFECTS = 0x0005,
        NOCAST_RANGEDUNDERWATER = 0x0006,
    };

    ~MagicItem();
    virtual bool IsAutoCalc();
    virtual void SetAutoCalc(bool);
    virtual MagicSystem::SpellType GetSpellType();
    bool CanBeTrap();
    bool IsSelfTargetedOnly();
    bool IsTouchTargetedOnly();
    virtual bool IgnoreResistance();
    virtual bool GetNoAbsorbOrReflect();
    unsigned int GetMagicItemFormID();
    // EffectSetting *GetAVEffect(MagicSystem::Range);
    bool CanLoadSpell();
    void Preload(bool);
    void FinishedLoading();
    bool IsLoaded();
    bool IsLoading();
    bool IsLoadingOrLoaded();
    void Unload(bool);
    BSStringT<char> GetCannotCastString(MagicItem::CannotCastReason);
    MagicItem(const MagicItem &);
    MagicItem();

    static MagicItem *GetMagicItemByNumericID(unsigned int);
    static int GetSummonedCreatureLoadedCount();
    static void IncSummonedCreatureLoadedCount();
    static void DecSummonedCreatureLoadedCount();

protected:
    virtual CHUNK_ID GetChunkID();
    virtual void *GetData();
    virtual unsigned int GetDataSize();
    virtual bool CompareMagicItemData(MagicItem *);
    virtual void CopyMagicItemData(MagicItem *);
    virtual void SaveMagicItemComponents();
    virtual void SaveMagicItemData();
    virtual void LoadMagicItemChunk(TESFile *, CHUNK_ID);
    void MagicItemInitItem(TESForm *);
    virtual void Endian();
    static int iSummonedCreatureLoadedCount;
};
