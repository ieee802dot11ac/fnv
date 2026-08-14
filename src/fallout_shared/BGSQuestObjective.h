#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/TESQuest.h"
#include "fallout_shared/TESQuestTarget.h"
#include "fallout_shared/tesfile.h"

enum QUEST_OBJECTIVE_STATE {
	QOS_DORMANT = 0x0000,
	QOS_DISPLAYED = 0x0001,
	QOS_COMPLETED = 0x0002,
	QOS_COMPLETED_DISPLAYED = 0x0003,
};

class BGSQuestObjective {
  public:
	BGSQuestObjective(const BGSQuestObjective&);
	BGSQuestObjective();
	virtual ~BGSQuestObjective();
	void InitializeData();
	void ClearData();
	void InitItem(TESQuest*);
	void Save();
	void Load(TESFile*);
	BSSimpleList<TESQuestTarget*>* GetTargetList();
	void RemoveTarget(TESQuestTarget*);
	void ClearTargetList();
	bool GetCompleted();
	bool GetDisplayed();
	bool CheckState(QUEST_OBJECTIVE_STATE);
	void SetState(QUEST_OBJECTIVE_STATE);
	void SetStateSimple(QUEST_OBJECTIVE_STATE);
	QUEST_OBJECTIVE_STATE GetState();
	unsigned int GetIndex();
	void SetIndex(unsigned int);
	unsigned int GetDisplayTextLength();
	const char* GetDisplayText();
	void SetDisplayText(const char*);
	TESQuest* GetOwner();
	void SetOwner(TESQuest*);
	bool ValidateTargetList(BSSimpleList<TESQuestTarget*>*);
	void UpdateCurrentTargetList(BSSimpleList<TESQuestTarget*>*);

  protected:
	unsigned int iIndex;					   // 0x04
	BSStringT<char> cDisplayText;			   // 0x08
	TESQuest* pOwnerQuest;					   // 0x10
	BSSimpleList<TESQuestTarget*> ListTargets; // 0x14
	bool bInitialized;						   // 0x1c
	QUEST_OBJECTIVE_STATE eState;			   // 0x20
};
