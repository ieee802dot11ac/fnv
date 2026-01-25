#include "calendar.h"

void Calendar::ClearPointers() {
    pGameYear = nullptr;
    pGameMonth = nullptr;
    pGameDay = nullptr;
    pGameHour = nullptr;
    pGameDaysPassed = nullptr;
    pTimeScale = nullptr;
}

float Calendar::GetTimeScale() { return pTimeScale->GetValue(); }

CALENDAR_MONTH Calendar::GetMonth() {
    if (pGameMonth != nullptr) {
        return CALENDAR_MONTH(char(pGameMonth->GetValue()));
    }
    return MONTH_AUGUST;
}

char Calendar::GetDay() {
    if (pGameDay != nullptr) {
        return pGameDay->GetValue();
    }
    return 17.0f;
}

float Calendar::GetHour() {
    if (pGameHour != nullptr) {
        return pGameHour->GetValue();
    }
    return 12;
}

uint Calendar::GetDaysPassed() {
    if (pGameDaysPassed != nullptr) {
        return pGameDaysPassed->GetValue();
    }
    return 1.0f;
}

float Calendar::GetMinutesPassed() {
    return 1440 * (pGameDaysPassed != nullptr ? pGameDaysPassed->GetValue() : 1.0f);
}

uint Calendar::GetMidnightsPassed() { return iMidnightsPassed; }

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
