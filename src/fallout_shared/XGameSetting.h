#pragma once

#include "bsmain/Setting.h"
#include "fallout_shared/tesfile.h"

class GameSettingCollection : public SettingCollectionMap<Setting> {
  public:
	static unsigned int iMapSize;

	GameSettingCollection(const GameSettingCollection&);
	GameSettingCollection();
	virtual bool Open(bool);
	virtual uint GetViewerStrings(NiTPrimitiveArray<char*>*);
	virtual bool WriteSetting(Setting&);
	virtual bool ReadSetting(TESFile*, const char*);
	virtual bool ReadSetting(Setting&);
	virtual bool Close();
	TESFile* File() { return (TESFile*)pHandle; }
	virtual ~GameSettingCollection();
};
