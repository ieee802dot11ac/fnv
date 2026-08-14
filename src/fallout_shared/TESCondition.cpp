#include "TESCondition.h"
#include "bscore/bssimplelist.h"
#include "fallout_shared/TESConditionItem.h"
#include "fallout_shared/enums.h"

const char* TESCondition::ComparisonConditionSymbols[6] = {"<=", ">=", ">",
														   "!=", "==", ""};

bool TESCondition::CheckValue(ENUM_COMPARISON_CONDITION aiCondition,
							  float afVal1, float afVal2) {
	// this is dumb. i hate this func
	switch (aiCondition) {
	case CC_EQUAL:
		return (afVal1 == afVal2);
	case CC_NOT_EQUAL:
		return (afVal1 != afVal2);
	case CC_GREATER_THAN:
		return (afVal1 > afVal2);
	case CC_GREATER_THAN_EQUAL:
		return (afVal1 >= afVal2);
	case CC_LESS_THAN:
		return (afVal1 < afVal2);
	case CC_LESS_THAN_EQUAL:
		return (afVal1 <= afVal2);
	default:
		return true;
	}
}

void TESCondition::Save() {
	for (auto* conds = &listConditions; conds != nullptr && !conds->IsEmpty();
		 conds = conds->GetNext()) {
		conds->GetItem()->Save();
	}
}

void TESCondition::InitItem(TESForm* apOwner) {
	for (auto* conds = &listConditions; conds != nullptr && !conds->IsEmpty();
		 conds = conds->GetNext()) {
		conds->GetItem()->InitItem(apOwner);
	}
}

bool TESCondition::Compare(TESCondition* apCompare) { return false; }

bool TESCondition::IsTrue(TESObjectREFR* apActionRef,
						  TESObjectREFR* apTargetRef,
						  bool& abDispositionFailure,
						  bool abEssentialPropertiesOnly) {
	return false;
}

TESConditionItem* TESCondition::GetConditionItem(int aiIndex) {
	return nullptr;
}

bool TESCondition::IsTrue(TESObjectREFR* apActionRef,
						  TESObjectREFR* apTargetRef) {
	bool b;
	return IsTrue(apActionRef, apTargetRef, b, false);
}

void TESCondition::ClearAllConditionItems() {
	for (auto* conds = &listConditions; !conds->IsEmpty();) {
		delete conds->GetItem();
		auto* next = conds->GetNext();
		if (next) {
			delete conds;
		}
		conds = next;
	}
}

TESCondition::~TESCondition() { ClearAllConditionItems(); }

void TESCondition::Load(TESFile* apFile) {
	if (apFile == nullptr || apFile->GetTESChunk() != CIDA_ID)
		return;
	TESConditionItem* item =
		new ("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout "
			 "Shared\\TESCondition.cpp",
			 122, __FUNCTION__) TESConditionItem;
	item->Load(apFile);
	listConditions.AddTail(item);
}

void TESCondition::Copy(TESCondition* apCopy, TESForm* apOwner) {
	ClearAllConditionItems();
	for (auto* conds = &apCopy->listConditions;
		 conds != nullptr && !conds->IsEmpty();) {
		TESConditionItem* item =
			new ("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout "
				 "Shared\\TESCondition.cpp",
				 162, __FUNCTION__) TESConditionItem;
		// wat
		item->Copy(conds->GetItem(), apOwner);
		listConditions.AddTail(item);
	}
}
