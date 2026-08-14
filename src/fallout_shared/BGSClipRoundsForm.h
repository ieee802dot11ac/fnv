#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"
#include "types.h"

class BGSClipRoundsForm : public BaseFormComponent {
  public:
	BGSClipRoundsForm();
	~BGSClipRoundsForm();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	int GetFormClipRounds();
	void SetFormClipRounds(int);

	static int GetFormClipRounds(TESForm*);

  private:
	u8 cClipRounds; // 0x4
};
