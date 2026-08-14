#pragma once

#include "fallout_shared/ContainerItemExtra.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesobject.h"

class TESActorBase;

class ContainerObject { /* Size=0xc */
  public:
	int i_count;					// 0x0
	TESBoundObject* pObj;			// 0x4
	ContainerItemExtra* pItemExtra; // 0x8

	ContainerObject();
	~ContainerObject();
	void Save();
	void InitItem(TESForm*);
	bool Compare(ContainerObject*);
	void Copy(ContainerObject*);
};

class TESContainer : public BaseFormComponent {
  public:
	TESContainer(const TESContainer&);
	TESContainer();
	~TESContainer();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	void InitItem(TESForm*);
	void FreeObjectList();
	ContainerObject* AddObject(CONTAINER_OBJECT_FILE*);
	ContainerObject* AddObject(TESObject*, int, ContainerItemExtra*);
	void AddDuplicateObject(ContainerObject*);
	ContainerObject* GetFirstContainerObject();
	void RemoveContainerObject(ContainerObject*);
	void ReplaceObject(TESObject*, TESObject*);
	bool HasObject(TESObject*);
	float GetContainerWeight(bool);
	int GetObjectCount(TESObject*);
	char Compare(ContainerObject*, ContainerObject*);
	float GetClothingModifier();
	void AddContainerContents(TESContainer*);
	void MultiplyContainerCounts(int);
	void ApplyHealthPercentToContainer(float);
	void AddContainerToReference(TESObjectREFR*, bool);
	void AddLevItemContainerToChanges(int, InventoryChanges*);
	TESAmmo* GetBestAmmo(TESActorBase*);
	TESObjectWEAP* GetBestWeapon(TESActorBase*);
	TESObjectARMO* GetBestArmor(TESActorBase*, BIPED_OBJECT);
	TESObjectCLOT* GetBestClothing(TESActorBase*, BIPED_OBJECT);
	TESBoundObject* GetWornItem(BIPED_OBJECT);
	BSSimpleList<ContainerObject*>* GetObjectList();
	BSSimpleList<ContainerObject*>* GetFilteredList();

	static bool ContainerCanHoldType(unsigned char);
	static bool IsGold(TESObject*);

  protected:
	BSSimpleList<ContainerObject*> objectList; // 0x4
};
