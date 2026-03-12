#pragma once

#include "fallout_shared/tesglobal.h"
#include "fallout_shared/tesscriptshared.h"

struct CONDITION_ITEM_DATA { /* Size=0x1c */
    char iFlags;
    union { // 0x4
        TESGlobal *pGlobal;
        float fValue;
    };
    FUNCTION_DATA FunctionData; // 0x08
    CONDITIONITEMOBJECT eObject; // 0x14
    TESObjectREFR *pRunOnRef; // 0x18

public:
    void Endian();
};

class TESConditionItem { /* Size=0x1c */
public:
    // static ConditionItemObjectDesc ObjectDescA[5];

    TESConditionItem();
    ~TESConditionItem();
    void Save();
    void Load(TESFile *);
    void InitItem(TESForm *);
    void Copy(TESConditionItem *, TESForm *);
    bool Compare(TESConditionItem *);
    bool GetOr();
    void SetOr(bool);
    TESObjectREFR *GetRunOnRef();
    void SetRunOnRef(TESObjectREFR *);
    CONDITIONITEMOBJECT GetObject();
    void SetObject(CONDITIONITEMOBJECT);
    SCRIPT_OUTPUT GetConditionFunction();
    void SetConditionFunction(SCRIPT_OUTPUT);
    FUNCTION_DATA *GetConditionFunctionData();
    void SetDefaultDataForFunction(SCRIPT_OUTPUT);
    bool GetValueIsGlobal();
    void SetValueIsGlobal(bool);
    float GetComparisonValue();
    TESGlobal *GetComparisonValueGlobal();
    void SetComparisonValueFloat(float);
    void SetComparisonValueGlobal(TESGlobal *);
    ENUM_COMPARISON_CONDITION GetComparisonCondition();
    void SetComparisonCondition(ENUM_COMPARISON_CONDITION);
    bool IsTrue(TESObjectREFR *, TESObjectREFR *, bool &);
    bool IsTrue(TESObjectREFR *, TESObjectREFR *);

protected:
    CONDITION_ITEM_DATA *GetData();

private:
    CONDITION_ITEM_DATA Data; // 0x0
};
