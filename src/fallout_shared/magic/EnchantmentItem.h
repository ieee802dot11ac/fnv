#pragma once

#include "fallout_shared/magic/MagicItemForm.h"

struct EnchantmentItemData {
    MagicSystem::CastingType eCastingType; // 0x0
    int iChargeOverride; // 0x4
    int iCostOverride; // 0x8
    u8 iFlags; // 0xc

    void Endian();
};

class EnchantmentItem : public MagicItemForm {
public:
    enum EnchantmentFlag {
        COST_OVERRIDE = 0x0001,
        EXTEND_DURATION = 0x0002,
        HIDE_EFFECT = 0x0004,
    };

    EnchantmentItem(const EnchantmentItem &);
    EnchantmentItem();
    virtual ~EnchantmentItem();
    virtual void InitializeData();
    virtual void ClearData();
    bool IsFlagSet(EnchantmentItem::EnchantmentFlag);
    void SetFlag(EnchantmentItem::EnchantmentFlag, bool);
    virtual bool IsAutoCalc();
    virtual void SetAutoCalc(bool);
    bool IsExtendDuration();
    void SetExtendDuration(bool);
    bool IsValidEnchantForObject(TESForm *);
    bool CanAddEffect(EffectSetting *);
    virtual MagicSystem::SpellType GetSpellType();
    MagicSystem::CastingType GetCastingType();
    void SetCastingType(MagicSystem::CastingType);
    virtual float GetCost(Actor *);
    int GetCharge();
    void SetCostOverride(int);
    int GetCostOverride();
    void SetChargeOverride(int);
    int GetChargeOverride();
    EnchantmentItemData *GetEnchantmentItemData();

    static bool
    IsValidEffectForEnchantment(TESBoundObject *, ExtraDataList *, EffectSetting *, bool);
    static bool IsValidEffectForEnchantment(class ItemChange *, EffectSetting *, bool);
    static bool EnchantmentItemFilterValidationFunction(EffectSetting *, void *);

protected:
    virtual CHUNK_ID GetChunkID();
    virtual void *GetData();
    virtual unsigned int GetDataSize();
    virtual void SaveMagicItemData();
    virtual bool CompareMagicItemData(MagicItem *);
    virtual void CopyMagicItemData(MagicItem *);
    virtual void Endian();

private:
    EnchantmentItemData data; // 0x44
};
