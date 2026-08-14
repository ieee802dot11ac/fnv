#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESFullName.h"

enum AMMO_EFFECT_TYPE {
	AMMO_EFFECT_DAM = 0x0000,
	AMMO_EFFECT_DR = 0x0001,
	AMMO_EFFECT_DT = 0x0002,
	AMMO_EFFECT_SPREAD = 0x0003,
	AMMO_EFFECT_CONDITION = 0x0004,
	AMMO_EFFECT_FATIGUE = 0x0005,
	AMMO_EFFECT_TYPE_COUNT = 0x0006,
};

enum AMMO_OPERATION_TYPE {
	AMMO_OPERATION_PLUS = 0x0000,
	AMMO_OPERATION_TIMES = 0x0001,
	AMMO_OPERATION_MINUS = 0x0002,
	AMMO_OPERATION_COUNT = 0x0003,
};

struct AMMO_EFFECT_DATA {			  /* Size=0xc */
	AMMO_EFFECT_TYPE iAmmoEffectType; // 0x0
	AMMO_OPERATION_TYPE iOperation;	  // 0x4
	float fValue;					  // 0x8

	void Endian();
};

class TESAmmoEffect : public TESForm, public TESFullName {
  public:
	TESAmmoEffect(const TESAmmoEffect&);
	TESAmmoEffect();
	virtual ~TESAmmoEffect() {}
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	AMMO_OPERATION_TYPE GetOperation();
	void SetOperation(AMMO_OPERATION_TYPE);
	AMMO_EFFECT_TYPE GetEffectType() { return data.iAmmoEffectType; }
	void SetEffectType(AMMO_EFFECT_TYPE);
	float GetEffectValue();
	void SetEffectValue(float);
	void BuildMenuString(char*, unsigned int);

	static float ApplyAmmoEffect(AMMO_EFFECT_TYPE,
								 BSSimpleList<TESAmmoEffect*>*, float);

	BS_MEM_OVERLOADS

  protected:
	AMMO_EFFECT_DATA data; // 0x34
};
