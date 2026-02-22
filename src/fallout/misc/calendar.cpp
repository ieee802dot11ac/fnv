#include "calendar.h"
#include <math.h>

void Calendar::ClearPointers() {
    pGameYear = nullptr;
    pGameMonth = nullptr;
    pGameDay = nullptr;
    pGameHour = nullptr;
    pGameDaysPassed = nullptr;
    pTimeScale = nullptr;
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
