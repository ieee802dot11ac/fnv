#pragma once

#include "bscore/bssimplelist.h"
#include "bscore/bsstring.h"
#include "bscore/memorymanager.h"
#include "fallout/misc/saveload/bgssaveformbuffer.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesfile.h"
#include "gamebryo2.2/corelibs/nimain/nipoint3.h"
#include "win_types.h"
#include <types.h>

struct FORM {
    uint form; // 0x00
    uint length; // 0x04
    uint flags; // 0x08
    uint iFormID; // 0x0c
    uint iVersionControl; // 0x10
    u16 sFormVersion; // 0x14
    u16 sVCVersion; // 0x16

    void Endian();

    BS_MEM_OVERLOADS
};

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class TESForm : public BaseFormComponent {
public:
    static bool bFormIDsBashed;
    // static NiTPointerMap<unsigned int,TESForm *>* pAllForms;
    // static NiTLargePrimitiveArray<TESForm *>* pAlteredForms;
    // static BSTCaseInsensitiveStringMap<TESForm *>* pAllFormsByEditorID;

    TESForm(const TESForm &);
    TESForm();
    virtual ~TESForm();
    virtual void InitializeData();
    virtual void InitializeDataComponent();
    void InitializeDataAllComponents();
    virtual void ClearData();
    virtual void ClearDataComponent();
    void ClearDataAllComponents();
    virtual bool ProcessBeforeSave();
    virtual bool Load(TESFile *);
    virtual bool LoadPartial(TESFile *);
    virtual bool Save(TESFile *);
    virtual void Save();
    virtual bool LoadEdit(TESFile *);
    virtual bool SaveEdit(TESFile *);
    virtual bool SavesBefore(FORM *);
    virtual bool SavesBefore(TESForm *);
    void SaveData();
    void LoadData(TESFile *, void *, u16);
    uint GetDataSizeAdded();
    //   public: virtual TESForm* CreateDuplicateForm(bool, NiTPointerMap<TESForm
    //   *,TESForm *>*);
    // public: virtual void PostDuplicateProcess(NiTPointerMap<TESForm
    //   *,TESForm *>*);
    virtual void AddChange(int);
    void ForceChange(int);
    virtual void RemoveChange(int);
    virtual u16 GetSaveSize(uint);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(uint);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(uint, uint);
    virtual void InitLoadGame(BGSLoadFormBuffer *);
    virtual void InitLoadGame(uint, uint);
    virtual void FinishInitLoadGame(uint, uint);
    virtual void Revert(BGSLoadFormBuffer *);
    virtual void Revert(uint);
    virtual void LoadQueuedFormData(u16);
    void SaveGameDataOLD(double *, int);
    void SaveGameDataOLD(NiPoint3 *, int);
    void SaveGameDataOLD(float *, int);
    void SaveGameDataOLD(uint *, int);
    void SaveGameDataOLD(int *, int);
    void SaveGameDataOLD(u16 *, int);
    void SaveGameDataOLD(s16 *, int);
    void SaveGameDataOLD(void *, int);
    void LoadGameDataOLD(double *, int);
    void LoadGameDataOLD(NiPoint3 *, int);
    void LoadGameDataOLD(float *, int);
    void LoadGameDataOLD(uint *, int);
    void LoadGameDataOLD(int *, int);
    void LoadGameDataOLD(u16 *, int);
    void LoadGameDataOLD(s16 *, int);
    void LoadGameDataOLD(void *, int);
    void SaveNumericID(uint *, int);
    void LoadNumericID(uint *, int);

    virtual bool FindInFileFast(TESFile *);
    virtual void CheckSaveGame(BGSSaveFormBuffer *);
    virtual void FinishLoadGame(BGSLoadFormBuffer *);
    virtual void InitItem();
    uint GetFileCount();
    TESFile *GetFile(int);
    TESFile *GetOwnerMaster();
    void SetFile(TESFile *);
    bool IsInFile(TESFile *);
    void ClearFiles();
    BSSimpleList<TESFile *> *GetFileList();
    char *GetFormTypeString() const;
    ENUM_FORM_ID GetFormType() const;
    void SetFormType(ENUM_FORM_ID);
    virtual ENUM_FORM_ID GetSavedFormType();
    virtual void GetFormDetailedString(BSStringT<char> &);
    void RemoveFromDataStructures();
    bool GetMaster() const; // bit 0
    bool GetDelete() const; // bit 6
    bool GetAltered() const;
    bool GetInitialized() const; // bit 3
    virtual bool GetQuestObject() const;
    virtual bool GetHasSpokenFlag() const;
    virtual bool GetHavokDeath() const;
    virtual bool GetRandomAnim() const;
    virtual bool GetNeedtoChangeProcess() const;
    bool GetBorderRegion() const;
    virtual bool GetDangerous() const;
    virtual bool GetHasPLSpecTex() const;
    bool GetIgnoreFriendlyHits() const;
    virtual bool GetObstacle() const;
    bool GetFireOff() const;
    bool GetTemporary() const { return iFormFlags & 0x4000; }
    bool GetIgnore() const;
    bool GetNoCollision() const; // bit 5
    bool GetHasResults() const;
    bool GetNoAIAcquire() const;
    bool GetReflectedByAutoWater() const;
    bool GetRefractedByAutoWater() const;
    virtual bool GetContinuousBroadcast() const;
    bool GetLockMultiBound() const;
    bool GetGlobalConstant() const;
    bool GetLODTree() const;
    bool GetChildCanUse() const;
    virtual bool GetOnLocalMap();
    bool GetInPlaceableWater();
    void SetInPlaceableWater(bool);
    virtual void SetOnLocalMap(bool);
    bool GetMustBeVisibleDistant() const;
    void SetMustBeVisibleDistant(bool);
    //   public: virtual NiColor* GetEmittanceColor();
    bool GetEmpty() const;
    bool GetResetDestruct() const;
    bool GetDestroyed() const;
    bool GetDestructible() const;
    bool GetVATSTargetOverride() const;
    bool GetDisableFade() const;
    void SetDisableFade(bool);
    bool IsStillLoading() const;
    void SetStillLoading(bool);
    bool IsRecentPCDrop() const;
    void SetRecentPCDrop(bool);
    void SetNoCollision(bool);
    void SetMaster(bool);
    virtual void SetDelete(bool);
    bool GetDeleted() const;
    void SetInitialized(bool);
    virtual void SetAltered(bool);
    virtual void SetQuestObject(bool);
    void SetIgnore(bool);
    virtual void SetHasSpokenFlag(bool);
    virtual void SetHavokDeath(bool);
    void SetRandomAnim(bool);
    virtual void SetNeedToChangeProcess(bool);
    void SetFireOff(bool);
    void SetTemporary();
    void SetBorderRegion(bool);
    void SetHasPLSpecTex(bool);
    void SetIgnoreFriendlyHits(bool);
    void SetObstacle(bool);
    void SetNoAIAcquire(bool);
    void SetReflectedByAutoWater(bool);
    void SetRefractedByAutoWater(bool);
    void SetLockMultiBound(bool);
    void SetGlobalConstant(bool);
    void SetLODTree(bool);
    void SetChildCanUse(bool);
    bool GetDisabled() const;
    void SetDisabled(bool);
    bool GetDisabledOrDeleted() const;
    void SetEmpty(bool);
    void SetResetDestruct(bool);
    void SetDestroyed(bool);
    void SetDestructible(bool);
    void SetVATSTargetOverride(bool);
    void SetHasResults(bool);
    bool IsDefaultForm() const;
    virtual void SaveObjectBound();
    virtual void LoadObjectBound(TESFile *);
    virtual bool IsBoundObject();
    virtual bool IsObject();
    virtual bool IsMagicItem();
    virtual bool IsReference();
    virtual bool IsArmorAddon();
    virtual bool IsActorBase();
    virtual bool IsMobileObject();
    virtual bool IsActor();
    virtual uint GetRefCount();
    void LoadForm(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    void CopyAllComponents(TESForm *);
    bool CompareAllComponents(TESForm *);
    virtual bool BelongsInGroup(FORM *, bool, bool);
    //   public: virtual void CreateGroupData(FORM*, FORM_GROUP*);
    uint GetFormEditorIDLength();
    virtual const char *GetFormEditorID();
    bool SetFormEditorID(HWND *, uint);
    bool SetFormEditorID(const char *);
    void SetVCVersion(unsigned char);
    unsigned char GetVCVersion();
    unsigned char GetVCPrevVersion();
    void IncVCVersion();
    void DecVCVersion();
    void SetVersionControl(uint);
    uint GetVersionControl() const;
    unsigned char GetCurrentUser() const;
    unsigned char GetLastUser() const;
    u16 GetVersionControlDate() const;
    bool IsLastUserRegion();
    bool IsCurrentUserRegion();
    void SetCurrentUserRegion();
    u16 GetVersionControlMonth() const;
    u16 GetVersionControlDay() const;
    u16 GetVersionControlYear() const;
    virtual bool IsParentForm();
    virtual bool IsParentFormTree();
    virtual bool IsFormTypeChild(unsigned char);
    //   public: virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool,
    //   TESBoundObject*, int);
    uint GetFormFlags() const;
    void SetFormFlags(uint);
    uint GetFormID() const;
    uint GetFormIDAsSaved();
    uint GetFormIDWithoutIndex() const;
    bool FormIDMatchesWithoutIndex(uint) const;
    virtual void SetFormID(uint, bool);
    virtual char *GetObjectTypeName();
    void *GetFormBuffer();
    uint GetFormBufferSize();
    void FreeFormBuffer();
    //   public: bool ExpandChunk(CHUNK*, u16);
    void __SaveData(void *, uint);
    void StartForm();
    void CloseForm();

    static void CompressSaveBuffer();
    //   public: static void RunPostDuplicateProcess(NiTPointerMap<TESForm *,TESForm *>*);
    static TESForm *GetFormByNumericID(uint);
    static TESForm *GetFormByEditorID(const char *);
    static TESForm *GetFormByFullName(const char *, unsigned char);
    static const char *GetFormTypeString(unsigned char);
    static ENUM_FORM_ID GetFormTypeFromFormString(uint);
    static bool CanBeOnLocalMap(unsigned char);
    static bool IsDefaultForm(uint);
    static bool FixFormEditorID(const char *);
    static bool FixFormEditorID(char *);
    static void AddCompileIndex(uint &, TESFile *);
    static void ReleaseFormDataStructures();
    static bool QEndianSwapOnSave();
    static void SetEndianSwapOnSave(bool);

    static void AddChunk(CHUNK_ID, ULARGE_INTEGER);
    static void AddChunk(CHUNK_ID, u16);
    static void AddChunk(CHUNK_ID, s16);
    static void AddChunk(CHUNK_ID, uint);
    static void AddChunk(CHUNK_ID, float);
    static void AddChunk(CHUNK_ID, int);
    static void AddChunk(CHUNK_ID, u8);
    static void AddChunk(CHUNK_ID, s8);
    static void AddChunk(CHUNK_ID);
    static void AddChunkArray(CHUNK_ID, const char *, uint);
    static void AddChunkArray(CHUNK_ID, const u16 *, uint);
    static void AddChunkArray(CHUNK_ID, const s16 *, uint);
    static void AddChunkArray(CHUNK_ID, const uint *, uint);
    static void AddChunkArray(CHUNK_ID, const int *, uint);
    static void AddChunkArray(CHUNK_ID, const float *, uint);
    static void __AddChunkData(CHUNK_ID, const void *, uint);

private:
    u8 cFormType; // 0x04
    uint iFormFlags; // 0x08
    uint iFormID; // 0x0c
    BSStringT<char> cFormEditorID; // 0x10
    uint iVersionControl; // 0x18
    u8 cVCVersion; // 0x1c
    BSSimpleList<TESFile *> pSourceFiles; // 0x20

    static uint iTotalFormCount;
    static void *pFormBuffer;
    static uint iBufferSize;
    static bool bEndianSwapOnSave;

    static void InitializeFormDataStructures();
    static void AddChunkArray32(CHUNK_ID, const void *, uint);
    static void AddChunkArray16(CHUNK_ID, const void *, uint);
};
