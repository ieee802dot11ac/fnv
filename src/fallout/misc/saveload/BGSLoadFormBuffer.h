#pragma once

#include "fallout/misc/saveload/BGSLoadGameBuffer.h"
#include "fallout/misc/saveload/bgssaveloadfile.h"
#include "fallout/misc/saveload/bgssaveloadstructs.h"
#include "fallout_shared/tesobjectrefr.h"

class Actor;

class BGSLoadFormBuffer : public BGSLoadGameBuffer {
  public:
	BGSLoadFormBuffer(const BGSLoadFormBuffer&);
	BGSLoadFormBuffer();
	int LoadHeader(BGSSaveLoadFile*);
	int LoadDataFromFile(BGSSaveLoadFile*);
	void SkipData(BGSSaveLoadFile*, unsigned int);
	unsigned int GetFormID();
	void SetForm(TESForm*);
	virtual TESForm* GetForm();
	virtual TESObjectREFR* GetReference();
	virtual Actor* GetActor();
	ENUM_FORM_ID GetFormType();
	BGSChangeFlags GetChangeFlags() { return Header.iChangeFlags; }
	void SetChangeFlags(BGSChangeFlags);
	BGSChangeFlags GetOldChangeFlags();
	void SetOldChangeFlags(BGSChangeFlags);
	void SetVersion(unsigned char);
	virtual unsigned char GetVersion();
	void SetSkipForm(bool);
	bool GetSkipForm();
	void SetFormPending(bool);
	bool GetFormPending();
	void SetRevertOnly(bool);
	bool GetRevertOnly();
	void SetReconstructedForm(bool);
	bool GetReconstructedForm();
	void SetCellChanged(bool);
	bool GetCellChanged();
	~BGSLoadFormBuffer();

  protected:
	unsigned int iFormID;			// 0x10
	BGSSaveLoadFormHeader Header;	// 0x14
	unsigned int iSize;				// 0x20
	TESForm* pForm;					// 0x24
	unsigned int iFlags;			// 0x28
	BGSChangeFlags iOldChangeFlags; // 0x2c
};
