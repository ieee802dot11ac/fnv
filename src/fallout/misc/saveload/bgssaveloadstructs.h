#pragma once

#include "fallout/misc/saveload/bgschangeflags.h"
#include "fallout_shared/enums.h"

struct BGSNumericIDIndex {
    unsigned char cData1; // 0
    unsigned char cData2; // 1
    unsigned char cData3; // 2

    BGSNumericIDIndex();
    unsigned int GetNumericID();
    void SetNumericID(unsigned int);
    bool IsZero();
};

struct BGSSaveLoadFormInfo { /* Size=0x1 */
    /* 0x0000 */ unsigned char cData;

    BGSSaveLoadFormInfo();
    ENUM_FORM_ID GetFormType();
    void SetFormType(ENUM_FORM_ID);
    SIZE_TYPE GetSizeType();
    void SetSizeType(SIZE_TYPE);

    static void InitSaveGameFormTypes();
};

struct BGSSaveLoadFormHeader {
    BGSNumericIDIndex FormIDIndex; // 0x0
    BGSChangeFlags iChangeFlags; // 0x3
    BGSSaveLoadFormInfo FormInfo; // 0x7
    unsigned char cVersion; // 0x8

    void Endian();
};
