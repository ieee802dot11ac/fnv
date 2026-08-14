#pragma once

#include "bscore/BSCriticalSection.h"
#include "bscore/bssimplelist.h"
#include "bssystem/bsfile.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiTArray.h"
#include "nimain/NiTexture.h"
#include "xapilibi/minwinbase.h"

class TESForm;
class TESObjectREFR;
class TESObjectCELL;
class Actor;
class TESPackage;
class RevertStateInfo;
class FormAndFlags;
class SaveGameFile;
class TESWorldSpace;
class ChangeData;
class LoadFormHeader;
class SaveFormHeader;
class TESGlobal;
class NumericIDBufferMap;
class CreatedReferenceData;
class MovedReferenceData;

class TESSaveLoadGame { /* Size=0x1c8 */
  public:
	static BSCriticalSection SaveGameCriticalSection;
	enum ACTION_TYPE {
		ACTION_SAVE = 0,
		ACTION_LOAD = 1,
		ACTION_READ = 2,
		ACTION_DELETE = 3,
		ACTION_TOTAL = 4,
	};

	TESSaveLoadGame();
	~TESSaveLoadGame();
	void AddChange(TESForm*, uint);
	void ForceChange(TESForm*, uint);
	void RemoveChange(TESForm*, uint);
	void RemoveChanges(TESForm*, bool);
	uint GetChangeFlags(TESForm*, bool);
	void AllowChanges(bool);
	bool GetAllowChanges();
	uint GetFileSize();
	bool SaveGame(BSFile*, const char*, bool);
	bool LoadGame(BSFile*, const char*, bool);
	void DeleteSaveGame(BSFile*);
	void DeleteSaveGame(BSFile*, const char*);
	void SaveGameDataOLD(double*, uint);
	void SaveGameDataOLD(NiPoint3*, uint);
	void SaveGameDataOLD(float*, uint);
	void SaveGameDataOLD(uint*, uint);
	void SaveGameDataOLD(int*, uint);
	void SaveGameDataOLD(unsigned long*, uint);
	void SaveGameDataOLD(long*, uint);
	void SaveGameDataOLD(u16*, uint);
	void SaveGameDataOLD(short*, uint);
	void SaveGameDataOLD(void*, uint);
	void LoadGameDataOLD(double*, uint);
	void LoadGameDataOLD(NiPoint3*, uint);
	void LoadGameDataOLD(float*, uint);
	void LoadGameDataOLD(uint*, uint);
	void LoadGameDataOLD(int*, uint);
	void LoadGameDataOLD(unsigned long*, uint);
	void LoadGameDataOLD(long*, uint);
	void LoadGameDataOLD(u16*, uint);
	void LoadGameDataOLD(short*, uint);
	void LoadGameDataOLD(void*, uint);
	void SaveNumericID(uint*, uint);
	bool LoadNumericID(uint*, uint);
	u16 GetFileNameSaveSize(const char*);
	void SaveFileName(const char*);
	char* LoadFileName(char*);
	uint EndianConvert(uint);
	int EndianConvert(int);
	u16 EndianConvert(u16);
	short EndianConvert(short);
	u8 EndianConvert(u8);
	char EndianConvert(char);
	void SaveGameDataOLDEndian(void*, uint, uint);
	void LoadGameDataOLDEndian(void*, uint, uint);
	void WriteFile(BSFile*, NiPoint3*, uint);
	void WriteFile(BSFile*, float*, uint);
	void WriteFile(BSFile*, uint*, uint);
	void WriteFile(BSFile*, int*, uint);
	void WriteFile(BSFile*, unsigned long*, uint);
	void WriteFile(BSFile*, long*, uint);
	void WriteFile(BSFile*, u16*, uint);
	void WriteFile(BSFile*, short*, uint);
	uint WriteFile(BSFile*, void*, uint);
	void ReadFile(BSFile*, NiPoint3*, uint);
	void ReadFile(BSFile*, float*, uint);
	void ReadFile(BSFile*, uint*, uint);
	void ReadFile(BSFile*, int*, uint);
	void ReadFile(BSFile*, unsigned long*, uint);
	void ReadFile(BSFile*, long*, uint);
	void ReadFile(BSFile*, u16*, uint);
	void ReadFile(BSFile*, short*, uint);
	uint ReadFile(BSFile*, void*, uint);
	void WriteFileEndian(BSFile*, void*, uint, uint);
	void ReadFileEndian(BSFile*, void*, uint, uint);
	void AdvanceBuffer(uint);
	bool GetLoading();
	bool GetIniting();
	bool GetConstructingObject();
	bool GetInitObject();
	bool GetPositioning();
	bool GetTemporarilyMovingRef();
	bool GetRevertingCurrentChanges();
	bool GetLoadingTempRefs();
	bool GetDeferInitForms();
	bool GetSimulatedMode();
	bool GetSkyLoading();
	bool GetSaveGameLoading();
	bool GetReconstructingObjects();
	bool GetFadingInFromSaveGame();
	bool GetLoadingGlobalData();
	bool GetAutosaveWhenFadedIn();
	bool GetBusy();
	bool GetLoadingCreatedBaseObjects();
	bool GetPositioningPlayerCharacter();
	void SetLoading(bool);
	void SetIniting(bool);
	void SetConstructingObject(bool);
	void SetInitObject(bool);
	void SetPositioning(bool);
	void SetTemporarilyMovingRef(bool);
	void SetRevertingCurrentChanges(bool);
	void SetLoadingTempRefs(bool);
	void SetDeferInitForms(bool);
	void SetSimulatedMode(bool);
	void SetSkyLoading(bool);
	void SetSaveGameLoading(bool);
	void SetReconstructingObjects(bool);
	void SetFadingInFromSaveGame(bool);
	void SetLoadingGlobalData(bool);
	void SetAutosaveWhenFadedIn(bool);
	void SetBusy(bool);
	void SetLoadingCreatedBaseObjects(bool);
	void SetPositioningPlayerCharacter(bool);
	void* GetBufferPointer();
	void SetBufferPointer(void*);
	bool LoadForm(TESForm*);
	bool UnloadForm(TESForm*);
	bool LoadCell(TESObjectCELL*);
	void InitForms(NiTLargePrimitiveArray<FormAndFlags*>*, FormAndFlags*, bool);
	TESPackage* CreatePackage(uint, u8);
	void ClearFormID(uint);
	bool HasReferenceMoved(TESObjectCELL*, TESObjectREFR*, uint);
	bool GetRevertBefore();
	bool GetRevertAfter();
	uint ComputeArmorHash(Actor*);
	uint ConvertNumericID(uint);
	uint ReverseConvertNumericID(uint);
	void BuildChangesString(char*, TESForm*, uint, u8, bool);
	void QueueRemoveChange(uint);
	void QueueAnimationLoad(TESObjectREFR*, u16);
	void QueueAttachedAnimationLoad(TESObjectREFR*, u16);
	void QueueCharControllerLoad(TESObjectREFR*, u16);
	void QueueHavokDataLoad(TESObjectREFR*, u16);
	void Autosave();
	void Autoload();
	void Quicksave();
	bool Quickload();
	void GetSaveGameDisplayData(BSFile*, uint*, char*, char*, char*);
	NiTexture* GetSaveGameDataOLD(BSFile*, uint*, char*, char*, char*, char*,
								  char*, char*, int*, bool);
	NiTexture* ReadSaveGameDataOLD(BSFile*, uint, uint*, char*, u16*, char*,
								   float*, _SYSTEMTIME*, uint*, int*);
	void RetrieveSaveGameDataOLD(BSFile*, uint*, char*, char*, _FILETIME*,
								 char*);
	void GenerateSaveGameDataOLD(char*, char*, char*);
	BSSimpleList<SaveGameFile*>* GetSaveGameList();
	void BuildSaveGameList();
	void DeleteSaveGameList();
	void LoadQueuedData(bool);
	bool IsFormIDInChangesMap(uint);
	uint GetCreatedExteriorCellFormID(uint, int, int);
	bool GetSavingAllowed();
	void AddCreatedBaseObject(TESForm*);
	void RemoveCreatedBaseObject(uint);
	void RemoveCreatedBaseObject(TESForm*);
	uint AddNumericIDToArray(uint);
	uint GetNumericIDFromArray(uint);
	u16 AddWorldSpaceIDToArray(uint);
	uint GetWorldSpaceIDFromArray(u16);
	void UpdateLoadingSequence();
	uint PurgeSavedDataForCell(TESObjectCELL*);
	uint PurgeSavedDataForWorld(TESWorldSpace*);
	uint PurgeSavedDataForLocation(uint, bool);
	bool GetInitArrayExists();
	u8 GetCurrentVersion();
	void SetCurrentVersion(u8);
	void ResetVersions();
	void ResetCurrentVersion();
	void TestAllCells(uint);
	void SaveQueuedHavokData(TESObjectREFR*);
	void SaveQueuedAttachedAnimation(TESObjectREFR*);
	void RevertCurrentChanges(bool);
	void RevertForm(TESForm*, ChangeData*);
	void PerformDeferredDeletions();
	void PerformDeferredInitActorPackages();
	void RevertGlobalData();
	void SetUseNumericIDArray(bool);
	bool GetUseNumericIDArray();
	bool UseSaveGameBlocks();
	void QueueFormForFinalization(TESForm*);
	void FinalizeQueuedForms();
	void RemoveFormFromDeferredDeletionList(TESForm*);
	LoadFormHeader* GetCurrentlyLoadingFormHeader();
	SaveFormHeader* GetCurrentlySavingFormHeader();
	void* CreateQueuedBuffer(u16);
	void SafetyCheckReferencePositionAndAngle(TESObjectREFR*);
	bool IsInvalidPoint(NiPoint3*);
	FILETIME* GetMostRecentSaveGame();
	void DeleteForm(TESForm*);
	void AddFormToDeferredDeletionsList(TESForm*);
	uint GetNeedToConvertPCSaveGames();
	bool ConvertPCSaveGames();
	void RemoveFormFromInitFormArray(TESForm*);
	void CleanUpExpiredData();
	void TestSaveCreatedBaseObjects();
	void ClearNextSaveNumber();
	void AddInitItem(TESForm*);
	bool GetReconstructedAllObjects();
	void CleanupMaps();
	ChangeData* GetChanges(TESForm*);
	uint CheckFlags(TESForm*, uint);

