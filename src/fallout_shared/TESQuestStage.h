#pragma once

#include "fallout_shared/TESScript.h"
#include "fallout_shared/tesfile.h"
#include "types.h"

struct QUEST_STAGE_DATA { /* Size=0x2 */
	u8 ucIndex;			  // 0x0
	bool bIsDone;		  // 0x1

	void Endian();
};

struct QUEST_STAGE_ITEM_DATA { /* Size=0x1 */
  /* 0x0000 */ public:
	unsigned char iFlags;

  public:
	void Endian();
};

class TESQuest;

class TESQuestStageItem {
  public:
	TESQuestStageItem(const TESQuestStageItem&);
	TESQuestStageItem();
	~TESQuestStageItem();
	void Save();
	bool Load(TESFile*);
	void InitItem(TESForm*, class TESQuestStage*);
	// TESCondition *GetConditions();
	// void SetConditions(TESCondition *);
	bool GetEndQuest();
	void SetEndQuest(bool);
	bool GetFailQuest();
	void SetFailQuest(bool);
	Script* GetResultScript();
	void SetLogEntry(bool);
	bool HasLogEntry();
	char* GetLogEntry(TESForm*);
	unsigned int GetFileOffset();
	// void ErrorCheckResults(TESTopic *);
	TESQuest* GetOwner();
	// Date *GetLogDate();
	// void SetLogDate(Date *);
	void Resolve(bool);
	void SetIndex(unsigned char);
	const unsigned char GetIndex();
	void SetNextQuest(TESQuest*);
	TESQuest* GetNextQuest();

  protected:
	QUEST_STAGE_ITEM_DATA* GetData();

  private:
	QUEST_STAGE_ITEM_DATA m_Data; // 0x00
	// TESCondition objConditions; // 0x04
	Script cResultScript;	   // 0x0c
	unsigned int m_fileOffset; // 0x70
	unsigned char ucIndex;	   // 0x74
	bool m_bHasLogEntry;	   // 0x75
	// Date *m_pLogDate; // 0x78
	TESQuest* m_pOwner;		// 0x7c
	TESQuest* m_pNextQuest; // 0x80
};

class TESQuestStage { /* Size=0xc */
  private:
	QUEST_STAGE_DATA m_Data; // 0x0
  private:
	BSSimpleList<TESQuestStageItem*> listStageItems; // 0x4

  public:
	TESQuestStage(const TESQuestStage&);
	TESQuestStage();
	~TESQuestStage();
	BSSimpleList<TESQuestStageItem*>* GetStageItemList();
	TESQuestStageItem* GetStageItem(unsigned char);
	void Save();
	void Load(TESFile*);
	void InitItem(TESForm*);
	void ClearStageItemList();
	void RemoveStageItem(TESQuestStageItem*);
	void SetDone(bool);
	void SetDone(TESQuest*, bool);
	bool GetDone();
	void SetIndex(unsigned char);
	unsigned char GetIndex();

  protected:
	QUEST_STAGE_DATA* GetData();
};
