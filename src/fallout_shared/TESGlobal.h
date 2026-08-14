#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/TESForm.h"

class TESGlobal : public TESForm {
  public:
	TESGlobal(const TESGlobal&);
	TESGlobal();
	virtual ~TESGlobal() { /* blr stub*/ }
	virtual void Save();
	virtual bool Load(TESFile*);
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	void SetType(char);
	char GetType();
	void SetValue(float value) { fValue = value; }
	float GetValue() { return fValue; }

	BS_MEM_OVERLOADS

  private:
	char cType;	  // 0x28
	float fValue; // 0x2c
};