  protected:
	void LoadAnimationForReference(TESObjectREFR*, uint, void*);
	void LoadAttachedAnimationForReference(TESObjectREFR*, void*);
	void LoadHavokDataForReference(TESObjectREFR*, void*);
	u16 GetQueuedBufferSaveSize(void*);
	BSFile* PrepForLoadSave(BSFile*, const char*, TESSaveLoadGame::ACTION_TYPE);
	void CleanupLoadSave(BSFile*, TESSaveLoadGame::ACTION_TYPE);

  private:
	uint LoadHeader(BSFile*, bool);
	void SaveHeader(BSFile*, const char*);
	void SaveGlobalData(BSFile*);
	void LoadGlobalData(BSFile*);
	void SaveGlobals(BSFile*);
	void LoadGlobals(BSFile*);
	void RevertGlobals(BSSimpleList<TESGlobal*>*);
	void SaveCreatedBaseObjects(BSFile*);
	void LoadCreatedBaseObjects(BSFile*);
	void DeleteCreatedBaseObjects();
	void SavePluginList(BSFile*);
	bool LoadPluginList(BSFile*);
	void SaveNumericIDArrays(BSFile*);
	void LoadNumericIDArrays(BSFile*);
	void SaveFinalData(BSFile*);
	void LoadFinalData(BSFile*);
	void LoadAnimations();
	void LoadAttachedAnimations();
	void LoadCharControllers();
	void LoadHavokData();
	void QueueBufferLoad(NumericIDBufferMap*, uint, u16);
	void CleanupCurrentGameState();
	void StartLoadingSequence();
	void EndLoadingSequence();
	uint CheckNewReference(TESForm*, uint);
	void CreateChangedReference(uint);
	TESForm* CreateReference(uint, CreatedReferenceData*);
	TESForm* CreateReferenceFromFile(uint, MovedReferenceData*);
	u16 GetInitialDataSaveSize(TESForm*, uint);
	void LoadInitialData(TESForm*, uint);
	void SaveInitialData(TESForm*, uint);
	void* CreateBuffer(uint);
	void SaveBuffer(BSFile*, void*, uint);
	void LoadBuffer(BSFile*, void*, uint);
	void DestroyBuffer(void*);
	void FinishLoad();
	bool ResetReferencePosition(TESObjectREFR*, bool);
	int ResetObject(TESForm*, uint, uint);
	bool InitObject(TESForm*, uint, bool);
	void SetRevertState(int);
	void GenerateSaveGameFileName(char*);
	void StripIllegalCharacters(char*);
	RevertStateInfo* GetRevertStateInfo(TESForm*);
	void ProcessRevertStateInfo(TESForm*, RevertStateInfo*);
	void SetCurrentlyLoadingFormHeader(LoadFormHeader*);
	void SetCurrentlySavingFormHeader(SaveFormHeader*);
	void ReInitForcedChanges(TESForm*, uint);
	void SetMostRecentSaveGame(BSFile*);
	void LoadMostRecentSaveGame();
	uint CalculateNextSaveNumber();
	uint GetNextSaveNumber();
	void SetReconstructedAllObjects(bool);
	void ReconstructAllObjects();
	bool CheckShouldReconstructAllObjects(NiPoint3, TESObjectCELL*,
										  TESWorldSpace*);
	void DisplayCorruptSaveGameMessage(BSFile*);

