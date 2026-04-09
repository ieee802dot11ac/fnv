#pragma once

#include "bsaudio/bssoundhandle.h"
#include "fallout/ai/baseprocess.h"
#include "fallout_shared/tesform.h"
#include "fallout_shared/tesobjectrefr.h"

class MobileObject : public TESObjectREFR { /* Size=0x98 */
    /* 0x0000: fields for TESObjectREFR */
protected:
    BaseProcess *pCurrentProcess; // 0x78
    TESObjectREFR *pTalkingActivator; // 0x7c
    MobileObject *pDialogueItemTarget; // 0x80
public:
    float fUpdateTargetTimer; // 0x84
    float fSayToFailVoiceTimer; // 0x88
    bool bSpeakingDone; // 0x8c
    bool bTalkingToPlayer; // 0x8d
    bool bIgnoreChangeAnimationCall; // 0x8e
    bool bSoundFileDone; // 0x8f
    bool bVoiceFileDone; // 0x90
    bool bTalkingActivator; // 0x91
    bool bInTempChangeList; // 0x92
    bool bDoNotRunSayToCallBack; // 0x93
protected:
    char cSoundCallBackSet; // 0x94
    bool bSoundCallBackSuccess; // 0x95
    bool bUseEmotion; // 0x96
    bool bRunsInLow; // 0x97

public:
    virtual bool MovetoHigh();
    virtual bool MovetoLow();
    virtual bool MovetoMiddleLow();
    virtual bool MovetoMiddleHigh();
    MobileObject(const MobileObject &);
    MobileObject();
    virtual ~MobileObject();
    virtual NiAVObject *Load3D(bool);
    virtual NiPoint3 GetBoundMin();
    virtual NiPoint3 GetBoundMax();
    virtual bool IsMobileObject();
    virtual bhkCharacterController *Move(float, NiPoint3 &, unsigned int);
    virtual bhkCharacterController *Jump();
    bhkCharacterController *GetCharController();
    virtual void SetAvoidanceDisabled(bool);
    unsigned int CheckHighDetail();
    void HandleTextureUpgrade(bool);
    float GetLastTimeProcessed();
    float GetLastDateProcessed();
    int GetLastDayProcessed();
    int GetLastMonthProcessed();
    int GetLastYearProcessed();
    void InitLastTimeProcessed();
    bool IsTalking();
    virtual void Process(float);
    PROCESS_TYPE GetCurrentProcessType();
    BaseProcess *GetCurrentAIProcess();
    void SetCurrentAIProcess(BaseProcess *);
    PROCESS_TYPE GetProcessLevel();
    bool ChangeProcessLevel(PROCESS_TYPE);
    bool ChangeProcessLevel(bool);
    virtual bool ChangeProcessLevel();
    PROCESS_TYPE GetDesiredProcessLevel();
    virtual void UpdateInDialogue(float, DialogueResponse *, bool);
    virtual void UpdateAnimation(float);
    virtual bool GetEVPBuffered();
    virtual void EvaluatePackage();
    virtual bool IsInCombat(bool);
    bool GetNoPersuasion();
    bool GetOfferBarter();
    bool GetOfferTraining();
    bool GetOfferRepair();
    bool GetOfferRecharge();
    bool IsInDialoguewithPlayer();
    virtual void SetDialoguewithPlayer(bool);
    virtual bool InitiateDialogue(TESPackage *);
    virtual bool InitiateDialogue(
        MobileObject *,
        PackageLocation *,
        PackageLocation *,
        bool,
        bool,
        bool,
        TESTopic *,
        bool,
        bool
    );
    virtual float SpeakSoundFunction(
        const char *,
        BSSoundHandle &,
        DIALOGUE_EMOTION,
        unsigned int,
        int,
        TESIdleForm *,
        TESIdleForm *,
        TESObjectREFR *,
        bool,
        bool,
        bool,
        bool,
        bool
    );
    virtual void EndDialogue();
    CFilter GetCollisionFilter();
    void CleanUpOtherMobileObjects(bool);
    void DeleteCurrentProcess();
    virtual void SetDelete(bool);
    void SetTalkingActivatorRef(TESObjectREFR *);
    void SetTalkingActivator(bool);
    bool IsTalkingActivator();
    TESObjectREFR *GetTalkingActivator();
    virtual void SetRunOnceExtraPackage(TESPackage *, char);
    void AddSayOnceTopicInfo(TESTopicInfo *);
    void RemoveSayOnceTopicInfo(TESTopicInfo *);
    bool HasSaidTopicInfo(TESTopicInfo *);
    void UpdateTopicInfoSayOnce();
    virtual bool HasEditorLocation();
    virtual TESWorldSpace *GetEditorLocationWorld();
    virtual TESObjectCELL *GetEditorLocationInteriorCell();
    virtual NiPoint3 GetEditorLocationCoord();
    virtual void SetParentCell(TESObjectCELL *);
    virtual bool DetachCharController();
    virtual bool RemoveCharController();
    virtual bool DetachHavok();
    virtual void InitHavok();
    virtual void SetPosition(const NiPoint3 &);
    virtual void GetLinearVelocity(NiPoint3 &);
    virtual void EvaluateDetection(float);
    virtual float GetDetectionTimer();
    virtual void ReduceDetectionTimer();
    virtual float GetHeading(bool);
    virtual void SetHeading(TESObjectREFR *);
    virtual void SetHeading(float);
    void ModHeading(float);
    float GetActualHeading();
    virtual TESObjectREFR *GetCurrentTarget();
    virtual bool IsAtPoint(const NiPoint3 &, float, bool, bool);
    float GetLooking();
    void SetLooking(float);
    void ModLooking(float);
    virtual int GetSpeakingEmotion();
    virtual void SetSpeakingEmotion(int);
    virtual int GetSpeakingEmotionValue();
    virtual void SetSpeakingEmotionValue(int);
    MobileObject *GetDialogueItemTarget();
    void SetDialogueItemTarget(MobileObject *);
    virtual void SetSize(float);
    void SetChaseBip(bool);
    virtual float GetAcrobatics();
    virtual bool IsDying();
    virtual bool IsKnockedOut();
    virtual void MoveHavok(bool);
    bool IsInAir();
    void SetRotation(const NiPoint3 &);
    virtual bool IsTransient();
    virtual void SetDisplayGeometry(bool);
    TESPackage *GetCurrentPackage();
    bool IsinDialogue();
    unsigned int GetChangeFlagsForPackage(TESPackage *);
    void StopCurrentDialogue();
    void AddChangeFlagsForPackage(TESPackage *);
    virtual void PutCreatedPackage(TESPackage *, bool, bool);
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void InitLoadGame(BGSLoadFormBuffer *);
    virtual void InitLoadGame(unsigned int, unsigned int);
    virtual void FinishInitLoadGame(unsigned int, unsigned int);
    virtual void Revert(BGSLoadFormBuffer *);
    virtual void Revert(unsigned int);
    virtual void FinishLoadGame(BGSLoadFormBuffer *);
    BSSoundHandle PlaySound(unsigned int, bool, unsigned int, bool);
    BSSoundHandle PlaySound(char *, bool, unsigned int);
    BSSoundHandle PlaySoundByEditorName(const char *, bool, unsigned int, bool);
    void SetSoundCallBack(char);
    void SetSoundCallBackSuccess(bool);
    virtual void UpdateSoundCallBack();
    virtual void Update(float);
    virtual void CleanUpPointersOnDisable();
    virtual MobileObject *SetUpTalkingActivatorActor(MobileObject *, MobileObject *&);
    bool GetShouldUseEmotionAnimation();
    void SetShouldUseEmotionAnimation(bool);
    void SetPackageStartLocationFromCurrentLocation();
    bool GetRunsInLow();
    virtual void SetRunsInLow(bool);

    static void SayToCallBack(void *, bool);
    static void ChangeDialogueAnimation(void *, bool);
    static void DialogueConversationCallBack(void *, bool);
    static void SoundFileCallBack(void *, bool);
    static void DisplaySubTitleCallback(void *, int);

private:
    static MobileObject *pTalkingToPlayer;
};
