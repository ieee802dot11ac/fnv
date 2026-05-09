#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/magic/spellitem.h"

struct BGSHungerStageData { /* Size=0x8 */
    uint iFOOD; // 0x0
    SpellItem *pSickness; // 0x4
    void Initialize() {
        iFOOD = 0;
        pSickness = nullptr;
    }
    void Endian() {
        EndianSwapEq(iFOOD);
        EndianSwapEq(reinterpret_cast<u32 &>(pSickness));
    }
    BGSHungerStageData() { Initialize(); }
};

class BGSHungerStage : public TESForm {
public:
    BGSHungerStage();
    virtual ~BGSHungerStage() { RemoveStage(this); }
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void InitItem();
    virtual void ClearData();
    BGSHungerStageData *GetData();
    virtual void InitializeData();
    SpellItem *GetSickness();
    void SetSickness(SpellItem *);
    uint GetRads();
    void SetRads(uint);

    static uint GetNumStages();
    static BGSHungerStage *GetStage(uint);
    static BGSHungerStage *FindStageForRadLevel(float);

    BS_MEM_OVERLOADS

protected:
    static BGSHungerStage **AllocateStages(uint);
    static void SortStages();
    static void AddStage(BGSHungerStage *);
    static void RemoveStage(uint);
    static void RemoveStage(BGSHungerStage *);

    BGSHungerStageData data; // 0x28
    static unsigned int iNumStages;
    static BGSHungerStage **pStagesArray;
};
