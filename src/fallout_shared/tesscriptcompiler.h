#pragma once

#include "fallout_shared/tesscriptvariable.h"

enum COMPILER_NAME {
    DEFAULT_COMPILER = 0x0000,
    SYSTEM_WINDOW_COMPILER = 0x0001,
    DIALOGUE_COMPILER = 0x0002,
    COMPILER_NAME_COUNT = 0x0003,
};

class ScriptCompileData {
public:
    ScriptCompileData(const ScriptCompileData &);
    ScriptCompileData();
    ~ScriptCompileData();
    bool GetVariable(SCRIPT_WORD *);
    SCRIPT_REFERENCED_OBJECT *GetReferencedObject(unsigned int);
    bool GetReferencedObject(SCRIPT_WORD *, bool, bool);
    bool VerifyReferencedObjectList();
    BSSimpleList<SCRIPT_LINE *> *GetScriptLineList();
    BSSimpleList<SCRIPT_REFERENCED_OBJECT *> *GetReferencedObjectList();
    BSSimpleList<ScriptVariable *> *GetVariableList();
    void ClearAllScriptLines();
    void ClearAllReferenceObjects();
    void ClearAllVariables();

    const char *input; // 0x00
    unsigned int uiInputOffset; // 0x04
    COMPILER_NAME eCompilerIndex; // 0x08
    BSStringT<char> cScriptName; // 0x0c
    SCRIPT_ERROR eLastError; // 0x14
    bool bIsPartialScript; // 0x18
    unsigned int uiLastLineNumber; // 0x1c
    char *pOutput; // 0x20
    unsigned int uiOutputOffset; // 0x24
    SCRIPT_HEADER header; // 0x28
    BSSimpleList<ScriptVariable *> listVariables; // 0x3c
    BSSimpleList<SCRIPT_REFERENCED_OBJECT *> listRefObjects; // 0x44
    Script *pCurrentScript; // 0x4c
private:
    BSSimpleList<SCRIPT_LINE *> listLines; // 0x50
};

class ScriptCompiler { /* Size=0x1 */

public:
    ScriptCompiler();
    ~ScriptCompiler();
    bool CompilePartialScript(Script *, TESObjectREFR *, COMPILER_NAME, bool);
    bool CompileFullScript(Script *, COMPILER_NAME);

    static bool StandardCompile(
        const unsigned short, const SCRIPT_PARAMETER *, SCRIPT_LINE *, ScriptCompileData *
    );
    static bool MessageBoxCompile(
        const unsigned short,
        const SCRIPT_PARAMETER *,
        SCRIPT_LINE *,
        ScriptCompileData *,
        bool,
        bool
    );
    static bool MessageBoxCompile(
        const unsigned short, const SCRIPT_PARAMETER *, SCRIPT_LINE *, ScriptCompileData *
    );
    static bool MessageCompile(
        const unsigned short, const SCRIPT_PARAMETER *, SCRIPT_LINE *, ScriptCompileData *
    );
    static bool OldMessageCompile(
        const unsigned short, const SCRIPT_PARAMETER *, SCRIPT_LINE *, ScriptCompileData *
    );
    static bool IsValidVariableName(const char *);
    static void ScriptError(ScriptCompileData *, char *, ...);
    static SCRIPT_FUNCTION *GetFunctionDef(SCRIPT_OUTPUT);

protected:
    bool Compile(Script *, ScriptCompileData *);
    bool CompileLine(Script *, ScriptCompileData *, SCRIPT_LINE *);
    SCRIPT_OUTPUT GetNextExpression(ScriptCompileData *);
    bool VerifyBlocks(ScriptCompileData *);
    int CountBlockLines(ScriptCompileData *, SCRIPT_LINE *);
    int CountIfLines(ScriptCompileData *, SCRIPT_LINE *);
    int CountVariablesNeeded();
    int CountButtonsNeeded();
    unsigned int
    ReplaceVariablesAndFunctions(ScriptCompileData *, const SCRIPT_LINE *, char *, char *);
    void VerifyParameters(SCRIPT_FUNCTION *, int);
    ANIM_GROUP_ENUM GetAnimGroup(char *);

    static int GetNextLine(ScriptCompileData *, SCRIPT_LINE *);
    static bool GetFunction(SCRIPT_WORD *);
    static int GetNextWord(
        ScriptCompileData *, SCRIPT_WORD *, const char *, unsigned int &, bool, bool
    );
    static void SkipWhiteSpace(const char *, unsigned int &);
    static bool CheckQuotes(const char *, const unsigned int);
    static bool CheckParentheses(const char *, const unsigned int);
};
