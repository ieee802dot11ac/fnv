#pragma once

#include "fallout_shared/TESTopicInfo.h"
#include "fallout_shared/tesfullname.h"

class TESTopic : public TESForm, public TESFullName {
public:
    TESTopic(const TESTopic &);
    TESTopic(DIALOGUE_TYPE);
    virtual ~TESTopic();
    virtual bool Save(TESFile *);
    virtual void Save();
    virtual bool SaveEdit(TESFile *);
    virtual bool Load(TESFile *);
    virtual void InitItem();
    virtual void InitializeData();
    virtual bool SavesBefore(FORM *);
    virtual bool SavesBefore(TESForm *);
    DIALOGUE_DATA *GetData();
    DIALOGUE_TYPE GetDialogueType() const;
    float GetPriority();
    void SetPriority(float);
    bool IsRemappedRumors() const;
    void SetRemappedRumors(bool);
    bool IsTopLevel();
    void SetTopLevel(bool);
    DUMMY_NODE_STATE GetDummyNodeState();
    void SetDummyNodeState(DUMMY_NODE_STATE);
    bool IsPersuasion();
    bool IsNonMenuTopic();
    const BSSimpleList<QUEST_INFO *> *GetQuestInfoList() const;
    BSSimpleList<QUEST_INFO *> *GetQuestInfoList();
    TopicInfoArray *GetInfoArray(TESQuest *);
    TESTopicInfo *GetInfoByID(TESQuest *, unsigned int, bool);
    TESTopicInfo *GetInfoByID(unsigned int, bool);
    TESTopicInfo *GetInfoByIndex(TESQuest *, unsigned int);
    TESQuest *GetOwnerQuest(TESTopicInfo *) const;
    QUEST_INFO *GetQuestInfoElement(TESTopicInfo *) const;
    BSStringT<char> &GetDummyPrompt();
    void SetDummyPrompt(const char *);
    bool HasDummyPrompt() const;
    void ClearSaidOnceInfosForQuest(TESQuest *);
    bool HasQuest(BSSimpleList<TESQuest *> *, bool) const;
    bool HasQuest(TESQuest *, bool) const;
    void ResetInfoIndexes(TESQuest *);
    bool InsertInfo(TESQuest *, TESTopicInfo *, unsigned int);
    QUEST_INFO *InsertQuest(TESQuest *, bool);
    bool AddInfoToEnd(TESQuest *, TESTopicInfo *);
    TESTopicInfo *CreateInfoAtIndex(TESQuest *, int);
    bool SortQuests();
    virtual bool IsParentForm();
    virtual bool IsFormTypeChild(unsigned char);
    DialogueItem *CreateDialogueItem(
        TESObjectREFR *, TESObjectREFR *, TESTopic *, BSSimpleList<DialogueItem *> *, bool
    );
    TESTopicInfo *GetMatchingInfo(
        bool &,
        TESObjectREFR *,
        TESObjectREFR *,
        bool,
        TESTopic *,
        BSSimpleList<DialogueItem *> *
    ) const;
    TESTopicInfo *GetMatchingInfo(bool &, TESObjectREFR *, TESObjectREFR *) const;
    TESTopicInfo *GetMatchingInfo(TESObjectREFR *, TESObjectREFR *) const;
    void ResetTopics();
    int GetJournalIndex();
    void SetJournalIndex(int);
    bool AddJournalEntry(int, Actor *);
    static void BadQuestInfo(QUEST_INFO *);
    static TESTopicInfo *GetInfoByIndex(QUEST_INFO *, unsigned int);
    static void ClearAllSaidOnceInfosForQuest(TESQuest *);
    static void ResetInfoIndexes(TopicInfoArray *);
    static void AddDefaultTopics();
    static void RemoveDefaultTopics();
    static TESTopic *GetTopic(DIALOGUE_TYPE, int);
    static TESTopic *GetOwnerTopic(TESTopicInfo *);
    static void AlterOwner(TESTopicInfo *);
    static void AddTopicToSortedList(TESTopic *, BSSimpleList<TESTopic *> *, bool);
    static bool CompareTopics(TESTopic *, TESTopic *, bool);
    static void SortTopics(bool, BSSimpleList<TESTopic *> *);
    static bool SortQuestsOnAllTopics(TESQuest *);
    static bool IsFormTypeDialogueChild(unsigned char);
    static unsigned int CreateConversation(
        TESObjectREFR *, TESObjectREFR *, BSSimpleList<DialogueItem *> *, TESTopic *
    );
    static TESTopicInfo *GetMatchingFollowUpInfo(
        TESTopicInfo *,
        bool &,
        TESObjectREFR *,
        TESObjectREFR *,
        bool,
        BSSimpleList<DialogueItem *> *
    );
    static void ResetAllTopics();
    static void SetShowConversationStats(bool);
    static bool GetShowConversationStats();
    static TESTopic *pLastTopic;

protected:
    static TESTopicInfo *GetMatchingInfo(
        const TESTopic *,
        bool &,
        TESObjectREFR *,
        TESObjectREFR *,
        bool,
        TESTopic *,
        BSSimpleList<DialogueItem *> *
    );

private:
    DIALOGUE_DATA m_Data; // 0x34
    float m_fPriority; // 0x38
    BSSimpleList<QUEST_INFO *> m_listQuestInfo; // 0x3c
    BSStringT<char> cDummyPrompt; // 0x44
    int m_iJournalIndex; // 0x4c
    static bool bShowConversationStats;
};
