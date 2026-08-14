#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/baseformcomponent.h"

class TESWeightForm : public BaseFormComponent {
  public:
	TESWeightForm(const TESWeightForm&);
	TESWeightForm();
	~TESWeightForm();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	float GetFormWeight();
	void SetFormWeight(float);

	static float GetFormWeight(TESForm*, bool);

  private:
	float fWeight; // 0x4
};
