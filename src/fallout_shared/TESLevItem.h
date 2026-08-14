#pragma once

#include "fallout_shared/TESLeveledList.h"
#include "fallout_shared/XGameSetting.h"
#include "fallout_shared/tesobject.h"

class TESLevItem : public TESBoundObject, public TESLeveledList {
  public:
	static SettingT<GameSettingCollection> iLevItemLevelDifferenceMax;

	TESLevItem(const TESLevItem&);
	TESLevItem();
	virtual ~TESLevItem();
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual void InitItem();
	virtual int GetMaxLevelDifference();
	virtual void SaveGame(BGSSaveFormBuffer*);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void Revert(BGSLoadFormBuffer*);
};
