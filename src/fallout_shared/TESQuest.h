#pragma once

#include "bscore/BSSimpleArray.h"
#include "fallout_shared/TESCondition.h"
#include "fallout_shared/TESQuestStage.h"
#include "fallout_shared/TESQuestTarget.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/TESTopicInfo.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tesicon.h"
#include "fallout_shared/tesscriptshared.h"

struct QUEST_DATA {
	u8 ucFlags;			   // 0x0
	u8 ucPriority;		   // 0x1
	float fQuestDelayTime; // 0x4

	void Endian();
};

struct INFO_LINK_ELEMENT {
	uint nID;			 // 0x0
	TESTopicInfo* pInfo; // 0x4
	int nDesiredIndex;	 // 0x8
};

struct QUEST_INFO {
	TESQuest* pQuest;									  // 0x00
	TopicInfoArray infoArray;							  // 0x04
	BSSimpleArray<INFO_LINK_ELEMENT, 1024> infoLinkArray; // 0x1c
	TESQuest* pRemovedQuest;							  // 0x2c
	bool bInitialized;									  // 0x30

	QUEST_INFO(const QUEST_INFO&);
	QUEST_INFO();
	TopicInfoArray* GetInfoArray();
	~QUEST_INFO();
};

class BGSQuestObjective;
class TESTopicInfo;

class TESQuest : public TESForm,
				 public TESScriptableForm,
				 public TESIcon,
				 public TESFullName {
  public:
	TESQuest(const TESQuest&);
	TESQuest();
	virtual ~TESQuest();
	virtual void InitializeData();
	virtual void ClearData();
	virtual void Save();
	virtual bool Load(TESFile*);
	virtual void InitItem();
	QUEST_DATA* GetData();
	BSSimpleList<TESQuestStage*>* GetStageList();
	void RemoveStage(TESQuestStage*);
	void ResortStageList();
	void AddStageDataAtIndex(TESQuestStage*);
	BSSimpleList<BGSQuestObjective*>* GetObjectiveList();
	void AddObjective(BGSQuestObjective*);
	void RemoveObjective(BGSQuestObjective*);
	BGSQuestObjective* GetObjective(unsigned int);
	void SetAllObjectivesComplete(bool);
	unsigned int GetPriority();
	void SetPriority(unsigned char);
	bool GetEnabled();
	void SetEnabled(bool);
	bool GetFailed();
	void SetFailed(bool);
	bool GetCompleted();
	void SetCompleted(bool);
	bool GetAllowRepeats();
	void SetAllowRepeats(bool);
	bool GetAllowRepeatStages();
	void SetAllowRepeatStages(bool);
	bool GetStartsEnabled();
	void SetStartsEnabled(bool);
	bool GetDisplayedInHUD();
	void SetDisplayedInHUD(bool);
	TESCondition* GetConditions();
	void SetConditions(TESCondition*);
	TESCondition* CreateCombinedConditions(TESTopicInfo*);
	ScriptLocals* GetScriptLocals();
	unsigned char GetStageIndexForStageItem(TESQuestStageItem*);
	float GetScriptProcessingDelay();
	void SetScriptProcessingDelay(float);
	void RunScript();
	bool SetStageDone(unsigned char);
	void FindCurrentStage();
	bool IsStageDone(unsigned char);
	unsigned int GetCurrentStage();
	void ResetQuest();
	bool ValidateTargetList(BSSimpleList<TESQuestTarget*>*,
							BSSimpleList<BGSQuestObjective*>*);
	void UpdateCurrentTargetList(BSSimpleList<TESQuestTarget*>*,
								 BSSimpleList<BGSQuestObjective*>*);
	TESQuestStage* GetStage(unsigned char);
	virtual unsigned short GetSaveSize(unsigned int);
	virtual void SaveGame(BGSSaveFormBuffer*);
	virtual void SaveGame(unsigned int);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void LoadGame(unsigned int, unsigned int);
	virtual void Revert(BGSLoadFormBuffer*);
	virtual void Revert(unsigned int);
	virtual void CheckSaveGame(BGSSaveFormBuffer*);
	int GetDialogLinesCount();

	static void GetQuestLog(BSSimpleList<TESQuestStageItem*>*, TESQuest*, bool,
							bool, bool);

  protected:
	void ClearStageList();
	void ClearObjectiveList();

  private:
	QUEST_DATA data;								   // 0x4c
	BSSimpleList<TESQuestStage*> m_listStages;		   // 0x54
	BSSimpleList<BGSQuestObjective*> m_listObjectives; // 0x5c
	TESCondition objConditions;						   // 0x64
	ScriptLocals* pScriptLocals;					   // 0x6c
	unsigned char cCurrentStage;					   // 0x70
};
