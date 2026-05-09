#include "MagicItem.h"
#include "bsmain/Setting.h"
#include "fallout_shared/XGameSetting.h"
#include "fallout_shared/magic/MagicItemForm.h"
#include "fallout_shared/magic/MagicItemObject.h"

static SETTING(GameSettingCollection, sMagicCastOKText, "OK");
static SETTING(
    GameSettingCollection, sMagicCastInsufficientMagicka, "You don't have enough Magicka"
);
static SETTING(
    GameSettingCollection, sMagicCastInsufficientSkill, "Your skill level is too low"
);
static SETTING(GameSettingCollection, sMagicCastSilenced, "You are currently Silenced");
static SETTING(
    GameSettingCollection, sMagicCastPowerUsed, "You can only cast Powers once per day"
);
static SETTING(
    GameSettingCollection,
    sMagicCastMultipleBoundEffects,
    "You already have that kind of Bound Item"
);
static SETTING(
    GameSettingCollection,
    sMagicCastRangedUnderwater,
    "You cannot cast ranged spells underwater"
);
static SETTING(GameSettingCollection, iMagicMaxSummonedCreatureTypes, 10);

uint MagicItem::GetMagicItemFormID() {
    MagicItemForm *mif = dynamic_cast<MagicItemForm *>(this);
    MagicItemObject *mio = dynamic_cast<MagicItemObject *>(this);
    if (mif != nullptr)
        return mif->GetFormID();
    if (mio != nullptr)
        return mio->GetFormID();
    return 0;
}

MagicItem *MagicItem::GetMagicItemByNumericID(uint aiFormID) {
    TESForm *form = TESForm::GetFormByNumericID(aiFormID);
    if (form == nullptr)
        return nullptr;
    MagicItemForm *mif = dynamic_cast<MagicItemForm *>(form);
    MagicItemObject *mio = dynamic_cast<MagicItemObject *>(form);
    if (mif != nullptr)
        return mif;
    if (mio != nullptr)
        return mio;
    return nullptr;
}

EffectSetting *MagicItem::GetAVEffect(MagicSystem::Range aeRange) { return nullptr; }

bool MagicItem::IsLoaded() { return false; }

bool MagicItem::IsLoadingOrLoaded() { return false; }

bool MagicItem::IsLoading() { return false; }

void MagicItem::MagicItemInitItem(TESForm *apForm) {}

void MagicItem::Preload(bool abNow) {}

void MagicItem::Unload(bool abRelease) {}

void MagicItem::FinishedLoading() {}

BSStringT<char> MagicItem::GetCannotCastString(MagicItem::CannotCastReason aeReason) {
    const char *ret;
    switch (aeReason) {
    case NOCAST_MAGICKA: {
        ret = sMagicCastInsufficientMagicka.String();
    } break;
    case NOCAST_SKILLCHECK: {
        ret = sMagicCastInsufficientSkill.String();
    } break;
    case NOCAST_POWERUSED: {
        ret = sMagicCastPowerUsed.String();
    } break;
    case NOCAST_SILENCED: {
        ret = sMagicCastSilenced.String();
    } break;
    case NOCAST_MULTIPLEBOUNDEFFECTS: {
        ret = sMagicCastMultipleBoundEffects.String();
    } break;
    case NOCAST_RANGEDUNDERWATER: {
        ret = sMagicCastRangedUnderwater.String();
    } break;
    default: {
        ret = sMagicCastOKText.String();
    } break;
    }

    BSStringT<char> val;
    val = ret;
    return val;
}

MagicItem::~MagicItem() { RemoveAllEffects(); }
