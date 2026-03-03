#include "calendar.h"
#include "fallout_shared/tesform.h"
#include <math.h>

void Calendar::ClearPointers() {
    pGameYear = nullptr;
    pGameMonth = nullptr;
    pGameDay = nullptr;
    pGameHour = nullptr;
    pGameDaysPassed = nullptr;
    pTimeScale = nullptr;
}

void Calendar::InitGlobals() {
    pGameYear = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x35));
    pGameMonth = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x36));
    pGameDay = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x37));
    pGameHour = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x38));
    pGameDaysPassed = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x39));
    pTimeScale = static_cast<TESGlobal *>(TESForm::GetFormByNumericID(0x3a));
    pGameDaysPassed->SetValue(pGameHour->GetValue() / 24.f + pGameDaysPassed->GetValue());
    iMidnightsPassed = 0;
}

float Calendar::GetTimeScale() { return pTimeScale->GetValue(); }

uint Calendar::GetYear() {
    return int(pGameYear != nullptr ? pGameYear->GetValue() : 77);
}

CALENDAR_MONTH Calendar::GetMonth() {
    if (pGameMonth != nullptr) {
        return CALENDAR_MONTH(char(pGameMonth->GetValue()));
    }
    return MONTH_AUGUST;
}

char Calendar::GetDay() { return pGameDay != nullptr ? pGameDay->GetValue() : 17.0f; }

float Calendar::GetHour() { return pGameHour != nullptr ? pGameHour->GetValue() : 12.0f; }

uint Calendar::GetDaysPassed() {
    return pGameDaysPassed != nullptr ? pGameDaysPassed->GetValue() : 1.0f;
}

uint Calendar::GetHoursPassed() {
    return floorf(
        (pGameDaysPassed != nullptr ? pGameDaysPassed->GetValue() : 1.0f) * 24.f
    );
}

float Calendar::GetMinutesPassed() {
    return 1440 * (pGameDaysPassed != nullptr ? pGameDaysPassed->GetValue() : 1.0f);
}

uint Calendar::GetMidnightsPassed() { return iMidnightsPassed; }

DAYS_OF_THE_WEEK Calendar::GetDayOfTheWeek() {
    return DAYS_OF_THE_WEEK(iMidnightsPassed % 7);
}

SEASON Calendar::GetSeason() {
    CALENDAR_MONTH month = GetMonth();
    switch (month) {
    case MONTH_DECEMBER:
    case MONTH_JANUARY:
    case MONTH_FEBRUARY:
        return SEASON_WINTER;
    case MONTH_MARCH:
    case MONTH_APRIL:
    case MONTH_MAY:
        return SEASON_SPRING;
    case MONTH_JUNE:
    case MONTH_JULY:
    case MONTH_AUGUST:
        return SEASON_SUMMER;
    case MONTH_SEPTEMBER:
    case MONTH_OCTOBER:
    case MONTH_NOVEMBER:
        return SEASON_FALL;
    }
}

BSStringT<char> Calendar::GetDateString() {
    BSStringT<char> str;
    float year = pGameYear != nullptr ? pGameYear->GetValue() : 77;
    float day = pGameDay != nullptr ? pGameDay->GetValue() : 17.0f;
    CALENDAR_MONTH month = GetMonth();
    // int year_mod_100 = ;
    str.SPrintF("%02d.%02d.%02d", month, (int)day, (int)year % 100);
    return str;
}
