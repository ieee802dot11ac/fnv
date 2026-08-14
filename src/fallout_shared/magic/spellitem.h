#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/SkillLevel.h"
#include "fallout_shared/magic/MagicItemForm.h"
#include "fallout_shared/magic/magicsystem.h"
class ActiveEffect;
class MagicCaster;
class MagicItem;

struct SpellDispelData {
	MagicItem* pSpell;			 // 0x0
	MagicCaster* pCaster;		 // 0x4
	ActiveEffect* pActiveEffect; // 0x8

	SpellDispelData();
	BS_MEM_OVERLOADS
};

struct SpellItemData {
	MagicSystem::SpellType iSpellType; // 0x0
	int iCostOverride;				   // 0x4
	SkillLevel::Value eLevelOverride;  // 0x8
	u8 iFlags;						   // 0xc

	void Endian();
};

class SpellItem : public MagicItemForm {
  public:
	enum SpellFlag {
		COST_OVERRIDE = 0x0001,
		ALWAYS_SUCCEEDS = 0x0002,
		PC_STARTSPELL = 0x0004,
		IMMUNE_TO_SILENCE = 0x0008,
		IGNORE_LOS_CHECK = 0x0010,
		IGNORE_RESISTANCE = 0x0020,
		NO_ABSORB_REFLECT = 0x0040,
		FORCE_TOUCH_EXPLODE = 0x0080,
	};

	SpellItem(const SpellItem&);
	SpellItem();
	virtual ~SpellItem();
	virtual void InitializeData();
	virtual void ClearData();
	bool IsFlagSet(SpellItem::SpellFlag);
	void SetFlag(SpellItem::SpellFlag, bool);
	virtual bool IsAutoCalc();
	virtual void SetAutoCalc(bool);
	bool IsPCStartSpell();
	virtual bool IgnoreResistance();
	virtual bool GetNoAbsorbOrReflect();
	void SetSpellType(MagicSystem::SpellType);
	virtual MagicSystem::SpellType GetSpellType();
	virtual float GetCost(class Actor*);
	virtual SkillLevel::Value GetLevel();
	void SetCostOverride(int);
	int GetCostOverride();
	void SetLevelOverride(SkillLevel::Value);
	SkillLevel::Value GetLevelOverride();
	SpellItemData* GetSpellItemData();

  protected:
	virtual CHUNK_ID GetChunkID();
	virtual void* GetData();
	virtual unsigned int GetDataSize();
	virtual void SaveMagicItemData();
	virtual bool CompareMagicItemData(MagicItem*);
	virtual void CopyMagicItemData(MagicItem*);
	virtual void Endian();

  private:
	SpellItemData data; // 0x44
};
