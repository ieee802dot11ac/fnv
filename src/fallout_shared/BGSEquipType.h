#pragma once

#include "fallout_shared/BGSMenuIcon.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

class BGSEquipType : public BaseFormComponent {
  public:
	enum EQUIP_TYPE {
		ET_NONE = 0xff,
		ET_BIG_GUN = 0x0000,
		ET_ENERGY_WEAPON = 0x0001,
		ET_SMALL_GUN = 0x0002,
		ET_MELEE_WEAPON = 0x0003,
		ET_UNARMED_WEAPON = 0x0004,
		ET_THROWN_WEAPON = 0x0005,
		ET_MINE = 0x0006,
		ET_BODY_WEAR = 0x0007,
		ET_HEAD_WEAR = 0x0008,
		ET_HAND_WEAR = 0x0009,
		ET_CHEMS = 0x000a,
		ET_STIMPACK = 0x000b,
		ET_FOOD = 0x000c,
		ET_ALCOHOL = 0x000d,
		ET_COUNT = 0x000e,
	};

	static const char* pEquipTypeNames[14];

	BGSEquipType(const BGSEquipType&);
	BGSEquipType();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	BGSEquipType::EQUIP_TYPE GetEquipType();
	void SetEquipType(BGSEquipType::EQUIP_TYPE);
	BGSEquipType& operator=(const BGSEquipType&);

	static BGSEquipType::EQUIP_TYPE GetEquipType(TESForm*);
	static BGSMenuIcon* GetEquipTypeIcon(BGSEquipType::EQUIP_TYPE);
	static const char* GetEquipTypeIconFilename(BGSEquipType::EQUIP_TYPE);
	static void GenerateDefaultMenuIcons();

  protected:
	BGSEquipType::EQUIP_TYPE eEquipType; // 0x4
	static BGSMenuIcon* pEquipTypeMenuIcons[14];
};
