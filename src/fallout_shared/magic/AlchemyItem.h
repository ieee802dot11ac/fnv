#pragma once

#include "fallout_shared/BGSDestructibleObjectForm.h"
#include "fallout_shared/BGSEquipType.h"
#include "fallout_shared/BGSMessageIcon.h"
#include "fallout_shared/BGSPickupPutdownSounds.h"
#include "fallout_shared/TESModelTextureSwap.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/TESWeightForm.h"
#include "fallout_shared/magic/MagicItemObject.h"
#include "fallout_shared/magic/magicitem.h"
#include "fallout_shared/magic/spellitem.h"
#include "fallout_shared/tesicon.h"

struct AlchemyItemData { /* Size=0x14 */
    int iCostOverride; // 0x00
    unsigned char iFlags; // 0x04
    SpellItem *pAddictionItem; // 0x08
    float fAddictionChance; // 0x0c
    TESSound *pConsumptionSound; // 0x10

    void Endian();
};

class AlchemyItem : public MagicItemObject,
                    public TESModelTextureSwap,
                    public TESIcon,
                    public BGSMessageIcon,
                    public TESScriptableForm,
                    public TESWeightForm,
                    public BGSEquipType,
                    public BGSDestructibleObjectForm,
                    public BGSPickupPutdownSounds { /* Size=0xe8 */
public:
    enum AlchemyFlag {
        COST_OVERRIDE = 0x0001,
        FOOD_ITEM = 0x0002,
        MEDICINE = 0x0004,
    };

    AlchemyItem(const AlchemyItem &);
    AlchemyItem();
    virtual ~AlchemyItem();
    virtual void InitializeData();
    virtual void ClearData();
    virtual void InitItem();
    bool IsFlagSet(AlchemyItem::AlchemyFlag);
    void SetFlag(AlchemyItem::AlchemyFlag, bool);
    virtual bool IsAutoCalc();
    virtual void SetAutoCalc(bool);
    virtual bool IsFood();
    virtual bool IsMedicine();
    bool IsWater();
    virtual MagicSystem::SpellType GetSpellType();
    virtual float GetCost(Actor *);
    void SetCostOverride(int);
    int GetCostOverride();
    void SetAddictionItem(SpellItem *);
    SpellItem *GetAddictionItem();
    void SetAddictionChance(float);
    float GetAddictionChance();
    TESSound *GetConsumptionSound();
    void SetConsumptionSound(TESSound *);
    AlchemyItemData *GetAlchemyItemData();

protected:
    virtual CHUNK_ID GetChunkID();
    virtual void *GetData();
    virtual unsigned int GetDataSize();
    virtual void SaveMagicItemComponents();
    virtual void SaveMagicItemData();
    virtual void LoadMagicItemChunk(TESFile *, CHUNK_ID);
    virtual bool CompareMagicItemData(MagicItem *);
    virtual void CopyMagicItemData(MagicItem *);
    virtual void Endian();

private:
    AlchemyItemData data; // 0xc8
    TESIcon MessageIcon; // 0xdc
};
