#pragma once

#include "fallout_shared/enums.h"
#include "fallout_shared/tesconditionitem.h"
#include "fallout_shared/tesform.h"

class TESCondition {
public:
    static const char *ComparisonConditionSymbols[6];

    TESCondition(const TESCondition &);
    TESCondition();
    ~TESCondition();
    void Save();
    void Load(TESFile *);
    void InitItem(TESForm *);
    void Copy(TESCondition *, TESForm *);
    bool Compare(TESCondition *);
    void AddConditionItem(TESConditionItem *);
    void AddConditionItemAtIndex(TESConditionItem *, int);
    TESConditionItem *GetConditionItem(int);
    void RemoveConditionItem(int);
    void RemoveConditionItem(TESConditionItem *);
    bool MoveConditionItem(TESConditionItem *, bool);
    void ClearAllConditionItems();
    void ForceTrailingAnd();
    bool IsTrue(TESObjectREFR *, TESObjectREFR *, bool &, bool);
    bool IsTrue(TESObjectREFR *, TESObjectREFR *);
    const BSSimpleList<TESConditionItem *> *GetConditionItemListConst();

    static const char *GetComparisonConditionSymbol(ENUM_COMPARISON_CONDITION);
    static bool CheckValue(ENUM_COMPARISON_CONDITION, float, float);

protected:
    BSSimpleList<TESConditionItem *> *GetConditionItemList();

private:
    BSSimpleList<TESConditionItem *> listConditions; // 0x0
};
