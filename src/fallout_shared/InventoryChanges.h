#pragma once

#include "bscore/bssimplelist.h"
#include "fallout_shared/ExtraDataList.h"
#include "fallout_shared/TESLevItem.h"
#include "fallout_shared/magic/effectsetting.h"
#include "fallout_shared/tesobjectrefr.h"

class TESContainer;
class TESActorBase;

class InventoryChanges {
  public:
	InventoryChanges(TESObjectREFR*);
	~InventoryChanges();
	void ForceWeightRecalculation();
	void CreateExtraDataList(TESBoundObject*, int, Actor*, ExtraDataList*,
							 ItemChange*);
	bool IsEmpty();
	void AddItem(TESBoundObject*, ExtraDataList*, int);
	void AddItem(TESObjectREFR*, int, bool, bool);
	void AddChangeItem(ItemChange*, bool);
	void RemoveChangeItem(TESBoundObject*);
	TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int,
							  ExtraDataList*, bool, TESObjectREFR*,
							  const NiPoint3*, const NiPoint3*, bool, bool,
							  ItemChange*);
	void RemoveItemType(ENUM_FORM_ID, bool, int);
	TESObjectREFR* DropItemIntoWorld(TESObjectREFR*, TESBoundObject*, int,
									 TESObjectREFR*, const NiPoint3*,
									 const NiPoint3*);
	void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*,
							  ExtraDataList*);
	void DamageItem(TESBoundObject*, float);
	void RepairItem(TESBoundObject*, float);
	void AddOwnership(TESBoundObject*, TESForm*);
	void RemoveOwnership(TESBoundObject*);
	TESContainer* GetOriginalContainer();
	void AddWorn(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
	bool RemoveWorn(bool&, TESBoundObject*, int, Actor*, ExtraDataList*, bool,
					bool, ItemChange*, bool*);
	void InitScripts();
	bool RunScripts(TESObjectREFR*);
	void CleanUpBadData();
	void CleanUpBoundItems(Actor*);
	TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
	void ModifyCharge(float);
	ItemChange* GetObjectInList(TESBoundObject*, bool, unsigned int);
	ExtraDataList* WearingObject(TESBoundObject*, bool);
	bool WearingWeapon(TESBoundObject**);
	bool WearingAmmo(TESBoundObject**);
	bool WearingTorch(TESBoundObject**);
	ItemChange* WearingRing(bool);
	bool WearingVoiceModulateItem();
	bool HasObjectId(unsigned int);
	bool ContainerHasObjects(TESBoundObject*, PACKAGE_OBJECT_TYPE, int,
							 PACKAGE_OBJECT_TYPE&, unsigned int,
							 TESObjectREFR*);
	bool HasQuestObject();
	bool HasScript();
	TESBoundObject* GetObjectbyType(ENUM_FORM_ID, int&);
	TESBoundObject* GetObjectbyPackObjType(PACKAGE_OBJECT_TYPE, int&);
	ItemChange* GetPotion(const EffectSetting*);
	ItemChange* GetBestAmmo(TESActorBase*, bool);
	TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool&);
	ItemChange* GetBestWeapon(TESActorBase*, float&, COMBAT_WEAPON_TYPE, bool);
	ItemChange* GetBestArmor(TESActorBase*, BIPED_OBJECT, bool);
	BSSimpleList<ItemChange*>* GetListBestArmor(TESActorBase*);
	ItemChange* GetBestClothing(TESActorBase*, BIPED_OBJECT, bool);
	ItemChange* GetBestLight(TESActorBase*, bool);
	ItemChange* GetWornItem(BIPED_OBJECT, bool);
	ItemChange* GetHotKeyItem(int);
	ItemChange** GetHotKeyItems(const int, const int);
	void SetHotKeyItem(ItemChange*, ExtraDataList*, int);
	void RemoveHotKeyItem(ItemChange*, int);
	void RemoveAllObjectsWorn(bool, TESObjectREFR*);
	bool RechargeAll();
	void RemoveAllHealth();
	int GetCount(bool);
	ItemChange* GetItembyIndex(int);
	OEI_Fast_InventoryIterator* StartOEIFastInventoryIteration();
	ItemChange* GetNextOEIFastInventoryItem(OEI_Fast_InventoryIterator*);
	void GetItemGroup(TESBoundObject*, BSSimpleList<ItemChange*>*);
	void GetRepairItemGroup(TESBoundObject*, BSSimpleList<ItemChange*>*);
	void GetItemModGroup(TESBoundObject*, BSSimpleList<ItemChange*>*);
	int GetObjectCount(ENUM_FORM_ID);
	int GetObjectCount(TESBoundObject*);
	ItemChange* GetBestFood();
	int GetGoldAmount();
	void RemoveGold(TESObjectREFR*, int, TESObjectREFR*);
	float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool,
							  bool, int, BGSListForm*);
	float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool,
						 int, BGSListForm*);
	void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
	void RemoveStolenItems(TESObjectREFR*, TESObjectREFR*, TESForm*);
	void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
	float GetInventoryWeight(bool);
	uint GetInventoryValue(bool, bool);
	void AddAmountToItemChange(TESBoundObject*, int);
	float GetEquippedWeight(Actor*);
	void InitLeveledItems();
	void InitFromContainerExtra();
	void RemoveDefaultLeveledItems();
	bool IsLevelItemInited(int);
	ItemChange* GetInventoryItem(TESBoundObject*, unsigned int);
	void SetItemsBacktoDefaultState();
	void CreateCopyofList(InventoryChanges*, TESObjectREFR*, bool);
	void ClearAllChangeItems();
	void ResetCachedWeights();
	ushort GetSaveSize();
	void SaveGame(BGSSaveFormBuffer*);
	void SaveGame();
	void LoadGame(BGSLoadFormBuffer*);
	void LoadGame();
	void InitLoadGame(BGSLoadFormBuffer*);
	void InitLoadGame();
	int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
	ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
	unsigned int IterateInventory(bool (*)(ItemChange*, void*), void*,
								  unsigned int);
	bool GetNextItem(InventoryIterator&, ItemChange*&, unsigned int);
	TESObjectREFR* GetRef();

	static void KillTempRef();
	static InventoryChanges* GetInventoryChanges(TESObjectREFR*);
	static TESObjectREFR* GetTempRef();

	BSSimpleList<ItemChange*>* pListofChanges; // 0x00
	static ExtraDataList* pRestackedList;

  private:
	TESObjectREFR* pRef;			// 0x04
	float fcontainerweight;			// 0x08
	float fpreviousContainerWeight; // 0x0c
	bool bcountdirty;				// 0x10
	static TESObjectREFR* pTempRef;
	static BSSpinLock kRunScriptsLock;

	void RemoveExtraFromObject(TESObject*, ExtraDataList*);
	void DeleteExtraData(TESBoundObject*, ExtraDataList*);
};
