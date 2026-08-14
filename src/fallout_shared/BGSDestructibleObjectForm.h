#pragma once

#include "bscore/BSSimpleArray.h"
#include "fallout_shared/BGSExplosion.h"
#include "fallout_shared/tesmodel.h"
#include "fallout_shared/tesobjectrefr.h"
#include "nimain/NiTMap.h"

class DestructibleObjectData {
  public:
	uint iHealth;										// 0x00
	u8 cNumStages;										// 0x04
	u8 cFlags;											// 0x05
	class DestructibleObjectStage** pStagesArray;		// 0x08
	volatile int iReplacementModelRefCount;				// 0x0c
	NiPointer<QueuedFile> spPreloadedReplacementModels; // 0x10
};

class BGSDestructibleObjectForm : public BaseFormComponent {
  public:
	BGSDestructibleObjectForm(const BGSDestructibleObjectForm&);
	BGSDestructibleObjectForm();
	~BGSDestructibleObjectForm();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	void InitItem(TESForm*);
	// DestructibleObjectData *GetData();
	// DestructibleObjectStage *GetStage(unsigned int);
	unsigned char GetStageCount();
	// DestructibleObjectStage **AllocateStages(unsigned char);
	void SortStages();
	// void AddStage(DestructibleObjectStage *);
	void RemoveStage(unsigned int);
	bool HasValidStages();
	bool GetTargetableInVATS();
	void SetTargetableInVATS(bool);
	unsigned int GetMaxHealth(TESObjectREFR*);
	void DamageObject(TESObjectREFR*, float, bool);
	unsigned int SpawnExplosionsAtBlastNodes(NiAVObject*, BGSExplosion*,
											 unsigned int, TESObjectREFR*);
	void FindBlastNodes(NiAVObject*, unsigned int,
						BSSimpleArray<NiNode*, 1024>&);
	// unsigned int SpawnDebrisAtDebrisNodes(
	//     NiAVObject *, BGSDebris *, unsigned int, TESObjectREFR *, unsigned
	//     int
	// );
	void FindDebrisNodes(NiAVObject*, unsigned int,
						 BSSimpleArray<NiNode*, 1024>&);
	void FindDamageStageNodes(NiAVObject*, unsigned int,
							  BSSimpleArray<NiNode*, 1024>&);
	bool UpdateCurrentDamageStage(TESObjectREFR*, bool);
	void ApplyTerminalDamage(TESObjectREFR*);
	void FindModelSwapNodes(NiAVObject*, BSSimpleArray<NiNode*, 1024>&);
	void QueueFiles(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*);
	void PreloadReplacementModels(TESBoundObject*);
	void UnloadReplacementModels();
	float CalculateDangerousExplosionHealth(u8, float, float, BGSExplosion**);
	float CalculateDangerousExplosionTerminalTime(u8, float, float,
												  BGSExplosion**);
	// void DisplayDebugText(IDebugText *, TESObjectREFR *); void
	// DisplayNodeDebugText(IDebugText *, TESObjectREFR *);

	static void LoadChunk(BGSDestructibleObjectForm*, TESFile*);
	static bool IsDestructible(TESForm*);
	static unsigned int GetObjectHealth(TESForm*);
	static BGSDestructibleObjectForm* GetDestructionForm(TESForm*);
	static int GetModelSwapIndex(TESForm*, TESModel*);
	static TESModel* GetModelSwap(TESForm*, int);
	static void UpdateDamageStageNodes(NiAVObject*, unsigned int);
	static void UpdateDestructibleObjects();
	static void RemoveDestructibleObject(TESObjectREFR*);
	static int CalcDestructionStage(TESObjectREFR*);
	static bool HideSmallDebris(NiAVObject*);
	static bool IsDangerousObject(TESForm*);
	static float CalculateDangerousExplosionHealth(TESObjectREFR*, float, float,
												   BGSExplosion**);
	static unsigned int GetSelfDamage(TESObjectREFR*, float);
	static void SetSelfDamage(TESObjectREFR*, unsigned int);
	static void ClearDestruction(TESObjectREFR*);
	static NiTMap<TESObjectREFR*, unsigned int>* GetDestructibleObjectMap();
	static float GetLastUpdateTime();
	static void SetLastUpdateTime(float);

  protected:
	void ClearStages();
	void CreateData();
	void RemoveData();

	DestructibleObjectData* pData; // 0x4

	static float fLastTime;
	static NiTMap<TESObjectREFR*, unsigned int> DestructibleObjects;
};
