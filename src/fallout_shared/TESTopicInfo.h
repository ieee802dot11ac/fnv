#pragma once

#include "fallout_shared/BGSPerk.h"
#include "fallout_shared/TESCondition.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/actorvalue.h"

class TESQuest;
class TESTopic;

struct TOPIC_INFO_DATA {
	s8 type;		// 0x0
	s8 nextSpeaker; // 0x1
	s8 flags;		// 0x2
	s8 flagsExt;	// 0x3

	void Endian();
};

class TESTopicInfo : public TESForm {
  public:
	TESTopicInfo(const TESTopicInfo&);
	TESTopicInfo(DIALOGUE_TYPE);
	virtual ~TESTopicInfo();
	virtual void Save();
	virtual bool Load(TESFile*);
	virtual void Copy(TESForm*);
	virtual void InitItem();
	virtual void InitializeData();
	virtual void ClearData();
	void RemoveInfoFromTopic(TESTopic*);
	virtual void SetAltered(bool);
	virtual bool SavesBefore(FORM*);
	virtual bool SavesBefore(TESForm*);
	virtual bool BelongsInGroup(FORM*, bool, bool);
	virtual void CreateGroupData(FORM*, FORM_GROUP*);
	virtual void GetFormDetailedString(BSStringT<char>&);
	DIALOGUE_TYPE GetTopicType();
	DIALOGUE_SPEAKER GetNextSpeaker();
	void SetNextSpeaker(DIALOGUE_SPEAKER);
	unsigned short GetInfoIndex();
	void SetInfoIndex(unsigned short);
	TESCondition* GetInfoConditions();
	void SetInfoConditions(TESCondition*);
	BSSimpleList<TESTopic*>* GetAddTopicList();
	bool InAddTopicList(TESTopic*);
	void GetInfoDisplayText(BSStringT<char>&, bool);
	TESQuest* GetOwnerQuest();
	void SetOwnerQuest(TESQuest*);
	bool IsGoodbye() const;
	void SetGoodbye(bool);
	bool IsRandom() const;
	void SetRandom(bool);
	bool IsRandomEnd() const;
	void SetRandomEnd(bool);
	bool IsSayOnce() const;
	void SetSayOnce(bool);
	bool IsInfoRefusal() const;
	void SetInfoRefusal(bool);
	bool IsRunImmediately();
	void SetRunImmediately(bool);
	bool IsRunRumorResults() const;
	void SetRunRumorResults(bool);
	bool IsSpeechChallenge() const;
	void SetSpeechChallenge(bool);
	bool IsSayOnceADay();
	void SetSayOnceADay(bool);
	bool IsAlwaysDarkened();
	void SetAlwaysDarkened(bool);
	DUMMY_NODE_STATE GetDummyNodeState();
	void SetDummyNodeState(DUMMY_NODE_STATE);
	TESConversationData* GetConversationData();
	void SetConversationData(TESConversationData*);
	BSStringT<char>& GetPrompt();
	void SetPrompt(const char*);
	bool HasPrompt() const;
	void SetActorValue(ActorValueInfo*);
	void SetPerk(BGSPerk*);
	ActorValueInfo* GetActorValue();
	BGSPerk* GetPerk();
	TESForm* GetPerkSkillStat();
	SPEECH_CHALLENGE_LEVEL GetDifficultyLevel();
	void SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL);
	int GetDifficulty();
	TESActorBase* GetSpeaker();
	void SetSpeaker(TESActorBase*);
	void CloneResponseList(ResponseListWrapper&);
	Script* GetResultScript(TOPIC_INFO_RESULT_SCRIPT);
	unsigned int GetTempDataOffset();
	void SetTempDataOffset(unsigned int);
	bool CheckCondition(bool&, TESQuest*, TESObjectREFR*, TESObjectREFR*);
	bool CheckCondition(TESQuest*, TESObjectREFR*, TESObjectREFR*);
	void HyperLinkCompile(const char*);
	void RemoveHyperLinks();
	void RunResult(TOPIC_INFO_RESULT_SCRIPT, TESObjectREFR*);
	void AddTopicList();
	bool SaidOnce();
	void SetSaidOnce();
	void ResetSaidOnceFlags();
	bool IsValidSaveID(bool);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void LoadGame(unsigned int, unsigned int);
	virtual void Revert(BGSLoadFormBuffer*);
	virtual void Revert(unsigned int);

	static void AddTopicInfoToSortedList(TESTopicInfo*,
										 BSSimpleList<TESTopicInfo*>*);
	static bool CompareTopicInfos(TESTopicInfo*, TESTopicInfo*);

  protected:
	ResponseListWrapper* GetResponseList(ResponseListWrapper*);
	void ClearResponseList();
	void ClearAddTopicList();
	TOPIC_INFO_DATA* GetData();

  private:
	TESCondition objConditions;				  // 0x28
	u16 iInfoIndex;							  // 0x30
	bool bSaidOnce;							  // 0x32
	TOPIC_INFO_DATA m_Data;					  // 0x33
	BSStringT<char> cPrompt;				  // 0x38
	BSSimpleList<TESTopic*> m_listAddTopics;  // 0x40
	TESConversationData* m_pConversationData; // 0x48
	TESActorBase* pSpeaker;					  // 0x4c
	TESForm* pPerkSkillStat;				  // 0x50
	SPEECH_CHALLENGE_LEVEL eDifficulty;		  // 0x54
	TESQuest* pOwnerQuest;					  // 0x58
	unsigned int iFileOffset;				  // 0x5c
};

class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo*> {
  public:
	void InsertInfoAt(unsigned int, TESTopicInfo*);
	void InsertArrayAt(unsigned int, TopicInfoArray*);
	TopicInfoArray(const TopicInfoArray&);
	TopicInfoArray();
	virtual ~TopicInfoArray();
};
