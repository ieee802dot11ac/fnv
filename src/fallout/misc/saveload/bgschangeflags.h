#pragma once

class TESForm;

class BGSChangeFlags {
public:
    BGSChangeFlags(int);
    BGSChangeFlags();
    bool CheckFlags(int);
    bool CheckFlagsExact(int);
    bool CheckFlagsExclusive(int);
    void SetFlags(int);
    void AddFlags(int);
    void RemoveFlags(int);
    BGSChangeFlags GetDifference(int);
    operator int();
    bool ReduceToForcedChanges(TESForm *);

    static const char *GetFlagName(int, unsigned int, bool);
    static const char *GetShortFlagName(int, unsigned int);
    static bool IsForcedChange(int, unsigned int, unsigned int);
    static BGSChangeFlags
    GetUnrevertibleChanges(BGSChangeFlags, BGSChangeFlags, unsigned int, bool);

protected:
    int iFlags; // 0x0
};
