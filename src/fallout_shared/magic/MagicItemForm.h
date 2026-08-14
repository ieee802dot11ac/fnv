#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/magic/MagicItem.h"

class MagicItemForm : public TESForm, public MagicItem {
  public:
	virtual bool IsAutoCalc() = 0;
	virtual void SetAutoCalc(bool) = 0;
	virtual MagicSystem::SpellType GetSpellType() = 0;
	virtual bool IsMagicItem();
	virtual void Save();
	virtual bool Load(TESFile*);
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual void InitItem();
	virtual void SetAltered(bool);

  protected:
	virtual CHUNK_ID GetChunkID() = 0;
	virtual void* GetData() = 0;
	virtual unsigned int GetDataSize() = 0;
	virtual bool CompareMagicItemData(MagicItem*) = 0;
	virtual void CopyMagicItemData(MagicItem*) = 0;
	virtual void SaveMagicItemComponents();
	virtual void LoadMagicItemChunk(TESFile*, CHUNK_ID);
	virtual void Endian() = 0;
};
