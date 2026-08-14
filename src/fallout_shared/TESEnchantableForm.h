#pragma once

#include "fallout_shared/magic/EnchantmentItem.h"
#include "fallout_shared/magic/magicsystem.h"

class TESEnchantableForm : public BaseFormComponent {
  public:
	TESEnchantableForm(const TESEnchantableForm&);
	TESEnchantableForm();
	void SetCastingType(MagicSystem::CastingType);
	virtual MagicSystem::CastingType GetCastingType();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	void InitItem(TESForm*);
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	EnchantmentItem* GetFormEnchanting();
	void SetFormEnchanting(EnchantmentItem*);
	u16 GetFormEnchantmentAmount();
	void SetFormEnchantmentAmount(u16);

	static EnchantmentItem* GetFormEnchanting(TESForm*);
	static u16 GetFormEnchantmentAmount(TESForm*);

  private:
	EnchantmentItem* pFormEnchanting;	   // 0x4
	u16 iAmountofEnchantment;			   // 0x8
	MagicSystem::CastingType eCastingType; // 0xc
};
