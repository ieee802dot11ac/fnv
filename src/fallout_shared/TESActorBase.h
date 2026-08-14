#pragma once

#include "fallout_shared/TESContainer.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/actorvalue.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tesmodel.h"
#include "fallout_shared/tesobject.h"

class TESActorBase : public TESBoundAnimObject,
					 public TESActorBaseData,
					 public TESContainer,
					 public BGSTouchSpellForm,
					 public TESSpellList,
					 public TESAIForm,
					 public TESHealthForm,
					 public TESAttributes,
					 public TESAnimation,
					 public TESFullName,
					 public TESModel,
					 public TESScriptableForm,
					 public ActorValueOwner,
					 public BGSDestructibleObjectForm {
  public:
	virtual bool IsActorBase();
	int GetHealth();
	void SetHealth(int);
	int GetBaseHealth();
	void SetBaseHealth(int);
	bool DoesSwim();
	bool DoesWalk();
	bool DoesFly();
	bool IsImmobile();
	bool FightsInWater();
	bool GetUseBipedAnims();
	SEX GetSex() const;
	virtual bool IsAutoCalc();
	virtual void SetAutoCalc(bool);
	float GetDesirability(TESForm*);
	virtual bool GetHasPLSpecTex() const;
	bool GetStartsDead() const;
	void SetStartsDead(bool);
	virtual BGSBodyPartData* GetBodyPartData();
	virtual void SetBodyPartData(BGSBodyPartData*);
	virtual TESCombatStyle* GetCombatStyle();
	virtual void SetCombatStyle(TESCombatStyle*);
	virtual unsigned short GetActorLevel();
	virtual int GetActorValue(ActorValue::Index);
	virtual float GetActorFloatValue(ActorValue::Index);
	virtual void SetActorValue(ActorValue::Index, float);
	virtual void SetActorValue(ActorValue::Index, int);
	virtual void ModActorValue(ActorValue::Index, float);
	virtual void ModActorValue(ActorValue::Index, int);
	void SetDialogDerivedAttributeTextFields(HWND*);
	virtual TESForm* GetAsForm();
	bool ShouldRunInitDefaultWorn(TESObjectREFR*);
	virtual void AddChange(int);
	virtual void RemoveChange(int);
	virtual unsigned short GetSaveSize(unsigned int);
	virtual void SaveGame(BGSSaveFormBuffer*);
	virtual void SaveGame(unsigned int);
	virtual void LoadGame(BGSLoadFormBuffer*);
	virtual void LoadGame(unsigned int, unsigned int);
	virtual void Revert(BGSLoadFormBuffer*);
	virtual void Revert(unsigned int);
	void Reset3DForLoadedActors(unsigned char);
	TESActorBase(const TESActorBase&);
	TESActorBase();
	virtual ~TESActorBase();
};
