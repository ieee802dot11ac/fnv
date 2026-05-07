#pragma once

#include "fallout_shared/TESCondition.h"
#include "fallout_shared/TESDescription.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tesicon.h"

enum PERK_ENTRY_TYPE {
    PERK_ENTRY_TYPE_QUEST = 0x0000,
    PERK_ENTRY_TYPE_ABILITY = 0x0001,
    PERK_ENTRY_TYPE_ENTRY_POINT = 0x0002,
    PERK_ENTRY_TYPE_COUNT = 0x0003,
};

struct PerkEntrySaveData {
    u8 cPerkEntryType; // 0x0
    u8 cRank; // 0x1
    u8 cPriority; // 0x2

    void Endian();
};

struct PerkData { /* Size=0x5 */
    bool bTrait; // 0x0
    u8 cLevel; // 0x1
    u8 cNumRanks; // 0x2
    bool bPlayable; // 0x3
    bool bHidden; // 0x4

    void Endian();
};

class BGSPerkEntry {
public:
    virtual bool CheckConditionFilters(unsigned int, TESForm **);
    virtual unsigned char GetFunction();
    virtual void *GetFunctionData();
    BGSPerkEntry(const BGSPerkEntry &);
    BGSPerkEntry();
    virtual ~BGSPerkEntry();
    virtual PERK_ENTRY_TYPE GetType();
    virtual void ClearData();
    virtual void InitItem(TESForm *);
    virtual BGSPerkEntry *Duplicate();
    virtual void Copy(BGSPerkEntry *);
    virtual bool Compare(BGSPerkEntry *);
    virtual void Save();
    virtual bool Load(TESFile *);
    void StartPerkEntry(PERK_ENTRY_TYPE);
    void FinishPerkEntry();
    void InitializeFromSaveData(PerkEntrySaveData *);
    unsigned char GetRank();
    unsigned char GetPriority();
    void SetRank(unsigned char);
    void SetPriority(unsigned char);
    virtual void ApplyPerkEntry(Actor *, bool);
    virtual void RemovePerkEntry(Actor *, bool);

    static BGSPerkEntry *CreatePerkEntryOfType(PERK_ENTRY_TYPE);

protected:
    u8 cRank; // 0x4
    u8 cPriority; // 0x5
};

class BGSPerk : public TESForm,
                public TESFullName,
                public TESDescription,
                public TESIcon {
public:
    BGSPerk(const BGSPerk &);
    BGSPerk();
    virtual ~BGSPerk();
    virtual void InitializeData();
    virtual void ClearData();
    virtual void InitItem();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void Save();
    virtual bool Load(TESFile *);
    bool AddPerkEntry(BGSPerkEntry *);
    void RemovePerkEntry(BGSPerkEntry *);
    unsigned char GetNumRanks();
    void SetNumRanks(unsigned char);
    bool GetIsTrait();
    bool GetIsPlayable();
    char GetLevel();
    bool IsPerkAvailable(TESObjectREFR *);
    bool IsPerkAttainable(TESObjectREFR *);
    bool IsPerkHidden();
    void ApplyPerk(Actor *, unsigned char, unsigned char, bool);
    void RevertPerk(Actor *, unsigned char, bool);
    void RemovePerk(Actor *, bool);
    BGSPerkEntry *GetPerkEntryByRank(unsigned char);
    void AddPerkEntryPoints(Actor *, unsigned char, bool);
    void BuildDescriptionString(char *, unsigned int);

    static int PerkEntryRankSortFunction(BGSPerkEntry *, BGSPerkEntry *);
    static int PerkEntryPrioritySortFunction(BGSPerkEntry *, BGSPerkEntry *);

protected:
    PerkData Data; // 0x48
    TESCondition PerkConditions; // 0x50
    BSSimpleList<BGSPerkEntry *> PerkEntries; // 0x58
};
