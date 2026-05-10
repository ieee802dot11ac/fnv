#pragma once

#include "bsmain/QueuedFiles.h"
#include "fallout_shared/BGSImpactData.h"
#include "fallout_shared/BGSPreloadable.h"
#include "fallout_shared/TESForm.h"

class ImpactSwap;

class BGSImpactDataSet : public TESForm, public BGSPreloadable {
public:
    enum IMPACT_MATERIAL_TYPE {
        IMP_MAT_STONE = 0x0000,
        IMP_MAT_DIRT = 0x0001,
        IMP_MAT_GRASS = 0x0002,
        IMP_MAT_GLASS = 0x0003,
        IMP_MAT_METAL = 0x0004,
        IMP_MAT_WOOD = 0x0005,
        IMP_MAT_ORGANIC = 0x0006,
        IMP_MAT_CLOTH = 0x0007,
        IMP_MAT_WATER = 0x0008,
        IMP_MAT_HOLLOW_METAL = 0x0009,
        IMP_MAT_ORGANIC_BUG = 0x000a,
        IMP_MAT_ORGANIC_GLOW = 0x000b,
        IMP_MAT_COUNT = 0x000c,
    };

    static char *pImpactMaterialString[IMP_MAT_COUNT];
    BGSImpactDataSet(const BGSImpactDataSet &);
    BGSImpactDataSet();
    virtual ~BGSImpactDataSet();
    virtual void InitializeData();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void InitItem();
    BGSImpactData *GetImpactData(MATERIAL_TYPE);
    BGSImpactData *GetImpactData(IMPACT_MATERIAL_TYPE);
    void SetImpactData(IMPACT_MATERIAL_TYPE, BGSImpactData *);
    void TestHavokLayer();
    virtual void QueueFiles(IO_TASK_PRIORITY, QueuedFile *);

    static IMPACT_MATERIAL_TYPE GetImpactMaterialType(MATERIAL_TYPE);
    static void CreateDefaultImpactDataSet();
    static BGSImpactDataSet *GetDefaultImpactDataSet();
    static void ClearDefaultImpactDataSet();
    static void ApplyImpactSwap(ImpactSwap *);

protected:
    BGSImpactData *ppImpactData[IMP_MAT_COUNT]; // 0x2c

    static BGSImpactDataSet *pDefaultImpactDataSet;
    static ImpactSwap *pActiveImpactSwap;
};
