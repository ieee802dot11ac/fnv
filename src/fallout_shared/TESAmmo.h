#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/BGSClipRoundsForm.h"
#include "fallout_shared/BGSDestructibleObjectForm.h"
#include "fallout_shared/BGSMessageIcon.h"
#include "fallout_shared/BGSPickupPutdownSounds.h"
#include "fallout_shared/BGSProjectile.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESAmmoEffect.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/TESModelTextureSwap.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/TESValueForm.h"

struct AMMO_DATA {
	float fSpeed; // 0x0
	u8 cFlags;	  // 0x4

	void Endian() { EndianSwapEq(reinterpret_cast<u32&>(fSpeed)); }
};

struct AMMO_DATA_NV {
	u8 cProjectilePerAmmo;				// 0x00
	BGSProjectile* pProjectileOverride; // 0x04
	float fWeightOverride;				// 0x08
	TESForm* pAmmoConsumedObject;		// 0x0c
	float fAmmoConsumedChance;			// 0x10

	void Endian() {
		EndianSwapEq(reinterpret_cast<u32&>(pProjectileOverride));
		EndianSwapEq(reinterpret_cast<u32&>(fWeightOverride));
		EndianSwapEq(reinterpret_cast<u32&>(pAmmoConsumedObject));
		EndianSwapEq(reinterpret_cast<u32&>(fAmmoConsumedChance));
	}
};

class TESAmmo : public TESBoundObject,
				public TESFullName,
				public TESModelTextureSwap,
				public TESIcon,
				public BGSMessageIcon,
				public TESValueForm,
				public BGSClipRoundsForm,
				public BGSDestructibleObjectForm,
				public BGSPickupPutdownSounds,
				public TESScriptableForm {
  public:
	TESAmmo();
	virtual ~TESAmmo();
	virtual void InitializeData();
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual void InitItem();
	virtual NiAVObject* Clone3D(TESObjectREFR*, bool);
	float GetSpeed();
	void SetSpeed(float);
	float GetWeight();
	void SetWeight(float);
	u8 GetNumProjectiles();
	void SetNumProjectiles(u8);
	BGSProjectile* GetProjectile();
	void SetProjectile(BGSProjectile*);
	BSSimpleList<TESAmmoEffect*>* GetAmmoEffectList() {
		return &pAmmoEffectList;
	}
	bool GetIgnoreResist();
	void SetIgnoreResist(bool);
	bool GetIsPlayable();
	void SetIsPlayable(bool);
	const char* GetShortDesc();
	void SetShortDesc(const char*);
	const char* GetAbbrev();
	void SetAbbrev(const char*);
	TESForm* GetAmmoConsumedForm();
	void SetAmmoConsumedForm(TESForm*);
	float GetAmmoConsumedPercent();
	void SetAmmoConsumedFormPercent(float);
	virtual u16 GetSaveSize(uint);
	virtual void SaveGame(BGSSaveFormBuffer*);
	virtual void SaveGame(uint);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void LoadGame(uint, uint);
	void BuildMenuString(char*, uint);

	BS_MEM_OVERLOADS

  protected:
	AMMO_DATA* GetData();
	AMMO_DATA_NV* GetNVData();

  private:
	AMMO_DATA data;								  // 0xb8
	AMMO_DATA_NV NVdata;						  // 0xc0
	BSStringT<char> cDesc;						  // 0xd4
	BSStringT<char> cAbbrev;					  // 0xdc
	BSSimpleList<TESAmmoEffect*> pAmmoEffectList; // 0xe4
};
