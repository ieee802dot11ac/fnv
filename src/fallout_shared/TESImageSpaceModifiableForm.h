#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESImageSpaceModifier.h"
#include "fallout_shared/baseformcomponent.h"

class TESImageSpaceModifiableForm : public BaseFormComponent {
  public:
	TESImageSpaceModifiableForm();
	virtual void InitializeDataComponent();
	virtual void ClearDataComponent();
	void Save();
	void InitItem(TESForm*);
	virtual void CopyComponent(BaseFormComponent*);
	virtual bool CompareComponent(BaseFormComponent*);
	TESImageSpaceModifier* GetFormImageSpaceModifying();
	void SetFormImageSpaceModifying(TESImageSpaceModifier*);

  protected:
	TESImageSpaceModifier* pFormImageSpaceModifying; // 0x4
};
