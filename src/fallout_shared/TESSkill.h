#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/SkillLevel.h"
#include "fallout_shared/TESDescription.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/actorvalue.h"
#include "fallout_shared/testexture.h"
#include "types.h"

struct SKILL_BONUS {
	s8 eSkill; // 0x0
	s8 cBonus; // 0x1
};

enum SKILL_ACTION {
	SA_BLOCK = 0x0000,
	SA_REPAIR = 0x0000,
	SA_ATTACK = 0x0000,
	SA_CAST = 0x0000,
	SA_BARGAIN = 0x0000,
	SA_PERSUASION = 0x0000,
	SA_HIT_BY_OPPONENT = 0x0000,
	SA_SECOND_OF_RUNNING = 0x0000,
	SA_POTION_CREATION = 0x0000,
	SA_PICK_LOCK = 0x0000,
	SA_AVOID_NOTICE = 0x0000,
	SA_JUMP = 0x0000,
	SA_SECOND_OF_SWIMMING = 0x0001,
	SA_INGREDIENT_USE = 0x0001,
	SA_PICK_POCKET = 0x0001,
	SA_FALL = 0x0001,
	SA_SPELLHIT = 0x0001,
	MAX_SKILL_ACTION = 0x0002,
};

struct SKILL_DATA {					/* Size=0x14 */
	ActorValue::Index eIndex;		// 0x0
	ActorValue::Index eAttribute;	// 0x4
	SPECIALIZATION eSpecialization; // 0x8
	float fActionValue[2];			// 0xc

	void Endian();
};

class TESSkill : public TESForm, public TESDescription, public TESTexture {
  public:
	TESSkill(const TESSkill&);
	TESSkill();
	virtual ~TESSkill() {}
	virtual void InitializeData();
	virtual void Save();
	virtual bool Load(TESFile*);
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	void SetIndex(ActorValue::Index);
	ActorValue::Index GetIndex();
	ActorValue::Index GetAttribute();
	void SetAttribute(ActorValue::Index);
	SPECIALIZATION GetSpecialization();
	void SetSpecialization(SPECIALIZATION);
	float GetActionValue(SKILL_ACTION);
	void SetActionValue(SKILL_ACTION, float);
	const char* GetLevelText(SkillLevel::Value);
	const char* GetSkillName();
	void ResetData();

	BS_MEM_OVERLOADS

  protected:
	SKILL_DATA* GetData();

  private:
	SKILL_DATA data;				  // 0x3c
	TESDescription SkillLevelText[4]; // 0x50
};
