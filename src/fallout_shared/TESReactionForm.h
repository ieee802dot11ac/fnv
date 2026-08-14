#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

enum FIGHT_REACTION {
	FIGHT_REACTION_NEUTRAL = 0x0000,
	FIGHT_REACTION_ENEMY = 0x0001,
	FIGHT_REACTION_ALLY = 0x0002,
	FIGHT_REACTION_FRIEND = 0x0003,
	FIGHT_REACTION_COUNT = 0x0004,
};

struct GROUP_REACTION {
	TESForm* pForm;		// 0x0
	int iReaction;		// 0x4
	int iFightReaction; // 0x8

	void Endian() {
		EndianSwapEq(reinterpret_cast<u32&>(pForm));
		EndianSwapEq(iReaction);
		EndianSwapEq(iFightReaction);
	}

	BS_MEM_OVERLOADS
};

class TESReactionForm : public BaseFormComponent {
  public:
	TESReactionForm();
	~TESReactionForm();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	void InitItem(TESForm*);
	void FreeReactionList();
	int GetLowestReaction(TESForm**, bool (*)(TESForm*, int), int);
	int GetHighestReaction(TESForm**, bool (*)(TESForm*, int), int);
	void SetReaction(TESForm*, int);
	int GetReaction(TESForm*);
	void ModReaction(TESForm*, int);
	FIGHT_REACTION GetFactionCombatRelation(TESForm*);
	void SetFightReaction(TESForm*, int);
	unsigned short GetSaveSize(uint);
	void SaveGame(BGSSaveFormBuffer*);
	void SaveGame(uint);
	void LoadGame(BGSLoadFormBuffer*);
	void LoadGame(uint, uint);
	void InitLoadGame(BGSLoadFormBuffer*);
	void InitLoadGame(uint, uint);

  protected:
	BSSimpleList<GROUP_REACTION*>* GetReactionList() { return &m_reactionList; }
	void RemoveReactionItem(GROUP_REACTION*);

  private:
	BSSimpleList<GROUP_REACTION*> m_reactionList; // 0x4
	u8 m_cGroupFormType;						  // 0xc
};
