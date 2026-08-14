#pragma once

#include "bscore/bsstring.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/tesfile.h"

class TESFullName : public BaseFormComponent {
  public:
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	unsigned int GetFullNameLength() const;
	const char* GetFullName() const;
	void SetFullName(const char* acFullName) { cFullName = acFullName; }
	TESFullName(const TESFullName&);
	TESFullName() {}

	static unsigned int GetFullNameLength(TESForm*);
	static const char* GetFullName(TESForm*);
	static void LoadFullNameChunk(TESFullName*, TESFile*);

  protected:
	const BSStringT<char>& GetFullNameString() const { return cFullName; }

  private:
	BSStringT<char> cFullName; // 4
};
