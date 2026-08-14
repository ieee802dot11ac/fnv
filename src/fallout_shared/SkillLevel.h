#pragma once

#include "fallout_shared/XGameSetting.h"

class SkillLevel {
  public:
	enum Value {
		NOVICE = 0x0000,
		APPRENTICE = 0x0001,
		JOURNEYMAN = 0x0002,
		EXPERT = 0x0003,
		MASTER = 0x0004,
		SKILL_LEVEL_COUNT = 0x0005,
	};

	static SkillLevel::Value GetSkillLevel(int);
	static const char* GetSkillLevelName(SkillLevel::Value);
	static int GetSkillLevelMinimum(SkillLevel::Value);

  private:
	static SettingT<GameSettingCollection>* pGameSettings[5];
};
