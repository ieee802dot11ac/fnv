#pragma once

#include "fallout_shared/TESGlobal.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesobjectrefr.h"
#include "types.h"

class TESContainer;
class ContainerItemExtra;

struct LEVELED_OBJECT {				/* Size=0xc */
	TESForm* pForm;					// 0x0
	u16 sCount;						// 0x4
	u16 sLevel;						// 0x6
	ContainerItemExtra* pItemExtra; // 0x8
};

class TESLeveledList : public BaseFormComponent {
  public:
	TESLeveledList(const TESLeveledList&);
	TESLeveledList();
	~TESLeveledList();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	virtual unsigned char GetChanceNone();
	void SetChanceNone(unsigned char);
	bool GetCalcAllBelow();
	void SetCalcAllBelow(bool);
	virtual bool GetMultCalc();
	void SetMultCalc(bool);
	bool GetUseAll();
	void SetUseAll(bool);
	TESGlobal* GetChanceGlobal();
	void SetChanceGlobal(TESGlobal*);
	virtual int GetMaxLevelDifference();
	void FreeLeveledList();
	void SortLeveledList();
	LEVELED_OBJECT* AddLeveledObject(u16, u16, TESForm*, ContainerItemExtra*);
	void DeleteLeveledObject(LEVELED_OBJECT*);
	void CalculateCurrentForm(u16, TESForm*&, u16&, ContainerItemExtra*&, bool,
							  int);
	void CalculateCurrentFormList(u16, u16, TESContainer*, int);
	void CalculateCurrentFormListForRef(TESObjectREFR*, TESContainer*);
	void RemoveAllScriptAddedLeveledObjects();
	void AddScriptAddedLeveledObject(TESForm*, u16, u16, TESForm*,
									 ContainerItemExtra*);
	void SaveGame(BGSSaveFormBuffer*);
	void LoadGame(BGSLoadFormBuffer*);
	void Revert(BGSLoadFormBuffer*);
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	void InitItem(TESForm*);
	virtual void ErrorCheckList();

	static TESLeveledList* GetFormAsLeveledList(TESForm*);

  protected:
	BSSimpleList<LEVELED_OBJECT*>* GetLeveledList() { return &leveledList; }

	BSSimpleList<LEVELED_OBJECT*> leveledList;	   // 0x04
	u8 cChanceNone;								   // 0x0c
	u8 cLLFlags;								   // 0x0d
	TESGlobal* pChanceGlobal;					   // 0x10
	BSSimpleList<LEVELED_OBJECT*> ScriptAddedList; // 0x14
};
