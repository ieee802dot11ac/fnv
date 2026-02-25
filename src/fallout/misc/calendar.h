#pragma once

#include "fallout_shared/tesglobal.h"
#include <types.h>

enum DAYS_OF_THE_WEEK {
    DAY_NONE = 0xff,
    DAY_SUNDAY = 0x0000,
    DAY_MONDAY = 0x0001,
    DAY_TUESDAY = 0x0002,
    DAY_WEDNESDAY = 0x0003,
    DAY_THURSDAY = 0x0004,
    DAY_FRIDAY = 0x0005,
    DAY_SATURDAY = 0x0006,
    DAY_COUNT = 0x0007,
};

enum SEASON {
    SEASON_NONE = 0xff,
    SEASON_SPRING = 0x0000,
    SEASON_SUMMER = 0x0001,
    SEASON_FALL = 0x0002,
    SEASON_WINTER = 0x0003,
    SEASON_COUNT = 0x0004,
};

enum CALENDAR_MONTH {
    MONTH_NONE = 0xff,
    MONTH_JANUARY = 0x0000,
    MONTH_FEBRUARY = 0x0001,
    MONTH_MARCH = 0x0002,
    MONTH_APRIL = 0x0003,
    MONTH_MAY = 0x0004,
    MONTH_JUNE = 0x0005,
    MONTH_JULY = 0x0006,
    MONTH_AUGUST = 0x0007,
    MONTH_SEPTEMBER = 0x0008,
    MONTH_OCTOBER = 0x0009,
    MONTH_NOVEMBER = 0x000a,
    MONTH_DECEMBER = 0x000b,
    MONTH_COUNT = 0x000c,
};

class Calendar { /* Size=0x1c */
    /* 0x0000 */ TESGlobal *pGameYear;
    /* 0x0004 */ TESGlobal *pGameMonth;
    /* 0x0008 */ TESGlobal *pGameDay;
    /* 0x000c */ TESGlobal *pGameHour;
    /* 0x0010 */ TESGlobal *pGameDaysPassed;
    /* 0x0014 */ TESGlobal *pTimeScale;
    /* 0x0018 */ uint iMidnightsPassed;

public:
    Calendar();
    ~Calendar();
    void InitGlobals();
    void Update(float);
    void ClearPointers();
    uint GetYear();
    SEASON GetSeason();
    CALENDAR_MONTH GetMonth();
    char GetDay();
    float GetHour();
    uint GetDaysPassed();
    uint GetHoursPassed();
    float GetMinutesPassed();
    uint GetMidnightsPassed();
    DAYS_OF_THE_WEEK GetDayOfTheWeek();
    const char *GetDayOfWeekString();
    float GetTimeScale();
    //   BSStringT<char> GetDateString();
    int ComputeDaysbetween(int, int, int);

    static float StaticGetHour();
};
