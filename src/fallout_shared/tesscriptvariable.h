#pragma once

#include "fallout_shared/tesscriptshared.h"

struct ScriptVariable {
    SCRIPT_LOCAL data; // 0x00
    BSStringT<char> cName; // 0x18

    ScriptVariable(const ScriptVariable &);
    ScriptVariable(ScriptVariable *);
    ScriptVariable();
    bool Compare(ScriptVariable *);
    void Save();
    void Load(TESFile *);
    ~ScriptVariable();
    ScriptVariable &operator=(const ScriptVariable &);
};
