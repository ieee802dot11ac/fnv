#pragma once

#include "fallout_shared/XGameSetting.h"

class ExperiencePoints {
  public:
	enum Activity {
		ACTIVITY_KILL_CREATURE = 0x0000,
		ACTIVITY_KILL_NPC = 0x0001,
		ACTIVITY_HACK_COMPUTER = 0x0002,
		ACTIVITY_PICK_LOCK = 0x0003,
		ACTIVITY_SPEECH_CHALLENGE = 0x0004,
		ACTIVITY_COUNT = 0x0005,
	};

	static int GetExperiencePoints(Activity, int);
	static bool CheckDamageThreshold(float, float);

  private:
	static int GetExperiencePoints(int, SettingT<GameSettingCollection>** [2],
								   int);
};
