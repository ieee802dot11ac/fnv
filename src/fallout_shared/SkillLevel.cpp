#include "SkillLevel.h"
#include "fallout_shared/XGameSetting.h"

static SETTING(GameSettingCollection, sSkillLevelNovice, "Novice");
static SETTING(GameSettingCollection, sSkillLevelApprentice, "Apprentice");
static SETTING(GameSettingCollection, sSkillLevelJourneyman, "Journeyman");
static SETTING(GameSettingCollection, sSkillLevelExpert, "Expert");
static SETTING(GameSettingCollection, sSkillLevelMaster, "Master");

static SETTING(GameSettingCollection, iSkillApprenticeMin, 25);
static SETTING(GameSettingCollection, iSkillJourneymanMin, 50);
static SETTING(GameSettingCollection, iSkillExpertMin, 75);
static SETTING(GameSettingCollection, iSkillMasterMin, 100);
