#pragma once

#include "fallout_shared/TESCondition.h"
#include "fallout_shared/TeleportData.h"
#include "fallout_shared/tesobjectrefr.h"

class TESQuestTarget {
  public:
	TESQuestTarget(const TESQuestTarget&);
	TESQuestTarget();
	~TESQuestTarget();
	void Save();
	void Load(TESFile*);
	void InitItem(TESForm*);
	TESCondition* GetConditions();
	void SetConditions(TESCondition*);
	TESObjectREFR* GetReference(bool);
	void SetReference(TESObjectREFR*);
	bool GetIgnoreLocks();
	void SetIgnoreLocks(bool);
	TESObjectREFR* QTrackingRef();
	TeleportPath* QTargetPath();

  protected:
	unsigned char cFlags;		 // 0x00
	TESCondition objConditions;	 // 0x04
	TESObjectREFR* m_pTargetRef; // 0x0c
	TeleportPath m_TargetPath;	 // 0x10
};