  public:
	static void DisplayDebugText(TESObjectREFR*, int, int*, int*);

  private:
	static int SaveGameCompare(SaveGameFile*, SaveGameFile*);
	/*
	  private:
		ChangesMap* m_pChanges;								   // 0x0000
		ChangesMap* m_pNewChanges;							   // 0x0004
		InteriorCellNewReferencesMap* m_pInteriorCellMap;	   // 0x0008
		ExteriorCellNewReferencesMap* m_pExteriorCellMap;	   // 0x000c
		ExteriorCellNewReferencesMap* m_pCreatedExteriorCells; // 0x0010
		void* m_pBuffer;									   // 0x0014
		uint m_iSaveLoadStates;								   // 0x0018
		bool m_bAllowChanges;								   // 0x001c
		NiTLargePrimitiveArray<FormAndFlags*>* m_pInitArray;   // 0x0020
		BSSimpleList<uint> m_MovedReferencesList;			   // 0x0024
		BSSimpleList<uint> m_CreatedBaseObjectsList;		   // 0x002c
		BSSimpleList<TESForm*> m_DeferredDeleteList;		   // 0x0034
		BSSimpleList<TESForm*> m_DeferredInitActorPackageList; // 0x003c
		SaveStats* m_pSaveLoadStats;						   // 0x0044
		int m_iRevertState;									   // 0x0048
		u8 m_iSavedPluginCount;								   // 0x004c
		u8* m_pFileIndexArray;								   // 0x0050
		uint m_iQueuedRemoveChanges;						   // 0x0054
		NumericIDBufferMap* m_pAnimationMap;				   // 0x0058
		NumericIDBufferMap* m_pAttachedAnimationMap;		   // 0x005c
		NumericIDBufferMap* m_pCharControllerMap;			   // 0x0060
		NumericIDBufferMap* m_pHavokDataMap;				   // 0x0064
		BSSimpleList<TESForm*> m_QueuedFormList;			   // 0x0068
		BSSimpleList<SaveGameFile*>* m_pSaveGameList;		   // 0x0070
		u8 m_cMajorVersion;									   // 0x0074
		u8 m_cMinorVersion;									   // 0x0075
		NiTLargePrimitiveArray<uint>* m_pNumericIDArray;	   // 0x0078
		NiTLargePrimitiveArray<uint>* m_pWorldSpaceIDArray;	   // 0x007c
		u8 m_cCurrentVersion;								   // 0x0080
		bool m_bUseNumericIDArray;							   // 0x0081
		LoadFormHeader* m_pCurrentlyLoadingFormHeader;		   // 0x0084
		SaveFormHeader* m_pCurrentlySavingFormHeader;		   // 0x0088
		uint m_iNextSaveNumber;								   // 0x008c
		uint m_iFileStartPosition;							   // 0x0090
		uint m_iSimulationFileSize;							   // 0x0094
		SYSTEMTIME m_OriginalSaveTime;						   // 0x0098
		uint m_iOriginalSaveVersion;						   // 0x00a8
		bool m_bReconstructedAllObjects;					   // 0x00ac
		bool m_bLoadingFromMainMenu;						   // 0x00ad
		bool m_bAutosaveDisabledDueToLackOfSpace;			   // 0x00ae
		bool m_bQuickloading;								   // 0x00af
		NiTLargePrimitiveArray<TESForm*>* m_pInitItemArray;	   // 0x00b0
		SavedPlayerData m_SavedPlayerData;					   // 0x00b4
		FILETIME* m_pMostRecentSaveGame;					   // 0x01c4
		*/
};

extern TESSaveLoadGame* pSaveLoadGameOLD;
