#pragma once

#include "fallout shared/TESForm.h"

class TESGlobal : public TESForm { /* Size=0x30 */
    /* 0x0000: fields for TESForm */
private:
    /* 0x0028 */ char cType;
    /* 0x002c */ float fValue;

public:
    TESGlobal(const TESGlobal &);
    TESGlobal();
    virtual ~TESGlobal();
    virtual void Save();
    // virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    void SetType(char);
    char GetType();
    void SetValue(float);
    float GetValue() { return fValue; }
    TESGlobal &operator=(const TESGlobal &);
};
