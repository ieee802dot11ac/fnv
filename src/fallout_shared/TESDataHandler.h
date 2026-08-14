#pragma once

#include "fallout/magic/MagicTarget.h"
#include "fallout_shared/TESAmmoEffect.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESRace.h"
#include "fallout_shared/tesobjectrefr.h"
#include "fallout_shared/tesscript.h"
#include "nimain/NiAVObject.h"

class TESDataHandler {
  public:
	TESDataHandler(const TESDataHandler&);
	TESDataHandler();
	~TESDataHandler();
	bool SaveForm(TESForm*, bool);
	char* GetFormName(u8);
	void CleanUpBadForms();
	void CheckModels(bool);
	void OutputModelSizeList();
	void CheckTexturesRecurse(NiAVObject*, const char*);
	void PrintTextureInfo(const NiTexturingProperty::Map*, NiTriBasedGeom*,
						  const char*, const char*, bool);
	void CheckIcons();
	void CheckForNiRawImageData(char*);
	bool AddFormToDataHandler(TESForm*);
	void ReleaseForm(TESForm*);
	u8 NotUniqueID(const char*);
	void GetObjectCounts();
	void GetReferenceCounts();
	void UpdateAutoCalcNPCs();
	void GenerateDefaultObjects();
	void EnumReferencesCloseToPoint(TESObjectCELL*, const NiPoint3&, float,
									const NiPoint3&, float,
									bool (*)(TESObjectREFR*, int), int);
	void EnumReferencesCloseToPoint(const NiPoint3&, float, const NiPoint3&,
									float, bool (*)(TESObjectREFR*, int), int);
	void EnumReferencesCloseToRef(TESObjectREFR*, float, const NiPoint3&, float,
								  bool (*)(TESObjectREFR*, int), int);
	bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*,
											BSSimpleList<TESObjectREFR*>*);
	bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*,
									   BSSimpleList<TESObjectREFR*>*);
	bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*,
											   BSSimpleList<TESObjectREFR*>*,
											   bool);
	TESObjectREFR* FindFirstReference(TESObject*);
	TESObjectREFR* FindFirstReference(char*);
	bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*,
							BSSimpleList<TESObjectREFR*>*);
	bool FindConnectedSmallSpace(TESForm*, TESForm*,
								 BSSimpleList<TESObjectREFR*>*,
								 BSSimpleList<TESObjectREFR*>*);
	TESWorldSpace* FindEntryPoint(TESForm*, NiPoint3&,
								  BSSimpleList<TESObjectREFR*>*);
	TESObjectREFR* FindClosestReference(TESBoundObject*, const NiPoint3&,
										TESObjectCELL*);
	TESObjectREFR* FindClosestReference(char*, const NiPoint3&, TESObjectCELL*);
	TESObjectREFR* GetReference(const char*);
	TESObjectREFR* GetReference(uint);
	TESLandTexture* GetLandTexture(const char*);
	TESLandTexture* GetLandTexture(uint);
	TESRace* GetRace(const char*);
	TESRace* GetRace(uint);
	TESClass* GetClass(const char*);
	TESClass* GetClass(uint);
	Script* GetScript(const char*);
	Script* GetScript(uint);
	TESSound* GetSound(const char*);
	TESSound* GetSound(uint);
	TESGlobal* GetGlobal(const char*);
	TESGlobal* GetGlobal(uint);
	BGSVoiceType* GetVoiceType(uint);
	TESFaction* GetFaction(const char*);
	TESFaction* GetFaction(uint);
	TESReputation* GetReputation(const char*);
	TESReputation* GetReputation(uint);
	TESRecipe* GetRecipe(const char*);
	TESRecipe* GetRecipe(uint);
	TESRecipeCategory* GetRecipeCategory(const char*);
	TESRecipeCategory* GetRecipeCategory(uint);
	TESCasino* GetCasino(const char*);
	TESCasino* GetCasino(uint);
	TESCaravanDeck* GetCaravanDeck(const char*);
	TESCaravanDeck* GetCaravanDeck(uint);
	TESTopic* GetTopic(DIALOGUE_TYPE, int);
	TESTopic* GetTopic(const char*);
	TESTopic* GetTopic(uint);
	TESChallenge* GetChallenge(const char*);
	TESAmmoEffect* GetAmmoEffect(const char*);
	TESQuest* GetQuest(const char*);
	TESCombatStyle* GetCombatStyle(const char*);
	TESEffectShader* GetEffectShader(const char*);
	BGSProjectile* GetProjectile(const char*);
	BGSExplosion* GetExplosion(const char*);
	BGSDebris* GetDebris(const char*);
	BGSPerk* GetPerk(const char*);
	BGSMessage* GetMessage(const char*);
	TESLoadScreenType* GetLoadScreenType(const char*);
	TESLoadScreenType* GetLoadScreenType(uint);
	TESObjectList* GetObjectList();
	BSSimpleList<TESFile*>* GetFileList();
	BSSimpleList<BGSBodyPartData*>* GetPartDataList();
	BSSimpleList<BGSPerk*>* GetPerkList();
	BSSimpleList<BGSDebris*>* GetDebrisList();
	BSSimpleList<BGSExplosion*>* GetExplosionList();
	BSSimpleList<BGSProjectile*>* GetProjectileList();
	BSSimpleList<BGSRadiationStage*>* GetRadiationStageList();
	BSSimpleList<BGSDehydrationStage*>* GetDehydrationStageList();
	BSSimpleList<BGSHungerStage*>* GetHungerStageList();
	BSSimpleList<BGSSleepDeprevationStage*>* GetSleepDeprevationStageList();
	BSSimpleList<TESEffectShader*>* GetEffectShaderList();
	BSSimpleList<TESWaterForm*>* GetWaterList();
	BSSimpleList<TESLoadScreen*>* GetLoadScreenList();
	BSSimpleList<TESObjectANIO*>* GetAnimObjectList();
	TESObjectANIO* GetAnimObject(TESIdleForm*, int);
	BSSimpleList<TESCombatStyle*>* GetCombatStyleList();
	BSSimpleList<TESPackage*>* GetPackageList();
	BSSimpleList<TESWorldSpace*>* GetWorldSpaceList();
	BSSimpleList<TESClimate*>* GetClimateList();
	BSSimpleList<TESImageSpace*>* GetImageSpaceList();
	BSSimpleList<TESImageSpaceModifier*>* GetImageSpaceModifierList();
	BSSimpleList<TESWeather*>* GetWeatherList();
	BSSimpleList<EnchantmentItem*>* GetEnchantmentItemList();
	BSSimpleList<SpellItem*>* GetSpellItemList();
	BSSimpleList<TESLandTexture*>* GetLandTextList();
	BSSimpleList<BGSCameraShot*>* GetCameraShotList();
	BSSimpleList<BGSHeadPart*>* GetHeadPartList();
	BSSimpleList<TESHair*>* GetHairList();
	BSSimpleList<TESEyes*>* GetEyesList();
	BSSimpleList<TESRace*>* GetRaceList();
	BSSimpleList<BGSEncounterZone*>* GetZoneList();
	BSSimpleList<TESClass*>* GetClassList();
	BSSimpleList<TESFaction*>* GetFactionList();
	BSSimpleList<TESReputation*>* GetReputationList();
	BSSimpleList<TESChallenge*>* GetChallengeList();
	BSSimpleList<TESRecipe*>* GetRecipeList();
	BSSimpleList<TESRecipeCategory*>* GetRecipeCategoryList();
	BSSimpleList<TESAmmoEffect*>* GetAmmoEffectList();
	BSSimpleList<TESCasino*>* GetCasinoList();
	BSSimpleList<TESCaravanDeck*>* GetCaravanDeckList();
	BSSimpleList<TESSound*>* GetSoundList();
	BSSimpleList<BGSAcousticSpace*>* GetAcousticSpaceList();
	BSSimpleList<BGSRagdoll*>* GetRagdollList();
	BSSimpleList<TESGlobal*>* GetGlobalList();
	BSSimpleList<BGSVoiceType*>* GetVoiceTypeList();
	BSSimpleList<BGSImpactData*>* GetImpactDataList();
	BSSimpleList<BGSImpactDataSet*>* GetImpactDataSetList();
	NiTList<TESForm*>* GetBadFormList();
	TESRegionList* GetRegionList();
	BSSimpleList<TESTopic*>* GetTopicList();
	BSSimpleList<TESTopicInfo*>* GetTopicInfoList();
	BSSimpleList<BGSNote*>* GetNoteList();
	BSSimpleList<BGSMenuIcon*>* GetMenuIconList();
	BSSimpleList<BGSListForm*>* GetListFormList();
	BSSimpleList<BGSMessage*>* GetMessageList();
	BSSimpleList<BGSLightingTemplate*>* GetLightingTemplateList();
	BSSimpleList<BGSMusicType*>* GetMusicTypeList();
	BSSimpleList<TESLoadScreenType*>* GetLoadScreenTypeList();
	BSSimpleList<MediaSet*>* GetMediaSetList();
	BSSimpleList<MediaLocationController*>* GetMediaLocationControllerList();
	void AddTopic(TESTopic*);
	void RemoveTopic(TESTopic*);
	void AddTopicInfo(TESTopicInfo*);
	void RemoveTopicInfo(TESTopicInfo*);
	BSSimpleList<Script*>* GetScriptList();
	void SortScriptList();
	BSSimpleList<TESQuest*>* GetQuestList();
	void AddQuest(TESQuest*);
	void RemoveQuest(TESQuest*);
	uint GetAddonNodeCount();
	BGSAddonNode* GetAddonNode(uint);
	void AddAddonNode(BGSAddonNode*);
	void RemoveAddonNode(BGSAddonNode*);
	TESObjectCELL* NewCell(char*);
	TESObjectCELL* NewCell(char*, int, int, TESWorldSpace*);
	uint GetInteriorCellCount();
	TESObjectCELL* GetInteriorCellByIndex(uint);
	void SortInteriorCells();
	uint GetCellCount();
	TESObjectCELL* GetCellByIndex(uint);
	TESObjectCELL* GetCellByNumericID(uint);
	TESObjectCELL* GetCellByEditorID(const char*);
	TESWorldSpace* GetExtCellDataFromFileByEditorID(const char*, int&, int&);
	TESObjectCELL* GetCellFromWorldCoord(float, float, TESWorldSpace*, bool);
	TESObjectCELL* GetCellFromCellCoord(int, int, TESWorldSpace*, bool);
	TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL*);
	void UnloadCell(TESObjectCELL*);
	void UnloadCell(int, int, TESWorldSpace*);
	void UnloadCell(char*);
	TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, const NiPoint3&,
											   const NiPoint3&, bool,
											   BGSPrimitive*, void*);
	TESObjectREFR* CreateReferenceAtLocation(TESBoundObject*, const NiPoint3&,
											 const NiPoint3&, TESObjectCELL*,
											 TESWorldSpace*, TESObjectREFR*,
											 BGSPrimitive*, void*);
	TESObjectCELL* SelectCell(NiPoint3, bool*, TESWorldSpace*);
	bool AssignToCell(TESObjectCELL*, TESObjectREFR*);
	bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
	void RemoveDuplicateReferences();
	TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, const NiPoint3&,
											  const NiPoint3&, TESObjectCELL*,
											  TESWorldSpace*);
	TESObjectREFR* CreateExplosionAtLocation(TESBoundObject*, const NiPoint3&,
											 const NiPoint3&, TESObjectCELL*,
											 TESWorldSpace*);
	TESFile* GetListFile(uint);
	TESFile* GetListFile(char*);
	bool RemoveListFile(TESFile*);
	char* GetActiveFileName();
	void SetActiveFile(TESFile*);
	TESFile* GetActiveFile();
	void RemoveIDFromDataHandler(uint);
	uint GetNextID();
	void AddCompiledFile(TESFile*);
	void ClearFileList();
	bool BuildFileList(char*);
	void CreateThreadSafeFiles();
	int CountCheckedFiles(COUNT_TYPE);
	uint CountFiles();
	uint CountCompiled();
	bool CompileFiles(bool);
	bool ClearData();
	bool SaveActiveData(char*, bool);
	void CloseAllTES();
	bool ConstructObjectList(TESFile*, bool);
	void ClearLoadedFormCount();
	uint AddDownloadedContentToFileList();
	void RunAllPersistentRefScripts();
	bool ConstructObject(TESFile*, bool, TESForm*, bool);
	bool FormGroupLoadsInGame(TESFile*, FORM*);
	bool ResetOffsetData(TESFile*);
	void FixAllScriptIDs();
	void SetMasterFileLargeBuffer(int);
	bool GetMasterSave();
	void SetMasterSave(bool);
	bool GetSaveLoadGame();
	void SetSaveLoadGame(bool);
	bool GetSaveLoad();
	void SetSaveLoad(bool);
	bool GetAutoSaving();
	void SetAutoSaving(bool);
	bool GetClearingData();
	void SetClearingData(bool);
	bool GetHasDesiredFiles();
	void SetHasDesiredFiles(bool);
	bool IsSavingLoading();
	void SetCheckingModels(bool);
	bool GetCheckingModels();
	void SetLoadingFiles(bool);
	bool GetLoadingFiles();
	bool GetGameSettingsLoaded();
	void SortAllList();
	void FlushSoundBuffers();
	void CreateBarterContainer(TESObjectREFR*);
	void RemoveItemBarterContainer(ItemChange*, int, TESObjectREFR*);
	void ClearBarterContainer();
	InventoryChanges* GetBarterContainer();
	void CreateRecipeContainer(TESObjectREFR*);
	void RemoveItemRecipeContainer(ItemChange*, int, TESObjectREFR*);
	void ClearRecipeContainer();
	InventoryChanges* GetRecipeContainer();
	TESRegionDataManager* GetRegionDataManager();
	TESFile* GetCompiledFile(int);
	uint GetNextFormID();
	void SetNextFormID(uint);
	bool IsFormIDCreated(uint);
	AlchemyItem* DoesPotionMatch(AlchemyItem*);
	void SetDontRemoveIDs(bool);
	bool GetDontRemoveIDs();
	NiTPrimitiveArray<TESObjectCELL*>& QArrayInteriorCells();
	TESEffectShader* GetSpotterShader();
	TESEffectShader* GetItemDetectedShader();
	TESEffectShader* GetCateyeShader();
	void SetSpotterShader(TESEffectShader*);
	void SetItemDetectedShader(TESEffectShader*);
	void SetCateyeShader(TESEffectShader*);
	void ClearDLCFlags();
	int GetNumDLCInstalled();

	static bool LoadForm(TESForm*, TESFile*);
	static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, const char*);
	static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, int);
	static void FileCacheCompleteCallback(const char*);
	static TESForm* CreateFormOfType(u8);

  protected:
	void DataError(DAT_ERROR);
	bool IsFormIDInUse(uint);
	void AdvanceNextID();
	char* GetDLCFlags();
	bool IsDLCFlagSet(char);
	void SetDLCFlag(char, bool);
	int IsDLCPackageName(char*);
	uint LoadFilesInDirectory(const char*, const _XCONTENT_DATA&);

	/* Size=0x63c */
	char cDLCFlags;												  // 0x000
	TESObjectList* pObjectList;									  // 0x004
	BSSimpleList<TESPackage*> listPackages;						  // 0x008
	BSSimpleList<TESWorldSpace*> listWorldSpaces;				  // 0x010
	BSSimpleList<TESClimate*> listClimates;						  // 0x018
	BSSimpleList<TESImageSpace*> listImageSpaces;				  // 0x020
	BSSimpleList<TESImageSpaceModifier*> listImageSpaceModifiers; // 0x028
	BSSimpleList<TESWeather*> listWeather;						  // 0x030
	BSSimpleList<EnchantmentItem*> listEnchantmentItems;		  // 0x038
	BSSimpleList<SpellItem*> listSpellItems;					  // 0x040
	BSSimpleList<BGSHeadPart*> listHeadParts;					  // 0x048
	BSSimpleList<TESHair*> listHair;							  // 0x050
	BSSimpleList<TESEyes*> listEyes;							  // 0x058
	BSSimpleList<TESRace*> listRaces;							  // 0x060
	BSSimpleList<BGSEncounterZone*> listZones;					  // 0x068
	BSSimpleList<TESLandTexture*> listLandTexts;				  // 0x070
	BSSimpleList<BGSCameraShot*> listCameraShots;				  // 0x078
	BSSimpleList<TESClass*> listClasses;						  // 0x080
	BSSimpleList<TESFaction*> listFactions;						  // 0x088
	BSSimpleList<TESReputation*> listReputations;				  // 0x090
	BSSimpleList<TESChallenge*> listChallenges;					  // 0x098
	BSSimpleList<TESRecipe*> listRecipes;						  // 0x0a0
	BSSimpleList<TESRecipeCategory*> listRecipeCategories;		  // 0x0a8
	BSSimpleList<TESAmmoEffect*> listAmmoEffects;				  // 0x0b0
	BSSimpleList<TESCasino*> listCasinos;						  // 0x0b8
	BSSimpleList<TESCaravanDeck*> listCaravanDecks;				  // 0x0c0
	BSSimpleList<Script*> listScripts;							  // 0x0c8
	BSSimpleList<TESSound*> listSounds;							  // 0x0d0
	BSSimpleList<BGSAcousticSpace*> listAcousticSpaces;			  // 0x0d8
	BSSimpleList<BGSRagdoll*> listRagdolls;						  // 0x0e0
	BSSimpleList<TESGlobal*> listGlobals;						  // 0x0e8
	BSSimpleList<BGSVoiceType*> listVoiceTypes;					  // 0x0f0
	BSSimpleList<BGSImpactData*> listImpactData;				  // 0x0f8
	BSSimpleList<BGSImpactDataSet*> listImpactDataSet;			  // 0x100
	BSSimpleList<TESTopic*> listTopics;							  // 0x108
	BSSimpleList<TESTopicInfo*> listTopicInfos;					  // 0x110
	BSSimpleList<TESQuest*> listQuests;							  // 0x118
	BSSimpleList<TESCombatStyle*> listCombatStyles;				  // 0x120
	BSSimpleList<TESLoadScreen*> listLoadScreens;				  // 0x128
	BSSimpleList<TESWaterForm*> listWater;						  // 0x130
	BSSimpleList<TESEffectShader*> listEffectShaders;			  // 0x138
	BSSimpleList<BGSProjectile*> listProjectiles;				  // 0x140
	BSSimpleList<BGSExplosion*> listExplosions;					  // 0x148
	BSSimpleList<BGSRadiationStage*> listRadiation;				  // 0x150
	BSSimpleList<BGSDehydrationStage*> listDehydration;			  // 0x158
	BSSimpleList<BGSHungerStage*> listHunger;					  // 0x160
	BSSimpleList<BGSSleepDeprevationStage*> listSleepDeprevation; // 0x168
	BSSimpleList<BGSDebris*> listDebris;						  // 0x170
	BSSimpleList<BGSPerk*> listPerks;							  // 0x178
	BSSimpleList<BGSBodyPartData*> listPartData;				  // 0x180
	BSSimpleList<BGSNote*> listNotes;							  // 0x188
	BSSimpleList<BGSListForm*> listListForms;					  // 0x190
	BSSimpleList<BGSMenuIcon*> listMenuIcons;					  // 0x198
	BSSimpleList<TESObjectANIO*> animObjects;					  // 0x1a0
	BSSimpleList<BGSMessage*> listMessages;						  // 0x1a8
	BSSimpleList<BGSLightingTemplate*> listLightingTemplates;	  // 0x1b0
	BSSimpleList<BGSMusicType*> listMusicTypes;					  // 0x1b8
	BSSimpleList<TESLoadScreenType*> listLoadScreenTypes;		  // 0x1c0
	BSSimpleList<MediaSet*> listMediaSets;						  // 0x1c8
	BSSimpleList<MediaLocationController*>
		listMediaLocationControllers;					  // 0x1d0
	TESRegionList* pRegionList;							  // 0x1d8
	NiTPrimitiveArray<TESObjectCELL*> arrayInteriorCells; // 0x1dc
	NiTPrimitiveArray<BGSAddonNode*> arrayAddonNodes;	  // 0x1ec
	NiTList<TESForm*> listBadForms;						  // 0x1fc
	uint iNextID;										  // 0x208
	TESFile* pActiveFile;								  // 0x20c
	BSSimpleList<TESFile*> listFiles;					  // 0x210
	uint iNumCompile;									  // 0x218
	TESFile* pFileIndex[255];							  // 0x21c
	bool bMasterSave;									  // 0x618
	bool bSaveLoadGame;									  // 0x619
	bool bSaveLoad;										  // 0x61a
	bool bAutoSaving;									  // 0x61b
	bool bExportingPlugin;								  // 0x61c
	bool bClearingData;									  // 0x61d
	bool bHasDesiredFiles;								  // 0x61e
	bool bCheckingModels;								  // 0x61f
	bool bLoadingFiles;									  // 0x620
	bool bDontRemoveIDs;								  // 0x621
	u8 ucGameSettingsLoadState;							  // 0x622
	TESRegionDataManager* pRegionDataManager;			  // 0x624
	InventoryChanges* pBarterContainer;					  // 0x628
	InventoryChanges* pRecipeContainer;					  // 0x62c
	TESEffectShader* pSpotterShader;					  // 0x630
	TESEffectShader* pItemDetectedShader;				  // 0x634
	TESEffectShader* pCateyeMobileShader;				  // 0x638
};
