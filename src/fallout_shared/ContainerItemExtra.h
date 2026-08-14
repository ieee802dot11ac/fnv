#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESGlobal.h"
#include "fallout_shared/TESScript.h"

class TESNPC;

class ContainerItemExtra {
  public:
	ContainerItemExtra();
	void Save();
	bool Load(TESFile*);
	void InitItem(TESForm*);
	bool Compare(ContainerItemExtra*);
	void Copy(ContainerItemExtra*);
	bool IsDefault();
	TESForm* GetOwnerForm();
	TESNPC* GetOwnerNPC();
	void SetOwnerNPC(TESNPC*);
	TESGlobal* GetOwnerGlobal();
	void SetOwnerGlobal(TESGlobal*);
	TESFaction* GetOwnerFaction();
	void SetOwnerFaction(TESFaction*);
	int GetOwnerFactionRank();
	void SetOwnerFactionRank(int);
	float QHealthPercent();
	void AddToExtraDataList(ExtraDataList*, TESHealthForm*);
	void AdjustHealthPercent(float);

  protected:
	TESForm* pOwnerForm; // 0x0
	union {				 // 0x4
		TESGlobal* pOwnerGlobal;
		int iOwnerRank;
		uint iUnion;
	};
	float fHealthMult; // 0x8
};
